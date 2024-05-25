/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**
 * \addtogroup Os_Interrupt
 * \{
 *
 * \file
 * \brief       Implementation of the interrupt module.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777, 0779, 0828  EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */


#define OS_INTERRUPT_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Interrupt.h"

/* Os module dependencies */
#include "Os_Thread.h"
#include "Os_TimingProtection.h"
#include "Os_Error.h"
#include "Os_Core.h"
#include "Os_Interrupt_Cfg.h"

/* Os Hal dependencies */
#include "Os_Hal_Compiler.h"
#include "Os_Hal_Core.h"


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
 *  Os_InterruptCheckNotInCriticalSection()
 **********************************************************************************************************************/
/*! \brief        Returns whether the caller is in a critical section (OS_CHECK_FAILED) or not (Not OS_CHECK_FAILED).
 *  \details      --no details--
 *
 *  \param[in]    InterruptState   The interrupt state to check. Parameter must not be NULL.
 *
 *  \retval       Not OS_CHECK_FAILED   Not in critical section.
 *  \retval       OS_CHECK_FAILED       In critical section.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_InterruptCheckNotInCriticalSection,
(
  P2CONST(Os_IntApiStateType, AUTOMATIC, OS_VAR_NOINIT) InterruptState
));


/***********************************************************************************************************************
 *  Os_InterruptDisableAllEnter()
 **********************************************************************************************************************/
/*! \brief          Sets the in "DisableAll" flag.
 *  \details        --no details--
 *
 *  \param[in,out]  InterruptState   The interrupt state to modify. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_InterruptDisableAllEnter,
(
  P2VAR(Os_IntApiStateType, AUTOMATIC, OS_VAR_NOINIT) InterruptState
));


/***********************************************************************************************************************
 *  Os_InterruptDisableAllExit()
 **********************************************************************************************************************/
/*! \brief          Clears the in "DisableAll" flag.
 *  \details        --no details--
 *
 *  \param[in,out]  InterruptState   The interrupt state to modify. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_InterruptDisableAllExit,
(
  P2VAR(Os_IntApiStateType, AUTOMATIC, OS_VAR_NOINIT) InterruptState
));


/***********************************************************************************************************************
 *  Os_InterruptCheckInDisableAll()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given interrupt state object is not in a disable-all critical section
 *                  (OS_CHECK_FAILED) or (Not OS_CHECK_FAILED).
 *  \details        --no details--
 *
 *  \param[in]      InterruptState   The interrupt state to modify. Parameter must not be NULL.
 *
 *  \retval         Not OS_CHECK_FAILED   In disable all.
 *  \retval         OS_CHECK_FAILED       Not in disable all.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_InterruptCheckInDisableAll,
(
  P2CONST(Os_IntApiStateType, AUTOMATIC, OS_VAR_NOINIT) InterruptState
));


/***********************************************************************************************************************
 *  Os_InterruptCheckNotInDisableAll()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given interrupt state object is in a disable-all critical section
 *                  (OS_CHECK_FAILED) or (Not OS_CHECK_FAILED).
 *  \details        --no details--
 *
 *  \param[in]      InterruptState   The interrupt state to modify. Parameter must not be NULL.
 *
 *  \retval         Not OS_CHECK_FAILED   Not in disable all.
 *  \retval         OS_CHECK_FAILED       In disable all.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_InterruptCheckNotInDisableAll,
(
  P2CONST(Os_IntApiStateType, AUTOMATIC, OS_VAR_NOINIT) InterruptState
));


/***********************************************************************************************************************
 *  Os_InterruptCheckInSuspendAll()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given interrupt state object is not in a "SuspendAll" critical section
 *                  (OS_CHECK_FAILED) or (Not OS_CHECK_FAILED).
 *  \details        --no details--
 *
 *  \param[in,out]  InterruptState   The interrupt state to modify. Parameter must not be NULL.
 *
 *  \retval         Not OS_CHECK_FAILED   In "SuspendAll".
 *  \retval         OS_CHECK_FAILED       Not in "SuspendAll".
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_InterruptCheckInSuspendAll,
(
  P2CONST(Os_IntApiStateType, AUTOMATIC, OS_VAR_NOINIT) InterruptState
));


/***********************************************************************************************************************
 *  Os_InterruptCheckNoOverflow()
 **********************************************************************************************************************/
/*! \brief        Returns whether the given nesting counter is greater zero (Not OS_CHECK_FAILED) or
 *                not (OS_CHECK_FAILED).
 *  \details      --no details--
 *
 *  \param[in]    InterruptState   The interrupt state to check.
 *
 *  \retval       Not OS_CHECK_FAILED   Greater zero.
 *  \retval       OS_CHECK_FAILED       zero.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_InterruptCheckNoOverflow,
(
  Os_IntApiCntType Counter
));


/***********************************************************************************************************************
 *  Os_InterruptCheckInSuspendOs()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given interrupt state object is not in a "SuspendOs" critical section
 *                  (OS_CHECK_FAILED) or (Not OS_CHECK_FAILED).
 *  \details        --no details--
 *
 *  \param[in,out]  InterruptState   The interrupt state to modify. Parameter must not be NULL.
 *
 *  \retval         Not OS_CHECK_FAILED   In "SuspendAll".
 *  \retval         OS_CHECK_FAILED       Not in "SuspendAll".
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_InterruptCheckInSuspendOs,
(
  P2CONST(Os_IntApiStateType, AUTOMATIC, OS_VAR_NOINIT) InterruptState
));


/***********************************************************************************************************************
 *  Os_InterruptTakeSnapshot()
 **********************************************************************************************************************/
/*! \brief          Takes a snapshot of the given counter, if service protection is enabled.
 *  \details        --no details--
 *
 *  \param[in,out]  Snapshot  Snapshot where the counter value shall be stored. Parameter must not be NULL.
 *  \param[in]      Counter   Counter value.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_InterruptTakeSnapshot,
(
  P2VAR(Os_IntApiCntType, AUTOMATIC, OS_VAR_NOINIT) Snapshot,
  Os_IntApiCntType Counter
));


/***********************************************************************************************************************
 *  Os_InterruptCheckSnapshot()
 **********************************************************************************************************************/
/*! \brief        Returns whether the given snapshot and the counter are identical (Not OS_CHECK_FAILED) or not
 *                (OS_CHECK_FAILED).
 *  \details      --no details--
 *
 *  \param[in]    Snapshot  Previous snapshot of the counter.
 *  \param[in]    Counter   Counter value.
 *
 *  \retval       Not OS_CHECK_FAILED   Identical.
 *  \retval       OS_CHECK_FAILED       Not identical.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Os_InterruptTakeSnapshot() has been called with same parameters previously.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_InterruptCheckSnapshot,
(
  Os_IntApiCntType Snapshot,
  Os_IntApiCntType Counter
));


/***********************************************************************************************************************
 *  Os_IntSuspendCat1()
 **********************************************************************************************************************/
/*! \brief          Suspend all ISRs of categories 1 and 2.
 *  \details        Disable core local interrupt delivery of category 1+2 ISRs and return previous state.
 *                  Prevent to change the interrupt level in case that would allow more interrupts to occur.
 *
 *  \param[out]     Cat1State Previous interrupt state information which allows resuming cat1 interrupt handling in HAL.
 *                            Parameter must not be NULL.
 *
 *  \context        ANY
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_IntSuspendCat1,
(
  P2VAR(Os_IntStateType, AUTOMATIC, OS_APPL_DATA) Cat1State
));


/***********************************************************************************************************************
 *  Os_IntResumeCat1()
 **********************************************************************************************************************/
/*! \brief          Resume all ISRs of categories 1 and 2.
 *  \details        Enable core local interrupt delivery of category 1+2 ISRs and return previous state.
 *
 *  \param[in]     Cat1State  Interrupt state information retrieved by Os_IntSuspendCat1 which allows resuming
 *                            cat1 interrupt handling in HAL. Parameter must not be NULL.
 *
 *  \context        ANY
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_IntResumeCat1,
(
  P2CONST(Os_IntStateType, AUTOMATIC, OS_APPL_DATA) Cat1State
));


/***********************************************************************************************************************
 *  Os_IntSuspendCat2()
 **********************************************************************************************************************/
/*! \brief          Suspend all category 2 ISRs.
 *  \details        Disable core local interrupt delivery of category 2 ISRs and return previous state.
 *                  Prevent to change the interrupt level in case that would allow more interrupts to occur.
 *                  If interrupt level switching is not supported, interrupts are disabled globally.
 *
 *  \param[out]     State   Previous interrupt state information which allows resuming cat2 interrupt handling in HAL.
 *                          Parameter must not be NULL.
 *
 *  \context        ANY
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_IntSuspendCat2,
(
  P2VAR(Os_IntStateType, AUTOMATIC, OS_APPL_DATA) State
));


/***********************************************************************************************************************
 *  Os_IntResumeCat2()
 **********************************************************************************************************************/
/*! \brief          Resume all ISRs of category 2.
 *  \details        Enable core local interrupt delivery of category 2 ISRs and return previous state.
 *                  If interrupt level switching is not supported, interrupts are resumed globally.
 *
 *  \param[in]      Cat2State  Interrupt state information retrieved by Os_IntSuspendCat2 which allows resuming
 *                             cat2 interrupt handling in HAL. Parameter must not be NULL.
 *
 *  \context        ANY
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_IntResumeCat2,
(
  P2CONST(Os_IntStateType, AUTOMATIC, OS_APPL_DATA) Cat2State
));


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  Os_InterruptCheckNotInCriticalSection()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_InterruptCheckNotInCriticalSection,
(
  P2CONST(Os_IntApiStateType, AUTOMATIC, OS_VAR_NOINIT) InterruptState
))
{
  return Os_ErrServiceProtectionCheck((Os_StdReturnType)((                                                              /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
                                                  (Os_StdReturnType)(InterruptState->Os_IntLockingState.InDisableAll) |
                                                  InterruptState->Os_IntLockingState.SuspendAllCounter |
                                                  InterruptState->Os_IntLockingState.SuspendOsCounter) == 0u));
}


/***********************************************************************************************************************
 *  Os_InterruptDisableAllEnter()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_InterruptDisableAllEnter,
(
  P2VAR(Os_IntApiStateType, AUTOMATIC, OS_VAR_NOINIT) InterruptState
))
{
  if(Os_InterruptIsCriticalSectionTracingEnabled() != 0u)
  {
    InterruptState->Os_IntLockingState.InDisableAll = 1;                                                                /* SBSW_OS_PWA_PRECONDITION */
  }
}


/***********************************************************************************************************************
 *  Os_InterruptDisableAllExit()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_InterruptDisableAllExit,
(
  P2VAR(Os_IntApiStateType, AUTOMATIC, OS_VAR_NOINIT) InterruptState
))
{
  if(Os_InterruptIsCriticalSectionTracingEnabled() != 0u)
  {
    InterruptState->Os_IntLockingState.InDisableAll = 0;                                                                /* SBSW_OS_PWA_PRECONDITION */
  }
}


/***********************************************************************************************************************
 *  Os_InterruptCheckInDisableAll()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_InterruptCheckInDisableAll,
(
  P2CONST(Os_IntApiStateType, AUTOMATIC, OS_VAR_NOINIT) InterruptState
))
{
  return Os_ErrServiceProtectionCheck((Os_StdReturnType)(InterruptState->Os_IntLockingState.InDisableAll == 1u));       /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_InterruptCheckNotInDisableAll()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_InterruptCheckNotInDisableAll,
(
  P2CONST(Os_IntApiStateType, AUTOMATIC, OS_VAR_NOINIT) InterruptState
))
{
  return Os_ErrServiceProtectionCheck((Os_StdReturnType)(InterruptState->Os_IntLockingState.InDisableAll == 0u));       /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_InterruptCheckInSuspendAll()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_InterruptCheckInSuspendAll,
(
  P2CONST(Os_IntApiStateType, AUTOMATIC, OS_VAR_NOINIT) InterruptState
))
{
  return Os_ErrServiceProtectionCheck((Os_StdReturnType)(InterruptState->Os_IntLockingState.SuspendAllCounter != 0u));  /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_InterruptCheckInSuspendOs()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_InterruptCheckInSuspendOs,
(
  P2CONST(Os_IntApiStateType, AUTOMATIC, OS_VAR_NOINIT) InterruptState
))
{
  return Os_ErrServiceProtectionCheck((Os_StdReturnType)(InterruptState->Os_IntLockingState.SuspendOsCounter != 0u));   /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_InterruptCheckNoOverflow()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_InterruptCheckNoOverflow,
(
  Os_IntApiCntType Counter
))
{
  return Os_ErrServiceProtectionCheck((Os_StdReturnType)(Counter > 0u));                                                /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_InterruptTakeSnapshot()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_InterruptTakeSnapshot,
(
  P2VAR(Os_IntApiCntType, AUTOMATIC, OS_VAR_NOINIT) Snapshot,
  Os_IntApiCntType Counter
))
{
  *Snapshot = Counter;                                                                                                  /* SBSW_OS_PWA_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_InterruptCheckSnapshot()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_InterruptCheckSnapshot,
(
  Os_IntApiCntType Snapshot,
  Os_IntApiCntType Counter
))
{
  return Os_ErrServiceProtectionCheck((Os_StdReturnType)(Snapshot == Counter));                                         /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}





/***********************************************************************************************************************
 *  Os_IntSuspendCat1()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_IntSuspendCat1,
(
  P2VAR(Os_IntStateType, AUTOMATIC, OS_APPL_DATA) Cat1State
))
{
  /* #10 Check if interrupt locking via level is needed: */
  if(Os_InterruptLockOnLevelIsNeeded() != 0u)                                                                           /* COV_OS_HALPLATFORMLEVELSUPPORT */
  {
    /* #20 Fetch current state and disable up category 1 ISRs if required. */
    Os_Hal_IntLevelType cat1DisableLevel;
    Os_Hal_IntLevelType levelState;

    Os_Hal_IntGetCat1LockLevel(&cat1DisableLevel);                                                                      /* SBSW_OS_FC_POINTER2LOCAL */
    Os_Hal_IntGetLevel(&levelState);                                                                                    /* SBSW_OS_FC_POINTER2LOCAL */

    if(Os_Hal_IntLevelIsGt(&cat1DisableLevel, &levelState) != 0u)                                                       /* SBSW_OS_FC_POINTER2LOCAL */
    {
      Os_Hal_IntSetLevel(&cat1DisableLevel);                                                                            /* SBSW_OS_FC_POINTER2LOCAL */
    }
    Cat1State->Level = levelState;                                                                                      /* SBSW_OS_PWA_PRECONDITION */
  }
  /* #30 Otherwise fetch current state and disable globally. */
  else
  {
    Cat1State->Global = Os_Hal_IntDisableAndReturnGlobalState();                                                        /* SBSW_OS_PWA_PRECONDITION */
  }
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_IntResumeCat1()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_IntResumeCat1,
(
  P2CONST(Os_IntStateType, AUTOMATIC, OS_APPL_DATA) Cat1State
))
{
  /* #10 If level lock is needed restore previous state level based. */
  if(Os_InterruptLockOnLevelIsNeeded() != 0u)                                                                           /* COV_OS_HALPLATFORMLEVELSUPPORT */
  {
    Os_Hal_IntSetLevel(&(Cat1State->Level));                                                                            /* SBSW_OS_FC_PRECONDITION */
  }
  /* #20 Otherwise restore previous state based on global state. */
  else
  {
    Os_Hal_IntSetGlobalState(&(Cat1State->Global));                                                                     /* SBSW_OS_FC_PRECONDITION */
  }
}


/***********************************************************************************************************************
 *  Os_IntSuspendCat2()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_IntSuspendCat2,
(
  P2VAR(Os_IntStateType, AUTOMATIC, OS_APPL_DATA) State
))
{
  /* #10 If interrupt level switching is supported: */
  if(Os_Hal_IntIsLevelSupported() != 0u)                                                                                /* COV_OS_HALPLATFORMLEVELSUPPORT */
  {
    Os_Hal_IntLevelType cat2DisableLevel;
    Os_Hal_IntLevelType levelState;

    /* #20 Get the level which has to be set to disable category2 interrupt handling. */
    Os_Hal_IntGetCat2LockLevel(&cat2DisableLevel);                                                                      /* SBSW_OS_FC_POINTER2LOCAL */
    /* #30 Get and store the current level from HAL. */
    Os_Hal_IntGetLevel(&levelState);                                                                                    /* SBSW_OS_FC_POINTER2LOCAL */

    /* #40 If the category 2 disable level is logically higher than the current level: */
    if(Os_Hal_IntLevelIsGt(&cat2DisableLevel, &levelState) != 0u)                                                       /* SBSW_OS_FC_POINTER2LOCAL */
    {
      /* #50 Call HAL method to disable level based. */
      Os_Hal_IntSetLevel(&cat2DisableLevel);                                                                            /* SBSW_OS_FC_POINTER2LOCAL */
    }
    State->Level = levelState;                                                                                          /* SBSW_OS_PWA_PRECONDITION */
  }
  else
  {
    /* #60 Otherwise disable global interrupt handling. */
    State->Global = Os_Hal_IntDisableAndReturnGlobalState();                                                            /* SBSW_OS_PWA_PRECONDITION */
  }
}


/***********************************************************************************************************************
 *  Os_IntResumeCat2()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_IntResumeCat2,
(
  P2CONST(Os_IntStateType, AUTOMATIC, OS_APPL_DATA) Cat2State
))
{
  /* #10 If level lock is needed restore previous state level based. */
  if(Os_Hal_IntIsLevelSupported() != 0u)                                                                                /* COV_OS_HALPLATFORMLEVELSUPPORT */
  {
    Os_Hal_IntSetLevel(&(Cat2State->Level));                                                                            /* SBSW_OS_FC_PRECONDITION */
  }
  /* #20 Otherwise restore previous state based on global state. */
  else
  {
    Os_Hal_IntSetGlobalState(&(Cat2State->Global));                                                                     /* SBSW_OS_FC_PRECONDITION */
  }
}


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_InterruptInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_InterruptInit
(
  P2VAR(Os_IntApiStateType, TYPEDEF, OS_VAR_NOINIT) IntApiState
)
{

  if(Os_InterruptIsCriticalSectionTracingEnabled() != 0u)
  {
    /* #10 Set all critical section flags to zero. */
    IntApiState->Os_IntLockingState.InDisableAll = 0;                                                                   /* SBSW_OS_PWA_PRECONDITION */
  }

  /* #20 Set the nesting counter for SuspendAll to zero. */
  IntApiState->Os_IntLockingState.SuspendAllCounter = 0;                                                                /* SBSW_OS_PWA_PRECONDITION */

  /* #30 Set the nesting counter for SuspendOS to zero. */
  IntApiState->Os_IntLockingState.SuspendOsCounter = 0;                                                                 /* SBSW_OS_PWA_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_Api_DisableAllInterrupts()
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
FUNC(void, OS_CODE) Os_Api_DisableAllInterrupts
(
  void
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) caller;
  P2VAR(Os_IntApiStateType, AUTOMATIC, OS_VAR_NOINIT) interruptApiState;

  caller = Os_CoreGetThread();
  interruptApiState = Os_ThreadGetInterruptApiState(caller);                                                            /* SBSW_OS_INT_THREADGETINTERRUPTAPISTATE_001 */

  /* #10 Check that no interrupt API has been called previously. */
  if(OS_UNLIKELY(Os_InterruptCheckNotInCriticalSection(interruptApiState) == OS_CHECK_FAILED))                          /* SBSW_OS_INT_INTERRUPTCHECKNOTINCRITICALSECTION_001 */
  {
    /*! Internal comment removed.
 *
 * */
    status = OS_STATUS_API_ERROR;
  }
  else
  {
    /* #20 Tell timing protection module to start measuring locking time. */
    Os_InterruptTpLockAllStart(caller);                                                                                 /* SBSW_OS_INT_INTERRUPTTPLOCKALLSTART_001 */

    /* #30 Save current interrupt state and disable up to cat1 ISRs. */
    Os_IntSuspendCat1(&(interruptApiState->SuspendAllPrevState));                                                       /* SBSW_OS_INT_INTSUSPENDCAT1_001 */

    /* #40 Inform the trace module that interrupts have been disabled */
    Os_TraceInterruptsGlobalDisabled();

    /* #50 Remember that we are in a DisableAllInterrupts() sequence so we are able to detect invalid service calls. */
    Os_InterruptDisableAllEnter(interruptApiState);                                                                     /* SBSW_OS_INT_INTERRUPTDISABLEALLENTER_001 */

    status = OS_STATUS_OK;
  }

  /* #60 Report error if applicable or return. */
  Os_ErrReportDisableAllInterrupts(status);
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_Api_EnableAllInterrupts()
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
FUNC(void, OS_CODE) Os_Api_EnableAllInterrupts
(
  void
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) caller;
  P2VAR(Os_IntApiStateType, AUTOMATIC, OS_VAR_NOINIT) interruptApiState;

  caller = Os_CoreGetThread();
  interruptApiState = Os_ThreadGetInterruptApiState(caller);                                                            /* SBSW_OS_INT_THREADGETINTERRUPTAPISTATE_001 */

  /* #10 Check that DisableAllInterrupts() has been called previously. */
  if(OS_UNLIKELY(Os_InterruptCheckInDisableAll(interruptApiState) == OS_CHECK_FAILED))                                  /* SBSW_OS_INT_INTERRUPTCHECKINDISABLEALL_001 */
  {
    status = OS_STATUS_API_ERROR;
  }
  else
  {
    /* #20 Remember that we left the interrupt critical section. */
    Os_InterruptDisableAllExit(interruptApiState);                                                                      /* SBSW_OS_INT_INTERRUPTDISABLEALLEXIT_001 */

    /* #30 Inform the trace module that interrupts are going to be enabled */
    Os_TraceInterruptsGlobalEnabled();

    /* #40 Restore the interrupt state which has been saved in DisableAllInterrupts(). */
    Os_IntResumeCat1(&interruptApiState->SuspendAllPrevState);                                                          /* SBSW_OS_INT_INTRESUMECAT1_001 */

    /* #50 Tell timing protection module to stop measuring locking time. */
    Os_InterruptTpLockAllStop(caller);                                                                                  /* SBSW_OS_INT_INTERRUPTTPLOCKALLSTOP_001 */

    status = OS_STATUS_OK;
  }

  /* #60 Report error if applicable or return. */
  Os_ErrReportEnableAllInterrupts(status);
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */



/***********************************************************************************************************************
 *  Os_Api_SuspendAllInterrupts()
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
FUNC(void, OS_CODE) Os_Api_SuspendAllInterrupts
(
  void
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) caller;
  P2VAR(Os_IntApiStateType, AUTOMATIC, OS_VAR_NOINIT) interruptApiState;

  caller = Os_CoreGetThread();
  interruptApiState = Os_ThreadGetInterruptApiState(caller);                                                            /* SBSW_OS_INT_THREADGETINTERRUPTAPISTATE_001 */

  /* #10 Check that DisableAllInterrupts() has not been called previously. */
  if(OS_UNLIKELY(Os_InterruptCheckNotInDisableAll(interruptApiState) == OS_CHECK_FAILED))                               /* SBSW_OS_INT_INTERRUPTCHECKNOTINCRITICALSECTION_001 */
  {
    status = OS_STATUS_API_ERROR;
  }
  else
  {
    /* #20 If SuspendAllInterrupts() nesting counter is zero: */
    if(interruptApiState->Os_IntLockingState.SuspendAllCounter == 0u)
    {
      /* #30 Tell timing protection module to start measuring locking time. */
      Os_InterruptTpLockAllStart(caller);                                                                               /* SBSW_OS_INT_INTERRUPTTPLOCKALLSTART_001 */

      /* #40 Save current interrupt state and disable up to cat1 ISRs. */
      Os_IntSuspendCat1(&interruptApiState->SuspendAllPrevState);                                                       /* SBSW_OS_INT_INTSUSPENDCAT1_001 */

      /* #50 Inform trace module that interrupts have been disabled */
      Os_TraceInterruptsGlobalDisabled();

      /* #60 Take SuspendOS nesting counter snapshot. */
      Os_InterruptTakeSnapshot(&interruptApiState->SuspendOsSnapshot,
                                                   interruptApiState->Os_IntLockingState.SuspendOsCounter);             /* SBSW_OS_INT_INTERRUPTTAKESNAPSHOT_001 */
    }

    /* #70 Increment the nesting counter for SuspendAllInterrupts() calls. */
    interruptApiState->Os_IntLockingState.SuspendAllCounter++;                                                          /* SBSW_OS_INT_THREADGETINTERRUPTAPISTATE_002 */

    /* #80 Check that there is no counter overflow. */
    if(OS_UNLIKELY(Os_InterruptCheckNoOverflow(                                                                         /* COV_OS_INTCOUNTEROVERFLOW */
            interruptApiState->Os_IntLockingState.SuspendAllCounter) == OS_CHECK_FAILED))
    {
      status = OS_STATUS_API_ERROR;
    }
    else
    {
      status = OS_STATUS_OK;
    }
  }

  /* #90 Report error if applicable or return. */
  Os_ErrReportSuspendAllInterrupts(status);
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_Api_ResumeAllInterrupts()
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
FUNC(void, OS_CODE) Os_Api_ResumeAllInterrupts
(
  void
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) caller;
  P2VAR(Os_IntApiStateType, AUTOMATIC, OS_VAR_NOINIT) interruptApiState;

  caller = Os_CoreGetThread();
  interruptApiState = Os_ThreadGetInterruptApiState(caller);                                                            /* SBSW_OS_INT_THREADGETINTERRUPTAPISTATE_001 */

  /* #10 Check that SuspendAllInterrupts() has been called previously. */
  if(OS_UNLIKELY(Os_InterruptCheckInSuspendAll(interruptApiState) == OS_CHECK_FAILED))                                  /* SBSW_OS_INT_INTERRUPTCHECKINSUSPENDALL_001 */
  {
    status = OS_STATUS_API_ERROR;
  }
  else
  {
    /* #20 Decrement the nesting counter for SuspendAllInterrupts() calls. */
    interruptApiState->Os_IntLockingState.SuspendAllCounter--;                                                          /* SBSW_OS_INT_THREADGETINTERRUPTAPISTATE_002 */

    /* #30 If the nesting counter is zero: */
    if (interruptApiState->Os_IntLockingState.SuspendAllCounter == 0u)
    {
      /* #40 Check whether the user did open/close a SuspendOSInterrupts() pair meanwhile. */
      if(OS_UNLIKELY(Os_InterruptCheckSnapshot(interruptApiState->SuspendOsSnapshot,
              interruptApiState->Os_IntLockingState.SuspendOsCounter) == OS_CHECK_FAILED))
      {
        status = OS_STATUS_API_ERROR;
      }
      else
      {
        /* #50 Inform the trace module that interrupts are going to be enabled */
        Os_TraceInterruptsGlobalEnabled();

        /* #60 Restore the interrupt state which has been saved in SuspendAllInterrupts(). */
        Os_IntResumeCat1(&interruptApiState->SuspendAllPrevState);                                                      /* SBSW_OS_INT_INTRESUMECAT1_001 */

        /* #70 Tell timing protection module to stop measuring locking time. */
        Os_InterruptTpLockAllStop(caller);                                                                              /* SBSW_OS_INT_INTERRUPTTPLOCKALLSTOP_001 */

        status = OS_STATUS_OK;
      }
    }
    else
    {
      status = OS_STATUS_OK;
    }
  }

  /* #80 Report error if applicable or return. */
  Os_ErrReportResumeAllInterrupts(status);
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_Api_SuspendOSInterrupts()
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
FUNC(void, OS_CODE) Os_Api_SuspendOSInterrupts
(
  void
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) caller;
  P2VAR(Os_IntApiStateType, AUTOMATIC, OS_VAR_NOINIT) interruptApiState;

  caller = Os_CoreGetThread();
  interruptApiState = Os_ThreadGetInterruptApiState(caller);                                                            /* SBSW_OS_INT_THREADGETINTERRUPTAPISTATE_001 */

  /* #10 Check that DisableAllInterrupts() has not been called previously. */
  if(OS_UNLIKELY(Os_InterruptCheckNotInDisableAll(interruptApiState) == OS_CHECK_FAILED))                               /* SBSW_OS_INT_INTERRUPTCHECKNOTINDISABLEALL_001 */
  {
    status = OS_STATUS_API_ERROR;
  }
  else
  {
    /* #20 If SuspendOSInterrupts() nesting counter is zero: */
    if (interruptApiState->Os_IntLockingState.SuspendOsCounter == 0u)
    {
      /* #30 Tell timing protection module to start measuring locking time. */
      Os_InterruptTpLockOsStart(caller);                                                                                /* SBSW_OS_INT_INTERRUPTTPLOCKOSSTART_001 */

      /* #40 Save current interrupt state and disable up to cat2 ISRs. */
      Os_IntSuspendCat2(&interruptApiState->SuspendOsPrevState);                                                        /* SBSW_OS_INT_INTSUSPENDCAT2_001 */

      /* #50 Inform the trace module that interrupts have been disabled. */
      Os_TraceInterruptsLevelDisabled();

      /* #60 Take SuspendAll nesting counter snapshot. */
      Os_InterruptTakeSnapshot(&interruptApiState->SuspendAllSnapshot,
                                                    interruptApiState->Os_IntLockingState.SuspendAllCounter);           /* SBSW_OS_INT_INTERRUPTTAKESNAPSHOT_001 */
    }

    /* #70 Increment the nesting counter for SuspendOSInterrupts() calls. */
    interruptApiState->Os_IntLockingState.SuspendOsCounter++;                                                           /* SBSW_OS_INT_THREADGETINTERRUPTAPISTATE_002 */

    /* #80 Check that there is no counter overflow. */
    if(OS_UNLIKELY(Os_InterruptCheckNoOverflow(                                                                         /* COV_OS_INTCOUNTEROVERFLOW */
            interruptApiState->Os_IntLockingState.SuspendOsCounter) == OS_CHECK_FAILED))
    {
      status = OS_STATUS_API_ERROR;
    }
    else
    {
      status = OS_STATUS_OK;
    }
  }

  /* #90 Report error if applicable or return. */
  Os_ErrReportSuspendOSInterrupts(status);
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_Api_ResumeOSInterrupts()
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
FUNC(void, OS_CODE) Os_Api_ResumeOSInterrupts
(
  void
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) caller;
  P2VAR(Os_IntApiStateType, AUTOMATIC, OS_VAR_NOINIT) interruptApiState;

  caller = Os_CoreGetThread();
  interruptApiState = Os_ThreadGetInterruptApiState(caller);                                                            /* SBSW_OS_INT_THREADGETINTERRUPTAPISTATE_001 */

  /* #10 Check that SuspendOSInterrupts() has been called previously. */
  if(OS_UNLIKELY(Os_InterruptCheckInSuspendOs(interruptApiState) == OS_CHECK_FAILED))                                   /* SBSW_OS_INT_INTERRUPTCHECKINSUSPENDOS_001 */
  {
    status = OS_STATUS_API_ERROR;
  }
  else
  {
    /* #20 Decrement the nesting counter for SuspendOSInterrupts() calls. */
    interruptApiState->Os_IntLockingState.SuspendOsCounter--;                                                           /* SBSW_OS_INT_THREADGETINTERRUPTAPISTATE_002 */

    /* #30 If the nesting counter is zero: */
    if (interruptApiState->Os_IntLockingState.SuspendOsCounter == 0u)
    {
      /* #40 Check whether the user did open/close a SuspendAllInterrupts() pair meanwhile. */
      if(OS_UNLIKELY(Os_InterruptCheckSnapshot(interruptApiState->SuspendAllSnapshot,
              interruptApiState->Os_IntLockingState.SuspendAllCounter) == OS_CHECK_FAILED))
      {
        status = OS_STATUS_API_ERROR;
      }
      else
      {
        /* #50 Inform the trace module that interrupts are going to be enabled. */
        Os_TraceInterruptsLevelEnabled();

        /* #60 Restore the interrupt state which has been saved in SuspendOSInterrupts(). */
        Os_IntResumeCat2(&(interruptApiState->SuspendOsPrevState));                                                     /* SBSW_OS_INT_INTRESUMECAT2_001 */

        /* #70 Tell timing protection module to stop measuring locking time. */
        Os_InterruptTpLockOsStop(caller);                                                                               /* SBSW_OS_INT_INTERRUPTTPLOCKOSSTOP_001 */

        status = OS_STATUS_OK;
      }
    }
    else
    {
      status = OS_STATUS_OK;
    }
  }

  /* #80 Report error if applicable or return. */
  Os_ErrReportResumeOSInterrupts(status);
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_Api_DisableGlobal()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
FUNC(void, OS_CODE) Os_Api_DisableGlobal
(
  void
)
{
  Os_InterruptDisableGlobal();
}


/***********************************************************************************************************************
 *  Os_Api_EnableGlobal()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
FUNC(void, OS_CODE) Os_Api_EnableGlobal
(
  void
)
{
  Os_InterruptEnableGlobal();
}


/***********************************************************************************************************************
 *  Os_Api_DisableLevel()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
FUNC(void, OS_CODE) Os_Api_DisableLevel
(
  void
)
{
  Os_InterruptDisableLevel();
}


/***********************************************************************************************************************
 *  Os_Api_EnableLevel()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 */
FUNC(void, OS_CODE) Os_Api_EnableLevel
(
  void
)
{
  Os_InterruptEnableLevel();
}


#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* module specific MISRA deviations:
 */


/* SBSW_JUSTIFICATION_BEGIN

\ID SBSW_OS_INT_THREADGETINTERRUPTAPISTATE_001
 \DESCRIPTION    Os_ThreadGetInterruptApiState is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_INT_THREADGETINTERRUPTAPISTATE_002
 \DESCRIPTION    Write access to the return value of Os_ThreadGetInterruptApiState.
 \COUNTERMEASURE \M [CM_OS_THREADGETINTERRUPTAPISTATE_M]

\ID SBSW_OS_INT_INTERRUPTTPLOCKALLSTART_001
 \DESCRIPTION    Os_InterruptTpLockAllStart is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_INT_INTERRUPTTPLOCKOSSTART_001
 \DESCRIPTION    Os_InterruptTpLockOsStart is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_INT_INTERRUPTCHECKNOTINCRITICALSECTION_001
 \DESCRIPTION    Os_InterruptCheckNotInCriticalSection is called with the return value of Os_ThreadGetInterruptApiState.
 \COUNTERMEASURE \M [CM_OS_THREADGETINTERRUPTAPISTATE_M]

\ID SBSW_OS_INT_INTERRUPTCHECKNOOVERFLOW_001
 \DESCRIPTION    Os_InterruptCheckNoOverflow is called with the return value of Os_ThreadGetInterruptApiState.
 \COUNTERMEASURE \M [CM_OS_THREADGETINTERRUPTAPISTATE_M]

\ID SBSW_OS_INT_INTERRUPTCHECKNOTINDISABLEALL_001
 \DESCRIPTION    Os_InterruptCheckNotInDisableAll is called with the return value of Os_ThreadGetInterruptApiState.
 \COUNTERMEASURE \M [CM_OS_THREADGETINTERRUPTAPISTATE_M]

\ID SBSW_OS_INT_INTERRUPTTAKESNAPSHOT_001
 \DESCRIPTION    Os_InterruptTakeSnapshot is called with the return value of Os_ThreadGetInterruptApiState.
 \COUNTERMEASURE \M [CM_OS_THREADGETINTERRUPTAPISTATE_M]

\ID SBSW_OS_INT_INTERRUPTCHECKSNAPSHOT_001
 \DESCRIPTION    Os_InterruptCheckSnapshot is called with the return value of Os_ThreadGetInterruptApiState.
 \COUNTERMEASURE \M [CM_OS_THREADGETINTERRUPTAPISTATE_M]

\ID SBSW_OS_INT_INTSUSPENDCAT1_001
 \DESCRIPTION    Os_IntSuspendCat1 is called with a value derived from the return value of
                 Os_ThreadGetInterruptApiState.
 \COUNTERMEASURE \M [CM_OS_THREADGETINTERRUPTAPISTATE_M]

\ID SBSW_OS_INT_INTSUSPENDCAT2_001
 \DESCRIPTION    Os_IntSuspendCat2 is called with a value derived from the return value of
                 Os_ThreadGetInterruptApiState.
 \COUNTERMEASURE \M [CM_OS_THREADGETINTERRUPTAPISTATE_M]

\ID SBSW_OS_INT_INTERRUPTDISABLEALLENTER_001
 \DESCRIPTION    Os_InterruptDisableAllEnter is called with the return value of Os_ThreadGetInterruptApiState.
 \COUNTERMEASURE \M [CM_OS_THREADGETINTERRUPTAPISTATE_M]

\ID SBSW_OS_INT_INTERRUPTCHECKINDISABLEALL_001
 \DESCRIPTION    Os_InterruptCheckInDisableAll is called with the return value of Os_ThreadGetInterruptApiState.
 \COUNTERMEASURE \M [CM_OS_THREADGETINTERRUPTAPISTATE_M]

\ID SBSW_OS_INT_INTERRUPTCHECKINSUSPENDALL_001
 \DESCRIPTION    Os_InterruptCheckInSuspendAll is called with the return value of Os_ThreadGetInterruptApiState.
 \COUNTERMEASURE \M [CM_OS_THREADGETINTERRUPTAPISTATE_M]

\ID SBSW_OS_INT_INTERRUPTCHECKINSUSPENDOS_001
 \DESCRIPTION    Os_InterruptCheckInSuspendOs is called with the return value of Os_ThreadGetInterruptApiState.
 \COUNTERMEASURE \M [CM_OS_THREADGETINTERRUPTAPISTATE_M]

\ID SBSW_OS_INT_INTERRUPTDISABLEALLEXIT_001
 \DESCRIPTION    Os_InterruptDisableAllExit is called with the return value of Os_ThreadGetInterruptApiState.
 \COUNTERMEASURE \M [CM_OS_THREADGETINTERRUPTAPISTATE_M]

\ID SBSW_OS_INT_INTRESUMECAT1_001
 \DESCRIPTION    Os_IntResumeCat1 is called with a value derived from the return value of
                 Os_ThreadGetInterruptApiState.
 \COUNTERMEASURE \M [CM_OS_THREADGETINTERRUPTAPISTATE_M]

\ID SBSW_OS_INT_INTRESUMECAT2_001
 \DESCRIPTION    Os_IntResumeCat2 is called with a value derived from the return value of
                 Os_ThreadGetInterruptApiState.
 \COUNTERMEASURE \M [CM_OS_THREADGETINTERRUPTAPISTATE_M]

\ID SBSW_OS_INT_INTERRUPTTPLOCKALLSTOP_001
 \DESCRIPTION    Os_InterruptTpLockAllStop is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_INT_INTERRUPTTPLOCKOSSTOP_001
 \DESCRIPTION    Os_InterruptTpLockOsStop is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_INT_TPSTARTALLINTERRUPT_001
 \DESCRIPTION    Os_TpStartAllInterrupt is called with the return value of Os_CoreAsrGetTimingProtection.
 \COUNTERMEASURE \M [CM_OS_COREASRGETTIMINGPROTECTION_M]

\ID SBSW_OS_INT_TPSTOPALLINTERRUPT_001
 \DESCRIPTION    Os_TpStopAllInterrupt is called with the return value of Os_CoreAsrGetTimingProtection.
 \COUNTERMEASURE \M [CM_OS_COREASRGETTIMINGPROTECTION_M]

\ID SBSW_OS_INT_TPSTARTOSINTERRUPT_001
 \DESCRIPTION    Os_TpStartOsInterrupt is called with the return value of Os_CoreAsrGetTimingProtection.
 \COUNTERMEASURE \M [CM_OS_COREASRGETTIMINGPROTECTION_M]

\ID SBSW_OS_INT_TPSTOPOSINTERRUPT_001
 \DESCRIPTION    Os_TpStopOsInterrupt is called with the return value of Os_CoreAsrGetTimingProtection.
 \COUNTERMEASURE \M [CM_OS_COREASRGETTIMINGPROTECTION_M]

\ID SBSW_OS_INT_COREASRGETTIMINGPROTECTION_001
 \DESCRIPTION    Os_CoreAsrGetTimingProtection is called with the return value of Os_ThreadGetCore.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

SBSW_JUSTIFICATION_END */


/* START_COVERAGE_JUSTIFICATION

\ID COV_OS_INTCOUNTEROVERFLOW
   \ACCEPT XF
   \REASON Counter overflow cannot be checked for type uint16_least as the type is quite large and
           even depends on the used compiler (+options). However, the code is unit tested and code inspected.

END_COVERAGE_JUSTIFICATION */




/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Interrupt.c
 **********************************************************************************************************************/

