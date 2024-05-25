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
 * \addtogroup Os_Ioc
 * \{
 *
 * \file
 * \brief       Provides the IOC implementation.
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777, 0779, 0828  EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */


#define OS_IOC_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Ioc_Lcfg.h"
#include "Os_Ioc.h"
#include "Os_Ioc_Cfg.h"
#include "Ioc.h"

/* Os kernel module dependencies */
#include "Os_Error.h"
#include "Os_Task.h"
#include "Os_Interrupt.h"
#include "Os_Application.h"
#include "OsInt.h"

/* Os hal dependencies */


/***********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  OS_IOC_INTERNAL_STATUS()
 **********************************************************************************************************************/
/*! \def        OS_IOC_INTERNAL_STATUS()
 *  \brief      Creates an internal IOC status code.
 *  \details    --no details--
 *
 *  \param[in]  Status    A status value in range 1...(2^24)-1
 *
 *  \return     Status code.
 **********************************************************************************************************************/
#define OS_IOC_INTERNAL_STATUS(Status)                                                                                  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */ \
  ((uint32) (((uint32)(Status)) << (sizeof(Std_ReturnType)*8u)) | (uint32)0xFF)                                         /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/***********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/*! Internal return types for receive functions (more error codes than the API functions) */
typedef enum
{
  /*! No error. */
  OS_IOC_E_INTERNAL_OK                  = IOC_E_OK,
  /*! The calling application is not the owner application of the send/receive function. */
  OS_IOC_E_INTERNAL_NOK                 = IOC_E_NOK,
  /*! Queue is empty, return value is empty. */
  OS_IOC_E_INTERNAL_NO_DATA             = IOC_E_NO_DATA,
  /*! Queue overflow detected, data lost, receive successful. */
  OS_IOC_E_INTERNAL_LOST_DATA           = IOC_E_LOST_DATA,
  /*! Queue overflow detected, data lost and queue is currently empty, receive successful. */
  OS_IOC_E_INTERNAL_LOST_AND_NO_DATA    = (IOC_E_NO_DATA | IOC_E_LOST_DATA),
  /*! Channel is inactive because of an earlier detected internal error. */
  OS_IOC_E_INTERNAL_CHANNEL_CLOSED      = OS_IOC_INTERNAL_STATUS(1u),
  /*! Channel shall be closed because of internal error (e.g. read/write-index out of range). */
  OS_IOC_E_INTERNAL_CLOSE_CHANNEL       = OS_IOC_INTERNAL_STATUS(2u)
}Os_IocInternalReturnType;


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
 *  Os_IocMultiReceiveInit()
 **********************************************************************************************************************/
/*! \brief          Initializes an Os_IocMultiReceiveConfigType object.
 *  \details        This function is called in Init-Step2 for global objects and in Init-Step4 for core local objects.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IocMultiReceiveInit,
(
  P2CONST(Os_IocMultiReceiveConfigType, AUTOMATIC, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_IocChannelIsEnabled()
 **********************************************************************************************************************/
/*! \brief          Returns whether or not the IOC channel is enabled.
 *  \details        --no details--
 *
 *  \param[in]      Ioc        IOC to query. Parameter must not be NULL.
 *
 *  \retval         !0         The IOC channel is enabled.
 *  \retval         0          The IOC channel is disabled (closed).
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_IocChannelIsEnabled,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_IocCloseChannel()
 **********************************************************************************************************************/
/*! \brief          Closes (disables) an IOC channel.
 *  \details        --no details--
 *
 *  \param[in,out]  Ioc        IOC to close. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IocCloseChannel,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_IocReceiveInit()
 **********************************************************************************************************************/
/*! \brief          Initializes an Os_IocReceiveConfigType object and its parent class objects.
 *  \details        This function is called in Init-Step2 for global objects and in Init-Step4 for core local objects.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IocReceiveInit,
(
  P2CONST(Os_IocReceiveConfigType, AUTOMATIC, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_IocReceiveCloseChannel()
 **********************************************************************************************************************/
/*! \brief          Closes (disables) receiver and sender side of an IOC channel from the receiver side.
 *  \details        --no details--
 *
 *  \param[in,out]  Ioc        IOC to close. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IocReceiveCloseChannel,
(
  P2CONST(Os_IocReceiveConfigType, AUTOMATIC, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_IocSendInit()
 **********************************************************************************************************************/
/*! \brief          Initializes an Os_IocSendConfigType object and its parent class objects.
 *  \details        This function is called in Init-Step2 for global objects and in Init-Step4 for core local objects.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IocSendInit,
(
  P2CONST(Os_IocSendConfigType, AUTOMATIC, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_IocSendCloseChannel()
 **********************************************************************************************************************/
/*! \brief          Closes (disables) receiver and sender side of an IOC channel from the sender side.
 *  \details        --no details--
 *
 *  \param[in,out]  Ioc        IOC to close. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IocSendCloseChannel,
(
  P2CONST(Os_IocSendConfigType, AUTOMATIC, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_IocMultiReceiveGetDyn()
 **********************************************************************************************************************/
/*! \brief          Returns the dynamic data.
 *  \details        --no details--
 *
 *  \param[in]      Ioc        IOC to query. Parameter must not be NULL.
 *
 *  \return         Pointer to the IOC's dynamic data.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2VAR(Os_IocMultiReceiveType volatile, AUTOMATIC, OS_VAR_NOINIT),
OS_CODE, OS_ALWAYS_INLINE, Os_IocMultiReceiveGetDyn,
(
  P2CONST(Os_IocMultiReceiveConfigType, AUTOMATIC, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_IocReceiveGetDyn()
 **********************************************************************************************************************/
/*! \brief          Returns the dynamic data.
 *  \details        --no details--
 *
 *  \param[in]      Ioc        IOC to query. Parameter must not be NULL.
 *
 *  \return         Pointer to the IOC's dynamic data.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2VAR(Os_IocReceiveType volatile, AUTOMATIC, OS_VAR_NOINIT),
OS_CODE, OS_ALWAYS_INLINE, Os_IocReceiveGetDyn,
(
  P2CONST(Os_IocReceiveConfigType, AUTOMATIC, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_IocSendGetDyn()
 **********************************************************************************************************************/
/*! \brief          Returns the dynamic data.
 *  \details        --no details--
 *
 *  \param[in]      Ioc        IOC to query. Parameter must not be NULL.
 *
 *  \return         Pointer to the IOC's dynamic data.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2VAR(Os_IocSendType volatile, AUTOMATIC, OS_VAR_NOINIT),
OS_CODE, OS_ALWAYS_INLINE, Os_IocSendGetDyn,
(
  P2CONST(Os_IocSendConfigType, AUTOMATIC, OS_CONST) Ioc
));



/***********************************************************************************************************************
 *  IOC Base
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  Os_IocLock()
 **********************************************************************************************************************/
/*! \brief          Acquire locks which are required for the given IOC.
 *  \details        --no details--
 *
 *  \param[in,out]  Ioc             IOC to query. Parameter must not be NULL.
 *  \param[out]     InterruptState  Pointer where the current interrupt state shall be stored.
 *                                  Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IocLock,
(
  P2CONST(Os_IocConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(Os_IntStateType, TYPEDEF, AUTOMATIC) InterruptState
));


/***********************************************************************************************************************
 *  Os_IocUnlock()
 **********************************************************************************************************************/
/*! \brief          Releases the IOC locks.
 *  \details        --no details--
 *
 *  \param[in,out]  Ioc             IOC to query. Parameter must not be NULL.
 *  \param[in]      InterruptState  The parameter from Os_IocLock. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IocUnlock,
(
  P2CONST(Os_IocConfigType, TYPEDEF, OS_CONST) Ioc,
  P2CONST(Os_IntStateType, TYPEDEF, AUTOMATIC) InterruptState
));


/***********************************************************************************************************************
 *  Os_IocCallCallbacks()
 **********************************************************************************************************************/
/*! \brief          Triggers execution of the receive callback.
 *  \details        --no details--
 *
 *  \param[in]      Callbacks             The callbacks to query. Parameter must not be NULL.
 *
 *  \retval         IOC_E_OK       If all callbacks are successfully triggered
 *  \retval         IOC_E_NOK      If at least one of the callbacks is not successfully triggered.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *
 *  \trace          SPEC-63565, SPEC-63577
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Std_ReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_IocCallCallbacks,
(
  P2CONST(Os_IocCallbacksConfigType, TYPEDEF, OS_CONST) Callbacks
));


/***********************************************************************************************************************
 *  Os_IocCheckNoDataLost()
 **********************************************************************************************************************/
/*! \brief          Returns whether data has been lost (OS_CHECK_FAILED) or not (!OS_CHECK_FAILED).
 *  \details        If data loss has been detected, the function updates a snapshot variable. Therefore the function
 *                  reports data loss only once per occurrence.
 *
 *  \param[in]      Ioc             IOC to query. Parameter must not be NULL.
 *
 *  \retval         OS_CHECK_FAILED   If the buffer is full.
 *  \retval         !OS_CHECK_FAILED  If the buffer is not full.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_IocCheckNoDataLost,
(
  P2CONST(Os_IocReceiveConfigType, TYPEDEF, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_IocIncrementLostCounter()
 **********************************************************************************************************************/
/*! \brief          This function has to be called when the user tries to write to the IOC while the buffer is full.
 *  \details        --no details--
 *
 *  \param[in,out]  Ioc             IOC to query. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IocIncrementLostCounter,
(
  P2CONST(Os_IocSendConfigType, TYPEDEF, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_Ioc08ReceiveInit()
 **********************************************************************************************************************/
/*! \brief          Initializes an Os_Ioc08ReceiveConfigType object and its parent class objects.
 *  \details        This function is called in Init-Step2 for global objects and in Init-Step4 for core local objects.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Ioc08ReceiveInit,
(
  P2CONST(Os_Ioc08ReceiveConfigType, TYPEDEF, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_Ioc08MultiReceiveInit()
 **********************************************************************************************************************/
/*! \brief          Initializes an Os_Ioc08MultiReceiveConfigType object and its receivers.
 *  \details        This function is called in Init-Step2 for global objects and in Init-Step4 for core local objects.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Ioc08MultiReceiveInit,
(
  P2CONST(Os_Ioc08MultiReceiveConfigType, AUTOMATIC, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_Ioc08SendInit()
 **********************************************************************************************************************/
/*! \brief          Initializes an Os_Ioc08SendConfigType object and its parent class objects.
 *  \details        This function is called in Init-Step2 for global objects and in Init-Step4 for core local objects.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Ioc08SendInit,
(
  P2CONST(Os_Ioc08SendConfigType, TYPEDEF, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_Ioc08ReceiveInternal()
 **********************************************************************************************************************/
/*! \brief          Reads one item from the IOC.
 *  \details        This function is also used for multi receive and group communication.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *  \param[out]     Data       The data read from the IOC. If the IOC is empty or inactive the content of
 *                             Data is undefined. Parameter must not be NULL.
 *
 *  \retval         OS_IOC_E_INTERNAL_OK         Reading from the IOC succeeded.
 *  \retval         OS_IOC_E_INTERNAL_CHANNEL_CLOSED Channel closed.
 *  \retval         OS_IOC_E_INTERNAL_CLOSE_CHANNEL Channel inconsistent. Receiver shall close channel.
 *  \retval         OS_IOC_E_INTERNAL_NO_DATA    The buffer is empty.
 *  \retval         OS_IOC_E_INTERNAL_LOST_DATA  The sender was unable to write all data to the IOC because of a buffer
 *                                            overflow.
 *  \retval         OS_IOC_E_INTERNAL_LOST_AND_NO_DATA Data has been lost and the queue is currently empty.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Depending on the lock type the caller has to synchronize the access to the given IOC object.
 *
 *  \trace          SPEC-63655
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE Os_IocInternalReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_Ioc08ReceiveInternal,
(
  P2CONST(Os_Ioc08ReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(uint8, TYPEDEF, AUTOMATIC) Data
));


/***********************************************************************************************************************
 *  Os_Ioc16ReceiveInit()
 **********************************************************************************************************************/
/*! \brief          Initializes an Os_Ioc16ReceiveConfigType object and its parent class objects.
 *  \details        This function is called in Init-Step2 for global objects and in Init-Step4 for core local objects.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Ioc16ReceiveInit,
(
  P2CONST(Os_Ioc16ReceiveConfigType, TYPEDEF, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_Ioc16MultiReceiveInit()
 **********************************************************************************************************************/
/*! \brief          Initializes an Os_Ioc16MultiReceiveConfigType object and its receivers.
 *  \details        This function is called in Init-Step2 for global objects and in Init-Step4 for core local objects.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Ioc16MultiReceiveInit,
(
  P2CONST(Os_Ioc16MultiReceiveConfigType, AUTOMATIC, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_Ioc16SendInit()
 **********************************************************************************************************************/
/*! \brief          Initializes an Os_Ioc16SendConfigType object and its parent class objects.
 *  \details        This function is called in Init-Step2 for global objects and in Init-Step4 for core local objects.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Ioc16SendInit,
(
  P2CONST(Os_Ioc16SendConfigType, TYPEDEF, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_Ioc16ReceiveInternal()
 **********************************************************************************************************************/
/*! \brief          Reads one item from the IOC.
 *  \details        This function is also used for multi receive and group communication.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *  \param[out]     Data       The data read from the IOC. If the IOC is empty or inactive the content of
 *                             Data is undefined. Parameter must not be NULL.
 *
 *  \retval         OS_IOC_E_INTERNAL_OK         Reading from the IOC succeeded.
 *  \retval         OS_IOC_E_INTERNAL_CHANNEL_CLOSED Channel closed.
 *  \retval         OS_IOC_E_INTERNAL_CLOSE_CHANNEL Channel inconsistent. Receiver shall close channel.
 *  \retval         OS_IOC_E_INTERNAL_NO_DATA    The buffer is empty.
 *  \retval         OS_IOC_E_INTERNAL_LOST_DATA  The sender was unable to write all data to the IOC because of a buffer
 *                                            overflow.
 *  \retval         OS_IOC_E_INTERNAL_LOST_AND_NO_DATA Data has been lost and the queue is currently empty.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Depending on the lock type the caller has to synchronize the access to the given IOC object.
 *
 *  \trace          SPEC-63655
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE Os_IocInternalReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_Ioc16ReceiveInternal,
(
  P2CONST(Os_Ioc16ReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(uint16, TYPEDEF, AUTOMATIC) Data
));


/***********************************************************************************************************************
 *  Os_Ioc32ReceiveInit()
 **********************************************************************************************************************/
/*! \brief          Initializes an Os_Ioc32ReceiveConfigType object and its parent class objects.
 *  \details        This function is called in Init-Step2 for global objects and in Init-Step4 for core local objects.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Ioc32ReceiveInit,
(
  P2CONST(Os_Ioc32ReceiveConfigType, TYPEDEF, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_Ioc32MultiReceiveInit()
 **********************************************************************************************************************/
/*! \brief          Initializes an Os_Ioc32MultiReceiveConfigType object and its receivers.
 *  \details        This function is called in Init-Step2 for global objects and in Init-Step4 for core local objects.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Ioc32MultiReceiveInit,
(
  P2CONST(Os_Ioc32MultiReceiveConfigType, AUTOMATIC, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_Ioc32SendInit()
 **********************************************************************************************************************/
/*! \brief          Initializes an Os_Ioc32SendConfigType object and its parent class objects.
 *  \details        This function is called in Init-Step2 for global objects and in Init-Step4 for core local objects.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Ioc32SendInit,
(
  P2CONST(Os_Ioc32SendConfigType, TYPEDEF, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_Ioc32ReceiveInternal()
 **********************************************************************************************************************/
/*! \brief          Reads one item from the IOC.
 *  \details        This function is also used for multi receive and group communication.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *  \param[out]     Data       The data read from the IOC. If the IOC is empty or inactive the content of
 *                             Data is undefined. Parameter must not be NULL.
 *
 *  \retval         OS_IOC_E_INTERNAL_OK         Reading from the IOC succeeded.
 *  \retval         OS_IOC_E_INTERNAL_CHANNEL_CLOSED Channel closed.
 *  \retval         OS_IOC_E_INTERNAL_CLOSE_CHANNEL Channel inconsistent. Receiver shall close channel.
 *  \retval         OS_IOC_E_INTERNAL_NO_DATA    The buffer is empty.
 *  \retval         OS_IOC_E_INTERNAL_LOST_DATA  The sender was unable to write all data to the IOC because of a buffer
 *                                            overflow.
 *  \retval         OS_IOC_E_INTERNAL_LOST_AND_NO_DATA Data has been lost and the queue is currently empty.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Depending on the lock type the caller has to synchronize the access to the given IOC object.
 *
 *  \trace          SPEC-63655
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE Os_IocInternalReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_Ioc32ReceiveInternal,
(
  P2CONST(Os_Ioc32ReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(uint32, TYPEDEF, AUTOMATIC) Data
));


/***********************************************************************************************************************
 *  Os_IocRefReceiveInit()
 **********************************************************************************************************************/
/*! \brief          Initializes an Os_IocRefReceiveConfigType object and its parent class objects.
 *  \details        This function is called in Init-Step2 for global objects and in Init-Step4 for core local objects.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IocRefReceiveInit,
(
  P2CONST(Os_IocRefReceiveConfigType, TYPEDEF, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_IocRefMultiReceiveInit()
 **********************************************************************************************************************/
/*! \brief          Initializes an Os_IocRefMultiReceiveConfigType object and its receivers.
 *  \details        This function is called in Init-Step2 for global objects and in Init-Step4 for core local objects.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IocRefMultiReceiveInit,
(
  P2CONST(Os_IocRefMultiReceiveConfigType, AUTOMATIC, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_IocRefSendInit()
 **********************************************************************************************************************/
/*! \brief          Initializes an Os_Ioc08SendConfigType object and its parent class objects.
 *  \details        This function is called in Init-Step2 for global objects and in Init-Step4 for core local objects.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IocRefSendInit,
(
  P2CONST(Os_IocRefSendConfigType, TYPEDEF, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_IocRefReceiveInternal()
 **********************************************************************************************************************/
/*! \brief          Reads one item from the IOC.
 *  \details        This function is also used for multi receive and group communication.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *  \param[out]     Data       The data read from the IOC. If the IOC is empty or inactive the content of
 *                             Data is undefined. Parameter must not be NULL.
 *
 *  \retval         OS_IOC_E_INTERNAL_OK         Reading from the IOC succeeded.
 *  \retval         OS_IOC_E_INTERNAL_CHANNEL_CLOSED Channel closed.
 *  \retval         OS_IOC_E_INTERNAL_CLOSE_CHANNEL Channel inconsistent. Receiver shall close channel.
 *  \retval         OS_IOC_E_INTERNAL_NO_DATA    The buffer is empty.
 *  \retval         OS_IOC_E_INTERNAL_LOST_DATA  The sender was unable to write all data to the IOC because of a buffer
 *                                            overflow.
 *  \retval         OS_IOC_E_INTERNAL_LOST_AND_NO_DATA Data has been lost and the queue is currently empty.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Depending on the lock type the caller has to synchronize the access to the given IOC object.
 *
 *  \trace          SPEC-63655
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE Os_IocInternalReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_IocRefReceiveInternal,
(
  P2CONST(Os_IocRefReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(void, TYPEDEF, AUTOMATIC) Data
));


/***********************************************************************************************************************
 *  Os_IocWriteInit()
 **********************************************************************************************************************/
/*! \brief          Initializes an Os_IocWriteConfigType object and its parent class objects.
 *  \details        This function is called in Init-Step2 for global objects and in Init-Step4 for core local objects.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Local core is an AUTOSAR core.
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IocWriteInit,
(
  P2CONST(Os_IocWriteConfigType, TYPEDEF, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_IocIoc2Ioc08MultiReceive()
 **********************************************************************************************************************/
/*! \brief          Returns the Ioc08MultiReceive corresponding to an Ioc.
 *  \details        --no details--
 *
 *  \param[in]      Ioc     IOC to translate. Parameter must not be NULL and must be of type Ioc08MultiReceive.
 *
 *  \return         The Ioc08MultiReceive corresponding to the given Ioc.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE P2CONST(Os_Ioc08MultiReceiveConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE,
Os_IocIoc2Ioc08MultiReceive,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_IocIoc2Ioc16MultiReceive()
 **********************************************************************************************************************/
/*! \brief          Returns the Ioc16MultiReceive corresponding to an Ioc.
 *  \details        --no details--
 *
 *  \param[in]      Ioc     IOC to translate. Parameter must not be NULL and must be of type Ioc16MultiReceive.
 *
 *  \return         The Ioc16MultiReceive corresponding to the given Ioc.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE P2CONST(Os_Ioc16MultiReceiveConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE,
Os_IocIoc2Ioc16MultiReceive,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_IocIoc2Ioc32MultiReceive()
 **********************************************************************************************************************/
/*! \brief          Returns the Ioc32MultiReceive corresponding to an Ioc.
 *  \details        --no details--
 *
 *  \param[in]      Ioc     IOC to translate. Parameter must not be NULL and must be of type Ioc32MultiReceive.
 *
 *  \return         The Ioc32MultiReceive corresponding to the given Ioc.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE P2CONST(Os_Ioc32MultiReceiveConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE,
Os_IocIoc2Ioc32MultiReceive,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_IocIoc2IocRefMultiReceive()
 **********************************************************************************************************************/
/*! \brief          Returns the IocRefMultiReceive corresponding to an Ioc.
 *  \details        --no details--
 *
 *  \param[in]      Ioc     IOC to translate. Parameter must not be NULL and must be of type IocRefMultiReceive.
 *
 *  \return         The IocRefMultiReceive corresponding to the given Ioc.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE P2CONST(Os_IocRefMultiReceiveConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE,
Os_IocIoc2IocRefMultiReceive,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_IocIoc2IocWrite()
 **********************************************************************************************************************/
/*! \brief          Returns the IocWrite corresponding to an Ioc.
 *  \details        --no details--
 *
 *  \param[in]      Ioc     IOC to translate. Parameter must not be NULL and must be of type IocWrite.
 *
 *  \return         The IocWrite corresponding to the given Ioc.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_IocWriteConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_IocIoc2IocWrite,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_IocIoc2Ioc08Receive()
 **********************************************************************************************************************/
/*! \brief          Returns the Ioc08Receive corresponding to an Ioc.
 *  \details        --no details--
 *
 *  \param[in]      Ioc     IOC to translate. Parameter must not be NULL and must be of type Ioc08Receive.
 *
 *  \return         The Ioc08Receive corresponding to the given Ioc.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_Ioc08ReceiveConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_IocIoc2Ioc08Receive,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_IocIoc2Ioc16Receive()
 **********************************************************************************************************************/
/*! \brief          Returns the Ioc16Receive corresponding to an Ioc.
 *  \details        --no details--
 *
 *  \param[in]      Ioc     IOC to translate. Parameter must not be NULL and must be of type Ioc16Receive.
 *
 *  \return         The Ioc16Receive corresponding to the given Ioc.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_Ioc16ReceiveConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_IocIoc2Ioc16Receive,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_IocIoc2Ioc32Receive()
 **********************************************************************************************************************/
/*! \brief          Returns the Ioc32Receive corresponding to an Ioc.
 *  \details        --no details--
 *
 *  \param[in]      Ioc     IOC to translate. Parameter must not be NULL and must be of type Ioc32Receive.
 *
 *  \return         The Ioc32Receive corresponding to the given Ioc.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_Ioc32ReceiveConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_IocIoc2Ioc32Receive,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_IocIoc2IocRefReceive()
 **********************************************************************************************************************/
/*! \brief          Returns the IocRefReceive corresponding to an Ioc.
 *  \details        --no details--
 *
 *  \param[in]      Ioc     IOC to translate. Parameter must not be NULL and must be of type IocRefReceive.
 *
 *  \return         The IocRefReceive corresponding to the given Ioc.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_IocRefReceiveConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_IocIoc2IocRefReceive,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_IocIoc2Ioc08Send()
 **********************************************************************************************************************/
/*! \brief          Returns the Ioc08Send corresponding to an Ioc.
 *  \details        --no details--
 *
 *  \param[in]      Ioc     IOC to translate. Parameter must not be NULL and must be of type Ioc08Send.
 *
 *  \return         The Ioc08Send corresponding to the given Ioc.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_Ioc08SendConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_IocIoc2Ioc08Send,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_IocIoc2Ioc16Send()
 **********************************************************************************************************************/
/*! \brief          Returns the Ioc16Send corresponding to an Ioc.
 *  \details        --no details--
 *
 *  \param[in]      Ioc     IOC to translate. Parameter must not be NULL and must be of type Ioc16Send.
 *
 *  \return         The Ioc16Send corresponding to the given Ioc.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_Ioc16SendConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_IocIoc2Ioc16Send,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_IocIoc2Ioc32Send()
 **********************************************************************************************************************/
/*! \brief          Returns the Ioc32Send corresponding to an Ioc.
 *  \details        --no details--
 *
 *  \param[in]      Ioc     IOC to translate. Parameter must not be NULL and must be of type Ioc32Send.
 *
 *  \return         The Ioc32Send corresponding to the given Ioc.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_Ioc32SendConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_IocIoc2Ioc32Send,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_IocIoc2IocRefSend()
 **********************************************************************************************************************/
/*! \brief          Returns the IocRefSend corresponding to an Ioc.
 *  \details        --no details--
 *
 *  \param[in]      Ioc     IOC to translate. Parameter must not be NULL and must be of type IocRefSend.
 *
 *  \return         The IocRefSend corresponding to the given Ioc.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_IocRefSendConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_IocIoc2IocRefSend,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_IocInitBase()
 **********************************************************************************************************************/
/*! \brief          Initializes an Os_IocConfigType object.
 *  \details        --no details--
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_IocInitBase,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_IocInitInternal()
 **********************************************************************************************************************/
/*! \brief          Initializes an Os_IocConfigType object.
 *  \details        --no details--
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Local core is an AUTOSAR core.
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_IocInitInternal                                                                                  /* PRQA S 3449 */ /* MD_Os_Rule8.5_3449 */
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
);


/***********************************************************************************************************************
 *  Os_IocEmptyMultiQueue()
 **********************************************************************************************************************/
/*! \brief      Empty multiple the queue content of a multireceive IOC.
 *  \details    Abstract function EmptyMultiQueue function. Depending on the actual IOC subclass it calls the concrete
 *              *EmptyMultiQueue function.
 *
 *  \param[in,out] Ioc       IOC to empty. Parameter must not be NULL.
 *  \param[in]     SubClass  IOC MultiReceive subclass.
 *
 *  \retval     IOC_E_OK  Content of the queue was successfully deleted.
 *
 *  \context    ANY
 *
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *
 *  \pre        -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Std_ReturnType, OS_CODE,
OS_ALWAYS_INLINE, Os_IocEmptyMultiQueue,
(
  P2CONST(Os_IocMultiReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  Os_IocSubClassType SubClass
));


/***********************************************************************************************************************
 *  Os_IocGetAccessingApplications()
 **********************************************************************************************************************/
/*! \brief          Get applications which have access to the given object.
 *  \details        --no details--
 *
 *  \param[in,out]  Task  The object to query. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_AppAccessMaskType, OS_CODE, OS_ALWAYS_INLINE,
Os_IocGetAccessingApplications,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_IocIoc2IocWrite()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE P2CONST(Os_IocWriteConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_IocIoc2IocWrite,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
))
{
  /* #10 Perform cast on given pointer. */
  return (P2CONST(Os_IocWriteConfigType, AUTOMATIC, OS_CONST))Ioc;                                                      /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  Os_IocIoc2Ioc08Receive()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE P2CONST(Os_Ioc08ReceiveConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE,
Os_IocIoc2Ioc08Receive,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
))
{
  /* #10 Perform cast on given pointer. */
  return (P2CONST(Os_Ioc08ReceiveConfigType, AUTOMATIC, OS_CONST))Ioc;                                                  /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  Os_IocIoc2Ioc16Receive()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE P2CONST(Os_Ioc16ReceiveConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE,
Os_IocIoc2Ioc16Receive,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
))
{
  /* #10 Perform cast on given pointer. */
  return (P2CONST(Os_Ioc16ReceiveConfigType, AUTOMATIC, OS_CONST))Ioc;                                                  /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  Os_IocIoc2Ioc32Receive()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE P2CONST(Os_Ioc32ReceiveConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE,
Os_IocIoc2Ioc32Receive,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
))
{
  /* #10 Perform cast on given pointer. */
  return (P2CONST(Os_Ioc32ReceiveConfigType, AUTOMATIC, OS_CONST))Ioc;                                                  /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  Os_IocIoc2IocRefReceive()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE P2CONST(Os_IocRefReceiveConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE,
Os_IocIoc2IocRefReceive,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
))
{
  /* #10 Perform cast on given pointer. */
  return (P2CONST(Os_IocRefReceiveConfigType, AUTOMATIC, OS_CONST))Ioc;                                                 /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  Os_IocIoc2Ioc08MultiReceive()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE P2CONST(Os_Ioc08MultiReceiveConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE,
Os_IocIoc2Ioc08MultiReceive,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
))
{
  return (P2CONST(Os_Ioc08MultiReceiveConfigType, AUTOMATIC, OS_CONST))Ioc;                                             /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  Os_IocIoc2Ioc16MultiReceive()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE P2CONST(Os_Ioc16MultiReceiveConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE,
Os_IocIoc2Ioc16MultiReceive,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
))
{
  return (P2CONST(Os_Ioc16MultiReceiveConfigType, AUTOMATIC, OS_CONST))Ioc;                                             /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  Os_IocIoc2Ioc32MultiReceive()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE P2CONST(Os_Ioc32MultiReceiveConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE,
Os_IocIoc2Ioc32MultiReceive,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
))
{
  return (P2CONST(Os_Ioc32MultiReceiveConfigType, AUTOMATIC, OS_CONST))Ioc;                                             /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  Os_IocIoc2IocRefMultiReceive()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE P2CONST(Os_IocRefMultiReceiveConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE,
Os_IocIoc2IocRefMultiReceive,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
))
{
  return (P2CONST(Os_IocRefMultiReceiveConfigType, AUTOMATIC, OS_CONST))Ioc;                                            /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  Os_IocIoc2Ioc08Send()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE P2CONST(Os_Ioc08SendConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE,
Os_IocIoc2Ioc08Send,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
))
{
  return (P2CONST(Os_Ioc08SendConfigType, AUTOMATIC, OS_CONST))Ioc;                                                     /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  Os_IocIoc2Ioc16Send()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE P2CONST(Os_Ioc16SendConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_IocIoc2Ioc16Send,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
))
{
  return (P2CONST(Os_Ioc16SendConfigType, AUTOMATIC, OS_CONST))Ioc;                                                     /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  Os_IocIoc2Ioc32Send()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE P2CONST(Os_Ioc32SendConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_IocIoc2Ioc32Send,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
))
{
  return (P2CONST(Os_Ioc32SendConfigType, AUTOMATIC, OS_CONST))Ioc;                                                     /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  Os_IocIoc2IocRefSend()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE P2CONST(Os_IocRefSendConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_IocIoc2IocRefSend,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
))
{
  return (P2CONST(Os_IocRefSendConfigType, AUTOMATIC, OS_CONST))Ioc;                                                    /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  Os_IocInitBase()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_IocInitBase,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
))
{
  /* #10 Initialize all fields. */
  Ioc->Dyn->State = OS_IOCCHANNELSTATE_ENABLED;                                                                         /* SBSW_OS_PWA_ABSTRACT_DYN */
}


/***********************************************************************************************************************
 *  Os_IocInitInternal()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_IocInitInternal
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
)
{
  /* #10 If Ioc is not enabled: KernelPanic. */
  if(Os_IocIsEnabled() == 0u)                                                                                           /* COV_OS_INVSTATE */
  {
    Os_ErrKernelPanic();
  }
  else
  {
    /* #20 Otherwise, call initialization functions of sub classes */
    switch(Ioc->SubClass)
    {
      case Ioc08Receive:
        Os_Ioc08ReceiveInit(       Os_IocIoc2Ioc08Receive(Ioc)      );                                                  /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_IOC_IOC08RECEIVEINIT_001 */
        break;
      case Ioc08MultiReceive:
        Os_Ioc08MultiReceiveInit(  Os_IocIoc2Ioc08MultiReceive(Ioc) );                                                  /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_IOC_IOC08MULTIRECEIVEINIT_001 */
        break;
      case Ioc08Send:
        Os_Ioc08SendInit(          Os_IocIoc2Ioc08Send(Ioc)         );                                                  /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_IOC_IOC08SENDINIT_001 */
        break;
      case Ioc16Receive:
        Os_Ioc16ReceiveInit(       Os_IocIoc2Ioc16Receive(Ioc)      );                                                  /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_IOC_IOC16RECEIVEINIT_001 */
        break;
      case Ioc16MultiReceive:
        Os_Ioc16MultiReceiveInit(  Os_IocIoc2Ioc16MultiReceive(Ioc) );                                                  /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_IOC_IOC16MULTIRECEIVEINIT_001 */
        break;
      case Ioc16Send:
        Os_Ioc16SendInit(          Os_IocIoc2Ioc16Send(Ioc)         );                                                  /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_IOC_IOC16SENDINIT_001 */
       break;
      case Ioc32Receive:
        Os_Ioc32ReceiveInit(       Os_IocIoc2Ioc32Receive(Ioc)      );                                                  /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_IOC_IOC32RECEIVEINIT_001 */
        break;
      case Ioc32MultiReceive:
        Os_Ioc32MultiReceiveInit(  Os_IocIoc2Ioc32MultiReceive(Ioc) );                                                  /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_IOC_IOC32MULTIRECEIVEINIT_001 */
        break;
      case Ioc32Send:
        Os_Ioc32SendInit(          Os_IocIoc2Ioc32Send(Ioc)         );                                                  /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_IOC_IOC32SENDINIT_001 */
        break;
      case IocRefReceive:
        Os_IocRefReceiveInit(      Os_IocIoc2IocRefReceive(Ioc)     );                                                  /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_IOC_IOCREFRECEIVEINIT_001 */
        break;
      case IocRefMultiReceive:
        Os_IocRefMultiReceiveInit( Os_IocIoc2IocRefMultiReceive(Ioc));                                                  /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_IOC_IOCREFMULTIRECEIVEINIT_001 */
        break;
      case IocRefSend:
        Os_IocRefSendInit(         Os_IocIoc2IocRefSend(Ioc)        );                                                  /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_IOC_IOCREFSENDINIT_001 */
        break;
      case IocRead:
        /* Nothing to be done. */
        break;
      case IocWrite:
        Os_IocWriteInit(Os_IocIoc2IocWrite(Ioc));                                                                       /* SBSW_OS_IOC_IOCWRITEINIT_001 */ /* SBSW_OS_FC_PRECONDITION */
        break;
      default:                                                                                                          /* COV_OS_INVSTATE */
        Os_ErrKernelPanic();
        break;
    }
  }
}                                                                                                                       /* PRQA S 6030, 6050 */ /* MD_Os_STCYC, MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_IocChannelIsEnabled()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_IocChannelIsEnabled,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
))
{
  return (Os_StdReturnType)(Ioc->Dyn->State == OS_IOCCHANNELSTATE_ENABLED);                                             /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_IocCloseChannel()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IocCloseChannel,                       /* COV_OS_INVSTATE */
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
))                                                                                                                      /* COV_OS_INVSTATE */
{
  /* #10 Change the state of the IOC channel */
  Ioc->Dyn->State = OS_IOCCHANNELSTATE_DISABLED;                                                                        /* SBSW_OS_PWA_ABSTRACT_DYN */
}


/***********************************************************************************************************************
 *  Os_IocReceiveInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IocReceiveInit,
(
  P2CONST(Os_IocReceiveConfigType, AUTOMATIC, OS_CONST) Ioc
))
{
  /* #10 Initialize all fields. */
  Os_IocInitBase(&(Ioc->Base));                                                                                         /* SBSW_OS_FC_PRECONDITION */

  Os_IocReceiveGetDyn(Ioc)->LostCounterSnapshot = 0;                                                                    /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_IOC_IOCRECEIVEGETDYN_001 */
}


/***********************************************************************************************************************
 *  Os_IocReceiveCloseChannel()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IocReceiveCloseChannel,                /* COV_OS_INVSTATE */
(
  P2CONST(Os_IocReceiveConfigType, AUTOMATIC, OS_CONST) Ioc
))                                                                                                                      /* COV_OS_INVSTATE */
{
  /* #10 Change the state of the base class. */
  Os_IocCloseChannel(&(Ioc->Base));                                                                                     /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_IocMultiReceiveInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IocMultiReceiveInit,
(
  P2CONST(Os_IocMultiReceiveConfigType, AUTOMATIC, OS_CONST) Ioc
))
{
  /* #10 Initialize all fields. */
  Os_IocInitBase(&(Ioc->Base));                                                                                         /* SBSW_OS_FC_PRECONDITION */

  Os_IocMultiReceiveGetDyn(Ioc)->NextReceiveChannel = 0;                                                                /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_IOC_IOCMULTIRECEIVEGETDYN_001 */
}


/***********************************************************************************************************************
 *  Os_Ioc08MultiReceiveInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Ioc08MultiReceiveInit,
(
  P2CONST(Os_Ioc08MultiReceiveConfigType, AUTOMATIC, OS_CONST) Ioc
))
{
  Os_ObjIdxType idx;

  /* #10 Initialize the base class */
  Os_IocMultiReceiveInit(&(Ioc->Ioc));                                                                                  /* SBSW_OS_FC_PRECONDITION */

  /* #20 Initialize all receivers */
  for(idx = 0; idx < Ioc->Ioc.ReceiveChannelCount; idx++)
  {
    Os_Ioc08ReceiveInit(&(Ioc->Receivers[idx]));                                                                        /* SBSW_OS_IOC_IOC08RECEIVEINIT_002 */
  }
}


/***********************************************************************************************************************
 *  Os_Ioc16MultiReceiveInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Ioc16MultiReceiveInit,
(
  P2CONST(Os_Ioc16MultiReceiveConfigType, AUTOMATIC, OS_CONST) Ioc
))
{
  Os_ObjIdxType idx;

  /* #10 Initialize the base class */
  Os_IocMultiReceiveInit(&(Ioc->Ioc));                                                                                  /* SBSW_OS_FC_PRECONDITION */

  /* #20 Initialize all receivers */
  for(idx = 0; idx < Ioc->Ioc.ReceiveChannelCount; idx++)
  {
    Os_Ioc16ReceiveInit(&(Ioc->Receivers[idx]));                                                                        /* SBSW_OS_IOC_IOC16RECEIVEINIT_002 */
  }
}


/***********************************************************************************************************************
 *  Os_Ioc32MultiReceiveInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Ioc32MultiReceiveInit,
(
  P2CONST(Os_Ioc32MultiReceiveConfigType, AUTOMATIC, OS_CONST) Ioc
))
{
  Os_ObjIdxType idx;

  /* #10 Initialize the base class */
  Os_IocMultiReceiveInit(&(Ioc->Ioc));                                                                                  /* SBSW_OS_FC_PRECONDITION */

  /* #20 Initialize all receivers */
  for(idx = 0; idx < Ioc->Ioc.ReceiveChannelCount; idx++)
  {
    Os_Ioc32ReceiveInit(&(Ioc->Receivers[idx]));                                                                        /* SBSW_OS_IOC_IOC32RECEIVEINIT_002 */
  }
}


/***********************************************************************************************************************
 *  Os_IocRefMultiReceiveInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IocRefMultiReceiveInit,
(
  P2CONST(Os_IocRefMultiReceiveConfigType, AUTOMATIC, OS_CONST) Ioc
))
{
  Os_ObjIdxType idx;

  /* #10 Initialize the base class */
  Os_IocMultiReceiveInit(&(Ioc->Ioc));                                                                                  /* SBSW_OS_FC_PRECONDITION */

  /* #20 Initialize all receivers */
  for(idx = 0; idx < Ioc->Ioc.ReceiveChannelCount; idx++)
  {
    Os_IocRefReceiveInit(&(Ioc->Receivers[idx]));                                                                       /* SBSW_OS_IOC_IOCREFRECEIVEINIT_002 */
  }
}


/***********************************************************************************************************************
 *  Os_IocSendInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IocSendInit,
(
  P2CONST(Os_IocSendConfigType, AUTOMATIC, OS_CONST) Ioc
))
{
  /* #10 Initialize all fields. */
  Os_IocInitBase(&(Ioc->Base));                                                                                         /* SBSW_OS_FC_PRECONDITION */

  Os_IocSendGetDyn(Ioc)->LostCounter = 0;                                                                               /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_IOC_IOCSENDGETDYN_002 */
}


/***********************************************************************************************************************
 *  Os_IocSendCloseChannel()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IocSendCloseChannel,                   /* COV_OS_INVSTATE */
(
  P2CONST(Os_IocSendConfigType, AUTOMATIC, OS_CONST) Ioc
))                                                                                                                      /* COV_OS_INVSTATE */
{
  /* #10 Change the state of the base class. */
  Os_IocCloseChannel(&(Ioc->Base));                                                                                     /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_IocMultiReceiveGetDyn()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2VAR(Os_IocMultiReceiveType volatile, AUTOMATIC, OS_VAR_NOINIT),
OS_CODE, OS_ALWAYS_INLINE, Os_IocMultiReceiveGetDyn,
(
  P2CONST(Os_IocMultiReceiveConfigType, AUTOMATIC, OS_CONST) Ioc
))
{
  return (P2VAR(Os_IocMultiReceiveType volatile, AUTOMATIC, OS_VAR_NOINIT))(Ioc->Base.Dyn);                             /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  Os_IocReceiveGetDyn()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2VAR(Os_IocReceiveType volatile, AUTOMATIC, OS_VAR_NOINIT),
OS_CODE, OS_ALWAYS_INLINE, Os_IocReceiveGetDyn,
(
  P2CONST(Os_IocReceiveConfigType, AUTOMATIC, OS_CONST) Ioc
))
{
  return (P2VAR(Os_IocReceiveType volatile, AUTOMATIC, OS_VAR_NOINIT))(Ioc->Base.Dyn);                                  /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  Os_IocSendGetDyn()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2VAR(Os_IocSendType volatile, AUTOMATIC, OS_VAR_NOINIT),
OS_CODE, OS_ALWAYS_INLINE, Os_IocSendGetDyn,
(
  P2CONST(Os_IocSendConfigType, AUTOMATIC, OS_CONST) Ioc
))
{
  return (P2VAR(Os_IocSendType volatile, AUTOMATIC, OS_VAR_NOINIT))(Ioc->Base.Dyn);                                     /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  IOC Base
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_IocLock()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IocLock,
(
  P2CONST(Os_IocConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(Os_IntStateType, TYPEDEF, AUTOMATIC) InterruptState
))
{
  /* #10 Get the required locks depending on the lock method. */
  switch(Ioc->LockMode)
  {
    case OS_IOCLOCKMODE_NONE:
      /* Do nothing. */
      break;
    case OS_IOCLOCKMODE_INTERRUPTS:
      /* Disable interrupts. */
      Os_IntSuspend(InterruptState);                                                                                    /* SBSW_OS_FC_PRECONDITION */
      break;
    case OS_IOCLOCKMODE_SPINLOCKS:                                                                                      /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
      /* Get the spinlock. */
      /* Concurrent lock has to be prevented by the user. */
      Os_SpinlockInternalGet(Ioc->Spinlock);                                                                            /* SBSW_OS_IOC_SPINLOCKINTERNALGET_001 */
      break;
    case OS_IOCLOCKMODE_ALL:                                                                                            /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
      /* Disable Interrupts and get the spinlock. */
      Os_IntSuspend(InterruptState);                                                                                    /* SBSW_OS_FC_PRECONDITION */
      Os_SpinlockInternalGet(Ioc->Spinlock);                                                                            /* SBSW_OS_IOC_SPINLOCKINTERNALGET_001 */
      break;
    default:                                                                                                            /* COV_OS_INVSTATE */
      Os_ErrKernelPanic();
      break;
  }
}


/***********************************************************************************************************************
 *  Os_IocUnlock()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IocUnlock,
(
  P2CONST(Os_IocConfigType, TYPEDEF, OS_CONST) Ioc,
  P2CONST(Os_IntStateType, TYPEDEF, AUTOMATIC) InterruptState
))
{
  switch(Ioc->LockMode)
  {
    case OS_IOCLOCKMODE_NONE:
      /* Do nothing. */
      break;
    case OS_IOCLOCKMODE_INTERRUPTS:
      /* Enable interrupts. */
      Os_IntResume(InterruptState);                                                                                     /* SBSW_OS_FC_PRECONDITION */
      break;
    case OS_IOCLOCKMODE_SPINLOCKS:                                                                                      /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
      /* Get the spinlock. */
      Os_SpinlockInternalRelease(Ioc->Spinlock);                                                                        /* SBSW_OS_IOC_SPINLOCKINTERNALRELEASE_001 */
      break;
    case OS_IOCLOCKMODE_ALL:                                                                                            /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
      /* Release the spinlock and enable interrupts */
      Os_SpinlockInternalRelease(Ioc->Spinlock);                                                                        /* SBSW_OS_IOC_SPINLOCKINTERNALRELEASE_001 */
      Os_IntResume(InterruptState);                                                                                     /* SBSW_OS_FC_PRECONDITION */
      break;
    default:                                                                                                            /* COV_OS_INVSTATE */
      Os_ErrKernelPanic();
      break;
  }
}


/***********************************************************************************************************************
 *  Os_IocCallCallbacks()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Std_ReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_IocCallCallbacks,
(
  P2CONST(Os_IocCallbacksConfigType, TYPEDEF, OS_CONST) Callbacks
))
{
  Std_ReturnType result;
  volatile uint16_least failedCalls = 0;

  /* #10 Check whether callbacks are enabled. */
  if (Os_IocHasCallbacks() != 0u)                                                                                       /* PRQA S 2991, 2995 */ /* MD_Os_Rule14.3_2991, MD_Os_Rule2.2_2995 */
  {
    Os_HookIdType index;

    /* #20 Call each configured callback. */
    for(index = (Os_HookIdType)0; index < Callbacks->CallbackCount; index++)
    {
      if(OS_UNLIKELY(Os_HookCallCallback(Callbacks->CallbackRefs[index]) != OS_STATUS_OK))                              /* SBSW_OS_IOC_HOOKCALLCALLBACK_001 */
      {
        failedCalls++;
      }
    }
  }

  /* #30 Returns IOC_E_NOK, if at least one of the callbacks is not successfully triggered. */
  if(OS_LIKELY(failedCalls == 0u))
  {
    result = IOC_E_OK;
  }
  else
  {
    result = IOC_E_NOK;
  }

  return result;
}


/***********************************************************************************************************************
 *  Os_IocCheckNoDataLost()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_IocCheckNoDataLost,
(
  P2CONST(Os_IocReceiveConfigType, TYPEDEF, OS_CONST) Ioc
))
{
  P2VAR(Os_IocReceiveType volatile, AUTOMATIC, TYPEDEF) receiverDyn;
  P2VAR(Os_IocSendType volatile, AUTOMATIC, TYPEDEF) senderDyn;
  Os_StdReturnType result;
  Os_IocLostCounterType lostCounter;

  receiverDyn = Os_IocReceiveGetDyn(Ioc);                                                                               /* SBSW_OS_FC_PRECONDITION */
  senderDyn = Os_IocSendGetDyn(Ioc->Send);                                                                              /* SBSW_OS_IOC_IOCSENDGETDYN_001 */

  lostCounter = senderDyn->LostCounter;

  /* #10 If the lost counter did not change since the last check, return no data lost. */
  if(lostCounter == receiverDyn->LostCounterSnapshot)
  {
    result = !OS_CHECK_FAILED;                                                                                         /* PRQA S 4404, 4558 */  /* MD_Os_C90BooleanCompatibility, MD_Os_Rule10.1_4558 */
  }
  /* #20 Otherwise: */
  else
  {
    /* #30 Update the lost counter snapshot. */
    receiverDyn->LostCounterSnapshot = lostCounter;                                                                     /* SBSW_OS_IOC_IOCRECEIVEGETDYN_001 */

    /* #40 Return data lost. */
    result = OS_CHECK_FAILED;
  }
  return result;
}


/***********************************************************************************************************************
 *  Os_IocIncrementLostCounter()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IocIncrementLostCounter,
(
  P2CONST(Os_IocSendConfigType, TYPEDEF, OS_CONST) Ioc
))
{
  P2VAR(Os_IocSendType volatile, AUTOMATIC, TYPEDEF) dyn;

  dyn = Os_IocSendGetDyn(Ioc);                                                                                          /* SBSW_OS_FC_PRECONDITION */

  /* #10 Increment the Lost counter. */
  dyn->LostCounter++;                                                                                                   /* SBSW_OS_IOC_IOCSENDGETDYN_002 */
}


/***********************************************************************************************************************
 *  Os_IocEmptyMultiQueue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Std_ReturnType, OS_CODE,                                                   /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
OS_ALWAYS_INLINE, Os_IocEmptyMultiQueue,
(
  P2CONST(Os_IocMultiReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  Os_IocSubClassType SubClass
))                                                                                                                      /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
{
  Os_ObjIdxType idx;

  /* #10 For all configured receive channels in the sub-class: */
  for(idx = 0; idx < Ioc->ReceiveChannelCount; idx++)
  {
    /* #20 Call the respective EmptyQueue-function. */
    switch(SubClass)
    {
      case Ioc08MultiReceive:
        (void)Os_Ioc08EmptyQueue(&(Os_IocIoc2Ioc08MultiReceive(&(Ioc->Base))->Receivers[idx]));                         /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_IOC_IOC08EMPTYQUEUE_001 */
        break;
      case Ioc16MultiReceive:
        (void)Os_Ioc16EmptyQueue(&(Os_IocIoc2Ioc16MultiReceive(&(Ioc->Base))->Receivers[idx]));                         /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_IOC_IOC16EMPTYQUEUE_001 */
        break;
      case Ioc32MultiReceive:
        (void)Os_Ioc32EmptyQueue(&(Os_IocIoc2Ioc32MultiReceive(&(Ioc->Base))->Receivers[idx]));                         /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_IOC_IOC32EMPTYQUEUE_001 */
        break;
      case IocRefMultiReceive:
        (void)Os_IocRefEmptyQueue(&(Os_IocIoc2IocRefMultiReceive(&(Ioc->Base))->Receivers[idx]));                       /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_IOC_IOCREFEMPTYQUEUE_001 */
        break;
      default:                                                                                                          /* COV_OS_INVSTATE */
        /* cannot be reached as the SubClass parameter is set by module internal caller only */
        Os_ErrKernelPanic();
        break;
    }
  }
  return IOC_E_OK;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_TaskGetAccessingApplications()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_AppAccessMaskType, OS_CODE, OS_ALWAYS_INLINE,
Os_IocGetAccessingApplications,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
))
{
  return Ioc->AccessingApplications;
}


/***********************************************************************************************************************
 *  Os_Ioc08ReceiveInternal()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE Os_IocInternalReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_Ioc08ReceiveInternal,
(
  P2CONST(Os_Ioc08ReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(uint8, TYPEDEF, AUTOMATIC) Data
))
{
  Os_IocInternalReturnType status;

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_IocChannelIsEnabled(&(Ioc->Ioc.Base)) == 0u))                                                       /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_INVSTATE */
  {
    status = OS_IOC_E_INTERNAL_CHANNEL_CLOSED;
  }
  else if(OS_UNLIKELY(Os_IocChannelIsEnabled(&(Ioc->Ioc.Send->Base)) == 0u))                                            /* SBSW_OS_IOC_IOCCHANNELISENABLED_001 */ /* COV_OS_INVSTATE */
  {
    status = OS_IOC_E_INTERNAL_CLOSE_CHANNEL;
  }
  else if(OS_UNLIKELY(Os_Fifo08IndicesInRangeOnRead(&(Ioc->FifoRead)) == 0u))                                           /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_INVSTATE */
  {
    status = OS_IOC_E_INTERNAL_CLOSE_CHANNEL;
  }
  else if(OS_UNLIKELY(Os_Fifo08IsEmpty(&(Ioc->FifoRead)) != 0u))                                                        /* SBSW_OS_FC_PRECONDITION */
  {
    if(OS_UNLIKELY(Os_IocCheckNoDataLost(&(Ioc->Ioc)) == OS_CHECK_FAILED))                                              /* SBSW_OS_FC_PRECONDITION */
    {
      status = OS_IOC_E_INTERNAL_LOST_AND_NO_DATA;
    }
    else
    {
      status = OS_IOC_E_INTERNAL_NO_DATA;
    }
  }
  else
  {
    if(OS_UNLIKELY(Os_IocCheckNoDataLost(&(Ioc->Ioc)) == OS_CHECK_FAILED))                                              /* SBSW_OS_FC_PRECONDITION */
    {
      status = OS_IOC_E_INTERNAL_LOST_DATA;
    }
    else
    {
      status = OS_IOC_E_INTERNAL_OK;
    }

    /* #20 Read from the IOC buffer. */
    (*Data) = Os_Fifo08Dequeue(&(Ioc->FifoRead));                                                                       /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_PWA_PRECONDITION */
  }

  return status;
}                                                                                                                       /* PRQA S 6080 */ /* MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_Ioc16ReceiveInternal()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE Os_IocInternalReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_Ioc16ReceiveInternal,
(
  P2CONST(Os_Ioc16ReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(uint16, TYPEDEF, AUTOMATIC) Data
))
{
  Os_IocInternalReturnType status;

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_IocChannelIsEnabled(&(Ioc->Ioc.Base)) == 0u))                                                       /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_INVSTATE */
  {
    status = OS_IOC_E_INTERNAL_CHANNEL_CLOSED;
  }
  else if(OS_UNLIKELY(Os_IocChannelIsEnabled(&(Ioc->Ioc.Send->Base)) == 0u))                                            /* SBSW_OS_IOC_IOCCHANNELISENABLED_001 */ /* COV_OS_INVSTATE */
  {
    status = OS_IOC_E_INTERNAL_CLOSE_CHANNEL;
  }
  else if(OS_UNLIKELY(Os_Fifo16IndicesInRangeOnRead(&(Ioc->FifoRead)) == 0u))                                           /* COV_OS_INVSTATE */ /* SBSW_OS_FC_PRECONDITION */
  {
    status = OS_IOC_E_INTERNAL_CLOSE_CHANNEL;
  }
  else if(OS_UNLIKELY(Os_Fifo16IsEmpty(&(Ioc->FifoRead)) != 0u))                                                        /* SBSW_OS_FC_PRECONDITION */
  {
    if(OS_UNLIKELY(Os_IocCheckNoDataLost(&(Ioc->Ioc)) == OS_CHECK_FAILED))                                              /* SBSW_OS_FC_PRECONDITION */
    {
      status = OS_IOC_E_INTERNAL_LOST_AND_NO_DATA;
    }
    else
    {
      status = OS_IOC_E_INTERNAL_NO_DATA;
    }
  }
  else
  {
    if(OS_UNLIKELY(Os_IocCheckNoDataLost(&(Ioc->Ioc)) == OS_CHECK_FAILED))                                              /* SBSW_OS_FC_PRECONDITION */
    {
      status = OS_IOC_E_INTERNAL_LOST_DATA;
    }
    else
    {
      status = OS_IOC_E_INTERNAL_OK;
    }

    /* #20 Read from the IOC buffer. */
    (*Data) = Os_Fifo16Dequeue(&(Ioc->FifoRead));                                                                       /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_PWA_PRECONDITION */
  }

  return status;
}                                                                                                                       /* PRQA S 6050, 6080 */ /* MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_Ioc32ReceiveInternal()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE Os_IocInternalReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_Ioc32ReceiveInternal,
(
  P2CONST(Os_Ioc32ReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(uint32, TYPEDEF, AUTOMATIC) Data
))
{
  Os_IocInternalReturnType status;

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_IocChannelIsEnabled(&(Ioc->Ioc.Base)) == 0u))                                                       /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_INVSTATE */
  {
    status = OS_IOC_E_INTERNAL_CHANNEL_CLOSED;
  }
  else if(OS_UNLIKELY(Os_IocChannelIsEnabled(&(Ioc->Ioc.Send->Base)) == 0u))                                            /* SBSW_OS_IOC_IOCCHANNELISENABLED_001 */ /* COV_OS_INVSTATE */
  {
    status = OS_IOC_E_INTERNAL_CLOSE_CHANNEL;
  }
  else if(OS_UNLIKELY(Os_Fifo32IndicesInRangeOnRead(&(Ioc->FifoRead)) == 0u))                                           /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_INVSTATE */
  {
    status = OS_IOC_E_INTERNAL_CLOSE_CHANNEL;
  }
  else if(OS_UNLIKELY(Os_Fifo32IsEmpty(&(Ioc->FifoRead)) != 0u))                                                        /* SBSW_OS_FC_PRECONDITION */
  {
    if(OS_UNLIKELY(Os_IocCheckNoDataLost(&(Ioc->Ioc)) == OS_CHECK_FAILED))                                              /* SBSW_OS_FC_PRECONDITION */
    {
      status = OS_IOC_E_INTERNAL_LOST_AND_NO_DATA;
    }
    else
    {
      status = OS_IOC_E_INTERNAL_NO_DATA;
    }
  }
  else
  {
    if(OS_UNLIKELY(Os_IocCheckNoDataLost(&(Ioc->Ioc)) == OS_CHECK_FAILED))                                              /* SBSW_OS_FC_PRECONDITION */
    {
      status = OS_IOC_E_INTERNAL_LOST_DATA;
    }
    else
    {
      status = OS_IOC_E_INTERNAL_OK;
    }

    /* #20 Read from the IOC buffer. */
    (*Data) = Os_Fifo32Dequeue(&(Ioc->FifoRead));                                                                       /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_PWA_PRECONDITION */
  }

  return status;
}                                                                                                                       /* PRQA S 6050, 6080 */ /* MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_IocRefReceiveInternal()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE Os_IocInternalReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_IocRefReceiveInternal,
(
  P2CONST(Os_IocRefReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(void, TYPEDEF, AUTOMATIC) Data
))
{
  Os_IocInternalReturnType status;

  /* #10 Perform checks. */
  if(OS_UNLIKELY(Os_IocChannelIsEnabled(&(Ioc->Ioc.Base)) == 0u))                                                       /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_INVSTATE */
  {
    status = OS_IOC_E_INTERNAL_CHANNEL_CLOSED;
  }
  else if(OS_UNLIKELY(Os_IocChannelIsEnabled(&(Ioc->Ioc.Send->Base)) == 0u))                                            /* SBSW_OS_IOC_IOCCHANNELISENABLED_001 */ /* COV_OS_INVSTATE */
  {
    status = OS_IOC_E_INTERNAL_CLOSE_CHANNEL;
  }
  else if(OS_UNLIKELY(Os_FifoRefIndicesInRangeOnRead(&(Ioc->FifoRead)) == 0u))                                          /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_INVSTATE */
  {
    status = OS_IOC_E_INTERNAL_CLOSE_CHANNEL;
  }
  else if(OS_UNLIKELY(Os_FifoRefIsEmpty(&(Ioc->FifoRead)) != 0u))                                                       /* SBSW_OS_FC_PRECONDITION */
  {
    if(OS_UNLIKELY(Os_IocCheckNoDataLost(&(Ioc->Ioc)) == OS_CHECK_FAILED))                                              /* SBSW_OS_FC_PRECONDITION */
    {
      status = OS_IOC_E_INTERNAL_LOST_AND_NO_DATA;
    }
    else
    {
      status = OS_IOC_E_INTERNAL_NO_DATA;
    }
  }
  else
  {
    if(OS_UNLIKELY(Os_IocCheckNoDataLost(&(Ioc->Ioc)) == OS_CHECK_FAILED))                                              /* SBSW_OS_FC_PRECONDITION */
    {
      status = OS_IOC_E_INTERNAL_LOST_DATA;
    }
    else
    {
      status = OS_IOC_E_INTERNAL_OK;
    }

    /* #20 Read from the IOC buffer. */
    Os_FifoRefDequeue(&(Ioc->FifoRead), Data);                                                                          /* SBSW_OS_FC_PRECONDITION */
  }

  return status;
}                                                                                                                       /* PRQA S 6050, 6080 */ /* MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  IOC uint8
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  Os_Ioc08ReceiveInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Ioc08ReceiveInit,
(
  P2CONST(Os_Ioc08ReceiveConfigType, TYPEDEF, OS_CONST) Ioc
))
{
  /* #10 Initialize the base class. */
  Os_IocReceiveInit(&(Ioc->Ioc));                                                                                       /* SBSW_OS_FC_PRECONDITION */

  /* #20 Initialize FIFO reader part. */
  Os_Fifo08ReadInit(&(Ioc->FifoRead));                                                                                  /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_Ioc08SendInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Ioc08SendInit,
(
  P2CONST(Os_Ioc08SendConfigType, TYPEDEF, OS_CONST) Ioc
))
{
  /* #10 Initialize the base class. */
  Os_IocSendInit(&(Ioc->Ioc));                                                                                          /* SBSW_OS_FC_PRECONDITION */

  /* #20 Initialize FIFO writer part. */
  Os_Fifo08WriteInit(&(Ioc->FifoWrite));                                                                                /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_Ioc08MultiReceive()
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
 */
FUNC(Std_ReturnType, OS_CODE) Os_Ioc08MultiReceive
(
  P2CONST(Os_Ioc08MultiReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(uint8, TYPEDEF, AUTOMATIC) Data
)
{
  Os_IocInternalReturnType status;

  /* #10 If Ioc is not enabled: KernelPanic. */
  if(Os_IocIsEnabled() == 0u)                                                                                           /* COV_OS_INVSTATE */
  {
    Os_ErrKernelPanic();
  }

  {
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;
    Os_AppAccessMaskType permittedApplications;

    currentApplication = Os_ThreadGetCurrentApplication(Os_CoreGetThread());                                            /* SBSW_OS_IOC_THREADGETCURRENTAPPLICATION_001 */
    permittedApplications = Os_IocGetAccessingApplications(&(Ioc->Ioc.Base));                                           /* SBSW_OS_FC_PRECONDITION */

    /* #15 Perform static checks. */
    if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication, permittedApplications) == OS_CHECK_FAILED))                    /* SBSW_OS_IOC_APPCHECKACCESS_001 */
    {
      status = OS_IOC_E_INTERNAL_NOK;
    }
    else
    {
      Os_IntStateType intState;
      Os_ObjIdxType currentReceiveIdx;

      /* #20 Get the locks. */
      Os_IocLock(&(Ioc->Ioc.Base), &intState);                                                                          /* SBSW_OS_IOC_IOCLOCK_001 */

      /* #30 Perform checks. */
      if(OS_UNLIKELY(Os_IocChannelIsEnabled(&(Ioc->Ioc.Base)) == 0u))                                                   /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_INVSTATE */
      {
        /* OS_IOC_E_INTERNAL_CHANNEL_CLOSED makes no sense here as it is not stated to the caller anyhow. */
        status = OS_IOC_E_INTERNAL_NO_DATA;
      }
      else
      {
        P2VAR(Os_IocMultiReceiveType volatile, AUTOMATIC, TYPEDEF) dyn;
        Os_ObjIdxType receiveChannelCounter;

        dyn = Os_IocMultiReceiveGetDyn(&(Ioc->Ioc));                                                                    /* SBSW_OS_FC_PRECONDITION */
        currentReceiveIdx = dyn->NextReceiveChannel;

        status = OS_IOC_E_INTERNAL_NO_DATA;

        /* #40 For each IOC channel, beginning from where last receive ended: */
        for(receiveChannelCounter = 0; receiveChannelCounter < Ioc->Ioc.ReceiveChannelCount; receiveChannelCounter++)   /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
        {
          /* #50 Read from the IOC channel. */
          status = Os_Ioc08ReceiveInternal(&(Ioc->Receivers[currentReceiveIdx]), Data);                                 /* SBSW_OS_IOC_IOC08RECEIVEINTERNAL_001 */

          /* #60 If the channel contained data or an error occurred, abort looking for data. */
          if (status != OS_IOC_E_INTERNAL_NO_DATA)
          {
            break;
          }

          currentReceiveIdx++;
          if (currentReceiveIdx >= Ioc->Ioc.ReceiveChannelCount)                                                        /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
          {
            currentReceiveIdx = 0;
          }
        }

        /* #70 Close all channels if an error has been detected */
        switch(status)
        {
          case OS_IOC_E_INTERNAL_OK:
            /* intentionally no break */
          case OS_IOC_E_INTERNAL_LOST_DATA:
            /* intentionally no break */
          case OS_IOC_E_INTERNAL_LOST_AND_NO_DATA:
            /* intentionally no break */
          case OS_IOC_E_INTERNAL_NO_DATA:
            /* no error to be handled inside this function */
            break;
          default:                                                                                                      /* COV_OS_INVSTATE */
            /* an internal error has occurred, close all channels */
            for(currentReceiveIdx = 0; currentReceiveIdx < Ioc->Ioc.ReceiveChannelCount; currentReceiveIdx++)           /* COV_OS_INVSTATE */
            {
              Os_IocReceiveCloseChannel(&(Ioc->Receivers[currentReceiveIdx].Ioc));                                      /* SBSW_OS_IOC_IOCRECEIVECLOSECHANNEL_001 */
            }
            /* The caller cannot handle internal error codes */
            status = OS_IOC_E_INTERNAL_NO_DATA;
            break;
        }

        /* #80 Compute the channel index for next IOC receive call. */
        dyn->NextReceiveChannel++;                                                                                      /* SBSW_OS_IOC_IOCMULTIRECEIVEGETDYN_001 */
        if (dyn->NextReceiveChannel >= Ioc->Ioc.ReceiveChannelCount)
        {
          dyn->NextReceiveChannel = 0;                                                                                  /* SBSW_OS_IOC_IOCMULTIRECEIVEGETDYN_001 */
        }
      }
      /* #90 Release the locks. */
      Os_IocUnlock(&(Ioc->Ioc.Base), &intState);                                                                        /* SBSW_OS_IOC_IOCUNLOCK_001 */
    }
  }

  return (Std_ReturnType) status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_Ioc08Receive()
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
FUNC(Std_ReturnType, OS_CODE) Os_Ioc08Receive
(
  P2CONST(Os_Ioc08ReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(uint8, TYPEDEF, AUTOMATIC) Data
)
{
  Os_IocInternalReturnType status;

  /* #10 If Ioc is not enabled: KernelPanic. */
  if(Os_IocIsEnabled() == 0u)                                                                                           /* COV_OS_INVSTATE */
  {
    Os_ErrKernelPanic();
  }

  {
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;
    Os_AppAccessMaskType permittedApplications;

    currentApplication = Os_ThreadGetCurrentApplication(Os_CoreGetThread());                                            /* SBSW_OS_IOC_THREADGETCURRENTAPPLICATION_001 */
    permittedApplications = Os_IocGetAccessingApplications(&(Ioc->Ioc.Base));                                           /* SBSW_OS_FC_PRECONDITION */

    /* #15 Perform checks. */
    if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication, permittedApplications) == OS_CHECK_FAILED))                    /* SBSW_OS_IOC_APPCHECKACCESS_001 */
    {
      status = OS_IOC_E_INTERNAL_NOK;
    }
    else
    {
      Os_IntStateType interruptState;

      /* #20 Get the locks. */
      Os_IocLock(&(Ioc->Ioc.Base), &interruptState);                                                                    /* SBSW_OS_IOC_IOCLOCK_001 */

      /* #30 Call internal receive function. */
      status = Os_Ioc08ReceiveInternal(Ioc, Data);                                                                      /* SBSW_OS_FC_PRECONDITION */

      /* #40 Correct the return value and close the channel if necessary. */
      if(OS_UNLIKELY((status == OS_IOC_E_INTERNAL_CLOSE_CHANNEL)))                                                      /* COV_OS_INVSTATE */
      {
        Os_IocReceiveCloseChannel(&(Ioc->Ioc));                                                                         /* SBSW_OS_FC_PRECONDITION */
        /* OS_IOC_E_INTERNAL_CLOSE_CHANNEL in not known externally, other return values are numerical identical */
        status = OS_IOC_E_INTERNAL_NO_DATA;
      }
      else if(OS_UNLIKELY(status == OS_IOC_E_INTERNAL_CHANNEL_CLOSED))                                                  /* COV_OS_INVSTATE */
      {
        /* OS_IOC_E_INTERNAL_CHANNEL_CLOSED in not known externally, other return values are numerical identical */
        status = OS_IOC_E_INTERNAL_NO_DATA;
      }
      else
      {
        /* status does not need to be changed. MISRA 14.10 */
      }

      /* #50 Release the locks. */
      Os_IocUnlock(&(Ioc->Ioc.Base), &interruptState);                                                                  /* SBSW_OS_IOC_IOCUNLOCK_001 */
    }
  }

  return (Std_ReturnType) status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_Ioc08EmptyQueue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, OS_CODE) Os_Ioc08EmptyQueue
(
  P2CONST(Os_Ioc08ReceiveConfigType, TYPEDEF, OS_CONST) Ioc
)
{
  Std_ReturnType status;

  /* #10 If Ioc is not enabled: KernelPanic. */
  if(Os_IocIsEnabled() == 0u)                                                                                           /* COV_OS_INVSTATE */
  {
    Os_ErrKernelPanic();
  }

  {
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;
    Os_AppAccessMaskType permittedApplications;

    currentApplication = Os_ThreadGetCurrentApplication(Os_CoreGetThread());                                            /* SBSW_OS_IOC_THREADGETCURRENTAPPLICATION_001 */
    permittedApplications = Os_IocGetAccessingApplications(&(Ioc->Ioc.Base));                                           /* SBSW_OS_FC_PRECONDITION */

    /* #15 Perform static checks. */
    if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication, permittedApplications) == OS_CHECK_FAILED))                    /* SBSW_OS_IOC_APPCHECKACCESS_001 */
    {
      status = IOC_E_NOK;
    }
    else
    {
      /* #20 Redirect to FIFO. */
      Os_Fifo08EmptyQueue(&(Ioc->FifoRead));                                                                            /* SBSW_OS_IOC_FIFO08EMPTYQUEUE_001 */

      status = IOC_E_OK;
    }
  }

  return status;
}


/***********************************************************************************************************************
 *  Os_Ioc08EmptyMultiQueue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, OS_CODE) Os_Ioc08EmptyMultiQueue                                                                   /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
(
  P2CONST(Os_Ioc08MultiReceiveConfigType, TYPEDEF, OS_CONST) Ioc
)
{
  Std_ReturnType status;

  /* #10 If Ioc is not enabled: KernelPanic. */
  if(Os_IocIsEnabled() == 0u)                                                                                           /* COV_OS_INVSTATE */
  {
    Os_ErrKernelPanic();
  }

  {
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;
    Os_AppAccessMaskType permittedApplications;

    currentApplication = Os_ThreadGetCurrentApplication(Os_CoreGetThread());                                            /* SBSW_OS_IOC_THREADGETCURRENTAPPLICATION_001 */
    permittedApplications = Os_IocGetAccessingApplications(&(Ioc->Ioc.Base));                                           /* SBSW_OS_FC_PRECONDITION */

    /* #15 Perform static checks. */
    if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication, permittedApplications) == OS_CHECK_FAILED))                    /* SBSW_OS_IOC_APPCHECKACCESS_001 */
    {
      status = IOC_E_NOK;
    }
    else
    {
      /* #20 Call the base class method. */
      (void)Os_IocEmptyMultiQueue(&(Ioc->Ioc), Ioc08MultiReceive);                                                      /* SBSW_OS_FC_PRECONDITION */
      status = IOC_E_OK;
    }
  }

  return status;
}


/***********************************************************************************************************************
 *  Os_Ioc08Send()
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
 */
FUNC(Std_ReturnType, OS_CODE) Os_Ioc08Send
(
  P2CONST(Os_Ioc08SendConfigType, TYPEDEF, OS_CONST) Ioc,
  uint8 Data
)
{
  Std_ReturnType status;

  /* #10 If Ioc is not enabled: KernelPanic. */
  if(Os_IocIsEnabled() == 0u)                                                                                           /* COV_OS_INVSTATE */
  {
    Os_ErrKernelPanic();
  }

  {
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;
    Os_AppAccessMaskType permittedApplications;

    currentApplication = Os_ThreadGetCurrentApplication(Os_CoreGetThread());                                            /* SBSW_OS_IOC_THREADGETCURRENTAPPLICATION_001 */
    permittedApplications = Os_IocGetAccessingApplications(&(Ioc->Ioc.Base));                                           /* SBSW_OS_FC_PRECONDITION */

    /* #15 Perform static checks. */
    if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication, permittedApplications) == OS_CHECK_FAILED))                    /* SBSW_OS_IOC_APPCHECKACCESS_001 */
    {
      status = IOC_E_NOK;
    }
    else
    {
      Os_IntStateType interruptState;
      Os_FifoWriteResultType result;

      status = IOC_E_OK;

      /* #20 Get the locks. */
      Os_IocLock(&(Ioc->Ioc.Base), &interruptState);                                                                    /* SBSW_OS_IOC_IOCLOCK_001 */

      /* #30 Check that the channel is enabled and that the FIFO indices are in range. If not close the channel. */
      if(OS_UNLIKELY(Os_IocChannelIsEnabled(&(Ioc->Ioc.Base)) == 0u))                                                   /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_INVSTATE */
      {
        status = IOC_E_LIMIT;
      }
      else if(OS_UNLIKELY((Os_IocChannelIsEnabled(&(Ioc->Ioc.Receive->Base)) == 0u)))                                   /* SBSW_OS_IOC_IOCCHANNELISENABLED_002 */ /* COV_OS_INVSTATE */
      {
        Os_IocSendCloseChannel(&(Ioc->Ioc));                                                                            /* SBSW_OS_FC_PRECONDITION */
        status = IOC_E_LIMIT;
      }
      else if(OS_UNLIKELY((Os_Fifo08IndicesInRangeOnWrite(&(Ioc->FifoWrite)) == 0u)))                                   /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_INVSTATE */
      {
        Os_IocSendCloseChannel(&(Ioc->Ioc));                                                                            /* SBSW_OS_FC_PRECONDITION */
        status = IOC_E_LIMIT;
      }
      else
      {
        /* #40 Try to write to the IOC buffer. */
        result = Os_Fifo08Enqueue(&(Ioc->FifoWrite), Data);                                                             /* SBSW_OS_FC_PRECONDITION */

        /* #50 If FIFO is already full: */
        if(OS_UNLIKELY((OS_UNLIKELY(result == OS_FIFOWRITERESULT_BUFFEROVERFLOW))))
        {
          /* #60 Increment lost counter. */
          Os_IocIncrementLostCounter(&(Ioc->Ioc));                                                                      /* SBSW_OS_FC_PRECONDITION */
          status = IOC_E_LIMIT;
        }
      }

      /* #70 Release the locks. */
      Os_IocUnlock(&(Ioc->Ioc.Base), &interruptState);                                                                  /* SBSW_OS_IOC_IOCUNLOCK_001 */

      /* #80 If no error detected: */
      if(OS_LIKELY(status == IOC_E_OK))
      {
        /* #90 Tell base class object, that sending is completed by calling the callbacks, when configured. */
        status = Os_IocCallCallbacks(&(Ioc->Ioc.Callbacks));                                                            /* SBSW_OS_FC_PRECONDITION */
      }
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050, 6080 */ /* MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  IOC 16
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  Os_Ioc16ReceiveInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Ioc16ReceiveInit,
(
  P2CONST(Os_Ioc16ReceiveConfigType, TYPEDEF, OS_CONST) Ioc
))
{
  /* #10 Initialize the base class. */
  Os_IocReceiveInit(&(Ioc->Ioc));                                                                                       /* SBSW_OS_FC_PRECONDITION */

  /* #20 Initialize all fields. */
  Os_Fifo16ReadInit(&(Ioc->FifoRead));                                                                                  /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_Ioc16SendInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Ioc16SendInit,
(
  P2CONST(Os_Ioc16SendConfigType, TYPEDEF, OS_CONST) Ioc
))
{
  /* #10 Initialize the base class. */
  Os_IocSendInit(&(Ioc->Ioc));                                                                                          /* SBSW_OS_FC_PRECONDITION */

  /* #20 Initialize all fields. */
  Os_Fifo16WriteInit(&(Ioc->FifoWrite));                                                                                /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_Ioc16MultiReceive()
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
 */
FUNC(Std_ReturnType, OS_CODE) Os_Ioc16MultiReceive
(
  P2CONST(Os_Ioc16MultiReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(uint16, TYPEDEF, AUTOMATIC) Data
)
{
  Os_IocInternalReturnType status;

  /* #10 If Ioc is not enabled: KernelPanic. */
  if(Os_IocIsEnabled() == 0u)                                                                                           /* COV_OS_INVSTATE */
  {
    Os_ErrKernelPanic();
  }

  {
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;
    Os_AppAccessMaskType permittedApplications;

    currentApplication = Os_ThreadGetCurrentApplication(Os_CoreGetThread());                                            /* SBSW_OS_IOC_THREADGETCURRENTAPPLICATION_001 */
    permittedApplications = Os_IocGetAccessingApplications(&(Ioc->Ioc.Base));                                           /* SBSW_OS_FC_PRECONDITION */

    /* #15 Perform static checks. */
    if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication, permittedApplications) == OS_CHECK_FAILED))                    /* SBSW_OS_IOC_APPCHECKACCESS_001 */
    {
      status = OS_IOC_E_INTERNAL_NOK;
    }
    else
    {
      Os_IntStateType intState;
      Os_ObjIdxType currentReceiveIdx;

      /* #20 Get the locks. */
      Os_IocLock(&(Ioc->Ioc.Base), &intState);                                                                          /* SBSW_OS_IOC_IOCLOCK_001 */

      /* #30 Perform checks. */
      if(OS_UNLIKELY(Os_IocChannelIsEnabled(&(Ioc->Ioc.Base)) == 0u))                                                   /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_INVSTATE */
      {
        /* OS_IOC_E_INTERNAL_CHANNEL_CLOSED makes no sense here as it is not stated to the caller anyhow */
        status = OS_IOC_E_INTERNAL_NO_DATA;
      }
      else
      {
        P2VAR(Os_IocMultiReceiveType volatile, AUTOMATIC, OS_VAR_NOINIT) dyn;
        Os_ObjIdxType receiveChannelCounter;

        dyn = Os_IocMultiReceiveGetDyn(&(Ioc->Ioc));                                                                    /* SBSW_OS_FC_PRECONDITION */
        currentReceiveIdx = dyn->NextReceiveChannel;

        status = OS_IOC_E_INTERNAL_NO_DATA;

        /* #40 For each IOC channel, beginning from where last receive ended: */
        for(receiveChannelCounter = 0; receiveChannelCounter < Ioc->Ioc.ReceiveChannelCount; receiveChannelCounter++)   /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
        {
          /* #50 Read from the IOC channel. */
          status = Os_Ioc16ReceiveInternal(&(Ioc->Receivers[currentReceiveIdx]), Data);                                 /* SBSW_OS_IOC_IOC16RECEIVEINTERNAL_001 */

          /* #60 If the channel contained data or an error occurred, abort looking for data. */
          if (status != OS_IOC_E_INTERNAL_NO_DATA)
          {
            break;
          }

          currentReceiveIdx++;
          if (currentReceiveIdx >= Ioc->Ioc.ReceiveChannelCount)                                                        /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
          {
            currentReceiveIdx = 0;
          }
        }

        /* #70 Close all channels if an error has been detected. */
        switch(status)
        {
          case OS_IOC_E_INTERNAL_OK:
            /* intentionally no break */
          case OS_IOC_E_INTERNAL_LOST_DATA:
            /* intentionally no break */
          case OS_IOC_E_INTERNAL_LOST_AND_NO_DATA:
            /* intentionally no break */
          case OS_IOC_E_INTERNAL_NO_DATA:
            /* no error to be handled inside this function */
            break;
          default:                                                                                                      /* COV_OS_INVSTATE */
            /* an internal error has occurred, close all channels */
            for(currentReceiveIdx = 0; currentReceiveIdx < Ioc->Ioc.ReceiveChannelCount; currentReceiveIdx++)           /* COV_OS_INVSTATE */
            {
              Os_IocReceiveCloseChannel(&(Ioc->Receivers[currentReceiveIdx].Ioc));                                      /* SBSW_OS_IOC_IOCRECEIVECLOSECHANNEL_001 */
            }
            /* The caller cannot handle internal error codes */
            status = OS_IOC_E_INTERNAL_NO_DATA;
            break;
        }

        /* #80 Compute the channel index for next IOC receive call. */
        dyn->NextReceiveChannel++;                                                                                      /* SBSW_OS_IOC_IOCMULTIRECEIVEGETDYN_001 */
        if (dyn->NextReceiveChannel >= Ioc->Ioc.ReceiveChannelCount)
        {
          dyn->NextReceiveChannel = 0;                                                                                  /* SBSW_OS_IOC_IOCMULTIRECEIVEGETDYN_001 */
        }
      }
      /* #90 Release the locks. */
      Os_IocUnlock(&(Ioc->Ioc.Base), &intState);                                                                        /* SBSW_OS_IOC_IOCUNLOCK_001 */
    }
  }

  return (Std_ReturnType) status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_Ioc16EmptyMultiQueue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, OS_CODE) Os_Ioc16EmptyMultiQueue                                                                   /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
(
  P2CONST(Os_Ioc16MultiReceiveConfigType, TYPEDEF, OS_CONST) Ioc
)
{
  Std_ReturnType status;

  /* #10 If Ioc is not enabled: KernelPanic. */
  if(Os_IocIsEnabled() == 0u)                                                                                           /* COV_OS_INVSTATE */
  {
    Os_ErrKernelPanic();
  }

  {
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;
    Os_AppAccessMaskType permittedApplications;

    currentApplication = Os_ThreadGetCurrentApplication(Os_CoreGetThread());                                            /* SBSW_OS_IOC_THREADGETCURRENTAPPLICATION_001 */
    permittedApplications = Os_IocGetAccessingApplications(&(Ioc->Ioc.Base));                                           /* SBSW_OS_FC_PRECONDITION */

    /* #15 Perform static checks. */
    if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication, permittedApplications) == OS_CHECK_FAILED))                    /* SBSW_OS_IOC_APPCHECKACCESS_001 */
    {
      status = IOC_E_NOK;
    }
    else
    {
      /* #20 Call the base class method. */
      (void)Os_IocEmptyMultiQueue(&(Ioc->Ioc), Ioc16MultiReceive);                                                      /* SBSW_OS_FC_PRECONDITION */
      status = IOC_E_OK;
    }
  }

  return status;
}


/***********************************************************************************************************************
 *  Os_Ioc16Receive()
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
FUNC(Std_ReturnType, OS_CODE) Os_Ioc16Receive
(
  P2CONST(Os_Ioc16ReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(uint16, TYPEDEF, AUTOMATIC) Data
)
{
  Os_IocInternalReturnType status;

  /* #10 If Ioc is not enabled: KernelPanic. */
  if(Os_IocIsEnabled() == 0u)                                                                                           /* COV_OS_INVSTATE */
  {
    Os_ErrKernelPanic();
  }

  {
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;
    Os_AppAccessMaskType permittedApplications;

    currentApplication = Os_ThreadGetCurrentApplication(Os_CoreGetThread());                                            /* SBSW_OS_IOC_THREADGETCURRENTAPPLICATION_001 */
    permittedApplications = Os_IocGetAccessingApplications(&(Ioc->Ioc.Base));                                           /* SBSW_OS_FC_PRECONDITION */

    /* #15 Perform checks. */
    if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication, permittedApplications) == OS_CHECK_FAILED))                    /* SBSW_OS_IOC_APPCHECKACCESS_001 */
    {
      status = OS_IOC_E_INTERNAL_NOK;
    }
    else
    {
      Os_IntStateType interruptState;

      /* #20 Get the locks. */
      Os_IocLock(&(Ioc->Ioc.Base), &interruptState);                                                                    /* SBSW_OS_IOC_IOCLOCK_001 */

      /* #30 Call internal receive function */
      status = Os_Ioc16ReceiveInternal(Ioc, Data);                                                                      /* SBSW_OS_FC_PRECONDITION */

      /* #40 Correct the return value and close the channel if necessary */
      if(OS_UNLIKELY((status == OS_IOC_E_INTERNAL_CLOSE_CHANNEL)))                                                      /* COV_OS_INVSTATE */
      {
        Os_IocReceiveCloseChannel(&(Ioc->Ioc));                                                                         /* SBSW_OS_FC_PRECONDITION */
        /* OS_IOC_E_INTERNAL_CLOSE_CHANNEL in not known externally, other return values are numerical identical */
        status = OS_IOC_E_INTERNAL_NO_DATA;
      }
      else if(OS_UNLIKELY((status == OS_IOC_E_INTERNAL_CHANNEL_CLOSED)))                                                /* COV_OS_INVSTATE */
      {
        /* OS_IOC_E_INTERNAL_CHANNEL_CLOSED in not known externally, other return values are numerical identical */
        status = OS_IOC_E_INTERNAL_NO_DATA;
      }
      else
      {
        /* status does not need to be changed. MISRA 14.10 */
      }

      /* #50 Release the locks. */
      Os_IocUnlock(&(Ioc->Ioc.Base), &interruptState);                                                                  /* SBSW_OS_IOC_IOCUNLOCK_001 */
    }
  }

  return (Std_ReturnType) status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_Ioc16EmptyQueue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, OS_CODE) Os_Ioc16EmptyQueue
(
  P2CONST(Os_Ioc16ReceiveConfigType, TYPEDEF, OS_CONST) Ioc
)
{
  Std_ReturnType status;

  /* #10 If Ioc is not enabled: KernelPanic. */
  if(Os_IocIsEnabled() == 0u)                                                                                           /* COV_OS_INVSTATE */
  {
    Os_ErrKernelPanic();
  }

  {
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;
    Os_AppAccessMaskType permittedApplications;

    currentApplication = Os_ThreadGetCurrentApplication(Os_CoreGetThread());                                            /* SBSW_OS_IOC_THREADGETCURRENTAPPLICATION_001 */
    permittedApplications = Os_IocGetAccessingApplications(&(Ioc->Ioc.Base));                                           /* SBSW_OS_FC_PRECONDITION */

    /* #15 Perform static checks. */
    if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication, permittedApplications) == OS_CHECK_FAILED))                    /* SBSW_OS_IOC_APPCHECKACCESS_001 */
    {
      status = IOC_E_NOK;
    }
    else
    {
      /* #20 Redirect to FIFO. */
      Os_Fifo16EmptyQueue(&(Ioc->FifoRead));                                                                            /* SBSW_OS_IOC_FIFO16EMPTYQUEUE_001 */

      status = IOC_E_OK;
    }
  }

  return status;
}


/***********************************************************************************************************************
 *  Os_Ioc16Send()
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
 */
FUNC(Std_ReturnType, OS_CODE) Os_Ioc16Send
(
  P2CONST(Os_Ioc16SendConfigType, TYPEDEF, OS_CONST) Ioc,
  uint16 Data
)
{
  Std_ReturnType status;

  /* #10 If Ioc is not enabled: KernelPanic. */
  if(Os_IocIsEnabled() == 0u)                                                                                           /* COV_OS_INVSTATE */
  {
    Os_ErrKernelPanic();
  }

  {
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;
    Os_AppAccessMaskType permittedApplications;

    currentApplication = Os_ThreadGetCurrentApplication(Os_CoreGetThread());                                            /* SBSW_OS_IOC_THREADGETCURRENTAPPLICATION_001 */
    permittedApplications = Os_IocGetAccessingApplications(&(Ioc->Ioc.Base));                                           /* SBSW_OS_FC_PRECONDITION */

    /* #15 Perform static checks. */
    if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication, permittedApplications) == OS_CHECK_FAILED))                    /* SBSW_OS_IOC_APPCHECKACCESS_001 */
    {
      status = IOC_E_NOK;
    }
    else
    {
      Os_IntStateType interruptState;
      Os_FifoWriteResultType result;

      status = IOC_E_OK;

      /* #20 Get the locks. */
      Os_IocLock(&(Ioc->Ioc.Base), &interruptState);                                                                    /* SBSW_OS_IOC_IOCLOCK_001 */

      /* #30 Check that the channel is enabled and that the FIFO indices are in range. If not close the channel. */
      if(OS_UNLIKELY((Os_IocChannelIsEnabled(&(Ioc->Ioc.Base)) == 0u)))                                                 /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_INVSTATE */
      {
        status = IOC_E_LIMIT;
      }
      else if(OS_UNLIKELY((Os_IocChannelIsEnabled(&(Ioc->Ioc.Receive->Base)) == 0u)))                                   /* SBSW_OS_IOC_IOCCHANNELISENABLED_002 */ /* COV_OS_INVSTATE */
      {
        Os_IocSendCloseChannel(&(Ioc->Ioc));                                                                            /* SBSW_OS_FC_PRECONDITION */
        status = IOC_E_LIMIT;
      }
      else if(OS_UNLIKELY((Os_Fifo16IndicesInRangeOnWrite(&(Ioc->FifoWrite)) == 0u)))                                   /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_INVSTATE */
      {
        Os_IocSendCloseChannel(&(Ioc->Ioc));                                                                            /* SBSW_OS_FC_PRECONDITION */
        status = IOC_E_LIMIT;
      }
      else
      {
        /* #40 Try to write to the IOC buffer. */
        result = Os_Fifo16Enqueue(&(Ioc->FifoWrite), Data);                                                             /* SBSW_OS_FC_PRECONDITION */

        /* #50 If FIFO is already full: */
        if(OS_UNLIKELY(result == OS_FIFOWRITERESULT_BUFFEROVERFLOW))
        {
          /* #60 Increment lost counter. */
          Os_IocIncrementLostCounter(&(Ioc->Ioc));                                                                      /* SBSW_OS_FC_PRECONDITION */
          status = IOC_E_LIMIT;
        }
      }

      /* #70 Release the locks. */
      Os_IocUnlock(&(Ioc->Ioc.Base), &interruptState);                                                                  /* SBSW_OS_IOC_IOCUNLOCK_001 */

      /* #80 If no error detected: */
      if(OS_LIKELY(status == IOC_E_OK))
      {
        /* #90 Tell base class object, that sending is completed by calling the callbacks, when configured. */
        status = Os_IocCallCallbacks(&(Ioc->Ioc.Callbacks));                                                            /* SBSW_OS_FC_PRECONDITION */
      }
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050, 6080 */ /* MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  IOC 32
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  Os_Ioc32ReceiveInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Ioc32ReceiveInit,
(
  P2CONST(Os_Ioc32ReceiveConfigType, TYPEDEF, OS_CONST) Ioc
))
{
  /* #10 Initialize the base class. */
  Os_IocReceiveInit(&(Ioc->Ioc));                                                                                       /* SBSW_OS_FC_PRECONDITION */

  /* #20 Initialize all fields. */
  Os_Fifo32ReadInit(&(Ioc->FifoRead));                                                                                  /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_Ioc32SendInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Ioc32SendInit,
(
  P2CONST(Os_Ioc32SendConfigType, TYPEDEF, OS_CONST) Ioc
))
{
  /* #10 Initialize the base class. */
  Os_IocSendInit(&(Ioc->Ioc));                                                                                          /* SBSW_OS_FC_PRECONDITION */

  /* #20 Initialize all fields. */
  Os_Fifo32WriteInit(&(Ioc->FifoWrite));                                                                                /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_Ioc32MultiReceive()
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
 */
FUNC(Std_ReturnType, OS_CODE) Os_Ioc32MultiReceive
(
  P2CONST(Os_Ioc32MultiReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(uint32, TYPEDEF, AUTOMATIC) Data
)
{
  Os_IocInternalReturnType status;

  /* #10 If Ioc is not enabled: KernelPanic. */
  if(Os_IocIsEnabled() == 0u)                                                                                           /* COV_OS_INVSTATE */
  {
    Os_ErrKernelPanic();
  }

  {
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;
    Os_AppAccessMaskType permittedApplications;

    currentApplication = Os_ThreadGetCurrentApplication(Os_CoreGetThread());                                            /* SBSW_OS_IOC_THREADGETCURRENTAPPLICATION_001 */
    permittedApplications = Os_IocGetAccessingApplications(&(Ioc->Ioc.Base));                                           /* SBSW_OS_FC_PRECONDITION */

    /* #15 Perform static checks. */
    if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication, permittedApplications) == OS_CHECK_FAILED))                    /* SBSW_OS_IOC_APPCHECKACCESS_001 */
    {
      status = OS_IOC_E_INTERNAL_NOK;
    }
    else
    {
      Os_IntStateType intState;
      Os_ObjIdxType currentReceiveIdx;

      /* #20 Get the locks. */
      Os_IocLock(&(Ioc->Ioc.Base), &intState);                                                                          /* SBSW_OS_IOC_IOCLOCK_001 */

      /* #30 Perform checks. */
      if(OS_UNLIKELY(Os_IocChannelIsEnabled(&(Ioc->Ioc.Base)) == 0u))                                                   /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_INVSTATE */
      {
        /* OS_IOC_E_INTERNAL_CHANNEL_CLOSED makes no sense here as it is not stated to the caller anyhow. */
        status = OS_IOC_E_INTERNAL_NO_DATA;
      }
      else
      {
        P2VAR(Os_IocMultiReceiveType volatile, AUTOMATIC, OS_VAR_NOINIT) dyn;
        Os_ObjIdxType receiveChannelCounter;

        dyn = Os_IocMultiReceiveGetDyn(&(Ioc->Ioc));                                                                    /* SBSW_OS_FC_PRECONDITION */
        currentReceiveIdx = dyn->NextReceiveChannel;

        status = OS_IOC_E_INTERNAL_NO_DATA;

        /* #40 For each IOC channel, beginning from where last receive ended: */
        for(receiveChannelCounter = 0; receiveChannelCounter < Ioc->Ioc.ReceiveChannelCount; receiveChannelCounter++)   /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
        {
          /* #50 Read from the IOC channel. */
          status = Os_Ioc32ReceiveInternal(&(Ioc->Receivers[currentReceiveIdx]), Data);                                 /* SBSW_OS_IOC_IOC32RECEIVEINTERNAL_001 */

          /* #60 If the channel contained data or an error occurred, abort looking for data. */
          if (status != OS_IOC_E_INTERNAL_NO_DATA)
          {
            break;
          }

          currentReceiveIdx++;
          if (currentReceiveIdx >= Ioc->Ioc.ReceiveChannelCount)                                                        /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
          {
            currentReceiveIdx = 0;
          }
        }

        /* #70 Close all channels if an error has been detected. */
        switch(status)
        {
          case OS_IOC_E_INTERNAL_OK:
            /* intentionally no break */
          case OS_IOC_E_INTERNAL_LOST_DATA:
            /* intentionally no break */
          case OS_IOC_E_INTERNAL_LOST_AND_NO_DATA:
            /* intentionally no break */
          case OS_IOC_E_INTERNAL_NO_DATA:
            /* no error to be handled inside this function */
            break;
          default:                                                                                                      /* COV_OS_INVSTATE */
            /* an internal error has occurred, close all channels */
            for(currentReceiveIdx = 0; currentReceiveIdx < Ioc->Ioc.ReceiveChannelCount; currentReceiveIdx++)           /* COV_OS_INVSTATE */
            {
              Os_IocReceiveCloseChannel(&(Ioc->Receivers[currentReceiveIdx].Ioc));                                      /* SBSW_OS_IOC_IOCRECEIVECLOSECHANNEL_001 */
            }
            /* The caller cannot handle internal error codes */
            status = OS_IOC_E_INTERNAL_NO_DATA;
            break;
        }

        /* #80 Compute the channel index for next IOC receive call. */
        dyn->NextReceiveChannel++;                                                                                      /* SBSW_OS_IOC_IOCMULTIRECEIVEGETDYN_001 */
        if (dyn->NextReceiveChannel >= Ioc->Ioc.ReceiveChannelCount)
        {
          dyn->NextReceiveChannel = 0;                                                                                  /* SBSW_OS_IOC_IOCMULTIRECEIVEGETDYN_001 */
        }
      }
      /* #90 Release the locks. */
      Os_IocUnlock(&(Ioc->Ioc.Base), &intState);                                                                        /* SBSW_OS_IOC_IOCUNLOCK_001 */
    }
  }

  return (Std_ReturnType) status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_Ioc32Receive()
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
FUNC(Std_ReturnType, OS_CODE) Os_Ioc32Receive
(
  P2CONST(Os_Ioc32ReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(uint32, TYPEDEF, AUTOMATIC) Data
)
{
  Os_IocInternalReturnType status;

  /* #10 If Ioc is not enabled: KernelPanic. */
  if(Os_IocIsEnabled() == 0u)                                                                                           /* COV_OS_INVSTATE */
  {
    Os_ErrKernelPanic();
  }

  {
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;
    Os_AppAccessMaskType permittedApplications;

    currentApplication = Os_ThreadGetCurrentApplication(Os_CoreGetThread());                                            /* SBSW_OS_IOC_THREADGETCURRENTAPPLICATION_001 */
    permittedApplications = Os_IocGetAccessingApplications(&(Ioc->Ioc.Base));                                           /* SBSW_OS_FC_PRECONDITION */

    /* #15 Perform checks. */
    if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication, permittedApplications) == OS_CHECK_FAILED))                    /* SBSW_OS_IOC_APPCHECKACCESS_001 */
    {
      status = OS_IOC_E_INTERNAL_NOK;
    }
    else
    {
      Os_IntStateType interruptState;

      /* #20 Get the locks. */
      Os_IocLock(&(Ioc->Ioc.Base), &interruptState);                                                                    /* SBSW_OS_IOC_IOCLOCK_001 */

      /* #30 Call internal receive function */
      status = Os_Ioc32ReceiveInternal(Ioc, Data);                                                                      /* SBSW_OS_FC_PRECONDITION */

      /* #40 Correct the return value and close the channel if necessary */
      if(OS_UNLIKELY((status == OS_IOC_E_INTERNAL_CLOSE_CHANNEL)))                                                      /* COV_OS_INVSTATE */
      {
        Os_IocReceiveCloseChannel(&(Ioc->Ioc));                                                                         /* SBSW_OS_FC_PRECONDITION */
        /* OS_IOC_E_INTERNAL_CLOSE_CHANNEL in not known externally, other return values are numerical identical */
        status = OS_IOC_E_INTERNAL_NO_DATA;
      }
      else if(OS_UNLIKELY((status == OS_IOC_E_INTERNAL_CHANNEL_CLOSED)))                                                /* COV_OS_INVSTATE */
      {
        /* OS_IOC_E_INTERNAL_CHANNEL_CLOSED in not known externally, other return values are numerical identical */
        status = OS_IOC_E_INTERNAL_NO_DATA;
      }
      else
      {
        /* status does not need to be changed. MISRA 14.10 */
      }

      /* #50 Release the locks. */
      Os_IocUnlock(&(Ioc->Ioc.Base), &interruptState);                                                                  /* SBSW_OS_IOC_IOCUNLOCK_001 */
    }
  }

  return (Std_ReturnType) status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_Ioc32EmptyQueue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, OS_CODE) Os_Ioc32EmptyQueue
(
  P2CONST(Os_Ioc32ReceiveConfigType, TYPEDEF, OS_CONST) Ioc
)
{
  Std_ReturnType status;

  /* #10 If Ioc is not enabled: KernelPanic. */
  if(Os_IocIsEnabled() == 0u)                                                                                           /* COV_OS_INVSTATE */
  {
    Os_ErrKernelPanic();
  }

  {
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;
    Os_AppAccessMaskType permittedApplications;

    currentApplication = Os_ThreadGetCurrentApplication(Os_CoreGetThread());                                            /* SBSW_OS_IOC_THREADGETCURRENTAPPLICATION_001 */
    permittedApplications = Os_IocGetAccessingApplications(&(Ioc->Ioc.Base));                                           /* SBSW_OS_FC_PRECONDITION */

    /* #15 Perform checks. */
    if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication, permittedApplications) == OS_CHECK_FAILED))                    /* SBSW_OS_IOC_APPCHECKACCESS_001 */
    {
      status = IOC_E_NOK;
    }
    else
    {
      /* #20 Redirect to FIFO. */
      Os_Fifo32EmptyQueue(&(Ioc->FifoRead));                                                                            /* SBSW_OS_IOC_FIFO32EMPTYQUEUE_001 */

      status = IOC_E_OK;
    }
  }

  return status;
}


/***********************************************************************************************************************
 *  Os_Ioc32EmptyMultiQueue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, OS_CODE) Os_Ioc32EmptyMultiQueue                                                                   /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
(
  P2CONST(Os_Ioc32MultiReceiveConfigType, TYPEDEF, OS_CONST) Ioc
)
{
  Std_ReturnType status;

  /* #10 If Ioc is not enabled: KernelPanic. */
  if(Os_IocIsEnabled() == 0u)                                                                                           /* COV_OS_INVSTATE */
  {
    Os_ErrKernelPanic();
  }

  {
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;
    Os_AppAccessMaskType permittedApplications;

    currentApplication = Os_ThreadGetCurrentApplication(Os_CoreGetThread());                                            /* SBSW_OS_IOC_THREADGETCURRENTAPPLICATION_001 */
    permittedApplications = Os_IocGetAccessingApplications(&(Ioc->Ioc.Base));                                           /* SBSW_OS_FC_PRECONDITION */

    /* #15 Perform static checks. */
    if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication, permittedApplications) == OS_CHECK_FAILED))                    /* SBSW_OS_IOC_APPCHECKACCESS_001 */
    {
      status = IOC_E_NOK;
    }
    else
    {
      /* #20 Call the base class method. */
      (void)Os_IocEmptyMultiQueue(&(Ioc->Ioc), Ioc32MultiReceive);                                                      /* SBSW_OS_FC_PRECONDITION */
      status = IOC_E_OK;
    }
  }

  return status;
}


/***********************************************************************************************************************
 *  Os_Ioc32Send()
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
 */
FUNC(Std_ReturnType, OS_CODE) Os_Ioc32Send
(
  P2CONST(Os_Ioc32SendConfigType, TYPEDEF, OS_CONST) Ioc,
  uint32 Data
)
{
  Std_ReturnType status;

  /* #10 If Ioc is not enabled: KernelPanic. */
  if(Os_IocIsEnabled() == 0u)                                                                                           /* COV_OS_INVSTATE */
  {
    Os_ErrKernelPanic();
  }

  {
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;
    Os_AppAccessMaskType permittedApplications;

    currentApplication = Os_ThreadGetCurrentApplication(Os_CoreGetThread());                                            /* SBSW_OS_IOC_THREADGETCURRENTAPPLICATION_001 */
    permittedApplications = Os_IocGetAccessingApplications(&(Ioc->Ioc.Base));                                           /* SBSW_OS_FC_PRECONDITION */

    /* #15 Perform static checks. */
    if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication, permittedApplications) == OS_CHECK_FAILED))                    /* SBSW_OS_IOC_APPCHECKACCESS_001 */
    {
      status = IOC_E_NOK;
    }
    else
    {
      Os_IntStateType interruptState;
      Os_FifoWriteResultType result;

      status = IOC_E_OK;

      /* #20 Get the locks. */
      Os_IocLock(&(Ioc->Ioc.Base), &interruptState);                                                                    /* SBSW_OS_IOC_IOCLOCK_001 */

      /* #30 Check that the channel is enabled and that the FIFO indices are in range. If not close the channel. */
      if(OS_UNLIKELY((Os_IocChannelIsEnabled(&(Ioc->Ioc.Base)) == 0u)))                                                 /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_INVSTATE */
      {
        status = IOC_E_LIMIT;
      }
      else if(OS_UNLIKELY((Os_IocChannelIsEnabled(&(Ioc->Ioc.Receive->Base)) == 0u)))                                   /* SBSW_OS_IOC_IOCCHANNELISENABLED_001 */ /* COV_OS_INVSTATE */
      {
        Os_IocSendCloseChannel(&(Ioc->Ioc));                                                                            /* SBSW_OS_FC_PRECONDITION */
        status = IOC_E_LIMIT;
      }
      else if(OS_UNLIKELY((Os_Fifo32IndicesInRangeOnWrite(&(Ioc->FifoWrite)) == 0u)))                                   /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_INVSTATE */
      {
        Os_IocSendCloseChannel(&(Ioc->Ioc));                                                                            /* SBSW_OS_FC_PRECONDITION */
        status = IOC_E_LIMIT;
      }
      else
      {
        /* #40 Try to write to the IOC buffer. */
        result = Os_Fifo32Enqueue(&(Ioc->FifoWrite), Data);                                                             /* SBSW_OS_FC_PRECONDITION */

        /* #50 If FIFO is already full: */
        if(OS_UNLIKELY(result == OS_FIFOWRITERESULT_BUFFEROVERFLOW))
        {
          /* #60 Increment lost counter. */
          Os_IocIncrementLostCounter(&(Ioc->Ioc));                                                                      /* SBSW_OS_FC_PRECONDITION */
          status = IOC_E_LIMIT;
        }
      }

      /* #70 Release the locks. */
      Os_IocUnlock(&(Ioc->Ioc.Base), &interruptState);                                                                  /* SBSW_OS_IOC_IOCUNLOCK_001 */

      /* #80 If no error detected: */
      if(OS_LIKELY(status == IOC_E_OK))
      {
        /* #90 Tell base class object, that sending is completed by calling the callbacks, when configured. */
        status = Os_IocCallCallbacks(&(Ioc->Ioc.Callbacks));                                                            /* SBSW_OS_FC_PRECONDITION */
      }
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050, 6080 */ /* MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  IOC Ref
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  Os_IocRefReceiveInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IocRefReceiveInit,
(
  P2CONST(Os_IocRefReceiveConfigType, TYPEDEF, OS_CONST) Ioc
))
{
  /* #10 Initialize the base class. */
  Os_IocReceiveInit(&(Ioc->Ioc));                                                                                       /* SBSW_OS_FC_PRECONDITION */

  /* #20 Initialize all fields. */
  Os_FifoRefReadInit(&(Ioc->FifoRead));                                                                                 /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_IocRefSendInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IocRefSendInit,
(
  P2CONST(Os_IocRefSendConfigType, TYPEDEF, OS_CONST) Ioc
))
{
  /* #10 Initialize the base class. */
  Os_IocSendInit(&(Ioc->Ioc));                                                                                          /* SBSW_OS_FC_PRECONDITION */

  /* #20 Initialize all fields. */
  Os_FifoRefWriteInit(&(Ioc->FifoWrite));                                                                               /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_IocRefMultiReceive()
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
 */
FUNC(Std_ReturnType, OS_CODE) Os_IocRefMultiReceive
(
  P2CONST(Os_IocRefMultiReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(void, TYPEDEF, AUTOMATIC) Data
)
{
  Os_IocInternalReturnType status;

  /* #10 If Ioc is not enabled: KernelPanic. */
  if(Os_IocIsEnabled() == 0u)                                                                                           /* COV_OS_INVSTATE */
  {
    Os_ErrKernelPanic();
  }

  {
    Os_IntStateType IntState;
    Os_ObjIdxType currentReceiveIdx;

    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;
    Os_AppAccessMaskType permittedApplications;

    currentApplication = Os_ThreadGetCurrentApplication(Os_CoreGetThread());                                            /* SBSW_OS_IOC_THREADGETCURRENTAPPLICATION_001 */
    permittedApplications = Os_IocGetAccessingApplications(&(Ioc->Ioc.Base));                                           /* SBSW_OS_FC_PRECONDITION */

    /* #15 Perform checks. */
    if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication, permittedApplications) == OS_CHECK_FAILED))                    /* SBSW_OS_IOC_APPCHECKACCESS_001 */
    {
      status = OS_IOC_E_INTERNAL_NOK;
    }
    else
    {
      /* #20 Get the locks. */
      Os_IocLock(&(Ioc->Ioc.Base), &IntState);                                                                          /* SBSW_OS_IOC_IOCLOCK_001 */

      if(OS_UNLIKELY(Os_IocChannelIsEnabled(&(Ioc->Ioc.Base)) == 0u))                                                   /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_INVSTATE */
      {
        /* OS_IOC_E_INTERNAL_CHANNEL_CLOSED makes no sense here as it is not stated to the caller anyhow. */
        status = OS_IOC_E_INTERNAL_NO_DATA;
      }
      else
      {
        P2VAR(Os_IocMultiReceiveType volatile, AUTOMATIC, OS_VAR_NOINIT) dyn;
        Os_ObjIdxType receiveChannelCounter;

        dyn = Os_IocMultiReceiveGetDyn(&(Ioc->Ioc));                                                                    /* SBSW_OS_FC_PRECONDITION */
        currentReceiveIdx = dyn->NextReceiveChannel;

        status = OS_IOC_E_INTERNAL_NO_DATA;

        /* #30 For each IOC channel, beginning from where last receive ended: */
        for(receiveChannelCounter = 0; receiveChannelCounter < Ioc->Ioc.ReceiveChannelCount; receiveChannelCounter++)   /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
        {
          /* #40 Read from the IOC channel. */
          status = Os_IocRefReceiveInternal(&(Ioc->Receivers[currentReceiveIdx]), Data);                                /* SBSW_OS_IOC_IOCREFRECEIVEINTERNAL_001 */

          /* #50 If the channel contained data or an error occurred, abort looking for data. */
          if (status != OS_IOC_E_INTERNAL_NO_DATA)
          {
            break;
          }

          currentReceiveIdx++;
          if (currentReceiveIdx >= Ioc->Ioc.ReceiveChannelCount)                                                        /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
          {
            currentReceiveIdx = 0;
          }
        }

        /* #60 Close all channels if an error has been detected. */
        switch(status)
        {
          case OS_IOC_E_INTERNAL_OK:
            /* intentionally no break */
          case OS_IOC_E_INTERNAL_LOST_DATA:
            /* intentionally no break */
          case OS_IOC_E_INTERNAL_LOST_AND_NO_DATA:
            /* intentionally no break */
          case OS_IOC_E_INTERNAL_NO_DATA:
            /* no error to be handled inside this function */
            break;
          default:                                                                                                      /* COV_OS_INVSTATE */
            /* an internal error has occurred, close all channels */
            for(currentReceiveIdx = 0; currentReceiveIdx < Ioc->Ioc.ReceiveChannelCount; currentReceiveIdx++)           /* COV_OS_INVSTATE */
            {
              Os_IocReceiveCloseChannel(&(Ioc->Receivers[currentReceiveIdx].Ioc));                                      /* SBSW_OS_IOC_IOCRECEIVECLOSECHANNEL_001 */
            }
            /* The caller cannot handle internal error codes */
            status = OS_IOC_E_INTERNAL_NO_DATA;
            break;
        }

        /* #70 Compute the channel index for next IOC receive call. */
        dyn->NextReceiveChannel++;                                                                                      /* SBSW_OS_IOC_IOCMULTIRECEIVEGETDYN_001 */
        if (dyn->NextReceiveChannel >= Ioc->Ioc.ReceiveChannelCount)
        {
          dyn->NextReceiveChannel = 0;                                                                                  /* SBSW_OS_IOC_IOCMULTIRECEIVEGETDYN_001 */
        }
      }

      /* #80 Release the locks. */
      Os_IocUnlock(&(Ioc->Ioc.Base), &IntState);                                                                        /* SBSW_OS_IOC_IOCUNLOCK_001 */
    }
  }

  return (Std_ReturnType) status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_IocRefReceive()
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
FUNC(Std_ReturnType, OS_CODE) Os_IocRefReceive
(
  P2CONST(Os_IocRefReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(void, TYPEDEF, AUTOMATIC) Data
)
{
  Os_IocInternalReturnType status;

  /* #10 If Ioc is not enabled: KernelPanic. */
  if(Os_IocIsEnabled() == 0u)                                                                                           /* COV_OS_INVSTATE */
  {
    Os_ErrKernelPanic();
  }

  {
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;
    Os_AppAccessMaskType permittedApplications;

    currentApplication = Os_ThreadGetCurrentApplication(Os_CoreGetThread());                                            /* SBSW_OS_IOC_THREADGETCURRENTAPPLICATION_001 */
    permittedApplications = Os_IocGetAccessingApplications(&(Ioc->Ioc.Base));                                           /* SBSW_OS_FC_PRECONDITION */

    /* #15 Perform checks. */
    if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication, permittedApplications) == OS_CHECK_FAILED))                    /* SBSW_OS_IOC_APPCHECKACCESS_001 */
    {
      status = OS_IOC_E_INTERNAL_NOK;
    }
    else
    {
      Os_IntStateType interruptState;

      /* #20 Get the locks. */
      Os_IocLock(&(Ioc->Ioc.Base), &interruptState);                                                                    /* SBSW_OS_IOC_IOCLOCK_001 */

      /* #30 Call internal receive function */
      status = Os_IocRefReceiveInternal(Ioc, Data);                                                                     /* SBSW_OS_FC_PRECONDITION */

      /* #40 Correct the return value and close the channel if necessary */
      if(OS_UNLIKELY((status == OS_IOC_E_INTERNAL_CLOSE_CHANNEL)))                                                      /* COV_OS_INVSTATE */
      {
        Os_IocReceiveCloseChannel(&(Ioc->Ioc));                                                                         /* SBSW_OS_FC_PRECONDITION */
        /* OS_IOC_E_INTERNAL_CLOSE_CHANNEL in not known externally, other return values are numerical identical */
        status = OS_IOC_E_INTERNAL_NO_DATA;
      }
      else if(OS_UNLIKELY((status == OS_IOC_E_INTERNAL_CHANNEL_CLOSED)))                                                /* COV_OS_INVSTATE */
      {
        /* OS_IOC_E_INTERNAL_CHANNEL_CLOSED in not known externally, other return values are numerical identical */
        status = OS_IOC_E_INTERNAL_NO_DATA;
      }
      else
      {
        /* status does not need to be changed. MISRA 14.10 */
      }

      /* #50 Release the locks. */
      Os_IocUnlock(&(Ioc->Ioc.Base), &interruptState);                                                                  /* SBSW_OS_IOC_IOCUNLOCK_001 */
    }
  }

  return (Std_ReturnType) status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_IocRefEmptyQueue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, OS_CODE) Os_IocRefEmptyQueue
(
  P2CONST(Os_IocRefReceiveConfigType, TYPEDEF, OS_CONST) Ioc
)
{
  Std_ReturnType status;

  /* #10 If Ioc is not enabled: KernelPanic. */
  if(Os_IocIsEnabled() == 0u)                                                                                           /* COV_OS_INVSTATE */
  {
    Os_ErrKernelPanic();
  }

  {
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;
    Os_AppAccessMaskType permittedApplications;

    currentApplication = Os_ThreadGetCurrentApplication(Os_CoreGetThread());                                            /* SBSW_OS_IOC_THREADGETCURRENTAPPLICATION_001 */
    permittedApplications = Os_IocGetAccessingApplications(&(Ioc->Ioc.Base));                                           /* SBSW_OS_FC_PRECONDITION */

    /* #15 Perform checks. */
    if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication, permittedApplications) == OS_CHECK_FAILED))                    /* SBSW_OS_IOC_APPCHECKACCESS_001 */
    {
      status = IOC_E_NOK;
    }
    else
    {
      /* #20 Redirect to FIFO. */
      Os_FifoRefEmptyQueue(&(Ioc->FifoRead));                                                                           /* SBSW_OS_IOC_FIFOREFEMPTYQUEUE_001 */

      status = IOC_E_OK;
    }
  }

  return status;
}


/***********************************************************************************************************************
 *  Os_IocRefEmptyMultiQueue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, OS_CODE) Os_IocRefEmptyMultiQueue                                                                  /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
(
  P2CONST(Os_IocRefMultiReceiveConfigType, TYPEDEF, OS_CONST) Ioc
)
{
  Std_ReturnType status;

  /* #10 If Ioc is not enabled: KernelPanic. */
  if(Os_IocIsEnabled() == 0u)                                                                                           /* COV_OS_INVSTATE */
  {
    Os_ErrKernelPanic();
  }

  {
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;
    Os_AppAccessMaskType permittedApplications;

    currentApplication = Os_ThreadGetCurrentApplication(Os_CoreGetThread());                                            /* SBSW_OS_IOC_THREADGETCURRENTAPPLICATION_001 */
    permittedApplications = Os_IocGetAccessingApplications(&(Ioc->Ioc.Base));                                           /* SBSW_OS_FC_PRECONDITION */

    /* #15 Perform static checks. */
    if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication, permittedApplications) == OS_CHECK_FAILED))                    /* SBSW_OS_IOC_APPCHECKACCESS_001 */
    {
      status = IOC_E_NOK;
    }
    else
    {
      /* #20 Call the base class method. */
      (void)Os_IocEmptyMultiQueue(&(Ioc->Ioc), IocRefMultiReceive);                                                     /* SBSW_OS_FC_PRECONDITION */
      status = IOC_E_OK;
    }
  }

  return status;
}


/***********************************************************************************************************************
 *  Os_IocRefSend()
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
 */
FUNC(Std_ReturnType, OS_CODE) Os_IocRefSend
(
  P2CONST(Os_IocRefSendConfigType, TYPEDEF, OS_CONST) Ioc,
  P2CONST(void, TYPEDEF, AUTOMATIC) Data
)
{
  Std_ReturnType status;

  /* #10 If Ioc is not enabled: KernelPanic. */
  if(Os_IocIsEnabled() == 0u)                                                                                           /* COV_OS_INVSTATE */
  {
    Os_ErrKernelPanic();
  }

  {
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;
    Os_AppAccessMaskType permittedApplications;

    currentApplication = Os_ThreadGetCurrentApplication(Os_CoreGetThread());                                            /* SBSW_OS_IOC_THREADGETCURRENTAPPLICATION_001 */
    permittedApplications = Os_IocGetAccessingApplications(&(Ioc->Ioc.Base));                                           /* SBSW_OS_FC_PRECONDITION */

    /* #15 Perform static checks. */
    if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication, permittedApplications) == OS_CHECK_FAILED))                    /* SBSW_OS_IOC_APPCHECKACCESS_001 */
    {
      status = IOC_E_NOK;
    }
    else
    {
      Os_IntStateType interruptState;
      Os_FifoWriteResultType result;

      status = IOC_E_OK;

      /* #20 Get the locks. */
      Os_IocLock(&(Ioc->Ioc.Base), &interruptState);                                                                    /* SBSW_OS_IOC_IOCLOCK_001 */

      /* #30 Check that the channel is enabled and that the FIFO indices are in range. If not close the channel. */
      if(OS_UNLIKELY((Os_IocChannelIsEnabled(&(Ioc->Ioc.Base)) == 0u)))                                                 /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_INVSTATE */
      {
        status = IOC_E_LIMIT;
      }
      else if(OS_UNLIKELY((Os_IocChannelIsEnabled(&(Ioc->Ioc.Receive->Base)) == 0u)))                                   /* SBSW_OS_IOC_IOCCHANNELISENABLED_002 */ /* COV_OS_INVSTATE */
      {
        Os_IocSendCloseChannel(&(Ioc->Ioc));                                                                            /* SBSW_OS_FC_PRECONDITION */
        status = IOC_E_LIMIT;
      }
      else if(OS_UNLIKELY((Os_FifoRefIndicesInRangeOnWrite(&(Ioc->FifoWrite)) == 0u)))                                  /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_INVSTATE */
      {
        Os_IocSendCloseChannel(&(Ioc->Ioc));                                                                            /* SBSW_OS_FC_PRECONDITION */
        status = IOC_E_LIMIT;
      }
      else
      {
        /* #40 Try to write to the IOC buffer. */
        result = Os_FifoRefEnqueue(&(Ioc->FifoWrite), Data);                                                            /* SBSW_OS_FC_PRECONDITION */

        /* #50 If FIFO is already full: */
        if(OS_UNLIKELY(result == OS_FIFOWRITERESULT_BUFFEROVERFLOW))
        {
          /* #60 Increment lost counter. */
          Os_IocIncrementLostCounter(&(Ioc->Ioc));                                                                      /* SBSW_OS_FC_PRECONDITION */
          status = IOC_E_LIMIT;
        }
      }

      /* #70 Release the locks. */
      Os_IocUnlock(&(Ioc->Ioc.Base), &interruptState);                                                                  /* SBSW_OS_IOC_IOCUNLOCK_001 */

      /* #80 If no error detected: */
      if(OS_LIKELY(status == IOC_E_OK))
      {
        /* #90 Tell base class object, that sending is completed by calling the callbacks, when configured. */
        status = Os_IocCallCallbacks(&(Ioc->Ioc.Callbacks));                                                            /* SBSW_OS_FC_PRECONDITION */
      }
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050, 6080 */ /* MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  IOC Single Buffer
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_IocWriteInit()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IocWriteInit,
(
  P2CONST(Os_IocWriteConfigType, TYPEDEF, OS_CONST) Ioc
))
{
  /* #10 Initialize Base Data. */
  Os_IocInitBase(&(Ioc->Ioc));                                                                                          /* SBSW_OS_FC_PRECONDITION */

  /* #20 If a callback function is configured: */
  if(Ioc->InitCbk != NULL_PTR)
  {
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) coreAsr;
    coreAsr = Os_Core2AsrCore(Os_CoreGetCurrentCore());                                                                 /* SBSW_OS_IOC_CORE2ASRCORE_001 */

    /* #30 Enter critical user section. */
    Os_CoreCriticalUserSectionEnter(coreAsr);                                                                           /* SBSW_OS_IOC_CORECRITICALUSERSECTIONENTER_001 */

    /* #40 Call the initialization callback function. */
    Ioc->InitCbk(Ioc->Data);                                                                                            /* SBSW_OS_IOC_IOCWRITEINITCBK */

    /* #50 Leave critical user section. */
    Os_CoreCriticalUserSectionLeave(coreAsr);                                                                           /* SBSW_OS_IOC_CORECRITICALUSERSECTIONLEAVE_001 */
  }
}


/***********************************************************************************************************************
 *  Os_IocRead()
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
FUNC(Std_ReturnType, OS_CODE) Os_IocRead
(
  P2CONST(Os_IocReadConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(void, TYPEDEF, AUTOMATIC) Data
)
{
  Std_ReturnType status;

  /* #10 If Ioc is not enabled: KernelPanic. */
  if(Os_IocIsEnabled() == 0u)                                                                                           /* COV_OS_INVSTATE */
  {
    Os_ErrKernelPanic();
  }

  {
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;
    Os_AppAccessMaskType permittedApplications;

    currentApplication = Os_ThreadGetCurrentApplication(Os_CoreGetThread());                                            /* SBSW_OS_IOC_THREADGETCURRENTAPPLICATION_001 */
    permittedApplications = Os_IocGetAccessingApplications(&(Ioc->Ioc));                                                /* SBSW_OS_FC_PRECONDITION */

    /* #15 Perform static checks. */
    if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication, permittedApplications) == OS_CHECK_FAILED))                    /* SBSW_OS_IOC_APPCHECKACCESS_001 */
    {
      status = IOC_E_NOK;
    }
    else
    {
      Os_IntStateType interruptState;

      /* #20 Get the locks. */
      Os_IocLock(&(Ioc->Ioc), &interruptState);                                                                         /* SBSW_OS_IOC_IOCLOCK_001 */

      /* #30 Copy data from the IOC buffer. */
      Ioc->CopyCbk(Ioc->Data, Data);                                                                                    /* SBSW_OS_IOC_IOCREADCOPYCBK_001 */

      /* #40 Release the locks. */
      Os_IocUnlock(&(Ioc->Ioc), &interruptState);                                                                       /* SBSW_OS_IOC_IOCUNLOCK_001 */

      status = IOC_E_OK;
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6030, 6050, 6080 */ /* MD_Os_STCYC, MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_IocWrite()
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
FUNC(Std_ReturnType, OS_CODE) Os_IocWrite
(
  P2CONST(Os_IocWriteConfigType, TYPEDEF, OS_CONST) Ioc,
  P2CONST(void, TYPEDEF, AUTOMATIC) Data
)
{
  Std_ReturnType status;

  /* #10 If Ioc is not enabled: KernelPanic. */
  if(Os_IocIsEnabled() == 0u)                                                                                           /* COV_OS_INVSTATE */
  {
    Os_ErrKernelPanic();
  }

  {
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;
    Os_AppAccessMaskType permittedApplications;

    currentApplication = Os_ThreadGetCurrentApplication(Os_CoreGetThread());                                            /* SBSW_OS_IOC_THREADGETCURRENTAPPLICATION_001 */
    permittedApplications = Os_IocGetAccessingApplications(&(Ioc->Ioc));                                                /* SBSW_OS_FC_PRECONDITION */

    /* #15 Perform checks. */
    if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication, permittedApplications) == OS_CHECK_FAILED))                    /* SBSW_OS_IOC_APPCHECKACCESS_001 */
    {
      status = IOC_E_NOK;
    }
    else
    {
      Os_IntStateType InterruptState;

      /* #20 Get the locks. */
      Os_IocLock(&(Ioc->Ioc), &InterruptState);                                                                         /* SBSW_OS_IOC_IOCLOCK_001 */

      /* #30 Copy data into the IOC buffer. */
      Ioc->CopyCbk(Data, Ioc->Data);                                                                                    /* SBSW_OS_IOC_IOCWRITECOPYCBK */

      /* #40 Release the locks. */
      Os_IocUnlock(&(Ioc->Ioc), &InterruptState);                                                                       /* SBSW_OS_IOC_IOCUNLOCK_001 */

      /* #50 Tell base class object, that sending is completed by calling the callbacks, when configured. */
      status = Os_IocCallCallbacks(&(Ioc->Callbacks));                                                                  /* SBSW_OS_FC_PRECONDITION */
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6030, 6050, 6080 */ /* MD_Os_STCYC, MD_Os_STCAL, MD_Os_STMIF */


#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* SBSW_JUSTIFICATION_BEGIN
\ID SBSW_OS_IOC_IOC08RECEIVEINIT_001
  \DESCRIPTION    Os_Ioc08ReceiveInit is called with the return value of Os_IocIoc2Ioc08Receive.
  \COUNTERMEASURE \N [CM_OS_IOCIOC2IOC08RECEIVE_N]

\ID SBSW_OS_IOC_IOC08RECEIVEINIT_002
  \DESCRIPTION    Os_Ioc08ReceiveInit is called with a receiver object. The receiver object is derived by an index
                  from the Receivers array of an Ioc 8 object. The Ioc object is an argument of the calling function.
                  The index is limited to the ReceiveChannelCount of the Ioc. The correctness of the caller argument is
                  ensured by precondition. The compliance of the precondition is check during review.
  \COUNTERMEASURE \M [CM_OS_IOC08MULTIRECEIVE_RECEIVERS_M]

\ID SBSW_OS_IOC_IOC08MULTIRECEIVEINIT_001
  \DESCRIPTION    Os_Ioc08MultiReceiveInit is called with the return value of Os_IocIoc2Ioc08MultiReceive.
  \COUNTERMEASURE \N [CM_OS_IOCIOC2IOC08MULTIRECEIVE_N]

\ID SBSW_OS_IOC_IOC08SENDINIT_001
  \DESCRIPTION    Os_Ioc08SendInit is called with the return value of Os_IocIoc2Ioc08Send.
  \COUNTERMEASURE \N [CM_OS_IOCIOC2IOC08SEND_N]

\ID SBSW_OS_IOC_IOC16RECEIVEINIT_001
  \DESCRIPTION    Os_Ioc16ReceiveInit is called with the return value of Os_IocIoc2Ioc16Receive.
  \COUNTERMEASURE \N [CM_OS_IOCIOC2IOC16RECEIVE_N]

\ID SBSW_OS_IOC_IOC16RECEIVEINIT_002
  \DESCRIPTION    Os_Ioc16ReceiveInit is called with a receiver object. The receiver object is derived by an index
                  from the Receivers array of an Ioc 16 object. The Ioc object is an argument of the calling function.
                  The index is limited to the ReceiveChannelCount of the Ioc. The correctness of the caller argument is
                  ensured by precondition. The compliance of the precondition is check during review.
  \COUNTERMEASURE \M [CM_OS_IOC16MULTIRECEIVE_RECEIVERS_M]

\ID SBSW_OS_IOC_IOC16MULTIRECEIVEINIT_001
  \DESCRIPTION    Os_Ioc16MultiReceiveInit is called with the return value of Os_IocIoc2Ioc16MultiReceive.
  \COUNTERMEASURE \N [CM_OS_IOCIOC2IOC16MULTIRECEIVE_N]

\ID SBSW_OS_IOC_IOC16SENDINIT_001
  \DESCRIPTION    Os_Ioc16SendInit is called with the return value of Os_IocIoc2Ioc16Send.
  \COUNTERMEASURE \N [CM_OS_IOCIOC2IOC16SEND_N]

\ID SBSW_OS_IOC_IOC32RECEIVEINIT_001
  \DESCRIPTION    Os_Ioc32ReceiveInit is called with the return value of Os_IocIoc2Ioc32Receive.
  \COUNTERMEASURE \N [CM_OS_IOCIOC2IOC32RECEIVE_N]

\ID SBSW_OS_IOC_IOC32RECEIVEINIT_002
  \DESCRIPTION    Os_Ioc32ReceiveInit is called with a receiver object. The receiver object is derived by an index
                  from the Receivers array of an Ioc 32 object. The Ioc object is an argument of the calling function.
                  The index is limited to the ReceiveChannelCount of the Ioc. The correctness of the caller argument is
                  ensured by precondition. The compliance of the precondition is check during review.
  \COUNTERMEASURE \M [CM_OS_IOC32MULTIRECEIVE_RECEIVERS_M]

\ID SBSW_OS_IOC_FIFO08READINIT_001
  \DESCRIPTION    Os_Fifo08ReadInit is called with the return value of Os_IocIoc2Ioc08Receive.
  \COUNTERMEASURE \N [CM_OS_IOCIOC2IOC08RECEIVE_N]

\ID SBSW_OS_IOC_FIFO16READINIT_001
  \DESCRIPTION    Os_Fifo16ReadInit is called with the return value of Os_IocIoc2Ioc16Receive.
  \COUNTERMEASURE \N [CM_OS_IOCIOC2IOC16RECEIVE_N]

\ID SBSW_OS_IOC_FIFO32READINIT_001
  \DESCRIPTION    Os_Fifo32ReadInit is called with the return value of Os_IocIoc2Ioc32Receive.
  \COUNTERMEASURE \N [CM_OS_IOCIOC2IOC32RECEIVE_N]

\ID SBSW_OS_IOC_FIFOREFREADINIT_001
  \DESCRIPTION    Os_FifoRefReadInit is called with the return value of Os_IocIoc2IocRefReceive.
  \COUNTERMEASURE \N [CM_OS_IOCIOC2IOCREFRECEIVE_N]

\ID SBSW_OS_IOC_FIFO08WRITEINIT_001
  \DESCRIPTION    Os_Fifo08WriteInit is called with the return value of Os_IocIoc2Ioc08Send.
  \COUNTERMEASURE \N [CM_OS_IOCIOC2IOC08RECEIVE_N]

\ID SBSW_OS_IOC_FIFO16WRITEINIT_001
  \DESCRIPTION    Os_Fifo16WriteInit is called with the return value of Os_IocIoc2Ioc16Send.
  \COUNTERMEASURE \N [CM_OS_IOCIOC2IOC16RECEIVE_N]

\ID SBSW_OS_IOC_FIFO32WRITEINIT_001
  \DESCRIPTION    Os_Fifo32WriteInit is called with the return value of Os_IocIoc2Ioc32Send.
  \COUNTERMEASURE \N [CM_OS_IOCIOC2IOC32RECEIVE_N]

\ID SBSW_OS_IOC_FIFOREFWRITEINIT_001
  \DESCRIPTION    Os_FifoRefWriteInit is called with the return value of Os_IocIoc2IocRefSend.
  \COUNTERMEASURE \N [CM_OS_IOCIOC2IOCREFRECEIVE_N]

\ID SBSW_OS_IOC_IOC32MULTIRECEIVEINIT_001
  \DESCRIPTION    Os_Ioc32MultiReceiveInit is called with the return value of Os_IocIoc2Ioc32MultiReceive.
  \COUNTERMEASURE \N [CM_OS_IOCIOC2IOC32MULTIRECEIVE_N]

\ID SBSW_OS_IOC_IOC32SENDINIT_001
  \DESCRIPTION    Os_Ioc32SendInit is called with the return value of Os_IocIoc2Ioc32Send.
  \COUNTERMEASURE \N [CM_OS_IOCIOC2IOC32SEND_N]

\ID SBSW_OS_IOC_IOCREFRECEIVEINIT_001
  \DESCRIPTION    Os_IocRefReceiveInit is called with the return value of Os_IocIoc2IocRefReceive.
  \COUNTERMEASURE \N [CM_OS_IOCIOC2IOCREFRECEIVE_N]

\ID SBSW_OS_IOC_IOCREFRECEIVEINIT_002
  \DESCRIPTION    Os_IocRefReceiveInit is called with a receiver object. The receiver object is derived by an index
                  from the Receivers array of an Ioc Ref object. The Ioc object is an argument of the calling function.
                  The index is limited to the ReceiveChannelCount of the Ioc. The correctness of the caller argument is
                  ensured by precondition. The compliance of the precondition is check during review.
  \COUNTERMEASURE \M [CM_OS_IOCREFMULTIRECEIVE_RECEIVERS_M]

\ID SBSW_OS_IOC_IOCREFMULTIRECEIVEINIT_001
  \DESCRIPTION    Os_IocRefMultiReceiveInit is called with the return value of Os_IocIoc2IocRefMultiReceive.
  \COUNTERMEASURE \N [CM_OS_IOCIOC2IOCREFMULTIRECEIVE_N]

\ID SBSW_OS_IOC_IOCREFSENDINIT_001
  \DESCRIPTION    Os_IocRefSendInit is called with the return value of Os_IocIoc2IocRefSend.
  \COUNTERMEASURE \N [CM_OS_IOCIOC2IOCREFSEND_N]

\ID SBSW_OS_IOC_IOCWRITEINIT_001
  \DESCRIPTION    Os_IocWriteInit is called with the return value of Os_IocIoc2IocWrite.
  \COUNTERMEASURE \N [CM_OS_IOCIOC2IOCWRITE_N]

\ID SBSW_OS_IOC_IOCRECEIVEGETDYN_001
  \DESCRIPTION    Write access to the return value of Os_IocReceiveGetDyn.
  \COUNTERMEASURE \M [CM_OS_IOCRECEIVEGETDYN_M]

\ID SBSW_OS_IOC_IOCSENDGETDYN_001
  \DESCRIPTION    Os_IocSendGetDyn is called with a Send reference derived from an IOC object. The IOC
                  object is passed as reference to the calling function. The correctness of the caller argument is
                  ensured by precondition. The compliance of the precondition is check during review.
  \COUNTERMEASURE \M [CM_OS_IOCRECEIVE_SEND_M]

\ID SBSW_OS_IOC_IOCSENDGETDYN_002
  \DESCRIPTION    Write access to the return value of Os_IocSendGetDyn.
  \COUNTERMEASURE \M [CM_OS_IOCSENDGETDYN_M]

\ID SBSW_OS_IOC_IOCMULTIRECEIVEGETDYN_001
  \DESCRIPTION    Write access to the return value of Os_IocMultiReceiveGetDyn.
  \COUNTERMEASURE \M [CM_OS_IOCMULTIRECEIVEGETDYN_M]

\ID SBSW_OS_IOC_SPINLOCKINTERNALGET_001
  \DESCRIPTION    Os_SpinlockInternalGet is called with a Spinlock reference derived from an IOC object. The IOC object
                  is passed as reference to the calling function. The correctness of the caller argument is ensured by
                  precondition. The compliance of the precondition is check during review.
  \COUNTERMEASURE \M [CM_OS_IOC_SPINLOCK_M]

\ID SBSW_OS_IOC_SPINLOCKINTERNALRELEASE_001
  \DESCRIPTION    Os_SpinlockInternalRelease is called with a Spinlock reference derived from an IOC object. The IOC
                  object is passed as reference to the calling function. The correctness of the caller argument is
                  ensured by precondition. The compliance of the precondition is check during review.
  \COUNTERMEASURE \M [CM_OS_IOC_SPINLOCK_M]

\ID SBSW_OS_IOC_IOC08EMPTYQUEUE_001
  \DESCRIPTION    Os_Ioc08EmptyQueue is called with a receiver object. The receiver object is derived by an index
                  from the return value of Os_IocIoc2IocRefMultiReceive. The index is limited to the ReceiveChannelCount
                  of the Ioc.
  \COUNTERMEASURE \M [CM_OS_IOC08MULTIRECEIVE_RECEIVERS_M]

\ID SBSW_OS_IOC_IOC16EMPTYQUEUE_001
  \DESCRIPTION    Os_Ioc16EmptyQueue is called with a receiver object. The receiver object is derived by an index
                  from the return value of Os_IocIoc2IocRefMultiReceive. The index is limited to the ReceiveChannelCount
                  of the Ioc.
  \COUNTERMEASURE \M [CM_OS_IOC16MULTIRECEIVE_RECEIVERS_M]

\ID SBSW_OS_IOC_IOC32EMPTYQUEUE_001
  \DESCRIPTION    Os_Ioc32EmptyQueue is called with a receiver object. The receiver object is derived by an index
                  from the return value of Os_IocIoc2IocRefMultiReceive. The index is limited to the ReceiveChannelCount
                  of the Ioc.
  \COUNTERMEASURE \M [CM_OS_IOC32MULTIRECEIVE_RECEIVERS_M]

\ID SBSW_OS_IOC_IOCREFEMPTYQUEUE_001
  \DESCRIPTION    Os_IocRefEmptyQueue is called with a receiver object. The receiver object is derived by an index
                  from the return value of Os_IocIoc2IocRefMultiReceive. The index is limited to the ReceiveChannelCount
                  of the Ioc.
  \COUNTERMEASURE \M [CM_OS_IOCREFMULTIRECEIVE_RECEIVERS_M]

\ID SBSW_OS_IOC_IOCCHANNELISENABLED_001
  \DESCRIPTION    Os_IocChannelIsEnabled is called with a Send reference derived from an IOC object. The IOC
                  object is passed as reference to the calling function. The correctness of the caller argument is
                  ensured by precondition. The compliance of the precondition is check during review.
  \COUNTERMEASURE \M [CM_OS_IOCRECEIVE_SEND_M]

\ID SBSW_OS_IOC_IOCCHANNELISENABLED_002
  \DESCRIPTION    Os_IocChannelIsEnabled is called with a Receive reference derived from an IOC object. The IOC
                  object is passed as reference to the calling function. The correctness of the caller argument is
                  ensured by precondition. The compliance of the precondition is check during review.
  \COUNTERMEASURE \M [CM_OS_IOCSEND_RECEIVE_M]

\ID SBSW_OS_IOC_IOCLOCK_001
  \DESCRIPTION    Os_IocLock is called with a pointer to a local variable and a reference derived from an IOC object.
                  The IOC object is passed as reference to the calling function.
  \COUNTERMEASURE \N [CM_OS_PRECONDITION_N]

\ID SBSW_OS_IOC_IOCUNLOCK_001
  \DESCRIPTION    Os_IocUnlock is called with a pointer to a local variable and a reference derived from an IOC object.
                  The IOC object is passed as reference to the calling function.
  \COUNTERMEASURE \N [CM_OS_PRECONDITION_N]

\ID SBSW_OS_IOC_IOC08RECEIVEINTERNAL_001
  \DESCRIPTION    Os_Ioc08ReceiveInternal is called with a receiver object and a Data object. The receiver object is
                  derived by an index from the Receivers array of an Ioc object. The index is limited to the
                  ReceiveChannelCount of the Ioc. The Ioc and the Data object are passed as parameters to the calling
                  function. The correctness of the parameters is ensured by precondition. The compliance of the
                  precondition is check during review.
  \COUNTERMEASURE \M [CM_OS_IOC08MULTIRECEIVE_RECEIVERS_M]

\ID SBSW_OS_IOC_IOC16RECEIVEINTERNAL_001
  \DESCRIPTION    Os_Ioc16ReceiveInternal is called with a receiver object and a Data object. The receiver object is
                  derived by an index from the Receivers array of an Ioc object. The index is limited to the
                  ReceiveChannelCount of the Ioc. The Ioc and the Data object are passed as parameters to the calling
                  function. The correctness of the parameters is ensured by precondition. The compliance of the
                  precondition is check during review.
  \COUNTERMEASURE \M [CM_OS_IOC16MULTIRECEIVE_RECEIVERS_M]

\ID SBSW_OS_IOC_IOC32RECEIVEINTERNAL_001
  \DESCRIPTION    Os_Ioc32ReceiveInternal is called with a receiver object and a Data object. The receiver object is
                  derived by an index from the Receivers array of an Ioc object. The index is limited to the
                  ReceiveChannelCount of the Ioc. The Ioc and the Data object are passed as parameters to the calling
                  function. The correctness of the parameters is ensured by precondition. The compliance of the
                  precondition is check during review.
  \COUNTERMEASURE \M [CM_OS_IOC32MULTIRECEIVE_RECEIVERS_M]

\ID SBSW_OS_IOC_IOCREFRECEIVEINTERNAL_001
  \DESCRIPTION    Os_IocRefReceiveInternal is called with a receiver object and a Data object. The receiver object is
                  derived by an index from the Receivers array of an Ioc object. The index is limited to the
                  ReceiveChannelCount of the Ioc. The Ioc and the Data object are passed as parameters to the calling
                  function. The correctness of the parameters is ensured by precondition. The compliance of the
                  precondition is check during review.
  \COUNTERMEASURE \M [CM_OS_IOCREFMULTIRECEIVE_RECEIVERS_M]

\ID SBSW_OS_IOC_IOCRECEIVECLOSECHANNEL_001
  \DESCRIPTION    Os_IocReceiveCloseChannel is called with a receiver object. The receiver object is
                  derived by an index from the Receivers array of an Ioc object. The index is limited to the
                  ReceiveChannelCount of the Ioc. The Ioc object is passed as parameter to the calling
                  function. The correctness of the parameter is ensured by precondition. The compliance of the
                  precondition is check during review.
  \COUNTERMEASURE \M [CM_OS_IOC08MULTIRECEIVE_RECEIVERS_M]
                  \M [CM_OS_IOC16MULTIRECEIVE_RECEIVERS_M]
                  \M [CM_OS_IOC32MULTIRECEIVE_RECEIVERS_M]
                  \M [CM_OS_IOCREFMULTIRECEIVE_RECEIVERS_M]

\ID SBSW_OS_IOC_IOCWRITECOPYCBK
  \DESCRIPTION    CopyCbk function pointer call with caller argument Data and Ioc->Data. CopyCbk and Data are
                  derived from an Ioc object. Ioc and Data are passed as parameter to the calling
                  function. The correctness of the parameters is ensured by precondition. The compliance of the
                  precondition is check during review.
  \COUNTERMEASURE \M [CM_OS_IOCWRITE_COPYCBK_M]
                  \M [CM_OS_IOCWRITE_DATA_M]

\ID SBSW_OS_IOC_IOCWRITEINITCBK
  \DESCRIPTION    InitCbk function pointer call with caller argument Ioc->Data. InitCbk and Data are
                  derived from an Ioc object. Ioc and Data are passed as parameter to the calling
                  function. The correctness of the parameter is ensured by precondition. The compliance of the
                  precondition is check during review.
  \COUNTERMEASURE \M [CM_OS_IOCWRITE_DATA_M]
                  \R [CM_OS_IOCWRITE_INITCBK_R]

\ID SBSW_OS_IOC_IOCREADCOPYCBK_001
  \DESCRIPTION    CopyCbk function pointer call with caller argument Data and Ioc->Data. CopyCbk and Data are
                  derived from an Ioc object. Ioc and Data are passed as parameter to the calling
                  function. The correctness of the parameters is ensured by precondition. The compliance of the
                  precondition is check during review.
  \COUNTERMEASURE \M [CM_OS_IOCREAD_COPYCBK_M]
                  \M [CM_OS_IOCREAD_DATA_M]

\ID SBSW_OS_IOC_THREADGETCURRENTAPPLICATION_001
 \DESCRIPTION    Os_ThreadGetCurrentApplication is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_IOC_APPCHECKACCESS_001
 \DESCRIPTION    Os_AppCheckAccess is called with the return value of Os_ThreadGetCurrentApplication.
 \COUNTERMEASURE \N [CM_OS_THREADGETCURRENTAPPLICATION_N]

\ID SBSW_OS_IOC_FIFO08EMPTYQUEUE_001
 \DESCRIPTION    Os_Fifo08EmptyQueue is called with value derived from an Ioc object. Ioc is passed as parameter to the
                 calling function.
 \COUNTERMEASURE \N [CM_OS_PRECONDITION_N]

\ID SBSW_OS_IOC_FIFO16EMPTYQUEUE_001
 \DESCRIPTION    Os_Fifo16EmptyQueue is called with value derived from an Ioc object. Ioc is passed as parameter to the
                 calling function.
 \COUNTERMEASURE \N [CM_OS_PRECONDITION_N]

\ID SBSW_OS_IOC_FIFO32EMPTYQUEUE_001
 \DESCRIPTION    Os_Fifo32EmptyQueue is called with value derived from an Ioc object. Ioc is passed as parameter to the
                 calling function.
 \COUNTERMEASURE \N [CM_OS_PRECONDITION_N]

\ID SBSW_OS_IOC_FIFOREFEMPTYQUEUE_001
 \DESCRIPTION    Os_FifoRefEmptyQueue is called with value derived from an Ioc object. Ioc is passed as parameter to the
                 calling function.
 \COUNTERMEASURE \N [CM_OS_PRECONDITION_N]

\ID SBSW_OS_IOC_HOOKINITCALLBACK_001
 \DESCRIPTION    Os_HookInitCallback is called with a Callback which is derived from an argument passed to the caller.
 \COUNTERMEASURE \R [CM_OS_IOC_CALLBACK_R]

\ID SBSW_OS_IOC_HOOKCALLCALLBACK_001
  \DESCRIPTION    Os_HookCallCallback is called with a callback derived with a loop index from the CallbackRefs of an
                  Os_IocCallbacksConfigType object. The object is passed as reference to the caller function.
                  The correctness of the parameters is ensured by precondition. The compliance of the precondition is
                  check during review.
  \COUNTERMEASURE \M [CM_OS_IOCCALLBACKSCONFIG_CALLBACKREFS_01_02_M]
                  \R [CM_OS_IOCCALLBACKSCONFIG_CALLBACKREFS_02_02_R]

\ID SBSW_OS_IOC_CORE2ASRCORE_001
 \DESCRIPTION    Os_Core2AsrCore is called with the return value of Os_CoreGetCurrentCore.
 \COUNTERMEASURE \S [CM_OS_COREGETCURRENTCORE_S]

\ID SBSW_OS_IOC_CORECRITICALUSERSECTIONENTER_001
 \DESCRIPTION    Os_CoreCriticalUserSectionEnter is called with the return value of Os_Core2AsrCore.
 \COUNTERMEASURE \N [CM_OS_CORE2ASRCORE_N]

\ID SBSW_OS_IOC_CORECRITICALUSERSECTIONLEAVE_001
 \DESCRIPTION    Os_CoreCriticalUserSectionLeave is called with the return value of Os_Core2AsrCore.
 \COUNTERMEASURE \N [CM_OS_CORE2ASRCORE_N]

SBSW_JUSTIFICATION_END */

/*
\CM CM_OS_IOCRECEIVE_SEND_M
      Verify that the Send pointer of each Os_IocReceiveConfigType object is initialized with no NULL_PTR.

\CM CM_OS_IOCSEND_RECEIVE_M
      Verify that the Receive pointer of each Os_IocSendConfigType object is initialized with no NULL_PTR.

\CM CM_OS_IOC_CALLBACK_R
      Runtime check ensures, that the passed callback is a non NULL_PTR.

\CM CM_OS_IOC08MULTIRECEIVE_RECEIVERS_M
      Verify that:
        1. Verify that each Os_Ioc08MultiReceiveConfigType object's Receivers pointer is no NULL_PTR,
        2. that the size of the Reveivers array equals the ReceiveChannelCount.

\CM CM_OS_IOC16MULTIRECEIVE_RECEIVERS_M
      Verify that:
        1. Verify that each Os_Ioc16MultiReceiveConfigType object's Receivers pointer is no NULL_PTR,
        2. that the size of the Reveivers array equals the ReceiveChannelCount.

\CM CM_OS_IOC32MULTIRECEIVE_RECEIVERS_M
      Verify that:
        1. Verify that each Os_Ioc32MultiReceiveConfigType object's Receivers pointer is no NULL_PTR,
        2. that the size of the Reveivers array equals the ReceiveChannelCount.

\CM CM_OS_IOCREFMULTIRECEIVE_RECEIVERS_M
      Verify that:
        1. Verify that each Os_IocRefMultiReceiveConfigType object's Receivers pointer is no NULL_PTR,
        2. that the size of the Reveivers array equals the ReceiveChannelCount.

\CM CM_OS_IOCRECEIVEGETDYN_M
      Verify that the IOC Dyn pointer of each Os_IocReceiveConfigType object is initialized with a
      dynamic IOC derived from an Os_IocReceiveType object.

\CM CM_OS_IOCSENDGETDYN_M
      Verify that the IOC Dyn pointer of each Os_IocSendConfigType object is initialized with a
      dynamic IOC derived from an Os_IocSendType object.

\CM CM_OS_IOCMULTIRECEIVEGETDYN_M
      Verify that the IOC Dyn pointer of each Os_IocMultiReceiveConfigType object is initialized with a
      dynamic IOC derived from an Os_IocMultiReceiveType object.

\CM CM_OS_IOCIOC2IOC08MULTIRECEIVE_N
      Precondition ensures that the pointer is valid. The compliance of the precondition is check during review.

\CM CM_OS_IOCIOC2IOC16MULTIRECEIVE_N
      Precondition ensures that the pointer is valid. The compliance of the precondition is check during review.

\CM CM_OS_IOCIOC2IOC32MULTIRECEIVE_N
      Precondition ensures that the pointer is valid. The compliance of the precondition is check during review.

\CM CM_OS_IOCIOC2IOCREFMULTIRECEIVE_N
      Precondition ensures that the pointer is valid. The compliance of the precondition is check during review.

\CM CM_OS_IOCIOC2IOCWRITE_N
      Precondition ensures that the pointer is valid. The compliance of the precondition is check during review.

\CM CM_OS_IOCIOC2IOC08RECEIVE_N
      Precondition ensures that the pointer is valid. The compliance of the precondition is check during review.

\CM CM_OS_IOCIOC2IOC16RECEIVE_N
      Precondition ensures that the pointer is valid. The compliance of the precondition is check during review.

\CM CM_OS_IOCIOC2IOC32RECEIVE_N
      Precondition ensures that the pointer is valid. The compliance of the precondition is check during review.

\CM CM_OS_IOCIOC2IOCREFRECEIVE_N
      Precondition ensures that the pointer is valid. The compliance of the precondition is check during review.

\CM CM_OS_IOCIOC2IOC08SEND_N
      Precondition ensures that the pointer is valid. The compliance of the precondition is check during review.

\CM CM_OS_IOCIOC2IOC16SEND_N
      Precondition ensures that the pointer is valid. The compliance of the precondition is check during review.

\CM CM_OS_IOCIOC2IOC32SEND_N
      Precondition ensures that the pointer is valid. The compliance of the precondition is check during review.

\CM CM_OS_IOCIOC2IOCREFSEND_N
      Precondition ensures that the pointer is valid. The compliance of the precondition is check during review.

\CM CM_OS_IOC_SPINLOCK_M
      Verify that the Spinlock pointer of each IOC, that's LockMode is set to OS_IOCLOCKMODE_SPINLOCKS or
      OS_IOCLOCKMODE_ALL, is no NULL_PTR.

\CM CM_OS_IOCWRITE_COPYCBK_M
      Verify that the CopyCbk pointer of each Os_IocWriteConfigType object is initialized with a non NULL_PTR.

\CM CM_OS_IOCREAD_COPYCBK_M
      Verify that the CopyCbk pointer of each Os_IocReadConfigType object is initialized with a non NULL_PTR.

\CM CM_OS_IOCWRITE_INITCBK_R
      Implementation ensures, that InitCbk is a non NULL_PTR.

\CM CM_OS_IOCWRITE_DATA_M
      Verify that the Data pointer of each Os_IocWriteConfigType object is initialized with a non NULL_PTR.

\CM CM_OS_IOCREAD_DATA_M
      Verify that the Data pointer of each Os_IocReadConfigType object is initialized with a non NULL_PTR.

\CM CM_OS_IOCCALLBACKSCONFIG_CALLBACKREFS_01_02_M
      Verify that
       1. the callback list of each Os_IocCallbacksConfigType object is a non NULL_PTR if the callback count as not
          zero
       2. and the number of entries in each Os_IocCallbackConfigRefType is equal to CallbackCount.

\CM CM_OS_IOCCALLBACKSCONFIG_CALLBACKREFS_02_02_R
      Runtime check ensures that the index is in a valid range.
 */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Ioc.c
 **********************************************************************************************************************/
