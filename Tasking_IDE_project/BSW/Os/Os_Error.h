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
 * \addtogroup Os_Error
 *
 * \{
 *
 * \file
 * \brief       OS services for error management.
 * \details     --no details--
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_ERROR_H
# define OS_ERROR_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_ErrorInt.h"

/* Os module dependencies */
# include "Os_Common.h"
# include "Os_Interrupt.h"
# include "Os_Trap.h"
# include "Os_Hook.h"

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
 *  Os_ErrReportDisableAllInterrupts()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportDisableAllInterrupts,
(
  Os_StatusType Status
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsProtectionPropagationRequired(Status) != 0u))
  {
    /* #20 Report the error. */
    Os_ErrProtectionError(Status);
  }
}


/***********************************************************************************************************************
 *  Os_ErrReportEnableAllInterrupts()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportEnableAllInterrupts,
(
  Os_StatusType Status
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsProtectionPropagationRequired(Status) != 0u))
  {
    /* #20 Report the error. */
    Os_ErrProtectionError(Status);
  }
}


/***********************************************************************************************************************
 *  Os_ErrReportSuspendAllInterrupts()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportSuspendAllInterrupts,
(
  Os_StatusType Status
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsProtectionPropagationRequired(Status) != 0u))
  {
    /* #20 Report the error. */
    Os_ErrProtectionError(Status);
  }
}


/***********************************************************************************************************************
 *  Os_ErrReportResumeAllInterrupts()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportResumeAllInterrupts,
(
  Os_StatusType Status
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsProtectionPropagationRequired(Status) != 0u))
  {
    /* #20 Report the error. */
    Os_ErrProtectionError(Status);
  }
}


/***********************************************************************************************************************
 *  Os_ErrReportSuspendOSInterrupts()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportSuspendOSInterrupts,
(
  Os_StatusType Status
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsProtectionPropagationRequired(Status) != 0u))
  {
    /* #20 Report the error. */
    Os_ErrProtectionError(Status);
  }
}


/***********************************************************************************************************************
 *  Os_ErrReportResumeOSInterrupts()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportResumeOSInterrupts,
(
  Os_StatusType Status
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsProtectionPropagationRequired(Status) != 0u))
  {
    /* #20 Report the error. */
    Os_ErrProtectionError(Status);
  }
}


/***********************************************************************************************************************
 *  Os_ErrReportTimerIsr()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportTimerIsr,
(
  Os_StatusType Status
))                                                                                                                      /* COV_OS_HALPLATFORMPITUNSUPPORTED_XX */
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_TimerIsr, Status, &errorParameters);                                         /* SBSW_OS_FC_POINTER2LOCAL */
  }
}


/***********************************************************************************************************************
 *  Os_ErrReportIsrEpilogue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportIsrEpilogue,
(
  Os_StatusType Status
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_IsrWrapper, Status, &errorParameters);                                       /* SBSW_OS_FC_POINTER2LOCAL */
  }
}

/***********************************************************************************************************************
 *  Os_ErrReportCallTrustedFunction()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportCallTrustedFunction,
(
  Os_StatusType Status,
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))                                                            /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamTrustedFunctionIndexType = FunctionIndex;                      /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */
    errorParameters.Parameter[OS_ERRORPARAMINDEX_2].ParamTrustedFunctionParameterRefType = FunctionParams;              /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_CallTrustedFunction, Status, &errorParameters);                              /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportCallFastTrustedFunction()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_UNSUPPORTED93813 */
Os_ErrReportCallFastTrustedFunction,
(
  Os_StatusType Status,
  Os_FastTrustedFunctionIndexType FunctionIndex,
  Os_FastTrustedFunctionParameterRefType FunctionParams
))                                                                                                                      /* COV_OS_UNSUPPORTED93813 */
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))                                                            /* COV_OS_UNSUPPORTED93813 */
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamOs_FastTrustedFunctionIndexType = FunctionIndex;               /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */
    errorParameters.Parameter[OS_ERRORPARAMINDEX_2].ParamOs_FastTrustedFunctionParameterRefType = FunctionParams;       /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_CallFastTrustedFunction, Status, &errorParameters);                          /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportCallNonTrustedFunction()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportCallNonTrustedFunction,
(
  Os_StatusType Status,
  Os_NonTrustedFunctionIndexType FunctionIndex,
  Os_NonTrustedFunctionParameterRefType FunctionParams
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamOs_NonTrustedFunctionIndexType = FunctionIndex;                /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */
    errorParameters.Parameter[OS_ERRORPARAMINDEX_2].ParamOs_NonTrustedFunctionParameterRefType = FunctionParams;        /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_CallNonTrustedFunction, Status, &errorParameters);                           /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportStartScheduleTableRel()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportStartScheduleTableRel,
(
  Os_StatusType Status,
  ScheduleTableType ScheduleTableID,
  TickType Offset
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamScheduleTableType = ScheduleTableID;                           /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */
    errorParameters.Parameter[OS_ERRORPARAMINDEX_2].ParamTickType = Offset;                                             /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_StartScheduleTableRel, Status, &errorParameters);                            /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}



/***********************************************************************************************************************
 *  Os_ErrReportStartScheduleTableAbs()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportStartScheduleTableAbs,
(
  Os_StatusType Status,
  ScheduleTableType ScheduleTableID,
  TickType Start
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamScheduleTableType = ScheduleTableID;                           /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */
    errorParameters.Parameter[OS_ERRORPARAMINDEX_2].ParamTickType = Start;                                              /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_StartScheduleTableAbs, Status, &errorParameters);                            /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportStopScheduleTable()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportStopScheduleTable,
(
  Os_StatusType Status,
  ScheduleTableType ScheduleTableID
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamScheduleTableType = ScheduleTableID;                           /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_StopScheduleTable, Status, &errorParameters);                                /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportNextScheduleTable()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportNextScheduleTable,
(
  Os_StatusType Status,
  ScheduleTableType ScheduleTableID_From,
  ScheduleTableType ScheduleTableID_To
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamScheduleTableType = ScheduleTableID_From;                      /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */
    errorParameters.Parameter[OS_ERRORPARAMINDEX_2].ParamScheduleTableType = ScheduleTableID_To;                        /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_NextScheduleTable, Status, &errorParameters);                                /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportStartScheduleTableSynchron()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportStartScheduleTableSynchron,
(
  Os_StatusType Status,
  ScheduleTableType ScheduleTableID
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamScheduleTableType = ScheduleTableID;                           /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_StartScheduleTableSynchron, Status, &errorParameters);                       /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportSyncScheduleTable()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportSyncScheduleTable,
(
  Os_StatusType Status,
  ScheduleTableType ScheduleTableID,
  TickType Value
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamScheduleTableType = ScheduleTableID;                           /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */
    errorParameters.Parameter[OS_ERRORPARAMINDEX_2].ParamTickType = Value;                                              /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_SyncScheduleTable, Status, &errorParameters);                                /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportSetScheduleTableAsync()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportSetScheduleTableAsync,
(
  Os_StatusType Status,
  ScheduleTableType ScheduleTableID
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamScheduleTableType = ScheduleTableID;                           /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_SetScheduleTableAsync, Status, &errorParameters);                            /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportGetScheduleTableStatus()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportGetScheduleTableStatus,
(
  Os_StatusType Status,
  ScheduleTableType ScheduleTableID,
  ScheduleTableStatusRefType ScheduleStatus
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamScheduleTableType = ScheduleTableID;                           /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */
    errorParameters.Parameter[OS_ERRORPARAMINDEX_2].ParamScheduleTableStatusRefType = ScheduleStatus;                   /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_GetScheduleTableStatus, Status, &errorParameters);                           /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportSchTExPoActivateTask()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportSchTExPoActivateTask,
(
  Os_StatusType Status,
  TaskType TaskID
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamTaskType = TaskID;                                             /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_ScheduleTableActivateTask, Status, &errorParameters);                        /* SBSW_OS_FC_POINTER2LOCAL */
  }
}


/***********************************************************************************************************************
 *  Os_ErrReportSchTExPoSetEvent()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportSchTExPoSetEvent,
(
  Os_StatusType Status,
  TaskType TaskID,
  EventMaskType Mask
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamTaskType = TaskID;                                             /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */
    errorParameters.Parameter[OS_ERRORPARAMINDEX_2].ParamEventMaskType = Mask;                                          /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_ScheduleTableSetEvent, Status, &errorParameters);                            /* SBSW_OS_FC_POINTER2LOCAL */
  }
}


/***********************************************************************************************************************
 *  Os_ErrReportIncrementCounter()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportIncrementCounter,
(
  Os_StatusType Status,
  CounterType CounterID
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamCounterType = CounterID;                                       /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_IncrementCounter, Status, &errorParameters);                                 /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportGetCounterValue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportGetCounterValue,
(
  Os_StatusType Status,
  CounterType CounterID,
  TickRefType Value
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamCounterType = CounterID;                                       /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */
    errorParameters.Parameter[OS_ERRORPARAMINDEX_2].ParamTickRefType = Value;                                           /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_GetCounterValue, Status, &errorParameters);                                  /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportGetElapsedValue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportGetElapsedValue,
(
  Os_StatusType Status,
  CounterType CounterID,
  TickRefType Value,
  TickRefType ElapsedValue
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamCounterType = CounterID;                                       /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */
    errorParameters.Parameter[OS_ERRORPARAMINDEX_2].ParamTickRefType = Value;                                           /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */
    errorParameters.Parameter[OS_ERRORPARAMINDEX_3].ParamTickRefType = ElapsedValue;                                    /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_GetElapsedValue, Status, &errorParameters);                                  /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportTerminateApplication()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportTerminateApplication,
(
  Os_StatusType Status,
  ApplicationType Application,
  RestartType RestartOption
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamApplicationType = Application;                                 /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */
    errorParameters.Parameter[OS_ERRORPARAMINDEX_2].ParamRestartType = RestartOption;                                   /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_TerminateApplication, Status, &errorParameters);                             /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportAllowAccess()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportAllowAccess,
(
  Os_StatusType Status
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_AllowAccess, Status, &errorParameters);                                      /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportGetApplicationState()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportGetApplicationState,
(
  Os_StatusType Status,
  ApplicationType Application,
  ApplicationStateRefType Value
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamApplicationType = Application;                                 /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */
    errorParameters.Parameter[OS_ERRORPARAMINDEX_2].ParamApplicationStateRefType = Value;                               /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_GetApplicationState, Status, &errorParameters);                              /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportGetSpinlock()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportGetSpinlock,
(
  Os_StatusType Status,
  SpinlockIdType SpinlockId
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamSpinlockIdType = SpinlockId;                                   /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_GetSpinlock, Status, &errorParameters);                                      /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportReleaseSpinlock()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportReleaseSpinlock,
(
  Os_StatusType Status,
  SpinlockIdType SpinlockId
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamSpinlockIdType = SpinlockId;                                   /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_ReleaseSpinlock, Status, &errorParameters);                                  /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}



/***********************************************************************************************************************
 *  Os_ErrReportTryToGetSpinlock()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportTryToGetSpinlock,
(
  Os_StatusType Status,
  SpinlockIdType SpinlockId,
  TryToGetSpinlockType const *Success
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamSpinlockIdType = SpinlockId;                                   /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */
    errorParameters.Parameter[OS_ERRORPARAMINDEX_2].ParamTryToGetSpinlockConstRefType = Success;                        /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_TryToGetSpinlock, Status, &errorParameters);                                 /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportControlIdle()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportControlIdle,
(
  Os_StatusType Status,
  CoreIdType CoreID,
  IdleModeType IdleMode
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))                                                            /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamCoreIdType = CoreID;                                           /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */
    errorParameters.Parameter[OS_ERRORPARAMINDEX_2].ParamIdleModeType = IdleMode;                                       /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_ControlIdle, Status, &errorParameters);                                      /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportGetExceptionContext()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportGetExceptionContext,
(
  Os_StatusType Status,
  Os_ExceptionContextRefType Context
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamExceptionContextRefType = Context;                             /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_GetExceptionContext, Status, &errorParameters);                              /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportSetExceptionContext()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportSetExceptionContext,
(
  Os_StatusType Status,
  Os_ExceptionContextRefType Context
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamExceptionContextRefType = Context;                             /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_SetExceptionContext, Status, &errorParameters);                              /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportGetUnhandledIrq()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportGetUnhandledIrq,
(
  Os_StatusType Status,
  Os_InterruptSourceIdRefType InterruptSource
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))                                                            /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamInterruptSourceIdRefType = InterruptSource;                    /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_GetUnhandledIrq, Status, &errorParameters);                                  /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportGetUnhandledExc()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportGetUnhandledExc,
(
  Os_StatusType Status,
  Os_ExceptionSourceIdRefType ExceptionSource
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))                                                            /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamExceptionSourceIdRefType = ExceptionSource;                    /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_GetUnhandledExc, Status, &errorParameters);                                  /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportAlarmActionSetEvent
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportAlarmActionSetEvent,
(
  Os_StatusType Status,
  TaskType Task,
  EventMaskType Mask
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamTaskType = Task;                                               /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */
    errorParameters.Parameter[OS_ERRORPARAMINDEX_2].ParamEventMaskType = Mask;                                          /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_AlarmActionSetEvent, Status, &errorParameters);                              /* SBSW_OS_FC_POINTER2LOCAL */
  }
}


/***********************************************************************************************************************
 *  Os_ErrReportAlarmActionActivateTask
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportAlarmActionActivateTask,
(
  Os_StatusType Status,
  TaskType Task
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamTaskType = Task;                                               /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_AlarmActionActivateTask, Status, &errorParameters);                          /* SBSW_OS_FC_POINTER2LOCAL */
  }
}


/***********************************************************************************************************************
 *  Os_ErrReportAlarmActionIncrementCounter
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportAlarmActionIncrementCounter,
(
  Os_StatusType Status
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_AlarmActionIncrementCounter, Status, &errorParameters);                      /* SBSW_OS_FC_POINTER2LOCAL */
  }
}


/***********************************************************************************************************************
 *  Os_ErrReportGetTaskStackUsage()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportGetTaskStackUsage,
(
  Os_StatusType Status,
  TaskType TaskID
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamTaskType = TaskID;                                             /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_GetTaskStackUsage, Status, &errorParameters);                                /* SBSW_OS_FC_POINTER2LOCAL */
  }
}


/***********************************************************************************************************************
 *  Os_ErrReportGetISRStackUsage()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportGetISRStackUsage,
(
  Os_StatusType Status,
  ISRType IsrID
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamISRType = IsrID;                                               /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_GetISRStackUsage, Status, &errorParameters);                                 /* SBSW_OS_FC_POINTER2LOCAL */
  }
}


/***********************************************************************************************************************
 *  Os_ErrReportGetKernelStackUsage()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportGetKernelStackUsage,
(
  Os_StatusType Status,
  CoreIdType CoreID
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamCoreIdType = CoreID;                                           /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_GetKernelStackUsage, Status, &errorParameters);                              /* SBSW_OS_FC_POINTER2LOCAL */
  }
}


/***********************************************************************************************************************
 *  Os_ErrReportGetStartupHookStackUsage()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportGetStartupHookStackUsage,
(
  Os_StatusType Status,
  CoreIdType CoreID
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamCoreIdType = CoreID;                                           /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_GetStartupHookStackUsage, Status, &errorParameters);                         /* SBSW_OS_FC_POINTER2LOCAL */
  }
}


/***********************************************************************************************************************
 *  Os_ErrReportGetErrorHookStackUsage()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportGetErrorHookStackUsage,
(
  Os_StatusType Status,
  CoreIdType CoreID
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamCoreIdType = CoreID;                                           /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_GetErrorHookStackUsage, Status, &errorParameters);                           /* SBSW_OS_FC_POINTER2LOCAL */
  }
}


/***********************************************************************************************************************
 *  Os_ErrReportGetShutdownHookStackUsage()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportGetShutdownHookStackUsage,
(
  Os_StatusType Status,
  CoreIdType CoreID
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamCoreIdType = CoreID;                                           /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_GetShutdownHookStackUsage, Status, &errorParameters);                        /* SBSW_OS_FC_POINTER2LOCAL */
  }
}


/***********************************************************************************************************************
 *  Os_ErrReportGetProtectionHookStackUsage()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportGetProtectionHookStackUsage,
(
  Os_StatusType Status,
  CoreIdType CoreID
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamCoreIdType = CoreID;                                           /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_GetProtectionHookStackUsage, Status, &errorParameters);                      /* SBSW_OS_FC_POINTER2LOCAL */
  }
}


/***********************************************************************************************************************
 *  Os_ErrReportDisableInterruptSource()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportDisableInterruptSource,
(
  Os_StatusType Status,
  ISRType ISRID
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamISRType = ISRID;                                               /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_DisableInterruptSource, Status, &errorParameters);                           /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportEnableInterruptSource()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportEnableInterruptSource,
(
  Os_StatusType Status,
  ISRType ISRID,
  boolean ClearPending
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamISRType = ISRID;                                               /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */
    errorParameters.Parameter[OS_ERRORPARAMINDEX_2].Paramboolean = ClearPending;                                        /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_EnableInterruptSource, Status, &errorParameters);                            /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportInitialEnableInterruptSources()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportInitialEnableInterruptSources,
(
  Os_StatusType Status,
  boolean ClearPending
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].Paramboolean = ClearPending;                                        /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_InitialEnableInterruptSources, Status, &errorParameters);                    /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportClearPendingInterrupt()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportClearPendingInterrupt,
(
  Os_StatusType Status,
  ISRType ISRID
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamISRType = ISRID;                                               /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_ClearPendingInterrupt, Status, &errorParameters);                            /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportIsInterruptSourceEnabled()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportIsInterruptSourceEnabled,
(
  Os_StatusType Status,
  ISRType ISRID,
  P2VAR(boolean, AUTOMATIC, OS_VAR_NOINIT) IsEnabled
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamISRType = ISRID;                                               /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */
    errorParameters.Parameter[OS_ERRORPARAMINDEX_2].ParambooleanRefType = IsEnabled;                                    /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_IsInterruptSourceEnabled, Status, &errorParameters);                         /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportIsInterruptPending()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportIsInterruptPending,
(
  Os_StatusType Status,
  ISRType ISRID,
  P2VAR(boolean, AUTOMATIC, OS_VAR_NOINIT) IsPending
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamISRType = ISRID;                                               /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */
    errorParameters.Parameter[OS_ERRORPARAMINDEX_2].ParambooleanRefType = IsPending;                                    /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_IsInterruptPending, Status, &errorParameters);                               /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportBarrierSynchronize()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_UNSUPPORTED93797 */
Os_ErrReportBarrierSynchronize,
(
  Os_StatusType Status,
  Os_BarrierIdType BarrierID
))                                                                                                                      /* COV_OS_UNSUPPORTED93797 */
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))                                                            /* COV_OS_UNSUPPORTED93797 */
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamBarrierIdType = BarrierID;                                     /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_BarrierSynchronize, Status, &errorParameters);                               /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportActivateTask()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportActivateTask,
(
  Os_StatusType Status,
  TaskType TaskID
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamTaskType = TaskID;                                             /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_ActivateTask, Status, &errorParameters);                                     /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportTerminateTask()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportTerminateTask,
(
  Os_StatusType Status
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_TerminateTask, Status, &errorParameters);                                    /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportChainTask()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportChainTask,
(
  Os_StatusType Status,
  TaskType TaskID
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamTaskType = TaskID;                                             /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_ChainTask, Status, &errorParameters);                                        /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportGetTaskID()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportGetTaskID,
(
  Os_StatusType Status,
  TaskRefType TaskID
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamTaskRefType = TaskID;                                          /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_GetTaskID, Status, &errorParameters);                                        /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportGetTaskState()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportGetTaskState,
(
  Os_StatusType Status,
  TaskType TaskID,
  TaskStateRefType State
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamTaskType = TaskID;                                             /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */
    errorParameters.Parameter[OS_ERRORPARAMINDEX_2].ParamTaskStateRefType = State;                                      /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_GetTaskState, Status, &errorParameters);                                     /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportSchedule()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportSchedule,
(
  Os_StatusType Status
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_Schedule, Status, &errorParameters);                                         /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportSetEvent()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportSetEvent,
(
  Os_StatusType Status,
  TaskType TaskID,
  EventMaskType Mask
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamTaskType = TaskID;                                             /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */
    errorParameters.Parameter[OS_ERRORPARAMINDEX_2].ParamEventMaskType = Mask;                                          /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_SetEvent, Status, &errorParameters);                                         /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportClearEvent()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportClearEvent,
(
  Os_StatusType Status,
  EventMaskType Mask
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamEventMaskType = Mask;                                          /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_ClearEvent, Status, &errorParameters);                                       /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportGetEvent()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportGetEvent,
(
  Os_StatusType Status,
  TaskType TaskID,
  EventMaskRefType Mask
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamTaskType = TaskID;                                             /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */
    errorParameters.Parameter[OS_ERRORPARAMINDEX_2].ParamEventMaskRefType = Mask;                                       /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_GetEvent, Status, &errorParameters);                                         /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportWaitEvent()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportWaitEvent,
(
  Os_StatusType Status,
  EventMaskType Mask
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamEventMaskType = Mask;                                          /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_WaitEvent, Status, &errorParameters);                                        /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportGetAlarmBase()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportGetAlarmBase,
(
  Os_StatusType Status,
  AlarmType AlarmID,
  AlarmBaseRefType Info
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamAlarmType = AlarmID;                                           /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */
    errorParameters.Parameter[OS_ERRORPARAMINDEX_2].ParamAlarmBaseRefType = Info;                                       /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_GetAlarmBase, Status, &errorParameters);                                     /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportGetAlarm()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportGetAlarm,
(
  Os_StatusType Status,
  AlarmType AlarmID,
  TickRefType Tick
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamAlarmType = AlarmID;                                           /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */
    errorParameters.Parameter[OS_ERRORPARAMINDEX_2].ParamTickRefType = Tick;                                            /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_GetAlarm, Status, &errorParameters);                                         /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportSetRelAlarm()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportSetRelAlarm,
(
  Os_StatusType Status,
  AlarmType AlarmID,
  TickType Increment,
  TickType Cycle
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamAlarmType = AlarmID;                                           /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */
    errorParameters.Parameter[OS_ERRORPARAMINDEX_2].ParamTickType = Increment;                                          /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */
    errorParameters.Parameter[OS_ERRORPARAMINDEX_3].ParamTickType = Cycle;                                              /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_SetRelAlarm, Status, &errorParameters);                                      /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportSetAbsAlarm()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportSetAbsAlarm,
(
  Os_StatusType Status,
  AlarmType AlarmID,
  TickType Start,
  TickType Cycle
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamAlarmType = AlarmID;                                           /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */
    errorParameters.Parameter[OS_ERRORPARAMINDEX_2].ParamTickType = Start;                                              /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */
    errorParameters.Parameter[OS_ERRORPARAMINDEX_3].ParamTickType = Cycle;                                              /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_SetAbsAlarm, Status, &errorParameters);                                      /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportCancelAlarm()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportCancelAlarm,
(
  Os_StatusType Status,
  AlarmType AlarmID
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamAlarmType = AlarmID;                                           /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_CancelAlarm, Status, &errorParameters);                                      /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportGetResource()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportGetResource,
(
  Os_StatusType Status,
  ResourceType ResID
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamResourceType = ResID;                                          /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_GetResource, Status, &errorParameters);                                      /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrReportReleaseResource()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrReportReleaseResource,
(
  Os_StatusType Status,
  ResourceType ResID
))
{
  /* #10 If there was an error: */
  if(OS_UNLIKELY(Os_ErrIsPropagationRequired(Status) != 0u))
  {
    /* #20 Create error parameter object. */
    Os_ErrorParamsType errorParameters;
    errorParameters.Parameter[OS_ERRORPARAMINDEX_1].ParamResourceType = ResID;                                          /* SBSW_OS_ERROR_ERROR_PARAMETER_001 */

    /* #30 Report the error and get the error return code. */
    Os_TrapErrApplicationError(OSServiceId_ReleaseResource, Status, &errorParameters);                                  /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #40 Return the error code. */
  return Os_ErrOsStatus2UserStatus(Status);
}


/***********************************************************************************************************************
 *  Os_ErrIsValueLo()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_ErrIsValueLo,
(
  uint32 Id,
  uint32 Compare
))
{
  return ((Os_StdReturnType)(Id < Compare));                                                                            /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_ErrExtendedCheck()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE,  Os_ErrExtendedCheck,
(
  Os_StdReturnType Value
))
{
  /* If extended status is disabled, the check always succeeds.
   * Otherwise Value indicates whether the check failed or not. */
  return ((!Os_ErrIsExtendedStatusEnabled()) || (Value));                                                               /* PRQA S 4404, 4558 */  /* MD_Os_C90BooleanCompatibility, MD_Os_Rule10.1_4558 */
}


/***********************************************************************************************************************
 *  Os_ErrSetOkInStdStatus()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE,                                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE,  Os_ErrSetOkInStdStatus,
(
  Os_StatusType Value
))
{
  Os_StatusType result;
  if(Os_ErrIsExtendedStatusEnabled() != 0u)
  {
    result = Value;
  }
  else
  {
    result = OS_STATUS_OK;
  }
  return result;
}


/***********************************************************************************************************************
 *  Os_ErrServiceProtectionCheck()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_ErrServiceProtectionCheck,
(
  Os_StdReturnType Value
))
{
  /* If service protection is disabled, the check always succeeds.
   * Otherwise Value indicates whether the check failed or not. */
  return ((!Os_ErrIsServiceProtectionEnabled()) || (Value));                                                            /* PRQA S 4404, 4558 */  /* MD_Os_C90BooleanCompatibility, MD_Os_Rule10.1_4558 */
}


/***********************************************************************************************************************
 *  Os_Assert()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Assert,
(
  Os_StdReturnType Condition
))
{
  if(Os_ErrIsAssertEnabled() != 0u)                                                                                     /* COV_OS_INVSTATE */
  {
    if (OS_UNLIKELY(!(Condition)))                                                                                      /* PRQA S 4558 */ /* MD_Os_Rule10.1_4558 */
    {
      Os_ErrKernelPanic();
    }
  }
}


/***********************************************************************************************************************
 *  Os_ErrCheckPointerIsNotNull()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_ErrCheckPointerIsNotNull,
(
  P2CONST(volatile void, AUTOMATIC, OS_APPL_DATA) Pointer
))
{
  return Os_ErrExtendedCheck((Os_StdReturnType)(Pointer != NULL_PTR));                                                  /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_ErrCheckIsBoolean()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_ErrCheckIsBoolean,
(
  boolean Value
))
{
  return Os_ErrExtendedCheck((Os_StdReturnType)((Value == TRUE) || (Value == FALSE)));                                  /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_ErrOsStatus2UserStatus()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,                                     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_ErrOsStatus2UserStatus,
(
  Os_StatusType OsStatus
))
{
  return (StatusType)OsStatus;
}


/***********************************************************************************************************************
 *  Os_ErrIsPropagationRequired()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_ErrIsPropagationRequired,
(
  Os_StatusType OsStatus
))
{
  /* #10 Return whether error hooks are configured and the given status is an error value. */
  return (Os_StdReturnType)((Os_HookIsErrorHookEnabled()) && (OsStatus != OS_STATUS_OK));                               /* PRQA S 4304, 4558 */ /* MD_Os_C90BooleanCompatibility, MD_Os_Rule10.1_4558 */
}


/***********************************************************************************************************************
 *  Os_ErrIsProtectionPropagationRequired()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_ErrIsProtectionPropagationRequired,
(
  Os_StatusType OsStatus
))
{
  /* #10 Return whether service protection is enabled and the given status is an error value. */
  return (Os_StdReturnType)((Os_ErrIsServiceProtectionEnabled()) && (OsStatus != OS_STATUS_OK));                        /* PRQA S 4304, 4558 */ /* MD_Os_C90BooleanCompatibility, MD_Os_Rule10.1_4558 */
}


/***********************************************************************************************************************
 *  Os_ErrIsKillingEnabled()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_ErrIsKillingEnabled, (void))
{
  return (OS_CFG_KILLING == STD_ON);                                                                                    /* PRQA S 4404 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_ErrIsAssertEnabled()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_ErrIsAssertEnabled, (void))
{
  return (OS_CFG_ASSERTIONS == STD_ON);                                                                                 /* PRQA S 4404 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_ErrIsServiceProtectionEnabled()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_ErrIsServiceProtectionEnabled, (void))
{
  return (OS_CFG_SERVICE_PROTECTION == STD_ON);                                                                         /* PRQA S 4404 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_ErrIsExtendedStatusEnabled()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_ErrIsExtendedStatusEnabled, (void))
{
  return (OS_CFG_EXTENDED_STATUS == STD_ON);                                                                            /* PRQA S 4404 */ /* MD_Os_C90BooleanCompatibility */
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_ERROR_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_Error.h
 **********************************************************************************************************************/
