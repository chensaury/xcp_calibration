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
 *              File: Os_Hal_Core_Lcfg.c
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

#define OS_HAL_CORE_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Core_Lcfg.h"
#include "Os_Hal_Core.h"

/* Os kernel module dependencies */

/* Os hal dependencies */
#include "Os_Hal_Context_Lcfg.h"
#include "Os_Hal_Entry_Lcfg.h"
#include "Os_Hal_Interrupt_Lcfg.h"
#include "Os_Hal_Kernel_Lcfg.h"


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

#define OS_START_SEC_CORE0_VAR_FAST_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic core to thread data: OsCore0 */
OS_LOCAL VAR(Os_Hal_Core2ThreadType, OS_VAR_NOINIT_FAST) OsCfg_Hal_Core2Thread_OsCore0_Dyn;

#define OS_STOP_SEC_CORE0_VAR_FAST_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE1_VAR_FAST_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic core to thread data: OsCore1 */
OS_LOCAL VAR(Os_Hal_Core2ThreadType, OS_VAR_NOINIT_FAST) OsCfg_Hal_Core2Thread_OsCore1_Dyn;

#define OS_STOP_SEC_CORE1_VAR_FAST_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE2_VAR_FAST_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic core to thread data: OsCore2 */
OS_LOCAL VAR(Os_Hal_Core2ThreadType, OS_VAR_NOINIT_FAST) OsCfg_Hal_Core2Thread_OsCore2_Dyn;

#define OS_STOP_SEC_CORE2_VAR_FAST_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE3_VAR_FAST_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic core to thread data: OsCore3 */
OS_LOCAL VAR(Os_Hal_Core2ThreadType, OS_VAR_NOINIT_FAST) OsCfg_Hal_Core2Thread_OsCore3_Dyn;

#define OS_STOP_SEC_CORE3_VAR_FAST_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE4_VAR_FAST_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic core to thread data: OsCore4 */
OS_LOCAL VAR(Os_Hal_Core2ThreadType, OS_VAR_NOINIT_FAST) OsCfg_Hal_Core2Thread_OsCore4_Dyn;

#define OS_STOP_SEC_CORE4_VAR_FAST_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE5_VAR_FAST_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic core to thread data: OsCore5 */
OS_LOCAL VAR(Os_Hal_Core2ThreadType, OS_VAR_NOINIT_FAST) OsCfg_Hal_Core2Thread_OsCore5_Dyn;

#define OS_STOP_SEC_CORE5_VAR_FAST_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL core initialized interrupt sources: OsCore0 */
CONSTP2CONST(Os_Hal_IntIsrConfigType, OS_CONST, OS_CONST)
  OsCfg_Hal_Core_OsCore0_InterruptSourceRefs[OS_CFG_NUM_CORE_OSCORE0_INTERRUPTSOURCEREFS + 1u] =
{
  /* No core exclusive interrupt sources to be initialized by OsCore0. */
  NULL_PTR
};


/*! HAL core configuration data: OsCore0 */
CONST(Os_Hal_CoreConfigType, OS_CONST) OsCfg_Hal_Core_OsCore0 =
{
  /* .CoreId                  = */ 0, /* Physical id of OsCore0 */
  /* .ProgramCounterRegister  = */ 0,
  /* .StartLabelAddress       = */ 0,
  /* .DBGSRRegister           = */ 0,
  /* .SYSCONRegister          = */ 0
}
;

/*! HAL AUTOSAR core configuration data: OsCore0 */
CONST(Os_Hal_CoreAsrConfigType, OS_CONST) OsCfg_Hal_CoreAsr_OsCore0 =
{
  /* .CoreId        = */ 0, /* This is the logical id of the core */
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL core initialized interrupt sources: OsCore1 */
CONSTP2CONST(Os_Hal_IntIsrConfigType, OS_CONST, OS_CONST)
  OsCfg_Hal_Core_OsCore1_InterruptSourceRefs[OS_CFG_NUM_CORE_OSCORE1_INTERRUPTSOURCEREFS + 1u] =
{
  /* No core exclusive interrupt sources to be initialized by OsCore1. */
  NULL_PTR
};


/*! HAL core configuration data: OsCore1 */
CONST(Os_Hal_CoreConfigType, OS_CONST) OsCfg_Hal_Core_OsCore1 =
{
  /* .CoreId                  = */ 1, /* Physical id of OsCore1 */
  /* .ProgramCounterRegister  = */ OS_HAL_CORE1_PC,
  /* .StartLabelAddress       = */ (uint32)&(_start_tc1), /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */
  /* .DBGSRRegister           = */ OS_HAL_CORE1_DBGSR,
  /* .SYSCONRegister          = */ OS_HAL_CORE1_SYSCON
}
;

/*! HAL AUTOSAR core configuration data: OsCore1 */
CONST(Os_Hal_CoreAsrConfigType, OS_CONST) OsCfg_Hal_CoreAsr_OsCore1 =
{
  /* .CoreId        = */ 1, /* This is the logical id of the core */
};

#define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL core initialized interrupt sources: OsCore2 */
CONSTP2CONST(Os_Hal_IntIsrConfigType, OS_CONST, OS_CONST)
  OsCfg_Hal_Core_OsCore2_InterruptSourceRefs[OS_CFG_NUM_CORE_OSCORE2_INTERRUPTSOURCEREFS + 1u] =
{
  /* No core exclusive interrupt sources to be initialized by OsCore2. */
  NULL_PTR
};


/*! HAL core configuration data: OsCore2 */
CONST(Os_Hal_CoreConfigType, OS_CONST) OsCfg_Hal_Core_OsCore2 =
{
  /* .CoreId                  = */ 2, /* Physical id of OsCore2 */
  /* .ProgramCounterRegister  = */ OS_HAL_CORE2_PC,
  /* .StartLabelAddress       = */ (uint32)&(_start_tc2), /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */
  /* .DBGSRRegister           = */ OS_HAL_CORE2_DBGSR,
  /* .SYSCONRegister          = */ OS_HAL_CORE2_SYSCON
}
;

/*! HAL AUTOSAR core configuration data: OsCore2 */
CONST(Os_Hal_CoreAsrConfigType, OS_CONST) OsCfg_Hal_CoreAsr_OsCore2 =
{
  /* .CoreId        = */ 2, /* This is the logical id of the core */
};

#define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE3_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL core initialized interrupt sources: OsCore3 */
CONSTP2CONST(Os_Hal_IntIsrConfigType, OS_CONST, OS_CONST)
  OsCfg_Hal_Core_OsCore3_InterruptSourceRefs[OS_CFG_NUM_CORE_OSCORE3_INTERRUPTSOURCEREFS + 1u] =
{
  /* No core exclusive interrupt sources to be initialized by OsCore3. */
  NULL_PTR
};


/*! HAL core configuration data: OsCore3 */
CONST(Os_Hal_CoreConfigType, OS_CONST) OsCfg_Hal_Core_OsCore3 =
{
  /* .CoreId                  = */ 3, /* Physical id of OsCore3 */
  /* .ProgramCounterRegister  = */ OS_HAL_CORE3_PC,
  /* .StartLabelAddress       = */ (uint32)&(_start_tc3), /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */
  /* .DBGSRRegister           = */ OS_HAL_CORE3_DBGSR,
  /* .SYSCONRegister          = */ OS_HAL_CORE3_SYSCON
}
;

/*! HAL AUTOSAR core configuration data: OsCore3 */
CONST(Os_Hal_CoreAsrConfigType, OS_CONST) OsCfg_Hal_CoreAsr_OsCore3 =
{
  /* .CoreId        = */ 3, /* This is the logical id of the core */
};

#define OS_STOP_SEC_CORE3_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE4_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL core initialized interrupt sources: OsCore4 */
CONSTP2CONST(Os_Hal_IntIsrConfigType, OS_CONST, OS_CONST)
  OsCfg_Hal_Core_OsCore4_InterruptSourceRefs[OS_CFG_NUM_CORE_OSCORE4_INTERRUPTSOURCEREFS + 1u] =
{
  /* No core exclusive interrupt sources to be initialized by OsCore4. */
  NULL_PTR
};


/*! HAL core configuration data: OsCore4 */
CONST(Os_Hal_CoreConfigType, OS_CONST) OsCfg_Hal_Core_OsCore4 =
{
  /* .CoreId                  = */ 4, /* Physical id of OsCore4 */
  /* .ProgramCounterRegister  = */ OS_HAL_CORE4_PC,
  /* .StartLabelAddress       = */ (uint32)&(_start_tc4), /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */
  /* .DBGSRRegister           = */ OS_HAL_CORE4_DBGSR,
  /* .SYSCONRegister          = */ OS_HAL_CORE4_SYSCON
}
;

/*! HAL AUTOSAR core configuration data: OsCore4 */
CONST(Os_Hal_CoreAsrConfigType, OS_CONST) OsCfg_Hal_CoreAsr_OsCore4 =
{
  /* .CoreId        = */ 4, /* This is the logical id of the core */
};

#define OS_STOP_SEC_CORE4_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE5_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL core initialized interrupt sources: OsCore5 */
CONSTP2CONST(Os_Hal_IntIsrConfigType, OS_CONST, OS_CONST)
  OsCfg_Hal_Core_OsCore5_InterruptSourceRefs[OS_CFG_NUM_CORE_OSCORE5_INTERRUPTSOURCEREFS + 1u] =
{
  /* No core exclusive interrupt sources to be initialized by OsCore5. */
  NULL_PTR
};


/*! HAL core configuration data: OsCore5 */
CONST(Os_Hal_CoreConfigType, OS_CONST) OsCfg_Hal_Core_OsCore5 =
{
  /* .CoreId                  = */ 6, /* Physical id of OsCore5 */
  /* .ProgramCounterRegister  = */ OS_HAL_CORE6_PC,
  /* .StartLabelAddress       = */ (uint32)&(_start_tc5), /* PRQA S 0306, 0324 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.2_0324 */
  /* .DBGSRRegister           = */ OS_HAL_CORE6_DBGSR,
  /* .SYSCONRegister          = */ OS_HAL_CORE6_SYSCON
}
;

/*! HAL AUTOSAR core configuration data: OsCore5 */
CONST(Os_Hal_CoreAsrConfigType, OS_CONST) OsCfg_Hal_CoreAsr_OsCore5 =
{
  /* .CoreId        = */ 5, /* This is the logical id of the core */
};

#define OS_STOP_SEC_CORE5_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL core to thread configuration data. */
CONST(Os_Hal_Core2ThreadConfigType, OS_CONST) OsCfg_Hal_Core2Thread =
{
  /* .Core2Thread = */
  {
    &OsCfg_Hal_Core2Thread_OsCore0_Dyn, /* OS_CORE_ID_0 */
    &OsCfg_Hal_Core2Thread_OsCore1_Dyn, /* OS_CORE_ID_1 */
    &OsCfg_Hal_Core2Thread_OsCore2_Dyn, /* OS_CORE_ID_2 */
    &OsCfg_Hal_Core2Thread_OsCore3_Dyn, /* OS_CORE_ID_3 */
    &OsCfg_Hal_Core2Thread_OsCore4_Dyn, /* OS_CORE_ID_4 */
    NULL_PTR,
    &OsCfg_Hal_Core2Thread_OsCore5_Dyn, /* OS_CORE_ID_5 */
  }
};

/*! HAL system configuration data. */
CONST(Os_Hal_SystemConfigType, OS_CONST) OsCfg_Hal_System =
0;

/*! Interrupt sources which are initialized by the hardware init core. */
CONSTP2CONST(Os_Hal_IntIsrConfigType, OS_CONST, OS_CONST)
  OsCfg_Hal_System_InterruptSourceRefs[OS_CFG_NUM_SYSTEM_INTERRUPTSOURCEREFS + 1u] =
{
  &OsCfg_Hal_IntIsr_ADC0SR0_ISR,
  &OsCfg_Hal_IntIsr_ADC1SR0_ISR,
  &OsCfg_Hal_IntIsr_ADC2SR0_ISR,
  &OsCfg_Hal_IntIsr_ADC3SR0_ISR,
  &OsCfg_Hal_IntIsr_ADC8SR0_ISR,
  &OsCfg_Hal_IntIsr_CanIsr_0,
  &OsCfg_Hal_IntIsr_CanIsr_1,
  &OsCfg_Hal_IntIsr_CanIsr_2,
  &OsCfg_Hal_IntIsr_CanIsr_3,
  &OsCfg_Hal_IntIsr_CanIsr_4,
  &OsCfg_Hal_IntIsr_CanIsr_5,
  &OsCfg_Hal_IntIsr_CounterIsr_SystemTimer0,
  &OsCfg_Hal_IntIsr_CounterIsr_SystemTimer1,
  &OsCfg_Hal_IntIsr_CounterIsr_SystemTimer2,
  &OsCfg_Hal_IntIsr_CounterIsr_SystemTimer3,
  &OsCfg_Hal_IntIsr_CounterIsr_SystemTimer4,
  &OsCfg_Hal_IntIsr_CounterIsr_SystemTimer5,
  &OsCfg_Hal_IntIsr_DMACH0SR_ISR,
  &OsCfg_Hal_IntIsr_DMACH3SR_ISR,
  &OsCfg_Hal_IntIsr_DMACH4SR_ISR,
  &OsCfg_Hal_IntIsr_DMACH5SR_ISR,
  &OsCfg_Hal_IntIsr_DMACH6SR_ISR,
  &OsCfg_Hal_IntIsr_DMACH7SR_ISR,
  &OsCfg_Hal_IntIsr_DMACH8SR_ISR,
  &OsCfg_Hal_IntIsr_DMACH9SR_ISR,
  &OsCfg_Hal_IntIsr_DMAERR0SR_ISR,
  &OsCfg_Hal_IntIsr_GTMATOM0SR0_ISR,
  &OsCfg_Hal_IntIsr_GTMATOM1SR0_ISR,
  &OsCfg_Hal_IntIsr_GTMATOM2SR0_ISR,
  &OsCfg_Hal_IntIsr_GTMATOM4SR0_ISR,
  &OsCfg_Hal_IntIsr_GTMTIM2SR3_ISR,
  &OsCfg_Hal_IntIsr_GTMTIM2SR5_ISR,
  &OsCfg_Hal_IntIsr_GTMTOM0SR0_ISR,
  &OsCfg_Hal_IntIsr_GTMTOM0SR1_ISR,
  &OsCfg_Hal_IntIsr_GTMTOM0SR2_ISR,
  &OsCfg_Hal_IntIsr_GTMTOM0SR3_ISR,
  &OsCfg_Hal_IntIsr_QSPI0ERR_ISR,
  &OsCfg_Hal_IntIsr_QSPI0PT_ISR,
  &OsCfg_Hal_IntIsr_QSPI1ERR_ISR,
  &OsCfg_Hal_IntIsr_QSPI1PT_ISR,
  &OsCfg_Hal_IntIsr_QSPI2ERR_ISR,
  &OsCfg_Hal_IntIsr_QSPI2PT_ISR,
  &OsCfg_Hal_IntIsr_QSPI3ERR_ISR,
  &OsCfg_Hal_IntIsr_QSPI3PT_ISR,
  &OsCfg_Hal_IntIsr_XSignalIsr_OsCore0,
  &OsCfg_Hal_IntIsr_XSignalIsr_OsCore1,
  &OsCfg_Hal_IntIsr_XSignalIsr_OsCore2,
  &OsCfg_Hal_IntIsr_XSignalIsr_OsCore3,
  &OsCfg_Hal_IntIsr_XSignalIsr_OsCore4,
  &OsCfg_Hal_IntIsr_XSignalIsr_OsCore5,
  NULL_PTR
};


#define OS_STOP_SEC_CONST_UNSPECIFIED
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
 *  END OF FILE: Os_Hal_Core_Lcfg.c
 *********************************************************************************************************************/

