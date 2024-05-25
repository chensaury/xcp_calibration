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
 *  \defgroup    Os_Error Error
 *  \brief       Error reporting primitives.
 *  \details
 *  This module provides error reporting primitives, used by other modules. It also provides OS APIs to get
 *  detailed information about the last error.
 *
 *
 *  Error Checking Levels
 *  ---------------------
 *
 *  Level                     | Description
 *  ------------------------- | ----------------------------------
 *  Standard Status           | For use in production phase. The OS does not check for invalid service calls or invalid
 *                            | parameters.
 *  Extended Status           | For use in test phase. The OS performs error checks to validate service calls and
 *                            | parameters.
 *  Service Protection        | Service protection prevents OS-Applications from corrupting the OS. It is an extension
 *                            | to Extended Status and requires additional checks. AUTOSAR requires service protection
 *                            | to be active in SC3 and SC4. Service protection checks are, e.g. illegal address,
 *                            | null-pointer, call level
 *  Assertion                 | Assertions perform OS internal plausibility checks which shall help to find invalid
 *                            | OS states during OS development and test. Error behavior for assertions is freeze.
 *                            | Assertions should not be enabled in production phase.
 *
 *
 *  Error Types
 *  -----------
 *
 *  MICROSAR OS differs between the following error types:
 *
 *    - Application Errors
 *    - Protection Errors
 *    - Kernel Panic
 *
 *  ### Application Error ###
 *  In this error type the OS could not execute the requested service correctly, but assumes the correctness of its
 *  internal data. Application errors are typically a result of wrong API usage. E.g., passing invalid object IDs,
 *  out of range values, etc. The centralized error treatment (Error Hook) is called. Additionally the OS returns the
 *  error by the status information for decentralized error treatment.
 *
 *  ![Application Error](Error_ApplicationError.png)
 *
 *
 *  ### Protection Error ###
 *  Protection errors are systematic errors in the software of an OS-Application. E.g. Memory Access Violation,
 *  Timing Fault, Hardware Exception, Illegal Service.
 *
 *  ![Protection Error - Reaction Terminate Task/ISR](Error_ProtectionError_TerminateTaskIsr.png)
 *
 *  ![Protection Error - Reaction Terminate Application](Error_ProtectionError_TerminateApplication.png)
 *
 *  ![Protection Error - Reaction Shutdown](Error_ProtectionError_Shutdown.png)
 *
 *  \see   \ref Os_Thread
 *  \see   \ref Os_Application
 *  \see   \ref Os_Core
 *
 *
 *  ### Kernel Panic ###
 *  Kernel freeze is triggered, if OS can no longer assume correctness of its internal data and regular shutdown
 *  cannot be reached. E.g.:
 *
 *  - Protection Hook or Shutdown Hook triggers a Memory Protection Violation
 *  - Protection Hook or Shutdown Hook generates Application Errors.
 *
 *  In case of kernel Panic, the OS disables all interrupts and enters an endless loop.
 *
 *
 *
 *  OSError_x1_x2()
 *  --------------------------------------------------------------------------------------------------------------------
 *
 *  No ErrorHook calls therefore no OSError_* interface for:
 *
 *   - CheckISRMemoryAccess()
 *   - CheckTaskMemoryAccess()
 *   - CheckObjectAccess()
 *   - CheckObjectOwnership()
 *   - StartCore()
 *   - StartNonAutosarCore()
 *   - ShutdownOS()
 *   - ShutdownAllCores()
 *   - Os_GetUnhandledIrq()
 *   - Os_GetUnhandledExc()
 *   - Os_GetTaskStackUsage()
 *   - Os_GetISRStackUsage()
 *   - Os_GetStartupHookStackUsage()
 *   - Os_GetErrorHookStackUsage()
 *   - Os_GetShutdownHookStackUsage()
 *   - Os_GetProtectionHookStackUsage()
 *   - Os_ReadPeripheral8()
 *   - Os_ReadPeripheral16()
 *   - Os_ReadPeripheral32()
 *   - Os_WritePeripheral8()
 *   - Os_WritePeripheral16()
 *   - Os_WritePeripheral32()
 *   - Os_ModifyPeripheral8()
 *   - Os_ModifyPeripheral16()
 *   - Os_ModifyPeripheral32()
 *   - Os_GetDetailedError()
 *
 *
 *
 *  \trace        SPEC-63567
 *  \{
 *
 *  \file
 *  \brief       Defines internal error handling logic.
 * \details     --no details--
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/


#ifndef OS_ERRORINT_H
# define OS_ERRORINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Error_Types.h"
# include "Os_Error_Cfg.h"

/* Os module dependencies */
# include "OsInt.h"
# include "Os_CommonInt.h"
# include "Os_Hook_Cfg.h"

/* Os Hal dependencies */
# include "Os_Hal_CompilerInt.h"



/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/*! Data type to store API parameters in case of an application error. */
struct Os_ErrorParamsType_Tag
{
  Os_ParamType Parameter[OS_ERRORPARAMINDEX_COUNT];
};

/*! Holds the error description. */
struct Os_ErrorType_Tag
{
  /*! Error information, which can be fetched by Os_GetDetailedError(). */
  Os_ErrorInformationType ErrorDetails;

  /*! The call parameters of the service. */
  Os_ErrorParamsType Parameters;
};


/*! Holds the static labels of a linker section. */
struct Os_LinkerSectionLabelsType_Tag
{
  /*! Start label of the linker section. */
  Os_AddressOfConstType StartLabel;

  /*! End label of the linker section. */
  Os_AddressOfConstType EndLabel;
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
 *  Os_ErrInit()
 **********************************************************************************************************************/
/*! \brief        Initialize the given error object (Init-Step2).
 *  \details      Error parameters are not initialized. This is done on error occurrence.
 *
 *  \param[in]    Error            The error to initialize. Parameter must not be NULL.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_ErrInit
(
  P2VAR(Os_ErrorType, AUTOMATIC, OS_VAR_NOINIT) Error
);


/***********************************************************************************************************************
 *  Os_ErrReportDisableAllInterrupts()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportDisableAllInterrupts,
(
  Os_StatusType Status
));


/***********************************************************************************************************************
 *  Os_ErrReportEnableAllInterrupts()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportEnableAllInterrupts,
(
  Os_StatusType Status
));


/***********************************************************************************************************************
 *  Os_ErrReportSuspendAllInterrupts()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportSuspendAllInterrupts,
(
  Os_StatusType Status
));


/***********************************************************************************************************************
 *  Os_ErrReportResumeAllInterrupts()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportResumeAllInterrupts,
(
  Os_StatusType Status
));


/***********************************************************************************************************************
 *  Os_ErrReportSuspendOSInterrupts()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportSuspendOSInterrupts,
(
  Os_StatusType Status
));


/***********************************************************************************************************************
 *  Os_ErrReportResumeOSInterrupts()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportResumeOSInterrupts,
(
  Os_StatusType Status
));


/***********************************************************************************************************************
 *  Os_ErrReportIsrEpilogue()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportIsrEpilogue,
(
  Os_StatusType Status
));


/***********************************************************************************************************************
 *  Os_ErrReportTimerIsr()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportTimerIsr,
(
  Os_StatusType Status
));


/***********************************************************************************************************************
 *  Os_ErrReportCallTrustedFunction()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    FunctionIndex     The first API parameter.
 *  \param[in]    FunctionParams    The second API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref CallTrustedFunction().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportCallTrustedFunction,
(
  Os_StatusType Status,
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams
));


/***********************************************************************************************************************
 *  Os_ErrReportCallFastTrustedFunction()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    FunctionIndex     The first API parameter.
 *  \param[in]    FunctionParams    The second API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref Os_CallFastTrustedFunction().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportCallFastTrustedFunction,
(
  Os_StatusType Status,
  Os_FastTrustedFunctionIndexType FunctionIndex,
  Os_FastTrustedFunctionParameterRefType FunctionParams
));


/***********************************************************************************************************************
 *  Os_ErrReportCallNonTrustedFunction()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    FunctionIndex     The first API parameter.
 *  \param[in]    FunctionParams    The second API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref Os_CallNonTrustedFunction().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportCallNonTrustedFunction,
(
  Os_StatusType Status,
  Os_NonTrustedFunctionIndexType FunctionIndex,
  Os_NonTrustedFunctionParameterRefType FunctionParams
));


/***********************************************************************************************************************
 *  Os_ErrReportStartScheduleTableRel()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    ScheduleTableID   The first API parameter.
 *  \param[in]    Offset            The second API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref StartScheduleTableRel().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportStartScheduleTableRel,
(
  Os_StatusType Status,
  ScheduleTableType ScheduleTableID,
  TickType Offset
));


/***********************************************************************************************************************
 *  Os_ErrReportStartScheduleTableAbs()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    ScheduleTableID   The first API parameter.
 *  \param[in]    Start             The second API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref StartScheduleTableAbs().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportStartScheduleTableAbs,
(
  Os_StatusType Status,
  ScheduleTableType ScheduleTableID,
  TickType Start
));


/***********************************************************************************************************************
 *  Os_ErrReportStopScheduleTable()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    ScheduleTableID   The first API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref StopScheduleTable().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportStopScheduleTable,
(
  Os_StatusType Status,
  ScheduleTableType ScheduleTableID
));


/***********************************************************************************************************************
 *  Os_ErrReportNextScheduleTable()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status                  The result of the API execution.
 *  \param[in]    ScheduleTableID_From    The first API parameter.
 *  \param[in]    ScheduleTableID_To      The second API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref NextScheduleTable().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportNextScheduleTable,
(
  Os_StatusType Status,
  ScheduleTableType ScheduleTableID_From,
  ScheduleTableType ScheduleTableID_To
));


/***********************************************************************************************************************
 *  Os_ErrReportStartScheduleTableSynchron()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    ScheduleTableID   The first API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref StartScheduleTableSynchron().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportStartScheduleTableSynchron,
(
  Os_StatusType Status,
  ScheduleTableType ScheduleTableID
));


/***********************************************************************************************************************
 *  Os_ErrReportSyncScheduleTable()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    ScheduleTableID   The first API parameter.
 *  \param[in]    Value             The second API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref SyncScheduleTable().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportSyncScheduleTable,
(
  Os_StatusType Status,
  ScheduleTableType ScheduleTableID,
  TickType Value
));


/***********************************************************************************************************************
 *  Os_ErrReportSetScheduleTableAsync()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    ScheduleTableID   The first API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref SetScheduleTableAsync().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportSetScheduleTableAsync,
(
  Os_StatusType Status,
  ScheduleTableType ScheduleTableID
));


/***********************************************************************************************************************
 *  Os_ErrReportGetScheduleTableStatus()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    ScheduleTableID   The first API parameter.
 *  \param[in]    ScheduleStatus    The second API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref GetScheduleTableStatus().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportGetScheduleTableStatus,
(
  Os_StatusType Status,
  ScheduleTableType ScheduleTableID,
  ScheduleTableStatusRefType ScheduleStatus
));


/***********************************************************************************************************************
 *  Os_ErrReportSchTExPoActivateTask()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    TaskID            The first API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportSchTExPoActivateTask,
(
  Os_StatusType Status,
  TaskType TaskID
));


/***********************************************************************************************************************
 *  Os_ErrReportSchTExPoSetEvent()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    TaskID            The first API parameter.
 *  \param[in]    Mask              The second API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportSchTExPoSetEvent,
(
  Os_StatusType Status,
  TaskType TaskID,
  EventMaskType Mask
));


/***********************************************************************************************************************
 *  Os_ErrReportIncrementCounter()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    CounterID         The first API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref IncrementCounter().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportIncrementCounter,
(
  Os_StatusType Status,
  CounterType CounterID
));


/***********************************************************************************************************************
 *  Os_ErrReportGetCounterValue()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    CounterID         The first API parameter.
 *  \param[in]    Value             The second API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref GetCounterValue().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportGetCounterValue,
(
  Os_StatusType Status,
  CounterType CounterID,
  TickRefType Value
));


/***********************************************************************************************************************
 *  Os_ErrReportGetElapsedValue()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    CounterID         The first API parameter.
 *  \param[in]    Value             The second API parameter.
 *  \param[in]    ElapsedValue      The third API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref GetElapsedValue().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportGetElapsedValue,
(
  Os_StatusType Status,
  CounterType CounterID,
  TickRefType Value,
  TickRefType ElapsedValue
));


/***********************************************************************************************************************
 *  Os_ErrReportTerminateApplication()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    Application       The first API parameter.
 *  \param[in]    RestartOption     The second API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref TerminateApplication().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportTerminateApplication,
(
  Os_StatusType Status,
  ApplicationType Application,
  RestartType RestartOption
));


/***********************************************************************************************************************
 *  Os_ErrReportAllowAccess()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref AllowAccess().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportAllowAccess,
(
  Os_StatusType Status
));


/***********************************************************************************************************************
 *  Os_ErrReportGetApplicationState()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    Application       The first API parameter.
 *  \param[in]    Value             The second API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref GetApplicationState().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportGetApplicationState,
(
  Os_StatusType Status,
  ApplicationType Application,
  ApplicationStateRefType Value
));


/***********************************************************************************************************************
 *  Os_ErrReportGetSpinlock()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    SpinlockId        The first API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref GetSpinlock().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportGetSpinlock,
(
  Os_StatusType Status,
  SpinlockIdType SpinlockId
));


/***********************************************************************************************************************
 *  Os_ErrReportReleaseSpinlock()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    SpinlockId        The first API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref ReleaseSpinlock().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportReleaseSpinlock,
(
  Os_StatusType Status,
  SpinlockIdType SpinlockId
));


/***********************************************************************************************************************
 *  Os_ErrReportTryToGetSpinlock()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    SpinlockId        The first API parameter.
 *  \param[in]    Success           The second API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref TryToGetSpinlock().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportTryToGetSpinlock,
(
  Os_StatusType Status,
  SpinlockIdType SpinlockId,
  TryToGetSpinlockType const* Success
));


/***********************************************************************************************************************
 *  Os_ErrReportControlIdle()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    CoreID            The first API parameter.
 *  \param[in]    IdleMode          The second API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref ControlIdle().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportControlIdle,
(
  Os_StatusType Status,
  CoreIdType CoreID,
  IdleModeType IdleMode
));


/***********************************************************************************************************************
 *  Os_ErrReportGetExceptionContext()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    Context           The first API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref GetExceptionContext().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportGetExceptionContext,
(
  Os_StatusType Status,
  Os_ExceptionContextRefType Context
));


/***********************************************************************************************************************
 *  Os_ErrReportSetExceptionContext()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    Context           The first API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref SetExceptionContext().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportSetExceptionContext,
(
  Os_StatusType Status,
  Os_ExceptionContextRefType Context
));


/***********************************************************************************************************************
 *  Os_ErrReportGetUnhandledIrq()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    InterruptSource   The first API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref Os_GetUnhandledIrq().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportGetUnhandledIrq,
(
  Os_StatusType Status,
  Os_InterruptSourceIdRefType InterruptSource
));


/***********************************************************************************************************************
 *  Os_ErrReportGetUnhandledExc()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    ExceptionSource   The first API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref Os_GetUnhandledExc().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportGetUnhandledExc,
(
  Os_StatusType Status,
  Os_ExceptionSourceIdRefType ExceptionSource
));


/***********************************************************************************************************************
 *  Os_ErrReportAlarmActionSetEvent()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    Task              The first API parameter.
 *  \param[in]    Mask              The second API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportAlarmActionSetEvent,
(
  Os_StatusType Status,
  TaskType Task,
  EventMaskType Mask
));


/***********************************************************************************************************************
 *  Os_ErrReportAlarmActionActivateTask()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    Task              The first API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportAlarmActionActivateTask,
(
  Os_StatusType Status,
  TaskType Task
));


/***********************************************************************************************************************
 *  Os_ErrReportAlarmActionIncrementCounter()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportAlarmActionIncrementCounter,
(
  Os_StatusType Status
));


/***********************************************************************************************************************
 *  Os_ErrReportGetTaskStackUsage()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    TaskID            The first API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportGetTaskStackUsage,
(
  Os_StatusType Status,
  TaskType TaskID
));


/***********************************************************************************************************************
 *  Os_ErrReportGetISRStackUsage()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    IsrID             The first API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_ErrReportGetISRStackUsage,
(
  Os_StatusType Status,
  ISRType IsrID
));


/***********************************************************************************************************************
 *  Os_ErrReportGetKernelStackUsage()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    CoreID            The first API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportGetKernelStackUsage,
(
  Os_StatusType Status,
  CoreIdType CoreID
));


/***********************************************************************************************************************
 *  Os_ErrReportGetStartupHookStackUsage()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    CoreID            The first API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportGetStartupHookStackUsage,
(
  Os_StatusType Status,
  CoreIdType CoreID
));


/***********************************************************************************************************************
 *  Os_ErrReportGetErrorHookStackUsage()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    CoreID            The first API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportGetErrorHookStackUsage,
(
  Os_StatusType Status,
  CoreIdType CoreID
));


/***********************************************************************************************************************
 *  Os_ErrReportGetShutdownHookStackUsage()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    CoreID            The first API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportGetShutdownHookStackUsage,
(
  Os_StatusType Status,
  CoreIdType CoreID
));


/***********************************************************************************************************************
 *  Os_ErrReportGetProtectionHookStackUsage()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    CoreID            The first API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportGetProtectionHookStackUsage,
(
  Os_StatusType Status,
  CoreIdType CoreID
));


/***********************************************************************************************************************
 *  Os_ErrReportDisableInterruptSource()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status           The result of the API execution.
 *  \param[in]    ISRID            The first API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref DisableInterruptSource().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportDisableInterruptSource,
(
  Os_StatusType Status,
  ISRType ISRID
));


/***********************************************************************************************************************
 *  Os_ErrReportEnableInterruptSource()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    ISRID             The first API parameter.
 *  \param[in]    ClearPending      The second API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref EnableInterruptSource().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportEnableInterruptSource,
(
  Os_StatusType Status,
  ISRType ISRID,
  boolean ClearPending
));

/***********************************************************************************************************************
 *  Os_ErrReportInitialEnableInterruptSources()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    ClearPending      The only API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref Os_InitialEnableInterruptSources().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportInitialEnableInterruptSources,
(
  Os_StatusType Status,
  boolean ClearPending
));


/***********************************************************************************************************************
 *  Os_ErrReportClearPendingInterrupt()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    ISRID            The first API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref ClearPendingInterrupt().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportClearPendingInterrupt,
(
  Os_StatusType Status,
  ISRType ISRID
));


/***********************************************************************************************************************
 *  Os_ErrReportIsInterruptSourceEnabled()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    ISRID             The first API parameter.
 *  \param[out]   IsEnabled         The second API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref IsInterruptSourceEnabled().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportIsInterruptSourceEnabled,
(
  Os_StatusType Status,
  ISRType ISRID,
  P2VAR(boolean, AUTOMATIC, OS_VAR_NOINIT) IsEnabled
));


/***********************************************************************************************************************
 *  Os_ErrReportIsInterruptPending()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    ISRID             The first API parameter.
 *  \param[out]   IsPending         The second API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref IsInterruptPending().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportIsInterruptPending,
(
  Os_StatusType Status,
  ISRType ISRID,
  P2VAR(boolean, AUTOMATIC, OS_VAR_NOINIT) IsPending
));


/***********************************************************************************************************************
 *  Os_ErrReportBarrierSynchronize()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    TaskID            The first API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref Os_BarrierSynchronize().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportBarrierSynchronize,
(
  Os_StatusType Status,
  Os_BarrierIdType BarrierID
));


/***********************************************************************************************************************
 *  Os_ErrReportActivateTask()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    TaskID            The first API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref ActivateTask().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportActivateTask,
(
  Os_StatusType Status,
  TaskType TaskID
));


/***********************************************************************************************************************
 *  Os_ErrReportTerminateTask()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref TerminateTask().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportTerminateTask,
(
  Os_StatusType Status
));


/***********************************************************************************************************************
 *  Os_ErrReportChainTask()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    TaskID            The first API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref ChainTask().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportChainTask,
(
  Os_StatusType Status,
  TaskType TaskID
));


/***********************************************************************************************************************
 *  Os_ErrReportGetTaskID()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    TaskID            The first API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref GetTaskID().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportGetTaskID,
(
  Os_StatusType Status,
  TaskRefType TaskID
));


/***********************************************************************************************************************
 *  Os_ErrReportGetTaskState()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    TaskID            The first API parameter.
 *  \param[in]    State             The second API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref GetTaskState().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportGetTaskState,
(
  Os_StatusType Status,
  TaskType TaskID,
  TaskStateRefType State
));


/***********************************************************************************************************************
 *  Os_ErrReportSchedule()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref Schedule().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportSchedule,
(
  Os_StatusType Status
));


/***********************************************************************************************************************
 *  Os_ErrReportSetEvent()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    TaskID            The first API parameter.
 *  \param[in]    Mask              The second API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref SetEvent().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportSetEvent,
(
  Os_StatusType Status,
  TaskType TaskID,
  EventMaskType Mask
));


/***********************************************************************************************************************
 *  Os_ErrReportClearEvent()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    Mask              The first API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref ClearEvent().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportClearEvent,
(
  Os_StatusType Status,
  EventMaskType Mask
));


/***********************************************************************************************************************
 *  Os_ErrReportGetEvent()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    TaskID            The first API parameter.
 *  \param[in]    Mask              The second API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref GetEvent().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportGetEvent,
(
  Os_StatusType Status,
  TaskType TaskID,
  EventMaskRefType Mask
));


/***********************************************************************************************************************
 *  Os_ErrReportWaitEvent()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    Mask              The first API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref WaitEvent().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportWaitEvent,
(
  Os_StatusType Status,
  EventMaskType Mask
));


/***********************************************************************************************************************
 *  Os_ErrReportGetAlarmBase()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    AlarmID           The first API parameter.
 *  \param[in]    Info              The second API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref GetAlarmBase().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportGetAlarmBase,
(
  Os_StatusType Status,
  AlarmType AlarmID,
  AlarmBaseRefType Info
));


/***********************************************************************************************************************
 *  Os_ErrReportGetAlarm()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    AlarmID           The first API parameter.
 *  \param[in]    Tick              The second API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref GetAlarm().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportGetAlarm,
(
  Os_StatusType Status,
  AlarmType AlarmID,
  TickRefType Tick
));


/***********************************************************************************************************************
 *  Os_ErrReportSetRelAlarm()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    AlarmID           The first API parameter.
 *  \param[in]    Increment         The second API parameter.
 *  \param[in]    Cycle             The third API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref SetRelAlarm().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportSetRelAlarm,
(
  Os_StatusType Status,
  AlarmType AlarmID,
  TickType Increment,
  TickType Cycle
));


/***********************************************************************************************************************
 *  Os_ErrReportSetAbsAlarm()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    AlarmID           The first API parameter.
 *  \param[in]    Start             The second API parameter.
 *  \param[in]    Cycle             The third API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref SetAbsAlarm().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportSetAbsAlarm,
(
  Os_StatusType Status,
  AlarmType AlarmID,
  TickType Start,
  TickType Cycle
));


/***********************************************************************************************************************
 *  Os_ErrReportCancelAlarm()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    AlarmID           The first API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref CancelAlarm().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportCancelAlarm,
(
  Os_StatusType Status,
  AlarmType AlarmID
));


/***********************************************************************************************************************
 *  Os_ErrReportGetResource()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    ResID             The first API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref GetResource().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportGetResource,
(
  Os_StatusType Status,
  ResourceType ResID
));


/***********************************************************************************************************************
 *  Os_ErrReportReleaseResource()
 **********************************************************************************************************************/
/*! \brief        Reports the given status value in case of errors otherwise the function returns the StatusType
 *                specified by AUTOSAR.
 *  \details      --no details--
 *
 *  \param[in]    Status            The result of the API execution.
 *  \param[in]    ResID             The first API parameter.
 *
 *  \context      OS_INTERNAL
 *
 *  \return       See \ref ReleaseResource().
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrReportReleaseResource,
(
  Os_StatusType Status,
  ResourceType ResID
));


/***********************************************************************************************************************
 *  Os_ErrKernelPanic()
 **********************************************************************************************************************/
/*! \brief        Kernel Panic behavior.
 *  \details      Disable interrupts globally and call Panic Hook.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 *
 *  \trace        CREQ-133061
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(void, OS_CODE, OS_NORETURN, Os_ErrKernelPanic, (void));


/***********************************************************************************************************************
 *  Os_ErrIsValueLo()
 **********************************************************************************************************************/
/*! \brief          Checks whether the provided ID (signed or unsigned) is below the provided compare value.
 *  \details        --no details--
 *
 *  \param[in]      Id       The ID to be checked against the compare value.
 *  \param[in]      Compare  The compare value, the ID shall be checked against.
 *
 *  \retval         0        The ID is greater or equal to the compare value.
 *  \retval         !0       The ID is smaller than the compare value.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_ErrIsValueLo,
(
  uint32 Id,
  uint32 Compare
));


/***********************************************************************************************************************
 *  Os_ErrExtendedCheck()
 **********************************************************************************************************************/
/*! \brief        If extended status is enabled, the given value is returned, otherwise (Not OS_CHECK_FAILED) is
 *                returned.
 *  \details      --no details--
 *
 *  \param[in]    Value     The value to be evaluated.
 *
 *  \retval       OS_CHECK_FAILED       If extended status is enabled and the given Value is OS_CHECK_FAILED.
 *  \retval       Not OS_CHECK_FAILED   Otherwise.
 *
 *  Internal comment removed.
 *
 *
 *
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 *
 *  \trace        SPEC-63567
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrExtendedCheck,
(
  Os_StdReturnType Value
));


/***********************************************************************************************************************
 *  Os_ErrSetOkInStdStatus()
 **********************************************************************************************************************/
/*! \brief        If extended status is enabled, the given value is returned, otherwise OS_STATUS_OK is returned.
 *  \details      This allows APIs to check their enablement before anything else. API can then be optimized out
 *                completely even in STANDARD status, when no ID checks are performed.
 *
 *  \param[in]    Value     The value to be evaluated.
 *
 *  \retval       Value given as param[in]    If extended status is enabled.
 *  \retval       OS_STATUS_OK                Otherwise.
 *
 *  Internal comment removed.
 *
 *
 *
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrSetOkInStdStatus,
(
  Os_StatusType Value
));


/***********************************************************************************************************************
 *  Os_ErrServiceProtectionCheck()
 **********************************************************************************************************************/
/*! \brief        If service protection is enabled, the given value is returned, otherwise (Not OS_CHECK_FAILED) is
 *                returned.
 *  \details      --no details--
 *
 *  \param[in]    Value     The value to be evaluated.
 *
 *  \retval       OS_CHECK_FAILED       If service protection status is enabled and the given Value is OS_CHECK_FAILED.
 *  \retval       Not OS_CHECK_FAILED   Otherwise.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrServiceProtectionCheck,
(
  Os_StdReturnType Value
));


/***********************************************************************************************************************
 *  Os_Assert()
 **********************************************************************************************************************/
/*! \brief        System freeze, if the given condition is not true.
 *  \details      --no details--
 *
 *  \param[in]    Condition   Condition to be checked.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE for different cores
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Assert,
(
  Os_StdReturnType Condition
));


/***********************************************************************************************************************
 *  Os_ErrCheckPointerIsNotNull()
 **********************************************************************************************************************/
/*! \brief        Returns whether the given pointer is a non-null pointer (Not OS_CHECK_FAILED),
 *                or not (OS_CHECK_FAILED).
 *  \details      In case that extended checks are disabled, the default result of \ref Os_ErrExtendedCheck() is
 *                returned.
 *
 *  \param[in]    Pointer   The pointer to be checked.
 *
 *  \retval       Not OS_CHECK_FAILED   The given pointer is valid.
 *  \retval       OS_CHECK_FAILED       The given pointer is invalid.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrCheckPointerIsNotNull,
(
  P2CONST(volatile void, AUTOMATIC, OS_APPL_DATA) Pointer
));


/***********************************************************************************************************************
 *  Os_ErrCheckIsBoolean()
 **********************************************************************************************************************/
/*! \brief        Returns whether the given Value is has a boolean Value (Not OS_CHECK_FAILED),
 *                or not (OS_CHECK_FAILED).
 *  \details      In case that extended checks are disabled, the default result of \ref Os_ErrExtendedCheck() is
 *                returned.
 *
 *  \param[in]    Value   Value to be checked.
 *
 *  \retval       Not OS_CHECK_FAILED   The given value is valid (Value is TRUE or FALSE).
 *  \retval       OS_CHECK_FAILED       The given pointer is invalid.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrCheckIsBoolean,
(
  boolean Value
));


/***********************************************************************************************************************
 *  Os_ErrOsStatus2UserStatus()
 **********************************************************************************************************************/
/*! \brief        Converts an OS error code into an user error code.
 *  \details      --no details--
 *
 *  \param[in]    OsStatus    The OS error code
 *
 *  \return       The user error code.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_ErrOsStatus2UserStatus,
(
  Os_StatusType OsStatus
));


/***********************************************************************************************************************
 *  Os_ErrIsPropagationRequired()
 **********************************************************************************************************************/
/*! \brief        Returns whether the given error has to be propagated (!0) or not (0).
 *  \details      This function is responsible for application errors.
 *
 *  \param[in]    OsStatus    The OS error code.
 *
 *  \retval       !0  Error code has to be propagated.
 *  \retval       0   Error code may not be propagated.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrIsPropagationRequired,
(
  Os_StatusType OsStatus
));


/***********************************************************************************************************************
 *  Os_ErrIsProtectionPropagationRequired()
 **********************************************************************************************************************/
/*! \brief        Returns whether the given error has to be propagated (!0) or not (0).
 *  \details      This function is responsible for service protection errors.
 *
 *  \param[in]    OsStatus    The OS error code.
 *
 *  \retval       !0  Error code has to be propagated.
 *  \retval       0   Error code may not be propagated.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_ErrIsProtectionPropagationRequired,
(
  Os_StatusType OsStatus
));


/***********************************************************************************************************************
 *  Os_ErrIsKillingEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether killing is enabled (!0) or not (0).
 *  \details      --no details--
 *
 *  \retval       !0    Killing is enabled.
 *  \retval       0     Killing is disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,
OS_ALWAYS_INLINE, Os_ErrIsKillingEnabled, (void));



/***********************************************************************************************************************
 *  Os_ErrIsAssertEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether assert are enabled (!0) or not (0).
 *  \details      --no details--
 *
 *  \retval       !0    Assert is enabled.
 *  \retval       0     Assert is disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,
OS_ALWAYS_INLINE, Os_ErrIsAssertEnabled, (void));


/***********************************************************************************************************************
 *  Os_ErrIsServiceProtectionEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether Service Protection is enabled (!0) or not (0).
 *  \details      --no details--
 *
 *  \retval       !0    Enabled.
 *  \retval       0     Disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_ErrIsServiceProtectionEnabled, (void));


/***********************************************************************************************************************
 *  Os_ErrIsExtendedStatusEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether Extended Status is enabled (!0) or not (0).
 *  \details      --no details--
 *
 *  \retval       !0    Enabled.
 *  \retval       0     Disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 *
 *  \trace        SPEC-63567
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_ErrIsExtendedStatusEnabled, (void));


/***********************************************************************************************************************
 *  Os_ErrApplicationError()
 **********************************************************************************************************************/
/*! \brief        Behavior for application errors.
 *  \details      This function is called if the OS detects an application error. It calls the error hook.
 *
 *  \param[in]    ServiceId   Service which has detected the error.
 *  \param[in]    Status      Status code which shall be reported.
 *  \param[in]    Parameters  Contains the API parameters.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE for different cores.
 *  \synchronous  TRUE
 *
 *  \pre          -
 *
 *  \trace        CREQ-54, CREQ-40, CREQ-26
 *  \trace        SPEC-63913, SPEC-63777, SPEC-63960
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_ErrApplicationError
(
  OSServiceIdType ServiceId,
  Os_StatusType Status,
  P2CONST(Os_ErrorParamsType, TYPEDEF, OS_VAR_NOINIT) Parameters
);


/***********************************************************************************************************************
 *  Os_ErrProtectionError()
 **********************************************************************************************************************/
/*! \brief        Behavior for protection errors.
 *  \details      This function is called if the OS detects a protection error. It calls the protection hook.
 *                Depending on the return value of the protection hook, the error is ignored, the Task/ISR/Application
 *                is killed or the OS is shut down.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 *
 *  \trace        CREQ-40, CREQ-38
 *  \trace        SPEC-63761, SPEC-63900, SPEC-63880, SPEC-64039, SPEC-64021, SPEC-64003, SPEC-63738, SPEC-63959
 *  \trace        SPEC-63718, SPEC-63920, SPEC-63941, SPEC-63832
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_ErrProtectionError(Os_StatusType Fatalerror);


/***********************************************************************************************************************
 *  Os_ErrProtectionException()
 **********************************************************************************************************************/
/*! \brief        Behavior for exception errors.
 *  \details      This function is called if the OS detects an exception error. It calls the protection hook with the
 *                given error code if the OS is consistent. Otherwise kernel panic is called.
 *
 *  \param[in]    Error                        The error code to be forwarded, if no inconsistent state is detected.
 *  \param[in]    ExceptionInstructionAddress  The address of the last executed instruction before exception happened.
 *  \param[in]    ExceptionCauserPrivileged    Defines whether the system was in privileged mode during occurence of
 *                                             the exception:
 *                                               - TRUE:  Privileged mode was active.
 *                                               - FALSE: Non-Privileged mode was active.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-133061
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_ErrProtectionException
(
  Os_StatusType Error,
  Os_AddressOfConstType ExceptionInstructionAddress,
  boolean ExceptionCauserPrivileged
);


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_AlarmType()
 **********************************************************************************************************************/
/*! \brief        Returns a error parameter.
 *  \details      --no details--
 *
 *  \param[in]    ParamIndex    The index of the parameter within the erroneous API.
 *                              The index must be smaller than OS_ERRORPARAMINDEX_COUNT.
 *
 *  \context      OS_INTERNAL|ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-97
 **********************************************************************************************************************/
FUNC(AlarmType, OS_CODE) Os_ErrorGetParameter_AlarmType
(
  Os_ErrorParmIndexType ParamIndex
);


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_AlarmBaseRefType()
 **********************************************************************************************************************/
/*! \brief        Returns a error parameter.
 *  \details      --no details--
 *
 *  \param[in]    ParamIndex    The index of the parameter within the erroneous API.
 *                              The index must be smaller than OS_ERRORPARAMINDEX_COUNT.
 *
 *  \context      OS_INTERNAL|ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-97
 **********************************************************************************************************************/
FUNC(AlarmBaseRefType, OS_CODE) Os_ErrorGetParameter_AlarmBaseRefType(Os_ErrorParmIndexType ParamIndex);


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_ApplicationStateRefType()
 **********************************************************************************************************************/
/*! \brief        Returns a error parameter.
 *  \details      --no details--
 *
 *  \param[in]    ParamIndex    The index of the parameter within the erroneous API.
 *                              The index must be smaller than OS_ERRORPARAMINDEX_COUNT.
 *
 *  \context      OS_INTERNAL|ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-97
 **********************************************************************************************************************/
FUNC(ApplicationStateRefType, OS_CODE) Os_ErrorGetParameter_ApplicationStateRefType
(
  Os_ErrorParmIndexType ParamIndex
);


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_ApplicationType()
 **********************************************************************************************************************/
/*! \brief        Returns a error parameter.
 *  \details      --no details--
 *
 *  \param[in]    ParamIndex    The index of the parameter within the erroneous API.
 *                              The index must be smaller than OS_ERRORPARAMINDEX_COUNT.
 *
 *  \context      OS_INTERNAL|ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-97
 **********************************************************************************************************************/
FUNC(ApplicationType, OS_CODE) Os_ErrorGetParameter_ApplicationType
(
  Os_ErrorParmIndexType ParamIndex
);


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_boolean()
 **********************************************************************************************************************/
/*! \brief        Returns a error parameter.
 *  \details      --no details--
 *
 *  \param[in]    ParamIndex    The index of the parameter within the erroneous API.
 *                              The index must be smaller than OS_ERRORPARAMINDEX_COUNT.
 *
 *  \context      OS_INTERNAL|ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-97
 **********************************************************************************************************************/
FUNC(boolean, OS_CODE) Os_ErrorGetParameter_boolean(Os_ErrorParmIndexType ParamIndex);


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_booleanRefType()
 **********************************************************************************************************************/
/*! \brief        Returns a error parameter.
 *  \details      --no details--
 *
 *  \param[in]    ParamIndex    The index of the parameter within the erroneous API.
 *                              The index must be smaller than OS_ERRORPARAMINDEX_COUNT.
 *
 *  \context      OS_INTERNAL|ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-97
 **********************************************************************************************************************/
FUNC(P2VAR(boolean, AUTOMATIC, OS_VAR_NOINIT), OS_CODE) Os_ErrorGetParameter_booleanRefType
(
  Os_ErrorParmIndexType ParamIndex
);


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_CoreIdType()
 **********************************************************************************************************************/
/*! \brief        Returns a error parameter.
 *  \details      --no details--
 *
 *  \param[in]    ParamIndex    The index of the parameter within the erroneous API.
 *                              The index must be smaller than OS_ERRORPARAMINDEX_COUNT.
 *
 *  \context      OS_INTERNAL|ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-97
 **********************************************************************************************************************/
FUNC(CoreIdType, OS_CODE) Os_ErrorGetParameter_CoreIdType(Os_ErrorParmIndexType ParamIndex);


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_ExceptionContextRefType()
 **********************************************************************************************************************/
/*! \brief        Returns a error parameter.
 *  \details      --no details--
 *
 *  \param[in]    ParamIndex    The index of the parameter within the erroneous API.
 *                              The index must be smaller than OS_ERRORPARAMINDEX_COUNT.
 *
 *  \context      OS_INTERNAL|ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-97
 **********************************************************************************************************************/
FUNC(Os_ExceptionContextRefType, OS_CODE) Os_ErrorGetParameter_ExceptionContextRefType
(
  Os_ErrorParmIndexType ParamIndex
);


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_CounterType()
 **********************************************************************************************************************/
/*! \brief        Returns a error parameter.
 *  \details      --no details--
 *
 *  \param[in]    ParamIndex    The index of the parameter within the erroneous API.
 *                              The index must be smaller than OS_ERRORPARAMINDEX_COUNT.
 *
 *  \context      OS_INTERNAL|ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-97
 **********************************************************************************************************************/
FUNC(CounterType, OS_CODE) Os_ErrorGetParameter_CounterType(Os_ErrorParmIndexType ParamIndex);


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_EventMaskType()
 **********************************************************************************************************************/
/*! \brief        Returns a error parameter.
 *  \details      --no details--
 *
 *  \param[in]    ParamIndex    The index of the parameter within the erroneous API.
 *                              The index must be smaller than OS_ERRORPARAMINDEX_COUNT.
 *
 *  \context      OS_INTERNAL|ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-97
 **********************************************************************************************************************/
FUNC(EventMaskType, OS_CODE) Os_ErrorGetParameter_EventMaskType(Os_ErrorParmIndexType ParamIndex);


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_EventMaskRefType()
 **********************************************************************************************************************/
/*! \brief        Returns a error parameter.
 *  \details      --no details--
 *
 *  \param[in]    ParamIndex    The index of the parameter within the erroneous API.
 *                              The index must be smaller than OS_ERRORPARAMINDEX_COUNT.
 *
 *  \context      OS_INTERNAL|ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-97
 **********************************************************************************************************************/
FUNC(EventMaskType*, OS_CODE) Os_ErrorGetParameter_EventMaskRefType(Os_ErrorParmIndexType ParamIndex);


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_IdleModeType()
 **********************************************************************************************************************/
/*! \brief        Returns a error parameter.
 *  \details      --no details--
 *
 *  \param[in]    ParamIndex    The index of the parameter within the erroneous API.
 *                              The index must be smaller than OS_ERRORPARAMINDEX_COUNT.
 *
 *  \context      OS_INTERNAL|ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-97
 **********************************************************************************************************************/
FUNC(IdleModeType, OS_CODE) Os_ErrorGetParameter_IdleModeType(Os_ErrorParmIndexType ParamIndex);


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_ISRType()
 **********************************************************************************************************************/
/*! \brief        Returns a error parameter.
 *  \details      --no details--
 *
 *  \param[in]    ParamIndex    The index of the parameter within the erroneous API.
 *                              The index must be smaller than OS_ERRORPARAMINDEX_COUNT.
 *
 *  \context      OS_INTERNAL|ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-97
 **********************************************************************************************************************/
FUNC(ISRType, OS_CODE) Os_ErrorGetParameter_ISRType(Os_ErrorParmIndexType ParamIndex);


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_ResourceType()
 **********************************************************************************************************************/
/*! \brief        Returns a error parameter.
 *  \details      --no details--
 *
 *  \param[in]    ParamIndex    The index of the parameter within the erroneous API.
 *                              The index must be smaller than OS_ERRORPARAMINDEX_COUNT.
 *
 *  \context      OS_INTERNAL|ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-97
 **********************************************************************************************************************/
FUNC(ResourceType, OS_CODE) Os_ErrorGetParameter_ResourceType(Os_ErrorParmIndexType ParamIndex);


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_InterruptSourceIdRefType()
 **********************************************************************************************************************/
/*! \brief        Returns a error parameter.
 *  \details      --no details--
 *
 *  \param[in]    ParamIndex    The index of the parameter within the erroneous API.
 *                              The index must be smaller than OS_ERRORPARAMINDEX_COUNT.
 *
 *  \context      OS_INTERNAL|ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-97
 **********************************************************************************************************************/
FUNC(Os_InterruptSourceIdRefType, OS_CODE) Os_ErrorGetParameter_InterruptSourceIdRefType
(
  Os_ErrorParmIndexType ParamIndex
);


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_ExceptionSourceIdRefType()
 **********************************************************************************************************************/
/*! \brief        Returns a error parameter.
 *  \details      --no details--
 *
 *  \param[in]    ParamIndex    The index of the parameter within the erroneous API.
 *                              The index must be smaller than OS_ERRORPARAMINDEX_COUNT.
 *
 *  \context      OS_INTERNAL|ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-97
 **********************************************************************************************************************/
FUNC(Os_ExceptionSourceIdRefType, OS_CODE) Os_ErrorGetParameter_ExceptionSourceIdRefType
(
  Os_ErrorParmIndexType ParamIndex
);


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_RestartType()
 **********************************************************************************************************************/
/*! \brief        Returns a error parameter.
 *  \details      --no details--
 *
 *  \param[in]    ParamIndex    The index of the parameter within the erroneous API.
 *                              The index must be smaller than OS_ERRORPARAMINDEX_COUNT.
 *
 *  \context      OS_INTERNAL|ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-97
 **********************************************************************************************************************/
FUNC(RestartType, OS_CODE) Os_ErrorGetParameter_RestartType(Os_ErrorParmIndexType ParamIndex);


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_ScheduleTableStatusRefType()
 **********************************************************************************************************************/
/*! \brief        Returns a error parameter.
 *  \details      --no details--
 *
 *  \param[in]    ParamIndex    The index of the parameter within the erroneous API.
 *                              The index must be smaller than OS_ERRORPARAMINDEX_COUNT.
 *
 *  \context      OS_INTERNAL|ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-97
 **********************************************************************************************************************/
FUNC(ScheduleTableStatusRefType, OS_CODE) Os_ErrorGetParameter_ScheduleTableStatusRefType
(
  Os_ErrorParmIndexType ParamIndex
);


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_ScheduleTableType()
 **********************************************************************************************************************/
/*! \brief        Returns a error parameter.
 *  \details      --no details--
 *
 *  \param[in]    ParamIndex    The index of the parameter within the erroneous API.
 *                              The index must be smaller than OS_ERRORPARAMINDEX_COUNT.
 *
 *  \context      OS_INTERNAL|ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-97
 **********************************************************************************************************************/
FUNC(ScheduleTableType, OS_CODE) Os_ErrorGetParameter_ScheduleTableType
(
  Os_ErrorParmIndexType ParamIndex
);



/***********************************************************************************************************************
 *  Os_ErrorGetParameter_SpinlockIdType()
 **********************************************************************************************************************/
/*! \brief        Returns a error parameter.
 *  \details      --no details--
 *
 *  \param[in]    ParamIndex    The index of the parameter within the erroneous API.
 *                              The index must be smaller than OS_ERRORPARAMINDEX_COUNT.
 *
 *  \context      OS_INTERNAL|ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-97
 **********************************************************************************************************************/
FUNC(SpinlockIdType, OS_CODE) Os_ErrorGetParameter_SpinlockIdType(Os_ErrorParmIndexType ParamIndex);


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_TaskRefType()
 **********************************************************************************************************************/
/*! \brief        Returns a error parameter.
 *  \details      --no details--
 *
 *  \param[in]    ParamIndex    The index of the parameter within the erroneous API.
 *                              The index must be smaller than OS_ERRORPARAMINDEX_COUNT.
 *
 *  \context      OS_INTERNAL|ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-97
 **********************************************************************************************************************/
FUNC(TaskRefType, OS_CODE) Os_ErrorGetParameter_TaskRefType(Os_ErrorParmIndexType ParamIndex);


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_TaskStateRefType()
 **********************************************************************************************************************/
/*! \brief        Returns a error parameter.
 *  \details      --no details--
 *
 *  \param[in]    ParamIndex    The index of the parameter within the erroneous API.
 *                              The index must be smaller than OS_ERRORPARAMINDEX_COUNT.
 *
 *  \context      OS_INTERNAL|ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-97
 **********************************************************************************************************************/
FUNC(TaskStateRefType, OS_CODE) Os_ErrorGetParameter_TaskStateRefType(Os_ErrorParmIndexType ParamIndex);


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_BarrierIdType()
 **********************************************************************************************************************/
/*! \brief        Returns a error parameter.
 *  \details      --no details--
 *
 *  \param[in]    ParamIndex    The index of the parameter within the erroneous API.
 *                              The index must be smaller than OS_ERRORPARAMINDEX_COUNT.
 *
 *  \context      OS_INTERNAL|ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-97
 **********************************************************************************************************************/
FUNC(Os_BarrierIdType, OS_CODE) Os_ErrorGetParameter_BarrierIdType(Os_ErrorParmIndexType ParamIndex);


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_TaskType()
 **********************************************************************************************************************/
/*! \brief        Returns a error parameter.
 *  \details      --no details--
 *
 *  \param[in]    ParamIndex    The index of the parameter within the erroneous API.
 *                              The index must be smaller than OS_ERRORPARAMINDEX_COUNT.
 *
 *  \context      OS_INTERNAL|ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-97
 **********************************************************************************************************************/
FUNC(TaskType, OS_CODE) Os_ErrorGetParameter_TaskType(Os_ErrorParmIndexType ParamIndex);


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_TickRefType()
 **********************************************************************************************************************/
/*! \brief        Returns a error parameter.
 *  \details      --no details--
 *
 *  \param[in]    ParamIndex    The index of the parameter within the erroneous API.
 *                              The index must be smaller than OS_ERRORPARAMINDEX_COUNT.
 *
 *  \context      OS_INTERNAL|ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-97
 **********************************************************************************************************************/
FUNC(TickRefType, OS_CODE) Os_ErrorGetParameter_TickRefType(Os_ErrorParmIndexType ParamIndex);


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_TickType()
 **********************************************************************************************************************/
/*! \brief        Returns a error parameter.
 *  \details      --no details--
 *
 *  \param[in]    ParamIndex    The index of the parameter within the erroneous API.
 *                              The index must be smaller than OS_ERRORPARAMINDEX_COUNT.
 *
 *  \context      OS_INTERNAL|ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-97
 **********************************************************************************************************************/
FUNC(TickType, OS_CODE) Os_ErrorGetParameter_TickType(Os_ErrorParmIndexType ParamIndex);


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_TrustedFunctionIndexType()
 **********************************************************************************************************************/
/*! \brief        Returns a error parameter.
 *  \details      --no details--
 *
 *  \param[in]    ParamIndex    The index of the parameter within the erroneous API.
 *                              The index must be smaller than OS_ERRORPARAMINDEX_COUNT.
 *
 *  \context      OS_INTERNAL|ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-97
 **********************************************************************************************************************/
FUNC(TrustedFunctionIndexType, OS_CODE) Os_ErrorGetParameter_TrustedFunctionIndexType
(
  Os_ErrorParmIndexType ParamIndex
);


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_TrustedFunctionParameterRefType()
 **********************************************************************************************************************/
/*! \brief        Returns a error parameter.
 *  \details      --no details--
 *
 *  \param[in]    ParamIndex    The index of the parameter within the erroneous API.
 *                              The index must be smaller than OS_ERRORPARAMINDEX_COUNT.
 *
 *  \context      OS_INTERNAL|ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-97
 **********************************************************************************************************************/
FUNC(TrustedFunctionParameterRefType, OS_CODE) Os_ErrorGetParameter_TrustedFunctionParameterRefType
(
  Os_ErrorParmIndexType ParamIndex
);


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_Os_NonTrustedFunctionIndexType()
 **********************************************************************************************************************/
/*! \brief        Returns a error parameter.
 *  \details      --no details--
 *
 *  \param[in]    ParamIndex    The index of the parameter within the erroneous API.
 *                              The index must be smaller than OS_ERRORPARAMINDEX_COUNT.
 *
 *  \context      OS_INTERNAL|ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-97
 **********************************************************************************************************************/
FUNC(Os_NonTrustedFunctionIndexType, OS_CODE) Os_ErrorGetParameter_Os_NonTrustedFunctionIndexType
(
  Os_ErrorParmIndexType ParamIndex
);


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_Os_NonTrustedFunctionParameterRefType()
 **********************************************************************************************************************/
/*! \brief        Returns a error parameter.
 *  \details      --no details--
 *
 *  \param[in]    ParamIndex    The index of the parameter within the erroneous API.
 *                              The index must be smaller than OS_ERRORPARAMINDEX_COUNT.
 *
 *  \context      OS_INTERNAL|ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-97
 **********************************************************************************************************************/
FUNC(Os_NonTrustedFunctionParameterRefType, OS_CODE) Os_ErrorGetParameter_Os_NonTrustedFunctionParameterRefType
(
  Os_ErrorParmIndexType ParamIndex
);


/***********************************************************************************************************************
 *  Os_ErrorGetParameter_TryToGetSpinlockRefType()
 **********************************************************************************************************************/
/*! \brief        Returns a error parameter.
 *  \details      --no details--
 *
 *  \param[in]    ParamIndex    The index of the parameter within the erroneous API.
 *                              The index must be smaller than OS_ERRORPARAMINDEX_COUNT.
 *
 *  \context      OS_INTERNAL|ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-97
 **********************************************************************************************************************/
FUNC(TryToGetSpinlockType const *, OS_CODE) Os_ErrorGetParameter_TryToGetSpinlockRefType
(
  Os_ErrorParmIndexType ParamIndex
);


/***********************************************************************************************************************
 *  Os_Api_GetDetailedError()
 **********************************************************************************************************************/
/*! \brief        Returns error information of the last error occurred on the local core.
 *  \details      For further details see Os_GetDetailedError().
 *
 *  \param[out]   ErrorRef    See Os_GetDetailedError().
 *                            Parameter must not be NULL.
 *
 *  \retval       OS_STATUS_OK             No error.
 *  \retval       OS_STATUS_CALLEVEL       (EXTENDED status:) Called from invalid context.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See Os_GetDetailedError().
 *
 *  \trace        CREQ-102
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_GetDetailedError(Os_ErrorInformationRefType ErrorRef);


/***********************************************************************************************************************
 *  Os_Api_ErrorGetServiceId()
 **********************************************************************************************************************/
/*! \brief        OS service OSErrorGetServiceId().
 *  \details      For further details see OSErrorGetServiceId().
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See OSErrorGetServiceId().
 *
 *  \trace        CREQ-23
 *  \trace        SPEC-67577
 **********************************************************************************************************************/
FUNC(OSServiceIdType, OS_CODE) Os_Api_ErrorGetServiceId
(
  void
);

/***********************************************************************************************************************
 *  GLOBAL FUNCTION
 **********************************************************************************************************************/




# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_ERRORINT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_ErrorInt.h
 **********************************************************************************************************************/
