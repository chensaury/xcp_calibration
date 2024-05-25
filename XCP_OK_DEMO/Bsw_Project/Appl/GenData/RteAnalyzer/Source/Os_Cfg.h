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
 *   ECU-Project:  ITMS
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
# define SchM_Core0 (6U)
# define SchM_Core1 (7U)
# define SchM_Core2 (8U)
# define SchM_Core3 (9U)
# define SchM_Core4 (10U)
# define SchM_Core5 (11U)

/* Alarms */
# define Rte_Al_TE_Core0Swc_Core0Runnable (0U)
# define Rte_Al_TE_Core1Swc_Core1Runnable (1U)
# define Rte_Al_TE_Core2Swc_Core2Runnable (2U)
# define Rte_Al_TE_Core3Swc_Core3Runnable (3U)
# define Rte_Al_TE_Core4Swc_Core4Runnable (4U)
# define Rte_Al_TE_Core5Swc_Core5Runnable (5U)
# define Rte_Al_TE2_SchM_Core0_0_10ms (6U)
# define Rte_Al_TE2_SchM_Core0_0_1ms (7U)
# define Rte_Al_TE2_SchM_Core0_0_20ms (8U)
# define Rte_Al_TE2_SchM_Core0_0_5ms (9U)
# define Rte_Al_TE1_EcuM_EcuM_MainFunction (10U)
# define Rte_Al_TE2_EcuM_EcuM_MainFunction (11U)
# define Rte_Al_TE3_EcuM_EcuM_MainFunction (12U)
# define Rte_Al_TE4_EcuM_EcuM_MainFunction (13U)
# define Rte_Al_TE6_EcuM_EcuM_MainFunction (14U)

/* Events */
# define Rte_Ev_Cyclic2_SchM_Core0_0_10ms (0x01)
# define Rte_Ev_Cyclic2_SchM_Core0_0_1ms (0x04)
# define Rte_Ev_Cyclic2_SchM_Core0_0_20ms (0x02)
# define Rte_Ev_Cyclic2_SchM_Core0_0_5ms (0x08)

/* Spinlocks */

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
