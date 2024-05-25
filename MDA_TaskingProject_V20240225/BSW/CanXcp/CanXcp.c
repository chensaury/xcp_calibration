/******************************************************************************
 | Project Name:   XCP on CAN Transport Layer for AUTOSAR CanIf Release 3.0
 |    File Name:   CanXcp.c
 |
 |  Description:
 |    Adaption component for the XCP Protocol Layer interface
 |    and AUTOSAR CAN Interface.
 |
 |  Limitations:
 |    - Detection of all XCP slaves within a CAN network is not supported
 |        ( GET_SLAVE_ID )
 |    - Assignment of CAN identifiers to DAQ lists or STIM is not supported
 |        ( GET_DAQ_ID, SET_DAQ_ID )
 |
 |------------------------------------------------------------------------------
 |               C O P Y R I G H T
 |------------------------------------------------------------------------------
 | Copyright (c) 2016 by Vector Informatik GmbH.          All rights reserved.
 |
 |       This software is copyright protected and 
 |       proporietary to Vector Informatik GmbH.
 |       Vector Informatik GmbH grants to you only
 |       those rights as set out in the license conditions.
 |       All other rights remain with Vector Informatik GmbH.
 | 
 |       Diese Software ist urheberrechtlich geschuetzt. 
 |       Vector Informatik GmbH raeumt Ihnen an dieser Software nur 
 |       die in den Lizenzbedingungen ausdruecklich genannten Rechte ein.
 |       Alle anderen Rechte verbleiben bei Vector Informatik GmbH.
 |
 |------------------------------------------------------------------------------
 |               A U T H O R   I D E N T I T Y
 |------------------------------------------------------------------------------
 | Initials     Name                      Company
 | --------     ---------------------     --------------------------------------
 | Tri          Frank Triem               Vector Informatik GmbH
 | Svh          Sven Hesselmann           Vector Informatik GmbH
 |  Hr          Andreas Herkommer         Vector Informatik GmbH
 | Dod          O'Donnell Dennis          Vector CANtech
 |------------------------------------------------------------------------------
 |               R E V I S I O N   H I S T O R Y
 |------------------------------------------------------------------------------
 |  Date       Version  Author  Description
 | ----------  -------  ------  ------------------------------------------------
 | 2007-01-18  1.00.00   Tri    ESCAN00017515: Creation of component based on Cp_XcpOnCan
 | 2007-01-29  1.01.00   Tri    ESCAN00019255: Compiler error: expression must have a constant value
 | 2008-04-04  1.02.00   Svh    ESCAN00023286: XCP will be reinitialized after transmission
 | 2008-07-25  1.03.00   Svh    ESCAN00028749: Post build support added
 |                              ESCAN00018171: Support BSW Scheduler
 | 2009-09-07  1.03.01    Hr    ESCAN00037598: Memory Mapping: Wrong PB section name
 | 2009-10-13             Hr    ESCAN00038409: Wrong variable section for compiler abstraction
 | 2009-11-25             Hr    ESCAN00039395: Support Multiple Identity
 | 2009-12-02  1.03.02    Hr    ESCAN00039524: Compiler warning due to missing define 'ON'
 | 2009-12-16  1.03.03    Hr    ESCAN00039803: Version information mismatch
 | 2009-12-22  1.03.04    Hr    ESCAN00039896: reject "master" message for inactive identities (physical multiple ECU)
 | 2010-01-14  1.03.05    Hr    ESCAN00040111: Support Multiple Identity by selectable Post-Build
 |                        Dod   ESCAN00040113: Support for address doubling in CANape for DSP micros
 | 2010-07-30  1.03.06    Hr    ESCAN00044364: Missing Memory mapping sections in CanXcp_MemMap.inc
 | 2010-08-13  1.04.00    Hr    ESCAN00041935: Add feature to disable XcpOnCanAsr in serial production ECUs
 | 2010-08-13                   ESCAN00043931: Add support for XCP measurement during bus off phases
 | 2010-08-25                   ESCAN00040120: Support MultiChannel
 | 2010-09-24  1.04.01    Hr    ESCAN00045559: Compile Error: Enum type in CanXcp_Types.h wrong
 |                              ESCAN00045562: Compile Error: Wrong code section naming
 | 2010-11-03  1.04.02    Hr    ESCAN00046218: Compiler Abstraction not used for all pointer typecasts
 |                              ESCAN00046234: Adapt AUTOSAR version check
 | 2011-01-04  1.05.00    Hr    ESCAN00046303: AR3-297 AR3-894: Support PduInfoType instead of the DataPtr
 |                              ESCAN00047329: Adapt MainFunction for usage with IdentityManagerConfig
 |                              ESCAN00047694: Development Error Detection not implemented
 | 2011-02-28  1.05.01    Hr    ESCAN00048951: Compiler error in CanXcp_Control
 | 2011-03-03  1.05.02    Hr    ESCAN00048789: Frames can get lost in case of CAN Bus Off
 | 2011-03-21  1.06.00    Hr    ESCAN00049424: Support Monitoring Hooks for AUTOSAR 4
 | 2011-08-24  1.06.01    Hr    ESCAN00052955: Wrong return type for CanXcp_Transmit
 | 2011-12-01  1.06.02    Hr    ESCAN00053422: AR3-2069: Remove non-SchM code for critical section handling
 | 2012-06-29  1.06.03    Hr    ESCAN00059770: DET check in CanXcp_RxIndication not working correctly
 |                        Hr    ESCAN00060169: Compile error if GENy option "Set PduMode Support" is disabled
 |                        Hr    ESCAN00060938: Support Cfg5
 |                        Hr    ESCAN00061136: Support new XcpGetSessionStatus API
 | 2012-09-06  1.06.04    Hr    ESCAN00061241: AR3 compile error: Xcp.h included instead of XcpProf.h
 | 2012-10-18  1.07.00    Hr    ESCAN00062360: Add module specific define
 |                              ESCAN00060584: AR3-2446: Implement all necessary countermeasures for SilentBSW
 |                              ESCAN00060552: AR3-2443: Implement Silent Checks in BSW module code
 |                              ESCAN00057331: AR3-2374: Implement Silent BSW
 |                              ESCAN00061038: AR3-2378: Implement AMD timemeasurement support
 | 2012-12-05  1.07.01    Hr    ESCAN00063553: Compiler error: When DET is disabled
 |                              ESCAN00063714: Optimization of Stack usage
 | 2013-01-21  1.08.00    Hr    ESCAN00064390: Create AUTOSAR 4.0 branch
 |                        Hr    ESCAN00071289: Rename generated Send function to have the same ending for all transport layers
 |                        Hr    ESCAN00071290: Remove AUTOSAR 4 Monitoring Hooks from AUTOSAR3 implementation
 | 2013-04-21  1.08.01    Hr    ESCAN00066897: Add memmap section for unspecified CONST data
 | 2013-09-12  1.08.02    Hr    ESCAN00066736: CanXcp_GetVersionInfo returns module ID 0xFF
 |                              ESCAN00066974: MISRA deviation: MISRA-C:2004 Rules 11.5, 19.4, 19.7,
 |                                             19.10, 8.12, 18.4 in CanXcp.c, CanXcp_Cfg.h and CanXcp_Types.h
 | 2013-09-30             Hr    ESCAN00066471: Multi-Config: relative network handle used for CanXcp_SetPduMode
 | 2013-10-22  1.08.03   Ore    -              Updated revision history and ALM filter options
 | 2014-07-21  1.09.00    Hr    ESCAN00076910: CanXcp not communicating in multichannel systems where CanXcp is not active on all channels
 |             1.09.00    Hr    ESCAN00076497: AR4-720: Support CAN FD Mode 2 for communication and diagnostics
 |             1.09.00   Ore    ESCAN00076847: AR4-698: Post-Build Selectable (Identity Manager)
 | 2015-05-07  1.10.00    Hr    ESCAN00082875: Support TxConfirmation timeout timer
 |                              ESCAN00081267: If Variable DLC is deactivated the data length is fixed to 8
 | 2015-11-12  1.10.01    Hr    ESCAN00086395: FEAT-1357: SafeXCP
 | 2016-08-31  2.00.00    Hr    ESCAN00091770: FEAT-1980: Add Multi Client / Multi Connection support
 |                              ESCAN00092155: Safe deactivation does not consider CanXcp_Init
 |                              ESCAN00092154: Safe deactivation shall be performed before DET checks or anything
 |*****************************************************************************/

#define CANXCP_SOURCE

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "CanXcp.h"           /* Include header of XCP on CAN Transport Layer */
#if defined (CANXCP_CONFIGURATOR) && (CANXCP_CONFIGURATOR == 5)
  #include "Xcp.h"                    /* Include header of XCP Protocol Layer */
#else
  #include "Xcp.h"                    /* Include header of XCP Protocol Layer */
#endif
#include "CanIf.h"                                   /* Include CAN Interface */

#if ( CANXCP_DEV_ERROR_DETECT == STD_ON )
  #include "Det.h"                        /* Include Diagnostic Event Manager */
#endif

#if defined (CANXCP_CONFIGURATOR) && (CANXCP_CONFIGURATOR == 5)
  #include "SchM_Xcp.h"
#endif

#if defined ( CANXCP_AMD_RUNTIME_MEASUREMENT ) && ( CANXCP_AMD_RUNTIME_MEASUREMENT == STD_ON )
  #include "AmdRtm.h"
#endif


/******************************************************************************/
/* Version check                                                              */
/******************************************************************************/
#if ( CP_XCPONCANASR_VERSION != 0x0200u )
  #error "Source and Header file are inconsistent!"
#endif
#if ( CP_XCPONCANASR_RELEASE_VERSION != 0x00u )
  #error "Source and Header file are inconsistent!"
#endif

#if ( CANXCP_TPS_MAJOR_VERSION != 0x02u )
# error "Source and Header file CanXcp_Types.h are inconsistent (CANXCP_TPS_MAJOR_VERSION)!"
#endif
#if ( CANXCP_TPS_MINOR_VERSION != 0x00u )
# error "Source and Header file CanXcp_Types.h are inconsistent (CANXCP_TPS_MINOR_VERSION)!"
#endif
#if ( CANXCP_TPS_PATCH_VERSION != 0x00u )
# error "Source and Header file CanXcp_Types.h are inconsistent (CANXCP_TPS_PATCH_VERSION)!"
#endif


#if defined ( CANIF_VENDOR_ID )
# if (CANIF_VENDOR_ID == CANXCP_VENDOR_ID)
#   if defined(CANIF_AR_MAJOR_VERSION) && defined(CANIF_AR_MINOR_VERSION)
#     if((CANIF_AR_MAJOR_VERSION != 0x04u) || (CANIF_AR_MINOR_VERSION != 0x00u))
#      error "Imported module has incompatible AR version - expected CANIF version is 0x04u.0x00u \
                                                      (CANIF_AR_MAJOR_VERSION.CANIF_AR_MINOR_VERSION)."
#     endif
#   endif
# endif
#endif

/******************************************************************************/
/* Defintions                                                                 */
/******************************************************************************/
/* States of CanXcp_SendWithoutQueueState */
#define CANXCP_MSG_IDLE           0
#define CANXCP_MSG_PENDING        1

/* PRQA S 3453 27 */ /*  MD_MSR_19.7 */
#if defined ( CANXCP_MULTI_CHANNEL_ENABLED )
  #define CanXcp_GetRxPduId()             CanXcp_RxPduId
  #if ( CanXcp_IsPostbuild() )
    #define CanXcp_GetTxPduIdIdx(idx)     CanXcp_ConfigurationAccess(CanXcp_XcpPduPtr[idx].CanIfTxPduId)
    #define CanXcp_GetTxConfPduIdIdx(idx) CanXcp_ConfigurationAccess(CanXcp_XcpPduPtr[idx].CanXcpTxPduId)
    #define CanXcp_GetRxPduIdIdx(idx)     CanXcp_ConfigurationAccess(CanXcp_XcpPduPtr[idx].CanXcpRxPduId)
    #define CanXcp_GetChHandle(NwH)       CanXcp_ConfigurationAccess(CanXcp_NwHMappingPtr[NwH])
  #else
    #define CanXcp_GetTxPduIdIdx(idx)     CanXcp_PduIdField[idx].CanIfTxPduId
    #define CanXcp_GetTxConfPduIdIdx(idx) CanXcp_PduIdField[idx].CanXcpTxPduId
    #define CanXcp_GetRxPduIdIdx(idx)     CanXcp_PduIdField[idx].CanXcpRxPduId
    #define CanXcp_GetChHandle(NwH)       CanXcp_NwHMapping[NwH]
  #endif
#else
  #if ( CanXcp_IsPostbuild() )
    #define CanXcp_GetTxPduIdIdx(idx)     CanXcp_ConfigurationAccess(CanXcp_XcpPduPtr[idx].CanIfTxPduId)
    #define CanXcp_GetTxConfPduIdIdx(idx) CanXcp_ConfigurationAccess(CanXcp_XcpPduPtr[idx].CanXcpTxPduId)
    #define CanXcp_GetRxPduId()           CanXcp_ConfigurationAccess(CanXcp_XcpPduPtr[0].CanXcpRxPduId)
    #define CanXcp_GetRxPduIdIdx(idx)     CanXcp_ConfigurationAccess(CanXcp_XcpPduPtr[idx].CanXcpRxPduId)
    #define CanXcp_GetChHandle(NwH)       CanXcp_ConfigurationAccess(CanXcp_NwHMappingPtr[NwH])
  #else
    #define CanXcp_GetTxPduIdIdx(idx)     CanXcp_PduIdField[idx].CanIfTxPduId
    #define CanXcp_GetTxConfPduIdIdx(idx) CanXcp_PduIdField[idx].CanXcpTxPduId
    #define CanXcp_GetRxPduId()           CanXcp_PduIdField[0].CanXcpRxPduId
    #define CanXcp_GetRxPduIdIdx(idx)     CanXcp_PduIdField[idx].CanXcpRxPduId
    #define CanXcp_GetChHandle(NwH)       CanXcp_NwHMapping[NwH]
  #endif
#endif

/******************************************************************************/
/* Macros                                                                     */
/******************************************************************************/
/***************************************************************************************************/
/* General definition of checking macros */
# define CanXcp_CheckErrorReturnVoid(cond, api, err)        \
{ if(!(cond)){                                           \
    CanXcp_CallDetReportError((api), (err));                \
    return;                                              \
}} /* PRQA S 3458 */ /* MD_MSR_19.4 */

# define CanXcp_CheckErrorReturnValue(cond, api, err, ret)  \
{ if(!(cond)){                                           \
    CanXcp_CallDetReportError((api), (err));                \
    return(ret);                                         \
}} /* PRQA S 3458 */ /* MD_MSR_19.4 */

# define CanXcp_CheckErrorContinue(cond, api, err)          \
{ if(!(cond)){                                           \
    CanXcp_CallDetReportError((api), (err));                \
}} /* PRQA S 3458 */ /* MD_MSR_19.4 */

/***************************************************************************************************/
/* Macros for DET abstraction */
#if(CANXCP_DEV_ERROR_DETECT == STD_ON)
  # define CanXcp_CheckDetErrorReturnVoid(cond, api, err)       CanXcp_CheckErrorReturnVoid((cond), (api), (err)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
  # define CanXcp_CheckDetErrorReturnValue(cond, api, err, ret) CanXcp_CheckErrorReturnValue((cond), (api), (err), (ret)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
  # define CanXcp_CheckDetErrorContinue(cond, api, err)         CanXcp_CheckErrorContinue((cond), (api), (err)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
  # define CanXcp_CallDetReportError(api, err)                  (void)Det_ReportError(CANXCP_MODULE_ID, 0u, (api), (err)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#else
  # define CanXcp_CheckDetErrorReturnVoid(cond, api, err) /* PRQA S 3453 */ /* MD_MSR_19.7 */
  # define CanXcp_CheckDetErrorReturnValue(cond, api, err, ret) /* PRQA S 3453 */ /* MD_MSR_19.7 */
  # define CanXcp_CheckDetErrorContinue(cond, api, err) /* PRQA S 3453 */ /* MD_MSR_19.7 */
  # define CanXcp_CallDetReportError(api, err) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif

/***************************************************************************************************/
/* Macros for SBSW check abstraction */
#if(CANXCP_SILENT_CHECK == STD_ON)
  # define CanXcp_SilentBswCheckErrorReturnVoid(cond, api, err)       CanXcp_CheckErrorReturnVoid( (cond), (api), (err)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
  # define CanXcp_SilentBswCheckErrorReturnValue(cond, api, err, ret) CanXcp_CheckErrorReturnValue( (cond), (api), (err), (ret)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#else
  # define CanXcp_SilentBswCheckErrorReturnVoid(cond, api, err)                \
  CanXcp_CheckDetErrorReturnVoid( (cond), (api), (err) ) /* PRQA S 3453 */ /* MD_MSR_19.7 */
  # define CanXcp_SilentBswCheckErrorReturnValue(cond, api, err, ret)          \
  CanXcp_CheckDetErrorReturnValue( (cond), (api), (err), (ret) ) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif 


/*******************************************************************************
 * Types
*******************************************************************************/
#define CANXCP_MAX(a, b)   (((a) > (b)) ? (a) : (b)) /* PRQA S 3453 */ /* MD_MSR_19.7 */

typedef union { /* PRQA S 0750 */ /* MD_MSR_18.4 */
  uint8  b[CANXCP_MAX(kCanXcpMaxCTO, kCanXcpMaxDTO)];
  uint16 w[CANXCP_MAX(kCanXcpMaxCTO, kCanXcpMaxDTO)/2];
  uint32 dw[CANXCP_MAX(kCanXcpMaxCTO, kCanXcpMaxDTO)/4];
} tCanXcpXto; /* PRQA S 3448 */ /* MD_CanXcp_3448 */

/* Define AUTOSAR types if not defined yet */
#if defined ( STATIC )
#else
  #define STATIC static
#endif

/*******************************************************************************
 * Data definitions
*******************************************************************************/
/* 
  State of CAN message, required to send without any queue.
  (requested to send via CanXcp_Send).
  These variables are initialized inCanXcp_Init().
*/
#if ( CANXCP_ENABLE_CONTROL == STD_ON )
# define CANXCP_START_SEC_VAR_INIT_UNSPECIFIED_SAFE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* TL Enable/Disable state */
VAR(uint8, CANXCP_VAR_INIT) CanXcp_ControlState = kXcponCan_Control_Enable;

# define CANXCP_STOP_SEC_VAR_INIT_UNSPECIFIED_SAFE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif

#define CANXCP_START_SEC_VAR_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if ( CANXCP_DEV_ERROR_DETECT == STD_ON )
STATIC volatile VAR(uint8, CANXCP_VAR_INIT) CanXcp_InitializationState = CANXCP_UNINIT;
#endif

#if ( CANXCP_ENABLE_CONTROL == STD_ON )
VAR(uint8, CANXCP_VAR_INIT) CanXcp_ControlDeniedCount = 0; /* PRQA S 3408 */ /* MD_Xcp_3408 */
#endif

#define CANXCP_STOP_SEC_VAR_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define CANXCP_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

STATIC VAR(uint8, CANXCP_VAR_NOINIT) CanXcp_SendWithoutQueueState[CANXCP_NUMBER_OF_CHANNELS];

#define CANXCP_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define CANXCP_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if ( CANXCP_ENABLE_PDUMODE == STD_ON )
STATIC VAR(CanXcp_PduSetModeType, CANXCP_VAR_NOINIT) CanXcp_PduState[CANXCP_NUMBER_OF_CHANNELS];
#endif
STATIC VAR(PduInfoType, CANXCP_VAR_NOINIT) CanXcp_QueuedPduInfo[CANXCP_NUMBER_OF_CHANNELS];
STATIC VAR(CanXcp_TimeoutTimerType, CANXCP_VAR_NOINIT) CanXcp_ConfTimeoutTimer[CANXCP_NUMBER_OF_CHANNELS];
STATIC VAR(tCanXcpXto, CANXCP_VAR_NOINIT) CanXcp_PduBuffer; /* PRQA S 0759 */ /* MD_MSR_18.4 */ /* PRQA S 3218 */ /* MD_CanXcp_3218 */

#define CANXCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#if defined ( CANXCP_MULTI_CHANNEL_ENABLED )
/* global variables */
# define CANXCP_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if ( XCP_NUMBER_OF_CHANNELS <= 1 )
STATIC VAR(PduIdType, CANXCP_VAR_NOINIT) CanXcp_RxPduId;
#endif

# define CANXCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#endif

#if ( CanXcp_IsPostbuild() )
# define CANXCP_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

STATIC P2CONST(CanXcp_ConfigType, CANXCP_VAR_NOINIT, CANXCP_PBCFG) CanXcp_Configuration;

# define CANXCP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
# define CanXcp_ConfigurationAccess(a)  (CanXcp_Configuration->a) /* PRQA S 3410 */ /* MD_CanXcp_3410 */ /* PRQA S 3453 */ /* MD_MSR_19.7 */
#else
# define CanXcp_ConfigurationAccess(a)  (CanXcp_Config.a) /* PRQA S 3410 */ /* MD_CanXcp_3410 */ /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif

/****************************************************************************/
/* External ROM Data                                                        */
/****************************************************************************/

#define CANXCP_START_SEC_CONST_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Global constants with XCP Transport Layer for CAN main and subversion */
CONST(uint8, CANXCP_CONST) kXcpOnCanAsrMainVersion    = (uint8)(CP_XCPONCANASR_VERSION >> 8);
CONST(uint8, CANXCP_CONST) kXcpOnCanSubAsrVersion     = (uint8)(CP_XCPONCANASR_VERSION & 0x00ff);
CONST(uint8, CANXCP_CONST) kXcpOnCanAsrReleaseVersion = (uint8)(CP_XCPONCANASR_RELEASE_VERSION);

#define CANXCP_STOP_SEC_CONST_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/******************************************************************************
*
*
*           Code Part for Cp_XcpOnCanAsr
*
*
*******************************************************************************/

#define CANXCP_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/****************************************************************************
| NAME:             CanXcp_InitMemory()
| SID:              none
| CALLED BY:        Upper layer
| PRECONDITIONS:    
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      Initializes global variables. This function has to be called
|                   before any other calls to the CanXcp API
****************************************************************************/
FUNC(void, CANXCP_CODE) CanXcp_InitMemory( void )
{
#if ( CANXCP_DEV_ERROR_DETECT == STD_ON )
  CanXcp_InitializationState = CANXCP_UNINIT;
#endif

#if ( CANXCP_ENABLE_CONTROL == STD_ON )
  /* TL Enable/Disable state */
  CanXcp_ControlState = kXcponCan_Control_Enable;
  CanXcp_ControlDeniedCount = 0;
#endif
}


#if ( CANXCP_VERSION_INFO_API == STD_ON )
/****************************************************************************
| NAME:             CanXcp_GetVersionInfo()
| SID:              0x0A
| CALLED BY:        Upper layer
| PRECONDITIONS:
| INPUT PARAMETERS: versioninfo - buffer to copy version info to
| RETURN VALUES:    Std_ReturnType
| DESCRIPTION:      Provide DLC and data of the specified Pdu to upper layers
****************************************************************************/
FUNC(void, CANXCP_CODE) CanXcp_GetVersionInfo
(
  P2VAR(Std_VersionInfoType, AUTOMATIC, CANXCP_APPL_VAR) Versioninfo
)
{
#if ( CANXCP_ENABLE_CONTROL == STD_ON )
  if ( CanXcp_ControlState == kXcponCan_Control_Disable )
  {
    CanXcp_ControlDeniedCount++;
    return;
  }
#endif

  CanXcp_SilentBswCheckErrorReturnVoid( Versioninfo != (P2VAR(Std_VersionInfoType, AUTOMATIC, CANXCP_APPL_VAR))NULL_PTR,
                                        CANXCP_GETVERSIONINFO_ID, CANXCP_E_NULL_POINTER )

  Versioninfo->vendorID         = CANXCP_VENDOR_ID;
  Versioninfo->moduleID         = CANXCP_MODULE_ID;
  #if ( defined CANXCP_AUTOSARVERSION ) && ( CANXCP_AUTOSARVERSION == 4 )
  #else
  Versioninfo->instanceID       = 0x00u;
  #endif
  Versioninfo->sw_major_version = CANXCP_SW_MAJOR_VERSION;
  Versioninfo->sw_minor_version = CANXCP_SW_MINOR_VERSION;
  Versioninfo->sw_patch_version = CANXCP_SW_PATCH_VERSION;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */
#endif


/*******************************************************************************
** Function:    CanXcp_Init
**
** Purpose:     Initializations of the XCP on CAN Transport Layer.
**
**  Called by:  Xcp_SendCrm, Xcp_SendEv, Xcp_SendDto
**
**  Parameter:  - 
**
**  Returncode: -
*******************************************************************************/
FUNC(void, CANXCP_CODE) CanXcp_Init
(
  P2CONST(CanXcp_ConfigType, AUTOMATIC, CANXCP_PBCFG) ConfigPtr
)
{
  uint8_least i;
#if ( CanXcp_IsPostbuild() )
  CanXcp_Configuration = ConfigPtr;
#else
  #if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  /* avoid compiler warning due to unused parameters */
  ConfigPtr            = ConfigPtr;
  #endif
#endif

#if ( CANXCP_ENABLE_CONTROL == STD_ON )
  if ( CanXcp_ControlState == kXcponCan_Control_Disable )
  {
    CanXcp_ControlDeniedCount++;
    return;
  }
#endif

#if ( CANXCP_DEV_ERROR_DETECT == STD_ON )
  CanXcp_InitializationState = CANXCP_UNINIT;
#endif

#if defined ( CANXCP_MULTI_CHANNEL_ENABLED ) && ( XCP_NUMBER_OF_CHANNELS <= 1 )
  /* Initialize static variables. */
  CanXcp_RxPduId = CanXcp_GetRxPduIdIdx(0);
#endif
  for( i = 0; i < CANXCP_NUMBER_OF_CHANNELS; i++ )
  {
#if ( CANXCP_ENABLE_PDUMODE == STD_ON )
    CanXcp_PduState[i] = CANXCP_SET_OFFLINE;
#endif
    CanXcp_SendWithoutQueueState[i] = (uint8)CANXCP_MSG_IDLE;
    CanXcp_ConfTimeoutTimer[i] = (CanXcp_TimeoutTimerType)0u;
    /* Initialize variables for transmisson without any queue. */
    CanXcp_QueuedPduInfo[i].SduDataPtr = (P2VAR(uint8, AUTOMATIC, CANXCP_APPL_VAR))NULL_PTR;
    CanXcp_QueuedPduInfo[i].SduLength  = (PduLengthType)8u;
  }

#if ( CANXCP_DEV_ERROR_DETECT == STD_ON )
  CanXcp_InitializationState = CANXCP_INIT;
#endif
} /* PRQA S 2006 */ /* MD_MSR_14.7 */


/*******************************************************************************
** Function:    CanXcp_MainFunction
**
** Purpose:     Main function of XCP on CAN Transport Layer
**
**  Called by:  BSW Scheduler, OS
**
**  Parameter:  - 
**
**  Returncode: -
*******************************************************************************/
FUNC(void, CANXCP_CODE) CanXcp_MainFunction( void )
{
  uint8_least i;
  /* Activation control */
#if ( CANXCP_ENABLE_CONTROL == STD_ON )
  if ( CanXcp_ControlState == kXcponCan_Control_Disable )
  {
    CanXcp_ControlDeniedCount++;
    return;
  }
#endif

  for( i = 0; i < CANXCP_NUMBER_OF_CHANNELS; i++ )
  {
#if ( CANXCP_ENABLE_PDUMODE == STD_ON )
    if ( CANXCP_SET_ONLINE == CanXcp_PduState[i] )
#endif
    {
      /* If a CAN message is pending, try to send this */
      if ( CanXcp_SendWithoutQueueState[i] == (uint8)CANXCP_MSG_PENDING )
      {
        /* Try to transmit the XCP Packet */
        if ( CanIf_Transmit( CanXcp_GetTxPduIdIdx(i), &CanXcp_QueuedPduInfo[i] ) == (Std_ReturnType)E_OK )
        {
          CanXcp_ConfTimeoutTimer[i] = (CanXcp_TimeoutTimerType)CANXCP_CONF_TIMEOUT;
          /* The message was sent successfully. Clear the 'message pending' bit. */
          CanXcp_SendWithoutQueueState[i] = (uint8)CANXCP_MSG_IDLE;
        }
        else
        {
          /* The message is still pending. */
	    }
      }
    }

    CanXcp_EnterCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if( CanXcp_ConfTimeoutTimer[i] > 0u)
    {
      CanXcp_ConfTimeoutTimer[i]--;
      CanXcp_LeaveCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      if( 0u == CanXcp_ConfTimeoutTimer[i] )
      {
        /* Timeout happened, release PDU */
        (void)Xcp_SendCallBack((uint8)(XCP_TRANSPORT_LAYER_CAN + i));
      }
    }
    else
    {
      CanXcp_LeaveCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }
  }
} /* PRQA S 2006 */ /* MD_MSR_14.7 */


/*******************************************************************************
** Function:    CanXcp_RxIndication
**
** Purpose:     Rx Indication for reception of CTO and DTO Packets
**              This function is configured in the generation tool.
**
**  Called by:  CanIf
**
**  Parameter:  
**              CanCanXcpRxPduId : Target PDU ID of CAN L-PDU that has been received.
**              CanSduPtr        : Pointer to received L-SDU (payload).
**
**  Returncode: -
*******************************************************************************/
FUNC(void, CANXCP_CODE) Xcp_CanIfRxIndication
(
  VAR(PduIdType, AUTOMATIC) CanCanXcpRxPduId,
  P2CONST(PduInfoType, AUTOMATIC, CANXCP_APPL_VAR) PduInfoPtr
)
{
  uint8_least i;
  PduLengthType sduLen;
#if ( XCP_NUMBER_OF_CHANNELS > 1 ) || !defined ( CANXCP_MULTI_CHANNEL_ENABLED )
  PduIdType CanXcp_RxPduId;
#endif

  /* Activation control */
#if ( CANXCP_ENABLE_CONTROL == STD_ON )
  if ( CanXcp_ControlState == kXcponCan_Control_Disable )
  {
    CanXcp_ControlDeniedCount++;
    return;
  }
#endif

  CanXcp_CheckDetErrorReturnVoid( CANXCP_UNINIT != CanXcp_InitializationState,
                                  CANXCP_RXINDICATION_SERVICE_ID, CANXCP_E_NOT_INITIALIZED )
  CanXcp_SilentBswCheckErrorReturnVoid( PduInfoPtr != (P2CONST(PduInfoType, AUTOMATIC, CANXCP_APPL_VAR))NULL_PTR,
                                        CANXCP_RXINDICATION_SERVICE_ID, CANXCP_E_NULL_POINTER )
  CanXcp_SilentBswCheckErrorReturnVoid( PduInfoPtr->SduDataPtr != (SduDataPtrType)NULL_PTR,
                                        CANXCP_RXINDICATION_SERVICE_ID, CANXCP_E_NULL_POINTER )

#if ( XCP_NUMBER_OF_CHANNELS > 1 )
  /* Store the Rx PDU Id to determine the reception channel. */
  CanXcp_RxPduId = CanCanXcpRxPduId;
#else
# if defined ( CANXCP_MULTI_CHANNEL_ENABLED )
  if ( CanXcp_RxPduId != CanCanXcpRxPduId )
  {
#  if defined ( CANXCP_MULTI_CONN_PROT_ENABLED )
    /* Ensure that no XCP connection is interrupt via another channel. */
    if ( 0 != (Xcp_GetSessionStatus(XCP_TRANSPORT_LAYER_CAN + CanXcp_RxPduId) & (SessionStatusType)SS_CONNECTED) )
    {
      /* Do not transmit an error packet due to XcpConfirmation() will be called on the wrong channel. */
      return;
    }
    else
#  endif
    {
      /* Store the Rx PDU Id to determine the reception channel. */
      CanXcp_RxPduId = CanCanXcpRxPduId;
    }
  }
# else
  /* Verifiy RX Pdu Id */
  if(CanCanXcpRxPduId == CanXcp_GetRxPduId())
  {
    /* Store the Rx PDU Id for the reception. */
    CanXcp_RxPduId = CanCanXcpRxPduId;
# endif
#endif

    if(0xff == PduInfoPtr->SduDataPtr[0])
    {
      /* In case of connect we set this as active TL */
      Xcp_SetActiveTl((uint8)(XCP_TRANSPORT_LAYER_CAN + CanXcp_RxPduId), kCanXcpMaxCTO, kCanXcpMaxDTO, XCP_TRANSPORT_LAYER_CAN);
    }

    if(XCP_TRANSPORT_LAYER_CAN == Xcp_GetActiveTl((uint8)(XCP_TRANSPORT_LAYER_CAN + CanXcp_RxPduId)))
    {
      /*
        A XCP Packet has been received.
        Copy the whole received SDU to an 32-Bit aligned buffer.
      */
      sduLen = CANXCP_MAX(kCanXcpMaxCTO, kCanXcpMaxDTO);
      if( PduInfoPtr->SduLength < sduLen )
      {
        sduLen = PduInfoPtr->SduLength;
      }
      for(i=0; i<sduLen; i++)
      {
        CanXcp_PduBuffer.b[i] = PduInfoPtr->SduDataPtr[i];
      }
      /* Execution of Command Interpreter (evaluation of the XCP Packet) */
      Xcp_Command((uint8)(XCP_TRANSPORT_LAYER_CAN + CanXcp_RxPduId), CanXcp_PduBuffer.dw );
    }
#if ( XCP_NUMBER_OF_CHANNELS > 1 )
#else
# if defined ( CANXCP_MULTI_CHANNEL_ENABLED )
# else
  }
# endif
#endif
} /* PRQA S 2006 */ /* MD_MSR_14.7 */ /* PRQA S 6010 */ /* MD_MSR_STPTH */


/*******************************************************************************
** Function:    CanXcp_TxConfirmation
**
** Purpose:     Tx Confirmation for successful transmission of CTO and DTO Packets
**              This function is configured in the generation tool.
**
**  Called by:  CanIf
**
**  Parameter:  
**              CanCanXcpTxPduId : PDU ID of CAN L-PDU transmitted successfully.
**
**  Returncode: -
*******************************************************************************/
FUNC(void, CANXCP_CODE) Xcp_CanIfTxConfirmation( VAR(PduIdType, AUTOMATIC) CanTxPduId )
{
  uint8_least i;

  /* Activation control */
#if ( CANXCP_ENABLE_CONTROL == STD_ON )
  if ( CanXcp_ControlState == kXcponCan_Control_Disable )
  {
    CanXcp_ControlDeniedCount++;
    return;
  }
#endif

  CanXcp_CheckDetErrorReturnVoid( CANXCP_UNINIT != CanXcp_InitializationState,
                                  CANXCP_TXCONFIRMATION_SERVICE_ID, CANXCP_E_NOT_INITIALIZED )

  /* Search respective channel handle */
  for(i=0; i<CANXCP_NUMBER_OF_CHANNELS; i++)
  {
    if( CanXcp_GetTxConfPduIdIdx(i) == CanTxPduId )
    {
      break;
    }
  }

  if( i < CANXCP_NUMBER_OF_CHANNELS )
  {
    CanXcp_ConfTimeoutTimer[i] = (CanXcp_TimeoutTimerType)0u;
    /*
      Notify the XCP protocol driver of the successful transmission of a message.
      The XCP driver will not call ApplXcpSend() again, until Xcp_SendCallBack has
      indicated the successful transmission of the previous message.
    */
    (void)Xcp_SendCallBack((uint8)(XCP_TRANSPORT_LAYER_CAN + i));
  }
} /* PRQA S 2006 */ /* MD_MSR_14.7 */


/*******************************************************************************
** Function:    CanXcp_Send
**
** Purpose:     Request for the transmission of a DTO or CTO message
**
**  Called by:  Xcp_SendCrm, Xcp_SendEv, Xcp_SendDto
**
**  Parameter:  
**              len : length of PDU data
**              msg : pointer to PDU data
**
**  Returncode: -
*******************************************************************************/
FUNC(void, CANXCP_CODE) CanXcp_Send
(
  uint8 Xcp_Channel,
  uint8 len,
  P2CONST(uint8, AUTOMATIC, CANXCP_APPL_VAR) msg
) /* ESCAN00071289 */
{
  PduInfoType PduInfo;

  /* Activation control */
#if ( CANXCP_ENABLE_CONTROL == STD_ON )
  if ( CanXcp_ControlState == kXcponCan_Control_Disable )
  {
    CanXcp_ControlDeniedCount++;
    return;
  }
#endif

  CanXcp_CheckDetErrorReturnVoid( CANXCP_UNINIT != CanXcp_InitializationState,
                                  CANXCP_SEND_ID, CANXCP_E_NOT_INITIALIZED )
  CanXcp_SilentBswCheckErrorReturnVoid( msg != (P2CONST(uint8, AUTOMATIC, CANXCP_APPL_VAR))NULL_PTR,
                                        CANXCP_SEND_ID, CANXCP_E_NULL_POINTER )

  PduInfo.SduDataPtr = (P2VAR(uint8, AUTOMATIC, CANXCP_APPL_VAR))msg; /* PRQA S 0311 */ /* MD_CanXcp_0311 */
#if defined ( CANXCP_VARIABLE_DLC_ENABLED )
  PduInfo.SduLength  = (PduLengthType)len;
#else
  PduInfo.SduLength  = (PduLengthType)CANXCP_PDU_SIZE;
  #if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  /* avoid compiler warning due to unused parameters */
  len = len;
  #endif
#endif

  /* Set correct channel index */
#if defined ( CANXCP_MULTI_CHANNEL_ENABLED ) && ( XCP_NUMBER_OF_CHANNELS <= 1 )
  Xcp_Channel = (uint8)CanXcp_RxPduId;
#else
  Xcp_Channel -= XCP_TRANSPORT_LAYER_CAN;
#endif
#if ( CANXCP_ENABLE_PDUMODE == STD_ON )
  if ( CANXCP_SET_ONLINE == CanXcp_PduState[Xcp_Channel] )
  {
#endif
    /* Transmit the XCP Packet */
    if ( CanIf_Transmit( CanXcp_GetTxPduIdIdx(Xcp_Channel), &PduInfo ) != (Std_ReturnType)E_OK )
    {
#if ( CANIF_TRANSMIT_BUFFER == STD_ON )

      /* Fatal Error. XCP Packet cannot be transmitted. */
      Xcp_Init();

#else /* if ( CANIF_TRANSMIT_BUFFER == STD_ON ) */
      /*
        Transmission via CanIf_Transmit has failed.
        Set a flag in order to re-start transmission of the XCP Packet in CanXcp_MainFunction
      */
      CanXcp_SendWithoutQueueState[Xcp_Channel] = (uint8)CANXCP_MSG_PENDING;
      CanXcp_QueuedPduInfo[Xcp_Channel]         = PduInfo;
#endif /* if ( CANIF_TRANSMIT_BUFFER == STD_ON ) */
    }
    else
    {
      CanXcp_ConfTimeoutTimer[Xcp_Channel] = (CanXcp_TimeoutTimerType)CANXCP_CONF_TIMEOUT;
    }
#if ( CANXCP_ENABLE_PDUMODE == STD_ON )
  }
  else
  {
    CanXcp_SendWithoutQueueState[Xcp_Channel] = (uint8)CANXCP_MSG_PENDING;
    CanXcp_QueuedPduInfo[Xcp_Channel]         = PduInfo;
  }
#endif
} /* PRQA S 2006 */ /* MD_MSR_14.7 */


/*******************************************************************************
** Function:    CanXcp_SendFlush
**
** Purpose:     Flush function of XCP on CAN Transport Layer
**
**  Called by:  Upper Layer
**
**  Parameter:  FlushType: 
**
**  Returncode: -
*******************************************************************************/
FUNC(void, CANXCP_CODE) CanXcp_SendFlush( uint8 Xcp_Channel, uint8 FlushType )
{
  /* Activation control */
#if ( CANXCP_ENABLE_CONTROL == STD_ON )
  if ( CanXcp_ControlState == kXcponCan_Control_Disable )
  {
    CanXcp_ControlDeniedCount++;
    return;
  }
#endif

  CanXcp_CheckDetErrorReturnVoid( CANXCP_UNINIT != CanXcp_InitializationState,
                                  CANXCP_SENDFLUSH_ID, CANXCP_E_NOT_INITIALIZED )

  #if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  /* avoid compiler warning due to unused parameters */
  Xcp_Channel = Xcp_Channel;
  FlushType = FlushType;
  #endif
} /* PRQA S 2006 */ /* MD_MSR_14.7 */


/*******************************************************************************
** Function:    CanXcp_TLService
**
** Purpose:     CAN Transport Layer Command
**
**  Called by:  Upper Layer
**
**  Parameter:  pCmd: pointer to cmd string
**
**  Returncode: -
*******************************************************************************/
FUNC(uint8, CANXCP_CODE) CanXcp_TLService( uint8 Xcp_Channel, P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) pCmd )
{
  /* Activation control */
#if ( CANXCP_ENABLE_CONTROL == STD_ON )
  if ( CanXcp_ControlState == kXcponCan_Control_Disable )
  {
    CanXcp_ControlDeniedCount++;
    return(XCP_CMD_UNKNOWN);
  }
#endif

  CanXcp_CheckDetErrorReturnValue( CANXCP_UNINIT != CanXcp_InitializationState,
                                   CANXCP_TLSERVICE_ID, CANXCP_E_NOT_INITIALIZED, XCP_CMD_UNKNOWN )

  #if defined ( V_ENABLE_USE_DUMMY_STATEMENT )
  /* avoid compiler warning due to unused parameters */
  Xcp_Channel = Xcp_Channel;
  pCmd = pCmd;
  #endif
  return(XCP_CMD_UNKNOWN);
} /* PRQA S 2006 */ /* MD_MSR_14.7 */


#if ( CANXCP_ENABLE_PDUMODE == STD_ON )
/*******************************************************************************
** Function:    CanXcp_SetPduMode
**
** Purpose:     Enable or disable the component
**
**  Called by:  State Manager
**
**  Parameter:  command : enable/disable
**
**  Returncode: -
*******************************************************************************/
FUNC(void, CANXCP_CODE) CanXcp_SetPduMode( NetworkHandleType XcpNwH, CanXcp_PduSetModeType PduMode )
{
  /* Activation control */
#if ( CANXCP_ENABLE_CONTROL == STD_ON )
  if ( CanXcp_ControlState == kXcponCan_Control_Disable )
  {
    CanXcp_ControlDeniedCount++;
    return;
  }
#endif

  CanXcp_CheckDetErrorReturnVoid( CANXCP_UNINIT != CanXcp_InitializationState,
                                  CANXCP_SETPDUMODE_ID, CANXCP_E_NOT_INITIALIZED )

  CanXcp_SilentBswCheckErrorReturnVoid(XcpNwH < CANXCP_NUMBER_OF_CHANNELS, CANXCP_SETPDUMODE_ID,
                                       CANXCP_E_INVALID_NW_HANDLE);

  CanXcp_PduState[XcpNwH] = PduMode;
} /* PRQA S 2006 */ /* MD_MSR_14.7 */
#endif



#define CANXCP_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*******************************************************************************
  Consistency checks
*******************************************************************************/

/* Check configuration of Transport Layer */
#if defined ( XCP_TRANSPORT_LAYER_TYPE_CAN_ASR )
#else
  #error "Configuration for XCP Transport Layer for AUTOSAR CAN Interface doesn't exist!"
#endif

/* Check range of kXcpMaxCTO and kXcpMaxDTO */
#if ( kCanXcpMaxCTO <= CANXCP_PDU_SIZE )
#else
  #error "XCP consistency error: MAX_CTO must be less or equal to the PDU size on CAN."
#endif
#if ( kCanXcpMaxDTO <= CANXCP_PDU_SIZE )
#else
  #error "XCP consistency error: MAX_DTO must be less or equal to the PDU size on CAN."
#endif


/*******************************************************************************
* Organi check
*******************************************************************************/


/* module specific MISRA deviations:
  MD_CanXcp_0311: Rule 11.5
      Reason:     Std Type from ASR does not use const, casting required to avoid compiler warning.
      Risk:       There is no risk as the pointers do only point to local component memory.
      Prevention: Covered by code review.
  MD_CanXcp_3218: Rule 8.7
      Reason:     For proper use of AUTOSAR memory mapping the variable is kept global even thogh
                  it is only used in one function
      Risk:       There is no risk as there is no prohibition of use.
      Prevention: Covered by code review.
  MD_Xcp_3408:    Rule 8.8
      Reason:     The variable is not defined as static to be accessible for debugging. No prototype is required for this.
      Risk:       There is no risk as this variable is not accessed externally.
      Prevention: Covered by code review.
  MD_CanXcp_3410: Rule 19.10
      Reason:     Additional parenthesis causes compile error
      Risk:       There is no risk as the macro is used locally.
      Prevention: Covered by code review.
  MD_CanXcp_3448: Rule 5.3
      Reason:     defined object is only external for debugging purposes. No use by other componentes.
      Risk:       There is no risk as the object is used locally.
      Prevention: Covered by code review.
*/

/**********************************************************************************************************************
 *  END OF FILE: CanXcp.c
 *********************************************************************************************************************/
