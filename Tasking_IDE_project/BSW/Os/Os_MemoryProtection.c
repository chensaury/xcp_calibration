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
 * \addtogroup Os_MemoryProtection
 * \{
 *
 * \file
 * \brief       Implementation of memory protection functionality.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777, 0779, 0828  EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */


#define OS_MEMORYPROTECTION_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_MemoryProtection.h"

/* Os kernel module dependencies */
#include "Os_Error.h"

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
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/



/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_MemFault()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_MemFault
(
  Os_AddressOfConstType ExceptionInstructionAddress,
  boolean ExceptionCauserPrivileged
)
{
  /* #10 Switch from global interrupt lock to level lock if needed. */
  Os_IntDisable();

  if(Os_InterruptLockOnLevelIsNeeded() != 0u)                                                                           /* COV_OS_HALPLATFORMLEVELSUPPORT */
  {
    if(Os_IntIsGlobal2LevelSwitchSupported() != 0u)                                                                     /* COV_OS_HALPLATFORMGLOBAL2LEVELSUPPORTED */
    {
      Os_IntEnableGlobal();
    }
  }

  /* #20 Inform the local core about the stack switch performed in HAL. */
  if(Os_StackIsMonitoringEnabled() != 0u)
  {
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) asrCore;
    
    asrCore = Os_Core2AsrCore(Os_CoreGetCurrentCore());                                                                 /* SBSW_OS_MP_CORE2ASRCORE_001 */
    Os_CoreSetCurrentStack(Os_CoreGetKernelStack(asrCore), asrCore);                                                    /* SBSW_OS_MP_COREGETKERNELSTACK_001 */ /* SBSW_OS_MP_CORESETCURRENTSTACK_001 */
  }

  /* #30 Report exception to error handling. */
  Os_ErrProtectionException(OS_STATUS_PROTECTION_MEMORY, ExceptionInstructionAddress, ExceptionCauserPrivileged);       /* SBSW_OS_MP_PROTECTIONEXCEPTION_001 */

}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* module specific MISRA deviations:
 */

/* SBSW_JUSTIFICATION_BEGIN
\ID SBSW_OS_MP_Hal_MPSYSTEMINIT_001
 \DESCRIPTION    Os_Hal_MpSystemInit is called with a HwConfig derived from the caller argument SystemConfig.
                 Precondition ensures that the SystemConfig pointer is valid. The compliance of the precondition is
                 check during review.
 \COUNTERMEASURE \M [CM_OS_MPSYSTEM_HWCONFIG_M]

\ID SBSW_OS_MP_Hal_MPCOREINIT_001
 \DESCRIPTION    Os_Hal_MpCoreInit is called with a HwConfig derived from the caller argument CoreConfig.
                 Precondition ensures that the CoreConfig pointer is valid. The compliance of the precondition is
                 check during review.
 \COUNTERMEASURE \M [CM_OS_MPCORE_HWCONFIG_M]

\ID SBSW_OS_MP_Hal_MPAPPSWITCH_001
 \DESCRIPTION    Os_Hal_MpAppSwitch is called with a AppAccessRights derived from the caller argument.
                 Precondition ensures that the pointer is valid. The compliance of the precondition is
                 check during review.
 \COUNTERMEASURE \M [CM_OS_MPACCESSRIGHTS_APPACCESSRIGHTS_M]

\ID SBSW_OS_MP_Hal_MPATHREADSWITCH_001
 \DESCRIPTION    Os_Hal_MpThreadSwitch is called with a ThreadAccessRights derived from the caller argument.
                 Precondition ensures that the pointer is valid. The compliance of the precondition is
                 check during review.
 \COUNTERMEASURE \M [CM_OS_MPACCESSRIGHTS_THREADACCESSRIGHTS_M]

\ID SBSW_OS_MP_PROTECTIONEXCEPTION_001
 \DESCRIPTION    Os_MemFault is called with a pointer parameter passed from the caller function.
 \COUNTERMEASURE \N The parameter is declared as pointer to const to prevent invalid write access.

\ID SBSW_OS_MP_CORE2ASRCORE_001
 \DESCRIPTION    Os_Core2AsrCore is called with the return value of Os_CoreGetCurrentCore.
 \COUNTERMEASURE \S [CM_OS_COREGETCURRENTCORE_S]

\ID SBSW_OS_MP_COREGETKERNELSTACK_001
 \DESCRIPTION    Os_CoreGetKernelStack is called with the return value of Os_Core2AsrCore.
 \COUNTERMEASURE \N [CM_OS_CORE2ASRCORE_N]

\ID SBSW_OS_MP_CORESETCURRENTSTACK_001
 \DESCRIPTION    Os_CoreSetCurrentStack is called with the return value of Os_CoreGetKernelStack
                 and the return value of Os_Core2AsrCore.
 \COUNTERMEASURE \M [CM_OS_COREASR_KERNELSTACK_M]
                    [CM_OS_CORE2ASRCORE_N]

 SBSW_JUSTIFICATION_END */

/*
\CM CM_OS_MPSYSTEM_HWCONFIG_M
      Verify that the HwConfig reference in each Os_MpSystemConfigType instance is a non NULL_PTR.

\CM CM_OS_MPCORE_HWCONFIG_M
      Verify that the HwConfig reference in each Os_MpCoreConfigType instance is a non NULL_PTR.

\CM CM_OS_MPACCESSRIGHTS_APPACCESSRIGHTS_M
      Verify that the AppAccessRights reference in each Os_MpAccessRightsType instance is a non NULL_PTR.

\CM CM_OS_MPACCESSRIGHTS_THREADACCESSRIGHTS_M
      Verify that the ThreadAccessRights reference in each Os_MpAccessRightsType instance is a non NULL_PTR.

 */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_MemoryProtection.c
 **********************************************************************************************************************/
