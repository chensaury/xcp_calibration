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
 *  \ingroup     Os_Kernel
 *  \defgroup    Os_Trace Trace
 *  \file        Os_TraceInt.h
 *  \brief       Definition of OS tracing hooks
 *  \details
 *  OS Tracing
 *  ===========
 *  OS Tracing is used for different purposes:
 *    - OSEK Runtime Interface (ORTI):
 *       - ORTI Service tracing
 *       - ORTI Thread tracing
 *    - Vector Timing Hooks (VTH):
 *       - VTH for thread switching
 *       - VTH for thread activation
 *       - VTH for locks
 *       - VTH for forcible termination
 *
 *  OSEK Runtime Interface
 *  ----------------------
 *  ORTI is a quite general interface description language which covers not only tracing aspects. However, this design
 *  only covers tracing and therefore only the tracing aspects of ORTI. ORTI tracing is performed by the debugger
 *  tracing the values of a specified set of global variables via the hardware debugging interface.
 *
 *  ### ORTI Service tracing
 *  ORTI service tracing is performed by means of the following two functions:
 *  - Os_TraceOrtiApiEntry()
 *  - Os_TraceOrtiApiExit()
 *
 *  Whenever an OS API function is entered, the function Os_TraceOrtiApiEntry is called while the function
 *  Os_TraceOrtiApiExit is called on any return from an OS API function to the application. These functions simply
 *  set the variable Os_CfgTraceCoreXDyn.OrtiCurrentServiceId (where X is the core-ID). As described in the ORTI
 *  standard, the least significant bit of the variable is set to 1 on API entry and to 0 on exit. The other bits
 *  of the variable contain the number of the API service.
 *
 *  ### ORTI Thread tracing
 *  The ORTI standard defines that threads are traced independently for tasks and ISRs. Unfortunately, this OS
 *  implementation has no such variables if no ORTI tracing is enabled. Therefore, two global variables per core
 *  exist if ORTI tracing is enabled to trace the currently running thread: Os_CfgTraceCore0Dyn.CurrentTask and
 *  Os_CfgTraceCore0Dyn.CurrentIsr. These variables are set by the functions:
 *  - Os_TraceThreadSuspendAndStart()
 *  - Os_TraceThreadCleanupAndResume()
 *  - Os_TraceThreadResetAndResume()
 *  - Os_TraceThreadSwitch()
 *
 *  These are exactly the same functions as used to call the scheduling hook in case timing hooks are enabled.
 *
 *  Vector timing hooks
 *  -------------------
 *  The MICROSAR OS timing hooks shall provide all timing relevant information at runtime to an external
 *  tracing tool. As timing relevant information, we consider:
 *  - Thread activation: A task or ISR gets activated but needs not necessarily start to run.
 *  - Thread switch: Task switch or interrupt entry/exit.
 *  - Locks: A lock (spinlock, semaphore, interrupt lock) is acquired or released.
 *  - Forcible termination: A task, ISR or OS application is terminated as a result of a detected problem.
 *
 *  The subchapters below define, how this information is provided to the external tracing tool.
 *
 *  ### VTH for thread activation
 *  Information about thread activation is useful to retrieve the minimum time between activations. This
 *  information can only be retrieved from the start times of threads with additional jitter. The information
 *  about thread activation is also helpful to visualize the time between activation and start of a thread.
 *  The different kinds of thread activation which have been identified are
 *  - Task activation
 *  - Event setting
 *
 *  Interrupt request would generally also be some sort of thread activation. However, this kind of thread
 *  activation is performed completely in the hardware and is therefore out of scope of the OS.
 *
 *  #### VTH for task activation
 *  Task activation may happen as a result of an API (ActivateTask(), ChainTask()) call or by alarm action or
 *  schedule table expiry point. If the called API is successful then it is signaled to the external tracing tool
 *  by calling the  macro OS_VTH_ACTIVATION(). If the called API is not successful because the number of activations
 *  has reached the limit then it is signaled to the external tracing tool by calling macro OS_VTH_ACTIVATION_LIMIT().
 *
 *  #### VTH for event setting
 *  Event setting may be seen as an activation of a task in case the task is typically waiting for events
 *  which trigger the activity of the task. However, if any event setting is considered to be an activation,
 *  the minimum time between task activations may be underestimated heavily. Therefore, the Autosar OS standard
 *  considers event setting only as an activation if it results in a state change from WAITING to READY.
 *  However, even that may not result in a suitable minimum time between activations. Therefore, also the events
 *  which shall be set are given to the external tracing tool.
 *  Examples where information about the events is necessary to make better assumptions on the timing behavior are:
 *  - A task which waits for two events (gets active if any of these events is set). Events occur with cycle times
 *    2ms and 3ms. Knowing the events could result in the intuition that at most two events per millisecond can occur
 *    while the minimum time between event occurrences may be measured infinitely small.
 *  - A task which waits until two events have occurred (first calling WaitEvent for the first event, afterwards
 *    waiting for the second one on a second call of WaitEvent). If the first event occurs first, this could be seen
 *    as an activation of the small task part until the second WaitEvent, the second event would be seen as the
 *    activation of the bigger task part. If the second event occurred first, this would not be seen as an activation
 *    but the occurrence of the first event would then be seen as an activation of both task parts.
 *
 *  Event setting can occur by means of the API call to SetEvent() or by means of alarm action or schedule table
 *  expiry point. Event setting is signaled to the external tracing tool by a call of the macro OS_VTH_SETEVENT().
 *
 *  ### VTH for thread switching
 *  Thread switches are the most important information to be traced by an external tool as they represent a change
 *  of the thread of control. Such thread switches occur at interrupt entry and exit as well as at a task switch.
 *  Each thread switch occurs between a task or ISR which was executed before the thread switch and another task
 *  or ISR which becomes executing as a result of the thread switch. In any case, there is a reason for the thread
 *  switch which often depends on the relation between the two threads. That reason can easily be divided into a
 *  reason why the last thread is no longer executed and a reason why the new thread becomes executing. That reason
 *  is important to the external tracing tool as it has to separate between interruption/preemption and the end of
 *  a task or ISR. The macro OS_VTH_SCHEDULE() is called by the OS to signal thread switches.
 *
 *  ###VTH for locks
 *  Information about locks (resources, spinlocks and interrupt locks) is interesting as threads which
 *  hold locks may prevent other threads from being executed. Dependent on the type of lock, a thread may wait
 *  (inactively or busy) until the lock is free and can be taken. Information about that is also interesting.
 *  The subchapters provide the measures for tracing of the different locks.
 *
 *  ####VTH for resources
 *  Resources are a lock type which never requires a thread to wait for it. So only the information about
 *  getting and releasing the lock is worth tracing. The OS signals the respective events to the external
 *  tracing tool by means of the macros: OS_VTH_GOT_RES() and OS_VTH_REL_RES().
 *
 *  ####VTH for spinlocks
 *  Spinlocks are a type of lock, where a thread may perform busy waiting. Therefore, the waiting time is
 *  unavailable to any thread with lower priority on the core where the spinlock shall be acquired. Once
 *  the spinlock has been taken, all other threads on other cores need to wait until the spinlock is released.
 *  This has been considered when stating the following requirements.
 *
 *  Mind that although spinlocks are used to coordinate cross core resource accesses, all spinlock operations
 *  are performed core locally.
 *
 *  The OS signals spinlock events to an external tracing tool by means of the macros OS_VTH_REQ_SPINLOCK(),
 *  OS_VTH_GOT_SPINLOCK() and OS_VTH_REL_SPINLOCK().
 *
 *  The OS uses spinlocks also internally. Usually one would assume that internal spinlocks are locked for
 *  much shorter time than those, used by the application. However, this may not be true for applications
 *  with extremely strict realtime requirements. Therefore, timing hooks are also provided for internally
 *  #used spinlocks. In order to keep the overhead small, the OS uses different hook macros. So these macros
 *  may be empty in case no information about internal locking is necessary.
 *
 *  The OS signals internal spinlock events to an external tracing tool by means of the macros
 *  OS_VTH_REQ_ISPINLOCK(), OS_VTH_GOT_ISPINLOCK() and OS_VTH_REL_ISPINLOCK().
 *
 *  ####VTH for interrupt locks
 *  The time of holding an interrupt lock is interesting as the processing core is unavailable to any other
 *  thread as long as a thread holds an interrupt lock. The OS signals interrupt lock events to the external
 *  tracing tool by means of the macros OS_VTH_DISABLEDINT() and OS_VTH_ENABLEDINT(). Either of these macros
 *  has a parameter to signal whether all interrupts are disabled or only just interrupts of category 2.
 *
 *  ###VTH for forcible termination
 *  Tasks and ISRs may be forcibly terminated as a result of a call to the API service TerminateApplication()
 *  or a a result of a detected protection error. This is important to an external tracing tool as the
 *  respective task of ISR will usually not finish its job on time. The OS signals forcible termination by
 *  a call of the macro OS_VTH_FORCED_TERMINATION().
 *
 *  \{
 *
 *  \brief       This file decides which tracing hooks shall be used.
 *  \details
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_TRACEINT_H
# define OS_TRACEINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Trace_Types.h"
# include "Os_Trace_Cfg.h"
# include "Os_Trace_Lcfg.h"


/* Os kernel module dependencies */
# include "Os_Cfg.h"
# include "OsInt.h"
# include "Os_Common_Types.h"
# include "Os_CoreInt.h"

/* Os Hal dependencies */
# include "Os_Hal_CompilerInt.h"


# if(OS_CFG_ORTI == STD_ON)
#   include "Os_Orti.h"
# endif

#  if !defined(OS_TRACE)                                                                                                /* COV_OS_TRACEOSTRACE */
#   define OS_TRACE       OS_CFG_ORTI
#  endif


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/* The OS_IS_DEFINED_ macros below are necessary as Doxygen cannot handle the following sequence correctly:
 * #ifndef   SOME_MACRO
 * DOXYGEN-comment for SOME_MACRO
 * #define SOME_MACRO
 * #endif
 *
 */
#ifdef OS_VTH_SCHEDULE
# define OS_IS_DEFINED_OS_VTH_SCHEDULE
#endif
#ifdef OS_VTH_FORCED_TERMINATION
# define OS_IS_DEFINED_OS_VTH_FORCED_TERMINATION
#endif
#ifdef OS_VTH_ACTIVATION
# define OS_IS_DEFINED_OS_VTH_ACTIVATION
#endif
#ifdef OS_VTH_ACTIVATION_LIMIT
# define OS_IS_DEFINED_OS_VTH_ACTIVATION_LIMIT
#endif
#ifdef OS_VTH_SETEVENT
# define OS_IS_DEFINED_OS_VTH_SETEVENT
#endif
#ifdef OS_VTH_WAITEVENT_NOWAIT
# define OS_IS_DEFINED_OS_VTH_WAITEVENT_NOWAIT
#endif
#ifdef OS_VTH_GOT_RES
# define OS_IS_DEFINED_OS_VTH_GOT_RES
#endif
#ifdef OS_VTH_REL_RES
# define OS_IS_DEFINED_OS_VTH_REL_RES
#endif
#ifdef OS_VTH_REQ_SPINLOCK
# define OS_IS_DEFINED_OS_VTH_REQ_SPINLOCK
#endif
#ifdef OS_VTH_GOT_SPINLOCK
# define OS_IS_DEFINED_OS_VTH_GOT_SPINLOCK
#endif
#ifdef OS_VTH_REL_SPINLOCK
# define OS_IS_DEFINED_OS_VTH_REL_SPINLOCK
#endif
#ifdef OS_VTH_DISABLEDINT
# define OS_IS_DEFINED_OS_VTH_DISABLEDINT
#endif
#ifdef OS_VTH_ENABLEDINT
# define OS_IS_DEFINED_OS_VTH_ENABLEDINT
#endif
#ifdef OS_VTH_REQ_ISPINLOCK
# define OS_IS_DEFINED_OS_VTH_REQ_ISPINLOCK
#endif
#ifdef OS_VTH_GOT_ISPINLOCK
# define OS_IS_DEFINED_OS_VTH_GOT_ISPINLOCK
#endif
#ifdef OS_VTH_REL_ISPINLOCK
# define OS_IS_DEFINED_OS_VTH_REL_ISPINLOCK
#endif



/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/*! Defines the reason why the OS starts to execute a thread. */
typedef enum
{
  /*! The task is started as it was activated. */
  OS_TRACE_TASK_ACTIVATION = OS_VTHP_TASK_ACTIVATION,
  /*! The ISR is started as the interrupt was requested. */
  OS_TRACE_ISR_START = OS_VTHP_ISR_START,
  /*! The task is executed as an event has occurred, the task was waiting for. */
  OS_TRACE_TASK_SETEVENT = OS_VTHP_TASK_SETEVENT,
  /*! The task is executed as it got the semaphore it was waiting for. */
  OS_TRACE_TASK_GOTSEMA = OS_VTHP_TASK_GOTSEMA,
  /*! The task or ISR is executed as the preempting/interrupting task/ISR has finished execution. */
  OS_TRACE_THREAD_RESUME = OS_VTHP_THREAD_RESUME,
  /*! The thread has been forcibly terminated, logical entry for cleanup only */
  OS_TRACE_THREAD_CLEANUP = OS_VTHP_THREAD_CLEANUP
}Os_TraceThreadRunReason;

#if (OS_VTHP_TASK_TERMINATION != OS_VTHP_TASK_ACTIVATION)
# error "The implementation assumes a direct mapping between values for FromThreadReason and ToThreadReason"
#endif
#if (OS_VTHP_ISR_END != OS_VTHP_ISR_START)
# error "The implementation assumes a direct mapping between values for FromThreadReason and ToThreadReason"
#endif
#if (OS_VTHP_TASK_WAITEVENT != OS_VTHP_TASK_SETEVENT)
# error "The implementation assumes a direct mapping between values for FromThreadReason and ToThreadReason"
#endif
#if (OS_VTHP_TASK_WAITSEMA != OS_VTHP_TASK_GOTSEMA)
# error "The implementation assumes a direct mapping between values for FromThreadReason and ToThreadReason"
#endif
#if (OS_VTHP_THREAD_PREEMPT != OS_VTHP_THREAD_RESUME)
# error "The implementation assumes a direct mapping between values for FromThreadReason and ToThreadReason"
#endif

/*! \brief    Represents the identification of OS services for an external debugger supporting the
 *            OSEK Runtime Interface (ORTI).
 *  \details  Start and end of a service are coded in the least significant bit according to the
 *            ORTI standard. Therefore, all IDs are even.
 *            We trace the service in a uint8. Therefore, at most 127 services are possible to
 *            trace currently.
 */
typedef enum
{
  OsOrtiApiIdGetApplicationID              = 0x02u,  /*!< GetApplicationID() */
  OsOrtiApiIdGetISRID                      = 0x04u,  /*!< GetISRID() */
  OsOrtiApiIdCallTrustedFunction           = 0x06u,  /*!< CallTrustedFunction() */
  OsOrtiApiIdCheckISRMemoryAccess          = 0x08u,  /*!< CheckISRMemoryAccess() */
  OsOrtiApiIdCheckTaskMemoryAccess         = 0x0Au,  /*!< CheckTaskMemoryAccess() */
  OsOrtiApiIdCheckObjectAccess             = 0x0Cu,  /*!< CheckObjectAccess() */
  OsOrtiApiIdCheckObjectOwnership          = 0x0Eu,  /*!< CheckObjectOwnership() */
  OsOrtiApiIdStartScheduleTableRel         = 0x10u,  /*!< StartScheduleTableRel() */
  OsOrtiApiIdStartScheduleTableAbs         = 0x12u,  /*!< StartScheduleTableAbs() */
  OsOrtiApiIdStopScheduleTable             = 0x14u,  /*!< StopScheduleTable() */
  OsOrtiApiIdNextScheduleTable             = 0x16u,  /*!< NextScheduleTable() */
  OsOrtiApiIdStartScheduleTableSynchron    = 0x18u,  /*!< StartScheduleTableSynchron() */
  OsOrtiApiIdSyncScheduleTable             = 0x1Au,  /*!< SyncScheduleTable() */
  OsOrtiApiIdSetScheduleTableAsync         = 0x1Cu,  /*!< SetScheduleTableAsync() */
  OsOrtiApiIdGetScheduleTableStatus        = 0x1Eu,  /*!< GetScheduleTableStatus() */
  OsOrtiApiIdIncrementCounter              = 0x20u,  /*!< IncrementCounter() */
  OsOrtiApiIdGetCounterValue               = 0x22u,  /*!< GetCounterValue() */
  OsOrtiApiIdGetElapsedValue               = 0x24u,  /*!< GetElapsedValue() */
  OsOrtiApiIdTerminateApplication          = 0x26u,  /*!< TerminateApplication() */
  OsOrtiApiIdAllowAccess                   = 0x28u,  /*!< AllowAccess() */
  OsOrtiApiIdGetApplicationState           = 0x2Au,  /*!< GetApplicationState() */
  OsOrtiApiIdGetNumberOfActivatedCores     = 0x2Cu,  /*!< GetNumberOfActivatedCores() */
  OsOrtiApiIdGetCoreID                     = 0x2Eu,  /*!< GetCoreID() */
  OsOrtiApiIdStartCore                     = 0x30u,  /*!< StartCore() */
  OsOrtiApiIdStartNonAutosarCore           = 0x32u,  /*!< StartNonAutosarCore() */
  OsOrtiApiIdGetSpinlock                   = 0x34u,  /*!< GetSpinlock() */
  OsOrtiApiIdReleaseSpinlock               = 0x36u,  /*!< ReleaseSpinlock() */
  OsOrtiApiIdTryToGetSpinlock              = 0x38u,  /*!< TryToGetSpinlock() */
  OsOrtiApiIdShutdownAllCores              = 0x3Au,  /*!< ShutdownAllCores() */
  OsOrtiApiIdControlIdle                   = 0x3Cu,  /*!< ControlIdle() */
  OsOrtiApiIdIocSend                       = 0x3Eu,  /*!< IocSend() */
  OsOrtiApiIdIocWrite                      = 0x40u,  /*!< IocWrite() */
  OsOrtiApiIdIocSendGroup                  = 0x42u,  /*!< IocSendGroup() */
  OsOrtiApiIdIocWriteGroup                 = 0x44u,  /*!< IocWriteGroup() */
  OsOrtiApiIdIocReceive                    = 0x46u,  /*!< IocReceive() */
  OsOrtiApiIdIocRead                       = 0x48u,  /*!< IocRead() */
  OsOrtiApiIdIocReceiveGroup               = 0x4Au,  /*!< IocReceiveGroup() */
  OsOrtiApiIdIocReadGroup                  = 0x4Cu,  /*!< IocReadGroup() */
  OsOrtiApiIdIocEmptyQueue                 = 0x4Eu,  /*!< IocEmptyQueue() */
  OsOrtiApiIdGetCurrentApplicationID       = 0x50u,  /*!< GetCurrentApplicationID() */
  OsOrtiApiIdCallNonTrustedFunction        = 0x52u,  /*!< CallNonTrustedFunction() */
  OsOrtiApiIdGetTaskStackUsage             = 0x54u,  /*!< Os_GetTaskStackUsage() */
  OsOrtiApiIdGetISRStackUsage              = 0x56u,  /*!< Os_GetISRStackUsage() */
  OsOrtiApiIdGetKernelStackUsage           = 0x58u,  /*!< Os_GetKernelStackUsage() */
  OsOrtiApiIdGetStartupHookStackUsage      = 0x5Au,  /*!< Os_GetStartupHookStackUsage() */
  OsOrtiApiIdGetErrorHookStackUsage        = 0x5Cu,  /*!< Os_GetErrorHookStackUsage() */
  OsOrtiApiIdGetShutdownHookStackUsage     = 0x5Eu,  /*!< Os_GetShutdownHookStackUsage() */
  OsOrtiApiIdGetProtectionHookStackUsage   = 0x60u,  /*!< Os_GetProtectionHookStackUsage() */
  OsOrtiApiIdGetSemaphore                  = 0x62u,  /*!< GetSemaphore() */
  OsOrtiApiIdReleaseSemaphore              = 0x64u,  /*!< ReleaseSemaphore() */
  OsOrtiApiIdStartOS                       = 0x66u,  /*!< StartOS() */
  OsOrtiApiIdGetActiveApplicationMode      = 0x68u,  /*!< GetActiveApplicationMode() */
  OsOrtiApiIdDisableAllInterrupts          = 0x6Au,  /*!< DisableAllInterrupts() */
  OsOrtiApiIdEnableAllInterrupts           = 0x6Cu,  /*!< EnableAllInterrupts() */
  OsOrtiApiIdSuspendAllInterrupts          = 0x6Eu,  /*!< SuspendAllInterrupts() */
  OsOrtiApiIdResumeAllInterrupts           = 0x70u,  /*!< ResumeAllInterrupts() */
  OsOrtiApiIdSuspendOSInterrupts           = 0x72u,  /*!< SuspendOSInterrupts() */
  OsOrtiApiIdResumeOSInterrupts            = 0x74u,  /*!< ResumeOSInterrupts() */
  OsOrtiApiIdActivateTask                  = 0x76u,  /*!< ActivateTask() */
  OsOrtiApiIdTerminateTask                 = 0x78u,  /*!< TerminateTask() */
  OsOrtiApiIdChainTask                     = 0x7Au,  /*!< ChainTask() */
  OsOrtiApiIdGetTaskID                     = 0x7Cu,  /*!< GetTaskID() */
  OsOrtiApiIdGetTaskState                  = 0x7Eu,  /*!< GetTaskState() */
  OsOrtiApiIdSchedule                      = 0x80u,  /*!< Schedule() */
  OsOrtiApiIdSetEvent                      = 0x82u,  /*!< SetEvent() */
  OsOrtiApiIdClearEvent                    = 0x84u,  /*!< ClearEvent() */
  OsOrtiApiIdGetEvent                      = 0x86u,  /*!< GetEvent() */
  OsOrtiApiIdWaitEvent                     = 0x88u,  /*!< WaitEvent() */
  OsOrtiApiIdGetAlarmBase                  = 0x8Au,  /*!< GetAlarmBase() */
  OsOrtiApiIdGetAlarm                      = 0x8Cu,  /*!< GetAlarm() */
  OsOrtiApiIdSetRelAlarm                   = 0x8Eu,  /*!< SetRelAlarm() */
  OsOrtiApiIdSetAbsAlarm                   = 0x90u,  /*!< SetAbsAlarm() */
  OsOrtiApiIdCancelAlarm                   = 0x92u,  /*!< CancelAlarm() */
  OsOrtiApiIdGetResource                   = 0x94u,  /*!< GetResource() */
  OsOrtiApiIdReleaseResource               = 0x96u,  /*!< ReleaseResource() */
  OsOrtiApiIdGetVersionInfo                = 0x98u,  /*!< GetVersionInfo() */
  OsOrtiApiIdEnterPreStartTask             = 0x9Eu,  /*!< EnterPreStartTask() */
  OsOrtiApiIdShutdownOS                    = 0xA0u,  /*!< ShutdownOS() */
  OsOrtiApiIdGetUnhandledIrq               = 0xA2u,  /*!< GetUnhandledIrq() */
  OsOrtiApiIdGetUnhandledExc               = 0xA4u,  /*!< GetUnhandledExc() */
  OsOrtiApiIdDisableOSInterrupts           = 0xA6u,  /*!< DisableOSInterrupts() */
  OsOrtiApiIdEnableOSInterrupts            = 0xA8u,  /*!< EnableOSInterrupts() */
  OsOrtiApiIdReadPeripheral8               = 0xAAu,  /*!< osReadPeripheral8() */
  OsOrtiApiIdReadPeripheral16              = 0xACu,  /*!< osReadPeripheral16() */
  OsOrtiApiIdReadPeripheral32              = 0xAEu,  /*!< osReadPeripheral32() */
  OsOrtiApiIdWritePeripheral8              = 0xB0u,  /*!< osWritePeripheral8() */
  OsOrtiApiIdWritePeripheral16             = 0xB2u,  /*!< osWritePeripheral16() */
  OsOrtiApiIdWritePeripheral32             = 0xB4u,  /*!< osWritePeripheral32() */
  OsOrtiApiIdModifyPeripheral8             = 0xB6u,  /*!< osModifyPeripheral8() */
  OsOrtiApiIdModifyPeripheral16            = 0xB8u,  /*!< osModifyPeripheral16() */
  OsOrtiApiIdModifyPeripheral32            = 0xBAu,  /*!< osModifyPeripheral32() */
  OsOrtiApiIdGetDetailedError              = 0xBCu,  /*!< GetDetailedError() */
  OsOrtiApiIdOSErrorGetServiceId           = 0xBEu,  /*!< OSErrorGetServiceId() */
  OsOrtiApiIdDisableInterruptSource        = 0xC0u,  /*!< Os_DisableInterruptSource() */
  OsOrtiApiIdEnableInterruptSource         = 0xC2u,  /*!< Os_EnableInterruptSource() */
  OsOrtiApiIdClearPendingInterrupt         = 0xC4u,  /*!< Os_ClearPendingInterrupt() */
  OsOrtiApiIdIsInterruptSourceEnabled      = 0xC6u,  /*!< Os_IsInterruptSourceEnabled() */
  OsOrtiApiIdIsInterruptPending            = 0xC8u,  /*!< Os_IsInterruptPending() */
  OsOrtiApiIdCallFastTrustedFunction       = 0xCAu,  /*!< Os_CallFastTrustedFunction() */
  OsOrtiApiIdBarrierSynchronize            = 0xCCu,  /*!< Os_BarrierSynchronize() */
  OsOrtiApiIdGetExceptionContext           = 0xCEu,  /*!< Os_GetExceptionContext() */
  OsOrtiApiIdSetExceptionContext           = 0xD0u,  /*!< Os_SetExceptionContext() */
  OsOrtiApiIdInitialEnableInterruptSources = 0xD2u   /*!< Os_InitialEnableInterruptSources() */
  /* All numbers should be even. */
} OsOrtiApiIdType;

/*! Defines the thread type. */
typedef enum
{
  /*! The task is started as it was activated.*/
  OS_TRACE_THREAD_TYPE_TASK = 0,
  /*! The ISR is started as the interrupt was requested. */
  OS_TRACE_THREAD_TYPE_ISR  = 1
}Os_TraceThreadTypeType;


/*! Defines the next reason to run the thread
 *  \details
 *      - Available per task and ISR
 *      - The next run reason is always determined by the last leave reason
 */
struct Os_TraceThreadType_Tag
{
  /*! The next run reason of this thread. */
  Os_TraceThreadRunReason NextRunReason;
};

/*! Trace configuration data of a thread.
 *  \details
 *     - Available per task and ISR
 *     - Provides the thread/task/ISR-ID to be used as parameter for Vector Timing Hooks. */
struct Os_TraceThreadConfigType_Tag
{
  /*! The dynamic trace data of this thread. */
  P2VAR(Os_TraceThreadType, TYPEDEF, OS_VAR_NOINIT) Dyn;
  /*! The thread ID to be reported to the timing hooks */
  Os_TraceThreadIdType Id;
  /*! The type of traced thread (task/ISR) */
  Os_TraceThreadTypeType Type;
};

/*! Defines the currently running task, ISR and API service per core. */
struct Os_TraceCoreType_Tag
{
    /*! The currently traced task (for ORTI only tasks and ISRs are relevant) */
    P2CONST(Os_TraceThreadConfigType, TYPEDEF, OS_CONST) CurrentTask;
    /*! The currently traced ISR (for ORTI only tasks and ISRs are relevant) */
    P2CONST(Os_TraceThreadConfigType, TYPEDEF, OS_CONST) CurrentIsr;
    /*! the currently traced API service */
    uint8 OrtiCurrentServiceId;
};

/*! Defines the ID of spinlocks and internal spinlocks for tracing */
struct Os_TraceSpinlockConfigType_Tag
{
    Os_TraceSpinlockIdType SpinlockId;
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
 *  Os_TraceIsTimingHookEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether timing hooks are enabled or not.
 *  \details      --no details--
 *
 *  \retval       !0    Vector timing hooks are enabled.
 *  \retval       0     Vector timing hooks are disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_TraceIsTimingHookEnabled,
( void ));

/***********************************************************************************************************************
 *  Os_TraceIsOrtiServiceTracingEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether ORTI service tracing is enabled or not.
 *  \details      This allows the ORTI debugger to trace the information about the currently performed OS API Service.
 *
 *  \retval       !0    Service tracing is enabled.
 *  \retval       0     Service tracing is disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceIsOrtiServiceTracingEnabled,
( void ));

/***********************************************************************************************************************
 *  Os_TraceIsOrtiTaskIsrTracingEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether ORTI Task/ISR tracing is enabled or not.
 *  \details      This allows the ORTI debugger to trace which task or ISR is currently performed.
 *
 *  \retval       !0    Task/ISR tracing is enabled.
 *  \retval       0     Task/ISR tracing is disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceIsOrtiTaskIsrTracingEnabled,
( void ));

/***********************************************************************************************************************
 *  Os_TraceThreadInit()
 **********************************************************************************************************************/
/*! \brief          Initialize a threads trace data.
 *  \details        The function is called for the idle task in Init-Step3 and for all threads in Init-Step4.
 *
 *  \param[in]      Thread             The thread which shall be initialized or NULL_PTR
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given objects is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceThreadInit,
(
  P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST) Thread
));

/***********************************************************************************************************************
 *  Os_TraceThreadInitAndStart()
 **********************************************************************************************************************/
/*! \brief          Initialize a threads trace data and trace a switch to that thread.
 *  \details        --no details--
 *
 *  \param[in]      Task             The task which shall be initialized and entered.
 *                                   Parameter must not be NULL if tracing is enabled.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 *  \pre            Concurrent access to given objects is prevented by caller.
 *  \pre            This function is called exactly once per core for the task which shall be traced first.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceThreadInitAndStart,
(
  P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST) Task
));

/***********************************************************************************************************************
 *  Os_TraceThreadSwitch()
 **********************************************************************************************************************/
/*! \brief          Trace a thread switch.
 *  \details        --no details--
 *
 *  \param[in]      CurrentTaskState The state of the task which is provided by parameter 'Current'
 *  \param[in,out]  Current          The thread which which is left.
 *                                   Parameter must not be NULL if tracing is enabled.
 *  \param[in]      Next             The thread which shall be entered.
 *                                   Parameter must not be NULL if tracing is enabled.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 *  \pre            Concurrent access to given objects is prevented by caller.
 *  \pre            Either Os_TraceThreadInitAndStart() or Os_TraceThreadInit() has been called before for both thread
 *                  parameters.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceThreadSwitch,
(
  TaskStateType CurrentTaskState,
  P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST) Current,
  P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST) Next
));

/***********************************************************************************************************************
 *  Os_TraceThreadResetAndResume()
 **********************************************************************************************************************/
/*! \brief          Trace a thread switch.
 *  \details        --no details--
 *
 *  \param[in,out]  Current The thread which which is left.
 *                          Parameter must not be NULL if tracing is enabled.
 *  \param[in]      Next    The thread which shall be entered.
 *                          Parameter must not be NULL if tracing is enabled.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 *  \pre            Concurrent access to given objects is prevented by caller.
 *  \pre            Either Os_TraceThreadInitAndStart() or Os_TraceThreadInit() has been called before for both thread
 *                  parameters.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceThreadResetAndResume,
(
  P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST) Current,
  P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST) Next
));

/***********************************************************************************************************************
 *  Os_TraceThreadCleanupAndResume()
 **********************************************************************************************************************/
/*! \brief          Trace a thread switch.
 *  \details        --no details--
 *
 *  \param[in,out]  Current The thread which which is left.
 *  \param[in]      Next    The thread which shall be entered.
 *                          Parameter must not be NULL if tracing is enabled.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 *  \pre            Concurrent access to given objects is prevented by caller.
 *  \pre            Either Os_TraceThreadInitAndStart() or Os_TraceThreadInit() has been called before for both thread
 *                  parameters.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceThreadCleanupAndResume,
(
  P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST) Current,
  P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST) Next
));

/***********************************************************************************************************************
 *  Os_TraceThreadSuspendAndStart()
 **********************************************************************************************************************/
/*! \brief          Trace a thread switch.
 *  \details        --no details--
 *
 *  \param[in,out]  Current The thread which which is left.
 *                          Parameter must not be NULL if tracing is enabled.
 *  \param[in]      Next    The thread which shall be entered.
 *                          Parameter must not be NULL if tracing is enabled.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 *  \pre            Concurrent access to given objects is prevented by caller.
 *  \pre            Either Os_TraceThreadInitAndStart() or Os_TraceThreadInit() has been called before for both thread
 *                  parameters.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceThreadSuspendAndStart,
(
  P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST) Current,
  P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST) Next
));

/***********************************************************************************************************************
 *  Os_TraceIsrKill()
 **********************************************************************************************************************/
/*! \brief          Trace the forcible termination of an ISR.
 *  \details        --no details--
 *
 *  \param[in,out]  KilledIsr The Isr which is forcibly terminated.
 *                            Parameter must not be NULL if tracing is enabled.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Os_TraceThreadInit() has been called before for KilledIsr.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceIsrKill,
(
  P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST) KilledIsr
));

/***********************************************************************************************************************
 *  Os_TraceTaskKill()
 **********************************************************************************************************************/
/*! \brief          Trace the forcible termination of a task.
 *  \details        --no details--
 *
 *  \param[in,out]  KilledTask      The task which is forcibly terminated.
 *                                  Parameter must not be NULL if tracing is enabled.
 *  \param[in]      IsTaskSuspended reflects the task state before the killing takes place:
 *                   - !0: The task is in state SUSPENDED
 *                   -  0: The task is not in state SUSPENDED
 *
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Either Os_TraceThreadInitAndStart() or Os_TraceThreadInit() has been called before for KilledTask.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceTaskKill,
(
  P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST) KilledTask,
  Os_StdReturnType IsTaskSuspended
));

/***********************************************************************************************************************
 *  Os_TraceTaskActivate()
 **********************************************************************************************************************/
/*! \brief          Trace the activation of a task.
 *  \details        --no details--
 *
 *  \param[in]      Task            The task which is activated.
 *                                  Parameter must not be NULL if tracing is enabled.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceTaskActivate,
(
  P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST) Task
));


/***********************************************************************************************************************
 *  Os_TraceTaskActivateLimit()
 **********************************************************************************************************************/
/*! \brief          Trace the failed activation of a task.
 *  \details        --no details--
 *
 *  \param[in]      Task            The task which failed to be activated because the number of activations has reached
 *                                  the limit. Parameter must not be NULL if tracing is enabled.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceTaskActivateLimit,
(
  P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST) Task
));


/***********************************************************************************************************************
 *  Os_TraceTaskSetEvent()
 **********************************************************************************************************************/
/*! \brief          Trace the event setting for a task.
 *  \details        --no details--
 *
 *  \param[in]      Task         The task for which an event is set.
 *                               Parameter must not be NULL if tracing is enabled.
 *  \param[in]      EventMask    The event mask which was used in the service call.
 *  \param[in]      StateChanged
 *                   - !0: The task state has changed from WAITING to READY
 *                   -  0: The task state has not changed
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceTaskSetEvent,
(
  P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST) Task,
  EventMaskType EventMask,
  boolean StateChanged
));


/***********************************************************************************************************************
 *  Os_TraceTaskWaitEventNoWait()
 **********************************************************************************************************************/
/*! \brief          Trace the waiting for event when event is already set.
 *  \details        --no details--
 *
 *  \param[in]      Task         The task which is waiting for the event.
 *                               Parameter must not be NULL if tracing is enabled.
 *  \param[in]      EventMask    The event mask which was used in the service call.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceTaskWaitEventNoWait,
(
  P2CONST(Os_TraceThreadConfigType, AUTOMATIC, OS_CONST) Task,
  EventMaskType EventMask
));


/***********************************************************************************************************************
 * Os_TraceResourceTaken()
 **********************************************************************************************************************/
/*! \brief          Trace resource occupation (get)
 *
 *  \param[in]      ResId The ID of the resource which has been taken
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceResourceTaken,
(
    ResourceType ResId
));

/***********************************************************************************************************************
 * Os_TraceResourceReleased()
 **********************************************************************************************************************/
/*! \brief          Trace resource occupation (release)
 *
 *  \param[in]      ResId The ID of the resource which has been released
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceResourceReleased,
(
    ResourceType ResId
));

/***********************************************************************************************************************
 * Os_TraceSpinlockRequested()
 **********************************************************************************************************************/
/*! \brief          Trace spinlock occupation (start spinning)
 *
 *  \param[in]      Spinlock        The trace object for the spinlock.
 *                                  Parameter must not be NULL if tracing is enabled.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceSpinlockRequested,
(
    P2CONST(Os_TraceSpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
));

/***********************************************************************************************************************
 * Os_TraceSpinlockTaken
 **********************************************************************************************************************/
/*! \brief          Trace spinlock occupation (taken -- immediately or after spinning)
 *
 *  \param[in]      Spinlock        The trace object for the spinlock.
 *                                  Parameter must not be NULL if tracing is enabled.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceSpinlockTaken,
(
    P2CONST(Os_TraceSpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
));

/***********************************************************************************************************************
 * Os_TraceSpinlockReleased
 **********************************************************************************************************************/
/*! \brief          Trace spinlock occupation (release)
 *
 *  \param[in]      Spinlock        The trace object for the spinlock.
 *                                  Parameter must not be NULL if tracing is enabled.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceSpinlockReleased,
(
    P2CONST(Os_TraceSpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
));

/***********************************************************************************************************************
 * Os_TraceInterruptsGlobalDisabled
 **********************************************************************************************************************/
/*! \brief          Trace interrupt locks (global disable)
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceInterruptsGlobalDisabled,
(
    void
));

/***********************************************************************************************************************
 * Os_TraceInterruptsLevelDisabled
 **********************************************************************************************************************/
/*! \brief          Trace interrupt locks (level disabled)
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceInterruptsLevelDisabled,
(
    void
));

/***********************************************************************************************************************
 * Os_TraceInterruptsGlobalEnabled
 **********************************************************************************************************************/
/*! \brief          Trace interrupt locks (global enabled)
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceInterruptsGlobalEnabled,
(
    void
));

/***********************************************************************************************************************
 * Os_TraceInterruptsLevelEnabled
 **********************************************************************************************************************/
/*! \brief          Trace interrupt locks (level enabled)
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts locked to TP lock level.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceInterruptsLevelEnabled,
(
    void
));


/***********************************************************************************************************************
 * Os_TraceOrtiApiEntry
 **********************************************************************************************************************/
/*! \brief          Trace the entry to an API function with an ORTI debugger
 *
 *  \param[in]      ServiceId The ID of the API service which is entered.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceOrtiApiEntry,
(
    OsOrtiApiIdType ServiceId
));

/***********************************************************************************************************************
 * Os_TraceOrtiApiExit
 **********************************************************************************************************************/
/*! \brief          Trace the exit from an API function with an ORTI debugger
 *
 *  \param[in]      ServiceId The ID of the API service which is left.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different threads.
 *  \synchronous    TRUE
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceOrtiApiExit,
(
    OsOrtiApiIdType ServiceId
));


/***********************************************************************************************************************
 *  Os_TraceGetNumberOfConfiguredSpinlocks()
 **********************************************************************************************************************/
/*! \brief        Returns the number of configured spinlocks.
 *  \details      --no details--
 *
 *  \return       Number of configured spinlocks.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_TraceSpinlockIdType, OS_CODE, OS_ALWAYS_INLINE,
Os_TraceGetNumberOfConfiguredSpinlocks, ( void ));


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_TRACEINT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_TraceInt.h
 **********************************************************************************************************************/
