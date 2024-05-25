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
 *          File:  Rte_CtPT2000_Handler.h
 *        Config:  Bsw_Project.dpa
 *   ECU-Project:  MDA
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  Application header file for SW-C <CtPT2000_Handler>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CTPT2000_HANDLER_H
# define _RTE_CTPT2000_HANDLER_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_CtPT2000_Handler_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_INIT) Rte_CtMDA_Control_Logic_PpVlvTgtCCFF_VlvTgtChannel; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_PpVlvTgtCCFF_VlvTgtChannel (0U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtPT2000_Handler_PpVlvTgtCCFF_VlvTgtCurrent(P2VAR(VlvTgtCurrent, AUTOMATIC, RTE_CTPT2000_HANDLER_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtPT2000_Handler_PpVlvTgtCCFF_VlvTgtFlutter(P2VAR(VlvTgtFlutter, AUTOMATIC, RTE_CTPT2000_HANDLER_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtPT2000_Handler_PpVlvTgtCCFF_VlvTgtFrequency(P2VAR(VlvTgtFrequency, AUTOMATIC, RTE_CTPT2000_HANDLER_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtPT2000_Handler_PpVelFbAll_VlvFL(P2CONST(VlvActFL, AUTOMATIC, RTE_CTPT2000_HANDLER_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtPT2000_Handler_PpVelFbAll_VlvFR(P2CONST(VlvActFR, AUTOMATIC, RTE_CTPT2000_HANDLER_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtPT2000_Handler_PpVelFbAll_VlvRL(P2CONST(VlvActRL, AUTOMATIC, RTE_CTPT2000_HANDLER_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtPT2000_Handler_PpVelFbAll_VlvRR(P2CONST(VlvActRR, AUTOMATIC, RTE_CTPT2000_HANDLER_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_PpVlvTgtCCFF_VlvTgtChannel Rte_Read_CtPT2000_Handler_PpVlvTgtCCFF_VlvTgtChannel
#  define Rte_Read_CtPT2000_Handler_PpVlvTgtCCFF_VlvTgtChannel(data) (*(data) = Rte_CtMDA_Control_Logic_PpVlvTgtCCFF_VlvTgtChannel, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_PpVlvTgtCCFF_VlvTgtCurrent Rte_Read_CtPT2000_Handler_PpVlvTgtCCFF_VlvTgtCurrent
#  define Rte_Read_PpVlvTgtCCFF_VlvTgtFlutter Rte_Read_CtPT2000_Handler_PpVlvTgtCCFF_VlvTgtFlutter
#  define Rte_Read_PpVlvTgtCCFF_VlvTgtFrequency Rte_Read_CtPT2000_Handler_PpVlvTgtCCFF_VlvTgtFrequency


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_PpVelFbAll_VlvFL Rte_Write_CtPT2000_Handler_PpVelFbAll_VlvFL
#  define Rte_Write_PpVelFbAll_VlvFR Rte_Write_CtPT2000_Handler_PpVelFbAll_VlvFR
#  define Rte_Write_PpVelFbAll_VlvRL Rte_Write_CtPT2000_Handler_PpVelFbAll_VlvRL
#  define Rte_Write_PpVelFbAll_VlvRR Rte_Write_CtPT2000_Handler_PpVelFbAll_VlvRR


# endif /* !defined(RTE_CORE) */


# define CtPT2000_Handler_START_SEC_CODE
# include "CtPT2000_Handler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_PT2000_Diag_HD PT2000_Diag_HD
#  define RTE_RUNNABLE_PT2000_Main_HD PT2000_Main_HD
#  define RTE_RUNNABLE_PoPT2000_Ctrl_PT2000_Enable_mode PoPT2000_Ctrl_PT2000_Enable_mode
#  define RTE_RUNNABLE_PoPT2000_Ctrl_PT2000_Init PoPT2000_Ctrl_PT2000_Init
#  define RTE_RUNNABLE_PoPT2000_Ctrl_PT2000_Mode_Change PoPT2000_Ctrl_PT2000_Mode_Change
#  define RTE_RUNNABLE_PoPT2000_Ctrl_Set_ConstantCurrent PoPT2000_Ctrl_Set_ConstantCurrent
#  define RTE_RUNNABLE_PoPT2000_Ctrl_Set_Peak_Hold PoPT2000_Ctrl_Set_Peak_Hold
# endif

FUNC(void, CtPT2000_Handler_CODE) PT2000_Diag_HD(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtPT2000_Handler_CODE) PT2000_Main_HD(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, CtPT2000_Handler_CODE) PoPT2000_Ctrl_PT2000_Enable_mode(uint8 Ch_number, uint8 Mode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CtPT2000_Handler_CODE) PoPT2000_Ctrl_PT2000_Init(uint8 init); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CtPT2000_Handler_CODE) PoPT2000_Ctrl_PT2000_Mode_Change(uint8 Ch_number, uint8 Mode_Change); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CtPT2000_Handler_CODE) PoPT2000_Ctrl_Set_ConstantCurrent(uint8 ChannelID, uint16 Current, uint16 Frequency, uint16 Flutter); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CtPT2000_Handler_CODE) PoPT2000_Ctrl_Set_Peak_Hold(uint8 ChannelID, uint16 IboostB, uint16 tbias_tot, uint16 tbias_off, uint16 ibias, uint16 iboostP, uint16 tpeak_tot, uint16 tpeak_off, uint16 ipeak, uint16 tbypass, uint16 thold_tot, uint16 thold_off, uint16 ihold, uint16 fwtimeOFF); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CtPT2000_Handler_STOP_SEC_CODE
# include "CtPT2000_Handler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CTPT2000_HANDLER_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
