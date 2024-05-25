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
 *          File:  Rte_CtMDA_Control_Logic.h
 *        Config:  Bsw_Project.dpa
 *   ECU-Project:  MDA
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  Application header file for SW-C <CtMDA_Control_Logic>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CTMDA_CONTROL_LOGIC_H
# define _RTE_CTMDA_CONTROL_LOGIC_H

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

# include "Rte_CtMDA_Control_Logic_Type.h"
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpBodyAccZ_BodyAcc(P2VAR(BodyAcc, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpIMU_IMUAcc(P2VAR(IMUAcc, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpIMU_IMUAngle(P2VAR(IMUAngle, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpIMU_IMURate(P2VAR(IMURate, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpIMU_IMUVel(P2VAR(IMUVel, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpMotFLAct_MotFLAct(P2VAR(MotActFL, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpMotFRAct_MotFRAct(P2VAR(MotActFR, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpMotRLAct_MotRLAct(P2VAR(MotActRL, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpMotRRAct_MotRRAct(P2VAR(MotActRR, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpPedlPos_PedlPos(P2VAR(PedlPos, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpPressure_Pressure(P2VAR(Pressure, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpSteerWhl_SteerWhl(P2VAR(SteerWhl, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpSuspHeight_SuspHeight(P2VAR(SuspHeight, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpVelFbAll_VlvFL(P2VAR(VlvActFL, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpVelFbAll_VlvFR(P2VAR(VlvActFR, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpVelFbAll_VlvRL(P2VAR(VlvActRL, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpVelFbAll_VlvRR(P2VAR(VlvActRR, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CtMDA_Control_Logic_PpWhlAccZ_WhlAcc(P2VAR(WhlAcc, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtMDA_Control_Logic_PpMotTgtOutFL_MotTgtOutFL(P2CONST(MotTgtOutFL, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtMDA_Control_Logic_PpMotTgtOutFR_MotTgtOutFR(P2CONST(MotTgtOutFR, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtMDA_Control_Logic_PpMotTgtOutRL_MotTgtOutRL(P2CONST(MotTgtOutRL, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtMDA_Control_Logic_PpMotTgtOutRR_MotTgtOutRR(P2CONST(MotTgtOutRR, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtMDA_Control_Logic_PpVlvTgtCCFF_VlvTgtCurrent(P2CONST(VlvTgtCurrent, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtMDA_Control_Logic_PpVlvTgtCCFF_VlvTgtFlutter(P2CONST(VlvTgtFlutter, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtMDA_Control_Logic_PpVlvTgtCCFF_VlvTgtFrequency(P2CONST(VlvTgtFrequency, AUTOMATIC, RTE_CTMDA_CONTROL_LOGIC_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_PpBodyAccZ_BodyAcc Rte_Read_CtMDA_Control_Logic_PpBodyAccZ_BodyAcc
#  define Rte_Read_PpIMU_IMUAcc Rte_Read_CtMDA_Control_Logic_PpIMU_IMUAcc
#  define Rte_Read_PpIMU_IMUAngle Rte_Read_CtMDA_Control_Logic_PpIMU_IMUAngle
#  define Rte_Read_PpIMU_IMURate Rte_Read_CtMDA_Control_Logic_PpIMU_IMURate
#  define Rte_Read_PpIMU_IMUVel Rte_Read_CtMDA_Control_Logic_PpIMU_IMUVel
#  define Rte_Read_PpMotFLAct_MotFLAct Rte_Read_CtMDA_Control_Logic_PpMotFLAct_MotFLAct
#  define Rte_Read_PpMotFRAct_MotFRAct Rte_Read_CtMDA_Control_Logic_PpMotFRAct_MotFRAct
#  define Rte_Read_PpMotRLAct_MotRLAct Rte_Read_CtMDA_Control_Logic_PpMotRLAct_MotRLAct
#  define Rte_Read_PpMotRRAct_MotRRAct Rte_Read_CtMDA_Control_Logic_PpMotRRAct_MotRRAct
#  define Rte_Read_PpPedlPos_PedlPos Rte_Read_CtMDA_Control_Logic_PpPedlPos_PedlPos
#  define Rte_Read_PpPressure_Pressure Rte_Read_CtMDA_Control_Logic_PpPressure_Pressure
#  define Rte_Read_PpSteerWhl_SteerWhl Rte_Read_CtMDA_Control_Logic_PpSteerWhl_SteerWhl
#  define Rte_Read_PpSuspHeight_SuspHeight Rte_Read_CtMDA_Control_Logic_PpSuspHeight_SuspHeight
#  define Rte_Read_PpVelFbAll_VlvFL Rte_Read_CtMDA_Control_Logic_PpVelFbAll_VlvFL
#  define Rte_Read_PpVelFbAll_VlvFR Rte_Read_CtMDA_Control_Logic_PpVelFbAll_VlvFR
#  define Rte_Read_PpVelFbAll_VlvRL Rte_Read_CtMDA_Control_Logic_PpVelFbAll_VlvRL
#  define Rte_Read_PpVelFbAll_VlvRR Rte_Read_CtMDA_Control_Logic_PpVelFbAll_VlvRR
#  define Rte_Read_PpWhlAccZ_WhlAcc Rte_Read_CtMDA_Control_Logic_PpWhlAccZ_WhlAcc


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_PpMotTgtOutFL_MotTgtOutFL Rte_Write_CtMDA_Control_Logic_PpMotTgtOutFL_MotTgtOutFL
#  define Rte_Write_PpMotTgtOutFR_MotTgtOutFR Rte_Write_CtMDA_Control_Logic_PpMotTgtOutFR_MotTgtOutFR
#  define Rte_Write_PpMotTgtOutRL_MotTgtOutRL Rte_Write_CtMDA_Control_Logic_PpMotTgtOutRL_MotTgtOutRL
#  define Rte_Write_PpMotTgtOutRR_MotTgtOutRR Rte_Write_CtMDA_Control_Logic_PpMotTgtOutRR_MotTgtOutRR
#  define Rte_Write_PpVlvTgtCCFF_VlvTgtChannel Rte_Write_CtMDA_Control_Logic_PpVlvTgtCCFF_VlvTgtChannel
#  define Rte_Write_CtMDA_Control_Logic_PpVlvTgtCCFF_VlvTgtChannel(data) (Rte_CtMDA_Control_Logic_PpVlvTgtCCFF_VlvTgtChannel = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_PpVlvTgtCCFF_VlvTgtCurrent Rte_Write_CtMDA_Control_Logic_PpVlvTgtCCFF_VlvTgtCurrent
#  define Rte_Write_PpVlvTgtCCFF_VlvTgtFlutter Rte_Write_CtMDA_Control_Logic_PpVlvTgtCCFF_VlvTgtFlutter
#  define Rte_Write_PpVlvTgtCCFF_VlvTgtFrequency Rte_Write_CtMDA_Control_Logic_PpVlvTgtCCFF_VlvTgtFrequency


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_CTPT2000_HANDLER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CTPT2000_HANDLER_APPL_CODE) PoPT2000_Ctrl_PT2000_Enable_mode(uint8 Ch_number, uint8 Mode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CTPT2000_HANDLER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_PoPT2000_Ctrl_PT2000_Enable_mode(arg1, arg2) (PoPT2000_Ctrl_PT2000_Enable_mode(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CTPT2000_HANDLER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CTPT2000_HANDLER_APPL_CODE) PoPT2000_Ctrl_PT2000_Init(uint8 init); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CTPT2000_HANDLER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_PoPT2000_Ctrl_PT2000_Init(arg1) (PoPT2000_Ctrl_PT2000_Init(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CTPT2000_HANDLER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CTPT2000_HANDLER_APPL_CODE) PoPT2000_Ctrl_PT2000_Mode_Change(uint8 Ch_number, uint8 Mode_Change); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CTPT2000_HANDLER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_PoPT2000_Ctrl_PT2000_Mode_Change(arg1, arg2) (PoPT2000_Ctrl_PT2000_Mode_Change(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CTPT2000_HANDLER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CTPT2000_HANDLER_APPL_CODE) PoPT2000_Ctrl_Set_ConstantCurrent(uint8 ChannelID, uint16 Current, uint16 Frequency, uint16 Flutter); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CTPT2000_HANDLER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_PoPT2000_Ctrl_Set_ConstantCurrent(arg1, arg2, arg3, arg4) (PoPT2000_Ctrl_Set_ConstantCurrent(arg1, arg2, arg3, arg4), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CTPT2000_HANDLER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_CTPT2000_HANDLER_APPL_CODE) PoPT2000_Ctrl_Set_Peak_Hold(uint8 ChannelID, uint16 IboostB, uint16 tbias_tot, uint16 tbias_off, uint16 ibias, uint16 iboostP, uint16 tpeak_tot, uint16 tpeak_off, uint16 ipeak, uint16 tbypass, uint16 thold_tot, uint16 thold_off, uint16 ihold, uint16 fwtimeOFF); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CTPT2000_HANDLER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_PoPT2000_Ctrl_Set_Peak_Hold(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14) (PoPT2000_Ctrl_Set_Peak_Hold(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define CtMDA_Control_Logic_START_SEC_CODE
# include "CtMDA_Control_Logic_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_MDA_Control_Logic MDA_Control_Logic
# endif

FUNC(void, CtMDA_Control_Logic_CODE) MDA_Control_Logic(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define CtMDA_Control_Logic_STOP_SEC_CODE
# include "CtMDA_Control_Logic_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CTMDA_CONTROL_LOGIC_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
