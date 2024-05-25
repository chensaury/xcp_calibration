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
 * \defgroup    Os_Bit Bit
 * \brief       Bit manipulation primitives.
 * \details
 *
 * \{
 *
 * \file        Os_BitInt.h
 * \brief       This file provides functions for bit manipulation
 * \details     --no details--
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_BITINT_H
# define OS_BITINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */

/* Os kernel module dependencies */
# include "Os_CommonInt.h"
# include "Os_ErrorInt.h"

/* Os HAL dependencies */
# include "Os_Hal_CompilerInt.h"
# include "Os_Hal_Core_Types.h"
# include "Os_Hal_CoreInt.h"




/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/*! The bit width of Os_BitFieldType. */
# define OS_BITFIELD_BITWIDTH         (sizeof(Os_BitFieldType) * 8u)

/*! The number of bit needed to address each bit in Os_BitFieldType. */
# define OS_BITFIELD_INDEXBITWIDTH    (OS_HAL_INDEXBITWIDTH)

/*! Mask with MSb set to '1'. */
# define OS_BITFIELD_MASK_MSB         ((Os_BitFieldType)( ((Os_BitFieldType)1) << (OS_BITFIELD_BITWIDTH - 1u )))


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/*! Addresses a single bit in a Os_BitFieldType. */
typedef uint8 Os_BitIndexType;


/*! Basic data type which is used to build a bit array. */
typedef Os_Hal_BitFieldType Os_BitFieldType;


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


/***********************************************************************************************************************
 *  Os_Bit_GetBitfieldWidth()
 **********************************************************************************************************************/
/*! \brief          Returns the width in bits of the Os_BitFieldType type.
 *  \details        --no details--
 *
 *  \return         The width in bits of the Os_BitFieldType type.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE uint8, OS_CODE, OS_ALWAYS_INLINE, Os_Bit_GetBitfieldWidth, (void));


/***********************************************************************************************************************
 *  Os_Bit_IsCountLeadingZerosInHardware()
 **********************************************************************************************************************/
/*! \brief          Returns count leading zeros is mapped to an instruction (!0) or computed by the kernel (0).
 *  \details        --no details--
 *
 *  \retval         !0  Count leading zeros is calculated in hardware.
 *  \retval         0   Count leading zeros is computed by the kernel.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_Bit_IsCountLeadingZerosInHardware, (void));


/***********************************************************************************************************************
 *  Os_Bit_CountLeadingZeros()
 **********************************************************************************************************************/
/*! \brief          Implementation of the Count Leading Zeros (CLZ) instruction.
 *  \details
 *  Returns the number of consecutive zeros starting from the MSb.
 *  If the MSb of BitArray is set, zero is returned.
 *  If the given BitArray is zero, the bit width of Os_BitArrayType is returned.
 *  This implementation works for bit fields up to 32Bit.
 *
 *  \see  [Find First Set](http:\\en.wikipedia.org/wiki/Find_first_set),
 *        [Count Leading Zeros](http:\\en.wikipedia.org/wiki/Find_first_set#CLZ),
 *        [Hardware support](http:\\en.wikipedia.org/wiki/Find_first_set#Hardware_support)
 *
 *  \param[in]      BitField        Task to query.
 *
 *  \return         The number of consecutive zero bits.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_BitIndexType, OS_CODE,
OS_ALWAYS_INLINE, Os_Bit_CountLeadingZeros,
(
  Os_BitFieldType BitField
));


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_BITINT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_BitInt.h
 **********************************************************************************************************************/
