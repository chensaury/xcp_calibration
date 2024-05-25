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
 *          File:  SchM_Spi.h
 *        Config:  Bsw_Project.dpa
 *   ECU-Project:  MDA
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  Header of BSW Scheduler for BSW Module <Spi>
 *********************************************************************************************************************/
#ifndef SCHM_SPI_H
# define SCHM_SPI_H

# ifdef __cplusplus
extern "C" {
# endif  /* __cplusplus */

# include "SchM_Spi_Type.h"

# define SPI_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, SPI_CODE) Spi_MainFunction_Handling(void); /* PRQA S 3451 */ /* MD_Rte_3451 */

# define SPI_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, RTE_CODE) SchM_Enter_Spi_Buffer_Update(void);
FUNC(void, RTE_CODE) SchM_Exit_Spi_Buffer_Update(void);
FUNC(void, RTE_CODE) SchM_Enter_Spi_Cancel_Seq(void);
FUNC(void, RTE_CODE) SchM_Exit_Spi_Cancel_Seq(void);
FUNC(void, RTE_CODE) SchM_Enter_Spi_ChannelLock(void);
FUNC(void, RTE_CODE) SchM_Exit_Spi_ChannelLock(void);
FUNC(void, RTE_CODE) SchM_Enter_Spi_Queue_Update(void);
FUNC(void, RTE_CODE) SchM_Exit_Spi_Queue_Update(void);
FUNC(void, RTE_CODE) SchM_Enter_Spi_Queue_Update_QSPI0(void);
FUNC(void, RTE_CODE) SchM_Exit_Spi_Queue_Update_QSPI0(void);
FUNC(void, RTE_CODE) SchM_Enter_Spi_Queue_Update_QSPI1(void);
FUNC(void, RTE_CODE) SchM_Exit_Spi_Queue_Update_QSPI1(void);
FUNC(void, RTE_CODE) SchM_Enter_Spi_Queue_Update_QSPI2(void);
FUNC(void, RTE_CODE) SchM_Exit_Spi_Queue_Update_QSPI2(void);
FUNC(void, RTE_CODE) SchM_Enter_Spi_Queue_Update_QSPI3(void);
FUNC(void, RTE_CODE) SchM_Exit_Spi_Queue_Update_QSPI3(void);
FUNC(void, RTE_CODE) SchM_Enter_Spi_Queue_Update_QSPI4(void);
FUNC(void, RTE_CODE) SchM_Exit_Spi_Queue_Update_QSPI4(void);
FUNC(void, RTE_CODE) SchM_Enter_Spi_Queue_Update_QSPI5(void);
FUNC(void, RTE_CODE) SchM_Exit_Spi_Queue_Update_QSPI5(void);
FUNC(void, RTE_CODE) SchM_Enter_Spi_SyncLock(void);
FUNC(void, RTE_CODE) SchM_Exit_Spi_SyncLock(void);

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif  /* __cplusplus */

#endif /* SCHM_SPI_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
