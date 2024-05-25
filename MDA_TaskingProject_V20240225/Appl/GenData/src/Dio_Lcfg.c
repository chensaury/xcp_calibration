
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
**  FILENAME  : Dio_Lcfg.c                                                    **
**                                                                            **
**  VERSION   : 1.0.0                                                         **
**                                                                            **
**  DATE, TIME: 2024-02-23, 10:02:52                                      **
**                                                                            **
**  GENERATOR : Build b170330-0431                                          **
**                                                                            **
**  BSW MODULE DECRIPTION : Dio.bmd                                           **
**                                                                            **
**  VARIANT   : Variant LT                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Dio configuration generated out of ECUC file               **
**                                                                            **
**  SPECIFICATION(S) : Specification of Dio Driver, AUTOSAR Release 4.2.2     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                             Includes                                       **
*******************************************************************************/

/* Include Port Module File */
#include "Dio.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/* Memory mapping of the DIO configuration */
#define DIO_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: To be compliant with autosar guidelines 
Dio_Memmap.h header is included without safegaurd.*/
#include "Dio_MemMap.h"

/*
      Configuration of DIO Channel groups 
*/
/* No Groups are configured */

static const Dio_PortChannelIdType Dio_kPortChannelConfig[] =
{
  { /* Port0 */
     DIO_PORT_CONFIGURED,
     (0x0fc0U)
  },
  { /* Port1 */
     DIO_PORT_NOT_CONFIGURED,
     (0x0000U)
  },
  { /* Port2 */
     DIO_PORT_CONFIGURED,
     (0x0200U)
  },
  { /* Port10 */
     DIO_PORT_CONFIGURED,
     (0x0080U)
  },
  { /* Port11 */
     DIO_PORT_CONFIGURED,
     (0x4000U)
  },
  { /* Port12 */
     DIO_PORT_NOT_CONFIGURED,
     (0x0000U)
  },
  { /* Port13 */
     DIO_PORT_NOT_CONFIGURED,
     (0x0000U)
  },
  { /* Port14 */
     DIO_PORT_CONFIGURED,
     (0x0003U)
  },
  { /* Port15 */
     DIO_PORT_CONFIGURED,
     (0x0102U)
  },
  { /* Port20 */
     DIO_PORT_CONFIGURED,
     (0x0408U)
  },
  { /* Port21 */
     DIO_PORT_CONFIGURED,
     (0x003fU)
  },
  { /* Port22 */
     DIO_PORT_CONFIGURED,
     (0x00ffU)
  },
  { /* Port23 */
     DIO_PORT_CONFIGURED,
     (0x00c0U)
  },
  { /* Port32 */
     DIO_PORT_CONFIGURED,
     (0x0018U)
  },
  { /* Port33 */
     DIO_PORT_CONFIGURED,
     (0x311fU)
  },
  { /* Port34 */
     DIO_PORT_CONFIGURED,
     (0x0014U)
  },
  { /* Port40 */
     DIO_PORT_NOT_CONFIGURED,
     (0x0000U)
  }
};

const Dio_ConfigType Dio_Config =
{

    /* Dio Port and Channelconfiguration */
    &Dio_kPortChannelConfig[0],
    /* Dio Channelgroup configuration */
    NULL_PTR,
    /* Configured number of Dio Channelgroups for configuration */
    DIO_CHANNELGROUPCOUNT

};
#define DIO_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: To be compliant with autosar guidelines 
Dio_Memmap.h header is included without safegaurd.*/
/* MISRA2012_RULE_20_1_JUSTIFICATION: Dio_Memmap.h header included as per Autosar 
   guidelines. */
#include "Dio_MemMap.h"

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
