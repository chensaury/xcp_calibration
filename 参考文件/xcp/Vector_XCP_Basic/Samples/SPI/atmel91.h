/* Kernbauer Version: 1.08 Konfiguration: AT91 Erzeugungsgangnummer: 71 */

/*****************************************************************************
| Project Name: OSEK 2.1
|    File Name: atmel91.h
|
|  Module version: $vv$=0.50
|
|  Description: definitions for ATMEL AT91M40400
|
|-----------------------------------------------------------------------------
|               C O P Y R I G H T
|-----------------------------------------------------------------------------
| Copyright (c) 2000 Vector Informatik GmbH               All rights reserved.
|****************************************************************************/

/* double include preventer */
#ifndef _ATMEL91_H
#define _ATMEL91_H

/* Vector release management */
#include <vrm.h>
/* KB begin vrmReleaseNumber */
/* Source release number */
#define osdVrmMajRelNum 2
#define osdVrmMinRelNum 90
/* KB end vrmReleaseNumber */
#include <vrm.h>


#define osd_EBI_CSR0      0xFFE00000
#define osd_EBI_CSR1      0xFFE00004
#define osd_EBI_CSR2      0xFFE00008
#define osd_EBI_CSR3      0xFFE0000C
#define osd_EBI_CSR4      0xFFE00010
#define osd_EBI_CSR5      0xFFE00014
#define osd_EBI_CSR6      0xFFE00018
#define osd_EBI_CSR7      0xFFE0001C
#define osd_EBI_RCR       0xFFE00020
#define osd_EBI_MCR       0xFFE00024


#define osd_AIC_SMR0      0xFFFFF000
#define osd_AIC_SMR1      0xFFFFF004
#define osd_AIC_SMR2      0xFFFFF008
#define osd_AIC_SMR3      0xFFFFF00C
#define osd_AIC_SMR4      0xFFFFF010
#define osd_AIC_SMR5      0xFFFFF014
#define osd_AIC_SMR6      0xFFFFF018
#define osd_AIC_SMR7      0xFFFFF01C
#define osd_AIC_SMR8      0xFFFFF020
#define osd_AIC_SMR9      0xFFFFF024
#define osd_AIC_SMR10     0xFFFFF028
#define osd_AIC_SMR11     0xFFFFF02C
#define osd_AIC_SMR12     0xFFFFF030
#define osd_AIC_SMR13     0xFFFFF034
#define osd_AIC_SMR14     0xFFFFF038
#define osd_AIC_SMR15     0xFFFFF03C
#define osd_AIC_SMR16     0xFFFFF040
#define osd_AIC_SMR17     0xFFFFF044
#define osd_AIC_SMR18     0xFFFFF048
#define osd_AIC_SMR19     0xFFFFF04C
#define osd_AIC_SMR20     0xFFFFF050
#define osd_AIC_SMR21     0xFFFFF054
#define osd_AIC_SMR22     0xFFFFF058
#define osd_AIC_SMR23     0xFFFFF05C
#define osd_AIC_SMR24     0xFFFFF060
#define osd_AIC_SMR25     0xFFFFF064
#define osd_AIC_SMR26     0xFFFFF068
#define osd_AIC_SMR27     0xFFFFF06C
#define osd_AIC_SMR28     0xFFFFF070
#define osd_AIC_SMR29     0xFFFFF074
#define osd_AIC_SMR30     0xFFFFF078
#define osd_AIC_SMR31     0xFFFFF07C


#define osd_AIC_SVR0      0xFFFFF080
#define osd_AIC_SVR1      0xFFFFF084
#define osd_AIC_SVR2      0xFFFFF088
#define osd_AIC_SVR3      0xFFFFF08C
#define osd_AIC_SVR4      0xFFFFF090
#define osd_AIC_SVR5      0xFFFFF094
#define osd_AIC_SVR6      0xFFFFF098
#define osd_AIC_SVR7      0xFFFFF09C
#define osd_AIC_SVR8      0xFFFFF0A0
#define osd_AIC_SVR9      0xFFFFF0A4
#define osd_AIC_SVR10     0xFFFFF0A8
#define osd_AIC_SVR11     0xFFFFF0AC
#define osd_AIC_SVR12     0xFFFFF0B0
#define osd_AIC_SVR13     0xFFFFF0B4
#define osd_AIC_SVR14     0xFFFFF0B8
#define osd_AIC_SVR15     0xFFFFF0BC
#define osd_AIC_SVR16     0xFFFFF0C0
#define osd_AIC_SVR17     0xFFFFF0C4
#define osd_AIC_SVR18     0xFFFFF0C8
#define osd_AIC_SVR19     0xFFFFF0CC
#define osd_AIC_SVR20     0xFFFFF0D0
#define osd_AIC_SVR21     0xFFFFF0D4
#define osd_AIC_SVR22     0xFFFFF0D8
#define osd_AIC_SVR23     0xFFFFF0DC
#define osd_AIC_SVR24     0xFFFFF0E0
#define osd_AIC_SVR25     0xFFFFF0E4
#define osd_AIC_SVR26     0xFFFFF0E8
#define osd_AIC_SVR27     0xFFFFF0EC
#define osd_AIC_SVR28     0xFFFFF0F0
#define osd_AIC_SVR29     0xFFFFF0F4
#define osd_AIC_SVR30     0xFFFFF0F8
#define osd_AIC_SVR31     0xFFFFF0FC


#define osd_AIC_IVR       0xFFFFF100
#define osd_AIC_FVR       0xFFFFF104
#define osd_AIC_ISR       0xFFFFF108
#define osd_AIC_IPR       0xFFFFF10C
#define osd_AIC_IMR       0xFFFFF110
#define osd_AIC_CISR      0xFFFFF114
#define osd_AIC_IECR      0xFFFFF120
#define osd_AIC_IDCR      0xFFFFF124
#define osd_AIC_ICCR      0xFFFFF128
#define osd_AIC_ISCR      0xFFFFF12C
#define osd_AIC_EOICR     0xFFFFF130
#define osd_AIC_SPU       0xFFFFF134


#define osd_PIO_PER       0xFFFF0000
#define osd_PIO_PDR       0xFFFF0004
#define osd_PIO_PSR       0xFFFF0008
#define osd_PIO_OER       0xFFFF0010
#define osd_PIO_ODR       0xFFFF0014
#define osd_PIO_OSR       0xFFFF0018
#define osd_PIO_IFER      0xFFFF0020
#define osd_PIO_IFDR      0xFFFF0024
#define osd_PIO_IFSR      0xFFFF0028
#define osd_PIO_SODR      0xFFFF0030
#define osd_PIO_CODR      0xFFFF0034
#define osd_PIO_ODSR      0xFFFF0038
#define osd_PIO_PDSR      0xFFFF003C
#define osd_PIO_IER       0xFFFF0040
#define osd_PIO_IDR       0xFFFF0044
#define osd_PIO_IMR       0xFFFF0048
#define osd_PIO_ISR       0xFFFF004C

#define osd_TC0_CCR       0xFFFE0000
#define osd_TC0_CMR       0xFFFE0004
#define osd_TC0_CV        0xFFFE0010
#define osd_TC0_RA        0xFFFE0014
#define osd_TC0_RB        0xFFFE0018
#define osd_TC0_RC        0xFFFE001C
#define osd_TC0_SR        0xFFFE0020
#define osd_TC0_IER       0xFFFE0024
#define osd_TC0_IDR       0xFFFE0028
#define osd_TC0_IMR       0xFFFE002C

#define osd_TC1_CCR       0xFFFE0040
#define osd_TC1_CMR       0xFFFE0044
#define osd_TC1_CV        0xFFFE0050
#define osd_TC1_RA        0xFFFE0054
#define osd_TC1_RB        0xFFFE0058
#define osd_TC1_RC        0xFFFE005C
#define osd_TC1_SR        0xFFFE0060
#define osd_TC1_IER       0xFFFE0064
#define osd_TC1_IDR       0xFFFE0068
#define osd_TC1_IMR       0xFFFE006C

#ifdef osdAT91M63200
#define osd_TC2_CCR       0xFFFD0000
#define osd_TC2_CMR       0xFFFD0004
#define osd_TC2_CV        0xFFFD0010
#define osd_TC2_RA        0xFFFD0014
#define osd_TC2_RB        0xFFFD0018
#define osd_TC2_RC        0xFFFD001C
#define osd_TC2_SR        0xFFFD0020
#define osd_TC2_IER       0xFFFD0024
#define osd_TC2_IDR       0xFFFD0028
#define osd_TC2_IMR       0xFFFD002C
#else
#define osd_TC2_CCR       0xFFFE0080
#define osd_TC2_CMR       0xFFFE0084
#define osd_TC2_CV        0xFFFE0090
#define osd_TC2_RA        0xFFFE0094
#define osd_TC2_RB        0xFFFE0098
#define osd_TC2_RC        0xFFFE009C
#define osd_TC2_SR        0xFFFE00A0
#define osd_TC2_IER       0xFFFE00A4
#define osd_TC2_IDR       0xFFFE00A8
#define osd_TC2_IMR       0xFFFE00AC
#endif

#define osd_TC_BCR        0xFFFE00C0
#define osd_TC_BMR        0xFFFE00C4

#define osd_WD_OMR        0xFFFF8000
#define osd_WD_CMR        0xFFFF8004
#define osd_WD_CR         0xFFFF8008
#define osd_WD_SR         0xFFFF800C

// PowerManagement 
#define PMC_SPI_CLK_EN    0x0020
#define PMC_TC3_CLK_EN    0x0200

#endif




