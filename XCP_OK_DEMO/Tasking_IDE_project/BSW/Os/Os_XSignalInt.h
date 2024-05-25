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
 * \defgroup    Os_XSignal XSignal
 * \brief       Internal cross core signal service.
 * \details
 * This component provides functionality to execute asynchronous and synchronous services on foreign cores. The concept
 * is described in \ref CrossCoreCommunication.
 *
 * XSignal Cross Core Communication Scheme
 * ---------------------------------------
 * The XSignal scheme is used for all communication which needs to trigger actions on another core. User level cross
 * core communication is not handled by this module (done by \ref Os_Ioc).
 *
 * ![Handling Cross Core Service](XSignal_CrossCoreService.png)
 *
 * The caller core of a service is referred as sender, the core which executes the service is referred as
 * receiver. Sending cores have a send port for each connected core. Receiver cores have a receiver port for each
 * connected sender core. Each pair of sender/receiver port is connected by a channel. The channel is a FIFO, consisting
 * of communication objects. Communication objects contain a send object and a receive object.
 *
 * ![Communication Structure](XSignalCommunicationStructure.png)
 *
 * ###Communication
 *  1. The sender handles the results of asynchronous requests in order to keep the channel free.
 *  2. The sender prepares the transmission by getting a communication object from the channel.
 *  3. The sender writes the service call information into the communication object:
 *     - The service to call.
 *     - The call parameters.
 *     - The mode of call (synchronous or asynchronous).
 *     - The sender thread.
 *  4. The sender initiates the reception by triggering a cross core interrupt on the receiver core.
 *  5. If the mode of the call is asynchronous, sending is done.
 *  6. The receiver gets the communication object from the channel.
 *  7. The receiver calls the requested service with the given call parameters.
 *  8. The receiver writes the execution result and status back to the communication object and returns
 *     the object to the channel.
 *  9. If the mode of the call is synchronous, the sender polls the channel for the result.
 * 10. If the result is available, the sender frees the communication object.
 *
 *
 * If the channel buffer is full and the sender wants to transmit a further request, it is assumed that the buffer is
 * to small and therefore a status error code is returned.
 * If the receiver core does not answer a synchronous request, the sender will spin forever. This case has to be handled
 * by the user (e.g. by using timing protection or a watch dog).
 * Sending and answering is carried out in a strictly FIFO order. The handling of the results performed by the sender
 * may happen in an arbitrary order. As the sender knows the used communication object, he can poll the object for its
 * state:
 *
 * ![Communication Flow](XSigCommunicationFlow.png)
 *
 *  1. The channel is empty.
 *  2. A low priority thread (Thread 1) sends request 1 and starts polling for the result.
 *  3. A high priority thread (Thread 2) interrupts thread 1 sends request 2 and starts polling for the result.
 *  4. The receiver ISR comes up and handles request 1.
 *  5. The receiver ISR handles request 2 and returns.
 *  6. Thread 2 detects that the result for request 2 is available. It handles the result, marks the communication
 *     object as free, returns from the synchronous send routine and terminates.
 *  7. Thread 1 becomes running again. It detects that result 2 is available, handles the result and marks the
 *     communication object as free.
 *  8. Thread 1 sends a further request 3. As the channel is not empty, any handled request is removed.
 *  9. The request 3 is written to the channel.
 *
 *
 * ###Measures against deadlock
 * - Busy waiting with disabled interrupts must be prevented (and is unnecessary in the described implementation)
 *   (busy waiting with disabled interrupts would disable the cross core interrupt as well so that simultaneous cross
 *   core function request of two cores for each other would end up in deadlock)
 *   - Busy waiting at the sending thread may occur in the described implementation when the cross-core interrupt has
 *     been triggered until it has finished a RPC.
 * - Cross core interrupts must have higher priority then all threads which request cross core function calls on the
 *   core.
 * - Threads which request cross core function calls must allow interruption (ISRs must allow nesting, Interrupts have
 *   to be enabled)
 *
 * ###Possible enhancements of this concept:
 * - The function table may not only contain OS function but also user functions
 *
 *
 * ###Safety Aspects
 * In order to verify that the call of the cross core receiver function was intended, each Os_XSigRecv_* has to check:
 *  - whether all passed IDs are valid
 *  - whether all addressed objects are assigned to the local core.
 *
 * \{
 *
 * \file
 * \brief       Declaration of cross core signal services.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_XSIGNALINT_H
# define OS_XSIGNALINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_XSignal_Types.h"
# include "Os_XSignal_Lcfg.h"


/* Os kernel module dependencies */
# include "Os_Common_Types.h"
# include "Os_Core_Types.h"
# include "Os_Counter_Types.h"
# include "Os_Task_Types.h"
# include "Os_Alarm_Types.h"
# include "Os_ScheduleTable_Types.h"
# include "Os_IsrInt.h"
# include "Os_Thread_Types.h"
# include "Os_XSignalChannelInt.h"
# include "Os_Error_Types.h"
# include "Os_InterruptInt.h"
# include "Os_Core_Lcfg.h"
# include "Os_HookInt.h"

/* Os hal dependencies */
# include "Os_Hal_CoreInt.h"
# include "Os_Hal_CompilerInt.h"




/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/
/*! Type cast from Os_XSigIsrConfigType to Os_IsrConfigType by use of base element addressing. */
#define OS_XSIGNAL_CASTCONFIG_XSIGNALISR_2_ISR(isr)      (&((isr).IsrCfg))                                              /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/*! \brief      Function pointer type for cross core services.
 *
 *  \param[in]  SendApp       Sender application. Parameter must not be NULL.
 *  \param[in]  InParameter   Parameters to be passed to the service. Parameter must not be NULL.
 *  \param[in]  OutParameter  Parameters which are returned by the service. Parameter must not be NULL.
 *
 *  \return     Status of the called XSignal service.
 *
 *  \context    OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre        Concurrent access is prevented by caller.
 */
typedef P2FUNC(Os_StatusType, OS_CODE, Os_XSigFunctionType)
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
);


/*! Describes a cross core function. */
typedef struct
{
  /*! Cross core function array. */
  Os_XSigFunctionType FunctionRef;
}Os_XSigFunctionDescritorConfigType;


/*! List of allowed cross core functions. */
struct Os_XSigFunctionTableConfigType_Tag
{
  /*! Cross core function descriptor array (NULL_PTR = function not available at this port). */
  Os_XSigFunctionDescritorConfigType FunctionDescription[OS_XSIGFUNCTIONIDX_USEDCOUNT+1];                               /* PRQA S 4521 */ /* MD_Os_Rule1.1_4521 */
};


/*! The XSignal send communication object. */
struct Os_XSigRecvPortConfigType_Tag
{
  /*! Cross core queue for the response. */
  Os_XSigChannelRecvConfigType RecvChannel;

  /*! The send port corresponding to this receive port. */
  P2CONST(Os_XSigSendPortConfigType, TYPEDEF, OS_CONST) SendPort;
};


/*! The XSignal send communication object. */
struct Os_XSigSendPortConfigType_Tag
{
  /*! Cross Core queue for the request. */
  Os_XSigChannelSendConfigType SendChannel;

  /*! The receiver ISR corresponding to the SendChannel. */
  P2CONST(Os_XSigIsrConfigType, TYPEDEF, OS_CONST) XSigIsr;

  /*! The receive port corresponding to this send port. */
  P2CONST(Os_XSigRecvPortConfigType, TYPEDEF, OS_CONST) RecvPort;

  /*! The sender core associated with this send port. */
  P2CONST(Os_CoreAsrConfigType, TYPEDEF, OS_CONST) SendCore;
};


/*! Interrupt configuration for the cross core function call interrupt
 *  \extends Os_IsrConfigType_Tag
 */
struct Os_XSigIsrConfigType_Tag
{
  /*! Base class */
  Os_IsrConfigType IsrCfg;

  /*! The cross core function table. */
  P2CONST(Os_XSigFunctionTableConfigType, TYPEDEF, OS_CONST) FunctionTable;

  /*! The list of receive ports, which are assigned to this ISR. */
  P2CONST(Os_XSigRecvPortConfigRefType, TYPEDEF, OS_CONST) RecvPortRefs;

  /*! The number of elements in RecvPortRefs (equals OS_CFG_XSIG_NUM_ISR_<Name>_RECEIVER). */
  Os_ObjIdxType RecvPortCount;

  /*! The cross core interrupt to be triggered after data has been added to the FIFO. */
  P2CONST(Os_Hal_XSigInterruptConfigType, TYPEDEF, OS_CONST) HwConfig;
};


/*! Dynamic information of Cross Core function call interrupt */
struct Os_XSigIsrType_Tag
{
  Os_IsrType Isr;
};



/***********************************************************************************************************************
 *  Cross Core Configuration
 **********************************************************************************************************************/
/*! The XSignal communication object. */
struct Os_XSigConfigType_Tag
{
  /*! Cross Core function ports to each other core.
   * \details Contains a NULL_PTR if the there is no port to a specific core. */
  P2CONST(Os_XSigSendPortConfigType, TYPEDEF, OS_CONST) SendPorts[OS_COREASRCOREIDX_COUNT];

  /*! Incoming cross core interrupts which handle the reception and hold the receive ports. */
  P2CONST(Os_XSigIsrConfigRefType, TYPEDEF, OS_CONST) RecvIsrRefs;

  /*! The number of elements in RecvPortRefs (equals OS_CFG_XSIG_NUM_ISR_<Name>_RECEIVER). */
  Os_ObjIdxType RecvIsrCount;
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
 *  Os_XSigInit()
 **********************************************************************************************************************/
/*! \brief          Initialize the given XSignal for the first time (Init-Step4).
 *  \details        If XSignal is disabled, this function does nothing and the given pointer is not used.
 *
 *  \param[in,out]  XSignal The task which shall be initialized. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different XSignal.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_XSigInit
(
  P2CONST(Os_XSigConfigType, AUTOMATIC, OS_CONST) XSignal
);


/***********************************************************************************************************************
 *  Os_XSigIsEnabled()
 **********************************************************************************************************************/
/*! \brief          Returns whether XSignal is disabled or enabled.
 *  \details        Returns current state of OS_CFG_XSIGNAL.
 *
 *  \retval         0    XSignal is disabled.
 *  \retval         !0   XSignal is enabled.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_XSigIsEnabled,
(
  void
));


/***********************************************************************************************************************
 *  Os_XSigUseAsynchronous()
 **********************************************************************************************************************/
/*! \brief          Returns whether asynchronous XSignal calls are enabled.
 *  \details        Returns current state of OS_CFG_XSIG_USEASYNC.
 *
 *  \retval         0    XSignal shall use synchronous calls only.
 *  \retval         !0   XSignal shall use asynchronous calls when possible.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_XSigUseAsynchronous,
(
  void
));


/***********************************************************************************************************************
 *  Os_XSigSend()
 **********************************************************************************************************************/
/*! \brief          Calls \ref Os_XSigSendAsync() or \ref Os_XSigSendSync() depending on the IsSynchronous flag.
 *  \details        --no details--
 *
 *  \param[in]      RecvCore        The receiving caller core. Parameter must not be NULL.
 *  \param[in]      SendThread      The sender thread of the cross core request. Parameter must not be NULL.
 *  \param[in]      FunctionIdx     The function to call.
 *  \param[in]      Parameters      The call parameters. Parameter must not be NULL.
 *
 *  \return         See \ref Os_XSigSendAsync() or \ref Os_XSigSendSync().
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts must be enabled! (the function performs busy waiting)
 *  \pre            Target object is located on receiver core.
 *  \pre            SendThread is the current thread.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_XSigSend,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  Os_XSigFunctionIdx FunctionIdx,
  P2CONST(Os_XSigParamsType, AUTOMATIC, TYPEDEF) Parameters
));


/***********************************************************************************************************************
 *  Os_XSigSendAsync()
 **********************************************************************************************************************/
/*! \brief          Trigger a remote function on a foreign core.
 *  \details        This function is used in case the cross core function shall be triggered asynchronously
 *                  (fire and forget).
 *
 *  \param[in]      RecvCore        The receiving caller core. Parameter must not be NULL.
 *  \param[in]      SendThread      The sender thread of the cross core request. Parameter must not be NULL.
 *  \param[in]      FunctionIdx     The function to call.
 *  \param[in]      Parameters      The call parameters. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_CALL_NOT_ALLOWED          No communication with that core allowed.
 *  \retval         OS_STATUS_FUNCTION_UNAVAILABLE      Destination ISR does not support this function.
 *  \retval         other                               The return value of the called function.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Target object is located on receiver core.
 *  \pre            SendThread is the current thread.
 *  \pre            Caller function is member of XSignal subcomponent.
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_XSigSendAsync
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  Os_XSigFunctionIdx FunctionIdx,
  P2CONST(Os_XSigParamsType, AUTOMATIC, TYPEDEF) Parameters
);


/***********************************************************************************************************************
 *  Os_XSigSendSync()
 **********************************************************************************************************************/
/*! \brief          Trigger a remote function on a foreign core and wait until it has finished.
 *  \details        This function is used in case the cross core function shall be triggered synchronously
 *                  (Remote Procedure Call, RPC).
 *
 *  \param[in]      RecvCore        The receiving caller core. Parameter must not be NULL.
 *  \param[in]      SendThread      The sender thread of the cross core request. Parameter must not be NULL.
 *  \param[in]      FunctionIdx     The function to call.
 *  \param[in]      InParameters    The call parameters. Parameter must not be NULL.
 *  \param[out]     OutParameters   The output parameters of the API call. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK                        No error.
 *  \retval         OS_STATUS_CALL_NOT_ALLOWED          No communication with that core allowed.
 *  \retval         OS_STATUS_FUNCTION_UNAVAILABLE      Destination ISR does not support this function.
 *  \retval         OS_STATUS_CALLEVEL_CROSS_CORE_SYNC  Synchronous request may not be send from the current context.
 *  \retval         other                               The return value of the called function.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts must be enabled! (the function performs busy waiting)
 *  \pre            SendThread is the current thread.
 *  \pre            Caller function is member of XSignal subcomponent.
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_XSigSendSync
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  Os_XSigFunctionIdx FunctionIdx,
  P2CONST(Os_XSigParamsType, AUTOMATIC, TYPEDEF) InParameters,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, TYPEDEF) OutParameters
);


/***********************************************************************************************************************
 *  Os_XSigSend_ActivateTask()
 **********************************************************************************************************************/
/*! \brief          Send signal to activate a task on a foreign core.
 *  \details        --no details--
 *
 *  \param[in]      RecvCore    Pointer to the core configuration of the destination core.
 *                              Parameter must not be NULL.
 *  \param[in]      SendThread  The user thread that called the API. Parameter must not be NULL.
 *  \param[in]      TaskID      As described for \ref Os_Api_ActivateTask.
 *
 *  \retval         OS_STATUS_OK                        No error.
 *  \retval         OS_STATUS_CALL_NOT_ALLOWED          No communication with that core allowed.
 *  \retval         OS_STATUS_FUNCTION_UNAVAILABLE      Destination ISR does not support this function.
 *  \retval         OS_STATUS_CALLEVEL_CROSS_CORE_SYNC  Synchronous request may not be send from the current context.
 *  \retval         other                               In case of RPC, this function may return the values
 *                                                      described for \ref Os_Api_ActivateTask.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Caller has already performed checks, which can be performed locally.
 *  \pre            Interrupts are enabled.
 *  \pre            Target object is located on receiver core.
 *  \pre            SendThread is the current thread.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_XSigSend_ActivateTask,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  TaskType TaskID
));


/***********************************************************************************************************************
 *  Os_XSigSend_ActivateTaskAsync()
 **********************************************************************************************************************/
/*! \brief    Send signal to activate a task on a foreign core asynchronous.
 *  \details  The call is performed asynchronous, independent from the configuration.
 *
 *  \param[in]      RecvCore    Pointer to the core configuration of the destination core.
 *                              Parameter must not be NULL.
 *  \param[in]      SendThread  The user thread that called the API. Parameter must not be NULL.
 *  \param[in]      TaskID      As described for \ref Os_Api_ActivateTask.
 *
 *  \retval         OS_STATUS_OK                        No error.
 *  \retval         OS_STATUS_CALL_NOT_ALLOWED          No communication with that core allowed.
 *  \retval         OS_STATUS_FUNCTION_UNAVAILABLE      Destination ISR does not support this function.
 *  \retval         OS_STATUS_CALLEVEL_CROSS_CORE_SYNC  Synchronous request may not be send from the current context.
 *  \retval         other                               In case of RPC, this function may return the values
 *                                                      described for \ref Os_Api_ActivateTask.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Caller has already performed checks, which can be performed locally.
 *  \pre            Target object is located on receiver core.
 *  \pre            SendThread is the current thread.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_XSigSend_ActivateTaskAsync,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  TaskType TaskID
));


/***********************************************************************************************************************
 *  Os_XSigSend_GetTaskState()
 **********************************************************************************************************************/
/*! \brief          Send signal to get the task state on a foreign core.
 *  \details        --no details--
 *
 *  \param[in]      RecvCore    Pointer to the core configuration of the destination core.
 *                              Parameter must not be NULL.
 *  \param[in]      SendThread  The user thread that called the API. Parameter must not be NULL.
 *  \param[in]      TaskID      As described for \ref Os_Api_GetTaskState.
 *  \param[in]      State       As described for \ref Os_Api_GetTaskState.
 *
 *  \retval         OS_STATUS_OK                        No error.
 *  \retval         OS_STATUS_CALL_NOT_ALLOWED          No communication with that core allowed.
 *  \retval         OS_STATUS_FUNCTION_UNAVAILABLE      Destination ISR does not support this function.
 *  \retval         OS_STATUS_CALLEVEL_CROSS_CORE_SYNC  Synchronous request may not be send from the current context.
 *  \retval         other                               In case of RPC, this function may return the values
 *                                                      described for \ref Os_Api_GetTaskState.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Caller has already performed checks, which can be performed locally.
 *  \pre            Target object is located on receiver core.
 *  \pre            Interrupts are enabled.
 *  \pre            SendThread is the current thread.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_XSigSend_GetTaskState,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  TaskType TaskID,
  TaskStateRefType State
));


/***********************************************************************************************************************
 *  Os_XSigSend_GetCounterValue()
 **********************************************************************************************************************/
/*! \brief          Send signal to get a counter value on a foreign core.
 *  \details        --no details--
 *
 *  \param[in]      RecvCore    Pointer to the core configuration of the destination core.
 *                              Parameter must not be NULL.
 *  \param[in]      SendThread  The user thread that called the API. Parameter must not be NULL.
 *  \param[in]      CounterID   The id of the counter.
 *  \param[in]      Value       As described for \ref Os_Api_GetCounterValue.
 *
 *  \retval         OS_STATUS_OK                        No error.
 *  \retval         OS_STATUS_CALL_NOT_ALLOWED          No communication with that core allowed.
 *  \retval         OS_STATUS_FUNCTION_UNAVAILABLE      Destination ISR does not support this function.
 *  \retval         OS_STATUS_CALLEVEL_CROSS_CORE_SYNC  Synchronous request may not be send from the current context.
 *  \retval         other                               In case of RPC, this function may return the values
 *                                                      described for \ref Os_Api_GetCounterValue.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Caller has already performed checks, which can be performed locally.
 *  \pre            Interrupts are enabled.
 *  \pre            Target object is located on receiver core.
 *  \pre            SendThread is the current thread.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_XSigSend_GetCounterValue,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  CounterType CounterID,
  TickRefType Value
));


/***********************************************************************************************************************
 *  Os_XSigSend_SetEvent()
 **********************************************************************************************************************/
/*! \brief          Send signal to set an event for a task on a foreign core.
 *  \details        --no details--
 *
 *  \param[in]      RecvCore    Pointer to the core configuration of the destination core.
 *                              Parameter must not be NULL.
 *  \param[in]      SendThread  The user thread that called the API. Parameter must not be NULL.
 *  \param[in]      TaskID      As described for \ref Os_Api_SetEvent.
 *  \param[in]      Mask        As described for \ref Os_Api_SetEvent.
 *
 *  \retval         OS_STATUS_OK                        No error.
 *  \retval         OS_STATUS_CALL_NOT_ALLOWED          No communication with that core allowed.
 *  \retval         OS_STATUS_FUNCTION_UNAVAILABLE      Destination ISR does not support this function.
 *  \retval         OS_STATUS_CALLEVEL_CROSS_CORE_SYNC  Synchronous request may not be send from the current context.
 *  \retval         other                               In case of RPC, this function may return the values
 *                                                      described for \ref Os_Api_SetEvent.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Caller has already performed checks, which can be performed locally.
 *  \pre            Interrupts are enabled.
 *  \pre            Target object is located on receiver core.
 *  \pre            SendThread is the current thread.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_XSigSend_SetEvent,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  TaskType TaskID,
  EventMaskType Mask
));


/***********************************************************************************************************************
 *  Os_XSigSend_SetEventAsync()
 **********************************************************************************************************************/
/*! \brief    Send signal to set an event for a task on a foreign core.
 *  \details  The call is performed asynchronous, independent from the configuration.
 *
 *  \param[in]      RecvCore    Pointer to the core configuration of the destination core.
 *                  Parameter must not be NULL.
 *  \param[in]      SendThread  The user thread that called the API. Parameter must not be NULL.
 *  \param[in]      TaskID      As described for \ref Os_Api_SetEvent.
 *  \param[in]      Mask        As described for \ref Os_Api_SetEvent.
 *
 *  \retval         OS_STATUS_OK                        No error.
 *  \retval         OS_STATUS_CALL_NOT_ALLOWED          No communication with that core allowed.
 *  \retval         OS_STATUS_FUNCTION_UNAVAILABLE      Destination ISR does not support this function.
 *  \retval         OS_STATUS_CALLEVEL_CROSS_CORE_SYNC  Synchronous request may not be send from the current context.
 *  \retval         other                               In case of RPC, this function may return the values
 *                                                      described for \ref Os_Api_SetEvent.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Caller has already performed checks, which can be performed locally.
 *  \pre            Interrupts are enabled.
 *  \pre            Target object is located on receiver core.
 *  \pre            SendThread is the current thread.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_XSigSend_SetEventAsync,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  TaskType TaskID,
  EventMaskType Mask
));


/***********************************************************************************************************************
 *  Os_XSigSend_GetEvent()
 **********************************************************************************************************************/
/*! \brief          Send signal to get an event for a task on a foreign core.
 *  \details        --no details--
 *
 *  \param[in]      RecvCore    Pointer to the core configuration of the destination core.
 *                              Parameter must not be NULL.
 *  \param[in]      SendThread  The user thread that called the API. Parameter must not be NULL.
 *  \param[in]      TaskID      As described for \ref Os_Api_GetEvent.
 *  \param[out]     Mask        As described for \ref Os_Api_GetEvent.
 *
 *  \retval         OS_STATUS_OK                        No error.
 *  \retval         OS_STATUS_CALL_NOT_ALLOWED          No communication with that core allowed.
 *  \retval         OS_STATUS_FUNCTION_UNAVAILABLE      Destination ISR does not support this function.
 *  \retval         OS_STATUS_CALLEVEL_CROSS_CORE_SYNC  Synchronous request may not be send from the current context.
 *  \retval         other                               In case of RPC, this function may return the values
 *                                                      described for \ref Os_Api_GetEvent.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Caller has already performed checks, which can be performed locally.
 *  \pre            Interrupts are enabled.
 *  \pre            Target object is located on receiver core.
 *  \pre            SendThread is the current thread.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_XSigSend_GetEvent,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  TaskType TaskID,
  EventMaskRefType Mask
));


/***********************************************************************************************************************
 *  Os_XSigSend_GetAlarm()
 **********************************************************************************************************************/
/*! \brief          Send signal to get the alarm on a foreign core.
 *  \details        --no details--
 *
 *  \param[in]      RecvCore    Pointer to the core configuration of the destination core.
 *                              Parameter must not be NULL.
 *  \param[in]      SendThread  The user thread that called the API. Parameter must not be NULL.
 *  \param[in]      AlarmID     As described for \ref Os_Api_GetAlarm().
 *  \param[out]     Tick        As described for \ref Os_Api_GetAlarm().
 *
 *  \retval         OS_STATUS_OK                        No error.
 *  \retval         OS_STATUS_CALL_NOT_ALLOWED          No communication with that core allowed.
 *  \retval         OS_STATUS_FUNCTION_UNAVAILABLE      Destination ISR does not support this function.
 *  \retval         OS_STATUS_CALLEVEL_CROSS_CORE_SYNC  Synchronous request may not be send from the current context.
 *  \retval         other                               In case of RPC, this function may return the values
 *                                                      described for \ref Os_Api_GetAlarm.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Caller has already performed checks, which can be performed locally.
 *  \pre            Interrupts are enabled.
 *  \pre            Target object is located on receiver core.
 *  \pre            SendThread is the current thread.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE,
OS_ALWAYS_INLINE, Os_XSigSend_GetAlarm,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  AlarmType AlarmID,
  TickRefType Tick
));


/***********************************************************************************************************************
 *  Os_XSigSend_SetRelAlarm()
 **********************************************************************************************************************/
/*! \brief          Send signal to setup a relative alarm on a foreign core.
 *  \details        --no details--
 *
 *  \param[in]      RecvCore    Pointer to the core configuration of the destination core.
 *                              Parameter must not be NULL.
 *  \param[in]      SendThread  The user thread that called the API. Parameter must not be NULL.
 *  \param[in]      AlarmID     As described for \ref Os_Api_SetRelAlarm.
 *  \param[in]      Increment   As described for \ref Os_Api_SetRelAlarm.
 *  \param[in]      Cycle       As described for \ref Os_Api_SetRelAlarm.
 *
 *  \retval         OS_STATUS_OK                        No error.
 *  \retval         OS_STATUS_CALL_NOT_ALLOWED          No communication with that core allowed.
 *  \retval         OS_STATUS_FUNCTION_UNAVAILABLE      Destination ISR does not support this function.
 *  \retval         OS_STATUS_CALLEVEL_CROSS_CORE_SYNC  Synchronous request may not be send from the current context.
 *  \retval         other                               In case of RPC, this function may return the values
 *                                                      described for \ref Os_Api_SetRelAlarm.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Caller has already performed checks, which can be performed locally.
 *  \pre            Interrupts are enabled.
 *  \pre            Target object is located on receiver core.
 *  \pre            SendThread is the current thread.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_XSigSend_SetRelAlarm,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  AlarmType AlarmID,
  TickType Increment,
  TickType Cycle
));


/***********************************************************************************************************************
 *  Os_XSigSend_SetAbsAlarm()
 **********************************************************************************************************************/
/*! \brief          Send signal to setup an absolute alarm on a foreign core.
 *  \details        --no details--
 *
 *  \param[in]      RecvCore    Pointer to the core configuration of the destination core.
 *                              Parameter must not be NULL.
 *  \param[in]      SendThread  The user thread that called the API. Parameter must not be NULL.
 *  \param[in]      AlarmID     As described for \ref Os_Api_SetAbsAlarm.
 *  \param[in]      Start       As described for \ref Os_Api_SetAbsAlarm.
 *  \param[in]      Cycle       As described for \ref Os_Api_SetAbsAlarm.
 *
 *  \retval         OS_STATUS_OK                        No error.
 *  \retval         OS_STATUS_CALL_NOT_ALLOWED          No communication with that core allowed.
 *  \retval         OS_STATUS_FUNCTION_UNAVAILABLE      Destination ISR does not support this function.
 *  \retval         OS_STATUS_CALLEVEL_CROSS_CORE_SYNC  Synchronous request may not be send from the current context.
 *  \retval         other                               In case of RPC, this function may return the values
 *                                                      described for \ref Os_Api_SetAbsAlarm.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Caller has already performed checks, which can be performed locally.
 *  \pre            Interrupts are enabled.
 *  \pre            Target object is located on receiver core.
 *  \pre            SendThread is the current thread.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_XSigSend_SetAbsAlarm,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  AlarmType AlarmID,
  TickType Start,
  TickType Cycle
));


/***********************************************************************************************************************
 *  Os_XSigSend_CancelAlarm()
 **********************************************************************************************************************/
/*! \brief          Send signal to cancel an alarm on a foreign core.
 *  \details        --no details--
 *
 *  \param[in]      RecvCore    Pointer to the core configuration of the destination core.
 *                              Parameter must not be NULL.
 *  \param[in]      SendThread  The user thread that called the API. Parameter must not be NULL.
 *  \param[in]      AlarmID     As described for \ref Os_Api_CancelAlarm.
 *
 *  \retval         OS_STATUS_OK                        No error.
 *  \retval         OS_STATUS_CALL_NOT_ALLOWED          No communication with that core allowed.
 *  \retval         OS_STATUS_FUNCTION_UNAVAILABLE      Destination ISR does not support this function.
 *  \retval         OS_STATUS_CALLEVEL_CROSS_CORE_SYNC  Synchronous request may not be send from the current context.
 *  \retval         other                               In case of RPC, this function may return the values
 *                                                      described for \ref Os_Api_CancelAlarm.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Caller has already performed checks, which can be performed locally.
 *  \pre            Interrupts are enabled.
 *  \pre            Target object is located on receiver core.
 *  \pre            SendThread is the current thread.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_XSigSend_CancelAlarm,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  AlarmType AlarmID
));


/***********************************************************************************************************************
 *  Os_XSigSend_StartScheduleTableRel()
 **********************************************************************************************************************/
/*! \brief          Send signal to perform the service StartScheduleTableRel on a foreign core.
 *  \details        --no details--
 *
 *  \param[in]      RecvCore        Pointer to the core configuration of the destination core.
 *                                  Parameter must not be NULL.
 *  \param[in]      SendThread      The user thread that called the API. Parameter must not be NULL.
 *  \param[in]      ScheduleTableID As described for \ref Os_Api_StartScheduleTableRel.
 *  \param[in]      Offset          As described for \ref Os_Api_StartScheduleTableRel.
 *
 *  \retval         OS_STATUS_OK                        No error.
 *  \retval         OS_STATUS_CALL_NOT_ALLOWED          No communication with that core allowed.
 *  \retval         OS_STATUS_FUNCTION_UNAVAILABLE      Destination ISR does not support this function.
 *  \retval         OS_STATUS_CALLEVEL_CROSS_CORE_SYNC  Synchronous request may not be send from the current context.
 *  \retval         other                               In case of RPC, this function may return the values
 *                                                      described for \ref Os_Api_StartScheduleTableRel.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Caller has already performed checks, which can be performed locally.
 *  \pre            Interrupts are enabled.
 *  \pre            Target object is located on receiver core.
 *  \pre            SendThread is the current thread.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_XSigSend_StartScheduleTableRel,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  ScheduleTableType ScheduleTableID,
  TickType Offset
));


/***********************************************************************************************************************
 *  Os_XSigSend_StartScheduleTableAbs()
 **********************************************************************************************************************/
/*! \brief          Send signal to perform the service StartScheduleTableAbs on a foreign core.
 *  \details        --no details--
 *
 *  \param[in]      RecvCore        Pointer to the core configuration of the destination core.
 *                                  Parameter must not be NULL.
 *  \param[in]      SendThread      The user thread that called the API. Parameter must not be NULL.
 *  \param[in]      ScheduleTableID As described for \ref Os_Api_StartScheduleTableAbs.
 *  \param[in]      Start           As described for \ref Os_Api_StartScheduleTableAbs.
 *
 *  \retval         OS_STATUS_OK                        No error.
 *  \retval         OS_STATUS_CALL_NOT_ALLOWED          No communication with that core allowed.
 *  \retval         OS_STATUS_FUNCTION_UNAVAILABLE      Destination ISR does not support this function.
 *  \retval         OS_STATUS_CALLEVEL_CROSS_CORE_SYNC  Synchronous request may not be send from the current context.
 *  \retval         other                               In case of RPC, this function may return the values
 *                                                      described for \ref Os_Api_StartScheduleTableAbs.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Caller has already performed checks, which can be performed locally.
 *  \pre            Interrupts are enabled.
 *  \pre            Target object is located on receiver core.
 *  \pre            SendThread is the current thread.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_XSigSend_StartScheduleTableAbs,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  ScheduleTableType ScheduleTableID,
  TickType Start
));


/***********************************************************************************************************************
 *  Os_XSigSend_StopScheduleTable()
 **********************************************************************************************************************/
/*! \brief          Send signal to perform the service StopScheduleTable on a foreign core.
 *  \details        --no details--
 *
 *  \param[in]      RecvCore        Pointer to the core configuration of the destination core.
 *                                  Parameter must not be NULL.
 *  \param[in]      SendThread      The user thread that called the API. Parameter must not be NULL.
 *  \param[in]      ScheduleTableID As described for \ref Os_Api_StopScheduleTable.
 *
 *  \retval         OS_STATUS_OK                        No error.
 *  \retval         OS_STATUS_CALL_NOT_ALLOWED          No communication with that core allowed.
 *  \retval         OS_STATUS_FUNCTION_UNAVAILABLE      Destination ISR does not support this function.
 *  \retval         OS_STATUS_CALLEVEL_CROSS_CORE_SYNC  Synchronous request may not be send from the current context.
 *  \retval         other                               In case of RPC, this function may return the values
 *                                                      described for \ref Os_Api_StopScheduleTable
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Caller has already performed checks, which can be performed locally.
 *  \pre            Interrupts are enabled.
 *  \pre            Target object is located on receiver core.
 *  \pre            SendThread is the current thread.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_XSigSend_StopScheduleTable,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  ScheduleTableType ScheduleTableID
));


/***********************************************************************************************************************
 *  Os_XSigSend_NextScheduleTable()
 **********************************************************************************************************************/
/*! \brief          Send signal to perform the service NextScheduleTable on a foreign core.
 *  \details        --no details--
 *
 *  \param[in]      RecvCore              Pointer to the core configuration of the destination core.
 *                                        Parameter must not be NULL.
 *  \param[in]      SendThread            The user thread that called the API. Parameter must not be NULL.
 *  \param[in]      ScheduleTableID_From  As described for \ref Os_Api_NextScheduleTable.
 *  \param[in]      ScheduleTableID_To    As described for \ref Os_Api_NextScheduleTable.
 *
 *  \retval         OS_STATUS_OK                        No error.
 *  \retval         OS_STATUS_CALL_NOT_ALLOWED          No communication with that core allowed.
 *  \retval         OS_STATUS_FUNCTION_UNAVAILABLE      Destination ISR does not support this function.
 *  \retval         OS_STATUS_CALLEVEL_CROSS_CORE_SYNC  Synchronous request may not be send from the current context.
 *  \retval         other                               In case of RPC, this function may return the values
 *                                                      described for \ref Os_Api_NextScheduleTable
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Caller has already performed checks, which can be performed locally.
 *  \pre            Interrupts are enabled.
 *  \pre            Target object is located on receiver core.
 *  \pre            SendThread is the current thread.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_XSigSend_NextScheduleTable,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  ScheduleTableType ScheduleTableID_From,
  ScheduleTableType ScheduleTableID_To
));


/***********************************************************************************************************************
 *  Os_XSigSend_GetScheduleTableStatus()
 **********************************************************************************************************************/
/*! \brief          Send signal to perform the service GetScheduleTableStatus on a foreign core.
 *  \details        --no details--
 *
 *  \param[in]      RecvCore        Pointer to the core configuration of the destination core.
 *                                  Parameter must not be NULL.
 *  \param[in]      SendThread      The user thread that called the API. Parameter must not be NULL.
 *  \param[in]      ScheduleTableID As described for \ref Os_Api_GetScheduleTableStatus.
 *  \param[in]      ScheduleStatus  As described for \ref Os_Api_GetScheduleTableStatus.
 *
 *  \retval         OS_STATUS_OK                        No error.
 *  \retval         OS_STATUS_CALL_NOT_ALLOWED          No communication with that core allowed.
 *  \retval         OS_STATUS_FUNCTION_UNAVAILABLE      Destination ISR does not support this function.
 *  \retval         OS_STATUS_CALLEVEL_CROSS_CORE_SYNC  Synchronous request may not be send from the current context.
 *  \retval         other                               In case of RPC, this function may return the values
 *                                                      described for \ref Os_Api_GetScheduleTableStatus.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Caller has already performed checks, which can be performed locally.
 *  \pre            Interrupts are enabled.
 *  \pre            Target object is located on receiver core.
 *  \pre            SendThread is the current thread.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_XSigSend_GetScheduleTableStatus,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  ScheduleTableType ScheduleTableID,
  ScheduleTableStatusRefType ScheduleStatus
));


/***********************************************************************************************************************
 *  Os_XSigSend_GetTaskStackUsage()
 **********************************************************************************************************************/
/*! \brief          Send signal to perform the service GetTaskStackUsage on a foreign core.
 *  \details        --no details--
 *
 *  \param[in]      RecvCore        Pointer to the core configuration of the destination core.
 *                                  Parameter must not be NULL.
 *  \param[in]      SendThread      The user thread that called the API. Parameter must not be NULL.
 *  \param[in]      TaskID          As described for \ref Os_Api_GetTaskStackUsage.
 *  \param[out]     Result          The stack usage. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK                        No error.
 *  \retval         OS_STATUS_CALL_NOT_ALLOWED          No communication with that core allowed.
 *  \retval         OS_STATUS_FUNCTION_UNAVAILABLE      Destination ISR does not support this function.
 *  \retval         OS_STATUS_CALLEVEL_CROSS_CORE_SYNC  Synchronous request may not be send from the current context.
 *  \retval         other                               In case of RPC, this function may return the values
 *                                                      described for \ref Os_Api_GetTaskStackUsage.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Caller has already performed checks, which can be performed locally.
 *  \pre            Interrupts are enabled.
 *  \pre            Target object is located on receiver core.
 *  \pre            SendThread is the current thread.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_XSigSend_GetTaskStackUsage,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  TaskType TaskID,
  P2VAR(uint32, AUTOMATIC, OS_CONST) Result
));


/***********************************************************************************************************************
 *  Os_XSigSend_GetISRStackUsage()
 **********************************************************************************************************************/
/*! \brief          Send signal to perform the service GetISRStackUsage on a foreign core.
 *  \details        --no details--
 *
 *  \param[in]      RecvCore        Pointer to the core configuration of the destination core.
 *                                  Parameter must not be NULL.
 *  \param[in]      SendThread      The user thread that called the API. Parameter must not be NULL.
 *  \param[in]      IsrID           As described for \ref Os_Api_GetISRStackUsage.
 *  \param[out]     Result          The stack usage. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK                        No error.
 *  \retval         OS_STATUS_CALL_NOT_ALLOWED          No communication with that core allowed.
 *  \retval         OS_STATUS_FUNCTION_UNAVAILABLE      Destination ISR does not support this function.
 *  \retval         OS_STATUS_CALLEVEL_CROSS_CORE_SYNC  Synchronous request may not be send from the current context.
 *  \retval         other                               In case of RPC, this function may return the values
 *                                                      described for \ref Os_Api_GetISRStackUsage.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Caller has already performed checks, which can be performed locally.
 *  \pre            Interrupts are enabled.
 *  \pre            Target object is located on receiver core.
 *  \pre            SendThread is the current thread.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_XSigSend_GetISRStackUsage,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  ISRType IsrID,
  P2VAR(uint32, AUTOMATIC, OS_CONST) Result
));


/***********************************************************************************************************************
 *  Os_XSigSend_ControlIdle()
 **********************************************************************************************************************/
/*! \brief          Send signal to perform the service ControlIdle on a foreign core.
 *  \details        --no details--
 *
 *  \param[in]      RecvCore        Pointer to the core configuration of the destination core.
 *                                  Parameter must not be NULL.
 *  \param[in]      SendThread      The user thread that called the API. Parameter must not be NULL.
 *  \param[in]      CoreID          As described for \ref Os_Api_ControlIdle.
 *  \param[out]     IdleMode        As described for \ref Os_Api_ControlIdle.
 *
 *  \retval         OS_STATUS_OK                        No error.
 *  \retval         OS_STATUS_CALL_NOT_ALLOWED          No communication with that core allowed.
 *  \retval         OS_STATUS_FUNCTION_UNAVAILABLE      Destination ISR does not support this function.
 *  \retval         OS_STATUS_CALLEVEL_CROSS_CORE_SYNC  Synchronous request may not be send from the current context.
 *  \retval         other                               In case of RPC, this function may return the values
 *                                                      described for \ref Os_Api_ControlIdle.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Caller has already performed checks, which can be performed locally.
 *  \pre            Interrupts are enabled.
 *  \pre            Target object is located on receiver core.
 *  \pre            SendThread is the current thread.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE,
OS_ALWAYS_INLINE, Os_XSigSend_ControlIdle,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  CoreIdType CoreID,
  IdleModeType IdleMode
));


/***********************************************************************************************************************
 *  Os_XSigSend_GetKernelStackUsage()
 **********************************************************************************************************************/
/*! \brief          Send signal to perform the service GetKernelStackUsage on a foreign core.
 *  \details        --no details--
 *
 *  \param[in]      RecvCore        Pointer to the core configuration of the destination core.
 *                                  Parameter must not be NULL.
 *  \param[in]      SendThread      The user thread that called the API. Parameter must not be NULL.
 *  \param[in]      CoreID          As described for \ref Os_Api_GetKernelStackUsage.
 *  \param[out]     Result          The stack usage. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK                        No error.
 *  \retval         OS_STATUS_CALL_NOT_ALLOWED          No communication with that core allowed.
 *  \retval         OS_STATUS_FUNCTION_UNAVAILABLE      Destination ISR does not support this function.
 *  \retval         OS_STATUS_CALLEVEL_CROSS_CORE_SYNC  Synchronous request may not be send from the current context.
 *  \retval         other                               In case of RPC, this function may return the values
 *                                                      described for \ref Os_Api_GetKernelStackUsage.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Caller has already performed checks, which can be performed locally.
 *  \pre            Interrupts are enabled.
 *  \pre            Target object is located on receiver core.
 *  \pre            SendThread is the current thread.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_XSigSend_GetKernelStackUsage,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  CoreIdType CoreID,
  P2VAR(uint32, AUTOMATIC, OS_CONST) Result
));


/***********************************************************************************************************************
 *  Os_XSigSend_GetStartupHookStackUsage()
 **********************************************************************************************************************/
/*! \brief          Send signal to perform the service GetStartupHookStackUsage on a foreign core.
 *  \details        --no details--
 *
 *  \param[in]      RecvCore        Pointer to the core configuration of the destination core.
 *                                  Parameter must not be NULL.
 *  \param[in]      SendThread      The user thread that called the API. Parameter must not be NULL.
 *  \param[in]      CoreID          As described for \ref Os_Api_GetStartupHookStackUsage.
 *  \param[out]     Result          The stack usage. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK                        No error.
 *  \retval         OS_STATUS_CALL_NOT_ALLOWED          No communication with that core allowed.
 *  \retval         OS_STATUS_FUNCTION_UNAVAILABLE      Destination ISR does not support this function.
 *  \retval         OS_STATUS_CALLEVEL_CROSS_CORE_SYNC  Synchronous request may not be send from the current context.
 *  \retval         other                               In case of RPC, this function may return the values
 *                                                      described for \ref Os_Api_GetStartupHookStackUsage.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Caller has already performed checks, which can be performed locally.
 *  \pre            Interrupts are enabled.
 *  \pre            The given core has a startup hook configured.
 *  \pre            Target object is located on receiver core.
 *  \pre            SendThread is the current thread.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_XSigSend_GetStartupHookStackUsage,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  CoreIdType CoreID,
  P2VAR(uint32, AUTOMATIC, OS_CONST) Result
));


/***********************************************************************************************************************
 *  Os_XSigSend_GetErrorHookStackUsage()
 **********************************************************************************************************************/
/*! \brief          Send signal to perform the service GetErrorHookStackUsage on a foreign core.
 *  \details        --no details--
 *
 *  \param[in]      RecvCore        Pointer to the core configuration of the destination core.
 *                                  Parameter must not be NULL.
 *  \param[in]      SendThread      The user thread that called the API. Parameter must not be NULL.
 *  \param[in]      CoreID          As described for \ref Os_Api_GetErrorHookStackUsage.
 *  \param[out]     Result          The stack usage. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK                        No error.
 *  \retval         OS_STATUS_CALL_NOT_ALLOWED          No communication with that core allowed.
 *  \retval         OS_STATUS_FUNCTION_UNAVAILABLE      Destination ISR does not support this function.
 *  \retval         OS_STATUS_CALLEVEL_CROSS_CORE_SYNC  Synchronous request may not be send from the current context.
 *  \retval         other                               In case of RPC, this function may return the values
 *                                                      described for \ref Os_Api_GetErrorHookStackUsage.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Caller has already performed checks, which can be performed locally.
 *  \pre            Interrupts are enabled.
 *  \pre            The given core has a error hook configured.
 *  \pre            Target object is located on receiver core.
 *  \pre            SendThread is the current thread.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_XSigSend_GetErrorHookStackUsage,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  CoreIdType CoreID,
  P2VAR(uint32, AUTOMATIC, OS_CONST) Result
));


/***********************************************************************************************************************
 *  Os_XSigSend_GetShutdownHookStackUsage()
 **********************************************************************************************************************/
/*! \brief          Send signal to perform the service GetShutdownHookStackUsage on a foreign core.
 *  \details        --no details--
 *
 *  \param[in]      RecvCore        Pointer to the core configuration of the destination core.
 *                                  Parameter must not be NULL.
 *  \param[in]      SendThread      The user thread that called the API. Parameter must not be NULL.
 *  \param[in]      CoreID          As described for \ref Os_Api_GetShutdownHookStackUsage.
 *  \param[out]     Result          The stack usage. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK                        No error.
 *  \retval         OS_STATUS_CALL_NOT_ALLOWED          No communication with that core allowed.
 *  \retval         OS_STATUS_FUNCTION_UNAVAILABLE      Destination ISR does not support this function.
 *  \retval         OS_STATUS_CALLEVEL_CROSS_CORE_SYNC  Synchronous request may not be send from the current context.
 *  \retval         other                               In case of RPC, this function may return the values
 *                                                      described for \ref Os_Api_GetShutdownHookStackUsage.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Caller has already performed checks, which can be performed locally.
 *  \pre            Interrupts are enabled.
 *  \pre            The given core has a shutdown hook configured.
 *  \pre            Target object is located on receiver core.
 *  \pre            SendThread is the current thread.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_XSigSend_GetShutdownHookStackUsage,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  CoreIdType CoreID,
  P2VAR(uint32, AUTOMATIC, OS_CONST) Result
));


/***********************************************************************************************************************
 *  Os_XSigSend_GetProtectionHookStackUsage()
 **********************************************************************************************************************/
/*! \brief          Send signal to perform the service GetProtectionHookStackUsage on a foreign core.
 *  \details        --no details--
 *
 *  \param[in]      RecvCore        Pointer to the core configuration of the destination core.
 *                                  Parameter must not be NULL.
 *  \param[in]      SendThread      The user thread that called the API. Parameter must not be NULL.
 *  \param[in]      CoreID          As described for \ref Os_Api_GetProtectionHookStackUsage.
 *  \param[out]     Result          The stack usage. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK                        No error.
 *  \retval         OS_STATUS_CALL_NOT_ALLOWED          No communication with that core allowed.
 *  \retval         OS_STATUS_FUNCTION_UNAVAILABLE      Destination ISR does not support this function.
 *  \retval         OS_STATUS_CALLEVEL_CROSS_CORE_SYNC  Synchronous request may not be send from the current context.
 *  \retval         other                               In case of RPC, this function may return the values
 *                                                      described for \ref Os_Api_GetProtectionHookStackUsage.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Caller has already performed checks, which can be performed locally.
 *  \pre            Interrupts are enabled.
 *  \pre            The given core has a protection hook configured.
 *  \pre            Target object is located on receiver core.
 *  \pre            SendThread is the current thread.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_XSigSend_GetProtectionHookStackUsage,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  CoreIdType CoreID,
  P2VAR(uint32, AUTOMATIC, OS_CONST) Result
));


/***********************************************************************************************************************
 *  Os_XSigSend_TerminateApplication()
 **********************************************************************************************************************/
/*! \brief          Send signal to perform the service TerminateApplication on a foreign core.
 *  \details        --no details--
 *
 *  \param[in]      RecvCore                    Pointer to the core configuration of the destination core.
 *                                              Parameter must not be NULL.
 *  \param[in]      SendThread                  The user thread that called the API. Parameter must not be NULL.
 *  \param[in]      Application                 As described for \ref Os_Api_TerminateApplication.
 *  \param[in]      RestartOption               As described for \ref Os_Api_TerminateApplication.
 *  \param[in]      CurrentCallerApplicationId  The current application of the calling thread.
 *
 *  \retval         OS_STATUS_OK                        No error.
 *  \retval         OS_STATUS_CALL_NOT_ALLOWED          No communication with that core allowed.
 *  \retval         OS_STATUS_FUNCTION_UNAVAILABLE      Destination ISR does not support this function.
 *  \retval         OS_STATUS_CALLEVEL_CROSS_CORE_SYNC  Synchronous request may not be send from the current context.
 *  \retval         other                               In case of RPC, this function may return the values
 *                                                      described for \ref Os_Api_TerminateApplication.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Caller has already performed checks, which can be performed locally.
 *  \pre            Interrupts are enabled.
 *  \pre            Target object is located on receiver core.
 *  \pre            SendThread is the current thread.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_XSigSend_TerminateApplication,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  ApplicationType Application,
  RestartType RestartOption,
  ApplicationType CurrentCallerApplicationId
));


/***********************************************************************************************************************
 *  Os_XSigSend_GetApplicationState()
 **********************************************************************************************************************/
/*! \brief          Send signal to perform the service GetApplicationState on a foreign core.
 *  \details        --no details--
 *
 *  \param[in]      RecvCore        Pointer to the core configuration of the destination core.
 *                                  Parameter must not be NULL.
 *  \param[in]      SendThread      The user thread that called the API. Parameter must not be NULL.
 *  \param[in]      Application     As described for \ref Os_Api_GetApplicationState.
 *  \param[out]     Value           As described for \ref Os_Api_GetApplicationState.
 *
 *  \retval         OS_STATUS_OK                        No error.
 *  \retval         OS_STATUS_CALL_NOT_ALLOWED          No communication with that core allowed.
 *  \retval         OS_STATUS_FUNCTION_UNAVAILABLE      Destination ISR does not support this function.
 *  \retval         OS_STATUS_CALLEVEL_CROSS_CORE_SYNC  Synchronous request may not be send from the current context.
 *  \retval         other                               In case of RPC, this function may return the values
 *                                                      described for \ref Os_Api_GetApplicationState.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Caller has already performed checks, which can be performed locally.
 *  \pre            Interrupts are enabled.
 *  \pre            Target object is located on receiver core.
 *  \pre            SendThread is the current thread.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_XSigSend_GetApplicationState,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  ApplicationType Application,
  ApplicationStateRefType Value
));


/***********************************************************************************************************************
 *  Os_XSigSend_ShutdownAllCores()
 **********************************************************************************************************************/
/*! \brief          Send signal to perform the service ShutdownAllCores on a foreign core.
 *  \details        --no details--
 *
 *  \param[in]      RecvCore        Pointer to the core configuration of the destination core.
 *                                  Parameter must not be NULL.
 *  \param[in]      SendThread      The user thread that called the API. Parameter must not be NULL.
 *  \param[in]      Error           As described for \ref Os_SystemShutdown.
 *
 *  \retval         OS_STATUS_OK                        No error.
 *  \retval         OS_STATUS_CALL_NOT_ALLOWED          No communication with that core allowed.
 *  \retval         OS_STATUS_FUNCTION_UNAVAILABLE      Destination ISR does not support this function.
 *  \retval         OS_STATUS_CALLEVEL_CROSS_CORE_SYNC  Synchronous request may not be send from the current context.
 *  \retval         other                               In case of RPC, this function may return the values
 *                                                      described for \ref Os_SystemShutdown.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Caller has already performed checks, which can be performed locally.
 *  \pre            Target object is located on receiver core.
 *  \pre            SendThread is the current thread.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_XSigSend_ShutdownAllCores,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  StatusType Error
));


/***********************************************************************************************************************
 *  Os_XSigSend_HookCallCallbackAsync()
 **********************************************************************************************************************/
/*! \brief          Send signal to call a callback on a foreign core.
 *  \details        --no details--
 *
 *  \param[in]      RecvCore        Pointer to the core configuration of the destination core.
 *                                  Parameter must not be NULL.
 *  \param[in]      SendThread      The user thread that called the API. Parameter must not be NULL.
 *  \param[in]      Id      The ID of the callback to start.
 *
 *  \retval         OS_STATUS_OK                        No error.
 *  \retval         OS_STATUS_CALL_NOT_ALLOWED          No communication with that core allowed.
 *  \retval         OS_STATUS_FUNCTION_UNAVAILABLE      Destination ISR does not support this function.
 *  \retval         OS_STATUS_CALLEVEL_CROSS_CORE_SYNC  Synchronous request may not be send from the current context.
 *  \retval         other                               In case of RPC, this function may return the values
 *                                                      described for \ref Os_HookCallCallbackLocal.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Caller has already performed checks, which can be performed locally.
 *  \pre            Target object is located on receiver core.
 *  \pre            SendThread is the current thread.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_XSigSend_HookCallCallbackAsync,
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  Os_HookIdType Id
));


/**********************************************************************************************************************
 *  Os_XSigRecv_ActivateTask()
 **********************************************************************************************************************/
/*! \brief          Handler for the call of ActivateTask() from foreign core.
 *  \details        --no details--
 *
 *  \param[in]      SendApp       The sender application. Parameter must not be NULL.
 *  \param[in]      InParameter   The API call parameters. Parameter must not be NULL.
 *  \param[out]     OutParameter  The output data of the call. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_CORE_CROSS_DATA  Passed object id is invalid or
 *                                             does not belong to the receiver core.
 *  \retval         other                      Return values of \ref Os_TaskActivateLocalTask().
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different objects
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_ActivateTask
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
);


/***********************************************************************************************************************
 *  Os_XSigRecv_GetTaskState()
 **********************************************************************************************************************/
/*! \brief          Handler for the call of GetTaskState() from foreign core.
 *  \details        --no details--
 *
 *  \param[in]      SendApp       The sender application. Parameter must not be NULL.
 *  \param[in]      InParameter   The API call parameters. Parameter must not be NULL.
 *  \param[out]     OutParameter  The output data of the call. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_CORE_CROSS_DATA  Passed object id is invalid or
 *                                             does not belong to the receiver core.
 *  \retval         other                      Return values of \ref Os_TaskGetStateLocal()
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different objects
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_GetTaskState
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
);


/***********************************************************************************************************************
 *  Os_XSigRecv_GetCounterValue()
 **********************************************************************************************************************/
/*! \brief          Handler for the call of GetCounterValue() from foreign core.
 *  \details        --no details--
 *
 *  \param[in]      SendApp       The sender application. Parameter must not be NULL.
 *  \param[in]      InParameter   The API call parameters. Parameter must not be NULL.
 *  \param[out]     OutParameter  The output data of the call. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_CORE_CROSS_DATA  Passed object id is invalid or
 *                                             does not belong to the receiver core.
 *  \retval         other                      Return values of \ref Os_CounterGetUserValueLocal()
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different objects
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_GetCounterValue
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
);


/***********************************************************************************************************************
 *  Os_XSigRecv_SetEvent()
 **********************************************************************************************************************/
/*! \brief          Handler for the call of SetEvent() from foreign core.
 *  \details        --no details--
 *
 *  \param[in]      SendApp       The sender application. Parameter must not be NULL.
 *  \param[in]      InParameter   The API call parameters. Parameter must not be NULL.
 *  \param[out]     OutParameter  The output data of the call. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_CORE_CROSS_DATA  Passed object id is invalid or
 *                                             does not belong to the receiver core.
 *  \retval         other                      Return values of \ref Os_EventSetLocal()
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different objects
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_SetEvent
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
);


/***********************************************************************************************************************
 *  Os_XSigRecv_GetEvent()
 **********************************************************************************************************************/
/*! \brief          Handler for the call of GetEvent() from foreign core.
 *  \details        --no details--
 *
 *  \param[in]      SendApp       The sender application. Parameter must not be NULL.
 *  \param[in]      InParameter   The API call parameters. Parameter must not be NULL.
 *  \param[out]     OutParameter  The output data of the call. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_CORE_CROSS_DATA  Passed object id is invalid or
 *                                             does not belong to the receiver core.
 *  \retval         other                      Return values of \ref Os_EventGetLocal()
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different objects
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_GetEvent
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
);


/***********************************************************************************************************************
 *  Os_XSigRecv_GetAlarm()
 **********************************************************************************************************************/
/*! \brief          Handler for the call of GetAlarm() from foreign core.
 *  \details        --no details--
 *
 *  \param[in]      SendApp       The sender application. Parameter must not be NULL.
 *  \param[in]      InParameter   The API call parameters. Parameter must not be NULL.
 *  \param[out]     OutParameter  The output data of the call. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_CORE_CROSS_DATA  Passed object id is invalid or
 *                                             does not belong to the receiver core.
 *  \retval         other                      Return values of \ref Os_AlarmGetAlarmLocal()
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different objects
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_GetAlarm
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
);


/***********************************************************************************************************************
 *  Os_XSigRecv_SetRelAlarm()
 **********************************************************************************************************************/
/*! \brief          Handler for the call of SetRelAlarm() from foreign core.
 *  \details        --no details--
 *
 *  \param[in]      SendApp       The sender application. Parameter must not be NULL.
 *  \param[in]      InParameter   The API call parameters. Parameter must not be NULL.
 *  \param[out]     OutParameter  The output data of the call. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_CORE_CROSS_DATA  Passed object id is invalid or
 *                                             does not belong to the receiver core.
 *  \retval         other                      Return values of \ref Os_AlarmSetRelAlarmLocal()
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different objects
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_SetRelAlarm
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
);


/***********************************************************************************************************************
 *  Os_XSigRecv_SetAbsAlarm()
 **********************************************************************************************************************/
/*! \brief          Handler for the call of SetAbsAlarm() from foreign core.
 *  \details        --no details--
 *
 *  \param[in]      SendApp       The sender application. Parameter must not be NULL.
 *  \param[in]      InParameter   The API call parameters. Parameter must not be NULL.
 *  \param[out]     OutParameter  The output data of the call. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_CORE_CROSS_DATA  Passed object id is invalid or
 *                                             does not belong to the receiver core.
 *  \retval         other                      Return values of \ref Os_AlarmSetAbsAlarmLocal()
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different objects
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_SetAbsAlarm
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
);


/***********************************************************************************************************************
 *  Os_XSigRecv_CancelAlarm()
 **********************************************************************************************************************/
/*! \brief          Handler for the call of CancelAlarm() from foreign core.
 *  \details        --no details--
 *
 *  \param[in]      SendApp       The sender application. Parameter must not be NULL.
 *  \param[in]      InParameter   The API call parameters. Parameter must not be NULL.
 *  \param[out]     OutParameter  The output data of the call. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_CORE_CROSS_DATA  Passed object id is invalid or
 *                                             does not belong to the receiver core.
 *  \retval         other                      Return values of \ref Os_AlarmCancelAlarmLocal()
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different objects
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_CancelAlarm
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
);


/***********************************************************************************************************************
 *  Os_XSigRecv_StartScheduleTableRel()
 **********************************************************************************************************************/
/*! \brief          Handler for the call of StartScheduleTableRel() from foreign core.
 *  \details        --no details--
 *
 *  \param[in]      SendApp       The sender application. Parameter must not be NULL.
 *  \param[in]      InParameter   The API call parameters. Parameter must not be NULL.
 *  \param[out]     OutParameter  The output data of the call. Parameter must not be NULL.
 *
 *  \return         The status of the call.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different objects
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_StartScheduleTableRel
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
);


/***********************************************************************************************************************
 *  Os_XSigRecv_StartScheduleTableAbs()
 **********************************************************************************************************************/
/*! \brief          Handler for the call of StartScheduleTableAbs() from foreign core.
 *  \details        --no details--
 *
 *  \param[in]      SendApp       The sender application. Parameter must not be NULL.
 *  \param[in]      InParameter   The API call parameters. Parameter must not be NULL.
 *  \param[out]     OutParameter  The output data of the call. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_CORE_CROSS_DATA  Passed object id is invalid or
 *                                             does not belong to the receiver core.
 *  \retval         other                      Return values of \ref Os_SchTStartScheduleTableAbsLocal().
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different objects
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_StartScheduleTableAbs
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
);


/***********************************************************************************************************************
 *  Os_XSigRecv_StopScheduleTable()
 **********************************************************************************************************************/
/*! \brief          Handler for the call of StopScheduleTable() from foreign core.
 *  \details        --no details--
 *
 *  \param[in]      SendApp       The sender application. Parameter must not be NULL.
 *  \param[in]      InParameter   The API call parameters. Parameter must not be NULL.
 *  \param[out]     OutParameter  The output data of the call. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_CORE_CROSS_DATA  Passed object id is invalid or
 *                                             does not belong to the receiver core.
 *  \retval         other                      Return values of \ref Os_SchTStopScheduleTableLocal().
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different objects
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_StopScheduleTable
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
);


/***********************************************************************************************************************
 *  Os_XSigRecv_NextScheduleTable()
 **********************************************************************************************************************/
/*! \brief          Handler for the call of NextScheduleTable() from foreign core.
 *  \details        --no details--
 *
 *  \param[in]      SendApp       The sender application. Parameter must not be NULL.
 *  \param[in]      InParameter   The API call parameters. Parameter must not be NULL.
 *  \param[out]     OutParameter  The output data of the call. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_CORE_CROSS_DATA  Passed object id is invalid or
 *                                             does not belong to the receiver core.
 *  \retval         other                      Return values of \ref Os_SchTNextScheduleTableLocal().
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different objects
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_NextScheduleTable
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
);


/***********************************************************************************************************************
 *  Os_XSigRecv_GetScheduleTableStatus()
 **********************************************************************************************************************/
/*! \brief          Handler for the call of GetScheduleTableStatus() from foreign core.
 *  \details        --no details--
 *
 *  \param[in]      SendApp       The sender application. Parameter must not be NULL.
 *  \param[in]      InParameter   The API call parameters. Parameter must not be NULL.
 *  \param[out]     OutParameter  The output data of the call. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_CORE_CROSS_DATA  Passed object id is invalid or
 *                                             does not belong to the receiver core.
 *  \retval         other                      Return values of \ref Os_SchTGetScheduleTableStatusLocal().
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different objects
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_GetScheduleTableStatus
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
);


/***********************************************************************************************************************
 *  Os_XSigRecv_GetTaskStackUsage()
 **********************************************************************************************************************/
/*! \brief          Handler for the call of GetTaskStackUsage() from foreign core.
 *  \details        --no details--
 *
 *  \param[in]      SendApp       The sender application. Parameter must not be NULL.
 *  \param[in]      InParameter   The API call parameters. Parameter must not be NULL.
 *  \param[out]     OutParameter  The output data of the call. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK               No error.
 *  \retval         OS_STATUS_CORE_CROSS_DATA  Passed object id is invalid or
 *                                             does not belong to the receiver core.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different objects
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_GetTaskStackUsage
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
);


/***********************************************************************************************************************
 *  Os_XSigRecv_GetISRStackUsage()
 **********************************************************************************************************************/
/*! \brief          Handler for the call of GetISRStackUsage() from foreign core.
 *  \details        --no details--
 *
 *  \param[in]      SendApp       The sender application. Parameter must not be NULL.
 *  \param[in]      InParameter   The API call parameters. Parameter must not be NULL.
 *  \param[out]     OutParameter  The output data of the call. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK               No error.
 *  \retval         OS_STATUS_CORE_CROSS_DATA  Passed object id is invalid or
 *                                             does not belong to the receiver core.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different objects
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_GetISRStackUsage
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
);


/***********************************************************************************************************************
 *  Os_XSigRecv_ControlIdle()
 **********************************************************************************************************************/
/*! \brief          Handler for the call of ControlIdle() from foreign core.
 *  \details        --no details--
 *
 *  \param[in]      SendApp       The sender application. Parameter must not be NULL.
 *  \param[in]      InParameter   The API call parameters. Parameter must not be NULL.
 *  \param[out]     OutParameter  The output data of the call. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK               No error.
 *  \retval         OS_STATUS_CORE_CROSS_DATA  Passed object id is invalid or
 *                                             does not belong to the receiver core.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different objects
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_ControlIdle
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
);


/***********************************************************************************************************************
 *  Os_XSigRecv_GetKernelStackUsage()
 **********************************************************************************************************************/
/*! \brief          Handler for the call of GetKernelStackUsage() from foreign core.
 *  \details        --no details--
 *
 *  \param[in]      SendApp       The sender application. Parameter must not be NULL.
 *  \param[in]      InParameter   The API call parameters. Parameter must not be NULL.
 *  \param[out]     OutParameter  The output data of the call. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK               No error.
 *  \retval         OS_STATUS_CORE_CROSS_DATA  Passed object id is invalid or
 *                                             does not belong to the receiver core.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different objects
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_GetKernelStackUsage
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
);


/***********************************************************************************************************************
 *  Os_XSigRecv_GetStartupHookStackUsage()
 **********************************************************************************************************************/
/*! \brief          Handler for the call of GetStartupHookStackUsage() from foreign core.
 *  \details        --no details--
 *
 *  \param[in]      SendApp       The sender application. Parameter must not be NULL.
 *  \param[in]      InParameter   The API call parameters. Parameter must not be NULL.
 *  \param[out]     OutParameter  The output data of the call. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK               No error.
 *  \retval         OS_STATUS_CORE_CROSS_DATA  Passed object id is invalid or
 *                                             does not belong to the receiver core.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different objects
 *  \synchronous    TRUE
 *
 *  \pre            The given core has a startup hook configured.
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_GetStartupHookStackUsage
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
);


/***********************************************************************************************************************
 *  Os_XSigRecv_GetErrorHookStackUsage()
 **********************************************************************************************************************/
/*! \brief          Handler for the call of GetErrorHookStackUsage() from foreign core.
 *  \details        --no details--
 *
 *  \param[in]      SendApp       The sender application. Parameter must not be NULL.
 *  \param[in]      InParameter   The API call parameters. Parameter must not be NULL.
 *  \param[out]     OutParameter  The output data of the call. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK               No error.
 *  \retval         OS_STATUS_CORE_CROSS_DATA  Passed object id is invalid or
 *                                             does not belong to the receiver core.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different objects
 *  \synchronous    TRUE
 *
 *  \pre            The given core has a error hook configured.
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_GetErrorHookStackUsage
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
);


/***********************************************************************************************************************
 *  Os_XSigRecv_GetShutdownHookStackUsage()
 **********************************************************************************************************************/
/*! \brief          Handler for the call of GetShutdownHookStackUsage() from foreign core.
 *  \details        --no details--
 *
 *  \param[in]      SendApp       The sender application. Parameter must not be NULL.
 *  \param[in]      InParameter   The API call parameters. Parameter must not be NULL.
 *  \param[out]     OutParameter  The output data of the call. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK               No error.
 *  \retval         OS_STATUS_CORE_CROSS_DATA  Passed object id is invalid or
 *                                             does not belong to the receiver core.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different objects
 *  \synchronous    TRUE
 *
 *  \pre            The given core has a shutdown hook configured.
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_GetShutdownHookStackUsage
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
);


/***********************************************************************************************************************
 *  Os_XSigRecv_GetProtectionHookStackUsage()
 **********************************************************************************************************************/
/*! \brief          Handler for the call of GetProtectionHookStackUsage() from foreign core.
 *  \details        --no details--
 *
 *  \param[in]      SendApp       The sender application. Parameter must not be NULL.
 *  \param[in]      InParameter   The API call parameters. Parameter must not be NULL.
 *  \param[out]     OutParameter  The output data of the call. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK               No error.
 *  \retval         OS_STATUS_CORE_CROSS_DATA  Passed object id is invalid or
 *                                             does not belong to the receiver core.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different objects
 *  \synchronous    TRUE
 *
 *  \pre            The given core has a protection hook configured.
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_GetProtectionHookStackUsage
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
);


/***********************************************************************************************************************
 *  Os_XSigRecv_TerminateApplication()
 **********************************************************************************************************************/
/*! \brief          Handler for the call of TerminateApplication() from foreign core.
 *  \details        --no details--
 *
 *  \param[in]      SendApp       The sender application. Parameter must not be NULL.
 *  \param[in]      InParameter   The API call parameters. Parameter must not be NULL.
 *  \param[out]     OutParameter  The output data of the call. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_CORE_CROSS_DATA  Passed object id is invalid or
 *                                             does not belong to the receiver core.
 *  \retval         other                      Return values of \ref Os_AppTerminateApplicationLocal().
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different objects
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_TerminateApplication
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
);


/***********************************************************************************************************************
 *  Os_XSigRecv_GetApplicationState()
 **********************************************************************************************************************/
/*! \brief          Handler for the call of GetApplicationState() from foreign core.
 *  \details        --no details--
 *
 *  \param[in]      SendApp       The sender application. Parameter must not be NULL.
 *  \param[in]      InParameter   The API call parameters. Parameter must not be NULL.
 *  \param[out]     OutParameter  The output data of the call. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_CORE_CROSS_DATA  Passed object id is invalid or
 *                                             does not belong to the receiver core.
 *  \retval         other                      Return values of \ref Os_AppGetApplicationStateLocal().
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different objects
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_GetApplicationState
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
);


/***********************************************************************************************************************
 *  Os_XSigRecv_ShutdownAllCores()
 **********************************************************************************************************************/
/*! \brief          Handler for the call of ShutdownAllCores() from foreign core.
 *  \details        --no details--
 *
 *  \param[in]      SendApp       The sender application. Parameter must not be NULL.
 *  \param[in]      InParameter   The API call parameters. Parameter must not be NULL.
 *  \param[out]     OutParameter  The output data of the call. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK  No Error.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different objects
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_ShutdownAllCores
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
);


/**********************************************************************************************************************
 *  Os_XSigRecv_HookCallCallback()
 **********************************************************************************************************************/
/*! \brief          Handler for the call of Os_HookCallCallbackLocal() from foreign core.
 *  \details        --no details--
 *
 *  \param[in]      SendApp       The sender application. Parameter must not be NULL.
 *  \param[in]      InParameter   The API call parameters. Parameter must not be NULL.
 *  \param[out]     OutParameter  The output data of the call. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_CORE_CROSS_DATA  Passed object id is invalid or
 *                                             does not belong to the receiver core.
 *  \retval         other                      Return values of \ref Os_HookCallCallbackLocal().
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different objects
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_HookCallCallback
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
);


/***********************************************************************************************************************
 *  ISR(Os_XSigRecvIsrHandler)
 **********************************************************************************************************************/
/*! \brief          Handles XSignal category 2 receive interrupts.
 *  \details        The receiver ISR scans each assigned receiver port for incoming data. Scanning is performed based on
 *                  the round robin principle. If a port has incoming data, the requested receiver function is called.
 *                  If within one scan cycle, none of the ports holds data, the ISR returns.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different XSignal receive interrupt configurations.
 *  \synchronous    TRUE
 *
 *  \pre            Current thread is an XSig receiver ISR.
 **********************************************************************************************************************/
ISR(Os_XSigRecvIsrHandler);

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_XSIGNALINT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_XSignalInt.h
 **********************************************************************************************************************/
