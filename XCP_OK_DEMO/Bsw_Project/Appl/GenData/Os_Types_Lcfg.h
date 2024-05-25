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
 *              File: Os_Types_Lcfg.h
 *   Generation Time: 2023-05-24 20:20:17
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

#ifndef OS_TYPES_LCFG_H
# define OS_TYPES_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */

/* Os kernel module dependencies */

/* Os hal dependencies */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* OS-Application identifiers. */
#define SystemApplication_OsCore0 SystemApplication_OsCore0
#define SystemApplication_OsCore1 SystemApplication_OsCore1
#define SystemApplication_OsCore2 SystemApplication_OsCore2
#define SystemApplication_OsCore3 SystemApplication_OsCore3
#define SystemApplication_OsCore4 SystemApplication_OsCore4
#define SystemApplication_OsCore5 SystemApplication_OsCore5

/* Trusted function identifiers. */

/* Non-trusted function identifiers. */

/* Fast trusted function identifiers. */

/* Task identifiers. */
#define APP_Task_Core0 APP_Task_Core0
#define APP_Task_Core1 APP_Task_Core1
#define APP_Task_Core2 APP_Task_Core2
#define APP_Task_Core3 APP_Task_Core3
#define APP_Task_Core4 APP_Task_Core4
#define APP_Task_Core5 APP_Task_Core5
#define IdleTask_OsCore0 IdleTask_OsCore0
#define IdleTask_OsCore1 IdleTask_OsCore1
#define IdleTask_OsCore2 IdleTask_OsCore2
#define IdleTask_OsCore3 IdleTask_OsCore3
#define IdleTask_OsCore4 IdleTask_OsCore4
#define IdleTask_OsCore5 IdleTask_OsCore5
#define Init_Core0 Init_Core0
#define Init_Core1 Init_Core1
#define Init_Core2 Init_Core2
#define Init_Core3 Init_Core3
#define Init_Core4 Init_Core4
#define Init_Core5 Init_Core5
#define SchM_Core0 SchM_Core0
#define SchM_Core1 SchM_Core1
#define SchM_Core2 SchM_Core2
#define SchM_Core3 SchM_Core3
#define SchM_Core4 SchM_Core4
#define SchM_Core5 SchM_Core5

/* Category 2 ISR identifiers. */
#define CanIsr_0 CanIsr_0
#define CounterIsr_SystemTimer0 CounterIsr_SystemTimer0
#define CounterIsr_SystemTimer1 CounterIsr_SystemTimer1
#define CounterIsr_SystemTimer2 CounterIsr_SystemTimer2
#define CounterIsr_SystemTimer3 CounterIsr_SystemTimer3
#define CounterIsr_SystemTimer4 CounterIsr_SystemTimer4
#define CounterIsr_SystemTimer5 CounterIsr_SystemTimer5
#define XSignalIsr_OsCore0 XSignalIsr_OsCore0
#define XSignalIsr_OsCore1 XSignalIsr_OsCore1
#define XSignalIsr_OsCore2 XSignalIsr_OsCore2
#define XSignalIsr_OsCore3 XSignalIsr_OsCore3
#define XSignalIsr_OsCore4 XSignalIsr_OsCore4
#define XSignalIsr_OsCore5 XSignalIsr_OsCore5

/* Alarm identifiers. */
#define Rte_Al_TE1_EcuM_EcuM_MainFunction Rte_Al_TE1_EcuM_EcuM_MainFunction
#define Rte_Al_TE2_EcuM_EcuM_MainFunction Rte_Al_TE2_EcuM_EcuM_MainFunction
#define Rte_Al_TE2_SchM_Core0_0_10ms Rte_Al_TE2_SchM_Core0_0_10ms
#define Rte_Al_TE2_SchM_Core0_0_1ms Rte_Al_TE2_SchM_Core0_0_1ms
#define Rte_Al_TE2_SchM_Core0_0_20ms Rte_Al_TE2_SchM_Core0_0_20ms
#define Rte_Al_TE2_SchM_Core0_0_5ms Rte_Al_TE2_SchM_Core0_0_5ms
#define Rte_Al_TE3_EcuM_EcuM_MainFunction Rte_Al_TE3_EcuM_EcuM_MainFunction
#define Rte_Al_TE4_EcuM_EcuM_MainFunction Rte_Al_TE4_EcuM_EcuM_MainFunction
#define Rte_Al_TE6_EcuM_EcuM_MainFunction Rte_Al_TE6_EcuM_EcuM_MainFunction
#define Rte_Al_TE_Core0Swc_Core0Runnable Rte_Al_TE_Core0Swc_Core0Runnable
#define Rte_Al_TE_Core1Swc_Core1Runnable Rte_Al_TE_Core1Swc_Core1Runnable
#define Rte_Al_TE_Core2Swc_Core2Runnable Rte_Al_TE_Core2Swc_Core2Runnable
#define Rte_Al_TE_Core3Swc_Core3Runnable Rte_Al_TE_Core3Swc_Core3Runnable
#define Rte_Al_TE_Core4Swc_Core4Runnable Rte_Al_TE_Core4Swc_Core4Runnable
#define Rte_Al_TE_Core5Swc_Core5Runnable Rte_Al_TE_Core5Swc_Core5Runnable

/* Counter identifiers. */
#define SystemTimer0 SystemTimer0
#define SystemTimer1 SystemTimer1
#define SystemTimer2 SystemTimer2
#define SystemTimer3 SystemTimer3
#define SystemTimer4 SystemTimer4
#define SystemTimer5 SystemTimer5

/* ScheduleTable identifiers. */

/* Resource identifiers. */
#define RES_SCHEDULER_OsCore0 RES_SCHEDULER_OsCore0
#define RES_SCHEDULER_OsCore1 RES_SCHEDULER_OsCore1
#define RES_SCHEDULER_OsCore2 RES_SCHEDULER_OsCore2
#define RES_SCHEDULER_OsCore3 RES_SCHEDULER_OsCore3
#define RES_SCHEDULER_OsCore4 RES_SCHEDULER_OsCore4
#define RES_SCHEDULER_OsCore5 RES_SCHEDULER_OsCore5

/* Spinlock identifiers. */

/* Peripheral identifiers. */

/* Barrier identifiers. */

/* Trace thread identifiers (Tasks and ISRs inclusive system objects). */

/* Trace spinlock identifiers (All spinlocks inclusive system objects). */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*! OS-Application identifiers. */
typedef enum
{
  SystemApplication_OsCore0 = 0, /* 0x00000001 */  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SystemApplication_OsCore1 = 1, /* 0x00000002 */  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SystemApplication_OsCore2 = 2, /* 0x00000004 */  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SystemApplication_OsCore3 = 3, /* 0x00000008 */  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SystemApplication_OsCore4 = 4, /* 0x00000010 */  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SystemApplication_OsCore5 = 5, /* 0x00000020 */  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_APPID_COUNT = 6,
  INVALID_OSAPPLICATION = OS_APPID_COUNT
} ApplicationType;

/*! Trusted function identifiers. */
typedef enum
{
  OS_TRUSTEDFUNCTIONID_COUNT = 0
} TrustedFunctionIndexType;

/*! Non-trusted function identifiers. */
typedef enum
{
  OS_NONTRUSTEDFUNCTIONID_COUNT = 0
} Os_NonTrustedFunctionIndexType;

/*! Fast trusted function identifiers. */
typedef enum
{
  OS_FASTTRUSTEDFUNCTIONID_COUNT = 0
} Os_FastTrustedFunctionIndexType;

/*! Task identifiers. */
typedef enum
{
  APP_Task_Core0 = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  APP_Task_Core1 = 1,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  APP_Task_Core2 = 2,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  APP_Task_Core3 = 3,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  APP_Task_Core4 = 4,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  APP_Task_Core5 = 5,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  IdleTask_OsCore0 = 6,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  IdleTask_OsCore1 = 7,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  IdleTask_OsCore2 = 8,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  IdleTask_OsCore3 = 9,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  IdleTask_OsCore4 = 10,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  IdleTask_OsCore5 = 11,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Init_Core0 = 12,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Init_Core1 = 13,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Init_Core2 = 14,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Init_Core3 = 15,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Init_Core4 = 16,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Init_Core5 = 17,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SchM_Core0 = 18,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SchM_Core1 = 19,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SchM_Core2 = 20,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SchM_Core3 = 21,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SchM_Core4 = 22,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SchM_Core5 = 23,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_TASKID_COUNT = 24,
  INVALID_TASK = OS_TASKID_COUNT
} TaskType;

/*! Category 2 ISR identifiers. */
typedef enum
{
  CanIsr_0 = 0,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CounterIsr_SystemTimer0 = 1,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CounterIsr_SystemTimer1 = 2,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CounterIsr_SystemTimer2 = 3,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CounterIsr_SystemTimer3 = 4,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CounterIsr_SystemTimer4 = 5,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CounterIsr_SystemTimer5 = 6,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  XSignalIsr_OsCore0 = 7,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  XSignalIsr_OsCore1 = 8,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  XSignalIsr_OsCore2 = 9,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  XSignalIsr_OsCore3 = 10,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  XSignalIsr_OsCore4 = 11,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  XSignalIsr_OsCore5 = 12,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_ISRID_COUNT = 13,
  INVALID_ISR = OS_ISRID_COUNT
} ISRType;

/*! Alarm identifiers. */
typedef enum
{
  Rte_Al_TE1_EcuM_EcuM_MainFunction = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE2_EcuM_EcuM_MainFunction = 1,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE2_SchM_Core0_0_10ms = 2,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE2_SchM_Core0_0_1ms = 3,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE2_SchM_Core0_0_20ms = 4,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE2_SchM_Core0_0_5ms = 5,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE3_EcuM_EcuM_MainFunction = 6,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE4_EcuM_EcuM_MainFunction = 7,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE6_EcuM_EcuM_MainFunction = 8,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Core0Swc_Core0Runnable = 9,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Core1Swc_Core1Runnable = 10,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Core2Swc_Core2Runnable = 11,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Core3Swc_Core3Runnable = 12,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Core4Swc_Core4Runnable = 13,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Core5Swc_Core5Runnable = 14,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_ALARMID_COUNT = 15
} AlarmType;

/*! Counter identifiers. */
typedef enum
{
  SystemTimer0 = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SystemTimer1 = 1,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SystemTimer2 = 2,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SystemTimer3 = 3,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SystemTimer4 = 4,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SystemTimer5 = 5,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_COUNTERID_COUNT = 6
} CounterType;

/*! ScheduleTable identifiers. */
typedef enum
{
  OS_SCHTID_COUNT = 0
} ScheduleTableType;

/*! Resource identifiers. */
typedef enum
{
  RES_SCHEDULER_OsCore0 = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  RES_SCHEDULER_OsCore1 = 1,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  RES_SCHEDULER_OsCore2 = 2,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  RES_SCHEDULER_OsCore3 = 3,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  RES_SCHEDULER_OsCore4 = 4,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  RES_SCHEDULER_OsCore5 = 5,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_RESOURCEID_COUNT = 6
} ResourceType;

/*! Spinlock identifiers. */
typedef enum
{
  OS_SPINLOCKID_COUNT = 0,
  INVALID_SPINLOCK = OS_SPINLOCKID_COUNT
} SpinlockIdType;

/*! Peripheral identifiers. */
typedef enum
{
  OS_PERIPHERALID_COUNT = 0
} Os_PeripheralIdType;

/*! Barrier identifiers. */
typedef enum
{
  OS_BARRIERID_COUNT = 0
} Os_BarrierIdType;

/*! Trace thread identifiers (Tasks and ISRs inclusive system objects). */
typedef enum
{
  OS_TRACE_THREADID_COUNT = 0,
  OS_TRACE_INVALID_THREAD = OS_TRACE_THREADID_COUNT + 1
} Os_TraceThreadIdType;

/*! Trace spinlock identifiers (All spinlocks inclusive system objects). */
typedef enum
{
  OS_TRACE_NUMBER_OF_CONFIGURED_SPINLOCKS = OS_SPINLOCKID_COUNT,
  OS_TRACE_NUMBER_OF_ALL_SPINLOCKS = OS_SPINLOCKID_COUNT + 0u,  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
  OS_TRACE_INVALID_SPINLOCK = OS_TRACE_NUMBER_OF_ALL_SPINLOCKS + 1
} Os_TraceSpinlockIdType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_TYPES_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Types_Lcfg.h
 *********************************************************************************************************************/
