/*****************************************************************************
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
**  FILENAME  : Mcu_17_TimerIp_Cfg.c                                          **
**                                                                            **
**  VERSION   : 8.0.0                                                         **
**                                                                            **
**  DATE, TIME: 2023-03-21, 20:00:22                                      **
**                                                                            **
**  GENERATOR : Build b170330-0431                                          **
**                                                                            **
**  BSW MODULE DECRIPTION : Mcu.bmd                                           **
**                                                                            **
**  VARIANT   : Variant PB                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION :  Timer IP user configuration generated out of ECUC file     **
**                                                                            **
**  SPECIFICATION(S) : NA                                                     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                            Includes                                        **
*******************************************************************************/
/* Include module header file */
#include "Mcu_17_TimerIp_Cfg.h"


/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define MCU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header included as per Autosar
guidelines. */
#include "Mcu_MemMap.h"

/* MISRA2012_RULE_8_4_JUSTIFICATION: The
declaration for Mcu_17_Eru_ChUserData is present in Mcu_17_TimerIp.c.
No side effects foreseen by violating this MISRA rule. */
/* MISRA2012_RULE_8_9_JUSTIFICATION: This constant is made used in ISRs
defined in Mcu_17_TimerIp.c for the channel user information. The
declaration for the same is present in Mcu_17_TimerIp.c. Hence can't
be made block scope. No side effects foreseen by violating this MISRA rule. */
const uint32 Mcu_17_Eru_ChUserData[MCU_17_ERU_NO_OF_OGU] =
{
  0x00000000,
  0x00000000,
  0x00000000,
  0x00000000,
  0x00000000,
  0x00000000,
  0x00000000,
  0x00000000
};

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define MCU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header included as per Autosar
guidelines. */
#include "Mcu_MemMap.h"

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define MCU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_16
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header included as per Autosar
guidelines. */
#include "Mcu_MemMap.h"

const uint16
/* MISRA2012_RULE_8_4_JUSTIFICATION: The
declaration for Mcu_17_Gtm_AtomChUserData is present in Mcu_17_TimerIp.c.
No side effects foreseen by violating this MISRA rule. */
/* MISRA2012_RULE_8_9_JUSTIFICATION: This constant is made used in ISRs
defined in Mcu_17_TimerIp.c for the channel user information. The
declaration for the same is present in Mcu_17_TimerIp.c. Hence can't
be made block scope. No side effects foreseen by violating this MISRA rule. */
Mcu_17_Gtm_AtomChUserData[MCU_17_GTM_NO_OF_ATOM_MODULES][MCU_17_GTM_NO_OF_ATOM_CHANNELS] =
{
  /* ATOM Module 0 */
  {
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000
  },
  /* ATOM Module 1 */
  {
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000
  },
  /* ATOM Module 2 */
  {
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000
  },
  /* ATOM Module 3 */
  {
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000
  },
  /* ATOM Module 4 */
  {
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000
  },
  /* ATOM Module 5 */
  {
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000
  },
  /* ATOM Module 6 */
  {
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000
  },
  /* ATOM Module 7 */
  {
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000
  },
  /* ATOM Module 8 */
  {
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000
  },
  /* ATOM Module 9 */
  {
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000
  },
  /* ATOM Module 10 */
  {
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000
  },
  /* ATOM Module 11 */
  {
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000
  }
};

const uint16
/* MISRA2012_RULE_8_4_JUSTIFICATION: The
declaration for Mcu_17_Gtm_TimChUserData is present in Mcu_17_TimerIp.c.
No side effects foreseen by violating this MISRA rule. */
/* MISRA2012_RULE_8_9_JUSTIFICATION: This constant is made used in ISRs
defined in Mcu_17_TimerIp.c for the channel user information. The
declaration for the same is present in Mcu_17_TimerIp.c. Hence can't
be made block scope. No side effects foreseen by violating this MISRA rule. */
Mcu_17_Gtm_TimChUserData[MCU_17_GTM_NO_OF_TIM_MODULES][MCU_17_GTM_NO_OF_TIM_CHANNELS] =
{
  /* TIM Module 0 */
  {
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000
  },
  /* TIM Module 1 */
  {
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000
  },
  /* TIM Module 2 */
  {
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000
  },
  /* TIM Module 3 */
  {
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000
  },
  /* TIM Module 4 */
  {
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000
  },
  /* TIM Module 5 */
  {
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000
  },
  /* TIM Module 6 */
  {
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000
  },
  /* TIM Module 7 */
  {
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000
  }
};

const uint16
/* MISRA2012_RULE_8_4_JUSTIFICATION: The
declaration for Mcu_17_Gtm_TomChUserData is present in Mcu_17_TimerIp.c.
No side effects foreseen by violating this MISRA rule. */
/* MISRA2012_RULE_8_9_JUSTIFICATION: This constant is made used in ISRs
defined in Mcu_17_TimerIp.c for the channel user information. The
declaration for the same is present in Mcu_17_TimerIp.c. Hence can't
be made block scope. No side effects foreseen by violating this MISRA rule. */
Mcu_17_Gtm_TomChUserData[MCU_17_GTM_NO_OF_TOM_MODULES][MCU_17_GTM_NO_OF_TOM_CHANNELS] =
{
  /* TOM Module 0 */
  {
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000
  },
  /* TOM Module 1 */
  {
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000
  },
  /* TOM Module 2 */
  {
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000
  },
  /* TOM Module 3 */
  {
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000
  },
  /* TOM Module 4 */
  {
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000
  },
  /* TOM Module 5 */
  {
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000
  }
};
const uint16
/* MISRA2012_RULE_8_4_JUSTIFICATION: The
declaration for Mcu_17_Ccu6_ChUserData is present in Mcu_17_TimerIp.c.
No side effects foreseen by violating this MISRA rule. */
/* MISRA2012_RULE_8_9_JUSTIFICATION: This constant is made used in ISRs
defined in Mcu_17_TimerIp.c for the channel user information. The
declaration for the same is present in Mcu_17_TimerIp.c. Hence can't
be made block scope. No side effects foreseen by violating this MISRA rule. */
Mcu_17_Ccu6_ChUserData[MCU_17_CCU6_NO_OF_KERNELS][MCU_17_CCU6_NO_OF_COMPARATORS] =
{
  {
  0x0000,
  0x0000,
  0x0000,
  0x0000
  },
  {
  0x0000,
  0x0000,
  0x0000,
  0x0000
  }
};

/* MISRA2012_RULE_8_4_JUSTIFICATION: The
declaration for Mcu_17_Gpt12_ChUserData is present in Mcu_17_TimerIp.c.
No side effects foreseen by violating this MISRA rule. */
/* MISRA2012_RULE_8_9_JUSTIFICATION: This constant is made used in ISRs
defined in Mcu_17_TimerIp.c for the channel user information. The
declaration for the same is present in Mcu_17_TimerIp.c. Hence can't
be made block scope. No side effects foreseen by violating this MISRA rule. */
const uint16 Mcu_17_Gpt12_ChUserData[MCU_17_GPT12_NO_OF_TIMERS] =
{
  0x0000,
  0x0000,
  0x0000,
  0x0000,
  0x0000
};


/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define MCU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_16
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header included as per Autosar
guidelines. */
#include "Mcu_MemMap.h"



/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define MCU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header included as per Autosar
guidelines. */
#include "Mcu_MemMap.h"

/* MISRA2012_RULE_8_4_JUSTIFICATION: The
declaration for Mcu_17_Eru_ChUserData is present in Mcu_17_TimerIp.c.
No side effects foreseen by violating this MISRA rule. */
/* MISRA2012_RULE_8_9_JUSTIFICATION: This constant is made used in ISRs
defined in Mcu_17_TimerIp.c for the channel user information. The
declaration for the same is present in Mcu_17_TimerIp.c. Hence can't
be made block scope. No side effects foreseen by violating this MISRA rule. */
const uint32 Mcu_17_Stm_ChUserData[MCU_17_STM_NO_OF_TIMERS] =
{
  0x00000000,
  0x00000000,
  0x00000000,
  0x00000000,
  0x00000000,
  0x00000000
};

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define MCU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header included as per Autosar
guidelines. */
#include "Mcu_MemMap.h"

