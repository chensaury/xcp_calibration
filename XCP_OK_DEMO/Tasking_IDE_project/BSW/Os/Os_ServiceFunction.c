/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**
 * \addtogroup Os_ServiceFunction
 * \{
 *
 * \file
 * \brief       Implementation of \ref Os_ServiceFunction.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777, 0779, 0828  EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */


#define OS_SERVICEFUNCTION_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_ServiceFunction.h"
#include "Os_ServiceFunction_Lcfg.h"

/* Os kernel module dependencies */
#include "Os_MemoryProtection.h"
#include "Os_TimingProtection.h"
#include "Os_Thread.h"
#include "Os_Application.h"
#include "Os_Error.h"
#include "Os_Interrupt.h"
#include "Os_Core.h"

/* Os hal dependencies */
#include "Os_Hal_Context.h"


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

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define OS_START_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  Os_ServiceCheckTfId()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given ID is valid (Not OS_CHECK_FAILED) or not (OS_CHECK_FAILED).
 *  \details        In case that extended checks are disabled, the default result of \ref Os_ErrExtendedCheck() is
 *                  returned.
 *
 *  \param[in]      Id        The ID to check.
 *
 *  \retval         Not OS_CHECK_FAILED   If the given ID is valid.
 *  \retval         OS_CHECK_FAILED       If the given ID is invalid.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_ServiceCheckTfId,
(
  TrustedFunctionIndexType Id
));


/***********************************************************************************************************************
 *  Os_ServiceCheckNtfId()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given ID is valid (Not OS_CHECK_FAILED) or not (OS_CHECK_FAILED).
 *  \details        In case that extended checks are disabled, the default result of \ref Os_ErrExtendedCheck() is
 *                  returned.
 *
 *  \param[in]      Id        The ID to check.
 *
 *  \retval         Not OS_CHECK_FAILED   If the given ID is valid.
 *  \retval         OS_CHECK_FAILED       If the given ID is invalid.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_ServiceCheckNtfId,
(
  Os_NonTrustedFunctionIndexType Id
));


/***********************************************************************************************************************
 *  Os_ServiceCheckFtfId()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given ID is valid (Not OS_CHECK_FAILED) or not (OS_CHECK_FAILED).
 *  \details        In case that extended checks are disabled, the default result of \ref Os_ErrExtendedCheck() is
 *                  returned.
 *
 *  \param[in]      Id        The ID to check.
 *
 *  \retval         Not OS_CHECK_FAILED   If the given ID is valid.
 *  \retval         OS_CHECK_FAILED       If the given ID is invalid.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_ServiceCheckFtfId,
(
  Os_FastTrustedFunctionIndexType Id
));


/***********************************************************************************************************************
 *  Os_ServiceCheckIsAccessible()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given service is accessible (Not OS_CHECK_FAILED) or not (OS_CHECK_FAILED).
 *  \details        In case that extended checks are disabled, the default result of \ref Os_ErrExtendedCheck() is
 *                  returned.
 *
 *  \param[in]      ServiceFunction       Service to query. Parameter must not be NULL.
 *
 *  \retval         Not OS_CHECK_FAILED   Not accessible.
 *  \retval         OS_CHECK_FAILED       Accessible.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_ServiceCheckIsAccessible,
(
  P2CONST(Os_ServiceConfigType, AUTOMATIC, OS_CONST) ServiceFunction
));


/***********************************************************************************************************************
 *  Os_ServiceStackPoolCheckIsAllowedToGet()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given application is allowed to get another stack from the pool.
 *  \details        --no details--
 *
 *  \param[in]      StackPool           StackPool which shall be accessed. Parameter must not be NULL.
 *  \param[in]      CurrentApplication  Application which wants to access. Parameter must be < OS_APPID_COUNT.
 *
 *  \retval         Not OS_CHECK_FAILED   Application is allowed to get a stack.
 *  \retval         OS_CHECK_FAILED       Application is not allowed to get another stack from the given pool.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_ServiceStackPoolCheckIsAllowedToGet,
(
  P2CONST(Os_ServiceStackPoolConfigType, AUTOMATIC, OS_CONST) StackPool,
  ApplicationType CurrentApplication
));


/***********************************************************************************************************************
 *  Os_ServiceTfId2Tf()
 **********************************************************************************************************************/
/*! \brief          Converts an ID into an object.
 *  \details        --no details--
 *
 *  \param[in]      Id     The object ID. Parameter must be < OS_TRUSTEDFUNCTIONID_COUNT.
 *
 *  \return         The object corresponding to the ID.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE P2CONST(Os_ServiceTfConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_ServiceTfId2Tf,
(
  TrustedFunctionIndexType Id
));


/***********************************************************************************************************************
 *  Os_ServiceNtfId2Ntf()
 **********************************************************************************************************************/
/*! \brief          Converts an ID into an object.
 *  \details        --no details--
 *
 *  \param[in]      Id     The object ID. Parameter must be < OS_TRUSTEDFUNCTIONID_COUNT.
 *
 *  \return         The object corresponding to the ID.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_ServiceNtfConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_ServiceNtfId2Ntf,
(
  Os_NonTrustedFunctionIndexType Id
));


/***********************************************************************************************************************
 *  Os_ServiceFtfId2Ftf()
 **********************************************************************************************************************/
/*! \brief          Converts an ID into an object.
 *  \details        --no details--
 *
 *  \param[in]      Id     The object ID. Parameter must be < OS_FASTTRUSTEDFUNCTIONID_COUNT.
 *
 *  \return         The object corresponding to the ID.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE P2CONST(Os_ServiceFtfConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_ServiceFtfId2Ftf,
(
  Os_FastTrustedFunctionIndexType Id
));


/***********************************************************************************************************************
 *  Os_ServiceIsTf()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given service is a trusted function.
 *  \details        --no details--
 *
 *  \param[in]      Service   Service to be queried. Parameter must not be NULL.
 *
 *  \retval         !0  Given service is a trusted function.
 *  \retval         0   Otherwise.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_ServiceIsTf,
(
  P2CONST(Os_ServiceConfigType, AUTOMATIC, OS_CONST) Service
));


/***********************************************************************************************************************
 *  Os_ServiceIsNtf()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given service is a non-trusted function.
 *  \details        --no details--
 *
 *  \param[in]      Service   Service to be queried. Parameter must not be NULL.
  *
 *  \retval         !0  Given service is a non trusted function.
 *  \retval         0   Otherwise.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_ServiceIsNtf,
(
  P2CONST(Os_ServiceConfigType, AUTOMATIC, OS_CONST) Service
));


/***********************************************************************************************************************
 *  Os_Service2Tf()
 **********************************************************************************************************************/
/*! \brief          Converts a service into a trusted function.
 *  \details        --no details--
 *
 *  \param[in]      Service   Service to be converted. Service must be a trusted function.
 *                            Parameter must not be NULL.
 *
 *  \return         The trusted function corresponding to the given service.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_ServiceTfConfigType, AUTOMATIC, OS_CONST),
OS_CODE, OS_ALWAYS_INLINE, Os_Service2Tf,
(
  P2CONST(Os_ServiceConfigType, AUTOMATIC, OS_CONST) Service
));


/***********************************************************************************************************************
 *  Os_Service2Ntf()
 **********************************************************************************************************************/
/*! \brief          Converts a service into a non trusted function.
 *  \details        --no details--
 *
 *  \param[in]      Service   Service to be converted. Service must be a non trusted function.
 *                            Parameter must not be NULL.
 *
 *  \return         The non trusted function corresponding to the given service.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_ServiceNtfConfigType, AUTOMATIC, OS_CONST),
OS_CODE, OS_ALWAYS_INLINE, Os_Service2Ntf,
(
  P2CONST(Os_ServiceConfigType, AUTOMATIC, OS_CONST) Service
));


/***********************************************************************************************************************
 *  Os_ServiceCall2NtfCall()
 **********************************************************************************************************************/
/*! \brief          Converts a service call into a NTF call.
 *  \details        --no details--
 *
 *  \param[in]      Service   Service to be converted. Service call must be a non trusted function call.
 *                            Parameter must not be NULL.
 *
 *  \return         The non trusted function call.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2VAR(Os_ServiceNtfCallType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE,
OS_ALWAYS_INLINE, Os_ServiceCall2NtfCall,
(
  P2VAR(Os_ServiceCallType, AUTOMATIC, OS_VAR_NOINIT) ServiceCall
));


/***********************************************************************************************************************
 *  Os_ServiceTfNeedsModeSwitch()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given trusted function requires a mode switch (!0) or not (0).
 *  \details        --no details--
 *
 *  \param[in]      TrustedFunction   Trusted Function to query. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_ServiceTfNeedsModeSwitch,
(
  P2CONST(Os_ServiceTfConfigType, AUTOMATIC, OS_CONST) TrustedFunction
));


/***********************************************************************************************************************
 *  Os_ServicePrologue()
 **********************************************************************************************************************/
/*! \brief          Save current access settings and change to access settings of the given service.
 *  \details        --no details--
 *
 *  \param[in,out]  ServiceCall     Where to store previous info. Parameter must not be NULL.
 *  \param[in]      Service         Service where to load the new settings from. Parameter must not be NULL.
 *  \param[in,out]  CurrentThread   Thread which shall be modified. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_LOCAL_INLINE FUNC(void, OS_CODE) Os_ServicePrologue
(
  P2VAR(Os_ServiceCallType, AUTOMATIC, OS_VAR_NOINIT) ServiceCall,
  P2CONST(Os_ServiceConfigType, AUTOMATIC, OS_CONST) Service,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) CurrentThread
);


/***********************************************************************************************************************
 *  Os_ServiceEpilogue()
 **********************************************************************************************************************/
/*! \brief          Restore access settings before service call.
 *  \details        --no details--
 *
 *  \param[in,out]  ServiceCall     Where to store previous info. Parameter must not be NULL.
 *  \param[in,out]  CurrentThread   Thread which shall be modified. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Os_ServicePrologue is called before the call of Os_ServiceEpilogue with the same arguments.
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_LOCAL_INLINE FUNC(void, OS_CODE) Os_ServiceEpilogue
(
  P2CONST(Os_ServiceCallType, AUTOMATIC, OS_VAR_NOINIT) ServiceCall,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) CurrentThread
);


/***********************************************************************************************************************
 *  Os_ServiceStackPoolInit()
 **********************************************************************************************************************/
/*! \brief          Initialize the given stack pool.
 *  \details        --no details--
 *
 *  \param[in,out]  StackPool           Stack pool to initialize. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_LOCAL_INLINE FUNC(void, OS_CODE) Os_ServiceStackPoolInit
(
  P2CONST(Os_ServiceStackPoolConfigType, AUTOMATIC, OS_CONST) StackPool
);


/***********************************************************************************************************************
 *  Os_ServiceStackPoolGetStack()
 **********************************************************************************************************************/
/*! \brief          Returns a stack object from the stack pool.
 *  \details        --no details--
 *
 *  \param[in,out]  StackPool           Stack pool to get the stack from. Parameter must not be NULL.
 *  \param[in]      CurrentApplication  Current application which wants to get a stack.
 *                                      Parameter must be < OS_APPID_COUNT.
 *
 *  \return         Stack object.
 *  \retval         NULL_PTR if there is no further stack available.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_LOCAL_INLINE FUNC(P2CONST(Os_ServiceStackConfigType, AUTOMATIC, OS_CONST), OS_CODE) Os_ServiceStackPoolGetStack
(
  P2CONST(Os_ServiceStackPoolConfigType, AUTOMATIC, OS_CONST) StackPool,
  ApplicationType CurrentApplication
);


/***********************************************************************************************************************
 *  Os_ServiceStackPoolReleaseStack()
 **********************************************************************************************************************/
/*! \brief          Returns a stack object from the stack pool.
 *  \details        --no details--
 *
 *  \param[in,out]  StackPool     Stack pool to get the stack from. Parameter must not be NULL.
 *  \param[in]      Stack         Stack which shall be released. Stack has to belong to the StackPool.
 *                                Parameter must not be NULL.
 *  \param[in]      Application   Application which wants to release the stack. Parameter must be < OS_APPID_COUNT.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_LOCAL_INLINE FUNC(void, OS_CODE) Os_ServiceStackPoolReleaseStack
(
  P2CONST(Os_ServiceStackPoolConfigType, AUTOMATIC, OS_CONST) StackPool,
  P2CONST( Os_ServiceStackConfigType, AUTOMATIC, OS_CONST) Stack,
  ApplicationType Application
);


/***********************************************************************************************************************
 *  Os_ServiceTfCall()
 **********************************************************************************************************************/
/*! \brief          Internal function to call trusted functions.
 *  \details        --no details--
 *
 *  \param[in,out]  TrustedFunction   Trusted Function which shall be executed. Parameter must not be NULL.
 *  \param[in]      FunctionIndex     FunctionIndex parameter to be passed.
 *                                    Parameter must be < OS_TRUSTEDFUNCTIONID_COUNT.
 *  \param[in]      FunctionParams    FunctionParams parameter to be passed. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_LOCAL_INLINE FUNC(Os_StatusType, OS_CODE) Os_ServiceTfCall
(
  P2CONST(Os_ServiceTfConfigType, AUTOMATIC, OS_CONST) TrustedFunction,
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams
);


/***********************************************************************************************************************
 *  Os_ServiceNtfCall()
 **********************************************************************************************************************/
/*! \brief          Internal function to call non-trusted functions.
 *  \details        --no details--
 *
 *  \param[in,out]  NonTrustedFunction  Non-Trusted Function which shall be executed. Parameter must not be NULL.
 *  \param[in]      FunctionIndex       FunctionIndex parameter to be passed.
 *                                      Parameter must be < OS_NONTRUSTEDFUNCTIONID_COUNT.
 *  \param[in]      FunctionParams      FunctionParams parameter to be passed. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK                            No error.
 *  \retval         OS_STATUS_NO_NTFSTACK_POOL_EMPTY        No NTF-stack available to for a further instance of the NTF.
 *  \retval         OS_STATUS_NO_NTFSTACK_APPLIMIT_EXCEEDED Caller application may not perform further NTF calls.
 *  \retval         OS_STATUS_NOTACCESSIBLE_1 (Service Protection:) Given object's owner application is not accessible.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_LOCAL_INLINE FUNC(Os_StatusType, OS_CODE) Os_ServiceNtfCall
(
  P2CONST(Os_ServiceNtfConfigType, AUTOMATIC, OS_CONST) NonTrustedFunction,
  Os_NonTrustedFunctionIndexType FunctionIndex,
  Os_NonTrustedFunctionParameterRefType FunctionParams
);


/***********************************************************************************************************************
 *  Os_ServiceFtfCall()
 **********************************************************************************************************************/
/*! \brief          Internal function to call fast trusted functions.
 *  \details        --no details--
 *
 *  \param[in,out]  FastTrustedFunction Fast Trusted Function which shall be executed. Parameter must not be NULL.
 *  \param[in]      FunctionIndex       FunctionIndex parameter to be passed.
 *                                      Parameter must be < OS_FASTTRUSTEDFUNCTIONID_COUNT.
 *  \param[in]      FunctionParams      FunctionParams parameter to be passed. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK                            No error.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_LOCAL_INLINE FUNC(Os_StatusType, OS_CODE) Os_ServiceFtfCall
(
  P2CONST(Os_ServiceFtfConfigType, AUTOMATIC, OS_CONST) FastTrustedFunction,
  Os_FastTrustedFunctionIndexType FunctionIndex,
  Os_FastTrustedFunctionParameterRefType FunctionParams
);


/***********************************************************************************************************************
 *  Os_ServiceInitInternal()
 **********************************************************************************************************************/
/*! \brief          Initialize the given service function.
 *  \details        --no details--
 *
 *  \param[in,out]  Service The service to initialize. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_ServiceInitInternal                                                                              /* PRQA S 3449 */ /* MD_Os_Rule8.5_3449 */
(
  P2CONST(Os_ServiceConfigType, AUTOMATIC, OS_CONST) Service
);


/***********************************************************************************************************************
 *  Os_ServiceNtfInit()
 **********************************************************************************************************************/
/*! \brief          Initialize the given non-trusted function.
 *  \details        --no details--
 *
 *  \param[in,out]  NonTrustedFunction   NonTrustedFunction to initialize. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_LOCAL_INLINE FUNC(void, OS_CODE) Os_ServiceNtfInit
(
  P2CONST(Os_ServiceNtfConfigType, AUTOMATIC, OS_CONST) NonTrustedFunction
);


/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/



/***********************************************************************************************************************
 *  Os_ServiceStackPoolInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_LOCAL_INLINE FUNC(void, OS_CODE) Os_ServiceStackPoolInit
(
  P2CONST(Os_ServiceStackPoolConfigType, AUTOMATIC, OS_CONST) StackPool
)
{
  /* #10 Initialize availability map. */
  Os_BitArrayInit(&StackPool->AvailabilityMap);                                                                         /* SBSW_OS_FC_PRECONDITION */

  /* #20 Set all stacks to available. */
  {
    uint8_least index;

    for(index = 0; index < StackPool->StackCount; index++)
    {
      Os_BitArraySetBit(&(StackPool->AvailabilityMap), (Os_BitArrayIndexType)index);                                    /* SBSW_OS_FC_PRECONDITION */
    }
  }

  /* #30 Set access counters to configured values. */
  {
    Os_ObjIdxType index;

    for(index = 0; index < (Os_ObjIdxType)OS_APPID_COUNT; index++)
    {
      StackPool->Dyn->AccessCounter[index] = StackPool->AccessCounter[index];                                           /* SBSW_OS_SF_SERVICESTACKPOOL_ACCESSCOUNTER_001 */
    }
  }
}


/***********************************************************************************************************************
 *  Os_ServiceCheckTfId()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_ServiceCheckTfId,
(
  TrustedFunctionIndexType Id
))
{
  return Os_ErrIsValueLo((uint32)Id, (uint32)OS_TRUSTEDFUNCTIONID_COUNT);
}


/***********************************************************************************************************************
 *  Os_ServiceCheckNtfId()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_ServiceCheckNtfId,
(
  Os_NonTrustedFunctionIndexType Id
))
{
  return Os_ErrIsValueLo((uint32)Id, (uint32)OS_NONTRUSTEDFUNCTIONID_COUNT);
}


/***********************************************************************************************************************
 *  Os_ServiceCheckFtfId()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* COV_OS_UNSUPPORTED93813 */
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_ServiceCheckFtfId,
(
  Os_FastTrustedFunctionIndexType Id
))                                                                                                                      /* COV_OS_UNSUPPORTED93813 */
{
  return Os_ErrIsValueLo((uint32)Id, (uint32)OS_FASTTRUSTEDFUNCTIONID_COUNT);
}


/***********************************************************************************************************************
 *  Os_ServiceCheckIsAccessible()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_ServiceCheckIsAccessible,
(
  P2CONST(Os_ServiceConfigType, AUTOMATIC, OS_CONST) ServiceFunction
))
{
  Os_StdReturnType accessible = !OS_CHECK_FAILED;                                                                       /* PRQA S 4404, 4558 */  /* MD_Os_C90BooleanCompatibility, MD_Os_Rule10.1_4558 */

  /* #10 If the application is not accessible, the service function is not accessible. */
  if(OS_UNLIKELY(Os_AppCheckIsAccessible(ServiceFunction->OwnerApplication) == OS_CHECK_FAILED))                        /* SBSW_OS_SF_APPCHECKISACCESSIBLE_001 */
  {
    accessible = OS_CHECK_FAILED;
    /* #30 The service function is nevertheless accessible, if called during pre start phase. */
    if(OS_UNLIKELY(Os_CoreOsIsPrestarted(Os_AppGetCore(ServiceFunction->OwnerApplication)) != 0u))                      /* SBSW_OS_SF_COREOSISPRESTARTED_001 */ /* SBSW_OS_SF_APPGETCORE_001 */
    {
      accessible = !OS_CHECK_FAILED;                                                                                    /* PRQA S 4404, 4558 */  /* MD_Os_C90BooleanCompatibility, MD_Os_Rule10.1_4558 */
    }
  }

  return accessible;
}


/***********************************************************************************************************************
 *  Os_ServiceStackPoolCheckIsAllowedToGet()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_ServiceStackPoolCheckIsAllowedToGet,
(
  P2CONST(Os_ServiceStackPoolConfigType, AUTOMATIC, OS_CONST) StackPool,
  ApplicationType CurrentApplication
))
{
  return (Os_StdReturnType)(StackPool->Dyn->AccessCounter[CurrentApplication] > 0u);                                    /* PRQA S 2842, 4304 */ /* MD_Os_Rule18.1_2842, MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_ServiceTfId2Tf()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE P2CONST(Os_ServiceTfConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_ServiceTfId2Tf,
(
  TrustedFunctionIndexType Id
))
{
  Os_Assert(Os_ErrIsValueLo((uint32)Id, (uint32)OS_TRUSTEDFUNCTIONID_COUNT));
  return OsCfg_TrustedFunctionRefs[Id];
}


/***********************************************************************************************************************
 *  Os_ServiceNtfId2Ntf()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE P2CONST(Os_ServiceNtfConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_ServiceNtfId2Ntf,
(
  Os_NonTrustedFunctionIndexType Id
))
{
  Os_Assert(Os_ErrIsValueLo((uint32)Id, (uint32)OS_NONTRUSTEDFUNCTIONID_COUNT));
  return OsCfg_NonTrustedFunctionRefs[Id];
}


/***********************************************************************************************************************
 *  Os_ServiceFtfId2Ftf()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* COV_OS_UNSUPPORTED93813 */
OS_LOCAL_INLINE P2CONST(Os_ServiceFtfConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_ServiceFtfId2Ftf,
(
  Os_FastTrustedFunctionIndexType Id
))                                                                                                                      /* COV_OS_UNSUPPORTED93813 */
{
  Os_Assert(Os_ErrIsValueLo((uint32)Id, (uint32)OS_FASTTRUSTEDFUNCTIONID_COUNT));
  return OsCfg_FastTrustedFunctionRefs[Id];
}


/***********************************************************************************************************************
 *  Os_ServiceIsTf()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
Os_ServiceIsTf,
(
  P2CONST(Os_ServiceConfigType, AUTOMATIC, OS_CONST) Service
))                                                                                                                      /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
{
  return (Os_StdReturnType)(Service->ServiceType == OS_SERVICE_TRUSTEDFUNCTION);                                        /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_ServiceIsNtf()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_ServiceIsNtf,
(
  P2CONST(Os_ServiceConfigType, AUTOMATIC, OS_CONST) Service
))
{
  return (Os_StdReturnType)(Service->ServiceType == OS_SERVICE_NONTRUSTEDFUNCTION);                                     /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_Service2Tf()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
OS_LOCAL_INLINE P2CONST(Os_ServiceTfConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_Service2Tf,
(
  P2CONST(Os_ServiceConfigType, AUTOMATIC, OS_CONST) Service
))                                                                                                                      /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
{
  Os_Assert(Os_ServiceIsTf(Service));                                                                                   /* SBSW_OS_FC_PRECONDITION */
  return (P2CONST(Os_ServiceTfConfigType, AUTOMATIC, OS_CONST)) Service;                                                /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  Os_Service2Ntf()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE P2CONST(Os_ServiceNtfConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_Service2Ntf,
(
  P2CONST(Os_ServiceConfigType, AUTOMATIC, OS_CONST) Service
))
{
  Os_Assert(Os_ServiceIsNtf(Service));                                                                                  /* SBSW_OS_FC_PRECONDITION */
  return (P2CONST(Os_ServiceNtfConfigType, AUTOMATIC, OS_CONST)) Service;                                               /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  Os_ServiceCall2NtfCall()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE P2VAR(Os_ServiceNtfCallType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE, OS_ALWAYS_INLINE,
Os_ServiceCall2NtfCall,
(
  P2VAR(Os_ServiceCallType, AUTOMATIC, OS_VAR_NOINIT) ServiceCall
))
{
  Os_Assert((Os_StdReturnType)(ServiceCall->Service->ServiceType == OS_SERVICE_NONTRUSTEDFUNCTION));                    /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
  return (P2VAR(Os_ServiceNtfCallType, AUTOMATIC, OS_VAR_NOINIT)) ServiceCall;                                          /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  Os_ServiceTrustedFunctionNeedsModeSwitch()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_ServiceTfNeedsModeSwitch,
(
  P2CONST(Os_ServiceTfConfigType, AUTOMATIC, OS_CONST) TrustedFunction
))
{
  return ((Os_StdReturnType)(TrustedFunction->Context != NULL_PTR));                                                    /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_ServicePrologue()
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
OS_LOCAL_INLINE FUNC(void, OS_CODE) Os_ServicePrologue
(
  P2VAR(Os_ServiceCallType, AUTOMATIC, OS_VAR_NOINIT) ServiceCall,
  P2CONST(Os_ServiceConfigType, AUTOMATIC, OS_CONST) Service,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) CurrentThread
)
{
  /* #10 Set service of given call to given service. */
  ServiceCall->Service = Service;                                                                                       /* SBSW_OS_PWA_PRECONDITION */

  /* #20 Save current application. */
  ServiceCall->PrevApplication = Os_ThreadGetCurrentApplication(CurrentThread);                                         /* SBSW_OS_PWA_PRECONDITION */ /* SBSW_OS_FC_PRECONDITION */

  /* #30 Save current memory protection settings. */
  ServiceCall->PrevMpAccessRights = Os_ThreadGetMpAccessRights(CurrentThread);                                          /* SBSW_OS_PWA_PRECONDITION */ /* SBSW_OS_FC_PRECONDITION */

  /* #40 Save current stack. */
  /* ServiceCall->PrevStack = Thread->Dyn->Stack <- For software based stack checks. */

  /* #50 Save current list of service calls. */
  ServiceCall->PrevServiceCalls = Os_ThreadGetServiceCalls(CurrentThread);                                              /* SBSW_OS_PWA_PRECONDITION */ /* SBSW_OS_FC_PRECONDITION */

  /* #60 Set current application to service's owner application. */
  Os_ThreadSetCurrentApplication(CurrentThread, Service->OwnerApplication);                                             /* SBSW_OS_SF_THREADSETCURRENTAPPLICATION_001 */

  /* #70 Set memory protection settings to service's memory protection settings. */
  Os_ThreadSetMpAccessRights(CurrentThread, Service->MpAccessRights);                                                   /* SBSW_OS_SF_THREADSETMPACCESSRIGHTS_001 */
  Os_MpSwitch(ServiceCall->PrevMpAccessRights, Service->MpAccessRights);                                                /* SBSW_OS_SF_MPSWITCH_001 */

  /* #80 Set stack monitoring stack to service's stack. */
  /* Thread->Dyn->Stack = Service->Stack <- For software based stack checks. */

  /* #90 Set service call list to new start of list. */
  Os_ThreadSetServiceCalls(CurrentThread, ServiceCall);                                                                 /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_ServiceEpilogue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_LOCAL_INLINE FUNC(void, OS_CODE) Os_ServiceEpilogue
(
  P2CONST(Os_ServiceCallType, AUTOMATIC, OS_VAR_NOINIT) ServiceCall,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) CurrentThread
)
{
  /* #10 Restore current application. */
  Os_ThreadSetCurrentApplication(CurrentThread, ServiceCall->PrevApplication);                                          /* SBSW_OS_SF_THREADSETCURRENTAPPLICATION_002 */

  /* #20 Restore memory protection settings. */
  Os_ThreadSetMpAccessRights(CurrentThread, ServiceCall->PrevMpAccessRights);                                           /* SBSW_OS_SF_THREADSETMPACCESSRIGHTS_002 */
  Os_MpSwitch(ServiceCall->Service->MpAccessRights, ServiceCall->PrevMpAccessRights);                                   /* SBSW_OS_SF_MPSWITCH_002 */

  /*! \note Restore current stack. */
  /* Thread->Dyn->Stack = ServiceCall->PrevStack <- For software based stack checks. */

  /* #30 Restore list of service calls. */
  Os_ThreadSetServiceCalls(CurrentThread, ServiceCall->PrevServiceCalls);                                               /* SBSW_OS_SF_THREADSETSERVICECALLS_001 */
}


/***********************************************************************************************************************
 *  Os_ServiceStackPoolGetStack()
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
 */
OS_LOCAL_INLINE FUNC(P2CONST( Os_ServiceStackConfigType, AUTOMATIC, OS_CONST), OS_CODE) Os_ServiceStackPoolGetStack
(
  P2CONST(Os_ServiceStackPoolConfigType, AUTOMATIC, OS_CONST) StackPool,
  ApplicationType CurrentApplication
)
{
  P2CONST( Os_ServiceStackConfigType, AUTOMATIC, OS_CONST) stack;
  Os_BitArrayIndexType index;

  /* #10 Check whether the current application is allowed to get a stack from the given pool. */
  Os_Assert(Os_ErrIsValueLo((uint32)CurrentApplication, (uint32)OS_APPID_COUNT));

  /* #20 Find first free stack. */
  index = Os_BitArrayCountLeadingZeros(&StackPool->AvailabilityMap);                                                    /* SBSW_OS_FC_PRECONDITION */

  /* #30 If there is no empty stack left:*/
  if(OS_UNLIKELY(index >= StackPool->StackCount))
  {
    /* #40 Return NULL pointer.*/
    stack = NULL_PTR;
  }
  /* #50 Otherwise: */
  else
  {
    /* #60 Mark the stack as occupied. */
    Os_BitArrayClearBit(&StackPool->AvailabilityMap, index);                                                            /* SBSW_OS_FC_PRECONDITION */

    /* #70 Decrement access counter of current application. */
    StackPool->Dyn->AccessCounter[CurrentApplication]--;                                                                /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */ /* SBSW_OS_SF_ACCESSCOUNTER_001 */

    /* #80 Return pointer to stack object. */
    stack = &(StackPool->Stacks[index]);
  }

  return stack;
}


/***********************************************************************************************************************
 *  Os_ServiceStackPoolReleaseStack()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_LOCAL_INLINE FUNC(void, OS_CODE) Os_ServiceStackPoolReleaseStack
(
  P2CONST(Os_ServiceStackPoolConfigType, AUTOMATIC, OS_CONST) StackPool,
  P2CONST( Os_ServiceStackConfigType, AUTOMATIC, OS_CONST) Stack,
  ApplicationType Application
)
{
  /* #10 Mark stack as free. */
  Os_BitArraySetBit(&(StackPool->AvailabilityMap), Stack->PoolIndex);                                                   /* SBSW_OS_FC_PRECONDITION */

  /* #20 Increment access counter of the given application. */
  StackPool->Dyn->AccessCounter[Application]++;                                                                         /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */ /* SBSW_OS_SF_ACCESSCOUNTER_001 */
}


/***********************************************************************************************************************
 *  Os_ServiceTfCall()
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
 *
 *
 *
 *
 *
 *
 *
 *
 */
OS_LOCAL_INLINE FUNC(Os_StatusType, OS_CODE) Os_ServiceTfCall
(
  P2CONST(Os_ServiceTfConfigType, AUTOMATIC, OS_CONST) TrustedFunction,
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) localCore;
  Os_ServiceCallType serviceCall;
  Os_IntStateType interruptState;
  Os_Hal_IntStateType userInterruptState;

  currentThread = Os_CoreGetThread();
  localCore = Os_ThreadGetCore(currentThread);                                                                          /* SBSW_OS_SF_THREADGETCORE_001 */

  /* #10 Store current interrupt state. */
  Os_Hal_IntGetInterruptState(&userInterruptState);                                                                     /* SBSW_OS_FC_POINTER2LOCAL */

  /* #20 Suspend interrupts. */
  Os_IntSuspend(&interruptState);                                                                                       /* SBSW_OS_FC_POINTER2LOCAL */

  /* #30 Check whether the service is accessible. */
  if(OS_UNLIKELY(Os_ServiceCheckIsAccessible(&(TrustedFunction->Base)) == OS_CHECK_FAILED))                             /* SBSW_OS_SF_SERVICECHECKISACCESSIBLE_001 */ /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
  {
    status = OS_STATUS_NOTACCESSIBLE_1;
  }
  else
  {
    volatile Os_StdReturnType hasTpDelay;

    hasTpDelay = Os_AppHasTimingProtectionDelay(TrustedFunction->Base.OwnerApplication);                                /* SBSW_OS_SF_APPHASTIMINGPROTECTIONDELAY_001 */

    /* #40 If the owner application of the trusted function has delayed timing protection configured. */
    if(hasTpDelay != 0u)                                                                                                /* COV_OS_HALPLATFORMTPUNSUPPORTED_XF */
    {
      /* #50 Tell timing protection to start delay violations. */
      Os_TpStartDelay(Os_CoreAsrGetTimingProtection(localCore));                                                        /* SBSW_OS_SF_TPSTARTDELAY_001 */ /* SBSW_OS_SF_COREASRGETTIMINGPROTECTION_001 */
    }

    /* #60 General service function prologue. */
    Os_ServicePrologue(&serviceCall, &(TrustedFunction->Base), currentThread);                                          /* SBSW_OS_SF_SERVICEPROLOGUE_001 */

    /* #70 Trusted function specific call behavior. */
    {
      /* #80 If the trusted function needs a mode switch: */
      if(Os_ServiceTfNeedsModeSwitch(TrustedFunction) != 0u)                                                            /* SBSW_OS_FC_PRECONDITION */
      {
        /* #90 Marshal trusted function parameters. */
        serviceCall.Parameters.TrustedFunctionParameters.FunctionIndex = FunctionIndex;
        serviceCall.Parameters.TrustedFunctionParameters.FunctionParams = FunctionParams;

        /* #100 Switch to prepared context. */
        Os_ThreadCallContext(currentThread, TrustedFunction->Context, &serviceCall, &userInterruptState,                /* PRQA S 0315 */ /* MD_Os_Dir1.1_0315 */ /* SBSW_OS_SF_THREADCALLCONTEXT_001 */
                             &(serviceCall.CallerContext), &(serviceCall.ServiceCallContext));
      }
      /* #110 Otherwise: */
      else
      {
        /* #120 Resume interrupts. */
        Os_IntResume(&interruptState);                                                                                  /* SBSW_OS_FC_POINTER2LOCAL */

        /* #130 Call the trusted function directly. */
        TrustedFunction->Callback(FunctionIndex, FunctionParams);                                                       /* SBSW_OS_SF_CALLBACK_001 */
      }
    }

    /* #140 Suspend interrupts. */
    Os_IntSuspend(&interruptState);                                                                                     /* SBSW_OS_FC_POINTER2LOCAL */

    /* #150 General service function epilogue. */
    Os_ServiceEpilogue(&serviceCall, currentThread);                                                                    /* SBSW_OS_SF_SERVICEEPILOGUE_001 */

    /* #160 If the owner application of the trusted function has delayed timing protection configured. */
    if(hasTpDelay != 0u)                                                                                                /* COV_OS_HALPLATFORMTPUNSUPPORTED_XF */
    {
      /* #170 Tell timing protection to stop delay violations. */
      Os_TpStopDelay(Os_CoreAsrGetTimingProtection(localCore));                                                         /* SBSW_OS_SF_TPSTOPDELAY_001 */ /* SBSW_OS_SF_COREASRGETTIMINGPROTECTION_001 */
    }

    status = OS_STATUS_OK;
  }

  /* #180 Resume interrupts. */
  Os_IntResume(&interruptState);                                                                                        /* SBSW_OS_FC_POINTER2LOCAL */

  return status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_ServiceNtfCall()
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
 *
 *
 */
OS_LOCAL_INLINE FUNC(Os_StatusType, OS_CODE) Os_ServiceNtfCall
(
  P2CONST(Os_ServiceNtfConfigType, AUTOMATIC, OS_CONST) NonTrustedFunction,
  Os_NonTrustedFunctionIndexType FunctionIndex,
  Os_NonTrustedFunctionParameterRefType FunctionParams
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;
  Os_IntStateType interruptState;
  Os_ServiceNtfCallType ntfCall;
  ApplicationType currentApplication;
  Os_Hal_IntStateType userInterruptState;

  currentThread = Os_CoreGetThread();
  currentApplication = Os_AppGetId(Os_ThreadGetCurrentApplication(currentThread));                                      /* SBSW_OS_SF_APPGETID_001 */ /* SBSW_OS_SF_THREADGETCURRENTAPPLICATION_001 */

  /* #10 Store current interrupt state. */
  Os_Hal_IntGetInterruptState(&userInterruptState);                                                                     /* SBSW_OS_FC_POINTER2LOCAL */

  /* #20 Suspend interrupts. */
  Os_IntSuspend(&interruptState);                                                                                       /* SBSW_OS_FC_POINTER2LOCAL */

  /* #30 Check whether the service is accessible. */
  if(OS_UNLIKELY(Os_ServiceCheckIsAccessible(&(NonTrustedFunction->Base)) == OS_CHECK_FAILED))                          /* SBSW_OS_SF_SERVICECHECKISACCESSIBLE_001 */ /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
  {
    status = OS_STATUS_NOTACCESSIBLE_1;
  }
  else if(OS_UNLIKELY(Os_ServiceStackPoolCheckIsAllowedToGet(NonTrustedFunction->StackPool, currentApplication)         /* SBSW_OS_SF_SERVICESTACKPOOLCHECKISALLOWEDTOGET_001 */
                                                      == OS_CHECK_FAILED))
  {
    status = OS_STATUS_NO_NTFSTACK_APPLIMIT_EXCEEDED;
  }
  else
  {
    /* #40 Get a stack from the pool. */
    ntfCall.Stack = Os_ServiceStackPoolGetStack(NonTrustedFunction->StackPool, currentApplication);                     /* SBSW_OS_SF_SERVICESTACKPOOLGETSTACK_001 */

    if(OS_UNLIKELY(ntfCall.Stack == NULL_PTR))
    {
      status = OS_STATUS_NO_NTFSTACK_POOL_EMPTY;
    }
    /* #50 If there was a stack available: */
    else
    {
      /* #60 General service call behavior. */
      Os_ServicePrologue(&(ntfCall.Base), &(NonTrustedFunction->Base), currentThread);                                  /* SBSW_OS_SF_SERVICEPROLOGUE_001 */

      /* #80 Marshal non-trusted function parameters. */
      ntfCall.Base.Parameters.NonTrustedFunctionParameters.FunctionIndex = FunctionIndex;
      ntfCall.Base.Parameters.NonTrustedFunctionParameters.FunctionParams = FunctionParams;

      /* #90 Call thread function for context call on defined stack. */
      Os_ThreadCallContextOnStack(currentThread, NonTrustedFunction->Context, ntfCall.Stack->HwConfig,                  /* SBSW_OS_SF_THREADCALLCONTEXTONSTACK_001 */
                                  &(ntfCall), &userInterruptState, &(ntfCall.Base.CallerContext),                       /* PRQA S 0315 */ /* MD_Os_Dir1.1_0315 */
                                  &(ntfCall.Base.ServiceCallContext));

      /* #100 Suspend interrupts. */
      Os_IntSuspend(&interruptState);                                                                                   /* SBSW_OS_FC_POINTER2LOCAL */

      /* #110 General service return behavior. */
      Os_ServiceEpilogue(&ntfCall.Base, currentThread);                                                                 /* SBSW_OS_SF_SERVICEEPILOGUE_001 */

      /* #120 Release the stack. */
      Os_ServiceStackPoolReleaseStack(NonTrustedFunction->StackPool, ntfCall.Stack, currentApplication);                /* SBSW_OS_SF_SERVICESTACKPOOLRELEASESTACK_001 */


      status = OS_STATUS_OK;
    }
  }

  /* #130 Resume interrupts. */
  Os_IntResume(&interruptState);                                                                                        /* SBSW_OS_FC_POINTER2LOCAL */

  return status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_ServiceFtfCall()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_LOCAL_INLINE FUNC(Os_StatusType, OS_CODE) Os_ServiceFtfCall                                                          /* COV_OS_UNSUPPORTED93813 */
(
  P2CONST(Os_ServiceFtfConfigType, AUTOMATIC, OS_CONST) FastTrustedFunction,
  Os_FastTrustedFunctionIndexType FunctionIndex,
  Os_FastTrustedFunctionParameterRefType FunctionParams
)                                                                                                                       /* COV_OS_UNSUPPORTED93813 */
{
  /* #10 Call the trusted function directly. */
  FastTrustedFunction->Callback(FunctionIndex, FunctionParams);                                                         /* SBSW_OS_SF_CALLBACK_001 */

  return OS_STATUS_OK;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_ServiceInitInternal()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_ServiceInitInternal
(
  P2CONST(Os_ServiceConfigType, AUTOMATIC, OS_CONST) Service
)
{
  /* #10 If the given service is a non-trusted function: */
  if(Os_ServiceIsNtf(Service) != 0u)                                                                                    /* SBSW_OS_FC_PRECONDITION */
  {
    /* #20 Initialize the non-trusted function. */
    Os_ServiceNtfInit(Os_Service2Ntf(Service));                                                                         /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */ /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_SF_SERVICENTFINIT_001 */
  }
}

/***********************************************************************************************************************
 *  Os_ServiceNtfInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_LOCAL_INLINE FUNC(void, OS_CODE) Os_ServiceNtfInit
(
  P2CONST(Os_ServiceNtfConfigType, AUTOMATIC, OS_CONST) NonTrustedFunction
)
{
  /* #10 If non-trusted functions have been configured: */
  if(Os_ServiceNtfIsEnabled() != 0u)
  {
    /* #20 Initialize the stack pool. */
    Os_ServiceStackPoolInit(NonTrustedFunction->StackPool);                                                             /* SBSW_OS_SF_SERVICESTACKPOOLINIT_001 */
  }
}


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_ServiceReturn()
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
OS_FUNC_ATTRIBUTE_DEFINITION(void, OS_CODE, OS_NORETURN, Os_ServiceReturn, (void))
{
  Os_StdReturnType tfEnabled = Os_ServiceTfIsEnabled();
  Os_StdReturnType ntfEnabled = Os_ServiceNtfIsEnabled();

  /* #10 If the module is enabled: */
  /* A logical OR instead of a bitwise OR would be more meaningful here.
   * But some compilers would complain about known decision outcome.
   * Moving the calls directly into the decision would solve this, but MISRA will complain about possible sideeffects
   * of the second call. The bitwise OR leads to correct functionality and overcomes both issues. */
  if((ntfEnabled | tfEnabled) != 0u)
  {
    P2VAR(Os_ServiceCallType, AUTOMATIC, OS_VAR_NOINIT) serviceCall;
    Os_Hal_IntStateType userInterruptState;
    Os_Hal_ContextType callerContext;

    /* #15 Store current interrupt state. */
    Os_Hal_IntGetInterruptState(&userInterruptState);                                                                   /* SBSW_OS_FC_POINTER2LOCAL */

    /* #20 Get the service call. */
    serviceCall = Os_ThreadGetServiceCalls(Os_CoreGetThread());                                                         /* SBSW_OS_SF_THREADGETSERVICECALLS_001 */

    /* #30 Get a copy of the caller context. Hint: A copy is needed because the context may be on a different stack.
     *     Stack protection would prevent write access. */
    callerContext = serviceCall->CallerContext;

    /* #40 Set the interrupt state of the caller context. */
    Os_Hal_ContextSetInterruptState(&callerContext, &userInterruptState);                                               /* SBSW_OS_FC_POINTER2LOCAL */

    /* #50 Disable interrupts. */
    Os_IntDisable();

    /* #60 Return to caller context. */
    Os_Hal_ContextReturn(serviceCall->ServiceCallContext, &callerContext);                                              /* SBSW_OS_FC_POINTER2LOCAL */
  }

  /* #70 KernelPanic. */
  Os_ErrKernelPanic();
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_ServiceTfWrapper()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(void, OS_CODE, OS_NORETURN,
Os_ServiceTfWrapper,
(
  P2CONST(Os_ServiceCallType, AUTOMATIC, OS_VAR_NOINIT) ServiceCall
))
{
  /* #10 If module is not enabled, KernelPanic. */
  if(Os_ServiceTfIsEnabled() == 0u)                                                                                     /* COV_OS_INVSTATE */
  {
    Os_ErrKernelPanic();
  }
  /* #20 Otherwise: */
  else
  {
    /* #30 Unmarshal service call details and call service with given service parameters. */
    Os_Service2Tf(ServiceCall->Service)->Callback(                                                                      /* SBSW_OS_SF_SERVICE2TF_001 */ /* SBSW_OS_SF_SERVICE_CALLBACK_001 */
        ServiceCall->Parameters.TrustedFunctionParameters.FunctionIndex,
        ServiceCall->Parameters.TrustedFunctionParameters.FunctionParams
    );

    /* #40 Return from service. */
    Os_TrapServiceReturn();
  }
}


/***********************************************************************************************************************
 *  Os_ServiceNtfWrapper()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(void, OS_CODE, OS_NORETURN,                                                                /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
Os_ServiceNtfWrapper,
(
  P2CONST(Os_ServiceCallType, AUTOMATIC, OS_VAR_NOINIT) ServiceCall
))                                                                                                                      /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
{
  /* #10 If module is not enabled, KernelPanic. */
  if(Os_ServiceNtfIsEnabled() == 0u)                                                                                    /* COV_OS_INVSTATE */
  {
    Os_ErrKernelPanic();
  }
  /* #20 Otherwise: */
  else
  {
    /* #30 Unmarshal service call details and call service with given service parameters. */
    Os_Service2Ntf(ServiceCall->Service)->Callback(                                                                     /* SBSW_OS_SF_SERVICE2NTF_001 */ /* SBSW_OS_SF_SERVICE_CALLBACK_002 */
        ServiceCall->Parameters.NonTrustedFunctionParameters.FunctionIndex,
        ServiceCall->Parameters.NonTrustedFunctionParameters.FunctionParams
    );

    /* #40 Return from service. */
    Os_TrapServiceReturn();
  }
}


/***********************************************************************************************************************
 *  Os_ServiceCallForceRelease()
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
FUNC(void, OS_CODE) Os_ServiceCallForceRelease
(
  P2VAR(Os_ServiceCallListType, AUTOMATIC, OS_VAR_NOINIT) ServiceCalls
)
{
  Os_StdReturnType tfEnabled = Os_ServiceTfIsEnabled();
  Os_StdReturnType ntfEnabled = Os_ServiceNtfIsEnabled();

  /* #10 If the module is enabled: */
  /* A logical OR instead of a bitwise OR would be more meaningful here.
   * But some compilers would complain about known decision outcome.
   * Moving the calls directly into the decision would solve this, but MISRA will complain about possible sideeffects
   * of the second call. The bitwise OR leads to correct functionality and overcomes both issues. */
  if((ntfEnabled | tfEnabled) != 0u)
  {
    P2VAR(Os_ServiceCallType, AUTOMATIC, OS_VAR_NOINIT) serviceCall;

    serviceCall = *ServiceCalls;

    /* #15 For each service call: */
    while(serviceCall != OS_SERVICECALL_LIST_END)
    {
      /* #20 If the service call is a NTF: */
      if(Os_ServiceIsNtf(serviceCall->Service) != 0u)                                                                   /* SBSW_OS_SF_SERVICEISNTF_001 */
      {
        P2CONST(Os_ServiceStackPoolConfigType, AUTOMATIC, OS_CONST) stackPool;
        P2CONST( Os_ServiceStackConfigType, AUTOMATIC, OS_CONST) stack;
        ApplicationType appId;

        stackPool = Os_Service2Ntf(serviceCall->Service)->StackPool;                                                    /* SBSW_OS_SF_SERVICE2NTF_002 */
        stack = Os_ServiceCall2NtfCall(serviceCall)->Stack;                                                             /* SBSW_OS_SF_SERVICECALL2NTFCALL_001 */

        appId = Os_AppGetId(serviceCall->PrevApplication);                                                              /* SBSW_OS_SF_APPGETID_002 */

        /* #30 Release the stack which has been occupied by the NTF call. */
        Os_ServiceStackPoolReleaseStack(stackPool, stack, appId);                                                       /* SBSW_OS_SF_SERVICESTACKPOOLRELEASESTACK_002 */
      }
      /* #40 For other services there is nothing to release. */

      serviceCall = serviceCall->PrevServiceCalls;
    }

    /* #50 Set list pointer to empty. */
    Os_ServiceCallsInit(ServiceCalls);                                                                                  /* SBSW_OS_FC_PRECONDITION */
  }
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_Api_CallTrustedFunction()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_Api_CallTrustedFunction
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

  currentThread = Os_CoreGetThread();

  /* #10 Perform error checks. */
  if(Os_ServiceTfIsEnabled() == 0u)
  {
    status = Os_ErrSetOkInStdStatus(OS_STATUS_SERVICEID);
  }
  else if(OS_UNLIKELY(Os_ServiceCheckTfId(FunctionIndex) == OS_CHECK_FAILED))                                           /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
  {
    status = OS_STATUS_SERVICEID;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckCallContext(currentThread, OS_APICONTEXT_CALLTRUSTEDFUNCTION) == OS_CHECK_FAILED))  /* COV_OS_HALPLATFORMTESTEDASMULTICORE */ /* SBSW_OS_SF_THREADCHECKCALLCONTEXT_001 */
  {
    status = OS_STATUS_CALLEVEL;
  }
  else
  {
    P2CONST(Os_ServiceTfConfigType, AUTOMATIC, OS_CONST) trustedFunction;
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) ownerCore;

    trustedFunction = Os_ServiceTfId2Tf(FunctionIndex);
    ownerCore = Os_AppGetCore(trustedFunction->Base.OwnerApplication);                                                  /* SBSW_OS_SF_APPGETCORE_002 */

    if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(ownerCore) == OS_CHECK_FAILED))                                           /* SBSW_OS_SF_COREASRCHECKISCORELOCAL_001 */ /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
    {
      status = OS_STATUS_ACCESSRIGHTS_1;
    }
    else
    {
      /* #20 Call behavior for trusted function calls. */
      status = Os_ServiceTfCall(trustedFunction, FunctionIndex, FunctionParams);                                        /* SBSW_OS_SF_SERVICETFCALL_001 */
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_Api_CallNonTrustedFunction()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_Api_CallNonTrustedFunction
(
  Os_NonTrustedFunctionIndexType FunctionIndex,
  Os_NonTrustedFunctionParameterRefType FunctionParams
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

  currentThread = Os_CoreGetThread();

  /* #10 Perform error checks. */
  if(Os_ServiceNtfIsEnabled() == 0u)
  {
    status = Os_ErrSetOkInStdStatus(OS_STATUS_SERVICEID);
  }
  else if(OS_UNLIKELY(Os_ServiceCheckNtfId(FunctionIndex) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_SERVICEID;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckCallContext(currentThread, OS_APICONTEXT_CALLNONTRUSTEDFUNCTION)                    /* COV_OS_HALPLATFORMTESTEDASMULTICORE */ /* SBSW_OS_SF_THREADCHECKCALLCONTEXT_001 */
      == OS_CHECK_FAILED))
  {
    status = OS_STATUS_CALLEVEL;
  }
  else
  {
    P2CONST(Os_ServiceNtfConfigType, AUTOMATIC, OS_CONST) nonTrustedFunction;
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) ownerCore;

    nonTrustedFunction = Os_ServiceNtfId2Ntf(FunctionIndex);
    ownerCore = Os_AppGetCore(nonTrustedFunction->Base.OwnerApplication);                                               /* SBSW_OS_SF_APPGETCORE_001 */

    if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(ownerCore) == OS_CHECK_FAILED))                                           /* SBSW_OS_SF_COREASRCHECKISCORELOCAL_001 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
    {
      status = OS_STATUS_ACCESSRIGHTS_1;
    }
    else
    {
      /* #20 Call behavior for non-trusted function calls. */
      status = Os_ServiceNtfCall(nonTrustedFunction, FunctionIndex, FunctionParams);                                    /* SBSW_OS_SF_SERVICENTFCALL_001 */
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_Api_CallFastTrustedFunction()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_Api_CallFastTrustedFunction                                                             /* COV_OS_UNSUPPORTED93813 */
(
  Os_FastTrustedFunctionIndexType FunctionIndex,
  Os_FastTrustedFunctionParameterRefType FunctionParams
)                                                                                                                       /* COV_OS_UNSUPPORTED93813 */
{
  Os_StatusType status;

  /* #10 Perform error checks. */
  if(Os_ServiceFtfIsEnabled() == 0u)                                                                                    /* COV_OS_UNSUPPORTED93813 */
  {
    status = Os_ErrSetOkInStdStatus(OS_STATUS_SERVICEID);
  }
  else if(OS_UNLIKELY(Os_ServiceCheckFtfId(FunctionIndex) == OS_CHECK_FAILED))                                          /* COV_OS_UNSUPPORTED93813 */
  {
    status = OS_STATUS_SERVICEID;
  }
  else
  {
    P2CONST(Os_ServiceFtfConfigType, AUTOMATIC, OS_CONST) fastTrustedFunction;

    fastTrustedFunction = Os_ServiceFtfId2Ftf(FunctionIndex);

    /* #20 Call behavior for fast trusted function calls. */
    status = Os_ServiceFtfCall(fastTrustedFunction, FunctionIndex, FunctionParams);                                     /* SBSW_OS_SF_SERVICEFTFCALL_001 */
  }

  return status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* module specific MISRA deviations:
 */

/* SBSW_JUSTIFICATION_BEGIN

\ID SBSW_OS_SF_SERVICESTACKPOOL_ACCESSCOUNTER_001
 \DESCRIPTION    Write access to the AccessCounter of the Dyn object of a StackPool. StackPool is passed as
                 argument to the caller. The correctness of the caller argument is ensured by precondition.
                 The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_SF_STACKPOOL_DYN_M]
                 \R [CM_OS_SF_INDEX_R]

\ID SBSW_OS_SF_APPGETCORE_001
 \DESCRIPTION    Os_AppGetCore is called with a OwnerApplication which is derived from a NonTrustedFunction.
                 NonTrustedFunction is passed as argument to the caller. The correctness of the caller argument is
                 ensured by precondition. The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_SF_OWNERAPPLICATION_M]

\ID SBSW_OS_SF_APPGETCORE_002
 \DESCRIPTION    Os_AppGetCore is called with an OwnerApplication derived from the return value of Os_ServiceTfId2Tf.
 \COUNTERMEASURE \M [CM_OS_SERVICETFID2TF_M]
                 \R [CM_OS_SERVICETFID2TF_R]
                 \M [CM_OS_SF_OWNERAPPLICATION_M]

\ID SBSW_OS_SF_COREOSISPRESTARTED_001
 \DESCRIPTION    Os_CoreOsIsPrestarted is called with the return value of Os_AppGetCore.
 \COUNTERMEASURE \M [CM_OS_APPGETCORE_M]

\ID SBSW_OS_SF_THREADSETCURRENTAPPLICATION_001
 \DESCRIPTION    Os_ThreadSetCurrentApplication is called with a OwnerApplication which is derived from a
                 Service. The Service is passed as argument to the caller. The correctness of the caller argument is
                 ensured by precondition. The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_SF_OWNERAPPLICATION_M]

\ID SBSW_OS_SF_THREADSETCURRENTAPPLICATION_002
 \DESCRIPTION    Os_ThreadSetCurrentApplication is called with a PrevApplication which is derived from a
                 ServiceCall. The ServiceCall is passed as argument to the caller. The correctness of the caller
                 argument is ensured by precondition. PrevApplication is initialized in Os_ServicePrologue. Precondition
                 ensures that Os_ServicePrologue is called before. The compliance of the preconditions is check during
                 review.
 \COUNTERMEASURE \M [CM_OS_SF_OWNERAPPLICATION_M]

\ID SBSW_OS_SF_MPSWITCH_001
 \DESCRIPTION    Os_MpSwitch is called with a MpAccessRights object and a PrevMpAccessRights object.
                 The MpAccessRights object is derived from a Service object. The PrevMpAccessRights is initialized with
                 the return value of Os_ThreadGetMpAccessRights. The PrevMpAccessRights object is derived
                 from a ServiceCall object. Service and ServiceCall are passed as argument to the caller.
                 The correctness of the caller arguments is ensured by precondition. The compliance of the precondition
                 is check during review.
 \COUNTERMEASURE \M [CM_OS_SF_MPACCESSRIGHTS_M]

\ID SBSW_OS_SF_MPSWITCH_002
 \DESCRIPTION    Os_MpSwitch is called with values derived from a ServiceCall object. This object hierarchy is
                 initialized in Os_ServicePrologue. Preconditions ensures, that Os_ServicePrologue is called before.
                 The compliance of the precondition is check during review.
 \COUNTERMEASURE \N [CM_OS_PRECONDITION_N]

\ID SBSW_OS_SF_THREADSETSERVICECALLS_001
 \DESCRIPTION    Os_ThreadSetServiceCalls is called with a CurrentThread and a PrevServiceCalls object. The
                 PrevServiceCalls object is derived from a ServiceCall object. ServiceCall and CurrentThread are
                 passed as arguments to the caller function. The correctness of the caller arguments is ensured by
                 precondition. This object hierarchy of ServiceCall is initialized in Os_ServicePrologue.
                 Preconditions ensures, that Os_ServicePrologue is called before. The compliance of the precondition
                 is check during review.
 \COUNTERMEASURE \N [CM_OS_PRECONDITION_N]

\ID SBSW_OS_SF_THREADSETMPACCESSRIGHTS_001
 \DESCRIPTION    Os_ThreadSetMpAccessRights is called with a MpAccessRights object and a CurrentThread object.
                 The MpAccessRights object is derived from a Service object. Service and CurrentThread are passed as
                 argument to the caller. The correctness of the caller arguments is ensured by precondition.
                 The compliance of the precondition
                 is check during review.
 \COUNTERMEASURE \M [CM_OS_SF_MPACCESSRIGHTS_M]
                 \T [CM_OS_THREADGETMPACCESSRIGHTS_T]

\ID SBSW_OS_SF_THREADSETMPACCESSRIGHTS_002
 \DESCRIPTION    Os_ThreadSetMpAccessRights is called with a PrevMpAccessRights object and a CurrentThread object.
                 The PrevMpAccessRights object is derived from a ServiceCall object. Service and CurrentThread are
                 passed as argument to the caller. The correctness of the caller arguments is ensured by
                 precondition. PrevMpAccessRights is initialized in Os_ServicePrologue. Precondition ensures
                 that Os_ServicePrologue is called before.  The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_SF_MPACCESSRIGHTS_M]
                 \T [CM_OS_THREADGETMPACCESSRIGHTS_T]

\ID SBSW_OS_SF_ACCESSCOUNTER_001
 \DESCRIPTION    Write access to an AccessCounter. The AccessCounter is derived with an index from an array of
                 AccessCounter. The array is derived from a Dyn object. The Dyn object is derived from a StackPool.
                 StackPool is passed as argument to the caller. The correctness of the caller argument is
                 ensured by precondition. The compliance of the precondition is check during review. The index is
                 of an enum type and therefore check by the compiler. All values of this enum are valid indices.
 \COUNTERMEASURE \M [CM_OS_SF_STACKPOOL_DYN_M]

\ID SBSW_OS_SF_APPHASTIMINGPROTECTIONDELAY_001
 \DESCRIPTION    Os_AppHasTimingProtectionDelay is called with a OwnerApplication which is derived from a
                 TrustedFunction. TrustedFunction is passed as argument to the caller. The correctness of the caller
                 argument is ensured by precondition. The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_SF_OWNERAPPLICATION_M]

\ID SBSW_OS_SF_APPCHECKISACCESSIBLE_001
 \DESCRIPTION    Os_AppCheckIsAccessible is called with a OwnerApplication which is derived from a ServiceFunction.
                 ServiceFunction is passed as argument to the caller. The correctness of the caller argument is
                 ensured by precondition. The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_SF_OWNERAPPLICATION_M]

\ID SBSW_OS_SF_COREASRGETTIMINGPROTECTION_001
 \DESCRIPTION    Os_CoreAsrGetTimingProtection is called with the return value of Os_ThreadGetCore.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_SF_SERVICEPROLOGUE_001
 \DESCRIPTION    Os_ServicePrologue is called with a pointer to the local variable, a pointer to a Base
                 object derived from an argument of the caller function and the return value of Os_CoreGetThread.
                 The correctness of the caller argument is ensured by precondition. The correctness of Os_CoreGetThread
                 is ensured by precondition. The compliance of the precondition is check during review.
 \COUNTERMEASURE \N [CM_OS_PRECONDITION_N]

\ID SBSW_OS_SF_CALLBACK_001
 \DESCRIPTION    Callback pointer is used for function pointer call. Callback is derived from an argument of the caller
                 function. The correctness of the caller argument is ensured by precondition.
 \COUNTERMEASURE \M [CM_OS_SF_TF_CALLBACKPOINTER_M]

\ID SBSW_OS_SF_SERVICEEPILOGUE_001
 \DESCRIPTION    Os_ServiceEpilogue is called with a pointer to the local variable serviceCall and the return value of
                 Os_CoreGetThread. The correctness of Os_CoreGetThread is ensured by precondition. The compliance of
                 the precondition is check during review.
 \COUNTERMEASURE \N [CM_OS_PRECONDITION_N]

\ID SBSW_OS_SF_TPSTARTDELAY_001
 \DESCRIPTION    Os_TpStartDelay is called with the return value of Os_CoreAsrGetTimingProtection.
 \COUNTERMEASURE \M [CM_OS_COREASRGETTIMINGPROTECTION_M]

\ID SBSW_OS_SF_TPSTOPDELAY_001
 \DESCRIPTION    Os_TpStopDelay is called with the return value of Os_CoreAsrGetTimingProtection.
 \COUNTERMEASURE \M [CM_OS_COREASRGETTIMINGPROTECTION_M]

\ID SBSW_OS_SF_THREADGETCURRENTAPPLICATION_001
 \DESCRIPTION    Os_ThreadGetCurrentApplication is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_SF_SERVICESTACKPOOLGETSTACK_001
 \DESCRIPTION    Os_ServiceStackPoolGetStack is called with a StackPool. StackPool is derived from an argument of the
                 caller function. The correctness of the caller argument is ensured by precondition. The compliance of
                 the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_SERVICESTACKPOOL_M]

\ID SBSW_OS_SF_SERVICESTACKPOOLRELEASESTACK_001
 \DESCRIPTION    Os_ServiceStackPoolReleaseStack is called with a StackPool and a Stack. StackPool is derived from an
                 argument of the caller function. The correctness of the caller argument is ensured by precondition.
                 The Stack is the return value of  Os_ServiceStackPoolGetStack. The compliance of the precondition is
                 check during review.
 \COUNTERMEASURE \M [CM_OS_SERVICESTACKPOOL_M]

\ID SBSW_OS_SF_SERVICESTACKPOOLRELEASESTACK_002
 \DESCRIPTION    Os_ServiceStackPoolReleaseStack is called with a StackPool derived from the return value of
                 Os_Service2Ntf and Stack derived from the return value of Os_ServiceCall2NtfCall.
 \COUNTERMEASURE \M [CM_OS_SERVICESTACKPOOL_M]
                 \R [CM_OS_SF_SERVICE2SERVICENTF_R]

\ID SBSW_OS_SF_SERVICESTACKPOOLINIT_001
 \DESCRIPTION    Os_ServiceStackPoolInit is called with a StackPool. StackPool is derived from an argument
                 of the caller function. The correctness of the caller argument is ensured by precondition.
                 The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_SERVICESTACKPOOL_M]

\ID SBSW_OS_SF_APPGETID_001
 \DESCRIPTION    Os_AppGetId is called with the return value of Os_ThreadGetCurrentApplication.
 \COUNTERMEASURE \N [CM_OS_THREADGETCURRENTAPPLICATION_N]

\ID SBSW_OS_SF_APPGETID_002
 \DESCRIPTION    Os_AppGetId is called with the PrevApplication derived from an iterator. The initial value is passed
                 as argument to the caller. The correctness of the caller argument is ensured by
                 precondition. The compliance of the precondition is check during review.
 \COUNTERMEASURE \R [CM_OS_SF_ITERATOR_R]
                 \T [CM_OS_SF_SERVICECALL_T]

\ID SBSW_OS_SF_THREADGETSERVICECALLS_001
 \DESCRIPTION    Os_ThreadGetServiceCalls is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_SF_THREADCHECKCALLCONTEXT_001
 \DESCRIPTION    Os_ThreadCheckCallContext is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_SF_THREADGETCORE_001
 \DESCRIPTION    Os_ThreadGetCore is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_SF_SERVICETFCALL_001
 \DESCRIPTION    Os_ServiceTfCall is called with the return value of Os_ServiceTfId2Tf and an argument passed to the
                 caller. The correctness of the caller argument is ensured by precondition. The compliance of the
                 precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_SERVICETFID2TF_M]
                 \R [CM_OS_SERVICETFID2TF_R]

\ID SBSW_OS_SF_SERVICEFTFCALL_001
 \DESCRIPTION    Os_ServiceFtfCall is called with the return value of Os_ServiceFtfId2Ftf and an argument passed to the
                 caller. The correctness of the caller argument is ensured by precondition. The compliance of the
                 precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_SERVICEFTFID2FTF_M]
                 \R [CM_OS_SERVICEFTFID2FTF_R]

\ID SBSW_OS_SF_COREASRCHECKISCORELOCAL_001
 \DESCRIPTION    Os_CoreAsrCheckIsCoreLocal is called with the return value of Os_AppGetCore.
 \COUNTERMEASURE \M [CM_OS_APPGETCORE_M]

\ID SBSW_OS_SF_SERVICENTFCALL_001
 \DESCRIPTION    Os_ServiceNtfCall is called with the return value of Os_ServiceNtfId2Ntf and a pointer passed as
                 argument to the caller. The correctness of the caller argument is ensured by precondition. The
                 compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_SERVICENTFID2NTF_M]

\ID SBSW_OS_SF_SERVICENTFINIT_001
 \DESCRIPTION    Os_ServiceNtfInit is called with an argument of the caller, which is converted into a more concrete
                 type. The correctness of the caller argument is ensured by precondition. The
                 compliance of the precondition is check during review.
 \COUNTERMEASURE \R [CM_OS_SF_SERVICE2SERVICENTF_R]

\ID SBSW_OS_SF_SERVICE2TF_001
 \DESCRIPTION    Os_Service2Tf called with a value derived from the return value of Os_ThreadGetServiceCalls.
 \COUNTERMEASURE \R [CM_OS_SERVICECALL_SERVICEVALUE_R]

\ID SBSW_OS_SF_SERVICE_CALLBACK_001
 \DESCRIPTION    The callback pointer of a trusted function is used for a function call which is derived from the
                 return value of Os_Service2Tf. The passed parameters are derived from the return value of
                 Os_ThreadGetServiceCalls.
 \COUNTERMEASURE \M [CM_OS_SF_TF_CALLBACK_M]
                 \M [CM_OS_SF_TF_CALLBACKPOINTER_M]
                 \T [CM_OS_SERVICE2TF_T]

\ID SBSW_OS_SF_SERVICE2NTF_001
 \DESCRIPTION    Os_Service2Ntf is called with a value derived from the return value of Os_ThreadGetServiceCalls.
 \COUNTERMEASURE \R [CM_OS_SERVICECALL_SERVICEVALUE_R]

\ID SBSW_OS_SF_SERVICE2NTF_002
 \DESCRIPTION    Os_Service2Ntf is called with a Service value derived from an iterator. The initial value is passed
                 as argument to the caller. The correctness of the caller argument is ensured by
                 precondition. The compliance of the precondition is check during review.
 \COUNTERMEASURE \R [CM_OS_SF_ITERATOR_R]
                 \T [CM_OS_SF_SERVICECALL_T]

\ID SBSW_OS_SF_SERVICECALL2NTFCALL_001
 \DESCRIPTION    Os_ServiceCall2NtfCall is called with an iterator. The initial value is passed
                 as argument to the caller. The correctness of the caller argument is ensured by
                 precondition. The compliance of the precondition is check during review.
 \COUNTERMEASURE \R [CM_OS_SF_ITERATOR_R]

\ID SBSW_OS_SF_SERVICE_CALLBACK_002
 \DESCRIPTION    The callback pointer of a non trusted function is used for a function call which is derived from
                 the return value of Os_Service2Ntf. The passed parameters are
                 derived from the return value of Os_ThreadGetServiceCalls.
 \COUNTERMEASURE \M [CM_OS_SF_NTF_CALLBACK_M]
                 \M [CM_OS_SF_NTF_CALLBACKPOINTER_M]
                 \T [CM_OS_SERVICE2NTF_T]

\ID SBSW_OS_SF_SERVICESTACKPOOLCHECKISALLOWEDTOGET_001
 \DESCRIPTION    Os_ServiceStackPoolCheckIsAllowedToGet is called with the StackPool derived from a NTF. The NTF
                 is passed as argument to the caller. The correctness of the caller argument is ensured by
                 precondition. The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_SERVICESTACKPOOL_M]

\ID SBSW_OS_SF_SERVICEISNTF_001
 \DESCRIPTION    Os_ServiceIsNtf is called with a Service value derived from an iterator. The initial value is passed
                 as argument to the caller. The correctness of the caller argument is ensured by
                 precondition. The compliance of the precondition is check during review.
 \COUNTERMEASURE \R [CM_OS_SF_ITERATOR_R]
                 \T [CM_OS_SF_SERVICECALL_T]

\ID SBSW_OS_SF_SERVICECHECKISACCESSIBLE_001
 \DESCRIPTION    Os_ServiceCheckIsAccessible is called with a pointer to a Base object derived from an argument
                 of the caller function. The correctness of the caller argument is ensured by precondition.
                 The compliance of the precondition is check during review.
 \COUNTERMEASURE \N [CM_OS_PRECONDITION_N]

\ID SBSW_OS_SF_THREADCALLCONTEXT_001
 \DESCRIPTION    Os_ThreadCallContext is called with the following arguments:
                 currentThread:
                   The return value of Os_CoreGetThread (CM_OS_COREGETTHREAD_N)
                 TrustedFunction->Context: Pointer to a Context object derived from an argument of the caller
                   function. The correctness of the caller argument is ensured by precondition.
                   The correctness of the Context pointer is ensured to be no NULL_PTR.
                 Others:
                   Four further argument pointers are derived from local objects, therefore pointers are valid.
 \COUNTERMEASURE \M [CM_OS_SF_CONTEXT_M]

\ID SBSW_OS_SF_THREADCALLCONTEXTONSTACK_001
 \DESCRIPTION    Os_ThreadCallContextOnStack is called with the following arguments:
                 currentThread:
                   The return value of Os_CoreGetThread (CM_OS_COREGETTHREAD_N)
                 NonTrustedFunction->Context:
                   Pointer to a Context object derived from an argument of the caller function.
                   The correctness of the caller argument is ensured by precondition.
                   The correctness of the Context pointer is ensured to be no NULL_PTR.
                 ntfCall.Stack->HwConfig:
                   Pointer to a stack object returned by Os_ServiceStackPoolGetStack.
                 Others:
                   Four further argument pointers are derived from local objects, therefore pointers are valid.
 \COUNTERMEASURE \M [CM_OS_SF_CONTEXT_M]
                 \R Runtime check ensures that ntfCall.Stack->HwConfig is no NULL_PTR.

SBSW_JUSTIFICATION_END */

/*
\CM CM_OS_SERVICETFID2TF_M
      The index's type correctness is checked by compiler and ensures that the given index is in range.
      If the value is retrieved from a user interface, a range check is required.
      Verify that:
        1. each TF in OsCfg_TrustedFunctionRefs is a non NULL_PTR,
        2. OsCfg_TrustedFunctionRefs has a size equal to OS_TRUSTEDFUNCTIONID_COUNT + 1 and
        3. each element in TrustedFunctionIndexType has a value lower than OS_TRUSTEDFUNCTIONID_COUNT.

\CM CM_OS_SERVICEFTFID2FTF_M
      The index's type correctness is checked by compiler and ensures that the given index is in range.
      If the value is retrieved from a user interface, a range check is required.
      Os_CallFastTrustedFunction() is a BETA feature.
      Verify that Fast Trusted Functions are not configured.

\CM CM_OS_SERVICETFID2TF_R
      Implementation ensures that the used index is in range.

\CM CM_OS_SERVICEFTFID2FTF_R
      Implementation ensures that the used index is in range.

\CM CM_OS_SERVICECALL_SERVICEVALUE_R
      Implementation ensures that the Service attribute is set before.

\CM CM_OS_SERVICENTFID2NTF_M
      Verify that:
        1. each NTF in OsCfg_NonTrustedFunctionRefs is a non NULL_PTR,
        2. OsCfg_NonTrustedFunctionRefs has a size equal to OS_NONTRUSTEDFUNCTIONID_COUNT + 1 and
        3. each element in Os_NonTrustedFunctionIndexType has a value lower than OS_NONTRUSTEDFUNCTIONID_COUNT.

\CM CM_OS_SERVICE2TF_T
      TCASE-345832 ensures that the current service call is set before call.

\CM CM_OS_SERVICE2NTF_T
      TCASE-345832 ensures that the current service call is set before call.

\CM CM_OS_SERVICESTACKPOOL_M
      Verify that:
        1. that the StackPool of each Os_ServiceNtfConfigType is non NULL_PTR,
        2. the Stacks reference of each Os_ServiceStackPoolConfigType is a non NULL_PTR,
        3. each Stacks array has a size equal to StackCount
        4. that the Stack pointer of each Stack in each StackPool is a non NULL_PTR and
        5. that the HwConfig pointer of each Stack in each StackPool is a non NULL_PTR.

\CM CM_OS_SF_STACKPOOL_DYN_M
      Verify that the Dyn pointer of each StackPoolConfigType object is a non NULL_PTR.

\CM CM_OS_SF_INDEX_R
      Caller ensures by implementation that the used index is valid.

\CM CM_OS_SF_OWNERAPPLICATION_M
      Verify that the OwnerApplication pointer of each Os_ServiceConfigType object is a non NULL_PTR.

\CM CM_OS_SF_MPACCESSRIGHTS_M
      Verify that the MpAccessRights pointer of each Os_ServiceConfigType object is a non NULL_PTR.

\CM CM_OS_SF_TF_CALLBACKPOINTER_M
      Verify that the Callback pointer of each Os_ServiceTfConfigType object is a non NULL_PTR.

\CM CM_OS_SF_NTF_CALLBACKPOINTER_M
      Verify that the Callback pointer of each Os_ServiceNtfConfigType object is a non NULL_PTR.

\CM CM_OS_SF_TF_CALLBACK_M
      Verify that the context of each trusted function, which is assigned to a non privileged application, refers
      to Os_ServiceTfWrapper and that no other object refers to Os_ServiceTfWrapper.

\CM CM_OS_SF_NTF_CALLBACK_M
      Verify that the context of each non trusted function object refers to Os_ServiceNtfWrapper and that no other
      object refers to Os_ServiceNtfWrapper.

\CM CM_OS_SF_CONTEXT_M
      Verify that the Context pointer of each Os_ServiceNtfConfigType object is a non NULL_PTR.

\CM CM_OS_SF_TF_CONTEXT_M
      Verify that the Context pointer of each Os_ServiceTfConfigType object is a non NULL_PTR.

\CM CM_OS_SF_SERVICE2SERVICENTF_R
      Ensured by implementation, that the conversion is valid.

\CM CM_OS_SF_ITERATOR_R
      Caller ensures by implementation that the used iterator is not used, in case the the iterator is a NULL_PTR.

\CM CM_OS_SF_SERVICECALL_T
      TCASE-345832 ensures that the list of service functions is correct and terminates with OS_SERVICECALL_LIST_END.
      All references of the listed services are initialized (PrevApplication, PrevMpAccessRights, PrevServiceCalls,
      and Service).
 */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_ServiceFunction.c
 **********************************************************************************************************************/
