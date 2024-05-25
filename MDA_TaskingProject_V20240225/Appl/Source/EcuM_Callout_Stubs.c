/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: EcuM
 *           Program: MSR_Vector_SLP4
 *          Customer: Aptiv (China) Technology Company Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Aurix 2G/TC397 B-Step
 *    License Scope : The usage is restricted to CBD1900078_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: EcuM_Callout_Stubs.c
 *   Generation Time: 2024-01-08 16:27:33
 *           Project: Bsw_Project - Version 1.0
 *          Delivery: CBD1900078_D01
 *      Tool Version: DaVinci Configurator (beta) 5.18.42 SP2
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Pro and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK User Version>                           DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/*********************************************************************************************************************
    INCLUDES
 *********************************************************************************************************************/
#define ECUM_CALLOUT_STUBS_SOURCE
#include "EcuM.h"

#define ECUM_PRIVATE_CFG_INCLUDE
#include "EcuM_PrivateCfg.h"
#undef ECUM_PRIVATE_CFG_INCLUDE /* PRQA S 0841 */ /* MD_EcuM_0841 */



/**********************************************************************************************************************
 *  All configured EcuM Wakeup Sources (as bitmasks) for usage in Callouts
 *********************************************************************************************************************/
/*
 * ECUM_WKSOURCE_NONE                                 (EcuM_WakeupSourceType)(0x00000000uL) 
 * ECUM_WKSOURCE_ALL_SOURCES                          (EcuM_WakeupSourceType)(~((EcuM_WakeupSourceType)0x00UL)) 
 * ECUM_WKSOURCE_POWER                                (EcuM_WakeupSourceType)(1uL) 
 * ECUM_WKSOURCE_RESET                                (EcuM_WakeupSourceType)(2uL) 
 * ECUM_WKSOURCE_INTERNAL_RESET                       (EcuM_WakeupSourceType)(4uL) 
 * ECUM_WKSOURCE_INTERNAL_WDG                         (EcuM_WakeupSourceType)(8uL) 
 * ECUM_WKSOURCE_EXTERNAL_WDG                         (EcuM_WakeupSourceType)(16uL) 
 * ECUM_WKSOURCE_CN_CAN00_8c3ac689                    (EcuM_WakeupSourceType)(32uL) 
 * ECUM_WKSOURCE_CN_Schaeffler_MDA_CANFD_c149c45e     (EcuM_WakeupSourceType)(64uL) 
 * ECUM_WKSOURCE_CN_Schaeffler_MotorFL_CANFD_b5523491 (EcuM_WakeupSourceType)(128uL) 
 * ECUM_WKSOURCE_CN_Schaeffler_MotorFR_CANFD_82b3d302 (EcuM_WakeupSourceType)(256uL) 
 * ECUM_WKSOURCE_CN_Schaeffler_MotorRL_CANFD_4da30b40 (EcuM_WakeupSourceType)(512uL) 
 * ECUM_WKSOURCE_CN_Schaeffler_MotorRR_CANFD_7a42ecd3 (EcuM_WakeupSourceType)(1024uL) 
 */

/**********************************************************************************************************************
 *  Additional configured User includes
 *********************************************************************************************************************/
#include "Rte_Main.h" 
#include "PduR.h" 
#include "Det.h" 
#include "Com.h" 
#include "ComM.h" 
#include "Can.h" 
#include "CanSM_EcuM.h" 
#include "CanIf.h" 
#include "BswM.h" 
#include "Xcp.h" 
#include "CanXcp.h" 
#include "Mcu.h" 
#include "Port.h" 
#include "Adc.h" 
#include "Rte_CtIoHardWare.h" 
#include "IfxSrc_reg.h" 
#include "Dma.h" 
#include "Spi.h" 
#include "Pwm_17_GtmCcu6.h" 
#include "Icu_17_TimerIp.h" 
#include "Gpt.h" 
#include "PSI5.h" 
#include "TLF35584.h" 


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK User Includes>                          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  CALLOUT FUNCTIONS
 *********************************************************************************************************************/
#define ECUM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */




/**********************************************************************************************************************
 *  GENERIC CALLOUTS
 *********************************************************************************************************************/

FUNC(void, ECUM_CODE) EcuM_ErrorHook(Std_ReturnType reason) /* COV_ECUM_CALLOUT */ /* PRQA S 3206 */ /* MD_EcuM_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_ErrorHook>                         DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
  /* dummy assignment to prevent compiler warnings on most of the compilers. */
  (void)reason;     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  /* Add implementation of EcuM_ErrorHook() */
  
  /* In case of an inconsistent configuration data, abort initialization here */
  if(reason == ECUM_E_HOOK_CONFIGURATION_DATA_INCONSISTENT)
  {
    while(1)
    {
    }
  }
  
# if(ECUM_NUMBER_OF_CORES > 1)
  /* In case of an invalid coreId, returned by the OS */
  if(reason == ECUM_E_HOOK_INVALID_COREID)
  {
    while(1)
    {
    }
  }
# endif
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_ErrorHook() */




/**********************************************************************************************************************
 *  CALLOUTS FROM THE SHUTDOWN PHASE
 *********************************************************************************************************************/



FUNC(void, ECUM_CODE) EcuM_OnGoOffOne(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_OnGoOffOne>                        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_OnGoOffOne() */
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_OnGoOffOne() */

FUNC(void, ECUM_CODE) EcuM_ShutdownOS(Std_ReturnType ErrCode)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_ShutdownOS>                        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_ShutdownOS() */
#if ( ECUM_NUMBER_OF_CORES > 1 )
  ShutdownAllCores(ErrCode);
#else
  ShutdownOS(ErrCode);
#endif
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_ShutdownOS() */

FUNC(void, ECUM_CODE) EcuM_OnGoOffTwo(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_OnGoOffTwo>                        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_OnGoOffTwo() */
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_OnGoOffTwo() */

FUNC(void, ECUM_CODE) EcuM_AL_SwitchOff(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_SwitchOff>                      DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_AL_SwitchOff() */
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_AL_SwitchOff() */

FUNC(void, ECUM_CODE) EcuM_AL_Reset(EcuM_ResetType Reset) /* PRQA S 3206 */ /* MD_EcuM_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_Reset>                          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
  /* dummy assignment to prevent compiler warnings on most of the compilers. */
  (void)Reset;  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  /* Add implementation of EcuM_AL_Reset() */

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_AL_Reset() */



/**********************************************************************************************************************
 *  CALLOUTS FROM THE STARTUP PHASE
 *********************************************************************************************************************/


/**********************************************************************************************************************
* EcuM_AL_DriverInitZero
**********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_AL_DriverInitZero(void) 
{
  if(GetCoreID() == ECUM_CORE_ID_BSW)
  {
    Rte_InitMemory();
    PduR_InitMemory();
    Det_InitMemory();
    Det_Init( Det_Config_Ptr );
    Com_InitMemory();
    ComM_InitMemory();
    Can_InitMemory();
    CanSM_InitMemory();
    CanIf_InitMemory();
    BswM_InitMemory();
    Xcp_InitMemory();
    CanXcp_InitMemory();
  }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_DriverInitZero>                 DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Add implementation of EcuM_AL_DriverInitZero  */

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
* EcuM_AL_DriverInitOne
**********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_AL_DriverInitOne(void) 
{
  if(GetCoreID() == ECUM_CORE_ID_BSW)
  {
    Mcu_Init( &Mcu_Config );
    	  Mcu_InitClock(0);
	  while (MCU_PLL_LOCKED != Mcu_GetPllStatus());
	  Mcu_DistributePllClock();
    Port_Init( &Port_Config );
    Adc_Init( &Adc_Config );
    	  while( (Adc_GetStartupCalStatus()) != E_OK);
	  IOHWAB_ADC_Init();
    	  SRC_CAN0INT0.B.SRE = 1;/* TOS=CORE0,InterruptEnable, Prior=51*/
	  SRC_CAN0INT1.B.SRE = 1;/* TOS=CORE0,InterruptEnable, Prior=52*/
	  SRC_CAN0INT2.B.SRE = 1;/* TOS=CORE0,InterruptEnable, Prior=53*/
	  SRC_CAN0INT3.B.SRE = 1;/* TOS=CORE0,InterruptEnable, Prior=54*/
	  SRC_CAN1INT0.B.SRE = 1;/* TOS=CORE0,InterruptEnable, Prior=55*/
	  SRC_CAN1INT1.B.SRE = 1;/* TOS=CORE0,InterruptEnable, Prior=56*/

      SRC_VADCG0SR0.B.SRE = 1;/* TOS=CORE0,InterruptEnable, Prior=22*/
      SRC_VADCG1SR0.B.SRE = 1;/* TOS=CORE0,InterruptEnable, Prior=23*/
      SRC_VADCG2SR0.B.SRE = 1;/* TOS=CORE0,InterruptEnable, Prior=24 */
      SRC_VADCG3SR0.B.SRE = 1;/* TOS=CORE0,InterruptEnable, Prior=25 */
      SRC_VADCG8SR0.B.SRE = 1;/* TOS=CORE0,InterruptEnable, Prior=48 */

	  SRC_DAM0ERR.B.SRE = 1;/* TOS=CORE0,InterruptEnable, Prior=47 */
	  SRC_DMACH0.B.SRE = 1;/* TOS=CORE0,InterruptEnable, Prior=26 */
	  SRC_DMACH3.B.SRE = 1;/* TOS=CORE0,InterruptEnable, Prior=27 */
	  SRC_DMACH4.B.SRE = 1;/* TOS=CORE0,InterruptEnable, Prior=28 */
	  SRC_DMACH5.B.SRE = 1;/* TOS=CORE0,InterruptEnable, Prior=29 */
	  SRC_DMACH6.B.SRE = 1;/* TOS=CORE0,InterruptEnable, Prior=30 */
	  SRC_DMACH7.B.SRE = 1;/* TOS=CORE0,InterruptEnable, Prior=31 */
	  SRC_DMACH8.B.SRE = 1;/* TOS=CORE0,InterruptEnable, Prior=32 */
	  SRC_DMACH9.B.SRE = 1;/* TOS=CORE0,InterruptEnable, Prior=33 */

	  SRC_QSPI0ERR.B.SRE = 1;/* TOS=CORE0,InterruptEnable, Prior=45 */
	  SRC_QSPI0PT.B.SRE = 1;/* TOS=CORE0,InterruptEnable, Prior=46 */
	  SRC_QSPI1ERR.B.SRE = 1;/* TOS=CORE0,InterruptEnable, Prior=43 */
	  SRC_QSPI1PT.B.SRE = 1;/* TOS=CORE0,InterruptEnable, Prior=44 */
	  SRC_QSPI2ERR.B.SRE = 1;/* TOS=CORE0,InterruptEnable, Prior=39 */
	  SRC_QSPI2PT.B.SRE = 1;/* TOS=CORE0,InterruptEnable, Prior=40 */
	  SRC_QSPI3ERR.B.SRE = 1;/* TOS=CORE0,InterruptEnable, Prior=41 */
	  SRC_QSPI3PT.B.SRE = 1;/* TOS=CORE0,InterruptEnable, Prior=42 */

	  SRC_QSPI2RX.U  = 0x0800 | 0x00; /* TOS=DMA,Prior=0(DMA_Channel_0) */
	  SRC_QSPI2TX.U  = 0x0800 | 0x04; /* TOS=DMA,Prior=4(DMA_Channel_4) */
	  SRC_QSPI3TX.U  = 0x0800 | 0x05; /* TOS=DMA,Prior=5(DMA_Channel_5) */
	  SRC_QSPI1RX.U  = 0x0800 | 0x06; /* TOS=DMA,Prior=6(DMA_Channel_6) */
	  SRC_QSPI1TX.U  = 0x0800 | 0x07; /* TOS=DMA,Prior=7(DMA_Channel_7) */
	  SRC_QSPI0RX.U  = 0x0800 | 0x08; /* TOS=DMA,Prior=8(DMA_Channel_8) */
	  SRC_QSPI0TX.U  = 0x0800 | 0x09; /* TOS=DMA,Prior=9(DMA_Channel_9) */

	  SRC_GTM_ATOM0_0.B.SRE = 1;
	  SRC_GTM_ATOM1_0.B.SRE = 1;
	  SRC_GTM_ATOM2_0.B.SRE = 1;
	  SRC_GTM_ATOM4_0.B.SRE = 1;

	  SRC_GTM_TOM0_0.B.SRE = 1;
	  SRC_GTM_TOM0_1.B.SRE = 1;
	  SRC_GTM_TOM0_2.B.SRE = 1;
	  SRC_GTM_TOM0_3.B.SRE = 1;
    	  Dma_Init(&Dma_Config);
    Spi_Init( &Spi_Config );
//    Pwm_17_GtmCcu6_Init( &Pwm_17_GtmCcu6_Config );
//    Icu_17_TimerIp_Init( &Icu_17_TimerIp_Config );
//    Gpt_Init( &Gpt_Config );
    PSI5_Init();
//    initTLF35584(&g_tlfDevice);
  }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_DriverInitOne>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Add implementation of EcuM_AL_DriverInitOne  */

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#if (ECUM_SLEEPMODELIST == STD_ON)
/**********************************************************************************************************************
* EcuM_AL_DriverRestartList
**********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_AL_DriverRestartList(void) 
{
  /* DriverRestartList will not be called () because no sleepmode is configured - So don't use this function! */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_DriverRestartList>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Add implementation of EcuM_AL_DriverRestartList  */

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}
#endif




FUNC(void, ECUM_CODE) EcuM_StartOS(AppModeType appMode)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_StartOS>                           DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_StartOS() */
#if ( ECUM_NUMBER_OF_CORES > 1 )
  uint8 coreId;
  StatusType status;
  if(GetCoreID()==ECUM_CORE_ID_STARTUP)
  {
    for(coreId=0; coreId < ECUM_NUMBER_OF_CORES; coreId++)
    {
      if(coreId!=ECUM_CORE_ID_STARTUP)
      {
        StartCore(coreId, &status); /* SBSW_ECUM_ADRESSPARAMETER_TOOS */
      }
    }
  }
#endif

  /* Start OS must be called for each core */
  StartOS(appMode);

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_StartOS() */

FUNC(void, ECUM_CODE) EcuM_AL_SetProgrammableInterrupts(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_SetProgrammableInterrupts>      DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_AL_SetProgrammableInterrupts() */

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_AL_SetProgrammableInterrupts() */

#if((ECUM_CONFIGURATION_VARIANT == ECUM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE) || (ECUM_POSTBUILD_VARIANT_SUPPORT == STD_ON))
FUNC(EcuM_GlobalConfigRefType, ECUM_CODE) EcuM_DeterminePbConfiguration(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_DeterminePbConfiguration>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_DeterminePbConfiguration() */
  
  return ;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_DeterminePbConfiguration() */
#endif

#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
FUNC(void, ECUM_CODE) EcuM_GptStartClock(Gpt_ChannelType GptChannel, Gpt_ModeType Mode, Gpt_ValueType Value)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_GptStartClock>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_GptStartClock() */

  Gpt_EnableNotification(GptChannel);
  Gpt_StartTimer(GptChannel, Value);
  Gpt_SetMode(Mode);

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_GptStartClock() */
#endif




/**********************************************************************************************************************
 *  CALLOUTS FROM THE SLEEP PHASE
 *********************************************************************************************************************/



#if(ECUM_SLAVE_CORE_HANDLING == STD_ON)
FUNC(void, ECUM_CODE) EcuM_WaitForSlaveCores(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_WaitForSlaveCores>                 DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_WaitForSlaveCores() */
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_WaitForSlaveCores() */
#endif

#if(ECUM_SLEEPMODELIST == STD_ON)

FUNC(void, ECUM_CODE) EcuM_GenerateRamHash(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_GenerateRamHash>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_GenerateRamHash() */
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_GenerateRamHash() */

FUNC(uint8, ECUM_CODE) EcuM_CheckRamHash(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_CheckRamHash>                      DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_CheckRamHash() */
  
  return (1u);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_CheckRamHash() */

FUNC(void, ECUM_CODE) EcuM_McuSetMode(Mcu_ModeType McuMode)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_McuSetMode>                        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_McuSetMode() */
  Mcu_SetMode(McuMode);
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_McuSetMode() */

#if(ECUM_POLLINGOFSLEEPMODELIST == STD_ON)
FUNC(void, ECUM_CODE) EcuM_SleepActivity(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_SleepActivity>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_SleepActivity() */
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_SleepActivity() */
#endif

FUNC(void, ECUM_CODE) EcuM_EnableWakeupSources(EcuM_WakeupSourceType wakeupSource) /* PRQA S 3206 */ /* MD_EcuM_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_EnableWakeupSources>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
  /* dummy assignment to prevent compiler warnings on most of the compilers. */
  (void)wakeupSource; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  /* Add implementation of EcuM_EnableWakeupSources() */
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_EnableWakeupSources() */

FUNC(void, ECUM_CODE) EcuM_DisableWakeupSources(EcuM_WakeupSourceType wakeupSource) /* PRQA S 3206 */ /* MD_EcuM_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_DisableWakeupSources>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
  /* dummy assignment to prevent compiler warnings on most of the compilers. */
  (void)wakeupSource; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  /* Add implementation of EcuM_DisableWakeupSources() */
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_DisableWakeupSources() */
#endif

FUNC(void, ECUM_CODE) EcuM_CheckWakeup(EcuM_WakeupSourceType wakeupSource) /* COV_ECUM_CALLOUT */
{
#if (ECUM_CHECKWAKEUPTIMEOFWAKEUPSOURCELIST == STD_ON)
  /* Do not remove the following function call. It is necessary for the CheckWakeup timeout mechanism */
  EcuM_StartCheckWakeup(wakeupSource);
#endif

#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
  if((ECUM_ALARM_WKSOURCE & wakeupSource) != 0u)
  {
    EcuM_AlarmCheckWakeup();
  }
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_CheckWakeup>                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
  /* dummy assignment to prevent compiler warnings on most of the compilers. */
  (void)wakeupSource; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  /* Add implementation of EcuM_CheckWakeup() */

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_CheckWakeup() */

#if ((ECUM_ALARM_CLOCK_PRESENT == STD_ON) && (ECUM_SLEEPMODELIST == STD_ON))
FUNC(void, ECUM_CODE) EcuM_GptSetNormal(Gpt_ChannelType GptChannel, Gpt_ModeType Mode)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_GptSetNormal>                      DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_GptSetNormal() */

  Gpt_EnableNotification(GptChannel);
  Gpt_SetMode(Mode);

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_GptSetNormal() */

FUNC(void, ECUM_CODE) EcuM_GptSetSleep(Gpt_ChannelType GptChannel, Gpt_ModeType Mode)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_GptSetSleep>                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* Add implementation of EcuM_GptSetSleep() */

  Gpt_EnableWakeup(GptChannel);
  Gpt_SetMode(Mode);

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_GptSetSleep() */
#endif



/**********************************************************************************************************************
 *  CALLOUTS FROM THE UP PHASE
 *********************************************************************************************************************/

#if(ECUM_VALIDATIONTIMEOFWAKEUPSOURCELIST == STD_ON)

FUNC(void, ECUM_CODE) EcuM_StartWakeupSources(EcuM_WakeupSourceType wakeupSource) /* PRQA S 3206 */ /* MD_EcuM_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_StartWakeupSources>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
  /* dummy assignment to prevent compiler warnings on most of the compilers. */
  (void)wakeupSource; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  /* Add implementation of EcuM_StartWakeupSources() */
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_StartWakeupSources() */

FUNC(void, ECUM_CODE) EcuM_StopWakeupSources(EcuM_WakeupSourceType wakeupSource) /* PRQA S 3206 */ /* MD_EcuM_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_StopWakeupSources>                 DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
  /* dummy assignment to prevent compiler warnings on most of the compilers. */
  (void)wakeupSource; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  /* Add implementation of EcuM_StopWakeupSources() */
  
  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_StopWakeupSources() */

FUNC(void, ECUM_CODE) EcuM_CheckValidation(EcuM_WakeupSourceType wakeupSource)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_CheckValidation>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
  /* dummy assignment to prevent compiler warnings on most of the compilers. */
  (void)wakeupSource; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  /* Add implementation of EcuM_CheckValidation() */

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_CheckValidation() */

#endif



#if (ECUM_BSW_ERROR_HOOK == STD_ON)
/**********************************************************************************************************************
 *  Errorhook for BSW errors during initialization
 *********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_BswErrorHook(uint16 BswModuleId, uint8 ErrorId) /* PRQA S 3206 */ /* MD_EcuM_3206 */ /* COV_ECUM_CALLOUT */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_BswErrorHook>                      DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 
#if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
  /* dummy assignment to prevent compiler warnings on most of the compilers. */
  (void)BswModuleId;  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  (void)ErrorId;      /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  /* Add implementation of EcuM_BswErrorHook() */
  
  if(BswModuleId == ECUM_MODULE_ID)
  {
    /* Abort initialization per default if the EcuM has reported an BswError */
    while(1)
    {
    }
  }

  return;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
} /* End of EcuM_BswErrorHook() */
#endif

#define ECUM_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if 0
#endif


/**********************************************************************************************************************
 *  END OF FILE: ECUM_CALLOUT_STUBS.C
 *********************************************************************************************************************/


