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
 * \ingroup     Os_Kernel
 * \defgroup    Os_Interrupt Interrupt
 * \brief       OS services related to the current interrupt state.
 * \details
 * MICROSAR OS provides the AUTOSAR OS services for disabling/enabling and suspending/resuming interrupts.
 *
 * In addition it provides a performance optimized extension to disable/enable interrupts.
 * These APIs do not perform any checks and are not allowed to be called nested.
 * Therefore the user is responsible for correct calling of these APIs.
 *
 * \{
 *
 * \file
 * \brief       Internal interface of the interrupt module.
 * \details     --no details--
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_INTERRUPTINT_H
# define OS_INTERRUPTINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Interrupt_Types.h"

/* Os module dependencies */
# include "Os_Interrupt_Cfg.h"

/* Os kernel module dependencies */
# include "Os_CommonInt.h"
# include "Os_TimingProtection_Types.h"
# include "Os_ErrorInt.h"
# include "Os_Thread_Types.h"

/* Os HAL dependencies */
# include "Os_Hal_CompilerInt.h"
# include "Os_Hal_InterruptInt.h"


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/*! Type to count nested calls of interrupt APIs. */
typedef uint16_least Os_IntApiCntType;

/*! Tells whether the user is inside of an interrupt API sequence. */
typedef struct
{
  Os_WordType InDisableAll : 1; /*!< Inside a DisableAllInterrupts() API sequence. */
  Os_IntApiCntType SuspendAllCounter;  /*! Nesting counter for SuspendAllInterrupts()/ResumeAllInterrupts(). */
  Os_IntApiCntType SuspendOsCounter;   /*! Nesting counter for SuspendOSInterrupts()/ResumeOSInterrupts(). */
} Os_IntLockingStateType;

/*! Management information for the interrupt API. */
struct Os_IntApiStateType_Tag
{
  /*! Holds the previous interrupt state for DisableAllInterrupts() and SuspendAllInterrupts(). */
  Os_IntStateType SuspendAllPrevState;

  /*! Holds the previous interrupt level for SuspendOSInterrupts(). */
  Os_IntStateType SuspendOsPrevState;

  /*! Holds the nesting counters and flag for interrupt locking state. */
  Os_IntLockingStateType Os_IntLockingState;

  /*! \brief    Snapshot of nesting counter for SuspendAllInterrupts().
   *  \details  This is needed to detect nesting not in pairs. */
  Os_IntApiCntType SuspendAllSnapshot;

  /*! \brief    Snapshot of nesting counter for SuspendOSInterrupts().
   *  \details  This is needed to detect nesting not in pairs. */
  Os_IntApiCntType SuspendOsSnapshot;
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
 *  Os_InterruptInit()
 **********************************************************************************************************************/
/*! \brief          Initialize the given interrupt API state.
 *  \details        This function is called in Init-Step2 for the first time but also when a re-initialization of the
 *                  interrupt API state is needed.
 *
 *  \param[out]     IntApiState   State to initialize. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_InterruptInit
(
  P2VAR(Os_IntApiStateType, TYPEDEF, OS_VAR_NOINIT) IntApiState
);


/***********************************************************************************************************************
 *  Os_IntEnableGlobal()
 **********************************************************************************************************************/
/*! \brief        Enable all interrupts except NMIs.
 *  \details      -- no details --
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre         -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IntEnableGlobal, (void));


/***********************************************************************************************************************
 *  Os_IntDisableGlobal()
 **********************************************************************************************************************/
/*! \brief        Disable all interrupts global.
 *  \details      -- no details --
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IntDisableGlobal, (void));


/***********************************************************************************************************************
 *  Os_IntSuspend()
 **********************************************************************************************************************/
/*! \brief        Suspend all interrupts except category 0 ISRs including timing protection interrupt.
 *  \details      This function shall be called from anywhere in the kernel except the interrupt API functions.
 *
 *  \param[out]   State   Previous interrupt state information which allows resuming in Os_IntResume().
 *                        Parameter must not be NULL.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IntSuspend,
(
  P2VAR(Os_IntStateType, AUTOMATIC, AUTOMATIC) State
));


/***********************************************************************************************************************
 *  Os_IntResume()
 **********************************************************************************************************************/
/*! \brief        Resume interrupt level returned by Os_IntSuspend().
 *  \details      This function shall be called from anywhere in the kernel except the interrupt API functions.
 *
 *  \param[in]    State   Desired interrupt level (as provided by Os_IntSuspend). Parameter must not be NULL.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          Supervisor mode.
 *  \pre          Os_IntSuspend() has been called and prepared State parameter.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IntResume,
(
  P2CONST(Os_IntStateType, AUTOMATIC, AUTOMATIC) State
));


/***********************************************************************************************************************
 *  Os_IntDisable()
 **********************************************************************************************************************/
/*! \brief        Disable all interrupts except NMIs.
 *  \details      Call Os_Hal_IntDisable and the respective timing hook for internal interrupt disabling.
 *                This function shall be called from anywhere in the kernel except the interrupt API functions.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IntDisable,
(
  void
));


/***********************************************************************************************************************
 *  Os_InterruptCheckEnabled()
 **********************************************************************************************************************/
/*! \brief        Checks the given interrupt API state for open interrupt API calls.
 *  \details      If service protection is disabled, the default value of Os_ErrServiceProtectionCheck is returned.
 *
 *  \param[in]    InterruptState   State to check. Parameter must not be NULL.
 *
 *  \retval       OS_CHECK_FAILED       If there are open interrupts API calls and Service Protection is enabled.
 *  \retval       Not OS_CHECK_FAILED   If there are no open interrupt API calls or Service Protection is disabled.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 *
 *  \trace        SPEC-63796
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_InterruptCheckEnabled,
(
  P2CONST(Os_IntApiStateType, AUTOMATIC, OS_VAR_NOINIT) InterruptState
));


/***********************************************************************************************************************
 *  Os_InterruptCleanup()
 **********************************************************************************************************************/
/*! \brief          Cleanup the given interrupt API state.
 *  \details        Initialize interrupt API states.
 *                  Error reporting of open interrupt API calls shall be done by the caller.
 *                  Because error reporting depends on the situation: In case of killing we don't need further error
 *                  reporting. Interrupt state/level fix should be done by the caller (dependent whether we cleanup
 *                  an ISR/Task or Hook).
 *
 *  \param[in,out]  InterruptState   Interrupt API state to inspect. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 *
 *  \trace          SPEC-63796, SPEC-63730
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_InterruptCleanup,
(
  P2VAR(Os_IntApiStateType, AUTOMATIC, OS_VAR_NOINIT) InterruptState
));


/***********************************************************************************************************************
 *  Os_InterruptCopy()
 **********************************************************************************************************************/
/*! \brief        Copies the interrupt state from Source to Destination.
 *  \details      --no details--
 *
 *  \param[in,out]    Source        The interrupt state to be copy. Parameter must not be NULL.
 *  \param[in,out]    Destination   The object to copy to. Parameter must not be NULL.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_InterruptCopy,
(
  P2CONST(Os_IntApiStateType, AUTOMATIC, OS_VAR_NOINIT) Source,
  P2VAR(Os_IntApiStateType, AUTOMATIC, OS_VAR_NOINIT) Destination
));


/***********************************************************************************************************************
 *  Os_InterruptIsCriticalSectionTracingEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether Service Tracing is enabled (!0) or not (0).
 *  \details      --no details--
 *
 *  \retval       !0    Enabled.
 *  \retval       0     Disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_InterruptIsCriticalSectionTracingEnabled, (void));


/***********************************************************************************************************************
 *  Os_IntIsGlobal2LevelSwitchSupported()
 **********************************************************************************************************************/
/*! \brief        Returns whether the platform supports the global disable to level lock switch (!0) or not (0).
 *  \details      --no details--
 *
 *  \retval       !0    Supported.
 *  \retval       0     Not supported.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_IntIsGlobal2LevelSwitchSupported, (void));


/***********************************************************************************************************************
 *  Os_Api_DisableAllInterrupts()
 **********************************************************************************************************************/
/*! \brief        OS service DisableAllInterrupts().
 *  \details      For further details see DisableAllInterrupts
 *
 *  \context      TASK|ISR2|ERRHOOK|PRETHOOK|POSTTHOOK|STARTHOOK|SHUTHOOK|ALARMHOOK|PROTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See DisableAllInterrupts().
 *
 *  \trace        CREQ-111, CREQ-40, CREQ-847, CREQ-31, CREQ-103, CREQ-131845
 *  \trace        SPEC-64187, SPEC-64188, SPEC-63877, SPEC-63867
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Api_DisableAllInterrupts
(
  void
);


/***********************************************************************************************************************
 *  Os_Api_EnableAllInterrupts()
 **********************************************************************************************************************/
/*! \brief        OS service EnableAllInterrupts().
 *  \details      For further details see EnableAllInterrupts().
 *
 *  \context      TASK|ISR2|ERRHOOK|PRETHOOK|POSTTHOOK|STARTHOOK|SHUTHOOK|ALARMHOOK|PROTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See EnableAllInterrupts().
 *
 *  \trace        CREQ-43, CREQ-40, CREQ-847, CREQ-31, CREQ-103, CREQ-131845
 *  \trace        SPEC-64189, SPEC-64192, SPEC-63697, SPEC-64188, SPEC-63951, SPEC-63867
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Api_EnableAllInterrupts
(
  void
);


/***********************************************************************************************************************
 *  Os_Api_SuspendAllInterrupts()
 **********************************************************************************************************************/
/*! \brief        OS service SuspendAllInterrupts().
 *  \details      For further details see SuspendAllInterrupts().
 *
 *  \context      TASK|ISR2|ERRHOOK|PRETHOOK|POSTTHOOK|STARTHOOK|SHUTHOOK|ALARMHOOK|PROTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See SuspendAllInterrupts().
 *
 *  \trace        CREQ-154, CREQ-40, CREQ-847, CREQ-31, CREQ-103, CREQ-131845
 *  \trace        SPEC-64197, SPEC-64195, SPEC-64196, SPEC-63739, SPEC-63867
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Api_SuspendAllInterrupts
(
  void
);


/***********************************************************************************************************************
 *  Os_Api_ResumeAllInterrupts()
 **********************************************************************************************************************/
/*! \brief        OS service ResumeAllInterrupts().
 *  \details      For further details see ResumeAllInterrupts().
 *
 *  \context      TASK|ISR2|ERRHOOK|PRETHOOK|POSTTHOOK|STARTHOOK|SHUTHOOK|ALARMHOOK|PROTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See ResumeAllInterrupts().
 *
 *  \trace        CREQ-98, CREQ-40, CREQ-847, CREQ-31, CREQ-103, CREQ-131845
 *  \trace        SPEC-64193, SPEC-64191, SPEC-63697, SPEC-63780, SPEC-63867
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Api_ResumeAllInterrupts
(
  void
);


/***********************************************************************************************************************
 *  Os_Api_SuspendOSInterrupts()
 **********************************************************************************************************************/
/*! \brief        OS service SuspendOSInterrupts().
 *  \details      For further details see SuspendOSInterrupts().
 *
 *  \context      TASK|ISR2|ERRHOOK|PRETHOOK|POSTTHOOK|STARTHOOK|SHUTHOOK|ALARMHOOK|PROTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See SuspendOSInterrupts().
 *
 *  \trace        CREQ-151, CREQ-40, CREQ-847, CREQ-31, CREQ-103, CREQ-131845
 *  \trace        SPEC-64199, SPEC-64194, SPEC-64198, SPEC-63912, SPEC-63867
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Api_SuspendOSInterrupts
(
  void
);


/***********************************************************************************************************************
 *  Os_Api_ResumeOSInterrupts()
 **********************************************************************************************************************/
/*! \brief        OS service ResumeOSInterrupts().
 *  \details      For further details see ResumeOSInterrupts().
 *
 *  \context      TASK|ISR2|ERRHOOK|PRETHOOK|POSTTHOOK|STARTHOOK|SHUTHOOK|ALARMHOOK|PROTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See ResumeOSInterrupts().
 *
 *  \trace        CREQ-82, CREQ-40, CREQ-847, CREQ-31, CREQ-103, CREQ-131845
 *  \trace        SPEC-64200, SPEC-64190, SPEC-63697, SPEC-63817, SPEC-63867
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Api_ResumeOSInterrupts
(
  void
);


/***********************************************************************************************************************
 *  Os_Api_DisableGlobal()
 **********************************************************************************************************************/
/*! \brief        OS service DisableGlobal().
 *  \details      Disables the recognition status of all interrupts. This service does not perform nesting
 *                nor service protection checks.
 *
 *  \context      TASK|ISR2|ERRHOOK|PRETHOOK|POSTTHOOK|STARTHOOK|SHUTHOOK|ALARMHOOK|PROTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 *
 *  \trace        CREQ-1256, CREQ-1257, CREQ-108741, CREQ-847, CREQ-31, CREQ-103, CREQ-131845
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Api_DisableGlobal
(
  void
);


/***********************************************************************************************************************
 *  Os_Api_EnableGlobal()
 **********************************************************************************************************************/
/*! \brief        OS service EnableGlobal().
 *  \details      Enables the recognition status of all interrupts. This service does not perform nesting
 *                nor service protection checks.
 *
 *  \context      TASK|ISR2|ERRHOOK|PRETHOOK|POSTTHOOK|STARTHOOK|SHUTHOOK|ALARMHOOK|PROTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 *
 *  \trace        CREQ-1258, CREQ-1259, CREQ-108742, CREQ-847, CREQ-31, CREQ-103, CREQ-131845
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Api_EnableGlobal
(
  void
);


/***********************************************************************************************************************
 *  Os_Api_DisableLevel()
 **********************************************************************************************************************/
/*! \brief        OS service DisableLevel().
 *  \details      Disables the recognition status of category 2 interrupts. This service does not perform nesting
 *                nor service protection checks.
 *
 *  \context      TASK|ISR2|ERRHOOK|PRETHOOK|POSTTHOOK|STARTHOOK|SHUTHOOK|ALARMHOOK|PROTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 *
 *  \trace        CREQ-108744, CREQ-108743, CREQ-108745, CREQ-847, CREQ-31, CREQ-103, CREQ-131845
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Api_DisableLevel
(
  void
);


/***********************************************************************************************************************
 *  Os_Api_EnableLevel()
 **********************************************************************************************************************/
/*! \brief        OS service EnableLevel().
 *  \details      Enables the recognition status of category 2 interrupts. This service does not perform nesting
 *                nor service protection checks.
 *
 *  \context      TASK|ISR2|ERRHOOK|PRETHOOK|POSTTHOOK|STARTHOOK|SHUTHOOK|ALARMHOOK|PROTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 *
 *  \trace        CREQ-108747, CREQ-108748, CREQ-108746, CREQ-847, CREQ-31, CREQ-103, CREQ-131845
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Api_EnableLevel
(
  void
);


/***********************************************************************************************************************
 *  Os_InterruptIsCat0Enabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether Cat0 Isrs are enabled (!0) or not (0).
 *  \details      --no details--
 *
 *  \retval       !0    Enabled.
 *  \retval       0     Disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_InterruptIsCat0Enabled, (void));


/***********************************************************************************************************************
 *  Os_InterruptLockOnLevelIsNeeded()
 **********************************************************************************************************************/
/*! \brief        Returns whether interrupt locking on level is needed (!0) or not (0).
 *  \details      If Cat 0 ISRs or timing protection are enabled it is not allowed to use the global interrupt flag.
 *
 *  \retval       !0    Enabled.
 *  \retval       0     Disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,
OS_ALWAYS_INLINE, Os_InterruptLockOnLevelIsNeeded, (void));


/***********************************************************************************************************************
 *  Os_InterruptSaveAndIncrease()
 **********************************************************************************************************************/
/*! \brief          Save the current interrupt state in the given state variable and disable interrupt handling up
 *                  to the requested level.
 *  \details        If interrupt priority level switching is supported, the current level is updated only if the
 *                  requested level is higher.
 *                  If interrupt priority level switching is not supported, interrupt handling is disabled globally.
 *
 *  \param[out]     CurrentState  The state to be written with the current interrupt state. Parameter must not be NULL.
 *  \param[in]      IncreaseLevel The level for priority comparison. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_InterruptSaveAndIncrease,
(
  P2VAR(Os_IntStateType, AUTOMATIC, AUTOMATIC) CurrentState,
  P2CONST(Os_Hal_IntLevelType, AUTOMATIC, OS_CONST) IncreaseLevel
));


/***********************************************************************************************************************
 *  Os_InterruptRestore()
 **********************************************************************************************************************/
/*! \brief          Restores the previous interrupt state.
 *  \details        If interrupt priority level switching is supported, the level is not changed, if the previous level
 *                  is not logically lower than the current priority.
 *                  If interrupt priority level switching is not supported, the previous global flag is restored.
 *
 *  \param[in]      PreviousIntState    The requested interrupt state of the caller. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Os_InterruptSaveAndIncrease was called before.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_InterruptRestore,
(
  P2CONST(Os_IntStateType, AUTOMATIC, OS_VAR_NOINIT) PreviousIntState
));


/***********************************************************************************************************************
 *  Os_InterruptTpLockAllStart()
 **********************************************************************************************************************/
/*! \brief          Starts "all-interrupts" blocking time monitoring for given thread.
 *  \details        --no details--
 *
 *  \param[in]      Thread   Thread which shall be used as the budget owner. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_InterruptTpLockAllStart,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_InterruptTpLockAllStop()
 **********************************************************************************************************************/
/*! \brief          Stop "all-interrupts" blocking time monitoring for given thread.
 *  \details        --no details--
 *
 *  \param[in]      Thread   Thread which shall be used as the budget owner. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_InterruptTpLockAllStop,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_InterruptTpLockOsStart()
 **********************************************************************************************************************/
/*! \brief          Starts "OS-interrupts" blocking time monitoring for given thread.
 *  \details        --no details--
 *
 *  \param[in]      Thread   Thread which shall be used as the budget owner. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_InterruptTpLockOsStart,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_InterruptTpLockOsStop()
 **********************************************************************************************************************/
/*! \brief          Stop "OS-interrupts" blocking time monitoring for given thread.
 *  \details        --no details--
 *
 *  \param[in]      Thread   Thread which shall be used as the budget owner. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_InterruptTpLockOsStop,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_InterruptDisableGlobal()
 **********************************************************************************************************************/
/*! \brief        Disables the recognition status of all interrupts.
 *  \details      This service does not perform nesting nor service protection checks.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_InterruptDisableGlobal,
(
  void
));


/***********************************************************************************************************************
 *  Os_InterruptEnableGlobal()
 **********************************************************************************************************************/
/*! \brief        Enables the recognition status of all interrupts.
 *  \details      This service does not perform nesting nor service protection checks.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_InterruptEnableGlobal,
(
  void
));


/***********************************************************************************************************************
 *  Os_InterruptDisableLevel()
 **********************************************************************************************************************/
/*! \brief        Disables the recognition status of category 2 interrupts.
 *  \details      This service does not perform nesting nor service protection checks.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_InterruptDisableLevel,
(
  void
));


/***********************************************************************************************************************
 *  Os_InterruptEnableLevel()
 **********************************************************************************************************************/
/*! \brief        Enables the recognition status of category 2 interrupts.
 *  \details      This service does not perform nesting nor service protection checks.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_InterruptEnableLevel,
(
  void
));


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_INTERRUPTINT_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_InterruptInt.h
 **********************************************************************************************************************/
