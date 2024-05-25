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
 *  \defgroup    Os_Trap Trap
 *  \brief       Handles supervisor mode entries.
 *  \details
 *  This module provides the OS API to the user. It is also responsible to get access to data and peripherals
 *  needed to execute OS services.
 *
 *  The following cases are differentiated by the trap module:
 *
 *   - Memory protection disabled: All APIs are called directly from the trap module.
 *   - Memory protection enabled:
 *     - Regular APIs which need write access to OS data check whether the caller is privileged:
 *       - Privileged caller: Direct call to API.
 *       - Non-Privileged caller: Call API via trap.
 *     - APIs which do not need write access to OS data call the API directly.
 *     - APIs which have out-parameters use local variables to protect the OS from invalid user-pointers.
 *       The write operation to the original pointer is performed in the trap function with caller's privilege level.
 *     - APIs which are always called in privileged mode (e.g. Os_DisableLevelKM()) directly call the API.
 *     - APIs which are expected to be called in non-privileged mode (e.g. Os_WritePeripheral8())
 *       call the API via trap.
 *
 *  ![Service Call - No Memory Protection](Trap_NoMemoryProtection.png)
 *
 *  ![Service Call - Memory Protection](Trap_MemoryProtection.png)
 *
 *  ![Service Call - Memory Protection For Trusted](Trap_MemoryProtectionForTrusted.png)
 *
 *
 *
 *
 *
 *  \{
 *
 *  \file
 *  \brief       Internal Trap API declaration.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_TRAPINT_H
# define OS_TRAPINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Trap_Types.h"

/* Os module dependencies */
# include "Os_Spinlock_Types.h"
# include "Os_Ioc_Types.h"
# include "Os_ErrorInt.h"
# include "Os_KernelInt.h"

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
/*! Trap vector service ID. */
typedef enum
{
  OS_TRAPID_GETCOREID,
  OS_TRAPID_GETACTIVEAPPLICATIONMODE,
  OS_TRAPID_SHUTDOWNOS,
  OS_TRAPID_SHUTDOWNALLCORES,
  OS_TRAPID_DISABLELEVEL,
  OS_TRAPID_ENABLELEVEL,
  OS_TRAPID_DISABLEGLOBAL,
  OS_TRAPID_ENABLEGLOBAL,
  OS_TRAPID_DISABLEALLINTERRUPTS,
  OS_TRAPID_ENABLEALLINTERRUPTS,
  OS_TRAPID_SUSPENDALLINTERRUPTS,
  OS_TRAPID_RESUMEALLINTERRUPTS,
  OS_TRAPID_SUSPENDOSINTERRUPTS,
  OS_TRAPID_RESUMEOSINTERRUPTS,
  OS_TRAPID_DISABLEINTERRUPTSOURCE,
  OS_TRAPID_ENABLEINTERRUPTSOURCE,
  OS_TRAPID_CLEARPENDINGINTERRUPT,
  OS_TRAPID_ISINTERRUPTSOURCEENABLED,
  OS_TRAPID_ISINTERRUPTPENDING,
  OS_TRAPID_ALLOWACCESS,
  OS_TRAPID_GETAPPLICATIONID,
  OS_TRAPID_GETCURRENTAPPLICATIONID,
  OS_TRAPID_GETAPPLICATIONSTATE,
  OS_TRAPID_CHECKOBJECTACCESS,
  OS_TRAPID_CHECKOBJECTOWNERSHIP,
  OS_TRAPID_TERMINATEAPPLICATION,
  OS_TRAPID_ACTIVATETASK,
  OS_TRAPID_TERMINATETASK,
  OS_TRAPID_CHAINTASK,
  OS_TRAPID_GETTASKSTATE,
  OS_TRAPID_GETTASKID,
  OS_TRAPID_GETISRID,
  OS_TRAPID_SCHEDULE,
  OS_TRAPID_INCREMENTCOUNTER,
  OS_TRAPID_GETCOUNTERVALUE,
  OS_TRAPID_GETELAPSEDVALUE,
  OS_TRAPID_GETALARM,
  OS_TRAPID_GETALARMBASE,
  OS_TRAPID_SETRELALARM,
  OS_TRAPID_SETABSALARM,
  OS_TRAPID_CANCELALARM,
  OS_TRAPID_GETRESOURCE,
  OS_TRAPID_RELEASERESOURCE,
  OS_TRAPID_SETEVENT,
  OS_TRAPID_CLEAREVENT,
  OS_TRAPID_WAITEVENT,
  OS_TRAPID_GETEVENT,
  OS_TRAPID_STARTSCHEDULETABLEREL,
  OS_TRAPID_STARTSCHEDULETABLEABS,
  OS_TRAPID_STOPSCHEDULETABLE,
  OS_TRAPID_NEXTSCHEDULETABLE,
  OS_TRAPID_STARTSCHEDULETABLESYNCHRON,
  OS_TRAPID_SETSCHEDULETABLEASYNC,
  OS_TRAPID_SYNCSCHEDULETABLE,
  OS_TRAPID_GETSCHEDULETABLESTATUS,
  OS_TRAPID_SPINLOCKGET,
  OS_TRAPID_SPINLOCKRELEASE,
  OS_TRAPID_SPINLOCKTRYGET,
  OS_TRAPID_IOC08RECEIVE,
  OS_TRAPID_IOC08EMPTYQUEUE,
  OS_TRAPID_IOC08SEND,
  OS_TRAPID_IOC16RECEIVE,
  OS_TRAPID_IOC16EMPTYQUEUE,
  OS_TRAPID_IOC16SEND,
  OS_TRAPID_IOC32RECEIVE,
  OS_TRAPID_IOC32EMPTYQUEUE,
  OS_TRAPID_IOC32SEND,
  OS_TRAPID_IOCREFRECEIVE,
  OS_TRAPID_IOCREFEMPTYQUEUE,
  OS_TRAPID_IOCREFSEND,
  OS_TRAPID_IOCREAD,
  OS_TRAPID_IOCWRITE,
  OS_TRAPID_IOC08MULTIRECEIVE,
  OS_TRAPID_IOC08EMPTYMULTIQUEUE,
  OS_TRAPID_IOC16MULTIRECEIVE,
  OS_TRAPID_IOC16EMPTYMULTIQUEUE,
  OS_TRAPID_IOC32MULTIRECEIVE,
  OS_TRAPID_IOC32EMPTYMULTIQUEUE,
  OS_TRAPID_IOCREFMULTIRECEIVE,
  OS_TRAPID_IOCREFEMPTYMULTIQUEUE,
  OS_TRAPID_READPERIPHERAL8,
  OS_TRAPID_READPERIPHERAL16,
  OS_TRAPID_READPERIPHERAL32,
  OS_TRAPID_WRITEPERIPHERAL8,
  OS_TRAPID_WRITEPERIPHERAL16,
  OS_TRAPID_WRITEPERIPHERAL32,
  OS_TRAPID_MODIFYPERIPHERAL8,
  OS_TRAPID_MODIFYPERIPHERAL16,
  OS_TRAPID_MODIFYPERIPHERAL32,
  OS_TRAPID_CALLTRUSTEDFUNCTION,
  OS_TRAPID_CALLNONTRUSTEDFUNCTION,
  OS_TRAPID_CALLFASTTRUSTEDFUNCTION,
  OS_TRAPID_ERRAPPLICATIONERROR,
  OS_TRAPID_TASKMISSINGTERMINATETASK,
  OS_TRAPID_ISREPILOGUE,
  OS_TRAPID_SERVICERETURN,
  OS_TRAPID_HOOKRETURN,
  OS_TRAPID_CONTROLIDLE,
  OS_TRAPID_GETTASKSTACKUSAGE,
  OS_TRAPID_GETISRSTACKUSAGE,
  OS_TRAPID_GETKERNELSTACKUSAGE,
  OS_TRAPID_GETSTARTUPHOOKSTACKUSAGE,
  OS_TRAPID_GETERRORHOOKSTACKUSAGE,
  OS_TRAPID_GETSHUTDOWNHOOKSTACKUSAGE,
  OS_TRAPID_GETPROTECTIONHOOKSTACKUSAGE,
  OS_TRAPID_GETUNHANDLEDIRQ,
  OS_TRAPID_GETUNHANDLEDEXC,
  OS_TRAPID_GETDETAILEDERROR,
  OS_TRAPID_GETSERVICEID,
  OS_TRAPID_COREGETTHREAD,
  OS_TRAPID_GETNUMBEROFACTIVATEDCORES,
  OS_TRAPID_CHECKTASKMEMORYACCESS,
  OS_TRAPID_CHECKISRMEMORYACCESS,
  OS_TRAPID_BARRIERSYNCHRONIZE,
  OS_TRAPID_GETEXCEPTIONCONTEXT,
  OS_TRAPID_SETEXCEPTIONCONTEXT,
  OS_TRAPID_COUNT
} Os_TrapIdType;


/*! Identifies parameters within a API prototype. */
typedef enum
{
  OS_TRAPPARAMINDEX_1 = 0,
  OS_TRAPPARAMINDEX_2,
  OS_TRAPPARAMINDEX_3,
  OS_TRAPPARAMINDEX_4,
  OS_TRAPPARAMINDEX_COUNT
} Os_TrapParamIndexType;


/*! Union of all OS API parameter types. */
typedef union
{                                                                                                                       /* PRQA S 0750 */ /* MD_MSR_Union */
  Os_ParamType                                                  ParamApiType;
  P2CONST(Os_SpinlockConfigType, TYPEDEF, OS_CONST)             ParamSpinlockConfigRefType;
  P2CONST(Os_Ioc08SendConfigType, TYPEDEF, OS_CONST)            ParamIoc08SendConfigRefType;
  P2CONST(Os_Ioc08ReceiveConfigType, TYPEDEF, OS_CONST)         ParamIoc08ReceiveConfigRefType;
  P2VAR(uint8, TYPEDEF, AUTOMATIC)                              ParamUint8RefType;
  P2CONST(uint8, TYPEDEF, AUTOMATIC)                            ParamConstUint8RefType;
  uint8                                                         ParamUint8Type;
  P2CONST(Os_Ioc16SendConfigType, TYPEDEF, OS_CONST)            ParamIoc16SendConfigRefType;
  P2CONST(Os_Ioc16ReceiveConfigType, TYPEDEF, OS_CONST)         ParamIoc16ReceiveConfigRefType;
  P2VAR(uint16, TYPEDEF, AUTOMATIC)                             ParamUint16RefType;
  P2CONST(uint16, TYPEDEF, AUTOMATIC)                           ParamConstUint16RefType;
  uint16                                                        ParamUint16Type;
  P2CONST(Os_Ioc32SendConfigType, TYPEDEF, OS_CONST)            ParamIoc32SendConfigRefType;
  P2CONST(Os_Ioc32ReceiveConfigType, TYPEDEF, OS_CONST)         ParamIoc32ReceiveConfigRefType;
  P2VAR(uint32, TYPEDEF, AUTOMATIC)                             ParamUint32RefType;
  P2CONST(uint32, TYPEDEF, AUTOMATIC)                           ParamConstUint32RefType;
  uint32                                                        ParamUint32Type;
  P2CONST(Os_IocRefSendConfigType, TYPEDEF, OS_CONST)           ParamIocRefSendConfigRefType;
  P2CONST(Os_IocRefReceiveConfigType, TYPEDEF, OS_CONST)        ParamIocRefReceiveConfigRefType;
  P2VAR(void, TYPEDEF, AUTOMATIC)                               ParamVoidRefType;
  P2CONST(void, TYPEDEF, AUTOMATIC)                             ParamVoidConfigRefType;
  P2CONST(Os_IocReadConfigType, TYPEDEF, OS_CONST)              ParamIocReadConfigRefType;
  P2CONST(Os_IocWriteConfigType, TYPEDEF, OS_CONST)             ParamIocWriteConfigRefType;
  P2CONST(Os_Ioc08MultiReceiveConfigType, TYPEDEF, OS_CONST)    ParamIoc08MultiReceiveConfigRefType;
  P2CONST(Os_Ioc16MultiReceiveConfigType, TYPEDEF, OS_CONST)    ParamIoc16MultiReceiveConfigRefType;
  P2CONST(Os_Ioc32MultiReceiveConfigType, TYPEDEF, OS_CONST)    ParamIoc32MultiReceiveConfigRefType;
  P2CONST(Os_IocRefMultiReceiveConfigType, TYPEDEF, OS_CONST)   ParamIocRefMultiReceiveConfigRefType;
  OSServiceIdType                                               ParamOSServiceIdType;
  Os_StatusType                                                 ParamOs_StatusType;
  P2VAR(Os_ErrorParamsType, TYPEDEF, OS_VAR_NOINIT)             ParamOs_ErrorParamsRefType;
} Os_TrapParameterType;


/*! Union of all OS API return types. */
typedef union
{                                                                                                                       /* PRQA S 0750 */ /* MD_MSR_Union */
  Os_StatusType       ReturnOs_StatusType;
  Std_ReturnType      ReturnStd_ReturnType;
  uint8               ReturnUint8Type;
  uint16              ReturnUint16Type;
  uint32              ReturnUint32Type;
  CoreIdType          ReturnCoreIdType;
  AppModeType         ReturnAppModeType;
  ISRType             ReturnISRType;
  ApplicationType     ReturnApplicationType;
  ObjectAccessType    ReturnObjectAccessType;
  AccessType          ReturnAccessType;
  OSServiceIdType     ReturnOSServiceIdType;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST)   ReturnThreadConfigRefType;
} Os_TrapReturnType;



/*! Parameter packet to pass service data from user space to kernel's trap handler. */
struct Os_TrapPacketType_Tag
{
  /*! Service to be called. */
  Os_TrapIdType TrapId;

  /*! Parameters to be passed. */
  Os_TrapParameterType Parameters[OS_TRAPPARAMINDEX_COUNT];

  /*! Return value. */
  Os_TrapReturnType ReturnValue;
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
 *  Os_TrapSpinlockGet()
 **********************************************************************************************************************/
/*! \brief        OS service GetSpinlock().
 *  \details      For further details see Os_SpinlockGet().
 *
 *  \param[in]    Spinlock        See Os_SpinlockGet().
 *
 *  \return       See Os_SpinlockGet().
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See Os_SpinlockGet().
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_TrapSpinlockGet
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
);


/***********************************************************************************************************************
 *  Os_TrapSpinlockRelease()
 **********************************************************************************************************************/
/*! \brief        OS service ReleaseSpinlock().
 *  \details      For further details see Os_SpinlockRelease().
 *
 *  \param[in]    Spinlock        See Os_SpinlockRelease().
 *
 *  \return       See Os_SpinlockRelease().
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See Os_SpinlockRelease().
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_TrapSpinlockRelease
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
);


/***********************************************************************************************************************
 *  Os_TrapSpinlockTryGet()
 **********************************************************************************************************************/
/*! \brief        OS service TryGetSpinlock().
 *  \details      For further details see Os_SpinlockTryGet().
 *
 *  \param[in]    Spinlock        See Os_SpinlockTryGet().
 *  \param[out]   Success         See Os_SpinlockTryGet().
 *
 *  \return       See Os_SpinlockTryGet().
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See Os_SpinlockTryGet().
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_TrapSpinlockTryGet
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock,
  TryToGetSpinlockType* Success
);


/***********************************************************************************************************************
 *  Os_TrapIoc08Receive()
 **********************************************************************************************************************/
/*! \brief        Reads one item from the IOC.
 *  \details      For further details see Os_Ioc08Receive().
 *
 *  \param[in]      IsTrapRequired  Defines whether a trap is required:
 *                                   - TRUE:  Trap is always performed.
 *                                   - FALSE: Trap is performed, if supervisor mode is required by platform.
 *  \param[in,out]  Ioc             See Os_Ioc08Receive().
 *  \param[out]     Data            See Os_Ioc08Receive().
 *
 *  \return       See Os_Ioc08Receive().
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          See Os_Ioc08Receive().
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_TrapIoc08Receive
(
  boolean IsTrapRequired,
  P2CONST(Os_Ioc08ReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(uint8, TYPEDEF, AUTOMATIC) Data
);


/***********************************************************************************************************************
 *  Os_TrapIoc08EmptyQueue()
 **********************************************************************************************************************/
/*! \brief        Empties the queue from the receiver side.
 *  \details      --no details--
 *
 *  \param[in]      IsTrapRequired  Defines whether a trap is required:
 *                                   - TRUE:  Trap is always performed.
 *                                   - FALSE: Trap is performed, if supervisor mode is required by platform.
 *  \param[in,out]  Ioc             See Os_Ioc08EmptyQueue().
 *
 *  \return       See Os_Ioc08EmptyQueue().
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          See Os_Ioc08EmptyQueue().
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_TrapIoc08EmptyQueue
(
  boolean IsTrapRequired,
  P2CONST(Os_Ioc08ReceiveConfigType, TYPEDEF, OS_CONST) Ioc
);


/***********************************************************************************************************************
 *  Os_TrapIoc08Send()
 **********************************************************************************************************************/
/*! \brief        Writes one item to the IOC.
 *  \details      For further details see Os_Ioc08Send().
 *
 *  \param[in]      IsTrapRequired  Defines whether a trap is required:
 *                                   - TRUE:  Trap is always performed.
 *                                   - FALSE: Trap is performed, if supervisor mode is required by platform.
 *  \param[in,out]  Ioc             See Os_Ioc08Send().
 *  \param[in]      Data            See Os_Ioc08Send().
 *
 *  \return       See Os_Ioc08Send().
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          See Os_Ioc08Send().
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_TrapIoc08Send
(
  boolean IsTrapRequired,
  P2CONST(Os_Ioc08SendConfigType, TYPEDEF, OS_CONST) Ioc,
  uint8 Data
);


/***********************************************************************************************************************
 *  Os_TrapIoc16Receive()
 **********************************************************************************************************************/
/*! \brief        Reads one item from the IOC.
 *  \details      For further details see Os_Ioc16Receive().
 *
 *  \param[in]      IsTrapRequired  Defines whether a trap is required:
 *                                   - TRUE:  Trap is always performed.
 *                                   - FALSE: Trap is performed, if supervisor mode is required by platform.
 *  \param[in,out]  Ioc             See Os_Ioc16Receive().
 *  \param[out]     Data            See Os_Ioc16Receive().
 *
 *  \return       See Os_Ioc16Receive().
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          See Os_Ioc16Receive().
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_TrapIoc16Receive
(
  boolean IsTrapRequired,
  P2CONST(Os_Ioc16ReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(uint16, TYPEDEF, AUTOMATIC) Data
);


/***********************************************************************************************************************
 *  Os_TrapIoc16EmptyQueue()
 **********************************************************************************************************************/
/*! \brief        Empties the queue from the receiver side.
 *  \details      --no details--
 *
 *  \param[in]      IsTrapRequired  Defines whether a trap is required:
 *                                   - TRUE:  Trap is always performed.
 *                                   - FALSE: Trap is performed, if supervisor mode is required by platform.
 *  \param[in,out]  Ioc             See Os_Ioc16EmptyQueue().
 *
 *  \return       See Os_Ioc16EmptyQueue().
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          See Os_Ioc16EmptyQueue().
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_TrapIoc16EmptyQueue
(
  boolean IsTrapRequired,
  P2CONST(Os_Ioc16ReceiveConfigType, TYPEDEF, OS_CONST) Ioc
);


/***********************************************************************************************************************
 *  Os_TrapIoc16Send()
 **********************************************************************************************************************/
/*! \brief        Writes one item to the IOC.
 *  \details      For further details see Os_Ioc16Send().
 *
 *  \param[in]      IsTrapRequired  Defines whether a trap is required:
 *                                   - TRUE:  Trap is always performed.
 *                                   - FALSE: Trap is performed, if supervisor mode is required by platform.
 *  \param[in,out]  Ioc             See Os_Ioc16Send().
 *  \param[in]      Data            See Os_Ioc16Send().
 *
 *  \return       See Os_Ioc16Send().
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          See Os_Ioc16Send().
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_TrapIoc16Send
(
  boolean IsTrapRequired,
  P2CONST(Os_Ioc16SendConfigType, TYPEDEF, OS_CONST) Ioc,
  uint16 Data
);


/***********************************************************************************************************************
 *  Os_TrapIoc32Receive()
 **********************************************************************************************************************/
/*! \brief        Reads one item from the IOC.
 *  \details      For further details see Os_Ioc32Receive().
 *
 *  \param[in]      IsTrapRequired  Defines whether a trap is required:
 *                                   - TRUE:  Trap is always performed.
 *                                   - FALSE: Trap is performed, if supervisor mode is required by platform.
 *  \param[in,out]  Ioc             See Os_Ioc32Receive().
 *  \param[out]     Data            See Os_Ioc32Receive().
 *
 *  \return       See Os_Ioc32Receive().
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          See Os_Ioc32Receive().
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_TrapIoc32Receive
(
  boolean IsTrapRequired,
  P2CONST(Os_Ioc32ReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(uint32, TYPEDEF, AUTOMATIC) Data
);


/***********************************************************************************************************************
 *  Os_TrapIoc32EmptyQueue()
 **********************************************************************************************************************/
/*! \brief        Empties the queue from the receiver side.
 *  \details      --no details--
 *
 *  \param[in]      IsTrapRequired  Defines whether a trap is required:
 *                                   - TRUE:  Trap is always performed.
 *                                   - FALSE: Trap is performed, if supervisor mode is required by platform.
 *  \param[in,out]  Ioc             See Os_Ioc32EmptyQueue().
 *
 *  \return       See Os_Ioc32EmptyQueue().
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          See Os_Ioc32EmptyQueue().
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_TrapIoc32EmptyQueue
(
  boolean IsTrapRequired,
  P2CONST(Os_Ioc32ReceiveConfigType, TYPEDEF, OS_CONST) Ioc
);


/***********************************************************************************************************************
 *  Os_TrapIoc32Send()
 **********************************************************************************************************************/
/*! \brief        Writes one item to the IOC.
 *  \details      For further details see Os_Ioc32Send().
 *
 *  \param[in]      IsTrapRequired  Defines whether a trap is required:
 *                                   - TRUE:  Trap is always performed.
 *                                   - FALSE: Trap is performed, if supervisor mode is required by platform.
 *  \param[in,out]  Ioc             See Os_Ioc32Send().
 *  \param[in]      Data            See Os_Ioc32Send().
 *
 *  \return       See Os_Ioc32Send().
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          See Os_Ioc32Send().
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_TrapIoc32Send
(
  boolean IsTrapRequired,
  P2CONST(Os_Ioc32SendConfigType, TYPEDEF, OS_CONST) Ioc,
  uint32 Data
);


/***********************************************************************************************************************
 *  Os_TrapIocRefReceive()
 **********************************************************************************************************************/
/*! \brief        Reads one item from the IOC.
 *  \details      For further details see Os_IocRefReceive().
 *
 *  \param[in]      IsTrapRequired  Defines whether a trap is required:
 *                                   - TRUE:  Trap is always performed.
 *                                   - FALSE: Trap is performed, if supervisor mode is required by platform.
 *  \param[in,out]  Ioc             See Os_IocRefReceive().
 *  \param[out]     Data            See Os_IocRefReceive().
 *
 *  \return       See Os_IocRefReceive().
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          See Os_IocRefReceive().
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_TrapIocRefReceive
(
  boolean IsTrapRequired,
  P2CONST(Os_IocRefReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(void, TYPEDEF, AUTOMATIC) Data
);


/***********************************************************************************************************************
 *  Os_TrapIocRefEmptyQueue()
 **********************************************************************************************************************/
/*! \brief        Empties the queue from the receiver side.
 *  \details      --no details--
 *
 *  \param[in]      IsTrapRequired  Defines whether a trap is required:
 *                                   - TRUE:  Trap is always performed.
 *                                   - FALSE: Trap is performed, if supervisor mode is required by platform.
 *  \param[in,out]  Ioc             See Os_IocRefEmptyQueue().
 *
 *  \return       See Os_IocRefEmptyQueue().
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          See Os_IocRefEmptyQueue().
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_TrapIocRefEmptyQueue
(
  boolean IsTrapRequired,
  P2CONST(Os_IocRefReceiveConfigType, TYPEDEF, OS_CONST) Ioc
);


/***********************************************************************************************************************
 *  Os_TrapIocRefSend()
 **********************************************************************************************************************/
/*! \brief        Writes one item to the IOC.
 *  \details      For further details see Os_IocRefSend().
 *
 *  \param[in]      IsTrapRequired  Defines whether a trap is required:
 *                                   - TRUE:  Trap is always performed.
 *                                   - FALSE: Trap is performed, if supervisor mode is required by platform.
 *  \param[in,out]  Ioc             See Os_IocRefSend().
 *  \param[in]      Data            See Os_IocRefSend().
 *
 *  \return       See Os_IocRefSend().
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          See Os_IocRefSend().
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_TrapIocRefSend
(
  boolean IsTrapRequired,
  P2CONST(Os_IocRefSendConfigType, TYPEDEF, OS_CONST) Ioc,
  P2CONST(void, TYPEDEF, AUTOMATIC) Data
);


/***********************************************************************************************************************
 *  Os_TrapIocRead()
 **********************************************************************************************************************/
/*! \brief        Reads one item from the IOC.
 *  \details      For further details see Os_IocRead().
 *
 *  \param[in]      IsTrapRequired  Defines whether a trap is required:
 *                                   - TRUE:  Trap is always performed.
 *                                   - FALSE: Trap is performed, if supervisor mode is required by platform.
 *  \param[in,out]  Ioc             See Os_IocRead().
 *  \param[out]     Data            See Os_IocRead().
 *
 *  \return       See Os_IocRead().
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          See Os_IocRead().
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_TrapIocRead
(
  boolean IsTrapRequired,
  P2CONST(Os_IocReadConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(void, TYPEDEF, AUTOMATIC) Data
);


/***********************************************************************************************************************
 *  Os_TrapIocWrite()
 **********************************************************************************************************************/
/*! \brief        Writes one item to the IOC.
 *  \details      For further details see Os_IocWrite().
 *
 *  \param[in]      IsTrapRequired  Defines whether a trap is required:
 *                                   - TRUE:  Trap is always performed.
 *                                   - FALSE: Trap is performed, if supervisor mode is required by platform.
 *  \param[in,out]  Ioc             See Os_IocWrite().
 *  \param[in]      Data            See Os_IocWrite().
 *
 *  \return       See Os_IocWrite().
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          See Os_IocWrite().
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_TrapIocWrite
(
  boolean IsTrapRequired,
  P2CONST(Os_IocWriteConfigType, TYPEDEF, OS_CONST) Ioc,
  P2CONST(void, TYPEDEF, AUTOMATIC) Data
);

/***********************************************************************************************************************
 *  Os_TrapIoc08MultiReceive()
 **********************************************************************************************************************/
/*! \brief        Reads one item from the next IOC channel.
 *  \details      For further details see Os_Ioc08MultiReceive().
 *
 *  \param[in]      IsTrapRequired  Defines whether a trap is required:
 *                                   - TRUE:  Trap is always performed.
 *                                   - FALSE: Trap is performed, if supervisor mode is required by platform.
 *  \param[in,out]  Ioc             See Os_Ioc08MultiReceive().
 *  \param[in]      Data            See Os_Ioc08MultiReceive().
 *
 *  \return       See Os_Ioc08MultiReceive().
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          See Os_Ioc08MultiReceive().
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_TrapIoc08MultiReceive
(
  boolean IsTrapRequired,
  P2CONST(Os_Ioc08MultiReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(uint8, TYPEDEF, AUTOMATIC) Data
);


/***********************************************************************************************************************
 *  Os_TrapIoc08EmptyMultiQueue()
 **********************************************************************************************************************/
/*! \brief        Empties the queues from the receiver side.
 *  \details      For further details see Os_Ioc08EmptyMultiQueue().
 *
 *  \param[in]      IsTrapRequired  Defines whether a trap is required:
 *                                   - TRUE:  Trap is always performed.
 *                                   - FALSE: Trap is performed, if supervisor mode is required by platform.
 *  \param[in,out]  Ioc             See Os_Ioc08EmptyMultiQueue().
 *  \param[in]      Data            See Os_Ioc08EmptyMultiQueue().
 *
 *  \return       See Os_Ioc08EmptyMultiQueue().
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          See Os_Ioc08EmptyMultiQueue().
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_TrapIoc08EmptyMultiQueue
(
    boolean IsTrapRequired,
  P2CONST(Os_Ioc08MultiReceiveConfigType, TYPEDEF, OS_CONST) Ioc
);


/***********************************************************************************************************************
 *  Os_TrapIoc16MultiReceive()
 **********************************************************************************************************************/
/*! \brief        Reads one item from the next IOC channel.
 *  \details      For further details see Os_Ioc16MultiReceive().
 *
 *  \param[in]      IsTrapRequired  Defines whether a trap is required:
 *                                   - TRUE:  Trap is always performed.
 *                                   - FALSE: Trap is performed, if supervisor mode is required by platform.
 *  \param[in,out]  Ioc             See Os_Ioc16MultiReceive().
 *  \param[in]      Data            See Os_Ioc16MultiReceive().
 *
 *  \return       See Os_Ioc16MultiReceive().
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          See Os_Ioc16MultiReceive().
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_TrapIoc16MultiReceive
(
  boolean IsTrapRequired,
  P2CONST(Os_Ioc16MultiReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(uint16, TYPEDEF, AUTOMATIC) Data
);


/***********************************************************************************************************************
 *  Os_TrapIoc16EmptyMultiQueue()
 **********************************************************************************************************************/
/*! \brief        Empties the queues from the receiver side.
 *  \details      For further details see Os_Ioc16EmptyMultiQueue().
 *
 *  \param[in]      IsTrapRequired  Defines whether a trap is required:
 *                                   - TRUE:  Trap is always performed.
 *                                   - FALSE: Trap is performed, if supervisor mode is required by platform.
 *  \param[in,out]  Ioc             See Os_Ioc16EmptyMultiQueue().
 *  \param[in]      Data            See Os_Ioc16EmptyMultiQueue().
 *
 *  \return       See Os_Ioc16EmptyMultiQueue().
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          See Os_Ioc16EmptyMultiQueue().
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_TrapIoc16EmptyMultiQueue
(
  boolean IsTrapRequired,
  P2CONST(Os_Ioc16MultiReceiveConfigType, TYPEDEF, OS_CONST) Ioc
);


/***********************************************************************************************************************
 *  Os_TrapIoc32MultiReceive()
 **********************************************************************************************************************/
/*! \brief        Reads one item from the next IOC channel.
 *  \details      For further details see Os_Ioc32MultiReceive().
 *
 *  \param[in]      IsTrapRequired  Defines whether a trap is required:
 *                                   - TRUE:  Trap is always performed.
 *                                   - FALSE: Trap is performed, if supervisor mode is required by platform.
 *  \param[in,out]  Ioc             See Os_Ioc32MultiReceive().
 *  \param[in]      Data            See Os_Ioc32MultiReceive().
 *
 *  \return       See Os_Ioc32MultiReceive().
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          See Os_Ioc32MultiReceive().
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_TrapIoc32MultiReceive
(
  boolean IsTrapRequired,
  P2CONST(Os_Ioc32MultiReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(uint32, TYPEDEF, AUTOMATIC) Data
);

/***********************************************************************************************************************
 *  Os_TrapIoc32EmptyMultiQueue()
 **********************************************************************************************************************/
/*! \brief        Empties the queues from the receiver side.
 *  \details      For further details see Os_Ioc32EmptyMultiQueue().
 *
 *  \param[in]      IsTrapRequired  Defines whether a trap is required:
 *                                   - TRUE:  Trap is always performed.
 *                                   - FALSE: Trap is performed, if supervisor mode is required by platform.
 *  \param[in,out]  Ioc             See Os_Ioc32EmptyMultiQueue().
 *  \param[in]      Data            See Os_Ioc32EmptyMultiQueue().
 *
 *  \return       See Os_Ioc32EmptyMultiQueue().
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          See Os_Ioc32EmptyMultiQueue().
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_TrapIoc32EmptyMultiQueue
(
  boolean IsTrapRequired,
  P2CONST(Os_Ioc32MultiReceiveConfigType, TYPEDEF, OS_CONST) Ioc
);

/***********************************************************************************************************************
 *  Os_TrapIocRefMultiReceive()
 **********************************************************************************************************************/
/*! \brief        Reads one item from the next IOC channel.
 *  \details      For further details see Os_IocWrite().
 *
 *  \param[in]      IsTrapRequired  Defines whether a trap is required:
 *                                   - TRUE:  Trap is always performed.
 *                                   - FALSE: Trap is performed, if supervisor mode is required by platform.
 *  \param[in,out]  Ioc             See Os_IocRefMultiReceive().
 *  \param[in]      Data            See Os_IocRefMultiReceive().
 *
 *  \return       See Os_IocRefMultiReceive().
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          See Os_IocRefMultiReceive().
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_TrapIocRefMultiReceive
(
  boolean IsTrapRequired,
  P2CONST(Os_IocRefMultiReceiveConfigType, TYPEDEF, OS_CONST) Ioc,
  P2VAR(void, TYPEDEF, AUTOMATIC) Data
);


/***********************************************************************************************************************
 *  Os_TrapIocRefEmptyMultiQueue()
 **********************************************************************************************************************/
/*! \brief        Empties the queues from the receiver side.
 *  \details      For further details see Os_IocRefEmptyMultiQueue().
 *
 *  \param[in]      IsTrapRequired  Defines whether a trap is required:
 *                                   - TRUE:  Trap is always performed.
 *                                   - FALSE: Trap is performed, if supervisor mode is required by platform.
 *  \param[in,out]  Ioc             See Os_IocRefEmptyMultiQueue().
 *
 *  \return       See Os_IocRefEmptyMultiQueue().
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          See Os_IocRefEmptyMultiQueue().
 **********************************************************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_TrapIocRefEmptyMultiQueue
(
  boolean IsTrapRequired,
  P2CONST(Os_IocRefMultiReceiveConfigType, TYPEDEF, OS_CONST) Ioc
);


/***********************************************************************************************************************
 *  Os_TrapErrApplicationError()
 **********************************************************************************************************************/
/*! \brief        Behavior for application errors.
 *  \details      For further details see Os_ErrApplicationError().
 *
 *  \param[in]    ServiceId   See Os_ErrApplicationError().
 *  \param[in]    Status      See Os_ErrApplicationError().
 *  \param[in]    Parameters  See Os_ErrApplicationError().
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See Os_ErrApplicationError().
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_TrapErrApplicationError
(
  OSServiceIdType ServiceId,
  Os_StatusType Status,
  P2VAR(Os_ErrorParamsType, TYPEDEF, OS_VAR_NOINIT) Parameters
);


/***********************************************************************************************************************
 *  Os_TrapServiceReturn()
 **********************************************************************************************************************/
/*! \brief        Returns to caller state before service call.
 *  \details      For further details see Os_ServiceReturn().
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Calling function is Os_ServiceTfWrapper or Os_ServiceNtfWrapper.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(void, OS_CODE, OS_NORETURN, Os_TrapServiceReturn, (void));


/***********************************************************************************************************************
 *  Os_TrapTaskMissingTerminateTask()
 **********************************************************************************************************************/
/*! \brief        Behavior in case a task did forget to terminate and simply returns.
 *  \details      For further details see Os_TaskMissingTerminateTask().
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See Os_TaskMissingTerminateTask().
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(void, OS_CODE, OS_NORETURN, Os_TrapTaskMissingTerminateTask, (void));


/***********************************************************************************************************************
 *  Os_TrapHookReturn()
 **********************************************************************************************************************/
/*! \brief          Resume previous thread where the hook was called.
 *  \details        For further details see Os_HookReturn().
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            See Os_HookReturnFromStartupHook().
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(void, OS_CODE, OS_NORETURN, Os_TrapHookReturn, (void));


/***********************************************************************************************************************
 *  Os_TrapCoreGetThread()
 **********************************************************************************************************************/
/*! \brief        Returns the current thread pointer of the local core.
 *  \details      For further details see Os_CoreGetThread().
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See Os_CoreGetThread().
 **********************************************************************************************************************/
FUNC(P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST), OS_CODE) Os_TrapCoreGetThread
(
  void
);


/***********************************************************************************************************************
 *  Os_TrapIsrEpilogue()
 **********************************************************************************************************************/
/*! \brief        Epilogue for ISR user functions.
 *  \details      For further details see Os_IsrEpilogue().
 *
 *  \context      ISR2|OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre            See Os_IsrEpilogue().
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(void, OS_CODE, OS_NORETURN, Os_TrapIsrEpilogue, (void));


/***********************************************************************************************************************
 *  Os_TrapHandler()
 **********************************************************************************************************************/
/*! \brief        Handles trap requests and calls the appropriate APIs with supervisor access.
 *  \details      --no details--
 *
 *  \param[in,out]  Packet                The data packet which contains parameters for API.
 *                                        Parameter must not be NULL.
 *  \param[in,out]  CallerInterruptState  Interrupt state of the caller which shall be restored/modified.
 *                                        Parameter must not be NULL.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *  \pre          Reference API parameters of the TrapPacket are valid.
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_TrapHandler
(
  P2VAR(Os_TrapPacketType, AUTOMATIC, OS_VAR_NOINIT) Packet,
  P2VAR(Os_Hal_IntTrapStateType, AUTOMATIC, OS_VAR_NOINIT) CallerInterruptState
);


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/



# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_TRAPINT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_TrapInt.h
 **********************************************************************************************************************/
