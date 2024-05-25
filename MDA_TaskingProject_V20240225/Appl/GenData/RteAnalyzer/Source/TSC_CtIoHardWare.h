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
 *          File:  TSC_CtIoHardWare.h
 *        Config:  Bsw_Project.dpa
 *   ECU-Project:  MDA
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Sender receiver - explicit write services */
Std_ReturnType TSC_CtIoHardWare_Rte_Write_PpIMU_IMUAcc(const IMUAcc *data);
Std_ReturnType TSC_CtIoHardWare_Rte_Write_PpIMU_IMUAngle(const IMUAngle *data);
Std_ReturnType TSC_CtIoHardWare_Rte_Write_PpIMU_IMURate(const IMURate *data);
Std_ReturnType TSC_CtIoHardWare_Rte_Write_PpIMU_IMUVel(const IMUVel *data);
Std_ReturnType TSC_CtIoHardWare_Rte_Write_PpPedlPos_PedlPos(const PedlPos *data);
Std_ReturnType TSC_CtIoHardWare_Rte_Write_PpPressure_Pressure(const Pressure *data);
Std_ReturnType TSC_CtIoHardWare_Rte_Write_PpSteerWhl_SteerWhl(const SteerWhl *data);
Std_ReturnType TSC_CtIoHardWare_Rte_Write_PpSuspHeight_SuspHeight(const SuspHeight *data);




