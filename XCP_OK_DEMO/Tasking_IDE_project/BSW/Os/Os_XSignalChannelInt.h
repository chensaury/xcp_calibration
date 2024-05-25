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
 * \ingroup     Os_XSignal
 * \defgroup    Os_XSignalChannel XSignal Channel
 * \brief       Provides a XSignal specific circular buffer implementation.
 * \details
 * A XSignal Channel has:
 *  - a send index (on sender)
 *  - a receive index (on receiver)
 *  - a result index (on sender)
 *
 * As the buffer supports cross core communication and a core may only write to it's own data,
 * *send and result indices are held by a different object then the receive index*.
 *
 * This separation doesn't allow to have a usage counter, as this counter has to be accessed from sender and
 * receiver core.
 *
 * Therefore the buffer is empty, if send and result indices are identical.
 * The buffer is treated as full, if the incremented send index equals the result index.
 *
 * So the buffer can hold Channel->Size-1 elements.
 * The maximum Channel->Size is equal to maxValue(Os_ObjIdxType) elements.
 *
 * [Circular Channel](https:\\en.wikipedia.org/wiki/Circular_buffer)
 *
 * \{
 *
 * \file
 * \brief       Contains the buffer interface.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_XSIGNALCHANNELINT_H
# define OS_XSIGNALCHANNELINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */

/* Os kernel module dependencies */
# include "Os_XSignal_Types.h"
# include "Os_XSignal_Lcfg.h"
# include "Os_CommonInt.h"
# include "Os_ErrorInt.h"

/* Os hal dependencies */
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
/***********************************************************************************************************************
 *  Communication Data
 **********************************************************************************************************************/
/*! \brief Defines whether the communication result is acknowledged or not.
 *  \details
 *   ![XSignal Request State Machine](XSigRequest_StateMachine.png)
 */
typedef enum
{
  OS_XSIGSTATE_ASYNC_NACK,    /*!< The request is asynchronous and the result was not handled on sender side. */
  OS_XSIGSTATE_SYNC_NACK,     /*!< The request is synchronous and the result was not handled on sender side. */
  OS_XSIGSTATE_SYNC_PENDING,  /*!< The request is synchronous and the result was handled on receiver side. */
  OS_XSIGSTATE_ACK            /*!< The result of the request was handled on sender side. */
}Os_XSigState_Type;


/*! Internal representation of cross core communication port. */
typedef struct
{
  /*! Send port which holds the function call information. */
  P2VAR(Os_XSigSendDataType volatile, TYPEDEF, OS_VAR_NOINIT) SendData;

  /*! Receive port which holds the response/result of the call. */
  P2VAR(Os_XSigRecvDataType volatile, TYPEDEF, OS_VAR_NOINIT) RecvData;

  /*! The index of the ComData in the queue. */
  Os_XSigBufferIdxType Idx;
}Os_XSigComDataConfigType;
typedef P2CONST(Os_XSigComDataConfigType, AUTOMATIC, OS_CONST) Os_XSigComDataConfigRefType;


/*! Container for function call parameters. */
typedef struct
{
  /*! Array of call parameters. */
  Os_ParamType ParameterData[OS_MAX_NUM_OF_CROSS_CORE_PARAMS];
}Os_XSigParamsType;


/*! The output parameters of a function call.
 *  \details Wrapping the output parameters with a structure, allows to keep interfaces unchanged in case
 *  that AUTOSAR adds a function with more than the number of output parameters currently supported. */
typedef struct
{
  /*! The output parameter of a function. */
  Os_ParamType ParameterData;
}Os_XSigOutputParamsType;

/*! Pointer to output parameters of a function call. */
typedef P2CONST(Os_XSigOutputParamsType, AUTOMATIC, OS_CONST) Os_XSigOutputParamsRefType;


/*! Container for function result data. */
typedef struct
{
  /*! The status return code of the function call. */
  Os_StatusType Status;

  /*! Output parameter of call by reference functions. */
  Os_XSigOutputParamsType OutputParameter;
}Os_XSigResultType;


/*! Data representation of a cross core function call sender port. */
struct Os_XSigSendDataType_Tag
{
  /*! Cross core function number. */
  Os_XSigFunctionIdx FunctionIdx;

  /*! The parameter data of the remote service. */
  Os_XSigParamsType ParameterData;

  /*! Pointer to the sender thread. */
  P2CONST(Os_ThreadConfigType, TYPEDEF, OS_CONST) Sender;

  /*! Pointer to the sender application. */
  P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) SenderApp;

  Os_XSigState_Type Acknowledge;
};


/***********************************************************************************************************************
 *  Channel Data
 **********************************************************************************************************************/
/*! Data representation of a cross core function call receiver port.
 *  \details To be linked to section  type RETURNVAL<No.>_VAR
 *  where <No.> is the number of the receiving core of XSignal/RPC. */
struct Os_XSigRecvDataType_Tag
{
  /*! Return data of the cross core service (may also support other types than Os_StatusType). */
  Os_XSigResultType ReturnData;
};


/*! The possible states of the channel. */
typedef enum
{
  OS_XSIGCHANNELSTATE_OK,              /*!< Channel buffer is not full. */
  OS_XSIGCHANNELSTATE_FULL             /*!< Channel buffer is full. */
}Os_XSigChannelStateType;


/*! Defines the runtime data of a Channel sender. */
typedef struct
{
  /*! \details   The index of the next send position of the sender.
   *  \details
   *  This is also the index of the first empty element.
   *  The channel buffer is empty, if SendIdx == ResultIdx.
   *  The channel buffer is full, if SendIdx+1 == ResultIdx.
   *   */
    Os_XSigBufferIdxType SendIdx;

  /*! \brief    The index of the the next receive element.
   *  \details
   *  The elements between ResultIdx and ReceiveIdx are handled by the receiver,
   *  but the sender still has to handle/report the result.
   *  The sender has handled all results, if ResultIdx == ReceiveIdx. */
  Os_XSigBufferIdxType ResultIdx;
}Os_XSigChannelSendType;


/*! Defines the runtime data of a Channel receiver. */
typedef struct
{
  /*! \brief  The index of the element which has already been received by the receiver.
   *  \details
   *  There is no element to receive, if ReceiveIdx == SendIdx. */
  Os_XSigBufferIdxType ReceiveIdx;
}Os_XSigChannelRecvType;


/*! Defines the configuration data of a Channel. */
typedef struct
{
  /*! Pointer to the runtime send data. */
  P2VAR(Os_XSigChannelSendType volatile, AUTOMATIC, OS_VAR_NOINIT) Dyn;

  /*! Pointer to the runtime receive data. */
  P2CONST(Os_XSigChannelRecvType volatile, AUTOMATIC, OS_VAR_NOINIT) Receive;

  /*! Pointer to the buffer array. */
  P2CONST(Os_XSigComDataConfigType, AUTOMATIC, OS_CONST) Buffer;

  /*! The buffer size. */
  Os_XSigBufferIdxType BufferSize;
}Os_XSigChannelSendConfigType;


/*! Defines the configuration data of a Channel. */
typedef struct
{
  /*! Pointer to the runtime receive data. */
  P2VAR(Os_XSigChannelRecvType volatile, AUTOMATIC, OS_VAR_NOINIT) Dyn;

  /*! Pointer to the runtime send data. */
  P2CONST(Os_XSigChannelSendType volatile, AUTOMATIC, OS_VAR_NOINIT) Send;

  /*! Pointer to the buffer array. */
  P2CONST(Os_XSigComDataConfigType, AUTOMATIC, OS_CONST) Buffer;

  /*! The buffer size. */
  Os_XSigBufferIdxType BufferSize;
}Os_XSigChannelRecvConfigType;


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


/***********************************************************************************************************************
 *  Os_XSigChannelIdxIncrement()
 **********************************************************************************************************************/
/*! \brief          Increments a buffer index with respect to the buffer size.
 *  \details        --no details--
 *
 *  \param[in,out]  Index The index to be incremented. Parameter must not be NULL.
 *  \param[in]      Size  The size of the buffer.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different Channels
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_XSigChannelIdxIncrement,
(
  P2VAR(Os_XSigBufferIdxType volatile, AUTOMATIC, OS_APPL_DATA) Index,
  Os_XSigBufferIdxType Size
));


/***********************************************************************************************************************
 *  Channel Send Functions
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  Os_XSigChannelSendInit()
 **********************************************************************************************************************/
/*! \brief          Initialize the send part of a buffer (Init-Step4).
 *  \details        --no details--
 *
 *  \param[in,out]  Channel The Channel instance. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_XSigChannelSendInit,
(
  P2CONST(Os_XSigChannelSendConfigType, AUTOMATIC, OS_APPL_DATA) Channel
));


/***********************************************************************************************************************
 *  Os_XSigChannelGetSendElement()
 **********************************************************************************************************************/
/*! \brief          Returns the next send element.
 *  \details        If there a free element has been found, it is not consumed. The element is consumed by
 *                  Os_XSigChannelSend() in Os_XSigSendInternal().
 *
 *  \param[in,out]  Channel     The Channel instance. Parameter must not be NULL.
 *
 *  \return         The next send element element.
 *
 *  \retval         NULL_PTR    If there is no send element available.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different Channels
 *  \synchronous    TRUE
 *
 *  \pre            Getting the send element and sending has to be performed atomically
 *                  (see \ref Os_XSigChannelSend).
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_XSigComDataConfigType, AUTOMATIC, OS_CONST),
OS_CODE, OS_ALWAYS_INLINE, Os_XSigChannelGetSendElement,
(
  P2CONST(Os_XSigChannelSendConfigType, AUTOMATIC, OS_APPL_DATA) Channel
));


/***********************************************************************************************************************
 *  Os_XSigChannelSend()
 **********************************************************************************************************************/
/*! \brief          Sends the current send element.
 *  \details        --no details--
 *
 *  \param[in,out]  Channel    The Channel instance. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different Channels
 *  \synchronous    TRUE
 *
 *  \pre            Getting the send element and sending has to be performed atomically
 *                  (see \ref Os_XSigChannelGetSendElement).
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_XSigChannelSend,
(
  P2CONST(Os_XSigChannelSendConfigType, AUTOMATIC, OS_APPL_DATA) Channel
));


/***********************************************************************************************************************
 *  Os_XSigChannelGetResult()
 **********************************************************************************************************************/
/*! \brief          Returns the next result element.
 *  \details        --no details--
 *
 *  \param[in,out]  Channel    The Channel instance. Parameter must not be NULL.
 *
 *  \return         The next result element element.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different Channels
 *  \synchronous    TRUE
 *
 *  \pre            The caller has to check that the buffer is not full. This check, getting the buffer
 *                  and sending has to be performed atomically.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_XSigComDataConfigType, AUTOMATIC, OS_CONST),
OS_CODE, OS_ALWAYS_INLINE, Os_XSigChannelGetResult,
(
  P2CONST(Os_XSigChannelSendConfigType, AUTOMATIC, OS_APPL_DATA) Channel
));


/***********************************************************************************************************************
 *  Os_XSigChannelFreeResult()
 **********************************************************************************************************************/
/*! \brief          Releases the current eldest result element.
 *  \details        --no details--
 *
 *  \param[in,out]  Channel    The Channel instance. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different Channels
 *  \synchronous    TRUE
 *
 *  \pre            The caller has to check that the result buffer contains data. This check, getting the result element
 *                  and free it has to be performed atomically.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_XSigChannelFreeResult,
(
  P2CONST(Os_XSigChannelSendConfigType, AUTOMATIC, OS_APPL_DATA) Channel
));


/***********************************************************************************************************************
 *  Os_XSigChannelIsResultAvailable()
 **********************************************************************************************************************/
/*! \brief          Returns whether further result elements are available or not.
 *  \details        --no details--
 *
 *  \param[in]      Channel  The Channel to query. Parameter must not be NULL.
 *
 *  \retval         !0    Further result data is available.
 *  \retval         0     No more result data available.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CONST, OS_ALWAYS_INLINE,
Os_XSigChannelIsResultAvailable,
(
  P2CONST(Os_XSigChannelSendConfigType, AUTOMATIC, OS_APPL_DATA) Channel
));



/***********************************************************************************************************************
 *  Os_XSigChannelIsRequestHandled()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given request was handled by the receiver (!0) or not (0).
 *  \details        --no details--
 *
 *  \param[in]      Channel  The Channel to query. Parameter must not be NULL.
 *  \param[in]      ComData The ComData to test for result data. Parameter must not be NULL.
 *
 *  \retval         !0    The result is available.
 *  \retval         0     The result is not available.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CONST,                                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_XSigChannelIsRequestHandled,
(
  P2CONST(Os_XSigChannelSendConfigType, AUTOMATIC, OS_APPL_DATA) Channel,
  P2CONST(Os_XSigComDataConfigType, AUTOMATIC, OS_CONST) ComData
));


/***********************************************************************************************************************
 *  Channel Receive Functions
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  Os_XSigChannelReceiveInit()
 **********************************************************************************************************************/
/*! \brief          Initialize the receive part of a buffer (Init-Step4).
 *  \details        --no details--
 *
 *  \param[in,out]  Channel    The Channel instance. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different Channels
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                          /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_XSigChannelReceiveInit,
(
  P2CONST(Os_XSigChannelRecvConfigType, AUTOMATIC, OS_APPL_DATA) Channel
));


/***********************************************************************************************************************
 *  Os_XSigChannelGetReceiveElement()
 **********************************************************************************************************************/
/*! \brief          Returns the eldest received element in the buffer.
 *  \details        --no details--
 *
 *  \param[in,out]  Channel    The Channel instance. Parameter must not be NULL.
 *
 *  \return         Returns eldest received element in the buffer.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different Channels
 *  \synchronous    TRUE
 *
 *  \pre            The caller has to check that the receive buffer is not empty. This check, getting the buffer
 *                  and reply has to be performed atomically.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
P2CONST(Os_XSigComDataConfigType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE, OS_ALWAYS_INLINE,
Os_XSigChannelGetReceiveElement,
(
  P2CONST(Os_XSigChannelRecvConfigType, AUTOMATIC, OS_APPL_DATA) Channel
));


/***********************************************************************************************************************
 *  Os_XSigChannelReply()
 **********************************************************************************************************************/
/*! \brief          Tells the sender that the eldest received element contains result data.
 *  \details        --no details--
 *
 *  \param[in,out]  Channel    The Channel instance. Parameter must not be NULL.
 *
 *  \return         Returns eldest received element in the buffer.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different Channels
 *  \synchronous    TRUE
 *
 *  \pre            The caller has to check that the receive buffer is not empty. This check, getting the buffer
 *                  and reply has to be performed atomically.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                          /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_XSigChannelReply,
(
  P2CONST(Os_XSigChannelRecvConfigType, AUTOMATIC, OS_APPL_DATA) Channel
));


/***********************************************************************************************************************
 *  Os_XSigChannelIsReceiveElementAvailable()
 **********************************************************************************************************************/
/*! \brief          Returns whether the buffer contains receive elements.
 *  \details        --no details--
 *
 *  \param[in]      Channel The Channel to query. Parameter must not be NULL.
 *
 *  \retval         !0    If receive data is available.
 *  \retval         0     If no receive data is available.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CONST,                                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_XSigChannelIsReceiveElementAvailable,
(
  P2CONST(Os_XSigChannelRecvConfigType, AUTOMATIC, OS_APPL_DATA) Channel
));


/***********************************************************************************************************************
 *  Os_XSigChannelReceiveCheckInRange()
 **********************************************************************************************************************/
/*! \brief          Returns whether the channel contains the valid send index.
 *  \details        --no details--
 *
 *  \param[in]      Channel The Channel to query. Parameter must not be NULL.
 *
 *  \retval         !0    If the send index is valid.
 *  \retval         0     If the send index is not in range.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CONST,                                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_XSigChannelReceiveCheckInRange,
(
  P2CONST(Os_XSigChannelRecvConfigType, AUTOMATIC, OS_APPL_DATA) Channel
));


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */




#endif /* OS_XSIGNALCHANNELINT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_XSignalChannelInt.h
 **********************************************************************************************************************/
