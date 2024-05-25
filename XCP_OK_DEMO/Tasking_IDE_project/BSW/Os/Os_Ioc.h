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
 * \addtogroup Os_Ioc
 * \{
 *
 * \file
 * \brief       Provides a set of default functions which are used by the generated ones.
 * \details     --no details--
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_IOC_H
# define OS_IOC_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_IocInt.h"
# include "Os_Ioc_Cfg.h"
# include "Os_Ioc_Lcfg.h"

/* Os kernel module dependencies */
# include "Os_Fifo.h"
# include "Os_Fifo08.h"
# include "Os_Fifo16.h"
# include "Os_Fifo32.h"
# include "Os_FifoRef.h"
# include "Os_Task.h"
# include "Os_Spinlock.h"
# include "Os_Hook.h"

/* Os hal dependencies */



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
 *  Os_IocInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_IocInit,
(
    P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc
))
{
  /* #10 If IOCs have been configured: */
  if(Os_IocIsEnabled() != 0u)
  {
    /* #20 Perform the initialization.  */
    FUNC(void, OS_CODE) Os_IocInitInternal
    (P2CONST(Os_IocConfigType, AUTOMATIC, OS_CONST) Ioc);

    Os_IocInitInternal(Ioc);                                                                                            /* SBSW_OS_FC_PRECONDITION */
  }
}


/***********************************************************************************************************************
 *  Os_IocIsEnabled()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_IocIsEnabled, (void))
{
  return (OS_CFG_IOC == STD_ON);                                                                                        /* PRQA S 4404 */ /*  MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_IocHasCallbacks
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_IocHasCallbacks,           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
(
  void
))
{
  /* #10 Return the general configuration switch. */
  return (OS_CFG_IOC_HAS_CALLBACKS == STD_ON);                                                                          /* PRQA S 4404 */ /*  MD_Os_C90BooleanCompatibility */
}

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_IOC_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_Ioc.h
 **********************************************************************************************************************/
