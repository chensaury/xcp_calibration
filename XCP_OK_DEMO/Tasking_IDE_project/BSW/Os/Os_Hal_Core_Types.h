/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**
 * \addtogroup  Os_Hal_Core
 * \{
 *
 * \file    Os_Hal_Core_Types.h
 * \brief   Core and multi-core related primitives.
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef OS_HAL_CORE_TYPES_H
# define OS_HAL_CORE_TYPES_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */

/* Os kernel module dependencies */

/* Os HAL dependencies */

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/*! Defines whether the HAL provides a count leading zeros command (STD_ON) or not (STD_OFF). */
# define OS_HAL_COUNT_LEADING_ZEROS_HARDWARE     STD_ON


/*! The required address width to subscript the bits of a Os_Hal_CoreBitFieldType.
 * The value can be selected from the following table:
 * typeof(Os_Hal_BitFieldType)      | OS_HAL_INDEXBITWIDTH
 * :------------------------------: | :----------------------------
 * uint8                            | 3
 * uint16                           | 4
 * uint32                           | 5
 * uint64                           | 6
 */
# define OS_HAL_INDEXBITWIDTH       (5)


/*! Defines the stack fill pattern, which is used to initialize an empty stack.
 * The value has to be selected from the following table:
 * typeof(Os_Hal_StackType)       | OS_HAL_STACK_FILL_PATTERN
 * :----------------------------: | :------------------------------
 * uint8                          | 0xAA
 * uint16                         | 0xAAAA
 * uint32                         | 0xAAAAAAAA
 * uint64                         | 0xAAAAAAAAAAAAAAAA
 */
# define OS_HAL_STACK_FILL_PATTERN   ((Os_Hal_StackType)0xAAAAAAAAuL)


/*! Defines the value which is returned by \ref Os_Hal_SpinTryLock, if locking succeeded. */
# define OS_HAL_SPINLOCKSUCCEEDED    ((Os_Hal_SpinlockResultType)OS_HAL_UNLOCKED)
/*! Defines the value of lock variable, when it is unlocked. */
# define OS_HAL_UNLOCKED             (0xFFFFFFFFuL)

/*! Defines the memory start address which is used to initialize MPU region for startup stack. */
# define OS_HAL_MEM_STARTADDR   (0x00000000uL)
/*! Defines the memory end address which is used to initialize MPU region for startup stack. */
# define OS_HAL_MEM_ENDADDR     (0xFFFFFFFFuL)

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/


/*! Data type which is used to perform efficient calculation of count leading zero bits.
 * Typically this type is mapped to the processors word type (unsigned int or Os_Hal_WordType).
 * The kernel uses this type to count the leading zeros in Os_Hal_CountLeadingZeros() respectively
 * Os_Bit_CountLeadingZeros(). */
typedef uint32 Os_Hal_BitFieldType;


/*! Defines the type of the stack array.
 * Typically this type is mapped to the processors word type (unsigned int or Os_Hal_WordType). */
typedef uint32 Os_Hal_StackType;


/*! Data type for spinlocks. */
typedef uint32 Os_Hal_SpinlockType;

/*! Defines whether the lock succeeded or not. */
typedef Os_Hal_SpinlockType Os_Hal_SpinlockResultType;

/*! Forward declaration of Os_Hal_CoreConfigType */
struct Os_Hal_CoreConfigType_Tag;
typedef struct Os_Hal_CoreConfigType_Tag Os_Hal_CoreConfigType;

struct Os_Hal_Core2ThreadType_Tag;
typedef struct Os_Hal_Core2ThreadType_Tag Os_Hal_Core2ThreadType;

struct Os_Hal_Core2ThreadConfigType_Tag;
typedef struct Os_Hal_Core2ThreadConfigType_Tag Os_Hal_Core2ThreadConfigType;

/*! Forward declaration of Os_Hal_CoreAsrConfigType */
struct Os_Hal_CoreAsrConfigType_Tag;
typedef struct Os_Hal_CoreAsrConfigType_Tag Os_Hal_CoreAsrConfigType;

typedef uint32 Os_Hal_SystemConfigType;

/*! Forward declaration of Os_Hal_XSigInterruptConfigType */
struct Os_Hal_XSigInterruptConfigType_Tag;
typedef struct Os_Hal_XSigInterruptConfigType_Tag Os_Hal_XSigInterruptConfigType;

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#endif /* OS_HAL_CORE_TYPES_H */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Core_Types.h
 **********************************************************************************************************************/
