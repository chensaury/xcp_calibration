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
 *   Generation Time: 2024-01-08 16:27:33
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
#define Core_OsTask_CDD Core_OsTask_CDD
#define Core_OsTask_IOHW Core_OsTask_IOHW
#define Core_OsTask_PSI5 Core_OsTask_PSI5
#define Core_OsTask_PT2000 Core_OsTask_PT2000
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
#define ADC0SR0_ISR ADC0SR0_ISR
#define ADC1SR0_ISR ADC1SR0_ISR
#define ADC2SR0_ISR ADC2SR0_ISR
#define ADC3SR0_ISR ADC3SR0_ISR
#define ADC8SR0_ISR ADC8SR0_ISR
#define CanIsr_0 CanIsr_0
#define CanIsr_1 CanIsr_1
#define CanIsr_2 CanIsr_2
#define CanIsr_3 CanIsr_3
#define CanIsr_4 CanIsr_4
#define CanIsr_5 CanIsr_5
#define CounterIsr_SystemTimer0 CounterIsr_SystemTimer0
#define CounterIsr_SystemTimer1 CounterIsr_SystemTimer1
#define CounterIsr_SystemTimer2 CounterIsr_SystemTimer2
#define CounterIsr_SystemTimer3 CounterIsr_SystemTimer3
#define CounterIsr_SystemTimer4 CounterIsr_SystemTimer4
#define CounterIsr_SystemTimer5 CounterIsr_SystemTimer5
#define DMACH0SR_ISR DMACH0SR_ISR
#define DMACH3SR_ISR DMACH3SR_ISR
#define DMACH4SR_ISR DMACH4SR_ISR
#define DMACH5SR_ISR DMACH5SR_ISR
#define DMACH6SR_ISR DMACH6SR_ISR
#define DMACH7SR_ISR DMACH7SR_ISR
#define DMACH8SR_ISR DMACH8SR_ISR
#define DMACH9SR_ISR DMACH9SR_ISR
#define DMAERR0SR_ISR DMAERR0SR_ISR
#define GTMATOM0SR0_ISR GTMATOM0SR0_ISR
#define GTMATOM1SR0_ISR GTMATOM1SR0_ISR
#define GTMATOM2SR0_ISR GTMATOM2SR0_ISR
#define GTMATOM4SR0_ISR GTMATOM4SR0_ISR
#define GTMTIM2SR3_ISR GTMTIM2SR3_ISR
#define GTMTIM2SR5_ISR GTMTIM2SR5_ISR
#define GTMTOM0SR0_ISR GTMTOM0SR0_ISR
#define GTMTOM0SR1_ISR GTMTOM0SR1_ISR
#define GTMTOM0SR2_ISR GTMTOM0SR2_ISR
#define GTMTOM0SR3_ISR GTMTOM0SR3_ISR
#define QSPI0ERR_ISR QSPI0ERR_ISR
#define QSPI0PT_ISR QSPI0PT_ISR
#define QSPI1ERR_ISR QSPI1ERR_ISR
#define QSPI1PT_ISR QSPI1PT_ISR
#define QSPI2ERR_ISR QSPI2ERR_ISR
#define QSPI2PT_ISR QSPI2PT_ISR
#define QSPI3ERR_ISR QSPI3ERR_ISR
#define QSPI3PT_ISR QSPI3PT_ISR
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
#define Rte_Al_TE_Core5swc_Runnable Rte_Al_TE_Core5swc_Runnable
#define Rte_Al_TE_CtCDD_CtCDD Rte_Al_TE_CtCDD_CtCDD
#define Rte_Al_TE_CtIoHardWare_Adc_Write Rte_Al_TE_CtIoHardWare_Adc_Write
#define Rte_Al_TE_CtMDA_Control_Logic_MDA_Control_Logic Rte_Al_TE_CtMDA_Control_Logic_MDA_Control_Logic
#define Rte_Al_TE_CtMotor_FL_CpApMotor_FL Rte_Al_TE_CtMotor_FL_CpApMotor_FL
#define Rte_Al_TE_CtMotor_FR_CpApMotor_FR Rte_Al_TE_CtMotor_FR_CpApMotor_FR
#define Rte_Al_TE_CtMotor_RL_CpApMotor_RL Rte_Al_TE_CtMotor_RL_CpApMotor_RL
#define Rte_Al_TE_CtMotor_RR_CpApMotor_RR Rte_Al_TE_CtMotor_RR_CpApMotor_RR
#define Rte_Al_TE_CtPSI5_Handler_PSI5MAIN_HD Rte_Al_TE_CtPSI5_Handler_PSI5MAIN_HD
#define Rte_Al_TE_CtPT2000_Handler_PT2000_Diag_HD Rte_Al_TE_CtPT2000_Handler_PT2000_Diag_HD
#define Rte_Al_TE_CtPT2000_Handler_PT2000_Main_HD Rte_Al_TE_CtPT2000_Handler_PT2000_Main_HD
#define Rte_Al_TE_CtPWM_Handler_PWM_SET Rte_Al_TE_CtPWM_Handler_PWM_SET

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
#define Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutFL_MotTgtOutFL Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutFL_MotTgtOutFL
#define Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutFR_MotTgtOutFR Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutFR_MotTgtOutFR
#define Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutRL_MotTgtOutRL Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutRL_MotTgtOutRL
#define Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutRR_MotTgtOutRR Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutRR_MotTgtOutRR
#define Rte_Spinlock_CtMotor_FL_PpMotFLAct_MotFLAct Rte_Spinlock_CtMotor_FL_PpMotFLAct_MotFLAct
#define Rte_Spinlock_CtMotor_FR_PpMotFRAct_MotFRAct Rte_Spinlock_CtMotor_FR_PpMotFRAct_MotFRAct
#define Rte_Spinlock_CtMotor_RL_PpMotRLAct_MotRLAct Rte_Spinlock_CtMotor_RL_PpMotRLAct_MotRLAct
#define Rte_Spinlock_CtMotor_RR_PpMotRRAct_MotRRAct Rte_Spinlock_CtMotor_RR_PpMotRRAct_MotRRAct

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
  Core_OsTask_CDD = 6,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Core_OsTask_IOHW = 7,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Core_OsTask_PSI5 = 8,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Core_OsTask_PT2000 = 9,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  IdleTask_OsCore0 = 10,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  IdleTask_OsCore1 = 11,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  IdleTask_OsCore2 = 12,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  IdleTask_OsCore3 = 13,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  IdleTask_OsCore4 = 14,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  IdleTask_OsCore5 = 15,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Init_Core0 = 16,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Init_Core1 = 17,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Init_Core2 = 18,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Init_Core3 = 19,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Init_Core4 = 20,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Init_Core5 = 21,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SchM_Core0 = 22,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SchM_Core1 = 23,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SchM_Core2 = 24,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SchM_Core3 = 25,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SchM_Core4 = 26,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SchM_Core5 = 27,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_TASKID_COUNT = 28,
  INVALID_TASK = OS_TASKID_COUNT
} TaskType;

/*! Category 2 ISR identifiers. */
typedef enum
{
  ADC0SR0_ISR = 0,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  ADC1SR0_ISR = 1,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  ADC2SR0_ISR = 2,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  ADC3SR0_ISR = 3,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  ADC8SR0_ISR = 4,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CanIsr_0 = 5,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CanIsr_1 = 6,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CanIsr_2 = 7,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CanIsr_3 = 8,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CanIsr_4 = 9,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CanIsr_5 = 10,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CounterIsr_SystemTimer0 = 11,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CounterIsr_SystemTimer1 = 12,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CounterIsr_SystemTimer2 = 13,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CounterIsr_SystemTimer3 = 14,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CounterIsr_SystemTimer4 = 15,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CounterIsr_SystemTimer5 = 16,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  DMACH0SR_ISR = 17,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  DMACH3SR_ISR = 18,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  DMACH4SR_ISR = 19,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  DMACH5SR_ISR = 20,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  DMACH6SR_ISR = 21,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  DMACH7SR_ISR = 22,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  DMACH8SR_ISR = 23,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  DMACH9SR_ISR = 24,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  DMAERR0SR_ISR = 25,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  GTMATOM0SR0_ISR = 26,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  GTMATOM1SR0_ISR = 27,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  GTMATOM2SR0_ISR = 28,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  GTMATOM4SR0_ISR = 29,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  GTMTIM2SR3_ISR = 30,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  GTMTIM2SR5_ISR = 31,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  GTMTOM0SR0_ISR = 32,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  GTMTOM0SR1_ISR = 33,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  GTMTOM0SR2_ISR = 34,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  GTMTOM0SR3_ISR = 35,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  QSPI0ERR_ISR = 36,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  QSPI0PT_ISR = 37,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  QSPI1ERR_ISR = 38,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  QSPI1PT_ISR = 39,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  QSPI2ERR_ISR = 40,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  QSPI2PT_ISR = 41,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  QSPI3ERR_ISR = 42,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  QSPI3PT_ISR = 43,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  XSignalIsr_OsCore0 = 44,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  XSignalIsr_OsCore1 = 45,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  XSignalIsr_OsCore2 = 46,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  XSignalIsr_OsCore3 = 47,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  XSignalIsr_OsCore4 = 48,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  XSignalIsr_OsCore5 = 49,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_ISRID_COUNT = 50,
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
  Rte_Al_TE_Core5swc_Runnable = 9,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_CtCDD_CtCDD = 10,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_CtIoHardWare_Adc_Write = 11,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_CtMDA_Control_Logic_MDA_Control_Logic = 12,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_CtMotor_FL_CpApMotor_FL = 13,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_CtMotor_FR_CpApMotor_FR = 14,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_CtMotor_RL_CpApMotor_RL = 15,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_CtMotor_RR_CpApMotor_RR = 16,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_CtPSI5_Handler_PSI5MAIN_HD = 17,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_CtPT2000_Handler_PT2000_Diag_HD = 18,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_CtPT2000_Handler_PT2000_Main_HD = 19,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_CtPWM_Handler_PWM_SET = 20,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_ALARMID_COUNT = 21
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
  Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutFL_MotTgtOutFL = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutFR_MotTgtOutFR = 1,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutRL_MotTgtOutRL = 2,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutRR_MotTgtOutRR = 3,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Spinlock_CtMotor_FL_PpMotFLAct_MotFLAct = 4,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Spinlock_CtMotor_FR_PpMotFRAct_MotFRAct = 5,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Spinlock_CtMotor_RL_PpMotRLAct_MotRLAct = 6,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Spinlock_CtMotor_RR_PpMotRRAct_MotRRAct = 7,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_SPINLOCKID_COUNT = 8,
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
