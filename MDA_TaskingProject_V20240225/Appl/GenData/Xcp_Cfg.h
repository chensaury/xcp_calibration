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
 *              File: Xcp_Cfg.h
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

    
#if !defined(__XCP_CFG_H__)
#define __XCP_CFG_H__ /* PRQA S 0602, 0603 */ /* MD_XCP_0602_03 */

#ifndef XCP_USE_DUMMY_STATEMENT
#define XCP_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef XCP_DUMMY_STATEMENT
#define XCP_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef XCP_DUMMY_STATEMENT_CONST
#define XCP_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef XCP_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define XCP_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef XCP_ATOMIC_VARIABLE_ACCESS
#define XCP_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef XCP_PROCESSOR_TC397_STEPB
#define XCP_PROCESSOR_TC397_STEPB
#endif
#ifndef XCP_COMP_TASKING
#define XCP_COMP_TASKING
#endif
#ifndef XCP_GEN_GENERATOR_MSR
#define XCP_GEN_GENERATOR_MSR
#endif
#ifndef XCP_CPUTYPE_BITORDER_LSB2MSB
#define XCP_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef XCP_CONFIGURATION_VARIANT_PRECOMPILE
#define XCP_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef XCP_CONFIGURATION_VARIANT_LINKTIME
#define XCP_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef XCP_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define XCP_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef XCP_CONFIGURATION_VARIANT
#define XCP_CONFIGURATION_VARIANT XCP_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef XCP_POSTBUILD_VARIANT_SUPPORT
#define XCP_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/* Development error detecting and reporting */
#define XCP_DEV_ERROR_DETECT                 STD_ON
#define XCP_DEV_ERROR_REPORT                 STD_ON

/* General settings */
#define XCP_BOOTLOADER_DOWNLOAD              STD_OFF
#define XCP_CONTROL                          STD_OFF
#define XCP_AMD_RUNTIME_MEASUREMENT          STD_OFF
#define XCP_VERSION_INFO_API                 STD_OFF 
#define XCP_GET_SESSION_STATUS_API           STD_OFF
#define XCP_TYPESAVE_COPY                    STD_OFF
#define XCP_DAQ_MEM_ACCESS_BY_APPL			 STD_OFF
/* Legacy settings */
#define XCP_DISABLE_UNALIGNED_MEM_ACCESS
#define XCP_ENABLE_SEND_QUEUE

/* Service Request Message */
#define XCP_SERV_TEXT                        STD_OFF
#define XCP_SEND_EVENT                       STD_OFF

/* Commands */
#define XCP_OPEN_COMMAND_IF                  STD_OFF

/*  - Standard Commands */
#define XCP_BLOCK_UPLOAD                     STD_OFF
#define XCP_COMM_MODE_INFO                   STD_OFF
#define XCP_USER_COMMAND                     STD_OFF
#define XCP_SEED_KEY                         STD_OFF
#define XCP_READ_PROTECTION                  STD_OFF
#define XCP_GET_ID_GENERIC                   STD_OFF
#define kXcpStationIdLength                  (0u)

/*    - CRC */
#define XCP_CHECKSUM                         STD_ON
#define XCP_CUSTOM_CRC                       STD_OFF
#define XCP_AUTOSAR_CRC_MODULE               STD_OFF
#define kXcpChecksumMethod                   XCP_CHECKSUM_TYPE_ADD14
#define kXcpChecksumBlockSize                (1024u)

/*  - Calibration commands */
#define XCP_CALIBRATION                      STD_ON
#define XCP_BLOCK_DOWNLOAD                   STD_ON
#define XCP_MODIFY_BITS                      STD_ON
#define XCP_SHORT_DOWNLOAD                   STD_ON
#define XCP_BLOCK_DOWNLOAD_MIN_ST            (1u)

/*  - Synchronous Data Acquisition (DAQ) commands */
#define XCP_DAQ                              STD_ON
#define XCP_NUMBER_OF_CORES                  (1u)
#define XCP_STIM                             STD_OFF
#define XCP_DAQ_PRESCALER                    STD_OFF
#define XCP_DAQ_OVERRUN_INDICATION           STD_ON
#define XCP_WRITE_DAQ_MULTIPLE               STD_OFF
#define XCP_DAQ_HDR_LEN                      (0x00u + 1U)
#define XCP_DAQ_RESUME                       STD_OFF
#define XCP_DAQ_PROCESSOR_INFO               STD_ON
#define XCP_DAQ_RESOLUTION_INFO              STD_OFF

#define XCP_MAX_DAQ                          (765U)
#define XCP_MAX_ODT_DAQ                      (123u)
#define XCP_MAX_ODT_ENTRIES                  (300u)
#define XCP_MAX_ODT_STIM                     (0u)

/*    - DAQ event Info */
#define XCP_DAQ_EVENT_INFO                   STD_ON
#define XCP_MAX_EVENT                        (3u)

/*    - DAQ Timestamp */
#define XCP_DAQ_TIMESTAMP_FIXED              STD_OFF
#define XCP_DAQ_TIMESTAMP_SIZE               XCP_DAQ_TIMESTAMP_OFF
#define XCP_DAQ_TIMESTAMP_UNIT               XCP_DAQ_TIMESTAMP_UNIT_1MS
#define XCP_DAQ_TIMESTAMP_TICKS_PER_UNIT     (1U)

/*  - Page switching */
#define XCP_CALIBRATION_PAGE                 STD_ON
#define XCP_MAX_SEGMENT                      (1u)
#define XCP_PAGE_INFO                        STD_ON
#define XCP_MAX_PAGES                        (2u)
#define XCP_COPY_CAL_PAGE                    STD_ON
#define XCP_PAGE_FREEZE                      STD_OFF

/*  - Programming */
#define XCP_PROGRAM                          STD_OFF
#define XCP_PROGRAMMING_WRITE_PROTECTION     STD_OFF
#define XCP_MAX_SECTOR                       (0u)
#define XCP_PROGRAM_INFO                     STD_OFF
#define kXcpProgramMinStPgm                  (0u)

#ifndef XCP_AUTOSARVERSION
#define XCP_AUTOSARVERSION                   (4u) 
#endif

#define XCP_CANOE_EMU                        STD_OFF


/* -----------------------------------------------------------------------------
    &&&~ Multiple transport layer support
 ----------------------------------------------------------------------------- */

#define XCP_MAX_CTO_MAX                      (8u)
#define XCP_MAX_DTO_MAX                      (8u)
/* Multiple transport layer support */
#define XCP_NUMBER_OF_TRANSPORTLAYERS        (1u)
#define XCP_NUMBER_OF_CHANNELS               ((1U))               

#define XCP_TRANSPORT_LAYER_TYPE_CAN_ASR
#define XCP_TRANSPORT_LAYER_CAN              (0u)

/* -----------------------------------------------------------------------------
    &&&~ FlexRay parameter access
 ----------------------------------------------------------------------------- */

#define XCP_READCCCONFIG                     STD_OFF
#define XCP_ADDR_EXT_READCCCONFIG            (0u)
    

/* end Fileversion check */

#endif /* __XCP_CFG_H__ */

