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
 * \addtogroup Os_Application
 * \{
 *
 * \file
 * \brief       Implementation of application functionality.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */

#define OS_APPLICATION_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Application_Cfg.h"
#include "Os_Application_Types.h"
#include "Os_Application_Lcfg.h"
#include "Os_Application.h"

/* Os kernel module dependencies */
#include "Os_Task.h"
#include "Os_Isr.h"
#include "Os_Hook.h"
#include "Os_Counter.h"
#include "Os_Alarm.h"
#include "Os_ScheduleTable.h"
#include "Os_Error.h"
#include "Os_Ioc.h"
#include "Os_Interrupt.h"
#include "Os_ServiceFunction.h"

/* Os hal dependencies */
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
 *  Os_AppCheckRestartOption()
 **********************************************************************************************************************/
/*! \brief          Returns whether the restart option is valid (Not OS_CHECK_FAILED) or not (OS_CHECK_FAILED).
 *  \details        In case that extended checks are disabled, the default result of \ref Os_ErrExtendedCheck() is
 *                  returned.
 *
 *  \param[in]      RestartOption   The option to check.
 *
 *  \retval         Not OS_CHECK_FAILED   RestartOption is valid.
 *  \retval         OS_CHECK_FAILED       Otherwise.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,
OS_ALWAYS_INLINE, Os_AppCheckRestartOption,
(
  RestartType RestartOption
));


/***********************************************************************************************************************
 *  Os_AppCheckIsUserApp()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given application is an user application.
 *  \details        --no details--
 *
 *  \param[in]      App   Application to check. Parameter must not be NULL.
 *
 *  \retval         Not OS_CHECK_FAILED   Given application is an user application.
 *  \retval         OS_CHECK_FAILED       Otherwise.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,
OS_ALWAYS_INLINE, Os_AppCheckIsUserApp,
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App
));


/***********************************************************************************************************************
 *  Os_AppCheckMayTerminate()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given terminator is allowed to terminate the given application
 *                  (Not OS_CHECK_FAILED) or not (OS_CHECK_FAILED).
 *  \details        Termination is allowed in case of self termination OR if TerminatorApp is trusted.
 *
 *  \param[in]      TerminatorApp     Application which wants to terminate the given target application.
 *                                    Parameter must not be NULL.
 *  \param[in]      TargetApp         Application to terminate. Parameter must not be NULL.
 *
 *  \retval         Not OS_CHECK_FAILED   Termination is allowed.
 *  \retval         OS_CHECK_FAILED       Otherwise.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,
OS_ALWAYS_INLINE, Os_AppCheckMayTerminate,
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) TerminatorApp,
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) TargetApp
));


/***********************************************************************************************************************
 *  Os_AppObjectGetApp()
 **********************************************************************************************************************/
/*! \brief          Returns the owner Get the application based on ObjectType and ObjectID.
 *  \details
 *  Depending on given object type, the function returns the owner application of the given object.
 *  If the ObjectType is invalid or has no application association, NULL_PTR is returned.
 *  If the ObjectType is valid, but the ObjectID is out of range, NULL_PTR is returned.
 *
 *  \param[in]      ObjectType    The type of the object given by the ObjectID.
 *  \param[in]      ObjectID      The ID of the object of interest.
 *
 *  \return         The corresponding application.
 *
 *  \retval         AppRef        Owner application of given object.
 *  \retval         NULL_PTR      If the given ObjectType or ObjectID is invalid.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_AppObjectGetApp,
(
  ObjectTypeType ObjectType,
  Os_ObjectIdType ObjectID
));


/***********************************************************************************************************************
 *  Os_AppObjectAccessIsAllowed()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given application has access to the given object.
 *  \details        --no details--
 *
 *  \param[in]      ApplID        OS-Application identifier.
 *  \param[in]      ObjectType    The type of the object given by the ObjectID.
 *  \param[in]      ObjectID      The ID of the object of interest.
 *
 *  \retval         !0   Access allowed.
 *  \retval         0    No access allowed or ObjectID or ObjectType is invalid.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_AppAccessMaskType, OS_CODE,
OS_ALWAYS_INLINE, Os_AppObjectAccessIsAllowed,
(
  ApplicationType ApplID,
  ObjectTypeType ObjectType,
  Os_ObjectIdType ObjectID
));


/***********************************************************************************************************************
 *  Os_AppKillMembers()
 **********************************************************************************************************************/
/*! \brief          Kill all objects belonging to the given application.
 *  \details        --no details--
 *
 *  \param[in,out]  App    The application to terminate. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_AppKillMembers,
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App
));


/***********************************************************************************************************************
 *  Os_AppKillInterruptedMemberThreads()
 **********************************************************************************************************************/
/*! \brief          Kill all interrupted threads, which belong to the given application.
 *  \details        --no details--
 *
 *  \param[in,out]  App    The application to terminate. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_AppKillInterruptedMemberThreads,
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App
));


/***********************************************************************************************************************
 *  Os_AppKillMemberThread()
 **********************************************************************************************************************/
/*! \brief          Kill given thread, if it belongs to the given application.
 *  \details        --no details--
 *
 *  \param[in,out]  Thread The thread to terminate. Parameter must not be NULL.
 *  \param[in]      App    The application to compare with. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) Os_AppKillMemberThread
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread,
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App
);


/***********************************************************************************************************************
 *  Os_AppKillInternal()
 **********************************************************************************************************************/
/*! \brief          Kills all members of the given application but performs no suicide.
 *  \details        --no details--
 *
 *  \param[in,out]  App             The application to terminate. Parameter must not be NULL.
 *  \param[in]      RestartOption   Termination kind: Terminate (NO_RESTART) or restart (RESTART).
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *
 *  \pre            If a restart is requested, the App has to have a valid restart task pointer.
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) Os_AppKillInternal
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App,
  RestartType RestartOption
);


/***********************************************************************************************************************
 *  Os_AppTerminateApplication()
 **********************************************************************************************************************/
/*! \brief          Second part of TerminateApplication() API.
 *  \details        This function performs some error checks and calls internal application kill behavior.
 *
 *  \param[in,out]  App                       Application to terminate. Parameter must not be NULL.
 *  \param[in]      RestartOption             Tells whether application shall be restarted.
 *  \param[in]      CallerCurrentApplication  The original caller of the API. Parameter must not be NULL.
 *
 *  \retval       OS_STATUS_OK              No error.
 *  \retval       OS_STATUS_STATE_ALREADY_TERMINATED    The application is already terminated.
 *  \retval       OS_STATUS_STATE_ALREADY_RESTARTING    The application is already restarting.
 *  \retval       OS_STATUS_STATE_RESTARTING_NO_MEMBER  The application is restarting AND the caller does not belong
 *                                                      to the application.
 *  \retval       OS_STATUS_NO_RESTARTTASK  Restart requested but no restart task configured.
 *  \retval       OS_STATUS_ACCESSRIGHTS_1  (EXTENDED status:) The caller belongs to a non-trusted OS-Application
 *                                          AND the caller does not belong to given Application.
 *  \retval       OS_STATUS_VALUE_IS_OUT_OF_BOUNDS_2 (EXTENDED status:) Restart option was not valid.
 *  \retval       OS_STATUS_KILL_KERNEL_OBJ (EXTENDED status:) Given application is a kernel application and is not
 *                                          allowed to be terminated.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      FALSE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_LOCAL FUNC(Os_StatusType, OS_CODE) Os_AppTerminateApplication
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App,
  RestartType RestartOption,
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) CallerCurrentApplication
);


/***********************************************************************************************************************
 *  Os_AppHooksInit()
 **********************************************************************************************************************/
/*! \brief          Initialize hooks of the given application.
 *  \details        The function is called in Init-Step3 for the kernel application and in Init-Step4 for all
 *                  applications.
 *
 *  \param[in,out]  App     The application to initialize. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different applications.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) Os_AppHooksInit
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App
);


/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_AppCheckIsUserApp()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,
OS_ALWAYS_INLINE, Os_AppCheckIsUserApp,
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App
))
{
  return Os_ErrExtendedCheck(Os_AppIsKernelApp(App) == 0u);                                                             /* PRQA S 4404 */ /* MD_Os_C90BooleanCompatibility */ /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_AppCheckRestartOption()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,
OS_ALWAYS_INLINE, Os_AppCheckRestartOption,
(
  RestartType RestartOption
))
{
  return Os_ErrExtendedCheck(Os_ErrIsValueLo((uint32)RestartOption, (uint32)OS_RESTARTTYPE_COUNT));
}


/***********************************************************************************************************************
 *  Os_AppCheckMayTerminate()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,
OS_ALWAYS_INLINE, Os_AppCheckMayTerminate,
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) TerminatorApp,
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) TargetApp
))
{
  return Os_ErrExtendedCheck(((Os_AppIsTrusted(TerminatorApp)) || (TerminatorApp == TargetApp)));                       /* PRQA S 4404, 4558 */  /* MD_Os_C90BooleanCompatibility, MD_Os_Rule10.1_4558 */ /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_AppObjectGetApp()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_AppObjectGetApp,
(
  ObjectTypeType ObjectType,
  Os_ObjectIdType ObjectID
))
{
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) ownerApp;

  ownerApp = NULL_PTR;

  switch(ObjectType)
  {
    case OBJECT_TASK:
      {
        TaskType objectId = (TaskType)ObjectID;                                                                         /* PRQA S 4342 */ /* MD_Os_Rule10.5_4342 */

        if(OS_LIKELY(Os_TaskCheckId(objectId) != OS_CHECK_FAILED))
        {
          ownerApp = Os_ThreadGetOwnerApplication(                                                                      /* SBSW_OS_APP_THREADGETOWNERAPPLICATION_003 */
                        Os_TaskGetThread(                                                                               /* SBSW_OS_APP_TASKGETTHREAD_001 */
                            Os_TaskId2Task(objectId)));
        }
      }
      break;
    case OBJECT_ISR:
      {
        ISRType objectId = (ISRType)ObjectID;                                                                           /* PRQA S 4342 */ /* MD_Os_Rule10.5_4342 */

        if(OS_LIKELY(Os_IsrCheckId(objectId) != OS_CHECK_FAILED))
        {
          ownerApp = Os_ThreadGetOwnerApplication(                                                                      /* SBSW_OS_APP_THREADGETOWNERAPPLICATION_004 */
                        Os_IsrGetThread(                                                                                /* SBSW_OS_APP_ISRGETTHREAD_001 */
                            Os_IsrId2Isr(objectId)));
        }
      }
      break;
    case OBJECT_ALARM:
      {
        AlarmType objectId = (AlarmType)ObjectID;                                                                       /* PRQA S 4342 */ /* MD_Os_Rule10.5_4342 */

        if(OS_LIKELY(Os_AlarmCheckId(objectId) != OS_CHECK_FAILED))
        {
          ownerApp = Os_AlarmGetApplication(                                                                            /* SBSW_OS_APP_ALARMGETAPPLICATION_001 */
                        Os_AlarmId2Alarm(objectId));
        }
      }
      break;
    case OBJECT_COUNTER:
      {
        CounterType objectId = (CounterType)ObjectID;                                                                   /* PRQA S 4342 */ /* MD_Os_Rule10.5_4342 */

        if(OS_LIKELY(Os_CounterCheckId(objectId) != OS_CHECK_FAILED))
        {
          ownerApp = Os_CounterGetApplication(                                                                          /* SBSW_OS_APP_COUNTERGETAPPLICATION_001 */
                        Os_CounterId2Counter(objectId));
        }
      }
      break;
    case OBJECT_SCHEDULETABLE:
      {
        ScheduleTableType objectId = (ScheduleTableType)ObjectID;                                                       /* PRQA S 4342 */ /* MD_Os_Rule10.5_4342 */

        if(OS_LIKELY(Os_SchTCheckId(objectId) != OS_CHECK_FAILED))
        {
          ownerApp = Os_SchTGetApplication(                                                                             /* SBSW_OS_APP_SCHTGETAPPLICATION_001 */
                        Os_SchTId2SchT(objectId));
        }
      }
      break;
    case OBJECT_SPINLOCK:
      /* Spinlocks are not owned by applications. */
    case OBJECT_RESOURCE:
      /* Resources are not owned by applications. */
    default:                                                                                                            /* PRQA S 2016 */ /* MD_MSR_EmptyClause */
      break;
  }

  return ownerApp;
}                                                                                                                       /* PRQA S 6030, 6050 */ /* MD_Os_STCYC, MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_AppObjectAccessIsAllowed()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_AppAccessMaskType, OS_CODE,
OS_ALWAYS_INLINE, Os_AppObjectAccessIsAllowed,
(
  ApplicationType ApplID,
  ObjectTypeType ObjectType,
  Os_ObjectIdType ObjectID
))
{
  Os_AppAccessMaskType accessingApplications;

  accessingApplications = 0;

  switch(ObjectType)
  {
    case OBJECT_TASK:
      {
        TaskType objectId = (TaskType)ObjectID;                                                                         /* PRQA S 4342 */ /* MD_Os_Rule10.5_4342 */

        if(OS_UNLIKELY(Os_TaskCheckId(objectId) != OS_CHECK_FAILED))
        {
          accessingApplications = Os_TaskGetAccessingApplications(                                                      /* SBSW_OS_APP_TASKGETACCESSINGAPPLICATIONS_001 */
                                      Os_TaskId2Task(objectId));
        }
      }
      break;
    case OBJECT_ALARM:
      {
        AlarmType objectId = (AlarmType)ObjectID;                                                                       /* PRQA S 4342 */ /* MD_Os_Rule10.5_4342 */

        if(OS_UNLIKELY(Os_AlarmCheckId(objectId) != OS_CHECK_FAILED))
        {
          accessingApplications = Os_AlarmGetAccessingApplications(                                                     /* SBSW_OS_APP_ALARMGETACCESSINGAPPLICATIONS_001 */
                                      Os_AlarmId2Alarm(objectId));
        }
      }
      break;
    case OBJECT_COUNTER:
      {
        CounterType objectId = (CounterType)ObjectID;                                                                   /* PRQA S 4342 */ /* MD_Os_Rule10.5_4342 */

        if(OS_UNLIKELY(Os_CounterCheckId(objectId) != OS_CHECK_FAILED))
        {
          accessingApplications = Os_CounterGetAccessingApplications(                                                   /* SBSW_OS_APP_COUNTERGETACCESSINGAPPLICATIONS_001 */
                                      Os_CounterId2Counter(objectId));
        }
      }
      break;
    case OBJECT_SCHEDULETABLE:
      {
        ScheduleTableType objectId = (ScheduleTableType)ObjectID;                                                       /* PRQA S 4342 */ /* MD_Os_Rule10.5_4342 */

        if(OS_UNLIKELY(Os_SchTCheckId(objectId) != OS_CHECK_FAILED))
        {
          accessingApplications = Os_SchTGetAccessingApplications(                                                      /* SBSW_OS_APP_SCHTGETACCESSINGAPPLICATIONS_001 */
                                      Os_SchTId2SchT(objectId));
        }
      }
      break;
    case OBJECT_RESOURCE:
      {
        ResourceType objectId = (ResourceType)ObjectID;                                                                 /* PRQA S 4342 */ /* MD_Os_Rule10.5_4342 */

        if(OS_UNLIKELY(Os_ResourceCheckId(objectId) != OS_CHECK_FAILED))
        {
          accessingApplications = Os_ResourceGetAccessingApplications(                                                  /* SBSW_OS_APP_RESOURCEGETACCESSINGAPPLICATIONS_001 */
                                      Os_ResourceId2Resource(objectId));
        }
      }
      break;
    case OBJECT_SPINLOCK:
      {
        SpinlockIdType objectId = (SpinlockIdType)ObjectID;                                                             /* PRQA S 4342 */ /* MD_Os_Rule10.5_4342 */

        if(OS_UNLIKELY(Os_SpinlockCheckId(objectId) != OS_CHECK_FAILED))
        {
          accessingApplications = Os_SpinlockGetAccessingApplications(                                                  /* SBSW_OS_APP_SPINLOCKGETACCESSINGAPPLICATIONS_001 */
                                      Os_SpinlockId2Spinlock(objectId));
        }
      }
      break;
    case OBJECT_ISR:
      /* ISRs do not have accessing applications. */
    default:                                                                                                            /* PRQA S 2016 */ /* MD_MSR_EmptyClause */
      break;
  }

  return (OS_APPID2MASK(ApplID) & accessingApplications);
}                                                                                                                       /* PRQA S 6030, 6050 */ /* MD_Os_STCYC, MD_Os_STCAL */





/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  Os_AppInit()
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
FUNC(void, OS_CODE) Os_AppInit
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App,
  AppModeType AppMode
)
{
  Os_ObjIdxType index;

  /* #10 Initialize tasks. */
  for(index = 0; index < App->TaskCount; index++)
  {
    Os_TaskInit(App->TaskRefs[index], AppMode);                                                                         /* SBSW_OS_APP_TASKINIT_001 */
  }

  /* #20 Initialize ISRs. */
  for(index = 0; index < App->IsrCat2Count; index++)
  {
    Os_IsrInit(App->IsrCat2Refs[index]);                                                                                /* SBSW_OS_APP_ISRINIT_001 */
  }

  /* #30 Initialize Counters. */
  for(index = 0; index < App->CounterCount; index++)
  {
    Os_CounterInit(App->CounterRefs[index]);                                                                            /* SBSW_OS_APP_COUNTERINIT_001 */
  }

  /* #40 Initialize Alarms. */
  for(index = 0; index < App->AlarmCount; index++)
  {
    Os_AlarmInit(App->AlarmRefs[index], AppMode);                                                                       /* SBSW_OS_APP_ALARMINIT_001 */
  }

  /* #50 Initialize Schedule Tables. */
  for(index = 0; index < App->SchTCount; index++)
  {
    Os_SchTInit(App->SchTRefs[index], AppMode);                                                                         /* SBSW_OS_APP_Os_SCHTINIT_001 */
  }

  /* #60 Initialize service functions. */
  Os_AppServicesInit(App);                                                                                              /* SBSW_OS_FC_PRECONDITION */

  /* #70 Initialize application hooks. */
  Os_AppHooksInit(App);                                                                                                 /* SBSW_OS_FC_PRECONDITION */

  /* #80 Initialize application state. */
  App->Dyn->State = APPLICATION_ACCESSIBLE;                                                                             /* SBSW_OS_APP_DYN_001 */
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_AppServicesInit()
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_AppServicesInit
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App
)
{
  Os_ObjIdxType index;

  for(index = 0; index < App->ServiceFunctionCount; index++)
  {
    Os_ServiceInit(App->ServiceFunctions[index]);                                                                       /* SBSW_OS_APP_SERVICEINIT_001 */
  }
}


/***********************************************************************************************************************
 *  Os_AppHooksInit()
 **********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) Os_AppHooksInit
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App
)
{
  Os_ObjIdxType index;

  for(index = 0; index < App->HookCount; index++)
  {
    Os_HookInit(App->HookRefs[index]);                                                                                  /* SBSW_OS_APP_Os_SCHTINIT_001 */
  }
}


/***********************************************************************************************************************
 *  Os_AppKillMembers()
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_AppKillMembers,
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App
))
{
  Os_ObjIdxType it;

  /* #10 Disable application's ISRs. */
  for(it = 0; it < App->IsrCat2Count; it++)
  {
    Os_IsrDisable(App->IsrCat2Refs[it]);                                                                                /* SBSW_OS_APP_ISRDISABLE_001 */
  }

  for(it = 0; it < App->IsrCat1Count; it++)
  {
    Os_IsrCat1Disable(App->IsrCat1Refs[it]);                                                                            /* SBSW_OS_APP_ISR1DISABLE_001 */
  }

  /* #20 Kill application's alarms. */
  for(it = 0; it < App->AlarmCount; it++)
  {
    Os_AlarmKill(App->AlarmRefs[it]);                                                                                   /* SBSW_OS_APP_ALARMKILL_001 */
  }

  /* #30 Kill application's schedule tables. */
  for(it = 0; it < App->SchTCount; it++)
  {
    Os_SchTKill(App->SchTRefs[it]);                                                                                     /* SBSW_OS_APP_Os_SCHTKILL_001 */
  }

  /* #40 Kill application's tasks (and all it outstanding activations). */
  for(it = 0; it < App->TaskCount; it++)
  {
    Os_TaskKillAll(App->TaskRefs[it]);                                                                                  /* SBSW_OS_APP_TASKKILLALL_001 */
  }

  /* #50 Kill interrupted threads, if they belong to the given application. */
  Os_AppKillInterruptedMemberThreads(App);                                                                              /* SBSW_OS_FC_PRECONDITION */

  /* #60 Kill current thread, if it belongs to the given application. */
  Os_AppKillMemberThread(Os_CoreGetThread(), App);                                                                      /* SBSW_OS_FC_PRECONDITION */

  /* #70 Kill application's service functions. */
  /* Currently service functions cannot be killed. */
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_AppKillInterruptedMemberThreads()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_AppKillInterruptedMemberThreads,
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App
))
{
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) core;
  Os_CoreThreadIdx iterator;
  Os_CoreThreadIdx iteratorEnd;

  core = Os_AppGetCore(App);                                                                                            /* SBSW_OS_FC_PRECONDITION */

  /* #10 For each interrupted thread on the interrupted threads stack: */
  iterator = Os_CoreInterruptedThreadsGetTopIdx(core);                                                                  /* SBSW_OS_FC_RETURNEDPOINTER */
  iteratorEnd = Os_CoreInterruptedThreadsGetBottomIdx();

  while(iterator != iteratorEnd)
  {
    P2CONST(Os_ThreadConfigType, TYPEDEF, OS_CONST) interruptedThread;

    interruptedThread = Os_CoreInterruptedThreadsGet(core, iterator);                                                   /* SBSW_OS_APP_COREINTERRUPTEDTHREADSGET_001 */

    /* #20 Kill the interrupted thread if it belongs to the given application. */
    Os_AppKillMemberThread(interruptedThread, App);                                                                     /* SBSW_OS_APP_APPKILLMEMBERTHREAD_001 */

    iterator = Os_CoreInterruptedThreadsMoveDown(iterator);
  }
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_AppKillMemberThread()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_LOCAL FUNC(void, OS_CODE) Os_AppKillMemberThread
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread,
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App
)
{
  /* #10 If the given thread is part of the given application: */
  if(Os_ThreadGetOwnerApplication(Thread) == App)                                                                       /* SBSW_OS_FC_PRECONDITION */
  {
    /* #20 Call the thread type specific kill function. */
    switch(Os_ThreadGetInitialType(Thread))                                                                             /* SBSW_OS_FC_PRECONDITION */
    {
      case OS_CALLCONTEXT_TASK:
        /* Tasks are killed separately by caller. */
        break;

      case OS_CALLCONTEXT_ISR2:
        Os_IsrKill(                                                                                                     /* SBSW_OS_APP_ISRKILL_001 */
            Os_IsrThread2Isr(Thread));                                                                                  /* SBSW_OS_FC_PRECONDITION */
        break;

      case OS_CALLCONTEXT_ERRORHOOK:
      case OS_CALLCONTEXT_STARTUPHOOK:
      case OS_CALLCONTEXT_IOCCALLBACK:
        Os_HookKill(Os_HookThread2Hook(Thread));                                                                        /* SBSW_OS_APP_HOOKKILL_001 */ /* SBSW_OS_FC_PRECONDITION */
        break;

      case OS_CALLCONTEXT_SHUTDOWNHOOK:                                                                                 /* COV_OS_INVSTATE */
      case OS_CALLCONTEXT_PRESTARTTASK:                                                                                 /* COV_OS_INVSTATE */
        /* Termination not reachable for this type of task. */
      case OS_CALLCONTEXT_PRETASKHOOK:                                                                                  /* COV_OS_INVSTATE */
      case OS_CALLCONTEXT_POSTTASKHOOK:                                                                                 /* COV_OS_INVSTATE */
        /* Not reachable, because initialcontext cannot contain PRETASKHOOK/POSTTASKHOOK. */
      case OS_CALLCONTEXT_ALARMCALLBACK:                                                                                /* COV_OS_INVSTATE */
        /* Not reachable, because initialcontext cannot contain ALARMCALLBACK. */
      case OS_CALLCONTEXT_PROTECTIONHOOK:                                                                               /* COV_OS_INVSTATE */
      case OS_CALLCONTEXT_TPISR:                                                                                        /* COV_OS_INVSTATE */
        /* Executed as part of the kernel application. Termination is not allowed for the kernel application. */

      default:                                                                                                          /* COV_OS_INVSTATE */
        Os_ErrKernelPanic();
        break;
    }
  }
}                                                                                                                       /* PRQA S 6030, 6050, 6080 */ /* MD_Os_STCYC, MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_AppKillInternal()
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
 */
OS_LOCAL_INLINE FUNC(void, OS_CODE) Os_AppKillInternal
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App,
  RestartType RestartOption
)
{
  /* #10 Check that the given application is a user application. */
  Os_Assert((Os_StdReturnType)(Os_AppIsKernelApp(App) == 0u));                                                          /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */ /* SBSW_OS_FC_PRECONDITION */

  /* #30 Terminate all members. */
  Os_AppKillMembers(App);                                                                                               /* SBSW_OS_FC_PRECONDITION */

  /* #40 If the application shall be restarted: */
  if(RestartOption == RESTART)
  {
    Os_StatusType status;
    Os_Assert((Os_StdReturnType)(App->RestartTask != NULL_PTR));                                                        /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */

    /* #50 Set the application state to restarting. */
    App->Dyn->State = APPLICATION_RESTARTING;                                                                           /* SBSW_OS_APP_DYN_001 */

    /* #60 Activate its restart task. */
    status = Os_TaskActivateRestartTask(App->RestartTask);                                                              /* SBSW_OS_FC_PRECONDITION */

    /* #70 If activation failed, Kernel Panic. */
    if(OS_UNLIKELY(status != OS_STATUS_OK))                                                                             /* COV_OS_INVSTATE */
    {
      Os_ErrKernelPanic();
    }
  }
  else
  {
    /* #80 Set the application state to terminated. */
    App->Dyn->State = APPLICATION_TERMINATED;                                                                           /* SBSW_OS_APP_DYN_001 */
  }
}


/***********************************************************************************************************************
 *  Os_AppKill()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_AppKill
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App,
  RestartType RestartOption
)
{
  /* #10 If killing is not enabled: KernelPanic */
  if(Os_ErrIsKillingEnabled() == 0u)                                                                                    /* COV_OS_INVSTATE */
  {
    Os_ErrKernelPanic();
  }

  /* #15 Call internal kill application behavior. */
  Os_AppKillInternal(App, RestartOption);                                                                               /* SBSW_OS_FC_PRECONDITION */

  /* #20 If the current thread is part of the terminated application: */
  if(Os_ThreadGetOwnerApplication(Os_CoreGetThread()) == App)                                                           /* SBSW_OS_APP_THREADGETOWNERAPPLICATION_001 */
  {
    /* #30 Call self killing behavior for the current thread. */
    Os_ThreadSuicide();
  }
}


/***********************************************************************************************************************
 *  Os_AppKillNoSuicide()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, OS_CODE) Os_AppKillNoSuicide
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App
)
{
  /* #10 Call internal kill application behavior. */
  Os_AppKillInternal(App, NO_RESTART);                                                                                  /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_Api_GetApplicationID()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(ApplicationType, OS_CODE) Os_Api_GetApplicationID
(
  void
)
{
  ApplicationType configuredApp;

  /* #10 Return the configured application ID of the current thread. */
  configuredApp = Os_AppGetId(                                                                                          /* SBSW_OS_APP_APPGETID_001 */
                      Os_ThreadGetOwnerApplication(                                                                     /* SBSW_OS_APP_THREADGETOWNERAPPLICATION_001 */
                          Os_CoreGetThread()));

  return configuredApp;
}


/***********************************************************************************************************************
 *  Os_Api_GetCurrentApplicationID()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(ApplicationType, OS_CODE) Os_Api_GetCurrentApplicationID
(
  void
)
{
  ApplicationType currentApp;

  /* #10 Return the current application ID of the current thread. */
  currentApp = Os_AppGetId(                                                                                             /* SBSW_OS_APP_APPGETID_002 */
                  Os_ThreadGetCurrentApplication(Os_CoreGetThread()));                                                  /* SBSW_OS_APP_THREADGETCURRENTAPPLICATION_001 */

  return currentApp;
}


/***********************************************************************************************************************
 *  Os_Api_GetApplicationState()
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
FUNC(Os_StatusType, OS_CODE) Os_Api_GetApplicationState
(
  ApplicationType Application,
  ApplicationStateRefType Value
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

  currentThread = Os_CoreGetThread();

  /* #10 Perform error checks. */
  if(OS_UNLIKELY(Os_AppCheckId(Application) == OS_CHECK_FAILED ))
  {
    status = OS_STATUS_ID_1;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckCallContext(                                                                        /* SBSW_OS_APP_THREADCHECKCALLCONTEXT_001 */
                                  currentThread, OS_APICONTEXT_GETAPPLICATIONSTATE) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_CALLEVEL;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckAreInterruptsEnabled(                                                               /* SBSW_OS_APP_THREADCHECKAREINTERRUPTSENABLED_001 */
                                  currentThread) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_DISABLEDINT;
  }
  else
  {
    P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) targetApp;

    targetApp = Os_AppId2App(Application);

    /* #30 If the given application is mapped to the local core: */
    if(OS_LIKELY(Os_AppIsCoreLocal(targetApp) != 0u))                                                                   /* SBSW_OS_APP_APPISCORELOCAL_001 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
    {
      /* #40 Read the application state. */
      *Value = Os_AppGetState(targetApp);                                                                               /* SBSW_OS_PWA_PRECONDITION */ /* SBSW_OS_APP_APPGETSTATE_001 */

      status = OS_STATUS_OK;
    }
    /* #50 Otherwise: */
    else
    {
      /* #60 Signal to target core. */
      status = Os_XSigSend_GetApplicationState(                                                                         /* SBSW_OS_APP_XSIGSEND_001 */
          Os_AppGetCore(targetApp), currentThread, Application, Value);                                                 /* SBSW_OS_APP_APPGETCORE_001 */
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_Api_CheckObjectAccess()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(ObjectAccessType, OS_CODE) Os_Api_CheckObjectAccess
(
  ApplicationType ApplID,
  ObjectTypeType ObjectType,
  Os_ObjectIdType ObjectID
)
{
  ObjectAccessType result;

  /* #10 Perform error checks. */
  if(Os_ErrIsServiceProtectionEnabled() == 0u)
  {
    result = ACCESS;
  }
  else if(OS_UNLIKELY(Os_AppCheckId(ApplID) == OS_CHECK_FAILED))
  {
    result = NO_ACCESS;
  }
  else
  {
    /* #20 Return whether the given application has access to given object. */
    if(Os_AppObjectAccessIsAllowed(ApplID, ObjectType, ObjectID) != 0u)
    {
      result = ACCESS;
    }
    else
    {
      result = NO_ACCESS;
    }
  }

  return result;
}


/***********************************************************************************************************************
 *  Os_Api_CheckObjectOwnership()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(ApplicationType, OS_CODE) Os_Api_CheckObjectOwnership
(
  ObjectTypeType ObjectType,
  Os_ObjectIdType ObjectID
)
{
  ApplicationType ownerAppId;
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) ownerApp;

  /* #10 Get the target application reference. */
  ownerApp = Os_AppObjectGetApp(ObjectType, ObjectID);

  /* #20 If the reference is a NULL_PTR the result is INVALID_OSAPPLICATION. */
  if(OS_UNLIKELY(ownerApp == NULL_PTR))
  {
    ownerAppId = INVALID_OSAPPLICATION;
  }
  /* #30 Otherwise the result is the ID of the application referenced. */
  else
  {
    ownerAppId = Os_AppGetId(ownerApp);                                                                                 /* SBSW_OS_APPGETID_002 */
  }

  return ownerAppId;
}


/***********************************************************************************************************************
 *  Os_Api_AllowAccess()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_Api_AllowAccess
(
  void
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) currentApp;

  currentThread = Os_CoreGetThread();
  currentApp = Os_ThreadGetCurrentApplication(currentThread);                                                           /* SBSW_OS_APP_THREADGETCURRENTAPPLICATION_001 */

  /* #10 Perform error checks. */
  if(Os_ErrIsKillingEnabled() == 0u)                                                                                    /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    status = Os_ErrSetOkInStdStatus(OS_STATUS_STATE_NO_RESTART);                                                        /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }
  else if(OS_UNLIKELY(Os_ThreadCheckCallContext(                                                                        /* SBSW_OS_APP_THREADCHECKCALLCONTEXT_001 */
                    currentThread, OS_APICONTEXT_ALLOWACCESS) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_CALLEVEL;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckAreInterruptsEnabled(                                                               /* SBSW_OS_APP_THREADCHECKAREINTERRUPTSENABLED_001 */
                         currentThread) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_DISABLEDINT;
  }
  else if(OS_UNLIKELY(Os_AppGetState(                                                                                   /* SBSW_OS_APP_APPGETSTATE_002 */
                        currentApp) != APPLICATION_RESTARTING))
  {
    status = OS_STATUS_STATE_NO_RESTART;
  }
  else
  {
    /* #20 Set the application state to APPLICATION_ACCESSIBLE. */
    currentApp->Dyn->State = APPLICATION_ACCESSIBLE;                                                                    /* SBSW_OS_APP_DYN_002 */

    status = OS_STATUS_OK;
  }

  return status;
}


/***********************************************************************************************************************
 *  Os_Api_TerminateApplication()
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
FUNC(Os_StatusType, OS_CODE) Os_Api_TerminateApplication
(
  ApplicationType Application,
  RestartType RestartOption
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

  currentThread = Os_CoreGetThread();

  /* #10 Perform error checks concerning the caller context. */
  if(Os_ErrIsKillingEnabled() == 0u)
  {
    status = OS_STATUS_KILLING_IS_DISABLED;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckCallContext(                                                                        /* SBSW_OS_APP_THREADCHECKCALLCONTEXT_001 */
                    currentThread, OS_APICONTEXT_TERMINATEAPPLICATION) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_CALLEVEL;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckAreInterruptsEnabled(                                                               /* SBSW_OS_APP_THREADCHECKAREINTERRUPTSENABLED_001 */
                        currentThread) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_DISABLEDINT;
  }
  else if(OS_UNLIKELY(Os_AppCheckId(Application) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_ID_1;
  }
  /* #20 Otherwise: */
  else
  {
    P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) targetApp;
    P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) currentApp;

    targetApp = Os_AppId2App(Application);
    currentApp = Os_ThreadGetCurrentApplication(currentThread);                                                         /* SBSW_OS_APP_THREADGETCURRENTAPPLICATION_001 */

    /* #30 If the given application is mapped to the local core: */
    if(OS_LIKELY(Os_AppIsCoreLocal(targetApp) != 0u))                                                                   /* SBSW_OS_APP_APPISCORELOCAL_001 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
    {
      /* #40 Call second part of TerminateApplication() API. */
      status = Os_AppTerminateApplication(                                                                              /* SBSW_OS_APP_APPTERMINATEAPPLICATION_001 */
                  targetApp,
                  RestartOption,
                  currentApp);
    }
    /* #50 Otherwise: */
    else
    {
      ApplicationType currentCallerApplicationID;

      currentCallerApplicationID = Os_AppGetId(currentApp);                                                             /* SBSW_OS_APPGETID_001 */

      /* #60 Signal to target core. */
      status = Os_XSigSend_TerminateApplication(                                                                        /* SBSW_OS_APP_XSIGSEND_001 */
                  Os_AppGetCore(targetApp),                                                                             /* SBSW_OS_APP_APPGETCORE_001 */
                  currentThread,
                  Application,
                  RestartOption,
                  currentCallerApplicationID);
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050, 6080 */ /* MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_AppTerminateApplication()
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
 */
OS_LOCAL FUNC(Os_StatusType, OS_CODE) Os_AppTerminateApplication
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App,
  RestartType RestartOption,
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) CallerCurrentApplication
)
{
  Os_StatusType status;

  /* #10 If killing is not enabled: KernelPanic */
  if(Os_ErrIsKillingEnabled() == 0u)                                                                                    /* COV_OS_INVSTATE */
  {
    Os_ErrKernelPanic();
  }

  /* #15 Perform checks. */
  if(OS_UNLIKELY(Os_AppCheckIsUserApp(App) == OS_CHECK_FAILED))                                                         /* SBSW_OS_FC_PRECONDITION */
  {
    status = OS_STATUS_KILL_KERNEL_OBJ;
  }
  else if(OS_UNLIKELY(Os_AppCheckRestartOption(RestartOption) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_VALUE_IS_OUT_OF_BOUNDS_2;
  }
  else if(OS_UNLIKELY((RestartOption == RESTART) && (App->RestartTask == NULL_PTR)))
  {
    status = OS_STATUS_NO_RESTARTTASK;
  }
  else if(OS_UNLIKELY(                                                                                                  /* SBSW_OS_FC_PRECONDITION */
      Os_AppCheckMayTerminate(CallerCurrentApplication, App) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_ACCESSRIGHTS_1;
  }
  else
  {
    ApplicationStateType appState;
    Os_IntStateType interruptState;

    /* #20 Suspend interrupts. */
    Os_IntSuspend(&interruptState);                                                                                     /* SBSW_OS_FC_POINTER2LOCAL */

    appState = Os_AppGetState(App);                                                                                     /* SBSW_OS_FC_PRECONDITION */

    if(OS_UNLIKELY((appState == APPLICATION_RESTARTING) && (CallerCurrentApplication != App)))                          /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
    {
      status = OS_STATUS_STATE_RESTARTING_NO_MEMBER;
    }
    else if(OS_UNLIKELY((appState == APPLICATION_RESTARTING) && (RestartOption == RESTART)))
    {
      status = OS_STATUS_STATE_ALREADY_RESTARTING;
    }
    else if(OS_UNLIKELY(appState == APPLICATION_TERMINATED))                                                            /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
    {
      status = OS_STATUS_STATE_ALREADY_TERMINATED;
    }
    else
    {
      P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

      /* #30 Call internal behavior for application termination. */
      Os_AppKill(App, RestartOption);                                                                                   /* SBSW_OS_FC_PRECONDITION */

      currentThread = Os_CoreGetThread();

      /* #40 If this function is called from a task: */
      if(Os_ThreadIsTask(currentThread) != 0u)                                                                          /* SBSW_OS_APP_THREADISTASK_001 */
      {
        P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) scheduler;

        scheduler = Os_CoreGetScheduler(Os_ThreadGetCore(currentThread));                                               /* SBSW_OS_APP_COREGETSCHEDULER_001 */ /* SBSW_OS_APP_THREADGETCORE_001 */

        /* #50 Switch to higher priority tasks if required. */
        if((Os_SchedulerTaskSwitchIsNeeded(scheduler) != 0u))                                                           /* SBSW_OS_APP_SCHEDULERTASKSWITCHISNEEDED_001 */
        {
          Os_TaskSwitch(scheduler, currentThread);                                                                      /* SBSW_OS_APP_TASKSWITCH_001 */
        }
      }

      status = OS_STATUS_OK;
    }

    /* #60 Resume interrupts. */
    Os_IntResume(&interruptState);                                                                                      /* SBSW_OS_FC_POINTER2LOCAL */
  }

  return status;
}                                                                                                                       /* PRQA S 6030, 6050, 6080 */ /* MD_Os_STCYC, MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_AppTerminateApplicationLocal()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_AppTerminateApplicationLocal                                                            /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App,
  RestartType RestartOption,
  ApplicationType CurrentCallerApplicationID
)
{
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) callerCurrentApplication;

  /* #10 If killing is not enabled: KernelPanic */
  if(Os_ErrIsKillingEnabled() == 0u)                                                                                    /* COV_OS_INVSTATE */
  {
    Os_ErrKernelPanic();
  }

  /* #20 Do the termination */
  callerCurrentApplication = Os_AppId2App(CurrentCallerApplicationID);

  return Os_AppTerminateApplication(App, RestartOption, callerCurrentApplication);                                      /* SBSW_OS_APP_APPTERMINATEAPPLICATION_002 */
}


/***********************************************************************************************************************
 *  Os_AppGetApplicationStateLocal()
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_AppGetApplicationStateLocal                                                             /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App,
  ApplicationStateRefType Value
)
{
  (*Value) = Os_AppGetState(App);                                                                                       /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_PWA_PRECONDITION */
  return OS_STATUS_OK;
}


#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */



/* module specific MISRA deviations:
 */

/* SBSW_JUSTIFICATION_BEGIN

\ID SBSW_OS_APP_DYN_001
 \DESCRIPTION    Write access to the dynamic data of an application. The application pointer is provided as a
                 parameter, validity is assured by precondition. The compliance to the precondition is checked
                 by review.
 \COUNTERMEASURE \M [CM_OS_APPDYN_M]

\ID SBSW_OS_APP_DYN_002
 \DESCRIPTION    Write access to the dynamic data of an application. The application pointer is provided as a return
                 value of Os_ThreadGetCurrentApplication.
                 CM_OS_THREADGETCURRENTAPPLICATION_N
 \COUNTERMEASURE \M [CM_OS_APPDYN_M]

\ID SBSW_OS_APP_APPTERMINATEAPPLICATION_001
 \DESCRIPTION    Os_AppTerminateApplication is called with the return values of Os_AppId2App() and
                 Os_ThreadGetCurrentApplication().
 \COUNTERMEASURE \M [CM_OS_APPID2APP_M]. No check required for Os_ThreadGetCurrentApplication
                 (see CM_OS_THREADGETCURRENTAPPLICATION_N)


\ID SBSW_OS_APP_APPTERMINATEAPPLICATION_002
 \DESCRIPTION    Os_AppTerminateApplication is called with the return values of Os_AppId2App() and a parameter argument
                 of the caller function. The correctness of the argument is ensured by a precondition. The precondition
                 is checked by review.
 \COUNTERMEASURE \M [CM_OS_APPID2APP_M]

\ID SBSW_OS_APPGETID_001
 \DESCRIPTION    Os_AppGetId is called with the return value of Os_ThreadGetCurrentApplication().
 \COUNTERMEASURE \N [CM_OS_THREADGETCURRENTAPPLICATION_N]

\ID SBSW_OS_APPGETID_002
 \DESCRIPTION    Os_AppGetId is called with the return value of Os_AppObjectGetApp(). That function always returns a
                 valid pointer or NULL_PTR. Check against NULL_PTR exists.
 \COUNTERMEASURE \R [CM_OS_APPOBJECTGETAPP_R]

\ID SBSW_OS_APP_XSIGSEND_001
 \DESCRIPTION    A cross core send function is called, with the return values of Os_AppGetCore() and Os_CoreGetThread().
                 Correctness of Os_CoreGetThread is ensured by preconditions (see CM_OS_COREGETTHREAD_N).
 \COUNTERMEASURE \M [CM_OS_APPGETCORE_M]

\ID SBSW_OS_APP_SCHEDULERTASKSWITCHISNEEDED_001
 \DESCRIPTION    Os_SchedulerTaskSwitchIsNeeded is called with the return value of Os_CoreGetScheduler.
 \COUNTERMEASURE \M [CM_OS_COREGETSCHEDULER_M]

\ID SBSW_OS_APP_ALARMGETAPPLICATION_001
 \DESCRIPTION    Os_AlarmGetApplication is called with the return value of Os_AlarmId2Alarm.
 \COUNTERMEASURE \M [CM_OS_ALARMID2ALARM_M]

\ID SBSW_OS_APP_COUNTERGETAPPLICATION_001
 \DESCRIPTION    Os_CounterGetApplication is called with the return value of Os_CounterId2Counter.
 \COUNTERMEASURE \M [CM_OS_COUNTERID2COUNTER_M]

\ID SBSW_OS_APP_SCHTGETAPPLICATION_001
 \DESCRIPTION    Os_SchTGetApplication is called with the return value of Os_SchTId2SchT.
 \COUNTERMEASURE \M [CM_OS_SCHTID2SCHT_M]

\ID SBSW_OS_APP_TASKGETTHREAD_001
 \DESCRIPTION    The passed pointer is returned by Os_TaskId2Task.
 \COUNTERMEASURE \M [CM_OS_TASKID2TASK_M]

\ID SBSW_OS_APP_ISRGETTHREAD_001
 \DESCRIPTION    Os_IsrGetThread is called with the return value of Os_IsrId2Isr.
 \COUNTERMEASURE \M [CM_OS_ISRID2ISR_M]

\ID SBSW_OS_APP_THREADGETCORE_001
 \DESCRIPTION    Os_ThreadGetCore is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_APP_COREINTERRUPTEDTHREADSGET_001
 \DESCRIPTION    The passed pointer is returned by Os_AppGetCore.
 \COUNTERMEASURE \M [CM_OS_APPGETCORE_M]

\ID SBSW_OS_APP_COREGETSCHEDULER_001
 \DESCRIPTION    Os_CoreGetScheduler is called with the return value of Os_ThreadGetCore.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_APP_TASKSWITCH_001
 \DESCRIPTION    Os_TaskSwitch is called with the return values of Os_CoreGetScheduler and Os_CoreGetThread.
                 The return value of Os_CoreGetThread is always valid (see CM_OS_COREGETTHREAD_N).
 \COUNTERMEASURE \M [CM_OS_COREGETSCHEDULER_M]

\ID SBSW_OS_APP_TASKGETACCESSINGAPPLICATIONS_001
 \DESCRIPTION    Os_TaskGetAccessingApplications is called with the return value of Os_TaskId2Task.
 \COUNTERMEASURE \M [CM_OS_TASKID2TASK_M]

\ID SBSW_OS_APP_ALARMGETACCESSINGAPPLICATIONS_001
 \DESCRIPTION    Os_AlarmGetAccessingApplications is called with the return value of Os_AlarmId2Alarm.
 \COUNTERMEASURE \M [CM_OS_ALARMID2ALARM_M]

\ID SBSW_OS_APP_COUNTERGETACCESSINGAPPLICATIONS_001
 \DESCRIPTION    Os_CounterGetAccessingApplications is called with the return value of Os_CounterId2Counter.
 \COUNTERMEASURE \M [CM_OS_COUNTERID2COUNTER_M]

\ID SBSW_OS_APP_SCHTGETACCESSINGAPPLICATIONS_001
 \DESCRIPTION    Os_SchTGetAccessingApplications is called with the return value of Os_SchTId2SchT.
 \COUNTERMEASURE \M [CM_OS_SCHTID2SCHT_M]

\ID SBSW_OS_APP_RESOURCEGETACCESSINGAPPLICATIONS_001
 \DESCRIPTION    Os_ResourceGetAccessingApplications is called with the return value of Os_ResourceId2Resource.
 \COUNTERMEASURE \M [CM_OS_RESOURCEID2RESOURCE_M]

\ID SBSW_OS_APP_SPINLOCKGETACCESSINGAPPLICATIONS_001
 \DESCRIPTION    Os_SpinlockGetAccessingApplications is called with the return value of Os_SpinlockId2Spinlock.
 \COUNTERMEASURE \M [CM_OS_SPINLOCKID2SPINLOCK_M]

\ID SBSW_OS_APP_TASKINIT_001
 \DESCRIPTION    Os_TaskInit is called with an entry of the array TaskRefs from an application.
 \COUNTERMEASURE \M [CM_OS_APP_TASKREF_M]

\ID SBSW_OS_APP_ISRINIT_001
 \DESCRIPTION    Os_IsrInit is called with an entry of the array IsrCat2Refs from an application.
 \COUNTERMEASURE \M [CM_OS_APP_ISRCAT2REF_M]

\ID SBSW_OS_APP_COUNTERINIT_001
 \DESCRIPTION    Os_CounterInit is called with an entry of the array CounterRefs from an application.
 \COUNTERMEASURE \M [CM_OS_APP_COUNTERREF_M]

\ID SBSW_OS_APP_ALARMINIT_001
 \DESCRIPTION    Os_AlarmInit is called with an entry of the array AlarmRefs from an application.
 \COUNTERMEASURE \M [CM_OS_APP_ALARMREF_M]

\ID SBSW_OS_APP_Os_SCHTINIT_001
 \DESCRIPTION    Os_SchTInit is called with an entry of the array SchTRefs from an application.
 \COUNTERMEASURE \M [CM_OS_APP_SCHTREF_M]

\ID SBSW_OS_APP_SERVICEINIT_001
 \DESCRIPTION    Os_ServiceInit is called with an entry of the array ServiceFunctions from an application.
 \COUNTERMEASURE \M [CM_OS_APP_SERIVCEFUNCTION_M]

\ID SBSW_OS_APP_COUNTERSTART_001
 \DESCRIPTION    Os_CounterStart is called with an entry of the array CounterRefs from an application.
 \COUNTERMEASURE \M [CM_OS_APP_COUNTERREF_M]

\ID SBSW_OS_APP_TASKKILLALL_001
 \DESCRIPTION    Os_TaskKillAll is called with an entry of the array TaskRefs from an application.
 \COUNTERMEASURE \M [CM_OS_APP_TASKREF_M]

\ID SBSW_OS_APP_ISR1DISABLE_001
 \DESCRIPTION    Os_IsrCat1Disable is called with an entry of the array IsrCat1Refs from an application.
 \COUNTERMEASURE \M [CM_OS_APP_ISRCAT1REF_M]

\ID SBSW_OS_APP_ISRDISABLE_001
 \DESCRIPTION    Os_IsrDisable is called with an entry of the array IsrCat2Refs from an application.
 \COUNTERMEASURE \M [CM_OS_APP_ISRCAT2REF_M]

\ID SBSW_OS_APP_ALARMKILL_001
 \DESCRIPTION    Os_AlarmKill is called with an entry of the array AlarmRefs from an application.
 \COUNTERMEASURE \M [CM_OS_APP_ALARMREF_M]

\ID SBSW_OS_APP_Os_SCHTKILL_001
 \DESCRIPTION    Os_SchTKill is called with an entry of the array SchTRefs from an application.
 \COUNTERMEASURE \M [CM_OS_APP_SCHTREF_M]

\ID SBSW_OS_APP_THREADGETOWNERAPPLICATION_001
 \DESCRIPTION    Os_ThreadGetOwnerApplication is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_APP_THREADGETOWNERAPPLICATION_003
 \DESCRIPTION    Os_ThreadGetOwnerApplication is called with the return value of Os_TaskGetThread.
 \COUNTERMEASURE \N [CM_OS_TASKGETTHREAD_N]

\ID SBSW_OS_APP_THREADGETOWNERAPPLICATION_004
 \DESCRIPTION    Os_ThreadGetOwnerApplication is called with the return value of Os_IsrGetThread.
 \COUNTERMEASURE \N [CM_OS_ISRGETTHREAD_N]

\ID SBSW_OS_APP_HOOKKILL_001
 \DESCRIPTION    Os_HookKill is called with the return value of Os_HookThread2Hook.
 \COUNTERMEASURE \N [CM_HOOKTHREAD2HOOK_N]

\ID SBSW_OS_APP_ISRKILL_001
 \DESCRIPTION    Os_IsrKill is called with the return value of Os_IsrThread2Isr.
 \COUNTERMEASURE \M [CM_OS_ISRTHREAD2ISR_01_02_M]
                 \M [CM_OS_ISRTHREAD2ISR_02_02_M]

\ID SBSW_OS_APP_APPGETID_001
 \DESCRIPTION    Os_AppGetId is called with the return value of Os_ThreadGetOwnerApplication.
 \COUNTERMEASURE \M [CM_OS_THREADGETOWNERAPPLICATION_M]

\ID SBSW_OS_APP_APPGETID_002
 \DESCRIPTION    Os_AppGetId is called with the return value of Os_ThreadGetCurrentApplication.
 \COUNTERMEASURE \N [CM_OS_THREADGETCURRENTAPPLICATION_N]

\ID SBSW_OS_APP_THREADGETCURRENTAPPLICATION_001
 \DESCRIPTION    Os_ThreadGetCurrentApplication is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_APP_THREADCHECKCALLCONTEXT_001
 \DESCRIPTION    Os_ThreadCheckCallContext is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_APP_THREADCHECKAREINTERRUPTSENABLED_001
 \DESCRIPTION    Os_ThreadCheckAreInterruptsEnabled is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_APP_APPISCORELOCAL_001
 \DESCRIPTION    Os_AppIsCoreLocal is called with the return values of Os_AppId2App.
 \COUNTERMEASURE \M [CM_OS_APPID2APP_M]

\ID SBSW_OS_APP_APPGETSTATE_001
 \DESCRIPTION    Os_AppGetState is called with the return value of Os_AppId2App.
 \COUNTERMEASURE \M [CM_OS_APPID2APP_M]

\ID SBSW_OS_APP_APPGETSTATE_002
 \DESCRIPTION    Os_AppGetState is called with the return value of Os_ThreadGetCurrentApplication.
 \COUNTERMEASURE \N [CM_OS_THREADGETCURRENTAPPLICATION_N]

\ID SBSW_OS_APP_APPGETCORE_001
 \DESCRIPTION    Os_AppGetCore is called with the return value of Os_AppId2App.
 \COUNTERMEASURE \M [CM_OS_APPID2APP_M]

\ID SBSW_OS_APP_THREADISTASK_001
 \DESCRIPTION    Os_ThreadIsTask is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_APP_COREGETKERNELAPP_001
 \DESCRIPTION    Os_CoreGetKernelApp is called with the Core member of an App instance. Precondition ensures that the
                 App pointer is valid. The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_APPGETCORE_M]

\ID SBSW_OS_APP_APPKILLMEMBERTHREAD_001
 \DESCRIPTION    Os_AppKillMemberThread is called with the return value of Os_CoreInterruptedThreadsGet and the App
                 parameter of the caller, which is assured to be valid by precondition. The precondition is checked
                 by review.
 \COUNTERMEASURE \R [CM_COREINTERRUPTEDTHREADSGET_R]

\ID SBSW_OS_APP_COREASRISCORELOCAL_001
 \DESCRIPTION    Os_CoreasrIsCoreLocal is called with the return value of Os_AppGetCore.
 \COUNTERMEASURE \M [CM_OS_APPGETCORE_M]

SBSW_JUSTIFICATION_END */




/* The following counter measures shall be used, if the caller uses the result of a function. */

/*

\CM CM_OS_APPDYN_M
      Verify that the Dyn pointer of each application is no NULL_PTR. An initialization of this pointer
      with an incorrect type is expected to be checked by the compiler.

\CM CM_OS_APPGETCORE_M
      Verify that the Core reference in each application instance is no NULL_PTR.

\CM CM_OS_APPGETSTARTUPHOOK_N
      Precondition ensures that the pointer is valid. The compliance of the precondition is check during review.
      The caller ensures, that the returned pointer is not used for write accesses, if the pointer is NULL_PTR.

\CM CM_OS_APPGETERRORHOOK_N
      Precondition ensures that the pointer is valid. The compliance of the precondition is check during review.
      The caller ensures, that the returned pointer is not used for write accesses, if the pointer is NULL_PTR.

\CM CM_OS_APPGETSHUTDOWNHOOK_N
      Precondition ensures that the pointer is valid. The compliance of the precondition is check during review.
      The caller ensures, that the returned pointer is not used for write accesses, if the pointer is NULL_PTR.

\CM CM_OS_APPID2APP_M
      Verify that:
        1. each Application in OsCfg_AppRefs except the last is a non NULL_PTR,
        2. OsCfg_AppRefs has a size equal to OS_APPID_COUNT + 1 and
        3. each element in ApplicationType has a value lower than OS_APPID_COUNT.

\CM CM_OS_APPOBJECTGETAPP_R
      The caller ensures, that the returned pointer is not used for write accesses or as input for further
      functions, if the returned pointer is NULL_PTR.

\CM CM_OS_APP_ALARMREF_M
      Verify that:
        1. each application's AlarmRefs pointer is no NULL_PTR,
        2. each application's AlarmRefs size is equal to the AlarmCount + 1 and
        3. each element in AlarmRefs of each application except the last one is no NULL_PTR, the last one must be
           NULL_PTR.

\CM CM_OS_APP_COUNTERREF_M
      Verify that:
        1. each application's CounterRefs pointer is no NULL_PTR,
        2. each application's CounterRefs size is equal to the CounterCount + 1 and
        3. each element in CounterRefs of each application except the last one is no NULL_PTR, the last one must be
           NULL_PTR.

\CM CM_OS_APP_ISRCAT1REF_M
      Verify that:
        1. each application's IsrCat1Refs pointer is no NULL_PTR,
        2. each application's IsrCat1Refs size is equal to the IsrCat1Count + 1 and
        3. each element in IsrCat1Refs of each application except the last one is no NULL_PTR, the last one must be
           NULL_PTR.

\CM CM_OS_APP_ISRCAT2REF_M
      Verify that:
        1. each application's IsrCat2Refs pointer is no NULL_PTR,
        2. each application's IsrCat2Refs size is equal to the IsrCat2Count + 1 and
        3. each element in IsrCat2Refs of each application except the last one is no NULL_PTR, the last one must be
           NULL_PTR.

\CM CM_OS_APP_SCHTREF_M
      Verify that:
        1. Verify that each application's SchTRefs pointer is no NULL_PTR,
        2. each application's SchTRefs size is equal to the SchTCount + 1 and
        3. each element in SchTRefs of each application except the last one is no NULL_PTR, the last one must be
           NULL_PTR.

\CM CM_OS_APP_TASKREF_M
      Verify that:
        1. each application's TaskRefs pointer is no NULL_PTR,
        2. each application's TaskRefs size is equal to the TaskCount + 1 and
        3. each element in TaskRefs of each application except the last one is no NULL_PTR, the last one must be
           NULL_PTR.

\CM CM_OS_APP_SERIVCEFUNCTION_M
      Verify that:
        1. each application's ServiceFunctions pointer is no NULL_PTR,
        2. that each application's ServiceFunctions size is equal to the ServiceFunctionCount + 1 and
        3. each element in ServiceFunctions of each application except the last one is no NULL_PTR, the last one must be
           NULL_PTR.
*/

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Application.c
 **********************************************************************************************************************/
