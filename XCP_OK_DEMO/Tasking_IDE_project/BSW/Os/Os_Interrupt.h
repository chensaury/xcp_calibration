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
 * \addtogroup Os_Interrupt
 * \{
 * \file
 * \brief       This interface provides the AUTOSAR OS interrupt API and Vector extensions.
 * \details     --no details--
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_INTERRUPT_H
# define OS_INTERRUPT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module dependencies */
# include "Os_InterruptInt.h"

/* Os kernel module dependencies */
# include "Os_Common.h"
# include "Os_Error.h"
# include "Os_Trace.h"
# include "Os_TimingProtection.h"

/* Os Hal dependencies */
# include "Os_Hal_Compiler.h"
# include "Os_Hal_Interrupt.h"




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
 *  GLOBAL FUNCTION
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  Os_IntDisableGlobal()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_IntDisableGlobal, (void))                                                                                            /* COV_OS_HALPLATFORMGLOBAL2LEVELSUPPORTED */
{
  Os_Hal_IntDisableGlobal();
}


/***********************************************************************************************************************
 *  Os_IntEnableGlobal()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_IntEnableGlobal, (void))                                                                                             /* COV_OS_HALPLATFORMGLOBAL2LEVELSUPPORTED */
{
  Os_Hal_IntGlobalStateType globalState;

  /* #10 Get the state to enable all interrupts global. */
  Os_Hal_IntGetGlobalEnable(&globalState);                                                                              /* SBSW_OS_FC_POINTER2LOCAL */

  /* #20 Enable interrupt handling. */
  Os_Hal_IntSetGlobalState(&globalState);                                                                               /* SBSW_OS_FC_POINTER2LOCAL */
}


/***********************************************************************************************************************
 *  Os_IntSuspend()
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_IntSuspend,
(
  P2VAR(Os_IntStateType, AUTOMATIC, AUTOMATIC) State
))
{
  /* #10 Check if interrupt locking via level is needed: */
  if(Os_InterruptLockOnLevelIsNeeded() != 0u)                                                                           /* COV_OS_HALPLATFORMLEVELSUPPORT */
  {
    Os_Hal_IntLevelType level;

    /* #20 Get the level to suspend all interrupts including timing protection interrupt. */
    Os_Hal_IntGetTPLockLevel(&level);                                                                                   /* SBSW_OS_FC_POINTER2LOCAL */

    /* #30 Get the current level, which should later be restored to resume interrupt handling. */
    Os_Hal_IntGetLevel(&(State->Level));                                                                                /* SBSW_OS_FC_PRECONDITION */

    /* #40 Change to interrupt level. */
    Os_Hal_IntSetLevel(&level);                                                                                         /* SBSW_OS_FC_POINTER2LOCAL */
  }
  /* #50 Otherwise fetch current state and disable globally. */
  else
  {
    /* #60 Store the current global state and disable global. */
    State->Global = Os_Hal_IntDisableAndReturnGlobalState();                                                            /* SBSW_OS_PWA_PRECONDITION */
  }
}


/***********************************************************************************************************************
 *  Os_IntResume()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_IntResume,
(
  P2CONST(Os_IntStateType, AUTOMATIC, AUTOMATIC) State
))
{
  /* #10 Check if interrupt locking via level is needed: */
  if(Os_InterruptLockOnLevelIsNeeded() != 0u)                                                                           /* COV_OS_HALPLATFORMLEVELSUPPORT */
  {
    /* #20 Restore the interrupt level. */
    Os_Hal_IntSetLevel(&(State->Level));                                                                                /* SBSW_OS_FC_PRECONDITION */
  }
  /* #30 Otherwise: */
  else
  {
    /* #40 Restore the global interrupt state. */
    Os_Hal_IntSetGlobalState(&(State->Global));                                                                         /* SBSW_OS_FC_PRECONDITION */
  }
}


/***********************************************************************************************************************
 *  Os_IntDisable()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_IntDisable,
(
  void
))
{
  Os_IntStateType state;

  /* #10 Call suspend behavior and forget current state. */
  Os_IntSuspend(&state);                                                                                                /* SBSW_OS_FC_POINTER2LOCAL */
}


/***********************************************************************************************************************
 *  Os_InterruptCheckEnabled()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_InterruptCheckEnabled,
(
  P2CONST(Os_IntApiStateType, AUTOMATIC, OS_VAR_NOINIT) InterruptState
))
{
  return Os_ErrExtendedCheck((Os_StdReturnType)(((Os_StdReturnType)(InterruptState->Os_IntLockingState.InDisableAll) |  /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
                                                 InterruptState->Os_IntLockingState.SuspendOsCounter  |
                                                 InterruptState->Os_IntLockingState.SuspendAllCounter  ) == 0u));
}


/***********************************************************************************************************************
 *  Os_InterruptCleanup()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_InterruptCleanup,                      /* PRQA S 3219, 3673 */ /* MD_Os_Rule2.1_3219, MD_MSR_Rule8.13 */
(
  P2VAR(Os_IntApiStateType, AUTOMATIC, OS_VAR_NOINIT) InterruptState
))
{
  /* #10 Initialize the given interrupt API state. */
  Os_InterruptInit(InterruptState);                                                                                     /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_InterruptCopy()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_InterruptCopy,                         /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
(
  P2CONST(Os_IntApiStateType, AUTOMATIC, OS_VAR_NOINIT) Source,
  P2VAR(Os_IntApiStateType, AUTOMATIC, OS_VAR_NOINIT) Destination
))
{
  *Destination = *Source;                                                                                               /* SBSW_OS_PWA_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_InterruptIsCriticalSectionTracingEnabled()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_InterruptIsCriticalSectionTracingEnabled, (void))
{
  return (Os_ErrIsServiceProtectionEnabled() | Os_ErrIsExtendedStatusEnabled());
}


/***********************************************************************************************************************
 *  Os_IntIsGlobal2LevelSwitchSupported()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMLEVELSUPPORT */
Os_IntIsGlobal2LevelSwitchSupported, (void))                                                                            /* COV_OS_HALPLATFORMLEVELSUPPORT */
{
  return Os_Hal_IntIsGlobal2LevelSwitchSupported();
}


/***********************************************************************************************************************
 *  Os_InterruptIsCat0Enabled()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMLEVELSUPPORT */
OS_ALWAYS_INLINE, Os_InterruptIsCat0Enabled, (void))                                                                    /* COV_OS_HALPLATFORMLEVELSUPPORT */
{
  return (Os_StdReturnType)(OS_CFG_CAT0 == STD_ON);                                                                     /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_InterruptLockOnLevelIsNeeded()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_InterruptLockOnLevelIsNeeded, (void))
{
  Os_StdReturnType result;

  result = 0;

  if(Os_Hal_IntIsLevelSupported() != 0u)                                                                                /* COV_OS_HALPLATFORMLEVELSUPPORT */
  {
    if(Os_TpIsEnabled() != 0u)                                                                                          /* COV_OS_HALPLATFORMTPUNSUPPORTED_XF */
    {
      result = !0u;                                                                                                     /* PRQA S 4404, 4558 */  /* MD_Os_C90BooleanCompatibility, MD_Os_Rule10.1_4558 */
    }
    else
    {
      result = Os_InterruptIsCat0Enabled();
    }
  }

  return result;
}


/***********************************************************************************************************************
 *  Os_InterruptSaveAndIncrease()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,                                                             /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_InterruptSaveAndIncrease,
(
  P2VAR(Os_IntStateType, AUTOMATIC, AUTOMATIC) CurrentState,
  P2CONST(Os_Hal_IntLevelType, AUTOMATIC, OS_CONST) IncreaseLevel
))
{
  /* #10 If interrupt level switching is supported: */
  if(Os_Hal_IntIsLevelSupported() != 0u)                                                                                /* COV_OS_HALPLATFORMLEVELSUPPORT */
  {
    Os_Hal_IntLevelType currentLevel;

    Os_Hal_IntGetLevel(&currentLevel);                                                                                  /* SBSW_OS_FC_POINTER2LOCAL */

    /* #20 If the given priority level is higher than the current interrupt priority level: */
    if(Os_Hal_IntLevelIsGt(IncreaseLevel, &currentLevel) != 0u)                                                         /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_FC_POINTER2LOCAL */
    {
      /* #30 Suspend to given interrupt priority level. */
      Os_Hal_IntSetLevel(IncreaseLevel);                                                                                /* SBSW_OS_FC_PRECONDITION */
    }

    /* #40 Save current interrupt priority level. */
    CurrentState->Level = currentLevel;                                                                                 /* SBSW_OS_PWA_PRECONDITION */
  }
  else
  {
    /* #50 Otherwise save current global state and disable interrupts. */
    CurrentState->Global = Os_Hal_IntDisableAndReturnGlobalState();                                                     /* SBSW_OS_PWA_PRECONDITION */
  }
}


/***********************************************************************************************************************
 *  Os_InterruptRestore()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_InterruptRestore,                      /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
(
  P2CONST(Os_IntStateType, AUTOMATIC, OS_VAR_NOINIT) PreviousIntState
))
{
  /* #10 If interrupt level switching is supported: */
  if(Os_Hal_IntIsLevelSupported() != 0u)                                                                                /* COV_OS_HALPLATFORMLEVELSUPPORT */
  {
    Os_Hal_IntLevelType currentLevel;

    Os_Hal_IntGetLevel(&currentLevel);                                                                                  /* SBSW_OS_FC_POINTER2LOCAL */

    /* #20 If the previous interrupt priority level is lower than the current interrupt priority level: */
    if(Os_Hal_IntLevelIsGt(&currentLevel, &(PreviousIntState->Level)) != 0u)                                            /* SBSW_OS_FC_POINTER2LOCAL */ /* SBSW_OS_FC_PRECONDITION */
    {
      /* #30 Suspend to given interrupt priority level. */
      Os_Hal_IntSetLevel(&(PreviousIntState->Level));                                                                   /* SBSW_OS_FC_PRECONDITION */
    }
  }
  else
  {
    /* #40 Otherwise restore the global flag. */
    Os_Hal_IntSetGlobalState(&(PreviousIntState->Global));                                                              /* SBSW_OS_FC_PRECONDITION */
  }
}


/***********************************************************************************************************************
 *  Os_InterruptTpLockAllStart()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_InterruptTpLockAllStart,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) core;
  P2CONST(Os_TpConfigType, TYPEDEF, OS_CONST) coreTp;

  /* #10 Get the correct parameter values and call the respective timing protection function. */
  core = Os_ThreadGetCore(Thread);                                                                                      /* SBSW_OS_FC_PRECONDITION */
  coreTp = Os_CoreAsrGetTimingProtection(core);                                                                         /* SBSW_OS_INT_COREASRGETTIMINGPROTECTION_001 */

  Os_TpStartAllInterrupt(coreTp);                                                                                       /* SBSW_OS_INT_TPSTARTALLINTERRUPT_001 */
}


/***********************************************************************************************************************
 *  Os_InterruptTpLockAllStop()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_InterruptTpLockAllStop,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) core;
  P2CONST(Os_TpConfigType, TYPEDEF, OS_CONST) coreTp;

  /* #10 Get the correct parameter values and call the respective timing protection function. */
  core = Os_ThreadGetCore(Thread);                                                                                      /* SBSW_OS_FC_PRECONDITION */
  coreTp = Os_CoreAsrGetTimingProtection(core);                                                                         /* SBSW_OS_INT_COREASRGETTIMINGPROTECTION_001 */

  Os_TpStopAllInterrupt(coreTp);                                                                                        /* SBSW_OS_INT_TPSTOPALLINTERRUPT_001 */
}


/***********************************************************************************************************************
 *  Os_InterruptTpLockOsStart()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_InterruptTpLockOsStart,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) core;
  P2CONST(Os_TpConfigType, TYPEDEF, OS_CONST) coreTp;

  /* #10 Get the correct parameter values and call the respective timing protection function. */
  core = Os_ThreadGetCore(Thread);                                                                                      /* SBSW_OS_FC_PRECONDITION */
  coreTp = Os_CoreAsrGetTimingProtection(core);                                                                         /* SBSW_OS_INT_COREASRGETTIMINGPROTECTION_001 */

  Os_TpStartOsInterrupt(coreTp);                                                                                        /* SBSW_OS_INT_TPSTARTOSINTERRUPT_001 */
}


/***********************************************************************************************************************
 *  Os_InterruptTpLockOsStop()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_InterruptTpLockOsStop,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) core;
  P2CONST(Os_TpConfigType, TYPEDEF, OS_CONST) coreTp;

  /* #10 Get the correct parameter values and call the respective timing protection function. */
  core = Os_ThreadGetCore(Thread);                                                                                      /* SBSW_OS_FC_PRECONDITION */
  coreTp = Os_CoreAsrGetTimingProtection(core);                                                                         /* SBSW_OS_INT_COREASRGETTIMINGPROTECTION_001 */

  Os_TpStopOsInterrupt(coreTp);                                                                                         /* SBSW_OS_INT_TPSTOPOSINTERRUPT_001 */
}


/***********************************************************************************************************************
 *  Os_InterruptDisableGlobal()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_InterruptDisableGlobal,                /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
(
  void
))
{
  /* #10 Tell timing protection module to start measuring locking time. */
  Os_InterruptTpLockAllStart(Os_CoreGetThread());                                                                       /* SBSW_OS_INT_INTERRUPTTPLOCKALLSTART_001 */

  /* #20 Check if interrupt locking via level is needed: */
  if(Os_InterruptLockOnLevelIsNeeded() != 0u)                                                                           /* COV_OS_HALPLATFORMLEVELSUPPORT */
  {
    Os_Hal_IntLevelType cat1DisableLevel;

    /* #30 Disable all interrupts up to category 1 ISRs. */
    Os_Hal_IntGetCat1LockLevel(&cat1DisableLevel);                                                                      /* SBSW_OS_FC_POINTER2LOCAL */
    Os_Hal_IntSetLevel(&cat1DisableLevel);                                                                              /* SBSW_OS_FC_POINTER2LOCAL */
  }
  else
  {
    /* #40 Otherwise disable global interrupt handling. */
    Os_Hal_IntDisableGlobal();
  }

  /* #50 Inform the trace module that interrupts have been disabled. */
  Os_TraceInterruptsGlobalDisabled();
}


/***********************************************************************************************************************
 *  Os_InterruptEnableGlobal()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_InterruptEnableGlobal,                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
(
  void
))
{
  /* #10 Inform the trace module that interrupts are going to be enabled. */
  Os_TraceInterruptsGlobalEnabled();

  /* #20 Check if interrupt locking via level is needed: */
  if(Os_InterruptLockOnLevelIsNeeded() != 0u)                                                                           /* COV_OS_HALPLATFORMLEVELSUPPORT */
  {
    Os_Hal_IntLevelType taskLevel;

    /* #30 Enable all interrupts. */
    Os_Hal_IntGetTaskLevel(&taskLevel);                                                                                 /* SBSW_OS_FC_POINTER2LOCAL */
    Os_Hal_IntSetLevel(&taskLevel);                                                                                     /* SBSW_OS_FC_POINTER2LOCAL */
  }
  else
  {
    /* #40 Otherwise enable global interrupt handling. */
    Os_Hal_IntEnableGlobal();
  }

  /* #50 Tell timing protection module to stop measuring locking time. */
  Os_InterruptTpLockAllStop(Os_CoreGetThread());                                                                        /* SBSW_OS_INT_INTERRUPTTPLOCKALLSTOP_001 */
}


/***********************************************************************************************************************
 *  Os_InterruptDisableLevel()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_InterruptDisableLevel,                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
(
  void
))
{
  /* #10 Tell timing protection module to start measuring locking time. */
  Os_InterruptTpLockOsStart(Os_CoreGetThread());                                                                        /* SBSW_OS_INT_INTERRUPTTPLOCKOSSTART_001 */

  /* #20 Check if interrupt level switching is supported: */
  if(Os_Hal_IntIsLevelSupported() != 0u)                                                                                /* COV_OS_HALPLATFORMLEVELSUPPORT */
  {
    Os_Hal_IntLevelType cat2DisableLevel;

    /* #30 Disable OS interrupts. */
    Os_Hal_IntGetCat2LockLevel(&cat2DisableLevel);                                                                      /* SBSW_OS_FC_POINTER2LOCAL */
    Os_Hal_IntSetLevel(&cat2DisableLevel);                                                                              /* SBSW_OS_FC_POINTER2LOCAL */
  }
  else
  {
    /* #40 Otherwise disable global interrupt handling. */
    Os_Hal_IntDisableGlobal();
  }

  /* #50 Inform the trace module that interrupts have been disabled. */
  Os_TraceInterruptsLevelDisabled();
}


/***********************************************************************************************************************
 *  Os_InterruptEnableLevel()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_InterruptEnableLevel,                  /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
(
  void
))
{
  /* #10 Inform the trace module that interrupts are going to be enabled. */
  Os_TraceInterruptsLevelEnabled();

  /* #20 Check if interrupt level switching is supported: */
  if(Os_Hal_IntIsLevelSupported() != 0u)                                                                                /* COV_OS_HALPLATFORMLEVELSUPPORT */
  {
    Os_Hal_IntLevelType taskLevel;

    /* #30 Enable OS interrupts. */
    Os_Hal_IntGetTaskLevel(&taskLevel);                                                                                 /* SBSW_OS_FC_POINTER2LOCAL */
    Os_Hal_IntSetLevel(&taskLevel);                                                                                     /* SBSW_OS_FC_POINTER2LOCAL */
  }
  else
  {
    /* #40 Otherwise enable global interrupt handling. */
    Os_Hal_IntEnableGlobal();
  }

  /* #50 Tell timing protection module to stop measuring locking time. */
  Os_InterruptTpLockOsStop(Os_CoreGetThread());                                                                         /* SBSW_OS_INT_INTERRUPTTPLOCKOSSTOP_001 */
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_INTERRUPT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Interrupt.h
 **********************************************************************************************************************/
