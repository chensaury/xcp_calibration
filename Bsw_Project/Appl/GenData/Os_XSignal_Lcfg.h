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
 *              File: Os_XSignal_Lcfg.h
 *   Generation Time: 2023-04-13 21:53:52
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

#ifndef OS_XSIGNAL_LCFG_H
# define OS_XSIGNAL_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_XSignal_Types.h"

/* Os kernel module dependencies */
# include "Os_Error_Types.h"
# include "OsInt.h"

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

/*! Cross-core function identifiers. */
typedef enum
{
  /* USED */
  XSigFunctionIdx_ActivateTask = 0,
  XSigFunctionIdx_CancelAlarm = 1,
  XSigFunctionIdx_ControlIdle = 2,
  XSigFunctionIdx_GetAlarm = 3,
  XSigFunctionIdx_GetApplicationState = 4,
  XSigFunctionIdx_GetCounterValue = 5,
  XSigFunctionIdx_GetErrorHookStackUsage = 6,
  XSigFunctionIdx_GetEvent = 7,
  XSigFunctionIdx_GetISRStackUsage = 8,
  XSigFunctionIdx_GetKernelStackUsage = 9,
  XSigFunctionIdx_GetProtectionHookStackUsage = 10,
  XSigFunctionIdx_GetScheduleTableStatus = 11,
  XSigFunctionIdx_GetShutdownHookStackUsage = 12,
  XSigFunctionIdx_GetStartupHookStackUsage = 13,
  XSigFunctionIdx_GetTaskStackUsage = 14,
  XSigFunctionIdx_GetTaskState = 15,
  XSigFunctionIdx_HookCallCallback = 16,
  XSigFunctionIdx_NextScheduleTable = 17,
  XSigFunctionIdx_SetAbsAlarm = 18,
  XSigFunctionIdx_SetEvent = 19,
  XSigFunctionIdx_SetRelAlarm = 20,
  XSigFunctionIdx_ShutdownAllCores = 21,
  XSigFunctionIdx_StartScheduleTableAbs = 22,
  XSigFunctionIdx_StartScheduleTableRel = 23,
  XSigFunctionIdx_StopScheduleTable = 24,
  XSigFunctionIdx_TerminateApplication = 25,
  OS_XSIGFUNCTIONIDX_USEDCOUNT = 26,
  /* UNUSED */
  OS_XSIGFUNCTIONIDX_COUNT = 26
} Os_XSigFunctionIdx;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* X-Signal configuration data: OsCore0 */
extern CONST(Os_XSigFunctionTableConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore0_FuncTable;
extern CONST(Os_XSigRecvPortConfigRefType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore0_PortRefs[OS_CFG_NUM_ISR_XSIGNALISR_OSCORE0_PORTS + 1u];
extern CONST(Os_XSigConfigType, OS_CONST) OsCfg_XSig_OsCore0;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE1_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* X-Signal configuration data: OsCore1 */
extern CONST(Os_XSigFunctionTableConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore1_FuncTable;
extern CONST(Os_XSigRecvPortConfigRefType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore1_PortRefs[OS_CFG_NUM_ISR_XSIGNALISR_OSCORE1_PORTS + 1u];
extern CONST(Os_XSigConfigType, OS_CONST) OsCfg_XSig_OsCore1;

# define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE2_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* X-Signal configuration data: OsCore2 */
extern CONST(Os_XSigFunctionTableConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore2_FuncTable;
extern CONST(Os_XSigRecvPortConfigRefType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore2_PortRefs[OS_CFG_NUM_ISR_XSIGNALISR_OSCORE2_PORTS + 1u];
extern CONST(Os_XSigConfigType, OS_CONST) OsCfg_XSig_OsCore2;

# define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE3_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* X-Signal configuration data: OsCore3 */
extern CONST(Os_XSigFunctionTableConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore3_FuncTable;
extern CONST(Os_XSigRecvPortConfigRefType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore3_PortRefs[OS_CFG_NUM_ISR_XSIGNALISR_OSCORE3_PORTS + 1u];
extern CONST(Os_XSigConfigType, OS_CONST) OsCfg_XSig_OsCore3;

# define OS_STOP_SEC_CORE3_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE4_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* X-Signal configuration data: OsCore4 */
extern CONST(Os_XSigFunctionTableConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore4_FuncTable;
extern CONST(Os_XSigRecvPortConfigRefType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore4_PortRefs[OS_CFG_NUM_ISR_XSIGNALISR_OSCORE4_PORTS + 1u];
extern CONST(Os_XSigConfigType, OS_CONST) OsCfg_XSig_OsCore4;

# define OS_STOP_SEC_CORE4_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE5_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* X-Signal configuration data: OsCore5 */
extern CONST(Os_XSigFunctionTableConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore5_FuncTable;
extern CONST(Os_XSigRecvPortConfigRefType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore5_PortRefs[OS_CFG_NUM_ISR_XSIGNALISR_OSCORE5_PORTS + 1u];
extern CONST(Os_XSigConfigType, OS_CONST) OsCfg_XSig_OsCore5;

# define OS_STOP_SEC_CORE5_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! X-Signal used services map. */
extern CONST(OSServiceIdType, OS_CONST) OsCfg_XSig_ServiceMap[OS_XSIGFUNCTIONIDX_USEDCOUNT + 1u];                       /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_XSIGNAL_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_XSignal_Lcfg.h
 *********************************************************************************************************************/
