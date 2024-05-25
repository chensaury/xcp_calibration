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
 *          File:  TSC_CtPT2000_Handler.h
 *        Config:  Bsw_Project.dpa
 *   ECU-Project:  MDA
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Sender receiver - explicit read services */
Std_ReturnType TSC_CtPT2000_Handler_Rte_Read_PpVlvTgtCCFF_VlvTgtChannel(uint8 *data);
Std_ReturnType TSC_CtPT2000_Handler_Rte_Read_PpVlvTgtCCFF_VlvTgtCurrent(VlvTgtCurrent *data);
Std_ReturnType TSC_CtPT2000_Handler_Rte_Read_PpVlvTgtCCFF_VlvTgtFlutter(VlvTgtFlutter *data);
Std_ReturnType TSC_CtPT2000_Handler_Rte_Read_PpVlvTgtCCFF_VlvTgtFrequency(VlvTgtFrequency *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_CtPT2000_Handler_Rte_Write_PpVelFbAll_VlvFL(const VlvActFL *data);
Std_ReturnType TSC_CtPT2000_Handler_Rte_Write_PpVelFbAll_VlvFR(const VlvActFR *data);
Std_ReturnType TSC_CtPT2000_Handler_Rte_Write_PpVelFbAll_VlvRL(const VlvActRL *data);
Std_ReturnType TSC_CtPT2000_Handler_Rte_Write_PpVelFbAll_VlvRR(const VlvActRR *data);




