/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Os
 *           Program: MSR_Vector_SLP4
 *          Customer: Aptiv (China) Technology Company Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Aurix 2G/TC397 B-Step
 *    License Scope : The usage is restricted to CBD1900078_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_XSignal_Lcfg.c
 *   Generation Time: 2024-01-08 16:27:33
 *           Project: Bsw_Project - Version 1.0
 *          Delivery: CBD1900078_D01
 *      Tool Version: DaVinci Configurator (beta) 5.18.42 SP2
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Pro and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_XSIGNAL_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_XSignal_Lcfg.h"
#include "Os_XSignal.h"

/* Os kernel module dependencies */
#include "Os_Common.h"
#include "Os_Isr_Lcfg.h"
#include "Os_Lcfg.h"

/* Os hal dependencies */


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! X-Signal send port configuration data: OsCore0 -> OsCore4/XSignalIsr_OsCore4_Recv0 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore0_Send0;

/*! X-Signal send port configuration data: OsCore0 -> OsCore3/XSignalIsr_OsCore3_Recv0 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore0_Send1;

/*! X-Signal send port configuration data: OsCore0 -> OsCore2/XSignalIsr_OsCore2_Recv0 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore0_Send2;

/*! X-Signal send port configuration data: OsCore0 -> OsCore1/XSignalIsr_OsCore1_Recv0 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore0_Send3;

/*! X-Signal send port configuration data: OsCore0 -> OsCore5/XSignalIsr_OsCore5_Recv0 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore0_Send4;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore0_Recv0 <- OsCore1 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore0_Recv0;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore0_Recv1 <- OsCore2 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore0_Recv1;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore0_Recv2 <- OsCore3 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore0_Recv2;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore0_Recv3 <- OsCore4 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore0_Recv3;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore0_Recv4 <- OsCore5 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore0_Recv4;

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! X-Signal send port configuration data: OsCore1 -> OsCore4/XSignalIsr_OsCore4_Recv1 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore1_Send0;

/*! X-Signal send port configuration data: OsCore1 -> OsCore3/XSignalIsr_OsCore3_Recv1 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore1_Send1;

/*! X-Signal send port configuration data: OsCore1 -> OsCore2/XSignalIsr_OsCore2_Recv1 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore1_Send2;

/*! X-Signal send port configuration data: OsCore1 -> OsCore0/XSignalIsr_OsCore0_Recv0 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore1_Send3;

/*! X-Signal send port configuration data: OsCore1 -> OsCore5/XSignalIsr_OsCore5_Recv1 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore1_Send4;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore1_Recv0 <- OsCore0 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore1_Recv0;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore1_Recv1 <- OsCore2 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore1_Recv1;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore1_Recv2 <- OsCore3 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore1_Recv2;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore1_Recv3 <- OsCore4 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore1_Recv3;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore1_Recv4 <- OsCore5 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore1_Recv4;

#define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! X-Signal send port configuration data: OsCore2 -> OsCore4/XSignalIsr_OsCore4_Recv2 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore2_Send0;

/*! X-Signal send port configuration data: OsCore2 -> OsCore3/XSignalIsr_OsCore3_Recv2 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore2_Send1;

/*! X-Signal send port configuration data: OsCore2 -> OsCore1/XSignalIsr_OsCore1_Recv1 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore2_Send2;

/*! X-Signal send port configuration data: OsCore2 -> OsCore0/XSignalIsr_OsCore0_Recv1 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore2_Send3;

/*! X-Signal send port configuration data: OsCore2 -> OsCore5/XSignalIsr_OsCore5_Recv2 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore2_Send4;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore2_Recv0 <- OsCore0 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore2_Recv0;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore2_Recv1 <- OsCore1 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore2_Recv1;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore2_Recv2 <- OsCore3 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore2_Recv2;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore2_Recv3 <- OsCore4 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore2_Recv3;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore2_Recv4 <- OsCore5 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore2_Recv4;

#define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE3_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! X-Signal send port configuration data: OsCore3 -> OsCore4/XSignalIsr_OsCore4_Recv3 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore3_Send0;

/*! X-Signal send port configuration data: OsCore3 -> OsCore2/XSignalIsr_OsCore2_Recv2 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore3_Send1;

/*! X-Signal send port configuration data: OsCore3 -> OsCore1/XSignalIsr_OsCore1_Recv2 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore3_Send2;

/*! X-Signal send port configuration data: OsCore3 -> OsCore0/XSignalIsr_OsCore0_Recv2 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore3_Send3;

/*! X-Signal send port configuration data: OsCore3 -> OsCore5/XSignalIsr_OsCore5_Recv3 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore3_Send4;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore3_Recv0 <- OsCore0 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore3_Recv0;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore3_Recv1 <- OsCore1 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore3_Recv1;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore3_Recv2 <- OsCore2 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore3_Recv2;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore3_Recv3 <- OsCore4 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore3_Recv3;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore3_Recv4 <- OsCore5 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore3_Recv4;

#define OS_STOP_SEC_CORE3_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE4_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! X-Signal send port configuration data: OsCore4 -> OsCore3/XSignalIsr_OsCore3_Recv3 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore4_Send0;

/*! X-Signal send port configuration data: OsCore4 -> OsCore2/XSignalIsr_OsCore2_Recv3 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore4_Send1;

/*! X-Signal send port configuration data: OsCore4 -> OsCore1/XSignalIsr_OsCore1_Recv3 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore4_Send2;

/*! X-Signal send port configuration data: OsCore4 -> OsCore0/XSignalIsr_OsCore0_Recv3 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore4_Send3;

/*! X-Signal send port configuration data: OsCore4 -> OsCore5/XSignalIsr_OsCore5_Recv4 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore4_Send4;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore4_Recv0 <- OsCore0 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore4_Recv0;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore4_Recv1 <- OsCore1 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore4_Recv1;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore4_Recv2 <- OsCore2 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore4_Recv2;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore4_Recv3 <- OsCore3 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore4_Recv3;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore4_Recv4 <- OsCore5 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore4_Recv4;

#define OS_STOP_SEC_CORE4_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE5_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! X-Signal send port configuration data: OsCore5 -> OsCore4/XSignalIsr_OsCore4_Recv4 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore5_Send0;

/*! X-Signal send port configuration data: OsCore5 -> OsCore3/XSignalIsr_OsCore3_Recv4 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore5_Send1;

/*! X-Signal send port configuration data: OsCore5 -> OsCore2/XSignalIsr_OsCore2_Recv4 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore5_Send2;

/*! X-Signal send port configuration data: OsCore5 -> OsCore1/XSignalIsr_OsCore1_Recv4 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore5_Send3;

/*! X-Signal send port configuration data: OsCore5 -> OsCore0/XSignalIsr_OsCore0_Recv4 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore5_Send4;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore5_Recv0 <- OsCore0 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore5_Recv0;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore5_Recv1 <- OsCore1 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore5_Recv1;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore5_Recv2 <- OsCore2 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore5_Recv2;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore5_Recv3 <- OsCore3 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore5_Recv3;

/*! X-Signal receive port configuration data: XSignalIsr_OsCore5_Recv4 <- OsCore4 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore5_Recv4;

#define OS_STOP_SEC_CORE5_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Dynamic X-Signal send port data: OsCore0 -> OsCore4/XSignalIsr_OsCore4_Recv0 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore0_Send0_XSignalIsr_OsCore4_Recv0_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore0_Send0_Data[OS_CFG_SIZE_OSCORE0_SEND0_XSIGNALISR_OSCORE4_RECV0_BUFFER];

/* Dynamic X-Signal send port data: OsCore0 -> OsCore3/XSignalIsr_OsCore3_Recv0 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore0_Send1_XSignalIsr_OsCore3_Recv0_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore0_Send1_Data[OS_CFG_SIZE_OSCORE0_SEND1_XSIGNALISR_OSCORE3_RECV0_BUFFER];

/* Dynamic X-Signal send port data: OsCore0 -> OsCore2/XSignalIsr_OsCore2_Recv0 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore0_Send2_XSignalIsr_OsCore2_Recv0_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore0_Send2_Data[OS_CFG_SIZE_OSCORE0_SEND2_XSIGNALISR_OSCORE2_RECV0_BUFFER];

/* Dynamic X-Signal send port data: OsCore0 -> OsCore1/XSignalIsr_OsCore1_Recv0 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore0_Send3_XSignalIsr_OsCore1_Recv0_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore0_Send3_Data[OS_CFG_SIZE_OSCORE0_SEND3_XSIGNALISR_OSCORE1_RECV0_BUFFER];

/* Dynamic X-Signal send port data: OsCore0 -> OsCore5/XSignalIsr_OsCore5_Recv0 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore0_Send4_XSignalIsr_OsCore5_Recv0_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore0_Send4_Data[OS_CFG_SIZE_OSCORE0_SEND4_XSIGNALISR_OSCORE5_RECV0_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore0_Recv0 <- OsCore1 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore1_Send3_XSignalIsr_OsCore0_Recv0_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore0_Recv0_Data[OS_CFG_SIZE_OSCORE1_SEND3_XSIGNALISR_OSCORE0_RECV0_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore0_Recv1 <- OsCore2 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore2_Send3_XSignalIsr_OsCore0_Recv1_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore0_Recv1_Data[OS_CFG_SIZE_OSCORE2_SEND3_XSIGNALISR_OSCORE0_RECV1_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore0_Recv2 <- OsCore3 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore3_Send3_XSignalIsr_OsCore0_Recv2_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore0_Recv2_Data[OS_CFG_SIZE_OSCORE3_SEND3_XSIGNALISR_OSCORE0_RECV2_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore0_Recv3 <- OsCore4 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore4_Send3_XSignalIsr_OsCore0_Recv3_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore0_Recv3_Data[OS_CFG_SIZE_OSCORE4_SEND3_XSIGNALISR_OSCORE0_RECV3_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore0_Recv4 <- OsCore5 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore5_Send4_XSignalIsr_OsCore0_Recv4_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore0_Recv4_Data[OS_CFG_SIZE_OSCORE5_SEND4_XSIGNALISR_OSCORE0_RECV4_BUFFER];

#define OS_STOP_SEC_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE1_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Dynamic X-Signal send port data: OsCore1 -> OsCore4/XSignalIsr_OsCore4_Recv1 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore1_Send0_XSignalIsr_OsCore4_Recv1_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore1_Send0_Data[OS_CFG_SIZE_OSCORE1_SEND0_XSIGNALISR_OSCORE4_RECV1_BUFFER];

/* Dynamic X-Signal send port data: OsCore1 -> OsCore3/XSignalIsr_OsCore3_Recv1 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore1_Send1_XSignalIsr_OsCore3_Recv1_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore1_Send1_Data[OS_CFG_SIZE_OSCORE1_SEND1_XSIGNALISR_OSCORE3_RECV1_BUFFER];

/* Dynamic X-Signal send port data: OsCore1 -> OsCore2/XSignalIsr_OsCore2_Recv1 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore1_Send2_XSignalIsr_OsCore2_Recv1_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore1_Send2_Data[OS_CFG_SIZE_OSCORE1_SEND2_XSIGNALISR_OSCORE2_RECV1_BUFFER];

/* Dynamic X-Signal send port data: OsCore1 -> OsCore0/XSignalIsr_OsCore0_Recv0 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore1_Send3_XSignalIsr_OsCore0_Recv0_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore1_Send3_Data[OS_CFG_SIZE_OSCORE1_SEND3_XSIGNALISR_OSCORE0_RECV0_BUFFER];

/* Dynamic X-Signal send port data: OsCore1 -> OsCore5/XSignalIsr_OsCore5_Recv1 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore1_Send4_XSignalIsr_OsCore5_Recv1_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore1_Send4_Data[OS_CFG_SIZE_OSCORE1_SEND4_XSIGNALISR_OSCORE5_RECV1_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore1_Recv0 <- OsCore0 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore0_Send3_XSignalIsr_OsCore1_Recv0_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore1_Recv0_Data[OS_CFG_SIZE_OSCORE0_SEND3_XSIGNALISR_OSCORE1_RECV0_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore1_Recv1 <- OsCore2 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore2_Send2_XSignalIsr_OsCore1_Recv1_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore1_Recv1_Data[OS_CFG_SIZE_OSCORE2_SEND2_XSIGNALISR_OSCORE1_RECV1_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore1_Recv2 <- OsCore3 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore3_Send2_XSignalIsr_OsCore1_Recv2_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore1_Recv2_Data[OS_CFG_SIZE_OSCORE3_SEND2_XSIGNALISR_OSCORE1_RECV2_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore1_Recv3 <- OsCore4 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore4_Send2_XSignalIsr_OsCore1_Recv3_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore1_Recv3_Data[OS_CFG_SIZE_OSCORE4_SEND2_XSIGNALISR_OSCORE1_RECV3_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore1_Recv4 <- OsCore5 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore5_Send3_XSignalIsr_OsCore1_Recv4_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore1_Recv4_Data[OS_CFG_SIZE_OSCORE5_SEND3_XSIGNALISR_OSCORE1_RECV4_BUFFER];

#define OS_STOP_SEC_CORE1_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE2_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Dynamic X-Signal send port data: OsCore2 -> OsCore4/XSignalIsr_OsCore4_Recv2 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore2_Send0_XSignalIsr_OsCore4_Recv2_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore2_Send0_Data[OS_CFG_SIZE_OSCORE2_SEND0_XSIGNALISR_OSCORE4_RECV2_BUFFER];

/* Dynamic X-Signal send port data: OsCore2 -> OsCore3/XSignalIsr_OsCore3_Recv2 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore2_Send1_XSignalIsr_OsCore3_Recv2_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore2_Send1_Data[OS_CFG_SIZE_OSCORE2_SEND1_XSIGNALISR_OSCORE3_RECV2_BUFFER];

/* Dynamic X-Signal send port data: OsCore2 -> OsCore1/XSignalIsr_OsCore1_Recv1 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore2_Send2_XSignalIsr_OsCore1_Recv1_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore2_Send2_Data[OS_CFG_SIZE_OSCORE2_SEND2_XSIGNALISR_OSCORE1_RECV1_BUFFER];

/* Dynamic X-Signal send port data: OsCore2 -> OsCore0/XSignalIsr_OsCore0_Recv1 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore2_Send3_XSignalIsr_OsCore0_Recv1_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore2_Send3_Data[OS_CFG_SIZE_OSCORE2_SEND3_XSIGNALISR_OSCORE0_RECV1_BUFFER];

/* Dynamic X-Signal send port data: OsCore2 -> OsCore5/XSignalIsr_OsCore5_Recv2 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore2_Send4_XSignalIsr_OsCore5_Recv2_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore2_Send4_Data[OS_CFG_SIZE_OSCORE2_SEND4_XSIGNALISR_OSCORE5_RECV2_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore2_Recv0 <- OsCore0 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore0_Send2_XSignalIsr_OsCore2_Recv0_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore2_Recv0_Data[OS_CFG_SIZE_OSCORE0_SEND2_XSIGNALISR_OSCORE2_RECV0_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore2_Recv1 <- OsCore1 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore1_Send2_XSignalIsr_OsCore2_Recv1_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore2_Recv1_Data[OS_CFG_SIZE_OSCORE1_SEND2_XSIGNALISR_OSCORE2_RECV1_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore2_Recv2 <- OsCore3 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore3_Send1_XSignalIsr_OsCore2_Recv2_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore2_Recv2_Data[OS_CFG_SIZE_OSCORE3_SEND1_XSIGNALISR_OSCORE2_RECV2_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore2_Recv3 <- OsCore4 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore4_Send1_XSignalIsr_OsCore2_Recv3_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore2_Recv3_Data[OS_CFG_SIZE_OSCORE4_SEND1_XSIGNALISR_OSCORE2_RECV3_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore2_Recv4 <- OsCore5 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore5_Send2_XSignalIsr_OsCore2_Recv4_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore2_Recv4_Data[OS_CFG_SIZE_OSCORE5_SEND2_XSIGNALISR_OSCORE2_RECV4_BUFFER];

#define OS_STOP_SEC_CORE2_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE3_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Dynamic X-Signal send port data: OsCore3 -> OsCore4/XSignalIsr_OsCore4_Recv3 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore3_Send0_XSignalIsr_OsCore4_Recv3_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore3_Send0_Data[OS_CFG_SIZE_OSCORE3_SEND0_XSIGNALISR_OSCORE4_RECV3_BUFFER];

/* Dynamic X-Signal send port data: OsCore3 -> OsCore2/XSignalIsr_OsCore2_Recv2 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore3_Send1_XSignalIsr_OsCore2_Recv2_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore3_Send1_Data[OS_CFG_SIZE_OSCORE3_SEND1_XSIGNALISR_OSCORE2_RECV2_BUFFER];

/* Dynamic X-Signal send port data: OsCore3 -> OsCore1/XSignalIsr_OsCore1_Recv2 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore3_Send2_XSignalIsr_OsCore1_Recv2_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore3_Send2_Data[OS_CFG_SIZE_OSCORE3_SEND2_XSIGNALISR_OSCORE1_RECV2_BUFFER];

/* Dynamic X-Signal send port data: OsCore3 -> OsCore0/XSignalIsr_OsCore0_Recv2 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore3_Send3_XSignalIsr_OsCore0_Recv2_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore3_Send3_Data[OS_CFG_SIZE_OSCORE3_SEND3_XSIGNALISR_OSCORE0_RECV2_BUFFER];

/* Dynamic X-Signal send port data: OsCore3 -> OsCore5/XSignalIsr_OsCore5_Recv3 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore3_Send4_XSignalIsr_OsCore5_Recv3_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore3_Send4_Data[OS_CFG_SIZE_OSCORE3_SEND4_XSIGNALISR_OSCORE5_RECV3_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore3_Recv0 <- OsCore0 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore0_Send1_XSignalIsr_OsCore3_Recv0_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore3_Recv0_Data[OS_CFG_SIZE_OSCORE0_SEND1_XSIGNALISR_OSCORE3_RECV0_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore3_Recv1 <- OsCore1 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore1_Send1_XSignalIsr_OsCore3_Recv1_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore3_Recv1_Data[OS_CFG_SIZE_OSCORE1_SEND1_XSIGNALISR_OSCORE3_RECV1_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore3_Recv2 <- OsCore2 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore2_Send1_XSignalIsr_OsCore3_Recv2_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore3_Recv2_Data[OS_CFG_SIZE_OSCORE2_SEND1_XSIGNALISR_OSCORE3_RECV2_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore3_Recv3 <- OsCore4 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore4_Send0_XSignalIsr_OsCore3_Recv3_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore3_Recv3_Data[OS_CFG_SIZE_OSCORE4_SEND0_XSIGNALISR_OSCORE3_RECV3_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore3_Recv4 <- OsCore5 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore5_Send1_XSignalIsr_OsCore3_Recv4_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore3_Recv4_Data[OS_CFG_SIZE_OSCORE5_SEND1_XSIGNALISR_OSCORE3_RECV4_BUFFER];

#define OS_STOP_SEC_CORE3_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE4_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Dynamic X-Signal send port data: OsCore4 -> OsCore3/XSignalIsr_OsCore3_Recv3 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore4_Send0_XSignalIsr_OsCore3_Recv3_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore4_Send0_Data[OS_CFG_SIZE_OSCORE4_SEND0_XSIGNALISR_OSCORE3_RECV3_BUFFER];

/* Dynamic X-Signal send port data: OsCore4 -> OsCore2/XSignalIsr_OsCore2_Recv3 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore4_Send1_XSignalIsr_OsCore2_Recv3_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore4_Send1_Data[OS_CFG_SIZE_OSCORE4_SEND1_XSIGNALISR_OSCORE2_RECV3_BUFFER];

/* Dynamic X-Signal send port data: OsCore4 -> OsCore1/XSignalIsr_OsCore1_Recv3 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore4_Send2_XSignalIsr_OsCore1_Recv3_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore4_Send2_Data[OS_CFG_SIZE_OSCORE4_SEND2_XSIGNALISR_OSCORE1_RECV3_BUFFER];

/* Dynamic X-Signal send port data: OsCore4 -> OsCore0/XSignalIsr_OsCore0_Recv3 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore4_Send3_XSignalIsr_OsCore0_Recv3_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore4_Send3_Data[OS_CFG_SIZE_OSCORE4_SEND3_XSIGNALISR_OSCORE0_RECV3_BUFFER];

/* Dynamic X-Signal send port data: OsCore4 -> OsCore5/XSignalIsr_OsCore5_Recv4 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore4_Send4_XSignalIsr_OsCore5_Recv4_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore4_Send4_Data[OS_CFG_SIZE_OSCORE4_SEND4_XSIGNALISR_OSCORE5_RECV4_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore4_Recv0 <- OsCore0 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore0_Send0_XSignalIsr_OsCore4_Recv0_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore4_Recv0_Data[OS_CFG_SIZE_OSCORE0_SEND0_XSIGNALISR_OSCORE4_RECV0_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore4_Recv1 <- OsCore1 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore1_Send0_XSignalIsr_OsCore4_Recv1_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore4_Recv1_Data[OS_CFG_SIZE_OSCORE1_SEND0_XSIGNALISR_OSCORE4_RECV1_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore4_Recv2 <- OsCore2 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore2_Send0_XSignalIsr_OsCore4_Recv2_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore4_Recv2_Data[OS_CFG_SIZE_OSCORE2_SEND0_XSIGNALISR_OSCORE4_RECV2_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore4_Recv3 <- OsCore3 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore3_Send0_XSignalIsr_OsCore4_Recv3_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore4_Recv3_Data[OS_CFG_SIZE_OSCORE3_SEND0_XSIGNALISR_OSCORE4_RECV3_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore4_Recv4 <- OsCore5 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore5_Send0_XSignalIsr_OsCore4_Recv4_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore4_Recv4_Data[OS_CFG_SIZE_OSCORE5_SEND0_XSIGNALISR_OSCORE4_RECV4_BUFFER];

#define OS_STOP_SEC_CORE4_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE5_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Dynamic X-Signal send port data: OsCore5 -> OsCore4/XSignalIsr_OsCore4_Recv4 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore5_Send0_XSignalIsr_OsCore4_Recv4_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore5_Send0_Data[OS_CFG_SIZE_OSCORE5_SEND0_XSIGNALISR_OSCORE4_RECV4_BUFFER];

/* Dynamic X-Signal send port data: OsCore5 -> OsCore3/XSignalIsr_OsCore3_Recv4 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore5_Send1_XSignalIsr_OsCore3_Recv4_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore5_Send1_Data[OS_CFG_SIZE_OSCORE5_SEND1_XSIGNALISR_OSCORE3_RECV4_BUFFER];

/* Dynamic X-Signal send port data: OsCore5 -> OsCore2/XSignalIsr_OsCore2_Recv4 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore5_Send2_XSignalIsr_OsCore2_Recv4_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore5_Send2_Data[OS_CFG_SIZE_OSCORE5_SEND2_XSIGNALISR_OSCORE2_RECV4_BUFFER];

/* Dynamic X-Signal send port data: OsCore5 -> OsCore1/XSignalIsr_OsCore1_Recv4 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore5_Send3_XSignalIsr_OsCore1_Recv4_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore5_Send3_Data[OS_CFG_SIZE_OSCORE5_SEND3_XSIGNALISR_OSCORE1_RECV4_BUFFER];

/* Dynamic X-Signal send port data: OsCore5 -> OsCore0/XSignalIsr_OsCore0_Recv4 */
OS_LOCAL VAR(Os_XSigChannelSendType, OS_VAR_NOINIT) OsCfg_XSig_OsCore5_Send4_XSignalIsr_OsCore0_Recv4_Send_Dyn;
OS_LOCAL VAR(Os_XSigSendDataType, OS_VAR_NOINIT)
  OsCore5_Send4_Data[OS_CFG_SIZE_OSCORE5_SEND4_XSIGNALISR_OSCORE0_RECV4_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore5_Recv0 <- OsCore0 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore0_Send4_XSignalIsr_OsCore5_Recv0_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore5_Recv0_Data[OS_CFG_SIZE_OSCORE0_SEND4_XSIGNALISR_OSCORE5_RECV0_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore5_Recv1 <- OsCore1 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore1_Send4_XSignalIsr_OsCore5_Recv1_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore5_Recv1_Data[OS_CFG_SIZE_OSCORE1_SEND4_XSIGNALISR_OSCORE5_RECV1_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore5_Recv2 <- OsCore2 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore2_Send4_XSignalIsr_OsCore5_Recv2_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore5_Recv2_Data[OS_CFG_SIZE_OSCORE2_SEND4_XSIGNALISR_OSCORE5_RECV2_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore5_Recv3 <- OsCore3 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore3_Send4_XSignalIsr_OsCore5_Recv3_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore5_Recv3_Data[OS_CFG_SIZE_OSCORE3_SEND4_XSIGNALISR_OSCORE5_RECV3_BUFFER];

/* Dynamic X-Signal receive port data: XSignalIsr_OsCore5_Recv4 <- OsCore4 */
OS_LOCAL VAR(Os_XSigChannelRecvType, OS_VAR_NOINIT) OsCfg_XSig_OsCore4_Send4_XSignalIsr_OsCore5_Recv4_Recv_Dyn;
OS_LOCAL VAR(Os_XSigRecvDataType, OS_VAR_NOINIT)
  XSignalIsr_OsCore5_Recv4_Data[OS_CFG_SIZE_OSCORE4_SEND4_XSIGNALISR_OSCORE5_RECV4_BUFFER];

#define OS_STOP_SEC_CORE5_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! X-Signal used services map. */
CONST(OSServiceIdType, OS_CONST) OsCfg_XSig_ServiceMap[OS_XSIGFUNCTIONIDX_USEDCOUNT + 1] =  /* PRQA S 1533, 4521 */ /* MD_Os_Rule8.9_1533, MD_Os_Rule1.1_4521 */
{
  OSServiceId_ActivateTask,
  OSServiceId_CancelAlarm,
  OSServiceId_ControlIdle,
  OSServiceId_GetAlarm,
  OSServiceId_GetApplicationState,
  OSServiceId_GetCounterValue,
  OSServiceId_GetErrorHookStackUsage,
  OSServiceId_GetEvent,
  OSServiceId_GetISRStackUsage,
  OSServiceId_GetKernelStackUsage,
  OSServiceId_GetProtectionHookStackUsage,
  OSServiceId_GetScheduleTableStatus,
  OSServiceId_GetShutdownHookStackUsage,
  OSServiceId_GetStartupHookStackUsage,
  OSServiceId_GetTaskStackUsage,
  OSServiceId_GetTaskState,
  OSServiceId_HookCallCallback,
  OSServiceId_NextScheduleTable,
  OSServiceId_SetAbsAlarm,
  OSServiceId_SetEvent,
  OSServiceId_SetRelAlarm,
  OSServiceId_ShutdownAllCores,
  OSServiceId_StartScheduleTableAbs,
  OSServiceId_StartScheduleTableRel,
  OSServiceId_StopScheduleTable,
  OSServiceId_TerminateApplication,
  OSSERVICEID_COUNT
};

/*! X-Signal data buffer: OsCore0 -> OsCore4/XSignalIsr_OsCore4_Recv0 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore0_Send0_XSignalIsr_OsCore4_Recv0_Buffer_Dyn[OS_CFG_SIZE_OSCORE0_SEND0_XSIGNALISR_OSCORE4_RECV0_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore0_Send0_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore4_Recv0_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore0_Send0_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore4_Recv0_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore0 -> OsCore3/XSignalIsr_OsCore3_Recv0 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore0_Send1_XSignalIsr_OsCore3_Recv0_Buffer_Dyn[OS_CFG_SIZE_OSCORE0_SEND1_XSIGNALISR_OSCORE3_RECV0_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore0_Send1_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore3_Recv0_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore0_Send1_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore3_Recv0_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore0 -> OsCore2/XSignalIsr_OsCore2_Recv0 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore0_Send2_XSignalIsr_OsCore2_Recv0_Buffer_Dyn[OS_CFG_SIZE_OSCORE0_SEND2_XSIGNALISR_OSCORE2_RECV0_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore0_Send2_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore2_Recv0_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore0_Send2_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore2_Recv0_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore0 -> OsCore1/XSignalIsr_OsCore1_Recv0 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore0_Send3_XSignalIsr_OsCore1_Recv0_Buffer_Dyn[OS_CFG_SIZE_OSCORE0_SEND3_XSIGNALISR_OSCORE1_RECV0_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore0_Send3_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore1_Recv0_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore0_Send3_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore1_Recv0_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore0 -> OsCore5/XSignalIsr_OsCore5_Recv0 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore0_Send4_XSignalIsr_OsCore5_Recv0_Buffer_Dyn[OS_CFG_SIZE_OSCORE0_SEND4_XSIGNALISR_OSCORE5_RECV0_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore0_Send4_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore5_Recv0_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore0_Send4_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore5_Recv0_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore1 -> OsCore4/XSignalIsr_OsCore4_Recv1 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore1_Send0_XSignalIsr_OsCore4_Recv1_Buffer_Dyn[OS_CFG_SIZE_OSCORE1_SEND0_XSIGNALISR_OSCORE4_RECV1_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore1_Send0_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore4_Recv1_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore1_Send0_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore4_Recv1_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore1 -> OsCore3/XSignalIsr_OsCore3_Recv1 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore1_Send1_XSignalIsr_OsCore3_Recv1_Buffer_Dyn[OS_CFG_SIZE_OSCORE1_SEND1_XSIGNALISR_OSCORE3_RECV1_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore1_Send1_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore3_Recv1_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore1_Send1_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore3_Recv1_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore1 -> OsCore2/XSignalIsr_OsCore2_Recv1 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore1_Send2_XSignalIsr_OsCore2_Recv1_Buffer_Dyn[OS_CFG_SIZE_OSCORE1_SEND2_XSIGNALISR_OSCORE2_RECV1_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore1_Send2_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore2_Recv1_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore1_Send2_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore2_Recv1_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore1 -> OsCore0/XSignalIsr_OsCore0_Recv0 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore1_Send3_XSignalIsr_OsCore0_Recv0_Buffer_Dyn[OS_CFG_SIZE_OSCORE1_SEND3_XSIGNALISR_OSCORE0_RECV0_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore1_Send3_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore0_Recv0_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore1_Send3_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore0_Recv0_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore1 -> OsCore5/XSignalIsr_OsCore5_Recv1 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore1_Send4_XSignalIsr_OsCore5_Recv1_Buffer_Dyn[OS_CFG_SIZE_OSCORE1_SEND4_XSIGNALISR_OSCORE5_RECV1_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore1_Send4_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore5_Recv1_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore1_Send4_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore5_Recv1_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore2 -> OsCore4/XSignalIsr_OsCore4_Recv2 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore2_Send0_XSignalIsr_OsCore4_Recv2_Buffer_Dyn[OS_CFG_SIZE_OSCORE2_SEND0_XSIGNALISR_OSCORE4_RECV2_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore2_Send0_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore4_Recv2_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore2_Send0_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore4_Recv2_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore2 -> OsCore3/XSignalIsr_OsCore3_Recv2 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore2_Send1_XSignalIsr_OsCore3_Recv2_Buffer_Dyn[OS_CFG_SIZE_OSCORE2_SEND1_XSIGNALISR_OSCORE3_RECV2_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore2_Send1_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore3_Recv2_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore2_Send1_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore3_Recv2_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore2 -> OsCore1/XSignalIsr_OsCore1_Recv1 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore2_Send2_XSignalIsr_OsCore1_Recv1_Buffer_Dyn[OS_CFG_SIZE_OSCORE2_SEND2_XSIGNALISR_OSCORE1_RECV1_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore2_Send2_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore1_Recv1_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore2_Send2_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore1_Recv1_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore2 -> OsCore0/XSignalIsr_OsCore0_Recv1 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore2_Send3_XSignalIsr_OsCore0_Recv1_Buffer_Dyn[OS_CFG_SIZE_OSCORE2_SEND3_XSIGNALISR_OSCORE0_RECV1_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore2_Send3_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore0_Recv1_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore2_Send3_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore0_Recv1_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore2 -> OsCore5/XSignalIsr_OsCore5_Recv2 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore2_Send4_XSignalIsr_OsCore5_Recv2_Buffer_Dyn[OS_CFG_SIZE_OSCORE2_SEND4_XSIGNALISR_OSCORE5_RECV2_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore2_Send4_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore5_Recv2_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore2_Send4_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore5_Recv2_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore3 -> OsCore4/XSignalIsr_OsCore4_Recv3 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore3_Send0_XSignalIsr_OsCore4_Recv3_Buffer_Dyn[OS_CFG_SIZE_OSCORE3_SEND0_XSIGNALISR_OSCORE4_RECV3_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore3_Send0_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore4_Recv3_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore3_Send0_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore4_Recv3_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore3 -> OsCore2/XSignalIsr_OsCore2_Recv2 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore3_Send1_XSignalIsr_OsCore2_Recv2_Buffer_Dyn[OS_CFG_SIZE_OSCORE3_SEND1_XSIGNALISR_OSCORE2_RECV2_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore3_Send1_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore2_Recv2_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore3_Send1_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore2_Recv2_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore3 -> OsCore1/XSignalIsr_OsCore1_Recv2 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore3_Send2_XSignalIsr_OsCore1_Recv2_Buffer_Dyn[OS_CFG_SIZE_OSCORE3_SEND2_XSIGNALISR_OSCORE1_RECV2_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore3_Send2_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore1_Recv2_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore3_Send2_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore1_Recv2_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore3 -> OsCore0/XSignalIsr_OsCore0_Recv2 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore3_Send3_XSignalIsr_OsCore0_Recv2_Buffer_Dyn[OS_CFG_SIZE_OSCORE3_SEND3_XSIGNALISR_OSCORE0_RECV2_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore3_Send3_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore0_Recv2_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore3_Send3_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore0_Recv2_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore3 -> OsCore5/XSignalIsr_OsCore5_Recv3 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore3_Send4_XSignalIsr_OsCore5_Recv3_Buffer_Dyn[OS_CFG_SIZE_OSCORE3_SEND4_XSIGNALISR_OSCORE5_RECV3_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore3_Send4_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore5_Recv3_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore3_Send4_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore5_Recv3_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore4 -> OsCore3/XSignalIsr_OsCore3_Recv3 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore4_Send0_XSignalIsr_OsCore3_Recv3_Buffer_Dyn[OS_CFG_SIZE_OSCORE4_SEND0_XSIGNALISR_OSCORE3_RECV3_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore4_Send0_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore3_Recv3_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore4_Send0_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore3_Recv3_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore4 -> OsCore2/XSignalIsr_OsCore2_Recv3 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore4_Send1_XSignalIsr_OsCore2_Recv3_Buffer_Dyn[OS_CFG_SIZE_OSCORE4_SEND1_XSIGNALISR_OSCORE2_RECV3_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore4_Send1_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore2_Recv3_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore4_Send1_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore2_Recv3_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore4 -> OsCore1/XSignalIsr_OsCore1_Recv3 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore4_Send2_XSignalIsr_OsCore1_Recv3_Buffer_Dyn[OS_CFG_SIZE_OSCORE4_SEND2_XSIGNALISR_OSCORE1_RECV3_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore4_Send2_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore1_Recv3_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore4_Send2_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore1_Recv3_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore4 -> OsCore0/XSignalIsr_OsCore0_Recv3 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore4_Send3_XSignalIsr_OsCore0_Recv3_Buffer_Dyn[OS_CFG_SIZE_OSCORE4_SEND3_XSIGNALISR_OSCORE0_RECV3_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore4_Send3_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore0_Recv3_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore4_Send3_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore0_Recv3_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore4 -> OsCore5/XSignalIsr_OsCore5_Recv4 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore4_Send4_XSignalIsr_OsCore5_Recv4_Buffer_Dyn[OS_CFG_SIZE_OSCORE4_SEND4_XSIGNALISR_OSCORE5_RECV4_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore4_Send4_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore5_Recv4_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore4_Send4_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore5_Recv4_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore5 -> OsCore4/XSignalIsr_OsCore4_Recv4 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore5_Send0_XSignalIsr_OsCore4_Recv4_Buffer_Dyn[OS_CFG_SIZE_OSCORE5_SEND0_XSIGNALISR_OSCORE4_RECV4_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore5_Send0_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore4_Recv4_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore5_Send0_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore4_Recv4_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore5 -> OsCore3/XSignalIsr_OsCore3_Recv4 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore5_Send1_XSignalIsr_OsCore3_Recv4_Buffer_Dyn[OS_CFG_SIZE_OSCORE5_SEND1_XSIGNALISR_OSCORE3_RECV4_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore5_Send1_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore3_Recv4_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore5_Send1_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore3_Recv4_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore5 -> OsCore2/XSignalIsr_OsCore2_Recv4 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore5_Send2_XSignalIsr_OsCore2_Recv4_Buffer_Dyn[OS_CFG_SIZE_OSCORE5_SEND2_XSIGNALISR_OSCORE2_RECV4_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore5_Send2_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore2_Recv4_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore5_Send2_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore2_Recv4_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore5 -> OsCore1/XSignalIsr_OsCore1_Recv4 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore5_Send3_XSignalIsr_OsCore1_Recv4_Buffer_Dyn[OS_CFG_SIZE_OSCORE5_SEND3_XSIGNALISR_OSCORE1_RECV4_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore5_Send3_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore1_Recv4_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore5_Send3_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore1_Recv4_Data[1]),
    /* .Idx      = */ 1
  }
};

/*! X-Signal data buffer: OsCore5 -> OsCore0/XSignalIsr_OsCore0_Recv4 */
OS_LOCAL CONST(Os_XSigComDataConfigType, OS_CONST) OsCfg_XSig_OsCore5_Send4_XSignalIsr_OsCore0_Recv4_Buffer_Dyn[OS_CFG_SIZE_OSCORE5_SEND4_XSIGNALISR_OSCORE0_RECV4_BUFFER] =
{
  {
    /* .SendData = */ &(OsCore5_Send4_Data[0]),
    /* .RecvData = */ &(XSignalIsr_OsCore0_Recv4_Data[0]),
    /* .Idx      = */ 0
  },
  {
    /* .SendData = */ &(OsCore5_Send4_Data[1]),
    /* .RecvData = */ &(XSignalIsr_OsCore0_Recv4_Data[1]),
    /* .Idx      = */ 1
  }
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! X-Signal send port configuration data: OsCore0 -> OsCore4/XSignalIsr_OsCore4_Recv0 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore0_Send0 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore0_Send0_XSignalIsr_OsCore4_Recv0_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore0_Send0_XSignalIsr_OsCore4_Recv0_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore0_Send0_XSignalIsr_OsCore4_Recv0_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE0_SEND0_XSIGNALISR_OSCORE4_RECV0_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore4,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore4_Recv0,
  /* .SendCore    = */ &OsCfg_Core_OsCore0
};

/*! X-Signal send port configuration data: OsCore0 -> OsCore3/XSignalIsr_OsCore3_Recv0 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore0_Send1 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore0_Send1_XSignalIsr_OsCore3_Recv0_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore0_Send1_XSignalIsr_OsCore3_Recv0_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore0_Send1_XSignalIsr_OsCore3_Recv0_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE0_SEND1_XSIGNALISR_OSCORE3_RECV0_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore3,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore3_Recv0,
  /* .SendCore    = */ &OsCfg_Core_OsCore0
};

/*! X-Signal send port configuration data: OsCore0 -> OsCore2/XSignalIsr_OsCore2_Recv0 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore0_Send2 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore0_Send2_XSignalIsr_OsCore2_Recv0_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore0_Send2_XSignalIsr_OsCore2_Recv0_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore0_Send2_XSignalIsr_OsCore2_Recv0_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE0_SEND2_XSIGNALISR_OSCORE2_RECV0_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore2,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore2_Recv0,
  /* .SendCore    = */ &OsCfg_Core_OsCore0
};

/*! X-Signal send port configuration data: OsCore0 -> OsCore1/XSignalIsr_OsCore1_Recv0 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore0_Send3 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore0_Send3_XSignalIsr_OsCore1_Recv0_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore0_Send3_XSignalIsr_OsCore1_Recv0_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore0_Send3_XSignalIsr_OsCore1_Recv0_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE0_SEND3_XSIGNALISR_OSCORE1_RECV0_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore1,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore1_Recv0,
  /* .SendCore    = */ &OsCfg_Core_OsCore0
};

/*! X-Signal send port configuration data: OsCore0 -> OsCore5/XSignalIsr_OsCore5_Recv0 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore0_Send4 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore0_Send4_XSignalIsr_OsCore5_Recv0_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore0_Send4_XSignalIsr_OsCore5_Recv0_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore0_Send4_XSignalIsr_OsCore5_Recv0_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE0_SEND4_XSIGNALISR_OSCORE5_RECV0_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore5,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore5_Recv0,
  /* .SendCore    = */ &OsCfg_Core_OsCore0
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore0_Recv0 <- OsCore1 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore0_Recv0 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore1_Send3_XSignalIsr_OsCore0_Recv0_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore1_Send3_XSignalIsr_OsCore0_Recv0_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore1_Send3_XSignalIsr_OsCore0_Recv0_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE1_SEND3_XSIGNALISR_OSCORE0_RECV0_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore1_Send3
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore0_Recv1 <- OsCore2 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore0_Recv1 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore2_Send3_XSignalIsr_OsCore0_Recv1_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore2_Send3_XSignalIsr_OsCore0_Recv1_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore2_Send3_XSignalIsr_OsCore0_Recv1_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE2_SEND3_XSIGNALISR_OSCORE0_RECV1_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore2_Send3
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore0_Recv2 <- OsCore3 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore0_Recv2 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore3_Send3_XSignalIsr_OsCore0_Recv2_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore3_Send3_XSignalIsr_OsCore0_Recv2_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore3_Send3_XSignalIsr_OsCore0_Recv2_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE3_SEND3_XSIGNALISR_OSCORE0_RECV2_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore3_Send3
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore0_Recv3 <- OsCore4 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore0_Recv3 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore4_Send3_XSignalIsr_OsCore0_Recv3_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore4_Send3_XSignalIsr_OsCore0_Recv3_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore4_Send3_XSignalIsr_OsCore0_Recv3_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE4_SEND3_XSIGNALISR_OSCORE0_RECV3_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore4_Send3
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore0_Recv4 <- OsCore5 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore0_Recv4 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore5_Send4_XSignalIsr_OsCore0_Recv4_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore5_Send4_XSignalIsr_OsCore0_Recv4_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore5_Send4_XSignalIsr_OsCore0_Recv4_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE5_SEND4_XSIGNALISR_OSCORE0_RECV4_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore5_Send4
};

/*! X-Signal ISR function table: XSignalIsr_OsCore0 */
CONST(Os_XSigFunctionTableConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore0_FuncTable =
{
  /* .FunctionDescription = */
  {
    { Os_XSigRecv_ActivateTask }, /* OSServiceId_ActivateTask */
    { Os_XSigRecv_CancelAlarm }, /* OSServiceId_CancelAlarm */
    { Os_XSigRecv_ControlIdle }, /* OSServiceId_ControlIdle */
    { Os_XSigRecv_GetAlarm }, /* OSServiceId_GetAlarm */
    { Os_XSigRecv_GetApplicationState }, /* OSServiceId_GetApplicationState */
    { Os_XSigRecv_GetCounterValue }, /* OSServiceId_GetCounterValue */
    { Os_XSigRecv_GetErrorHookStackUsage }, /* OSServiceId_GetErrorHookStackUsage */
    { Os_XSigRecv_GetEvent }, /* OSServiceId_GetEvent */
    { Os_XSigRecv_GetISRStackUsage }, /* OSServiceId_GetISRStackUsage */
    { Os_XSigRecv_GetKernelStackUsage }, /* OSServiceId_GetKernelStackUsage */
    { Os_XSigRecv_GetProtectionHookStackUsage }, /* OSServiceId_GetProtectionHookStackUsage */
    { Os_XSigRecv_GetScheduleTableStatus }, /* OSServiceId_GetScheduleTableStatus */
    { Os_XSigRecv_GetShutdownHookStackUsage }, /* OSServiceId_GetShutdownHookStackUsage */
    { Os_XSigRecv_GetStartupHookStackUsage }, /* OSServiceId_GetStartupHookStackUsage */
    { Os_XSigRecv_GetTaskStackUsage }, /* OSServiceId_GetTaskStackUsage */
    { Os_XSigRecv_GetTaskState }, /* OSServiceId_GetTaskState */
    { Os_XSigRecv_HookCallCallback }, /* OSServiceId_HookCallCallback */
    { Os_XSigRecv_NextScheduleTable }, /* OSServiceId_NextScheduleTable */
    { Os_XSigRecv_SetAbsAlarm }, /* OSServiceId_SetAbsAlarm */
    { Os_XSigRecv_SetEvent }, /* OSServiceId_SetEvent */
    { Os_XSigRecv_SetRelAlarm }, /* OSServiceId_SetRelAlarm */
    { Os_XSigRecv_ShutdownAllCores }, /* OSServiceId_ShutdownAllCores */
    { Os_XSigRecv_StartScheduleTableAbs }, /* OSServiceId_StartScheduleTableAbs */
    { Os_XSigRecv_StartScheduleTableRel }, /* OSServiceId_StartScheduleTableRel */
    { Os_XSigRecv_StopScheduleTable }, /* OSServiceId_StopScheduleTable */
    { Os_XSigRecv_TerminateApplication }, /* OSServiceId_TerminateApplication */
    { NULL_PTR }
  }
};

/*! X-Signal ISR receive ports reference table: XSignalIsr_OsCore0 */
CONST(Os_XSigRecvPortConfigRefType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore0_PortRefs[OS_CFG_NUM_ISR_XSIGNALISR_OSCORE0_PORTS + 1u] =
{
  &OsCfg_XSig_XSignalIsr_OsCore0_Recv0,
  &OsCfg_XSig_XSignalIsr_OsCore0_Recv1,
  &OsCfg_XSig_XSignalIsr_OsCore0_Recv2,
  &OsCfg_XSig_XSignalIsr_OsCore0_Recv3,
  &OsCfg_XSig_XSignalIsr_OsCore0_Recv4,
  NULL_PTR
};

/*! X-Signal receiver ISRs reference table: OsCore0 */
OS_LOCAL CONST(Os_XSigIsrConfigRefType, OS_CONST) OsCfg_XSig_OsCore0_IsrRefs[OS_CFG_NUM_XSIG_OSCORE0_ISRS + 1u] =
{
  &OsCfg_Isr_XSignalIsr_OsCore0,
  NULL_PTR
};

/*! X-Signal configuration data: OsCore0 */
CONST(Os_XSigConfigType, OS_CONST) OsCfg_XSig_OsCore0 =
{
  /* .XSigSendPorts    = */ 
  {
    /* [0] = */ NULL_PTR, /* OsCore0 */
    /* [1] = */ &OsCfg_XSig_OsCore0_Send3, /* OsCore1 */
    /* [2] = */ &OsCfg_XSig_OsCore0_Send2, /* OsCore2 */
    /* [3] = */ &OsCfg_XSig_OsCore0_Send1, /* OsCore3 */
    /* [4] = */ &OsCfg_XSig_OsCore0_Send0, /* OsCore4 */
    /* [5] = */ &OsCfg_XSig_OsCore0_Send4 /* OsCore5 */
  },
  /* .XSigRecvIsrRefs  = */ OsCfg_XSig_OsCore0_IsrRefs,
  /* .XSigRecvIsrCount = */ (Os_ObjIdxType)OS_CFG_NUM_XSIG_OSCORE0_ISRS
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! X-Signal send port configuration data: OsCore1 -> OsCore4/XSignalIsr_OsCore4_Recv1 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore1_Send0 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore1_Send0_XSignalIsr_OsCore4_Recv1_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore1_Send0_XSignalIsr_OsCore4_Recv1_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore1_Send0_XSignalIsr_OsCore4_Recv1_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE1_SEND0_XSIGNALISR_OSCORE4_RECV1_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore4,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore4_Recv1,
  /* .SendCore    = */ &OsCfg_Core_OsCore1
};

/*! X-Signal send port configuration data: OsCore1 -> OsCore3/XSignalIsr_OsCore3_Recv1 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore1_Send1 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore1_Send1_XSignalIsr_OsCore3_Recv1_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore1_Send1_XSignalIsr_OsCore3_Recv1_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore1_Send1_XSignalIsr_OsCore3_Recv1_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE1_SEND1_XSIGNALISR_OSCORE3_RECV1_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore3,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore3_Recv1,
  /* .SendCore    = */ &OsCfg_Core_OsCore1
};

/*! X-Signal send port configuration data: OsCore1 -> OsCore2/XSignalIsr_OsCore2_Recv1 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore1_Send2 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore1_Send2_XSignalIsr_OsCore2_Recv1_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore1_Send2_XSignalIsr_OsCore2_Recv1_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore1_Send2_XSignalIsr_OsCore2_Recv1_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE1_SEND2_XSIGNALISR_OSCORE2_RECV1_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore2,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore2_Recv1,
  /* .SendCore    = */ &OsCfg_Core_OsCore1
};

/*! X-Signal send port configuration data: OsCore1 -> OsCore0/XSignalIsr_OsCore0_Recv0 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore1_Send3 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore1_Send3_XSignalIsr_OsCore0_Recv0_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore1_Send3_XSignalIsr_OsCore0_Recv0_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore1_Send3_XSignalIsr_OsCore0_Recv0_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE1_SEND3_XSIGNALISR_OSCORE0_RECV0_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore0,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore0_Recv0,
  /* .SendCore    = */ &OsCfg_Core_OsCore1
};

/*! X-Signal send port configuration data: OsCore1 -> OsCore5/XSignalIsr_OsCore5_Recv1 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore1_Send4 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore1_Send4_XSignalIsr_OsCore5_Recv1_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore1_Send4_XSignalIsr_OsCore5_Recv1_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore1_Send4_XSignalIsr_OsCore5_Recv1_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE1_SEND4_XSIGNALISR_OSCORE5_RECV1_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore5,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore5_Recv1,
  /* .SendCore    = */ &OsCfg_Core_OsCore1
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore1_Recv0 <- OsCore0 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore1_Recv0 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore0_Send3_XSignalIsr_OsCore1_Recv0_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore0_Send3_XSignalIsr_OsCore1_Recv0_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore0_Send3_XSignalIsr_OsCore1_Recv0_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE0_SEND3_XSIGNALISR_OSCORE1_RECV0_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore0_Send3
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore1_Recv1 <- OsCore2 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore1_Recv1 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore2_Send2_XSignalIsr_OsCore1_Recv1_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore2_Send2_XSignalIsr_OsCore1_Recv1_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore2_Send2_XSignalIsr_OsCore1_Recv1_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE2_SEND2_XSIGNALISR_OSCORE1_RECV1_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore2_Send2
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore1_Recv2 <- OsCore3 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore1_Recv2 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore3_Send2_XSignalIsr_OsCore1_Recv2_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore3_Send2_XSignalIsr_OsCore1_Recv2_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore3_Send2_XSignalIsr_OsCore1_Recv2_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE3_SEND2_XSIGNALISR_OSCORE1_RECV2_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore3_Send2
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore1_Recv3 <- OsCore4 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore1_Recv3 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore4_Send2_XSignalIsr_OsCore1_Recv3_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore4_Send2_XSignalIsr_OsCore1_Recv3_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore4_Send2_XSignalIsr_OsCore1_Recv3_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE4_SEND2_XSIGNALISR_OSCORE1_RECV3_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore4_Send2
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore1_Recv4 <- OsCore5 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore1_Recv4 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore5_Send3_XSignalIsr_OsCore1_Recv4_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore5_Send3_XSignalIsr_OsCore1_Recv4_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore5_Send3_XSignalIsr_OsCore1_Recv4_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE5_SEND3_XSIGNALISR_OSCORE1_RECV4_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore5_Send3
};

/*! X-Signal ISR function table: XSignalIsr_OsCore1 */
CONST(Os_XSigFunctionTableConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore1_FuncTable =
{
  /* .FunctionDescription = */
  {
    { Os_XSigRecv_ActivateTask }, /* OSServiceId_ActivateTask */
    { Os_XSigRecv_CancelAlarm }, /* OSServiceId_CancelAlarm */
    { Os_XSigRecv_ControlIdle }, /* OSServiceId_ControlIdle */
    { Os_XSigRecv_GetAlarm }, /* OSServiceId_GetAlarm */
    { Os_XSigRecv_GetApplicationState }, /* OSServiceId_GetApplicationState */
    { Os_XSigRecv_GetCounterValue }, /* OSServiceId_GetCounterValue */
    { Os_XSigRecv_GetErrorHookStackUsage }, /* OSServiceId_GetErrorHookStackUsage */
    { Os_XSigRecv_GetEvent }, /* OSServiceId_GetEvent */
    { Os_XSigRecv_GetISRStackUsage }, /* OSServiceId_GetISRStackUsage */
    { Os_XSigRecv_GetKernelStackUsage }, /* OSServiceId_GetKernelStackUsage */
    { Os_XSigRecv_GetProtectionHookStackUsage }, /* OSServiceId_GetProtectionHookStackUsage */
    { Os_XSigRecv_GetScheduleTableStatus }, /* OSServiceId_GetScheduleTableStatus */
    { Os_XSigRecv_GetShutdownHookStackUsage }, /* OSServiceId_GetShutdownHookStackUsage */
    { Os_XSigRecv_GetStartupHookStackUsage }, /* OSServiceId_GetStartupHookStackUsage */
    { Os_XSigRecv_GetTaskStackUsage }, /* OSServiceId_GetTaskStackUsage */
    { Os_XSigRecv_GetTaskState }, /* OSServiceId_GetTaskState */
    { Os_XSigRecv_HookCallCallback }, /* OSServiceId_HookCallCallback */
    { Os_XSigRecv_NextScheduleTable }, /* OSServiceId_NextScheduleTable */
    { Os_XSigRecv_SetAbsAlarm }, /* OSServiceId_SetAbsAlarm */
    { Os_XSigRecv_SetEvent }, /* OSServiceId_SetEvent */
    { Os_XSigRecv_SetRelAlarm }, /* OSServiceId_SetRelAlarm */
    { Os_XSigRecv_ShutdownAllCores }, /* OSServiceId_ShutdownAllCores */
    { Os_XSigRecv_StartScheduleTableAbs }, /* OSServiceId_StartScheduleTableAbs */
    { Os_XSigRecv_StartScheduleTableRel }, /* OSServiceId_StartScheduleTableRel */
    { Os_XSigRecv_StopScheduleTable }, /* OSServiceId_StopScheduleTable */
    { Os_XSigRecv_TerminateApplication }, /* OSServiceId_TerminateApplication */
    { NULL_PTR }
  }
};

/*! X-Signal ISR receive ports reference table: XSignalIsr_OsCore1 */
CONST(Os_XSigRecvPortConfigRefType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore1_PortRefs[OS_CFG_NUM_ISR_XSIGNALISR_OSCORE1_PORTS + 1u] =
{
  &OsCfg_XSig_XSignalIsr_OsCore1_Recv0,
  &OsCfg_XSig_XSignalIsr_OsCore1_Recv1,
  &OsCfg_XSig_XSignalIsr_OsCore1_Recv2,
  &OsCfg_XSig_XSignalIsr_OsCore1_Recv3,
  &OsCfg_XSig_XSignalIsr_OsCore1_Recv4,
  NULL_PTR
};

/*! X-Signal receiver ISRs reference table: OsCore1 */
OS_LOCAL CONST(Os_XSigIsrConfigRefType, OS_CONST) OsCfg_XSig_OsCore1_IsrRefs[OS_CFG_NUM_XSIG_OSCORE1_ISRS + 1u] =
{
  &OsCfg_Isr_XSignalIsr_OsCore1,
  NULL_PTR
};

/*! X-Signal configuration data: OsCore1 */
CONST(Os_XSigConfigType, OS_CONST) OsCfg_XSig_OsCore1 =
{
  /* .XSigSendPorts    = */ 
  {
    /* [0] = */ &OsCfg_XSig_OsCore1_Send3, /* OsCore0 */
    /* [1] = */ NULL_PTR, /* OsCore1 */
    /* [2] = */ &OsCfg_XSig_OsCore1_Send2, /* OsCore2 */
    /* [3] = */ &OsCfg_XSig_OsCore1_Send1, /* OsCore3 */
    /* [4] = */ &OsCfg_XSig_OsCore1_Send0, /* OsCore4 */
    /* [5] = */ &OsCfg_XSig_OsCore1_Send4 /* OsCore5 */
  },
  /* .XSigRecvIsrRefs  = */ OsCfg_XSig_OsCore1_IsrRefs,
  /* .XSigRecvIsrCount = */ (Os_ObjIdxType)OS_CFG_NUM_XSIG_OSCORE1_ISRS
};

#define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! X-Signal send port configuration data: OsCore2 -> OsCore4/XSignalIsr_OsCore4_Recv2 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore2_Send0 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore2_Send0_XSignalIsr_OsCore4_Recv2_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore2_Send0_XSignalIsr_OsCore4_Recv2_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore2_Send0_XSignalIsr_OsCore4_Recv2_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE2_SEND0_XSIGNALISR_OSCORE4_RECV2_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore4,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore4_Recv2,
  /* .SendCore    = */ &OsCfg_Core_OsCore2
};

/*! X-Signal send port configuration data: OsCore2 -> OsCore3/XSignalIsr_OsCore3_Recv2 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore2_Send1 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore2_Send1_XSignalIsr_OsCore3_Recv2_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore2_Send1_XSignalIsr_OsCore3_Recv2_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore2_Send1_XSignalIsr_OsCore3_Recv2_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE2_SEND1_XSIGNALISR_OSCORE3_RECV2_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore3,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore3_Recv2,
  /* .SendCore    = */ &OsCfg_Core_OsCore2
};

/*! X-Signal send port configuration data: OsCore2 -> OsCore1/XSignalIsr_OsCore1_Recv1 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore2_Send2 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore2_Send2_XSignalIsr_OsCore1_Recv1_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore2_Send2_XSignalIsr_OsCore1_Recv1_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore2_Send2_XSignalIsr_OsCore1_Recv1_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE2_SEND2_XSIGNALISR_OSCORE1_RECV1_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore1,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore1_Recv1,
  /* .SendCore    = */ &OsCfg_Core_OsCore2
};

/*! X-Signal send port configuration data: OsCore2 -> OsCore0/XSignalIsr_OsCore0_Recv1 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore2_Send3 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore2_Send3_XSignalIsr_OsCore0_Recv1_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore2_Send3_XSignalIsr_OsCore0_Recv1_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore2_Send3_XSignalIsr_OsCore0_Recv1_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE2_SEND3_XSIGNALISR_OSCORE0_RECV1_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore0,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore0_Recv1,
  /* .SendCore    = */ &OsCfg_Core_OsCore2
};

/*! X-Signal send port configuration data: OsCore2 -> OsCore5/XSignalIsr_OsCore5_Recv2 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore2_Send4 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore2_Send4_XSignalIsr_OsCore5_Recv2_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore2_Send4_XSignalIsr_OsCore5_Recv2_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore2_Send4_XSignalIsr_OsCore5_Recv2_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE2_SEND4_XSIGNALISR_OSCORE5_RECV2_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore5,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore5_Recv2,
  /* .SendCore    = */ &OsCfg_Core_OsCore2
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore2_Recv0 <- OsCore0 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore2_Recv0 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore0_Send2_XSignalIsr_OsCore2_Recv0_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore0_Send2_XSignalIsr_OsCore2_Recv0_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore0_Send2_XSignalIsr_OsCore2_Recv0_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE0_SEND2_XSIGNALISR_OSCORE2_RECV0_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore0_Send2
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore2_Recv1 <- OsCore1 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore2_Recv1 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore1_Send2_XSignalIsr_OsCore2_Recv1_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore1_Send2_XSignalIsr_OsCore2_Recv1_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore1_Send2_XSignalIsr_OsCore2_Recv1_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE1_SEND2_XSIGNALISR_OSCORE2_RECV1_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore1_Send2
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore2_Recv2 <- OsCore3 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore2_Recv2 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore3_Send1_XSignalIsr_OsCore2_Recv2_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore3_Send1_XSignalIsr_OsCore2_Recv2_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore3_Send1_XSignalIsr_OsCore2_Recv2_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE3_SEND1_XSIGNALISR_OSCORE2_RECV2_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore3_Send1
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore2_Recv3 <- OsCore4 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore2_Recv3 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore4_Send1_XSignalIsr_OsCore2_Recv3_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore4_Send1_XSignalIsr_OsCore2_Recv3_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore4_Send1_XSignalIsr_OsCore2_Recv3_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE4_SEND1_XSIGNALISR_OSCORE2_RECV3_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore4_Send1
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore2_Recv4 <- OsCore5 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore2_Recv4 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore5_Send2_XSignalIsr_OsCore2_Recv4_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore5_Send2_XSignalIsr_OsCore2_Recv4_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore5_Send2_XSignalIsr_OsCore2_Recv4_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE5_SEND2_XSIGNALISR_OSCORE2_RECV4_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore5_Send2
};

/*! X-Signal ISR function table: XSignalIsr_OsCore2 */
CONST(Os_XSigFunctionTableConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore2_FuncTable =
{
  /* .FunctionDescription = */
  {
    { Os_XSigRecv_ActivateTask }, /* OSServiceId_ActivateTask */
    { Os_XSigRecv_CancelAlarm }, /* OSServiceId_CancelAlarm */
    { Os_XSigRecv_ControlIdle }, /* OSServiceId_ControlIdle */
    { Os_XSigRecv_GetAlarm }, /* OSServiceId_GetAlarm */
    { Os_XSigRecv_GetApplicationState }, /* OSServiceId_GetApplicationState */
    { Os_XSigRecv_GetCounterValue }, /* OSServiceId_GetCounterValue */
    { Os_XSigRecv_GetErrorHookStackUsage }, /* OSServiceId_GetErrorHookStackUsage */
    { Os_XSigRecv_GetEvent }, /* OSServiceId_GetEvent */
    { Os_XSigRecv_GetISRStackUsage }, /* OSServiceId_GetISRStackUsage */
    { Os_XSigRecv_GetKernelStackUsage }, /* OSServiceId_GetKernelStackUsage */
    { Os_XSigRecv_GetProtectionHookStackUsage }, /* OSServiceId_GetProtectionHookStackUsage */
    { Os_XSigRecv_GetScheduleTableStatus }, /* OSServiceId_GetScheduleTableStatus */
    { Os_XSigRecv_GetShutdownHookStackUsage }, /* OSServiceId_GetShutdownHookStackUsage */
    { Os_XSigRecv_GetStartupHookStackUsage }, /* OSServiceId_GetStartupHookStackUsage */
    { Os_XSigRecv_GetTaskStackUsage }, /* OSServiceId_GetTaskStackUsage */
    { Os_XSigRecv_GetTaskState }, /* OSServiceId_GetTaskState */
    { Os_XSigRecv_HookCallCallback }, /* OSServiceId_HookCallCallback */
    { Os_XSigRecv_NextScheduleTable }, /* OSServiceId_NextScheduleTable */
    { Os_XSigRecv_SetAbsAlarm }, /* OSServiceId_SetAbsAlarm */
    { Os_XSigRecv_SetEvent }, /* OSServiceId_SetEvent */
    { Os_XSigRecv_SetRelAlarm }, /* OSServiceId_SetRelAlarm */
    { Os_XSigRecv_ShutdownAllCores }, /* OSServiceId_ShutdownAllCores */
    { Os_XSigRecv_StartScheduleTableAbs }, /* OSServiceId_StartScheduleTableAbs */
    { Os_XSigRecv_StartScheduleTableRel }, /* OSServiceId_StartScheduleTableRel */
    { Os_XSigRecv_StopScheduleTable }, /* OSServiceId_StopScheduleTable */
    { Os_XSigRecv_TerminateApplication }, /* OSServiceId_TerminateApplication */
    { NULL_PTR }
  }
};

/*! X-Signal ISR receive ports reference table: XSignalIsr_OsCore2 */
CONST(Os_XSigRecvPortConfigRefType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore2_PortRefs[OS_CFG_NUM_ISR_XSIGNALISR_OSCORE2_PORTS + 1u] =
{
  &OsCfg_XSig_XSignalIsr_OsCore2_Recv0,
  &OsCfg_XSig_XSignalIsr_OsCore2_Recv1,
  &OsCfg_XSig_XSignalIsr_OsCore2_Recv2,
  &OsCfg_XSig_XSignalIsr_OsCore2_Recv3,
  &OsCfg_XSig_XSignalIsr_OsCore2_Recv4,
  NULL_PTR
};

/*! X-Signal receiver ISRs reference table: OsCore2 */
OS_LOCAL CONST(Os_XSigIsrConfigRefType, OS_CONST) OsCfg_XSig_OsCore2_IsrRefs[OS_CFG_NUM_XSIG_OSCORE2_ISRS + 1u] =
{
  &OsCfg_Isr_XSignalIsr_OsCore2,
  NULL_PTR
};

/*! X-Signal configuration data: OsCore2 */
CONST(Os_XSigConfigType, OS_CONST) OsCfg_XSig_OsCore2 =
{
  /* .XSigSendPorts    = */ 
  {
    /* [0] = */ &OsCfg_XSig_OsCore2_Send3, /* OsCore0 */
    /* [1] = */ &OsCfg_XSig_OsCore2_Send2, /* OsCore1 */
    /* [2] = */ NULL_PTR, /* OsCore2 */
    /* [3] = */ &OsCfg_XSig_OsCore2_Send1, /* OsCore3 */
    /* [4] = */ &OsCfg_XSig_OsCore2_Send0, /* OsCore4 */
    /* [5] = */ &OsCfg_XSig_OsCore2_Send4 /* OsCore5 */
  },
  /* .XSigRecvIsrRefs  = */ OsCfg_XSig_OsCore2_IsrRefs,
  /* .XSigRecvIsrCount = */ (Os_ObjIdxType)OS_CFG_NUM_XSIG_OSCORE2_ISRS
};

#define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE3_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! X-Signal send port configuration data: OsCore3 -> OsCore4/XSignalIsr_OsCore4_Recv3 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore3_Send0 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore3_Send0_XSignalIsr_OsCore4_Recv3_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore3_Send0_XSignalIsr_OsCore4_Recv3_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore3_Send0_XSignalIsr_OsCore4_Recv3_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE3_SEND0_XSIGNALISR_OSCORE4_RECV3_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore4,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore4_Recv3,
  /* .SendCore    = */ &OsCfg_Core_OsCore3
};

/*! X-Signal send port configuration data: OsCore3 -> OsCore2/XSignalIsr_OsCore2_Recv2 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore3_Send1 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore3_Send1_XSignalIsr_OsCore2_Recv2_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore3_Send1_XSignalIsr_OsCore2_Recv2_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore3_Send1_XSignalIsr_OsCore2_Recv2_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE3_SEND1_XSIGNALISR_OSCORE2_RECV2_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore2,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore2_Recv2,
  /* .SendCore    = */ &OsCfg_Core_OsCore3
};

/*! X-Signal send port configuration data: OsCore3 -> OsCore1/XSignalIsr_OsCore1_Recv2 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore3_Send2 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore3_Send2_XSignalIsr_OsCore1_Recv2_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore3_Send2_XSignalIsr_OsCore1_Recv2_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore3_Send2_XSignalIsr_OsCore1_Recv2_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE3_SEND2_XSIGNALISR_OSCORE1_RECV2_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore1,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore1_Recv2,
  /* .SendCore    = */ &OsCfg_Core_OsCore3
};

/*! X-Signal send port configuration data: OsCore3 -> OsCore0/XSignalIsr_OsCore0_Recv2 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore3_Send3 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore3_Send3_XSignalIsr_OsCore0_Recv2_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore3_Send3_XSignalIsr_OsCore0_Recv2_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore3_Send3_XSignalIsr_OsCore0_Recv2_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE3_SEND3_XSIGNALISR_OSCORE0_RECV2_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore0,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore0_Recv2,
  /* .SendCore    = */ &OsCfg_Core_OsCore3
};

/*! X-Signal send port configuration data: OsCore3 -> OsCore5/XSignalIsr_OsCore5_Recv3 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore3_Send4 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore3_Send4_XSignalIsr_OsCore5_Recv3_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore3_Send4_XSignalIsr_OsCore5_Recv3_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore3_Send4_XSignalIsr_OsCore5_Recv3_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE3_SEND4_XSIGNALISR_OSCORE5_RECV3_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore5,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore5_Recv3,
  /* .SendCore    = */ &OsCfg_Core_OsCore3
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore3_Recv0 <- OsCore0 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore3_Recv0 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore0_Send1_XSignalIsr_OsCore3_Recv0_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore0_Send1_XSignalIsr_OsCore3_Recv0_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore0_Send1_XSignalIsr_OsCore3_Recv0_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE0_SEND1_XSIGNALISR_OSCORE3_RECV0_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore0_Send1
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore3_Recv1 <- OsCore1 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore3_Recv1 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore1_Send1_XSignalIsr_OsCore3_Recv1_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore1_Send1_XSignalIsr_OsCore3_Recv1_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore1_Send1_XSignalIsr_OsCore3_Recv1_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE1_SEND1_XSIGNALISR_OSCORE3_RECV1_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore1_Send1
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore3_Recv2 <- OsCore2 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore3_Recv2 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore2_Send1_XSignalIsr_OsCore3_Recv2_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore2_Send1_XSignalIsr_OsCore3_Recv2_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore2_Send1_XSignalIsr_OsCore3_Recv2_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE2_SEND1_XSIGNALISR_OSCORE3_RECV2_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore2_Send1
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore3_Recv3 <- OsCore4 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore3_Recv3 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore4_Send0_XSignalIsr_OsCore3_Recv3_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore4_Send0_XSignalIsr_OsCore3_Recv3_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore4_Send0_XSignalIsr_OsCore3_Recv3_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE4_SEND0_XSIGNALISR_OSCORE3_RECV3_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore4_Send0
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore3_Recv4 <- OsCore5 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore3_Recv4 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore5_Send1_XSignalIsr_OsCore3_Recv4_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore5_Send1_XSignalIsr_OsCore3_Recv4_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore5_Send1_XSignalIsr_OsCore3_Recv4_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE5_SEND1_XSIGNALISR_OSCORE3_RECV4_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore5_Send1
};

/*! X-Signal ISR function table: XSignalIsr_OsCore3 */
CONST(Os_XSigFunctionTableConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore3_FuncTable =
{
  /* .FunctionDescription = */
  {
    { Os_XSigRecv_ActivateTask }, /* OSServiceId_ActivateTask */
    { Os_XSigRecv_CancelAlarm }, /* OSServiceId_CancelAlarm */
    { Os_XSigRecv_ControlIdle }, /* OSServiceId_ControlIdle */
    { Os_XSigRecv_GetAlarm }, /* OSServiceId_GetAlarm */
    { Os_XSigRecv_GetApplicationState }, /* OSServiceId_GetApplicationState */
    { Os_XSigRecv_GetCounterValue }, /* OSServiceId_GetCounterValue */
    { Os_XSigRecv_GetErrorHookStackUsage }, /* OSServiceId_GetErrorHookStackUsage */
    { Os_XSigRecv_GetEvent }, /* OSServiceId_GetEvent */
    { Os_XSigRecv_GetISRStackUsage }, /* OSServiceId_GetISRStackUsage */
    { Os_XSigRecv_GetKernelStackUsage }, /* OSServiceId_GetKernelStackUsage */
    { Os_XSigRecv_GetProtectionHookStackUsage }, /* OSServiceId_GetProtectionHookStackUsage */
    { Os_XSigRecv_GetScheduleTableStatus }, /* OSServiceId_GetScheduleTableStatus */
    { Os_XSigRecv_GetShutdownHookStackUsage }, /* OSServiceId_GetShutdownHookStackUsage */
    { Os_XSigRecv_GetStartupHookStackUsage }, /* OSServiceId_GetStartupHookStackUsage */
    { Os_XSigRecv_GetTaskStackUsage }, /* OSServiceId_GetTaskStackUsage */
    { Os_XSigRecv_GetTaskState }, /* OSServiceId_GetTaskState */
    { Os_XSigRecv_HookCallCallback }, /* OSServiceId_HookCallCallback */
    { Os_XSigRecv_NextScheduleTable }, /* OSServiceId_NextScheduleTable */
    { Os_XSigRecv_SetAbsAlarm }, /* OSServiceId_SetAbsAlarm */
    { Os_XSigRecv_SetEvent }, /* OSServiceId_SetEvent */
    { Os_XSigRecv_SetRelAlarm }, /* OSServiceId_SetRelAlarm */
    { Os_XSigRecv_ShutdownAllCores }, /* OSServiceId_ShutdownAllCores */
    { Os_XSigRecv_StartScheduleTableAbs }, /* OSServiceId_StartScheduleTableAbs */
    { Os_XSigRecv_StartScheduleTableRel }, /* OSServiceId_StartScheduleTableRel */
    { Os_XSigRecv_StopScheduleTable }, /* OSServiceId_StopScheduleTable */
    { Os_XSigRecv_TerminateApplication }, /* OSServiceId_TerminateApplication */
    { NULL_PTR }
  }
};

/*! X-Signal ISR receive ports reference table: XSignalIsr_OsCore3 */
CONST(Os_XSigRecvPortConfigRefType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore3_PortRefs[OS_CFG_NUM_ISR_XSIGNALISR_OSCORE3_PORTS + 1u] =
{
  &OsCfg_XSig_XSignalIsr_OsCore3_Recv0,
  &OsCfg_XSig_XSignalIsr_OsCore3_Recv1,
  &OsCfg_XSig_XSignalIsr_OsCore3_Recv2,
  &OsCfg_XSig_XSignalIsr_OsCore3_Recv3,
  &OsCfg_XSig_XSignalIsr_OsCore3_Recv4,
  NULL_PTR
};

/*! X-Signal receiver ISRs reference table: OsCore3 */
OS_LOCAL CONST(Os_XSigIsrConfigRefType, OS_CONST) OsCfg_XSig_OsCore3_IsrRefs[OS_CFG_NUM_XSIG_OSCORE3_ISRS + 1u] =
{
  &OsCfg_Isr_XSignalIsr_OsCore3,
  NULL_PTR
};

/*! X-Signal configuration data: OsCore3 */
CONST(Os_XSigConfigType, OS_CONST) OsCfg_XSig_OsCore3 =
{
  /* .XSigSendPorts    = */ 
  {
    /* [0] = */ &OsCfg_XSig_OsCore3_Send3, /* OsCore0 */
    /* [1] = */ &OsCfg_XSig_OsCore3_Send2, /* OsCore1 */
    /* [2] = */ &OsCfg_XSig_OsCore3_Send1, /* OsCore2 */
    /* [3] = */ NULL_PTR, /* OsCore3 */
    /* [4] = */ &OsCfg_XSig_OsCore3_Send0, /* OsCore4 */
    /* [5] = */ &OsCfg_XSig_OsCore3_Send4 /* OsCore5 */
  },
  /* .XSigRecvIsrRefs  = */ OsCfg_XSig_OsCore3_IsrRefs,
  /* .XSigRecvIsrCount = */ (Os_ObjIdxType)OS_CFG_NUM_XSIG_OSCORE3_ISRS
};

#define OS_STOP_SEC_CORE3_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE4_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! X-Signal send port configuration data: OsCore4 -> OsCore3/XSignalIsr_OsCore3_Recv3 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore4_Send0 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore4_Send0_XSignalIsr_OsCore3_Recv3_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore4_Send0_XSignalIsr_OsCore3_Recv3_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore4_Send0_XSignalIsr_OsCore3_Recv3_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE4_SEND0_XSIGNALISR_OSCORE3_RECV3_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore3,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore3_Recv3,
  /* .SendCore    = */ &OsCfg_Core_OsCore4
};

/*! X-Signal send port configuration data: OsCore4 -> OsCore2/XSignalIsr_OsCore2_Recv3 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore4_Send1 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore4_Send1_XSignalIsr_OsCore2_Recv3_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore4_Send1_XSignalIsr_OsCore2_Recv3_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore4_Send1_XSignalIsr_OsCore2_Recv3_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE4_SEND1_XSIGNALISR_OSCORE2_RECV3_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore2,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore2_Recv3,
  /* .SendCore    = */ &OsCfg_Core_OsCore4
};

/*! X-Signal send port configuration data: OsCore4 -> OsCore1/XSignalIsr_OsCore1_Recv3 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore4_Send2 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore4_Send2_XSignalIsr_OsCore1_Recv3_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore4_Send2_XSignalIsr_OsCore1_Recv3_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore4_Send2_XSignalIsr_OsCore1_Recv3_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE4_SEND2_XSIGNALISR_OSCORE1_RECV3_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore1,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore1_Recv3,
  /* .SendCore    = */ &OsCfg_Core_OsCore4
};

/*! X-Signal send port configuration data: OsCore4 -> OsCore0/XSignalIsr_OsCore0_Recv3 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore4_Send3 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore4_Send3_XSignalIsr_OsCore0_Recv3_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore4_Send3_XSignalIsr_OsCore0_Recv3_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore4_Send3_XSignalIsr_OsCore0_Recv3_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE4_SEND3_XSIGNALISR_OSCORE0_RECV3_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore0,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore0_Recv3,
  /* .SendCore    = */ &OsCfg_Core_OsCore4
};

/*! X-Signal send port configuration data: OsCore4 -> OsCore5/XSignalIsr_OsCore5_Recv4 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore4_Send4 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore4_Send4_XSignalIsr_OsCore5_Recv4_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore4_Send4_XSignalIsr_OsCore5_Recv4_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore4_Send4_XSignalIsr_OsCore5_Recv4_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE4_SEND4_XSIGNALISR_OSCORE5_RECV4_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore5,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore5_Recv4,
  /* .SendCore    = */ &OsCfg_Core_OsCore4
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore4_Recv0 <- OsCore0 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore4_Recv0 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore0_Send0_XSignalIsr_OsCore4_Recv0_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore0_Send0_XSignalIsr_OsCore4_Recv0_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore0_Send0_XSignalIsr_OsCore4_Recv0_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE0_SEND0_XSIGNALISR_OSCORE4_RECV0_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore0_Send0
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore4_Recv1 <- OsCore1 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore4_Recv1 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore1_Send0_XSignalIsr_OsCore4_Recv1_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore1_Send0_XSignalIsr_OsCore4_Recv1_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore1_Send0_XSignalIsr_OsCore4_Recv1_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE1_SEND0_XSIGNALISR_OSCORE4_RECV1_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore1_Send0
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore4_Recv2 <- OsCore2 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore4_Recv2 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore2_Send0_XSignalIsr_OsCore4_Recv2_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore2_Send0_XSignalIsr_OsCore4_Recv2_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore2_Send0_XSignalIsr_OsCore4_Recv2_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE2_SEND0_XSIGNALISR_OSCORE4_RECV2_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore2_Send0
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore4_Recv3 <- OsCore3 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore4_Recv3 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore3_Send0_XSignalIsr_OsCore4_Recv3_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore3_Send0_XSignalIsr_OsCore4_Recv3_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore3_Send0_XSignalIsr_OsCore4_Recv3_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE3_SEND0_XSIGNALISR_OSCORE4_RECV3_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore3_Send0
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore4_Recv4 <- OsCore5 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore4_Recv4 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore5_Send0_XSignalIsr_OsCore4_Recv4_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore5_Send0_XSignalIsr_OsCore4_Recv4_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore5_Send0_XSignalIsr_OsCore4_Recv4_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE5_SEND0_XSIGNALISR_OSCORE4_RECV4_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore5_Send0
};

/*! X-Signal ISR function table: XSignalIsr_OsCore4 */
CONST(Os_XSigFunctionTableConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore4_FuncTable =
{
  /* .FunctionDescription = */
  {
    { Os_XSigRecv_ActivateTask }, /* OSServiceId_ActivateTask */
    { Os_XSigRecv_CancelAlarm }, /* OSServiceId_CancelAlarm */
    { Os_XSigRecv_ControlIdle }, /* OSServiceId_ControlIdle */
    { Os_XSigRecv_GetAlarm }, /* OSServiceId_GetAlarm */
    { Os_XSigRecv_GetApplicationState }, /* OSServiceId_GetApplicationState */
    { Os_XSigRecv_GetCounterValue }, /* OSServiceId_GetCounterValue */
    { Os_XSigRecv_GetErrorHookStackUsage }, /* OSServiceId_GetErrorHookStackUsage */
    { Os_XSigRecv_GetEvent }, /* OSServiceId_GetEvent */
    { Os_XSigRecv_GetISRStackUsage }, /* OSServiceId_GetISRStackUsage */
    { Os_XSigRecv_GetKernelStackUsage }, /* OSServiceId_GetKernelStackUsage */
    { Os_XSigRecv_GetProtectionHookStackUsage }, /* OSServiceId_GetProtectionHookStackUsage */
    { Os_XSigRecv_GetScheduleTableStatus }, /* OSServiceId_GetScheduleTableStatus */
    { Os_XSigRecv_GetShutdownHookStackUsage }, /* OSServiceId_GetShutdownHookStackUsage */
    { Os_XSigRecv_GetStartupHookStackUsage }, /* OSServiceId_GetStartupHookStackUsage */
    { Os_XSigRecv_GetTaskStackUsage }, /* OSServiceId_GetTaskStackUsage */
    { Os_XSigRecv_GetTaskState }, /* OSServiceId_GetTaskState */
    { Os_XSigRecv_HookCallCallback }, /* OSServiceId_HookCallCallback */
    { Os_XSigRecv_NextScheduleTable }, /* OSServiceId_NextScheduleTable */
    { Os_XSigRecv_SetAbsAlarm }, /* OSServiceId_SetAbsAlarm */
    { Os_XSigRecv_SetEvent }, /* OSServiceId_SetEvent */
    { Os_XSigRecv_SetRelAlarm }, /* OSServiceId_SetRelAlarm */
    { Os_XSigRecv_ShutdownAllCores }, /* OSServiceId_ShutdownAllCores */
    { Os_XSigRecv_StartScheduleTableAbs }, /* OSServiceId_StartScheduleTableAbs */
    { Os_XSigRecv_StartScheduleTableRel }, /* OSServiceId_StartScheduleTableRel */
    { Os_XSigRecv_StopScheduleTable }, /* OSServiceId_StopScheduleTable */
    { Os_XSigRecv_TerminateApplication }, /* OSServiceId_TerminateApplication */
    { NULL_PTR }
  }
};

/*! X-Signal ISR receive ports reference table: XSignalIsr_OsCore4 */
CONST(Os_XSigRecvPortConfigRefType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore4_PortRefs[OS_CFG_NUM_ISR_XSIGNALISR_OSCORE4_PORTS + 1u] =
{
  &OsCfg_XSig_XSignalIsr_OsCore4_Recv0,
  &OsCfg_XSig_XSignalIsr_OsCore4_Recv1,
  &OsCfg_XSig_XSignalIsr_OsCore4_Recv2,
  &OsCfg_XSig_XSignalIsr_OsCore4_Recv3,
  &OsCfg_XSig_XSignalIsr_OsCore4_Recv4,
  NULL_PTR
};

/*! X-Signal receiver ISRs reference table: OsCore4 */
OS_LOCAL CONST(Os_XSigIsrConfigRefType, OS_CONST) OsCfg_XSig_OsCore4_IsrRefs[OS_CFG_NUM_XSIG_OSCORE4_ISRS + 1u] =
{
  &OsCfg_Isr_XSignalIsr_OsCore4,
  NULL_PTR
};

/*! X-Signal configuration data: OsCore4 */
CONST(Os_XSigConfigType, OS_CONST) OsCfg_XSig_OsCore4 =
{
  /* .XSigSendPorts    = */ 
  {
    /* [0] = */ &OsCfg_XSig_OsCore4_Send3, /* OsCore0 */
    /* [1] = */ &OsCfg_XSig_OsCore4_Send2, /* OsCore1 */
    /* [2] = */ &OsCfg_XSig_OsCore4_Send1, /* OsCore2 */
    /* [3] = */ &OsCfg_XSig_OsCore4_Send0, /* OsCore3 */
    /* [4] = */ NULL_PTR, /* OsCore4 */
    /* [5] = */ &OsCfg_XSig_OsCore4_Send4 /* OsCore5 */
  },
  /* .XSigRecvIsrRefs  = */ OsCfg_XSig_OsCore4_IsrRefs,
  /* .XSigRecvIsrCount = */ (Os_ObjIdxType)OS_CFG_NUM_XSIG_OSCORE4_ISRS
};

#define OS_STOP_SEC_CORE4_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE5_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! X-Signal send port configuration data: OsCore5 -> OsCore4/XSignalIsr_OsCore4_Recv4 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore5_Send0 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore5_Send0_XSignalIsr_OsCore4_Recv4_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore5_Send0_XSignalIsr_OsCore4_Recv4_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore5_Send0_XSignalIsr_OsCore4_Recv4_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE5_SEND0_XSIGNALISR_OSCORE4_RECV4_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore4,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore4_Recv4,
  /* .SendCore    = */ &OsCfg_Core_OsCore5
};

/*! X-Signal send port configuration data: OsCore5 -> OsCore3/XSignalIsr_OsCore3_Recv4 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore5_Send1 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore5_Send1_XSignalIsr_OsCore3_Recv4_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore5_Send1_XSignalIsr_OsCore3_Recv4_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore5_Send1_XSignalIsr_OsCore3_Recv4_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE5_SEND1_XSIGNALISR_OSCORE3_RECV4_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore3,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore3_Recv4,
  /* .SendCore    = */ &OsCfg_Core_OsCore5
};

/*! X-Signal send port configuration data: OsCore5 -> OsCore2/XSignalIsr_OsCore2_Recv4 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore5_Send2 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore5_Send2_XSignalIsr_OsCore2_Recv4_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore5_Send2_XSignalIsr_OsCore2_Recv4_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore5_Send2_XSignalIsr_OsCore2_Recv4_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE5_SEND2_XSIGNALISR_OSCORE2_RECV4_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore2,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore2_Recv4,
  /* .SendCore    = */ &OsCfg_Core_OsCore5
};

/*! X-Signal send port configuration data: OsCore5 -> OsCore1/XSignalIsr_OsCore1_Recv4 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore5_Send3 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore5_Send3_XSignalIsr_OsCore1_Recv4_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore5_Send3_XSignalIsr_OsCore1_Recv4_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore5_Send3_XSignalIsr_OsCore1_Recv4_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE5_SEND3_XSIGNALISR_OSCORE1_RECV4_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore1,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore1_Recv4,
  /* .SendCore    = */ &OsCfg_Core_OsCore5
};

/*! X-Signal send port configuration data: OsCore5 -> OsCore0/XSignalIsr_OsCore0_Recv4 */
OS_LOCAL CONST(Os_XSigSendPortConfigType, OS_CONST) OsCfg_XSig_OsCore5_Send4 =
{
  /* .SendChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore5_Send4_XSignalIsr_OsCore0_Recv4_Send_Dyn,
    /* .Receive    = */ &OsCfg_XSig_OsCore5_Send4_XSignalIsr_OsCore0_Recv4_Recv_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore5_Send4_XSignalIsr_OsCore0_Recv4_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE5_SEND4_XSIGNALISR_OSCORE0_RECV4_BUFFER
  },
  /* .XSigIsr     = */ &OsCfg_Isr_XSignalIsr_OsCore0,
  /* .RecvPort    = */ &OsCfg_XSig_XSignalIsr_OsCore0_Recv4,
  /* .SendCore    = */ &OsCfg_Core_OsCore5
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore5_Recv0 <- OsCore0 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore5_Recv0 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore0_Send4_XSignalIsr_OsCore5_Recv0_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore0_Send4_XSignalIsr_OsCore5_Recv0_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore0_Send4_XSignalIsr_OsCore5_Recv0_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE0_SEND4_XSIGNALISR_OSCORE5_RECV0_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore0_Send4
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore5_Recv1 <- OsCore1 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore5_Recv1 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore1_Send4_XSignalIsr_OsCore5_Recv1_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore1_Send4_XSignalIsr_OsCore5_Recv1_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore1_Send4_XSignalIsr_OsCore5_Recv1_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE1_SEND4_XSIGNALISR_OSCORE5_RECV1_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore1_Send4
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore5_Recv2 <- OsCore2 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore5_Recv2 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore2_Send4_XSignalIsr_OsCore5_Recv2_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore2_Send4_XSignalIsr_OsCore5_Recv2_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore2_Send4_XSignalIsr_OsCore5_Recv2_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE2_SEND4_XSIGNALISR_OSCORE5_RECV2_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore2_Send4
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore5_Recv3 <- OsCore3 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore5_Recv3 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore3_Send4_XSignalIsr_OsCore5_Recv3_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore3_Send4_XSignalIsr_OsCore5_Recv3_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore3_Send4_XSignalIsr_OsCore5_Recv3_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE3_SEND4_XSIGNALISR_OSCORE5_RECV3_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore3_Send4
};

/*! X-Signal receive port configuration data: XSignalIsr_OsCore5_Recv4 <- OsCore4 */
OS_LOCAL CONST(Os_XSigRecvPortConfigType, OS_CONST) OsCfg_XSig_XSignalIsr_OsCore5_Recv4 =
{
  /* .RecvChannel = */
  {
    /* .Dyn        = */ &OsCfg_XSig_OsCore4_Send4_XSignalIsr_OsCore5_Recv4_Recv_Dyn,
    /* .Send       = */ &OsCfg_XSig_OsCore4_Send4_XSignalIsr_OsCore5_Recv4_Send_Dyn,
    /* .Buffer     = */ OsCfg_XSig_OsCore4_Send4_XSignalIsr_OsCore5_Recv4_Buffer_Dyn,
    /* .BufferSize = */ (Os_XSigBufferIdxType)OS_CFG_SIZE_OSCORE4_SEND4_XSIGNALISR_OSCORE5_RECV4_BUFFER
  },
  /* .SendPort    = */ &OsCfg_XSig_OsCore4_Send4
};

/*! X-Signal ISR function table: XSignalIsr_OsCore5 */
CONST(Os_XSigFunctionTableConfigType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore5_FuncTable =
{
  /* .FunctionDescription = */
  {
    { Os_XSigRecv_ActivateTask }, /* OSServiceId_ActivateTask */
    { Os_XSigRecv_CancelAlarm }, /* OSServiceId_CancelAlarm */
    { Os_XSigRecv_ControlIdle }, /* OSServiceId_ControlIdle */
    { Os_XSigRecv_GetAlarm }, /* OSServiceId_GetAlarm */
    { Os_XSigRecv_GetApplicationState }, /* OSServiceId_GetApplicationState */
    { Os_XSigRecv_GetCounterValue }, /* OSServiceId_GetCounterValue */
    { Os_XSigRecv_GetErrorHookStackUsage }, /* OSServiceId_GetErrorHookStackUsage */
    { Os_XSigRecv_GetEvent }, /* OSServiceId_GetEvent */
    { Os_XSigRecv_GetISRStackUsage }, /* OSServiceId_GetISRStackUsage */
    { Os_XSigRecv_GetKernelStackUsage }, /* OSServiceId_GetKernelStackUsage */
    { Os_XSigRecv_GetProtectionHookStackUsage }, /* OSServiceId_GetProtectionHookStackUsage */
    { Os_XSigRecv_GetScheduleTableStatus }, /* OSServiceId_GetScheduleTableStatus */
    { Os_XSigRecv_GetShutdownHookStackUsage }, /* OSServiceId_GetShutdownHookStackUsage */
    { Os_XSigRecv_GetStartupHookStackUsage }, /* OSServiceId_GetStartupHookStackUsage */
    { Os_XSigRecv_GetTaskStackUsage }, /* OSServiceId_GetTaskStackUsage */
    { Os_XSigRecv_GetTaskState }, /* OSServiceId_GetTaskState */
    { Os_XSigRecv_HookCallCallback }, /* OSServiceId_HookCallCallback */
    { Os_XSigRecv_NextScheduleTable }, /* OSServiceId_NextScheduleTable */
    { Os_XSigRecv_SetAbsAlarm }, /* OSServiceId_SetAbsAlarm */
    { Os_XSigRecv_SetEvent }, /* OSServiceId_SetEvent */
    { Os_XSigRecv_SetRelAlarm }, /* OSServiceId_SetRelAlarm */
    { Os_XSigRecv_ShutdownAllCores }, /* OSServiceId_ShutdownAllCores */
    { Os_XSigRecv_StartScheduleTableAbs }, /* OSServiceId_StartScheduleTableAbs */
    { Os_XSigRecv_StartScheduleTableRel }, /* OSServiceId_StartScheduleTableRel */
    { Os_XSigRecv_StopScheduleTable }, /* OSServiceId_StopScheduleTable */
    { Os_XSigRecv_TerminateApplication }, /* OSServiceId_TerminateApplication */
    { NULL_PTR }
  }
};

/*! X-Signal ISR receive ports reference table: XSignalIsr_OsCore5 */
CONST(Os_XSigRecvPortConfigRefType, OS_CONST) OsCfg_Isr_XSignalIsr_OsCore5_PortRefs[OS_CFG_NUM_ISR_XSIGNALISR_OSCORE5_PORTS + 1u] =
{
  &OsCfg_XSig_XSignalIsr_OsCore5_Recv0,
  &OsCfg_XSig_XSignalIsr_OsCore5_Recv1,
  &OsCfg_XSig_XSignalIsr_OsCore5_Recv2,
  &OsCfg_XSig_XSignalIsr_OsCore5_Recv3,
  &OsCfg_XSig_XSignalIsr_OsCore5_Recv4,
  NULL_PTR
};

/*! X-Signal receiver ISRs reference table: OsCore5 */
OS_LOCAL CONST(Os_XSigIsrConfigRefType, OS_CONST) OsCfg_XSig_OsCore5_IsrRefs[OS_CFG_NUM_XSIG_OSCORE5_ISRS + 1u] =
{
  &OsCfg_Isr_XSignalIsr_OsCore5,
  NULL_PTR
};

/*! X-Signal configuration data: OsCore5 */
CONST(Os_XSigConfigType, OS_CONST) OsCfg_XSig_OsCore5 =
{
  /* .XSigSendPorts    = */ 
  {
    /* [0] = */ &OsCfg_XSig_OsCore5_Send4, /* OsCore0 */
    /* [1] = */ &OsCfg_XSig_OsCore5_Send3, /* OsCore1 */
    /* [2] = */ &OsCfg_XSig_OsCore5_Send2, /* OsCore2 */
    /* [3] = */ &OsCfg_XSig_OsCore5_Send1, /* OsCore3 */
    /* [4] = */ &OsCfg_XSig_OsCore5_Send0, /* OsCore4 */
    /* [5] = */ NULL_PTR /* OsCore5 */
  },
  /* .XSigRecvIsrRefs  = */ OsCfg_XSig_OsCore5_IsrRefs,
  /* .XSigRecvIsrCount = */ (Os_ObjIdxType)OS_CFG_NUM_XSIG_OSCORE5_ISRS
};

#define OS_STOP_SEC_CORE5_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: Os_XSignal_Lcfg.c
 *********************************************************************************************************************/
