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
 *  \ingroup    Os_Hal
 *  \defgroup   Os_Hal_Context  HAL Context
 *  \brief      Context switching primitives.
 *  \details
 *  This module provides the hardware specific primitives for context initialization, switching and resuming.
 *  The kernel uses the context primitives to implement:
 *  - Tasks
 *  - ISRs
 *  - Hooks
 *  - Service Functions
 *
 *  Hardware Context
 *  ----------------
 *  The hardware context is the minimal set of hardware registers which are used by a thread, to allow interruption
 *  and resumption. Typically the hardware context contains the following information:
 *
 *  - Core
 *    - Program counter
 *    - Link register
 *    - Stack pointer
 *    - Machine status register(s)
 *    - Scratch registers
 *    - Permanent registers
 *  - FPU
 *    - FPU registers
 *  - MPU/MMU
 *    - Stack region configuration
 *
 *  ### Optimization
 *
 *  \note Add a FPU interface, so kernel decides generally when to save/restore/disable/enable FPU.
 *        The context switches would get faster, because FPU registers are typically a lot of data to save/restore.
 *
 *
 *  \see \ref ContextSwitch
 *  \see \ref Os_Thread
 *  \see [Setcontext C-functions](en.wikipedia.org/wiki/Setcontext)
 *  \see [Context](en.wikipedia.org/wiki/Context_%28computing%29)
 *
 *  \{
 *  \file       Os_Hal_ContextInt.h
 *  \brief      Context switching primitives.
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/


#ifndef OS_HAL_CONTEXTINT_H
# define OS_HAL_CONTEXTINT_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_Context_Types.h"

/* Os kernel module dependencies */
# include "Os_MemoryProtection_Cfg.h"

/* Os HAL dependencies */
# include "Os_Hal_CoreInt.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/*! This function just continues the execution with the already prepared context. */
# define Os_Hal_ContextIntGo()                                                                  \
         Os_Hal_Mtcr(OS_HAL_PSW_OFFSET, Os_Hal_Mfcr(OS_HAL_PSW_OFFSET) & ~OS_HAL_PSW_CDE_MASK); \
         Os_Hal_Isync();                                                                        \
         Os_Hal_Rfe()

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/*! Minimal set of hardware registers to be able to suspend and resume a thread.
 *
 *  ### Implementation Hint ###
 *  This data type typically holds the following information:
 *  - Stack region
 *  - Stack pointer
 *  - Link register
 *  - Machine status register
 *  - Permanent registers
 *
 *  Some of this information may be automatically saved by hardware (on stack or some kind of dedicated saving area).
 *  In this case you may need to save a pointer to this data, to be able to instruct the hardware to restore it later.
 */
struct Os_Hal_ContextType_Tag
{
  /*! The link register, from which the thread will be proceeded. */
  uint32 Lr;

  /*! The (encoded) pointer to the previous context (CSA) including the following information:
   *  permanent registers (stored in CSA pointed by this pointer),
   *  stack pointer (stored in CSA pointed by this pointer),
   *  PSW (stored in CSA pointed by this pointer),
   *  interrupt status (encoded in this pointer),
   *  interrupt level (encoded in this pointer). */
  uint32 PreviousContextInfo;

  /*! The (encoded) pointer to the reserved context (CSA). */
  uint32 InitPCXI;
  
  /*! The (encoded) pointer to the running context during initialization (CSA). */
  uint32 RunningPCXI;

  /*! The lower address of the MPU region for stack. */
  uint32 MpuRegionForStackLow;

  /*! The upper address of the MPU region for stack. */
  uint32 MpuRegionForStackUpper;

  /*! The first pointer parameter. */
  uint32 A4;
};


/*! Information needed to initialize the context of a thread.
 *
 *  ### Implementation Hint ###
 *  This data type typically holds the following information:
 *  - Stack region
 *  - Entry address
 *  - Machine status register
 */
struct Os_Hal_ContextConfigType_Tag
{
  /*! The stack end address of this thread (the upper address). */
  uint32 StackEndAddr;

  /*! The stack start address of this thread (the lower address). */
  uint32 StackStartAddr;

  /*! The PSW register configuration containing
      - protection set (corresponding to memory protection identifier),
      - accessing privilege (2 for privileged thread, 1 for non-privileged thread),
      - IS_MASK (1 for trusted thread, 0 for non-trusted thread)
      - CDE_MASK (always set). */
  uint32 ProgramStatus;

  /*! The execution start address of this thread. */
  uint32 Entry;

  /*! The return address of this thread, which is depending on whether it is a task, ISR, trusted or non-trusted. */
  uint32 ReturnAddress;

  /*! The interrupt level and global flag of this thread, which is depending on whether it is a task, a ISR or
   *  a Hook. This attribute is to be written into PCXI register. */
  uint32 IntStatus;
};


/*! Information needed to perform a stack switch.
 *
 *  ### Implementation Hint ###
 *  This data type typically holds the following information:
 *  - Stack region
 */
struct Os_Hal_ContextStackConfigType_Tag
{
  /*! Stack start address (lower bound) */
  uint32 StackRegionStart;

  /*! Stack end address (higher bound) */
  uint32 StackRegionEnd;
};


 /*! Set of floating point registers to be able to suspend and resume a thread. */
 struct Os_Hal_ContextFpuContextType_Tag
 {
   /*! Dummy data: fpu registers are already saved in the context switch mechanism.. */
   uint32 DummyFpuFlagRegister;
 };
 
/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  Os_Hal_ContextInit()
 **********************************************************************************************************************/
/*! \brief        Initialize the given context for the first time, such that it performs a thread start,
 *                if it is resumed the next time.
 *  \details      The kernel never starts a thread but only resumes it. Therefore this function is necessary to
 *                initialize the context such that the thread is started.
 *                This function shall initialize the context so that the task or ISR starts at its start address on
 *                the next resumption.
 *                The kernel uses this function during OS initialization to initialize all thread contexts.
 *  \param[in]    Config    Context configuration. Parameter must not be NULL.
 *  \param[out]   Context   Context to initialize. Parameter must not be NULL.
 *  \context      ANY
 *  \reentrant    TRUE for different context.
 *  \synchronous  TRUE
 *  \pre          Supervisor mode.
 *  \pre          Interrupts locked to TP lock level.
 *  \pre          Concurrent access to given data shall be prevented.
 *  \pre          Config and Context parameter belong together.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextInit,
(
  P2CONST(Os_Hal_ContextConfigType, AUTOMATIC, OS_CONST) Config,
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context
));


/***********************************************************************************************************************
 *  Os_Hal_ContextReset()
 **********************************************************************************************************************/
/*! \brief        Reset the given context, such that it performs a thread start, if it is resumed the next time.
 *  \details      This function shall initialize the context so that the task starts at its start address on
 *                the next resumption.
 *                The kernel uses this function to kill tasks, but not for self-termination.
 *  \param[in]    Config    Context configuration.  Parameter must not be NULL.
 *  \param[out]   Context   Context to reset.  Parameter must not be NULL.
 *  \context      ANY
 *  \reentrant    TRUE for different context.
 *  \synchronous  TRUE
 *  \pre          Supervisor mode.
 *  \pre          Interrupts locked to TP lock level.
 *  \pre          Concurrent access to given data shall be prevented.
 *  \pre          Config and Context parameter belong together.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextReset,
(
  P2CONST(Os_Hal_ContextConfigType, AUTOMATIC, OS_CONST) Config,
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context
));


/***********************************************************************************************************************
 *  Os_Hal_ContextSetParameter()
 **********************************************************************************************************************/
/*! \brief        Sets the first parameter register of the given context.
 *  \details      The kernel uses this function to prepare a context which needs a parameter (e.g. hooks and
 *                service functions).
 *
 *  \param[out]   Context    Context to modify. Parameter must not be NULL.
 *  \param[in]    Parameter  Parameter which shall be the first argument. Parameter must not be NULL.
 *
 *  \context      ANY
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 *  \pre          Interrupts locked to TP lock level.
 *  \pre          Concurrent access to given data shall be prevented.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextSetParameter,
(
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context,
  P2CONST(void, AUTOMATIC, OS_VAR_NOINIT) Parameter
));


/***********************************************************************************************************************
 *  Os_Hal_ContextSetStack()
 **********************************************************************************************************************/
/*! \brief        Sets the stack of the given context.
 *  \details      The kernel uses this function to prepare a context which is executed on a separate stack.
 *
 *  \param[out]   Context    Context to modify. Parameter must not be NULL.
 *  \param[in]    Stack      Stack which shall be used. Parameter must not be NULL.
 *
 *  \context      ANY
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 *  \pre          Interrupts locked to TP lock level.
 *  \pre          Concurrent access to given data shall be prevented.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextSetStack,
(
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context,
  P2CONST(Os_Hal_ContextStackConfigType, AUTOMATIC, OS_VAR_NOINIT) Stack
));


/***********************************************************************************************************************
 *  Os_Hal_ContextGetStack()
 **********************************************************************************************************************/
/*! \brief        Get the stack settings.
 *
 *  \details      Get the stack config from given context config.
 *
 *  \param[in]    Context  Pointer to given context config. Parameter must not be NULL.
 *
 *  \param[out]   Stack    Pointer to stack config which has to be set. Parameter must not be NULL.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextGetStack,
(
  P2CONST(Os_Hal_ContextConfigType, AUTOMATIC, OS_CONST) Context,
  P2VAR(Os_Hal_ContextStackConfigType, AUTOMATIC, OS_VAR_NOINIT) Stack
));


/***********************************************************************************************************************
 *  Os_Hal_ContextSetInterruptState()
 **********************************************************************************************************************/
/*! \brief        Sets the interrupt state of the given context.
 *  \details      The kernel uses this function to prepare the interrupt state of the given context.
 *
 *  \param[out]   Context          Context to modify. Parameter must not be NULL.
 *  \param[in]    InterruptState   Interrupt state which shall be used. Parameter must not be NULL.
 *
 *  \context      ANY
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 *  \pre          Interrupts locked to TP lock level.
 *  \pre          Concurrent access to given data shall be prevented.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextSetInterruptState,
(
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context,
  P2CONST(Os_Hal_IntStateType, AUTOMATIC, OS_VAR_NOINIT) InterruptState
));


/***********************************************************************************************************************
 *  Os_Hal_ContextSetUserMsrBits()
 **********************************************************************************************************************/
/*! \brief           Updates the MSR of the given context according to the user configuration.
 *  \details         The kernel uses this function to prepare the MSR of the given context according to the user setup.
 *
 *  \param[in, out]  Context    Context to modify. Parameter must not be NULL.
 *
 *  \context         ANY
 *
 *  \reentrant       TRUE
 *  \synchronous     TRUE
 *
 *  \pre             Supervisor mode.
 *  \pre             Concurrent access to given data shall be prevented.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextSetUserMsrBits,
(
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context
));


/***********************************************************************************************************************
 *  Os_Hal_ContextFirstResume()
 **********************************************************************************************************************/
/*! \brief        Resume the given context for the first time.
 *  \details      The kernel uses this function to enter the first thread after OS initialization.
 *                This function is called when no thread has been started before.
 *                On some architectures you may have to perform some extra activities here
 *                (e.g. on TriCore release all CSAs used by the startup code).
 *  \param[in]    Next      Pointer to next context. Parameter must not be NULL.
 *  \context      ANY
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          Supervisor mode.
 *  \pre          Interrupts locked to TP lock level.
 *  \pre          Concurrent access to given data shall be prevented.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextFirstResume,
(
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Next
));


/***********************************************************************************************************************
 *  Os_Hal_ContextSwitch()
 **********************************************************************************************************************/
/*! \brief        Switch the current hardware context.
 *  \details      Save the current hardware context and restore another one.
 *                The kernel uses this function to switch between tasks.
 *  \param[out]   Current  Pointer where to save the current context. Parameter must not be NULL.
 *  \param[in]    Next     Pointer from where the next context shall be restored. Parameter must not be NULL.
 *  \context      ANY
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          Supervisor mode.
 *  \pre          Interrupts locked to TP lock level.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(void, OS_CODE, OS_HAL_NOINLINE,
Os_Hal_ContextSwitch,
(
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Current,
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Next
));


/***********************************************************************************************************************
 *  Os_Hal_ContextResetAndResume()
 **********************************************************************************************************************/
/*! \brief        Reset the current context and resume the next context.
 *  \details      The kernel uses this function to self-terminate tasks (i.e. to close the current context
 *                and resume another context).
 *                On some architectures both steps are highly coupled. E.g. on TriCore you cannot simply free the
 *                current thread's CSA chain and return to resume another context later.
 *                You always have to perform a CSA switch afterwards.
 *                For this reason this function shall perform both steps.
 *  \param[in]    CurrentConfig   Context configuration of the current thread. Parameter must not be NULL.
 *  \param[out]   Current         Context of the current thread to reset. Parameter must not be NULL.
 *  \param[in]    Next            Pointer to next context. Parameter must not be NULL.
 *  \context      ANY
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          Supervisor mode.
 *  \pre          Interrupts locked to TP lock level.
 *  \pre          Concurrent access to given data shall be prevented.
 *  \pre          Config and Context parameter belong together.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextResetAndResume,
(
  P2CONST(Os_Hal_ContextConfigType, AUTOMATIC, OS_CONST) CurrentConfig,
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Current,
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Next
));


/***********************************************************************************************************************
 *  Os_Hal_ContextAbort()
 **********************************************************************************************************************/
/*! \brief        Abort the given context, so it will execute the return function when it is resumed.
 *
 *  \details      The kernel uses this function to terminate ISRs.
 *
 *  \param[in]      Config  Configuration of the context. Parameter must not be NULL.
 *  \param[in,out]  Context Context to abort. Parameter must not be NULL.
 *
 *  \context      ISR2
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 *  \pre          Interrupts locked to TP lock level.
 *  \pre          Concurrent access to given data shall be prevented.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextAbort,
(
  P2CONST(Os_Hal_ContextConfigType, AUTOMATIC, OS_CONST) Config,
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context
));


/***********************************************************************************************************************
 *  Os_Hal_ContextCall()
 **********************************************************************************************************************/
/*! \brief        Suspend the current context and start the next context on the current stack.
 *  \details      The kernel uses this function to execute functions with a different privilege mode.
 *                It shall save the whole context of the caller (Current) and execute Next.
 *
 *                Starting Next includes:
 *                - Update interrupt state.
 *                - Update first argument register which is given in Next.
 *                - Adopt the stack of the current context to the next context.
 *                - Update privilege mode.
 *                - Execute function.
 *
 *  \param[out]   Current   Pointer where to save the current context. Parameter must not be NULL.
 *  \param[in]    Next      Pointer to the next context. Parameter must not be NULL.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 *  \pre          Interrupts locked to TP lock level.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(void, OS_CODE, OS_HAL_NOINLINE,
Os_Hal_ContextCall,
(
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Current,
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Next
));



/***********************************************************************************************************************
 *  Os_Hal_ContextCallOnStack()
 **********************************************************************************************************************/
/*! \brief        Suspend the current context and start the next context on a different stack.
 *  \details      This function is identical to \ref Os_Hal_ContextCall() but shall also perform a stack switch.
 *
 *                Starting Next includes:
 *                - Switch stack.
 *                - Update interrupt state.
 *                - Update first argument register which is given in Next.
 *                - Update privilege mode.
 *                - Execute function.
 *
 *  \param[out]   Current   Pointer where to save the current context. Parameter must not be NULL.
 *  \param[in]    Next      Pointer to the next context. Parameter must not be NULL.

 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 *  \pre          Interrupts locked to TP lock level.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(void, OS_CODE, OS_HAL_NOINLINE,
Os_Hal_ContextCallOnStack,
(
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Current,
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Next
));


/***********************************************************************************************************************
 *  Os_Hal_ContextReturn()
 **********************************************************************************************************************/
/*! \brief        Resume the given context which has been saved during a context call.
 *  \details      This function is the return function of \ref Os_Hal_ContextCall() and
 *                \ref Os_Hal_ContextCallOnStack().
 *
 *  \param[in]    Current  Context of the current thread, when returning from hooks/ISRs.
 *                         Context of the service function, when returning from service functions.
 *                         Parameter must not be NULL.
 *  \param[in]    Next     Context which shall be resumed.
 *                         Parameter must not be NULL.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 *  \pre          Interrupts locked to TP lock level.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextReturn,
(
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Current,
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Next
));


/***********************************************************************************************************************
 *  Os_Hal_ContextIsExceptionContextSupported()
 **********************************************************************************************************************/
/*! \brief        Returns whether the HAL supports exception context manipulation.
 *  \details      --no details--
 *
 *  \retval       !0    exception context can be manipulated.
 *  \retval       0     exception context cannot be manipulated.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextIsExceptionContextSupported,
(
  void
));


/***********************************************************************************************************************
 *  Os_Hal_ContextIntCleanupCSAs()
 **********************************************************************************************************************/
/*! \brief        Clean up the used CSAs by a thread.
 *  \details      This is an internal function which destroys the given context by freeing the CSAs pointed by "Context"
 *  \param[out]   Context                       Context to destroy. Parameter must not be NULL.
 *  \param[in]    PreviousGlobalIntState        Previous global interrupt status. Parameter must not be NULL.
 *  \context      ANY
 *  \reentrant    TRUE for different context.
 *  \synchronous  TRUE
 *  \pre          Interrupts are disabled up to TP lock level.
 *  \pre          Supervisor mode. 
 *  \pre          Concurrent access to given data shall be prevented.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextIntCleanupCSAs,
(
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context,
  P2CONST(Os_Hal_IntGlobalStateType, AUTOMATIC, OS_CONST) PreviousGlobalIntState
));


/***********************************************************************************************************************
 *  Os_Hal_ContextIntPrepareCSAContent()
 **********************************************************************************************************************/
/*! \brief        Prepare the content in the CSA used for thread running.
 *  \details      This is an internal function which initialize the CSA fields, which are used for thread running.
 *  \param[in]    CurrentConfig                 Context configuration. Parameter must not be NULL.
 *  \param[in]    Context                       Context to initialize. Parameter must not be NULL.
 *  \context      ANY
 *  \reentrant    TRUE for different context.
 *  \synchronous  TRUE
 *  \pre          Interrupts are disabled up to TP lock level.
 *  \pre          Supervisor mode.
 *  \pre          Concurrent access to given data shall be prevented.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextIntPrepareCSAContent,
(
  P2CONST(Os_Hal_ContextConfigType, AUTOMATIC, OS_CONST) CurrentConfig,
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context
));


/***********************************************************************************************************************
 *  Os_Hal_ContextIntInitialize()
 **********************************************************************************************************************/
/*! \brief        Initialize the running context of a thread.
 *  \details      This is an internal function which initialize the actual starting context of a thread based on the
 *                given configuration
 *  \param[in]    CurrentConfig                 Context configuration. Parameter must not be NULL.
 *  \param[in]    Context                       Context to initialize. Parameter must not be NULL.
 *  \param[in]    PreviousGlobalIntState        Previous global interrupt status. Parameter must not be NULL.
 *  \context      ANY
 *  \reentrant    TRUE for different context.
 *  \synchronous  TRUE
 *  \pre          Interrupts are disabled up to TP lock level.
 *  \pre          Supervisor mode.
 *  \pre          Concurrent access to given data shall be prevented.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextIntInitialize,
(
  P2CONST(Os_Hal_ContextConfigType, AUTOMATIC, OS_CONST) CurrentConfig,
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context,
  P2CONST(Os_Hal_IntGlobalStateType, AUTOMATIC, OS_CONST) PreviousGlobalIntState
));


/***********************************************************************************************************************
 *  Os_Hal_ContextIntInitializeReserved()
 **********************************************************************************************************************/
/*! \brief        Initialize the running context of a thread.
 *  \details      This is an internal function which initialize the actual starting context of a thread based on the
 *                given configuration
 *  \param[in]    CurrentConfig                 Context configuration. Parameter must not be NULL.
 *  \param[in]    Context                       Runtime context. Parameter must not be NULL.
 *  \param[in]    PreviousGlobalIntState        Previous global interrupt status. Parameter must not be NULL.
 *  \context      ANY
 *  \reentrant    TRUE for different context.
 *  \synchronous  TRUE
 *  \pre          Interrupts are disabled up to TP lock level.
 *  \pre          Supervisor mode.
 *  \pre          Concurrent access to given data shall be prevented.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextIntInitializeReserved,
(
  P2CONST(Os_Hal_ContextConfigType, AUTOMATIC, OS_CONST) CurrentConfig,
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context,
  P2CONST(Os_Hal_IntGlobalStateType, AUTOMATIC, OS_CONST) PreviousGlobalIntState
));


/***********************************************************************************************************************
 *  Os_Hal_ContextIntSave()
 **********************************************************************************************************************/
/*! \brief        Save the context variables of a thread.
 *  \details      This function saves the context of currently interrupted thread to its context variables.
 *  \param[in]    Context     Context that should be saved. Parameter must not be NULL.
 *  \context      ANY
 *  \reentrant    TRUE for different context.
 *  \synchronous  TRUE
 *  \pre          Interrupts locked to TP lock level.
 *  \pre          Supervisor mode.
 *  \pre          Concurrent access to given data shall be prevented.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextIntSave,
(
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context
));


/***********************************************************************************************************************
 *  Os_Hal_ContextIntRestore()
 **********************************************************************************************************************/
/*! \brief        Restore the context variables of a thread.
 *  \details      This function restores the context of next thread from its context variables.
 *  \param[in]    Context      Context that should be restored. Parameter must not be NULL.
 *  \context      ANY
 *  \reentrant    TRUE for different context.
 *  \synchronous  TRUE
 *  \pre          Interrupts are disabled up to TP lock level.
 *  \pre          Supervisor mode.
 *  \pre          Concurrent access to given data shall be prevented.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextIntRestore,
(
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context
));


/***********************************************************************************************************************
 *  Os_Hal_ContextFetchInitialFpuContext()
 **********************************************************************************************************************/
/*! \brief        Initialize the given FPU context structure
 *  \details      --no details--
 *
 *  \param[out]   InitialContext   Pointer to the initial FPU context. Parameter must not be NULL.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE for different context.
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 *  \pre          Interrupts locked to TP lock level.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextFetchInitialFpuContext,
(
  P2VAR(Os_Hal_ContextFpuContextType, AUTOMATIC, OS_VAR_NOINIT) InitialContext
));


/***********************************************************************************************************************
 *  Os_Hal_ContextInitFpu()
 **********************************************************************************************************************/
/*! \brief        Initialize the FPU configuration from the given initial value.
 *  \details      This function restores the configuration of the FPU. Intermediate registers are not modified.
 *
 *  \param[in]    InitialContext   Pointer to the initial FPU context. Parameter must not be NULL.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE for different context.
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 *  \pre          Interrupts locked to TP lock level.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextInitFpu,
(
  P2CONST(Os_Hal_ContextFpuContextType, AUTOMATIC, OS_VAR_NOINIT) InitialContext
));


/***********************************************************************************************************************
 *  Os_Hal_ContextInitFpuContext()
 **********************************************************************************************************************/
/*! \brief        Initialize the the given FPU context structure
 *  \details      --no details--
 *
 *  \param[out]   Context          Pointer where to save the initial FPU context. Parameter must not be NULL.
 *  \param[in]    InitialContext   Pointer to the initial FPU context. Parameter must not be NULL.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE for different context.
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 *  \pre          Interrupts locked to TP lock level.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextInitFpuContext,
(
  P2VAR(Os_Hal_ContextFpuContextType, AUTOMATIC, OS_VAR_NOINIT) Context,
  P2CONST(Os_Hal_ContextFpuContextType, AUTOMATIC, OS_VAR_NOINIT) InitialContext
));


/***********************************************************************************************************************
 *  Os_Hal_ContextStoreFpuContext()
 **********************************************************************************************************************/
/*! \brief        Store the FPU context into the given structure
 *  \details      --no details--
 *  \param[out]   Context   Pointer where to save the current FPU context. Parameter must not be NULL.
 *  \context      OS_INTERNAL
 *  \reentrant    TRUE for different context.
 *  \synchronous  TRUE
 *  \pre          Supervisor mode.
 *  \pre          Interrupts locked to TP lock level.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextStoreFpuContext,
(
  P2VAR(Os_Hal_ContextFpuContextType, AUTOMATIC, OS_VAR_NOINIT) Context
));


/***********************************************************************************************************************
 *  Os_Hal_ContextRestoreFpuContext()
 **********************************************************************************************************************/
/*! \brief        Restore the FPU context from the given structure
 *  \details      --no details--
 *  \param[out]   Context   Pointer where to load the current FPU context from. Parameter must not be NULL.
 *  \context      OS_INTERNAL
 *  \reentrant    TRUE for different context.
 *  \synchronous  TRUE
 *  \pre          Supervisor mode.
 *  \pre          Interrupts locked to TP lock level.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextRestoreFpuContext,
(
  P2CONST(Os_Hal_ContextFpuContextType, AUTOMATIC, OS_VAR_NOINIT) Context
));


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_HAL_CONTEXTINT_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_ContextInt.h
 **********************************************************************************************************************/

