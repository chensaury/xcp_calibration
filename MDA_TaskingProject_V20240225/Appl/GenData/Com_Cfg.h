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
 *            Module: Com
 *           Program: MSR_Vector_SLP4
 *          Customer: Aptiv (China) Technology Company Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Aurix 2G/TC397 B-Step
 *    License Scope : The usage is restricted to CBD1900078_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Com_Cfg.h
 *   Generation Time: 2024-01-08 16:27:31
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


#if !defined (COM_CFG_H)
# define COM_CFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
# include "Com_Types.h"
# include "Com_PBcfg.h"
# include "Com_Cbk.h"
# include "PduR_Cfg.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/

#ifndef COM_USE_DUMMY_STATEMENT
#define COM_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef COM_DUMMY_STATEMENT
#define COM_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef COM_DUMMY_STATEMENT_CONST
#define COM_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef COM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define COM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef COM_ATOMIC_VARIABLE_ACCESS
#define COM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef COM_PROCESSOR_TC397_STEPB
#define COM_PROCESSOR_TC397_STEPB
#endif
#ifndef COM_COMP_TASKING
#define COM_COMP_TASKING
#endif
#ifndef COM_GEN_GENERATOR_MSR
#define COM_GEN_GENERATOR_MSR
#endif
#ifndef COM_CPUTYPE_BITORDER_LSB2MSB
#define COM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef COM_CONFIGURATION_VARIANT_PRECOMPILE
#define COM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef COM_CONFIGURATION_VARIANT_LINKTIME
#define COM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef COM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define COM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef COM_CONFIGURATION_VARIANT
#define COM_CONFIGURATION_VARIANT COM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef COM_POSTBUILD_VARIANT_SUPPORT
#define COM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  ComPCDataSwitches  Com Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define COM_ACTIVATABLERXCOMIPDUS                                     STD_ON
#define COM_RXPDUINFOIDXOFACTIVATABLERXCOMIPDUS                       STD_ON
#define COM_ACTIVATABLETXCOMIPDUS                                     STD_ON
#define COM_TXPDUINFOIDXOFACTIVATABLETXCOMIPDUS                       STD_ON
#define COM_ALWAYSACTIVERXCOMIPDUS                                    STD_OFF  /**< Deactivateable: 'Com_AlwaysActiveRxComIPdus' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_RXPDUINFOIDXOFALWAYSACTIVERXCOMIPDUS                      STD_OFF  /**< Deactivateable: 'Com_AlwaysActiveRxComIPdus.RxPduInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_ALWAYSACTIVETXCOMIPDUS                                    STD_OFF  /**< Deactivateable: 'Com_AlwaysActiveTxComIPdus' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_TXPDUINFOIDXOFALWAYSACTIVETXCOMIPDUS                      STD_OFF  /**< Deactivateable: 'Com_AlwaysActiveTxComIPdus.TxPduInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKRXTOUTFUNCPTR                                          STD_OFF  /**< Deactivateable: 'Com_CbkRxTOutFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKRXTOUTFUNCPTRIND                                       STD_OFF  /**< Deactivateable: 'Com_CbkRxTOutFuncPtrInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXACKDEFFUNCPTR                                        STD_OFF  /**< Deactivateable: 'Com_CbkTxAckDefFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXACKDEFFUNCPTRIND                                     STD_OFF  /**< Deactivateable: 'Com_CbkTxAckDefFuncPtrInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXACKIMFUNCPTR                                         STD_OFF  /**< Deactivateable: 'Com_CbkTxAckImFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXACKIMFUNCPTRIND                                      STD_OFF  /**< Deactivateable: 'Com_CbkTxAckImFuncPtrInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXERRFUNCPTR                                           STD_OFF  /**< Deactivateable: 'Com_CbkTxErrFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXERRFUNCPTRIND                                        STD_OFF  /**< Deactivateable: 'Com_CbkTxErrFuncPtrInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXTOUTFUNCPTR                                          STD_OFF  /**< Deactivateable: 'Com_CbkTxTOutFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXTOUTFUNCPTRIND                                       STD_OFF  /**< Deactivateable: 'Com_CbkTxTOutFuncPtrInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONFIGID                                                  STD_ON
#define COM_CONSTVALUEARRAYBASED                                      STD_OFF  /**< Deactivateable: 'Com_ConstValueArrayBased' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEFLOAT32                                         STD_ON
#define COM_CONSTVALUEFLOAT64                                         STD_OFF  /**< Deactivateable: 'Com_ConstValueFloat64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESINT16                                          STD_ON
#define COM_CONSTVALUESINT32                                          STD_OFF  /**< Deactivateable: 'Com_ConstValueSInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESINT64                                          STD_OFF  /**< Deactivateable: 'Com_ConstValueSInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESINT8                                           STD_OFF  /**< Deactivateable: 'Com_ConstValueSInt8' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESIGGRPARRAYACCESS                               STD_OFF  /**< Deactivateable: 'Com_ConstValueSigGrpArrayAccess' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEUINT16                                          STD_ON
#define COM_CONSTVALUEUINT32                                          STD_OFF  /**< Deactivateable: 'Com_ConstValueUInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEUINT64                                          STD_OFF  /**< Deactivateable: 'Com_ConstValueUInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEUINT8                                           STD_ON
#define COM_CURRENTTXMODE                                             STD_ON
#define COM_CYCLETIMECNT                                              STD_ON
#define COM_CYCLICSENDREQUEST                                         STD_ON
#define COM_DEFERREDGWMAPPINGEVENT                                    STD_OFF  /**< Deactivateable: 'Com_DeferredGwMappingEvent' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionRoutingCodeGeneration] is configured to 'false'' */
#define COM_DEFERREDGWMAPPINGINFO                                     STD_OFF  /**< Deactivateable: 'Com_DeferredGwMappingInfo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionRoutingCodeGeneration] is configured to 'false'' */
#define COM_RXPDUINFOIDXOFDEFERREDGWMAPPINGINFO                       STD_OFF  /**< Deactivateable: 'Com_DeferredGwMappingInfo.RxPduInfoIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionRoutingCodeGeneration] is configured to 'false'' */
#define COM_DELAYTIMECNT                                              STD_ON
#define COM_DIRECTTRIGGER                                             STD_OFF  /**< Deactivateable: 'Com_DirectTrigger' Reason: 'the parameter is only needed if ComEnableMDTForCyclicTransmission is equals FALSE.' */
#define COM_FILTERINFO_FLOAT32                                        STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_FLOAT32                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_FLOAT32                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_FLOAT32                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterMax' Reason: 'FilterMin, FilterMax, FilterX are deactivated for Float32 and Float64 Filter Info, because they aren't configurable.' */
#define COM_FILTERMINOFFILTERINFO_FLOAT32                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterMin' Reason: 'FilterMin, FilterMax, FilterX are deactivated for Float32 and Float64 Filter Info, because they aren't configurable.' */
#define COM_FILTERXOFFILTERINFO_FLOAT32                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterX' Reason: 'FilterMin, FilterMax, FilterX are deactivated for Float32 and Float64 Filter Info, because they aren't configurable.' */
#define COM_FILTERINFO_FLOAT64                                        STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_FLOAT64                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_FLOAT64                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_FLOAT64                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterMax' Reason: 'FilterMin, FilterMax, FilterX are deactivated for Float32 and Float64 Filter Info, because they aren't configurable.' */
#define COM_FILTERMINOFFILTERINFO_FLOAT64                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterMin' Reason: 'FilterMin, FilterMax, FilterX are deactivated for Float32 and Float64 Filter Info, because they aren't configurable.' */
#define COM_FILTERXOFFILTERINFO_FLOAT64                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterX' Reason: 'FilterMin, FilterMax, FilterX are deactivated for Float32 and Float64 Filter Info, because they aren't configurable.' */
#define COM_FILTERINFO_SINT16                                         STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_SINT16                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_SINT16                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_SINT16                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_SINT16                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_SINT16                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_SINT32                                         STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_SINT32                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_SINT32                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_SINT32                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_SINT32                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_SINT32                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_SINT64                                         STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_SINT64                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_SINT64                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_SINT64                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_SINT64                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_SINT64                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_SINT8                                          STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_SINT8                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_SINT8                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_SINT8                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_SINT8                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_SINT8                                 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_UINT16                                         STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_UINT16                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_UINT16                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_UINT16                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_UINT16                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_UINT16                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_UINT32                                         STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_UINT32                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_UINT32                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_UINT32                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_UINT32                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_UINT32                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_UINT64                                         STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_UINT64                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_UINT64                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_UINT64                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_UINT64                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_UINT64                                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_UINT8                                          STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_UINT8                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_UINT8                              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_UINT8                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_UINT8                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_UINT8                                 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERINFO_UINT8_N                                        STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_FILTERALGOOFFILTERINFO_UINT8_N                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMASKOFFILTERINFO_UINT8_N                            STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterMask' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMAXOFFILTERINFO_UINT8_N                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterMax' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERMINOFFILTERINFO_UINT8_N                             STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterMin' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTERXOFFILTERINFO_UINT8_N                               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterX' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FINALMAGICNUMBER                                          STD_OFF  /**< Deactivateable: 'Com_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define COM_GATEWAYDESCRIPTIONPROCESSINGISRLOCKCOUNTER                STD_OFF  /**< Deactivateable: 'Com_GatewayDescriptionProcessingISRLockCounter' Reason: 'Gateway description feature is not licensed' */
#define COM_GATEWAYDESCRIPTIONPROCESSINGISRLOCKTHRESHOLD              STD_OFF  /**< Deactivateable: 'Com_GatewayDescriptionProcessingISRLockThreshold' Reason: 'Gateway description feature is not licensed' */
#define COM_GATEWAYPROCESSINGISRLOCKCOUNTER                           STD_ON
#define COM_GATEWAYPROCESSINGISRLOCKTHRESHOLD                         STD_OFF  /**< Deactivateable: 'Com_GatewayProcessingISRLockThreshold' Reason: 'Signal Gateway either not licensed or not configured.' */
#define COM_GWDESCRIPTIONACCESSINFO                                   STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo' Reason: 'Gateway description feature is not licensed' */
#define COM_BITOFFSETOFGWDESCRIPTIONACCESSINFO                        STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.BitOffset' Reason: 'Gateway description feature is not licensed' */
#define COM_BITSIZEOFGWDESCRIPTIONACCESSINFO                          STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.BitSize' Reason: 'Gateway description feature is not licensed' */
#define COM_COPYTYPEOFGWDESCRIPTIONACCESSINFO                         STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.CopyType' Reason: 'Gateway description feature is not licensed' */
#define COM_ENDIANNESSOFGWDESCRIPTIONACCESSINFO                       STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Endianness' Reason: 'Gateway description feature is not licensed' */
#define COM_GWSOURCESTARTBITINDEXOFGWDESCRIPTIONACCESSINFO            STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.GwSourceStartBitIndex' Reason: 'Gateway description feature is not licensed' */
#define COM_RXUBIDXOFGWDESCRIPTIONACCESSINFO                          STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.RxUbIdx' Reason: 'Gateway description feature is not licensed' */
#define COM_RXUBMASKIDXOFGWDESCRIPTIONACCESSINFO                      STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.RxUbMaskIdx' Reason: 'Gateway description feature is not licensed' */
#define COM_RXUBMASKUSEDOFGWDESCRIPTIONACCESSINFO                     STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.RxUbMaskUsed' Reason: 'Gateway description feature is not licensed' */
#define COM_SOURCEDESCRIPTIONMASKENDMASKIDXOFGWDESCRIPTIONACCESSINFO  STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.SourceDescriptionMaskEndMaskIdx' Reason: 'Gateway description feature is not licensed' */
#define COM_SOURCEDESCRIPTIONMASKENDMASKUSEDOFGWDESCRIPTIONACCESSINFO STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.SourceDescriptionMaskEndMaskUsed' Reason: 'Gateway description feature is not licensed' */
#define COM_SOURCEDESCRIPTIONMASKIDXOFGWDESCRIPTIONACCESSINFO         STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.SourceDescriptionMaskIdx' Reason: 'Gateway description feature is not licensed' */
#define COM_SOURCESTARTBYTEPOSITIONOFGWDESCRIPTIONACCESSINFO          STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.SourceStartBytePosition' Reason: 'Gateway description feature is not licensed' */
#define COM_TXBUFFERENDIDXOFGWDESCRIPTIONACCESSINFO                   STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxBufferEndIdx' Reason: 'Gateway description feature is not licensed' */
#define COM_TXBUFFERLENGTHOFGWDESCRIPTIONACCESSINFO                   STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxBufferLength' Reason: 'Gateway description feature is not licensed' */
#define COM_TXBUFFERSTARTIDXOFGWDESCRIPTIONACCESSINFO                 STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxBufferStartIdx' Reason: 'Gateway description feature is not licensed' */
#define COM_TXBUFFERUBIDXOFGWDESCRIPTIONACCESSINFO                    STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxBufferUbIdx' Reason: 'Gateway description feature is not licensed' */
#define COM_TXBUFFERUBUSEDOFGWDESCRIPTIONACCESSINFO                   STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxBufferUbUsed' Reason: 'Gateway description feature is not licensed' */
#define COM_TXPDUINFOIDXOFGWDESCRIPTIONACCESSINFO                     STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxPduInfoIdx' Reason: 'Gateway description feature is not licensed' */
#define COM_TXUBMASKIDXOFGWDESCRIPTIONACCESSINFO                      STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxUbMaskIdx' Reason: 'Gateway description feature is not licensed' */
#define COM_TXUBMASKUSEDOFGWDESCRIPTIONACCESSINFO                     STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.TxUbMaskUsed' Reason: 'Gateway description feature is not licensed' */
#define COM_TYPEOFGWDESCRIPTIONACCESSINFO                             STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: 'Gateway description feature is not licensed' */
#define COM_VALIDDLCOFGWDESCRIPTIONACCESSINFO                         STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.ValidDlc' Reason: 'Gateway description feature is not licensed' */
#define COM_GWEVENT                                                   STD_OFF  /**< Deactivateable: 'Com_GwEvent' Reason: 'The gateway is deactivated!' */
#define COM_GWEVENTCACHE                                              STD_OFF  /**< Deactivateable: 'Com_GwEventCache' Reason: 'Gateway description feature is not licensed' */
#define COM_GWEVENTCACHEINDEX                                         STD_OFF  /**< Deactivateable: 'Com_GwEventCacheIndex' Reason: 'Gateway description feature is not licensed' */
#define COM_GWGRPSIGMAPPING                                           STD_OFF  /**< Deactivateable: 'Com_GwGrpSigMapping' Reason: 'The gateway is deactivated!' */
#define COM_RXACCESSINFOIDXOFGWGRPSIGMAPPING                          STD_OFF  /**< Deactivateable: 'Com_GwGrpSigMapping.RxAccessInfoIdx' Reason: 'The gateway is deactivated!' */
#define COM_TXSIGIDOFGWGRPSIGMAPPING                                  STD_OFF  /**< Deactivateable: 'Com_GwGrpSigMapping.TxSigId' Reason: 'The gateway is deactivated!' */
#define COM_GWINFO                                                    STD_OFF  /**< Deactivateable: 'Com_GwInfo' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGGRPMAPPINGENDIDXOFGWINFO                             STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigGrpMappingEndIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGGRPMAPPINGSTARTIDXOFGWINFO                           STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigGrpMappingStartIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGGRPMAPPINGUSEDOFGWINFO                               STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigGrpMappingUsed' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGMAPPINGENDIDXOFGWINFO                                STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigMappingEndIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGMAPPINGSTARTIDXOFGWINFO                              STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigMappingStartIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGMAPPINGUSEDOFGWINFO                                  STD_OFF  /**< Deactivateable: 'Com_GwInfo.GwSigMappingUsed' Reason: 'The gateway is deactivated!' */
#define COM_GWROUTINGTIMEOUTCOUNTER                                   STD_OFF  /**< Deactivateable: 'Com_GwRoutingTimeoutCounter' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_GWSIGGRPMAPPING                                           STD_OFF  /**< Deactivateable: 'Com_GwSigGrpMapping' Reason: 'The gateway is deactivated!' */
#define COM_GWGRPSIGMAPPINGENDIDXOFGWSIGGRPMAPPING                    STD_OFF  /**< Deactivateable: 'Com_GwSigGrpMapping.GwGrpSigMappingEndIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWGRPSIGMAPPINGSTARTIDXOFGWSIGGRPMAPPING                  STD_OFF  /**< Deactivateable: 'Com_GwSigGrpMapping.GwGrpSigMappingStartIdx' Reason: 'The gateway is deactivated!' */
#define COM_TXSIGGRPIDOFGWSIGGRPMAPPING                               STD_OFF  /**< Deactivateable: 'Com_GwSigGrpMapping.TxSigGrpId' Reason: 'The gateway is deactivated!' */
#define COM_GWSIGMAPPING                                              STD_OFF  /**< Deactivateable: 'Com_GwSigMapping' Reason: 'The gateway is deactivated!' */
#define COM_RXACCESSINFOIDXOFGWSIGMAPPING                             STD_OFF  /**< Deactivateable: 'Com_GwSigMapping.RxAccessInfoIdx' Reason: 'The gateway is deactivated!' */
#define COM_TXSIGIDOFGWSIGMAPPING                                     STD_OFF  /**< Deactivateable: 'Com_GwSigMapping.TxSigId' Reason: 'The gateway is deactivated!' */
#define COM_GWTIMEOUTINFO                                             STD_OFF  /**< Deactivateable: 'Com_GwTimeoutInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_GWROUTINGTIMEOUTFACTOROFGWTIMEOUTINFO                     STD_OFF  /**< Deactivateable: 'Com_GwTimeoutInfo.GwRoutingTimeoutFactor' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXPDUINFOIDXOFGWTIMEOUTINFO                               STD_OFF  /**< Deactivateable: 'Com_GwTimeoutInfo.TxPduInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_GWTXPDUDESCRIPTIONINFO                                    STD_OFF  /**< Deactivateable: 'Com_GwTxPduDescriptionInfo' Reason: 'Gateway description feature is not licensed' */
#define COM_GWDESCRIPTIONACCESSINFOENDIDXOFGWTXPDUDESCRIPTIONINFO     STD_OFF  /**< Deactivateable: 'Com_GwTxPduDescriptionInfo.GwDescriptionAccessInfoEndIdx' Reason: 'Gateway description feature is not licensed' */
#define COM_GWDESCRIPTIONACCESSINFOSTARTIDXOFGWTXPDUDESCRIPTIONINFO   STD_OFF  /**< Deactivateable: 'Com_GwTxPduDescriptionInfo.GwDescriptionAccessInfoStartIdx' Reason: 'Gateway description feature is not licensed' */
#define COM_HANDLERXDEFERREDGWDESCRIPTION                             STD_OFF  /**< Deactivateable: 'Com_HandleRxDeferredGwDescription' Reason: 'Gateway description feature is not licensed' */
#define COM_HANDLERXPDUDEFERRED                                       STD_ON
#define COM_HANDLETXPDUDEFERRED                                       STD_OFF  /**< Deactivateable: 'Com_HandleTxPduDeferred' Reason: 'This array is deactivated, because no Tx notification functions for deferred signal processing are configured.' */
#define COM_IPDUGROUPINFO                                             STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_IPDUGROUPINFOTOSUBIPDUGROUPSINDENDIDXOFIPDUGROUPINFO      STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo.IPduGroupInfoToSubIPduGroupsIndEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_IPDUGROUPINFOTOSUBIPDUGROUPSINDSTARTIDXOFIPDUGROUPINFO    STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo.IPduGroupInfoToSubIPduGroupsIndStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_IPDUGROUPINFOTOSUBIPDUGROUPSINDUSEDOFIPDUGROUPINFO        STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo.IPduGroupInfoToSubIPduGroupsIndUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_INVALIDHNDOFIPDUGROUPINFO                                 STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo.InvalidHnd' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_RXPDUINFOINDENDIDXOFIPDUGROUPINFO                         STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo.RxPduInfoIndEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_RXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                       STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo.RxPduInfoIndStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_RXPDUINFOINDUSEDOFIPDUGROUPINFO                           STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo.RxPduInfoIndUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_TXPDUINFOINDENDIDXOFIPDUGROUPINFO                         STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo.TxPduInfoIndEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_TXPDUINFOINDSTARTIDXOFIPDUGROUPINFO                       STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo.TxPduInfoIndStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_TXPDUINFOINDUSEDOFIPDUGROUPINFO                           STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfo.TxPduInfoIndUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_IPDUGROUPINFOOFRXPDUINFOIND                               STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfoOfRxPduInfoInd' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_IPDUGROUPINFOOFTXPDUINFOIND                               STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfoOfTxPduInfoInd' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_IPDUGROUPINFOTOSUBIPDUGROUPSIND                           STD_OFF  /**< Deactivateable: 'Com_IPduGroupInfoToSubIPduGroupsInd' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_IPDUGROUPSTATE                                            STD_OFF  /**< Deactivateable: 'Com_IPduGroupState' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComOptimizedIPduGroupHandling] is configured to 'false'' */
#define COM_INITDATAHASHCODE                                          STD_OFF  /**< Deactivateable: 'Com_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define COM_INITIALIZED                                               STD_ON
#define COM_PDUGRPCNT                                                 STD_ON
#define COM_PDUGRPVECTOR                                              STD_ON
#define COM_REPCNT                                                    STD_ON
#define COM_REPCYCLECNT                                               STD_ON
#define COM_RXACCESSINFO                                              STD_ON
#define COM_APPLTYPEOFRXACCESSINFO                                    STD_ON
#define COM_BITLENGTHOFRXACCESSINFO                                   STD_ON
#define COM_BITPOSITIONOFRXACCESSINFO                                 STD_ON
#define COM_BUFFERIDXOFRXACCESSINFO                                   STD_ON
#define COM_BUFFERUSEDOFRXACCESSINFO                                  STD_ON
#define COM_BUSACCOFRXACCESSINFO                                      STD_ON
#define COM_BYTELENGTHOFRXACCESSINFO                                  STD_ON
#define COM_BYTEPOSITIONOFRXACCESSINFO                                STD_ON
#define COM_CONSTVALUEARRAYBASEDINITVALUEENDIDXOFRXACCESSINFO         STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedInitValueEndIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInitValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINITVALUELENGTHOFRXACCESSINFO         STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedInitValueLength' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInitValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINITVALUESTARTIDXOFRXACCESSINFO       STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedInitValueStartIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInitValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINITVALUEUSEDOFRXACCESSINFO           STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedInitValueUsed' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInitValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINVVALUEENDIDXOFRXACCESSINFO          STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedInvValueEndIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINVVALUELENGTHOFRXACCESSINFO          STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedInvValueLength' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINVVALUESTARTIDXOFRXACCESSINFO        STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedInvValueStartIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINVVALUEUSEDOFRXACCESSINFO            STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedInvValueUsed' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDRXDATATIMEOUTSUBSTITUTIONVALUEENDIDXOFRXACCESSINFO STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedRxDataTimeoutSubstitutionValueEndIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedRxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDRXDATATIMEOUTSUBSTITUTIONVALUELENGTHOFRXACCESSINFO STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedRxDataTimeoutSubstitutionValueLength' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedRxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDRXDATATIMEOUTSUBSTITUTIONVALUESTARTIDXOFRXACCESSINFO STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedRxDataTimeoutSubstitutionValueStartIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedRxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDRXDATATIMEOUTSUBSTITUTIONVALUEUSEDOFRXACCESSINFO STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ConstValueArrayBasedRxDataTimeoutSubstitutionValueUsed' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedRxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_FILTERINFOIDXOFRXACCESSINFO                               STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.FilterInfoIdx' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_FILTERINFOUSEDOFRXACCESSINFO                              STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.FilterInfoUsed' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_GWINFOIDXOFRXACCESSINFO                                   STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.GwInfoIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWINFOUSEDOFRXACCESSINFO                                  STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.GwInfoUsed' Reason: 'The gateway is deactivated!' */
#define COM_INITVALUEIDXOFRXACCESSINFO                                STD_ON
#define COM_INITVALUEUSEDOFRXACCESSINFO                               STD_ON
#define COM_INVVALUEIDXOFRXACCESSINFO                                 STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.InvValueIdx' Reason: 'the optional indirection is deactivated because InvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_INVVALUEUSEDOFRXACCESSINFO                                STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.InvValueUsed' Reason: 'the optional indirection is deactivated because InvValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_INVALIDHNDOFRXACCESSINFO                                  STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.InvalidHnd' Reason: 'the value of Com_InvalidHndOfRxAccessInfo is always 'false' due to this, the array is deactivated.' */
#define COM_ISGROUPSIGNALOFRXACCESSINFO                               STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.IsGroupSignal' Reason: 'the value of Com_IsGroupSignalOfRxAccessInfo is always 'false' due to this, the array is deactivated.' */
#define COM_ROUTINGBUFFERIDXOFRXACCESSINFO                            STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RoutingBufferIdx' Reason: 'The gateway is deactivated!' */
#define COM_ROUTINGBUFFERUSEDOFRXACCESSINFO                           STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RoutingBufferUsed' Reason: 'The gateway is deactivated!' */
#define COM_RXDATATIMEOUTSUBSTITUTIONVALUEIDXOFRXACCESSINFO           STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxDataTimeoutSubstitutionValueIdx' Reason: 'the optional indirection is deactivated because RxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXDATATIMEOUTSUBSTITUTIONVALUEUSEDOFRXACCESSINFO          STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxDataTimeoutSubstitutionValueUsed' Reason: 'the optional indirection is deactivated because RxDataTimeoutSubstitutionValueUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXPDUINFOIDXOFRXACCESSINFO                                STD_ON
#define COM_RXSIGBUFFERARRAYBASEDBUFFERENDIDXOFRXACCESSINFO           STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedBufferEndIdx' Reason: 'the optional indirection is deactivated because RxSigBufferArrayBasedBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGBUFFERARRAYBASEDBUFFERLENGTHOFRXACCESSINFO           STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedBufferLength' Reason: 'the optional indirection is deactivated because RxSigBufferArrayBasedBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGBUFFERARRAYBASEDBUFFERSTARTIDXOFRXACCESSINFO         STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedBufferStartIdx' Reason: 'the optional indirection is deactivated because RxSigBufferArrayBasedBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGBUFFERARRAYBASEDBUFFERUSEDOFRXACCESSINFO             STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedBufferUsed' Reason: 'the optional indirection is deactivated because RxSigBufferArrayBasedBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGBUFFERARRAYBASEDROUTINGBUFFERENDIDXOFRXACCESSINFO    STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedRoutingBufferEndIdx' Reason: 'The gateway is deactivated!' */
#define COM_RXSIGBUFFERARRAYBASEDROUTINGBUFFERLENGTHOFRXACCESSINFO    STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedRoutingBufferLength' Reason: 'The gateway is deactivated!' */
#define COM_RXSIGBUFFERARRAYBASEDROUTINGBUFFERSTARTIDXOFRXACCESSINFO  STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedRoutingBufferStartIdx' Reason: 'The gateway is deactivated!' */
#define COM_RXSIGBUFFERARRAYBASEDROUTINGBUFFERUSEDOFRXACCESSINFO      STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedRoutingBufferUsed' Reason: 'The gateway is deactivated!' */
#define COM_RXSIGBUFFERARRAYBASEDSHDBUFFERENDIDXOFRXACCESSINFO        STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedShdBufferEndIdx' Reason: 'the optional indirection is deactivated because RxSigBufferArrayBasedShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGBUFFERARRAYBASEDSHDBUFFERLENGTHOFRXACCESSINFO        STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedShdBufferLength' Reason: 'the optional indirection is deactivated because RxSigBufferArrayBasedShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGBUFFERARRAYBASEDSHDBUFFERSTARTIDXOFRXACCESSINFO      STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedShdBufferStartIdx' Reason: 'the optional indirection is deactivated because RxSigBufferArrayBasedShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGBUFFERARRAYBASEDSHDBUFFERUSEDOFRXACCESSINFO          STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxSigBufferArrayBasedShdBufferUsed' Reason: 'the optional indirection is deactivated because RxSigBufferArrayBasedShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXTOUTINFOIDXOFRXACCESSINFO                               STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxTOutInfoIdx' Reason: 'the optional indirection is deactivated because RxTOutInfoUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXTOUTINFOUSEDOFRXACCESSINFO                              STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.RxTOutInfoUsed' Reason: 'the optional indirection is deactivated because RxTOutInfoUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_SHDBUFFERIDXOFRXACCESSINFO                                STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ShdBufferIdx' Reason: 'the optional indirection is deactivated because ShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_SHDBUFFERUSEDOFRXACCESSINFO                               STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.ShdBufferUsed' Reason: 'the optional indirection is deactivated because ShdBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_SIGNEXTREQUIREDOFRXACCESSINFO                             STD_ON
#define COM_STARTBYTEINPDUPOSITIONOFRXACCESSINFO                      STD_ON
#define COM_TMPBUFFERIDXOFRXACCESSINFO                                STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpBufferIdx' Reason: 'the optional indirection is deactivated because TmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TMPBUFFERUSEDOFRXACCESSINFO                               STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpBufferUsed' Reason: 'the optional indirection is deactivated because TmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TMPRXSHDBUFFERARRAYBASEDTMPBUFFERENDIDXOFRXACCESSINFO     STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpRxShdBufferArrayBasedTmpBufferEndIdx' Reason: 'the optional indirection is deactivated because TmpRxShdBufferArrayBasedTmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TMPRXSHDBUFFERARRAYBASEDTMPBUFFERLENGTHOFRXACCESSINFO     STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpRxShdBufferArrayBasedTmpBufferLength' Reason: 'the optional indirection is deactivated because TmpRxShdBufferArrayBasedTmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TMPRXSHDBUFFERARRAYBASEDTMPBUFFERSTARTIDXOFRXACCESSINFO   STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpRxShdBufferArrayBasedTmpBufferStartIdx' Reason: 'the optional indirection is deactivated because TmpRxShdBufferArrayBasedTmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TMPRXSHDBUFFERARRAYBASEDTMPBUFFERUSEDOFRXACCESSINFO       STD_OFF  /**< Deactivateable: 'Com_RxAccessInfo.TmpRxShdBufferArrayBasedTmpBufferUsed' Reason: 'the optional indirection is deactivated because TmpRxShdBufferArrayBasedTmpBufferUsedOfRxAccessInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXACCESSINFOGRPSIGIND                                     STD_OFF  /**< Deactivateable: 'Com_RxAccessInfoGrpSigInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXACCESSINFOIND                                           STD_ON
#define COM_RXACCESSINFOREPLACEGRPSIGIND                              STD_OFF  /**< Deactivateable: 'Com_RxAccessInfoReplaceGrpSigInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXACCESSINFOREPLACESIGIND                                 STD_OFF  /**< Deactivateable: 'Com_RxAccessInfoReplaceSigInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXCBKFUNCPTR                                              STD_OFF  /**< Deactivateable: 'Com_RxCbkFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXDEADLINEMONITORINGISRLOCKCOUNTER                        STD_ON
#define COM_RXDEADLINEMONITORINGISRLOCKTHRESHOLD                      STD_OFF  /**< Deactivateable: 'Com_RxDeadlineMonitoringISRLockThreshold' Reason: 'No Rx Signals or SignalGroups with a configured timeout are present. ' */
#define COM_RXDEFPDUBUFFER                                            STD_ON
#define COM_RXDEFERREDEVENTCACHE                                      STD_OFF  /**< Deactivateable: 'Com_RxDeferredEventCache' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDeferredEventCacheSupport] is configured to 'false'' */
#define COM_RXDEFERREDFCTPTRCACHE                                     STD_OFF  /**< Deactivateable: 'Com_RxDeferredFctPtrCache' Reason: 'Deactivate cache as cache size is set to zero' */
#define COM_RXDEFERREDPROCESSINGISRLOCKCOUNTER                        STD_ON
#define COM_RXDEFERREDPROCESSINGISRLOCKTHRESHOLD                      STD_ON
#define COM_RXDLMONDIVISOR                                            STD_OFF  /**< Deactivateable: 'Com_RxDlMonDivisor' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMainfunctionTimingDomainSupport] is configured to 'false'' */
#define COM_RXDLMONDIVISORCOUNTER                                     STD_OFF  /**< Deactivateable: 'Com_RxDlMonDivisorCounter' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMainfunctionTimingDomainSupport] is configured to 'false'' */
#define COM_RXDYNSIGNALLENGTH                                         STD_OFF  /**< Deactivateable: 'Com_RxDynSignalLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXDYNSIGNALTMPLENGTHFORSIGNALGROUPS                       STD_OFF  /**< Deactivateable: 'Com_RxDynSignalTmpLengthForSignalGroups' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXIPDUGROUPISRLOCKCOUNTER                                 STD_ON
#define COM_RXIPDUGROUPISRLOCKTHRESHOLD                               STD_ON
#define COM_RXNEXTEVENTCACHEENTY                                      STD_OFF  /**< Deactivateable: 'Com_RxNextEventCacheEnty' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDeferredEventCacheSupport] is configured to 'false'' */
#define COM_RXPDUCALLOUTFUNCPTR                                       STD_OFF  /**< Deactivateable: 'Com_RxPduCalloutFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXPDUDMSTATE                                              STD_OFF  /**< Deactivateable: 'Com_RxPduDmState' Reason: 'This array is deactivated, because no Rx timeout is configured.' */
#define COM_RXPDUGRPACTIVE                                            STD_ON
#define COM_RXPDUGRPINFO                                              STD_ON
#define COM_PDUGRPVECTORENDIDXOFRXPDUGRPINFO                          STD_ON
#define COM_PDUGRPVECTORSTARTIDXOFRXPDUGRPINFO                        STD_ON
#define COM_PDUGRPVECTORUSEDOFRXPDUGRPINFO                            STD_ON
#define COM_RXPDUINFO                                                 STD_ON
#define COM_DEFERREDGWMAPPINGINFOIDXOFRXPDUINFO                       STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.DeferredGwMappingInfoIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionRoutingCodeGeneration] is configured to 'false'' */
#define COM_DEFERREDGWMAPPINGINFOUSEDOFRXPDUINFO                      STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.DeferredGwMappingInfoUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComDescriptionRoutingCodeGeneration] is configured to 'false'' */
#define COM_GWINFOENDIDXOFRXPDUINFO                                   STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.GwInfoEndIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWINFOSTARTIDXOFRXPDUINFO                                 STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.GwInfoStartIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWINFOUSEDOFRXPDUINFO                                     STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.GwInfoUsed' Reason: 'The gateway is deactivated!' */
#define COM_GWTXPDUDESCRIPTIONINFOENDIDXOFRXPDUINFO                   STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.GwTxPduDescriptionInfoEndIdx' Reason: 'Gateway description feature is not licensed' */
#define COM_GWTXPDUDESCRIPTIONINFOSTARTIDXOFRXPDUINFO                 STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.GwTxPduDescriptionInfoStartIdx' Reason: 'Gateway description feature is not licensed' */
#define COM_GWTXPDUDESCRIPTIONINFOUSEDOFRXPDUINFO                     STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.GwTxPduDescriptionInfoUsed' Reason: 'Gateway description feature is not licensed' */
#define COM_HANDLERXDEFERREDGWDESCRIPTIONIDXOFRXPDUINFO               STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.HandleRxDeferredGwDescriptionIdx' Reason: 'Gateway description feature is not licensed' */
#define COM_HANDLERXDEFERREDGWDESCRIPTIONUSEDOFRXPDUINFO              STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.HandleRxDeferredGwDescriptionUsed' Reason: 'Gateway description feature is not licensed' */
#define COM_HANDLERXPDUDEFERREDIDXOFRXPDUINFO                         STD_ON
#define COM_HANDLERXPDUDEFERREDUSEDOFRXPDUINFO                        STD_ON
#define COM_IPDUGROUPINFOOFRXPDUINFOINDENDIDXOFRXPDUINFO              STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.IPduGroupInfoOfRxPduInfoIndEndIdx' Reason: 'the optional indirection is deactivated because IPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_IPDUGROUPINFOOFRXPDUINFOINDSTARTIDXOFRXPDUINFO            STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.IPduGroupInfoOfRxPduInfoIndStartIdx' Reason: 'the optional indirection is deactivated because IPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_IPDUGROUPINFOOFRXPDUINFOINDUSEDOFRXPDUINFO                STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.IPduGroupInfoOfRxPduInfoIndUsed' Reason: 'the optional indirection is deactivated because IPduGroupInfoOfRxPduInfoIndUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_INVALIDHNDOFRXPDUINFO                                     STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.InvalidHnd' Reason: 'the value of Com_InvalidHndOfRxPduInfo is always 'false' due to this, the array is deactivated.' */
#define COM_RXACCESSINFOINDENDIDXOFRXPDUINFO                          STD_ON
#define COM_RXACCESSINFOINDSTARTIDXOFRXPDUINFO                        STD_ON
#define COM_RXACCESSINFOINDUSEDOFRXPDUINFO                            STD_ON
#define COM_RXDEFPDUBUFFERENDIDXOFRXPDUINFO                           STD_ON
#define COM_RXDEFPDUBUFFERLENGTHOFRXPDUINFO                           STD_ON
#define COM_RXDEFPDUBUFFERSTARTIDXOFRXPDUINFO                         STD_ON
#define COM_RXDEFPDUBUFFERUSEDOFRXPDUINFO                             STD_ON
#define COM_RXPDUCALLOUTFUNCPTRIDXOFRXPDUINFO                         STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxPduCalloutFuncPtrIdx' Reason: 'the optional indirection is deactivated because RxPduCalloutFuncPtrUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXPDUCALLOUTFUNCPTRUSEDOFRXPDUINFO                        STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxPduCalloutFuncPtrUsed' Reason: 'the optional indirection is deactivated because RxPduCalloutFuncPtrUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGGRPINFOINDENDIDXOFRXPDUINFO                          STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxSigGrpInfoIndEndIdx' Reason: 'the optional indirection is deactivated because RxSigGrpInfoIndUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGGRPINFOINDSTARTIDXOFRXPDUINFO                        STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxSigGrpInfoIndStartIdx' Reason: 'the optional indirection is deactivated because RxSigGrpInfoIndUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGGRPINFOINDUSEDOFRXPDUINFO                            STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxSigGrpInfoIndUsed' Reason: 'the optional indirection is deactivated because RxSigGrpInfoIndUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXSIGINFOENDIDXOFRXPDUINFO                                STD_ON
#define COM_RXSIGINFOSTARTIDXOFRXPDUINFO                              STD_ON
#define COM_RXSIGINFOUSEDOFRXPDUINFO                                  STD_ON
#define COM_RXTOUTINFOIDXOFRXPDUINFO                                  STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxTOutInfoIdx' Reason: 'the optional indirection is deactivated because RxTOutInfoUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXTOUTINFOINDENDIDXOFRXPDUINFO                            STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxTOutInfoIndEndIdx' Reason: 'the optional indirection is deactivated because RxTOutInfoIndUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXTOUTINFOINDSTARTIDXOFRXPDUINFO                          STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxTOutInfoIndStartIdx' Reason: 'the optional indirection is deactivated because RxTOutInfoIndUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXTOUTINFOINDUSEDOFRXPDUINFO                              STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxTOutInfoIndUsed' Reason: 'the optional indirection is deactivated because RxTOutInfoIndUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXTOUTINFOUSEDOFRXPDUINFO                                 STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxTOutInfoUsed' Reason: 'the optional indirection is deactivated because RxTOutInfoUsedOfRxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXTPINFOIDXOFRXPDUINFO                                    STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxTpInfoIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPINFOUSEDOFRXPDUINFO                                   STD_OFF  /**< Deactivateable: 'Com_RxPduInfo.RxTpInfoUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_SIGNALPROCESSINGOFRXPDUINFO                               STD_ON
#define COM_TYPEOFRXPDUINFO                                           STD_ON
#define COM_RXPDUINFOIND                                              STD_OFF  /**< Deactivateable: 'Com_RxPduInfoInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGARRAYACCESSSIGGRPBUFFER                              STD_OFF  /**< Deactivateable: 'Com_RxSigArrayAccessSigGrpBuffer' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERARRAYBASED                                     STD_OFF  /**< Deactivateable: 'Com_RxSigBufferArrayBased' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERFLOAT32                                        STD_ON
#define COM_RXSIGBUFFERFLOAT64                                        STD_OFF  /**< Deactivateable: 'Com_RxSigBufferFloat64' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERSINT16                                         STD_ON
#define COM_RXSIGBUFFERSINT32                                         STD_OFF  /**< Deactivateable: 'Com_RxSigBufferSInt32' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERSINT64                                         STD_OFF  /**< Deactivateable: 'Com_RxSigBufferSInt64' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERSINT8                                          STD_OFF  /**< Deactivateable: 'Com_RxSigBufferSInt8' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERUINT16                                         STD_ON
#define COM_RXSIGBUFFERUINT32                                         STD_OFF  /**< Deactivateable: 'Com_RxSigBufferUInt32' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERUINT64                                         STD_OFF  /**< Deactivateable: 'Com_RxSigBufferUInt64' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERUINT8                                          STD_ON
#define COM_RXSIGBUFFERZEROBIT                                        STD_OFF  /**< Deactivateable: 'Com_RxSigBufferZeroBit' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGGRPINFO                                              STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_ARRAYACCESSUSEDOFRXSIGGRPINFO                             STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ArrayAccessUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUESIGGRPARRAYACCESSENDIDXOFRXSIGGRPINFO           STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueSigGrpArrayAccessEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESIGGRPARRAYACCESSLENGTHOFRXSIGGRPINFO           STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueSigGrpArrayAccessLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESIGGRPARRAYACCESSSTARTIDXOFRXSIGGRPINFO         STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueSigGrpArrayAccessStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUESIGGRPARRAYACCESSUSEDOFRXSIGGRPINFO             STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueSigGrpArrayAccessUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEUINT8ENDIDXOFRXSIGGRPINFO                       STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueUInt8EndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEUINT8LENGTHOFRXSIGGRPINFO                       STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueUInt8Length' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEUINT8STARTIDXOFRXSIGGRPINFO                     STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueUInt8StartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CONSTVALUEUINT8USEDOFRXSIGGRPINFO                         STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ConstValueUInt8Used' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FILTEREVENTOFRXSIGGRPINFO                                 STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.FilterEvent' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_GWINFOIDXOFRXSIGGRPINFO                                   STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.GwInfoIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWINFOUSEDOFRXSIGGRPINFO                                  STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.GwInfoUsed' Reason: 'The gateway is deactivated!' */
#define COM_INVEVENTOFRXSIGGRPINFO                                    STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.InvEvent' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_INVALIDHNDOFRXSIGGRPINFO                                  STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXACCESSINFOGRPSIGINDENDIDXOFRXSIGGRPINFO                 STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxAccessInfoGrpSigIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXACCESSINFOGRPSIGINDSTARTIDXOFRXSIGGRPINFO               STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxAccessInfoGrpSigIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXACCESSINFOGRPSIGINDUSEDOFRXSIGGRPINFO                   STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxAccessInfoGrpSigIndUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXCBKFUNCPTRACKIDXOFRXSIGGRPINFO                          STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxCbkFuncPtrAckIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXCBKFUNCPTRACKUSEDOFRXSIGGRPINFO                         STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxCbkFuncPtrAckUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXCBKFUNCPTRINVACKIDXOFRXSIGGRPINFO                       STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxCbkFuncPtrInvAckIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXCBKFUNCPTRINVACKUSEDOFRXSIGGRPINFO                      STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxCbkFuncPtrInvAckUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXPDUINFOIDXOFRXSIGGRPINFO                                STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxPduInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGARRAYACCESSSIGGRPBUFFERENDIDXOFRXSIGGRPINFO          STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigArrayAccessSigGrpBufferEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGARRAYACCESSSIGGRPBUFFERLENGTHOFRXSIGGRPINFO          STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigArrayAccessSigGrpBufferLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGARRAYACCESSSIGGRPBUFFERSTARTIDXOFRXSIGGRPINFO        STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigArrayAccessSigGrpBufferStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGARRAYACCESSSIGGRPBUFFERUSEDOFRXSIGGRPINFO            STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigArrayAccessSigGrpBufferUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERUINT8ENDIDXOFRXSIGGRPINFO                      STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigBufferUInt8EndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERUINT8LENGTHOFRXSIGGRPINFO                      STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigBufferUInt8Length' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERUINT8STARTIDXOFRXSIGGRPINFO                    STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigBufferUInt8StartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGBUFFERUINT8USEDOFRXSIGGRPINFO                        STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxSigBufferUInt8Used' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXTOUTINFOIDXOFRXSIGGRPINFO                               STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxTOutInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXTOUTINFOUSEDOFRXSIGGRPINFO                              STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.RxTOutInfoUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_SHDBUFFERREQUIREDOFRXSIGGRPINFO                           STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ShdBufferRequired' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_SIGNALPROCESSINGOFRXSIGGRPINFO                            STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.SignalProcessing' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_STARTBYTEPOSITIONOFRXSIGGRPINFO                           STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.StartBytePosition' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_UBIDXOFRXSIGGRPINFO                                       STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.UbIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_UBMASKIDXOFRXSIGGRPINFO                                   STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.UbMaskIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_UBMASKUSEDOFRXSIGGRPINFO                                  STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.UbMaskUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_VALIDDLCOFRXSIGGRPINFO                                    STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.ValidDlc' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGGRPINFOIND                                           STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfoInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXSIGINFO                                                 STD_ON
#define COM_GWINFOIDXOFRXSIGINFO                                      STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.GwInfoIdx' Reason: 'The gateway is deactivated!' */
#define COM_GWINFOUSEDOFRXSIGINFO                                     STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.GwInfoUsed' Reason: 'The gateway is deactivated!' */
#define COM_RXACCESSINFOIDXOFRXSIGINFO                                STD_ON
#define COM_RXCBKFUNCPTRACKIDXOFRXSIGINFO                             STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.RxCbkFuncPtrAckIdx' Reason: 'the optional indirection is deactivated because RxCbkFuncPtrAckUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXCBKFUNCPTRACKUSEDOFRXSIGINFO                            STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.RxCbkFuncPtrAckUsed' Reason: 'the optional indirection is deactivated because RxCbkFuncPtrAckUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXCBKFUNCPTRINVACKIDXOFRXSIGINFO                          STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.RxCbkFuncPtrInvAckIdx' Reason: 'the optional indirection is deactivated because RxCbkFuncPtrInvAckUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXCBKFUNCPTRINVACKUSEDOFRXSIGINFO                         STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.RxCbkFuncPtrInvAckUsed' Reason: 'the optional indirection is deactivated because RxCbkFuncPtrInvAckUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXTOUTINFOIDXOFRXSIGINFO                                  STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.RxTOutInfoIdx' Reason: 'the optional indirection is deactivated because RxTOutInfoUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_RXTOUTINFOUSEDOFRXSIGINFO                                 STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.RxTOutInfoUsed' Reason: 'the optional indirection is deactivated because RxTOutInfoUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_SIGNALPROCESSINGOFRXSIGINFO                               STD_ON
#define COM_UBIDXOFRXSIGINFO                                          STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.UbIdx' Reason: 'the value of Com_UbIdxOfRxSigInfo is always 'COM_NO_UBIDXOFRXSIGINFO' due to this, the array is deactivated.' */
#define COM_UBMASKIDXOFRXSIGINFO                                      STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.UbMaskIdx' Reason: 'the optional indirection is deactivated because UbMaskUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_UBMASKUSEDOFRXSIGINFO                                     STD_OFF  /**< Deactivateable: 'Com_RxSigInfo.UbMaskUsed' Reason: 'the optional indirection is deactivated because UbMaskUsedOfRxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_VALIDDLCOFRXSIGINFO                                       STD_ON
#define COM_RXTOUTCNT                                                 STD_OFF  /**< Deactivateable: 'Com_RxTOutCnt' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXTOUTINFO                                                STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_CBKRXTOUTFUNCPTRINDENDIDXOFRXTOUTINFO                     STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.CbkRxTOutFuncPtrIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKRXTOUTFUNCPTRINDSTARTIDXOFRXTOUTINFO                   STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.CbkRxTOutFuncPtrIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKRXTOUTFUNCPTRINDUSEDOFRXTOUTINFO                       STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.CbkRxTOutFuncPtrIndUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FACTOROFRXTOUTINFO                                        STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.Factor' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FIRSTFACTOROFRXTOUTINFO                                   STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.FirstFactor' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXACCESSINFOREPLACEGRPSIGINDENDIDXOFRXTOUTINFO            STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceGrpSigIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXACCESSINFOREPLACEGRPSIGINDSTARTIDXOFRXTOUTINFO          STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceGrpSigIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXACCESSINFOREPLACEGRPSIGINDUSEDOFRXTOUTINFO              STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceGrpSigIndUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXACCESSINFOREPLACESIGINDENDIDXOFRXTOUTINFO               STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceSigIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXACCESSINFOREPLACESIGINDSTARTIDXOFRXTOUTINFO             STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceSigIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXACCESSINFOREPLACESIGINDUSEDOFRXTOUTINFO                 STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxAccessInfoReplaceSigIndUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXPDUINFOIDXOFRXTOUTINFO                                  STD_OFF  /**< Deactivateable: 'Com_RxTOutInfo.RxPduInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXTOUTINFOIND                                             STD_OFF  /**< Deactivateable: 'Com_RxTOutInfoInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_RXTPBUFFER                                                STD_OFF  /**< Deactivateable: 'Com_RxTpBuffer' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPCONNECTIONSTATE                                       STD_OFF  /**< Deactivateable: 'Com_RxTpConnectionState' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPINFO                                                  STD_OFF  /**< Deactivateable: 'Com_RxTpInfo' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_BUFFERSIZEOFRXTPINFO                                      STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.BufferSize' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_DYNAMICINITIALLENGTHOFRXTPINFO                            STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.DynamicInitialLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXACCESSINFODYNSIGIDXOFRXTPINFO                           STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxAccessInfoDynSigIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXACCESSINFODYNSIGUSEDOFRXTPINFO                          STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxAccessInfoDynSigUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPBUFFERENDIDXOFRXTPINFO                                STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxTpBufferEndIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPBUFFERSTARTIDXOFRXTPINFO                              STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxTpBufferStartIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPBUFFERUSEDOFRXTPINFO                                  STD_OFF  /**< Deactivateable: 'Com_RxTpInfo.RxTpBufferUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPSDULENGTH                                             STD_OFF  /**< Deactivateable: 'Com_RxTpSduLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_RXTPWRITTENBYTESCOUNTER                                   STD_OFF  /**< Deactivateable: 'Com_RxTpWrittenBytesCounter' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_SIGGRPARRAYFILTERINFO                                     STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERMASKENDIDXOFSIGGRPARRAYFILTERINFO    STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterMaskEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERMASKLENGTHOFSIGGRPARRAYFILTERINFO    STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterMaskLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERMASKSTARTIDXOFSIGGRPARRAYFILTERINFO  STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterMaskStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERMASKUSEDOFSIGGRPARRAYFILTERINFO      STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterMaskUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERVALUEXENDIDXOFSIGGRPARRAYFILTERINFO  STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterValueXEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERVALUEXLENGTHOFSIGGRPARRAYFILTERINFO  STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterValueXLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERVALUEXSTARTIDXOFSIGGRPARRAYFILTERINFO STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterValueXStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_CONSTVALUEUINT8FILTERVALUEXUSEDOFSIGGRPARRAYFILTERINFO    STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.ConstValueUInt8FilterValueXUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_FILTERALGOOFSIGGRPARRAYFILTERINFO                         STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_OFFSETINSIGNALGROUPOFSIGGRPARRAYFILTERINFO                STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.OffsetInSignalGroup' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGRPEVENTFLAG                                           STD_ON
#define COM_SIZEOFACTIVATABLERXCOMIPDUS                               STD_ON
#define COM_SIZEOFACTIVATABLETXCOMIPDUS                               STD_ON
#define COM_SIZEOFCONSTVALUEFLOAT32                                   STD_ON
#define COM_SIZEOFCONSTVALUESINT16                                    STD_ON
#define COM_SIZEOFCONSTVALUEUINT16                                    STD_ON
#define COM_SIZEOFCONSTVALUEUINT8                                     STD_ON
#define COM_SIZEOFCURRENTTXMODE                                       STD_ON
#define COM_SIZEOFCYCLETIMECNT                                        STD_ON
#define COM_SIZEOFCYCLICSENDREQUEST                                   STD_ON
#define COM_SIZEOFDELAYTIMECNT                                        STD_ON
#define COM_SIZEOFHANDLERXPDUDEFERRED                                 STD_ON
#define COM_SIZEOFPDUGRPVECTOR                                        STD_ON
#define COM_SIZEOFREPCNT                                              STD_ON
#define COM_SIZEOFREPCYCLECNT                                         STD_ON
#define COM_SIZEOFRXACCESSINFO                                        STD_ON
#define COM_SIZEOFRXACCESSINFOIND                                     STD_ON
#define COM_SIZEOFRXDEFPDUBUFFER                                      STD_ON
#define COM_SIZEOFRXPDUGRPACTIVE                                      STD_ON
#define COM_SIZEOFRXPDUGRPINFO                                        STD_ON
#define COM_SIZEOFRXPDUINFO                                           STD_ON
#define COM_SIZEOFRXSIGBUFFERFLOAT32                                  STD_ON
#define COM_SIZEOFRXSIGBUFFERSINT16                                   STD_ON
#define COM_SIZEOFRXSIGBUFFERUINT16                                   STD_ON
#define COM_SIZEOFRXSIGBUFFERUINT8                                    STD_ON
#define COM_SIZEOFRXSIGINFO                                           STD_ON
#define COM_SIZEOFSIGGRPEVENTFLAG                                     STD_ON
#define COM_SIZEOFTRANSMITREQUEST                                     STD_ON
#define COM_SIZEOFTXBUFFER                                            STD_ON
#define COM_SIZEOFTXMODEFALSE                                         STD_ON
#define COM_SIZEOFTXMODEINFO                                          STD_ON
#define COM_SIZEOFTXMODETRUE                                          STD_ON
#define COM_SIZEOFTXPDUGRPACTIVE                                      STD_ON
#define COM_SIZEOFTXPDUGRPINFO                                        STD_ON
#define COM_SIZEOFTXPDUINFO                                           STD_ON
#define COM_SIZEOFTXPDUINITVALUE                                      STD_ON
#define COM_SIZEOFTXSDULENGTH                                         STD_ON
#define COM_SIZEOFTXSIGGRPINFO                                        STD_ON
#define COM_SIZEOFTXSIGGRPINFOIND                                     STD_ON
#define COM_SIZEOFTXSIGGRPMASK                                        STD_ON
#define COM_SIZEOFTXSIGINFO                                           STD_ON
#define COM_SOURCEDESCRIPTIONMASK                                     STD_OFF  /**< Deactivateable: 'Com_SourceDescriptionMask' Reason: 'Gateway description feature is not licensed' */
#define COM_TMPRXBUFFER                                               STD_OFF  /**< Deactivateable: 'Com_TmpRxBuffer' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERARRAYBASED                                  STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferArrayBased' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERFLOAT32                                     STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferFloat32' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERFLOAT64                                     STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferFloat64' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERSINT16                                      STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferSInt16' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERSINT32                                      STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferSInt32' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERSINT64                                      STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferSInt64' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERSINT8                                       STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferSInt8' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERUINT16                                      STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferUInt16' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERUINT32                                      STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferUInt32' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERUINT64                                      STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferUInt64' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TMPRXSHDBUFFERUINT8                                       STD_OFF  /**< Deactivateable: 'Com_TmpRxShdBufferUInt8' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TRANSMITREQUEST                                           STD_ON
#define COM_TXBUFFER                                                  STD_ON
#define COM_TXCYCLECOUNTERDIVISOR                                     STD_OFF  /**< Deactivateable: 'Com_TxCycleCounterDivisor' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMainfunctionTimingDomainSupport] is configured to 'false'' */
#define COM_TXCYCLECOUNTERDIVISORCOUNTER                              STD_OFF  /**< Deactivateable: 'Com_TxCycleCounterDivisorCounter' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMainfunctionTimingDomainSupport] is configured to 'false'' */
#define COM_TXCYCLICPROCESSINGISRLOCKCOUNTER                          STD_ON
#define COM_TXCYCLICPROCESSINGISRLOCKTHRESHOLD                        STD_ON
#define COM_TXDEADLINEMONITORINGISRLOCKCOUNTER                        STD_ON
#define COM_TXDEADLINEMONITORINGISRLOCKTHRESHOLD                      STD_OFF  /**< Deactivateable: 'Com_TxDeadlineMonitoringISRLockThreshold' Reason: 'No Tx Signals or SignalGroups with a configured timeout are present. ' */
#define COM_TXDLMONDIVISOR                                            STD_OFF  /**< Deactivateable: 'Com_TxDlMonDivisor' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMainfunctionTimingDomainSupport] is configured to 'false'' */
#define COM_TXDLMONDIVISORCOUNTER                                     STD_OFF  /**< Deactivateable: 'Com_TxDlMonDivisorCounter' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMainfunctionTimingDomainSupport] is configured to 'false'' */
#define COM_TXDYNSIGNALLENGTH                                         STD_OFF  /**< Deactivateable: 'Com_TxDynSignalLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXFILTERINITSTATE                                         STD_OFF  /**< Deactivateable: 'Com_TxFilterInitState' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEARRAYBASED                               STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueArrayBased' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEFLOAT32                                  STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueFloat32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEFLOAT64                                  STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueFloat64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUESINT16                                   STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueSInt16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUESINT32                                   STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueSInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUESINT64                                   STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueSInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUESINT8                                    STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueSInt8' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUESIGGRPARRAYACCESS                        STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueSigGrpArrayAccess' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEUINT16                                   STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueUInt16' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEUINT32                                   STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueUInt32' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEUINT64                                   STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueUInt64' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERINITVALUEUINT8                                    STD_OFF  /**< Deactivateable: 'Com_TxFilterInitValueUInt8' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUEARRAYBASED                                STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueArrayBased' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUEFLOAT32                                   STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueFloat32' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUEFLOAT64                                   STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueFloat64' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUESINT16                                    STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueSInt16' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUESINT32                                    STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueSInt32' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUESINT64                                    STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueSInt64' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUESINT8                                     STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueSInt8' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUEUINT16                                    STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueUInt16' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUEUINT32                                    STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueUInt32' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUEUINT64                                    STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueUInt64' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTEROLDVALUEUINT8                                     STD_OFF  /**< Deactivateable: 'Com_TxFilterOldValueUInt8' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXFILTERSTATE                                             STD_OFF  /**< Deactivateable: 'Com_TxFilterState' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXIPDUGROUPISRLOCKCOUNTER                                 STD_ON
#define COM_TXIPDUGROUPISRLOCKTHRESHOLD                               STD_ON
#define COM_TXMODEFALSE                                               STD_ON
#define COM_DIRECTOFTXMODEFALSE                                       STD_OFF  /**< Deactivateable: 'Com_TxModeFalse.Direct' Reason: 'the value of Com_DirectOfTxModeFalse is always 'false' due to this, the array is deactivated.' */
#define COM_PERIODICOFTXMODEFALSE                                     STD_ON
#define COM_REPCNTOFTXMODEFALSE                                       STD_OFF  /**< Deactivateable: 'Com_TxModeFalse.RepCnt' Reason: 'the value of Com_RepCntOfTxModeFalse is always '0' due to this, the array is deactivated.' */
#define COM_REPPERIODOFTXMODEFALSE                                    STD_OFF  /**< Deactivateable: 'Com_TxModeFalse.RepPeriod' Reason: 'the value of Com_RepPeriodOfTxModeFalse is always '0' due to this, the array is deactivated.' */
#define COM_TIMEOFFSETOFTXMODEFALSE                                   STD_OFF  /**< Deactivateable: 'Com_TxModeFalse.TimeOffset' Reason: 'the value of Com_TimeOffsetOfTxModeFalse is always '1' due to this, the array is deactivated.' */
#define COM_TIMEPERIODOFTXMODEFALSE                                   STD_ON
#define COM_TXMODEINFO                                                STD_ON
#define COM_INITMODEOFTXMODEINFO                                      STD_ON
#define COM_INVALIDHNDOFTXMODEINFO                                    STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.InvalidHnd' Reason: 'the value of Com_InvalidHndOfTxModeInfo is always 'false' due to this, the array is deactivated.' */
#define COM_MINIMUMDELAYOFTXMODEINFO                                  STD_ON
#define COM_TXFILTERINITSTATEENDIDXOFTXMODEINFO                       STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxFilterInitStateEndIdx' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITSTATESTARTIDXOFTXMODEINFO                     STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxFilterInitStateStartIdx' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITSTATEUSEDOFTXMODEINFO                         STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxFilterInitStateUsed' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXMODEFALSEIDXOFTXMODEINFO                                STD_ON
#define COM_TXMODETRUEIDXOFTXMODEINFO                                 STD_ON
#define COM_TXSIGINFOFILTERINITVALUEINDENDIDXOFTXMODEINFO             STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxSigInfoFilterInitValueIndEndIdx' Reason: 'the optional indirection is deactivated because TxSigInfoFilterInitValueIndUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXSIGINFOFILTERINITVALUEINDSTARTIDXOFTXMODEINFO           STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxSigInfoFilterInitValueIndStartIdx' Reason: 'the optional indirection is deactivated because TxSigInfoFilterInitValueIndUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXSIGINFOFILTERINITVALUEINDUSEDOFTXMODEINFO               STD_OFF  /**< Deactivateable: 'Com_TxModeInfo.TxSigInfoFilterInitValueIndUsed' Reason: 'the optional indirection is deactivated because TxSigInfoFilterInitValueIndUsedOfTxModeInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXMODETRUE                                                STD_ON
#define COM_DIRECTOFTXMODETRUE                                        STD_OFF  /**< Deactivateable: 'Com_TxModeTrue.Direct' Reason: 'the value of Com_DirectOfTxModeTrue is always 'false' due to this, the array is deactivated.' */
#define COM_PERIODICOFTXMODETRUE                                      STD_ON
#define COM_REPCNTOFTXMODETRUE                                        STD_OFF  /**< Deactivateable: 'Com_TxModeTrue.RepCnt' Reason: 'the value of Com_RepCntOfTxModeTrue is always '0' due to this, the array is deactivated.' */
#define COM_REPPERIODOFTXMODETRUE                                     STD_OFF  /**< Deactivateable: 'Com_TxModeTrue.RepPeriod' Reason: 'the value of Com_RepPeriodOfTxModeTrue is always '0' due to this, the array is deactivated.' */
#define COM_TIMEOFFSETOFTXMODETRUE                                    STD_OFF  /**< Deactivateable: 'Com_TxModeTrue.TimeOffset' Reason: 'the value of Com_TimeOffsetOfTxModeTrue is always '1' due to this, the array is deactivated.' */
#define COM_TIMEPERIODOFTXMODETRUE                                    STD_ON
#define COM_TXPDUCALLOUTFUNCPTR                                       STD_OFF  /**< Deactivateable: 'Com_TxPduCalloutFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXPDUGRPACTIVE                                            STD_ON
#define COM_TXPDUGRPINFO                                              STD_ON
#define COM_PDUGRPVECTORENDIDXOFTXPDUGRPINFO                          STD_ON
#define COM_PDUGRPVECTORSTARTIDXOFTXPDUGRPINFO                        STD_ON
#define COM_PDUGRPVECTORUSEDOFTXPDUGRPINFO                            STD_ON
#define COM_TXPDUINFO                                                 STD_ON
#define COM_CANCELLATIONSUPPORTOFTXPDUINFO                            STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CancellationSupport' Reason: '/ActiveEcuC/PduR/Com[0:PduRCancelTransmit] is configured to 'false'' */
#define COM_CBKTXACKDEFFUNCPTRINDENDIDXOFTXPDUINFO                    STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckDefFuncPtrIndEndIdx' Reason: 'the optional indirection is deactivated because CbkTxAckDefFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXACKDEFFUNCPTRINDSTARTIDXOFTXPDUINFO                  STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckDefFuncPtrIndStartIdx' Reason: 'the optional indirection is deactivated because CbkTxAckDefFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXACKDEFFUNCPTRINDUSEDOFTXPDUINFO                      STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckDefFuncPtrIndUsed' Reason: 'the optional indirection is deactivated because CbkTxAckDefFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXACKIMFUNCPTRINDENDIDXOFTXPDUINFO                     STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckImFuncPtrIndEndIdx' Reason: 'the optional indirection is deactivated because CbkTxAckImFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXACKIMFUNCPTRINDSTARTIDXOFTXPDUINFO                   STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckImFuncPtrIndStartIdx' Reason: 'the optional indirection is deactivated because CbkTxAckImFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXACKIMFUNCPTRINDUSEDOFTXPDUINFO                       STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxAckImFuncPtrIndUsed' Reason: 'the optional indirection is deactivated because CbkTxAckImFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXERRFUNCPTRINDENDIDXOFTXPDUINFO                       STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxErrFuncPtrIndEndIdx' Reason: 'the optional indirection is deactivated because CbkTxErrFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXERRFUNCPTRINDSTARTIDXOFTXPDUINFO                     STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxErrFuncPtrIndStartIdx' Reason: 'the optional indirection is deactivated because CbkTxErrFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CBKTXERRFUNCPTRINDUSEDOFTXPDUINFO                         STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.CbkTxErrFuncPtrIndUsed' Reason: 'the optional indirection is deactivated because CbkTxErrFuncPtrIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CLRUBOFTXPDUINFO                                          STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ClrUb' Reason: 'This array is deactivated, because no Tx I-PDUs with update-bits are configured.' */
#define COM_CONSTVALUEUINT8UBCLEARMASKENDIDXOFTXPDUINFO               STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ConstValueUInt8UbClearMaskEndIdx' Reason: 'the optional indirection is deactivated because ConstValueUInt8UbClearMaskUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEUINT8UBCLEARMASKSTARTIDXOFTXPDUINFO             STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ConstValueUInt8UbClearMaskStartIdx' Reason: 'the optional indirection is deactivated because ConstValueUInt8UbClearMaskUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEUINT8UBCLEARMASKUSEDOFTXPDUINFO                 STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ConstValueUInt8UbClearMaskUsed' Reason: 'the optional indirection is deactivated because ConstValueUInt8UbClearMaskUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_EXTERNALIDOFTXPDUINFO                                     STD_ON
#define COM_GWTIMEOUTINFOIDXOFTXPDUINFO                               STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.GwTimeoutInfoIdx' Reason: 'the optional indirection is deactivated because GwTimeoutInfoUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_GWTIMEOUTINFOUSEDOFTXPDUINFO                              STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.GwTimeoutInfoUsed' Reason: 'the optional indirection is deactivated because GwTimeoutInfoUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_IPDUGROUPINFOOFTXPDUINFOINDENDIDXOFTXPDUINFO              STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.IPduGroupInfoOfTxPduInfoIndEndIdx' Reason: 'the optional indirection is deactivated because IPduGroupInfoOfTxPduInfoIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_IPDUGROUPINFOOFTXPDUINFOINDSTARTIDXOFTXPDUINFO            STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.IPduGroupInfoOfTxPduInfoIndStartIdx' Reason: 'the optional indirection is deactivated because IPduGroupInfoOfTxPduInfoIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_IPDUGROUPINFOOFTXPDUINFOINDUSEDOFTXPDUINFO                STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.IPduGroupInfoOfTxPduInfoIndUsed' Reason: 'the optional indirection is deactivated because IPduGroupInfoOfTxPduInfoIndUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_INVALIDHNDOFTXPDUINFO                                     STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.InvalidHnd' Reason: 'the value of Com_InvalidHndOfTxPduInfo is always 'false' due to this, the array is deactivated.' */
#define COM_METADATALENGTHOFTXPDUINFO                                 STD_ON
#define COM_PDUWITHMETADATALENGTHOFTXPDUINFO                          STD_ON
#define COM_TXBUFFERENDIDXOFTXPDUINFO                                 STD_ON
#define COM_TXBUFFERLENGTHOFTXPDUINFO                                 STD_ON
#define COM_TXBUFFERMETADATAENDIDXOFTXPDUINFO                         STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxBufferMetaDataEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXBUFFERMETADATALENGTHOFTXPDUINFO                         STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxBufferMetaDataLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXBUFFERMETADATASTARTIDXOFTXPDUINFO                       STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxBufferMetaDataStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXBUFFERMETADATAUSEDOFTXPDUINFO                           STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxBufferMetaDataUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXBUFFERSTARTIDXOFTXPDUINFO                               STD_ON
#define COM_TXBUFFERUSEDOFTXPDUINFO                                   STD_ON
#define COM_TXPDUCALLOUTFUNCPTRIDXOFTXPDUINFO                         STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduCalloutFuncPtrIdx' Reason: 'the optional indirection is deactivated because TxPduCalloutFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXPDUCALLOUTFUNCPTRUSEDOFTXPDUINFO                        STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduCalloutFuncPtrUsed' Reason: 'the optional indirection is deactivated because TxPduCalloutFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXPDUINITVALUEENDIDXOFTXPDUINFO                           STD_ON
#define COM_TXPDUINITVALUEMETADATAENDIDXOFTXPDUINFO                   STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduInitValueMetaDataEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXPDUINITVALUEMETADATASTARTIDXOFTXPDUINFO                 STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduInitValueMetaDataStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXPDUINITVALUEMETADATAUSEDOFTXPDUINFO                     STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduInitValueMetaDataUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] is configured to 'false'' */
#define COM_TXPDUINITVALUESTARTIDXOFTXPDUINFO                         STD_ON
#define COM_TXPDUINITVALUEUSEDOFTXPDUINFO                             STD_ON
#define COM_TXPDUTTCALLOUTFUNCPTRIDXOFTXPDUINFO                       STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduTTCalloutFuncPtrIdx' Reason: 'the optional indirection is deactivated because TxPduTTCalloutFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXPDUTTCALLOUTFUNCPTRUSEDOFTXPDUINFO                      STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxPduTTCalloutFuncPtrUsed' Reason: 'the optional indirection is deactivated because TxPduTTCalloutFuncPtrUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXSIGGRPINFOINDENDIDXOFTXPDUINFO                          STD_ON
#define COM_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO                        STD_ON
#define COM_TXSIGGRPINFOINDUSEDOFTXPDUINFO                            STD_ON
#define COM_TXTOUTINFOIDXOFTXPDUINFO                                  STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxTOutInfoIdx' Reason: 'the optional indirection is deactivated because TxTOutInfoUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXTOUTINFOUSEDOFTXPDUINFO                                 STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxTOutInfoUsed' Reason: 'the optional indirection is deactivated because TxTOutInfoUsedOfTxPduInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXTPINFOIDXOFTXPDUINFO                                    STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxTpInfoIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXTPINFOUSEDOFTXPDUINFO                                   STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.TxTpInfoUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXPDUINFOIND                                              STD_OFF  /**< Deactivateable: 'Com_TxPduInfoInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXPDUINITVALUE                                            STD_ON
#define COM_TXPDUTTCALLOUTFUNCPTR                                     STD_OFF  /**< Deactivateable: 'Com_TxPduTTCalloutFuncPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXPROCESSINGISRLOCKCOUNTER                                STD_ON
#define COM_TXPROCESSINGISRLOCKTHRESHOLD                              STD_ON
#define COM_TXSDULENGTH                                               STD_ON
#define COM_TXSIGGRPINFO                                              STD_ON
#define COM_ARRAYACCESSUSEDOFTXSIGGRPINFO                             STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.ArrayAccessUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_INVALIDHNDOFTXSIGGRPINFO                                  STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.InvalidHnd' Reason: 'the value of Com_InvalidHndOfTxSigGrpInfo is always 'false' due to this, the array is deactivated.' */
#define COM_PDUOFFSETOFTXSIGGRPINFO                                   STD_ON
#define COM_SIGGROUPONCHANGEOFFSETOFTXSIGGRPINFO                      STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGroupOnChangeOffset' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGROUPONCHANGESTARTPOSITIONOFTXSIGGRPINFO               STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGroupOnChangeStartPosition' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGROUPONCHANGEWITHOUTREPOFFSETOFTXSIGGRPINFO            STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGroupOnChangeWithoutRepOffset' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGROUPONCHANGEWITHOUTREPSTARTPOSITIONOFTXSIGGRPINFO     STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGroupOnChangeWithoutRepStartPosition' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGRPARRAYFILTERINFOENDIDXOFTXSIGGRPINFO                 STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGrpArrayFilterInfoEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGRPARRAYFILTERINFOSTARTIDXOFTXSIGGRPINFO               STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGrpArrayFilterInfoStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_SIGGRPARRAYFILTERINFOUSEDOFTXSIGGRPINFO                   STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.SigGrpArrayFilterInfoUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TRANSFERPROPERTYOFTXSIGGRPINFO                            STD_ON
#define COM_TXBUFFERENDIDXOFTXSIGGRPINFO                              STD_ON
#define COM_TXBUFFERLENGTHOFTXSIGGRPINFO                              STD_ON
#define COM_TXBUFFERSIGGRPINTXIPDUENDIDXOFTXSIGGRPINFO                STD_ON
#define COM_TXBUFFERSIGGRPINTXIPDULENGTHOFTXSIGGRPINFO                STD_ON
#define COM_TXBUFFERSIGGRPINTXIPDUSTARTIDXOFTXSIGGRPINFO              STD_ON
#define COM_TXBUFFERSTARTIDXOFTXSIGGRPINFO                            STD_ON
#define COM_TXBUFFERUBIDXINTXBUFFERIDXOFTXSIGGRPINFO                  STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxBufferUbIdxInTxBufferIdx' Reason: 'the optional indirection is deactivated because TxBufferUbIdxInTxBufferUsedOfTxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXBUFFERUBIDXINTXBUFFERUSEDOFTXSIGGRPINFO                 STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxBufferUbIdxInTxBufferUsed' Reason: 'the optional indirection is deactivated because TxBufferUbIdxInTxBufferUsedOfTxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXBUFFERUSEDOFTXSIGGRPINFO                                STD_ON
#define COM_TXFILTERINITSTATEENDIDXOFTXSIGGRPINFO                     STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxFilterInitStateEndIdx' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITSTATESTARTIDXOFTXSIGGRPINFO                   STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxFilterInitStateStartIdx' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITSTATEUSEDOFTXSIGGRPINFO                       STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxFilterInitStateUsed' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXPDUINFOIDXOFTXSIGGRPINFO                                STD_ON
#define COM_TXSIGGRPMASKENDIDXOFTXSIGGRPINFO                          STD_ON
#define COM_TXSIGGRPMASKLENGTHOFTXSIGGRPINFO                          STD_ON
#define COM_TXSIGGRPMASKSTARTIDXOFTXSIGGRPINFO                        STD_ON
#define COM_TXSIGGRPMASKUSEDOFTXSIGGRPINFO                            STD_ON
#define COM_TXSIGGRPONCHANGEMASKONCHANGEENDIDXOFTXSIGGRPINFO          STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGELENGTHOFTXSIGGRPINFO          STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGESTARTIDXOFTXSIGGRPINFO        STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGEUSEDOFTXSIGGRPINFO            STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPENDIDXOFTXSIGGRPINFO STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeWithoutRepEndIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPLENGTHOFTXSIGGRPINFO STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeWithoutRepLength' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPSTARTIDXOFTXSIGGRPINFO STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeWithoutRepStartIdx' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGGRPONCHANGEMASKONCHANGEWITHOUTREPUSEDOFTXSIGGRPINFO  STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigGrpOnChangeMaskOnChangeWithoutRepUsed' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGINFOINVVALUEINDENDIDXOFTXSIGGRPINFO                  STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigInfoInvValueIndEndIdx' Reason: 'the optional indirection is deactivated because TxSigInfoInvValueIndUsedOfTxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXSIGINFOINVVALUEINDSTARTIDXOFTXSIGGRPINFO                STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigInfoInvValueIndStartIdx' Reason: 'the optional indirection is deactivated because TxSigInfoInvValueIndUsedOfTxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXSIGINFOINVVALUEINDUSEDOFTXSIGGRPINFO                    STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.TxSigInfoInvValueIndUsed' Reason: 'the optional indirection is deactivated because TxSigInfoInvValueIndUsedOfTxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_UBMASKIDXOFTXSIGGRPINFO                                   STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.UbMaskIdx' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_UBMASKUSEDOFTXSIGGRPINFO                                  STD_OFF  /**< Deactivateable: 'Com_TxSigGrpInfo.UbMaskUsed' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigGrpInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXSIGGRPINFOIND                                           STD_ON
#define COM_TXSIGGRPMASK                                              STD_ON
#define COM_TXSIGGRPONCHANGEMASK                                      STD_OFF  /**< Deactivateable: 'Com_TxSigGrpOnChangeMask' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_TXSIGINFO                                                 STD_ON
#define COM_APPLTYPEOFTXSIGINFO                                       STD_ON
#define COM_BITLENGTHOFTXSIGINFO                                      STD_ON
#define COM_BITPOSITIONOFTXSIGINFO                                    STD_ON
#define COM_BUSACCOFTXSIGINFO                                         STD_ON
#define COM_BYTELENGTHOFTXSIGINFO                                     STD_ON
#define COM_BYTEPOSITIONOFTXSIGINFO                                   STD_ON
#define COM_CONSTVALUEARRAYBASEDINVVALUEENDIDXOFTXSIGINFO             STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.ConstValueArrayBasedInvValueEndIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINVVALUELENGTHOFTXSIGINFO             STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.ConstValueArrayBasedInvValueLength' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINVVALUESTARTIDXOFTXSIGINFO           STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.ConstValueArrayBasedInvValueStartIdx' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_CONSTVALUEARRAYBASEDINVVALUEUSEDOFTXSIGINFO               STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.ConstValueArrayBasedInvValueUsed' Reason: 'the optional indirection is deactivated because ConstValueArrayBasedInvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_FILTERINFOIDXOFTXSIGINFO                                  STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInfoIdx' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_FILTERINFOUSEDOFTXSIGINFO                                 STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInfoUsed' Reason: 'the optional indirection is deactivated because FilterInfoUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_FILTERINITVALUEIDXOFTXSIGINFO                             STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInitValueIdx' Reason: 'the optional indirection is deactivated because FilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_FILTERINITVALUEUSEDOFTXSIGINFO                            STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.FilterInitValueUsed' Reason: 'the optional indirection is deactivated because FilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_INVVALUEIDXOFTXSIGINFO                                    STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.InvValueIdx' Reason: 'the optional indirection is deactivated because InvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_INVVALUEUSEDOFTXSIGINFO                                   STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.InvValueUsed' Reason: 'the optional indirection is deactivated because InvValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_INVALIDHNDOFTXSIGINFO                                     STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.InvalidHnd' Reason: 'the value of Com_InvalidHndOfTxSigInfo is always 'false' due to this, the array is deactivated.' */
#define COM_ONCHANGEIDXOFTXSIGINFO                                    STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.OnChangeIdx' Reason: 'the optional indirection is deactivated because OnChangeUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_ONCHANGEUSEDOFTXSIGINFO                                   STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.OnChangeUsed' Reason: 'the optional indirection is deactivated because OnChangeUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_STARTBYTEINPDUPOSITIONOFTXSIGINFO                         STD_ON
#define COM_TRIGGEREDOFTXSIGINFO                                      STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.Triggered' Reason: 'the value of Com_TriggeredOfTxSigInfo is always 'false' due to this, the array is deactivated.' */
#define COM_TXBUFFERENDIDXOFTXSIGINFO                                 STD_ON
#define COM_TXBUFFERLENGTHOFTXSIGINFO                                 STD_ON
#define COM_TXBUFFERSTARTIDXOFTXSIGINFO                               STD_ON
#define COM_TXBUFFERUBIDXINTXBUFFERIDXOFTXSIGINFO                     STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxBufferUbIdxInTxBufferIdx' Reason: 'the optional indirection is deactivated because TxBufferUbIdxInTxBufferUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXBUFFERUBIDXINTXBUFFERUSEDOFTXSIGINFO                    STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxBufferUbIdxInTxBufferUsed' Reason: 'the optional indirection is deactivated because TxBufferUbIdxInTxBufferUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXBUFFERUSEDOFTXSIGINFO                                   STD_ON
#define COM_TXFILTERINITSTATEIDXOFTXSIGINFO                           STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitStateIdx' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITSTATEUSEDOFTXSIGINFO                          STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitStateUsed' Reason: 'the optional indirection is deactivated because TxFilterInitStateUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITVALUEARRAYBASEDFILTERINITVALUEENDIDXOFTXSIGINFO STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitValueArrayBasedFilterInitValueEndIdx' Reason: 'the optional indirection is deactivated because TxFilterInitValueArrayBasedFilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITVALUEARRAYBASEDFILTERINITVALUELENGTHOFTXSIGINFO STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitValueArrayBasedFilterInitValueLength' Reason: 'the optional indirection is deactivated because TxFilterInitValueArrayBasedFilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITVALUEARRAYBASEDFILTERINITVALUESTARTIDXOFTXSIGINFO STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitValueArrayBasedFilterInitValueStartIdx' Reason: 'the optional indirection is deactivated because TxFilterInitValueArrayBasedFilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXFILTERINITVALUEARRAYBASEDFILTERINITVALUEUSEDOFTXSIGINFO STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.TxFilterInitValueArrayBasedFilterInitValueUsed' Reason: 'the optional indirection is deactivated because TxFilterInitValueArrayBasedFilterInitValueUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_TXPDUINFOIDXOFTXSIGINFO                                   STD_ON
#define COM_TXSIGGRPINFOIDXOFTXSIGINFO                                STD_ON
#define COM_TXSIGGRPINFOUSEDOFTXSIGINFO                               STD_ON
#define COM_UBMASKIDXOFTXSIGINFO                                      STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.UbMaskIdx' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_UBMASKUSEDOFTXSIGINFO                                     STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.UbMaskUsed' Reason: 'the optional indirection is deactivated because UbMaskUsedOfTxSigInfo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define COM_WITHOUTREPOFTXSIGINFO                                     STD_OFF  /**< Deactivateable: 'Com_TxSigInfo.WithoutRep' Reason: 'the value of Com_WithoutRepOfTxSigInfo is always 'false' due to this, the array is deactivated.' */
#define COM_TXSIGINFOFILTERINITVALUEIND                               STD_OFF  /**< Deactivateable: 'Com_TxSigInfoFilterInitValueInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXSIGINFOINVVALUEIND                                      STD_OFF  /**< Deactivateable: 'Com_TxSigInfoInvValueInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXTOUTCNT                                                 STD_OFF  /**< Deactivateable: 'Com_TxTOutCnt' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXTOUTINFO                                                STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define COM_CBKTXTOUTFUNCPTRINDENDIDXOFTXTOUTINFO                     STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.CbkTxTOutFuncPtrIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXTOUTFUNCPTRINDSTARTIDXOFTXTOUTINFO                   STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.CbkTxTOutFuncPtrIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_CBKTXTOUTFUNCPTRINDUSEDOFTXTOUTINFO                       STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.CbkTxTOutFuncPtrIndUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_FACTOROFTXTOUTINFO                                        STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.Factor' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_MODEOFTXTOUTINFO                                          STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.Mode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXPDUINFOIDXOFTXTOUTINFO                                  STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.TxPduInfoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_TXTMPTPPDULENGTH                                          STD_OFF  /**< Deactivateable: 'Com_TxTmpTpPduLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXTPCONNECTIONSTATE                                       STD_OFF  /**< Deactivateable: 'Com_TxTpConnectionState' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXTPINFO                                                  STD_OFF  /**< Deactivateable: 'Com_TxTpInfo' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_BUFFERSIZEOFTXTPINFO                                      STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.BufferSize' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_DYNAMICINITIALLENGTHOFTXTPINFO                            STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.DynamicInitialLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXBUFFERENDIDXOFTXTPINFO                                  STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxBufferEndIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXBUFFERLENGTHOFTXTPINFO                                  STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxBufferLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXBUFFERSTARTIDXOFTXTPINFO                                STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxBufferStartIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXBUFFERUSEDOFTXTPINFO                                    STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxBufferUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXSIGINFODYNSIGIDXOFTXTPINFO                              STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxSigInfoDynSigIdx' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXSIGINFODYNSIGUSEDOFTXTPINFO                             STD_OFF  /**< Deactivateable: 'Com_TxTpInfo.TxSigInfoDynSigUsed' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXTPSDULENGTH                                             STD_OFF  /**< Deactivateable: 'Com_TxTpSduLength' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_TXTPWRITTENBYTESCOUNTER                                   STD_OFF  /**< Deactivateable: 'Com_TxTpWrittenBytesCounter' Reason: '/ActiveEcuC/PduR/Com[0:PduRTransportProtocol] is configured to 'false'' */
#define COM_WAITINGFORCONFIRMATION                                    STD_OFF  /**< Deactivateable: 'Com_WaitingForConfirmation' Reason: 'This array is deactivated, because no Tx error notification functions are configured.' */
#define COM_PCCONFIG                                                  STD_ON
#define COM_ACTIVATABLERXCOMIPDUSOFPCCONFIG                           STD_ON
#define COM_ACTIVATABLETXCOMIPDUSOFPCCONFIG                           STD_ON
#define COM_CONFIGIDOFPCCONFIG                                        STD_ON
#define COM_CONSTVALUEFLOAT32OFPCCONFIG                               STD_ON
#define COM_CONSTVALUESINT16OFPCCONFIG                                STD_ON
#define COM_CONSTVALUEUINT16OFPCCONFIG                                STD_ON
#define COM_CONSTVALUEUINT8OFPCCONFIG                                 STD_ON
#define COM_CURRENTTXMODEOFPCCONFIG                                   STD_ON
#define COM_CYCLETIMECNTOFPCCONFIG                                    STD_ON
#define COM_CYCLICSENDREQUESTOFPCCONFIG                               STD_ON
#define COM_DELAYTIMECNTOFPCCONFIG                                    STD_ON
#define COM_FINALMAGICNUMBEROFPCCONFIG                                STD_OFF  /**< Deactivateable: 'Com_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define COM_GATEWAYDESCRIPTIONPROCESSINGISRLOCKTHRESHOLDOFPCCONFIG    STD_OFF  /**< Deactivateable: 'Com_PCConfig.GatewayDescriptionProcessingISRLockThreshold' Reason: 'Gateway description feature is not licensed' */
#define COM_GATEWAYPROCESSINGISRLOCKCOUNTEROFPCCONFIG                 STD_ON
#define COM_GATEWAYPROCESSINGISRLOCKTHRESHOLDOFPCCONFIG               STD_OFF  /**< Deactivateable: 'Com_PCConfig.GatewayProcessingISRLockThreshold' Reason: 'Signal Gateway either not licensed or not configured.' */
#define COM_HANDLERXPDUDEFERREDOFPCCONFIG                             STD_ON
#define COM_INITDATAHASHCODEOFPCCONFIG                                STD_OFF  /**< Deactivateable: 'Com_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define COM_INITIALIZEDOFPCCONFIG                                     STD_ON
#define COM_PDUGRPCNTOFPCCONFIG                                       STD_ON
#define COM_PDUGRPVECTOROFPCCONFIG                                    STD_ON
#define COM_REPCNTOFPCCONFIG                                          STD_ON
#define COM_REPCYCLECNTOFPCCONFIG                                     STD_ON
#define COM_RXACCESSINFOINDOFPCCONFIG                                 STD_ON
#define COM_RXACCESSINFOOFPCCONFIG                                    STD_ON
#define COM_RXDEADLINEMONITORINGISRLOCKCOUNTEROFPCCONFIG              STD_ON
#define COM_RXDEADLINEMONITORINGISRLOCKTHRESHOLDOFPCCONFIG            STD_OFF  /**< Deactivateable: 'Com_PCConfig.RxDeadlineMonitoringISRLockThreshold' Reason: 'No Rx Signals or SignalGroups with a configured timeout are present. ' */
#define COM_RXDEFPDUBUFFEROFPCCONFIG                                  STD_ON
#define COM_RXDEFERREDPROCESSINGISRLOCKCOUNTEROFPCCONFIG              STD_ON
#define COM_RXDEFERREDPROCESSINGISRLOCKTHRESHOLDOFPCCONFIG            STD_ON
#define COM_RXDLMONDIVISOROFPCCONFIG                                  STD_OFF  /**< Deactivateable: 'Com_PCConfig.RxDlMonDivisor' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMainfunctionTimingDomainSupport] is configured to 'false'' */
#define COM_RXIPDUGROUPISRLOCKCOUNTEROFPCCONFIG                       STD_ON
#define COM_RXIPDUGROUPISRLOCKTHRESHOLDOFPCCONFIG                     STD_ON
#define COM_RXPDUGRPACTIVEOFPCCONFIG                                  STD_ON
#define COM_RXPDUGRPINFOOFPCCONFIG                                    STD_ON
#define COM_RXPDUINFOOFPCCONFIG                                       STD_ON
#define COM_RXSIGBUFFERFLOAT32OFPCCONFIG                              STD_ON
#define COM_RXSIGBUFFERSINT16OFPCCONFIG                               STD_ON
#define COM_RXSIGBUFFERUINT16OFPCCONFIG                               STD_ON
#define COM_RXSIGBUFFERUINT8OFPCCONFIG                                STD_ON
#define COM_RXSIGINFOOFPCCONFIG                                       STD_ON
#define COM_SIGGRPEVENTFLAGOFPCCONFIG                                 STD_ON
#define COM_SIZEOFACTIVATABLERXCOMIPDUSOFPCCONFIG                     STD_ON
#define COM_SIZEOFACTIVATABLETXCOMIPDUSOFPCCONFIG                     STD_ON
#define COM_SIZEOFCONSTVALUEFLOAT32OFPCCONFIG                         STD_ON
#define COM_SIZEOFCONSTVALUESINT16OFPCCONFIG                          STD_ON
#define COM_SIZEOFCONSTVALUEUINT16OFPCCONFIG                          STD_ON
#define COM_SIZEOFCONSTVALUEUINT8OFPCCONFIG                           STD_ON
#define COM_SIZEOFCURRENTTXMODEOFPCCONFIG                             STD_ON
#define COM_SIZEOFCYCLETIMECNTOFPCCONFIG                              STD_ON
#define COM_SIZEOFCYCLICSENDREQUESTOFPCCONFIG                         STD_ON
#define COM_SIZEOFDELAYTIMECNTOFPCCONFIG                              STD_ON
#define COM_SIZEOFHANDLERXPDUDEFERREDOFPCCONFIG                       STD_ON
#define COM_SIZEOFPDUGRPVECTOROFPCCONFIG                              STD_ON
#define COM_SIZEOFREPCNTOFPCCONFIG                                    STD_ON
#define COM_SIZEOFREPCYCLECNTOFPCCONFIG                               STD_ON
#define COM_SIZEOFRXACCESSINFOINDOFPCCONFIG                           STD_ON
#define COM_SIZEOFRXACCESSINFOOFPCCONFIG                              STD_ON
#define COM_SIZEOFRXDEFPDUBUFFEROFPCCONFIG                            STD_ON
#define COM_SIZEOFRXPDUGRPACTIVEOFPCCONFIG                            STD_ON
#define COM_SIZEOFRXPDUGRPINFOOFPCCONFIG                              STD_ON
#define COM_SIZEOFRXPDUINFOOFPCCONFIG                                 STD_ON
#define COM_SIZEOFRXSIGBUFFERFLOAT32OFPCCONFIG                        STD_ON
#define COM_SIZEOFRXSIGBUFFERSINT16OFPCCONFIG                         STD_ON
#define COM_SIZEOFRXSIGBUFFERUINT16OFPCCONFIG                         STD_ON
#define COM_SIZEOFRXSIGBUFFERUINT8OFPCCONFIG                          STD_ON
#define COM_SIZEOFRXSIGINFOOFPCCONFIG                                 STD_ON
#define COM_SIZEOFSIGGRPEVENTFLAGOFPCCONFIG                           STD_ON
#define COM_SIZEOFTRANSMITREQUESTOFPCCONFIG                           STD_ON
#define COM_SIZEOFTXBUFFEROFPCCONFIG                                  STD_ON
#define COM_SIZEOFTXMODEFALSEOFPCCONFIG                               STD_ON
#define COM_SIZEOFTXMODEINFOOFPCCONFIG                                STD_ON
#define COM_SIZEOFTXMODETRUEOFPCCONFIG                                STD_ON
#define COM_SIZEOFTXPDUGRPACTIVEOFPCCONFIG                            STD_ON
#define COM_SIZEOFTXPDUGRPINFOOFPCCONFIG                              STD_ON
#define COM_SIZEOFTXPDUINFOOFPCCONFIG                                 STD_ON
#define COM_SIZEOFTXPDUINITVALUEOFPCCONFIG                            STD_ON
#define COM_SIZEOFTXSDULENGTHOFPCCONFIG                               STD_ON
#define COM_SIZEOFTXSIGGRPINFOINDOFPCCONFIG                           STD_ON
#define COM_SIZEOFTXSIGGRPINFOOFPCCONFIG                              STD_ON
#define COM_SIZEOFTXSIGGRPMASKOFPCCONFIG                              STD_ON
#define COM_SIZEOFTXSIGINFOOFPCCONFIG                                 STD_ON
#define COM_TRANSMITREQUESTOFPCCONFIG                                 STD_ON
#define COM_TXBUFFEROFPCCONFIG                                        STD_ON
#define COM_TXCYCLECOUNTERDIVISOROFPCCONFIG                           STD_OFF  /**< Deactivateable: 'Com_PCConfig.TxCycleCounterDivisor' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMainfunctionTimingDomainSupport] is configured to 'false'' */
#define COM_TXCYCLICPROCESSINGISRLOCKCOUNTEROFPCCONFIG                STD_ON
#define COM_TXCYCLICPROCESSINGISRLOCKTHRESHOLDOFPCCONFIG              STD_ON
#define COM_TXDEADLINEMONITORINGISRLOCKCOUNTEROFPCCONFIG              STD_ON
#define COM_TXDEADLINEMONITORINGISRLOCKTHRESHOLDOFPCCONFIG            STD_OFF  /**< Deactivateable: 'Com_PCConfig.TxDeadlineMonitoringISRLockThreshold' Reason: 'No Tx Signals or SignalGroups with a configured timeout are present. ' */
#define COM_TXDLMONDIVISOROFPCCONFIG                                  STD_OFF  /**< Deactivateable: 'Com_PCConfig.TxDlMonDivisor' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComMainfunctionTimingDomainSupport] is configured to 'false'' */
#define COM_TXIPDUGROUPISRLOCKCOUNTEROFPCCONFIG                       STD_ON
#define COM_TXIPDUGROUPISRLOCKTHRESHOLDOFPCCONFIG                     STD_ON
#define COM_TXMODEFALSEOFPCCONFIG                                     STD_ON
#define COM_TXMODEINFOOFPCCONFIG                                      STD_ON
#define COM_TXMODETRUEOFPCCONFIG                                      STD_ON
#define COM_TXPDUGRPACTIVEOFPCCONFIG                                  STD_ON
#define COM_TXPDUGRPINFOOFPCCONFIG                                    STD_ON
#define COM_TXPDUINFOOFPCCONFIG                                       STD_ON
#define COM_TXPDUINITVALUEOFPCCONFIG                                  STD_ON
#define COM_TXPROCESSINGISRLOCKCOUNTEROFPCCONFIG                      STD_ON
#define COM_TXPROCESSINGISRLOCKTHRESHOLDOFPCCONFIG                    STD_ON
#define COM_TXSDULENGTHOFPCCONFIG                                     STD_ON
#define COM_TXSIGGRPINFOINDOFPCCONFIG                                 STD_ON
#define COM_TXSIGGRPINFOOFPCCONFIG                                    STD_ON
#define COM_TXSIGGRPMASKOFPCCONFIG                                    STD_ON
#define COM_TXSIGINFOOFPCCONFIG                                       STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  ComPCMinNumericValueDefines  Com Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define COM_MIN_CYCLETIMECNT                                          0u
#define COM_MIN_DELAYTIMECNT                                          0u
#define COM_MIN_GATEWAYPROCESSINGISRLOCKCOUNTER                       0u
#define COM_MIN_HANDLERXPDUDEFERRED                                   0u
#define COM_MIN_REPCNT                                                0u
#define COM_MIN_REPCYCLECNT                                           0u
#define COM_MIN_RXDEADLINEMONITORINGISRLOCKCOUNTER                    0u
#define COM_MIN_RXDEFPDUBUFFER                                        0u
#define COM_MIN_RXDEFERREDPROCESSINGISRLOCKCOUNTER                    0u
#define COM_MIN_RXIPDUGROUPISRLOCKCOUNTER                             0u
#define COM_MIN_RXSIGBUFFERSINT16                                     -32768
#define COM_MIN_RXSIGBUFFERUINT16                                     0u
#define COM_MIN_RXSIGBUFFERUINT8                                      0u
#define COM_MIN_SIGGRPEVENTFLAG                                       0u
#define COM_MIN_TXBUFFER                                              0u
#define COM_MIN_TXCYCLICPROCESSINGISRLOCKCOUNTER                      0u
#define COM_MIN_TXDEADLINEMONITORINGISRLOCKCOUNTER                    0u
#define COM_MIN_TXIPDUGROUPISRLOCKCOUNTER                             0u
#define COM_MIN_TXPROCESSINGISRLOCKCOUNTER                            0u
#define COM_MIN_TXSDULENGTH                                           0u
/** 
  \}
*/ 

/** 
  \defgroup  ComPCMaxNumericValueDefines  Com Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define COM_MAX_CYCLETIMECNT                                          255u
#define COM_MAX_DELAYTIMECNT                                          255u
#define COM_MAX_GATEWAYPROCESSINGISRLOCKCOUNTER                       65535u
#define COM_MAX_HANDLERXPDUDEFERRED                                   4294967295u
#define COM_MAX_REPCNT                                                255u
#define COM_MAX_REPCYCLECNT                                           255u
#define COM_MAX_RXDEADLINEMONITORINGISRLOCKCOUNTER                    65535u
#define COM_MAX_RXDEFPDUBUFFER                                        255u
#define COM_MAX_RXDEFERREDPROCESSINGISRLOCKCOUNTER                    65535u
#define COM_MAX_RXIPDUGROUPISRLOCKCOUNTER                             65535u
#define COM_MAX_RXSIGBUFFERSINT16                                     32767
#define COM_MAX_RXSIGBUFFERUINT16                                     65535u
#define COM_MAX_RXSIGBUFFERUINT8                                      255u
#define COM_MAX_SIGGRPEVENTFLAG                                       255u
#define COM_MAX_TXBUFFER                                              255u
#define COM_MAX_TXCYCLICPROCESSINGISRLOCKCOUNTER                      65535u
#define COM_MAX_TXDEADLINEMONITORINGISRLOCKCOUNTER                    65535u
#define COM_MAX_TXIPDUGROUPISRLOCKCOUNTER                             65535u
#define COM_MAX_TXPROCESSINGISRLOCKCOUNTER                            65535u
#define COM_MAX_TXSDULENGTH                                           4294967295u
/** 
  \}
*/ 

/** 
  \defgroup  ComPCNoReferenceDefines  Com No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define COM_NO_BUFFERIDXOFRXACCESSINFO                                65535u
#define COM_NO_INITVALUEIDXOFRXACCESSINFO                             255u
#define COM_NO_PDUGRPVECTORENDIDXOFRXPDUGRPINFO                       255u
#define COM_NO_PDUGRPVECTORSTARTIDXOFRXPDUGRPINFO                     255u
#define COM_NO_HANDLERXPDUDEFERREDIDXOFRXPDUINFO                      255u
#define COM_NO_RXACCESSINFOINDENDIDXOFRXPDUINFO                       65535u
#define COM_NO_RXACCESSINFOINDSTARTIDXOFRXPDUINFO                     65535u
#define COM_NO_RXDEFPDUBUFFERENDIDXOFRXPDUINFO                        65535u
#define COM_NO_RXDEFPDUBUFFERSTARTIDXOFRXPDUINFO                      65535u
#define COM_NO_RXSIGINFOENDIDXOFRXPDUINFO                             65535u
#define COM_NO_RXSIGINFOSTARTIDXOFRXPDUINFO                           65535u
#define COM_NO_PDUGRPVECTORENDIDXOFTXPDUGRPINFO                       255u
#define COM_NO_PDUGRPVECTORSTARTIDXOFTXPDUGRPINFO                     255u
#define COM_NO_TXBUFFERENDIDXOFTXPDUINFO                              65535u
#define COM_NO_TXBUFFERSTARTIDXOFTXPDUINFO                            65535u
#define COM_NO_TXPDUINITVALUEENDIDXOFTXPDUINFO                        65535u
#define COM_NO_TXPDUINITVALUESTARTIDXOFTXPDUINFO                      65535u
#define COM_NO_TXSIGGRPINFOINDENDIDXOFTXPDUINFO                       255u
#define COM_NO_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO                     255u
#define COM_NO_TXBUFFERENDIDXOFTXSIGGRPINFO                           65535u
#define COM_NO_TXBUFFERSTARTIDXOFTXSIGGRPINFO                         65535u
#define COM_NO_TXSIGGRPMASKENDIDXOFTXSIGGRPINFO                       255u
#define COM_NO_TXSIGGRPMASKSTARTIDXOFTXSIGGRPINFO                     255u
#define COM_NO_TXBUFFERENDIDXOFTXSIGINFO                              65535u
#define COM_NO_TXBUFFERSTARTIDXOFTXSIGINFO                            65535u
#define COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO                             255u
/** 
  \}
*/ 

/** 
  \defgroup  ComPCEnumExistsDefines  Com Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_FLOAT32              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_FLOAT32               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_FLOAT32 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_FLOAT32 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_FLOAT32 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_FLOAT32      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_FLOAT32       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_FLOAT32                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_FLOAT64              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_FLOAT64               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_FLOAT64 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_FLOAT64 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_FLOAT64 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_FLOAT64      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_FLOAT64       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_FLOAT64                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_Float64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_SINT16               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_SINT16                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_SINT16 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_SINT16 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_SINT16  STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_SINT16       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_SINT16        STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_SINT16                 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_SINT32               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_SINT32                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_SINT32 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_SINT32 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_SINT32  STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_SINT32       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_SINT32        STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_SINT32                 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_SINT64               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_SINT64                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_SINT64 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_SINT64 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_SINT64  STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_SINT64       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_SINT64        STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_SINT64                 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_SINT8                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_SINT8                 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_SINT8 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_SINT8  STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_SINT8   STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_SINT8        STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_SINT8         STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_SINT8                  STD_OFF  /**< Deactivateable: 'Com_FilterInfo_SInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_UINT16               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_UINT16                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_UINT16 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_UINT16 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_UINT16  STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_UINT16       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_UINT16        STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_UINT16                 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt16.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_UINT32               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_UINT32                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_UINT32 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_UINT32 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_UINT32  STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_UINT32       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_UINT32        STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_UINT32                 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt32.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_UINT64               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_UINT64                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_UINT64 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_UINT64 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_UINT64  STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_UINT64       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_UINT64        STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_UINT64                 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt64.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_UINT8                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_UINT8                 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_UINT8 STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_UINT8  STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_UINT8   STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_UINT8        STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_UINT8         STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_UINT8                  STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_ALWAYS_FILTERALGOOFFILTERINFO_UINT8_N              STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEVER_FILTERALGOOFFILTERINFO_UINT8_N               STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFFILTERINFO_UINT8_N STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFFILTERINFO_UINT8_N STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFFILTERINFO_UINT8_N STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFFILTERINFO_UINT8_N      STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFFILTERINFO_UINT8_N       STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_FILTERALGOOFFILTERINFO_UINT8_N                STD_OFF  /**< Deactivateable: 'Com_FilterInfo_UInt8_N.FilterAlgo' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_DIRECT_COPYTYPEOFGWDESCRIPTIONACCESSINFO           STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.CopyType' Reason: 'Gateway description feature is not licensed' */
#define COM_EXISTS_RIGHTSHIFT_COPYTYPEOFGWDESCRIPTIONACCESSINFO       STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.CopyType' Reason: 'Gateway description feature is not licensed' */
#define COM_EXISTS_LEFTSHIFT_COPYTYPEOFGWDESCRIPTIONACCESSINFO        STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.CopyType' Reason: 'Gateway description feature is not licensed' */
#define COM_EXISTS_BIG_ENDIAN_ENDIANNESSOFGWDESCRIPTIONACCESSINFO     STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Endianness' Reason: 'Gateway description feature is not licensed' */
#define COM_EXISTS_LITTLE_ENDIAN_ENDIANNESSOFGWDESCRIPTIONACCESSINFO  STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Endianness' Reason: 'Gateway description feature is not licensed' */
#define COM_EXISTS_IMMEDIATE_PENDING_TYPEOFGWDESCRIPTIONACCESSINFO    STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: 'Gateway description feature is not licensed' */
#define COM_EXISTS_IMMEDIATE_TRIGGERED_TYPEOFGWDESCRIPTIONACCESSINFO  STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: 'Gateway description feature is not licensed' */
#define COM_EXISTS_IMMEDIATE_TRIGGERED_ONCHANGE_TYPEOFGWDESCRIPTIONACCESSINFO STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: 'Gateway description feature is not licensed' */
#define COM_EXISTS_IMMEDIATE_TRIGGERED_ONCHANGE_WITHOUTREP_TYPEOFGWDESCRIPTIONACCESSINFO STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: 'Gateway description feature is not licensed' */
#define COM_EXISTS_IMMEDIATE_TRIGGERED_WITHOUTREP_TYPEOFGWDESCRIPTIONACCESSINFO STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: 'Gateway description feature is not licensed' */
#define COM_EXISTS_DEFERRED_PENDING_TYPEOFGWDESCRIPTIONACCESSINFO     STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: 'Gateway description feature is not licensed' */
#define COM_EXISTS_DEFERRED_TRIGGERED_TYPEOFGWDESCRIPTIONACCESSINFO   STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: 'Gateway description feature is not licensed' */
#define COM_EXISTS_DEFERRED_TRIGGERED_ONCHANGE_TYPEOFGWDESCRIPTIONACCESSINFO STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: 'Gateway description feature is not licensed' */
#define COM_EXISTS_DEFERRED_TRIGGERED_ONCHANGE_WITHOUTREP_TYPEOFGWDESCRIPTIONACCESSINFO STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: 'Gateway description feature is not licensed' */
#define COM_EXISTS_DEFERRED_TRIGGERED_WITHOUTREP_TYPEOFGWDESCRIPTIONACCESSINFO STD_OFF  /**< Deactivateable: 'Com_GwDescriptionAccessInfo.Type' Reason: 'Gateway description feature is not licensed' */
#define COM_EXISTS_UINT8_APPLTYPEOFRXACCESSINFO                       STD_ON
#define COM_EXISTS_SINT8_APPLTYPEOFRXACCESSINFO                       STD_OFF
#define COM_EXISTS_UINT16_APPLTYPEOFRXACCESSINFO                      STD_ON
#define COM_EXISTS_SINT16_APPLTYPEOFRXACCESSINFO                      STD_ON
#define COM_EXISTS_UINT32_APPLTYPEOFRXACCESSINFO                      STD_OFF
#define COM_EXISTS_SINT32_APPLTYPEOFRXACCESSINFO                      STD_OFF
#define COM_EXISTS_UINT64_APPLTYPEOFRXACCESSINFO                      STD_OFF
#define COM_EXISTS_SINT64_APPLTYPEOFRXACCESSINFO                      STD_OFF
#define COM_EXISTS_UINT8_N_APPLTYPEOFRXACCESSINFO                     STD_OFF
#define COM_EXISTS_UINT8_DYN_APPLTYPEOFRXACCESSINFO                   STD_OFF
#define COM_EXISTS_ZEROBIT_APPLTYPEOFRXACCESSINFO                     STD_OFF
#define COM_EXISTS_FLOAT32_APPLTYPEOFRXACCESSINFO                     STD_ON
#define COM_EXISTS_FLOAT64_APPLTYPEOFRXACCESSINFO                     STD_OFF
#define COM_EXISTS_NBIT_BUSACCOFRXACCESSINFO                          STD_ON
#define COM_EXISTS_BYTE_BUSACCOFRXACCESSINFO                          STD_ON
#define COM_EXISTS_NBYTE_BUSACCOFRXACCESSINFO                         STD_ON
#define COM_EXISTS_NBYTE_SW_BUSACCOFRXACCESSINFO                      STD_ON
#define COM_EXISTS_NBITNBYTE_BUSACCOFRXACCESSINFO                     STD_OFF
#define COM_EXISTS_NBITNBYTE_SW_BUSACCOFRXACCESSINFO                  STD_ON
#define COM_EXISTS_ARRAY_BASED_BUSACCOFRXACCESSINFO                   STD_OFF
#define COM_EXISTS_DEFERRED_SIGNALPROCESSINGOFRXPDUINFO               STD_ON
#define COM_EXISTS_IMMEDIATE_SIGNALPROCESSINGOFRXPDUINFO              STD_OFF
#define COM_EXISTS_NORMAL_TYPEOFRXPDUINFO                             STD_ON
#define COM_EXISTS_TP_TYPEOFRXPDUINFO                                 STD_OFF
#define COM_EXISTS_DEFERRED_SIGNALPROCESSINGOFRXSIGGRPINFO            STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.SignalProcessing' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_IMMEDIATE_SIGNALPROCESSINGOFRXSIGGRPINFO           STD_OFF  /**< Deactivateable: 'Com_RxSigGrpInfo.SignalProcessing' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO               STD_ON
#define COM_EXISTS_IMMEDIATE_SIGNALPROCESSINGOFRXSIGINFO              STD_OFF
#define COM_EXISTS_ALWAYS_FILTERALGOOFSIGGRPARRAYFILTERINFO           STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_NEVER_FILTERALGOOFSIGGRPARRAYFILTERINFO            STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_MASKED_OLD_FILTERALGOOFSIGGRPARRAYFILTERINFO STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_MASKED_NEW_DIFFERS_X_FILTERALGOOFSIGGRPARRAYFILTERINFO STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_MASKED_NEW_EQUALS_X_FILTERALGOOFSIGGRPARRAYFILTERINFO STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_NEW_IS_OUTSIDE_FILTERALGOOFSIGGRPARRAYFILTERINFO   STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_NEW_IS_WITHIN_FILTERALGOOFSIGGRPARRAYFILTERINFO    STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_NONE_FILTERALGOOFSIGGRPARRAYFILTERINFO             STD_OFF  /**< Deactivateable: 'Com_SigGrpArrayFilterInfo.FilterAlgo' Reason: '/ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] is configured to 'false'' */
#define COM_EXISTS_TRANSMIT_CLRUBOFTXPDUINFO                          STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ClrUb' Reason: 'This array is deactivated, because no Tx I-PDUs with update-bits are configured.' */
#define COM_EXISTS_TRIGGER_TRANSMIT_CLRUBOFTXPDUINFO                  STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ClrUb' Reason: 'This array is deactivated, because no Tx I-PDUs with update-bits are configured.' */
#define COM_EXISTS_NOT_USED_CLRUBOFTXPDUINFO                          STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ClrUb' Reason: 'This array is deactivated, because no Tx I-PDUs with update-bits are configured.' */
#define COM_EXISTS_CONFIRMATION_CLRUBOFTXPDUINFO                      STD_OFF  /**< Deactivateable: 'Com_TxPduInfo.ClrUb' Reason: 'This array is deactivated, because no Tx I-PDUs with update-bits are configured.' */
#define COM_EXISTS_PENDING_TRANSFERPROPERTYOFTXSIGGRPINFO             STD_ON
#define COM_EXISTS_TRIGGERED_TRANSFERPROPERTYOFTXSIGGRPINFO           STD_OFF
#define COM_EXISTS_TRIGGERED_WITHOUT_REPETITION_TRANSFERPROPERTYOFTXSIGGRPINFO STD_OFF
#define COM_EXISTS_TRIGGERED_ON_CHANGE_TRANSFERPROPERTYOFTXSIGGRPINFO STD_OFF
#define COM_EXISTS_TRIGGERED_ON_CHANGE_WITHOUT_REPETITION_TRANSFERPROPERTYOFTXSIGGRPINFO STD_OFF
#define COM_EXISTS_UINT8_APPLTYPEOFTXSIGINFO                          STD_ON
#define COM_EXISTS_SINT8_APPLTYPEOFTXSIGINFO                          STD_OFF
#define COM_EXISTS_UINT16_APPLTYPEOFTXSIGINFO                         STD_ON
#define COM_EXISTS_SINT16_APPLTYPEOFTXSIGINFO                         STD_OFF
#define COM_EXISTS_UINT32_APPLTYPEOFTXSIGINFO                         STD_ON
#define COM_EXISTS_SINT32_APPLTYPEOFTXSIGINFO                         STD_OFF
#define COM_EXISTS_UINT64_APPLTYPEOFTXSIGINFO                         STD_ON
#define COM_EXISTS_SINT64_APPLTYPEOFTXSIGINFO                         STD_OFF
#define COM_EXISTS_UINT8_N_APPLTYPEOFTXSIGINFO                        STD_ON
#define COM_EXISTS_UINT8_DYN_APPLTYPEOFTXSIGINFO                      STD_OFF
#define COM_EXISTS_ZEROBIT_APPLTYPEOFTXSIGINFO                        STD_OFF
#define COM_EXISTS_FLOAT32_APPLTYPEOFTXSIGINFO                        STD_ON
#define COM_EXISTS_FLOAT64_APPLTYPEOFTXSIGINFO                        STD_OFF
#define COM_EXISTS_NBIT_BUSACCOFTXSIGINFO                             STD_ON
#define COM_EXISTS_BYTE_BUSACCOFTXSIGINFO                             STD_ON
#define COM_EXISTS_NBYTE_BUSACCOFTXSIGINFO                            STD_ON
#define COM_EXISTS_NBYTE_SW_BUSACCOFTXSIGINFO                         STD_OFF
#define COM_EXISTS_NBITNBYTE_BUSACCOFTXSIGINFO                        STD_ON
#define COM_EXISTS_NBITNBYTE_SW_BUSACCOFTXSIGINFO                     STD_OFF
#define COM_EXISTS_ARRAY_BASED_BUSACCOFTXSIGINFO                      STD_ON
#define COM_EXISTS_NORMAL_MODEOFTXTOUTINFO                            STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.Mode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define COM_EXISTS_NONE_MODEOFTXTOUTINFO                              STD_OFF  /**< Deactivateable: 'Com_TxTOutInfo.Mode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
/** 
  \}
*/ 

/** 
  \defgroup  ComPCEnumDefines  Com Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define COM_UINT8_APPLTYPEOFRXACCESSINFO                              0x00u
#define COM_UINT16_APPLTYPEOFRXACCESSINFO                             0x02u
#define COM_SINT16_APPLTYPEOFRXACCESSINFO                             0x03u
#define COM_FLOAT32_APPLTYPEOFRXACCESSINFO                            0x0Bu
#define COM_NBIT_BUSACCOFRXACCESSINFO                                 0x00u
#define COM_BYTE_BUSACCOFRXACCESSINFO                                 0x01u
#define COM_NBYTE_BUSACCOFRXACCESSINFO                                0x02u
#define COM_NBYTE_SW_BUSACCOFRXACCESSINFO                             0x03u
#define COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO                         0x05u
#define COM_DEFERRED_SIGNALPROCESSINGOFRXPDUINFO                      0x00u
#define COM_NORMAL_TYPEOFRXPDUINFO                                    0x00u
#define COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO                      0x00u
#define COM_PENDING_TRANSFERPROPERTYOFTXSIGGRPINFO                    0x00u
#define COM_UINT8_APPLTYPEOFTXSIGINFO                                 0x00u
#define COM_UINT16_APPLTYPEOFTXSIGINFO                                0x02u
#define COM_UINT32_APPLTYPEOFTXSIGINFO                                0x04u
#define COM_UINT64_APPLTYPEOFTXSIGINFO                                0x06u
#define COM_UINT8_N_APPLTYPEOFTXSIGINFO                               0x08u
#define COM_FLOAT32_APPLTYPEOFTXSIGINFO                               0x0Bu
#define COM_NBIT_BUSACCOFTXSIGINFO                                    0x00u
#define COM_BYTE_BUSACCOFTXSIGINFO                                    0x01u
#define COM_NBYTE_BUSACCOFTXSIGINFO                                   0x02u
#define COM_NBITNBYTE_BUSACCOFTXSIGINFO                               0x04u
#define COM_ARRAY_BASED_BUSACCOFTXSIGINFO                             0x06u
/** 
  \}
*/ 

/** 
  \defgroup  ComPCIsReducedToDefineDefines  Com Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define COM_ISDEF_RXPDUINFOIDXOFACTIVATABLERXCOMIPDUS                 STD_OFF
#define COM_ISDEF_TXPDUINFOIDXOFACTIVATABLETXCOMIPDUS                 STD_OFF
#define COM_ISDEF_CONSTVALUEFLOAT32                                   STD_OFF
#define COM_ISDEF_CONSTVALUESINT16                                    STD_OFF
#define COM_ISDEF_CONSTVALUEUINT16                                    STD_OFF
#define COM_ISDEF_CONSTVALUEUINT8                                     STD_OFF
#define COM_ISDEF_PDUGRPVECTOR                                        STD_OFF
#define COM_ISDEF_APPLTYPEOFRXACCESSINFO                              STD_OFF
#define COM_ISDEF_BITLENGTHOFRXACCESSINFO                             STD_OFF
#define COM_ISDEF_BITPOSITIONOFRXACCESSINFO                           STD_OFF
#define COM_ISDEF_BUFFERIDXOFRXACCESSINFO                             STD_OFF
#define COM_ISDEF_BUFFERUSEDOFRXACCESSINFO                            STD_OFF
#define COM_ISDEF_BUSACCOFRXACCESSINFO                                STD_OFF
#define COM_ISDEF_BYTELENGTHOFRXACCESSINFO                            STD_OFF
#define COM_ISDEF_BYTEPOSITIONOFRXACCESSINFO                          STD_OFF
#define COM_ISDEF_INITVALUEIDXOFRXACCESSINFO                          STD_OFF
#define COM_ISDEF_INITVALUEUSEDOFRXACCESSINFO                         STD_OFF
#define COM_ISDEF_RXPDUINFOIDXOFRXACCESSINFO                          STD_OFF
#define COM_ISDEF_SIGNEXTREQUIREDOFRXACCESSINFO                       STD_OFF
#define COM_ISDEF_STARTBYTEINPDUPOSITIONOFRXACCESSINFO                STD_OFF
#define COM_ISDEF_RXACCESSINFOIND                                     STD_OFF
#define COM_ISDEF_PDUGRPVECTORENDIDXOFRXPDUGRPINFO                    STD_OFF
#define COM_ISDEF_PDUGRPVECTORSTARTIDXOFRXPDUGRPINFO                  STD_OFF
#define COM_ISDEF_PDUGRPVECTORUSEDOFRXPDUGRPINFO                      STD_OFF
#define COM_ISDEF_HANDLERXPDUDEFERREDIDXOFRXPDUINFO                   STD_OFF
#define COM_ISDEF_HANDLERXPDUDEFERREDUSEDOFRXPDUINFO                  STD_OFF
#define COM_ISDEF_RXACCESSINFOINDENDIDXOFRXPDUINFO                    STD_OFF
#define COM_ISDEF_RXACCESSINFOINDSTARTIDXOFRXPDUINFO                  STD_OFF
#define COM_ISDEF_RXACCESSINFOINDUSEDOFRXPDUINFO                      STD_OFF
#define COM_ISDEF_RXDEFPDUBUFFERENDIDXOFRXPDUINFO                     STD_OFF
#define COM_ISDEF_RXDEFPDUBUFFERLENGTHOFRXPDUINFO                     STD_OFF
#define COM_ISDEF_RXDEFPDUBUFFERSTARTIDXOFRXPDUINFO                   STD_OFF
#define COM_ISDEF_RXDEFPDUBUFFERUSEDOFRXPDUINFO                       STD_OFF
#define COM_ISDEF_RXSIGINFOENDIDXOFRXPDUINFO                          STD_OFF
#define COM_ISDEF_RXSIGINFOSTARTIDXOFRXPDUINFO                        STD_OFF
#define COM_ISDEF_RXSIGINFOUSEDOFRXPDUINFO                            STD_OFF
#define COM_ISDEF_SIGNALPROCESSINGOFRXPDUINFO                         STD_OFF
#define COM_ISDEF_TYPEOFRXPDUINFO                                     STD_OFF
#define COM_ISDEF_RXACCESSINFOIDXOFRXSIGINFO                          STD_OFF
#define COM_ISDEF_SIGNALPROCESSINGOFRXSIGINFO                         STD_OFF
#define COM_ISDEF_VALIDDLCOFRXSIGINFO                                 STD_OFF
#define COM_ISDEF_PERIODICOFTXMODEFALSE                               STD_OFF
#define COM_ISDEF_TIMEPERIODOFTXMODEFALSE                             STD_OFF
#define COM_ISDEF_INITMODEOFTXMODEINFO                                STD_OFF
#define COM_ISDEF_MINIMUMDELAYOFTXMODEINFO                            STD_OFF
#define COM_ISDEF_TXMODEFALSEIDXOFTXMODEINFO                          STD_OFF
#define COM_ISDEF_TXMODETRUEIDXOFTXMODEINFO                           STD_OFF
#define COM_ISDEF_PERIODICOFTXMODETRUE                                STD_OFF
#define COM_ISDEF_TIMEPERIODOFTXMODETRUE                              STD_OFF
#define COM_ISDEF_PDUGRPVECTORENDIDXOFTXPDUGRPINFO                    STD_OFF
#define COM_ISDEF_PDUGRPVECTORSTARTIDXOFTXPDUGRPINFO                  STD_OFF
#define COM_ISDEF_PDUGRPVECTORUSEDOFTXPDUGRPINFO                      STD_OFF
#define COM_ISDEF_EXTERNALIDOFTXPDUINFO                               STD_OFF
#define COM_ISDEF_METADATALENGTHOFTXPDUINFO                           STD_OFF
#define COM_ISDEF_PDUWITHMETADATALENGTHOFTXPDUINFO                    STD_OFF
#define COM_ISDEF_TXBUFFERENDIDXOFTXPDUINFO                           STD_OFF
#define COM_ISDEF_TXBUFFERLENGTHOFTXPDUINFO                           STD_OFF
#define COM_ISDEF_TXBUFFERSTARTIDXOFTXPDUINFO                         STD_OFF
#define COM_ISDEF_TXBUFFERUSEDOFTXPDUINFO                             STD_OFF
#define COM_ISDEF_TXPDUINITVALUEENDIDXOFTXPDUINFO                     STD_OFF
#define COM_ISDEF_TXPDUINITVALUESTARTIDXOFTXPDUINFO                   STD_OFF
#define COM_ISDEF_TXPDUINITVALUEUSEDOFTXPDUINFO                       STD_OFF
#define COM_ISDEF_TXSIGGRPINFOINDENDIDXOFTXPDUINFO                    STD_OFF
#define COM_ISDEF_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO                  STD_OFF
#define COM_ISDEF_TXSIGGRPINFOINDUSEDOFTXPDUINFO                      STD_OFF
#define COM_ISDEF_TXPDUINITVALUE                                      STD_OFF
#define COM_ISDEF_PDUOFFSETOFTXSIGGRPINFO                             STD_OFF
#define COM_ISDEF_TRANSFERPROPERTYOFTXSIGGRPINFO                      STD_OFF
#define COM_ISDEF_TXBUFFERENDIDXOFTXSIGGRPINFO                        STD_OFF
#define COM_ISDEF_TXBUFFERLENGTHOFTXSIGGRPINFO                        STD_OFF
#define COM_ISDEF_TXBUFFERSIGGRPINTXIPDUENDIDXOFTXSIGGRPINFO          STD_OFF
#define COM_ISDEF_TXBUFFERSIGGRPINTXIPDULENGTHOFTXSIGGRPINFO          STD_OFF
#define COM_ISDEF_TXBUFFERSIGGRPINTXIPDUSTARTIDXOFTXSIGGRPINFO        STD_OFF
#define COM_ISDEF_TXBUFFERSTARTIDXOFTXSIGGRPINFO                      STD_OFF
#define COM_ISDEF_TXBUFFERUSEDOFTXSIGGRPINFO                          STD_OFF
#define COM_ISDEF_TXPDUINFOIDXOFTXSIGGRPINFO                          STD_OFF
#define COM_ISDEF_TXSIGGRPMASKENDIDXOFTXSIGGRPINFO                    STD_OFF
#define COM_ISDEF_TXSIGGRPMASKLENGTHOFTXSIGGRPINFO                    STD_OFF
#define COM_ISDEF_TXSIGGRPMASKSTARTIDXOFTXSIGGRPINFO                  STD_OFF
#define COM_ISDEF_TXSIGGRPMASKUSEDOFTXSIGGRPINFO                      STD_OFF
#define COM_ISDEF_TXSIGGRPINFOIND                                     STD_OFF
#define COM_ISDEF_TXSIGGRPMASK                                        STD_OFF
#define COM_ISDEF_APPLTYPEOFTXSIGINFO                                 STD_OFF
#define COM_ISDEF_BITLENGTHOFTXSIGINFO                                STD_OFF
#define COM_ISDEF_BITPOSITIONOFTXSIGINFO                              STD_OFF
#define COM_ISDEF_BUSACCOFTXSIGINFO                                   STD_OFF
#define COM_ISDEF_BYTELENGTHOFTXSIGINFO                               STD_OFF
#define COM_ISDEF_BYTEPOSITIONOFTXSIGINFO                             STD_OFF
#define COM_ISDEF_STARTBYTEINPDUPOSITIONOFTXSIGINFO                   STD_OFF
#define COM_ISDEF_TXBUFFERENDIDXOFTXSIGINFO                           STD_OFF
#define COM_ISDEF_TXBUFFERLENGTHOFTXSIGINFO                           STD_OFF
#define COM_ISDEF_TXBUFFERSTARTIDXOFTXSIGINFO                         STD_OFF
#define COM_ISDEF_TXBUFFERUSEDOFTXSIGINFO                             STD_OFF
#define COM_ISDEF_TXPDUINFOIDXOFTXSIGINFO                             STD_OFF
#define COM_ISDEF_TXSIGGRPINFOIDXOFTXSIGINFO                          STD_OFF
#define COM_ISDEF_TXSIGGRPINFOUSEDOFTXSIGINFO                         STD_OFF
#define COM_ISDEF_ACTIVATABLERXCOMIPDUSOFPCCONFIG                     STD_ON
#define COM_ISDEF_ACTIVATABLETXCOMIPDUSOFPCCONFIG                     STD_ON
#define COM_ISDEF_CONSTVALUEFLOAT32OFPCCONFIG                         STD_ON
#define COM_ISDEF_CONSTVALUESINT16OFPCCONFIG                          STD_ON
#define COM_ISDEF_CONSTVALUEUINT16OFPCCONFIG                          STD_ON
#define COM_ISDEF_CONSTVALUEUINT8OFPCCONFIG                           STD_ON
#define COM_ISDEF_CURRENTTXMODEOFPCCONFIG                             STD_ON
#define COM_ISDEF_CYCLETIMECNTOFPCCONFIG                              STD_ON
#define COM_ISDEF_CYCLICSENDREQUESTOFPCCONFIG                         STD_ON
#define COM_ISDEF_DELAYTIMECNTOFPCCONFIG                              STD_ON
#define COM_ISDEF_GATEWAYPROCESSINGISRLOCKCOUNTEROFPCCONFIG           STD_ON
#define COM_ISDEF_HANDLERXPDUDEFERREDOFPCCONFIG                       STD_ON
#define COM_ISDEF_INITIALIZEDOFPCCONFIG                               STD_ON
#define COM_ISDEF_PDUGRPVECTOROFPCCONFIG                              STD_ON
#define COM_ISDEF_REPCNTOFPCCONFIG                                    STD_ON
#define COM_ISDEF_REPCYCLECNTOFPCCONFIG                               STD_ON
#define COM_ISDEF_RXACCESSINFOINDOFPCCONFIG                           STD_ON
#define COM_ISDEF_RXACCESSINFOOFPCCONFIG                              STD_ON
#define COM_ISDEF_RXDEADLINEMONITORINGISRLOCKCOUNTEROFPCCONFIG        STD_ON
#define COM_ISDEF_RXDEFPDUBUFFEROFPCCONFIG                            STD_ON
#define COM_ISDEF_RXDEFERREDPROCESSINGISRLOCKCOUNTEROFPCCONFIG        STD_ON
#define COM_ISDEF_RXIPDUGROUPISRLOCKCOUNTEROFPCCONFIG                 STD_ON
#define COM_ISDEF_RXPDUGRPACTIVEOFPCCONFIG                            STD_ON
#define COM_ISDEF_RXPDUGRPINFOOFPCCONFIG                              STD_ON
#define COM_ISDEF_RXPDUINFOOFPCCONFIG                                 STD_ON
#define COM_ISDEF_RXSIGBUFFERFLOAT32OFPCCONFIG                        STD_ON
#define COM_ISDEF_RXSIGBUFFERSINT16OFPCCONFIG                         STD_ON
#define COM_ISDEF_RXSIGBUFFERUINT16OFPCCONFIG                         STD_ON
#define COM_ISDEF_RXSIGBUFFERUINT8OFPCCONFIG                          STD_ON
#define COM_ISDEF_RXSIGINFOOFPCCONFIG                                 STD_ON
#define COM_ISDEF_SIGGRPEVENTFLAGOFPCCONFIG                           STD_ON
#define COM_ISDEF_TRANSMITREQUESTOFPCCONFIG                           STD_ON
#define COM_ISDEF_TXBUFFEROFPCCONFIG                                  STD_ON
#define COM_ISDEF_TXCYCLICPROCESSINGISRLOCKCOUNTEROFPCCONFIG          STD_ON
#define COM_ISDEF_TXDEADLINEMONITORINGISRLOCKCOUNTEROFPCCONFIG        STD_ON
#define COM_ISDEF_TXIPDUGROUPISRLOCKCOUNTEROFPCCONFIG                 STD_ON
#define COM_ISDEF_TXMODEFALSEOFPCCONFIG                               STD_ON
#define COM_ISDEF_TXMODEINFOOFPCCONFIG                                STD_ON
#define COM_ISDEF_TXMODETRUEOFPCCONFIG                                STD_ON
#define COM_ISDEF_TXPDUGRPACTIVEOFPCCONFIG                            STD_ON
#define COM_ISDEF_TXPDUGRPINFOOFPCCONFIG                              STD_ON
#define COM_ISDEF_TXPDUINFOOFPCCONFIG                                 STD_ON
#define COM_ISDEF_TXPDUINITVALUEOFPCCONFIG                            STD_ON
#define COM_ISDEF_TXPROCESSINGISRLOCKCOUNTEROFPCCONFIG                STD_ON
#define COM_ISDEF_TXSDULENGTHOFPCCONFIG                               STD_ON
#define COM_ISDEF_TXSIGGRPINFOINDOFPCCONFIG                           STD_ON
#define COM_ISDEF_TXSIGGRPINFOOFPCCONFIG                              STD_ON
#define COM_ISDEF_TXSIGGRPMASKOFPCCONFIG                              STD_ON
#define COM_ISDEF_TXSIGINFOOFPCCONFIG                                 STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  ComPCEqualsAlwaysToDefines  Com Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define COM_EQ2_RXPDUINFOIDXOFACTIVATABLERXCOMIPDUS                   
#define COM_EQ2_TXPDUINFOIDXOFACTIVATABLETXCOMIPDUS                   
#define COM_EQ2_CONSTVALUEFLOAT32                                     
#define COM_EQ2_CONSTVALUESINT16                                      
#define COM_EQ2_CONSTVALUEUINT16                                      
#define COM_EQ2_CONSTVALUEUINT8                                       
#define COM_EQ2_PDUGRPVECTOR                                          
#define COM_EQ2_APPLTYPEOFRXACCESSINFO                                
#define COM_EQ2_BITLENGTHOFRXACCESSINFO                               
#define COM_EQ2_BITPOSITIONOFRXACCESSINFO                             
#define COM_EQ2_BUFFERIDXOFRXACCESSINFO                               
#define COM_EQ2_BUFFERUSEDOFRXACCESSINFO                              
#define COM_EQ2_BUSACCOFRXACCESSINFO                                  
#define COM_EQ2_BYTELENGTHOFRXACCESSINFO                              
#define COM_EQ2_BYTEPOSITIONOFRXACCESSINFO                            
#define COM_EQ2_INITVALUEIDXOFRXACCESSINFO                            
#define COM_EQ2_INITVALUEUSEDOFRXACCESSINFO                           
#define COM_EQ2_RXPDUINFOIDXOFRXACCESSINFO                            
#define COM_EQ2_SIGNEXTREQUIREDOFRXACCESSINFO                         
#define COM_EQ2_STARTBYTEINPDUPOSITIONOFRXACCESSINFO                  
#define COM_EQ2_RXACCESSINFOIND                                       
#define COM_EQ2_PDUGRPVECTORENDIDXOFRXPDUGRPINFO                      
#define COM_EQ2_PDUGRPVECTORSTARTIDXOFRXPDUGRPINFO                    
#define COM_EQ2_PDUGRPVECTORUSEDOFRXPDUGRPINFO                        
#define COM_EQ2_HANDLERXPDUDEFERREDIDXOFRXPDUINFO                     
#define COM_EQ2_HANDLERXPDUDEFERREDUSEDOFRXPDUINFO                    
#define COM_EQ2_RXACCESSINFOINDENDIDXOFRXPDUINFO                      
#define COM_EQ2_RXACCESSINFOINDSTARTIDXOFRXPDUINFO                    
#define COM_EQ2_RXACCESSINFOINDUSEDOFRXPDUINFO                        
#define COM_EQ2_RXDEFPDUBUFFERENDIDXOFRXPDUINFO                       
#define COM_EQ2_RXDEFPDUBUFFERLENGTHOFRXPDUINFO                       
#define COM_EQ2_RXDEFPDUBUFFERSTARTIDXOFRXPDUINFO                     
#define COM_EQ2_RXDEFPDUBUFFERUSEDOFRXPDUINFO                         
#define COM_EQ2_RXSIGINFOENDIDXOFRXPDUINFO                            
#define COM_EQ2_RXSIGINFOSTARTIDXOFRXPDUINFO                          
#define COM_EQ2_RXSIGINFOUSEDOFRXPDUINFO                              
#define COM_EQ2_SIGNALPROCESSINGOFRXPDUINFO                           
#define COM_EQ2_TYPEOFRXPDUINFO                                       
#define COM_EQ2_RXACCESSINFOIDXOFRXSIGINFO                            
#define COM_EQ2_SIGNALPROCESSINGOFRXSIGINFO                           
#define COM_EQ2_VALIDDLCOFRXSIGINFO                                   
#define COM_EQ2_PERIODICOFTXMODEFALSE                                 
#define COM_EQ2_TIMEPERIODOFTXMODEFALSE                               
#define COM_EQ2_INITMODEOFTXMODEINFO                                  
#define COM_EQ2_MINIMUMDELAYOFTXMODEINFO                              
#define COM_EQ2_TXMODEFALSEIDXOFTXMODEINFO                            
#define COM_EQ2_TXMODETRUEIDXOFTXMODEINFO                             
#define COM_EQ2_PERIODICOFTXMODETRUE                                  
#define COM_EQ2_TIMEPERIODOFTXMODETRUE                                
#define COM_EQ2_PDUGRPVECTORENDIDXOFTXPDUGRPINFO                      
#define COM_EQ2_PDUGRPVECTORSTARTIDXOFTXPDUGRPINFO                    
#define COM_EQ2_PDUGRPVECTORUSEDOFTXPDUGRPINFO                        
#define COM_EQ2_EXTERNALIDOFTXPDUINFO                                 
#define COM_EQ2_METADATALENGTHOFTXPDUINFO                             
#define COM_EQ2_PDUWITHMETADATALENGTHOFTXPDUINFO                      
#define COM_EQ2_TXBUFFERENDIDXOFTXPDUINFO                             
#define COM_EQ2_TXBUFFERLENGTHOFTXPDUINFO                             
#define COM_EQ2_TXBUFFERSTARTIDXOFTXPDUINFO                           
#define COM_EQ2_TXBUFFERUSEDOFTXPDUINFO                               
#define COM_EQ2_TXPDUINITVALUEENDIDXOFTXPDUINFO                       
#define COM_EQ2_TXPDUINITVALUESTARTIDXOFTXPDUINFO                     
#define COM_EQ2_TXPDUINITVALUEUSEDOFTXPDUINFO                         
#define COM_EQ2_TXSIGGRPINFOINDENDIDXOFTXPDUINFO                      
#define COM_EQ2_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO                    
#define COM_EQ2_TXSIGGRPINFOINDUSEDOFTXPDUINFO                        
#define COM_EQ2_TXPDUINITVALUE                                        
#define COM_EQ2_PDUOFFSETOFTXSIGGRPINFO                               
#define COM_EQ2_TRANSFERPROPERTYOFTXSIGGRPINFO                        
#define COM_EQ2_TXBUFFERENDIDXOFTXSIGGRPINFO                          
#define COM_EQ2_TXBUFFERLENGTHOFTXSIGGRPINFO                          
#define COM_EQ2_TXBUFFERSIGGRPINTXIPDUENDIDXOFTXSIGGRPINFO            
#define COM_EQ2_TXBUFFERSIGGRPINTXIPDULENGTHOFTXSIGGRPINFO            
#define COM_EQ2_TXBUFFERSIGGRPINTXIPDUSTARTIDXOFTXSIGGRPINFO          
#define COM_EQ2_TXBUFFERSTARTIDXOFTXSIGGRPINFO                        
#define COM_EQ2_TXBUFFERUSEDOFTXSIGGRPINFO                            
#define COM_EQ2_TXPDUINFOIDXOFTXSIGGRPINFO                            
#define COM_EQ2_TXSIGGRPMASKENDIDXOFTXSIGGRPINFO                      
#define COM_EQ2_TXSIGGRPMASKLENGTHOFTXSIGGRPINFO                      
#define COM_EQ2_TXSIGGRPMASKSTARTIDXOFTXSIGGRPINFO                    
#define COM_EQ2_TXSIGGRPMASKUSEDOFTXSIGGRPINFO                        
#define COM_EQ2_TXSIGGRPINFOIND                                       
#define COM_EQ2_TXSIGGRPMASK                                          
#define COM_EQ2_APPLTYPEOFTXSIGINFO                                   
#define COM_EQ2_BITLENGTHOFTXSIGINFO                                  
#define COM_EQ2_BITPOSITIONOFTXSIGINFO                                
#define COM_EQ2_BUSACCOFTXSIGINFO                                     
#define COM_EQ2_BYTELENGTHOFTXSIGINFO                                 
#define COM_EQ2_BYTEPOSITIONOFTXSIGINFO                               
#define COM_EQ2_STARTBYTEINPDUPOSITIONOFTXSIGINFO                     
#define COM_EQ2_TXBUFFERENDIDXOFTXSIGINFO                             
#define COM_EQ2_TXBUFFERLENGTHOFTXSIGINFO                             
#define COM_EQ2_TXBUFFERSTARTIDXOFTXSIGINFO                           
#define COM_EQ2_TXBUFFERUSEDOFTXSIGINFO                               
#define COM_EQ2_TXPDUINFOIDXOFTXSIGINFO                               
#define COM_EQ2_TXSIGGRPINFOIDXOFTXSIGINFO                            
#define COM_EQ2_TXSIGGRPINFOUSEDOFTXSIGINFO                           
#define COM_EQ2_ACTIVATABLERXCOMIPDUSOFPCCONFIG                       Com_ActivatableRxComIPdus
#define COM_EQ2_ACTIVATABLETXCOMIPDUSOFPCCONFIG                       Com_ActivatableTxComIPdus
#define COM_EQ2_CONSTVALUEFLOAT32OFPCCONFIG                           Com_ConstValueFloat32
#define COM_EQ2_CONSTVALUESINT16OFPCCONFIG                            Com_ConstValueSInt16
#define COM_EQ2_CONSTVALUEUINT16OFPCCONFIG                            Com_ConstValueUInt16
#define COM_EQ2_CONSTVALUEUINT8OFPCCONFIG                             Com_ConstValueUInt8
#define COM_EQ2_CURRENTTXMODEOFPCCONFIG                               Com_CurrentTxMode
#define COM_EQ2_CYCLETIMECNTOFPCCONFIG                                Com_CycleTimeCnt
#define COM_EQ2_CYCLICSENDREQUESTOFPCCONFIG                           Com_CyclicSendRequest
#define COM_EQ2_DELAYTIMECNTOFPCCONFIG                                Com_DelayTimeCnt
#define COM_EQ2_GATEWAYPROCESSINGISRLOCKCOUNTEROFPCCONFIG             (&(Com_GatewayProcessingISRLockCounter))
#define COM_EQ2_HANDLERXPDUDEFERREDOFPCCONFIG                         Com_HandleRxPduDeferred.raw
#define COM_EQ2_INITIALIZEDOFPCCONFIG                                 (&(Com_Initialized))
#define COM_EQ2_PDUGRPVECTOROFPCCONFIG                                Com_PduGrpVector
#define COM_EQ2_REPCNTOFPCCONFIG                                      Com_RepCnt
#define COM_EQ2_REPCYCLECNTOFPCCONFIG                                 Com_RepCycleCnt
#define COM_EQ2_RXACCESSINFOINDOFPCCONFIG                             Com_RxAccessInfoInd
#define COM_EQ2_RXACCESSINFOOFPCCONFIG                                Com_RxAccessInfo
#define COM_EQ2_RXDEADLINEMONITORINGISRLOCKCOUNTEROFPCCONFIG          (&(Com_RxDeadlineMonitoringISRLockCounter))
#define COM_EQ2_RXDEFPDUBUFFEROFPCCONFIG                              Com_RxDefPduBuffer.raw
#define COM_EQ2_RXDEFERREDPROCESSINGISRLOCKCOUNTEROFPCCONFIG          (&(Com_RxDeferredProcessingISRLockCounter))
#define COM_EQ2_RXIPDUGROUPISRLOCKCOUNTEROFPCCONFIG                   (&(Com_RxIPduGroupISRLockCounter))
#define COM_EQ2_RXPDUGRPACTIVEOFPCCONFIG                              Com_RxPduGrpActive
#define COM_EQ2_RXPDUGRPINFOOFPCCONFIG                                Com_RxPduGrpInfo
#define COM_EQ2_RXPDUINFOOFPCCONFIG                                   Com_RxPduInfo
#define COM_EQ2_RXSIGBUFFERFLOAT32OFPCCONFIG                          Com_RxSigBufferFloat32
#define COM_EQ2_RXSIGBUFFERSINT16OFPCCONFIG                           Com_RxSigBufferSInt16
#define COM_EQ2_RXSIGBUFFERUINT16OFPCCONFIG                           Com_RxSigBufferUInt16
#define COM_EQ2_RXSIGBUFFERUINT8OFPCCONFIG                            Com_RxSigBufferUInt8
#define COM_EQ2_RXSIGINFOOFPCCONFIG                                   Com_RxSigInfo
#define COM_EQ2_SIGGRPEVENTFLAGOFPCCONFIG                             Com_SigGrpEventFlag
#define COM_EQ2_TRANSMITREQUESTOFPCCONFIG                             Com_TransmitRequest
#define COM_EQ2_TXBUFFEROFPCCONFIG                                    Com_TxBuffer
#define COM_EQ2_TXCYCLICPROCESSINGISRLOCKCOUNTEROFPCCONFIG            (&(Com_TxCyclicProcessingISRLockCounter))
#define COM_EQ2_TXDEADLINEMONITORINGISRLOCKCOUNTEROFPCCONFIG          (&(Com_TxDeadlineMonitoringISRLockCounter))
#define COM_EQ2_TXIPDUGROUPISRLOCKCOUNTEROFPCCONFIG                   (&(Com_TxIPduGroupISRLockCounter))
#define COM_EQ2_TXMODEFALSEOFPCCONFIG                                 Com_TxModeFalse
#define COM_EQ2_TXMODEINFOOFPCCONFIG                                  Com_TxModeInfo
#define COM_EQ2_TXMODETRUEOFPCCONFIG                                  Com_TxModeTrue
#define COM_EQ2_TXPDUGRPACTIVEOFPCCONFIG                              Com_TxPduGrpActive
#define COM_EQ2_TXPDUGRPINFOOFPCCONFIG                                Com_TxPduGrpInfo
#define COM_EQ2_TXPDUINFOOFPCCONFIG                                   Com_TxPduInfo
#define COM_EQ2_TXPDUINITVALUEOFPCCONFIG                              Com_TxPduInitValue
#define COM_EQ2_TXPROCESSINGISRLOCKCOUNTEROFPCCONFIG                  (&(Com_TxProcessingISRLockCounter))
#define COM_EQ2_TXSDULENGTHOFPCCONFIG                                 Com_TxSduLength
#define COM_EQ2_TXSIGGRPINFOINDOFPCCONFIG                             Com_TxSigGrpInfoInd
#define COM_EQ2_TXSIGGRPINFOOFPCCONFIG                                Com_TxSigGrpInfo
#define COM_EQ2_TXSIGGRPMASKOFPCCONFIG                                Com_TxSigGrpMask
#define COM_EQ2_TXSIGINFOOFPCCONFIG                                   Com_TxSigInfo
/** 
  \}
*/ 

/** 
  \defgroup  ComPCSymbolicInitializationPointers  Com Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define Com_Config_Ptr                                                NULL_PTR  /**< symbolic identifier which shall be used to initialize 'Com' */
/** 
  \}
*/ 

/** 
  \defgroup  ComPCInitializationSymbols  Com Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define Com_Config                                                    NULL_PTR  /**< symbolic identifier which could be used to initialize 'Com */
/** 
  \}
*/ 

/** 
  \defgroup  ComPCGeneral  Com General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define COM_CHECK_INIT_POINTER                                        STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define COM_FINAL_MAGIC_NUMBER                                        0x321Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of Com */
#define COM_INDIVIDUAL_POSTBUILD                                      STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'Com' is not configured to be postbuild capable. */
#define COM_INIT_DATA                                                 COM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define COM_INIT_DATA_HASH_CODE                                       -917688657  /**< the precompile constant to validate the initialization structure at initialization time of Com with a hashcode. The seed value is '0x321Eu' */
#define COM_USE_ECUM_BSW_ERROR_HOOK                                   STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define COM_USE_INIT_POINTER                                          STD_OFF  /**< STD_ON if the init pointer Com shall be used. */
/** 
  \}
*/ 



/* General */
#define COM_DEV_ERROR_DETECT                 STD_ON  /**< /ActiveEcuC/Com/ComGeneral[0:ComSafeBswChecks] || /ActiveEcuC/Com/ComGeneral[0:ComConfigurationUseDet] */
#define COM_DEV_ERROR_REPORT                 STD_ON  /**< /ActiveEcuC/Com/ComGeneral[0:ComConfigurationUseDet] */
#define COM_RETRY_FAILED_TRANSMIT_REQUESTS   STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComRetryFailedTransmitRequests] */
#define COM_IPDUCALLOUT_USEPDUINFOPTR        STD_ON  /**< /ActiveEcuC/Com/ComGeneral[0:ComAdvancedIPduCallouts] */

/* Optimization */
#define COM_RECEIVE_SIGNAL_MACRO_API         STD_OFF

/* API */
#define COM_COMMUNICATION_INTERFACE          STD_ON  /**< /ActiveEcuC/PduR/Com[0:PduRCommunicationInterface] */
#define COM_TRANSPORT_PROTOCOL               STD_OFF  /**< /ActiveEcuC/PduR/Com[0:PduRTransportProtocol] */

#define COM_TRIGGER_TRANSMIT_API             STD_OFF  /**< /ActiveEcuC/PduR/Com[0:PduRTriggertransmit] */
#define COM_TX_CONFIRMATION_API              STD_ON  /**< /ActiveEcuC/PduR/Com[0:PduRTxConfirmation] */
#define COM_TRIGGER_IPDU_SEND_WITH_META_DATA_API    STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComMetaDataSupport] */
#define COM_MAIN_FUNCTION_ROUTE_SIGNALS_API  STD_OFF
#define COM_ENABLE_SIGNAL_GROUP_ARRAY_API    STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComEnableSignalGroupArrayApi] */

#define COM_VERSION_INFO_API                 STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComVersionInfoApi] */
#define COM_GENERATED_DESCRIPTION_ROUTING    STD_OFF  /**< /ActiveEcuC/Com/ComGeneral[0:ComDescriptionRoutingCodeGeneration] */

#define COM_LMGT_MAXIPDUGROUPVECTORBYTECNT   2U
#define COM_SUPPORTED_IPDU_GROUPS            11uL  /**< /ActiveEcuC/Com/ComGeneral[0:ComSupportedIPduGroups] */

#define COM_RXIMMEDIATEFCTPTRCACHE           STD_OFF
#define COM_RXIMMEDIATEFCTPTRCACHESIZE       0U

/**
  \brief  Constants to compare floating-point values according to ISO C-99 standard.
  \details  -
    \{
*/
#define COM_FLT_EPSILON                      1E-5
#define COM_DBL_EPSILON                      1E-9
/**
  \}
*/




/**
 * \defgroup ComHandleIdsComRxSig Handle IDs of handle space ComRxSig.
 * \brief Rx Signals
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComSignal_ADataRawSafeALat_oVddmPropFr09_oCAN00_a776222d_Rx 0u
#define ComConf_ComSignal_ADataRawSafeALgt_oVddmPropFr09_oCAN00_4abc5057_Rx 1u
#define ComConf_ComSignal_ADataRawSafeAVert_oVddmPropFr09_oCAN00_5affce16_Rx 2u
#define ComConf_ComSignal_AccrPedlRatAccrPedlRat_oEcmPropFr00_oCAN00_4ad8b74f_Rx 3u
#define ComConf_ComSignal_AgDataRawSafeRollRate_oVddmPropFr12_oCAN00_938781d5_Rx 4u
#define ComConf_ComSignal_AgDataRawSafeYawRate_oVddmPropFr12_oCAN00_ab257c3a_Rx 5u
#define ComConf_ComSignal_BrkFricTqAtWhlFrntLeAct_oVddmPropFr10_oCAN00_b6b8e9ec_Rx 6u
#define ComConf_ComSignal_BrkFricTqAtWhlFrntRiAct_oVddmPropFr10_oCAN00_a1ab9bd5_Rx 7u
#define ComConf_ComSignal_BrkFricTqAtWhlReLeAct_oVddmPropFr10_oCAN00_8d4d2f89_Rx 8u
#define ComConf_ComSignal_BrkFricTqAtWhlReRiAct_oVddmPropFr10_oCAN00_9a5e5db0_Rx 9u
#define ComConf_ComSignal_BrkPedlPsdBrkPedlNotPsdSafe_oVddmPropFr05_oCAN00_6dd71a9b_Rx 10u
#define ComConf_ComSignal_BrkPedlPsdBrkPedlPsd_oVddmPropFr05_oCAN00_dcf25825_Rx 11u
#define ComConf_ComSignal_BrkTqAtWhlsReq_oVddmPropFr08_oCAN00_2a675d21_Rx 12u
#define ComConf_ComSignal_GearLvrIndcn_oEcmPropFr24_oCAN00_fa2560a8_Rx 13u
#define ComConf_ComSignal_HvSysSts_oBecmPropFr01_oCAN00_919ec934_Rx   14u
#define ComConf_ComSignal_PtTqAtAxleFrntAct_oEcmPropFr07_oCAN00_59efea99_Rx 15u
#define ComConf_ComSignal_PtTqAtAxleFrntReq_oVddmPropFr08_oCAN00_b5a3120c_Rx 16u
#define ComConf_ComSignal_PtTqAtAxleReReq_oVddmPropFr08_oCAN00_ecdac0ff_Rx 17u
#define ComConf_ComSignal_PtTqAtWhlFrntLeAct_oEcmPropFr07_oCAN00_2226bbb1_Rx 18u
#define ComConf_ComSignal_PtTqAtWhlFrntRiAct_oEcmPropFr07_oCAN00_86eac12f_Rx 19u
#define ComConf_ComSignal_Sig_Mot_Current_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_7013e7f5_Rx 20u
#define ComConf_ComSignal_Sig_Mot_Current_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_0d36ed6f_Rx 21u
#define ComConf_ComSignal_Sig_Mot_Current_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_6f298d95_Rx 22u
#define ComConf_ComSignal_Sig_Mot_Current_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_120c870f_Rx 23u
#define ComConf_ComSignal_Sig_Mot_Diags_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_940a4d73_Rx 24u
#define ComConf_ComSignal_Sig_Mot_Diags_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_e92f47e9_Rx 25u
#define ComConf_ComSignal_Sig_Mot_Diags_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_8b302713_Rx 26u
#define ComConf_ComSignal_Sig_Mot_Diags_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_f6152d89_Rx 27u
#define ComConf_ComSignal_Sig_Mot_Mode_commandFL_FrPC_oMSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_4378bd23_Rx 28u
#define ComConf_ComSignal_Sig_Mot_Mode_commandFR_FrPC_oMSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_2af2baa2_Rx 29u
#define ComConf_ComSignal_Sig_Mot_Mode_commandRL_FrPC_oMSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_193391c2_Rx 30u
#define ComConf_ComSignal_Sig_Mot_Mode_commandRR_FrPC_oMSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_70b99643_Rx 31u
#define ComConf_ComSignal_Sig_Mot_Mode_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_880421cb_Rx 32u
#define ComConf_ComSignal_Sig_Mot_Mode_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_f5212b51_Rx 33u
#define ComConf_ComSignal_Sig_Mot_Mode_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_973e4bab_Rx 34u
#define ComConf_ComSignal_Sig_Mot_Mode_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ea1b4131_Rx 35u
#define ComConf_ComSignal_Sig_Mot_Pos_commandFL_FrPC_oMSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_1f1f7c0c_Rx 36u
#define ComConf_ComSignal_Sig_Mot_Pos_commandFR_FrPC_oMSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_76957b8d_Rx 37u
#define ComConf_ComSignal_Sig_Mot_Pos_commandRL_FrPC_oMSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_455450ed_Rx 38u
#define ComConf_ComSignal_Sig_Mot_Pos_commandRR_FrPC_oMSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_2cde576c_Rx 39u
#define ComConf_ComSignal_Sig_Mot_Pos_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_5071d764_Rx 40u
#define ComConf_ComSignal_Sig_Mot_Pos_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_2d54ddfe_Rx 41u
#define ComConf_ComSignal_Sig_Mot_Pos_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_4f4bbd04_Rx 42u
#define ComConf_ComSignal_Sig_Mot_Pos_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_326eb79e_Rx 43u
#define ComConf_ComSignal_Sig_Mot_Speed_commandFL_FrPC_oMSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_86e41f3b_Rx 44u
#define ComConf_ComSignal_Sig_Mot_Speed_commandFR_FrPC_oMSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_ef6e18ba_Rx 45u
#define ComConf_ComSignal_Sig_Mot_Speed_commandRL_FrPC_oMSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_dcaf33da_Rx 46u
#define ComConf_ComSignal_Sig_Mot_Speed_commandRR_FrPC_oMSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_b525345b_Rx 47u
#define ComConf_ComSignal_Sig_Mot_Speed_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_05cd1d48_Rx 48u
#define ComConf_ComSignal_Sig_Mot_Speed_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_78e817d2_Rx 49u
#define ComConf_ComSignal_Sig_Mot_Speed_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_1af77728_Rx 50u
#define ComConf_ComSignal_Sig_Mot_Speed_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_67d27db2_Rx 51u
#define ComConf_ComSignal_Sig_Mot_State_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_115de03b_Rx 52u
#define ComConf_ComSignal_Sig_Mot_State_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_6c78eaa1_Rx 53u
#define ComConf_ComSignal_Sig_Mot_State_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_0e678a5b_Rx 54u
#define ComConf_ComSignal_Sig_Mot_State_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_734280c1_Rx 55u
#define ComConf_ComSignal_Sig_Mot_Temp_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_811760c8_Rx 56u
#define ComConf_ComSignal_Sig_Mot_Temp_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_fc326a52_Rx 57u
#define ComConf_ComSignal_Sig_Mot_Temp_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_9e2d0aa8_Rx 58u
#define ComConf_ComSignal_Sig_Mot_Temp_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_e3080032_Rx 59u
#define ComConf_ComSignal_Sig_Mot_Torque_commandFL_FrPC_oMSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_798d9eb1_Rx 60u
#define ComConf_ComSignal_Sig_Mot_Torque_commandFR_FrPC_oMSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_10079930_Rx 61u
#define ComConf_ComSignal_Sig_Mot_Torque_commandRL_FrPC_oMSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_23c6b250_Rx 62u
#define ComConf_ComSignal_Sig_Mot_Torque_commandRR_FrPC_oMSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_4a4cb5d1_Rx 63u
#define ComConf_ComSignal_Sig_Mot_Torque_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_f956be0b_Rx 64u
#define ComConf_ComSignal_Sig_Mot_Torque_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_8473b491_Rx 65u
#define ComConf_ComSignal_Sig_Mot_Torque_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e66cd46b_Rx 66u
#define ComConf_ComSignal_Sig_Mot_Torque_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_9b49def1_Rx 67u
#define ComConf_ComSignal_Sig_Mot_Voltage_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_31f62729_Rx 68u
#define ComConf_ComSignal_Sig_Mot_Voltage_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_4cd32db3_Rx 69u
#define ComConf_ComSignal_Sig_Mot_Voltage_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_2ecc4d49_Rx 70u
#define ComConf_ComSignal_Sig_Mot_Voltage_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_53e947d3_Rx 71u
#define ComConf_ComSignal_Sig_Mot_commandFL_FrPC_oMSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_fb218646_Rx 72u
#define ComConf_ComSignal_Sig_Mot_commandFR_FrPC_oMSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_92ab81c7_Rx 73u
#define ComConf_ComSignal_Sig_Mot_commandRL_FrPC_oMSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_a16aaaa7_Rx 74u
#define ComConf_ComSignal_Sig_Mot_commandRR_FrPC_oMSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_c8e0ad26_Rx 75u
#define ComConf_ComSignal_Sig_Valve1_DutyCycle_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_a5032589_Rx 76u
#define ComConf_ComSignal_Sig_Valve1_FWtimeOFF0_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_cdb96a4e_Rx 77u
#define ComConf_ComSignal_Sig_Valve1_Frequency_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_84915280_Rx 78u
#define ComConf_ComSignal_Sig_Valve1_Ibias_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_16ed333d_Rx 79u
#define ComConf_ComSignal_Sig_Valve1_IboostB_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_c914d65f_Rx 80u
#define ComConf_ComSignal_Sig_Valve1_IboostP_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_946a5245_Rx 81u
#define ComConf_ComSignal_Sig_Valve1_Ihold_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_6df9b71a_Rx 82u
#define ComConf_ComSignal_Sig_Valve1_Ipeak_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_af0de4c2_Rx 83u
#define ComConf_ComSignal_Sig_Valve1_MDAswitchPC_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_6ab83b1c_Rx 84u
#define ComConf_ComSignal_Sig_Valve1_Mode_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_87ad547b_Rx 85u
#define ComConf_ComSignal_Sig_Valve1_State_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_93106638_Rx 86u
#define ComConf_ComSignal_Sig_Valve1_Tbias_off_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_275b00ec_Rx 87u
#define ComConf_ComSignal_Sig_Valve1_Tbias_tot_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_733ed7db_Rx 88u
#define ComConf_ComSignal_Sig_Valve1_Tbypass_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_21bc9bdf_Rx 89u
#define ComConf_ComSignal_Sig_Valve1_Thold_off_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_15fb5bd6_Rx 90u
#define ComConf_ComSignal_Sig_Valve1_Thold_tot_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_419e8ce1_Rx 91u
#define ComConf_ComSignal_Sig_Valve1_Tpeak_off_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_9d5bdd6c_Rx 92u
#define ComConf_ComSignal_Sig_Valve1_Tpeak_tot_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_c93e0a5b_Rx 93u
#define ComConf_ComSignal_Sig_Valve2_DutyCycle_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_683212a7_Rx 94u
#define ComConf_ComSignal_Sig_Valve2_FWtimeOFF0_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_3f59c6a3_Rx 95u
#define ComConf_ComSignal_Sig_Valve2_Frequency_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_49a065ae_Rx 96u
#define ComConf_ComSignal_Sig_Valve2_Ibias_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_060cdf30_Rx 97u
#define ComConf_ComSignal_Sig_Valve2_IboostB_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_960e99ce_Rx 98u
#define ComConf_ComSignal_Sig_Valve2_IboostP_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_cb701dd4_Rx 99u
#define ComConf_ComSignal_Sig_Valve2_Ihold_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_7d185b17_Rx 100u
#define ComConf_ComSignal_Sig_Valve2_Ipeak_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_bfec08cf_Rx 101u
#define ComConf_ComSignal_Sig_Valve2_MDAswitchPC_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_9a0ad560_Rx 102u
#define ComConf_ComSignal_Sig_Valve2_Mode_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f3a6979c_Rx 103u
#define ComConf_ComSignal_Sig_Valve2_State_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_83f18a35_Rx 104u
#define ComConf_ComSignal_Sig_Valve2_Tbias_off_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_ea6a37c2_Rx 105u
#define ComConf_ComSignal_Sig_Valve2_Tbias_tot_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_be0fe0f5_Rx 106u
#define ComConf_ComSignal_Sig_Valve2_Tbypass_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_7ea6d44e_Rx 107u
#define ComConf_ComSignal_Sig_Valve2_Thold_off_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_d8ca6cf8_Rx 108u
#define ComConf_ComSignal_Sig_Valve2_Thold_tot_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_8cafbbcf_Rx 109u
#define ComConf_ComSignal_Sig_Valve2_Tpeak_off_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_506aea42_Rx 110u
#define ComConf_ComSignal_Sig_Valve2_Tpeak_tot_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_040f3d75_Rx 111u
#define ComConf_ComSignal_Sig_Valve3_DutyCycle_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_9a0dfd82_Rx 112u
#define ComConf_ComSignal_Sig_Valve3_FWtimeOFF0_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6ef9a2f8_Rx 113u
#define ComConf_ComSignal_Sig_Valve3_Frequency_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_bb9f8a8b_Rx 114u
#define ComConf_ComSignal_Sig_Valve3_Ibias_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_bf7c86f4_Rx 115u
#define ComConf_ComSignal_Sig_Valve3_IboostB_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_15d7a17e_Rx 116u
#define ComConf_ComSignal_Sig_Valve3_IboostP_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_48a92564_Rx 117u
#define ComConf_ComSignal_Sig_Valve3_Ihold_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_c46802d3_Rx 118u
#define ComConf_ComSignal_Sig_Valve3_Ipeak_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_069c510b_Rx 119u
#define ComConf_ComSignal_Sig_Valve3_MDAswitchPC_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_7cb4728b_Rx 120u
#define ComConf_ComSignal_Sig_Valve3_Mode_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6970d4fe_Rx 121u
#define ComConf_ComSignal_Sig_Valve3_State_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_3a81d3f1_Rx 122u
#define ComConf_ComSignal_Sig_Valve3_Tbias_off_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_1855d8e7_Rx 123u
#define ComConf_ComSignal_Sig_Valve3_Tbias_tot_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_4c300fd0_Rx 124u
#define ComConf_ComSignal_Sig_Valve3_Tbypass_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_fd7fecfe_Rx 125u
#define ComConf_ComSignal_Sig_Valve3_Thold_off_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_2af583dd_Rx 126u
#define ComConf_ComSignal_Sig_Valve3_Thold_tot_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_7e9054ea_Rx 127u
#define ComConf_ComSignal_Sig_Valve3_Tpeak_off_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_a2550567_Rx 128u
#define ComConf_ComSignal_Sig_Valve3_Tpeak_tot_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_f630d250_Rx 129u
#define ComConf_ComSignal_Sig_Valve4_DutyCycle_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_29217aba_Rx 130u
#define ComConf_ComSignal_Sig_Valve4_FWtimeOFF0_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_01e99938_Rx 131u
#define ComConf_ComSignal_Sig_Valve4_Frequency_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_08b30db3_Rx 132u
#define ComConf_ComSignal_Sig_Valve4_Ibias_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_27cf072a_Rx 133u
#define ComConf_ComSignal_Sig_Valve4_IboostB_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_283a06ec_Rx 134u
#define ComConf_ComSignal_Sig_Valve4_IboostP_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_754482f6_Rx 135u
#define ComConf_ComSignal_Sig_Valve4_Ihold_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_5cdb830d_Rx 136u
#define ComConf_ComSignal_Sig_Valve4_Ipeak_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_9e2fd0d5_Rx 137u
#define ComConf_ComSignal_Sig_Valve4_MDAswitchPC_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_a01e0fd9_Rx 138u
#define ComConf_ComSignal_Sig_Valve4_Mode_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_1bb11052_Rx 139u
#define ComConf_ComSignal_Sig_Valve4_State_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_a232522f_Rx 140u
#define ComConf_ComSignal_Sig_Valve4_Tbias_off_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_ab795fdf_Rx 141u
#define ComConf_ComSignal_Sig_Valve4_Tbias_tot_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_ff1c88e8_Rx 142u
#define ComConf_ComSignal_Sig_Valve4_Tbypass_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_c0924b6c_Rx 143u
#define ComConf_ComSignal_Sig_Valve4_Thold_off_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_99d904e5_Rx 144u
#define ComConf_ComSignal_Sig_Valve4_Thold_tot_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_cdbcd3d2_Rx 145u
#define ComConf_ComSignal_Sig_Valve4_Tpeak_off_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_1179825f_Rx 146u
#define ComConf_ComSignal_Sig_Valve4_Tpeak_tot_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_451c5568_Rx 147u
#define ComConf_ComSignal_Sig_Valve5_DutyCycle_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_db1e959f_Rx 148u
#define ComConf_ComSignal_Sig_Valve5_FWtimeOFF0_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_5049fd63_Rx 149u
#define ComConf_ComSignal_Sig_Valve5_Frequency_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_fa8ce296_Rx 150u
#define ComConf_ComSignal_Sig_Valve5_Ibias_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_9ebf5eee_Rx 151u
#define ComConf_ComSignal_Sig_Valve5_IboostB_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_abe33e5c_Rx 152u
#define ComConf_ComSignal_Sig_Valve5_IboostP_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_f69dba46_Rx 153u
#define ComConf_ComSignal_Sig_Valve5_Ihold_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_e5abdac9_Rx 154u
#define ComConf_ComSignal_Sig_Valve5_Ipeak_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_275f8911_Rx 155u
#define ComConf_ComSignal_Sig_Valve5_MDAswitchPC_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_46a0a832_Rx 156u
#define ComConf_ComSignal_Sig_Valve5_Mode_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_81675330_Rx 157u
#define ComConf_ComSignal_Sig_Valve5_State_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_1b420beb_Rx 158u
#define ComConf_ComSignal_Sig_Valve5_Tbias_off_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_5946b0fa_Rx 159u
#define ComConf_ComSignal_Sig_Valve5_Tbias_tot_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_0d2367cd_Rx 160u
#define ComConf_ComSignal_Sig_Valve5_Tbypass_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_434b73dc_Rx 161u
#define ComConf_ComSignal_Sig_Valve5_Thold_off_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_6be6ebc0_Rx 162u
#define ComConf_ComSignal_Sig_Valve5_Thold_tot_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_3f833cf7_Rx 163u
#define ComConf_ComSignal_Sig_Valve5_Tpeak_off_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_e3466d7a_Rx 164u
#define ComConf_ComSignal_Sig_Valve5_Tpeak_tot_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_b723ba4d_Rx 165u
#define ComConf_ComSignal_Sig_Valve6_DutyCycle_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_162fa2b1_Rx 166u
#define ComConf_ComSignal_Sig_Valve6_FWtimeOFF0_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_a2a9518e_Rx 167u
#define ComConf_ComSignal_Sig_Valve6_Frequency_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_37bdd5b8_Rx 168u
#define ComConf_ComSignal_Sig_Valve6_Ibias_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_8e5eb2e3_Rx 169u
#define ComConf_ComSignal_Sig_Valve6_IboostB_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f4f971cd_Rx 170u
#define ComConf_ComSignal_Sig_Valve6_IboostP_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_a987f5d7_Rx 171u
#define ComConf_ComSignal_Sig_Valve6_Ihold_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f54a36c4_Rx 172u
#define ComConf_ComSignal_Sig_Valve6_Ipeak_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_37be651c_Rx 173u
#define ComConf_ComSignal_Sig_Valve6_MDAswitchPC_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_b612464e_Rx 174u
#define ComConf_ComSignal_Sig_Valve6_Mode_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f56c90d7_Rx 175u
#define ComConf_ComSignal_Sig_Valve6_State_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_0ba3e7e6_Rx 176u
#define ComConf_ComSignal_Sig_Valve6_Tbias_off_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_947787d4_Rx 177u
#define ComConf_ComSignal_Sig_Valve6_Tbias_tot_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_c01250e3_Rx 178u
#define ComConf_ComSignal_Sig_Valve6_Tbypass_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_1c513c4d_Rx 179u
#define ComConf_ComSignal_Sig_Valve6_Thold_off_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_a6d7dcee_Rx 180u
#define ComConf_ComSignal_Sig_Valve6_Thold_tot_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f2b20bd9_Rx 181u
#define ComConf_ComSignal_Sig_Valve6_Tpeak_off_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_2e775a54_Rx 182u
#define ComConf_ComSignal_Sig_Valve6_Tpeak_tot_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_7a128d63_Rx 183u
#define ComConf_ComSignal_Sig_Valve7_DutyCycle_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_e4104d94_Rx 184u
#define ComConf_ComSignal_Sig_Valve7_FWtimeOFF0_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_f30935d5_Rx 185u
#define ComConf_ComSignal_Sig_Valve7_Frequency_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_c5823a9d_Rx 186u
#define ComConf_ComSignal_Sig_Valve7_Ibias_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_372eeb27_Rx 187u
#define ComConf_ComSignal_Sig_Valve7_IboostB_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_7720497d_Rx 188u
#define ComConf_ComSignal_Sig_Valve7_IboostP_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_2a5ecd67_Rx 189u
#define ComConf_ComSignal_Sig_Valve7_Ihold_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_4c3a6f00_Rx 190u
#define ComConf_ComSignal_Sig_Valve7_Ipeak_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_8ece3cd8_Rx 191u
#define ComConf_ComSignal_Sig_Valve7_MDAswitchPC_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_50ace1a5_Rx 192u
#define ComConf_ComSignal_Sig_Valve7_Mode_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6fbad3b5_Rx 193u
#define ComConf_ComSignal_Sig_Valve7_State_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_b2d3be22_Rx 194u
#define ComConf_ComSignal_Sig_Valve7_Tbias_off_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_664868f1_Rx 195u
#define ComConf_ComSignal_Sig_Valve7_Tbias_tot_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_322dbfc6_Rx 196u
#define ComConf_ComSignal_Sig_Valve7_Tbypass_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_9f8804fd_Rx 197u
#define ComConf_ComSignal_Sig_Valve7_Thold_off_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_54e833cb_Rx 198u
#define ComConf_ComSignal_Sig_Valve7_Thold_tot_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_008de4fc_Rx 199u
#define ComConf_ComSignal_Sig_Valve7_Tpeak_off_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_dc48b571_Rx 200u
#define ComConf_ComSignal_Sig_Valve7_Tpeak_tot_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_882d6246_Rx 201u
#define ComConf_ComSignal_Sig_Valve8_DutyCycle_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_ab07aa80_Rx 202u
#define ComConf_ComSignal_Sig_Valve8_FWtimeOFF0_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_7c89260e_Rx 203u
#define ComConf_ComSignal_Sig_Valve8_Frequency_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_8a95dd89_Rx 204u
#define ComConf_ComSignal_Sig_Valve8_Ibias_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_6448b71e_Rx 205u
#define ComConf_ComSignal_Sig_Valve8_IboostB_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_8f223ee9_Rx 206u
#define ComConf_ComSignal_Sig_Valve8_IboostP_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_d25cbaf3_Rx 207u
#define ComConf_ComSignal_Sig_Valve8_Ihold_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_1f5c3339_Rx 208u
#define ComConf_ComSignal_Sig_Valve8_Ipeak_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_dda860e1_Rx 209u
#define ComConf_ComSignal_Sig_Valve8_MDAswitchPC_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_d437baab_Rx 210u
#define ComConf_ComSignal_Sig_Valve8_Mode_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_10ef198f_Rx 211u
#define ComConf_ComSignal_Sig_Valve8_State_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_e1b5e21b_Rx 212u
#define ComConf_ComSignal_Sig_Valve8_Tbias_off_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_295f8fe5_Rx 213u
#define ComConf_ComSignal_Sig_Valve8_Tbias_tot_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_7d3a58d2_Rx 214u
#define ComConf_ComSignal_Sig_Valve8_Tbypass_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_678a7369_Rx 215u
#define ComConf_ComSignal_Sig_Valve8_Thold_off_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_1bffd4df_Rx 216u
#define ComConf_ComSignal_Sig_Valve8_Thold_tot_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_4f9a03e8_Rx 217u
#define ComConf_ComSignal_Sig_Valve8_Tpeak_off_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_935f5265_Rx 218u
#define ComConf_ComSignal_Sig_Valve8_Tpeak_tot_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_c73a8552_Rx 219u
#define ComConf_ComSignal_Sig_Valve9_DutyCycle_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_593845a5_Rx 220u
#define ComConf_ComSignal_Sig_Valve9_FWtimeOFF0_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_2d294255_Rx 221u
#define ComConf_ComSignal_Sig_Valve9_Frequency_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_78aa32ac_Rx 222u
#define ComConf_ComSignal_Sig_Valve9_Ibias_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_dd38eeda_Rx 223u
#define ComConf_ComSignal_Sig_Valve9_IboostB_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_0cfb0659_Rx 224u
#define ComConf_ComSignal_Sig_Valve9_IboostP_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_51858243_Rx 225u
#define ComConf_ComSignal_Sig_Valve9_Ihold_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_a62c6afd_Rx 226u
#define ComConf_ComSignal_Sig_Valve9_Ipeak_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_64d83925_Rx 227u
#define ComConf_ComSignal_Sig_Valve9_MDAswitchPC_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_32891d40_Rx 228u
#define ComConf_ComSignal_Sig_Valve9_Mode_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_8a395aed_Rx 229u
#define ComConf_ComSignal_Sig_Valve9_State_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_58c5bbdf_Rx 230u
#define ComConf_ComSignal_Sig_Valve9_Tbias_off_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_db6060c0_Rx 231u
#define ComConf_ComSignal_Sig_Valve9_Tbias_tot_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_8f05b7f7_Rx 232u
#define ComConf_ComSignal_Sig_Valve9_Tbypass_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_e4534bd9_Rx 233u
#define ComConf_ComSignal_Sig_Valve9_Thold_off_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_e9c03bfa_Rx 234u
#define ComConf_ComSignal_Sig_Valve9_Thold_tot_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_bda5eccd_Rx 235u
#define ComConf_ComSignal_Sig_Valve9_Tpeak_off_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_6160bd40_Rx 236u
#define ComConf_ComSignal_Sig_Valve9_Tpeak_tot_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_35056a77_Rx 237u
#define ComConf_ComSignal_Sig_Valve10_DutyCycle_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_e5041d25_Rx 238u
#define ComConf_ComSignal_Sig_Valve10_FWtimeOFF0_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_2c61f86f_Rx 239u
#define ComConf_ComSignal_Sig_Valve10_Frequency_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_c4966a2c_Rx 240u
#define ComConf_ComSignal_Sig_Valve10_Ibias_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_9cd31f0c_Rx 241u
#define ComConf_ComSignal_Sig_Valve10_IboostB_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_65518e5a_Rx 242u
#define ComConf_ComSignal_Sig_Valve10_IboostP_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_382f0a40_Rx 243u
#define ComConf_ComSignal_Sig_Valve10_Ihold_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_e7c79b2b_Rx 244u
#define ComConf_ComSignal_Sig_Valve10_Ipeak_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_2533c8f3_Rx 245u
#define ComConf_ComSignal_Sig_Valve10_MDAswitchPC_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_18c8890a_Rx 246u
#define ComConf_ComSignal_Sig_Valve10_Mode_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_4a458887_Rx 247u
#define ComConf_ComSignal_Sig_Valve10_State_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_192e4a09_Rx 248u
#define ComConf_ComSignal_Sig_Valve10_Tbias_off_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_675c3840_Rx 249u
#define ComConf_ComSignal_Sig_Valve10_Tbias_tot_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_3339ef77_Rx 250u
#define ComConf_ComSignal_Sig_Valve10_Tbypass_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_8df9c3da_Rx 251u
#define ComConf_ComSignal_Sig_Valve10_Thold_off_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_55fc637a_Rx 252u
#define ComConf_ComSignal_Sig_Valve10_Thold_tot_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_0199b44d_Rx 253u
#define ComConf_ComSignal_Sig_Valve10_Tpeak_off_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_dd5ce5c0_Rx 254u
#define ComConf_ComSignal_Sig_Valve10_Tpeak_tot_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_893932f7_Rx 255u
#define ComConf_ComSignal_Sig_Valve11_DutyCycle_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_173bf200_Rx 256u
#define ComConf_ComSignal_Sig_Valve11_FWtimeOFF0_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_7dc19c34_Rx 257u
#define ComConf_ComSignal_Sig_Valve11_Frequency_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_36a98509_Rx 258u
#define ComConf_ComSignal_Sig_Valve11_Ibias_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_25a346c8_Rx 259u
#define ComConf_ComSignal_Sig_Valve11_IboostB_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_e688b6ea_Rx 260u
#define ComConf_ComSignal_Sig_Valve11_IboostP_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_bbf632f0_Rx 261u
#define ComConf_ComSignal_Sig_Valve11_Ihold_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_5eb7c2ef_Rx 262u
#define ComConf_ComSignal_Sig_Valve11_Ipeak_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_9c439137_Rx 263u
#define ComConf_ComSignal_Sig_Valve11_MDAswitchPC_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_fe762ee1_Rx 264u
#define ComConf_ComSignal_Sig_Valve11_Mode_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_d093cbe5_Rx 265u
#define ComConf_ComSignal_Sig_Valve11_State_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_a05e13cd_Rx 266u
#define ComConf_ComSignal_Sig_Valve11_Tbias_off_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_9563d765_Rx 267u
#define ComConf_ComSignal_Sig_Valve11_Tbias_tot_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_c1060052_Rx 268u
#define ComConf_ComSignal_Sig_Valve11_Tbypass_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0e20fb6a_Rx 269u
#define ComConf_ComSignal_Sig_Valve11_Thold_off_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_a7c38c5f_Rx 270u
#define ComConf_ComSignal_Sig_Valve11_Thold_tot_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_f3a65b68_Rx 271u
#define ComConf_ComSignal_Sig_Valve11_Tpeak_off_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_2f630ae5_Rx 272u
#define ComConf_ComSignal_Sig_Valve11_Tpeak_tot_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_7b06ddd2_Rx 273u
#define ComConf_ComSignal_Sig_Valve12_DutyCycle_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_da0ac52e_Rx 274u
#define ComConf_ComSignal_Sig_Valve12_FWtimeOFF0_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_8f2130d9_Rx 275u
#define ComConf_ComSignal_Sig_Valve12_Frequency_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_fb98b227_Rx 276u
#define ComConf_ComSignal_Sig_Valve12_Ibias_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_3542aac5_Rx 277u
#define ComConf_ComSignal_Sig_Valve12_IboostB_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_b992f97b_Rx 278u
#define ComConf_ComSignal_Sig_Valve12_IboostP_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_e4ec7d61_Rx 279u
#define ComConf_ComSignal_Sig_Valve12_Ihold_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_4e562ee2_Rx 280u
#define ComConf_ComSignal_Sig_Valve12_Ipeak_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_8ca27d3a_Rx 281u
#define ComConf_ComSignal_Sig_Valve12_MDAswitchPC_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_0ec4c09d_Rx 282u
#define ComConf_ComSignal_Sig_Valve12_Mode_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_a4980802_Rx 283u
#define ComConf_ComSignal_Sig_Valve12_State_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_b0bfffc0_Rx 284u
#define ComConf_ComSignal_Sig_Valve12_Tbias_off_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_5852e04b_Rx 285u
#define ComConf_ComSignal_Sig_Valve12_Tbias_tot_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_0c37377c_Rx 286u
#define ComConf_ComSignal_Sig_Valve12_Tbypass_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_513ab4fb_Rx 287u
#define ComConf_ComSignal_Sig_Valve12_Thold_off_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_6af2bb71_Rx 288u
#define ComConf_ComSignal_Sig_Valve12_Thold_tot_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_3e976c46_Rx 289u
#define ComConf_ComSignal_Sig_Valve12_Tpeak_off_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_e2523dcb_Rx 290u
#define ComConf_ComSignal_Sig_Valve12_Tpeak_tot_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_b637eafc_Rx 291u
#define ComConf_ComSignal_Sig_Valve13_DutyCycle_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_28352a0b_Rx 292u
#define ComConf_ComSignal_Sig_Valve13_FWtimeOFF0_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_de815482_Rx 293u
#define ComConf_ComSignal_Sig_Valve13_Frequency_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_09a75d02_Rx 294u
#define ComConf_ComSignal_Sig_Valve13_Ibias_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_8c32f301_Rx 295u
#define ComConf_ComSignal_Sig_Valve13_IboostB_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_3a4bc1cb_Rx 296u
#define ComConf_ComSignal_Sig_Valve13_IboostP_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_673545d1_Rx 297u
#define ComConf_ComSignal_Sig_Valve13_Ihold_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_f7267726_Rx 298u
#define ComConf_ComSignal_Sig_Valve13_Ipeak_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_35d224fe_Rx 299u
#define ComConf_ComSignal_Sig_Valve13_MDAswitchPC_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_e87a6776_Rx 300u
#define ComConf_ComSignal_Sig_Valve13_Mode_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_3e4e4b60_Rx 301u
#define ComConf_ComSignal_Sig_Valve13_State_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_09cfa604_Rx 302u
#define ComConf_ComSignal_Sig_Valve13_Tbias_off_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_aa6d0f6e_Rx 303u
#define ComConf_ComSignal_Sig_Valve13_Tbias_tot_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_fe08d859_Rx 304u
#define ComConf_ComSignal_Sig_Valve13_Tbypass_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_d2e38c4b_Rx 305u
#define ComConf_ComSignal_Sig_Valve13_Thold_off_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_98cd5454_Rx 306u
#define ComConf_ComSignal_Sig_Valve13_Thold_tot_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_cca88363_Rx 307u
#define ComConf_ComSignal_Sig_Valve13_Tpeak_off_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_106dd2ee_Rx 308u
#define ComConf_ComSignal_Sig_Valve13_Tpeak_tot_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_440805d9_Rx 309u
#define ComConf_ComSignal_Sig_Valve14_DutyCycle_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_9b19ad33_Rx 310u
#define ComConf_ComSignal_Sig_Valve14_FWtimeOFF0_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_b1916f42_Rx 311u
#define ComConf_ComSignal_Sig_Valve14_Frequency_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_ba8bda3a_Rx 312u
#define ComConf_ComSignal_Sig_Valve14_Ibias_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_148172df_Rx 313u
#define ComConf_ComSignal_Sig_Valve14_IboostB_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_07a66659_Rx 314u
#define ComConf_ComSignal_Sig_Valve14_IboostP_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_5ad8e243_Rx 315u
#define ComConf_ComSignal_Sig_Valve14_Ihold_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_6f95f6f8_Rx 316u
#define ComConf_ComSignal_Sig_Valve14_Ipeak_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_ad61a520_Rx 317u
#define ComConf_ComSignal_Sig_Valve14_MDAswitchPC_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_34d01a24_Rx 318u
#define ComConf_ComSignal_Sig_Valve14_Mode_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_4c8f8fcc_Rx 319u
#define ComConf_ComSignal_Sig_Valve14_State_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_917c27da_Rx 320u
#define ComConf_ComSignal_Sig_Valve14_Tbias_off_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_19418856_Rx 321u
#define ComConf_ComSignal_Sig_Valve14_Tbias_tot_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_4d245f61_Rx 322u
#define ComConf_ComSignal_Sig_Valve14_Tbypass_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_ef0e2bd9_Rx 323u
#define ComConf_ComSignal_Sig_Valve14_Thold_off_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_2be1d36c_Rx 324u
#define ComConf_ComSignal_Sig_Valve14_Thold_tot_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_7f84045b_Rx 325u
#define ComConf_ComSignal_Sig_Valve14_Tpeak_off_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_a34155d6_Rx 326u
#define ComConf_ComSignal_Sig_Valve14_Tpeak_tot_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_f72482e1_Rx 327u
#define ComConf_ComSignal_Sig_Valve15_DutyCycle_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_69264216_Rx 328u
#define ComConf_ComSignal_Sig_Valve15_FWtimeOFF0_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_e0310b19_Rx 329u
#define ComConf_ComSignal_Sig_Valve15_Frequency_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_48b4351f_Rx 330u
#define ComConf_ComSignal_Sig_Valve15_Ibias_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_adf12b1b_Rx 331u
#define ComConf_ComSignal_Sig_Valve15_IboostB_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_847f5ee9_Rx 332u
#define ComConf_ComSignal_Sig_Valve15_IboostP_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_d901daf3_Rx 333u
#define ComConf_ComSignal_Sig_Valve15_Ihold_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_d6e5af3c_Rx 334u
#define ComConf_ComSignal_Sig_Valve15_Ipeak_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_1411fce4_Rx 335u
#define ComConf_ComSignal_Sig_Valve15_MDAswitchPC_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_d26ebdcf_Rx 336u
#define ComConf_ComSignal_Sig_Valve15_Mode_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_d659ccae_Rx 337u
#define ComConf_ComSignal_Sig_Valve15_State_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_280c7e1e_Rx 338u
#define ComConf_ComSignal_Sig_Valve15_Tbias_off_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_eb7e6773_Rx 339u
#define ComConf_ComSignal_Sig_Valve15_Tbias_tot_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_bf1bb044_Rx 340u
#define ComConf_ComSignal_Sig_Valve15_Tbypass_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_6cd71369_Rx 341u
#define ComConf_ComSignal_Sig_Valve15_Thold_off_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_d9de3c49_Rx 342u
#define ComConf_ComSignal_Sig_Valve15_Thold_tot_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_8dbbeb7e_Rx 343u
#define ComConf_ComSignal_Sig_Valve15_Tpeak_off_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_517ebaf3_Rx 344u
#define ComConf_ComSignal_Sig_Valve15_Tpeak_tot_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_051b6dc4_Rx 345u
#define ComConf_ComSignal_Sig_Valve16_DutyCycle_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_a4177538_Rx 346u
#define ComConf_ComSignal_Sig_Valve16_FWtimeOFF0_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_12d1a7f4_Rx 347u
#define ComConf_ComSignal_Sig_Valve16_Frequency_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_85850231_Rx 348u
#define ComConf_ComSignal_Sig_Valve16_Ibias_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_bd10c716_Rx 349u
#define ComConf_ComSignal_Sig_Valve16_IboostB_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_db651178_Rx 350u
#define ComConf_ComSignal_Sig_Valve16_IboostP_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_861b9562_Rx 351u
#define ComConf_ComSignal_Sig_Valve16_Ihold_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_c6044331_Rx 352u
#define ComConf_ComSignal_Sig_Valve16_Ipeak_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_04f010e9_Rx 353u
#define ComConf_ComSignal_Sig_Valve16_MDAswitchPC_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_22dc53b3_Rx 354u
#define ComConf_ComSignal_Sig_Valve16_Mode_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_a2520f49_Rx 355u
#define ComConf_ComSignal_Sig_Valve16_State_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_38ed9213_Rx 356u
#define ComConf_ComSignal_Sig_Valve16_Tbias_off_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_264f505d_Rx 357u
#define ComConf_ComSignal_Sig_Valve16_Tbias_tot_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_722a876a_Rx 358u
#define ComConf_ComSignal_Sig_Valve16_Tbypass_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_33cd5cf8_Rx 359u
#define ComConf_ComSignal_Sig_Valve16_Thold_off_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_14ef0b67_Rx 360u
#define ComConf_ComSignal_Sig_Valve16_Thold_tot_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_408adc50_Rx 361u
#define ComConf_ComSignal_Sig_Valve16_Tpeak_off_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_9c4f8ddd_Rx 362u
#define ComConf_ComSignal_Sig_Valve16_Tpeak_tot_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_c82a5aea_Rx 363u
#define ComConf_ComSignal_SteerWhlSnsrAgSpd_oVddmPropFr29_oCAN00_d671b60e_Rx 364u
#define ComConf_ComSignal_SteerWhlSnsrAg_oVddmPropFr29_oCAN00_896c638d_Rx 365u
#define ComConf_ComSignal_TrsmVehSpd_oTcmPropFr04_oCAN00_9a41ead0_Rx  366u
#define ComConf_ComSignal_VehSpdLgtA_oVddmPropFr05_oCAN00_aa5f0501_Rx 367u
#define ComConf_ComSignal_WhlMotSysTqEstIsgTqAct_oIemEduPropFr01_oCAN00_32af1c7a_Rx 368u
#define ComConf_ComSignal_WhlMotSysTqReq_oEcmPropFr24_oCAN00_2b85d3d8_Rx 369u
/**\} */

/**
 * \defgroup ComHandleIdsComTxSig Handle IDs of handle space ComTxSig.
 * \brief Tx Signals
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComGroupSignal_Sig_9_Axis_IMU_Body_Accel_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_bddf38ed_Tx 31u
#define ComConf_ComGroupSignal_Sig_9_Axis_IMU_East_Speed_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_d74b99fa_Tx 32u
#define ComConf_ComGroupSignal_Sig_9_Axis_IMU_Ground_Speed_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_5603cee8_Tx 33u
#define ComConf_ComGroupSignal_Sig_9_Axis_IMU_Lateral_Accel_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_8d5c04c7_Tx 34u
#define ComConf_ComGroupSignal_Sig_9_Axis_IMU_North_Speed_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_a75ef127_Tx 35u
#define ComConf_ComGroupSignal_Sig_9_Axis_IMU_Pitch_Angle_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_5cea06fd_Tx 36u
#define ComConf_ComGroupSignal_Sig_9_Axis_IMU_Pitch_Rate_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_39d01e28_Tx 37u
#define ComConf_ComGroupSignal_Sig_9_Axis_IMU_Roll_Angle_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_a36dcf74_Tx 38u
#define ComConf_ComGroupSignal_Sig_9_Axis_IMU_Roll_Rate_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_b173e7f1_Tx 39u
#define ComConf_ComGroupSignal_Sig_9_Axis_IMU_Vertical_Accel_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_12c41d42_Tx 40u
#define ComConf_ComGroupSignal_Sig_9_Axis_IMU_Yawing_Angle_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_31e9e392_Tx 41u
#define ComConf_ComGroupSignal_Sig_9_Axis_IMU_Yawing_Rate_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_e7d19a3d_Tx 42u
#define ComConf_ComGroupSignal_Sig_CRC_ID_B10_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_31745b74_Tx 0u
#define ComConf_ComGroupSignal_Sig_CRC_ID_B11_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_ca199fab_Tx 43u
#define ComConf_ComGroupSignal_Sig_Counter_ID_B10_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_5e38a8f5_Tx 1u
#define ComConf_ComGroupSignal_Sig_Counter_ID_B11_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_a5556c2a_Tx 44u
#define ComConf_ComGroupSignal_Sig_ETL1_ID_B10_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_0242ca9f_Tx 2u
#define ComConf_ComGroupSignal_Sig_ETL1_ID_B11_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_f92f0e40_Tx 45u
#define ComConf_ComGroupSignal_Sig_ETL2_ID_B10_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_3d89b40a_Tx 3u
#define ComConf_ComGroupSignal_Sig_ETL2_ID_B11_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_c6e470d5_Tx 46u
#define ComConf_ComGroupSignal_Sig_ETL3_ID_B10_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9e1f9c46_Tx 4u
#define ComConf_ComGroupSignal_Sig_ETL3_ID_B11_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_65725899_Tx 47u
#define ComConf_ComGroupSignal_Sig_ETL4_ID_B11_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_b9728dff_Tx 48u
#define ComConf_ComGroupSignal_Sig_ETL5_ID_B11_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_1ae4a5b3_Tx 49u
#define ComConf_ComGroupSignal_Sig_Sensor_Brake_pedal_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_4466e9c1_Tx 5u
#define ComConf_ComGroupSignal_Sig_Sensor_Gas_pedal_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_85d258d3_Tx 6u
#define ComConf_ComGroupSignal_Sig_Sensor_HeightFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_05802db6_Tx 7u
#define ComConf_ComGroupSignal_Sig_Sensor_HeightFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9c832483_Tx 8u
#define ComConf_ComGroupSignal_Sig_Sensor_HeightRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_d763aa45_Tx 9u
#define ComConf_ComGroupSignal_Sig_Sensor_HeightRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_4e60a370_Tx 10u
#define ComConf_ComGroupSignal_Sig_Sensor_Power_Diag_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_70e35f64_Tx 11u
#define ComConf_ComGroupSignal_Sig_Sensor_Pressure_DownFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_49f6aa56_Tx 12u
#define ComConf_ComGroupSignal_Sig_Sensor_Pressure_DownFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_d0f5a363_Tx 13u
#define ComConf_ComGroupSignal_Sig_Sensor_Pressure_DownRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9b152da5_Tx 14u
#define ComConf_ComGroupSignal_Sig_Sensor_Pressure_DownRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_02162490_Tx 15u
#define ComConf_ComGroupSignal_Sig_Sensor_Pressure_UpFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_4ff296ad_Tx 16u
#define ComConf_ComGroupSignal_Sig_Sensor_Pressure_UpFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_d6f19f98_Tx 17u
#define ComConf_ComGroupSignal_Sig_Sensor_Pressure_UpRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9d11115e_Tx 18u
#define ComConf_ComGroupSignal_Sig_Sensor_Pressure_UpRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_0412186b_Tx 19u
#define ComConf_ComGroupSignal_Sig_Sensor_Steering_AngleRate_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9378dbfb_Tx 20u
#define ComConf_ComGroupSignal_Sig_Sensor_Steering_Angle_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_32c000be_Tx 21u
#define ComConf_ComGroupSignal_Sig_Sensor_Steering_Torque_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_fc4f17d8_Tx 22u
#define ComConf_ComGroupSignal_Sig_X_Axis_Body_AccelFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_d436b53e_Tx 23u
#define ComConf_ComGroupSignal_Sig_X_Axis_Body_AccelFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_4d35bc0b_Tx 24u
#define ComConf_ComGroupSignal_Sig_X_Axis_Body_AccelRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_06d532cd_Tx 25u
#define ComConf_ComGroupSignal_Sig_X_Axis_Body_AccelRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9fd63bf8_Tx 26u
#define ComConf_ComGroupSignal_Sig_X_Axis_Wheel_AccelFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_7bc3a6cd_Tx 27u
#define ComConf_ComGroupSignal_Sig_X_Axis_Wheel_AccelFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_e2c0aff8_Tx 28u
#define ComConf_ComGroupSignal_Sig_X_Axis_Wheel_AccelRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_a920213e_Tx 29u
#define ComConf_ComGroupSignal_Sig_X_Axis_Wheel_AccelRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_3023280b_Tx 30u
#define ComConf_ComSignal_Sig_MDA_ActiveForceFL_oMSG_MDA_Internal_oSchaeffler_MDA_CANFD_d3a8bf7b_Tx 50u
#define ComConf_ComSignal_Sig_MDA_ActiveForceFR_oMSG_MDA_Internal_oSchaeffler_MDA_CANFD_b9c3726a_Tx 51u
#define ComConf_ComSignal_Sig_MDA_ActiveForceRL_oMSG_MDA_Internal_oSchaeffler_MDA_CANFD_29ebcf6e_Tx 52u
#define ComConf_ComSignal_Sig_MDA_ActiveForceRR_oMSG_MDA_Internal_oSchaeffler_MDA_CANFD_4380027f_Tx 53u
#define ComConf_ComSignal_Sig_Mot_Current_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_6a00d445_Tx 54u
#define ComConf_ComSignal_Sig_Mot_Current_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_ec6aae44_Tx 55u
#define ComConf_ComSignal_Sig_Mot_Current_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_862e4532_Tx 56u
#define ComConf_ComSignal_Sig_Mot_Current_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_00443f33_Tx 57u
#define ComConf_ComSignal_Sig_Mot_Diags_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_8e197ec3_Tx 58u
#define ComConf_ComSignal_Sig_Mot_Diags_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_087304c2_Tx 59u
#define ComConf_ComSignal_Sig_Mot_Diags_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_6237efb4_Tx 60u
#define ComConf_ComSignal_Sig_Mot_Diags_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_e45d95b5_Tx 61u
#define ComConf_ComSignal_Sig_Mot_Mode_commandFL_oMSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_7d5f8b40_Tx 62u
#define ComConf_ComSignal_Sig_Mot_Mode_commandFR_oMSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_d3c19435_Tx 63u
#define ComConf_ComSignal_Sig_Mot_Mode_commandRL_oMSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_42219988_Tx 64u
#define ComConf_ComSignal_Sig_Mot_Mode_commandRR_oMSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_ecbf86fd_Tx 65u
#define ComConf_ComSignal_Sig_Mot_Mode_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_9217127b_Tx 66u
#define ComConf_ComSignal_Sig_Mot_Mode_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_147d687a_Tx 67u
#define ComConf_ComSignal_Sig_Mot_Mode_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_7e39830c_Tx 68u
#define ComConf_ComSignal_Sig_Mot_Mode_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_f853f90d_Tx 69u
#define ComConf_ComSignal_Sig_Mot_Pos_commandFL_oMSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_dda52c0a_Tx 70u
#define ComConf_ComSignal_Sig_Mot_Pos_commandFR_oMSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_733b337f_Tx 71u
#define ComConf_ComSignal_Sig_Mot_Pos_commandRL_oMSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_e2db3ec2_Tx 72u
#define ComConf_ComSignal_Sig_Mot_Pos_commandRR_oMSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_4c4521b7_Tx 73u
#define ComConf_ComSignal_Sig_Mot_Pos_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_4a62e4d4_Tx 74u
#define ComConf_ComSignal_Sig_Mot_Pos_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_cc089ed5_Tx 75u
#define ComConf_ComSignal_Sig_Mot_Pos_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_a64c75a3_Tx 76u
#define ComConf_ComSignal_Sig_Mot_Pos_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_20260fa2_Tx 77u
#define ComConf_ComSignal_Sig_Mot_Speed_commandFL_oMSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_4c2f58b5_Tx 78u
#define ComConf_ComSignal_Sig_Mot_Speed_commandFR_oMSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_e2b147c0_Tx 79u
#define ComConf_ComSignal_Sig_Mot_Speed_commandRL_oMSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_73514a7d_Tx 80u
#define ComConf_ComSignal_Sig_Mot_Speed_commandRR_oMSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_ddcf5508_Tx 81u
#define ComConf_ComSignal_Sig_Mot_Speed_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_1fde2ef8_Tx 82u
#define ComConf_ComSignal_Sig_Mot_Speed_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_99b454f9_Tx 83u
#define ComConf_ComSignal_Sig_Mot_Speed_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_f3f0bf8f_Tx 84u
#define ComConf_ComSignal_Sig_Mot_Speed_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_759ac58e_Tx 85u
#define ComConf_ComSignal_Sig_Mot_State_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_0b4ed38b_Tx 86u
#define ComConf_ComSignal_Sig_Mot_State_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_8d24a98a_Tx 87u
#define ComConf_ComSignal_Sig_Mot_State_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_e76042fc_Tx 88u
#define ComConf_ComSignal_Sig_Mot_State_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_610a38fd_Tx 89u
#define ComConf_ComSignal_Sig_Mot_Temp_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_9b045378_Tx 90u
#define ComConf_ComSignal_Sig_Mot_Temp_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_1d6e2979_Tx 91u
#define ComConf_ComSignal_Sig_Mot_Temp_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_772ac20f_Tx 92u
#define ComConf_ComSignal_Sig_Mot_Temp_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_f140b80e_Tx 93u
#define ComConf_ComSignal_Sig_Mot_Torque_commandFL_oMSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_cc22eb0f_Tx 94u
#define ComConf_ComSignal_Sig_Mot_Torque_commandFR_oMSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_62bcf47a_Tx 95u
#define ComConf_ComSignal_Sig_Mot_Torque_commandRL_oMSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_f35cf9c7_Tx 96u
#define ComConf_ComSignal_Sig_Mot_Torque_commandRR_oMSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_5dc2e6b2_Tx 97u
#define ComConf_ComSignal_Sig_Mot_Torque_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_e3458dbb_Tx 98u
#define ComConf_ComSignal_Sig_Mot_Torque_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_652ff7ba_Tx 99u
#define ComConf_ComSignal_Sig_Mot_Torque_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_0f6b1ccc_Tx 100u
#define ComConf_ComSignal_Sig_Mot_Torque_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_890166cd_Tx 101u
#define ComConf_ComSignal_Sig_Mot_Voltage_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_2be51499_Tx 102u
#define ComConf_ComSignal_Sig_Mot_Voltage_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_ad8f6e98_Tx 103u
#define ComConf_ComSignal_Sig_Mot_Voltage_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_c7cb85ee_Tx 104u
#define ComConf_ComSignal_Sig_Mot_Voltage_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_41a1ffef_Tx 105u
#define ComConf_ComSignal_Sig_Mot_commandFL_oMSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_f43eb050_Tx 106u
#define ComConf_ComSignal_Sig_Mot_commandFR_oMSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_5aa0af25_Tx 107u
#define ComConf_ComSignal_Sig_Mot_commandRL_oMSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_cb40a298_Tx 108u
#define ComConf_ComSignal_Sig_Mot_commandRR_oMSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_65debded_Tx 109u
#define ComConf_ComSignal_Sig_PT1_Channel_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_35deee4a_Tx 110u
#define ComConf_ComSignal_Sig_PT1_Cksys_Lack_oMSG_PT2000_oSchaeffler_MDA_CANFD_75935422_Tx 111u
#define ComConf_ComSignal_Sig_PT1_DCDC_HS7_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_aa37a69c_Tx 112u
#define ComConf_ComSignal_Sig_PT1_DCDC_LS7_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_4342bfe7_Tx 113u
#define ComConf_ComSignal_Sig_PT1_Disable_Output_oMSG_PT2000_oSchaeffler_MDA_CANFD_9bb393fa_Tx 114u
#define ComConf_ComSignal_Sig_PT1_SPI_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_64dd9785_Tx 115u
#define ComConf_ComSignal_Sig_PT1_Valve1_HS1_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_dc7f0e1c_Tx 116u
#define ComConf_ComSignal_Sig_PT1_Valve1_HS2_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_f6c3be94_Tx 117u
#define ComConf_ComSignal_Sig_PT1_Valve1_LS1_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_350a1767_Tx 118u
#define ComConf_ComSignal_Sig_PT1_Valve1_LS2_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_1fb6a7ef_Tx 119u
#define ComConf_ComSignal_Sig_PT1_Valve2_HS3_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_27ff6475_Tx 120u
#define ComConf_ComSignal_Sig_PT1_Valve2_HS4_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_ddc29722_Tx 121u
#define ComConf_ComSignal_Sig_PT1_Valve2_LS3_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_ce8a7d0e_Tx 122u
#define ComConf_ComSignal_Sig_PT1_Valve2_LS4_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_34b78e59_Tx 123u
#define ComConf_ComSignal_Sig_PT1_Valve3_HS5_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_58ae3d07_Tx 124u
#define ComConf_ComSignal_Sig_PT1_Valve3_HS6_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_72128d8f_Tx 125u
#define ComConf_ComSignal_Sig_PT1_Valve3_LS5_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_b1db247c_Tx 126u
#define ComConf_ComSignal_Sig_PT1_Valve3_LS6_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_9b6794f4_Tx 127u
#define ComConf_ComSignal_Sig_PT2_Channel_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_7f47993e_Tx 128u
#define ComConf_ComSignal_Sig_PT2_Cksys_Lack_oMSG_PT2000_oSchaeffler_MDA_CANFD_f5c9f897_Tx 129u
#define ComConf_ComSignal_Sig_PT2_DCDC_HS7_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_964be8d5_Tx 130u
#define ComConf_ComSignal_Sig_PT2_DCDC_LS7_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_7f3ef1ae_Tx 131u
#define ComConf_ComSignal_Sig_PT2_Disable_Output_oMSG_PT2000_oSchaeffler_MDA_CANFD_cc91bfa8_Tx 132u
#define ComConf_ComSignal_Sig_PT2_SPI_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_5b16e910_Tx 133u
#define ComConf_ComSignal_Sig_PT2_Valve4_HS1_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_ad20fc3f_Tx 134u
#define ComConf_ComSignal_Sig_PT2_Valve4_HS2_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_879c4cb7_Tx 135u
#define ComConf_ComSignal_Sig_PT2_Valve4_LS1_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_4455e544_Tx 136u
#define ComConf_ComSignal_Sig_PT2_Valve4_LS2_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_6ee955cc_Tx 137u
#define ComConf_ComSignal_Sig_PT2_Valve5_HS3_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_02f0e692_Tx 138u
#define ComConf_ComSignal_Sig_PT2_Valve5_HS4_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_f8cd15c5_Tx 139u
#define ComConf_ComSignal_Sig_PT2_Valve5_LS3_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_eb85ffe9_Tx 140u
#define ComConf_ComSignal_Sig_PT2_Valve5_LS4_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_11b80cbe_Tx 141u
#define ComConf_ComSignal_Sig_PT2_Valve6_HS5_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_29f1cf24_Tx 142u
#define ComConf_ComSignal_Sig_PT2_Valve6_HS6_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_034d7fac_Tx 143u
#define ComConf_ComSignal_Sig_PT2_Valve6_LS5_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_c084d65f_Tx 144u
#define ComConf_ComSignal_Sig_PT2_Valve6_LS6_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_ea3866d7_Tx 145u
#define ComConf_ComSignal_Sig_PT3_Channel_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_f01fb62d_Tx 146u
#define ComConf_ComSignal_Sig_PT3_Cksys_Lack_oMSG_PT2000_oSchaeffler_MDA_CANFD_8a006304_Tx 147u
#define ComConf_ComSignal_Sig_PT3_DCDC_HS7_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_82602d12_Tx 148u
#define ComConf_ComSignal_Sig_PT3_DCDC_LS7_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_6b153469_Tx 149u
#define ComConf_ComSignal_Sig_PT3_Disable_Output_oMSG_PT2000_oSchaeffler_MDA_CANFD_48a0a659_Tx 150u
#define ComConf_ComSignal_Sig_PT3_SPI_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_f880c15c_Tx 151u
#define ComConf_ComSignal_Sig_PT3_Valve7_HS1_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_8215adde_Tx 152u
#define ComConf_ComSignal_Sig_PT3_Valve7_HS2_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_a8a91d56_Tx 153u
#define ComConf_ComSignal_Sig_PT3_Valve7_LS1_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_6b60b4a5_Tx 154u
#define ComConf_ComSignal_Sig_PT3_Valve7_LS2_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_41dc042d_Tx 155u
#define ComConf_ComSignal_Sig_PT3_Valve8_HS3_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_5b05e36e_Tx 156u
#define ComConf_ComSignal_Sig_PT3_Valve8_HS4_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_a1381039_Tx 157u
#define ComConf_ComSignal_Sig_PT3_Valve8_LS3_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_b270fa15_Tx 158u
#define ComConf_ComSignal_Sig_PT3_Valve8_LS4_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_484d0942_Tx 159u
#define ComConf_ComSignal_Sig_PT3_Valve9_HS5_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_2454ba1c_Tx 160u
#define ComConf_ComSignal_Sig_PT3_Valve9_HS6_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_0ee80a94_Tx 161u
#define ComConf_ComSignal_Sig_PT3_Valve9_LS5_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_cd21a367_Tx 162u
#define ComConf_ComSignal_Sig_PT3_Valve9_LS6_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_e79d13ef_Tx 163u
#define ComConf_ComSignal_Sig_PT4_Channel_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_ea7577d6_Tx 164u
#define ComConf_ComSignal_Sig_PT4_Cksys_Lack_oMSG_PT2000_oSchaeffler_MDA_CANFD_2e0da7bc_Tx 165u
#define ComConf_ComSignal_Sig_PT4_DCDC_HS7_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_eeb37447_Tx 166u
#define ComConf_ComSignal_Sig_PT4_DCDC_LS7_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_07c66d3c_Tx 167u
#define ComConf_ComSignal_Sig_PT4_Disable_Output_oMSG_PT2000_oSchaeffler_MDA_CANFD_62d5e70c_Tx 168u
#define ComConf_ComSignal_Sig_PT4_SPI_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_2480143a_Tx 169u
#define ComConf_ComSignal_Sig_PT4_Valve10_HS1_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_3529bf8d_Tx 170u
#define ComConf_ComSignal_Sig_PT4_Valve10_HS2_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_1f950f05_Tx 171u
#define ComConf_ComSignal_Sig_PT4_Valve10_LS1_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_dc5ca6f6_Tx 172u
#define ComConf_ComSignal_Sig_PT4_Valve10_LS2_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_f6e0167e_Tx 173u
#define ComConf_ComSignal_Sig_PT4_Valve11_HS3_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_9af9a520_Tx 174u
#define ComConf_ComSignal_Sig_PT4_Valve11_HS4_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_60c45677_Tx 175u
#define ComConf_ComSignal_Sig_PT4_Valve11_LS3_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_738cbc5b_Tx 176u
#define ComConf_ComSignal_Sig_PT4_Valve11_LS4_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_89b14f0c_Tx 177u
#define ComConf_ComSignal_Sig_PT4_Valve12_HS5_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_b1f88c96_Tx 178u
#define ComConf_ComSignal_Sig_PT4_Valve12_HS6_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_9b443c1e_Tx 179u
#define ComConf_ComSignal_Sig_PT4_Valve12_LS5_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_588d95ed_Tx 180u
#define ComConf_ComSignal_Sig_PT4_Valve12_LS6_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_72312565_Tx 181u
#define ComConf_ComSignal_Sig_PT5_Channel_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_652d58c5_Tx 182u
#define ComConf_ComSignal_Sig_PT5_Cksys_Lack_oMSG_PT2000_oSchaeffler_MDA_CANFD_51c43c2f_Tx 183u
#define ComConf_ComSignal_Sig_PT5_DCDC_HS7_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_fa98b180_Tx 184u
#define ComConf_ComSignal_Sig_PT5_DCDC_LS7_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_13eda8fb_Tx 185u
#define ComConf_ComSignal_Sig_PT5_Disable_Output_oMSG_PT2000_oSchaeffler_MDA_CANFD_e6e4fefd_Tx 186u
#define ComConf_ComSignal_Sig_PT5_SPI_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_87163c76_Tx 187u
#define ComConf_ComSignal_Sig_PT5_Valve13_HS1_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_b9eee1f2_Tx 188u
#define ComConf_ComSignal_Sig_PT5_Valve13_HS2_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_9352517a_Tx 189u
#define ComConf_ComSignal_Sig_PT5_Valve13_LS1_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_509bf889_Tx 190u
#define ComConf_ComSignal_Sig_PT5_Valve13_LS2_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_7a274801_Tx 191u
#define ComConf_ComSignal_Sig_PT5_Valve14_HS3_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_eace6a13_Tx 192u
#define ComConf_ComSignal_Sig_PT5_Valve14_HS4_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_10f39944_Tx 193u
#define ComConf_ComSignal_Sig_PT5_Valve14_LS3_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_03bb7368_Tx 194u
#define ComConf_ComSignal_Sig_PT5_Valve14_LS4_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_f986803f_Tx 195u
#define ComConf_ComSignal_Sig_PT5_Valve15_HS5_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_959f3361_Tx 196u
#define ComConf_ComSignal_Sig_PT5_Valve15_HS6_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_bf2383e9_Tx 197u
#define ComConf_ComSignal_Sig_PT5_Valve15_LS5_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_7cea2a1a_Tx 198u
#define ComConf_ComSignal_Sig_PT5_Valve15_LS6_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_56569a92_Tx 199u
#define ComConf_ComSignal_Sig_PT6_Channel_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_2fb42fb1_Tx 200u
#define ComConf_ComSignal_Sig_PT6_Cksys_Lack_oMSG_PT2000_oSchaeffler_MDA_CANFD_d19e909a_Tx 201u
#define ComConf_ComSignal_Sig_PT6_DCDC_HS7_oMSG_PTDriver_06_oSchaeffler_MDA_CANFD_c6e4ffc9_Tx 202u
#define ComConf_ComSignal_Sig_PT6_DCDC_LS7_oMSG_PTDriver_06_oSchaeffler_MDA_CANFD_2f91e6b2_Tx 203u
#define ComConf_ComSignal_Sig_PT6_Disable_Output_oMSG_PT2000_oSchaeffler_MDA_CANFD_b1c6d2af_Tx 204u
#define ComConf_ComSignal_Sig_PT6_SPI_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_b8dd42e3_Tx 205u
#define ComConf_ComSignal_Sig_PT6_Valve16_HS1_oMSG_PTDriver_06_oSchaeffler_MDA_CANFD_f7d60532_Tx 206u
#define ComConf_ComSignal_Sig_PT6_Valve16_HS2_oMSG_PTDriver_06_oSchaeffler_MDA_CANFD_dd6ab5ba_Tx 207u
#define ComConf_ComSignal_Sig_PT6_Valve16_LS1_oMSG_PTDriver_06_oSchaeffler_MDA_CANFD_1ea31c49_Tx 208u
#define ComConf_ComSignal_Sig_PT6_Valve16_LS2_oMSG_PTDriver_06_oSchaeffler_MDA_CANFD_341facc1_Tx 209u
#define ComConf_ComSignal_Sig_Valve1_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_0bdb9dd5_Tx 210u
#define ComConf_ComSignal_Sig_Valve1_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_8ece5c4e_Tx 211u
#define ComConf_ComSignal_Sig_Valve2_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_75a3d573_Tx 212u
#define ComConf_ComSignal_Sig_Valve2_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_f0b614e8_Tx 213u
#define ComConf_ComSignal_Sig_Valve3_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_5f8bed11_Tx 214u
#define ComConf_ComSignal_Sig_Valve3_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_da9e2c8a_Tx 215u
#define ComConf_ComSignal_Sig_Valve4_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_8953443f_Tx 216u
#define ComConf_ComSignal_Sig_Valve4_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_0c4685a4_Tx 217u
#define ComConf_ComSignal_Sig_Valve5_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_a37b7c5d_Tx 218u
#define ComConf_ComSignal_Sig_Valve5_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_266ebdc6_Tx 219u
#define ComConf_ComSignal_Sig_Valve6_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_dd0334fb_Tx 220u
#define ComConf_ComSignal_Sig_Valve6_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_5816f560_Tx 221u
#define ComConf_ComSignal_Sig_Valve7_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_f72b0c99_Tx 222u
#define ComConf_ComSignal_Sig_Valve7_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_723ecd02_Tx 223u
#define ComConf_ComSignal_Sig_Valve8_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_abc360e6_Tx 224u
#define ComConf_ComSignal_Sig_Valve8_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_2ed6a17d_Tx 225u
#define ComConf_ComSignal_Sig_Valve9_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_81eb5884_Tx 226u
#define ComConf_ComSignal_Sig_Valve9_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_04fe991f_Tx 227u
#define ComConf_ComSignal_Sig_Valve10_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_b49ae336_Tx 228u
#define ComConf_ComSignal_Sig_Valve10_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_318f22ad_Tx 229u
#define ComConf_ComSignal_Sig_Valve11_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_9eb2db54_Tx 230u
#define ComConf_ComSignal_Sig_Valve11_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_1ba71acf_Tx 231u
#define ComConf_ComSignal_Sig_Valve12_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_e0ca93f2_Tx 232u
#define ComConf_ComSignal_Sig_Valve12_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_65df5269_Tx 233u
#define ComConf_ComSignal_Sig_Valve13_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_cae2ab90_Tx 234u
#define ComConf_ComSignal_Sig_Valve13_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_4ff76a0b_Tx 235u
#define ComConf_ComSignal_Sig_Valve14_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_1c3a02be_Tx 236u
#define ComConf_ComSignal_Sig_Valve14_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_992fc325_Tx 237u
#define ComConf_ComSignal_Sig_Valve15_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_36123adc_Tx 238u
#define ComConf_ComSignal_Sig_Valve15_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_b307fb47_Tx 239u
#define ComConf_ComSignal_Sig_Valve16_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_486a727a_Tx 240u
#define ComConf_ComSignal_Sig_Valve16_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_cd7fb3e1_Tx 241u
/**\} */




/**
 * \defgroup ComHandleIdscomTxSigGrp Handle IDs of handle space comTxSigGrp.
 * \brief Tx SignalGroups
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComSignalGroup_SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx 0u
#define ComConf_ComSignalGroup_SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx 1u
/**\} */




/**
 * \defgroup ComHandleIds Handle IDs.
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define ComConf_ComIPduGroup_MDA_oCAN00_Rx_982be727                   0u
#define ComConf_ComIPduGroup_MDA_oSchaeffler_MDA_CANFD_Rx_370d2033    1u
#define ComConf_ComIPduGroup_MDA_oSchaeffler_MDA_CANFD_Tx_615787b5    2u
#define ComConf_ComIPduGroup_MDA_oSchaeffler_MotorFL_CANFD_Rx_d87c4b2a 3u
#define ComConf_ComIPduGroup_MDA_oSchaeffler_MotorFL_CANFD_Tx_8e26ecac 4u
#define ComConf_ComIPduGroup_MDA_oSchaeffler_MotorFR_CANFD_Rx_e11bfa71 5u
#define ComConf_ComIPduGroup_MDA_oSchaeffler_MotorFR_CANFD_Tx_b7415df7 6u
#define ComConf_ComIPduGroup_MDA_oSchaeffler_MotorRL_CANFD_Rx_c653fc63 7u
#define ComConf_ComIPduGroup_MDA_oSchaeffler_MotorRL_CANFD_Tx_90095be5 8u
#define ComConf_ComIPduGroup_MDA_oSchaeffler_MotorRR_CANFD_Rx_ff344d38 9u
#define ComConf_ComIPduGroup_MDA_oSchaeffler_MotorRR_CANFD_Tx_a96eeabe 10u
/**\} */

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
  \defgroup  ComPCGetConstantDuplicatedRootDataMacros  Com Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define Com_GetActivatableRxComIPdusOfPCConfig()                      Com_ActivatableRxComIPdus  /**< the pointer to Com_ActivatableRxComIPdus */
#define Com_GetActivatableTxComIPdusOfPCConfig()                      Com_ActivatableTxComIPdus  /**< the pointer to Com_ActivatableTxComIPdus */
#define Com_GetConfigIdOfPCConfig()                                   0u  /**< DefinitionRef: /MICROSAR/Com/ComConfig/ComConfigurationId */
#define Com_GetConstValueFloat32OfPCConfig()                          Com_ConstValueFloat32  /**< the pointer to Com_ConstValueFloat32 */
#define Com_GetConstValueSInt16OfPCConfig()                           Com_ConstValueSInt16  /**< the pointer to Com_ConstValueSInt16 */
#define Com_GetConstValueUInt16OfPCConfig()                           Com_ConstValueUInt16  /**< the pointer to Com_ConstValueUInt16 */
#define Com_GetConstValueUInt8OfPCConfig()                            Com_ConstValueUInt8  /**< the pointer to Com_ConstValueUInt8 */
#define Com_GetCurrentTxModeOfPCConfig()                              Com_CurrentTxMode  /**< the pointer to Com_CurrentTxMode */
#define Com_GetCycleTimeCntOfPCConfig()                               Com_CycleTimeCnt  /**< the pointer to Com_CycleTimeCnt */
#define Com_GetCyclicSendRequestOfPCConfig()                          Com_CyclicSendRequest  /**< the pointer to Com_CyclicSendRequest */
#define Com_GetDelayTimeCntOfPCConfig()                               Com_DelayTimeCnt  /**< the pointer to Com_DelayTimeCnt */
#define Com_GetGatewayProcessingISRLockCounterOfPCConfig()            (&(Com_GatewayProcessingISRLockCounter))  /**< the pointer to Com_GatewayProcessingISRLockCounter */
#define Com_GetHandleRxPduDeferredOfPCConfig()                        Com_HandleRxPduDeferred.raw  /**< the pointer to Com_HandleRxPduDeferred */
#define Com_GetInitializedOfPCConfig()                                (&(Com_Initialized))  /**< the pointer to Com_Initialized */
#define Com_GetPduGrpCntOfPCConfig()                                  11u
#define Com_GetPduGrpVectorOfPCConfig()                               Com_PduGrpVector  /**< the pointer to Com_PduGrpVector */
#define Com_GetRepCntOfPCConfig()                                     Com_RepCnt  /**< the pointer to Com_RepCnt */
#define Com_GetRepCycleCntOfPCConfig()                                Com_RepCycleCnt  /**< the pointer to Com_RepCycleCnt */
#define Com_GetRxAccessInfoIndOfPCConfig()                            Com_RxAccessInfoInd  /**< the pointer to Com_RxAccessInfoInd */
#define Com_GetRxAccessInfoOfPCConfig()                               Com_RxAccessInfo  /**< the pointer to Com_RxAccessInfo */
#define Com_GetRxDeadlineMonitoringISRLockCounterOfPCConfig()         (&(Com_RxDeadlineMonitoringISRLockCounter))  /**< the pointer to Com_RxDeadlineMonitoringISRLockCounter */
#define Com_GetRxDefPduBufferOfPCConfig()                             Com_RxDefPduBuffer.raw  /**< the pointer to Com_RxDefPduBuffer */
#define Com_GetRxDeferredProcessingISRLockCounterOfPCConfig()         (&(Com_RxDeferredProcessingISRLockCounter))  /**< the pointer to Com_RxDeferredProcessingISRLockCounter */
#define Com_GetRxDeferredProcessingISRLockThresholdOfPCConfig()       1u
#define Com_GetRxIPduGroupISRLockCounterOfPCConfig()                  (&(Com_RxIPduGroupISRLockCounter))  /**< the pointer to Com_RxIPduGroupISRLockCounter */
#define Com_GetRxIPduGroupISRLockThresholdOfPCConfig()                1u
#define Com_GetRxPduGrpActiveOfPCConfig()                             Com_RxPduGrpActive  /**< the pointer to Com_RxPduGrpActive */
#define Com_GetRxPduGrpInfoOfPCConfig()                               Com_RxPduGrpInfo  /**< the pointer to Com_RxPduGrpInfo */
#define Com_GetRxPduInfoOfPCConfig()                                  Com_RxPduInfo  /**< the pointer to Com_RxPduInfo */
#define Com_GetRxSigBufferFloat32OfPCConfig()                         Com_RxSigBufferFloat32  /**< the pointer to Com_RxSigBufferFloat32 */
#define Com_GetRxSigBufferSInt16OfPCConfig()                          Com_RxSigBufferSInt16  /**< the pointer to Com_RxSigBufferSInt16 */
#define Com_GetRxSigBufferUInt16OfPCConfig()                          Com_RxSigBufferUInt16  /**< the pointer to Com_RxSigBufferUInt16 */
#define Com_GetRxSigBufferUInt8OfPCConfig()                           Com_RxSigBufferUInt8  /**< the pointer to Com_RxSigBufferUInt8 */
#define Com_GetRxSigInfoOfPCConfig()                                  Com_RxSigInfo  /**< the pointer to Com_RxSigInfo */
#define Com_GetSigGrpEventFlagOfPCConfig()                            Com_SigGrpEventFlag  /**< the pointer to Com_SigGrpEventFlag */
#define Com_GetSizeOfActivatableRxComIPdusOfPCConfig()                36u  /**< the number of accomplishable value elements in Com_ActivatableRxComIPdus */
#define Com_GetSizeOfActivatableTxComIPdusOfPCConfig()                19u  /**< the number of accomplishable value elements in Com_ActivatableTxComIPdus */
#define Com_GetSizeOfConstValueFloat32OfPCConfig()                    1u  /**< the number of accomplishable value elements in Com_ConstValueFloat32 */
#define Com_GetSizeOfConstValueSInt16OfPCConfig()                     1u  /**< the number of accomplishable value elements in Com_ConstValueSInt16 */
#define Com_GetSizeOfConstValueUInt16OfPCConfig()                     1u  /**< the number of accomplishable value elements in Com_ConstValueUInt16 */
#define Com_GetSizeOfConstValueUInt8OfPCConfig()                      1u  /**< the number of accomplishable value elements in Com_ConstValueUInt8 */
#define Com_GetSizeOfHandleRxPduDeferredOfPCConfig()                  36u  /**< the number of accomplishable value elements in Com_HandleRxPduDeferred */
#define Com_GetSizeOfPduGrpVectorOfPCConfig()                         11u  /**< the number of accomplishable value elements in Com_PduGrpVector */
#define Com_GetSizeOfRxAccessInfoIndOfPCConfig()                      370u  /**< the number of accomplishable value elements in Com_RxAccessInfoInd */
#define Com_GetSizeOfRxAccessInfoOfPCConfig()                         370u  /**< the number of accomplishable value elements in Com_RxAccessInfo */
#define Com_GetSizeOfRxDefPduBufferOfPCConfig()                       1193u  /**< the number of accomplishable value elements in Com_RxDefPduBuffer */
#define Com_GetSizeOfRxPduGrpInfoOfPCConfig()                         36u  /**< the number of accomplishable value elements in Com_RxPduGrpInfo */
#define Com_GetSizeOfRxPduInfoOfPCConfig()                            36u  /**< the number of accomplishable value elements in Com_RxPduInfo */
#define Com_GetSizeOfRxSigBufferFloat32OfPCConfig()                   4u  /**< the number of accomplishable value elements in Com_RxSigBufferFloat32 */
#define Com_GetSizeOfRxSigBufferSInt16OfPCConfig()                    12u  /**< the number of accomplishable value elements in Com_RxSigBufferSInt16 */
#define Com_GetSizeOfRxSigBufferUInt16OfPCConfig()                    262u  /**< the number of accomplishable value elements in Com_RxSigBufferUInt16 */
#define Com_GetSizeOfRxSigBufferUInt8OfPCConfig()                     92u  /**< the number of accomplishable value elements in Com_RxSigBufferUInt8 */
#define Com_GetSizeOfRxSigInfoOfPCConfig()                            370u  /**< the number of accomplishable value elements in Com_RxSigInfo */
#define Com_GetSizeOfTxBufferOfPCConfig()                             916u  /**< the number of accomplishable value elements in Com_TxBuffer */
#define Com_GetSizeOfTxModeFalseOfPCConfig()                          2u  /**< the number of accomplishable value elements in Com_TxModeFalse */
#define Com_GetSizeOfTxModeInfoOfPCConfig()                           19u  /**< the number of accomplishable value elements in Com_TxModeInfo */
#define Com_GetSizeOfTxModeTrueOfPCConfig()                           2u  /**< the number of accomplishable value elements in Com_TxModeTrue */
#define Com_GetSizeOfTxPduGrpInfoOfPCConfig()                         19u  /**< the number of accomplishable value elements in Com_TxPduGrpInfo */
#define Com_GetSizeOfTxPduInfoOfPCConfig()                            19u  /**< the number of accomplishable value elements in Com_TxPduInfo */
#define Com_GetSizeOfTxPduInitValueOfPCConfig()                       800u  /**< the number of accomplishable value elements in Com_TxPduInitValue */
#define Com_GetSizeOfTxSigGrpInfoIndOfPCConfig()                      2u  /**< the number of accomplishable value elements in Com_TxSigGrpInfoInd */
#define Com_GetSizeOfTxSigGrpInfoOfPCConfig()                         2u  /**< the number of accomplishable value elements in Com_TxSigGrpInfo */
#define Com_GetSizeOfTxSigGrpMaskOfPCConfig()                         115u  /**< the number of accomplishable value elements in Com_TxSigGrpMask */
#define Com_GetSizeOfTxSigInfoOfPCConfig()                            242u  /**< the number of accomplishable value elements in Com_TxSigInfo */
#define Com_GetTransmitRequestOfPCConfig()                            Com_TransmitRequest  /**< the pointer to Com_TransmitRequest */
#define Com_GetTxBufferOfPCConfig()                                   Com_TxBuffer  /**< the pointer to Com_TxBuffer */
#define Com_GetTxCyclicProcessingISRLockCounterOfPCConfig()           (&(Com_TxCyclicProcessingISRLockCounter))  /**< the pointer to Com_TxCyclicProcessingISRLockCounter */
#define Com_GetTxCyclicProcessingISRLockThresholdOfPCConfig()         1u
#define Com_GetTxDeadlineMonitoringISRLockCounterOfPCConfig()         (&(Com_TxDeadlineMonitoringISRLockCounter))  /**< the pointer to Com_TxDeadlineMonitoringISRLockCounter */
#define Com_GetTxIPduGroupISRLockCounterOfPCConfig()                  (&(Com_TxIPduGroupISRLockCounter))  /**< the pointer to Com_TxIPduGroupISRLockCounter */
#define Com_GetTxIPduGroupISRLockThresholdOfPCConfig()                1u
#define Com_GetTxModeFalseOfPCConfig()                                Com_TxModeFalse  /**< the pointer to Com_TxModeFalse */
#define Com_GetTxModeInfoOfPCConfig()                                 Com_TxModeInfo  /**< the pointer to Com_TxModeInfo */
#define Com_GetTxModeTrueOfPCConfig()                                 Com_TxModeTrue  /**< the pointer to Com_TxModeTrue */
#define Com_GetTxPduGrpActiveOfPCConfig()                             Com_TxPduGrpActive  /**< the pointer to Com_TxPduGrpActive */
#define Com_GetTxPduGrpInfoOfPCConfig()                               Com_TxPduGrpInfo  /**< the pointer to Com_TxPduGrpInfo */
#define Com_GetTxPduInfoOfPCConfig()                                  Com_TxPduInfo  /**< the pointer to Com_TxPduInfo */
#define Com_GetTxPduInitValueOfPCConfig()                             Com_TxPduInitValue  /**< the pointer to Com_TxPduInitValue */
#define Com_GetTxProcessingISRLockCounterOfPCConfig()                 (&(Com_TxProcessingISRLockCounter))  /**< the pointer to Com_TxProcessingISRLockCounter */
#define Com_GetTxProcessingISRLockThresholdOfPCConfig()               1u
#define Com_GetTxSduLengthOfPCConfig()                                Com_TxSduLength  /**< the pointer to Com_TxSduLength */
#define Com_GetTxSigGrpInfoIndOfPCConfig()                            Com_TxSigGrpInfoInd  /**< the pointer to Com_TxSigGrpInfoInd */
#define Com_GetTxSigGrpInfoOfPCConfig()                               Com_TxSigGrpInfo  /**< the pointer to Com_TxSigGrpInfo */
#define Com_GetTxSigGrpMaskOfPCConfig()                               Com_TxSigGrpMask  /**< the pointer to Com_TxSigGrpMask */
#define Com_GetTxSigInfoOfPCConfig()                                  Com_TxSigInfo  /**< the pointer to Com_TxSigInfo */
/** 
  \}
*/ 

/** 
  \defgroup  ComPCGetDuplicatedRootDataMacros  Com Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define Com_GetSizeOfCurrentTxModeOfPCConfig()                        Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_CurrentTxMode */
#define Com_GetSizeOfCycleTimeCntOfPCConfig()                         Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_CycleTimeCnt */
#define Com_GetSizeOfCyclicSendRequestOfPCConfig()                    Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_CyclicSendRequest */
#define Com_GetSizeOfDelayTimeCntOfPCConfig()                         Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_DelayTimeCnt */
#define Com_GetSizeOfRepCntOfPCConfig()                               Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_RepCnt */
#define Com_GetSizeOfRepCycleCntOfPCConfig()                          Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_RepCycleCnt */
#define Com_GetSizeOfRxPduGrpActiveOfPCConfig()                       Com_GetSizeOfRxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_RxPduGrpActive */
#define Com_GetSizeOfSigGrpEventFlagOfPCConfig()                      Com_GetSizeOfTxSigGrpInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_SigGrpEventFlag */
#define Com_GetSizeOfTransmitRequestOfPCConfig()                      Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_TransmitRequest */
#define Com_GetSizeOfTxPduGrpActiveOfPCConfig()                       Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_TxPduGrpActive */
#define Com_GetSizeOfTxSduLengthOfPCConfig()                          Com_GetSizeOfTxPduInfoOfPCConfig()  /**< the number of accomplishable value elements in Com_TxSduLength */
/** 
  \}
*/ 

/** 
  \defgroup  ComPCGetDataMacros  Com Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define Com_GetConstValueFloat32(Index)                               (Com_GetConstValueFloat32OfPCConfig()[(Index)])
#define Com_GetConstValueSInt16(Index)                                (Com_GetConstValueSInt16OfPCConfig()[(Index)])
#define Com_GetConstValueUInt16(Index)                                (Com_GetConstValueUInt16OfPCConfig()[(Index)])
#define Com_GetConstValueUInt8(Index)                                 (Com_GetConstValueUInt8OfPCConfig()[(Index)])
#define Com_IsCurrentTxMode(Index)                                    ((Com_GetCurrentTxModeOfPCConfig()[(Index)]) != FALSE)
#define Com_GetCycleTimeCnt(Index)                                    (Com_GetCycleTimeCntOfPCConfig()[(Index)])
#define Com_IsCyclicSendRequest(Index)                                ((Com_GetCyclicSendRequestOfPCConfig()[(Index)]) != FALSE)
#define Com_GetDelayTimeCnt(Index)                                    (Com_GetDelayTimeCntOfPCConfig()[(Index)])
#define Com_GetGatewayProcessingISRLockCounter()                      ((*(Com_GetGatewayProcessingISRLockCounterOfPCConfig())))
#define Com_GetHandleRxPduDeferred(Index)                             (Com_GetHandleRxPduDeferredOfPCConfig()[(Index)])
#define Com_IsInitialized()                                           (((*(Com_GetInitializedOfPCConfig()))) != FALSE)
#define Com_GetPduGrpVector(Index)                                    (Com_GetPduGrpVectorOfPCConfig()[(Index)])
#define Com_GetRepCnt(Index)                                          (Com_GetRepCntOfPCConfig()[(Index)])
#define Com_GetRepCycleCnt(Index)                                     (Com_GetRepCycleCntOfPCConfig()[(Index)])
#define Com_GetApplTypeOfRxAccessInfo(Index)                          (Com_GetRxAccessInfoOfPCConfig()[(Index)].ApplTypeOfRxAccessInfo)
#define Com_GetBitLengthOfRxAccessInfo(Index)                         (Com_GetRxAccessInfoOfPCConfig()[(Index)].BitLengthOfRxAccessInfo)
#define Com_GetBitPositionOfRxAccessInfo(Index)                       (Com_GetRxAccessInfoOfPCConfig()[(Index)].BitPositionOfRxAccessInfo)
#define Com_GetBufferIdxOfRxAccessInfo(Index)                         (Com_GetRxAccessInfoOfPCConfig()[(Index)].BufferIdxOfRxAccessInfo)
#define Com_GetBusAccOfRxAccessInfo(Index)                            (Com_GetRxAccessInfoOfPCConfig()[(Index)].BusAccOfRxAccessInfo)
#define Com_GetByteLengthOfRxAccessInfo(Index)                        (Com_GetRxAccessInfoOfPCConfig()[(Index)].ByteLengthOfRxAccessInfo)
#define Com_GetBytePositionOfRxAccessInfo(Index)                      (Com_GetRxAccessInfoOfPCConfig()[(Index)].BytePositionOfRxAccessInfo)
#define Com_GetInitValueIdxOfRxAccessInfo(Index)                      (Com_GetRxAccessInfoOfPCConfig()[(Index)].InitValueIdxOfRxAccessInfo)
#define Com_IsInitValueUsedOfRxAccessInfo(Index)                      ((Com_GetRxAccessInfoOfPCConfig()[(Index)].InitValueUsedOfRxAccessInfo) != FALSE)
#define Com_GetRxPduInfoIdxOfRxAccessInfo(Index)                      (Com_GetRxAccessInfoOfPCConfig()[(Index)].RxPduInfoIdxOfRxAccessInfo)
#define Com_IsSignExtRequiredOfRxAccessInfo(Index)                    ((Com_GetRxAccessInfoOfPCConfig()[(Index)].SignExtRequiredOfRxAccessInfo) != FALSE)
#define Com_GetStartByteInPduPositionOfRxAccessInfo(Index)            (Com_GetRxAccessInfoOfPCConfig()[(Index)].StartByteInPduPositionOfRxAccessInfo)
#define Com_GetRxAccessInfoInd(Index)                                 (Com_GetRxAccessInfoIndOfPCConfig()[(Index)])
#define Com_GetRxDeadlineMonitoringISRLockCounter()                   ((*(Com_GetRxDeadlineMonitoringISRLockCounterOfPCConfig())))
#define Com_GetRxDefPduBuffer(Index)                                  (Com_GetRxDefPduBufferOfPCConfig()[(Index)])
#define Com_GetRxDeferredProcessingISRLockCounter()                   ((*(Com_GetRxDeferredProcessingISRLockCounterOfPCConfig())))
#define Com_GetRxIPduGroupISRLockCounter()                            ((*(Com_GetRxIPduGroupISRLockCounterOfPCConfig())))
#define Com_IsRxPduGrpActive(Index)                                   ((Com_GetRxPduGrpActiveOfPCConfig()[(Index)]) != FALSE)
#define Com_GetPduGrpVectorEndIdxOfRxPduGrpInfo(Index)                (Com_GetRxPduGrpInfoOfPCConfig()[(Index)].PduGrpVectorEndIdxOfRxPduGrpInfo)
#define Com_GetPduGrpVectorStartIdxOfRxPduGrpInfo(Index)              (Com_GetRxPduGrpInfoOfPCConfig()[(Index)].PduGrpVectorStartIdxOfRxPduGrpInfo)
#define Com_IsRxAccessInfoIndUsedOfRxPduInfo(Index)                   ((Com_GetRxPduInfoOfPCConfig()[(Index)].RxAccessInfoIndUsedOfRxPduInfo) != FALSE)
#define Com_GetRxDefPduBufferEndIdxOfRxPduInfo(Index)                 (Com_GetRxPduInfoOfPCConfig()[(Index)].RxDefPduBufferEndIdxOfRxPduInfo)
#define Com_GetRxDefPduBufferStartIdxOfRxPduInfo(Index)               (Com_GetRxPduInfoOfPCConfig()[(Index)].RxDefPduBufferStartIdxOfRxPduInfo)
#define Com_GetRxSigInfoEndIdxOfRxPduInfo(Index)                      (Com_GetRxPduInfoOfPCConfig()[(Index)].RxSigInfoEndIdxOfRxPduInfo)
#define Com_GetRxSigInfoStartIdxOfRxPduInfo(Index)                    (Com_GetRxPduInfoOfPCConfig()[(Index)].RxSigInfoStartIdxOfRxPduInfo)
#define Com_GetTypeOfRxPduInfo(Index)                                 (Com_GetRxPduInfoOfPCConfig()[(Index)].TypeOfRxPduInfo)
#define Com_GetRxSigBufferFloat32(Index)                              (Com_GetRxSigBufferFloat32OfPCConfig()[(Index)])
#define Com_GetRxSigBufferSInt16(Index)                               (Com_GetRxSigBufferSInt16OfPCConfig()[(Index)])
#define Com_GetRxSigBufferUInt16(Index)                               (Com_GetRxSigBufferUInt16OfPCConfig()[(Index)])
#define Com_GetRxSigBufferUInt8(Index)                                (Com_GetRxSigBufferUInt8OfPCConfig()[(Index)])
#define Com_GetRxAccessInfoIdxOfRxSigInfo(Index)                      (Com_GetRxSigInfoOfPCConfig()[(Index)].RxAccessInfoIdxOfRxSigInfo)
#define Com_GetSignalProcessingOfRxSigInfo(Index)                     (Com_GetRxSigInfoOfPCConfig()[(Index)].SignalProcessingOfRxSigInfo)
#define Com_GetValidDlcOfRxSigInfo(Index)                             (Com_GetRxSigInfoOfPCConfig()[(Index)].ValidDlcOfRxSigInfo)
#define Com_GetSigGrpEventFlag(Index)                                 (Com_GetSigGrpEventFlagOfPCConfig()[(Index)])
#define Com_IsTransmitRequest(Index)                                  ((Com_GetTransmitRequestOfPCConfig()[(Index)]) != FALSE)
#define Com_GetTxBuffer(Index)                                        (Com_GetTxBufferOfPCConfig()[(Index)])
#define Com_GetTxCyclicProcessingISRLockCounter()                     ((*(Com_GetTxCyclicProcessingISRLockCounterOfPCConfig())))
#define Com_GetTxDeadlineMonitoringISRLockCounter()                   ((*(Com_GetTxDeadlineMonitoringISRLockCounterOfPCConfig())))
#define Com_GetTxIPduGroupISRLockCounter()                            ((*(Com_GetTxIPduGroupISRLockCounterOfPCConfig())))
#define Com_IsPeriodicOfTxModeFalse(Index)                            ((Com_GetTxModeFalseOfPCConfig()[(Index)].PeriodicOfTxModeFalse) != FALSE)
#define Com_GetTimePeriodOfTxModeFalse(Index)                         (Com_GetTxModeFalseOfPCConfig()[(Index)].TimePeriodOfTxModeFalse)
#define Com_IsInitModeOfTxModeInfo(Index)                             ((Com_GetTxModeInfoOfPCConfig()[(Index)].InitModeOfTxModeInfo) != FALSE)
#define Com_GetMinimumDelayOfTxModeInfo(Index)                        (Com_GetTxModeInfoOfPCConfig()[(Index)].MinimumDelayOfTxModeInfo)
#define Com_GetTxModeTrueIdxOfTxModeInfo(Index)                       (Com_GetTxModeInfoOfPCConfig()[(Index)].TxModeTrueIdxOfTxModeInfo)
#define Com_IsPeriodicOfTxModeTrue(Index)                             ((Com_GetTxModeTrueOfPCConfig()[(Index)].PeriodicOfTxModeTrue) != FALSE)
#define Com_GetTimePeriodOfTxModeTrue(Index)                          (Com_GetTxModeTrueOfPCConfig()[(Index)].TimePeriodOfTxModeTrue)
#define Com_IsTxPduGrpActive(Index)                                   ((Com_GetTxPduGrpActiveOfPCConfig()[(Index)]) != FALSE)
#define Com_GetPduGrpVectorEndIdxOfTxPduGrpInfo(Index)                (Com_GetTxPduGrpInfoOfPCConfig()[(Index)].PduGrpVectorEndIdxOfTxPduGrpInfo)
#define Com_GetPduGrpVectorStartIdxOfTxPduGrpInfo(Index)              (Com_GetTxPduGrpInfoOfPCConfig()[(Index)].PduGrpVectorStartIdxOfTxPduGrpInfo)
#define Com_GetMetaDataLengthOfTxPduInfo(Index)                       (Com_GetTxPduInfoOfPCConfig()[(Index)].MetaDataLengthOfTxPduInfo)
#define Com_GetTxBufferLengthOfTxPduInfo(Index)                       (Com_GetTxPduInfoOfPCConfig()[(Index)].TxBufferLengthOfTxPduInfo)
#define Com_GetTxPduInitValueEndIdxOfTxPduInfo(Index)                 (Com_GetTxPduInfoOfPCConfig()[(Index)].TxPduInitValueEndIdxOfTxPduInfo)
#define Com_GetTxPduInitValueStartIdxOfTxPduInfo(Index)               (Com_GetTxPduInfoOfPCConfig()[(Index)].TxPduInitValueStartIdxOfTxPduInfo)
#define Com_IsTxPduInitValueUsedOfTxPduInfo(Index)                    ((Com_GetTxPduInfoOfPCConfig()[(Index)].TxPduInitValueUsedOfTxPduInfo) != FALSE)
#define Com_GetTxSigGrpInfoIndEndIdxOfTxPduInfo(Index)                (Com_GetTxPduInfoOfPCConfig()[(Index)].TxSigGrpInfoIndEndIdxOfTxPduInfo)
#define Com_GetTxSigGrpInfoIndStartIdxOfTxPduInfo(Index)              (Com_GetTxPduInfoOfPCConfig()[(Index)].TxSigGrpInfoIndStartIdxOfTxPduInfo)
#define Com_GetTxPduInitValue(Index)                                  (Com_GetTxPduInitValueOfPCConfig()[(Index)])
#define Com_GetTxProcessingISRLockCounter()                           ((*(Com_GetTxProcessingISRLockCounterOfPCConfig())))
#define Com_GetTxSduLength(Index)                                     (Com_GetTxSduLengthOfPCConfig()[(Index)])
#define Com_GetTransferPropertyOfTxSigGrpInfo(Index)                  (Com_GetTxSigGrpInfoOfPCConfig()[(Index)].TransferPropertyOfTxSigGrpInfo)
#define Com_GetTxBufferSigGrpInTxIPDULengthOfTxSigGrpInfo(Index)      (Com_GetTxSigGrpInfoOfPCConfig()[(Index)].TxBufferSigGrpInTxIPDULengthOfTxSigGrpInfo)
#define Com_GetTxBufferSigGrpInTxIPDUStartIdxOfTxSigGrpInfo(Index)    (Com_GetTxSigGrpInfoOfPCConfig()[(Index)].TxBufferSigGrpInTxIPDUStartIdxOfTxSigGrpInfo)
#define Com_GetTxBufferStartIdxOfTxSigGrpInfo(Index)                  (Com_GetTxSigGrpInfoOfPCConfig()[(Index)].TxBufferStartIdxOfTxSigGrpInfo)
#define Com_GetTxSigGrpMaskStartIdxOfTxSigGrpInfo(Index)              (Com_GetTxSigGrpInfoOfPCConfig()[(Index)].TxSigGrpMaskStartIdxOfTxSigGrpInfo)
#define Com_IsTxSigGrpMaskUsedOfTxSigGrpInfo(Index)                   ((Com_GetTxSigGrpInfoOfPCConfig()[(Index)].TxSigGrpMaskUsedOfTxSigGrpInfo) != FALSE)
#define Com_GetTxSigGrpMask(Index)                                    (Com_GetTxSigGrpMaskOfPCConfig()[(Index)])
#define Com_GetApplTypeOfTxSigInfo(Index)                             (Com_GetTxSigInfoOfPCConfig()[(Index)].ApplTypeOfTxSigInfo)
#define Com_GetBitLengthOfTxSigInfo(Index)                            (Com_GetTxSigInfoOfPCConfig()[(Index)].BitLengthOfTxSigInfo)
#define Com_GetBitPositionOfTxSigInfo(Index)                          (Com_GetTxSigInfoOfPCConfig()[(Index)].BitPositionOfTxSigInfo)
#define Com_GetBusAccOfTxSigInfo(Index)                               (Com_GetTxSigInfoOfPCConfig()[(Index)].BusAccOfTxSigInfo)
#define Com_GetByteLengthOfTxSigInfo(Index)                           (Com_GetTxSigInfoOfPCConfig()[(Index)].ByteLengthOfTxSigInfo)
#define Com_GetStartByteInPduPositionOfTxSigInfo(Index)               (Com_GetTxSigInfoOfPCConfig()[(Index)].StartByteInPduPositionOfTxSigInfo)
#define Com_GetTxBufferEndIdxOfTxSigInfo(Index)                       (Com_GetTxSigInfoOfPCConfig()[(Index)].TxBufferEndIdxOfTxSigInfo)
#define Com_GetTxBufferStartIdxOfTxSigInfo(Index)                     (Com_GetTxSigInfoOfPCConfig()[(Index)].TxBufferStartIdxOfTxSigInfo)
#define Com_GetTxPduInfoIdxOfTxSigInfo(Index)                         (Com_GetTxSigInfoOfPCConfig()[(Index)].TxPduInfoIdxOfTxSigInfo)
#define Com_GetTxSigGrpInfoIdxOfTxSigInfo(Index)                      (Com_GetTxSigInfoOfPCConfig()[(Index)].TxSigGrpInfoIdxOfTxSigInfo)
/** 
  \}
*/ 

/** 
  \defgroup  ComPCGetDeduplicatedDataMacros  Com Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define Com_GetRxPduInfoIdxOfActivatableRxComIPdus(Index)             ((Com_RxPduInfoIdxOfActivatableRxComIPdusType)((Index)))  /**< the index of the 1:1 relation pointing to Com_RxPduInfo */
#define Com_GetTxPduInfoIdxOfActivatableTxComIPdus(Index)             ((Com_TxPduInfoIdxOfActivatableTxComIPdusType)((Index)))  /**< the index of the 1:1 relation pointing to Com_TxPduInfo */
#define Com_GetConfigId()                                             Com_GetConfigIdOfPCConfig()
#define Com_GetPduGrpCnt()                                            Com_GetPduGrpCntOfPCConfig()
#define Com_IsBufferUsedOfRxAccessInfo(Index)                         Com_IsInitValueUsedOfRxAccessInfo(Index)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_RxSigBufferUInt8,Com_RxSigBufferUInt16,Com_RxSigBufferUInt32,Com_RxSigBufferUInt64,Com_RxSigBufferZeroBit,Com_RxSigBufferSInt8,Com_RxSigBufferSInt16,Com_RxSigBufferSInt32,Com_RxSigBufferSInt64,Com_RxSigBufferFloat32,Com_RxSigBufferFloat64 */
#define Com_GetRxDeferredProcessingISRLockThreshold()                 Com_GetRxDeferredProcessingISRLockThresholdOfPCConfig()
#define Com_GetRxIPduGroupISRLockThreshold()                          Com_GetRxIPduGroupISRLockThresholdOfPCConfig()
#define Com_IsPduGrpVectorUsedOfRxPduGrpInfo(Index)                   (((boolean)(Com_GetPduGrpVectorStartIdxOfRxPduGrpInfo(Index) != COM_NO_PDUGRPVECTORSTARTIDXOFRXPDUGRPINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_PduGrpVector */
#define Com_GetHandleRxPduDeferredIdxOfRxPduInfo(Index)               ((Com_HandleRxPduDeferredIdxOfRxPduInfoType)((Index)))  /**< the index of the 0:1 relation pointing to Com_HandleRxPduDeferred */
#define Com_IsHandleRxPduDeferredUsedOfRxPduInfo(Index)               Com_IsRxAccessInfoIndUsedOfRxPduInfo(Index)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_HandleRxPduDeferred */
#define Com_GetRxAccessInfoIndEndIdxOfRxPduInfo(Index)                Com_GetRxSigInfoEndIdxOfRxPduInfo(Index)  /**< the end index of the 0:n relation pointing to Com_RxAccessInfoInd */
#define Com_GetRxAccessInfoIndStartIdxOfRxPduInfo(Index)              Com_GetRxSigInfoStartIdxOfRxPduInfo(Index)  /**< the start index of the 0:n relation pointing to Com_RxAccessInfoInd */
#define Com_GetRxDefPduBufferLengthOfRxPduInfo(Index)                 ((Com_RxDefPduBufferLengthOfRxPduInfoType)((Com_GetRxDefPduBufferEndIdxOfRxPduInfo(Index) - Com_GetRxDefPduBufferStartIdxOfRxPduInfo(Index))))  /**< the number of relations pointing to Com_RxDefPduBuffer */
#define Com_IsRxDefPduBufferUsedOfRxPduInfo(Index)                    Com_IsRxAccessInfoIndUsedOfRxPduInfo(Index)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_RxDefPduBuffer */
#define Com_IsRxSigInfoUsedOfRxPduInfo(Index)                         Com_IsRxAccessInfoIndUsedOfRxPduInfo(Index)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_RxSigInfo */
#define Com_GetSignalProcessingOfRxPduInfo(Index)                     Com_GetTypeOfRxPduInfo(Index)  /**< Defines whether rx Pdu is processed in DEFERRED or IMMEDIATE fashion. */
#define Com_GetSizeOfActivatableRxComIPdus()                          Com_GetSizeOfActivatableRxComIPdusOfPCConfig()
#define Com_GetSizeOfActivatableTxComIPdus()                          Com_GetSizeOfActivatableTxComIPdusOfPCConfig()
#define Com_GetSizeOfConstValueFloat32()                              Com_GetSizeOfConstValueFloat32OfPCConfig()
#define Com_GetSizeOfConstValueSInt16()                               Com_GetSizeOfConstValueSInt16OfPCConfig()
#define Com_GetSizeOfConstValueUInt16()                               Com_GetSizeOfConstValueUInt16OfPCConfig()
#define Com_GetSizeOfConstValueUInt8()                                Com_GetSizeOfConstValueUInt8OfPCConfig()
#define Com_GetSizeOfCurrentTxMode()                                  Com_GetSizeOfCurrentTxModeOfPCConfig()
#define Com_GetSizeOfCycleTimeCnt()                                   Com_GetSizeOfCycleTimeCntOfPCConfig()
#define Com_GetSizeOfCyclicSendRequest()                              Com_GetSizeOfCyclicSendRequestOfPCConfig()
#define Com_GetSizeOfDelayTimeCnt()                                   Com_GetSizeOfDelayTimeCntOfPCConfig()
#define Com_GetSizeOfHandleRxPduDeferred()                            Com_GetSizeOfHandleRxPduDeferredOfPCConfig()
#define Com_GetSizeOfPduGrpVector()                                   Com_GetSizeOfPduGrpVectorOfPCConfig()
#define Com_GetSizeOfRepCnt()                                         Com_GetSizeOfRepCntOfPCConfig()
#define Com_GetSizeOfRepCycleCnt()                                    Com_GetSizeOfRepCycleCntOfPCConfig()
#define Com_GetSizeOfRxAccessInfo()                                   Com_GetSizeOfRxAccessInfoOfPCConfig()
#define Com_GetSizeOfRxAccessInfoInd()                                Com_GetSizeOfRxAccessInfoIndOfPCConfig()
#define Com_GetSizeOfRxDefPduBuffer()                                 Com_GetSizeOfRxDefPduBufferOfPCConfig()
#define Com_GetSizeOfRxPduGrpActive()                                 Com_GetSizeOfRxPduGrpActiveOfPCConfig()
#define Com_GetSizeOfRxPduGrpInfo()                                   Com_GetSizeOfRxPduGrpInfoOfPCConfig()
#define Com_GetSizeOfRxPduInfo()                                      Com_GetSizeOfRxPduInfoOfPCConfig()
#define Com_GetSizeOfRxSigBufferFloat32()                             Com_GetSizeOfRxSigBufferFloat32OfPCConfig()
#define Com_GetSizeOfRxSigBufferSInt16()                              Com_GetSizeOfRxSigBufferSInt16OfPCConfig()
#define Com_GetSizeOfRxSigBufferUInt16()                              Com_GetSizeOfRxSigBufferUInt16OfPCConfig()
#define Com_GetSizeOfRxSigBufferUInt8()                               Com_GetSizeOfRxSigBufferUInt8OfPCConfig()
#define Com_GetSizeOfRxSigInfo()                                      Com_GetSizeOfRxSigInfoOfPCConfig()
#define Com_GetSizeOfSigGrpEventFlag()                                Com_GetSizeOfSigGrpEventFlagOfPCConfig()
#define Com_GetSizeOfTransmitRequest()                                Com_GetSizeOfTransmitRequestOfPCConfig()
#define Com_GetSizeOfTxBuffer()                                       Com_GetSizeOfTxBufferOfPCConfig()
#define Com_GetSizeOfTxModeFalse()                                    Com_GetSizeOfTxModeFalseOfPCConfig()
#define Com_GetSizeOfTxModeInfo()                                     Com_GetSizeOfTxModeInfoOfPCConfig()
#define Com_GetSizeOfTxModeTrue()                                     Com_GetSizeOfTxModeTrueOfPCConfig()
#define Com_GetSizeOfTxPduGrpActive()                                 Com_GetSizeOfTxPduGrpActiveOfPCConfig()
#define Com_GetSizeOfTxPduGrpInfo()                                   Com_GetSizeOfTxPduGrpInfoOfPCConfig()
#define Com_GetSizeOfTxPduInfo()                                      Com_GetSizeOfTxPduInfoOfPCConfig()
#define Com_GetSizeOfTxPduInitValue()                                 Com_GetSizeOfTxPduInitValueOfPCConfig()
#define Com_GetSizeOfTxSduLength()                                    Com_GetSizeOfTxSduLengthOfPCConfig()
#define Com_GetSizeOfTxSigGrpInfo()                                   Com_GetSizeOfTxSigGrpInfoOfPCConfig()
#define Com_GetSizeOfTxSigGrpInfoInd()                                Com_GetSizeOfTxSigGrpInfoIndOfPCConfig()
#define Com_GetSizeOfTxSigGrpMask()                                   Com_GetSizeOfTxSigGrpMaskOfPCConfig()
#define Com_GetSizeOfTxSigInfo()                                      Com_GetSizeOfTxSigInfoOfPCConfig()
#define Com_GetTxCyclicProcessingISRLockThreshold()                   Com_GetTxCyclicProcessingISRLockThresholdOfPCConfig()
#define Com_GetTxIPduGroupISRLockThreshold()                          Com_GetTxIPduGroupISRLockThresholdOfPCConfig()
#define Com_GetTxModeFalseIdxOfTxModeInfo(Index)                      Com_GetTxModeTrueIdxOfTxModeInfo(Index)  /**< the index of the 1:1 relation pointing to Com_TxModeFalse */
#define Com_IsPduGrpVectorUsedOfTxPduGrpInfo(Index)                   (((boolean)(Com_GetPduGrpVectorStartIdxOfTxPduGrpInfo(Index) != COM_NO_PDUGRPVECTORSTARTIDXOFTXPDUGRPINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_PduGrpVector */
#define Com_GetExternalIdOfTxPduInfo(Index)                           ((Com_ExternalIdOfTxPduInfoType)((Index)))  /**< External ID used to call PduR_ComTransmit(). */
#define Com_GetPduWithMetaDataLengthOfTxPduInfo(Index)                Com_GetTxBufferLengthOfTxPduInfo(Index)  /**< Length of Pdu with MetaData. */
#define Com_GetTxBufferEndIdxOfTxPduInfo(Index)                       Com_GetTxPduInitValueEndIdxOfTxPduInfo(Index)  /**< the end index of the 0:n relation pointing to Com_TxBuffer */
#define Com_GetTxBufferStartIdxOfTxPduInfo(Index)                     Com_GetTxPduInitValueStartIdxOfTxPduInfo(Index)  /**< the start index of the 0:n relation pointing to Com_TxBuffer */
#define Com_IsTxBufferUsedOfTxPduInfo(Index)                          Com_IsTxPduInitValueUsedOfTxPduInfo(Index)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_TxBuffer */
#define Com_IsTxSigGrpInfoIndUsedOfTxPduInfo(Index)                   (((boolean)(Com_GetTxSigGrpInfoIndStartIdxOfTxPduInfo(Index) != COM_NO_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_TxSigGrpInfoInd */
#define Com_GetTxProcessingISRLockThreshold()                         Com_GetTxProcessingISRLockThresholdOfPCConfig()
#define Com_GetPduOffsetOfTxSigGrpInfo(Index)                         Com_GetTransferPropertyOfTxSigGrpInfo(Index)  /**< Byte offset relative to the PDU the signal group is starting. */
#define Com_GetTxBufferEndIdxOfTxSigGrpInfo(Index)                    ((Com_TxBufferEndIdxOfTxSigGrpInfoType)((Com_GetTxBufferStartIdxOfTxSigGrpInfo(Index) + 58u)))  /**< the end index of the 0:n relation pointing to Com_TxBuffer */
#define Com_GetTxBufferLengthOfTxSigGrpInfo(Index)                    Com_GetTxBufferSigGrpInTxIPDULengthOfTxSigGrpInfo(Index)  /**< the number of relations pointing to Com_TxBuffer */
#define Com_GetTxBufferSigGrpInTxIPDUEndIdxOfTxSigGrpInfo(Index)      ((Com_TxBufferSigGrpInTxIPDUEndIdxOfTxSigGrpInfoType)((Com_GetTxBufferSigGrpInTxIPDUStartIdxOfTxSigGrpInfo(Index) + 58u)))  /**< the end index of the 1:n relation pointing to Com_TxBuffer */
#define Com_IsTxBufferUsedOfTxSigGrpInfo(Index)                       Com_IsTxSigGrpMaskUsedOfTxSigGrpInfo(Index)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_TxBuffer */
#define Com_GetTxPduInfoIdxOfTxSigGrpInfo(Index)                      ((Com_TxPduInfoIdxOfTxSigGrpInfoType)((((Com_TxPduInfoIdxOfTxSigGrpInfoType)(Index)) + 16u)))  /**< the index of the 1:1 relation pointing to Com_TxPduInfo */
#define Com_GetTxSigGrpMaskEndIdxOfTxSigGrpInfo(Index)                ((Com_TxSigGrpMaskEndIdxOfTxSigGrpInfoType)((Com_GetTxSigGrpMaskStartIdxOfTxSigGrpInfo(Index) + 58u)))  /**< the end index of the 0:n relation pointing to Com_TxSigGrpMask */
#define Com_GetTxSigGrpMaskLengthOfTxSigGrpInfo(Index)                Com_GetTxBufferSigGrpInTxIPDULengthOfTxSigGrpInfo(Index)  /**< the number of relations pointing to Com_TxSigGrpMask */
#define Com_GetTxSigGrpInfoInd(Index)                                 ((Com_TxSigGrpInfoIndType)((Index)))  /**< the indexes of the 1:1 sorted relation pointing to Com_TxSigGrpInfo */
#define Com_GetBytePositionOfTxSigInfo(Index)                         Com_GetStartByteInPduPositionOfTxSigInfo(Index)  /**< Little endian byte position of the signal or group signal within the I-PDU. */
#define Com_GetTxBufferLengthOfTxSigInfo(Index)                       ((Com_TxBufferLengthOfTxSigInfoType)((Com_GetTxBufferEndIdxOfTxSigInfo(Index) - Com_GetTxBufferStartIdxOfTxSigInfo(Index))))  /**< the number of relations pointing to Com_TxBuffer */
#define Com_IsTxBufferUsedOfTxSigInfo(Index)                          (((boolean)(Com_GetTxBufferLengthOfTxSigInfo(Index) != 0u)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_TxBuffer */
#define Com_IsTxSigGrpInfoUsedOfTxSigInfo(Index)                      (((boolean)(Com_GetTxSigGrpInfoIdxOfTxSigInfo(Index) != COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_TxSigGrpInfo */
/** 
  \}
*/ 

/** 
  \defgroup  ComPCSetDataMacros  Com Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define Com_SetCurrentTxMode(Index, Value)                            Com_GetCurrentTxModeOfPCConfig()[(Index)] = (Value)
#define Com_SetCycleTimeCnt(Index, Value)                             Com_GetCycleTimeCntOfPCConfig()[(Index)] = (Value)
#define Com_SetCyclicSendRequest(Index, Value)                        Com_GetCyclicSendRequestOfPCConfig()[(Index)] = (Value)
#define Com_SetDelayTimeCnt(Index, Value)                             Com_GetDelayTimeCntOfPCConfig()[(Index)] = (Value)
#define Com_SetGatewayProcessingISRLockCounter(Value)                 (*(Com_GetGatewayProcessingISRLockCounterOfPCConfig())) = (Value)
#define Com_SetHandleRxPduDeferred(Index, Value)                      Com_GetHandleRxPduDeferredOfPCConfig()[(Index)] = (Value)
#define Com_SetInitialized(Value)                                     (*(Com_GetInitializedOfPCConfig())) = (Value)
#define Com_SetRepCnt(Index, Value)                                   Com_GetRepCntOfPCConfig()[(Index)] = (Value)
#define Com_SetRepCycleCnt(Index, Value)                              Com_GetRepCycleCntOfPCConfig()[(Index)] = (Value)
#define Com_SetRxDeadlineMonitoringISRLockCounter(Value)              (*(Com_GetRxDeadlineMonitoringISRLockCounterOfPCConfig())) = (Value)
#define Com_SetRxDefPduBuffer(Index, Value)                           Com_GetRxDefPduBufferOfPCConfig()[(Index)] = (Value)
#define Com_SetRxDeferredProcessingISRLockCounter(Value)              (*(Com_GetRxDeferredProcessingISRLockCounterOfPCConfig())) = (Value)
#define Com_SetRxIPduGroupISRLockCounter(Value)                       (*(Com_GetRxIPduGroupISRLockCounterOfPCConfig())) = (Value)
#define Com_SetRxPduGrpActive(Index, Value)                           Com_GetRxPduGrpActiveOfPCConfig()[(Index)] = (Value)
#define Com_SetRxSigBufferFloat32(Index, Value)                       Com_GetRxSigBufferFloat32OfPCConfig()[(Index)] = (Value)
#define Com_SetRxSigBufferSInt16(Index, Value)                        Com_GetRxSigBufferSInt16OfPCConfig()[(Index)] = (Value)
#define Com_SetRxSigBufferUInt16(Index, Value)                        Com_GetRxSigBufferUInt16OfPCConfig()[(Index)] = (Value)
#define Com_SetRxSigBufferUInt8(Index, Value)                         Com_GetRxSigBufferUInt8OfPCConfig()[(Index)] = (Value)
#define Com_SetSigGrpEventFlag(Index, Value)                          Com_GetSigGrpEventFlagOfPCConfig()[(Index)] = (Value)
#define Com_SetTransmitRequest(Index, Value)                          Com_GetTransmitRequestOfPCConfig()[(Index)] = (Value)
#define Com_SetTxBuffer(Index, Value)                                 Com_GetTxBufferOfPCConfig()[(Index)] = (Value)
#define Com_SetTxCyclicProcessingISRLockCounter(Value)                (*(Com_GetTxCyclicProcessingISRLockCounterOfPCConfig())) = (Value)
#define Com_SetTxDeadlineMonitoringISRLockCounter(Value)              (*(Com_GetTxDeadlineMonitoringISRLockCounterOfPCConfig())) = (Value)
#define Com_SetTxIPduGroupISRLockCounter(Value)                       (*(Com_GetTxIPduGroupISRLockCounterOfPCConfig())) = (Value)
#define Com_SetTxPduGrpActive(Index, Value)                           Com_GetTxPduGrpActiveOfPCConfig()[(Index)] = (Value)
#define Com_SetTxProcessingISRLockCounter(Value)                      (*(Com_GetTxProcessingISRLockCounterOfPCConfig())) = (Value)
#define Com_SetTxSduLength(Index, Value)                              Com_GetTxSduLengthOfPCConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  ComPCGetAddressOfDataMacros  Com Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define Com_GetAddrConstValueFloat32(Index)                           (&Com_GetConstValueFloat32(Index))
#define Com_GetAddrConstValueSInt16(Index)                            (&Com_GetConstValueSInt16(Index))
#define Com_GetAddrConstValueUInt16(Index)                            (&Com_GetConstValueUInt16(Index))
#define Com_GetAddrConstValueUInt8(Index)                             (&Com_GetConstValueUInt8(Index))
#define Com_GetAddrRxDefPduBuffer(Index)                              (&Com_GetRxDefPduBuffer(Index))
#define Com_GetAddrRxSigBufferFloat32(Index)                          (&Com_GetRxSigBufferFloat32(Index))
#define Com_GetAddrRxSigBufferSInt16(Index)                           (&Com_GetRxSigBufferSInt16(Index))
#define Com_GetAddrRxSigBufferUInt16(Index)                           (&Com_GetRxSigBufferUInt16(Index))
#define Com_GetAddrRxSigBufferUInt8(Index)                            (&Com_GetRxSigBufferUInt8(Index))
#define Com_GetAddrTxBuffer(Index)                                    (&Com_GetTxBuffer(Index))
#define Com_GetAddrTxPduInitValue(Index)                              (&Com_GetTxPduInitValue(Index))
#define Com_GetAddrTxSigGrpMask(Index)                                (&Com_GetTxSigGrpMask(Index))
/** 
  \}
*/ 

/** 
  \defgroup  ComPCHasMacros  Com Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Com_HasActivatableRxComIPdus()                                (TRUE != FALSE)
#define Com_HasRxPduInfoIdxOfActivatableRxComIPdus()                  (TRUE != FALSE)
#define Com_HasActivatableTxComIPdus()                                (TRUE != FALSE)
#define Com_HasTxPduInfoIdxOfActivatableTxComIPdus()                  (TRUE != FALSE)
#define Com_HasConfigId()                                             (TRUE != FALSE)
#define Com_HasConstValueFloat32()                                    (TRUE != FALSE)
#define Com_HasConstValueSInt16()                                     (TRUE != FALSE)
#define Com_HasConstValueUInt16()                                     (TRUE != FALSE)
#define Com_HasConstValueUInt8()                                      (TRUE != FALSE)
#define Com_HasCurrentTxMode()                                        (TRUE != FALSE)
#define Com_HasCycleTimeCnt()                                         (TRUE != FALSE)
#define Com_HasCyclicSendRequest()                                    (TRUE != FALSE)
#define Com_HasDelayTimeCnt()                                         (TRUE != FALSE)
#define Com_HasGatewayProcessingISRLockCounter()                      (TRUE != FALSE)
#define Com_HasHandleRxPduDeferred()                                  (TRUE != FALSE)
#define Com_HasInitialized()                                          (TRUE != FALSE)
#define Com_HasPduGrpCnt()                                            (TRUE != FALSE)
#define Com_HasPduGrpVector()                                         (TRUE != FALSE)
#define Com_HasRepCnt()                                               (TRUE != FALSE)
#define Com_HasRepCycleCnt()                                          (TRUE != FALSE)
#define Com_HasRxAccessInfo()                                         (TRUE != FALSE)
#define Com_HasApplTypeOfRxAccessInfo()                               (TRUE != FALSE)
#define Com_HasBitLengthOfRxAccessInfo()                              (TRUE != FALSE)
#define Com_HasBitPositionOfRxAccessInfo()                            (TRUE != FALSE)
#define Com_HasBufferIdxOfRxAccessInfo()                              (TRUE != FALSE)
#define Com_HasBufferUsedOfRxAccessInfo()                             (TRUE != FALSE)
#define Com_HasBusAccOfRxAccessInfo()                                 (TRUE != FALSE)
#define Com_HasByteLengthOfRxAccessInfo()                             (TRUE != FALSE)
#define Com_HasBytePositionOfRxAccessInfo()                           (TRUE != FALSE)
#define Com_HasInitValueIdxOfRxAccessInfo()                           (TRUE != FALSE)
#define Com_HasInitValueUsedOfRxAccessInfo()                          (TRUE != FALSE)
#define Com_HasRxPduInfoIdxOfRxAccessInfo()                           (TRUE != FALSE)
#define Com_HasSignExtRequiredOfRxAccessInfo()                        (TRUE != FALSE)
#define Com_HasStartByteInPduPositionOfRxAccessInfo()                 (TRUE != FALSE)
#define Com_HasRxAccessInfoInd()                                      (TRUE != FALSE)
#define Com_HasRxDeadlineMonitoringISRLockCounter()                   (TRUE != FALSE)
#define Com_HasRxDefPduBuffer()                                       (TRUE != FALSE)
#define Com_HasRxDeferredProcessingISRLockCounter()                   (TRUE != FALSE)
#define Com_HasRxDeferredProcessingISRLockThreshold()                 (TRUE != FALSE)
#define Com_HasRxIPduGroupISRLockCounter()                            (TRUE != FALSE)
#define Com_HasRxIPduGroupISRLockThreshold()                          (TRUE != FALSE)
#define Com_HasRxPduGrpActive()                                       (TRUE != FALSE)
#define Com_HasRxPduGrpInfo()                                         (TRUE != FALSE)
#define Com_HasPduGrpVectorEndIdxOfRxPduGrpInfo()                     (TRUE != FALSE)
#define Com_HasPduGrpVectorStartIdxOfRxPduGrpInfo()                   (TRUE != FALSE)
#define Com_HasPduGrpVectorUsedOfRxPduGrpInfo()                       (TRUE != FALSE)
#define Com_HasRxPduInfo()                                            (TRUE != FALSE)
#define Com_HasHandleRxPduDeferredIdxOfRxPduInfo()                    (TRUE != FALSE)
#define Com_HasHandleRxPduDeferredUsedOfRxPduInfo()                   (TRUE != FALSE)
#define Com_HasRxAccessInfoIndEndIdxOfRxPduInfo()                     (TRUE != FALSE)
#define Com_HasRxAccessInfoIndStartIdxOfRxPduInfo()                   (TRUE != FALSE)
#define Com_HasRxAccessInfoIndUsedOfRxPduInfo()                       (TRUE != FALSE)
#define Com_HasRxDefPduBufferEndIdxOfRxPduInfo()                      (TRUE != FALSE)
#define Com_HasRxDefPduBufferLengthOfRxPduInfo()                      (TRUE != FALSE)
#define Com_HasRxDefPduBufferStartIdxOfRxPduInfo()                    (TRUE != FALSE)
#define Com_HasRxDefPduBufferUsedOfRxPduInfo()                        (TRUE != FALSE)
#define Com_HasRxSigInfoEndIdxOfRxPduInfo()                           (TRUE != FALSE)
#define Com_HasRxSigInfoStartIdxOfRxPduInfo()                         (TRUE != FALSE)
#define Com_HasRxSigInfoUsedOfRxPduInfo()                             (TRUE != FALSE)
#define Com_HasSignalProcessingOfRxPduInfo()                          (TRUE != FALSE)
#define Com_HasTypeOfRxPduInfo()                                      (TRUE != FALSE)
#define Com_HasRxSigBufferFloat32()                                   (TRUE != FALSE)
#define Com_HasRxSigBufferSInt16()                                    (TRUE != FALSE)
#define Com_HasRxSigBufferUInt16()                                    (TRUE != FALSE)
#define Com_HasRxSigBufferUInt8()                                     (TRUE != FALSE)
#define Com_HasRxSigInfo()                                            (TRUE != FALSE)
#define Com_HasRxAccessInfoIdxOfRxSigInfo()                           (TRUE != FALSE)
#define Com_HasSignalProcessingOfRxSigInfo()                          (TRUE != FALSE)
#define Com_HasValidDlcOfRxSigInfo()                                  (TRUE != FALSE)
#define Com_HasSigGrpEventFlag()                                      (TRUE != FALSE)
#define Com_HasSizeOfActivatableRxComIPdus()                          (TRUE != FALSE)
#define Com_HasSizeOfActivatableTxComIPdus()                          (TRUE != FALSE)
#define Com_HasSizeOfConstValueFloat32()                              (TRUE != FALSE)
#define Com_HasSizeOfConstValueSInt16()                               (TRUE != FALSE)
#define Com_HasSizeOfConstValueUInt16()                               (TRUE != FALSE)
#define Com_HasSizeOfConstValueUInt8()                                (TRUE != FALSE)
#define Com_HasSizeOfCurrentTxMode()                                  (TRUE != FALSE)
#define Com_HasSizeOfCycleTimeCnt()                                   (TRUE != FALSE)
#define Com_HasSizeOfCyclicSendRequest()                              (TRUE != FALSE)
#define Com_HasSizeOfDelayTimeCnt()                                   (TRUE != FALSE)
#define Com_HasSizeOfHandleRxPduDeferred()                            (TRUE != FALSE)
#define Com_HasSizeOfPduGrpVector()                                   (TRUE != FALSE)
#define Com_HasSizeOfRepCnt()                                         (TRUE != FALSE)
#define Com_HasSizeOfRepCycleCnt()                                    (TRUE != FALSE)
#define Com_HasSizeOfRxAccessInfo()                                   (TRUE != FALSE)
#define Com_HasSizeOfRxAccessInfoInd()                                (TRUE != FALSE)
#define Com_HasSizeOfRxDefPduBuffer()                                 (TRUE != FALSE)
#define Com_HasSizeOfRxPduGrpActive()                                 (TRUE != FALSE)
#define Com_HasSizeOfRxPduGrpInfo()                                   (TRUE != FALSE)
#define Com_HasSizeOfRxPduInfo()                                      (TRUE != FALSE)
#define Com_HasSizeOfRxSigBufferFloat32()                             (TRUE != FALSE)
#define Com_HasSizeOfRxSigBufferSInt16()                              (TRUE != FALSE)
#define Com_HasSizeOfRxSigBufferUInt16()                              (TRUE != FALSE)
#define Com_HasSizeOfRxSigBufferUInt8()                               (TRUE != FALSE)
#define Com_HasSizeOfRxSigInfo()                                      (TRUE != FALSE)
#define Com_HasSizeOfSigGrpEventFlag()                                (TRUE != FALSE)
#define Com_HasSizeOfTransmitRequest()                                (TRUE != FALSE)
#define Com_HasSizeOfTxBuffer()                                       (TRUE != FALSE)
#define Com_HasSizeOfTxModeFalse()                                    (TRUE != FALSE)
#define Com_HasSizeOfTxModeInfo()                                     (TRUE != FALSE)
#define Com_HasSizeOfTxModeTrue()                                     (TRUE != FALSE)
#define Com_HasSizeOfTxPduGrpActive()                                 (TRUE != FALSE)
#define Com_HasSizeOfTxPduGrpInfo()                                   (TRUE != FALSE)
#define Com_HasSizeOfTxPduInfo()                                      (TRUE != FALSE)
#define Com_HasSizeOfTxPduInitValue()                                 (TRUE != FALSE)
#define Com_HasSizeOfTxSduLength()                                    (TRUE != FALSE)
#define Com_HasSizeOfTxSigGrpInfo()                                   (TRUE != FALSE)
#define Com_HasSizeOfTxSigGrpInfoInd()                                (TRUE != FALSE)
#define Com_HasSizeOfTxSigGrpMask()                                   (TRUE != FALSE)
#define Com_HasSizeOfTxSigInfo()                                      (TRUE != FALSE)
#define Com_HasTransmitRequest()                                      (TRUE != FALSE)
#define Com_HasTxBuffer()                                             (TRUE != FALSE)
#define Com_HasTxCyclicProcessingISRLockCounter()                     (TRUE != FALSE)
#define Com_HasTxCyclicProcessingISRLockThreshold()                   (TRUE != FALSE)
#define Com_HasTxDeadlineMonitoringISRLockCounter()                   (TRUE != FALSE)
#define Com_HasTxIPduGroupISRLockCounter()                            (TRUE != FALSE)
#define Com_HasTxIPduGroupISRLockThreshold()                          (TRUE != FALSE)
#define Com_HasTxModeFalse()                                          (TRUE != FALSE)
#define Com_HasPeriodicOfTxModeFalse()                                (TRUE != FALSE)
#define Com_HasTimePeriodOfTxModeFalse()                              (TRUE != FALSE)
#define Com_HasTxModeInfo()                                           (TRUE != FALSE)
#define Com_HasInitModeOfTxModeInfo()                                 (TRUE != FALSE)
#define Com_HasMinimumDelayOfTxModeInfo()                             (TRUE != FALSE)
#define Com_HasTxModeFalseIdxOfTxModeInfo()                           (TRUE != FALSE)
#define Com_HasTxModeTrueIdxOfTxModeInfo()                            (TRUE != FALSE)
#define Com_HasTxModeTrue()                                           (TRUE != FALSE)
#define Com_HasPeriodicOfTxModeTrue()                                 (TRUE != FALSE)
#define Com_HasTimePeriodOfTxModeTrue()                               (TRUE != FALSE)
#define Com_HasTxPduGrpActive()                                       (TRUE != FALSE)
#define Com_HasTxPduGrpInfo()                                         (TRUE != FALSE)
#define Com_HasPduGrpVectorEndIdxOfTxPduGrpInfo()                     (TRUE != FALSE)
#define Com_HasPduGrpVectorStartIdxOfTxPduGrpInfo()                   (TRUE != FALSE)
#define Com_HasPduGrpVectorUsedOfTxPduGrpInfo()                       (TRUE != FALSE)
#define Com_HasTxPduInfo()                                            (TRUE != FALSE)
#define Com_HasExternalIdOfTxPduInfo()                                (TRUE != FALSE)
#define Com_HasMetaDataLengthOfTxPduInfo()                            (TRUE != FALSE)
#define Com_HasPduWithMetaDataLengthOfTxPduInfo()                     (TRUE != FALSE)
#define Com_HasTxBufferEndIdxOfTxPduInfo()                            (TRUE != FALSE)
#define Com_HasTxBufferLengthOfTxPduInfo()                            (TRUE != FALSE)
#define Com_HasTxBufferStartIdxOfTxPduInfo()                          (TRUE != FALSE)
#define Com_HasTxBufferUsedOfTxPduInfo()                              (TRUE != FALSE)
#define Com_HasTxPduInitValueEndIdxOfTxPduInfo()                      (TRUE != FALSE)
#define Com_HasTxPduInitValueStartIdxOfTxPduInfo()                    (TRUE != FALSE)
#define Com_HasTxPduInitValueUsedOfTxPduInfo()                        (TRUE != FALSE)
#define Com_HasTxSigGrpInfoIndEndIdxOfTxPduInfo()                     (TRUE != FALSE)
#define Com_HasTxSigGrpInfoIndStartIdxOfTxPduInfo()                   (TRUE != FALSE)
#define Com_HasTxSigGrpInfoIndUsedOfTxPduInfo()                       (TRUE != FALSE)
#define Com_HasTxPduInitValue()                                       (TRUE != FALSE)
#define Com_HasTxProcessingISRLockCounter()                           (TRUE != FALSE)
#define Com_HasTxProcessingISRLockThreshold()                         (TRUE != FALSE)
#define Com_HasTxSduLength()                                          (TRUE != FALSE)
#define Com_HasTxSigGrpInfo()                                         (TRUE != FALSE)
#define Com_HasPduOffsetOfTxSigGrpInfo()                              (TRUE != FALSE)
#define Com_HasTransferPropertyOfTxSigGrpInfo()                       (TRUE != FALSE)
#define Com_HasTxBufferEndIdxOfTxSigGrpInfo()                         (TRUE != FALSE)
#define Com_HasTxBufferLengthOfTxSigGrpInfo()                         (TRUE != FALSE)
#define Com_HasTxBufferSigGrpInTxIPDUEndIdxOfTxSigGrpInfo()           (TRUE != FALSE)
#define Com_HasTxBufferSigGrpInTxIPDULengthOfTxSigGrpInfo()           (TRUE != FALSE)
#define Com_HasTxBufferSigGrpInTxIPDUStartIdxOfTxSigGrpInfo()         (TRUE != FALSE)
#define Com_HasTxBufferStartIdxOfTxSigGrpInfo()                       (TRUE != FALSE)
#define Com_HasTxBufferUsedOfTxSigGrpInfo()                           (TRUE != FALSE)
#define Com_HasTxPduInfoIdxOfTxSigGrpInfo()                           (TRUE != FALSE)
#define Com_HasTxSigGrpMaskEndIdxOfTxSigGrpInfo()                     (TRUE != FALSE)
#define Com_HasTxSigGrpMaskLengthOfTxSigGrpInfo()                     (TRUE != FALSE)
#define Com_HasTxSigGrpMaskStartIdxOfTxSigGrpInfo()                   (TRUE != FALSE)
#define Com_HasTxSigGrpMaskUsedOfTxSigGrpInfo()                       (TRUE != FALSE)
#define Com_HasTxSigGrpInfoInd()                                      (TRUE != FALSE)
#define Com_HasTxSigGrpMask()                                         (TRUE != FALSE)
#define Com_HasTxSigInfo()                                            (TRUE != FALSE)
#define Com_HasApplTypeOfTxSigInfo()                                  (TRUE != FALSE)
#define Com_HasBitLengthOfTxSigInfo()                                 (TRUE != FALSE)
#define Com_HasBitPositionOfTxSigInfo()                               (TRUE != FALSE)
#define Com_HasBusAccOfTxSigInfo()                                    (TRUE != FALSE)
#define Com_HasByteLengthOfTxSigInfo()                                (TRUE != FALSE)
#define Com_HasBytePositionOfTxSigInfo()                              (TRUE != FALSE)
#define Com_HasStartByteInPduPositionOfTxSigInfo()                    (TRUE != FALSE)
#define Com_HasTxBufferEndIdxOfTxSigInfo()                            (TRUE != FALSE)
#define Com_HasTxBufferLengthOfTxSigInfo()                            (TRUE != FALSE)
#define Com_HasTxBufferStartIdxOfTxSigInfo()                          (TRUE != FALSE)
#define Com_HasTxBufferUsedOfTxSigInfo()                              (TRUE != FALSE)
#define Com_HasTxPduInfoIdxOfTxSigInfo()                              (TRUE != FALSE)
#define Com_HasTxSigGrpInfoIdxOfTxSigInfo()                           (TRUE != FALSE)
#define Com_HasTxSigGrpInfoUsedOfTxSigInfo()                          (TRUE != FALSE)
#define Com_HasPCConfig()                                             (TRUE != FALSE)
#define Com_HasActivatableRxComIPdusOfPCConfig()                      (TRUE != FALSE)
#define Com_HasActivatableTxComIPdusOfPCConfig()                      (TRUE != FALSE)
#define Com_HasConfigIdOfPCConfig()                                   (TRUE != FALSE)
#define Com_HasConstValueFloat32OfPCConfig()                          (TRUE != FALSE)
#define Com_HasConstValueSInt16OfPCConfig()                           (TRUE != FALSE)
#define Com_HasConstValueUInt16OfPCConfig()                           (TRUE != FALSE)
#define Com_HasConstValueUInt8OfPCConfig()                            (TRUE != FALSE)
#define Com_HasCurrentTxModeOfPCConfig()                              (TRUE != FALSE)
#define Com_HasCycleTimeCntOfPCConfig()                               (TRUE != FALSE)
#define Com_HasCyclicSendRequestOfPCConfig()                          (TRUE != FALSE)
#define Com_HasDelayTimeCntOfPCConfig()                               (TRUE != FALSE)
#define Com_HasGatewayProcessingISRLockCounterOfPCConfig()            (TRUE != FALSE)
#define Com_HasHandleRxPduDeferredOfPCConfig()                        (TRUE != FALSE)
#define Com_HasInitializedOfPCConfig()                                (TRUE != FALSE)
#define Com_HasPduGrpCntOfPCConfig()                                  (TRUE != FALSE)
#define Com_HasPduGrpVectorOfPCConfig()                               (TRUE != FALSE)
#define Com_HasRepCntOfPCConfig()                                     (TRUE != FALSE)
#define Com_HasRepCycleCntOfPCConfig()                                (TRUE != FALSE)
#define Com_HasRxAccessInfoIndOfPCConfig()                            (TRUE != FALSE)
#define Com_HasRxAccessInfoOfPCConfig()                               (TRUE != FALSE)
#define Com_HasRxDeadlineMonitoringISRLockCounterOfPCConfig()         (TRUE != FALSE)
#define Com_HasRxDefPduBufferOfPCConfig()                             (TRUE != FALSE)
#define Com_HasRxDeferredProcessingISRLockCounterOfPCConfig()         (TRUE != FALSE)
#define Com_HasRxDeferredProcessingISRLockThresholdOfPCConfig()       (TRUE != FALSE)
#define Com_HasRxIPduGroupISRLockCounterOfPCConfig()                  (TRUE != FALSE)
#define Com_HasRxIPduGroupISRLockThresholdOfPCConfig()                (TRUE != FALSE)
#define Com_HasRxPduGrpActiveOfPCConfig()                             (TRUE != FALSE)
#define Com_HasRxPduGrpInfoOfPCConfig()                               (TRUE != FALSE)
#define Com_HasRxPduInfoOfPCConfig()                                  (TRUE != FALSE)
#define Com_HasRxSigBufferFloat32OfPCConfig()                         (TRUE != FALSE)
#define Com_HasRxSigBufferSInt16OfPCConfig()                          (TRUE != FALSE)
#define Com_HasRxSigBufferUInt16OfPCConfig()                          (TRUE != FALSE)
#define Com_HasRxSigBufferUInt8OfPCConfig()                           (TRUE != FALSE)
#define Com_HasRxSigInfoOfPCConfig()                                  (TRUE != FALSE)
#define Com_HasSigGrpEventFlagOfPCConfig()                            (TRUE != FALSE)
#define Com_HasSizeOfActivatableRxComIPdusOfPCConfig()                (TRUE != FALSE)
#define Com_HasSizeOfActivatableTxComIPdusOfPCConfig()                (TRUE != FALSE)
#define Com_HasSizeOfConstValueFloat32OfPCConfig()                    (TRUE != FALSE)
#define Com_HasSizeOfConstValueSInt16OfPCConfig()                     (TRUE != FALSE)
#define Com_HasSizeOfConstValueUInt16OfPCConfig()                     (TRUE != FALSE)
#define Com_HasSizeOfConstValueUInt8OfPCConfig()                      (TRUE != FALSE)
#define Com_HasSizeOfCurrentTxModeOfPCConfig()                        (TRUE != FALSE)
#define Com_HasSizeOfCycleTimeCntOfPCConfig()                         (TRUE != FALSE)
#define Com_HasSizeOfCyclicSendRequestOfPCConfig()                    (TRUE != FALSE)
#define Com_HasSizeOfDelayTimeCntOfPCConfig()                         (TRUE != FALSE)
#define Com_HasSizeOfHandleRxPduDeferredOfPCConfig()                  (TRUE != FALSE)
#define Com_HasSizeOfPduGrpVectorOfPCConfig()                         (TRUE != FALSE)
#define Com_HasSizeOfRepCntOfPCConfig()                               (TRUE != FALSE)
#define Com_HasSizeOfRepCycleCntOfPCConfig()                          (TRUE != FALSE)
#define Com_HasSizeOfRxAccessInfoIndOfPCConfig()                      (TRUE != FALSE)
#define Com_HasSizeOfRxAccessInfoOfPCConfig()                         (TRUE != FALSE)
#define Com_HasSizeOfRxDefPduBufferOfPCConfig()                       (TRUE != FALSE)
#define Com_HasSizeOfRxPduGrpActiveOfPCConfig()                       (TRUE != FALSE)
#define Com_HasSizeOfRxPduGrpInfoOfPCConfig()                         (TRUE != FALSE)
#define Com_HasSizeOfRxPduInfoOfPCConfig()                            (TRUE != FALSE)
#define Com_HasSizeOfRxSigBufferFloat32OfPCConfig()                   (TRUE != FALSE)
#define Com_HasSizeOfRxSigBufferSInt16OfPCConfig()                    (TRUE != FALSE)
#define Com_HasSizeOfRxSigBufferUInt16OfPCConfig()                    (TRUE != FALSE)
#define Com_HasSizeOfRxSigBufferUInt8OfPCConfig()                     (TRUE != FALSE)
#define Com_HasSizeOfRxSigInfoOfPCConfig()                            (TRUE != FALSE)
#define Com_HasSizeOfSigGrpEventFlagOfPCConfig()                      (TRUE != FALSE)
#define Com_HasSizeOfTransmitRequestOfPCConfig()                      (TRUE != FALSE)
#define Com_HasSizeOfTxBufferOfPCConfig()                             (TRUE != FALSE)
#define Com_HasSizeOfTxModeFalseOfPCConfig()                          (TRUE != FALSE)
#define Com_HasSizeOfTxModeInfoOfPCConfig()                           (TRUE != FALSE)
#define Com_HasSizeOfTxModeTrueOfPCConfig()                           (TRUE != FALSE)
#define Com_HasSizeOfTxPduGrpActiveOfPCConfig()                       (TRUE != FALSE)
#define Com_HasSizeOfTxPduGrpInfoOfPCConfig()                         (TRUE != FALSE)
#define Com_HasSizeOfTxPduInfoOfPCConfig()                            (TRUE != FALSE)
#define Com_HasSizeOfTxPduInitValueOfPCConfig()                       (TRUE != FALSE)
#define Com_HasSizeOfTxSduLengthOfPCConfig()                          (TRUE != FALSE)
#define Com_HasSizeOfTxSigGrpInfoIndOfPCConfig()                      (TRUE != FALSE)
#define Com_HasSizeOfTxSigGrpInfoOfPCConfig()                         (TRUE != FALSE)
#define Com_HasSizeOfTxSigGrpMaskOfPCConfig()                         (TRUE != FALSE)
#define Com_HasSizeOfTxSigInfoOfPCConfig()                            (TRUE != FALSE)
#define Com_HasTransmitRequestOfPCConfig()                            (TRUE != FALSE)
#define Com_HasTxBufferOfPCConfig()                                   (TRUE != FALSE)
#define Com_HasTxCyclicProcessingISRLockCounterOfPCConfig()           (TRUE != FALSE)
#define Com_HasTxCyclicProcessingISRLockThresholdOfPCConfig()         (TRUE != FALSE)
#define Com_HasTxDeadlineMonitoringISRLockCounterOfPCConfig()         (TRUE != FALSE)
#define Com_HasTxIPduGroupISRLockCounterOfPCConfig()                  (TRUE != FALSE)
#define Com_HasTxIPduGroupISRLockThresholdOfPCConfig()                (TRUE != FALSE)
#define Com_HasTxModeFalseOfPCConfig()                                (TRUE != FALSE)
#define Com_HasTxModeInfoOfPCConfig()                                 (TRUE != FALSE)
#define Com_HasTxModeTrueOfPCConfig()                                 (TRUE != FALSE)
#define Com_HasTxPduGrpActiveOfPCConfig()                             (TRUE != FALSE)
#define Com_HasTxPduGrpInfoOfPCConfig()                               (TRUE != FALSE)
#define Com_HasTxPduInfoOfPCConfig()                                  (TRUE != FALSE)
#define Com_HasTxPduInitValueOfPCConfig()                             (TRUE != FALSE)
#define Com_HasTxProcessingISRLockCounterOfPCConfig()                 (TRUE != FALSE)
#define Com_HasTxProcessingISRLockThresholdOfPCConfig()               (TRUE != FALSE)
#define Com_HasTxSduLengthOfPCConfig()                                (TRUE != FALSE)
#define Com_HasTxSigGrpInfoIndOfPCConfig()                            (TRUE != FALSE)
#define Com_HasTxSigGrpInfoOfPCConfig()                               (TRUE != FALSE)
#define Com_HasTxSigGrpMaskOfPCConfig()                               (TRUE != FALSE)
#define Com_HasTxSigInfoOfPCConfig()                                  (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  ComPCIncrementDataMacros  Com Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define Com_IncCycleTimeCnt(Index)                                    Com_GetCycleTimeCnt(Index)++
#define Com_IncDelayTimeCnt(Index)                                    Com_GetDelayTimeCnt(Index)++
#define Com_IncGatewayProcessingISRLockCounter()                      Com_GetGatewayProcessingISRLockCounter()++
#define Com_IncHandleRxPduDeferred(Index)                             Com_GetHandleRxPduDeferred(Index)++
#define Com_IncRepCnt(Index)                                          Com_GetRepCnt(Index)++
#define Com_IncRepCycleCnt(Index)                                     Com_GetRepCycleCnt(Index)++
#define Com_IncRxDeadlineMonitoringISRLockCounter()                   Com_GetRxDeadlineMonitoringISRLockCounter()++
#define Com_IncRxDefPduBuffer(Index)                                  Com_GetRxDefPduBuffer(Index)++
#define Com_IncRxDeferredProcessingISRLockCounter()                   Com_GetRxDeferredProcessingISRLockCounter()++
#define Com_IncRxIPduGroupISRLockCounter()                            Com_GetRxIPduGroupISRLockCounter()++
#define Com_IncRxSigBufferSInt16(Index)                               Com_GetRxSigBufferSInt16(Index)++
#define Com_IncRxSigBufferUInt16(Index)                               Com_GetRxSigBufferUInt16(Index)++
#define Com_IncRxSigBufferUInt8(Index)                                Com_GetRxSigBufferUInt8(Index)++
#define Com_IncSigGrpEventFlag(Index)                                 Com_GetSigGrpEventFlag(Index)++
#define Com_IncTxBuffer(Index)                                        Com_GetTxBuffer(Index)++
#define Com_IncTxCyclicProcessingISRLockCounter()                     Com_GetTxCyclicProcessingISRLockCounter()++
#define Com_IncTxDeadlineMonitoringISRLockCounter()                   Com_GetTxDeadlineMonitoringISRLockCounter()++
#define Com_IncTxIPduGroupISRLockCounter()                            Com_GetTxIPduGroupISRLockCounter()++
#define Com_IncTxProcessingISRLockCounter()                           Com_GetTxProcessingISRLockCounter()++
#define Com_IncTxSduLength(Index)                                     Com_GetTxSduLength(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  ComPCDecrementDataMacros  Com Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define Com_DecCycleTimeCnt(Index)                                    Com_GetCycleTimeCnt(Index)--
#define Com_DecDelayTimeCnt(Index)                                    Com_GetDelayTimeCnt(Index)--
#define Com_DecGatewayProcessingISRLockCounter()                      Com_GetGatewayProcessingISRLockCounter()--
#define Com_DecHandleRxPduDeferred(Index)                             Com_GetHandleRxPduDeferred(Index)--
#define Com_DecRepCnt(Index)                                          Com_GetRepCnt(Index)--
#define Com_DecRepCycleCnt(Index)                                     Com_GetRepCycleCnt(Index)--
#define Com_DecRxDeadlineMonitoringISRLockCounter()                   Com_GetRxDeadlineMonitoringISRLockCounter()--
#define Com_DecRxDefPduBuffer(Index)                                  Com_GetRxDefPduBuffer(Index)--
#define Com_DecRxDeferredProcessingISRLockCounter()                   Com_GetRxDeferredProcessingISRLockCounter()--
#define Com_DecRxIPduGroupISRLockCounter()                            Com_GetRxIPduGroupISRLockCounter()--
#define Com_DecRxSigBufferSInt16(Index)                               Com_GetRxSigBufferSInt16(Index)--
#define Com_DecRxSigBufferUInt16(Index)                               Com_GetRxSigBufferUInt16(Index)--
#define Com_DecRxSigBufferUInt8(Index)                                Com_GetRxSigBufferUInt8(Index)--
#define Com_DecSigGrpEventFlag(Index)                                 Com_GetSigGrpEventFlag(Index)--
#define Com_DecTxBuffer(Index)                                        Com_GetTxBuffer(Index)--
#define Com_DecTxCyclicProcessingISRLockCounter()                     Com_GetTxCyclicProcessingISRLockCounter()--
#define Com_DecTxDeadlineMonitoringISRLockCounter()                   Com_GetTxDeadlineMonitoringISRLockCounter()--
#define Com_DecTxIPduGroupISRLockCounter()                            Com_GetTxIPduGroupISRLockCounter()--
#define Com_DecTxProcessingISRLockCounter()                           Com_GetTxProcessingISRLockCounter()--
#define Com_DecTxSduLength(Index)                                     Com_GetTxSduLength(Index)--
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


/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  ComPCIterableTypes  Com Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate Com_ActivatableRxComIPdus */
typedef uint8_least Com_ActivatableRxComIPdusIterType;

/**   \brief  type used to iterate Com_ActivatableTxComIPdus */
typedef uint8_least Com_ActivatableTxComIPdusIterType;

/**   \brief  type used to iterate Com_ConstValueFloat32 */
typedef uint8_least Com_ConstValueFloat32IterType;

/**   \brief  type used to iterate Com_ConstValueSInt16 */
typedef uint8_least Com_ConstValueSInt16IterType;

/**   \brief  type used to iterate Com_ConstValueUInt16 */
typedef uint8_least Com_ConstValueUInt16IterType;

/**   \brief  type used to iterate Com_ConstValueUInt8 */
typedef uint8_least Com_ConstValueUInt8IterType;

/**   \brief  type used to iterate Com_HandleRxPduDeferred */
typedef uint8_least Com_HandleRxPduDeferredIterType;

/**   \brief  type used to iterate Com_PduGrpVector */
typedef uint8_least Com_PduGrpVectorIterType;

/**   \brief  type used to iterate Com_RxAccessInfo */
typedef uint16_least Com_RxAccessInfoIterType;

/**   \brief  type used to iterate Com_RxAccessInfoInd */
typedef uint16_least Com_RxAccessInfoIndIterType;

/**   \brief  type used to iterate Com_RxDefPduBuffer */
typedef uint16_least Com_RxDefPduBufferIterType;

/**   \brief  type used to iterate Com_RxPduGrpInfo */
typedef uint8_least Com_RxPduGrpInfoIterType;

/**   \brief  type used to iterate Com_RxPduInfo */
typedef uint8_least Com_RxPduInfoIterType;

/**   \brief  type used to iterate Com_RxSigBufferFloat32 */
typedef uint8_least Com_RxSigBufferFloat32IterType;

/**   \brief  type used to iterate Com_RxSigBufferSInt16 */
typedef uint8_least Com_RxSigBufferSInt16IterType;

/**   \brief  type used to iterate Com_RxSigBufferUInt16 */
typedef uint16_least Com_RxSigBufferUInt16IterType;

/**   \brief  type used to iterate Com_RxSigBufferUInt8 */
typedef uint8_least Com_RxSigBufferUInt8IterType;

/**   \brief  type used to iterate Com_RxSigInfo */
typedef uint16_least Com_RxSigInfoIterType;

/**   \brief  type used to iterate Com_TxBuffer */
typedef uint16_least Com_TxBufferIterType;

/**   \brief  type used to iterate Com_TxModeFalse */
typedef uint8_least Com_TxModeFalseIterType;

/**   \brief  type used to iterate Com_TxModeInfo */
typedef uint8_least Com_TxModeInfoIterType;

/**   \brief  type used to iterate Com_TxModeTrue */
typedef uint8_least Com_TxModeTrueIterType;

/**   \brief  type used to iterate Com_TxPduGrpInfo */
typedef uint8_least Com_TxPduGrpInfoIterType;

/**   \brief  type used to iterate Com_TxPduInfo */
typedef uint8_least Com_TxPduInfoIterType;

/**   \brief  type used to iterate Com_TxPduInitValue */
typedef uint16_least Com_TxPduInitValueIterType;

/**   \brief  type used to iterate Com_TxSigGrpInfo */
typedef uint8_least Com_TxSigGrpInfoIterType;

/**   \brief  type used to iterate Com_TxSigGrpInfoInd */
typedef uint8_least Com_TxSigGrpInfoIndIterType;

/**   \brief  type used to iterate Com_TxSigGrpMask */
typedef uint8_least Com_TxSigGrpMaskIterType;

/**   \brief  type used to iterate Com_TxSigInfo */
typedef uint8_least Com_TxSigInfoIterType;

/** 
  \}
*/ 

/** 
  \defgroup  ComPCIterableTypesWithSizeRelations  Com Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate Com_CurrentTxMode */
typedef Com_TxPduInfoIterType Com_CurrentTxModeIterType;

/**   \brief  type used to iterate Com_CycleTimeCnt */
typedef Com_TxPduInfoIterType Com_CycleTimeCntIterType;

/**   \brief  type used to iterate Com_CyclicSendRequest */
typedef Com_TxPduInfoIterType Com_CyclicSendRequestIterType;

/**   \brief  type used to iterate Com_DelayTimeCnt */
typedef Com_TxPduInfoIterType Com_DelayTimeCntIterType;

/**   \brief  type used to iterate Com_RepCnt */
typedef Com_TxPduInfoIterType Com_RepCntIterType;

/**   \brief  type used to iterate Com_RepCycleCnt */
typedef Com_TxPduInfoIterType Com_RepCycleCntIterType;

/**   \brief  type used to iterate Com_RxPduGrpActive */
typedef Com_RxPduInfoIterType Com_RxPduGrpActiveIterType;

/**   \brief  type used to iterate Com_SigGrpEventFlag */
typedef Com_TxSigGrpInfoIterType Com_SigGrpEventFlagIterType;

/**   \brief  type used to iterate Com_TransmitRequest */
typedef Com_TxPduInfoIterType Com_TransmitRequestIterType;

/**   \brief  type used to iterate Com_TxPduGrpActive */
typedef Com_TxPduInfoIterType Com_TxPduGrpActiveIterType;

/**   \brief  type used to iterate Com_TxSduLength */
typedef Com_TxPduInfoIterType Com_TxSduLengthIterType;

/** 
  \}
*/ 

/** 
  \defgroup  ComPCValueTypes  Com Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for Com_RxPduInfoIdxOfActivatableRxComIPdus */
typedef uint8 Com_RxPduInfoIdxOfActivatableRxComIPdusType;

/**   \brief  value based type definition for Com_TxPduInfoIdxOfActivatableTxComIPdus */
typedef uint8 Com_TxPduInfoIdxOfActivatableTxComIPdusType;

/**   \brief  value based type definition for Com_ConfigId */
typedef uint8 Com_ConfigIdType;

/**   \brief  value based type definition for Com_ConstValueFloat32 */
typedef float32 Com_ConstValueFloat32Type;

/**   \brief  value based type definition for Com_ConstValueSInt16 */
typedef sint8 Com_ConstValueSInt16Type;

/**   \brief  value based type definition for Com_ConstValueUInt16 */
typedef uint16 Com_ConstValueUInt16Type;

/**   \brief  value based type definition for Com_ConstValueUInt8 */
typedef uint8 Com_ConstValueUInt8Type;

/**   \brief  value based type definition for Com_CurrentTxMode */
typedef boolean Com_CurrentTxModeType;

/**   \brief  value based type definition for Com_CycleTimeCnt */
typedef uint8 Com_CycleTimeCntType;

/**   \brief  value based type definition for Com_CyclicSendRequest */
typedef boolean Com_CyclicSendRequestType;

/**   \brief  value based type definition for Com_DelayTimeCnt */
typedef uint8 Com_DelayTimeCntType;

/**   \brief  value based type definition for Com_GatewayProcessingISRLockCounter */
typedef uint16 Com_GatewayProcessingISRLockCounterType;

/**   \brief  value based type definition for Com_HandleRxPduDeferred */
typedef PduLengthType Com_HandleRxPduDeferredType;

/**   \brief  value based type definition for Com_Initialized */
typedef boolean Com_InitializedType;

/**   \brief  value based type definition for Com_PduGrpCnt */
typedef uint8 Com_PduGrpCntType;

/**   \brief  value based type definition for Com_PduGrpVector */
typedef uint8 Com_PduGrpVectorType;

/**   \brief  value based type definition for Com_RepCnt */
typedef uint8 Com_RepCntType;

/**   \brief  value based type definition for Com_RepCycleCnt */
typedef uint8 Com_RepCycleCntType;

/**   \brief  value based type definition for Com_ApplTypeOfRxAccessInfo */
typedef uint8 Com_ApplTypeOfRxAccessInfoType;

/**   \brief  value based type definition for Com_BitLengthOfRxAccessInfo */
typedef uint8 Com_BitLengthOfRxAccessInfoType;

/**   \brief  value based type definition for Com_BitPositionOfRxAccessInfo */
typedef uint8 Com_BitPositionOfRxAccessInfoType;

/**   \brief  value based type definition for Com_BufferIdxOfRxAccessInfo */
typedef uint16 Com_BufferIdxOfRxAccessInfoType;

/**   \brief  value based type definition for Com_BufferUsedOfRxAccessInfo */
typedef boolean Com_BufferUsedOfRxAccessInfoType;

/**   \brief  value based type definition for Com_BusAccOfRxAccessInfo */
typedef uint8 Com_BusAccOfRxAccessInfoType;

/**   \brief  value based type definition for Com_ByteLengthOfRxAccessInfo */
typedef uint8 Com_ByteLengthOfRxAccessInfoType;

/**   \brief  value based type definition for Com_BytePositionOfRxAccessInfo */
typedef uint8 Com_BytePositionOfRxAccessInfoType;

/**   \brief  value based type definition for Com_InitValueIdxOfRxAccessInfo */
typedef uint8 Com_InitValueIdxOfRxAccessInfoType;

/**   \brief  value based type definition for Com_InitValueUsedOfRxAccessInfo */
typedef boolean Com_InitValueUsedOfRxAccessInfoType;

/**   \brief  value based type definition for Com_RxPduInfoIdxOfRxAccessInfo */
typedef uint8 Com_RxPduInfoIdxOfRxAccessInfoType;

/**   \brief  value based type definition for Com_SignExtRequiredOfRxAccessInfo */
typedef boolean Com_SignExtRequiredOfRxAccessInfoType;

/**   \brief  value based type definition for Com_StartByteInPduPositionOfRxAccessInfo */
typedef uint8 Com_StartByteInPduPositionOfRxAccessInfoType;

/**   \brief  value based type definition for Com_RxAccessInfoInd */
typedef uint16 Com_RxAccessInfoIndType;

/**   \brief  value based type definition for Com_RxDeadlineMonitoringISRLockCounter */
typedef uint16 Com_RxDeadlineMonitoringISRLockCounterType;

/**   \brief  value based type definition for Com_RxDefPduBuffer */
typedef uint8 Com_RxDefPduBufferType;

/**   \brief  value based type definition for Com_RxDeferredProcessingISRLockCounter */
typedef uint16 Com_RxDeferredProcessingISRLockCounterType;

/**   \brief  value based type definition for Com_RxDeferredProcessingISRLockThreshold */
typedef uint8 Com_RxDeferredProcessingISRLockThresholdType;

/**   \brief  value based type definition for Com_RxIPduGroupISRLockCounter */
typedef uint16 Com_RxIPduGroupISRLockCounterType;

/**   \brief  value based type definition for Com_RxIPduGroupISRLockThreshold */
typedef uint8 Com_RxIPduGroupISRLockThresholdType;

/**   \brief  value based type definition for Com_RxPduGrpActive */
typedef boolean Com_RxPduGrpActiveType;

/**   \brief  value based type definition for Com_PduGrpVectorEndIdxOfRxPduGrpInfo */
typedef uint8 Com_PduGrpVectorEndIdxOfRxPduGrpInfoType;

/**   \brief  value based type definition for Com_PduGrpVectorStartIdxOfRxPduGrpInfo */
typedef uint8 Com_PduGrpVectorStartIdxOfRxPduGrpInfoType;

/**   \brief  value based type definition for Com_PduGrpVectorUsedOfRxPduGrpInfo */
typedef boolean Com_PduGrpVectorUsedOfRxPduGrpInfoType;

/**   \brief  value based type definition for Com_HandleRxPduDeferredIdxOfRxPduInfo */
typedef uint8 Com_HandleRxPduDeferredIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_HandleRxPduDeferredUsedOfRxPduInfo */
typedef boolean Com_HandleRxPduDeferredUsedOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxAccessInfoIndEndIdxOfRxPduInfo */
typedef uint16 Com_RxAccessInfoIndEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxAccessInfoIndStartIdxOfRxPduInfo */
typedef uint16 Com_RxAccessInfoIndStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxAccessInfoIndUsedOfRxPduInfo */
typedef boolean Com_RxAccessInfoIndUsedOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxDefPduBufferEndIdxOfRxPduInfo */
typedef uint16 Com_RxDefPduBufferEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxDefPduBufferLengthOfRxPduInfo */
typedef uint8 Com_RxDefPduBufferLengthOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxDefPduBufferStartIdxOfRxPduInfo */
typedef uint16 Com_RxDefPduBufferStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxDefPduBufferUsedOfRxPduInfo */
typedef boolean Com_RxDefPduBufferUsedOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxSigInfoEndIdxOfRxPduInfo */
typedef uint16 Com_RxSigInfoEndIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxSigInfoStartIdxOfRxPduInfo */
typedef uint16 Com_RxSigInfoStartIdxOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxSigInfoUsedOfRxPduInfo */
typedef boolean Com_RxSigInfoUsedOfRxPduInfoType;

/**   \brief  value based type definition for Com_SignalProcessingOfRxPduInfo */
typedef uint8 Com_SignalProcessingOfRxPduInfoType;

/**   \brief  value based type definition for Com_TypeOfRxPduInfo */
typedef uint8 Com_TypeOfRxPduInfoType;

/**   \brief  value based type definition for Com_RxSigBufferFloat32 */
typedef float32 Com_RxSigBufferFloat32Type;

/**   \brief  value based type definition for Com_RxSigBufferSInt16 */
typedef sint16 Com_RxSigBufferSInt16Type;

/**   \brief  value based type definition for Com_RxSigBufferUInt16 */
typedef uint16 Com_RxSigBufferUInt16Type;

/**   \brief  value based type definition for Com_RxSigBufferUInt8 */
typedef uint8 Com_RxSigBufferUInt8Type;

/**   \brief  value based type definition for Com_RxAccessInfoIdxOfRxSigInfo */
typedef uint16 Com_RxAccessInfoIdxOfRxSigInfoType;

/**   \brief  value based type definition for Com_SignalProcessingOfRxSigInfo */
typedef uint8 Com_SignalProcessingOfRxSigInfoType;

/**   \brief  value based type definition for Com_ValidDlcOfRxSigInfo */
typedef uint8 Com_ValidDlcOfRxSigInfoType;

/**   \brief  value based type definition for Com_SigGrpEventFlag */
typedef uint8 Com_SigGrpEventFlagType;

/**   \brief  value based type definition for Com_SizeOfActivatableRxComIPdus */
typedef uint8 Com_SizeOfActivatableRxComIPdusType;

/**   \brief  value based type definition for Com_SizeOfActivatableTxComIPdus */
typedef uint8 Com_SizeOfActivatableTxComIPdusType;

/**   \brief  value based type definition for Com_SizeOfConstValueFloat32 */
typedef uint8 Com_SizeOfConstValueFloat32Type;

/**   \brief  value based type definition for Com_SizeOfConstValueSInt16 */
typedef uint8 Com_SizeOfConstValueSInt16Type;

/**   \brief  value based type definition for Com_SizeOfConstValueUInt16 */
typedef uint8 Com_SizeOfConstValueUInt16Type;

/**   \brief  value based type definition for Com_SizeOfConstValueUInt8 */
typedef uint8 Com_SizeOfConstValueUInt8Type;

/**   \brief  value based type definition for Com_SizeOfCurrentTxMode */
typedef uint8 Com_SizeOfCurrentTxModeType;

/**   \brief  value based type definition for Com_SizeOfCycleTimeCnt */
typedef uint8 Com_SizeOfCycleTimeCntType;

/**   \brief  value based type definition for Com_SizeOfCyclicSendRequest */
typedef uint8 Com_SizeOfCyclicSendRequestType;

/**   \brief  value based type definition for Com_SizeOfDelayTimeCnt */
typedef uint8 Com_SizeOfDelayTimeCntType;

/**   \brief  value based type definition for Com_SizeOfHandleRxPduDeferred */
typedef uint8 Com_SizeOfHandleRxPduDeferredType;

/**   \brief  value based type definition for Com_SizeOfPduGrpVector */
typedef uint8 Com_SizeOfPduGrpVectorType;

/**   \brief  value based type definition for Com_SizeOfRepCnt */
typedef uint8 Com_SizeOfRepCntType;

/**   \brief  value based type definition for Com_SizeOfRepCycleCnt */
typedef uint8 Com_SizeOfRepCycleCntType;

/**   \brief  value based type definition for Com_SizeOfRxAccessInfo */
typedef uint16 Com_SizeOfRxAccessInfoType;

/**   \brief  value based type definition for Com_SizeOfRxAccessInfoInd */
typedef uint16 Com_SizeOfRxAccessInfoIndType;

/**   \brief  value based type definition for Com_SizeOfRxDefPduBuffer */
typedef uint16 Com_SizeOfRxDefPduBufferType;

/**   \brief  value based type definition for Com_SizeOfRxPduGrpActive */
typedef uint8 Com_SizeOfRxPduGrpActiveType;

/**   \brief  value based type definition for Com_SizeOfRxPduGrpInfo */
typedef uint8 Com_SizeOfRxPduGrpInfoType;

/**   \brief  value based type definition for Com_SizeOfRxPduInfo */
typedef uint8 Com_SizeOfRxPduInfoType;

/**   \brief  value based type definition for Com_SizeOfRxSigBufferFloat32 */
typedef uint8 Com_SizeOfRxSigBufferFloat32Type;

/**   \brief  value based type definition for Com_SizeOfRxSigBufferSInt16 */
typedef uint8 Com_SizeOfRxSigBufferSInt16Type;

/**   \brief  value based type definition for Com_SizeOfRxSigBufferUInt16 */
typedef uint16 Com_SizeOfRxSigBufferUInt16Type;

/**   \brief  value based type definition for Com_SizeOfRxSigBufferUInt8 */
typedef uint8 Com_SizeOfRxSigBufferUInt8Type;

/**   \brief  value based type definition for Com_SizeOfRxSigInfo */
typedef uint16 Com_SizeOfRxSigInfoType;

/**   \brief  value based type definition for Com_SizeOfSigGrpEventFlag */
typedef uint8 Com_SizeOfSigGrpEventFlagType;

/**   \brief  value based type definition for Com_SizeOfTransmitRequest */
typedef uint8 Com_SizeOfTransmitRequestType;

/**   \brief  value based type definition for Com_SizeOfTxBuffer */
typedef uint16 Com_SizeOfTxBufferType;

/**   \brief  value based type definition for Com_SizeOfTxModeFalse */
typedef uint8 Com_SizeOfTxModeFalseType;

/**   \brief  value based type definition for Com_SizeOfTxModeInfo */
typedef uint8 Com_SizeOfTxModeInfoType;

/**   \brief  value based type definition for Com_SizeOfTxModeTrue */
typedef uint8 Com_SizeOfTxModeTrueType;

/**   \brief  value based type definition for Com_SizeOfTxPduGrpActive */
typedef uint8 Com_SizeOfTxPduGrpActiveType;

/**   \brief  value based type definition for Com_SizeOfTxPduGrpInfo */
typedef uint8 Com_SizeOfTxPduGrpInfoType;

/**   \brief  value based type definition for Com_SizeOfTxPduInfo */
typedef uint8 Com_SizeOfTxPduInfoType;

/**   \brief  value based type definition for Com_SizeOfTxPduInitValue */
typedef uint16 Com_SizeOfTxPduInitValueType;

/**   \brief  value based type definition for Com_SizeOfTxSduLength */
typedef uint8 Com_SizeOfTxSduLengthType;

/**   \brief  value based type definition for Com_SizeOfTxSigGrpInfo */
typedef uint8 Com_SizeOfTxSigGrpInfoType;

/**   \brief  value based type definition for Com_SizeOfTxSigGrpInfoInd */
typedef uint8 Com_SizeOfTxSigGrpInfoIndType;

/**   \brief  value based type definition for Com_SizeOfTxSigGrpMask */
typedef uint8 Com_SizeOfTxSigGrpMaskType;

/**   \brief  value based type definition for Com_SizeOfTxSigInfo */
typedef uint8 Com_SizeOfTxSigInfoType;

/**   \brief  value based type definition for Com_TransmitRequest */
typedef boolean Com_TransmitRequestType;

/**   \brief  value based type definition for Com_TxBuffer */
typedef uint8 Com_TxBufferType;

/**   \brief  value based type definition for Com_TxCyclicProcessingISRLockCounter */
typedef uint16 Com_TxCyclicProcessingISRLockCounterType;

/**   \brief  value based type definition for Com_TxCyclicProcessingISRLockThreshold */
typedef uint8 Com_TxCyclicProcessingISRLockThresholdType;

/**   \brief  value based type definition for Com_TxDeadlineMonitoringISRLockCounter */
typedef uint16 Com_TxDeadlineMonitoringISRLockCounterType;

/**   \brief  value based type definition for Com_TxIPduGroupISRLockCounter */
typedef uint16 Com_TxIPduGroupISRLockCounterType;

/**   \brief  value based type definition for Com_TxIPduGroupISRLockThreshold */
typedef uint8 Com_TxIPduGroupISRLockThresholdType;

/**   \brief  value based type definition for Com_PeriodicOfTxModeFalse */
typedef boolean Com_PeriodicOfTxModeFalseType;

/**   \brief  value based type definition for Com_TimePeriodOfTxModeFalse */
typedef uint8 Com_TimePeriodOfTxModeFalseType;

/**   \brief  value based type definition for Com_InitModeOfTxModeInfo */
typedef boolean Com_InitModeOfTxModeInfoType;

/**   \brief  value based type definition for Com_MinimumDelayOfTxModeInfo */
typedef uint8 Com_MinimumDelayOfTxModeInfoType;

/**   \brief  value based type definition for Com_TxModeFalseIdxOfTxModeInfo */
typedef uint8 Com_TxModeFalseIdxOfTxModeInfoType;

/**   \brief  value based type definition for Com_TxModeTrueIdxOfTxModeInfo */
typedef uint8 Com_TxModeTrueIdxOfTxModeInfoType;

/**   \brief  value based type definition for Com_PeriodicOfTxModeTrue */
typedef boolean Com_PeriodicOfTxModeTrueType;

/**   \brief  value based type definition for Com_TimePeriodOfTxModeTrue */
typedef uint8 Com_TimePeriodOfTxModeTrueType;

/**   \brief  value based type definition for Com_TxPduGrpActive */
typedef boolean Com_TxPduGrpActiveType;

/**   \brief  value based type definition for Com_PduGrpVectorEndIdxOfTxPduGrpInfo */
typedef uint8 Com_PduGrpVectorEndIdxOfTxPduGrpInfoType;

/**   \brief  value based type definition for Com_PduGrpVectorStartIdxOfTxPduGrpInfo */
typedef uint8 Com_PduGrpVectorStartIdxOfTxPduGrpInfoType;

/**   \brief  value based type definition for Com_PduGrpVectorUsedOfTxPduGrpInfo */
typedef boolean Com_PduGrpVectorUsedOfTxPduGrpInfoType;

/**   \brief  value based type definition for Com_ExternalIdOfTxPduInfo */
typedef uint8 Com_ExternalIdOfTxPduInfoType;

/**   \brief  value based type definition for Com_MetaDataLengthOfTxPduInfo */
typedef uint8 Com_MetaDataLengthOfTxPduInfoType;

/**   \brief  value based type definition for Com_PduWithMetaDataLengthOfTxPduInfo */
typedef uint8 Com_PduWithMetaDataLengthOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxBufferEndIdxOfTxPduInfo */
typedef uint16 Com_TxBufferEndIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxBufferLengthOfTxPduInfo */
typedef uint8 Com_TxBufferLengthOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxBufferStartIdxOfTxPduInfo */
typedef uint16 Com_TxBufferStartIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxBufferUsedOfTxPduInfo */
typedef boolean Com_TxBufferUsedOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxPduInitValueEndIdxOfTxPduInfo */
typedef uint16 Com_TxPduInitValueEndIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxPduInitValueStartIdxOfTxPduInfo */
typedef uint16 Com_TxPduInitValueStartIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxPduInitValueUsedOfTxPduInfo */
typedef boolean Com_TxPduInitValueUsedOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxSigGrpInfoIndEndIdxOfTxPduInfo */
typedef uint8 Com_TxSigGrpInfoIndEndIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxSigGrpInfoIndStartIdxOfTxPduInfo */
typedef uint8 Com_TxSigGrpInfoIndStartIdxOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxSigGrpInfoIndUsedOfTxPduInfo */
typedef boolean Com_TxSigGrpInfoIndUsedOfTxPduInfoType;

/**   \brief  value based type definition for Com_TxPduInitValue */
typedef uint8 Com_TxPduInitValueType;

/**   \brief  value based type definition for Com_TxProcessingISRLockCounter */
typedef uint16 Com_TxProcessingISRLockCounterType;

/**   \brief  value based type definition for Com_TxProcessingISRLockThreshold */
typedef uint8 Com_TxProcessingISRLockThresholdType;

/**   \brief  value based type definition for Com_TxSduLength */
typedef PduLengthType Com_TxSduLengthType;

/**   \brief  value based type definition for Com_PduOffsetOfTxSigGrpInfo */
typedef uint8 Com_PduOffsetOfTxSigGrpInfoType;

/**   \brief  value based type definition for Com_TransferPropertyOfTxSigGrpInfo */
typedef uint8 Com_TransferPropertyOfTxSigGrpInfoType;

/**   \brief  value based type definition for Com_TxBufferEndIdxOfTxSigGrpInfo */
typedef uint16 Com_TxBufferEndIdxOfTxSigGrpInfoType;

/**   \brief  value based type definition for Com_TxBufferLengthOfTxSigGrpInfo */
typedef uint8 Com_TxBufferLengthOfTxSigGrpInfoType;

/**   \brief  value based type definition for Com_TxBufferSigGrpInTxIPDUEndIdxOfTxSigGrpInfo */
typedef uint16 Com_TxBufferSigGrpInTxIPDUEndIdxOfTxSigGrpInfoType;

/**   \brief  value based type definition for Com_TxBufferSigGrpInTxIPDULengthOfTxSigGrpInfo */
typedef uint8 Com_TxBufferSigGrpInTxIPDULengthOfTxSigGrpInfoType;

/**   \brief  value based type definition for Com_TxBufferSigGrpInTxIPDUStartIdxOfTxSigGrpInfo */
typedef uint16 Com_TxBufferSigGrpInTxIPDUStartIdxOfTxSigGrpInfoType;

/**   \brief  value based type definition for Com_TxBufferStartIdxOfTxSigGrpInfo */
typedef uint16 Com_TxBufferStartIdxOfTxSigGrpInfoType;

/**   \brief  value based type definition for Com_TxBufferUsedOfTxSigGrpInfo */
typedef boolean Com_TxBufferUsedOfTxSigGrpInfoType;

/**   \brief  value based type definition for Com_TxPduInfoIdxOfTxSigGrpInfo */
typedef uint8 Com_TxPduInfoIdxOfTxSigGrpInfoType;

/**   \brief  value based type definition for Com_TxSigGrpMaskEndIdxOfTxSigGrpInfo */
typedef uint8 Com_TxSigGrpMaskEndIdxOfTxSigGrpInfoType;

/**   \brief  value based type definition for Com_TxSigGrpMaskLengthOfTxSigGrpInfo */
typedef uint8 Com_TxSigGrpMaskLengthOfTxSigGrpInfoType;

/**   \brief  value based type definition for Com_TxSigGrpMaskStartIdxOfTxSigGrpInfo */
typedef uint8 Com_TxSigGrpMaskStartIdxOfTxSigGrpInfoType;

/**   \brief  value based type definition for Com_TxSigGrpMaskUsedOfTxSigGrpInfo */
typedef boolean Com_TxSigGrpMaskUsedOfTxSigGrpInfoType;

/**   \brief  value based type definition for Com_TxSigGrpInfoInd */
typedef uint8 Com_TxSigGrpInfoIndType;

/**   \brief  value based type definition for Com_TxSigGrpMask */
typedef uint8 Com_TxSigGrpMaskType;

/**   \brief  value based type definition for Com_ApplTypeOfTxSigInfo */
typedef uint8 Com_ApplTypeOfTxSigInfoType;

/**   \brief  value based type definition for Com_BitLengthOfTxSigInfo */
typedef uint8 Com_BitLengthOfTxSigInfoType;

/**   \brief  value based type definition for Com_BitPositionOfTxSigInfo */
typedef uint16 Com_BitPositionOfTxSigInfoType;

/**   \brief  value based type definition for Com_BusAccOfTxSigInfo */
typedef uint8 Com_BusAccOfTxSigInfoType;

/**   \brief  value based type definition for Com_ByteLengthOfTxSigInfo */
typedef uint8 Com_ByteLengthOfTxSigInfoType;

/**   \brief  value based type definition for Com_BytePositionOfTxSigInfo */
typedef uint8 Com_BytePositionOfTxSigInfoType;

/**   \brief  value based type definition for Com_StartByteInPduPositionOfTxSigInfo */
typedef uint8 Com_StartByteInPduPositionOfTxSigInfoType;

/**   \brief  value based type definition for Com_TxBufferEndIdxOfTxSigInfo */
typedef uint16 Com_TxBufferEndIdxOfTxSigInfoType;

/**   \brief  value based type definition for Com_TxBufferLengthOfTxSigInfo */
typedef uint8 Com_TxBufferLengthOfTxSigInfoType;

/**   \brief  value based type definition for Com_TxBufferStartIdxOfTxSigInfo */
typedef uint16 Com_TxBufferStartIdxOfTxSigInfoType;

/**   \brief  value based type definition for Com_TxBufferUsedOfTxSigInfo */
typedef boolean Com_TxBufferUsedOfTxSigInfoType;

/**   \brief  value based type definition for Com_TxPduInfoIdxOfTxSigInfo */
typedef uint8 Com_TxPduInfoIdxOfTxSigInfoType;

/**   \brief  value based type definition for Com_TxSigGrpInfoIdxOfTxSigInfo */
typedef uint8 Com_TxSigGrpInfoIdxOfTxSigInfoType;

/**   \brief  value based type definition for Com_TxSigGrpInfoUsedOfTxSigInfo */
typedef boolean Com_TxSigGrpInfoUsedOfTxSigInfoType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  ComPCStructTypes  Com Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in Com_ActivatableRxComIPdus */
typedef struct sCom_ActivatableRxComIPdusType
{
  uint8 Com_ActivatableRxComIPdusNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Com_ActivatableRxComIPdusType;

/**   \brief  type used in Com_ActivatableTxComIPdus */
typedef struct sCom_ActivatableTxComIPdusType
{
  uint8 Com_ActivatableTxComIPdusNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Com_ActivatableTxComIPdusType;

/**   \brief  type used in Com_RxAccessInfo */
typedef struct sCom_RxAccessInfoType
{
  Com_BufferIdxOfRxAccessInfoType BufferIdxOfRxAccessInfo;  /**< the index of the 0:1 relation pointing to Com_RxSigBufferUInt8,Com_RxSigBufferUInt16,Com_RxSigBufferUInt32,Com_RxSigBufferUInt64,Com_RxSigBufferZeroBit,Com_RxSigBufferSInt8,Com_RxSigBufferSInt16,Com_RxSigBufferSInt32,Com_RxSigBufferSInt64,Com_RxSigBufferFloat32,Com_RxSigBufferFloat64 */
  Com_InitValueUsedOfRxAccessInfoType InitValueUsedOfRxAccessInfo;  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64,Com_ConstValueFloat32,Com_ConstValueFloat64 */
  Com_SignExtRequiredOfRxAccessInfoType SignExtRequiredOfRxAccessInfo;  /**< TRUE if sign extension is required for signal / group signal reception. */
  Com_ApplTypeOfRxAccessInfoType ApplTypeOfRxAccessInfo;  /**< Application data type. */
  Com_BitLengthOfRxAccessInfoType BitLengthOfRxAccessInfo;  /**< Bit length of the signal or group signal. */
  Com_BitPositionOfRxAccessInfoType BitPositionOfRxAccessInfo;  /**< Little endian bit position of the signal or group signal within the I-PDU. */
  Com_BusAccOfRxAccessInfoType BusAccOfRxAccessInfo;  /**< BUS access algorithm for signal or group signal packing / un-packing. */
  Com_ByteLengthOfRxAccessInfoType ByteLengthOfRxAccessInfo;  /**< Byte length of the signal or group signal. */
  Com_BytePositionOfRxAccessInfoType BytePositionOfRxAccessInfo;  /**< Little endian byte position of the signal or group signal within the I-PDU. */
  Com_InitValueIdxOfRxAccessInfoType InitValueIdxOfRxAccessInfo;  /**< the index of the 0:1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64,Com_ConstValueFloat32,Com_ConstValueFloat64 */
  Com_RxPduInfoIdxOfRxAccessInfoType RxPduInfoIdxOfRxAccessInfo;  /**< the index of the 1:1 relation pointing to Com_RxPduInfo */
  Com_StartByteInPduPositionOfRxAccessInfoType StartByteInPduPositionOfRxAccessInfo;  /**< Start Byte position of the signal or group signal within the I-PDU. */
} Com_RxAccessInfoType;

/**   \brief  type used in Com_RxPduGrpInfo */
typedef struct sCom_RxPduGrpInfoType
{
  Com_PduGrpVectorEndIdxOfRxPduGrpInfoType PduGrpVectorEndIdxOfRxPduGrpInfo;  /**< the end index of the 0:n relation pointing to Com_PduGrpVector */
  Com_PduGrpVectorStartIdxOfRxPduGrpInfoType PduGrpVectorStartIdxOfRxPduGrpInfo;  /**< the start index of the 0:n relation pointing to Com_PduGrpVector */
} Com_RxPduGrpInfoType;

/**   \brief  type used in Com_RxPduInfo */
typedef struct sCom_RxPduInfoType
{
  Com_RxDefPduBufferEndIdxOfRxPduInfoType RxDefPduBufferEndIdxOfRxPduInfo;  /**< the end index of the 0:n relation pointing to Com_RxDefPduBuffer */
  Com_RxDefPduBufferStartIdxOfRxPduInfoType RxDefPduBufferStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to Com_RxDefPduBuffer */
  Com_RxSigInfoEndIdxOfRxPduInfoType RxSigInfoEndIdxOfRxPduInfo;  /**< the end index of the 0:n relation pointing to Com_RxSigInfo */
  Com_RxSigInfoStartIdxOfRxPduInfoType RxSigInfoStartIdxOfRxPduInfo;  /**< the start index of the 0:n relation pointing to Com_RxSigInfo */
  Com_RxAccessInfoIndUsedOfRxPduInfoType RxAccessInfoIndUsedOfRxPduInfo;  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_RxAccessInfoInd */
  Com_TypeOfRxPduInfoType TypeOfRxPduInfo;  /**< Defines whether rx Pdu is a NORMAL or TP IPdu. */
} Com_RxPduInfoType;

/**   \brief  type used in Com_RxSigInfo */
typedef struct sCom_RxSigInfoType
{
  Com_RxAccessInfoIdxOfRxSigInfoType RxAccessInfoIdxOfRxSigInfo;  /**< the index of the 1:1 relation pointing to Com_RxAccessInfo */
  Com_SignalProcessingOfRxSigInfoType SignalProcessingOfRxSigInfo;
  Com_ValidDlcOfRxSigInfoType ValidDlcOfRxSigInfo;  /**< Minimum length of PDU required to completely receive the signal or signal group. */
} Com_RxSigInfoType;

/**   \brief  type used in Com_TxModeFalse */
typedef struct sCom_TxModeFalseType
{
  Com_PeriodicOfTxModeFalseType PeriodicOfTxModeFalse;  /**< TRUE if transmission mode contains a cyclic part. */
  Com_TimePeriodOfTxModeFalseType TimePeriodOfTxModeFalse;  /**< Cycle time factor. */
} Com_TxModeFalseType;

/**   \brief  type used in Com_TxModeInfo */
typedef struct sCom_TxModeInfoType
{
  Com_InitModeOfTxModeInfoType InitModeOfTxModeInfo;  /**< Initial transmission mode selector of the Tx I-PDU. */
  Com_MinimumDelayOfTxModeInfoType MinimumDelayOfTxModeInfo;  /**< Minimum delay factor of the Tx I-PDU. */
  Com_TxModeTrueIdxOfTxModeInfoType TxModeTrueIdxOfTxModeInfo;  /**< the index of the 1:1 relation pointing to Com_TxModeTrue */
} Com_TxModeInfoType;

/**   \brief  type used in Com_TxModeTrue */
typedef struct sCom_TxModeTrueType
{
  Com_PeriodicOfTxModeTrueType PeriodicOfTxModeTrue;  /**< TRUE if transmission mode contains a cyclic part. */
  Com_TimePeriodOfTxModeTrueType TimePeriodOfTxModeTrue;  /**< Cycle time factor. */
} Com_TxModeTrueType;

/**   \brief  type used in Com_TxPduGrpInfo */
typedef struct sCom_TxPduGrpInfoType
{
  Com_PduGrpVectorEndIdxOfTxPduGrpInfoType PduGrpVectorEndIdxOfTxPduGrpInfo;  /**< the end index of the 0:n relation pointing to Com_PduGrpVector */
  Com_PduGrpVectorStartIdxOfTxPduGrpInfoType PduGrpVectorStartIdxOfTxPduGrpInfo;  /**< the start index of the 0:n relation pointing to Com_PduGrpVector */
} Com_TxPduGrpInfoType;

/**   \brief  type used in Com_TxPduInfo */
typedef struct sCom_TxPduInfoType
{
  Com_TxPduInitValueEndIdxOfTxPduInfoType TxPduInitValueEndIdxOfTxPduInfo;  /**< the end index of the 0:n relation pointing to Com_TxPduInitValue */
  Com_TxPduInitValueStartIdxOfTxPduInfoType TxPduInitValueStartIdxOfTxPduInfo;  /**< the start index of the 0:n relation pointing to Com_TxPduInitValue */
  Com_TxPduInitValueUsedOfTxPduInfoType TxPduInitValueUsedOfTxPduInfo;  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_TxPduInitValue */
  Com_MetaDataLengthOfTxPduInfoType MetaDataLengthOfTxPduInfo;  /**< Length of MetaData. */
  Com_TxBufferLengthOfTxPduInfoType TxBufferLengthOfTxPduInfo;  /**< the number of relations pointing to Com_TxBuffer */
  Com_TxSigGrpInfoIndEndIdxOfTxPduInfoType TxSigGrpInfoIndEndIdxOfTxPduInfo;  /**< the end index of the 0:n relation pointing to Com_TxSigGrpInfoInd */
  Com_TxSigGrpInfoIndStartIdxOfTxPduInfoType TxSigGrpInfoIndStartIdxOfTxPduInfo;  /**< the start index of the 0:n relation pointing to Com_TxSigGrpInfoInd */
} Com_TxPduInfoType;

/**   \brief  type used in Com_TxSigGrpInfo */
typedef struct sCom_TxSigGrpInfoType
{
  Com_TxBufferSigGrpInTxIPDUStartIdxOfTxSigGrpInfoType TxBufferSigGrpInTxIPDUStartIdxOfTxSigGrpInfo;  /**< the start index of the 1:n relation pointing to Com_TxBuffer */
  Com_TxBufferStartIdxOfTxSigGrpInfoType TxBufferStartIdxOfTxSigGrpInfo;  /**< the start index of the 0:n relation pointing to Com_TxBuffer */
  Com_TxSigGrpMaskUsedOfTxSigGrpInfoType TxSigGrpMaskUsedOfTxSigGrpInfo;  /**< TRUE, if the 0:n relation has 1 relation pointing to Com_TxSigGrpMask */
  Com_TransferPropertyOfTxSigGrpInfoType TransferPropertyOfTxSigGrpInfo;
  Com_TxBufferSigGrpInTxIPDULengthOfTxSigGrpInfoType TxBufferSigGrpInTxIPDULengthOfTxSigGrpInfo;  /**< the number of relations pointing to Com_TxBuffer */
  Com_TxSigGrpMaskStartIdxOfTxSigGrpInfoType TxSigGrpMaskStartIdxOfTxSigGrpInfo;  /**< the start index of the 0:n relation pointing to Com_TxSigGrpMask */
} Com_TxSigGrpInfoType;

/**   \brief  type used in Com_TxSigInfo */
typedef struct sCom_TxSigInfoType
{
  Com_BitPositionOfTxSigInfoType BitPositionOfTxSigInfo;  /**< Little endian bit position of the signal or group signal within the I-PDU. */
  Com_TxBufferEndIdxOfTxSigInfoType TxBufferEndIdxOfTxSigInfo;  /**< the end index of the 0:n relation pointing to Com_TxBuffer */
  Com_TxBufferStartIdxOfTxSigInfoType TxBufferStartIdxOfTxSigInfo;  /**< the start index of the 0:n relation pointing to Com_TxBuffer */
  Com_ApplTypeOfTxSigInfoType ApplTypeOfTxSigInfo;  /**< Application data type. */
  Com_BitLengthOfTxSigInfoType BitLengthOfTxSigInfo;  /**< Bit length of the signal or group signal. */
  Com_BusAccOfTxSigInfoType BusAccOfTxSigInfo;  /**< BUS access algorithm for signal or group signal packing / un-packing. */
  Com_ByteLengthOfTxSigInfoType ByteLengthOfTxSigInfo;  /**< Byte length of the signal or group signal. */
  Com_StartByteInPduPositionOfTxSigInfoType StartByteInPduPositionOfTxSigInfo;  /**< Start Byte position of the signal or group signal within the I-PDU. */
  Com_TxPduInfoIdxOfTxSigInfoType TxPduInfoIdxOfTxSigInfo;  /**< the index of the 1:1 relation pointing to Com_TxPduInfo */
  Com_TxSigGrpInfoIdxOfTxSigInfoType TxSigGrpInfoIdxOfTxSigInfo;  /**< the index of the 0:1 relation pointing to Com_TxSigGrpInfo */
} Com_TxSigInfoType;

/** 
  \}
*/ 

/** 
  \defgroup  ComPCSymbolicStructTypes  Com Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to Com_HandleRxPduDeferred */
typedef struct Com_HandleRxPduDeferredStructSTag
{
  Com_HandleRxPduDeferredType BecmPropFr01_oCAN00_e2f0fff8_Rx;
  Com_HandleRxPduDeferredType EcmPropFr00_oCAN00_2afbaddb_Rx;
  Com_HandleRxPduDeferredType EcmPropFr07_oCAN00_203ea4c2_Rx;
  Com_HandleRxPduDeferredType EcmPropFr24_oCAN00_80478ba7_Rx;
  Com_HandleRxPduDeferredType IemEduPropFr01_oCAN00_97fdab75_Rx;
  Com_HandleRxPduDeferredType MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_985efe2d_Rx;
  Com_HandleRxPduDeferredType MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_8b12c95b_Rx;
  Com_HandleRxPduDeferredType MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_49f811f9_Rx;
  Com_HandleRxPduDeferredType MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_5ab4268f_Rx;
  Com_HandleRxPduDeferredType MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx;
  Com_HandleRxPduDeferredType MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx;
  Com_HandleRxPduDeferredType MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx;
  Com_HandleRxPduDeferredType MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx;
  Com_HandleRxPduDeferredType MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx;
  Com_HandleRxPduDeferredType MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx;
  Com_HandleRxPduDeferredType MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx;
  Com_HandleRxPduDeferredType MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx;
  Com_HandleRxPduDeferredType MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx;
  Com_HandleRxPduDeferredType MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx;
  Com_HandleRxPduDeferredType MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx;
  Com_HandleRxPduDeferredType MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx;
  Com_HandleRxPduDeferredType MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx;
  Com_HandleRxPduDeferredType MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx;
  Com_HandleRxPduDeferredType MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx;
  Com_HandleRxPduDeferredType MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx;
  Com_HandleRxPduDeferredType MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx;
  Com_HandleRxPduDeferredType MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx;
  Com_HandleRxPduDeferredType MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx;
  Com_HandleRxPduDeferredType MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx;
  Com_HandleRxPduDeferredType TcmPropFr04_oCAN00_6f4049d8_Rx;
  Com_HandleRxPduDeferredType VddmPropFr05_oCAN00_53500d40_Rx;
  Com_HandleRxPduDeferredType VddmPropFr08_oCAN00_c8551891_Rx;
  Com_HandleRxPduDeferredType VddmPropFr09_oCAN00_04ff180f_Rx;
  Com_HandleRxPduDeferredType VddmPropFr10_oCAN00_0ccb1767_Rx;
  Com_HandleRxPduDeferredType VddmPropFr12_oCAN00_4eee101a_Rx;
  Com_HandleRxPduDeferredType VddmPropFr29_oCAN00_2a093089_Rx;
} Com_HandleRxPduDeferredStructSType;

/**   \brief  type to be used as symbolic data element access to Com_RxDefPduBuffer */
typedef struct Com_RxDefPduBufferStructSTag
{
  Com_RxDefPduBufferType BecmPropFr01_oCAN00_e2f0fff8_Rx[8];
  Com_RxDefPduBufferType EcmPropFr00_oCAN00_2afbaddb_Rx[8];
  Com_RxDefPduBufferType EcmPropFr07_oCAN00_203ea4c2_Rx[6];
  Com_RxDefPduBufferType EcmPropFr24_oCAN00_80478ba7_Rx[4];
  Com_RxDefPduBufferType IemEduPropFr01_oCAN00_97fdab75_Rx[3];
  Com_RxDefPduBufferType MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_985efe2d_Rx[8];
  Com_RxDefPduBufferType MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_8b12c95b_Rx[8];
  Com_RxDefPduBufferType MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_49f811f9_Rx[8];
  Com_RxDefPduBufferType MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_5ab4268f_Rx[8];
  Com_RxDefPduBufferType MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx[64];
  Com_RxDefPduBufferType MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx[64];
  Com_RxDefPduBufferType MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx[64];
  Com_RxDefPduBufferType MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx[64];
  Com_RxDefPduBufferType MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx[64];
  Com_RxDefPduBufferType MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx[64];
  Com_RxDefPduBufferType MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx[64];
  Com_RxDefPduBufferType MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx[64];
  Com_RxDefPduBufferType MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx[64];
  Com_RxDefPduBufferType MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx[64];
  Com_RxDefPduBufferType MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx[64];
  Com_RxDefPduBufferType MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx[64];
  Com_RxDefPduBufferType MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx[64];
  Com_RxDefPduBufferType MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx[64];
  Com_RxDefPduBufferType MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx[64];
  Com_RxDefPduBufferType MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx[64];
  Com_RxDefPduBufferType MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx[16];
  Com_RxDefPduBufferType MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx[16];
  Com_RxDefPduBufferType MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx[16];
  Com_RxDefPduBufferType MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx[16];
  Com_RxDefPduBufferType TcmPropFr04_oCAN00_6f4049d8_Rx[6];
  Com_RxDefPduBufferType VddmPropFr05_oCAN00_53500d40_Rx[6];
  Com_RxDefPduBufferType VddmPropFr08_oCAN00_c8551891_Rx[8];
  Com_RxDefPduBufferType VddmPropFr09_oCAN00_04ff180f_Rx[8];
  Com_RxDefPduBufferType VddmPropFr10_oCAN00_0ccb1767_Rx[8];
  Com_RxDefPduBufferType VddmPropFr12_oCAN00_4eee101a_Rx[4];
  Com_RxDefPduBufferType VddmPropFr29_oCAN00_2a093089_Rx[4];
} Com_RxDefPduBufferStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  ComPCUnionIndexAndSymbolTypes  Com Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access Com_HandleRxPduDeferred in an index and symbol based style. */
typedef union Com_HandleRxPduDeferredUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Com_HandleRxPduDeferredType raw[36];
  Com_HandleRxPduDeferredStructSType str;
} Com_HandleRxPduDeferredUType;

/**   \brief  type to access Com_RxDefPduBuffer in an index and symbol based style. */
typedef union Com_RxDefPduBufferUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Com_RxDefPduBufferType raw[1193];
  Com_RxDefPduBufferStructSType str;
} Com_RxDefPduBufferUType;

/** 
  \}
*/ 

/** 
  \defgroup  ComPCRootPointerTypes  Com Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to Com_ActivatableRxComIPdus */
typedef P2CONST(Com_ActivatableRxComIPdusType, TYPEDEF, COM_CONST) Com_ActivatableRxComIPdusPtrType;

/**   \brief  type used to point to Com_ActivatableTxComIPdus */
typedef P2CONST(Com_ActivatableTxComIPdusType, TYPEDEF, COM_CONST) Com_ActivatableTxComIPdusPtrType;

/**   \brief  type used to point to Com_ConstValueFloat32 */
typedef P2CONST(Com_ConstValueFloat32Type, TYPEDEF, COM_CONST) Com_ConstValueFloat32PtrType;

/**   \brief  type used to point to Com_ConstValueSInt16 */
typedef P2CONST(Com_ConstValueSInt16Type, TYPEDEF, COM_CONST) Com_ConstValueSInt16PtrType;

/**   \brief  type used to point to Com_ConstValueUInt16 */
typedef P2CONST(Com_ConstValueUInt16Type, TYPEDEF, COM_CONST) Com_ConstValueUInt16PtrType;

/**   \brief  type used to point to Com_ConstValueUInt8 */
typedef P2CONST(Com_ConstValueUInt8Type, TYPEDEF, COM_CONST) Com_ConstValueUInt8PtrType;

/**   \brief  type used to point to Com_CurrentTxMode */
typedef P2VAR(Com_CurrentTxModeType, TYPEDEF, COM_VAR_NOINIT) Com_CurrentTxModePtrType;

/**   \brief  type used to point to Com_CycleTimeCnt */
typedef P2VAR(Com_CycleTimeCntType, TYPEDEF, COM_VAR_NOINIT) Com_CycleTimeCntPtrType;

/**   \brief  type used to point to Com_CyclicSendRequest */
typedef P2VAR(Com_CyclicSendRequestType, TYPEDEF, COM_VAR_NOINIT) Com_CyclicSendRequestPtrType;

/**   \brief  type used to point to Com_DelayTimeCnt */
typedef P2VAR(Com_DelayTimeCntType, TYPEDEF, COM_VAR_NOINIT) Com_DelayTimeCntPtrType;

/**   \brief  type used to point to Com_GatewayProcessingISRLockCounter */
typedef P2VAR(Com_GatewayProcessingISRLockCounterType, TYPEDEF, COM_VAR_NOINIT) Com_GatewayProcessingISRLockCounterPtrType;

/**   \brief  type used to point to Com_HandleRxPduDeferred */
typedef P2VAR(Com_HandleRxPduDeferredType, TYPEDEF, COM_VAR_NOINIT) Com_HandleRxPduDeferredPtrType;

/**   \brief  type used to point to Com_Initialized */
typedef P2VAR(Com_InitializedType, TYPEDEF, COM_VAR_ZERO_INIT) Com_InitializedPtrType;

/**   \brief  type used to point to Com_PduGrpVector */
typedef P2CONST(Com_PduGrpVectorType, TYPEDEF, COM_CONST) Com_PduGrpVectorPtrType;

/**   \brief  type used to point to Com_RepCnt */
typedef P2VAR(Com_RepCntType, TYPEDEF, COM_VAR_NOINIT) Com_RepCntPtrType;

/**   \brief  type used to point to Com_RepCycleCnt */
typedef P2VAR(Com_RepCycleCntType, TYPEDEF, COM_VAR_NOINIT) Com_RepCycleCntPtrType;

/**   \brief  type used to point to Com_RxAccessInfo */
typedef P2CONST(Com_RxAccessInfoType, TYPEDEF, COM_CONST) Com_RxAccessInfoPtrType;

/**   \brief  type used to point to Com_RxAccessInfoInd */
typedef P2CONST(Com_RxAccessInfoIndType, TYPEDEF, COM_CONST) Com_RxAccessInfoIndPtrType;

/**   \brief  type used to point to Com_RxDeadlineMonitoringISRLockCounter */
typedef P2VAR(Com_RxDeadlineMonitoringISRLockCounterType, TYPEDEF, COM_VAR_NOINIT) Com_RxDeadlineMonitoringISRLockCounterPtrType;

/**   \brief  type used to point to Com_RxDefPduBuffer */
typedef P2VAR(Com_RxDefPduBufferType, TYPEDEF, COM_VAR_NOINIT) Com_RxDefPduBufferPtrType;

/**   \brief  type used to point to Com_RxDeferredProcessingISRLockCounter */
typedef P2VAR(Com_RxDeferredProcessingISRLockCounterType, TYPEDEF, COM_VAR_NOINIT) Com_RxDeferredProcessingISRLockCounterPtrType;

/**   \brief  type used to point to Com_RxIPduGroupISRLockCounter */
typedef P2VAR(Com_RxIPduGroupISRLockCounterType, TYPEDEF, COM_VAR_NOINIT) Com_RxIPduGroupISRLockCounterPtrType;

/**   \brief  type used to point to Com_RxPduGrpActive */
typedef P2VAR(Com_RxPduGrpActiveType, TYPEDEF, COM_VAR_NOINIT) Com_RxPduGrpActivePtrType;

/**   \brief  type used to point to Com_RxPduGrpInfo */
typedef P2CONST(Com_RxPduGrpInfoType, TYPEDEF, COM_CONST) Com_RxPduGrpInfoPtrType;

/**   \brief  type used to point to Com_RxPduInfo */
typedef P2CONST(Com_RxPduInfoType, TYPEDEF, COM_CONST) Com_RxPduInfoPtrType;

/**   \brief  type used to point to Com_RxSigBufferFloat32 */
typedef P2VAR(Com_RxSigBufferFloat32Type, TYPEDEF, COM_VAR_NOINIT) Com_RxSigBufferFloat32PtrType;

/**   \brief  type used to point to Com_RxSigBufferSInt16 */
typedef P2VAR(Com_RxSigBufferSInt16Type, TYPEDEF, COM_VAR_NOINIT) Com_RxSigBufferSInt16PtrType;

/**   \brief  type used to point to Com_RxSigBufferUInt16 */
typedef P2VAR(Com_RxSigBufferUInt16Type, TYPEDEF, COM_VAR_NOINIT) Com_RxSigBufferUInt16PtrType;

/**   \brief  type used to point to Com_RxSigBufferUInt8 */
typedef P2VAR(Com_RxSigBufferUInt8Type, TYPEDEF, COM_VAR_NOINIT) Com_RxSigBufferUInt8PtrType;

/**   \brief  type used to point to Com_RxSigInfo */
typedef P2CONST(Com_RxSigInfoType, TYPEDEF, COM_CONST) Com_RxSigInfoPtrType;

/**   \brief  type used to point to Com_SigGrpEventFlag */
typedef P2VAR(Com_SigGrpEventFlagType, TYPEDEF, COM_VAR_NOINIT) Com_SigGrpEventFlagPtrType;

/**   \brief  type used to point to Com_TransmitRequest */
typedef P2VAR(Com_TransmitRequestType, TYPEDEF, COM_VAR_NOINIT) Com_TransmitRequestPtrType;

/**   \brief  type used to point to Com_TxBuffer */
typedef P2VAR(Com_TxBufferType, TYPEDEF, COM_VAR_NOINIT) Com_TxBufferPtrType;

/**   \brief  type used to point to Com_TxCyclicProcessingISRLockCounter */
typedef P2VAR(Com_TxCyclicProcessingISRLockCounterType, TYPEDEF, COM_VAR_NOINIT) Com_TxCyclicProcessingISRLockCounterPtrType;

/**   \brief  type used to point to Com_TxDeadlineMonitoringISRLockCounter */
typedef P2VAR(Com_TxDeadlineMonitoringISRLockCounterType, TYPEDEF, COM_VAR_NOINIT) Com_TxDeadlineMonitoringISRLockCounterPtrType;

/**   \brief  type used to point to Com_TxIPduGroupISRLockCounter */
typedef P2VAR(Com_TxIPduGroupISRLockCounterType, TYPEDEF, COM_VAR_NOINIT) Com_TxIPduGroupISRLockCounterPtrType;

/**   \brief  type used to point to Com_TxModeFalse */
typedef P2CONST(Com_TxModeFalseType, TYPEDEF, COM_CONST) Com_TxModeFalsePtrType;

/**   \brief  type used to point to Com_TxModeInfo */
typedef P2CONST(Com_TxModeInfoType, TYPEDEF, COM_CONST) Com_TxModeInfoPtrType;

/**   \brief  type used to point to Com_TxModeTrue */
typedef P2CONST(Com_TxModeTrueType, TYPEDEF, COM_CONST) Com_TxModeTruePtrType;

/**   \brief  type used to point to Com_TxPduGrpActive */
typedef P2VAR(Com_TxPduGrpActiveType, TYPEDEF, COM_VAR_NOINIT) Com_TxPduGrpActivePtrType;

/**   \brief  type used to point to Com_TxPduGrpInfo */
typedef P2CONST(Com_TxPduGrpInfoType, TYPEDEF, COM_CONST) Com_TxPduGrpInfoPtrType;

/**   \brief  type used to point to Com_TxPduInfo */
typedef P2CONST(Com_TxPduInfoType, TYPEDEF, COM_CONST) Com_TxPduInfoPtrType;

/**   \brief  type used to point to Com_TxPduInitValue */
typedef P2CONST(Com_TxPduInitValueType, TYPEDEF, COM_CONST) Com_TxPduInitValuePtrType;

/**   \brief  type used to point to Com_TxProcessingISRLockCounter */
typedef P2VAR(Com_TxProcessingISRLockCounterType, TYPEDEF, COM_VAR_NOINIT) Com_TxProcessingISRLockCounterPtrType;

/**   \brief  type used to point to Com_TxSduLength */
typedef P2VAR(Com_TxSduLengthType, TYPEDEF, COM_VAR_NOINIT) Com_TxSduLengthPtrType;

/**   \brief  type used to point to Com_TxSigGrpInfo */
typedef P2CONST(Com_TxSigGrpInfoType, TYPEDEF, COM_CONST) Com_TxSigGrpInfoPtrType;

/**   \brief  type used to point to Com_TxSigGrpInfoInd */
typedef P2CONST(Com_TxSigGrpInfoIndType, TYPEDEF, COM_CONST) Com_TxSigGrpInfoIndPtrType;

/**   \brief  type used to point to Com_TxSigGrpMask */
typedef P2CONST(Com_TxSigGrpMaskType, TYPEDEF, COM_CONST) Com_TxSigGrpMaskPtrType;

/**   \brief  type used to point to Com_TxSigInfo */
typedef P2CONST(Com_TxSigInfoType, TYPEDEF, COM_CONST) Com_TxSigInfoPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  ComPCRootValueTypes  Com Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in Com_PCConfig */
typedef struct sCom_PCConfigType
{
  uint8 Com_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Com_PCConfigType;

typedef Com_PCConfigType Com_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  Com_ConstValueFloat32
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueFloat32
  \brief  Optimized array of commonly used values like initial or invalid values. (FLOAT32)
*/ 
#define COM_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_ConstValueFloat32Type, COM_CONST) Com_ConstValueFloat32[1];
#define COM_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueSInt16
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueSInt16
  \brief  Optimized array of commonly used values like initial or invalid values. (SINT16)
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_ConstValueSInt16Type, COM_CONST) Com_ConstValueSInt16[1];
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueUInt16
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt16
  \brief  Optimized array of commonly used values like initial or invalid values. (UINT16)
*/ 
#define COM_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_ConstValueUInt16Type, COM_CONST) Com_ConstValueUInt16[1];
#define COM_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueUInt8
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt8
  \brief  Optimized array of commonly used values like initial or invalid values. (BOOLEAN, UINT8)
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_ConstValueUInt8Type, COM_CONST) Com_ConstValueUInt8[1];
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_PduGrpVector
**********************************************************************************************************************/
/** 
  \var    Com_PduGrpVector
  \brief  Contains an I-PDU-Group vector for each I-PDU, mapping the I-PDU to the corresponding I-PDU-Groups.
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_PduGrpVectorType, COM_CONST) Com_PduGrpVector[11];
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxAccessInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxAccessInfo
  \brief  Contains all signal layout information necessary for signal access within an I-PDU.
  \details
  Element                   Description
  BufferIdx                 the index of the 0:1 relation pointing to Com_RxSigBufferUInt8,Com_RxSigBufferUInt16,Com_RxSigBufferUInt32,Com_RxSigBufferUInt64,Com_RxSigBufferZeroBit,Com_RxSigBufferSInt8,Com_RxSigBufferSInt16,Com_RxSigBufferSInt32,Com_RxSigBufferSInt64,Com_RxSigBufferFloat32,Com_RxSigBufferFloat64
  InitValueUsed             TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64,Com_ConstValueFloat32,Com_ConstValueFloat64
  SignExtRequired           TRUE if sign extension is required for signal / group signal reception.
  ApplType                  Application data type.
  BitLength                 Bit length of the signal or group signal.
  BitPosition               Little endian bit position of the signal or group signal within the I-PDU.
  BusAcc                    BUS access algorithm for signal or group signal packing / un-packing.
  ByteLength                Byte length of the signal or group signal.
  BytePosition              Little endian byte position of the signal or group signal within the I-PDU.
  InitValueIdx              the index of the 0:1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64,Com_ConstValueFloat32,Com_ConstValueFloat64
  RxPduInfoIdx              the index of the 1:1 relation pointing to Com_RxPduInfo
  StartByteInPduPosition    Start Byte position of the signal or group signal within the I-PDU.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_RxAccessInfoType, COM_CONST) Com_RxAccessInfo[370];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxAccessInfoInd
**********************************************************************************************************************/
/** 
  \var    Com_RxAccessInfoInd
  \brief  the indexes of the 1:1 sorted relation pointing to Com_RxAccessInfo
*/ 
#define COM_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_RxAccessInfoIndType, COM_CONST) Com_RxAccessInfoInd[370];
#define COM_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduGrpInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxPduGrpInfo
  \brief  Contains all I-PDU-Group relevant information for Rx I-PDUs.
  \details
  Element                 Description
  PduGrpVectorEndIdx      the end index of the 0:n relation pointing to Com_PduGrpVector
  PduGrpVectorStartIdx    the start index of the 0:n relation pointing to Com_PduGrpVector
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_RxPduGrpInfoType, COM_CONST) Com_RxPduGrpInfo[36];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxPduInfo
  \brief  Contains all relevant common information for Rx I-PDUs.
  \details
  Element                   Description
  RxDefPduBufferEndIdx      the end index of the 0:n relation pointing to Com_RxDefPduBuffer
  RxDefPduBufferStartIdx    the start index of the 0:n relation pointing to Com_RxDefPduBuffer
  RxSigInfoEndIdx           the end index of the 0:n relation pointing to Com_RxSigInfo
  RxSigInfoStartIdx         the start index of the 0:n relation pointing to Com_RxSigInfo
  RxAccessInfoIndUsed       TRUE, if the 0:n relation has 1 relation pointing to Com_RxAccessInfoInd
  Type                      Defines whether rx Pdu is a NORMAL or TP IPdu.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_RxPduInfoType, COM_CONST) Com_RxPduInfo[36];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxSigInfo
  \brief  Contains all relevant information for Rx signals.
  \details
  Element             Description
  RxAccessInfoIdx     the index of the 1:1 relation pointing to Com_RxAccessInfo
  SignalProcessing
  ValidDlc            Minimum length of PDU required to completely receive the signal or signal group.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_RxSigInfoType, COM_CONST) Com_RxSigInfo[370];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeFalse
**********************************************************************************************************************/
/** 
  \var    Com_TxModeFalse
  \brief  Contains all relevant information for transmission mode false.
  \details
  Element       Description
  Periodic      TRUE if transmission mode contains a cyclic part.
  TimePeriod    Cycle time factor.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_TxModeFalseType, COM_CONST) Com_TxModeFalse[2];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxModeInfo
  \brief  Contains all relevant information for transmission mode handling.
  \details
  Element          Description
  InitMode         Initial transmission mode selector of the Tx I-PDU.
  MinimumDelay     Minimum delay factor of the Tx I-PDU.
  TxModeTrueIdx    the index of the 1:1 relation pointing to Com_TxModeTrue
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_TxModeInfoType, COM_CONST) Com_TxModeInfo[19];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeTrue
**********************************************************************************************************************/
/** 
  \var    Com_TxModeTrue
  \brief  Contains all relevant information for transmission mode true.
  \details
  Element       Description
  Periodic      TRUE if transmission mode contains a cyclic part.
  TimePeriod    Cycle time factor.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_TxModeTrueType, COM_CONST) Com_TxModeTrue[2];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduGrpInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxPduGrpInfo
  \brief  Contains all I-PDU-Group relevant information for Tx I-PDUs.
  \details
  Element                 Description
  PduGrpVectorEndIdx      the end index of the 0:n relation pointing to Com_PduGrpVector
  PduGrpVectorStartIdx    the start index of the 0:n relation pointing to Com_PduGrpVector
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_TxPduGrpInfoType, COM_CONST) Com_TxPduGrpInfo[19];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxPduInfo
  \brief  Contains all relevant information for Tx I-PDUs.
  \details
  Element                    Description
  TxPduInitValueEndIdx       the end index of the 0:n relation pointing to Com_TxPduInitValue
  TxPduInitValueStartIdx     the start index of the 0:n relation pointing to Com_TxPduInitValue
  TxPduInitValueUsed         TRUE, if the 0:n relation has 1 relation pointing to Com_TxPduInitValue
  MetaDataLength             Length of MetaData.
  TxBufferLength             the number of relations pointing to Com_TxBuffer
  TxSigGrpInfoIndEndIdx      the end index of the 0:n relation pointing to Com_TxSigGrpInfoInd
  TxSigGrpInfoIndStartIdx    the start index of the 0:n relation pointing to Com_TxSigGrpInfoInd
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_TxPduInfoType, COM_CONST) Com_TxPduInfo[19];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduInitValue
**********************************************************************************************************************/
/** 
  \var    Com_TxPduInitValue
  \brief  Initial values used for Tx I-PDU buffer initialization.
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_TxPduInitValueType, COM_CONST) Com_TxPduInitValue[800];
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSigGrpInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxSigGrpInfo
  \brief  Contains all relevant information for Tx Signal Groups.
  \details
  Element                           Description
  TxBufferSigGrpInTxIPDUStartIdx    the start index of the 1:n relation pointing to Com_TxBuffer
  TxBufferStartIdx                  the start index of the 0:n relation pointing to Com_TxBuffer
  TxSigGrpMaskUsed                  TRUE, if the 0:n relation has 1 relation pointing to Com_TxSigGrpMask
  TransferProperty              
  TxBufferSigGrpInTxIPDULength      the number of relations pointing to Com_TxBuffer
  TxSigGrpMaskStartIdx              the start index of the 0:n relation pointing to Com_TxSigGrpMask
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_TxSigGrpInfoType, COM_CONST) Com_TxSigGrpInfo[2];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSigGrpMask
**********************************************************************************************************************/
/** 
  \var    Com_TxSigGrpMask
  \brief  Signal group mask needed to copy interlaced signal groups to the Tx PDU buffer.
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_TxSigGrpMaskType, COM_CONST) Com_TxSigGrpMask[115];
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSigInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxSigInfo
  \brief  Contains all relevant information for Tx signals and group signals.
  \details
  Element                   Description
  BitPosition               Little endian bit position of the signal or group signal within the I-PDU.
  TxBufferEndIdx            the end index of the 0:n relation pointing to Com_TxBuffer
  TxBufferStartIdx          the start index of the 0:n relation pointing to Com_TxBuffer
  ApplType                  Application data type.
  BitLength                 Bit length of the signal or group signal.
  BusAcc                    BUS access algorithm for signal or group signal packing / un-packing.
  ByteLength                Byte length of the signal or group signal.
  StartByteInPduPosition    Start Byte position of the signal or group signal within the I-PDU.
  TxPduInfoIdx              the index of the 1:1 relation pointing to Com_TxPduInfo
  TxSigGrpInfoIdx           the index of the 0:1 relation pointing to Com_TxSigGrpInfo
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Com_TxSigInfoType, COM_CONST) Com_TxSigInfo[242];
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_CurrentTxMode
**********************************************************************************************************************/
/** 
  \var    Com_CurrentTxMode
  \brief  Current transmission mode state of all Tx I-PDUs.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_CurrentTxModeType, COM_VAR_NOINIT) Com_CurrentTxMode[19];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_CycleTimeCnt
**********************************************************************************************************************/
/** 
  \var    Com_CycleTimeCnt
  \brief  Current counter value of cyclic transmission.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_CycleTimeCntType, COM_VAR_NOINIT) Com_CycleTimeCnt[19];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_CyclicSendRequest
**********************************************************************************************************************/
/** 
  \var    Com_CyclicSendRequest
  \brief  Cyclic send request flag used to indicate cyclic transmission mode for all Tx I-PDU.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_CyclicSendRequestType, COM_VAR_NOINIT) Com_CyclicSendRequest[19];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_DelayTimeCnt
**********************************************************************************************************************/
/** 
  \var    Com_DelayTimeCnt
  \brief  Current counter value of minimum delay counter.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_DelayTimeCntType, COM_VAR_NOINIT) Com_DelayTimeCnt[19];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_GatewayProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_GatewayProcessingISRLockCounterType, COM_VAR_NOINIT) Com_GatewayProcessingISRLockCounter;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_HandleRxPduDeferred
**********************************************************************************************************************/
/** 
  \var    Com_HandleRxPduDeferred
  \brief  Array indicating received Rx I-PDUs to be processed deferred within the next call of Com_MainfunctionRx().
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_HandleRxPduDeferredUType, COM_VAR_NOINIT) Com_HandleRxPduDeferred;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_Initialized
**********************************************************************************************************************/
/** 
  \var    Com_Initialized
  \brief  Initialization state of Com. TRUE, if Com_Init() has been called, else FALSE.
*/ 
#define COM_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_InitializedType, COM_VAR_ZERO_INIT) Com_Initialized;
#define COM_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RepCnt
**********************************************************************************************************************/
/** 
  \var    Com_RepCnt
  \brief  Current repetition counter value for replication of transmission requests plus one initial transmit.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_RepCntType, COM_VAR_NOINIT) Com_RepCnt[19];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RepCycleCnt
**********************************************************************************************************************/
/** 
  \var    Com_RepCycleCnt
  \brief  Current counter value of repetition period for replication of transmission requests.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_RepCycleCntType, COM_VAR_NOINIT) Com_RepCycleCnt[19];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDeadlineMonitoringISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_RxDeadlineMonitoringISRLockCounterType, COM_VAR_NOINIT) Com_RxDeadlineMonitoringISRLockCounter;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDefPduBuffer
**********************************************************************************************************************/
/** 
  \var    Com_RxDefPduBuffer
  \brief  Rx I-PDU buffer for deferred signal processing.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_RxDefPduBufferUType, COM_VAR_NOINIT) Com_RxDefPduBuffer;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDeferredProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_RxDeferredProcessingISRLockCounterType, COM_VAR_NOINIT) Com_RxDeferredProcessingISRLockCounter;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxIPduGroupISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_RxIPduGroupISRLockCounterType, COM_VAR_NOINIT) Com_RxIPduGroupISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduGrpActive
**********************************************************************************************************************/
/** 
  \var    Com_RxPduGrpActive
  \brief  Rx I-PDU based state (started/stopped) of the corresponding I-PDU-Group.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_RxPduGrpActiveType, COM_VAR_NOINIT) Com_RxPduGrpActive[36];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferFloat32
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferFloat32
  \brief  Rx Signal and Group Signal Buffer. (FLOAT32)
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_RxSigBufferFloat32Type, COM_VAR_NOINIT) Com_RxSigBufferFloat32[4];
#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferSInt16
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferSInt16
  \brief  Rx Signal and Group Signal Buffer. (SINT16)
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_RxSigBufferSInt16Type, COM_VAR_NOINIT) Com_RxSigBufferSInt16[12];
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt16
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt16
  \brief  Rx Signal and Group Signal Buffer. (UINT16)
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_RxSigBufferUInt16Type, COM_VAR_NOINIT) Com_RxSigBufferUInt16[262];
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt8
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt8
  \brief  Rx Signal and Group Signal Buffer. (BOOLEAN, UINT8)
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_RxSigBufferUInt8Type, COM_VAR_NOINIT) Com_RxSigBufferUInt8[92];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_SigGrpEventFlag
**********************************************************************************************************************/
/** 
  \var    Com_SigGrpEventFlag
  \brief  Flag is set if a group signal write access caused a triggered event.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_SigGrpEventFlagType, COM_VAR_NOINIT) Com_SigGrpEventFlag[2];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TransmitRequest
**********************************************************************************************************************/
/** 
  \var    Com_TransmitRequest
  \brief  Transmit request flag used for decoupled Tx I-PDU tranmission.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_TransmitRequestType, COM_VAR_NOINIT) Com_TransmitRequest[19];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxBuffer
**********************************************************************************************************************/
/** 
  \var    Com_TxBuffer
  \brief  Shared uint8 buffer for Tx I-PDUs and ComSignalGroup shadow buffer.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_TxBufferType, COM_VAR_NOINIT) Com_TxBuffer[916];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxCyclicProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_TxCyclicProcessingISRLockCounterType, COM_VAR_NOINIT) Com_TxCyclicProcessingISRLockCounter;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxDeadlineMonitoringISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_TxDeadlineMonitoringISRLockCounterType, COM_VAR_NOINIT) Com_TxDeadlineMonitoringISRLockCounter;  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxIPduGroupISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_TxIPduGroupISRLockCounterType, COM_VAR_NOINIT) Com_TxIPduGroupISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduGrpActive
**********************************************************************************************************************/
/** 
  \var    Com_TxPduGrpActive
  \brief  Tx I-PDU based state (started/stopped) of the corresponding I-PDU-Group.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_TxPduGrpActiveType, COM_VAR_NOINIT) Com_TxPduGrpActive[19];
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_TxProcessingISRLockCounterType, COM_VAR_NOINIT) Com_TxProcessingISRLockCounter;
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSduLength
**********************************************************************************************************************/
/** 
  \var    Com_TxSduLength
  \brief  This var Array contains the Com Ipdu Length.
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Com_TxSduLengthType, COM_VAR_NOINIT) Com_TxSduLength[19];
#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  RECEIVE MACRO API
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/* User Config File Start */

/* User Config File End */


#endif  /* COM_CFG_H */
/**********************************************************************************************************************
  END OF FILE: Com_Cfg.h
**********************************************************************************************************************/

