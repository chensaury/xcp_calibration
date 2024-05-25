/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_CtIoHardWare_Type.h
 *        Config:  Bsw_Project.dpa
 *   ECU-Project:  MDA
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  Application types header file for SW-C <CtIoHardWare>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CTIOHARDWARE_TYPE_H
# define _RTE_CTIOHARDWARE_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  define AccPedlPos_LowerLimit (0.0F)
#  define AccPedlPos_UpperLimit (800.0F)

#  define PressureRR1_LowerLimit (0.0F)
#  define PressureRR1_UpperLimit (20.0F)

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CTIOHARDWARE_TYPE_H */
