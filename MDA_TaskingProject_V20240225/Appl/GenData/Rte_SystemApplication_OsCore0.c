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
 *          File:  Rte_SystemApplication_OsCore0.c
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

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(IMUAcc, RTE_VAR_INIT) Rte_CtIoHardWare_PpIMU_IMUAcc = {
  0.0F, 0.0F, 0.0F
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(IMUAngle, RTE_VAR_INIT) Rte_CtIoHardWare_PpIMU_IMUAngle = {
  0.0F, 0.0F, 0.0F
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(IMURate, RTE_VAR_INIT) Rte_CtIoHardWare_PpIMU_IMURate = {
  0.0F, 0.0F, 0.0F
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(IMUVel, RTE_VAR_INIT) Rte_CtIoHardWare_PpIMU_IMUVel = {
  0.0F, 0.0F, 0.0F
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(PedlPos, RTE_VAR_INIT) Rte_CtIoHardWare_PpPedlPos_PedlPos = {
  0.0F, 0.0F
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Pressure, RTE_VAR_INIT) Rte_CtIoHardWare_PpPressure_Pressure = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SteerWhl, RTE_VAR_INIT) Rte_CtIoHardWare_PpSteerWhl_SteerWhl = {
  0.0F, 0.0F, 0.0F
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SuspHeight, RTE_VAR_INIT) Rte_CtIoHardWare_PpSuspHeight_SuspHeight = {
  0.0F, 0.0F, 0.0F, 0.0F
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_CtMDA_Control_Logic_PpVlvTgtCCFF_VlvTgtChannel = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(VlvTgtCurrent, RTE_VAR_INIT) Rte_CtMDA_Control_Logic_PpVlvTgtCCFF_VlvTgtCurrent = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(VlvTgtFlutter, RTE_VAR_INIT) Rte_CtMDA_Control_Logic_PpVlvTgtCCFF_VlvTgtFlutter = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(VlvTgtFrequency, RTE_VAR_INIT) Rte_CtMDA_Control_Logic_PpVlvTgtCCFF_VlvTgtFrequency = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(BodyAcc, RTE_VAR_INIT) Rte_CtPSI5_Handler_PpBodyAccZ_BodyAcc = {
  0.0F, 0.0F, 0.0F, 0.0F
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(WhlAcc, RTE_VAR_INIT) Rte_CtPSI5_Handler_PpWhlAccZ_WhlAcc = {
  0.0F, 0.0F, 0.0F, 0.0F
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(VlvActFL, RTE_VAR_INIT) Rte_CtPT2000_Handler_PpVelFbAll_VlvFL = {
  0U, 0U, 0U, 0U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(VlvActFR, RTE_VAR_INIT) Rte_CtPT2000_Handler_PpVelFbAll_VlvFR = {
  0U, 0U, 0U, 0U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(VlvActRL, RTE_VAR_INIT) Rte_CtPT2000_Handler_PpVelFbAll_VlvRL = {
  0U, 0U, 0U, 0U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(VlvActRR, RTE_VAR_INIT) Rte_CtPT2000_Handler_PpVelFbAll_VlvRR = {
  0U, 0U, 0U, 0U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(MotTgtOutFL, RTE_VAR_INIT_NOCACHE) Rte_CtMDA_Control_Logic_PpMotTgtOutFL_MotTgtOutFL = {
  0.0F, 0.0F, 0U, 0.0F, 0U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(MotTgtOutFR, RTE_VAR_INIT_NOCACHE) Rte_CtMDA_Control_Logic_PpMotTgtOutFR_MotTgtOutFR = {
  0.0F, 0.0F, 0U, 0.0F, 0U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(MotTgtOutRL, RTE_VAR_INIT_NOCACHE) Rte_CtMDA_Control_Logic_PpMotTgtOutRL_MotTgtOutRL = {
  0.0F, 0.0F, 0U, 0.0F, 0U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(MotTgtOutRR, RTE_VAR_INIT_NOCACHE) Rte_CtMDA_Control_Logic_PpMotTgtOutRR_MotTgtOutRR = {
  0.0F, 0.0F, 0U, 0.0F, 0U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * TxAck/ModeSwitchAck Flags
 *********************************************************************************************************************/


#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(Rte_SystemApplication_OsCore0_AckFlagsType, RTE_VAR_INIT) Rte_SystemApplication_OsCore0_AckFlags = { /* PRQA S 0850 */ /* MD_MSR_19.8 */
  1,
};

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define Rte_SystemApplication_OsCore0_AckFlagsInit() (Rte_MemClr(&Rte_SystemApplication_OsCore0_AckFlags, sizeof(Rte_SystemApplication_OsCore0_AckFlagsType)))
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
 * Data structures for mode management
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
VAR(BswM_ESH_Mode, RTE_VAR_INIT) Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_BswM_ESH_Mode_STARTUP; /* PRQA S 3408 */ /* MD_Rte_3408 */
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
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


FUNC(void, RTE_CODE) Rte_InitMemory_SystemApplication_OsCore0(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* set default values for internal data */
  Rte_CtIoHardWare_PpIMU_IMUAcc = Rte_C_IMUAcc_0;
  Rte_CtIoHardWare_PpIMU_IMUAngle = Rte_C_IMUAngle_0;
  Rte_CtIoHardWare_PpIMU_IMURate = Rte_C_IMURate_0;
  Rte_CtIoHardWare_PpIMU_IMUVel = Rte_C_IMUVel_0;
  Rte_CtIoHardWare_PpPedlPos_PedlPos = Rte_C_PedlPos_0;
  Rte_CtIoHardWare_PpPressure_Pressure = Rte_C_Pressure_0;
  Rte_CtIoHardWare_PpSteerWhl_SteerWhl = Rte_C_SteerWhl_0;
  Rte_CtIoHardWare_PpSuspHeight_SuspHeight = Rte_C_SuspHeight_0;
  Rte_CtMDA_Control_Logic_PpMotTgtOutFL_MotTgtOutFL = Rte_C_MotTgtOutFL_0;
  Rte_CtMDA_Control_Logic_PpMotTgtOutFR_MotTgtOutFR = Rte_C_MotTgtOutFR_0;
  Rte_CtMDA_Control_Logic_PpMotTgtOutRL_MotTgtOutRL = Rte_C_MotTgtOutRL_0;
  Rte_CtMDA_Control_Logic_PpMotTgtOutRR_MotTgtOutRR = Rte_C_MotTgtOutRR_0;
  Rte_CtMDA_Control_Logic_PpVlvTgtCCFF_VlvTgtChannel = 0U;
  Rte_CtMDA_Control_Logic_PpVlvTgtCCFF_VlvTgtCurrent = Rte_C_VlvTgtCurrent_0;
  Rte_CtMDA_Control_Logic_PpVlvTgtCCFF_VlvTgtFlutter = Rte_C_VlvTgtFlutter_0;
  Rte_CtMDA_Control_Logic_PpVlvTgtCCFF_VlvTgtFrequency = Rte_C_VlvTgtFrequency_0;
  Rte_CtPSI5_Handler_PpBodyAccZ_BodyAcc = Rte_C_BodyAcc_0;
  Rte_CtPSI5_Handler_PpWhlAccZ_WhlAcc = Rte_C_WhlAcc_0;
  Rte_CtPT2000_Handler_PpVelFbAll_VlvFL = Rte_C_VlvActFL_0;
  Rte_CtPT2000_Handler_PpVelFbAll_VlvFR = Rte_C_VlvActFR_0;
  Rte_CtPT2000_Handler_PpVelFbAll_VlvRL = Rte_C_VlvActRL_0;
  Rte_CtPT2000_Handler_PpVelFbAll_VlvRR = Rte_C_VlvActRR_0;

  /* reset Tx Ack Flags */
  Rte_SystemApplication_OsCore0_AckFlagsInit();
  Rte_SystemApplication_OsCore0_AckFlags.Rte_ModeSwitchAck_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode_Ack = 1;

  /* mode management initialization part 1 */

  Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_BswM_ESH_Mode_STARTUP;

}


/**********************************************************************************************************************
 * Internal/External Tx connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtIoHardWare_PpIMU_IMUAcc(P2CONST(IMUAcc, AUTOMATIC, RTE_CTIOHARDWARE_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  SuspendOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_CtIoHardWare_PpIMU_IMUAcc = *(data);
  ResumeOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtIoHardWare_PpIMU_IMUAngle(P2CONST(IMUAngle, AUTOMATIC, RTE_CTIOHARDWARE_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  SuspendOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_CtIoHardWare_PpIMU_IMUAngle = *(data);
  ResumeOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtIoHardWare_PpIMU_IMURate(P2CONST(IMURate, AUTOMATIC, RTE_CTIOHARDWARE_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  SuspendOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_CtIoHardWare_PpIMU_IMURate = *(data);
  ResumeOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtIoHardWare_PpIMU_IMUVel(P2CONST(IMUVel, AUTOMATIC, RTE_CTIOHARDWARE_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  SuspendOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_CtIoHardWare_PpIMU_IMUVel = *(data);
  ResumeOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtIoHardWare_PpPedlPos_PedlPos(P2CONST(PedlPos, AUTOMATIC, RTE_CTIOHARDWARE_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  SuspendOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_CtIoHardWare_PpPedlPos_PedlPos = *(data);
  ResumeOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtIoHardWare_PpPressure_Pressure(P2CONST(Pressure, AUTOMATIC, RTE_CTIOHARDWARE_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  SuspendOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_CtIoHardWare_PpPressure_Pressure = *(data);
  ResumeOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtIoHardWare_PpSteerWhl_SteerWhl(P2CONST(SteerWhl, AUTOMATIC, RTE_CTIOHARDWARE_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  SuspendOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_CtIoHardWare_PpSteerWhl_SteerWhl = *(data);
  ResumeOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtIoHardWare_PpSuspHeight_SuspHeight(P2CONST(SuspHeight, AUTOMATIC, RTE_CTIOHARDWARE_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  SuspendOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_CtIoHardWare_PpSuspHeight_SuspHeight = *(data);
  ResumeOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtMDA_Control_Logic_PpMotTgtOutFL_MotTgtOutFL(P2CONST(MotTgtOutFL, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  (void)GetSpinlock(Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutFL_MotTgtOutFL);
  Rte_CtMDA_Control_Logic_PpMotTgtOutFL_MotTgtOutFL = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutFL_MotTgtOutFL);

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtMDA_Control_Logic_PpMotTgtOutFR_MotTgtOutFR(P2CONST(MotTgtOutFR, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  (void)GetSpinlock(Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutFR_MotTgtOutFR);
  Rte_CtMDA_Control_Logic_PpMotTgtOutFR_MotTgtOutFR = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutFR_MotTgtOutFR);

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtMDA_Control_Logic_PpMotTgtOutRL_MotTgtOutRL(P2CONST(MotTgtOutRL, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  (void)GetSpinlock(Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutRL_MotTgtOutRL);
  Rte_CtMDA_Control_Logic_PpMotTgtOutRL_MotTgtOutRL = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutRL_MotTgtOutRL);

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtMDA_Control_Logic_PpMotTgtOutRR_MotTgtOutRR(P2CONST(MotTgtOutRR, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  (void)GetSpinlock(Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutRR_MotTgtOutRR);
  Rte_CtMDA_Control_Logic_PpMotTgtOutRR_MotTgtOutRR = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutRR_MotTgtOutRR);

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtMDA_Control_Logic_PpVlvTgtCCFF_VlvTgtCurrent(P2CONST(VlvTgtCurrent, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_CtMDA_Control_Logic_PpVlvTgtCCFF_VlvTgtCurrent = *(data);

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtMDA_Control_Logic_PpVlvTgtCCFF_VlvTgtFlutter(P2CONST(VlvTgtFlutter, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_CtMDA_Control_Logic_PpVlvTgtCCFF_VlvTgtFlutter = *(data);

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtMDA_Control_Logic_PpVlvTgtCCFF_VlvTgtFrequency(P2CONST(VlvTgtFrequency, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_CtMDA_Control_Logic_PpVlvTgtCCFF_VlvTgtFrequency = *(data);

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtPSI5_Handler_PpBodyAccZ_BodyAcc(P2CONST(BodyAcc, AUTOMATIC, RTE_CTPSI5_HANDLER_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_CtPSI5_Handler_PpBodyAccZ_BodyAcc = *(data);

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtPSI5_Handler_PpWhlAccZ_WhlAcc(P2CONST(WhlAcc, AUTOMATIC, RTE_CTPSI5_HANDLER_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_CtPSI5_Handler_PpWhlAccZ_WhlAcc = *(data);

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtPT2000_Handler_PpVelFbAll_VlvFL(P2CONST(VlvActFL, AUTOMATIC, RTE_CTPT2000_HANDLER_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_CtPT2000_Handler_PpVelFbAll_VlvFL = *(data);
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtPT2000_Handler_PpVelFbAll_VlvFR(P2CONST(VlvActFR, AUTOMATIC, RTE_CTPT2000_HANDLER_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_CtPT2000_Handler_PpVelFbAll_VlvFR = *(data);
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtPT2000_Handler_PpVelFbAll_VlvRL(P2CONST(VlvActRL, AUTOMATIC, RTE_CTPT2000_HANDLER_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_CtPT2000_Handler_PpVelFbAll_VlvRL = *(data);
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtPT2000_Handler_PpVelFbAll_VlvRR(P2CONST(VlvActRR, AUTOMATIC, RTE_CTPT2000_HANDLER_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_CtPT2000_Handler_PpVelFbAll_VlvRR = *(data);
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */


/**********************************************************************************************************************
 * Internal/External Rx connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_PostRunRequest_0_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 0850, 3673, 1505, 3206 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10, MD_Rte_3206 */
{
  *data = 0U;

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_PostRunRequest_1_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 0850, 3673, 1505, 3206 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10, MD_Rte_3206 */
{
  *data = 0U;

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_RunRequest_0_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 0850, 3673, 1505, 3206 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10, MD_Rte_3206 */
{
  *data = 0U;

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_RunRequest_1_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 0850, 3673, 1505, 3206 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10, MD_Rte_3206 */
{
  *data = 0U;

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpBodyAccZ_BodyAcc(P2VAR(BodyAcc, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_CtPSI5_Handler_PpBodyAccZ_BodyAcc;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpIMU_IMUAcc(P2VAR(IMUAcc, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_CtIoHardWare_PpIMU_IMUAcc;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpIMU_IMUAngle(P2VAR(IMUAngle, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_CtIoHardWare_PpIMU_IMUAngle;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpIMU_IMURate(P2VAR(IMURate, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_CtIoHardWare_PpIMU_IMURate;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpIMU_IMUVel(P2VAR(IMUVel, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_CtIoHardWare_PpIMU_IMUVel;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpMotFLAct_MotFLAct(P2VAR(MotActFL, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  (void)GetSpinlock(Rte_Spinlock_CtMotor_FL_PpMotFLAct_MotFLAct);
  *(data) = Rte_CtMotor_FL_PpMotFLAct_MotFLAct;
  (void)ReleaseSpinlock(Rte_Spinlock_CtMotor_FL_PpMotFLAct_MotFLAct);

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpMotFRAct_MotFRAct(P2VAR(MotActFR, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  (void)GetSpinlock(Rte_Spinlock_CtMotor_FR_PpMotFRAct_MotFRAct);
  *(data) = Rte_CtMotor_FR_PpMotFRAct_MotFRAct;
  (void)ReleaseSpinlock(Rte_Spinlock_CtMotor_FR_PpMotFRAct_MotFRAct);

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpMotRLAct_MotRLAct(P2VAR(MotActRL, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  (void)GetSpinlock(Rte_Spinlock_CtMotor_RL_PpMotRLAct_MotRLAct);
  *(data) = Rte_CtMotor_RL_PpMotRLAct_MotRLAct;
  (void)ReleaseSpinlock(Rte_Spinlock_CtMotor_RL_PpMotRLAct_MotRLAct);

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpMotRRAct_MotRRAct(P2VAR(MotActRR, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  (void)GetSpinlock(Rte_Spinlock_CtMotor_RR_PpMotRRAct_MotRRAct);
  *(data) = Rte_CtMotor_RR_PpMotRRAct_MotRRAct;
  (void)ReleaseSpinlock(Rte_Spinlock_CtMotor_RR_PpMotRRAct_MotRRAct);

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpPedlPos_PedlPos(P2VAR(PedlPos, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_CtIoHardWare_PpPedlPos_PedlPos;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpPressure_Pressure(P2VAR(Pressure, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_CtIoHardWare_PpPressure_Pressure;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpSteerWhl_SteerWhl(P2VAR(SteerWhl, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_CtIoHardWare_PpSteerWhl_SteerWhl;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpSuspHeight_SuspHeight(P2VAR(SuspHeight, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_CtIoHardWare_PpSuspHeight_SuspHeight;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpVelFbAll_VlvFL(P2VAR(VlvActFL, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_CtPT2000_Handler_PpVelFbAll_VlvFL;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpVelFbAll_VlvFR(P2VAR(VlvActFR, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_CtPT2000_Handler_PpVelFbAll_VlvFR;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpVelFbAll_VlvRL(P2VAR(VlvActRL, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_CtPT2000_Handler_PpVelFbAll_VlvRL;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpVelFbAll_VlvRR(P2VAR(VlvActRR, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_CtPT2000_Handler_PpVelFbAll_VlvRR;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpWhlAccZ_WhlAcc(P2VAR(WhlAcc, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_CtPSI5_Handler_PpWhlAccZ_WhlAcc;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtPT2000_Handler_PpVlvTgtCCFF_VlvTgtCurrent(P2VAR(VlvTgtCurrent, AUTOMATIC, RTE_CTPT2000_HANDLER_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  *(data) = Rte_CtMDA_Control_Logic_PpVlvTgtCCFF_VlvTgtCurrent;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtPT2000_Handler_PpVlvTgtCCFF_VlvTgtFlutter(P2VAR(VlvTgtFlutter, AUTOMATIC, RTE_CTPT2000_HANDLER_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  *(data) = Rte_CtMDA_Control_Logic_PpVlvTgtCCFF_VlvTgtFlutter;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtPT2000_Handler_PpVlvTgtCCFF_VlvTgtFrequency(P2VAR(VlvTgtFrequency, AUTOMATIC, RTE_CTPT2000_HANDLER_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  *(data) = Rte_CtMDA_Control_Logic_PpVlvTgtCCFF_VlvTgtFrequency;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */


/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode(BswM_ESH_Mode nextMode) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  BswM_ESH_Mode currentMode;
  SuspendOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  currentMode = Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode;
  if (nextMode >= 5U)
  {
    ResumeOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }
  else if (currentMode >= 5U)
  {
    ResumeOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }
  else
  {
    Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = nextMode;
    ResumeOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */


/**********************************************************************************************************************
 * Mode reading API (Rte_Mode)
 *********************************************************************************************************************/

FUNC(BswM_ESH_Mode, RTE_CODE) Rte_Mode_BswM_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode(void) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  BswM_ESH_Mode curMode;
  curMode = Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode;
  return curMode;
}


/**********************************************************************************************************************
 * Task bodies for RTE controlled tasks
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Task:     APP_Task_Core0
 * Priority: 60
 * Schedule: FULL
 * Alarm:    Cycle Time 0.001 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(APP_Task_Core0) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{

  /* call runnable */
  MDA_Control_Logic();

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     Core_OsTask_CDD
 * Priority: 56
 * Schedule: FULL
 * Alarm:    Cycle Time 0.05 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Core_OsTask_CDD) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{

  /* call runnable */
  CtCDD();

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     Core_OsTask_IOHW
 * Priority: 57
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Core_OsTask_IOHW) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{
  EventMaskType ev;

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Run_CtIoHardWare_Adc_Write | Rte_Ev_Run_CtPWM_Handler_PWM_SET); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(Core_OsTask_IOHW, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Run_CtIoHardWare_Adc_Write | Rte_Ev_Run_CtPWM_Handler_PWM_SET)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Run_CtIoHardWare_Adc_Write) != (EventMaskType)0)
    {
      /* call runnable */
      Adc_Write();
    }

    if ((ev & Rte_Ev_Run_CtPWM_Handler_PWM_SET) != (EventMaskType)0)
    {
      /* call runnable */
      PWM_SET();
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     Core_OsTask_PSI5
 * Priority: 59
 * Schedule: NON
 * Alarm:    Cycle Time 0.003 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(Core_OsTask_PSI5) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{

  /* call runnable */
  PSI5MAIN_HD();

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     Core_OsTask_PT2000
 * Priority: 58
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Core_OsTask_PT2000) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{
  EventMaskType ev;

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Run_CtPT2000_Handler_PT2000_Diag_HD | Rte_Ev_Run_CtPT2000_Handler_PT2000_Main_HD); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(Core_OsTask_PT2000, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Run_CtPT2000_Handler_PT2000_Diag_HD | Rte_Ev_Run_CtPT2000_Handler_PT2000_Main_HD)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Run_CtPT2000_Handler_PT2000_Main_HD) != (EventMaskType)0)
    {
      /* call runnable */
      PT2000_Main_HD();
    }

    if ((ev & Rte_Ev_Run_CtPT2000_Handler_PT2000_Diag_HD) != (EventMaskType)0)
    {
      /* call runnable */
      PT2000_Diag_HD();
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     SchM_Core0
 * Priority: 20
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(SchM_Core0) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{
  EventMaskType ev;

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Cyclic2_SchM_Core0_0_10ms | Rte_Ev_Cyclic2_SchM_Core0_0_1ms | Rte_Ev_Cyclic2_SchM_Core0_0_20ms | Rte_Ev_Cyclic2_SchM_Core0_0_5ms); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(SchM_Core0, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic2_SchM_Core0_0_10ms | Rte_Ev_Cyclic2_SchM_Core0_0_1ms | Rte_Ev_Cyclic2_SchM_Core0_0_20ms | Rte_Ev_Cyclic2_SchM_Core0_0_5ms)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic2_SchM_Core0_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      BswM_MainFunction();

      /* call schedulable entity */
      CanSM_MainFunction();

      /* call schedulable entity */
      Can_MainFunction_BusOff();

      /* call schedulable entity */
      Can_MainFunction_Mode();

      /* call schedulable entity */
      Can_MainFunction_Wakeup();
    }

    if ((ev & Rte_Ev_Cyclic2_SchM_Core0_0_20ms) != (EventMaskType)0)
    {
      /* call runnable */
      ComM_MainFunction_0();

      /* call runnable */
      ComM_MainFunction_1();

      /* call runnable */
      ComM_MainFunction_2();

      /* call runnable */
      ComM_MainFunction_3();

      /* call runnable */
      ComM_MainFunction_4();

      /* call runnable */
      ComM_MainFunction_5();
    }

    if ((ev & Rte_Ev_Cyclic2_SchM_Core0_0_10ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      Com_MainFunctionRx();
    }

    if ((ev & Rte_Ev_Cyclic2_SchM_Core0_0_1ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      Com_MainFunctionTx();
    }

    if ((ev & Rte_Ev_Cyclic2_SchM_Core0_0_5ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      CanXcp_MainFunction();

      /* call schedulable entity */
      Xcp_MainFunction();
    }

    if ((ev & Rte_Ev_Cyclic2_SchM_Core0_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      EcuM_MainFunction();
    }

    if ((ev & Rte_Ev_Cyclic2_SchM_Core0_0_5ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      Spi_MainFunction_Handling();
    }

    if ((ev & Rte_Ev_Cyclic2_SchM_Core0_0_1ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      Rte_ComSendSignalProxyPeriodic();
    }
  }
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

   MD_Rte_3206:  MISRA rule: -
     Reason:     The parameter's are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

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
