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
 * \brief       Implementation of cross core signals.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777, 0779, 0828  EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */


#define OS_XSIGNAL_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_XSignal.h"

/* Os kernel module dependencies */
#include "Os_Cfg.h"
#include "Os_Common_Types.h"
#include "Os_Task_Types.h"
#include "Os_Task.h"
#include "Os_Event.h"
#include "Os_Thread.h"
#include "Os_Isr.h"
#include "Os_Counter.h"
#include "Os_XSignalChannel.h"
#include "Os_Error.h"
#include "Os_Alarm.h"
#include "Os_ScheduleTable.h"
#include "Os_Stack.h"
#include "Os_Hook.h"

/* Os hal dependencies */
#include "Os_Hal_Compiler.h"


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

#define OS_START_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */
/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  Os_XSigGetSendPort()
 **********************************************************************************************************************/
/*! \brief        Returns the send port which is connected to the receiver.
 *  \details      --no details--
 *
 *  \param[in]    XSignal     The XSignal to query. Parameter must not be NULL.
 *  \param[in]    SendPortIdx The index of the connection (equal to the Autosar core index of the receiver core).
 *                            The index must be < OS_COREASRCOREIDX_COUNT.
 *
 *  \return       The send port which is connected to the given receiver core.
 *  \retval       NULL_PTR    If there is no connection to the requested core.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_XSigSendPortConfigType, AUTOMATIC, OS_CONST),
OS_CODE, OS_ALWAYS_INLINE, Os_XSigGetSendPort,
(
  P2CONST(Os_XSigConfigType, AUTOMATIC, OS_CONST) XSignal,
  Os_CoreAsrCoreIdx SendPortIdx
));


/***********************************************************************************************************************
 *  Os_XSigGetRecvIsrCount()
 **********************************************************************************************************************/
/*! \brief        Returns the number of ISRs assigned to the XSignal instance.
 *  \details      --no details--
 *
 *  \param[in]    XSignal     The XSignal to query. Parameter must not be NULL.
 *
 *  \return       The number of ISRs assigned to the XSignal instance.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_ObjIdxType, OS_CODE, OS_ALWAYS_INLINE, Os_XSigGetRecvIsrCount,
(
  P2CONST(Os_XSigConfigType, AUTOMATIC, OS_CONST) XSignal
));



/***********************************************************************************************************************
 *  Os_XSigGetRecvIsr()
 **********************************************************************************************************************/
/*! \brief        Returns the requested ISR.
 *  \details      --no details--
 *
 *  \param[in]    XSignal     The XSignal to query. Parameter must not be NULL.
 *  \param[in]    IsrIdx      The index of the ISR. Parameter must be < XSignal->RecvIsrCount.
 *
 *  \return       The requested ISR.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_XSigIsrConfigType, TYPEDEF, OS_CONST),
OS_CODE, OS_ALWAYS_INLINE, Os_XSigGetRecvIsr,
(
  P2CONST(Os_XSigConfigType, AUTOMATIC, OS_CONST) XSignal,
  Os_ObjIdxType IsrIdx
));


/***********************************************************************************************************************
 *  Os_XSigGetSendPortToCore()
 **********************************************************************************************************************/
/*! \brief        Returns the send port which is connected to the receiver.
 *  \details      --no details--
 *
 *  \param[in]    SendThread  The XSignal sender thread. Parameter must not be NULL.
 *  \param[in]    RecvCore    The XSignal receiver core. Parameter must not be NULL.
 *
 *  \return       The send port which is connected to the given receiver core.
 *  \retval       NULL_PTR    If there is no connection to the requested core.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          XSignal is enabled.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_XSigSendPortConfigType, AUTOMATIC, OS_CONST),
OS_CODE, OS_ALWAYS_INLINE, Os_XSigGetSendPortToCore,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore
));


/***********************************************************************************************************************
 *  Os_XSigRecvCheckIsFunctionAvailable()
 **********************************************************************************************************************/
/*! \brief        Checks whether the given function is available.
 *  \details      --no details--
 *
 *  \param[in]    XSigIsr           XSignal to query. Parameter must not be NULL.
 *  \param[in]    FunctionIdx       The index of the function.
 *
 *  \context      OS_INTERNAL
 *
 *  \retval       !OS_CHECK_FAILED  Function is available.
 *  \retval       OS_CHECK_FAILED   Function is not available.
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          The given index is in a valid range.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_XSigRecvCheckIsFunctionAvailable,
(
  P2CONST(Os_XSigIsrConfigType, AUTOMATIC, OS_CONST) XSigIsr,
  Os_XSigFunctionIdx FunctionIdx
));


/***********************************************************************************************************************
 *  Os_XSigRecvCheckIsReceiveElementValid()
 **********************************************************************************************************************/
/*! \brief        Checks whether the given element is valid.
 *  \details      --no details--
 *
 *  \param[in]    XSigRecvElement   Rec. Parameter must not be NULL.
 *
 *  \context      OS_INTERNAL
 *
 *  \retval       !0                Element is valid
 *  \retval       0                 Element is not available.
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          The given index is in a valid range.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_XSigRecvCheckIsReceiveElementValid,
(
    P2CONST(Os_XSigComDataConfigType, AUTOMATIC, OS_VAR_NOINIT) XSigRecvElement
));


/***********************************************************************************************************************
 *  Os_XSigSendInternal()
 **********************************************************************************************************************/
/*! \brief          Sets a given parameter in a parameter object.
 *  \details        The ComData reference is valid, if the returned value is OS_STATUS_OK.
 *
 *  \param[in,out]  SendPort      The send port to write to. Parameter must not be NULL.
 *  \param[in]      SendThread    The sender of the cross core request. Parameter must not be NULL.
 *  \param[in]      FunctionIdx   The function to call.
 *  \param[in]      Parameters    The parameters which are passed to the function. Parameter must not be NULL.
 *  \param[in]      Acknowledge   The acknowledge value of the request.
 *  \param[out]     ComData       The ComData object which has been used for data transmission.
 *                                Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK        Transmission done.
 *  \retval         OS_STATUS_OVERFLOW  No free sending element available.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE,
OS_ALWAYS_INLINE, Os_XSigSendInternal,
(
  P2CONST(Os_XSigSendPortConfigType, AUTOMATIC, OS_CONST) SendPort,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  Os_XSigFunctionIdx FunctionIdx,
  P2CONST(Os_XSigParamsType, AUTOMATIC, TYPEDEF) Parameters,
  Os_XSigState_Type Acknowledge,
  P2VAR(Os_XSigComDataConfigRefType, AUTOMATIC, OS_VAR_NOINIT) ComData
));


/***********************************************************************************************************************
 *  Os_XSigFunctionIdx2SerciceId()
 **********************************************************************************************************************/
/*! \brief        Converts a function index into a service identifier.
 *  \details      --no details--
 *
 *  \param[in]    FunctionIdx    The function index to convert into a service identifier.
 *                               FunctionIdx must be < OS_XSIGFUNCTIONIDX_USEDCOUNT.
 *
 *  \return       The service identifier.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE OSServiceIdType, OS_CODE, OS_ALWAYS_INLINE, Os_XSigFunctionIdx2SerciceId,
(
  Os_XSigFunctionIdx FunctionIdx
));


/***********************************************************************************************************************
 *  Os_XSigHandleResults
 **********************************************************************************************************************/
/*! \brief        Handles all returned results of asynchronous requests.
 *  \details      --no details--
 *
 *  \param[in]    SendChannel    The send buffer that's results are handled. Parameter must not be NULL.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 *
 *  \trace        SPEC-63727
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_XSigHandleResults,
(
  P2CONST(Os_XSigChannelSendConfigType, TYPEDEF, OS_CONST) SendChannel
));


/***********************************************************************************************************************
 *  Os_XSigSendPortInit()
 **********************************************************************************************************************/
/*! \brief        Initializes the given send port (Init-Step4).
 *  \details      --no details--
 *
 *  \param[in,out]    SendPort    The send port to initialize. NULL_PTR is allowed.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_XSigSendPortInit,
(
  P2CONST(Os_XSigSendPortConfigType, AUTOMATIC, OS_CONST) SendPort
));


/***********************************************************************************************************************
 *  Os_XSigRecvPortInit()
 **********************************************************************************************************************/
/*! \brief        Initializes the given receive port (Init-Step4).
 *  \details      --no details--
 *
 *  \param[in,out]    RecvPort    The receive port to initialize. Parameter must not be NULL.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_XSigRecvPortInit,
(
  P2CONST(Os_XSigRecvPortConfigType, AUTOMATIC, OS_CONST) RecvPort
));


/***********************************************************************************************************************
 *  Os_XSigIsrInit()
 **********************************************************************************************************************/
/*! \brief          Initializes the given ISR (Init-Step4).
 *  \details        --no details--
 *
 *  \param[in,out]  XSigIsr    The ISR to initialize. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_XSigIsrInit,
(
  P2CONST(Os_XSigIsrConfigType, AUTOMATIC, OS_CONST) XSigIsr
));


/***********************************************************************************************************************
 *  Os_XSigThread2XSigIsr()
 **********************************************************************************************************************/
/*! \brief          Returns the XSiganl ISR corresponding to a thread.
 *  \details        --no details--
 *
 *  \param[in]      Thread  Thread which shall be converted. Parameter must not be NULL.
 *
 *  \context        ISR2
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Given thread is a XSignal ISR.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_XSigIsrConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_XSigThread2XSigIsr,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  Os_XSigGetSendPort()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2CONST(Os_XSigSendPortConfigType, AUTOMATIC, OS_CONST),
OS_CODE, OS_ALWAYS_INLINE, Os_XSigGetSendPort,
(
  P2CONST(Os_XSigConfigType, AUTOMATIC, OS_CONST) XSignal,
  Os_CoreAsrCoreIdx SendPortIdx
))
{
  Os_Assert(Os_ErrIsValueLo((uint32)SendPortIdx, (uint32)OS_COREASRCOREIDX_COUNT));
  return XSignal->SendPorts[SendPortIdx];                                                                               /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842_Precondition */
}



/***********************************************************************************************************************
 *  Os_XSigGetRecvIsrCount()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_ObjIdxType, OS_CODE, OS_ALWAYS_INLINE, Os_XSigGetRecvIsrCount,
(
  P2CONST(Os_XSigConfigType, AUTOMATIC, OS_CONST) XSignal
))
{
  return XSignal->RecvIsrCount;
}



/***********************************************************************************************************************
 *  Os_XSigGetRecvIsr()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2CONST(Os_XSigIsrConfigType, TYPEDEF, OS_CONST),
OS_CODE, OS_ALWAYS_INLINE, Os_XSigGetRecvIsr,
(
  P2CONST(Os_XSigConfigType, AUTOMATIC, OS_CONST) XSignal,
  Os_ObjIdxType IsrIdx
))
{
  Os_Assert((Os_StdReturnType)(IsrIdx < Os_XSigGetRecvIsrCount(XSignal)));                                              /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */ /* SBSW_OS_FC_PRECONDITION */
  return XSignal->RecvIsrRefs[IsrIdx];
}


/***********************************************************************************************************************
 *  Os_XSigGetSendPortToCore()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2CONST(Os_XSigSendPortConfigType, AUTOMATIC, OS_CONST),                   /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
OS_CODE, OS_ALWAYS_INLINE, Os_XSigGetSendPortToCore,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) sendCore;
  P2CONST(Os_XSigConfigType, AUTOMATIC, OS_CONST) xSignal;
  Os_CoreAsrCoreIdx recvCoreIdx;

  recvCoreIdx = Os_CoreGetAsrCoreIdx(RecvCore);                                                                         /* SBSW_OS_FC_PRECONDITION */
  sendCore = Os_ThreadGetCore(SendThread);                                                                              /* SBSW_OS_FC_PRECONDITION */

  /* #10 Get the XSignal of the sending core. */
  xSignal = Os_CoreGetXSig(sendCore);                                                                                   /* SBSW_OS_XSIG_COREGETXSIG_001 */

  Os_Assert(Os_ErrIsValueLo((uint32)recvCoreIdx, (uint32)OS_COREASRCOREIDX_COUNT));

  /* #20 Get the send port which is connected to the receiving core. */
  return Os_XSigGetSendPort(xSignal, recvCoreIdx);                                                                      /* SBSW_OS_XSIG_XSIGGETSENDPORT_001 */
}


/***********************************************************************************************************************
 *  Os_XSigRecvCheckIsFunctionAvailable()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
Os_XSigRecvCheckIsFunctionAvailable,
(
  P2CONST(Os_XSigIsrConfigType, AUTOMATIC, OS_CONST) XSigIsr,
  Os_XSigFunctionIdx FunctionIdx
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_StdReturnType result;

  result = OS_CHECK_FAILED;

  if(OS_UNLIKELY(Os_ErrIsValueLo((uint32)FunctionIdx, (uint32)OS_XSIGFUNCTIONIDX_USEDCOUNT) != 0u))
  {
    result = (Os_StdReturnType)(XSigIsr->FunctionTable->FunctionDescription[FunctionIdx].FunctionRef != NULL_PTR);      /* PRQA S 2842, 4304 */ /* MD_Os_Rule18.1_2842_Precondition, MD_Os_C90BooleanCompatibility */
  }

  return result;
}


/***********************************************************************************************************************
 *  Os_XSigRecvCheckIsReceiveElementValid()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
Os_XSigRecvCheckIsReceiveElementValid,
(
    P2CONST(Os_XSigComDataConfigType, AUTOMATIC, OS_VAR_NOINIT) XSigRecvElement
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
        /*! Internal comment removed.
 *
 *
 *
 *
         */
  /* #10 Check that the received element is not acknowledged by the sender. */
  return (Os_StdReturnType) ( (XSigRecvElement->SendData->Acknowledge == OS_XSIGSTATE_ASYNC_NACK) ||                    /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
                              (XSigRecvElement->SendData->Acknowledge == OS_XSIGSTATE_SYNC_NACK ) );
}

/***********************************************************************************************************************
 *  Os_XSigSendInternal()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE,                                                    /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
OS_ALWAYS_INLINE, Os_XSigSendInternal,
(
  P2CONST(Os_XSigSendPortConfigType, AUTOMATIC, OS_CONST) SendPort,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  Os_XSigFunctionIdx FunctionIdx,
  P2CONST(Os_XSigParamsType, AUTOMATIC, TYPEDEF) Parameters,
  Os_XSigState_Type Acknowledge,
  P2VAR(Os_XSigComDataConfigRefType, AUTOMATIC, OS_VAR_NOINIT) ComData
))                                                                                                                      /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
{
  Os_StatusType status;
  Os_IntStateType interruptState;

  /* #10 Suspend interrupts. */
  Os_IntSuspend(&interruptState);                                                                                       /* SBSW_OS_FC_POINTER2LOCAL */

  {
    /* #20 Free the result buffer. */
    Os_XSigHandleResults(&(SendPort->SendChannel));                                                                     /* SBSW_OS_FC_PRECONDITION */

    /* #30 Get a communication data element from the queue and initialize it. */
    *ComData = Os_XSigChannelGetSendElement(&(SendPort->SendChannel));                                                  /* SBSW_OS_PWA_PRECONDITION */ /* SBSW_OS_FC_PRECONDITION */

    /* #40 Check that the sender queue is not full. */
    if(OS_UNLIKELY(*ComData == NULL_PTR))
    {
      status = OS_STATUS_OVERFLOW;
    }
    else
    {
      (*ComData)->SendData->FunctionIdx = FunctionIdx;                                                                  /* SBSW_OS_XSIG_SENDDATA_001 */
      (*ComData)->SendData->Acknowledge = Acknowledge;                                                                  /* SBSW_OS_XSIG_SENDDATA_001 */
      (*ComData)->SendData->ParameterData = *Parameters;                                                                /* SBSW_OS_XSIG_SENDDATA_001 */
      (*ComData)->SendData->Sender = SendThread;                                                                        /* SBSW_OS_XSIG_SENDDATA_001 */
      (*ComData)->SendData->SenderApp = Os_ThreadGetCurrentApplication(SendThread);                                     /* SBSW_OS_XSIG_SENDDATA_001 */ /* SBSW_OS_FC_PRECONDITION */

      /* #50 Send the data element and trigger the receiver. */
      Os_XSigChannelSend(&(SendPort->SendChannel));                                                                     /* SBSW_OS_FC_PRECONDITION */
      Os_Hal_XSigTrigger(SendPort->XSigIsr->HwConfig);                                                                  /* SBSW_OS_XSIG_HAL_XSIGTRIGGER_001 */

      status = OS_STATUS_OK;
    }
  }

  /* #60 Resume interrupts. */
  Os_IntResume(&interruptState);                                                                                        /* SBSW_OS_FC_POINTER2LOCAL */
  return status;
}                                                                                                                       /* PRQA S 6060 */ /* MD_Os_STPAR */


/***********************************************************************************************************************
 *  Os_XSigFunctionIdx2SerciceId()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE OSServiceIdType, OS_CODE, OS_ALWAYS_INLINE, Os_XSigFunctionIdx2SerciceId,  /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
  Os_XSigFunctionIdx FunctionIdx
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_Assert(Os_ErrIsValueLo((uint32)FunctionIdx, (uint32)OS_XSIGFUNCTIONIDX_USEDCOUNT));
  return OsCfg_XSig_ServiceMap[FunctionIdx];                                                                            /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842_Precondition */
}


/***********************************************************************************************************************
 *  Os_XSigHandleResults
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_XSigHandleResults,                     /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
  P2CONST(Os_XSigChannelSendConfigType, TYPEDEF, OS_CONST) SendChannel
))                                                                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  Os_StatusType status;

  /* #10 Loop while there are results in the buffer. */
  while(Os_XSigChannelIsResultAvailable(SendChannel) != 0u)                                                             /* SBSW_OS_FC_PRECONDITION */
  {
    P2CONST(Os_XSigComDataConfigType, AUTOMATIC, OS_CONST) comData;

    comData = Os_XSigChannelGetResult(SendChannel);                                                                     /* SBSW_OS_FC_PRECONDITION */

    /* #20 If the request is an asynchronous one: */
    if(comData->SendData->Acknowledge == OS_XSIGSTATE_ASYNC_NACK)
    {
      status = comData->RecvData->ReturnData.Status;

      /* #30 If the request status indicates an error: */
      if(OS_UNLIKELY(status != OS_STATUS_OK))
      {
        /*! Internal comment removed.
 *
 * */
        Os_ErrorParmIndexType idx;
        OSServiceIdType serviceId;
        Os_ErrorParamsType errorParameters;

        serviceId = Os_XSigFunctionIdx2SerciceId(comData->SendData->FunctionIdx);

        /* Copy the parameters in a loop because the request may contain more parameters
         * than the error module can handle. */
        /*! Internal comment removed.
 *
 * */
        for(idx = (Os_ErrorParmIndexType)0; idx < OS_ERRORPARAMINDEX_COUNT; ++idx)                                      /* PRQA S 4332,  4527 */ /* MD_Os_Rule10.5_4332,  MD_Os_Rule10.1_4527 */
        {
          errorParameters.Parameter[idx] = comData->SendData->ParameterData.ParameterData[idx];                         /* SBSW_OS_XSIG_ERRORPARAMETER_001 */
        }

        /* #40 Report service, status and call parameters to the error module. */
        /*! Internal comment removed.
 *
 * */
        Os_ErrApplicationError(serviceId, status, &errorParameters);                                                    /* SBSW_OS_FC_POINTER2LOCAL */
      }

      /* #50 Mark the buffer element as unused. */
      comData->SendData->Acknowledge = OS_XSIGSTATE_ACK;                                                                /* SBSW_OS_XSIG_XSIGCHANNELGETRESULT_001 */
    }
    /* #60 Otherwise if the result is a synchronous one: */
    else if(comData->SendData->Acknowledge ==  OS_XSIGSTATE_SYNC_NACK)
    {
      /* #70 Set the state to pending. It will be handled by the sender.*/
       comData->SendData->Acknowledge = OS_XSIGSTATE_SYNC_PENDING;                                                      /* SBSW_OS_XSIG_XSIGCHANNELGETRESULT_001 */
    }
    else /* The MISRA-else */
    {
       /* OS_XSIGSTATE_ACK don't require any action. */
       /* OS_XSIGSTATE_SYNC_PENDING will be handled by the sender, no action here. */
    }
    /* #80 Remove the element from the buffer. */
    Os_XSigChannelFreeResult(SendChannel);                                                                              /* SBSW_OS_FC_PRECONDITION */
  }
}


/***********************************************************************************************************************
 *  Os_XSigInitSendPort()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_XSigSendPortInit,
(
  P2CONST(Os_XSigSendPortConfigType, AUTOMATIC, OS_CONST) SendPort
))
{
  if(SendPort !=  NULL_PTR)
  {
    /* #10 Initialize the sender side of the communication buffer. */
    Os_XSigChannelSendInit(&(SendPort->SendChannel));                                                                   /* SBSW_OS_FC_PRECONDITION */
  }
}


/***********************************************************************************************************************
 *  Os_XSigRecvPortInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_XSigRecvPortInit,
(
  P2CONST(Os_XSigRecvPortConfigType, AUTOMATIC, OS_CONST) RecvPort
))
{
  /* #10 Initialize the receiver side of the communication buffer. */
  Os_XSigChannelReceiveInit(&(RecvPort->RecvChannel));                                                                  /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_XSigIsrInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_XSigIsrInit,
(
    P2CONST(Os_XSigIsrConfigType, AUTOMATIC, OS_CONST) XSigIsr
))
{
  Os_ObjIdxType it;

  /* #10 Initialize the base ISR. */
  Os_IsrInit(&(XSigIsr->IsrCfg));                                                                                       /* SBSW_OS_FC_PRECONDITION */

  /* #20 Initialize the hardware interrupt. */
  Os_Hal_XSigInit(XSigIsr->HwConfig);                                                                                   /* SBSW_OS_XSIG_HAL_XSIGINIT_001 */

  /* #30 Initialize the receiver ports. */
  for(it = 0; it < XSigIsr->RecvPortCount; ++it)
  {
    Os_XSigRecvPortInit(XSigIsr->RecvPortRefs[it]);                                                                     /* SBSW_OS_XSIG_XSIGRECVPORTINIT_001 */
  }
}


/***********************************************************************************************************************
 *  Os_XSigThread2XSigIsr()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2CONST(Os_XSigIsrConfigType, AUTOMATIC, OS_CONST), OS_CODE,               /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
OS_ALWAYS_INLINE, Os_XSigThread2XSigIsr,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))                                                                                                                      /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
{
  return (P2CONST(Os_XSigIsrConfigType, AUTOMATIC, OS_CONST))Thread;                                                    /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  ISR(Os_XSigRecvIsrHandler)
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
 *
 *
 *
 *
 */

ISR(Os_XSigRecvIsrHandler)                                                                                              /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
{
  P2CONST(Os_XSigIsrConfigType, AUTOMATIC, OS_CONST) xSigIsr;
  Os_StatusType status;
  Os_IntStateType interruptState;
  uint8_least messageReceived;

  xSigIsr = Os_XSigThread2XSigIsr(Os_CoreGetThread());                                                                  /* SBSW_OS_XSIG_XSIGTHREAD2XSIGISR_001 */

  /* #10 Suspend interrupts. */
  Os_IntSuspend(&interruptState);                                                                                       /* SBSW_OS_FC_POINTER2LOCAL */

  /* #20 Loop. */
  do
  {
    Os_ObjIdxType it;

    messageReceived = 0;

    /* #30 Acknowledge the interrupt. */
    Os_Hal_XSigAcknowledge(xSigIsr->HwConfig);                                                                          /* SBSW_OS_XSIG_HAL_XSIGACKNOWLEDGE_001 */

    /* #30 Loop over all incoming ports. */
    for(it = 0; it < xSigIsr->RecvPortCount; ++it)
    {
      P2CONST(Os_XSigRecvPortConfigType, AUTOMATIC, OS_CONST) recvPort;
      P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) sendCore;

      recvPort = xSigIsr->RecvPortRefs[it];
      sendCore = recvPort->SendPort->SendCore;

      /* #40 If the core was started as AUTOSAR core: */
      if(Os_CoreIsStartedAsAsr(Os_CoreAsr2Core(sendCore)) != 0u)                                                        /* SBSW_OS_XSIG_COREISSTARTEDASASR */ /* SBSW_OS_XSIG_COREASR2CORE_001 */
      {
        /* #50 If the sender's channel index is valid: */
        if(Os_XSigChannelReceiveCheckInRange(&(recvPort->RecvChannel)) != 0u)                                           /* SBSW_OS_XSIG_XSIGCHANNELRECEIVECHECKINRANGE */
        {
          /* #60 If the core has send a request: */
          if(Os_XSigChannelIsReceiveElementAvailable(&(recvPort->RecvChannel)) != 0u)                                   /* SBSW_OS_XSIG_XSIGCHANNELISRECEIVEELEMENTAVAILABLE_001 */
          {
            P2CONST(Os_XSigComDataConfigType, AUTOMATIC, OS_CONST) comData;
            P2CONST(Os_XSigSendDataType volatile, AUTOMATIC, OS_VAR_NOINIT) sendData;

            /* #70 Check that the received data is valid. */
            comData = Os_XSigChannelGetReceiveElement(&(recvPort->RecvChannel));                                        /* SBSW_OS_XSIG_XSIGCHANNELGETRECEIVEELEMENT_001 */
            if(Os_XSigRecvCheckIsReceiveElementValid(comData) != 0u)                                                    /* SBSW_OS_XSIGRECVCHECKISRECEIVEELEMENTVALID_001 */
            {
              sendData = comData->SendData;

              /* #80 Check that the function is available. */
              if(Os_XSigRecvCheckIsFunctionAvailable(xSigIsr, sendData->FunctionIdx) == OS_CHECK_FAILED)                /* SBSW_OS_XSIG_XSIGRECVCHECKISFUNCTIONAVAILABLE_001 */
              {
                status = OS_STATUS_FUNCTION_UNAVAILABLE;
              }
              /* #90 Call the respective function. */
              else
              {
                Os_XSigFunctionType functionRef;
                P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) inParameter;
                P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) outParameter;

                /* Explicitly cast pointers to volatile data to non volatile data. */
                inParameter = ((P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT))&(sendData->ParameterData));       /* PRQA S 0312 */ /* MD_Os_Rule11.8_0312_Volatile */
                outParameter = ((P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT))                              /* PRQA S 0312 */ /* MD_Os_Rule11.8_0312_Volatile */
                    &(comData->RecvData->ReturnData.OutputParameter));

                functionRef = xSigIsr->FunctionTable->FunctionDescription[sendData->FunctionIdx].FunctionRef;           /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842_Check */

                status = functionRef(sendData->SenderApp, inParameter, outParameter);                                   /* SBSW_OS_XSIG_CALLCACK_001 */
              }

              /* #100 Reply. */
              comData->RecvData->ReturnData.Status = status;                                                            /* SBSW_OS_XSIG_RECVDATA_001 */
            }
            Os_XSigChannelReply(&(recvPort->RecvChannel));                                                              /* SBSW_OS_XSIG_XSIGCHANNELREPLY_001 */
            messageReceived = 1;
          }
        }
      }
    }
    /* #110 While any buffer had entries. */
  } while(messageReceived != 0u);

  /* #120 Resume interrupts. */
  Os_IntResume(&interruptState);                                                                                        /* SBSW_OS_FC_POINTER2LOCAL */
}                                                                                                                       /* PRQA S 6050, 6080 */ /* MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

# if defined (OS_CFG_COMPILER_TASKING)                                                                                  /* COV_OS_COMPILERPRAGMA */
/* This suppresses the warning with regard to "condition always false" by checking against OS_COREASRCOREIDX_COUNT.
 * This can be suppressed, since this warning is only valid for configurations with no XSignal channels.
 */
#  pragma warning 549                                                                                                   /* PRQA S 3116 */ /* MD_MSR_Pragma */
# endif
/***********************************************************************************************************************
 *  Os_XSigInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_XSigInit
(
  P2CONST(Os_XSigConfigType, AUTOMATIC, OS_CONST) XSignal
)
{
  /* #10 If XSignal is enabled: */
  if(Os_XSigIsEnabled() != 0u)
  {
    Os_CoreAsrCoreIdx itSendPort;
    Os_ObjIdxType itReceivePort;
    Os_ObjIdxType recvIsrCount;

    recvIsrCount = Os_XSigGetRecvIsrCount(XSignal);                                                                     /* SBSW_OS_FC_PRECONDITION */

    /* #20 Initialize the send ports. */
    for(itSendPort = (Os_CoreAsrCoreIdx)0; itSendPort < OS_COREASRCOREIDX_COUNT; ++itSendPort)                          /* PRQA S 4332,  4527 */ /* MD_Os_Rule10.5_4332,  MD_Os_Rule10.1_4527 */
    {
      Os_XSigSendPortInit(Os_XSigGetSendPort(XSignal, itSendPort));                                                     /* SBSW_OS_XSIG_XSIGSENDPORTINIT_001 */ /* SBSW_OS_FC_PRECONDITION */
    }

    /* #30 Initialize the receiver ISRs. */
    for(itReceivePort = 0; itReceivePort < recvIsrCount; ++itReceivePort)
    {
      Os_XSigIsrInit(Os_XSigGetRecvIsr(XSignal, itReceivePort));                                                        /* SBSW_OS_XSIG_XSIGISRINIT_001 */ /* SBSW_OS_FC_PRECONDITION */
    }
  }
}
# if defined (OS_CFG_COMPILER_TASKING)                                                                                  /* COV_OS_COMPILERPRAGMA */
#  pragma warning restore                                                                                               /* PRQA S 3116 */ /* MD_MSR_Pragma */
# endif


/***********************************************************************************************************************
 *  Os_XSigSendAsync()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_XSigSendAsync                                                                           /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  Os_XSigFunctionIdx FunctionIdx,
  P2CONST(Os_XSigParamsType, AUTOMATIC, TYPEDEF) Parameters
)
{
  Os_StatusType status;

  if(Os_XSigIsEnabled() != 0u)
  {
    P2CONST(Os_XSigSendPortConfigType, AUTOMATIC, OS_CONST) sendPort;
    Os_XSigComDataConfigRefType comData;

    sendPort = Os_XSigGetSendPortToCore(SendThread, RecvCore);                                                          /* SBSW_OS_FC_PRECONDITION */

    /* #10 Check that a send port to the receiver core exists. */
    if(OS_UNLIKELY(sendPort == NULL_PTR))
    {
      status = OS_STATUS_CALL_NOT_ALLOWED;
    }
    /* #20 Trigger the transmission asynchronously. */
    else
    {
      status = Os_XSigSendInternal(sendPort, SendThread, FunctionIdx, Parameters, OS_XSIGSTATE_ASYNC_NACK, &comData);   /* SBSW_OS_XSIG_XSIGSENDINTERNAL_001 */
    }
  }
  else
  {
    status = OS_STATUS_FUNCTION_UNAVAILABLE;
  }

  return status;
}


/***********************************************************************************************************************
 *  Os_XSigSendSync()
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
FUNC(Os_StatusType, OS_CODE) Os_XSigSendSync                                                                            /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
(
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) RecvCore,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) SendThread,
  Os_XSigFunctionIdx FunctionIdx,
  P2CONST(Os_XSigParamsType, AUTOMATIC, TYPEDEF) InParameters,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, TYPEDEF) OutParameters
)
{
  Os_StatusType status;

  if(Os_XSigIsEnabled() != 0u)
  {
    P2CONST(Os_XSigSendPortConfigType, AUTOMATIC, OS_CONST) sendPort;
    Os_XSigComDataConfigRefType comData;

    sendPort = Os_XSigGetSendPortToCore(SendThread, RecvCore);                                                          /* SBSW_OS_FC_PRECONDITION */

    /* #10 Perform checks. */
    if(OS_UNLIKELY(sendPort == NULL_PTR))
    {
      status = OS_STATUS_CALL_NOT_ALLOWED;
    }
    /*! Internal comment removed.
 *
 * */
    else if(OS_UNLIKELY(Os_ThreadCheckCallContext(SendThread, OS_APICONTEXT_XSIGSENDSYNC) == OS_CHECK_FAILED))          /* SBSW_OS_FC_PRECONDITION */
    {
      status = OS_STATUS_CALLEVEL_CROSS_CORE_SYNC;
    }
    else
    {
      /* #20 Send the request. */
      status = Os_XSigSendInternal(sendPort, SendThread, FunctionIdx, InParameters, OS_XSIGSTATE_SYNC_NACK, &comData);  /* SBSW_OS_XSIG_XSIGSENDINTERNAL_001 */

      if(status == OS_STATUS_OK)
      {
        /* #30 Wait until the result is available. */
        while(Os_XSigChannelIsRequestHandled(&(sendPort->SendChannel), comData) == 0u)                                  /* SBSW_OS_XSIG_XSIGCHANNELISREQUESTHANDLED_001 */
        {
          /*! Internal comment removed.
 *
 *
 * */
          Os_Hal_CoreNop();
        }

        /* #40 Copy return data. */
        status = comData->RecvData->ReturnData.Status;
        (*OutParameters) = comData->RecvData->ReturnData.OutputParameter;                                               /* SBSW_OS_PWA_PRECONDITION */

        /* #50 Free the communication element. */
        comData->SendData->Acknowledge = OS_XSIGSTATE_ACK;                                                              /* SBSW_OS_XSIG_SENDDATA_002 */
      }
    }
  }
  else
  {
    status = OS_STATUS_FUNCTION_UNAVAILABLE;
  }

  return status;
}                                                                                                                       /* PRQA S 6060, 6080 */ /* MD_Os_STPAR, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_XSigRecv_ActivateTask()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_ActivateTask                                                                   /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter                                                 /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  Os_StatusType status;
  TaskType taskId;

  OS_IGNORE_UNREF_PARAM(OutParameter);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  taskId = InParameter->ParameterData[0].ParamTaskType;

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_TaskCheckId(taskId) == OS_CHECK_FAILED))                                                            /* COV_OS_XSIGDOUBLECHECK */
  {
    status = OS_STATUS_CORE_CROSS_DATA;
  }
  else
  {
    P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) taskRef;
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) taskCore;
    Os_AppAccessMaskType permittedApplications;

    taskRef = Os_TaskId2Task(taskId);
    taskCore = Os_TaskGetCore(taskRef);                                                                                 /* SBSW_OS_XSIG_TASKGETCORE_001 */

    permittedApplications = Os_TaskGetAccessingApplications(taskRef);                                                   /* SBSW_OS_XSIG_TASKGETACCESSINGAPPLICATIONS_001 */

    if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(taskCore) == OS_CHECK_FAILED))                                            /* SBSW_OS_XSIG_COREASRCHECKISCORELOCAL_001 */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else if( OS_UNLIKELY(Os_AppCheckAccess(SendApp, permittedApplications) == OS_CHECK_FAILED) )                        /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else
    {
      /* #20 Call the local API function. */
      status = Os_TaskActivateLocalTask(taskRef);                                                                       /* SBSW_OS_XSIG_TASKACTIVATELOCALTASK_001 */
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_XSigRecv_GetTaskState()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_GetTaskState                                                                   /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
)
{
  Os_StatusType status;
  TaskType taskId;

  taskId = InParameter->ParameterData[0].ParamTaskType;

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_TaskCheckId(taskId) == OS_CHECK_FAILED))                                                            /* COV_OS_XSIGDOUBLECHECK */
  {
    status = OS_STATUS_CORE_CROSS_DATA;
  }
  else
  {
    P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) taskRef;
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) taskCore;
    Os_AppAccessMaskType permittedApplications;

    taskRef = Os_TaskId2Task(taskId);
    taskCore = Os_TaskGetCore(taskRef);                                                                                 /* SBSW_OS_XSIG_TASKGETCORE_001 */

    permittedApplications = Os_TaskGetAccessingApplications(taskRef);                                                   /* SBSW_OS_XSIG_TASKGETACCESSINGAPPLICATIONS_001 */

    if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(taskCore) == OS_CHECK_FAILED))                                            /* SBSW_OS_XSIG_COREASRCHECKISCORELOCAL_001 */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else if( OS_UNLIKELY(Os_AppCheckAccess(SendApp, permittedApplications) == OS_CHECK_FAILED) )                        /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else
    {
      /* #20 Call the local API function. */
      status = Os_TaskGetStateLocal(taskRef, &(OutParameter->ParameterData.ParamTaskStateType));                        /* SBSW_OS_XSIG_TASKGETSTATELOCAL_001 */
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_XSigRecv_GetCounterValue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_GetCounterValue                                                                /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
)
{
  Os_StatusType status;
  CounterType counterId;

  counterId = InParameter->ParameterData[0].ParamCounterType;

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_CounterCheckId(counterId) == OS_CHECK_FAILED))                                                      /* COV_OS_XSIGDOUBLECHECK */
  {
    status = OS_STATUS_CORE_CROSS_DATA;
  }
  else
  {
    P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) counterRef;
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) counterCore;
    Os_AppAccessMaskType permittedApplications;

    counterRef = Os_CounterId2Counter(counterId);
    counterCore = Os_CounterGetCore(counterRef);                                                                        /* SBSW_OS_XSIG_COUNTERGETCORE_001 */

    permittedApplications = Os_CounterGetAccessingApplications(counterRef);                                             /* SBSW_OS_XSIG_COUNTERGETACCESSINGAPPLICATIONS_001 */

    if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(counterCore) == OS_CHECK_FAILED))                                         /* SBSW_OS_XSIG_COREASRCHECKISCORELOCAL_002 */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else if( OS_UNLIKELY(Os_AppCheckAccess(SendApp, permittedApplications) == OS_CHECK_FAILED) )                        /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else
    {
      /* #20 Call the local API function. */
      status = Os_CounterGetUserValueLocal(counterRef, &(OutParameter->ParameterData.ParamTickType));                   /* SBSW_OS_XSIG_COUNTERGETUSERVALUELOCAL_001 */
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_XSigRecv_SetEvent()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_SetEvent                                                                       /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
 P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
 P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
 P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter                                                  /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  Os_StatusType status;
  TaskType taskId;

  OS_IGNORE_UNREF_PARAM(OutParameter);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  taskId = InParameter->ParameterData[0].ParamTaskType;

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_TaskCheckId(taskId) == OS_CHECK_FAILED))                                                            /* COV_OS_XSIGDOUBLECHECK */
  {
    status = OS_STATUS_CORE_CROSS_DATA;
  }
  else
  {
    P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) taskRef;
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) taskCore;
    Os_AppAccessMaskType permittedApplications;

    taskRef = Os_TaskId2Task(taskId);
    taskCore = Os_TaskGetCore(taskRef);                                                                                 /* SBSW_OS_XSIG_TASKGETCORE_001 */

    permittedApplications = Os_TaskGetAccessingApplications(taskRef);                                                   /* SBSW_OS_XSIG_TASKGETACCESSINGAPPLICATIONS_001 */

    if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(taskCore) == OS_CHECK_FAILED))                                            /* SBSW_OS_XSIG_COREASRCHECKISCORELOCAL_001 */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else if( OS_UNLIKELY(Os_AppCheckAccess(SendApp, permittedApplications) == OS_CHECK_FAILED) )                        /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else
    {
      EventMaskType mask;

      mask = InParameter->ParameterData[1].ParamEventMaskType;

      /* #20 Call the local API function. */
      status = Os_EventSetLocal(taskRef, mask);                                                                         /* SBSW_OS_XSIG_EVENTSETLOCAL_001 */
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_XSigRecv_GetEvent()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_GetEvent                                                                       /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
)
{
  Os_StatusType status;
  TaskType taskId;

  taskId = InParameter->ParameterData[0].ParamTaskType;

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_TaskCheckId(taskId) == OS_CHECK_FAILED))                                                            /* COV_OS_XSIGDOUBLECHECK */
  {
    status = OS_STATUS_CORE_CROSS_DATA;
  }
  else
  {
    P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) taskRef;
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) taskCore;
    Os_AppAccessMaskType permittedApplications;

    taskRef = Os_TaskId2Task(taskId);
    taskCore = Os_TaskGetCore(taskRef);                                                                                 /* SBSW_OS_XSIG_TASKGETCORE_001 */

    permittedApplications = Os_TaskGetAccessingApplications(taskRef);                                                   /* SBSW_OS_XSIG_TASKGETACCESSINGAPPLICATIONS_001 */

    if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(taskCore) == OS_CHECK_FAILED))                                            /* SBSW_OS_XSIG_COREASRCHECKISCORELOCAL_001 */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else if( OS_UNLIKELY(Os_AppCheckAccess(SendApp, permittedApplications) == OS_CHECK_FAILED) )                        /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else
    {
      /* #20 Call the local API function. */
      status = Os_EventGetLocal(taskRef, &(OutParameter->ParameterData.ParamEventMaskType));                            /* SBSW_OS_XSIG_EVENTGETLOCAL_001 */
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_XSigRecv_GetAlarm()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_GetAlarm                                                                       /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
)
{
  Os_StatusType status;
  AlarmType alarmId;

  alarmId = InParameter->ParameterData[0].ParamAlarmType;

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_AlarmCheckId(alarmId) == OS_CHECK_FAILED))                                                          /* COV_OS_XSIGDOUBLECHECK */
  {
    status = OS_STATUS_CORE_CROSS_DATA;
  }
  else
  {
    P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) alarmRef;
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) alarmCore;
    Os_AppAccessMaskType permittedApplications;

    alarmRef = Os_AlarmId2Alarm(alarmId);
    alarmCore = Os_AlarmGetCore(alarmRef);                                                                              /* SBSW_OS_XSIG_ALARMGETCORE_001 */

    permittedApplications = Os_AlarmGetAccessingApplications(alarmRef);                                                 /* SBSW_OS_XSIG_ALARMGETACCESSINGAPPLICATIONS_001 */

    if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(alarmCore) == OS_CHECK_FAILED))                                           /* SBSW_OS_XSIG_COREASRCHECKISCORELOCAL_003 */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else if( OS_UNLIKELY(Os_AppCheckAccess(SendApp, permittedApplications) == OS_CHECK_FAILED) )                        /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else
    {
      /* #20 Call the local API function. */
      status = Os_AlarmGetAlarmLocal(alarmRef, &(OutParameter->ParameterData.ParamTickType));                           /* SBSW_OS_XSIG_ALARMGETALARMLOCAL_001 */
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_XSigRecv_SetRelAlarm()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_SetRelAlarm                                                                    /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
 P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
 P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
 P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter                                                  /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  Os_StatusType status;
  AlarmType alarmId;

  OS_IGNORE_UNREF_PARAM(OutParameter);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  alarmId = InParameter->ParameterData[0].ParamAlarmType;

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_AlarmCheckId(alarmId) == OS_CHECK_FAILED))                                                          /* COV_OS_XSIGDOUBLECHECK */
  {
    status = OS_STATUS_CORE_CROSS_DATA;
  }
  else
  {
    P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) alarmRef;
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) alarmCore;
    Os_AppAccessMaskType permittedApplications;

    alarmRef = Os_AlarmId2Alarm(alarmId);
    alarmCore = Os_AlarmGetCore(alarmRef);                                                                              /* SBSW_OS_XSIG_ALARMGETCORE_001 */

    permittedApplications = Os_AlarmGetAccessingApplications(alarmRef);                                                 /* SBSW_OS_XSIG_ALARMGETACCESSINGAPPLICATIONS_001 */

    if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(alarmCore) == OS_CHECK_FAILED))                                           /* SBSW_OS_XSIG_COREASRCHECKISCORELOCAL_003 */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else if( OS_UNLIKELY(Os_AppCheckAccess(SendApp, permittedApplications) == OS_CHECK_FAILED) )                        /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else
    {
      Os_TickType increment;
      Os_TickType cycle;

      increment = InParameter->ParameterData[1].ParamTickType;
      cycle = InParameter->ParameterData[2].ParamTickType;

      /* #20 Call the local API function. */
      status = Os_AlarmSetRelAlarmLocal(alarmRef, increment, cycle);                                                    /* SBSW_OS_XSIG_ALARMSETRELALARMLOCAL_001 */
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_XSigRecv_SetAbsAlarm()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_SetAbsAlarm                                                                    /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
 P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
 P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
 P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter                                                  /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  Os_StatusType status;
  AlarmType alarmId;

  OS_IGNORE_UNREF_PARAM(OutParameter);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  alarmId = InParameter->ParameterData[0].ParamAlarmType;

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_AlarmCheckId(alarmId) == OS_CHECK_FAILED))                                                          /* COV_OS_XSIGDOUBLECHECK */
  {
    status = OS_STATUS_CORE_CROSS_DATA;
  }
  else
  {
    P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) alarmRef;
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) alarmCore;
    Os_AppAccessMaskType permittedApplications;

    alarmRef = Os_AlarmId2Alarm(alarmId);
    alarmCore = Os_AlarmGetCore(alarmRef);                                                                              /* SBSW_OS_XSIG_ALARMGETCORE_001 */

    permittedApplications = Os_AlarmGetAccessingApplications(alarmRef);                                                 /* SBSW_OS_XSIG_ALARMGETACCESSINGAPPLICATIONS_001 */

    if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(alarmCore) == OS_CHECK_FAILED))                                           /* SBSW_OS_XSIG_COREASRCHECKISCORELOCAL_003 */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else if( OS_UNLIKELY(Os_AppCheckAccess(SendApp, permittedApplications) == OS_CHECK_FAILED) )                        /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else
    {
      Os_TickType start;
      Os_TickType cycle;

      start = InParameter->ParameterData[1].ParamTickType;
      cycle = InParameter->ParameterData[2].ParamTickType;

      /* #20 Call the local API function. */
      status = Os_AlarmSetAbsAlarmLocal(alarmRef, start, cycle);                                                        /* SBSW_OS_XSIG_ALARMSETABSALARMLOCAL_001 */
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */

/***********************************************************************************************************************
 *  Os_XSigRecv_CancelAlarm()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_CancelAlarm                                                                    /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
 P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
 P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
 P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter                                                  /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  Os_StatusType status;
  AlarmType alarmId;

  OS_IGNORE_UNREF_PARAM(OutParameter);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  alarmId = InParameter->ParameterData[0].ParamAlarmType;

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_AlarmCheckId(alarmId) == OS_CHECK_FAILED))                                                          /* COV_OS_XSIGDOUBLECHECK */
  {
    status = OS_STATUS_CORE_CROSS_DATA;
  }
  else
  {
    P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) alarmRef;
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) alarmCore;
    Os_AppAccessMaskType permittedApplications;

    alarmRef = Os_AlarmId2Alarm(alarmId);
    alarmCore = Os_AlarmGetCore(alarmRef);                                                                              /* SBSW_OS_XSIG_ALARMGETCORE_001 */

    permittedApplications = Os_AlarmGetAccessingApplications(alarmRef);                                                 /* SBSW_OS_XSIG_ALARMGETACCESSINGAPPLICATIONS_001 */

    if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(alarmCore) == OS_CHECK_FAILED))                                           /* SBSW_OS_XSIG_COREASRCHECKISCORELOCAL_003 */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else if( OS_UNLIKELY(Os_AppCheckAccess(SendApp, permittedApplications) == OS_CHECK_FAILED) )                        /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else
    {
      /* #20 Call the local API function. */
      status = Os_AlarmCancelAlarmLocal(alarmRef);                                                                      /* SBSW_OS_XSIG_ALARMCANCELALARMLOCAL_001 */
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */

/***********************************************************************************************************************
 *  Os_XSigRecv_StartScheduleTableRel()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_StartScheduleTableRel                                                          /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
 P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
 P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
 P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter                                                  /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  Os_StatusType status;
  ScheduleTableType scheduleTableID;

  OS_IGNORE_UNREF_PARAM(OutParameter);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  scheduleTableID = InParameter->ParameterData[0].ParamScheduleTableType;

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_SchTCheckId(scheduleTableID) == OS_CHECK_FAILED))                                                   /* COV_OS_XSIGDOUBLECHECK */
  {
    status = OS_STATUS_CORE_CROSS_DATA;
  }
  else
  {
    P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) schTRef;
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) schTCore;
    Os_AppAccessMaskType permittedApplications;

    schTRef = Os_SchTId2SchT(scheduleTableID);
    schTCore = Os_SchTGetCore(schTRef);                                                                                 /* SBSW_OS_XSIG_SCHTGETCORE_001 */

    permittedApplications = Os_SchTGetAccessingApplications(schTRef);                                                   /* SBSW_OS_XSIG_SCHTGETACCESSINGAPPLICATIONS_001 */

    if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(schTCore) == OS_CHECK_FAILED))                                            /* SBSW_OS_XSIG_COREASRCHECKISCORELOCAL_004 */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else if( OS_UNLIKELY(Os_AppCheckAccess(SendApp, permittedApplications) == OS_CHECK_FAILED) )                        /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else
    {
      TickType offset;

      offset = InParameter->ParameterData[1].ParamTickType;

      /* #20 Call the local API function. */
      status = Os_SchTStartScheduleTableRelLocal(schTRef, offset);                                                      /* SBSW_OS_XSIG_SCHTSTARTSCHEDULETABLERELLOCAL_001 */
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_XSigRecv_StartScheduleTableAbs()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_StartScheduleTableAbs                                                          /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
 P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
 P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
 P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter                                                  /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  Os_StatusType status;
  ScheduleTableType scheduleTableID;

  OS_IGNORE_UNREF_PARAM(OutParameter);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  scheduleTableID = InParameter->ParameterData[0].ParamScheduleTableType;

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_SchTCheckId(scheduleTableID) == OS_CHECK_FAILED))                                                   /* COV_OS_XSIGDOUBLECHECK */
  {
    status = OS_STATUS_CORE_CROSS_DATA;
  }
  else
  {
    P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) schTRef;
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) schTCore;
    Os_AppAccessMaskType permittedApplications;

    schTRef = Os_SchTId2SchT(scheduleTableID);
    schTCore = Os_SchTGetCore(schTRef);                                                                                 /* SBSW_OS_XSIG_SCHTGETCORE_001 */

    permittedApplications = Os_SchTGetAccessingApplications(schTRef);                                                   /* SBSW_OS_XSIG_SCHTGETACCESSINGAPPLICATIONS_001 */

    if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(schTCore) == OS_CHECK_FAILED))                                            /* SBSW_OS_XSIG_COREASRCHECKISCORELOCAL_004 */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else if( OS_UNLIKELY(Os_AppCheckAccess(SendApp, permittedApplications) == OS_CHECK_FAILED) )                        /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else
    {
      TickType start;

      start = InParameter->ParameterData[1].ParamTickType;

      /* #20 Call the local API function. */
      status = Os_SchTStartScheduleTableAbsLocal(schTRef, start);                                                       /* SBSW_OS_XSIG_SCHTSTARTSCHEDULETABLEABSLOCAL_001 */
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_XSigRecv_StopScheduleTable()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_StopScheduleTable                                                              /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
 P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
 P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
 P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter                                                  /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  Os_StatusType status;
  ScheduleTableType scheduleTableID;

  OS_IGNORE_UNREF_PARAM(OutParameter);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  scheduleTableID = InParameter->ParameterData[0].ParamScheduleTableType;

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_SchTCheckId(scheduleTableID) == OS_CHECK_FAILED))                                                   /* COV_OS_XSIGDOUBLECHECK */
  {
    status = OS_STATUS_CORE_CROSS_DATA;
  }
  else
  {
    P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) schTRef;
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) schTCore;
    Os_AppAccessMaskType permittedApplications;

    schTRef = Os_SchTId2SchT(scheduleTableID);
    schTCore = Os_SchTGetCore(schTRef);                                                                                 /* SBSW_OS_XSIG_SCHTGETCORE_001 */

    permittedApplications = Os_SchTGetAccessingApplications(schTRef);                                                   /* SBSW_OS_XSIG_SCHTGETACCESSINGAPPLICATIONS_001 */

    if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(schTCore) == OS_CHECK_FAILED))                                            /* SBSW_OS_XSIG_COREASRCHECKISCORELOCAL_004 */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else if( OS_UNLIKELY(Os_AppCheckAccess(SendApp, permittedApplications) == OS_CHECK_FAILED) )                        /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else
    {
      /* #20 Call the local API function. */
      status = Os_SchTStopScheduleTableLocal(schTRef);                                                                  /* SBSW_OS_XSIG_SCHTSTOPSCHEDULETABLELOCAL_001 */
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_XSigRecv_NextScheduleTable()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_NextScheduleTable                                                              /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
 P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
 P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
 P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter                                                  /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  Os_StatusType status;
  ScheduleTableType scheduleTableID_From;
  ScheduleTableType scheduleTableID_To;

  OS_IGNORE_UNREF_PARAM(OutParameter);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  scheduleTableID_From = InParameter->ParameterData[0].ParamScheduleTableType;
  scheduleTableID_To = InParameter->ParameterData[1].ParamScheduleTableType;

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_SchTCheckId(scheduleTableID_From) == OS_CHECK_FAILED))                                              /* COV_OS_XSIGDOUBLECHECK */
  {
    status = OS_STATUS_CORE_CROSS_DATA;
  }
  else if(OS_UNLIKELY(Os_SchTCheckId(scheduleTableID_To) == OS_CHECK_FAILED))                                           /* COV_OS_XSIGDOUBLECHECK */
  {
    status = OS_STATUS_CORE_CROSS_DATA;
  }
  else
  {
    P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) schTRef_From;
    P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) schTRef_To;
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) schTFromCore;
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) schTToCore;
    Os_AppAccessMaskType permittedApplications_From;
    Os_AppAccessMaskType permittedApplications_To;

    schTRef_From = Os_SchTId2SchT(scheduleTableID_From);
    schTRef_To = Os_SchTId2SchT(scheduleTableID_To);
    schTFromCore = Os_SchTGetCore(schTRef_From);                                                                        /* SBSW_OS_XSIG_SCHTGETCORE_001 */
    schTToCore = Os_SchTGetCore(schTRef_To);                                                                            /* SBSW_OS_XSIG_SCHTGETCORE_001 */

    permittedApplications_From = Os_SchTGetAccessingApplications(schTRef_From);                                         /* SBSW_OS_XSIG_SCHTGETACCESSINGAPPLICATIONS_001 */
    permittedApplications_To = Os_SchTGetAccessingApplications(schTRef_To);                                             /* SBSW_OS_XSIG_SCHTGETACCESSINGAPPLICATIONS_001 */

    if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(schTFromCore) == OS_CHECK_FAILED))                                        /* SBSW_OS_XSIG_COREASRCHECKISCORELOCAL_004 */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(schTToCore) == OS_CHECK_FAILED))                                     /* SBSW_OS_XSIG_COREASRCHECKISCORELOCAL_004 */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else if( OS_UNLIKELY(Os_AppCheckAccess(SendApp, permittedApplications_From) == OS_CHECK_FAILED) )                   /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else if( OS_UNLIKELY(Os_AppCheckAccess(SendApp, permittedApplications_To) == OS_CHECK_FAILED) )                     /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else
    {
      /* #20 Call the local API function. */
      status = Os_SchTNextScheduleTableLocal(schTRef_From, schTRef_To);                                                 /* SBSW_OS_XSIG_SCHTNEXTSCHEDULETABLELOCAL_001 */
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050, 6080 */ /* MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_XSigRecv_GetScheduleTableStatus()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_GetScheduleTableStatus                                                         /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
)
{
  Os_StatusType status;
  ScheduleTableType scheduleTableID;

  OS_IGNORE_UNREF_PARAM(OutParameter);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  scheduleTableID = InParameter->ParameterData[0].ParamScheduleTableType;

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_SchTCheckId(scheduleTableID) == OS_CHECK_FAILED))                                                   /* COV_OS_XSIGDOUBLECHECK */
  {
    status = OS_STATUS_CORE_CROSS_DATA;
  }
  else
  {
    P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) schTRef;
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) schTCore;
    Os_AppAccessMaskType permittedApplications;

    schTRef = Os_SchTId2SchT(scheduleTableID);
    schTCore = Os_SchTGetCore(schTRef);                                                                                 /* SBSW_OS_XSIG_SCHTGETCORE_001 */

    permittedApplications = Os_SchTGetAccessingApplications(schTRef);                                                   /* SBSW_OS_XSIG_SCHTGETACCESSINGAPPLICATIONS_001 */

    if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(schTCore) == OS_CHECK_FAILED))                                            /* SBSW_OS_XSIG_COREASRCHECKISCORELOCAL_004 */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else if( OS_UNLIKELY(Os_AppCheckAccess(SendApp, permittedApplications) == OS_CHECK_FAILED) )                        /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else
    {
      /* #20 Call the local API function. */
      status = Os_SchTGetScheduleTableStatusLocal(schTRef, &(OutParameter->ParameterData.ParamScheduleTableStatusType));/* SBSW_OS_XSIG_SCHTGETSCHEDULETABLESTATUSLOCAL_001 */
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_XSigRecv_GetTaskStackUsage()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_GetTaskStackUsage                                                              /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
)
{
  Os_StatusType status;
  TaskType taskId;

  OS_IGNORE_UNREF_PARAM(SendApp);                                                                                       /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  taskId = InParameter->ParameterData[0].ParamTaskType;

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_TaskCheckId(taskId) == OS_CHECK_FAILED))                                                            /* COV_OS_XSIGDOUBLECHECK */
  {
    status = OS_STATUS_CORE_CROSS_DATA;
  }
  else
  {
    P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) taskRef;
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) taskCore;

    taskRef = Os_TaskId2Task(taskId);
    taskCore = Os_TaskGetCore(taskRef);                                                                                 /* SBSW_OS_XSIG_TASKGETCORE_001 */

    if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(taskCore) == OS_CHECK_FAILED))                                             /* SBSW_OS_XSIG_COREASRCHECKISCORELOCAL_001 */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else
    {
      /* #20 Call the local API function. */
      OutParameter->ParameterData.Paramuint32 = Os_StackGetTaskStackUsageLocal(taskRef);                                /* SBSW_OS_PWA_PRECONDITION */ /* SBSW_OS_XSIG_STACKGETTASKSTACKUSAGELOCAL_001 */
      status = OS_STATUS_OK;
    }
  }

  return status;
}


/***********************************************************************************************************************
 *  Os_XSigRecv_GetISRStackUsage()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_GetISRStackUsage                                                               /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
)
{
  Os_StatusType status;
  ISRType isrId;

  OS_IGNORE_UNREF_PARAM(SendApp);                                                                                       /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  isrId = InParameter->ParameterData[0].ParamISRType;

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_IsrCheckId(isrId) == OS_CHECK_FAILED))                                                              /* COV_OS_XSIGDOUBLECHECK */
  {
    status = OS_STATUS_CORE_CROSS_DATA;
  }
  else
  {
    P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) isrRef;
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) isrCore;

    isrRef = Os_IsrId2Isr(isrId);
    isrCore = Os_ThreadGetCore(Os_IsrGetThread(isrRef));                                                                /* SBSW_OS_XSIG_THREADGETCORE_002 */ /* SBSW_OS_XSIG_ISRGETTHREAD_001 */

    if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(isrCore) == OS_CHECK_FAILED))                                             /* SBSW_OS_XSIG_COREASRCHECKISCORELOCAL_005 */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else
    {
      /* #20 Call the local API function. */
      OutParameter->ParameterData.Paramuint32 = Os_StackGetISRStackUsageLocal(isrRef);                                  /* SBSW_OS_PWA_PRECONDITION */ /* SBSW_OS_XSIG_STACKGETISRSTACKUSAGELOCAL_001 */
      status = OS_STATUS_OK;
    }
  }

  return status;
}


/***********************************************************************************************************************
 *  Os_XSigRecv_ControlIdle()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_ControlIdle                                                                    /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter                                                 /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  Os_StatusType status;
  CoreIdType coreId;

  OS_IGNORE_UNREF_PARAM(OutParameter);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(SendApp);                                                                                       /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  coreId = InParameter->ParameterData[0].ParamCoreIdType;

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_CoreCheckId(coreId) == OS_CHECK_FAILED))                                                            /* COV_OS_XSIGDOUBLECHECK */
  {
    status = OS_STATUS_CORE_CROSS_DATA;
  }
  else
  {
    P2CONST(Os_CoreConfigType, AUTOMATIC, OS_CONST) targetCore;

    targetCore = Os_CoreId2Core(coreId);

    if(OS_UNLIKELY(Os_CoreCheckIsAsrCore(targetCore) == OS_CHECK_FAILED))                                               /* SBSW_OS_XSIG_CORECHECKISASRCORE_001 */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else
    {
      P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) coreRef;

      coreRef = Os_Core2AsrCore(targetCore);                                                                            /* SBSW_OS_XSIG_CORE2ASRCORE_001 */

      if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(coreRef) == OS_CHECK_FAILED))                                           /* SBSW_OS_XSIG_COREASRCHECKISCORELOCAL_006 */ /* COV_OS_XSIGDOUBLECHECK */
      {
        status = OS_STATUS_CORE_CROSS_DATA;
      }
      else
      {
        P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) localCore;
        IdleModeType idleMode;

        localCore = Os_ThreadGetCore(Os_CoreGetThread());                                                               /* SBSW_OS_XSIG_THREADGETCORE_001 */
        idleMode = InParameter->ParameterData[1].ParamIdleModeType;

        /* #20 Call the local API function. */
        status = Os_CoreControlIdle(localCore, idleMode);                                                               /* SBSW_OS_XSIG_CORECONTROLIDLE_001 */
      }
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_XSigRecv_GetKernelStackUsage()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_GetKernelStackUsage                                                            /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
)
{
  Os_StatusType status;
  CoreIdType coreId;

  OS_IGNORE_UNREF_PARAM(SendApp);                                                                                       /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  coreId = InParameter->ParameterData[0].ParamCoreIdType;

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_CoreCheckId(coreId) == OS_CHECK_FAILED))                                                            /* COV_OS_XSIGDOUBLECHECK */
  {
    status = OS_STATUS_CORE_CROSS_DATA;
  }
  else
  {
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) coreRef;

    coreRef = Os_Core2AsrCore(Os_CoreId2Core(coreId));                                                                  /* SBSW_OS_XSIG_CORE2ASRCORE_001 */

    if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(coreRef) == OS_CHECK_FAILED))                                             /* SBSW_OS_XSIG_COREASRCHECKISCORELOCAL_006 */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else
    {
      /* #20 Call the local API function. */
      OutParameter->ParameterData.Paramuint32 = Os_StackGetKernelStackUsageLocal(coreRef);                              /* SBSW_OS_XSIG_STACKGETUSAGE_001 */ /* SBSW_OS_PWA_PRECONDITION */
      status = OS_STATUS_OK;
    }
  }

  return status;
}


/***********************************************************************************************************************
 *  Os_XSigRecv_GetStartupHookStackUsage()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_GetStartupHookStackUsage                                                       /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
)
{
  Os_StatusType status;
  CoreIdType coreId;

  OS_IGNORE_UNREF_PARAM(SendApp);                                                                                       /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  coreId = InParameter->ParameterData[0].ParamCoreIdType;

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_CoreCheckId(coreId) == OS_CHECK_FAILED))                                                            /* COV_OS_XSIGDOUBLECHECK */
  {
    status = OS_STATUS_CORE_CROSS_DATA;
  }
  else
  {
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) coreRef;

    coreRef = Os_Core2AsrCore(Os_CoreId2Core(coreId));                                                                  /* SBSW_OS_XSIG_CORE2ASRCORE_001 */

    if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(coreRef) == OS_CHECK_FAILED))                                             /* SBSW_OS_XSIG_COREASRCHECKISCORELOCAL_006 */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else
    {
      /* #20 Call the local API function. */
      OutParameter->ParameterData.Paramuint32 = Os_StackGetStartupHookStackUsageLocal(coreRef);                         /* SBSW_OS_PWA_PRECONDITION */ /* SBSW_OS_XSIG_STACKGETUSAGE_001 */
      status = OS_STATUS_OK;
    }
  }

  return status;
}


/***********************************************************************************************************************
 *  Os_XSigRecv_GetErrorHookStackUsage()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_GetErrorHookStackUsage                                                         /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
)
{
  Os_StatusType status;
  CoreIdType coreId;

  OS_IGNORE_UNREF_PARAM(SendApp);                                                                                       /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  coreId = InParameter->ParameterData[0].ParamCoreIdType;

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_CoreCheckId(coreId) == OS_CHECK_FAILED))                                                            /* COV_OS_XSIGDOUBLECHECK */
  {
    status = OS_STATUS_CORE_CROSS_DATA;
  }
  else
  {
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) coreRef;

    coreRef = Os_Core2AsrCore(Os_CoreId2Core(coreId));                                                                  /* SBSW_OS_XSIG_CORE2ASRCORE_001 */

    if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(coreRef) == OS_CHECK_FAILED))                                             /* SBSW_OS_XSIG_COREASRCHECKISCORELOCAL_006 */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else
    {
      /* #20 Call the local API function. */
      OutParameter->ParameterData.Paramuint32 = Os_StackGetErrorHookStackUsageLocal(coreRef);                           /* SBSW_OS_PWA_PRECONDITION */ /* SBSW_OS_XSIG_STACKGETUSAGE_001 */
      status = OS_STATUS_OK;
    }
  }

  return status;
}


/***********************************************************************************************************************
 *  Os_XSigRecv_GetShutdownHookStackUsage()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_GetShutdownHookStackUsage                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
)
{
  Os_StatusType status;
  CoreIdType coreId;

  OS_IGNORE_UNREF_PARAM(SendApp);                                                                                       /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  coreId = InParameter->ParameterData[0].ParamCoreIdType;

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_CoreCheckId(coreId) == OS_CHECK_FAILED))                                                            /* COV_OS_XSIGDOUBLECHECK */
  {
    status = OS_STATUS_CORE_CROSS_DATA;
  }
  else
  {
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) coreRef;

    coreRef = Os_Core2AsrCore(Os_CoreId2Core(coreId));                                                                  /* SBSW_OS_XSIG_CORE2ASRCORE_001 */

    if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(coreRef) == OS_CHECK_FAILED))                                             /* SBSW_OS_XSIG_COREASRCHECKISCORELOCAL_006 */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else
    {
      /* #20 Call the local API function. */
      OutParameter->ParameterData.Paramuint32 = Os_StackGetShutdownHookStackUsageLocal(coreRef);                        /* SBSW_OS_PWA_PRECONDITION */ /* SBSW_OS_XSIG_STACKGETUSAGE_001 */
      status = OS_STATUS_OK;
    }
  }

  return status;
}



/***********************************************************************************************************************
 *  Os_XSigRecv_GetProtectionHookStackUsage()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_GetProtectionHookStackUsage                                                    /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
)
{
  Os_StatusType status;
  CoreIdType coreId;

  OS_IGNORE_UNREF_PARAM(SendApp);                                                                                       /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  coreId = InParameter->ParameterData[0].ParamCoreIdType;

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_CoreCheckId(coreId) == OS_CHECK_FAILED))                                                            /* COV_OS_XSIGDOUBLECHECK */
  {
    status = OS_STATUS_CORE_CROSS_DATA;
  }
  else
  {
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) coreRef;

    coreRef = Os_Core2AsrCore(Os_CoreId2Core(coreId));                                                                  /* SBSW_OS_XSIG_CORE2ASRCORE_001 */

    if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(coreRef) == OS_CHECK_FAILED))                                              /* SBSW_OS_XSIG_COREASRCHECKISCORELOCAL_006 */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else
    {
      /* #20 Call the local API function. */
      OutParameter->ParameterData.Paramuint32 = Os_StackGetProtectionHookStackUsageLocal(coreRef);                      /* SBSW_OS_PWA_PRECONDITION */ /* SBSW_OS_XSIG_STACKGETUSAGE_001 */
      status = OS_STATUS_OK;
    }
  }

  return status;
}


/***********************************************************************************************************************
 *  Os_XSigRecv_TerminateApplication()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_TerminateApplication                                                           /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
 P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
 P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
 P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter                                                  /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  Os_StatusType status;
  ApplicationType application;

  OS_IGNORE_UNREF_PARAM(OutParameter);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(SendApp);                                                                                       /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  application = InParameter->ParameterData[0].ParamApplicationType;

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_AppCheckId(application) == OS_CHECK_FAILED))                                                        /* COV_OS_XSIGDOUBLECHECK */
  {
    status = OS_STATUS_CORE_CROSS_DATA;
  }
  else
  {
    P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) appRef;
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) appCore;

    appRef = Os_AppId2App(application);
    appCore = Os_AppGetCore(appRef);                                                                                    /* SBSW_OS_XSIG_APPGETCORE_001 */

    if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(appCore) == OS_CHECK_FAILED))                                             /* SBSW_OS_XSIG_COREASRCHECKISCORELOCAL_007 */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else
    {
      RestartType restartOption;
      ApplicationType currentCallerApplication;

      restartOption = InParameter->ParameterData[1].ParamRestartType;
      currentCallerApplication = InParameter->ParameterData[2].ParamApplicationType;

      /* #20 Call the local API function. */
      status = Os_AppTerminateApplicationLocal(appRef, restartOption,  currentCallerApplication);                       /* SBSW_OS_XSIG_APPTERMINATEAPPLICATIONLOCAL_001 */
    }
  }

  return status;
}


/***********************************************************************************************************************
 *  Os_XSigRecv_GetApplicationState()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_GetApplicationState                                                            /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
  P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
  P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter
)
{
  Os_StatusType status;
  ApplicationType application;

  OS_IGNORE_UNREF_PARAM(SendApp);                                                                                       /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  application = InParameter->ParameterData[0].ParamApplicationType;

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_AppCheckId(application) == OS_CHECK_FAILED))                                                        /* COV_OS_XSIGDOUBLECHECK */
  {
    status = OS_STATUS_CORE_CROSS_DATA;
  }
  else
  {
    P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) appRef;
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) appCore;

    appRef = Os_AppId2App(application);
    appCore = Os_AppGetCore(appRef);                                                                                    /* SBSW_OS_XSIG_APPGETCORE_001 */

    if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(appCore) == OS_CHECK_FAILED))                                             /* SBSW_OS_XSIG_COREASRCHECKISCORELOCAL_007 */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    else
    {
      /* #20 Call the local API function. */
      status = Os_AppGetApplicationStateLocal(appRef, &(OutParameter->ParameterData.ParamApplicationStateType));        /* SBSW_OS_XSIG_APPGETAPPLICATIONSTATELOCAL_001 */
    }
  }

  return status;
}


/***********************************************************************************************************************
 *  Os_XSigRecv_ShutdownAllCores()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */

FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_ShutdownAllCores                                                               /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
 P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
 P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
 P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter                                                  /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  StatusType error;

  OS_IGNORE_UNREF_PARAM(OutParameter);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(SendApp);                                                                                       /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  error = InParameter->ParameterData[0].ParamStatusType;

  /* #20 Call the local API function. */
  Os_CoreShutdownAllLocal(error);

  return OS_STATUS_OK;
}


/***********************************************************************************************************************
 *  Os_XSigRecv_HookCallCallback()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */

FUNC(Os_StatusType, OS_CODE) Os_XSigRecv_HookCallCallback                                                               /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
 P2CONST(Os_AppConfigType, AUTOMATIC, OS_VAR_NOINIT) SendApp,
 P2CONST(Os_XSigParamsType, AUTOMATIC, OS_VAR_NOINIT) InParameter,
 P2VAR(Os_XSigOutputParamsType, AUTOMATIC, OS_VAR_NOINIT) OutParameter                                                  /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
)
{
  Os_StatusType status;
  Os_HookIdType id;

  OS_IGNORE_UNREF_PARAM(OutParameter);                                                                                  /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */
  OS_IGNORE_UNREF_PARAM(SendApp);                                                                                       /* PRQA S 3112 */ /* MD_Os_Rule2.2_3112 */

  id = InParameter->ParameterData[0].ParamHookIdType;

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_HookCheckId(id) == OS_CHECK_FAILED))                                                                /* COV_OS_XSIGDOUBLECHECK */
  {
    status = OS_STATUS_CORE_CROSS_DATA;
  }
  else
  {
    P2CONST(Os_HookConfigType, AUTOMATIC, OS_CONST) callbackRef;
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) callbackCore;

    callbackRef = Os_HookId2Hook(id);
    callbackCore = Os_ThreadGetCore(Os_HookGetThread(callbackRef));                                                     /* SBSW_OS_XSIG_THREADGETCORE_003 */ /* SBSW_OS_XSIG_HOOKGETTHREAD_001 */

    if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(callbackCore) == OS_CHECK_FAILED))                                        /* SBSW_OS_XSIG_COREASRCHECKISCORELOCAL_005 */ /* COV_OS_XSIGDOUBLECHECK */
    {
      status = OS_STATUS_CORE_CROSS_DATA;
    }
    /* #20 Check that the given hook is a callback. */
    else
    {
      /* #30 Call the local API function. */
      status = Os_HookCallCallbackLocal(Os_Hook2CallbackHook(callbackRef));                                             /* SBSW_OS_XSIG_HOOKCALLCALLBACKLOCAL_001 */ /* SBSW_OS_XSIG_HOOK2CALLBACKHOOK_001 */
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */



#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* module specific MISRA deviations:
 */

/* SBSW_JUSTIFICATION_BEGIN

\ID SBSW_OS_XSIG_COREGETXSIG_001
 \DESCRIPTION    Os_CoreGetXSig is called with the return value of Os_ThreadGetCore.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_XSIG_XSIGGETSENDPORT_001
 \DESCRIPTION    Os_XSigGetSendPort is called with the return value of Os_CoreGetXSig.
                 Precondition ensures, that the function is only called if XSignal is enabled.
 \COUNTERMEASURE \M [CM_OS_COREASR_XSIGNAL_M]

\ID SBSW_OS_XSIG_HAL_XSIGTRIGGER_001
 \DESCRIPTION    Os_Hal_XSigTrigger is called with the HwConfig derived from a XSigIsr. The XSigIsr is derived
                 from a SendPort passed as argument to the caller function. The correctness of the caller argument
                 is ensured by precondition. The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_XSIGSENDPORT_ISR_M]
                 \M [CM_OS_XSIGISR_HWCONFIG_M]

\ID SBSW_OS_XSIG_HAL_XSIGINIT_001
 \DESCRIPTION    Os_Hal_XSigInit is called with the HwConfig derived from a XSigIsr. The XSigIsr is passed as
                 argument to the caller function. The correctness of the caller argument
                 is ensured by precondition. The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_XSIGISR_HWCONFIG_M]

\ID SBSW_OS_XSIG_XSIGCHANNELGETRESULT_001
 \DESCRIPTION    Write access to the SendData derived from the return value of Os_XSigChannelGetResult.
 \COUNTERMEASURE \M [CM_OS_XSIGCHANNELGETRESULT_01_04_M]
                 \M [CM_OS_XSIGCHANNELGETRESULT_02_04_M]
                 \M [CM_OS_XSIGCHANNELGETRESULT_03_04_M]
                 \T [CM_OS_XSIGCHANNELGETRESULT_04_04_T]
                 \M [CM_OS_XSIGCOM_SENDDATA_M]

\ID SBSW_OS_XSIG_XSIGRECVPORTINIT_001
 \DESCRIPTION    Os_XSigRecvPortInit is called for each RecvPort of the XSigIsr passed as argument to the caller.
                 The correctness of the caller argument is ensured by precondition. The compliance of the precondition
                 is check during review.
 \COUNTERMEASURE \M [CM_OS_XSIGISR_RECVPORTREFS_01_03_M]
                 \M [CM_OS_XSIGISR_RECVPORTREFS_02_03_M]
                 \R [CM_OS_XSIGISR_RECVPORTREFS_03_03_R]

\ID SBSW_OS_XSIG_ERRORPARAMETER_001
 \DESCRIPTION    Array write access to the Parameter array of a local variable.
 \COUNTERMEASURE \R Runtime range check against array limit.

\ID SBSW_OS_XSIG_XSIGTHREAD2XSIGISR_001
 \DESCRIPTION    Os_XSigThread2XSigIsr is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_XSIG_HAL_XSIGACKNOWLEDGE_001
 \DESCRIPTION    Os_Hal_XSigAcknowledge is called with the HwConfig derived from a XSigIsr.
 \COUNTERMEASURE \M [CM_OS_XSIGISR_HWCONFIG_M]
                 \M [CM_OS_XSIGTHREAD2XSIGISR_M]

\ID SBSW_OS_XSIG_XSIGCHANNELISRECEIVEELEMENTAVAILABLE_001
 \DESCRIPTION    Os_XSigChannelIsReceiveElementAvailable is called with a receive channel derived from a receive port.
                 The receive port is derived with an index from the receive port list of a XSigIsr. The XSigIsr
                 is the return value of Os_XSigThread2XSigIsr.
 \COUNTERMEASURE \M [CM_OS_XSIGTHREAD2XSIGISR_M]
                 \M [CM_OS_XSIGISR_RECVPORTREFS_01_03_M]
                 \M [CM_OS_XSIGISR_RECVPORTREFS_02_03_M]
                 \R [CM_OS_XSIGISR_RECVPORTREFS_03_03_R]
                 \M [CM_OS_XSIGRECVPORT_M]
                 \R [CM_OS_XSIG_INDEX_R]

\ID SBSW_OS_XSIG_XSIGCHANNELGETRECEIVEELEMENT_001
 \DESCRIPTION    Os_XSigChannelGetReceiveElement is called with a receive channel derived from a receive port.
                 The receive port is derived with an index from the receive port list of a XSigIsr. The XSigIsr
                 is the return value of Os_XSigThread2XSigIsr.
 \COUNTERMEASURE \M [CM_OS_XSIGTHREAD2XSIGISR_M]
                 \M [CM_OS_XSIGISR_RECVPORTREFS_01_03_M]
                 \M [CM_OS_XSIGISR_RECVPORTREFS_02_03_M]
                 \R [CM_OS_XSIGISR_RECVPORTREFS_03_03_R]
                 \M [CM_OS_XSIGRECVPORT_M]
                 \R [CM_OS_XSIG_INDEX_R]

\ID SBSW_OS_XSIGRECVCHECKISRECEIVEELEMENTVALID_001
 \DESCRIPTION    Os_XSigRecvCheckIsReceiveElementValid is called with the return value of
                 Os_XSigChannelGetReceiveElement.
 \COUNTERMEASURE \M [CM_OS_XSIGCHANNELGETRECEIVEELEMENT_01_03_M]
                 \M [CM_OS_XSIGCHANNELGETRECEIVEELEMENT_02_03_M]
                 \T [CM_OS_XSIGCHANNELGETRECEIVEELEMENT_03_03_T]

\ID SBSW_OS_XSIG_XSIGRECVCHECKISFUNCTIONAVAILABLE_001
 \DESCRIPTION    Os_XSigRecvCheckIsFunctionAvailable is called with the return value of Os_XSigThread2XSigIsr.
 \COUNTERMEASURE \M [CM_OS_XSIGTHREAD2XSIGISR_M]

\ID SBSW_OS_XSIG_CHANNEL_SENDDATA_001
 \DESCRIPTION    Write access to the send data element derived with an index from the buffer array of a Channel.
                 The channel is passed as argument to the caller function. The correctness of the caller argument
                 is ensured by precondition. The compliance of the precondition is check during review.
 \COUNTERMEASURE \R [CM_OS_XSIGSENDDATA_FUNCTIONIDX_R]
                 \M [CM_OS_XSIGCHANNELSEND_BUFFER_01_02_M]
                 \M [CM_OS_XSIGCHANNELSEND_BUFFER_02_02_M]

\ID SBSW_OS_XSIG_CALLCACK_001
 \DESCRIPTION    Receiver callback pointer is used for function call. The callback pointer is derived with an index
                 from a function description array. The array is derived from a function table which is derived from
                 a xSigIsr. The xSigIsr is the return value of Os_XSigThread2XSigIsr.
                 The sendData->SenderApp parameter is a pointer which will only be read in the callee.
                 The InParameter parameter is derived from the send data of the used com data object which is the
                 return value of Os_XSigChannelGetReceiveElement.
                 The OutParameter parameter is derived from the receive data of the used com data object which is the
                 return value of Os_XSigChannelGetReceiveElement.
 \COUNTERMEASURE \M [CM_OS_XSIGTHREAD2XSIGISR_M]
                 \M [CM_OS_XSIGISR_FUNCTIONTABLE_M]
                 \M [CM_OS_XSIGFUNCTIONTABLE_FUNCTIONDESCRIPTION_M]
                 \R [CM_OS_XSIGSENDDATA_FUNCTIONIDX_R]
                 \M [CM_OS_XSIGCOM_SENDDATA_M]
                 \M [CM_OS_XSIGCOM_RECEIVCEDATA_M]
                 \M [CM_OS_XSIGCHANNELGETRECEIVEELEMENT_01_03_M]
                 \M [CM_OS_XSIGCHANNELGETRECEIVEELEMENT_02_03_M]
                 \T [CM_OS_XSIGCHANNELGETRECEIVEELEMENT_03_03_T]

\ID SBSW_OS_XSIG_RECVDATA_001
 \DESCRIPTION    Write access to the receive data derived from the return value of Os_XSigChannelGetReceiveElement.
 \COUNTERMEASURE \M [CM_OS_XSIGCOM_RECEIVCEDATA_M]
                 \M [CM_OS_XSIGCHANNELGETRECEIVEELEMENT_01_03_M]
                 \M [CM_OS_XSIGCHANNELGETRECEIVEELEMENT_02_03_M]
                 \T [CM_OS_XSIGCHANNELGETRECEIVEELEMENT_03_03_T]

\ID SBSW_OS_XSIG_XSIGCHANNELREPLY_001
 \DESCRIPTION    Os_XSigChannelReply is called with a receive channel derived from a receive port.
                 The receive port is derived with an index from the receive port list of a XSigIsr. The XSigIsr
                 is the return value of Os_XSigThread2XSigIsr.
 \COUNTERMEASURE \M [CM_OS_XSIGTHREAD2XSIGISR_M]
                 \M [CM_OS_XSIGISR_RECVPORTREFS_01_03_M]
                 \M [CM_OS_XSIGISR_RECVPORTREFS_02_03_M]
                 \R [CM_OS_XSIGISR_RECVPORTREFS_03_03_R]
                 \M [CM_OS_XSIGRECVPORT_M]
                 \R [CM_OS_XSIG_INDEX_R]

\ID SBSW_OS_XSIG_XSIGSENDPORTINIT_001
 \DESCRIPTION    Os_XSigSendPortInit is called with the return value of Os_XSigGetSendPort.
 \COUNTERMEASURE \R [CM_OS_XSIGGETSENDPORT_01_02_R]
                 \R [CM_OS_XSIGGETSENDPORT_02_02_R]

\ID SBSW_OS_XSIG_XSIGISRINIT_001
 \DESCRIPTION    Os_XSigIsrInit is called with the return value of Os_XSigGetRecvIsr.
 \COUNTERMEASURE \M [CM_OS_XSIGGETRECVISR_01_02_M]
                 \R [CM_OS_XSIGGETRECVISR_02_02_R]

\ID SBSW_OS_XSIG_XSIGSENDINTERNAL_001
 \DESCRIPTION    Os_XSigSendInternal is called with
                  - the return value of Os_XSigGetSendPortToCore
                  - two arguments passed as pointer to the caller function
                  - and one reference to a local variable.
 \COUNTERMEASURE \M [CM_OS_XSIGGETSENDPORTTOCORE_01_02_M]
                 \R [CM_OS_XSIGGETSENDPORTTOCORE_02_02_R]

\ID SBSW_OS_XSIG_XSIGCHANNELISREQUESTHANDLED_001
 \DESCRIPTION    Os_XSigChannelIsRequestHandled is called with
                  - the return value of Os_XSigGetSendPortToCore
                  - and one reference to a local variable.
 \COUNTERMEASURE \M [CM_OS_XSIGGETSENDPORTTOCORE_01_02_M]
                 \R [CM_OS_XSIGGETSENDPORTTOCORE_02_02_R]

\ID SBSW_OS_XSIG_SENDDATA_001
 \DESCRIPTION    Write access to the send data derived from the return value of Os_XSigChannelGetSendElement.
 \COUNTERMEASURE \R [CM_OS_XSIGCHANNELGETSENDELEMENT_R]
                 \M [CM_OS_XSIGCOM_SENDDATA_M]

\ID SBSW_OS_XSIG_SENDDATA_002
 \DESCRIPTION    Write access to the send data derived from the out value of Os_XSigSendInternal.
 \COUNTERMEASURE \R [CM_OS_XSIGSENDINTERNAL_R]
                 \M [CM_OS_XSIGCOM_SENDDATA_M]

\ID SBSW_OS_XSIG_TASKGETCORE_001
 \DESCRIPTION    Os_TaskGetCore is called with the return value of Os_TaskId2Task.
 \COUNTERMEASURE \M [CM_OS_TASKID2TASK_M]

\ID SBSW_OS_XSIG_THREADGETCORE_001
 \DESCRIPTION    Os_ThreadGetCore is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_XSIG_THREADGETCORE_002
 \DESCRIPTION    Os_ThreadGetCore is called with the return value of Os_IsrGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_XSIG_THREADGETCORE_003
 \DESCRIPTION    Os_ThreadGetCore is called with the return value of Os_HookGetThread.
 \COUNTERMEASURE \N [CM_OS_HOOKCALLBACKGETTHREAD_N]

\ID SBSW_OS_XSIG_HOOKGETTHREAD_001
 \DESCRIPTION    Os_HookGetThread is called with the return value of Os_HookId2Hook.
 \COUNTERMEASURE \M [CM_OS_HOOKID2HOOK_M]

\ID SBSW_OS_XSIG_COREASRCHECKISCORELOCAL_001
 \DESCRIPTION    Os_CoreAsrCheckIsCoreLocal is called with the return values of Os_TaskGetCore.
 \COUNTERMEASURE \M [CM_OS_TASKGETCORE_M]

\ID SBSW_OS_XSIG_COREASRCHECKISCORELOCAL_002
 \DESCRIPTION    Os_CoreAsrCheckIsCoreLocal is called with the return values of Os_CounterGetCore.
 \COUNTERMEASURE \M [CM_OS_COUNTERGETCORE_M]

\ID SBSW_OS_XSIG_COREASRCHECKISCORELOCAL_003
 \DESCRIPTION    Os_CoreAsrCheckIsCoreLocal is called with the return values of Os_AlarmGetCore.
 \COUNTERMEASURE \M [CM_OS_ALARMGETCORE_M]

\ID SBSW_OS_XSIG_COREASRCHECKISCORELOCAL_004
 \DESCRIPTION    Os_CoreAsrCheckIsCoreLocal is called with the return values of Os_SchTGetCore.
                 Precondition ensures that the return value of Os_SchTGetCore is valid. The compliance of the
                 precondition is check during review.
 \COUNTERMEASURE \N [CM_OS_SCHTGETCORE_N]

\ID SBSW_OS_XSIG_COREASRCHECKISCORELOCAL_005
 \DESCRIPTION    Os_CoreAsrCheckIsCoreLocal is called with the return value of Os_ThreadGetCore.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_XSIG_COREASRCHECKISCORELOCAL_006
 \DESCRIPTION    Os_CoreAsrCheckIsCoreLocal is called with the return values of Os_Core2AsrCore.
 \COUNTERMEASURE \M [CM_OS_COREID2CORE_M]

\ID SBSW_OS_XSIG_COREASRCHECKISCORELOCAL_007
 \DESCRIPTION    Os_CoreAsrCheckIsCoreLocal is called with the return values of Os_AppGetCore.
 \COUNTERMEASURE \M [CM_OS_APPGETCORE_M]

\ID SBSW_OS_XSIG_TASKACTIVATELOCALTASK_001
 \DESCRIPTION    Os_TaskActivateLocalTask is called with the return value of Os_TaskId2Task.
 \COUNTERMEASURE \M [CM_OS_TASKID2TASK_M]

\ID SBSW_OS_XSIG_TASKGETSTATELOCAL_001
 \DESCRIPTION    Os_TaskGetStateLocal is called with the return value of Os_TaskId2Task and a pointer derived from
                 an argument passed to the caller. The correctness of the caller argument
                 is ensured by precondition. The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_TASKID2TASK_M]

\ID SBSW_OS_XSIG_COUNTERGETCORE_001
 \DESCRIPTION    Os_CounterGetCore is called with the return value of Os_CounterId2Counter.
 \COUNTERMEASURE \M [CM_OS_COUNTERID2COUNTER_M]

\ID SBSW_OS_XSIG_COUNTERGETUSERVALUELOCAL_001
 \DESCRIPTION    Os_CounterGetUserValueLocal is called with the return value of Os_CounterId2Counter and a pointer
                 derived from an argument passed to the caller. The correctness of the caller argument
                 is ensured by precondition. The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_COUNTERID2COUNTER_M]

\ID SBSW_OS_XSIG_EVENTSETLOCAL_001
 \DESCRIPTION    Os_EventSetLocal is called with the return value of Os_TaskId2Task.
 \COUNTERMEASURE \M [CM_OS_TASKID2TASK_M]

\ID SBSW_OS_XSIG_EVENTGETLOCAL_001
 \DESCRIPTION    Os_EventGetLocal is called with the return value of Os_TaskId2Task and a pointer
                 derived from an argument passed to the caller. The correctness of the caller argument
                 is ensured by precondition. The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_TASKID2TASK_M]

\ID SBSW_OS_XSIG_ALARMGETALARMLOCAL_001
 \DESCRIPTION    Os_AlarmGetAlarmLocal is called with the return value of Os_AlarmId2Alarm and a pointer
                 derived from an argument passed to the caller. The correctness of the caller argument
                 is ensured by precondition. The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_ALARMID2ALARM_M]

\ID SBSW_OS_XSIG_ALARMGETCORE_001
 \DESCRIPTION    Os_AlarmGetCore is called with the return value of Os_AlarmId2Alarm.
 \COUNTERMEASURE \M [CM_OS_ALARMID2ALARM_M]

\ID SBSW_OS_XSIG_ALARMSETRELALARMLOCAL_001
 \DESCRIPTION    Os_AlarmSetRelAlarmLocal is called with the return value of Os_AlarmId2Alarm.
 \COUNTERMEASURE \M [CM_OS_ALARMID2ALARM_M]

\ID SBSW_OS_XSIG_ALARMSETABSALARMLOCAL_001
 \DESCRIPTION    Os_AlarmSetAbsAlarmLocal is called with the return value of Os_AlarmId2Alarm.
 \COUNTERMEASURE \M [CM_OS_ALARMID2ALARM_M]

\ID SBSW_OS_XSIG_ALARMCANCELALARMLOCAL_001
 \DESCRIPTION    Os_AlarmCancelAlarmLocal is called with the return value of Os_AlarmId2Alarm.
 \COUNTERMEASURE \M [CM_OS_ALARMID2ALARM_M]

\ID SBSW_OS_XSIG_SCHTGETCORE_001
 \DESCRIPTION    Os_SchTGetCore function is called with the return value of Os_SchTId2SchT.
 \COUNTERMEASURE \M [CM_OS_SCHTID2SCHT_M]

\ID SBSW_OS_XSIG_SCHTSTARTSCHEDULETABLERELLOCAL_001
 \DESCRIPTION    Os_SchTStartScheduleTableRelLocal function is called with the return value of Os_SchTId2SchT.
 \COUNTERMEASURE \M [CM_OS_SCHTID2SCHT_M]

\ID SBSW_OS_XSIG_SCHTSTARTSCHEDULETABLEABSLOCAL_001
 \DESCRIPTION    Os_SchTStartScheduleTableAbsLocal function is called with the return value of Os_SchTId2SchT.
 \COUNTERMEASURE \M [CM_OS_SCHTID2SCHT_M]

\ID SBSW_OS_XSIG_SCHTSTOPSCHEDULETABLELOCAL_001
 \DESCRIPTION    Os_SchTStopScheduleTableLocal function is called with the return value of Os_SchTId2SchT.
 \COUNTERMEASURE \M [CM_OS_SCHTID2SCHT_M]

\ID SBSW_OS_XSIG_SCHTNEXTSCHEDULETABLELOCAL_001
 \DESCRIPTION    Os_SchTNextScheduleTableLocal function is called with the return values of Os_SchTId2SchT.
                 The correctness of the caller argument
                 is ensured by precondition. The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_SCHTID2SCHT_M]

\ID SBSW_OS_XSIG_SCHTGETSCHEDULETABLESTATUSLOCAL_001
 \DESCRIPTION    Os_SchTGetScheduleTableStatusLocal function is called with the return values of Os_SchTId2SchT.
                 The correctness of the caller argument
                 is ensured by precondition. The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_SCHTID2SCHT_M]

\ID SBSW_OS_XSIG_STACKGETTASKSTACKUSAGELOCAL_001
 \DESCRIPTION    Os_StackGetTaskStackUsageLocal function is called with the return value of Os_TaskId2Task.
 \COUNTERMEASURE \M [CM_OS_TASKID2TASK_M]

\ID SBSW_OS_XSIG_ISRGETTHREAD_001
 \DESCRIPTION    Os_IsrGetThread is called with the return value of Os_IsrId2Isr.
 \COUNTERMEASURE \M [CM_OS_ISRID2ISR_M]

\ID SBSW_OS_XSIG_STACKGETISRSTACKUSAGELOCAL_001
 \DESCRIPTION    Os_StackGetISRStackUsageLocal is called with the return value of Os_IsrId2Isr.
 \COUNTERMEASURE \M [CM_OS_ISRID2ISR_M]

\ID SBSW_OS_XSIG_CORE2ASRCORE_001
 \DESCRIPTION    Os_Core2AsrCore is called with the return value of Os_CoreId2Core.
 \COUNTERMEASURE \M [CM_OS_COREID2CORE_M]

\ID SBSW_OS_XSIG_CORECHECKISASRCORE_001
 \DESCRIPTION    Os_CoreCheckIsAsrCore is called with the return value of Os_CoreId2Core.
 \COUNTERMEASURE \M [CM_OS_COREID2CORE_M]

\ID SBSW_OS_XSIG_CORECONTROLIDLE_001
 \DESCRIPTION    Os_CoreControlIdle is called with the return value of Os_ThreadGetCore.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_XSIG_STACKGETUSAGE_001
 \DESCRIPTION    A Os_StackGet*Usage function is called with the return value of Os_Core2AsrCore.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_XSIG_APPTERMINATEAPPLICATIONLOCAL_001
 \DESCRIPTION    Os_AppTerminateApplicationLocal is called with the return value of Os_AppGetCore.
 \COUNTERMEASURE \M [CM_OS_APPGETCORE_M]

\ID SBSW_OS_XSIG_APPGETCORE_001
 \DESCRIPTION    Os_AppGetCore is called with the return value of Os_AppId2App.
 \COUNTERMEASURE \M [CM_OS_APPID2APP_M]

\ID SBSW_OS_XSIG_APPGETAPPLICATIONSTATELOCAL_001
 \DESCRIPTION    Os_AppGetApplicationStateLocal function is called with the return value of Os_AppId2App and a pointer
                 derived from an argument passed to the caller. The correctness of the caller argument
                 is ensured by precondition. The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_APPID2APP_M]

\ID SBSW_OS_XSIG_XSIGSEND_001
 \DESCRIPTION    An Os_XSigSend* function is called with values passed as parameters to the caller function and pointer
                 to local variables.
 \COUNTERMEASURE \N [CM_OS_PRECONDITION_N]

\ID SBSW_OS_XSIG_XSIGCHANNELSEND_001
 \DESCRIPTION    Write access to the Dyn member of a XSigChannelSend object. The channel is passed as argument to the
                 caller. The correctness of the caller argument
                 is ensured by precondition. The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_XSIGCHANNELSEND_DYN_M]

\ID SBSW_OS_XSIG_XSIGCHANNELRECV_001
 \DESCRIPTION    Write access to the Dyn member of a XSigChannelRecv object. The channel is passed as argument to the
                 caller. The correctness of the caller argument
                 is ensured by precondition. The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_XSIGCHANNELRECV_DYN_M]

\ID SBSW_OS_XSIG_XSIGCHANNELIDXINCREMENT_001
 \DESCRIPTION    Os_XSigChannelIdxIncrement is called with a reference derived from the Dyn member of a XSigChannelSend
                 object. The channel is passed as argument to the caller. The correctness of the caller argument
                 is ensured by precondition. The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_XSIGCHANNELSEND_DYN_M]

\ID SBSW_OS_XSIG_XSIGCHANNELIDXINCREMENT_002
 \DESCRIPTION    Os_XSigChannelIdxIncrement is called with a reference derived from the Dyn member of a XSigChannelRecv
                 object. The channel is passed as argument to the caller. The correctness of the caller argument
                 is ensured by precondition. The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_XSIGCHANNELRECV_DYN_M]

\ID SBSW_OS_XSIG_HOOKCALLCALLBACKLOCAL_001
 \DESCRIPTION    Os_HookCallCallbackLocal is called with the return value of Os_Hook2CallbackHook.
 \COUNTERMEASURE \N [CM_OS_HOOK2CALLBACKHOOK_PRE_N]

\ID SBSW_OS_XSIG_HOOK2CALLBACKHOOK_001
 \DESCRIPTION    Os_Hook2CallbackHook is called with the return value of Os_HookId2Hook.
 \COUNTERMEASURE \M [CM_OS_HOOKID2HOOK_M]

\ID SBSW_OS_XSIG_TASKGETACCESSINGAPPLICATIONS_001
 \DESCRIPTION    Os_TaskGetAccessingApplications is called with the return value of Os_TaskId2Task.
 \COUNTERMEASURE \M [CM_OS_TASKID2TASK_M]

\ID SBSW_OS_XSIG_COUNTERGETACCESSINGAPPLICATIONS_001
 \DESCRIPTION     Os_CounterGetAccessingApplications is called with the return value of Os_CounterId2Counter.
 \COUNTERMEASURE  \M [CM_OS_COUNTERID2COUNTER_M]

\ID SBSW_OS_XSIG_ALARMGETACCESSINGAPPLICATIONS_001
 \DESCRIPTION    Os_AlarmGetApplication is called with the return value of Os_AlarmId2Alarm.
 \COUNTERMEASURE \M [CM_OS_ALARMID2ALARM_M]

\ID SBSW_OS_XSIG_SCHTGETACCESSINGAPPLICATIONS_001
 \DESCRIPTION    Os_SchTGetAccessingApplications is called with the return value of Os_SchTId2SchT.
 \COUNTERMEASURE \M [CM_OS_SCHTID2SCHT_M]

\ID SBSW_OS_XSIG_APPCHECKMAYTERMINATE_001
 \DESCRIPTION    Os_AppCheckMayTerminate is called with the return values of Os_AppId2App() and
                 Os_ThreadGetCurrentApplication().
 \COUNTERMEASURE \M [CM_OS_APPID2APP_M].
                 No check required for Os_ThreadGetCurrentApplication (see CM_OS_THREADGETCURRENTAPPLICATION_N).

\ID SBSW_OS_XSIG_COREISSTARTEDASASR
 \DESCRIPTION    Os_CoreIsStartedAsAsr is called with the return value of Os_CoreAsr2Core.
 \COUNTERMEASURE \N [CM_OS_COREASR2CORE_N]

\ID SBSW_OS_XSIG_XSIGCHANNELRECEIVECHECKINRANGE
 \DESCRIPTION    Os_XSigChannelReceiveCheckInRange is called with a value which is derived from each RecvPort of the
                 XSigIsr. XSigIsr is returned by Os_XSigThread2XSigIsr. The receive port is derived with an index from
                 the receive port list of a XSigIsr.
 \COUNTERMEASURE \M [CM_OS_XSIGTHREAD2XSIGISR_M]
                 \M [CM_OS_XSIGISR_RECVPORTREFS_01_03_M]
                 \M [CM_OS_XSIGISR_RECVPORTREFS_02_03_M]
                 \R [CM_OS_XSIGISR_RECVPORTREFS_03_03_R]
                 \M [CM_OS_XSIGRECVPORT_M]
                 \R [CM_OS_XSIG_INDEX_R]

\ID SBSW_OS_XSIG_COREASR2CORE_001
 \DESCRIPTION    Os_CoreAsr2Core is called with a SendCore from a SendPort from a RecvPort. The RecvPorts are part of
                 the XSignIsr. XSigIsr is returned by Os_XSigThread2XSigIsr. The receive port is derived with an index
                 from the receive port list of a XSigIsr.
 \COUNTERMEASURE \M [CM_OS_XSIGRECVPORTGETSENDPORT_M]
                 \M [CM_OS_XSIGSENDPORTGETSENDCORE_M]
                 \M [CM_OS_XSIGTHREAD2XSIGISR_M]
                 \M [CM_OS_XSIGISR_RECVPORTREFS_01_03_M]
                 \M [CM_OS_XSIGISR_RECVPORTREFS_02_03_M]
                 \R [CM_OS_XSIGISR_RECVPORTREFS_03_03_R]
                 \M [CM_OS_XSIGRECVPORT_M]
                 \R [CM_OS_XSIG_INDEX_R]


SBSW_JUSTIFICATION_END */


/*
\CM CM_OS_XSIGRECVPORTGETSENDPORT_M
      Verify that the SendPort of each Os_XSigRecvPortConfigType object is a non NULL_PTR.

\CM CM_OS_XSIGSENDPORTGETSENDCORE_M
      Verify that the SendCore of each Os_XSigSendPortConfigType object is a non NULL_PTR.

\CM CM_OS_XSIGGETSENDPORTTOCORE_01_02_M
      Verify that the CoreIdx of each CoreAsr instance is lower than OS_COREASRCOREIDX_COUNT.

\CM CM_OS_XSIGGETSENDPORTTOCORE_02_02_R
      Implementation ensures, that the returned value is not used if it is a NULL_PTR.

\CM CM_OS_XSIGGETSENDPORT_01_02_R
      The called function ensures, that the returned pointer is not used for write accesses, if the pointer is NULL_PTR.

\CM CM_OS_XSIGGETSENDPORT_02_02_R
      Implementation ensures that the index passed to Os_XSigGetSendPort is valid.

\CM CM_OS_XSIGGETRECVISR_01_02_M
      Verify that:
        1. RecvIsrRefs of each Os_XSigConfigType object is a non NULL_PTR except the last one,
        2. RecvIsrRefs has a size equal to RecvIsrCount + 1 and
        3. that each XSignal's RecvIsrRefs pointer is no NULL_PTR.

\CM CM_OS_XSIGGETRECVISR_02_02_R
      Implementation ensures that the index passed to Os_XSigGetSendPort is valid.

\CM CM_OS_XSIGSENDPORT_ISR_M
      Verify that the XSigIsr reference of each SendPort instance is a non NULL_PTR.

\CM CM_OS_XSIGISR_HWCONFIG_M
      Verify that the HwConfig reference of each XSigIsr instance is a non NULL_PTR.

\CM CM_OS_XSIGCOM_SENDDATA_M
      Verify that each SendData reference of each XSigCom instance is a non NULL_PTR.

\CM CM_OS_XSIGCOM_RECEIVCEDATA_M
      Verify that each RecvData reference of each XSigCom instance is a non NULL_PTR.

\CM CM_OS_XSIGCHANNELGETRESULT_01_04_M
      Verify that the Buffer reference of each XSigSendPort instance is a non NULL_PTR.

\CM CM_OS_XSIGCHANNELGETRESULT_02_04_M
      Verify that the Buffer of each XSigSendPort instance has a size equal to the BufferSize member.

\CM CM_OS_XSIGCHANNELGETRESULT_03_04_M
      Verify that the Dyn reference of each XSigSendPort instance is a non NULL_PTR.

\CM CM_OS_XSIGCHANNELGETRESULT_04_04_T
      TCASE-345841 ensures that ResultIdx is always in a valid range.

\CM CM_OS_XSIGSENDDATA_FUNCTIONIDX_R
      Implementation ensures that the used index is in a valid range.

\CM CM_OS_XSIGISR_RECVPORTREFS_01_03_M
      Verify that the RecvPortRefs reference of each XSigIsr instance is a non NULL_PTR.

\CM CM_OS_XSIGISR_RECVPORTREFS_02_03_M
      Verify that the size of the RecvPortRefs array is equal to the RecvPortCount+1 of each XSigIsr.

\CM CM_OS_XSIGISR_RECVPORTREFS_03_03_R
      Implementation ensures that the passed index is valid.

\CM CM_OS_XSIGRECVPORT_M
      Verify that each entry of each RecvPort instance is a non NULL_PTR except the last one.

\CM CM_OS_XSIGTHREAD2XSIGISR_M
      Verify that Os_XSigRecvIsrHandler is referenced in the object HwConfig of each XSigIsr and only in XSigIsrs.

\CM CM_OS_XSIG_INDEX_R
      Implementation ensures that the used index is in a valid range.

\CM CM_OS_XSIGISR_FUNCTIONTABLE_M
      Verify that the FunctionTable reference of each XSigIsr is a non NULL_PTR.

\CM CM_OS_XSIGFUNCTIONTABLE_FUNCTIONDESCRIPTION_M
      Verify that each function refers either to the receive callback function which belongs to the corresponding
      enum identifier or that the function reference is a NULL_PTR.

\CM CM_OS_XSIGCHANNELGETRECEIVEELEMENT_01_03_M
      Verify that the Buffer reference of each XSigChannelRecv instance is a non NULL_PTR.

\CM CM_OS_XSIGCHANNELGETRECEIVEELEMENT_02_03_M
      Verify that the Buffer of each XSigChannelRecv instance has a size equal to the BufferSize member.

\CM CM_OS_XSIGCHANNELGETRECEIVEELEMENT_03_03_T
      TCASE-345841 ensures that ReceivceIdx is always in a valid range.

\CM CM_OS_XSIGCHANNELGETSENDELEMENT_R
      Implementation ensures that the pointer is not used, if it is a NULL_PTR.

\CM CM_OS_XSIGSENDINTERNAL_R
      Implementation ensures, that the output value is only used, if the returned status is OS_STATUS_OK.

\CM CM_OS_XSIGCHANNELSEND_DYN_M
      Verify that the Dyn reference of each XSigChannelSend instance is a non NULL_PTR.

\CM CM_OS_XSIGCHANNELRECV_DYN_M
      Verify that the Dyn reference of each XSigChannelRecv instance is a non NULL_PTR.

\CM CM_OS_XSIGCHANNELSEND_BUFFER_01_02_M
      Verify that the Buffer reference of each XSigChannelSend instance is a non NULL_PTR.

\CM CM_OS_XSIGCHANNELSEND_BUFFER_02_02_M
      Verify that the Buffer of each XSigChannelSend instance has a size equal to the BufferSize member.

*/
/* START_COVERAGE_JUSTIFICATION

\ID COV_OS_XSIGDOUBLECHECK
   \ACCEPT XX
   \ACCEPT XF
   \ACCEPT TX
   \REASON The receiver double checks that the sender has provided correct data here in order to detect hardware
           failures on other cores. [COV_MSR_INV_STATE]

\ID COV_OS_NOT_DETERMINISTICALLY_TESTABLE
   \ACCEPT TX
   \REASON This path is not deterministically testable since it depends on exact timing of queued interrupts on another
           core. Since instrumentation of static code passages would be required to test this functionality, we accept
           the true variant of the expression.

END_COVERAGE_JUSTIFICATION */


/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_XSignal.c
 **********************************************************************************************************************/
