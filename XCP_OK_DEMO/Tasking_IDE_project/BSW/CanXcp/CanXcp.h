/******************************************************************************
 | Project Name:   XCP on CAN Transport Layer for AUTOSAR CanIf Release 3.0
 |    File Name:   CanXcp.h
 |
 |  Description:
 |    Header of adaption component for the XCP Protocol Layer interface
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
 | 2009-11-25             Hr    ESCAN00039395: Support Multiple Configuration
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
#if !defined ( CANXCP_H )
#define CANXCP_H

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "CanXcp_Types.h"              /* Type definitions for XCP on CAN ASR */
#include "CanXcp_Cfg.h"                /* Include configuration of XCP on CAN */
#include "Xcp_Cfg.h"           /* Include configuration of XCP Protocol Layer */

#if defined (CANXCP_CONFIGURATOR) && (CANXCP_CONFIGURATOR == 5)
/* ESCAN00076847: extern declaration of the root struct */
#include "CanXcp_Lcfg.h"
#include "CanXcp_PBcfg.h"
#else
  #include "SchM_CanXcp.h"
#endif


/*******************************************************************************
* Version
*******************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : Cp_XcpOnCanAsr CQComponent : Implementation */
#define CP_XCPONCANASR_VERSION          0x0200u
#define CP_XCPONCANASR_RELEASE_VERSION  0x00u

#define CANXCP_SW_MAJOR_VERSION         ((CP_XCPONCANASR_VERSION & 0xFF00) >> 8)
#define CANXCP_SW_MINOR_VERSION         (CP_XCPONCANASR_VERSION & 0xFF)
#define CANXCP_SW_PATCH_VERSION         (CP_XCPONCANASR_RELEASE_VERSION)

#define CANXCP_VENDOR_ID                30u
#define CANXCP_MODULE_ID                212u

#define CANXCP_START_SEC_CONST_8BIT
#include "MemMap.h"

extern CONST(uint8, CANXCP_CONST)       kXcpOnCanAsrMainVersion;
extern CONST(uint8, CANXCP_CONST)       kXcpOnCanSubAsrVersion;
extern CONST(uint8, CANXCP_CONST)       kXcpOnCanAsrReleaseVersion;

#define CANXCP_STOP_SEC_CONST_8BIT
#include "MemMap.h"

/* Version of the XCP Transport Layer for CAN specification. */
#if ! defined ( CANXCP_TRANSPORT_LAYER_VERSION )
  #define CANXCP_TRANSPORT_LAYER_VERSION   0x0100
#endif

/*******************************************************************************
* Default Defintions
*******************************************************************************/

/* CTO and DTO are per default 8 on CAN. */

#if defined ( kCanXcpMaxCTO )
#else
  #define kCanXcpMaxCTO                    8
#endif

#if defined ( kCanXcpMaxDTO )
#else
  #define kCanXcpMaxDTO                    8
#endif

#if defined CANXCP_PDU_SIZE
#else
  #define CANXCP_PDU_SIZE 8
#endif

#if !defined ( CANXCP_CONF_TIMEOUT )
# define CANXCP_CONF_TIMEOUT 25u
#endif

/* Initialization status of XCP. */
#define CANXCP_UNINIT   0
#define CANXCP_INIT     1

/* The function XcpGetSessionStatus is required for the protection against multiple connections. */
#if defined ( CANXCP_MULTI_CONN_PROT_ENABLED )
  #if !defined ( XCP_ENABLE_GET_SESSION_STATUS_API )
    #define XCP_ENABLE_GET_SESSION_STATUS_API
  #endif
#endif

#if !defined ( CANXCP_ENABLE_PDUMODE )
  #if defined (CANXCP_AUTOSARVERSION) && (CANXCP_AUTOSARVERSION == 4)
    #define CANXCP_ENABLE_PDUMODE STD_OFF
  #else
    #define CANXCP_ENABLE_PDUMODE STD_ON
  #endif
#endif


/*******************************************************************************
* Type definitions
*******************************************************************************/

/* Development errors */
#if ( CANXCP_DEV_ERROR_DETECT == STD_ON )
/* Definition of the API ID */
  #define CANXCP_INIT_SERVICE_ID                   0u
  #define CANXCP_TLSERVICE_ID                      1u
  #define CANXCP_SEND_ID                           2u
  #define CANXCP_SENDFLUSH_ID                      4u
  #define CANXCP_CONTROL_ID                        5u
  #define CANXCP_GETVERSIONINFO_ID                 6u
  #define CANXCP_SETPDUMODE_ID                     7u
  #define CANXCP_TXCONFIRMATION_SERVICE_ID       101u
  #define CANXCP_RXINDICATION_SERVICE_ID         102u
  #define CANXCP_MAINFUNCTION_SERVICE_ID         200u

/* Definition of errors/exceptions */
  #define CANXCP_E_INV_POINTER                     1u
  #define CANXCP_E_NOT_INITIALIZED                 2u
  #define CANXCP_E_INVALID_PDUID                   3u
  #define CANXCP_E_NULL_POINTER                   18u
  #define CANXCP_E_RX_BUFFER_OVERFLOW              4u
  #define CANXCP_E_WRONG_CONTROL_COMMAND           5u
  #define CANXCP_E_INVALID_NW_HANDLE               6u
#endif


/***************************************************************************/
/* Default macros                                                          */
/***************************************************************************/

/* Interrupt enable and disable functions */
#define CanXcp_EnterCritical()            SchM_Enter_Xcp_CANXCP_EXCLUSIVE_AREA_0()
#define CanXcp_LeaveCritical()            SchM_Exit_Xcp_CANXCP_EXCLUSIVE_AREA_0()

#if defined ( ApplXcpInterruptDisable )
#else
# define ApplXcpInterruptDisable()        SchM_Enter_Xcp_CANXCP_EXCLUSIVE_AREA_0()
#endif
#if defined ( ApplXcpInterruptEnable )
#else
# define ApplXcpInterruptEnable()         SchM_Exit_Xcp_CANXCP_EXCLUSIVE_AREA_0()
#endif

#if defined ( XCP_GEN_GENERATOR_MSR )
  #define CanXcp_IsPostbuild() ((3u == CANXCP_CONFIG_VARIANT) || (XCP_POSTBUILD_VARIANT_SUPPORT == STD_ON))
#else
  #define CanXcp_IsPostbuild() (3u == CANXCP_CONFIG_VARIANT)
#endif


/******************************************************************************/
/* External ROM Data                                                          */
/******************************************************************************/

/******************************************************************************/
/* External RAM Data                                                          */
/******************************************************************************/
/* En- or disable the Xcp Protocol Layer globally */
#if ( CANXCP_ENABLE_CONTROL == STD_ON )
# define CANXCP_START_SEC_VAR_INIT_UNSPECIFIED_SAFE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* TL Enable/Disable state */
extern VAR(uint8, CANXCP_VAR_INIT) CanXcp_ControlState;

# define CANXCP_STOP_SEC_VAR_INIT_UNSPECIFIED_SAFE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# define kXcponCan_Control_Disable   0x00u
# define kXcponCan_Control_Enable    0x01u
#endif


/****************************************************************************/
/* Prototypes                                                               */
/****************************************************************************/

#define CANXCP_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void, CANXCP_CODE) CanXcp_InitMemory( void );

#if ( CANXCP_VERSION_INFO_API == STD_ON )
extern FUNC(void, CANXCP_CODE) CanXcp_GetVersionInfo
(
  P2VAR(Std_VersionInfoType, AUTOMATIC, CANXCP_APPL_VAR) Versioninfo
);
#endif

extern FUNC(void, CANXCP_CODE) CanXcp_Init
(
  P2CONST(CanXcp_ConfigType, AUTOMATIC, CANXCP_PBCFG) ConfigPtr
);

#if ( CANXCP_AUTOSARVERSION == 4 )
#else
extern FUNC(void, CANXCP_CODE) CanXcp_MainFunction( void );
#endif

extern FUNC(void, CANXCP_CODE) Xcp_CanIfRxIndication
(
  VAR(PduIdType, AUTOMATIC) CanCanXcpRxPduId,
  P2CONST(PduInfoType, AUTOMATIC, CANXCP_APPL_VAR) PduInfoPtr
);

extern FUNC(void, CANXCP_CODE) Xcp_CanIfTxConfirmation( VAR(PduIdType, AUTOMATIC) CanTxPduId );

extern FUNC(void, CANXCP_CODE) CanXcp_Send
(
  uint8 Xcp_Channel,
  uint8 len,
  P2CONST(uint8, AUTOMATIC, CANXCP_APPL_VAR) msg
); /* ESCAN00071289 */

extern FUNC(void, CANXCP_CODE) CanXcp_SendFlush( uint8 Xcp_Channel, uint8 FlushType );
extern FUNC(uint8, CANXCP_CODE) CanXcp_TLService( uint8 Xcp_Channel, P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) pCmd );
#if ( CANXCP_ENABLE_PDUMODE == STD_ON )
extern FUNC(void, CANXCP_CODE) CanXcp_SetPduMode( NetworkHandleType XcpNwH, CanXcp_PduSetModeType PduMode );
#else
  #define CanXcp_SetPduMode(XcpNwH, PduMode)
#endif

#define CANXCP_STOP_SEC_CODE
#include "MemMap.h"

#endif /* CANXCP_H */
