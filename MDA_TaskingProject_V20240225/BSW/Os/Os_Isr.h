/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**
 * \addtogroup Os_Isr
 * \{
 *
 * \file
 * \brief       OS services concerning category 2 ISRs.
 * \details     --no details--
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_ISR_H
# define OS_ISR_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module dependencies */
# include "Os_IsrInt.h"
# include "Os_Isr_Lcfg.h"

/* Os kernel module dependencies */
# include "Os_Common.h"
# include "Os_Thread.h"
# include "Os_Lcfg.h"
# include "Os_AccessCheck.h"
# include "Os_XSignal.h"
# include "Os_Timer.h"

/* Os Hal dependencies */
# include "Os_Hal_Compiler.h"
# include "Os_Hal_Interrupt.h"


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_IsrThread2Isr()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE                                                                            /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_IsrThread2Isr,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  Os_Assert((Os_StdReturnType)(Os_ThreadIsIsr(Thread) != 0u));                                                          /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */ /* SBSW_OS_FC_PRECONDITION */
  return (P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST))Thread;                                                        /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  Os_IsrId2Isr()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE                                                                            /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_IsrId2Isr,
(
  ISRType IsrId
))
{
  Os_Assert(Os_ErrIsValueLo((uint32)IsrId, (uint32)OS_ISRID_COUNT));
  return OsCfg_IsrRefs[IsrId];                                                                                          /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  Os_IsrCheckId()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_IsrCheckId,
(
  ISRType IsrId
))
{
  return Os_ErrExtendedCheck(Os_ErrIsValueLo((uint32)IsrId, (uint32)OS_ISRID_COUNT));
}


/***********************************************************************************************************************
 *  Os_IsrHalIntLevel2CoreIntLevel()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_IsrHalIntLevel2CoreIntLevel,
(
  P2VAR(Os_IntLevelType, AUTOMATIC, AUTOMATIC) Level,
  P2CONST(Os_Hal_IntLevelType, AUTOMATIC, OS_CONST) HalLevel
))
{
  Level->State = *HalLevel;                                                                                             /* SBSW_OS_PWA_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_IsrLevelIsLe()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_IsrLevelIsLe,
(
  P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) Isr,
  P2CONST(Os_IntLevelType, AUTOMATIC, OS_CONST) Level
))
{
  return Os_Hal_IntIsrLevelIsLe(Isr->HwConfig, &(Level->State));                                                        /* SBSW_OS_ISR_HAL_INTISRLEVELISLE_001 */
}


/***********************************************************************************************************************
 *  Os_IsrGetThread()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE                                                                            /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_IsrGetThread,
(
  P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) Isr
))
{
  return &(Isr->Thread);
}


/***********************************************************************************************************************
 *  Os_IsrGetAccessRights()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE                                                                            /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
P2CONST(Os_AccessCheckConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_IsrGetAccessRights,
(
  P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) Isr
))
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) thread;

  thread = Os_IsrGetThread(Isr);                                                                                        /* SBSW_OS_FC_PRECONDITION */
  return Os_ThreadGetAccessRights(thread);                                                                              /* SBSW_OS_ISR_THREADGETACCESSRIGHTS_001 */
}


/***********************************************************************************************************************
 *  Os_IsrSuicide()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_NORETURN OS_ALWAYS_INLINE, Os_IsrSuicide, (void))
{
  Os_IsrEpilogue();
}


/***********************************************************************************************************************
 *  Os_IsrDisable()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IsrDisable,
(
  P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) Isr
))
{
  Os_Hal_IntDisableSource(Isr->HwConfig);                                                                               /* SBSW_OS_ISR_HAL_INTDISABLESOURCE_002 */
}


/***********************************************************************************************************************
 *  Os_IsrCat1Disable()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_IsrCat1Disable,
(
  P2CONST(Os_IsrCat1ConfigType, AUTOMATIC, OS_CONST) Isr
))
{
  Os_Hal_IntDisableSource(Isr->HwConfig);                                                                               /* SBSW_OS_ISR_HAL_INTDISABLESOURCE_002 */
}


/***********************************************************************************************************************
 *  Os_IsrInitialEnable()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_IsrInitialEnable,
(
  P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) Isr,
  boolean ClearPending
))
{
  /*#10 If ISR shall be enabled on initialization  */
  if(Isr->IsEnabledOnInitialization != FALSE)
  {
    /* #20 Clear the pending flag if requested. */
    Os_IsrClearPendingIfRequested(Isr, ClearPending);                                                                   /* SBSW_OS_FC_PRECONDITION */

    /* #30 Enable the ISR source. */
    Os_Hal_IntEnableSource(Isr->HwConfig);                                                                              /* SBSW_OS_FC_PRECONDITION */
  }/* if IsEnabledOnInitialization */
   
}


/***********************************************************************************************************************
 *  Os_IsrClearPendingIfRequested()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_IsrClearPendingIfRequested,
(
  P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) Isr,
  boolean ClearPending
))
{
  if(ClearPending == TRUE)                                                                                              /* COV_OS_HALPLATFORMCLEARPENDINGAVAILABILITY */
  {
    Os_Hal_IntClearPending(Isr->HwConfig);                                                                              /* SBSW_OS_FC_PRECONDITION */
  }  
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_ISR_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_Isr.h
 **********************************************************************************************************************/
