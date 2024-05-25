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
 * \ingroup     Os_Hal
 * \addtogroup  Os_Hal_Timer
 *
 * \{
 *
 * \file       Os_Hal_Timer_GPT.h
 * \brief      This file contains hardware specific definition of GPT module
 *
 *********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/
                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */


#ifndef OS_HAL_TIMER_GPT_H
# define OS_HAL_TIMER_GPT_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_Timer_GPTInt.h"

/* Os kernel module dependencies */

/* Os Hal dependencies */
# include "Os_Hal_Interrupt.h"

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
 *  Os_Hal_TimerPitInit()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_TimerPitInit,
(
  P2CONST(Os_Hal_TimerPitConfigType, AUTOMATIC, OS_CONST) TimerConfig
))
{
  uint32 tempSRC;

  /* #10 Initial the counter register with the reload value. */
  *(volatile uint32*)TimerConfig->CounterRegisterAddress = TimerConfig->ReloadValue;                                    /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_GPTCONFIG */

  /* #20 Initial the reload register with the reload value. */
  *(volatile uint32*)TimerConfig->ReloadRegisterAddress = TimerConfig->ReloadValue;                                     /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_GPTCONFIG */

  /* #30 Configure the reload register. */
  *(volatile uint32*)TimerConfig->ReloadConfRegisterAddress = TimerConfig->ReloadConfRegisterValue;                     /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_GPTCONFIG */

  /* #40 Configure the counter register. */
  *(volatile uint32*)TimerConfig->CounterConfRegisterAddress = TimerConfig->CounterConfRegisterValue;                   /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_GPTCONFIG */
  
  /* #50 Enable the interrupt. */
  tempSRC = *(volatile uint32*)(TimerConfig->InterruptSRCRegisterAddress);                                              /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  tempSRC |= OS_HAL_INT_SRC_SRE_MASK;
  *(volatile uint32*) (TimerConfig->InterruptSRCRegisterAddress) = tempSRC;                                             /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */ /* SBSW_OS_HAL_PWA_GPTCONFIG */
}


/***********************************************************************************************************************
 *  Os_Hal_TimerPitAckAndReload()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_TimerPitAckAndReload,
(
  P2CONST(Os_Hal_TimerPitConfigType, AUTOMATIC, OS_CONST) TimerConfig
))
{
  /*!
   * \note There is no need to acknowledge a PIT. The reload value will automatically reloaded.
   */
  OS_IGNORE_UNREF_PARAM(TimerConfig);                                                                                   /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
}


/***********************************************************************************************************************
 *  Os_Hal_TimerPitIsPending()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE uint32, OS_CODE, OS_ALWAYS_INLINE,                                         /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_TimerPitIsPending,
(
  P2CONST(Os_Hal_TimerPitConfigType, AUTOMATIC, OS_CONST) TimerConfig
))
{
  /* #10 Return the pending bit from the interrupt source register. */
  return (*(volatile uint32*)TimerConfig->InterruptSRCRegisterAddress) & OS_HAL_INT_SRC_SRR_MASK;                       /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_HAL_TIMER_GPT_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Timer_GPT.h
 *********************************************************************************************************************/
