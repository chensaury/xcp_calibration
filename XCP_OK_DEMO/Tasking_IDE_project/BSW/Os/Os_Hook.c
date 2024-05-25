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
 * \addtogroup Os_Hook
 * \{
 *
 * \file
 * \brief       Hook wrappers.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777, 0779, 0828  EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */


#define OS_HOOK_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hook_Cfg.h"
#include "Os_Hook_Types.h"
#include "Os_Hook.h"

/* Os kernel module dependencies */
#include "OsInt.h"
#include "Os_Core.h"
#include "Os_Error.h"
#include "Os_Ioc.h"
#include "Os_Thread.h"
#include "Os_Task.h"
#include "Os_Trap.h"

/* Os hal dependencies */
#include "Os_Hal_Core.h"


/***********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/
#if OS_CFG_PANICHOOK == STD_ON
# define OS_PANICHOOK        Os_PanicHook
#else
# define OS_PANICHOOK        Os_Hal_CoreFreeze
#endif

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
 *  Os_HookGetDyn()
 **********************************************************************************************************************/
/*! \brief          Returns the dynamic part of a hook.
 *  \details        --no details--
 *
 *  \param[in]      Hook  Hook to query. Parameter must not be NULL.
 *
 *  \return         Dynamic part.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2VAR(Os_HookType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE,
OS_ALWAYS_INLINE, Os_HookGetDyn,
(
  P2CONST(Os_HookConfigType, AUTOMATIC, OS_CONST) Hook
));


/***********************************************************************************************************************
 *  Os_HookIsNestingAllowed()
 **********************************************************************************************************************/
/*! \brief        Returns whether the given hook is allowed to occur in the given hook situation.
 *  \details      --no details--
 *
 *  \param[in]    CurrentHookStatus  Bitmask containing all hooks which are currently active.
 *                                   Parameter must not be NULL.
 *  \param[in]    HookToBeNested     Hook to be nested. Parameter must not be NULL.
 *
 *  \retval       !0    Nesting is not allowed
 *  \retval       0     Nesting is allowed
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_HookIsNestingAllowed,
(
    P2CONST(Os_HookInfoType, AUTOMATIC, OS_VAR_NOINIT) CurrentHookStatus,
    P2CONST(Os_HookConfigType, AUTOMATIC, OS_CONST)    HookToBeNested
));


/***********************************************************************************************************************
 *  Os_HookIsPanicHookEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether the \ref Os_PanicHook() enabled or not.
 *  \details      --no details--
 *
 *  \retval       !0    PanicHook is enabled.
 *  \retval       0     PanicHook is disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_HookIsPanicHookEnabled,
( void ));


/***********************************************************************************************************************
 *  Os_HookIsStatusHookEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether status hooks (ErrorHook or ShutdownHook) are enabled or not.
 *  \details      --no details--
 *
 *  \retval       !0    Status hooks are enabled.
 *  \retval       0     Status hooks are disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_HookIsStatusHookEnabled,
( void ));


/***********************************************************************************************************************
 *  Os_HookIsStartupHookEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether Startup hooks are enabled or not.
 *  \details      --no details--
 *
 *  \retval       !0    Startup hooks are enabled.
 *  \retval       0     Startup hooks are disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_HookIsStartupHookEnabled,
( void ));


/***********************************************************************************************************************
 *  Os_HookIsCallbackEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether callback hooks (StartupHook or IOC Callbacks) are enabled or not.
 *  \details      --no details--
 *
 *  \retval       !0    Callback hooks are enabled.
 *  \retval       0     Callback hooks are disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_HookIsCallbackEnabled,
( void ));


/***********************************************************************************************************************
 *  Os_HookReturnWithSchedule()
 **********************************************************************************************************************/
/*! \brief          Resume previous thread where the hook was called.
 *  \details        Return behavior for hooks which may return to a task which is not the task where the Hook has been
 *                  called. This is needed for killing.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_NORETURN, Os_HookReturnWithSchedule, (void));


/***********************************************************************************************************************
 *  Os_HookReturnWithoutSchedule()
 **********************************************************************************************************************/
/*! \brief          Resume previous thread where the hook was called.
 *  \details        Return behavior for hooks which do always return to the interrupted thread.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_NORETURN, Os_HookReturnWithoutSchedule, (void));


/***********************************************************************************************************************
 *  Os_HookCall()
 **********************************************************************************************************************/
/*! \brief          Call the given hook.
 *  \details        --no details--
 *
 *  \param[in]      Hook     The hook to call. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_HookCall,
(
  P2CONST(Os_HookConfigType, AUTOMATIC, OS_CONST) Hook
));

/***********************************************************************************************************************
 *  Os_Hook2StatusHook()
 **********************************************************************************************************************/
/*! \brief          Returns the hook as a StatusHook.
 *  \details        --no details--
 *
 *  \param[in]      Hook     The hook to convert. Parameter must not be NULL and must be a StatusHook
 *
 *  \return         StatusHook.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_HookStatusHookConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_Hook2StatusHook,
(
  P2CONST(Os_HookConfigType, AUTOMATIC, OS_CONST) Hook
));

/***********************************************************************************************************************
 *  Os_Hook2ProtectionHook()
 **********************************************************************************************************************/
/*! \brief          Returns the hook as a ProtectionHook.
 *  \details        --no details--
 *
 *  \param[in]      Hook     The hook to convert. Parameter must not be NULL and must be a ProtectionHook.
 *
 *  \return         ProtectionHook.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_HookProtectionHookConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_Hook2ProtectionHook,
(
  P2CONST(Os_HookConfigType, AUTOMATIC, OS_CONST) Hook
));


/***********************************************************************************************************************
 *  Os_Hook2InitHook()
 **********************************************************************************************************************/
/*! \brief          Returns the hook as an InitHook.
 *  \details        --no details--
 *
 *  \param[in]      Hook     The hook to convert. Parameter must not be NULL and must be an InitHook.
 *
 *  \return         InitHook.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_HookInitHookConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_Hook2InitHook,
(
  P2CONST(Os_HookConfigType, AUTOMATIC, OS_CONST) Hook
));


/***********************************************************************************************************************
 *  Os_HookGetDyn()
 **********************************************************************************************************************/
/*! \brief          Returns the dynamic part of a hook.
 *  \details        --no details--
 *
 *  \param[in]      Hook  Hook to query. Parameter must not be NULL.
 *
 *  \return         Dynamic part.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2VAR(Os_HookType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE,
OS_ALWAYS_INLINE, Os_HookGetDyn,
(
  P2CONST(Os_HookConfigType, AUTOMATIC, OS_CONST) Hook
));


/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  Os_HookIsNestingAllowed()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_HookIsNestingAllowed,
(
  P2CONST(Os_HookInfoType, AUTOMATIC, OS_VAR_NOINIT) CurrentHookStatus,
  P2CONST(Os_HookConfigType, AUTOMATIC, OS_CONST) HookToBeNested
))
{
  Os_HookFlagType unallowedNestingFlags = ~HookToBeNested->NestingMask;
  return ((Os_StdReturnType)((CurrentHookStatus->InHookFlags & unallowedNestingFlags) == 0u));                          /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_HookIsStatusHookEnabled()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_HookIsStatusHookEnabled, ( void ))
{
  return (Os_StdReturnType)((OS_CFG_ERRORHOOKS == STD_ON) || (OS_CFG_SHUTDOWNHOOKS == STD_ON));                         /* COV_OS_INVSTATE */ /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_HookIsStartupHookEnabled()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_HookIsStartupHookEnabled, ( void ))
{
  return (Os_StdReturnType)(OS_CFG_STARTUPHOOKS == STD_ON);                                                             /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_HookIsCallbackEnabled()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_HookIsCallbackEnabled, ( void ))
{
  Os_StdReturnType startupHookEnabled = Os_HookIsStartupHookEnabled();
  Os_StdReturnType iocHasCallback = Os_IocHasCallbacks();

  /* A logical OR instead of a bitwise OR would be more meaningful here.
   * But some compilers would complain about known decision outcome.
   * Moving the calls directly into the decision would solve this, but MISRA will complain about possible sideeffects
   * of the second call. The bitwise OR leads to correct functionality and overcomes both issues. */
  return (startupHookEnabled | iocHasCallback);
}


/***********************************************************************************************************************
 *  Os_HookReturn()
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
OS_FUNC_ATTRIBUTE_DEFINITION(void, OS_CODE, OS_NORETURN, Os_HookReturn, (void))
{
  P2CONST(Os_HookConfigType, AUTOMATIC, OS_CONST) currentHook;
  P2VAR(Os_HookInfoType, AUTOMATIC, OS_VAR_NOINIT) activeHooks;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;
  Os_HookTaskReturnType taskReturn;

  /* #10 Disable interrupts. */
  Os_IntDisable();

  currentThread = Os_CoreGetThread();

  currentHook = Os_HookThread2Hook(currentThread);                                                                      /* SBSW_OS_HK_HOOKTHREAD2HOOK_001 */

  /* #20 Restore the previous flag state. */
  activeHooks = Os_CoreGetHookInfo(Os_ThreadGetCore(currentThread));                                                    /* SBSW_OS_HK_COREGETHOOKINFO_001 */ /* SBSW_OS_HK_THREADGETCORE_001 */
  activeHooks->InHookFlags = Os_HookGetDyn(currentHook)->HookTypeFlag;                                                  /* SBSW_OS_HK_COREGETHOOKINFO_002 */ /* SBSW_OS_HK_HOOKGETDYN_001 */
  taskReturn = currentHook->TaskReturn;

  /* #25 If returning with schedule, skip scheduling depending on critical user section. */
  if(taskReturn == Os_HookTaskReturn_WithSchedule)
  {
    if(OS_UNLIKELY(Os_CoreCriticalUserSectionIsActive(Os_ThreadGetCore(currentThread)) == TRUE))                        /* SBSW_OS_HK_THREADGETCORE_001 */ /* SBSW_OS_HK_CORECRITICALUSERSECTIONISACTIVE_001 */
    {
      taskReturn = Os_HookTaskReturn_ToCallerTask;
    }
  }

  switch(taskReturn)
  {
    /* #30 If returning without schedule return directly. */
    case Os_HookTaskReturn_ToCallerTask:
      Os_HookReturnWithoutSchedule();
      break;

    /* #40 If scheduling is needed, return with schedule. */
    case Os_HookTaskReturn_WithSchedule:
      Os_HookReturnWithSchedule();
      break;

    /* #50 If returning for the first time begin scheduling. */
    case Os_HookTaskReturn_BeginScheduling:
      Os_TaskBeginScheduling();
      break;

    /* #60 For unknown values call the Panic Hook. */
    default:                                                                                                            /* COV_OS_INVSTATE */
      Os_ErrKernelPanic();
      break;
  }
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_HookReturnWithSchedule()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_NORETURN, Os_HookReturnWithSchedule,
(
  void
))
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) previousThread;

  currentThread = Os_CoreGetThread();

  previousThread = Os_CoreInterruptedThreadsPop(Os_ThreadGetCore(currentThread));                                       /* SBSW_OS_HK_COREINTERRUPTEDTHREADSPOP_001 */ /* SBSW_OS_HK_THREADGETCORE_001 */

  /* #10 If the previous thread is a task: */
  if(Os_ThreadIsTask(previousThread) != 0u)                                                                             /* SBSW_OS_HK_THREADISTASK_001 */
  {
    /* #20 Return to task level (consider that the previous task may be terminated): */
    Os_TaskReturnToTaskLevel(Os_TaskThread2Task(previousThread));                                                       /* SBSW_OS_HK_TASKRETURNTOTASKLEVEL_001 */ /* SBSW_OS_HK_TASKTHREAD2TASK_001 */
  }
  /* #30 Otherwise: Resume the interrupted ISR/hook. */
  else
  {
    /* In case of termination, its context has been aborted and only the return path is executed. */
    Os_ThreadCleanupAndResume(previousThread, FALSE);                                                                   /* SBSW_OS_HK_THREADCLEANUPANDRESUME_001 */
  }
}


/***********************************************************************************************************************
 *  Os_HookReturnWithoutSchedule()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_NORETURN, Os_HookReturnWithoutSchedule, (void))
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) previousThread;

  currentThread = Os_CoreGetThread();

  previousThread = Os_CoreInterruptedThreadsPop(Os_ThreadGetCore(currentThread));                                       /* SBSW_OS_HK_COREINTERRUPTEDTHREADSPOP_001 */ /* SBSW_OS_HK_THREADGETCORE_001 */

  /* #10 Resume the interrupted thread. */
  Os_ThreadCleanupAndResume(previousThread, FALSE);                                                                     /* SBSW_OS_HK_THREADCLEANUPANDRESUME_001 */
}


/***********************************************************************************************************************
 *  Os_HookCall()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_HookCall,
(
  P2CONST(Os_HookConfigType, AUTOMATIC, OS_CONST) Hook
))
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) localCore;
  P2VAR(Os_IntApiStateType, AUTOMATIC, OS_VAR_NOINIT) intApiStateRef;
  P2VAR(Os_HookInfoType, AUTOMATIC, OS_VAR_NOINIT) activeHooks;
  Os_IntApiStateType intApiStateCopy;

  /* #10 Fetch the current Hook flag state. */
  currentThread = Os_CoreGetThread();
  localCore = Os_ThreadGetCore(currentThread);                                                                          /* SBSW_OS_HK_THREADGETCORE_001 */
  activeHooks = Os_CoreGetHookInfo(localCore);                                                                          /* SBSW_OS_HK_COREGETHOOKINFO_001 */

  /* #20 If the current hook may not be nested into: */
  if(Os_HookIsNestingAllowed(activeHooks, Hook) == 0u)                                                                  /* SBSW_OS_HK_HOOKISNESTINGALLOWED_001 */
  {
    /* #30 Kernel Panic. */
    Os_ErrKernelPanic();
  }

  /* - #40 Update current hook flag state. */
  Os_HookGetDyn(Hook)->HookTypeFlag = activeHooks->InHookFlags;                                                         /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_HK_HOOKGETDYN_002 */
  activeHooks->InHookFlags |= Hook->HookTypeFlag;                                                                       /* SBSW_OS_HK_COREGETHOOKINFO_002 */

  /* - #50 Back up and reset the current interrupt state. */
  intApiStateRef = Os_ThreadGetInterruptApiState(currentThread);                                                        /* SBSW_OS_HK_THREADGETINTERRUPTAPISTATE_001 */
  Os_InterruptCopy(intApiStateRef, &intApiStateCopy);                                                                   /* SBSW_OS_HK_INTERRUPTCOPY_001 */

  Os_InterruptInit(intApiStateRef);                                                                                     /* SBSW_OS_HK_INTERRUPTINIT_001 */

  /* - #60 Push the interrupted thread on the interrupted thread stack. */
  Os_CoreInterruptedThreadsPush(localCore, currentThread);                                                              /* SBSW_OS_HK_COREINTERRUPTEDTHREADSPUSH_001 */

  /* - #70 Start hook thread. */
  Os_ThreadSuspendAndStart(currentThread, &(Hook->Thread), FALSE);                                                      /* SBSW_OS_HK_THREADSUSPENDANDSTART_001 */

  /* - #80 Restore the previous interrupt state. */
  Os_InterruptCopy(&intApiStateCopy, intApiStateRef);                                                                   /* SBSW_OS_HK_INTERRUPTCOPY_001 */

}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_HookInfoInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, OS_CODE) Os_HookInfoInit
(
  P2VAR(Os_HookInfoType, AUTOMATIC, OS_VAR_NOINIT) HookInfo
)
{
  /* #10 Set InHooksFlags to no active hook. */
  HookInfo->InHookFlags = 0;                                                                                            /* SBSW_OS_PWA_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_HookInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_HookInit
(
  P2CONST(Os_HookConfigType, AUTOMATIC, OS_CONST) Hook
)
{
  /* #10 If the given hook reference is not NULL and not an InitHook: */
  if( (Hook != NULL_PTR) && (Hook->HookTypeFlag != OS_HOOKFLAG_INITHOOK) )
  {
    /* #20 Initialize threads kernel data. */
    Os_ThreadInit(&Hook->Thread);                                                                                       /* SBSW_OS_FC_PRECONDITION_AND_CHECK */
  }
}


/***********************************************************************************************************************
 *  Os_HookCallStatusHook()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_HookCallStatusHook
(
  P2CONST(Os_HookStatusHookConfigType, AUTOMATIC, OS_CONST) Hook,
  StatusType Error
)
{
  /* #10 If no StatusHooks are configured: KernelPanic. */
  if(Os_HookIsStatusHookEnabled() == 0u)                                                                                /* COV_OS_INVSTATE */ /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    Os_ErrKernelPanic();                                                                                                /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }
  /* #20 Otherwise: */
  else
  {
    /* #30 If the given hook reference is not NULL: */
    if(Hook != NULL_PTR)
    {
      /* #40 Bypass error parameter.                 */
      Os_HookGetDyn(&(Hook->Hook))->Parameter.Status = Error;                                                           /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_HK_HOOKGETDYN_002 */

      /* #50 Use general "hook call" implementation. */
      Os_HookCall(&(Hook->Hook));                                                                                       /* SBSW_OS_FC_PRECONDITION */
    }
  }
}


/***********************************************************************************************************************
 *  Os_HookWrapperStatusHook()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_HookWrapperStatusHook
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
)
{
  /* #10 If no StatusHooks are configured: KernelPanic. */
  if(Os_HookIsStatusHookEnabled() == 0u)                                                                                /* COV_OS_INVSTATE */ /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    Os_ErrKernelPanic();                                                                                                /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }
  /* #20 Otherwise: */
  else
  {
    StatusType status;
    P2CONST(Os_HookConfigType, AUTOMATIC, OS_CONST) hook;

    hook = Os_HookThread2Hook(Thread);                                                                                  /* SBSW_OS_FC_PRECONDITION */

    /* #30 Get status parameter. */
    status = Os_HookGetDyn(hook)->Parameter.Status;                                                                     /* SBSW_OS_HK_HOOKGETDYN_002 */

    /* #40 Call hook callback function and pass status parameter. */
    Os_Hook2StatusHook(hook)->Callback(status);                                                                         /* SBSW_OS_HK_HOOK2STATUSHOOK_001 */ /* SBSW_OS_HK_STATUS_CALLBACK_001 */

    /* #50 Resume previous thread. */
    Os_TrapHookReturn();
  }
}


/***********************************************************************************************************************
 *  Os_HookCallOs_CoreInitHook()
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
FUNC(void, OS_CODE) Os_HookCallOs_CoreInitHook
(
  P2CONST(Os_HookInitHookConfigType, AUTOMATIC, OS_CONST) Hook,
  AppModeType Mode
)
{
  /* #10 If the given hook reference is NULL: */
  if(OS_UNLIKELY(Hook == NULL_PTR))                                                                                     /* COV_OS_INVSTATE */
  {
    /* #20 Kernel panic. */
    Os_ErrKernelPanic();
  }
  /* #30 Otherwise: */
  else
  {
    P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) hookThread;
    P2VAR(Os_HookType, AUTOMATIC, OS_VAR_NOINIT) hookDyn;

    hookDyn = Os_HookGetDyn(&(Hook->Hook));                                                                             /* SBSW_OS_FC_PRECONDITION */
    hookThread = Os_HookGetThread(&(Hook->Hook));                                                                       /* SBSW_OS_FC_PRECONDITION */

    /* #40 Initialize the hook thread. */
    Os_ThreadInit(hookThread);                                                                                          /* SBSW_OS_HK_THREADINIT_001 */

    /* #50 Set previous "InHookFlags" state to "no hooks". */
    /* This value will be restored in Hook return path. */
    hookDyn->HookTypeFlag = OS_HOOKFLAG_NOHOOKS;                                                                        /* SBSW_OS_HK_HOOKGETDYN_002 */

    /* #60 Bypass mode parameter.                 */
    hookDyn->Parameter.Mode = Mode;                                                                                     /* SBSW_OS_HK_HOOKGETDYN_002 */

    /* #70 Start hook thread. */
    Os_ThreadStartFirst(hookThread, FALSE);                                                                             /* SBSW_OS_HK_THREADSTARTFIRST_001 */
  }
}


/***********************************************************************************************************************
 *  Os_HookWrapperOs_CoreInitHook()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_HookWrapperOs_CoreInitHook
(
  void
)
{
  AppModeType mode;
  P2CONST(Os_HookConfigType, AUTOMATIC, OS_CONST) hook;

  hook = Os_HookThread2Hook(Os_CoreGetThread());                                                                        /* SBSW_OS_HK_HOOKTHREAD2HOOK_001 */

  /* #10 Get mode parameter. */
  mode = Os_HookGetDyn(hook)->Parameter.Mode;                                                                           /* SBSW_OS_HK_HOOKGETDYN_001 */

  /* #20 Call hook callback function and pass mode parameter. */
  Os_Hook2InitHook(hook)->Callback(mode);                                                                               /* SBSW_OS_HK_HOOK2INITHOOK_001 */ /* SBSW_OS_HK_INITHOOK_CALLBACK_001 */

  /* #30 Resume previous thread. */
  Os_TrapHookReturn();
}


/***********************************************************************************************************************
 *  Os_HookWrapperProtectionHook()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_HookWrapperProtectionHook
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
)
{
  /* #10 If ProtectionHook is not enabled: KernelPanic. */
  if(Os_HookIsProtectionHookEnabled() == 0u)                                                                            /* COV_OS_INVSTATE */ /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    Os_ErrKernelPanic();                                                                                                /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }
  /* #20 Otherwise: */
  else
  {
    StatusType status;
    ProtectionReturnType protectionReaction;
    P2CONST(Os_HookConfigType, AUTOMATIC, OS_CONST) hook;
    P2VAR(Os_HookType, AUTOMATIC, OS_VAR_NOINIT) hookDyn;
    P2CONST(Os_HookProtectionHookConfigType, AUTOMATIC, OS_CONST) protectionHook;

    hook = Os_HookThread2Hook(Thread);                                                                                  /* SBSW_OS_FC_PRECONDITION */
    hookDyn = Os_HookGetDyn(hook);                                                                                      /* SBSW_OS_HK_HOOKGETDYN_001 */
    protectionHook = Os_Hook2ProtectionHook(hook);                                                                      /* SBSW_OS_HK_HOOK2PROTECTIONHOOK_001 */
    status = hookDyn->Parameter.Status;

    /* #30 Call hook callback function and pass status parameter. */
    protectionReaction = protectionHook->Callback(status);                                                              /* SBSW_OS_HK_PROTECTIONHOOK_CALLBACK_001 */

    /* #40 Store return value. */
    /*! Internal comment removed.
 *
 * */
    hookDyn->ReturnValue.ProtectionReaction = protectionReaction;                                                       /* SBSW_OS_HK_HOOKGETDYN_002 */

    /* #50 Resume previous thread and pass protection reaction. */
    Os_HookReturn();
  }
}


/***********************************************************************************************************************
 *  Os_HookCallProtectionHook()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(ProtectionReturnType, OS_CODE) Os_HookCallProtectionHook
(
  P2CONST(Os_HookProtectionHookConfigType, AUTOMATIC, OS_CONST) Hook,
  StatusType Fatalerror
)
{
  ProtectionReturnType protectionReaction;

  /* #10 If the ProtectionHook is enabled, and the given hook reference is not NULL: */
  if (Os_HookIsProtectionHookEnabled() != 0u)                                                                           /* PRQA S 2991, 2995 */ /* MD_Os_Rule14.3_2991, MD_Os_Rule2.2_2995 */ /* COV_OS_INVSTATE */
  {
    if(Hook != NULL_PTR)                                                                                                /* COV_OS_INVSTATE */
    {
      /* #20 Bypass error parameter.                 */
      Os_HookGetDyn(&(Hook->Hook))->Parameter.Status = Fatalerror;                                                      /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_HK_HOOKGETDYN_002 */

      /* #30 Use general "hook call" implementation. */
      Os_HookCall(&(Hook->Hook));                                                                                       /* SBSW_OS_FC_PRECONDITION */

      /* #40 Fetch bypassed protection reaction. */
      protectionReaction = Os_HookGetDyn(&(Hook->Hook))->ReturnValue.ProtectionReaction;                                /* SBSW_OS_FC_PRECONDITION */
    }
    /* #50 If there is no protection hook return PRO_SHUTDOWN. */
    else
    {
      protectionReaction = PRO_SHUTDOWN;
    }
  }
  else
  {
    protectionReaction = PRO_SHUTDOWN;                                                                                  /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }

  return protectionReaction;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_HookCallCallback()
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
FUNC(Os_StatusType, OS_CODE) Os_HookCallCallback
(
  P2CONST(Os_HookCallbackConfigType, AUTOMATIC, OS_CONST) Hook
)
{
  Os_StatusType status;

  /* #10 If Callbacks are enabled, and the given hook reference is not NULL: */
  if(Os_HookIsCallbackEnabled() != 0u)                                                                                  /* PRQA S 2991, 2995 */ /* MD_Os_Rule14.3_2991, MD_Os_Rule2.2_2995 */
  {
    if(Hook != NULL_PTR)
    {
      P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) targetThread;
      P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) targetCore;

      targetThread = Os_HookCallbackGetThread(Hook);                                                                    /* SBSW_OS_FC_PRECONDITION */
      targetCore = Os_ThreadGetCore(targetThread);                                                                      /* SBSW_OS_HK_THREADGETCORE_002 */

      /* #20 If Hook is assigned to local core: */
      if(Os_CoreAsrIsCoreLocal(targetCore) != 0u)                                                                       /* SBSW_OS_HK_COREASRISCORELOCAL_001 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
      {
        Os_IntStateType interruptState;

        /* #30 Disable interrupts. */
        Os_IntSuspend(&interruptState);                                                                                 /* SBSW_OS_PWA_LOCAL */

        /* #40 Call local callback. */
        status = Os_HookCallCallbackLocal(Hook);                                                                        /* SBSW_OS_FC_PRECONDITION */

        /* #50 Resume interrupts. */
        Os_IntResume(&interruptState);                                                                                  /* SBSW_OS_PWA_LOCAL */
      }
      /* #60 Otherwise: */
      else
      {
        P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

        currentThread = Os_CoreGetThread();

        /* #70 Send XSignal call. */
        status = Os_XSigSend_HookCallCallbackAsync(targetCore, currentThread, Hook->Hook.Id);                           /* SBSW_OS_HK_XSIGSEND_001 */
      }
    }
    /* #80 Otherwise: Return OS_STATUS_OK. */
    else
    {
      status = OS_STATUS_OK;
    }
  }
  else
  {
    status = OS_STATUS_OK;                                                                                              /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }

  return status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_HookCallCallbackLocal()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_HookCallCallbackLocal
(
  P2CONST(Os_HookCallbackConfigType, AUTOMATIC, OS_CONST) Hook
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) hookThread;

  /* #10 If Callbacks are not enabled: KernelPanic. */
  if(Os_HookIsCallbackEnabled() == 0u)                                                                                  /* COV_OS_INVSTATE */ /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    Os_ErrKernelPanic();                                                                                                /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }

  hookThread = Os_HookCallbackGetThread(Hook);                                                                          /* SBSW_OS_FC_PRECONDITION */

  /* #30 Check that application of given hook is accessible. */
  if(OS_UNLIKELY(Os_AppCheckIsAccessible(Os_ThreadGetOwnerApplication(hookThread)) == OS_CHECK_FAILED))                 /* SBSW_OS_HK_APPCHECKISACCESSIBLE_001 */ /* SBSW_OS_HK_THREADGETOWNERAPPLICATION_001 */
  {
    status = OS_STATUS_NOTACCESSIBLE_1;
  }
  else
  {
    /* #40 Use general "hook call" implementation. */
    Os_HookCall(&(Hook->Hook));                                                                                         /* SBSW_OS_FC_PRECONDITION */

    status = OS_STATUS_OK;
  }

  return status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_HookWrapperCallback()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_HookWrapperCallback
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
)
{
  /* #10 If Callbacks are not enabled: KernelPanic. */
  if(Os_HookIsCallbackEnabled() == 0u)                                                                                  /* COV_OS_INVSTATE */ /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    Os_ErrKernelPanic();                                                                                                /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }
  /* #20 Otherwise: */
  else
  {
    P2CONST(Os_HookConfigType, AUTOMATIC, OS_CONST) hook;

    hook = Os_HookThread2Hook(Thread);                                                                                  /* SBSW_OS_FC_PRECONDITION */

    /* #30 Call hook callback function. */
    Os_Hook2CallbackHook(hook)->Callback();                                                                             /* SBSW_OS_HK_HOOK2CALLBACKHOOK_001 */ /* SBSW_OS_HK_CALLBACK_CALLBACK_001 */

    /* #40 Resume previous thread. */
    Os_TrapHookReturn();
  }
}


/***********************************************************************************************************************
 *  Os_HookKill()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_HookKill
(
  P2CONST(Os_HookConfigType, AUTOMATIC, OS_CONST) Hook
)
{
  /* #10 If killing is not enabled: KernelPanic */
  if(Os_ErrIsKillingEnabled() == 0u)                                                                                    /* COV_OS_INVSTATE */
  {
    Os_ErrKernelPanic();
  }

  /* #20 Kill hook's thread. */
  if(Hook != NULL_PTR)
  {
    Os_ThreadKill(&(Hook->Thread));                                                                                     /* SBSW_OS_FC_PRECONDITION_AND_CHECK */
  }
}


/***********************************************************************************************************************
 *  Os_HookCallPanicHook()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, OS_CODE) Os_HookCallPanicHook(void)
{
  /* #10 If Panic Hook enabled, call Panic Hook. */
  /*! Internal comment removed.
 *
 *
 * */
  if(Os_HookIsPanicHookEnabled() != 0u)                                                                                 /* PRQA S 2991, 2995 */ /* MD_Os_Rule14.3_2991, MD_Os_Rule2.2_2995 */
  {
    OS_PANICHOOK();
  }
}


/***********************************************************************************************************************
 *  Os_HookIsPanicHookEnabled()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_HookIsPanicHookEnabled,
( void ))
{
  return (Os_StdReturnType)(OS_CFG_PANICHOOK == STD_ON);                                                                /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_Hook2StatusHook()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2CONST(Os_HookStatusHookConfigType, AUTOMATIC, OS_CONST), OS_CODE,        /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_Hook2StatusHook,
(
  P2CONST(Os_HookConfigType, AUTOMATIC, OS_CONST) Hook
))
{
  return  (P2CONST(Os_HookStatusHookConfigType, AUTOMATIC, OS_CONST))(Hook);                                            /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  Os_Hook2ProtectionHook()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2CONST(Os_HookProtectionHookConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_Hook2ProtectionHook,
(
  P2CONST(Os_HookConfigType, AUTOMATIC, OS_CONST) Hook
))
{
  return  (P2CONST(Os_HookProtectionHookConfigType, AUTOMATIC, OS_CONST))(Hook);                                        /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  Os_Hook2InitHook()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2CONST(Os_HookInitHookConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_Hook2InitHook,
(
  P2CONST(Os_HookConfigType, AUTOMATIC, OS_CONST) Hook
))
{
  return  (P2CONST(Os_HookInitHookConfigType, AUTOMATIC, OS_CONST))(Hook);                                              /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  Os_HookGetDyn()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2VAR(Os_HookType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE, OS_ALWAYS_INLINE,
Os_HookGetDyn,
(
  P2CONST(Os_HookConfigType, AUTOMATIC, OS_CONST) Hook
))
{
  return (P2VAR(Os_HookType, AUTOMATIC, OS_VAR_NOINIT))Hook->Thread.Dyn;                                                /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* module specific MISRA deviations:
 */

/* SBSW_JUSTIFICATION_BEGIN

\ID SBSW_OS_HK_HOOKISNESTINGALLOWED_001
 \DESCRIPTION    Os_HookIsNestingAllowed is called with the return value of Os_CoreGetHookInfo and an argument passed
                 to the caller. Correctness of caller argument is ensured by precondition.
 \COUNTERMEASURE \N [CM_OS_COREASR_HOOKINFO_N]

\ID SBSW_OS_HK_HOOKTHREAD2HOOK_001
 \DESCRIPTION    Os_HookThread2Hook is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_HK_HOOK2STATUSHOOK_001
 \DESCRIPTION    Os_Hook2StatusHook is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \M [CM_OS_HOOK2STATUSHOOK_M]

\ID SBSW_OS_HK_HOOK2PROTECTIONHOOK_001
 \DESCRIPTION    Os_Hook2ProtectionHook is called with the return value of Os_HookThread2Hook.
 \COUNTERMEASURE \M [CM_OS_HOOKTHREAD2HOOK_M]

\ID SBSW_OS_HK_HOOK2INITHOOK_001
 \DESCRIPTION    Os_Hook2InitHook is called with the return value of Os_HookThread2Hook.
 \COUNTERMEASURE \M [CM_OS_HOOKTHREAD2HOOK_M]

\ID SBSW_OS_HK_HOOK2CALLBACKHOOK_001
 \DESCRIPTION    Os_Hook2CallbackHook is called with the return value of Os_HookThread2Hook.
 \COUNTERMEASURE \M [CM_OS_HOOKTHREAD2HOOK_M]

\ID SBSW_OS_HK_HOOKGETDYN_001
 \DESCRIPTION    Os_HookGetDyn is called with a value derived from the return value of
                 Os_HookThread2Hook.
 \COUNTERMEASURE \M [CM_OS_HOOKTHREAD2HOOK_M]

\ID SBSW_OS_HK_HOOKGETDYN_002
 \DESCRIPTION    Write access to the return value of Os_HookGetDyn.
 \COUNTERMEASURE \M [CM_OS_HOOKGETDYN_M]

\ID SBSW_OS_HK_HOOKPROTECTIONHOOKGETDYN_001
 \DESCRIPTION    Os_HookProtectionHookGetDyn is called with a value derived from the return value of
                 Os_HookThread2ProtectionHook.
 \COUNTERMEASURE \M [CM_OS_HOOKTHREAD2PROTECTIONHOOK_M]

\ID SBSW_OS_HK_HOOKERRORHOOKGETDYN_002
 \DESCRIPTION    Os_HookErrorHookGetDyn is called with a value passed as argument to the caller.
 \COUNTERMEASURE \N Correctness of argument is ensured by precondition.

\ID SBSW_OS_HK_COREINTERRUPTEDTHREADSPOP_001
 \DESCRIPTION    Os_CoreInterruptedThreadsPop is called with the return value of Os_ThreadGetCore.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_HK_COREINTERRUPTEDTHREADSPUSH_001
 \DESCRIPTION    Os_CoreInterruptedThreadsPush is called with the return values of Os_ThreadGetCore and
                 Os_CoreGetThread. Correctness of Os_CoreGetThread is ensured by preconditions.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_HK_THREADISTASK_001
 \DESCRIPTION    Os_ThreadIsTask is called with the return value of Os_CoreInterruptedThreadsPop.
 \COUNTERMEASURE \T [CM_OS_COREINTERRUPTEDTHREADSPOP_T]

\ID SBSW_OS_HK_THREADISHOOK_001
 \DESCRIPTION    Os_ThreadIsHook is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_HK_THREADSUSPENDANDSTART_001
 \DESCRIPTION    Os_ThreadSuspendAndStart is called with the return value of Os_CoreGetThread and caller argument.
                 Correctness of Os_CoreGetThread is ensured by preconditions.
 \COUNTERMEASURE \N [CM_OS_PRECONDITION_AND_CHECK_N]

\ID SBSW_OS_HK_TASKTHREAD2TASK_001
 \DESCRIPTION    Os_TaskThread2Task is called with the return value of Os_CoreInterruptedThreadsPop.
 \COUNTERMEASURE \T [CM_OS_COREINTERRUPTEDTHREADSPOP_T]

\ID SBSW_OS_HK_TASKRETURNTOTASKLEVEL_001
 \DESCRIPTION    Os_TaskReturnToTaskLevel is called with the return value of Os_TaskThread2Task.
 \COUNTERMEASURE \R [CM_OS_TASKTHREAD2TASK_R]

\ID SBSW_OS_HK_THREADGETCORE_001
 \DESCRIPTION    Os_ThreadGetCore is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_HK_THREADGETCORE_002
 \DESCRIPTION    Os_ThreadGetCore is called with the return value of Os_HookCallbackGetThread.
 \COUNTERMEASURE \N [CM_OS_HOOKCALLBACKGETTHREAD_N]

\ID SBSW_OS_HK_THREADCLEANUPANDRESUME_001
 \DESCRIPTION    Os_ThreadCleanupAndResume is called with the return value of Os_CoreInterruptedThreadsPop.
 \COUNTERMEASURE \T [CM_OS_COREINTERRUPTEDTHREADSPOP_T]

\ID SBSW_OS_HK_THREADGETINTERRUPTAPISTATE_001
 \DESCRIPTION    Os_ThreadGetInterruptApiState is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_HK_INTERRUPTCOPY_001
 \DESCRIPTION    Os_InterruptCopy is called with the return value of Os_ThreadGetInterruptApiState and a pointer to
                 a local variable.
 \COUNTERMEASURE \M [CM_OS_THREADGETINTERRUPTAPISTATE_M]

\ID SBSW_OS_HK_INTERRUPTINIT_001
 \DESCRIPTION    Os_InterruptInit is called with the return value of Os_ThreadGetInterruptApiState.
 \COUNTERMEASURE \M [CM_OS_THREADGETINTERRUPTAPISTATE_M]

\ID SBSW_OS_HK_STATUS_CALLBACK_001
 \DESCRIPTION    Function pointer is called, derived form the return value of ?????????.
 \COUNTERMEASURE \M [CM_OS_HOOK_STATUS_CALLBACK_M]

\ID SBSW_OS_HK_PROTECTIONHOOK_CALLBACK_001
 \DESCRIPTION    Function pointer is called, derived form the return value of Os_Hook2ProtectionHook.
 \COUNTERMEASURE \M [CM_OS_HOOK_PROTECTIONHOOK_CALLBACK_M]
                 \M [CM_OS_HOOK2PROTECTIONHOOK_M]

\ID SBSW_OS_HK_CALLBACK_CALLBACK_001
 \DESCRIPTION    Function pointer is called, derived form an argument passed to the caller.
                 Correctness of caller argument is ensured by precondition.
 \COUNTERMEASURE \M [CM_OS_HOOK_CALLBACK_CALLBACK_M]

\ID SBSW_OS_HK_INITHOOK_CALLBACK_001
 \DESCRIPTION    Function pointer is called, derived form the return value of Os_Hook2InitHook.
 \COUNTERMEASURE \M [CM_OS_HOOK_INITHOOK_CALLBACK_M]

\ID SBSW_OS_HK_THREADGETINITIALTYPE_001
 \DESCRIPTION    Os_ThreadGetInitialType is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_HK_COREGETHOOKINFO_001
 \DESCRIPTION    Os_CoreGetHookInfo is called with the return value of Os_ThreadGetCore.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_HK_COREGETHOOKINFO_002
 \DESCRIPTION    Write access to the return value of Os_CoreGetHookInfo.
 \COUNTERMEASURE \N [CM_OS_COREASR_HOOKINFO_N]

\ID SBSW_OS_HK_XSIGSEND_001
 \DESCRIPTION    A cross core send function is called, with the return values of Os_ThreadGetCore() and
                 Os_CoreGetThread(). Correctness of Os_CoreGetThread() is ensured by preconditions.
                 The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_HK_THREADGETOWNERAPPLICATION_001
 \DESCRIPTION    Os_ThreadGetOwnerApplication is called with the return value of Os_HookCallbackGetThread.
 \COUNTERMEASURE \N CM_OS_HOOKCALLBACKGETTHREAD_N

\ID SBSW_OS_HK_APPCHECKISACCESSIBLE_001
 \DESCRIPTION    Os_AppCheckIsAccessible is called with the return value of Os_ThreadGetOwnerApplication.
 \COUNTERMEASURE \M [CM_OS_THREADGETOWNERAPPLICATION_M]

\ID SBSW_OS_HK_THREADINIT_001
 \DESCRIPTION    Os_ThreadInit is called with the return value of Os_HookGetThread.
 \COUNTERMEASURE \N [CM_OS_HOOKINITHOOKGETTHREAD_N]

\ID SBSW_OS_HK_THREADSTARTFIRST_001
 \DESCRIPTION    Os_ThreadStartFirst is called with the return value of Os_HookGetThread.
 \COUNTERMEASURE \N [CM_OS_HOOKINITHOOKGETTHREAD_N]

\ID SBSW_OS_HK_CORECRITICALUSERSECTIONISACTIVE_001
 \DESCRIPTION    Os_CoreCriticalUserSectionIsActive is called with the return value of Os_ThreadGetCore.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_HK_COREASRISCORELOCAL_001
 \DESCRIPTION    Os_CoreAsrIsCoreLocal is called with the return value of Os_ThreadGetCore.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

SBSW_JUSTIFICATION_END */



/*
\CM CM_HOOKTHREAD2HOOK_N
      Precondition ensures that the pointer is valid. The compliance of the precondition is check during review.

\CM CM_OS_HOOKSHUTDOWNHOOKGETTHREAD_N
      Precondition ensures that the pointer is valid. The compliance of the precondition is check during review.

\CM CM_OS_HOOKSTATUSHOOKGETTHREAD_N
      Precondition ensures that the pointer is valid. The compliance of the precondition is check during review.

\CM CM_OS_HOOKPROTECTIONHOOKGETTHREAD_N
      Precondition ensures that the pointer is valid. The compliance of the precondition is check during review.

\CM CM_OS_HOOKGETDYN_M
      Verify that the Hook Dyn pointer of each Os_HookConfigType object is initialized with a
      dynamic hook object.

\CM CM_OS_HOOKTHREAD2PROTECTIONHOOK_M
      Verify that the thread context of each ProtectionHook refers to Os_HookWrapperProtectionHook and that there is
      no other reference to Os_HookWrapperProtectionHook from other objects.

\CM CM_OS_HOOKTHREAD2HOOK_M
      Verify that the thread context of each Hook refers to Os_TrapHookReturn and that there is
      no other reference to Os_TrapHookReturn.

\CM CM_OS_HOOK2STATUSHOOK_M
      Verify that the thread context of each StatusHook refers to Os_HookWrapperStatusHook and that there is
      no other reference to Os_HookWrapperStatusHook from other objects.

\CM CM_OS_HOOK2PROTECTIONHOOK_M
      [CM_OS_HOOKTHREAD2PROTECTIONHOOK_M]

\CM CM_OS_HOOK2CALLBACKHOOK_PRE_N
      Precondition ensures that returned pointer is valid.

\CM CM_OS_HOOK_STATUS_CALLBACK_M
      Verify that the callback pointer of each Os_HookStatusHookConfigType object is initialized with a valid function
      pointer.

\CM CM_OS_HOOK_PROTECTIONHOOK_CALLBACK_M
      Verify that the callback pointer of each Os_HookProtectionHookConfigType object is a non NULL_PTR.

\CM CM_OS_HOOK_CALLBACK_CALLBACK_M
      Verify that the callback pointer of each Os_HookCallbackType object is a non NULL_PTR.

\CM CM_OS_HOOK_INITHOOK_CALLBACK_M
      Verify that the callback pointer of each Os_HookInitHookConfigType object is a non NULL_PTR.

\CM CM_OS_HOOKCALLBACKGETTHREAD_N
      Precondition ensures that the pointer is valid. The compliance of the precondition is check during review.

\CM CM_OS_HOOKINITHOOKGETTHREAD_N
      Precondition ensures that the pointer is valid. The compliance of the precondition is check during review.

\CM CM_OS_HOOKID2HOOK_M
      Verify that:
        1. each entry in OsCfg_HookRefs except the last is no NULL_PTR and
        2. the size of OsCfg_HookRefs is equal to OS_CFG_NUM_HOOKS + 1 


*/

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hook.c
 **********************************************************************************************************************/

