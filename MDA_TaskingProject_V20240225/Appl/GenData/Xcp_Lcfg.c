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
 *              File: Xcp_Lcfg.c
 *   Generation Time: 2024-01-08 16:27:30
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

    
#define XCP_LCFG_SOURCE
    
#include "Xcp.h"

/*lint -e451 */ /* Suppress ID451 because MemMap.h cannot use a include guard */

#if ( XCP_DAQ == STD_ON )
# define XCP_START_SEC_VAR_NOCACHE_NOINIT_32BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h"

XCP_LOCAL VAR(uint8, XCP_VAR_NOINIT_NOCACHE) Xcp_SendQueue_Core0[XCP_NUMBER_OF_CHANNELS][256uL];

# define XCP_STOP_SEC_VAR_NOCACHE_NOINIT_32BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h"
#endif

#define XCP_START_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

#if( XCP_DAQ == STD_ON )
CONSTP2VAR(uint8, XCP_CONST, XCP_VAR_NOINIT) Xcp_SendQueueRef[XCP_NUMBER_OF_CORES] =
{
  &Xcp_SendQueue_Core0[0][0]
};

CONST(uint32, XCP_CONST) Xcp_SendQueueSize[XCP_NUMBER_OF_CORES] =
{
  sizeof(Xcp_SendQueue_Core0[0])
};

CONST(Xcp_ECcIDType, XCP_CONST) Xcp_ECcIdMapping[XCP_MAX_EVENT] = /* PRQA S 1533 */ /* MD_XCP_1533 */
{
  {
    0u, 
    0u
  }, 
  {
    0u, 
    0u
  }, 
  {
    0u, 
    0u
  }
};
#endif

CONST(Xcp_TlApiType, XCP_CONST) Xcp_TlApi[1] = 
{
  {
    CanXcp_Send /*  ApplXcpSend  */ , 
    CanXcp_SendFlush /*  ApplXcpSendFlush  */ , 
    CanXcp_TLService /*  ApplXcpTLService  */ 
  }
};

/* Events */
CONST(uint8, XCP_CONST) kXcpEventName_0[20] = "XcpEventChannel50ms";
CONST(uint8, XCP_CONST) kXcpEventName_1[20] = "XcpEventChannel10ms";
CONST(uint8, XCP_CONST) kXcpEventName_2[21] = "XcpEventChannel100ms";

CONSTP2CONST(uint8, XCP_CONST, XCP_CONST) kXcpEventName[3] = /* PRQA S 1533 */ /* MD_XCP_1533 */
{
  &kXcpEventName_0[0], 
  &kXcpEventName_1[0], 
  &kXcpEventName_2[0]
};
CONST(uint8, XCP_CONST) kXcpEventNameLength[3] = /* PRQA S 1533 */ /* MD_XCP_1533 */ 
{
  19u, 
  19u, 
  20u
};
CONST(uint8, XCP_CONST) kXcpEventCycle[3] = /* PRQA S 1533 */ /* MD_XCP_1533 */ 
{
  50u, 
  10u, 
  100u
};
CONST(uint8, XCP_CONST) kXcpEventUnit[3] = /* PRQA S 1533 */ /* MD_XCP_1533 */
{
  XCP_DAQ_TIMESTAMP_UNIT_1MS, 
  XCP_DAQ_TIMESTAMP_UNIT_1MS, 
  XCP_DAQ_TIMESTAMP_UNIT_1MS
}; 
CONST(uint8, XCP_CONST) kXcpEventDirection[3] = /* PRQA S 1533 */ /* MD_XCP_1533 */
{
  XCP_DAQ_EVENT_DIRECTION_DAQ, 
  XCP_DAQ_EVENT_DIRECTION_DAQ, 
  XCP_DAQ_EVENT_DIRECTION_DAQ
}; 
CONST(uint8, XCP_CONST) kXcpEventNumDaq[3] = /* PRQA S 1533 */ /* MD_XCP_1533 */
{
  0xFFu, 
  0xFFu, 
  0xFFu
}; 
 
/* Flash programming */

#define XCP_STOP_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

