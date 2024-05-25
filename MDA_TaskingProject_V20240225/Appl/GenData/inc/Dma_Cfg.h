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
**  FILENAME  : Dma_Cfg.h                                                     **
**                                                                            **
**  VERSION   : 3.0.0                                                         **
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

#ifndef DMA_CFG_H
#define DMA_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Include the McalLib header */
#include "McalLib_Cfg.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/* AUTOSAR specification version numbers */
/* [cover parentID={40CCE8CD-73D5-44c6-8370-F659C1A56ABD}]
DMA_AR_RELEASE_MAJOR_VERSION
[/cover] */
/* [cover parentID={CF5151EF-73C2-40af-BC84-20167F6C2EDB}]
DMA_AR_RELEASE_MINOR_VERSION
[/cover] */
/* [cover parentID={2BBA264E-605D-4a4f-9477-4C4F87931E68}]
DMA_AR_RELEASE_REVISION_VERSION
[/cover] */
#define DMA_AR_RELEASE_MAJOR_VERSION        (4U)
#define DMA_AR_RELEASE_MINOR_VERSION        (2U)
#define DMA_AR_RELEASE_REVISION_VERSION     (2U)

/*SW Version Information*/
/* [cover parentID={60DF11D7-94B0-4b23-B422-7FE28D556787}]
DMA_SW_MAJOR_VERSION
[/cover] */
/* [cover parentID={72B5A76B-8621-42f1-AC66-D18D21F086AF}]
DMA_SW_MINOR_VERSION
[/cover] */
/* [cover parentID={8737518F-C058-4265-B186-EF33C18D403C}]
DMA_SW_PATCH_VERSION
[/cover] */
#define DMA_SW_MAJOR_VERSION                (2U)
#define DMA_SW_MINOR_VERSION                (1U)
#define DMA_SW_PATCH_VERSION                (0U)

/*Number of DMA channels present in the controller*/
/* [cover pparentID={A02B4E43-1406-49a7-8E03-D631ED6393E1}]
DMA_MAX_NUM_OF_CHANNELS
[/cover] */
#define DMA_MAX_NUM_OF_CHANNELS             (128U)


/* Derived Configuration for DmaDevErrorDetect */
/*
Configuration: DMA_DEV_ERROR_DETECT
Preprocessor switch for enabling the development error detection and
reporting.
- if STD_ON, DET is Enabled
- if STD_OFF,DET is Disabled
*/
/* [cover parentID={7AB95133-DBBB-49fd-913E-CE67BDD9B492}]
DMA_DEV_ERROR_DETECT
[/cover] */
#define DMA_DEV_ERROR_DETECT                (STD_OFF)


/* Configuration: DMA_CHDEINIT_API
Deinit API configuration
- if STD_ON, Dma_ChDeInit API is available
- if STD_OFF, Dma_ChDeInit API is not available
*/
/* [cover parentID={B4288CCC-24CC-483e-AEB4-6E0F74DB4B19}]
DMA_CHDEINIT_API
[/cover] */
#define DMA_CHDEINIT_API                    (STD_ON)

/* Configuration: DMA_SUSPEND_API
Suspend and freeze API configuration
- if STD_ON, Dma_ChTransferFreeze and Dma_ChTransferResume APIs are available
- if STD_OFF, Dma_ChTransferFreeze and Dma_ChTransferResume APIs are not
              available
*/
/* [cover parentID={74E1D4AB-F716-4619-826F-31B9A0C41D80}]
DMA_SUSPEND_API
[/cover] */
#define DMA_SUSPEND_API                     (STD_ON)

/* Configuration: DMA_TRIGGER_API
Channel hardware trigger API configuration
- if STD_ON, Dma_ChEnableHardwareTrigger and Dma_ChDisableHardwareTrigger APIs
             are available
- if STD_OFF, Dma_ChEnableHardwareTrigger and Dma_ChDisableHardwareTrigger APIs
             are not available
*/
/* [cover parentID={E7799D5F-670D-43df-B25E-06FF48229C23}]
DMA_TRIGGER_API
[/cover] */
#define DMA_TRIGGER_API                     (STD_ON)

/* Configuration: DMA_DATA_PENDING_API
Get remaining data API configuration
- if STD_ON, Dma_ChGetRemainingData API is available
- if STD_OFF, Dma_ChGetRemainingData API is not available
*/
/* [cover parentID={E296EFD7-A8D9-4b8e-82DB-86F106D97ABB}]
DMA_DATA_PENDING_API
[/cover] */
#define DMA_DATA_PENDING_API                (STD_ON)

/* Configuration: DMA_BUFFER_SWITCH_API
Buffer Switch API configuration
- if STD_ON, Dma_ChSwitchBuffer API is available
- if STD_OFF, Dma_ChSwitchBuffer API is not available
*/
/* [cover parentID={FA7482A2-4409-4e56-80AE-B45E388D4F9F}]
DMA_BUFFER_SWITCH_API
[/cover] */
#define DMA_BUFFER_SWITCH_API               (STD_ON)

/* Configuration: DMA_GETVERSIONINFO_API
Version Information API configuration
- if STD_ON, Dma_GetVersionInfo API is available
- if STD_OFF, Dma_GetVersionInfo API is not available
*/
/* [cover parentID={19352A23-55BC-4b78-90F5-47815F96C79A}]
DMA_GETVERSIONINFO_API
[/cover] */
#define DMA_GETVERSIONINFO_API               (STD_OFF)


/* Maximum number of transaction set allowed on a DMA channel in case
   of linked list
*/
/* [cover parentID={2187C834-E665-4db0-99A6-8AA5DB9AA087}]
DMA_MAX_TRANSACTION_SET_PER_CHANNEL
[/cover] */
#define DMA_MAX_TRANSACTION_SET_PER_CHANNEL (1U)


/* configuration for DMA_LINKED_LIST_ENABLE
- if STD_ON, Any channel has more than one TCS
- if STD_OFF, None of the DMA channel has more than one TCS
*/

#define DMA_LINKED_LIST_ENABLE              (STD_OFF)

/* configuration for DMA_DOUBLE_BUFFER_ENABLE
- if STD_ON, Any DMA channel has Double buffer configuration
- if STD_OFF, None of the DMA channel has Double buffer configuration
*/
/* [cover parentID={18C5B46C-0D0E-48b2-B9E6-1225E057A522}]
DMA_DOUBLE_BUFFER_ENABLE
[/cover] */
#define DMA_DOUBLE_BUFFER_ENABLE            (STD_OFF)

/* No of DMA channels used in the configuration */
/* [cover parentID={0D41BBBC-A58F-4caf-B254-6241838765EA}]
DMA_NUM_OF_CHANNELS
[/cover] */
#define DMA_NUM_OF_CHANNELS                 (8U)


/* ******************** USER/SUPERVISOR MODE CONFIGURATIONS ***************** */

#define DMA_MCAL_SUPERVISORMODE (0U)
#define DMA_MCAL_USER1MODE      (1U)

/* Configuration: DMA_INIT_API_MODE
Mode selection for the Init and Deinit APIs
- if DMA_MCAL_SUPERVISORMODE, the init and deinit functions should be
  running in the supervisor mode
- if DMA_MCAL_USER1MODE, the init and deinit functions should be running in the
  user1 mode
*/
/* [cover parentID={109A2A0C-FAD5-46d6-8640-09FB91EE6147}]
DMA_INIT_API_MODE
[/cover] */
#define DMA_INIT_API_MODE       (DMA_MCAL_SUPERVISORMODE)

/* Configuration: DMA_RUNTIME_API_MODE
Mode selection for the Runtime APIs
- if DMA_MCAL_SUPERVISORMODE, the Runtime functions should be running in the
  supervisor mode
- if DMA_MCAL_USER1MODE, the Runtime functions should be running in the
  user1 mode
*/
/* [cover parentID={6E3C8B08-0002-434f-B6E8-F4F6F61A496F}]
DMA_RUNTIME_API_MODE
[/cover] */
#define DMA_RUNTIME_API_MODE    (DMA_MCAL_SUPERVISORMODE)
/* ************************************************************************** */


/* ************************ MULTICORE CONFIGURATIONS ************************ */

/* Derived Configuration for DmaMultiCoreErrorDetect */
/*
Configuration: DMA_MULTICORE_ERROR_DETECT
Preprocessor switch for enabling the multicore error checks and error reporting.
- if STD_ON, multicore error checks are Enabled
- if STD_OFF, multicore error checks are Disabled
*/
/* [cover parentID={6A6168FB-F0C0-4a19-8AC6-7BBD2FEA1914}]
DMA_MULTICORE_ERROR_DETECT
[/cover] */

#define DMA_MULTICORE_ERROR_DETECT          (STD_OFF)

/* Total number of DMA channels in core 0 */
#define DMA_ALLOCATED_CHANNELS_CORE0 (8U)
/* Total number of DMA channels in core 1 */
#define DMA_ALLOCATED_CHANNELS_CORE1 (0U)
/* Total number of DMA channels in core 2 */
#define DMA_ALLOCATED_CHANNELS_CORE2 (0U)
/* Total number of DMA channels in core 3 */
#define DMA_ALLOCATED_CHANNELS_CORE3 (0U)
/* Total number of DMA channels in core 4 */
#define DMA_ALLOCATED_CHANNELS_CORE4 (0U)
/* Total number of DMA channels in core 5 */
#define DMA_ALLOCATED_CHANNELS_CORE5 (0U)

/* ************************************************************************** */


/* *************************** SAFETY CONFIGURATIONS ************************ */

/* Derived Configuration for DmaSafetyEnable */
/*
Configuration: DMA_SAFETY_ENABLE
Preprocessor switch for enabling the safety checks and error reporting.
- if STD_ON, Safety checks are Enabled
- if STD_OFF,Safety checks are Disabled
*/
/* [cover parentID={513EAA68-EE91-45a0-9556-76A5DDF1CD8E}]
DMA_SAFETY_ENABLE
[/cover] */
#define DMA_SAFETY_ENABLE                   (STD_OFF)

/* Configuration: DMA_INITCHECK_API
Init check API configuration
- if STD_ON,  Dma_InitCheck API is available
- if STD_OFF, Dma_InitCheck API is not available
*/
/* [cover parentID={CFB33CEC-75DF-451b-AD5F-3B89E2032BF7}]
DMA_INITCHECK_API
[/cover] */
#define DMA_INITCHECK_API                   (STD_ON)
/* ************************************************************************** */

#endif  /* DMA_CFG_H */


