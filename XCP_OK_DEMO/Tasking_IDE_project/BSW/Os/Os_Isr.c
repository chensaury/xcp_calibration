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
 * \addtogroup Os_Isr
 * \{
 *
 * \file
 * \brief       ISR management implementation.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777, 0779, 0828  EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */


#define OS_ISR_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Isr_Types.h"
#include "Os_Isr_Lcfg.h"
#include "Os_Isr.h"

/* Os kernel module dependencies */
#include "Os_Lcfg.h"
#include "Os_Thread.h"
#include "Os_Task.h"
#include "Os_Trace.h"
#include "Os_Error.h"
#include "Os_Core.h"

/* Os hal dependencies */
#include "Os_Hal_Core.h"
#include "Os_Hal_MemoryProtection.h"


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
 *  Os_IsrCat2IsrsConfigured()
 **********************************************************************************************************************/
/*! \brief          Returns whether any ISRs are configured (!0) or not (0).
 *  \details        --no details--
 *
 *  \retval         !0  ISRs are configured.
 *  \retval         0   no ISRs are configured.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_IsrCat2IsrsConfigured,
(
  void
));


/***********************************************************************************************************************
 *  Os_IsrGetDyn()
 **********************************************************************************************************************/
/*! \brief          Returns the dynamic data of an ISR.
 *  \details        --no details--
 *
 *  \param[in]      Isr         ISR to query. Parameter must not be NULL.
 *
 *  \return         Pointer to the ISR's dynamic data.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2VAR(Os_IsrType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE, OS_ALWAYS_INLINE,
Os_IsrGetDyn,
(
  P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) Isr
));


/***********************************************************************************************************************
 *  Os_IsrCheckClearPendingSupported()
 **********************************************************************************************************************/
/*! \brief          Returns whether the hardware supports clearing of pending interrupts (Not OS_CHECK_FAILED) or not
 *                  (OS_CHECK_FAILED).
 *  \details        In case that extended checks are disabled, the default result of \ref Os_ErrExtendedCheck() is
 *                  returned.
 *
 *  \param[in]      ClearPendingRequested -TRUE:  Clearing of pending interrupts has been requested.
 *                                        -FALSE: Clearing of pending interrupts has not been requested.
 *
 *  \retval         Not OS_CHECK_FAILED   If the hardware supports clearing of pending interrupts.
 *  \retval         OS_CHECK_FAILED       If the hardware does not support clearing of pending interrupts.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_IsrCheckClearPendingSupported,
(
  boolean ClearPendingRequested
));


/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_IsrCat2IsrsConfigured()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_IsrCat2IsrsConfigured,
(
  void
))
{
  return (Os_StdReturnType)((uint32)OS_ISRID_COUNT > 0u);                                                               /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_IsrGetDyn()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE P2VAR(Os_IsrType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE, OS_ALWAYS_INLINE, Os_IsrGetDyn,
(
  P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) Isr
))
{
  return (P2VAR(Os_IsrType, AUTOMATIC, OS_VAR_NOINIT)) (Os_IsrGetThread(Isr)->Dyn);                                     /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */ /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_IsrCheckClearPendingSupported()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_IsrCheckClearPendingSupported,
(
  boolean ClearPendingRequested
))
{
  return Os_ErrExtendedCheck((Os_StdReturnType)((Os_Hal_IntIsClearPendingSupported() != 0u    ) ||                      /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
                                                (ClearPendingRequested               == FALSE)    ));                   /* COV_OS_HALPLATFORMCLEARPENDINGAVAILABILITY */
}


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_IsrInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_IsrInit
(
  P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) Isr
)
{
  Os_Assert(Os_ErrIsValueLo((uint32)Isr->Id, (uint32)OS_ISRID_COUNT));

  /* #10 Initialize thread. */
  Os_ThreadInit(Os_IsrGetThread(Isr));                                                                                  /* SBSW_OS_ISR_THREADINIT_001 */ /* SBSW_OS_FC_PRECONDITION */

  /* #20 Set killed flag to false. */
  Os_IsrGetDyn(Isr)->IsKilled = FALSE;                                                                                  /* SBSW_OS_ISR_ISRGETDYN_002 */ /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_IsrRun()
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
 */
FUNC(void, OS_CODE) Os_IsrRun
(
  P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) Isr
)
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) interruptedThread;
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) core;
  P2CONST(Os_TpConfigType, TYPEDEF, OS_CONST) timingProtection;
  Os_IntStateType interruptState;

  interruptedThread = Os_CoreGetThread();
  core = Os_ThreadGetCore(&Isr->Thread);                                                                                /* SBSW_OS_FC_PRECONDITION */
  timingProtection = Os_CoreAsrGetTimingProtection(core);                                                               /* SBSW_OS_ISR_COREASRGETTIMINGPROTECTION_001 */

  /* #10 Suspend interrupts. */
  Os_IntSuspend(&interruptState);                                                                                       /* SBSW_OS_FC_POINTER2LOCAL */

  /* #15 Enable global interrupt flag if suspended to level previously. */
  if(Os_InterruptLockOnLevelIsNeeded() != 0u)                                                                           /* COV_OS_HALPLATFORMLEVELSUPPORT */
  {
    if(Os_IntIsGlobal2LevelSwitchSupported() != 0u)                                                                     /* COV_OS_HALPLATFORMGLOBAL2LEVELSUPPORTED */
    {
      Os_IntEnableGlobal();
    }
  }

  /* #20 If inter-arrival time is okay: */
  if(OS_LIKELY(Os_TpCheckInterArrival(timingProtection, Os_ThreadGetTpConfig(&Isr->Thread)) != OS_CHECK_FAILED))        /* SBSW_OS_ISR_TPCHECKINTERARRIVAL_001 */ /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_HALPLATFORMTPUNSUPPORTED_TX */
  {
    /* #30 Push the interrupted thread on the interrupted thread stack. */
    Os_CoreInterruptedThreadsPush(core, interruptedThread);                                                             /* SBSW_OS_ISR_COREINTERRUPTEDTHREADSPUSH_001 */

    Os_TraceThreadSuspendAndStart(Os_ThreadGetTrace(interruptedThread), Os_ThreadGetTrace(&(Isr->Thread)));             /* SBSW_OS_ISR_TRACETHREADSUSPENDANDSTART_001 */ /* SBSW_OS_ISR_THREADGETTRACE_001 */ /* SBSW_OS_FC_PRECONDITION */

    /* #40 Suspend the current thread and start the ISR's thread. */
    Os_ThreadSuspendAndStart(interruptedThread, &Isr->Thread, FALSE);                                                   /* SBSW_OS_ISR_THREADSUSPENDANDSTART_001 */

    /* Do not add code after Os_ThreadSuspendAndStart!
     * Consider: The interrupted thread may be a task, which gets terminated, so Os_ThreadSuspendAndStart()
     *           may never return. */
  }
  /* #50 Otherwise: */
  else
  {
    /* #60 Signal hardware the end of interrupt. */
    Os_Hal_IntEndOfInterrupt(Isr->HwConfig);                                                                            /* SBSW_OS_ISR_HAL_INTENDOFINTERRUPT_001 */
  }

  /* #65 Disable global interrupt flag if suspended to level previously. */
  if(Os_InterruptLockOnLevelIsNeeded() != 0u)                                                                           /* COV_OS_HALPLATFORMLEVELSUPPORT */
  {
    if(Os_IntIsGlobal2LevelSwitchSupported() != 0u)                                                                     /* COV_OS_HALPLATFORMGLOBAL2LEVELSUPPORTED */
    {
      Os_IntDisableGlobal();
    }
  }

  /* #70 Resume interrupts. */
  Os_IntResume(&interruptState);                                                                                        /* SBSW_OS_FC_POINTER2LOCAL */
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_IsrEpilogue()
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
OS_FUNC_ATTRIBUTE_DEFINITION(void, OS_CODE, OS_NORETURN, Os_IsrEpilogue, (void))
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) isrThread;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) interruptedThread;
  P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) isr;
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) core;

  isrThread = Os_CoreGetThread();
  isr = Os_IsrThread2Isr(isrThread);                                                                                    /* SBSW_OS_ISR_ISRTHREAD2ISR_001 */
  core = Os_ThreadGetCore(isrThread);                                                                                   /* SBSW_OS_ISR_THREADGETCORE_001 */

  /* #10 Disable interrupts. */
  Os_IntDisable();

  /* #20 If the ISR has been killed (locks have already been released) (unlikely): */
  if(OS_UNLIKELY(Os_IsrGetDyn(isr)->IsKilled == TRUE))                                                                  /* SBSW_OS_ISR_ISRGETDYN_001 */
  {
    /* #30 Reset killed flag. */
    Os_IsrGetDyn(isr)->IsKilled = FALSE;                                                                                /* SBSW_OS_ISR_ISRGETDYN_001 */ /* SBSW_OS_ISR_ISRGETDYN_002 */
  }
  /* #40 Otherwise, if the ISR holds any locks (unlikely): */
  else
  {
    /* #50 Release locks and report errors. */
    if(OS_UNLIKELY(Os_ThreadCheckResourcesReleased(isrThread) == OS_CHECK_FAILED))                                      /* SBSW_OS_ISR_THREADCHECKRESOURCESRELEASED_001 */
    {
      Os_ThreadResourceForceRelease(isrThread);                                                                         /* SBSW_OS_ISR_THREADRESOURCEFORCERELEASE_001 */
      Os_ErrReportIsrEpilogue(OS_STATUS_RESOURCE);
    }

    if(OS_UNLIKELY(Os_ThreadCheckSpinlocksReleased(isrThread) == OS_CHECK_FAILED))                                      /* SBSW_OS_ISR_THREADCHECKSPINLOCKSRELEASED_001 */ /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
    {
      Os_ThreadSpinlockForceRelease(isrThread);                                                                         /* SBSW_OS_ISR_THREADSPINLOCKFORCERELEASE_001 */
      Os_ErrReportIsrEpilogue(OS_STATUS_SPINLOCK);
    }

    if(OS_UNLIKELY(Os_ThreadCheckAreInterruptsEnabled(isrThread) == OS_CHECK_FAILED))                                   /* SBSW_OS_ISR_THREADCHECKAREINTERRUPTSENABLED_001 */
    {
      Os_InterruptCleanup(Os_ThreadGetInterruptApiState(isrThread));                                                    /* SBSW_OS_ISR_INTERRUPTCLEANUP_001 */ /* SBSW_OS_ISR_THREADGETINTERRUPTAPISTATE_001 */
      Os_ErrReportIsrEpilogue(OS_STATUS_DISABLEDINT);
    }
  }

  /* #60 Signal hardware the end of interrupt. */
  Os_Hal_IntEndOfInterrupt(isr->HwConfig);                                                                              /* SBSW_OS_ISR_HAL_INTENDOFINTERRUPT_002 */

  /* #70 Tell core, that we end processing an ISR now. */
  interruptedThread = Os_CoreInterruptedThreadsPop(core);                                                               /* SBSW_OS_ISR_COREINTERRUPTEDTHREADSPOP_001 */

  /* #80 If the interrupted thread is a task: */
  if(Os_ThreadIsTask(interruptedThread) != 0u)                                                                          /* SBSW_OS_ISR_THREADISTASK_001 */ /* COV_OS_HALPLATFORMISRNESTINGSUPPORT_TX */
  {
    /* #90 Resume the next task. */
    Os_TaskReturnToTaskLevel(Os_TaskThread2Task(interruptedThread));                                                    /* SBSW_OS_ISR_TASKRETURNTOTASKLEVEL_001 */ /* SBSW_OS_ISR_TASKTHREAD2TASK_001 */
  }
  /* #100 Otherwise: */
  else
  {
    Os_TraceThreadCleanupAndResume(Os_ThreadGetTrace(isrThread), Os_ThreadGetTrace(interruptedThread));                 /* SBSW_OS_ISR_TRACETHREADCLEANUPANDRESUME_001 */ /* SBSW_OS_ISR_THREADGETTRACE_001 */ /* SBSW_OS_ISR_THREADGETTRACE_002 */

    /* #110 Resume the interrupted ISR. */
    Os_ThreadCleanupAndResume(interruptedThread, FALSE);                                                                /* SBSW_OS_ISR_THREADCLEANUPANDRESUME_001 */
  }

  Os_ErrKernelPanic();
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_IsrEpilogueTp()
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(void, OS_CODE, OS_NORETURN, Os_IsrEpilogueTp, (void))                                      /* COV_OS_HALPLATFORMTPUNSUPPORTED_XX */
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) isrThread;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) interruptedThread;
  P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) isr;
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) core;

  /* #10 If TimingProtection is not enabled: KernelPanic. */
  if(Os_TpIsEnabled() == 0u)                                                                                           /*  COV_OS_INVSTATE*/
  {
    Os_ErrKernelPanic();
  }

  isrThread = Os_CoreGetThread();
  isr = Os_IsrThread2Isr(isrThread);                                                                                    /* SBSW_OS_ISR_ISRTHREAD2ISR_001 */
  core = Os_ThreadGetCore(isrThread);                                                                                   /* SBSW_OS_ISR_THREADGETCORE_001 */

  /* #15 Disable interrupts. */
  Os_IntDisable();

  /* #20 Handle killing case (considered unreachable) */
  if(OS_UNLIKELY(Os_IsrGetDyn(isr)->IsKilled == TRUE))                                                                  /* SBSW_OS_ISR_ISRGETDYN_001 */ /* COV_OS_INVSTATE */
  {
    /* As this is a TP ISR, which always belongs to the kernel application, and thus this ISR can not be killed. The
     * only valid reaction is shutdown. This case indicates an consistency error. */
    Os_ErrKernelPanic();
  }

  /* #30 Signal hardware the end of interrupt. */
  Os_Hal_IntEndOfInterrupt(isr->HwConfig);                                                                              /* SBSW_OS_ISR_HAL_INTENDOFINTERRUPT_002 */

  /* #40 Tell core, that we end processing a Tp_ISR now. */
  interruptedThread = Os_CoreInterruptedThreadsPop(core);                                                               /* SBSW_OS_ISR_COREINTERRUPTEDTHREADSPOP_001 */

  /* #50 If the interrupted thread is a task: */
  if(Os_ThreadIsTask(interruptedThread) != 0u)                                                                          /* SBSW_OS_ISR_THREADISTASK_001 */
  {
    /* #60 Resume the next task. */
    Os_TaskReturnToTaskLevel(Os_TaskThread2Task(interruptedThread));                                                    /* SBSW_OS_ISR_TASKRETURNTOTASKLEVEL_001 */ /* SBSW_OS_ISR_TASKTHREAD2TASK_001 */
  }
  /* #70 Otherwise: */
  else
  {
    Os_TraceThreadCleanupAndResume(Os_ThreadGetTrace(isrThread), Os_ThreadGetTrace(interruptedThread));                 /* SBSW_OS_ISR_TRACETHREADCLEANUPANDRESUME_001 */ /* SBSW_OS_ISR_THREADGETTRACE_001 */ /* SBSW_OS_ISR_THREADGETTRACE_002 */

    /* #80 Resume the interrupted ISR. */
    Os_ThreadCleanupAndResume(interruptedThread, FALSE);                                                                /* SBSW_OS_ISR_THREADCLEANUPANDRESUME_001 */
  }

  Os_ErrKernelPanic();
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_Api_GetISRID()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(ISRType, OS_CODE) Os_Api_GetISRID(void)
{
  ISRType isrId;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) core;

  isrId = INVALID_ISR;

  currentThread = Os_CoreGetThread();
  core = Os_ThreadGetCore(currentThread);                                                                               /* SBSW_OS_ISR_THREADGETCORE_001 */

  /* #10 Perform error checks. */
  if(OS_UNLIKELY(Os_ThreadCheckCallContext(currentThread, OS_APICONTEXT_GETISRID) == OS_CHECK_FAILED))                  /* SBSW_OS_ISR_THREADCHECKCALLCONTEXT_001 */
  {
    ;
  }
  else
  {
    P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) isrThread;

    /* #20 Find the first ISR in the list of interrupted threads (including current thread). */
    /* Precondition of Os_CoreThreadGetByContext requires that 'Concurrent access to given object is prevented by
     * caller.'. This is given, as any interrupting thread restores the previous state, before returning to the
     * current one. */
    isrThread = Os_CoreThreadGetByContext(core, OS_CALLCONTEXT_ISR2);                                                   /* SBSW_OS_ISR_CORETHREADGETBYCONTEXT_001 */

    /* #30 If an ISR has been found, return its ID. */
    if(isrThread != NULL_PTR)
    {
      isrId = Os_IsrThread2Isr(isrThread)->Id;                                                                          /* SBSW_OS_ISR_ISRTHREAD2ISR_002 */
    }
  }

  return isrId;
}                                                                                                                       /* PRQA S 6050, 6080 */ /* MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_Api_DisableInterruptSource()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_Api_DisableInterruptSource(ISRType ISRID)
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;
  Os_StatusType status;

  currentThread = Os_CoreGetThread();

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_IsrCheckId(ISRID) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_ID_1;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckCallContext(currentThread, OS_APICONTEXT_ISRDISABLESOURCE) == OS_CHECK_FAILED))     /* SBSW_OS_ISR_THREADCHECKCALLCONTEXT_001 */
  {
    status = OS_STATUS_CALLEVEL;
  }
  else
  {
    P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) isr;

    isr = Os_IsrId2Isr(ISRID);

    if(OS_UNLIKELY(Os_ThreadCheckIsCurrentApplication(                                                                  /* SBSW_OS_ISR_THREADCHECKISCURRENTAPPLICATION_001 */ /* SBSW_OS_ISR_ISRGETTHREAD_001 */ /* SBSW_OS_ISR_THREADGETOWNERAPPLICATION_001 */
                      currentThread,
                      Os_ThreadGetOwnerApplication(Os_IsrGetThread(isr))) == OS_CHECK_FAILED))
    {
      status = OS_STATUS_NOT_THE_OWNER_1;
    }
    else
    {
      /* #20 Disable the ISR source. */
      Os_Hal_IntDisableSource(isr->HwConfig);                                                                           /* SBSW_OS_ISR_HAL_INTDISABLESOURCE_001 */
      status = OS_STATUS_OK;
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_Api_EnableInterruptSource()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_Api_EnableInterruptSource(ISRType ISRID, boolean ClearPending)
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;
  Os_StatusType status;

  currentThread = Os_CoreGetThread();

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_ErrCheckIsBoolean(ClearPending) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_VALUE_IS_NOT_BOOLEAN;
  }
  else if(OS_UNLIKELY(Os_IsrCheckClearPendingSupported(ClearPending) == OS_CHECK_FAILED))                               /* COV_OS_NOFUNCCALL */
  {
    status = OS_STATUS_UNIMPLEMENTED_CLEARPENDING;
  }
  else if(OS_UNLIKELY(Os_IsrCheckId(ISRID) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_ID_1;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckCallContext(currentThread, OS_APICONTEXT_ISRENABLESOURCE) == OS_CHECK_FAILED))      /* SBSW_OS_ISR_THREADCHECKCALLCONTEXT_001 */
  {
    status = OS_STATUS_CALLEVEL;
  }
  else
  {
    P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) isr;

    isr = Os_IsrId2Isr(ISRID);

    if(OS_UNLIKELY(Os_ThreadCheckIsCurrentApplication(                                                                  /* SBSW_OS_ISR_THREADCHECKISCURRENTAPPLICATION_001 */ /* SBSW_OS_ISR_ISRGETTHREAD_001 */ /* SBSW_OS_ISR_THREADGETOWNERAPPLICATION_001 */
                      currentThread,
                      Os_ThreadGetOwnerApplication(Os_IsrGetThread(isr))) == OS_CHECK_FAILED))
    {
      status = OS_STATUS_NOT_THE_OWNER_1;
    }
    else
    {
      /* #20 Clear the pending flag if requested. */
      Os_IsrClearPendingIfRequested(isr, ClearPending);                                                                 /* SBSW_OS_ISR_CLEARPENDINGIFREQUESTED_001 */

      /* #30 Enable the ISR source. */
      Os_Hal_IntEnableSource(isr->HwConfig);                                                                            /* SBSW_OS_ISR_HAL_INTENABLESOURCE_001 */
      status = OS_STATUS_OK;
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050, 6080 */ /* MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_Api_InitialEnableInterruptSources()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_Api_InitialEnableInterruptSources(boolean ClearPending)
{
  P2CONST(Os_ThreadConfigType,  AUTOMATIC, OS_CONST) currentThread;
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) currentCore;
  Os_StatusType status;

  currentThread = Os_CoreGetThread();
  currentCore = Os_ThreadGetCore(currentThread);                                                                        /* SBSW_OS_ISR_THREADGETCORE_001 */

  /* #10 Perform checks. */
  if(Os_IsrCat2IsrsConfigured() == 0u)                                                                                  /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */  /* COV_OS_TESTSUITERESTRICTIONCAT2ISRS_XF */
  {
    status = Os_ErrSetOkInStdStatus(OS_STATUS_ID_1);                                                                    /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }
  else if(OS_UNLIKELY(Os_ErrCheckIsBoolean(ClearPending) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_VALUE_IS_NOT_BOOLEAN;
  }
  else if(OS_UNLIKELY(Os_IsrCheckClearPendingSupported(ClearPending) == OS_CHECK_FAILED))                               /* COV_OS_NOFUNCCALL */
  {
    status = OS_STATUS_UNIMPLEMENTED_CLEARPENDING;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckCallContext(currentThread, OS_APICONTEXT_ISRINITENABLESOURCE) == OS_CHECK_FAILED))  /* SBSW_OS_ISR_THREADCHECKCALLCONTEXT_001 */
  {
    status = OS_STATUS_CALLEVEL;
  }
  else
  {
    Os_CoreInitialEnableInterruptSources(currentCore, ClearPending);                                                    /* SBSW_OS_ISR_COREINITIALENABLEINTERRUPTSOURCES_001 */
    status = OS_STATUS_OK;
  }/* else */

  return status;
}                                                                                                                       /* PRQA S 6050, 6080 */ /* MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_Api_ClearPendingInterrupt()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_Api_ClearPendingInterrupt(ISRType ISRID)
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;
  Os_StatusType status;

  currentThread = Os_CoreGetThread();

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_IsrCheckClearPendingSupported(TRUE) == OS_CHECK_FAILED))                                            /* COV_OS_NOFUNCCALL */
  {
    status = OS_STATUS_UNIMPLEMENTED_CLEARPENDING;
  }
  else if(OS_UNLIKELY(Os_IsrCheckId(ISRID) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_ID_1;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckCallContext(currentThread, OS_APICONTEXT_ISRCLEARPENDING) == OS_CHECK_FAILED))      /* SBSW_OS_ISR_THREADCHECKCALLCONTEXT_001 */
  {
    status = OS_STATUS_CALLEVEL;
  }
  else
  {
    P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) isr;

    isr = Os_IsrId2Isr(ISRID);

    if(OS_UNLIKELY(Os_ThreadCheckIsCurrentApplication(                                                                  /* SBSW_OS_ISR_THREADCHECKISCURRENTAPPLICATION_001 */ /* SBSW_OS_ISR_ISRGETTHREAD_001 */ /* SBSW_OS_ISR_THREADGETOWNERAPPLICATION_001 */
                      currentThread,
                      Os_ThreadGetOwnerApplication(Os_IsrGetThread(isr))) == OS_CHECK_FAILED))
    {
      status = OS_STATUS_NOT_THE_OWNER_1;
    }
    else
    {
      /* #20 Clear the pending flag of the ISR source. */
      Os_Hal_IntClearPending(isr->HwConfig);                                                                            /* SBSW_OS_ISR_HAL_INTCLEARPENDING_001 */
      status = OS_STATUS_OK;
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_Api_IsInterruptSourceEnabled()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_Api_IsInterruptSourceEnabled
(
  ISRType ISRID,
  P2VAR(boolean, AUTOMATIC, OS_VAR_NOINIT) IsEnabled
)
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;
  Os_StatusType status;

  currentThread = Os_CoreGetThread();

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_IsrCheckId(ISRID) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_ID_1;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckCallContext(                                                                        /* SBSW_OS_ISR_THREADCHECKCALLCONTEXT_001 */
                         currentThread,
                         OS_APICONTEXT_ISINTERRUPTSOURCEENABLED) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_CALLEVEL;
  }
  else
  {
    P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) isr;

    isr = Os_IsrId2Isr(ISRID);

    if(OS_UNLIKELY(Os_ThreadCheckIsCurrentApplication(                                                                  /* SBSW_OS_ISR_THREADCHECKISCURRENTAPPLICATION_001 */ /* SBSW_OS_ISR_ISRGETTHREAD_001 */ /* SBSW_OS_ISR_THREADGETOWNERAPPLICATION_001 */
                      currentThread,
                      Os_ThreadGetOwnerApplication(Os_IsrGetThread(isr))) == OS_CHECK_FAILED))
    {
      status = OS_STATUS_NOT_THE_OWNER_1;
    }
    else
    {
      /* #20 Read interrupt source enable value. */
      if (Os_Hal_IntIsInterruptSourceEnabled(isr->HwConfig) == 0u )                                                     /* SBSW_OS_ISR_HAL_INTISINTERRUPTSOURCEENABLED_001 */
      {
         (*IsEnabled) = FALSE;                                                                                          /* SBSW_OS_PWA_PRECONDITION */
      }
      else
      {
         (*IsEnabled) = TRUE;                                                                                           /* SBSW_OS_PWA_PRECONDITION */
      }
      status = OS_STATUS_OK;
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050, 6080 */ /* MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_Api_IsInterruptPending()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_Api_IsInterruptPending
(
  ISRType ISRID,
  P2VAR(boolean, AUTOMATIC, OS_VAR_NOINIT) IsPending
)
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;
  Os_StatusType status;

  currentThread = Os_CoreGetThread();

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_IsrCheckClearPendingSupported(TRUE) == OS_CHECK_FAILED))                                            /* COV_OS_NOFUNCCALL */
  {
    status = OS_STATUS_UNIMPLEMENTED_CLEARPENDING;
  }
  else if(OS_UNLIKELY(Os_IsrCheckId(ISRID) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_ID_1;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckCallContext(currentThread, OS_APICONTEXT_ISINTERRUPTPENDING) == OS_CHECK_FAILED))   /* SBSW_OS_ISR_THREADCHECKCALLCONTEXT_001 */
  {
    status = OS_STATUS_CALLEVEL;
  }
  else
  {
    P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) isr;

    isr = Os_IsrId2Isr(ISRID);

    if(OS_UNLIKELY(Os_ThreadCheckIsCurrentApplication(                                                                  /* SBSW_OS_ISR_THREADCHECKISCURRENTAPPLICATION_001 */ /* SBSW_OS_ISR_ISRGETTHREAD_001 */ /* SBSW_OS_ISR_THREADGETOWNERAPPLICATION_001 */
                      currentThread,
                      Os_ThreadGetOwnerApplication(Os_IsrGetThread(isr))) == OS_CHECK_FAILED))
    {
      status = OS_STATUS_NOT_THE_OWNER_1;
    }
    else
    {
      /* #20 Read if there are any pending interrupts. */
      if (Os_Hal_IntIsInterruptPending(isr->HwConfig) == 0u)                                                            /* SBSW_OS_ISR_HAL_INTISINTERRUPTPENDING_001 */
      {
        (*IsPending)=FALSE;                                                                                             /* SBSW_OS_PWA_PRECONDITION */
      }
      else
      {
        (*IsPending)=TRUE;                                                                                              /* SBSW_OS_PWA_PRECONDITION */
      }
      status = OS_STATUS_OK;
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050, 6080 */ /* MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_IsrKill()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_IsrKill
(
  P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) Isr
)
{
  /* #10 If there is no ProtectionHook and no Killing: KernelPanic. */
  if (Os_HookIsProtectionHookEnabled() == 0u)                                                                           /* COV_OS_INVSTATE */ /* PRQA S 2991, 2995 */ /* MD_Os_Rule14.3_2991, MD_Os_Rule2.2_2995 */
  {
    if (Os_ErrIsKillingEnabled() == 0u)                                                                                 /* COV_OS_INVSTATE */ /* PRQA S 2991, 2995 */ /* MD_Os_Rule14.3_2991, MD_Os_Rule2.2_2995 */
    {
      Os_ErrKernelPanic();
    }
  }

  /* #15 Mark the Isr as killed */
  Os_IsrGetDyn(Isr)->IsKilled = TRUE;                                                                                   /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_ISR_ISRGETDYN_002 */

  /* #20 Inform trace and thread objects about the killing */
  Os_TraceIsrKill(Os_ThreadGetTrace(Os_IsrGetThread(Isr)));                                                             /* SBSW_OS_ISR_TRACEISRKILL_001 */ /* SBSW_OS_ISR_THREADGETTRACE_003 */ /* SBSW_OS_ISR_ISRGETTHREAD_001 */
  Os_ThreadKill(Os_IsrGetThread(Isr));                                                                                  /* SBSW_OS_ISR_THREADKILL_001 */ /* SBSW_OS_FC_PRECONDITION */
}                                                                                                                       /* PRQA S 6030, 6050, 6080 */ /* MD_Os_STCYC, MD_Os_STCAL, MD_Os_STMIF */


#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* module specific MISRA deviations:
 */

/* SBSW_JUSTIFICATION_BEGIN
\ID SBSW_OS_ISR_ISRGETTHREAD_001
  \DESCRIPTION    Os_IsrGetThread is called with the return value of Os_IsrId2Isr. The parameter of Os_IsrId2Isr is in the designed range.
  \COUNTERMEASURE \M [CM_OS_ISRID2ISR_M]

\ID SBSW_OS_ISR_THREADINIT_001
  \DESCRIPTION    Os_ThreadInit is called with the return value of Os_IsrGetThread.
  \COUNTERMEASURE \N [CM_OS_ISRGETTHREAD_N]

\ID SBSW_OS_ISR_ISRGETDYN_001
  \DESCRIPTION    Os_IsrGetDyn is called with the return value of Os_IsrThread2Isr.
  \COUNTERMEASURE \M [CM_OS_ISRTHREAD2ISR_01_02_M]
                  \M [CM_OS_ISRTHREAD2ISR_02_02_M]

\ID SBSW_OS_ISR_ISRGETDYN_002
  \DESCRIPTION    Write access to the return value of Os_IsrGetDyn.
  \COUNTERMEASURE \M [CM_OS_ISRGETDYN_M]

\ID SBSW_OS_ISR_COREASRGETTIMINGPROTECTION_001
 \DESCRIPTION    Os_CoreAsrGetTimingProtection is called with the return value of Os_ThreadGetCore.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_ISR_COREINITIALENABLEINTERRUPTSOURCES_001
 \DESCRIPTION    Os_CoreInitialEnableInterruptSources is called with the return value of Os_ThreadGetCore.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_ISR_TPCHECKINTERARRIVAL_001
 \DESCRIPTION    Os_TpCheckInterArrival is called with the return values of Os_CoreAsrGetTimingProtection and
                 Os_ThreadGetTpConfig.
 \COUNTERMEASURE \M [CM_OS_COREASRGETTIMINGPROTECTION_M]
                 \M [CM_OS_THREADGETTPCONFIG_M]

\ID SBSW_OS_ISR_COREINTERRUPTEDTHREADSPUSH_001
 \DESCRIPTION    Os_CoreInterruptedThreadsPush is called with the return values of Os_ThreadGetCore and
                 Os_CoreGetThread. Correctness of Os_CoreGetThread is ensured by preconditions. The compliance of the
                 precondition is checked during review.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_ISR_TRACETHREADSUSPENDANDSTART_001
 \DESCRIPTION    Os_TraceThreadSuspendAndStart is called with the return values of two calls of Os_ThreadGetTrace.
                 Correctness of Os_CoreGetThread is ensured by preconditions.
 \COUNTERMEASURE \M [CM_OS_THREADGETTRACE_M]

\ID SBSW_OS_ISR_THREADGETTRACE_001
 \DESCRIPTION    Os_ThreadGetTrace is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_ISR_THREADGETTRACE_002
 \DESCRIPTION    Os_ThreadGetTrace is called with the return value of Os_CoreInterruptedThreadsPop and Os_CoreGetThread.
                 Precondition ensures that the Os_CoreGetThread pointer is valid. The compliance of the
                 precondition is checked during review.
 \COUNTERMEASURE \T [CM_OS_COREINTERRUPTEDTHREADSPOP_T]

\ID SBSW_OS_ISR_THREADGETTRACE_003
 \DESCRIPTION    Os_ThreadGetTrace is called with the return value of Os_IsrGetThread.
 \COUNTERMEASURE \N [CM_OS_ISRGETTHREAD_N]

\ID SBSW_OS_ISR_THREADSUSPENDANDSTART_001
 \DESCRIPTION    Os_ThreadSuspendAndStart is called with the return value of Os_CoreGetThread and a value derived from
                 the Isr caller argument. Precondition ensures that the Isr pointer is valid. The compliance of the
                 precondition is checked during review.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD]

\ID SBSW_OS_ISR_HAL_INTENDOFINTERRUPT_001
 \DESCRIPTION    Os_Hal_IntEndOfInterrupt is called with the HwConfig derived from the caller argument Isr. Precondition
                 ensures that the Isr pointer is valid. The compliance of the precondition is checked during review.
 \COUNTERMEASURE \M [CM_OS_ISR_HWCONFIG_M]

\ID SBSW_OS_ISR_HAL_INTENDOFINTERRUPT_002
 \DESCRIPTION    Os_Hal_IntEndOfInterrupt is called with the HwConfig derived from an Isr object. The Isr object is
                 the return value of Os_IsrThread2Isr.
 \COUNTERMEASURE \M [CM_OS_ISRTHREAD2ISR_01_02_M]
                 \M [CM_OS_ISRTHREAD2ISR_02_02_M]

\ID SBSW_OS_ISR_HAL_INTDISABLESOURCE_001
 \DESCRIPTION    Os_Hal_IntDisableSource is called with the HwConfig derived from an Isr object. The Isr object is
                 the return value of Os_IsrId2Isr.
  \COUNTERMEASURE \M [CM_OS_ISRID2ISR_M]

\ID SBSW_OS_ISR_HAL_INTDISABLESOURCE_002
 \DESCRIPTION    Os_Hal_IntDisableSource is called with the HwConfig derived from an Isr object. The Isr object is
                 passed as argument to the caller. Precondition ensures that the Isr pointer is valid. The compliance
                 of the precondition is checked during review.
  \COUNTERMEASURE \M [CM_OS_ISR_HWCONFIG_M]

\ID SBSW_OS_ISR_HAL_INTCLEARPENDING_001
 \DESCRIPTION    Os_Hal_IntClearPending is called with the HwConfig derived from an Isr object. The Isr object is
                 the return value of Os_IsrId2Isr.
  \COUNTERMEASURE \M [CM_OS_ISRID2ISR_M]

\ID SBSW_OS_ISR_CLEARPENDINGIFREQUESTED_001
  \DESCRIPTION    Os_IsrClearPendingIfRequested is called with the return value of Os_IsrId2Isr. The parameter of 
                  Os_IsrId2Isr is in the designed range.
  \COUNTERMEASURE \M [CM_OS_ISRID2ISR_M]

\ID SBSW_OS_ISR_HAL_INTCLEARPENDING_002
 \DESCRIPTION    Os_Hal_IntClearPending is called with the HwConfig derived from an Isr object. The Isr object is
                 provided by the caller, validity is assured by the caller.
  \COUNTERMEASURE \N [CM_OS_ISRCLEARPENDING_N]

\ID SBSW_OS_ISR_CLEARPENDINGIFREQUESTED_001
  \DESCRIPTION    Os_IsrClearPendingIfRequested is called with the return value of Os_IsrId2Isr. The parameter of 
                  Os_IsrId2Isr is in the designed range.
  \COUNTERMEASURE \M [CM_OS_ISRID2ISR_M]


\ID SBSW_OS_ISR_HAL_INTISINTERRUPTSOURCEENABLED_001
 \DESCRIPTION    Os_Hal_IntIsInterruptSourceEnabled is called with the HwConfig derived from an Isr object and a
                 isEnabled boolean reference passed as argument to the caller .
                 The Isr object is the return value of Os_IsrId2Isr.
                 Preconditions ensures that isEnabled pointer is valid.
                 The compliance of the precondition is checked during review.
  \COUNTERMEASURE \M [CM_OS_ISRID2ISR_M]

\ID SBSW_OS_ISR_HAL_INTISINTERRUPTPENDING_001
 \DESCRIPTION    Os_Hal_IntIsInterruptPending is called with the HwConfig derived from an Isr object and a
                 isPending boolean reference passed as argument to the caller.
                 The Isr object is the return value of Os_IsrId2Isr.
                 Preconditions ensures that isPending pointer is valid.
                 The compliance of the precondition is checked during review.
  \COUNTERMEASURE \M [CM_OS_ISRID2ISR_M]

\ID SBSW_OS_ISR_HAL_INTENABLESOURCE_001
 \DESCRIPTION    Os_Hal_IntEnableSource is called with the HwConfig derived from an Isr object. The Isr object is
                 the return value of Os_IsrId2Isr.
  \COUNTERMEASURE \M [CM_OS_ISRID2ISR_M]

\ID SBSW_OS_ISR_HAL_INTISRLEVELISLE_001
 \DESCRIPTION    Os_Hal_IntIsrLevelIsLe is called with the HwConfig derived from the caller argument Isr and a level
                 derived from a second caller argument. Precondition ensures that arguments are valid. The compliance
                 of the precondition is checked during review.
 \COUNTERMEASURE \M [CM_OS_ISR_HWCONFIG_M]

\ID SBSW_OS_ISR_ISRTHREAD2ISR_001
 \DESCRIPTION    Os_IsrThread2Isr is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_ISR_ISRTHREAD2ISR_002
 \DESCRIPTION    Os_IsrThread2Isr is called with the return value of Os_CoreThreadGetByContext.
 \COUNTERMEASURE \R [CM_OS_CORETHREADGETBYCONTEXT_R]

\ID SBSW_OS_ISR_THREADGETCORE_001
 \DESCRIPTION    Os_ThreadGetCore is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_ISR_THREADGETCORE_002
 \DESCRIPTION    Os_ThreadGetCore is called with the return value of Os_IsrGetThread.
 \COUNTERMEASURE \N [CM_OS_ISRGETTHREAD_N]

\ID SBSW_OS_ISR_THREADCHECKRESOURCESRELEASED_001
 \DESCRIPTION    Os_ThreadCheckResourcesReleased is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_ISR_THREADRESOURCEFORCERELEASE_001
 \DESCRIPTION    Os_ThreadResourceForceRelease is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_ISR_THREADCHECKSPINLOCKSRELEASED_001
 \DESCRIPTION    Os_ThreadCheckSpinlocksReleased is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_ISR_THREADSPINLOCKFORCERELEASE_001
 \DESCRIPTION    Os_ThreadSpinlockForceRelease is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_ISR_THREADCHECKAREINTERRUPTSENABLED_001
 \DESCRIPTION    Os_ThreadCheckAreInterruptsEnabled is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_ISR_THREADGETINTERRUPTAPISTATE_001
 \DESCRIPTION    Os_ThreadGetInterruptApiState is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_ISR_INTERRUPTCLEANUP_001
 \DESCRIPTION    Os_InterruptCleanup is called with the return value of Os_ThreadGetInterruptApiState.
 \COUNTERMEASURE \M [CM_OS_THREADGETINTERRUPTAPISTATE_M]

\ID SBSW_OS_ISR_COREINTERRUPTEDTHREADSPOP_001
 \DESCRIPTION    Os_CoreInterruptedThreadsPop is called with the return value of Os_ThreadGetCore.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_ISR_THREADISTASK_001
 \DESCRIPTION    Os_ThreadIsTask is called with the return value of Os_CoreInterruptedThreadsPop.
 \COUNTERMEASURE \T [CM_OS_COREINTERRUPTEDTHREADSPOP_T]

\ID SBSW_OS_ISR_TASKRETURNTOTASKLEVEL_001
 \DESCRIPTION    Os_TaskReturnToTaskLevel is called with the return value of Os_TaskThread2Task.
 \COUNTERMEASURE \R [CM_OS_TASKTHREAD2TASK_R]

\ID SBSW_OS_ISR_TASKTHREAD2TASK_001
 \DESCRIPTION    Os_TaskThread2Task is called with the return value of Os_CoreInterruptedThreadsPop.
 \COUNTERMEASURE \T [CM_OS_COREINTERRUPTEDTHREADSPOP_T]

\ID SBSW_OS_ISR_TRACETHREADCLEANUPANDRESUME_001
 \DESCRIPTION    Os_TraceThreadCleanupAndResume is called with the return values of two calls of Os_ThreadGetTrace.
                 Correctness of Os_CoreGetThread is ensured by preconditions.
 \COUNTERMEASURE \M [CM_OS_THREADGETTRACE_M]

\ID SBSW_OS_ISR_THREADCLEANUPANDRESUME_001
 \DESCRIPTION    Os_ThreadCleanupAndResume is called with the return value of Os_CoreInterruptedThreadsPop.
 \COUNTERMEASURE \T [CM_OS_COREINTERRUPTEDTHREADSPOP_T]

\ID SBSW_OS_ISR_THREADCHECKCALLCONTEXT_001
 \DESCRIPTION    Os_ThreadCheckCallContext is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_ISR_THREADCHECKISCURRENTAPPLICATION_001
 \DESCRIPTION    Os_ThreadCheckIsCurrentApplication is called with the return values of Os_CoreGetThread and
                 Os_ThreadGetOwnerApplication. Precondition ensures that the return value of Os_CoreGetThread pointer
                 is valid. The compliance of the precondition is checked during review.
 \COUNTERMEASURE \M [CM_OS_THREADGETOWNERAPPLICATION_M]

\ID SBSW_OS_ISR_THREADGETOWNERAPPLICATION_001
 \DESCRIPTION    Os_ThreadGetOwnerApplication is called with the return value of Os_IsrGetThread.
 \COUNTERMEASURE \N [CM_OS_ISRGETTHREAD_N]

\ID SBSW_OS_ISR_TRACEISRKILL_001
 \DESCRIPTION    Os_TraceIsrKill is called with the return value of Os_ThreadGetTrace.
 \COUNTERMEASURE \M [CM_OS_THREADGETTRACE_M]

\ID SBSW_OS_ISR_THREADKILL_001
 \DESCRIPTION    Os_ThreadKill is called with the return value of Os_IsrGetThread.
 \COUNTERMEASURE \N [CM_OS_ISRGETTHREAD_N]

\ID SBSW_OS_ISR_THREADGETACCESSRIGHTS_001
 \DESCRIPTION    Os_ThreadGetAccessRights is called with the return value of Os_IsrGetThread.
 \COUNTERMEASURE \N [CM_OS_ISRGETTHREAD_N]

\ID SBSW_OS_ISR_CORETHREADGETBYCONTEXT_001
 \DESCRIPTION    Os_CoreThreadGetByContext is called with the return value of Os_ThreadGetCore.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

SBSW_JUSTIFICATION_END */

/*
\CM CM_OS_ISRTHREAD2ISR_01_02_M
      Verify that
        1. the return address of each ISR except the timing protection ISR and of each object
           which is derived from ISR is Os_IsrEpilogue and
        2. that Os_IsrEpilogue is not the return address of any other thread object.

\CM CM_OS_ISRTHREAD2ISR_02_02_M
      Verify that
        1. the return address of timing protection ISRs is Os_IsrEpilogueTp and
        2. that Os_IsrEpilogueTp is not the return address of any other thread object.

\CM CM_OS_ISRID2ISR_M
      Verify that:
        1. each ISR pointer in OsCfg_IsrRefs except the last is no NULL_PTR,
        2. the size of OsCfg_IsrRefs is equal to OS_ISRID_COUNT + 1 and
        3. each element in ISRType has a lower value than OS_ISRID_COUNT.

\CM CM_OS_ISRGETDYN_M
      Verify that the ISR Dyn pointer of each Os_IsrConfigType object is initialized with a
      dynamic ISR derived from an Os_IsrType object.

\CM CM_OS_ISRGETTHREAD_N
      Precondition ensures that the pointer is valid. The compliance of the precondition is checked during review.

\CM CM_OS_ISRCLEARPENDING_N
      Precondition ensures that the pointer is valid. The compliance of the precondition is checked during review.

\CM CM_OS_ISR_HWCONFIG_M
      Verify that the ISR HwConfig pointer of each Os_IsrType object is initialized with a
      dynamic ISR derived from an Os_IsrType object.

\CM CM_OS_ISRGETACCESSRIGHTS_M
      [CM_OS_THREADGETACCESSRIGHTS_M]
*/

/*!
 * \}
 */

/**********************************************************************************************************************
 *  END OF FILE: Os_Isr.c
 *********************************************************************************************************************/
