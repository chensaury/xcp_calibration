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
 *          File:  Os_Cfg.h
 *        Config:  Bsw_Project.dpa
 *   ECU-Project:  MDA
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  Os definitions
 *********************************************************************************************************************/

#ifndef _OS_CFG_H_
# define _OS_CFG_H_

/* Os definitions */

/* Tasks */
# define APP_Task_Core0 (0U)
# define APP_Task_Core1 (1U)
# define APP_Task_Core2 (2U)
# define APP_Task_Core3 (3U)
# define APP_Task_Core4 (4U)
# define APP_Task_Core5 (5U)
# define Core_OsTask_CDD (6U)
# define Core_OsTask_IOHW (7U)
# define Core_OsTask_PSI5 (8U)
# define Core_OsTask_PT2000 (9U)
# define SchM_Core0 (10U)
# define SchM_Core1 (11U)
# define SchM_Core2 (12U)
# define SchM_Core3 (13U)
# define SchM_Core4 (14U)
# define SchM_Core5 (15U)

/* Alarms */
# define Rte_Al_TE_CtMDA_Control_Logic_MDA_Control_Logic (0U)
# define Rte_Al_TE_CtMotor_FL_CpApMotor_FL (1U)
# define Rte_Al_TE_CtMotor_FR_CpApMotor_FR (2U)
# define Rte_Al_TE_CtMotor_RL_CpApMotor_RL (3U)
# define Rte_Al_TE_CtMotor_RR_CpApMotor_RR (4U)
# define Rte_Al_TE_Core5swc_Runnable (5U)
# define Rte_Al_TE_CtCDD_CtCDD (6U)
# define Rte_Al_TE_CtIoHardWare_Adc_Write (7U)
# define Rte_Al_TE_CtPWM_Handler_PWM_SET (8U)
# define Rte_Al_TE_CtPSI5_Handler_PSI5MAIN_HD (9U)
# define Rte_Al_TE_CtPT2000_Handler_PT2000_Diag_HD (10U)
# define Rte_Al_TE_CtPT2000_Handler_PT2000_Main_HD (11U)
# define Rte_Al_TE2_SchM_Core0_0_10ms (12U)
# define Rte_Al_TE2_SchM_Core0_0_1ms (13U)
# define Rte_Al_TE2_SchM_Core0_0_20ms (14U)
# define Rte_Al_TE2_SchM_Core0_0_5ms (15U)
# define Rte_Al_TE1_EcuM_EcuM_MainFunction (16U)
# define Rte_Al_TE2_EcuM_EcuM_MainFunction (17U)
# define Rte_Al_TE3_EcuM_EcuM_MainFunction (18U)
# define Rte_Al_TE4_EcuM_EcuM_MainFunction (19U)
# define Rte_Al_TE6_EcuM_EcuM_MainFunction (20U)

/* Events */
# define Rte_Ev_Cyclic2_SchM_Core0_0_10ms (0x02)
# define Rte_Ev_Cyclic2_SchM_Core0_0_1ms (0x04)
# define Rte_Ev_Cyclic2_SchM_Core0_0_20ms (0x01)
# define Rte_Ev_Cyclic2_SchM_Core0_0_5ms (0x08)
# define Rte_Ev_Run_CtIoHardWare_Adc_Write (0x01)
# define Rte_Ev_Run_CtPT2000_Handler_PT2000_Diag_HD (0x01)
# define Rte_Ev_Run_CtPT2000_Handler_PT2000_Main_HD (0x02)
# define Rte_Ev_Run_CtPWM_Handler_PWM_SET (0x02)

/* Spinlocks */
# define Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutFL_MotTgtOutFL (0U)
# define Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutFR_MotTgtOutFR (1U)
# define Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutRL_MotTgtOutRL (2U)
# define Rte_Spinlock_CtMDA_Control_Logic_PpMotTgtOutRR_MotTgtOutRR (3U)
# define Rte_Spinlock_CtMotor_FL_PpMotFLAct_MotFLAct (4U)
# define Rte_Spinlock_CtMotor_FR_PpMotFRAct_MotFRAct (5U)
# define Rte_Spinlock_CtMotor_RL_PpMotRLAct_MotRLAct (6U)
# define Rte_Spinlock_CtMotor_RR_PpMotRRAct_MotRRAct (7U)

/* Resources */

/* ScheduleTables */

/* Cores */
# define OS_CORE_ID_0 (0U)
# define OS_CORE_ID_1 (1U)
# define OS_CORE_ID_2 (2U)
# define OS_CORE_ID_3 (3U)
# define OS_CORE_ID_4 (4U)
# define OS_CORE_ID_5 (5U)
# include "usrostyp.h"

/* Trusted Functions */


#endif /* _OS_CFG_H_ */
