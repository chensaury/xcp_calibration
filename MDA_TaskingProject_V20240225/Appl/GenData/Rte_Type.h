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
 *          File:  Rte_Type.h
 *        Config:  Bsw_Project.dpa
 *   ECU-Project:  MDA
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  Header file containing user defined AUTOSAR types and RTE structures
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_TYPE_H
# define _RTE_TYPE_H

# include "Rte.h"


/**********************************************************************************************************************
 * Data type definitions
 *********************************************************************************************************************/

# define Rte_TypeDef_BodyAcc
typedef struct
{
  float32 BodyAccZFL;
  float32 BodyAccZFR;
  float32 BodyAccZRL;
  float32 BodyAccZRR;
} BodyAcc;

# define Rte_TypeDef_IMUAcc
typedef struct
{
  float32 IMUAccX;
  float32 IMUAccY;
  float32 IMUAccZ;
} IMUAcc;

# define Rte_TypeDef_IMUAngle
typedef struct
{
  float32 IMUPitchAngle;
  float32 IMURollAngle;
  float32 IMUYawAngle;
} IMUAngle;

# define Rte_TypeDef_IMURate
typedef struct
{
  float32 IMURollRate;
  float32 IMUPitchRate;
  float32 IMUYawRate;
} IMURate;

# define Rte_TypeDef_IMUVel
typedef struct
{
  float32 IMUVelNorth;
  float32 IMUVelEast;
  float32 IMUVelEarth;
} IMUVel;

# define Rte_TypeDef_MotActFL
typedef struct
{
  uint8 MotFLActSts;
  float32 MotFLActCurrent;
  float32 MotFLActVoltage;
  float32 MotFLActPos;
  float32 MotFLActTemp;
  float32 MotFLActSpd;
  float32 MotFLActTorq;
  uint8 MotFLDiagSts;
} MotActFL;

# define Rte_TypeDef_MotActFR
typedef struct
{
  uint8 MotFRActSts;
  float32 MotFRActCurrent;
  float32 MotFRActVoltage;
  float32 MotFRActPos;
  float32 MotFRActTemp;
  float32 MotFRActSpd;
  float32 MotFRActTorq;
  uint8 MotFRDiagSts;
} MotActFR;

# define Rte_TypeDef_MotActRL
typedef struct
{
  uint8 MotRLActSts;
  float32 MotRLActCurrent;
  float32 MotRLActVoltage;
  float32 MotRLActPos;
  float32 MotRLActTemp;
  float32 MotRLActSpd;
  float32 MotRLActTorq;
  uint8 MotRLDiagSts;
} MotActRL;

# define Rte_TypeDef_MotActRR
typedef struct
{
  uint8 MotRRActSts;
  float32 MotRRActCurrent;
  float32 MotRRActVoltage;
  float32 MotRRActPos;
  float32 MotRRActTemp;
  float32 MotRRActSpd;
  float32 MotRRActTorq;
  uint8 MotRRDiagSts;
} MotActRR;

# define Rte_TypeDef_MotTgtOutFL
typedef struct
{
  float32 MotTgtSpdFL;
  float32 MotTgtTorqFL;
  uint8 MotTgtModeFL;
  float32 MotTgtPosFL;
  uint8 Mot_Mode_PreSC_FL;
} MotTgtOutFL;

# define Rte_TypeDef_MotTgtOutFR
typedef struct
{
  float32 MotTgtSpdFR;
  float32 MotTgtTorqFR;
  uint8 MotTgtModeFR;
  float32 MotTgtPosFR;
  uint8 Mot_Mode_PreSC_FR;
} MotTgtOutFR;

# define Rte_TypeDef_MotTgtOutRL
typedef struct
{
  float32 MotTgtSpdRL;
  float32 MotTgtTorqRL;
  uint8 MotTgtModeRL;
  float32 MotTgtPosRL;
  uint8 Mot_Mode_PreSC_RL;
} MotTgtOutRL;

# define Rte_TypeDef_MotTgtOutRR
typedef struct
{
  float32 MotTgtSpdRR;
  float32 MotTgtTorqRR;
  uint8 MotTgtModeRR;
  float32 MotTgtPosRR;
  uint8 Mot_Mode_PreSC_RR;
} MotTgtOutRR;

# define Rte_TypeDef_PedlPos
typedef struct
{
  float32 AccPedlPos;
  float32 BrkPedlPos;
} PedlPos;

# define Rte_TypeDef_Pressure
typedef struct
{
  float32 PressureFL1;
  float32 PressureFL2;
  float32 PressureFR1;
  float32 PressureFR2;
  float32 PressureRL1;
  float32 PressureRL2;
  float32 PressureRR1;
  float32 PressureRR2;
} Pressure;

# define Rte_TypeDef_SteerWhl
typedef struct
{
  float32 SteerWhlAngle;
  float32 SteerWhlAngleRate;
  float32 SteerWhlHandTrq;
} SteerWhl;

# define Rte_TypeDef_SuspHeight
typedef struct
{
  float32 SuspHeightFL;
  float32 SuspHeightFR;
  float32 SuspHeightRL;
  float32 SuspHeightRR;
} SuspHeight;

# define Rte_TypeDef_VlvActFL
typedef struct
{
  uint8 VlvFLSts1;
  uint8 VlvFLSts2;
  uint8 VlvFLDiagSts1;
  uint8 VlvFLDiagSts2;
} VlvActFL;

# define Rte_TypeDef_VlvActFR
typedef struct
{
  uint8 VlvFRSts1;
  uint8 VlvFRSts2;
  uint8 VlvFRDiagSts1;
  uint8 VlvFRDiagSts2;
} VlvActFR;

# define Rte_TypeDef_VlvActRL
typedef struct
{
  uint8 VlvRLSts1;
  uint8 VlvRLSts2;
  uint8 VlvRLDiagSts1;
  uint8 VlvRLDiagSts2;
} VlvActRL;

# define Rte_TypeDef_VlvActRR
typedef struct
{
  uint8 VlvRRSts1;
  uint8 VlvRRSts2;
  uint8 VlvRRDiagSts1;
  uint8 VlvRRDiagSts2;
} VlvActRR;

# define Rte_TypeDef_VlvTgtCurrent
typedef struct
{
  uint16 VlvTgtCurrentFL1;
  uint16 VlvTgtCurrentFL2;
  uint16 VlvTgtCurrentFR1;
  uint16 VlvTgtCurrentFR2;
  uint16 VlvTgtCurrentRL1;
  uint16 VlvTgtCurrentRL2;
  uint16 VlvTgtCurrentRR1;
  uint16 VlvTgtCurrentRR2;
} VlvTgtCurrent;

# define Rte_TypeDef_VlvTgtFlutter
typedef struct
{
  uint16 VlvTgtFlutterFL1;
  uint16 VlvTgtFlutterFL2;
  uint16 VlvTgtFlutterFR1;
  uint16 VlvTgtFlutterFR2;
  uint16 VlvTgtFlutterRL1;
  uint16 VlvTgtFlutterRL2;
  uint16 VlvTgtFlutterRR1;
  uint16 VlvTgtFlutterRR2;
} VlvTgtFlutter;

# define Rte_TypeDef_VlvTgtFrequency
typedef struct
{
  uint16 VlvTgtFrequencyFL1;
  uint16 VlvTgtFrequencyFL2;
  uint16 VlvTgtFrequencyFR1;
  uint16 VlvTgtFrequencyFR2;
  uint16 VlvTgtFrequencyRL1;
  uint16 VlvTgtFrequencyRL2;
  uint16 VlvTgtFrequencyRR1;
  uint16 VlvTgtFrequencyRR2;
} VlvTgtFrequency;

# define Rte_TypeDef_WhlAcc
typedef struct
{
  float32 WhlAccZFL;
  float32 WhlAccZFR;
  float32 WhlAccZRL;
  float32 WhlAccZRR;
} WhlAcc;

# define Rte_TypeDef_BswM_ESH_Mode
typedef uint8 BswM_ESH_Mode;

# define Rte_TypeDef_BswM_ESH_RunRequest
typedef uint8 BswM_ESH_RunRequest;

# define Rte_TypeDef_ComM_InhibitionStatusType
typedef uint8 ComM_InhibitionStatusType;

# define Rte_TypeDef_ComM_ModeType
typedef uint8 ComM_ModeType;

# define Rte_TypeDef_ComM_UserHandleType
typedef uint8 ComM_UserHandleType;

# define Rte_TypeDef_EcuM_BootTargetType
typedef uint8 EcuM_BootTargetType;

# define Rte_TypeDef_EcuM_ModeType
typedef uint8 EcuM_ModeType;

# define Rte_TypeDef_EcuM_ShutdownCauseType
typedef uint8 EcuM_ShutdownCauseType;

# define Rte_TypeDef_EcuM_StateType
typedef uint8 EcuM_StateType;

# define Rte_TypeDef_EcuM_TimeType
typedef uint32 EcuM_TimeType;

# define Rte_TypeDef_EcuM_UserType
typedef uint8 EcuM_UserType;

# define Rte_TypeDef_TimeInMicrosecondsType
typedef uint32 TimeInMicrosecondsType;


# ifndef RTE_SUPPRESS_UNUSED_DATATYPES
/**********************************************************************************************************************
 * Unused Data type definitions
 *********************************************************************************************************************/

#  define Rte_TypeDef_dtRef_VOID
typedef void * dtRef_VOID;

#  define Rte_TypeDef_dtRef_const_VOID
typedef const void * dtRef_const_VOID;

#  define Rte_TypeDef_Dem_UdsStatusByteType
typedef uint8 Dem_UdsStatusByteType;

#  define Rte_TypeDef_NvM_RequestResultType
typedef uint8 NvM_RequestResultType;

#  define Rte_TypeDef_NvM_ServiceIdType
typedef uint8 NvM_ServiceIdType;

# endif


/**********************************************************************************************************************
 * Constant value definitions
 *********************************************************************************************************************/

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONST(BodyAcc, RTE_CONST) Rte_C_BodyAcc_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(IMUAcc, RTE_CONST) Rte_C_IMUAcc_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(IMUAngle, RTE_CONST) Rte_C_IMUAngle_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(IMURate, RTE_CONST) Rte_C_IMURate_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(IMUVel, RTE_CONST) Rte_C_IMUVel_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(MotActFL, RTE_CONST) Rte_C_MotActFL_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(MotActFR, RTE_CONST) Rte_C_MotActFR_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(MotActRL, RTE_CONST) Rte_C_MotActRL_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(MotActRR, RTE_CONST) Rte_C_MotActRR_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(MotTgtOutFL, RTE_CONST) Rte_C_MotTgtOutFL_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(MotTgtOutFR, RTE_CONST) Rte_C_MotTgtOutFR_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(MotTgtOutRL, RTE_CONST) Rte_C_MotTgtOutRL_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(MotTgtOutRR, RTE_CONST) Rte_C_MotTgtOutRR_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(PedlPos, RTE_CONST) Rte_C_PedlPos_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Pressure, RTE_CONST) Rte_C_Pressure_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SteerWhl, RTE_CONST) Rte_C_SteerWhl_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SuspHeight, RTE_CONST) Rte_C_SuspHeight_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(VlvActFL, RTE_CONST) Rte_C_VlvActFL_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(VlvActFR, RTE_CONST) Rte_C_VlvActFR_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(VlvActRL, RTE_CONST) Rte_C_VlvActRL_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(VlvActRR, RTE_CONST) Rte_C_VlvActRR_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(VlvTgtCurrent, RTE_CONST) Rte_C_VlvTgtCurrent_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(VlvTgtFlutter, RTE_CONST) Rte_C_VlvTgtFlutter_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(VlvTgtFrequency, RTE_CONST) Rte_C_VlvTgtFrequency_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(WhlAcc, RTE_CONST) Rte_C_WhlAcc_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
# include "Rte_DataHandleType.h"

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef unsigned int Rte_BitType;
/**********************************************************************************************************************
 * type and extern declarations of RTE internal variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte Init State Variable
 *********************************************************************************************************************/

# define RTE_STATE_UNINIT    (0U)
# define RTE_STATE_SCHM_INIT (1U)
# define RTE_STATE_INIT      (2U)

# define RTE_START_SEC_VAR_ZERO_INIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern volatile VAR(uint8, RTE_VAR_ZERO_INIT) Rte_InitState; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */

# define RTE_STOP_SEC_VAR_ZERO_INIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# define RTE_START_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern volatile VAR(uint8, RTE_VAR_ZERO_INIT_NOCACHE) Rte_InitState_1; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */

# define RTE_STOP_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# define RTE_START_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern volatile VAR(uint8, RTE_VAR_ZERO_INIT_NOCACHE) Rte_InitState_2; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */

# define RTE_STOP_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# define RTE_START_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern volatile VAR(uint8, RTE_VAR_ZERO_INIT_NOCACHE) Rte_InitState_3; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */

# define RTE_STOP_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# define RTE_START_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern volatile VAR(uint8, RTE_VAR_ZERO_INIT_NOCACHE) Rte_InitState_4; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */

# define RTE_STOP_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# define RTE_START_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern volatile VAR(uint8, RTE_VAR_ZERO_INIT_NOCACHE) Rte_InitState_5; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */

# define RTE_STOP_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef RTE_CORE

/**********************************************************************************************************************
 * Buffers for unqueued S/R
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(IMUAcc, RTE_VAR_INIT) Rte_CtIoHardWare_PpIMU_IMUAcc; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(IMUAngle, RTE_VAR_INIT) Rte_CtIoHardWare_PpIMU_IMUAngle; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(IMURate, RTE_VAR_INIT) Rte_CtIoHardWare_PpIMU_IMURate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(IMUVel, RTE_VAR_INIT) Rte_CtIoHardWare_PpIMU_IMUVel; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(PedlPos, RTE_VAR_INIT) Rte_CtIoHardWare_PpPedlPos_PedlPos; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Pressure, RTE_VAR_INIT) Rte_CtIoHardWare_PpPressure_Pressure; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SteerWhl, RTE_VAR_INIT) Rte_CtIoHardWare_PpSteerWhl_SteerWhl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SuspHeight, RTE_VAR_INIT) Rte_CtIoHardWare_PpSuspHeight_SuspHeight; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(uint8, RTE_VAR_INIT) Rte_CtMDA_Control_Logic_PpVlvTgtCCFF_VlvTgtChannel; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(VlvTgtCurrent, RTE_VAR_INIT) Rte_CtMDA_Control_Logic_PpVlvTgtCCFF_VlvTgtCurrent; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(VlvTgtFlutter, RTE_VAR_INIT) Rte_CtMDA_Control_Logic_PpVlvTgtCCFF_VlvTgtFlutter; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(VlvTgtFrequency, RTE_VAR_INIT) Rte_CtMDA_Control_Logic_PpVlvTgtCCFF_VlvTgtFrequency; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(BodyAcc, RTE_VAR_INIT) Rte_CtPSI5_Handler_PpBodyAccZ_BodyAcc; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(WhlAcc, RTE_VAR_INIT) Rte_CtPSI5_Handler_PpWhlAccZ_WhlAcc; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(VlvActFL, RTE_VAR_INIT) Rte_CtPT2000_Handler_PpVelFbAll_VlvFL; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(VlvActFR, RTE_VAR_INIT) Rte_CtPT2000_Handler_PpVelFbAll_VlvFR; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(VlvActRL, RTE_VAR_INIT) Rte_CtPT2000_Handler_PpVelFbAll_VlvRL; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(VlvActRR, RTE_VAR_INIT) Rte_CtPT2000_Handler_PpVelFbAll_VlvRR; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(MotTgtOutFL, RTE_VAR_INIT_NOCACHE) Rte_CtMDA_Control_Logic_PpMotTgtOutFL_MotTgtOutFL; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(MotTgtOutFR, RTE_VAR_INIT_NOCACHE) Rte_CtMDA_Control_Logic_PpMotTgtOutFR_MotTgtOutFR; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(MotTgtOutRL, RTE_VAR_INIT_NOCACHE) Rte_CtMDA_Control_Logic_PpMotTgtOutRL_MotTgtOutRL; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(MotTgtOutRR, RTE_VAR_INIT_NOCACHE) Rte_CtMDA_Control_Logic_PpMotTgtOutRR_MotTgtOutRR; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#  define RTE_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_SystemApplication_OsCore1_NOCACHE_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(MotActFL, RTE_VAR_INIT_NOCACHE) Rte_CtMotor_FL_PpMotFLAct_MotFLAct; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#  define RTE_STOP_SEC_VAR_SystemApplication_OsCore1_NOCACHE_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_SystemApplication_OsCore2_NOCACHE_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(MotActFR, RTE_VAR_INIT_NOCACHE) Rte_CtMotor_FR_PpMotFRAct_MotFRAct; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#  define RTE_STOP_SEC_VAR_SystemApplication_OsCore2_NOCACHE_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_SystemApplication_OsCore3_NOCACHE_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(MotActRL, RTE_VAR_INIT_NOCACHE) Rte_CtMotor_RL_PpMotRLAct_MotRLAct; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#  define RTE_STOP_SEC_VAR_SystemApplication_OsCore3_NOCACHE_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_SystemApplication_OsCore4_NOCACHE_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(MotActRR, RTE_VAR_INIT_NOCACHE) Rte_CtMotor_RR_PpMotRRAct_MotRRAct; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#  define RTE_STOP_SEC_VAR_SystemApplication_OsCore4_NOCACHE_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef struct
{
  Rte_BitType Rte_ModeSwitchAck_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode_Ack : 1;
} Rte_SystemApplication_OsCore0_AckFlagsType;

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Rte_SystemApplication_OsCore0_AckFlagsType, RTE_VAR_INIT) Rte_SystemApplication_OsCore0_AckFlags; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Data structures for mode management
 *********************************************************************************************************************/


#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(BswM_ESH_Mode, RTE_VAR_INIT) Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode; /* PRQA S 3408 */ /* MD_Rte_3408 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# endif /* defined(RTE_CORE) */

#endif /* _RTE_TYPE_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3408:  MISRA rule: 8.8
     Reason:     For the purpose of monitoring during calibration or debugging it is necessary to use non-static declarations.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       No functional risk.
     Prevention: Not required.

*/
