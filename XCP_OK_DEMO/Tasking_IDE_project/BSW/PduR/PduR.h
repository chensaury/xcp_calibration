/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  PduR.h
 *      Project:  Gw_AsrPduRCfg5
 *       Module:  MICROSAR PDU Router
 *    Generator:  Configurator 5
 *
 *  Description:  Vector implementation of AUTOSAR PDU Router
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Erich Schondelmaier         visehs        Vector Informatik GmbH
 *  Gunnar Meiss                visms         Vector Informatik GmbH
 *  Sebastian Waldvogel         visswa        Vector Informatik GmbH
 *  Stephan Probst              visspt        Vector Informatik GmbH
 *  Florian Roehm               visfrm        Vector Informatik GmbH
 *  Di Li                       visldi        Vector Informatik GmbH
 *  Buesra Bayrak               visbbk        Vector Informatik GmbH
 *  Sylvia Schlag               visssg        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version  Date        Author  Change Id       Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  1.00.00  2011-12-05  visms   -               derived initial CFG5 version from Gw_AsrPduR 3.17.00
 *  2.00.00  2012-07-12  visehs  ESCAN00059664   PDUR reports a incorrect DET error for the Handle ID parameter
 *           2012-07-12  visehs  ESCAN00058311   AR4-160: Support AUTOSAR 4.0.3 as Beta
 *  2.01.00  2012-09-26  visehs  ESCAN00061711   AR4-225: Support high level TP Gateway Routing
 *           2012-10-05  visehs  ESCAN00061982   Compiler warning: expression evaluates to a function which is missing
 *                                               an argument list
 *           2012-10-05  visehs  ESCAN00061471   Linker error: unresolved external symbol _PduR_GetDestHndOfDFiFoInfo
 *  2.01.01  2012-11-05  visms   ESCAN00062706   Compiler error: error C2065: 'destHandleId' : undeclared identifier
 *           2012-11-05  visms   ESCAN00062709   Linker Error: Unresolved Symbol PduR_DcmTransmit
 *  2.01.02  2012-11-08  visms   ESCAN00062868   Compiler error: identifier PduR_TpBAHndType not declared
 *  2.02.00  2012-11-12  visms   ESCAN00061832   AR4-285: Support PduRRoutingPathGroups
 *           2012-11-12  visms   ESCAN00062808   Use upper case 'U' suffix for unsigned variables / numbers
 *           2012-11-13  visms   ESCAN00062963   Compiler error: illegal else without matching if in
 *                                               PduR_RmTp_LoAndUpTransmit
 *           2012-11-16  visms   ESCAN00062979   Routing abort with 1:N TP Routing (with an Upper Layer destination)
 *           2012-11-30  visehs  ESCAN00063475   Version Define does not match with the Component name
 *  2.02.01  2013-02-06  visms   ESCAN00064828   Out of bounds array access in PduR_EnableRouting and
 *                                               PduR_DisableRouting
 *           2013-02-06  visms   ESCAN00064829   Switching PduRRoutingPathGroups for IF PduRRoutingPaths with multiple
 *                                               destinations does not work
 *  2.03.00  2013-02-14  visms   ESCAN00064303   AR4-325: Implement Post-Build Loadable
 *           2013-02-18  visswa  ESCAN00063380   Separate Misra/PcLint comments with blank
 *           2013-02-20  visehs  ESCAN00065996   Add Det error Id  "PDUR_E_PARAM_INVALID " according to ASR4
 *           2013-03-19  visms   ESCAN00064485   AR4-282: Export BSW DBG Data
 *           2013-03-20  visehs  ESCAN00066041   Make the Enable-, DisableRouting APIs more robust
 *           2013-04-02  visehs  ESCAN00065323   Compiler error: Cannot resolve symbol
 *                                               PduR_GetRmDestTpEndIdxOfRmSrcRom in PduR_RmTp_LoAndUpTransmit()
 *           2013-04-09  visswa  ESCAN00066490   MISRA compliance
 *           2013-04-18  visehs  ESCAN00066722   Interface Gateway Routing: Wrong data are sent in case of direct
 *                                               routing
 *           2013-04-18  visehs  ESCAN00066723   Interface Gateway Routing: Wrong data are sent in case of trigger
 *                                               transmit routing
 *  2.04.00  2013-08-16  visms   ESCAN00069870   The prefix of VAR data shall be <Msn> followed by '_'
 *           2013-08-23  visms   ESCAN00069150   Include "SchM_PduR.h" only in source files
 *           2013-08-23  visms   ESCAN00068899   TT Single Buffer is not initialized
 *           2013-10-14  visehs  ESCAN00071100   Memory could be overwritten by interface gateway routings with a
 *                                               TT- FIFO with queue depth > 1 and dynamic DLC
 *  2.04.01  2013-11-18  visehs  ESCAN00072015   Transport protocol data can be corrupted during gateway transmission
 *                                               in case of parallel routings
 *  2.05.00  2013-11-26  visspt  ESCAN00072172   Reduce unnecessary Code in function PduR_RmIf_RxIndication_MultiIf.
 *           2013-11-26  visspt  ESCAN00072225   Optimize while condition in function PduR_RmIf_RxIndication_MultiIf
 *           2013-12-04  visspt  ESCAN00072430   Memory overwritten in PduR_Init function, if Tp Gw Routing are
 *                                               configured
 *  2.05.00  2013-12-11  visehs  ESCAN00072594   Redesign the Tp Routing State machine
 *           2014-01-17  visehs  ESCAN00073049   Adapt Tp 1:N Fanout routing according to RfC 52242
 *  3.00.00  2014-02-05  visehs  ESCAN00070543   AR4-345: Implement PF4_PostBuildSelectable
 *           2014-02-25  visehs  ESCAN00071600   AR4-601: TP routing with immediate transmission
 *           2014-03-19  visehs  ESCAN00072450   AR4-601: TP routing with variable addresses
 *           2014-05-12  visehs  ESCAN00071925   AR4-619: Support the StartOfReception API (with the PduInfoType),
 *                                               TxConfirmation and RxIndication according ASR4.1.2
 *           2014-05-23  visms   ESCAN00074114   AR4-642: Deleting container at post-build time
 *           2014-05-26  visehs  ESCAN00075191   TpGw Routing deadlock if RxIndication and TxConfirmation comes at the
 *                                               same time with an result != E_OK
 *  3.00.01  2014-06-05  visehs  ESCAN00076390   MISRA compliance
 *  4.00.00  2014-07-08  visehs  ESCAN00072859   AR4-795: Back-to-Back-Routing of TP messages
 *           2014-10-08  visehs  ESCAN00078796   IF Gateway Routings with Data Provision "TriggerTransmit" and
 *                                               "Tx Buffer Depth" > 1 sends deprecated data
 *           2014-10-08  visehs  ESCAN00076362   Remove uint16_least in PduR_BufMgr_* APIs
 *  4.00.01  2014-11-10  visehs  ESCAN00079470   Memory overwritten in  PduR_RmTp_BufAdminMgr_ReleaseRxBuffer()
 *                                               function, if Tp Gw Routing are configured
 *  4.00.02  2014-11-19  visehs  ESCAN00079684   Compiler error: SINGLEBUFFER': undeclared identifier
 *  5.00.00  2014-11-21  visehs  ESCAN00079509   Messages are not send to the destination bus, after Flexray state
 *                                               "out of sync"
 *           2014-11-28  visehs  ESCAN00079881   Unexpected buffer overrun during interface gateway routing after
 *                                               initialization
 *           2014-11-28  visehs  ESCAN00079882   Report always a DET error if a Buffer overrun occurs
 *           2014-12-10  visehs  ESCAN00080136   Harmonies API Naming
 *           2014-12-22  visehs  ESCAN00080372   Make Tp routing more robust for a better sub-contractor TP module
 *                                               support
 *           2015-01-14  visehs  ESCAN00080576   Remove unreachable statement and rearrange conditions that never apply
 *           2015-01-16  visehs  ESCAN00080641   Linker error: unresolved external symbol EcuM_BswErrorHook() referenced
 *                                               in function PduR_Init()
 *           2015-01-20  visehs  ESCAN00080686   Fixed MPU warning: Erroneous read access for an unused variable
 *           2015-01-26  visehs  ESCAN00080814   Interface Gateway Routings with Data Provision "TriggerTransmit", "
 *                                               Tx Buffer Depth" ==  1 could not handle with dynamic length
 *           2015-02-11  visehs  ESCAN00081184   Optimize runtime and safety aspects for PduR Buffer manager
 *           2015-02-11  visehs  ESCAN00080292   FEAT-427: SafeBSW Step I
 *           2015-03-20  visehs  ESCAN00079911   Optimization: Flush D-FiFo after Queue overrun.
 *  6.00.00  2015-04-14  visehs  ESCAN00082414   Optimization: Flush IF- FiFo or Tp Buffer after disabling routing path group
 *           2015-06-02  visehs  ESCAN00083229   Memory could be overwritten for IF- Gateway routings where a buffer is
 *                                               used and the PduRPduMaxLength is not equal to the global Pdu length.
 *           2015-07-30  visehs  ESCAN00082968   FEAT-109: Support N:1 Routing for communication interface routing.
 *           2015-08-04  visehs  ESCAN00083327   PduR Switching mechanism.
 *           2015-09-15  visehs  ESCAN00085244   MISRA deviation: MISRA-C:2004 MD_MSR_14.3 for SchM_Enter and SchM_Exit APIs
 *  6.01.00  2015-09-03  visspt  ESCAN00084962   The Safe BSW variant is not Safe if PduRDevErrorDetect is deactivated
 *           2015-09-30  visehs  ESCAN00081780   FEAT-1275: SafeBSW Step 2
 *  7.00.00  2015-10-01  visehs  ESCAN00085227   FEAT-1485: Support N:1, 1:N, FIFO TP gateway routing paths
 *           2015-11-18  visehs  ESCAN00086596   Compiler warning: used wrong Memory class qualifier in several functions
 *           2015-10-09  visfrm  ESCAN00085750   Entire Pdu length is incorrectly calculated if meta data feature is used.
 *           2016-01-16  visehs  ESCAN00087296   The provided buffer size lacks the meta data size if the threshold is
 *                                               reached and the Transmit function is called.
 *           2016-02-08  visehs  ESCAN00087751   Compiler warning: conversion from 'PduIdType' to 'PduR_SizeOfRmSrcRomType',
 *                                               possible loss of data
 *           2016-02-08  visehs  ESCAN00088147   Compiler error: 'PduR_RmIf_CancelTransmit_Multi' : undeclared identifier
 *           2016-02-16  visehs  ESCAN00088326   N:1 Gateway Communication Interface routing are not interlocked during
 *                                               runtime if no routing path groups are configured.
 *           2016-02-25  visms   ESCAN00087831   FEAT-1631: Trigger Transmit API with SduLength In/Out according to ASR4.2.2
 *           2016-03-14  visehs  ESCAN00088326   N:1 Gateway Communication Interface routing are not interlocked during runtime
 *                                               if no routing path groups are configured
 *           2016-03-21  visehs  ESCAN00087798   FEAT-1688: SafeBSW Step 4
 *           2016-03-21  visswa  ESCAN00088986   FEAT-1642: Release Backbone Switching
 * 7.01.00   2016-04-01  visehs  ESCAN00089189   Optimize runtime in case of 1:1 Tp routing.
 *           2016-04-01  visehs  ESCAN00089194   Cleanup Misra Comments in PduR.h
 * 7.01.01   2016-04-29  visehs  ESCAN00089820   Support post build loadable configurations without EcuM module
 *           2016-04-29  visehs  ESCAN00089822   MISRA deviation: MISRA-C:2004 Rule 3355, 3356 condition is
 *                                               always true or always false
 * 7.02.00   2016-04-07  visehs  ESCAN00089160   Compiler warning: C4244 possible loss of data
 *           2016-04-07  visehs  ESCAN00090108   Compiler warning:  function "PduR_Init_Rpg" was declared but never referenced
 * 7.03.00   2016-04-29  visehs  ESCAN00089795   Add Instance Routing State machine to allow proper Routing Path Group
 *                                               handling in case of 1:N Tp routing
 *           2016-06-16  visehs  ESCAN00090418   Optimize ROM consumption and Init runtime for Communication Interface
 *                                               gateway routings
 *                       visehs  ESCAN00082683   Compiler Error: Datatype PduR_PBConfigIdType not defined by PduR
 *           2016-06-30  visehs  ESCAN00090762   Support overall total Tp buffer size greater than 65535
 * 8.00.00   2016-07-01  visehs  ESCAN00090767   Compiler warning conversion from 'PduIdType' to 'PduR_RmSrcRomIterType'
 *                                               and conversion from 'PduIdType' to 'PduR_RmGDestRomIterType'
 *           2016-07-16  visehs  ESCAN00091194   DET reports a fatal error and communication interface PDU is not routed
 * 8.00.01   2016-08-05  visehs  ESCAN00091336   Communication Interface Gateway with direct routing: Random value could be
 *                                               send after Initialization.
 * 9.00.00   2016-07-12  visehs  ESCAN00089979   FEAT-1955 Shared buffer pool and dedicate buffer support.
 *           2016-08.01  visswa  FEAT-1611       Support address bases learning strategy (OVTP gateway).
 *           2016-12-09  visms   ESCAN00093240   The PduR buffer shall be mappable into a own section
 * 9.00.01   2017-01-31  visehs  ESCAN00093792   Compiler warning:  conversion from 'PduIdType' to 'PduR_RmSrcRomIterType', possible loss of data
 *           2017-01-31  visehs  ESCAN00093790   Compiler warning:  conversion from 'PduIdType' to 'PduR_TxMulti2LoStateIterType', possible loss of data
 *           2017-03-20  visehs  ESCAN00094425   Compiler warning: "possible loss of data"
 *           2017-03-29  visehs  ESCAN00094099   Invalid data is routed while a communication interface routing if the PduRPduMaxLength is not equal to the PduLength
 *  9.00.02  2017-05-16  visehs  ESCAN00095163   Communication interface gateway routing fails.
 *           2017-05-14  visehs  ESCAN00095170   Routing path group enabling/ disabling fails.
 *           2017-05-19  visehs  ESCAN00095241   Fatal Det Error is reported if a dedicated buffer is used for Tp gateway routing.
 * 10.00.00  2017-01-31  visehs  FEATC-933       FEAT-2315:  Use Gw_AsrPduRCfg5 Unit Tests (testability changes)
 *           2017-03-27  visehs  FEAT-2386       WriteOutOfBoundsWriteProtectionStrategy with INDEX_SATURATION and INDEX_CHECKING shall not be used in productive builds
 * 11.00.00  2017-09-08  visldi  ESCAN00090806   Compiler warning: C4310: cast truncates constant value
 * 11.00.01  2017-10-17  visfrm  ESCAN00097071   Implementation version incorrect
 * 11.01.00  2017-11-03  visfrm  STORYC-2971     Merge routing path group tables into existing tables
 *           2017-12-01  visfrm  ESCAN00097472   Communication Interface 1:N Tx API Forwarding not working
 *           2017-12-01  visfrm  STORYC-2031     Support buffered IF API Forwarding routing paths
 *           2017-12-01  visfrm  STORYC-2970     Merge If N:1 Fan-In tables into existing tables
 * 11.03.00  2018-01-03  visbbk  STORYC-3239     Support Deferred IF Processing
 *           2018-01-10  visfrm  STORYC-3860     Merge Tp N:1 Fan-In tables into existing tables
 *           2018-01-12  visfrm  ESCAN00097955   Compiler warning: "possible loss of data"
 * 11.04.00  2018-01-22  visbbk  ESCAN00098082   Deferred Processing not working for single Buffer or flushed FiFo
 *           2018-01-24  visfrm  STORYC-3416     PduR: Enable assignment of buffers smaller than the associated PDU sizes to the buffer pool referenced by a routing path
 *           2018-01-25  visfrm  STORYC-3435     PduR: Enable routing paths with different connected PDU sizes in gateway routings
 *           2018-01-27  visfrm  STORYC-2972     Merge function pointer tables
 *           2018-01-27  visfrm  STORYC-3904     Reduce memory consumption for refactored RmSrc, RmDest, RmGDest tables
 *           2018-02-12  visfrm  ESCAN00098365   OS error 0x2C01 occurs
 *           2018-02-16  visfrm  STORYC-4290     Analyze Core Specific RMW Variable Usage Step1
 * 11.05.00  2018-02-19  visfrm  STORYC-3934     Process dept of R20.4
 *           2018-02-23  visfrm  ESCAN00098624   Compiler error: 'PduR_IsIfCancelTransmitSupportedOfMmRom'/'PduR_RmIf_MultipleSourceHandler_CancelTransmit' undefined
 * 12.00.00  2018-02-23  visspt  STORYC-3240     Support Deferred TP Processing
 * 12.01.00  2018-04-26  visfrm  STORYC-5154     Implement efficient multicore queue for If routings
 *           2018-05-16  visfrm  STORYC-5027     Improve ROM Consumption
 *           2018-05-17  visssg  STORYC-4400     MISRA-C:2012 PduR
 *           2018-05-25  visfrm  STORYC-5438     Add deferred Event Cache
 * 12.02.00  2018-06-11  visfrm  STORYC-4890     Release PduRBswModules on different Cores
 * 12.03.00  2018-08-09  visfrm  ESCAN00100103   Transport protocol Queued Tx API forwarding routing path does not work
 *           2018-08-24  visldi  ESCAN00100510   MISRA deviation: MISRA-C:2012 Dir4.1, Rule18.1, Rule21.18 Apparent: Dereference of an invalid pointer value
 *           2018-08-24  visldi  ESCAN00100517   MISRA deviation: MISRA-C:2012 Rule10.6 A composite expression of 'essentially unsigned' type (%1s) is being converted to wider unsigned type, '%2s' on assignment
 *           2018-08-24  visldi  ESCAN00100515   MISRA deviation: MISRA-C:2012 Rule2.2 This operation is redundant. The value of the result is always that of the left-hand operand
 *           2018-08-24  visldi  ESCAN00100519   MISRA deviation: MISRA-C:2012 Rule10.4 The operands of this bitwise operator are of different 'essential signedness' but will generate a result of type 'signed int'
 *           2018-08-24  visldi  ESCAN00100512   MISRA deviation: MISRA-C:2012 Rule2.2 The result of this logical operation is always 'true'
 *           2018-08-24  visldi  ESCAN00100514   MISRA deviation: MISRA-C:2012 Rule2.7 The parameter 'bmTxBufferInstanceRomIdx' is not used in this function.
 * 12.03.01  2019-01-28  visfrm  ESCAN00100313   Queued Transport Protocol routing path with queue depth 1 does not work
 *********************************************************************************************************************/
#ifndef PDUR_H
# define PDUR_H

/**********************************************************************************************************************
 * MISRA / PCLINT JUSTIFICATION
 *********************************************************************************************************************/
/* PRQA S 3453 EOF */ /* MD_MSR_FctLikeMacro */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
/* \trace SPEC-2020230, SPEC-38402 */

# include "PduR_Types.h"
# include "PduR_Cfg.h"
# if (PDUR_DEV_ERROR_REPORT == STD_ON)
#  include "Det.h"
# endif
# include "PduR_Lcfg.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/



/*********************************************************************************************************************/
/* Version                  (abcd: Main version ab Sub Version cd )                                                  */
/*********************************************************************************************************************/

/* AUTOSAR Version Information */
# define PDUR_AR_RELEASE_MAJOR_VERSION       4u
# define PDUR_AR_RELEASE_MINOR_VERSION       0u
# define PDUR_AR_RELEASE_REVISION_VERSION    3u

# define PDUR_SW_MAJOR_VERSION  12u  /**< Major version */
# define PDUR_SW_MINOR_VERSION   3u  /**< Minor version */
# define PDUR_SW_PATCH_VERSION   1u  /**< Patch level version */

/*********************************************************************************************************************/
/* Module Identification                                                                                            */
/*********************************************************************************************************************/
/* \trace SPEC-626, SPEC-1246 */

# define PDUR_VENDOR_ID           30u
# define PDUR_MODULE_ID           51u

/** \defgroup DetErrorIDs DetError IDs
    \brief    Det Error IDs as reported to DET. */
/*  \trace SPEC-2020179 */
/** This error code is only used in conjunction with post-build configuration: An invalid post-build configuration data
 *  pointer has been handled to PduR_Init(). The error is either caused by a failed consistency check or because a null
 *  pointer was handled to PduR_Init(). */

# define PDUR_E_CONFIG_PTR_INVALID             ((uint8)0x00u)
/** An API service has been used without a call of PduR_Init() or PduR_Init() was called while the PDU Router is
 *  initialized. If your system does not use a start-up code to initialize global variables,
 *  PduR_InitMemory() can be called before PduR_Init() to avoid this problem. */

# define PDUR_E_INVALID_REQUEST                ((uint8)0x01u)
/** An invalid PDU identifier was used as parameter for a PDU Router API call. */
# define PDUR_E_PDU_ID_INVALID                 ((uint8)0x02u)
/** TP Gateway was not able to transmit a TP Tx I-PDU due to an error reported by the TP layer. The gateway will abort
 *  the routing and not attempt a re-transmission. */
# define PDUR_E_TP_TX_REQ_REJECTED             ((uint8)0x03u)
/** If  any  of  the  parameter passed  is  out  of  respective ranges */
# define PDUR_E_PARAM_INVALID                  ((uint8)0x04u)
/**A I-PDU ID is received that is already in process  */
# define PDUR_E_DUPLICATE_IPDU_ID              ((uint8)0x06u)
/** I-PDU is longer than expected */
# define PDUR_E_IPDU_TOO_LONG                  ((uint8)0x07u)
/** If  the  routing  table  is  invalid that is given to the PduR_EnableRouting or PduR_DisableRouting functions */
# define PDUR_E_ROUTING_PATH_GROUP_ID_INVALID  ((uint8)0x08u)
/** Pointer parameter is null */
# define PDUR_E_NULL_POINTER                   ((uint8)0x09u)
/** PDU Router initialization failed \trace SPEC-38417 */
# define PDUR_E_INIT_FAILED                    ((uint8)0x0Bu)
/** Loss of a PDU instance (FIFO flushed because of an overrun) */
# define PDUR_E_PDU_INSTANCES_LOST             ((uint8)0x0Au)

/** An internal PDU Router error occurred that was eventually caused by incorrect or manipulated configuration data. */
# define PDUR_E_INVALID_CFG_DATA               ((uint8)0xA0u)
/** The indicated API was called although the current PDU Router configuration and internal state does not expect a
 *  call to this API. */
# define PDUR_E_UNEXPECTED_CALL                ((uint8)0xA1u)

/** Fatal error */
# define PDUR_E_FATAL                          ((uint8)0xFFu)

/** Indication or Transmit Request queue is full */
# define PDUR_E_MCQ_QUEUE_OVERFLOW             ((uint8)0xB0u)
/** Indication or Transmit Request queue is full */
# define PDUR_E_EVC_QUEUE_OVERFLOW             ((uint8)0xB1u)

/** Returned core Id is invalid */
# define PDUR_E_INVALID_CORE_ID                ((uint8)0xB2u)

/** \defgroup ServiceIDs Service IDs
    \brief    Service IDs as reported to DET. */
/** Service ID PduR_Init */
# define PDUR_FCT_INIT                 ((uint8)0x00u)

/** Service ID PduR_GetVersionInfo */
# define PDUR_FCT_VERSIONINFO          ((uint8)0xf1u)
/** Service ID PduR_GetConfigurationId */
# define PDUR_FCT_CONFIGURATIONID      ((uint8)0xf2u)

/** Service ID internal function */
# define PDUR_FCT_MULTIIFRXIND         ((uint8)0x80u)
/** Service ID internal function */
# define PDUR_FCT_RMIF_RXIND           ((uint8)0x81u)
/** Service ID internal function */
# define PDUR_FCT_RMIF_TXCONF          ((uint8)0x82u)
/** Service ID internal function */
# define PDUR_FCT_RMIF_TXTT            ((uint8)0x83u)
/** Service ID internal function */
# define PDUR_FCT_RMIF_FQ              ((uint8)0x8Bu)
/** Service ID internal function */
# define PDUR_FCT_RMTP_TPRXIND         ((uint8)0x85u)
/** Service ID internal function */
# define PDUR_FCT_RMTP_TPTXCONF        ((uint8)0x86u)
/** Service ID internal function */
# define PDUR_FCT_RMTP_ROUTE           ((uint8)0x87u)
/** Service ID internal function */
# define PDUR_FCT_RMTP_SORX            ((uint8)0x88u)
/** Service ID internal function */
# define PDUR_FCT_RMTP_CPYRX           ((uint8)0x89u)
/** Service ID internal function */
# define PDUR_FCT_RMTP_CPYTX           ((uint8)0x8Au)
/** Service ID internal function */
# define PDUR_FCT_GW_BUFMGR_PUT_BETWEEN_WRITEIDX_ENDIDX   ((uint8)0x8Bu)
/** Service ID internal function */
# define PDUR_FCT_GW_BUFMGR_PUT_BETWEEN_WRITEIDX_READIDX  ((uint8)0x8Cu)
/** Service ID internal function */
# define PDUR_FCT_GW_BUFMGR_GET_BETWEEN_READIDX_ENDIDX    ((uint8)0x8Du)
/** Service ID internal function */
# define PDUR_FCT_GW_BUFMGR_GET_BETWEEN_READIDX_WRITEIDX  ((uint8)0x8Eu)
/** Service ID internal function */
# define PDUR_FCT_RMIF_FIFOMGR_APPENDELEMENT              ((uint8)0x93u)
/** Service ID internal function */
# define PDUR_FCT_RMIF_FIFOMGR_OVERWRITEELEMENT           ((uint8)0x94u)
/** Service ID internal function */
# define PDUR_FCT_RMTP_TRANSMITPREPARATION                ((uint8)0x95u)
/** Service ID internal function */
# define PDUR_FCT_PDUR_RMIF_RXINDICATION_ROUTE_FIB        ((uint8)0x96u)
/** Service ID internal function */
# define PDUR_FCT_PDUR_RMIF_RXINDICATION_UPDATE_FIB_AND_ROUTE        ((uint8)0x97u)
/** Service ID internal function */
# define PDUR_FCT_PDUR_RMIF_RXINDICATION_UPDATE_FIB_AND_ROUTE_MULTI  ((uint8)0x98u)
/** Service ID internal function */
# define PDUR_FCT_PDUR_RMTP_LOANDUPTRANSMIT  ((uint8)0x99u)
/** Service ID internal function */
# define PDUR_RMTP_TXINSTSM_TPTXCONFIRMATION_ACTIVEORABORTED ((uint8)0x9Au)
/** Service ID internal function */
# define PDUR_RMTP_TXINSTSM_TPCANCELTRANSMIT_FATALERROR ((uint8)0x9Bu)
/** Service ID internal function */
# define PDUR_RMTP_FIFOSM_ACTIVATENEXT_FATALERROR ((uint8)0x9Du)
/** Service ID internal function */
# define PDUR_RMTP_RXSM_TPRXINDICATION_UNEXPECTEDCALL  ((uint8)0x9Fu)
/** Service ID internal function */
# define PDUR_RMTP_TXINSTSM_TPTXCONFIRMATION_UNEXPECTEDCALL ((uint8)0xA2u)
 /** Service ID internal function */
# define PDUR_RMTP_FIFOSM_CHECKREADY2TRANSMIT_FATALERROR ((uint8)0xA4u)
/** Service ID internal function */
# define PDUR_RMTP_FIFOSM_RXFINISHED_FATALERROR ((uint8)0xA5u)
/** Service ID internal function */
# define PDUR_RMTP_FIFOSM_TXFINISHED_FATALERROR ((uint8)0xA6u)
/** Service ID internal function */
# define PDUR_RXSM_TPCANCELRECEIVE_FATALERROR ((uint8)0xA6u)
/** Service ID internal function */
# define PDUR_RXSM_COPYRXDATA_UNEXPECTEDCALL ((uint8)0xA7u)
/** Service ID internal function */
# define PDUR_RMTP_TXINSTSM_COPYTXDATA_UNEXPECTEDCALL ((uint8)0xA8u)
/** Service ID internal function */
# define PDUR_RMTP_MULTIPLESOURCEHANDLER_TPTXCONFIRMATION ((uint8)0xA9u)
/** Service ID internal function */
# define PDUR_RMTP_MULTIPLESOURCEHANDLER_CANCELTRANSMIT ((uint8)0xAAu)
/** Service ID internal function */
# define PDUR_RMTP_MULTIPLESOURCEHANDLER_COPYTXDATA ((uint8)0xABu)
/** Service ID internal function */
# define PDUR_RMTP_TXINSTSM_TPTRIGGERTRANSMIT_ACTIVEORABORTED ((uint8)0xACu)
/** Service ID internal function */
# define PDUR_RMIF_MULTIPLESOURCEHANDLER_CANCELTRANSMIT ((uint8)0xADu)
/** Service ID internal function */
# define PDUR_TXINSTSM_COPYTXDATA_RMTXINSTACTIVE ((uint8)0xAEu)
/** Service ID internal function */
# define PDUR_GW_BUFMGR_UPDATEMAINREADIDX ((uint8)0xAFu)
/** Service ID internal function */
# define PDUR_RMIF_MULTIPLESOURCEHANDLER_TRIGGERTRANSMIT ((uint8)0xB0u)
/** Service ID internal function */
# define PDUR_GW_BUFMGR_UPDATEMAIN_AFTER_GETDATA ((uint8)0xB1u)
/** Service ID internal function */
# define PDUR_GW_BUFMGR_UPDATEMAIN_AFTER_GETDATA_STATEHANDLER_BUFFER_FULL_OR_READ4WRITE ((uint8)0xB2u)
/** Service ID internal function */
# define PDUR_GW_BUFMGR_UPDATEMAIN_AFTER_GETDATA_STATEHANDLER_BUFFER_WRITE4READ ((uint8)0xB3u)
/** Service ID internal function */
# define PDUR_RMTP_TXSM_CHECK4TXFINISH_FATALERROR  ((uint8)0xB4u)
/** Service ID internal function */
# define PDUR_RMTP_ASSIGNASSOCIATEDBUFFER2DESTINATION  ((uint8)0xB5u)
/** Service ID internal function */
# define PDUR_RMTP_TXINSTSM_TPTRIGGERTRANSMIT_FATALERROR ((uint8)0xB6u)
/** Service ID internal function */
# define PDUR_FM_ACTIVATENEXT ((uint8)0xB7u)
/** Service ID internal function */
# define PDUR_RM_TPTRIGGERTRANSMIT_FATALERROR ((uint8)0xB8u)
/** Service ID internal function */
# define PDUR_RMIF_INIT_DEDICATEDTXBUFFER  ((uint8)0xB9u)
/** Service ID internal function */
# define PDUR_RMIF_INIT_TTSINGLEBUFFER ((uint8)0xBAu)
/** Service ID internal function */
# define PDUR_RMTP_INIT_DEDICATEDTXBUFFER ((uint8)0xBBu)
/** Service ID internal function */
# define PDUR_RMIF_SINGLEBUFFERHANDLING ((uint8)0xBCu)
/** Service ID internal function */
# define PDUR_RMIF_DFIFOANDTTFIFOHANDLING ((uint8)0xBDu)
/** Service ID internal function */
# define PDUR_FM_FREEFIFOELEMENT ((uint8)0xBFu)
/** Service ID internal function */
# define PDUR_FM_ACTIVATEWRITE ((uint8)0xC0u)
/** Service ID internal function */
# define PDUR_FMFINISHREAD ((uint8)0xC1u)
/** Service ID internal function */
# define  PDUR_FMACTIVATEREAD ((uint8)0xC2u)
/** Service ID internal function */
# define  PDUR_RXSM_STARTOFRECEPTION ((uint8)0xC3u)
/** Service ID internal function */
# define  PDUR_FINISHRECEPTION ((uint8)0xC4u)
/** Service ID internal function */
# define  PDUR_FCT_CHPARA ((uint8)0xC5u)
/** Service ID internal function */
# define  PDUR_FCT_CRX ((uint8)0xC6u)
/** Service ID internal function */
# define PDUR_FCT_CTX ((uint8)0xC7u)
/** Service ID internal function */
# define PDUR_FCT_TX ((uint8)0xC8u)
/** Service ID internal function */
# define PDUR_FCT_IFRXIND ((uint8)0xC9u)
/** Service ID internal function */
# define PDUR_FCT_IFTXCFM ((uint8)0xCAu)
/** Service ID internal function */
# define PDUR_FCT_TT ((uint8)0xCBu)
/** Service ID internal function */
# define PDUR_FCT_SOR ((uint8)0xCCu)
/** Service ID internal function */
# define PDUR_FCT_CPYRX ((uint8)0xCDu)
/** Service ID internal function */
# define PDUR_FCT_CPYTX ((uint8)0xCEu)
/** Service ID internal function */
# define PDUR_FCT_TPRXIND ((uint8)0xCFu)
/** Service ID internal function */
# define PDUR_FCT_TPTXCFM ((uint8)0xD0u)
/** Service ID internal function */
# define PDUR_RMIF_MULTIPLESOURCEHANDLER_TXCONFIRMATION ((uint8)0xD3u)
/** Service ID internal function */
# define PDUR_FCT_MAINFUNCTION_TX ((uint8)0xD4u)

/** Service ID internal function */
# define PDUR_LOCK_LOCK ((uint8)0xD5u)
/** Service ID internal function */
# define PDUR_LOCK_UNLOCK ((uint8)0xD5u)

/** Service ID internal function */
# define PDUR_MCQ_WRITE_DATA ((uint8)0xDAu)
/** Service ID internal function */
# define PDUR_MCQ_MAINFUNCTION ((uint8)0xDAu)

/** Service ID internal function */
# define PDUR_EVC_PUT ((uint8)0xDBu)

/** Service ID internal function */
# define PDUR_MCQ_PENDING_READ_IDX ((uint8)0xDCu)

# if(PDUR_RPGROM == STD_ON)
/** Service ID PduR_EnableRouting */
#  define PDUR_FCT_ENABLEROUTING        ((uint8)0x8Du)
/** Service ID PduR_DisableRouting */
#  define PDUR_FCT_DISABLEROUTING       ((uint8)0x8Eu)
# endif

# define PDUR_E_NO_ERROR                ((uint8)0u)
# define PDUR_E_ALREADY_INITIALIZED     ((uint8)1u)
# define PDUR_INIT                      ((uint8)2u)
/* old define was PDUR_E_INVALID_REQUEST therefore used 1 in this case, later another number should be used */
# define PDUR_E_UNINIT                  ((uint8)1u)
# define PDUR_E_INVALID_HANDLE          ((uint8)4u)
/* \trace SPEC-38417 */
# define PDUR_E_PARAM_POINTER           ((uint8)9u)

# if (PDUR_DEV_ERROR_REPORT == STD_ON)
#  define PduR_Det_ReportError(ApiId, ErrorCode)  (void)Det_ReportError(PDUR_MODULE_ID, 0U, (ApiId), (ErrorCode))
#  define PduR_ReportRuntimeDetError(ApiId, ErrorCode) (void) Det_ReportRuntimeError(PDUR_MODULE_ID, 0U, (ApiId), (ErrorCode))
# else
#  define PduR_Det_ReportError(ApiId, ErrorCode)
#  define PduR_ReportRuntimeDetError(ApiId, ErrorCode)
# endif /* (PDUR_DEV_ERROR_REPORT == STD_ON) */

# include "vstdlib.h"
/*********************************************************************************************************************/
/* User Configuration File Configurable Features (can be modified using the user configuration file)                 */
/*********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define PDUR_START_SEC_CODE
# include "MemMap.h"    /* PRQA S 5087 */       /* MD_MSR_MemMap */

/**********************************************************************************************************************
  PduR_GetConfigurationId
**********************************************************************************************************************/
/*! \brief        Provides the unique identifier of the PDUR configuration.
 *  \details      If the API is called in pre-compile or post-build variant and the module is not initialized "0"
 *                else the configuration Id is returned.
 *   \return      the configuration Id
 *   \pre         PduR_Init() is executed successfully.
 *   \context     TASK|ISR1|ISR2
 *   \reentrant   FALSE
 *   \synchronous TRUE
 *   \trace       CREQ-1235
 *   \trace       SPEC-1049, SPEC-38467, SPEC-1257, SPEC-1327
 *   \note        The function is called by the Application.
 *********************************************************************************************************************/
FUNC(PduR_PBConfigIdType, PDUR_CODE) PduR_GetConfigurationId(void);

/**********************************************************************************************************************
  PduR_Init
**********************************************************************************************************************/
/*! \brief       This function initializes the PDUR
 *  \details     Initializes all component variables and sets the component state to initialized.
 *  \param[in]   ConfigPtr  NULL_PTR if PDUR_USE_INIT_POINTER is STD_OFF
 *                          Pointer to the PduR configuration data if PDUR_USE_INIT_POINTER is STD_ON
 *  \pre         Interrupts are disabled.
 *  \pre         Module is uninitialized.
 *  \pre         PduR_InitMemory has been called unless PduR_ModuleInitialized is initialized by start-up code.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        In Multi Core UseCase: This function shall only be called ONCE and NOT for each core.
 *  \trace       SPEC-38464
 ********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Init(P2CONST(PduR_PBConfigType, AUTOMATIC, PDUR_PBCFG) ConfigPtr);

/**********************************************************************************************************************
  PduR_InitMemory
**********************************************************************************************************************/
/*! \brief       Power-up memory initialization
 *  \details     Initializes component variables in *_INIT_* sections at power up.
 *  \pre         Module is uninitialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        Use this function in case these variables are not initialized by the startup code.
 ********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_InitMemory(void);

/**********************************************************************************************************************
 *  General PduR API
 *********************************************************************************************************************/
# if(PDUR_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
  PduR_GetVersionInfo
**********************************************************************************************************************/
/*! \brief       Returns the version information of the PDUR.
 *  \details     -
 *  \param[out]  versionInfo     Pointer to where to store the version information of the PDUR.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-1236
 *  \trace       SPEC-38447
 *  \note        The function is called by the Application.
**********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, PDUR_APPL_DATA) versionInfo);
# endif
# if (PDUR_TX2LO == STD_ON)
/**********************************************************************************************************************
 * PduR_UpTransmit
 *********************************************************************************************************************/
/*!
 * \brief        The function serves to request the transmission of an upper layer I-PDU.\n
 *               The PDU Router evaluates the upper layer I-PDU handle and identifies the destination(s) of the PDU.\n
 *               The call is routed to a lower IF module using the appropriate I-PDU handle of the destination layer.
 * \details       -
 * \param[in]    id                ID of the upper layer I-PDU to be transmitted
 * \param[in]    info              Payload information of the I-PDU (pointer to data and data length).
 * \return       Std_ReturnType\n
 *               E_OK              The request was accepted by the PDU Router and by the destination layer.\n
 *               E_NOT_OK          The PDU Router is in the PDUR_UNINIT state\n
 *                                 or the UpTxPduId is not valid\n
 *                                 or the UpTxPduId is not forwarded in this identity\n
 *                                 or the info is not valid\n
 *                                 or the request was not accepted by the destination layer.\n
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
 * \note        The function is called by upper layer.\n
 * \trace       DSGN-PduR_TP_Forwarding
 * \trace       SPEC-666, SPEC-679, SPEC-686, SPEC-1827, SPEC-1096, SPEC-2020085, SPEC-38411
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_UpTransmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);
# endif
# if (PDUR_RXIF2DEST == STD_ON)
/**********************************************************************************************************************
 * PduR_LoIfRxIndication
 *********************************************************************************************************************/
/*!
 * \brief        The function is called by the lower layer to indicate the complete reception of a lower layer I-PDU.\n
 *               The PDU Router evaluates the lower layer I-PDU handle and identifies the destination(s) of the PDU.\n
 *               The call is routed to an upper IF module using the appropriate I-PDU handle of the destination layer.
 *  \details     -
 * \param[in]    RxPduId     ID of the received lower layer I-PDU
 * \param[in]    info        Payload information of the received I-PDU (pointer to data and data length)
 * \pre          -
 * \context      TASK|ISR1|ISR2
 * \reentrant    TRUE
 * \synchronous  TRUE
 * \trace        DSGN-PduR_IF_Forwarding
 * \trace        SPEC-666, SPEC-674, SPEC-1096, SPEC-2020085
 * \note         The function is called by lower layer communication interface.
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_LoIfRxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);
# endif
# if ((PDUR_TRIGGERTRANSMITSUPPORTEDOFRMSRCROM == STD_ON) || (PDUR_EXISTS_T_T_SINGLE_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON) || (PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM == STD_ON))
/**********************************************************************************************************************
 * PduR_LoIfTriggerTransmit
 *********************************************************************************************************************/
/*!
 * \brief      The function is called by the lower layer to request the lower layer TX I-PDU before transmission.\n
 *             The PDU Router evaluates the lower layer I-PDU handle and identifies the destination(s) of the PDU.
 *             The call is routed to an upper IF module using the appropriate I-PDU handle of the destination layer.
 *  \details     -
 * \param[in]  TxPduId       ID of the lower layer I-PDU that will be transmitted
 * \param[in,out]  info          Contains a pointer to a buffer (SduDataPtr) to where the SDU
 *                               data shall be copied, and the available buffer size in SduLengh.
 *                               On return, the service will indicate the length of the copied SDU
 *                               data in SduLength.
 * \return       Std_ReturnType\n
 *                 E_OK          SDU has been copied and SduLength indicates the number of copied bytes.
 * \return         E_NOT_OK      No data has been copied, because
 *                               PduR is not initialized
 *                               or TxPduId is not valid
 *                               or PduInfoPtr is NULL_PTR
 *                               or SduDataPtr is NULL_PTR
 *                               or SduLength is too small.
 * \pre      -
 * \context  TASK|ISR1|ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace    DSGN-PduR_IF_Forwarding
 * \trace    SPEC-666, SPEC-1828
 * \note     The function is called by lower layer communication interface.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_LoIfTriggerTransmit(PduIdType TxPduId, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);
# endif
# if (PDUR_TXCONFIRMATIONUSEDOFTXIF2UP == STD_ON)
/**********************************************************************************************************************
 * PduR_LoIfTxConfirmation
 *********************************************************************************************************************/
/*!
 * \brief      The function is called by the lower layer to confirm the complete transmission of a lower layer I-PDU.\n
 *             The PDU Router evaluates the lower layer I-PDU handle and identifies the destination(s) of the PDU.\n
 *             The call is routed to an upper IF module using the appropriate I-PDU handle of the destination layer.
 * \details     -
 * \param[in]  TxPduId           ID of the transmitted lower layer I-PDU
 * \pre        -
 * \context    TASK|ISR1|ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace      DSGN-PduR_IF_Forwarding
 * \trace      SPEC-666, SPEC-38455, SPEC-38450
 * \note       The function is called by lower layer communication interface.
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_LoIfTxConfirmation(PduIdType TxPduId);
# endif
# if (PDUR_RXTP2DEST == STD_ON)
/**********************************************************************************************************************
 * PduR_LoTpStartOfReception
 *********************************************************************************************************************/
/*!
 * \brief        This function will be called by the lower layer Tp at the start of a I-PDU reception.\n
 *               The I-PDU might be fragmented into multiple N-PDUs\n
 *               (FF with one or more following CFs) or might consist of a single N-PDU (SF).\n
 *               The PDU Router evaluates the lower layer Tp I-PDU handle and identifies the destination(s) of the PDU.\n
 *               The call is routed to an upper Tp or gateway module using the appropriate I-PDU handle of the\n
 *               destination layer.
 *  \details     -
 * \param[in]    id                ID of the lower layer Tp I-PDU that will be received.\n
 * \param[in]    info              Pointer to the buffer with meta data if the meta data feature is used (SduDataPtr) \n
 *                                 length empty (use configured length) \n
 * \param[in]    TpSduLength       Length of the entire the lower layer Tp SDU which will be received.\n
 * \param[out]   bufferSizePtr     Pointer to the receive buffer in the receiving module.\n
 *                                 This parameter will be used to compute Block Size (BS) in the transport protocol module.
 * \return       BufReq_ReturnType\n
 *               BUFREQ_OK         Connection has been accepted. bufferSizePtr indicates the available receive buffer.\n
 *               BUFREQ_E_NOT_OK   The PDU Router is in the PDUR_UNINIT state\n
 *                                 or the id is not valid\n
 *                                 or the id is not forwarded in this identity\n
 *                                 or the request was not accepted by the destination layer.\n
 *                                 or no buffer is available.\n
 * \pre          -
 * \context      TASK|ISR1|ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace        DSGN-PduR_TP_Forwarding
 * \trace        SPEC-666, SPEC-1096, SPEC-2020085, SPEC-38410
 * \note         The function is called by lower layer Tp.
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpStartOfReception(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, PduLengthType TpSduLength,
                                                             P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr);
# endif
# if (PDUR_RXTP2DEST == STD_ON)
/**********************************************************************************************************************
 * PduR_LoTpCopyRxData
 *********************************************************************************************************************/
/*!
 * \brief    This function is called by the lower layer Tp if data has to be to copied to the receiving module.\n
 *           Each call to this function copies the next part of the received data.\n
 *           Several calls may be made during transportation of an I-PDU.\n
 *           The PDU Router evaluates the lower layer Tp I-PDU handle and identifies the destination(s) of the PDU.\n
 *           The call is routed to an upper Tp or gateway module using the appropriate I-PDU handle of the\n
 *           destination layer.
 *  \details     -
 * \param[in]    id                ID of the lower layer Tp I-PDU that will be received
 * \param[in]    info              Pointer to the buffer (SduDataPtr) and its length (SduLength)\n
 *                             containing the data to be copied by PDU Router module in case of gateway\n
 *                             or upper layer module in case of reception.\n
 *                             A copy size of 0 can be used to poll the available buffer size.
 * \param[out]  bufferSizePtr     Available receive buffer after data has been copied.
 * \return   BufReq_ReturnType\n
 *           BUFREQ_OK         Buffer request accomplished successful\n
 *           BUFREQ_E_NOT_OK   The PDU Router is in the PDUR_UNINIT state\n
 *                             or the id is not valid\n
 *                             or the id is not forwarded in this identity\n
 *                             or the infois not valid\n
 *                             or the request was not accepted by the destination layer\n
 *                             or no buffer is available.\n
 *           BUFREQ_E_OVFL     The upper TP module is not able to receive the number of bytes.\n
 *                             The request was not accepted by the destination layer.
 * \pre      -
 * \context  TASK|ISR1|ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace    DSGN-PduR_TP_Forwarding
 * \trace    SPEC-666, SPEC-1096, SPEC-2020085, SPEC-38432
 * \note     The function is called by lower layer Tp.
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpCopyRxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr);
# endif
# if (PDUR_RXTP2DEST == STD_ON)
/**********************************************************************************************************************
 * PduR_LoTpRxIndication
 *********************************************************************************************************************/
/*!
 * \brief    The function is called by the lower layer Tp to indicate the complete reception of a lower layer Tp I-PDU or to\n
 *           report an error that occurred during reception. The PDU Router evaluates the lower layer Tp I-PDU handle and\n
 *           performs appropriate handle and port conversion. The call is routed to an upper Tp module using the\n
 *           appropriate I-PDU handle of the destination layer.
 *  \details     -
 * \param[in]    id                              ID of the received lower layer Tp I-PDU
 * \param[out]    result                     Result of the TP reception\n
 *           E_OK                            The TP transmission has been completed successfully.\n
 *           E_NOT_OK                        The PDU Router is in the PDUR_UNINIT state\n
 *                                           or the LoTpTxPduId is not valid\n
 *                                           or the LoTpTxPduId is not forwarded in this identity\n
 *                                           or the request was not accepted by the destination upper layer.\n
 * \pre      -
 * \context  TASK|ISR1|ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace    DSGN-PduR_TP_Forwarding
 * \trace    SPEC-666, SPEC-674, SPEC-38409
 * \note     The function is called by lower layer Tp.
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_LoTpRxIndication(PduIdType id, Std_ReturnType result);
# endif
# if(PDUR_TXTP2SRC == STD_ON)
/**********************************************************************************************************************
 * PduR_LoTpCopyTxData
 *********************************************************************************************************************/
/*!
 * \brief    This function is called by the lower layer Tp to query the transmit data of an I-PDU segment.\n
 *           Each call to this function copies the next part of the transmit data.\n
 *           The PDU Router evaluates the lower layer Tp I-PDU handle and identifies the destination(s) of the PDU.
 *           The call is routed to an upper Tp or gateway module using the appropriate I-PDU handle of the\n
 *           destination layer.
 *  \details     -
 * \param[in]    id                ID of the lower layer Tp I-PDU that will be transmitted
 * \param[in]    info              Pointer to the destination buffer and the number of bytes to copy.\n
 *                             In case of gateway the PDU Router module will copy otherwise the source \n
 *                             upper layer module will copy the data. If not enough transmit data is available,\n
 *                             no data is copied.\n
 *                             A copy size of 0 can be used to poll the available Tx data.
 * \param[in]    retry             retry not supported yet. Is not used.
 * \param[out]    availableDataPtr  Indicates the remaining number of bytes that are available in the PduR Tx buffer.\n
 *                             availableDataPtr can be used by TP modules that support dynamic payload lengths\n
 *                             (e.g. Iso FrTp) to determine the size of the following CFs.
 * \return   BufReq_ReturnType\n
 *           BUFREQ_OK         The data has been copied to the transmit buffer successful\n
 *           BUFREQ_E_BUSY     Request could not be fulfilled, because the required amount of \n
 *                             Tx data is not available. The LoTp module can either retry the request \n
 *           BUFREQ_E_NOT_OK   The PDU Router is in the PDUR_UNINIT state\n
 *                             or the id is not valid\n
 *                             or the id is not forwarded in this identity\n
 *                             or the info pointer is not valid\n
 *                             or the request was not accepted by the destination layer\n
 *                             or the request length to copy is greater than the remaining buffer size.
 * \pre      -
 * \context  TASK|ISR1|ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace    DSGN-PduR_TP_Forwarding
 * \trace    SPEC-666, SPEC-1096, SPEC-2020085, SPEC-38401
 * \note     The function is called by lower layer Tp.
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpCopyTxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
                                                       P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr);
# endif
# if (PDUR_TXTP2SRC == STD_ON)
/**********************************************************************************************************************
 * PduR_LoTpTxConfirmation
 *********************************************************************************************************************/
/*!
 * \brief    The function is called by the lower layer Tp to confirm the complete transmission of a lower layer Tp I-PDU or to\n
 *           report an error that occurred during reception. The PDU Router evaluates the lower layer Tp I-PDU handle and\n
 *           performs appropriate handle and port conversion.The call is routed to an upper Tp module using the\n
 *           appropriate I-PDU handle of the destination layer.
 * \details     -
 * \param[in]    id                              ID of the transmitted lower layer Tp I-PDU
 * \param[out]   result                          Result of the TP transmission\n
 *           E_OK                            The TP transmission has been completed successfully.\n
 *           E_NOT_OK                        The PDU Router is in the PDUR_UNINIT state\n
 *                                           or the LoTpTxPduId is not valid\n
 *                                           or the LoTpTxPduId is not forwarded in this identity\n
 *                                           or the request was not accepted by the destination upper layer.\n
 * \pre      -
 * \context  TASK|ISR1|ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace    DSGN-PduR_TP_Forwarding
 * \trace    SPEC-666
 * \note     The function is called by lower layer Tp.
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_LoTpTxConfirmation(PduIdType id, Std_ReturnType result);
# endif
# if (PDUR_CANCELRECEIVESUPPORTEDOFMMROM == STD_ON)
/**********************************************************************************************************************
 * PduR_CancelReceive
 *********************************************************************************************************************/
/*!
 * \brief    The function serves to cancel the reception of a TP layer I-PDU.\n
 *           The PDU Router evaluates the upper layer I-PDU handle and identifies the destination(s) of the PDU.\n
 *           The call is routed to a lower TP module using the appropriate I-PDU handle of the destination layer.
 * \details     -
 * \param[in]    id                ID of the upper layer I-PDU to be cancelled.
 * \return   Std_ReturnType\n
 *           E_OK              Cancellation was executed successfully by the destination module.
 *           E_NOT_OK          Cancellation was rejected by the destination module.
 * \pre      -
 * \context  TASK|ISR1|ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace    DSGN-PduR_TP_CancelReceive
 * \trace    SPEC-1009, SPEC-1096, SPEC-2020085, SPEC-38446
 * \note     The function is called by upper layer.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_CancelReceive(PduIdType id);
# endif
# if (PDUR_CHANGEPARAMETERSUPPORTEDOFMMROM == STD_ON)
/**********************************************************************************************************************
 * PduR_ChangeParameter
 *********************************************************************************************************************/
/*!
 * \brief       The function serves to change a specific transport protocol parameter (e.g. block-size, STmin).\n
 *              The PDU Router evaluates the  upper layer I-PDU handle and identifies the destination(s) of the PDU.\n
 *              The call is routed to a lower TP module using the appropriate I-PDU handle of the destination layer.
 * \details     -
 * \param[in]   id               ID of the  upper layer I-PDU where the parameter has to be changed.
 * \param[in]   parameter        The TP parameter that shall be changed.
 * \param[in]   value            The new value for the TP parameter.
 * \return      Std_ReturnType\n
 *              E_OK             The parameter was changed successfully.
 *              E_NOT_OK         The parameter change was rejected.
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace       DSGN-PduR_TP_ChangeParameter
 * \trace       SPEC-666, SPEC-38426
 * \note        The function is called by Dcm
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_ChangeParameter(PduIdType id, TPParameterType parameter, uint16 value);
# endif
# if ((PDUR_IFCANCELTRANSMITSUPPORTEDOFMMROM == STD_ON) || (PDUR_TPCANCELTRANSMITSUPPORTEDOFMMROM == STD_ON))
/**********************************************************************************************************************
 * PduR_CancelTransmit
 *********************************************************************************************************************/
/*!
 * \brief    The function serves to cancel the transmission of a IF/TP layer I-PDU.\n
 *           The PDU Router evaluates the upper layer I-PDU handle and identifies the destination(s) of the PDU.\n
 *           The call is routed to a lower TP module using the appropriate I-PDU handle of the destination layer.
 * \details     -
 * \param[in]    id                ID of the upper layer I-PDU to be cancelled
 * \return   Std_ReturnType\n
 *           E_OK              Cancellation was executed successfully by the destination module.
 *           E_NOT_OK          Cancellation was rejected by the destination module.
 * \pre      -
 * \context  TASK|ISR1|ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace    DSGN-PduR_TP_CancelTransmission
 * \trace    SPEC-38442, SPEC-1096, SPEC-2020085, SPEC-38416
 * \note     The function is called by upper layer
**********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_CancelTransmit(PduIdType id);
# endif

# if (PDUR_RPGROM == STD_ON)
/**********************************************************************************************************************
PduR_EnableRouting
**********************************************************************************************************************/
/*! \brief       This function enables a routing path group.
 *  \details     If the routing path group does not exist or is already enabled, the function returns with no action.
 *               PduR_EnableRouting or PduR_DisableRouting calls for the same id.
 *  \param[in]       id    Identification of the routing path group.
 *                  Routing path groups are defined in the PDU router configuration.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       SPEC-38435, SPEC-1254, SPEC-38437
 *  \note        The function is called by the BSW Mode Manager.
 *               The routing of a destination PDU of a PduRRoutingPath which is contained in multiple
 *               PduRRoutingPathGroups start if one related PduRRoutingPathGroups is started.
 **********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_EnableRouting(PduR_RoutingPathGroupIdType id);
# endif

# if (PDUR_RPGROM == STD_ON)
/**********************************************************************************************************************
PduR_DisableRouting
**********************************************************************************************************************/
/*! \brief       This function disables a routing path group.
 *  \details     If the routing path group does not exist or is already disabled, the function returns with no action.
 *               PduR_EnableRouting or PduR_DisableRouting calls for the same id.
 *  \param[in]       id    Identification of the routing path group.
 *                     Routing path groups are defined in the PDU router configuration.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        The function is called by the BSW Mode Manager.
 *               The routing of a destination PDU of a PduRRoutingPath which is contained in multiple
 *               PduRRoutingPathGroups stops if all related PduRRoutingPathGroups are stopped.
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_DisableRouting(PduR_RoutingPathGroupIdType id);
# endif

# if(PDUR_RMGDESTNTO1INFORAMIDXOFRMGDESTROM == STD_ON)
/**********************************************************************************************************************
 * PduR_Rm_MultipleSourceHandler_Reset
 *********************************************************************************************************************/
/*! \brief       Reset RAM variables which hold the N:1 routing information.
 *  \details     -
 *  \param[in]   rmGDestRomIdx             Handle Id of the corresponding global Dest Pdu
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \note        The function is called  in context PduR_RmIf_MultipleSourceHandler_Transmit
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Rm_MultipleSourceHandler_Reset(PduR_RmGDestRomIterType rmGDestRomIdx);
# endif

/**********************************************************************************************************************
 PduR_Rm_GetSrcDestPdu
**********************************************************************************************************************/
/*! \brief      This functions returns the RmDest index of the last transmitted source DestPdu.
 *  \details    -
 *  \param[in]   rmGDestRomIdx        ID of the globalPdu
 *  \param[out]  rmDestRomIdx         ID of the source DestPdu
 *  \return      Std_ReturnType    E_OK:     The SDU has been copied and the SduLength indicates
 *                                           the number of copied bytes.
 *                                 E_NOT_OK: The SDU has not been copied and the SduLength has not been set.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 ***********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_Rm_GetSrcDestPdu(PduR_RmGDestRomIterType rmGDestRomIdx, P2VAR(PduR_RmDestRomIterType, AUTOMATIC, PDUR_APPL_DATA) rmDestRomIdx);

# if (PDUR_DEFERREDEVENTCACHEROM == STD_ON)
/**********************************************************************************************************************
 * PduR_EvC_Put
 *********************************************************************************************************************/
/*! \brief       Write Id into the event queue.
 *  \details     -
 *  \param[in]   deferredEventCacheIdx    Id identify the correct queue to be used
 *  \param[in]   rmGDestRomIdx            Index to the destination Pdu to be queued
 *  \return      E_OK                     Write to the queue was successful.
 *               E_NOT_OK                 Write to the queue was not successful.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_EvC_Put(PduR_DeferredEventCacheRomIdxOfSrcCoreRomType deferredEventCacheIdx, PduR_RmGDestRomIterType rmGDestRomIdx);
# endif

# if (PDUR_DEFERREDEVENTCACHEROM == STD_ON)
/**********************************************************************************************************************
 * PduR_EvC_Get
 *********************************************************************************************************************/
/*! \brief       Read the next rmGDestRomIdx from the event queue, if available
 *  \details -
 *  \param[in]   deferredEventCacheIdx    Id of the correct queue to be used
 *  \param[out]  rmGDestRomIdxPtr         the read rmGDestRomIdx - Caller must ensure validity of the pointer.
 *  \return      E_OK                     Read was successful.
 *               E_NOT_OK                 Read was not successful. Queue is empty.
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_EvC_Get(PduR_DeferredEventCacheRomIdxOfSrcCoreRomType deferredEventCacheIdx, P2VAR(PduR_RmGDestRomIterType, AUTOMATIC, PDUR_APPL_DATA) rmGDestRomIdxPtr);
# endif

# define PDUR_STOP_SEC_CODE
# include "MemMap.h"    /* PRQA S 5087 */       /* MD_MSR_MemMap */
/*!
 * \exclusivearea PDUR_EXCLUSIVE_AREA_0
 * Ensures consistency while performing state changes and buffer handling.
 * \protects all PduR functions
 * \usedin all PduR functions
 * \exclude local functions
 * \length SHORT to LONG depending on the API and the call graph.
 * \endexclusivearea
 */
#endif /* !defined(PDUR_H) */

/**********************************************************************************************************************
 * END OF FILE: PduR.h
 *********************************************************************************************************************/
