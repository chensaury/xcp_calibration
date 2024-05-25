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
 * \file       Os_Hal_Timer_STMInt.h
 * \brief      This file contains hardware specific declaration of the STM module
 *
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
 *********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/


#ifndef OS_HAL_TIMER_STMINT_H
# define OS_HAL_TIMER_STMINT_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_Timer_STM_Types.h"

/* Os kernel module dependencies */

/* Os Hal dependencies */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* STM registers */
/*! Offset of TIM0 */
# define OS_HAL_TIMER_STM_TIM0_OFFSET             0x10u
/*! Offset of TIM5 */
# define OS_HAL_TIMER_STM_TIM5_OFFSET             0x24u
/*! Offset of TIM6 */
# define OS_HAL_TIMER_STM_TIM6_OFFSET             0x28u
/*! Offset of CAP */
# define OS_HAL_TIMER_STM_CAP_OFFSET              0x10u
/*! Offset of CMP0 */
# define OS_HAL_TIMER_STM_CMP0_OFFSET             0x30u
/*! Offset of CMP1 */
# define OS_HAL_TIMER_STM_CMP1_OFFSET             0x34u
/*! Offset of CMCON */
# define OS_HAL_TIMER_STM_CMCON_OFFSET            0x38u
/*! Bit mask for CMCON register if the compare channel 0 is used */
# define OS_HAL_TIMER_STM_CMCON_USE_CMP0_MASK     0xFFFF0000uL
/*! Bit value for CMCON register if the compare channel 0 is used */
# define OS_HAL_TIMER_STM_CMCON_USE_CMP0_VALUE    0x0000001FuL
/*! Bit mask for CMCON register if the compare channel 1 is used */
# define OS_HAL_TIMER_STM_CMCON_USE_CMP1_MASK     0x0000FFFFuL
/*! Bit value for CMCON register if the compare channel 1 is used */
# define OS_HAL_TIMER_STM_CMCON_USE_CMP1_VALUE    0x001F0000uL
/*! Offset of ICR */
# define OS_HAL_TIMER_STM_ICR_OFFSET              0x3Cu
/*! Bit mask for ICR register if the compare channel 0 is used */
# define OS_HAL_TIMER_STM_ICR_USE_CMP0_MASK       0x00000070uL
/*! Bit value for ICR register if the compare channel 0 is used */
# define OS_HAL_TIMER_STM_ICR_USE_CMP0_VALUE      0x00000001uL
/*! Bit mask for ICR register if the compare channel 1 is used */
# define OS_HAL_TIMER_STM_ICR_USE_CMP1_MASK       0x00000007uL
/*! Bit value for ICR register if the compare channel 1 is used */
# define OS_HAL_TIMER_STM_ICR_USE_CMP1_VALUE      0x00000050uL


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*! High resolution timer configuration information. */
struct Os_Hal_TimerFrtConfigType_Tag
{
  /*! This is the address of the counter register */
  uint32 CounterRegisterAddress;

  /*! This is the address of the compare register */
  uint32 CompareRegisterAddress;

  /*! This is the address of the CMCON register */
  uint32 CMCONRegisterAddress;

  /*! This is the mask for the CMCON register */
  uint32 CMCONMask;

  /*! This is the value for the CMCON register */
  uint32 CMCONValue;

  /*! This is the address of the interrupt source register used by this timer */
  uint32 InterruptSRCRegisterAddress;

  /*! This is the address of the ICR register */
  uint32 ICRRegisterAddress;

  /*! This is the mask for the ICR register */
  uint32 ICRMask;

  /*! This is the value for the ICR register */
  uint32 ICRValue;

  /*! This is the reload value, if this timer is used to simulate a PIT */
  uint32 ReloadValue;

};

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  Os_Hal_TimerFrtInit()
 **********************************************************************************************************************/
/*! \brief          Initialize a free running timer using the given configuration.
 *  \details
 *  The kernel uses this function during OS initialization to initialize hardware timers.
 *  Enable the interrupt source of the hardware timer.
 *
 *  \param[in]      TimerConfig     Timer hardware configuration. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode
 *  \pre            Concurrent access is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_TimerFrtInit,
(
  P2CONST(Os_Hal_TimerFrtConfigType, AUTOMATIC, OS_CONST) TimerConfig
));


/***********************************************************************************************************************
 *  Os_Hal_TimerFrtGetCounterValue()
 **********************************************************************************************************************/
/*! \brief          Return the current counter register value of the given free running timer.
 *  \details
 *  The kernel uses this function to implement the AUTOSAR counter interface in case of a free running timer.
 *
 *  \param[in]      TimerConfig     Timer hardware configuration. Parameter must not be NULL.
 *
 *  \return         Current counter register value.
 *
 *  \context        OS_INTERNAL|ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode
 *  \pre            Concurrent access prevented by caller.
 *  \trace          SPEC-63797
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_Hal_TimerFrtTickType, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_TimerFrtGetCounterValue,
(
  P2CONST(Os_Hal_TimerFrtConfigType, AUTOMATIC, OS_CONST) TimerConfig
));


/***********************************************************************************************************************
 *  Os_Hal_TimerFrtSetCompareValue()
 **********************************************************************************************************************/
/*! \brief          Set the compare value of the given HRT.
 *  \details
 *  This function shall set the compare value of the given timer.
 *
 *  \param[in,out]  TimerConfig     Timer hardware configuration. Parameter must not be NULL.
 *  \param[in]      ExpirationTime  The new compare value.
 *
 *  \context        ISR2|OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode
 *  \pre            Concurrent access is prevented by caller.
 *  \trace          SPEC-63797
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_TimerFrtSetCompareValue,
(
  P2CONST(Os_Hal_TimerFrtConfigType, AUTOMATIC, OS_CONST) TimerConfig,
  Os_Hal_TimerFrtTickType ExpirationTime
));


/***********************************************************************************************************************
 *  Os_Hal_TimerFrtAcknowledge()
 **********************************************************************************************************************/
/*! \brief          Tell the timer hardware, that we are handling the interrupt request.
 *  \details
 *  The kernel uses this function to implement the FRT ISR. It is used to clear pending timer interrupt flags,
 *  to be able to configure the next timer interrupt.
 *
 *  \param[in]      TimerConfig     Timer hardware configuration. Parameter must not be NULL.
 *
 *  \context        ISR2|OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode
 *  \pre            Concurrent access is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_TimerFrtAcknowledge,
(
  P2CONST(Os_Hal_TimerFrtConfigType, AUTOMATIC, OS_CONST) TimerConfig
));


/***********************************************************************************************************************
 *  Os_Hal_TimerFrtTriggerIrq()
 **********************************************************************************************************************/
/*! \brief          Triggers a HRT timer interrupt.
 *  \details        The kernel uses this function, to trigger a timer ISR, if it detects that an expiration time stamp
 *                  has been missed.
 *
 *  \param[in]      TimerConfig     Timer hardware configuration. Parameter must not be NULL.
 *
 *  \context        ISR2|OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Supervisor mode
 *  \pre            Concurrent access is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_TimerFrtTriggerIrq,
(
  P2CONST(Os_Hal_TimerFrtConfigType, AUTOMATIC, OS_CONST) TimerConfig
));


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_HAL_TIMER_STMINT_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Timer_STMInt.h
 *********************************************************************************************************************/
