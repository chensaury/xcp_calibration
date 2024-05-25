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
 * \addtogroup Os_XSignal
 * \{
 *
 * \file
 * \brief       Implementation of cross core signal services.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_XSIGNAL_H
# define OS_XSIGNAL_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_XSignalInt.h"
# include "Os_XSignal_Lcfg.h"


/* Os kernel module dependencies */
# include "Os_Core.h"
# include "Os_Counter.h"
# include "Os_Task.h"
# include "Os_Event.h"
# include "Os_Alarm.h"
# include "Os_ScheduleTable.h"
# include "Os_Isr.h"
# include "Os_Thread.h"
# include "Os_XSignalChannel.h"
# include "Os_Error.h"
# include "Os_Interrupt.h"
# include "Os_Common.h"
# include "Os_Hook.h"

/* Os hal dependencies */
# include "Os_Hal_Core.h"
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
 *  Os_XSigIsEnabled()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_XSigIsEnabled,
(
  void
))
{
  return (OS_CFG_XSIGNAL == STD_ON);                                                                                    /* PRQA S 4404 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_XSigUseAsynchronous()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_ALWAYS_INLINE, Os_XSigUseAsynchronous,
(
  void
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  return (OS_CFG_XSIG_USEASYNC == STD_ON);                                                                              /* PRQA S 4404 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_XSigSend()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE,                                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_ALWAYS_INLINE, Os_XSigSend,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  Os_XSigFunctionIdx FunctionIdx,
  P2CONST(Os_XSigParamsType, AUTOMATIC, TYPEDEF) Parameters
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_StatusType status;

  /* #10 Select the configured send function. */
  if(Os_XSigUseAsynchronous() != 0u)
  {
    status = Os_XSigSendAsync(RecvCore, SendThread, FunctionIdx, Parameters);                                           /* SBSW_OS_FC_PRECONDITION */
  }
  else
  {
    Os_XSigOutputParamsType OutParameters;
    status = Os_XSigSendSync(RecvCore, SendThread, FunctionIdx, Parameters, &OutParameters);                            /* SBSW_OS_XSIG_XSIGSEND_001 */
  }

  return status;
}


/***********************************************************************************************************************
 *  Os_XSigSend_ActivateTask()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE,                                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_ALWAYS_INLINE, Os_XSigSend_ActivateTask,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  TaskType TaskID
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_XSigParamsType parameters;

  /* #10 Initialize the call parameters. */
  parameters.ParameterData[0].ParamTaskType = TaskID;                                                                   /* SBSW_OS_PWA_LOCAL */

  /* #20 Send the request. */
  return Os_XSigSend(RecvCore, SendThread, XSigFunctionIdx_ActivateTask, &parameters);                                  /* SBSW_OS_XSIG_XSIGSEND_001 */
}


/***********************************************************************************************************************
 *  Os_XSigSend_ActivateTaskAsync()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE,                                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_ALWAYS_INLINE, Os_XSigSend_ActivateTaskAsync,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  TaskType TaskID
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_XSigParamsType parameters;

  /* #10 Initialize the call parameters. */
  parameters.ParameterData[0].ParamTaskType = TaskID;                                                                   /* SBSW_OS_PWA_LOCAL */

  /* #20 Send the request. */
  return Os_XSigSendAsync(RecvCore, SendThread, XSigFunctionIdx_ActivateTask, &parameters);                             /* SBSW_OS_XSIG_XSIGSEND_001 */
}


/***********************************************************************************************************************
 *  Os_XSigSend_GetTaskState()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE,                                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_ALWAYS_INLINE, Os_XSigSend_GetTaskState,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  TaskType TaskID,
  TaskStateRefType State
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_StatusType status;
  Os_XSigParamsType parameters;
  Os_XSigOutputParamsType outParameters;

  /* #10 Initialize the call parameters. */
  parameters.ParameterData[0].ParamTaskType = TaskID;                                                                   /* SBSW_OS_PWA_LOCAL */

  /* #20 Send the request. */
  status = Os_XSigSendSync(RecvCore, SendThread, XSigFunctionIdx_GetTaskState, &parameters, &outParameters);            /* SBSW_OS_XSIG_XSIGSEND_001 */
  (*State) = outParameters.ParameterData.ParamTaskStateType;                                                            /* SBSW_OS_PWA_PRECONDITION */

  return status;
}


/***********************************************************************************************************************
 *  Os_XSigSend_GetCounterValue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE,                                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_ALWAYS_INLINE, Os_XSigSend_GetCounterValue,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  CounterType CounterID,
  TickRefType Value
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_StatusType status;
  Os_XSigParamsType parameters;
  Os_XSigOutputParamsType outParameters;

  /* #10 Initialize the call parameters. */
  parameters.ParameterData[0].ParamCounterType = CounterID;                                                             /* SBSW_OS_PWA_LOCAL */

  /* #20 Send the request. */
  status = Os_XSigSendSync(RecvCore, SendThread, XSigFunctionIdx_GetCounterValue, &parameters, &outParameters);         /* SBSW_OS_XSIG_XSIGSEND_001 */
  (*Value) = outParameters.ParameterData.ParamTickType;                                                                 /* SBSW_OS_PWA_PRECONDITION */

  return status;
}


/***********************************************************************************************************************
 *  Os_XSigSend_SetEvent()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE,                                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_ALWAYS_INLINE, Os_XSigSend_SetEvent,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  TaskType TaskID,
  EventMaskType Mask
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_XSigParamsType parameters;

  /* #10 Initialize the call parameters. */
  parameters.ParameterData[0].ParamTaskType = TaskID;                                                                   /* SBSW_OS_PWA_LOCAL */
  parameters.ParameterData[1].ParamEventMaskType = Mask;                                                                /* SBSW_OS_PWA_LOCAL */

  /* #20 Send the request. */
  return Os_XSigSend(RecvCore, SendThread, XSigFunctionIdx_SetEvent, &parameters);                                      /* SBSW_OS_XSIG_XSIGSEND_001 */
}


/***********************************************************************************************************************
 *  Os_XSigSend_SetEventAsync()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE,                                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_ALWAYS_INLINE, Os_XSigSend_SetEventAsync,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  TaskType TaskID,
  EventMaskType Mask
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_XSigParamsType parameters;

  /* #10 Initialize the call parameters. */
  parameters.ParameterData[0].ParamTaskType = TaskID;                                                                   /* SBSW_OS_PWA_LOCAL */
  parameters.ParameterData[1].ParamEventMaskType = Mask;                                                                /* SBSW_OS_PWA_LOCAL */

  /* #20 Send the request. */
  return Os_XSigSendAsync(RecvCore, SendThread, XSigFunctionIdx_SetEvent, &parameters);                                 /* SBSW_OS_XSIG_XSIGSEND_001 */
}


/***********************************************************************************************************************
 *  Os_XSigSend_GetEvent()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE,                                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_ALWAYS_INLINE, Os_XSigSend_GetEvent,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  TaskType TaskID,
  EventMaskRefType Mask
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_StatusType status;
  Os_XSigParamsType parameters;
  Os_XSigOutputParamsType outParameters;

  /* #10 Initialize the call parameters. */
  parameters.ParameterData[0].ParamTaskType = TaskID;                                                                   /* SBSW_OS_PWA_LOCAL */

  /* #20 Send the request. */
  status = Os_XSigSendSync(RecvCore, SendThread, XSigFunctionIdx_GetEvent, &parameters, &outParameters);                /* SBSW_OS_XSIG_XSIGSEND_001 */

  (*Mask) = outParameters.ParameterData.ParamEventMaskType;                                                             /* SBSW_OS_PWA_PRECONDITION */

  return status;
}


/***********************************************************************************************************************
 *  Os_XSigSend_GetAlarm()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE,                                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_ALWAYS_INLINE, Os_XSigSend_GetAlarm,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  AlarmType AlarmID,
  TickRefType Tick
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_StatusType status;
  Os_XSigParamsType parameters;
  Os_XSigOutputParamsType outParameters;

  /* #10 Initialize the call parameters. */
  parameters.ParameterData[0].ParamAlarmType = AlarmID;                                                                 /* SBSW_OS_PWA_LOCAL */

  /* #20 Send the request synchronous. */
  status = Os_XSigSendSync(RecvCore, SendThread, XSigFunctionIdx_GetAlarm, &parameters, &outParameters);                /* SBSW_OS_XSIG_XSIGSEND_001 */

  /* #30 Get the result. */
  (*Tick) = outParameters.ParameterData.ParamTickType;                                                                  /* SBSW_OS_PWA_PRECONDITION */

  return status;
}


/***********************************************************************************************************************
 *  Os_XSigSend_SetRelAlarm()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE,                                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_ALWAYS_INLINE, Os_XSigSend_SetRelAlarm,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  AlarmType AlarmID,
  TickType Increment,
  TickType Cycle
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_XSigParamsType parameters;

  /* #10 Initialize the call parameters. */
  parameters.ParameterData[0].ParamAlarmType = AlarmID;                                                                 /* SBSW_OS_PWA_LOCAL */
  parameters.ParameterData[1].ParamTickType = Increment;                                                                /* SBSW_OS_PWA_LOCAL */
  parameters.ParameterData[2].ParamTickType = Cycle;                                                                    /* SBSW_OS_PWA_LOCAL */

  /* #20 Send the request. */
  return Os_XSigSend(RecvCore, SendThread, XSigFunctionIdx_SetRelAlarm, &parameters);                                   /* SBSW_OS_XSIG_XSIGSEND_001 */
}


/***********************************************************************************************************************
 *  Os_XSigSend_SetAbsAlarm()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE,                                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_ALWAYS_INLINE, Os_XSigSend_SetAbsAlarm,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  AlarmType AlarmID,
  TickType Start,
  TickType Cycle
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_XSigParamsType parameters;

  /* #10 Initialize the call parameters. */
  parameters.ParameterData[0].ParamAlarmType = AlarmID;                                                                 /* SBSW_OS_PWA_LOCAL */
  parameters.ParameterData[1].ParamTickType = Start;                                                                    /* SBSW_OS_PWA_LOCAL */
  parameters.ParameterData[2].ParamTickType = Cycle;                                                                    /* SBSW_OS_PWA_LOCAL */

  /* #20 Send the request. */
  return Os_XSigSend(RecvCore, SendThread, XSigFunctionIdx_SetAbsAlarm, &parameters);                                   /* SBSW_OS_XSIG_XSIGSEND_001 */
}


/***********************************************************************************************************************
 *  Os_XSigSend_CancelAlarm()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE,                                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_ALWAYS_INLINE, Os_XSigSend_CancelAlarm,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  AlarmType AlarmID
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_XSigParamsType parameters;

  /* #10 Initialize the call parameters. */
  parameters.ParameterData[0].ParamAlarmType = AlarmID;                                                                 /* SBSW_OS_PWA_LOCAL */

  /* #20 Send the request. */
  return Os_XSigSend(RecvCore, SendThread, XSigFunctionIdx_CancelAlarm, &parameters);                                   /* SBSW_OS_XSIG_XSIGSEND_001 */
}


/***********************************************************************************************************************
 *  Os_XSigSend_StartScheduleTableRel()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE,                                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_ALWAYS_INLINE, Os_XSigSend_StartScheduleTableRel,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  ScheduleTableType ScheduleTableID,
  TickType Offset
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_XSigParamsType parameters;

  /* #10 Initialize the call parameters. */
  parameters.ParameterData[0].ParamScheduleTableType = ScheduleTableID;                                                 /* SBSW_OS_PWA_LOCAL */
  parameters.ParameterData[1].ParamTickType = Offset;                                                                   /* SBSW_OS_PWA_LOCAL */

  /* #20 Send the request. */
  return Os_XSigSend(RecvCore, SendThread, XSigFunctionIdx_StartScheduleTableRel, &parameters);                         /* SBSW_OS_XSIG_XSIGSEND_001 */
}


/***********************************************************************************************************************
 *  Os_XSigSend_StartScheduleTableAbs()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE,                                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_ALWAYS_INLINE, Os_XSigSend_StartScheduleTableAbs,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  ScheduleTableType ScheduleTableID,
  TickType Start
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_XSigParamsType parameters;

  /* #10 Initialize the call parameters. */
  parameters.ParameterData[0].ParamScheduleTableType = ScheduleTableID;                                                 /* SBSW_OS_PWA_LOCAL */
  parameters.ParameterData[1].ParamTickType = Start;                                                                    /* SBSW_OS_PWA_LOCAL */

  /* #20 Send the request. */
  return Os_XSigSend(RecvCore, SendThread, XSigFunctionIdx_StartScheduleTableAbs, &parameters);                         /* SBSW_OS_XSIG_XSIGSEND_001 */
}


/***********************************************************************************************************************
 *  Os_XSigSend_StopScheduleTable()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE,                                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_ALWAYS_INLINE, Os_XSigSend_StopScheduleTable,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  ScheduleTableType ScheduleTableID
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_XSigParamsType parameters;

  /* #10 Initialize the call parameters. */
  parameters.ParameterData[0].ParamScheduleTableType = ScheduleTableID;                                                 /* SBSW_OS_PWA_LOCAL */

  /* #20 Send the request. */
  return Os_XSigSend(RecvCore, SendThread, XSigFunctionIdx_StopScheduleTable, &parameters);                             /* SBSW_OS_XSIG_XSIGSEND_001 */
}


/***********************************************************************************************************************
 *  Os_XSigSend_NextScheduleTable()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE,                                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_ALWAYS_INLINE, Os_XSigSend_NextScheduleTable,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  ScheduleTableType ScheduleTableID_From,
  ScheduleTableType ScheduleTableID_To
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_XSigParamsType parameters;

  /* #10 Initialize the call parameters. */
  parameters.ParameterData[0].ParamScheduleTableType = ScheduleTableID_From;                                            /* SBSW_OS_PWA_LOCAL */
  parameters.ParameterData[1].ParamScheduleTableType = ScheduleTableID_To;                                              /* SBSW_OS_PWA_LOCAL */

  /* #20 Send the request. */
  return Os_XSigSend(RecvCore, SendThread, XSigFunctionIdx_NextScheduleTable, &parameters);                             /* SBSW_OS_XSIG_XSIGSEND_001 */
}


/***********************************************************************************************************************
 *  Os_XSigSend_GetScheduleTableStatus()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE,                                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_ALWAYS_INLINE, Os_XSigSend_GetScheduleTableStatus,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  ScheduleTableType ScheduleTableID,
  ScheduleTableStatusRefType ScheduleStatus
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_StatusType status;
  Os_XSigParamsType parameters;
  Os_XSigOutputParamsType outParameters;

  /* #10 Initialize the call parameters. */
  parameters.ParameterData[0].ParamScheduleTableType = ScheduleTableID;                                                 /* SBSW_OS_PWA_LOCAL */

  /* #20 Send the request. */
  status = Os_XSigSendSync(RecvCore, SendThread, XSigFunctionIdx_GetScheduleTableStatus, &parameters, &outParameters);  /* SBSW_OS_XSIG_XSIGSEND_001 */
  (*ScheduleStatus) = outParameters.ParameterData.ParamScheduleTableStatusType;                                         /* SBSW_OS_PWA_PRECONDITION */

  return status;
}


/***********************************************************************************************************************
 *  Os_XSigSend_GetTaskStackUsage()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE,                                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_ALWAYS_INLINE, Os_XSigSend_GetTaskStackUsage,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  TaskType TaskID,
  P2VAR(uint32, AUTOMATIC, OS_CONST) Result
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_StatusType status;
  Os_XSigParamsType parameters;
  Os_XSigOutputParamsType outParameters;

  /* #10 Initialize the call parameters. */
  parameters.ParameterData[0].ParamTaskType = TaskID;                                                                   /* SBSW_OS_PWA_LOCAL */

  /* #20 Send the request. */
  status = Os_XSigSendSync(RecvCore, SendThread, XSigFunctionIdx_GetTaskStackUsage, &parameters, &outParameters);       /* SBSW_OS_XSIG_XSIGSEND_001 */
  (*Result) = outParameters.ParameterData.Paramuint32;                                                                  /* SBSW_OS_PWA_PRECONDITION */

  return status;
}


/***********************************************************************************************************************
 *  Os_XSigSend_GetISRStackUsage()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE,                                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_ALWAYS_INLINE, Os_XSigSend_GetISRStackUsage,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  ISRType IsrID,
  P2VAR(uint32, AUTOMATIC, OS_CONST) Result
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_StatusType status;
  Os_XSigParamsType parameters;
  Os_XSigOutputParamsType outParameters;

  /* #10 Initialize the call parameters. */
  parameters.ParameterData[0].ParamISRType = IsrID;                                                                     /* SBSW_OS_PWA_LOCAL */

  /* #20 Send the request. */
  status = Os_XSigSendSync(RecvCore, SendThread, XSigFunctionIdx_GetISRStackUsage, &parameters, &outParameters);        /* SBSW_OS_XSIG_XSIGSEND_001 */
  (*Result) = outParameters.ParameterData.Paramuint32;                                                                  /* SBSW_OS_PWA_PRECONDITION */

  return status;
}


/***********************************************************************************************************************
 *  Os_XSigSend_ControlIdle()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE,                                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_ALWAYS_INLINE, Os_XSigSend_ControlIdle,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  CoreIdType CoreID,
  IdleModeType IdleMode
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_StatusType status;
  Os_XSigParamsType parameters;

  /* #10 Initialize the call parameters. */
  parameters.ParameterData[0].ParamCoreIdType = CoreID;                                                                 /* SBSW_OS_PWA_LOCAL */
  parameters.ParameterData[1].ParamIdleModeType = IdleMode;                                                             /* SBSW_OS_PWA_LOCAL */

  /* #20 Send the request. */
  status = Os_XSigSend(RecvCore, SendThread, XSigFunctionIdx_ControlIdle, &parameters);                                 /* SBSW_OS_XSIG_XSIGSEND_001 */

  return status;
}


/***********************************************************************************************************************
 *  Os_XSigSend_GetKernelStackUsage()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE,                                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_ALWAYS_INLINE, Os_XSigSend_GetKernelStackUsage,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  CoreIdType CoreID,
  P2VAR(uint32, AUTOMATIC, OS_CONST) Result
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_StatusType status;
  Os_XSigParamsType parameters;
  Os_XSigOutputParamsType outParameters;

  /* #10 Initialize the call parameters. */
  parameters.ParameterData[0].ParamCoreIdType = CoreID;                                                                 /* SBSW_OS_PWA_LOCAL */

  /* #20 Send the request. */
  status = Os_XSigSendSync(RecvCore, SendThread, XSigFunctionIdx_GetKernelStackUsage, &parameters, &outParameters);     /* SBSW_OS_XSIG_XSIGSEND_001 */
  (*Result) = outParameters.ParameterData.Paramuint32;                                                                  /* SBSW_OS_PWA_PRECONDITION */

  return status;
}


/***********************************************************************************************************************
 *  Os_XSigSend_GetStartupHookStackUsage()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE,                                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_ALWAYS_INLINE, Os_XSigSend_GetStartupHookStackUsage,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  CoreIdType CoreID,
  P2VAR(uint32, AUTOMATIC, OS_CONST) Result
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_StatusType status;
  Os_XSigParamsType parameters;
  Os_XSigOutputParamsType outParameters;

  /* #10 Initialize the call parameters. */
  parameters.ParameterData[0].ParamCoreIdType = CoreID;                                                                 /* SBSW_OS_PWA_LOCAL */

  /* #20 Send the request. */
  status = Os_XSigSendSync(RecvCore, SendThread, XSigFunctionIdx_GetStartupHookStackUsage, &parameters, &outParameters);/* SBSW_OS_XSIG_XSIGSEND_001 */
  (*Result) = outParameters.ParameterData.Paramuint32;                                                                  /* SBSW_OS_PWA_PRECONDITION */

  return status;
}


/***********************************************************************************************************************
 *  Os_XSigSend_GetErrorHookStackUsage()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE,                                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_ALWAYS_INLINE, Os_XSigSend_GetErrorHookStackUsage,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  CoreIdType CoreID,
  P2VAR(uint32, AUTOMATIC, OS_CONST) Result
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_StatusType status;
  Os_XSigParamsType parameters;
  Os_XSigOutputParamsType outParameters;

  /* #10 Initialize the call parameters. */
  parameters.ParameterData[0].ParamCoreIdType = CoreID;                                                                 /* SBSW_OS_PWA_LOCAL */

  /* #20 Send the request. */
  status = Os_XSigSendSync(RecvCore, SendThread, XSigFunctionIdx_GetErrorHookStackUsage, &parameters, &outParameters);  /* SBSW_OS_XSIG_XSIGSEND_001 */
  (*Result) = outParameters.ParameterData.Paramuint32;                                                                  /* SBSW_OS_PWA_PRECONDITION */

  return status;
}


/***********************************************************************************************************************
 *  Os_XSigSend_GetShutdownHookStackUsage()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE,                                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_ALWAYS_INLINE, Os_XSigSend_GetShutdownHookStackUsage,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  CoreIdType CoreID,
  P2VAR(uint32, AUTOMATIC, OS_CONST) Result
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_StatusType status;
  Os_XSigParamsType parameters;
  Os_XSigOutputParamsType outParameters;

  /* #10 Initialize the call parameters. */
  parameters.ParameterData[0].ParamCoreIdType = CoreID;                                                                 /* SBSW_OS_PWA_LOCAL */

  /* #20 Send the request. */
  status = Os_XSigSendSync(                                                                                             /* SBSW_OS_XSIG_XSIGSEND_001 */
                RecvCore, SendThread, XSigFunctionIdx_GetShutdownHookStackUsage, &parameters, &outParameters);

  (*Result) = outParameters.ParameterData.Paramuint32;                                                                  /* SBSW_OS_PWA_PRECONDITION */

  return status;
}


/***********************************************************************************************************************
 *  Os_XSigSend_GetProtectionHookStackUsage()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE,                                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_ALWAYS_INLINE, Os_XSigSend_GetProtectionHookStackUsage,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  CoreIdType CoreID,
  P2VAR(uint32, AUTOMATIC, OS_CONST) Result
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_StatusType status;
  Os_XSigParamsType parameters;
  Os_XSigOutputParamsType outParameters;

  /* #10 Initialize the call parameters. */
  parameters.ParameterData[0].ParamCoreIdType = CoreID;                                                                 /* SBSW_OS_PWA_LOCAL */

  /* #20 Send the request. */
  status = Os_XSigSendSync( RecvCore, SendThread, XSigFunctionIdx_GetProtectionHookStackUsage, &parameters,             /* SBSW_OS_XSIG_XSIGSEND_001 */
                            &outParameters);

  (*Result) = outParameters.ParameterData.Paramuint32;                                                                  /* SBSW_OS_PWA_PRECONDITION */

  return status;
}


/***********************************************************************************************************************
 *  Os_XSigSend_TerminateApplication()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE,                                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_ALWAYS_INLINE, Os_XSigSend_TerminateApplication,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  ApplicationType Application,
  RestartType RestartOption,
  ApplicationType CurrentCallerApplicationId
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_StatusType status;
  Os_XSigParamsType parameters;
  Os_XSigOutputParamsType outParameters;

  /* #10 Initialize the call parameters. */
  parameters.ParameterData[0].ParamApplicationType = Application;                                                       /* SBSW_OS_PWA_LOCAL */
  parameters.ParameterData[1].ParamRestartType = RestartOption;                                                         /* SBSW_OS_PWA_LOCAL */
  parameters.ParameterData[2].ParamApplicationType = CurrentCallerApplicationId;                                        /* SBSW_OS_PWA_LOCAL */

  /* #20 Send the request. */
  status = Os_XSigSendSync(RecvCore, SendThread, XSigFunctionIdx_TerminateApplication, &parameters, &outParameters);    /* SBSW_OS_XSIG_XSIGSEND_001 */

  return status;
}


/***********************************************************************************************************************
 *  Os_XSigSend_GetApplicationState()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE,                                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_ALWAYS_INLINE, Os_XSigSend_GetApplicationState,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  ApplicationType Application,
  ApplicationStateRefType Value
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_StatusType status;
  Os_XSigParamsType parameters;
  Os_XSigOutputParamsType outParameters;

  /* #10 Initialize the call parameters. */
  parameters.ParameterData[0].ParamApplicationType = Application;                                                       /* SBSW_OS_PWA_LOCAL */

  /* #20 Send the request. */
  status = Os_XSigSendSync(RecvCore, SendThread, XSigFunctionIdx_GetApplicationState, &parameters, &outParameters);     /* SBSW_OS_XSIG_XSIGSEND_001 */

  (*Value) = outParameters.ParameterData.ParamApplicationStateType;                                                     /* SBSW_OS_PWA_PRECONDITION */

  return status;
}


/***********************************************************************************************************************
 *  Os_XSigSend_ShutdownAllCores()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE,                                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_ALWAYS_INLINE, Os_XSigSend_ShutdownAllCores,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  StatusType Error
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_StatusType status;
  Os_XSigParamsType parameters;

  /* #10 Initialize the call parameters. */
  parameters.ParameterData[0].ParamStatusType = Error;                                                                  /* SBSW_OS_PWA_LOCAL */

  /* #20 Send the request. */
  status = Os_XSigSendAsync(RecvCore, SendThread, XSigFunctionIdx_ShutdownAllCores, &parameters);                       /* SBSW_OS_XSIG_XSIGSEND_001 */

  return status;
}


/***********************************************************************************************************************
 *  Os_XSigSend_HookCallCallbackAsync()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE,                                  /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
Os_XSigSend_HookCallCallbackAsync,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  Os_HookIdType Id
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_XSigParamsType parameters;

  /* #10 Initialize the call parameters. */
  parameters.ParameterData[0].ParamHookIdType = Id;                                                                     /* SBSW_OS_PWA_LOCAL */

  /* #20 Send the request. */
  return Os_XSigSendAsync(RecvCore, SendThread, XSigFunctionIdx_HookCallCallback, &parameters);                         /* SBSW_OS_XSIG_XSIGSEND_001 */
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_XSIGNAL_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_XSignal.h
 **********************************************************************************************************************/
