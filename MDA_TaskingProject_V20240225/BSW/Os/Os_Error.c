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
 *  \addtogroup Os_Error
 *  \{
 *
 *  \file
 *  \brief       Function implementations of error module.
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777, 0779, 0828  EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */


#define OS_ERROR_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Error.h"
#include "Os_Error_Cfg.h"
#include "Os_Error_Lcfg.h"

/* Os module dependencies */
#include "Os_Hook.h"
#include "Os_Isr.h"
#include "Os_Task.h"
#include "Os_Thread.h"
#include "Os_Application.h"
#include "Os_Core.h"
#include "Os_Stack.h"
#include "Os_Interrupt.h"

/* Os Hal dependencies */
#include "Os_Hal_Compiler.h"


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define OS_START_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  Os_ErrVerifyProtectionReaction()
 **********************************************************************************************************************/
/*! \brief        Verifies the protection reaction selected by the user and verifies whether it is possible in the
 *                current error situation.
 *  \details      --no details--
 *
 *
 *  \param[in]    UserReaction  Protection reaction to verify.
 *  \param[in]    Error         Error state in which the protection reaction has been selected.
 *
 *  \return       Adjusted protection reaction.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        SPEC-63723, SPEC-63562, SPEC-63718
 **********************************************************************************************************************/
OS_LOCAL FUNC(ProtectionReturnType, OS_CODE) Os_ErrVerifyProtectionReaction
(
  ProtectionReturnType UserReaction,
  StatusType Error
);


/***********************************************************************************************************************
 *  Os_ErrHandleProtectionReaction()
 **********************************************************************************************************************/
/*! \brief        Performs given protection reaction.
 *  \details      --no details--
 *
 *  \param[in]    ProtectionReaction  Protection reaction to handle.
 *  \param[in]    Error               The error code to be reported, in case of shutdown.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-21
 *  \trace        SPEC-63562
 **********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) Os_ErrHandleProtectionReaction
(
  ProtectionReturnType ProtectionReaction,
  StatusType Error
);


/***********************************************************************************************************************
 *  Os_ErrSetErrorDetails()
 **********************************************************************************************************************/
/*! \brief          Set the user accessible error information.
 *  \details        --no details--
 *
 *  \param[in,out]  ErrorDetails  Error details object to set. Parameter must not be NULL.
 *  \param[in]      ServiceId     Service ID to set. The value must not be OSSERVICEID_COUNT.
 *  \param[in]      Status        Detailed error status code.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrSetErrorDetails,
(
  P2VAR(Os_ErrorInformationType, AUTOMATIC, OS_APPL_VAR) ErrorDetails,
  OSServiceIdType ServiceId,
  Os_StatusType Status
));


/***********************************************************************************************************************
 *  Os_ErrIsInternalExceptionDetectionSupported()
 **********************************************************************************************************************/
/*! \brief          Returns if the internal exception detection is supported or not.
 *  \details        --no details--
 *
 *  \retval         !0 If the compiler supports internal exception detection.
 *  \retval         0  If the compiler does not support internal exception detection.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrIsInternalExceptionDetectionSupported,
(
  void
));


/***********************************************************************************************************************
 *  Os_ErrIsAddressInsideSection()
 **********************************************************************************************************************/
/*! \brief          Returns if the given address is inside the given memory area.
 *  \details        --no details--
 *
 *  \param[in]      Section        Start and end addresses to be checked.
 *  \param[in]      Address        Address to be checked.
 *
 *  \retval         !0 If the address is inside the given area.
 *  \retval         0  If the address is not inside the given area.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrIsAddressInsideSection,
(
  P2CONST(Os_LinkerSectionLabelsType, AUTOMATIC, OS_CONST) Section,
  Os_AddressOfConstType Address
));


/***********************************************************************************************************************
 *  Os_ErrIsOsInternalException()
 **********************************************************************************************************************/
/*! \brief        Returns whether the OS might be in an inconsistent state due to the given exception.
 *  \details      If the given exception occured during OS code execution with privileged access, the OS could be in
 *                an inconsistent state. Whereby exceution in non privileged mode never leads to inconsistency.
 *
 *  \see          \ref Os_ErrProtectionException
 *
 *  \param[in]    ErrorCausingAddress    Address that leads to an misbehavior of the system.
 *  \param[in]    ErrorCauserPrivileged  Privilege state before the error.
 *
 *  \retval       !0 The OS could be in an inconsistent state.
 *  \retval       0  The OS is consistent.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 **********************************************************************************************************************/
OS_LOCAL FUNC(Os_StdReturnType, OS_CODE) Os_ErrIsOsInternalException
(
  Os_AddressOfConstType ExceptionInstructionAddress,
  boolean ExceptionCauserPrivileged
);


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_ErrVerifyProtectionReaction()
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
 *
 *
 *
 *
 *
 */
OS_LOCAL FUNC(ProtectionReturnType, OS_CODE) Os_ErrVerifyProtectionReaction
(
  ProtectionReturnType UserReaction,
  StatusType Error
)
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;
  ProtectionReturnType result;

  /* #10 If there is no ProtectionHook: KernelPanic. */
  if (Os_HookIsProtectionHookEnabled() == 0u)                                                                           /* COV_OS_INVSTATE */ /* PRQA S 2991, 2995 */ /* MD_Os_Rule14.3_2991, MD_Os_Rule2.2_2995 */
  {
    Os_ErrKernelPanic();
  }

  currentThread = Os_CoreGetThread();
  result = UserReaction;

  /* #15 If the given user reaction is out of range, shutdown. */
  if(OS_UNLIKELY(Os_ErrIsValueLo((uint32)UserReaction, (uint32)OS_PROTECTIONREACTION_COUNT) == 0u))
  {
    result = PRO_SHUTDOWN;
  }
  /* #20 If the OS is not started on the current core, shutdown. */
  else if(OS_UNLIKELY((Os_CoreOsIsStarted(Os_ThreadGetCore(currentThread)) == 0u) &&                                    /* SBSW_OS_ERROR_COREOSISSTARTED_001 */ /* SBSW_OS_ERROR_THREADGETCORE_001 */
                      (UserReaction != PRO_IGNORE_EXCEPTION)))
  {
    result = PRO_SHUTDOWN;
  }
  /* #30 If the user reaction is PRO_IGNORE and there was no arrival time error, shutdown. */
  else if(OS_UNLIKELY((UserReaction == PRO_IGNORE) && (Error != E_OS_PROTECTION_ARRIVAL)))
  {
    result = PRO_SHUTDOWN;
  }
  /* #40 If there was an arrival time error and the user reaction is not PRO_IGNORE, shutdown. */
  else if(OS_UNLIKELY((Error == E_OS_PROTECTION_ARRIVAL) && (UserReaction != PRO_IGNORE)))                              /* COV_OS_HALPLATFORMTPUNSUPPORTED_XF */
  {
    result = PRO_SHUTDOWN;
  }
  /* #50 If protection violation has occured during user critical section, shutdown. */
  else if(OS_UNLIKELY((Os_CoreCriticalUserSectionIsActive(Os_ThreadGetCore(currentThread)) == TRUE) &&                  /* SBSW_OS_ERROR_THREADGETCORE_001 */ /* SBSW_OS_ERROR_CORECRITICALUSERSECTIONISACTIVE_001 */
                      (UserReaction != PRO_IGNORE_EXCEPTION)))
  {
    result = PRO_SHUTDOWN;
  }
  /* #60 If the user reaction is PRO_IGNORE_EXCEPTION and there was no memory error or exception, shutdown. */
  else if(OS_UNLIKELY((UserReaction == PRO_IGNORE_EXCEPTION) &&
                      ((Error != E_OS_PROTECTION_MEMORY)     &&
                       (Error != E_OS_PROTECTION_EXCEPTION))))
  {
    result = PRO_SHUTDOWN;
  }
  /* #70 If the user reaction is PRO_IGNORE_EXCEPTION and the HAL does not support this feature, shutdown */
  else if(OS_UNLIKELY((Os_CoreIsExceptionContextSupported() == 0u) && (UserReaction == PRO_IGNORE_EXCEPTION)))          /* COV_OS_NOFUNCCALL */
  {
    result = PRO_SHUTDOWN;
  }
  /* #80 If the user reaction requires termination: */
  else if((UserReaction == PRO_TERMINATETASKISR) ||
          (UserReaction == PRO_TERMINATEAPPL) ||
          (UserReaction == PRO_TERMINATEAPPL_RESTART))
  {
    P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) responsibleThread;
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) responsibleApplication;

    responsibleThread = Os_CoreThreadGetByContext(Os_ThreadGetCore(currentThread), OS_CALLCONTEXT_TERMINATEABLE);       /* SBSW_OS_ERROR_CORETHREADGETBYCONTEXT_001 */ /* SBSW_OS_ERROR_THREADGETCORE_001 */

    if(OS_UNLIKELY(responsibleThread == NULL_PTR))                                                                      /* COV_OS_INVSTATE */
    {
      /* As there is always a task, this case indicates an consistency error. */
      Os_ErrKernelPanic();
    }

    responsibleApplication = Os_ThreadGetCurrentApplication(responsibleThread);                                         /* SBSW_OS_ERROR_THREADGETCURRENTAPPLICATION_002 */

    if(OS_UNLIKELY(responsibleApplication == NULL_PTR))                                                                 /* COV_OS_INVSTATE */
    {
      /* As there is always a valid application, this case indicates an consistency error. */
      Os_ErrKernelPanic();
    }

    /* #90 If the current thread is a kernel thread, shutdown. */
    if(OS_UNLIKELY(Os_AppIsKernelApp(responsibleApplication) != 0u))                                                    /* SBSW_OS_ERROR_APPISKERNELAPP_001 */
    {
      result = PRO_SHUTDOWN;
    }

    /* #100 If the user reaction is PRO_TERMINATETASKISR and the responsible thread is neither a task
     *      nor an ISR, terminate the responsible application. */
    else if(UserReaction == PRO_TERMINATETASKISR)
    {
      Os_StdReturnType isTask;
      Os_StdReturnType isIsr;

      isTask = Os_ThreadIsTask(responsibleThread);                                                                      /* SBSW_OS_ERROR_THREADISTASK_001 */
      isIsr = Os_ThreadIsIsr(responsibleThread);                                                                        /* SBSW_OS_ERROR_THREADISISR_001 */

      if(OS_UNLIKELY((isIsr == 0u) && (isTask == 0u)))
      {
        result = PRO_TERMINATEAPPL;
      }
    }
    /* #110 If the user reaction is PRO_TERMINATEAPPL_RESTART and there is no restart task, shutdown */
    else if(UserReaction == PRO_TERMINATEAPPL_RESTART)
    {
      if(OS_UNLIKELY((Os_AppIsRestartTaskAvailable(responsibleApplication) == 0u)))                                     /* SBSW_OS_ERROR_APPISRESTARTTASKAVAILABLE_001 */
      {
        result = PRO_SHUTDOWN;
      }
    }
    else
    {
      /* No action required in any other case. MISRA 14.10 */
    }
  }
  else
  {
    /* No action required in any other case. MISRA 14.10 */
  }

  /* #120 Otherwise the user reaction is valid, return it. */

  return result;
}                                                                                                                       /* PRQA S 6030, 6050, 6080 */ /* MD_Os_STCYC, MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_ErrHandleProtectionReaction()
 **********************************************************************************************************************/
/*!
 *
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
OS_LOCAL FUNC(void, OS_CODE) Os_ErrHandleProtectionReaction
(
  ProtectionReturnType ProtectionReaction,
  StatusType Error
)
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) responsibleThread;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) responsibleApplication;

  /* #10 If there is no ProtectionHook: KernelPanic. */
  if (Os_HookIsProtectionHookEnabled() == 0u)                                                                           /* COV_OS_INVSTATE */ /* PRQA S 2991, 2995 */ /* MD_Os_Rule14.3_2991, MD_Os_Rule2.2_2995 */
  {
    Os_ErrKernelPanic();
  }

  /* #15 Call panic hook if the responsible thread cannot be resolved. */
  currentThread = Os_CoreGetThread();
  responsibleThread = Os_CoreThreadGetByContext(Os_ThreadGetCore(currentThread), OS_CALLCONTEXT_TERMINATEABLE);         /* SBSW_OS_ERROR_CORETHREADGETBYCONTEXT_001 */ /* SBSW_OS_ERROR_THREADGETCORE_001 */
  if(OS_UNLIKELY(responsibleThread == NULL_PTR))                                                                        /* COV_OS_INVSTATE */
  {
    /* As there is always a task, this case indicates an consistency error. */
    Os_ErrKernelPanic();
  }
  /*! Internal comment removed.
 *
 *
 * */
  responsibleApplication = Os_ThreadGetOwnerApplication(responsibleThread);                                             /* SBSW_OS_ERROR_THREADGETOWNERAPPLICATION_001 */

  switch(ProtectionReaction)
  {
    /* #20 PRO_IGNORE - If the arrival time was exceeded, do nothing. */
    case PRO_IGNORE:                                                                                                    /* COV_OS_HALPLATFORMTPUNSUPPORTED_XX */
      break;

    /* #30 PRO_IGNORE_EXCEPTION - If memory error or exception was reported, return with modified user context. */
    case PRO_IGNORE_EXCEPTION:                                                                                          /* COV_OS_HALPLATFORMEXCEPTIONCONTEXTUNSUPPORTED */
      break;

    /* #40 PRO_TERMINATETASKISR - Kill the erroneous task/ISR instance. */
    case PRO_TERMINATETASKISR:
      if(Os_ThreadIsTask(responsibleThread) != 0u)                                                                      /* SBSW_OS_ERROR_THREADISTASK_002 */
      {
        Os_TaskKill();
      }
      else if(Os_ThreadIsIsr(responsibleThread) != 0u)                                                                  /* SBSW_OS_ERROR_THREADISISR_002 */
      {
        Os_IsrKill(Os_IsrThread2Isr(responsibleThread));                                                                /* SBSW_OS_ERROR_ISRKILL_001 */ /* SBSW_OS_ERROR_ISRTHREAD2ISR_001 */
      }
      else
      {
        Os_ErrKernelPanic();
      }

      if(Os_ThreadIsTpIsr(currentThread) == 0u)                                                                         /* SBSW_OS_ERROR_THREADISTPISR_001 */
      {
        Os_ThreadSuicide();
      }
      break;

    /* #50 PRO_TERMINATEAPPL - Kill the erroneous application. */
    case PRO_TERMINATEAPPL:
      Os_AppKill(responsibleApplication, NO_RESTART);                                                                   /* SBSW_OS_ERROR_APPKILL_001 */
      break;

    /* #60 PRO_TERMINATEAPPL_RESTART - Kill and restart the erroneous application. */
    case PRO_TERMINATEAPPL_RESTART:
      Os_AppKill(responsibleApplication, RESTART);                                                                      /* SBSW_OS_ERROR_APPKILL_001 */
      break;

    /* #70 PRO_SHUTDOWN - Shutdown the system. */
    case PRO_SHUTDOWN:
      Os_SystemShutdown(Error);
      break;

    /* #80 Invalid protection reaction - kernel panic. */
    default:                                                                                                            /* COV_OS_INVSTATE */
      Os_ErrKernelPanic();
      break;
  }
}                                                                                                                       /* PRQA S 6030, 6050 */ /* MD_Os_STCYC, MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_ErrSetErrorDetails()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrSetErrorDetails,
(
  P2VAR(Os_ErrorInformationType, AUTOMATIC, OS_APPL_VAR) ErrorDetails,
  OSServiceIdType ServiceId,
  Os_StatusType Status
))
{
  ErrorDetails->Service = ServiceId;                                                                                    /* SBSW_OS_PWA_PRECONDITION */
  ErrorDetails->Error = Os_ErrOsStatus2UserStatus(Status);                                                              /* SBSW_OS_PWA_PRECONDITION */
  ErrorDetails->DetailedError = Status;                                                                                 /* SBSW_OS_PWA_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_ErrIsInternalExceptionDetectionSupported()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrIsInternalExceptionDetectionSupported, (void))
{
  return (Os_StdReturnType)(OS_CFG_INTERNAL_EXCEPTION_DETECTION == STD_ON);                                             /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_ErrIsAddressInsideSection()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrIsAddressInsideSection,
(
  P2CONST(Os_LinkerSectionLabelsType, AUTOMATIC, OS_CONST) Section,
  Os_AddressOfConstType Address
))
{
  return (Os_StdReturnType) ((Address >= Section->StartLabel) &&                                                        /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
                             (Address <= Section->EndLabel));
}


/***********************************************************************************************************************
 *  Os_ErrIsOsInternalException()
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
OS_LOCAL FUNC(Os_StdReturnType, OS_CODE) Os_ErrIsOsInternalException
(
  Os_AddressOfConstType ExceptionInstructionAddress,
  boolean ExceptionCauserPrivileged
)
{
  Os_StdReturnType result;

  /* #10 If the causer of the exception was not privileged: */
  if (ExceptionCauserPrivileged == FALSE)
  {
    /* #20 The OS could not be inconsistent. */
    result = 0;
  }
  /* #30 Otherwise, if the OS code section check is supported: */
  else if(Os_ErrIsInternalExceptionDetectionSupported() != 0u)                                                          /* PRQA S 2991, 2995 */ /* MD_Os_Rule14.3_2991, MD_Os_Rule2.2_2995 */ /* COV_OS_ERRCODESECTIONCHECK */
  {
    Os_ObjIdxType index;
    result = 0;

    /* #40 Check each OS code section: */
    for(index = 0; index < (Os_ObjIdxType)OS_CFG_NUM_OSCODE_SECTIONS; index++)
    {
      /* #50 If the address is inside the OS code section: */
      if (Os_ErrIsAddressInsideSection(OsCfg_OsCode_Sections[index], ExceptionInstructionAddress) != 0u)                /* SBSW_OS_ERROR_ISADDRESSINSIDESECTION_001 */
      {
        /* #60 The OS could be in an inconsistent state. */
        result = !0u;                                                                                                   /* PRQA S 4404, 4558 */ /* MD_Os_C90BooleanCompatibility, MD_Os_Rule10.1_4558 */
      }
    }
  }
  else
  {
    /* #70 Otherwise, if the causer of the exception was privileged and code section check is not supported,
     *     the OS could be in an inconsistent state. */
    result = !0u;                                                                                                       /* PRQA S 2880, 4404, 4558 */ /* MD_Os_Rule2.1_2880, MD_Os_C90BooleanCompatibility, MD_Os_Rule10.1_4558 */
  }

  return result;
}


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_ErrInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, OS_CODE) Os_ErrInit
(
  P2VAR(Os_ErrorType, AUTOMATIC, OS_VAR_NOINIT) Error
)
{
  /* #10 Initialize error details. */
  Os_ErrSetErrorDetails(&(Error->ErrorDetails), OSSERVICEID_COUNT, OS_STATUS_OK);                                       /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_AlarmType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(AlarmType, OS_CODE) Os_ErrorGetParameter_AlarmType(Os_ErrorParmIndexType ParamIndex)
{
  Os_Assert(Os_ErrIsValueLo((uint32)ParamIndex, (uint32)OS_ERRORPARAMINDEX_COUNT));

  /* #10 Fetch requested error parameter from core and return it. */
  return Os_CoreGetLastError(Os_ThreadGetCore(Os_TrapCoreGetThread()))                                                  /* SBSW_OS_ERROR_COREGETLASTERROR_001 */ /* SBSW_OS_ERROR_THREADGETCORE_002 */
      ->Parameters.Parameter[ParamIndex].ParamAlarmType;                                                                /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_AlarmBaseRefType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(AlarmBaseRefType, OS_CODE) Os_ErrorGetParameter_AlarmBaseRefType(Os_ErrorParmIndexType ParamIndex)
{
  Os_Assert(Os_ErrIsValueLo((uint32)ParamIndex, (uint32)OS_ERRORPARAMINDEX_COUNT));

  /* #10 Fetch requested error parameter from core and return it. */
  return Os_CoreGetLastError(Os_ThreadGetCore(Os_TrapCoreGetThread()))                                                  /* SBSW_OS_ERROR_COREGETLASTERROR_001 */ /* SBSW_OS_ERROR_THREADGETCORE_002 */
      ->Parameters.Parameter[ParamIndex].ParamAlarmBaseRefType;                                                         /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_ApplicationStateRefType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(ApplicationStateRefType, OS_CODE) Os_ErrorGetParameter_ApplicationStateRefType
(
  Os_ErrorParmIndexType ParamIndex
)
{
  Os_Assert(Os_ErrIsValueLo((uint32)ParamIndex, (uint32)OS_ERRORPARAMINDEX_COUNT));

  /* #10 Fetch requested error parameter from core and return it. */
  return Os_CoreGetLastError(Os_ThreadGetCore(Os_TrapCoreGetThread()))                                                  /* SBSW_OS_ERROR_COREGETLASTERROR_001 */ /* SBSW_OS_ERROR_THREADGETCORE_002 */
      ->Parameters.Parameter[ParamIndex].ParamApplicationStateRefType;                                                  /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_ApplicationType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(ApplicationType, OS_CODE) Os_ErrorGetParameter_ApplicationType(Os_ErrorParmIndexType ParamIndex)
{
  Os_Assert(Os_ErrIsValueLo((uint32)ParamIndex, (uint32)OS_ERRORPARAMINDEX_COUNT));

  /* #10 Fetch requested error parameter from core and return it. */
  return Os_CoreGetLastError(Os_ThreadGetCore(Os_TrapCoreGetThread()))                                                  /* SBSW_OS_ERROR_COREGETLASTERROR_001 */ /* SBSW_OS_ERROR_THREADGETCORE_002 */
      ->Parameters.Parameter[ParamIndex].ParamApplicationType;                                                          /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_boolean()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(boolean, OS_CODE) Os_ErrorGetParameter_boolean(Os_ErrorParmIndexType ParamIndex)
{
  Os_Assert(Os_ErrIsValueLo((uint32)ParamIndex, (uint32)OS_ERRORPARAMINDEX_COUNT));

  /* #10 Fetch requested error parameter from core and return it. */
  return Os_CoreGetLastError(Os_ThreadGetCore(Os_TrapCoreGetThread()))                                                  /* SBSW_OS_ERROR_COREGETLASTERROR_001 */ /* SBSW_OS_ERROR_THREADGETCORE_002 */
      ->Parameters.Parameter[ParamIndex].Paramboolean;                                                                  /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_booleanRefType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(P2VAR(boolean, AUTOMATIC, OS_VAR_NOINIT), OS_CODE) Os_ErrorGetParameter_booleanRefType
(
  Os_ErrorParmIndexType ParamIndex
)
{
  Os_Assert(Os_ErrIsValueLo((uint32)ParamIndex, (uint32)OS_ERRORPARAMINDEX_COUNT));

  /* #10 Fetch requested error parameter from core and return it. */
  return Os_CoreGetLastError(Os_ThreadGetCore(Os_TrapCoreGetThread()))                                                  /* SBSW_OS_ERROR_COREGETLASTERROR_001 */ /* SBSW_OS_ERROR_THREADGETCORE_002 */
      ->Parameters.Parameter[ParamIndex].ParambooleanRefType;                                                           /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_CoreIdType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(CoreIdType, OS_CODE) Os_ErrorGetParameter_CoreIdType(Os_ErrorParmIndexType ParamIndex)                             /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
{
  Os_Assert(Os_ErrIsValueLo((uint32)ParamIndex, (uint32)OS_ERRORPARAMINDEX_COUNT));

  /* #10 Fetch requested error parameter from core and return it. */
  return Os_CoreGetLastError(Os_ThreadGetCore(Os_TrapCoreGetThread()))                                                  /* SBSW_OS_ERROR_COREGETLASTERROR_001 */ /* SBSW_OS_ERROR_THREADGETCORE_002 */
      ->Parameters.Parameter[ParamIndex].ParamCoreIdType;                                                               /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_ExceptionContextRefType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Os_ExceptionContextRefType, OS_CODE) Os_ErrorGetParameter_ExceptionContextRefType(Os_ErrorParmIndexType ParamIndex)
{
  Os_Assert(Os_ErrIsValueLo((uint32)ParamIndex, (uint32)OS_ERRORPARAMINDEX_COUNT));

  /* #10 Fetch requested error parameter from core and return it. */
  return Os_CoreGetLastError(Os_ThreadGetCore(Os_TrapCoreGetThread()))                                                  /* SBSW_OS_ERROR_COREGETLASTERROR_001 */ /* SBSW_OS_ERROR_THREADGETCORE_002 */
      ->Parameters.Parameter[ParamIndex].ParamExceptionContextRefType;                                                  /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_CounterType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(CounterType, OS_CODE) Os_ErrorGetParameter_CounterType(Os_ErrorParmIndexType ParamIndex)
{
  Os_Assert(Os_ErrIsValueLo((uint32)ParamIndex, (uint32)OS_ERRORPARAMINDEX_COUNT));

  /* #10 Fetch requested error parameter from core and return it. */
  return Os_CoreGetLastError(Os_ThreadGetCore(Os_TrapCoreGetThread()))                                                  /* SBSW_OS_ERROR_COREGETLASTERROR_001 */ /* SBSW_OS_ERROR_THREADGETCORE_002 */
      ->Parameters.Parameter[ParamIndex].ParamCounterType;                                                              /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_EventMaskType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(EventMaskType, OS_CODE) Os_ErrorGetParameter_EventMaskType(Os_ErrorParmIndexType ParamIndex)
{
  Os_Assert(Os_ErrIsValueLo((uint32)ParamIndex, (uint32)OS_ERRORPARAMINDEX_COUNT));

  /* #10 Fetch requested error parameter from core and return it. */
  return Os_CoreGetLastError(Os_ThreadGetCore(Os_TrapCoreGetThread()))                                                  /* SBSW_OS_ERROR_COREGETLASTERROR_001 */ /* SBSW_OS_ERROR_THREADGETCORE_002 */
      ->Parameters.Parameter[ParamIndex].ParamEventMaskType;                                                            /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_EventMaskRefType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(EventMaskType*, OS_CODE) Os_ErrorGetParameter_EventMaskRefType(Os_ErrorParmIndexType ParamIndex)
{
  Os_Assert(Os_ErrIsValueLo((uint32)ParamIndex, (uint32)OS_ERRORPARAMINDEX_COUNT));

  /* #10 Fetch requested error parameter from core and return it. */
  return Os_CoreGetLastError(Os_ThreadGetCore(Os_TrapCoreGetThread()))                                                  /* SBSW_OS_ERROR_COREGETLASTERROR_001 */ /* SBSW_OS_ERROR_THREADGETCORE_002 */
      ->Parameters.Parameter[ParamIndex].ParamEventMaskRefType;                                                         /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_IdleModeType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(IdleModeType, OS_CODE) Os_ErrorGetParameter_IdleModeType(Os_ErrorParmIndexType ParamIndex)                         /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
{
  Os_Assert(Os_ErrIsValueLo((uint32)ParamIndex, (uint32)OS_ERRORPARAMINDEX_COUNT));

  /* #10 Fetch requested error parameter from core and return it. */
  return Os_CoreGetLastError(Os_ThreadGetCore(Os_TrapCoreGetThread()))                                                  /* SBSW_OS_ERROR_COREGETLASTERROR_001 */ /* SBSW_OS_ERROR_THREADGETCORE_002 */
      ->Parameters.Parameter[ParamIndex].ParamIdleModeType;                                                             /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_ISRType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(ISRType, OS_CODE) Os_ErrorGetParameter_ISRType(Os_ErrorParmIndexType ParamIndex)
{
  Os_Assert(Os_ErrIsValueLo((uint32)ParamIndex, (uint32)OS_ERRORPARAMINDEX_COUNT));

  /* #10 Fetch requested error parameter from core and return it. */
  return Os_CoreGetLastError(Os_ThreadGetCore(Os_TrapCoreGetThread()))                                                  /* SBSW_OS_ERROR_COREGETLASTERROR_001 */ /* SBSW_OS_ERROR_THREADGETCORE_002 */
      ->Parameters.Parameter[ParamIndex].ParamISRType;                                                                  /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_ResourceType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(ResourceType, OS_CODE) Os_ErrorGetParameter_ResourceType(Os_ErrorParmIndexType ParamIndex)
{
  Os_Assert(Os_ErrIsValueLo((uint32)ParamIndex, (uint32)OS_ERRORPARAMINDEX_COUNT));

  /* #10 Fetch requested error parameter from core and return it. */
  return Os_CoreGetLastError(Os_ThreadGetCore(Os_TrapCoreGetThread()))                                                  /* SBSW_OS_ERROR_COREGETLASTERROR_001 */ /* SBSW_OS_ERROR_THREADGETCORE_002 */
      ->Parameters.Parameter[ParamIndex].ParamResourceType;                                                             /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_InterruptSourceIdRefType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Os_InterruptSourceIdRefType, OS_CODE) Os_ErrorGetParameter_InterruptSourceIdRefType                                /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
(
  Os_ErrorParmIndexType ParamIndex
)
{
  Os_Assert(Os_ErrIsValueLo((uint32)ParamIndex, (uint32)OS_ERRORPARAMINDEX_COUNT));

  /* #10 Fetch requested error parameter from core and return it. */
  return Os_CoreGetLastError(Os_ThreadGetCore(Os_TrapCoreGetThread()))                                                  /* SBSW_OS_ERROR_COREGETLASTERROR_001 */ /* SBSW_OS_ERROR_THREADGETCORE_002 */
      ->Parameters.Parameter[ParamIndex].ParamInterruptSourceIdRefType;                                                 /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_ExceptionSourceIdRefType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Os_ExceptionSourceIdRefType, OS_CODE) Os_ErrorGetParameter_ExceptionSourceIdRefType                                /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
(
  Os_ErrorParmIndexType ParamIndex
)
{
  Os_Assert(Os_ErrIsValueLo((uint32)ParamIndex, (uint32)OS_ERRORPARAMINDEX_COUNT));

  /* #10 Fetch requested error parameter from core and return it. */
  return Os_CoreGetLastError(Os_ThreadGetCore(Os_TrapCoreGetThread()))                                                  /* SBSW_OS_ERROR_COREGETLASTERROR_001 */ /* SBSW_OS_ERROR_THREADGETCORE_002 */
      ->Parameters.Parameter[ParamIndex].ParamExceptionSourceIdRefType;                                                 /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_RestartType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(RestartType, OS_CODE) Os_ErrorGetParameter_RestartType(Os_ErrorParmIndexType ParamIndex)
{
  Os_Assert(Os_ErrIsValueLo((uint32)ParamIndex, (uint32)OS_ERRORPARAMINDEX_COUNT));

  /* #10 Fetch requested error parameter from core and return it. */
  return Os_CoreGetLastError(Os_ThreadGetCore(Os_TrapCoreGetThread()))                                                  /* SBSW_OS_ERROR_COREGETLASTERROR_001 */ /* SBSW_OS_ERROR_THREADGETCORE_002 */
      ->Parameters.Parameter[ParamIndex].ParamRestartType;                                                              /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_ScheduleTableStatusRefType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(ScheduleTableStatusRefType, OS_CODE) Os_ErrorGetParameter_ScheduleTableStatusRefType
(
  Os_ErrorParmIndexType ParamIndex
)
{
  Os_Assert(Os_ErrIsValueLo((uint32)ParamIndex, (uint32)OS_ERRORPARAMINDEX_COUNT));

  /* #10 Fetch requested error parameter from core and return it. */
  return Os_CoreGetLastError(Os_ThreadGetCore(Os_TrapCoreGetThread()))                                                  /* SBSW_OS_ERROR_COREGETLASTERROR_001 */ /* SBSW_OS_ERROR_THREADGETCORE_002 */
      ->Parameters.Parameter[ParamIndex].ParamScheduleTableStatusRefType;                                               /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_ScheduleTableType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(ScheduleTableType, OS_CODE) Os_ErrorGetParameter_ScheduleTableType(Os_ErrorParmIndexType ParamIndex)
{
  Os_Assert(Os_ErrIsValueLo((uint32)ParamIndex, (uint32)OS_ERRORPARAMINDEX_COUNT));

  /* #10 Fetch requested error parameter from core and return it. */
  return Os_CoreGetLastError(Os_ThreadGetCore(Os_TrapCoreGetThread()))                                                  /* SBSW_OS_ERROR_COREGETLASTERROR_001 */ /* SBSW_OS_ERROR_THREADGETCORE_002 */
      ->Parameters.Parameter[ParamIndex].ParamScheduleTableType;                                                        /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_SpinlockIdType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(SpinlockIdType, OS_CODE) Os_ErrorGetParameter_SpinlockIdType(Os_ErrorParmIndexType ParamIndex)
{
  Os_Assert(Os_ErrIsValueLo((uint32)ParamIndex, (uint32)OS_ERRORPARAMINDEX_COUNT));

  /* #10 Fetch requested error parameter from core and return it. */
  return Os_CoreGetLastError(Os_ThreadGetCore(Os_TrapCoreGetThread()))                                                  /* SBSW_OS_ERROR_COREGETLASTERROR_001 */ /* SBSW_OS_ERROR_THREADGETCORE_002 */
      ->Parameters.Parameter[ParamIndex].ParamSpinlockIdType;                                                           /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_TaskRefType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(TaskRefType, OS_CODE) Os_ErrorGetParameter_TaskRefType(Os_ErrorParmIndexType ParamIndex)
{
  Os_Assert(Os_ErrIsValueLo((uint32)ParamIndex, (uint32)OS_ERRORPARAMINDEX_COUNT));

  /* #10 Fetch requested error parameter from core and return it. */
  return Os_CoreGetLastError(Os_ThreadGetCore(Os_TrapCoreGetThread()))                                                  /* SBSW_OS_ERROR_COREGETLASTERROR_001 */ /* SBSW_OS_ERROR_THREADGETCORE_002 */
      ->Parameters.Parameter[ParamIndex].ParamTaskRefType;                                                              /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_TaskStateRefType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(TaskStateRefType, OS_CODE) Os_ErrorGetParameter_TaskStateRefType(Os_ErrorParmIndexType ParamIndex)
{
  Os_Assert(Os_ErrIsValueLo((uint32)ParamIndex, (uint32)OS_ERRORPARAMINDEX_COUNT));

  /* #10 Fetch requested error parameter from core and return it. */
  return Os_CoreGetLastError(Os_ThreadGetCore(Os_TrapCoreGetThread()))                                                  /* SBSW_OS_ERROR_COREGETLASTERROR_001 */ /* SBSW_OS_ERROR_THREADGETCORE_002 */
      ->Parameters.Parameter[ParamIndex].ParamTaskStateRefType;                                                         /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_BarrierIdType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Os_BarrierIdType, OS_CODE) Os_ErrorGetParameter_BarrierIdType(Os_ErrorParmIndexType ParamIndex)                    /* COV_OS_UNSUPPORTED93797 */
{
  Os_Assert(Os_ErrIsValueLo((uint32)ParamIndex, (uint32)OS_ERRORPARAMINDEX_COUNT));

  /* #10 Fetch requested error parameter from core and return it. */
  return Os_CoreGetLastError(Os_ThreadGetCore(Os_TrapCoreGetThread()))                                                  /* SBSW_OS_ERROR_COREGETLASTERROR_001 */ /* SBSW_OS_ERROR_THREADGETCORE_002 */
      ->Parameters.Parameter[ParamIndex].ParamBarrierIdType;                                                            /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_TaskType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(TaskType, OS_CODE) Os_ErrorGetParameter_TaskType(Os_ErrorParmIndexType ParamIndex)
{
  Os_Assert(Os_ErrIsValueLo((uint32)ParamIndex, (uint32)OS_ERRORPARAMINDEX_COUNT));

  /* #10 Fetch requested error parameter from core and return it. */
  return Os_CoreGetLastError(Os_ThreadGetCore(Os_TrapCoreGetThread()))                                                  /* SBSW_OS_ERROR_COREGETLASTERROR_001 */ /* SBSW_OS_ERROR_THREADGETCORE_002 */
      ->Parameters.Parameter[ParamIndex].ParamTaskType;                                                                 /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_TickRefType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(TickRefType, OS_CODE) Os_ErrorGetParameter_TickRefType(Os_ErrorParmIndexType ParamIndex)
{
  Os_Assert(Os_ErrIsValueLo((uint32)ParamIndex, (uint32)OS_ERRORPARAMINDEX_COUNT));

  /* #10 Fetch requested error parameter from core and return it. */
  return Os_CoreGetLastError(Os_ThreadGetCore(Os_TrapCoreGetThread()))                                                  /* SBSW_OS_ERROR_COREGETLASTERROR_001 */ /* SBSW_OS_ERROR_THREADGETCORE_002 */
      ->Parameters.Parameter[ParamIndex].ParamTickRefType;                                                              /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_TickType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(TickType, OS_CODE) Os_ErrorGetParameter_TickType(Os_ErrorParmIndexType ParamIndex)
{
  Os_Assert(Os_ErrIsValueLo((uint32)ParamIndex, (uint32)OS_ERRORPARAMINDEX_COUNT));

  /* #10 Fetch requested error parameter from core and return it. */
  return Os_CoreGetLastError(Os_ThreadGetCore(Os_TrapCoreGetThread()))                                                  /* SBSW_OS_ERROR_COREGETLASTERROR_001 */ /* SBSW_OS_ERROR_THREADGETCORE_002 */
      ->Parameters.Parameter[ParamIndex].ParamTickType;                                                                 /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_TrustedFunctionIndexType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(TrustedFunctionIndexType, OS_CODE) Os_ErrorGetParameter_TrustedFunctionIndexType                                   /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
(
  Os_ErrorParmIndexType ParamIndex
)
{
  Os_Assert(Os_ErrIsValueLo((uint32)ParamIndex, (uint32)OS_ERRORPARAMINDEX_COUNT));

  /* #10 Fetch requested error parameter from core and return it. */
  return Os_CoreGetLastError(Os_ThreadGetCore(Os_TrapCoreGetThread()))                                                  /* SBSW_OS_ERROR_COREGETLASTERROR_001 */ /* SBSW_OS_ERROR_THREADGETCORE_002 */
      ->Parameters.Parameter[ParamIndex].ParamTrustedFunctionIndexType;                                                 /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_TrustedFunctionParameterRefType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(TrustedFunctionParameterRefType, OS_CODE) Os_ErrorGetParameter_TrustedFunctionParameterRefType                     /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
(
  Os_ErrorParmIndexType ParamIndex
)
{
  Os_Assert(Os_ErrIsValueLo((uint32)ParamIndex, (uint32)OS_ERRORPARAMINDEX_COUNT));

  /* #10 Fetch requested error parameter from core and return it. */
  return Os_CoreGetLastError(Os_ThreadGetCore(Os_TrapCoreGetThread()))                                                  /* SBSW_OS_ERROR_COREGETLASTERROR_001 */ /* SBSW_OS_ERROR_THREADGETCORE_002 */
      ->Parameters.Parameter[ParamIndex].ParamTrustedFunctionParameterRefType;                                          /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_Os_NonTrustedFunctionIndexType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Os_NonTrustedFunctionIndexType, OS_CODE) Os_ErrorGetParameter_Os_NonTrustedFunctionIndexType                       /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
(
  Os_ErrorParmIndexType ParamIndex
)
{
  Os_Assert(Os_ErrIsValueLo((uint32)ParamIndex, (uint32)OS_ERRORPARAMINDEX_COUNT));

  /* #10 Fetch requested error parameter from core and return it. */
  return Os_CoreGetLastError(Os_ThreadGetCore(Os_TrapCoreGetThread()))                                                  /* SBSW_OS_ERROR_COREGETLASTERROR_001 */ /* SBSW_OS_ERROR_THREADGETCORE_002 */
      ->Parameters.Parameter[ParamIndex].ParamOs_NonTrustedFunctionIndexType;                                           /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_Os_NonTrustedFunctionParameterRefType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Os_NonTrustedFunctionParameterRefType, OS_CODE) Os_ErrorGetParameter_Os_NonTrustedFunctionParameterRefType         /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
(
  Os_ErrorParmIndexType ParamIndex
)
{
  Os_Assert(Os_ErrIsValueLo((uint32)ParamIndex, (uint32)OS_ERRORPARAMINDEX_COUNT));

  /* #10 Fetch requested error parameter from core and return it. */
  return Os_CoreGetLastError(Os_ThreadGetCore(Os_TrapCoreGetThread()))                                                  /* SBSW_OS_ERROR_COREGETLASTERROR_001 */ /* SBSW_OS_ERROR_THREADGETCORE_002 */
      ->Parameters.Parameter[ParamIndex].ParamOs_NonTrustedFunctionParameterRefType;                                    /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_TryToGetSpinlockRefType()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(TryToGetSpinlockType const*, OS_CODE) Os_ErrorGetParameter_TryToGetSpinlockRefType
(Os_ErrorParmIndexType ParamIndex)
{
  Os_Assert(Os_ErrIsValueLo((uint32)ParamIndex, (uint32)OS_ERRORPARAMINDEX_COUNT));

  /* #10 Fetch requested error parameter from core and return it. */
  return Os_CoreGetLastError(Os_ThreadGetCore(Os_TrapCoreGetThread()))                                                  /* SBSW_OS_ERROR_COREGETLASTERROR_001 */ /* SBSW_OS_ERROR_THREADGETCORE_002 */
      ->Parameters.Parameter[ParamIndex].ParamTryToGetSpinlockConstRefType;                                             /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  Os_ErrApplicationError()
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
FUNC(void, OS_CODE) Os_ErrApplicationError
(
  OSServiceIdType ServiceId,
  Os_StatusType Status,
  P2CONST(Os_ErrorParamsType, TYPEDEF, OS_VAR_NOINIT) Parameters
)
{
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) localCore;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;
  P2VAR(Os_ErrorType, AUTOMATIC, OS_VAR_NOINIT) lastError;
  Os_IntStateType interruptState;
  StatusType userStatus;

  currentThread = Os_CoreGetThread();
  localCore = Os_ThreadGetCore(currentThread);                                                                          /* SBSW_OS_ERROR_THREADGETCORE_001 */
  lastError = Os_CoreGetLastError(localCore);                                                                           /* SBSW_OS_ERROR_COREGETLASTERROR_001 */

  /* #10 Suspend interrupts. */
  Os_IntSuspend(&interruptState);                                                                                       /* SBSW_OS_FC_POINTER2LOCAL */

  /* #20 Write the error information to the core's error object. */
  Os_ErrSetErrorDetails(&lastError->ErrorDetails, ServiceId, Status);                                                   /* SBSW_OS_ERROR_ERRSETERRORDETAILS_001 */
  lastError->Parameters = *Parameters;                                                                                  /* SBSW_OS_ERROR_COREGETLASTERROR_002 */

  userStatus = Os_ErrOsStatus2UserStatus(Status);

  /* #30 Call system error hook (might never come back). */
  Os_HookCallStatusHook(Os_CoreGetErrorHook(localCore), userStatus);                                                    /* SBSW_OS_ERROR_HOOKCALLSTATUSHOOK_001 */ /* SBSW_OS_ERROR_COREGETERRORHOOK_001 */

  /* #40 If StartOS() has been called before, so applications are initialized: */
  if(OS_LIKELY(Os_CoreOsIsStarted(localCore) != 0u))                                                                    /* SBSW_OS_ERROR_COREOSISSTARTED_001 */
  {
    /* #50 Call application specific error hook of current application (might never come back). */
    Os_HookCallStatusHook(Os_AppGetErrorHook(Os_ThreadGetCurrentApplication(currentThread)), userStatus);               /* SBSW_OS_ERROR_OS_HOOKSTATUSHOOK_002 */ /* SBSW_OS_ERROR_APPGETERRORHOOK_001 */ /* SBSW_OS_ERROR_THREADGETCURRENTAPPLICATION_001 */
  }

  /* #60 Resume interrupts. */
  Os_IntResume(&interruptState);                                                                                        /* SBSW_OS_FC_POINTER2LOCAL */
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_ErrProtectionError()
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
FUNC(void, OS_CODE) Os_ErrProtectionError(Os_StatusType Fatalerror)
{
  StatusType status;

  status = Os_ErrOsStatus2UserStatus(Fatalerror);

  if (Os_HookIsProtectionHookEnabled() != 0u)                                                                           /* PRQA S 2991, 2995 */ /* MD_Os_Rule14.3_2991, MD_Os_Rule2.2_2995 */
  {
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) localCore;
    P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;
    ProtectionReturnType protectionReaction;
    Os_IntStateType interruptState;

    currentThread = Os_CoreGetThread();
    localCore = Os_ThreadGetCore(currentThread);                                                                        /* SBSW_OS_ERROR_THREADGETCORE_001 */

    /* #10 Suspend interrupts. */
    Os_IntSuspend(&interruptState);                                                                                     /* SBSW_OS_FC_POINTER2LOCAL */

    /* #20 Call protection hook. */
    protectionReaction = Os_HookCallProtectionHook(Os_CoreGetProtectionHook(localCore), status);                        /* SBSW_OS_ERROR_COREGETPROTECTIONHOOK_001 */ /* SBSW_OS_ERROR_HOOKCALLPROTECTIONHOOK_001 */

    /* #30 Verify protection reaction. */
    protectionReaction = Os_ErrVerifyProtectionReaction(protectionReaction, status);

    /* #40 Handle protection hook return value. */
    Os_ErrHandleProtectionReaction(protectionReaction, status);

    /* #50 Resume interrupts. */
    Os_IntResume(&interruptState);                                                                                      /* SBSW_OS_FC_POINTER2LOCAL */
  }
  else
  {
    Os_SystemShutdown(status);
  }
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_ErrProtectionException()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_ErrProtectionException
(
  Os_StatusType Error,
  Os_AddressOfConstType ExceptionInstructionAddress,
  boolean ExceptionCauserPrivileged
)
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;
  currentThread = Os_CoreGetThread();

  /* #10 If the user critical section is active, call the panic hook. */
  if (Os_CoreCriticalUserSectionIsActive(Os_ThreadGetCore(currentThread)) != 0u)                                        /* SBSW_OS_ERROR_THREADGETCORE_001 */ /* SBSW_OS_ERROR_CORECRITICALUSERSECTIONISACTIVE_001 */
  {
    Os_ErrKernelPanic();
  }
  /* #20 Otherwise, if the OS is potentially in an inconsistent state, call the panic hook. */
  else if(Os_ErrIsOsInternalException(ExceptionInstructionAddress, ExceptionCauserPrivileged) != 0u)                    /* SBSW_OS_ERROR_ISOSINTERNALEXCEPTION */
  {
    Os_ErrKernelPanic();
  }
  /* #30 Otherwise forward the error to the protection hook. */
  else
  {
    Os_ErrProtectionError(Error);
  }
}


/***********************************************************************************************************************
 *  Os_Api_GetDetailedError()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_Api_GetDetailedError(Os_ErrorInformationRefType ErrorRef)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

  currentThread = Os_CoreGetThread();

  /* #10 Check that the context is valid. */
  if(OS_UNLIKELY(Os_ThreadCheckCallContext(currentThread, OS_APICONTEXT_GETDETAILEDERROR) == OS_CHECK_FAILED))          /* SBSW_OS_ERROR_THREADCHECKCALLCONTEXT_001 */
  {
    status = OS_STATUS_CALLEVEL;
  }
  else
  {
    /* #20 Copy the data from the local core error object into the given object. */
    *ErrorRef = Os_CoreGetLastError(Os_ThreadGetCore(currentThread))->ErrorDetails;                                     /* SBSW_OS_ERROR_THREADGETCORE_001 */ /* SBSW_OS_ERROR_COREGETLASTERROR_001 */ /* SBSW_OS_PWA_PRECONDITION */

    status = OS_STATUS_OK;
  }

  /* #30 Return the status. */
  return status;
}


/***********************************************************************************************************************
 *  Os_Api_ErrorGetServiceId()
 **********************************************************************************************************************/
FUNC(OSServiceIdType, OS_CODE) Os_Api_ErrorGetServiceId
(
  void
)
{
  return Os_CoreGetLastError(Os_ThreadGetCore(Os_CoreGetThread()))->ErrorDetails.Service;                               /* SBSW_OS_ERROR_THREADGETCORE_001 */ /* SBSW_OS_ERROR_COREGETLASTERROR_001 */
}


/***********************************************************************************************************************
 *  Os_ErrKernelPanic()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(void, OS_CODE, OS_NORETURN, Os_ErrKernelPanic, (void))
{
  /* #10 Disable interrupts. */
  Os_IntDisable();

  /* #20 Call Panic Hook. */
  Os_HookCallPanicHook();

  /* #30 Freeze. */
  Os_Hal_CoreFreeze();
}


#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* module specific MISRA deviations:
 */

/* SBSW_JUSTIFICATION_BEGIN

\ID SBSW_OS_ERROR_THREADGETOWNERAPPLICATION_001
 \DESCRIPTION    Os_ThreadGetOwnerApplication() is called with the return value of Os_CoreThreadGetByContext().
 \COUNTERMEASURE \R [CM_OS_CORETHREADGETBYCONTEXT_R]

\ID SBSW_OS_ERROR_APPISKERNELAPP_001
 \DESCRIPTION    Os_AppIsKernelApp() is called with the return value of Os_ThreadGetCurrentApplication().
 \COUNTERMEASURE \N [CM_OS_THREADGETCURRENTAPPLICATION_N]

\ID SBSW_OS_ERROR_THREADISTASK_001
 \DESCRIPTION    Os_ThreadIsTask is called with the return value of Os_ThreadGetCurrentApplication.
 \COUNTERMEASURE \N [CM_OS_THREADGETCURRENTAPPLICATION_N]

\ID SBSW_OS_ERROR_THREADISTASK_002
 \DESCRIPTION    Os_ThreadIsTask is called with the return value of Os_CoreThreadGetByContext().
 \COUNTERMEASURE \R [CM_OS_CORETHREADGETBYCONTEXT_R]

\ID SBSW_OS_ERROR_THREADISISR_001
 \DESCRIPTION    Os_ThreadIsIsr is called with the return value of Os_ThreadGetCurrentApplication.
 \COUNTERMEASURE \N [CM_OS_THREADGETCURRENTAPPLICATION_N]

\ID SBSW_OS_ERROR_THREADISISR_002
 \DESCRIPTION    Os_ThreadIsIsr is called with the return value of Os_CoreThreadGetByContext.
 \COUNTERMEASURE \R [CM_OS_CORETHREADGETBYCONTEXT_R]

\ID SBSW_OS_ERROR_APPISRESTARTTASKAVAILABLE_001
 \DESCRIPTION    Os_AppIsRestartTaskAvailable() is called with the return value of Os_ThreadGetCurrentApplication().
 \COUNTERMEASURE \N [CM_OS_THREADGETCURRENTAPPLICATION_N]

\ID SBSW_OS_ERROR_ISRTHREAD2ISR_001
 \DESCRIPTION    Os_IsrThread2Isr is called with the return value of Os_CoreThreadGetByContext.
 \COUNTERMEASURE \R [CM_OS_CORETHREADGETBYCONTEXT_R]

\ID SBSW_OS_ERROR_ISRKILL_001
 \DESCRIPTION    Os_IsrKill() is called with the return value of Os_IsrThread2Isr().
 \COUNTERMEASURE \M [CM_OS_ISRTHREAD2ISR_01_02_M]
                 \M [CM_OS_ISRTHREAD2ISR_02_02_M]

\ID SBSW_OS_ERROR_APPKILL_001
 \DESCRIPTION    Os_AppKill() is called with the return value of Os_ThreadGetOwnerApplication().
 \COUNTERMEASURE \M [CM_OS_THREADGETOWNERAPPLICATION_M]

\ID SBSW_OS_ERROR_THREADGETCORE_001
 \DESCRIPTION    Os_ThreadGetCore is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_ERROR_THREADGETCORE_002
 \DESCRIPTION    Os_ThreadGetCore is called with the return value of Os_TrapCoreGetThread.
 \COUNTERMEASURE \N [CM_OS_TRAPCOREGETTHREAD_N]

\ID SBSW_OS_ERROR_THREADISTPISR_001
 \DESCRIPTION    Os_ThreadIsTpIsr is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_ERROR_COREGETLASTERROR_001
 \DESCRIPTION    Os_CoreGetLastError is called with the return value of Os_ThreadGetCore.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_ERROR_COREGETLASTERROR_002
 \DESCRIPTION    Write access to the return value Os_CoreGetLastError.
 \COUNTERMEASURE \M [CM_OS_COREGETLASTERROR_M]

\ID SBSW_OS_ERROR_OS_COREGETERRORHOOK_001
 \DESCRIPTION    Os_CoreGetErrorHook is called with the return value of Os_ThreadGetCore.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_ERROR_OS_HOOKCALLSTATUSHOOK_001
 \DESCRIPTION    Os_HookCallStatusHook is called with the return value of Os_CoreGetErrorHook.
 \COUNTERMEASURE \N [CM_OS_COREGETERRORHOOK_N]

\ID SBSW_OS_ERROR_OS_HOOKSTATUSHOOK_002
 \DESCRIPTION    Os_HookCallStatusHook is called with the return value of Os_AppGetErrorHook.
 \COUNTERMEASURE \N [CM_OS_APPGETERRORHOOK_N]

\ID SBSW_OS_ERROR_COREOSISSTARTED_001
 \DESCRIPTION    Os_CoreOsIsStarted is called with the return value of Os_ThreadGetCore.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_ERROR_APPGETERRORHOOK_001
 \DESCRIPTION    Os_AppGetErrorHook is called with the return value of Os_ThreadGetCurrentApplication.
 \COUNTERMEASURE \N [CM_OS_THREADGETCURRENTAPPLICATION_N]

\ID SBSW_OS_ERROR_COREGETPROTECTIONHOOK_001
 \DESCRIPTION    Os_CoreGetProtectionHook is called with the return value of Os_ThreadGetCore.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_ERROR_HOOKCALLPROTECTIONHOOK_001
 \DESCRIPTION    Os_HookCallProtectionHook is called with the return value of Os_CoreGetProtectionHook.
 \COUNTERMEASURE \N [CM_OS_COREGETPROTECTIONHOOK_N]

\ID SBSW_OS_ERROR_HOOKCALLSTATUSHOOK_001
 \DESCRIPTION    Os_HookCallStatusHook is called with the return value of Os_CoreGetErrorHook.
 \COUNTERMEASURE \N [CM_OS_COREGETERRORHOOK_N]

\ID SBSW_OS_ERROR_HOOKCALLSTATUSHOOK_002
 \DESCRIPTION    Os_HookCallStatusHook is called with the return value of Os_AppGetErrorHook.
 \COUNTERMEASURE \N [CM_OS_COREGETERRORHOOK_N]

\ID SBSW_OS_ERROR_COREGETERRORHOOK_001
 \DESCRIPTION    Os_CoreGetErrorHook is called with the return value of Os_ThreadGetCore.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_ERROR_ERRSETERRORDETAILS_001
 \DESCRIPTION    Os_ErrSetErrorDetails is called with the return value of Os_CoreGetLastError.
 \COUNTERMEASURE \M [CM_OS_COREGETLASTERROR_M]

\ID SBSW_OS_ERROR_THREADCHECKCALLCONTEXT_001
 \DESCRIPTION    Os_ThreadCheckCallContext is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_ERROR_ERROR_PARAMETER_001
 \DESCRIPTION    Array write access to a local Os_ErrorParamsType variable with enum index.
 \COUNTERMEASURE \N No measure required, as the array is indexed with an enum value. Design ensures, that enum value
                    is in range.

\ID SBSW_OS_ERROR_CORETHREADGETBYCONTEXT_001
 \DESCRIPTION    Os_CoreThreadGetByContext is called with the return value of Os_ThreadGetCore.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_ERROR_THREADGETCURRENTAPPLICATION_001
 \DESCRIPTION    Os_ThreadGetCurrentApplication is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_ERROR_THREADGETCURRENTAPPLICATION_002
 \DESCRIPTION    Os_ThreadGetCurrentApplication is called with the return value of Os_CoreThreadGetByContext.
 \COUNTERMEASURE \R [CM_OS_CORETHREADGETBYCONTEXT_R]

\ID SBSW_OS_ERROR_CORECRITICALUSERSECTIONISACTIVE_001
 \DESCRIPTION    Os_CoreCriticalUserSectionIsActive is called with the return value of Os_ThreadGetCore.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_ERROR_ISADDRESSINSIDESECTION_001
 \DESCRIPTION    Os_ErrIsAddressInsideSection is called with an entry of OsCfg_OsCode_Sections.
                 The used index is limited to OS_CFG_NUM_OSCODE_SECTIONS.
 \COUNTERMEASURE \M [CM_OS_ERROR_CODESECTIONS_M]

\ID SBSW_OS_ERROR_ISOSINTERNALEXCEPTION
 \DESCRIPTION    Os_ErrIsOsInternalException is called with a pointer parameter passed from the caller function.
 \COUNTERMEASURE \N The parameter is declared as pointer to const to prevent invalid write access.

SBSW_JUSTIFICATION_END */


/*
\CM CM_OS_ERRCHECKPOINTERISNOTNULL_N
      Function is able to handle NULL_PTR.

\CM CM_OS_ERRREPORT_N
      Passed value is not used for write access by OS.

\CM CM_OS_ERROR_CODESECTIONS_M
      Verify that
      each element in OsCfg_OsCode_Sections except the last is a non NULL_PTR and
      OsCfg_OsCode_Sections has a size equal to OS_CFG_NUM_OSCODE_SECTIONS + 1.

*/

/* START_COVERAGE_JUSTIFICATION

\ID COV_OS_ERRPARAMLIBFUNCT
   \ACCEPT XX
   \REASON This function is a library function. It is meant as an API to retrieve error information of the
           caller function within the ErrorHook. As the ErrorHook is currently not called from that function,
           the error retrieve function is useless and may become useful or removed in future versions. The
           risk of keeping the code now is low as it is unit tested and code inspected and only returns read
           values (no write instructions at all).

\ID COV_OS_ERRCODESECTIONCHECK
   \ACCEPT TX
   \REASON The feature Internal Exception Detection is always supported. Therefore the false branch is not covered.
           The risk of keeping the code is considered to be low as it is unit tested and reviewed.

END_COVERAGE_JUSTIFICATION */


/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Error.c
 **********************************************************************************************************************/
