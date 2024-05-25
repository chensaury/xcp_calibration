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
 *  \defgroup    Os_ServiceFunction Service Function
 *  \brief       Defines service functions.
 *  \details
 *  A *service function* is a function which is called inside the current thread with modified access rights.
 *  It allows using services of other applications, without invoking the scheduler.
 *
 *  AUTOSAR Trusted Functions are implemented as a service function.
 *  MICROSAR OS also provides Non-Trusted Functions, which are an extension to AUTOSAR OS.
 *
 *  ![Service Function Concept](ServiceFunction_Concept.png)
 *
 *  ![Trusted Function Call](ServiceFunction_TfCall.png)
 *
 *  ![Non-Trusted Function Call](ServiceFunction_NtfCall.png)
 *
 *
 *  Non-Trusted Functions
 *  ---------------------
 *  On each Non-Trusted Function call a stack switch is performed.
 *  There have to be enough stacks configured to handle the worst case during runtime. This means there must be
 *  as many stacks as there are concurrent NTF instances during run-time.
 *
 *  To protect applications against each other from consuming all the stacks, each application has a configured limit
 *  for concurrent NTF calls per NTF.
 *
 *  The generator adds all possible concurrent NTF-Calls per NTF and creates an NTF stack pool.
 *  During runtime, if a NTF is called, the OS takes one stack from the pool.
 *  And executes the NTF instance on this stack.
 *  If the NTF returns, the OS switches back to the previous stack and returns the stack to the pool.
 *
 *  If an application reaches its configured limit of concurrent NTF calls for a NTF,
 *  the OS refuses the call and returns with an error.
 *
 *  ![Stack handling for Non-Trusted Functions](NtfConcept.png)
 *
 *
 *  \{
 *
 *  \file
 *  \brief        OS internal functions to work with service functions.
 *  \details      --no details--
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_SERVICEFUNCTIONINT_H
# define OS_SERVICEFUNCTIONINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_ServiceFunction_Types.h"

/* Os kernel module dependencies */
# include "Os_Application_Types.h"
# include "Os_MemoryProtection_Types.h"
# include "Os_Stack_Types.h"
# include "Os_BitArrayInt.h"
# include "Os_Lcfg.h"
# include "OsInt.h"

/* Os hal dependencies */
# include "Os_Hal_ContextInt.h"
# include "Os_Hal_CompilerInt.h"



/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/
/*! End marker of linked list of service calls. */
#define OS_SERVICECALL_LIST_END            ((P2VAR(Os_ServiceCallType, AUTOMATIC, OS_VAR_NOINIT))(NULL_PTR))

/*! Type cast from Os_ServiceTfConfigType to Os_ServiceConfigType by use of base element addressing. */
#define OS_SERVICE_CASTCONFIG_TF_2_SERVICE(tf)                   (&((tf).Base))                                         /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Type cast from Os_ServiceNtfConfigType to Os_ServiceConfigType by use of base element addressing. */
#define OS_SERVICE_CASTCONFIG_NTF_2_SERVICE(ntf)                 (&((ntf).Base))                                        /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Type cast from Os_ServiceFtfConfigType to Os_ServiceConfigType by use of base element addressing. */
#define OS_SERVICE_CASTCONFIG_FTF_2_SERVICE(ftf)                 (&((ftf).Base))                                        /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/*! Available types of the service functions. */
typedef enum
{
  OS_SERVICE_TRUSTEDFUNCTION,     /*!< Switch: Current Application, MPU access rights, (Processor mode). */
  OS_SERVICE_NONTRUSTEDFUNCTION,  /*!< Switch: Current Application, MPU access rights, Processor mode, Stack. */
  OS_SERVICE_FASTTRUSTEDFUNCTION  /*!< Switch: (Processor mode). */
} Os_ServiceTypeType;


/*! Data type to marshal trusted function parameters. */
typedef struct
{
  /*! Index parameter of the service. */
  TrustedFunctionIndexType FunctionIndex;

  /*! Parameter reference of the the trusted function. */
  TrustedFunctionParameterRefType FunctionParams;
} Os_ServiceTrustedFunctionParamsType;

/*! Data type to marshal trusted function parameters. */
typedef struct
{
  /*! Index parameter of the service. */
  Os_NonTrustedFunctionIndexType FunctionIndex;

  /*! Parameter reference of the the trusted function. */
  Os_NonTrustedFunctionParameterRefType FunctionParams;
} Os_ServiceNonTrustedFunctionParamsType;

/*! Data type to marshal fast trusted function parameters. */
typedef struct
{
  /*! Index parameter of the service. */
  Os_FastTrustedFunctionIndexType FunctionIndex;

  /*! Parameter reference of the the fast trusted function. */
  Os_FastTrustedFunctionParameterRefType FunctionParams;
} Os_ServiceFastTrustedFunctionParamsType;


/*! Data type to marshal service parameters. */
typedef union
{                                                                                                                       /* PRQA S 0750 */ /* MD_MSR_Union */
  Os_ServiceTrustedFunctionParamsType TrustedFunctionParameters;
  Os_ServiceNonTrustedFunctionParamsType NonTrustedFunctionParameters;
  Os_ServiceFastTrustedFunctionParamsType FastTrustedFunctionParameters;
} Os_ServiceParamsType;


/*! Service call info container.
 *  Data type to save the current state before a service call. */
struct Os_ServiceCallType_Tag
{
  /*! Application before the service call. */
  P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) PrevApplication;

  /*! Memory protection settings before the service call. */
  P2CONST(Os_MpAccessRightsType, TYPEDEF, OS_CONST) PrevMpAccessRights;

  /*! List of services before the service call. */
  P2VAR(Os_ServiceCallType, TYPEDEF, OS_VAR_NOINIT) PrevServiceCalls;

  /*! Context before service call. */
  Os_Hal_ContextType CallerContext;

  /*! Context of the current service call. */
  P2VAR(Os_Hal_ContextType, TYPEDEF, OS_VAR_NOINIT) ServiceCallContext;

  /*! Pointer to service which has been called. */
  P2CONST(Os_ServiceConfigType, TYPEDEF, OS_CONST) Service;

  /*! Parameter marshaling container. */
  Os_ServiceParamsType Parameters;
};


/*! Service call info container.
 *  Data type to save the current state before a NTF service call.
 *  \extends Os_ServiceCallType_Tag */
struct Os_ServiceNtfCallType_Tag
{
  /*! Base service call attributes.
   *  This attribute must be the first. */
  Os_ServiceCallType Base;

  /*! Stack which is used for the NTF call. */
  P2CONST(Os_ServiceStackConfigType, TYPEDEF, OS_CONST) Stack;
};



/*! Configuration information of a service function.
 *  \trace SPEC-63853, SPEC-63511 */
struct Os_ServiceConfigType_Tag
{
  /*! Owner application. */
  P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) OwnerApplication;

  /*! Memory protection settings. */
  P2CONST(Os_MpAccessRightsType, TYPEDEF, OS_CONST) MpAccessRights;

  /*! Tells what kind of service it is. */
  Os_ServiceTypeType ServiceType;
};


/*! Type of user provided trusted functions. */
typedef P2FUNC(void, OS_CODE, Os_ServiceTfCbkType)
(
  TrustedFunctionIndexType,
  TrustedFunctionParameterRefType
);                                                                                                                      /* PRQA S 1336 */ /* MD_Os_Rule8.2_1336 */


/*! Trusted Functions.
 *  \extends Os_ServiceConfigType */
struct Os_ServiceTfConfigType_Tag
{
  /*! Base service attributes.
   *  This attribute must be the first. */
  Os_ServiceConfigType Base;

  /*! Pointer to user function. */
  Os_ServiceTfCbkType Callback;

  /*! Context configuration of the mode switch service. */
  P2CONST(Os_Hal_ContextConfigType, TYPEDEF, OS_CONST) Context;
};



/*! Type of user provided non-trusted functions. */
typedef P2FUNC(void, OS_CODE, Os_ServiceNtfCbkType)
(
  Os_NonTrustedFunctionIndexType,
  Os_NonTrustedFunctionParameterRefType
);                                                                                                                      /* PRQA S 1336 */ /* MD_Os_Rule8.2_1336 */


/*! Configuration for services which need a mode switch.
 *  \extends Os_ServiceConfigType */
struct Os_ServiceNtfConfigType_Tag
{
  /*! Base service attributes.
   *  This attribute must be the first. */
  Os_ServiceConfigType Base;

  /*! Pointer to user function. */
  Os_ServiceNtfCbkType Callback;

  /*! Context configuration of the service. */
  P2CONST(Os_Hal_ContextConfigType, TYPEDEF, OS_CONST) Context;

  /*! Stack pool where the service gets its stack from. */
  P2CONST(Os_ServiceStackPoolConfigType, TYPEDEF, OS_CONST) StackPool;
};



/*! Configuration information of a single stack of a pool. */
struct  Os_ServiceStackConfigType_Tag
{
  /*! Stack configuration. */
  P2CONST(Os_StackConfigType, TYPEDEF, OS_CONST) Stack;

  /*! Hal encoding of the stack configuration. */
  P2CONST(Os_Hal_ContextStackConfigType, TYPEDEF, OS_CONST) HwConfig;

  /*! Index of this pooled stack. */
  uint8 PoolIndex;
};


/*! Dynamic data of a stack pool. */
struct Os_ServiceStackPoolType_Tag
{
  /*! Access counter per application. */
  uint8_least AccessCounter[OS_APPID_COUNT];
};


/*! Configuration information of a stack pool. */
struct Os_ServiceStackPoolConfigType_Tag
{
  /*! Dynamic data of the stack pool. */
  P2VAR(Os_ServiceStackPoolType, TYPEDEF, OS_VAR_NOINIT) Dyn;

  /*! References to free stacks. */
  Os_BitArrayConfigType AvailabilityMap;

  /*! Pointer to stacks. */
  P2CONST(Os_ServiceStackConfigType, TYPEDEF, OS_CONST) Stacks;

  /*! Pointer to stacks. */
  uint8 StackCount;

  /*! Configured access counter per application. */
  uint8 AccessCounter[OS_APPID_COUNT];
};



/*! Type of user provided trusted functions. */
typedef P2FUNC(void, OS_CODE, Os_ServiceFtfCbkType)
(
  Os_FastTrustedFunctionIndexType,
  Os_FastTrustedFunctionParameterRefType
);                                                                                                                      /* PRQA S 1336 */ /* MD_Os_Rule8.2_1336 */

/*! Fast Trusted Functions.
 *  \extends Os_ServiceConfigType */
struct Os_ServiceFtfConfigType_Tag
{
  /*! Base service attributes.
   *  This attribute must be the first. */
  Os_ServiceConfigType Base;

  /*! Pointer to user function. */
  Os_ServiceFtfCbkType Callback;
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
 *  Os_ServiceReturn()
 **********************************************************************************************************************/
/*! \brief          Restores the state before the last service call of the current thread.
 *  \details        --no details--
 *
 *  \context        TASK|ISR2
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Current thread is in a service call sequence.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(void, OS_CODE, OS_NORETURN, Os_ServiceReturn, (void));


/***********************************************************************************************************************
 *  Os_ServiceTfWrapper()
 **********************************************************************************************************************/
/*! \brief          Unmarshal service parameters, execute service and restore context of service caller.
 *  \details        --no details--
 *
 *  \param[in]      ServiceCall   Service call instance which shall be executed. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Current thread is in service function.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(void, OS_CODE, OS_NORETURN,
Os_ServiceTfWrapper,
(
  P2CONST(Os_ServiceCallType, AUTOMATIC, OS_VAR_NOINIT) ServiceCall
));


/***********************************************************************************************************************
 *  Os_ServiceNtfWrapper()
 **********************************************************************************************************************/
/*! \brief          Unmarshal service parameters, execute service and restore context of service caller.
 *  \details        --no details--
 *
 *  \param[in]      ServiceCall   Service call instance which shall be executed. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Current thread is in service function.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(void, OS_CODE, OS_NORETURN,
Os_ServiceNtfWrapper,
(
  P2CONST(Os_ServiceCallType, AUTOMATIC, OS_VAR_NOINIT) ServiceCall
));


/***********************************************************************************************************************
 *  Os_ServiceCallsInit()
 **********************************************************************************************************************/
/*! \brief          Initialize list of service calls.
 *  \details        Set list to empty.
 *
 *  \param[in,out]  ServiceCalls   List of service calls to initialize. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_ServiceCallsInit,
(
  P2VAR(Os_ServiceCallListType, AUTOMATIC, OS_VAR_NOINIT) ServiceCalls
));


/***********************************************************************************************************************
 *  Os_ServiceCallForceRelease()
 **********************************************************************************************************************/
/*! \brief          Release service calls in given list.
 *  \details        Release NTF-Stacks in the given service call list and set the service calls list to empty.
 *
 *  \param[in,out]  ServiceCalls   List of service calls to kill. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_ServiceCallForceRelease
(
  P2VAR(Os_ServiceCallListType, AUTOMATIC, OS_VAR_NOINIT) ServiceCalls
);


/***********************************************************************************************************************
 *  Os_ServiceNtfIsEnabled()
 **********************************************************************************************************************/
/*! \brief          Returns whether Non-Trusted Functions are enabled (!0) or not (0).
 *  \details        --no details--
 *
 *  \retval         !0  Non-Trusted Functions enabled.
 *  \retval         0   Non-Trusted Functions disabled.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_ServiceNtfIsEnabled,
(
  void
));


/***********************************************************************************************************************
 *  Os_ServiceTfIsEnabled()
 **********************************************************************************************************************/
/*! \brief          Returns whether Trusted Functions are enabled (!0) or not (0).
 *  \details        --no details--
 *
 *  \retval         !0  Trusted Functions enabled.
 *  \retval         0   Trusted Functions disabled.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_ServiceTfIsEnabled,
(
  void
));


/***********************************************************************************************************************
 *  Os_ServiceFtfIsEnabled()
 **********************************************************************************************************************/
/*! \brief          Returns whether Fast Trusted Functions are enabled (!0) or not (0).
 *  \details        --no details--
 *
 *  \retval         !0  Fast Trusted Functions enabled.
 *  \retval         0   Fast Trusted Functions disabled.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_ServiceFtfIsEnabled,
(
  void
));


/***********************************************************************************************************************
 *  Os_ServiceInit()
 **********************************************************************************************************************/
/*! \brief          Initialize the given service.
 *  \details        --no details--
 *
 *  \param[in,out]  Service     Service to init. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_ServiceInit,
(
  P2CONST(Os_ServiceConfigType, AUTOMATIC, OS_CONST) Service
));


/***********************************************************************************************************************
 *  Os_Api_CallTrustedFunction()
 **********************************************************************************************************************/
/*! \brief        OS service CallTrustedFunction().
 *  \details      For further details see CallTrustedFunction().
 *
 *  \param[in]    FunctionIndex   See CallTrustedFunction().
 *  \param[in]    FunctionParams  See CallTrustedFunction().
 *
 *  \retval       OS_STATUS_OK              No error.
 *  \retval       OS_STATUS_SERVICEID       No function defined for this index.
 *  \retval       OS_STATUS_CALLEVEL        (EXTENDED status:) Called from invalid context.
 *  \retval       OS_STATUS_ACCESSRIGHTS_1  (EXTENDED status:) The given object belongs to a foreign core.
 *  \retval       OS_STATUS_NOTACCESSIBLE_1 (Service Protection:) Given object's owner application is not accessible.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          See CallTrustedFunction().
 *
 *  \trace        CREQ-34, CREQ-40
 *  \trace        SPEC-64035, SPEC-63961, SPEC-64031, SPEC-63795, SPEC-63988, SPEC-63943, SPEC-63773, SPEC-64011
 *  \trace        SPEC-63802, SPEC-64022, SPEC-63997, SPEC-63743, SPEC-63972
 *
 *
 *  Internal comment removed.
 *
 *
 *
 *
 *
 *
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_CallTrustedFunction
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams
);


/***********************************************************************************************************************
 *  Os_Api_CallNonTrustedFunction()
 **********************************************************************************************************************/
/*! \brief        OS service Os_CallNonTrustedFunction().
 *  \details      For further details see Os_CallNonTrustedFunction().
 *                Function is callable in PreStartTasks.
 *
 *  \param[in]    FunctionIndex   See Os_CallNonTrustedFunction().
 *  \param[in]    FunctionParams  See Os_CallNonTrustedFunction().
 *
 *  \retval       OS_STATUS_OK              No error.
 *  \retval       OS_STATUS_SERVICEID       No function defined for this index.
 *  \retval       OS_STATUS_CALLEVEL        (EXTENDED status:) Called from invalid context.
 *  \retval       OS_STATUS_ACCESSRIGHTS_1  (EXTENDED status:) The given object belongs to a foreign core.
 *  \retval       OS_STATUS_NOTACCESSIBLE_1 (Service Protection:) Given object's owner application is not accessible.
 *  \retval       OS_STATUS_NO_NTFSTACK_POOL_EMPTY        No NTF-stack available to for a further instance of the NTF.
 *  \retval       OS_STATUS_NO_NTFSTACK_APPLIMIT_EXCEEDED Caller application may not perform further NTF calls.
 *
 *  \context      TASK|ISR2
 *  \note         Function is callable in PreStartTasks.
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          See Os_CallNonTrustedFunction().
 *
 *  \trace        CREQ-105586, CREQ-105587
 *
 *  Internal comment removed.
 *
 *
 *
 *
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_CallNonTrustedFunction
(
  Os_NonTrustedFunctionIndexType FunctionIndex,
  Os_NonTrustedFunctionParameterRefType FunctionParams
);


/***********************************************************************************************************************
 *  Os_Api_CallFastTrustedFunction()
 **********************************************************************************************************************/
/*! \brief        OS service Os_CallFastTrustedFunction().
 *  \details      For further details see Os_CallFastTrustedFunction().
 *                Function is callable in PreStartTasks.
 *
 *  \param[in]    FunctionIndex   See Os_CallFastTrustedFunction().
 *  \param[in]    FunctionParams  See Os_CallFastTrustedFunction().
 *
 *  \retval       OS_STATUS_OK              No error.
 *  \retval       OS_STATUS_SERVICEID       No function defined for this index.
 *
 *  \context      TASK|ISR2
 *  \note         Function is callable in PreStartTasks.
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          See Os_CallFastTrustedFunction().
 *
 *  \note         SPEC-64000  Is not implemented for this API because SPEC-63961 explicitly allows NULL pointers.
 *  \note         SPEC-64017  Check is not performed, because usage of this API inside of critical sections is a common
 *                            use case for some users.
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_CallFastTrustedFunction
(
  Os_FastTrustedFunctionIndexType FunctionIndex,
  Os_FastTrustedFunctionParameterRefType FunctionParams
);


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/



# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_SERVICEFUNCTIONINT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_ServiceFunctionInt.h
 **********************************************************************************************************************/
