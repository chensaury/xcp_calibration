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
 * \addtogroup Os_Thread
 * \{
 *
 * \file
 * \brief       Provides thread related function implementations.
 * \details     --no details--
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777, 0779, 0828  EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */


#define OS_THREAD_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Thread.h"

/* Os kernel module dependencies */
#include "Os_Task.h"
#include "Os_Isr.h"
#include "Os_Hook.h"
#include "Os_Error.h"

/* Os hal dependencies */
#include "Os_Hal_Compiler.h"


/***********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define OS_START_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */


/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_ThreadSuicide()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(void, OS_CODE, OS_NORETURN, Os_ThreadSuicide, (void))
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread = Os_CoreGetThread();

  switch(Os_ThreadGetInitialType(currentThread))                                                                        /* SBSW_OS_TRD_THREADGETCORE_001 */
  {
    case OS_CALLCONTEXT_TASK:
        Os_TaskSuicide(); /* function never returns! */
      break;

    case OS_CALLCONTEXT_ISR2:
        Os_IsrSuicide(); /* function never returns! */
      break;

    case OS_CALLCONTEXT_ERRORHOOK:
    case OS_CALLCONTEXT_STARTUPHOOK:
    case OS_CALLCONTEXT_IOCCALLBACK:
        Os_HookSuicide(); /* function never returns! */
      break;

    case OS_CALLCONTEXT_PRETASKHOOK:                                                                                    /* COV_OS_INVSTATE */
    case OS_CALLCONTEXT_POSTTASKHOOK:                                                                                   /* COV_OS_INVSTATE */
    case OS_CALLCONTEXT_ALARMCALLBACK:                                                                                  /* COV_OS_INVSTATE */
    case OS_CALLCONTEXT_SHUTDOWNHOOK:                                                                                   /* COV_OS_INVSTATE */
    case OS_CALLCONTEXT_PROTECTIONHOOK:                                                                                 /* COV_OS_INVSTATE */
    default:                                                                                                            /* COV_OS_INVSTATE */
      /* Invalid OS state. */
      Os_ErrKernelPanic(); /* function never returns! */
      break;
  }

  /* Invalid OS state. */
  Os_ErrKernelPanic(); /* function never returns! */
}


#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* module specific MISRA deviations:
 */

/* SBSW_JUSTIFICATION_BEGIN

\ID SBSW_OS_TRD_THREADGETCORE_001
 \DESCRIPTION    Os_ThreadGetInitialType is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_TRD_THREADINITFPUCONTEXT_001
 \DESCRIPTION    Os_ThreadInitFpuContext is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_TRD_THREADGETCORE_002
 \DESCRIPTION    Os_ThreadGetCore is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_TRD_THREADGETDYN_001
 \DESCRIPTION    Write access to the return value of Os_ThreadGetDyn. The Thread pointer is passed as argument to the
                 caller function. Precondition ensures that the argument pointer is valid. The compliance of the
                 precondition is check during review.
 \COUNTERMEASURE \N [CM_OS_THREADGETDYN_N]

\ID SBSW_OS_TRD_RESOURCEFORCIBLYRELEASELOCKS_001
 \DESCRIPTION    Os_ResourceForciblyReleaseLocks is called with the return value of Os_ThreadGetLocks.
 \COUNTERMEASURE \N [CM_OS_THREADGETLOCKS_N]

\ID SBSW_OS_TRD_LOCKLISTINIT_001
 \DESCRIPTION    Os_LockListInit is called with the the Locks argument derived from the Dyn pointer of a Thread.
                 The Thread is passed as argument to the caller.
 \COUNTERMEASURE \N [CM_OS_THREADGETLOCKS_N]

\ID SBSW_OS_TRD_SPINLOCKLISTINIT_001
 \DESCRIPTION    Os_SpinlockListInit is called with the return value of Os_ThreadGetSpinlocks.
 \COUNTERMEASURE \N [CM_OS_THREADGETSPINLOCKS_N]
\ID SBSW_OS_TRD_LOCKLISTISEMPTY_001
 \DESCRIPTION    Os_LockListIsEmpty is called with an iterator pointer which was initialized with a value passed
                 the Locks value of a Thread. Thread is passed as argument to the caller. Precondition ensures
                 that the argument pointer is valid. The compliance of the precondition is check during review.
 \COUNTERMEASURE \R [CM_LOCKLISTISEMPTY_R]

\ID SBSW_OS_TRD_SERVICECALLSINIT_001
 \DESCRIPTION    Os_ServiceCallsInit is called with an the ServiceCalls member derived from a thread. Thread
                 is passed as argument to the caller. Precondition ensures that the argument pointer is valid.
                 The compliance of the precondition is check during review.
 \COUNTERMEASURE \T [CM_OS_THREADGETSERVICECALLS_01_02_T]
                 \T [CM_OS_THREADGETSERVICECALLS_02_02_T]

\ID SBSW_OS_TRD_LOCKLISTISTOPRES_001
 \DESCRIPTION    Os_LockListIsTopRes is called with an iterator.
 \COUNTERMEASURE \R Loop condition ensures that the passed pointer is valid.

\ID SBSW_OS_TRD_LOCKLISTISTOPSPINLOCK_001
 \DESCRIPTION    Os_LockListIsTopSpinlock is called with an iterator.
 \COUNTERMEASURE \R Loop condition ensures that the passed pointer is valid.

\ID SBSW_OS_TRD_LOCKLISTNEXT_001
 \DESCRIPTION    Os_LockListNext is called with an iterator.
 \COUNTERMEASURE \R Loop condition ensures that the passed pointer is valid.

\ID SBSW_OS_TRD_INTERRUPTCLEANUP_001
 \DESCRIPTION    Os_InterruptCleanup is called with the IntApiState of a Thread. Thread is passed as argument to the
                 caller. Precondition ensures that the argument pointer is valid. The compliance of the precondition
                 is check during review.
 \COUNTERMEASURE \M [CM_OS_THREADGETINTERRUPTAPISTATE_M]

\ID SBSW_OS_TRD_INTERRUPTCHECKENABLED_001
 \DESCRIPTION    Os_InterruptCheckEnabled is called with the IntApiState of a Thread. Thread is passed as argument to
                 the caller. Precondition ensures that the argument pointer is valid. The compliance of the precondition
                 is check during review.
 \COUNTERMEASURE \M [CM_OS_THREADGETINTERRUPTAPISTATE_M]

\ID SBSW_OS_TRD_COREASRGETTIMINGPROTECTION_001
 \DESCRIPTION    Os_CoreAsrGetTimingProtection is called with the return value of Os_ThreadGetCore.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_TRD_TPTHREADINIT_001
 \DESCRIPTION    Os_TpThreadInit is called with the return values of Os_CoreAsrGetTimingProtection and
                 Os_ThreadGetTpConfig.
 \COUNTERMEASURE \M [CM_OS_COREASRGETTIMINGPROTECTION_M]
                 \M [CM_OS_THREADGETTPCONFIG_M]

\ID SBSW_OS_TRD_TPRESETANDRESUME_001
 \DESCRIPTION    Os_TpResetAndResume is called with the return values of Os_CoreAsrGetTimingProtection and
                 Os_ThreadGetTpConfig and an argument passed to the caller. Precondition ensures that the argument
                 pointer is valid. The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_COREASRGETTIMINGPROTECTION_M]
                 \M [CM_OS_THREADGETTPCONFIG_M]

\ID SBSW_OS_TRD_TPSWITCH_001
 \DESCRIPTION    Os_TpSwitch is called with the return values of Os_CoreAsrGetTimingProtection and
                 Os_ThreadGetTpConfig and an argument passed to the caller. Precondition ensures that the argument
                 pointer is valid. The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_COREASRGETTIMINGPROTECTION_M]
                 \M [CM_OS_THREADGETTPCONFIG_M]

\ID SBSW_OS_TRD_THREADISTASK_001
 \DESCRIPTION    Os_ThreadIsTask is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_TRD_THREADGETTPCONFIG_001
 \DESCRIPTION    Os_ThreadGetTpConfig is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_TRD_SERVICECALLFORCERELEASE_001
 \DESCRIPTION    Os_ServiceCallForceRelease is called with ServiceCalls which is derived from the Dyn pointer of a
                 thread. The thread is the return value of Os_CoreGetThread. Precondition ensures that the pointer
                 returned by Os_CoreGetThread is valid. The compliance of the precondition is check during review.
 \COUNTERMEASURE \T [CM_OS_THREADGETSERVICECALLS_01_02_T]
                 \T [CM_OS_THREADGETSERVICECALLS_02_02_T]

\ID SBSW_OS_TRD_MPTHREADINIT_001
 \DESCRIPTION    Os_MpThreadInit is called with the static and dynamic MpAccessRights data of a thread which
                 is passed as argument to the caller function. Precondition ensures that the argument pointer is valid.
                 The compliance of the precondition is check during review. The dynamic MpAccessRights are derived
                 from the Dyn data of the Thread. As each thread object of an abstract class is always part of a
                 concrete class, the concrete class guarantees, that the Dyn pointer is valid.
 \COUNTERMEASURE \T [CM_OS_THREADGETMPACCESSRIGHTS_T]
                 \M [CM_OS_THREADGETMPACCESSRIGHTSINITIAL_M]

\ID SBSW_OS_TRD_MPSWITCH_001
 \DESCRIPTION    Os_MpSwitch is called with the dynamic MpAccessRights data of two threads. The first thread is
                 the return value of Os_CoreGetThread. Precondition ensures that the pointer
                 returned by Os_CoreGetThread is valid. The second thread is passed as argument to the caller function.
                 Precondition ensures that the argument pointer is valid. The compliance of the preconditions is check
                 during review.
 \COUNTERMEASURE \T [CM_OS_THREADGETMPACCESSRIGHTS_T]

\ID SBSW_OS_TRD_MPSWITCH_002
 \DESCRIPTION    Os_MpSwitch is called with the dynamic MpAccessRights data of two threads. Both are passed as
                 arguments to the caller function. Precondition ensures that the argument pointer is valid.
                 The compliance of the preconditions is check during review.
 \COUNTERMEASURE \T [CM_OS_THREADGETMPACCESSRIGHTS_T]

\ID SBSW_OS_TRD_MPSWITCHTO_001
 \DESCRIPTION    Os_MpSwitchTo is called with the dynamic MpAccessRights data of a thread. The thread is passed as
                 argument to the caller function. Precondition ensures that the argument pointer is valid.
                 The compliance of the preconditions is check during review.
 \COUNTERMEASURE \T [CM_OS_THREADGETMPACCESSRIGHTS_T]

\ID SBSW_OS_TRD_HAL_CONTEXTINIT_001
 \DESCRIPTION    Os_Hal_ContextInit is called with ContextConfig and Context of a thread which
                 is passed as argument to the caller function. Precondition ensures that the argument pointer is valid.
                 The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_THREADGETCONTEXT_M]
                 \M [CM_OS_THREADGETCONTEXTCONFIG_M]

\ID SBSW_OS_TRD_HAL_CONTEXTINIT_002
 \DESCRIPTION    Os_Hal_ContextInit is called with a pointer to a context config object passed as argument to the caller
                 and a pointer to a local variable. Precondition ensures that the argument pointer is valid.
 \COUNTERMEASURE \N [CM_OS_PRECONDITION_N]

\ID SBSW_OS_TRD_HAL_CONTEXTRETURN_001
 \DESCRIPTION    Os_Hal_ContextReturn is called with the Contexts of two threads which
                 is passed as argument to the caller function. Precondition ensures that the argument pointer is valid.
                 The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_THREADGETCONTEXT_M]

\ID SBSW_OS_TRD_HAL_CONTEXTRESET_001
 \DESCRIPTION    Os_Hal_ContextReset is called with ContextConfig and Context of a thread which
                 is passed as argument to the caller function. Precondition ensures that the argument pointer is valid.
                 The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_THREADGETCONTEXT_M]
                 \M [CM_OS_THREADGETCONTEXTCONFIG_M]

\ID SBSW_OS_TRD_HAL_CONTEXTABORT_001
 \DESCRIPTION    Os_Hal_ContextAbort is called with ContextConfig and Context of a thread which
                 is passed as argument to the caller function. Precondition ensures that the argument pointer is valid.
                 The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_THREADGETCONTEXT_M]
                 \M [CM_OS_THREADGETCONTEXTCONFIG_M]

\ID SBSW_OS_TRD_HAL_CONTEXTSETINTERRUPTSTATE_001
 \DESCRIPTION    Os_Hal_ContextSetInterruptState is called with the Context of a thread, which is passed as argument to
                 the caller function. Precondition ensures that the argument pointer is valid.
                 The compliance of the precondition is assured during review.
 \COUNTERMEASURE \M [CM_OS_THREADGETCONTEXT_M]
                 \M [CM_OS_THREADGETCONTEXTCONFIG_M]

\ID SBSW_OS_TRD_HAL_CONTEXTFIRSTRESUME_001
 \DESCRIPTION    Os_Hal_ContextFirstResume is called with the Context of a thread. The thread is passed as argument
                 to the caller function. Precondition ensures that the argument pointer is valid. The compliance of
                 the preconditions is checked during review.
 \COUNTERMEASURE \M [CM_OS_THREADGETCONTEXT_M]

\ID SBSW_OS_TRD_HAL_CONTEXTRESETANDRESUME_001
 \DESCRIPTION    Os_Hal_ContextResetAndResume is called with ContextConfig and Context of two threads. The first
                 thread is the return value of Os_CoreGetThread. Precondition ensures that the pointer
                 returned by Os_CoreGetThread is valid. The second thread is passed as argument to the caller function.
                 Precondition ensures that the argument pointer is valid. The compliance of the preconditions is check
                 during review.
 \COUNTERMEASURE \M [CM_OS_THREADGETCONTEXT_M]
                 \M [CM_OS_THREADGETCONTEXTCONFIG_M]

\ID SBSW_OS_TRD_HAL_CONTEXTSWITCH_001
 \DESCRIPTION    Os_Hal_ContextSwitch is called with the Contexts of two threads. Both threads are passed as arguments
                 to the caller function. Precondition ensures that the argument pointer is valid. The compliance of
                 the preconditions is checked during review.
 \COUNTERMEASURE \M [CM_OS_THREADGETCONTEXT_M]

\ID SBSW_OS_TRD_HAL_CONTEXTSETPARAMETER_001
 \DESCRIPTION    Os_Hal_ContextSetParameter is called with the Context of a thread and the a thread. Thread is passed
                 as argument to the caller function. Precondition ensures that the argument pointer is valid. The
                 compliance of the preconditions is checked during review.
 \COUNTERMEASURE \M [CM_OS_THREADGETCONTEXT_M]

\ID SBSW_OS_TRD_CORESETCURRENTSTACK_001
 \DESCRIPTION    Os_CoreSetCurrentStack is called with a Stack and a Core which is derived from a thread passed to the 
                 calling function. Precondition ensures that the passed pointers are valid.
                 The compliance of the precondition is checked during review.
 \COUNTERMEASURE \M [CM_OS_THREADGETSTACK_M]

\ID SBSW_OS_TRD_TPTHREADKILL_001
 \DESCRIPTION    Os_TpThreadKill is called with the return value of Os_ThreadGetTpConfig.
 \COUNTERMEASURE \M [CM_OS_THREADGETTPCONFIG_M]

\ID SBSW_OS_TRD_TRACETHREADINIT_001
 \DESCRIPTION    Os_TraceThreadInit is called with the the Trace member of a thread. The thread is passed as argument
                 to the caller function. Precondition ensures that the argument pointer is valid. The compliance of the
                 preconditions is checked during review.
 \COUNTERMEASURE \M [CM_OS_THREADGETTRACE_M]

\ID SBSW_OS_TRD_HAL_CONTEXTCALLONSTACK_001
 \DESCRIPTION    Os_Hal_ContextCallOnStack is called with the Contexts of two thread. The threads are passed as
                 arguments to the caller function. Precondition ensures that the argument pointer is valid. The
                 compliance of the preconditions is checked during review.
 \COUNTERMEASURE \M [CM_OS_THREADGETCONTEXT_M]

\ID SBSW_OS_TRD_HAL_CONTEXTCALLONSTACK_002
 \DESCRIPTION    Os_Hal_ContextCallOnStack is called with a pointer which is passed as argument to the caller function
                 and a pointer to a local variable. Precondition ensures that the argument pointer is valid.
 \COUNTERMEASURE \N [CM_OS_PRECONDITION_N]

\ID SBSW_OS_TRD_HAL_CONTEXTCALL_001
 \DESCRIPTION    Os_Hal_ContextCall is called with a pointer which is passed as argument to the caller function
                 and a pointer to a local variable. Precondition ensures that the argument pointer is valid.
 \COUNTERMEASURE \N [CM_OS_PRECONDITION_N]

\ID SBSW_OS_TRD_PRETHREAD_CALLBACK_001
 \DESCRIPTION    The PreThreadHook is used as a function pointer will only be called if requested and not NULL.
 \COUNTERMEASURE \M [CM_OS_THREADPRETHREAD_CALLBACK_M]
                 \R [CM_OS_THREADPRETHREAD_R]

\ID SBSW_OS_TRD_HAL_CONTEXTINITFPUCONTEXT_001
 \DESCRIPTION    Os_Hal_ContextInitFpuContext is called with a value derived from the return of Os_CoreGetThreadClass
                 and a pointer derived from an argument of the caller function. Precondition ensures that the argument
                 pointer is valid.
 \COUNTERMEASURE \M [CM_OS_COREASR_THREADCLASS_M]
                 \M [CM_OS_THREADGETFPUCONTEXT_M]

\ID SBSW_OS_TRD_HAL_CONTEXTINITFPU_001
 \DESCRIPTION    Os_Hal_ContextInitFpu is called with a value derived from the return of Os_CoreGetThreadClass.
 \COUNTERMEASURE \M [CM_OS_COREASR_THREADCLASS_M]
                 \M [CM_OS_THREADGETFPUCONTEXT_M]

\ID SBSW_OS_TRD_HAL_CONTEXTSTOREFPUCONTEXT_001
 \DESCRIPTION    Os_Hal_ContextStoreFpuContext is called with the FPU context of a thread. The thread is passed as
                 an argument to the caller function. Precondition ensures that the argument pointer is valid.
                 The compliance of the preconditions is checked during review.
 \COUNTERMEASURE \M [CM_OS_THREADGETFPUCONTEXT_M]

\ID SBSW_OS_TRD_HAL_CONTEXTRESTOREFPUCONTEXT_001
 \DESCRIPTION    Os_Hal_ContextRestoreFpuContext is called with the FPU context of a thread. The thread is passed as
                 an argument to the caller function. Precondition ensures that the argument pointer is valid.
                 The compliance of the preconditions is checked during review.
 \COUNTERMEASURE \M [CM_OS_THREADGETFPUCONTEXT_M]

\ID SBSW_OS_TRD_HAL_CONTEXTSETPARAMETER_002
 \DESCRIPTION    Os_Hal_ContextSetParameter is called with a pointer to a local variable and a pointer which is passed
                 as argument to the caller function. Precondition ensures that the argument pointer is valid.
 \COUNTERMEASURE \N [CM_OS_PRECONDITION_N]

\ID SBSW_OS_TRD_HAL_CONTEXTSETSTACK_001
 \DESCRIPTION    Os_Hal_ContextSetStack is called with a pointer to a local variable and a pointer which is passed
                 as argument to the caller function. Precondition ensures that the argument pointer is valid.
 \COUNTERMEASURE \N [CM_OS_PRECONDITION_N]

\ID SBSW_OS_TRD_HAL_CONTEXTSETINTERRUPTSTATE_002
 \DESCRIPTION    Os_Hal_ContextSetInterruptState is called with a pointer to a local variable and a pointer which is
                 passed as argument to the caller function. Precondition ensures that the argument pointer is valid.
 \COUNTERMEASURE \N [CM_OS_PRECONDITION_N]

\ID SBSW_OS_TRD_COREGETTHREADCLASS_001
 \DESCRIPTION    Os_CoreGetThreadClass is called with a value derived from the return value of Os_ThreadGetCore.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_TRD_HAL_CONTEXTSETUSERMSRBITS_001
 \DESCRIPTION    Os_Hal_ContextSetUserMsrBits is called with the Context of a thread, which is passed as argument to
                 the caller function. Precondition ensures that the argument pointer is valid.
                 The compliance of the precondition is assured during review.
 \COUNTERMEASURE \M [CM_OS_THREADGETCONTEXT_M]

SBSW_JUSTIFICATION_END */

/*
\CM CM_OS_THREADGETLOCKS_N
      Locks is derived from a thread Dyn pointer. As each object of an abstract class is always part of a concrete
      class, the concrete class  guarantees, that the Dyn pointer is valid.
      Precondition ensures that the Locks pointer is valid. The compliance of the precondition is check during review.

\CM CM_OS_THREADGETSPINLOCKS_N
      Precondition ensures that the pointer is valid. The compliance of the precondition is check during review.

\CM CM_OS_THREADGETSERVICECALLS_01_02_T
      TCASE-345836 ensures that ServiceCalls is initialized during init phase.

\CM CM_OS_THREADGETSERVICECALLS_02_02_T
      Data modification of ServiceCalls occurs only in subcomponent ServiceFunction.
      Consistency of objects is ensured by UnitTest TCASE-345832

\CM CM_OS_THREADGETTRACE_M
      Verify that the Trace reference in each thread instance, except hook threads,  is no NULL_PTR,
      if tracing is enabled.

\CM CM_OS_THREADGETSTACK_M
      Verify that the Stack reference of each thread is no NULL_PTR.

\CM CM_OS_THREADGETINTERRUPTAPISTATE_M
      Verify that the IntApiState reference in each thread instance is no NULL_PTR.

\CM CM_OS_THREADGETCORE_M
      Verify that the Core reference in each thread instance is no NULL_PTR.

\CM CM_OS_THREADGETCONTEXT_M
      Verify that the Context reference in each thread instance is no NULL_PTR.

\CM CM_OS_THREADGETCONTEXTCONFIG_M
      Verify that the ContextConfig reference in each thread instance is no NULL_PTR.

\CM CM_OS_THREADGETOWNERAPPLICATION_M
      Verify that the OwnerApplication reference in each thread instance is no NULL_PTR.

\CM CM_OS_THREADGETCURRENTAPPLICATION_N
      Thread is an abstract class. The validity of the Dyn pointer is ensured by checks of concrete classes.
      Precondition ensures that the Application pointer is valid. The compliance of the  precondition is check during
      review.

\CM CM_OS_THREADGETMPACCESSRIGHTSINITIAL_M
      Verify that the MpAccessRightsInitial reference in each thread instance is no NULL_PTR, if memory protection
      is enabled.

\CM CM_OS_THREADGETMPACCESSRIGHTS_T
      TCASE-345836 ensures the MpAccessRights member of dyn object is always initialized correctly, if required.

\CM CM_OS_THREADGETTPCONFIG_M
      Verify that the TimingProtection reference in each thread instance is no NULL_PTR, if timing protection is
      enabled.

\CM CM_OS_THREADGETDYN_N
      As each object of an abstract class is always part of a concrete class, the concrete class
      guarantees, that the Dyn pointer is valid.

\CM CM_OS_THREADGETACCESSRIGHTS_M
      Verify that the AccessRights reference in each thread instance is no NULL_PTR.

\CM CM_OS_THREADPRETHREAD_CALLBACK_M
      Verify that the PreThreadHook is Os_TaskCallPreTaskHook for all Thread objects defined within Tasks and
      NULL_PTR for all Thread objects defined in other types.

\CM CM_OS_THREADPRETHREAD_R
      Implementation ensures that the function pointer is not NULL_PTR before calling it.

\CM CM_OS_THREADGETFPUCONTEXT_M
      Verify that
        - FpuContext is no NULL_PTR in case that Context saving is enabled for thread (UsesFpu).
        - Context saving is enabled (UsesFpu) for all threads if OS_CFG_THREAD_FPU_CONTEXT_ALL_THREADS_ENABLED
          equals STD_ON.

 */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Thread.c
 **********************************************************************************************************************/
