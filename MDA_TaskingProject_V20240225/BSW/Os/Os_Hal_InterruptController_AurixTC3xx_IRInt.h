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
 * \ingroup    Os_Hal
 * \addtogroup Os_Hal_Interrupt
 * \brief      Primitives definition on the Aurix TC3xx platform
 *
 * \{
 *
 * \file       Os_Hal_InterruptController_AurixTC3xx_IRInt.h
 * \brief      This file contains hardware specific definition on the Aurix platform, e.g.: register addresses
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


#ifndef OS_HAL_INTERRUPTCONTROLLER_AURIXTC3XX_IRINT_H
# define OS_HAL_INTERRUPTCONTROLLER_AURIXTC3XX_IRINT_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Base address of interrupt source controller registers. */
# define OS_HAL_INT_SRC_BASE                (OS_HAL_INTERRUPT_IR_BASE + 0x1000uL)
/*! bit mask for interrupt priority */
# define OS_HAL_INT_SRC_SRPN_MASK           0x000000FFuL
/*! bit mask for interrupt pending information */
# define OS_HAL_INT_SRC_SRR_MASK            0x01000000uL
/*! bit mask to clear interrupt pending flag */
# define OS_HAL_INT_SRC_CLRR_MASK           0x02000000uL
/*! bit mask for triggering interrupt sources */
# define OS_HAL_INT_SRC_SETR_MASK           0x04000000uL
/*! bit mask for enabling and disabling interrupt sources */
# define OS_HAL_INT_SRC_SRE_MASK            0x00000400uL
/*! bit mask for interrupts to cores assignment */
# define OS_HAL_INT_SRC_TOS_MASK            0x00003800uL



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

#endif /* OS_HAL_INTERRUPTCONTROLLER_AURIXTC3XX_IRINT_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_InterruptController_AurixTC3xx_IRInt.h
 *********************************************************************************************************************/
