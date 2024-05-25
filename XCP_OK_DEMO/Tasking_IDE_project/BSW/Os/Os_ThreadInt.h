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
 *  \ingroup     Os_Kernel
 *  \defgroup    Os_Thread Thread
 *  \brief       An abstract user code container.
 *  \details
 *  A *thread* is an user code container. It is the summary of all information needed to identify, preempt, resume and
 *  terminate an user code sequence.
 *
 *  The following information is managed by a thread:
 *  - Hardware Context (see \ref Os_Hal_Context)
 *  - Stack (see \ref Os_Stack)
 *  - Service Protection Access Rights (see \ref Os_Application)
 *  - Memory Protection Access Rights (see \ref Os_MemoryProtection)
 *  - Timing Protection Budgets (see \ref Os_TimingProtection)
 *  - Resources (see \ref Os_Resource)
 *  - Spinlocks (see \ref Os_Spinlock)
 *  - Service Function Calls (see \ref Os_ServiceFunction)
 *
 *  OSEK/AUTOSAR OS concepts of executing user code (i.e. Tasks and ISRs) are executed in a thread.
 *
 *  ![Thread Concept](Thread_Concept.png)
 *
 *  ![Thread Switching](Thread_Switch.png)
 *
 *  ![Thread Killing](Thread_Kill.png)
 *
 *  \see \ref Inheritance
 *  \see \ref Os_Task
 *  \see \ref Os_Isr
 *  \see \ref Os_Hook
 *  \see \ref Os_ServiceFunction
 *
 *
 *  \{
 *
 *  \file
 *  \brief      Internal functions to work with threads.
 * \details     --no details--
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_THREADINT_H
# define OS_THREADINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Thread_Types.h"

/* Os module dependencies */
# include "Os_CommonInt.h"
# include "Os_StackInt.h"
# include "Os_InterruptInt.h"
# include "Os_CoreInt.h"
# include "Os_MemoryProtectionInt.h"
# include "Os_TimingProtection_Types.h"
# include "Os_Application_Types.h"
# include "Os_ErrorInt.h"
# include "Os_Spinlock_Types.h"
# include "Os_ResourceInt.h"
# include "Os_Lock_Types.h"
# include "Os_XSignal_Cfg.h"
# include "Os_XSignal_Types.h"
# include "Os_AccessCheck_Types.h"
# include "Os_TraceInt.h"

/* Os Hal dependencies */
# include "Os_Hal_CompilerInt.h"
# include "Os_Hal_ContextInt.h"


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/*! Dynamic management information of the thread class. */
struct Os_ThreadClassType_Tag
{
  /*! The initial FPU context of a thread. */
  Os_Hal_ContextFpuContextType InitialFpuContext;
};


/*! Dynamic management information of a thread. */
struct Os_ThreadType_Tag
{
  /*! List of occupied locks. */
  Os_LockListType Locks;

  /*! List of occupied spinlocks. */
  Os_SpinlockListType Spinlocks;

  /*! The current application of this thread. */
  P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) Application;

  /*! Current memory protection settings. */
  P2CONST(Os_MpAccessRightsType, TYPEDEF, OS_CONST) MpAccessRights;

  /*! List of current service calls. */
  P2VAR(Os_ServiceCallType, TYPEDEF, OS_VAR_NOINIT) ServiceCalls;

  /*! Current call context. */
  Os_CallContextType CallContext;
};


/*! Configuration information of a thread.
 * \trace SPEC-63853, SPEC-63511 */
struct Os_ThreadConfigType_Tag
{
  /*! Information needed to initialize the thread's context.
   *  \trace SPEC-64065, SPEC-63973, SPEC-64007 */
  P2CONST(Os_Hal_ContextConfigType, TYPEDEF, OS_CONST) ContextConfig;

  /*! This structure holds the hardware context of the thread if it is suspended */
  P2VAR(Os_Hal_ContextType, TYPEDEF, OS_VAR_NOINIT) Context;

  /*! Associated stack. */
  P2CONST(Os_StackConfigType, TYPEDEF, OS_CONST) Stack;

  /*! The dynamic data of this thread. */
  P2VAR(Os_ThreadType, TYPEDEF, OS_VAR_NOINIT) Dyn;

  /*! The application to which this thread belongs. */
  P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) OwnerApplication;

  /*! The core to which this thread belongs. */
  P2CONST(Os_CoreAsrConfigType, TYPEDEF, OS_CONST) Core;

  /*! Current state of the interrupt API.
   *  Internal comment removed.
 *
 * */
  P2VAR(Os_IntApiStateType, TYPEDEF, OS_VAR_NOINIT) IntApiState;

  /*! Configured timing protection settings for this thread. */
  P2CONST(Os_TpThreadConfigType, TYPEDEF, OS_CONST) TimeProtConfig;

  /*! Configured memory protection settings for this thread. */
  P2CONST(Os_MpAccessRightsType, TYPEDEF, OS_CONST) MpAccessRightsInitial;

  /*! Pointer to an array of configured memory access rights. */
  P2CONST(Os_AccessCheckConfigType, TYPEDEF, OS_CONST) AccessRights;

  /*! Pointer to the configured trace data. */
  P2CONST(Os_TraceThreadConfigType, TYPEDEF, OS_CONST) Trace;

  /*! This structure holds the floating point unit context of the thread if it is supported,
   *  may be NULL if FPU context is not needed. */
  P2VAR(Os_Hal_ContextFpuContextType, TYPEDEF, OS_VAR_NOINIT) FpuContext;

  /*! Initial call context. */
  Os_CallContextType InitialCallContext;

  /*! Hook to be called before Thread is started/resumed. May be NULL_PTR. */
  Os_PreThreadHookCbkType PreThreadHook;

  /*! Tells whether the thread is initialized during system startup or during runtime
   *  when starting the thread. Value is defined by concrete thread class. */
  boolean InitDuringStartUp;

  /*! Tells whether the thread uses the floating point unit. */
  boolean UsesFpu;
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
 *  Os_ThreadGetLocks()
 **********************************************************************************************************************/
/*! \brief        Returns the list of locks, which are currently occupied by the given thread.
 *  \details      -
 *
 *  \param[in]    Thread  Thread to query. Parameter must not be NULL.
 *
 *  \return       Linked list of locks.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE P2VAR(Os_LockListType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE,
OS_ALWAYS_INLINE, Os_ThreadGetLocks,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadGetSpinlocks()
 **********************************************************************************************************************/
/*! \brief        Returns the list of spinlocks, which are currently occupied by the given thread.
 *  \details      -
 *
 *  \param[in]    Thread  Thread to query. Parameter must not be NULL.
 *
 *  \return       Linked list of spinlocks.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE P2VAR(Os_SpinlockListType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE,
OS_ALWAYS_INLINE, Os_ThreadGetSpinlocks,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadGetServiceCalls()
 **********************************************************************************************************************/
/*! \brief        Returns a list of service calls, which are currently active by the given thread.
 *  \details      --no details--
 *
 *  \param[in]    Thread  Thread to query. Parameter must not be NULL.
 *
 *  \return       Linked list of services.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE P2VAR(Os_ServiceCallType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE,
OS_ALWAYS_INLINE, Os_ThreadGetServiceCalls,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadSetServiceCalls()
 **********************************************************************************************************************/
/*! \brief        Set the start of the list of service calls, which are currently active by the given thread.
 *  \details      --no details--
 *
 *  \param[in,out]  Thread        Thread to query. Parameter must not be NULL.
 *  \param[in]      ServiceCalls  Linked list of service calls. Parameter must not be NULL.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_ThreadSetServiceCalls,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread,
  P2VAR(Os_ServiceCallType, AUTOMATIC, OS_VAR_NOINIT) ServiceCalls
));


/***********************************************************************************************************************
 *  Os_ThreadGetTrace()
 **********************************************************************************************************************/
/*! \brief        Returns the trace configuration of the given thread.
 *  \details      --no details--
 *
 *  \param[in]    Thread  Thread to query. Parameter must not be NULL.
 *
 *  \return       The tracing configuration of the given thread. The pointer is always valid, if tracing is enabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_ThreadGetTrace,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadGetTpConfig()
 **********************************************************************************************************************/
/*! \brief        Returns the timing protection configuration of the given thread.
 *  \details      --no details--
 *
 *  \param[in]    Thread  Thread to query. Parameter must not be NULL.
 *
 *  \return       Timing protection configuration of the given thread. The pointer is always valid, if timing protection
 *                is enabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_ThreadGetTpConfig,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadGetStack()
 **********************************************************************************************************************/
/*! \brief        Returns the stack configuration of the given thread.
 *  \details      --no details--
 *
 *  \param[in]    Thread  Thread to query. Parameter must not be NULL.
 *
 *  \return       Stack configuration of the given thread.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_StackConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_ThreadGetStack,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadGetContext()
 **********************************************************************************************************************/
/*! \brief        Returns the context configuration of the given thread.
 *  \details      --no details--
 *
 *  \param[in]    Thread  Thread to query. Parameter must not be NULL.
 *
 *  \return       Context configuration of the given thread.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_Hal_ContextConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_ThreadGetContext,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadGetInterruptApiState()
 **********************************************************************************************************************/
/*! \brief        Returns the interrupt API state associated with the given thread.
 *  \details      --no details--
 *
 *  \param[in]    Thread  Thread to query. Parameter must not be NULL.
 *
 *  \return       Interrupt API state associated with the given thread.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2VAR(Os_IntApiStateType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE,
OS_ALWAYS_INLINE, Os_ThreadGetInterruptApiState,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadGetCore()
 **********************************************************************************************************************/
/*! \brief        Returns the core to which a thread belongs.
 *  \details      --no details--
 *
 *  \param[in]    Thread  Thread to query. Parameter must not be NULL.
 *
 *  \return       The core of the given thread.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 *
 *  \trace        SPEC-64020, SPEC-63810, SPEC-63899
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_ThreadGetCore,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadGetCurrentType()
 **********************************************************************************************************************/
/*! \brief        Returns the current call context type of the given thread.
 *  \details      --no details--
 *
 *  \param[in]    Thread  Thread to query. Parameter must not be NULL.
 *
 *  \return       The call context type of the given thread.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_CallContextType, OS_CODE, OS_ALWAYS_INLINE, Os_ThreadGetCurrentType,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadGetInitialType()
 **********************************************************************************************************************/
/*! \brief        Returns the initial call context type of the given thread.
 *  \details      --no details--
 *
 *  \param[in]    Thread  Thread to query. Parameter must not be NULL.
 *
 *  \return       The call context type of the given thread.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_CallContextType, OS_CODE, OS_ALWAYS_INLINE, Os_ThreadGetInitialType,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadSwitchType()
 **********************************************************************************************************************/
/*! \brief        Switches the current call context type of the given thread to the given one.
 *  \details      --no details--
 *
 *  \param[in,out]  Thread           Thread to modify. Parameter must not be NULL.
 *  \param[in]      NextCallContext  Next call context.
 *
 *  \return       Previous call context type.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_CallContextType, OS_CODE, OS_ALWAYS_INLINE, Os_ThreadSwitchType,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread,
  Os_CallContextType NextCallContext
));


/***********************************************************************************************************************
 *  Os_ThreadIsTask()
 **********************************************************************************************************************/
/*! \brief        Returns whether the given thread is a task (!0) or not (0).
 *  \details      --no details--
 *
 *  \param[in]    Thread  Thread to query. Parameter must not be NULL.
 *
 *  \retval       !0  Given thread is a task.
 *  \retval       0   Otherwise.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_ThreadIsTask,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadIsTpIsr()
 **********************************************************************************************************************/
/*! \brief        Returns whether the given thread is a Timing Protection ISR (!0) or not (0).
 *  \details      --no details--
 *
 *  \param[in]    Thread  Thread to query. Parameter must not be NULL.
 *
 *  \retval       !0  Given thread is a Timing Protection Isr.
 *  \retval       0   Otherwise.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_ThreadIsTpIsr,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadIsIsr()
 **********************************************************************************************************************/
/*! \brief        Returns whether the given thread is an Isr (!0) or not (0).
 *  \details      --no details--
 *
 *  \param[in]    Thread  Thread to query. Parameter must not be NULL.
 *
 *  \retval       !0  Given thread is an Isr.
 *  \retval       0   Otherwise.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_ThreadIsIsr,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadIsAnyInitialContext()
 **********************************************************************************************************************/
/*! \brief        Returns whether the initial thread is any of the passed contexts (!0) or not (0).
 *  \details      --no details--
 *
 *  \param[in]    Thread  Thread to query. Parameter must not be NULL.
 *  \param[in]    Context The context mask.
 *
 *  \retval       !0  Given thread is of any of the given contexts.
 *  \retval       0   Otherwise.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_ThreadIsAnyInitialContext,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread,
  Os_CallContextType Context
));


/***********************************************************************************************************************
 *  Os_ThreadIsShutdownHook()
 **********************************************************************************************************************/
/*! \brief        Returns whether the given thread is a shutdown hook (!0) or not (0).
 *  \details      --no details--
 *
 *  \param[in]    Thread  Thread to query. Parameter must not be NULL.
 *
 *  \retval       !0  Given thread is a shutdown hook.
 *  \retval       0   Otherwise.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_ThreadIsShutdownHook,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadIsHook()
 **********************************************************************************************************************/
/*! \brief        Returns whether the given thread is a hook (!0) or not (0).
 *  \details      --no details--
 *
 *  \param[in]    Thread  Thread to query. Parameter must not be NULL.
 *
 *  \retval       !0  Given thread is a hook.
 *  \retval       0   Otherwise.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_ThreadIsHook,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadCheckCallContext()
 **********************************************************************************************************************/
/*! \brief        Returns whether the given thread is one of the permitted call context (Not OS_CHECK_FAILED)
 *                or not (OS_CHECK_FAILED).
 *  \details      In case that extended checks are disabled, the default result of \ref Os_ErrExtendedCheck() is
 *                returned.
 *
 *  \param[in]    Thread                The thread to check. Parameter must not be NULL.
 *  \param[in]    PermittedCallContext  The permitted call context.
 *
 *  \retval       Not OS_CHECK_FAILED   No call context violation.
 *  \retval       OS_CHECK_FAILED       Call context violation.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_ThreadCheckCallContext,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread,
  Os_CallContextType PermittedCallContext
));


/***********************************************************************************************************************
 *  Os_ThreadCheckIsCurrentApplication()
 **********************************************************************************************************************/
/*! \brief        Returns whether the given application is the current application of the thread (Not OS_CHECK_FAILED)
 *                or not (OS_CHECK_FAILED).
 *  \details      In case that service protection checks are disabled, the default result of
 *                \ref Os_ErrServiceProtectionCheck() is returned.
 *
 *  \param[in]    Thread                The thread to check. Parameter must not be NULL.
 *  \param[in]    App                   The application to check. Parameter must not be NULL.
 *
 *  \retval       Not OS_CHECK_FAILED   Given application is the current application of the given thread.
 *  \retval       OS_CHECK_FAILED       Given application is the not the current application of the given thread.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_ThreadCheckIsCurrentApplication,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread,
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App
));


/***********************************************************************************************************************
 *  Os_ThreadGetOwnerApplication()
 **********************************************************************************************************************/
/*! \brief        Returns the owner application of the given thread.
 *  \details      --no details--
 *
 *  \param[in]    Thread  Thread to query. Parameter must not be NULL.
 *
 *  \return       Owner application of the given thread.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST), OS_CODE, OS_ALWAYS_INLINE,
Os_ThreadGetOwnerApplication,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadGetCurrentApplication()
 **********************************************************************************************************************/
/*! \brief        Returns the current application of the given thread.
 *  \details      --no details--
 *
 *  \param[in]    Thread  Thread to query. Parameter must not be NULL.
 *
 *  \return       Current application of the given thread.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          The current application is set to a valid value.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST), OS_CODE, OS_ALWAYS_INLINE,
Os_ThreadGetCurrentApplication,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadSetCurrentApplication()
 **********************************************************************************************************************/
/*! \brief        Set the current application of the given thread.
 *  \details      --no details--
 *
 *  \param[in]    Thread  Thread to query. Parameter must not be NULL.
 *  \param[in]    App     Application which shall be the new current application. Parameter must not be NULL.
 *
 *  \return       Current application of the given thread.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_ThreadSetCurrentApplication,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread,
  P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) App
));


/***********************************************************************************************************************
 *  Os_ThreadHasResourcesLocked()
 **********************************************************************************************************************/
/*! \brief        Returns whether the given thread occupies any resources.
 *  \details      As the function contains a loop over potentially all list elements, it shall only be used in
 *                situations where the list is expected to be empty.
 *
 *  \param[in]    Thread      The thread to be queried. Parameter must not be NULL.
 *
 *  \retval       !0     The thread does not occupy a resource.
 *  \retval       0      The thread occupies at least one resource.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_ThreadHasResourcesLocked,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadHasSpinlockLocked()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given thread occupies any spinlocks.
 *  \details        As the function contains a loop over potentially all list elements, it shall only be used in
 *                  situations where the list is expected to be empty.
 *
 *  \param[in]      Thread      The thread to be queried. Parameter must not be NULL.
 *
 *  \retval         !0     The thread does not occupy a spinlock.
 *  \retval         0      The thread occupies at least one spinlock.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_ThreadHasSpinlockLocked,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadCheckResourcesReleased()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given thread occupies any locks.
 *  \details        In case that extended checks are disabled, the default result of \ref Os_ErrExtendedCheck() is
 *                  returned.
 *
 *  \param[in]      Thread      The thread to be queried. Parameter must not be NULL.
 *
 *  \retval         OS_CHECK_FAILED         The thread occupies a resource.
 *  \retval         Not OS_CHECK_FAILED     The thread does not occupy a resource.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_ThreadCheckResourcesReleased,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadCheckSpinlocksReleased()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given thread occupies any spinlocks.
 *  \details        In case that extended checks are disabled, the default result of \ref Os_ErrExtendedCheck() is
 *                  returned.
 *
 *  \param[in]      Thread      The thread to be queried. Parameter must not be NULL.
 *
 *  \retval         OS_CHECK_FAILED         The thread occupies a spinlock.
 *  \retval         Not OS_CHECK_FAILED     The thread does not occupy a spinlock.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_ThreadCheckSpinlocksReleased,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadCheckAreInterruptsEnabled()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given thread has a valid interrupt state.
 *  \details        --no details--
 *
 *  \param[in]      Thread      The thread to be queried. Parameter must not be NULL.
 *
 *  \retval         OS_CHECK_FAILED       Interrupts are enabled.
 *  \retval         Not OS_CHECK_FAILED   Interrupts are disabled.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_ThreadCheckAreInterruptsEnabled,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadSpinlockForceRelease()
 **********************************************************************************************************************/
/*! \brief          Releases all spinlocks occupied by the given thread.
 *  \details        See brief description.
 *
 *  \param[in,out]  Thread  The thread whose locks shall be released. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            The given task is assigned to the local core.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_ThreadSpinlockForceRelease,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadResourceForceRelease()
 **********************************************************************************************************************/
/*! \brief          Releases all resources occupied by the given thread.
 *  \details        See brief description.
 *
 *  \param[in,out]  Thread  The thread whose locks shall be released. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            The given task is assigned to the local core.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_ThreadResourceForceRelease,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadLocksForceRelease()
 **********************************************************************************************************************/
/*! \brief          Releases all locks occupied by the given thread.
 *  \details        See brief description.
 *
 *  \param[in,out]  Thread  The thread whose locks shall be released. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            The given task is assigned to the local core.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_ThreadLocksForceRelease,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadInit()
 **********************************************************************************************************************/
/*! \brief          Initialize the given thread and all its children.
 *  \details        The kernel uses this function to initialize all threads during OS initialization. The function
 *                  is called for some threads in Init-Step3 and for all threads in Init-Step4.
 *
 *  \param[in,out]  Thread  The thread which shall be initialized. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ThreadInit,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadClassInit()
 **********************************************************************************************************************/
/*! \brief        Initialize thread class data which is shared between all threads assigned to the local core.
 *  \details      Reads the initial FPU context from the hardware.
 *
 *  \param[out]   InitialFpuContext  The storage address of the context. Parameter must not be NULL.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ThreadClassInit,
(
  P2VAR(Os_ThreadClassType, AUTOMATIC, OS_VAR_NOINIT) ThreadClass
));


/***********************************************************************************************************************
 *  Os_ThreadInit2()
 **********************************************************************************************************************/
/*! \brief          Basic initialization of the given thread (Init-Step2).
 *  \details        Initialize only the absolute minimum, necessary to enter Startup-Phase2.
 *
 *  \param[in,out]  Thread  The thread which shall be initialized. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ThreadInit2,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadResetAndResume()
 **********************************************************************************************************************/
/*! \brief          Reset the current thread for next run and resume the next thread.
 *  \details        Initialization of the current thread has to be done by the caller, if needed.
 *                  The kernel uses this function to switch to the next task, if the current task is terminated.
 *
 *  \param[in,out]  Next              The thread which shall be resumed. Parameter must not be NULL.
 *  \param[in]      CallPreThreadHook Tells whether the PreThreadHook should be called (TRUE) or not (FALSE).
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Current thread is a task.
 *
 *  Internal comment removed.
 *
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_NORETURN OS_ALWAYS_INLINE,
Os_ThreadResetAndResume,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Next,
  boolean CallPreThreadHook
));


/***********************************************************************************************************************
 *  Os_ThreadStartFirst()
 **********************************************************************************************************************/
/*! \brief          Start the first thread.
 *  \details        Initialization of the current thread has to be done by the caller, if needed.
 *
 *  \param[in,out]  Next              The thread which shall be resumed. Parameter must not be NULL.
 *  \param[in]      CallPreThreadHook Tells whether the PreThreadHook should be called (TRUE) or not (FALSE).
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *
 *  Internal comment removed.
 *
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ThreadStartFirst,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Next,
  boolean CallPreThreadHook
));


/***********************************************************************************************************************
 *  Os_ThreadCleanupAndResume()
 **********************************************************************************************************************/
/*! \brief          Cleanup the current thread and resume the next one.
 *  \details        --no details--
 *
 *  \param[in,out]  Next              The thread which shall be resumed. Parameter must not be NULL.
 *  \param[in]      CallPreThreadHook Tells whether the PreThreadHook should be called (TRUE) or not (FALSE).
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            The current thread is no task thread.
 *
 *  Internal comment removed.
 *
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_NORETURN OS_ALWAYS_INLINE,
Os_ThreadCleanupAndResume,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Next,
  boolean CallPreThreadHook
));


/***********************************************************************************************************************
 *  Os_ThreadKill()
 **********************************************************************************************************************/
/*! \brief          Kill the given thread.
 *  \details        If the given thread is not the current thread, the context of the given thread is aborted.
 *                  If the given thread is the current thread, its context is not modified instead it has to be modified
 *                  after all killing activities (e.g. by TerminateApplication()) is completed using Os_ThreadSuicide().
 *
 *  \param[in,out]  Thread  Thread to kill. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *
 *  \trace          SPEC-63756, SPEC-64025
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ThreadKill,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadSuicide()
 **********************************************************************************************************************/
/*! \brief          Perform context cleanup and resume next thread during killing.
 *  \details        Depending on the thread type, killing has to be performed differently.
 *                  This function does not return.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access is prevented by caller.
 *  \pre            If the current thread is a task, the task is not scheduled.
 *  \pre            If the current thread is an ISR, \ref Os_IsrKill() was called before.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(void, OS_CODE, OS_NORETURN, Os_ThreadSuicide, (void));


/***********************************************************************************************************************
 *  Os_ThreadSwitch()
 **********************************************************************************************************************/
/*! \brief          Perform a thread switch.
 *  \details        --no details--
 *
 *  \param[in,out]  Current           The thread which shall be suspended. Parameter must not be NULL.
 *  \param[in,out]  Next              The thread which shall be resumed. Parameter must not be NULL.
 *  \param[in]      CallPreThreadHook Tells whether the PreThreadHook should be called (TRUE) or not (FALSE).
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ThreadSwitch,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Current,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Next,
  boolean CallPreThreadHook
));


/***********************************************************************************************************************
 *  Os_ThreadSuspendAndStart()
 **********************************************************************************************************************/
/*! \brief          Suspend the current thread, initialize and start given thread with first parameter = pointer
 *                  to thread.
 *  \details        --no details--
 *
 *  \param[in,out]  Current           The thread which shall be suspended. Parameter must not be NULL.
 *  \param[in,out]  Next              The thread which shall be resumed. Parameter must not be NULL.
 *  \param[in]      CallPreThreadHook Tells whether the PreThreadHook should be called (TRUE) or not (FALSE).
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *
 *  \trace          SPEC-63778
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ThreadSuspendAndStart,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Current,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Next,
  boolean CallPreThreadHook
));


/***********************************************************************************************************************
 *  Os_ThreadGetAccessRights()
 **********************************************************************************************************************/
/*! \brief          Returns the access right configuration of the given thread.
 *  \details        --no details--
 *
 *  \param[in]      Thread    The thread to query. Parameter must not be NULL.
 *
 *  \return         The access rights of the given thread.
 *  \retval         NULL_PTR  If the thread has no access rights configured.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_AccessCheckConfigType, AUTOMATIC, OS_CONST),
OS_CODE, OS_ALWAYS_INLINE, Os_ThreadGetAccessRights,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadGetMpAccessRights()
 **********************************************************************************************************************/
/*! \brief          Returns the current memory protection access rights of the given thread.
 *  \details        --no details--
 *
 *  \param[in]      Thread    The thread to query.  Parameter must not be NULL.
 *
 *  \return         The current access rights of the thread. If MemoryProtection is disabled, the return value is
 *                  undefined.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE P2CONST(Os_MpAccessRightsType, AUTOMATIC, OS_CONST),
OS_CODE, OS_ALWAYS_INLINE, Os_ThreadGetMpAccessRights,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadSetMpAccessRights()
 **********************************************************************************************************************/
/*! \brief          Set the current memory protection access right configuration of the given thread.
 *  \details        --no details--
 *
 *  \param[in,out]  Thread        The thread to modify. Parameter must not be NULL.
 *  \param[in]      AccessRights  The new access right.
 *                                Parameter must not be NULL if Memory proteciton is enabled.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE void,
OS_CODE, OS_ALWAYS_INLINE, Os_ThreadSetMpAccessRights,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread,
  P2CONST(Os_MpAccessRightsType, AUTOMATIC, OS_CONST) AccessRights
));


/***********************************************************************************************************************
 *  Os_ThreadSetInterruptState()
 **********************************************************************************************************************/
/*! \brief          Set the current interrupt state of the given thread.
 *  \details        --no details--
 *
 *  \param[in,out]  Thread         The thread to modify. Parameter must not be NULL.
 *  \param[in]      InterruptState The interrupt state to set. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE void,
OS_CODE, OS_ALWAYS_INLINE, Os_ThreadSetInterruptState,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread,
  P2CONST(Os_Hal_IntStateType, AUTOMATIC, OS_CONST) InterruptState
));

/***********************************************************************************************************************
 *  Os_ThreadCallPreThreadHook()
 **********************************************************************************************************************/
/*! \brief          Call the PreThreadHook if requested and configured.
 *  \details        --no details--
 *
 *  \param[in]      Thread            The owner thread. Parameter must not be NULL.
 *  \param[in]      CallPreThreadHook States if a PreThreadHook was requested.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ThreadCallPreThreadHook,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread,
  boolean CallPreThreadHook
));


/***********************************************************************************************************************
 *  Os_ThreadCallContextOnStack()
 **********************************************************************************************************************/
/*! \brief          Perform the kernel context initialization/saving/restoring part of a context call on stack.
 *  \details        --no details--
 *
 *  \param[in]      Thread             The caller thread. Parameter must not be NULL.
 *  \param[in]      HalContextCfg      Initial context values. Parameter must not be NULL.
 *  \param[in]      HalStackCfg        Stack which shall be used. Parameter must not be NULL.
 *  \param[in]      Parameter          Parameter used as the first argument of the call. Parameter must not be NULL.
 *  \param[in]      InterruptState     Interrupt state which shall be used. Parameter must not be NULL.
 *  \param[in]      CallerContext      Pointer where to save the current context. Parameter must not be NULL.
 *  \param[out]     CalleeContext      Pointer where this function stores a reference to the callee's context.
 *                                     This pointer is invalid when function returns. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ThreadCallContextOnStack,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread,
  P2CONST(Os_Hal_ContextConfigType, AUTOMATIC, OS_CONST) HalContextCfg,
  P2CONST(Os_Hal_ContextStackConfigType, AUTOMATIC, OS_CONST) HalStackCfg,
  P2CONST(void, AUTOMATIC, OS_VAR_NOINIT) Parameter,
  P2CONST(Os_Hal_IntStateType, AUTOMATIC, OS_VAR_NOINIT) InterruptState,
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) CallerContext,
  P2VAR(Os_ThreadContextRefType, AUTOMATIC, OS_VAR_NOINIT) CalleeContext
));


/***********************************************************************************************************************
 *  Os_ThreadCallContext()
 **********************************************************************************************************************/
/*! \brief          Perform the kernel context initialization/saving/restoring part of a context call on stack.
 *  \details        --no details--
 *
 *  \param[in]      Thread             The caller thread. Parameter must not be NULL.
 *  \param[in]      HalContextCfg      Initial context values. Parameter must not be NULL.
 *  \param[in]      Parameter          Parameter used as the first argument of the call. Parameter must not be NULL.
 *  \param[in]      InterruptState     Interrupt state which shall be used. Parameter must not be NULL.
 *  \param[in]      CallerContext      Pointer where to save the current context. Parameter must not be NULL.
 *  \param[out]     CalleeContext      Pointer where this function stores a reference to the callee's context.
 *                                     This pointer is invalid when function returns. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ThreadCallContext,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread,
  P2CONST(Os_Hal_ContextConfigType, AUTOMATIC, OS_CONST) HalContextCfg,
  P2CONST(void, AUTOMATIC, OS_VAR_NOINIT) Parameter,
  P2CONST(Os_Hal_IntStateType, AUTOMATIC, OS_VAR_NOINIT) InterruptState,
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) CallerContext,
  P2VAR(Os_ThreadContextRefType, AUTOMATIC, OS_VAR_NOINIT) CalleeContext
));


/***********************************************************************************************************************
 *  Os_ThreadInitFpuContext()
 **********************************************************************************************************************/
/*! \brief          Initialize the FPU context if needed.
 *  \details        --no details--
 *
 *  \param[in]      Thread            The owner thread. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE void,
OS_CODE, OS_ALWAYS_INLINE, Os_ThreadInitFpuContext,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadInitFpu()
 **********************************************************************************************************************/
/*! \brief          Initialize the FPU if needed.
 *  \details        This function restores the configuration of the FPU. Intermediate registers are not modified.
 *
 *  \param[in]      Thread            The owner thread. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ThreadInitFpu,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadStoreFpuContext()
 **********************************************************************************************************************/
/*! \brief          Store the FPU context if needed.
 *  \details        --no details--
 *
 *  \param[in]      Thread            The owner thread. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ThreadStoreFpuContext,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadRestoreFpuContext()
 **********************************************************************************************************************/
/*! \brief          Restore the FPU context if needed.
 *  \details        --no details--
 *
 *  \param[in]      Thread            The owner thread. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ThreadRestoreFpuContext,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadIsFpuContextEnabledForThread()
 **********************************************************************************************************************/
/*! \brief        Returns whether the given thread needs saving /restoring of FPU context (!0) or not (0).
 *  \details      --no details--
 *
 *  \param[in]    Thread  Thread to query. Parameter must not be NULL.
 *
 *  \retval       !0  Given thread needs saving /restoring of the FPU context.
 *  \retval       0   Otherwise.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_ThreadIsFpuContextEnabledForThread,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_ThreadAllThreadsUseFpu()
 **********************************************************************************************************************/
/*! \brief        Returns whether all threads use the FPU (!0) or not (0).
 *  \details      --no details--
 *
 *  \retval       !0  All threads use the FPU.
 *  \retval       0   Otherwise.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_ThreadAllThreadsUseFpu,
(
  void
));


/***********************************************************************************************************************
 *  Os_ThreadIsFpuContextEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether no thread uses the FPU (!0) or not (0).
 *  \details      --no details--
 *
 *  \retval       !0  No thread uses the FPU.
 *  \retval       0   Otherwise.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_ThreadIsFpuContextEnabled,
(
  void
));


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_THREAD_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Thread.h
 **********************************************************************************************************************/
