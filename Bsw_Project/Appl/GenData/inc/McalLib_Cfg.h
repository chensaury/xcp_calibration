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
**  FILENAME  : McalLib_Cfg.h                                                 **
**                                                                            **
**  VERSION   : 6.0.0                                                         **
**                                                                            **
**  DATE, TIME: 2023-05-24, 20:20:14                                      **
**                                                                            **
**  GENERATOR : Build b170330-0431                                          **
**                                                                            **
**  BSW MODULE DECRIPTION : McalLib.bmd                                       **
**                                                                            **
**  VARIANT   : Variant PC                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : McalLib configuration generated out of ECUC file           **
**                                                                            **
**  SPECIFICATION(S) : Specification of McalLib Driver                        **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
#ifndef MCALLIB_CFG_H
#define MCALLIB_CFG_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

#define MCALLIB_AR_RELEASE_MAJOR_VERSION      (4U)
#define MCALLIB_AR_RELEASE_MINOR_VERSION      (2U)
#define MCALLIB_AR_RELEASE_REVISION_VERSION   (2U)

#define MCALLIB_SW_MAJOR_VERSION  (3U)
#define MCALLIB_SW_MINOR_VERSION  (0U)
#define MCALLIB_SW_PATCH_VERSION  (0U)

/*Number of cores available*/
#define MCAL_NO_OF_CORES              (0x6U)

/* Backup clock frequency in MHz */
#define MCAL_BACKUP_FREQUENCY         (0x64U)

/* System clock frequency in MHz*/
#define MCAL_SYSCLK_FREQUENCY         (0x14U)

/* Global PSPR base address */

#define MCAL_PSPR0_GLOBAL_BASE_ADDR   (0x70100000U)
#define MCAL_PSPR1_GLOBAL_BASE_ADDR   (0x60100000U)
#define MCAL_PSPR2_GLOBAL_BASE_ADDR   (0x50100000U)
#define MCAL_PSPR3_GLOBAL_BASE_ADDR   (0x40100000U)
#define MCAL_PSPR4_GLOBAL_BASE_ADDR   (0x30100000U)
#define MCAL_PSPR5_GLOBAL_BASE_ADDR   (0x10100000U)

/* Global PSPR End address */
#define MCAL_PSPR0_GLOBAL_END_ADDR   (0x7010ffffU)
#define MCAL_PSPR1_GLOBAL_END_ADDR   (0x6010ffffU)
#define MCAL_PSPR2_GLOBAL_END_ADDR   (0x5010ffffU)
#define MCAL_PSPR3_GLOBAL_END_ADDR   (0x4010ffffU)
#define MCAL_PSPR4_GLOBAL_END_ADDR   (0x3010ffffU)
#define MCAL_PSPR5_GLOBAL_END_ADDR   (0x1010ffffU)

/* Global DSPR base address */
#define MCAL_DSPR0_GLOBAL_BASE_ADDR    (0x70000000U)
#define MCAL_DSPR1_GLOBAL_BASE_ADDR    (0x60000000U)
#define MCAL_DSPR2_GLOBAL_BASE_ADDR    (0x50000000U)
#define MCAL_DSPR3_GLOBAL_BASE_ADDR    (0x40000000U)
#define MCAL_DSPR4_GLOBAL_BASE_ADDR    (0x30000000U)
#define MCAL_DSPR5_GLOBAL_BASE_ADDR    (0x10000000U)

/* Global DSPR End address */
#define MCAL_DSPR0_GLOBAL_END_ADDR   (0x7003bfffU)
#define MCAL_DSPR1_GLOBAL_END_ADDR   (0x6003bfffU)
#define MCAL_DSPR2_GLOBAL_END_ADDR   (0x50017fffU)
#define MCAL_DSPR3_GLOBAL_END_ADDR   (0x40017fffU)
#define MCAL_DSPR4_GLOBAL_END_ADDR   (0x30017fffU)
#define MCAL_DSPR5_GLOBAL_END_ADDR   (0x10017fffU)

/*
Configuration: MCALLIB_SAFETY_ENABLE:
Compile switch to enable/disable the Safety Enable API
- ON if McalLibSafetyEnable   is true
- OFF if McalLibSafetyEnable   is false
*/
#define  MCALLIB_SAFETY_ENABLE          (STD_OFF)
                                  
/*For retriving the Master Core ID */
#define MCAL_MASTER_COREID                 ((uint32)0U)
#endif  /* MCALLIB_CFG_H */

