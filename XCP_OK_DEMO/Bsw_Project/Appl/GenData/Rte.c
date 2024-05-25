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
 *          File:  Rte.c
 *        Config:  Bsw_Project.dpa
 *   ECU-Project:  ITMS
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
#include "Rte_Core0Swc.h"
#include "Rte_Core1Swc.h"
#include "Rte_Core2Swc.h"
#include "Rte_Core3Swc.h"
#include "Rte_Core4Swc.h"
#include "Rte_Core5Swc.h"
#include "Rte_Det.h"
#include "Rte_EcuM.h"
#include "Rte_Os_OsCore0_swc.h"
#include "Rte_Os_OsCore1_swc.h"
#include "Rte_Os_OsCore2_swc.h"
#include "Rte_Os_OsCore3_swc.h"
#include "Rte_Os_OsCore4_swc.h"
#include "Rte_Os_OsCore5_swc.h"
#include "SchM_BswM.h"
#include "SchM_Can.h"
#include "SchM_CanIf.h"
#include "SchM_CanSM.h"
#include "SchM_Com.h"
#include "SchM_ComM.h"
#include "SchM_Det.h"
#include "SchM_Dio.h"
#include "SchM_EcuM.h"
#include "SchM_McalLib.h"
#include "SchM_Mcu.h"
#include "SchM_PduR.h"
#include "SchM_Port.h"
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
 * Rte Init State Variable
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

volatile VAR(uint8, RTE_VAR_ZERO_INIT) Rte_InitState = RTE_STATE_UNINIT; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */

#define RTE_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

volatile VAR(uint8, RTE_VAR_ZERO_INIT_NOCACHE) Rte_InitState_1 = RTE_STATE_UNINIT; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */

#define RTE_STOP_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

volatile VAR(uint8, RTE_VAR_ZERO_INIT_NOCACHE) Rte_InitState_2 = RTE_STATE_UNINIT; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */

#define RTE_STOP_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

volatile VAR(uint8, RTE_VAR_ZERO_INIT_NOCACHE) Rte_InitState_3 = RTE_STATE_UNINIT; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */

#define RTE_STOP_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

volatile VAR(uint8, RTE_VAR_ZERO_INIT_NOCACHE) Rte_InitState_4 = RTE_STATE_UNINIT; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */

#define RTE_STOP_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

volatile VAR(uint8, RTE_VAR_ZERO_INIT_NOCACHE) Rte_InitState_5 = RTE_STATE_UNINIT; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */

#define RTE_STOP_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
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
#define RTE_CONST_MSEC_SystemTimer0_10 (1000000UL)
#define RTE_CONST_MSEC_SystemTimer1_10 (1000000UL)
#define RTE_CONST_MSEC_SystemTimer2_10 (1000000UL)
#define RTE_CONST_MSEC_SystemTimer3_10 (1000000UL)
#define RTE_CONST_MSEC_SystemTimer4_10 (1000000UL)
#define RTE_CONST_MSEC_SystemTimer5_10 (1000000UL)
#define RTE_CONST_MSEC_SystemTimer0_100 (10000000UL)
#define RTE_CONST_MSEC_SystemTimer0_20 (2000000UL)
#define RTE_CONST_MSEC_SystemTimer1_200 (20000000UL)
#define RTE_CONST_MSEC_SystemTimer0_5 (500000UL)
#define RTE_CONST_MSEC_SystemTimer2_500 (50000000UL)

#define RTE_CONST_SEC_SystemTimer3_0 (0UL)
#define RTE_CONST_SEC_SystemTimer4_0 (0UL)
#define RTE_CONST_SEC_SystemTimer5_0 (0UL)
#define RTE_CONST_SEC_SystemTimer3_1 (100000000UL)
#define RTE_CONST_SEC_SystemTimer4_2 (200000000UL)
#define RTE_CONST_SEC_SystemTimer5_5 (500000000UL)


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

FUNC(void, RTE_CODE) Rte_MemClr(P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT) ptr, uint32_least num)
{
  P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) dst = (P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT))ptr;
  uint32_least i;
  for (i = 0; i < num; i++)
  {
    dst[i] = 0;
  }
}

FUNC(void, RTE_CODE) SchM_Init(void)
{
  uint32 id = GetCoreID();
  if (id == OS_CORE_ID_0)
  {
    /* activate the tasks */
    (void)ActivateTask(SchM_Core0); /* PRQA S 3417 */ /* MD_Rte_Os */

    /* activate the alarms used for TimingEvents */
    (void)SetRelAlarm(Rte_Al_TE2_SchM_Core0_0_10ms, RTE_MSEC_SystemTimer0(0) + (TickType)1, RTE_MSEC_SystemTimer0(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)SetRelAlarm(Rte_Al_TE2_SchM_Core0_0_1ms, RTE_MSEC_SystemTimer0(0) + (TickType)1, RTE_MSEC_SystemTimer0(1)); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)SetRelAlarm(Rte_Al_TE2_SchM_Core0_0_20ms, RTE_MSEC_SystemTimer0(0) + (TickType)1, RTE_MSEC_SystemTimer0(20)); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)SetRelAlarm(Rte_Al_TE2_SchM_Core0_0_5ms, RTE_MSEC_SystemTimer0(0) + (TickType)1, RTE_MSEC_SystemTimer0(5)); /* PRQA S 3417 */ /* MD_Rte_Os */

    Rte_InitState = RTE_STATE_SCHM_INIT;
  }
  if (id == OS_CORE_ID_1)
  {
    /* activate the alarms used for TimingEvents */
    (void)SetRelAlarm(Rte_Al_TE1_EcuM_EcuM_MainFunction, RTE_MSEC_SystemTimer1(0) + (TickType)1, RTE_MSEC_SystemTimer1(10)); /* PRQA S 3417 */ /* MD_Rte_Os */

    Rte_InitState_1 = RTE_STATE_SCHM_INIT;
  }
  if (id == OS_CORE_ID_2)
  {
    /* activate the alarms used for TimingEvents */
    (void)SetRelAlarm(Rte_Al_TE2_EcuM_EcuM_MainFunction, RTE_MSEC_SystemTimer2(0) + (TickType)1, RTE_MSEC_SystemTimer2(10)); /* PRQA S 3417 */ /* MD_Rte_Os */

    Rte_InitState_2 = RTE_STATE_SCHM_INIT;
  }
  if (id == OS_CORE_ID_3)
  {
    /* activate the alarms used for TimingEvents */
    (void)SetRelAlarm(Rte_Al_TE3_EcuM_EcuM_MainFunction, RTE_MSEC_SystemTimer3(0) + (TickType)1, RTE_MSEC_SystemTimer3(10)); /* PRQA S 3417 */ /* MD_Rte_Os */

    Rte_InitState_3 = RTE_STATE_SCHM_INIT;
  }
  if (id == OS_CORE_ID_4)
  {
    /* activate the alarms used for TimingEvents */
    (void)SetRelAlarm(Rte_Al_TE4_EcuM_EcuM_MainFunction, RTE_MSEC_SystemTimer4(0) + (TickType)1, RTE_MSEC_SystemTimer4(10)); /* PRQA S 3417 */ /* MD_Rte_Os */

    Rte_InitState_4 = RTE_STATE_SCHM_INIT;
  }
  if (id == OS_CORE_ID_5)
  {
    /* activate the alarms used for TimingEvents */
    (void)SetRelAlarm(Rte_Al_TE6_EcuM_EcuM_MainFunction, RTE_MSEC_SystemTimer5(0) + (TickType)1, RTE_MSEC_SystemTimer5(10)); /* PRQA S 3417 */ /* MD_Rte_Os */

    Rte_InitState_5 = RTE_STATE_SCHM_INIT;
  }
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Start(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  uint32 id = GetCoreID();
  if (id == OS_CORE_ID_0)
  {
    /* activate the alarms used for TimingEvents */
    (void)SetRelAlarm(Rte_Al_TE_Core5Swc_Core5Runnable, RTE_SEC_SystemTimer5(0) + (TickType)1, RTE_SEC_SystemTimer5(5)); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)SetRelAlarm(Rte_Al_TE_Core4Swc_Core4Runnable, RTE_SEC_SystemTimer4(0) + (TickType)1, RTE_SEC_SystemTimer4(2)); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)SetRelAlarm(Rte_Al_TE_Core3Swc_Core3Runnable, RTE_SEC_SystemTimer3(0) + (TickType)1, RTE_SEC_SystemTimer3(1)); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)SetRelAlarm(Rte_Al_TE_Core2Swc_Core2Runnable, RTE_MSEC_SystemTimer2(0) + (TickType)1, RTE_MSEC_SystemTimer2(500)); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)SetRelAlarm(Rte_Al_TE_Core1Swc_Core1Runnable, RTE_MSEC_SystemTimer1(0) + (TickType)1, RTE_MSEC_SystemTimer1(200)); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)SetRelAlarm(Rte_Al_TE_Core0Swc_Core0Runnable, RTE_MSEC_SystemTimer0(0) + (TickType)1, RTE_MSEC_SystemTimer0(100)); /* PRQA S 3417 */ /* MD_Rte_Os */

    Rte_InitState = RTE_STATE_INIT;

  }
  if (id == OS_CORE_ID_1)
  {
    Rte_InitState_1 = RTE_STATE_INIT;

  }
  if (id == OS_CORE_ID_2)
  {
    Rte_InitState_2 = RTE_STATE_INIT;

  }
  if (id == OS_CORE_ID_3)
  {
    Rte_InitState_3 = RTE_STATE_INIT;

  }
  if (id == OS_CORE_ID_4)
  {
    Rte_InitState_4 = RTE_STATE_INIT;

  }
  if (id == OS_CORE_ID_5)
  {
    Rte_InitState_5 = RTE_STATE_INIT;

  }
  return RTE_E_OK;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Stop(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  uint32 id = GetCoreID();
  if (id == OS_CORE_ID_0)
  {
    /* deactivate alarms */
    (void)CancelAlarm(Rte_Al_TE_Core0Swc_Core0Runnable); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)CancelAlarm(Rte_Al_TE_Core1Swc_Core1Runnable); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)CancelAlarm(Rte_Al_TE_Core2Swc_Core2Runnable); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)CancelAlarm(Rte_Al_TE_Core3Swc_Core3Runnable); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)CancelAlarm(Rte_Al_TE_Core4Swc_Core4Runnable); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)CancelAlarm(Rte_Al_TE_Core5Swc_Core5Runnable); /* PRQA S 3417 */ /* MD_Rte_Os */

    Rte_InitState = RTE_STATE_SCHM_INIT;

  }
  if (id == OS_CORE_ID_1)
  {
    Rte_InitState_1 = RTE_STATE_SCHM_INIT;

  }
  if (id == OS_CORE_ID_2)
  {
    Rte_InitState_2 = RTE_STATE_SCHM_INIT;

  }
  if (id == OS_CORE_ID_3)
  {
    Rte_InitState_3 = RTE_STATE_SCHM_INIT;

  }
  if (id == OS_CORE_ID_4)
  {
    Rte_InitState_4 = RTE_STATE_SCHM_INIT;

  }
  if (id == OS_CORE_ID_5)
  {
    Rte_InitState_5 = RTE_STATE_SCHM_INIT;

  }
  return RTE_E_OK;
}

FUNC(void, RTE_CODE) SchM_Deinit(void)
{
  uint32 id = GetCoreID();
  if (id == OS_CORE_ID_0)
  {
    /* deactivate alarms */
    (void)CancelAlarm(Rte_Al_TE2_SchM_Core0_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)CancelAlarm(Rte_Al_TE2_SchM_Core0_0_1ms); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)CancelAlarm(Rte_Al_TE2_SchM_Core0_0_20ms); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)CancelAlarm(Rte_Al_TE2_SchM_Core0_0_5ms); /* PRQA S 3417 */ /* MD_Rte_Os */

    Rte_InitState = RTE_STATE_UNINIT;
  }
  if (id == OS_CORE_ID_1)
  {
    /* deactivate alarms */
    (void)CancelAlarm(Rte_Al_TE1_EcuM_EcuM_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */

    Rte_InitState_1 = RTE_STATE_UNINIT;
  }
  if (id == OS_CORE_ID_2)
  {
    /* deactivate alarms */
    (void)CancelAlarm(Rte_Al_TE2_EcuM_EcuM_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */

    Rte_InitState_2 = RTE_STATE_UNINIT;
  }
  if (id == OS_CORE_ID_3)
  {
    /* deactivate alarms */
    (void)CancelAlarm(Rte_Al_TE3_EcuM_EcuM_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */

    Rte_InitState_3 = RTE_STATE_UNINIT;
  }
  if (id == OS_CORE_ID_4)
  {
    /* deactivate alarms */
    (void)CancelAlarm(Rte_Al_TE4_EcuM_EcuM_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */

    Rte_InitState_4 = RTE_STATE_UNINIT;
  }
  if (id == OS_CORE_ID_5)
  {
    /* deactivate alarms */
    (void)CancelAlarm(Rte_Al_TE6_EcuM_EcuM_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */

    Rte_InitState_5 = RTE_STATE_UNINIT;
  }
}

FUNC(void, RTE_CODE) Rte_InitMemory(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  uint32 id;
  id = GetCoreID();
  if (id == OS_CORE_ID_0)
  {
    Rte_InitState = RTE_STATE_UNINIT;
    Rte_InitMemory_SystemApplication_OsCore0();
  }
  else if (id == OS_CORE_ID_1) /* PRQA S 2004 */ /* MD_Rte_2004 */
  {
    Rte_InitState_1 = RTE_STATE_UNINIT;
    Rte_InitMemory_SystemApplication_OsCore1();
  }
  else if (id == OS_CORE_ID_2) /* PRQA S 2004 */ /* MD_Rte_2004 */
  {
    Rte_InitState_2 = RTE_STATE_UNINIT;
    Rte_InitMemory_SystemApplication_OsCore2();
  }
  else if (id == OS_CORE_ID_3) /* PRQA S 2004 */ /* MD_Rte_2004 */
  {
    Rte_InitState_3 = RTE_STATE_UNINIT;
    Rte_InitMemory_SystemApplication_OsCore3();
  }
  else if (id == OS_CORE_ID_4) /* PRQA S 2004 */ /* MD_Rte_2004 */
  {
    Rte_InitState_4 = RTE_STATE_UNINIT;
    Rte_InitMemory_SystemApplication_OsCore4();
  }
  else if (id == OS_CORE_ID_5) /* PRQA S 2004 */ /* MD_Rte_2004 */
  {
    Rte_InitState_5 = RTE_STATE_UNINIT;
    Rte_InitMemory_SystemApplication_OsCore5();
  }
}


/**********************************************************************************************************************
 * Exclusive area access
 *********************************************************************************************************************/

FUNC(void, RTE_CODE) SchM_Enter_Mcu_AtomAgcReg(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

FUNC(void, RTE_CODE) SchM_Exit_Mcu_AtomAgcReg(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}


FUNC(void, RTE_CODE) SchM_Enter_Mcu_TomTgcReg(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}

FUNC(void, RTE_CODE) SchM_Exit_Mcu_TomTgcReg(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
}



/**********************************************************************************************************************
 * RTE Schedulable entity for COM-Access from different partitions
 *********************************************************************************************************************/
FUNC(void, RTE_CODE) Rte_ComSendSignalProxyPeriodic(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

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

   MD_Rte_2004:  MISRA rule: 14.10
     Reason:     The concluding else is not needed and an empty else makes the code more difficult to understand.
     Risk:       Wrong implementations could remain undetected.
     Prevention: Code inspection and test of different source code variants by the component test suites.

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

*/
