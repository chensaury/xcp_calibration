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
 *  \defgroup    Os_Ioc Inter-OS-Application Communicator
 *  \file        Os_IocInt.h
 *  \brief       The "IOC" is responsible for the communication between OS-Applications and in particular for the
 *               communication crossing core or memory protection boundaries.
 *  \details
 *  ###Wording
 *
 *   Wording       | Description
 *  -------------- | ----------------------------------------------------------------------------------------
 *   Queued        | FIFO channel between communication partners.
 *   Non queued    | Synonym for Single Buffer
 *   Single Buffer | Latest is best channel between communication partners.
 *   1:1           | 1 sender, 1 receiver
 *   N:1           | N sender, 1 receiver, group commands not supported
 *   N:M           | N sender, M receiver, group commands not supported, only non queued
 *   Client        | A sender.
 *   Server        | A receiver.
 *   Writer        | Sender of a non queued channel.
 *   Reader        | Receiver of a non queued channel.
 *   IOC channel   | Communication path from a sender to a receiver. Each queue is one channel
 *                 | (in queued communication).
 *
 *
 *
 *  ###1:1 (Single and Group Parameter)
 *  ####Queued
 *  A FIFO is used for communication. No locks are required. The sender first writes the data to the buffer and
 *  then the buffer is enqueued.
 *  ![Single Sender - Single Receiver, queued](Ioc_1to1_queued.png)
 *
 *  ####Non Queued
 *  The sender holds a buffer.
 *  When sending:
 *   - The sender gets a lock -- see later chapter for the required kind of lock.
 *   - The sender writes to the buffer.
 *   - The sender releases the lock.
 *
 *  Receiving is performed in the same way.
 *
 *  ![Single Writer - Single Reader, non queued](Ioc_1to1_unqueued.png)
 *
 *  ###N:1 (Single and Group Parameter)
 *  ####Queued -- user space
 *  This subchapter describes the queued multiple sender, single receiver communication in case of communication in
 *  user space memory.
 *  The configuration provides one queue per sending application. The receiver has one receiver queue per sending core.
 *  Each queue has the complete configured length. When receiving, the receiver starts iterating over all queues at a
 *  position which was stored in the previous receive. The receiver iterates until it finds a non empty queue and read
 *  the value from that queue. The receiver stores a start position for the next receive run which is identical to the
 *  last start position plus 1. The reception order of data sent from a single application equals the send order.
 *  The overall receive order may differ from the send order if all sending applications are considered.
 *
 *  ![Multiple Sender - Single Receiver, queued, user space](Ioc_Nto1_queued.png)
 *
 *  ####Queued -- OS space
 *
 *  This subchapter describes the queued multiple sender, single receiver communication in case of communication in
 *  user space memory.
 *  The configuration provides one central queue located in OS space. Therefore, the send/receive functions need
 *  to be performed in supervisor mode with full access rights to OS memory. The reception order of data globally
 *  equals the send order. Write accesses to the queue are serialized by means of sufficient locks.
 *
 *  ![Multiple Sender - Single Receiver, queued, OS space](Ioc_Nto1_queued_OsSpace.png)
  *
 *  ####Non Queued
 *  The configuration provides one write buffer.
 *
 *  When sending:
 *   - The sender gets a lock -- see later chapter for the required kind of lock,
 *   - writes the data to its buffer,
 *   - and releases the lock.
 *
 *  When receiving:
 *   - The receiver gets a lock -- see later chapter for the required kind of lock,
 *   - reads the data from the this buffer,
 *   - and releases the lock.
 *
 *  ![Multiple Writer - Single Reader, non queued](Ioc_Nto1_unqueued.png)
 *
 *  ###1:N (Single and Group Parameter)
 *  ####Queued
 *  Not supported.
 *
 *  ####Unqueued
 *  This case is equal to Multiple Sender and Single Receiver.
 *  \note Performance can be improved by using read/write spinlocks.
 *
 *
 *  ###N:M (Single and Group Parameter)
 *  ####Queued
 *  Not supported.
 *
 *  ####Non Queued
 *  This case is equal to Single Sender and Single Receiver.
 *
 *
 *  ###Determining the required lock type
 *   __NonQueued:__
 *   - If the data can be read/written atomically, no locks are necessary, else
 *      - If all sender and the receiver are located on different cores, no interrupt locking is required and vice
 *        versa.
 *      - If all sender and the receiver are located on the same core no spinlock is required and vice versa.
 *
 *   __Queued (one queue per sender 1:1 or N:1):__
 *   - No interrupt lock and no spinlocks are necessary as all sender and receivers are perfectly decoupled.
 *
 *   __Queued (one central queue):__
 *   - If all sender are located on different cores, no interrupt locking is required and vice versa.
 *   - If all sender are located on the same core no spinlock is required and vice versa.
 *
 *
 *  ###Implementation Details
 *  ####OS/Application Mode
 *  If all the following conditions are fulfilled, no switch to the privileged mode is required when using an IOC
 *  channel:
 *   - The applications are allowed to disable/enable interrupts (if interrupt locks required).
 *   - The applications have access to the spinlock (if spinlocks enabled).
 *   - The sender/writer application has write access to the send/write data of the IOC.
 *   - The receiver/reader application has write access to the receive/read data of the IOC.
 *   - The sender is allowed to activate the receiver callback.
 *
 *  In any other case the IOC data has to be accessed by using a trap into the OS.
 *
 *  ####API Generation
 *  APIs which always return IOC_E_OK are allowed to be generated as function like macros. Other APIs may be generated
 *  as static inline functions. Generation as standard function is always allowed.
 *
 *  ####Non Queued Function Generation
 *  If all IOC data is owned by the application, no locks are required and no callback is configured, the buffer data
 *  and the IOC API functions are completely generated. These function do not use any functionality provided by the OS.
 *  In any other case, default functions provided by the IOC module, are used.
 *
 *  ####Callbacks
 *  Receiver/Reader callbacks are implemented as hooks owned by the receiver application. They are activated by the
 *  sender. The callback name is derived from the IOC ID.: [IOC ID]_ReceivePullCallback
 *
 *  ###Service Protection Check
 *  IOC data is protected by access checks and/or by memory protection. Access checks are performed, if any of the
 *  following conditions matches:
 *   - the IOC has a callback configured
 *   - the IOC requires a lock (interrupt or spinlock)
 *   - or the IOC requires a trap (see \ref OS/Application Mode)
 *
 *  ###Files
 *  ####Os_Ioc.h
 *  Provides all standard functions for IOC.
 *
 *  ####Ioc.h
 *  Ioc.h contains generated interface definition. This file is directly included by the user and may not be included by
 *  any other OS header file. The generator maps each IOC API to a function provided by Os_IocInt.h.
 *  OS files may not be included by Ioc.h. Instead, any OS internal function used by an IOC interface has to
 *  be forward declared within a local function scope. The user has to configure the required include files which
 *  provide the used IOC types.
 *
 *  \trace CREQ-75, CREQ-848, CREQ-849, CREQ-850, CREQ-852, CREQ-851, CREQ-141
 *  \trace SPEC-63608, SPEC-63564, SPEC-63561, SPEC-63565, SPEC-63675
 *  \note  See also SWS_Os_00671
 *
 *  ###configuration structure
 *
 *  - IocCommunication
 *    - BufferLength
 *    - OS/Application Spinlock (defines whether the spinlock mapped by OS or by the application)
 *    - DataProperties
 *      - Index
 *      - InitValue
 *      - DataType
 *    - ReceiverProperties
 *      - Function/Macro/Inline
 *      - ReceiverPullCallback (reference to hook, assigned to the receiver application)
 *      - Application
 *      - Interrupt locks, possibilities:
 *        - Lock
 *        - None
 *        - Auto
 *      - Spinlock, possibilities:
 *        - Lock
 *        - None
 *        - Auto
 *    - SenderProperties
 *      - Function/Macro/Inline
 *      - ID
 *      - Application
 *      - Interrupt locks, possibilities:
 *        - Lock
 *        - None
 *        - Auto
 *      - Spinlock, possibilities:
 *        - Lock
 *        - None
 *        - Auto
 *
 *  Others:
 *  The decision whether a trap into the OS is required, is based on the access level of the accessing applications
 *  (privileged/non-privileged, access to read/write access to OS data).
 *
 *  Internal comment removed.
 *
 *
 *
 *
 *
 *
 *  \{
 *
 *  \brief       Provides a set of default functions which are used by the generated ones.
 *  \details     --no details--
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_IOCINT_H
# define OS_IOCINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Ioc_Types.h"

/* Os kernel module dependencies */
# include "Os_FifoInt.h"
# include "Os_Fifo08Int.h"
# include "Os_Fifo16Int.h"
# include "Os_Fifo32Int.h"
# include "Os_FifoRefInt.h"
# include "Os_Spinlock_Types.h"
# include "Os_Task_Types.h"
# include "Os_TaskInt.h"
# include "Os_HookInt.h"

/* Os hal dependencies */



/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/*! Type cast from Os_IocWriteConfigType to Os_IocConfigType by use of base element addressing. */
#define OS_IOC_CASTCONFIG_IOCWRITE_2_IOC(ioc)           (&((ioc).Ioc))                                                  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_IocReadConfigType to Os_IocConfigType by use of base element addressing. */
#define OS_IOC_CASTCONFIG_IOCREAD_2_IOC(ioc)            (&((ioc).Ioc))                                                  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_Ioc08ReceiveConfigType to Os_IocConfigType by use of base element addressing. */
#define OS_IOC_CASTCONFIG_IOC08RECEIVE_2_IOC(ioc)       (&((ioc).Ioc.Base))                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_Ioc16ReceiveConfigType to Os_IocConfigType by use of base element addressing. */
#define OS_IOC_CASTCONFIG_IOC16RECEIVE_2_IOC(ioc)       (&((ioc).Ioc.Base))                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_Ioc32ReceiveConfigType to Os_IocConfigType by use of base element addressing. */
#define OS_IOC_CASTCONFIG_IOC32RECEIVE_2_IOC(ioc)       (&((ioc).Ioc.Base))                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_IocRefReceiveConfigType to Os_IocConfigType by use of base element addressing. */
#define OS_IOC_CASTCONFIG_IOCREFRECEIVE_2_IOC(ioc)      (&((ioc).Ioc.Base))                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_Ioc08SendConfigType to Os_IocConfigType by use of base element addressing. */
#define OS_IOC_CASTCONFIG_IOC08SEND_2_IOC(ioc)          (&((ioc).Ioc.Base))                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_Ioc16SendConfigType to Os_IocConfigType by use of base element addressing. */
#define OS_IOC_CASTCONFIG_IOC16SEND_2_IOC(ioc)          (&((ioc).Ioc.Base))                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_Ioc32SendConfigType to Os_IocConfigType by use of base element addressing. */
#define OS_IOC_CASTCONFIG_IOC32SEND_2_IOC(ioc)          (&((ioc).Ioc.Base))                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_IocRefSendConfigType to Os_IocConfigType by use of base element addressing. */
#define OS_IOC_CASTCONFIG_IOCREFSEND_2_IOC(ioc)         (&((ioc).Ioc.Base))                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_Ioc08MultiReceiveConfigType to Os_IocConfigType by use of base element addressing. */
#define OS_IOC_CASTCONFIG_IOC08MULTIRECEIVE_2_IOC(ioc)  (&((ioc).Ioc.Base))                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_Ioc16MultiReceiveConfigType to Os_IocConfigType by use of base element addressing. */
#define OS_IOC_CASTCONFIG_IOC16MULTIRECEIVE_2_IOC(ioc)  (&((ioc).Ioc.Base))                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_Ioc32MultiReceiveConfigType to Os_IocConfigType by use of base element addressing. */
#define OS_IOC_CASTCONFIG_IOC32MULTIRECEIVE_2_IOC(ioc)  (&((ioc).Ioc.Base))                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_IocRefMultiReceiveConfigType to Os_IocConfigType by use of base element addressing. */
#define OS_IOC_CASTCONFIG_IOCREFMULTIRECEIVE_2_IOC(ioc) (&((ioc).Ioc.Base))                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_IocWriteType to Os_IocType by use of base element addressing. */
#define OS_IOC_CASTDYN_IOCWRITE_2_IOC(ioc)              (&((ioc).Ioc))                                                  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_IocReadType to Os_IocType by use of base element addressing. */
#define OS_IOC_CASTDYN_IOCREAD_2_IOC(ioc)               (&((ioc).Ioc))                                                  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_Ioc08ReceiveType to Os_IocType by use of base element addressing. */
#define OS_IOC_CASTDYN_IOC08RECEIVE_2_IOC(ioc)          (&((ioc).Ioc.Base))                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_Ioc16ReceiveType to Os_IocType by use of base element addressing. */
#define OS_IOC_CASTDYN_IOC16RECEIVE_2_IOC(ioc)          (&((ioc).Ioc.Base))                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_Ioc32ReceiveType to Os_IocType by use of base element addressing. */
#define OS_IOC_CASTDYN_IOC32RECEIVE_2_IOC(ioc)          (&((ioc).Ioc.Base))                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_IocRefReceiveType to Os_IocType by use of base element addressing. */
#define OS_IOC_CASTDYN_IOCREFRECEIVE_2_IOC(ioc)         (&((ioc).Ioc.Base))                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_Ioc08SendType to Os_IocType by use of base element addressing. */
#define OS_IOC_CASTDYN_IOC08SEND_2_IOC(ioc)             (&((ioc).Ioc.Base))                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_Ioc16SendType to Os_IocType by use of base element addressing. */
#define OS_IOC_CASTDYN_IOC16SEND_2_IOC(ioc)             (&((ioc).Ioc.Base))                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_Ioc32SendType to Os_IocType by use of base element addressing. */
#define OS_IOC_CASTDYN_IOC32SEND_2_IOC(ioc)             (&((ioc).Ioc.Base))                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_IocRefSendType to Os_IocType by use of base element addressing. */
#define OS_IOC_CASTDYN_IOCREFSEND_2_IOC(ioc)            (&((ioc).Ioc.Base))                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_Ioc08MultiReceiveType to Os_IocType by use of base element addressing. */
#define OS_IOC_CASTDYN_IOC08MULTIRECEIVE_2_IOC(ioc)     (&((ioc).Base))                                                 /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_Ioc16MultiReceiveType to Os_IocType by use of base element addressing. */
#define OS_IOC_CASTDYN_IOC16MULTIRECEIVE_2_IOC(ioc)     (&((ioc).Base))                                                 /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_Ioc32MultiReceiveType to Os_IocType by use of base element addressing. */
#define OS_IOC_CASTDYN_IOC32MULTIRECEIVE_2_IOC(ioc)     (&((ioc).Base))                                                 /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_IocRefMultiReceiveType to Os_IocType by use of base element addressing. */
#define OS_IOC_CASTDYN_IOCREFMULTIRECEIVE_2_IOC(ioc)    (&((ioc).Base))                                                 /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  IOC Generic
 **********************************************************************************************************************/

/*! Reference to an IOC callback. */
typedef P2CONST(Os_HookCallbackConfigType, AUTOMATIC, OS_CONST) Os_IocCallbackConfigRefType;

/*! The static data of a IOC callback. */
struct Os_IocCallbacksConfigType_Tag
{
  /*! The callbacks which are provided by the receivers. */
  P2CONST(Os_IocCallbackConfigRefType, AUTOMATIC, OS_CONST) CallbackRefs;

  /*! Number of callback references. */
  Os_HookIdType CallbackCount;
};


/*! Dynamic base type for all IOC configurations. */
struct Os_IocType_Tag
{
  /*! Defines whether the IOC may be used or not. */
  Os_IocChannelStateType State;
};


/*! Class type specifier */
typedef enum
{
  Ioc08Receive,      /*!< Sub class is Os_Ioc08Receive      */
  Ioc08MultiReceive, /*!< Sub class is Os_Ioc08MultiReceive */
  Ioc08Send,         /*!< Sub class is Os_Ioc08Send         */
  Ioc16Receive,      /*!< Sub class is Os_Ioc16Receive      */
  Ioc16MultiReceive, /*!< Sub class is Os_Ioc16MultiReceive */
  Ioc16Send,         /*!< Sub class is Os_Ioc16Send         */
  Ioc32Receive,      /*!< Sub class is Os_Ioc32Receive      */
  Ioc32MultiReceive, /*!< Sub class is Os_Ioc32MultiReceive */
  Ioc32Send,         /*!< Sub class is Os_Ioc32Send         */
  IocRefReceive,     /*!< Sub class is Os_IocRefReceive     */
  IocRefMultiReceive,/*!< Sub class is Os_IocRefMultiReceive */
  IocRefSend,        /*!< Sub class is Os_IocRefSend        */
  IocRead,           /*!< Sub class is Os_IocRead           */
  IocWrite           /*!< Sub class is Os_IocWrite          */
}Os_IocSubClassType;


/*! Static base type for all IOC configurations. */
struct Os_IocConfigType_Tag
{
  /*! \brief  The spinlock which is used to synchronize the IOC access.
   * \details If this pointer is a NULL_PTR, no spinlock is used. */
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock;

  /*! Defines the lock method which is required for accessing the IOC. */
  Os_IocLockModeType LockMode;

  /*! The dynamic IOC data. */
  P2VAR(Os_IocType volatile, AUTOMATIC, TYPEDEF) Dyn;

  /*! Information about sub class
   *  \details Used to unify initialization (see \ref Os_IocInit()). */
  Os_IocSubClassType SubClass;

  /*! Reference to applications which access this object. */
  Os_AppAccessMaskType AccessingApplications;
};


/*!  Generic dynamic receiver part of a queued IOC.
 *  \extends Os_IocType_Tag  */
struct Os_IocReceiveType_Tag
{
  /*! Generic data.
   * This attribute must come first! */
  Os_IocType Base;

  /*! \brief    State of the sender's lose counter, when the reception was triggered the last time.
   *  \details  Since only changes are of interest for the receiver, an overflow does not care. */
  Os_IocLostCounterType LostCounterSnapshot;
};


/*! Generic static receiver part of a queued IOC.
 *  \extends Os_IocConfigType_Tag */
struct Os_IocReceiveConfigType_Tag
{
  /*! \brief    Generic data.
   *  \details  This attribute must come first! */
  Os_IocConfigType Base;

  /*! The corresponding sender */
  P2CONST(Os_IocSendConfigType, AUTOMATIC, TYPEDEF) Send;
};


/*! Generic dynamic sender part of a queued IOC.
 *  \extends Os_IocType_Tag */
struct Os_IocSendType_Tag
{
  /*! \brief    Generic data.
   *  \details  This attribute must come first! */
  Os_IocType Base;

  /*! The number of lost elements on the last read access. */
  Os_IocLostCounterType LostCounter;
};


/*! Generic static sender part of a queued IOC.
 *  \extends Os_IocConfigType_Tag */
struct Os_IocSendConfigType_Tag
{
  /*! \brief    Generic data.
   *  \details  This attribute must come first! */
  Os_IocConfigType Base;

  /*! The receiver callbacks. */
  Os_IocCallbacksConfigType Callbacks;

  /*! The corresponding receiver */
  P2CONST(Os_IocReceiveConfigType, AUTOMATIC, TYPEDEF) Receive;
};


/*! \brief    IOC base class for multiple receive (N:1) communication.
 *  \details  This type is used only for IOCs which are mapped to the application.
 *  \extends  Os_IocType_Tag */
struct Os_IocMultiReceiveType_Tag
{
  /*! \brief    Generic data.
   *  \details  This attribute must come first! */
  Os_IocType Base;

  /*! The index of the IOC channel from which is received next. */
  Os_ObjIdxType NextReceiveChannel;
};


/*! \brief   IOC base class for multiple receive (N:1) communication.
 *  \details This type is used for IOCs which are mapped to the application.
 *  \extends Os_IocConfigType_Tag */
struct Os_IocMultiReceiveConfigType_Tag
{
  /*! \brief    Generic data.
   *  \details  This attribute must come first! */
  Os_IocConfigType Base;

  /*! The number of incoming channels. */
  Os_ObjIdxType ReceiveChannelCount;
};


/***********************************************************************************************************************
 *  IOC Queued uint8
 **********************************************************************************************************************/
/*! IOC for uint8 communication.
 *  \extends Os_IocReceiveType_Tag */
struct Os_Ioc08ReceiveType_Tag
{
  /*! \brief    Generic data.
   *  \details  This attribute must come first! */
  Os_IocReceiveType Ioc;

  /*! The incoming queue. */
  Os_Fifo08ReadType FifoRead;
};


/*! IOC for uint8 communication.
 *  \extends Os_IocReceiveConfigType_Tag */
struct Os_Ioc08ReceiveConfigType_Tag
{
  /*! \brief    Generic data.
   *  \details  This attribute must come first! */
  Os_IocReceiveConfigType Ioc;

  /*! The incoming queue. */
  Os_Fifo08ReadConfigType FifoRead;
};


/*! \brief  IOC for uint8 communication.
 *  \details This type is used for IOCs which are mapped to the application.
 *  \extends Os_IocMultiReceiveConfigType_Tag */
struct Os_Ioc08MultiReceiveConfigType_Tag
{
  /*! The base class */
  Os_IocMultiReceiveConfigType Ioc;

  /*! Generic data. */
  P2CONST(Os_Ioc08ReceiveConfigType, TYPEDEF, AUTOMATIC) Receivers;
};


/*! \brief  IOC for uint8 communication.
 *  \details This type ensures data locality.
 *  \extends Os_IocSendType_Tag */
struct Os_Ioc08SendType_Tag
{
  /*! Generic data.
   * This attribute must come first! */
  Os_IocSendType Ioc;

  /*! The incoming queue. */
  Os_Fifo08WriteType FifoWrite;
};


/*! IOC for uint8 communication.
 *  \extends Os_IocSendConfigType_Tag */
struct Os_Ioc08SendConfigType_Tag
{
  /*! Generic data.
   * This attribute must come first! */
  Os_IocSendConfigType Ioc;

  /*! The outgoing queue. */
  Os_Fifo08WriteConfigType FifoWrite;
};


/***********************************************************************************************************************
 *  IOC Queued uint16
 **********************************************************************************************************************/
/*! \brief  IOC for uint16 communication.
 *  \details This type ensures data locality.
 *  \extends Os_IocReceiveType_Tag */
struct Os_Ioc16ReceiveType_Tag
{
  /*! Generic data.
   * This attribute must come first! */
  Os_IocReceiveType Ioc;

  /*! The incoming queue. */
  Os_Fifo16ReadType FifoRead;
};


/*! IOC for uint16 communication.
 *  \extends Os_IocReceiveConfigType_Tag */
struct Os_Ioc16ReceiveConfigType_Tag
{
  /*! Generic data.
   * This attribute must come first! */
  Os_IocReceiveConfigType Ioc;

  /*! The incoming queue. */
  Os_Fifo16ReadConfigType FifoRead;
};


/*! \brief  IOC for uint16 communication.
 *  \extends Os_IocMultiReceiveConfigType_Tag
 *  \details This type is used for IOCs which are mapped to the application. */
struct Os_Ioc16MultiReceiveConfigType_Tag
{
  /*! The base class */
  Os_IocMultiReceiveConfigType Ioc;

  /*! Generic data. */
  P2CONST(Os_Ioc16ReceiveConfigType, TYPEDEF, AUTOMATIC) Receivers;
};


/*! \brief  IOC for uint16 communication.
 *  \details This type ensures data locality.
 *  \extends Os_IocSendType_Tag */
struct Os_Ioc16SendType_Tag
{
  /*! Generic data.
   * This attribute must come first! */
  Os_IocSendType Ioc;

  /*! The incoming queue. */
  Os_Fifo16WriteType FifoWrite;
};


/*! \brief    IOC for uint16 communication.
 *  \extends Os_IocSendConfigType_Tag */
struct Os_Ioc16SendConfigType_Tag
{
  /*! Generic data.
   * This attribute must come first! */
  Os_IocSendConfigType Ioc;

  /*! The outgoing queue. */
  Os_Fifo16WriteConfigType FifoWrite;
};


/***********************************************************************************************************************
 *  IOC Queued uint32
 **********************************************************************************************************************/
/*! \brief  IOC for uint32 communication.
 *  \details This type ensures data locality.
 *  \extends Os_IocReceiveType_Tag */
struct Os_Ioc32ReceiveType_Tag
{
  /*! Generic data.
   * This attribute must come first! */
  Os_IocReceiveType Ioc;

  /*! The incoming queue. */
  Os_Fifo32ReadType FifoRead;
};


/*! \brief    IOC for uint32 communication.
 *  \extends  Os_IocReceiveConfigType_Tag */
struct Os_Ioc32ReceiveConfigType_Tag
{
  /*! Generic data.
   * This attribute must come first! */
  Os_IocReceiveConfigType Ioc;

  /*! The incoming queue. */
  Os_Fifo32ReadConfigType FifoRead;
};


/*! \brief   IOC for uint32 communication.
 *  \extends Os_IocMultiReceiveConfigType_Tag
 *  \details This type is used for IOCs which are mapped to the application. */
struct Os_Ioc32MultiReceiveConfigType_Tag
{
  /*! The base class */
  Os_IocMultiReceiveConfigType Ioc;

  /*! Generic data. */
  P2CONST(Os_Ioc32ReceiveConfigType, TYPEDEF, AUTOMATIC) Receivers;
};


/*! \brief  IOC for uint32 communication.
 *  \details This type ensures data locality.
 *  \extends Os_IocSendType_Tag */
struct Os_Ioc32SendType_Tag
{
  /*! Generic data.
   * This attribute must come first! */
  Os_IocSendType Ioc;

  /*! The incoming queue. */
  Os_Fifo32WriteType FifoWrite;
};


/*! IOC for uint32 communication.
 *  \extends Os_IocSendConfigType_Tag */
struct Os_Ioc32SendConfigType_Tag
{
  /*! Generic data.
   * This attribute must come first! */
  Os_IocSendConfigType Ioc;

  /*! The outgoing queue. */
  Os_Fifo32WriteConfigType FifoWrite;
};


/***********************************************************************************************************************
 *  IOC Queued Ref
 **********************************************************************************************************************/
/*! \brief   IOC for Ref communication.
 *  \details This type ensures data locality.
 *  \extends Os_IocReceiveType_Tag */
struct Os_IocRefReceiveType_Tag
{
  /*! Generic data.
   * This attribute must come first! */
  Os_IocReceiveType Ioc;

  /*! The incoming queue. */
  Os_FifoRefReadType FifoRead;
};


/*! IOC for Ref communication.
 *  \extends Os_IocReceiveConfigType_Tag */
struct Os_IocRefReceiveConfigType_Tag
{
  /*! Generic data.
   * This attribute must come first! */
  Os_IocReceiveConfigType Ioc;

  /*! The incoming queue. */
  Os_FifoRefReadConfigType FifoRead;
};


/*! \brief   IOC for Ref communication.
 *  \extends Os_IocMultiReceiveConfigType_Tag
 *  \details This type is used for IOCs which are mapped to the application. */
struct Os_IocRefMultiReceiveConfigType_Tag
{
  /*! The base class */
  Os_IocMultiReceiveConfigType Ioc;

  /*! Generic data. */
  P2CONST(Os_IocRefReceiveConfigType, TYPEDEF, AUTOMATIC) Receivers;
};


/*! \brief   IOC for Ref communication.
 *  \details This type ensures data locality.
 *  \extends Os_IocSendType_Tag */
struct Os_IocRefSendType_Tag
{
  /*! Generic data.
   * This attribute must come first! */
  Os_IocSendType Ioc;

  /*! The incoming queue. */
  Os_FifoRefWriteType FifoWrite;
};


/*! IOC for Ref communication.
 *  \extends Os_IocSendConfigType_Tag */
struct Os_IocRefSendConfigType_Tag
{
  /*! Generic data.
   * This attribute must come first! */
  Os_IocSendConfigType Ioc;

  /*! The outgoing queue. */
  Os_FifoRefWriteConfigType FifoWrite;
};


/***********************************************************************************************************************
 *  IOC Single Buffer
 **********************************************************************************************************************/
/*! \brief Callback function type to copy data from one object to another.
 *  \details The copy operation is expected to be based on the correct data type.
 *
 *  \param[in]  Source  The pointer to read from.
 *  \param[out] Target  The pointer to write to.
 */
typedef P2FUNC(void, OS_CODE, Os_IocCopyCbk)
(
  P2CONST(void, AUTOMATIC, TYPEDEF) Source,
  P2VAR(void, AUTOMATIC, TYPEDEF) Target
);


/*! \brief Callback function type to initialize the data buffer.
 *  \details Each data property with initial value is directly copied to the data buffer.
 *
 *  \param[in]  Data  The pointer to the data buffer.
 */
typedef P2FUNC(void, OS_CODE, Os_IocInitCbk)
(
  P2VAR(void, AUTOMATIC, TYPEDEF) Data
);


/*! IOC for single buffered communication.
 *  \extends Os_IocType_Tag */
struct Os_IocReadType_Tag
{
  /*! Generic data.
   * This attribute must come first! */
  Os_IocType Ioc;
};


/*! IOC for single buffered communication.
 *  \extends Os_IocConfigType_Tag */
struct Os_IocReadConfigType_Tag
{
  /*! Generic data.
   * This attribute must come first! */
  Os_IocConfigType Ioc;

  /*! The data buffer. */
  P2CONST(void, TYPEDEF, AUTOMATIC) Data;

  /*! The callback function to copy data with the correct type. */
  Os_IocCopyCbk CopyCbk;
};


/*! IOC for single buffered communication.
 *  \extends Os_IocType_Tag */
struct Os_IocWriteType_Tag
{
  /*! Generic data.
   * This attribute must come first! */
  Os_IocType Ioc;
};


/*! IOC for single buffered communication.
 *  \extends Os_IocConfigType_Tag */
struct Os_IocWriteConfigType_Tag
{
  /*! Generic data.
   * This attribute must come first! */
  Os_IocConfigType Ioc;

  /*! The data buffer. */
  P2VAR(void, TYPEDEF, AUTOMATIC) Data;

  /*! The receiver callbacks. */
  Os_IocCallbacksConfigType Callbacks;

  /*! The callback function to copy data with the correct type. */
  Os_IocCopyCbk CopyCbk;

  /*! The callback function to initialize the data buffer. */
  Os_IocInitCbk InitCbk;
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
 *  Os_IocInit()
 **********************************************************************************************************************/
/*! \brief          Initializes an Os_IocConfigType object.
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
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IocInit,
(
  P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
));


/***********************************************************************************************************************
 *  Os_IocIsEnabled()
 **********************************************************************************************************************/
/*! \brief          Returns whether the IOC is enabled (!0) or not (0).
 *  \details        --no details--
 *
 *  \retval         0     IOC is disabled.
 *  \retval         !0    IOC is enabled.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_IocIsEnabled, (void));


/***********************************************************************************************************************
 *  Os_IocHasCallbacks
 **********************************************************************************************************************/
/*! \brief        Returns whether callbacks have been configured (!0) or not (0).
 *  \details      --no details--
 *
 *  \retval       0   No callbacks have been configured for any IOC in the system.
 *  \retval       !0  At least one callback has been configured for an IOC in the system.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_IocHasCallbacks,
(
  void
));


/***********************************************************************************************************************
 *  IOC uint8
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_Ioc08MultiReceive()
 **********************************************************************************************************************/
/*! \brief          Reads one item from the next IOC channel.
 *  \details        This function is also used for group communication.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *  \param[out]     Data       Data reference to be filled with the received data element. Parameter must not be NULL.
 *
 *  \retval         IOC_E_OK        Reading from the IOC succeeded.
 *  \retval         IOC_E_LOST_DATA The sender was unable to write all data to the IOC because of a buffer overflow.
 *  \retval         IOC_E_NO_DATA   The buffer is empty.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Depending on the lock type the caller has to synchronize the access to the given IOC object.
 *
 *  \trace          CREQ-160, CREQ-113
 *  \trace          SPEC-63625, SPEC-63687, SPEC-63662, SPEC-63676, SPEC-63648, SPEC-63617, SPEC-63626, SPEC-63670
 *  \trace          SPEC-63669, SPEC-63606, SPEC-63634, SPEC-63666
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Ioc08MultiReceive
(
  P2CONST(Os_Ioc08MultiReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(uint8, TYPEDEF, AUTOMATIC) Data
);


/***********************************************************************************************************************
 *  Os_Ioc08Receive()
 **********************************************************************************************************************/
/*! \brief          Reads one item from the IOC.
 *  \details        This function is also used for group communication.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *  \param[out]     Data       Data reference to be filled with the received data element. Parameter must not be NULL.
 *
 *  \retval         IOC_E_OK        Reading from the IOC succeeded.
 *  \retval         IOC_E_LOST_DATA The sender was unable to write all data to the IOC because of a buffer overflow.
 *  \retval         IOC_E_NO_DATA   The buffer is empty.
 *  \retval         IOC_E_NOK       The current application may not use this IOC function.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Depending on the lock type the caller has to synchronize the access to the given IOC object.
 *
 *  \trace          CREQ-160, CREQ-113
 *  \trace          SPEC-63625, SPEC-63687, SPEC-63662, SPEC-63676, SPEC-63648, SPEC-63617, SPEC-63626, SPEC-63670
 *  \trace          SPEC-63669, SPEC-63606, SPEC-63634, SPEC-63666
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Ioc08Receive
(
  P2CONST(Os_Ioc08ReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(uint8, TYPEDEF, AUTOMATIC) Data
);


/***********************************************************************************************************************
 *  Os_Ioc08EmptyQueue()
 **********************************************************************************************************************/
/*! \brief          Empties the queue from the receiver side.
 *  \details        --no details--
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *
 *  \retval         IOC_E_OK     Operations succeeded.
 *  \retval         IOC_E_NOK    The current application may not use this IOC function.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Depending on the lock type the caller has to synchronize the access to the given IOC object.
 *
 *  \trace          CREQ-128
 *  \trace          SPEC-63578, SPEC-63673, SPEC-63566
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Ioc08EmptyQueue
(
  P2CONST(Os_Ioc08ReceiveConfigType, TYPEDEF, OS_CONST) Ioc
);


/***********************************************************************************************************************
 *  Os_Ioc08EmptyMultiQueue()
 **********************************************************************************************************************/
/*! \brief          Empties the queues from the receiver side.
 *  \details        --no details--
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *
 *  \retval         IOC_E_OK     Operations succeeded.
 *  \retval         IOC_E_NOK       The current application may not use this IOC function.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Depending on the lock type the caller has to synchronize the access to the given IOC object.
 *
 *  \trace          CREQ-128
 *  \trace          SPEC-63578, SPEC-63673, SPEC-63566
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Ioc08EmptyMultiQueue
(
  P2CONST(Os_Ioc08MultiReceiveConfigType, TYPEDEF, OS_CONST) Ioc
);


/***********************************************************************************************************************
 *  Os_Ioc08Send()
 **********************************************************************************************************************/
/*! \brief          Writes one item to the IOC.
 *  \details        This function is also used for group communication.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *  \param[in]      Data       The data to write to the IOC.
 *
 *  \retval         IOC_E_OK        Writing to the IOC succeeded.
 *  \retval         IOC_E_LIMIT     The sender was unable to write all data to the IOC because of a buffer overflow.
 *  \retval         IOC_E_NOK       The current application may not use this IOC function or at least one of the
 *                                  callbacks is not successfully triggered.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Depending on the lock type the caller has to synchronize the access to the given IOC object.
 *
 *  \trace          CREQ-91, CREQ-119
 *  \trace          SPEC-63620, SPEC-63598, SPEC-63613, SPEC-63658, SPEC-63588, SPEC-63645, SPEC-63671, SPEC-63590
 *  \trace          SPEC-63635, SPEC-63595, SPEC-63605, SPEC-63660, SPEC-63691, SPEC-63689, SPEC-63601
 *  \trace          SPEC-63615, SPEC-63657, SPEC-63597, SPEC-63684, SPEC-2566498, SPEC-63575, SPEC-63655
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Ioc08Send
(
  P2CONST(Os_Ioc08SendConfigType, TYPEDEF, OS_CONST) Ioc,
  uint8 Data
);


/***********************************************************************************************************************
 *  IOC uint16
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  Os_Ioc16MultiReceive()
 **********************************************************************************************************************/
/*! \brief          Reads one item from the next IOC channel.
 *  \details        This function is also used for group communication.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *  \param[out]     Data       Data reference to be filled with the received data element.
 *                             Parameter must not be NULL.
 *
 *  \retval         IOC_E_OK        Reading from the IOC succeeded.
 *  \retval         IOC_E_LOST_DATA The sender was unable to write all data to the IOC because of a buffer overflow.
 *  \retval         IOC_E_NO_DATA   The buffer is empty.
 *  \retval         IOC_E_NOK       The current application may not use this IOC function.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Depending on the lock type the caller has to synchronize the access to the given IOC object.
 *
 *  \trace          CREQ-160, CREQ-113
 *  \trace          SPEC-63625, SPEC-63687, SPEC-63662, SPEC-63676, SPEC-63648, SPEC-63617, SPEC-63626, SPEC-63670
 *  \trace          SPEC-63669, SPEC-63606, SPEC-63634, SPEC-63666
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Ioc16MultiReceive
(
  P2CONST(Os_Ioc16MultiReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(uint16, TYPEDEF, AUTOMATIC) Data
);


/***********************************************************************************************************************
 *  Os_Ioc16Receive()
 **********************************************************************************************************************/
/*! \brief          Reads one item from the IOC.
 *  \details        This function is also used for group communication.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *  \param[out]     Data       Data reference to be filled with the received data element.
 *                             Parameter must not be NULL.
 *
 *  \retval         IOC_E_OK        Reading from the IOC succeeded.
 *  \retval         IOC_E_LOST_DATA The sender was unable to write all data to the IOC because of a buffer overflow.
 *  \retval         IOC_E_NO_DATA   The buffer is empty.
 *  \retval         IOC_E_NOK       The current application may not use this IOC function.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Depending on the lock type the caller has to synchronize the access to the given IOC object.
 *
 *  \trace          CREQ-160, CREQ-113
 *  \trace          SPEC-63625, SPEC-63687, SPEC-63662, SPEC-63676, SPEC-63648, SPEC-63617, SPEC-63626, SPEC-63670
 *  \trace          SPEC-63669, SPEC-63606, SPEC-63634, SPEC-63666
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Ioc16Receive
(
  P2CONST(Os_Ioc16ReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(uint16, TYPEDEF, AUTOMATIC) Data
);


/***********************************************************************************************************************
 *  Os_Ioc16EmptyQueue()
 **********************************************************************************************************************/
/*! \brief          Empties the queue from the receiver side.
 *  \details        This function is also used for group communication.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *
 *  \retval         IOC_E_OK        Operations succeeded.
 *  \retval         IOC_E_NOK       The current application may not use this IOC function.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Depending on the lock type the caller has to synchronize the access to the given IOC object.
 *
 *  \trace          CREQ-128
 *  \trace          SPEC-63578, SPEC-63566, SPEC-63573
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Ioc16EmptyQueue
(
  P2CONST(Os_Ioc16ReceiveConfigType, TYPEDEF, OS_CONST) Ioc
);


/***********************************************************************************************************************
 *  Os_Ioc16EmptyMultiQueue()
 **********************************************************************************************************************/
/*! \brief          Empties the queues from the receiver side.
 *  \details        This function is also used for group communication.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *
 *  \retval         IOC_E_OK        Operations succeeded.
 *  \retval         IOC_E_NOK       The current application may not use this IOC function.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Depending on the lock type the caller has to synchronize the access to the given IOC object.
 *
 *  \trace          CREQ-128
 *  \trace          SPEC-63578, SPEC-63566, SPEC-63573
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Ioc16EmptyMultiQueue
(
  P2CONST(Os_Ioc16MultiReceiveConfigType, TYPEDEF, OS_CONST) Ioc
);


/***********************************************************************************************************************
 *  Os_Ioc16Send()
 **********************************************************************************************************************/
/*! \brief          Writes one item to the IOC.
 *  \details        This function is also used for group communication.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *  \param[in]      Data       The data to write to the IOC.
 *
 *  \retval         IOC_E_OK        Writing to the IOC succeeded.
 *  \retval         IOC_E_LIMIT     The sender was unable to write all data to the IOC because of a buffer overflow.
 *  \retval         IOC_E_NOK       The current application may not use this IOC function or at least one of the
 *                                  callbacks is not successfully triggered.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Depending on the lock type the caller has to synchronize the access to the given IOC object.
 *
 *  \trace          CREQ-91, CREQ-119
 *  \trace          SPEC-63620, SPEC-63598, SPEC-63613, SPEC-63658, SPEC-63588, SPEC-63645, SPEC-63671, SPEC-63590
 *  \trace          SPEC-63635, SPEC-63595, SPEC-63605, SPEC-63660, SPEC-63691, SPEC-63689, SPEC-63601
 *  \trace          SPEC-63615, SPEC-63657, SPEC-63597, SPEC-63684, SPEC-2566498, SPEC-63575, SPEC-63655
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Ioc16Send
(
  P2CONST(Os_Ioc16SendConfigType, TYPEDEF, OS_CONST) Ioc,
  uint16 Data
);


/***********************************************************************************************************************
 *  IOC uint32
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  Os_Ioc32MultiReceive()
 **********************************************************************************************************************/
/*! \brief          Reads one item from the next IOC channel.
 *  \details        This function is also used for group communication.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *  \param[out]     Data       Data reference to be filled with the received data element. Parameter must not be NULL.
 *
 *  \retval         IOC_E_OK        Reading from the IOC succeeded.
 *  \retval         IOC_E_LOST_DATA The sender was unable to write all data to the IOC because of a buffer overflow.
 *  \retval         IOC_E_NO_DATA   The buffer is empty.
 *  \retval         IOC_E_NOK       The current application may not use this IOC function.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Depending on the lock type the caller has to synchronize the access to the given IOC object.
 *
 *  \trace          CREQ-160, CREQ-113
 *  \trace          SPEC-63625, SPEC-63687, SPEC-63662, SPEC-63676, SPEC-63648, SPEC-63617, SPEC-63626, SPEC-63670
 *  \trace          SPEC-63669, SPEC-63606, SPEC-63634, SPEC-63666
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Ioc32MultiReceive
(
  P2CONST(Os_Ioc32MultiReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(uint32, TYPEDEF, AUTOMATIC) Data
);


/***********************************************************************************************************************
 *  Os_Ioc32Receive()
 **********************************************************************************************************************/
/*! \brief          Reads one item from the IOC.
 *  \details        This function is also used for group communication.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *  \param[out]     Data       Data reference to be filled with the received data element. Parameter must not be NULL.
 *
 *  \retval         IOC_E_OK        Reading from the IOC succeeded.
 *  \retval         IOC_E_LOST_DATA The sender was unable to write all data to the IOC because of a buffer overflow.
 *  \retval         IOC_E_NO_DATA   The buffer is empty.
 *  \retval         IOC_E_NOK       The current application may not use this IOC function.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Depending on the lock type the caller has to synchronize the access to the given IOC object.
 *
 *  \trace          CREQ-160, CREQ-113
 *  \trace          SPEC-63625, SPEC-63687, SPEC-63662, SPEC-63676, SPEC-63648, SPEC-63617, SPEC-63626, SPEC-63670
 *  \trace          SPEC-63669, SPEC-63606, SPEC-63634, SPEC-63666
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Ioc32Receive
(
  P2CONST(Os_Ioc32ReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(uint32, TYPEDEF, AUTOMATIC) Data
);


/***********************************************************************************************************************
 *  Os_Ioc32EmptyQueue()
 **********************************************************************************************************************/
/*! \brief          Empties the queue from the receiver side.
 *  \details        --no details--
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *
 *  \retval         IOC_E_OK     Operations succeeded.
 *  \retval         IOC_E_NOK       The current application may not use this IOC function.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Depending on the lock type the caller has to synchronize the access to the given IOC object.
 *
 *  \trace          CREQ-128
 *  \trace          SPEC-63578, SPEC-63566, SPEC-63573
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Ioc32EmptyQueue
(
  P2CONST(Os_Ioc32ReceiveConfigType, TYPEDEF, OS_CONST) Ioc
);


/***********************************************************************************************************************
 *  Os_Ioc32EmptyMultiQueue()
 **********************************************************************************************************************/
/*! \brief          Empties the queues from the receiver side.
 *  \details        --no details--
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *
 *  \retval         IOC_E_OK     Operations succeeded.
 *  \retval         IOC_E_NOK       The current application may not use this IOC function.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Depending on the lock type the caller has to synchronize the access to the given IOC object.
 *
 *  \trace          CREQ-128
 *  \trace          SPEC-63578, SPEC-63566, SPEC-63573
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Ioc32EmptyMultiQueue
(
  P2CONST(Os_Ioc32MultiReceiveConfigType, TYPEDEF, OS_CONST) Ioc
);


/***********************************************************************************************************************
 *  Os_Ioc32Send()
 **********************************************************************************************************************/
/*! \brief          Writes one item to the IOC.
 *  \details        This function is also used for group communication.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *  \param[in]      Data       The data to write to the IOC.
 *
 *  \retval         IOC_E_OK        Writing to the IOC succeeded.
 *  \retval         IOC_E_LIMIT     The sender was unable to write all data to the IOC because of a buffer overflow.
 *  \retval         IOC_E_NOK       The current application may not use this IOC function or at least one of the
 *                                  callbacks is not successfully triggered.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Depending on the lock type the caller has to synchronize the access to the given IOC object.
 *
 *  \trace          CREQ-91, CREQ-119
 *  \trace          SPEC-63620, SPEC-63598, SPEC-63613, SPEC-63658, SPEC-63588, SPEC-63645, SPEC-63671, SPEC-63590
 *  \trace          SPEC-63635, SPEC-63595, SPEC-63605, SPEC-63660, SPEC-63691, SPEC-63689, SPEC-63601
 *  \trace          SPEC-63615, SPEC-63657, SPEC-63597, SPEC-63684, SPEC-2566498, SPEC-63575, SPEC-63655
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_Ioc32Send
(
  P2CONST(Os_Ioc32SendConfigType, TYPEDEF, OS_CONST) Ioc,
  uint32 Data
);


/***********************************************************************************************************************
 *  IOC Ref
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  Os_IocRefMultiReceive()
 **********************************************************************************************************************/
/*! \brief          Reads one item from the next IOC channel.
 *  \details        This function is also used for group communication.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *  \param[out]     Data       Data reference to be filled with the received data element. Parameter must not be NULL.
 *
 *  \retval         IOC_E_OK        Reading from the IOC succeeded.
 *  \retval         IOC_E_LOST_DATA The sender was unable to write all data to the IOC because of a buffer overflow.
 *  \retval         IOC_E_NO_DATA   The buffer is empty.
 *  \retval         IOC_E_NOK       The current application may not use this IOC function.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Depending on the lock type the caller has to synchronize the access to the given IOC object.
 *
 *  \trace          CREQ-160, CREQ-113
 *  \trace          SPEC-63625, SPEC-63687, SPEC-63662, SPEC-63676, SPEC-63648, SPEC-63617, SPEC-63626, SPEC-63670
 *  \trace          SPEC-63669, SPEC-63606, SPEC-63634, SPEC-63666
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_IocRefMultiReceive
(
  P2CONST(Os_IocRefMultiReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(void, TYPEDEF, AUTOMATIC) Data
);


/***********************************************************************************************************************
 *  Os_IocRefReceive()
 **********************************************************************************************************************/
/*! \brief          Reads one item from the IOC.
 *  \details        This function is also used for group communication.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *  \param[out]     Data       Data reference to be filled with the received data element. Parameter must not be NULL.
 *
 *  \retval         IOC_E_OK        Reading from the IOC succeeded.
 *  \retval         IOC_E_LOST_DATA The sender was unable to write all data to the IOC because of a buffer overflow.
 *  \retval         IOC_E_NO_DATA   The buffer is empty.
 *  \retval         IOC_E_NOK       The current application may not use this IOC function.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Depending on the lock type the caller has to synchronize the access to the given IOC object.
 *
 *  \trace          CREQ-160, CREQ-113
 *  \trace          SPEC-63625, SPEC-63687, SPEC-63662, SPEC-63676, SPEC-63648, SPEC-63617, SPEC-63626, SPEC-63670
 *  \trace          SPEC-63669, SPEC-63606, SPEC-63634, SPEC-63666
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_IocRefReceive
(
  P2CONST(Os_IocRefReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(void, TYPEDEF, AUTOMATIC) Data
);


/***********************************************************************************************************************
 *  Os_IocRefEmptyQueue()
 **********************************************************************************************************************/
/*! \brief          Empties the queue from the receiver side.
 *  \details        --no details--
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *
 *  \retval         IOC_E_OK     Operations succeeded.
 *  \retval         IOC_E_NOK       The current application may not use this IOC function.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Depending on the lock type the caller has to synchronize the access to the given IOC object.
 *
 *  \trace          CREQ-128
 *  \trace          SPEC-63578, SPEC-63566, SPEC-63573
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_IocRefEmptyQueue
(
  P2CONST(Os_IocRefReceiveConfigType, TYPEDEF, OS_CONST) Ioc
);


/***********************************************************************************************************************
 *  Os_IocRefEmptyMultiQueue()
 **********************************************************************************************************************/
/*! \brief          Empties the queues from the receiver side.
 *  \details        --no details--
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *
 *  \retval         IOC_E_OK     Operations succeeded.
 *  \retval         IOC_E_NOK       The current application may not use this IOC function.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Depending on the lock type the caller has to synchronize the access to the given IOC object.
 *
 *  \trace          CREQ-128
 *  \trace          SPEC-63578, SPEC-63566, SPEC-63573
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_IocRefEmptyMultiQueue
(
  P2CONST(Os_IocRefMultiReceiveConfigType, TYPEDEF, OS_CONST) Ioc
);


/***********************************************************************************************************************
 *  Os_IocRefSend()
 **********************************************************************************************************************/
/*! \brief          Writes one item to the IOC.
 *  \details        This function is also used for group communication.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *  \param[in]      Data       The data to write to the IOC. Parameter must not be NULL.
 *
 *  \retval         IOC_E_OK        Writing to the IOC succeeded.
 *  \retval         IOC_E_LIMIT     The sender was unable to write all data to the IOC because of a buffer overflow.
 *  \retval         IOC_E_NOK       The current application may not use this IOC function or at least one of the
 *                                  callbacks is not successfully triggered.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Depending on the lock type the caller has to synchronize the access to the given IOC object.
 *
 *  \trace          CREQ-91, CREQ-119
 *  \trace          SPEC-63620, SPEC-63598, SPEC-63613, SPEC-63658, SPEC-63588, SPEC-63645, SPEC-63671, SPEC-63590
 *  \trace          SPEC-63635, SPEC-63595, SPEC-63605, SPEC-63660, SPEC-63691, SPEC-63689, SPEC-63601
 *  \trace          SPEC-63615, SPEC-63657, SPEC-63597, SPEC-63684, SPEC-2566498, SPEC-63575, SPEC-63655, SPEC-63663
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_IocRefSend
(
  P2CONST(Os_IocRefSendConfigType, TYPEDEF, OS_CONST) Ioc,
  P2CONST(void, TYPEDEF, AUTOMATIC) Data
);


/***********************************************************************************************************************
 *  IOC Single Buffer
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  Os_IocRead()
 **********************************************************************************************************************/
/*! \brief          Reads one item from the IOC.
 *  \details        This function is also used for group communication.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *  \param[out]     Data       Data reference to be filled with the received data element. Parameter must not be NULL.
 *
 *  \retval         IOC_E_OK        Reading from the IOC succeeded.
 *  \retval         IOC_E_NOK       The current application may not use this IOC function.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Depending on the lock type the caller has to synchronize the access to the given IOC object.
 *
 *  \trace          CREQ-147, CREQ-55
 *  \trace          SPEC-63648, SPEC-63617, SPEC-63626, SPEC-63670, SPEC-63641, SPEC-2458899
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_IocRead
(
  P2CONST(Os_IocReadConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(void, TYPEDEF, AUTOMATIC) Data
);


/***********************************************************************************************************************
 *  Os_IocWrite()
 **********************************************************************************************************************/
/*! \brief          Writes one item to the IOC.
 *  \details        This function is also used for group communication.
 *
 *  \param[in,out]  Ioc        IOC to query. Parameter must not be NULL.
 *  \param[in]      Data       The to write to the IOC. Parameter must not be NULL.
 *
 *  \retval         IOC_E_OK        Writing to the IOC succeeded.
 *  \retval         IOC_E_NOK       The current application may not use this IOC function or at least one of the
 *                                  callbacks is not successfully triggered.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Depending on the lock type the caller has to synchronize the access to the given IOC object.
 *
 *  \trace          CREQ-150, CREQ-90
 *  \trace          SPEC-63620, SPEC-63598, SPEC-63613, SPEC-63658, SPEC-63588, SPEC-63645, SPEC-63671, SPEC-63605
 *  \trace          SPEC-63660, SPEC-63691, SPEC-63689, SPEC-63601, SPEC-63615, SPEC-63657, SPEC-63597
 *  \trace          SPEC-63684, SPEC-63575
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_IocWrite
(
  P2CONST(Os_IocWriteConfigType, TYPEDEF, OS_CONST) Ioc,
  P2CONST(void, TYPEDEF, AUTOMATIC) Data
);


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */



#endif /* OS_IOCINT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_IocInt.h
 **********************************************************************************************************************/
