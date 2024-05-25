/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**
 *  \addtogroup Os_Hal_Context
 *  \trace      CREQ-1201
 *
 *  \{
 *  \file       Os_Hal_Context.h
 *  \brief      Context switching primitives.
 *  \details    Hardware information can be found in:
 *              "TriCore TC1.6P & TC1.6E - Core Architecture (Volume 1, V1.0 D10 2012-12)".
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/
                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_HAL_CONTEXT_H
# define OS_HAL_CONTEXT_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module dependencies */
# include "Os_Hal_ContextInt.h"
# include "Os_Hal_Context_Lcfg.h"

/* Os kernel module dependencies */

/* Os HAL dependencies */
# include "Os_Hal_Compiler.h"
# include "Os_Hal_Core.h"

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
 *  Os_Hal_ContextInit()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextInit,
(
  P2CONST(Os_Hal_ContextConfigType, AUTOMATIC, OS_CONST) Config,
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context
))
{
  uint32 SavedPCXIRaw;
  Os_Hal_IntGlobalStateType previousState;

  /* #10 Store the current interrupt global state and disable all interrupts. */
  Os_Hal_IntGetGlobalState(&previousState);                                                                             /* SBSW_OS_HAL_FC_LOCAL_VAR */

  /* #20 Save the current PCXI, since this function is called inside another context */
  SavedPCXIRaw = Os_Hal_Mfcr(OS_HAL_PCXI_OFFSET);

  /* #30 Create the reserved CSA */
  Os_Hal_ContextIntInitializeReserved(Config, Context, &previousState);                                                 /* SBSW_OS_HAL_FC_CALLER */

  /* #40 Create the actual CSA */
  Os_Hal_ContextIntInitialize(Config, Context, &previousState);                                                         /* SBSW_OS_HAL_FC_CALLER */

  /* #50 Disable all interrupts */
  Os_Hal_Disable();

  /* #60 Restore the old PCXI */
  Os_Hal_Mtcr(OS_HAL_PCXI_OFFSET, SavedPCXIRaw);
  Os_Hal_Isync();

  /* #70 Restore all interrupts to decrease the Cat 0 ISR lock time. */
  Os_Hal_IntSetGlobalState(&previousState);                                                                             /* SBSW_OS_HAL_FC_LOCAL_VAR */
}


/***********************************************************************************************************************
 *  Os_Hal_ContextReset()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextReset,
(
  P2CONST(Os_Hal_ContextConfigType, AUTOMATIC, OS_CONST) Config,
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context
))
{
  uint32 SavedPCXIRaw;
  Os_Hal_IntGlobalStateType previousState;

  /* #10 Store the current interrupt global state and disable all interrupts. */
  Os_Hal_IntGetGlobalState(&previousState);                                                                             /* SBSW_OS_HAL_FC_LOCAL_VAR */

  /* #20 Save the current PCXI, since this function is called inside another context */
  SavedPCXIRaw = Os_Hal_Mfcr(OS_HAL_PCXI_OFFSET);

  /* #30 Disable all interrupts */
  Os_Hal_Disable();

  /* #40 Set PCXI to the given context. */
  Os_Hal_Mtcr(OS_HAL_PCXI_OFFSET, Context->PreviousContextInfo);
  Os_Hal_Isync();

  /* #50 Restore all interrupts to decrease the Cat 0 ISR lock time. */
  Os_Hal_IntSetGlobalState(&previousState);                                                                             /* SBSW_OS_HAL_FC_LOCAL_VAR */

  /* #60 Cleanup the CSAs and re-initialize the context */
  Os_Hal_ContextIntCleanupCSAs(Context, &previousState);                                                                /* SBSW_OS_HAL_FC_CALLER */
  Os_Hal_ContextIntInitializeReserved(Config, Context, &previousState);                                                 /* SBSW_OS_HAL_FC_CALLER */
  Os_Hal_ContextIntInitialize(Config, Context, &previousState);                                                         /* SBSW_OS_HAL_FC_CALLER */

  /* #70 Disable all interrupts */
  Os_Hal_Disable();

  /* #80 Restore the old PCXI */
  Os_Hal_Mtcr(OS_HAL_PCXI_OFFSET, SavedPCXIRaw);
  Os_Hal_Isync();

  /* #90 Restore all interrupts to decrease the Cat 0 ISR lock time. */
  Os_Hal_IntSetGlobalState(&previousState);                                                                             /* SBSW_OS_HAL_FC_LOCAL_VAR */
}


/***********************************************************************************************************************
 *  Os_Hal_ContextSetParameter()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_ContextSetParameter,
(
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context,
  P2CONST(void, AUTOMATIC, OS_VAR_NOINIT) Parameter
))
{
  Context->A4 = (uint32)Parameter;                                                                                      /* SBSW_OS_HAL_PWA_CALLER */ /* PRQA S 0306, 0326 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule11.6_0326 */
}


/***********************************************************************************************************************
 *  Os_Hal_ContextSetStack()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_ContextSetStack,
(
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context,
  P2CONST(Os_Hal_ContextStackConfigType, AUTOMATIC, OS_VAR_NOINIT) Stack
))
{
  uint32 PCXIAddr;

  /* #10 Save the current PCXI, since this function is called inside another context */
  if(Os_MpIsEnabled() != 0u)
  {
    Context->MpuRegionForStackLow = Stack->StackRegionStart;                                                            /* SBSW_OS_HAL_PWA_CALLER */
    Context->MpuRegionForStackUpper = Stack->StackRegionEnd;                                                            /* SBSW_OS_HAL_PWA_CALLER */
  }

  PCXIAddr = Os_Hal_GetCsaAddress(Context->PreviousContextInfo);
  *(uint32*)(PCXIAddr + OS_HAL_CSA_SP_OFFSET) = Stack->StackRegionEnd;                                                  /* SBSW_OS_HAL_PWA_PCXI_CONTEXTSWITCH */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
}

/***********************************************************************************************************************
 *  Os_Hal_ContextGetStack()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_ContextGetStack,
(
  P2CONST(Os_Hal_ContextConfigType, AUTOMATIC, OS_CONST) Context,
  P2VAR(Os_Hal_ContextStackConfigType, AUTOMATIC, OS_VAR_NOINIT) Stack
))
{
   Stack->StackRegionStart = Context->StackStartAddr;                                                                   /* SBSW_OS_HAL_PWA_CALLER */
   Stack->StackRegionEnd = Context->StackEndAddr;                                                                       /* SBSW_OS_HAL_PWA_CALLER */
}

/***********************************************************************************************************************
 *  Os_Hal_ContextSetInterruptState()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_ContextSetInterruptState,
(
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context,
  P2CONST(Os_Hal_IntStateType, AUTOMATIC, OS_VAR_NOINIT) InterruptState
))
{
  Context->PreviousContextInfo &= (~OS_HAL_PCXI_PCPN_MASK) & (~OS_HAL_PCXI_PIE_MASK);                                   /* SBSW_OS_HAL_PWA_CALLER */
  Context->PreviousContextInfo |= (*InterruptState & OS_HAL_ICR_INT_MASK) << OS_HAL_PCXI_IE_TO_PIE;                     /* SBSW_OS_HAL_PWA_CALLER */
  Context->PreviousContextInfo |= (*InterruptState & OS_HAL_ICR_INT_LEVEL_MASK) << OS_HAL_PCXI_CCPN_TO_PCPN;            /* SBSW_OS_HAL_PWA_CALLER */
}


/***********************************************************************************************************************
 *  Os_Hal_ContextSetUserMsrBits()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219, 3673 */ /* MD_Os_Rule2.1_3219, MD_Os_Hal_Rule8.13_3673 */
Os_Hal_ContextSetUserMsrBits,
(
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context
))
{
  uint32 PCXIAddr;
  P2VAR(uint32, AUTOMATIC, OS_VAR_NOINIT) ctxPsw;

  PCXIAddr = Os_Hal_GetCsaAddress(Context->PreviousContextInfo);
  ctxPsw = (P2VAR(uint32, AUTOMATIC, OS_VAR_NOINIT))(PCXIAddr + OS_HAL_CSA_PSW_OFFSET);                                 /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */

  /* #10 Update PSW according to user settings. */
  *ctxPsw = ((*ctxPsw & (~OS_HAL_CORE_MSR_USER_BIT_MSK)) |                                                              /* SBSW_OS_HAL_PWA_PCXI_CONTEXTSWITCH */
            (Os_Hal_Mfcr(OS_HAL_PSW_OFFSET) & OS_HAL_CORE_MSR_USER_BIT_MSK));
}


/***********************************************************************************************************************
 *  Os_Hal_ContextFirstResume()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_ContextFirstResume,
(
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Next
))
{
  uint32 PCXIRaw;
  Os_Hal_IntGlobalStateType previousState;

  /* #10 Store the current interrupt global state and disable all interrupts. */
  Os_Hal_IntGetGlobalState(&previousState);                                                                             /* SBSW_OS_HAL_FC_LOCAL_VAR */

  for( PCXIRaw = Os_Hal_Mfcr(OS_HAL_PCXI_OFFSET);
       (PCXIRaw & OS_HAL_PCXI_PCX_MASK) != 0x0uL;
       PCXIRaw = Os_Hal_Mfcr(OS_HAL_PCXI_OFFSET))
  {
    /* #20 Disable all interrupts */
    Os_Hal_Disable();

    /* #30 Clean up CSA used by the startup code. */
    Os_Hal_Mtcr(OS_HAL_PCXI_OFFSET, PCXIRaw & ~OS_HAL_PCXI_UL_MASK);
    Os_Hal_Isync();
    Os_Hal_Rslcx();

    /* #40 Restore all interrupts to decrease the Cat 0 ISR lock time. */
    Os_Hal_IntSetGlobalState(&previousState);                                                                           /* SBSW_OS_HAL_FC_LOCAL_VAR */
  }

  /* #50 Restore the next thread context */
  Os_Hal_ContextIntRestore(Next);                                                                                       /* SBSW_OS_HAL_FC_CALLER */
}


/***********************************************************************************************************************
 *  Os_Hal_ContextResetAndResume()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_ContextResetAndResume,
(
  P2CONST(Os_Hal_ContextConfigType, AUTOMATIC, OS_CONST) CurrentConfig,
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Current,
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Next
))
{
  /* #10 Check if the current CSA chain is in the same state as just after initialization. */ 
  if(Os_Hal_Mfcr(OS_HAL_PCXI_OFFSET) == Current->RunningPCXI)
  {
    /* #20 Disable all interrupts. */
    Os_Hal_Disable();
    
    /* #30 Re-prepare the CSA content. */
    Os_Hal_ContextIntPrepareCSAContent(CurrentConfig, Current);                                                         /* SBSW_OS_HAL_FC_CALLER */
  }else
  /* #40 Otherwise we need to completely clean up the CSA chain. */
  {
    Os_Hal_IntGlobalStateType previousState;

    /* #50 Store the current interrupt global state and disable all interrupts. */
    Os_Hal_IntGetGlobalState(&previousState);                                                                           /* SBSW_OS_HAL_FC_LOCAL_VAR */
  
    /* #60 Cleanup the CSAs and re-initialize the context. */
    Os_Hal_ContextIntCleanupCSAs(Current, &previousState);                                                              /* SBSW_OS_HAL_FC_CALLER */
    Os_Hal_ContextIntInitializeReserved(CurrentConfig, Current, &previousState);                                        /* SBSW_OS_HAL_FC_CALLER */
    Os_Hal_ContextIntInitialize(CurrentConfig, Current, &previousState);                                                /* SBSW_OS_HAL_FC_CALLER */
  }

  /* #70 Restore the next PCXI and the link register. */
  Os_Hal_ContextIntRestore(Next);                                                                                       /* SBSW_OS_HAL_FC_CALLER */
}


/***********************************************************************************************************************
 *  Os_Hal_ContextAbort()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_Hal_ContextAbort,
(
  P2CONST(Os_Hal_ContextConfigType, AUTOMATIC, OS_CONST) Config,
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context
))
{
  uint32 SavedPCXIRaw;
  Os_Hal_IntGlobalStateType previousState;

  /* #10 Store the current interrupt global state and disable all interrupts. */
  Os_Hal_IntGetGlobalState(&previousState);                                                                             /* SBSW_OS_HAL_FC_LOCAL_VAR */

  /* #10 Save the current PCXI, since this function is called inside another context */
  SavedPCXIRaw = Os_Hal_Mfcr(OS_HAL_PCXI_OFFSET);

  /* #20 Disable all interrupts */
  Os_Hal_Disable();

  /* #30 Set PCXI to the given context. */
  Os_Hal_Mtcr(OS_HAL_PCXI_OFFSET, Context->PreviousContextInfo);
  Os_Hal_Isync();

  /* #40 Restore all interrupts to decrease the Cat 0 ISR lock time. */
  Os_Hal_IntSetGlobalState(&previousState);                                                                             /* SBSW_OS_HAL_FC_LOCAL_VAR */

  /* #50 Cleanup the CSAs and re-initialize the context only with the reserved CSA */
  Os_Hal_ContextIntCleanupCSAs(Context, &previousState);                                                                /* SBSW_OS_HAL_FC_CALLER */
  Os_Hal_ContextIntInitializeReserved(Config, Context, &previousState);                                                 /* SBSW_OS_HAL_FC_CALLER */

  /* #60 Overwrite the context pointer */
  Context->PreviousContextInfo = Os_Hal_Mfcr(OS_HAL_PCXI_OFFSET);                                                       /* SBSW_OS_HAL_PWA_CALLER */

  /* #70 Overwrite the link register to the address of Os_IsrEpilogue */
  Context->Lr = Config->ReturnAddress;                                                                                  /* SBSW_OS_HAL_PWA_CALLER */

  /* #80 Disable all interrupts */
  Os_Hal_Disable();

  /* #90 Restore the old PCXI */
  Os_Hal_Mtcr(OS_HAL_PCXI_OFFSET, SavedPCXIRaw);
  Os_Hal_Isync();

  /* #100 Restore all interrupts to decrease the Cat 0 ISR lock time. */
  Os_Hal_IntSetGlobalState(&previousState);                                                                             /* SBSW_OS_HAL_FC_LOCAL_VAR */
}


/***********************************************************************************************************************
 *  Os_Hal_ContextReturn()
 **********************************************************************************************************************/
 /*!
  *
  * Internal comment removed.
 *
 *
 *
 *
  */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_ContextReturn,
(
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Current,
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Next
))
{
  Os_Hal_IntGlobalStateType previousState;

  /* #10 Store the current interrupt global state and disable all interrupts. */
  Os_Hal_IntGetGlobalState(&previousState);                                                                             /* SBSW_OS_HAL_FC_LOCAL_VAR */

  /* #20 Clean up the used CSAs. */
  Os_Hal_ContextIntCleanupCSAs(Current, &previousState);                                                                /* SBSW_OS_HAL_FC_CALLER */

  /* #30 Restore the saved context. The interrupt state is assumed to be adjusted in core code */
  Os_Hal_ContextIntRestore(Next);                                                                                       /* SBSW_OS_HAL_FC_CALLER */
}


/***********************************************************************************************************************
 *  Os_Hal_ContextIsExceptionContextSupported()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_ContextIsExceptionContextSupported,
(
  void
))
{
  return !0u;                                                                                                           /* PRQA S 4404, 4558 */ /* MD_Os_C90BooleanCompatibility, MD_Os_Rule10.1_4558 */
}


/***********************************************************************************************************************
*  Os_Hal_ContextIntCleanupCSAs()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextIntCleanupCSAs,
(
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context,
  P2CONST(Os_Hal_IntGlobalStateType, AUTOMATIC, OS_CONST) PreviousGlobalIntState
))
{
  uint32 PCXIRaw;
  uint32 FirstPCXIAddr;

  /* #10 Disable all interrupts */
  Os_Hal_Disable();

  /* #20 Create a dummy CSA just for the case that the context list is empty */
  Os_Hal_Svlcx();
  Os_Hal_Dsync();

  /* #30 Cleanup the CSAs based on the stored InitPCXI */
  PCXIRaw = Os_Hal_Mfcr(OS_HAL_PCXI_OFFSET);
  FirstPCXIAddr = Os_Hal_GetCsaAddress(Context->InitPCXI);
  Os_Hal_Mtcr(OS_HAL_PCXI_OFFSET, *(uint32*)FirstPCXIAddr);                                                             /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  *(uint32*)FirstPCXIAddr = Os_Hal_Mfcr(OS_HAL_FCX_OFFSET);                                                             /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* SBSW_OS_HAL_PWA_FIRST_PCXI */
  Os_Hal_Mtcr(OS_HAL_FCX_OFFSET, PCXIRaw);
  Os_Hal_Isync();

  /* #40 Restore all interrupts to decrease the Cat 0 ISR lock time. */
  Os_Hal_IntSetGlobalState(PreviousGlobalIntState);                                                                     /* SBSW_OS_HAL_FC_LOCAL_VAR */
}


/***********************************************************************************************************************
*  Os_Hal_ContextIntPrepareCSAContent()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextIntPrepareCSAContent,
(
  P2CONST(Os_Hal_ContextConfigType, AUTOMATIC, OS_CONST) CurrentConfig,
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context
))
{
  uint32 PCXIRaw;
  uint32 PCXIAddr;

  /* #10 Adapt the created CSA entry based on the thread configuration */
  PCXIRaw = Os_Hal_Mfcr(OS_HAL_PCXI_OFFSET);
  PCXIAddr = Os_Hal_GetCsaAddress(PCXIRaw);

  /* #20 Initialize the program status word with call depth 1 due to the reserved CSA frame */
  *(uint32*)(PCXIAddr + OS_HAL_CSA_PSW_OFFSET) = CurrentConfig->ProgramStatus | OS_HAL_PSW_CDC_1;                       /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* SBSW_OS_HAL_PWA_PCXI */

  /* #30 Initialize the stack pointer */
  *(uint32*)(PCXIAddr + OS_HAL_CSA_SP_OFFSET) = CurrentConfig->StackEndAddr;                                            /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* SBSW_OS_HAL_PWA_PCXI */

  /* #40 Initialize the return address */
  *(uint32*)(PCXIAddr + OS_HAL_CSA_RA_UPPER_OFFSET) = CurrentConfig->ReturnAddress;                                     /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* SBSW_OS_HAL_PWA_PCXI */

  /* #50 Initialize the interrupt status */
  PCXIRaw &= (~OS_HAL_PCXI_PCPN_MASK) & (~OS_HAL_PCXI_PIE_MASK);
  PCXIRaw |= OS_HAL_PCXI_UL_MASK | CurrentConfig->IntStatus;
  Os_Hal_Mtcr(OS_HAL_PCXI_OFFSET, PCXIRaw);
  Os_Hal_Isync();

  /* #60 Initialize the MPU stack settings */
  if(Os_MpIsEnabled() != 0u)
  {
    Context->MpuRegionForStackLow = CurrentConfig->StackStartAddr;                                                      /* SBSW_OS_HAL_PWA_CALLER */
    Context->MpuRegionForStackUpper = CurrentConfig->StackEndAddr;                                                      /* SBSW_OS_HAL_PWA_CALLER */
  }

  /* #70 Initialize the runtime context variable */
  Context->PreviousContextInfo = Os_Hal_Mfcr(OS_HAL_PCXI_OFFSET);                                                       /* SBSW_OS_HAL_PWA_CALLER */
  Context->RunningPCXI = Os_Hal_Mfcr(OS_HAL_PCXI_OFFSET);                                                               /* SBSW_OS_HAL_PWA_CALLER */
  Context->Lr = CurrentConfig->Entry;                                                                                   /* SBSW_OS_HAL_PWA_CALLER */                                                                   /* SBSW_OS_HAL_FC_LOCAL_VAR */
}


/***********************************************************************************************************************
*  Os_Hal_ContextIntInitialize()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextIntInitialize,
(
  P2CONST(Os_Hal_ContextConfigType, AUTOMATIC, OS_CONST) CurrentConfig,
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context,
  P2CONST(Os_Hal_IntGlobalStateType, AUTOMATIC, OS_CONST) PreviousGlobalIntState
))
{
  /* #10 Disable all interrupts. */
  Os_Hal_Disable();

  /* #20 Create a new CSA entry (lower context), which is actually used as part of the initial context. */
  Os_Hal_Svlcx();
  Os_Hal_Dsync();

  /* #30 Adapt the created CSA entry based on the thread configuration. */
  Os_Hal_ContextIntPrepareCSAContent(CurrentConfig, Context);                                                           /* SBSW_OS_HAL_FC_CALLER */

  /* #40 Restore all interrupts to decrease the Cat 0 ISR lock time. */
  Os_Hal_IntSetGlobalState(PreviousGlobalIntState);                                                                     /* SBSW_OS_HAL_FC_LOCAL_VAR */
}


/***********************************************************************************************************************
*  Os_Hal_ContextIntInitializeReserved()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ContextIntInitializeReserved,
(
  P2CONST(Os_Hal_ContextConfigType, AUTOMATIC, OS_CONST) CurrentConfig,
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context,
  P2CONST(Os_Hal_IntGlobalStateType, AUTOMATIC, OS_CONST) PreviousGlobalIntState
))
{
  uint32 PCXIRaw;
  uint32 PCXIAddr;

  /* #10 Disable all interrupts */
  Os_Hal_Disable();

  /* #20 Create a new CSA entry (lower context), which is a reserved context and is only used when ISRs
   *     terminate or tasks terminate without calling TerminateTask */
  Os_Hal_Mtcr(OS_HAL_PCXI_OFFSET, 0x00000000uL);
  Os_Hal_Isync();
  Os_Hal_Svlcx();
  Os_Hal_Dsync();

  /* #30 Adapt the created CSA entry based on the thread configuration */
  PCXIRaw = Os_Hal_Mfcr(OS_HAL_PCXI_OFFSET);
  PCXIAddr = Os_Hal_GetCsaAddress(PCXIRaw);

  /* #40 Initialize the program status word */
  *(uint32*)(PCXIAddr + OS_HAL_CSA_PSW_OFFSET) = CurrentConfig->ProgramStatus;                                          /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* SBSW_OS_HAL_PWA_PCXI */

  /* #50 Initialize the stack pointer */
  *(uint32*)(PCXIAddr + OS_HAL_CSA_SP_OFFSET) = CurrentConfig->StackEndAddr;                                            /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* SBSW_OS_HAL_PWA_PCXI */

  /* #60 Initialize the return address. When this CSA is restored, the program should never return */
  *(uint32*)(PCXIAddr + OS_HAL_CSA_RA_UPPER_OFFSET) = 0x00000000uL;                                                     /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* SBSW_OS_HAL_PWA_PCXI */

  /* #70 Initialize the interrupt status */
  PCXIRaw &= (~OS_HAL_PCXI_PCPN_MASK) & (~OS_HAL_PCXI_PIE_MASK);
  PCXIRaw |= OS_HAL_PCXI_UL_MASK | CurrentConfig->IntStatus;
  Os_Hal_Mtcr(OS_HAL_PCXI_OFFSET, PCXIRaw);
  Os_Hal_Isync();

  /* #80 Initialize the runtime context variable */
  Context->InitPCXI = Os_Hal_Mfcr(OS_HAL_PCXI_OFFSET);                                                                  /* SBSW_OS_HAL_PWA_CALLER */

  /* #90 Restore all interrupts to decrease the Cat 0 ISR lock time. */
  Os_Hal_IntSetGlobalState(PreviousGlobalIntState);                                                                     /* SBSW_OS_HAL_FC_LOCAL_VAR */
}


/***********************************************************************************************************************
*  Os_Hal_ContextIntSave()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_ContextIntSave,
(
  P2VAR(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context
))
{
  /* #10 Save the PCXI register. */
  Context->PreviousContextInfo = Os_Hal_Mfcr(OS_HAL_PCXI_OFFSET);                                                       /* SBSW_OS_HAL_PWA_CALLER */

  /* #20 Save the link register (A11). */
  Context->Lr = Os_Hal_Mfa11();                                                                                         /* SBSW_OS_HAL_PWA_CALLER */

  /* #30 Save the stack region in MPU. */
  if(Os_MpIsEnabled() != 0u)
  {
    Context->MpuRegionForStackLow = Os_Hal_Mfcr(OS_HAL_COREMPU_DPR_LOW0);                                               /* SBSW_OS_HAL_PWA_CALLER */
    Context->MpuRegionForStackUpper = Os_Hal_Mfcr(OS_HAL_COREMPU_DPR_UPPER0);                                           /* SBSW_OS_HAL_PWA_CALLER */
  }
}


/***********************************************************************************************************************
*  Os_Hal_ContextIntRestore()
**********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_ContextIntRestore,
(
  P2CONST(Os_Hal_ContextType, AUTOMATIC, OS_VAR_NOINIT) Context
))
{
  /* #10 Disable all interrupts. */
  Os_Hal_Disable();

  /* #20 Restore the stack region in MPU. */
  if(Os_MpIsEnabled() != 0u)
  {
    Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER0, Context->MpuRegionForStackUpper);
    Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW0, Context->MpuRegionForStackLow);
  }

  /* #30 Restore the link register (A11). */
  Os_Hal_Mta11(Context->Lr);

  /* #40 Restore the parameter register (A4). */
  Os_Hal_Mta4(Context->A4);

  /* #50 Restore the PCXI register. */
  Os_Hal_Mtcr(OS_HAL_PCXI_OFFSET, Context->PreviousContextInfo);
  Os_Hal_Isync();

  /* #60 Go the next thread. */
  Os_Hal_ContextIntGo();
}

/***********************************************************************************************************************
 *  Os_Hal_ContextFetchInitialFpuContext()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219, 3673 */ /* MD_Os_Rule2.1_3219, MD_Os_Hal_Rule8.13_3673 */
Os_Hal_ContextFetchInitialFpuContext,
(
  P2VAR(Os_Hal_ContextFpuContextType, AUTOMATIC, OS_VAR_NOINIT) InitialContext
))
{
  /* #10 Stub implementation: fpu registers are already saved in the context switch mechanism. */
  OS_IGNORE_UNREF_PARAM(InitialContext);                                                                                /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
}


/***********************************************************************************************************************
 *  Os_Hal_ContextInitFpu()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_ContextInitFpu,
(
  P2CONST(Os_Hal_ContextFpuContextType, AUTOMATIC, OS_VAR_NOINIT) InitialContext
))
{
  /* Stub implementation: fpu registers are already saved in the context switch mechanism. */
  OS_IGNORE_UNREF_PARAM(InitialContext);                                                                                /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
}


/***********************************************************************************************************************
 *  Os_Hal_ContextInitFpuContext()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219, 3673 */ /* MD_Os_Rule2.1_3219, MD_Os_Hal_Rule8.13_3673 */
Os_Hal_ContextInitFpuContext,
(
  P2VAR(Os_Hal_ContextFpuContextType, AUTOMATIC, OS_VAR_NOINIT) Context,
  P2CONST(Os_Hal_ContextFpuContextType, AUTOMATIC, OS_VAR_NOINIT) InitialContext
))
{
  /* #10 Stub implementation: fpu registers are already saved in the context switch mechanism. */
  OS_IGNORE_UNREF_PARAM(Context);                                                                                       /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
  OS_IGNORE_UNREF_PARAM(InitialContext);                                                                                /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
}


/***********************************************************************************************************************
 *  Os_Hal_ContextStoreFpuContext()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219, 3673 */ /* MD_Os_Rule2.1_3219, MD_Os_Hal_Rule8.13_3673 */
Os_Hal_ContextStoreFpuContext,
(
  P2VAR(Os_Hal_ContextFpuContextType, AUTOMATIC, OS_VAR_NOINIT) Context
))
{
  /* #10 Stub implementation: fpu context is saved during the context switch. */
  OS_IGNORE_UNREF_PARAM(Context);                                                                                       /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
}

/***********************************************************************************************************************
 *  Os_Hal_ContextRestoreFpuContext()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_ContextRestoreFpuContext,
(
  P2CONST(Os_Hal_ContextFpuContextType, AUTOMATIC, OS_VAR_NOINIT) Context
))
{
  /* #10 Stub implementation: fpu context is restored during the context switch. */
  OS_IGNORE_UNREF_PARAM(Context);                                                                                       /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
}

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_HAL_CONTEXT_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Context.h
 **********************************************************************************************************************/

