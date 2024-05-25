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
 *          File:  SchM_Mcu.h
 *        Config:  E:/Autosar_CP/TC397_Classic/SIP_0317/give_customer/Bsw_Project/Bsw_Project.dpa
 *    BSW Module:  Mcu
 *  Generated at:  Tue Mar 21 20:44:33 2023
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  Header of BSW Scheduler for BSW Module <Mcu> (Contract Phase)
 *********************************************************************************************************************/
#ifndef SCHM_MCU_H
# define SCHM_MCU_H

# ifdef __cplusplus
extern "C" {
# endif  /* __cplusplus */

# include "SchM_Mcu_Type.h"

# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, RTE_CODE) SchM_Enter_Mcu_AtomAgcReg(void);
FUNC(void, RTE_CODE) SchM_Exit_Mcu_AtomAgcReg(void);
FUNC(void, RTE_CODE) SchM_Enter_Mcu_TomTgcReg(void);
FUNC(void, RTE_CODE) SchM_Exit_Mcu_TomTgcReg(void);

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif  /* __cplusplus */

#endif /* SCHM_MCU_H */
