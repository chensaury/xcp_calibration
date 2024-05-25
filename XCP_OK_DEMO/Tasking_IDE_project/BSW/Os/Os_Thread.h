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
 * \addtogroup Os_Thread
 *
 * \{
 *
 * \file
 * \brief      Internal functions implementation to work with threads.
 * \details     --no details--
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/


#ifndef OS_THREAD_H
# define OS_THREAD_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_ThreadInt.h"
# include "Os_Thread_Types.h"

/* Os module dependencies */
# include "Os_Common.h"
# include "Os_Stack.h"
# include "Os_Interrupt.h"
# include "Os_Core.h"
# include "Os_MemoryProtection.h"
# include "Os_TimingProtection.h"
# include "Os_Application.h"
# include "Os_Error.h"
# include "Os_Resource.h"
# include "Os_ServiceFunction.h"
# include "Os_XSignal_Cfg.h"
# include "Os_Trace.h"
# include "Os_Spinlock.h"
# include "Os_Lock.h"
# include "Os_XSignal.h"
# include "Os_AccessCheck.h"

/* Os Hal dependencies */
# include "Os_Hal_Compiler.h"
# include "Os_Hal_Context.h"


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
 *  Os_ThreadGetLocks()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE P2VAR(Os_LockListType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE,
OS_ALWAYS_INLINE, Os_ThreadGetLocks,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  return &(Thread->Dyn->Locks);
}


/***********************************************************************************************************************
 *  Os_ThreadGetSpinlocks()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE P2VAR(Os_SpinlockListType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE, OS_ALWAYS_INLINE,
Os_ThreadGetSpinlocks,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  return &(Thread->Dyn->Spinlocks);
}


/***********************************************************************************************************************
 *  Os_ThreadGetServiceCalls()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE P2VAR(Os_ServiceCallType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE,
OS_ALWAYS_INLINE, Os_ThreadGetServiceCalls,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  return Thread->Dyn->ServiceCalls;
}


/***********************************************************************************************************************
 *  Os_ThreadSetServiceCalls()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_ThreadSetServiceCalls,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread,
  P2VAR(Os_ServiceCallType, AUTOMATIC, OS_VAR_NOINIT) ServiceCalls
))
{
  Thread->Dyn->ServiceCalls = ServiceCalls;                                                                             /* SBSW_OS_TRD_THREADGETDYN_001 */
}


/***********************************************************************************************************************
 *  Os_ThreadGetTrace()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_ThreadGetTrace,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  return Thread->Trace;
}


/***********************************************************************************************************************
 *  Os_ThreadGetTpConfig()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_ThreadGetTpConfig,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  return Thread->TimeProtConfig;
}


/***********************************************************************************************************************
 *  Os_ThreadGetStack()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE P2CONST(Os_StackConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_ThreadGetStack,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  return (Thread->Stack);
}


/***********************************************************************************************************************
 *  Os_ThreadGetContext()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE P2CONST(Os_Hal_ContextConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE,
Os_ThreadGetContext,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  return Thread->ContextConfig;
}


/***********************************************************************************************************************
 *  Os_ThreadGetIntApiState()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE P2VAR(Os_IntApiStateType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE, OS_ALWAYS_INLINE,
Os_ThreadGetInterruptApiState,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  return Thread->IntApiState;
}


/***********************************************************************************************************************
 *  Os_ThreadGetCore()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE,
Os_ThreadGetCore,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  return Thread->Core;
}


/***********************************************************************************************************************
 *  Os_ThreadGetCurrentType()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_CallContextType, OS_CODE,                                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_ThreadGetCurrentType,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  return Thread->Dyn->CallContext;
}


/***********************************************************************************************************************
 *  Os_ThreadGetInitialType()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_CallContextType, OS_CODE,                                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_ThreadGetInitialType,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  return Thread->InitialCallContext;
}


/***********************************************************************************************************************
 *  Os_ThreadSwitchType()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_CallContextType, OS_CODE,                                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_ThreadSwitchType,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread,
  Os_CallContextType NextCallContext
))
{
  Os_CallContextType prevCallContext;

  prevCallContext = Thread->Dyn->CallContext;
  Thread->Dyn->CallContext = NextCallContext;                                                                           /* SBSW_OS_TRD_THREADGETDYN_001 */

  return prevCallContext;
}


/***********************************************************************************************************************
 *  Os_ThreadIsTask()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_ThreadIsTask,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  return ((Thread->InitialCallContext == OS_CALLCONTEXT_TASK) ||                                                        /* PRQA S  4404 */ /* MD_Os_C90BooleanCompatibility */
          (Thread->InitialCallContext == OS_CALLCONTEXT_PRESTARTTASK));
}


/***********************************************************************************************************************
 *  Os_ThreadIsTpIsr()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_ThreadIsTpIsr,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  return (Thread->InitialCallContext == OS_CALLCONTEXT_TPISR);                                                          /* PRQA S  4404 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_ThreadIsIsr()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_ThreadIsIsr,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  return ((Os_StdReturnType)Thread->InitialCallContext & OS_CALLCONTEXT_ISR);
}


/***********************************************************************************************************************
 *  Os_ThreadIsAnyInitialContext()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_ThreadIsAnyInitialContext,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread,
  Os_CallContextType Context
))
{
  return ((Os_StdReturnType)Thread->InitialCallContext & (Os_StdReturnType)Context);
}


/***********************************************************************************************************************
 *  Os_ThreadIsShutdownHook()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_ThreadIsShutdownHook,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  return (Thread->InitialCallContext == OS_CALLCONTEXT_SHUTDOWNHOOK);                                                   /* PRQA S  4404 */ /*  MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_ThreadIsHook()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_ThreadIsHook,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  return ((Os_StdReturnType)Thread->InitialCallContext & OS_CALLCONTEXT_ANYHOOK);
}


/***********************************************************************************************************************
 *  Os_ThreadCheckCallContext()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_ThreadCheckCallContext,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread,
  Os_CallContextType PermittedCallContext
))
{
  return Os_ErrExtendedCheck((Os_StdReturnType)Os_ThreadGetCurrentType(Thread) & PermittedCallContext);                 /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_ThreadCheckIsCurrentApplication()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_ThreadCheckIsCurrentApplication,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread,
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App
))
{
  return Os_ErrServiceProtectionCheck((Os_StdReturnType)(Os_ThreadGetCurrentApplication(Thread) == App));               /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */ /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_ThreadGetOwnerApplication()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST), OS_CODE, OS_ALWAYS_INLINE,
Os_ThreadGetOwnerApplication,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  return Thread->OwnerApplication;
}


/***********************************************************************************************************************
 *  Os_ThreadGetCurrentApplication()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_ThreadGetCurrentApplication,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  return Thread->Dyn->Application;
}


/***********************************************************************************************************************
 *  Os_ThreadSetCurrentApplication()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_ThreadSetCurrentApplication,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread,
  P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) App
))
{
  Thread->Dyn->Application = App;                                                                                       /* SBSW_OS_TRD_THREADGETDYN_001 */
}


/***********************************************************************************************************************
 *  Os_ThreadHasResourcesLocked()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_ThreadHasResourcesLocked,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  Os_StdReturnType hasResources;
  Os_LockListType it;

  hasResources = 0;
  it = Thread->Dyn->Locks;

  /* #10 Search the complete lock list */
  while(OS_UNLIKELY(Os_LockListIsEmpty(&it) == 0u))                                                                     /* SBSW_OS_TRD_LOCKLISTISEMPTY_001 */
  {
    /* #20 If one resource is found, stop searching and return 1 (0 in any other case). */
    if(Os_LockListIsTopRes(&it) != 0u)                                                                                  /* SBSW_OS_TRD_LOCKLISTISTOPRES_001 */
    {
      hasResources = 1;
      break;
    }

    it = Os_LockListNext(it);                                                                                           /* SBSW_OS_TRD_LOCKLISTNEXT_001 */
  }

  return hasResources;
}


/***********************************************************************************************************************
 *  Os_ThreadHasSpinlockLocked()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_ThreadHasSpinlockLocked,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  Os_StdReturnType hasSpinlocks;
  Os_LockListType it;

  hasSpinlocks = 0;
  it = Thread->Dyn->Locks;


  /* #10 Search the complete lock list */
  while(OS_UNLIKELY(Os_LockListIsEmpty(&it) == 0u))                                                                     /* SBSW_OS_TRD_LOCKLISTISEMPTY_001 */ /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
  {
    /* #20 If one spinlock is found, stop searching and return 1 (0 in any other case). */
    if(Os_LockListIsTopSpinlock(&it) != 0u)                                                                             /* SBSW_OS_TRD_LOCKLISTISTOPSPINLOCK_001 */
    {
      hasSpinlocks = 1;
      break;
    }

    it = Os_LockListNext(it);                                                                                           /* SBSW_OS_TRD_LOCKLISTNEXT_001 */
  }

  return hasSpinlocks;
}


/***********************************************************************************************************************
 *  Os_ThreadCheckResourcesReleased()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_ThreadCheckResourcesReleased,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  return Os_ErrExtendedCheck(Os_ThreadHasResourcesLocked(Thread) == 0u);                                                /* PRQA S 4404 */ /* MD_Os_C90BooleanCompatibility */ /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_ThreadCheckSpinlocksReleased()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType,                                                          /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_CODE, OS_ALWAYS_INLINE, Os_ThreadCheckSpinlocksReleased,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  return Os_ErrExtendedCheck(Os_ThreadHasSpinlockLocked(Thread) == 0u);                                                 /* PRQA S 4404 */ /* MD_Os_C90BooleanCompatibility */ /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_ThreadCheckAreInterruptsEnabled()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_ThreadCheckAreInterruptsEnabled,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  return Os_InterruptCheckEnabled(Os_ThreadGetInterruptApiState(Thread));                                               /* SBSW_OS_TRD_INTERRUPTCHECKENABLED_001 */ /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_ThreadSpinlockForceRelease()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ThreadSpinlockForceRelease,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  Os_SpinlockForciblyReleaseThreadLocks(Thread);                                                                        /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_ThreadResourceForceRelease()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ThreadResourceForceRelease,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  Os_ResourceForciblyReleaseLocks(Thread);                                                                              /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_ThreadLocksForceRelease()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ThreadLocksForceRelease,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  /* #10 Clean up the interrupt state. */
  Os_InterruptCleanup(Thread->IntApiState);                                                                             /* SBSW_OS_TRD_INTERRUPTCLEANUP_001 */

  /* #20 Release all locks. */
  Os_ThreadResourceForceRelease(Thread);                                                                                /* SBSW_OS_FC_PRECONDITION */
  Os_ThreadSpinlockForceRelease(Thread);                                                                                /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_ThreadClassInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ThreadClassInit,
(
  P2VAR(Os_ThreadClassType, AUTOMATIC, OS_CONST) ThreadClass
))
{
  /* #10 Fetch initial FPU context from HAL if FPU context is enabled. */
  if(Os_ThreadIsFpuContextEnabled() != 0u)
  {
    Os_Hal_ContextFetchInitialFpuContext(&(ThreadClass->InitialFpuContext));                                            /* SBSW_OS_FC_PRECONDITION */
  }
}


/***********************************************************************************************************************
 *  Os_ThreadInit()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ThreadInit,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  /* #10 Initialize current application. */
  Thread->Dyn->Application = Thread->OwnerApplication;                                                                  /* SBSW_OS_TRD_THREADGETDYN_001 */

  /* #20 Initialize current context. */
  Thread->Dyn->CallContext = Thread->InitialCallContext;                                                                /* SBSW_OS_TRD_THREADGETDYN_001 */

  /* #30 Initialize service call list. */
  Os_ServiceCallsInit(&(Thread->Dyn->ServiceCalls));                                                                    /* SBSW_OS_TRD_SERVICECALLSINIT_001 */

  /* #40 Initialize the lock list. */
  Os_LockListInit(&(Thread->Dyn->Locks));                                                                               /* SBSW_OS_TRD_LOCKLISTINIT_001 */

  /* #50 Initialize spinlock order list. */
  Os_SpinlockListInit(Os_ThreadGetSpinlocks(Thread));                                                                   /* SBSW_OS_TRD_SPINLOCKLISTINIT_001 */ /* SBSW_OS_FC_PRECONDITION */

  /* #60 Initialize the timing protection. */
  {
    P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST) currentTp;
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) core;
    P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) coreTp;

    core = Os_ThreadGetCore(Thread);                                                                                    /* SBSW_OS_FC_PRECONDITION */
    coreTp = Os_CoreAsrGetTimingProtection(core);                                                                       /* SBSW_OS_TRD_COREASRGETTIMINGPROTECTION_001 */
    currentTp = Os_ThreadGetTpConfig(Thread);                                                                           /* SBSW_OS_FC_PRECONDITION */

    Os_TpThreadInit(coreTp, currentTp);                                                                                 /* SBSW_OS_TRD_TPTHREADINIT_001 */
  }

  /* #70 Initialize the memory protection. */
  Os_MpThreadInit(Thread->MpAccessRightsInitial, &(Thread->Dyn->MpAccessRights));                                       /* SBSW_OS_TRD_MPTHREADINIT_001 */


  /* #80 If the given thread shall be initialized during startup: */
  if(Thread->InitDuringStartUp != FALSE)
  {
    /* #90 Initialize its hardware context, so that it will start with a fresh stack and at function entry,
     *     if resumed. */
    Os_Hal_ContextInit(Thread->ContextConfig, Thread->Context);                                                         /* SBSW_OS_TRD_HAL_CONTEXTINIT_001 */

    /* #95 Initialize the FPU context of all threads which use FPU at startup. */
    Os_ThreadInitFpuContext(Thread);                                                                                    /* SBSW_OS_FC_PRECONDITION */
  }


  /* #100 Initialize the tracing data of this thread. */
  Os_TraceThreadInit(Thread->Trace);                                                                                    /* SBSW_OS_TRD_TRACETHREADINIT_001 */
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_ThreadInit2()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ThreadInit2,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  /* #10 Initialize current application. */
  Thread->Dyn->Application = Thread->OwnerApplication;                                                                  /* SBSW_OS_TRD_THREADGETDYN_001 */
}


/***********************************************************************************************************************
 *  Os_ThreadResetAndResume()
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_NORETURN OS_ALWAYS_INLINE,                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ThreadResetAndResume,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Next,
  boolean CallPreThreadHook
))
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) current;

  current = Os_CoreGetThread();

  /* Check that the function is called from a task. */
  Os_Assert((Os_StdReturnType)(Os_ThreadIsTask(current) != 0u));                                                        /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */ /* SBSW_OS_TRD_THREADISTASK_001 */

  /* #10 Release all services called by the thread. */
  Os_ServiceCallForceRelease(&(current->Dyn->ServiceCalls));                                                            /* SBSW_OS_TRD_SERVICECALLFORCERELEASE_001 */

  /* #20 Perform stack overflow check. */
  Os_StackOverflowCheck();

  /* #25 Initialize the FPU context of all threads which use FPU at startup. */
  Os_ThreadInitFpuContext(current);                                                                                     /* SBSW_OS_TRD_THREADINITFPUCONTEXT_001 */

  /* #30 Tell timing protection module to resume timing protection for Next. */
  {
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) core;
    P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) configTp;
    P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST) nextTp;
    P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST) currentTp;

    core = Os_ThreadGetCore(Next);                                                                                      /* SBSW_OS_FC_PRECONDITION */
    configTp = Os_CoreAsrGetTimingProtection(core);                                                                     /* SBSW_OS_TRD_COREASRGETTIMINGPROTECTION_001 */
    nextTp = Os_ThreadGetTpConfig(Next);                                                                                /* SBSW_OS_FC_PRECONDITION */
    currentTp = Os_ThreadGetTpConfig(current);                                                                          /* SBSW_OS_TRD_THREADGETTPCONFIG_001 */
    Os_TpResetAndResume(configTp, currentTp, nextTp, Next);                                                             /* SBSW_OS_TRD_TPRESETANDRESUME_001 */
  }

  /* #40 Resume memory protection access rights of Next. */
  Os_MpSwitch(current->Dyn->MpAccessRights, Next->Dyn->MpAccessRights);                                                 /* SBSW_OS_TRD_MPSWITCH_001 */

  /* #50 Call PreThreadHook. */
  Os_ThreadCallPreThreadHook(Next, CallPreThreadHook);                                                                  /* SBSW_OS_FC_PRECONDITION */

  /* #55 Restore FPU context of next thread if needed. */
  Os_ThreadRestoreFpuContext(Next);                                                                                     /* SBSW_OS_FC_PRECONDITION */

  /* #60 Set the current thread pointer. */
  Os_CoreSetThread(Next);                                                                                               /* SBSW_OS_FC_PRECONDITION */

  /* #70 Set the current stack pointer. */
  Os_CoreSetCurrentStack(Next->Stack, Next->Core);                                                                      /* SBSW_OS_TRD_CORESETCURRENTSTACK_001 */

  /* #80 Update the Msr of the next thread. */
  Os_Hal_ContextSetUserMsrBits(Next->Context);                                                                          /* SBSW_OS_TRD_HAL_CONTEXTSETUSERMSRBITS_001 */

  /* #90 Resume the hardware context of the next thread. */
  Os_Hal_ContextResetAndResume(current->ContextConfig, current->Context, Next->Context); /* function never returns! */  /* SBSW_OS_TRD_HAL_CONTEXTRESETANDRESUME_001 */

  /* Never reached */
  Os_ErrKernelPanic(); /* function never returns! */
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_ThreadStartFirst()
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ThreadStartFirst,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Next,
  boolean CallPreThreadHook
))
{
  P2CONST(Os_TpConfigType, TYPEDEF, OS_CONST) configTp;
  P2CONST(Os_TpThreadConfigType, TYPEDEF, OS_CONST) nextTp;
  P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST) currentTp;

  configTp = Os_CoreAsrGetTimingProtection(Os_ThreadGetCore(Next));                                                     /* SBSW_OS_TRD_COREASRGETTIMINGPROTECTION_001 */ /* SBSW_OS_FC_PRECONDITION */
  nextTp = Os_ThreadGetTpConfig(Next);                                                                                  /* SBSW_OS_FC_PRECONDITION */
  currentTp = Os_ThreadGetTpConfig(Os_CoreGetThread());                                                                 /* SBSW_OS_TRD_THREADGETTPCONFIG_001 */

  /* #10 Tell timing protection module to resume timing protection for Next. */
  Os_TpResetAndResume(configTp, currentTp, nextTp, Next);                                                               /* SBSW_OS_TRD_TPRESETANDRESUME_001 */

  /* #20 Set memory protection access rights of Next. */
  Os_MpSwitchTo(Next->Dyn->MpAccessRights);                                                                             /* SBSW_OS_TRD_MPSWITCHTO_001 */

  /* #30 Call PreThreadHook. */
  Os_ThreadCallPreThreadHook(Next, CallPreThreadHook);                                                                  /* SBSW_OS_FC_PRECONDITION */

  /* #40 Set the current thread pointer. */
  Os_CoreSetThread(Next);                                                                                               /* SBSW_OS_FC_PRECONDITION */

  /* #50 Set the current stack pointer. */
  Os_CoreSetCurrentStack(Next->Stack, Next->Core);                                                                      /* SBSW_OS_TRD_CORESETCURRENTSTACK_001 */

  /* #60 Update the Msr of the nest thread. */
  Os_Hal_ContextSetUserMsrBits(Next->Context);                                                                          /* SBSW_OS_TRD_HAL_CONTEXTSETUSERMSRBITS_001 */

  /* #70 Resume the hardware context of the first thread. */
  Os_Hal_ContextFirstResume(Next->Context); /* function never returns! */                                               /* SBSW_OS_TRD_HAL_CONTEXTFIRSTRESUME_001 */

  /* Never reached. */
  Os_ErrKernelPanic(); /* function never returns! */
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_ThreadCleanupAndResume()
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_NORETURN OS_ALWAYS_INLINE,                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ThreadCleanupAndResume,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Next,
  boolean CallPreThreadHook
))
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) current;

  current = Os_CoreGetThread();

  /* Check that the function is not called from a task. */
  Os_Assert((Os_StdReturnType)(Os_ThreadIsTask(current) == 0u));                                                        /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */ /* SBSW_OS_TRD_THREADISTASK_001 */

  /* #10 Release all services called by the thread. */
  Os_ServiceCallForceRelease(&(current->Dyn->ServiceCalls));                                                            /* SBSW_OS_TRD_SERVICECALLFORCERELEASE_001 */

  /* #20 Perform stack overflow check. */
  Os_StackOverflowCheck();

  /* #30 Tell timing protection module to resume timing protection for Next. */
  {
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) core;
    P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) configTp;
    P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST) nextTp;
    P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST) currentTp;

    core = Os_ThreadGetCore(Next);                                                                                      /* SBSW_OS_FC_PRECONDITION */
    configTp = Os_CoreAsrGetTimingProtection(core);                                                                     /* SBSW_OS_TRD_COREASRGETTIMINGPROTECTION_001 */
    nextTp = Os_ThreadGetTpConfig(Next);                                                                                /* SBSW_OS_FC_PRECONDITION */
    currentTp = Os_ThreadGetTpConfig(current);                                                                          /* SBSW_OS_TRD_THREADGETTPCONFIG_001 */
    Os_TpResetAndResume(configTp, currentTp, nextTp, Next);                                                             /* SBSW_OS_TRD_TPRESETANDRESUME_001 */
  }

  /* #40 Resume memory protection access rights of Next. */
  Os_MpSwitch(current->Dyn->MpAccessRights, Next->Dyn->MpAccessRights);                                                 /* SBSW_OS_TRD_MPSWITCH_001 */

  /* #50 Call PreThreadHook. */
  Os_ThreadCallPreThreadHook(Next, CallPreThreadHook);                                                                  /* SBSW_OS_FC_PRECONDITION */

  /* #55 Restore FPU context of next thread if needed. */
  Os_ThreadRestoreFpuContext(Next);                                                                                     /* SBSW_OS_FC_PRECONDITION */

  /* #60 Set the current thread pointer. */
  Os_CoreSetThread(Next);                                                                                               /* SBSW_OS_FC_PRECONDITION */

  /* #70 Set the current stack pointer. */
  Os_CoreSetCurrentStack(Next->Stack, Next->Core);                                                                      /* SBSW_OS_TRD_CORESETCURRENTSTACK_001 */

  /* #80 Update the Msr of the next thread. */
  Os_Hal_ContextSetUserMsrBits(Next->Context);                                                                          /* SBSW_OS_TRD_HAL_CONTEXTSETUSERMSRBITS_001 */

  /* #90 Cleanup the current hardware context and resume the hardware context of the next thread. */
  Os_Hal_ContextReturn(current->Context, Next->Context);                                                                /* SBSW_OS_TRD_HAL_CONTEXTRETURN_001 */

  /* Never reached */
  Os_ErrKernelPanic(); /* function never returns! */
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_ThreadKill()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ThreadKill,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  /* #10 Initialize current application. */
  Thread->Dyn->Application = Thread->OwnerApplication;                                                                  /* SBSW_OS_TRD_THREADGETDYN_001 */

  /* #20 Initialize current context. */
  Thread->Dyn->CallContext = Thread->InitialCallContext;                                                                /* SBSW_OS_TRD_THREADGETDYN_001 */

  /* #30 Release all services called by the thread. */
  Os_ServiceCallForceRelease(&(Thread->Dyn->ServiceCalls));                                                             /* SBSW_OS_TRD_SERVICECALLFORCERELEASE_001 */

  /* #40 Release all locks and resources, which are hold by the thread. */
  Os_ThreadLocksForceRelease(Thread);                                                                                   /* SBSW_OS_FC_PRECONDITION */

  /* #50 Reset timing protection. */
  {
    P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST) currentTp;

    currentTp = Os_ThreadGetTpConfig(Thread);                                                                           /* SBSW_OS_FC_PRECONDITION */

    Os_TpThreadKill(currentTp);                                                                                         /* SBSW_OS_TRD_TPTHREADKILL_001 */
  }

  /* #60 Initialize the memory protection. */
  Os_MpThreadInit(Thread->MpAccessRightsInitial, &(Thread->Dyn->MpAccessRights));                                       /* SBSW_OS_TRD_MPTHREADINIT_001 */


  /* #70 If the given thread is not the current thread: */
  {
    P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) current;

    current = Os_CoreGetThread();

    if(OS_LIKELY(Thread != current))
    {
      /* #80 If the given thread is a task: */
      if(Os_ThreadIsTask(Thread) != 0u)                                                                                 /* SBSW_OS_FC_PRECONDITION */
      {
        /* #90 Reset its hardware context. */
        Os_Hal_ContextReset(Thread->ContextConfig, Thread->Context);                                                    /* SBSW_OS_TRD_HAL_CONTEXTRESET_001 */
        Os_ThreadInitFpuContext(Thread);                                                                                /* SBSW_OS_FC_PRECONDITION */
      }
      /* #100 Otherwise: */
      else
      {
        Os_Hal_IntStateType currentIntState;

        /* #110 Abort the threads context. Execute the return function the next time it will be resumed. */
        Os_Hal_ContextAbort(Thread->ContextConfig, Thread->Context);                                                    /* SBSW_OS_TRD_HAL_CONTEXTABORT_001 */

        /* #120 Set the interrupt state for the context used after the abort. */
        Os_Hal_IntGetInterruptState(&currentIntState);                                                                  /* SBSW_OS_FC_POINTER2LOCAL */
        Os_Hal_ContextSetInterruptState(Thread->Context, &currentIntState);                                             /* SBSW_OS_TRD_HAL_CONTEXTSETINTERRUPTSTATE_001 */
      }
    }
  }
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_ThreadSwitch()
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ThreadSwitch,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Current,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Next,
  boolean CallPreThreadHook
))
{
  /* #10 Perform stack overflow check. */
  Os_StackOverflowCheck();

  /* #15 Store FPU context of current thread if needed. */
  Os_ThreadStoreFpuContext(Current);                                                                                    /* SBSW_OS_FC_PRECONDITION */

  /* #20 Tell timing protection module to switch. */
  {
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) core;
    P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) configTp;
    P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST) currentTp;
    P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST) nextTp;

    core = Os_ThreadGetCore(Next);                                                                                      /* SBSW_OS_FC_PRECONDITION */
    configTp = Os_CoreAsrGetTimingProtection(core);                                                                     /* SBSW_OS_TRD_COREASRGETTIMINGPROTECTION_001 */
    currentTp = Os_ThreadGetTpConfig(Current);                                                                          /* SBSW_OS_FC_PRECONDITION */
    nextTp = Os_ThreadGetTpConfig(Next);                                                                                /* SBSW_OS_FC_PRECONDITION */
    Os_TpSwitch(configTp, currentTp, nextTp, Next);                                                                     /* SBSW_OS_TRD_TPSWITCH_001 */
  }

  /* #30 Resume memory protection access rights of Next. */
  Os_MpSwitch(Current->Dyn->MpAccessRights, Next->Dyn->MpAccessRights);                                                 /* SBSW_OS_TRD_MPSWITCH_002 */

  /* #40 Call PreThreadHook. */
  Os_ThreadCallPreThreadHook(Next, CallPreThreadHook);                                                                  /* SBSW_OS_FC_PRECONDITION */

  /* #45 Restore FPU context of next thread if needed. */
  Os_ThreadRestoreFpuContext(Next);                                                                                     /* SBSW_OS_FC_PRECONDITION */

  /* #50 Switch current thread pointer. */
  Os_CoreSetThread(Next);                                                                                               /* SBSW_OS_FC_PRECONDITION */

  /* #60 Set the current stack pointer. */
  Os_CoreSetCurrentStack(Next->Stack, Next->Core);                                                                      /* SBSW_OS_TRD_CORESETCURRENTSTACK_001 */

  /* #70 Update the Msr of the next thread. */
  Os_Hal_ContextSetUserMsrBits(Next->Context);                                                                          /* SBSW_OS_TRD_HAL_CONTEXTSETUSERMSRBITS_001 */

  /* #80 Perform a hardware context switch. */
  Os_Hal_ContextSwitch(Current->Context, Next->Context);                                                                /* SBSW_OS_TRD_HAL_CONTEXTSWITCH_001 */
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_ThreadSuspendAndStart()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ThreadSuspendAndStart,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Current,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Next,
  boolean CallPreThreadHook
))
{
  Os_StackOverflowCheck();

  /* #10 Tell timing protection module to switch. */
  {
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) core;
    P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) configTp;
    P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST) currentTp;
    P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST) nextTp;

    core = Os_ThreadGetCore(Next);                                                                                      /* SBSW_OS_FC_PRECONDITION */
    configTp = Os_CoreAsrGetTimingProtection(core);                                                                     /* SBSW_OS_TRD_COREASRGETTIMINGPROTECTION_001 */
    currentTp = Os_ThreadGetTpConfig(Current);                                                                          /* SBSW_OS_FC_PRECONDITION */
    nextTp = Os_ThreadGetTpConfig(Next);                                                                                /* SBSW_OS_FC_PRECONDITION */
    Os_TpSwitch(configTp, currentTp, nextTp, Next);                                                                     /* SBSW_OS_TRD_TPSWITCH_001 */
  }

  /* #15 Store FPU context if needed */
  Os_ThreadStoreFpuContext(Current);                                                                                    /* SBSW_OS_FC_PRECONDITION */

  /* #20 Resume memory protection access rights of Next. */
  Os_MpSwitch(Current->Dyn->MpAccessRights, Next->Dyn->MpAccessRights);                                                 /* SBSW_OS_TRD_MPSWITCH_002 */

  /* #30 Call PreThreadHook. */
  Os_ThreadCallPreThreadHook(Next, CallPreThreadHook);                                                                  /* SBSW_OS_FC_PRECONDITION */

  /* #40 Switch current thread pointer. */
  Os_CoreSetThread(Next);                                                                                               /* SBSW_OS_FC_PRECONDITION */

  /* #50 Set the current stack pointer. */
  Os_CoreSetCurrentStack(Next->Stack, Next->Core);                                                                      /* SBSW_OS_TRD_CORESETCURRENTSTACK_001 */

  /* #60 Prepare context of next thread. */
  Os_Hal_ContextInit(Next->ContextConfig, Next->Context);                                                               /* SBSW_OS_TRD_HAL_CONTEXTINIT_001 */

  /* #70 Setup FPU for next thread. */
  Os_ThreadInitFpu(Next);                                                                                               /* SBSW_OS_FC_PRECONDITION */

  /* #80 Set parameter for the entry function, currently only used for hooks (hook thread pointer). */
  Os_Hal_ContextSetParameter(Next->Context, Next);                                                                      /* PRQA S 0315 */ /* MD_Os_Dir1.1_0315 */ /* SBSW_OS_TRD_HAL_CONTEXTSETPARAMETER_001 */

  /* #90 Update the Msr of the next thread. */
  Os_Hal_ContextSetUserMsrBits(Next->Context);                                                                          /* SBSW_OS_TRD_HAL_CONTEXTSETUSERMSRBITS_001 */

  /* #100 Perform context switch. */
  Os_Hal_ContextCallOnStack(Current->Context, Next->Context);                                                           /* SBSW_OS_TRD_HAL_CONTEXTCALLONSTACK_001 */

  /* #110 Restore FPU context if needed */
  Os_ThreadRestoreFpuContext(Current);                                                                                  /* SBSW_OS_FC_PRECONDITION */
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_ThreadGetAccessRights()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE                                                                            /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
P2CONST(Os_AccessCheckConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE,
Os_ThreadGetAccessRights,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  return Thread->AccessRights;
}


/***********************************************************************************************************************
 *  Os_ThreadGetMpAccessRights()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE                                                                            /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
P2CONST(Os_MpAccessRightsType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE,
Os_ThreadGetMpAccessRights,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  return Thread->Dyn->MpAccessRights;
}


/***********************************************************************************************************************
 *  Os_ThreadSetMpAccessRights()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void,
OS_CODE, OS_ALWAYS_INLINE, Os_ThreadSetMpAccessRights,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread,
  P2CONST(Os_MpAccessRightsType, AUTOMATIC, OS_CONST) AccessRights
))
{
  Thread->Dyn->MpAccessRights = AccessRights;                                                                           /* SBSW_OS_TRD_THREADGETDYN_001 */
}


/***********************************************************************************************************************
 *  Os_ThreadSetInterruptState()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void,
OS_CODE, OS_ALWAYS_INLINE, Os_ThreadSetInterruptState,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread,
  P2CONST(Os_Hal_IntStateType, AUTOMATIC, OS_CONST) InterruptState
))
{
  Os_Hal_ContextSetInterruptState(Thread->Context, InterruptState);                                                     /* SBSW_OS_FC_PRECONDITION */
}

/***********************************************************************************************************************
 *  Os_ThreadCallPreThreadHook()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void,
OS_CODE, OS_ALWAYS_INLINE, Os_ThreadCallPreThreadHook,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread,
  boolean CallPreThreadHook
))
{
  /* #10 Call the PreThreadHook if requested and configured. */
  if((CallPreThreadHook == TRUE) && (Thread->PreThreadHook != NULL_PTR))
  {
    Thread->PreThreadHook();                                                                                            /* SBSW_OS_TRD_PRETHREAD_CALLBACK_001 */
  }
}


/***********************************************************************************************************************
 *  Os_ThreadCallContextOnStack(()
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ThreadCallContextOnStack,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread,
  P2CONST(Os_Hal_ContextConfigType, AUTOMATIC, OS_CONST) HalContextCfg,
  P2CONST(Os_Hal_ContextStackConfigType, AUTOMATIC, OS_CONST) HalStackCfg,
  P2CONST(void, AUTOMATIC, OS_VAR_NOINIT) Parameter,
  P2CONST(Os_Hal_IntStateType, AUTOMATIC, OS_VAR_NOINIT) InterruptState,
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) CallerContext,
  P2VAR(Os_ThreadContextRefType, AUTOMATIC, OS_VAR_NOINIT) CalleeContext
))
{
  Os_Hal_ContextType calleeContext;

  *CalleeContext = &calleeContext;                                                                                      /* PRQA S 3225 */ /* MD_Os_Rule18.6_3225 */ /* SBSW_OS_PWA_PRECONDITION */

  /* #10 Prepare non-trusted function context. Set its parameter, stack, interrupt and machine state. */
  Os_Hal_ContextInit(HalContextCfg, &calleeContext);                                                                    /* SBSW_OS_TRD_HAL_CONTEXTINIT_002 */
  Os_Hal_ContextSetParameter(&calleeContext, Parameter);                                                                /* SBSW_OS_TRD_HAL_CONTEXTSETPARAMETER_002 */
  Os_Hal_ContextSetStack(&calleeContext, HalStackCfg);                                                                  /* SBSW_OS_TRD_HAL_CONTEXTSETSTACK_001 */
  Os_Hal_ContextSetInterruptState(&calleeContext, InterruptState);                                                      /* SBSW_OS_TRD_HAL_CONTEXTSETINTERRUPTSTATE_002 */
  Os_Hal_ContextSetUserMsrBits(&calleeContext);                                                                         /* SBSW_OS_FC_POINTER2LOCAL */

  /* #20 If the calling thread needs saving of the FPU context: */
  if(Os_ThreadIsFpuContextEnabledForThread(Thread) != 0u)                                                               /* SBSW_OS_FC_PRECONDITION */
  {
    /*!
     * Internal comment removed.
 *
 *
 *
     */
    Os_Hal_ContextFpuContextType fpuContext;

    /* #30 Store and reinitialize FPU context. */
    Os_Hal_ContextStoreFpuContext(&fpuContext);                                                                         /* SBSW_OS_FC_POINTER2LOCAL */
    Os_ThreadInitFpu(Thread);                                                                                           /* SBSW_OS_FC_PRECONDITION */

    /* #40 Switch to prepared context. */
    Os_Hal_ContextCallOnStack(CallerContext, &calleeContext);                                                           /* SBSW_OS_TRD_HAL_CONTEXTCALLONSTACK_001 */

    /* #50 Restore the FPU context. */
    Os_Hal_ContextRestoreFpuContext(&fpuContext);                                                                       /* SBSW_OS_FC_POINTER2LOCAL */
  }
  /* #60 Otherwise */
  else
  {
    /* #70 Switch to prepared context. */
    Os_Hal_ContextCallOnStack(CallerContext, &calleeContext);                                                           /* SBSW_OS_TRD_HAL_CONTEXTCALLONSTACK_001 */
  }

  /* #80 Invalidate output pointer. */
  *CalleeContext = NULL_PTR;                                                                                            /* PRQA S 3225 */ /* MD_Os_Rule18.6_3225 */ /* SBSW_OS_PWA_PRECONDITION */
}                                                                                                                       /* PRQA S 6050, 6060 */ /* MD_Os_STCAL, MD_Os_STPAR */


/***********************************************************************************************************************
 *  Os_ThreadCallContext(()
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ThreadCallContext,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread,
  P2CONST(Os_Hal_ContextConfigType, AUTOMATIC, OS_CONST) HalContextCfg,
  P2CONST(void, AUTOMATIC, OS_VAR_NOINIT) Parameter,
  P2CONST(Os_Hal_IntStateType, AUTOMATIC, OS_VAR_NOINIT) InterruptState,
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) CallerContext,
  P2VAR(Os_ThreadContextRefType, AUTOMATIC, OS_VAR_NOINIT) CalleeContext
))
{
  Os_Hal_ContextType calleeContext;

  *CalleeContext = &calleeContext;                                                                                      /* PRQA S 3225 */ /* MD_Os_Rule18.6_3225 */ /* SBSW_OS_PWA_PRECONDITION */

  /* #10 Prepare call context. Set its parameter, interrupt and machine state. */
  Os_Hal_ContextInit(HalContextCfg, &calleeContext);                                                                    /* SBSW_OS_TRD_HAL_CONTEXTINIT_002 */
  Os_Hal_ContextSetParameter(&calleeContext, Parameter);                                                                /* SBSW_OS_FC_POINTER2LOCAL */
  Os_Hal_ContextSetInterruptState(&calleeContext, InterruptState);                                                      /* SBSW_OS_FC_POINTER2LOCAL */
  Os_Hal_ContextSetUserMsrBits(&calleeContext);                                                                         /* SBSW_OS_FC_POINTER2LOCAL */

  /* #20 If the calling thread needs saving of the FPU context: */
  if(Os_ThreadIsFpuContextEnabledForThread(Thread) != 0u)                                                               /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_UNSUPPORTED89701_XF */
  {
    /*!
     * Internal comment removed.
 *
 *
 *
     */
    Os_Hal_ContextFpuContextType fpuContext;

    /* #30 Store and reinitialize FPU context. */
    Os_Hal_ContextStoreFpuContext(&fpuContext);                                                                         /* SBSW_OS_FC_POINTER2LOCAL */
    Os_ThreadInitFpu(Thread);                                                                                           /* SBSW_OS_FC_PRECONDITION */

    /*! Internal comment removed.
 *
 *
 * */

    /* #40 Switch to prepared context. */
    Os_Hal_ContextCall(CallerContext, &calleeContext);                                                                  /* SBSW_OS_TRD_HAL_CONTEXTCALL_001 */


    /* #50 Restore the FPU context. */
    Os_Hal_ContextRestoreFpuContext(&fpuContext);                                                                       /* SBSW_OS_FC_POINTER2LOCAL */
  }
  /* #60 Otherwise */
  else
  {
    /* #70 Switch to prepared context. */
    Os_Hal_ContextCall(CallerContext, &calleeContext);                                                                  /* SBSW_OS_TRD_HAL_CONTEXTCALL_001 */
  }

  /* #80 Invalidate output pointer. */
  *CalleeContext = NULL_PTR;                                                                                            /* PRQA S 3225 */ /* MD_Os_Rule18.6_3225 */ /* SBSW_OS_PWA_PRECONDITION */
}                                                                                                                       /* PRQA S 6050, 6060 */ /* MD_Os_STCAL, MD_Os_STPAR */


/***********************************************************************************************************************
 *  Os_ThreadInitFpuContext()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ThreadInitFpuContext,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  /* #10 If the FPU context needs to be stored at context switches */
  if(Os_ThreadIsFpuContextEnabledForThread(Thread) != 0u)                                                               /* SBSW_OS_FC_PRECONDITION */
  {
    /* #20 Initialize the FPU context. */
    P2VAR(Os_ThreadClassType, AUTOMATIC, OS_VAR_NOINIT) threadClassObject;

    threadClassObject = Os_CoreGetThreadClass(Os_ThreadGetCore(Thread));                                                /* SBSW_OS_TRD_COREGETTHREADCLASS_001 */ /* SBSW_OS_FC_PRECONDITION */
    Os_Hal_ContextInitFpuContext(Thread->FpuContext, &(threadClassObject->InitialFpuContext));                          /* SBSW_OS_TRD_HAL_CONTEXTINITFPUCONTEXT_001 */
  }
}


/***********************************************************************************************************************
 *  Os_ThreadInitFpu()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ThreadInitFpu,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  /* #10 If the FPU context needs to be stored at context switches: */
  if(Os_ThreadIsFpuContextEnabledForThread(Thread) != 0u)                                                               /* SBSW_OS_FC_PRECONDITION */
  {
    /* #20 Initialize the FPU from stored initial FPU context. */
    P2VAR(Os_ThreadClassType, AUTOMATIC, OS_VAR_NOINIT) threadClassObject;

    threadClassObject = Os_CoreGetThreadClass(Os_ThreadGetCore(Thread));                                                /* SBSW_OS_TRD_COREGETTHREADCLASS_001 */ /* SBSW_OS_FC_PRECONDITION */
    Os_Hal_ContextInitFpu(&(threadClassObject->InitialFpuContext));                                                     /* SBSW_OS_TRD_HAL_CONTEXTINITFPU_001 */
  }
}


/***********************************************************************************************************************
 *  Os_ThreadStoreFpuContext()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ThreadStoreFpuContext,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  if(Os_ThreadIsFpuContextEnabledForThread(Thread) != 0u)                                                               /* SBSW_OS_FC_PRECONDITION */
  {
    Os_Hal_ContextStoreFpuContext(Thread->FpuContext);                                                                  /* SBSW_OS_TRD_HAL_CONTEXTSTOREFPUCONTEXT_001 */
  }
}


/***********************************************************************************************************************
 *  Os_ThreadRestoreFpuContext()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ThreadRestoreFpuContext,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  if(Os_ThreadIsFpuContextEnabledForThread(Thread) != 0u)                                                               /* SBSW_OS_FC_PRECONDITION */
  {
    Os_Hal_ContextRestoreFpuContext(Thread->FpuContext);                                                                /* SBSW_OS_TRD_HAL_CONTEXTRESTOREFPUCONTEXT_001 */
  }
}


/***********************************************************************************************************************
 *  Os_ThreadIsFpuContextEnabledForThread()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ThreadIsFpuContextEnabledForThread,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  Os_StdReturnType result;

  /* #10 If FPU context is enabled: */
  if(Os_ThreadIsFpuContextEnabled() != 0u)
  {
    /* #20 If FPU context is generally enabled for all threads return !0. */
    if(Os_ThreadAllThreadsUseFpu() != 0u)
    {
      result = !0u;                                                                                                     /* PRQA S 4404, 4558 */  /* MD_Os_C90BooleanCompatibility, MD_Os_Rule10.1_4558 */
    }
    /* #30 Otherwise return whether the given thread uses FPU context. */
    else
    {
      result = (Os_StdReturnType)Thread->UsesFpu;
    }
  }
  /* #40 Otherwise return 0. */
  else
  {
    result = 0;
  }

  return result;
}


/***********************************************************************************************************************
 *  Os_ThreadAllThreadsUseFpu()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ThreadAllThreadsUseFpu,
(
  void
))
{
  /* #10 Return whether all threads use FPU. */
  return (OS_CFG_THREAD_FPU_CONTEXT_FOR_ALL_THREADS_ENABLED == STD_ON);                                                 /* PRQA S 4404, 4548 */ /* MD_Os_C90BooleanCompatibility, MD_Os_Rule10.1_4548 */
}


/***********************************************************************************************************************
 *  Os_ThreadIsFpuContextEnabled()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ThreadIsFpuContextEnabled,
(
  void
))
{
  /* #10 Return whether FPU contexts are enabled. */
  return (OS_CFG_THREAD_FPU_CONTEXT_ENABLED == STD_ON);                                                                 /* PRQA S 4404, 4548 */ /* MD_Os_C90BooleanCompatibility, MD_Os_Rule10.1_4548 */
}


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
