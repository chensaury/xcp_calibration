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
 *  \addtogroup  Os_Hal_Core
 *  \{
 *
 * \file        Os_Hal_Core.c
 * \brief       Core related primitives which don't have to be inlined.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */

#define OS_HAL_CORE_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Core.h"

/* Os kernel module dependencies */

/* Os HAL dependencies */
#include "Os_Hal_Os.h"
#include "Os_Hal_Cfg.h"

/***********************************************************************************************************************
 *  VERSION CHECK
 **********************************************************************************************************************/

/* Check the version of OS header file */
#if (  (OS_HAL_SW_MAJOR_VERSION != (2u)) \
    || (OS_HAL_SW_MINOR_VERSION != (27u)) \
    || (OS_HAL_SW_PATCH_VERSION != (0u)) )
# error "Vendor specific version numbers of Os_Hal_Core.c and Os_Hal_Os.h are inconsistent"
#endif

/* Check the version of the configuration header file */
#if (  (OS_CFG_HAL_MAJOR_VERSION != (2u)) \
    || (OS_CFG_HAL_MINOR_VERSION != (16u)) )
# error "Version numbers of Os_Hal_Core.c and Os_Hal_Cfg.h are inconsistent!"
#endif

/***********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define OS_START_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */


/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  Os_Hal_CoreInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/*! This function initialize the IS and TS bits in SYSCON. */
FUNC(void, OS_CODE) Os_Hal_CoreInit(P2CONST(Os_Hal_CoreAsrConfigType, AUTOMATIC, OS_CONST) Config)
{
  Os_Hal_IntGlobalStateType previousState;

  /* #10 Store the current interrupt global state and disable all interrupts. */
  Os_Hal_IntGetGlobalState(&previousState);                                                                             /* SBSW_OS_HAL_FC_LOCAL_VAR */
  Os_Hal_Disable();

  /* #20 Initialize the IS and TS bits in SYSCON. */
  Os_Hal_Mtcr(OS_HAL_SYSCON_OFFSET, Os_Hal_Mfcr(OS_HAL_SYSCON_OFFSET) | OS_HAL_SYSCON_IS_MASK | OS_HAL_SYSCON_TS_MASK);
  Os_Hal_Isync();

  /* #30 Restore the previous interrupt global state. */
  Os_Hal_IntSetGlobalState(&previousState);                                                                             /* SBSW_OS_HAL_FC_LOCAL_VAR */

  OS_IGNORE_UNREF_PARAM(Config);                                                                                        /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
}


/***********************************************************************************************************************
 *  Os_Hal_CoreInitHardware()
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Hal_CoreInitHardware(P2CONST(Os_Hal_SystemConfigType, AUTOMATIC, OS_CONST) Config)
{
  OS_IGNORE_UNREF_PARAM(Config);                                                                                        /* PRQA S 3112 */ /* MD_MSR_DummyStmt */
}


/***********************************************************************************************************************
 *  Os_Hal_CoreFreeze()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(void, OS_CODE, OS_NORETURN, Os_Hal_CoreFreeze,                                             /* COV_OS_HALCOREFREEZE */
(
  void
))
{
  while( (1 == 1) )                                                                                                     /* COV_OS_HALCOREFREEZE */
  {

  }
}


#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* START_COVERAGE_JUSTIFICATION
\ID COV_OS_HALCMSTATICCODEANALYSIS
  \ACCEPT TX
  \REASON The code after this condition is always covered and it just needs to be removed during static code analysis.
          See also [COV_OS_STATICCODEANALYSIS].

\ID COV_OS_HALUNSUPPORTEDCODEREGIONS
   \ACCEPT XX
   \ACCEPT XF
   \REASON This code has not been reached as the switch of code memory regions is not supported. The risk
           of keeping this code is considered to be low.

\ID COV_OS_TESTCODE
   \ACCEPT XX
   \REASON This code is not part of the operating system but of the test framework. Therefore it needs not be covered
           by the operating system tests.

\ID COV_OS_HALINVSTATE
   \ACCEPT XF
   \REASON [COV_MSR_INV_STATE]

\ID COV_OS_HALCOREFREEZE
   \ACCEPT XX
   \REASON This function is called from Os_ErrKernelPanic() right after the panic hook has returned. As the panic hook
           is the last possible exit point for the tests, Os_Hal_CoreFreeze cannot be covered in tests. Because of the
           simplicity of the code, the performed code inspection results in sufficient quality.

\ID COV_OS_HALCOREASSEMBLERINSTRUCTIONDATACASE
   \ACCEPT XX
   \REASON This case in a switch/case instruction has not been reached. However, the result of the switch/case
           construct is simply to use the same assembler instruction with different intermediate data. So each
           case does the same with different data. The risk of testing just some cases is considered to be low.

Justifications for core:

\ID COV_OS_HALPLATFORMCLZAVAILABILITY
   \ACCEPT TX
   \REASON The condition is hardware dependent always true. The unnecessary code parts should be
           removed by compiler optimization. As the tests run on each platform, the OS is to be released for, we
           always just test the code for the respective platform. No risk as the remaining code shall be optimized
           away. (Other platforms may set ACCEPT XF with a similar justification)

\ID COV_OS_HALPLATFORMTHREADPOINTERUSERREADABILITY_TX_XF
   \ACCEPT TX
   \REASON The condition is hardware dependent always true. The unnecessary code parts should be
           removed by compiler optimization. As the tests run on each platform, the OS is to be released for, we
           always just test the code for the respective platform. No risk as the remaining code shall be optimized
           away. (Other platforms may set ACCEPT XF with a similar justification)

\ID COV_OS_HALPLATFORMCOREIDUSERREADABILITY_TX_XF
   \ACCEPT TX
   \REASON The condition is hardware dependent always true. The unnecessary code parts should be
           removed by compiler optimization. As the tests run on each platform, the OS is to be released for, we
           always just test the code for the respective platform. No risk as the remaining code shall be optimized
           away. (Other platforms may set ACCEPT XF with a similar justification)

\ID COV_OS_HALPLATFORMPRIVILEGEMODEUSERREADABILITY
  \ACCEPT TX
  \REASON The condition is hardware dependent always true. The unnecessary code parts should be
          removed by compiler optimization. As the tests run on each platform, the OS is to be released for, we
          always just test the code for the respective platform. No risk as the remaining code shall be optimized
          away.

\ID COV_OS_HALPLATFORMTHREADPOINTERUSERREADABILITY_XX
  \ACCEPT XX
  \REASON Due to the hardware ability to read the current privileges directly, this function is never called. The
          unnecessary code parts should be removed by compiler optimization. As the tests run on each platform, the OS
          is to be released for, we always just test the code for the respective platform. No risk as the remaining code
          shall be optimized away.

\ID COV_OS_HALPLATFORMCLEARPENDINGAVAILABILITY
   \ACCEPT TX
   \REASON The condition is hardware dependent always true. The unnecessary code parts should be
           removed by compiler optimization. As the tests run on each platform, the OS is to be released for, we
           always just test the code for the respective platform. No risk as the remaining code shall be optimized
           away. (Other platforms may set ACCEPT XF with a similar justification)

\ID COV_OS_HALPLATFORMBITLIBCLZ
   \ACCEPT XX
   \REASON This code is meant as library code for the software implementation of Os_Bit_CountLeadingZeros(). As this
           processor provides a hardware solution, this code is unused. However, the function is extremely simple,
           code inspected and unit tested. It is typically optimized away by the linker. Therefore, the risk of
           keeping this code is expected to be low.

\ID COV_OS_HALPLATFORMUNHANDLEDSYSCALL
   \ACCEPT XX
   \REASON This function is only reacheable on some platforms. However, unit test and code inspection have not found
           any risk in keeping this code. The function is fully tested on those platforms which have potentially
           unhandled system calls.

\ID COV_OS_HALPLATFORMNEEDMORETHAN2CORES
   \ACCEPT TF
   \REASON This justification is not valid for TriCore, thus it must be covered.

\ID COV_OS_HALPLATFORMMASTERSTARTALLOWED
   \ACCEPT TF
   \REASON This justification is not valid for TriCore, thus it must be covered.

\ID COV_OS_HALPLATFORMNONAUTOSTARTCORE
   \ACCEPT TF
   \REASON This justification is not valid for TriCore, thus it must be covered.

\ID COV_OS_HALPLATFORMGETSPINLOCK
   \ACCEPT TF
   \REASON This justification is not valid for TriCore, thus it must be covered.

\ID COV_OS_HALPLATFORMAPPISPRIVILEGED
   \ACCEPT XX
   \REASON This cannot be reached within TriCore since the mode is always be read from the PSW

\ID COV_OS_HALPLATFORM_NEED_NO_TRAP_IOC_MULTIQUEUE
  \ACCEPT XF
  \ACCEPT XX
  \REASON This path can never be reached on this platform. As IsTrapRequired is always false for multi-queue IOCs
          and the thread pointer is readable in user mode on this platform, no trap is necessary.

\ID COV_OS_HALPLATFORMCOREINTERRUPTSUNSUPPORTED
  \ACCEPT XF
  \REASON The loop invariant is never true, because on this platform all interrupts are system wide.
          They are initialized in Os_SystemInterruptHandlingInit.

\ID COV_OS_HALPLATFORMEXCEPTIONCONTEXTUNSUPPORTED
   \ACCEPT XF
   \ACCEPT XX
   \REASON The feature "exception context" is not supported on this platform.

\ID COV_OS_HALPLATFORMEXCEPTIONCONTEXTAVAILABILITY
   \ACCEPT XF
   \REASON The feature "exception context" is available on this platform.

\ID COV_OS_HALPLATFORMGLOBAL2LEVELSUPPORTED
   \ACCEPT TX
   \REASON Global to level switch is supported on this platform.

\ID COV_OS_HALPLATFORMPERIPHERALINTTRIGGERSUPPORTED
  \ACCEPT TX
  \REASON This platform always support peripheral interrupt software trigger.

END_COVERAGE_JUSTIFICATION */

/* SBSW_JUSTIFICATION_BEGIN

\ID SBSW_OS_HAL_PWA_CALLER
 \DESCRIPTION    A write access is performed on a pointer, which is coming directly from the caller.
 \COUNTERMEASURE \N No measure is required, because the caller has to check the validity.

\ID SBSW_OS_HAL_FC_CALLER
 \DESCRIPTION    A function is called with one or more pointer parameters, which are coming directly from the caller.
 \COUNTERMEASURE \N No measure is required, because the caller has to check the validity.

\ID SBSW_OS_HAL_FC_LOCAL_VAR
 \DESCRIPTION    A function is called with one or more pointer parameters, which are pointing to local variables.
 \COUNTERMEASURE \N No measure is required, because local variables are always valid.

\ID SBSW_OS_HAL_FC_MIXED_VAR
 \DESCRIPTION    A function is called with one or more pointer parameters, which are pointing to local variables or
                 are passed to the calling function.
 \COUNTERMEASURE \N No measure is required, because local variables are always valid.

\ID SBSW_OS_HAL_PWA_FIRST_PCXI
 \DESCRIPTION    A write access is performed on a pointer, which points to the memory address of the CSA frame. The
                 memory address is derived from "Context->InitPCXI". The validity of "Context" is ensured by the
                 caller. The content of "Context->InitPCXI" is also valid, because it is always initialized, before
                 this pointer write access is performed. If "Context" is a task context, then its "InitPCXI" is
                 initialized in Os_Hal_ContextInit and is re-initialized in Os_Hal_ContextReset and
                 Os_Hal_ContextResetAndResume. If "Context" is an ISR/Hook context, then its "InitPCXI" is either
                 initialized in Os_Hal_ContextInit or re-initialized in Os_Hal_Abort, when the ISR is killed.
                 As a result, whenever Os_Hal_ContextIntCleanupCSAs is called, "Context->InitPCXI" always contains
                 a valid value. Thus, this write access is always performed on a valid pointer.
 \COUNTERMEASURE \N No measure is required, because its validity is ensured by code review.

\ID SBSW_OS_HAL_PWA_PCXI
 \DESCRIPTION    A write access is performed on a pointer, which points to the memory address of the CSA frame. The
                 memory address is derived from the PCXI register. Since Os_Hal_Svlcx is previously performed, the
                 PCXI register always contains a valid value. Thus, this write access is always performed on a valid
                 pointer.
 \COUNTERMEASURE \N No measure is required, because its validity is ensured by code review.

\ID SBSW_OS_HAL_PWA_PCXI_CONTEXTSWITCH
 \DESCRIPTION    A write access is performed on a pointer, which points to the memory address of the CSA frame. The
                 memory address is derived from the InitPCXI or PreviousContextInfo of the context, which is
                 initialized previously by calling Os_Hal_ContextInit in the core code.
 \COUNTERMEASURE \N No measure is required, because its validity is ensured by code review.

\ID SBSW_OS_HAL_PWA_CORECONFIG_PC
 \DESCRIPTION    A write access is performed on the program counter of a foreign core. The address is generated in
                 the corresponding core configuration of type Os_Hal_CoreConfigType.
 \COUNTERMEASURE \S Safety manual should state that generated constant variable of Os_Hal_CoreConfigType in
                 Os_Hal_Core_Lcfg.c needs to be checked. More specifically, the attribute ".ProgramCounterRegister"
                 must be OS_HAL_CORE<X>_PC, where <X> is the core ID. SMI-474

\ID SBSW_OS_HAL_PWA_CORECONFIG_DBGSR
 \DESCRIPTION    A write access is performed on the DBGSR register of a foreign core. The address is generated in
                 the corresponding core configuration of type Os_Hal_CoreConfigType.
 \COUNTERMEASURE \S Safety manual should state that generated constant variable of Os_Hal_CoreConfigType in
                 Os_Hal_Core_Lcfg.c needs to be checked. More specifically, the attribute ".DBGSRRegister"
                 must be OS_HAL_CORE<X>_DBGSR, where <X> is the core ID. SMI-475

\ID SBSW_OS_HAL_PWA_CORECONFIG_SYSCON
 \DESCRIPTION    A write access is performed on the SYSCON register of a foreign core. The address is generated in
                 the corresponding core configuration of type Os_Hal_CoreConfigType.
 \COUNTERMEASURE \S Safety manual should state that generated constant variable of Os_Hal_CoreConfigType in
                 Os_Hal_Core_Lcfg.c needs to be checked. More specifically, the attribute ".SYSCONRegister"
                 must be OS_HAL_CORE<X>_SYSCON, where <X> is the core ID. SMI-46520

\ID SBSW_OS_HAL_PWA_ISRCONFIG_XSIG
 \DESCRIPTION    A write access is performed on the interrupt source register (SRC) of the configured XSignal ISR. The
                 address is in the generated XSignal interrupt configuration of type Os_Hal_XSigInterruptConfigType.
                 In addition, the validity of OS_HAL_INT_SRC_BASE is checked by review.
 \COUNTERMEASURE \S Safety manual should state that the functionality of each configured ISR has to be checked for its
                 correctness. This includes the correct call of the ISR handler as well as enabling, disabling,
                 reading the enable state, reading the pending state and clearing of the pending information of
                 the corresponding ISR sources. SMI-491

\ID SBSW_OS_HAL_PWA_ISRCONFIG
 \DESCRIPTION    A write access is performed on the interrupt source register (SRC) of the configured ISR. The
                 address is in the generated interrupt configuration of type Os_Hal_IntIsrConfigType.
                 In addition, the validity of OS_HAL_INT_SRC_BASE is checked by review.
 \COUNTERMEASURE \S Safety manual should state that the functionality of each configured ISR has to be checked for its
                 correctness. This includes the correct call of the ISR handler as well as enabling, disabling,
                 reading the enable state, reading the pending state and clearing of the pending information of
                 the corresponding ISR sources. SMI-491

\ID SBSW_OS_HAL_FC_MPUCONFIG
 \DESCRIPTION    A function is called with a pointer parameter.
 \COUNTERMEASURE \N No measure required, because this pointer will not be used for write operation by the callee.

\ID SBSW_OS_HAL_PWA_GPTCONFIG
 \DESCRIPTION    A write access is performed on a pointer, which is in the generated timer configuration for GPT of
                 type Os_Hal_TimerPitConfigType.
 \COUNTERMEASURE \S Safety manual should state that the PIT timer configuration is to be checked for its correctness.
                 More specifically, if the GPT channel 0 is configured, the following attributes must be generated
                 as follows:
                 CounterRegisterAddress      = OS_HAL_TIMER_GPT_BASE + OS_HAL_TIMER_GPT_T3_OFFSET
                 CounterConfRegisterAddress  = OS_HAL_TIMER_GPT_BASE + OS_HAL_TIMER_GPT_T3CON_OFFSET
                 ReloadRegisterAddress       = OS_HAL_TIMER_GPT_BASE + OS_HAL_TIMER_GPT_T2_OFFSET
                 ReloadConfRegisterAddress   = OS_HAL_TIMER_GPT_BASE + OS_HAL_TIMER_GPT_T2CON_OFFSET
                 InterruptSRCRegisterAddress = OS_HAL_INT_SRC_BASE + OS_HAL_INT_SRC_GPT_CH0_OFFSET
                 If the GPT channel 1 is configured, the following attributes must be generated as follows:
                 CounterRegisterAddress      = OS_HAL_TIMER_GPT_BASE + OS_HAL_TIMER_GPT_T6_OFFSET
                 CounterConfRegisterAddress  = OS_HAL_TIMER_GPT_BASE + OS_HAL_TIMER_GPT_T6CON_OFFSET
                 ReloadRegisterAddress       = OS_HAL_TIMER_GPT_BASE + OS_HAL_TIMER_GPT_CAPREL_OFFSET
                 ReloadConfRegisterAddress   = OS_HAL_TIMER_GPT_BASE + OS_HAL_TIMER_GPT_CAPREL_OFFSET
                 InterruptSRCRegisterAddress = OS_HAL_INT_SRC_BASE + OS_HAL_INT_SRC_GPT_CH1_OFFSET
                 SMI-478

\ID SBSW_OS_HAL_PWA_FRTCONFIG
 \DESCRIPTION    A write access is performed on a pointer, which is in the generated timer configuration for STM of
                 type Os_Hal_TimerFFrtConfigType.
 \COUNTERMEASURE \S Safety manual should state that the PIT timer configuration is to be checked for its correctness.
                 More specifically, the following attributes must generated as follows, where <X> (0, 1, 2, 3, 4, 5)
                 is STM ID and <Y> (0, 1) is the compare channel ID:
                 CompareRegisterAddress      = OS_HAL_TIMER_STM<X>_BASE + OS_HAL_TIMER_STM_CMP<Y>_OFFSET
                 CMCONRegisterAddress        = OS_HAL_TIMER_STM<X>_BASE + OS_HAL_TIMER_STM_CMCON_OFFSET
                 InterruptSRCRegisterAddress = OS_HAL_INT_SRC_BASE + OS_HAL_INT_SRC_STM<X>_CH<Y>_OFFSET
                 ICRRegisterAddress          = OS_HAL_TIMER_STM<X>_BASE + OS_HAL_TIMER_STM_ICR_OFFSET
                 SMI-479

\ID SBSW_OS_HAL_AWA_EXCEPTION_CONTEXT
 \DESCRIPTION    A write access is performed on an array element.
 \COUNTERMEASURE \N No measure is required, because the correct index is ensured by code review.

\ID SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_SAVE
 \DESCRIPTION    A write access is performed on a pointer read from OsCfg_Hal_Context_ExceptionContextRef.
 \COUNTERMEASURE \R Validity of the pointer is ensured by runtime check.

\ID SBSW_OS_HAL_PWA_EXCEPTION_CONTEXT_RESUME
 \DESCRIPTION    A write access is performed on a pointer derived from the parameter Pcxi.
 \COUNTERMEASURE \N No measure is required, because the correctness of the parameter Pcxi is ensured by the
                 pre-condition and the correct decoding is ensured by review.

SBSW_JUSTIFICATION_END */


/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_Core.c
 **********************************************************************************************************************/
