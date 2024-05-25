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
 * \addtogroup  Os_Kernel
 * \{
 *
 * \file
 * \brief       OS API relevant forward declarations.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_TYPES_H
# define OS_TYPES_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Types_Lcfg.h"
/* Os kernel module dependencies */

/* Os hal dependencies */
# include "Os_Hal_Os_Types.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/* ----- OSEK ----- (Values are defined) */
/*! Illegal access. */
# define E_OS_ACCESS                            ((StatusType)0x01)
/*! Invalid calling context. */
# define E_OS_CALLEVEL                          ((StatusType)0x02)
/*! Invalid OS object ID. */
# define E_OS_ID                                ((StatusType)0x03)
/*! Maximum task activations reached. */
# define E_OS_LIMIT                             ((StatusType)0x04)
/*! OS object is currently not in use. */
# define E_OS_NOFUNC                            ((StatusType)0x05)
/*! Scheduling requested with occupied resource. */
# define E_OS_RESOURCE                          ((StatusType)0x06)
/*! OS object is not in correct state to perform the requested operation. */
# define E_OS_STATE                             ((StatusType)0x07)
/*! Given value is out of the configured range. */
# define E_OS_VALUE                             ((StatusType)0x08)

/* ----- AUTOSAR OS ----- */
/*! Service can not be called. */
# define E_OS_SERVICEID                         ((StatusType)0x09)
/*! An invalid address is given as a parameter to a service.
 * \details This value may only be returned in memory protected systems. As this error is hard to detected,
 * it is handled by the Protection Hook and so E_OS_ILLEGAL_ADDRESS will never be returned by any function. */
# define E_OS_ILLEGAL_ADDRESS                   ((StatusType)0x0A)
/*! Tasks terminates without a TerminateTask() or ChainTask() call. */
# define E_OS_MISSINGEND                        ((StatusType)0x0B)
/*! A service of the OS is called inside an interrupt disable/enable pair. */
# define E_OS_DISABLEDINT                       ((StatusType)0x0C)
/*! A stack fault detected via stack monitoring by the OS */
# define E_OS_STACKFAULT                        ((StatusType)0x0D)
/*! A memory access violation occurred */
# define E_OS_PROTECTION_MEMORY                 ((StatusType)0x0E)
/*! A Task/ISR2 exceeds its execution time budget  */
# define E_OS_PROTECTION_TIME                   ((StatusType)0x0F)
/*! A Task/ISR2 arrives before its timeframe has expired */
# define E_OS_PROTECTION_ARRIVAL                ((StatusType)0x10)
/*! A Task/Category 2 ISR blocks for too long */
# define E_OS_PROTECTION_LOCKED                 ((StatusType)0x11)
/*! A trap occurred  */
# define E_OS_PROTECTION_EXCEPTION              ((StatusType)0x12)
/*! Deadlock situation due to interference */
# define E_OS_INTERFERENCE_DEADLOCK             ((StatusType)0x13)
/*! Potential deadlock due to wrong nesting */
# define E_OS_NESTING_DEADLOCK                  ((StatusType)0x14)
/*! De-scheduling with occupied spinlock */
# define E_OS_SPINLOCK                          ((StatusType)0x15)
/*! Core is not available */
# define E_OS_CORE                              ((StatusType)0x16)
/*! A null pointer was given as argument */
# define E_OS_PARAM_POINTER                     ((StatusType)0x17)

/* ----- Vector Extensions ----- */
/*! The given functionality is not enabled in the configuration */
# define E_OS_SYS_DISABLED                      ((StatusType)0xF1)
/*! The calling Task is not configured to participate in the given barrier */
# define E_OS_SYS_NO_BARRIER_PARTICIPANT        ((StatusType)0xF2)
/*! Not enough Non-Trusted Function stacks configured to execute an additional Non-Trusted Function instance. */
/*! Functionality is not implemented on this hardware */
# define E_OS_SYS_UNIMPLEMENTED_FUNCTIONALITY   ((StatusType)0xF3)
/*! Not enough Non-Trusted Function stacks configured to execute an additional Non-Trusted Function instance. */
# define E_OS_SYS_NO_NTFSTACK                   ((StatusType)0xF4)
/*! A buffer or value overflow occurred. */
# define E_OS_SYS_OVERFLOW                      ((StatusType)0xF5)
/*! Forcible termination of OS object requested. */
# define E_OS_SYS_KILL_KERNEL_OBJ               ((StatusType)0xF6)
/*! Application restart requested but no restarttask configured. */
# define E_OS_SYS_NO_RESTARTTASK                ((StatusType)0xF7)
/*! The current core may not send cross core calls to the target core. */
# define E_OS_SYS_CALL_NOT_ALLOWED              ((StatusType)0xF8)
/*! The triggerd cross core function is not available on the target core. */
# define E_OS_SYS_FUNCTION_UNAVAILABLE          ((StatusType)0xF9)
/*! An unhandled syscall occurred.  */
# define E_OS_SYS_PROTECTION_SYSCALL            ((StatusType)0xFA)
/*! An unhandled interrupt occurred.  */
# define E_OS_SYS_PROTECTION_IRQ                ((StatusType)0xFB)
/*! Wrong API usage */
# define E_OS_SYS_API_ERROR                     ((StatusType)0xFC)
/*! Internal OS assertion */
# define E_OS_SYS_ASSERTION                     ((StatusType)0xFD)
/*! A job could not be done in time */
# define E_OS_SYS_OVERLOAD                      ((StatusType)0xFE)
/*! This API call is performed on another core with no acknowledgment (yet) */
# define E_OS_SYS_CROSS_CORE_REQUESTED          ((StatusType)0xFF)

/* ----- Vector Timing Hooks Parameters ----- */
/*! \brief   The thread is a task which has terminated.
 *  \details Parameter value of hook macro OS_VTH_SCHEDULE() for parameter FromThreadReason */
#define OS_VTHP_TASK_TERMINATION   1
/*! \brief   The thread is an ISR which has reached its end.
 *  \details Parameter value of hook macro OS_VTH_SCHEDULE() for parameter FromThreadReason */
#define OS_VTHP_ISR_END            2
/*! \brief   The thread is a task which waits for an event.
 *  \details Parameter value of hook macro OS_VTH_SCHEDULE() for parameter FromThreadReason */
#define OS_VTHP_TASK_WAITEVENT     4
/*! \brief   The thread is a task which waits for a semaphore.
 *  \details Parameter value of hook macro OS_VTH_SCHEDULE() for parameter FromThreadReason */
#define OS_VTHP_TASK_WAITSEMA      8
/*! \brief   The thread is a task or ISR which is interrupted by a task or ISR with higher priority.
 *  \details Parameter value of hook macro OS_VTH_SCHEDULE() for parameter FromThreadReason */
#define OS_VTHP_THREAD_PREEMPT    16
/*! \brief   The thread is a task which was activated (therefore starts at the task start address).
 *  \details Parameter value of hook macro OS_VTH_SCHEDULE() for parameter ToThreadReason */
#define OS_VTHP_TASK_ACTIVATION    1
/*! \brief   The thread is an ISR which will now start at its start address.
 *  \details Parameter value of hook macro OS_VTH_SCHEDULE() for parameter ToThreadReason */
#define OS_VTHP_ISR_START          2
/*! \brief   The thread is a task which has shortly before received an event, it was waiting for.
 *  \details Parameter value of hook macro OS_VTH_SCHEDULE() for parameter ToThreadReason */
#define OS_VTHP_TASK_SETEVENT      4
/*! \brief   The thread is a task which has got the semaphore it was waiting for.
 *  \details Parameter value of hook macro OS_VTH_SCHEDULE() for parameter ToThreadReason */
#define OS_VTHP_TASK_GOTSEMA       8
/*! \brief   The thread is a task or ISR which was preempted before and becomes now running
 *           again as all higher priority tasks and ISRs do not run anymore.
 *  \details Parameter value of hook macro OS_VTH_SCHEDULE() for parameter ToThreadReason */
#define OS_VTHP_THREAD_RESUME     16
/*! \brief   The thread cleanup code (inside the OS) is called after the thread was forcibly terminated.
 *  \details Parameter value of hook macro OS_VTH_SCHEDULE() for parameter ToThreadReason */
#define OS_VTHP_THREAD_CLEANUP    32
/*! \brief   All category 2 ISRs have been enabled/disabled by means of a change of the current interrupt level
 *  \details Parameter value of hook macros OS_VTH_DISABLEDINT() and OS_VTH_ENABLEDINT(). */
#define OS_VTHP_CAT2INTERRUPTS     1
/*! \brief   All ISRs have been enabled/disabled by means of the global interrupt enable/disable flag
 *  \details Parameter value of hook macros OS_VTH_DISABLEDINT() and OS_VTH_ENABLEDINT(). */
#define OS_VTHP_ALLINTERRUPTS      2


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  OS_STATUS_TYPE_VARIANT()
 **********************************************************************************************************************/
/*! \def        OS_STATUS_TYPE_VARIANT()
 *  \brief      Creates a variant of a status code.
 *  \details  --no details--
 *
 *  \param[in]  Status    A standard status value.
 *  \param[in]  Variant   The number of the variant in range 1...(2^24)-1
 **********************************************************************************************************************/
# define OS_STATUS_TYPE_VARIANT(Status, Variant)                                                                        /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */\
    ((uint32) (((uint32)(Variant)) << (sizeof(StatusType)*8u)) | (uint32)(Status))


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/*! \typedef  TrustedFunctionParameterRefType
 *  \brief    This data type points to a structure which holds the arguments for a call to a trusted function.
 *  \details  --no details--
 *  \trace    SPEC-63560
 */
typedef P2VAR(void, TYPEDEF, OS_APPL_DATA) TrustedFunctionParameterRefType;

/*! This data type points to a structure which holds the arguments for a call to a non-trusted function. */
typedef P2VAR(void, TYPEDEF, OS_APPL_DATA) Os_NonTrustedFunctionParameterRefType;

/*! This data type points to a structure which holds the arguments for a call to a fast trusted function. */
typedef P2VAR(void, TYPEDEF, OS_APPL_DATA) Os_FastTrustedFunctionParameterRefType;

/*! This data type represents an application mode.
 *  \trace CREQ-118
 *  \trace SPEC-67575
 */
typedef uint8  AppModeType;


/*! \typedef  CoreIdType
 *  \brief    The core identifier type.
 *  \details  It represents logical core IDs.
 *            This data type is generated.
 *  \trace    SPEC-63895, SPEC-63942, SPEC-63552
 */


/*! This data type identifies the idle mode behavior.
 *  \trace    SPEC-63556
 */
typedef enum
{
  IDLE_NO_HALT = 0, /*!< The core does not perform any specific actions during idle time. */
  OS_IDLEMODE_COUNT = 1
} IdleModeType;


/*! Identifies an interrupt source. */
typedef uint32 Os_InterruptSourceIdType;


/*! Reference to an exception source. */
typedef P2VAR(Os_InterruptSourceIdType, TYPEDEF, AUTOMATIC) Os_InterruptSourceIdRefType;


/*! Identifies an exception source. */
typedef uint32 Os_ExceptionSourceIdType;


/*! Reference to an exception source. */
typedef P2VAR(Os_ExceptionSourceIdType, TYPEDEF, AUTOMATIC) Os_ExceptionSourceIdRefType;


/*! Reference to an exception context. */
typedef P2VAR(Os_ExceptionContextType, TYPEDEF, AUTOMATIC) Os_ExceptionContextRefType;


/*! \typedef  SpinlockIdType
 *  \brief    Identifies a spinlock instance.
 *  \details  This data type is generated.
 *  \trace    SPEC-63554
 */


/*! Indicates if the spinlock has been occupied or not.
 * \trace SPEC-63558 */
typedef enum
{
  TRYTOGETSPINLOCK_SUCCESS,   /*!< Spinlock successfully occupied. */
  TRYTOGETSPINLOCK_NOSUCCESS  /*!< Unable to occupy the spinlock. */
}TryToGetSpinlockType;


/*! \typedef  TaskType
 *  \brief    The task identifier type.
 *  \details  This data type is generated.
 */


/*! Pointer to task identifier */
typedef P2VAR(TaskType, AUTOMATIC, OS_VAR_NOINIT_FAST) TaskRefType;

/*! \brief    Possible scheduling states of a task.
 *  \details  The RUNNING state is an artificial state. It is not needed for scheduling. A task is RUNNING, if it is
 *            READY and has the highest priority of all READY tasks. The only place where the OS has to evaluate whether
 *            a task is RUNNING is in the API GetTaskState().
 *
 *            ![Task State Machine](Task_StateMachine.png)
 */
typedef enum
{
  /*! The CPU is assigned to the task.
   *  \trace CREQ-302 */
  RUNNING,
  /*! The task is ready for a transition into the RUNNING state, but waits for allocation of the processor.
   *  \trace CREQ-300 */
  READY,
  /*! The task cannot continue execution because it waits for at least one event.
   *  \trace CREQ-301 */
  WAITING,
  /*! The task is passive and can be activated.
   *  \trace CREQ-303 */
  SUSPENDED
} TaskStateType;

/*! Pointer to task scheduling state */
typedef P2VAR(TaskStateType, AUTOMATIC, OS_VAR_NOINIT_FAST) TaskStateRefType;


/*! A set of events. */
typedef uint64 EventMaskType;

/*! Pointer to a set of events. */
typedef P2VAR(EventMaskType, AUTOMATIC, OS_VAR_NOINIT) EventMaskRefType;



/*! \typedef  CounterType
 *  \brief    This data type identifies a counter.
 *  \details  This data type is generated.
 *  \trace    SPEC-63544
 */

/*! This data type represents count values in ticks.
 * \trace SPEC-63546 */
typedef uint32  PhysicalTimeType;

/*! Data type to measure time. */
typedef uint32    Os_TickType;

/*! Data type do store time differences */
typedef sint32    Os_TickDiffType; /*!< currently used for ScheduleTable only but must have same size as Os_TickType */

/*! This data type represents count values in ticks. */
typedef Os_TickType TickType;


/*! This data type points to the data type TickType. */
typedef P2VAR(TickType, AUTOMATIC, OS_VAR_NOINIT_FAST) TickRefType;



/*! \typedef  AlarmType
 *  \brief    The alarm identifier type.
 *  \details  This data type is generated.
 */

/*! Structure for AlarmBase. */
typedef struct
{
  /*! Maximum possible allowed count value (for example in ticks or angle degrees) */
  TickType maxallowedvalue;
  /*! Number of ticks required to reach a counter-specific (significant) unit. */
  TickType ticksperbase;
  /*! Minimum allowed number of ticks for a cyclic alarm (only for systems with Extended Status). */
  TickType mincycle;
}AlarmBaseType;

/*! This data type points to the data type TickType. */
typedef P2VAR(AlarmBaseType, AUTOMATIC, OS_VAR_NOINIT_FAST) AlarmBaseRefType;

/*! Specifies whether an object's application is accessible or not.
 *  \trace SPEC-63576 */
typedef enum
{
  NO_ACCESS,  /*!< The evaluated object is unavailable. */
  ACCESS      /*!< The evaluated object is available. */
} ObjectAccessType;


/*! Defines the use of a Restart Task after terminating an OS-Application.
 *  \trace SPEC-63547 */
typedef enum
{
  RESTART,              /*!< OS-Application shall be restarted. */
  NO_RESTART,           /*!< OS-Application shall not be restarted. */
  OS_RESTARTTYPE_COUNT  /*!< Number of restart types. */
} RestartType;


/*! \brief    This data type identifies the state of an OS-Application.
 *  \details  ![Application State Machine](Application_StateMachine.png)
 *
 *  \trace    SPEC-63580 */
typedef enum
{
  APPLICATION_TERMINATED = 0, /*!< The application is terminated and inaccessible. \trace CREQ-1265 */
  APPLICATION_RESTARTING,     /*!< The application is in the restart phase and inaccessible. \trace CREQ-1264 */
  APPLICATION_ACCESSIBLE      /*!< The application is active and accessible. \trace CREQ-1263 */
} ApplicationStateType;


/*! Specifies the type of the given object.
 *  \trace SPEC-63582 */
typedef enum
{
  OBJECT_TASK,          /*!< The provided object is a task. */
  OBJECT_ISR,           /*!< The provided object is an ISR. */
  OBJECT_ALARM,         /*!< The provided object is an alarm. */
  OBJECT_RESOURCE,      /*!< The provided object is a resource. */
  OBJECT_COUNTER,       /*!< The provided object is a counter. */
  OBJECT_SCHEDULETABLE, /*!< The provided object is a schedule table. */
  OBJECT_SPINLOCK       /*!< The provided object is a spinlock. */
} ObjectTypeType;


/*! The id of an OS object. */
typedef uint32 Os_ObjectIdType;


/*! \typedef  ApplicationType
 *  \brief    This data type identifies the OS-Application.
 *  \details  This data type is generated.
 *  \trace    SPEC-63579
 */


/*! This data type points to location where a ApplicationStateType can be stored.
 *  \trace SPEC-63574 */
typedef P2VAR(ApplicationStateType, AUTOMATIC, OS_VAR_NOINIT_FAST) ApplicationStateRefType;


/*! \typedef  TrustedFunctionIndexType
 *  \brief    Trusted Function identifier.
 *  \details  This data type is generated.
 *  \trace    SPEC-63571
 */


/*! \brief    Represents the identification of OS services.
 *  \details  Services which have been introduced by AUTOSAR have increasing IDs.
 *            These service IDs are specified by AUTOSAR.
 *  \trace    SPEC-67576 */
typedef enum
{
  /* ---- AUTOSAR OS ----- */
  OSServiceId_GetApplicationID            = 0x00u,  /*!< GetApplicationID() */
  OSServiceId_GetISRID                    = 0x01u,  /*!< GetISRID() */
  OSServiceId_CallTrustedFunction         = 0x02u,  /*!< CallTrustedFunction() */
  OSServiceId_CheckISRMemoryAccess        = 0x03u,  /*!< CheckISRMemoryAccess() */
  OSServiceId_CheckTaskMemoryAccess       = 0x04u,  /*!< CheckTaskMemoryAccess() */
  OSServiceId_CheckObjectAccess           = 0x05u,  /*!< CheckObjectAccess() */
  OSServiceId_CheckObjectOwnership        = 0x06u,  /*!< CheckObjectOwnership() */
  OSServiceId_StartScheduleTableRel       = 0x07u,  /*!< StartScheduleTableRel() */
  OSServiceId_StartScheduleTableAbs       = 0x08u,  /*!< StartScheduleTableAbs() */
  OSServiceId_StopScheduleTable           = 0x09u,  /*!< StopScheduleTable() */
  OSServiceId_NextScheduleTable           = 0x0au,  /*!< NextScheduleTable() */
  OSServiceId_StartScheduleTableSynchron  = 0x0bu,  /*!< StartScheduleTableSynchron() */
  OSServiceId_SyncScheduleTable           = 0x0cu,  /*!< SyncScheduleTable() */
  OSServiceId_SetScheduleTableAsync       = 0x0du,  /*!< SetScheduleTableAsync() */
  OSServiceId_GetScheduleTableStatus      = 0x0eu,  /*!< GetScheduleTableStatus() */
  OSServiceId_IncrementCounter            = 0x0fu,  /*!< IncrementCounter() */
  OSServiceId_GetCounterValue             = 0x10u,  /*!< GetCounterValue() */
  OSServiceId_GetElapsedValue             = 0x11u,  /*!< GetElapsedValue() */
  OSServiceId_TerminateApplication        = 0x12u,  /*!< TerminateApplication() */
  OSServiceId_AllowAccess                 = 0x13u,  /*!< AllowAccess() */
  OSServiceId_GetApplicationState         = 0x14u,  /*!< GetApplicationState() */
  OSServiceId_GetNumberOfActivatedCores   = 0x15u,  /*!< GetNumberOfActivatedCores() */
  OSServiceId_GetCoreID                   = 0x16u,  /*!< GetCoreID() */
  OSServiceId_StartCore                   = 0x17u,  /*!< StartCore() */
  OSServiceId_StartNonAutosarCore         = 0x18u,  /*!< StartNonAutosarCore() */
  OSServiceId_GetSpinlock                 = 0x19u,  /*!< GetSpinlock() */
  OSServiceId_ReleaseSpinlock             = 0x1au,  /*!< ReleaseSpinlock() */
  OSServiceId_TryToGetSpinlock            = 0x1bu,  /*!< TryToGetSpinlock() */
  OSServiceId_ShutdownAllCores            = 0x1cu,  /*!< ShutdownAllCores() */
  OSServiceId_ControlIdle                 = 0x1du,  /*!< ControlIdle() */
  OSServiceId_IocSend                     = 0x1eu,  /*!< IocSend() */
  OSServiceId_IocWrite                    = 0x1fu,  /*!< IocWrite() */
  OSServiceId_IocSendGroup                = 0x20u,  /*!< IocSendGroup() */
  OSServiceId_IocWriteGroup               = 0x21u,  /*!< IocWriteGroup() */
  OSServiceId_IocReceive                  = 0x22u,  /*!< IocReceive() */
  OSServiceId_IocRead                     = 0x23u,  /*!< IocRead() */
  OSServiceId_IocReceiveGroup             = 0x24u,  /*!< IocReceiveGroup() */
  OSServiceId_IocReadGroup                = 0x25u,  /*!< IocReadGroup() */
  OSServiceId_IocEmptyQueue               = 0x26u,  /*!< IocEmptyQueue() */
  OSServiceId_GetCurrentApplicationID     = 0x27u,  /*!< GetCurrentApplicationID() */

  /* ----- Vector Extensions ----- */
  OSServiceId_GetExceptionContext         = 0xA0u,  /*!< Os_GetExceptionContext() */
  OSServiceId_SetExceptionContext         = 0xA1u,  /*!< Os_SetExceptionContext() */
  OSServiceId_CallNonTrustedFunction      = 0xA2u,  /*!< Os_CallNonTrustedFunction() */
  OSServiceId_AppKill                     = 0xA3u,  /*!< Killing of applications. */
  OSServiceId_AlarmActionSetEvent         = 0xA4u,  /*!< Alarm action handlers */
  OSServiceId_AlarmActionActivateTask     = 0xA5u,  /*!< Alarm action handlers */
  OSServiceId_AlarmActionIncrementCounter = 0xA6u,  /*!< Alarm action handlers */
  OSServiceId_AlarmActionCallback         = 0xA7u,  /*!< Alarm action handlers */
  OSServiceId_TimerIsr                    = 0xA8u,  /*!< Timer ISR */
  OSServiceId_IsrWrapper                  = 0xA9u,  /*!< Category 2 ISR wrapper */
  OSServiceId_GetTaskStackUsage           = 0xAAu,  /*!< Os_GetTaskStackUsage() */
  OSServiceId_GetISRStackUsage            = 0xABu,  /*!< Os_GetISRStackUsage() */
  OSServiceId_GetKernelStackUsage         = 0xACu,  /*!< Os_GetKernelStackUsage() */
  OSServiceId_GetStartupHookStackUsage    = 0xADu,  /*!< Os_GetStartupHookStackUsage() */
  OSServiceId_GetErrorHookStackUsage      = 0xAEu,  /*!< Os_GetErrorHookStackUsage() */
  OSServiceId_GetShutdownHookStackUsage   = 0xAFu,  /*!< Os_GetShutdownHookStackUsage() */
  OSServiceId_GetProtectionHookStackUsage = 0xB0u,  /*!< Os_GetProtectionHookStackUsage() */
  OSServiceId_GetSemaphore                = 0xB1u,  /*!< GetSemaphore() (not yet implemented it there is no link presented in the CDD) */
  OSServiceId_ReleaseSemaphore            = 0xB2u,  /*!< ReleaseSemaphore() (not yet implemented it there is no link presented in the CDD) */
  OSServiceId_ScheduleTableActivateTask   = 0xB3u,  /*!< Os_SchTExPoWorkAction()/ActivateTask */
  OSServiceId_ScheduleTableSetEvent       = 0xB4u,  /*!< Os_SchTExPoWorkAction()/SetEvent */
  OSServiceId_DisableInterruptSource      = 0xB5u,  /*!< Os_DisableInterruptSource() */
  OSServiceId_EnableInterruptSource       = 0xB6u,  /*!< Os_EnableInterruptSource() */
  OSServiceId_ClearPendingInterrupt       = 0xB7u,  /*!< Os_ClearPendingInterrupt() */
  OSServiceId_GetUnhandledIrq             = 0xB8u,  /*!< Os_GetUnhandledIrq() */
  OSServiceId_GetUnhandledExc             = 0xB9u,  /*!< Os_GetUnhandledExc() */
  OSServiceId_HookCallCallback            = 0xBAu,  /*!< Os_HookCallCallback() */
  OSServiceId_IsInterruptSourceEnabled    = 0xBBu,  /*!< Os_IsInterruptSourceEnabled() */
  OSServiceId_IsInterruptPending          = 0xBCu,  /*!< Os_IsInterruptPending() */
  OSServiceId_CallFastTrustedFunction     = 0xBDu,  /*!< Os_CallFastTrustedFunction() */
  OSServiceId_BarrierSynchronize          = 0xBEu,  /*!< Os_BarrierSynchronize() */
  OSServiceId_InitialEnableInterruptSources=0xBFu,  /*!< Os_InitialEnableInterruptSources() */

  /* ----- OSEK ----- */
  OSServiceId_StartOS                     = 0xC0u,  /*!< StartOS() */
  OSServiceId_GetActiveApplicationMode    = 0xC2u,  /*!< GetActiveApplicationMode() */
  OSServiceId_DisableAllInterrupts        = 0xC3u,  /*!< DisableAllInterrupts() */
  OSServiceId_EnableAllInterrupts         = 0xC4u,  /*!< EnableAllInterrupts() */
  OSServiceId_SuspendAllInterrupts        = 0xC5u,  /*!< SuspendAllInterrupts() */
  OSServiceId_ResumeAllInterrupts         = 0xC6u,  /*!< ResumeAllInterrupts() */
  OSServiceId_SuspendOSInterrupts         = 0xC7u,  /*!< SuspendOSInterrupts() */
  OSServiceId_ResumeOSInterrupts          = 0xC8u,  /*!< ResumeOSInterrupts() */
  OSServiceId_ActivateTask                = 0xC9u,  /*!< ActivateTask() */
  OSServiceId_TerminateTask               = 0xCAu,  /*!< TerminateTask() */
  OSServiceId_ChainTask                   = 0xCBu,  /*!< ChainTask() */
  OSServiceId_GetTaskID                   = 0xCCu,  /*!< GetTaskID() */
  OSServiceId_GetTaskState                = 0xCDu,  /*!< GetTaskState() */
  OSServiceId_Schedule                    = 0xCEu,  /*!< Schedule() */
  OSServiceId_SetEvent                    = 0xCFu,  /*!< SetEvent() */
  OSServiceId_ClearEvent                  = 0xD0u,  /*!< ClearEvent() */
  OSServiceId_GetEvent                    = 0xD1u,  /*!< GetEvent() */
  OSServiceId_WaitEvent                   = 0xD2u,  /*!< WaitEvent() */
  OSServiceId_GetAlarmBase                = 0xD3u,  /*!< GetAlarmBase() */
  OSServiceId_GetAlarm                    = 0xD4u,  /*!< GetAlarm() */
  OSServiceId_SetRelAlarm                 = 0xD5u,  /*!< SetRelAlarm() */
  OSServiceId_SetAbsAlarm                 = 0xD6u,  /*!< SetAbsAlarm() */
  OSServiceId_CancelAlarm                 = 0xD7u,  /*!< CancelAlarm() */
  OSServiceId_GetResource                 = 0xD8u,  /*!< GetResource() */
  OSServiceId_ReleaseResource             = 0xD9u,  /*!< ReleaseResource() */

  OSSERVICEID_COUNT                       = 0xFF
} OSServiceIdType;



/*! \brief    Vendor specific detailed error codes.
 *  \details  Lowest 8bit are used for AUTOSAR/OSEK status codes. Higher bits are used for detailed information.
 *
 *     0xFFFFFFee
 *       |     |
 *       |     +--- Status
 *       +----- Extended information
 *  Internal comment removed.
 *
 *
 *
 */
typedef enum
{
  /* ----- OSEK ----- */
  /*! No error. */
  OS_STATUS_OK                                = E_OK,
  /*! Invalid calling context. */
  OS_STATUS_CALLEVEL                          = E_OS_CALLEVEL,
  /*! Maximum task activations reached. */
  OS_STATUS_LIMIT                             = E_OS_LIMIT,
  /*! Scheduling requested with occupied resource. */
  OS_STATUS_RESOURCE                          = E_OS_RESOURCE,

  /* ----- AUTOSAR OS ----- */
  /*! Service can not be called. */
  OS_STATUS_SERVICEID                         = E_OS_SERVICEID,
  /*!
   * \brief   An invalid address is given as a parameter to a service.
   * \details This value may only be returned in memory protected systems. As this error is hard to detected,
   *          it is handled by the Protection Hook and so E_OS_ILLEGAL_ADDRESS will never be returned by any function.*/
  OS_STATUS_ILLEGAL_ADDRESS                   = E_OS_ILLEGAL_ADDRESS,
  /*! Tasks terminates without a TerminateTask(, or ChainTask(, call. */
  OS_STATUS_MISSINGEND                        = E_OS_MISSINGEND,
  /*! A service of the OS is called inside an interrupt disable/enable pair. */
  OS_STATUS_DISABLEDINT                       = E_OS_DISABLEDINT,
  /*! A stack fault detected via stack monitoring by the OS */
  OS_STATUS_STACKFAULT                        = E_OS_STACKFAULT,
  /*! A memory access violation occurred */
  OS_STATUS_PROTECTION_MEMORY                 = E_OS_PROTECTION_MEMORY,
  /*! A Task/ISR exceeds its execution time budget  */
  OS_STATUS_PROTECTION_TIME                   = E_OS_PROTECTION_TIME,
  /*! A Task/ISR arrives before its time frame has expired */
  OS_STATUS_PROTECTION_ARRIVAL                = E_OS_PROTECTION_ARRIVAL,
  /*! A Task/Category 2 ISR blocks for too long */
  OS_STATUS_PROTECTION_LOCKED                 = E_OS_PROTECTION_LOCKED,
  /*! A trap occurred  */
  OS_STATUS_PROTECTION_EXCEPTION              = E_OS_PROTECTION_EXCEPTION,
  /*! Deadlock situation due to interference */
  OS_STATUS_INTERFERENCE_DEADLOCK             = E_OS_INTERFERENCE_DEADLOCK,
  /*! Potential deadlock due to wrong nesting */
  OS_STATUS_NESTING_DEADLOCK                  = E_OS_NESTING_DEADLOCK,
  /*! De-scheduling with occupied spinlock */
  OS_STATUS_SPINLOCK                          = E_OS_SPINLOCK,
  /*! Core is not available */
  OS_STATUS_CORE                              = E_OS_CORE,
  /*! A null pointer was given as argument */
  /* OS_STATUS_PARAM_POINTER                     = E_OS_PARAM_POINTER, */

  /* ----- Vector Extensions ----- */
  /*! Forcible termination of kernel object requested. */
  OS_STATUS_KILL_KERNEL_OBJ                   = E_OS_SYS_KILL_KERNEL_OBJ,
  /*! Application restart requested but no restart task configured. */
  OS_STATUS_NO_RESTARTTASK                    = E_OS_SYS_NO_RESTARTTASK,
  /*! An unhandled interrupt occurred  */
  OS_STATUS_PROTECTION_IRQ                    = E_OS_SYS_PROTECTION_IRQ,
  /*! An unhandled syscall occurred  */
  OS_STATUS_PROTECTION_SYSCALL                = E_OS_SYS_PROTECTION_SYSCALL,
  /*! Wrong API usage */
  OS_STATUS_API_ERROR                         = E_OS_SYS_API_ERROR,
  /*! Internal OS assertion */
  OS_STATUS_ASSERTION                         = E_OS_SYS_ASSERTION,
  /*! A job could not be done in time */
  OS_STATUS_OVERLOAD                          = E_OS_SYS_OVERLOAD,
  /*! The current core may not send cross core calls to the target core. */
  OS_STATUS_CALL_NOT_ALLOWED                  = E_OS_SYS_CALL_NOT_ALLOWED,
  /*! The triggerd cross core function is not available on the target core. */
  OS_STATUS_FUNCTION_UNAVAILABLE              = E_OS_SYS_FUNCTION_UNAVAILABLE,
  /*! A buffer or value overflow occurred. */
  OS_STATUS_OVERFLOW                          = E_OS_SYS_OVERFLOW,

  /*! Invalid calling context. */
  OS_STATUS_CALLEVEL_SHARED_STACK             = (OS_STATUS_TYPE_VARIANT(E_OS_CALLEVEL, 1u)),
  /*! Invalid calling context. */
  OS_STATUS_CALLEVEL_CROSS_CORE_SYNC          = (OS_STATUS_TYPE_VARIANT(E_OS_CALLEVEL, 2u)),
  /*! OS object is accessed in the wrong order. */
  OS_STATUS_ORDER                             = (OS_STATUS_TYPE_VARIANT(E_OS_RESOURCE, 1u)),
  /*! Tried to release a resource in an non LIFO order. */
  OS_STATUS_LIFO_TOP_IS_SPINLOCK              = (OS_STATUS_TYPE_VARIANT(E_OS_RESOURCE, 2u)),
  /*! Tried to release a spinlock in an non LIFO order. */
  OS_STATUS_LIFO_TOP_IS_RESOURCE              = (OS_STATUS_TYPE_VARIANT(E_OS_RESOURCE, 3u)),
  /*! No access for object given in parameter 1. */
  OS_STATUS_ACCESSRIGHTS_1                    = (OS_STATUS_TYPE_VARIANT(E_OS_ACCESS, 1u)),
  /*! No access for object given in parameter 2. */
  OS_STATUS_ACCESSRIGHTS_2                    = (OS_STATUS_TYPE_VARIANT(E_OS_ACCESS, 2u)),
  /*! Application state for object given in parameter 1 is not accessible. */
  OS_STATUS_NOTACCESSIBLE_1                   = (OS_STATUS_TYPE_VARIANT(E_OS_ACCESS, 3u)),
  /*! Application state for object given in parameter 2 is not accessible. */
  OS_STATUS_NOTACCESSIBLE_2                   = (OS_STATUS_TYPE_VARIANT(E_OS_ACCESS, 4u)),
  /*! ID given in parameter 1 does not belong to an extended task. */
  OS_STATUS_NOEXTENDEDTASK_1                  = (OS_STATUS_TYPE_VARIANT(E_OS_ACCESS, 5u)),
  /*! ID given in parameter 2 does not belong to an extended task. */
  OS_STATUS_NOEXTENDEDTASK_2                  = (OS_STATUS_TYPE_VARIANT(E_OS_ACCESS, 6u)),
  /*! The caller is not an extended task. */
  OS_STATUS_NOEXTENDEDTASK_CALLER             = (OS_STATUS_TYPE_VARIANT(E_OS_ACCESS, 7u)),
  /*! The given lock is already locked. */
  OS_STATUS_LOCKED                            = (OS_STATUS_TYPE_VARIANT(E_OS_ACCESS, 8u)),
  /*! The given object has an invalid priority. */
  OS_STATUS_PRIORITY                          = (OS_STATUS_TYPE_VARIANT(E_OS_ACCESS, 9u)),
  /*! The caller is not the owner of the accessed object in parameter 1. */
  OS_STATUS_NOT_THE_OWNER_1                   = (OS_STATUS_TYPE_VARIANT(E_OS_ACCESS, 10u)),
  /*! ID given in parameter 1 is invalid. */
  OS_STATUS_ID_1                              = (OS_STATUS_TYPE_VARIANT(E_OS_ID, 1u)),
  /*! ID given in parameter 2 is invalid. */
  OS_STATUS_ID_2                              = (OS_STATUS_TYPE_VARIANT(E_OS_ID, 2u)),
  /*! Type given in parameter 1- is invalid. */
  OS_STATUS_ID_TYPE_1                         = (OS_STATUS_TYPE_VARIANT(E_OS_ID, 3u)),
  /*! Type given objects are assigned to different counters. */
  OS_STATUS_ID_DIFFERENT_COUNTER              = (OS_STATUS_TYPE_VARIANT(E_OS_ID, 4u)),
  /*! Type given objects have different synchronization types. */
  OS_STATUS_ID_DIFFERENT_SYNC                 = (OS_STATUS_TYPE_VARIANT(E_OS_ID, 5u)),
  /*! The requested hook is not available. */
  OS_STATUS_HOOK_NOT_AVAILABLE                = (OS_STATUS_TYPE_VARIANT(E_OS_ID, 6u)),
  /*! OS object is currently unlocked. */
  OS_STATUS_UNLOCKED                          = (OS_STATUS_TYPE_VARIANT(E_OS_NOFUNC, 1u)),
  /*! OS object given in parameter 1 is currently not in use. */
  OS_STATUS_NOFUNC_1                          = (OS_STATUS_TYPE_VARIANT(E_OS_NOFUNC, 2u)),
  /*! OS object given in parameter 2 is currently not in use. */
  OS_STATUS_NOFUNC_2                          = (OS_STATUS_TYPE_VARIANT(E_OS_NOFUNC, 3u)),
  /*! OS object given in parameter 1 is currently not in use. */
  OS_STATUS_SPINLOCK_ORDER                    = (OS_STATUS_TYPE_VARIANT(E_OS_NOFUNC, 4u)),
  /*! OS object given in parameter 1 is currently stopped. */
  OS_STATUS_STOPPED_1                         = (OS_STATUS_TYPE_VARIANT(E_OS_NOFUNC, 5u)),
  /*! OS object given in parameter 2 is currently not stopped. */
  OS_STATUS_NOT_STOPPED_2                     = (OS_STATUS_TYPE_VARIANT(E_OS_NOFUNC, 6u)),
  /*! OS object given in parameter 1 is currently nexted. */
  OS_STATUS_NEXTED_1                          = (OS_STATUS_TYPE_VARIANT(E_OS_NOFUNC, 7u)),
  /*! Operation not permitted when killing is disabled. */
  OS_STATUS_KILLING_IS_DISABLED               = (OS_STATUS_TYPE_VARIANT(E_OS_NOFUNC, 8u)),
  /*! OS object is not in correct state to perform the requested operation. */
  OS_STATUS_STATE_1                           = (OS_STATUS_TYPE_VARIANT(E_OS_STATE, 1u)),
  /*! OS object is not in correct state to perform the requested operation. */
  OS_STATUS_STATE_2                           = (OS_STATUS_TYPE_VARIANT(E_OS_STATE, 2u)),
  /*! OS object is in stopped state and not allowed to perform the requested operation. */
  OS_STATUS_STATE_STOPPED                     = (OS_STATUS_TYPE_VARIANT(E_OS_STATE, 3u)),
  /*! OS object is in running state and not allowed to perform the requested operation. */
  OS_STATUS_STATE_RUNNING                     = (OS_STATUS_TYPE_VARIANT(E_OS_STATE, 4u)),
  /*! OS object is in next state and not allowed to perform the requested operation. */
  OS_STATUS_STATE_NEXTED                      = (OS_STATUS_TYPE_VARIANT(E_OS_STATE, 5u)),
  /*! OS object is in waiting state and not allowed to perform the requested operation. */
  OS_STATUS_STATE_WAITING                     = (OS_STATUS_TYPE_VARIANT(E_OS_STATE, 6u)),
  /*! The current application is not in the restarting state. */
  OS_STATUS_STATE_NO_RESTART                  = (OS_STATUS_TYPE_VARIANT(E_OS_STATE, 7u)),
  /*! Termination requested for an application which is already terminated. */
  OS_STATUS_STATE_ALREADY_TERMINATED          = (OS_STATUS_TYPE_VARIANT(E_OS_STATE, 8u)),
  /*! The application is restarting AND the caller does not belong to the application. */
  OS_STATUS_STATE_RESTARTING_NO_MEMBER        = (OS_STATUS_TYPE_VARIANT(E_OS_STATE, 9u)),
  /*! Restart requested for an application which is already restarting. */
  OS_STATUS_STATE_ALREADY_RESTARTING          = (OS_STATUS_TYPE_VARIANT(E_OS_STATE, 10u)),
  /*! Value given in parameter 1 is zero. */
  OS_STATUS_VALUE_IS_ZERO_1                   = (OS_STATUS_TYPE_VARIANT(E_OS_VALUE, 1u)),
  /*! Value given in parameter 2 is zero. */
  OS_STATUS_VALUE_IS_ZERO_2                   = (OS_STATUS_TYPE_VARIANT(E_OS_VALUE, 2u)),
  /*! Value given in parameter 1 is to high. */
  OS_STATUS_VALUE_IS_TOO_HIGH_1               = (OS_STATUS_TYPE_VARIANT(E_OS_VALUE, 3u)),
  /*! Value given in parameter 2 is to high. */
  OS_STATUS_VALUE_IS_TOO_HIGH_2               = (OS_STATUS_TYPE_VARIANT(E_OS_VALUE, 4u)),
  /*! Value given in parameter 3 is to high. */
  OS_STATUS_VALUE_IS_TOO_HIGH_3               = (OS_STATUS_TYPE_VARIANT(E_OS_VALUE, 5u)),
  /*! Value given in parameter 1 is out of bounds. */
  OS_STATUS_VALUE_IS_OUT_OF_BOUNDS_1          = (OS_STATUS_TYPE_VARIANT(E_OS_VALUE, 6u)),
  /*! Value given in parameter 2 is out of bounds. */
  OS_STATUS_VALUE_IS_OUT_OF_BOUNDS_2          = (OS_STATUS_TYPE_VARIANT(E_OS_VALUE, 7u)),
  /*! Value given in parameter 1 is to low. */
  OS_STATUS_VALUE_IS_TOO_LOW_1                = (OS_STATUS_TYPE_VARIANT(E_OS_VALUE, 8u)),
  /*! Value given in parameter 2 is to low. */
  OS_STATUS_VALUE_IS_TOO_LOW_2                = (OS_STATUS_TYPE_VARIANT(E_OS_VALUE, 9u)),
  /*! Value given in parameter 3 is to low. */
  OS_STATUS_VALUE_IS_TOO_LOW_3                = (OS_STATUS_TYPE_VARIANT(E_OS_VALUE, 10u)),
  /*! Value given in parameter 2 has to be TRUE or FALSE. */
  OS_STATUS_VALUE_IS_NOT_BOOLEAN              = (OS_STATUS_TYPE_VARIANT(E_OS_VALUE, 11u)),
  /*! The data passed to the receiver of a cross core request is invalid. */
  OS_STATUS_CORE_CROSS_DATA                   = (OS_STATUS_TYPE_VARIANT(E_OS_CORE, 1u)),
  /*! Pointer given in parameter 1 is null. */
  OS_STATUS_PARAM_POINTER_1                   = (OS_STATUS_TYPE_VARIANT(E_OS_PARAM_POINTER, 1u)),
  /*! Pointer given in parameter 2 is null. */
  OS_STATUS_PARAM_POINTER_2                   = (OS_STATUS_TYPE_VARIANT(E_OS_PARAM_POINTER, 2u)),
  /*! Pointer given in parameter 3 is null. */
  OS_STATUS_PARAM_POINTER_3                   = (OS_STATUS_TYPE_VARIANT(E_OS_PARAM_POINTER, 3u)),
  /*! Not enough Non-Trusted Function stacks configured to execute an additional Non-Trusted Function instance. */
  OS_STATUS_NO_NTFSTACK_POOL_EMPTY            = (OS_STATUS_TYPE_VARIANT(E_OS_SYS_NO_NTFSTACK, 1u)),
  /*! Not enough Non-Trusted Function stacks configured for the caller application. */
  OS_STATUS_NO_NTFSTACK_APPLIMIT_EXCEEDED     = (OS_STATUS_TYPE_VARIANT(E_OS_SYS_NO_NTFSTACK, 2u)),
  /*! Hardware does not support to clear an interrupt pending flag */
  OS_STATUS_UNIMPLEMENTED_CLEARPENDING        = (OS_STATUS_TYPE_VARIANT(E_OS_SYS_UNIMPLEMENTED_FUNCTIONALITY, 1u)),
  /*! The functionality of exception context manipulation is not implemented for this hardware */
  OS_STATUS_UNIMPLEMENTED_EXCEPTIONCONTEXT    = (OS_STATUS_TYPE_VARIANT(E_OS_SYS_UNIMPLEMENTED_FUNCTIONALITY, 2u)),
  /*! The calling Task is not configured to participate in the given barrier */
  OS_STATUS_NO_BARRIER_PARTICIPANT            = (OS_STATUS_TYPE_VARIANT(E_OS_SYS_NO_BARRIER_PARTICIPANT, 1u)),
  /*! Stack Usage Measurement is not enabled in the configuration */
  OS_STATUS_STACKUSAGE_DISABLED_BY_CONFIG     = (OS_STATUS_TYPE_VARIANT(E_OS_SYS_DISABLED, 1u))

} Os_StatusType;

/*! This data type identifies a value which controls further actions of the OS on return from the ProtectionHook().
 * \trace SPEC-63553
 */
typedef enum
{
  PRO_IGNORE,                     /*!< The OS shall ignore the error and continue normal operation. */
  PRO_IGNORE_EXCEPTION,           /*!< The OS shall ignore the error and continue normal operation. */
  PRO_TERMINATETASKISR,           /*!< The OS shall forcibly terminate the faulty Task/ ISR. */
  PRO_TERMINATEAPPL,              /*!< The OS shall forcibly terminate the faulty OS-Application. */
  PRO_TERMINATEAPPL_RESTART,      /*!< The OS shall forcibly terminate the faulty OS-Application and afterwards restart
                                       the OS-Application. */
  PRO_SHUTDOWN,                   /*!< The OS shall shutdown the OS. */
  OS_PROTECTIONREACTION_COUNT     /*!< Out of range boundary value. */
} ProtectionReturnType;


/*! Identifies parameters within a API prototype. */
typedef enum
{
  OS_ERRORPARAMINDEX_1 = 0,
  OS_ERRORPARAMINDEX_2 = 1,
  OS_ERRORPARAMINDEX_3 = 2,
  OS_ERRORPARAMINDEX_COUNT = 3
}Os_ErrorParmIndexType;


/*! Error information data type, which can be fetched by Os_GetDetailedError(). */
typedef struct
{
  /*! Service which was processed while the error occurred. */
  OSServiceIdType Service;

  /*! AUTOSAR OS status code of the occurred error. */
  StatusType Error;

  /*! Holds the unambiguous error information. */
  Os_StatusType DetailedError;
} Os_ErrorInformationType;


/*! Defines a reference to an Os_ErrorInformationType. */
typedef P2VAR(Os_ErrorInformationType, AUTOMATIC, OS_APPL_VAR) Os_ErrorInformationRefType;


/*! \typedef  ResourceType
 *  \brief    This data type identifies a resource.
 *  \details  This data type is generated.
 *  \trace    SPEC-67382
 */



/*! \typedef  ScheduleTableType
 *  \brief    The schedule table identifier type.
 *  \details  This data type is generated.
 *  \trace    SPEC-63559
 */


/*! \brief    ScheduleTable states.
 *  \details
 *  ![Schedule Table State Machine (No Synchronization)](SchT_StateMachine.png)
 *
 *  ![Schedule Table State Machine (Implicit Synchronization)](SchT_SyncImplicit_StateMachine.png)
 *
 *  ![Schedule Table State Machine (Explicit Synchronization)](SchT_SyncExplicit_StateMachine.png)
 *
 *  \trace    SPEC-63548
 */
typedef enum
{
  /*! The schedule table was stopped or is in default state.
   * \trace CREQ-308 */
  SCHEDULETABLE_STOPPED                 = 0,
  /*! The schedule table is registered to be the next schedule table after another one has finished.
   * \trace CREQ-305 */
  SCHEDULETABLE_NEXT                    = 1,
  /*! The schedule table waits for provision of a synchronization count.
   * \trace CREQ-309 */
  SCHEDULETABLE_WAITING                 = 2,
  /*! The schedule table runs but may be not synchronous cannot be synchronized at all.
   * \trace CREQ-310 */
  SCHEDULETABLE_RUNNING                 = 3,
  /*! The schedule table runs and is synchronous.
   *  \trace CREQ-311 */
  SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS = 4
} ScheduleTableStatusType;

/*! Reference to a schedule table status type \trace SPEC-63551 */
typedef ScheduleTableStatusType *ScheduleTableStatusRefType;


/*! The address type of a region. */
typedef Os_Hal_AddressType  Os_AccessCheckAddress;

/*! Data type for pointers to any (constant) location in the MCU address space.
 *  \trace SPEC-63568 */
typedef P2CONST(void, AUTOMATIC, OS_VAR_NOINIT) MemoryStartAddressType;

/*! Data type holds the size (in bytes) of a memory region.
 *  \trace SPEC-63563 */
typedef Os_AccessCheckAddress MemorySizeType;


/*! Access rights of a task/ISR/Application to a memory region */
typedef enum
{
  OS_MEM_ACCESS_TYPE_NON     = 0,  /*!< No access rights are granted                                             */
  OS_MEM_ACCESS_TYPE_READ    = 1,  /*!< Read access right is granted                                             */
  OS_MEM_ACCESS_TYPE_R       = 1,  /*!< Read access right is granted (R: short form of READ)                     */
  OS_MEM_ACCESS_TYPE_WRITE   = 2,  /*!< Write access right is granted                                            */
  OS_MEM_ACCESS_TYPE_W       = 2,  /*!< Write access right is granted (W: short form of WRITE)                   */
  OS_MEM_ACCESS_TYPE_RW      = 3,  /*!< Read/Write access rights are granted                                     */
  OS_MEM_ACCESS_TYPE_EXECUTE = 4,  /*!< Execution right is granted                                               */
  OS_MEM_ACCESS_TYPE_X       = 4,  /*!< Execution right is granted (X: short form of EXECUTE)                    */
  OS_MEM_ACCESS_TYPE_RX      = 5,  /*!< Read access and Execution rights are granted                             */
  OS_MEM_ACCESS_TYPE_WX      = 6,  /*!< Write access and execution rights are granted                            */
  OS_MEM_ACCESS_TYPE_RWX     = 7,  /*!< Read/Write access and execution rights are granted                       */
  OS_MEM_ACCESS_TYPE_STACK   = 8,  /*!< This is stack region                                                     */
  OS_MEM_ACCESS_TYPE_S       = 8,  /*!< This is stack region (S: short form of STACK)                            */
  OS_MEM_ACCESS_TYPE_RS      = 9,  /*!< Read access right is granted, this is stack region                       */
  OS_MEM_ACCESS_TYPE_WS      = 10, /*!< Write access right is granted, this is stack region                      */
  OS_MEM_ACCESS_TYPE_RWS     = 11, /*!< Read/Write access rights are granted, this is stack region               */
  OS_MEM_ACCESS_TYPE_XS      = 12, /*!< Execution right is granted, this is stack region                         */
  OS_MEM_ACCESS_TYPE_RXS     = 13, /*!< Read access and Execution rights are granted, this is stack region       */
  OS_MEM_ACCESS_TYPE_WXS     = 14, /*!< Write access and execution rights are granted, this is stack region      */
  OS_MEM_ACCESS_TYPE_RWXS    = 15  /*!< Read/Write access and execution rights are granted, this is stack region */
} Os_MemAccessType;

typedef Os_MemAccessType AccessType; /*!< Autosar type for the access rights of a task/ISR to a memory region */


/*! Data type for writable addresses. */
typedef P2VAR(void, TYPEDEF, AUTOMATIC) Os_AddressType;
/*! Data type for readable addresses. */
typedef P2CONST(void, TYPEDEF, AUTOMATIC) Os_AddressOfConstType;



/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/



#endif /* OS_TYPES_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_Types.h
 **********************************************************************************************************************/
