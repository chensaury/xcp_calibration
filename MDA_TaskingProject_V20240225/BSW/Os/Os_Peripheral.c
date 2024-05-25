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
 * \addtogroup Os_Peripheral
 * \{
 *
 * \file
 * \brief       The implementation of the peripheral subcomponent.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777, 0779, 0828  EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */


#define OS_PERIPHERAL_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Peripheral_Types.h"
#include "Os_Peripheral_Lcfg.h"
#include "Os_Peripheral.h"

/* Os kernel module dependencies */
#include "Os_Common_Types.h"
#include "Os_Error.h"
#include "Os_Thread.h"

/* Os hal dependencies */
#include "Os_Hal_Compiler.h"


/***********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL FUNCTION MACROS*
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
 *  Os_PeripheralId2Peripheral()
 **********************************************************************************************************************/
/*! \brief          Returns the peripheral belonging to the given ID.
 *  \details        --no details--
 *
 *  \param[in]      PeripheralID        The ID of the searched peripheral. The ID must be smaller than
 *                                      OS_PERIPHERALID_COUNT.
 *
 *  \return         The peripheral belonging to the given ID.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_PeripheralConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_PeripheralId2Peripheral,
(
  Os_PeripheralIdType PeripheralID
));


/***********************************************************************************************************************
 *  Os_PeripheralCheck()
 **********************************************************************************************************************/
/*! \brief          Performs general checks and returns the peripheral belonging to the given ID.
 *  \details        In case that a check failed, the protection hook is called with one of the following values:
 *                   - OS_STATUS_ID_1             (EXTENDED status:) Invalid peripheral ID.
 *                   - OS_STATUS_CALLEVEL         (EXTENDED status:) Called from invalid context.
 *                   - OS_STATUS_ACCESSRIGHTS_1   (Service Protection:) Caller's access rights are not sufficient.
 *
 *  \param[in]      PeripheralID      The ID of the searched region. The ID must be smaller than OS_PERIPHERALID_COUNT,
 *                                    if extended status checks are disabled.
 *
 *  \return         The peripheral belonging to the given ID.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_PeripheralConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_PeripheralCheck,
(
  Os_PeripheralIdType PeripheralID
));


/***********************************************************************************************************************
 *  Os_PeripheralCheck08()
 **********************************************************************************************************************/
/*! \brief          Performs general checks and uint8 specific checks.
 *  \details        --no details--
 *
 *  \param[in]      PeripheralID      The ID of the searched region. The ID must be smaller than OS_PERIPHERALID_COUNT,
 *                                    if extended status checks are disabled.
 *  \param[in]      Address           The address to check.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_PeripheralCheck08,
(
  Os_PeripheralIdType PeripheralID,
  Os_AddressOfConstType Address
));


/***********************************************************************************************************************
 *  Os_PeripheralCheck16()
 **********************************************************************************************************************/
/*! \brief          Performs general checks and uint16 specific checks.
 *  \details        --no details--
 *
 *  \param[in]      PeripheralID      The ID of the searched region. The ID must be smaller than OS_PERIPHERALID_COUNT,
 *                                    if extended status checks are disabled.
 *  \param[in]      Address           The address to check.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_PeripheralCheck16,
(
  Os_PeripheralIdType PeripheralID,
  Os_AddressOfConstType Address
));


/***********************************************************************************************************************
 *  Os_PeripheralCheck32()
 **********************************************************************************************************************/
/*! \brief          Performs general checks and uint32 specific checks.
 *  \details        --no details--
 *
 *  \param[in]      PeripheralID      The ID of the searched region. The ID must be smaller than OS_PERIPHERALID_COUNT,
 *                                    if extended status checks are disabled.
 *  \param[in]      Address           The address to check.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_PeripheralCheck32,
(
  Os_PeripheralIdType PeripheralID,
  Os_AddressOfConstType Address
));


/***********************************************************************************************************************
 *  Os_PeripheralCheckId()
 **********************************************************************************************************************/
/*! \brief          Checks whether the given ID is in range.
 *  \details        --no details--
 *
 *  \param[in]      PeripheralID        The ID of the searched region.
 *
 *  \retval         !OS_CHECK_FAILED  The given ID is in a valid range.
 *  \retval         OS_CHECK_FAILED   The given ID is not in a valid range.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_PeripheralCheckId,
(
  Os_PeripheralIdType PeripheralID
));


/***********************************************************************************************************************
 *  Os_PeripheralIsInAddressRange()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given address is in a valid range.
 *  \details        --no details--
 *
 *  \param[in]      Peripheral        The peripheral to query. Parameter must not be NULL.
 *  \param[in]      Address           The address to check.
 *  \param[in]      Size              The size of the addressed type in bytes.
 *
 *  \retval         !0  The given address is in a valid range.
 *  \retval         0   The given address is not in a valid range.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_PeripheralIsInAddressRange,
(
  P2CONST(Os_PeripheralConfigType, AUTOMATIC, OS_CONST) Peripheral,
  Os_AddressOfConstType Address,
  uint32 Size
));


/***********************************************************************************************************************
 *  Os_PeripheralCheckAddressRange08()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given address is in a valid range.
 *  \details        --no details--
 *
 *  \param[in]      Peripheral        The peripheral to query. Parameter must not be NULL.
 *  \param[in]      Address           The address to check.
 *
 *  \retval         !OS_CHECK_FAILED  The given address is in a valid range.
 *  \retval         OS_CHECK_FAILED   The given address is not in a valid range.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_PeripheralCheckAddressRange08,
(
  P2CONST(Os_PeripheralConfigType, AUTOMATIC, OS_CONST) Peripheral,
  Os_AddressOfConstType Address
));


/***********************************************************************************************************************
 *  Os_PeripheralCheckAddressRange16()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given address is in a valid range.
 *  \details        --no details--
 *
 *  \param[in]      Peripheral        The peripheral to query. Parameter must not be NULL.
 *  \param[in]      Address           The address to check.
 *
 *  \retval         !OS_CHECK_FAILED  The given address is in a valid range.
 *  \retval         OS_CHECK_FAILED   The given address is not in a valid range.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_PeripheralCheckAddressRange16,
(
  P2CONST(Os_PeripheralConfigType, AUTOMATIC, OS_CONST) Peripheral,
  Os_AddressOfConstType Address
));


/***********************************************************************************************************************
 *  Os_PeripheralCheckAddressRange32()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given address is in a valid range.
 *  \details        --no details--
 *
 *  \param[in]      Peripheral        The peripheral to query. Parameter must not be NULL.
 *  \param[in]      Address           The address to check.
 *
 *  \retval         !OS_CHECK_FAILED  The given address is in a valid range.
 *  \retval         OS_CHECK_FAILED   The given address is not in a valid range.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_PeripheralCheckAddressRange32,
(
  P2CONST(Os_PeripheralConfigType, AUTOMATIC, OS_CONST) Peripheral,
  Os_AddressOfConstType Address
));



/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_PeripheralId2Peripheral()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE P2CONST(Os_PeripheralConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE,
Os_PeripheralId2Peripheral,
(
    Os_PeripheralIdType PeripheralID
))
{
  Os_Assert(Os_ErrIsValueLo((uint32)PeripheralID, (uint32)OS_PERIPHERALID_COUNT));
  return OsCfg_PeripheralRefs[PeripheralID];                                                                            /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  Os_PeripheralCheck()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2CONST(Os_PeripheralConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_PeripheralCheck,
(
  Os_PeripheralIdType PeripheralID
))
{
  Os_StatusType status;
  P2CONST(Os_PeripheralConfigType, AUTOMATIC, OS_CONST) peripheral;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) thread;

  thread = Os_CoreGetThread();
  peripheral = NULL_PTR;

  /* #10  Perform checks. */
  if(OS_UNLIKELY(Os_PeripheralCheckId(PeripheralID) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_ID_1;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckCallContext(thread, OS_APICONTEXT_PERIPHERAL) == OS_CHECK_FAILED))                  /* SBSW_OS_PP_THREADCHECKCALLCONTEXT_001 */
  {
    status = OS_STATUS_CALLEVEL;
  }
  else
  {
    P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) application;

    application = Os_ThreadGetCurrentApplication(thread);                                                               /* SBSW_OS_PP_THREADGETCURRENTAPPLICATION_001 */

    peripheral = Os_PeripheralId2Peripheral(PeripheralID);

    if(OS_UNLIKELY(Os_AppCheckAccess(application, peripheral->AccessingApplications) == OS_CHECK_FAILED))               /* SBSW_OS_PP_APPCHECKACCESS_001 */
    {
      status = OS_STATUS_ACCESSRIGHTS_1;
    }
    else
    {
      status = OS_STATUS_OK;
    }
  }

  /* #20  If any check failed, call the Protection Hook. */
  if(OS_UNLIKELY(status != OS_STATUS_OK))
  {
    Os_ErrProtectionError(status);
  }

  return peripheral;
}


/***********************************************************************************************************************
 *  Os_PeripheralCheck08()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_PeripheralCheck08,
(
  Os_PeripheralIdType PeripheralID,
  Os_AddressOfConstType Address
))
{
  P2CONST(Os_PeripheralConfigType, AUTOMATIC, OS_CONST) peripheral;

  /* #10  Perform general checks. */
  peripheral = Os_PeripheralCheck(PeripheralID);

  /* #20  If the given address is invalid, call the Protection Hook. */
  if(OS_UNLIKELY(Os_PeripheralCheckAddressRange08(peripheral, Address) == OS_CHECK_FAILED))                             /* SBSW_OS_PP_PERIPHERALCHECKADDRESSRANGE08_001 */
  {
    Os_ErrProtectionError(OS_STATUS_PARAM_POINTER_2);
  }

  /*! Internal comment removed.
 *
 * */
}


/***********************************************************************************************************************
 *  Os_PeripheralCheck16()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_PeripheralCheck16,
(
  Os_PeripheralIdType PeripheralID,
  Os_AddressOfConstType Address
))
{
  P2CONST(Os_PeripheralConfigType, AUTOMATIC, OS_CONST) peripheral;

  /* #10  Perform general checks. */
  peripheral = Os_PeripheralCheck(PeripheralID);

  /* #20  If the given address is invalid, call the Protection Hook. */
  if(OS_UNLIKELY(Os_PeripheralCheckAddressRange16(peripheral, Address) == OS_CHECK_FAILED))                             /* SBSW_OS_PP_PERIPHERALCHECKADDRESSRANGE16_001 */
  {
    Os_ErrProtectionError(OS_STATUS_PARAM_POINTER_2);
  }

  /*! Internal comment removed.
 *
 * */
}


/***********************************************************************************************************************
 *  Os_PeripheralCheck32()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_PeripheralCheck32,
(
  Os_PeripheralIdType PeripheralID,
  Os_AddressOfConstType Address
))
{
  P2CONST(Os_PeripheralConfigType, AUTOMATIC, OS_CONST) peripheral;

  /* #10  Perform general checks. */
  peripheral = Os_PeripheralCheck(PeripheralID);

  /* #20  If the given address is invalid, call the Protection Hook. */
  if(OS_UNLIKELY(Os_PeripheralCheckAddressRange32(peripheral, Address) == OS_CHECK_FAILED))                             /* SBSW_OS_PP_PERIPHERALCHECKADDRESSRANGE32_001 */
  {
    Os_ErrProtectionError(OS_STATUS_PARAM_POINTER_2);
  }

  /*! Internal comment removed.
 *
 * */
}


/***********************************************************************************************************************
 *  Os_PeripheralCheckId()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_PeripheralCheckId,
(
  Os_PeripheralIdType PeripheralID
))
{
  return Os_ErrExtendedCheck(Os_ErrIsValueLo((uint32)PeripheralID, (uint32)OS_PERIPHERALID_COUNT));
}


/***********************************************************************************************************************
 *  Os_PeripheralIsInAddressRange()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_PeripheralIsInAddressRange,
(
  P2CONST(Os_PeripheralConfigType, AUTOMATIC, OS_CONST) Peripheral,
  Os_AddressOfConstType Address,
  uint32 Size
))
{
  return (Os_StdReturnType) (   (((const uint8*)Address) >=  ((const uint8*)Peripheral->AddressStart))                  /* PRQA S 0316, 4304 */ /* MD_Os_Rule11.5_0316, MD_Os_C90BooleanCompatibility */
                             && (((const uint8*)Address) <= (((const uint8*)Peripheral->AddressEnd) - (Size - 1u) )));  /* PRQA S 0488, 0316 */ /* MD_Os_Rule18.4_0488_PeripheralAddress, MD_Os_Rule18.4_0316 */
}


/***********************************************************************************************************************
 *  Os_PeripheralCheckAddressRange08()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_PeripheralCheckAddressRange08,
(
  P2CONST(Os_PeripheralConfigType, AUTOMATIC, OS_CONST) Peripheral,
  Os_AddressOfConstType Address
))
{
  return Os_ErrExtendedCheck(Os_PeripheralIsInAddressRange(Peripheral, Address, sizeof(uint8)));                        /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_PeripheralCheckAddressRange16()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_PeripheralCheckAddressRange16,
(
  P2CONST(Os_PeripheralConfigType, AUTOMATIC, OS_CONST) Peripheral,
  Os_AddressOfConstType Address
))
{
  return Os_ErrExtendedCheck(Os_PeripheralIsInAddressRange(Peripheral, Address, sizeof(uint16)));                       /* SBSW_OS_FC_PRECONDITION */
}



/***********************************************************************************************************************
 *  Os_PeripheralCheckAddressRange32()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_PeripheralCheckAddressRange32,
(
  P2CONST(Os_PeripheralConfigType, AUTOMATIC, OS_CONST) Peripheral,
  Os_AddressOfConstType Address
))
{
  return Os_ErrExtendedCheck(Os_PeripheralIsInAddressRange(Peripheral, Address, sizeof(uint32)));                       /* SBSW_OS_FC_PRECONDITION */
}



/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_Api_ReadPeripheral8()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(uint8, OS_CODE) Os_Api_ReadPeripheral8
(
  Os_PeripheralIdType PeripheralID,
  P2CONST(uint8, AUTOMATIC, OS_APPL_DATA) Address
)
{
  uint8 result;

  /* #10 Perform error checks. */
  Os_PeripheralCheck08(PeripheralID, Address);                                                                          /* PRQA S 0315 */ /* MD_Os_Dir1.1_0315 */ /* SBSW_OS_PP_PERIPHERALCHECK */

  /* #20 Read the target address value. */
  result = *Address;

  return result;
}


/***********************************************************************************************************************
 *  Os_Api_ReadPeripheral16()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(uint16, OS_CODE) Os_Api_ReadPeripheral16
(
  Os_PeripheralIdType PeripheralID,
  P2CONST(uint16, AUTOMATIC, OS_APPL_DATA) Address
)
{
  uint16 result;

  /* #10 Perform error checks. */
  Os_PeripheralCheck16(PeripheralID, Address);                                                                          /* PRQA S 0315 */ /* MD_Os_Dir1.1_0315 */ /* SBSW_OS_PP_PERIPHERALCHECK */

  /* #20 Read the target address value. */
  result = *Address;

  return result;
}


/***********************************************************************************************************************
 *  Os_Api_ReadPeripheral32()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(uint32, OS_CODE) Os_Api_ReadPeripheral32
(
  Os_PeripheralIdType PeripheralID,
  P2CONST(uint32, AUTOMATIC, OS_APPL_DATA) Address
)
{
  uint32 result;

  /* #10 Perform error checks. */
  Os_PeripheralCheck32(PeripheralID, Address);                                                                          /* PRQA S 0315 */ /* MD_Os_Dir1.1_0315 */ /* SBSW_OS_PP_PERIPHERALCHECK */

  /* #20 Read the target address value. */
  result = *Address;

  return result;
}


/***********************************************************************************************************************
 *  Os_Api_WritePeripheral8()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_Api_WritePeripheral8
(
  Os_PeripheralIdType PeripheralID,
  P2VAR(uint8, AUTOMATIC, OS_APPL_DATA) Address,
  uint8 Value
)
{
  /* #10 Perform error checks. */
  Os_PeripheralCheck08(PeripheralID, Address);                                                                          /* PRQA S 0315 */ /* MD_Os_Dir1.1_0315 */ /* SBSW_OS_PP_PERIPHERALCHECK */

  /* #20 Modify the target address value. */
  *Address = Value;                                                                                                     /* SBSW_OS_PP_PERIPHERAL_ADDRESS_001 */
}


/***********************************************************************************************************************
 *  Os_Api_WritePeripheral16()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_Api_WritePeripheral16
(
  Os_PeripheralIdType PeripheralID,
  P2VAR(uint16, AUTOMATIC, OS_APPL_DATA) Address,
  uint16 Value
)
{
  /* #10 Perform error checks. */
  Os_PeripheralCheck16(PeripheralID, Address);                                                                          /* PRQA S 0315 */ /* MD_Os_Dir1.1_0315 */ /* SBSW_OS_PP_PERIPHERALCHECK */

  /* #20 Modify the target address value. */
  *Address = Value;                                                                                                     /* SBSW_OS_PP_PERIPHERAL_ADDRESS_001 */
}


/***********************************************************************************************************************
 *  Os_Api_WritePeripheral32()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_Api_WritePeripheral32
(
  Os_PeripheralIdType PeripheralID,
  P2VAR(uint32, AUTOMATIC, OS_APPL_DATA) Address,
  uint32 Value
)
{
  /* #10 Perform error checks. */
  Os_PeripheralCheck32(PeripheralID, Address);                                                                          /* PRQA S 0315 */ /* MD_Os_Dir1.1_0315 */ /* SBSW_OS_PP_PERIPHERALCHECK */

  /* #20 Modify the target address value. */
  *Address = Value;                                                                                                     /* SBSW_OS_PP_PERIPHERAL_ADDRESS_001 */
}


/***********************************************************************************************************************
 *  Os_Api_ModifyPeripheral8()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_Api_ModifyPeripheral8
(
  Os_PeripheralIdType PeripheralID,
  P2VAR(uint8, AUTOMATIC, OS_APPL_DATA) Address,
  uint8 ClearMask,
  uint8 SetMask
)
{
  /* #10 Perform error checks. */
  Os_PeripheralCheck08(PeripheralID, Address);                                                                          /* PRQA S 0315 */ /* MD_Os_Dir1.1_0315 */ /* SBSW_OS_PP_PERIPHERALCHECK */

  /* #20 Modify the target address value. */
  /* As the result of a bitwise operation is a word, casts are required. */
  *Address = (uint8)(((uint8)((*Address)) & ClearMask) | SetMask);                                                      /* SBSW_OS_PP_PERIPHERAL_ADDRESS_001 */
}


/***********************************************************************************************************************
 *  Os_Api_ModifyPeripheral16()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_Api_ModifyPeripheral16
(
  Os_PeripheralIdType PeripheralID,
  P2VAR(uint16, AUTOMATIC, OS_APPL_DATA) Address,
  uint16 ClearMask,
  uint16 SetMask
)
{
  /* #10 Perform error checks. */
  Os_PeripheralCheck16(PeripheralID, Address);                                                                          /* PRQA S 0315 */ /* MD_Os_Dir1.1_0315 */ /* SBSW_OS_PP_PERIPHERALCHECK */

  /* #20 Modify the target address value. */
  /* As the result of a bitwise operation is a word, casts are required. */
  *Address = (uint16)(((uint16)(*Address) & ClearMask) | SetMask);                                                      /* SBSW_OS_PP_PERIPHERAL_ADDRESS_001 */
}


/***********************************************************************************************************************
 *  Os_Api_ModifyPeripheral32()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_Api_ModifyPeripheral32
(
  Os_PeripheralIdType PeripheralID,
  P2VAR(uint32, AUTOMATIC, OS_APPL_DATA) Address,
  uint32 ClearMask,
  uint32 SetMask
)
{
  /* #10 Perform error checks. */
  Os_PeripheralCheck32(PeripheralID, Address);                                                                          /* PRQA S 0315 */ /* MD_Os_Dir1.1_0315 */ /* SBSW_OS_PP_PERIPHERALCHECK */

  /* #20 Modify the target address value. */
  /* As the result of a bitwise operation is a word, casts are required. */
  *Address = (uint32)((uint32)((*Address) & ClearMask) | SetMask);                                                      /* SBSW_OS_PP_PERIPHERAL_ADDRESS_001 */
}


#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* module specific MISRA deviations:
 */

/* SBSW_JUSTIFICATION_BEGIN

\ID SBSW_OS_PP_THREADCHECKCALLCONTEXT_001
 \DESCRIPTION    Os_ThreadCheckCallContext is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_PP_THREADGETCURRENTAPPLICATION_001
 \DESCRIPTION    Os_ThreadGetCurrentApplication is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_PP_APPCHECKACCESS_001
 \DESCRIPTION    Os_AppCheckAccess is called with the return value of Os_ThreadGetCurrentApplication.
 \COUNTERMEASURE \N [CM_OS_THREADGETCURRENTAPPLICATION_N]

\ID SBSW_OS_PP_PERIPHERALCHECKADDRESSRANGE08_001
 \DESCRIPTION    Os_PeripheralCheckAddressRange08 is called with the return value of Os_PeripheralCheck.
 \COUNTERMEASURE \N [CM_OS_PERIPHERALCHECK_N]

\ID SBSW_OS_PP_PERIPHERALCHECKADDRESSRANGE16_001
 \DESCRIPTION    Os_PeripheralCheckAddressRange16 is called with the return value of Os_PeripheralCheck.
 \COUNTERMEASURE \N [CM_OS_PERIPHERALCHECK_N]

\ID SBSW_OS_PP_PERIPHERALCHECKADDRESSRANGE32_001
 \DESCRIPTION    Os_PeripheralCheckAddressRange32 is called with the return value of Os_PeripheralCheck.
 \COUNTERMEASURE \N [CM_OS_PERIPHERALCHECK_N]

\ID SBSW_OS_PP_PERIPHERAL_ADDRESS_001
 \DESCRIPTION    Write access to a address passed as argument.
 \COUNTERMEASURE \S [CM_OS_PERIPHERAL_ADDRESS_S]

\ID SBSW_OS_PP_PERIPHERALCHECK
 \DESCRIPTION    Pass pointer to validation function.
 \COUNTERMEASURE \N Called validation function checks whether Address is in the range of the given Peripheral Region.
                    There is no precondition for parameter Address. The validation function does neither write nor read
                    to the given Address.

SBSW_JUSTIFICATION_END */


/*
\CM CM_OS_PERIPHERALID2PERIPHERAL
      Verify that:
        1. Verify that each peripheral region in OsCfg_PeripheralRefs is no NULL_PTR,
        2. the size of OsCfg_PeripheralRefs is equal OS_PERIPHERALID_COUNT + 1 and
        3. each element in Os_PeripheralIdType has a value lower than OS_PERIPHERALID_COUNT.

\CM CM_OS_PERIPHERALCHECK_N
      Precondition ensures that the pointer is valid. The compliance of the precondition is check during review.

\CM CM_OS_PERIPHERAL_ADDRESS_S
      Verify that the complete range specified by each Os_PeripheralConfigType object in Os_Peripheral_Lcfg.c is either
      part of the writable address space or that there are no write accesses to that region via the Peripheral API.
      The first writable address is denoted as AddressStart and the last writable address is denoted as AddressEnd.
      SMI-340

 */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Peripheral.c
 **********************************************************************************************************************/
