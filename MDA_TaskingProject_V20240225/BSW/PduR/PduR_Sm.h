/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  PduR_Sm.h
 *      Project:  Gw_AsrPduRCfg5
 *       Module:  MICROSAR PDU Router
 *    Generator:  Configurator 5
 *
 *  Description:  Vector implementation of AUTOSAR PDU Router
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/
#if !defined (PDUR_SM_H)
# define PDUR_SM_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "PduR_Types.h"
# include "PduR_Cfg.h"
# include "PduR_Lcfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define PDUR_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

# if (PDUR_SMDATAPLANEROM == STD_ON)
/**********************************************************************************************************************
 * PduR_Sm_Init
 *********************************************************************************************************************/
/*! \brief       This function initializes the switching manager sub-module.
 *  \details     -
 *  \pre         PduR_InitMemory() has been executed, if the start up code does not initialize variables.
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \note        The function must be called on task level and has not to be interrupted
 *               by other administrative function calls.
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Sm_Init(void);
# endif
# if(PDUR_SMDATAPLANEROM)
/**********************************************************************************************************************
 * PduR_Sm_SrcFilter_LinearTaToSaCalculationStrategy
 *********************************************************************************************************************/
/*! \brief       Call from the routing manager to the switching manager to perform source filtering.
 *  \details     Switching manager updates FIB with PDU adress info.
 *               Used calculation strategy: Linear target to source adress.
 *  \param[in]   smSrcRomIdx           ID of the switching manager source PDU
 *  \param[in]   info                  Pointer to the PDU data and length
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 **********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Sm_SrcFilter_LinearTaToSaCalculationStrategy(PduR_SmSrcRomIdxOfRmSrcRomType smSrcRomIdx, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);
# endif

# if(PDUR_SMDATAPLANEROM)
/**********************************************************************************************************************
 * PduR_Sm_SrcFilter_SaTaFromMetaDataCalculationStrategy
 *********************************************************************************************************************/
/*! \brief       Call from the routing manager to the switching manager to perform source filtering.
 *  \details     Switching manager updates FIB with PDU adress info.
 *               Used calculation strategy: source and target adress adress from meta data by bit positions.
 *  \param[in]   smSrcRomIdx           ID of the switching manager source PDU
 *  \param[in]   info                  Pointer to the PDU data and length
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 **********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_Sm_SrcFilter_SaTaFromMetaDataCalculationStrategy(PduR_SmSrcRomIdxOfRmSrcRomType smSrcRomIdx, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);
# endif

# if(PDUR_SMDATAPLANEROM)
/**********************************************************************************************************************
 * PduR_Sm_LinearTaToSaCalculationStrategy_GetSa_AddOffset
 *********************************************************************************************************************/
/*! \brief       Internal switching manager call to calculate the source and target adress from meta data value.
 *  \details     Linear target to source adress calculation. Offset is added to target adress.
 *  \param[in]   smLinearTaToSaCalculationStrategyIdx  Calculation strategy index.
 *  \param[in]   metaData                              PDU meta data
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 **********************************************************************************************************************/
FUNC(PduR_SmSaType, PDUR_CODE) PduR_Sm_LinearTaToSaCalculationStrategy_GetSa_AddOffset(PduR_SmLinearTaToSaCalculationStrategyRomIterType smLinearTaToSaCalculationStrategyIdx, uint32 metaData);
# endif

# if(PDUR_SMDATAPLANEROM)
/**********************************************************************************************************************
 * PduR_Sm_LinearTaToSaCalculationStrategy_GetSa_SubtractOffset
 *********************************************************************************************************************/
/*! \brief       Internal switching manager call to calculate the source and target adress from meta data value.
 *  \details     Linear target to source adress calculation. Offset is subtracted from target adress.
 *  \param[in]   smLinearTaToSaCalculationStrategyIdx  Calculation strategy index.
 *  \param[in]   metaData                              PDU meta data
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 **********************************************************************************************************************/
FUNC(PduR_SmSaType, PDUR_CODE) PduR_Sm_LinearTaToSaCalculationStrategy_GetSa_SubtractOffset(PduR_SmLinearTaToSaCalculationStrategyRomIterType smLinearTaToSaCalculationStrategyIdx, uint32 metaData);
# endif

# if(PDUR_SMDATAPLANEROM)
/**********************************************************************************************************************
 * PduR_Sm_DestFilter_LinearTaToSaCalculationStrategy
 *********************************************************************************************************************/
/*! \brief       Call from the routing manager to the switching manager to perform destination filtering.
 *  \details     Switching manager checks FIB and allows or blocks the routing of the destination Pdu.
 *               Used calculation strategy: Linear target to source adress.
 *  \param[in]   smGDestRomIdx         ID of the switching manager destination PDU
 *  \param[in]   info                  Pointer to the PDU data and length
 *  \return      PduR_FilterReturnType PDUR_FILTER_PASS   allow routing
 *                                     PDUR_FILTER_BLOCK  block routing
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 **********************************************************************************************************************/
FUNC(PduR_FilterReturnType, PDUR_CODE) PduR_Sm_DestFilter_LinearTaToSaCalculationStrategy(PduR_SmGDestRomIdxOfRmGDestRomType smGDestRomIdx, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);
# endif

# if(PDUR_SMDATAPLANEROM)
/**********************************************************************************************************************
 * PduR_Sm_DestFilter_SaTaFromMetaDataCalculationStrategy
 *********************************************************************************************************************/
/*! \brief       Call from the routing manager to the switching manager to perform destination filtering.
 *  \details     Switching manager checks FIB and allows or blocks the routing of the destination Pdu.
 *               Used calculation strategy: source and target adress adress from meta data by bit positions.
 *  \param[in]   smGDestRomIdx         ID of the switching manager destination PDU
 *  \param[in]   info                  Pointer to the PDU data and length
 *  \return      PduR_FilterReturnType PDUR_FILTER_PASS   allow routing
 *                                     PDUR_FILTER_BLOCK  block routing
 *  \pre         -
 *  \context     TASK|ISR1|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 **********************************************************************************************************************/
FUNC(PduR_FilterReturnType, PDUR_CODE) PduR_Sm_DestFilter_SaTaFromMetaDataCalculationStrategy(PduR_SmGDestRomIdxOfRmGDestRomType smGDestRomIdx, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);
# endif

# define PDUR_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */
#endif /* PDUR_SM_H */
/**********************************************************************************************************************
 *  END OF FILE: PduR_Sm.h
 *********************************************************************************************************************/
