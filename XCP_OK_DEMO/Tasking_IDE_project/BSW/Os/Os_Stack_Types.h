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
 * \addtogroup Os_Stack
 * \{
 *
 * \file
 * \brief       Internal type forward declarations of \ref Os_Stack.
 * \details     --no details--
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_STACK_TYPES_H
# define OS_STACK_TYPES_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */

/* Os kernel module dependencies */

/* Os hal dependencies */
# include "Os_Hal_Core_Types.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  OS_STACK_GETLOWADDRESS()
 **********************************************************************************************************************/
/*! \brief        Get the low address of a stack.
 *  \details
 *  The kernel uses this macro for stack assignment in the configuration data.
 *
 *  \param[in]    StackLabel  The stack label to query.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
# define OS_STACK_GETLOWADDRESS(StackLabel)      ((&(StackLabel)[0]))                                                   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/***********************************************************************************************************************
 *  OS_STACK_GETSIZE()
 **********************************************************************************************************************/
/*! \brief        Get the size of a stack.
 *  \details
 *  The kernel uses this macro for stack assignment in the configuration data.
 *
 *  \param[in]    StackLabel  The stack label to query.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
# define OS_STACK_GETSIZE(StackLabel)           ((uint32)(sizeof(StackLabel)))                                          /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */



/***********************************************************************************************************************
 *  OS_STACK_GETHIGHADDRESS()
 **********************************************************************************************************************/
/*! \brief        Get the high address of a stack label.
 *  \details
 *  The kernel uses this macro for stack assignment in the configuration data.
 *
 *  \param[in]    StackLabel  The stack label to query.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
# define OS_STACK_GETHIGHADDRESS(StackLabel)  ((P2VAR(Os_Hal_StackType, TYPEDEF, OS_VAR_NOINIT))                        /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */ \
(&StackLabel[(OS_STACK_GETSIZE(StackLabel)/sizeof(Os_Hal_StackType))-1u]))                                              /* PRQA S 3410, 3453 */ /* MD_Os_Rule20.7_3410_Decl, MD_MSR_FctLikeMacro */



/***********************************************************************************************************************
 *  OS_STACK_DECLARE()
 **********************************************************************************************************************/
/*! \brief        Create a stack.
 *  \details
 *  The kernel uses this macro to create a stack, independent of the stack type width.
 *
 *  \param[in]    StackLabel  The name of the stack.
 *  \param[in]    ByteSize    The size of the stack.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
# define OS_STACK_DECLARE(StackLabel, ByteSize)   VAR(Os_Hal_StackType, OS_VAR_NOINIT)                                  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */ \
StackLabel[(ByteSize)/sizeof(Os_Hal_StackType)]                                                                         /* PRQA S 3410, 3453 */ /* MD_Os_Rule20.7_3410, MD_MSR_FctLikeMacro */


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
struct Os_StackConfigType_Tag;
typedef struct Os_StackConfigType_Tag Os_StackConfigType;


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/



#endif /* OS_STACK_TYPES_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_Stack_Types.h
 **********************************************************************************************************************/
