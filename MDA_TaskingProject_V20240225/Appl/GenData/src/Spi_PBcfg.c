
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2017)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Spi_PBCfg.c                                                   **
**                                                                            **
**  VERSION   : 5.0.0                                                         **
**                                                                            **
**  DATE, TIME: 2024-02-23, 10:02:42                                      **
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






/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Module header file */
#include "Spi.h"

/*******************************************************************************
**                      Private Macro definition                              **
*******************************************************************************/
/* MISRA2012_RULE_4_9_JUSTIFICATION: More readble as macros. Code coplexity
reduces as well. */
#define Spi_BaudRateAndClockParam(TQ,LB,Q,A,B,C,CPH,CPOL,PAREN)                \
            (                                                                  \
             (uint32)(                                                         \
                      ((uint32)TQ << 16U)|((uint32)LB << 30U)|((uint32)Q)|\
                      ((uint32)A << 6U)|((uint32)B << 8U)|         \
                      ((uint32)C << 10U)|((uint32)CPH << 12U)|        \
                      ((uint32)CPOL << 13U)|((uint32)PAREN << 14U)     \
                     )                                                         \
            )

/* MISRA2012_RULE_4_9_JUSTIFICATION: More readble as macros. Code coplexity
reduces as well. */
#define Spi_IdleLeadTrailParam(IPRE,IDLE,LPRE,LEAD,TPRE,TRAIL,PARTYP)          \
            (                                                                  \
             (uint32)(                                                         \
                       ((uint32)IPRE << 1U)|((uint32)IDLE << 4U)|    \
                       ((uint32)LPRE << 7U)|((uint32)LEAD << 10U)|   \
                       ((uint32)TPRE << 13U)|((uint32)TRAIL << 16U)| \
                       ((uint32)PARTYP << 19U)            \
                     )                                                         \
            )

/*******************************************************************************
**                      Extern Declaration                                    **
*******************************************************************************/



/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/******************* GLOBAL CONFIGURATION MEMMAP SECTION *********************/


/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
 * because of AS naming convention*/
 /* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
 shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
 names
 * because of AS naming convention*/
#define SPI_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32

/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
 * without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
 * this is due to inclusion of memmap.h to specify the location to which
 * the variable has to be placed. */
#include "Spi_MemMap.h"


/*Sequence Index Lookup*/

static const uint8 SequenceLookupIndex[9] =
{

    /* Physical index value for Sequence SpiSequence_0_QSPI0 Sequence ID 0 */
    0U,

    /* Physical index value for Sequence SpiSequence_1_QSPI1 Sequence ID 1 */
    1U,

    /* Physical index value for Sequence SpiSequence_1_QSPI2 Sequence ID 2 */
    2U,

    /* Physical index value for Sequence SpiSequence_1_QSPI3 Sequence ID 3 */
    3U,

    /* Physical index value for Sequence SpiSequence_1_QSPI4 Sequence ID 4 */
    4U,

    /* Physical index value for Sequence SpiSequence_1_QSPI5 Sequence ID 5 */
    5U,

    /* Physical index value for Sequence SpiSequence_1_QSPI6 Sequence ID 6 */
    6U,

    /* Physical index value for Sequence SpiSequence_2_QSPI2 Sequence ID 7 */
    7U,

    /* Physical index value for Sequence SpiSequence_3_QSPI3 Sequence ID 8 */
    8U
};

/*Job Index Lookup*/

/* MISRA2012_RULE_8_3_JUSTIFICATION: Agreed violation */
/* MISRA2012_RULE_8_9_JUSTIFICATION: Agreed violation */
static const uint16 JobLookupIndex[9] =
{

    /* Physical index value for Job SpiJob_0_QSPI0 Job ID 0 */
    0U,

    /* Physical index value for Job SpiJob_1_QSPI1_1 Job ID 1 */
    1U,

    /* Physical index value for Job SpiJob_2_QSPI1_2 Job ID 2 */
    2U,

    /* Physical index value for Job SpiJob_3_QSPI1_3 Job ID 3 */
    3U,

    /* Physical index value for Job SpiJob_4_QSPI1_4 Job ID 4 */
    4U,

    /* Physical index value for Job SpiJob_5_QSPI1_5 Job ID 5 */
    5U,

    /* Physical index value for Job SpiJob_6_QSPI1_6 Job ID 6 */
    6U,

    /* Physical index value for Job SpiJob_7_QSPI2 Job ID 7 */
    7U,

    /* Physical index value for Job SpiJob_8_QSPI3 Job ID 8 */
    8U
};

/*Channel Index Lookup*/

static const uint8 ChannelLookupIndex[9] =
{

    /* Physical index value for channel SpiChannel_QSPI0 channel ID 0 */
    0U,

    /* Physical index value for channel SpiChannel_QSPI1_1 channel ID 1 */
    6U,

    /* Physical index value for channel SpiChannel_QSPI1_2 channel ID 2 */
    5U,

    /* Physical index value for channel SpiChannel_QSPI1_3 channel ID 3 */
    4U,

    /* Physical index value for channel SpiChannel_QSPI1_4 channel ID 4 */
    3U,

    /* Physical index value for channel SpiChannel_QSPI1_5 channel ID 5 */
    2U,

    /* Physical index value for channel SpiChannel_QSPI1_6 channel ID 6 */
    1U,

    /* Physical index value for channel SpiChannel_QSPI2 channel ID 7 */
    7U,

    /* Physical index value for channel SpiChannel_QSPI3 channel ID 8 */
    8U
};

/* Linked list for the Job[s] assigned to the sequence[s] Physical*/

static const Spi_JobType SpiSequence_0_QSPI0_JobLinkPtr_Physical[] =
{
  0U,        /* Physical index value for Job SpiJob_0_QSPI0 Job ID 0 */

  SPI_JOB_DELIMITER
};

static const Spi_JobType SpiSequence_1_QSPI1_JobLinkPtr_Physical[] =
{
  1U,        /* Physical index value for Job SpiJob_1_QSPI1_1 Job ID 1 */

  SPI_JOB_DELIMITER
};

static const Spi_JobType SpiSequence_1_QSPI2_JobLinkPtr_Physical[] =
{
  2U,        /* Physical index value for Job SpiJob_2_QSPI1_2 Job ID 2 */

  SPI_JOB_DELIMITER
};

static const Spi_JobType SpiSequence_1_QSPI3_JobLinkPtr_Physical[] =
{
  3U,        /* Physical index value for Job SpiJob_3_QSPI1_3 Job ID 3 */

  SPI_JOB_DELIMITER
};

static const Spi_JobType SpiSequence_1_QSPI4_JobLinkPtr_Physical[] =
{
  4U,        /* Physical index value for Job SpiJob_4_QSPI1_4 Job ID 4 */

  SPI_JOB_DELIMITER
};

static const Spi_JobType SpiSequence_1_QSPI5_JobLinkPtr_Physical[] =
{
  5U,        /* Physical index value for Job SpiJob_5_QSPI1_5 Job ID 5 */

  SPI_JOB_DELIMITER
};

static const Spi_JobType SpiSequence_1_QSPI6_JobLinkPtr_Physical[] =
{
  6U,        /* Physical index value for Job SpiJob_6_QSPI1_6 Job ID 6 */

  SPI_JOB_DELIMITER
};

static const Spi_JobType SpiSequence_2_QSPI2_JobLinkPtr_Physical[] =
{
  7U,        /* Physical index value for Job SpiJob_7_QSPI2 Job ID 7 */

  SPI_JOB_DELIMITER
};

static const Spi_JobType SpiSequence_3_QSPI3_JobLinkPtr_Physical[] =
{
  8U,        /* Physical index value for Job SpiJob_8_QSPI3 Job ID 8 */

  SPI_JOB_DELIMITER
};

/* Linked list for the channel[s] assigned to the job[s] Physical */

static const Spi_ChannelType SpiJob_0_QSPI0_ChannelLinkPtr_Physical[] =
{
  0U,        /* Physical index value for Channel SpiChannel_QSPI0 Channel ID 0 */
  
  SPI_CHANNEL_DELIMITER
};

static const Spi_ChannelType SpiJob_1_QSPI1_1_ChannelLinkPtr_Physical[] =
{
  6U,        /* Physical index value for Channel SpiChannel_QSPI1_1 Channel ID 1 */
  
  SPI_CHANNEL_DELIMITER
};

static const Spi_ChannelType SpiJob_2_QSPI1_2_ChannelLinkPtr_Physical[] =
{
  5U,        /* Physical index value for Channel SpiChannel_QSPI1_2 Channel ID 2 */
  
  SPI_CHANNEL_DELIMITER
};

static const Spi_ChannelType SpiJob_3_QSPI1_3_ChannelLinkPtr_Physical[] =
{
  4U,        /* Physical index value for Channel SpiChannel_QSPI1_3 Channel ID 3 */
  
  SPI_CHANNEL_DELIMITER
};

static const Spi_ChannelType SpiJob_4_QSPI1_4_ChannelLinkPtr_Physical[] =
{
  3U,        /* Physical index value for Channel SpiChannel_QSPI1_4 Channel ID 4 */
  
  SPI_CHANNEL_DELIMITER
};

static const Spi_ChannelType SpiJob_5_QSPI1_5_ChannelLinkPtr_Physical[] =
{
  2U,        /* Physical index value for Channel SpiChannel_QSPI1_5 Channel ID 5 */
  
  SPI_CHANNEL_DELIMITER
};

static const Spi_ChannelType SpiJob_6_QSPI1_6_ChannelLinkPtr_Physical[] =
{
  1U,        /* Physical index value for Channel SpiChannel_QSPI1_6 Channel ID 6 */
  
  SPI_CHANNEL_DELIMITER
};

static const Spi_ChannelType SpiJob_7_QSPI2_ChannelLinkPtr_Physical[] =
{
  7U,        /* Physical index value for Channel SpiChannel_QSPI2 Channel ID 7 */
  
  SPI_CHANNEL_DELIMITER
};

static const Spi_ChannelType SpiJob_8_QSPI3_ChannelLinkPtr_Physical[] =
{
  8U,        /* Physical index value for Channel SpiChannel_QSPI3 Channel ID 8 */
  
  SPI_CHANNEL_DELIMITER
};

/* Linked list of sequence[s] with Job[s] shared  */
static const Spi_SequenceType SpiSequence_0_QSPI0_SeqSharePtr[] =
{
  SPI_SEQUENCE_DELIMITER
};
static const Spi_SequenceType SpiSequence_1_QSPI1_SeqSharePtr[] =
{
  SPI_SEQUENCE_DELIMITER
};
static const Spi_SequenceType SpiSequence_1_QSPI2_SeqSharePtr[] =
{
  SPI_SEQUENCE_DELIMITER
};
static const Spi_SequenceType SpiSequence_1_QSPI3_SeqSharePtr[] =
{
  SPI_SEQUENCE_DELIMITER
};
static const Spi_SequenceType SpiSequence_1_QSPI4_SeqSharePtr[] =
{
  SPI_SEQUENCE_DELIMITER
};
static const Spi_SequenceType SpiSequence_1_QSPI5_SeqSharePtr[] =
{
  SPI_SEQUENCE_DELIMITER
};
static const Spi_SequenceType SpiSequence_1_QSPI6_SeqSharePtr[] =
{
  SPI_SEQUENCE_DELIMITER
};
static const Spi_SequenceType SpiSequence_2_QSPI2_SeqSharePtr[] =
{
  SPI_SEQUENCE_DELIMITER
};
static const Spi_SequenceType SpiSequence_3_QSPI3_SeqSharePtr[] =
{
  SPI_SEQUENCE_DELIMITER
};

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
 * because of AS naming convention*/
 /* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
 shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
 names
 * because of AS naming convention*/
#define SPI_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
 * without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
 * this is due to inclusion of memmap.h to specify the location to which
 * the variable has to be placed. */
#include "Spi_MemMap.h"

/******************* GLOBAL CONFIGURATION MEMMAP SECTION *********************/



 /******************* CORE0 SEQUENCE CONFIGURATION MEMMAP SECTION *************/

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
 * because of AS naming convention*/
 /* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
 shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
 names
 * because of AS naming convention*/
#define SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
 * without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
 * this is due to inclusion of memmap.h to specify the location to which
 * the variable has to be placed. */
#include "Spi_MemMap.h"


static const Spi_SequenceConfigType Spi_kSequenceConfig_Core0[] =
{
  /* Asynchronous Sequence[s] on QSPI0 */
  /* Sequence:SpiSequence_0_QSPI0 */
  {
    SpiConf_SpiSequence_SpiSequence_0_QSPI0,
    /* Notification function */
    NULL_PTR,
    /* Job linked list */
    SpiSequence_0_QSPI0_JobLinkPtr_Physical,
    /* Seq linked list, with jobs shared */
    SpiSequence_0_QSPI0_SeqSharePtr,
    /* No. of jobs in Seq */
    1U,
    /* Seq Interruptible or not */
    SPI_SEQ_INT_FALSE,
    /* Hw Module Used (b000001)*/
    0x01U,
    /* Sync sequence = 0x00 or Async sequence = 0x01 */
    0x01U
  },
  /* Asynchronous Sequence[s] on QSPI1 */
  /* Sequence:SpiSequence_1_QSPI1 */
  {
    SpiConf_SpiSequence_SpiSequence_1_QSPI1,
    /* Notification function */
    NULL_PTR,
    /* Job linked list */
    SpiSequence_1_QSPI1_JobLinkPtr_Physical,
    /* Seq linked list, with jobs shared */
    SpiSequence_1_QSPI1_SeqSharePtr,
    /* No. of jobs in Seq */
    1U,
    /* Seq Interruptible or not */
    SPI_SEQ_INT_FALSE,
    /* Hw Module Used (b000010)*/
    0x02U,
    /* Sync sequence = 0x00 or Async sequence = 0x01 */
    0x01U
  },
  /* Sequence:SpiSequence_1_QSPI2 */
  {
    SpiConf_SpiSequence_SpiSequence_1_QSPI2,
    /* Notification function */
    NULL_PTR,
    /* Job linked list */
    SpiSequence_1_QSPI2_JobLinkPtr_Physical,
    /* Seq linked list, with jobs shared */
    SpiSequence_1_QSPI2_SeqSharePtr,
    /* No. of jobs in Seq */
    1U,
    /* Seq Interruptible or not */
    SPI_SEQ_INT_FALSE,
    /* Hw Module Used (b000010)*/
    0x02U,
    /* Sync sequence = 0x00 or Async sequence = 0x01 */
    0x01U
  },
  /* Sequence:SpiSequence_1_QSPI3 */
  {
    SpiConf_SpiSequence_SpiSequence_1_QSPI3,
    /* Notification function */
    NULL_PTR,
    /* Job linked list */
    SpiSequence_1_QSPI3_JobLinkPtr_Physical,
    /* Seq linked list, with jobs shared */
    SpiSequence_1_QSPI3_SeqSharePtr,
    /* No. of jobs in Seq */
    1U,
    /* Seq Interruptible or not */
    SPI_SEQ_INT_FALSE,
    /* Hw Module Used (b000010)*/
    0x02U,
    /* Sync sequence = 0x00 or Async sequence = 0x01 */
    0x01U
  },
  /* Sequence:SpiSequence_1_QSPI4 */
  {
    SpiConf_SpiSequence_SpiSequence_1_QSPI4,
    /* Notification function */
    NULL_PTR,
    /* Job linked list */
    SpiSequence_1_QSPI4_JobLinkPtr_Physical,
    /* Seq linked list, with jobs shared */
    SpiSequence_1_QSPI4_SeqSharePtr,
    /* No. of jobs in Seq */
    1U,
    /* Seq Interruptible or not */
    SPI_SEQ_INT_FALSE,
    /* Hw Module Used (b000010)*/
    0x02U,
    /* Sync sequence = 0x00 or Async sequence = 0x01 */
    0x01U
  },
  /* Sequence:SpiSequence_1_QSPI5 */
  {
    SpiConf_SpiSequence_SpiSequence_1_QSPI5,
    /* Notification function */
    NULL_PTR,
    /* Job linked list */
    SpiSequence_1_QSPI5_JobLinkPtr_Physical,
    /* Seq linked list, with jobs shared */
    SpiSequence_1_QSPI5_SeqSharePtr,
    /* No. of jobs in Seq */
    1U,
    /* Seq Interruptible or not */
    SPI_SEQ_INT_FALSE,
    /* Hw Module Used (b000010)*/
    0x02U,
    /* Sync sequence = 0x00 or Async sequence = 0x01 */
    0x01U
  },
  /* Sequence:SpiSequence_1_QSPI6 */
  {
    SpiConf_SpiSequence_SpiSequence_1_QSPI6,
    /* Notification function */
    NULL_PTR,
    /* Job linked list */
    SpiSequence_1_QSPI6_JobLinkPtr_Physical,
    /* Seq linked list, with jobs shared */
    SpiSequence_1_QSPI6_SeqSharePtr,
    /* No. of jobs in Seq */
    1U,
    /* Seq Interruptible or not */
    SPI_SEQ_INT_FALSE,
    /* Hw Module Used (b000010)*/
    0x02U,
    /* Sync sequence = 0x00 or Async sequence = 0x01 */
    0x01U
  },
  /* Asynchronous Sequence[s] on QSPI2 */
  /* Sequence:SpiSequence_2_QSPI2 */
  {
    SpiConf_SpiSequence_SpiSequence_2_QSPI2,
    /* Notification function */
    NULL_PTR,
    /* Job linked list */
    SpiSequence_2_QSPI2_JobLinkPtr_Physical,
    /* Seq linked list, with jobs shared */
    SpiSequence_2_QSPI2_SeqSharePtr,
    /* No. of jobs in Seq */
    1U,
    /* Seq Interruptible or not */
    SPI_SEQ_INT_FALSE,
    /* Hw Module Used (b000100)*/
    0x04U,
    /* Sync sequence = 0x00 or Async sequence = 0x01 */
    0x01U
  },
  /* Asynchronous Sequence[s] on QSPI3 */
  /* Sequence:SpiSequence_3_QSPI3 */
  {
    SpiConf_SpiSequence_SpiSequence_3_QSPI3,
    /* Notification function */
    NULL_PTR,
    /* Job linked list */
    SpiSequence_3_QSPI3_JobLinkPtr_Physical,
    /* Seq linked list, with jobs shared */
    SpiSequence_3_QSPI3_SeqSharePtr,
    /* No. of jobs in Seq */
    1U,
    /* Seq Interruptible or not */
    SPI_SEQ_INT_FALSE,
    /* Hw Module Used (b001000)*/
    0x08U,
    /* Sync sequence = 0x00 or Async sequence = 0x01 */
    0x01U
  }};


/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
 * because of AS naming convention*/
 /* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
 shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
 names
 * because of AS naming convention*/
#define SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
 * without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
 * this is due to inclusion of memmap.h to specify the location to which
 * the variable has to be placed. */
#include "Spi_MemMap.h"

/***************** CORE0 SEQUENCE CONFIGURATION MEMMAP SECTION END *************/






/******************* CORE0 JOB CONFIGURATION MEMMAP SECTION *************/


/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
 * because of AS naming convention*/
 /* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
 shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
 names
 * because of AS naming convention*/
#define SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
 * without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
 * this is due to inclusion of memmap.h to specify the location to which
 * the variable has to be placed. */
#include "Spi_MemMap.h"

static const Spi_JobConfigType Spi_kJobConfig_Core0[] =
{
  /* Asynchronous Job[s] on QSPI0 */

  /* Job:SpiJob_0_QSPI0 */
  {
    SpiConf_SpiJob_SpiJob_0_QSPI0,
    NULL_PTR,                   /* No Notification function */
    Spi_BaudRateAndClockParam(  /* Baudrate = 2000000.0Hz */
     (0x18U), (0x00U),          /* TQ , LoopBack */
     (0x01U), (0x00U),          /*  Q , A        */
     (0x00U), (0x01U),          /*  B , C        */
     (0x01U), (0x00U),          /*  CPH , CPOL   */
     (0x00U)                    /*  PAREN        */
    ),
    Spi_IdleLeadTrailParam(
     (1U), (4U), /* IPRE,IDLE:   IdleA/B delay = 1.0E-7s */
     (1U), (4U), /* LPRE,LEAD:   Lead delay    = 1.0E-7s */
     (1U), (4U),/* TPRE, TRAIL: Trail delay   = 1.0E-7s */
     (1U)
    ),
    SpiJob_0_QSPI0_ChannelLinkPtr_Physical, /* Channel linked list Physical*/
    SPI_CS_VIA_HW_OR_NONE,   /* CS_VIA_HW */
    (uint8)3U,               /* Job Priority : 0...3*/
    (uint8)STD_LOW,              /* CS polarity */
     /* Chnl[bit:7:4],QSPI[3:0] */
    (uint8)((SPI_QSPI_CHANNEL2 << 4U)|SPI_QSPI0_INDEX),
    SPI_PARITY_UNUSED,        /* Parity support */
    (0U)                    /*Frame based CS is disabled*/
  },
  /* Asynchronous Job[s] on QSPI1 */

  /* Job:SpiJob_1_QSPI1_1 */
  {
    SpiConf_SpiJob_SpiJob_1_QSPI1_1,
    NULL_PTR,                   /* No Notification function */
    Spi_BaudRateAndClockParam(  /* Baudrate = 1.25E7Hz */
     (0x03U), (0x00U),          /* TQ , LoopBack */
     (0x01U), (0x00U),          /*  Q , A        */
     (0x00U), (0x01U),          /*  B , C        */
     (0x01U), (0x00U),          /*  CPH , CPOL   */
     (0x00U)                    /*  PAREN        */
    ),
    Spi_IdleLeadTrailParam(
     (1U), (4U), /* IPRE,IDLE:   IdleA/B delay = 1.0E-7s */
     (1U), (4U), /* LPRE,LEAD:   Lead delay    = 1.0E-7s */
     (1U), (4U),/* TPRE, TRAIL: Trail delay   = 1.0E-7s */
     (1U)
    ),
    SpiJob_1_QSPI1_1_ChannelLinkPtr_Physical, /* Channel linked list Physical*/
    SPI_CS_VIA_HW_OR_NONE,   /* CS_VIA_HW */
    (uint8)2U,               /* Job Priority : 0...3*/
    (uint8)STD_LOW,              /* CS polarity */
     /* Chnl[bit:7:4],QSPI[3:0] */
    (uint8)((SPI_QSPI_CHANNEL0 << 4U)|SPI_QSPI1_INDEX),
    SPI_PARITY_UNUSED,        /* Parity support */
    (0U)                    /*Frame based CS is disabled*/
  },

  /* Job:SpiJob_2_QSPI1_2 */
  {
    SpiConf_SpiJob_SpiJob_2_QSPI1_2,
    NULL_PTR,                   /* No Notification function */
    Spi_BaudRateAndClockParam(  /* Baudrate = 1.25E7Hz */
     (0x03U), (0x00U),          /* TQ , LoopBack */
     (0x01U), (0x00U),          /*  Q , A        */
     (0x00U), (0x01U),          /*  B , C        */
     (0x01U), (0x00U),          /*  CPH , CPOL   */
     (0x00U)                    /*  PAREN        */
    ),
    Spi_IdleLeadTrailParam(
     (1U), (4U), /* IPRE,IDLE:   IdleA/B delay = 1.0E-7s */
     (1U), (4U), /* LPRE,LEAD:   Lead delay    = 1.0E-7s */
     (1U), (4U),/* TPRE, TRAIL: Trail delay   = 1.0E-7s */
     (1U)
    ),
    SpiJob_2_QSPI1_2_ChannelLinkPtr_Physical, /* Channel linked list Physical*/
    SPI_CS_VIA_HW_OR_NONE,   /* CS_VIA_HW */
    (uint8)2U,               /* Job Priority : 0...3*/
    (uint8)STD_LOW,              /* CS polarity */
     /* Chnl[bit:7:4],QSPI[3:0] */
    (uint8)((SPI_QSPI_CHANNEL1 << 4U)|SPI_QSPI1_INDEX),
    SPI_PARITY_UNUSED,        /* Parity support */
    (0U)                    /*Frame based CS is disabled*/
  },

  /* Job:SpiJob_3_QSPI1_3 */
  {
    SpiConf_SpiJob_SpiJob_3_QSPI1_3,
    NULL_PTR,                   /* No Notification function */
    Spi_BaudRateAndClockParam(  /* Baudrate = 1.25E7Hz */
     (0x03U), (0x00U),          /* TQ , LoopBack */
     (0x01U), (0x00U),          /*  Q , A        */
     (0x00U), (0x01U),          /*  B , C        */
     (0x01U), (0x00U),          /*  CPH , CPOL   */
     (0x00U)                    /*  PAREN        */
    ),
    Spi_IdleLeadTrailParam(
     (1U), (4U), /* IPRE,IDLE:   IdleA/B delay = 1.0E-7s */
     (1U), (4U), /* LPRE,LEAD:   Lead delay    = 1.0E-7s */
     (1U), (4U),/* TPRE, TRAIL: Trail delay   = 1.0E-7s */
     (1U)
    ),
    SpiJob_3_QSPI1_3_ChannelLinkPtr_Physical, /* Channel linked list Physical*/
    SPI_CS_VIA_HW_OR_NONE,   /* CS_VIA_HW */
    (uint8)2U,               /* Job Priority : 0...3*/
    (uint8)STD_LOW,              /* CS polarity */
     /* Chnl[bit:7:4],QSPI[3:0] */
    (uint8)((SPI_QSPI_CHANNEL6 << 4U)|SPI_QSPI1_INDEX),
    SPI_PARITY_UNUSED,        /* Parity support */
    (0U)                    /*Frame based CS is disabled*/
  },

  /* Job:SpiJob_4_QSPI1_4 */
  {
    SpiConf_SpiJob_SpiJob_4_QSPI1_4,
    NULL_PTR,                   /* No Notification function */
    Spi_BaudRateAndClockParam(  /* Baudrate = 1.25E7Hz */
     (0x03U), (0x00U),          /* TQ , LoopBack */
     (0x01U), (0x00U),          /*  Q , A        */
     (0x00U), (0x01U),          /*  B , C        */
     (0x01U), (0x00U),          /*  CPH , CPOL   */
     (0x00U)                    /*  PAREN        */
    ),
    Spi_IdleLeadTrailParam(
     (1U), (4U), /* IPRE,IDLE:   IdleA/B delay = 1.0E-7s */
     (1U), (4U), /* LPRE,LEAD:   Lead delay    = 1.0E-7s */
     (1U), (4U),/* TPRE, TRAIL: Trail delay   = 1.0E-7s */
     (1U)
    ),
    SpiJob_4_QSPI1_4_ChannelLinkPtr_Physical, /* Channel linked list Physical*/
    SPI_CS_VIA_HW_OR_NONE,   /* CS_VIA_HW */
    (uint8)2U,               /* Job Priority : 0...3*/
    (uint8)STD_LOW,              /* CS polarity */
     /* Chnl[bit:7:4],QSPI[3:0] */
    (uint8)((SPI_QSPI_CHANNEL7 << 4U)|SPI_QSPI1_INDEX),
    SPI_PARITY_UNUSED,        /* Parity support */
    (0U)                    /*Frame based CS is disabled*/
  },

  /* Job:SpiJob_5_QSPI1_5 */
  {
    SpiConf_SpiJob_SpiJob_5_QSPI1_5,
    NULL_PTR,                   /* No Notification function */
    Spi_BaudRateAndClockParam(  /* Baudrate = 1.25E7Hz */
     (0x03U), (0x00U),          /* TQ , LoopBack */
     (0x01U), (0x00U),          /*  Q , A        */
     (0x00U), (0x01U),          /*  B , C        */
     (0x01U), (0x00U),          /*  CPH , CPOL   */
     (0x00U)                    /*  PAREN        */
    ),
    Spi_IdleLeadTrailParam(
     (1U), (4U), /* IPRE,IDLE:   IdleA/B delay = 1.0E-7s */
     (1U), (4U), /* LPRE,LEAD:   Lead delay    = 1.0E-7s */
     (1U), (4U),/* TPRE, TRAIL: Trail delay   = 1.0E-7s */
     (1U)
    ),
    SpiJob_5_QSPI1_5_ChannelLinkPtr_Physical, /* Channel linked list Physical*/
    SPI_CS_VIA_HW_OR_NONE,   /* CS_VIA_HW */
    (uint8)2U,               /* Job Priority : 0...3*/
    (uint8)STD_LOW,              /* CS polarity */
     /* Chnl[bit:7:4],QSPI[3:0] */
    (uint8)((SPI_QSPI_CHANNEL8 << 4U)|SPI_QSPI1_INDEX),
    SPI_PARITY_UNUSED,        /* Parity support */
    (0U)                    /*Frame based CS is disabled*/
  },

  /* Job:SpiJob_6_QSPI1_6 */
  {
    SpiConf_SpiJob_SpiJob_6_QSPI1_6,
    NULL_PTR,                   /* No Notification function */
    Spi_BaudRateAndClockParam(  /* Baudrate = 1.25E7Hz */
     (0x03U), (0x00U),          /* TQ , LoopBack */
     (0x01U), (0x00U),          /*  Q , A        */
     (0x00U), (0x01U),          /*  B , C        */
     (0x01U), (0x00U),          /*  CPH , CPOL   */
     (0x00U)                    /*  PAREN        */
    ),
    Spi_IdleLeadTrailParam(
     (1U), (4U), /* IPRE,IDLE:   IdleA/B delay = 1.0E-7s */
     (1U), (4U), /* LPRE,LEAD:   Lead delay    = 1.0E-7s */
     (1U), (4U),/* TPRE, TRAIL: Trail delay   = 1.0E-7s */
     (1U)
    ),
    SpiJob_6_QSPI1_6_ChannelLinkPtr_Physical, /* Channel linked list Physical*/
    SPI_CS_VIA_HW_OR_NONE,   /* CS_VIA_HW */
    (uint8)2U,               /* Job Priority : 0...3*/
    (uint8)STD_LOW,              /* CS polarity */
     /* Chnl[bit:7:4],QSPI[3:0] */
    (uint8)((SPI_QSPI_CHANNEL10 << 4U)|SPI_QSPI1_INDEX),
    SPI_PARITY_UNUSED,        /* Parity support */
    (0U)                    /*Frame based CS is disabled*/
  },
  /* Asynchronous Job[s] on QSPI2 */

  /* Job:SpiJob_7_QSPI2 */
  {
    SpiConf_SpiJob_SpiJob_7_QSPI2,
    NULL_PTR,                   /* No Notification function */
    Spi_BaudRateAndClockParam(  /* Baudrate = 4000000.0Hz */
     (0x04U), (0x00U),          /* TQ , LoopBack */
     (0x04U), (0x00U),          /*  Q , A        */
     (0x00U), (0x01U),          /*  B , C        */
     (0x01U), (0x00U),          /*  CPH , CPOL   */
     (0x00U)                    /*  PAREN        */
    ),
    Spi_IdleLeadTrailParam(
     (1U), (4U), /* IPRE,IDLE:   IdleA/B delay = 1.0E-7s */
     (1U), (4U), /* LPRE,LEAD:   Lead delay    = 1.0E-7s */
     (1U), (4U),/* TPRE, TRAIL: Trail delay   = 1.0E-7s */
     (1U)
    ),
    SpiJob_7_QSPI2_ChannelLinkPtr_Physical, /* Channel linked list Physical*/
    SPI_CS_VIA_HW_OR_NONE,   /* CS_VIA_HW */
    (uint8)0U,               /* Job Priority : 0...3*/
    (uint8)STD_LOW,              /* CS polarity */
     /* Chnl[bit:7:4],QSPI[3:0] */
    (uint8)((SPI_QSPI_CHANNEL8 << 4U)|SPI_QSPI2_INDEX),
    SPI_PARITY_UNUSED,        /* Parity support */
    (0U)                    /*Frame based CS is disabled*/
  },
  /* Asynchronous Job[s] on QSPI3 */

  /* Job:SpiJob_8_QSPI3 */
  {
    SpiConf_SpiJob_SpiJob_8_QSPI3,
    NULL_PTR,                   /* No Notification function */
    Spi_BaudRateAndClockParam(  /* Baudrate = 4000000.0Hz */
     (0x04U), (0x00U),          /* TQ , LoopBack */
     (0x04U), (0x00U),          /*  Q , A        */
     (0x00U), (0x01U),          /*  B , C        */
     (0x01U), (0x00U),          /*  CPH , CPOL   */
     (0x00U)                    /*  PAREN        */
    ),
    Spi_IdleLeadTrailParam(
     (1U), (4U), /* IPRE,IDLE:   IdleA/B delay = 1.0E-7s */
     (1U), (4U), /* LPRE,LEAD:   Lead delay    = 1.0E-7s */
     (1U), (4U),/* TPRE, TRAIL: Trail delay   = 1.0E-7s */
     (1U)
    ),
    SpiJob_8_QSPI3_ChannelLinkPtr_Physical, /* Channel linked list Physical*/
    SPI_CS_VIA_HW_OR_NONE,   /* CS_VIA_HW */
    (uint8)1U,               /* Job Priority : 0...3*/
    (uint8)STD_LOW,              /* CS polarity */
     /* Chnl[bit:7:4],QSPI[3:0] */
    (uint8)((SPI_QSPI_CHANNEL5 << 4U)|SPI_QSPI3_INDEX),
    SPI_PARITY_UNUSED,        /* Parity support */
    (0U)                    /*Frame based CS is disabled*/
  }
};


/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
 * because of AS naming convention*/
 /* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
 shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
 names
 * because of AS naming convention*/
#define SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
 * without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
 * this is due to inclusion of memmap.h to specify the location to which
 * the variable has to be placed. */
#include "Spi_MemMap.h"

/***************** CORE0 JOB CONFIGURATION MemMap SECTION END *************/






/******************* CORE0 CHANNEL CONFIGURATION MEMMAP SECTION *************/


/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
 * because of AS naming convention*/
 /* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
 shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
 names
 * because of AS naming convention*/
#define SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
 * without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
 * this is due to inclusion of memmap.h to specify the location to which
 * the variable has to be placed. */
#include "Spi_MemMap.h"


static const Spi_ChannelConfigType Spi_kChannelConfig_Core0[] =
{


    /* EB Chnl[s] on QSPI0 core0*/
        
    /* Channel:SpiChannel_QSPI0 */
  {
    0x00000000U,     /* Default data */
    0x0020U,         /* Number of Data Elements */
    SPI_EB_CHANNEL,  /* External Buffer Channel */
    0x90U,            /* MSB[7], DataWidth=16[6:0] */
    SpiConf_SpiChannel_SpiChannel_QSPI0
  },


    /* EB Chnl[s] on QSPI1 core0*/

    /* Channel:SpiChannel_QSPI1_6 */
  {
    0x00000000U,     /* Default data */
    0x0010U,         /* Number of Data Elements */
    SPI_EB_CHANNEL,  /* External Buffer Channel */
    0x88U,            /* MSB[7], DataWidth=8[6:0] */
    SpiConf_SpiChannel_SpiChannel_QSPI1_6
  },

    /* Channel:SpiChannel_QSPI1_5 */
  {
    0x00000000U,     /* Default data */
    0x0010U,         /* Number of Data Elements */
    SPI_EB_CHANNEL,  /* External Buffer Channel */
    0x88U,            /* MSB[7], DataWidth=8[6:0] */
    SpiConf_SpiChannel_SpiChannel_QSPI1_5
  },

    /* Channel:SpiChannel_QSPI1_4 */
  {
    0x00000000U,     /* Default data */
    0x0010U,         /* Number of Data Elements */
    SPI_EB_CHANNEL,  /* External Buffer Channel */
    0x88U,            /* MSB[7], DataWidth=8[6:0] */
    SpiConf_SpiChannel_SpiChannel_QSPI1_4
  },

    /* Channel:SpiChannel_QSPI1_3 */
  {
    0x00000000U,     /* Default data */
    0x0010U,         /* Number of Data Elements */
    SPI_EB_CHANNEL,  /* External Buffer Channel */
    0x88U,            /* MSB[7], DataWidth=8[6:0] */
    SpiConf_SpiChannel_SpiChannel_QSPI1_3
  },

    /* Channel:SpiChannel_QSPI1_2 */
  {
    0x00000000U,     /* Default data */
    0x0010U,         /* Number of Data Elements */
    SPI_EB_CHANNEL,  /* External Buffer Channel */
    0x88U,            /* MSB[7], DataWidth=8[6:0] */
    SpiConf_SpiChannel_SpiChannel_QSPI1_2
  },

    /* Channel:SpiChannel_QSPI1_1 */
  {
    0x00000000U,     /* Default data */
    0x0010U,         /* Number of Data Elements */
    SPI_EB_CHANNEL,  /* External Buffer Channel */
    0x88U,            /* MSB[7], DataWidth=8[6:0] */
    SpiConf_SpiChannel_SpiChannel_QSPI1_1
  },


    /* EB Chnl[s] on QSPI2 core0*/

    /* Channel:SpiChannel_QSPI2 */
  {
    0x00000000U,     /* Default data */
    0x0020U,         /* Number of Data Elements */
    SPI_EB_CHANNEL,  /* External Buffer Channel */
    0x90U,            /* MSB[7], DataWidth=16[6:0] */
    SpiConf_SpiChannel_SpiChannel_QSPI2
  },


    /* EB Chnl[s] on QSPI3 core0*/

    /* Channel:SpiChannel_QSPI3 */
  {
    0x00000000U,     /* Default data */
    0x0020U,         /* Number of Data Elements */
    SPI_EB_CHANNEL,  /* External Buffer Channel */
    0x90U,            /* MSB[7], DataWidth=16[6:0] */
    SpiConf_SpiChannel_SpiChannel_QSPI3
  }
};


/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
 * because of AS naming convention*/
 /* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
 shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
 names
 * because of AS naming convention*/
#define SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
 * without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
 * this is due to inclusion of memmap.h to specify the location to which
 * the variable has to be placed. */
#include "Spi_MemMap.h"

/***************** CORE0 JOB CONFIGURATION MemMap SECTION END *************/







/******************* CORE0 QSPI0 CONFIGURATION MEMMAP SECTION *************/


/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
 * because of AS naming convention*/
 /* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
 shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
 names
 * because of AS naming convention*/
#define SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
 * without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
 * this is due to inclusion of memmap.h to specify the location to which
 * the variable has to be placed. */
#include "Spi_MemMap.h"

  /* QSPI0 */
static const Spi_QspiHwConfigType Spi_kQspiHwConfigQSPI0 =
{
  0x00040000U,               /* Active CS Level, SSOC SFR value */
  SPI_ASYNC_IB_BUFFER_SIZE_QSPI0,  /* Buffers on QSPI0 only */
  SPI_JOB_QUEUE_LENGTH_QSPI0,/* Job Queue Length */
  (uint8)8U,                 /* DMA Rx Channel */
  (uint8)9U,                 /* DMA Tx Channel */
  SPI_DMA_MAX_TCS_NUM_QSPI0, /* DMA TCS count, for both Rx and Tx */
  SPI_CLK_SLEEP_DISABLE,     /* Module Sleep disabled */
  (uint8)0U,                 /* Input class, MRIS bit field in PISEL SFR */
  1U                         /* Max Sequence Count on the QSPI */
};


/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
 * because of AS naming convention*/
 /* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
 shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
 names
 * because of AS naming convention*/
#define SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
 * without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
 * this is due to inclusion of memmap.h to specify the location to which
 * the variable has to be placed. */
#include "Spi_MemMap.h"

/***************** CORE0 QSPI0 CONFIGURATION MemMap SECTION END *************/

/******************* CORE0 QSPI1 CONFIGURATION MEMMAP SECTION *************/

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
 * because of AS naming convention*/
 /* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
 shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
 names
 * because of AS naming convention*/
#define SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
 * without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
 * this is due to inclusion of memmap.h to specify the location to which
 * the variable has to be placed. */
#include "Spi_MemMap.h"

  /* QSPI1 */
static const Spi_QspiHwConfigType Spi_kQspiHwConfigQSPI1 =
{
  0x05c30000U,               /* Active CS Level, SSOC SFR value */
  SPI_ASYNC_IB_BUFFER_SIZE_QSPI1,  /* Buffers on QSPI1 only */
  SPI_JOB_QUEUE_LENGTH_QSPI1,/* Job Queue Length */
  (uint8)6U,                 /* DMA Rx Channel */
  (uint8)7U,                 /* DMA Tx Channel */
  SPI_DMA_MAX_TCS_NUM_QSPI1, /* DMA TCS count, for both Rx and Tx */
  SPI_CLK_SLEEP_DISABLE,     /* Module Sleep disabled */
  (uint8)0U,                 /* Input class, MRIS bit field in PISEL SFR */
  6U                         /* Max Sequence Count on the QSPI */
};

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
 * because of AS naming convention*/
 /* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
 shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
 names
 * because of AS naming convention*/
#define SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
 * without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
 * this is due to inclusion of memmap.h to specify the location to which
 * the variable has to be placed. */
#include "Spi_MemMap.h"

/***************** CORE0 QSPI1 CONFIGURATION MemMap SECTION END *************/

/******************* CORE0 QSPI2 CONFIGURATION MEMMAP SECTION *************/

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
 * because of AS naming convention*/
 /* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
 shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
 names
 * because of AS naming convention*/
#define SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
 * without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
 * this is due to inclusion of memmap.h to specify the location to which
 * the variable has to be placed. */
#include "Spi_MemMap.h"

  /* QSPI2 */
static const Spi_QspiHwConfigType Spi_kQspiHwConfigQSPI2 =
{
  0x01000000U,               /* Active CS Level, SSOC SFR value */
  SPI_ASYNC_IB_BUFFER_SIZE_QSPI2,  /* Buffers on QSPI2 only */
  SPI_JOB_QUEUE_LENGTH_QSPI2,/* Job Queue Length */
  (uint8)0U,                 /* DMA Rx Channel */
  (uint8)3U,                 /* DMA Tx Channel */
  SPI_DMA_MAX_TCS_NUM_QSPI2, /* DMA TCS count, for both Rx and Tx */
  SPI_CLK_SLEEP_DISABLE,     /* Module Sleep disabled */
  (uint8)0U,                 /* Input class, MRIS bit field in PISEL SFR */
  1U                         /* Max Sequence Count on the QSPI */
};

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
 * because of AS naming convention*/
 /* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
 shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
 names
 * because of AS naming convention*/
#define SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
 * without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
 * this is due to inclusion of memmap.h to specify the location to which
 * the variable has to be placed. */
#include "Spi_MemMap.h"

/***************** CORE0 QSPI2 CONFIGURATION MemMap SECTION END *************/

/******************* CORE0 QSPI3 CONFIGURATION MEMMAP SECTION *************/

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
 * because of AS naming convention*/
 /* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
 shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
 names
 * because of AS naming convention*/
#define SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
 * without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
 * this is due to inclusion of memmap.h to specify the location to which
 * the variable has to be placed. */
#include "Spi_MemMap.h"

  /* QSPI3 */
static const Spi_QspiHwConfigType Spi_kQspiHwConfigQSPI3 =
{
  0x00200000U,               /* Active CS Level, SSOC SFR value */
  SPI_ASYNC_IB_BUFFER_SIZE_QSPI3,  /* Buffers on QSPI3 only */
  SPI_JOB_QUEUE_LENGTH_QSPI3,/* Job Queue Length */
  (uint8)4U,                 /* DMA Rx Channel */
  (uint8)5U,                 /* DMA Tx Channel */
  SPI_DMA_MAX_TCS_NUM_QSPI3, /* DMA TCS count, for both Rx and Tx */
  SPI_CLK_SLEEP_DISABLE,     /* Module Sleep disabled */
  (uint8)0U,                 /* Input class, MRIS bit field in PISEL SFR */
  1U                         /* Max Sequence Count on the QSPI */
};

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
 * because of AS naming convention*/
 /* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
 shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
 names
 * because of AS naming convention*/
#define SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
 * without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
 * this is due to inclusion of memmap.h to specify the location to which
 * the variable has to be placed. */
#include "Spi_MemMap.h"

/***************** CORE0 QSPI3 CONFIGURATION MemMap SECTION END *************/




























/********************CORE0 RX/TX BUFFERS MEMMAP SECTION***********************/


/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
 * because of AS naming convention*/
 /* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
 shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
 names
 * because of AS naming convention*/
#define SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
 * without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
 * this is due to inclusion of memmap.h to specify the location to which
 * the variable has to be placed. */
#include "Spi_MemMap.h"
/* Lookup table to hold the offset in buffer and total elements to be transferred for all IB channels.
Index - Represents channel number, 1st element - Offset in buffer, 2nd element - Total elements to be transmitted */


static const Spi_CoreChannelOffsetType Spi_ChannelOffsets_Core0[SPI_NUM_IB_CHANNELS_CORE0 +  SPI_NUM_EB_CHANNELS_CORE0 + 1U] =
{
  {0, 0},    /*SpiChannel_QSPI0*/
  {0, 0},    /*SpiChannel_QSPI1_6*/
  {0, 0},    /*SpiChannel_QSPI1_5*/
  {0, 0},    /*SpiChannel_QSPI1_4*/
  {0, 0},    /*SpiChannel_QSPI1_3*/
  {0, 0},    /*SpiChannel_QSPI1_2*/
  {0, 0},    /*SpiChannel_QSPI1_1*/
  {0, 0},    /*SpiChannel_QSPI2*/
  {0, 0},    /*SpiChannel_QSPI3*/
  {0xFFFF, 0xFFFF}
};


/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
 * because of AS naming convention*/
 /* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
 shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
 names
 * because of AS naming convention*/
#define SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
 * without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
 * this is due to inclusion of memmap.h to specify the location to which
 * the variable has to be placed. */
#include "Spi_MemMap.h"
/********************CORE0 RX/TX BUFFERS MEMMAP SECTION***********************/


/******************* CORE0 Spi_Config_Core CONFIGURATION MEMMAP SECTION *************/


/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
 * because of AS naming convention*/
 /* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
 shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
 names
 * because of AS naming convention*/
#define SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
 * without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
 * this is due to inclusion of memmap.h to specify the location to which
 * the variable has to be placed. */
#include "Spi_MemMap.h"

/* MISRA2012_RULE_8_7_JUSTIFICATION: Spi_Config_Core0 is being used globally
 * cannot be static */
 /* MISRA2012_RULE_8_4_JUSTIFICATION: Agreed violation */


const Spi_CoreConfigType Spi_Config_Core0 =
{
  /* Sequence Configuration */
  Spi_kSequenceConfig_Core0,

  /* Job configuration */
  Spi_kJobConfig_Core0,

  /* Channel Configuration */
  Spi_kChannelConfig_Core0,

  Spi_ChannelOffsets_Core0,
  /* QSPI Hw configuration */
  {

    &Spi_kQspiHwConfigQSPI0,

    &Spi_kQspiHwConfigQSPI1,

    &Spi_kQspiHwConfigQSPI2,

    &Spi_kQspiHwConfigQSPI3,

    NULL_PTR,

     NULL_PTR,
  },

  /* Hw Map Index */


  /*
  (000 QSPI not configured for core0)
  (001 QSPI configured as Sync for core0)
  (010 QSPI configured as Async for core0)

  QSPI5 - 0

  QSPI4 - 0

  QSPI3 - 2

  QSPI2 - 2
  
  QSPI1 - 2

  QSPI0 - 2
  */

  0x00492U,

  /* No. of Sequences configured */
  9U,

  /* No. of Jobs configured */
  9U,

  /* No. of Channels configured */
  9U
};


/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
 * because of AS naming convention*/
 /* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
 shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
 names
 * because of AS naming convention*/
#define SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
 * without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
 * this is due to inclusion of memmap.h to specify the location to which
 * the variable has to be placed. */
#include "Spi_MemMap.h"

/***************** CORE0 Spi_Config_Core CONFIGURATION MemMap SECTION END *************/







/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
 * because of AS naming convention*/
 /* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
 shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
 names
 * because of AS naming convention*/
#define SPI_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
 * without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
 * this is due to inclusion of memmap.h to specify the location to which
 * the variable has to be placed. */
#include "Spi_MemMap.h"



const Spi_ConfigType Spi_Config =
{
  {

    &Spi_Config_Core0  ,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR

  },
  SequenceLookupIndex,
  JobLookupIndex,
  ChannelLookupIndex,

  /*Total number of Sequence*/
  9U,
  /*Total number of Jobs*/
  9U,
  /*Total number of Channels*/
  9U,
  /*Sync Delay*/
  65535U
};


/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers shall be distinct
 * because of AS naming convention*/
 /* MISRA2012_RULE_5_2_JUSTIFICATION: Identifiers declared in the same scope
 shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: Macro identifiers shall be distinct
 * because of AS naming convention*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: Identifiers shall be distinct from macro
 names
 * because of AS naming convention*/
#define SPI_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
/* MISRA2012_RULE_4_10_JUSTIFICATION: Spi_Memmap.h is repeatedly included
 * without include guard. This is as per AUTOSAR */
/* MISRA2012_RULE_20_1_JUSTIFICATION: Declaration before #include,
 * this is due to inclusion of memmap.h to specify the location to which
 * the variable has to be placed. */
#include "Spi_MemMap.h"

/* End Of File */
