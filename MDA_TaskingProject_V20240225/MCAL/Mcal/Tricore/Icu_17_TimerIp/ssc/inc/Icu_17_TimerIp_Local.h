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
**  FILENAME     : Icu_17_TimerIp_Local.h                                     **
**                                                                            **
**  VERSION      : 11.0.0                                                     **
**                                                                            **
**  DATE         : 2018-08-22                                                 **
**                                                                            **
**  VARIANT      : Variant PB                                                 **
**                                                                            **
**  PLATFORM     : Infineon AURIX2G                                           **
**                                                                            **
**  AUTHOR       : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**  VENDOR       : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : Icu Driver Local header definition file                    **
**                                                                            **
**  SPECIFICATION(S) : Specification of Icu Driver, AUTOSAR Release 4.2.2     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/* [cover parentID={52CE2EA5-4B3F-4622-BAC4-DD150AEC5AD2}] */
/*  [/cover] */
#ifndef ICU_17_TIMERIP_LOCAL_H
#define ICU_17_TIMERIP_LOCAL_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                             **
*******************************************************************************/

/* General Requirements:
  All timer units will be of ticks. This is mainly applicable in
  Icu_17_TimerIp_GetTimeElapsed , Icu_17_TimerIp_GetDutyCycleValues.
  NA (no DEM)
  All API's parameter checking is enabled by ICU_17_TIMERIP_DEV_ERROR_DETECT
  NA (no DEM)
  NA (no DEM)
  no specific error implementation
  resetting interrupt flag handled by GPTA Driver.
  Other required modules are MCU, PORT , IRQ and GPTA.
  NA (File structure)
  NA (DEM)
*/

/******************************************************************************
**                      Private Macro Definitions                            **
******************************************************************************/
#define ICU_GTM_TIM_CICTRL_POS  ((uint32)6UL)
#define ICU_GTM_TIM_FLTEN_POS  (16U)
#define ICU_GTM_TIM_FLTCNTFRQ_POS  (17U)
#define ICU_GTM_TIM_MODEFORRISING_POS  (20U)
#define ICU_GTM_TIM_MODEFORFALLING_POS  (22U)
#define ICU_GTM_INVALID_NUMBER (0xFFU)
#define ICU_GTM_CHANNELS_PER_TIM_MODULE (8U)
#define ICU_GTM_MODULE_NO_MSK  (0x7U)
#define ICU_GTM_TIMER_MASK (0x00FFFFFFU)
#define ICU_GTM_TIMER_MAX (0x00FFFFFFU)
#define ICU_GTM_TIM_INTERRUPTMODE_POS  (6U)
#define ICU_GTM_CHAN_ID_MOD_NO_POS (2U)
#define ICU_GTM_TIMINSEL_CH1SEL_OFF (4u)
#define ICU_MCU_TIM_MODULE_POS (0x8U)

#define ICU_GTM_TIMINSEL_MASK (0xFu)
#define ICU_TIMER_UNUSED (0xFFU)

/* To indicate an error */
#define ICU_ERROR_FOUND                (1U)
#define ICU_ERROR_NOT_FOUND            (0U)

/* For CLRR position in SRC registers */
#define ICU_CLRR_POSITION              (25U)
/* To assert CLRR */
#define ICU_CLRR_ASSERT                (1UL)
/* To enable the notification */
#define ICU_ENABLE_NOTIFICATION        (1U)

/* To assert EIEN for ERU line */
#define ICU_ASSERT_EIEN                (0x800U)

/* Number of bits to setup edge */
#define ICU_ERU_EDGE_BITS              2
#define ICU_ERU_EDGE_MASK              (0x3UL)

/* Number of bits to setup edge and enable REN */
#define ICU_ERU_EDGEREN_BITS           4

/* Mask for Core ID in channel map */
#define ICU_CHNL_MAP_CORE_ID_MASK (0xF00UL)
#define ICU_CHNL_MAP_CORE_ID_OFFSET (8U)
/* Mask for core specific channel index in channel map */
#define ICU_CHNL_MAP_CHNL_INDEX_MASK ((uint8)0xFFUL)
#define ICU_CHNL_MAP_INVALID_CHNL_INDEX (0xFFUL)

/* Bit Positions in Icu_GlbIndexStatus */
/*Position 0 
  Used to provide information on channel status when 
  Icu_17_TimerIp_GetInputState() called
*/
#define ICU_CHNL_STATUS_POS            (0U)
/* ICU_CHNL_STATUS_POS bit length */
#define ICU_CHNL_STATUS_BIT_LENGTH     1
/*Position 1 */
#define ICU_CHNL_WAKEUP_CAPABLE_POS    (1U)

/* ICU_CHNL_WAKEUP_CAPABLE_POS bit length */
#define ICU_CHNL_WAKEUP_BIT_LENGTH     1
/*Position 2
  Used to store the Activation asked for which kind of edges 
  RISING_EDGE/FALLING_EDGE/BOTH_EDGES. 
  No of bits :2
*/
#define ICU_CHNL_EDGE_POS              (2U)

/*
  Used to store the number of bits required for ICU_CHNL_EDGE_POS 
*/
#define ICU_CHNL_EDGE_BIT_LENGTH       2
/*
  Used to store the mask to extract Activation edge
*/
#define ICU_CHNL_EDGE_MASK              (0xCU)
/* 
   Position 4
   Used to keep track on to know whether notification required or not.
*/
#define ICU_CHNL_NOTIF_PRESENCE_POS    (4U)
/* ICU_CHNL_NOTIF_PRESENCE_POS bit length */
#define ICU_CHNL_NOTIF_BIT_LENGTH      1
/*
  Position 5
  Used for Edge Counting and Time Stamp, Signal measurement
*/
#define ICU_CHNL_ACTIVITY_STARTED_POS  (5U)

/* ICU_CHNL_ACTIVITY_STARTED_POS bit length */
#define ICU_CHNL_ACTIVITY_BIT_LENGTH   1
/*
  Position 6
  Indicates if Notification is cleared for an Edge Detection Channel 
  No of bits: 1
*/
#define ICU_CHNL_ERU_GPT_SIGEDGE_STATUS_POS       (6UL)

/*
  Indicates if Notification is cleared for an Edge Detection Channel 
  No of bits: 1
*/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
#define ICU_CHNL_ERU_GPT_SIGEDGE_STATUS_BIT_LENGTH      1

/*
  Position 7
  Indicates if an edge detection Channel has been disabled 
  No of bits: 1
*/
#define ICU_CHNL_MULTIEDGE_STAT_POS       (7UL)

/*
  Indicates if an edge detection Channel has been disabled 
  No of bits: 1
*/
#define ICU_CHNL_MULTIEDGE_STAT_BIT_LENGTH      1
/*
  Position 8
  Indicates if an reset edge count Channel status
  No of bits: 1
*/
#define ICU_CHNL_RSTEDGE_STAT_POS       (8U)
/*
  Indicates if an reset edge count Channel status
  No of bits: 1
*/
#define ICU_CHNL_RSTEDGE_STAT_BIT_LENGTH      1

/*
  Position 9
  Indicates if Signal measure Get input state
  No of bits: 1
*/
#define ICU_SIGNALMESURE_INPUT_STAT_POS       (9U)

#define ICU_SIGNALMESURE_INPUT_STAT_LENGTH       1

/*
  Position 10
  Indicates if Signal measure HIGH/LOW time overflow ISR executed on wrong phase
  No of bits: 1
*/
#define ICU_OVFL_ISR_STAT_POS       (10U)

#define ICU_OVFL_ISR_STAT_LENGTH       1
/* To denote Activity has started */
#define ICU_ACTIVITY_STARTED           (1U)
/* To denote Reset edge count Activity has started */
#define ICU_RSTEDCNT_ACTIVITY_STARTED  (1U)
/* ERU INTFx clear position */
#define ICU_ERU_FCSTART                ((uint32)16)
/* Maximum number of ICU Channels */
#define ICU_MAX_USAGE                  (0x7fU) /* 127 */
/* Status to indicate that ICU is initialized */
#define ICU_DEINITPENDING              ((uint32)2)
/* Status to indicate that ICU is initialized */
#define ICU_INITIALIZED                (1U)
/* Status to indicate that ICU is de-initailized */
#define ICU_DEINITIALIZED              ((uint32)0)

#define ICU_INIT_STAUS_SIZE            2
#define ICU_INIT_STAUS_MASK            (0x3U)
#define ICU_SWAP_32BIT_MASK           (0xFFFFFFFFUL)
#define ICU_SWAP_16BIT_MASK           (0xFFFFUL)
#define ICU_CCU6_SIG_MEAS_MASK       (0xFFFFU)
#define ICU_CCU6_SIG_MEAS_ACTIVETIME_OFFSET       (0x10U)
#define ICU_24BIT_MASK           (0xFFFFFFUL)
#define ICU_CHNL_MAP_POS              (0x8U)
/* Number of bits to clear to disable a ERU Line */
#define ICU_ERU_DISABLE_BIT_LENGTH     12

/* Total number of ERU lines */
#define ICU_ERU_LINES                  (8U)

/* Eru Exis Bit Length  */
#define ICU_ERU_INP_BIT_LENGTH         3
#define ICU_ERU_EXIS_BIT_LENGTH         3

/* Bit length of IGP bit of IGCR  */
#define ICU_ERU_IGP_BIT_LENGTH        2
#define ICU_ERU_IGP_BIT_MASK        (3UL)

/* Bit length of IGP bit of IGCR  */
#define ICU_ERU_IGP_BIT_VALUE        (1)

/* Eru Fen Bit Length  */
#define ICU_ERU_FEN_BIT_LENGTH         2

/* Max Signal measurement channels position in MaxChannels array */
#define ICU_MAX_SIGNALMEASUREMENT_POS  (3U)   

/* Max Edge count channels position in MaxChannels array */

#define ICU_MAX_EDGECOUNTCHNL_POS      (2U)

/* TIM Modes */
#define ICU_GTM_TIM_MODE_TIPM  (3UL)
#define ICU_GTM_TIM_MODE_TIEM  (2UL)
#define ICU_GTM_TIM_MODE_TPWM  (0UL)
#define ICU_GTM_TIM_MODE_POS   (1U)
#define ICU_GTM_TIM_EN_POS   (0U)
#define ICU_GTM_TIM_EN_LEN    1

#define ICU_GTM_TIM_CLOCKDIV_POS  24U

/* mask to extract index of TINSEL register */
#define ICU_TOUTSEL_MASK            (0x3FU)

#define ICU_SELX_POS                (0x06U)

#define ICU_SELX_MASK               (0x07U)

#define ICU_CHANNEL_SEL_POS         (0x09U)

#define ICU_CHANNEL_SEL_MASK        (0x0FU)

#define ICU_INITCHECK_NO_ERR_VAL  (0xFFFFFFFFU)

/* TIM Interrupt Flag */
#define ICU_GTM_TIM_NEWVAL_IRQ  (0U)
#define ICU_GTM_TIM_NEWVAL_MASK  (1U)
#define ICU_GTM_TIM_CNTOFL_IRQ  (2U)

/* TIM Enable */
#define ICU_GTM_TIM_ENABLE_CHANNEL ((uint32)1UL)

/* TIM DSL */
#define ICU_GTM_TIM_ISL_DSL_FALLING (0UL)
#define ICU_GTM_TIM_ISL_DSL_RISING (0x2000UL)
#define ICU_GTM_TIM_ISL_DSL_BOTH (0x4000UL)

#define ICU_ECTRL_IMM_START (0x20000000U)

/* Mask to identify high or low time signal measure.*/
#define ICU_GTM_TIM_HIGH_LOW_TIME (0x10U)

/* FEN bit position in EICR register */
#define ICU_ERU_FEN_0_POS ((uint32)8)
#define ICU_ERU_FEN_1_POS ((uint32)24)

/* EXIS0 Position in EICR register */
#define ICU_ERU_EXIS0_POS  (4U)
#define ICU_ERU_EXIS1_POS  (20U)

/* IGPx Position in IGCR register */
#define ICU_ERU_IGP0_POS  ((uint8)(14UL))
#define ICU_ERU_IGP1_POS  ((uint8)(30UL))

/* INPx Position in EICR register */
#define ICU_ERU_INP0_POS  ((12U))
#define ICU_ERU_INP1_POS  ((28U))

/* Offset for upper half of EICR register */
#define ICU_EICR_UPPER_HALF_OFFSET (16U)
#define ICU_EICR_LOWER_HALF_OFFSET (0U)
#define ICU_EICR_UPPER_HALF_MASK (0xFFFF0000U)
#define ICU_EICR_LOWER_HALF_MASK (0x0000FFFFU)

#define ICU_ERU_EICR_LEN 16

#define ICU_ERU_CHNL_PAIR_COUNT (0x2U)
#define ICU_ERU_OGU_CHNL_BIT_POS (0x6U)
#define ICU_ERU_CHNL_MASK (0x7U)
#define ICU_ERU_EXIS_CHNL_BIT_POS (0x3U)
#define ICU_ERU_RISING_EDGE   (0x2U)
#define ICU_ERU_FALLING_EDGE  (0x1U)
#define ICU_ERU_BOTH_EDGE     (0x3U)
#define ICU_INVALID_OGU ((uint8)0xFFUL)

#define ICU_SET_BIT (1UL)
#define ICU_TIM_CTRL_DSL_POS (13)
#define ICU_TIM_CTRL_DSL_MASK (3UL)

#define ICU_TIM_CTRL_GPR0_CNTS_SEL (3U)
#define ICU_TIM_CTRL_GPR1_CNT_SEL  (3U)
#define ICU_TIM_CTRL_GPR0SEL_POS   (8U)
#define ICU_TIM_CTRL_GPR1SEL_POS   (10U)
#define ICU_TIM_CTRL_GPRxSEL_MASK   (3UL)
#define ICU_TIM_CTRL_ECNT_RESET_SET   (0x8000UL)
#if (ICU_17_TIMERIP_GTM_TIM_USED == STD_ON)
#define ICU_TIM_IRQ_ECNT_MASK (2UL)
#define ICU_TIM_GET_LOWER_15BITS (0x00007FFFUL)
#define ICU_TIM_GET_LOWER_NIBBLE_U   (0x0FU)
#define ICU_TIM_GET_UPPER_NIBBLE_U   (0xF0U)
#define ICU_TIM_GET_LOWER_NIBBLE_UL  (0x0FUL)
#define ICU_TIM_EDGE_COUNT_INFO (0xFF000000UL)
/* amount of Shift needed to bring 1 byte info of a 32 bit number to LSB */
#define ICU_BRING_TO_LSB_32     (24U)
#define ICU_BIT_4_MASK (0x10U)
#define ICU_BITS_PER_CHANNEL (2U)
#define ICU_GTM_CNTOVFL_FLAG_SET (0x4U)
#define ICU_GTM_NEWVAL_FLAG_SET (0x1U)
#endif

/* Write 1 to the Notify bits to clear the Interrupts */
#define ICU_GTM_CLEAR_INTERRUPTS (0x3fUL)

/* write 0 in IRQ_EN register during init(), later API's
enable the interrupts */
#define ICU_GTM_RESET_INTERRUPTS (0x0UL)
/*GTM Lookup table not in use */
#define ICU_GTM_LOOKUPTABLE_NOTUSED (0x0UL)
/* TIM CNT overflow offset */
#define ICU_TIM_CNTOFL_OFFSET (0x1000000UL)

/* To get CCU kernal and channel number */
#define ICU_CCU_GET_LOWER_NIBBLE (0x0FU)
#define ICU_CCU_GET_UPPER_NIBBLE (0xF0U)
#define ICU_CCU_NIBBLE_SIZE      (0x4U)
#define ICU_MCU_CCU_COMPARATOR_POS  (0x10U)

/* Defines for CCU handling */
#define ICU_CCU_INP_BITS_PER_CHANNEL (2U)
#define ICU_CCU_CAPTURE_MODE1 (4UL)
#define ICU_CCU_CAPTURE_MODE2 (5UL)
#define ICU_CCU_CAPTURE_MODE3 (6UL)
#define ICU_CCU_MSEL_BITS_PER_CHANNEL 4
#define ICU_CCU_PISEL_BITS_PER_CHANNEL (2U)
#define ICU_CCU_MSEL_RESET_VAL (0xFUL)
#define ICU_CCU_TCTR0_RESET_VAL (~(0xFUL))
#define ICU_CCU_CLEAR_INTERRUPT (3UL)
#define ICU_CCU_IS_BITS_PER_CHANNEL 2
#define ICU_CCU_RISING_EDGE (1U)
#define ICU_CCU_FALLING_EDGE (2U)
#define ICU_CCU_BOTH_EDGES (3U)
#define ICU_CCU_INTERRUPT_FLAG (3UL)
#define ICU_BRING_TO_BIT_0 (4U)
#define ICU_CCU6_MAX_T12_TIMER_VAL (0xFFFFUL)
#define ICU_LOWER_NIBBLE (0xFU)
#define ICU_CCU_T12_MAX_VAL (0xFFFFUL)
#define ICU_CC_NOT_USED (0xFFU)
#define ICU_CCU_SLEEP_REQD (1UL << 4)
#define ICU_CCU_PISEL_RESET_VAL (3UL)
#define ICU_CCU_INP_SR0 (3UL)
#define ICU_CCU_SRx_POSITION (7UL)
#define ICU_CCU_INP_SR_NUM (3UL)
#define ICU_CCU6_T12_START (1U)
#define ICU_CCU6_ACTIVETIME_OFFSET (0x10UL)
#define ICU_CCU6_ISR_FLAGS_MASK (0x3UL)
#define ICU_CCU6_CMPMODIF_CLEAR_OFFSET  (0x8U)


#define ICU_GPT12_TXCON_TXR_POS (6U)
#define ICU_GPT12_TXCON_TXR_LEN  1
#define ICU_GPT12_TX_RUN         1U
#define ICU_GPT12_TxI_POS        (0x0U)
#define ICU_GPT12_TxI_LEN        3
#define ICU_GPT12_COUNTER_MODE  ((uint32)1U << 3U)
#define ICU_GPT_TIMER_T3   (1U)
#define ICU_GPT_TIMER_T6    (4U)
/* GPT timer overflow offset */
#define ICU_GPT12_OVFL_OFFSET (0x10000UL)
#define ICU_GPT12_COUNTER_MASK (0xFFFFUL)
#define ICU_GPT12_COUNTER_MAX (0xFFFFUL)

/******************************************************************************
**                      Private Type Definitions                             **
******************************************************************************/
/* [cover parentID={666A6E66-5038-425b-9449-59CDD80515CB}] */
/*
  This structure is used by the driver in interrupt service routines
  to track the memory address ,counter and notification in Timestamp
  measurement.
*/
typedef struct
{
  /* Time stamping buffer address */
  Icu_17_TimerIp_ValueType *Address;
  /* buffer Size */
  uint16 Size;
  /* position of the Time stamp buffer */
  volatile uint16        Counter;
  /* Notification interval */
  uint16        Notify;
   /* Notification interval counter */
  volatile uint16        NotifyCounter;
} Icu_17_TimerIp_TimeCaptureParasType;
/*  [/cover] */

/* [cover parentID={9459BCBA-A873-4f4d-9282-6E549A12788A}] */
/*
  This structure is used by the driver in interrupt service routines
  to track the Active time, period and time marker in signal
  measurement.
*/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
typedef struct
{
  /* Active Time(high/low) */
  volatile uint32 ActiveTime;
  /* TimeMarker to track overflow */
  volatile uint32 RegValue;
  /* Reserved */
  volatile uint32 FirstEdgeFlag;
} Icu_17_TimerIp_SigMeasureParasCcu6Type;
/*  [/cover] */

/* [cover parentID=] */
/*
  This structure is used by the driver in interrupt service routines
  to track the edge count numbers in edge count.
*/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
typedef struct
{
  /* Edge count */
  volatile uint32 EdgeCounter;
  /* Reserved */
  uint32 Reserved1;
  /* Reserved */
  uint32 Reserved2;
} Icu_17_TimerIp_EdgeCountParasType;
/*  [/cover] */

/* [cover parentID={D7C99019-4A5B-422d-8A93-B73A6442BAF7}] */
/*
  This structure is used by the driver in interrupt service routines
  to track the edge detect count in multi edge detect mode for GPT12.
*/
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
  in generated code due to Autosar Naming constraints.*/
typedef struct
{
    /* Edge detect */
    uint32 EdgeDetectCount;
    /* Reserved */
    uint32 Reserved1;
    /* Reserved */
    uint32 Reserved2;
} Icu_17_TimerIp_EdgeDetectParasType;
/*  [/cover] */

typedef union {
  Icu_17_TimerIp_TimeCaptureParasType TimeCaptureParas;
  Icu_17_TimerIp_SigMeasureParasCcu6Type SigMeasureParasCcu6;
  Icu_17_TimerIp_EdgeCountParasType EdgeCountParas;
  Icu_17_TimerIp_EdgeDetectParasType EdgeDetectParas;
} Icu_17_TimerIp_ChannelData;
/* --------------------------------------------------------------
 Icu_17_TimerIp_CoreType
 -------------------------------------------------------------- */
#if(ICU_17_TIMERIP_MAX_CHANNELS != 0U)
typedef struct
{
  uint32* GlbIndexStatusBasePtr;
  Icu_17_TimerIp_ChannelData* ChannelDataBasePtr;

  /* Check for Report wakeup Source  */
#if (ICU_17_TIMERIP_REPORT_WAKEUP_SOURCE == STD_ON)
  EcuM_WakeupSourceType WakeupChannelInfo;
#endif
  Icu_17_TimerIp_ModeType GlobalMode;
}Icu_17_TimerIp_CoreType;
#endif 

#endif /* ICU_17_TIMERIP_LOCAL_H */

/*         STUBS              */
#define ICU_GETCOREID ((uint8)(Mcal_GetCpuIndex()))

