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
 * \defgroup    Os_Peripheral Peripheral Region
 * \brief       Provides access to dedicated memory regions for callers with restricted rights.
 * \details
 * On some platforms, there are memory mapped hardware registers, which are only accessible in
 * privileged mode. To access this kind of registers in non-trusted applications
 * (i.e. in non-privileged mode), MICROSAR OS provides *peripheral regions*.
 * To access such registers a peripheral region has to be configured. When accessing a region, the OS
 * checks whether the caller has access to this region and performs the requested access operation in
 * privileged mode.
 *
 * The OS provides access functions for the following access types: 8, 16, and 32 bit.
 *
 * Miss aligned user addresses are expected to be handled by hardware. No special check is added.
 *
 * \trace       CREQ-131
 *
 * \{
 *
 * \file
 * \brief       Provides the OS internal peripheral API.
 * \details     --no details--
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_PERIPHERALINT_H
# define OS_PERIPHERALINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "OsInt.h"
# include "Os_Peripheral_Types.h"

/* Os kernel module dependencies */
# include "Os_Application_Types.h"

/* Os hal dependencies */


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/


/*! The static configuration type of a peripheral region. */
struct Os_PeripheralConfigType_Tag
{
  /*! The first accessible address of the region. */
  Os_AddressOfConstType AddressStart;

  /*! The last accessible address of the region. */
  Os_AddressOfConstType AddressEnd;

  /*! Reference to applications which are allowed to access this object. */
  Os_AppAccessMaskType AccessingApplications;
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
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  Os_Api_ReadPeripheral8()
 **********************************************************************************************************************/
/*! \brief        OS service Os_ReadPeripheral8().
 *  \details      For further details see Os_ReadPeripheral8().
 *
 *  \param[in]    PeripheralID      See Os_ReadPeripheral8().
 *  \param[in]    Address           See Os_ReadPeripheral8().
 *
 *  \return       See Os_ReadPeripheral8().
 *
 *  \context      TASK|ISR2|ERRHOOK|STARTHOOK|SHUTHOOK
 *
 *  \reentrant    TRUE for different addresses.
 *  \synchronous  TRUE
 *
 *  \pre          See Os_ReadPeripheral8().
 *
 *  \trace        CREQ-79, CREQ-40
 **********************************************************************************************************************/
FUNC(uint8, OS_CODE) Os_Api_ReadPeripheral8
(
  Os_PeripheralIdType PeripheralID,
  P2CONST(uint8, AUTOMATIC, OS_APPL_DATA) Address
);


/***********************************************************************************************************************
 *  Os_Api_ReadPeripheral16()
 **********************************************************************************************************************/
/*! \brief        OS service Os_ReadPeripheral16().
 *  \details      For further details see Os_ReadPeripheral16().
 *
 *  \param[in]    PeripheralID      See Os_ReadPeripheral16().
 *  \param[in]    Address           See Os_ReadPeripheral16().
 *
 *  \return       See Os_ReadPeripheral16().
 *
 *  \context      TASK|ISR2|ERRHOOK|STARTHOOK|SHUTHOOK
 *
 *  \reentrant    TRUE for different addresses.
 *  \synchronous  TRUE
 *
 *  \pre          See Os_ReadPeripheral16().
 *
 *  \trace        CREQ-79, CREQ-40
 **********************************************************************************************************************/
FUNC(uint16, OS_CODE) Os_Api_ReadPeripheral16
(
  Os_PeripheralIdType PeripheralID,
  P2CONST(uint16, AUTOMATIC, OS_APPL_DATA) Address
);


/***********************************************************************************************************************
 *  Os_Api_ReadPeripheral32()
 **********************************************************************************************************************/
/*! \brief        OS service Os_ReadPeripheral32().
 *  \details      For further details see Os_ReadPeripheral32().
 *
 *  \param[in]    PeripheralID      See Os_ReadPeripheral32().
 *  \param[in]    Address           See Os_ReadPeripheral32().
 *
 *  \return       See Os_ReadPeripheral32().
 *
 *  \context      TASK|ISR2|ERRHOOK|PRETHOOK|POSTTHOOK|STARTHOOK|SHUTHOOK|ALARMHOOK|PROTHOOK
 *
 *  \reentrant    TRUE for different addresses.
 *  \synchronous  TRUE
 *
 *  \pre          See Os_ReadPeripheral32().
 *
 *  \trace        CREQ-79, CREQ-40
 **********************************************************************************************************************/
FUNC(uint32, OS_CODE) Os_Api_ReadPeripheral32
(
  Os_PeripheralIdType PeripheralID,
  P2CONST(uint32, AUTOMATIC, OS_APPL_DATA) Address
);


/***********************************************************************************************************************
 *  Os_Api_WritePeripheral8()
 **********************************************************************************************************************/
/*! \brief        OS service Os_WritePeripheral8().
 *  \details      For further details see Os_WritePeripheral8().
 *
 *  \param[in]     PeripheralID      See Os_WritePeripheral8().
 *  \param[in,out] Address           See Os_WritePeripheral8().
 *  \param[in]     Value             See Os_WritePeripheral8().
 *
 *  \context      TASK|ISR2|ERRHOOK|STARTHOOK|SHUTHOOK
 *
 *  \reentrant    TRUE for different addresses.
 *  \synchronous  TRUE
 *
 *  \pre          See Os_WritePeripheral8().
 *
 *  \trace        CREQ-145, CREQ-40
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Api_WritePeripheral8
(
  Os_PeripheralIdType PeripheralID,
  P2VAR(uint8, AUTOMATIC, OS_APPL_DATA) Address,
  uint8 Value
);


/***********************************************************************************************************************
 *  Os_Api_WritePeripheral16()
 **********************************************************************************************************************/
/*! \brief        OS service Os_WritePeripheral16().
 *  \details      For further details see Os_WritePeripheral16().
 *
 *  \param[in]     PeripheralID      See Os_WritePeripheral16().
 *  \param[in,out] Address           See Os_WritePeripheral16().
 *  \param[in]     Value             See Os_WritePeripheral16().
 *
 *  \context      TASK|ISR2|ERRHOOK|STARTHOOK|SHUTHOOK
 *
 *  \reentrant    TRUE for different addresses.
 *  \synchronous  TRUE
 *
 *  \pre          See Os_WritePeripheral16().
 *
 *  \trace        CREQ-145, CREQ-40
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Api_WritePeripheral16
(
  Os_PeripheralIdType PeripheralID,
  P2VAR(uint16, AUTOMATIC, OS_APPL_DATA) Address,
  uint16 Value
);


/***********************************************************************************************************************
 *  Os_Api_WritePeripheral32()
 **********************************************************************************************************************/
/*! \brief        OS service Os_WritePeripheral32().
 *  \details      For further details see Os_WritePeripheral32().
 *
 *  \param[in]     PeripheralID      See Os_WritePeripheral32().
 *  \param[in,out] Address           See Os_WritePeripheral32().
 *  \param[in]     Value             See Os_WritePeripheral32().
 *
 *  \context      TASK|ISR2|ERRHOOK|STARTHOOK|SHUTHOOK
 *
 *  \reentrant    TRUE for different addresses.
 *  \synchronous  TRUE
 *
 *  \pre          See Os_WritePeripheral32().
 *
 *  \trace        CREQ-145, CREQ-40
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Api_WritePeripheral32
(
  Os_PeripheralIdType PeripheralID,
  P2VAR(uint32, AUTOMATIC, OS_APPL_DATA) Address,
  uint32 Value
);


/***********************************************************************************************************************
 *  Os_Api_ModifyPeripheral8()
 **********************************************************************************************************************/
/*! \brief        OS service Os_ModifyPeripheral8().
 *  \details      For further details see Os_ModifyPeripheral8().
 *
 *  \param[in]     PeripheralID     See Os_ModifyPeripheral8().
 *  \param[in,out] Address          See Os_ModifyPeripheral8().
 *  \param[in]     ClearMask        See Os_ModifyPeripheral8().
 *  \param[in]     SetMask          See Os_ModifyPeripheral8().
 *
 *  \context      TASK|ISR2|ERRHOOK|STARTHOOK|SHUTHOOK
 *
 *  \reentrant    TRUE for different addresses.
 *  \synchronous  TRUE
 *
 *  \pre          See Os_ModifyPeripheral8().
 *
 *  \trace        CREQ-35, CREQ-40
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Api_ModifyPeripheral8
(
  Os_PeripheralIdType PeripheralID,
  P2VAR(uint8, AUTOMATIC, OS_APPL_DATA) Address,
  uint8 ClearMask,
  uint8 SetMask
);


/***********************************************************************************************************************
 *  Os_Api_ModifyPeripheral16()
 **********************************************************************************************************************/
/*! \brief        OS service Os_ModifyPeripheral16().
 *  \details      For further details see Os_ModifyPeripheral16().
 *
 *  \param[in]     PeripheralID     See Os_ModifyPeripheral16().
 *  \param[in,out] Address          See Os_ModifyPeripheral16().
 *  \param[in]     ClearMask        See Os_ModifyPeripheral16().
 *  \param[in]     SetMask          See Os_ModifyPeripheral16().
 *
 *  \context      TASK|ISR2|ERRHOOK|STARTHOOK|SHUTHOOK
 *
 *  \reentrant    TRUE for different addresses.
 *  \synchronous  TRUE
 *
 *  \pre          See Os_ModifyPeripheral16().
 *
 *  \trace        CREQ-35, CREQ-40
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Api_ModifyPeripheral16
(
  Os_PeripheralIdType PeripheralID,
  P2VAR(uint16, AUTOMATIC, OS_APPL_DATA) Address,
  uint16 ClearMask,
  uint16 SetMask
);


/***********************************************************************************************************************
 *  Os_Api_ModifyPeripheral32()
 **********************************************************************************************************************/
/*! \brief        OS service Os_ModifyPeripheral32().
 *  \details      For further details see Os_ModifyPeripheral32().
 *
 *  \param[in]     PeripheralID     See Os_ModifyPeripheral32().
 *  \param[in,out] Address          See Os_ModifyPeripheral32().
 *  \param[in]     ClearMask        See Os_ModifyPeripheral32().
 *  \param[in]     SetMask          See Os_ModifyPeripheral32().
 *
 *  \context      TASK|ISR2|ERRHOOK|STARTHOOK|SHUTHOOK
 *
 *  \reentrant    TRUE for different addresses.
 *  \synchronous  TRUE
 *
 *  \pre          See Os_ModifyPeripheral32().
 *
 *  \trace        CREQ-35, CREQ-40
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Api_ModifyPeripheral32
(
  Os_PeripheralIdType PeripheralID,
  P2VAR(uint32, AUTOMATIC, OS_APPL_DATA) Address,
  uint32 ClearMask,
  uint32 SetMask
);

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_PERIPHERALINT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_PeripheralInt.h
 **********************************************************************************************************************/
