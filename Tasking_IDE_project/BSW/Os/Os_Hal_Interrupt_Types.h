/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**
 *  \addtogroup Os_Hal_Interrupt
 *  \{
 *
 *  \file    Os_Hal_Interrupt_Types.h
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef OS_HAL_INTERRUPT_TYPES_H
# define OS_HAL_INTERRUPT_TYPES_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */

/* Os kernel module dependencies */

/* Os HAL dependencies */


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/*! \brief    Interrupt state.
 *  \details  The kernel uses this data type to suspend/resume interrupts, also in case of timing protection and
 *            to protect OS internal critical sections.
 *            This type is typically some kind of bit mask (e.g. processor status word).
 *            Variables of this type store the global interrupt state and is defined as a bit mask of ICR register.
 *            ICR with the IE mask:           0b 0000 0000 0000 0000 X000 0000 0000 0000
 *            Interrupt is globally enabled:  0b 0000 0000 0000 0000 1000 0000 0000 0000
 *            Interrupt is globally disabled: 0b 0000 0000 0000 0000 0000 0000 0000 0000 */
typedef uint32 Os_Hal_IntGlobalStateType;

/*! \brief    Interrupt level.
 *  \details  The kernel uses this data type to suspend/resume category 2 ISRs up to a certain level.
 *            This data type is needed to implement interrupt resources.
 *            Variables of this type store interrupt level and is a bit mask of ICR register.
 *            ICR with the CCPN mask: 0x 00 00 00 XX */
typedef uint32 Os_Hal_IntLevelType;

/*! \brief    Interrupt state (with trap information).
 *  \details  The kernel uses this data type to restore the caller's interrupt state on OS service requests.
 *            On TriCore this data type also contains a pointer to the user space CSA.
 *            Variables of this type store interrupt level and global state, which is a bit mask of ICR register.
 *            Variables of this type is used to store and restore interrupt states during system calls.
 *            ICR with the IE mask:   0b 0000 0000 0000 0000 X000 0000 0000 0000
 *            ICR with the CCPN mask: 0x 00 00 00 XX */
typedef uint32 Os_Hal_IntTrapStateType;

/*! \brief    Data type containing the complete interrupt state including global state and level.
 *  \details  Variables of this type store interrupt level and global state, which is a bit mask of ICR register.
 *            Variables of this type is used to store and restore interrupt states during service function calls.
 *            ICR with the IE mask:   0b 0000 0000 0000 0000 X000 0000 0000 0000
 *            ICR with the CCPN mask: 0x 00 00 00 XX */
typedef uint32 Os_Hal_IntStateType;

/*! \brief    Interrupt source.
 *  \details  The kernel uses this data type to disable an interrupt source.
 *            This data type is needed to implement killing of applications.
 *            It is typically an interrupt index or interrupt source address. */
typedef uint32 Os_Hal_IntSourceType;

/*! Forward declaration of Os_Hal_IntIsrConfigType */
struct Os_Hal_IntIsrConfigType_Tag;
typedef struct Os_Hal_IntIsrConfigType_Tag Os_Hal_IntIsrConfigType;


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


#endif /* OS_HAL_INTERRUPT_TYPES_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Interrupt_Types.h
 **********************************************************************************************************************/

