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
 * \defgroup    Os_Isr ISR
 * \brief       ISR management.
 * \details
 * In MICROSAR OS an category 2 ISR (*ISR2*) is a thread, which is scheduled by hardware. An ISR extends a thread with
 * interrupt priority and core assignment.
 *
 * Sharing ISR Dynamic Data
 * ------------------------
 * ISRs which cannot interrupt each other can share memory for their dynamic part (ISRs which cannot interrupt each
 * other are ISRs on the same priority and not-nestable ISRs). Similar to stack sharing (see \ref StackSharing) this can
 * save a lot of memory (e.g. 200 ISRs on the same priority consume only one dynamic ISR part). As a drawback, it is not
 * possible to reinit the ISR for the next run on the ISRs exit. Because we don't know which ISR will use the dynamic
 * part next. For this reason ISRs have to be initialized right before they are executed, which results in a slightly
 * longer response time.
 *
 * We use the HAL interface functions for this:
 * - Os_Hal_ContextInit()
 * - Os_Hal_ContextSetParameter()
 * - Os_Hal_ContextSetUserMsrBits()
 * - Os_Hal_ContextCallOnStack()
 * - Os_Hal_ContextReturn()
 *
 * They respect that ISRs have no waiting state and are always started from the beginning. Context reinitialization can
 * be skipped. Os_Hal_ContextInit() loads the (initial) context configuration directly.
 * Os_Hal_ContextReturn() does not need to reinitialize the current context. If hardware needs some kind of
 * cleanup (e.g. release CSAs) this can be done here.
 *
 * Runtime View
 * ------------
 * There are four different control flows during ISR handling:
 *
 * ### Simple ISR Handling ###
 * The current thread, has been interrupted by an ISR.
 *
 * Low level ISR handling is done by \ref Os_Irq_Isr(). High level ISR handling is done by two kernel functions:
 * - \ref Os_IsrRun()
 * - \ref Os_IsrEpilogue()
 *
 * ![ISR Handling](Isr_Handling.png)
 *
 * ### ISR Handling With Task Switch ###
 * While executing ISR task scheduling has been changed.
 *
 * If a task switch is needed after the ISR user function returns, \ref Os_IsrEpilogue() directly switches to the next
 * task, without restoring the interrupted task first. If the interrupted task is resumed again, execution
 * resumes after \ref Os_Hal_ContextCallOnStack().
 *
 * Mind that the return to the task is performed by the HAL specific epilogue of \ref Os_Irq_Isr().
 *
 * ![ISR Handling with Task Switch](ISR_HandlingWithTaskSwitch.png)
 *
 * ### ISR Suicide ###
 * Termination which has been triggered inside the current ISR. Self termination can be triggered in the following
 * cases:
 * - As part of a **protection reaction**.
 * - Self termination as part of TerminateApplication().
 *
 * ![ISR Suicide](Isr_Suicide.png)
 *
 * ### Killing nested ISRs ###
 * Killing of a nested ISR can be triggered:
 * - As part of a **protection reaction**.
 * - As part of TerminateApplication().
 *
 * ![Nested ISR Killed](Isr_NestedIsrKilled.png)
 *
 *
 *
 * \see \ref Inheritance
 * \see \ref StackSharing
 * \see \ref Os_Thread
 * \see \ref Os_Hal_Context
 * \see \ref Os_Hal_Entry
 *
 *  \trace      CREQ-355
 *  \trace      SPEC-63925
 *
 * \{
 *
 * \file
 * \brief   Internal interface for category 2 ISR management.
 * \details --no details--
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_ISRINT_H
# define OS_ISRINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Isr_Types.h"
# include "Os_Isr_Lcfg.h"

/* Os kernel module dependencies */
# include "Os_Thread_Types.h"
# include "Os_ThreadInt.h"
# include "Os_Lcfg.h"
# include "Os_AccessCheck_Types.h"

/* Os hal dependencies */
# include "Os_Hal_InterruptInt.h"


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/*! Type cast from Os_IsrType to Os_ThreadType by use of base element addressing. */
#define OS_ISR_CASTDYN_ISR_2_THREAD(isr)    (&((isr).Thread))                                                           /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */



/*! Type cast from Os_IsrConfigType to Os_IsrConfigType by use of base element addressing. */
#define OS_ISR_CASTCONFIG_ISR_2_ISR(isr)               (&(isr))                                                         /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/*! Dynamic management information of a category 2 ISR.
 * \extends Os_ThreadType_Tag
 */
struct Os_IsrType_Tag
{
  /*! The dynamic thread information of this ISR.
   * This attribute must come first! */
  Os_ThreadType Thread;

  /*! Flag to remember whether an ISR has been killed.
   * It influences behavior in Os_IsrEpilogue(). */
  boolean IsKilled;
};


/*! Configuration information of a category 2 ISR.
 *  \details
 *  The dynamic data pointer of an ISR can be fetched with Os_IsrGetDyn().
 *  \extends Os_ThreadConfigType_Tag
 */
struct Os_IsrConfigType_Tag
{
 /*! The thread attributes of this ISR.
  * This attribute must come first! */
  Os_ThreadConfigType Thread;

  /*! Hardware specific ISR configuration. */
  P2CONST(Os_Hal_IntIsrConfigType, TYPEDEF, OS_CONST) HwConfig;

  /*! The ID of the ISR. */
  ISRType Id;

  /*! Defines whether or not the ISR shall be enabled by API function Os_InitialEnableInterruptSources() */
  boolean IsEnabledOnInitialization;
};


/*! Configuration information of a category 1 ISR. */
struct Os_IsrCat1ConfigType_Tag
{
  /*! Hardware specific ISR configuration. */
  P2CONST(Os_Hal_IntIsrConfigType, TYPEDEF, OS_CONST) HwConfig;
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
 *  Os_IsrInit()
 **********************************************************************************************************************/
/*! \brief          Initialize the given ISR (Init-Step4).
 *  \details        The kernel uses this function to initialize the given ISR during OS initialization.
 *
 *  \param[in,out]  Isr  The ISR which shall be initialized. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different ISRs.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_IsrInit
(
  P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) Isr
);


/***********************************************************************************************************************
 *  Os_IsrThread2Isr()
 **********************************************************************************************************************/
/*! \brief          Translate thread reference to an ISR.
 *  \details        --no details--
 *
 *  \param[in]      Thread     Thread to translate. Parameter must not be NULL and must be an ISR thread.
 *
 *  \return         The ISR belonging to the given thread.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_IsrThread2Isr,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_IsrId2Isr()
 **********************************************************************************************************************/
/*! \brief          Returns the ISR belonging to the given id.
 *  \details        --no details--
 *
 *  \param[in]      IsrId        The id of the searched ISR. The IsrId must be smaller than OS_ISRID_COUNT.
 *
 *  \return         The ISR belonging to the given id.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_IsrId2Isr,
(
  ISRType IsrId
));


/***********************************************************************************************************************
 *  Os_IsrCheckId()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given ID is valid (Not OS_CHECK_FAILED) or not (OS_CHECK_FAILED).
 *  \details        In case that extended checks are disabled, the default result of \ref Os_ErrExtendedCheck() is
 *                  returned.
 *
 *  \param[in]      IsrId        The ID to check.
 *
 *  \retval         Not OS_CHECK_FAILED   If the given ID is valid.
 *  \retval         OS_CHECK_FAILED       If the given ID is not valid.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_IsrCheckId,
(
  ISRType IsrId
));


/***********************************************************************************************************************
 *  Os_IsrHal2CoreIntLevel()
 **********************************************************************************************************************/
/*! \brief          Converts the given HAL interrupt level into a core level.
 *  \details        --no details-
 *
 *  \param[in,out]  Level        The core level. Parameter must not be NULL.
 *  \param[in]      HalLevel     The HAL level. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_IsrHalIntLevel2CoreIntLevel,
(
  P2VAR(Os_IntLevelType, AUTOMATIC, AUTOMATIC) Level,
  P2CONST(Os_Hal_IntLevelType, AUTOMATIC, OS_CONST) HalLevel
));


/***********************************************************************************************************************
 *  Os_IsrKill()
 **********************************************************************************************************************/
/*! \brief          Kill the given ISR.
 *  \details        Set kill flag of the given ISR and kill its thread.
 *                  The kernel uses this function to terminate a foreign ISR.
 *
 *  \param[in,out]  Isr   ISR which shall be killed. Parameter must not be NULL.
 *
 *  \context        ISR2
 *
 *  \reentrant      TRUE for different ISRs.
 *  \synchronous    TRUE
 *
 *  \trace          CREQ-21
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            ISR has not finished processing.
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_IsrKill
(
  P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) Isr
);


/***********************************************************************************************************************
 *  Os_IsrSuicide()
 **********************************************************************************************************************/
/*! \brief          Self termination of current ISR.
 *  \details        Execute the ISR epilogue.
 *
 *  \context        ISR2
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            The current thread is an ISR2.
 *  \pre            Os_IsrKill() has already been called.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_NORETURN OS_ALWAYS_INLINE, Os_IsrSuicide, (void));


/***********************************************************************************************************************
 *  Os_IsrDisable()
 **********************************************************************************************************************/
/*! \brief          Disable the interrupt source of the given category 2 ISR.
 *  \details        The kernel uses this function to implement TerminateApplication().
 *
 *  \param[in,out]  Isr   Category 2 ISR which shall be disabled. Parameter must not be NULL.
 *
 *  \context        TASK|ISR2|ERRHOOK
 *
 *  \reentrant      TRUE for different ISRs.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IsrDisable,
(
  P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) Isr
));


/***********************************************************************************************************************
 *  Os_IsrCat1Disable()
 **********************************************************************************************************************/
/*! \brief          Disable the interrupt source of the given category 1 ISR.
 *  \details        The kernel uses this function to implement TerminateApplication().
 *
 *  \param[in,out]  Isr   Category 1 ISR which shall be disabled. Parameter must not be NULL.
 *
 *  \context        TASK|ISR2|ERRHOOK
 *
 *  \reentrant      TRUE for different ISRs.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IsrCat1Disable,
(
  P2CONST(Os_IsrCat1ConfigType, AUTOMATIC, OS_CONST) Isr
));


/***********************************************************************************************************************
 *  Os_IsrRun()
 **********************************************************************************************************************/
/*! \brief          Prologue for ISR user functions.
 *  \details
 *  Suspends the current thread and prepares the environment for the given ISR.
 *  This function is typically executed on the stack of the interrupted thread.
 *
 *  \param[in,out]  Isr   ISR which shall be executed. Parameter must not be NULL.
 *
 *  \context        TASK|ISR2
 *
 *  \reentrant      TRUE for different ISRs.
 *  \synchronous    TRUE
 *
 *  \pre            Executed on the interrupted stack.
 *  \pre            Called on the interrupt priority level of the given ISR.
 *
 *  \trace          CREQ-115, CREQ-846
 *  \trace          SPEC-63775, SPEC-63778, SPEC-63851
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_IsrRun
(
  P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) Isr
);


/***********************************************************************************************************************
 *  Os_IsrEpilogue()
 **********************************************************************************************************************/
/*! \brief        Epilogue for ISR user functions.
 *  \details      Cleanup environment after ISR has been executed. Signal the hardware the end of interrupt (EOI).
 *                Switch to the next thread.
 *                The next thread might be the thread, which has been interrupted by the ISR or another one
 *                (e.g. if a task switch is requested).
 *                This function shall be executed after an ISR user function returns.
 *                This function is used as the return address of the ISR user function.
 *                This function is executed on the stack where the ISR user function is executed.
 *                This function never returns.
 *
 *  \context      ISR2|OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          The current thread is an ISR2.
 *
 *  \trace        CREQ-115
 *  \trace        SPEC-63796, SPEC-63785, SPEC-63881, SPEC-64061
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(void, OS_CODE, OS_NORETURN, Os_IsrEpilogue, (void));


/***********************************************************************************************************************
 *  Os_IsrEpilogueTp()
 **********************************************************************************************************************/
/*! \brief        Epilogue for timing protection ISR function.
 *  \details      Cleanup environment after ISR has been executed. Signal the hardware the end of interrupt (EOI).
 *                Switch to the next thread.
 *                The next thread might be the thread, which has been interrupted by the ISR or another one
 *                (e.g. if a task switch is requested).
 *                This function shall be executed after a TP ISR returns
 *                This function is used as the return address of the TP ISR function.
 *                This function is executed on the stack where the TP ISR function is executed.
 *                This function never returns.
 *
 *  \context      ISR2|OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          The current thread is a TP ISR.
 *
 *  \trace        CREQ-115
 *  \trace        SPEC-63796, SPEC-63785, SPEC-63881, SPEC-64061
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(void, OS_CODE, OS_NORETURN, Os_IsrEpilogueTp, (void));


/***********************************************************************************************************************
 *  Os_IsrLevelIsLe()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given ISR has an interrupt priority level, which is lower than or equal to
 *                  the given interrupt priority level.
 *  \details        --no details--
 *
 *  \param[in]      Isr     The ISR which shall be checked. Parameter must not be NULL.
 *  \param[in]      Level   The interrupt priority level to compare with. Parameter must not be NULL.
 *
 *  \retval         !0  The configured interrupt priority level of Isr is logically lower than or equal to Level.
 *  \retval         0   The configured interrupt priority level of Isr is logically greater than Level.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_IsrLevelIsLe,
(
  P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) Isr,
  P2CONST(Os_IntLevelType, AUTOMATIC, OS_CONST) Level
));


/***********************************************************************************************************************
 *  Os_IsrGetThread()
 **********************************************************************************************************************/
/*! \brief          Returns the thread of an ISR.
 *  \details        --no details--
 *
 *  \param[in]      Isr         ISR to query. Parameter must not be NULL.
 *
 *  \return         Pointer to the ISR's thread.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_IsrGetThread,
(
  P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) Isr
));


/***********************************************************************************************************************
 *  Os_IsrGetAccessRights()
 **********************************************************************************************************************/
/*! \brief          Returns the access rights of the given ISR.
 *  \details        --no details--
 *
 *  \param[in]      Isr         ISR to query. Parameter must not be NULL.
 *
 *  \return         Pointer to the ISR's access rights.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_AccessCheckConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_IsrGetAccessRights,
(
  P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) Isr
));


/***********************************************************************************************************************
 *  Os_IsrInitialEnable()
 **********************************************************************************************************************/
/*! \brief          Initially enable the given ISR.
 *  \details        --no details--
 *
 *  \param[in]      Isr    ISR to enable. Parameter must not be NULL.
 *  \param[in]      ClearPending  Defines whether the pending flag shall be cleared (TRUE) or not (FALSE).
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_IsrInitialEnable,
(
  P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) Isr,
  boolean ClearPending
));


/***********************************************************************************************************************
 *  Os_IsrClearPendingIfRequested()
 **********************************************************************************************************************/
/*! \brief        Clear pending interrupts in accordance to the parameter ClearPending.
 *
 *  \param[in]    Isr           The ISR to clear pending interrupts for. Parameter must not be NULL.
 *  \param[in]    ClearPending  Defines whether the pending flag of the ISRs shall be cleared (TRUE) or not (FALSE).
 *
 *  \return       -
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_IsrClearPendingIfRequested,
(
  P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) Isr,
  boolean ClearPending
));



/***********************************************************************************************************************
 *  Os_Api_GetISRID()
 **********************************************************************************************************************/
/*! \brief        OS service GetISRID().
 *  \details      For further details see GetISRID().
 *
 *  \return       See GetISRID().
 *
 *  \context      TASK|ISR2|ERRHOOK|PROTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See GetISRID().
 *
 *  \trace        CREQ-16
 *  \trace        SPEC-63782, SPEC-63918, SPEC-63962, SPEC-64002, SPEC-63980
 **********************************************************************************************************************/
FUNC(ISRType, OS_CODE) Os_Api_GetISRID(void);


/***********************************************************************************************************************
 *  Os_Api_DisableInterruptSource()
 **********************************************************************************************************************/
/*! \brief        OS service Os_DisableInterruptSource().
 *  \details      For further details see Os_DisableInterruptSource().
 *
 *  \param[in]    ISRID   Category 2 ISR which shall be disabled.
 *
 *  \retval         OS_STATUS_OK              No error.
 *  \retval         OS_STATUS_CALLEVEL        (EXTENDED status:) Called from invalid context.
 *  \retval         OS_STATUS_ID_1            (EXTENDED status:) Invalid ISRID.
 *  \retval         OS_STATUS_NOT_THE_OWNER_1 (Service Protection:) The current application is not the interrupt owner.
 *
 *  \context        TASK|ISR2|ERRHOOK
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre          For further details see Os_DisableInterruptSource().
 *
 *  \trace          CREQ-106181
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_DisableInterruptSource(ISRType ISRID);


/***********************************************************************************************************************
 *  Os_Api_EnableInterruptSource()
 **********************************************************************************************************************/
/*! \brief        OS service Os_EnableInterruptSource().
 *  \details      For further details see Os_EnableInterruptSource().
 *
 *  \param[in]    ISRID   Category 2 ISR which shall be enabled.
 *  \param[in]    ClearPending  Defines whether the pending flag shall be cleared (TRUE) or not (FALSE).
 *
 *  \retval         OS_STATUS_OK                                               No error.
 *  \retval         OS_STATUS_UNIMPLEMENTED_CLEARPENDING (EXTENDED status:)    Hardware does not support to clear
 *                                                                             pending interrupts.
 *  \retval         OS_STATUS_CALLEVEL                   (EXTENDED status:)    Called from invalid context.
 *  \retval         OS_STATUS_ID_1                       (EXTENDED status:)    Invalid ISRID.
 *  \retval         OS_STATUS_NOT_THE_OWNER_1            (Service Protection:) The current application is not the
 *                                                                             owner of the ISR.
 *  \retval         OS_STATUS_VALUE_IS_NOT_BOOLEAN       (EXTENDED status:)    ClearPending is neither TRUE nor FALSE.
 *
 *  \context        TASK|ISR2
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre          See Os_EnableInterruptSource().
 *
 *  \trace          CREQ-106182
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_EnableInterruptSource(ISRType ISRID, boolean ClearPending);


/***********************************************************************************************************************
 *  Os_Api_InitialEnableInterruptSources()
 **********************************************************************************************************************/
/*! \brief        OS service Os_InitialEnableInterruptSources().
 *  \details      For further information see Os_InitialEnableInterruptSources().
 *
 *  \param[in]    ClearPending  Defines whether the pending flag of the ISRs shall be cleared (TRUE) or not (FALSE).
 *
 *  \return       OS_STATUS_OK                                             No error.
 *                OS_STATUS_UNIMPLEMENTED_CLEARPENDING (EXTENDED status:)  Hardware does not support to clear
 *                                                                         pending interrupts.
 *                OS_STATUS_CALLEVEL                   (EXTENDED status:)  Called from invalid context.
 *                OS_STATUS_VALUE_IS_NOT_BOOLEAN       (EXTENDED status:)  ClearPending is neither TRUE nor FALSE.
 *
 *  \context      TASK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See Os_InitialEnableInterruptSources()
 *
 *  \trace        CREQ-183488
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_InitialEnableInterruptSources(boolean ClearPending);


/***********************************************************************************************************************
 *  Os_Api_ClearPendingInterrupt()
 **********************************************************************************************************************/
/*! \brief        OS service Os_ClearPendingInterrupt().
 *  \details      For further details see Os_ClearPendingInterrupt().
 *
 *  \param[in]    ISRID         Category 2 ISR that's pending flag shall be cleared.
 *
 *  \retval         OS_STATUS_OK                                               No error.
 *  \retval         OS_STATUS_UNIMPLEMENTED_CLEARPENDING (EXTENDED status:)    Hardware does not support to clear
 *                                                                             pending  interrupts.
 *  \retval         OS_STATUS_CALLEVEL                   (EXTENDED status:)    Called from invalid context.
 *  \retval         OS_STATUS_ID_1                       (EXTENDED status:)    Invalid ISRID.
 *  \retval         OS_STATUS_NOT_THE_OWNER_1            (Service Protection:) The current application is not the
 *                                                                             owner of the ISR.
 *
 *  \context        TASK|ISR2
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \trace          CREQ-106183
 *
 *  \pre            See Os_ClearPendingInterrupt().
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_ClearPendingInterrupt(ISRType ISRID);


/***********************************************************************************************************************
 *  Os_Api_IsInterruptSourceEnabled()
 **********************************************************************************************************************/
/*! \brief        OS service Os_IsInterruptSourceEnabled().
 *  \details      For further details see Os_IsInterruptSourceEnabled().
 *
 *  \param[in]    ISRID      Category 2 ISR that shall be checked if enabled or not.
 *  \param[out]   IsEnabled  Defines whether the source of the ISR is enabled (TRUE) or not (FALSE).
 *
 *  \retval         OS_STATUS_OK                                          No error.
 *  \retval         OS_STATUS_PARAM_POINTER_2       (EXTENDED status:)    Pointer to the IsEnabled variable set to NULL.
 *  \retval         OS_STATUS_CALLEVEL              (EXTENDED status:)    Called from invalid context.
 *  \retval         OS_STATUS_ID_1                  (EXTENDED status:)    Invalid ISRID.
 *  \retval         OS_STATUS_NOT_THE_OWNER_1       (Service Protection:) The current application is not the
 *                                                                        owner of the ISR.
 *
 *  \context        TASK|ISR2
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            See Os_IsInterruptSourceEnabled().
 *
 *  \trace          CREQ-114872
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_IsInterruptSourceEnabled(ISRType ISRID,
                                                             P2VAR(boolean, AUTOMATIC, OS_VAR_NOINIT) IsEnabled);


/***********************************************************************************************************************
 *  Os_Api_IsInterruptPending()
 **********************************************************************************************************************/
/*! \brief        OS service Os_IsInterruptPending().
 *  \details      For further details see Os_IsInterruptPending().
 *
 *  \param[in]    ISRID      Category 2 ISR that shall be checked if has been requested.
 *  \param[out]   IsPending  Defines whether the given ISR request is pending (TRUE) or not (FALSE).
 *
 *  \retval         OS_STATUS_OK                                          No error.
 *  \retval         OS_STATUS_PARAM_POINTER_2       (EXTENDED status:)    Pointer to the IsPending variable set to NULL.
 *  \retval         OS_STATUS_CALLEVEL              (EXTENDED status:)    Called from invalid context.
 *  \retval         OS_STATUS_ID_1                  (EXTENDED status:)    Invalid ISRID.
 *  \retval         OS_STATUS_NOT_THE_OWNER_1       (Service Protection:) The current application is not the
 *                                                                        owner of the ISR.
 *  \retval         OS_STATUS_UNIMPLEMENTED_CLEARPENDING (EXTENDED status:)  Hardware does not support to clear
 *                                                                           pending  interrupts.
 *  \context        TASK|ISR2
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            See Os_IsInterruptPending().
 *
 *  \trace          CREQ-114873
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_IsInterruptPending(ISRType ISRID,
                                                       P2VAR(boolean, AUTOMATIC, OS_VAR_NOINIT) IsPending);


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/



# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_ISRINT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_IsrInt.h
 **********************************************************************************************************************/
