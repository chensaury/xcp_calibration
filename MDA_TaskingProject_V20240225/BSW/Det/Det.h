/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2018 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Det.h
 *        \brief  Header of Default Error Tracer
 *
 *      \details  Contains definitions, types, externals and prototype declarations.
 *      \trace    SPEC-2880976, SPEC-2880977
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Oliver Meili                  Om            Vector Informatik GmbH
 *  Joachim Kalmbach              Jk            Vector Informatik GmbH
 *  Hartmut Hoerner               HH            Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id      Description
 *  -------------------------------------------------------------------------------------------------------------------
 *   0.01.00  2005-08-18  Om      Creation
 *   2.00.00  2006-05-18  Om      Update for AUTOSAR Release 2.0
 *   3.00.00  2007-08-08  Jk      Update for AUTOSAR Release 2.1 
 *   3.01.00  2007-09-17  Jk      GetVersionInfo API added 
 *   3.02.00  2007-11-28  HH      Extended debug features added 
 *   4.00.00  2008-01-02  HH      Update for AUTOSAR Release 3.0 
 *                                compiler abstraction and memmap added
 *   4.01.00  2008-09-12  HH      ESCAN00023736: DET entry callout
 *                                ESCAN00029923: DET could be called recursively
 *   4.02.00  2008-12-09  HH      ESCAN00030591: compile error if extended version check is disabled
 *                                ESCAN00031617: Compiler warning about sprintf on CANoe emulation platform
 *   4.03.00  2008-12-09  HH      ESCAN00033897: case-sensitive issue: #include "VStdLib.h" instead of "#include "vstdlib.h" in Det.c
 *   4.03.01  2009-05-20  HH      ESCAN00034249: DET entry callout Appl_DetEntryCallout is only called once
 *                                ESCAN00034566: Compiler warnings because of unused parameters in Det_ReportError
 *   4.03.02  2010-07-27  HH      ESCAN00039898: Endless loop on CANoe platform
 *                                ESCAN00042300: support time-stamp for write window messages on CANoe platform
 *   5.00.00  2011-01-13  HH      ESCAN00048023: Update for AUTOSAR Release 4.0
 *   5.01.00  2011-10-27  HH      ESCAN00054556: AR3-1698 support CDK MISRA report
 *   5.02.00  2012-06-25  HH      ESCAN00060956: do not use v_cfg.h for Cfg5
 *   5.03.00  2013-01-18  HH      ESCAN00064266: AR4-220: Compiler error: Different errors due to unknown STATIC
 *   6.00.00  2013-08-22  HH      ESCAN00068394: AR4-292: Reporting of DET and DEM errors via DLT
 *   6.00.01  2013-12-17  HH      ESCAN00072683: version consistency checking is too strict
 *   6.01.00  2014-03-20  HH      ESCAN00074316: AR4-647: Adapt DET for VIP
 *   7.00.00  2014-12-11  HH      ESCAN00080181: FEAT-427: SafeBSW Step I [AR4-728]
 *                                ESCAN00077908: MISRA deviation: MISRA-C:2004 Rule 4060 metric deviation
 *                                ESCAN00079312: change return value from Appl_DetEntryCallout from uint8 to boolean
 *                                ESCAN00077108: ESCAN00077108: Add "consume ticks" for a more realistic behaviour in VTT
 *                                ESCAN00081763: FEAT-1275: SafeBSW Step 2
 *                                ESCAN00082803: [VTT] Det uses wrong Macro to detect VTT Usecase
 *   7.00.01  2015-11-24  HH      ESCAN00086457: Compiler warning: file does not end in newline
 *   7.01.00  2016-02-22  HH      ESCAN00087792: FEAT-1688: SafeBSW Step 4
 *  10.00.00  2016-12-24  HH      FEAT-1939:  Support AUTOSAR 4.3
 *  11.00.00  2018-08-20  HH      STORYC-4674: MISRA-C:2012 Compliance
*********************************************************************************************************************/

#ifndef DET_H
# define DET_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "Std_Types.h"
# include "Det_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**
 * Define vendor and module ID
 */
# define DET_VENDOR_ID         (30u) /* HIS Vendor ID for Vector               */
# define DET_MODULE_ID         (15u) /* Det Module ID according to BSW Modules */

/**
 * Define AUTOSAR specification version if not already externally specified (ESCAN00072683)
 */
# if !defined (DET_AR_MAJOR_VERSION) /* COV_DET_COMPATIBILITY */
#  define DET_AR_MAJOR_VERSION  (4u)
#  define DET_AR_MINOR_VERSION  (3u)
#  define DET_AR_PATCH_VERSION  (0u)
# endif

/**
 * Define AUTOSAR release version  if not already externally specified (ESCAN00072683)
 */
# if !defined (DET_AR_RELEASE_MAJOR_VERSION) /* COV_DET_COMPATIBILITY */
#  define DET_AR_RELEASE_MAJOR_VERSION  (4u)
#  define DET_AR_RELEASE_MINOR_VERSION  (3u)
#  define DET_AR_RELEASE_PATCH_VERSION  (0u)
#  define DET_AR_RELEASE_REVISION_VERSION  DET_AR_RELEASE_PATCH_VERSION
# endif

/**
 * Define version for header and source file consistency (decimal version of ALM implementation package)
 */
# define DET_SW_MAJOR_VERSION  (11u)
# define DET_SW_MINOR_VERSION  (0u)
# define DET_SW_PATCH_VERSION  (0u)

/**
 * Define error types
 */

/* Development Errors */
# define DET_E_PARAM_POINTER  (1u)

/* Runtime Errors - currently not used by the DET */
# define DET_E_CANNOT_REPORT  (1u)
# define DET_E_WRONG_MODULE   (2u)
# define DET_E_WRONG_INSTANCE (3u)
# define DET_E_WRONG_API      (4u)
# define DET_E_WRONG_ERROR    (5u)

/* Transient Faults - currently not used by the DET */
# define DET_E_UNAVAILABLE    (1u)

/**
 * Define API service IDs
 */
#define DET_SID_INIT                         (0x00u)
#define DET_SID_START                        (0x02u)
#define DET_SID_REPORTERROR                  (0x01u)
#define DET_SID_REPORTRUNTIMEERROR           (0x04u)
#define DET_SID_REPORTTRANSIENTFAULT         (0x05u)
#define DET_SID_GETVERSIONINFO               (0x03u)

#define DET_INSTANCE_ID                      (0x00u)

# if (DET_ENABLED == STD_ON)

#  if (DET_DEBUG_ENABLED == STD_ON)

/* don't care patterns for filters */
#define DET_DONTCARE_8  (0xFFu)
#define DET_DONTCARE_16 (0xFFFFu)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*! structure used to configure filters and store log data, using 0xFF for a filter item means don't care */
typedef struct
{
  uint16 mModuleId;
  uint8 mInstanceId;
  uint8 mApiId;
  uint8 mErrorId;
} DetInfoType;

/*! structure to control the operation of DET debug extension */
typedef struct
{
  boolean globalFilterActive; /* FALSE: global filters disabled, TRUE: global filters enabled */
  boolean logActive;          /* FALSE: logging disabled, TRUE: logging enabled */
  boolean breakOnLogOverrun;  /* FALSE: break on log buffer overrun disabled, TRUE: break on log buffer overrun enabled */
  boolean breakFilterActive;  /* FALSE: break filters disabled, TRUE: break filters enabled */
  boolean unlockBreak;        /* FALSE: break, TRUE: unlock break, can be used to unlock endless loop */
  boolean dltFilterActive;    /* FALSE: dlt filters disabled, TRUE: dlt filters enabled */
  uint8 logIndex;             /* do not modify: last index in array where data was logged, range: 0..DET_LOGBUFFERSIZE-1 */
} DetStatusType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

#   define DET_START_SEC_VAR_NOINIT_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*! global variables, should be put in a watch window */
#   if (DET_GLOBALFILTERSIZE > 0)
/*! ##### use this variable to configure global filters */
extern volatile VAR(DetInfoType, DET_VAR) detGlobalFilter[DET_GLOBALFILTERSIZE];
#   endif
#   if (DET_BREAKFILTERSIZE > 0)
/*! ##### use this variable to configure break filters */
extern volatile VAR(DetInfoType, DET_VAR) detBreakFilter[DET_BREAKFILTERSIZE];
#   endif
#   if (DET_DLTFILTERSIZE > 0)
/*! ##### use this variable to configure dlt filters */
extern volatile VAR(DetInfoType, DET_VAR) detDltFilter[DET_DLTFILTERSIZE];
#   endif
#   if (DET_LOGBUFFERSIZE > 0)
/*! ##### use this variable to view log buffer (circular buffer) */
extern volatile VAR(DetInfoType, DET_VAR) detLogBuffer[DET_LOGBUFFERSIZE];
#   endif
/*! ##### use this variable to configure DET debug operation */
extern volatile VAR(DetStatusType, DET_VAR) detStatus;                  
#   define DET_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#   include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

#  endif /* DET_DEBUG_ENABLED */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#  define DET_START_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  Det_Init()
 **********************************************************************************************************************/
/*! \brief       Initializes the DET
 *  \details     Global function as an interface from EcuM to DET for initialization
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        Shall be called during startup by EcuM in a safe context.
 *  \trace       SPEC-2880978, SPEC-2880979, SPEC-2880995, SPEC-2880996
 *  \trace       CREQ-1
 **********************************************************************************************************************/
FUNC(void, DET_CODE) Det_Init( CONSTP2CONST( Det_ConfigType, AUTOMATIC, DET_CONST ) ConfigPtr );

/***********************************************************************************************************************
 *  Det_Start()
 **********************************************************************************************************************/
/*! \brief       Starts the DET
 *  \details     Global function as an interface from EcuM to DET for start
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        This API has no functionality in this DET implementation. Therefore its call is optional.
 *  \trace       SPEC-2880980, SPEC-2880998
 *  \trace       CREQ-2
 **********************************************************************************************************************/
FUNC(void, DET_CODE) Det_Start( void );

/***********************************************************************************************************************
 *  Det_InitMemory()
 **********************************************************************************************************************/
/*! \brief       Initializes the DET
 *  \details     Global function as an interface from EcuM to DET for initialization
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        Shall be called during startup by EcuM in a safe context.
 *  \trace       CREQ-3
 **********************************************************************************************************************/
FUNC(void, DET_CODE) Det_InitMemory( void );

/***********************************************************************************************************************
 *  Det_ReportError()
 **********************************************************************************************************************/
/*! \brief       Development error reporting function
 *  \details     Global function for BSW-Modules to report errors to the DET
 *  \param[in]   ModuleId      Module ID of calling module
 *  \param[in]   InstanceId    The identifier of the index based instance of a module
 *  \param[in]   ApiId         ID of API service in which error is detected
 *  \param[in]   ErrorId       ID of detected development error
 *  \return      E_OK (always)
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \note        If filtering is active the default settings of the filter discard error reports of ModuleId 0 (zero).
 *  \trace       SPEC-2880982, SPEC-2880983, SPEC-2880984, SPEC-2880985, SPEC-2880986, SPEC-2880987, SPEC-2880988 
 *  \trace       SPEC-2880989, SPEC-2880991, SPEC-2880997, SPEC-2881003
 *  \trace       CREQ-4, DSGN-Det22798, DSGN-Det22785, DSGN-Det22786, DSGN-Det22801, DSGN-Det22811
 **********************************************************************************************************************/
FUNC(Std_ReturnType, DET_CODE) Det_ReportError( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId );

/***********************************************************************************************************************
 *  Det_ReportRuntimeError()
 **********************************************************************************************************************/
/*! \brief       Runtime error reporting function
 *  \details     Global function for BSW-Modules to report errors to the DET
 *  \param[in]   ModuleId      Module ID of calling module
 *  \param[in]   InstanceId    The identifier of the index based instance of a module
 *  \param[in]   ApiId         ID of API service in which error is detected
 *  \param[in]   ErrorId       ID of detected development error
 *  \return      E_OK (always)
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       SPEC-2880982, SPEC-2880983, SPEC-2880984, SPEC-2880987, SPEC-2880988, SPEC-2880993
 *  \trace       SPEC-2880999, SPEC-2881004
 *  \trace       CREQ-120271, DSGN-Det22801, DSGN-Det22784, DSGN-Det22786, DSGN-Det22811
 **********************************************************************************************************************/
FUNC(Std_ReturnType, DET_CODE) Det_ReportRuntimeError( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId );

/***********************************************************************************************************************
 *  Det_ReportTransientFault()
 **********************************************************************************************************************/
/*! \brief       Transient fault reporting function
 *  \details     Global function for BSW-Modules to report errors to the DET
 *  \param[in]   ModuleId      Module ID of calling module
 *  \param[in]   InstanceId    The identifier of the index based instance of a module
 *  \param[in]   ApiId         ID of API service in which error is detected
 *  \param[in]   ErrorId       ID of detected development error
 *  \return      E_OK (always) if no callouts are configured - return value of last callout if callouts are configured
 *  \pre         -
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       SPEC-2880982, SPEC-2880983, SPEC-2880984, SPEC-2880987, SPEC-2880988, SPEC-2880992
 *  \trace       SPEC-2881000, SPEC-2881005
 *  \trace       CREQ-120272, DSGN-Det22801, DSGN-Det22784, DSGN-Det22786, DSGN-Det22811
 **********************************************************************************************************************/
FUNC(Std_ReturnType, DET_CODE) Det_ReportTransientFault( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId );

/***********************************************************************************************************************
 *  Det_GetVersionInfo()
 **********************************************************************************************************************/
/*! \brief       Read the DET version information
 *  \details     Global function for BSW-Modules to get the Version of DET
 *  \param[out]  versioninfo    Version information of the DET
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      DET_VERSION_INFO_API
 *  \trace       SPEC-2880990, SPEC-2880994, SPEC-2881001
 *  \trace       CREQ-5
 **********************************************************************************************************************/
#  if (DET_VERSION_INFO_API == STD_ON)
FUNC(void, DET_CODE) Det_GetVersionInfo( P2VAR( Std_VersionInfoType, AUTOMATIC, DET_APPL_DATA ) versioninfo );
#  endif

#  define DET_STOP_SEC_CODE
#  include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

# endif /* DET_ENABLED */
#endif /* DET_H */

/*!
 * \exclusivearea DET_EXCLUSIVE_AREA_0 
 * Assures atomic storage of reported errors in the log buffer and consistency of recursion counters.
 * \protects detLogBuffer, detStatus.logIndex
 * \protects detRecursionCounterReportError, detRecursionCounterReportRuntimeError
 * \protects detRecursionCounterReportTransientFault
 * \usedin Det_ReportError, Det_ReportRuntimeError, Det_ReportTransientFault
 * \exclude Det_ReportError, Det_ReportRuntimeError, Det_ReportTransientFault
 * \length SHORT maximal 10 C-statements without loop are used this exclusive area.
 * \endexclusivearea
 */

/**********************************************************************************************************************
 *  END OF FILE: Det.h
 *********************************************************************************************************************/

