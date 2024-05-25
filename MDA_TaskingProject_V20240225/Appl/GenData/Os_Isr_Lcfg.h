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
 *              File: Os_Isr_Lcfg.h
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

#ifndef OS_ISR_LCFG_H
# define OS_ISR_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Isr_Types.h"

/* Os kernel module dependencies */
# include "Os_Lcfg.h"
# include "Os_Timer_Types.h"
# include "Os_XSignal_Types.h"

/* Os hal dependencies */


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

/*! ISR configuration data: ADC0SR0_ISR */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_ADC0SR0_ISR;

/*! ISR configuration data: ADC1SR0_ISR */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_ADC1SR0_ISR;

/*! ISR configuration data: ADC2SR0_ISR */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_ADC2SR0_ISR;

/*! ISR configuration data: ADC3SR0_ISR */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_ADC3SR0_ISR;

/*! ISR configuration data: ADC8SR0_ISR */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_ADC8SR0_ISR;

/*! ISR configuration data: CanIsr_4 */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsr_4;

/*! ISR configuration data: CanIsr_5 */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsr_5;

/*! ISR configuration data: CounterIsr_SystemTimer0 */
extern CONST(Os_TimerIsrConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer0;

/*! ISR configuration data: DMACH0SR_ISR */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_DMACH0SR_ISR;

/*! ISR configuration data: DMACH3SR_ISR */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_DMACH3SR_ISR;

/*! ISR configuration data: DMACH4SR_ISR */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_DMACH4SR_ISR;

/*! ISR configuration data: DMACH5SR_ISR */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_DMACH5SR_ISR;

/*! ISR configuration data: DMACH6SR_ISR */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_DMACH6SR_ISR;

/*! ISR configuration data: DMACH7SR_ISR */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_DMACH7SR_ISR;

/*! ISR configuration data: DMACH8SR_ISR */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_DMACH8SR_ISR;

/*! ISR configuration data: DMACH9SR_ISR */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_DMACH9SR_ISR;

/*! ISR configuration data: DMAERR0SR_ISR */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_DMAERR0SR_ISR;

/*! ISR configuration data: GTMATOM0SR0_ISR */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_GTMATOM0SR0_ISR;

/*! ISR configuration data: GTMATOM1SR0_ISR */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_GTMATOM1SR0_ISR;

/*! ISR configuration data: GTMATOM2SR0_ISR */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_GTMATOM2SR0_ISR;

/*! ISR configuration data: GTMATOM4SR0_ISR */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_GTMATOM4SR0_ISR;

/*! ISR configuration data: GTMTIM2SR3_ISR */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_GTMTIM2SR3_ISR;

/*! ISR configuration data: GTMTIM2SR5_ISR */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_GTMTIM2SR5_ISR;

/*! ISR configuration data: GTMTOM0SR0_ISR */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_GTMTOM0SR0_ISR;

/*! ISR configuration data: GTMTOM0SR1_ISR */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_GTMTOM0SR1_ISR;

/*! ISR configuration data: GTMTOM0SR2_ISR */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_GTMTOM0SR2_ISR;

/*! ISR configuration data: GTMTOM0SR3_ISR */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_GTMTOM0SR3_ISR;

/*! ISR configuration data: QSPI0ERR_ISR */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_QSPI0ERR_ISR;

/*! ISR configuration data: QSPI0PT_ISR */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_QSPI0PT_ISR;

/*! ISR configuration data: QSPI1ERR_ISR */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_QSPI1ERR_ISR;

/*! ISR configuration data: QSPI1PT_ISR */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_QSPI1PT_ISR;

/*! ISR configuration data: QSPI2ERR_ISR */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_QSPI2ERR_ISR;

/*! ISR configuration data: QSPI2PT_ISR */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_QSPI2PT_ISR;

/*! ISR configuration data: QSPI3ERR_ISR */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_QSPI3ERR_ISR;

/*! ISR configuration data: QSPI3PT_ISR */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_QSPI3PT_ISR;

/*! ISR configuration data: XSignalIsr_OsCore0 */
extern CONST(Os_XSigIsrConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore0;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE1_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! ISR configuration data: CanIsr_0 */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsr_0;

/*! ISR configuration data: CounterIsr_SystemTimer1 */
extern CONST(Os_TimerIsrConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer1;

/*! ISR configuration data: XSignalIsr_OsCore1 */
extern CONST(Os_XSigIsrConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore1;

# define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE2_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! ISR configuration data: CanIsr_1 */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsr_1;

/*! ISR configuration data: CounterIsr_SystemTimer2 */
extern CONST(Os_TimerIsrConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer2;

/*! ISR configuration data: XSignalIsr_OsCore2 */
extern CONST(Os_XSigIsrConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore2;

# define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE3_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! ISR configuration data: CanIsr_2 */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsr_2;

/*! ISR configuration data: CounterIsr_SystemTimer3 */
extern CONST(Os_TimerIsrConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer3;

/*! ISR configuration data: XSignalIsr_OsCore3 */
extern CONST(Os_XSigIsrConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore3;

# define OS_STOP_SEC_CORE3_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE4_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! ISR configuration data: CanIsr_3 */
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsr_3;

/*! ISR configuration data: CounterIsr_SystemTimer4 */
extern CONST(Os_TimerIsrConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer4;

/*! ISR configuration data: XSignalIsr_OsCore4 */
extern CONST(Os_XSigIsrConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore4;

# define OS_STOP_SEC_CORE4_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE5_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! ISR configuration data: CounterIsr_SystemTimer5 */
extern CONST(Os_TimerIsrConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer5;

/*! ISR configuration data: XSignalIsr_OsCore5 */
extern CONST(Os_XSigIsrConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore5;

# define OS_STOP_SEC_CORE5_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for category 2 ISRs. */
extern CONSTP2CONST(Os_IsrConfigType, OS_CONST, OS_CONST) OsCfg_IsrRefs[OS_ISRID_COUNT + 1];  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_ISR_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Isr_Lcfg.h
 *********************************************************************************************************************/
