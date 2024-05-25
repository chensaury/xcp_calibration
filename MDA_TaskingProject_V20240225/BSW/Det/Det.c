/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2018 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Det.c
 *        \brief  Default Error Tracer source file
 *
 *      \details  Contains the implementation of static and API functions.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

#define DET_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Det.h"

#include "Compiler.h"
#if defined (_MICROSOFT_C_CANOE_) || defined (_MICROSOFT_C_VTT_) /* COV_DET_CANOE_VTT */
# define DET_COMP_ANSI_CANOE
#endif

#if defined (DET_COMP_ANSI_CANOE)
# include <stdio.h> /* PRQA S 5124 */  /* MD_DET_5124 */ /* simulation environment, no production code */
# include "os.h"
# include "CANoeApi.h"
# if (_MSC_VER >= 1400) /* COV_DET_CANOE_VTT */
#  include <string.h>
#  include <time.h> /* PRQA S 5127 */  /* MD_DET_5127 */ /* simulation environment, no production code */
# endif
#endif /* DET_COMP_ANSI_CANOE */

#if (DET_DEBUG_ENABLED == STD_ON)
# include "SchM_Det.h"
#endif

#if (DET_FORWARD_TO_DLT == STD_ON)
# include "Dlt.h"
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/**
 * Version check for source and header file consistency
 */
#if (DET_SW_MAJOR_VERSION != 11)
# error "Source and Header file are inconsistent!"
#endif

#if (DET_SW_MINOR_VERSION != 0)
# error "Source and Header file are inconsistent!"
#endif

#if (DET_SW_PATCH_VERSION != 0)
# error "Source and Header file are inconsistent!"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/


/********************** compiler abstraction *******************************/
#if !defined (DET_LOCAL) /* COV_DET_COMPATIBILITY */
# define DET_LOCAL  static   /* standard AutoSar 4.x define */
#endif

#if !defined (DET_LOCAL_INLINE) /* COV_DET_COMPATIBILITY */
# if defined (LOCAL_INLINE) /* COV_DET_COMPATIBILITY */
#  define DET_LOCAL_INLINE  LOCAL_INLINE
# else
#  define DET_LOCAL_INLINE  DET_LOCAL
# endif
#endif

#if (DET_ENABLED == STD_ON)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/

/* critical section macros \trace DSGN-Det22791 */
# define Det_EnterCritical() SchM_Enter_Det_DET_EXCLUSIVE_AREA_0()
# define Det_LeaveCritical() SchM_Exit_Det_DET_EXCLUSIVE_AREA_0()

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/

# define DET_START_SEC_VAR_INIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

DET_LOCAL volatile VAR(boolean, DET_VAR) detModuleInit = FALSE;

# define DET_STOP_SEC_VAR_INIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# define DET_START_SEC_VAR_NOINIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

# if (DET_REPORT_ERROR_RECURSIONLIMIT > 0)
DET_LOCAL volatile VAR(uint8, DET_VAR) detRecursionCounterReportError;                /* recursion limit counter \trace DSGN-Det22792 */
# endif

# if (DET_REPORT_RUNTIMEERROR_RECURSIONLIMIT > 0)
DET_LOCAL volatile VAR(uint8, DET_VAR) detRecursionCounterReportRuntimeError;         /* recursion limit counter \trace DSGN-Det22792 */
# endif

# if (DET_REPORT_TRANSIENTFAULT_RECURSIONLIMIT > 0)
DET_LOCAL volatile VAR(uint8, DET_VAR) detRecursionCounterReportTransientFault;       /* recursion limit counter \trace DSGN-Det22792 */
# endif

# define DET_STOP_SEC_VAR_NOINIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

# define DET_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */
 
# if (DET_DEBUG_ENABLED == STD_ON)

/* global variables, should be put in a watch window */
#  if (DET_GLOBALFILTERSIZE > 0)
volatile VAR(DetInfoType, DET_VAR) detGlobalFilter[DET_GLOBALFILTERSIZE]; /* ##### use this variable to configure global filters */ /* PRQA S 1504 */ /* MD_DET_1504 */
#  endif
#  if (DET_BREAKFILTERSIZE > 0)
volatile VAR(DetInfoType, DET_VAR) detBreakFilter[DET_BREAKFILTERSIZE];   /* ##### use this variable to configure break filters */ /* PRQA S 1504 */ /* MD_DET_1504 */
#  endif
#  if (DET_DLTFILTERSIZE > 0)
volatile VAR(DetInfoType, DET_VAR) detDltFilter[DET_DLTFILTERSIZE];     /* ##### use this variable to configure dlt filters */ /* PRQA S 1504 */ /* MD_DET_1504 */
#  endif
#  if (DET_LOGBUFFERSIZE > 0)
volatile VAR(DetInfoType, DET_VAR) detLogBuffer[DET_LOGBUFFERSIZE];       /* ##### use this variable to view log buffer */ /* PRQA S 1504 */ /* MD_DET_1504 */
#  endif
volatile VAR(DetStatusType, DET_VAR) detStatus;                           /* ##### use this variable to configure DET debug operation */ /* PRQA S 1504 */ /* MD_DET_1504 */

# endif /* DET_DEBUG_ENABLED */

# define DET_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define DET_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# if (DET_DEBUG_ENABLED == STD_ON)
/***********************************************************************************************************************
 *  Det_CheckFilterMatch()
 **********************************************************************************************************************/
/*! \brief      Check if a DET error matches filter conditions
 *  \details    A filter match is detected if all structure members of at least one filter and detInfo are identical 
 *              or the non-identical ones are don't care (0xFF).
 *  \param[in]  filter      pointer to an array of filters
 *  \param[in]  size        number of filters
 *  \param[in]  active      flag to indicate if filter is active
 *  \param[in]  detInfo     pointer to structure holding DET error for filtering
 *  \return     FALSE: no filter match, TRUE: filter match
 *  \pre        -
 *  \context    TASK|ISR2
 *  \reentrant  TRUE
 *  \synchronous TRUE
 *  \trace      DSGN-Det22783, DSGN-Det22785
 **********************************************************************************************************************/
#  if (DET_GLOBALFILTERSIZE > 0) || (DET_BREAKFILTERSIZE > 0)
DET_LOCAL_INLINE FUNC(boolean, DET_CODE) Det_CheckFilterMatch( volatile P2CONST( DetInfoType, AUTOMATIC, DET_VAR ) filter, uint8 size, boolean active, P2CONST( DetInfoType, AUTOMATIC, DET_VAR ) detInfo );
#  endif

/***********************************************************************************************************************
 *  Det_LogError()
 **********************************************************************************************************************/
/*! \brief      Store a DET error in the log buffer
 *  \details    It is further detected if an overrun occurs and if a forced break handler call is required. 
 *  \param[in]  active    flag to indicate if logging is active
 *  \param[in]  detInfo   pointer to structure holding DET error for filtering
 *  \return     FALSE: do not force break handler call, TRUE: force break handler call
 *  \pre        -
 *  \context    TASK|ISR2
 *  \reentrant  TRUE
 *  \synchronous TRUE
 *  \trace      DSGN-Det22792, DSGN-Det22784
 **********************************************************************************************************************/
#  if (DET_LOGBUFFERSIZE > 0)
DET_LOCAL_INLINE FUNC(boolean, DET_CODE) Det_LogError( boolean active, P2CONST( DetInfoType, AUTOMATIC, DET_VAR ) detInfo );
#  endif

# endif /* DET_DEBUG_ENABLED */

/***********************************************************************************************************************
 *  Det_CanoeOutput()
 **********************************************************************************************************************/
/*! \brief      Output DET error information in CANoe
 *  \details    Its behavior depends on the version of the simulation environment. 
 *  \param[in]  ModuleId      Module ID of calling module
 *  \param[in]  InstanceId    The identifier of the index based instance of a module
 *  \param[in]  ApiId         ID of API service in which error is detected
 *  \param[in]  ErrorId       ID of detected development error
 *  \pre        -
 *  \context    TASK|ISR2
 *  \reentrant  TRUE
 *  \synchronous TRUE
 **********************************************************************************************************************/
# if defined (DET_COMP_ANSI_CANOE)
DET_LOCAL_INLINE FUNC(void, DET_CODE) Det_CanoeOutput( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId );
# endif

/***********************************************************************************************************************
 *  Det_EndlessLoop()
 **********************************************************************************************************************/
/*! \brief      Enter endless loop
 *  \details    Used to stop further processing. 
 *  \pre        -
 *  \context    TASK|ISR2
 *  \reentrant  TRUE
 *  \synchronous TRUE
 **********************************************************************************************************************/
DET_LOCAL FUNC(void, DET_CODE) Det_EndlessLoop( void );

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

# if (DET_DEBUG_ENABLED == STD_ON)
/***********************************************************************************************************************
 *  Det_CheckFilterMatch()
 **********************************************************************************************************************/
/*! 
 *  Internal comment removed.
 *
 *
 *
 *
 **********************************************************************************************************************/
#  if (DET_GLOBALFILTERSIZE > 0) || (DET_BREAKFILTERSIZE > 0)
DET_LOCAL_INLINE FUNC(boolean, DET_CODE) Det_CheckFilterMatch( volatile P2CONST( DetInfoType, AUTOMATIC, DET_VAR ) filter, uint8 size, boolean active, P2CONST( DetInfoType, AUTOMATIC, DET_VAR ) detInfo )
{
  VAR(uint8_least, AUTOMATIC) i;
  VAR (boolean, AUTOMATIC) retval = FALSE; /* no filter match */
  /* #10 if filter is active */
  if(active == TRUE)
  {
    /* #20 linear search over all filters */
    for(i = 0; i < size; i++)
    {
      /* #30 compare each structure member if it is identical or if filter is set to don't care */
      if(
        ((filter[i].mModuleId == detInfo->mModuleId) || (filter[i].mModuleId == DET_DONTCARE_16)) &&
        ((filter[i].mInstanceId == detInfo->mInstanceId) || (filter[i].mInstanceId == DET_DONTCARE_8)) &&
        ((filter[i].mApiId == detInfo->mApiId) || (filter[i].mApiId == DET_DONTCARE_8)) &&
        ((filter[i].mErrorId == detInfo->mErrorId) || (filter[i].mErrorId == DET_DONTCARE_8))
        )
      {
        retval = TRUE;
        break;
      }
    }
  }
  return retval;
}
#  endif

/***********************************************************************************************************************
 *  Det_LogError()
 **********************************************************************************************************************/
/*! 
 *  Internal comment removed.
 *
 *
 *
 *
 *
 *
 **********************************************************************************************************************/
#  if (DET_LOGBUFFERSIZE > 0)
DET_LOCAL_INLINE FUNC(boolean, DET_CODE) Det_LogError( boolean active, P2CONST( DetInfoType, AUTOMATIC, DET_VAR ) detInfo )
{
  VAR (boolean, AUTOMATIC) forceBreakHandler = FALSE; /* do not force break handler call */

  /* #10 if logging is active */
  if(active == TRUE)
  {
      Det_EnterCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      detStatus.logIndex++;
      /* #20 if overrun of circular buffer occurs */
      if(detStatus.logIndex >= DET_LOGBUFFERSIZE)
      {
        detStatus.logIndex = 0;
        /* #30 if break on overrun is active set return value to force break handler call */
        if(detStatus.breakOnLogOverrun == TRUE)
        {
          forceBreakHandler = TRUE;
        }
      }
      /* #40 store DET error in log buffer */
      detLogBuffer[detStatus.logIndex].mModuleId = detInfo->mModuleId;       /* SBSW_DET_1 */
      detLogBuffer[detStatus.logIndex].mInstanceId = detInfo->mInstanceId;   /* SBSW_DET_1 */
      detLogBuffer[detStatus.logIndex].mApiId = detInfo->mApiId;             /* SBSW_DET_1 */
      detLogBuffer[detStatus.logIndex].mErrorId = detInfo->mErrorId;         /* SBSW_DET_1 */
      Det_LeaveCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }
  return forceBreakHandler;
}
#  endif

# endif /* DET_DEBUG_ENABLED */

/***********************************************************************************************************************
 *  Det_CanoeOutput()
 **********************************************************************************************************************/
/*! 
 *  Internal comment removed.
 *
 *
 *
 *
 **********************************************************************************************************************/
# if defined (DET_COMP_ANSI_CANOE)
DET_LOCAL_INLINE FUNC(void, DET_CODE) Det_CanoeOutput( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId )
{
#  if defined (_MICROSOFT_C_VTT_) /* COV_DET_CANOE_VTT */
  /* #10 if VIP is configured forward error to CANoe API */
  (void) CANoeAPI_DetReportError(ModuleId, InstanceId, ApiId, ErrorId);
#  else
  /* #20 else format error string and output it in the CANoe write window */
  {
    char str[255]; /* PRQA S 5013 */ /* MD_DET_5013 */

#   if (_MSC_VER >= 1400) /* COV_DET_CANOE_VTT */
    time_t timeVal;
    struct tm timeS;

    (void) time(&timeVal); /* PRQA S 5127 */  /* MD_DET_5127 */ /* simulation environment, no production code */ /* SBSW_DET_3 */
    (void) localtime_s(&timeS, &timeVal); /* PRQA S 5127 */  /* MD_DET_5127 */ /* simulation environment, no production code */ /* SBSW_DET_3 */

    (void) strftime(str, sizeof(str), "%H:%M:%S", &timeS); /* PRQA S 5127 */  /* MD_DET_5127 */ /* simulation environment, no production code */ /* SBSW_DET_3 */

    (void) sprintf_s(str + strlen(str), sizeof(str) - strlen(str),  /* PRQA S 0488 */  /* MD_DET_0488 */ /* simulation environment, no production code */ /* SBSW_DET_3 */
       " DET Error: ModuleId 0x%x, InstanceId 0x%x, ApiId 0x%x, ErrorId 0x%x", ModuleId, InstanceId, ApiId, ErrorId); 
#   else
    (void) sprintf(str, "DET Error: ModuleId 0x%x, InstanceId 0x%x, ApiId 0x%x, ErrorId 0x%x",  /* SBSW_DET_3 */
       ModuleId, InstanceId, ApiId, ErrorId);
#   endif
    CANoeAPI_WriteString((const char *)str);  /* PRQA S 5013 */ /* MD_DET_5013 */ /* SBSW_DET_3 */
  }
#  endif
}
# endif

/***********************************************************************************************************************
 *  Det_EndlessLoop()
 **********************************************************************************************************************/
/*! 
 *  Internal comment removed.
 *
 *
 *
 **********************************************************************************************************************/
DET_LOCAL FUNC(void, DET_CODE) Det_EndlessLoop( void )
{
# if (DET_DEBUG_ENABLED == STD_ON)
#  if ! defined (DET_REGRESSION_TEST) /* COV_TEST_CODE */
  while(detStatus.unlockBreak == FALSE) /* set this variable to 0 to unlock breakpoint */
#  endif
# else
#  if ! defined (DET_REGRESSION_TEST) /* COV_TEST_CODE */
  while(1) 
#  endif
# endif
  {
    ; /* ##### typical place for a breakpoint if extended debugging support is enabled */
# if defined (DET_COMP_ANSI_CANOE)
#  if (CANOEAPI_VERSION < 200) /* COV_DET_CANOE_VTT */
            break;
#  else
            CANoeAPI_ConsumeTicks(1);
#  endif
# endif
  }
# if (DET_DEBUG_ENABLED == STD_ON)
#  if ! defined (DET_REGRESSION_TEST) /* COV_TEST_CODE */
  detStatus.unlockBreak = FALSE; /* PRQA S 2880 */ /* MD_DET_2880 */
#  else
  detStatus.unlockBreak = TRUE; /* PRQA S 2880 */ /* MD_DET_2880 */
#  endif
# endif
}


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  Det_Init()
 **********************************************************************************************************************/
/*! 
 *  Internal comment removed.
 *
 *
 **********************************************************************************************************************/
FUNC(void, DET_CODE) Det_Init( CONSTP2CONST( Det_ConfigType, AUTOMATIC, DET_CONST ) ConfigPtr ) /* PRQA S 1505 */ /* MD_DET_1505 */
{
# if (DET_DEBUG_ENABLED == STD_ON)
#  if (DET_GLOBALFILTERSIZE > 0) || (DET_BREAKFILTERSIZE > 0) || (DET_LOGBUFFERSIZE > 0)
  VAR(uint8_least, AUTOMATIC) i;
#  endif
  detStatus.globalFilterActive = FALSE;
  detStatus.logActive = FALSE;
  detStatus.logIndex = 0;
  detStatus.breakOnLogOverrun = FALSE;
  detStatus.breakFilterActive = FALSE;
  detStatus.unlockBreak = FALSE;
#  if (DET_GLOBALFILTERSIZE > 0)
  for(i = 0; i < DET_GLOBALFILTERSIZE; i++)
  {
    detGlobalFilter[i].mModuleId = 0;   /* SBSW_DET_2 */
    detGlobalFilter[i].mInstanceId = 0; /* SBSW_DET_2 */
    detGlobalFilter[i].mApiId = 0;      /* SBSW_DET_2 */
    detGlobalFilter[i].mErrorId = 0;    /* SBSW_DET_2 */
  }
#  endif
#  if (DET_BREAKFILTERSIZE > 0)
  for(i = 0; i < DET_BREAKFILTERSIZE; i++)
  {
    detBreakFilter[i].mModuleId = 0;    /* SBSW_DET_2 */
    detBreakFilter[i].mInstanceId = 0;  /* SBSW_DET_2 */
    detBreakFilter[i].mApiId = 0;       /* SBSW_DET_2 */
    detBreakFilter[i].mErrorId = 0;     /* SBSW_DET_2 */
  }
#  endif
#  if (DET_DLTFILTERSIZE > 0)
  for(i = 0; i < DET_DLTFILTERSIZE; i++)
  {
    detDltFilter[i].mModuleId = 0;      /* SBSW_DET_2 */
    detDltFilter[i].mInstanceId = 0;    /* SBSW_DET_2 */
    detDltFilter[i].mApiId = 0;         /* SBSW_DET_2 */
    detDltFilter[i].mErrorId = 0;       /* SBSW_DET_2 */
  }
#  endif
#  if (DET_LOGBUFFERSIZE > 0)
  for(i = 0; i < DET_LOGBUFFERSIZE; i++)
  {
    detLogBuffer[i].mModuleId = 0;      /* SBSW_DET_2 */
    detLogBuffer[i].mInstanceId = 0;    /* SBSW_DET_2 */
    detLogBuffer[i].mApiId = 0;         /* SBSW_DET_2 */
    detLogBuffer[i].mErrorId = 0;       /* SBSW_DET_2 */
  }
#  endif
# endif

# if (DET_REPORT_ERROR_RECURSIONLIMIT > 0)
  detRecursionCounterReportError = 0;                /* reset recursion limit counter */
# endif

# if (DET_REPORT_RUNTIMEERROR_RECURSIONLIMIT > 0)
  detRecursionCounterReportRuntimeError = 0;         /* reset recursion limit counter */
# endif

# if (DET_REPORT_TRANSIENTFAULT_RECURSIONLIMIT > 0)
  detRecursionCounterReportTransientFault = 0;       /* reset recursion limit counter */
# endif

  DET_DUMMY_STATEMENT_CONST(ConfigPtr);  /* is never used */ /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  detModuleInit = TRUE;
}

/***********************************************************************************************************************
 *  Det_Start()
 **********************************************************************************************************************/
/*! 
 *  Internal comment removed.
 *
 *
 **********************************************************************************************************************/
FUNC(void, DET_CODE) Det_Start( void ) /* PRQA S 1505 */ /* MD_DET_1505 */
{
}

/***********************************************************************************************************************
 *  Det_InitMemory()
 **********************************************************************************************************************/
/*! 
 *  Internal comment removed.
 *
 *
 **********************************************************************************************************************/
FUNC(void, DET_CODE) Det_InitMemory(void) /* PRQA S 1505 */ /* MD_DET_1505 */
{
  detModuleInit = FALSE;
}

/***********************************************************************************************************************
 *  Det_ReportError()
 **********************************************************************************************************************/
/*! 
 *  Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 **********************************************************************************************************************/
FUNC(Std_ReturnType, DET_CODE) Det_ReportError( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId ) /* PRQA S 1505 */ /* MD_DET_1505 */ /*lint -e{438} */
{
# if (DET_ERROR_HOOK_ENABLED == STD_ON )
  VAR(Std_ReturnType, AUTOMATIC) calloutReturn = E_OK; /* PRQA S 2981 */ /* MD_DET_2981 */
  VAR(uint8_least, AUTOMATIC) index;
# endif
# if (DET_DEBUG_ENABLED == STD_ON)
#  if (DET_LOGBUFFERSIZE > 0)
  VAR(boolean, AUTOMATIC) forceBreakHandler;
#  endif
#  if (DET_GLOBALFILTERSIZE > 0) || (DET_BREAKFILTERSIZE > 0) || (DET_LOGBUFFERSIZE > 0) || ((DET_FORWARD_TO_DLT == STD_ON) && (DET_DLTFILTERSIZE > 0))
  VAR(DetInfoType, AUTOMATIC) detInfo;
  detInfo.mModuleId = ModuleId;
  detInfo.mInstanceId = InstanceId;
  detInfo.mApiId = ApiId;
  detInfo.mErrorId = ErrorId;
#  endif
# endif

# if defined (DET_COMP_ANSI_CANOE)
  /* #10 forward DET error to CANoe if configured */
  Det_CanoeOutput(ModuleId, InstanceId, ApiId, ErrorId);
# else
#  if (DET_FORWARD_TO_DLT == STD_OFF) && (DET_ERROR_HOOK_ENABLED == STD_OFF ) && ((DET_DEBUG_ENABLED == STD_OFF) || \
    ((DET_DEBUG_ENABLED == STD_ON) && (DET_GLOBALFILTERSIZE==0) && (DET_LOGBUFFERSIZE==0) && (DET_BREAKFILTERSIZE==0)))
  DET_DUMMY_STATEMENT(ModuleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  DET_DUMMY_STATEMENT(InstanceId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  DET_DUMMY_STATEMENT(ApiId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  DET_DUMMY_STATEMENT(ErrorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
#  endif
# endif

  /* #40 if DET is initialized: */
  if(detModuleInit == TRUE) /* in case of call to uninitialized DET return */
  {
    /* #45 increment nesting counter for recursion detection */
# if (DET_REPORT_ERROR_RECURSIONLIMIT > 0)
    Det_EnterCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    detRecursionCounterReportError++;
    Det_LeaveCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if(detRecursionCounterReportError > DET_REPORT_ERROR_RECURSIONLIMIT)
    {
      Det_EndlessLoop();
    }
    else
#endif
    {
      /* #50 call error hooks (if configured) */
# if (DET_ERROR_HOOK_ENABLED == STD_ON )
      for(index = 0; index < Det_GetSizeOfErrorHookTable(); index++)
      {
        calloutReturn = Det_GetErrorHookTable(index)(ModuleId, InstanceId, ApiId, ErrorId); /* SBSW_DET_4 */
      }
# endif

# if (DET_FORWARD_TO_DLT == STD_ON)
      /* #60 forward DET error to DLT module (if configured) unless filtered out by a DLT filter */
#  if (DET_DEBUG_ENABLED == STD_ON) && (DET_DLTFILTERSIZE > 0)
      if(Det_CheckFilterMatch(detDltFilter, DET_DLTFILTERSIZE, detStatus.dltFilterActive, &detInfo) == FALSE) /* SBSW_DET_6 */
#  endif
      {
        Dlt_DetForwardErrorTrace(ModuleId, InstanceId, ApiId, ErrorId);
      }
# endif


# if (DET_ERROR_HOOK_ENABLED == STD_ON )
      /* if last error hook (if configured) returned E_OK: */
      if(calloutReturn == E_OK)
# endif
      {

# if (DET_DEBUG_ENABLED == STD_ON)
        /* #70 check for global filter match (if configured), in case of no match continue */
#  if (DET_GLOBALFILTERSIZE > 0)
        if(Det_CheckFilterMatch(detGlobalFilter, DET_GLOBALFILTERSIZE, detStatus.globalFilterActive, &detInfo) == FALSE) /* SBSW_DET_6 */
#  endif
        {
#  if (DET_LOGBUFFERSIZE > 0)
          /* #80 store DET error in log buffer (if configured) */
          forceBreakHandler = Det_LogError(detStatus.logActive, &detInfo); /* SBSW_DET_6 */
#  endif
          /* #90 check for break filter match or forced break handler call (if configured), in case of no match continue */
#  if (DET_BREAKFILTERSIZE > 0)
          if((Det_CheckFilterMatch(detBreakFilter, DET_BREAKFILTERSIZE, detStatus.breakFilterActive, &detInfo) == FALSE) /* SBSW_DET_6 */
#   if (DET_LOGBUFFERSIZE > 0)
               || (forceBreakHandler == TRUE)
#   endif
               )
#  endif
          {
            /* #100 enter endless loop - in variant with debug support loop can be left by setting a flag */
            Det_EndlessLoop();
          }
        }
# else /* DET_DEBUG_ENABLED */
        /* in variant without debug support it is not possible to leave the endless loop on a real target */
        Det_EndlessLoop(); /*lint !e522 */
# endif /* DET_DEBUG_ENABLED */

      }
    }
    /* #110 decrement nesting counter for recursion detection */
# if (DET_REPORT_ERROR_RECURSIONLIMIT > 0)
    Det_EnterCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    detRecursionCounterReportError--;
    Det_LeaveCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
#endif
  }

  return E_OK;
} /* Det_ReportError */ /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */


/***********************************************************************************************************************
 *  Det_ReportRuntimeError()
 **********************************************************************************************************************/
/*! 
 *  Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 **********************************************************************************************************************/
FUNC(Std_ReturnType, DET_CODE) Det_ReportRuntimeError( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId ) /* PRQA S 1505 */ /* MD_DET_1505 */ /*lint -e{438} */
{
# if (DET_RUNTIME_ERROR_CALLOUT_ENABLED == STD_ON)
  VAR(Std_ReturnType, AUTOMATIC) calloutReturn = E_OK;  /* PRQA S 2981 */ /* MD_DET_2981 */
  VAR(uint8_least, AUTOMATIC) index;
# endif
# if (DET_DEBUG_ENABLED == STD_ON)
#  if (DET_LOGBUFFERSIZE > 0) || ((DET_FORWARD_TO_DLT == STD_ON) && (DET_DLTFILTERSIZE > 0))
  VAR(DetInfoType, AUTOMATIC) detInfo;
  detInfo.mModuleId = ModuleId;
  detInfo.mInstanceId = InstanceId;
  detInfo.mApiId = ApiId;
  detInfo.mErrorId = ErrorId;
#  endif
# endif

# if defined (DET_COMP_ANSI_CANOE)
  /* #10 forward DET error to CANoe if configured */
  Det_CanoeOutput(ModuleId, InstanceId, ApiId, ErrorId);
# else
#  if (DET_FORWARD_TO_DLT == STD_OFF) && (DET_RUNTIME_ERROR_CALLOUT_ENABLED == STD_OFF ) && ((DET_DEBUG_ENABLED == STD_OFF) || \
    ((DET_DEBUG_ENABLED == STD_ON) && (DET_LOGBUFFERSIZE==0) ))
  DET_DUMMY_STATEMENT(ModuleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  DET_DUMMY_STATEMENT(InstanceId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  DET_DUMMY_STATEMENT(ApiId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  DET_DUMMY_STATEMENT(ErrorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
#  endif
# endif

  /* #40 if DET is initialized: */
  if(detModuleInit == TRUE) /* in case of call to uninitialized DET return */
  {
    /* #45 increment nesting counter for recursion detection */
# if (DET_REPORT_RUNTIMEERROR_RECURSIONLIMIT > 0)
    Det_EnterCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    detRecursionCounterReportRuntimeError++;
    Det_LeaveCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if(detRecursionCounterReportRuntimeError > DET_REPORT_RUNTIMEERROR_RECURSIONLIMIT)
    {
      Det_EndlessLoop();
    }
    else
# endif
    {
      /* #50 call runtime error callouts (if configured) */
# if (DET_RUNTIME_ERROR_CALLOUT_ENABLED == STD_ON)
      for(index = 0; index < Det_GetSizeOfRuntimeErrorCalloutTable(); index++)
      {
        calloutReturn = Det_GetRuntimeErrorCalloutTable(index)(ModuleId, InstanceId, ApiId, ErrorId); /* SBSW_DET_4 */
      }
# endif

# if (DET_FORWARD_TO_DLT == STD_ON)
      /* #60 forward DET error to DLT module (if configured) unless filtered out by a DLT filter */
#  if (DET_DEBUG_ENABLED == STD_ON) && (DET_DLTFILTERSIZE > 0)
      if(Det_CheckFilterMatch(detDltFilter, DET_DLTFILTERSIZE, detStatus.dltFilterActive, &detInfo) == FALSE) /* SBSW_DET_6 */
#  endif
      {
        Dlt_DetForwardErrorTrace(ModuleId, InstanceId, ApiId, ErrorId);
      }
# endif

# if (DET_RUNTIME_ERROR_CALLOUT_ENABLED == STD_ON )
      /* #65 if last runtime error callout (if configured) returned E_OK: */
      if(calloutReturn == E_OK)
# endif
      {
# if (DET_DEBUG_ENABLED == STD_ON)
#  if (DET_LOGBUFFERSIZE > 0)
        /* #80 store DET error in log buffer (if configured) */
        (void) Det_LogError(detStatus.logActive, &detInfo); /* SBSW_DET_6 */
#  endif
# endif
      }
    }
    /* #110 decrement nesting counter for recursion detection */
# if (DET_REPORT_RUNTIMEERROR_RECURSIONLIMIT > 0)
    Det_EnterCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    detRecursionCounterReportRuntimeError--;
    Det_LeaveCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
#endif
  }

  return E_OK;
} /* Det_ReportRuntimeError */ /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */


/***********************************************************************************************************************
 *  Det_ReportTransientFault()
 **********************************************************************************************************************/
/*! 
 *  Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 **********************************************************************************************************************/
FUNC(Std_ReturnType, DET_CODE) Det_ReportTransientFault( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId ) /* PRQA S 1505 */ /* MD_DET_1505 */ /*lint -e{438} */
{
# if (DET_TRANSIENT_FAULT_CALLOUT_ENABLED == STD_ON)
  VAR(Std_ReturnType, AUTOMATIC) calloutReturn = E_OK;  /* PRQA S 2981 */ /* MD_DET_2981 */
  VAR(uint8_least, AUTOMATIC) index;
# endif
# if (DET_DEBUG_ENABLED == STD_ON)
#  if (DET_LOGBUFFERSIZE > 0) || ((DET_FORWARD_TO_DLT == STD_ON) && (DET_DLTFILTERSIZE > 0))
  VAR(DetInfoType, AUTOMATIC) detInfo;
  detInfo.mModuleId = ModuleId;
  detInfo.mInstanceId = InstanceId;
  detInfo.mApiId = ApiId;
  detInfo.mErrorId = ErrorId;
#  endif
# endif

# if defined (DET_COMP_ANSI_CANOE)
  /* #10 forward DET error to CANoe if configured */
  Det_CanoeOutput(ModuleId, InstanceId, ApiId, ErrorId);
# else
#  if (DET_FORWARD_TO_DLT == STD_OFF) && (DET_TRANSIENT_FAULT_CALLOUT_ENABLED == STD_OFF ) && ((DET_DEBUG_ENABLED == STD_OFF) || \
    ((DET_DEBUG_ENABLED == STD_ON) && (DET_LOGBUFFERSIZE==0) ))
  DET_DUMMY_STATEMENT(ModuleId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  DET_DUMMY_STATEMENT(InstanceId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  DET_DUMMY_STATEMENT(ApiId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  DET_DUMMY_STATEMENT(ErrorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
#  endif
# endif

  /* #40 if DET is initialized: */
  if(detModuleInit == TRUE) /* in case of call to uninitialized DET return */
  {
    /* #45 increment nesting counter for recursion detection */
# if (DET_REPORT_TRANSIENTFAULT_RECURSIONLIMIT > 0)
    Det_EnterCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    detRecursionCounterReportTransientFault++;
    Det_LeaveCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if(detRecursionCounterReportTransientFault > DET_REPORT_TRANSIENTFAULT_RECURSIONLIMIT)
    {
      Det_EndlessLoop();
    }
    else
# endif
    {
      /* call transient fault callouts (if configured) */
# if (DET_TRANSIENT_FAULT_CALLOUT_ENABLED == STD_ON)
      for(index = 0; index < Det_GetSizeOfTransientFaultCalloutTable(); index++)
      {
        calloutReturn = Det_GetTransientFaultCalloutTable(index)(ModuleId, InstanceId, ApiId, ErrorId); /* SBSW_DET_4 */
      }
# endif

# if (DET_FORWARD_TO_DLT == STD_ON)
      /* #60 forward DET error to DLT module (if configured) unless filtered out by a DLT filter */
#  if (DET_DEBUG_ENABLED == STD_ON) && (DET_DLTFILTERSIZE > 0)
      if(Det_CheckFilterMatch(detDltFilter, DET_DLTFILTERSIZE, detStatus.dltFilterActive, &detInfo) == FALSE) /* SBSW_DET_6 */
#  endif
      {
        Dlt_DetForwardErrorTrace(ModuleId, InstanceId, ApiId, ErrorId);
      }
# endif

# if (DET_DEBUG_ENABLED == STD_ON)
#  if (DET_LOGBUFFERSIZE > 0)
      /* #80 store DET error in log buffer (if configured) */
      (void) Det_LogError(detStatus.logActive, &detInfo); /* SBSW_DET_6 */
#  endif
# endif
    }
    /* #110 decrement nesting counter for recursion detection */
# if (DET_REPORT_TRANSIENTFAULT_RECURSIONLIMIT > 0)
    Det_EnterCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    detRecursionCounterReportTransientFault--;
    Det_LeaveCritical(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
#endif
  }

# if (DET_TRANSIENT_FAULT_CALLOUT_ENABLED == STD_ON)
  /* #120 use return value of last transient fault callout (if configured) */
  return calloutReturn;
# else
  return E_OK;
# endif
} /* Det_ReportRuntimeError */ /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */



/***********************************************************************************************************************
 *  Det_GetVersionInfo()
 **********************************************************************************************************************/
/*! 
 *  Internal comment removed.
 *
 *
 *
 **********************************************************************************************************************/
# if (DET_VERSION_INFO_API == STD_ON)
FUNC(void, DET_CODE) Det_GetVersionInfo( P2VAR( Std_VersionInfoType, AUTOMATIC, DET_APPL_DATA ) versioninfo ) /* PRQA S 1505 */ /* MD_DET_1505 */
{
  /* #10 if versioninfo is no NULL pointer */
  if(versioninfo != NULL_PTR)
  {
    /* #20 fill versions from defines into versioninfo structure */
    versioninfo->vendorID           = DET_VENDOR_ID;          /* SBSW_DET_7 */
    versioninfo->moduleID           = DET_MODULE_ID;          /* SBSW_DET_7 */
    versioninfo->sw_major_version   = DET_SW_MAJOR_VERSION;   /* SBSW_DET_7 */
    versioninfo->sw_minor_version   = DET_SW_MINOR_VERSION;   /* SBSW_DET_7 */
    versioninfo->sw_patch_version   = DET_SW_PATCH_VERSION;   /* SBSW_DET_7 */
  }
  else
  {
    (void) Det_ReportError(DET_MODULE_ID, DET_INSTANCE_ID, DET_SID_GETVERSIONINFO, DET_E_PARAM_POINTER);
  }
}
# endif

# define DET_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DET_ENABLED */

/* module specific MISRA deviations:
   MD_DET_5013:  MISRA2012 rule 4.6
     Reason:     Usage of "char" data type is necessary if error messages are output in the CANoe write window because the CANoe API requires this. 
     Risk:       Potentially unknown size and signedness of data type.
     Prevention: The affected code part is only active in a PC simulation environment and does not run on an embedded target. Therefore this deviation is not critical. No change planned.
   MD_DET_1504:  MISRA2012 rule 8.7
     Reason:     The global variables could be used by the application for testing and debugging purposes, therefore they have been made global. The MISRA test configuration does not reference these variables.
     Risk:       These variables could be used by the application for unrelated purposes.
     Prevention: This deviation is not critical, no change planned.
   MD_DET_2880:  MISRA2012 rule 2.1
     Reason:     No violation - tool issue in QAC (it is not detected that loop can be left due to intended debug concept via manipulation of control variable).
     Risk:       None.
     Prevention: No change planned.
   MD_DET_0488:  MISRA2012 rule 18.4
     Reason:     Pointer arithmetic is only used in the CANoe simulation environment for debug purposes, not included in production code.
     Risk:       None.
     Prevention: No change planned.
   MD_DET_5124:  MISRA2012 rule 21.6
     Reason:     Standard library functionality is only used in the CANoe simulation environment for debug purposes, not included in production code.
     Risk:       None.
     Prevention: No change planned.
   MD_DET_5127:  MISRA2012 rule 21.10
     Reason:     Standard library functionality is only used in the CANoe simulation environment for debug purposes, not included in production code.
     Risk:       None.
     Prevention: No change planned.
   MD_DET_2981:  MISRA2012 rule 2.2
     Reason:     Default initialization is required by SafeBSW API pattern.
     Risk:       None.
     Prevention: No change planned.
   MD_DET_1505:  MISRA2012 rule 8.7
     Reason:     MISRA analysis is performed without other modules using the API.
     Risk:       None.
     Prevention: No change planned.
*/

/* SBSW_JUSTIFICATION_BEGIN
   \ID SBSW_DET_1    
     \DESCRIPTION Array Write Access (P6 - Wrong Initialization and Usage of a Pointer due to Wrong Index)
      Update of log buffer in Det_LogError. Due to the code structure the calculated array index cannot exceed the array size. 
      Therefore this is not critical and no out of bounds array access can occur. The index is unconditionally reset to zero if is equal or greater than DET_LOGBUFFERSIZE.
     \COUNTERMEASURE \N The code structure already ensures that the index cannot exceed the size of the array.
   \ID SBSW_DET_2    
     \DESCRIPTION Array Write Access (P6 - Wrong Initialization and Usage of a Pointer due to Wrong Index)
      Initialization of global array in Det_Init. Both the array size and the loop is is controlled by generated #defines DET_*SIZE. 
      Therefore this is not critical and no out of bounds array access can occur.
     \COUNTERMEASURE \N The code structure already ensures that the index cannot exceed the size of the array.
   \ID SBSW_DET_3    
     \DESCRIPTION Function Call
      Calls to CANoe API or C stdlib with pointer parameters. 
      This code is only active in case of the CANoe emulation or vtt environment which is not used production code.
     \COUNTERMEASURE \N This code part is not active for embedded production targets.
   \ID SBSW_DET_4    
     \DESCRIPTION Function Pointer Call
      Iteration over generated function pointer tables using identifiers generated by the ComStackLib. 
     \COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib assures correct dimension of arrays and consistency of corresponding size definitions.
      The validity of the callout function names is covered by SMI-5.
   \ID SBSW_DET_6    
     \DESCRIPTION Function Call
      call of internal functions Det_CheckFilterMatch and Det_LogError (both functions cannot be called by the application or other modules)
      There could be a Null pointer dereferencing if these functions are called with invalid pointer parameters.
      However, at the three places in Det_ReportError where these functions are called the calls always uses valid pointers.
      So there is no need for an additional Null pointer check in these functions.
     \COUNTERMEASURE \N The code structure already ensures that the functions are always called with valid pointers.
   \ID SBSW_DET_7    
     \DESCRIPTION Pointer Write Access (P1 - Wrong Pointer Parameter)
      The function Det_GetVersionInfo writes to the object referenced by parameter versioninfo. The structure is provided by application code and passed to the DET. 
      The fault pattern P9 is already prevented by a NULL pointer check.
     \COUNTERMEASURE \N The caller ensures that the pointers passed to the parameter versioninfo is valid.
   \ID SBSW_DET_8    
     \DESCRIPTION Usage of debug features (generic aspect, not traceable to a specific ReviewHelper finding)
     \COUNTERMEASURE \S The DET should not be in production code. 
      If it is used the extended debug features should be switched off because they are only relevant if a debugger is attached. 
      All of the above listed array write accesses occur only if extended debug features are enabled. SMI-60
   \ID SBSW_DET_9    
     \DESCRIPTION Argument for completeness of analyzed code (generic aspect, not traceable to a specific ReviewHelper finding)
     \COUNTERMEASURE \N If all features of the DET are activated the whole code of the DET is active, there are no mutual exclusive code parts except for the AUTOSAR version which is fixed to 4.
      The additional debug code in case of C_COMP_ANSI_CANOE has not been considered because it is a simulation environment only and therefore this code will never run on an ECU.
SBSW_JUSTIFICATION_END */

/* START_COVERAGE_JUSTIFICATION
\ID COV_DET_COMPATIBILITY
   \ACCEPT TX
   \ACCEPT XF
   \REASON [COV_MSR_COMPATIBILITY]
\ID COV_DET_CANOE_VTT
  \ACCEPT TF xf tf
  \ACCEPT TX
  \ACCEPT XF
  \ACCEPT XX
  \REASON Code which is only relevant for the CANoeEmu and VTT simulation environments which are not used by the test suite.
\ID COV_TEST_CODE
  \ACCEPT TX
  \REASON Code is only deactivated during regression test to prevent endless loop.
END_COVERAGE_JUSTIFICATION */
