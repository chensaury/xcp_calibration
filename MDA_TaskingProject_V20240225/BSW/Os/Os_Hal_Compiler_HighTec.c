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
 *  \addtogroup Os_Hal_Compiler
 *  \{
 *
 *  \file
 *  \brief        Compiler abstraction for HighTec compiler.
 *  \details
 *  Internal comment removed.
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
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */

#define OS_HAL_COMPILER_HIGHTEC_SOURCE

# ifdef CDK_CHECK_MISRA                                                                                                 /* COV_OS_STATICCODEANALYSIS */
#  ifndef OS_STATIC_CODE_ANALYSIS                                                                                       /* COV_OS_STATICCODEANALYSIS */
#    define OS_STATIC_CODE_ANALYSIS
#  endif
# endif


#ifndef OS_STATIC_CODE_ANALYSIS                                                                                         /* COV_OS_HALCMSTATICCODEANALYSIS */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os hal module dependencies */
# include "Os_Hal_Compiler.h"

# if defined (OS_CFG_COMPILER_GNU)

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

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
# include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  Os_Hal_UnhandledExceptionHandler()
 **********************************************************************************************************************/
/*! \brief         branch island for all exception vectors without user function (unhandled exception)
 *                 it switches the stack and calls Os_Hal_UnhandledExc
 *                 the parameter passed to Os_Hal_UnhandledExc are
 *                    D4: exception class and TIN (already prepared by exception vector handler)
 *                    D5: current PCXI value
 *                    A4: causing address (potential return address)
 *                    D6: current Stack memory region lower
 *                    D7: current Stack memory region upper
 *  \context      EXCEPTION VECTOR
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(void, OS_CODE, OS_HAL_NOINLINE, Os_Hal_UnhandledExceptionHandler, (void));
OS_FUNC_ATTRIBUTE_DECLARATION(void, OS_CODE, OS_HAL_NOINLINE, Os_Hal_UnhandledExceptionHandler, (void))
{
  __asm ("mfcr %d6, " OS_HAL_EXPAND(OS_HAL_COREMPU_DPR_LOW0));      /* prepare parameters for C-Function; D6 = OS_HAL_COREMPU_DPR_LOW0 */
  __asm ("mfcr %d7, " OS_HAL_EXPAND(OS_HAL_COREMPU_DPR_UPPER0));    /* prepare parameters for C-Function; D7 = OS_HAL_COREMPU_DPR_UPPER0 */
  __asm ("mfcr %d14, " OS_HAL_EXPAND(OS_HAL_CORE_ID_REGISTER));     /* get core ID; D14 = Core ID */
  __asm ("movh.a %a4, hi:OsCfg_Stack_KernelStacks");                /* get address of the correct kernal stack (indexed by core ID) */
  __asm ("lea %a4,[%a4]lo:OsCfg_Stack_KernelStacks");               /* get address of the correct kernal stack (indexed by core ID); A4 = &OsCfg_Stack_KernelStacks */
  __asm ("addsc.a %a15,%a4,%d14,2");                                /* choose the correct element out of the array; A15 = &OsCfg_Stack_KernelStacks[Core ID] */
  __asm ("ld.a %a15,[%a15]");                                       /* get the pointer to the Os_Hal_ContextStackConfigType struct */
  __asm ("ld.w %d12,[%a15]");                                       /* get the content of Stack.StackRegionStart; D12 = Stack.StackRegionStart */
  __asm ("mtcr " OS_HAL_EXPAND(OS_HAL_COREMPU_DPR_LOW0)", %d12");   /* OS_HAL_COREMPU_DPR_LOW0 = D12 */
  __asm ("ld.w %d12,[%a15]4");                                      /* get the content of Stack.StackRegionEnd;   D12 = Stack.StackRegionEnd */
  __asm ("mtcr " OS_HAL_EXPAND(OS_HAL_COREMPU_DPR_UPPER0)", %d12"); /* OS_HAL_COREMPU_DPR_UPPER0 = D12 */
  __asm ("isync");
  __asm ("mov.a %a10, %d12");                                       /* SP = Stack.StackRegionEnd; stack switch */
  __asm ("mfcr %d5, " OS_HAL_EXPAND(OS_HAL_PCXI_OFFSET));           /* prepare parameters for C-Function; D5 = PCXI */
  __asm ("mov.aa %a4, %a11");                                       /* prepare parameters for C-Function; A4 = Return Address (A11) */
  __asm ("call Os_Hal_UnhandledExc");                               /* call the C-Function; the stack MPU regions are restored within the C-Function */
  __asm ("rslcx");                                                  /* restore lower context saved exception vector handler */
  __asm ("rfe");                                                    /* return from exception; old stackpointer is restored with this instruction */
}

/***********************************************************************************************************************
 *  Os_Hal_MemFaultExceptionHandler()
 **********************************************************************************************************************/
/*! \brief         branch island for mem fault exception vector
 *                 it switches the stack and calls Os_Hal_MemFault
 *                 the parameter passed to Os_Hal_MemFault are
 *                    D4: exception class and TIN (already prepared by exception vector handler)
 *                    D5: current PCXI value
 *                    A4: causing address (potential return address)
 *                    D6: current Stack memory region lower
 *                    D7: current Stack memory region upper
 *  \context      EXCEPTION VECTOR
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(void, OS_CODE, OS_HAL_NOINLINE, Os_Hal_MemFaultExceptionHandler, (void));
OS_FUNC_ATTRIBUTE_DECLARATION(void, OS_CODE, OS_HAL_NOINLINE, Os_Hal_MemFaultExceptionHandler, (void))
{
  __asm ("mfcr %d6, " OS_HAL_EXPAND(OS_HAL_COREMPU_DPR_LOW0));      /* prepare parameters for C-Function; D6 = OS_HAL_COREMPU_DPR_LOW0 */
  __asm ("mfcr %d7, " OS_HAL_EXPAND(OS_HAL_COREMPU_DPR_UPPER0));    /* prepare parameters for C-Function; D7 = OS_HAL_COREMPU_DPR_UPPER0 */
  __asm ("mfcr %d14, " OS_HAL_EXPAND(OS_HAL_CORE_ID_REGISTER));     /* get core ID; D14 = Core ID */
  __asm ("movh.a %a4, hi:OsCfg_Stack_KernelStacks");                /* get address of the correct kernal stack (indexed by core ID) */
  __asm ("lea %a4,[%a4]lo:OsCfg_Stack_KernelStacks");               /* get address of the correct kernal stack (indexed by core ID); A4 = &OsCfg_Stack_KernelStacks */
  __asm ("addsc.a %a15,%a4,%d14,2");                                /* choose the correct element out of the array; A15 = &OsCfg_Stack_KernelStacks[Core ID] */
  __asm ("ld.a %a15,[%a15]");                                       /* get the pointer to the Os_Hal_ContextStackConfigType struct */
  __asm ("ld.w %d12,[%a15]");                                       /* get the content of Stack.StackRegionStart; D12 = Stack.StackRegionStart */
  __asm ("mtcr " OS_HAL_EXPAND(OS_HAL_COREMPU_DPR_LOW0)", %d12");   /* OS_HAL_COREMPU_DPR_LOW0 = D12 */
  __asm ("ld.w %d12,[%a15]4");                                      /* get the content of Stack.StackRegionEnd;   D12 = Stack.StackRegionEnd */
  __asm ("mtcr " OS_HAL_EXPAND(OS_HAL_COREMPU_DPR_UPPER0)", %d12"); /* OS_HAL_COREMPU_DPR_UPPER0 = D12 */
  __asm ("isync");
  __asm ("mov.a %a10, %d12");                                       /* SP = Stack.StackRegionEnd; stack switch */
  __asm ("mfcr %d5, " OS_HAL_EXPAND(OS_HAL_PCXI_OFFSET));           /* prepare parameters for C-Function; D5 = PCXI */
  __asm ("mov.aa %a4, %a11");                                       /* prepare parameters for C-Function; A4 = Return Address (A11) */
  __asm ("call Os_Hal_MemFault");                                   /* call the C-Function; the stack MPU regions are restored within the C-Function */
  __asm ("rslcx");                                                  /* restore lower context saved at function start */
  __asm ("rfe");                                                    /* return from exception; old stackpointer is restored with this instruction */
}

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* if defined (OS_CFG_COMPILER_GNU) */

#endif /* #ifndef (CDK_CHECK_MISRA) */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Compiler_Arm.c
 *********************************************************************************************************************/
