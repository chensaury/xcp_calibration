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
 *            Module: Xcp
 *           Program: MSR_Vector_SLP4
 *          Customer: Aptiv (China) Technology Company Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Aurix 2G/TC397 B-Step
 *    License Scope : The usage is restricted to CBD1900078_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanXcp_Lcfg.c
 *   Generation Time: 2024-01-08 16:27:29
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

	

#define CANXCP_LCFG_SOURCE

#include "CanXcp_Lcfg.h"

#include "CanIf.h" /* for CanIf symbolic name value defines */

 

/* -----------------------------------------------------------------------------
    &&&~ CanXcp_PduField - 
 ----------------------------------------------------------------------------- */
#define CANXCP_START_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

CONST(CanXcp_XcpPduType, CANXCP_PBCFG) CanXcp_PduIdField[CANXCP_NUMBER_OF_CHANNELS] =
{
  {
    XcpConf_XcpRxPdu_XCP_S_oCAN00_aa3b84ab_Rx, 
    XcpConf_XcpTxPdu_XCP_R_oCAN00_31486e7f_Tx, 
    CanIfConf_CanIfTxPduCfg_XCP_R_oCAN00_267e057e_Tx
  } /*  CanXcpRxPduId CanXcpTxPduId CanIfTxPduId  */ 
}; 

/* -----------------------------------------------------------------------------
    &&&~ CanXcp_Config - 
 ----------------------------------------------------------------------------- */

CONST(CanXcp_ConfigType, CANXCP_PBCFG) CanXcp_Config = 
{
  CanXcp_PduIdField,
  NULL_PTR,
  1
};

#define CANXCP_STOP_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"


