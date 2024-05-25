/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Os
 *           Program: MSR_Vector_SLP4
 *          Customer: Aptiv (China) Technology Company Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Aurix 2G/TC397 B-Step
 *    License Scope : The usage is restricted to CBD1900078_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Hal_Interrupt_Lcfg.h
 *   Generation Time: 2024-01-08 16:27:31
 *           Project: Bsw_Project - Version 1.0
 *          Delivery: CBD1900078_D01
 *      Tool Version: DaVinci Configurator (beta) 5.18.42 SP2
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Pro and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/


                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_HAL_INTERRUPT_LCFG_H
# define OS_HAL_INTERRUPT_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_Interrupt_Cfg.h"
# include "Os_Hal_Interrupt_Types.h"

/* Os kernel module dependencies */
# include "Os_Interrupt_Types.h"

/* Os hal dependencies */
# include "Os_Hal_Core_Types.h"


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
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL ISR configuration data: ADC0SR0_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_ADC0SR0_ISR;

/*! HAL ISR configuration data: ADC1SR0_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_ADC1SR0_ISR;

/*! HAL ISR configuration data: ADC2SR0_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_ADC2SR0_ISR;

/*! HAL ISR configuration data: ADC3SR0_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_ADC3SR0_ISR;

/*! HAL ISR configuration data: ADC8SR0_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_ADC8SR0_ISR;

/*! HAL ISR configuration data: CanIsr_4 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsr_4;

/*! HAL ISR configuration data: CanIsr_5 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsr_5;

/*! HAL ISR configuration data: CounterIsr_SystemTimer0 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CounterIsr_SystemTimer0;

/*! HAL ISR configuration data: DMACH0SR_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_DMACH0SR_ISR;

/*! HAL ISR configuration data: DMACH3SR_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_DMACH3SR_ISR;

/*! HAL ISR configuration data: DMACH4SR_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_DMACH4SR_ISR;

/*! HAL ISR configuration data: DMACH5SR_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_DMACH5SR_ISR;

/*! HAL ISR configuration data: DMACH6SR_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_DMACH6SR_ISR;

/*! HAL ISR configuration data: DMACH7SR_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_DMACH7SR_ISR;

/*! HAL ISR configuration data: DMACH8SR_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_DMACH8SR_ISR;

/*! HAL ISR configuration data: DMACH9SR_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_DMACH9SR_ISR;

/*! HAL ISR configuration data: DMAERR0SR_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_DMAERR0SR_ISR;

/*! HAL ISR configuration data: GTMATOM0SR0_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_GTMATOM0SR0_ISR;

/*! HAL ISR configuration data: GTMATOM1SR0_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_GTMATOM1SR0_ISR;

/*! HAL ISR configuration data: GTMATOM2SR0_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_GTMATOM2SR0_ISR;

/*! HAL ISR configuration data: GTMATOM4SR0_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_GTMATOM4SR0_ISR;

/*! HAL ISR configuration data: GTMTIM2SR3_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_GTMTIM2SR3_ISR;

/*! HAL ISR configuration data: GTMTIM2SR5_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_GTMTIM2SR5_ISR;

/*! HAL ISR configuration data: GTMTOM0SR0_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_GTMTOM0SR0_ISR;

/*! HAL ISR configuration data: GTMTOM0SR1_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_GTMTOM0SR1_ISR;

/*! HAL ISR configuration data: GTMTOM0SR2_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_GTMTOM0SR2_ISR;

/*! HAL ISR configuration data: GTMTOM0SR3_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_GTMTOM0SR3_ISR;

/*! HAL ISR configuration data: QSPI0ERR_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_QSPI0ERR_ISR;

/*! HAL ISR configuration data: QSPI0PT_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_QSPI0PT_ISR;

/*! HAL ISR configuration data: QSPI1ERR_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_QSPI1ERR_ISR;

/*! HAL ISR configuration data: QSPI1PT_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_QSPI1PT_ISR;

/*! HAL ISR configuration data: QSPI2ERR_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_QSPI2ERR_ISR;

/*! HAL ISR configuration data: QSPI2PT_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_QSPI2PT_ISR;

/*! HAL ISR configuration data: QSPI3ERR_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_QSPI3ERR_ISR;

/*! HAL ISR configuration data: QSPI3PT_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_QSPI3PT_ISR;

/*! HAL ISR configuration data: XSignalIsr_OsCore0 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_XSignalIsr_OsCore0;

/*! HAL X-Signal ISR configuration data: XSignalIsr_OsCore0 */
extern CONST(Os_Hal_XSigInterruptConfigType, OS_CONST) OsCfg_Hal_XSig_XSignalIsr_OsCore0;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE1_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL ISR configuration data: CanIsr_0 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsr_0;

/*! HAL ISR configuration data: CounterIsr_SystemTimer1 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CounterIsr_SystemTimer1;

/*! HAL ISR configuration data: XSignalIsr_OsCore1 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_XSignalIsr_OsCore1;

/*! HAL X-Signal ISR configuration data: XSignalIsr_OsCore1 */
extern CONST(Os_Hal_XSigInterruptConfigType, OS_CONST) OsCfg_Hal_XSig_XSignalIsr_OsCore1;

# define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE2_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL ISR configuration data: CanIsr_1 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsr_1;

/*! HAL ISR configuration data: CounterIsr_SystemTimer2 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CounterIsr_SystemTimer2;

/*! HAL ISR configuration data: XSignalIsr_OsCore2 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_XSignalIsr_OsCore2;

/*! HAL X-Signal ISR configuration data: XSignalIsr_OsCore2 */
extern CONST(Os_Hal_XSigInterruptConfigType, OS_CONST) OsCfg_Hal_XSig_XSignalIsr_OsCore2;

# define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE3_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL ISR configuration data: CanIsr_2 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsr_2;

/*! HAL ISR configuration data: CounterIsr_SystemTimer3 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CounterIsr_SystemTimer3;

/*! HAL ISR configuration data: XSignalIsr_OsCore3 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_XSignalIsr_OsCore3;

/*! HAL X-Signal ISR configuration data: XSignalIsr_OsCore3 */
extern CONST(Os_Hal_XSigInterruptConfigType, OS_CONST) OsCfg_Hal_XSig_XSignalIsr_OsCore3;

# define OS_STOP_SEC_CORE3_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE4_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL ISR configuration data: CanIsr_3 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsr_3;

/*! HAL ISR configuration data: CounterIsr_SystemTimer4 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CounterIsr_SystemTimer4;

/*! HAL ISR configuration data: XSignalIsr_OsCore4 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_XSignalIsr_OsCore4;

/*! HAL X-Signal ISR configuration data: XSignalIsr_OsCore4 */
extern CONST(Os_Hal_XSigInterruptConfigType, OS_CONST) OsCfg_Hal_XSig_XSignalIsr_OsCore4;

# define OS_STOP_SEC_CORE4_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE5_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL ISR configuration data: CounterIsr_SystemTimer5 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CounterIsr_SystemTimer5;

/*! HAL ISR configuration data: XSignalIsr_OsCore5 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_XSignalIsr_OsCore5;

/*! HAL X-Signal ISR configuration data: XSignalIsr_OsCore5 */
extern CONST(Os_Hal_XSigInterruptConfigType, OS_CONST) OsCfg_Hal_XSig_XSignalIsr_OsCore5;

# define OS_STOP_SEC_CORE5_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_HAL_INTERRUPT_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Interrupt_Lcfg.h
 *********************************************************************************************************************/
