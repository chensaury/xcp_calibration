/*******************************************************************************
* Example Code
*
* Copyright(C) 2023 NXP Semiconductors
* NXP Semiconductors Confidential and Proprietary
*
* Software that is described herein is for illustrative purposes only
* which provides customers with programming information regarding the
* NXP products.  This software is supplied "AS IS" without any warranties
* of any kind, and NXP Semiconductors and its licensor disclaim any and
* all warranties, express or implied, including all implied warranties of
* merchantability, fitness for a particular purpose and non-infringement of
* intellectual property rights.  NXP Semiconductors assumes no responsibility
* or liability for the use of the software, conveys no license or rights
* under any patent, copyright, mask work right, or any other intellectual
* property rights in or to any products. NXP Semiconductors reserves the
* right to make changes in the software without notification. NXP
* Semiconductors also makes no representation or warranty that such
* application will be suitable for the specified use without further testing
* or modification.
*
* IN NO EVENT WILL NXP SEMICONDUCTORS BE LIABLE, WHETHER IN CONTRACT, 
* TORT, OR OTHERWISE, FOR ANY INCIDENTAL, SPECIAL, INDIRECT, CONSEQUENTIAL 
* OR PUNITIVE DAMAGES, INCLUDING, BUT NOT LIMITED TO, DAMAGES FOR ANY 
* LOSS OF USE, LOSS OF TIME, INCONVENIENCE, COMMERCIAL LOSS, OR LOST 
* PROFITS, SAVINGS, OR REVENUES, TO THE FULL EXTENT SUCH MAY BE DISCLAIMED  
* BY LAW. NXP SEMICONDUCTOR鈥橲 TOTAL LIABILITY FOR ALL COSTS, DAMAGES,
* CLAIMS, OR LOSSES WHATSOEVER ARISING OUT OF OR IN CONNECTION WITH THE 
* SOFTWARE IS LIMITED TO THE AGGREGATE AMOUNT PAID BY YOU TO NXP SEMICONDUCTORS
* IN CONNECTION WITH THE SOFTWARE TO WHICH LOSSES OR DAMAGES ARE CLAIMED.
*
* Permission to use, copy, modify, and distribute this software and its
* documentation is hereby granted, under NXP Semiconductors' and its
* licensor's relevant copyrights in the software, without fee, provided
* that it is used in conjunction with NXP Semiconductors devices.  This
* copyright, permission, and disclaimer notice must appear in all copies
* of this code.
*******************************************************************************/

//==============================================================================
// This file contains data array declarations for the code RAM, data RAM and
// register arrays for the PT2000.
//==============================================================================

// ECU: IDE Project
// Project: MC33PT2000_VFM_65V_3C

#ifndef PT2000_DATA_H_
#define PT2000_DATA_H_


/*********************************/
/*       constant_current         */
/*******************************/
extern unsigned short PT2000_code_RAM1[134];         // CODE RAM CH 1
extern unsigned short PT2000_code_RAM2[75];          // CODE RAM CH 2
extern unsigned short PT2000_code_RAM3[24];          // CODE RAM CH 3
extern unsigned short PT2000_data_RAM[192];          // DATA RAM
extern unsigned short PT2000_main_config[32];        // main configurations
extern unsigned short PT2000_ch1_config[20];         // CH 1 configurations
extern unsigned short PT2000_ch2_config[20];         // CH 2 configurations
extern unsigned short PT2000_ch3_config[20];         // CH 3 configurations
extern unsigned short PT2000_io_config[73];          // IO configurations
extern unsigned short PT2000_diag_config[64];        // diag configurations
/*********************************/
/*           peak_hold          */
/*******************************/
extern unsigned short PT2000_code_Peak_RAM1[138];    // CODE RAM CH 1
extern unsigned short PT2000_code_Peak_RAM2[77];     // CODE RAM CH 2
extern unsigned short PT2000_code_Peak_RAM3[24];          // CODE RAM CH 3
extern unsigned short PT2000_data_Peak_RAM[192];          // DATA RAM
extern unsigned short PT2000_main_Peak_config[32];        // main configurations
extern unsigned short PT2000_ch1_Peak_config[20];         // CH 1 configurations
extern unsigned short PT2000_ch2_Peak_config[20];         // CH 2 configurations
extern unsigned short PT2000_ch3_Peak_config[20];         // CH 3 configurations
extern unsigned short PT2000_io_Peak_config[73];          // IO configurations
extern unsigned short PT2000_diag_Peak_config[64];        // diag configurations
/*********************************/
/*    1 涓� 鎭掓祦 2 涓� peak         */
/*******************************/
extern unsigned short PT2000_code_Constant1_Peak2_RAM1[136];         // CODE RAM CH 1
extern unsigned short PT2000_code_Constant1_Peak2_RAM2[73];          // CODE RAM CH 2
extern unsigned short PT2000_code_Constant1_Peak2_RAM3[24];          // CODE RAM CH 3
extern unsigned short PT2000_data_Constant1_Peak2_RAM[192];          // DATA RAM
extern unsigned short PT2000_main_Constant1_Peak2_config[32];        // main configurations
extern unsigned short PT2000_ch1_Constant1_Peak2_config[20];         // CH 1 configurations
extern unsigned short PT2000_ch2_Constant1_Peak2_config[20];         // CH 2 configurations
extern unsigned short PT2000_ch3_Constant1_Peak2_config[20];         // CH 3 configurations
extern unsigned short PT2000_io_Constant1_Peak2_config[73];          // IO configurations
extern unsigned short PT2000_diag_Constant1_Peak2_config[64];        // diag configurations


/*********************************/
/*         1涓篜EAK 2涓烘亽娴�         */
/*******************************/

extern unsigned short PT2000_code_Peak1_Constant2_RAM1[136];         // CODE RAM CH 1
extern unsigned short PT2000_code_Peak1_Constant2_RAM2[73];          // CODE RAM CH 2
extern unsigned short PT2000_code_Peak1_Constant2_RAM3[24];          // CODE RAM CH 3
extern unsigned short PT2000_data_Peak1_Constant2_RAM[192];          // DATA RAM
extern unsigned short PT2000_main_Peak1_Constant2_config[32];        // main configurations
extern unsigned short PT2000_ch1_Peak1_Constant2_config[20];         // CH 1 configurations
extern unsigned short PT2000_ch2_Peak1_Constant2_config[20];         // CH 2 configurations
extern unsigned short PT2000_ch3_Peak1_Constant2_config[20];         // CH 3 configurations
extern unsigned short PT2000_io_Peak1_Constant2_config[73];          // IO configurations
extern unsigned short PT2000_diag_Peak1_Constant2_config[64];        // diag configurations



#endif /* PT2000_DATA_H_ */
