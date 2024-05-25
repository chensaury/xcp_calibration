/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_SystemApplication_OsCore4.c
 *        Config:  Bsw_Project.dpa
 *   ECU-Project:  MDA
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  RTE implementation file
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0781, 0857 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779, MD_Rte_0781, MD_MSR_1.1_857 */

#define RTE_CORE
#include "Os.h" /* PRQA S 0828, 0883 */ /* MD_MSR_1.1_828, MD_Rte_Os */
#include "Rte_Type.h"
#include "Rte_Main.h"

#include "Rte_BswM.h"
#include "Rte_ComM.h"
#include "Rte_Core5swc.h"
#include "Rte_CtCDD.h"
#include "Rte_CtIoHardWare.h"
#include "Rte_CtMDA_Control_Logic.h"
#include "Rte_CtMotor_FL.h"
#include "Rte_CtMotor_FR.h"
#include "Rte_CtMotor_RL.h"
#include "Rte_CtMotor_RR.h"
#include "Rte_CtPSI5_Handler.h"
#include "Rte_CtPT2000_Handler.h"
#include "Rte_CtPWM_Handler.h"
#include "Rte_Det.h"
#include "Rte_EcuM.h"
#include "Rte_Os_OsCore0_swc.h"
#include "Rte_Os_OsCore1_swc.h"
#include "Rte_Os_OsCore2_swc.h"
#include "Rte_Os_OsCore3_swc.h"
#include "Rte_Os_OsCore4_swc.h"
#include "Rte_Os_OsCore5_swc.h"
#include "SchM_Adc.h"
#include "SchM_BswM.h"
#include "SchM_Can.h"
#include "SchM_CanIf.h"
#include "SchM_CanSM.h"
#include "SchM_Com.h"
#include "SchM_ComM.h"
#include "SchM_Det.h"
#include "SchM_Dio.h"
#include "SchM_Dma.h"
#include "SchM_EcuM.h"
#include "SchM_Gpt.h"
#include "SchM_Icu_17_TimerIp.h"
#include "SchM_Irq.h"
#include "SchM_McalLib.h"
#include "SchM_Mcu.h"
#include "SchM_PduR.h"
#include "SchM_Port.h"
#include "SchM_Pwm_17_GtmCcu6.h"
#include "SchM_Spi.h"
#include "SchM_Xcp.h"

#include "Rte_Hook.h"

#include "Rte_Cbk.h"

/* AUTOSAR 3.x compatibility */
#if !defined (RTE_LOCAL)
# define RTE_LOCAL static
#endif


/**********************************************************************************************************************
 * API for enable / disable interrupts global
 *********************************************************************************************************************/

#if defined(osDisableGlobalKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableAllInterrupts() osDisableGlobalKM()   /* MICROSAR OS */
#else
# define Rte_DisableAllInterrupts() DisableAllInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableGlobalKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableAllInterrupts() osEnableGlobalKM()   /* MICROSAR OS */
#else
# define Rte_EnableAllInterrupts() EnableAllInterrupts()   /* AUTOSAR OS */
#endif

/**********************************************************************************************************************
 * API for enable / disable interrupts up to the systemLevel
 *********************************************************************************************************************/

#if defined(osDisableLevelKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableOSInterrupts() osDisableLevelKM()   /* MICROSAR OS */
#else
# define Rte_DisableOSInterrupts() SuspendOSInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableLevelKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableOSInterrupts() osEnableLevelKM()   /* MICROSAR OS */
#else
# define Rte_EnableOSInterrupts() ResumeOSInterrupts()   /* AUTOSAR OS */
#endif


/**********************************************************************************************************************
 * Buffers for unqueued S/R
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_SystemApplication_OsCore4_NOCACHE_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(MotActRR, RTE_VAR_INIT_NOCACHE) Rte_CtMotor_RR_PpMotRRAct_MotRRAct = {
  0U, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_SystemApplication_OsCore4_NOCACHE_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
/**********************************************************************************************************************
 * Defines for Rte_ComSendSignalProxy
 *********************************************************************************************************************/
#define RTE_COM_SENDSIGNALPROXY_NOCHANGE       (0U)
#define RTE_COM_SENDSIGNALPROXY_SEND           (1U)
#define RTE_COM_SENDSIGNALPROXY_INVALIDATE     (2U)


#define RTE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, RTE_CODE) Rte_MemClr(P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT) ptr, uint32_least num); /* PRQA S 0850, 3447, 3408 */ /* MD_MSR_19.8, MD_Rte_3447, MD_Rte_3408 */

#define RTE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Timer handling
 *********************************************************************************************************************/

#if defined OS_US2TICKS_SystemTimer0
# define RTE_USEC_SystemTimer0 OS_US2TICKS_SystemTimer0
#else
# define RTE_USEC_SystemTimer0(val) ((TickType)RTE_CONST_USEC_SystemTimer0_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_MS2TICKS_SystemTimer0
# define RTE_MSEC_SystemTimer0 OS_MS2TICKS_SystemTimer0
#else
# define RTE_MSEC_SystemTimer0(val) ((TickType)RTE_CONST_MSEC_SystemTimer0_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_SEC2TICKS_SystemTimer0
# define RTE_SEC_SystemTimer0 OS_SEC2TICKS_SystemTimer0
#else
# define RTE_SEC_SystemTimer0(val)  ((TickType)RTE_CONST_SEC_SystemTimer0_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_US2TICKS_SystemTimer1
# define RTE_USEC_SystemTimer1 OS_US2TICKS_SystemTimer1
#else
# define RTE_USEC_SystemTimer1(val) ((TickType)RTE_CONST_USEC_SystemTimer1_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_MS2TICKS_SystemTimer1
# define RTE_MSEC_SystemTimer1 OS_MS2TICKS_SystemTimer1
#else
# define RTE_MSEC_SystemTimer1(val) ((TickType)RTE_CONST_MSEC_SystemTimer1_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_SEC2TICKS_SystemTimer1
# define RTE_SEC_SystemTimer1 OS_SEC2TICKS_SystemTimer1
#else
# define RTE_SEC_SystemTimer1(val)  ((TickType)RTE_CONST_SEC_SystemTimer1_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_US2TICKS_SystemTimer2
# define RTE_USEC_SystemTimer2 OS_US2TICKS_SystemTimer2
#else
# define RTE_USEC_SystemTimer2(val) ((TickType)RTE_CONST_USEC_SystemTimer2_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_MS2TICKS_SystemTimer2
# define RTE_MSEC_SystemTimer2 OS_MS2TICKS_SystemTimer2
#else
# define RTE_MSEC_SystemTimer2(val) ((TickType)RTE_CONST_MSEC_SystemTimer2_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_SEC2TICKS_SystemTimer2
# define RTE_SEC_SystemTimer2 OS_SEC2TICKS_SystemTimer2
#else
# define RTE_SEC_SystemTimer2(val)  ((TickType)RTE_CONST_SEC_SystemTimer2_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_US2TICKS_SystemTimer3
# define RTE_USEC_SystemTimer3 OS_US2TICKS_SystemTimer3
#else
# define RTE_USEC_SystemTimer3(val) ((TickType)RTE_CONST_USEC_SystemTimer3_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_MS2TICKS_SystemTimer3
# define RTE_MSEC_SystemTimer3 OS_MS2TICKS_SystemTimer3
#else
# define RTE_MSEC_SystemTimer3(val) ((TickType)RTE_CONST_MSEC_SystemTimer3_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_SEC2TICKS_SystemTimer3
# define RTE_SEC_SystemTimer3 OS_SEC2TICKS_SystemTimer3
#else
# define RTE_SEC_SystemTimer3(val)  ((TickType)RTE_CONST_SEC_SystemTimer3_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_US2TICKS_SystemTimer4
# define RTE_USEC_SystemTimer4 OS_US2TICKS_SystemTimer4
#else
# define RTE_USEC_SystemTimer4(val) ((TickType)RTE_CONST_USEC_SystemTimer4_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_MS2TICKS_SystemTimer4
# define RTE_MSEC_SystemTimer4 OS_MS2TICKS_SystemTimer4
#else
# define RTE_MSEC_SystemTimer4(val) ((TickType)RTE_CONST_MSEC_SystemTimer4_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_SEC2TICKS_SystemTimer4
# define RTE_SEC_SystemTimer4 OS_SEC2TICKS_SystemTimer4
#else
# define RTE_SEC_SystemTimer4(val)  ((TickType)RTE_CONST_SEC_SystemTimer4_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_US2TICKS_SystemTimer5
# define RTE_USEC_SystemTimer5 OS_US2TICKS_SystemTimer5
#else
# define RTE_USEC_SystemTimer5(val) ((TickType)RTE_CONST_USEC_SystemTimer5_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_MS2TICKS_SystemTimer5
# define RTE_MSEC_SystemTimer5 OS_MS2TICKS_SystemTimer5
#else
# define RTE_MSEC_SystemTimer5(val) ((TickType)RTE_CONST_MSEC_SystemTimer5_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_SEC2TICKS_SystemTimer5
# define RTE_SEC_SystemTimer5 OS_SEC2TICKS_SystemTimer5
#else
# define RTE_SEC_SystemTimer5(val)  ((TickType)RTE_CONST_SEC_SystemTimer5_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#define RTE_CONST_MSEC_SystemTimer0_0 (0UL)
#define RTE_CONST_MSEC_SystemTimer1_0 (0UL)
#define RTE_CONST_MSEC_SystemTimer2_0 (0UL)
#define RTE_CONST_MSEC_SystemTimer3_0 (0UL)
#define RTE_CONST_MSEC_SystemTimer4_0 (0UL)
#define RTE_CONST_MSEC_SystemTimer5_0 (0UL)
#define RTE_CONST_MSEC_SystemTimer0_1 (100000UL)
#define RTE_CONST_MSEC_SystemTimer1_1 (100000UL)
#define RTE_CONST_MSEC_SystemTimer2_1 (100000UL)
#define RTE_CONST_MSEC_SystemTimer3_1 (100000UL)
#define RTE_CONST_MSEC_SystemTimer4_1 (100000UL)
#define RTE_CONST_MSEC_SystemTimer0_10 (1000000UL)
#define RTE_CONST_MSEC_SystemTimer1_10 (1000000UL)
#define RTE_CONST_MSEC_SystemTimer2_10 (1000000UL)
#define RTE_CONST_MSEC_SystemTimer3_10 (1000000UL)
#define RTE_CONST_MSEC_SystemTimer4_10 (1000000UL)
#define RTE_CONST_MSEC_SystemTimer5_10 (1000000UL)
#define RTE_CONST_MSEC_SystemTimer0_20 (2000000UL)
#define RTE_CONST_MSEC_SystemTimer0_3 (300000UL)
#define RTE_CONST_MSEC_SystemTimer0_4 (400000UL)
#define RTE_CONST_MSEC_SystemTimer0_5 (500000UL)
#define RTE_CONST_MSEC_SystemTimer0_50 (5000000UL)


/**********************************************************************************************************************
 * Internal definitions
 *********************************************************************************************************************/

#define RTE_TASK_TIMEOUT_EVENT_MASK   ((EventMaskType)0x01)
#define RTE_TASK_WAITPOINT_EVENT_MASK ((EventMaskType)0x02)

/**********************************************************************************************************************
 * RTE life cycle API
 *********************************************************************************************************************/

#define RTE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


FUNC(void, RTE_CODE) Rte_InitMemory_SystemApplication_OsCore4(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* set default values for internal data */
  Rte_CtMotor_RR_PpMotRRAct_MotRRAct = Rte_C_MotActRR_0;

}


/**********************************************************************************************************************
 * Internal/External Tx connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtMotor_RR_PpMotRRAct_MotRRAct(P2CONST(MotActRR, AUTOMATIC, RTE_CTMOTOR_RR_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  (void)GetSpinlock(Rte_Spinlock_CtMotor_RR_PpMotRRAct_MotRRAct);
  Rte_CtMotor_RR_PpMotRRAct_MotRRAct = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_CtMotor_RR_PpMotRRAct_MotRRAct);

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */


/**********************************************************************************************************************
 * Internal/External Rx connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMotor_RR_PpMotTgtOutRR_MotTgtOutRR(P2VAR(MotTgtOutRR, AUTOMATIC, RTE_CTMOTOR_RR_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  (void)GetSpinlock(Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutRR_MotTgtOutRR);
  *(data) = Rte_CtMDA_Control_Logic_PpMotTgtOutRR_MotTgtOutRR;
  (void)ReleaseSpinlock(Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutRR_MotTgtOutRR);

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */


/**********************************************************************************************************************
 * Task bodies for RTE controlled tasks
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Task:     APP_Task_Core4
 * Priority: 50
 * Schedule: FULL
 * Alarm:    Cycle Time 0.001 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(APP_Task_Core4) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{

  /* call runnable */
  CpApMotor_RR();

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     SchM_Core4
 * Priority: 20
 * Schedule: FULL
 * Alarm:    Cycle Time 0.01 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(SchM_Core4) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{

  /* call schedulable entity */
  EcuM_MainFunction();

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0781:  MISRA rule: 5.6
     Reason:     The name is being used as a structure/union member as well as being a label, tag or ordinary identifier.
                 The compliance to this rule is under user's control.
     Risk:       Ambiguous identifiers can lead to compiler errors / warnings.
     Prevention: Verified during compile time. If the compiler reports an error or warning, the user has to rename the objects leading to the violation.

   MD_Rte_3408:  MISRA rule: 8.8
     Reason:     For the purpose of monitoring during calibration or debugging it is necessary to use non-static declarations.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3447:  MISRA rule: 8.8
     Reason:     For the purpose of monitoring during calibration or debugging it is necessary to use non-static declarations.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_Os:
     Reason:     This justification is used as summary justification for all deviations caused by the MICROSAR OS
                 which is for testing of the RTE. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_Qac:
     Reason:     This justification is used as summary justification for all deviations caused by wrong analysis tool results.
                 The used analysis tool QAC 7.0 sometimes creates wrong messages. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/
