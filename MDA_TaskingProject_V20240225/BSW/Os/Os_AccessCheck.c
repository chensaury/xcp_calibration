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
 * \addtogroup  Os_AccessCheck
 * \{
 *
 * \file
 * \brief       Function implementations of memory access rights functions.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/
                                                                                                                        /* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */


#define OS_ACCESSCHECK_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_AccessCheck_Lcfg.h"
#include "Os_AccessCheck_Cfg.h"
#include "Os_AccessCheck.h"

/* Os kernel module dependencies */
#include "Os_Common_Types.h"
#include "Os_Thread.h"
#include "Os_Isr.h"
#include "Os_Task.h"

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

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define OS_START_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  Os_AccessCheckCheckAddresses()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given addresses are valid (Not OS_CHECK_FAILED) or not (OS_CHECK_FAILED).
 *  \details        In case that extended checks are disabled, the default result of \ref Os_ErrExtendedCheck() is
 *                  returned.
 *
 *  \param[in]      AddressStart  The start address to check.
 *  \param[in]      AddressEnd    The end address to check.
 *
 *  \retval         Not OS_CHECK_FAILED   If the given addresses are valid.
 *  \retval         OS_CHECK_FAILED       If the given addresses are invalid.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_AccessCheckCheckAddresses,
(
  Os_AccessCheckAddress AddressStart,
  Os_AccessCheckAddress AddressEnd
));


/***********************************************************************************************************************
 *  Os_AccessCheckTest()
 **********************************************************************************************************************/
/*! \brief        Returns the access right of a thread for the given memory region.
 *  \details      --no details--
 *
 *  \note         Limitation: The region to be checked has to be part of a configured region. If the region to be
 *                            checked is completely covered by two or more regions, the result will be no access.
 *
 *  \param[in]    AccessRights        The access rights of the object to be checked. Parameter must not be NULL.
 *  \param[in]    Address             Start address of the memory region, the access rights shall be checked for.
 *  \param[in]    Size                The size of the memory region, the access rights shall be checked for.
 *
 *  \return       Value which contains the access rights to the given memory region.
 *  \retval       OS_MEM_ACCESS_TYPE_NON      No access or address range overflow.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE AccessType, OS_CODE, OS_ALWAYS_INLINE,
Os_AccessCheckTest,
(
  P2CONST(Os_AccessCheckConfigType, AUTOMATIC, OS_CONST) AccessRights,
  MemoryStartAddressType Address,
  MemorySizeType Size
));


/***********************************************************************************************************************
 *  Os_AccessCheckIsEnabled()
 **********************************************************************************************************************/
/*! \brief          Returns whether access check API is enabled (!0) or not (0).
 *  \details        --no details--
 *
 *  \retval         !0    Access check API is enabled.
 *  \retval         0     Access check API is disabled.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_AccessCheckIsEnabled,
(
  void
));


/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  Os_AccessCheckCheckAddresses()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_AccessCheckCheckAddresses,
(
  Os_AccessCheckAddress AddressStart,
  Os_AccessCheckAddress AddressEnd
))
{
  return Os_ErrExtendedCheck((Os_StdReturnType)(AddressStart <= AddressEnd));                                           /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_AccessCheckTest()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE AccessType, OS_CODE, OS_ALWAYS_INLINE,
Os_AccessCheckTest,
(
  P2CONST(Os_AccessCheckConfigType, AUTOMATIC, OS_CONST) AccessRights,
  MemoryStartAddressType Address,
  MemorySizeType Size
))
{
  AccessType result;
  Os_AccessCheckAddress addressStart;
  Os_AccessCheckAddress addressEnd;

  addressStart = (Os_AccessCheckAddress)Address;                                                                        /* PRQA S 0306, 0326 */ /* MD_Os_Rule11.4_0306_AccessCheckTest, MD_Os_Rule11.6_0326 */
  addressEnd = (addressStart + Size) - 1u;

  /* #10 Perform checks. */
  if(OS_UNLIKELY( Os_AccessCheckCheckAddresses(addressStart, addressEnd) == OS_CHECK_FAILED ))
  {
    result = OS_MEM_ACCESS_TYPE_NON;
  }
  else
  {
    Os_AccessCheckIdx idx;
    P2CONST(Os_AccessCheckRegionConfigType, AUTOMATIC, OS_CONST) region;

    result = OS_MEM_ACCESS_TYPE_NON;

    /* #20 Search in the access right configuration for the correct region. */
    for(idx = 0; idx < AccessRights->RegionCount; ++idx)
    {
      region = &(AccessRights->Regions[idx]);

      /* #30 If such a region was found, set the return value to its access rights. */
      if( (addressStart >= region->AddressStart) && (addressEnd <= region->AddressEnd) )
      {
        result = region->AccessRights;
        break;
      }
    }
  }

  return result;
}


/***********************************************************************************************************************
 *  Os_AccessCheckIsEnabled()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,
OS_ALWAYS_INLINE, Os_AccessCheckIsEnabled,
(
  void
))
{
  return (Os_StdReturnType)(OS_CFG_ACCESSCHECK == STD_ON);                                                              /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  Os_Api_CheckTaskMemoryAccess()
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
FUNC(AccessType, OS_CODE) Os_Api_CheckTaskMemoryAccess
(
  TaskType TaskID,
  MemoryStartAddressType Address,
  MemorySizeType Size
)
{
  AccessType result;

  /* #10 If the API is not configured, set the return value to 'no access'. */
  if(Os_AccessCheckIsEnabled() == 0u)                                                                                   /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    result = OS_MEM_ACCESS_TYPE_NON;                                                                                    /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }
  /* #15 Otherwise, if the TaskID is invalid, set the return value to 'no access'. */
  else if(OS_UNLIKELY(Os_TaskCheckId(TaskID) == OS_CHECK_FAILED))
  {
    result = OS_MEM_ACCESS_TYPE_NON;
  }
  /* #20 Otherwise: */
  else
  {
    P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) task;
    P2CONST(Os_AccessCheckConfigType, AUTOMATIC, OS_CONST) accessRights;

    /* #30 Get the tasks access rights. */
    task = Os_TaskId2Task(TaskID);
    accessRights = Os_TaskGetAccessRights(task);                                                                        /* SBSW_OS_AC_TASKGETACCESSRIGHTS_001 */

    /* #40 Set the return value to the result of OsCheckThreadMemoryAccess. */
    result = Os_AccessCheckTest(accessRights, Address, Size);                                                           /* SBSW_OS_AC_ACCESSCHECKTEST_001 */
  }

  return result;
}


/***********************************************************************************************************************
 *  Os_Api_CheckISRMemoryAccess()
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
FUNC(AccessType, OS_CODE) Os_Api_CheckISRMemoryAccess
(
  ISRType ISRID,
  MemoryStartAddressType Address,
  MemorySizeType Size
)
{
  AccessType result;

  /* #10 If the API is not configured, set the return value to 'no access'. */
  if(Os_AccessCheckIsEnabled() == 0u)                                                                                   /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    result = OS_MEM_ACCESS_TYPE_NON;                                                                                    /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }
  /* #15 Otherwise, if the ISRID is invalid, set the return value to 'no access'. */
  else if(OS_UNLIKELY(Os_IsrCheckId(ISRID) == OS_CHECK_FAILED))
  {
    result = OS_MEM_ACCESS_TYPE_NON;
  }
  /* #20 Otherwise: */
  else
  {
    P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) isr;
    P2CONST(Os_AccessCheckConfigType, AUTOMATIC, OS_CONST) accessRights;

    /* #30 Get the ISRs access rights. */
    isr = Os_IsrId2Isr(ISRID);
    accessRights = Os_IsrGetAccessRights(isr);                                                                          /* SBSW_OS_AC_ISRGETACCESSRIGHTS_001 */

    /* #40 Set the return value to the result of OsCheckThreadMemoryAccess. */
    result = Os_AccessCheckTest(accessRights, Address, Size);                                                           /* SBSW_OS_AC_ACCESSCHECKTEST_002 */
  }

  return result;
}


#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* module specific MISRA deviations:
 */

/* SBSW_JUSTIFICATION_BEGIN
\ID SBSW_OS_AC_TASKGETACCESSRIGHTS_001
 \DESCRIPTION    Os_TaskGetAccessRights is called with the return value of Os_TaskId2Task.
 \COUNTERMEASURE \M [CM_OS_TASKID2TASK_M]

\ID SBSW_OS_AC_ACCESSCHECKTEST_001
 \DESCRIPTION    Os_AccessCheckTest is called with the return value of Os_TaskGetAccessRights.
 \COUNTERMEASURE \M [CM_OS_TASKGETACCESSRIGHTS_M]

\ID SBSW_OS_AC_ISRGETACCESSRIGHTS_001
 \DESCRIPTION    Os_TaskGetAccessRights is called with the return value of Os_IsrId2Isr.
 \COUNTERMEASURE \M [CM_OS_ISRID2ISR_M]

\ID SBSW_OS_AC_ACCESSCHECKTEST_002
 \DESCRIPTION    Os_AccessCheckTest is called with the return value of Os_IsrGetAccessRights.
 \COUNTERMEASURE \M [CM_OS_ISRGETACCESSRIGHTS_M]


 SBSW_JUSTIFICATION_END */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_AccessCheck.c
 **********************************************************************************************************************/
