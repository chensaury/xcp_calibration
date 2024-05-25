/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**
 * \ingroup     Os_Hal
 * \addtogroup  Os_Hal_Core
 *
 * \{
 *
 * \file       Os_Hal_Core_162_P.h
 * \brief      Primitives function implementation for TriCore Processor Core TC1.6.2P
 *
 *********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/
                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */


#ifndef OS_HAL_CORE_162_P_H
# define OS_HAL_CORE_162_P_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_Core_162_PInt.h"

/* Os kernel module dependencies */

/* Os Hal dependencies */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/
 
/***********************************************************************************************************************
 *  Os_Hal_CoreStart()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_CoreStart,
(
  P2CONST(Os_Hal_CoreConfigType, AUTOMATIC, OS_CONST) Core
))
{
  /* #10 Write the foreign PC with the startup code symbol for core 1. */
  *((volatile uint32*)Core->ProgramCounterRegister) = (uint32)(Core->StartLabelAddress);                                /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_CORECONFIG_PC */

  /* #20 Reset the core. */
  *((volatile uint32*)Core->DBGSRRegister) = OS_HAL_DBGSR_START_CORE;                                                   /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_CORECONFIG_DBGSR */
  
  /* #30 Release the core. */
  *((volatile uint32*)Core->SYSCONRegister) &= ~OS_HAL_SYSCON_BHALT_MASK;                                               /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_CORECONFIG_SYSCON */
}


/***********************************************************************************************************************
 *  Os_Hal_InitializeAccessDPRE()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_InitializeAccessDPRE,
(
  CONST(uint32, AUTOMATIC) Value[OS_HAL_COREMPU_NUM_OF_PS]
))
{
  Os_Hal_Mtcr(OS_HAL_COREMPU_DPRE0, Value[0]);
  Os_Hal_Mtcr(OS_HAL_COREMPU_DPRE1, Value[1]);
  Os_Hal_Mtcr(OS_HAL_COREMPU_DPRE2, Value[2]);
  Os_Hal_Mtcr(OS_HAL_COREMPU_DPRE3, Value[3]);
  Os_Hal_Mtcr(OS_HAL_COREMPU_DPRE4, Value[4]);
  Os_Hal_Mtcr(OS_HAL_COREMPU_DPRE5, Value[5]);
}


/***********************************************************************************************************************
 *  Os_Hal_InitializeAccessDPWE()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_InitializeAccessDPWE,
(
  CONST(uint32, AUTOMATIC) Value[OS_HAL_COREMPU_NUM_OF_PS]
))
{
  Os_Hal_Mtcr(OS_HAL_COREMPU_DPWE0, Value[0]);
  Os_Hal_Mtcr(OS_HAL_COREMPU_DPWE1, Value[1]);
  Os_Hal_Mtcr(OS_HAL_COREMPU_DPWE2, Value[2]);
  Os_Hal_Mtcr(OS_HAL_COREMPU_DPWE3, Value[3]);
  Os_Hal_Mtcr(OS_HAL_COREMPU_DPWE4, Value[4]);
  Os_Hal_Mtcr(OS_HAL_COREMPU_DPWE5, Value[5]);
}


/***********************************************************************************************************************
 *  Os_Hal_InitializeAccessCPXE()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_InitializeAccessCPXE,
(
  CONST(uint32, AUTOMATIC) Value[OS_HAL_COREMPU_NUM_OF_PS]
))
{
  Os_Hal_Mtcr(OS_HAL_COREMPU_CPXE0, Value[0]);
  Os_Hal_Mtcr(OS_HAL_COREMPU_CPXE1, Value[1]);
  Os_Hal_Mtcr(OS_HAL_COREMPU_CPXE2, Value[2]);
  Os_Hal_Mtcr(OS_HAL_COREMPU_CPXE3, Value[3]);
  Os_Hal_Mtcr(OS_HAL_COREMPU_CPXE4, Value[4]);
  Os_Hal_Mtcr(OS_HAL_COREMPU_CPXE5, Value[5]);
}


/***********************************************************************************************************************
 *  Os_Hal_ReadModifyAccessDPRE()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_ReadModifyAccessDPRE,
(
  CONST(uint8, AUTOMATIC) ProtectionSet,
  CONST(uint32, AUTOMATIC) Mask,
  CONST(uint32, AUTOMATIC) Value
))
{
  switch(ProtectionSet)
  {
    case 0:                                                                                                             /* COV_OS_UNSUPPORTED88830 */
      Os_Hal_Mtcr(OS_HAL_COREMPU_DPRE0, (Os_Hal_Mfcr(OS_HAL_COREMPU_DPRE0) & ~(Mask)) | (Value));
      break;
    case 1:
      Os_Hal_Mtcr(OS_HAL_COREMPU_DPRE1, (Os_Hal_Mfcr(OS_HAL_COREMPU_DPRE1) & ~(Mask)) | (Value));
      break;
    case 2:                                                                                                             /* COV_OS_HALCOREASSEMBLERINSTRUCTIONDATACASE */
      Os_Hal_Mtcr(OS_HAL_COREMPU_DPRE2, (Os_Hal_Mfcr(OS_HAL_COREMPU_DPRE2) & ~(Mask)) | (Value));
      break;
    case 3:                                                                                                             /* COV_OS_HALCOREASSEMBLERINSTRUCTIONDATACASE */
      Os_Hal_Mtcr(OS_HAL_COREMPU_DPRE3, (Os_Hal_Mfcr(OS_HAL_COREMPU_DPRE3) & ~(Mask)) | (Value));
      break;
    case 4:                                                                                                             /* COV_OS_HALCOREASSEMBLERINSTRUCTIONDATACASE */
      Os_Hal_Mtcr(OS_HAL_COREMPU_DPRE4, (Os_Hal_Mfcr(OS_HAL_COREMPU_DPRE4) & ~(Mask)) | (Value));
      break;
    case 5:                                                                                                             /* COV_OS_HALCOREASSEMBLERINSTRUCTIONDATACASE */
      Os_Hal_Mtcr(OS_HAL_COREMPU_DPRE5, (Os_Hal_Mfcr(OS_HAL_COREMPU_DPRE5) & ~(Mask)) | (Value));
      break;
    default:                                                                                                            /* PRQA S 2016 */ /* MD_MSR_EmptyClause */ /* COV_OS_INVSTATE */
      break;
  }
}


/***********************************************************************************************************************
 *  Os_Hal_ReadModifyAccessDPWE()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_ReadModifyAccessDPWE,
(
  CONST(uint8, AUTOMATIC) ProtectionSet,
  CONST(uint32, AUTOMATIC) Mask,
  CONST(uint32, AUTOMATIC) Value
))
{
  switch(ProtectionSet)
  {
    case 0:                                                                                                             /* COV_OS_UNSUPPORTED88830 */
      Os_Hal_Mtcr(OS_HAL_COREMPU_DPWE0, (Os_Hal_Mfcr(OS_HAL_COREMPU_DPWE0) & ~(Mask)) | (Value));
      break;
    case 1:
      Os_Hal_Mtcr(OS_HAL_COREMPU_DPWE1, (Os_Hal_Mfcr(OS_HAL_COREMPU_DPWE1) & ~(Mask)) | (Value));
      break;
    case 2:                                                                                                             /* COV_OS_HALCOREASSEMBLERINSTRUCTIONDATACASE */
      Os_Hal_Mtcr(OS_HAL_COREMPU_DPWE2, (Os_Hal_Mfcr(OS_HAL_COREMPU_DPWE2) & ~(Mask)) | (Value));
      break;
    case 3:                                                                                                             /* COV_OS_HALCOREASSEMBLERINSTRUCTIONDATACASE */
      Os_Hal_Mtcr(OS_HAL_COREMPU_DPWE3, (Os_Hal_Mfcr(OS_HAL_COREMPU_DPWE3) & ~(Mask)) | (Value));
      break;
    case 4:                                                                                                             /* COV_OS_HALCOREASSEMBLERINSTRUCTIONDATACASE */
      Os_Hal_Mtcr(OS_HAL_COREMPU_DPWE4, (Os_Hal_Mfcr(OS_HAL_COREMPU_DPWE4) & ~(Mask)) | (Value));
      break;
    case 5:                                                                                                             /* COV_OS_HALCOREASSEMBLERINSTRUCTIONDATACASE */
      Os_Hal_Mtcr(OS_HAL_COREMPU_DPWE5, (Os_Hal_Mfcr(OS_HAL_COREMPU_DPWE5) & ~(Mask)) | (Value));
      break;
    default:                                                                                                            /* PRQA S 2016 */ /* MD_MSR_EmptyClause */ /* COV_OS_INVSTATE */
      break;
  }
}


/***********************************************************************************************************************
 *  Os_Hal_ReadModifyAccessCPXE()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* COV_OS_HALUNSUPPORTEDCODEREGIONS */ /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_ReadModifyAccessCPXE,
(
  CONST(uint8, AUTOMATIC) ProtectionSet,
  CONST(uint32, AUTOMATIC) Mask,
  CONST(uint32, AUTOMATIC) Value
))
{
  switch(ProtectionSet)
  {
    case 0:
      Os_Hal_Mtcr(OS_HAL_COREMPU_CPXE0, (Os_Hal_Mfcr(OS_HAL_COREMPU_CPXE0) & ~(Mask)) | (Value));
      break;
    case 1:
      Os_Hal_Mtcr(OS_HAL_COREMPU_CPXE1, (Os_Hal_Mfcr(OS_HAL_COREMPU_CPXE1) & ~(Mask)) | (Value));
      break;
    case 2:
      Os_Hal_Mtcr(OS_HAL_COREMPU_CPXE2, (Os_Hal_Mfcr(OS_HAL_COREMPU_CPXE2) & ~(Mask)) | (Value));
      break;
    case 3:
      Os_Hal_Mtcr(OS_HAL_COREMPU_CPXE3, (Os_Hal_Mfcr(OS_HAL_COREMPU_CPXE3) & ~(Mask)) | (Value));
      break;
    case 4:
      Os_Hal_Mtcr(OS_HAL_COREMPU_CPXE4, (Os_Hal_Mfcr(OS_HAL_COREMPU_CPXE4) & ~(Mask)) | (Value));
      break;
    case 5:
      Os_Hal_Mtcr(OS_HAL_COREMPU_CPXE5, (Os_Hal_Mfcr(OS_HAL_COREMPU_CPXE5) & ~(Mask)) | (Value));
      break;
    default:                                                                                                            /* PRQA S 2016 */ /* MD_MSR_EmptyClause */
      break;
  }
}

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_HAL_CORE_162_P_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Core_162_P.h
 *********************************************************************************************************************/
