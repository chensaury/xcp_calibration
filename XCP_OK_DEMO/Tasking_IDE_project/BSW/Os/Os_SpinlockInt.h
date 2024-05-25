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
 * \defgroup    Os_Spinlock Spinlock
 * \brief       Provides a multicore synchronization mechanism.
 *
 * \details
 * This module provides the spinlock API defined by AUTOSAR OS.
 *
 * Introduction
 * ---------------------------------------------------------------------------------------------------------------------
 * A spinlock is a cross core synchronization mechanism where the TASK waits in a loop ("spins") repeatedly checking
 * for a shared variable to become a certain value. The value indicates whether the lock is free or not. In Multi-Core
 * systems the comparison and changing of the variable typically requires an atomic operation. As the TASK remains
 * active but is not doing anything useful, a spinlock is a busy waiting mechanism.
 * The number of spinlocks is limited to 255 by \ref Os_SpinlockOrderType.
 *
 * The user has to configure all participants which may occupy a spinlock.
 *
 * ### Optimized Spinlocks
 * Depending on the user configuration, the configuration values
 *  - Mode,
 *  - Trace and
 *  - Check
 *
 * have to be set. The following table shows, which setting has to be chosen depending on
 *  - the spinlock type,
 *  - whether killing is supported,
 *  - the selected lock method.
 *
 *
 * Type       | Killing       |  Method    |  Mode  |  Trace   |  Check
 * :--------- | :------------ |:---------: | :----: | :------: | :-----:
 * AUTOSAR    | don't care    | don't care | SUPER. | ENABLED  | ENABLED
 * OPTIMIZED  | disabled      | NOTHING    |  USER  | DISABLED | DISABLED
 * OPTIMIZED  | disabled      | NOT NOTHING| SUPER. | DISABLED | DISABLED
 * OPTIMIZED  | enabled       | don't care | SUPER. | ENABLED  | DISABLED
 *
 * If optimized spinlocks are used, the application is responsible for the correct mapping of the spinlock variable.
 * For each optimized spinlock a separate section is provided (see \ref SectionDescription_SPINLOCK_x_VAR_NOCACHE).
 *
 * ### Spinlock Order
 * To avoid deadlocks, Spinlocks have to be locked in a defined sequence. This sequence is defined by the spinlock
 * order number. Spinlocks with lower order numbers may not be locked by threads which already hold locks of higher
 * order numbers.
 *
 * ### Nesting With Resources
 * The resource API and spinlock API can be used together in a mixed nested fashion
 * (e.g. GetResource(), GetSpinlock(), GetResource(), ...). Nesting has to be strictly LIFO.
 *
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 * \trace     CREQ-15
 * \trace     SPEC-63619
 * \{
 *
 * \file
 * \brief     Provides the OS internal interface.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_SPINLOCKINT_H
# define OS_SPINLOCKINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Spinlock_Lcfg.h"
# include "Os_Spinlock_Types.h"

/* Os kernel module dependencies */
# include "Os_Cfg.h"
# include "Os_Common_Types.h"
# include "Os_LockInt.h"
# include "Os_Thread_Types.h"
# include "Os_Scheduler_Types.h"
# include "Os_Trace_Types.h"
# include "Os_ErrorInt.h"
# include "Os_InterruptInt.h"

/* Os hal dependencies */
# include "Os_Hal_CoreInt.h"
# include "Os_Hal_CompilerInt.h"




/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
/*! End marker of linked list of spinlocks. */
#define OS_SPINLOCK_LIST_END            ((P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST))(NULL_PTR))

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/*! Type cast from \ref Os_SpinlockType to \ref Os_LockType by use of base element addressing. */
#define OS_SPINLOCK_CASTDYN_SPINLOCK_2_LOCK(spinlock)  (&((spinlock).Lock))                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/*! Lock methods which can be used when a spinlock is taken. */
typedef enum
{
  /*! Disable all interrupts. */
  OS_SPINLOCKMETHOD_ALL_INT,
  /*! Disable up to Cat. 2 interrupts. */
  OS_SPINLOCKMETHOD_CAT2,
  /*! Disable task switching. */
  OS_SPINLOCKMETHOD_SCHEDULER,
  /*! Disable nothing, just get the lock. */
  OS_SPINLOCKMETHOD_NOTHING
}Os_SpinlockMethodType;


/*! Defines whether the API has to switch into the supervisor mode or not. */
typedef enum
{
  /*! The spinlock handling is performed in the mode of the caller.
   * This mode is only allowed if forcible termination is disabled. */
  OS_SPINLOCKMODE_USER,
  /*! The spinlock handling is performed in supervisor mode. */
  OS_SPINLOCKMODE_SUPERVISOR
}Os_SpinlockModeType;


/*! Defines whether owner tracing is enabled or not. */
typedef enum
{
  /*! Spinlock does not trace the spinlock owner.
   * \details In case that forcible termination is supported, the spinlock owner is set and the spinlock is not traced
   * in the thread's list of locks. */
  OS_SPINLOCKTRACE_DISABLED,
  /*! \brief    Thread traces the spinlock owner.
   *  \details  This value is only allowed for supervisor mode spinlocks. */
  OS_SPINLOCKTRACE_ENABLED
}Os_SpinlockTraceType;


/*! Defines whether API checks are enabled or not. */
typedef enum
{
  /*! Spinlock checks are disabled. */
  OS_SPINLOCKCHECK_DISABLED,
  /*! \brief    Spinlock checks are enabled.
   *  \details  This value is only allowed for spinlocks which allow tracing. */
  OS_SPINLOCKCHECK_ENABLED
}Os_SpinlockCheckType;


/*! Type which specifies the order number of a spinlock. */
typedef uint8_least Os_SpinlockOrderType;


/*! Dynamic information of a spinlock.
 * \extends Os_LockType */
struct Os_SpinlockType_Tag
{
  /*! Dynamic information for LIFO nestable locks.
   * This attribute must be the first. */
  Os_LockType Lock;

  /*! Points to the owner thread or is a NULL_PTR. */
  P2CONST(Os_ThreadConfigType, TYPEDEF, OS_CONST) OwnerThread;

  /*! Previous locked spinlock. */
  P2CONST(Os_SpinlockConfigType, TYPEDEF, OS_CONST) PreviousSpinlock;

  /*! The spinlock variable. */
  /*! Internal comment removed.
 *
 * */
  volatile Os_Hal_SpinlockType Spinlock;

  /*! The priority of the task before the spinlock was locked. */
  Os_TaskPrioType PreviousPriority;
};


/*! Constant information of a spinlock.
 * \extends Os_LockConfigType */
struct Os_SpinlockConfigType_Tag
{
  /*! General information for LIFO nestable locks. */
  Os_LockConfigType Lock;

  /*! Lock method which is used when a spinlock is taken. */
  Os_SpinlockMethodType Method;

  /*! The core specific task ceiling priority. */
  Os_TaskPrioType CeilingPriority;

  /*! The mode which is required to access the spinlock. */
  Os_SpinlockModeType Mode;

  /*! Tells whether the spinlock shall be traced in the thread. */
  Os_SpinlockTraceType Trace;

  /*! Defines whether API checks are enabled. */
  Os_SpinlockCheckType Checks;

  /*! Defines the order in which the spinlock may be allocated. */
  Os_SpinlockOrderType Order;

  /*! Pointer to the configured trace data. */
  P2CONST(Os_TraceSpinlockConfigType, TYPEDEF, OS_CONST) TimingHookTrace;
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
 *  Os_SpinlockIsEnabled()
 **********************************************************************************************************************/
/*! \brief          Returns whether Spinlocks are configured or not.
 *
 *  \retval         !0   If Spinlocks are configured.
 *  \retval         0    Otherwise.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,
OS_ALWAYS_INLINE, Os_SpinlockIsEnabled, (void));


/***********************************************************************************************************************
 *  Os_SpinlockListInit()
 **********************************************************************************************************************/
/*! \brief          Initialize a list of locks.
 *  \details        Set list pointer to OS_LOCK_LIST_END. The function is called for the idle task in Init-Step3 and
 *                  for all threads in Init-Step4.
 *
 *  \param[in]      LockList  The list of locks to init. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_SpinlockListInit,
(
  P2VAR(Os_SpinlockListType, AUTOMATIC, OS_VAR_NOINIT) LockList
));


/***********************************************************************************************************************
 *  Os_SpinlockInit()
 **********************************************************************************************************************/
/*! \brief          Initialize the given spinlock (Init-Step2).
 *  \details        The kernel uses this function to initialize all spinlocks during OS initialization.
 *                  It initializes the lock object of the given spinlock.
 *
 *  \param[in,out]  Spinlock  Spinlock to initialize. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_SpinlockInit,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
));


/***********************************************************************************************************************
 *  Os_SpinlockGetDyn()
 **********************************************************************************************************************/
/*! \brief          Returns the dynamic part of a spinlock.
 *  \details        --no details--
 *
 *  \param[in]      Spinlock  The spinlock to query. Parameter must not be NULL.
 *
 *  \return         The dynamic data of the spinlock.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2VAR(Os_SpinlockType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE,
OS_ALWAYS_INLINE, Os_SpinlockGetDyn,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_VAR_NOINIT) Spinlock
));


/***********************************************************************************************************************
 *  Os_SpinlockCheckId()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given ID is valid (Not OS_CHECK_FAILED) or not (OS_CHECK_FAILED).
 *  \details        In case that extended checks are disabled, the default result of \ref Os_ErrExtendedCheck() is
 *                  returned.
 *
 *  \param[in]      SpinlockId        The ID to check.
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
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,
OS_ALWAYS_INLINE, Os_SpinlockCheckId,
(
  SpinlockIdType SpinlockId
));


/***********************************************************************************************************************
 *  Os_SpinlockId2Spinlock()
 **********************************************************************************************************************/
/*! \brief          Returns the spinlock which belongs to the given Id.
 *  \details        --no details--
 *
 *  \param[in]      SpinlockId  The id of the spinlock. Parameter must be < OS_SPINLOCKID_COUNT.
 *
 *  \return         The spinlock.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST),
OS_CODE, OS_ALWAYS_INLINE, Os_SpinlockId2Spinlock,
(
  SpinlockIdType SpinlockId
));


/***********************************************************************************************************************
 *  Os_SpinlockGetAccessingApplications()
 **********************************************************************************************************************/
/*! \brief          Get applications which have access to the given object.
 *  \details        --no details--
 *
 *  \param[in,out]  Spinlock  The object to query. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_AppAccessMaskType, OS_CODE, OS_ALWAYS_INLINE,
Os_SpinlockGetAccessingApplications,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
));


/***********************************************************************************************************************
 *  Os_SpinlockGet()
 **********************************************************************************************************************/
/*! \brief          Locks the given spinlock.
 *  \details        This functions is used for locks which have a LockMethod different from NOTHING.
 *
 *  \param[in,out]  Spinlock  Spinlock to lock. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK                No error.
 *  \retval         OS_STATUS_INTERFERENCE_DEADLOCK (EXTENDED status:) Spinlock already occupied by a task/ISR
 *                                              of the same core.
 *  \retval         OS_STATUS_NESTING_DEADLOCK  (EXTENDED status:)  Invalid Spinlock allocation order.
 *  \retval         OS_STATUS_CALLEVEL          (EXTENDED status:) Called from invalid context.
 *  \retval         OS_STATUS_ACCESSRIGHTS_1    (Service Protection:) Caller's access rights are not sufficient.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_SpinlockGet
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
);



/***********************************************************************************************************************
 *  Os_SpinlockRelease()
 **********************************************************************************************************************/
/*! \brief          Releases the given spinlock.
 *  \details        This functions is used for locks which have a LockMethod different from NOTHING, have tracing
 *                  enabled or if killing is enabled.
 *
 *  \param[in,out]  Spinlock  Spinlock to lock. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK              No error.
 *  \retval         OS_STATUS_STATE_1         (EXTENDED status:) The caller is not the owner of the given spinlock.
 *  \retval         OS_STATUS_LIFO_TOP_IS_RESOURCE (EXTENDED status:) Spinlock and Resource API not used in LIFO order.
 *  \retval         OS_STATUS_SPINLOCK_ORDER  (EXTENDED status:) Attempt to release a nested spinlock in wrong order.
 *  \retval         OS_STATUS_ACCESSRIGHTS_1  (Service Protection:) Caller's access rights are not sufficient. This
 *                                            error may occur in combination with trusted functions.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 *
 *  Internal comment removed.
 *
 *
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_SpinlockRelease
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
);


/***********************************************************************************************************************
 *  Os_SpinlockTryGet()
 **********************************************************************************************************************/
/*! \brief          Tries once to lock the given spinlock and returns.
 *  \details        This functions is used for locks which have a LockMethod different from NOTHING.
 *
 *  \param[in,out]  Spinlock  Spinlock to lock. Parameter must not be NULL.
 *  \param[out]     Success   The result of the lock attempt. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK                No error.
 *  \retval         OS_STATUS_INTERFERENCE_DEADLOCK (EXTENDED status:)  Spinlock already occupied by a task of
 *                                              the same core.
 *  \retval         OS_STATUS_NESTING_DEADLOCK  (EXTENDED status:)  Invalid Spinlock allocation order.
 *  \retval         OS_STATUS_CALLEVEL          (EXTENDED status:) Called from invalid context.
 *  \retval         OS_STATUS_ACCESSRIGHTS_1    (Service Protection:) Caller's access rights are not sufficient.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_SpinlockTryGet
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock,
  TryToGetSpinlockType* Success
);


/***********************************************************************************************************************
 *  Os_SpinlockForciblyReleaseThreadLocks()
 **********************************************************************************************************************/
/*! \brief          Release all spinlocks, which are owned by the given thread.
 *  \details        --no details--
 *
 *  \param[in,out]  Thread  Thread to release. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_SpinlockForciblyReleaseThreadLocks
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
);


/***********************************************************************************************************************
 *  Os_SpinlockInternalGet()
 **********************************************************************************************************************/
/*! \brief          Busy wait for spinlock, occupy if spinlock is free.
 *  \details        Spinlock based on just test-and-set, can lead to resource contention in busy lock
 *                  (caused by bus locking and cache invalidation). Therefore this function is based on
 *                  the test and test-and-set algorithm.
 *
 *                  \see          [Test and Test-and-set](https:\\en.wikipedia.org/wiki/Test_and_Test-and-set)
 *
 *  \param[in,out]  Spinlock  The spinlock to lock. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            If forcible termination is enabled, this function has to be called in supervisor mode.
 *  \pre            Spinlock is not locked on local core.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_SpinlockInternalGet,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
));


/***********************************************************************************************************************
 *  Os_SpinlockInternalTryGet()
 **********************************************************************************************************************/
/*! \brief          Try once to get the spinlock.
 *  \details        --no details--
 *
 *  \param[in,out]  Spinlock  The spinlock to lock. Parameter must not be NULL.
 *
 *  \retval         OS_HAL_SPINLOCKSUCCEEDED     If locking succeeded.
 *  \retval         !OS_HAL_SPINLOCKSUCCEEDED    If locking failed.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            If forcible termination is enabled, this function has to be called in supervisor mode.
 *  \pre            Spinlock is not locked on locale core.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_Hal_SpinlockResultType, OS_CODE, OS_ALWAYS_INLINE,
Os_SpinlockInternalTryGet,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
));


/***********************************************************************************************************************
 *  Os_SpinlockInternalRelease()
 **********************************************************************************************************************/
/*! \brief          Releases the given spinlock.
 *  \details        --no details--
 *
 *  \param[in,out]  Spinlock  The spinlock to be release. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            If forcible termination is enabled, this function has to be called in supervisor mode.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_SpinlockInternalRelease,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
));


/***********************************************************************************************************************
 *  Os_Api_GetSpinlock()
 **********************************************************************************************************************/
/*! \brief        OS service GetSpinlock().
 *  \details      For further details see GetSpinlock().
 *
 *  \param[in]    SpinlockId        See GetSpinlock().
 *
 *  \retval       OS_STATUS_OK              No error.
 *  \retval       OS_STATUS_ID_1            (EXTENDED status:) Invalid SpinlockID.
 *  \retval       other                     See \ref Os_SpinlockGet().
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See GetSpinlock().
 *
 *  \trace        CREQ-17, CREQ-40
 *  \trace        SPEC-63584, SPEC-63585, SPEC-63600, SPEC-63603, SPEC-63604, SPEC-63614, SPEC-63623, SPEC-63630
 *  \trace        SPEC-63649, SPEC-63659, SPEC-63665, SPEC-63673, SPEC-63680, SPEC-63682, SPEC-63692, SPEC-63752
 *  \trace        SPEC-63980, SPEC-63593
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_GetSpinlock(SpinlockIdType SpinlockId);


/***********************************************************************************************************************
 *  Os_Api_ReleaseSpinlock()
 **********************************************************************************************************************/
/*! \brief        OS service ReleaseSpinlock().
 *  \details      For further details see ReleaseSpinlock().
 *
 *  \param[in]    SpinlockId        See ReleaseSpinlock().
 *
 *  \retval       OS_STATUS_OK              No error.
 *  \retval       OS_STATUS_ID_1            (EXTENDED status:) Invalid SpinlockID.
 *  \retval       other                     See \ref Os_SpinlockRelease().
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See ReleaseSpinlock().
 *
 *  \trace        CREQ-167, CREQ-40
 *  \trace        SPEC-63586, SPEC-63587, SPEC-63621, SPEC-63622, SPEC-63630, SPEC-63636, SPEC-63661, SPEC-63677
 *  \trace        SPEC-63683, SPEC-63686, SPEC-63629, SPEC-63642, SPEC-63752
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_ReleaseSpinlock(SpinlockIdType SpinlockId);


/***********************************************************************************************************************
 *  Os_Api_TryToGetSpinlock()
 **********************************************************************************************************************/
/*! \brief        OS service TryToGetSpinlock().
 *  \details      For further details see TryToGetSpinlock().
 *
 *  \param[in]    SpinlockId        See TryToGetSpinlock().
 *  \param[out]   Success           See TryToGetSpinlock().
 *
 *  \retval       OS_STATUS_OK              No error.
 *  \retval       OS_STATUS_ID_1            (EXTENDED status:) Invalid SpinlockID.
 *  \retval       other                     See \ref Os_SpinlockTryGet().
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See TryToGetSpinlock().
 *
 *  \trace        CREQ-139, CREQ-40
 *  \trace        SPEC-63592, SPEC-63602, SPEC-63632, SPEC-63633, SPEC-63638, SPEC-63640, SPEC-63646, SPEC-63654
 *  \trace        SPEC-63667, SPEC-63672, SPEC-63681, SPEC-63690, SPEC-63693, SPEC-63752, SPEC-63980, SPEC-2566497
 *  \trace        SPEC-63593
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_TryToGetSpinlock
(
  SpinlockIdType SpinlockId,
  TryToGetSpinlockType* Success
);


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */



#endif /* OS_SPINLOCKINT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_SpinlockInt.h
 **********************************************************************************************************************/
