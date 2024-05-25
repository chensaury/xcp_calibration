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
 * \defgroup    Os_AccessCheck Access Check
 * \brief       Memory Access Check Functionality
 * \details
 * This module contains functions to handle memory access rights in the application. It also contains declarations
 * of the necessary data structures. The functions provide:
 *   - The check of memory protection rights for a specific task/ISR on a specific memory region
 *   - The check whether memory access to a specific address is prevented by the MPU
 *
 *
 * Os_Api_SafeMemCpy:
 *
 * This function is currently not supported by the OS. The design of this function is available in SVN revision 20259.
 * The review findings have to be considered (same version).
 * Alternative solutions are:
 *  - The IOC may be used for transferring data from a trusted function to its caller.
 *  - Modify the non-trusted function call:
 *    - CallNontrusteFunction() creates a copy of each parameter in the OS code, but with callers rights.
 *    - The OS calls the non-trusted function.
 *    - When returned from the NTF to the caller's level (still in the OS), the OS copies the output data of the NTF
 *      into the original call parameters.
 *
 *
 * \{
 *
 * \file
 * \brief       OS internal functions and data types to handle memory access rights in the application
 * \details     -
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_ACCESSCHECKINT_H
# define OS_ACCESSCHECKINT_H

                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_AccessCheck_Types.h"

/* Os kernel module dependencies */
# include "Os_Common_Types.h"
# include "OsInt.h"

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
/*! A memory region and the access rights on it (for a specific thread). */
typedef struct
{
  Os_AccessCheckAddress AddressStart;     /*!< The start address of the memory region. */
  Os_AccessCheckAddress AddressEnd;       /*!< The last address of a memory region (access granted). */
  AccessType AccessRights;                /*!< The access rights for this memory region. */
} Os_AccessCheckRegionConfigType;


/*! All memory regions (for a specific thread) and the access rights on them. */
struct Os_AccessCheckConfigType_Tag
{
  /*! Array of memory regions, last array element is a struct with all elements set to zero or NULL. */
  P2CONST(Os_AccessCheckRegionConfigType, AUTOMATIC, OS_CONST) Regions;

  /*! The number of configured regions */
  Os_AccessCheckIdx RegionCount;
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
 *  Os_Api_CheckTaskMemoryAccess()
 **********************************************************************************************************************/
/*! \brief        OS service CheckTaskMemoryAccess().
 *  \details      For further details see CheckTaskMemoryAccess().
 *
 *  \param[in]    TaskID              See CheckTaskMemoryAccess().
 *  \param[in]    Address             See CheckTaskMemoryAccess().
 *  \param[in]    Size                See CheckTaskMemoryAccess().
 *
 *  \return       See CheckTaskMemoryAccess().
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See CheckTaskMemoryAccess().
 *
 *  \trace        CREQ-73
 *  \trace        SPEC-63949, SPEC-63842, SPEC-63907, SPEC-63888, SPEC-63798, SPEC-63869
 *
 *  Internal comment removed.
 *
 *
 *
 *
 *
 **********************************************************************************************************************/
FUNC(AccessType, OS_CODE) Os_Api_CheckTaskMemoryAccess
(
  TaskType TaskID,
  MemoryStartAddressType Address,
  MemorySizeType Size
);


/***********************************************************************************************************************
 *  Os_Api_CheckISRMemoryAccess()
 **********************************************************************************************************************/
/*! \brief        OS service CheckISRMemoryAccess().
 *  \details      For further details see CheckISRMemoryAccess().
 *
 *  \param[in]    ISRID               See CheckISRMemoryAccess().
 *  \param[in]    Address             See CheckISRMemoryAccess().
 *  \param[in]    Size                See CheckISRMemoryAccess().
 *
 *  \return       See CheckISRMemoryAccess().
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See CheckISRMemoryAccess().
 *
 *  \trace        CREQ-13
 *  \trace        SPEC-63949, SPEC-63728, SPEC-64063, SPEC-63981, SPEC-63754, SPEC-63924
 *
 *  Internal comment removed.
 *
 *
 *
 *
 *
 **********************************************************************************************************************/
FUNC(AccessType, OS_CODE) Os_Api_CheckISRMemoryAccess
(
  ISRType ISRID,
  MemoryStartAddressType Address,
  MemorySizeType Size
);


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */




#endif /* OS_ACCESSCHECKINT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_AccessCheckInt.h
 **********************************************************************************************************************/
