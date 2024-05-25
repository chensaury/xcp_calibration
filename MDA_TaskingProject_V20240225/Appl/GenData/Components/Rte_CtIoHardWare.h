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
 *          File:  Rte_CtIoHardWare.h
 *        Config:  Bsw_Project.dpa
 *   ECU-Project:  MDA
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  Application header file for SW-C <CtIoHardWare>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CTIOHARDWARE_H
# define _RTE_CTIOHARDWARE_H

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

# include "Rte_CtIoHardWare_Type.h"
# include "Rte_DataHandleType.h"


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtIoHardWare_PpIMU_IMUAcc(P2CONST(IMUAcc, AUTOMATIC, RTE_CTIOHARDWARE_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtIoHardWare_PpIMU_IMUAngle(P2CONST(IMUAngle, AUTOMATIC, RTE_CTIOHARDWARE_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtIoHardWare_PpIMU_IMURate(P2CONST(IMURate, AUTOMATIC, RTE_CTIOHARDWARE_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtIoHardWare_PpIMU_IMUVel(P2CONST(IMUVel, AUTOMATIC, RTE_CTIOHARDWARE_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtIoHardWare_PpPedlPos_PedlPos(P2CONST(PedlPos, AUTOMATIC, RTE_CTIOHARDWARE_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtIoHardWare_PpPressure_Pressure(P2CONST(Pressure, AUTOMATIC, RTE_CTIOHARDWARE_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtIoHardWare_PpSteerWhl_SteerWhl(P2CONST(SteerWhl, AUTOMATIC, RTE_CTIOHARDWARE_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtIoHardWare_PpSuspHeight_SuspHeight(P2CONST(SuspHeight, AUTOMATIC, RTE_CTIOHARDWARE_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_PpIMU_IMUAcc Rte_Write_CtIoHardWare_PpIMU_IMUAcc
#  define Rte_Write_PpIMU_IMUAngle Rte_Write_CtIoHardWare_PpIMU_IMUAngle
#  define Rte_Write_PpIMU_IMURate Rte_Write_CtIoHardWare_PpIMU_IMURate
#  define Rte_Write_PpIMU_IMUVel Rte_Write_CtIoHardWare_PpIMU_IMUVel
#  define Rte_Write_PpPedlPos_PedlPos Rte_Write_CtIoHardWare_PpPedlPos_PedlPos
#  define Rte_Write_PpPressure_Pressure Rte_Write_CtIoHardWare_PpPressure_Pressure
#  define Rte_Write_PpSteerWhl_SteerWhl Rte_Write_CtIoHardWare_PpSteerWhl_SteerWhl
#  define Rte_Write_PpSuspHeight_SuspHeight Rte_Write_CtIoHardWare_PpSuspHeight_SuspHeight


# endif /* !defined(RTE_CORE) */


# define CtIoHardWare_START_SEC_CODE
# include "CtIoHardWare_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Adc_Write Adc_Write
# endif

FUNC(void, CtIoHardWare_CODE) Adc_Write(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define CtIoHardWare_STOP_SEC_CODE
# include "CtIoHardWare_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CTIOHARDWARE_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
