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
 * \addtogroup Os_Spinlock
 *
 * \{
 *
 * \file
 * \brief       User API for Spinlocks.
 * \details     --no details--
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_SPINLOCK_H
# define OS_SPINLOCK_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_SpinlockInt.h"


/* Os kernel module dependencies */
# include "OsInt.h"
# include "Os_Lcfg.h"
# include "Os_Common.h"
# include "Os_Lock.h"
# include "Os_Error.h"
# include "Os_Core.h"
# include "Os_Interrupt.h"
# include "Os_Trace.h"
# include "Os_Thread.h"
# include "Os_Scheduler.h"

/* Os hal dependencies */
# include "Os_Hal_Compiler.h"
# include "Os_Hal_Core.h"



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
 *  Os_SpinlockIsEnabled()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_SpinlockIsEnabled, (void))
{
  return (Os_StdReturnType)((uint32)OS_SPINLOCKID_COUNT > 0u);                                                          /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_SpinlockListInit()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,                                                             /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_SpinlockListInit,
(
  P2VAR(Os_SpinlockListType, AUTOMATIC, OS_CONST) LockList
))
{
  *LockList = OS_SPINLOCK_LIST_END;                                                                                     /* SBSW_OS_PWA_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_SpinlockInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_SpinlockInit,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
))
{
  P2VAR(Os_SpinlockType, AUTOMATIC, OS_VAR_NOINIT) spinlockDyn;

  spinlockDyn = Os_SpinlockGetDyn(Spinlock);                                                                            /* SBSW_OS_FC_PRECONDITION */

  /* #10 Initialize the underlying lock. */
  Os_LockInit(&(Spinlock->Lock));                                                                                       /* SBSW_OS_FC_PRECONDITION */

  /* #20 Set owner thread to "no owner". */
  spinlockDyn->OwnerThread = NULL_PTR;                                                                                  /* SBSW_OS_SL_SPINLOCKGETDYN_001 */

  /* #30 Initialize the HAL spinlock. */
  Os_Hal_SpinInit(&(spinlockDyn->Spinlock));                                                                            /* SBSW_OS_SL_HAL_SPININIT_001 */
}


/***********************************************************************************************************************
 *  Os_SpinlockGetDyn()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE                                                                            /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
P2VAR(Os_SpinlockType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE, OS_ALWAYS_INLINE, Os_SpinlockGetDyn,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
))
{
  return (P2VAR(Os_SpinlockType, AUTOMATIC, OS_VAR_NOINIT))Os_LockGetDyn(&(Spinlock->Lock));                            /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */ /* SBSW_OS_FC_PRECONDITION */

}


/***********************************************************************************************************************
 *  Os_SpinlockCheckId()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_SpinlockCheckId,
(
  SpinlockIdType SpinlockId
))
{
  return Os_ErrExtendedCheck(Os_ErrIsValueLo((uint32)SpinlockId, (uint32)OS_SPINLOCKID_COUNT));
}


# if defined (OS_CFG_COMPILER_TASKING)                                                                                  /* COV_OS_COMPILERPRAGMA */
/* This suppresses the warning with regard to "access out of bound". This can be suppressed here,
 * since this warning is only reported by the compiler if no spinlock is configured.
 * In this case Os_SpinlockId2Spinlock will never be used during run-time.
 */
#  pragma warning 561                                                                                                   /* PRQA S 3116 */ /* MD_MSR_Pragma */
# endif
/***********************************************************************************************************************
 *  Os_SpinlockId2Spinlock()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE                                                                            /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_SpinlockId2Spinlock,
(
  SpinlockIdType SpinlockId
))
{
  Os_Assert(Os_ErrIsValueLo((uint32)SpinlockId, (uint32)OS_SPINLOCKID_COUNT));
  return OsCfg_SpinlockRefs[SpinlockId];
}
# if defined (OS_CFG_COMPILER_TASKING)                                                                                  /* COV_OS_COMPILERPRAGMA */
#  pragma warning restore                                                                                               /* PRQA S 3116 */ /* MD_MSR_Pragma */
# endif


/***********************************************************************************************************************
 *  Os_SpinlockGetAccessingApplications()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_AppAccessMaskType, OS_CODE,                                             /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_SpinlockGetAccessingApplications,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
))
{
  return Os_LockGetAccessingApplications(&Spinlock->Lock);                                                              /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_SpinlockInternalGet()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
Os_SpinlockInternalGet,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  P2VAR(Os_SpinlockType, AUTOMATIC, OS_VAR_NOINIT) spinlockDyn;
  Os_Hal_SpinlockResultType result;

  spinlockDyn = Os_SpinlockGetDyn(Spinlock);                                                                            /* SBSW_OS_FC_PRECONDITION */

  /* #10 Inform the trace module */
  Os_TraceSpinlockRequested(Spinlock->TimingHookTrace);                                                                 /* SBSW_OS_SL_TRACESPINLOCKREQUESTED_001 */

  /* #20 Loop. */
  do
  {
    /* #30 Spin while the spinlock is locked. */
    while(Os_Hal_SpinIsLocked(&(spinlockDyn->Spinlock)) != 0u)                                                          /* SBSW_OS_SL_HAL_SPINISLOCKED_001 */
    {
      Os_Hal_CoreNop();
    }

    /* #40 Try to get the lock. */
    result = Os_SpinlockInternalTryGet(Spinlock);                                                                       /* SBSW_OS_FC_PRECONDITION */

  /* #50 Loop while locking failed. */
  }while(result != OS_HAL_SPINLOCKSUCCEEDED);                                                                           /* COV_OS_SPINLOCKRACECONDITION */
}


/***********************************************************************************************************************
 *  Os_SpinlockInternalTryGet()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_Hal_SpinlockResultType, OS_CODE,                                        /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_SpinlockInternalTryGet,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_Hal_SpinlockResultType result;
  P2VAR(Os_SpinlockType, AUTOMATIC, OS_VAR_NOINIT) spinlockDyn;

  spinlockDyn = Os_SpinlockGetDyn(Spinlock);                                                                            /* SBSW_OS_FC_PRECONDITION */

  /* #10 If killing is enabled: */
  if(Os_ErrIsKillingEnabled() != 0u)                                                                                    /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
  {
    Os_IntStateType interruptState;

    /* #20 Suspend all interrupts including timing protection. */
    Os_IntSuspend(&interruptState);                                                                                     /* SBSW_OS_FC_POINTER2LOCAL */

    /* #30 Try to get the lock. */
    result = Os_Hal_SpinTryLock(&(spinlockDyn->Spinlock));                                                              /* SBSW_OS_SL_HAL_SPINTRYLOCK_001 */

    /* #40 On success: */
    if(result == OS_HAL_SPINLOCKSUCCEEDED)
    {
      /* #50 Set the lock owner. */
      spinlockDyn->OwnerThread = Os_CoreGetThread();                                                                    /* SBSW_OS_SL_SPINLOCKGETDYN_001 */
    }

    /* #60 Resume interrupts. */
    Os_IntResume(&interruptState);                                                                                      /* SBSW_OS_FC_POINTER2LOCAL */
  }
  /* #70 Else try to get the lock. */
  else
  {
    result = Os_Hal_SpinTryLock(&(spinlockDyn->Spinlock));                                                              /* SBSW_OS_SL_HAL_SPINTRYLOCK_001 */
  }

  /* #80 On Success inform the trace module. */
  if(result == OS_HAL_SPINLOCKSUCCEEDED)
  {
    Os_TraceSpinlockTaken(Spinlock->TimingHookTrace);                                                                   /* SBSW_OS_SL_TRACESPINLOCKTAKEN_001 */
  }

  /* #90 Return result. */
  return result;
}


/***********************************************************************************************************************
 *  Os_SpinlockInternalRelease()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
Os_SpinlockInternalRelease,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  P2VAR(Os_SpinlockType, AUTOMATIC, OS_VAR_NOINIT) spinlockDyn;

  spinlockDyn = Os_SpinlockGetDyn(Spinlock);                                                                            /* SBSW_OS_FC_PRECONDITION */

  /* #10 If killing is enabled: */
  if(Os_ErrIsKillingEnabled() != 0u)                                                                                    /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
  {
    Os_IntStateType interruptState;

    Os_Assert((Os_StdReturnType)(spinlockDyn->OwnerThread == Os_CoreGetThread()));                                      /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */

    /* #20 Suspend interrupts. */
    Os_IntSuspend(&interruptState);                                                                                     /* SBSW_OS_FC_POINTER2LOCAL */

    /* #30 Inform the trace module. */
    Os_TraceSpinlockReleased(Spinlock->TimingHookTrace);                                                                /* SBSW_OS_SL_TRACESPINLOCKRELEASED_001 */

    /* #40 Delegate to the HAL. */
    Os_Hal_SpinUnlock(&(spinlockDyn->Spinlock));                                                                        /* SBSW_OS_SL_HAL_SPINUNLOCKED_001 */

    /* #50 Clear the owner. */
    spinlockDyn->OwnerThread = NULL_PTR;                                                                                /* SBSW_OS_SL_SPINLOCKGETDYN_001 */

    /* #60 Resume interrupts. */
    Os_IntResume(&interruptState);                                                                                      /* SBSW_OS_FC_POINTER2LOCAL */
  }
  else
  {
    /* #70 Else inform the trace module. */
    Os_TraceSpinlockReleased(Spinlock->TimingHookTrace);                                                                /* SBSW_OS_SL_TRACESPINLOCKRELEASED_001 */

    /* #80 Delegate to the HAL. */
    Os_Hal_SpinUnlock(&(spinlockDyn->Spinlock));                                                                        /* SBSW_OS_SL_HAL_SPINUNLOCKED_001 */
  }

}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */





#endif /* OS_SPINLOCK_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_Spinlock.h
 **********************************************************************************************************************/
