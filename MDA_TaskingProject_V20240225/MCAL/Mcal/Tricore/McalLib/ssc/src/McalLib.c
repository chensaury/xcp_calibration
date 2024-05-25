/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2018)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME     : McalLib.c                                                  **
**                                                                            **
**  VERSION      : 17.0.0                                                     **
**                                                                            **
**  DATE         : 2018-08-24                                                 **
**                                                                            **
**  VARIANT      : Variant PC                                                 **
**                                                                            **
**  PLATFORM     : Infineon AURIX2G                                           **
**                                                                            **
**  AUTHOR       : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**  VENDOR       : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : MCAL Library source file                                   **
**                                                                            **
**  SPECIFICATION(S) : NA                                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "McalLib.h"
#include "SchM_McalLib.h"
#include "IfxScu_reg.h"
#include "IfxScu_bf.h"
#include "IfxStm_reg.h"
#include "IfxCpu_reg.h"
/* Include Safety Error header definition */
#if(MCALLIB_SAFETY_ENABLE == STD_ON)
#include "Mcal_SafetyError.h"
#endif
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/


/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define MCAL_PASSEQSHIFT                           (0xBU)  /* 11U */
#define MCAL_PASSWORD_SHIFT                        (0xCU)  /* 12U */
#define MCAL_LFSR_SHIFT                            (0xDU)  /* 13U */
#define MCAL_INVALID_ARGUMENT                      (0x0U)

/* Macros for Mcal_GetGlobalDsprAddress/Mcal_GetLocalDsprAddress */
#define MCAL_VALID_DSPR_MSB                        (0xDU)
/* Macros for Mcal_GetGlobalPsprAddress/Mcal_GetLocalPsprAddress */
#define MCAL_VALID_PSPR_MSB                        (0xCU)
#define MCAL_PSPR_ADDRESS_MASK                     (0xF0100000U)
#define MCAL_PSPR_ADDRESS_MASK_N                   (~MCAL_PSPR_ADDRESS_MASK)
#define MCAL_INVALID_CPU_ID_5                      (0x5U)
#define MCAL_SHIFT_UPPER_NIBBLE                    (0x1CU)/* Bit position 28 */

#if ( MCAL_NO_OF_CORES > 5U )
#define MCAL_INVALID_PSPR_ADDR                     (0x0U)
#endif

#if ( MCAL_NO_OF_CORES > 5U )
#define MCAL_INVALID_DSPR_ADDR                     (0x0U)
#endif

/* Macros for ENDINIT protection */
#define MCAL_ENDINIT_WDT_PWD_INV                   (0x3FU)
#define MCAL_ENDINIT_WDT_PWD_MASK                  (0x0000FFFCU)

/* Macros for Peripheral ENDINIT protection */
#define MCAL_PER_ENDINIT_PROTECTED                 (0x1U)
#define MCAL_PER_ENDINIT_WDT_TIMER_REL             (0xFFFC0000U)

/* Macros for Safety ENDINIT protection */
#define MCAL_SAFETY_ENDINIT_PROTECTED              (0x1U)
#define MCAL_SAFETY_ENDINIT_WDT_TIMER_REL          (0xFFFC0000U)
#define MCAL_DEFAULT_MASK_VALUE                    (uint32)(0xFFFFFFFFU)
#define MCAL_SPINLOCK_DEFAULT_TIMEOUT              (uint32)(0x2710U)

/* Macros for CPUWDT ENDINIT protection */
#define MCAL_ENDINIT_RELOAD_MASK                   (0xFFFF0000U)
#define MCAL_CPUWDTSR_TIMER_MASK                   (0xFFFF0000U)
#define MCAL_ENDINIT_TIMEOUT_VALUE                 (0x0000FFFCU)
#define MCAL_CPUWDT_TIMER_VALUE_MAX                (0xFFFFU)

#define MCAL_CPUWDTCON0_UNLOCK                     (0x1U)
#define MCAL_CPUWDTCON0_LOCK                       (0x3U)
#define MCAL_CPUWDTCON0_DISABLE_ENDINIT            (0x2U)
#define MCAL_CPUWDTCON0_ENABLE_ENDINIT             (0x3U)

#define MCAL_AUTO_PWD_SEQ_ENABLED                  (0x1U)
#define MCAL_TIMER_CHECK_ENABLED                   (0x1U)

/* Macros for STM frequency calculation */
#define MCAL_STM_TIMER_RESOL_ZERO                  (0x0U)
#define MCAL_STMCLK_DISABLED                       (0x0U)
#define MCAL_PLL0_CLK_SRC0_FREQ                    (0x1U)
#define MCAL_OSC0_CLK_PLL0_FREQ                    (0x1U)
#define MCAL_RESOLUTION_U                          (0x3E8U) /* 1000U */
#define MCAL_OSCVAL_MHz                            (0x10U)  /* 16 Mhz*/
#define MCAL_OSCFREQ_MHz                            (0x1U)   /* 1 Mhz*/

/* Macros for Spinlock address*/
#define SPINLOCKFREE                               (0x0U)
/*SpinLock is Available*/
#define SPINLOCKBUSY                               (0x1U)
/*SpinLock is Not Available*/
#define MCAL_TIMEOUT                               (0x3E8U) /* 1000U */

/*******************************************************************************
**                      Imported Compiler Switch Checks                       **
*******************************************************************************/
/* [cover parentID={491F788E-197E-4a54-B1C8-2902F835C275}]McalLib version
   check[/cover] */
#ifndef MCALLIB_SW_MAJOR_VERSION
#error "MCALLIB_SW_MAJOR_VERSION is not defined. "
#endif

#ifndef MCALLIB_SW_MINOR_VERSION
#error "MCALLIB_SW_MINOR_VERSION is not defined. "
#endif

#ifndef MCALLIB_SW_PATCH_VERSION
#error "MCALLIB_SW_PATCH_VERSION is not defined. "
#endif

/* Check for Correct inclusion of headers */
#if ( MCALLIB_SW_MAJOR_VERSION != 3U )
#error "MCALLIB_SW_MAJOR_VERSION does not match. "
#endif

#if ( MCALLIB_SW_MINOR_VERSION != 0U )
#error "MCALLIB_SW_MINOR_VERSION does not match. "
#endif

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/* [cover parentID={EA0715EE-3E3C-4aac-A42E-4B5CFC96CEED}]Memory Mapping
   [/cover] */
/* [cover parentID={566ED99C-0D96-46ac-97BF-E97B04E2C700}]Memory mapping for
   callout code is not applicable for McalLib[/cover] */
/* [cover parentID={E4047F9A-8865-4b2c-9D3C-385479854EAD}]Memory mapping for
    configuration data is not applicable for McalLib[/cover] */
/* [cover parentID={72DABBEB-F27B-4677-B6B4-B53F634341BA}]Memory mapping for
    variables[/cover] */
/* [cover parentID={D11431C7-DF20-470b-8994-6A31F882BA7C}][/cover] */
#define MCALLIB_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: 'McalLib_MemMap.h' is header file which
 * contains the memory sections for McalLib. It should not be guarded by
 * standard include. No side effects foreseen by violating this MISRA rule. */

/* MISRA2012_RULE_20_1_JUSTIFICATION: variable 'Mcal_StmTimerResolution'
 * declared before MemMap header file. This variable needs to be placed in a
 * appropriate memory section. No side effects foreseen by violating
 * this MISRA rule */
#include "McalLib_MemMap.h"

static uint32 Mcal_StmTimerResolution;

/* Need to be placed in LMURAM_NC*/
static uint32 Mcal_LockAddressSiecon0;

static uint32 Mcal_LockAddressEicon0;
/* [cover parentID={72DABBEB-F27B-4677-B6B4-B53F634341BA}]Memory mapping for
    variables[/cover] */
#define MCALLIB_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: 'McalLib_MemMap.h' is header file which
 * contains the memory sections for McalLib. It should not be guarded by
 * standard include. No side effects foreseen by violating this MISRA rule. */

/* MISRA2012_RULE_20_1_JUSTIFICATION: variable 'Mcal_StmTimerResolution'
 * declared before MemMap header file. This variable needs to be placed in a
 * appropriate memory section. No side effects foreseen by violating
 * this MISRA rule */
#include "McalLib_MemMap.h"
/* [cover parentID={1A65EADD-AFD0-4845-B2D2-8257E086DD67}]No user mode macro
used [/cover] */

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
/* [cover parentID={5713A17A-3FA1-427f-A0B6-89125A17689A}]No user mode macro
used [/cover] */
#define MCALLIB_START_SEC_CONST_ASIL_B_GLOBAL_8
/* MISRA2012_RULE_4_10_JUSTIFICATION: 'McalLib_MemMap.h' is header file which
 * contains the memory sections for McalLib. It should not be guarded by
 * standard include. No side effects foreseen by violating this MISRA rule. */

/* MISRA2012_RULE_20_1_JUSTIFICATION: variable 'Mcal_StmTimerResolution'
 * declared before MemMap header file. This variable needs to be placed in a
 * appropriate memory section. No side effects foreseen by violating
 * this MISRA rule */
#include "McalLib_MemMap.h"

static const uint8 Mcal_kCoreXMemSegment[MCAL_MAX_CORES + 1U] =
{
  MCAL_CORE0_MEM_SEGMENT, /* index 0 */

  MCAL_CORE1_MEM_SEGMENT, /* index 1 */

  MCAL_CORE2_MEM_SEGMENT, /* index 2 */

  MCAL_CORE3_MEM_SEGMENT, /* index 3 */

  MCAL_CORE4_MEM_SEGMENT, /* index 4 */

  MCAL_MEM_SEGMENT2_MSB,  /* index 5 */
  MCAL_CORE5_MEM_SEGMENT  /* index 6 */

};
#define MCALLIB_STOP_SEC_CONST_ASIL_B_GLOBAL_8
/* MISRA2012_RULE_4_10_JUSTIFICATION: 'McalLib_MemMap.h' is header file which
 * contains the memory sections for McalLib. It should not be guarded by
 * standard include. No side effects foreseen by violating this MISRA rule. */

/* MISRA2012_RULE_20_1_JUSTIFICATION: variable 'Mcal_StmTimerResolution'
 * declared before MemMap header file. This variable needs to be placed in a
 * appropriate memory section. No side effects foreseen by violating
 * this MISRA rule */
#include "McalLib_MemMap.h"

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*[cover parentID={4579FE20-92DA-4848-93DB-7AD4FD35DD50}]Memory mapping for
   code[/cover]*/
#define MCALLIB_START_SEC_CODE_ASIL_B_GLOBAL
/* MISRA2012_RULE_4_10_JUSTIFICATION: 'McalLib_MemMap.h' is header file which
 * contains the memory sections for McalLib. It should not be guarded by
 * standard include. No side effects foreseen by violating this MISRA rule. */

/* MISRA2012_RULE_20_1_JUSTIFICATION: variable 'Mcal_StmTimerResolution'
 * declared before MemMap header file. This variable needs to be placed in a
 * appropriate memory section. No side effects foreseen by violating
 * this MISRA rule */
#include "McalLib_MemMap.h"

LOCAL_INLINE uint32 Mcal_lCpuPwSequence(uint32 CpuIndex, \
                                        uint32 WdtCpuCon0Value);
LOCAL_INLINE uint32 Mcal_lCpuRelValue(uint32 CpuIndex, uint32 WdtCpuCon0Value);

LOCAL_INLINE uint16 Mcal_lDecryptPw(uint32 Value);

LOCAL_INLINE void Mcal_lWriteSafetyEndInitProtection
( volatile void* const RegAddress, const uint32 DataValue, const uint32 Mask);
LOCAL_INLINE uint32 Mcal_lDelayResetTickCalibration(void);
#if (MCALLIB_SAFETY_ENABLE == STD_ON)
static void Mcal_lReportError(const uint8 ApiId, const uint8 ErrorId);
#endif
/*[cover parentID={4579FE20-92DA-4848-93DB-7AD4FD35DD50}]Memory mapping for
   code[/cover]*/
#define MCALLIB_STOP_SEC_CODE_ASIL_B_GLOBAL
/* MISRA2012_RULE_4_10_JUSTIFICATION: 'McalLib_MemMap.h' is header file which
 * contains the memory sections for McalLib. It should not be guarded by
 * standard include. No side effects foreseen by violating this MISRA rule. */

/* MISRA2012_RULE_20_1_JUSTIFICATION: variable 'Mcal_StmTimerResolution'
 * declared before MemMap header file. This variable needs to be placed in a
 * appropriate memory section. No side effects foreseen by violating
 * this MISRA rule */
#include "McalLib_MemMap.h"

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*[cover parentID={4579FE20-92DA-4848-93DB-7AD4FD35DD50}]Memory mapping for
   code[/cover]*/
#define MCALLIB_START_SEC_CODE_ASIL_B_GLOBAL
/* MISRA2012_RULE_4_10_JUSTIFICATION: 'McalLib_MemMap.h' is header file which
 * contains the memory sections for McalLib. It should not be guarded by
 * standard include. No side effects foreseen by violating this MISRA rule. */

/* MISRA2012_RULE_20_1_JUSTIFICATION: variable 'Mcal_StmTimerResolution'
 * declared before MemMap header file. This variable needs to be placed in a
 * appropriate memory section. No side effects foreseen by violating
 * this MISRA rule */
#include "McalLib_MemMap.h"
/*******************************************************************************
** Traceability     : [cover parentID={8366FBD5-CC94-4b46-84C1-1587582733A4}] **
**           [/cover]                                                         **
** Syntax           : uint32 Mcal_GetCpuWdgPassword (void)                    **
**                                                                            **
** Description      : This interface is used by applications to retrieve the  **
**                    endinit password currently installed in the watchdog of **
**                    the CPU they are currently executing on.                **
**                                                                            **
** Service ID       : 0x01                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Currently installed password                            **
**                                                                            **
*******************************************************************************/
uint32 Mcal_GetCpuWdgPassword(void)
{
  uint32 Password;
  /*[cover parentID={7ABA6FAF-7F08-48b8-B059-2F99F2798124}]Retrieve cpuindex
     of current core[/cover] */
  uint32 CoreIdIndex = Mcal_GetCpuIndex();

  /* Retrieve the encrypted(partially inverted) password from the register */
  /* [cover parentID={714F01A3-0913-4052-9F62-D4E907791D82}]Extract the
      password content from WDTCPUxCON0 reg PW bit[/cover] */
  Password = Mcal_GetBitAtomic(MODULE_SCU.WDTCPU[CoreIdIndex].CON0.U, \
                               IFX_SCU_WDTCPU_CON0_PW_OFF, \
                               IFX_SCU_WDTCPU_CON0_PW_LEN);
  /* Decrypt the password (invert bits 0:5) */
  /* [cover parentID={A820A825-B92B-4ff8-87F0-D28F16C2F619}]Decrypt the
      password by inverting bits 0:5[/cover] */
  Password = Password ^ (uint32)MCAL_ENDINIT_WDT_PWD_INV;
  /* [cover parentID={E9117C0D-92CC-41a9-90CB-BE6DBC90F5C3}]return  password
     [/cover] */
  return (Password);
}

/*******************************************************************************
** Traceability     : [cover parentID={C5FA4346-076A-4fce-AC48-91FD7E7C4CBF}] **
**                                                                            **
** Syntax           : uint32 Mcal_SetCpuWdgPassword (const uint32 Password)   **
**                                                                            **
** Description      : This interface is used by applications to install a     **
**                    specified endinit password in the endinit registers of  **
**                    the watchdog of the CPU they are executing on.          **
**                    Previously stored data in the PW bitfield of            **
**                    WDTCPUxCON0 register is returned back to the caller     **
**                                                                            **
** Service ID       : 0x02                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant on same CPU, Reentrant on other CPUs      **
**                                                                            **
** Parameters(in)   : Password - New password to be installed into            **
**                    WDTCPUxCON0 register                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : return the previous installed password                  **
**                                                                            **
*******************************************************************************/
uint32 Mcal_SetCpuWdgPassword(const uint32 Password)
{
  uint32 OldPassword;
  uint32 UnlockCpuWdtCon0Value;
  uint32 NewCpuWdtCon0Value;
  uint32 UnlockPassword;
  uint32 UnlockTimerReload;
  uint32 TimerReload;
  /* The variable 'dummy' is made volatile to prevent any optimization of the
   * variable during compilation, since the variable is used only for read
   * back of ENDINIT control registers, after the same register is written in
   * the previous statement
   */
  volatile uint32 dummy;
  uint32 NewPassword = (Password & (uint32)IFX_SCU_WDTCPU_CON0_PW_MSK);
  /* [cover parentID={C3A1147A-CF1C-480d-8134-75BEDE663A14}]
     Reterive CoreIdIndex[/cover] */
  uint32 CoreIdIndex = Mcal_GetCpuIndex();


  /* Enter critical section */
  /* [cover parentID={4D3611DD-6749-4cc3-81CB-EADA6F27831F}]Enter crtical
        section for updating CpuWdg password[/cover] */
  SchM_Enter_McalLib_CpuEndInit();

  /* Compute the password required to unlock the WDTCPUxCON0 register */
  /* [cover parentID={FDF4342F-66D7-421f-BB54-D832F72EBEAB}]Unlock the
       SCU_WDTCPU_CON0 register, in order to add new  password[/cover] */
  UnlockPassword = Mcal_lCpuPwSequence(CoreIdIndex, \
                               (uint32)(MODULE_SCU.WDTCPU[CoreIdIndex].CON0.U));

  /* Compute the timer reload value required to unlock the
     WDTCPUxCON0 register */
  /* [cover parentID={DDBC84E3-D921-44a3-8F4F-F435AD6181AC}]Compute the timer
      reload value required to unlock the reg[/cover] */
  UnlockTimerReload = Mcal_lCpuRelValue(CoreIdIndex, \
                               (uint32)(MODULE_SCU.WDTCPU[CoreIdIndex].CON0.U));

  /* Compute the latest WDT timer value, which is used during
     setting the new password */
  /* [cover parentID={1CAA54C6-F9D6-485c-82A9-A1980F7D2E9C}]Compute the latest
     WDT timer value, which is used during setting the new password[/cover] */
  TimerReload = Mcal_GetBitAtomic( \
                                   MODULE_SCU.WDTCPU[CoreIdIndex].SR.U, \
                                   IFX_SCU_WDTCPU_SR_TIM_OFF,\
                                   IFX_SCU_WDTCPU_SR_TIM_LEN);

  /* Compute the old password, to be returned, based on the retrieved
     WDTCPUxCON0 value */
  /* [cover parentID={0B562063-81A4-49d4-B1CC-AC13DC27D52D}]Compute the old
      password, to be returned, based on the retrieved WDTCPUxCON0 value
     [/cover] */
  OldPassword = \
               Mcal_lDecryptPw((uint32)(MODULE_SCU.WDTCPU[CoreIdIndex].CON0.U));

  /* Calculate the value to be written in WDTCPUxCON0, to unlock it */
  /* [cover parentID={D48BC0AA-A835-4f73-9183-5A9BB88B8066}]Compute the
          password required to unlock the WDTCPUxCON0 register[/cover]*/
  UnlockCpuWdtCon0Value = \
                          (UnlockTimerReload << IFX_SCU_WDTCPU_CON0_REL_OFF) | \
                          (UnlockPassword << IFX_SCU_WDTCPU_CON0_PW_OFF) | \
                          ((uint32)MCAL_CPUWDTCON0_UNLOCK);

  /*Calculate the value to be written in WDTCPUxCON0, to update it with
     new password */
  /* [cover parentID={560DEE14-8F61-4e98-A434-6BEFC40C2862}]Calculate the
      value to be written in WDTCPUxCON0, to update it with new password
      WDTCPUxCON0 [/cover] */
  NewCpuWdtCon0Value = (TimerReload << IFX_SCU_WDTCPU_CON0_REL_OFF) | \
                       (NewPassword << IFX_SCU_WDTCPU_CON0_PW_OFF) | \
                       ((uint32)MCAL_CPUWDTCON0_LOCK);

  /* Unlock the SCU_WDTCPU_CON0 register, in order to add new  password */
  /* [cover parentID={FDF4342F-66D7-421f-BB54-D832F72EBEAB}][/cover] */
  MODULE_SCU.WDTCPU[CoreIdIndex].CON0.U = UnlockCpuWdtCon0Value;

  dummy = MODULE_SCU.WDTCPU[CoreIdIndex].CON0.U;

  /* Update the SCU_WDTCPU_CON0 with the new password */
  MODULE_SCU.WDTCPU[CoreIdIndex].CON0.U = NewCpuWdtCon0Value;
  dummy = MODULE_SCU.WDTCPU[CoreIdIndex].CON0.U;

  /* Exit critical section */
  /* [cover parentID={3A2FCF58-EB50-44b4-AF19-75E0C63B690D}]Exit critical
     section[/cover] */
  SchM_Exit_McalLib_CpuEndInit();
  UNUSED_PARAMETER(dummy);
  /* [cover parentID={B493E147-E76E-4186-9FDC-70714AA64E31}]
      Return Previously installed password[/cover] */
  return (OldPassword);
}

/*******************************************************************************
** Traceability     : [cover parentID={1619BFC3-44C7-4fe5-84B7-EA6DC8570B6A}] **
**                                                                            **
** Syntax           : void Mcal_WriteCpuEndInitProtReg                        **
**                   (volatile void* const RegAddress, const uint32 DataValue)**
**                                                                            **
** Description      : This interface is used by applications to resume        **
**                    protection of CPU endinit protected registers of the    **
**                    CPU they are executing on.                              **
**                                                                            **
** Service ID       : 0X03                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : RegAddress - CPU Endinit protected register address     **
**                    DataValue - Value to be written to the register located **
**                    at RegAddress.                                          **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
*******************************************************************************/
void Mcal_WriteCpuEndInitProtReg
(volatile void* const RegAddress, const uint32 DataValue)
{
  uint32 UnlockCpuWdtCon0Value;
  uint32 NewCpuWdtCon0Value;
  uint32 UnlockPassword;
  uint32 UnlockTimerReload;
  uint32 TimerReload, TimerReloadAtReset;
  uint32 Password;
  /* [cover parentID={E178D5D6-9647-4bde-9B6D-A42416AC714B}]
     If SAFETY Error Check is Enabled[/cover] */
  #if (MCALLIB_SAFETY_ENABLE == STD_ON)
  uint8  ErrStatus = E_NOT_OK;
  /* [cover parentID={AC213D25-D820-4cef-A724-CA3EB87EB2C6}]
      Check if input address is null pointer[/cover] */
  if ((RegAddress) == NULL_PTR)
  {
    /* [cover parentID={8AA5A630-14E4-444b-AF64-6702217F5C39}]
        Report error MCALLIB_E_PARAM_POINTER[/cover] */
    Mcal_lReportError(MCALLIB_SID_CPUENDINIT, MCALLIB_E_PARAM_POINTER);
    ErrStatus = (uint8)E_NOT_OK;
  }
  /* [cover parentID={FE4D45F8-C269-41d8-A66C-28BF60649F7D}]
     If address is not null pointer [/cover] */
  else
  {
    ErrStatus = (uint8)E_OK;
  }
  /* [cover parentID={FE4D45F8-C269-41d8-A66C-28BF60649F7D}]
     If address is not null pointer [/cover] */
  if (ErrStatus == E_OK)
  #endif
  {
    /* MISRA2012_RULE_11_5_JUSTIFICATION: SFR access. No side effects
       foreseen by violating this MISRA rule.*/
    /* MISRA2012_RULE_11_3_JUSTIFICATION: Conversion between
      pointers of different object types due to SFR access. */
    volatile uint32* const RegAddress0 = RegAddress;
    /* The variable 'dummy' is made volatile to prevent any optimization of
     * the variable during compilation, since the variable is used only for
     * read back of ENDINIT control registers, after the same register is
     * written in the previous statement`
     */
    volatile uint32 dummy;
    /* [cover parentID={5FC8A013-625D-433a-9381-7C74D60AA759}]Retrieve
       cpuindex of current core[/cover] */
    uint32 CoreIdIndex = Mcal_GetCpuIndex();
    /*Enter critical section*/
    /* [cover parentID={34A552A8-765E-401c-9462-0AFA14725E63}]
        Enter critical section [/cover] */
    SchM_Enter_McalLib_CpuEndInit();

    /* Compute the password required to unlock the WDTCPUxCON0 register */
    /* [cover parentID={4351BE63-725F-424f-B835-4196E88830B9}]Compute
        password required to unlock watchdog CPU configuration register
        [/cover] */
    UnlockPassword = Mcal_lCpuPwSequence(CoreIdIndex, \
                               (uint32)(MODULE_SCU.WDTCPU[CoreIdIndex].CON0.U));

    /* Compute the timer reload value required to unlock
     * the WDTCPUxCON0 register */

    /* [cover parentID={8B203839-AEE3-4f52-AF6A-FC24761A09DD}]Compute the
       timer reload value to be written to watchdog CPU configuration
       register to unlock it[/cover] */
    UnlockTimerReload = Mcal_lCpuRelValue(CoreIdIndex, \
                               (uint32)(MODULE_SCU.WDTCPU[CoreIdIndex].CON0.U));

    /* Extract the current timer reload value */
    TimerReload = Mcal_GetBitAtomic( \
                                     MODULE_SCU.WDTCPU[CoreIdIndex].SR.U, \
                                     IFX_SCU_WDTCPU_SR_TIM_OFF, \
                                     IFX_SCU_WDTCPU_SR_TIM_LEN);
    TimerReloadAtReset = TimerReload;
    /* Compute the current password, to be returned, based on the retrieved
     * WDTCPUxCON0 value */
    /* [cover parentID={47EBC9A1-7FBF-4107-93DF-606B80F9AE02}]Compute the
     previously installed password from Watchdog  CPU configuration register
        to return currently installed password[/cover] */
    Password = \
               Mcal_lDecryptPw((uint32)(MODULE_SCU.WDTCPU[CoreIdIndex].CON0.U));

    /* Calculate the value to be written in WDTCPUxCON0, to unlock it */
    UnlockCpuWdtCon0Value = \
                          (UnlockTimerReload << IFX_SCU_WDTCPU_CON0_REL_OFF) | \
                            (UnlockPassword << IFX_SCU_WDTCPU_CON0_PW_OFF) | \
                            ((uint32)MCAL_CPUWDTCON0_UNLOCK);

    /* Calculate the value to be written in WDTCPUxCON0,
     * to temporarily disable ENDINIT protection */
    /* [cover parentID={B8D135AC-BE2F-41e3-9F09-9AED1EDD108C}] Disable the
    ENDINIT protection of Watchdog  CPU configuration register[/cover] */
    NewCpuWdtCon0Value = (TimerReload << IFX_SCU_WDTCPU_CON0_REL_OFF) | \
                         (Password << IFX_SCU_WDTCPU_CON0_PW_OFF) | \
                         ((uint32)MCAL_CPUWDTCON0_DISABLE_ENDINIT);

    /* Unlock the WDTCPUxCON0 register */
    /* [cover parentID={367189E6-9478-4dde-8EF8-16CA2F8C1A0F}] Unlock the
    Watchdog  CPU configuration register using previously computed password
    and timer reload value [/cover] */
    MODULE_SCU.WDTCPU[CoreIdIndex].CON0.U = UnlockCpuWdtCon0Value;
    dummy = MODULE_SCU.WDTCPU[CoreIdIndex].CON0.U;

    /* Update the WDTCPUxCON0 to temporarily disable ENDINIT protection */
    MODULE_SCU.WDTCPU[CoreIdIndex].CON0.U = NewCpuWdtCon0Value;
    dummy = MODULE_SCU.WDTCPU[CoreIdIndex].CON0.U;
    /* [cover parentID={4B6D66E2-D559-49b5-8AD1-F37218EACADC}]
    Update the Cpuendinit protected register with data value[/cover] */
    *RegAddress0 = (uint32)DataValue;
    /* Compute the timer reload value required to unlock the
     * WDTCPUxCON0 register */
    UnlockTimerReload = Mcal_lCpuRelValue(CoreIdIndex, \
                               (uint32)(MODULE_SCU.WDTCPU[CoreIdIndex].CON0.U));

    /* Extract the current timer reload value */
    /* [cover parentID={EF7787FA-639B-4a4b-9F01-D7CE76153C15}]Compute the
       updated timer reload value and to be written when the ENDINIT
       protection is re-enabled[/cover] */
    TimerReload = Mcal_GetBitAtomic(MODULE_SCU.WDTCPU[CoreIdIndex].SR.U, \
                                    IFX_SCU_WDTCPU_SR_TIM_OFF, \
                                    IFX_SCU_WDTCPU_SR_TIM_LEN);

    TimerReload = TimerReload - (uint32)MCAL_ENDINIT_TIMEOUT_VALUE;

    /* [cover parentID={07A12F82-FCC8-42aa-9469-778ACA97A60B}]Updated timer
       reload is sum of current timer reload value and the WDT timer value
       when ENDINIT protection was disabled[/cover] */
    TimerReload = TimerReload + TimerReloadAtReset;

    /* [cover parentID={07B3AC39-320A-4714-BAE3-5B07DBAFE741}]
      Check if timer reload value is greater than max WDG timer reload value
      [/cover] */
    if(TimerReload > (uint32)MCAL_CPUWDT_TIMER_VALUE_MAX)
    {
      /* [cover parentID={B9A51650-92C7-43b7-83B0-989D4356368B}]
          Max WDG timer reload value[/cover] */
      TimerReload = MCAL_CPUWDT_TIMER_VALUE_MAX;
    }
    /* Compute the current password, to be returned, based on the
     * retrieved WDTCPUxCON0 value */
    /* Calculate the value to be written in WDTCPUxCON0, to unlock it */
    /* [cover parentID={5D815056-3F1F-4e22-86EE-6E3380562918}]Compute the
    watchdog CPU configuration register value to Unlock the register.
    [/cover]*/
    UnlockCpuWdtCon0Value = \
                          (UnlockTimerReload << IFX_SCU_WDTCPU_CON0_REL_OFF) | \
                            (UnlockPassword << IFX_SCU_WDTCPU_CON0_PW_OFF) | \
                            ((uint32)MCAL_CPUWDTCON0_UNLOCK);

    /* Calculate the value to be written in WDTCPUxCON0,
     * to re-enable ENDINIT protection */
    /* [cover parentID={259162D2-0F74-4e1b-AB5F-B34B9FDCC457}]
    Update the watchdog CPU configuration register with computed value and
    re-enable ENDINIT protection[/cover] */

    NewCpuWdtCon0Value = (TimerReload << IFX_SCU_WDTCPU_CON0_REL_OFF) | \
                         (Password << IFX_SCU_WDTCPU_CON0_PW_OFF) | \
                         ((uint32)MCAL_CPUWDTCON0_ENABLE_ENDINIT);

    /* Unlock the WDTCPUxCON0 register */
    /* [cover parentID={D854F817-C570-4357-AB55-AA22B3FA8F7D}]
        Unlock the watchdog CPU configuration register[/cover] */
    MODULE_SCU.WDTCPU[CoreIdIndex].CON0.U = UnlockCpuWdtCon0Value;
    dummy = MODULE_SCU.WDTCPU[CoreIdIndex].CON0.U;

    /* Update the WDTCPUxCON0 to re-enable ENDINIT protection */
    /* [cover parentID={4C959BAF-37E8-4113-956E-185185F746C3}]Compute the
        watchdog CPU configuration register value to re-enable the ENDINIT
         protection[/cover] */
    MODULE_SCU.WDTCPU[CoreIdIndex].CON0.U = NewCpuWdtCon0Value;
    dummy = MODULE_SCU.WDTCPU[CoreIdIndex].CON0.U;
    /* [cover parentID={2D104F76-B51A-43a7-BF3C-34D486FC6476}]
       Exit critical section [/cover] */
    SchM_Exit_McalLib_CpuEndInit();

    UNUSED_PARAMETER(dummy);
  }
}
/*******************************************************************************
** Traceability     : [cover parentID={5BE87D93-DC0C-4989-A16E-CE49AEE7BF0D}] **
**                                                                            **
** Syntax           : uint32 Mcal_GetSafetyEndInitPassword (void)             **
**                                                                            **
** Description      : This interface is used by applications to retrieve the  **
**                    Safety endinit password currently installed in the      **
**                    Global ENDINIT control register (SEICON0 register).     **
**                    The password corresponds to EPW bitfield in register    **
**                    SEICON0.                                                **
**                                                                            **
** Service ID       : 0x04                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Currently installed password                            **
**                                                                            **
*******************************************************************************/
uint32 Mcal_GetSafetyEndInitPassword(void)
{
  uint32 Password;

  /* Retrieve the encrypted(partially inverted) password from the register */
  /* [cover parentID={7C4FBB47-84FA-4491-BE2D-D07F7C6AA2D1}]Retrieve the
      encrypted  password from the register[/cover] */
  Password = Mcal_GetBitAtomic(MODULE_SCU.SEICON0.U, \
                               IFX_SCU_SEICON0_EPW_OFF, \
                               IFX_SCU_SEICON0_EPW_LEN);

  /* Decrypt the password (invert bits 0:5) */
  /* [cover parentID={6180D731-B725-466c-8DC7-5CC0D41BB597}]Decrypt the
      password[/cover] */
  Password = Password ^ (uint32)MCAL_ENDINIT_WDT_PWD_INV;
  /* [cover parentID={50367A61-FB21-4c2e-9258-9AA88D7CA8AC}]
      Return password[/cover] */
  return (Password);
}
/*******************************************************************************
** Traceability     : [cover parentID={1D74AAF8-8492-4b33-B8D8-B865ECB04396}] **
**                                                                            **
** Syntax           : uint32 Mcal_SetSafetyEndInitPassword                    **
**                                               (const uint32 Password)      **
**                                                                            **
** Description      : This interface is used by applications to install a     **
**                    password for Safety endinit protection. The interface   **
**                    internally prepares the password (shifting, inversion   **
**                    etc.), installs the password and returns the previously **
**                    installed password (from the EPW bitfield).             **
**                                                                            **
** Service ID       : 0x05                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : Password - New password to be installed into            **
**                    SEICON0 register                                        **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Returns the last installed password                     **
**                                                                            **
*******************************************************************************/
uint32 Mcal_SetSafetyEndInitPassword(const uint32 Password)
{
  uint32 OldPassword;
  uint32 UnlockSeicon0Value;
  uint32 NewSeicon0Value;
  /* The variable 'dummy' is made volatile to prevent any optimization of the
   * variable during compilation, since the variable is used only for read
   * back of ENDINIT control registers, after the same register is written in
   * the previous statement
   */
  volatile uint32 dummy;
  uint32 NewPassword = (Password & (uint32)IFX_SCU_SEICON0_EPW_MSK);

  /* Critical section to protect SCU_SEICON0 register*/
  /* [cover parentID={E6F5A6B8-5E08-496d-B4C3-EB42D886A1F7}]Enter Critical
     Section for updating safety endinit password[/cover] */
  SchM_Enter_McalLib_SafetyEndInit();
  /* [cover parentID={E25FC2A4-0B8A-41fc-936B-A4DF2CB8DCFE}]
      Acquire the spinlock for SEICON0  reg [/cover] */
  Mcal_GetSpinlock(&Mcal_LockAddressSiecon0, \
                   (uint32)MCAL_SPINLOCK_DEFAULT_TIMEOUT);

  /* [cover parentID={6CFA30E3-B332-47a0-9779-39A715C02A47}]
    Calculate the old password from the retrieved SCU_SEICON0 register
    [/cover]*/
  OldPassword = Mcal_lDecryptPw((uint32)(MODULE_SCU.SEICON0.U));
  /* Calculate the value to be written in SCU_SEICON0, to unlock it */
  /* [cover parentID={649ADD16-7FB0-4df9-A7A5-844CCE458E51}]*/
  UnlockSeicon0Value = ((uint32)MCAL_SAFETY_ENDINIT_WDT_TIMER_REL | \
                      ((uint32)OldPassword << (uint32)IFX_SCU_SEICON0_EPW_OFF));

  /* Calculate the value to be written in SCU_SEICON0,
   * to update it with new password */

  NewSeicon0Value = \
                    (uint32)((uint32)MCAL_SAFETY_ENDINIT_WDT_TIMER_REL | \
                    ((uint32)NewPassword << (uint32)IFX_SCU_SEICON0_EPW_OFF) | \
                             ((uint32)MCAL_SAFETY_ENDINIT_PROTECTED << \
                              (uint32)IFX_SCU_SEICON0_ENDINIT_OFF));
  /* Unlock the SCU_SEICON0 register, in order to add new  password */
  /* [cover parentID={080B1935-DD06-456b-BBDB-A50E6DDC6062}]Update the
     SCU_SEICON0 with the new password and release the lock from reg*/
  MODULE_SCU.SEICON0.U = UnlockSeicon0Value;
  dummy = MODULE_SCU.SEICON0.U;

  /* Update the SCU_SEICON0 with the new password */
  MODULE_SCU.SEICON0.U = NewSeicon0Value;
  dummy = MODULE_SCU.SEICON0.U;
  /*Release the Spinlock*/
  /*[/cover] */
  Mcal_ReleaseSpinlock(&Mcal_LockAddressSiecon0);
  /* [cover parentID={EA17FFF8-6438-4167-80A3-470F8B14D1C4}]
     Exit critical section [/cover] */
  SchM_Exit_McalLib_SafetyEndInit();
  UNUSED_PARAMETER(dummy);
  /*Return old password*/
  /* [cover parentID={567C341C-482C-4c37-9651-52F4095AA60E}]Return old
     password [/cover] */
  return (OldPassword);
}
/*******************************************************************************
** Traceability     :[cover parentID={49C5FBA9-0673-47dd-8182-DE8AED479123}]  **
** [/cover]                                                                   **
** Syntax           : void Mcal_WriteSafetyEndInitProtReg                     **
                     (volatile void* const RegAddress, const uint32 DataValue)**
**                                                                            **
** Description      : This API is needed to write required values to safety   **
**                    end-init protected registers by unprotecting to write   **
**                    and protecting back to keep protection intact           **
**                                                                            **
**                                                                            **
** Service ID       : 0x06                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : RegAddress - Safety Endinit protected register address  **
**                    DataValue - Value to be written to the register located **
**                    at RegAddress                                           **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
*******************************************************************************/
void Mcal_WriteSafetyEndInitProtReg
( volatile void* const RegAddress, const uint32 DataValue)
{
  /* [cover parentID={4035DB5A-D359-4547-B3D4-AD4A8475F6EE}]
      If SAFETY Error Check is Enabled[/cover] */
  #if (MCALLIB_SAFETY_ENABLE == STD_ON)
  uint8  ErrStatus = E_NOT_OK;
  /* [cover parentID={2C16B817-914C-46a6-8232-4EE20FC3FDAA}]
      Check if input address is null pointer[/cover] */
  if ((RegAddress) == NULL_PTR)
  {
    /* [cover parentID={27FF0329-1BC1-4339-91A7-E02687B80671}]
        Report error MCALLIB_E_PARAM_POINTER[/cover] */
    Mcal_lReportError(MCALLIB_SID_SAFETYENDINIT, \
                      MCALLIB_E_PARAM_POINTER);
    ErrStatus = (uint8)E_NOT_OK;
  }
  /* [cover parentID={AB76685F-687F-4e66-9DAC-E28B0DBCAFCE}]
       If address is not null pointer[/cover] */
  else
  {
    ErrStatus = (uint8)E_OK;
  }
  /* [cover parentID={AB76685F-687F-4e66-9DAC-E28B0DBCAFCE}]
     If address is not null pointer[/cover] */
  if (ErrStatus == E_OK)
  #endif
  {
    /* [cover parentID={D3758D48-3C0C-4ef7-B702-4279CC4E0FD5}]
         Mcal_WriteSafetyEndInitProtReg[/cover] */
    /* [cover parentID={0AB9676C-BE6A-4851-AC15-612F9E23A897}]
       Write the data into safetyendinit register with default mask
       [/cover] */
    Mcal_lWriteSafetyEndInitProtection\
    ( RegAddress, (uint32)DataValue\
      , (uint32)MCAL_DEFAULT_MASK_VALUE);

  }
}
/*******************************************************************************
** Traceability     : [cover parentID={C056F09A-B74A-4ac8-A7E8-9B8D40D8C8E2}] **
** [/cover]                                                                   **
** Syntax           : void Mcal_WriteSafetyEndInitProtRegMask                 **
**                      (volatile void* const RegAddress,                     **
**                      const uint32 DataValue,                               **
**                      uint32 Mask)                                          **
**                                                                            **
** Description      : This API is needed to write required values to safety   **
**                    end-init protected register bits by unprotecting to     **
                      write and protecting back to keep protection intact     **
**                                                                            **
**                                                                            **
**                                                                            **
** Service ID       : 0x16                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : RegAddress - Safety Endinit protected register address  **
**                    DataValue - Value to be written to the register located **
**                    at RegAddress                                           **
**                    Mask - Value to be written to mask the register value   **
**                    need to be changed.                                     **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
*******************************************************************************/
void Mcal_WriteSafetyEndInitProtRegMask
(volatile void* const RegAddress, const uint32 DataValue, uint32 Mask)
{
  /* [cover parentID={5974CFB6-87C9-4794-B9F9-0EC6DD775F98}]
      If SAFETY Error Check is Enabled[/cover] */
  #if (MCALLIB_SAFETY_ENABLE == STD_ON)
  uint8  ErrStatus = E_NOT_OK;
  /* [cover parentID={CBE8BCA9-7698-4c9d-8E65-EE8C1F75B35D}]
      Check if input address is null pointer[/cover] */
  if ((RegAddress) == NULL_PTR)
  {
    /* [cover parentID={E2348FD8-212E-4299-88D4-3849DBE60CCF}]
       Report error MCALLIB_E_PARAM_POINTER[/cover] */
    Mcal_lReportError(MCALLIB_SID_SAFETYENDINITMASK, \
                      MCALLIB_E_PARAM_POINTER);
    ErrStatus = (uint8)E_NOT_OK;
  }
  /* [cover parentID={1348778A-0EA6-4fb3-B370-4751F20C57D0}]
     If address is not null pointer[/cover] */
  else
  {
    ErrStatus = (uint8)E_OK;
  }
  /* [cover parentID={1348778A-0EA6-4fb3-B370-4751F20C57D0}]
     If address is not null pointer[/cover] */
  if (ErrStatus == E_OK)
  #endif
  {
    /* [cover parentID={D8F923BB-96E0-441d-A9F8-BA1A6D865DE4}]
       Mcal_WriteSafetyEndInitProtRegMask[/cover] */
    /* [cover parentID={F67D85E8-2ED7-481e-AA31-B1BC3FC37866}]
       Write the data into safetyendinit register with mask[/cover] */
    Mcal_lWriteSafetyEndInitProtection\
    (RegAddress, (uint32)DataValue, (uint32)Mask);
  }
}
/*******************************************************************************
** Traceability     : [cover parentID={E0C11962-A636-4404-B096-E13741CF52ED}] **
** [/cover]                                                                   **
** Syntax           : uint32 Mcal_GetPeripheralEndInitPassword (void)         **
**                                                                            **
** Description      : This interface is used by applications to retrieve the  **
**                    peripheral endinit password currently installed in the  **
**                    Global ENDINIT control register (EICON0 register).      **
**                    The password corresponds to bits 15:2 in register EICON0**
**                                                                            **
** Service ID       : 0x07                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Currently installed password                            **
**                                                                            **
*******************************************************************************/
uint32 Mcal_GetPeripheralEndInitPassword(void)
{
  uint32 Password;

  /* Retrieve the encrypted(partially inverted) password from the register */
  /* [cover parentID={C2FA35C2-FD4F-42ab-81A5-3CB77AB6293F}]Retrieve the
     encrypted  password from the register[/cover] */
  Password = Mcal_GetBitAtomic(MODULE_SCU.EICON0.U, \
                               IFX_SCU_EICON0_EPW_OFF, \
                               IFX_SCU_EICON0_EPW_LEN);

  /* Decrypt the password (invert bits 0:5) */
  /* [cover parentID={B8B47083-237D-44e7-8286-FAD882674D90}]Decrypt the
     password[/cover] */
  Password = Password ^ (uint32)MCAL_ENDINIT_WDT_PWD_INV;
  /* [cover parentID={8E0B1A74-D0AD-4d98-A6D4-7AB519A9F963}]
     Return password[/cover] */
  return (Password);
}
/*******************************************************************************
** Traceability     :[cover parentID={1C3749D6-0FFF-4339-B267-3167F5938B13}]  **
**                                                                            **
** Syntax           : uint32 Mcal_SetPeripheralEndInitPassword                **
**                   (const uint32 Password)                                  **
**                                                                            **
** Description      : This interface is used by applications to install a     **
**                    password for peripheral endinit protection. The         **
**                    interface internally prepares the password (shifting,   **
**                    inversion etc.), installs the password and returns the  **
**                    previously installed password.                          **
**                                                                            **
** Service ID       : 0x08                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : Password - New password to be installed into            **
**                    EICON0 register                                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Returns the last installed password                     **
**                                                                            **
*******************************************************************************/
uint32 Mcal_SetPeripheralEndInitPassword(const uint32 Password)
{
  uint32 OldPassword;
  uint32 UnlockEicon0Value;
  uint32 NewEicon0Value;
  /* The variable 'dummy' is made volatile to prevent any optimization of the
   * variable during compilation, since the variable is used only for read
   * back of ENDINIT control registers, after the same register is written in
   * the previous statement
   */
  volatile uint32 dummy;
  uint32 NewPassword = (Password & (uint32)IFX_SCU_EICON0_EPW_MSK);

  /* Enter Critical section, to protect write to SCU_EICON0 register */
  /* [cover parentID={BC630CB8-C731-46da-8F2D-AAD711F48140}]Enter crtical
          section for updating peripheral endinit password[/cover] */
  SchM_Enter_McalLib_PeripheralEndInit();

  /*Acquire the Spinlock for writing tp SCU_EICCON0 register*/
  /* [cover parentID={D437EBC8-69C1-41f7-9F98-1A83FC2FD42F}]Acquire the
     Spinlock for  SCU_EICCON0 reg[/cover] */
  Mcal_GetSpinlock(&Mcal_LockAddressEicon0, \
                   (uint32)MCAL_SPINLOCK_DEFAULT_TIMEOUT);
  /* Calculate the old password from the retrieved SCU_EICON0 register */
  /* [cover parentID={E2CA0A31-9262-4ce9-9DA3-CEEDC94F84AD}]Calculate the old
       password from the retrieved SCU_EICON0 reg[/cover] */
  OldPassword = Mcal_lDecryptPw((uint32)(MODULE_SCU.EICON0.U));
  /* Calculate the value to be written in SCU_EICON0, to unlock it */
  /* [cover parentID={24A57C94-A134-42a3-8C56-8DD828FD73F8}]Unlock the
           SCU_EICON0 to update it with new password */
  UnlockEicon0Value = ((uint32)MCAL_PER_ENDINIT_WDT_TIMER_REL | \
                       ((uint32)OldPassword << (uint32)IFX_SCU_EICON0_EPW_OFF));

  /* Calculate the value to be written in SCU_EICON0,
   * to update it with new password */
  /*[/cover] */
  NewEicon0Value = \
                   ((uint32)MCAL_PER_ENDINIT_WDT_TIMER_REL | \
                    ((uint32)NewPassword << (uint32)IFX_SCU_EICON0_EPW_OFF) | \
            ((uint32)MCAL_PER_ENDINIT_PROTECTED << IFX_SCU_EICON0_ENDINIT_OFF));

  /* Unlock the SCU_EICON0 register, in order to add new  password */
  MODULE_SCU.EICON0.U = (uint32)UnlockEicon0Value;
  dummy = MODULE_SCU.EICON0.U;

  /* Update the SCU_EICON0 with the new password */
  MODULE_SCU.EICON0.U = NewEicon0Value;
  dummy = MODULE_SCU.EICON0.U;
  /*Release the Spinlock*/
  /* [cover parentID={F278194C-27DD-4269-BCBE-0B7082469A6C}]Release the
     spinlock from SCU_EICON0 reg[/cover] */
  Mcal_ReleaseSpinlock(&Mcal_LockAddressEicon0);
  /* Exit Critical section */
  /* [cover parentID={354CAA44-C8E0-4010-A6C0-A010432A0C74}]Exit critical
     section[/cover] */
  SchM_Exit_McalLib_PeripheralEndInit();
  UNUSED_PARAMETER(dummy);
  /*Return old password*/
  /* [cover parentID={61C56107-C8EB-4fbf-9A29-8BEA6DEDBADF}]Return old
     password [/cover] */
  return (OldPassword);
}
/*******************************************************************************
** Traceability     : [cover parentID={382E875A-A388-4f3f-842B-BBD7143DEE70}] **
**                                                                            **
** Syntax           : Mcal_WritePeripEndInitProtReg                           **
**                   (volatile void* const RegAddress, const uint32 DataValue)**
**                                                                            **
** Description      :This API is needed to write required values to peripheral**
**                   protected registers by unprotecting to write end-init    **
**                   and protecting back to keep protection intact.           **
**                                                                            **
** Service ID       : 0x09                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : RegAddress - Peripheral Endinit protected register      **
**                    address.                                                **
**                    DataValue - Value to be written to the register         **
**                    located at RegAddress.                                  **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
*******************************************************************************/
void Mcal_WritePeripEndInitProtReg
( volatile void* const RegAddress, const uint32 DataValue)
{
  uint32 Password;
  uint32 Eicon0Value;
  /* [cover parentID={AFFF6EC8-965F-4f68-A3DA-BBCC7AE589B1}]
     If SAFETY Error Check is Enabled[/cover] */
  #if (MCALLIB_SAFETY_ENABLE == STD_ON)
  uint8  ErrStatus = E_NOT_OK;
  /* [cover parentID={E437DC4F-781A-4f79-B1CC-4C6D0557C31D}]
      Check if input address is null pointer[/cover] */
  if ((RegAddress) == NULL_PTR)
  {
    /* [cover parentID={55F2F56D-E927-47b0-9B15-38874239EA8D}]
       Report error MCALLIB_E_PARAM_POINTER[/cover] */
    Mcal_lReportError(MCALLIB_SID_PERIPHERALENDINIT, \
                      MCALLIB_E_PARAM_POINTER);
    ErrStatus = (uint8)E_NOT_OK;
  }
  /* [cover parentID={68C78085-FCDC-4bf6-8D36-F75B06543DB5}]
     If address is not null pointer [/cover] */
  else
  {
    ErrStatus = (uint8)E_OK;
  }
  /* [cover parentID={68C78085-FCDC-4bf6-8D36-F75B06543DB5}]
     If address is not null pointer [/cover] */
  if (ErrStatus == E_OK)
  #endif
  {
    /* The variable 'dummy' is made volatile to prevent any optimization of
    *  the variable during compilation, since the variable is used only for
    *  read back of ENDINIT control registers, after the same register is
    *  written in the previous statement
    */
    volatile uint32 dummy;
    /* MISRA2012_RULE_11_5_JUSTIFICATION: SFR access. No side effects
       foreseen by violating this MISRA rule.*/
    /* MISRA2012_RULE_11_3_JUSTIFICATION: Conversion between
    pointers of different object types due to SFR access. */
    volatile uint32* const RegAddress0 = RegAddress;
    /*Critical section to protect SCU_EICON0 ans SCU_EICON1 registers */
    /* [cover parentID={F256AEAD-46DA-45e8-9F8C-AB0972C9C7AD}][/cover] */
    SchM_Enter_McalLib_PeripheralEndInit();
    /*Acquire the lock for SCU_EICCON0 register*/
    /* [cover parentID={68AF95B0-1C75-437c-B442-870B38CE80E7}]Acquire the
        lock for SCU_EICCON0 register[/cover] */
    Mcal_GetSpinlock(&Mcal_LockAddressEicon0, \
                     (uint32)MCAL_SPINLOCK_DEFAULT_TIMEOUT);

    /* Calculate the password from the retrieved SCU_EICON0 register */
    /* [cover parentID={4790B570-E53A-4919-BD53-9C83E2C93981}]Retrieved the
        decrypted password from  SCU_EICON0 register[/cover] */
    Password = Mcal_lDecryptPw((uint32)(MODULE_SCU.EICON0.U));

    /* Calculate the value to be written in SCU_EICON0, to unlock it */
    Eicon0Value = ((uint32)MCAL_PER_ENDINIT_WDT_TIMER_REL | \
                   ((uint32)Password << (uint32)IFX_SCU_EICON0_EPW_OFF));

    /* Unlock the SCU_EICON0 register to disable ENDINIT protection */
    /* [cover parentID={60EC2B4D-F0A9-4c56-A2E9-475647958FC6}]Compute the
       EICON0 register value to Disable the ENDINIT protection[/cover] */
    MODULE_SCU.EICON0.U = Eicon0Value;
    /* [cover parentID={B92CEA4B-F2C7-426f-9814-01805ADBF1F3}]
        Read back the EICON0  reg to ensure Write is is done correctly.
       [/cover] */
    dummy = MODULE_SCU.EICON0.U;

    *RegAddress0 = (uint32)DataValue;

    /* Calculate the value to be written in SCU_EICON0,
     * to enable protection of Peripheral ENDINIT protected registers */
    /* [cover parentID={0D72C330-7F4F-4a4c-81E6-9548AF6C21E8}]Compute the
        EICON0 register value to Re-enable the ENDINIT protection[/cover] */
    Eicon0Value = \
                  (uint32)MCAL_PER_ENDINIT_WDT_TIMER_REL | \
                  (uint32)(Password << (uint32)IFX_SCU_EICON0_EPW_OFF) | \
                  ((uint32)MCAL_PER_ENDINIT_PROTECTED << \
                   IFX_SCU_EICON0_ENDINIT_OFF);

    /* Update the SCU_EICON0 to re-enable ENDINIT protection */
    /* [cover parentID={D8037720-9D59-4714-9652-EF3A45A60A19}]Update the
      ENDINIT protected Register with the data passed as a input [/cover] */
    /* [cover parentID={2253ECF3-FDD1-4f24-B198-A9D39BEFA6C1}] Re-enable the
       ENDINIT protection[/cover] */
    MODULE_SCU.EICON0.U = Eicon0Value;
    /* [cover parentID={E7073F52-21BD-454a-9099-89C9D22FE964}]
       Read back the EICON0  reg to ensure Write is is done correctly.
       [/cover] */
    dummy = MODULE_SCU.EICON0.U;
    /*release the lock on SCU_EICCON0 register*/
    /* [cover parentID={81B778B2-1F71-440d-AF4F-DD2846703777}]Release the
        lock for SCU_EICCON0 register[/cover] */
    Mcal_ReleaseSpinlock(&Mcal_LockAddressEicon0);
    /* [cover parentID={12BBC363-4093-406b-9496-7C0B26EFEC31}]
       Exit critical section[/cover] */
    SchM_Exit_McalLib_PeripheralEndInit();
    UNUSED_PARAMETER(dummy);
  }
}
/*******************************************************************************
** Traceability     : [cover parentID={32C6BD4E-84D4-4d99-9939-40ACDFBADF92}] **
**                                                                            **
** Syntax           : uint32 Mcal_GetCpuPhysicalId(void)                      **
**                                                                            **
** Description      : This interface is used by applications in a multicore   **
**                    environment to determine the CPU they are executing on. **
**                    The API returns the contents of CORE_ID register, for   **
**                    the core on which it is invoked.                        **
**                                                                            **
** Service ID       : 0x0A                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Physical Core ID for the CPU on which this API is called**
**                                                                            **
*******************************************************************************/
uint32 Mcal_GetCpuPhysicalId(void)
{
  /* [cover parentID={67B47B7B-BCC4-4e5f-9A7E-1E171742E615}]
     Read the CPU_CORE_ID register to retrieve the CoreId [/cover] */
  uint32 CoreId = (uint32)MFCR(CPU_CORE_ID);
  /* [cover parentID={2E22F876-FA68-47b1-BFFC-3EBDC68F5C10}]
     Return CoreId[/cover] */
  return(CoreId);
}

/*******************************************************************************
** Traceability     : [cover parentID={19A3024B-65AF-4139-95D6-AF25CB4A476E}] **
**                                                                            **
** Syntax           : uint32 Mcal_GetGlobalDsprAddress                        **
**                    (                                                       **
**                     const uint32 CpuId,                                    **
**                     const uint32 LocalDsprAddress                          **
**                    )                                                       **
**                                                                            **
** Description      : This interface is used by applications in a multicore   **
**                    environment to determine the global address of a local  **
**                    DSPR address of a specified CPU. A value 0 is returned  **
**                    in case an invalid input argument is passed             **
**                    (incorrect CpuId, local DSPR address)                   **
**                                                                            **
**                                                                            **
** Service ID       : 0x0C                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : CpuId - Physical Core ID                                **
**                    LocalDsprAddress - Local DSPR address for which global  **
**                    DSPR address is returned                                **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : 0: Invalid input parameter passed                       **
**                    Else, value returned the Global DSPR address            **
**                    If passed parameter is valid global DSPR address        **
**                    corresponding to passed CPU id then return              **
**                    passed address as is.                                   **
*******************************************************************************/
uint32 Mcal_GetGlobalDsprAddress
(const uint32 CpuId, const uint32 LocalDsprAddress)
{

  /* Obtain the memory segment information to which
   * LocalDsprAddress belongs to */
  uint8 DsprMsb = \
                 (uint8)((LocalDsprAddress & (uint32)MCAL_DSPR_GLOBAL_MASK) >> \
                          MCAL_SHIFT_UPPER_NIBBLE);

  uint32  RetGlobalAddress = MCAL_INVALID_ARGUMENT;
  /* [cover parentID={5AB06FBB-9343-4fe2-AEC4-6F40F2290CA4}]
     Compute an DSPR end address based on available core [/cover] */
  uint32  DsprEndAddress[MCAL_COREID_MAX_VALUE + 1U] =
  {
    MCAL_DSPR0_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 1U )
    MCAL_DSPR1_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 2U )
    MCAL_DSPR2_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 3U )
    MCAL_DSPR3_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 4U )
    MCAL_DSPR4_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 5U )
    MCAL_INVALID_DSPR_ADDR,
    MCAL_DSPR5_END_ADDR
    #endif
    #endif
    #endif
    #endif
    #endif
  };

  /* Is the input physical CpuId a valid value */
  /* [cover parentID={4601D034-5B02-4e38-8306-3B0B47BFD6E2}]
     Check if CpuId is not coreId5 and geater than or equal to number of core
     [/cover] */
  if((CpuId != (uint32)MCAL_INVALID_CPU_ID_5) && \
      (CpuId <= (uint32)MCAL_COREID_MAX_VALUE))
  {
    /* Is LocalDsprAddress within the DSPR address range */
    /* The check against the starting address of DSPR memory range isnlt
     * done as its base address starts from 0xM0000000 - 0xM0018000,
     * where 'M' corresponds to memory segment
     */
    /* [cover parentID={7584D010-0D1C-4cec-8371-A89B322A1E92}]Local
       DsprAddress within the DSPR address range[/cover] */
    if((LocalDsprAddress & (uint32)MCAL_DSPR_GLOBAL_MASK_N) <= \
        DsprEndAddress[CpuId])
    {
      /* Does LocalDsprAddress belong to memory segment 0xD */
      /* [cover parentID={C021555F-7DEF-4011-8235-C90C2DE91FF3}]LocalDspr
         Address belong to memory segment 0xD[/cover] */
      if (DsprMsb == (uint8)MCAL_VALID_DSPR_MSB)
      {
        /* Compute the Global DSPR address */
        /* [cover parentID={68068C41-3E2A-4f2c-ADF7-D527D8A53EF7}]
            Compute globalDspraddress[/cover] */
        RetGlobalAddress = \
                       ((LocalDsprAddress & (uint32)MCAL_DSPR_GLOBAL_MASK_N) | \
                            ((uint32)Mcal_kCoreXMemSegment[CpuId]\
                             << MCAL_SHIFT_UPPER_NIBBLE));
      }
      else
      {
        /* Validate if DSPR address's memory segment belongs to a
         * valid CPUx memory segment */
        /*if ((DsprMsb != (uint8)MCAL_MEM_SEGMENT2_MSB) && \
            (DsprMsb <= (uint8)MCAL_CORE0_MEM_SEGMENT) && \
            (DsprMsb >= Mcal_kCoreXMemSegment[MCAL_COREID_MAX_VALUE]))*/
        /* [cover parentID={B6E52E52-6E44-4bdf-95CD-25E11748601C}]GlobalDspr
        address memory segment belong to valid CPU memory segment[/cover] */
        if(DsprMsb == Mcal_kCoreXMemSegment[CpuId])
        {
          /*[cover parentID={EA7BB3D2-D189-4931-80BF-6C6E091157F4}]Return
                 GlobalDsprAddress[/cover] */
          RetGlobalAddress = LocalDsprAddress;
        }
      }
    }
  }
  /* [cover parentID={EA7BB3D2-D189-4931-80BF-6C6E091157F4}]Return
     GlobalDsprAddress[/cover] */
  /* [cover parentID={9E058E8D-CE5F-4aeb-A4ED-BA0B0CCFE5B6}]Return
     GlobalDspraddress 0[/cover] */
  return (RetGlobalAddress);
}
/*******************************************************************************
** Traceability     : [cover parentID={6A4C10C1-2C3C-468f-8F33-C02634550889}] **
**                                                                            **
** Syntax           : uint32 Mcal_GetLocalDsprAddress                         **
**                    (                                                       **
**                     const uint32 GlobalDsprAddress                         **
**                    )                                                       **
**                                                                            **
** Description      : This API is used by applications in a multicore         **
**                    environment to determine the local CPU address of a     **
**                    global DSPR address of the CPU, this interface is       **
**                    invoked on. A value 0 is returned in case an invalid    **
**                    input argument is passed(incorrect global DSPR address) **
**                                                                            **
** Service ID       : 0x0D                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : GlobalDsprAddress - Global DSPR address                 **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : 0: Invalid input parameter passed                       **
**                    Else, value returned the local DSPR address             **
**                    If passed parameter is valid local DSPR address         **
**                    corresponding to currently executing CPU then routine   **
**                    shall return passed address as is                       **
*******************************************************************************/
uint32 Mcal_GetLocalDsprAddress(const uint32 GlobalDsprAddress)
{

  /* Obtain the memory segment information to which
   * GlobalDsprAddress belongs to */
  uint8 DsprMsb = \
                (uint8)((GlobalDsprAddress & (uint32)MCAL_DSPR_GLOBAL_MASK) >> \
                          MCAL_SHIFT_UPPER_NIBBLE);
  uint32 RetLocalAddress = MCAL_INVALID_ARGUMENT;
  /* [cover parentID={F1D77D46-E71E-461c-BB86-B438B9716DAC}]Check for CPUIndex
     [/cover] */
  uint32 CoreIndex = Mcal_GetCpuIndex();

  /* [cover parentID={B66F0432-1D0A-44c3-926A-D1B6897684AB}]
  Compute a global DSPR end address based on available core [/cover] */
  uint32 DsprEndAddress[MCAL_COREID_MAX_VALUE + 1U] =
  {
    MCAL_DSPR0_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 1U )
    MCAL_DSPR1_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 2U )
    MCAL_DSPR2_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 3U )
    MCAL_DSPR3_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 4U )
    MCAL_DSPR4_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 5U )
    MCAL_INVALID_DSPR_ADDR,
    MCAL_DSPR5_END_ADDR
    #endif
    #endif
    #endif
    #endif
    #endif

  };
  /* [cover parentID={F43CEA65-A9BE-4051-99B2-D7AA361231AB}]
  Compute a global DSPR end address based on available CPU index[/cover] */
  uint32  DsprEndAddressIndexBased[MCAL_NO_OF_CORES] =
  {
    MCAL_DSPR0_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 1U )
    MCAL_DSPR1_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 2U )
    MCAL_DSPR2_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 3U )
    MCAL_DSPR3_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 4U )
    MCAL_DSPR4_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 5U )
    MCAL_DSPR5_END_ADDR
    #endif
    #endif
    #endif
    #endif
    #endif
  };
  /* Validate if Global DSPR address's memory segment is a
   *  valid CPUx memory segment */
  /* [cover parentID={E163BFCC-7444-4c74-9762-D50D80ACA3B9}]Is
     GlobalDsprAddress’s memory segment a valid CPU memory segment[/cover] */
  if ((DsprMsb != (uint8)MCAL_MEM_SEGMENT2_MSB) && \
      (DsprMsb <= (uint8)MCAL_CORE0_MEM_SEGMENT) && \
      (DsprMsb >= Mcal_kCoreXMemSegment[MCAL_COREID_MAX_VALUE]))
  {
    /* Is GlobalDsprAddress within the DSPR address range */
    /* The check against the starting address of DSPR memory range isn't
     * done as its base address starts from 0xM0000000 - 0xM0018000, where
     * 'M' corresponds to memory segment
     */
    /* [cover parentID={F490A20E-4BB0-46d3-9E7E-78D3E82E289D}]Is
       GlobalDsprAddress address within the DSPR address range[/cover] */
    if((GlobalDsprAddress & (uint32)MCAL_DSPR_GLOBAL_MASK_N) <= \
        DsprEndAddress[MCAL_CORE0_MEM_SEGMENT - DsprMsb])
    {
      /* Compute Local DSPR address */
      /* [cover parentID={CE9639D9-9374-49f3-950A-A8E65048B103}]Compute
          Local DSPR address[/cover] */
      RetLocalAddress = \
                      ((GlobalDsprAddress & (uint32)MCAL_DSPR_GLOBAL_MASK_N) | \
                         (uint32)MCAL_LOCAL_DSPR_BASE_ADDR);
    }

  }
  else
  {
    /* [cover parentID={26D4B584-E7D8-493b-B524-16A6C479D2BF}]GlobalDspr
        Address belong to memory segment 0xD[/cover] */
    if(DsprMsb == (uint8)MCAL_VALID_DSPR_MSB)
    {
      /* [cover parentID={7056C288-3337-4661-9838-32727B69CAED}]Input
          parameter is valid localDspraddress with executing CPU
          [/cover] */
      if((GlobalDsprAddress & (uint32)MCAL_DSPR_GLOBAL_MASK_N) <= \
          DsprEndAddressIndexBased[CoreIndex])
      {
        /* [cover parentID={A13DD372-FA55-4fa2-9DE6-A9BE2182505B}]
           Return LocalDsprAddress[/cover] */
        RetLocalAddress = GlobalDsprAddress;
      }

    }
  }
  /* [cover parentID={A13DD372-FA55-4fa2-9DE6-A9BE2182505B}]
     Return LocalDsprAddress[/cover] */
  /* [cover parentID={C8838677-BE78-49d8-8448-7EEE5C587AC8}]Return
     LocalDsprAddress 0[/cover] */
  return (RetLocalAddress);
}

/*******************************************************************************
** Traceability     : [cover parentID={3FCAA99A-4260-4c7e-9224-EAE68F1461C6}] **
**                                                                            **
** Syntax           : uint32 Mcal_GetGlobalPsprAddress                        **
**                    (                                                       **
**                     const uint32 CpuId,                                    **
**                     const uint32 LocalPsprAddress                          **
**                    )                                                       **
**                                                                            **
** Description      : This interface is used by applications in a multicore   **
**                    environment to determine the global address of a local  **
**                    PSPR address of a specified CPU. A value 0 is returned  **
**                    in case an invalid input argument is passed             **
**                    (incorrect CpuId, local PSPR address)                   **
**                                                                            **
** Service ID       : 0x0E                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : CpuId - Physical Core ID                                **
**                    LocalPsprAddress - Local PSPR address for which global  **
**                    PSPR address is returned                                **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : 0: Invalid input parameter passed                       **
**                    Else, value returned the Global PSPR address            **
**                    If passed parameter is valid Global PSPR address        **
**                    corresponding to currently executing CPU then routine   **
**                    shall return passed address as is                       **
*******************************************************************************/
uint32 Mcal_GetGlobalPsprAddress
(const uint32 CpuId, const uint32 LocalPsprAddress)
{
  /* Obtain the memory segment information to which
   * LocalPsprAddress belongs to */
  uint8 PsprMsb = \
                 (uint8)((LocalPsprAddress & (uint32)MCAL_PSPR_GLOBAL_MASK) >> \
                          MCAL_SHIFT_UPPER_NIBBLE);
  uint32 RetGlobalAddress = MCAL_INVALID_ARGUMENT;
  uint32 LocalRetAddress = LocalPsprAddress;
  /* [cover parentID={403F7F86-1A80-48c4-A0EA-8E26D88266DB}]
  Compute an PSPR local end address based on available core [/cover] */
  uint32 PsprLocalEndAddress[MCAL_COREID_MAX_VALUE + 1U] =
  {
    MCAL_LOCAL_PSPR0_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 1U )
    MCAL_LOCAL_PSPR1_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 2U )
    MCAL_LOCAL_PSPR2_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 3U )
    MCAL_LOCAL_PSPR3_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 4U )
    MCAL_LOCAL_PSPR4_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 5U )
    MCAL_INVALID_PSPR_ADDR,
    MCAL_LOCAL_PSPR5_END_ADDR
    #endif
    #endif
    #endif
    #endif
    #endif
  };
  /* [cover parentID={10237588-2B06-4bbc-B125-748F470CCF13}]
  Compute an PSPR global end address based on available core
  [/cover] */

  uint32 PsprGlobalEndAddress[MCAL_COREID_MAX_VALUE + 1U] =
  {
    MCAL_PSPR0_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 1U )
    MCAL_PSPR1_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 2U )
    MCAL_PSPR2_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 3U )
    MCAL_PSPR3_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 4U )
    MCAL_PSPR4_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 5U )
    MCAL_INVALID_PSPR_ADDR,
    MCAL_PSPR5_END_ADDR
    #endif
    #endif
    #endif
    #endif
    #endif
  };
  /* [cover parentID={25715C02-92C1-4291-8AF4-673F0029A86B}]
  Compute an PSPR global base address based on available core
  [/cover] */
  uint32 PsprGlobalBaseAddress[MCAL_COREID_MAX_VALUE + 1U] =
  {
    MCAL_PSPR0_BASE_ADDR,
    #if ( MCAL_NO_OF_CORES > 1U )
    MCAL_PSPR1_BASE_ADDR,
    #if ( MCAL_NO_OF_CORES > 2U )
    MCAL_PSPR2_BASE_ADDR,
    #if ( MCAL_NO_OF_CORES > 3U )
    MCAL_PSPR3_BASE_ADDR,
    #if ( MCAL_NO_OF_CORES > 4U )
    MCAL_PSPR4_BASE_ADDR,
    #if ( MCAL_NO_OF_CORES > 5U )
    MCAL_INVALID_PSPR_ADDR,
    MCAL_PSPR5_BASE_ADDR
    #endif
    #endif
    #endif
    #endif
    #endif
  };


  /* Is the input physical CpuId a valid value */
  /* [cover parentID={7107E3A8-43A4-4d74-9810-7883B9E33371}]
  Check if CpuId is not coreId5 and geater than or equal to number of core
  [/cover] */
  if((CpuId != (uint32)MCAL_INVALID_CPU_ID_5) && \
      (CpuId <= (uint32)MCAL_COREID_MAX_VALUE))
  {
    /* Does LocalPsprAddress belong to memory segment 0xC */
    /* [cover parentID={3B145523-EEA5-4b96-9540-53E3228BB612}]Local
        PsprAddress belong to memory segment 0xC[/cover] */
    if (PsprMsb == (uint8)MCAL_VALID_PSPR_MSB)
    {
      /* Is LocalPsprAddress within the PSPR address range */
      /* [cover parentID={E2C43B5E-E279-404a-8AD6-1919A5A32CE7}]Local
         PsprAddress within the PSPR address range[/cover] */
      if (LocalRetAddress <= PsprLocalEndAddress[CpuId])
      {
        /* Compute the Global PSPR address */
        /* [cover parentID={9718F7E1-972D-4d85-B1D3-19833108A29D}]
            Compute GlobalPSPR address[/cover] */
        RetGlobalAddress = \
                (uint32)((LocalRetAddress & (uint32)MCAL_PSPR_GLOBAL_MASK_N) | \
             (((uint32)Mcal_kCoreXMemSegment[CpuId] << MCAL_SHIFT_UPPER_NIBBLE)\
                                     | PsprGlobalBaseAddress[CpuId]));
      }
    }
    else
    {
      /* Validate if PSPR address's memory segment is a
       * valid Global CPUx memory segment */
      /*[cover parentID={D48BCD3E-A39E-41fd-ADE8-80102F454106}]PSPR address
          memory segment is a valid Global CPUx memory segment[/cover] */
      if (PsprMsb == Mcal_kCoreXMemSegment[CpuId])
      {
        LocalRetAddress = (LocalRetAddress & \
                           (uint32)MCAL_PSPR_GLOBAL_MASK_N);
        /* [cover parentID={373CFC21-BBFA-422f-B29A-345340C106B9}]
           Check if local PSPR address is more than or equal to global
           PSPR base address and less than or equal to global PSPR end
           address [/cover] */
        if((LocalRetAddress >= PsprGlobalBaseAddress[CpuId])  &&
            (LocalRetAddress <= PsprGlobalEndAddress[CpuId]))
        {
          /* [cover parentID={14A6F0A2-A944-4aaa-854F-0E8C66FEA20A}]
              Return GlobalPSPR address[/cover] */
          RetGlobalAddress = LocalPsprAddress;
        }
      }
    }
  }
  /* [cover parentID={14A6F0A2-A944-4aaa-854F-0E8C66FEA20A}]Return GlobalPSPR
     address[/cover] */
  /* [cover parentID={B3D4FDB4-1431-4344-8002-3B3FD3DBE383}]Return GlobalPSPR
     address 0[/cover] */
  return (RetGlobalAddress);
}
/*******************************************************************************
** Traceability     : [cover parentID={CD35B780-C410-4f80-98F4-722831388424}] **
**                                                                            **
** Syntax           : uint32 Mcal_GetLocalPsprAddress                         **
**                    (                                                       **
**                     const  uint32 GlobalPsprAddress                        **
**                    )                                                       **
**                                                                            **
** Description      : This API is used by applications in a multicore         **
**                    environment to determine the local CPU address of a     **
**                    global PSPR address of the CPU, this interface is       **
**                    invoked on. A value 0 is returned in case an invalid    **
**                    input argument is passed(incorrect global PSPR address) **
**                                                                            **
** Service ID       : 0x0F                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : GlobalPsprAddress - Global PSPR address                 **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : 0: Invalid input parameter passed                       **
**                    Else, value returned the local PSPR address             **
**                    If passed parameter is valid local PSPR address         **
**                    corresponding to currently executing CPU then routine   **
**                    shall return passed address as is                       **
**                                                                            **
*******************************************************************************/
uint32 Mcal_GetLocalPsprAddress(const uint32 GlobalPsprAddress)
{
  /* Obtain the memory segment information to which
   * GlobalPsprAddress belongs to */
  uint8 PsprMsb = \
                (uint8)((GlobalPsprAddress & (uint32)MCAL_PSPR_GLOBAL_MASK) >> \
                          MCAL_SHIFT_UPPER_NIBBLE);
  uint32 RetLocalAddress = MCAL_INVALID_ARGUMENT;
  uint32 LocalRetAddress = GlobalPsprAddress;
  /* [cover parentID={88AD1AD5-66D4-4114-BC45-CB7F0111D626}]
     Retrieve CPU index[/cover] */
  uint32 CpuIndex = Mcal_GetCpuIndex();

  /* [cover parentID={8D55C24F-2536-4651-B221-B3C2E1DAF6BF}]
      Compute an PSPR global start address based on available core [/cover] */
  uint32 PsprGlobalStartAddress[MCAL_COREID_MAX_VALUE + 1U] =
  {
    MCAL_PSPR0_BASE_ADDR,
    #if ( MCAL_NO_OF_CORES > 1U )
    MCAL_PSPR1_BASE_ADDR,
    #if ( MCAL_NO_OF_CORES > 2U )
    MCAL_PSPR2_BASE_ADDR,
    #if ( MCAL_NO_OF_CORES > 3U )
    MCAL_PSPR3_BASE_ADDR,
    #if ( MCAL_NO_OF_CORES > 4U )
    MCAL_PSPR4_BASE_ADDR,
    #if ( MCAL_NO_OF_CORES > 5U )
    MCAL_INVALID_PSPR_ADDR,
    MCAL_PSPR5_BASE_ADDR
    #endif
    #endif
    #endif
    #endif
    #endif

  };
  /* [cover parentID={C88A6DFC-0AA1-4b7f-92E2-D40B9CEBF72B}]
     Compute an PSPR global end address based on available core[/cover] */
  uint32 PsprGlobalEndAddress[MCAL_COREID_MAX_VALUE + 1U] =
  {
    MCAL_PSPR0_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 1U )
    MCAL_PSPR1_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 2U )
    MCAL_PSPR2_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 3U )
    MCAL_PSPR3_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 4U )
    MCAL_PSPR4_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 5U )
    MCAL_INVALID_PSPR_ADDR,
    MCAL_PSPR5_END_ADDR
    #endif
    #endif
    #endif
    #endif
    #endif

  };
  /* [cover parentID={3A0405BB-A65F-46b5-A4DC-64363E713D9F}]
     Compute an PSPR local end address based on available core [/cover] */
  uint32 PsprLocalEndAddress[MCAL_NO_OF_CORES] =
  {
    MCAL_LOCAL_PSPR0_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 1U )
    MCAL_LOCAL_PSPR1_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 2U )
    MCAL_LOCAL_PSPR2_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 3U )
    MCAL_LOCAL_PSPR3_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 4U )
    MCAL_LOCAL_PSPR4_END_ADDR,
    #if ( MCAL_NO_OF_CORES > 5U )
    MCAL_LOCAL_PSPR5_END_ADDR
    #endif
    #endif
    #endif
    #endif
    #endif
  };

  /* Validate if Global PSPR address's memory segment is a
   * valid CPUx memory segment */
  /* [cover parentID={E45A508B-6870-4523-8C60-3D302AA693A4}]Global PSPR
      address's memory segment is a valid CPUx memory segment[/cover] */
  if ((PsprMsb != (uint8)MCAL_MEM_SEGMENT2_MSB) && \
      (PsprMsb <= (uint8)MCAL_CORE0_MEM_SEGMENT) && \
      (PsprMsb >= Mcal_kCoreXMemSegment[(MCAL_COREID_MAX_VALUE)]))
  {

    LocalRetAddress = (LocalRetAddress & (uint32)MCAL_PSPR_GLOBAL_MASK_N);
    /* Is GlobalPsprAddress within the PSPR address range */
    /* [cover parentID={0A6EDA28-0C9F-4f61-BE7A-CF5254FC561E}]GlobalPspr
        Address within the PSPR address range[/cover] */
    if((LocalRetAddress >= PsprGlobalStartAddress\
        [MCAL_CORE0_MEM_SEGMENT - PsprMsb]) && (LocalRetAddress <= \
            PsprGlobalEndAddress[MCAL_CORE0_MEM_SEGMENT - PsprMsb]))
    {
      /* Compute Local PSPR address */
      /* [cover parentID={2C9717B8-872D-46ac-88C1-195339372B6E}]Compute
         Local PSPR address[/cover] */
      RetLocalAddress = \
                  (uint32)((LocalRetAddress & (uint32)MCAL_PSPR_ADDRESS_MASK_N)\
                                 | (uint32)MCAL_LOCAL_PSPR_BASE_ADDR);
    }
  }
  else
  {
    /* Does GlobalPsprAddress belong to memory segment 0xC */
    /* [cover parentID={49C478D4-2415-4338-B240-445B9CA08490}]GlobalPspr
        Address belong to memory segment 0xC[/cover] */
    if (PsprMsb == (uint8)MCAL_VALID_PSPR_MSB)
    {
      /* Is GlobalPsprAddress a valid local PSPR address belonging
                        to the executing core */
      /* [cover parentID={3A55B630-2EEB-4968-A499-49366CCC5792}]
         GlobalPsprAddress a valid local PSPR address belonging to the
         executing core[/cover] */
      if(LocalRetAddress <= PsprLocalEndAddress[CpuIndex])
      {
        /*[cover parentID={6552A987-2D25-4170-9013-3028CB051E91}]Return
            Local PSPR address[/cover] */
        RetLocalAddress = GlobalPsprAddress;
      }
    }

  }
  /* [cover parentID={6552A987-2D25-4170-9013-3028CB051E91}]Return Local PSPR
    address[/cover] */
  /* [cover parentID={9D170B96-D5E4-46c2-B034-1A6C9734C791}]Return Local PSPR
    address 0[/cover] */
  return (RetLocalAddress);
}

/*******************************************************************************
** Traceability     : [cover parentID={106361C3-AE5B-4684-9B55-96C57BF8AC41}] **
**                                                                            **
** Syntax           : uint32 Mcal_DelayTickResolution (void)                  **
**                                                                            **
** Description      : The interface is used by applications to retrieve in    **
**                    nanoseconds the resolution of the delay tick (STM timer)**
**                                                                            **
** Service ID       : 0x11                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Resolution of STM timer delay tick in nanoseconds       **
**                                                                            **
*******************************************************************************/
uint32 Mcal_DelayTickResolution(void)
{
  /* Return the STM timer resolution is 1ns resolution */
  return (Mcal_StmTimerResolution);
}

/*******************************************************************************
** Traceability     : [cover parentID={06D30CED-D581-4f9d-88B2-BF39C78EA317}] **
**                                                                            **
** Syntax           : uint32 Mcal_DelayResetTickCalibration(void)             **
**                                                                            **
** Description      : The interface is used by applications to indicate to    **
**                    MCALLib that the clock tree has changed. The expectation**
**                    is that as a result of invocation of this service, any  **
**                    internally cached tick resolution data is discarded.    **
**                    This service is expected to query the clock tree and    **
**                    determine the resolution. The interface returns in      **
**                    nanoseconds the resolution of the delay tick (STM timer)**
**                                                                            **
** Service ID       : 0x10                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Resolution of delay tick in nanoseconds                 **
**                                                                            **
*******************************************************************************/
uint32 Mcal_DelayResetTickCalibration(void)
{
  uint32 StmTimerResol;
  /* [cover parentID={2203708E-A73E-4414-AC15-6ECB9D9A5858}]
     Calculate STM timer resolution in 1ns resolution[/cover] */
  StmTimerResol = Mcal_lDelayResetTickCalibration();
  Mcal_StmTimerResolution = (uint32)StmTimerResol;
  /* [cover parentID={F8D3FCA6-8D9A-406c-8E9F-28E04CFBFB5B}]
   Return STM timer resolution[/cover] */
  return (Mcal_StmTimerResolution);
}
/*******************************************************************************
** Traceability     : [cover parentID={B90FF39B-C537-412f-8234-E9B0307B4D62}] **
** [/cover]                                                                   **
** Syntax           : uint32 Mcal_DelayGetTick (void)                         **
**                                                                            **
** Description      : This interface is used by applications to retrieve the  **
**                    latest tick count of the underlying STM timer. The      **
**                    latest tick count in STM0_TIM0 is returned by this      **
**                    interface. There are two uses of this interface.        **
**                    Applications can retrieve a base tick count, add the    **
**                    desired delay to the base tick count and arrive at a    **
**                    terminal tick count. Applications can also then         **
**                    periodically invoke this interface to determine if the  **
**                    underlying timer has counted up to the terminal tick    **
**                    count.                                                  **
**                                                                            **
** Service ID       : 0x12                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Latest lower 32 bit counter value of STM0 timer         **
**                                                                            **
**                                                                            **
*******************************************************************************/
uint32 Mcal_DelayGetTick(void)
{
  /* [cover parentID={4C08C419-6659-4ae1-A70F-A5C8FC62A22B}][/cover] */
  /* Return the latest tick count from STMx_TIM0*/
  return (MODULE_STM0.TIM0.U);
}
/*******************************************************************************
** Traceability     :[cover parentID={1800AF01-292F-4937-B75B-A5A1CD450B30}]  **
**  [/cover]                                                                  **
** Syntax           : uint32 Mcal_GetCpuIndex (uint32 CpuId)                  **
**                                                                            **
** Description      : This interface is used by applications in a multicore   **
**                    environment to determine the CPU they are executing on. **
**                    The API returns the contents of CORE_ID register,       **
**                   variable, structure for the core on which it is invoked. **
**                                                                            **
** Service ID       : 0x0B                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Returns the Core Index corresponding to the input       **
**                    physical Core Id. In case the input Core Id is an       **
**                    invalid value, then the API returns 0xFFFFFFFF          **
**                                                                            **
*******************************************************************************/
uint32 Mcal_GetCpuIndex(void)
{
  /* [cover parentID={EDC5F10B-3F52-4106-AD95-0188FDF4F8B9}]
  Read the CPU_CORE_ID register to retrieve the CoreIdIndex  [/cover] */
  uint32 CoreIdIndex = (uint32)MFCR(CPU_CORE_ID);
  /* [cover parentID={C1AF88CC-E114-4acc-AC3B-CB3FC0189913}]
  MCAL_NO_OF_CORES is greater than 5[/cover] */
  #if ( MCAL_NO_OF_CORES > 5U )
  /* If the CpuId is greater than, equal to that of CPU5 Core Id(0x6U),
   * then return CoreIndex as (CpuId - 1),
   * else return the same value as input CpuId */
  /* [cover parentID={AE523516-C486-444f-8ABA-EB62C5C5A3A0}]
  Check if CoreIdIndex is greater than, equal to number of core [/cover] */
  /* [cover parentID={D6249350-C9DC-44e2-A84C-97251A1AB4EA}]
  return CoreIdIndex as ( CoreIdIndex - 1)[/cover] */
  CoreIdIndex = ((CoreIdIndex >= (uint32)MCAL_NO_OF_CORES) ? \
                 (CoreIdIndex - (uint32)1U) : CoreIdIndex);
  #endif

  return(CoreIdIndex);
}
/*******************************************************************************
** Traceability     : [cover parentID={79233180-2CAD-4a65-A94F-FEB42233EEC0}] **
** [/cover]                                                                   **
** Syntax           : void McalLib_GetVersionInfo                             **
**                                (Std_VersionInfoType* const versioninfo)    **
** Description      : Function "McalLib_GetVersionInfo" shall have means to   **
**                    provide the version information of the MCALLIB module.  **
**                                                                            **
** Service ID       : 0x0                                                     **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters(in)   : versioninfo - Pointer to where to store the version     **
                      information of MCALLIB module.                          **
**                                                                            **
** Parameters (out) : MCALLIB version information                             **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
*******************************************************************************/
void  McalLib_GetVersionInfo(Std_VersionInfoType* const versioninfo)
{
  /* [cover parentID={1B3AF15C-FD6B-43a1-8ACB-D951C425066B}]
     McalLib_GetVersionInfo[/cover] */
  /* [cover parentID={469F845E-C354-42a3-B671-C8CB1FF18715}]
     If SAFETY Error Check is Enabled[/cover] */
  #if (MCALLIB_SAFETY_ENABLE == STD_ON)
  uint8  ErrStatus = E_NOT_OK;
  #endif
  /* [cover parentID={469F845E-C354-42a3-B671-C8CB1FF18715}]
     If SAFETY Error Check is Enabled[/cover] */
  /* [cover parentID={8DE01E71-D128-4972-B0AF-D082246619F6}]
     Error check[/cover] */
  #if (MCALLIB_SAFETY_ENABLE == STD_ON)
  /* [cover parentID={3E0E8009-CCD1-4404-A60B-EDED50CA216F}]
   Check if input parameter is null pointer[/cover] */
  if ((versioninfo) == NULL_PTR)
  {
    /* [cover parentID={64253942-C0B1-4ade-BC23-FAA4429C18A8}]
       Report error MCALLIB_E_PARAM_POINTER[/cover] */
    Mcal_lReportError(MCALLIB_SID_GETVERSIONINFO, MCALLIB_E_PARAM_POINTER);
    ErrStatus = (uint8)E_NOT_OK;
  }
  /* [cover parentID={75420898-D793-4c5f-94E0-2E9C44DA3DEB}]
     Have all check passed?[/cover] */
  else
  {
    ErrStatus = (uint8)E_OK;
  }
  if(ErrStatus == E_OK)
  #endif
  {
    /* [cover parentID={100FDF35-3B62-4c30-9799-B7F79121EF87}]
    Retrieve the version information of the module[/cover] */
    ((Std_VersionInfoType*)(versioninfo))->vendorID = \
        (uint16)MCALLIB_VENDOR_ID;
    /* Get McalLib Module ID */
    ((Std_VersionInfoType*)(versioninfo))->moduleID = \
        (uint16)MCALLIB_MODULE_ID;
    /* Get McalLib module Software major version */
    ((Std_VersionInfoType*)(versioninfo))->sw_major_version = \
        (uint8)MCALLIB_SW_MAJOR_VERSION;
    /* Get McalLib module Software minor version */
    ((Std_VersionInfoType*)(versioninfo))->sw_minor_version = \
        (uint8)MCALLIB_SW_MINOR_VERSION;
    /* Get McalLib module Software patch version */
    ((Std_VersionInfoType*)(versioninfo))->sw_patch_version = \
        (uint8)MCALLIB_SW_PATCH_VERSION;
  }
}

/*******************************************************************************
** Traceability     : [cover parentID={FDC04393-3918-4d1a-BD98-97EB51ACDAB3}] **
** [/cover]                                                                   **
** Syntax           : void Mcal_GetSpinlock                                   **
**                  ( volatile uint32 * const LockAddress,\                   **
**                             const uint32 Timeout)                          **
**                                                                            **
** Description     : This API will check if spinlock is available in an non   **
**                   atomic fashion and if spinlock is free then it is        **
**                   acquired in an atomic fashion acquired else it will      **
**                   try again until the timer tick provided by user is not   **
**                   less than difference between current and base stm ticks. **
** Service ID       : 0x14                                                    **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : LockAddress - It is used to lock the shared variables.  **
**                    Timeout - It is total time provided in micro second by  **
**                              user using which spinlock should be acquired. **
**                              Timeout value should be in range of 1 µs to   **
**                              1048575 µs (timeout when passed as 1 indicate **
**                              as 1 µs to this API).                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None.                                                   **
*******************************************************************************/
/* [cover parentID={58554703-8423-44e3-841C-F530E6124C69}]
Mcal_GetSpinlock[/cover] */
void Mcal_GetSpinlock
(volatile uint32 * const LockAddress, const uint32 Timeout)
{
  uint32 LockVal = SPINLOCKBUSY;
  uint32 LockAddVal;
  uint32 DelayTickResolution;
  uint32 LockAddRet;
  uint32 DelayTicks, BaseSTMTick, CurrSTMTick;
  /* [cover parentID={A6FC0022-BE1B-4764-9527-D4B928AADD62}]
     If SAFETY Error Check is Enabled[/cover] */
  #if (MCALLIB_SAFETY_ENABLE == STD_ON)
  uint8  ErrStatus = E_NOT_OK;
  /* [cover parentID={F361A66A-5290-4fed-ABF2-9547AFB2BBAE}]
     Check if input address is null pointer[/cover] */
  if ((LockAddress) == NULL_PTR)
  {
    /* [cover parentID={49CFCB8A-36C7-4dc0-BD9F-C28247C3EDEC}]
       Report error MCALLIB_E_PARAM_POINTER[/cover] */
    Mcal_lReportError(MCALLIB_SID_GETSPINLOCK, MCALLIB_E_PARAM_POINTER);
    ErrStatus = (uint8)E_NOT_OK;
  }
  /* [cover parentID={A6C42DE8-F567-438d-85B0-E41F29CF91B3}]
     If address is not null pointer [/cover] */
  else
  {
    ErrStatus = (uint8)E_OK;
  }
  /* [cover parentID={A6C42DE8-F567-438d-85B0-E41F29CF91B3}]
     If address is not null pointer [/cover] */
  if(ErrStatus == E_OK)
  #endif
  {
    /* [cover parentID={5CD5C958-4194-4127-AF46-4F54B0B72BAF}]
       Check if DelayTickResolution is zero[/cover] */
    if(Mcal_StmTimerResolution == 0U)
    {
      /* [cover parentID={23D3ADDB-748B-46da-AC7E-D30829A72B7F}]
          Calculate DelayTickResolution using calibration API[/cover] */
      DelayTickResolution = Mcal_lDelayResetTickCalibration();
    }
    /* [cover parentID={E159CA47-30EC-4c7a-9135-5AA48C37F85B}]
    DelayTickResolution is equal to Mcal_StmTimerResolution[/cover] */
    else
    {
      DelayTickResolution = Mcal_StmTimerResolution;
    }
    /* [cover parentID={3E2841FF-49D6-4f7f-9AA6-6F04797DDFB3}]
       check if delaytick resolution is zero [/cover] */
    if(DelayTickResolution == 0U)
    {
      /* [cover parentID={F7EE891A-BF3E-4b27-9EE6-03BEE60A54DF}]
      Delay tick is zero[/cover] */
      DelayTicks = 0U;
    }
    /* [cover parentID={53455069-47DE-4f99-A0D2-516F81AE00A7}]
       Calculate delay tick using delay tick resolution[/cover] */
    else
    {
      DelayTicks = ((Timeout / DelayTickResolution) * MCAL_TIMEOUT);
    }
    CurrSTMTick         = Mcal_DelayGetTick();
    BaseSTMTick         = CurrSTMTick;
    do
    {
      LockAddVal = *LockAddress;
      /* [cover parentID={D9F90DA5-757B-4f95-877D-FA451C80C175}]
      Loop untill the lock address is free  for a specified timeout in a
      non-atomic fashion[/cover] */
      /* [cover parentID={67A0CB3C-042E-4282-8A76-4DEBFBA2C290}]
        Loop if spinlock is busy and if difference between current and
        base STM ticks is less than delay ticks[/cover] */
      /* [cover parentID={EC4F192C-1733-4e10-B474-23092DE01F1E}] If
      spinlock is not acquired and if difference between current and base
      STM ticks is less Than delay ticks[/cover] */
      while(((uint32)(CurrSTMTick - BaseSTMTick) < DelayTicks) && \
            (LockAddVal != (uint32)SPINLOCKFREE))
      {
        /* [cover parentID={49709B70-3945-4cb6-A0EE-468F3D428C2E}]Read
         the current STM tick from STM.TIM0 register[/cover] */
        CurrSTMTick       = Mcal_DelayGetTick();
        LockAddVal = *LockAddress;
      }
      /* MISRA2012_RULE_11_3_JUSTIFICATION: Intrinsic function used for
       compare swap which require pointer conversion, no side effect seen
        as pointer passed is always 32-bit aligned*/
      /* MISRA2012_RULE_11_5_JUSTIFICATION: Intrinsic function used for
       compare swap which require pointer conversion, no side effect seen
       as pointer passed is always 32-bit aligned*/
      /* MISRA2012_RULE_11_8_JUSTIFICATION: Intrinsic function used for
       compare swap which require removing of volatile from pointer, no
       side effect seen as pointer passed is always 32-bit aligned*/
      /* MISRA2012_RULE_4_6_JUSTIFICATION: Basic numerical type - int/
         unsigned int is used while invoking compiler intrinsic functions.
         These compiler intrinsic functions are implemented specific to
         tricore.*/
      LockAddRet = Mcal_CmpAndSwap(LockAddress, LockVal, SPINLOCKFREE);
      /* [cover parentID={B521C11D-9E91-45d3-BEA8-881B2F74641C}]Compare
       if Lock address is free and than acquire the lock in an atomic
       fashion if difference between current and base STM ticks is less
       than delay ticks[/cover] */
    } while(
      (LockAddRet != (uint32)SPINLOCKFREE) && \
      (((CurrSTMTick - BaseSTMTick) < DelayTicks)));
    /* [cover parentID={F7B55E1F-6FC0-4e17-8334-F6412638E26B}]
    If SAFETY Error Check is Enabled */
    #if (MCALLIB_SAFETY_ENABLE == STD_ON)
    /* [cover parentID={EB6435DE-D9D6-4a8e-AC88-6DA0BD229680}]
     Check if lockvalue is busy[/cover] */
    if((LockAddRet != (uint32)SPINLOCKFREE) && \
        (((CurrSTMTick - BaseSTMTick) >= DelayTicks)))
    {
      /* [cover parentID={B553BE58-F292-4561-9956-BB24BB85515D}]
          Report error MCALLIB_E_TIMEOUT_FAILED[/cover] */
      Mcal_lReportError(MCALLIB_SID_GETSPINLOCK, MCALLIB_E_TIMEOUT_FAILED);
    }
    /* [/cover] */
    #endif
  }
  return;
  /* [cover parentID={4B47E363-544B-4df0-84DF-79CDF97925AF}]
     ActivityFinal[/cover] */
}

/*******************************************************************************
** Traceability     : [cover parentID={87DDCCC6-8C0A-4942-B49F-A3BABA4BFCA2}] **
** [/cover]                                                                   **
** Syntax           : void Mcal_ReleaseSpinlock                               **
**                               (volatile uint32 * const LockAddress)        **
**                                                                            **
** Description     : This API will release the Spinlock and value of lock     **
                     address will be 0x0U.                                    **
**                                                                            **
**                                                                            **
** Service ID      : 0x15                                                     **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : Non Reentrant                                            **
**                                                                            **
** Parameters(in)   : Lock Address                                            **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : void                                                    **
**                                                                            **
*******************************************************************************/
void Mcal_ReleaseSpinlock(volatile uint32 * const LockAddress)
{
  /* [cover parentID={1CE56696-4A08-4fca-ADF7-6443897F9F9A}]
     If SAFETY Error Check is Enabled[/cover] */
  #if (MCALLIB_SAFETY_ENABLE == STD_ON)
  uint8  ErrStatus = E_NOT_OK;
  /* [cover parentID={E8246BFE-9198-46ec-989E-075408125C86}]
     Check if input address is null pointer[/cover] */
  if ((LockAddress) == NULL_PTR)
  {
    /* [cover parentID={A3DF5750-8B9E-43dc-8859-853BADDD7CEA}]
        Report error MCALLIB_E_PARAM_POINTER[/cover] */
    Mcal_lReportError(MCALLIB_SID_RELSPINLOCK, MCALLIB_E_PARAM_POINTER);
    ErrStatus = (uint8)E_NOT_OK;
  }
  /* [cover parentID={3B173FA2-D1EF-49f7-B05E-6E14223B735D}]
     If address is not null pointer [/cover] */
  else
  {
    ErrStatus = (uint8)E_OK;
  }
  /* [cover parentID={3B173FA2-D1EF-49f7-B05E-6E14223B735D}]
     If address is not null pointer [/cover] */
  if(ErrStatus == E_OK)
  #endif
  {
    *LockAddress = (uint32)SPINLOCKFREE;
  }
}

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : LOCAL_INLINE uint32  Mcal_lCpuPwSequence                **
**                    (                                                       **
**                      const uint32 CpuIndex,                                **
**                      const uint32 WdtCpuCon0Value                          **
**                    )                                                       **
**                                                                            **
** Description      : This function returns the password to be used during    **
**                    ‘password access’ of WDTCPUxCON0 to unlock the register **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : CpuIndex -  CpuIndex corresponding to CPU Core Id       **
**                    WdtCpuCon0Value -  Contents of register WDTCPUxCON0     **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : password to be written to WDTCPUxCON0 to unlock it      **
**                                                                            **
*******************************************************************************/

LOCAL_INLINE uint32  Mcal_lCpuPwSequence
(const uint32 CpuIndex, const uint32 WdtCpuCon0Value)
{
  uint32 PwdBit0Value;

  /* [cover parentID={B44279C3-41FF-4e95-8F82-33919982A41E}]
  Decrypt the password extracted from WdtCpuCon0 reg[/cover] */
  uint32 Password = Mcal_lDecryptPw(WdtCpuCon0Value);

  /* Check if Auto sequence password is enabled */
  /* [cover parentID={8764C622-562B-499e-BF57-7F467B553FCF}]
     Check if Automatic password sequencing is enable[/cover] */
  if (Mcal_GetBitAtomic(MODULE_SCU.WDTCPU[CpuIndex].SR.U, \
                      IFX_SCU_WDTCPU_SR_PAS_OFF, IFX_SCU_WDTCPU_SR_PAS_LEN) == \
      MCAL_AUTO_PWD_SEQ_ENABLED)
  {
    /*  Modify the password with expected password by calculating new
     *  14-bit LFSR with characteristic polynomial x14+x13+x12+x2+1.*/
    /* [cover parentID={C5E54F01-B967-4f08-BB1D-6147BE98DEAE}]
    Calculate the next password based upon a 14 bit ‘Linear Feedback Shift
    Register’ .[/cover] */
    PwdBit0Value = (((Password >> 1U) ^ (Password >> MCAL_PASSEQSHIFT) ^\
                     (Password >> MCAL_PASSWORD_SHIFT) ^\
                     (Password >> MCAL_LFSR_SHIFT)) & (uint32)1U);

    Password = (((Password << 1U) | PwdBit0Value ) & \
                (uint32)IFX_SCU_WDTCPU_CON0_PW_MSK);
  }
  /* [cover parentID={A3754FD3-C09F-48d8-BF9C-D11CD9E3BC51}]
     Return the password without modification[/cover] */
  /* [cover parentID={56281BA0-25B6-45a7-AB4E-FFE889986FC4}]
    Return password[/cover] */
  return (Password);
}

/*******************************************************************************

** Traceability     :                                                         **
**                                                                            **
** Syntax           : LOCAL_INLINE uint32 Mcal_lCpuRelValue                   **
**                    (                                                       **
**                      const uint32 CpuIndex,                                **
**                      const uint32 WdtCpuCon0Value                          **
**                    )                                                       **
**                                                                            **
** Description      : This function returns the timer reload value to be used **
**                    during ‘password access’ of WDTCPUxCON0 to unlock the   **
**                    register                                                **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : CpuIndex -  CpuIndex corresponding to CPU Core Id       **
**                    WdtCpuCon0Value -  Contents of register WDTCPUxCON0     **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : timer reload value  to be written to WDTCPUxCON0 to     **
**                    unlock it                                               **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 Mcal_lCpuRelValue
(const uint32 CpuIndex, const uint32 WdtCpuCon0Value)
{
  uint32 TimerReload;
  /* Is Timer check enabled */
  /* [cover parentID={D511EF7F-5C92-4103-98CF-A5F8EC01DA99}]
   Check If  WDTCPUxSR register TCS bit is enable[/cover] */
  if (Mcal_GetBitAtomic( \
                         MODULE_SCU.WDTCPU[CpuIndex].SR.U, \
                         IFX_SCU_WDTCPU_SR_TCS_OFF, \
                         IFX_SCU_WDTCPU_SR_TCS_LEN) == MCAL_TIMER_CHECK_ENABLED)
  {
    /* Compute Timer reload value based on the inverted value of
     * running WDT timer value */
    /* [cover parentID={D1B6CC5D-442B-4413-9887-CFCBFCBBA7AF}]
     Timer reload value give inverted value of current timer value obtain
      from WDTCPUxSR.TIM [/cover] */
    TimerReload = (((MODULE_SCU.WDTCPU[CpuIndex].SR.U) & \
                    MCAL_CPUWDTSR_TIMER_MASK) \
                   >> IFX_SCU_WDTCPU_SR_TIM_OFF);
    TimerReload = ((~TimerReload) & (uint32)IFX_SCU_WDTCPU_SR_TIM_MSK);
  }
  /* [cover parentID={81383C2C-9BA0-4b49-B811-EB98942760DC}]
    From input WDTCPUxCON0 extract timer reload value [/cover] */
  else
  { /* [cover parentID={81383C2C-9BA0-4b49-B811-EB98942760DC}]
    From input WDTCPUxCON0 extract timer reload value [/cover] */
    /* Compute Timer reload value based on the current timer reload value */
    TimerReload = ((WdtCpuCon0Value & (uint32)MCAL_ENDINIT_RELOAD_MASK) \
                   >> IFX_SCU_WDTCPU_CON0_REL_OFF);
  }
  /* [cover parentID={978E3EE6-83B3-4387-BB63-1AD7D2E83877}]
     Return timer reload value[/cover] */
  return (TimerReload);
}
/*******************************************************************************
** Traceability     :                                                         **
**                                                                            **
** Syntax           : LOCAL_INLINE uint16 Mcal_lDecryptPw                     **
**                    (                                                       **
**                      const uint32 Value                                    **
**                    )                                                       **
**                                                                            **
** Description      : This function returns the decrypted password, which is  **
**                    used to in unlocking the ENDINIT registers              **
**                    (EICON0/SEICON0/WDTCPUxCON0)                            **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : Value -  Data from which password is extracted          **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : the decrypted password                                  **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint16 Mcal_lDecryptPw(const uint32 Value)
{
  /* Decrypt the password, by extract password from positions [15:2], and
   * inverting the last 6 bits on the extracted password
   */
  return((uint16)(((Value & (uint32)MCAL_ENDINIT_WDT_PWD_MASK) >> \
                   IFX_SCU_WDTCPU_CON0_PW_OFF) ^ \
                  (uint32)MCAL_ENDINIT_WDT_PWD_INV));
}

/*******************************************************************************
** Traceability     : [cover parentID=]                                       **
**                                                                            **
** Syntax           : void Mcal_lWriteSafetyEndInitProtection                 **
                      ( volatile void* const RegAddress,                      **
                        const uint32 DataValue,                               **
                        const uint32 Mask)                                    **
**                                                                            **
** Description      : This API is needed to write required values to safety   **
**                    end-init protected registers by unprotecting to write   **
**                    and protecting back to keep protection intact           **
**                                                                            **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : RegAddress - Safety Endinit protected register address  **
**                    DataValue - Value to be written to the register located **
**                    at RegAddress.                                          **
**                    Mask - Value to indicate which register bits need       **
**                    to be updated.                                          **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE void Mcal_lWriteSafetyEndInitProtection
( volatile void* const RegAddress, const uint32 DataValue, const uint32 Mask)

{
  uint32 Password;
  uint32 Seicon0Value;
  /* The variable 'dummy' is made volatile to prevent any optimization of the
   * variable during compilation, since the variable is used only for read
   * back of ENDINIT control registers, after the same register is written in
   * the previous statement
   */
  volatile uint32 dummy;
  /* MISRA2012_RULE_11_5_JUSTIFICATION: SFR access. No side effects foreseen
    by violating this MISRA rule.*/
  /* MISRA2012_RULE_11_3_JUSTIFICATION: Conversion between
     pointers of different object types due to SFR access. */
  volatile uint32* const RegAddress0 = RegAddress;

  /* Critical section to protect SCU_SEICON0 and SCU_SEICON1 register*/
  /* [cover parentID={FD315CB5-7A55-4a5a-A03E-CA38993CA5FF}]
     Enter critical section for write safety endinit protection reg
     [/cover] */
  /*[cover parentID={58B33909-7455-49a5-8259-C7144939461B}][/cover] */
  SchM_Enter_McalLib_SafetyEndInit();
  /* [cover parentID={BB2B86C5-BDB8-48f4-996F-D3AA2193C106}]
     Acquire the lock for SCU_SEICON0 register[/cover] */
  Mcal_GetSpinlock(&Mcal_LockAddressSiecon0, \
                   (uint32)MCAL_SPINLOCK_DEFAULT_TIMEOUT);

  /* Calculate the password from the retrieved SCU_SEICON0 register */
  /* [cover parentID={3D568050-A94B-47e8-A8CA-29C7091926F1}]
     Retrieved the decrypted password from  SCU_SEICON0 register [/cover] */
  Password = Mcal_lDecryptPw((uint32)(MODULE_SCU.SEICON0.U));
  /* Calculate the value to be written in SCU_SEICON0, to unlock it */
  /* [cover parentID={92B9CEC9-4CE0-464c-9510-6E7790FB3221}] Compute the
     SEICON0 register value to Disable the ENDINIT protection[/cover] */
  Seicon0Value = ((uint32)MCAL_SAFETY_ENDINIT_WDT_TIMER_REL | \
                  ((uint32)Password << (uint32)IFX_SCU_SEICON0_EPW_OFF));
  /* Unlock the SCU_SEICON0 register to disable ENDINIT protection */
  MODULE_SCU.SEICON0.U = Seicon0Value;
  /* [cover parentID={4CD44660-92EA-4bac-BF36-601CA95F5513}]
    Read back the SEICON0  reg to ensure Write is is done correctly.[/cover]*/
  dummy = MODULE_SCU.SEICON0.U;
  /* [cover parentID={BA9E20D4-6E4D-4786-89D4-0B74E521F38E}]Update
   the safety endinit protected register with mask data value[/cover] */
  *RegAddress0 = \
         (uint32)(((uint32) * RegAddress0 & (uint32)~Mask) | (uint32)DataValue);

  /* Calculate the value to be written in SCU_SEICON0,
   * to enable protection of Safety ENDINIT protected registers */
  /* [cover parentID={E34E71D3-B81E-4301-9FEC-DAC0F75DEFDD}] Compute
  the SEICON0 register value to Re-enable the ENDINIT protection[/cover] */
  Seicon0Value = \
                 ((uint32)MCAL_SAFETY_ENDINIT_WDT_TIMER_REL | \
                  ((uint32)Password << (uint32)IFX_SCU_SEICON0_EPW_OFF) | \
                  ((uint32)MCAL_SAFETY_ENDINIT_PROTECTED << \
                   IFX_SCU_SEICON0_ENDINIT_OFF));

  /* Update the SCU_SEICON0 to enable ENDINIT protection */
  /* [cover parentID={2C485262-44B8-4978-82FA-8AD1B2F95121}]
     Re-enable the ENDINIT protection[/cover] */
  MODULE_SCU.SEICON0.U = Seicon0Value;
  /* [cover parentID={5E3A260F-E948-40ca-8426-BDDFD30BD032}]
   Read back the SEICON0  reg to ensure Write is is done correctly.[/cover] */
  dummy = MODULE_SCU.SEICON0.U;
  /* [cover parentID={0B8FB1AC-ADDD-489f-A57F-B19339932CB0}]
      Release the lock for SCU_SEICCON0 register[/cover] */
  Mcal_ReleaseSpinlock(&Mcal_LockAddressSiecon0);
  /* [cover parentID={47D510AB-F328-415b-889F-A9D32E5F686E}]
      Exit critical section[/cover] */
  SchM_Exit_McalLib_SafetyEndInit();


  UNUSED_PARAMETER(dummy);
}
/*******************************************************************************
** Traceability     : [cover parentID={1CCEB859-15A4-4d14-98E6-0191C58E03B5}] **
**                                                                            **
** Syntax           :LOCAL_INLINE uint32 Mcal_lDelayResetTickCalibration(void)**
**                                                                            **
** Description      : The interface is used by applications to indicate to    **
**                    MCALLib that the clock tree has changed. The expectation**
**                    is that as a result of invocation of this service, any  **
**                    internally cached tick resolution data is discarded.    **
**                    This service is expected to query the clock tree and    **
**                    determine the resolution. The interface returns in      **
**                    nanoseconds the resolution of the delay tick (STM timer)**
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non Reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Resolution of delay tick in nanoseconds                 **
**                                                                            **
*******************************************************************************/
LOCAL_INLINE uint32 Mcal_lDelayResetTickCalibration(void)
{
  /* [cover parentID={0245DED7-5AFC-4f35-876D-AEC5118EE056}]
      Enter critical section[/cover] */
  SchM_Enter_McalLib_StmTimerResolution();

  uint8 StmDiv     = (uint8)(((uint32)MODULE_SCU.CCUCON0.U)  & \
                             (uint32)IFX_SCU_CCUCON0_STMDIV_MSK);

  uint8 Src0ClkSel = (uint8)((((uint32)MODULE_SCU.CCUCON0.U) >> \
                              IFX_SCU_CCUCON0_CLKSEL_OFF) & \
                             (uint32)IFX_SCU_CCUCON0_CLKSEL_MSK);

  uint8 PLL0Ndiv   = (uint8)((((uint32)MODULE_SCU.SYSPLLCON0.U) >> \
                              IFX_SCU_SYSPLLCON0_NDIV_OFF) & \
                             (uint32)IFX_SCU_SYSPLLCON0_NDIV_MSK) + (uint8)1U;

  uint8 PLL0Pdiv   = (uint8)((((uint32)MODULE_SCU.SYSPLLCON0.U) >> \
                              IFX_SCU_SYSPLLCON0_PDIV_OFF) & \
                             (uint32)IFX_SCU_SYSPLLCON0_PDIV_MSK) + (uint8)1U;

  uint8 PLL0K2div  = (uint8)(((uint32)MODULE_SCU.SYSPLLCON1.U) & \
                             (uint32)IFX_SCU_SYSPLLCON1_K2DIV_MSK) + (uint8)1U;

  uint8 Oscval     = (uint8)((((uint32)MODULE_SCU.OSCCON.U) >> \
                              IFX_SCU_OSCCON_OSCVAL_OFF) & \
                             (uint32)IFX_SCU_OSCCON_OSCVAL_MSK);

  uint8 PLL0ClkSel = (uint8)((((uint32)MODULE_SCU.SYSPLLCON0.U) >> \
                              IFX_SCU_SYSPLLCON0_INSEL_OFF) & \
                             (uint32)IFX_SCU_SYSPLLCON0_INSEL_MSK);

  /* [cover parentID={AABD4D00-A372-4e29-B360-0543BA412484}]
     Exit critical Section[/cover] */
  SchM_Exit_McalLib_StmTimerResolution();
  uint32 OscFreq;
  float32 StmFreq, PLL0Freq;
  float32 LocalStmTimerResol = (float32)0;


  /* If fSTM is disabled, then return timer resolution as 0 */
  /* [cover parentID={9AEC7374-8E25-4936-AA51-224738F39F36}]
      Check if STM clock disabled[/cover] */
  if(StmDiv == (uint8)MCAL_STMCLK_DISABLED)
  {
    /* [cover parentID={7DB1FA52-2712-4daa-8EB3-5D3BF1CBF02D}]If SAFETY
        Error Check is Enabled[/cover] */
    /* [cover parentID={96699695-17F2-4fa8-AC73-49A2C470DC33}]If SAFETY
        Error Check is Enabled[/cover] */
    /* [cover parentID={21BC6F5D-85A7-4d5a-BFBB-C782B3FEC56B}]If SAFETY
        Error Check is Enabled[/cover] */
    #if (MCALLIB_SAFETY_ENABLE == STD_ON)
    /* [cover parentID={8A536F85-CDD2-4a3d-AF62-D1744ABCD2CF}]
    Report error MCALLIB_E_CLKDISABLE[/cover] */
    Mcal_lReportError(MCALLIB_SID_DELAYTICKRESOLUTION, \
                      MCALLIB_E_CLKDISABLE);
    #endif
    /* [cover parentID={19F230D8-6462-4c4d-9833-2618D4960F84}]
       return STM timer resolution zero[/cover] */
    Mcal_StmTimerResolution = MCAL_STM_TIMER_RESOL_ZERO;
  }
  else
  {
    /* Check the source of fSource0 - PLL0 or backup clock */
    /* [cover parentID={344D24C2-972E-432e-8A0A-9ED87525D74A}]
       Check the Source of freq PLL0 clock sel[/cover] */
    if(Src0ClkSel == (uint8)MCAL_PLL0_CLK_SRC0_FREQ)
    {
      /* Check the source of fPLL0 - System clock or backup clock or OSC0*/
      /* [cover parentID={344D24C2-972E-432e-8A0A-9ED87525D74A}]
         Check the Source of freq PLL0 clock sel[/cover] */
      switch(PLL0ClkSel)
      {
        /* [cover parentID={5EB344C3-9A2B-4bca-92AA-9B89A1FE3DDA}]
            Is PLL0 clock source Osc 0 clock [/cover] */
        case MCAL_OSC0_CLK_PLL0_FREQ:
          /* Calculate OSC0 frequency(its in MHz)*/
          /* [cover parentID={2073EAEB-1D43-47da-A1B4-608B3846D17A}]Calculate
             OSC_ClockFreq [/cover] */
          OscFreq = ((uint32)Oscval + \
                     (uint32)MCAL_OSCVAL_MHz - (uint32)MCAL_OSCFREQ_MHz);
          break;
        default:
          /* [cover parentID={B8FBCFA9-AACF-4dbe-8D8F-AD75CFEE3751}]
                     OSC_ClockFreq is Backup Clock frequency[/cover] */
          OscFreq = MCAL_BACKUP_FREQUENCY;
          break;
      }
      /* Calculate PLL0 freq by formula = (fOSC * Ndiv)/(K2div * Pdiv)*/
      /* [cover parentID={DEC7141C-7011-422c-8C9E-4B270FE50403}]Calculate
         PLL0_Clockfreq using Oscfreq,Ndiv, Pdiv, K2div[/cover] */
      PLL0Freq = (((float32)OscFreq * (float32)PLL0Ndiv) / \
                  ((float32)PLL0Pdiv * (float32)PLL0K2div));
      /* Calculate fSTM */
      /* [cover parentID={CE793E76-8F55-4fc5-9B98-CA024C14371D}]Calculate
      Stm_Freq using PLL0_Clockfreq ,StmDiv[/cover] */
      StmFreq = PLL0Freq / (float32)StmDiv;
    }
    else
    {
      /* Calculate fSTM */
      /* [cover parentID={3E42C595-B418-4c0f-9181-5D89C75125C1}]
      Calculate STM freq depends on Backup Clock freq and STM divider
      [/cover] */
      StmFreq = (float32)MCAL_BACKUP_FREQUENCY / (float32)StmDiv;
    }

    /* Mcal_StmTimerResolution in 1ns resolution is obtained by
     * (10^9)/(StmFreq * 10^6), since value of StmFreq is MHz,
     *  Mcal_StmTimerResolution = 10^9/(StmFreq * 10^6)
     *  Mcal_StmTimerResolution = 10^3/(StmFreq)
     */
    /* [cover parentID={205F9729-B78C-4ff6-B5A4-4CF0A0512ABD}]Calculate STM
    timer resolution in 1ns resolution[/cover] */
    LocalStmTimerResol = ((float32)MCAL_RESOLUTION_U / StmFreq);
  }
  /* [cover parentID={E1412D6E-B1C5-4683-AEFA-730560F0772F}]
     Return STM timer resolution[/cover] */
  /* [cover parentID={19F230D8-6462-4c4d-9833-2618D4960F84}]
     return STM timer resolution zero[/cover] */
  return ((uint32)LocalStmTimerResol);
}
#if (MCALLIB_SAFETY_ENABLE == STD_ON)
/*******************************************************************************
** Traceability      :[cover parentID=]                                       **
**                                                                            **
** Syntax :          static void Mcal_lReportError( const uint8 ApiId,        **
**                                          const uint8 ErrorId)              **
**                                                                            **
**                                                                            **
** Service ID:       None                                                     **
** [/cover]                                                                   **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       Reentrant                                                **
**                                                                            **
** Parameters (in):  ApiId - Service ID of the API reporting an error         **
**                   ErrorId - ID of the error reported                       **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
** Description :    Function to report Safety Error                           **
*                                                                             **
*******************************************************************************/
static void Mcal_lReportError(const uint8 ApiId, const uint8 ErrorId)
{
  /* [cover parentID={1ED24B5B-7C99-4b40-8ACA-6BE2E491699F}]
      Is Safety Enable[/cover] */
  #if (MCALLIB_SAFETY_ENABLE == STD_ON)
  /* [cover parentID={BD0CD7D9-C226-4a66-95A5-FD5A391A776B}]
      Mcal Safety Error[/cover] */
  Mcal_ReportSafetyError(MCALLIB_MODULE_ID, MCALLIB_INSTANCE_ID, \
                         ApiId, ErrorId);
  /* End of report to Safety */
  #endif
}
#endif
/*[cover parentID={4579FE20-92DA-4848-93DB-7AD4FD35DD50}]Memory mapping for
   code[/cover]*/
#define MCALLIB_STOP_SEC_CODE_ASIL_B_GLOBAL

/* MISRA2012_RULE_4_10_JUSTIFICATION: 'McalLib_MemMap.h' is header file which
 * contains the memory sections for McalLib. It should not be guarded by
 * standard include. No side effects foreseen by violating this MISRA rule. */

/* MISRA2012_RULE_20_1_JUSTIFICATION: variable 'Mcal_StmTimerResolution'
 * declared before MemMap header file. This variable needs to be placed in a
 * appropriate memory section. No side effects foreseen by violating
 * this MISRA rule */
#include "McalLib_MemMap.h"
