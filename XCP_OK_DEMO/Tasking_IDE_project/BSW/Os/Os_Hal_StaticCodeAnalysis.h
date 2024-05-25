/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**
 * \ingroup    Os_Hal
 * \addtogroup Os_Hal_Compiler
 * \brief      Compiler abstraction of the ANSI C compiler used for MISRA and ReviewHelper
 *
 * \{
 *
 * \file       Os_Hal_StaticCodeAnalysis.h
 * \brief   Compiler abstraction of the ANSI C compiler used for MISRA and ReviewHelper
 * \details
 *
 *********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/


#ifndef OS_HAL_STATICCODEANALYSIS_H
# define OS_HAL_STATICCODEANALYSIS_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"
# include "Os_CommonInt.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*! \brief  Abstraction for compiler specific attributes, required by core */
# define OS_ALWAYS_INLINE            
# define OS_NORETURN                 
# define OS_FLATTEN                  
# define PS_PURE                     
# define OS_LIKELY(x)                (x)                                                                                /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define OS_UNLIKELY(x)              (x)                                                                                /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! \brief  Abstraction for HAL specific compiler attribute to prevent from inlining a function. */
# define OS_HAL_NOINLINE             


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/ 
 

/*! \brief      Declares a function with a compiler specific attribute.
 *  \details    The implementations prototype has to be created with OS_FUNC_ATTRIBUTE_DEFINITION.
 *  \param[in]  rettype       The return type of the function.
 *  \param[in]  memclass      The memory class of the function.
 *  \param[in]  attribute     The function attribute {OS_ALWAYS_INLINE; OS_PURE, ...}.
 *  \param[in]  functionName  The function name.
 *  \param[in]  arguments     The function arguments in brackets. E.g. (uint8 a, uint16 b) or (void).
 */
# define OS_FUNC_ATTRIBUTE_DECLARATION(rettype, memclass, attribute, functionName, arguments)                           /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */ \
         attribute FUNC(rettype, memclass) functionName arguments                                                       /* PRQA S 0850 */ /* MD_MSR_MacroArgumentEmpty */


/*! \brief      Provides a function prototype for function definitions with a compiler specific attribute.
 *  \details    The declaration has to be created with OS_FUNC_ATTRIBUTE_DECLARE.
 *  \param[in]  rettype       The return type of the function.
 *  \param[in]  memclass      The memory class of the function.
 *  \param[in]  attribute     The function attribute {OS_ALWAYS_INLINE; OS_PURE, ...}.
 *  \param[in]  functionName  The function name.
 *  \param[in]  arguments     The function arguments in brackets. E.g. (uint8 a, uint16 b) or (void).
 */
# define OS_FUNC_ATTRIBUTE_DEFINITION(rettype, memclass, attribute, functionName, arguments)                            /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */ \
         attribute FUNC(rettype, memclass) functionName arguments                                                       /* PRQA S 0850 */ /* MD_MSR_MacroArgumentEmpty */


/*! \brief      Compiler abstraction for preprocessor string concatenation.
 *  \details    The define is used, when a macro calls another macro with string concatenation.
 *  \param[in]  x       The called macro which needs sting concatenation.
 */
# define OS_HAL_EXPAND(x)  OS_HAL_EXPAND1(x)                                                                            /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define OS_HAL_EXPAND1(x) (x)                                                                                          /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! \brief         Abstraction of disabling core local interrupt.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_Disable()         (void)Os_Hal_DummyRead(0)


/*! \brief         Abstraction of enabling core local interrupt.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_Enable()          (void)Os_Hal_DummyRead(0)


/*! \brief         Abstraction of reading core special function register.
 *  \param[in]     x       The address offset of CSFR that should be read.
 *  \return        The value of the CSFR.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_Mfcr(x)           Os_Hal_DummyRead(x)                                                                   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! \brief         Abstraction of writing core special function register.
 *  \param[in]     x       The address offset of CSFR that should be written.
 *  \param[in]     y       The value that should be written.
 *  \context       Supervisor
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_Mtcr(x, y)        (void)Os_Hal_DummyRead(y)                                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! \brief         Abstraction of the ISYNC instruction.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_Isync()           (void)Os_Hal_DummyRead(0)


/*! \brief         Abstraction of the DSYNC instruction.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_Dsync()           (void)Os_Hal_DummyRead(0)


/*! \brief         Abstraction of the SVLCX instruction.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_Svlcx()           (void)Os_Hal_DummyRead(0)


/*! \brief         Abstraction of the RSLCX instruction.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_Rslcx()           (void)Os_Hal_DummyRead(0)


/*! \brief         Abstraction of the CLZ instruction.
 *  \param[in]     x       The value, whose leading zero needs to be counted.
 *  \return        The number of leading zero.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_Clz(x)            Os_Hal_DummyRead(x)                                                                   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! \brief         Abstraction of the DEBUG instruction.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_Debug()           (void)Os_Hal_DummyRead(0)


/*! \brief         Abstraction of the RFE instruction.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_Rfe()             (void)Os_Hal_DummyRead(0)


/*! \brief         Abstraction of the NOP instruction.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_Nop()             (void)Os_Hal_DummyRead(0)


/*! \brief         Abstraction of the JI instruction to the A11 register.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_JumpToA11()       (void)Os_Hal_DummyRead(0)


/*! \brief         Abstraction of setting the register a11.
 *  \param[in]     x       The variable which will be set to the a11 register.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_Mta11(x)          (void)Os_Hal_DummyRead(x)                                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! \brief         Abstraction of setting the register a10.
 *  \param[in]     x       The variable which will be set to the a10 register.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_Mta10(x)          (void)Os_Hal_DummyRead(x)                                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! \brief         Abstraction of setting the register a8.
 *  \param[in]     x       The variable which will be set to the a8 register.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_Mta8(x)           (void)Os_Hal_DummyRead(x)                                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! \brief         Abstraction of setting the register a9.
 *  \param[in]     x       The variable which will be set to the a9 register.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_Mta9(x)           (void)Os_Hal_DummyRead(x)                                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! \brief         Abstraction of setting the register a0.
 *  \param[in]     x       The variable which will be set to the a0 register.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_Mta0(x)           (void)Os_Hal_DummyRead(x)                                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! \brief         Abstraction of setting the register a1.
 *  \param[in]     x       The variable which will be set to the a1 register.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_Mta1(x)           (void)Os_Hal_DummyRead(x)                                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! \brief         Abstraction of setting the register a2.
 *  \param[in]     x       The variable which will be set to the a2 register.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_Mta2(x)           (void)Os_Hal_DummyRead(x)                                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! \brief         Abstraction of setting the register a4.
 *  \param[in]     x       The variable which will be set to the a4 register.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_Mta4(x)           (void)Os_Hal_DummyRead(x)                                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! \brief         Abstraction of unhandled exception entry.
 *  \details       This macro is defined as empty on purpose for MISRA and ReviewHelper
 *                 analysis.
 *  \param[in]     core       On which core the exception entry is registered.
 *  \param[in]     class      For which trap class the exception entry is registered.
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_UnhandledTrapEntry(core, class)


/*! \brief         Abstraction of memory exception entry.
 *  \details       This macro is defined as empty on purpose for MISRA and ReviewHelper
 *                 analysis.
 *  \param[in]     core       On which core the exception entry is registered.
 *  \param[in]     class      For which trap class the exception entry is registered.
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_MemoryTrapEntry(core, class)


/*! \brief         Abstraction of system call exception entry.
 *  \details       This macro is defined as empty on purpose for MISRA and ReviewHelper
 *                 analysis.
 *  \param[in]     core       On which core the entry is registered.
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_SysCallTrapEntry(core)


/*! \brief         Abstraction of user defined exception entry.
 *  \details       This macro is defined as empty on purpose for MISRA and ReviewHelper
 *                 analysis.
 *  \param[in]     core       On which core the entry is registered.
 *  \param[in]     class      For which class the entry is registered.
 *  \param[in]     UserFunc   The user function, which is to be called.
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_UserTrapEntry(core, class, UserFunc)


/*! \brief         Abstraction of Cat2 interrupt entry.
 *  \details       This macro is defined as empty on purpose for MISRA and ReviewHelper
 *                 analysis.
 *  \param[in]     core          On which core the entry is registered.
 *  \param[in]     level         For which level the entry is registered.
 *  \param[in]     systemlevel   The interrupt level, until which the interrupts are disabled.
 *  \param[in]     isrconfig     The pointer to the ISR configuration data, which should be handled.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_Cat2InterruptEntry(core, level, systemlevel, isrconfig)


/*! \brief         Abstraction of unhandled interrupt entry.
 *  \details       This macro is defined as empty on purpose for MISRA and ReviewHelper
 *                 analysis.
 *  \param[in]     core          On which core the entry is registered.
 *  \param[in]     level         For which level the entry is registered.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_UnhandledInterruptEntry(core, level)


/*! \brief         Abstraction of Cat0 interrupt entry.
 *  \details       This macro is defined as empty on purpose for MISRA and ReviewHelper
 *                 analysis.
 *  \param[in]     core       On which core the entry is registered.
 *  \param[in]     level      For which level the entry is registered.
 *  \param[in]     func       The user function, which is to be called.
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_Cat0InterruptEntry(core, level, function)


/*! \brief         Abstraction of Cat1 interrupt entry.
 *  \details       This macro is defined as empty on purpose for MISRA and ReviewHelper
 *                 analysis.
 *  \param[in]     core       On which core the entry is registered.
 *  \param[in]     level      For which level the entry is registered.
 *  \param[in]     func       The user function, which is to be called.
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_Cat1InterruptEntry(core, level, function)


/*! \brief         Abstraction of function declaration to trigger system call.
 *  \details       This macro is defined as empty on purpose for MISRA and ReviewHelper
 *                 analysis.
 *  \param[in]     name       The function name.
 *  \param[in]     parameters The parameters
 *  \param[in]     id         The system call identifier (TIN in system call handler)
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_DeclareTrapFunction(name, parameters, id)                                                               /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */ \
         OS_FUNC_ATTRIBUTE_DECLARATION(void, OS_CODE, OS_HAL_NOINLINE, name, parameters)


/*! \brief         Abstraction of function definition to trigger system call.
 *  \details       This macro is defined as empty on purpose for MISRA and ReviewHelper
 *                 analysis.
 *  \param[in]     name                  The function name.
 *  \param[in]     parametersAsArguments The parameters in form of the function arguments (with types)
 *  \param[in]     parameters            The pure name of the parameters
 *  \param[in]     id                    The system call identifier (TIN in system call handler)
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
# define Os_Hal_DefineTrapFunction(name, parametersAsArguments, parameters, id)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! \brief         Abstraction of reading the register a10.
 *  \return        The value of a10 register.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE uint32, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_Mfa10, (void));
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE uint32, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_Mfa10, (void))                   /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  return 0;
}


/*! \brief         Abstraction of reading the register a11.
 *  \return        The value of a11 register.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE uint32, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_Mfa11, (void));
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE uint32, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_Mfa11, (void))                   /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  return 0;
}


/*! \brief         Abstraction of reading the register a8.
 *  \return        The value of a8 register.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE uint32, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_Mfa8, (void));
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE uint32, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_Mfa8, (void))                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  return 0;
}


/*! \brief         Abstraction of reading the register a9.
 *  \return        The value of a9 register.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE uint32, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_Mfa9, (void));
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE uint32, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_Mfa9, (void))                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  return 0;
}


/*! \brief         Abstraction of reading the register a0.
 *  \return        The value of a0 register.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE uint32, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_Mfa0, (void));
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE uint32, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_Mfa0, (void))                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  return 0;
}


/*! \brief         Abstraction of reading the register a1.
 *  \return        The value of a1 register.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE uint32, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_Mfa1, (void));
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE uint32, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_Mfa1, (void))                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  return 0;
}


/*! \brief         Abstraction of the CMPSWAP instruction.
 *  \param[in]     x       The address of the spinlock variable.
 *  \param[in]     y       The value that should be swapped.
 *  \param[in]     z.......The condition value. Only when *x == z, y is swapped
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 */
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE uint32, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_CmpSwap,
(volatile uint32* x, uint32 y, uint32 z));
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE uint32, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_CmpSwap,                         /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
(volatile uint32* x, uint32 y, uint32 z))
{
  if(*x == z)
  {
    *x = y;                                                                                                             /* SBSW_OS_HAL_PWA_CALLER */
  }
  return *x;
}


/*! \brief         Dummy read function to avoid compiler/MISRA warnings.
 *  \param[in]     x       The variable to read
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \pre           -
 */
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE uint32, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_DummyRead, (uint32 x));
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE uint32, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_DummyRead, (uint32 x))           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
{
  volatile uint32 dummy;
  dummy = x;
  while(dummy == 0uL)
  {
    ;
  }
  return dummy;
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_HAL_STATICCODEANALYSIS_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_StaticCodeAnalysis.h
 *********************************************************************************************************************/
