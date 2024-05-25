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
 * \addtogroup Os_Counter Counter
 * \{
 *
 * \file
 * \brief       OS services for counters.
 * \details     --no details--
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_COUNTER_H
# define OS_COUNTER_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_CounterInt.h"
# include "Os_Counter_Cfg.h"
# include "Os_Counter_Lcfg.h"

/* Os kernel module dependencies */
# include "Os_Common.h"
# include "Os_PriorityQueue.h"
# include "OsInt.h"
# include "Os_Lcfg.h"
# include "Os_Error.h"
# include "Os_Application.h"
# include "Os_Core.h"
# include "Os_Timer.h"

/* Os hal dependencies */
# include "Os_Hal_Compiler.h"



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
 *  Os_CounterHasPfrtCounter()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_CounterHasPfrtCounter,     /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
(
  void
))                                                                                                                      /* COV_OS_HALPLATFORMPFRTUNSUPPORTED_XX */
{
  return (Os_StdReturnType)(OS_CFG_COUNTER_PFRT_USED == STD_ON);                                                        /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_CounterHasHrtCounter()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_CounterHasHrtCounter,      /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
(
  void
))                                                                                                                      /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
{
  return (Os_StdReturnType)(OS_CFG_COUNTER_HRT_USED == STD_ON);                                                         /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_CounterHasPitCounter()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_CounterHasPitCounter,      /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
(
  void
))                                                                                                                      /* COV_OS_HALPLATFORMPITUNSUPPORTED_XX */
{
  return (Os_StdReturnType)(OS_CFG_COUNTER_PIT_USED == STD_ON);                                                         /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_CounterCheckId()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_CounterCheckId,
(
  CounterType CounterId
))
{
  return Os_ErrExtendedCheck(Os_ErrIsValueLo((uint32)CounterId, (uint32)OS_COUNTERID_COUNT));
}


/***********************************************************************************************************************
 *  Os_CounterId2Counter()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE                                                                            /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_CounterId2Counter,
(
  CounterType CounterId
))
{
  Os_Assert(Os_ErrIsValueLo((uint32)CounterId, (uint32)OS_COUNTERID_COUNT));
  return OsCfg_CounterRefs[CounterId];
}


/***********************************************************************************************************************
 *  Os_CounterGetApplication()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_CounterGetApplication,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
))
{
  return Counter->OwnerApplication;
}


/***********************************************************************************************************************
 *  Os_CounterGetAccessingApplications()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_AppAccessMaskType, OS_CODE,                                             /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_CounterGetAccessingApplications,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
))
{
  return Counter->AccessingApplications;
}


/***********************************************************************************************************************
 *  Os_CounterGetCore()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE                                                                            /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_CounterGetCore,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
))
{
  return Counter->Core;
}


/***********************************************************************************************************************
 *  Os_CounterIsFutureValue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_CounterIsFutureValue,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter,
  Os_TickType Value,
  Os_TickType ReferenceValue
))
{
  /* #10 Fetch result from internal implementation. */
  return Os_CounterIsFutureValueInternal( Counter->Characteristics.MaxCountingValue,
                                          Counter->Characteristics.MaxDifferentialValue,
                                          Value,
                                          ReferenceValue);
}


/***********************************************************************************************************************
 *  Os_CounterIsFutureValueInternal()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_CounterIsFutureValueInternal,
(
  Os_TickType MaxCountingValue,
  Os_TickType MaxDifferentialValue,
  Os_TickType Value,
  Os_TickType ReferenceValue
))
{
  Os_StdReturnType result;
  Os_TickType diffTime;

  Os_Assert((Os_StdReturnType)(Value <= MaxCountingValue));                                                             /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
  Os_Assert((Os_StdReturnType)(ReferenceValue <= MaxCountingValue));                                                    /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */

  /* - #10 Subtract the higher from the lower value and return whether the difference is greater
   *       than the MaxDifferentialValue or not. */
  if(Value > ReferenceValue)
  {
    diffTime = Value - ReferenceValue;

    /* If the left job is less than or equal to MaxDifferentialValue ticks ahead of the right job,
     * then the left job lies in the future of the right job.
     */
    result = (Os_StdReturnType)(diffTime <= MaxDifferentialValue);                                                      /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
  }
  else if(Value < ReferenceValue)
  {
    diffTime = ReferenceValue - Value;

    /* If the right job is less than or equal to MaxDifferentialValue ticks ahead of the left job,
     * then the left job lies in the past of the right job.
     */
    result = (Os_StdReturnType)(diffTime > MaxDifferentialValue);                                                       /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
  }
  else
  {
    /* Value == ReferenceValue => Value is not in the future of ReferenceValue. */
    result = 0;
  }

  return result;
}


/***********************************************************************************************************************
 *  Os_CounterCheckValueLeMaxAllowed()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_CounterCheckValueLeMaxAllowed,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter,
  TickType Value
))
{
  return Os_ErrExtendedCheck((Os_StdReturnType)(Value <= Counter->Characteristics.MaxAllowedValue));                    /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_CounterCheckValueLeReducedMaxAllowed()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE,  Os_CounterCheckValueLeReducedMaxAllowed,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter,
  TickType Reduce,
  TickType Value
))
{
  Os_Assert((Os_StdReturnType)(Reduce <= Counter->Characteristics.MaxAllowedValue));                                    /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
  return Os_ErrExtendedCheck((Os_StdReturnType)(Value <= (Counter->Characteristics.MaxAllowedValue - Reduce)));         /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_CounterCheckValueGeMinCycleOrZero()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_CounterCheckValueGeMinCycleOrZero,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter,
  TickType Cycle
))
{
  return Os_ErrExtendedCheck((Os_StdReturnType)((Cycle >= Counter->Characteristics.MinCycle) || (Cycle == 0u)));        /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_CounterGetCharacteristics()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE P2CONST(Os_CounterCharacteristicsConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE,
Os_CounterGetCharacteristics,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
))
{
  return &(Counter->Characteristics);
}


/***********************************************************************************************************************
 *  Os_CounterGetMaxAllowedValue()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMTPUNSUPPORTED_XX */
OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,
Os_CounterGetMaxAllowedValue,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
))                                                                                                                      /* COV_OS_HALPLATFORMTPUNSUPPORTED_XX */
{
  return Counter->Characteristics.MaxAllowedValue;
}


/***********************************************************************************************************************
 *  Os_CounterGetMaxCountingValue()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMTPUNSUPPORTED_XX */
OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,
Os_CounterGetMaxCountingValue,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
))                                                                                                                      /* COV_OS_HALPLATFORMTPUNSUPPORTED_XX */
{
  return Counter->Characteristics.MaxCountingValue;
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_COUNTER_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_Counter.h
 **********************************************************************************************************************/
