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
 * \addtogroup Os_Thread
 * \{
 *
 * \file          Os_Thread_Types.h
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_THREAD_TYPES_H
# define OS_THREAD_TYPES_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
# include "Std_Types.h"
# include "Os_Hal_Context_Types.h"


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/
/*! Call context ID for Tasks. */
# define OS_CALLCONTEXT_TASK              ((Os_CallContextType)1 <<  0)
/*! Call context ID for Category 2 ISRs. */
# define OS_CALLCONTEXT_ISR2              ((Os_CallContextType)1 <<  1)
/*! Call context ID for Error Hooks. */
# define OS_CALLCONTEXT_ERRORHOOK         ((Os_CallContextType)1 <<  2)
/*! Call context ID for PreTask Hooks. */
# define OS_CALLCONTEXT_PRETASKHOOK       ((Os_CallContextType)1 <<  3)
/*! Call context ID for PostTask Hooks. */
# define OS_CALLCONTEXT_POSTTASKHOOK      ((Os_CallContextType)1 <<  4)
/*! Call context ID for Startup Hooks. */
# define OS_CALLCONTEXT_STARTUPHOOK       ((Os_CallContextType)1 <<  5)
/*! Call context ID for Shutdown Hooks. */
# define OS_CALLCONTEXT_SHUTDOWNHOOK      ((Os_CallContextType)1 <<  6)
/*! Call context ID for Alarm Callbacks. */
# define OS_CALLCONTEXT_ALARMCALLBACK     ((Os_CallContextType)1 <<  7)
/*! Call context ID for Protection Hooks. */
# define OS_CALLCONTEXT_PROTECTIONHOOK    ((Os_CallContextType)1 <<  8)
/*! Call context ID for Pre-Start Tasks. */
# define OS_CALLCONTEXT_PRESTARTTASK      ((Os_CallContextType)1 <<  9)
/*! Call context ID for Timing Protection ISR. */
# define OS_CALLCONTEXT_TPISR             ((Os_CallContextType)1 << 10)
/*! Call context ID for Callbacks. */
# define OS_CALLCONTEXT_IOCCALLBACK       ((Os_CallContextType)1 << 11)
/*! Call context ID for Init Hooks. */
# define OS_CALLCONTEXT_INITHOOK          ((Os_CallContextType)1 << 12)

/*! Any Category2 ISR (allows easy check whether the current context is a ISR function) */
# define OS_CALLCONTEXT_ISR               ((Os_CallContextType)(OS_CALLCONTEXT_ISR2          |   \
                                                                OS_CALLCONTEXT_TPISR          ))

/*! Any Hook (allows easy check whether the current context is a hook function) */
# define OS_CALLCONTEXT_ANYHOOK           ((Os_CallContextType)(OS_CALLCONTEXT_ERRORHOOK     |   \
                                                                OS_CALLCONTEXT_PRETASKHOOK   |   \
                                                                OS_CALLCONTEXT_POSTTASKHOOK  |   \
                                                                OS_CALLCONTEXT_STARTUPHOOK   |   \
                                                                OS_CALLCONTEXT_SHUTDOWNHOOK  |   \
                                                                OS_CALLCONTEXT_ALARMCALLBACK |   \
                                                                OS_CALLCONTEXT_PROTECTIONHOOK|   \
                                                                OS_CALLCONTEXT_IOCCALLBACK   |   \
                                                                OS_CALLCONTEXT_INITHOOK       ))

/*! All contexts except the timing protection ISR and the InitHook. */
# define OS_CALLCONTEXT_TERMINATEABLE    ((Os_CallContextType)( OS_CALLCONTEXT_TASK          |   \
                                                                OS_CALLCONTEXT_ISR2          |   \
                                                                OS_CALLCONTEXT_ERRORHOOK     |   \
                                                                OS_CALLCONTEXT_PRETASKHOOK   |   \
                                                                OS_CALLCONTEXT_POSTTASKHOOK  |   \
                                                                OS_CALLCONTEXT_STARTUPHOOK   |   \
                                                                OS_CALLCONTEXT_SHUTDOWNHOOK  |   \
                                                                OS_CALLCONTEXT_IOCCALLBACK   |   \
                                                                OS_CALLCONTEXT_PRESTARTTASK  |   \
                                                                OS_CALLCONTEXT_ALARMCALLBACK  ))



/* ----- Allowed call contexts for each API ----- */
/*! Calling Context: ActivateTask() */
#define OS_APICONTEXT_ACTIVATETASK                ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2))
/*! Calling Context: TerminateTask() */
#define OS_APICONTEXT_TERMINATETASK               ((Os_CallContextType)(OS_CALLCONTEXT_TASK))
/*! Calling Context: ChainTask() */
#define OS_APICONTEXT_CHAINTASK                   ((Os_CallContextType)(OS_CALLCONTEXT_TASK))
/*! Calling Context: Schedule() */
#define OS_APICONTEXT_SCHEDULE                    ((Os_CallContextType)(OS_CALLCONTEXT_TASK))
/*! Calling Context: GetTaskID() */
#define OS_APICONTEXT_GETTASKID                   ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2 | \
                                                                        OS_CALLCONTEXT_ERRORHOOK | \
                                                                        OS_CALLCONTEXT_PRETASKHOOK | \
                                                                        OS_CALLCONTEXT_POSTTASKHOOK | \
                                                                        OS_CALLCONTEXT_PROTECTIONHOOK))
/*! Calling Context: GetTaskState() */
#define OS_APICONTEXT_GETTASKSTATE                ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2 | \
                                                                        OS_CALLCONTEXT_ERRORHOOK | \
                                                                        OS_CALLCONTEXT_PRETASKHOOK | \
                                                                        OS_CALLCONTEXT_POSTTASKHOOK))

/*! Calling Context: Os_BarrierSynchronize() */
#define OS_APICONTEXT_BARRIERSYNCHRONIZE          ((Os_CallContextType)(OS_CALLCONTEXT_TASK))

/*! Calling Context: DisableAllInterrupts() */
#define OS_APICONTEXT_DISABLEALLINTERRUPTS        ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2 | \
                                                                        OS_CALLCONTEXT_PRESTARTTASK | \
                                                                        OS_CALLCONTEXT_ERRORHOOK | \
                                                                        OS_CALLCONTEXT_PRETASKHOOK | \
                                                                        OS_CALLCONTEXT_POSTTASKHOOK | \
                                                                        OS_CALLCONTEXT_STARTUPHOOK | \
                                                                        OS_CALLCONTEXT_SHUTDOWNHOOK | \
                                                                        OS_CALLCONTEXT_ALARMCALLBACK | \
                                                                        OS_CALLCONTEXT_PROTECTIONHOOK))
/*! Calling Context: EnableAllInterrupts() */
#define OS_APICONTEXT_ENABLEALLINTERRUPTS         ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2 | \
                                                                        OS_CALLCONTEXT_PRESTARTTASK | \
                                                                        OS_CALLCONTEXT_ERRORHOOK | \
                                                                        OS_CALLCONTEXT_PRETASKHOOK | \
                                                                        OS_CALLCONTEXT_POSTTASKHOOK | \
                                                                        OS_CALLCONTEXT_STARTUPHOOK | \
                                                                        OS_CALLCONTEXT_SHUTDOWNHOOK | \
                                                                        OS_CALLCONTEXT_ALARMCALLBACK | \
                                                                        OS_CALLCONTEXT_PROTECTIONHOOK))
/*! Calling Context: SuspendAllInterrupts() */
#define OS_APICONTEXT_SUSPENDALLINTERRUPTS        ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2 | \
                                                                        OS_CALLCONTEXT_PRESTARTTASK | \
                                                                        OS_CALLCONTEXT_ERRORHOOK | \
                                                                        OS_CALLCONTEXT_PRETASKHOOK | \
                                                                        OS_CALLCONTEXT_POSTTASKHOOK | \
                                                                        OS_CALLCONTEXT_STARTUPHOOK | \
                                                                        OS_CALLCONTEXT_SHUTDOWNHOOK | \
                                                                        OS_CALLCONTEXT_ALARMCALLBACK | \
                                                                        OS_CALLCONTEXT_PROTECTIONHOOK))
/*! Calling Context: ResumeAllInterrupts() */
#define OS_APICONTEXT_RESUMEALLINTERRUPTS         ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2 | \
                                                                        OS_CALLCONTEXT_PRESTARTTASK | \
                                                                        OS_CALLCONTEXT_ERRORHOOK | \
                                                                        OS_CALLCONTEXT_PRETASKHOOK | \
                                                                        OS_CALLCONTEXT_POSTTASKHOOK | \
                                                                        OS_CALLCONTEXT_STARTUPHOOK | \
                                                                        OS_CALLCONTEXT_SHUTDOWNHOOK | \
                                                                        OS_CALLCONTEXT_ALARMCALLBACK | \
                                                                        OS_CALLCONTEXT_PROTECTIONHOOK))
/*! Calling Context: SuspendOSInterrupts() */
#define OS_APICONTEXT_SUSPENDOSINTERRUPTS         ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2 | \
                                                                        OS_CALLCONTEXT_PRESTARTTASK | \
                                                                        OS_CALLCONTEXT_ERRORHOOK | \
                                                                        OS_CALLCONTEXT_PRETASKHOOK | \
                                                                        OS_CALLCONTEXT_POSTTASKHOOK | \
                                                                        OS_CALLCONTEXT_STARTUPHOOK | \
                                                                        OS_CALLCONTEXT_SHUTDOWNHOOK | \
                                                                        OS_CALLCONTEXT_ALARMCALLBACK | \
                                                                        OS_CALLCONTEXT_PROTECTIONHOOK))
/*! Calling Context: ResumeOSInterrupts() */
#define OS_APICONTEXT_RESUMEOSINTERRUPTS          ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2 | \
                                                                        OS_CALLCONTEXT_PRESTARTTASK | \
                                                                        OS_CALLCONTEXT_ERRORHOOK | \
                                                                        OS_CALLCONTEXT_PRETASKHOOK | \
                                                                        OS_CALLCONTEXT_POSTTASKHOOK | \
                                                                        OS_CALLCONTEXT_STARTUPHOOK | \
                                                                        OS_CALLCONTEXT_SHUTDOWNHOOK | \
                                                                        OS_CALLCONTEXT_ALARMCALLBACK | \
                                                                        OS_CALLCONTEXT_PROTECTIONHOOK))
/*! Calling Context: GetResource() */
#define OS_APICONTEXT_GETRESOURCE                 ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2))
/*! Calling Context: ReleaseResource() */
#define OS_APICONTEXT_RELEASERESOURCE             ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2))
/*! Calling Context: SetEvent() */
#define OS_APICONTEXT_SETEVENT                    ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2))
/*! Calling Context: ClearEvent() */
#define OS_APICONTEXT_CLEAREVENT                  ((Os_CallContextType)(OS_CALLCONTEXT_TASK))
/*! Calling Context: GetEvent() */
#define OS_APICONTEXT_GETEVENT                    ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2 | \
                                                                        OS_CALLCONTEXT_ERRORHOOK | \
                                                                        OS_CALLCONTEXT_PRETASKHOOK | \
                                                                        OS_CALLCONTEXT_POSTTASKHOOK))
/*! Calling Context: WaitEvent() */
#define OS_APICONTEXT_WAITEVENT                   ((Os_CallContextType)(OS_CALLCONTEXT_TASK))
/*! Calling Context: GetAlarmBase() */
#define OS_APICONTEXT_GETALARMBASE                ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2 | \
                                                                        OS_CALLCONTEXT_ERRORHOOK | \
                                                                        OS_CALLCONTEXT_PRETASKHOOK | \
                                                                        OS_CALLCONTEXT_POSTTASKHOOK))
/*! Calling Context: GetAlarm() */
#define OS_APICONTEXT_GETALARM                    ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2 | \
                                                                        OS_CALLCONTEXT_ERRORHOOK | \
                                                                        OS_CALLCONTEXT_PRETASKHOOK | \
                                                                        OS_CALLCONTEXT_POSTTASKHOOK))
/*! Calling Context: SetRelAlarm() */
#define OS_APICONTEXT_SETRELALARM                 ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2))
/*! Calling Context: SetAbsAlarm() */
#define OS_APICONTEXT_SETABSALARM                 ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2))
/*! Calling Context: CancelAlarm() */
#define OS_APICONTEXT_CANCELALARM                 ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2))
/*! Calling Context: GetActiveApplicationMode() */
#define OS_APICONTEXT_GETACTIVEAPPLICATIONMODE    ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2 | \
                                                                        OS_CALLCONTEXT_ERRORHOOK | \
                                                                        OS_CALLCONTEXT_PRETASKHOOK | \
                                                                        OS_CALLCONTEXT_POSTTASKHOOK | \
                                                                        OS_CALLCONTEXT_STARTUPHOOK | \
                                                                        OS_CALLCONTEXT_SHUTDOWNHOOK))
/*! Calling Context: StartOS() */
#define OS_APICONTEXT_STARTOS                     ((Os_CallContextType)(0))
/*! Calling Context: ShutdownOS() */
#define OS_APICONTEXT_SHUTDOWNOS                  ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2 | \
                                                                        OS_CALLCONTEXT_ERRORHOOK | \
                                                                        OS_CALLCONTEXT_STARTUPHOOK))
/*! Calling Context: GetApplicationID() */
#define OS_APICONTEXT_GETAPPLICATIONID            ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2 | \
                                                                        OS_CALLCONTEXT_ERRORHOOK | \
                                                                        OS_CALLCONTEXT_PRETASKHOOK | \
                                                                        OS_CALLCONTEXT_POSTTASKHOOK | \
                                                                        OS_CALLCONTEXT_STARTUPHOOK | \
                                                                        OS_CALLCONTEXT_SHUTDOWNHOOK | \
                                                                        OS_CALLCONTEXT_PROTECTIONHOOK))
/*! Calling Context: GetISRID() */
#define OS_APICONTEXT_GETISRID                    ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2 | \
                                                                        OS_CALLCONTEXT_ERRORHOOK | \
                                                                        OS_CALLCONTEXT_PROTECTIONHOOK))
/*! Calling Context: Os_DisableInterruptSource() */
#define OS_APICONTEXT_ISRDISABLESOURCE            ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2))

/*! Calling Context: Os_EnableInterruptSource() */
#define OS_APICONTEXT_ISRENABLESOURCE             ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2))

/*! Calling Context: Os_InitialEnableInterruptSources() */
#define OS_APICONTEXT_ISRINITENABLESOURCE         ((Os_CallContextType)(OS_CALLCONTEXT_TASK))

/*! Calling Context: Os_ClearPendingInterrupt() */
#define OS_APICONTEXT_ISRCLEARPENDING             ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2))

/*! Calling Context: Os_IsInterruptSourceEnabled() */
#define OS_APICONTEXT_ISINTERRUPTSOURCEENABLED    ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2))

/*! Calling Context: Os_IsInterruptPending() */
#define OS_APICONTEXT_ISINTERRUPTPENDING          ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2))
/*! Calling Context: CallTrustedFunction() */
#define OS_APICONTEXT_CALLTRUSTEDFUNCTION         ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2 | \
                                                                        OS_CALLCONTEXT_PRESTARTTASK))
/*! Calling Context: CallNonTrustedFunction() */
#define OS_APICONTEXT_CALLNONTRUSTEDFUNCTION      ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2 | \
                                                                        OS_CALLCONTEXT_PRESTARTTASK))

/*! Calling Context: CheckISRMemoryAccess() */
#define OS_APICONTEXT_CHECKISRMEMORYACCESS        ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2 | \
                                                                        OS_CALLCONTEXT_ERRORHOOK | \
                                                                        OS_CALLCONTEXT_PROTECTIONHOOK))
/*! Calling Context: CheckTaskMemoryAccess() */
#define OS_APICONTEXT_CHECKTASKMEMORYACCESS       ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2 | \
                                                                        OS_CALLCONTEXT_ERRORHOOK | \
                                                                        OS_CALLCONTEXT_PROTECTIONHOOK))
/*! Calling Context: CheckObjectAccess() */
#define OS_APICONTEXT_CHECKOBJECTACCESS           ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2 | \
                                                                        OS_CALLCONTEXT_ERRORHOOK | \
                                                                        OS_CALLCONTEXT_PROTECTIONHOOK))
/*! Calling Context: CheckObjectOwnership() */
#define OS_APICONTEXT_CHECKOBJECTOWNERSHIP        ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2 | \
                                                                        OS_CALLCONTEXT_ERRORHOOK | \
                                                                        OS_CALLCONTEXT_PROTECTIONHOOK))
/*! Calling Context: StartScheduleTableRel() */
#define OS_APICONTEXT_STARTSCHEDULETABLEREL       ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2))
/*! Calling Context: StartScheduleTableAbs() */
#define OS_APICONTEXT_STARTSCHEDULETABLEABS       ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2))
/*! Calling Context: StopScheduleTable() */
#define OS_APICONTEXT_STOPSCHEDULETABLE           ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2))
/*! Calling Context: NextScheduleTable() */
#define OS_APICONTEXT_NEXTSCHEDULETABLE           ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2))
/*! Calling Context: StartScheduleTableSynchron() */
#define OS_APICONTEXT_STARTSCHEDULETABLESYNCHRON  ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2))
/*! Calling Context: SyncScheduleTable() */
#define OS_APICONTEXT_SYNCSCHEDULETABLE           ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2))
/*! Calling Context: GetScheduleTableStatus() */
#define OS_APICONTEXT_GETSCHEDULETABLESTATUS      ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2))
/*! Calling Context: SetScheduleTableAsync() */
#define OS_APICONTEXT_SETSCHEDULETABLEASYNC       ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2))
/*! Calling Context: IncrementCounter() */
#define OS_APICONTEXT_INCREMENTCOUNTER            ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2))
/*! Calling Context: GetCounterValue() */
#define OS_APICONTEXT_GETCOUNTERVALUE             ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2))
/*! Calling Context: GetElapsedValue() */
#define OS_APICONTEXT_GETELAPSEDVALUE             ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2))
/*! Calling Context: TerminateApplication() */
#define OS_APICONTEXT_TERMINATEAPPLICATION        ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2 | \
                                                                        OS_CALLCONTEXT_ERRORHOOK))
/*! Calling Context: AllowAccess() */
#define OS_APICONTEXT_ALLOWACCESS                 ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2))
/*! Calling Context: GetApplicationState() */
#define OS_APICONTEXT_GETAPPLICATIONSTATE         ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2 | \
                                                                        OS_CALLCONTEXT_ERRORHOOK | \
                                                                        OS_CALLCONTEXT_PRETASKHOOK | \
                                                                        OS_CALLCONTEXT_POSTTASKHOOK | \
                                                                        OS_CALLCONTEXT_STARTUPHOOK | \
                                                                        OS_CALLCONTEXT_SHUTDOWNHOOK | \
                                                                        OS_CALLCONTEXT_PROTECTIONHOOK))
/*! Calling Context: ControlIdle() */
#define OS_APICONTEXT_CONTROLIDLE                 ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2))
/*! Calling Context: GetCurrentApplicationID() */
#define OS_APICONTEXT_GETCURRENTAPPLICATIONID     ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2 | \
                                                                        OS_CALLCONTEXT_ERRORHOOK | \
                                                                        OS_CALLCONTEXT_PRETASKHOOK | \
                                                                        OS_CALLCONTEXT_POSTTASKHOOK | \
                                                                        OS_CALLCONTEXT_STARTUPHOOK | \
                                                                        OS_CALLCONTEXT_SHUTDOWNHOOK | \
                                                                        OS_CALLCONTEXT_PROTECTIONHOOK))
/*! Calling Context: GetNumberOfActivatedCores() */
#define OS_APICONTEXT_GETNUMBEROFACTIVATEDCORES   ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2))
/*! Calling Context: GetCoreID() */
#define OS_APICONTEXT_GETCOREID                   ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2 | \
                                                                        OS_CALLCONTEXT_ERRORHOOK | \
                                                                        OS_CALLCONTEXT_PRETASKHOOK | \
                                                                        OS_CALLCONTEXT_POSTTASKHOOK | \
                                                                        OS_CALLCONTEXT_STARTUPHOOK | \
                                                                        OS_CALLCONTEXT_SHUTDOWNHOOK | \
                                                                        OS_CALLCONTEXT_ALARMCALLBACK | \
                                                                        OS_CALLCONTEXT_PROTECTIONHOOK) )
/*! Calling Context: StartCore() */
#define OS_APICONTEXT_STARTCORE                   ((Os_CallContextType)(0))
/*! Calling Context: StartNonAutosarCore() */
#define OS_APICONTEXT_STARTNONAUTOSARCORE         ((Os_CallContextType)(0))
/*! Calling Context: GetSpinlock() */
#define OS_APICONTEXT_GETSPINLOCK                 ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2))
/*! Calling Context: ReleaseSpinlock() */
#define OS_APICONTEXT_RELEASESPINLOCK             ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2))
/*! Calling Context: TryToGetSpinlock() */
#define OS_APICONTEXT_TRYTOGETSPINLOCK            ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2))
/*! Calling Context: ShutdownAllCores() */
#define OS_APICONTEXT_SHUTDOWNALLCORES            ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2 | \
                                                                        OS_CALLCONTEXT_ERRORHOOK | \
                                                                        OS_CALLCONTEXT_STARTUPHOOK))
/*! Calling Context: Os_GetDetailedError() */
#define OS_APICONTEXT_GETDETAILEDERROR            ((Os_CallContextType)(OS_CALLCONTEXT_ERRORHOOK))

/*! Calling Context peripheral access API */
#define OS_APICONTEXT_PERIPHERAL                  ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2 | \
                                                                        OS_CALLCONTEXT_PRESTARTTASK | \
                                                                        OS_CALLCONTEXT_STARTUPHOOK | \
                                                                        OS_CALLCONTEXT_ERRORHOOK | \
                                                                        OS_CALLCONTEXT_SHUTDOWNHOOK))
#define OS_APICONTEXT_XSIGSENDSYNC                ((Os_CallContextType)(OS_CALLCONTEXT_TASK | \
                                                                        OS_CALLCONTEXT_ISR2))


/*! Calling Context: Os_GetExceptionContext() */
#define OS_APICONTEXT_GETEXCEPTIONCONTEXT         ((Os_CallContextType)(OS_CALLCONTEXT_PROTECTIONHOOK))

/*! Calling Context: Os_SetExceptionContext() */
#define OS_APICONTEXT_SETEXCEPTIONCONTEXT         ((Os_CallContextType)(OS_CALLCONTEXT_PROTECTIONHOOK))




/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
struct Os_ThreadType_Tag;
struct Os_ThreadConfigType_Tag;

/*! Dynamic management information of the thread class. */
typedef struct Os_ThreadClassType_Tag Os_ThreadClassType;

/*! Dynamic management information of a thread. */
typedef struct Os_ThreadType_Tag Os_ThreadType;

/*! Configuration information of a thread. */
typedef struct Os_ThreadConfigType_Tag Os_ThreadConfigType;


/*! Identifies the current executing context type. */
typedef uint16        Os_CallContextType;

/*! Function pointer type for the PreThreadHook. */
typedef P2FUNC(void, OS_CODE, Os_PreThreadHookCbkType)(void);

/*! Function pointer type for the PreThreadHook. */
typedef P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Os_ThreadContextRefType;


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/






#endif /* OS_THREAD_TYPES_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Thread_Types.h
 **********************************************************************************************************************/
