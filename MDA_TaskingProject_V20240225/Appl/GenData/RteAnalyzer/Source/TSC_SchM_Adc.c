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
 *          File:  TSC_SchM_Adc.c
 *        Config:  Bsw_Project.dpa
 *   ECU-Project:  MDA
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "SchM_Adc.h"
#include "TSC_SchM_Adc.h"
void TSC_Adc_SchM_Enter_Adc_KernelData(void)
{
  SchM_Enter_Adc_KernelData();
}
void TSC_Adc_SchM_Exit_Adc_KernelData(void)
{
  SchM_Exit_Adc_KernelData();
}
void TSC_Adc_SchM_Enter_Adc_SrcRegAccess(void)
{
  SchM_Enter_Adc_SrcRegAccess();
}
void TSC_Adc_SchM_Exit_Adc_SrcRegAccess(void)
{
  SchM_Exit_Adc_SrcRegAccess();
}
