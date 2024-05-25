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
 *  \addtogroup Os_Hal_Entry
 *  \{
 *
 *  \file       Os_Hal_Entry.c
 *  \brief      This component handles hardware exceptions and interrupts.
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */

#define OS_HAL_ENTRY_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Entry.h"

/* Os module dependencies */
#include "Os_Cfg.h"

/* Os Hal dependencies */
#include "Os_Hal_Compiler.h"


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
 *  Os_Hal_Exception_Save_Context()
 **********************************************************************************************************************/
/*! \brief        Performs the HAL specific context saving before the core exception handling function is called.
 *  \details      This function shall be used to save context at memory protection entrance, it takes a snapshot of the
                  current context and stores it in a global variable.
 *  \param[in]    ExceptionSource    The exception class.
 *  \param[in]    Pcxi               The previous state.
 *  \context      EXCEPTION
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          Supervisor mode.
 *  \pre          Interrupts disabled.
 *  \pre          Concurrent access to given data shall be prevented.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_Exception_Save_Context,
(
  Os_ExceptionSourceIdType ExceptionSource,
  uint32 Pcxi
));

/***********************************************************************************************************************
 *  Os_Hal_Exception_Resume_Context()
 **********************************************************************************************************************/
/*! \brief       Performs the HAL specific context resume if the exception is ignored.
*  \details      This function shall be used to resume context at memory protection exit, it takes the value from the
                 global context variable and restores it in the hardware.
 *  \param[in]   Pcxi               The previous state.
 *  \context     EXCEPTION
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \pre         Supervisor mode.
 *  \pre         Interrupts disabled.
 *  \pre         Concurrent access to given data shall be prevented.
 *  \pre         The parameter Pcxi must be valid .
 **********************************************************************************************************************/
 OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_Exception_Resume_Context,
(
  uint32 Pcxi
));

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  Os_Hal_Exception_Save_Context()
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
Os_Hal_Exception_Save_Context,
(
  Os_ExceptionSourceIdType ExceptionSource,
  uint32 Pcxi
))
{
  Os_ExceptionContextRefType context;
  context = OsCfg_Hal_Context_ExceptionContextRef[Os_Hal_CoreGetId()];

  if(context == NULL_PTR)                                                                                               /* COV_OS_HALINVSTATE */
  {
    Os_ErrKernelPanic();
  }
  else
  {
    uint32 param;

    param = Pcxi;
    /* #10 Get Lower Context Save Area Address from Pcxi. */
    param = Os_Hal_GetCsaAddress(param);

    /* #20 Save all lower context registers. */
    context->AddressRegisters[2] = *(uint32*)(param + OS_HAL_CSA_A2_OFFSET);                                            /* SBSW_OS_HAL_AWA_EXCEPTION_CONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
    context->AddressRegisters[3] = *(uint32*)(param + OS_HAL_CSA_A3_OFFSET);                                            /* SBSW_OS_HAL_AWA_EXCEPTION_CONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
    context->DataRegisters[0]    = *(uint32*)(param + OS_HAL_CSA_D0_OFFSET);                                            /* SBSW_OS_HAL_AWA_EXCEPTION_CONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
    context->DataRegisters[1]    = *(uint32*)(param + OS_HAL_CSA_D1_OFFSET);                                            /* SBSW_OS_HAL_AWA_EXCEPTION_CONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
    context->DataRegisters[2]    = *(uint32*)(param + OS_HAL_CSA_D2_OFFSET);                                            /* SBSW_OS_HAL_AWA_EXCEPTION_CONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
    context->DataRegisters[3]    = *(uint32*)(param + OS_HAL_CSA_D3_OFFSET);                                            /* SBSW_OS_HAL_AWA_EXCEPTION_CONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
    context->AddressRegisters[4] = *(uint32*)(param + OS_HAL_CSA_A4_OFFSET);                                            /* SBSW_OS_HAL_AWA_EXCEPTION_CONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
    context->AddressRegisters[5] = *(uint32*)(param + OS_HAL_CSA_A5_OFFSET);                                            /* SBSW_OS_HAL_AWA_EXCEPTION_CONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
    context->AddressRegisters[6] = *(uint32*)(param + OS_HAL_CSA_A6_OFFSET);                                            /* SBSW_OS_HAL_AWA_EXCEPTION_CONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
    context->AddressRegisters[7] = *(uint32*)(param + OS_HAL_CSA_A7_OFFSET);                                            /* SBSW_OS_HAL_AWA_EXCEPTION_CONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
    context->DataRegisters[4]    = *(uint32*)(param + OS_HAL_CSA_D4_OFFSET);                                            /* SBSW_OS_HAL_AWA_EXCEPTION_CONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
    context->DataRegisters[5]    = *(uint32*)(param + OS_HAL_CSA_D5_OFFSET);                                            /* SBSW_OS_HAL_AWA_EXCEPTION_CONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
    context->DataRegisters[6]    = *(uint32*)(param + OS_HAL_CSA_D6_OFFSET);                                            /* SBSW_OS_HAL_AWA_EXCEPTION_CONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
    context->DataRegisters[7]    = *(uint32*)(param + OS_HAL_CSA_D7_OFFSET);                                            /* SBSW_OS_HAL_AWA_EXCEPTION_CONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
    context->Ra                  = *(uint32*)(param + OS_HAL_CSA_RA_LOWER_OFFSET);                                      /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_SAVE */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */

    /* #30 Get value of Pcxi from the lower context. */
    param = *(uint32*)(param + OS_HAL_CSA_PCXI_OFFSET);                                                                 /* PRQA S 0306, 2985 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule2.2_2985 */

    /* #40 Save the previous interrupt state. */
    context->Pie =  (param & OS_HAL_PCXI_PIE_MASK) >> OS_HAL_PCXI_PIE_BIT_POSITION;                                     /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_SAVE */
    context->Pcpn = (param & OS_HAL_PCXI_PCPN_MASK ) >> OS_HAL_PCXI_PCPN_BIT_POSITION;                                  /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_SAVE */

    /* #50 Get Upper Context Save Area Address from Pcxi. */
    param = Os_Hal_GetCsaAddress(param);

    /* #60 Save all upper context registers. */
    context->Psw                  = *(uint32*)(param + OS_HAL_CSA_PSW_OFFSET);                                          /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_SAVE */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
    context->AddressRegisters[10] = *(uint32*)(param + OS_HAL_CSA_SP_OFFSET);                                           /* SBSW_OS_HAL_AWA_EXCEPTION_CONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
    context->AddressRegisters[11] = *(uint32*)(param + OS_HAL_CSA_RA_UPPER_OFFSET);                                     /* SBSW_OS_HAL_AWA_EXCEPTION_CONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
    context->DataRegisters[8]     = *(uint32*)(param + OS_HAL_CSA_D8_OFFSET);                                           /* SBSW_OS_HAL_AWA_EXCEPTION_CONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
    context->DataRegisters[9]     = *(uint32*)(param + OS_HAL_CSA_D9_OFFSET);                                           /* SBSW_OS_HAL_AWA_EXCEPTION_CONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
    context->DataRegisters[10]    = *(uint32*)(param + OS_HAL_CSA_D10_OFFSET);                                          /* SBSW_OS_HAL_AWA_EXCEPTION_CONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
    context->DataRegisters[11]    = *(uint32*)(param + OS_HAL_CSA_D11_OFFSET);                                          /* SBSW_OS_HAL_AWA_EXCEPTION_CONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
    context->AddressRegisters[12] = *(uint32*)(param + OS_HAL_CSA_A12_OFFSET);                                          /* SBSW_OS_HAL_AWA_EXCEPTION_CONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
    context->AddressRegisters[13] = *(uint32*)(param + OS_HAL_CSA_A13_OFFSET);                                          /* SBSW_OS_HAL_AWA_EXCEPTION_CONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
    context->AddressRegisters[14] = *(uint32*)(param + OS_HAL_CSA_A14_OFFSET);                                          /* SBSW_OS_HAL_AWA_EXCEPTION_CONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
    context->AddressRegisters[15] = *(uint32*)(param + OS_HAL_CSA_A15_OFFSET);                                          /* SBSW_OS_HAL_AWA_EXCEPTION_CONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
    context->DataRegisters[12]    = *(uint32*)(param + OS_HAL_CSA_D12_OFFSET);                                          /* SBSW_OS_HAL_AWA_EXCEPTION_CONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
    context->DataRegisters[13]    = *(uint32*)(param + OS_HAL_CSA_D13_OFFSET);                                          /* SBSW_OS_HAL_AWA_EXCEPTION_CONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
    context->DataRegisters[14]    = *(uint32*)(param + OS_HAL_CSA_D14_OFFSET);                                          /* SBSW_OS_HAL_AWA_EXCEPTION_CONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
    context->DataRegisters[15]    = *(uint32*)(param + OS_HAL_CSA_D15_OFFSET);                                          /* SBSW_OS_HAL_AWA_EXCEPTION_CONTEXT */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */

    /* #70 Save the additional information. */
    context->ExceptionSource      = ExceptionSource;                                                                    /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_SAVE */
    context->AddressRegisters[0]  = Os_Hal_Mfa0();                                                                      /* SBSW_OS_HAL_AWA_EXCEPTION_CONTEXT */
    context->AddressRegisters[1]  = Os_Hal_Mfa1();                                                                      /* SBSW_OS_HAL_AWA_EXCEPTION_CONTEXT */
    context->AddressRegisters[8]  = Os_Hal_Mfa8();                                                                      /* SBSW_OS_HAL_AWA_EXCEPTION_CONTEXT */
    context->AddressRegisters[9]  = Os_Hal_Mfa9();                                                                      /* SBSW_OS_HAL_AWA_EXCEPTION_CONTEXT */
  }
}


/***********************************************************************************************************************
 *  Os_Hal_Exception_Resume_Context()
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
Os_Hal_Exception_Resume_Context,
(
  uint32 Pcxi
))
{
  Os_ExceptionContextRefType context;
  uint32 param;

  param = Pcxi;
  context = OsCfg_Hal_Context_ExceptionContextRef[Os_Hal_CoreGetId()];

  /* #10 Get CSA address of the lower context. */
  param = Os_Hal_GetCsaAddress(param);

  /* #20 Restore all lower context registers. */
  *(uint32*)(param + OS_HAL_CSA_A2_OFFSET)       = context->AddressRegisters[2];                                        /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_RESUME */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  *(uint32*)(param + OS_HAL_CSA_A3_OFFSET)       = context->AddressRegisters[3];                                        /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_RESUME */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  *(uint32*)(param + OS_HAL_CSA_D0_OFFSET)       = context->DataRegisters[0];                                           /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_RESUME */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  *(uint32*)(param + OS_HAL_CSA_D1_OFFSET)       = context->DataRegisters[1];                                           /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_RESUME */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  *(uint32*)(param + OS_HAL_CSA_D2_OFFSET)       = context->DataRegisters[2];                                           /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_RESUME */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  *(uint32*)(param + OS_HAL_CSA_D3_OFFSET)       = context->DataRegisters[3];                                           /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_RESUME */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  *(uint32*)(param + OS_HAL_CSA_A4_OFFSET)       = context->AddressRegisters[4];                                        /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_RESUME */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  *(uint32*)(param + OS_HAL_CSA_A5_OFFSET)       = context->AddressRegisters[5];                                        /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_RESUME */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  *(uint32*)(param + OS_HAL_CSA_A6_OFFSET)       = context->AddressRegisters[6];                                        /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_RESUME */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  *(uint32*)(param + OS_HAL_CSA_A7_OFFSET)       = context->AddressRegisters[7];                                        /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_RESUME */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  *(uint32*)(param + OS_HAL_CSA_D4_OFFSET)       = context->DataRegisters[4];                                           /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_RESUME */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  *(uint32*)(param + OS_HAL_CSA_D5_OFFSET)       = context->DataRegisters[5];                                           /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_RESUME */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  *(uint32*)(param + OS_HAL_CSA_D6_OFFSET)       = context->DataRegisters[6];                                           /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_RESUME */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  *(uint32*)(param + OS_HAL_CSA_D7_OFFSET)       = context->DataRegisters[7];                                           /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_RESUME */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  *(uint32*)(param + OS_HAL_CSA_RA_LOWER_OFFSET) = context->Ra;                                                         /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_RESUME */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */

  /* #30 Restore the previous interrupt state. */
  *(uint32*)(param + OS_HAL_CSA_PCXI_OFFSET) = (                                                                        /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_RESUME */ /* PRQA S 0306, 2985 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule2.2_2985 */
                                                 (*(uint32*)(param + OS_HAL_CSA_PCXI_OFFSET)) &                         /* PRQA S 0306, 2985 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule2.2_2985 */
                                                 (~OS_HAL_PCXI_PIE_MASK) &
                                                 (~OS_HAL_PCXI_PCPN_MASK)
                                               )
                                               |
                                               (context->Pie << OS_HAL_PCXI_PIE_BIT_POSITION)
                                               |
                                               (context->Pcpn << OS_HAL_PCXI_PCPN_BIT_POSITION);

  /* #40 Get value of PCXI from the lower context. */
  param = *(uint32*)(param + OS_HAL_CSA_PCXI_OFFSET);                                                                   /* PRQA S 0306, 2985 */ /* MD_Os_Hal_Rule11.4_0306, MD_Os_Hal_Rule2.2_2985 */

  /* #50 Get CSA address of the upper context. */
  param = Os_Hal_GetCsaAddress(param);

  /* #60 Restore all upper context registers. */
  *(uint32*)(param + OS_HAL_CSA_PSW_OFFSET)      = context->Psw;                                                        /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_RESUME */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  *(uint32*)(param + OS_HAL_CSA_SP_OFFSET)       = context->AddressRegisters[10];                                       /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_RESUME */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  *(uint32*)(param + OS_HAL_CSA_RA_UPPER_OFFSET) = context->AddressRegisters[11];                                       /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_RESUME */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  *(uint32*)(param + OS_HAL_CSA_D8_OFFSET)       = context->DataRegisters[8];                                           /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_RESUME */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  *(uint32*)(param + OS_HAL_CSA_D9_OFFSET)       = context->DataRegisters[9];                                           /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_RESUME */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  *(uint32*)(param + OS_HAL_CSA_D10_OFFSET)      = context->DataRegisters[10];                                          /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_RESUME */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  *(uint32*)(param + OS_HAL_CSA_D11_OFFSET)      = context->DataRegisters[11];                                          /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_RESUME */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  *(uint32*)(param + OS_HAL_CSA_A12_OFFSET)      = context->AddressRegisters[12] ;                                      /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_RESUME */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  *(uint32*)(param + OS_HAL_CSA_A13_OFFSET)      = context->AddressRegisters[13] ;                                      /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_RESUME */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  *(uint32*)(param + OS_HAL_CSA_A14_OFFSET)      = context->AddressRegisters[14] ;                                      /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_RESUME */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  *(uint32*)(param + OS_HAL_CSA_A15_OFFSET)      = context->AddressRegisters[15] ;                                      /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_RESUME */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  *(uint32*)(param + OS_HAL_CSA_D12_OFFSET)      = context->DataRegisters[12];                                          /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_RESUME */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  *(uint32*)(param + OS_HAL_CSA_D13_OFFSET)      = context->DataRegisters[13];                                          /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_RESUME */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  *(uint32*)(param + OS_HAL_CSA_D14_OFFSET)      = context->DataRegisters[14];                                          /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_RESUME */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */
  *(uint32*)(param + OS_HAL_CSA_D15_OFFSET)      = context->DataRegisters[15];                                          /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_RESUME */ /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */

  /* #70 Restore the additional information. */
  Os_Hal_Mtcr(OS_HAL_PSW_OFFSET, Os_Hal_Mfcr(OS_HAL_PSW_OFFSET) | OS_HAL_PSW_GW_MASK);
  Os_Hal_Isync();
  Os_Hal_Mta0(context->AddressRegisters[0]);
  Os_Hal_Mta1(context->AddressRegisters[1]);
  Os_Hal_Mta8(context->AddressRegisters[8]);
  Os_Hal_Mta9(context->AddressRegisters[9]);
}

/***********************************************************************************************************************
 *  Os_Hal_UnhandledExc()
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(void, OS_CODE, OS_HAL_NOINLINE,
Os_Hal_UnhandledExc,
(
  Os_ExceptionSourceIdType ExceptionSource,
  uint32 Pcxi,
  Os_AddressOfConstType ExceptionAddress,
   uint32 SavedMpuRegionForStackLow,
   uint32 SavedMpuRegionForStackUpper
))
{
  Os_ExceptionContextRefType ptrToExceptionContext;
  ptrToExceptionContext = OsCfg_Hal_Context_ExceptionContextRef[Os_Hal_CoreGetId()];

  if (ptrToExceptionContext == NULL_PTR)                                                                                              /* COV_OS_HALINVSTATE */
  {
    Os_ErrKernelPanic();
  }
  else
  {
    boolean privilegedMode = Os_Hal_CoreGetPrivilegedModeFromPcxi(Pcxi);

    /* #10 If memory protection is enabled: */
    if(Os_MpIsEnabled() != 0u)
    {
      /* #20 Store the current stack region in the context. */
      ptrToExceptionContext->MpuRegionForStackLow   = SavedMpuRegionForStackLow;                                                     /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_SAVE */
      ptrToExceptionContext->MpuRegionForStackUpper = SavedMpuRegionForStackUpper;                                                   /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_SAVE */
    }

    /* #30 Save the exception context before calling Os_UnhandledExc. */
    Os_Hal_Exception_Save_Context(ExceptionSource, Pcxi);                                                               /* SBSW_OS_HAL_FC_CALLER */

    /* #40 Call the handler in core. */
    /* Note that this core function may unlock category 0 ISRs. */
    Os_UnhandledExc(ExceptionSource, ExceptionAddress, privilegedMode);                                                 /* SBSW_OS_HAL_FC_CALLER */

    /* #50 Disable interrupt globally to lock category 0 ISRs. */
    Os_Hal_Disable();

    /* #60 Restore the exception context after returning from calling Os_UnhandledExc. */
    Os_Hal_Exception_Resume_Context(Pcxi);                                                                              /* SBSW_OS_HAL_FC_CALLER */

    /* #70 If memory protection is enabled: */
    if(Os_MpIsEnabled() != 0u)
    {
      /* #80 Restore the MPU stack region. */
      Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER0, ptrToExceptionContext->MpuRegionForStackUpper);
      Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW0, ptrToExceptionContext->MpuRegionForStackLow);
      Os_Hal_Isync();
    }
  }
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_Hal_MemFault()
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
OS_FUNC_ATTRIBUTE_DEFINITION(void, OS_CODE, OS_HAL_NOINLINE,
Os_Hal_MemFault,
(
  Os_ExceptionSourceIdType ExceptionSource,
  uint32 Pcxi,
  Os_AddressOfConstType ExceptionAddress,
  uint32 SavedMpuRegionForStackLow,
  uint32 SavedMpuRegionForStackUpper
))
{
  Os_ExceptionContextRefType ptrToExceptionContext;
  ptrToExceptionContext = OsCfg_Hal_Context_ExceptionContextRef[Os_Hal_CoreGetId()];

  if (ptrToExceptionContext == NULL_PTR)                                                                                /* COV_OS_HALINVSTATE */
  {
    Os_ErrKernelPanic();
  }
  else
  {
    boolean privilegedMode = Os_Hal_CoreGetPrivilegedModeFromPcxi(Pcxi);
    /* #10 Store the current stack region in the context. */
    ptrToExceptionContext->MpuRegionForStackLow = SavedMpuRegionForStackLow;                                            /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_SAVE */
    ptrToExceptionContext->MpuRegionForStackUpper = SavedMpuRegionForStackUpper;                                        /* SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_SAVE */

    /* #20 Save the exception context before handling the memory fault. */
    Os_Hal_Exception_Save_Context(ExceptionSource, Pcxi);                                                                 /* SBSW_OS_HAL_FC_CALLER */

    /* #30 Call the handler in core. */
    /* Note that this core function may unlock category 0 ISRs. */
    Os_MemFault(ExceptionAddress, privilegedMode);                                                                        /* SBSW_OS_HAL_FC_CALLER */

    /* #40 Disable interrupt globally to lock category 0 ISRs. */
    Os_Hal_Disable();

    /* #50 Restore the exception context after returning from calling Os_MemFault. */
    Os_Hal_Exception_Resume_Context(Pcxi);                                                                                /* SBSW_OS_HAL_FC_CALLER */

    /* #60 Restore the stack regions in the MPU. */
    /* Note that the stack pointer will be automatically restored after this function returns. */
    Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER0, ptrToExceptionContext->MpuRegionForStackUpper);
    Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW0, ptrToExceptionContext->MpuRegionForStackLow);
    Os_Hal_Isync();
  }
}

/***********************************************************************************************************************
 *  Os_Hal_SysCall()
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
OS_FUNC_ATTRIBUTE_DEFINITION(uint32, OS_CODE, OS_HAL_NOINLINE,
Os_Hal_SysCall,
(
  uint32 Tin,
  uint32 Pcxi,
  P2VAR(Os_TrapPacketType, AUTOMATIC, OS_VAR_NOINIT) Packet,
  Os_AddressOfConstType Addr
))
{
  uint32 returnPcxi;

  returnPcxi = Pcxi;

  /* #10 Check that the system call identification number is valid */
  if(Tin == (uint32)OS_HAL_SYSCALL_TRAP_ID)
  {
    Os_Hal_IntTrapStateType callerState;

    /* #20 Prepare the interrupt state for Os_TrapHandler */
    callerState = (Pcxi & OS_HAL_PCXI_PCPN_MASK) >> OS_HAL_PCXI_CCPN_TO_PCPN;
    callerState |= (Pcxi & OS_HAL_PCXI_PIE_MASK) >> OS_HAL_PCXI_IE_TO_PIE;

    /* #30 Call Os_TrapHandler */
    Os_TrapHandler(Packet, &callerState);                                                                               /* SBSW_OS_HAL_FC_MIXED_VAR */

    /* #40 Prepare the PCXI content for return from system call */
    returnPcxi &= (~(OS_HAL_PCXI_PCPN_MASK | OS_HAL_PCXI_PIE_MASK));
    returnPcxi |= (callerState & OS_HAL_ICR_INT_MASK) << OS_HAL_PCXI_IE_TO_PIE;
    returnPcxi |= (callerState & OS_HAL_ICR_INT_LEVEL_MASK) << OS_HAL_PCXI_CCPN_TO_PCPN;
  }
  else
  {
    boolean PrivilegedMode = Os_Hal_CoreGetPrivilegedModeFromPcxi(Pcxi);
    /* #50 If the identification number is invalid */
    Os_UnhandledSysCall(Addr, PrivilegedMode);                                                                          /* SBSW_OS_HAL_FC_CALLER */
  }

  /* #60 Return Pcxi */
  return returnPcxi;
}


/***********************************************************************************************************************
 *  Os_Hal_IsrRun()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(void, OS_CODE, OS_HAL_NOINLINE,
Os_Hal_IsrRun,
(
  P2CONST(Os_IsrConfigType, AUTOMATIC, OS_CONST) Isr
))
{
  /* #10 Call the handler in core. */
  Os_IsrRun(Isr);                                                                                                       /* SBSW_OS_HAL_FC_CALLER */
}


/***********************************************************************************************************************
 *  Os_Hal_UnhandledIrq()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(void, OS_CODE, OS_HAL_NOINLINE,
Os_Hal_UnhandledIrq,
(
  Os_InterruptSourceIdType InterruptSource,
  uint32 Pcxi,
  Os_AddressOfConstType InterruptAddress
))
{
  boolean PrivilegedMode = Os_Hal_CoreGetPrivilegedModeFromPcxi(Pcxi);
  /* #10 Call the handler in core. */
  Os_UnhandledIrq(InterruptSource, InterruptAddress, PrivilegedMode);                                                   /* SBSW_OS_HAL_FC_CALLER */
}

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Entry.c
 **********************************************************************************************************************/

