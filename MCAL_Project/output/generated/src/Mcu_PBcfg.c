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
**  FILENAME  : Mcu_PBcfg.c                                                   **
**                                                                            **
**  VERSION   : 11.0.0                                                        **
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
**  DESCRIPTION  : Mcu configuration generated out of ECUC file               **
**                                                                            **
**  SPECIFICATION(S) : Specification of Mcu Driver, AUTOSAR Release 4.2.2     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                       Includes                                             **
*******************************************************************************/
/* Include module header file */
#include "Mcu.h"
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/*[cover parentID={72DABBEB-F27B-4677-B6B4-B53F634341BA}][/cover]*/
/*[cover parentID={E4047F9A-8865-4b2c-9D3C-385479854EAD}][/cover]*/
#define MCU_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
/*[cover parentID={4E3D9856-2420-4bc0-8E39-B0F93F3DC39E}][/cover]*/
#include "Mcu_MemMap.h"

/*
  PLL Distribution configuration structure(s)
  for each clock setting configurations
*/
/* MISRA2012_RULE_5_1_JUSTIFICATION:Compiler supports macro names going beyond
   32 chars and this macro is used only inside the MCU module*/
/* MISRA2012_RULE_5_2_JUSTIFICATION:Compiler supports macro names going beyond
   32 chars and this macro is used only inside the MCU module*/
/* MISRA2012_RULE_5_4_JUSTIFICATION:Compiler supports macro names going beyond
   32 chars and this macro is used only inside the MCU module*/
/* MISRA2012_RULE_5_5_JUSTIFICATION:Compiler supports macro names going beyond
   32 chars and this macro is used only inside the MCU module*/
static const Mcu_PllDistributionConfigType Mcu_kPllDistributionConfiguration_Config_0 =
{
  /* CCUCON0 value */
  0x17230113U,
  /* CCUCON1 value */
  0x00000292U,
  /* CCUCON2 value */
  0x00000000U,
  /* CCUCON5 value */
  0x00000132U,
  /* CCUCON6...CCUCON11 value */
  {
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x00000000U
  }
};
/*
   Configuration : Mcu_ConfigType
   For Mcu_ConfigType: MCU specific configuration ID
   This id corresponds to the container name of the McuConfiguration.
   Use this as the parameter for API: Mcu_Init
   Container: McuClockSettingConfig
   Multilplicity : 1 - *
*/
static const Mcu_ClockConfigType Mcu_kClockConfiguration_Config[1] =
{
  /*McuClockSettingConfig_0*/
  {
    /* System PLL configuration value */
    {
      1U,
      0U,
      29U,
      1U,
      0U,
      0U
    },
    /* Peripheral PLL configuration value */
    {
      39U,
      0U,
      4U,
      1U,
      1U,
      0U
    },
    /* System PLL K2 divider increment step change delay */
    10U,
    /* System PLL K2 divider decrement step change delay */
    10U,
    /* Peripheral PLL K2 divider step change increment */
    10U,
    /* Peripheral PLL K2 divider step change decrement */
    10U,
    /* Peripheral PLL K3 divider step change increment */
    10U,
    /* Peripheral PLL K3 divider step change decrement */
    10U,
    /* PLL clock divider configuration pointer */
    &Mcu_kPllDistributionConfiguration_Config_0,
    /* External Clock configuration */
    0x00000000U,
    /* Backup frequency K Divider value for both PLLs */
    0x0375U,
    /* Converter Control Phase Synchronization configuration */
    0x00U,
  },/*McuClockReferencePointConfig*/
};
/*
  Ptr to RAM Section in config structure
  Container: McuRamSectorSettingConf
  Multiplicity: 1 - *
  Configuration: RAM Section Id
  This id corresponds to the container name of the McuRAMSettingConfiguration.
  Use this as the parameter for API: Mcu_InitRamSection
*/

/*
  Standby Mode config structure for Low Power (Standby) Mode Configuration:
  
*/
static const Mcu_LowPowerModeType  Mcu_kLowPowerModeConfiguration_Config =
{
  /*MaxModeEvrcCtrl value*/
  {
    0x1U,
    0x0U,
    0U
  },
  /* PMSWCR0 Register value */
  0x00000000U,
  /* PMSWCR3Value  */
  0x00000000U,
  /* PMSWCR4Value  */
  0x00000000U,
  /* PMSWCR5Value  */
  0x00000000U
};
/*Generate configuration structure for GTM Clock config*/
                                                static const Mcu_GtmClockSettingType Mcu_kGtmClockConfigPtr_Config =
{
  /*CMU config clock, external and fixed clock enable - GtmCmuClockEnable*/
  0x0080aaaaU,
  /*CMU global clock numerator - GtmCmuGlobalNumerator*/
  0x00000001U,
  /*CMU global clock denominator - GtmCmuGlobalDenominator*/
  0x00000001U,

  /*CMU config clock_0...7 Numerator and Denominator - GtmCmuConfClkCtrl*/
  {
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x00000000U,
    0x00000000U
  },

  /*CMU fixed clock Divider selection - GtmCmuFixedClkCtrl*/
    0x00000000U,

  /*GTM cluster input clock divider configuration - GtmCmuClusterInputClockDividerEnable */
  0x00aaaaaaU,

  /* External clock settings - GtmEclkCtrl*/
  {
    /*External Clock_0 disabled - reset value of numerator and denominator*/
    {1U, 1U},
    /*External Clock_1 disabled - reset value of numerator and denominator*/
    {1U, 1U},
    /*External Clock_2 disabled - reset value of numerator and denominator*/
    {1U, 1U}
  }
};
/*Generate configuration structure for GTM cluster config*/
static const Mcu_GtmClusterConfigType Mcu_kGtmClusterConfigPtr_Config[12] =
{
            
  /*GTM Cluster_0 configuration*/
  {
    /*GTM cluster TIM/TOM/ATOM enable settings*/
    0x00000000U,
    /*GTM cluster config clock settings*/
    0x00000000U,
    /*GTM cluster fixed clock settings*/
    0x00000000U
  },            
  /*GTM Cluster_1 configuration*/
  {
    /*GTM cluster TIM/TOM/ATOM enable settings*/
    0x00000000U,
    /*GTM cluster config clock settings*/
    0x00000000U,
    /*GTM cluster fixed clock settings*/
    0x00000000U
  },            
  /*GTM Cluster_2 configuration*/
  {
    /*GTM cluster TIM/TOM/ATOM enable settings*/
    0x00000000U,
    /*GTM cluster config clock settings*/
    0x00000000U,
    /*GTM cluster fixed clock settings*/
    0x00000000U
  },            
  /*GTM Cluster_3 configuration*/
  {
    /*GTM cluster TIM/TOM/ATOM enable settings*/
    0x00000000U,
    /*GTM cluster config clock settings*/
    0x00000000U,
    /*GTM cluster fixed clock settings*/
    0x00000000U
  },            
  /*GTM Cluster_4 configuration*/
  {
    /*GTM cluster TIM/TOM/ATOM enable settings*/
    0x00000000U,
    /*GTM cluster config clock settings*/
    0x00000000U,
    /*GTM cluster fixed clock settings*/
    0x00000000U
  },            
  /*GTM Cluster_5 configuration*/
  {
    /*GTM cluster TIM/TOM/ATOM enable settings*/
    0x00000000U,
    /*GTM cluster config clock settings*/
    0x00000000U,
    /*GTM cluster fixed clock settings*/
    0x00000000U
  },            
  /*GTM Cluster_6 configuration*/
  {
    /*GTM cluster TIM/TOM/ATOM enable settings*/
    0x00000000U,
    /*GTM cluster config clock settings*/
    0x00000000U,
    /*GTM cluster fixed clock settings*/
    0x00000000U
  },            
  /*GTM Cluster_7 configuration*/
  {
    /*GTM cluster TIM/TOM/ATOM enable settings*/
    0x00000000U,
    /*GTM cluster config clock settings*/
    0x00000000U,
    /*GTM cluster fixed clock settings*/
    0x00000000U
  },            
  /*GTM Cluster_8 configuration*/
  {
    /*GTM cluster TIM/TOM/ATOM enable settings*/
    0x00000000U,
    /*GTM cluster config clock settings*/
    0x00000000U,
    /*GTM cluster fixed clock settings*/
    0x00000000U
  },            
  /*GTM Cluster_9 configuration*/
  {
    /*GTM cluster TIM/TOM/ATOM enable settings*/
    0x00000000U,
    /*GTM cluster config clock settings*/
    0x00000000U,
    /*GTM cluster fixed clock settings*/
    0x00000000U
  },            
  /*GTM Cluster_10 configuration*/
  {
    /*GTM cluster TIM/TOM/ATOM enable settings*/
    0x00000000U,
    /*GTM cluster config clock settings*/
    0x00000000U,
    /*GTM cluster fixed clock settings*/
    0x00000000U
  },            
  /*GTM Cluster_11 configuration*/
  {
    /*GTM cluster TIM/TOM/ATOM enable settings*/
    0x00000000U,
    /*GTM cluster config clock settings*/
    0x00000000U,
    /*GTM cluster fixed clock settings*/
    0x00000000U
  }
};

/*
 Gtm Configuration structure for module
  Container: Mcu_kGtmConfiguration
  Multiplicity: 1 - *
*/
static const Mcu_GtmConfigType Mcu_kGtmConfiguration_Config =
{
  /* Ptr to GTM clock configuration -  GtmClockCfgPtr */
  &Mcu_kGtmClockConfigPtr_Config,
  /* Ptr to GTM cluster configuration -  GtmClusterCfgPtr */
  Mcu_kGtmClusterConfigPtr_Config,
  /*Configuration for TOM global settings*/
  {
    /*Configuration for Tom global settings -  GtmTomCfg*/

    /*GtmTomGlobalConf_0*/
    {
      /*TomTgcIntTrigRstCn0 value for group0*/
      0x00000000U,
      /*TomTgcActTb value for group0*/
      0x00000001U
    },
    {
      /*TomTgcIntTrigRstCn1 value for group1*/
      0x00000000U,
      /*TomTgcActTb value for group1*/
      0x00000001U
    },
    /*GtmTomGlobalConf_1*/
    {
      /*TomTgcIntTrigRstCn0 value for group0*/
      0x00000000U,
      /*TomTgcActTb value for group0*/
      0x00000001U
    },
    {
      /*TomTgcIntTrigRstCn1 value for group1*/
      0x00000000U,
      /*TomTgcActTb value for group1*/
      0x00000001U
    },
    /*GtmTomGlobalConf_2*/
    {
      /*TomTgcIntTrigRstCn0 value for group0*/
      0x00000000U,
      /*TomTgcActTb value for group0*/
      0x00000001U
    },
    {
      /*TomTgcIntTrigRstCn1 value for group1*/
      0x00000000U,
      /*TomTgcActTb value for group1*/
      0x00000001U
    },
    /*GtmTomGlobalConf_3*/
    {
      /*TomTgcIntTrigRstCn0 value for group0*/
      0x00000000U,
      /*TomTgcActTb value for group0*/
      0x00000001U
    },
    {
      /*TomTgcIntTrigRstCn1 value for group1*/
      0x00000000U,
      /*TomTgcActTb value for group1*/
      0x00000001U
    },
    /*GtmTomGlobalConf_4*/
    {
      /*TomTgcIntTrigRstCn0 value for group0*/
      0x00000000U,
      /*TomTgcActTb value for group0*/
      0x00000001U
    },
    {
      /*TomTgcIntTrigRstCn1 value for group1*/
      0x00000000U,
      /*TomTgcActTb value for group1*/
      0x00000001U
    },
    /*GtmTomGlobalConf_5*/
    {
      /*TomTgcIntTrigRstCn0 value for group0*/
      0x00000000U,
      /*TomTgcActTb value for group0*/
      0x00000001U
    },
    {
      /*TomTgcIntTrigRstCn1 value for group1*/
      0x00000000U,
      /*TomTgcActTb value for group1*/
      0x00000001U
    }
  },
  /*Configuration for ATOM global settings*/
  {
    /*Configuration for Atom global settings -  GtmAtomCfg*/

    /*GtmAtomGlobalConf_0*/
    {
      /*AtomTgcIntTrigRstCn0 value*/
      0x00000000U,
      /*AtomTgcActTb value */
      0x00000001U
    },
    /*GtmAtomGlobalConf_1*/
    {
      /*AtomTgcIntTrigRstCn0 value*/
      0x00000000U,
      /*AtomTgcActTb value */
      0x00000001U
    },
    /*GtmAtomGlobalConf_2*/
    {
      /*AtomTgcIntTrigRstCn0 value*/
      0x00000000U,
      /*AtomTgcActTb value */
      0x00000001U
    },
    /*GtmAtomGlobalConf_3*/
    {
      /*AtomTgcIntTrigRstCn0 value*/
      0x00000000U,
      /*AtomTgcActTb value */
      0x00000001U
    },
    /*GtmAtomGlobalConf_4*/
    {
      /*AtomTgcIntTrigRstCn0 value*/
      0x00000000U,
      /*AtomTgcActTb value */
      0x00000001U
    },
    /*GtmAtomGlobalConf_5*/
    {
      /*AtomTgcIntTrigRstCn0 value*/
      0x00000000U,
      /*AtomTgcActTb value */
      0x00000001U
    },
    /*GtmAtomGlobalConf_6*/
    {
      /*AtomTgcIntTrigRstCn0 value*/
      0x00000000U,
      /*AtomTgcActTb value */
      0x00000001U
    },
    /*GtmAtomGlobalConf_7*/
    {
      /*AtomTgcIntTrigRstCn0 value*/
      0x00000000U,
      /*AtomTgcActTb value */
      0x00000001U
    },
    /*GtmAtomGlobalConf_8*/
    {
      /*AtomTgcIntTrigRstCn0 value*/
      0x00000000U,
      /*AtomTgcActTb value */
      0x00000001U
    },
    /*GtmAtomGlobalConf_9*/
    {
      /*AtomTgcIntTrigRstCn0 value*/
      0x00000000U,
      /*AtomTgcActTb value */
      0x00000001U
    },
    /*GtmAtomGlobalConf_10*/
    {
      /*AtomTgcIntTrigRstCn0 value*/
      0x00000000U,
      /*AtomTgcActTb value */
      0x00000001U
    },
    /*GtmAtomGlobalConf_11*/
    {
      /*AtomTgcIntTrigRstCn0 value*/
      0x00000000U,
      /*AtomTgcActTb value */
      0x00000001U
    }
  },

  /*Configuration for Gtm to Adc trigger settings*/
  {
    /*Configuration of Gtm Adc trigger 0*/
    {
      /*GtmAdcOut0 value*/
      0x00000000U,
      /*GtmAdcOut1 value */
      0x00000000U
    },    /*Configuration of Gtm Adc trigger 1*/
    {
      /*GtmAdcOut0 value*/
      0x00000000U,
      /*GtmAdcOut1 value */
      0x00000000U
    },    /*Configuration of Gtm Adc trigger 2*/
    {
      /*GtmAdcOut0 value*/
      0x00000000U,
      /*GtmAdcOut1 value */
      0x00000000U
    },    /*Configuration of Gtm Adc trigger 3*/
    {
      /*GtmAdcOut0 value*/
      0x00000000U,
      /*GtmAdcOut1 value */
      0x00000000U
    },    /*Configuration of Gtm Adc trigger 4*/
    {
      /*GtmAdcOut0 value*/
      0x00000000U,
      /*GtmAdcOut1 value */
      0x00000000U
    }
  },
  /*Configuration for TBU channel - GtmTbuCfg (GtmTbuChannelConf)*/
  0x00000000U,
  /* TOM modules used configuration */
  0x0000U,
  /* ATOM modules used configuration */
  0x0000U,
  /* Gtm sleep mode configuration */
  (boolean)FALSE
};
/* Main MCU Configuration Structure */
/* MISRA2012_RULE_8_7_JUSTIFICATION: Module configuration data structure
   declaration as per Autosar guidelines. This data structure may be needed
   by SW units using Mcu Driver APIs */
/* MISRA2012_RULE_8_4_JUSTIFICATION: Definition is as per Autosar guidelines */
const Mcu_ConfigType Mcu_Config =
{
  /*McuModuleConfiguration*/
  /* MCU clock Configuration Pointer*/
  Mcu_kClockConfiguration_Config,
  /* Ram Section configuration Pointer*/
  NULL_PTR,
  #if (MCU_GTM_USED == STD_ON)
  /* GTM Global Configuration Pointer*/
  &Mcu_kGtmConfiguration_Config,
  #endif
  /* Ptr to Standby Mode in config structure */
  &Mcu_kLowPowerModeConfiguration_Config,
  /* Reset configuration */
  0x00000000U,
  /* Application Reset Disable configuration */
  0x00000000U,
  /* Trap configuration */
  0xffffffffU,
  0x0000ffffU,
  /*Eru global input filter configuration */
  0x00000000U,
  /* Total number of Clock settings */
  ((Mcu_ClockType)1U),
  /* Total number of RAM Sectors */
  ((Mcu_RamSectionType)0U)
};
/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

#define MCU_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Memmap header included as per Autosar
   guidelines. */
#include "Mcu_MemMap.h"
