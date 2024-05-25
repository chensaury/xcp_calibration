
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
**  FILENAME  : Spi_Cfg.h                                                     **
**                                                                            **
**  VERSION   : 8.0.0                                                         **
**                                                                            **
**  DATE, TIME: 2024-02-23, 10:02:41                                      **
**                                                                            **
**  GENERATOR : Build b170330-0431                                          **
**                                                                            **
**  BSW MODULE DECRIPTION : Spi.bmd                                           **
**                                                                            **
**  VARIANT   : Variant PB                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Spi configuration generated out of ECUC file               **
**                                                                            **
**  SPECIFICATION(S) : Specification of Spi Driver, AUTOSAR Release 4.2.2     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/


/* To avoid multiple inclusion of the header file more than once */
#ifndef SPI_CFG_H
#define SPI_CFG_H



/* Section to Generate Autosar Specific Version Information */
#define SPI_AR_RELEASE_MAJOR_VERSION          (4U)
#define SPI_AR_RELEASE_MINOR_VERSION          (2U)
#define SPI_AR_RELEASE_REVISION_VERSION       (2U)



/* Section to Generate Vendor Specific Version Information */
/* Vendor specific implementation version information      */
#define SPI_SW_MAJOR_VERSION                  (2U)
#define SPI_SW_MINOR_VERSION                  (0U)
#define SPI_SW_PATCH_VERSION                  (0U)


/* Pre-Compile parameters */

/* (Development Error)/(Default Error) Trace */

#define SPI_DEV_ERROR_DETECT                  (STD_OFF)



/* Safety error check */
#define SPI_SAFETY_ENABLE                  (STD_OFF)


/* Dem reporting  macros */
#define SPI_DEM_REPORT_DISABLED               (0U)
#define SPI_DEM_REPORT_ENABLED                (1U)

/* Dem Related Macros */
#define SPI_HW_ERROR_DEM_REPORT               (SPI_DEM_REPORT_DISABLED)

/* Kind of transmission available,
   0 - Only Synchronous Transmission
   1 - Only Asynchronous Transmission(Interrupt mode only)
   2 - Both Sync and Async(Both Interrupt and Polling Mode) Transmission */


#define SPI_LEVEL_DELIVERED                   (2U)

/* Main function period - Used by application to poll the SPI Hw module */


#define SPI_MAIN_FUNCTION_PERIOD              (0.01U)

/* Kind of Channele buffers allowed
   0 - Only Internal buffers allowed
   1 - Only External buffers allowed
   2 - Both Internal and External buffers allowed */


#define SPI_CHANNEL_BUFFERS_ALLOWED           (1U)

/* Specifies if the API Spi_Cancel() is available */


#define SPI_CANCEL_API                        (STD_ON)

/* Specifies if the API Spi_GetHWUnitStatus() is available */


#define SPI_HW_STATUS_API                     (STD_ON)

/* Specifies if the API Spi_GetVersionInfo() is available */

#define SPI_VERSION_INFO_API                  (STD_OFF)

/* Specifies if Sequences can be interrupted during
   transmission. For Level = 0, its value is STD_OFF by default */


#define SPI_INTERRUPTIBLE_SEQ_ALLOWED         (STD_ON)

/* Configuration Options:
   SPI Sequence Interruptible Options */
#define SPI_SEQ_INT_FALSE                     ((uint8)0U)
#define SPI_SEQ_INT_TRUE                      ((uint8)1U)

/* Specifies if concurrent transmission of synchronous
   sequences are allowed. For Level = 1, its value is STD_OFF by default */

#define SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT  (STD_OFF)

/* Maximum QSPI Hw units available */


#define SPI_MAX_HW_UNIT                       (6U)

#define SPI_SYNC_BUS                          (0U)
#define SPI_ASYNC_BUS                         (1U)

/* Is QSPI0 Used */
#define SPI_HW_QSPI0_USED                     (STD_ON)
/* Index for QSPI0 module */
#define SPI_QSPI0_INDEX                       (0U)
/* Sync/Async */
#define SPI_QSPI0_HWTYPE                      (SPI_ASYNC_BUS)

/* Is QSPI1 Used */
#define SPI_HW_QSPI1_USED                     (STD_ON)
  /* Index for QSPI1module */
#define SPI_QSPI1_INDEX                       (1U)
/* Sync/Async */
#define SPI_QSPI1_HWTYPE                      (SPI_ASYNC_BUS)

/* Is QSPI2 Used */
#define SPI_HW_QSPI2_USED                     (STD_ON)
/* Index for QSPI2 module */
#define SPI_QSPI2_INDEX                       (2U)
/* Sync/Async */
#define SPI_QSPI2_HWTYPE                      (SPI_ASYNC_BUS)

/* Is QSPI3 Used */
#define SPI_HW_QSPI3_USED                     (STD_ON)
/* Index for QSPI3 module */
#define SPI_QSPI3_INDEX                       (3U)
/* Sync/Async */
#define SPI_QSPI3_HWTYPE                      (SPI_ASYNC_BUS)

/* Is QSPI4 Used */
#define SPI_HW_QSPI4_USED                     (STD_OFF)

/* Is QSPI5 Used */
#define SPI_HW_QSPI5_USED                     (STD_OFF)

/* Timeout value to wait for trail delay to be completed.
   Should be atleast greater than the Trail delay
   (also to avoid possible infinite loops) */
#define SPI_DELAY_TIMEOUT                     (0xFFFFFFFEU)

/* SPI Module is enabled,
   Module does not enter sleep mode upon sleep request */
#define SPI_CLK_SLEEP_DISABLE                 (0x00000008U)

/* SPI Module is enabled,
   Module enters sleep mode upon sleep request         */
#define SPI_CLK_SLEEP_ENABLE                  (0x00000000U)

/* Job Delimiter, marks end of Job */
#define SPI_JOB_DELIMITER                     ((uint16)0xFFFFU)

/* Sequence Delimiter, marks end of Sequence */
#define SPI_SEQUENCE_DELIMITER                ((uint8)0xFFU)

/* Channel Delimiter, marks the end of channel */
#define SPI_CHANNEL_DELIMITER                 ((uint8)0xFFU)

/* QSPI HW Delimiter, marks the end of QSPI module */
#define SPI_QSPI_HW_DELIMITER                 ((uint8)0xFFU)


/* Array size to store the 2-bit status of all the Jobs */
#define SPI_JOB_STATUS_ARRAY_INDEX            (1U)

/* Array size to store the 2-bit status of all the Sequence */
#define SPI_SEQUENCE_STATUS_ARRAY_INDEX       (1U)



/* IB buffer Size for Async QSPI0 */
#define SPI_ASYNC_IB_BUFFER_SIZE_QSPI0        (0U)



#define SPI_MAX_SEQUENCE_QSPI0                (1U)

/* IB buffer Size for Async QSPI1 */
#define SPI_ASYNC_IB_BUFFER_SIZE_QSPI1        (0U)


#define SPI_MAX_SEQUENCE_QSPI1                (6U)


/* IB buffer Size for Async QSPI2 */
#define SPI_ASYNC_IB_BUFFER_SIZE_QSPI2        (0U)



#define SPI_MAX_SEQUENCE_QSPI2                (1U)


/* IB buffer Size for Async QSPI3 */
#define SPI_ASYNC_IB_BUFFER_SIZE_QSPI3        (0U)


#define SPI_MAX_SEQUENCE_QSPI3                (1U)




#define SPI_ASYNC_IB_BUFFER_SIZE_CORE0           (0U)


/* IB Buffer Size for Sync QSPIx */
/*kernel 0*/
#define SPI_SYNC_IB_BUFFER_SIZE_QSPI0         (0U)
/*kernel 1*/
#define SPI_SYNC_IB_BUFFER_SIZE_QSPI1         (0U)
/*kernel 2*/
#define SPI_SYNC_IB_BUFFER_SIZE_QSPI2         (0U)
/*kernel 3*/
#define SPI_SYNC_IB_BUFFER_SIZE_QSPI3         (0U)

#define SPI_SYNC_IB_BUFFER_SIZE_CORE0            (0U)


/* Job Queue Length for QSPI1 */


#define SPI_JOB_QUEUE_LENGTH_QSPI0            (2U)

/* Job Queue Length for QSPI1 */
#define SPI_JOB_QUEUE_LENGTH_QSPI1            (12U)

/* Job Queue Length for QSPI2 */
#define SPI_JOB_QUEUE_LENGTH_QSPI2            (2U)

/* Job Queue Length for QSPI3 */
#define SPI_JOB_QUEUE_LENGTH_QSPI3            (2U)

/* Job Queue Length for QSPI4 */
#define SPI_JOB_QUEUE_LENGTH_QSPI4            (0U)

/* Job Queue Length for QSPI5 */
#define SPI_JOB_QUEUE_LENGTH_QSPI5            (0U)

/* QSPI Channel Index */
#define SPI_QSPI_CHANNEL0                     ((uint8)0U)
#define SPI_QSPI_CHANNEL1                     ((uint8)1U)
#define SPI_QSPI_CHANNEL2                     ((uint8)2U)
#define SPI_QSPI_CHANNEL3                     ((uint8)3U)
#define SPI_QSPI_CHANNEL4                     ((uint8)4U)
#define SPI_QSPI_CHANNEL5                     ((uint8)5U)
#define SPI_QSPI_CHANNEL6                     ((uint8)6U)
#define SPI_QSPI_CHANNEL7                     ((uint8)7U)
#define SPI_QSPI_CHANNEL8                     ((uint8)8U)
#define SPI_QSPI_CHANNEL9                     ((uint8)9U)
#define SPI_QSPI_CHANNEL10                    ((uint8)10U)
#define SPI_QSPI_CHANNEL11                    ((uint8)11U)
#define SPI_QSPI_CHANNEL12                    ((uint8)12U)
#define SPI_QSPI_CHANNEL13                    ((uint8)13U)
#define SPI_QSPI_CHANNEL14                    ((uint8)14U)
#define SPI_QSPI_CHANNEL15                    ((uint8)15U)



/* Number of IB channels on Async Hw */
/*Kernel 0*/
#define SPI_NUM_ASYNC_IB_CHANNELS_QSPI0       (0U)
/*Kernel 1*/
#define SPI_NUM_ASYNC_IB_CHANNELS_QSPI1       (0U)
/*Kernel 2*/
#define SPI_NUM_ASYNC_IB_CHANNELS_QSPI2       (0U)
/*Kernel 3*/
#define SPI_NUM_ASYNC_IB_CHANNELS_QSPI3       (0U)

/* Number of IB channels on Sync Hw */
/*Kernel 0*/
#define SPI_NUM_SYNC_IB_CHANNELS_QSPI0        (0U)
/*Kernel 1*/
#define SPI_NUM_SYNC_IB_CHANNELS_QSPI1        (0U)
/*Kernel 2*/
#define SPI_NUM_SYNC_IB_CHANNELS_QSPI2        (0U)
/*kernel 3*/
#define SPI_NUM_SYNC_IB_CHANNELS_QSPI3        (0U)


#define SPI_NUM_IB_CHANNELS_CORE0            (0U)

/* Number of IB channels */
#define SPI_NUM_IB_CHANNELS_QSPI0               (SPI_NUM_ASYNC_IB_CHANNELS_QSPI0 + SPI_NUM_SYNC_IB_CHANNELS_QSPI0)
#define SPI_NUM_IB_CHANNELS_QSPI1               (SPI_NUM_ASYNC_IB_CHANNELS_QSPI1 + SPI_NUM_SYNC_IB_CHANNELS_QSPI1)
#define SPI_NUM_IB_CHANNELS_QSPI2               (SPI_NUM_ASYNC_IB_CHANNELS_QSPI2 + SPI_NUM_SYNC_IB_CHANNELS_QSPI2)
#define SPI_NUM_IB_CHANNELS_QSPI3               (SPI_NUM_ASYNC_IB_CHANNELS_QSPI3 + SPI_NUM_SYNC_IB_CHANNELS_QSPI3)

#define SPI_CORE0_ENABLE     STD_ON
#define SPI_CORE1_ENABLE     STD_OFF
#define SPI_CORE2_ENABLE     STD_OFF
#define SPI_CORE3_ENABLE     STD_OFF
#define SPI_CORE4_ENABLE     STD_OFF
#define SPI_CORE5_ENABLE     STD_OFF

/* Macro will be used as the sixe for the WriteLock
   variable which is uint32 holds the status of the IB channel */
#define SPI_WRITE_LOCK_INDEX                  (1U)
/*kernel 0*/
#define SPI_WRITE_LOCK_INDEX_QSPI0            (1U)
/*kernel 1*/
#define SPI_WRITE_LOCK_INDEX_QSPI1            (1U)
/*kernel 2*/
#define SPI_WRITE_LOCK_INDEX_QSPI2            (1U)
/*kernel 3*/
#define SPI_WRITE_LOCK_INDEX_QSPI3            (1U)

/* Number of EB channels */
/*kernel 0*/
#define SPI_NUM_EB_CHANNELS_QSPI0            (1U)
/*kernel 1*/
#define SPI_NUM_EB_CHANNELS_QSPI1            (6U)
/*Kernel 2*/
#define SPI_NUM_EB_CHANNELS_QSPI2            (1U)
/*Kernel 3*/
#define SPI_NUM_EB_CHANNELS_QSPI3            (1U)


#define SPI_NUM_EB_CHANNELS_CORE0            (9U)


/* Number of Asynchronous QSPI master */
#define SPI_NUM_ASYNC_QSPI_MASTER             (4U)

/* Number of Synchronous QSPI master */
#define SPI_NUM_SYNC_QSPI_MASTER              (0U)

/* Number of QSPI master */
#define SPI_NUM_QSPI_MASTER                   (4U)

/* DMA Transaction control set per channel for QSPI0 */
#define SPI_DMA_MAX_TCS_NUM_QSPI0             (1U)

/* DMA Transaction control set per channel for QSPI1 */
#define SPI_DMA_MAX_TCS_NUM_QSPI1             (1U)

/* DMA Transaction control set per channel for QSPI2 */
#define SPI_DMA_MAX_TCS_NUM_QSPI2             (1U)

/* DMA Transaction control set per channel for QSPI3 */
#define SPI_DMA_MAX_TCS_NUM_QSPI3             (1U)



/* Indicates no CS to be done */
#define SPI_CS_VIA_HW_OR_NONE                 (0xFFFFU)

#define SPI_PARITY_EVEN                       (0U)
#define SPI_PARITY_ODD                        (1U)
#define SPI_PARITY_UNUSED                     (2U)

/* Configuration Options:
   Selection of Channel Buffer Type */
/* EB Buffer Channel Type */
#define SPI_EB_CHANNEL                        (0U)
/* IB Buffer Channel Type */
#define SPI_IB_CHANNEL                        (1U)

/* Invalid DMA channel */
#define SPI_DMA_CHNL_INVALID                  (0xFFU)

/* Sequence ID */

/* MISRA2012_RULE_5_1_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_2_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_4_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_5_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */


#define SpiConf_SpiSequence_SpiSequence_0_QSPI0      (0U)


/* MISRA2012_RULE_5_1_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_2_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_4_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_5_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */


#define SpiConf_SpiSequence_SpiSequence_1_QSPI1      (1U)


/* MISRA2012_RULE_5_1_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_2_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_4_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_5_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */


#define SpiConf_SpiSequence_SpiSequence_1_QSPI2      (2U)


/* MISRA2012_RULE_5_1_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_2_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_4_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_5_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */


#define SpiConf_SpiSequence_SpiSequence_1_QSPI3      (3U)


/* MISRA2012_RULE_5_1_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_2_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_4_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_5_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */


#define SpiConf_SpiSequence_SpiSequence_1_QSPI4      (4U)


/* MISRA2012_RULE_5_1_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_2_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_4_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_5_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */


#define SpiConf_SpiSequence_SpiSequence_1_QSPI5      (5U)


/* MISRA2012_RULE_5_1_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_2_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_4_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_5_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */


#define SpiConf_SpiSequence_SpiSequence_1_QSPI6      (6U)


/* MISRA2012_RULE_5_1_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_2_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_4_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_5_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */


#define SpiConf_SpiSequence_SpiSequence_2_QSPI2      (7U)


/* MISRA2012_RULE_5_1_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_2_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_4_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_5_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */


#define SpiConf_SpiSequence_SpiSequence_3_QSPI3      (8U)




/* Job ID */


#define SpiConf_SpiJob_SpiJob_0_QSPI0      (0U)



#define SpiConf_SpiJob_SpiJob_1_QSPI1_1      (1U)



#define SpiConf_SpiJob_SpiJob_2_QSPI1_2      (2U)



#define SpiConf_SpiJob_SpiJob_3_QSPI1_3      (3U)



#define SpiConf_SpiJob_SpiJob_4_QSPI1_4      (4U)



#define SpiConf_SpiJob_SpiJob_5_QSPI1_5      (5U)



#define SpiConf_SpiJob_SpiJob_6_QSPI1_6      (6U)



#define SpiConf_SpiJob_SpiJob_7_QSPI2      (7U)



#define SpiConf_SpiJob_SpiJob_8_QSPI3      (8U)




/* Channel ID */

/* MISRA2012_RULE_5_1_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_2_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_4_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_5_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */


#define SpiConf_SpiChannel_SpiChannel_QSPI0      (0U)


/* MISRA2012_RULE_5_1_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_2_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_4_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_5_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */


#define SpiConf_SpiChannel_SpiChannel_QSPI1_1      (1U)


/* MISRA2012_RULE_5_1_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_2_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_4_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_5_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */


#define SpiConf_SpiChannel_SpiChannel_QSPI1_2      (2U)


/* MISRA2012_RULE_5_1_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_2_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_4_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_5_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */


#define SpiConf_SpiChannel_SpiChannel_QSPI1_3      (3U)


/* MISRA2012_RULE_5_1_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_2_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_4_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_5_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */


#define SpiConf_SpiChannel_SpiChannel_QSPI1_4      (4U)


/* MISRA2012_RULE_5_1_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_2_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_4_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_5_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */


#define SpiConf_SpiChannel_SpiChannel_QSPI1_5      (5U)


/* MISRA2012_RULE_5_1_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_2_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_4_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_5_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */


#define SpiConf_SpiChannel_SpiChannel_QSPI1_6      (6U)


/* MISRA2012_RULE_5_1_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_2_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_4_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_5_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */


#define SpiConf_SpiChannel_SpiChannel_QSPI2      (7U)


/* MISRA2012_RULE_5_1_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_2_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_4_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */
/* MISRA2012_RULE_5_5_JUSTIFICATION: The macro is generated as per the naming
convention followed for symbolic names, defined as per AUTOSAR  */


#define SpiConf_SpiChannel_SpiChannel_QSPI3      (8U)



/*Physical sequence ID*/

/* Physical Job ID */

/* Channel ID */
/*end Physical*/

#define SPI_SEQUENCE_COUNT_CORE0      9U
        
#define SPI_SEQUENCE_COUNT_CORE1      0U
        
#define SPI_SEQUENCE_COUNT_CORE2      0U
        
#define SPI_SEQUENCE_COUNT_CORE3      0U
        
#define SPI_SEQUENCE_COUNT_CORE4      0U
        
#define SPI_SEQUENCE_COUNT_CORE5      0U
        

#define SPI_JOB_COUNT_CORE0       9U
        
#define SPI_JOB_COUNT_CORE1       0U
        
#define SPI_JOB_COUNT_CORE2       0U
        
#define SPI_JOB_COUNT_CORE3       0U
        
#define SPI_JOB_COUNT_CORE4       0U
        
#define SPI_JOB_COUNT_CORE5       0U
        
#define SPI_QSPI0_CORE          0

#define SPI_QSPI1_CORE          0

#define SPI_QSPI2_CORE          0

#define SPI_QSPI3_CORE          0



#define SPI_INIT_DEINIT_API_MODE              SPI_MCAL_SUPERVISOR


#define SPI_RUN_TIME_API_MODE                 SPI_MCAL_SUPERVISOR


#define SPI_MCAL_SUPERVISOR                   (0U)


#define SPI_MCAL_USER1                        (1U)


#define SPI_INIT_CHECK_API                        (STD_ON)

#define SPI_MULTICORE_ERROR_DETECT                        (STD_OFF)

#endif  /* SPI_CFG_H */

/* End Of File */
