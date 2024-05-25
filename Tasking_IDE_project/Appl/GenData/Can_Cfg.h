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
 *            Module: Can
 *           Program: MSR_Vector_SLP4
 *          Customer: Aptiv (China) Technology Company Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Aurix 2G/TC397 B-Step
 *    License Scope : The usage is restricted to CBD1900078_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Can_Cfg.h
 *   Generation Time: 2023-04-13 21:32:41
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

/* -----------------------------------------------------------------------------
    Generator Info
 ----------------------------------------------------------------------------- 
  Name:     MICROSAR M_CAN driver Generator
  Version:  4.01.00
  MSN:      Can
  Origin:   CAN
  Descrip:  MICROSAR Can driver generator
  JavaPack: com.vector.cfg.gen.DrvCan_Mpc5700McanAsr
 ----------------------------------------------------------------------------- */

#if !defined(CAN_CFG_H)
#define CAN_CFG_H

/* CAN222, CAN389, CAN365, CAN366, CAN367 */
/* CAN022, CAN047, CAN388, CAN397, CAN390, CAN392  */

/* PRQA S 0779 EOF */ /* MD_MSR_Rule5.2 */

/* -----------------------------------------------------------------------------
    Includes
 ----------------------------------------------------------------------------- */

#include "ComStack_Types.h"

#include "Can_GeneralTypes.h" /* CAN435 */

#if defined (CAN_LCFG_SOURCE) || defined (C_DRV_INTERNAL) /* ESCAN00070085 */
# include "Os.h"
#endif

/* -----------------------------------------------------------------------------
    General Switches for CAN module
 ----------------------------------------------------------------------------- */

#ifndef CAN_USE_DUMMY_STATEMENT
#define CAN_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef CAN_DUMMY_STATEMENT
#define CAN_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CAN_DUMMY_STATEMENT_CONST
#define CAN_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CAN_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CAN_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef CAN_ATOMIC_VARIABLE_ACCESS
#define CAN_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef CAN_CPU_AURIXPLUSS
#define CAN_CPU_AURIXPLUSS
#endif
#ifndef CAN_PROCESSOR_TC397_STEPB
#define CAN_PROCESSOR_TC397_STEPB
#endif
#ifndef CAN_COMP_TASKING
#define CAN_COMP_TASKING
#endif
#ifndef CAN_GEN_GENERATOR_MSR
#define CAN_GEN_GENERATOR_MSR
#endif
#ifndef CAN_CPUTYPE_BITORDER_LSB2MSB
#define CAN_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef CAN_CONFIGURATION_VARIANT_PRECOMPILE
#define CAN_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CAN_CONFIGURATION_VARIANT_LINKTIME
#define CAN_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CAN_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CAN_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CAN_CONFIGURATION_VARIANT
#define CAN_CONFIGURATION_VARIANT CAN_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CAN_POSTBUILD_VARIANT_SUPPORT
#define CAN_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/* -----------------------------------------------------------------------------
    General Switches from old v_cfg.h
 ----------------------------------------------------------------------------- */
#if !defined(V_GEN_GENERATOR5)
# define V_GEN_GENERATOR5 /* need by LL */
#endif
#if !defined(V_ENABLE_CAN_ASR_ABSTRACTION)
# define V_ENABLE_CAN_ASR_ABSTRACTION /* ATK */
#endif
#define CAN_GEN_COM_STACK_LIB

#if !defined( V_OSTYPE_AUTOSAR )
# define V_OSTYPE_AUTOSAR
#endif

#if (CPU_TYPE == CPU_TYPE_32)
# if !defined( C_CPUTYPE_32BIT )
#  define C_CPUTYPE_32BIT
# endif
#endif
#if (CPU_TYPE == CPU_TYPE_16)
# if !defined( C_CPUTYPE_16BIT )
#  define C_CPUTYPE_16BIT
# endif
#endif
#if (CPU_TYPE == CPU_TYPE_8)
# if !defined( C_CPUTYPE_8BIT )
#  define C_CPUTYPE_8BIT
# endif
#endif
#if (CPU_BIT_ORDER == LSB_FIRST)
# if !defined( C_CPUTYPE_BITORDER_LSB2MSB )
#  define C_CPUTYPE_BITORDER_LSB2MSB
# endif
#endif
#if (CPU_BIT_ORDER == MSB_FIRST)
# if !defined( C_CPUTYPE_BITORDER_MSB2LSB )
#  define C_CPUTYPE_BITORDER_MSB2LSB
# endif
#endif
#if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
# if !defined( C_CPUTYPE_LITTLEENDIAN )
#  define C_CPUTYPE_LITTLEENDIAN
# endif
#endif
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
# if !defined( C_CPUTYPE_BIGENDIAN )
#  define C_CPUTYPE_BIGENDIAN
# endif
#endif

#if !defined( V_DISABLE_USE_DUMMY_FUNCTIONS )
# define V_DISABLE_USE_DUMMY_FUNCTIONS
#endif
#if !defined( V_ENABLE_USE_DUMMY_STATEMENT )
# define V_ENABLE_USE_DUMMY_STATEMENT
#endif

#if !defined( V_CPU_TC3XX )
# define V_CPU_TC3XX
#endif

#if !defined( C_PROCESSOR_TC3XX_12CH )
# define C_PROCESSOR_TC3XX_12CH
#endif
#if !defined( V_PROCESSOR_TC3XX_12CH )
# define V_PROCESSOR_TC3XX_12CH
#endif

#if !defined( C_COMP_TASKING_TC3XX_MCAN )
#define C_COMP_TASKING_TC3XX_MCAN
#endif
#if !defined( V_COMP_TASKING )
# define V_COMP_TASKING
#endif
#if !defined( V_COMP_TASKING_TC3XX )
# define V_COMP_TASKING_TC3XX
#endif

#if !defined( V_SUPPRESS_EXTENDED_VERSION_CHECK )
# define V_SUPPRESS_EXTENDED_VERSION_CHECK
#endif

/* -----------------------------------------------------------------------------
    Version defines
 ----------------------------------------------------------------------------- */

/* CAN024, CAN023 */
#define CAN_ASR_VERSION              0x0400u
#define CAN_GEN_BASE_CFG5_VERSION    0x0103u
#define CAN_GEN_BASESASR_VERSION     0x0407u
#define CAN_GEN_Mpc5700McanAsr_VERSION              0x0100u
#define CAN_MICROSAR_VERSION         CAN_MSR403

/* -----------------------------------------------------------------------------
    Hardcoded defines
 ----------------------------------------------------------------------------- */

#define CAN_INSTANCE_ID           0

#define CAN_RX_BASICCAN_TYPE                 0u
#define CAN_RX_FULLCAN_TYPE                  1u
#define CAN_TX_BASICCAN_TYPE                 2u
#define CAN_TX_FULLCAN_TYPE                  3u
#define CAN_UNUSED_CAN_TYPE                  4u
#define CAN_TX_BASICCAN_MUX_TYPE             5u
#define CAN_TX_BASICCAN_FIFO_TYPE            6u

#define CAN_INTERRUPT                        0u
#define CAN_POLLING                          1u

#define kCanChannelNotUsed                     CAN_NO_CANIFCHANNELID 

#define CAN_NONE                             0u
/* RAM check (also  none) */
#define CAN_NOTIFY_ISSUE                     1u
#define CAN_NOTIFY_MAILBOX                   2u
#define CAN_EXTENDED                         3u
/* Interrupt lock (also  none) */
#define CAN_DRIVER                           1u
#define CAN_APPL                             2u
#define CAN_BOTH                             3u
/* Overrun Notification (als none,appl) */
#define CAN_DET                              1u
/* CAN FD Support */
#define CAN_BRS                              1u
#define CAN_FULL                             2u
/* CAN FD Configuration */
#define CAN_FD_RXONLY                        2u /* FD Baudrate exist (RX) */
#define CAN_FD_RXTX                          1u /* FD Baudrate also used for TX */
/* Generic Confirmation */
#define CAN_API1                             1u
#define CAN_API2                             2u

#define CAN_OS_TICK2MS(tick)     OS_TICKS2MS_SystemTimer0((tick))     /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define CAN_OS_COUNTER_ID        SystemTimer0

/* -----------------------------------------------------------------------------
    Defines / Switches
 ----------------------------------------------------------------------------- */

/* Version and Issue detection */
#define CAN_VERSION_INFO_API                 STD_OFF   /* CAN106_Conf */
#define CAN_DEV_ERROR_DETECT                 STD_OFF   /* CAN064_Conf */
#define CAN_DEV_ERROR_REPORT                 STD_OFF
#define CAN_SAFE_BSW                         STD_OFF

/* Interrupt / Polling */
#define CAN_TX_PROCESSING                    CAN_INTERRUPT   /* CAN318_Conf */
#define CAN_RX_PROCESSING                    CAN_INTERRUPT   /* CAN317_Conf */
#define CAN_BUSOFF_PROCESSING                CAN_INTERRUPT   /* CAN314_Conf */
#define CAN_WAKEUP_PROCESSING                CAN_INTERRUPT   /* CAN319_Conf */
#define CAN_INDIVIDUAL_PROCESSING            STD_OFF
#define CAN_INTERRUPT_USED                   STD_ON
#define CAN_NESTED_INTERRUPTS                STD_OFF
#define C_ENABLE_OSEK_OS_INTCAT2
#define C_DISABLE_ISRVOID
#define CAN_INTLOCK                          CAN_DRIVER

/* Tx Handling */
#define CAN_MULTIPLEXED_TX_MAX               1u
#define CAN_CANCEL_SUPPORT_API               STD_OFF
#define CAN_TRANSMIT_BUFFER                  STD_ON
#define CAN_MULTIPLEXED_TRANSMISSION         STD_OFF   /* CAN095_Conf */
#define CAN_TX_HW_FIFO                       STD_OFF
#define CAN_HW_TRANSMIT_CANCELLATION         STD_OFF   /* CAN069_Conf */
#define CAN_IDENTICAL_ID_CANCELLATION        STD_OFF   /* CAN378_Conf */
#define CAN_MULTIPLE_BASICCAN_TX             STD_OFF

/* Rx Handling */
#define CAN_MULTIPLE_BASICCAN                STD_OFF
#define CAN_RX_QUEUE                         STD_OFF
#define CAN_OVERRUN_NOTIFICATION             CAN_NONE

/* Sleep Wakeup */
#define CAN_SLEEP_SUPPORT                    STD_OFF
#define CAN_WAKEUP_SUPPORT                   STD_OFF   /* CAN330_Conf */

/* Hardware loop check */
#define CAN_HARDWARE_CANCELLATION            STD_ON
#define CAN_TIMEOUT_DURATION                 10uL   /* CAN113_Conf */
#define CAN_LOOP_MAX                         8u

/* Appl calls */
#define CAN_HW_LOOP_SUPPORT_API              STD_OFF
#define CAN_GENERIC_PRECOPY                  STD_OFF
#define CAN_GENERIC_CONFIRMATION             STD_OFF
#define CAN_GENERIC_PRETRANSMIT              STD_OFF
#define CAN_USE_OS_INTERRUPT_CONTROL         STD_ON

/* Optimization */
#define CAN_RX_FULLCAN_OBJECTS               STD_OFF
#define CAN_TX_FULLCAN_OBJECTS               STD_OFF
#define CAN_RX_BASICCAN_OBJECTS              STD_ON
#define CAN_EXTENDED_ID                      STD_OFF
#define CAN_MIXED_ID                         STD_OFF
#define CAN_ONE_CONTROLLER_OPTIMIZATION      STD_ON
#define CAN_CHANGE_BAUDRATE_API              STD_OFF   /* CAN460_Conf */
#define CAN_FD_HW_BUFFER_OPTIMIZATION        STD_ON

/* CAN FD */
#define CAN_SET_BAUDRATE_API                 STD_OFF   /* CAN482_Conf */
#define CAN_FD_SUPPORT                       CAN_NONE

/* Other */
#define CAN_COMMON_CAN                       STD_OFF
#define CAN_RAM_CHECK                        CAN_NONE
#define CAN_REINIT_START                     STD_OFF
#define CAN_GET_STATUS                       STD_OFF
#define CAN_RUNTIME_MEASUREMENT_SUPPORT      STD_OFF
#define CAN_PROTECTED_MODE                   STD_OFF
#define CAN_MIRROR_MODE                      STD_OFF
#define CAN_SILENT_MODE                      STD_OFF
#define CAN_CHECK_WAKEUP_CAN_RET_TYPE        STD_OFF
/* -----------------------------------------------------------------------------
    Channel And Mailbox
 ----------------------------------------------------------------------------- */
#ifndef C_DRV_INTERNAL
# ifndef kCanNumberOfChannels
#  define kCanNumberOfChannels               1u
# endif
# ifndef kCanNumberOfHwChannels
#  define kCanNumberOfHwChannels             1u
# endif
#endif
#ifndef kCanNumberOfUsedChannels /* ATK only */
# define kCanNumberOfUsedChannels            1u
#endif

#define kCanPhysToLogChannelIndex_0 

#define kCanNumberOfPhysChannels             1u

/* -----------------------------------------------------------------------------
    Symbolic Name Values for Controller, HardwareObject and Baudrates
 ----------------------------------------------------------------------------- */
/* These definitions can change at Link-time and Post-build configuration time. Use them wisely. */



/**
 * \defgroup CanHandleIdsactivated Handle IDs of handle space activated.
 * \brief controllers by CanControllerActivation
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define CanConf_CanController_CT_CAN00_617059cf                       0u
/**\} */
#define CanConf_CN_CAN00_a2de9a4f_Tx 0u
#define CanConf_CN_CAN00_e847a2b9_Rx 1u

#define CanConf_ControllerBaudrateConfig_CT_CAN00_617059cf_CanControllerBaudrateConfig 0u

#define CanConf_MemorySection_Memory_CT_CAN00_617059cf 0u



/* -----------------------------------------------------------------------------
    Types
 ----------------------------------------------------------------------------- */
/* HW specific BEGIN */

/* HW specific Pre Can Config H file */

/* -----------------------------------------------------------------------------
    &&&~ Defines / Switches (Hw specific ) 
 ----------------------------------------------------------------------------- */

#define CAN_REGEXT_MCMCAN                      STD_ON  /* #define C_ENABLE_MC_MCAN */
#define CAN_TRICORE_ERRATUM_AI_H001            STD_ON

#define CAN_REGEXT_MCANSS                  STD_OFF

#define CAN_REGEXT_SICANFD                  STD_OFF

#define CAN_REGEXT_TTCANFD                  STD_OFF

#define CAN_SHM_DATAQOS                  STD_OFF

#define CAN_REGEXT_AS1CANFD                  STD_OFF

#define C_ENABLE_GENERATE_FULLCAN_MASK           /* FullCAN filter generation supported */

#define CAN_ISR_ALL_CHAN          STD_OFF
#define CAN_ISR_LEVEL_TRIGGERED   STD_OFF

typedef VAR(uint32, CAN_VAR_NOINIT) tCanLLCanIntOld;


#if (defined(CAN_LCFG_SOURCE) || defined(C_DRV_INTERNAL)) && (CAN_USE_OS_INTERRUPT_CONTROL == STD_ON)
typedef ISRType Can_OsIsrType;
#else
typedef uint8 Can_OsIsrType;
#endif

#define kCanISRPrio_0                     0x00000025uL

/* !HW specific Pre Can Config H file */ 
/* HW specific END */ 

typedef VAR(uint8, TYPEDEF) CanChannelHandle;

#if defined (CAN_LCFG_SOURCE) || defined (C_DRV_INTERNAL)
typedef TickType Can_ExternalTickType;
#else
typedef uint32 Can_ExternalTickType;
#endif

typedef VAR(Can_ExternalTickType, TYPEDEF) Can_LoopTimeout_dim_type[CAN_LOOP_MAX+1u];




/* -----------------------------------------------------------------------------
    CONST Declarations
 ----------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
    VAR Declarations
 ----------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
    Hw specific
 ----------------------------------------------------------------------------- */
/* HW specific BEGIN */
/* HW specific global H file */

/* !HW specific global H file */
/* HW specific END */


/**********************************************************************************************************************
  ComStackLib
**********************************************************************************************************************/
/* Can_GlobalConfig: CAN354_Conf */
/* Can_ConfigType: CAN413 */

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanPCDataSwitches  Can Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CAN_ACTIVESENDOBJECT                                          STD_ON
#define CAN_PDUOFACTIVESENDOBJECT                                     STD_ON
#define CAN_STATEOFACTIVESENDOBJECT                                   STD_ON
#define CAN_BTP                                                       STD_ON
#define CAN_BASEDLL_GENERATORVERSION                                  STD_ON
#define CAN_BUFFERCONFIG                                              STD_ON
#define CAN_RXBCOFBUFFERCONFIG                                        STD_ON
#define CAN_RXF0COFBUFFERCONFIG                                       STD_ON
#define CAN_RXF1COFBUFFERCONFIG                                       STD_ON
#define CAN_TXBCOFBUFFERCONFIG                                        STD_ON
#define CAN_TXEFCOFBUFFERCONFIG                                       STD_ON
#define CAN_CAN_FD_NISO                                               STD_ON
#define CAN_CAN_NUMBER_OF_SRN                                         STD_ON
#define CAN_C_ENABLE_MPC5700_MCAN_CREL_SSTEP                          STD_ON
#define CAN_C_ENABLE_MPC5700_MCAN_CREL_STEP                           STD_ON
#define CAN_C_ENABLE_MPC5700_MCAN_MAJOR_CREL                          STD_ON
#define CAN_CANIFCHANNELID                                            STD_ON
#define CAN_CONTROLLERCONFIG                                          STD_ON
#define CAN_BASISADROFCONTROLLERCONFIG                                STD_ON
#define CAN_CANCONTROLLERDEFAULTBAUDRATEIDXOFCONTROLLERCONFIG         STD_ON
#define CAN_CANCONTROLLERDEFAULTBAUDRATEOFCONTROLLERCONFIG            STD_ON
#define CAN_ISTTCANOFCONTROLLERCONFIG                                 STD_ON
#define CAN_MAILBOXRXBASICENDIDXOFCONTROLLERCONFIG                    STD_ON
#define CAN_MAILBOXRXBASICLENGTHOFCONTROLLERCONFIG                    STD_ON
#define CAN_MAILBOXRXBASICSTARTIDXOFCONTROLLERCONFIG                  STD_ON
#define CAN_MAILBOXRXBASICUSEDOFCONTROLLERCONFIG                      STD_ON
#define CAN_MAILBOXRXFULLENDIDXOFCONTROLLERCONFIG                     STD_OFF  /**< Deactivateable: 'Can_ControllerConfig.MailboxRxFullEndIdx' Reason: 'the optional indirection is deactivated because MailboxRxFullUsedOfControllerConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CAN_MAILBOXRXFULLLENGTHOFCONTROLLERCONFIG                     STD_OFF  /**< Deactivateable: 'Can_ControllerConfig.MailboxRxFullLength' Reason: 'the optional indirection is deactivated because MailboxRxFullUsedOfControllerConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CAN_MAILBOXRXFULLSTARTIDXOFCONTROLLERCONFIG                   STD_OFF  /**< Deactivateable: 'Can_ControllerConfig.MailboxRxFullStartIdx' Reason: 'the optional indirection is deactivated because MailboxRxFullUsedOfControllerConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CAN_MAILBOXRXFULLUSEDOFCONTROLLERCONFIG                       STD_OFF  /**< Deactivateable: 'Can_ControllerConfig.MailboxRxFullUsed' Reason: 'the optional indirection is deactivated because MailboxRxFullUsedOfControllerConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CAN_MAILBOXTXBASICENDIDXOFCONTROLLERCONFIG                    STD_ON
#define CAN_MAILBOXTXBASICLENGTHOFCONTROLLERCONFIG                    STD_ON
#define CAN_MAILBOXTXBASICSTARTIDXOFCONTROLLERCONFIG                  STD_ON
#define CAN_MAILBOXTXBASICUSEDOFCONTROLLERCONFIG                      STD_ON
#define CAN_MAILBOXTXFULLENDIDXOFCONTROLLERCONFIG                     STD_OFF  /**< Deactivateable: 'Can_ControllerConfig.MailboxTxFullEndIdx' Reason: 'the optional indirection is deactivated because MailboxTxFullUsedOfControllerConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CAN_MAILBOXTXFULLLENGTHOFCONTROLLERCONFIG                     STD_OFF  /**< Deactivateable: 'Can_ControllerConfig.MailboxTxFullLength' Reason: 'the optional indirection is deactivated because MailboxTxFullUsedOfControllerConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CAN_MAILBOXTXFULLSTARTIDXOFCONTROLLERCONFIG                   STD_OFF  /**< Deactivateable: 'Can_ControllerConfig.MailboxTxFullStartIdx' Reason: 'the optional indirection is deactivated because MailboxTxFullUsedOfControllerConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CAN_MAILBOXTXFULLUSEDOFCONTROLLERCONFIG                       STD_OFF  /**< Deactivateable: 'Can_ControllerConfig.MailboxTxFullUsed' Reason: 'the optional indirection is deactivated because MailboxTxFullUsedOfControllerConfig is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CAN_MAILBOXUNUSEDENDIDXOFCONTROLLERCONFIG                     STD_ON
#define CAN_MAILBOXUNUSEDLENGTHOFCONTROLLERCONFIG                     STD_ON
#define CAN_MAILBOXUNUSEDSTARTIDXOFCONTROLLERCONFIG                   STD_ON
#define CAN_MAILBOXUNUSEDUSEDOFCONTROLLERCONFIG                       STD_ON
#define CAN_RXBASICHWSTARTOFCONTROLLERCONFIG                          STD_ON
#define CAN_RXBASICHWSTOPOFCONTROLLERCONFIG                           STD_ON
#define CAN_RXFULLHWSTARTOFCONTROLLERCONFIG                           STD_ON
#define CAN_RXFULLHWSTOPOFCONTROLLERCONFIG                            STD_ON
#define CAN_RXSELECTIONOFCONTROLLERCONFIG                             STD_ON
#define CAN_TXBASICHWSTARTOFCONTROLLERCONFIG                          STD_ON
#define CAN_TXBASICHWSTOPOFCONTROLLERCONFIG                           STD_ON
#define CAN_TXFULLHWSTARTOFCONTROLLERCONFIG                           STD_ON
#define CAN_TXFULLHWSTOPOFCONTROLLERCONFIG                            STD_ON
#define CAN_UNUSEDHWSTARTOFCONTROLLERCONFIG                           STD_ON
#define CAN_UNUSEDHWSTOPOFCONTROLLERCONFIG                            STD_ON
#define CAN_CONTROLLERDATA                                            STD_ON
#define CAN_BUSOFFNOTIFICATIONOFCONTROLLERDATA                        STD_ON
#define CAN_BUSOFFTRANSITIONREQUESTOFCONTROLLERDATA                   STD_ON
#define CAN_CANINTERRUPTCOUNTEROFCONTROLLERDATA                       STD_ON
#define CAN_CANINTERRUPTOLDSTATUSOFCONTROLLERDATA                     STD_ON
#define CAN_INTENABLEOFCONTROLLERDATA                                 STD_ON
#define CAN_ISBUSOFFOFCONTROLLERDATA                                  STD_ON
#define CAN_LASTINITOBJECTOFCONTROLLERDATA                            STD_ON
#define CAN_LASTSTATEOFCONTROLLERDATA                                 STD_ON
#define CAN_LOGSTATUSOFCONTROLLERDATA                                 STD_ON
#define CAN_LOOPTIMEOUTOFCONTROLLERDATA                               STD_ON
#define CAN_MODETRANSITIONREQUESTOFCONTROLLERDATA                     STD_ON
#define CAN_PREVMODEOFCONTROLLERDATA                                  STD_ON
#define CAN_RAMCHECKTRANSITIONREQUESTOFCONTROLLERDATA                 STD_ON
#define CAN_TXBCROFCONTROLLERDATA                                     STD_ON
#define CAN_TXBRPOFCONTROLLERDATA                                     STD_ON
#define CAN_FBTP                                                      STD_ON
#define CAN_FINALMAGICNUMBER                                          STD_OFF  /**< Deactivateable: 'Can_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CAN_GFC                                                       STD_ON
#define CAN_INT_PRIORITY                                              STD_ON
#define CAN_INT_ROUTINGGROUP                                          STD_ON
#define CAN_INITDATAHASHCODE                                          STD_OFF  /**< Deactivateable: 'Can_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CAN_INITOBJECTBAUDRATE                                        STD_ON
#define CAN_INITOBJECTSTARTINDEX                                      STD_ON
#define CAN_ISROSID                                                   STD_ON
#define CAN_MAILBOX                                                   STD_ON
#define CAN_ACTIVESENDOBJECTOFMAILBOX                                 STD_ON
#define CAN_CONTROLLERCONFIGIDXOFMAILBOX                              STD_ON
#define CAN_HWHANDLEOFMAILBOX                                         STD_ON
#define CAN_IDVALUEOFMAILBOX                                          STD_ON
#define CAN_MAILBOXSIZEOFMAILBOX                                      STD_ON
#define CAN_MAILBOXTYPEOFMAILBOX                                      STD_ON
#define CAN_MAXDATALENOFMAILBOX                                       STD_ON
#define CAN_MEMORYSECTIONSINDEXOFMAILBOX                              STD_ON
#define CAN_MEMORYSECTIONINFO                                         STD_ON
#define CAN_MEMORYSECTIONSTARTOFMEMORYSECTIONINFO                     STD_ON
#define CAN_MEMORYSECTIONOBJECTS                                      STD_ON
#define CAN_HWHANDLEOFMEMORYSECTIONOBJECTS                            STD_ON
#define CAN_MAILBOXELEMENTOFMEMORYSECTIONOBJECTS                      STD_ON
#define CAN_MAILBOXHANDLEOFMEMORYSECTIONOBJECTS                       STD_ON
#define CAN_PLATFORMDLL_GENERATORVERSION                              STD_ON
#define CAN_SIDFC                                                     STD_ON
#define CAN_FLSSAOFSIDFC                                              STD_ON
#define CAN_LSSOFSIDFC                                                STD_ON
#define CAN_SIDFEENDIDXOFSIDFC                                        STD_ON
#define CAN_SIDFESTARTIDXOFSIDFC                                      STD_ON
#define CAN_SIDFEUSEDOFSIDFC                                          STD_ON
#define CAN_SIDFE                                                     STD_ON
#define CAN_SRN_ADDRESS                                               STD_ON
#define CAN_SHMADR                                                    STD_ON
#define CAN_RXBAOFSHMADR                                              STD_ON
#define CAN_RXF0AOFSHMADR                                             STD_ON
#define CAN_RXF1AOFSHMADR                                             STD_ON
#define CAN_SIDFAOFSHMADR                                             STD_ON
#define CAN_STARTADROFSHMADR                                          STD_ON
#define CAN_STOPADROFSHMADR                                           STD_ON
#define CAN_TXBAOFSHMADR                                              STD_ON
#define CAN_TXEFAOFSHMADR                                             STD_ON
#define CAN_XIDFAOFSHMADR                                             STD_ON
#define CAN_SHMELEMENTSIZE                                            STD_OFF  /**< Deactivateable: 'Can_ShmElementSize' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CAN_F0DSOFSHMELEMENTSIZE                                      STD_OFF  /**< Deactivateable: 'Can_ShmElementSize.F0DS' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CAN_F1DSOFSHMELEMENTSIZE                                      STD_OFF  /**< Deactivateable: 'Can_ShmElementSize.F1DS' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CAN_RBDSOFSHMELEMENTSIZE                                      STD_OFF  /**< Deactivateable: 'Can_ShmElementSize.RBDS' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CAN_TBDSOFSHMELEMENTSIZE                                      STD_OFF  /**< Deactivateable: 'Can_ShmElementSize.TBDS' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CAN_TEFBDSOFSHMELEMENTSIZE                                    STD_OFF  /**< Deactivateable: 'Can_ShmElementSize.TEFBDS' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CAN_SIZEOFACTIVESENDOBJECT                                    STD_ON
#define CAN_SIZEOFBTP                                                 STD_ON
#define CAN_SIZEOFBUFFERCONFIG                                        STD_ON
#define CAN_SIZEOFCANIFCHANNELID                                      STD_ON
#define CAN_SIZEOFCONTROLLERCONFIG                                    STD_ON
#define CAN_SIZEOFCONTROLLERDATA                                      STD_ON
#define CAN_SIZEOFFBTP                                                STD_ON
#define CAN_SIZEOFGFC                                                 STD_ON
#define CAN_SIZEOFINT_PRIORITY                                        STD_ON
#define CAN_SIZEOFINT_ROUTINGGROUP                                    STD_ON
#define CAN_SIZEOFINITOBJECTBAUDRATE                                  STD_ON
#define CAN_SIZEOFINITOBJECTSTARTINDEX                                STD_ON
#define CAN_SIZEOFISROSID                                             STD_ON
#define CAN_SIZEOFMAILBOX                                             STD_ON
#define CAN_SIZEOFMEMORYSECTIONINFO                                   STD_ON
#define CAN_SIZEOFMEMORYSECTIONOBJECTS                                STD_ON
#define CAN_SIZEOFSIDFC                                               STD_ON
#define CAN_SIZEOFSIDFE                                               STD_ON
#define CAN_SIZEOFSRN_ADDRESS                                         STD_ON
#define CAN_SIZEOFSHMADR                                              STD_ON
#define CAN_SIZEOFTDCR                                                STD_ON
#define CAN_SIZEOFXIDAM                                               STD_ON
#define CAN_SIZEOFXIDFC                                               STD_ON
#define CAN_SIZEOFXIDFE                                               STD_ON
#define CAN_TDCR                                                      STD_ON
#define CAN_XIDAM                                                     STD_ON
#define CAN_XIDFC                                                     STD_ON
#define CAN_FLESAOFXIDFC                                              STD_ON
#define CAN_LSEOFXIDFC                                                STD_ON
#define CAN_XIDFEENDIDXOFXIDFC                                        STD_OFF  /**< Deactivateable: 'Can_XIDFC.XIDFEEndIdx' Reason: 'the optional indirection is deactivated because XIDFEUsedOfXIDFC is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CAN_XIDFESTARTIDXOFXIDFC                                      STD_OFF  /**< Deactivateable: 'Can_XIDFC.XIDFEStartIdx' Reason: 'the optional indirection is deactivated because XIDFEUsedOfXIDFC is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CAN_XIDFEUSEDOFXIDFC                                          STD_OFF  /**< Deactivateable: 'Can_XIDFC.XIDFEUsed' Reason: 'the optional indirection is deactivated because XIDFEUsedOfXIDFC is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CAN_XIDFE                                                     STD_ON
#define CAN_EIDFE_0OFXIDFE                                            STD_ON
#define CAN_EIDFE_1OFXIDFE                                            STD_ON
#define CAN_KCANUSEDCORE                                              STD_ON
#define CAN_PCCONFIG                                                  STD_ON
#define CAN_ACTIVESENDOBJECTOFPCCONFIG                                STD_ON
#define CAN_BTPOFPCCONFIG                                             STD_ON
#define CAN_BASEDLL_GENERATORVERSIONOFPCCONFIG                        STD_ON
#define CAN_BUFFERCONFIGOFPCCONFIG                                    STD_ON
#define CAN_CAN_FD_NISOOFPCCONFIG                                     STD_ON
#define CAN_CAN_NUMBER_OF_SRNOFPCCONFIG                               STD_ON
#define CAN_C_ENABLE_MPC5700_MCAN_CREL_SSTEPOFPCCONFIG                STD_ON
#define CAN_C_ENABLE_MPC5700_MCAN_CREL_STEPOFPCCONFIG                 STD_ON
#define CAN_C_ENABLE_MPC5700_MCAN_MAJOR_CRELOFPCCONFIG                STD_ON
#define CAN_CANIFCHANNELIDOFPCCONFIG                                  STD_ON
#define CAN_CONTROLLERCONFIGOFPCCONFIG                                STD_ON
#define CAN_CONTROLLERDATAOFPCCONFIG                                  STD_ON
#define CAN_FBTPOFPCCONFIG                                            STD_ON
#define CAN_FINALMAGICNUMBEROFPCCONFIG                                STD_OFF  /**< Deactivateable: 'Can_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CAN_GFCOFPCCONFIG                                             STD_ON
#define CAN_INT_PRIORITYOFPCCONFIG                                    STD_ON
#define CAN_INT_ROUTINGGROUPOFPCCONFIG                                STD_ON
#define CAN_INITDATAHASHCODEOFPCCONFIG                                STD_OFF  /**< Deactivateable: 'Can_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CAN_INITOBJECTBAUDRATEOFPCCONFIG                              STD_ON
#define CAN_INITOBJECTSTARTINDEXOFPCCONFIG                            STD_ON
#define CAN_ISROSIDOFPCCONFIG                                         STD_ON
#define CAN_MAILBOXOFPCCONFIG                                         STD_ON
#define CAN_MEMORYSECTIONINFOOFPCCONFIG                               STD_ON
#define CAN_MEMORYSECTIONOBJECTSOFPCCONFIG                            STD_ON
#define CAN_PLATFORMDLL_GENERATORVERSIONOFPCCONFIG                    STD_ON
#define CAN_SIDFCOFPCCONFIG                                           STD_ON
#define CAN_SIDFEOFPCCONFIG                                           STD_ON
#define CAN_SRN_ADDRESSOFPCCONFIG                                     STD_ON
#define CAN_SHMADROFPCCONFIG                                          STD_ON
#define CAN_SIZEOFACTIVESENDOBJECTOFPCCONFIG                          STD_ON
#define CAN_SIZEOFBTPOFPCCONFIG                                       STD_ON
#define CAN_SIZEOFBUFFERCONFIGOFPCCONFIG                              STD_ON
#define CAN_SIZEOFCANIFCHANNELIDOFPCCONFIG                            STD_ON
#define CAN_SIZEOFCONTROLLERCONFIGOFPCCONFIG                          STD_ON
#define CAN_SIZEOFCONTROLLERDATAOFPCCONFIG                            STD_ON
#define CAN_SIZEOFFBTPOFPCCONFIG                                      STD_ON
#define CAN_SIZEOFGFCOFPCCONFIG                                       STD_ON
#define CAN_SIZEOFINT_PRIORITYOFPCCONFIG                              STD_ON
#define CAN_SIZEOFINT_ROUTINGGROUPOFPCCONFIG                          STD_ON
#define CAN_SIZEOFINITOBJECTBAUDRATEOFPCCONFIG                        STD_ON
#define CAN_SIZEOFINITOBJECTSTARTINDEXOFPCCONFIG                      STD_ON
#define CAN_SIZEOFISROSIDOFPCCONFIG                                   STD_ON
#define CAN_SIZEOFMAILBOXOFPCCONFIG                                   STD_ON
#define CAN_SIZEOFMEMORYSECTIONINFOOFPCCONFIG                         STD_ON
#define CAN_SIZEOFMEMORYSECTIONOBJECTSOFPCCONFIG                      STD_ON
#define CAN_SIZEOFSIDFCOFPCCONFIG                                     STD_ON
#define CAN_SIZEOFSIDFEOFPCCONFIG                                     STD_ON
#define CAN_SIZEOFSRN_ADDRESSOFPCCONFIG                               STD_ON
#define CAN_SIZEOFSHMADROFPCCONFIG                                    STD_ON
#define CAN_SIZEOFTDCROFPCCONFIG                                      STD_ON
#define CAN_SIZEOFXIDAMOFPCCONFIG                                     STD_ON
#define CAN_SIZEOFXIDFCOFPCCONFIG                                     STD_ON
#define CAN_SIZEOFXIDFEOFPCCONFIG                                     STD_ON
#define CAN_TDCROFPCCONFIG                                            STD_ON
#define CAN_XIDAMOFPCCONFIG                                           STD_ON
#define CAN_XIDFCOFPCCONFIG                                           STD_ON
#define CAN_XIDFEOFPCCONFIG                                           STD_ON
#define CAN_KCANUSEDCOREOFPCCONFIG                                    STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CanPCMinNumericValueDefines  Can Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define CAN_MIN_PDUOFACTIVESENDOBJECT                                 0u
#define CAN_MIN_STATEOFACTIVESENDOBJECT                               0u
#define CAN_MIN_BUSOFFNOTIFICATIONOFCONTROLLERDATA                    0u
#define CAN_MIN_BUSOFFTRANSITIONREQUESTOFCONTROLLERDATA               0u
#define CAN_MIN_CANINTERRUPTCOUNTEROFCONTROLLERDATA                   0u
#define CAN_MIN_INTENABLEOFCONTROLLERDATA                             0u
#define CAN_MIN_LASTINITOBJECTOFCONTROLLERDATA                        0u
#define CAN_MIN_LASTSTATEOFCONTROLLERDATA                             0u
#define CAN_MIN_LOGSTATUSOFCONTROLLERDATA                             0u
#define CAN_MIN_MODETRANSITIONREQUESTOFCONTROLLERDATA                 0u
#define CAN_MIN_PREVMODEOFCONTROLLERDATA                              0u
#define CAN_MIN_RAMCHECKTRANSITIONREQUESTOFCONTROLLERDATA             0u
#define CAN_MIN_TXBCROFCONTROLLERDATA                                 0u
#define CAN_MIN_TXBRPOFCONTROLLERDATA                                 0u
/** 
  \}
*/ 

/** 
  \defgroup  CanPCMaxNumericValueDefines  Can Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define CAN_MAX_PDUOFACTIVESENDOBJECT                                 255u
#define CAN_MAX_STATEOFACTIVESENDOBJECT                               65535u
#define CAN_MAX_BUSOFFNOTIFICATIONOFCONTROLLERDATA                    255u
#define CAN_MAX_BUSOFFTRANSITIONREQUESTOFCONTROLLERDATA               255u
#define CAN_MAX_CANINTERRUPTCOUNTEROFCONTROLLERDATA                   255u
#define CAN_MAX_INTENABLEOFCONTROLLERDATA                             4294967295u
#define CAN_MAX_LASTINITOBJECTOFCONTROLLERDATA                        255u
#define CAN_MAX_LASTSTATEOFCONTROLLERDATA                             255u
#define CAN_MAX_LOGSTATUSOFCONTROLLERDATA                             255u
#define CAN_MAX_MODETRANSITIONREQUESTOFCONTROLLERDATA                 255u
#define CAN_MAX_PREVMODEOFCONTROLLERDATA                              255u
#define CAN_MAX_RAMCHECKTRANSITIONREQUESTOFCONTROLLERDATA             255u
#define CAN_MAX_TXBCROFCONTROLLERDATA                                 4294967295u
#define CAN_MAX_TXBRPOFCONTROLLERDATA                                 4294967295u
/** 
  \}
*/ 

/** 
  \defgroup  CanPCNoReferenceDefines  Can No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define CAN_NO_CANIFCHANNELID                                         255u
#define CAN_NO_CANCONTROLLERDEFAULTBAUDRATEIDXOFCONTROLLERCONFIG      255u
#define CAN_NO_CANCONTROLLERDEFAULTBAUDRATEOFCONTROLLERCONFIG         65535u
#define CAN_NO_MAILBOXRXBASICENDIDXOFCONTROLLERCONFIG                 255u
#define CAN_NO_MAILBOXRXBASICSTARTIDXOFCONTROLLERCONFIG               255u
#define CAN_NO_MAILBOXTXBASICENDIDXOFCONTROLLERCONFIG                 255u
#define CAN_NO_MAILBOXTXBASICSTARTIDXOFCONTROLLERCONFIG               255u
#define CAN_NO_MAILBOXUNUSEDENDIDXOFCONTROLLERCONFIG                  255u
#define CAN_NO_MAILBOXUNUSEDSTARTIDXOFCONTROLLERCONFIG                255u
#define CAN_NO_RXBASICHWSTARTOFCONTROLLERCONFIG                       255u
#define CAN_NO_RXBASICHWSTOPOFCONTROLLERCONFIG                        255u
#define CAN_NO_RXFULLHWSTARTOFCONTROLLERCONFIG                        255u
#define CAN_NO_RXFULLHWSTOPOFCONTROLLERCONFIG                         255u
#define CAN_NO_TXBASICHWSTARTOFCONTROLLERCONFIG                       255u
#define CAN_NO_TXBASICHWSTOPOFCONTROLLERCONFIG                        255u
#define CAN_NO_TXFULLHWSTARTOFCONTROLLERCONFIG                        255u
#define CAN_NO_TXFULLHWSTOPOFCONTROLLERCONFIG                         255u
#define CAN_NO_UNUSEDHWSTARTOFCONTROLLERCONFIG                        255u
#define CAN_NO_UNUSEDHWSTOPOFCONTROLLERCONFIG                         255u
#define CAN_NO_SIDFEENDIDXOFSIDFC                                     255u
#define CAN_NO_SIDFESTARTIDXOFSIDFC                                   255u
/** 
  \}
*/ 

/** 
  \defgroup  CanPCEnumExistsDefines  Can Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define CAN_EXISTS_RX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX              STD_ON
#define CAN_EXISTS_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX               STD_OFF
#define CAN_EXISTS_TX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX              STD_ON
#define CAN_EXISTS_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX               STD_OFF
#define CAN_EXISTS_UNUSED_CAN_TYPE_MAILBOXTYPEOFMAILBOX               STD_ON
#define CAN_EXISTS_TX_BASICCAN_MUX_TYPE_MAILBOXTYPEOFMAILBOX          STD_OFF
#define CAN_EXISTS_TX_BASICCAN_FIFO_TYPE_MAILBOXTYPEOFMAILBOX         STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  CanPCEnumDefines  Can Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define CAN_RX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX                     0x00u
#define CAN_TX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX                     0x02u
#define CAN_UNUSED_CAN_TYPE_MAILBOXTYPEOFMAILBOX                      0x04u
/** 
  \}
*/ 

/** 
  \defgroup  CanPCIsReducedToDefineDefines  Can Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CAN_ISDEF_BTP                                                 STD_OFF
#define CAN_ISDEF_RXBCOFBUFFERCONFIG                                  STD_OFF
#define CAN_ISDEF_RXF0COFBUFFERCONFIG                                 STD_OFF
#define CAN_ISDEF_RXF1COFBUFFERCONFIG                                 STD_OFF
#define CAN_ISDEF_TXBCOFBUFFERCONFIG                                  STD_OFF
#define CAN_ISDEF_TXEFCOFBUFFERCONFIG                                 STD_OFF
#define CAN_ISDEF_CANIFCHANNELID                                      STD_OFF
#define CAN_ISDEF_BASISADROFCONTROLLERCONFIG                          STD_OFF
#define CAN_ISDEF_CANCONTROLLERDEFAULTBAUDRATEIDXOFCONTROLLERCONFIG   STD_OFF
#define CAN_ISDEF_CANCONTROLLERDEFAULTBAUDRATEOFCONTROLLERCONFIG      STD_OFF
#define CAN_ISDEF_ISTTCANOFCONTROLLERCONFIG                           STD_OFF
#define CAN_ISDEF_MAILBOXRXBASICENDIDXOFCONTROLLERCONFIG              STD_OFF
#define CAN_ISDEF_MAILBOXRXBASICLENGTHOFCONTROLLERCONFIG              STD_OFF
#define CAN_ISDEF_MAILBOXRXBASICSTARTIDXOFCONTROLLERCONFIG            STD_OFF
#define CAN_ISDEF_MAILBOXRXBASICUSEDOFCONTROLLERCONFIG                STD_OFF
#define CAN_ISDEF_MAILBOXTXBASICENDIDXOFCONTROLLERCONFIG              STD_OFF
#define CAN_ISDEF_MAILBOXTXBASICLENGTHOFCONTROLLERCONFIG              STD_OFF
#define CAN_ISDEF_MAILBOXTXBASICSTARTIDXOFCONTROLLERCONFIG            STD_OFF
#define CAN_ISDEF_MAILBOXTXBASICUSEDOFCONTROLLERCONFIG                STD_OFF
#define CAN_ISDEF_MAILBOXUNUSEDENDIDXOFCONTROLLERCONFIG               STD_OFF
#define CAN_ISDEF_MAILBOXUNUSEDLENGTHOFCONTROLLERCONFIG               STD_OFF
#define CAN_ISDEF_MAILBOXUNUSEDSTARTIDXOFCONTROLLERCONFIG             STD_OFF
#define CAN_ISDEF_MAILBOXUNUSEDUSEDOFCONTROLLERCONFIG                 STD_OFF
#define CAN_ISDEF_RXBASICHWSTARTOFCONTROLLERCONFIG                    STD_OFF
#define CAN_ISDEF_RXBASICHWSTOPOFCONTROLLERCONFIG                     STD_OFF
#define CAN_ISDEF_RXFULLHWSTARTOFCONTROLLERCONFIG                     STD_OFF
#define CAN_ISDEF_RXFULLHWSTOPOFCONTROLLERCONFIG                      STD_OFF
#define CAN_ISDEF_RXSELECTIONOFCONTROLLERCONFIG                       STD_OFF
#define CAN_ISDEF_TXBASICHWSTARTOFCONTROLLERCONFIG                    STD_OFF
#define CAN_ISDEF_TXBASICHWSTOPOFCONTROLLERCONFIG                     STD_OFF
#define CAN_ISDEF_TXFULLHWSTARTOFCONTROLLERCONFIG                     STD_OFF
#define CAN_ISDEF_TXFULLHWSTOPOFCONTROLLERCONFIG                      STD_OFF
#define CAN_ISDEF_UNUSEDHWSTARTOFCONTROLLERCONFIG                     STD_OFF
#define CAN_ISDEF_UNUSEDHWSTOPOFCONTROLLERCONFIG                      STD_OFF
#define CAN_ISDEF_FBTP                                                STD_OFF
#define CAN_ISDEF_GFC                                                 STD_OFF
#define CAN_ISDEF_INT_PRIORITY                                        STD_OFF
#define CAN_ISDEF_INT_ROUTINGGROUP                                    STD_OFF
#define CAN_ISDEF_INITOBJECTBAUDRATE                                  STD_OFF
#define CAN_ISDEF_INITOBJECTSTARTINDEX                                STD_OFF
#define CAN_ISDEF_ISROSID                                             STD_OFF
#define CAN_ISDEF_ACTIVESENDOBJECTOFMAILBOX                           STD_OFF
#define CAN_ISDEF_CONTROLLERCONFIGIDXOFMAILBOX                        STD_OFF
#define CAN_ISDEF_HWHANDLEOFMAILBOX                                   STD_OFF
#define CAN_ISDEF_IDVALUEOFMAILBOX                                    STD_OFF
#define CAN_ISDEF_MAILBOXSIZEOFMAILBOX                                STD_OFF
#define CAN_ISDEF_MAILBOXTYPEOFMAILBOX                                STD_OFF
#define CAN_ISDEF_MAXDATALENOFMAILBOX                                 STD_OFF
#define CAN_ISDEF_MEMORYSECTIONSINDEXOFMAILBOX                        STD_OFF
#define CAN_ISDEF_MEMORYSECTIONSTARTOFMEMORYSECTIONINFO               STD_OFF
#define CAN_ISDEF_HWHANDLEOFMEMORYSECTIONOBJECTS                      STD_OFF
#define CAN_ISDEF_MAILBOXELEMENTOFMEMORYSECTIONOBJECTS                STD_OFF
#define CAN_ISDEF_MAILBOXHANDLEOFMEMORYSECTIONOBJECTS                 STD_OFF
#define CAN_ISDEF_FLSSAOFSIDFC                                        STD_OFF
#define CAN_ISDEF_LSSOFSIDFC                                          STD_OFF
#define CAN_ISDEF_SIDFEENDIDXOFSIDFC                                  STD_OFF
#define CAN_ISDEF_SIDFESTARTIDXOFSIDFC                                STD_OFF
#define CAN_ISDEF_SIDFEUSEDOFSIDFC                                    STD_OFF
#define CAN_ISDEF_SIDFE                                               STD_OFF
#define CAN_ISDEF_SRN_ADDRESS                                         STD_OFF
#define CAN_ISDEF_RXBAOFSHMADR                                        STD_OFF
#define CAN_ISDEF_RXF0AOFSHMADR                                       STD_OFF
#define CAN_ISDEF_RXF1AOFSHMADR                                       STD_OFF
#define CAN_ISDEF_SIDFAOFSHMADR                                       STD_OFF
#define CAN_ISDEF_STARTADROFSHMADR                                    STD_OFF
#define CAN_ISDEF_STOPADROFSHMADR                                     STD_OFF
#define CAN_ISDEF_TXBAOFSHMADR                                        STD_OFF
#define CAN_ISDEF_TXEFAOFSHMADR                                       STD_OFF
#define CAN_ISDEF_XIDFAOFSHMADR                                       STD_OFF
#define CAN_ISDEF_TDCR                                                STD_OFF
#define CAN_ISDEF_XIDAM                                               STD_OFF
#define CAN_ISDEF_FLESAOFXIDFC                                        STD_OFF
#define CAN_ISDEF_LSEOFXIDFC                                          STD_OFF
#define CAN_ISDEF_EIDFE_0OFXIDFE                                      STD_OFF
#define CAN_ISDEF_EIDFE_1OFXIDFE                                      STD_OFF
#define CAN_ISDEF_ACTIVESENDOBJECTOFPCCONFIG                          STD_ON
#define CAN_ISDEF_BTPOFPCCONFIG                                       STD_ON
#define CAN_ISDEF_BUFFERCONFIGOFPCCONFIG                              STD_ON
#define CAN_ISDEF_CANIFCHANNELIDOFPCCONFIG                            STD_ON
#define CAN_ISDEF_CONTROLLERCONFIGOFPCCONFIG                          STD_ON
#define CAN_ISDEF_CONTROLLERDATAOFPCCONFIG                            STD_ON
#define CAN_ISDEF_FBTPOFPCCONFIG                                      STD_ON
#define CAN_ISDEF_GFCOFPCCONFIG                                       STD_ON
#define CAN_ISDEF_INT_PRIORITYOFPCCONFIG                              STD_ON
#define CAN_ISDEF_INT_ROUTINGGROUPOFPCCONFIG                          STD_ON
#define CAN_ISDEF_INITOBJECTBAUDRATEOFPCCONFIG                        STD_ON
#define CAN_ISDEF_INITOBJECTSTARTINDEXOFPCCONFIG                      STD_ON
#define CAN_ISDEF_ISROSIDOFPCCONFIG                                   STD_ON
#define CAN_ISDEF_MAILBOXOFPCCONFIG                                   STD_ON
#define CAN_ISDEF_MEMORYSECTIONINFOOFPCCONFIG                         STD_ON
#define CAN_ISDEF_MEMORYSECTIONOBJECTSOFPCCONFIG                      STD_ON
#define CAN_ISDEF_SIDFCOFPCCONFIG                                     STD_ON
#define CAN_ISDEF_SIDFEOFPCCONFIG                                     STD_ON
#define CAN_ISDEF_SRN_ADDRESSOFPCCONFIG                               STD_ON
#define CAN_ISDEF_SHMADROFPCCONFIG                                    STD_ON
#define CAN_ISDEF_TDCROFPCCONFIG                                      STD_ON
#define CAN_ISDEF_XIDAMOFPCCONFIG                                     STD_ON
#define CAN_ISDEF_XIDFCOFPCCONFIG                                     STD_ON
#define CAN_ISDEF_XIDFEOFPCCONFIG                                     STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CanPCEqualsAlwaysToDefines  Can Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CAN_EQ2_BTP                                                   
#define CAN_EQ2_RXBCOFBUFFERCONFIG                                    
#define CAN_EQ2_RXF0COFBUFFERCONFIG                                   
#define CAN_EQ2_RXF1COFBUFFERCONFIG                                   
#define CAN_EQ2_TXBCOFBUFFERCONFIG                                    
#define CAN_EQ2_TXEFCOFBUFFERCONFIG                                   
#define CAN_EQ2_CANIFCHANNELID                                        
#define CAN_EQ2_BASISADROFCONTROLLERCONFIG                            
#define CAN_EQ2_CANCONTROLLERDEFAULTBAUDRATEIDXOFCONTROLLERCONFIG     
#define CAN_EQ2_CANCONTROLLERDEFAULTBAUDRATEOFCONTROLLERCONFIG        
#define CAN_EQ2_ISTTCANOFCONTROLLERCONFIG                             
#define CAN_EQ2_MAILBOXRXBASICENDIDXOFCONTROLLERCONFIG                
#define CAN_EQ2_MAILBOXRXBASICLENGTHOFCONTROLLERCONFIG                
#define CAN_EQ2_MAILBOXRXBASICSTARTIDXOFCONTROLLERCONFIG              
#define CAN_EQ2_MAILBOXRXBASICUSEDOFCONTROLLERCONFIG                  
#define CAN_EQ2_MAILBOXTXBASICENDIDXOFCONTROLLERCONFIG                
#define CAN_EQ2_MAILBOXTXBASICLENGTHOFCONTROLLERCONFIG                
#define CAN_EQ2_MAILBOXTXBASICSTARTIDXOFCONTROLLERCONFIG              
#define CAN_EQ2_MAILBOXTXBASICUSEDOFCONTROLLERCONFIG                  
#define CAN_EQ2_MAILBOXUNUSEDENDIDXOFCONTROLLERCONFIG                 
#define CAN_EQ2_MAILBOXUNUSEDLENGTHOFCONTROLLERCONFIG                 
#define CAN_EQ2_MAILBOXUNUSEDSTARTIDXOFCONTROLLERCONFIG               
#define CAN_EQ2_MAILBOXUNUSEDUSEDOFCONTROLLERCONFIG                   
#define CAN_EQ2_RXBASICHWSTARTOFCONTROLLERCONFIG                      
#define CAN_EQ2_RXBASICHWSTOPOFCONTROLLERCONFIG                       
#define CAN_EQ2_RXFULLHWSTARTOFCONTROLLERCONFIG                       
#define CAN_EQ2_RXFULLHWSTOPOFCONTROLLERCONFIG                        
#define CAN_EQ2_RXSELECTIONOFCONTROLLERCONFIG                         
#define CAN_EQ2_TXBASICHWSTARTOFCONTROLLERCONFIG                      
#define CAN_EQ2_TXBASICHWSTOPOFCONTROLLERCONFIG                       
#define CAN_EQ2_TXFULLHWSTARTOFCONTROLLERCONFIG                       
#define CAN_EQ2_TXFULLHWSTOPOFCONTROLLERCONFIG                        
#define CAN_EQ2_UNUSEDHWSTARTOFCONTROLLERCONFIG                       
#define CAN_EQ2_UNUSEDHWSTOPOFCONTROLLERCONFIG                        
#define CAN_EQ2_FBTP                                                  
#define CAN_EQ2_GFC                                                   
#define CAN_EQ2_INT_PRIORITY                                          
#define CAN_EQ2_INT_ROUTINGGROUP                                      
#define CAN_EQ2_INITOBJECTBAUDRATE                                    
#define CAN_EQ2_INITOBJECTSTARTINDEX                                  
#define CAN_EQ2_ISROSID                                               
#define CAN_EQ2_ACTIVESENDOBJECTOFMAILBOX                             
#define CAN_EQ2_CONTROLLERCONFIGIDXOFMAILBOX                          
#define CAN_EQ2_HWHANDLEOFMAILBOX                                     
#define CAN_EQ2_IDVALUEOFMAILBOX                                      
#define CAN_EQ2_MAILBOXSIZEOFMAILBOX                                  
#define CAN_EQ2_MAILBOXTYPEOFMAILBOX                                  
#define CAN_EQ2_MAXDATALENOFMAILBOX                                   
#define CAN_EQ2_MEMORYSECTIONSINDEXOFMAILBOX                          
#define CAN_EQ2_MEMORYSECTIONSTARTOFMEMORYSECTIONINFO                 
#define CAN_EQ2_HWHANDLEOFMEMORYSECTIONOBJECTS                        
#define CAN_EQ2_MAILBOXELEMENTOFMEMORYSECTIONOBJECTS                  
#define CAN_EQ2_MAILBOXHANDLEOFMEMORYSECTIONOBJECTS                   
#define CAN_EQ2_FLSSAOFSIDFC                                          
#define CAN_EQ2_LSSOFSIDFC                                            
#define CAN_EQ2_SIDFEENDIDXOFSIDFC                                    
#define CAN_EQ2_SIDFESTARTIDXOFSIDFC                                  
#define CAN_EQ2_SIDFEUSEDOFSIDFC                                      
#define CAN_EQ2_SIDFE                                                 
#define CAN_EQ2_SRN_ADDRESS                                           
#define CAN_EQ2_RXBAOFSHMADR                                          
#define CAN_EQ2_RXF0AOFSHMADR                                         
#define CAN_EQ2_RXF1AOFSHMADR                                         
#define CAN_EQ2_SIDFAOFSHMADR                                         
#define CAN_EQ2_STARTADROFSHMADR                                      
#define CAN_EQ2_STOPADROFSHMADR                                       
#define CAN_EQ2_TXBAOFSHMADR                                          
#define CAN_EQ2_TXEFAOFSHMADR                                         
#define CAN_EQ2_XIDFAOFSHMADR                                         
#define CAN_EQ2_TDCR                                                  
#define CAN_EQ2_XIDAM                                                 
#define CAN_EQ2_FLESAOFXIDFC                                          
#define CAN_EQ2_LSEOFXIDFC                                            
#define CAN_EQ2_EIDFE_0OFXIDFE                                        
#define CAN_EQ2_EIDFE_1OFXIDFE                                        
#define CAN_EQ2_ACTIVESENDOBJECTOFPCCONFIG                            Can_ActiveSendObject
#define CAN_EQ2_BTPOFPCCONFIG                                         Can_BTP
#define CAN_EQ2_BUFFERCONFIGOFPCCONFIG                                Can_BufferConfig
#define CAN_EQ2_CANIFCHANNELIDOFPCCONFIG                              Can_CanIfChannelId
#define CAN_EQ2_CONTROLLERCONFIGOFPCCONFIG                            Can_ControllerConfig
#define CAN_EQ2_CONTROLLERDATAOFPCCONFIG                              Can_ControllerData
#define CAN_EQ2_FBTPOFPCCONFIG                                        Can_FBTP
#define CAN_EQ2_GFCOFPCCONFIG                                         Can_GFC
#define CAN_EQ2_INT_PRIORITYOFPCCONFIG                                Can_INT_Priority
#define CAN_EQ2_INT_ROUTINGGROUPOFPCCONFIG                            Can_INT_RoutingGroup
#define CAN_EQ2_INITOBJECTBAUDRATEOFPCCONFIG                          Can_InitObjectBaudrate
#define CAN_EQ2_INITOBJECTSTARTINDEXOFPCCONFIG                        Can_InitObjectStartIndex
#define CAN_EQ2_ISROSIDOFPCCONFIG                                     Can_IsrOsId
#define CAN_EQ2_MAILBOXOFPCCONFIG                                     Can_Mailbox
#define CAN_EQ2_MEMORYSECTIONINFOOFPCCONFIG                           Can_MemorySectionInfo
#define CAN_EQ2_MEMORYSECTIONOBJECTSOFPCCONFIG                        Can_MemorySectionObjects
#define CAN_EQ2_SIDFCOFPCCONFIG                                       Can_SIDFC
#define CAN_EQ2_SIDFEOFPCCONFIG                                       Can_SIDFE
#define CAN_EQ2_SRN_ADDRESSOFPCCONFIG                                 Can_SRN_Address
#define CAN_EQ2_SHMADROFPCCONFIG                                      Can_ShmAdr
#define CAN_EQ2_TDCROFPCCONFIG                                        Can_TDCR
#define CAN_EQ2_XIDAMOFPCCONFIG                                       Can_XIDAM
#define CAN_EQ2_XIDFCOFPCCONFIG                                       Can_XIDFC
#define CAN_EQ2_XIDFEOFPCCONFIG                                       Can_XIDFE
/** 
  \}
*/ 

/** 
  \defgroup  CanPCSymbolicInitializationPointers  Can Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define Can_Config_Ptr                                                NULL_PTR  /**< symbolic identifier which shall be used to initialize 'Can' */
/** 
  \}
*/ 

/** 
  \defgroup  CanPCInitializationSymbols  Can Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define Can_Config                                                    NULL_PTR  /**< symbolic identifier which could be used to initialize 'Can */
/** 
  \}
*/ 

/** 
  \defgroup  CanPCGeneral  Can General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define CAN_CHECK_INIT_POINTER                                        STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define CAN_FINAL_MAGIC_NUMBER                                        0x501Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of Can */
#define CAN_INDIVIDUAL_POSTBUILD                                      STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'Can' is not configured to be postbuild capable. */
#define CAN_INIT_DATA                                                 CAN_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define CAN_INIT_DATA_HASH_CODE                                       -1893185136  /**< the precompile constant to validate the initialization structure at initialization time of Can with a hashcode. The seed value is '0x501Eu' */
#define CAN_USE_ECUM_BSW_ERROR_HOOK                                   STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define CAN_USE_INIT_POINTER                                          STD_OFF  /**< STD_ON if the init pointer Can shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanLTDataSwitches  Can Data Switches  (LINK)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CAN_LTCONFIG                                                  STD_OFF  /**< Deactivateable: 'Can_LTConfig' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanPBDataSwitches  Can Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CAN_PBCONFIG                                                  STD_OFF  /**< Deactivateable: 'Can_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CAN_LTCONFIGIDXOFPBCONFIG                                     STD_OFF  /**< Deactivateable: 'Can_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CAN_PCCONFIGIDXOFPBCONFIG                                     STD_OFF  /**< Deactivateable: 'Can_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 



/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanPCGetConstantDuplicatedRootDataMacros  Can Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define Can_GetActiveSendObjectOfPCConfig()                           Can_ActiveSendObject  /**< the pointer to Can_ActiveSendObject */
#define Can_GetBTPOfPCConfig()                                        Can_BTP  /**< the pointer to Can_BTP */
#define Can_GetBaseDll_GeneratorVersionOfPCConfig()                   0x0103u
#define Can_GetBufferConfigOfPCConfig()                               Can_BufferConfig  /**< the pointer to Can_BufferConfig */
#define Can_GetCAN_FD_NISOOfPCConfig()                                0x00u  /**< MCAN ISO/Bosch conformance */
#define Can_GetCAN_NUMBER_OF_SRNOfPCConfig()                          0x01u  /**< Number of Service Request Nodes */
#define Can_GetC_ENABLE_MPC5700_MCAN_CREL_SSTEPOfPCConfig()           0x05u  /**< MCAN Release Sub Step */
#define Can_GetC_ENABLE_MPC5700_MCAN_CREL_STEPOfPCConfig()            0x01u  /**< MCAN Release Step */
#define Can_GetC_ENABLE_MPC5700_MCAN_MAJOR_CRELOfPCConfig()           0x03u  /**< MCAN Release Version */
#define Can_GetCanIfChannelIdOfPCConfig()                             Can_CanIfChannelId  /**< the pointer to Can_CanIfChannelId */
#define Can_GetControllerConfigOfPCConfig()                           Can_ControllerConfig  /**< the pointer to Can_ControllerConfig */
#define Can_GetControllerDataOfPCConfig()                             Can_ControllerData  /**< the pointer to Can_ControllerData */
#define Can_GetFBTPOfPCConfig()                                       Can_FBTP  /**< the pointer to Can_FBTP */
#define Can_GetGFCOfPCConfig()                                        Can_GFC  /**< the pointer to Can_GFC */
#define Can_GetINT_PriorityOfPCConfig()                               Can_INT_Priority  /**< the pointer to Can_INT_Priority */
#define Can_GetINT_RoutingGroupOfPCConfig()                           Can_INT_RoutingGroup  /**< the pointer to Can_INT_RoutingGroup */
#define Can_GetInitObjectBaudrateOfPCConfig()                         Can_InitObjectBaudrate  /**< the pointer to Can_InitObjectBaudrate */
#define Can_GetInitObjectStartIndexOfPCConfig()                       Can_InitObjectStartIndex  /**< the pointer to Can_InitObjectStartIndex */
#define Can_GetIsrOsIdOfPCConfig()                                    Can_IsrOsId  /**< the pointer to Can_IsrOsId */
#define Can_GetMailboxOfPCConfig()                                    Can_Mailbox  /**< the pointer to Can_Mailbox */
#define Can_GetMemorySectionInfoOfPCConfig()                          Can_MemorySectionInfo  /**< the pointer to Can_MemorySectionInfo */
#define Can_GetMemorySectionObjectsOfPCConfig()                       Can_MemorySectionObjects  /**< the pointer to Can_MemorySectionObjects */
#define Can_GetPlatformDll_GeneratorVersionOfPCConfig()               0x0100u
#define Can_GetSIDFCOfPCConfig()                                      Can_SIDFC  /**< the pointer to Can_SIDFC */
#define Can_GetSIDFEOfPCConfig()                                      Can_SIDFE  /**< the pointer to Can_SIDFE */
#define Can_GetSRN_AddressOfPCConfig()                                Can_SRN_Address  /**< the pointer to Can_SRN_Address */
#define Can_GetShmAdrOfPCConfig()                                     Can_ShmAdr  /**< the pointer to Can_ShmAdr */
#define Can_GetSizeOfActiveSendObjectOfPCConfig()                     1u  /**< the number of accomplishable value elements in Can_ActiveSendObject */
#define Can_GetSizeOfBTPOfPCConfig()                                  1u  /**< the number of accomplishable value elements in Can_BTP */
#define Can_GetSizeOfBufferConfigOfPCConfig()                         1u  /**< the number of accomplishable value elements in Can_BufferConfig */
#define Can_GetSizeOfCanIfChannelIdOfPCConfig()                       1u  /**< the number of accomplishable value elements in Can_CanIfChannelId */
#define Can_GetSizeOfControllerConfigOfPCConfig()                     1u  /**< the number of accomplishable value elements in Can_ControllerConfig */
#define Can_GetSizeOfFBTPOfPCConfig()                                 1u  /**< the number of accomplishable value elements in Can_FBTP */
#define Can_GetSizeOfGFCOfPCConfig()                                  1u  /**< the number of accomplishable value elements in Can_GFC */
#define Can_GetSizeOfINT_PriorityOfPCConfig()                         1u  /**< the number of accomplishable value elements in Can_INT_Priority */
#define Can_GetSizeOfINT_RoutingGroupOfPCConfig()                     1u  /**< the number of accomplishable value elements in Can_INT_RoutingGroup */
#define Can_GetSizeOfInitObjectBaudrateOfPCConfig()                   1u  /**< the number of accomplishable value elements in Can_InitObjectBaudrate */
#define Can_GetSizeOfInitObjectStartIndexOfPCConfig()                 2u  /**< the number of accomplishable value elements in Can_InitObjectStartIndex */
#define Can_GetSizeOfIsrOsIdOfPCConfig()                              1u  /**< the number of accomplishable value elements in Can_IsrOsId */
#define Can_GetSizeOfMailboxOfPCConfig()                              3u  /**< the number of accomplishable value elements in Can_Mailbox */
#define Can_GetSizeOfMemorySectionInfoOfPCConfig()                    1u  /**< the number of accomplishable value elements in Can_MemorySectionInfo */
#define Can_GetSizeOfMemorySectionObjectsOfPCConfig()                 2u  /**< the number of accomplishable value elements in Can_MemorySectionObjects */
#define Can_GetSizeOfSIDFCOfPCConfig()                                1u  /**< the number of accomplishable value elements in Can_SIDFC */
#define Can_GetSizeOfSIDFEOfPCConfig()                                1u  /**< the number of accomplishable value elements in Can_SIDFE */
#define Can_GetSizeOfSRN_AddressOfPCConfig()                          1u  /**< the number of accomplishable value elements in Can_SRN_Address */
#define Can_GetSizeOfShmAdrOfPCConfig()                               1u  /**< the number of accomplishable value elements in Can_ShmAdr */
#define Can_GetSizeOfTDCROfPCConfig()                                 1u  /**< the number of accomplishable value elements in Can_TDCR */
#define Can_GetSizeOfXIDAMOfPCConfig()                                1u  /**< the number of accomplishable value elements in Can_XIDAM */
#define Can_GetSizeOfXIDFCOfPCConfig()                                1u  /**< the number of accomplishable value elements in Can_XIDFC */
#define Can_GetSizeOfXIDFEOfPCConfig()                                1u  /**< the number of accomplishable value elements in Can_XIDFE */
#define Can_GetTDCROfPCConfig()                                       Can_TDCR  /**< the pointer to Can_TDCR */
#define Can_GetXIDAMOfPCConfig()                                      Can_XIDAM  /**< the pointer to Can_XIDAM */
#define Can_GetXIDFCOfPCConfig()                                      Can_XIDFC  /**< the pointer to Can_XIDFC */
#define Can_GetXIDFEOfPCConfig()                                      Can_XIDFE  /**< the pointer to Can_XIDFE */
#define Can_GetkCanUsedCoreOfPCConfig()                               0x00u  /**< CAN Interrupt CPU Core Selection */
/** 
  \}
*/ 

/** 
  \defgroup  CanPCGetDuplicatedRootDataMacros  Can Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define Can_GetSizeOfControllerDataOfPCConfig()                       Can_GetSizeOfControllerConfigOfPCConfig()  /**< the number of accomplishable value elements in Can_ControllerData */
/** 
  \}
*/ 

/** 
  \defgroup  CanPCGetDataMacros  Can Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define Can_GetPduOfActiveSendObject(Index)                           (Can_GetActiveSendObjectOfPCConfig()[(Index)].PduOfActiveSendObject)
#define Can_GetStateOfActiveSendObject(Index)                         (Can_GetActiveSendObjectOfPCConfig()[(Index)].StateOfActiveSendObject)
#define Can_GetBTP(Index)                                             (Can_GetBTPOfPCConfig()[(Index)])
#define Can_GetRXBCOfBufferConfig(Index)                              (Can_GetBufferConfigOfPCConfig()[(Index)].RXBCOfBufferConfig)
#define Can_GetRXF0COfBufferConfig(Index)                             (Can_GetBufferConfigOfPCConfig()[(Index)].RXF0COfBufferConfig)
#define Can_GetRXF1COfBufferConfig(Index)                             (Can_GetBufferConfigOfPCConfig()[(Index)].RXF1COfBufferConfig)
#define Can_GetTXBCOfBufferConfig(Index)                              (Can_GetBufferConfigOfPCConfig()[(Index)].TXBCOfBufferConfig)
#define Can_GetTXEFCOfBufferConfig(Index)                             (Can_GetBufferConfigOfPCConfig()[(Index)].TXEFCOfBufferConfig)
#define Can_GetCanIfChannelId(Index)                                  (Can_GetCanIfChannelIdOfPCConfig()[(Index)])
#define Can_GetBasisAdrOfControllerConfig(Index)                      (Can_GetControllerConfigOfPCConfig()[(Index)].BasisAdrOfControllerConfig)
#define Can_GetCanControllerDefaultBaudrateIdxOfControllerConfig(Index) (Can_GetControllerConfigOfPCConfig()[(Index)].CanControllerDefaultBaudrateIdxOfControllerConfig)
#define Can_GetCanControllerDefaultBaudrateOfControllerConfig(Index)  (Can_GetControllerConfigOfPCConfig()[(Index)].CanControllerDefaultBaudrateOfControllerConfig)
#define Can_IsIsTTCanOfControllerConfig(Index)                        ((Can_GetControllerConfigOfPCConfig()[(Index)].IsTTCanOfControllerConfig) != FALSE)
#define Can_GetMailboxRxBasicEndIdxOfControllerConfig(Index)          (Can_GetControllerConfigOfPCConfig()[(Index)].MailboxRxBasicEndIdxOfControllerConfig)
#define Can_GetMailboxRxBasicLengthOfControllerConfig(Index)          (Can_GetControllerConfigOfPCConfig()[(Index)].MailboxRxBasicLengthOfControllerConfig)
#define Can_GetMailboxRxBasicStartIdxOfControllerConfig(Index)        (Can_GetControllerConfigOfPCConfig()[(Index)].MailboxRxBasicStartIdxOfControllerConfig)
#define Can_GetMailboxTxBasicEndIdxOfControllerConfig(Index)          (Can_GetControllerConfigOfPCConfig()[(Index)].MailboxTxBasicEndIdxOfControllerConfig)
#define Can_GetMailboxTxBasicLengthOfControllerConfig(Index)          (Can_GetControllerConfigOfPCConfig()[(Index)].MailboxTxBasicLengthOfControllerConfig)
#define Can_GetMailboxTxBasicStartIdxOfControllerConfig(Index)        (Can_GetControllerConfigOfPCConfig()[(Index)].MailboxTxBasicStartIdxOfControllerConfig)
#define Can_GetMailboxUnusedEndIdxOfControllerConfig(Index)           (Can_GetControllerConfigOfPCConfig()[(Index)].MailboxUnusedEndIdxOfControllerConfig)
#define Can_GetMailboxUnusedLengthOfControllerConfig(Index)           (Can_GetControllerConfigOfPCConfig()[(Index)].MailboxUnusedLengthOfControllerConfig)
#define Can_GetMailboxUnusedStartIdxOfControllerConfig(Index)         (Can_GetControllerConfigOfPCConfig()[(Index)].MailboxUnusedStartIdxOfControllerConfig)
#define Can_GetRxBasicHwStartOfControllerConfig(Index)                (Can_GetControllerConfigOfPCConfig()[(Index)].RxBasicHwStartOfControllerConfig)
#define Can_GetRxBasicHwStopOfControllerConfig(Index)                 (Can_GetControllerConfigOfPCConfig()[(Index)].RxBasicHwStopOfControllerConfig)
#define Can_GetRxFullHwStartOfControllerConfig(Index)                 (Can_GetControllerConfigOfPCConfig()[(Index)].RxFullHwStartOfControllerConfig)
#define Can_GetRxFullHwStopOfControllerConfig(Index)                  (Can_GetControllerConfigOfPCConfig()[(Index)].RxFullHwStopOfControllerConfig)
#define Can_GetRxSelectionOfControllerConfig(Index)                   (Can_GetControllerConfigOfPCConfig()[(Index)].RxSelectionOfControllerConfig)
#define Can_GetTxBasicHwStartOfControllerConfig(Index)                (Can_GetControllerConfigOfPCConfig()[(Index)].TxBasicHwStartOfControllerConfig)
#define Can_GetTxBasicHwStopOfControllerConfig(Index)                 (Can_GetControllerConfigOfPCConfig()[(Index)].TxBasicHwStopOfControllerConfig)
#define Can_GetTxFullHwStartOfControllerConfig(Index)                 (Can_GetControllerConfigOfPCConfig()[(Index)].TxFullHwStartOfControllerConfig)
#define Can_GetTxFullHwStopOfControllerConfig(Index)                  (Can_GetControllerConfigOfPCConfig()[(Index)].TxFullHwStopOfControllerConfig)
#define Can_GetUnusedHwStartOfControllerConfig(Index)                 (Can_GetControllerConfigOfPCConfig()[(Index)].UnusedHwStartOfControllerConfig)
#define Can_GetUnusedHwStopOfControllerConfig(Index)                  (Can_GetControllerConfigOfPCConfig()[(Index)].UnusedHwStopOfControllerConfig)
#define Can_GetBusOffNotificationOfControllerData(Index)              (Can_GetControllerDataOfPCConfig()[(Index)].BusOffNotificationOfControllerData)
#define Can_GetBusOffTransitionRequestOfControllerData(Index)         (Can_GetControllerDataOfPCConfig()[(Index)].BusOffTransitionRequestOfControllerData)
#define Can_GetCanInterruptCounterOfControllerData(Index)             (Can_GetControllerDataOfPCConfig()[(Index)].CanInterruptCounterOfControllerData)
#define Can_GetCanInterruptOldStatusOfControllerData(Index)           (Can_GetControllerDataOfPCConfig()[(Index)].CanInterruptOldStatusOfControllerData)
#define Can_GetIntEnableOfControllerData(Index)                       (Can_GetControllerDataOfPCConfig()[(Index)].IntEnableOfControllerData)
#define Can_IsIsBusOffOfControllerData(Index)                         ((Can_GetControllerDataOfPCConfig()[(Index)].IsBusOffOfControllerData) != FALSE)
#define Can_GetLastInitObjectOfControllerData(Index)                  (Can_GetControllerDataOfPCConfig()[(Index)].LastInitObjectOfControllerData)
#define Can_GetLastStateOfControllerData(Index)                       (Can_GetControllerDataOfPCConfig()[(Index)].LastStateOfControllerData)
#define Can_GetLogStatusOfControllerData(Index)                       (Can_GetControllerDataOfPCConfig()[(Index)].LogStatusOfControllerData)
#define Can_GetLoopTimeoutOfControllerData(Index)                     (Can_GetControllerDataOfPCConfig()[(Index)].LoopTimeoutOfControllerData)
#define Can_GetModeTransitionRequestOfControllerData(Index)           (Can_GetControllerDataOfPCConfig()[(Index)].ModeTransitionRequestOfControllerData)
#define Can_GetPrevModeOfControllerData(Index)                        (Can_GetControllerDataOfPCConfig()[(Index)].PrevModeOfControllerData)
#define Can_GetRamCheckTransitionRequestOfControllerData(Index)       (Can_GetControllerDataOfPCConfig()[(Index)].RamCheckTransitionRequestOfControllerData)
#define Can_GetTXBCROfControllerData(Index)                           (Can_GetControllerDataOfPCConfig()[(Index)].TXBCROfControllerData)
#define Can_GetTXBRPOfControllerData(Index)                           (Can_GetControllerDataOfPCConfig()[(Index)].TXBRPOfControllerData)
#define Can_GetFBTP(Index)                                            (Can_GetFBTPOfPCConfig()[(Index)])
#define Can_GetGFC(Index)                                             (Can_GetGFCOfPCConfig()[(Index)])
#define Can_GetINT_Priority(Index)                                    (Can_GetINT_PriorityOfPCConfig()[(Index)])
#define Can_GetINT_RoutingGroup(Index)                                (Can_GetINT_RoutingGroupOfPCConfig()[(Index)])
#define Can_GetInitObjectBaudrate(Index)                              (Can_GetInitObjectBaudrateOfPCConfig()[(Index)])
#define Can_GetInitObjectStartIndex(Index)                            (Can_GetInitObjectStartIndexOfPCConfig()[(Index)])
#define Can_GetIsrOsId(Index)                                         (Can_GetIsrOsIdOfPCConfig()[(Index)])
#define Can_GetActiveSendObjectOfMailbox(Index)                       (Can_GetMailboxOfPCConfig()[(Index)].ActiveSendObjectOfMailbox)
#define Can_GetControllerConfigIdxOfMailbox(Index)                    (Can_GetMailboxOfPCConfig()[(Index)].ControllerConfigIdxOfMailbox)
#define Can_GetHwHandleOfMailbox(Index)                               (Can_GetMailboxOfPCConfig()[(Index)].HwHandleOfMailbox)
#define Can_GetIDValueOfMailbox(Index)                                (Can_GetMailboxOfPCConfig()[(Index)].IDValueOfMailbox)
#define Can_GetMailboxSizeOfMailbox(Index)                            (Can_GetMailboxOfPCConfig()[(Index)].MailboxSizeOfMailbox)
#define Can_GetMailboxTypeOfMailbox(Index)                            (Can_GetMailboxOfPCConfig()[(Index)].MailboxTypeOfMailbox)
#define Can_GetMaxDataLenOfMailbox(Index)                             (Can_GetMailboxOfPCConfig()[(Index)].MaxDataLenOfMailbox)
#define Can_GetMemorySectionsIndexOfMailbox(Index)                    (Can_GetMailboxOfPCConfig()[(Index)].MemorySectionsIndexOfMailbox)
#define Can_GetMemorySectionStartOfMemorySectionInfo(Index)           (Can_GetMemorySectionInfoOfPCConfig()[(Index)].MemorySectionStartOfMemorySectionInfo)
#define Can_GetHwHandleOfMemorySectionObjects(Index)                  (Can_GetMemorySectionObjectsOfPCConfig()[(Index)].HwHandleOfMemorySectionObjects)
#define Can_GetMailboxElementOfMemorySectionObjects(Index)            (Can_GetMemorySectionObjectsOfPCConfig()[(Index)].MailboxElementOfMemorySectionObjects)
#define Can_GetMailboxHandleOfMemorySectionObjects(Index)             (Can_GetMemorySectionObjectsOfPCConfig()[(Index)].MailboxHandleOfMemorySectionObjects)
#define Can_GetFLSSAOfSIDFC(Index)                                    (Can_GetSIDFCOfPCConfig()[(Index)].FLSSAOfSIDFC)
#define Can_GetLSSOfSIDFC(Index)                                      (Can_GetSIDFCOfPCConfig()[(Index)].LSSOfSIDFC)
#define Can_GetSIDFEEndIdxOfSIDFC(Index)                              (Can_GetSIDFCOfPCConfig()[(Index)].SIDFEEndIdxOfSIDFC)
#define Can_GetSIDFEStartIdxOfSIDFC(Index)                            (Can_GetSIDFCOfPCConfig()[(Index)].SIDFEStartIdxOfSIDFC)
#define Can_GetSIDFE(Index)                                           (Can_GetSIDFEOfPCConfig()[(Index)])
#define Can_GetSRN_Address(Index)                                     (Can_GetSRN_AddressOfPCConfig()[(Index)])
#define Can_GetRXBAOfShmAdr(Index)                                    (Can_GetShmAdrOfPCConfig()[(Index)].RXBAOfShmAdr)
#define Can_GetRXF0AOfShmAdr(Index)                                   (Can_GetShmAdrOfPCConfig()[(Index)].RXF0AOfShmAdr)
#define Can_GetRXF1AOfShmAdr(Index)                                   (Can_GetShmAdrOfPCConfig()[(Index)].RXF1AOfShmAdr)
#define Can_GetSIDFAOfShmAdr(Index)                                   (Can_GetShmAdrOfPCConfig()[(Index)].SIDFAOfShmAdr)
#define Can_GetStartAdrOfShmAdr(Index)                                (Can_GetShmAdrOfPCConfig()[(Index)].StartAdrOfShmAdr)
#define Can_GetStopAdrOfShmAdr(Index)                                 (Can_GetShmAdrOfPCConfig()[(Index)].StopAdrOfShmAdr)
#define Can_GetTXBAOfShmAdr(Index)                                    (Can_GetShmAdrOfPCConfig()[(Index)].TXBAOfShmAdr)
#define Can_GetTXEFAOfShmAdr(Index)                                   (Can_GetShmAdrOfPCConfig()[(Index)].TXEFAOfShmAdr)
#define Can_GetXIDFAOfShmAdr(Index)                                   (Can_GetShmAdrOfPCConfig()[(Index)].XIDFAOfShmAdr)
#define Can_GetTDCR(Index)                                            (Can_GetTDCROfPCConfig()[(Index)])
#define Can_GetXIDAM(Index)                                           (Can_GetXIDAMOfPCConfig()[(Index)])
#define Can_GetFLESAOfXIDFC(Index)                                    (Can_GetXIDFCOfPCConfig()[(Index)].FLESAOfXIDFC)
#define Can_GetLSEOfXIDFC(Index)                                      (Can_GetXIDFCOfPCConfig()[(Index)].LSEOfXIDFC)
#define Can_GetEIDFE_0OfXIDFE(Index)                                  (Can_GetXIDFEOfPCConfig()[(Index)].EIDFE_0OfXIDFE)
#define Can_GetEIDFE_1OfXIDFE(Index)                                  (Can_GetXIDFEOfPCConfig()[(Index)].EIDFE_1OfXIDFE)
/** 
  \}
*/ 

/** 
  \defgroup  CanPCGetDeduplicatedDataMacros  Can Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define Can_GetBaseDll_GeneratorVersion()                             Can_GetBaseDll_GeneratorVersionOfPCConfig()
#define Can_GetCAN_FD_NISO()                                          Can_GetCAN_FD_NISOOfPCConfig()
#define Can_GetCAN_NUMBER_OF_SRN()                                    Can_GetCAN_NUMBER_OF_SRNOfPCConfig()
#define Can_GetC_ENABLE_MPC5700_MCAN_CREL_SSTEP()                     Can_GetC_ENABLE_MPC5700_MCAN_CREL_SSTEPOfPCConfig()
#define Can_GetC_ENABLE_MPC5700_MCAN_CREL_STEP()                      Can_GetC_ENABLE_MPC5700_MCAN_CREL_STEPOfPCConfig()
#define Can_GetC_ENABLE_MPC5700_MCAN_MAJOR_CREL()                     Can_GetC_ENABLE_MPC5700_MCAN_MAJOR_CRELOfPCConfig()
#define Can_IsMailboxRxBasicUsedOfControllerConfig(Index)             (((boolean)(Can_GetMailboxRxBasicLengthOfControllerConfig(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Can_Mailbox */
#define Can_IsMailboxTxBasicUsedOfControllerConfig(Index)             (((boolean)(Can_GetMailboxTxBasicLengthOfControllerConfig(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Can_Mailbox */
#define Can_IsMailboxUnusedUsedOfControllerConfig(Index)              (((boolean)(Can_GetMailboxUnusedLengthOfControllerConfig(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Can_Mailbox */
#define Can_GetPlatformDll_GeneratorVersion()                         Can_GetPlatformDll_GeneratorVersionOfPCConfig()
#define Can_IsSIDFEUsedOfSIDFC(Index)                                 (((boolean)(Can_GetSIDFEStartIdxOfSIDFC(Index) != CAN_NO_SIDFESTARTIDXOFSIDFC)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Can_SIDFE */
#define Can_GetSizeOfActiveSendObject()                               Can_GetSizeOfActiveSendObjectOfPCConfig()
#define Can_GetSizeOfBTP()                                            Can_GetSizeOfBTPOfPCConfig()
#define Can_GetSizeOfBufferConfig()                                   Can_GetSizeOfBufferConfigOfPCConfig()
#define Can_GetSizeOfCanIfChannelId()                                 Can_GetSizeOfCanIfChannelIdOfPCConfig()
#define Can_GetSizeOfControllerConfig()                               Can_GetSizeOfControllerConfigOfPCConfig()
#define Can_GetSizeOfControllerData()                                 Can_GetSizeOfControllerDataOfPCConfig()
#define Can_GetSizeOfFBTP()                                           Can_GetSizeOfFBTPOfPCConfig()
#define Can_GetSizeOfGFC()                                            Can_GetSizeOfGFCOfPCConfig()
#define Can_GetSizeOfINT_Priority()                                   Can_GetSizeOfINT_PriorityOfPCConfig()
#define Can_GetSizeOfINT_RoutingGroup()                               Can_GetSizeOfINT_RoutingGroupOfPCConfig()
#define Can_GetSizeOfInitObjectBaudrate()                             Can_GetSizeOfInitObjectBaudrateOfPCConfig()
#define Can_GetSizeOfInitObjectStartIndex()                           Can_GetSizeOfInitObjectStartIndexOfPCConfig()
#define Can_GetSizeOfIsrOsId()                                        Can_GetSizeOfIsrOsIdOfPCConfig()
#define Can_GetSizeOfMailbox()                                        Can_GetSizeOfMailboxOfPCConfig()
#define Can_GetSizeOfMemorySectionInfo()                              Can_GetSizeOfMemorySectionInfoOfPCConfig()
#define Can_GetSizeOfMemorySectionObjects()                           Can_GetSizeOfMemorySectionObjectsOfPCConfig()
#define Can_GetSizeOfSIDFC()                                          Can_GetSizeOfSIDFCOfPCConfig()
#define Can_GetSizeOfSIDFE()                                          Can_GetSizeOfSIDFEOfPCConfig()
#define Can_GetSizeOfSRN_Address()                                    Can_GetSizeOfSRN_AddressOfPCConfig()
#define Can_GetSizeOfShmAdr()                                         Can_GetSizeOfShmAdrOfPCConfig()
#define Can_GetSizeOfTDCR()                                           Can_GetSizeOfTDCROfPCConfig()
#define Can_GetSizeOfXIDAM()                                          Can_GetSizeOfXIDAMOfPCConfig()
#define Can_GetSizeOfXIDFC()                                          Can_GetSizeOfXIDFCOfPCConfig()
#define Can_GetSizeOfXIDFE()                                          Can_GetSizeOfXIDFEOfPCConfig()
#define Can_GetkCanUsedCore()                                         Can_GetkCanUsedCoreOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  CanPCSetDataMacros  Can Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define Can_SetPduOfActiveSendObject(Index, Value)                    Can_GetActiveSendObjectOfPCConfig()[(Index)].PduOfActiveSendObject = (Value)
#define Can_SetStateOfActiveSendObject(Index, Value)                  Can_GetActiveSendObjectOfPCConfig()[(Index)].StateOfActiveSendObject = (Value)
#define Can_SetBusOffNotificationOfControllerData(Index, Value)       Can_GetControllerDataOfPCConfig()[(Index)].BusOffNotificationOfControllerData = (Value)
#define Can_SetBusOffTransitionRequestOfControllerData(Index, Value)  Can_GetControllerDataOfPCConfig()[(Index)].BusOffTransitionRequestOfControllerData = (Value)
#define Can_SetCanInterruptCounterOfControllerData(Index, Value)      Can_GetControllerDataOfPCConfig()[(Index)].CanInterruptCounterOfControllerData = (Value)
#define Can_SetCanInterruptOldStatusOfControllerData(Index, Value)    Can_GetControllerDataOfPCConfig()[(Index)].CanInterruptOldStatusOfControllerData = (Value)
#define Can_SetIntEnableOfControllerData(Index, Value)                Can_GetControllerDataOfPCConfig()[(Index)].IntEnableOfControllerData = (Value)
#define Can_SetIsBusOffOfControllerData(Index, Value)                 Can_GetControllerDataOfPCConfig()[(Index)].IsBusOffOfControllerData = (Value)
#define Can_SetLastInitObjectOfControllerData(Index, Value)           Can_GetControllerDataOfPCConfig()[(Index)].LastInitObjectOfControllerData = (Value)
#define Can_SetLastStateOfControllerData(Index, Value)                Can_GetControllerDataOfPCConfig()[(Index)].LastStateOfControllerData = (Value)
#define Can_SetLogStatusOfControllerData(Index, Value)                Can_GetControllerDataOfPCConfig()[(Index)].LogStatusOfControllerData = (Value)
#define Can_SetLoopTimeoutOfControllerData(Index, Value)              Can_GetControllerDataOfPCConfig()[(Index)].LoopTimeoutOfControllerData = (Value)
#define Can_SetModeTransitionRequestOfControllerData(Index, Value)    Can_GetControllerDataOfPCConfig()[(Index)].ModeTransitionRequestOfControllerData = (Value)
#define Can_SetPrevModeOfControllerData(Index, Value)                 Can_GetControllerDataOfPCConfig()[(Index)].PrevModeOfControllerData = (Value)
#define Can_SetRamCheckTransitionRequestOfControllerData(Index, Value) Can_GetControllerDataOfPCConfig()[(Index)].RamCheckTransitionRequestOfControllerData = (Value)
#define Can_SetTXBCROfControllerData(Index, Value)                    Can_GetControllerDataOfPCConfig()[(Index)].TXBCROfControllerData = (Value)
#define Can_SetTXBRPOfControllerData(Index, Value)                    Can_GetControllerDataOfPCConfig()[(Index)].TXBRPOfControllerData = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  CanPCHasMacros  Can Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Can_HasActiveSendObject()                                     (TRUE != FALSE)
#define Can_HasPduOfActiveSendObject()                                (TRUE != FALSE)
#define Can_HasStateOfActiveSendObject()                              (TRUE != FALSE)
#define Can_HasBTP()                                                  (TRUE != FALSE)
#define Can_HasBaseDll_GeneratorVersion()                             (TRUE != FALSE)
#define Can_HasBufferConfig()                                         (TRUE != FALSE)
#define Can_HasRXBCOfBufferConfig()                                   (TRUE != FALSE)
#define Can_HasRXF0COfBufferConfig()                                  (TRUE != FALSE)
#define Can_HasRXF1COfBufferConfig()                                  (TRUE != FALSE)
#define Can_HasTXBCOfBufferConfig()                                   (TRUE != FALSE)
#define Can_HasTXEFCOfBufferConfig()                                  (TRUE != FALSE)
#define Can_HasCAN_FD_NISO()                                          (TRUE != FALSE)
#define Can_HasCAN_NUMBER_OF_SRN()                                    (TRUE != FALSE)
#define Can_HasC_ENABLE_MPC5700_MCAN_CREL_SSTEP()                     (TRUE != FALSE)
#define Can_HasC_ENABLE_MPC5700_MCAN_CREL_STEP()                      (TRUE != FALSE)
#define Can_HasC_ENABLE_MPC5700_MCAN_MAJOR_CREL()                     (TRUE != FALSE)
#define Can_HasCanIfChannelId()                                       (TRUE != FALSE)
#define Can_HasControllerConfig()                                     (TRUE != FALSE)
#define Can_HasBasisAdrOfControllerConfig()                           (TRUE != FALSE)
#define Can_HasCanControllerDefaultBaudrateIdxOfControllerConfig()    (TRUE != FALSE)
#define Can_HasCanControllerDefaultBaudrateOfControllerConfig()       (TRUE != FALSE)
#define Can_HasIsTTCanOfControllerConfig()                            (TRUE != FALSE)
#define Can_HasMailboxRxBasicEndIdxOfControllerConfig()               (TRUE != FALSE)
#define Can_HasMailboxRxBasicLengthOfControllerConfig()               (TRUE != FALSE)
#define Can_HasMailboxRxBasicStartIdxOfControllerConfig()             (TRUE != FALSE)
#define Can_HasMailboxRxBasicUsedOfControllerConfig()                 (TRUE != FALSE)
#define Can_HasMailboxTxBasicEndIdxOfControllerConfig()               (TRUE != FALSE)
#define Can_HasMailboxTxBasicLengthOfControllerConfig()               (TRUE != FALSE)
#define Can_HasMailboxTxBasicStartIdxOfControllerConfig()             (TRUE != FALSE)
#define Can_HasMailboxTxBasicUsedOfControllerConfig()                 (TRUE != FALSE)
#define Can_HasMailboxUnusedEndIdxOfControllerConfig()                (TRUE != FALSE)
#define Can_HasMailboxUnusedLengthOfControllerConfig()                (TRUE != FALSE)
#define Can_HasMailboxUnusedStartIdxOfControllerConfig()              (TRUE != FALSE)
#define Can_HasMailboxUnusedUsedOfControllerConfig()                  (TRUE != FALSE)
#define Can_HasRxBasicHwStartOfControllerConfig()                     (TRUE != FALSE)
#define Can_HasRxBasicHwStopOfControllerConfig()                      (TRUE != FALSE)
#define Can_HasRxFullHwStartOfControllerConfig()                      (TRUE != FALSE)
#define Can_HasRxFullHwStopOfControllerConfig()                       (TRUE != FALSE)
#define Can_HasRxSelectionOfControllerConfig()                        (TRUE != FALSE)
#define Can_HasTxBasicHwStartOfControllerConfig()                     (TRUE != FALSE)
#define Can_HasTxBasicHwStopOfControllerConfig()                      (TRUE != FALSE)
#define Can_HasTxFullHwStartOfControllerConfig()                      (TRUE != FALSE)
#define Can_HasTxFullHwStopOfControllerConfig()                       (TRUE != FALSE)
#define Can_HasUnusedHwStartOfControllerConfig()                      (TRUE != FALSE)
#define Can_HasUnusedHwStopOfControllerConfig()                       (TRUE != FALSE)
#define Can_HasControllerData()                                       (TRUE != FALSE)
#define Can_HasBusOffNotificationOfControllerData()                   (TRUE != FALSE)
#define Can_HasBusOffTransitionRequestOfControllerData()              (TRUE != FALSE)
#define Can_HasCanInterruptCounterOfControllerData()                  (TRUE != FALSE)
#define Can_HasCanInterruptOldStatusOfControllerData()                (TRUE != FALSE)
#define Can_HasIntEnableOfControllerData()                            (TRUE != FALSE)
#define Can_HasIsBusOffOfControllerData()                             (TRUE != FALSE)
#define Can_HasLastInitObjectOfControllerData()                       (TRUE != FALSE)
#define Can_HasLastStateOfControllerData()                            (TRUE != FALSE)
#define Can_HasLogStatusOfControllerData()                            (TRUE != FALSE)
#define Can_HasLoopTimeoutOfControllerData()                          (TRUE != FALSE)
#define Can_HasModeTransitionRequestOfControllerData()                (TRUE != FALSE)
#define Can_HasPrevModeOfControllerData()                             (TRUE != FALSE)
#define Can_HasRamCheckTransitionRequestOfControllerData()            (TRUE != FALSE)
#define Can_HasTXBCROfControllerData()                                (TRUE != FALSE)
#define Can_HasTXBRPOfControllerData()                                (TRUE != FALSE)
#define Can_HasFBTP()                                                 (TRUE != FALSE)
#define Can_HasGFC()                                                  (TRUE != FALSE)
#define Can_HasINT_Priority()                                         (TRUE != FALSE)
#define Can_HasINT_RoutingGroup()                                     (TRUE != FALSE)
#define Can_HasInitObjectBaudrate()                                   (TRUE != FALSE)
#define Can_HasInitObjectStartIndex()                                 (TRUE != FALSE)
#define Can_HasIsrOsId()                                              (TRUE != FALSE)
#define Can_HasMailbox()                                              (TRUE != FALSE)
#define Can_HasActiveSendObjectOfMailbox()                            (TRUE != FALSE)
#define Can_HasControllerConfigIdxOfMailbox()                         (TRUE != FALSE)
#define Can_HasHwHandleOfMailbox()                                    (TRUE != FALSE)
#define Can_HasIDValueOfMailbox()                                     (TRUE != FALSE)
#define Can_HasMailboxSizeOfMailbox()                                 (TRUE != FALSE)
#define Can_HasMailboxTypeOfMailbox()                                 (TRUE != FALSE)
#define Can_HasMaxDataLenOfMailbox()                                  (TRUE != FALSE)
#define Can_HasMemorySectionsIndexOfMailbox()                         (TRUE != FALSE)
#define Can_HasMemorySectionInfo()                                    (TRUE != FALSE)
#define Can_HasMemorySectionStartOfMemorySectionInfo()                (TRUE != FALSE)
#define Can_HasMemorySectionObjects()                                 (TRUE != FALSE)
#define Can_HasHwHandleOfMemorySectionObjects()                       (TRUE != FALSE)
#define Can_HasMailboxElementOfMemorySectionObjects()                 (TRUE != FALSE)
#define Can_HasMailboxHandleOfMemorySectionObjects()                  (TRUE != FALSE)
#define Can_HasPlatformDll_GeneratorVersion()                         (TRUE != FALSE)
#define Can_HasSIDFC()                                                (TRUE != FALSE)
#define Can_HasFLSSAOfSIDFC()                                         (TRUE != FALSE)
#define Can_HasLSSOfSIDFC()                                           (TRUE != FALSE)
#define Can_HasSIDFEEndIdxOfSIDFC()                                   (TRUE != FALSE)
#define Can_HasSIDFEStartIdxOfSIDFC()                                 (TRUE != FALSE)
#define Can_HasSIDFEUsedOfSIDFC()                                     (TRUE != FALSE)
#define Can_HasSIDFE()                                                (TRUE != FALSE)
#define Can_HasSRN_Address()                                          (TRUE != FALSE)
#define Can_HasShmAdr()                                               (TRUE != FALSE)
#define Can_HasRXBAOfShmAdr()                                         (TRUE != FALSE)
#define Can_HasRXF0AOfShmAdr()                                        (TRUE != FALSE)
#define Can_HasRXF1AOfShmAdr()                                        (TRUE != FALSE)
#define Can_HasSIDFAOfShmAdr()                                        (TRUE != FALSE)
#define Can_HasStartAdrOfShmAdr()                                     (TRUE != FALSE)
#define Can_HasStopAdrOfShmAdr()                                      (TRUE != FALSE)
#define Can_HasTXBAOfShmAdr()                                         (TRUE != FALSE)
#define Can_HasTXEFAOfShmAdr()                                        (TRUE != FALSE)
#define Can_HasXIDFAOfShmAdr()                                        (TRUE != FALSE)
#define Can_HasSizeOfActiveSendObject()                               (TRUE != FALSE)
#define Can_HasSizeOfBTP()                                            (TRUE != FALSE)
#define Can_HasSizeOfBufferConfig()                                   (TRUE != FALSE)
#define Can_HasSizeOfCanIfChannelId()                                 (TRUE != FALSE)
#define Can_HasSizeOfControllerConfig()                               (TRUE != FALSE)
#define Can_HasSizeOfControllerData()                                 (TRUE != FALSE)
#define Can_HasSizeOfFBTP()                                           (TRUE != FALSE)
#define Can_HasSizeOfGFC()                                            (TRUE != FALSE)
#define Can_HasSizeOfINT_Priority()                                   (TRUE != FALSE)
#define Can_HasSizeOfINT_RoutingGroup()                               (TRUE != FALSE)
#define Can_HasSizeOfInitObjectBaudrate()                             (TRUE != FALSE)
#define Can_HasSizeOfInitObjectStartIndex()                           (TRUE != FALSE)
#define Can_HasSizeOfIsrOsId()                                        (TRUE != FALSE)
#define Can_HasSizeOfMailbox()                                        (TRUE != FALSE)
#define Can_HasSizeOfMemorySectionInfo()                              (TRUE != FALSE)
#define Can_HasSizeOfMemorySectionObjects()                           (TRUE != FALSE)
#define Can_HasSizeOfSIDFC()                                          (TRUE != FALSE)
#define Can_HasSizeOfSIDFE()                                          (TRUE != FALSE)
#define Can_HasSizeOfSRN_Address()                                    (TRUE != FALSE)
#define Can_HasSizeOfShmAdr()                                         (TRUE != FALSE)
#define Can_HasSizeOfTDCR()                                           (TRUE != FALSE)
#define Can_HasSizeOfXIDAM()                                          (TRUE != FALSE)
#define Can_HasSizeOfXIDFC()                                          (TRUE != FALSE)
#define Can_HasSizeOfXIDFE()                                          (TRUE != FALSE)
#define Can_HasTDCR()                                                 (TRUE != FALSE)
#define Can_HasXIDAM()                                                (TRUE != FALSE)
#define Can_HasXIDFC()                                                (TRUE != FALSE)
#define Can_HasFLESAOfXIDFC()                                         (TRUE != FALSE)
#define Can_HasLSEOfXIDFC()                                           (TRUE != FALSE)
#define Can_HasXIDFE()                                                (TRUE != FALSE)
#define Can_HasEIDFE_0OfXIDFE()                                       (TRUE != FALSE)
#define Can_HasEIDFE_1OfXIDFE()                                       (TRUE != FALSE)
#define Can_HaskCanUsedCore()                                         (TRUE != FALSE)
#define Can_HasPCConfig()                                             (TRUE != FALSE)
#define Can_HasActiveSendObjectOfPCConfig()                           (TRUE != FALSE)
#define Can_HasBTPOfPCConfig()                                        (TRUE != FALSE)
#define Can_HasBaseDll_GeneratorVersionOfPCConfig()                   (TRUE != FALSE)
#define Can_HasBufferConfigOfPCConfig()                               (TRUE != FALSE)
#define Can_HasCAN_FD_NISOOfPCConfig()                                (TRUE != FALSE)
#define Can_HasCAN_NUMBER_OF_SRNOfPCConfig()                          (TRUE != FALSE)
#define Can_HasC_ENABLE_MPC5700_MCAN_CREL_SSTEPOfPCConfig()           (TRUE != FALSE)
#define Can_HasC_ENABLE_MPC5700_MCAN_CREL_STEPOfPCConfig()            (TRUE != FALSE)
#define Can_HasC_ENABLE_MPC5700_MCAN_MAJOR_CRELOfPCConfig()           (TRUE != FALSE)
#define Can_HasCanIfChannelIdOfPCConfig()                             (TRUE != FALSE)
#define Can_HasControllerConfigOfPCConfig()                           (TRUE != FALSE)
#define Can_HasControllerDataOfPCConfig()                             (TRUE != FALSE)
#define Can_HasFBTPOfPCConfig()                                       (TRUE != FALSE)
#define Can_HasGFCOfPCConfig()                                        (TRUE != FALSE)
#define Can_HasINT_PriorityOfPCConfig()                               (TRUE != FALSE)
#define Can_HasINT_RoutingGroupOfPCConfig()                           (TRUE != FALSE)
#define Can_HasInitObjectBaudrateOfPCConfig()                         (TRUE != FALSE)
#define Can_HasInitObjectStartIndexOfPCConfig()                       (TRUE != FALSE)
#define Can_HasIsrOsIdOfPCConfig()                                    (TRUE != FALSE)
#define Can_HasMailboxOfPCConfig()                                    (TRUE != FALSE)
#define Can_HasMemorySectionInfoOfPCConfig()                          (TRUE != FALSE)
#define Can_HasMemorySectionObjectsOfPCConfig()                       (TRUE != FALSE)
#define Can_HasPlatformDll_GeneratorVersionOfPCConfig()               (TRUE != FALSE)
#define Can_HasSIDFCOfPCConfig()                                      (TRUE != FALSE)
#define Can_HasSIDFEOfPCConfig()                                      (TRUE != FALSE)
#define Can_HasSRN_AddressOfPCConfig()                                (TRUE != FALSE)
#define Can_HasShmAdrOfPCConfig()                                     (TRUE != FALSE)
#define Can_HasSizeOfActiveSendObjectOfPCConfig()                     (TRUE != FALSE)
#define Can_HasSizeOfBTPOfPCConfig()                                  (TRUE != FALSE)
#define Can_HasSizeOfBufferConfigOfPCConfig()                         (TRUE != FALSE)
#define Can_HasSizeOfCanIfChannelIdOfPCConfig()                       (TRUE != FALSE)
#define Can_HasSizeOfControllerConfigOfPCConfig()                     (TRUE != FALSE)
#define Can_HasSizeOfControllerDataOfPCConfig()                       (TRUE != FALSE)
#define Can_HasSizeOfFBTPOfPCConfig()                                 (TRUE != FALSE)
#define Can_HasSizeOfGFCOfPCConfig()                                  (TRUE != FALSE)
#define Can_HasSizeOfINT_PriorityOfPCConfig()                         (TRUE != FALSE)
#define Can_HasSizeOfINT_RoutingGroupOfPCConfig()                     (TRUE != FALSE)
#define Can_HasSizeOfInitObjectBaudrateOfPCConfig()                   (TRUE != FALSE)
#define Can_HasSizeOfInitObjectStartIndexOfPCConfig()                 (TRUE != FALSE)
#define Can_HasSizeOfIsrOsIdOfPCConfig()                              (TRUE != FALSE)
#define Can_HasSizeOfMailboxOfPCConfig()                              (TRUE != FALSE)
#define Can_HasSizeOfMemorySectionInfoOfPCConfig()                    (TRUE != FALSE)
#define Can_HasSizeOfMemorySectionObjectsOfPCConfig()                 (TRUE != FALSE)
#define Can_HasSizeOfSIDFCOfPCConfig()                                (TRUE != FALSE)
#define Can_HasSizeOfSIDFEOfPCConfig()                                (TRUE != FALSE)
#define Can_HasSizeOfSRN_AddressOfPCConfig()                          (TRUE != FALSE)
#define Can_HasSizeOfShmAdrOfPCConfig()                               (TRUE != FALSE)
#define Can_HasSizeOfTDCROfPCConfig()                                 (TRUE != FALSE)
#define Can_HasSizeOfXIDAMOfPCConfig()                                (TRUE != FALSE)
#define Can_HasSizeOfXIDFCOfPCConfig()                                (TRUE != FALSE)
#define Can_HasSizeOfXIDFEOfPCConfig()                                (TRUE != FALSE)
#define Can_HasTDCROfPCConfig()                                       (TRUE != FALSE)
#define Can_HasXIDAMOfPCConfig()                                      (TRUE != FALSE)
#define Can_HasXIDFCOfPCConfig()                                      (TRUE != FALSE)
#define Can_HasXIDFEOfPCConfig()                                      (TRUE != FALSE)
#define Can_HaskCanUsedCoreOfPCConfig()                               (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  CanPCIncrementDataMacros  Can Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define Can_IncPduOfActiveSendObject(Index)                           Can_GetPduOfActiveSendObject(Index)++
#define Can_IncStateOfActiveSendObject(Index)                         Can_GetStateOfActiveSendObject(Index)++
#define Can_IncBusOffNotificationOfControllerData(Index)              Can_GetBusOffNotificationOfControllerData(Index)++
#define Can_IncBusOffTransitionRequestOfControllerData(Index)         Can_GetBusOffTransitionRequestOfControllerData(Index)++
#define Can_IncCanInterruptCounterOfControllerData(Index)             Can_GetCanInterruptCounterOfControllerData(Index)++
#define Can_IncCanInterruptOldStatusOfControllerData(Index)           Can_GetCanInterruptOldStatusOfControllerData(Index)++
#define Can_IncIntEnableOfControllerData(Index)                       Can_GetIntEnableOfControllerData(Index)++
#define Can_IncLastInitObjectOfControllerData(Index)                  Can_GetLastInitObjectOfControllerData(Index)++
#define Can_IncLastStateOfControllerData(Index)                       Can_GetLastStateOfControllerData(Index)++
#define Can_IncLogStatusOfControllerData(Index)                       Can_GetLogStatusOfControllerData(Index)++
#define Can_IncLoopTimeoutOfControllerData(Index)                     Can_GetLoopTimeoutOfControllerData(Index)++
#define Can_IncModeTransitionRequestOfControllerData(Index)           Can_GetModeTransitionRequestOfControllerData(Index)++
#define Can_IncPrevModeOfControllerData(Index)                        Can_GetPrevModeOfControllerData(Index)++
#define Can_IncRamCheckTransitionRequestOfControllerData(Index)       Can_GetRamCheckTransitionRequestOfControllerData(Index)++
#define Can_IncTXBCROfControllerData(Index)                           Can_GetTXBCROfControllerData(Index)++
#define Can_IncTXBRPOfControllerData(Index)                           Can_GetTXBRPOfControllerData(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  CanPCDecrementDataMacros  Can Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define Can_DecPduOfActiveSendObject(Index)                           Can_GetPduOfActiveSendObject(Index)--
#define Can_DecStateOfActiveSendObject(Index)                         Can_GetStateOfActiveSendObject(Index)--
#define Can_DecBusOffNotificationOfControllerData(Index)              Can_GetBusOffNotificationOfControllerData(Index)--
#define Can_DecBusOffTransitionRequestOfControllerData(Index)         Can_GetBusOffTransitionRequestOfControllerData(Index)--
#define Can_DecCanInterruptCounterOfControllerData(Index)             Can_GetCanInterruptCounterOfControllerData(Index)--
#define Can_DecCanInterruptOldStatusOfControllerData(Index)           Can_GetCanInterruptOldStatusOfControllerData(Index)--
#define Can_DecIntEnableOfControllerData(Index)                       Can_GetIntEnableOfControllerData(Index)--
#define Can_DecLastInitObjectOfControllerData(Index)                  Can_GetLastInitObjectOfControllerData(Index)--
#define Can_DecLastStateOfControllerData(Index)                       Can_GetLastStateOfControllerData(Index)--
#define Can_DecLogStatusOfControllerData(Index)                       Can_GetLogStatusOfControllerData(Index)--
#define Can_DecLoopTimeoutOfControllerData(Index)                     Can_GetLoopTimeoutOfControllerData(Index)--
#define Can_DecModeTransitionRequestOfControllerData(Index)           Can_GetModeTransitionRequestOfControllerData(Index)--
#define Can_DecPrevModeOfControllerData(Index)                        Can_GetPrevModeOfControllerData(Index)--
#define Can_DecRamCheckTransitionRequestOfControllerData(Index)       Can_GetRamCheckTransitionRequestOfControllerData(Index)--
#define Can_DecTXBCROfControllerData(Index)                           Can_GetTXBCROfControllerData(Index)--
#define Can_DecTXBRPOfControllerData(Index)                           Can_GetTXBRPOfControllerData(Index)--
/** 
  \}
*/ 

  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/

/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/

/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CanPCIterableTypes  Can Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate Can_ActiveSendObject */
typedef uint8_least Can_ActiveSendObjectIterType;

/**   \brief  type used to iterate Can_BTP */
typedef uint8_least Can_BTPIterType;

/**   \brief  type used to iterate Can_BufferConfig */
typedef uint8_least Can_BufferConfigIterType;

/**   \brief  type used to iterate Can_CanIfChannelId */
typedef uint8_least Can_CanIfChannelIdIterType;

/**   \brief  type used to iterate Can_ControllerConfig */
typedef uint8_least Can_ControllerConfigIterType;

/**   \brief  type used to iterate Can_FBTP */
typedef uint8_least Can_FBTPIterType;

/**   \brief  type used to iterate Can_GFC */
typedef uint8_least Can_GFCIterType;

/**   \brief  type used to iterate Can_INT_Priority */
typedef uint8_least Can_INT_PriorityIterType;

/**   \brief  type used to iterate Can_INT_RoutingGroup */
typedef uint8_least Can_INT_RoutingGroupIterType;

/**   \brief  type used to iterate Can_InitObjectBaudrate */
typedef uint8_least Can_InitObjectBaudrateIterType;

/**   \brief  type used to iterate Can_InitObjectStartIndex */
typedef uint8_least Can_InitObjectStartIndexIterType;

/**   \brief  type used to iterate Can_IsrOsId */
typedef uint8_least Can_IsrOsIdIterType;

/**   \brief  type used to iterate Can_Mailbox */
typedef uint8_least Can_MailboxIterType;

/**   \brief  type used to iterate Can_MemorySectionInfo */
typedef uint8_least Can_MemorySectionInfoIterType;

/**   \brief  type used to iterate Can_MemorySectionObjects */
typedef uint8_least Can_MemorySectionObjectsIterType;

/**   \brief  type used to iterate Can_SIDFC */
typedef uint8_least Can_SIDFCIterType;

/**   \brief  type used to iterate Can_SIDFE */
typedef uint8_least Can_SIDFEIterType;

/**   \brief  type used to iterate Can_SRN_Address */
typedef uint8_least Can_SRN_AddressIterType;

/**   \brief  type used to iterate Can_ShmAdr */
typedef uint8_least Can_ShmAdrIterType;

/**   \brief  type used to iterate Can_TDCR */
typedef uint8_least Can_TDCRIterType;

/**   \brief  type used to iterate Can_XIDAM */
typedef uint8_least Can_XIDAMIterType;

/**   \brief  type used to iterate Can_XIDFC */
typedef uint8_least Can_XIDFCIterType;

/**   \brief  type used to iterate Can_XIDFE */
typedef uint8_least Can_XIDFEIterType;

/** 
  \}
*/ 

/** 
  \defgroup  CanPCIterableTypesWithSizeRelations  Can Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate Can_ControllerData */
typedef Can_ControllerConfigIterType Can_ControllerDataIterType;

/** 
  \}
*/ 

/** 
  \defgroup  CanPCValueTypes  Can Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for Can_PduOfActiveSendObject */
typedef PduIdType Can_PduOfActiveSendObjectType;

/**   \brief  value based type definition for Can_StateOfActiveSendObject */
typedef uint16 Can_StateOfActiveSendObjectType;

/**   \brief  value based type definition for Can_BTP */
typedef uint32 Can_BTPType;

/**   \brief  value based type definition for Can_BaseDll_GeneratorVersion */
typedef uint16 Can_BaseDll_GeneratorVersionType;

/**   \brief  value based type definition for Can_RXBCOfBufferConfig */
typedef uint8 Can_RXBCOfBufferConfigType;

/**   \brief  value based type definition for Can_RXF0COfBufferConfig */
typedef uint32 Can_RXF0COfBufferConfigType;

/**   \brief  value based type definition for Can_RXF1COfBufferConfig */
typedef uint8 Can_RXF1COfBufferConfigType;

/**   \brief  value based type definition for Can_TXBCOfBufferConfig */
typedef uint32 Can_TXBCOfBufferConfigType;

/**   \brief  value based type definition for Can_TXEFCOfBufferConfig */
typedef uint8 Can_TXEFCOfBufferConfigType;

/**   \brief  value based type definition for Can_CAN_FD_NISO */
typedef uint8 Can_CAN_FD_NISOType;

/**   \brief  value based type definition for Can_CAN_NUMBER_OF_SRN */
typedef uint8 Can_CAN_NUMBER_OF_SRNType;

/**   \brief  value based type definition for Can_C_ENABLE_MPC5700_MCAN_CREL_SSTEP */
typedef uint8 Can_C_ENABLE_MPC5700_MCAN_CREL_SSTEPType;

/**   \brief  value based type definition for Can_C_ENABLE_MPC5700_MCAN_CREL_STEP */
typedef uint8 Can_C_ENABLE_MPC5700_MCAN_CREL_STEPType;

/**   \brief  value based type definition for Can_C_ENABLE_MPC5700_MCAN_MAJOR_CREL */
typedef uint8 Can_C_ENABLE_MPC5700_MCAN_MAJOR_CRELType;

/**   \brief  value based type definition for Can_CanIfChannelId */
typedef uint8 Can_CanIfChannelIdType;

/**   \brief  value based type definition for Can_BasisAdrOfControllerConfig */
typedef uint32 Can_BasisAdrOfControllerConfigType;

/**   \brief  value based type definition for Can_CanControllerDefaultBaudrateIdxOfControllerConfig */
typedef uint8 Can_CanControllerDefaultBaudrateIdxOfControllerConfigType;

/**   \brief  value based type definition for Can_CanControllerDefaultBaudrateOfControllerConfig */
typedef uint16 Can_CanControllerDefaultBaudrateOfControllerConfigType;

/**   \brief  value based type definition for Can_IsTTCanOfControllerConfig */
typedef boolean Can_IsTTCanOfControllerConfigType;

/**   \brief  value based type definition for Can_MailboxRxBasicEndIdxOfControllerConfig */
typedef uint8 Can_MailboxRxBasicEndIdxOfControllerConfigType;

/**   \brief  value based type definition for Can_MailboxRxBasicLengthOfControllerConfig */
typedef uint8 Can_MailboxRxBasicLengthOfControllerConfigType;

/**   \brief  value based type definition for Can_MailboxRxBasicStartIdxOfControllerConfig */
typedef uint8 Can_MailboxRxBasicStartIdxOfControllerConfigType;

/**   \brief  value based type definition for Can_MailboxRxBasicUsedOfControllerConfig */
typedef boolean Can_MailboxRxBasicUsedOfControllerConfigType;

/**   \brief  value based type definition for Can_MailboxTxBasicEndIdxOfControllerConfig */
typedef uint8 Can_MailboxTxBasicEndIdxOfControllerConfigType;

/**   \brief  value based type definition for Can_MailboxTxBasicLengthOfControllerConfig */
typedef uint8 Can_MailboxTxBasicLengthOfControllerConfigType;

/**   \brief  value based type definition for Can_MailboxTxBasicStartIdxOfControllerConfig */
typedef uint8 Can_MailboxTxBasicStartIdxOfControllerConfigType;

/**   \brief  value based type definition for Can_MailboxTxBasicUsedOfControllerConfig */
typedef boolean Can_MailboxTxBasicUsedOfControllerConfigType;

/**   \brief  value based type definition for Can_MailboxUnusedEndIdxOfControllerConfig */
typedef uint8 Can_MailboxUnusedEndIdxOfControllerConfigType;

/**   \brief  value based type definition for Can_MailboxUnusedLengthOfControllerConfig */
typedef uint8 Can_MailboxUnusedLengthOfControllerConfigType;

/**   \brief  value based type definition for Can_MailboxUnusedStartIdxOfControllerConfig */
typedef uint8 Can_MailboxUnusedStartIdxOfControllerConfigType;

/**   \brief  value based type definition for Can_MailboxUnusedUsedOfControllerConfig */
typedef boolean Can_MailboxUnusedUsedOfControllerConfigType;

/**   \brief  value based type definition for Can_RxBasicHwStartOfControllerConfig */
typedef uint8 Can_RxBasicHwStartOfControllerConfigType;

/**   \brief  value based type definition for Can_RxBasicHwStopOfControllerConfig */
typedef uint8 Can_RxBasicHwStopOfControllerConfigType;

/**   \brief  value based type definition for Can_RxFullHwStartOfControllerConfig */
typedef uint8 Can_RxFullHwStartOfControllerConfigType;

/**   \brief  value based type definition for Can_RxFullHwStopOfControllerConfig */
typedef uint8 Can_RxFullHwStopOfControllerConfigType;

/**   \brief  value based type definition for Can_RxSelectionOfControllerConfig */
typedef uint8 Can_RxSelectionOfControllerConfigType;

/**   \brief  value based type definition for Can_TxBasicHwStartOfControllerConfig */
typedef uint8 Can_TxBasicHwStartOfControllerConfigType;

/**   \brief  value based type definition for Can_TxBasicHwStopOfControllerConfig */
typedef uint8 Can_TxBasicHwStopOfControllerConfigType;

/**   \brief  value based type definition for Can_TxFullHwStartOfControllerConfig */
typedef uint8 Can_TxFullHwStartOfControllerConfigType;

/**   \brief  value based type definition for Can_TxFullHwStopOfControllerConfig */
typedef uint8 Can_TxFullHwStopOfControllerConfigType;

/**   \brief  value based type definition for Can_UnusedHwStartOfControllerConfig */
typedef uint8 Can_UnusedHwStartOfControllerConfigType;

/**   \brief  value based type definition for Can_UnusedHwStopOfControllerConfig */
typedef uint8 Can_UnusedHwStopOfControllerConfigType;

/**   \brief  value based type definition for Can_BusOffNotificationOfControllerData */
typedef uint8 Can_BusOffNotificationOfControllerDataType;

/**   \brief  value based type definition for Can_BusOffTransitionRequestOfControllerData */
typedef uint8 Can_BusOffTransitionRequestOfControllerDataType;

/**   \brief  value based type definition for Can_CanInterruptCounterOfControllerData */
typedef uint8 Can_CanInterruptCounterOfControllerDataType;

/**   \brief  value based type definition for Can_IntEnableOfControllerData */
typedef uint32 Can_IntEnableOfControllerDataType;

/**   \brief  value based type definition for Can_IsBusOffOfControllerData */
typedef boolean Can_IsBusOffOfControllerDataType;

/**   \brief  value based type definition for Can_LastInitObjectOfControllerData */
typedef uint8 Can_LastInitObjectOfControllerDataType;

/**   \brief  value based type definition for Can_LastStateOfControllerData */
typedef uint8 Can_LastStateOfControllerDataType;

/**   \brief  value based type definition for Can_LogStatusOfControllerData */
typedef uint8 Can_LogStatusOfControllerDataType;

/**   \brief  value based type definition for Can_ModeTransitionRequestOfControllerData */
typedef uint8 Can_ModeTransitionRequestOfControllerDataType;

/**   \brief  value based type definition for Can_PrevModeOfControllerData */
typedef uint8 Can_PrevModeOfControllerDataType;

/**   \brief  value based type definition for Can_RamCheckTransitionRequestOfControllerData */
typedef uint8 Can_RamCheckTransitionRequestOfControllerDataType;

/**   \brief  value based type definition for Can_TXBCROfControllerData */
typedef uint32 Can_TXBCROfControllerDataType;

/**   \brief  value based type definition for Can_TXBRPOfControllerData */
typedef uint32 Can_TXBRPOfControllerDataType;

/**   \brief  value based type definition for Can_FBTP */
typedef uint8 Can_FBTPType;

/**   \brief  value based type definition for Can_GFC */
typedef uint8 Can_GFCType;

/**   \brief  value based type definition for Can_INT_Priority */
typedef uint8 Can_INT_PriorityType;

/**   \brief  value based type definition for Can_INT_RoutingGroup */
typedef uint8 Can_INT_RoutingGroupType;

/**   \brief  value based type definition for Can_InitObjectBaudrate */
typedef uint16 Can_InitObjectBaudrateType;

/**   \brief  value based type definition for Can_InitObjectStartIndex */
typedef uint8 Can_InitObjectStartIndexType;

/**   \brief  value based type definition for Can_ActiveSendObjectOfMailbox */
typedef uint8 Can_ActiveSendObjectOfMailboxType;

/**   \brief  value based type definition for Can_ControllerConfigIdxOfMailbox */
typedef uint8 Can_ControllerConfigIdxOfMailboxType;

/**   \brief  value based type definition for Can_HwHandleOfMailbox */
typedef uint8 Can_HwHandleOfMailboxType;

/**   \brief  value based type definition for Can_IDValueOfMailbox */
typedef uint8 Can_IDValueOfMailboxType;

/**   \brief  value based type definition for Can_MailboxSizeOfMailbox */
typedef uint8 Can_MailboxSizeOfMailboxType;

/**   \brief  value based type definition for Can_MailboxTypeOfMailbox */
typedef uint8 Can_MailboxTypeOfMailboxType;

/**   \brief  value based type definition for Can_MaxDataLenOfMailbox */
typedef uint8 Can_MaxDataLenOfMailboxType;

/**   \brief  value based type definition for Can_MemorySectionsIndexOfMailbox */
typedef uint8 Can_MemorySectionsIndexOfMailboxType;

/**   \brief  value based type definition for Can_MemorySectionStartOfMemorySectionInfo */
typedef uint8 Can_MemorySectionStartOfMemorySectionInfoType;

/**   \brief  value based type definition for Can_HwHandleOfMemorySectionObjects */
typedef uint8 Can_HwHandleOfMemorySectionObjectsType;

/**   \brief  value based type definition for Can_MailboxElementOfMemorySectionObjects */
typedef uint8 Can_MailboxElementOfMemorySectionObjectsType;

/**   \brief  value based type definition for Can_MailboxHandleOfMemorySectionObjects */
typedef uint8 Can_MailboxHandleOfMemorySectionObjectsType;

/**   \brief  value based type definition for Can_PlatformDll_GeneratorVersion */
typedef uint16 Can_PlatformDll_GeneratorVersionType;

/**   \brief  value based type definition for Can_FLSSAOfSIDFC */
typedef uint8 Can_FLSSAOfSIDFCType;

/**   \brief  value based type definition for Can_LSSOfSIDFC */
typedef uint8 Can_LSSOfSIDFCType;

/**   \brief  value based type definition for Can_SIDFEEndIdxOfSIDFC */
typedef uint8 Can_SIDFEEndIdxOfSIDFCType;

/**   \brief  value based type definition for Can_SIDFEStartIdxOfSIDFC */
typedef uint8 Can_SIDFEStartIdxOfSIDFCType;

/**   \brief  value based type definition for Can_SIDFEUsedOfSIDFC */
typedef boolean Can_SIDFEUsedOfSIDFCType;

/**   \brief  value based type definition for Can_SIDFE */
typedef uint32 Can_SIDFEType;

/**   \brief  value based type definition for Can_SRN_Address */
typedef uint32 Can_SRN_AddressType;

/**   \brief  value based type definition for Can_RXBAOfShmAdr */
typedef uint32 Can_RXBAOfShmAdrType;

/**   \brief  value based type definition for Can_RXF0AOfShmAdr */
typedef uint32 Can_RXF0AOfShmAdrType;

/**   \brief  value based type definition for Can_RXF1AOfShmAdr */
typedef uint32 Can_RXF1AOfShmAdrType;

/**   \brief  value based type definition for Can_SIDFAOfShmAdr */
typedef uint32 Can_SIDFAOfShmAdrType;

/**   \brief  value based type definition for Can_StartAdrOfShmAdr */
typedef uint32 Can_StartAdrOfShmAdrType;

/**   \brief  value based type definition for Can_StopAdrOfShmAdr */
typedef uint32 Can_StopAdrOfShmAdrType;

/**   \brief  value based type definition for Can_TXBAOfShmAdr */
typedef uint32 Can_TXBAOfShmAdrType;

/**   \brief  value based type definition for Can_TXEFAOfShmAdr */
typedef uint32 Can_TXEFAOfShmAdrType;

/**   \brief  value based type definition for Can_XIDFAOfShmAdr */
typedef uint32 Can_XIDFAOfShmAdrType;

/**   \brief  value based type definition for Can_SizeOfActiveSendObject */
typedef uint8 Can_SizeOfActiveSendObjectType;

/**   \brief  value based type definition for Can_SizeOfBTP */
typedef uint8 Can_SizeOfBTPType;

/**   \brief  value based type definition for Can_SizeOfBufferConfig */
typedef uint8 Can_SizeOfBufferConfigType;

/**   \brief  value based type definition for Can_SizeOfCanIfChannelId */
typedef uint8 Can_SizeOfCanIfChannelIdType;

/**   \brief  value based type definition for Can_SizeOfControllerConfig */
typedef uint8 Can_SizeOfControllerConfigType;

/**   \brief  value based type definition for Can_SizeOfControllerData */
typedef uint8 Can_SizeOfControllerDataType;

/**   \brief  value based type definition for Can_SizeOfFBTP */
typedef uint8 Can_SizeOfFBTPType;

/**   \brief  value based type definition for Can_SizeOfGFC */
typedef uint8 Can_SizeOfGFCType;

/**   \brief  value based type definition for Can_SizeOfINT_Priority */
typedef uint8 Can_SizeOfINT_PriorityType;

/**   \brief  value based type definition for Can_SizeOfINT_RoutingGroup */
typedef uint8 Can_SizeOfINT_RoutingGroupType;

/**   \brief  value based type definition for Can_SizeOfInitObjectBaudrate */
typedef uint8 Can_SizeOfInitObjectBaudrateType;

/**   \brief  value based type definition for Can_SizeOfInitObjectStartIndex */
typedef uint8 Can_SizeOfInitObjectStartIndexType;

/**   \brief  value based type definition for Can_SizeOfIsrOsId */
typedef uint8 Can_SizeOfIsrOsIdType;

/**   \brief  value based type definition for Can_SizeOfMailbox */
typedef uint8 Can_SizeOfMailboxType;

/**   \brief  value based type definition for Can_SizeOfMemorySectionInfo */
typedef uint8 Can_SizeOfMemorySectionInfoType;

/**   \brief  value based type definition for Can_SizeOfMemorySectionObjects */
typedef uint8 Can_SizeOfMemorySectionObjectsType;

/**   \brief  value based type definition for Can_SizeOfSIDFC */
typedef uint8 Can_SizeOfSIDFCType;

/**   \brief  value based type definition for Can_SizeOfSIDFE */
typedef uint8 Can_SizeOfSIDFEType;

/**   \brief  value based type definition for Can_SizeOfSRN_Address */
typedef uint8 Can_SizeOfSRN_AddressType;

/**   \brief  value based type definition for Can_SizeOfShmAdr */
typedef uint8 Can_SizeOfShmAdrType;

/**   \brief  value based type definition for Can_SizeOfTDCR */
typedef uint8 Can_SizeOfTDCRType;

/**   \brief  value based type definition for Can_SizeOfXIDAM */
typedef uint8 Can_SizeOfXIDAMType;

/**   \brief  value based type definition for Can_SizeOfXIDFC */
typedef uint8 Can_SizeOfXIDFCType;

/**   \brief  value based type definition for Can_SizeOfXIDFE */
typedef uint8 Can_SizeOfXIDFEType;

/**   \brief  value based type definition for Can_TDCR */
typedef uint8 Can_TDCRType;

/**   \brief  value based type definition for Can_XIDAM */
typedef uint32 Can_XIDAMType;

/**   \brief  value based type definition for Can_FLESAOfXIDFC */
typedef uint8 Can_FLESAOfXIDFCType;

/**   \brief  value based type definition for Can_LSEOfXIDFC */
typedef uint8 Can_LSEOfXIDFCType;

/**   \brief  value based type definition for Can_EIDFE_0OfXIDFE */
typedef uint8 Can_EIDFE_0OfXIDFEType;

/**   \brief  value based type definition for Can_EIDFE_1OfXIDFE */
typedef uint8 Can_EIDFE_1OfXIDFEType;

/**   \brief  value based type definition for Can_kCanUsedCore */
typedef uint8 Can_kCanUsedCoreType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CanPCStructTypes  Can Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in Can_ActiveSendObject */
typedef struct sCan_ActiveSendObjectType
{
  Can_StateOfActiveSendObjectType StateOfActiveSendObject;  /**< send state like cancelled or send activ */
  Can_PduOfActiveSendObjectType PduOfActiveSendObject;  /**< buffered PduId for confirmation or cancellation */
} Can_ActiveSendObjectType;

/**   \brief  type used in Can_BufferConfig */
typedef struct sCan_BufferConfigType
{
  Can_RXF0COfBufferConfigType RXF0COfBufferConfig;
  Can_TXBCOfBufferConfigType TXBCOfBufferConfig;
  Can_RXBCOfBufferConfigType RXBCOfBufferConfig;
  Can_RXF1COfBufferConfigType RXF1COfBufferConfig;
  Can_TXEFCOfBufferConfigType TXEFCOfBufferConfig;
} Can_BufferConfigType;

/**   \brief  type used in Can_ControllerConfig */
typedef struct sCan_ControllerConfigType
{
  Can_BasisAdrOfControllerConfigType BasisAdrOfControllerConfig;  /**< CAN channel base address */
  Can_CanControllerDefaultBaudrateOfControllerConfigType CanControllerDefaultBaudrateOfControllerConfig;
  Can_IsTTCanOfControllerConfigType IsTTCanOfControllerConfig;  /**< TTCAN channel support */
  Can_CanControllerDefaultBaudrateIdxOfControllerConfigType CanControllerDefaultBaudrateIdxOfControllerConfig;
  Can_MailboxRxBasicEndIdxOfControllerConfigType MailboxRxBasicEndIdxOfControllerConfig;  /**< the end index of the 0:n relation pointing to Can_Mailbox */
  Can_MailboxRxBasicLengthOfControllerConfigType MailboxRxBasicLengthOfControllerConfig;  /**< the number of relations pointing to Can_Mailbox */
  Can_MailboxRxBasicStartIdxOfControllerConfigType MailboxRxBasicStartIdxOfControllerConfig;  /**< the start index of the 0:n relation pointing to Can_Mailbox */
  Can_MailboxTxBasicEndIdxOfControllerConfigType MailboxTxBasicEndIdxOfControllerConfig;  /**< the end index of the 0:n relation pointing to Can_Mailbox */
  Can_MailboxTxBasicLengthOfControllerConfigType MailboxTxBasicLengthOfControllerConfig;  /**< the number of relations pointing to Can_Mailbox */
  Can_MailboxTxBasicStartIdxOfControllerConfigType MailboxTxBasicStartIdxOfControllerConfig;  /**< the start index of the 0:n relation pointing to Can_Mailbox */
  Can_MailboxUnusedEndIdxOfControllerConfigType MailboxUnusedEndIdxOfControllerConfig;  /**< the end index of the 0:n relation pointing to Can_Mailbox */
  Can_MailboxUnusedLengthOfControllerConfigType MailboxUnusedLengthOfControllerConfig;  /**< the number of relations pointing to Can_Mailbox */
  Can_MailboxUnusedStartIdxOfControllerConfigType MailboxUnusedStartIdxOfControllerConfig;  /**< the start index of the 0:n relation pointing to Can_Mailbox */
  Can_RxBasicHwStartOfControllerConfigType RxBasicHwStartOfControllerConfig;
  Can_RxBasicHwStopOfControllerConfigType RxBasicHwStopOfControllerConfig;
  Can_RxFullHwStartOfControllerConfigType RxFullHwStartOfControllerConfig;
  Can_RxFullHwStopOfControllerConfigType RxFullHwStopOfControllerConfig;
  Can_RxSelectionOfControllerConfigType RxSelectionOfControllerConfig;  /**< CAN Rx Selection */
  Can_TxBasicHwStartOfControllerConfigType TxBasicHwStartOfControllerConfig;
  Can_TxBasicHwStopOfControllerConfigType TxBasicHwStopOfControllerConfig;
  Can_TxFullHwStartOfControllerConfigType TxFullHwStartOfControllerConfig;
  Can_TxFullHwStopOfControllerConfigType TxFullHwStopOfControllerConfig;
  Can_UnusedHwStartOfControllerConfigType UnusedHwStartOfControllerConfig;
  Can_UnusedHwStopOfControllerConfigType UnusedHwStopOfControllerConfig;
} Can_ControllerConfigType;

/**   \brief  type used in Can_ControllerData */
typedef struct sCan_ControllerDataType
{
  Can_IntEnableOfControllerDataType IntEnableOfControllerData;  /**< CAN Interrupt Enable state for each controller */
  Can_TXBCROfControllerDataType TXBCROfControllerData;  /**< CAN Tx Buffer Cancellation Request for each controller */
  Can_TXBRPOfControllerDataType TXBRPOfControllerData;  /**< CAN Tx Buffer request Pending for each controller */
  Can_BusOffNotificationOfControllerDataType BusOffNotificationOfControllerData;  /**< CAN state for each controller: busoff occur */
  Can_BusOffTransitionRequestOfControllerDataType BusOffTransitionRequestOfControllerData;  /**< CAN state request for each controller: ContinueBusOffRecovery=0x00, FinishBusOffRecovery=0x01 */
  Can_CanInterruptCounterOfControllerDataType CanInterruptCounterOfControllerData;  /**< CAN interrupt disable counter for each controller */
  Can_IsBusOffOfControllerDataType IsBusOffOfControllerData;  /**< CAN state for each controller: busoff occur */
  Can_LastInitObjectOfControllerDataType LastInitObjectOfControllerData;  /**< last set baudrate for reinit */
  Can_LastStateOfControllerDataType LastStateOfControllerData;  /**< CAN mode transition request status for each controller */
  Can_LogStatusOfControllerDataType LogStatusOfControllerData;  /**< CAN state for each controller: UNINIT=0x00, START=0x01, STOP=0x02, INIT=0x04, INCONSISTENT=0x08, WARNING =0x10, PASSIVE=0x20, BUSOFF=0x40, SLEEP=0x80 */
  Can_ModeTransitionRequestOfControllerDataType ModeTransitionRequestOfControllerData;  /**< CAN state request for each controller: INIT=0x00, SLEEP=0x01, WAKEUP=0x02, STOP+INIT=0x03, START=0x04, START+INIT=0x05, NONE=0x06 */
  Can_PrevModeOfControllerDataType PrevModeOfControllerData;  /**< CAN mode transition request for each controller */
  Can_RamCheckTransitionRequestOfControllerDataType RamCheckTransitionRequestOfControllerData;  /**< CAN state request for each controller: kCanSuppressRamCheck=0x01, kCanExecuteRamCheck=0x00 */
  tCanLLCanIntOld CanInterruptOldStatusOfControllerData;  /**< last CAN interrupt status for restore interrupt for each controller */
  Can_LoopTimeout_dim_type LoopTimeoutOfControllerData;  /**< hw loop timeout for each controller */
} Can_ControllerDataType;

/**   \brief  type used in Can_Mailbox */
typedef struct sCan_MailboxType
{
  Can_ActiveSendObjectOfMailboxType ActiveSendObjectOfMailbox;
  Can_ControllerConfigIdxOfMailboxType ControllerConfigIdxOfMailbox;  /**< the index of the 1:1 relation pointing to Can_ControllerConfig */
  Can_HwHandleOfMailboxType HwHandleOfMailbox;
  Can_IDValueOfMailboxType IDValueOfMailbox;
  Can_MailboxSizeOfMailboxType MailboxSizeOfMailbox;
  Can_MailboxTypeOfMailboxType MailboxTypeOfMailbox;
  Can_MaxDataLenOfMailboxType MaxDataLenOfMailbox;
  Can_MemorySectionsIndexOfMailboxType MemorySectionsIndexOfMailbox;
} Can_MailboxType;

/**   \brief  type used in Can_MemorySectionInfo */
typedef struct sCan_MemorySectionInfoType
{
  Can_MemorySectionStartOfMemorySectionInfoType MemorySectionStartOfMemorySectionInfo;
} Can_MemorySectionInfoType;

/**   \brief  type used in Can_MemorySectionObjects */
typedef struct sCan_MemorySectionObjectsType
{
  Can_HwHandleOfMemorySectionObjectsType HwHandleOfMemorySectionObjects;
  Can_MailboxElementOfMemorySectionObjectsType MailboxElementOfMemorySectionObjects;
  Can_MailboxHandleOfMemorySectionObjectsType MailboxHandleOfMemorySectionObjects;
} Can_MemorySectionObjectsType;

/**   \brief  type used in Can_SIDFC */
typedef struct sCan_SIDFCType
{
  Can_FLSSAOfSIDFCType FLSSAOfSIDFC;  /**< Filter List Standard Start Address */
  Can_LSSOfSIDFCType LSSOfSIDFC;  /**< List size standard */
  Can_SIDFEEndIdxOfSIDFCType SIDFEEndIdxOfSIDFC;  /**< the end index of the 0:n relation pointing to Can_SIDFE */
  Can_SIDFEStartIdxOfSIDFCType SIDFEStartIdxOfSIDFC;  /**< the start index of the 0:n relation pointing to Can_SIDFE */
} Can_SIDFCType;

/**   \brief  type used in Can_ShmAdr */
typedef struct sCan_ShmAdrType
{
  Can_RXBAOfShmAdrType RXBAOfShmAdr;  /**< RX Buffer Address */
  Can_RXF0AOfShmAdrType RXF0AOfShmAdr;  /**< RX FIFO0 Address */
  Can_RXF1AOfShmAdrType RXF1AOfShmAdr;  /**< RX FIFO1 Address */
  Can_SIDFAOfShmAdrType SIDFAOfShmAdr;  /**< Standard Filters Address */
  Can_StartAdrOfShmAdrType StartAdrOfShmAdr;  /**< Start address of the shared memory area */
  Can_StopAdrOfShmAdrType StopAdrOfShmAdr;  /**< Stop address of the shared memory area */
  Can_TXBAOfShmAdrType TXBAOfShmAdr;  /**< TX Buffer address */
  Can_TXEFAOfShmAdrType TXEFAOfShmAdr;  /**< TX Event FIFO address */
  Can_XIDFAOfShmAdrType XIDFAOfShmAdr;  /**< Extended Filters Address */
} Can_ShmAdrType;

/**   \brief  type used in Can_XIDFC */
typedef struct sCan_XIDFCType
{
  Can_FLESAOfXIDFCType FLESAOfXIDFC;  /**< Filter List Extended Start Address */
  Can_LSEOfXIDFCType LSEOfXIDFC;  /**< List size extended */
} Can_XIDFCType;

/**   \brief  type used in Can_XIDFE */
typedef struct sCan_XIDFEType
{
  Can_EIDFE_0OfXIDFEType EIDFE_0OfXIDFE;
  Can_EIDFE_1OfXIDFEType EIDFE_1OfXIDFE;
} Can_XIDFEType;

/** 
  \}
*/ 

/** 
  \defgroup  CanPCRootPointerTypes  Can Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to Can_ActiveSendObject */
typedef P2VAR(Can_ActiveSendObjectType, TYPEDEF, CAN_VAR_NOINIT) Can_ActiveSendObjectPtrType;

/**   \brief  type used to point to Can_BTP */
typedef P2CONST(Can_BTPType, TYPEDEF, CAN_CONST) Can_BTPPtrType;

/**   \brief  type used to point to Can_BufferConfig */
typedef P2CONST(Can_BufferConfigType, TYPEDEF, CAN_CONST) Can_BufferConfigPtrType;

/**   \brief  type used to point to Can_CanIfChannelId */
typedef P2CONST(Can_CanIfChannelIdType, TYPEDEF, CAN_CONST) Can_CanIfChannelIdPtrType;

/**   \brief  type used to point to Can_ControllerConfig */
typedef P2CONST(Can_ControllerConfigType, TYPEDEF, CAN_CONST) Can_ControllerConfigPtrType;

/**   \brief  type used to point to Can_ControllerData */
typedef P2VAR(Can_ControllerDataType, TYPEDEF, CAN_VAR_NOINIT) Can_ControllerDataPtrType;

/**   \brief  type used to point to Can_FBTP */
typedef P2CONST(Can_FBTPType, TYPEDEF, CAN_CONST) Can_FBTPPtrType;

/**   \brief  type used to point to Can_GFC */
typedef P2CONST(Can_GFCType, TYPEDEF, CAN_CONST) Can_GFCPtrType;

/**   \brief  type used to point to Can_INT_Priority */
typedef P2CONST(Can_INT_PriorityType, TYPEDEF, CAN_CONST) Can_INT_PriorityPtrType;

/**   \brief  type used to point to Can_INT_RoutingGroup */
typedef P2CONST(Can_INT_RoutingGroupType, TYPEDEF, CAN_CONST) Can_INT_RoutingGroupPtrType;

/**   \brief  type used to point to Can_InitObjectBaudrate */
typedef P2CONST(Can_InitObjectBaudrateType, TYPEDEF, CAN_CONST) Can_InitObjectBaudratePtrType;

/**   \brief  type used to point to Can_InitObjectStartIndex */
typedef P2CONST(Can_InitObjectStartIndexType, TYPEDEF, CAN_CONST) Can_InitObjectStartIndexPtrType;

/**   \brief  type used to point to Can_IsrOsId */
typedef P2CONST(Can_OsIsrType, TYPEDEF, CAN_CONST) Can_IsrOsIdPtrType;

/**   \brief  type used to point to Can_Mailbox */
typedef P2CONST(Can_MailboxType, TYPEDEF, CAN_CONST) Can_MailboxPtrType;

/**   \brief  type used to point to Can_MemorySectionInfo */
typedef P2CONST(Can_MemorySectionInfoType, TYPEDEF, CAN_CONST) Can_MemorySectionInfoPtrType;

/**   \brief  type used to point to Can_MemorySectionObjects */
typedef P2CONST(Can_MemorySectionObjectsType, TYPEDEF, CAN_CONST) Can_MemorySectionObjectsPtrType;

/**   \brief  type used to point to Can_SIDFC */
typedef P2CONST(Can_SIDFCType, TYPEDEF, CAN_CONST) Can_SIDFCPtrType;

/**   \brief  type used to point to Can_SIDFE */
typedef P2CONST(Can_SIDFEType, TYPEDEF, CAN_CONST) Can_SIDFEPtrType;

/**   \brief  type used to point to Can_SRN_Address */
typedef P2CONST(Can_SRN_AddressType, TYPEDEF, CAN_CONST) Can_SRN_AddressPtrType;

/**   \brief  type used to point to Can_ShmAdr */
typedef P2CONST(Can_ShmAdrType, TYPEDEF, CAN_CONST) Can_ShmAdrPtrType;

/**   \brief  type used to point to Can_TDCR */
typedef P2CONST(Can_TDCRType, TYPEDEF, CAN_CONST) Can_TDCRPtrType;

/**   \brief  type used to point to Can_XIDAM */
typedef P2CONST(Can_XIDAMType, TYPEDEF, CAN_CONST) Can_XIDAMPtrType;

/**   \brief  type used to point to Can_XIDFC */
typedef P2CONST(Can_XIDFCType, TYPEDEF, CAN_CONST) Can_XIDFCPtrType;

/**   \brief  type used to point to Can_XIDFE */
typedef P2CONST(Can_XIDFEType, TYPEDEF, CAN_CONST) Can_XIDFEPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  CanPCRootValueTypes  Can Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in Can_PCConfig */
typedef struct sCan_PCConfigType
{
  uint8 Can_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Can_PCConfigType;

typedef Can_PCConfigType Can_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  Can_BTP
**********************************************************************************************************************/
/** 
  \var    Can_BTP
  \brief  Bit Timing and Prescaler
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_BTPType, CAN_CONST) Can_BTP[1];
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_BufferConfig
**********************************************************************************************************************/
/** 
  \var    Can_BufferConfig
  \brief  CAN Buffer Configuration
  \details
  Element    Description
  RXF0C  
  TXBC   
  RXBC   
  RXF1C  
  TXEFC  
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_BufferConfigType, CAN_CONST) Can_BufferConfig[1];
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_CanIfChannelId
**********************************************************************************************************************/
/** 
  \var    Can_CanIfChannelId
  \brief  indirection table Can to CanIf controller ID
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_CanIfChannelIdType, CAN_CONST) Can_CanIfChannelId[1];
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_ControllerConfig
**********************************************************************************************************************/
/** 
  \var    Can_ControllerConfig
  \brief  Global configuration for all controllers
  \details
  Element                            Description
  BasisAdr                           CAN channel base address
  CanControllerDefaultBaudrate   
  IsTTCan                            TTCAN channel support
  CanControllerDefaultBaudrateIdx
  MailboxRxBasicEndIdx               the end index of the 0:n relation pointing to Can_Mailbox
  MailboxRxBasicLength               the number of relations pointing to Can_Mailbox
  MailboxRxBasicStartIdx             the start index of the 0:n relation pointing to Can_Mailbox
  MailboxTxBasicEndIdx               the end index of the 0:n relation pointing to Can_Mailbox
  MailboxTxBasicLength               the number of relations pointing to Can_Mailbox
  MailboxTxBasicStartIdx             the start index of the 0:n relation pointing to Can_Mailbox
  MailboxUnusedEndIdx                the end index of the 0:n relation pointing to Can_Mailbox
  MailboxUnusedLength                the number of relations pointing to Can_Mailbox
  MailboxUnusedStartIdx              the start index of the 0:n relation pointing to Can_Mailbox
  RxBasicHwStart                 
  RxBasicHwStop                  
  RxFullHwStart                  
  RxFullHwStop                   
  RxSelection                        CAN Rx Selection
  TxBasicHwStart                 
  TxBasicHwStop                  
  TxFullHwStart                  
  TxFullHwStop                   
  UnusedHwStart                  
  UnusedHwStop                   
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_ControllerConfigType, CAN_CONST) Can_ControllerConfig[1];
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_FBTP
**********************************************************************************************************************/
/** 
  \var    Can_FBTP
  \brief  Fast Bit Timing and Prescaler
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_FBTPType, CAN_CONST) Can_FBTP[1];
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_GFC
**********************************************************************************************************************/
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_GFCType, CAN_CONST) Can_GFC[1];
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_INT_Priority
**********************************************************************************************************************/
/** 
  \var    Can_INT_Priority
  \brief  Interrupt Priority
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_INT_PriorityType, CAN_CONST) Can_INT_Priority[1];
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_INT_RoutingGroup
**********************************************************************************************************************/
/** 
  \var    Can_INT_RoutingGroup
  \brief  Interrupt routing for Groups
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_INT_RoutingGroupType, CAN_CONST) Can_INT_RoutingGroup[1];
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitObjectBaudrate
**********************************************************************************************************************/
/** 
  \var    Can_InitObjectBaudrate
  \brief  baudrates ('InitStruct' as index)
*/ 
#define CAN_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_InitObjectBaudrateType, CAN_CONST) Can_InitObjectBaudrate[1];
#define CAN_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitObjectStartIndex
**********************************************************************************************************************/
/** 
  \var    Can_InitObjectStartIndex
  \brief  Start index of 'InitStruct' / baudratesets (controllers as index)
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_InitObjectStartIndexType, CAN_CONST) Can_InitObjectStartIndex[2];
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_IsrOsId
**********************************************************************************************************************/
/** 
  \var    Can_IsrOsId
  \brief  OS Symbolic Name Value for Service Request Nodes.
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_OsIsrType, CAN_CONST) Can_IsrOsId[1];
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_Mailbox
**********************************************************************************************************************/
/** 
  \var    Can_Mailbox
  \brief  mailbox configuration (over all controllers)
  \details
  Element                Description
  ActiveSendObject   
  ControllerConfigIdx    the index of the 1:1 relation pointing to Can_ControllerConfig
  HwHandle           
  IDValue            
  MailboxSize        
  MailboxType        
  MaxDataLen         
  MemorySectionsIndex
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_MailboxType, CAN_CONST) Can_Mailbox[3];
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_MemorySectionInfo
**********************************************************************************************************************/
/** 
  \var    Can_MemorySectionInfo
  \brief  Memory section description
  \details
  Element               Description
  MemorySectionStart
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_MemorySectionInfoType, CAN_CONST) Can_MemorySectionInfo[1];
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_MemorySectionObjects
**********************************************************************************************************************/
/** 
  \var    Can_MemorySectionObjects
  \brief  Memory section objects description
  \details
  Element           Description
  HwHandle      
  MailboxElement
  MailboxHandle 
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_MemorySectionObjectsType, CAN_CONST) Can_MemorySectionObjects[2];
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_SIDFC
**********************************************************************************************************************/
/** 
  \var    Can_SIDFC
  \brief  Standard ID filter configuration
  \details
  Element          Description
  FLSSA            Filter List Standard Start Address
  LSS              List size standard
  SIDFEEndIdx      the end index of the 0:n relation pointing to Can_SIDFE
  SIDFEStartIdx    the start index of the 0:n relation pointing to Can_SIDFE
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_SIDFCType, CAN_CONST) Can_SIDFC[1];
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_SIDFE
**********************************************************************************************************************/
/** 
  \var    Can_SIDFE
  \brief  Standard ID filters
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_SIDFEType, CAN_CONST) Can_SIDFE[1];
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_SRN_Address
**********************************************************************************************************************/
/** 
  \var    Can_SRN_Address
  \brief  Service Request Node Addresses
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_SRN_AddressType, CAN_CONST) Can_SRN_Address[1];
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_ShmAdr
**********************************************************************************************************************/
/** 
  \var    Can_ShmAdr
  \brief  CAN Shared Message RAM configuration
  \details
  Element     Description
  RXBA        RX Buffer Address
  RXF0A       RX FIFO0 Address
  RXF1A       RX FIFO1 Address
  SIDFA       Standard Filters Address
  StartAdr    Start address of the shared memory area
  StopAdr     Stop address of the shared memory area
  TXBA        TX Buffer address
  TXEFA       TX Event FIFO address
  XIDFA       Extended Filters Address
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_ShmAdrType, CAN_CONST) Can_ShmAdr[1];
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_TDCR
**********************************************************************************************************************/
/** 
  \var    Can_TDCR
  \brief  Transmitter Delay Compensation
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_TDCRType, CAN_CONST) Can_TDCR[1];
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_XIDAM
**********************************************************************************************************************/
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_XIDAMType, CAN_CONST) Can_XIDAM[1];
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_XIDFC
**********************************************************************************************************************/
/** 
  \var    Can_XIDFC
  \brief  Extended ID filter configuration
  \details
  Element    Description
  FLESA      Filter List Extended Start Address
  LSE        List size extended
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_XIDFCType, CAN_CONST) Can_XIDFC[1];
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_XIDFE
**********************************************************************************************************************/
/** 
  \var    Can_XIDFE
  \brief  Extended ID filters
  \details
  Element    Description
  EIDFE_0
  EIDFE_1
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Can_XIDFEType, CAN_CONST) Can_XIDFE[1];
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_ActiveSendObject
**********************************************************************************************************************/
/** 
  \var    Can_ActiveSendObject
  \brief  temporary data for TX object
  \details
  Element    Description
  State      send state like cancelled or send activ
  Pdu        buffered PduId for confirmation or cancellation
*/ 
#define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Can_ActiveSendObjectType, CAN_VAR_NOINIT) Can_ActiveSendObject[1];
#define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_ControllerData
**********************************************************************************************************************/
/** 
  \var    Can_ControllerData
  \brief  struct for all controller related variable data
  \details
  Element                      Description
  IntEnable                    CAN Interrupt Enable state for each controller
  TXBCR                        CAN Tx Buffer Cancellation Request for each controller
  TXBRP                        CAN Tx Buffer request Pending for each controller
  BusOffNotification           CAN state for each controller: busoff occur
  BusOffTransitionRequest      CAN state request for each controller: ContinueBusOffRecovery=0x00, FinishBusOffRecovery=0x01
  CanInterruptCounter          CAN interrupt disable counter for each controller
  IsBusOff                     CAN state for each controller: busoff occur
  LastInitObject               last set baudrate for reinit
  LastState                    CAN mode transition request status for each controller
  LogStatus                    CAN state for each controller: UNINIT=0x00, START=0x01, STOP=0x02, INIT=0x04, INCONSISTENT=0x08, WARNING =0x10, PASSIVE=0x20, BUSOFF=0x40, SLEEP=0x80
  ModeTransitionRequest        CAN state request for each controller: INIT=0x00, SLEEP=0x01, WAKEUP=0x02, STOP+INIT=0x03, START=0x04, START+INIT=0x05, NONE=0x06
  PrevMode                     CAN mode transition request for each controller
  RamCheckTransitionRequest    CAN state request for each controller: kCanSuppressRamCheck=0x01, kCanExecuteRamCheck=0x00
  CanInterruptOldStatus        last CAN interrupt status for restore interrupt for each controller
  LoopTimeout                  hw loop timeout for each controller
*/ 
#define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Can_ControllerDataType, CAN_VAR_NOINIT) Can_ControllerData[1];
#define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/* -----------------------------------------------------------------------------
    UserConfigFile
 ----------------------------------------------------------------------------- */
/* User Config File Start */

/* User Config File End */



#endif  /* CAN_CFG_H */
/**********************************************************************************************************************
  END OF FILE: Can_Cfg.h
**********************************************************************************************************************/
 

