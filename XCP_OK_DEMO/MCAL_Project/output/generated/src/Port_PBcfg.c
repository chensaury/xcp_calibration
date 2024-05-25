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
**  FILENAME  : Port_PBCfg.c                                                  **
**                                                                            **
**  VERSION   : 5.0.0                                                         **
**                                                                            **
**  DATE, TIME: 2023-03-21, 20:00:22                                      **
**                                                                            **
**  GENERATOR : Build b170330-0431                                          **
**                                                                            **
**  BSW MODULE DECRIPTION : Port.bmd                                          **
**                                                                            **
**  VARIANT   : Variant PB                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Port configuration generated out of ECUC file              **
**                                                                            **
**  SPECIFICATION(S) : Specification of Port Driver, AUTOSAR Release 4.2.2    **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/


 
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of Port Header file */
#include "Port.h"




/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/


/* Macro definition for PORT pad drive control register Pn_PDR0 */
/* MISRA2012_RULE_4_9_JUSTIFICATION: Function like macros are used to calculate 
register values */
#define  Portx_lPdrConfig1(Pd0,Pd1,Pd2,Pd3,Pd4,Pd5,Pd6,Pd7)                    \
         ( ((uint32)(Pd7) << (uint32)28) | ((uint32)(Pd6) << (uint32)24) |     \
           ((uint32)(Pd5) << (uint32)20) | ((uint32)(Pd4) << (uint32)16) |     \
           ((uint32)(Pd3) << (uint32)12) |  ((uint32)(Pd2) << (uint32)8)  |    \
           ((uint32)(Pd1) << (uint32)4)  | (uint32)(Pd0)                       \
         )

/* Macro definition for PORT pad drive control register Pn_PDR1 */
/* MISRA2012_RULE_4_9_JUSTIFICATION: Function like macros are used to calculate 
register values */
#define  Portx_lPdrConfig2(Pd8,Pd9,Pd10,Pd11,Pd12,Pd13,Pd14,Pd15)              \
         ( ((uint32)(Pd15) << (uint32)28) | ((uint32)(Pd14) << (uint32)24) |   \
           ((uint32)(Pd13) << (uint32)20) | ((uint32)(Pd12) << (uint32)16) |   \
           ((uint32)(Pd11) << (uint32)12)|  ((uint32)(Pd10) << (uint32)8)  |   \
           ((uint32)(Pd9) << (uint32)4) | (uint32)(Pd8)                        \
         )                  
       
/* Macro definition for PORT Pad Disable Control Register */
/* MISRA2012_RULE_4_9_JUSTIFICATION: Function like macros are used to calculate 
register values */
#define Port_lDiscSet(b0,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15)   \
  ((uint16)(                                                                   \
            (uint32)(b0) | ((uint32)(b1) << (uint32)1) |                       \
            ((uint32)(b2) << (uint32)2) | ((uint32)(b3) << (uint32)3) |        \
            ((uint32)(b4) << (uint32)4) | ((uint32)(b5) << (uint32)5) |        \
            ((uint32)(b6) << (uint32)6) | ((uint32)(b7) << (uint32)7) |        \
            ((uint32)(b8) << (uint32)8) | ((uint32)(b9) << (uint32)9) |        \
            ((uint32)(b10) << (uint32)10) | ((uint32)(b11) << (uint32)11) |    \
            ((uint32)(b12) << (uint32)12) | ((uint32)(b13)<< (uint32)13) |     \
            ((uint32)(b14) << (uint32)14) | ((uint32)(b15) << (uint32)15)      \
           ))

/* MISRA2012_RULE_4_9_JUSTIFICATION: Function like macros are used to calculate 
register values */
#define Port_lPcsr(b0,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15)      \
  ((uint32)(                                                                   \
            ((uint32)(b0)) | ((uint32)(b1) << (uint32)1) |                     \
            ((uint32)(b2) << (uint32)2) | ((uint32)(b3) << (uint32)3) |        \
            ((uint32)(b4) << (uint32)4) | ((uint32)(b5) << (uint32)5) |        \
            ((uint32)(b6) << (uint32)6) | ((uint32)(b7) << (uint32)7) |        \
            ((uint32)(b8) << (uint32)8) | ((uint32)(b9) << (uint32)9) |        \
            ((uint32)(b10) << (uint32)10) | ((uint32)(b11) << (uint32)11) |    \
            ((uint32)(b12) << (uint32)12) | ((uint32)(b13) << (uint32)13) |    \
            ((uint32)(b14) << (uint32)14) | ((uint32)(b15) << (uint32)15)      \
           ))
       
/* Macro definition for PORT LPCR register for LVDS */
/* MISRA2012_RULE_4_9_JUSTIFICATION: Function like macros are used to calculate 
register values */
#define Port_lLvds(REN_CTRL,RX_EN,TERM,LRTXERM,LVDSM,PS,TEN_CTRL,TX_EN,\
                   VIDFFADJ,VOSDYN,VOSEXT,TX_PD,TX_PWDPD) \
  ((uint32)(                                                                   \
           ((uint32)(REN_CTRL)) | ((uint32)(RX_EN) << (uint32)1) |             \
           ((uint32)(TERM) << (uint32)2) | ((uint32)(LRTXERM) << (uint32)3) |  \
           ((uint32)(LVDSM) << (uint32)6) |((uint32)(PS) << (uint32)7) |       \
           ((uint32)(TEN_CTRL) << (uint32)8) |                                 \
           ((uint32)(TX_EN) << (uint32)9) |((uint32)(VIDFFADJ) << (uint32)10) |\
           ((uint32)(VOSDYN) << (uint32)12) | ((uint32)(VOSEXT) << (uint32)13)|\
           ((uint32)(TX_PD) << (uint32)14) | ((uint32)(TX_PWDPD) << (uint32)15)\
           ))
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/* [cover parentID={E4047F9A-8865-4b2c-9D3C-385479854EAD}] [/cover] */
#define PORT_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: To be compliant with autosar guidelines 
Port_Memmap.h header is included without safegaurd.*/
#include "Port_MemMap.h"

/*******************************************************************************
**                      Configuration Options                                 **
*******************************************************************************/
/*
                     Container : PortPinConfiguration
*/
/* Macros to define pin Default Input Output control value */
#define  PORT_PIN_DEFAULT                   (0x10U)

/* 
Configuration Options: Physical pin level
-LOW  (Low Volatage Level)
-HIGH (High Voltage Level) 
*/
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define PORT_PIN_LEVEL_LOW    (0x00U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define PORT_PIN_LEVEL_HIGH   (0x01U)

/* 
Configuration Options: Pin input pull resistor 
-NO PULL
-PULL DOWN
-PULL UP
*/
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define PORT_PIN_IN_PULL_UP     (0x10U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define PORT_PIN_IN_PULL_DOWN   (0x08U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define PORT_PIN_IN_NO_PULL     (0x00U)

/*
Configuration Options: Pin driver strength
*/
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define RFAST_PORT_PIN_STRONG_DRIVER_SHARP_EDGE  (0x0U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define RFAST_PORT_PIN_STRONG_DRIVER_MEDIUM_EDGE (0x1U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define RFAST_PORT_PIN_MEDIUM_DRIVER             (0x2U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define RFAST_PORT_PIN_RGMII_DRIVER              (0x3U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define RFAST_PORT_PIN_DEFAULT_DRIVER            (0x0U)

/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define FAST_PORT_PIN_STRONG_DRIVER_SHARP_EDGE  (0x0U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define FAST_PORT_PIN_STRONG_DRIVER_MEDIUM_EDGE (0x1U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define FAST_PORT_PIN_MEDIUM_DRIVER             (0x2U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define FAST_PORT_PIN_DEFAULT_DRIVER            (0x0U)


/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define SLOW_PORT_PIN_MEDIUM_DRIVER_SHARP_EDGE  (0x0U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define SLOW_PORT_PIN_MEDIUM_DRIVER             (0x1U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define SLOW_PORT_PIN_DEFAULT_DRIVER            (0x0U)

/* Pin driver strength value for the non available pins*/
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define  PORT_PIN_PAD_STRENGTH_DEFAULT      (0x0U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define  PORT_PIN_PAD_LEVEL_DEFAULT         (0x0U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define  PORT_PIN_PAD_DEFAULT               (0x0U)

/* 
Configuration Options: Pin output characteristics 
-PUSHPULL
-OPENDRAIN
*/

/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define PORT_PIN_OUT_PUSHPULL     (0x00U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define PORT_PIN_OUT_OPENDRAIN    (0x40U)

/*
Configuration Options: Pin Pad Level  
*/
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE  (0x0U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define PORT_INPUT_LEVEL_TTL_3_3V       (0xCU)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define PORT_INPUT_LEVEL_TTL_5_0V       (0x8U)


/* For the Px_DISC register value set */
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define PORT_PIN_ANALOG_INPUT_ENABLE  (0x1U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define PORT_PIN_ANALOG_INPUT_DISABLE (0x0U)

/* For PCSR register */
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define PORT_PCSR_ENABLE  (0x1U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define PORT_PCSR_DISABLE (0x0U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define PORT_PCSR_DEFAULT   (0x0U)

/* For Pn_LPCR registers wrt LVDSH pads */
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define PORT_LVDS_PORT_CONTROLLED           (0x0U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define PORT_LVDS_HSCT_CONTROLLED           (0x1U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define PORT_LVDS_ENABLE                    (0x1U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define PORT_LVDS_DISABLE                   (0x0U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define PORT_LVDS_INTERNAL_TERMINATION      (0x1U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define PORT_LVDS_EXTERNAL_TERMINATION      (0x0U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define PORT_LVDS_POLY_RESISTOR_TERM        (0x0U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define PORT_LVDS_LVDSM                     (0x1U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define PORT_LVDS_LVDSH                     (0x0U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define PAD_SUPPLY_3_3V                     (0x0U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define PAD_SUPPLY_5_0V                    (0x1U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define PORT_LVDS_LVDS_VDIFF_ADJ            (0x1U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define PORT_LVDS_VOSDYN                    (0x1U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define PORT_LVDS_VOSEXT                    (0x0U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define PORT_LVDS_POWER_DOWN                (0x1U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define PORT_LVDS_TX_PWDPD_ENABLE           (0x1U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define PORT_LVDS_TX_PWDPD_DISABLE          (0x0U)
/* MISRA2012_RULE_2_5_JUSTIFICATION: Local Macros used in the configuration 
structures for generation values for structure members. The use of the macros 
in code is dependent on user configuration and hence the macros cant be removed.*/
#define PORT_LVDS_DEFAULT                   (0x0U)



/******************************************************************************/



static const Port_n_ConfigType Port_kConfiguration[] = 
{
/*                              Port0                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 0*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 1*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 2*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 3*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 4*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 5*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 6*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 7*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 8*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 9*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 10*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 11*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 12*/
  (PORT_PIN_DEFAULT),/*Pin 13*/
  (PORT_PIN_DEFAULT),/*Pin 14*/
  (PORT_PIN_DEFAULT)/*Pin 15*/
      
    },
  
    {
      /* Port pins initial level configuration */
      
         PORT_PIN_LEVEL_LOW,/* Pin 0 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 1 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 2 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 3 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 4 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 5 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 6 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 7 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 8 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 9 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 10 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 11 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 12 */ 
         0U,/* Pin 13 */ 
         0U,/* Pin 14 */ 
         0U /* Pin 15 */ 
      
    },
  /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin0*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin1*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin2*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin3*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin4*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin5*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin6*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  /*Pin7*/
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin8*/
     (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin9*/
     (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin10*/
     (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin11*/
     (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin12*/
   (PORT_PIN_PAD_DEFAULT),/*Pin13*/
   (PORT_PIN_PAD_DEFAULT),/*Pin14*/
   (PORT_PIN_PAD_DEFAULT)/*Pin15*/
                     ),

    {/* Port pin run time mode changeable or not configuration */
      
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 0 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 1 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 2 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 3 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 4 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 5 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 6 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 7 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 8 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 9 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 10 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 11 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 12 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 13 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 14 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE /* Pin 15 */

      
    }

   },
/*                              Port1                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      
  (PORT_PIN_DEFAULT),/*Pin 0*/
  (PORT_PIN_DEFAULT),/*Pin 1*/
  (PORT_PIN_DEFAULT),/*Pin 2*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 3*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 4*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 5*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 6*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 7*/
  (PORT_PIN_DEFAULT),/*Pin 8*/
  (PORT_PIN_DEFAULT),/*Pin 9*/
  (PORT_PIN_DEFAULT),/*Pin 10*/
  (PORT_PIN_DEFAULT),/*Pin 11*/
  (PORT_PIN_DEFAULT),/*Pin 12*/
  (PORT_PIN_DEFAULT),/*Pin 13*/
  (PORT_PIN_DEFAULT),/*Pin 14*/
  (PORT_PIN_DEFAULT)/*Pin 15*/
      
    },
  
    {
      /* Port pins initial level configuration */
      
         0U,/* Pin 0 */ 
         0U,/* Pin 1 */ 
         0U,/* Pin 2 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 3 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 4 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 5 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 6 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 7 */ 
         0U,/* Pin 8 */ 
         0U,/* Pin 9 */ 
         0U,/* Pin 10 */ 
         0U,/* Pin 11 */ 
         0U,/* Pin 12 */ 
         0U,/* Pin 13 */ 
         0U,/* Pin 14 */ 
         0U /* Pin 15 */ 
      
    },
  /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
  (PORT_PIN_PAD_DEFAULT),/*Pin0*/
  (PORT_PIN_PAD_DEFAULT),/*Pin1*/
  (PORT_PIN_PAD_DEFAULT),/*Pin2*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin3*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin4*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin5*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin6*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  /*Pin7*/
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
  (PORT_PIN_PAD_DEFAULT),/*Pin8*/
   (PORT_PIN_PAD_DEFAULT),/*Pin9*/
   (PORT_PIN_PAD_DEFAULT),/*Pin10*/
   (PORT_PIN_PAD_DEFAULT),/*Pin11*/
   (PORT_PIN_PAD_DEFAULT),/*Pin12*/
   (PORT_PIN_PAD_DEFAULT),/*Pin13*/
   (PORT_PIN_PAD_DEFAULT),/*Pin14*/
   (PORT_PIN_PAD_DEFAULT)/*Pin15*/
                     ),

    {/* Port pin run time mode changeable or not configuration */
      
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 0 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 1 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 2 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 3 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 4 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 5 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 6 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 7 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 8 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 9 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 10 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 11 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 12 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 13 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 14 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE /* Pin 15 */

      
    }

   },
/*                              Port2                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 0*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 1*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 2*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 3*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 4*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 5*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 6*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 7*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 8*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 9*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 10*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 11*/
  (PORT_PIN_DEFAULT),/*Pin 12*/
  (PORT_PIN_DEFAULT),/*Pin 13*/
  (PORT_PIN_DEFAULT),/*Pin 14*/
  (PORT_PIN_DEFAULT)/*Pin 15*/
      
    },
  
    {
      /* Port pins initial level configuration */
      
         PORT_PIN_LEVEL_LOW,/* Pin 0 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 1 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 2 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 3 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 4 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 5 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 6 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 7 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 8 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 9 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 10 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 11 */ 
         0U,/* Pin 12 */ 
         0U,/* Pin 13 */ 
         0U,/* Pin 14 */ 
         0U /* Pin 15 */ 
      
    },
  /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin0*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin1*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin2*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin3*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin4*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin5*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin6*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  /*Pin7*/
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin8*/
     (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin9*/
     (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin10*/
     (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin11*/
   (PORT_PIN_PAD_DEFAULT),/*Pin12*/
   (PORT_PIN_PAD_DEFAULT),/*Pin13*/
   (PORT_PIN_PAD_DEFAULT),/*Pin14*/
   (PORT_PIN_PAD_DEFAULT)/*Pin15*/
                     ),

    {/* Port pin run time mode changeable or not configuration */
      
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 0 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 1 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 2 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 3 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 4 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 5 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 6 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 7 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 8 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 9 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 10 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 11 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 12 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 13 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 14 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE /* Pin 15 */

      
    }

   },
/*                              Port10                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 0*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 1*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 2*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 3*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 4*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 5*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 6*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 7*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 8*/
  (PORT_PIN_DEFAULT),/*Pin 9*/
  (PORT_PIN_DEFAULT),/*Pin 10*/
  (PORT_PIN_DEFAULT),/*Pin 11*/
  (PORT_PIN_DEFAULT),/*Pin 12*/
  (PORT_PIN_DEFAULT),/*Pin 13*/
  (PORT_PIN_DEFAULT),/*Pin 14*/
  (PORT_PIN_DEFAULT)/*Pin 15*/
      
    },
  
    {
      /* Port pins initial level configuration */
      
         PORT_PIN_LEVEL_LOW,/* Pin 0 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 1 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 2 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 3 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 4 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 5 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 6 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 7 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 8 */ 
         0U,/* Pin 9 */ 
         0U,/* Pin 10 */ 
         0U,/* Pin 11 */ 
         0U,/* Pin 12 */ 
         0U,/* Pin 13 */ 
         0U,/* Pin 14 */ 
         0U /* Pin 15 */ 
      
    },
  /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin0*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin1*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin2*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin3*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin4*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin5*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin6*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  /*Pin7*/
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin8*/
   (PORT_PIN_PAD_DEFAULT),/*Pin9*/
   (PORT_PIN_PAD_DEFAULT),/*Pin10*/
   (PORT_PIN_PAD_DEFAULT),/*Pin11*/
   (PORT_PIN_PAD_DEFAULT),/*Pin12*/
   (PORT_PIN_PAD_DEFAULT),/*Pin13*/
   (PORT_PIN_PAD_DEFAULT),/*Pin14*/
   (PORT_PIN_PAD_DEFAULT)/*Pin15*/
                     ),

    {/* Port pin run time mode changeable or not configuration */
      
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 0 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 1 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 2 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 3 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 4 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 5 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 6 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 7 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 8 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 9 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 10 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 11 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 12 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 13 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 14 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE /* Pin 15 */

      
    }

   },
/*                              Port11                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 0*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 1*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 2*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 3*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 4*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 5*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 6*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 7*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 8*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 9*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 10*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 11*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 12*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 13*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 14*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO)/*Pin 15*/
      
    },
  
    {
      /* Port pins initial level configuration */
      
         PORT_PIN_LEVEL_LOW,/* Pin 0 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 1 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 2 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 3 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 4 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 5 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 6 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 7 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 8 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 9 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 10 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 11 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 12 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 13 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 14 */ 
         PORT_PIN_LEVEL_LOW /* Pin 15 */ 
      
    },
  /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
      (PORT_PIN_PAD_LEVEL_DEFAULT|RFAST_PORT_PIN_DEFAULT_DRIVER)    ,/*Pin0*/
      (PORT_PIN_PAD_LEVEL_DEFAULT|RFAST_PORT_PIN_DEFAULT_DRIVER)    ,/*Pin1*/
      (PORT_PIN_PAD_LEVEL_DEFAULT|RFAST_PORT_PIN_DEFAULT_DRIVER)    ,/*Pin2*/
      (PORT_PIN_PAD_LEVEL_DEFAULT|RFAST_PORT_PIN_DEFAULT_DRIVER)    ,/*Pin3*/
      (PORT_PIN_PAD_LEVEL_DEFAULT|RFAST_PORT_PIN_DEFAULT_DRIVER)    ,/*Pin4*/
      (PORT_PIN_PAD_LEVEL_DEFAULT|RFAST_PORT_PIN_DEFAULT_DRIVER)    ,/*Pin5*/
      (PORT_PIN_PAD_LEVEL_DEFAULT|RFAST_PORT_PIN_DEFAULT_DRIVER)    ,/*Pin6*/
      (PORT_PIN_PAD_LEVEL_DEFAULT|RFAST_PORT_PIN_DEFAULT_DRIVER)    /*Pin7*/
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
      (PORT_PIN_PAD_LEVEL_DEFAULT|RFAST_PORT_PIN_DEFAULT_DRIVER)    ,/*Pin8*/
       (PORT_PIN_PAD_LEVEL_DEFAULT|RFAST_PORT_PIN_DEFAULT_DRIVER)    ,/*Pin9*/
       (PORT_PIN_PAD_LEVEL_DEFAULT|RFAST_PORT_PIN_DEFAULT_DRIVER)    ,/*Pin10*/
       (PORT_PIN_PAD_LEVEL_DEFAULT|RFAST_PORT_PIN_DEFAULT_DRIVER)    ,/*Pin11*/
       (PORT_PIN_PAD_LEVEL_DEFAULT|RFAST_PORT_PIN_DEFAULT_DRIVER)    ,/*Pin12*/
       (PORT_PIN_PAD_LEVEL_DEFAULT|SLOW_PORT_PIN_DEFAULT_DRIVER)    ,/*Pin13*/
       (PORT_PIN_PAD_LEVEL_DEFAULT|SLOW_PORT_PIN_DEFAULT_DRIVER)    ,/*Pin14*/
       (PORT_PIN_PAD_LEVEL_DEFAULT|SLOW_PORT_PIN_DEFAULT_DRIVER)    /*Pin15*/
                     ),

    {/* Port pin run time mode changeable or not configuration */
      
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 0 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 1 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 2 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 3 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 4 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 5 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 6 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 7 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 8 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 9 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 10 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 11 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 12 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 13 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 14 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE /* Pin 15 */

      
    }

   },
/*                              Port12                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 0*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 1*/
  (PORT_PIN_DEFAULT),/*Pin 2*/
  (PORT_PIN_DEFAULT),/*Pin 3*/
  (PORT_PIN_DEFAULT),/*Pin 4*/
  (PORT_PIN_DEFAULT),/*Pin 5*/
  (PORT_PIN_DEFAULT),/*Pin 6*/
  (PORT_PIN_DEFAULT),/*Pin 7*/
  (PORT_PIN_DEFAULT),/*Pin 8*/
  (PORT_PIN_DEFAULT),/*Pin 9*/
  (PORT_PIN_DEFAULT),/*Pin 10*/
  (PORT_PIN_DEFAULT),/*Pin 11*/
  (PORT_PIN_DEFAULT),/*Pin 12*/
  (PORT_PIN_DEFAULT),/*Pin 13*/
  (PORT_PIN_DEFAULT),/*Pin 14*/
  (PORT_PIN_DEFAULT)/*Pin 15*/
      
    },
  
    {
      /* Port pins initial level configuration */
      
         PORT_PIN_LEVEL_LOW,/* Pin 0 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 1 */ 
         0U,/* Pin 2 */ 
         0U,/* Pin 3 */ 
         0U,/* Pin 4 */ 
         0U,/* Pin 5 */ 
         0U,/* Pin 6 */ 
         0U,/* Pin 7 */ 
         0U,/* Pin 8 */ 
         0U,/* Pin 9 */ 
         0U,/* Pin 10 */ 
         0U,/* Pin 11 */ 
         0U,/* Pin 12 */ 
         0U,/* Pin 13 */ 
         0U,/* Pin 14 */ 
         0U /* Pin 15 */ 
      
    },
  /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin0*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin1*/
  (PORT_PIN_PAD_DEFAULT),/*Pin2*/
  (PORT_PIN_PAD_DEFAULT),/*Pin3*/
  (PORT_PIN_PAD_DEFAULT),/*Pin4*/
  (PORT_PIN_PAD_DEFAULT),/*Pin5*/
  (PORT_PIN_PAD_DEFAULT),/*Pin6*/
  (PORT_PIN_PAD_DEFAULT)/*Pin7*/
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
  (PORT_PIN_PAD_DEFAULT),/*Pin8*/
   (PORT_PIN_PAD_DEFAULT),/*Pin9*/
   (PORT_PIN_PAD_DEFAULT),/*Pin10*/
   (PORT_PIN_PAD_DEFAULT),/*Pin11*/
   (PORT_PIN_PAD_DEFAULT),/*Pin12*/
   (PORT_PIN_PAD_DEFAULT),/*Pin13*/
   (PORT_PIN_PAD_DEFAULT),/*Pin14*/
   (PORT_PIN_PAD_DEFAULT)/*Pin15*/
                     ),

    {/* Port pin run time mode changeable or not configuration */
      
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 0 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 1 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 2 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 3 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 4 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 5 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 6 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 7 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 8 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 9 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 10 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 11 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 12 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 13 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 14 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE /* Pin 15 */

      
    }

   },
/*                              Port13                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 0*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 1*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 2*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 3*/
  (PORT_PIN_DEFAULT),/*Pin 4*/
  (PORT_PIN_DEFAULT),/*Pin 5*/
  (PORT_PIN_DEFAULT),/*Pin 6*/
  (PORT_PIN_DEFAULT),/*Pin 7*/
  (PORT_PIN_DEFAULT),/*Pin 8*/
  (PORT_PIN_DEFAULT),/*Pin 9*/
  (PORT_PIN_DEFAULT),/*Pin 10*/
  (PORT_PIN_DEFAULT),/*Pin 11*/
  (PORT_PIN_DEFAULT),/*Pin 12*/
  (PORT_PIN_DEFAULT),/*Pin 13*/
  (PORT_PIN_DEFAULT),/*Pin 14*/
  (PORT_PIN_DEFAULT)/*Pin 15*/
      
    },
  
    {
      /* Port pins initial level configuration */
      
         PORT_PIN_LEVEL_HIGH,/* Pin 0 */ 
         PORT_PIN_LEVEL_HIGH,/* Pin 1 */ 
         PORT_PIN_LEVEL_HIGH,/* Pin 2 */ 
         PORT_PIN_LEVEL_HIGH,/* Pin 3 */ 
         0U,/* Pin 4 */ 
         0U,/* Pin 5 */ 
         0U,/* Pin 6 */ 
         0U,/* Pin 7 */ 
         0U,/* Pin 8 */ 
         0U,/* Pin 9 */ 
         0U,/* Pin 10 */ 
         0U,/* Pin 11 */ 
         0U,/* Pin 12 */ 
         0U,/* Pin 13 */ 
         0U,/* Pin 14 */ 
         0U /* Pin 15 */ 
      
    },
  /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
      (PORT_PIN_PAD_LEVEL_DEFAULT|FAST_PORT_PIN_DEFAULT_DRIVER)    ,/*Pin0*/
      (PORT_PIN_PAD_LEVEL_DEFAULT|FAST_PORT_PIN_DEFAULT_DRIVER)    ,/*Pin1*/
      (PORT_PIN_PAD_LEVEL_DEFAULT|FAST_PORT_PIN_DEFAULT_DRIVER)    ,/*Pin2*/
      (PORT_PIN_PAD_LEVEL_DEFAULT|FAST_PORT_PIN_DEFAULT_DRIVER)    ,/*Pin3*/
  (PORT_PIN_PAD_DEFAULT),/*Pin4*/
  (PORT_PIN_PAD_DEFAULT),/*Pin5*/
  (PORT_PIN_PAD_DEFAULT),/*Pin6*/
  (PORT_PIN_PAD_DEFAULT)/*Pin7*/
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
  (PORT_PIN_PAD_DEFAULT),/*Pin8*/
   (PORT_PIN_PAD_DEFAULT),/*Pin9*/
   (PORT_PIN_PAD_DEFAULT),/*Pin10*/
   (PORT_PIN_PAD_DEFAULT),/*Pin11*/
   (PORT_PIN_PAD_DEFAULT),/*Pin12*/
   (PORT_PIN_PAD_DEFAULT),/*Pin13*/
   (PORT_PIN_PAD_DEFAULT),/*Pin14*/
   (PORT_PIN_PAD_DEFAULT)/*Pin15*/
                     ),

    {/* Port pin run time mode changeable or not configuration */
      
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 0 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 1 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 2 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 3 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 4 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 5 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 6 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 7 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 8 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 9 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 10 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 11 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 12 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 13 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 14 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE /* Pin 15 */

      
    }

   },
/*                              Port14                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 0*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 1*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 2*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 3*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 4*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 5*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 6*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 7*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 8*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 9*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 10*/
  (PORT_PIN_DEFAULT),/*Pin 11*/
  (PORT_PIN_DEFAULT),/*Pin 12*/
  (PORT_PIN_DEFAULT),/*Pin 13*/
  (PORT_PIN_DEFAULT),/*Pin 14*/
  (PORT_PIN_DEFAULT)/*Pin 15*/
      
    },
  
    {
      /* Port pins initial level configuration */
      
         PORT_PIN_LEVEL_LOW,/* Pin 0 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 1 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 2 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 3 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 4 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 5 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 6 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 7 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 8 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 9 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 10 */ 
         0U,/* Pin 11 */ 
         0U,/* Pin 12 */ 
         0U,/* Pin 13 */ 
         0U,/* Pin 14 */ 
         0U /* Pin 15 */ 
      
    },
  /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin0*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin1*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin2*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin3*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin4*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin5*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin6*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  /*Pin7*/
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin8*/
     (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin9*/
     (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin10*/
   (PORT_PIN_PAD_DEFAULT),/*Pin11*/
   (PORT_PIN_PAD_DEFAULT),/*Pin12*/
   (PORT_PIN_PAD_DEFAULT),/*Pin13*/
   (PORT_PIN_PAD_DEFAULT),/*Pin14*/
   (PORT_PIN_PAD_DEFAULT)/*Pin15*/
                     ),

    {/* Port pin run time mode changeable or not configuration */
      
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 0 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 1 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 2 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 3 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 4 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 5 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 6 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 7 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 8 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 9 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 10 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 11 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 12 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 13 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 14 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE /* Pin 15 */

      
    }

   },
/*                              Port15                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 0*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 1*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 2*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 3*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 4*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 5*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 6*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 7*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 8*/
  (PORT_PIN_DEFAULT),/*Pin 9*/
  (PORT_PIN_DEFAULT),/*Pin 10*/
  (PORT_PIN_DEFAULT),/*Pin 11*/
  (PORT_PIN_DEFAULT),/*Pin 12*/
  (PORT_PIN_DEFAULT),/*Pin 13*/
  (PORT_PIN_DEFAULT),/*Pin 14*/
  (PORT_PIN_DEFAULT)/*Pin 15*/
      
    },
  
    {
      /* Port pins initial level configuration */
      
         PORT_PIN_LEVEL_LOW,/* Pin 0 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 1 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 2 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 3 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 4 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 5 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 6 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 7 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 8 */ 
         0U,/* Pin 9 */ 
         0U,/* Pin 10 */ 
         0U,/* Pin 11 */ 
         0U,/* Pin 12 */ 
         0U,/* Pin 13 */ 
         0U,/* Pin 14 */ 
         0U /* Pin 15 */ 
      
    },
  /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin0*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin1*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin2*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin3*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin4*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin5*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin6*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  /*Pin7*/
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin8*/
   (PORT_PIN_PAD_DEFAULT),/*Pin9*/
   (PORT_PIN_PAD_DEFAULT),/*Pin10*/
   (PORT_PIN_PAD_DEFAULT),/*Pin11*/
   (PORT_PIN_PAD_DEFAULT),/*Pin12*/
   (PORT_PIN_PAD_DEFAULT),/*Pin13*/
   (PORT_PIN_PAD_DEFAULT),/*Pin14*/
   (PORT_PIN_PAD_DEFAULT)/*Pin15*/
                     ),

    {/* Port pin run time mode changeable or not configuration */
      
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 0 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 1 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 2 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 3 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 4 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 5 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 6 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 7 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 8 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 9 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 10 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 11 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 12 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 13 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 14 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE /* Pin 15 */

      
    }

   },
/*                              Port20                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 0*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 1*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 2*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 3*/
  (PORT_PIN_DEFAULT),/*Pin 4*/
  (PORT_PIN_DEFAULT),/*Pin 5*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 6*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 7*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 8*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 9*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 10*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 11*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 12*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 13*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 14*/
  (PORT_PIN_DEFAULT)/*Pin 15*/
      
    },
  
    {
      /* Port pins initial level configuration */
      
         PORT_PIN_LEVEL_LOW,/* Pin 0 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 1 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 2 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 3 */ 
         0U,/* Pin 4 */ 
         0U,/* Pin 5 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 6 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 7 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 8 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 9 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 10 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 11 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 12 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 13 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 14 */ 
         0U /* Pin 15 */ 
      
    },
  /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin0*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin1*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin2*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin3*/
  (PORT_PIN_PAD_DEFAULT),/*Pin4*/
  (PORT_PIN_PAD_DEFAULT),/*Pin5*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin6*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  /*Pin7*/
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin8*/
     (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin9*/
     (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin10*/
     (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin11*/
     (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin12*/
     (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin13*/
     (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin14*/
   (PORT_PIN_PAD_DEFAULT)/*Pin15*/
                     ),

    {/* Port pin run time mode changeable or not configuration */
      
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 0 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 1 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 2 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 3 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 4 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 5 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 6 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 7 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 8 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 9 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 10 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 11 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 12 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 13 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 14 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE /* Pin 15 */

      
    }

   },
/*                              Port21                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 0*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 1*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 2*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 3*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 4*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 5*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 6*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 7*/
  (PORT_PIN_DEFAULT),/*Pin 8*/
  (PORT_PIN_DEFAULT),/*Pin 9*/
  (PORT_PIN_DEFAULT),/*Pin 10*/
  (PORT_PIN_DEFAULT),/*Pin 11*/
  (PORT_PIN_DEFAULT),/*Pin 12*/
  (PORT_PIN_DEFAULT),/*Pin 13*/
  (PORT_PIN_DEFAULT),/*Pin 14*/
  (PORT_PIN_DEFAULT)/*Pin 15*/
      
    },
  
    {
      /* Port pins initial level configuration */
      
         PORT_PIN_LEVEL_LOW,/* Pin 0 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 1 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 2 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 3 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 4 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 5 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 6 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 7 */ 
         0U,/* Pin 8 */ 
         0U,/* Pin 9 */ 
         0U,/* Pin 10 */ 
         0U,/* Pin 11 */ 
         0U,/* Pin 12 */ 
         0U,/* Pin 13 */ 
         0U,/* Pin 14 */ 
         0U /* Pin 15 */ 
      
    },
  /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin0*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin1*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin2*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin3*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin4*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin5*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin6*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  /*Pin7*/
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
  (PORT_PIN_PAD_DEFAULT),/*Pin8*/
   (PORT_PIN_PAD_DEFAULT),/*Pin9*/
   (PORT_PIN_PAD_DEFAULT),/*Pin10*/
   (PORT_PIN_PAD_DEFAULT),/*Pin11*/
   (PORT_PIN_PAD_DEFAULT),/*Pin12*/
   (PORT_PIN_PAD_DEFAULT),/*Pin13*/
   (PORT_PIN_PAD_DEFAULT),/*Pin14*/
   (PORT_PIN_PAD_DEFAULT)/*Pin15*/
                     ),

    {/* Port pin run time mode changeable or not configuration */
      
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 0 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 1 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 2 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 3 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 4 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 5 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 6 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 7 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 8 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 9 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 10 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 11 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 12 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 13 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 14 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE /* Pin 15 */

      
    }

   },
/*                              Port22                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 0*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 1*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 2*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 3*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 4*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 5*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 6*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 7*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 8*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 9*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 10*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 11*/
  (PORT_PIN_DEFAULT),/*Pin 12*/
  (PORT_PIN_DEFAULT),/*Pin 13*/
  (PORT_PIN_DEFAULT),/*Pin 14*/
  (PORT_PIN_DEFAULT)/*Pin 15*/
      
    },
  
    {
      /* Port pins initial level configuration */
      
         PORT_PIN_LEVEL_LOW,/* Pin 0 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 1 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 2 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 3 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 4 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 5 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 6 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 7 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 8 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 9 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 10 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 11 */ 
         0U,/* Pin 12 */ 
         0U,/* Pin 13 */ 
         0U,/* Pin 14 */ 
         0U /* Pin 15 */ 
      
    },
  /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin0*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin1*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin2*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin3*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin4*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin5*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin6*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  /*Pin7*/
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin8*/
     (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin9*/
     (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin10*/
     (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin11*/
   (PORT_PIN_PAD_DEFAULT),/*Pin12*/
   (PORT_PIN_PAD_DEFAULT),/*Pin13*/
   (PORT_PIN_PAD_DEFAULT),/*Pin14*/
   (PORT_PIN_PAD_DEFAULT)/*Pin15*/
                     ),

    {/* Port pin run time mode changeable or not configuration */
      
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 0 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 1 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 2 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 3 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 4 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 5 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 6 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 7 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 8 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 9 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 10 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 11 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 12 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 13 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 14 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE /* Pin 15 */

      
    }

   },
/*                              Port23                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 0*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 1*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 2*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 3*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_OUT | PORT_PIN_OUT_PUSHPULL | PORT_PIN_MODE_GPIO),/*Pin 4*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 5*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 6*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 7*/
  (PORT_PIN_DEFAULT),/*Pin 8*/
  (PORT_PIN_DEFAULT),/*Pin 9*/
  (PORT_PIN_DEFAULT),/*Pin 10*/
  (PORT_PIN_DEFAULT),/*Pin 11*/
  (PORT_PIN_DEFAULT),/*Pin 12*/
  (PORT_PIN_DEFAULT),/*Pin 13*/
  (PORT_PIN_DEFAULT),/*Pin 14*/
  (PORT_PIN_DEFAULT)/*Pin 15*/
      
    },
  
    {
      /* Port pins initial level configuration */
      
         PORT_PIN_LEVEL_LOW,/* Pin 0 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 1 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 2 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 3 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 4 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 5 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 6 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 7 */ 
         0U,/* Pin 8 */ 
         0U,/* Pin 9 */ 
         0U,/* Pin 10 */ 
         0U,/* Pin 11 */ 
         0U,/* Pin 12 */ 
         0U,/* Pin 13 */ 
         0U,/* Pin 14 */ 
         0U /* Pin 15 */ 
      
    },
  /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin0*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin1*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin2*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin3*/
      (PORT_PIN_PAD_LEVEL_DEFAULT|FAST_PORT_PIN_DEFAULT_DRIVER)    ,/*Pin4*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin5*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin6*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  /*Pin7*/
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
  (PORT_PIN_PAD_DEFAULT),/*Pin8*/
   (PORT_PIN_PAD_DEFAULT),/*Pin9*/
   (PORT_PIN_PAD_DEFAULT),/*Pin10*/
   (PORT_PIN_PAD_DEFAULT),/*Pin11*/
   (PORT_PIN_PAD_DEFAULT),/*Pin12*/
   (PORT_PIN_PAD_DEFAULT),/*Pin13*/
   (PORT_PIN_PAD_DEFAULT),/*Pin14*/
   (PORT_PIN_PAD_DEFAULT)/*Pin15*/
                     ),

    {/* Port pin run time mode changeable or not configuration */
      
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 0 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 1 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 2 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 3 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 4 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 5 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 6 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 7 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 8 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 9 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 10 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 11 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 12 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 13 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 14 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE /* Pin 15 */

      
    }

   },
/*                              Port32                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 0*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 1*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 2*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 3*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 4*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 5*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 6*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 7*/
  (PORT_PIN_DEFAULT),/*Pin 8*/
  (PORT_PIN_DEFAULT),/*Pin 9*/
  (PORT_PIN_DEFAULT),/*Pin 10*/
  (PORT_PIN_DEFAULT),/*Pin 11*/
  (PORT_PIN_DEFAULT),/*Pin 12*/
  (PORT_PIN_DEFAULT),/*Pin 13*/
  (PORT_PIN_DEFAULT),/*Pin 14*/
  (PORT_PIN_DEFAULT)/*Pin 15*/
      
    },
  
    {
      /* Port pins initial level configuration */
      
         PORT_PIN_LEVEL_LOW,/* Pin 0 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 1 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 2 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 3 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 4 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 5 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 6 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 7 */ 
         0U,/* Pin 8 */ 
         0U,/* Pin 9 */ 
         0U,/* Pin 10 */ 
         0U,/* Pin 11 */ 
         0U,/* Pin 12 */ 
         0U,/* Pin 13 */ 
         0U,/* Pin 14 */ 
         0U /* Pin 15 */ 
      
    },
  /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin0*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin1*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin2*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin3*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin4*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin5*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin6*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  /*Pin7*/
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
  (PORT_PIN_PAD_DEFAULT),/*Pin8*/
   (PORT_PIN_PAD_DEFAULT),/*Pin9*/
   (PORT_PIN_PAD_DEFAULT),/*Pin10*/
   (PORT_PIN_PAD_DEFAULT),/*Pin11*/
   (PORT_PIN_PAD_DEFAULT),/*Pin12*/
   (PORT_PIN_PAD_DEFAULT),/*Pin13*/
   (PORT_PIN_PAD_DEFAULT),/*Pin14*/
   (PORT_PIN_PAD_DEFAULT)/*Pin15*/
                     ),

    {/* Port pin run time mode changeable or not configuration */
      
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 0 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 1 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 2 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 3 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 4 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 5 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 6 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 7 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 8 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 9 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 10 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 11 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 12 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 13 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 14 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE /* Pin 15 */

      
    }

   },
/*                              Port33                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 0*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 1*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 2*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 3*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 4*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 5*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 6*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 7*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 8*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 9*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 10*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 11*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 12*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 13*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 14*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO)/*Pin 15*/
      
    },
  
    {
      /* Port pins initial level configuration */
      
         PORT_PIN_LEVEL_LOW,/* Pin 0 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 1 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 2 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 3 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 4 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 5 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 6 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 7 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 8 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 9 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 10 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 11 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 12 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 13 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 14 */ 
         PORT_PIN_LEVEL_LOW /* Pin 15 */ 
      
    },
  /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin0*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin1*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin2*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin3*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin4*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin5*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin6*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  /*Pin7*/
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin8*/
     (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin9*/
     (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin10*/
     (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin11*/
     (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin12*/
     (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin13*/
     (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin14*/
     (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  /*Pin15*/
                     ),

    {/* Port pin run time mode changeable or not configuration */
      
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 0 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 1 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 2 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 3 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 4 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 5 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 6 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 7 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 8 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 9 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 10 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 11 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 12 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 13 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 14 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE /* Pin 15 */

      
    }

   },
/*                              Port34                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      
  (PORT_PIN_DEFAULT),/*Pin 0*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 1*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 2*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 3*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 4*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 5*/
  (PORT_PIN_DEFAULT),/*Pin 6*/
  (PORT_PIN_DEFAULT),/*Pin 7*/
  (PORT_PIN_DEFAULT),/*Pin 8*/
  (PORT_PIN_DEFAULT),/*Pin 9*/
  (PORT_PIN_DEFAULT),/*Pin 10*/
  (PORT_PIN_DEFAULT),/*Pin 11*/
  (PORT_PIN_DEFAULT),/*Pin 12*/
  (PORT_PIN_DEFAULT),/*Pin 13*/
  (PORT_PIN_DEFAULT),/*Pin 14*/
  (PORT_PIN_DEFAULT)/*Pin 15*/
      
    },
  
    {
      /* Port pins initial level configuration */
      
         0U,/* Pin 0 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 1 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 2 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 3 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 4 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 5 */ 
         0U,/* Pin 6 */ 
         0U,/* Pin 7 */ 
         0U,/* Pin 8 */ 
         0U,/* Pin 9 */ 
         0U,/* Pin 10 */ 
         0U,/* Pin 11 */ 
         0U,/* Pin 12 */ 
         0U,/* Pin 13 */ 
         0U,/* Pin 14 */ 
         0U /* Pin 15 */ 
      
    },
  /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
  (PORT_PIN_PAD_DEFAULT),/*Pin0*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin1*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin2*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin3*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin4*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin5*/
  (PORT_PIN_PAD_DEFAULT),/*Pin6*/
  (PORT_PIN_PAD_DEFAULT)/*Pin7*/
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
  (PORT_PIN_PAD_DEFAULT),/*Pin8*/
   (PORT_PIN_PAD_DEFAULT),/*Pin9*/
   (PORT_PIN_PAD_DEFAULT),/*Pin10*/
   (PORT_PIN_PAD_DEFAULT),/*Pin11*/
   (PORT_PIN_PAD_DEFAULT),/*Pin12*/
   (PORT_PIN_PAD_DEFAULT),/*Pin13*/
   (PORT_PIN_PAD_DEFAULT),/*Pin14*/
   (PORT_PIN_PAD_DEFAULT)/*Pin15*/
                     ),

    {/* Port pin run time mode changeable or not configuration */
      
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 0 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 1 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 2 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 3 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 4 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 5 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 6 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 7 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 8 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 9 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 10 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 11 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 12 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 13 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 14 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE /* Pin 15 */

      
    }

   },
/*                              Port40                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 0*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 1*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 2*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 3*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 4*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 5*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 6*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 7*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 8*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 9*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 10*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 11*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 12*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 13*/
/* MISRA2012_RULE_10_3_JUSTIFICATION: Union is needed to access data 
per port pin and as a 32 Bit Value*/
  ((uint8)PORT_PIN_IN | PORT_PIN_IN_PULL_UP | PORT_PIN_MODE_GPIO),/*Pin 14*/
  (PORT_PIN_DEFAULT)/*Pin 15*/
      
    },
  
    {
      /* Port pins initial level configuration */
      
         PORT_PIN_LEVEL_LOW,/* Pin 0 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 1 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 2 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 3 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 4 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 5 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 6 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 7 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 8 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 9 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 10 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 11 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 12 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 13 */ 
         PORT_PIN_LEVEL_LOW,/* Pin 14 */ 
         0U /* Pin 15 */ 
      
    },
  /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin0*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin1*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin2*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin3*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin4*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin5*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin6*/
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  /*Pin7*/
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
    (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin8*/
     (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin9*/
     (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin10*/
     (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin11*/
     (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin12*/
     (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin13*/
     (PORT_INPUT_LEVEL_CMOS_AUTOMOTIVE|PORT_PIN_PAD_STRENGTH_DEFAULT)  ,/*Pin14*/
   (PORT_PIN_PAD_DEFAULT)/*Pin15*/
                     ),

    {/* Port pin run time mode changeable or not configuration */
      
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 0 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 1 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 2 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 3 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 4 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 5 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 6 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 7 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 8 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 9 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 10 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 11 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 12 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 13 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE,/* Pin 14 */ 
         PORT_PIN_EMERGENCY_STOP_DISABLE /* Pin 15 */

      
    }

   },
};

static const uint32 Port_DiscSet[] = 
{     
 /*                              Port0                       */
  
  Port_lDiscSet(
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 0 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 1 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 2 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 3 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 4 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 5 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 6 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 7 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 8 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 9 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 10 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 11 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 12 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 13 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 14 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE /* Pin 15 */ 
                ),
 /*                              Port1                       */
  
  Port_lDiscSet(
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 0 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 1 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 2 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 3 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 4 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 5 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 6 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 7 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 8 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 9 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 10 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 11 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 12 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 13 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 14 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE /* Pin 15 */ 
                ),
 /*                              Port2                       */
  
  Port_lDiscSet(
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 0 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 1 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 2 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 3 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 4 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 5 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 6 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 7 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 8 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 9 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 10 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 11 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 12 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 13 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 14 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE /* Pin 15 */ 
                ),
 /*                              Port33                       */
  
  Port_lDiscSet(
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 0 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 1 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 2 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 3 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 4 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 5 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 6 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 7 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 8 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 9 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 10 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 11 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 12 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 13 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 14 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE /* Pin 15 */ 
                ),
 /*                              Port34                       */
  
  Port_lDiscSet(
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 0 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 1 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 2 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 3 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 4 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 5 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 6 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 7 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 8 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 9 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 10 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 11 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 12 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 13 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 14 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE /* Pin 15 */ 
                ),
 /*                              Port40                       */
  
  Port_lDiscSet(
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 0 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 1 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 2 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 3 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 4 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 5 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 6 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 7 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 8 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 9 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 10 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 11 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 12 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 13 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE,/* Pin 14 */ 
                PORT_PIN_ANALOG_INPUT_DISABLE /* Pin 15 */ 
                ),
};

/* LVDS configuration */
static const Port_n_LVDSConfigType Port_kLVDSConfig[] = 
{
  { /*             Port13            */
/*             LPCR0            */


    Port_lLvds(
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PAD_SUPPLY_3_3V,
                  PORT_LVDS_PORT_CONTROLLED,
                  PORT_LVDS_DISABLE,
                  PORT_LVDS_LVDS_VDIFF_ADJ,
                  PORT_LVDS_VOSDYN,
                  PORT_LVDS_VOSEXT,
                  PORT_LVDS_POWER_DOWN,
                  PORT_LVDS_TX_PWDPD_DISABLE
                ),
/*             LPCR1            */


    Port_lLvds(
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PAD_SUPPLY_3_3V,
                  PORT_LVDS_PORT_CONTROLLED,
                  PORT_LVDS_DISABLE,
                  PORT_LVDS_LVDS_VDIFF_ADJ,
                  PORT_LVDS_VOSDYN,
                  PORT_LVDS_VOSEXT,
                  PORT_LVDS_POWER_DOWN,
                  PORT_LVDS_TX_PWDPD_DISABLE
                ),
/*             LPCR2            */


                  PORT_LPCR_DEFAULT,
/*             LPCR3            */


                  PORT_LPCR_DEFAULT,
/*             LPCR4            */


                  PORT_LPCR_DEFAULT,
/*             LPCR5            */


                  PORT_LPCR_DEFAULT,
/*             LPCR6            */


                  PORT_LPCR_DEFAULT
  },  { /*             Port14            */
/*             LPCR0            */


                  PORT_LPCR_DEFAULT,
/*             LPCR1            */


                  PORT_LPCR_DEFAULT,
/*             LPCR2            */


                  PORT_LPCR_DEFAULT,
/*             LPCR3            */


                  PORT_LPCR_DEFAULT,
/*             LPCR4            */


                  PORT_LPCR_DEFAULT,
/*             LPCR5            */


    Port_lLvds(
                  PORT_LVDS_PORT_CONTROLLED,
                  PORT_LVDS_DISABLE,
                  PORT_LVDS_INTERNAL_TERMINATION,
                  PORT_LVDS_POLY_RESISTOR_TERM,
                  PORT_LVDS_LVDSH,
                  PAD_SUPPLY_3_3V,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT
                ),
/*             LPCR6            */


                  PORT_LPCR_DEFAULT
  },  { /*             Port21            */
/*             LPCR0            */


    Port_lLvds(
                  PORT_LVDS_PORT_CONTROLLED,
                  PORT_LVDS_DISABLE,
                  PORT_LVDS_INTERNAL_TERMINATION,
                  PORT_LVDS_POLY_RESISTOR_TERM,
                  PORT_LVDS_LVDSH,
                  PAD_SUPPLY_3_3V,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT
                ),
/*             LPCR1            */


    Port_lLvds(
                  PORT_LVDS_PORT_CONTROLLED,
                  PORT_LVDS_DISABLE,
                  PORT_LVDS_INTERNAL_TERMINATION,
                  PORT_LVDS_POLY_RESISTOR_TERM,
                  PORT_LVDS_LVDSH,
                  PAD_SUPPLY_3_3V,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT
                ),
/*             LPCR2            */


    Port_lLvds(
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PAD_SUPPLY_3_3V,
                  PORT_LVDS_PORT_CONTROLLED,
                  PORT_LVDS_DISABLE,
                  PORT_LVDS_LVDS_VDIFF_ADJ,
                  PORT_LVDS_VOSDYN,
                  PORT_LVDS_VOSEXT,
                  PORT_LVDS_POWER_DOWN,
                  PORT_LVDS_TX_PWDPD_DISABLE
                ),
/*             LPCR3            */


                  PORT_LPCR_DEFAULT,
/*             LPCR4            */


                  PORT_LPCR_DEFAULT,
/*             LPCR5            */


                  PORT_LPCR_DEFAULT,
/*             LPCR6            */


                  PORT_LPCR_DEFAULT
  },  { /*             Port22            */
/*             LPCR0            */


    Port_lLvds(
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PAD_SUPPLY_3_3V,
                  PORT_LVDS_PORT_CONTROLLED,
                  PORT_LVDS_DISABLE,
                  PORT_LVDS_LVDS_VDIFF_ADJ,
                  PORT_LVDS_VOSDYN,
                  PORT_LVDS_VOSEXT,
                  PORT_LVDS_POWER_DOWN,
                  PORT_LVDS_TX_PWDPD_DISABLE
                ),
/*             LPCR1            */


    Port_lLvds(
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PORT_LVDS_DEFAULT,
                  PAD_SUPPLY_3_3V,
                  PORT_LVDS_PORT_CONTROLLED,
                  PORT_LVDS_DISABLE,
                  PORT_LVDS_LVDS_VDIFF_ADJ,
                  PORT_LVDS_VOSDYN,
                  PORT_LVDS_VOSEXT,
                  PORT_LVDS_POWER_DOWN,
                  PORT_LVDS_TX_PWDPD_DISABLE
                ),
/*             LPCR2            */


                  PORT_LPCR_DEFAULT,
/*             LPCR3            */


                  PORT_LPCR_DEFAULT,
/*             LPCR4            */


                  PORT_LPCR_DEFAULT,
/*             LPCR5            */


                  PORT_LPCR_DEFAULT,
/*             LPCR6            */


                  PORT_LPCR_DEFAULT
  }};

/* PCSR configuration */
static const Port_n_PCSRConfigType Port_kPCSRConfig[] = 
{

               /*           Port0            */
   Port_lPcsr(
               PORT_PCSR_DEFAULT,  /*Pin0*/
               PORT_PCSR_DEFAULT,  /*Pin1*/
               PORT_PCSR_DEFAULT,  /*Pin2*/
               PORT_PCSR_DEFAULT,  /*Pin3*/
               PORT_PCSR_DEFAULT,  /*Pin4*/
               PORT_PCSR_DEFAULT,  /*Pin5*/
               PORT_PCSR_DEFAULT,  /*Pin6*/
               PORT_PCSR_DEFAULT,  /*Pin7*/
               PORT_PCSR_DEFAULT,  /*Pin8*/
               PORT_PCSR_DEFAULT,  /*Pin9*/
               PORT_PCSR_DISABLE,  /*Pin10*/
               PORT_PCSR_DISABLE,  /*Pin11*/
               PORT_PCSR_DEFAULT,  /*Pin12*/
               PORT_PCSR_DEFAULT,  /*Pin13*/
               PORT_PCSR_DEFAULT,  /*Pin14*/
               PORT_PCSR_DEFAULT   /*Pin15*/
              ),

               /*           Port11            */
   Port_lPcsr(
               PORT_PCSR_DISABLE,  /*Pin0*/
               PORT_PCSR_DISABLE,  /*Pin1*/
               PORT_PCSR_DISABLE,  /*Pin2*/
               PORT_PCSR_DISABLE,  /*Pin3*/
               PORT_PCSR_DISABLE,  /*Pin4*/
               PORT_PCSR_DEFAULT,  /*Pin5*/
               PORT_PCSR_DISABLE,  /*Pin6*/
               PORT_PCSR_DEFAULT,  /*Pin7*/
               PORT_PCSR_DEFAULT,  /*Pin8*/
               PORT_PCSR_DEFAULT,  /*Pin9*/
               PORT_PCSR_DEFAULT,  /*Pin10*/
               PORT_PCSR_DEFAULT,  /*Pin11*/
               PORT_PCSR_DEFAULT,  /*Pin12*/
               PORT_PCSR_DEFAULT,  /*Pin13*/
               PORT_PCSR_DEFAULT,  /*Pin14*/
               PORT_PCSR_DEFAULT   /*Pin15*/
              ),

               /*           Port33            */
   Port_lPcsr(
               PORT_PCSR_DISABLE,  /*Pin0*/
               PORT_PCSR_DISABLE,  /*Pin1*/
               PORT_PCSR_DISABLE,  /*Pin2*/
               PORT_PCSR_DISABLE,  /*Pin3*/
               PORT_PCSR_DISABLE,  /*Pin4*/
               PORT_PCSR_DISABLE,  /*Pin5*/
               PORT_PCSR_DISABLE,  /*Pin6*/
               PORT_PCSR_DISABLE,  /*Pin7*/
               PORT_PCSR_DISABLE,  /*Pin8*/
               PORT_PCSR_DISABLE,  /*Pin9*/
               PORT_PCSR_DISABLE,  /*Pin10*/
               PORT_PCSR_DISABLE,  /*Pin11*/
               PORT_PCSR_DISABLE,  /*Pin12*/
               PORT_PCSR_DISABLE,  /*Pin13*/
               PORT_PCSR_DISABLE,  /*Pin14*/
               PORT_PCSR_DISABLE   /*Pin15*/
              ),

               /*           Port34            */
   Port_lPcsr(
               PORT_PCSR_DEFAULT,  /*Pin0*/
               PORT_PCSR_DISABLE,  /*Pin1*/
               PORT_PCSR_DEFAULT,  /*Pin2*/
               PORT_PCSR_DEFAULT,  /*Pin3*/
               PORT_PCSR_DEFAULT,  /*Pin4*/
               PORT_PCSR_DEFAULT,  /*Pin5*/
               PORT_PCSR_DEFAULT,  /*Pin6*/
               PORT_PCSR_DEFAULT,  /*Pin7*/
               PORT_PCSR_DEFAULT,  /*Pin8*/
               PORT_PCSR_DEFAULT,  /*Pin9*/
               PORT_PCSR_DEFAULT,  /*Pin10*/
               PORT_PCSR_DEFAULT,  /*Pin11*/
               PORT_PCSR_DEFAULT,  /*Pin12*/
               PORT_PCSR_DEFAULT,  /*Pin13*/
               PORT_PCSR_DEFAULT,  /*Pin14*/
               PORT_PCSR_DEFAULT   /*Pin15*/
              ),

               /*           Port40            */
   Port_lPcsr(
               PORT_PCSR_DEFAULT,  /*Pin0*/
               PORT_PCSR_DISABLE,  /*Pin1*/
               PORT_PCSR_DISABLE,  /*Pin2*/
               PORT_PCSR_DISABLE,  /*Pin3*/
               PORT_PCSR_DEFAULT,  /*Pin4*/
               PORT_PCSR_DISABLE,  /*Pin5*/
               PORT_PCSR_DEFAULT,  /*Pin6*/
               PORT_PCSR_DEFAULT,  /*Pin7*/
               PORT_PCSR_DEFAULT,  /*Pin8*/
               PORT_PCSR_DEFAULT,  /*Pin9*/
               PORT_PCSR_DISABLE,  /*Pin10*/
               PORT_PCSR_DISABLE,  /*Pin11*/
               PORT_PCSR_DISABLE,  /*Pin12*/
               PORT_PCSR_DEFAULT,  /*Pin13*/
               PORT_PCSR_DEFAULT,  /*Pin14*/
               PORT_PCSR_DEFAULT   /*Pin15*/
              )
};




/* MISRA2012_RULE_8_7_JUSTIFICATION: Module configuration data structure
   declaration as per Autosar guidelines. This data structure may be needed
   by SW units using Port Driver APIs */
/* MISRA2012_RULE_8_4_JUSTIFICATION: Definition is as per Autosar guidelines */


const Port_ConfigType Port_Config = 
{


    /* Port Configuration set  */
    &Port_kConfiguration[0],
    /* Port 40-th Disc configuration set  */
    &Port_DiscSet[0],

    /* LVDS configuration */
    &Port_kLVDSConfig[0],
    /* PCSR Configuration */
    &Port_kPCSRConfig[0]
  
};


#define PORT_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: To be compliant with autosar guidelines 
Port_Memmap.h header is included without safegaurd.*/
/* MISRA2012_RULE_20_1_JUSTIFICATION: Port_Memmap.h header included as per Autosar 
   guidelines. */
#include "Port_MemMap.h"


/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/


