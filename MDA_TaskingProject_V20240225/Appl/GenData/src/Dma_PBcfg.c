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
**  FILENAME  : Dma_PBCfg.c                                                   **
**                                                                            **
**  VERSION   : 4.0.0                                                         **
**                                                                            **
**  DATE, TIME: 2024-02-23, 10:02:53                                      **
**                                                                            **
**  GENERATOR : Build b170330-0431                                          **
**                                                                            **
**  BSW MODULE DECRIPTION : NA                                                **
**                                                                            **
**  VARIANT   : Variant PB                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Dma configuration generated out of ECUC file               **
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
#include "Dma.h"



/* ********* Resource partition error notification functions ********* */
/* User defined notification functions to be called by DMA driver in case
 * of error from the resource partitions */
/* Error notification function from Resource Partition 0 */
/* <**No notification function is configured for this resource partition**> */
/* Error notification function from Resource Partition 1 */
/* <**No notification function is configured for this resource partition**> */
/* Error notification function from Resource Partition 2 */
/* <**No notification function is configured for this resource partition**> */
/* Error notification function from Resource Partition 3 */
/* <**No notification function is configured for this resource partition**> */
/* ******************************************************************* */


/* ************* Channel specific notification functions ************* */
/* User defined notification functions for channels to be called by
 * the DMA driver in case of channel interrupts */
/* Channel specific notification function for Channel 8  */
extern void QSPI0RX_DMACallout(uint8 Channel, uint32 Event);
/* Channel specific notification function for Channel 9  */
extern void QSPI0TX_DMACallout(uint8 Channel, uint32 Event);
/* Channel specific notification function for Channel 6  */
extern void QSPI1RX_DMACallout(uint8 Channel, uint32 Event);
/* Channel specific notification function for Channel 7  */
extern void QSPI1TX_DMACallout(uint8 Channel, uint32 Event);
/* Channel specific notification function for Channel 0  */
extern void QSPI2RX_DMACallout(uint8 Channel, uint32 Event);
/* Channel specific notification function for Channel 3  */
extern void QSPI2TX_DMACallout(uint8 Channel, uint32 Event);
/* Channel specific notification function for Channel 4  */
extern void QSPI3RX_DMACallout(uint8 Channel, uint32 Event);
/* Channel specific notification function for Channel 5  */
extern void QSPI3TX_DMACallout(uint8 Channel, uint32 Event);
/* ******************************************************************* */



    



/* [cover parentID={64855B2E-FB75-4b7d-B34C-E5AA5CBAC0CE}]
Dma_kChConfigRoot_Core
[/cover] */

/* ***************** Configuration of the TCSes ***************** */
                            
                    
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
#define DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE0_256
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is
* repeatedly included without include guard. This is
* as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of
* MoveEngine Notification before #include memap.h
* - Accepted deviation in AUTOSAR */
/* [cover parentID={5713A17A-3FA1-427f-A0B6-89125A17689A}]
* Const Section
* [/cover]*/
/* [cover parentID={E4047F9A-8865-4b2c-9D3C-385479854EAD}]
* Const Section
* [/cover]*/
#include "Dma_MemMap.h"

/* DMA channel 8 Transaction set control Configuration */
static const Dma_TransactionCtrlSetType Dma_kChannel_8_TcsConfigRoot[]=
{
  /* Dma Channel 8 TCS 0 */
  {
    /* Configuration for DMA source address register DMA_SADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: Shadow SFR access */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Shadow SFR access */
    (uint32 *)0x00000000U,
    /* Configuration for DMA destination address register DMA_DADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: Shadow SFR access */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Shadow SFR access */
    (uint32 *)0x00000000U,
    /* Configuration for DMA Channel Address and Interrupt Control
    * Register DMA_ADICRz */
    0x00000088U,
    /* Configuration for DMA Channel Configuration Register DMA_CHCFGRz */
    0x00000000U,
    /* Configuration for DMA Channel Shadow Address Register DMA_SHADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: Shadow SFR access */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Shadow SFR access */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
#define DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_256
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of MoveEngine Notification
* before #include memap.h - Accepted deviation in AUTOSAR */
#include "Dma_MemMap.h"

                            
                    
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
#define DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE0_256
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is
* repeatedly included without include guard. This is
* as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of
* MoveEngine Notification before #include memap.h
* - Accepted deviation in AUTOSAR */
/* [cover parentID={5713A17A-3FA1-427f-A0B6-89125A17689A}]
* Const Section
* [/cover]*/
/* [cover parentID={E4047F9A-8865-4b2c-9D3C-385479854EAD}]
* Const Section
* [/cover]*/
#include "Dma_MemMap.h"

/* DMA channel 9 Transaction set control Configuration */
static const Dma_TransactionCtrlSetType Dma_kChannel_9_TcsConfigRoot[]=
{
  /* Dma Channel 9 TCS 0 */
  {
    /* Configuration for DMA source address register DMA_SADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: Shadow SFR access */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Shadow SFR access */
    (uint32 *)0x00000000U,
    /* Configuration for DMA destination address register DMA_DADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: Shadow SFR access */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Shadow SFR access */
    (uint32 *)0x00000000U,
    /* Configuration for DMA Channel Address and Interrupt Control
    * Register DMA_ADICRz */
    0x00000088U,
    /* Configuration for DMA Channel Configuration Register DMA_CHCFGRz */
    0x00000000U,
    /* Configuration for DMA Channel Shadow Address Register DMA_SHADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: Shadow SFR access */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Shadow SFR access */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
#define DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_256
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of MoveEngine Notification
* before #include memap.h - Accepted deviation in AUTOSAR */
#include "Dma_MemMap.h"

                            
                    
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
#define DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE0_256
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is
* repeatedly included without include guard. This is
* as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of
* MoveEngine Notification before #include memap.h
* - Accepted deviation in AUTOSAR */
/* [cover parentID={5713A17A-3FA1-427f-A0B6-89125A17689A}]
* Const Section
* [/cover]*/
/* [cover parentID={E4047F9A-8865-4b2c-9D3C-385479854EAD}]
* Const Section
* [/cover]*/
#include "Dma_MemMap.h"

/* DMA channel 6 Transaction set control Configuration */
static const Dma_TransactionCtrlSetType Dma_kChannel_6_TcsConfigRoot[]=
{
  /* Dma Channel 6 TCS 0 */
  {
    /* Configuration for DMA source address register DMA_SADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: Shadow SFR access */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Shadow SFR access */
    (uint32 *)0x00000000U,
    /* Configuration for DMA destination address register DMA_DADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: Shadow SFR access */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Shadow SFR access */
    (uint32 *)0x00000000U,
    /* Configuration for DMA Channel Address and Interrupt Control
    * Register DMA_ADICRz */
    0x00000088U,
    /* Configuration for DMA Channel Configuration Register DMA_CHCFGRz */
    0x00000000U,
    /* Configuration for DMA Channel Shadow Address Register DMA_SHADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: Shadow SFR access */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Shadow SFR access */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
#define DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_256
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of MoveEngine Notification
* before #include memap.h - Accepted deviation in AUTOSAR */
#include "Dma_MemMap.h"

                            
                    
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
#define DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE0_256
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is
* repeatedly included without include guard. This is
* as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of
* MoveEngine Notification before #include memap.h
* - Accepted deviation in AUTOSAR */
/* [cover parentID={5713A17A-3FA1-427f-A0B6-89125A17689A}]
* Const Section
* [/cover]*/
/* [cover parentID={E4047F9A-8865-4b2c-9D3C-385479854EAD}]
* Const Section
* [/cover]*/
#include "Dma_MemMap.h"

/* DMA channel 7 Transaction set control Configuration */
static const Dma_TransactionCtrlSetType Dma_kChannel_7_TcsConfigRoot[]=
{
  /* Dma Channel 7 TCS 0 */
  {
    /* Configuration for DMA source address register DMA_SADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: Shadow SFR access */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Shadow SFR access */
    (uint32 *)0x00000000U,
    /* Configuration for DMA destination address register DMA_DADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: Shadow SFR access */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Shadow SFR access */
    (uint32 *)0x00000000U,
    /* Configuration for DMA Channel Address and Interrupt Control
    * Register DMA_ADICRz */
    0x00000088U,
    /* Configuration for DMA Channel Configuration Register DMA_CHCFGRz */
    0x00000000U,
    /* Configuration for DMA Channel Shadow Address Register DMA_SHADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: Shadow SFR access */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Shadow SFR access */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
#define DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_256
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of MoveEngine Notification
* before #include memap.h - Accepted deviation in AUTOSAR */
#include "Dma_MemMap.h"

                            
                    
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
#define DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE0_256
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is
* repeatedly included without include guard. This is
* as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of
* MoveEngine Notification before #include memap.h
* - Accepted deviation in AUTOSAR */
/* [cover parentID={5713A17A-3FA1-427f-A0B6-89125A17689A}]
* Const Section
* [/cover]*/
/* [cover parentID={E4047F9A-8865-4b2c-9D3C-385479854EAD}]
* Const Section
* [/cover]*/
#include "Dma_MemMap.h"

/* DMA channel 0 Transaction set control Configuration */
static const Dma_TransactionCtrlSetType Dma_kChannel_0_TcsConfigRoot[]=
{
  /* Dma Channel 0 TCS 0 */
  {
    /* Configuration for DMA source address register DMA_SADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: Shadow SFR access */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Shadow SFR access */
    (uint32 *)0x00000000U,
    /* Configuration for DMA destination address register DMA_DADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: Shadow SFR access */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Shadow SFR access */
    (uint32 *)0x00000000U,
    /* Configuration for DMA Channel Address and Interrupt Control
    * Register DMA_ADICRz */
    0x00000088U,
    /* Configuration for DMA Channel Configuration Register DMA_CHCFGRz */
    0x00000000U,
    /* Configuration for DMA Channel Shadow Address Register DMA_SHADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: Shadow SFR access */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Shadow SFR access */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
#define DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_256
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of MoveEngine Notification
* before #include memap.h - Accepted deviation in AUTOSAR */
#include "Dma_MemMap.h"

                            
                    
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
#define DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE0_256
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is
* repeatedly included without include guard. This is
* as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of
* MoveEngine Notification before #include memap.h
* - Accepted deviation in AUTOSAR */
/* [cover parentID={5713A17A-3FA1-427f-A0B6-89125A17689A}]
* Const Section
* [/cover]*/
/* [cover parentID={E4047F9A-8865-4b2c-9D3C-385479854EAD}]
* Const Section
* [/cover]*/
#include "Dma_MemMap.h"

/* DMA channel 3 Transaction set control Configuration */
static const Dma_TransactionCtrlSetType Dma_kChannel_3_TcsConfigRoot[]=
{
  /* Dma Channel 3 TCS 0 */
  {
    /* Configuration for DMA source address register DMA_SADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: Shadow SFR access */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Shadow SFR access */
    (uint32 *)0x00000000U,
    /* Configuration for DMA destination address register DMA_DADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: Shadow SFR access */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Shadow SFR access */
    (uint32 *)0x00000000U,
    /* Configuration for DMA Channel Address and Interrupt Control
    * Register DMA_ADICRz */
    0x00000088U,
    /* Configuration for DMA Channel Configuration Register DMA_CHCFGRz */
    0x00000000U,
    /* Configuration for DMA Channel Shadow Address Register DMA_SHADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: Shadow SFR access */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Shadow SFR access */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
#define DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_256
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of MoveEngine Notification
* before #include memap.h - Accepted deviation in AUTOSAR */
#include "Dma_MemMap.h"

                            
                    
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
#define DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE0_256
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is
* repeatedly included without include guard. This is
* as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of
* MoveEngine Notification before #include memap.h
* - Accepted deviation in AUTOSAR */
/* [cover parentID={5713A17A-3FA1-427f-A0B6-89125A17689A}]
* Const Section
* [/cover]*/
/* [cover parentID={E4047F9A-8865-4b2c-9D3C-385479854EAD}]
* Const Section
* [/cover]*/
#include "Dma_MemMap.h"

/* DMA channel 4 Transaction set control Configuration */
static const Dma_TransactionCtrlSetType Dma_kChannel_4_TcsConfigRoot[]=
{
  /* Dma Channel 4 TCS 0 */
  {
    /* Configuration for DMA source address register DMA_SADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: Shadow SFR access */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Shadow SFR access */
    (uint32 *)0x00000000U,
    /* Configuration for DMA destination address register DMA_DADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: Shadow SFR access */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Shadow SFR access */
    (uint32 *)0x00000000U,
    /* Configuration for DMA Channel Address and Interrupt Control
    * Register DMA_ADICRz */
    0x08000088U,
    /* Configuration for DMA Channel Configuration Register DMA_CHCFGRz */
    0x00000000U,
    /* Configuration for DMA Channel Shadow Address Register DMA_SHADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: Shadow SFR access */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Shadow SFR access */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
#define DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_256
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of MoveEngine Notification
* before #include memap.h - Accepted deviation in AUTOSAR */
#include "Dma_MemMap.h"

                            
                    
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going
* beyond 32 chars because of naming convention*/
#define DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE0_256
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is
* repeatedly included without include guard. This is
* as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of
* MoveEngine Notification before #include memap.h
* - Accepted deviation in AUTOSAR */
/* [cover parentID={5713A17A-3FA1-427f-A0B6-89125A17689A}]
* Const Section
* [/cover]*/
/* [cover parentID={E4047F9A-8865-4b2c-9D3C-385479854EAD}]
* Const Section
* [/cover]*/
#include "Dma_MemMap.h"

/* DMA channel 5 Transaction set control Configuration */
static const Dma_TransactionCtrlSetType Dma_kChannel_5_TcsConfigRoot[]=
{
  /* Dma Channel 5 TCS 0 */
  {
    /* Configuration for DMA source address register DMA_SADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: Shadow SFR access */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Shadow SFR access */
    (uint32 *)0x00000000U,
    /* Configuration for DMA destination address register DMA_DADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: Shadow SFR access */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Shadow SFR access */
    (uint32 *)0x00000000U,
    /* Configuration for DMA Channel Address and Interrupt Control
    * Register DMA_ADICRz */
    0x08000088U,
    /* Configuration for DMA Channel Configuration Register DMA_CHCFGRz */
    0x00000000U,
    /* Configuration for DMA Channel Shadow Address Register DMA_SHADRz */
    /* MISRA2012_RULE_11_6_JUSTIFICATION: Shadow SFR access */
    /* MISRA2012_RULE_11_4_JUSTIFICATION: Shadow SFR access */
  }
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
#define DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_256
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of MoveEngine Notification
* before #include memap.h - Accepted deviation in AUTOSAR */
#include "Dma_MemMap.h"

/* ************************************************************** */



/* [cover parentID={416F272A-A694-48be-ABDE-72991E89C5B4}]
Dma_kChConfigRoot_Core
[/cover] */

/* *************** Channel root configuration list ************** */


/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
#define DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of MoveEngine Notification
* before #include memap.h - Accepted deviation in AUTOSAR */
#include "Dma_MemMap.h"
/* Configuration of all the DMA channels */
static const Dma_ChConfigType Dma_kChConfigRoot_Core0[]=
{
    {
    &Dma_kChannel_8_TcsConfigRoot[0U], /* TCS config Root */
    QSPI0RX_DMACallout, /* Channel Notification */
    0x00000000U, /* TSR configuration */
    (uint8)8U, /* Dma Channel ID */
    (uint8)0x0U, /* Channel Assigned partition */
    NULL_PTR /* Error Notification */
  },
    {
    &Dma_kChannel_9_TcsConfigRoot[0U], /* TCS config Root */
    QSPI0TX_DMACallout, /* Channel Notification */
    0x00000000U, /* TSR configuration */
    (uint8)9U, /* Dma Channel ID */
    (uint8)0x0U, /* Channel Assigned partition */
    NULL_PTR /* Error Notification */
  },
    {
    &Dma_kChannel_6_TcsConfigRoot[0U], /* TCS config Root */
    QSPI1RX_DMACallout, /* Channel Notification */
    0x00000000U, /* TSR configuration */
    (uint8)6U, /* Dma Channel ID */
    (uint8)0x0U, /* Channel Assigned partition */
    NULL_PTR /* Error Notification */
  },
    {
    &Dma_kChannel_7_TcsConfigRoot[0U], /* TCS config Root */
    QSPI1TX_DMACallout, /* Channel Notification */
    0x00000000U, /* TSR configuration */
    (uint8)7U, /* Dma Channel ID */
    (uint8)0x0U, /* Channel Assigned partition */
    NULL_PTR /* Error Notification */
  },
    {
    &Dma_kChannel_0_TcsConfigRoot[0U], /* TCS config Root */
    QSPI2RX_DMACallout, /* Channel Notification */
    0x00000000U, /* TSR configuration */
    (uint8)0U, /* Dma Channel ID */
    (uint8)0x0U, /* Channel Assigned partition */
    NULL_PTR /* Error Notification */
  },
    {
    &Dma_kChannel_3_TcsConfigRoot[0U], /* TCS config Root */
    QSPI2TX_DMACallout, /* Channel Notification */
    0x00000000U, /* TSR configuration */
    (uint8)3U, /* Dma Channel ID */
    (uint8)0x0U, /* Channel Assigned partition */
    NULL_PTR /* Error Notification */
  },
    {
    &Dma_kChannel_4_TcsConfigRoot[0U], /* TCS config Root */
    QSPI3RX_DMACallout, /* Channel Notification */
    0x00000000U, /* TSR configuration */
    (uint8)4U, /* Dma Channel ID */
    (uint8)0x0U, /* Channel Assigned partition */
    NULL_PTR /* Error Notification */
  },
    {
    &Dma_kChannel_5_TcsConfigRoot[0U], /* TCS config Root */
    QSPI3TX_DMACallout, /* Channel Notification */
    0x00000000U, /* TSR configuration */
    (uint8)5U, /* Dma Channel ID */
    (uint8)0x0U, /* Channel Assigned partition */
    NULL_PTR /* Error Notification */
  }};
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
#define DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of MoveEngine Notification
* before #include memap.h - Accepted deviation in AUTOSAR */
#include "Dma_MemMap.h"





/* *************************************************************** */



/* [cover parentID={CE1183AE-EDA0-404c-B75F-70B07380424E}]
Dma_ChConfigRootCoreX
[/cover] */

/* ************* Configuration structure of each core ************* */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
#define DMA_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of MoveEngine Notification
* before #include memap.h - Accepted deviation in AUTOSAR */
#include "Dma_MemMap.h"
static const Dma_CoreSpecificChConfigType Dma_ChConfigRootCore0=
{
  /* Core specific config pointer */
  &Dma_kChConfigRoot_Core0[0],
    /* Total number of DMA channels in core 0 */
  
  8
};
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
#define DMA_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of MoveEngine Notification
* before #include memap.h - Accepted deviation in AUTOSAR */
#include "Dma_MemMap.h"
/* **************************************************************** */


/* [cover parentID={5D84DC08-6409-4201-903B-A8C9F4EEC524}]
Dma_Config
[/cover] */

/* ************* Base Configuration Structure of DMA ************* */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
#define DMA_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of MoveEngine Notification
* before #include memap.h - Accepted deviation in AUTOSAR */
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
#include "Dma_MemMap.h"
/* MISRA2012_RULE_8_7_JUSTIFICATION: Module configuration data structure
declaration as per Autosar guidelines. This data structure may be needed
by SW units using Mcu Driver APIs */
/* MISRA2012_RULE_8_4_JUSTIFICATION: Definition is as per Autosar guidelines */
const Dma_ConfigType Dma_Config=
{
  
  {
    /* Channel Configuration root for Core 0*/
    /* This is the number of resources:0 */
    &Dma_ChConfigRootCore0,
    /* Channel Configuration root for Core 1*/
    /* This is the number of resources:0 */
    NULL_PTR,
    /* Channel Configuration root for Core 2*/
    /* This is the number of resources:0 */
    NULL_PTR,
    /* Channel Configuration root for Core 3*/
    /* This is the number of resources:0 */
    NULL_PTR,
    /* Channel Configuration root for Core 4*/
    /* This is the number of resources:0 */
    NULL_PTR,
    /* Channel Configuration root for Core 5*/
    /* This is the number of resources:0 */
    NULL_PTR,
  },
  
  
  /* MoveEngine Error config for ME0 and ME1 */
  {0X00000000U,0X00000000U},
  /* Access partition configuration */
  {
    /* Bus master configuration */
    {0XFFFFFFFFU,0XFFFFFFFFU,0XFFFFFFFFU,0XFFFFFFFFU},
    /* Resource partition configuration */
    {0X01U,0X01U,0X01U,0X01U}
  },
  /* { Channel Position Index, Channel Core Map } - The mapping data of channels */
  {
    {4, 0 }, /* Channel 0 */
    {255, 255 }, /* Channel 1 */
    {255, 255 }, /* Channel 2 */
    {5, 0 }, /* Channel 3 */
    {6, 0 }, /* Channel 4 */
    {7, 0 }, /* Channel 5 */
    {2, 0 }, /* Channel 6 */
    {3, 0 }, /* Channel 7 */
    {0, 0 }, /* Channel 8 */
    {1, 0 }, /* Channel 9 */
    {255, 255 }, /* Channel 10 */
    {255, 255 }, /* Channel 11 */
    {255, 255 }, /* Channel 12 */
    {255, 255 }, /* Channel 13 */
    {255, 255 }, /* Channel 14 */
    {255, 255 }, /* Channel 15 */
    {255, 255 }, /* Channel 16 */
    {255, 255 }, /* Channel 17 */
    {255, 255 }, /* Channel 18 */
    {255, 255 }, /* Channel 19 */
    {255, 255 }, /* Channel 20 */
    {255, 255 }, /* Channel 21 */
    {255, 255 }, /* Channel 22 */
    {255, 255 }, /* Channel 23 */
    {255, 255 }, /* Channel 24 */
    {255, 255 }, /* Channel 25 */
    {255, 255 }, /* Channel 26 */
    {255, 255 }, /* Channel 27 */
    {255, 255 }, /* Channel 28 */
    {255, 255 }, /* Channel 29 */
    {255, 255 }, /* Channel 30 */
    {255, 255 }, /* Channel 31 */
    {255, 255 }, /* Channel 32 */
    {255, 255 }, /* Channel 33 */
    {255, 255 }, /* Channel 34 */
    {255, 255 }, /* Channel 35 */
    {255, 255 }, /* Channel 36 */
    {255, 255 }, /* Channel 37 */
    {255, 255 }, /* Channel 38 */
    {255, 255 }, /* Channel 39 */
    {255, 255 }, /* Channel 40 */
    {255, 255 }, /* Channel 41 */
    {255, 255 }, /* Channel 42 */
    {255, 255 }, /* Channel 43 */
    {255, 255 }, /* Channel 44 */
    {255, 255 }, /* Channel 45 */
    {255, 255 }, /* Channel 46 */
    {255, 255 }, /* Channel 47 */
    {255, 255 }, /* Channel 48 */
    {255, 255 }, /* Channel 49 */
    {255, 255 }, /* Channel 50 */
    {255, 255 }, /* Channel 51 */
    {255, 255 }, /* Channel 52 */
    {255, 255 }, /* Channel 53 */
    {255, 255 }, /* Channel 54 */
    {255, 255 }, /* Channel 55 */
    {255, 255 }, /* Channel 56 */
    {255, 255 }, /* Channel 57 */
    {255, 255 }, /* Channel 58 */
    {255, 255 }, /* Channel 59 */
    {255, 255 }, /* Channel 60 */
    {255, 255 }, /* Channel 61 */
    {255, 255 }, /* Channel 62 */
    {255, 255 }, /* Channel 63 */
    {255, 255 }, /* Channel 64 */
    {255, 255 }, /* Channel 65 */
    {255, 255 }, /* Channel 66 */
    {255, 255 }, /* Channel 67 */
    {255, 255 }, /* Channel 68 */
    {255, 255 }, /* Channel 69 */
    {255, 255 }, /* Channel 70 */
    {255, 255 }, /* Channel 71 */
    {255, 255 }, /* Channel 72 */
    {255, 255 }, /* Channel 73 */
    {255, 255 }, /* Channel 74 */
    {255, 255 }, /* Channel 75 */
    {255, 255 }, /* Channel 76 */
    {255, 255 }, /* Channel 77 */
    {255, 255 }, /* Channel 78 */
    {255, 255 }, /* Channel 79 */
    {255, 255 }, /* Channel 80 */
    {255, 255 }, /* Channel 81 */
    {255, 255 }, /* Channel 82 */
    {255, 255 }, /* Channel 83 */
    {255, 255 }, /* Channel 84 */
    {255, 255 }, /* Channel 85 */
    {255, 255 }, /* Channel 86 */
    {255, 255 }, /* Channel 87 */
    {255, 255 }, /* Channel 88 */
    {255, 255 }, /* Channel 89 */
    {255, 255 }, /* Channel 90 */
    {255, 255 }, /* Channel 91 */
    {255, 255 }, /* Channel 92 */
    {255, 255 }, /* Channel 93 */
    {255, 255 }, /* Channel 94 */
    {255, 255 }, /* Channel 95 */
    {255, 255 }, /* Channel 96 */
    {255, 255 }, /* Channel 97 */
    {255, 255 }, /* Channel 98 */
    {255, 255 }, /* Channel 99 */
    {255, 255 }, /* Channel 100 */
    {255, 255 }, /* Channel 101 */
    {255, 255 }, /* Channel 102 */
    {255, 255 }, /* Channel 103 */
    {255, 255 }, /* Channel 104 */
    {255, 255 }, /* Channel 105 */
    {255, 255 }, /* Channel 106 */
    {255, 255 }, /* Channel 107 */
    {255, 255 }, /* Channel 108 */
    {255, 255 }, /* Channel 109 */
    {255, 255 }, /* Channel 110 */
    {255, 255 }, /* Channel 111 */
    {255, 255 }, /* Channel 112 */
    {255, 255 }, /* Channel 113 */
    {255, 255 }, /* Channel 114 */
    {255, 255 }, /* Channel 115 */
    {255, 255 }, /* Channel 116 */
    {255, 255 }, /* Channel 117 */
    {255, 255 }, /* Channel 118 */
    {255, 255 }, /* Channel 119 */
    {255, 255 }, /* Channel 120 */
    {255, 255 }, /* Channel 121 */
    {255, 255 }, /* Channel 122 */
    {255, 255 }, /* Channel 123 */
    {255, 255 }, /* Channel 124 */
    {255, 255 }, /* Channel 125 */
    {255, 255 }, /* Channel 126 */
    {255, 255 }, /* Channel 127 */
  },
  0X00000008U,
};
/* ************************************************************** */


/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars
* because of naming convention*/
#define DMA_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: Dma_Memmap.h is repeatedly included
* without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: declaration of MoveEngine Notification
* before #include memap.h - Accepted deviation in AUTOSAR */
#include "Dma_MemMap.h"
