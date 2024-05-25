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
 *  \ingroup    Os_Hal
 *  \defgroup   Os_Hal_Trap HAL Trap
 *  \brief      The platform shall provide trap functions to the OS services here.
 *  \details    The trap functions shall call the associated kernel function in privileged mode.
 *
 *  \{
 *
 *  \file      Os_Hal_TrapInt.h
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/


#ifndef OS_HAL_TRAPINT_H
# define OS_HAL_TRAPINT_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */

/* Os kernel module dependencies */
# include "Os_TrapInt.h"

/* Os HAL dependencies */
# include "Os_Hal_CompilerInt.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
/*! Define the valid system call id */
# define OS_HAL_SYSCALL_TRAP_ID         31


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
 *  Os_Hal_Trap()
 **********************************************************************************************************************/
/*! \brief        Trigger trap to execute OS service.
 *  \details      The declaration of this function is dependent on the used compiler. Thus the compiler abstraction
 *                Os_Hal_DeclareTrapFunction is used. More information can be found in the individual compiler
 *                abstraction files, e.g.: Os_Hal_Compiler_TaskingInt.h
 *
 *  \param[in]    Parameters   Parameters to be bypassed to kernel's trap handler. Parameter must not be NULL.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Reference API parameters of the TrapPacket are valid.
 **********************************************************************************************************************/
Os_Hal_DeclareTrapFunction(
                            Os_Hal_Trap,
                            (
                              P2VAR(Os_TrapPacketType, AUTOMATIC, OS_VAR_NOINIT) Parameters
                            ),
                            OS_HAL_SYSCALL_TRAP_ID
                          );


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_HAL_TRAPINT_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_TrapInt.h
 **********************************************************************************************************************/

