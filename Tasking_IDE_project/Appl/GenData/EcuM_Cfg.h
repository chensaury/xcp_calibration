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
 *            Module: EcuM
 *           Program: MSR_Vector_SLP4
 *          Customer: Aptiv (China) Technology Company Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Aurix 2G/TC397 B-Step
 *    License Scope : The usage is restricted to CBD1900078_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: EcuM_Cfg.h
 *   Generation Time: 2023-03-21 20:44:22
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


#if !defined(ECUM_CFG_H)
#define ECUM_CFG_H

/**********************************************************************************************************************
 *  PRE-COMPILE Switches
 *********************************************************************************************************************/
/* pre-compile switches for EcuM configuration and services */
#ifndef ECUM_DEV_ERROR_DETECT
#define ECUM_DEV_ERROR_DETECT STD_ON
#endif
#ifndef ECUM_DEV_ERROR_REPORT
#define ECUM_DEV_ERROR_REPORT STD_ON
#endif

# define ECUM_DEFERRED_BSWM_NOTIFICATION                              (STD_OFF)
# define ECUM_NONCHANNEL_WAKEUP_RUN                                   (STD_OFF)
# define ECUM_SLAVE_CORE_HANDLING                                     (STD_ON)
# define ECUM_BSW_ERROR_HOOK                                          (STD_ON)


/* pre-compile switches for module API */
# define ECUM_VERSION_INFO_API                                        (STD_OFF)

/* pre-compile switches for the EcuMFlex Behavior */ 
# define ECUM_ENABLE_DEF_BEHAVIOR                                     (STD_OFF)
# define ECUM_RESET_LOOP_DETECTION                                    (STD_OFF)
# define ECUM_ALARM_CLOCK_PRESENT                                     (STD_OFF)
# define ECUM_MODE_HANDLING                                           (STD_OFF)



/* pre-compile switches for the EcuMFixed Behavior */
# define ECUM_FIXED_BEHAVIOR                                          (STD_OFF)
# define ECUM_SUPPORT_RTE                                             (STD_OFF)
# define ECUM_SUPPORT_RTE_MODE_SWITCH                                 (STD_OFF)
# define ECUM_SUPPORT_RTE_MODE_SWITCH_ACK                             (STD_OFF)
# define ECUM_INCLUDE_NVRAM_MGR                                       (STD_OFF)
# define ECUM_SUPPORT_DEM                                             (STD_OFF)
# define ECUM_SUPPORT_COMM                                            (STD_OFF)

/* current configuration variant ECUM_VARIANT_PRECOMPILE  || ECUM_VARIANT_POSTBUILD */

/* General Defines */
#ifndef ECUM_USE_DUMMY_STATEMENT
#define ECUM_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef ECUM_DUMMY_STATEMENT
#define ECUM_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef ECUM_DUMMY_STATEMENT_CONST
#define ECUM_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef ECUM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define ECUM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef ECUM_ATOMIC_VARIABLE_ACCESS
#define ECUM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef ECUM_PROCESSOR_TC397_STEPB
#define ECUM_PROCESSOR_TC397_STEPB
#endif
#ifndef ECUM_COMP_TASKING
#define ECUM_COMP_TASKING
#endif
#ifndef ECUM_GEN_GENERATOR_MSR
#define ECUM_GEN_GENERATOR_MSR
#endif
#ifndef ECUM_CPUTYPE_BITORDER_LSB2MSB
#define ECUM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef ECUM_CONFIGURATION_VARIANT_PRECOMPILE
#define ECUM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef ECUM_CONFIGURATION_VARIANT_LINKTIME
#define ECUM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef ECUM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define ECUM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef ECUM_CONFIGURATION_VARIANT
#define ECUM_CONFIGURATION_VARIANT ECUM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef ECUM_POSTBUILD_VARIANT_SUPPORT
#define ECUM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/**********************************************************************************************************************
 *  PRE-COMPILE Parameters
 *********************************************************************************************************************/
/* Variables that are used to determine the arraysizes or the number of some modes */
#define ECUM_RESETMODECOUNT                                           (4u)
#define ECUM_SHUTDOWNCAUSECOUNT                                       (4u)
#define ECUM_NUMBER_OF_CORES                                          (6u)
#define ECUM_NUMBER_OF_OS_APPLICATIONS                                (6u)

#define ECUM_CORE_ID_STARTUP                                          OS_CORE_ID_MASTER
#define ECUM_CORE_ID_BSW                                              OS_CORE_ID_MASTER
#define ECUM_OS_RESOURCE                                              RES_SCHEDULER_OsCore0 /*  The selected OsResource  */ 


#define ECUM_BSWM_CONFIG_POINTER                                      BswM_Config_Ptr
#define ECUM_SCHM_CONFIG_POINTER                                      

typedef uint32 *EcuM_CoreStatusArrayType;
typedef uint32 EcuM_CoreStatusType;
#define EcuM_SetCoreStatusValue(partitionIdx, value)                  (*EcuM_GetCoreStatus(partitionIdx) = value) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define EcuM_GetCoreStatusValue(partitionIdx)                         (*EcuM_GetCoreStatus(partitionIdx))         /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

# if (STD_ON == ECUM_DEV_ERROR_DETECT)
#  define EcuM_Det_ReportError(EcuM_FunctionId, EcuM_ErrorCode)       ((void)Det_ReportError((ECUM_MODULE_ID), (ECUM_INSTANCE_ID), (EcuM_FunctionId), (EcuM_ErrorCode))) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# else
#  define EcuM_Det_ReportError(EcuM_FunctionId, EcuM_ErrorCode)  
# endif

/*---- configurable DEM Errors ---------------------------------------------*/



/**********************************************************************************************************************
 *  POSTBUILD Parameters
 *********************************************************************************************************************/
 
 /**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/* Postbuild */
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  EcuMPBDataSwitches  EcuM Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define ECUM_PBCONFIG                                                 STD_OFF  /**< Deactivateable: 'EcuM_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define ECUM_LTCONFIGIDXOFPBCONFIG                                    STD_OFF  /**< Deactivateable: 'EcuM_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define ECUM_PCCONFIGIDXOFPBCONFIG                                    STD_OFF  /**< Deactivateable: 'EcuM_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  EcuMPCDataSwitches  EcuM Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define ECUM_ALARMCLOCKTIMEOUT                                        STD_OFF  /**< Deactivateable: 'EcuM_AlarmClockTimeOut' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define ECUM_COMMPNCS                                                 STD_OFF  /**< Deactivateable: 'EcuM_ComMPNCs' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define ECUM_PNCOFCOMMPNCS                                            STD_OFF  /**< Deactivateable: 'EcuM_ComMPNCs.PNC' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define ECUM_CORERESOURCE                                             STD_OFF  /**< Deactivateable: 'EcuM_CoreResource' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define ECUM_CORESTATUS                                               STD_ON
#define ECUM_DEFAULTAPPMODE                                           STD_ON
#define ECUM_DEFAULTSHUTDOWNMODE                                      STD_ON
#define ECUM_DEFAULTSHUTDOWNTARGET                                    STD_ON
#define ECUM_DRIVERINITONE                                            STD_ON
#define ECUM_FUNCTIONOFDRIVERINITONE                                  STD_ON
#define ECUM_DRIVERRESTARTLIST                                        STD_OFF  /**< Deactivateable: 'EcuM_DriverRestartList' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define ECUM_FUNCTIONOFDRIVERRESTARTLIST                              STD_OFF  /**< Deactivateable: 'EcuM_DriverRestartList.Function' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define ECUM_ECUM_CRCHASH_LOWER                                       STD_ON
#define ECUM_ECUM_CRCHASH_UPPER                                       STD_ON
#define ECUM_FINALMAGICNUMBER                                         STD_OFF  /**< Deactivateable: 'EcuM_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define ECUM_FLEXUSER                                                 STD_OFF  /**< Deactivateable: 'EcuM_FlexUser' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define ECUM_ALARMCLOCKIDOFFLEXUSER                                   STD_OFF  /**< Deactivateable: 'EcuM_FlexUser.AlarmClockId' Reason: 'Alarm Clock Feature is not active.' */
#define ECUM_GODOWNALLOWEDOFFLEXUSER                                  STD_OFF  /**< Deactivateable: 'EcuM_FlexUser.GoDownAllowed' Reason: 'Defensive Behavior is not active!' */
#define ECUM_MODULEIDOFFLEXUSER                                       STD_OFF  /**< Deactivateable: 'EcuM_FlexUser.ModuleId' Reason: 'Defensive Behavior is not active.' */
#define ECUM_SETCLOCKALLOWEDOFFLEXUSER                                STD_OFF  /**< Deactivateable: 'EcuM_FlexUser.SetClockAllowed' Reason: 'Alarm Clock Feature is not active.' */
#define ECUM_GENERATORCOMPATIBILITYVERSION                            STD_ON
#define ECUM_INITDATAHASHCODE                                         STD_OFF  /**< Deactivateable: 'EcuM_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define ECUM_MAXWAKEUPSOURCECOUNT                                     STD_ON
#define ECUM_MODULESTATE                                              STD_ON
#define ECUM_NORMALMCUMODE                                            STD_ON
#define ECUM_PARTITIONINIT                                            STD_ON
#define ECUM_APPLICATIONOFPARTITIONINIT                               STD_ON
#define ECUM_BSWMPARTITIONOFPARTITIONINIT                             STD_OFF  /**< Deactivateable: 'EcuM_PartitionInit.BswMPartition' Reason: 'the value of EcuM_BswMPartitionOfPartitionInit is always 'false' due to this, the array is deactivated.' */
#define ECUM_ECUMPARTITIONOFPARTITIONINIT                             STD_ON
#define ECUM_SIZEOFCORESTATUS                                         STD_ON
#define ECUM_SIZEOFDRIVERINITONE                                      STD_ON
#define ECUM_SIZEOFPARTITIONINIT                                      STD_ON
#define ECUM_SIZEOFWAKEUPSOURCELIST                                   STD_ON
#define ECUM_SLEEPMODELIST                                            STD_OFF  /**< Deactivateable: 'EcuM_SleepModeList' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define ECUM_MCUMODEOFSLEEPMODELIST                                   STD_OFF  /**< Deactivateable: 'EcuM_SleepModeList.McuMode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define ECUM_POLLINGOFSLEEPMODELIST                                   STD_OFF  /**< Deactivateable: 'EcuM_SleepModeList.Polling' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define ECUM_VALIDOFSLEEPMODELIST                                     STD_OFF  /**< Deactivateable: 'EcuM_SleepModeList.Valid' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define ECUM_WAKEUPSOURCEOFSLEEPMODELIST                              STD_OFF  /**< Deactivateable: 'EcuM_SleepModeList.WakeupSource' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define ECUM_VALIDATIONTIMEOUTTABLE                                   STD_OFF  /**< Deactivateable: 'EcuM_ValidationTimeoutTable' Reason: 'No validation timeouts configured.' */
#define ECUM_WAKEUPSOURCELIST                                         STD_ON
#define ECUM_CHANNELOFWAKEUPSOURCELIST                                STD_ON
#define ECUM_CHECKWAKEUPTIMEOFWAKEUPSOURCELIST                        STD_OFF  /**< Deactivateable: 'EcuM_WakeupSourceList.CheckWakeupTime' Reason: 'the value of EcuM_CheckWakeupTimeOfWakeupSourceList is always '0' due to this, the array is deactivated.' */
#define ECUM_COMMPNCSENDIDXOFWAKEUPSOURCELIST                         STD_OFF  /**< Deactivateable: 'EcuM_WakeupSourceList.ComMPNCsEndIdx' Reason: 'the optional indirection is deactivated because ComMPNCsUsedOfWakeupSourceList is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define ECUM_COMMPNCSSTARTIDXOFWAKEUPSOURCELIST                       STD_OFF  /**< Deactivateable: 'EcuM_WakeupSourceList.ComMPNCsStartIdx' Reason: 'the optional indirection is deactivated because ComMPNCsUsedOfWakeupSourceList is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define ECUM_COMMPNCSUSEDOFWAKEUPSOURCELIST                           STD_OFF  /**< Deactivateable: 'EcuM_WakeupSourceList.ComMPNCsUsed' Reason: 'the optional indirection is deactivated because ComMPNCsUsedOfWakeupSourceList is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define ECUM_POLLINGOFWAKEUPSOURCELIST                                STD_OFF  /**< Deactivateable: 'EcuM_WakeupSourceList.Polling' Reason: 'the value of EcuM_PollingOfWakeupSourceList is always 'false' due to this, the array is deactivated.' */
#define ECUM_REASONOFWAKEUPSOURCELIST                                 STD_OFF  /**< Deactivateable: 'EcuM_WakeupSourceList.Reason' Reason: 'No Mcu Reset Reason configured.' */
#define ECUM_VALIDOFWAKEUPSOURCELIST                                  STD_OFF  /**< Deactivateable: 'EcuM_WakeupSourceList.Valid' Reason: 'the value of EcuM_ValidOfWakeupSourceList is always 'true' due to this, the array is deactivated.' */
#define ECUM_VALIDATIONTIMEOFWAKEUPSOURCELIST                         STD_OFF  /**< Deactivateable: 'EcuM_WakeupSourceList.ValidationTime' Reason: 'the value of EcuM_ValidationTimeOfWakeupSourceList is always '0' due to this, the array is deactivated.' */
#define ECUM_PCCONFIG                                                 STD_ON
#define ECUM_CORESTATUSOFPCCONFIG                                     STD_ON
#define ECUM_DEFAULTAPPMODEOFPCCONFIG                                 STD_ON
#define ECUM_DEFAULTSHUTDOWNMODEOFPCCONFIG                            STD_ON
#define ECUM_DEFAULTSHUTDOWNTARGETOFPCCONFIG                          STD_ON
#define ECUM_DRIVERINITONEOFPCCONFIG                                  STD_ON
#define ECUM_ECUM_CRCHASH_LOWEROFPCCONFIG                             STD_ON
#define ECUM_ECUM_CRCHASH_UPPEROFPCCONFIG                             STD_ON
#define ECUM_FINALMAGICNUMBEROFPCCONFIG                               STD_OFF  /**< Deactivateable: 'EcuM_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define ECUM_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                  STD_ON
#define ECUM_INITDATAHASHCODEOFPCCONFIG                               STD_OFF  /**< Deactivateable: 'EcuM_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define ECUM_MAXWAKEUPSOURCECOUNTOFPCCONFIG                           STD_ON
#define ECUM_MODULESTATEOFPCCONFIG                                    STD_ON
#define ECUM_NORMALMCUMODEOFPCCONFIG                                  STD_ON
#define ECUM_PARTITIONINITOFPCCONFIG                                  STD_ON
#define ECUM_SIZEOFCORESTATUSOFPCCONFIG                               STD_ON
#define ECUM_SIZEOFDRIVERINITONEOFPCCONFIG                            STD_ON
#define ECUM_SIZEOFPARTITIONINITOFPCCONFIG                            STD_ON
#define ECUM_SIZEOFWAKEUPSOURCELISTOFPCCONFIG                         STD_ON
#define ECUM_WAKEUPSOURCELISTOFPCCONFIG                               STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  EcuMPCIsReducedToDefineDefines  EcuM Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define ECUM_ISDEF_CORESTATUS                                         STD_OFF
#define ECUM_ISDEF_FUNCTIONOFDRIVERINITONE                            STD_OFF
#define ECUM_ISDEF_APPLICATIONOFPARTITIONINIT                         STD_OFF
#define ECUM_ISDEF_ECUMPARTITIONOFPARTITIONINIT                       STD_ON
#define ECUM_ISDEF_CHANNELOFWAKEUPSOURCELIST                          STD_OFF
#define ECUM_ISDEF_CORESTATUSOFPCCONFIG                               STD_ON
#define ECUM_ISDEF_DRIVERINITONEOFPCCONFIG                            STD_ON
#define ECUM_ISDEF_MODULESTATEOFPCCONFIG                              STD_ON
#define ECUM_ISDEF_PARTITIONINITOFPCCONFIG                            STD_ON
#define ECUM_ISDEF_WAKEUPSOURCELISTOFPCCONFIG                         STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  EcuMPCEqualsAlwaysToDefines  EcuM Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define ECUM_EQ2_CORESTATUS                                           
#define ECUM_EQ2_FUNCTIONOFDRIVERINITONE                              
#define ECUM_EQ2_APPLICATIONOFPARTITIONINIT                           
#define ECUM_EQ2_ECUMPARTITIONOFPARTITIONINIT                         TRUE
#define ECUM_EQ2_CHANNELOFWAKEUPSOURCELIST                            
#define ECUM_EQ2_CORESTATUSOFPCCONFIG                                 EcuM_CoreStatus
#define ECUM_EQ2_DRIVERINITONEOFPCCONFIG                              EcuM_DriverInitOne
#define ECUM_EQ2_MODULESTATEOFPCCONFIG                                (&(EcuM_ModuleState))
#define ECUM_EQ2_PARTITIONINITOFPCCONFIG                              EcuM_PartitionInit
#define ECUM_EQ2_WAKEUPSOURCELISTOFPCCONFIG                           EcuM_WakeupSourceList
/** 
  \}
*/ 

/** 
  \defgroup  EcuMPCSymbolicInitializationPointers  EcuM Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define EcuM_Config_Ptr                                               NULL_PTR  /**< symbolic identifier which shall be used to initialize 'EcuM' */
/** 
  \}
*/ 

/** 
  \defgroup  EcuMPCInitializationSymbols  EcuM Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define EcuM_Config                                                   NULL_PTR  /**< symbolic identifier which could be used to initialize 'EcuM */
/** 
  \}
*/ 

/** 
  \defgroup  EcuMPCGeneral  EcuM General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define ECUM_CHECK_INIT_POINTER                                       STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define ECUM_FINAL_MAGIC_NUMBER                                       0x0A1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of EcuM */
#define ECUM_INDIVIDUAL_POSTBUILD                                     STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'EcuM' is not configured to be postbuild capable. */
#define ECUM_INIT_DATA                                                ECUM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define ECUM_INIT_DATA_HASH_CODE                                      1797910197  /**< the precompile constant to validate the initialization structure at initialization time of EcuM with a hashcode. The seed value is '0x0A1Eu' */
#define ECUM_USE_ECUM_BSW_ERROR_HOOK                                  STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define ECUM_USE_INIT_POINTER                                         STD_OFF  /**< STD_ON if the init pointer EcuM shall be used. */
/** 
  \}
*/ 



/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
typedef P2FUNC ( void, ECUM_CODE, EcuM_DriverFuncType)( void );

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  EcuMPCIterableTypes  EcuM Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate EcuM_CoreStatus */
typedef uint8_least EcuM_CoreStatusIterType;

/**   \brief  type used to iterate EcuM_DriverInitOne */
typedef uint8_least EcuM_DriverInitOneIterType;

/**   \brief  type used to iterate EcuM_PartitionInit */
typedef uint8_least EcuM_PartitionInitIterType;

/**   \brief  type used to iterate EcuM_WakeupSourceList */
typedef uint8_least EcuM_WakeupSourceListIterType;

/** 
  \}
*/ 

/** 
  \defgroup  EcuMPCValueTypes  EcuM Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for EcuM_DefaultAppMode */
typedef uint32 EcuM_DefaultAppModeType;

/**   \brief  value based type definition for EcuM_DefaultShutdownMode */
typedef uint8 EcuM_DefaultShutdownModeType;

/**   \brief  value based type definition for EcuM_EcuM_CRCHash_Lower */
typedef uint32 EcuM_EcuM_CRCHash_LowerType;

/**   \brief  value based type definition for EcuM_EcuM_CRCHash_Upper */
typedef uint32 EcuM_EcuM_CRCHash_UpperType;

/**   \brief  value based type definition for EcuM_GeneratorCompatibilityVersion */
typedef uint16 EcuM_GeneratorCompatibilityVersionType;

/**   \brief  value based type definition for EcuM_MaxWakeupSourceCount */
typedef uint8 EcuM_MaxWakeupSourceCountType;

/**   \brief  value based type definition for EcuM_NormalMcuMode */
typedef uint32 EcuM_NormalMcuModeType;

/**   \brief  value based type definition for EcuM_ApplicationOfPartitionInit */
typedef uint8 EcuM_ApplicationOfPartitionInitType;

/**   \brief  value based type definition for EcuM_EcuMPartitionOfPartitionInit */
typedef boolean EcuM_EcuMPartitionOfPartitionInitType;

/**   \brief  value based type definition for EcuM_SizeOfCoreStatus */
typedef uint8 EcuM_SizeOfCoreStatusType;

/**   \brief  value based type definition for EcuM_SizeOfDriverInitOne */
typedef uint8 EcuM_SizeOfDriverInitOneType;

/**   \brief  value based type definition for EcuM_SizeOfPartitionInit */
typedef uint8 EcuM_SizeOfPartitionInitType;

/**   \brief  value based type definition for EcuM_SizeOfWakeupSourceList */
typedef uint8 EcuM_SizeOfWakeupSourceListType;

/**   \brief  value based type definition for EcuM_ChannelOfWakeupSourceList */
typedef uint8 EcuM_ChannelOfWakeupSourceListType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  EcuMPCStructTypes  EcuM Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in EcuM_DriverInitOne */
typedef struct sEcuM_DriverInitOneType
{
  EcuM_DriverFuncType FunctionOfDriverInitOne;
} EcuM_DriverInitOneType;

/**   \brief  type used in EcuM_PartitionInit */
typedef struct sEcuM_PartitionInitType
{
  EcuM_ApplicationOfPartitionInitType ApplicationOfPartitionInit;  /**<  */
} EcuM_PartitionInitType;

/**   \brief  type used in EcuM_WakeupSourceList */
typedef struct sEcuM_WakeupSourceListType
{
  EcuM_ChannelOfWakeupSourceListType ChannelOfWakeupSourceList;  /**< Mapped ComM channel number - 255 if no ComM channel is assigned. */
} EcuM_WakeupSourceListType;

/** 
  \}
*/ 

/** 
  \defgroup  EcuMPCRootPointerTypes  EcuM Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to EcuM_CoreStatus */
typedef P2CONST(EcuM_CoreStatusArrayType, TYPEDEF, ECUM_CONST) EcuM_CoreStatusPtrType;

/**   \brief  type used to point to EcuM_DriverInitOne */
typedef P2CONST(EcuM_DriverInitOneType, TYPEDEF, ECUM_CONST) EcuM_DriverInitOnePtrType;

/**   \brief  type used to point to EcuM_ModuleState */
typedef P2VAR(EcuM_StateType, TYPEDEF, ECUM_VAR_NOINIT) EcuM_ModuleStatePtrType;

/**   \brief  type used to point to EcuM_PartitionInit */
typedef P2CONST(EcuM_PartitionInitType, TYPEDEF, ECUM_CONST) EcuM_PartitionInitPtrType;

/**   \brief  type used to point to EcuM_WakeupSourceList */
typedef P2CONST(EcuM_WakeupSourceListType, TYPEDEF, ECUM_CONST) EcuM_WakeupSourceListPtrType;

/**   \brief  type used to point to EcuM_DefaultAppModeOfPCConfig */
typedef P2CONST(EcuM_DefaultAppModeType, TYPEDEF, ECUM_CONST) EcuM_DefaultAppModeOfPCConfigPtrType;

/**   \brief  type used to point to EcuM_DefaultShutdownTargetOfPCConfig */
typedef P2CONST(EcuM_StateType, TYPEDEF, ECUM_CONST) EcuM_DefaultShutdownTargetOfPCConfigPtrType;

/**   \brief  type used to point to EcuM_NormalMcuModeOfPCConfig */
typedef P2CONST(EcuM_NormalMcuModeType, TYPEDEF, ECUM_CONST) EcuM_NormalMcuModeOfPCConfigPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  EcuMPCRootValueTypes  EcuM Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in EcuM_PCConfig */
typedef struct sEcuM_PCConfigType
{
  uint8 EcuM_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} EcuM_PCConfigType;

typedef EcuM_PCConfigType EcuM_PbConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 




/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/





#endif /* ECUM_CFG_H */
/**********************************************************************************************************************
 *  END OF FILE: ECUM_CFG.H
 *********************************************************************************************************************/


