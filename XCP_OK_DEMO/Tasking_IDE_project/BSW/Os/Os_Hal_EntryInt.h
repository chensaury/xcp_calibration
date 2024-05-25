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
 *  \defgroup   Os_Hal HAL
 *  \brief      The HAL provides the platform specific low level part of the OS. It has to be implemented by the
 *              platform.
 *  \details    All files given here define the HAL and can be seen as a template to implement a new platform.
 */
/**
 *  \ingroup    Os_Hal
 *  \defgroup   Os_Hal_Entry  HAL Entry
 *  \brief      This component handles hardware exceptions and interrupts.
 *  \details
 *  Most of the HAL consists of macros and functions that are called by the kernel via the
 *  HAL interface. These perform the required low level operations by accessing the hardware and then return.
 *  The entry component is an exception to this. It handles exceptions: either synchronous hardware traps or
 *  asynchronous device interrupts. So we have some kind of control inversion here.
 *
 *  First the control is passed to the HAL, which then passes it to the kernel or the application.
 *  After the kernel has finished, control is passed back to the HAL for in order to restore the CPU
 *  state and resume processing from the point at which the exception occurred.
 *
 *  The exact implementation of this code is under the control of the HAL implementer. As long as it interacts
 *  correctly with the functions defined in Kernel Interface it may take any form. However there is typically
 *  the entry type pattern which is listed in this component description.
 *
 *  If there are any statements within a HAL function, which have influence to the control flow, the platform
 *  developer has to ensure that all paths are covered by tests (MC/DC). If this it not possible, the
 *  functionality has to be ensured by review.
 *
 *  Timing Protection Interrupt
 *  ---------------------------
 *  The kernel handles timing protection interrupts in an ISR. The ISR has to be executed with highest priority
 *  (or NMI).
 *
 *  Inter Processor Interrupt
 *  -------------------------
 *  The kernel handles inter processor interrupts in an ISR.
 *
 *   \{
 *  \file       Os_Hal_EntryInt.h
 *  \brief      This component handles hardware exceptions and interrupts.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/


#ifndef OS_HAL_ENTRYINT_H
# define OS_HAL_ENTRYINT_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */

/* Os kernel module dependencies */
# include "Os_KernelInt.h"
# include "Os_TrapInt.h"

/* Os hal dependencies */
# include "Os_Hal_CompilerInt.h"
# include "Os_Hal_InterruptInt.h"
# include "Os_Hal_TrapInt.h"


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */



/***********************************************************************************************************************
 *  Os_Hal_UnhandledExc()
 **********************************************************************************************************************/
/*! \brief    This handler is called, if an exception is triggered, which is not handled by the OS.
 *  \details  In this handler it is not safe to use the current stack pointer any longer, because the exception
 *            may be a result of an invalid stack pointer. For this reason the handler has to switch to the kernel
 *            stack before using any stack.
 *
 *            This handler shall call the kernel's Os_UnhandledExc() function.
 *            Os_UnhandledExc() expects the following parameters:
 *              <EXC-SOURCE>           The source number of the exception.
 *              <INSTRUCTION-ADDRESS>  The address of the causing instruction.
 *              <CAUSER-PRIVILEGED>    The privilege state before the exception:
 *                                       !0 Before the exception, the core was privileged.
 *                                       0  Before the exception, the core was not privileged.
 *
 *  \param[in]    ExceptionSource    The exception class and the TIN number
 *  \param[in]    Pcxi               The previous state.
 *  \param[in]    ExceptionAddress   The address of the instruction which caused the exception.
 *  \param[in]    SavedMpuRegionForStackLow     The value for the stack MPU region which has to be saved by C-Part of the Code
 *  \param[in]    SavedMpuRegionForStackUpper   The value for the stack MPU region which has to be saved by C-Part of the Code
 *  \context      ANY
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          Supervisor mode.
 *  \pre          Interrupts disabled.
 *  \pre          Concurrent access to given data shall be prevented.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(void, OS_CODE, OS_HAL_NOINLINE,
Os_Hal_UnhandledExc,
(
  Os_ExceptionSourceIdType ExceptionSource,
  uint32 Pcxi,
  Os_AddressOfConstType ExceptionAddress,
  uint32 SavedMpuRegionForStackLow,
  uint32 SavedMpuRegionForStackUpper
));


/***********************************************************************************************************************
 *  Os_Hal_MemFault()
 **********************************************************************************************************************/
/*! \brief        Performs the additional HAL specific prologue before the core function Os_MemFault is called.
 *  \details      This function shall save and restore the current context.
 *  \param[in]    ExceptionSource   The exception class and the TIN number
 *  \param[in]    Pcxi              The previous state.
 *  \param[in]    ExceptionAddress  The address of the instruction which caused the exception.
 *  \param[in]    SavedMpuRegionForStackLow     The value for the stack MPU region which has to be saved by C-Part of the Code
 *  \param[in]    SavedMpuRegionForStackUpper   The value for the stack MPU region which has to be saved by C-Part of the Code
 *  \context      ANY
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          Supervisor mode.
 *  \pre          Interrupts disabled.
 *  \pre          Concurrent access to given data shall be prevented.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(void, OS_CODE, OS_HAL_NOINLINE,
Os_Hal_MemFault,
(
  Os_ExceptionSourceIdType ExceptionSource,
  uint32 Pcxi,
  Os_AddressOfConstType ExceptionAddress,
  uint32 SavedMpuRegionForStackLow,
  uint32 SavedMpuRegionForStackUpper
));

/***********************************************************************************************************************
 *  Os_Hal_SysCall()
 **********************************************************************************************************************/
/*! \brief        Performs the HAL specific prologue before the core function Os_TrapHandler is called.
 *  \details      This function shall check the trap identification number and calculate the caller interrupt state.
 *  \param[in]    Tin    The trap identification number. It must be in range [0, 7].
 *  \param[in]    Pcxi   The previous state.
 *  \param[in]    Packet The parameter pointer. Parameter must not be NULL.
 *  \param[in]    Addr   The address of the instruction which was interrupted by syscall.
 *  \retval       The possibly modified PCXI, which is to be restored when system call returns.
 *  \context      ANY
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          Supervisor mode.
 *  \pre          Interrupts disabled.
 *  \pre          Concurrent access to given data shall be prevented.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(uint32, OS_CODE, OS_HAL_NOINLINE,
Os_Hal_SysCall,
(
  uint32 Tin,
  uint32 Pcxi,
  P2VAR(Os_TrapPacketType, AUTOMATIC, OS_VAR_NOINIT) Packet,
  Os_AddressOfConstType Addr
));


/***********************************************************************************************************************
 *  Os_Hal_IsrRun()
 **********************************************************************************************************************/
/*! \brief        Performs the HAL specific prologue before the core function Os_IsrRun is called.
 *  \details      This function shall forward the parameters to the function Os_IsrRun.
 *  \param[in]    Isr The ISR pointer. Parameter must not be NULL.
 *  \context      ANY
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          Supervisor mode.
 *  \pre          Interrupts disabled.
 *  \pre          Concurrent access to given data shall be prevented.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(void, OS_CODE, OS_HAL_NOINLINE,
Os_Hal_IsrRun,
(
  P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) Isr
));


/***********************************************************************************************************************
 *  Os_Hal_UnhandledIrq()
 **********************************************************************************************************************/
/*! \brief        Performs the HAL specific prologue before the core function Os_UnhandledIrq is called.
 *  \details      This function shall forward the parameters to the function Os_UnhandledIrq.
 *  \param[in]    InterruptSource   The interrupt level of the un-configured ISR.
 *  \param[in]    Pcxi              The previous state.
 *  \param[in]    InterruptAddress  The address of the instruction which was interrupted.
 *  \context      ANY
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          Supervisor mode.
 *  \pre          Interrupts disabled.
 *  \pre          Concurrent access to given data shall be prevented.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(void, OS_CODE, OS_HAL_NOINLINE,
Os_Hal_UnhandledIrq,
(
  Os_InterruptSourceIdType InterruptSource,
  uint32 Pcxi,
  Os_AddressOfConstType InterruptAddress
));

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_HAL_ENTRYINT_H */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_EntryInt.h
 **********************************************************************************************************************/
