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
 * \addtogroup Os_Bit
 *
 * \{
 *
 * \file
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

#ifndef OS_BIT_H
# define OS_BIT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_BitInt.h"

/* Os kernel module dependencies */
# include "Os_Common.h"
# include "Os_Error.h"

/* Os HAL dependencies */
# include "Os_Hal_Compiler.h"
# include "Os_Hal_Core.h"



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
 *  Os_Bit_GetBitfieldWidth()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE uint8, OS_CODE, OS_ALWAYS_INLINE,                                          /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMBITLIBCLZ */
Os_Bit_GetBitfieldWidth, (void))                                                                                        /* COV_OS_HALPLATFORMBITLIBCLZ */
{
  return (uint8)OS_BITFIELD_BITWIDTH;
}


/***********************************************************************************************************************
 *  Os_Bit_IsCountLeadingZerosInHardware()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_Bit_IsCountLeadingZerosInHardware, (void))
{
  return (OS_HAL_COUNT_LEADING_ZEROS_HARDWARE == STD_ON);                                                               /* PRQA S 4404 */ /*  MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_Bit_CountLeadingZeros()
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_BitIndexType, OS_CODE,                                                  /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_Bit_CountLeadingZeros,
(
  Os_BitFieldType BitField
))
{
  Os_BitIndexType result;

  /* #10  If available perform operation in hardware. */
  if (Os_Bit_IsCountLeadingZerosInHardware() != 0u)                                                                     /* COV_OS_HALPLATFORMCLZAVAILABILITY */
  {
    result = (Os_BitIndexType)Os_Hal_CountLeadingZeros(BitField);
  }
  /* #20 Otherwise perform calculation in software. */
  else
  {
    Os_BitIndexType indexOffset;
    Os_BitFieldType index;
    static CONST(Os_BitIndexType, OS_CONST) countLeadingZeros4BitMap[16]=
    {
       4,     /* 0000 */
       3,     /* 0001 */
       2,     /* 0010 */
       2,     /* 0011 */
       1,     /* 0100 */
       1,     /* 0101 */
       1,     /* 0110 */
       1,     /* 0111 */
       0,     /* 1000 */
       0,     /* 1001 */
       0,     /* 1010 */
       0,     /* 1011 */
       0,     /* 1100 */
       0,     /* 1101 */
       0,     /* 1110 */
       0      /* 1111 */
    };

    index = BitField;
    indexOffset = 0;

    Os_Assert((Os_StdReturnType)(Os_Bit_GetBitfieldWidth() >= 8u));                                                     /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */

    if(Os_Bit_GetBitfieldWidth() >= 32u)
    {
      /* #30 Check whether there is a one in the 'upper' 16 bits. */
      if((index & 0xFFFF0000u) != 0u)
      {
        /* #40 If so, shift the value by 16 bits. */
        index >>= (Os_BitFieldType)16;
      }
      else
      {
        /* #50 Otherwise the first 16 bits are zero. */
        indexOffset += (Os_BitIndexType)16;
      }
    }

    if(Os_Bit_GetBitfieldWidth() >= 16u)
    {
      /* #60 Check whether there is a one in the 'upper' 8 bits. */
      if((index & 0xFF00u) != 0u)
      {
        /* #70 If so, shift the value by 8 bits. */
        index >>= (Os_BitFieldType)8;
      }
      else
      {
        /* #80 Otherwise the first 8 bits are zero. */
        indexOffset += (Os_BitIndexType)8;
      }
    }

    /* #90 Check whether there is a one in the 'upper' 4 bits. */
    if((index & 0xF0u) != 0u)
    {
      /* #100 If so, shift the value by 4 bits. */
      index >>= (Os_BitFieldType)4;
    }
    else
    {
      /* #110 Otherwise the first 4 bits are zero. */
      indexOffset += (Os_BitIndexType)4;
    }

    /* #120 Get the index of the leading zero of the last 4 bits from the map. */
    result = indexOffset + countLeadingZeros4BitMap[index];
  }

  return result;
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */



#endif /* OS_BIT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Bit.h
 **********************************************************************************************************************/
