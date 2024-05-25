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
 *  \addtogroup Os_Application
 *  \{
 *  \file
 *  \brief       Public application services.
 *  \details     --no details--
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_APPLICATION_H
# define OS_APPLICATION_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_ApplicationInt.h"

/* Os kernel module dependencies */
# include "Os_Error.h"
# include "Os_Core.h"
# include "Os_Isr.h"
# include "Os_TimingProtection.h"
# include "Os_Task.h"
# include "Os_Hook.h"
# include "Os_Counter.h"
# include "Os_Alarm.h"
# include "Os_Application.h"
# include "Os_ScheduleTable.h"
# include "Os_Common.h"
# include "Os_ServiceFunction.h"

/* Os Hal dependencies */
# include "Os_Hal_Compiler.h"



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
 *  Os_AppSetNotAccessible()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_AppSetNotAccessible,
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App
))
{
  App->Dyn->State = APPLICATION_TERMINATED;                                                                             /* SBSW_OS_APP_DYN_001 */
}


/***********************************************************************************************************************
 *  Os_AppStart()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_AppStart,                              /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App
))
{
  Os_ObjIdxType index;

  /* #10 Start Counters. */
  for(index = 0; index < App->CounterCount; index++)
  {
    Os_CounterStart(App->CounterRefs[index]);                                                                           /* SBSW_OS_APP_COUNTERSTART_001 */
  }
}


/***********************************************************************************************************************
 *  Os_AppGetState()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE ApplicationStateType, OS_CODE,                                             /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_AppGetState,
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App
))
{
  return App->Dyn->State;
}


/***********************************************************************************************************************
 *  Os_AppIsTrusted()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_AppIsTrusted,
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App
))
{
  return (Os_StdReturnType)(App->IsTrusted != FALSE);                                                                   /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_AppIsPrivileged()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMAPPISPRIVILEGED */
OS_ALWAYS_INLINE, Os_AppIsPrivileged,
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App
))                                                                                                                      /* COV_OS_HALPLATFORMAPPISPRIVILEGED */
{
  return (Os_StdReturnType)(App->IsPrivileged != FALSE);                                                                /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_AppHasTimingProtectionDelay()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_AppHasTimingProtectionDelay,
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App
))
{
  return (Os_StdReturnType)((Os_TpIsEnabled()) && (App->HasTimingProtectionDelay != FALSE));                            /* PRQA S 4304, 4558 */ /* MD_Os_C90BooleanCompatibility, MD_Os_Rule10.1_4558 */ /* COV_OS_HALPLATFORMTPUNSUPPORTED_XF */
}



/***********************************************************************************************************************
 *  Os_AppCheckAccess()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_AppCheckAccess,
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App,
  Os_AppAccessMaskType AccessMask
))
{
  return Os_ErrServiceProtectionCheck((Os_StdReturnType)(App->AccessRightId & AccessMask));
}


/***********************************************************************************************************************
 *  Os_AppCheckIsAccessible()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_AppCheckIsAccessible,
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App
))
{
  return Os_ErrServiceProtectionCheck((Os_StdReturnType)(                                                               /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
      Os_AppGetState(App) == APPLICATION_ACCESSIBLE));                                                                  /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_AppIsCoreLocal()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType,                                                          /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_CODE, OS_ALWAYS_INLINE, Os_AppIsCoreLocal,
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App
))
{
  return (Os_StdReturnType)(Os_CoreAsrIsCoreLocal(Os_AppGetCore(App)));                                                 /* SBSW_OS_APP_COREASRISCORELOCAL_001 */ /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_AppIsKernelApp()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_AppIsKernelApp,
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App
))
{
  return (Os_StdReturnType)(App == Os_CoreGetKernelApp(Os_AppGetCore(App)));                                            /* SBSW_OS_APP_COREGETKERNELAPP_001 */ /* SBSW_OS_FC_PRECONDITION */ /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_AppGetCore()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_AppGetCore,
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App
))
{
  return App->Core;
}


/***********************************************************************************************************************
 *  Os_AppGetId()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE ApplicationType, OS_CODE, OS_ALWAYS_INLINE, Os_AppGetId,
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App
))
{
  return App->Id;
}


/***********************************************************************************************************************
 *  Os_AppGetStartupHook()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE                                                                            /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
P2CONST(Os_HookCallbackConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_AppGetStartupHook,
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App
))
{
  return App->StartupHookRef;
}


/***********************************************************************************************************************
 *  Os_AppGetErrorHook()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE                                                                            /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
P2CONST(Os_HookStatusHookConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_AppGetErrorHook,
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App
))
{
  return App->ErrorHookRef;
}


/***********************************************************************************************************************
 *  Os_AppGetShutdownHook()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE                                                                            /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
P2CONST(Os_HookStatusHookConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_AppGetShutdownHook,
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App
))
{
  return App->ShutdownHookRef;
}


/***********************************************************************************************************************
 *  Os_AppCheckId()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_AppCheckId,
(
  ApplicationType AppId
))
{
  return Os_ErrExtendedCheck(Os_ErrIsValueLo((uint32)AppId, (uint32)OS_APPID_COUNT));
}


/***********************************************************************************************************************
 *  Os_AppId2App()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_AppId2App,
(
  ApplicationType AppId
))
{
  Os_Assert(Os_ErrIsValueLo((uint32)AppId, (uint32)OS_APPID_COUNT));
  return OsCfg_AppRefs[AppId];
}


/***********************************************************************************************************************
 *  Os_AppIsRestartTaskAvailable()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_AppIsRestartTaskAvailable,
(
    P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) App
))
{
  return (Os_StdReturnType)(App->RestartTask != NULL_PTR);                                                              /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */



#endif /* OS_APPLICATION_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_Application.h
 **********************************************************************************************************************/
