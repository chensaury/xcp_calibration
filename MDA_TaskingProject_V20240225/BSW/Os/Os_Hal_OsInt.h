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
 *  \ingroup    Os_Hal
 *  \defgroup   Os_Hal_Os  HAL OS
 *  \{
 *
 *  \file       Os_Hal_OsInt.h
 *  \brief      HAL interfaces which are visible to the user.
 *  \details
 *  This file is included by Os.h. Therefore all symbols defined here are visible to the user.
 *
 **********************************************************************************************************************/
 
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef OS_HAL_OSINT_H
# define OS_HAL_OSINT_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_Os_Types.h"

/* Os kernel module dependencies */
# include "Os_Lcfg.h"

/* Os hal dependencies */
# include "Os_Hal_Cfg.h"


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/*! \brief         Abstraction of Cat0 and Cat1 ISR definition.
 *  \details       This macro is provided for user to define a Cat0 or Cat1 interrupt service routine.
 */
# if defined (OS_STATIC_CODE_ANALYSIS)                                                                                  /* COV_OS_STATICCODEANALYSIS */
#  define OS_HAL_ISR0_DEFINE(IsrName)   void IsrName(void)                                                              /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define OS_HAL_ISR1_DEFINE(IsrName)   void IsrName(void)                                                              /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# else
#  if defined (OS_CFG_COMPILER_GNU)
#   define OS_HAL_ISR0_DEFINE(IsrName)   __attribute__((interrupt_handler)) void IsrName(void)                          /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#   define OS_HAL_ISR1_DEFINE(IsrName)   __attribute__((interrupt_handler)) void IsrName(void)                          /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  elif defined (OS_CFG_COMPILER_TASKING)   
#   define OS_HAL_ISR0_DEFINE(IsrName) \
    void __interrupt(OS_CFG_HAL_ISR_##IsrName##_LEVEL)  __vector_table(OS_CFG_HAL_ISR_##IsrName##_CORE) IsrName(void)   /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#   define OS_HAL_ISR1_DEFINE(IsrName) \
    void __interrupt(OS_CFG_HAL_ISR_##IsrName##_LEVEL)  __vector_table(OS_CFG_HAL_ISR_##IsrName##_CORE) IsrName(void)   /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#  else
#   error "Undefined or unsupported compiler"
#  endif
# endif

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/*! Set of hardware registers to be able to resume from an exception. */
struct Os_ExceptionContextType_Tag
{
  /* Stored Address registers of the thread (a2-a7, a12-a15)*/
  uint32 AddressRegisters[16];

  /* Stored Data registers of the thread (d0-d15)*/
  uint32 DataRegisters[16];

  /*! Stored return address of the thread */
  uint32 Ra;

  /*! Stored Psw of the thread */
  uint32 Psw;

  /*! Stored Exception source(Exception class and tin number) of the thread */
  uint32 ExceptionSource;

  /*! Stored Pcpn (Previous CPU Priority number) from the Pcxi of the thread */
  uint32 Pcpn;

  /*! Stored Pie (Previous Interrupt Enable) from the Pcxi of the thread */
  uint32 Pie;

  /*! The lower address of the MPU region for stack. */
  uint32 MpuRegionForStackLow;

  /*! The upper address of the MPU region for stack. */
  uint32 MpuRegionForStackUpper;
};

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#endif /* OS_HAL_OSINT_H */


/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_OsInt.h
 **********************************************************************************************************************/

