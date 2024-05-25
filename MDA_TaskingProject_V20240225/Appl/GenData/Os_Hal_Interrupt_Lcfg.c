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
 *              File: Os_Hal_Interrupt_Lcfg.c
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

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_HAL_INTERRUPT_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Interrupt_Lcfg.h"
#include "Os_Hal_Interrupt.h"

/* Os kernel module dependencies */

/* Os hal dependencies */
#include "Os_Hal_Core.h"


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL ISR configuration data: ADC0SR0_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_ADC0SR0_ISR =
{
  /* .Level          = */ 22,
  /* .Source         = */ 0x670uL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: ADC1SR0_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_ADC1SR0_ISR =
{
  /* .Level          = */ 23,
  /* .Source         = */ 0x680uL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: ADC2SR0_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_ADC2SR0_ISR =
{
  /* .Level          = */ 24,
  /* .Source         = */ 0x690uL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: ADC3SR0_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_ADC3SR0_ISR =
{
  /* .Level          = */ 25,
  /* .Source         = */ 0x6a0uL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: ADC8SR0_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_ADC8SR0_ISR =
{
  /* .Level          = */ 48,
  /* .Source         = */ 0x6f0uL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: CanIsr_4 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsr_4 =
{
  /* .Level          = */ 69,
  /* .Source         = */ 0x5f0uL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: CanIsr_5 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsr_5 =
{
  /* .Level          = */ 49,
  /* .Source         = */ 0x5f4uL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: CounterIsr_SystemTimer0 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CounterIsr_SystemTimer0 =
{
  /* .Level          = */ 12,
  /* .Source         = */ 0x300uL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: DMACH0SR_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_DMACH0SR_ISR =
{
  /* .Level          = */ 26,
  /* .Source         = */ 0x370uL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: DMACH3SR_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_DMACH3SR_ISR =
{
  /* .Level          = */ 27,
  /* .Source         = */ 0x37cuL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: DMACH4SR_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_DMACH4SR_ISR =
{
  /* .Level          = */ 28,
  /* .Source         = */ 0x380uL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: DMACH5SR_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_DMACH5SR_ISR =
{
  /* .Level          = */ 29,
  /* .Source         = */ 0x384uL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: DMACH6SR_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_DMACH6SR_ISR =
{
  /* .Level          = */ 30,
  /* .Source         = */ 0x388uL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: DMACH7SR_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_DMACH7SR_ISR =
{
  /* .Level          = */ 31,
  /* .Source         = */ 0x38cuL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: DMACH8SR_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_DMACH8SR_ISR =
{
  /* .Level          = */ 32,
  /* .Source         = */ 0x390uL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: DMACH9SR_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_DMACH9SR_ISR =
{
  /* .Level          = */ 33,
  /* .Source         = */ 0x394uL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: DMAERR0SR_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_DMAERR0SR_ISR =
{
  /* .Level          = */ 47,
  /* .Source         = */ 0x340uL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: GTMATOM0SR0_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_GTMATOM0SR0_ISR =
{
  /* .Level          = */ 55,
  /* .Source         = */ 0xef0uL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: GTMATOM1SR0_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_GTMATOM1SR0_ISR =
{
  /* .Level          = */ 56,
  /* .Source         = */ 0xf00uL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: GTMATOM2SR0_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_GTMATOM2SR0_ISR =
{
  /* .Level          = */ 57,
  /* .Source         = */ 0xf10uL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: GTMATOM4SR0_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_GTMATOM4SR0_ISR =
{
  /* .Level          = */ 58,
  /* .Source         = */ 0xf30uL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: GTMTIM2SR3_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_GTMTIM2SR3_ISR =
{
  /* .Level          = */ 59,
  /* .Source         = */ 0xbdcuL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: GTMTIM2SR5_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_GTMTIM2SR5_ISR =
{
  /* .Level          = */ 60,
  /* .Source         = */ 0xbe4uL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: GTMTOM0SR0_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_GTMTOM0SR0_ISR =
{
  /* .Level          = */ 61,
  /* .Source         = */ 0xe10uL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: GTMTOM0SR1_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_GTMTOM0SR1_ISR =
{
  /* .Level          = */ 62,
  /* .Source         = */ 0xe14uL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: GTMTOM0SR2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_GTMTOM0SR2_ISR =
{
  /* .Level          = */ 63,
  /* .Source         = */ 0xe18uL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: GTMTOM0SR3_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_GTMTOM0SR3_ISR =
{
  /* .Level          = */ 64,
  /* .Source         = */ 0xe1cuL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: QSPI0ERR_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_QSPI0ERR_ISR =
{
  /* .Level          = */ 45,
  /* .Source         = */ 0xf8uL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: QSPI0PT_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_QSPI0PT_ISR =
{
  /* .Level          = */ 46,
  /* .Source         = */ 0xfcuL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: QSPI1ERR_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_QSPI1ERR_ISR =
{
  /* .Level          = */ 43,
  /* .Source         = */ 0x10cuL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: QSPI1PT_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_QSPI1PT_ISR =
{
  /* .Level          = */ 44,
  /* .Source         = */ 0x110uL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: QSPI2ERR_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_QSPI2ERR_ISR =
{
  /* .Level          = */ 39,
  /* .Source         = */ 0x120uL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: QSPI2PT_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_QSPI2PT_ISR =
{
  /* .Level          = */ 40,
  /* .Source         = */ 0x124uL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: QSPI3ERR_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_QSPI3ERR_ISR =
{
  /* .Level          = */ 41,
  /* .Source         = */ 0x134uL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: QSPI3PT_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_QSPI3PT_ISR =
{
  /* .Level          = */ 42,
  /* .Source         = */ 0x138uL,
  /* .CoreAssignment = */ 0
};

/*! HAL ISR configuration data: XSignalIsr_OsCore0 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_XSignalIsr_OsCore0 =
{
  /* .Level          = */ 18,
  /* .Source         = */ 0x990uL,
  /* .CoreAssignment = */ 0
};

/*! HAL X-Signal ISR configuration data: XSignalIsr_OsCore0 */
CONST(Os_Hal_XSigInterruptConfigType, OS_CONST) OsCfg_Hal_XSig_XSignalIsr_OsCore0 =
{
  /* .ConfigData  = */ &OsCfg_Hal_IntIsr_XSignalIsr_OsCore0,
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL ISR configuration data: CanIsr_0 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsr_0 =
{
  /* .Level          = */ 21,
  /* .Source         = */ 0x5b0uL,
  /* .CoreAssignment = */ 2
};

/*! HAL ISR configuration data: CounterIsr_SystemTimer1 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CounterIsr_SystemTimer1 =
{
  /* .Level          = */ 20,
  /* .Source         = */ 0x308uL,
  /* .CoreAssignment = */ 2
};

/*! HAL ISR configuration data: XSignalIsr_OsCore1 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_XSignalIsr_OsCore1 =
{
  /* .Level          = */ 18,
  /* .Source         = */ 0xb40uL,
  /* .CoreAssignment = */ 2
};

/*! HAL X-Signal ISR configuration data: XSignalIsr_OsCore1 */
CONST(Os_Hal_XSigInterruptConfigType, OS_CONST) OsCfg_Hal_XSig_XSignalIsr_OsCore1 =
{
  /* .ConfigData  = */ &OsCfg_Hal_IntIsr_XSignalIsr_OsCore1,
};

#define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL ISR configuration data: CanIsr_1 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsr_1 =
{
  /* .Level          = */ 66,
  /* .Source         = */ 0x5b4uL,
  /* .CoreAssignment = */ 3
};

/*! HAL ISR configuration data: CounterIsr_SystemTimer2 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CounterIsr_SystemTimer2 =
{
  /* .Level          = */ 20,
  /* .Source         = */ 0x310uL,
  /* .CoreAssignment = */ 3
};

/*! HAL ISR configuration data: XSignalIsr_OsCore2 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_XSignalIsr_OsCore2 =
{
  /* .Level          = */ 18,
  /* .Source         = */ 0x9d0uL,
  /* .CoreAssignment = */ 3
};

/*! HAL X-Signal ISR configuration data: XSignalIsr_OsCore2 */
CONST(Os_Hal_XSigInterruptConfigType, OS_CONST) OsCfg_Hal_XSig_XSignalIsr_OsCore2 =
{
  /* .ConfigData  = */ &OsCfg_Hal_IntIsr_XSignalIsr_OsCore2,
};

#define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE3_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL ISR configuration data: CanIsr_2 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsr_2 =
{
  /* .Level          = */ 67,
  /* .Source         = */ 0x5b8uL,
  /* .CoreAssignment = */ 4
};

/*! HAL ISR configuration data: CounterIsr_SystemTimer3 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CounterIsr_SystemTimer3 =
{
  /* .Level          = */ 20,
  /* .Source         = */ 0x318uL,
  /* .CoreAssignment = */ 4
};

/*! HAL ISR configuration data: XSignalIsr_OsCore3 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_XSignalIsr_OsCore3 =
{
  /* .Level          = */ 18,
  /* .Source         = */ 0x9f0uL,
  /* .CoreAssignment = */ 4
};

/*! HAL X-Signal ISR configuration data: XSignalIsr_OsCore3 */
CONST(Os_Hal_XSigInterruptConfigType, OS_CONST) OsCfg_Hal_XSig_XSignalIsr_OsCore3 =
{
  /* .ConfigData  = */ &OsCfg_Hal_IntIsr_XSignalIsr_OsCore3,
};

#define OS_STOP_SEC_CORE3_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE4_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL ISR configuration data: CanIsr_3 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsr_3 =
{
  /* .Level          = */ 68,
  /* .Source         = */ 0x5bcuL,
  /* .CoreAssignment = */ 5
};

/*! HAL ISR configuration data: CounterIsr_SystemTimer4 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CounterIsr_SystemTimer4 =
{
  /* .Level          = */ 20,
  /* .Source         = */ 0x320uL,
  /* .CoreAssignment = */ 5
};

/*! HAL ISR configuration data: XSignalIsr_OsCore4 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_XSignalIsr_OsCore4 =
{
  /* .Level          = */ 18,
  /* .Source         = */ 0xa10uL,
  /* .CoreAssignment = */ 5
};

/*! HAL X-Signal ISR configuration data: XSignalIsr_OsCore4 */
CONST(Os_Hal_XSigInterruptConfigType, OS_CONST) OsCfg_Hal_XSig_XSignalIsr_OsCore4 =
{
  /* .ConfigData  = */ &OsCfg_Hal_IntIsr_XSignalIsr_OsCore4,
};

#define OS_STOP_SEC_CORE4_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE5_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL ISR configuration data: CounterIsr_SystemTimer5 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CounterIsr_SystemTimer5 =
{
  /* .Level          = */ 20,
  /* .Source         = */ 0x328uL,
  /* .CoreAssignment = */ 6
};

/*! HAL ISR configuration data: XSignalIsr_OsCore5 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_XSignalIsr_OsCore5 =
{
  /* .Level          = */ 18,
  /* .Source         = */ 0xa30uL,
  /* .CoreAssignment = */ 6
};

/*! HAL X-Signal ISR configuration data: XSignalIsr_OsCore5 */
CONST(Os_Hal_XSigInterruptConfigType, OS_CONST) OsCfg_Hal_XSig_XSignalIsr_OsCore5 =
{
  /* .ConfigData  = */ &OsCfg_Hal_IntIsr_XSignalIsr_OsCore5,
};

#define OS_STOP_SEC_CORE5_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Interrupt_Lcfg.c
 *********************************************************************************************************************/
