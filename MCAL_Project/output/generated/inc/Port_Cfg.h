
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
**  FILENAME  : Port_Cfg.h                                                    **
**                                                                            **
**  VERSION   : 4.0.0                                                         **
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

#ifndef PORT_CFG_H
#define PORT_CFG_H



/* AUTOSAR specification version numbers */
#define PORT_AR_RELEASE_MAJOR_VERSION  (4U)
#define PORT_AR_RELEASE_MINOR_VERSION  (2U)
#define PORT_AR_RELEASE_REVISION_VERSION (2U)


/* Vendor specific implementation version information */
#define PORT_SW_MAJOR_VERSION  (3U)
#define PORT_SW_MINOR_VERSION  (0U)
#define PORT_SW_PATCH_VERSION  (0U)

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/


/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*
                     Container : PortGeneralConfiguration
*/
/*
Configuration: PORT_DEV_ERROR_DETECT
- if STD_ON, DET is Enabled 
- if STD_OFF, DET is Disabled 
*/
#define PORT_DEV_ERROR_DETECT       (STD_OFF)

/*
Configuration: PORT_VERSION_INFO_API 
- if STD_ON,  Function Port_GetVersionInfo is available  
- if STD_OFF, Function Port_GetVersionInfo is not available 
*/
#define PORT_VERSION_INFO_API       (STD_OFF)


/*
Configuration: PORT_SET_PIN_MODE_API 
- if STD_ON,  Function Port_SetPinMode is available  
- if STD_OFF, Function Port_SetPinMode is not available 
*/
/*[cover parentID={0552C05C-931B-4cb3-A833-7F8AA492DE1C}][/cover]*/ 
#define PORT_SET_PIN_MODE_API       (STD_OFF)

/*
Configuration: PORT_SET_PIN_DIRECTION_API
- if STD_ON,  Function Port_SetPinDirection is available  
- if STD_OFF, Function Port_SetPinDirection is not available 
*/
/*[cover parentID={7BC3B15F-4AE7-4635-AF9C-600CF7D3AA5E}][/cover]*/ 
#define PORT_SET_PIN_DIRECTION_API  (STD_OFF)

/*
Configuration: PORT_INIT_API_MODE:
-User Mode Macro for Init API
*/
#define PORT_INIT_API_MODE                                    (PORT_MCAL_SUPERVISOR)

/*
Configuration: PortSafetyEnable  
- if STD_ON, Safety is Enabled 
- if STD_OFF, Safety  is Disabled 
*/
#define PORT_SAFETY_ENABLE    (STD_OFF)


/*
Configuration: PortInitCheckApi  
- if STD_ON, PortInitCheckApi is available 
- if STD_OFF, PortInitCheckApi is not available 
*/
#define PORT_INIT_CHECK_API    (STD_OFF)

                                              
/* Definition to specify the ports available on the microcontroller
   Bit value = 0 implies the port is not available
   Bit value = 1 implies the port is available
   Bit 0 is for Port 0, Bit 1 is for Port 1, ... , Bit 31 is for Port 31 
*/
#define PORTS_AVAILABLE_00_31       (0x00f0fc07U)

/* Definition to specify the ports available on the microcontroller
   Bit value = 0 implies the port is not available
   Bit value = 1 implies the port is available
   Bit 0 is for Port 32, Bit 1 is for Port 33, ... , Bit 8 is for Port 40 
*/
#define PORTS_AVAILABLE_32_63       (0x00000107U)

/* Definition to specify the ports that are read only ports on the
   microcontroller
   Bit value = 0 implies the port readable/writable
   Bit value = 1 implies the port is read only port
   Bit 0 is for Port 0, Bit 1 is for Port 1, ... , Bit 31 is for Port 31 
*/
#define PORTS_READONLY_00_31       (0x00000000U)

/* Definition to specify the ports that are read only ports on the
   microcontroller
   Bit value = 0 implies the port readable/writable
   Bit value = 1 implies the port is read only port
   Bit 0 is for Port 32, Bit 1 is for Port 33, ... , Bit 8 is for Port 40 
*/
#define PORTS_READONLY_32_63       (0x00000100U)

/* Maximum Port Number(Hex) */
#define PORT_MAX_NUMBER             (40U)

/* Maximum PortPinID */
#define PORT_MAX_PIN_ID             (0x28fU)

/* Max Port Number available */
#define PORT_TOTAL_AVAILABLE_PORTS   (16U)

/* Max LPCR Register available */
#define PORT_MAX_LPCR_REG           (7U)

/*Macro that defines the derivate for errata PORTS_TC.H012 */


#define PORT14_PDISC_MASK             (0U)


/* Definition to specify the ports that are LVDS ports on the
   microcontroller
   Bit value = 0 implies the port supports LVDS
   Bit value = 1 implies the port does not support LVDS
   Bit 0 is for Port 0, Bit 1 is for Port 1, ... , Bit 31 is for Port 31
*/
#define PORTS_LVDS_00_31       (0x00606000U)

/* Definition to specify the ports that are LVDS ports on the
   microcontroller
   Bit value = 0 implies the port supports LVDS
   Bit value = 1 implies the port does not support LVDS
   Bit 0 is for Port 32, Bit 1 is for Port 33, ... , Bit 8 is for Port 40 
*/
#define PORTS_LVDS_32_63       (0x00000000U)

/* Definition to specify the ports that support PCSR on the
   microcontroller
   Bit value = 0 implies the port supports PCSR
   Bit value = 1 implies the port does not support PCSR
   Bit 0 is for Port 0, Bit 1 is for Port 1, ... , Bit 31 is for Port 31
*/
#define PORTS_PCSR_00_31       (0x00000801U)

/* Definition to specify the ports that PCSR on the
   microcontroller
   Bit value = 0 implies the port supports PCSR
   Bit value = 1 implies the port does not support PCSR
   Bit 0 is for Port 32, Bit 1 is for Port 33, ... , Bit 8 is for Port 40 
*/
#define PORTS_PCSR_32_63       (0x00000106U)

/* Definitions to specify the pins available in the port 
   Bit value = 0 implies the pin is not available
   Bit value = 1 implies the pin is available
   Bit 0 is for Pin 0, Bit 1 is for Pin 1, ... , Bit 15 is for Pin 15
*/
#define PORT_AVAILABLE_PINS_PORT0        (0x1fffU)
#define PORT_AVAILABLE_PINS_PORT1        (0x00f8U)
#define PORT_AVAILABLE_PINS_PORT2        (0x0fffU)
#define PORT_AVAILABLE_PINS_PORT3        (0x0000U)
#define PORT_AVAILABLE_PINS_PORT4        (0x0000U)
#define PORT_AVAILABLE_PINS_PORT5        (0x0000U)
#define PORT_AVAILABLE_PINS_PORT6        (0x0000U)
#define PORT_AVAILABLE_PINS_PORT7        (0x0000U)
#define PORT_AVAILABLE_PINS_PORT8        (0x0000U)
#define PORT_AVAILABLE_PINS_PORT9        (0x0000U)
#define PORT_AVAILABLE_PINS_PORT10        (0x01ffU)
#define PORT_AVAILABLE_PINS_PORT11        (0xffffU)
#define PORT_AVAILABLE_PINS_PORT12        (0x0003U)
#define PORT_AVAILABLE_PINS_PORT13        (0x000fU)
#define PORT_AVAILABLE_PINS_PORT14        (0x07ffU)
#define PORT_AVAILABLE_PINS_PORT15        (0x01ffU)
#define PORT_AVAILABLE_PINS_PORT16        (0x0000U)
#define PORT_AVAILABLE_PINS_PORT17        (0x0000U)
#define PORT_AVAILABLE_PINS_PORT18        (0x0000U)
#define PORT_AVAILABLE_PINS_PORT19        (0x0000U)
#define PORT_AVAILABLE_PINS_PORT20        (0x7fcfU)
#define PORT_AVAILABLE_PINS_PORT21        (0x00ffU)
#define PORT_AVAILABLE_PINS_PORT22        (0x0fffU)
#define PORT_AVAILABLE_PINS_PORT23        (0x00ffU)
#define PORT_AVAILABLE_PINS_PORT24        (0x0000U)
#define PORT_AVAILABLE_PINS_PORT25        (0x0000U)
#define PORT_AVAILABLE_PINS_PORT26        (0x0000U)
#define PORT_AVAILABLE_PINS_PORT27        (0x0000U)
#define PORT_AVAILABLE_PINS_PORT28        (0x0000U)
#define PORT_AVAILABLE_PINS_PORT29        (0x0000U)
#define PORT_AVAILABLE_PINS_PORT30        (0x0000U)
#define PORT_AVAILABLE_PINS_PORT31        (0x0000U)
#define PORT_AVAILABLE_PINS_PORT32        (0x00ffU)
#define PORT_AVAILABLE_PINS_PORT33        (0xffffU)
#define PORT_AVAILABLE_PINS_PORT34        (0x003eU)
#define PORT_AVAILABLE_PINS_PORT35        (0x0000U)
#define PORT_AVAILABLE_PINS_PORT36        (0x0000U)
#define PORT_AVAILABLE_PINS_PORT37        (0x0000U)
#define PORT_AVAILABLE_PINS_PORT38        (0x0000U)
#define PORT_AVAILABLE_PINS_PORT39        (0x0000U)
#define PORT_AVAILABLE_PINS_PORT40        (0x7fffU)
#define PORT_AVAILABLE_PINS_PORT41        (0x0000U)

/* Definition to specify the ports that support PDISC on the
   microcontroller
   Bit value = 0 implies the port supports PDISC
   Bit value = 1 implies the port does not support PDISC
   Bit 0 is for Port 0, Bit 1 is for Port 1, ... , Bit 31 is for Port 31
*/
#define PORTS_PDISC_00_31       (0x00000007U)

/* Definition to specify the ports that PDISC on the
   microcontroller
   Bit value = 0 implies the port supports PDISC
   Bit value = 1 implies the port does not support PDISC
   Bit 0 is for Port 32, Bit 1 is for Port 33, ... , Bit 8 is for Port 40 
*/
#define PORTS_PDISC_32_63       (0x00000106U)
/********************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/* 
  User Defined Symbolic names of all port pins Port_ConfigSet
*/

                   
/*   
   Port0   
*/ 
  
/* Symbolic Name: PORT_0_PIN_0 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_0_PORT_0_PIN_0 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_0_PORT_0_PIN_0  (Port_PinType )(0x0000U)
#endif
/* Symbolic Name: PORT_0_PIN_1 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_0_PORT_0_PIN_1 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_0_PORT_0_PIN_1  (Port_PinType )(0x0001U)
#endif
/* Symbolic Name: PORT_0_PIN_2 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_0_PORT_0_PIN_2 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_0_PORT_0_PIN_2  (Port_PinType )(0x0002U)
#endif
/* Symbolic Name: PORT_0_PIN_3 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_0_PORT_0_PIN_3 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_0_PORT_0_PIN_3  (Port_PinType )(0x0003U)
#endif
/* Symbolic Name: PORT_0_PIN_4 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_0_PORT_0_PIN_4 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_0_PORT_0_PIN_4  (Port_PinType )(0x0004U)
#endif
/* Symbolic Name: PORT_0_PIN_5 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_0_PORT_0_PIN_5 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_0_PORT_0_PIN_5  (Port_PinType )(0x0005U)
#endif
/* Symbolic Name: PORT_0_PIN_6 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_0_PORT_0_PIN_6 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_0_PORT_0_PIN_6  (Port_PinType )(0x0006U)
#endif
/* Symbolic Name: PORT_0_PIN_7 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_0_PORT_0_PIN_7 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_0_PORT_0_PIN_7  (Port_PinType )(0x0007U)
#endif
/* Symbolic Name: PORT_0_PIN_8 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_0_PORT_0_PIN_8 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_0_PORT_0_PIN_8  (Port_PinType )(0x0008U)
#endif
/* Symbolic Name: PORT_0_PIN_9 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_0_PORT_0_PIN_9 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_0_PORT_0_PIN_9  (Port_PinType )(0x0009U)
#endif
/* Symbolic Name: PORT_0_PIN_10 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_0_PORT_0_PIN_10 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_0_PORT_0_PIN_10  (Port_PinType )(0x000aU)
#endif
/* Symbolic Name: PORT_0_PIN_11 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_0_PORT_0_PIN_11 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_0_PORT_0_PIN_11  (Port_PinType )(0x000bU)
#endif
/* Symbolic Name: PORT_0_PIN_12 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_0_PORT_0_PIN_12 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_0_PORT_0_PIN_12  (Port_PinType )(0x000cU)
#endif

                   
/*   
   Port1   
*/ 
  
/* Symbolic Name: PORT_1_PIN_3 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_1_PORT_1_PIN_3 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_1_PORT_1_PIN_3  (Port_PinType )(0x0013U)
#endif
/* Symbolic Name: PORT_1_PIN_4 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_1_PORT_1_PIN_4 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_1_PORT_1_PIN_4  (Port_PinType )(0x0014U)
#endif
/* Symbolic Name: PORT_1_PIN_5 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_1_PORT_1_PIN_5 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_1_PORT_1_PIN_5  (Port_PinType )(0x0015U)
#endif
/* Symbolic Name: PORT_1_PIN_6 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_1_PORT_1_PIN_6 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_1_PORT_1_PIN_6  (Port_PinType )(0x0016U)
#endif
/* Symbolic Name: PORT_1_PIN_7 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_1_PORT_1_PIN_7 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_1_PORT_1_PIN_7  (Port_PinType )(0x0017U)
#endif

                   
/*   
   Port2   
*/ 
  
/* Symbolic Name: PORT_2_PIN_0 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_2_PORT_2_PIN_0 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_2_PORT_2_PIN_0  (Port_PinType )(0x0020U)
#endif
/* Symbolic Name: PORT_2_PIN_1 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_2_PORT_2_PIN_1 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_2_PORT_2_PIN_1  (Port_PinType )(0x0021U)
#endif
/* Symbolic Name: PORT_2_PIN_2 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_2_PORT_2_PIN_2 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_2_PORT_2_PIN_2  (Port_PinType )(0x0022U)
#endif
/* Symbolic Name: PORT_2_PIN_3 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_2_PORT_2_PIN_3 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_2_PORT_2_PIN_3  (Port_PinType )(0x0023U)
#endif
/* Symbolic Name: PORT_2_PIN_4 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_2_PORT_2_PIN_4 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_2_PORT_2_PIN_4  (Port_PinType )(0x0024U)
#endif
/* Symbolic Name: PORT_2_PIN_5 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_2_PORT_2_PIN_5 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_2_PORT_2_PIN_5  (Port_PinType )(0x0025U)
#endif
/* Symbolic Name: PORT_2_PIN_6 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_2_PORT_2_PIN_6 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_2_PORT_2_PIN_6  (Port_PinType )(0x0026U)
#endif
/* Symbolic Name: PORT_2_PIN_7 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_2_PORT_2_PIN_7 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_2_PORT_2_PIN_7  (Port_PinType )(0x0027U)
#endif
/* Symbolic Name: PORT_2_PIN_8 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_2_PORT_2_PIN_8 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_2_PORT_2_PIN_8  (Port_PinType )(0x0028U)
#endif
/* Symbolic Name: PORT_2_PIN_9 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_2_PORT_2_PIN_9 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_2_PORT_2_PIN_9  (Port_PinType )(0x0029U)
#endif
/* Symbolic Name: PORT_2_PIN_10 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_2_PORT_2_PIN_10 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_2_PORT_2_PIN_10  (Port_PinType )(0x002aU)
#endif
/* Symbolic Name: PORT_2_PIN_11 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_2_PORT_2_PIN_11 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_2_PORT_2_PIN_11  (Port_PinType )(0x002bU)
#endif








                   
/*   
   Port10   
*/ 
  
/* Symbolic Name: PORT_10_PIN_0 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_3_PORT_10_PIN_0 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_3_PORT_10_PIN_0  (Port_PinType )(0x00a0U)
#endif
/* Symbolic Name: PORT_10_PIN_1 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_3_PORT_10_PIN_1 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_3_PORT_10_PIN_1  (Port_PinType )(0x00a1U)
#endif
/* Symbolic Name: PORT_10_PIN_2 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_3_PORT_10_PIN_2 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_3_PORT_10_PIN_2  (Port_PinType )(0x00a2U)
#endif
/* Symbolic Name: PORT_10_PIN_3 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_3_PORT_10_PIN_3 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_3_PORT_10_PIN_3  (Port_PinType )(0x00a3U)
#endif
/* Symbolic Name: PORT_10_PIN_4 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_3_PORT_10_PIN_4 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_3_PORT_10_PIN_4  (Port_PinType )(0x00a4U)
#endif
/* Symbolic Name: PORT_10_PIN_5 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_3_PORT_10_PIN_5 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_3_PORT_10_PIN_5  (Port_PinType )(0x00a5U)
#endif
/* Symbolic Name: PORT_10_PIN_6 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_3_PORT_10_PIN_6 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_3_PORT_10_PIN_6  (Port_PinType )(0x00a6U)
#endif
/* Symbolic Name: PORT_10_PIN_7 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_3_PORT_10_PIN_7 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_3_PORT_10_PIN_7  (Port_PinType )(0x00a7U)
#endif
/* Symbolic Name: PORT_10_PIN_8 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_3_PORT_10_PIN_8 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_3_PORT_10_PIN_8  (Port_PinType )(0x00a8U)
#endif

                   
/*   
   Port11   
*/ 
  
/* Symbolic Name: PORT_11_PIN_0 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_4_PORT_11_PIN_0 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_4_PORT_11_PIN_0  (Port_PinType )(0x00b0U)
#endif
/* Symbolic Name: PORT_11_PIN_1 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_4_PORT_11_PIN_1 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_4_PORT_11_PIN_1  (Port_PinType )(0x00b1U)
#endif
/* Symbolic Name: PORT_11_PIN_2 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_4_PORT_11_PIN_2 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_4_PORT_11_PIN_2  (Port_PinType )(0x00b2U)
#endif
/* Symbolic Name: PORT_11_PIN_3 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_4_PORT_11_PIN_3 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_4_PORT_11_PIN_3  (Port_PinType )(0x00b3U)
#endif
/* Symbolic Name: PORT_11_PIN_4 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_4_PORT_11_PIN_4 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_4_PORT_11_PIN_4  (Port_PinType )(0x00b4U)
#endif
/* Symbolic Name: PORT_11_PIN_5 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_4_PORT_11_PIN_5 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_4_PORT_11_PIN_5  (Port_PinType )(0x00b5U)
#endif
/* Symbolic Name: PORT_11_PIN_6 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_4_PORT_11_PIN_6 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_4_PORT_11_PIN_6  (Port_PinType )(0x00b6U)
#endif
/* Symbolic Name: PORT_11_PIN_7 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_4_PORT_11_PIN_7 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_4_PORT_11_PIN_7  (Port_PinType )(0x00b7U)
#endif
/* Symbolic Name: PORT_11_PIN_8 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_4_PORT_11_PIN_8 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_4_PORT_11_PIN_8  (Port_PinType )(0x00b8U)
#endif
/* Symbolic Name: PORT_11_PIN_9 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_4_PORT_11_PIN_9 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_4_PORT_11_PIN_9  (Port_PinType )(0x00b9U)
#endif
/* Symbolic Name: PORT_11_PIN_10 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_4_PORT_11_PIN_10 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_4_PORT_11_PIN_10  (Port_PinType )(0x00baU)
#endif
/* Symbolic Name: PORT_11_PIN_11 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_4_PORT_11_PIN_11 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_4_PORT_11_PIN_11  (Port_PinType )(0x00bbU)
#endif
/* Symbolic Name: PORT_11_PIN_12 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_4_PORT_11_PIN_12 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_4_PORT_11_PIN_12  (Port_PinType )(0x00bcU)
#endif
/* Symbolic Name: PORT_11_PIN_13 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_4_PORT_11_PIN_13 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_4_PORT_11_PIN_13  (Port_PinType )(0x00bdU)
#endif
/* Symbolic Name: PORT_11_PIN_14 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_4_PORT_11_PIN_14 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_4_PORT_11_PIN_14  (Port_PinType )(0x00beU)
#endif
/* Symbolic Name: PORT_11_PIN_15 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_4_PORT_11_PIN_15 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_4_PORT_11_PIN_15  (Port_PinType )(0x00bfU)
#endif

                   
/*   
   Port12   
*/ 
  
/* Symbolic Name: PORT_12_PIN_0 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_5_PORT_12_PIN_0 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_5_PORT_12_PIN_0  (Port_PinType )(0x00c0U)
#endif
/* Symbolic Name: PORT_12_PIN_1 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_5_PORT_12_PIN_1 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_5_PORT_12_PIN_1  (Port_PinType )(0x00c1U)
#endif

                   
/*   
   Port13   
*/ 
  
/* Symbolic Name: PORT_13_PIN_0 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_6_PORT_13_PIN_0 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_6_PORT_13_PIN_0  (Port_PinType )(0x00d0U)
#endif
/* Symbolic Name: PORT_13_PIN_1 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_6_PORT_13_PIN_1 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_6_PORT_13_PIN_1  (Port_PinType )(0x00d1U)
#endif
/* Symbolic Name: PORT_13_PIN_2 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_6_PORT_13_PIN_2 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_6_PORT_13_PIN_2  (Port_PinType )(0x00d2U)
#endif
/* Symbolic Name: PORT_13_PIN_3 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_6_PORT_13_PIN_3 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_6_PORT_13_PIN_3  (Port_PinType )(0x00d3U)
#endif

                   
/*   
   Port14   
*/ 
  
/* Symbolic Name: PORT_14_PIN_0 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_7_PORT_14_PIN_0 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_7_PORT_14_PIN_0  (Port_PinType )(0x00e0U)
#endif
/* Symbolic Name: PORT_14_PIN_1 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_7_PORT_14_PIN_1 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_7_PORT_14_PIN_1  (Port_PinType )(0x00e1U)
#endif
/* Symbolic Name: PORT_14_PIN_2 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_7_PORT_14_PIN_2 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_7_PORT_14_PIN_2  (Port_PinType )(0x00e2U)
#endif
/* Symbolic Name: PORT_14_PIN_3 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_7_PORT_14_PIN_3 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_7_PORT_14_PIN_3  (Port_PinType )(0x00e3U)
#endif
/* Symbolic Name: PORT_14_PIN_4 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_7_PORT_14_PIN_4 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_7_PORT_14_PIN_4  (Port_PinType )(0x00e4U)
#endif
/* Symbolic Name: PORT_14_PIN_5 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_7_PORT_14_PIN_5 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_7_PORT_14_PIN_5  (Port_PinType )(0x00e5U)
#endif
/* Symbolic Name: PORT_14_PIN_6 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_7_PORT_14_PIN_6 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_7_PORT_14_PIN_6  (Port_PinType )(0x00e6U)
#endif
/* Symbolic Name: PORT_14_PIN_7 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_7_PORT_14_PIN_7 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_7_PORT_14_PIN_7  (Port_PinType )(0x00e7U)
#endif
/* Symbolic Name: PORT_14_PIN_8 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_7_PORT_14_PIN_8 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_7_PORT_14_PIN_8  (Port_PinType )(0x00e8U)
#endif
/* Symbolic Name: PORT_14_PIN_9 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_7_PORT_14_PIN_9 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_7_PORT_14_PIN_9  (Port_PinType )(0x00e9U)
#endif
/* Symbolic Name: PORT_14_PIN_10 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_7_PORT_14_PIN_10 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_7_PORT_14_PIN_10  (Port_PinType )(0x00eaU)
#endif

                   
/*   
   Port15   
*/ 
  
/* Symbolic Name: PORT_15_PIN_0 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_8_PORT_15_PIN_0 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_8_PORT_15_PIN_0  (Port_PinType )(0x00f0U)
#endif
/* Symbolic Name: PORT_15_PIN_1 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_8_PORT_15_PIN_1 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_8_PORT_15_PIN_1  (Port_PinType )(0x00f1U)
#endif
/* Symbolic Name: PORT_15_PIN_2 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_8_PORT_15_PIN_2 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_8_PORT_15_PIN_2  (Port_PinType )(0x00f2U)
#endif
/* Symbolic Name: PORT_15_PIN_3 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_8_PORT_15_PIN_3 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_8_PORT_15_PIN_3  (Port_PinType )(0x00f3U)
#endif
/* Symbolic Name: PORT_15_PIN_4 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_8_PORT_15_PIN_4 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_8_PORT_15_PIN_4  (Port_PinType )(0x00f4U)
#endif
/* Symbolic Name: PORT_15_PIN_5 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_8_PORT_15_PIN_5 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_8_PORT_15_PIN_5  (Port_PinType )(0x00f5U)
#endif
/* Symbolic Name: PORT_15_PIN_6 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_8_PORT_15_PIN_6 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_8_PORT_15_PIN_6  (Port_PinType )(0x00f6U)
#endif
/* Symbolic Name: PORT_15_PIN_7 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_8_PORT_15_PIN_7 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_8_PORT_15_PIN_7  (Port_PinType )(0x00f7U)
#endif
/* Symbolic Name: PORT_15_PIN_8 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_8_PORT_15_PIN_8 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_8_PORT_15_PIN_8  (Port_PinType )(0x00f8U)
#endif





                   
/*   
   Port20   
*/ 
  
/* Symbolic Name: PORT_20_PIN_0 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_9_PORT_20_PIN_0 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_9_PORT_20_PIN_0  (Port_PinType )(0x0140U)
#endif
/* Symbolic Name: PORT_20_PIN_1 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_9_PORT_20_PIN_1 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_9_PORT_20_PIN_1  (Port_PinType )(0x0141U)
#endif
/* Symbolic Name: PORT_20_PIN_2 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_9_PORT_20_PIN_2 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_9_PORT_20_PIN_2  (Port_PinType )(0x0142U)
#endif
/* Symbolic Name: PORT_20_PIN_3 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_9_PORT_20_PIN_3 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_9_PORT_20_PIN_3  (Port_PinType )(0x0143U)
#endif
/* Symbolic Name: PORT_20_PIN_6 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_9_PORT_20_PIN_6 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_9_PORT_20_PIN_6  (Port_PinType )(0x0146U)
#endif
/* Symbolic Name: PORT_20_PIN_7 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_9_PORT_20_PIN_7 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_9_PORT_20_PIN_7  (Port_PinType )(0x0147U)
#endif
/* Symbolic Name: PORT_20_PIN_8 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_9_PORT_20_PIN_8 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_9_PORT_20_PIN_8  (Port_PinType )(0x0148U)
#endif
/* Symbolic Name: PORT_20_PIN_9 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_9_PORT_20_PIN_9 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_9_PORT_20_PIN_9  (Port_PinType )(0x0149U)
#endif
/* Symbolic Name: PORT_20_PIN_10 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_9_PORT_20_PIN_10 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_9_PORT_20_PIN_10  (Port_PinType )(0x014aU)
#endif
/* Symbolic Name: PORT_20_PIN_11 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_9_PORT_20_PIN_11 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_9_PORT_20_PIN_11  (Port_PinType )(0x014bU)
#endif
/* Symbolic Name: PORT_20_PIN_12 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_9_PORT_20_PIN_12 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_9_PORT_20_PIN_12  (Port_PinType )(0x014cU)
#endif
/* Symbolic Name: PORT_20_PIN_13 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_9_PORT_20_PIN_13 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_9_PORT_20_PIN_13  (Port_PinType )(0x014dU)
#endif
/* Symbolic Name: PORT_20_PIN_14 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_9_PORT_20_PIN_14 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_9_PORT_20_PIN_14  (Port_PinType )(0x014eU)
#endif

                   
/*   
   Port21   
*/ 
  
/* Symbolic Name: PORT_21_PIN_0 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_10_PORT_21_PIN_0 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_10_PORT_21_PIN_0  (Port_PinType )(0x0150U)
#endif
/* Symbolic Name: PORT_21_PIN_1 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_10_PORT_21_PIN_1 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_10_PORT_21_PIN_1  (Port_PinType )(0x0151U)
#endif
/* Symbolic Name: PORT_21_PIN_2 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_10_PORT_21_PIN_2 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_10_PORT_21_PIN_2  (Port_PinType )(0x0152U)
#endif
/* Symbolic Name: PORT_21_PIN_3 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_10_PORT_21_PIN_3 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_10_PORT_21_PIN_3  (Port_PinType )(0x0153U)
#endif
/* Symbolic Name: PORT_21_PIN_4 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_10_PORT_21_PIN_4 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_10_PORT_21_PIN_4  (Port_PinType )(0x0154U)
#endif
/* Symbolic Name: PORT_21_PIN_5 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_10_PORT_21_PIN_5 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_10_PORT_21_PIN_5  (Port_PinType )(0x0155U)
#endif
/* Symbolic Name: PORT_21_PIN_6 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_10_PORT_21_PIN_6 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_10_PORT_21_PIN_6  (Port_PinType )(0x0156U)
#endif
/* Symbolic Name: PORT_21_PIN_7 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_10_PORT_21_PIN_7 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_10_PORT_21_PIN_7  (Port_PinType )(0x0157U)
#endif

                   
/*   
   Port22   
*/ 
  
/* Symbolic Name: PORT_22_PIN_0 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_11_PORT_22_PIN_0 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_11_PORT_22_PIN_0  (Port_PinType )(0x0160U)
#endif
/* Symbolic Name: PORT_22_PIN_1 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_11_PORT_22_PIN_1 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_11_PORT_22_PIN_1  (Port_PinType )(0x0161U)
#endif
/* Symbolic Name: PORT_22_PIN_2 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_11_PORT_22_PIN_2 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_11_PORT_22_PIN_2  (Port_PinType )(0x0162U)
#endif
/* Symbolic Name: PORT_22_PIN_3 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_11_PORT_22_PIN_3 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_11_PORT_22_PIN_3  (Port_PinType )(0x0163U)
#endif
/* Symbolic Name: PORT_22_PIN_4 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_11_PORT_22_PIN_4 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_11_PORT_22_PIN_4  (Port_PinType )(0x0164U)
#endif
/* Symbolic Name: PORT_22_PIN_5 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_11_PORT_22_PIN_5 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_11_PORT_22_PIN_5  (Port_PinType )(0x0165U)
#endif
/* Symbolic Name: PORT_22_PIN_6 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_11_PORT_22_PIN_6 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_11_PORT_22_PIN_6  (Port_PinType )(0x0166U)
#endif
/* Symbolic Name: PORT_22_PIN_7 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_11_PORT_22_PIN_7 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_11_PORT_22_PIN_7  (Port_PinType )(0x0167U)
#endif
/* Symbolic Name: PORT_22_PIN_8 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_11_PORT_22_PIN_8 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_11_PORT_22_PIN_8  (Port_PinType )(0x0168U)
#endif
/* Symbolic Name: PORT_22_PIN_9 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_11_PORT_22_PIN_9 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_11_PORT_22_PIN_9  (Port_PinType )(0x0169U)
#endif
/* Symbolic Name: PORT_22_PIN_10 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_11_PORT_22_PIN_10 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_11_PORT_22_PIN_10  (Port_PinType )(0x016aU)
#endif
/* Symbolic Name: PORT_22_PIN_11 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_11_PORT_22_PIN_11 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_11_PORT_22_PIN_11  (Port_PinType )(0x016bU)
#endif

                   
/*   
   Port23   
*/ 
  
/* Symbolic Name: PORT_23_PIN_0 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_12_PORT_23_PIN_0 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_12_PORT_23_PIN_0  (Port_PinType )(0x0170U)
#endif
/* Symbolic Name: PORT_23_PIN_1 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_12_PORT_23_PIN_1 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_12_PORT_23_PIN_1  (Port_PinType )(0x0171U)
#endif
/* Symbolic Name: PORT_23_PIN_2 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_12_PORT_23_PIN_2 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_12_PORT_23_PIN_2  (Port_PinType )(0x0172U)
#endif
/* Symbolic Name: PORT_23_PIN_3 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_12_PORT_23_PIN_3 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_12_PORT_23_PIN_3  (Port_PinType )(0x0173U)
#endif
/* Symbolic Name: PORT_23_PIN_4 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_12_PORT_23_PIN_4 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_12_PORT_23_PIN_4  (Port_PinType )(0x0174U)
#endif
/* Symbolic Name: PORT_23_PIN_5 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_12_PORT_23_PIN_5 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_12_PORT_23_PIN_5  (Port_PinType )(0x0175U)
#endif
/* Symbolic Name: PORT_23_PIN_6 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_12_PORT_23_PIN_6 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_12_PORT_23_PIN_6  (Port_PinType )(0x0176U)
#endif
/* Symbolic Name: PORT_23_PIN_7 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_12_PORT_23_PIN_7 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_12_PORT_23_PIN_7  (Port_PinType )(0x0177U)
#endif









                   
/*   
   Port32   
*/ 
  
/* Symbolic Name: PORT_32_PIN_0 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_13_PORT_32_PIN_0 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_13_PORT_32_PIN_0  (Port_PinType )(0x0200U)
#endif
/* Symbolic Name: PORT_32_PIN_1 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_13_PORT_32_PIN_1 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_13_PORT_32_PIN_1  (Port_PinType )(0x0201U)
#endif
/* Symbolic Name: PORT_32_PIN_2 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_13_PORT_32_PIN_2 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_13_PORT_32_PIN_2  (Port_PinType )(0x0202U)
#endif
/* Symbolic Name: PORT_32_PIN_3 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_13_PORT_32_PIN_3 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_13_PORT_32_PIN_3  (Port_PinType )(0x0203U)
#endif
/* Symbolic Name: PORT_32_PIN_4 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_13_PORT_32_PIN_4 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_13_PORT_32_PIN_4  (Port_PinType )(0x0204U)
#endif
/* Symbolic Name: PORT_32_PIN_5 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_13_PORT_32_PIN_5 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_13_PORT_32_PIN_5  (Port_PinType )(0x0205U)
#endif
/* Symbolic Name: PORT_32_PIN_6 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_13_PORT_32_PIN_6 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_13_PORT_32_PIN_6  (Port_PinType )(0x0206U)
#endif
/* Symbolic Name: PORT_32_PIN_7 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_13_PORT_32_PIN_7 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_13_PORT_32_PIN_7  (Port_PinType )(0x0207U)
#endif

                   
/*   
   Port33   
*/ 
  
/* Symbolic Name: PORT_33_PIN_0 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_14_PORT_33_PIN_0 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_14_PORT_33_PIN_0  (Port_PinType )(0x0210U)
#endif
/* Symbolic Name: PORT_33_PIN_1 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_14_PORT_33_PIN_1 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_14_PORT_33_PIN_1  (Port_PinType )(0x0211U)
#endif
/* Symbolic Name: PORT_33_PIN_2 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_14_PORT_33_PIN_2 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_14_PORT_33_PIN_2  (Port_PinType )(0x0212U)
#endif
/* Symbolic Name: PORT_33_PIN_3 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_14_PORT_33_PIN_3 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_14_PORT_33_PIN_3  (Port_PinType )(0x0213U)
#endif
/* Symbolic Name: PORT_33_PIN_4 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_14_PORT_33_PIN_4 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_14_PORT_33_PIN_4  (Port_PinType )(0x0214U)
#endif
/* Symbolic Name: PORT_33_PIN_5 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_14_PORT_33_PIN_5 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_14_PORT_33_PIN_5  (Port_PinType )(0x0215U)
#endif
/* Symbolic Name: PORT_33_PIN_6 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_14_PORT_33_PIN_6 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_14_PORT_33_PIN_6  (Port_PinType )(0x0216U)
#endif
/* Symbolic Name: PORT_33_PIN_7 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_14_PORT_33_PIN_7 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_14_PORT_33_PIN_7  (Port_PinType )(0x0217U)
#endif
/* Symbolic Name: PORT_33_PIN_8 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_14_PORT_33_PIN_8 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_14_PORT_33_PIN_8  (Port_PinType )(0x0218U)
#endif
/* Symbolic Name: PORT_33_PIN_9 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_14_PORT_33_PIN_9 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_14_PORT_33_PIN_9  (Port_PinType )(0x0219U)
#endif
/* Symbolic Name: PORT_33_PIN_10 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_14_PORT_33_PIN_10 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_14_PORT_33_PIN_10  (Port_PinType )(0x021aU)
#endif
/* Symbolic Name: PORT_33_PIN_11 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_14_PORT_33_PIN_11 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_14_PORT_33_PIN_11  (Port_PinType )(0x021bU)
#endif
/* Symbolic Name: PORT_33_PIN_12 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_14_PORT_33_PIN_12 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_14_PORT_33_PIN_12  (Port_PinType )(0x021cU)
#endif
/* Symbolic Name: PORT_33_PIN_13 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_14_PORT_33_PIN_13 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_14_PORT_33_PIN_13  (Port_PinType )(0x021dU)
#endif
/* Symbolic Name: PORT_33_PIN_14 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_14_PORT_33_PIN_14 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_14_PORT_33_PIN_14  (Port_PinType )(0x021eU)
#endif
/* Symbolic Name: PORT_33_PIN_15 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_14_PORT_33_PIN_15 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_14_PORT_33_PIN_15  (Port_PinType )(0x021fU)
#endif

                   
/*   
   Port34   
*/ 
  
/* Symbolic Name: PORT_34_PIN_1 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_15_PORT_34_PIN_1 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_15_PORT_34_PIN_1  (Port_PinType )(0x0221U)
#endif
/* Symbolic Name: PORT_34_PIN_2 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_15_PORT_34_PIN_2 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_15_PORT_34_PIN_2  (Port_PinType )(0x0222U)
#endif
/* Symbolic Name: PORT_34_PIN_3 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_15_PORT_34_PIN_3 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_15_PORT_34_PIN_3  (Port_PinType )(0x0223U)
#endif
/* Symbolic Name: PORT_34_PIN_4 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_15_PORT_34_PIN_4 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_15_PORT_34_PIN_4  (Port_PinType )(0x0224U)
#endif
/* Symbolic Name: PORT_34_PIN_5 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_15_PORT_34_PIN_5 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_15_PORT_34_PIN_5  (Port_PinType )(0x0225U)
#endif






                   
/*   
   Port40   
*/ 
  
/* Symbolic Name: PORT_40_PIN_0 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_16_PORT_40_PIN_0 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_16_PORT_40_PIN_0  (Port_PinType )(0x0280U)
#endif
/* Symbolic Name: PORT_40_PIN_1 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_16_PORT_40_PIN_1 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_16_PORT_40_PIN_1  (Port_PinType )(0x0281U)
#endif
/* Symbolic Name: PORT_40_PIN_2 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_16_PORT_40_PIN_2 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_16_PORT_40_PIN_2  (Port_PinType )(0x0282U)
#endif
/* Symbolic Name: PORT_40_PIN_3 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_16_PORT_40_PIN_3 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_16_PORT_40_PIN_3  (Port_PinType )(0x0283U)
#endif
/* Symbolic Name: PORT_40_PIN_4 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_16_PORT_40_PIN_4 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_16_PORT_40_PIN_4  (Port_PinType )(0x0284U)
#endif
/* Symbolic Name: PORT_40_PIN_5 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_16_PORT_40_PIN_5 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_16_PORT_40_PIN_5  (Port_PinType )(0x0285U)
#endif
/* Symbolic Name: PORT_40_PIN_6 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_16_PORT_40_PIN_6 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_16_PORT_40_PIN_6  (Port_PinType )(0x0286U)
#endif
/* Symbolic Name: PORT_40_PIN_7 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_16_PORT_40_PIN_7 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_16_PORT_40_PIN_7  (Port_PinType )(0x0287U)
#endif
/* Symbolic Name: PORT_40_PIN_8 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_16_PORT_40_PIN_8 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_16_PORT_40_PIN_8  (Port_PinType )(0x0288U)
#endif
/* Symbolic Name: PORT_40_PIN_9 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_16_PORT_40_PIN_9 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_16_PORT_40_PIN_9  (Port_PinType )(0x0289U)
#endif
/* Symbolic Name: PORT_40_PIN_10 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_16_PORT_40_PIN_10 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_16_PORT_40_PIN_10  (Port_PinType )(0x028aU)
#endif
/* Symbolic Name: PORT_40_PIN_11 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_16_PORT_40_PIN_11 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_16_PORT_40_PIN_11  (Port_PinType )(0x028bU)
#endif
/* Symbolic Name: PORT_40_PIN_12 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_16_PORT_40_PIN_12 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_16_PORT_40_PIN_12  (Port_PinType )(0x028cU)
#endif
/* Symbolic Name: PORT_40_PIN_13 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_16_PORT_40_PIN_13 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_16_PORT_40_PIN_13  (Port_PinType )(0x028dU)
#endif
/* Symbolic Name: PORT_40_PIN_14 */
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#ifndef PortConf_PortContainer_16_PORT_40_PIN_14 
/*MISRA2012_RULE_5_1_JUSTIFICATION:
MISRA2012_RULE_5_2_JUSTIFICATION:
MISRA2012_RULE_5_4_JUSTIFICATION:
MISRA2012_RULE_5_5_JUSTIFICATION: decomposition of name is not possible,
Further distinct name can not be given*/
#define PortConf_PortContainer_16_PORT_40_PIN_14  (Port_PinType )(0x028eU)
#endif



/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#endif /* PORT_CFG_H */

