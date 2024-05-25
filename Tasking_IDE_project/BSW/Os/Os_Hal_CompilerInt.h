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
 *  \defgroup   Os_Hal_Compiler  HAL Compiler
 *  \brief      Abstraction of compiler specific keywords to allow the compiler to generate more efficient code.
 *  \details
 *  The kernel should be able to give the compiler meta information to generate more efficient code.
 *  It also needs to tell the linker where to put data and code to implement Memory Protection.
 *  In multi core systems there may be the need for data/code duplication.
 *  The keywords to provide this information are not part of ANSI-C and are highly compiler dependent.
 *
 *  AUTOSAR already defines concepts to abstract compiler specifics:
 *  - [AUTOSAR Compiler Abstraction](www.autosar.org/fileadmin/files/releases/4-2/software-architecture/
 *                                   implementation-integration/standard/AUTOSAR_SWS_CompilerAbstraction.pdf)
 *  - [AUTOSAR Memory Mapping](www.autosar.org/fileadmin/files/releases/3-2/software-architecture/implementation
 *                             -integration/standard/AUTOSAR_SWS_MemoryMapping.pdf)
 *
 *  They are used in MICROSAR OS. This module defines additional compiler abstraction keywords for MICROSAR OS.
 *  They are relevant to provide OS functionality or improve efficiency.
 *
 *  \{
 *
 *  \file       Os_Hal_CompilerInt.h
 *  \brief      Additional services defined here are available to the user.
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/


#ifndef OS_HAL_COMPILERINT_H
# define OS_HAL_COMPILERINT_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */

/* Os kernel module dependencies */
# include "Os_Cfg.h"
# include "Os_CommonInt.h"

/* Os hal dependencies */
# if defined(OS_STATIC_CODE_ANALYSIS)                                                                                   /* COV_OS_STATICCODEANALYSIS */
#  include "Os_Hal_StaticCodeAnalysis.h"
# else
#  if defined (OS_CFG_COMPILER_TASKING)
#   include "Os_Hal_Compiler_TaskingInt.h"
#  elif defined (OS_CFG_COMPILER_GNU)
#   include "Os_Hal_Compiler_HighTecInt.h"
#  else
#   error "Undefined or unsupported compiler"
#  endif
# endif





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

#endif /* OS_HAL_COMPILERINT_H */

/* module specific MISRA deviations:

  MD_Os_Hal_Rule2.2_2985:
      Reason:     This operation is redundant. The value of the result is always that of the left-hand operand.
      Risk:       Resulting code does not behave as expected.
      Prevention: The code contains macros with neutral values, e.g. 0 is added or subtracted. There may be cases where
                  the value has an effect. Component logic is tested carefully to ensure intended behavior.

  MD_Os_Hal_Rule8.13_3673:
      Reason:     This is a function prototype requested by the core implementation for platform independence.
                  Not all parameters are written by the according HAL implementation.
      Risk:       None.
      Prevention: None.

  MD_Os_Hal_Rule11.1_0305:
      Reason:     This statement converts a function pointer to an integral address. This is unavoidable to put the
                  function pointer to a core register.
      Risk:       None.
      Prevention: None.

  MD_Os_Hal_Rule11.2_0324:
      Reason:     This statement converts an address label (given as an array of unspecified size) to the corresponding
                  address value. This is unavoidable for memory access of that address or to put a pointer to a core
                  register.
      Risk:       None.
      Prevention: None.

  MD_Os_Hal_Rule11.4_0303:
      Reason:     This statement converts an integral address to a pointer or vice versa. This is unavoidable for
                  memory access of that address or put a pointer to a core register.
      Risk:       None.
      Prevention: None.

  MD_Os_Hal_Rule11.4_0306:
      Reason:     This statement converts a pointer to object to an integral address. This is unavoidable to read back
                  or write the corresponding address from or to a core register.
      Risk:       None.
      Prevention: None.

 MD_Os_Hal_Rule11.6_0326:
      Reason:     This statement converts an integral address to a pointer or vice versa. This is unavoidable for
                  memory access of that address or put a pointer to a core register.
      Risk:       None.
      Prevention: None.

 */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_CompilerInt.h
 **********************************************************************************************************************/

