/**************************************************************************/
/* FILE NAME: mpc5500_usrccdcfg.h            COPYRIGHT (c) Freescale 2004 */
/*                                                All Rights Reserved     */
/* DESCRIPTION:                                                           */
/* This file contains user definitions for the MPC5500 C functions.       */
/*                                                                        */
/*  The user will make changes to this file for the desired configuration.*/
/*                                                                        */
/*     New definitions will need to be unique for this file,              */
/*     mpc5500_ccdcfg.h and for the assembly equates in mpc5500_defs.inc. */
/*========================================================================*/
/*                                                                        */
/* REV      AUTHOR        DATE       DESCRIPTION OF CHANGE                */
/* ---   -----------   -----------   ---------------------                */
/* 0.1   J. Yokubaitis   8/Oct/03    Initial version.                     */
/* 0.2   G. Jackson     13/Nov/03    Converted for reconfiguration file.  */
/* 0.3   G. Jackson     02/Dec/03    Set up global Pbridge addresses in   */
/*                                     MMU to cover all addresses.        */
/* 0.4   G. Jackson     15/Apr/04    Removed references to application    */
/*                                     code.                              */
/* 0.5   G. Jackson     29/Apr/04    User definition C code file only.    */
/* 0.6   G. Jackson     13/May/04    Changed EBI ORn address mask entries */
/* 0.7   G. Jackson     05/Jun/04    Added PCR field assignments for the  */
/*                                     external bus.                      */
/* 0.8   G. Jackson     10/Jun/04    Added INT_BOOT config option for     */
/*                                    external bus config control.        */
/* 1.0   G. Jackson     30/Jun/04    Changed INT_BOOT to I_EXT_BUS_EN     */
/*                                    Added I_DATA_PORT_SIZE              */
/**************************************************************************/
#include "mpc5500_ccdcfg.h"

#ifdef  __cplusplus
extern "C" {
#endif

/* Define this macro for GNU specific C source code */
#define __PEGNU__

/*****************************************************************/
/*****************************************************************/
/* The user should modify the "C" definitions in this file only */

/* Configure for External Bus Enable */
#define I_EXT_BUS_EN      EXTERNAL_BUS_EN_YES //EXTERNAL_BUS_EN_YES/NO
/* Configure for External Data Port Size */
#define I_DATA_PORT_SIZE  DATA_PORT_32
/* Configure the external clock speeds */ 
#define I_CFG_XCLKS       XCLK_CHNG_YES //XCLK_CHNG_YES/NO 
/* Configure the PBRIDGE and XBAR */
#define I_CFG_PBRG_XBAR   PBRG_XBAR_CHNG_NO //PBRG_XBAR_CHNG_YES/NO


/*################################################*/
/* Fields for the SIU_ECCR (External Clock Control Register (XCLKS)) definitions */
#define ECCR_ENGDIV ENGDIV_128
#define ECCR_EBTS   EBTS_HOLD_NO
#define ECCR_EBDF   EBDF_DIV_2

/*################################################*/
/* Fields for the SIU PCR definitions */
/* SIU PCR ADDR field entries */
#define PA_A_VAL   PA_PRIM
#define OBE_A_VAL  OBE_NO
#define IBE_A_VAL  IBE_NO
#define DSC_A_VAL  DSC_20PF
#define ODE_A_VAL  ODE_DIS
#define HYS_A_VAL  HYS_DIS
#define SRC_A_VAL  SRC_MIN
#define WPE_A_VAL  WPE_DIS
#define WPS_A_VAL  WPS_DN

/* SIU PCR DATA[0:15] field entries */
#define PA_DL   PA_PRIM
#define OBE_DL  OBE_NO
#define IBE_DL  IBE_NO
#define DSC_DL  DSC_20PF
#define ODE_DL  ODE_DIS
#define HYS_DL  HYS_DIS
#define SRC_DL  SRC_MIN
#define WPE_DL  WPE_DIS
#define WPS_DL  WPS_DN

/* SIU PCR DATA[16:31] field entries */
#define PA_DH   PA_PRIM
#define OBE_DH  OBE_NO
#define IBE_DH  IBE_NO
#define DSC_DH  DSC_20PF
#define ODE_DH  ODE_DIS
#define HYS_DH  HYS_DIS
#define SRC_DH  SRC_MIN
#define WPE_DH  WPE_DIS
#define WPS_DH  WPS_DN

/******************************************************************/
/*                Entries for *_C1 and *_C2 are control variables */
/*                Entries for *_CG1 through *_CG4 are Control     */
/*                 Group numbers. A Control Group is independent  */
/*                 of the control variables (*_C1,etc.)           */
/******************************************************************/
/* SIU PCR External Bus Control field 1 entries */
#define PA_C1   PA_PRIM
#define OBE_C1  OBE_NO
#define IBE_C1  IBE_NO
#define DSC_C1  DSC_20PF
#define ODE_C1  ODE_DIS
#define HYS_C1  HYS_DIS
#define SRC_C1  SRC_MIN
#define WPE_C1  WPE_DIS
#define WPS_C1  WPS_DN

/* SIU PCR External Bus Control field 2 entries */
#define PA_C2   PA_PRIM
#define OBE_C2  OBE_NO
#define IBE_C2  IBE_NO
#define DSC_C2  DSC_20PF
#define ODE_C2  ODE_DIS
#define HYS_C2  HYS_DIS
#define SRC_C2  SRC_MIN
#define WPE_C2  WPE_EN
#define WPS_C2  WPS_UP

/* First PCR number and number of PCR registers written in a group. */
/*  FRST_PCR_CGn = PCR number of 1st entry; PCR_CNT_CGn = number of PCRs */
#define FRST_PCR_CG1 62     /* PCR number of first entry for control group one (CG1) */
#define PCR_CNT_CG1   2     /* Number of PCRs for control group 1 (CG1) */
#define FRST_PCR_CG2 64     /* PCR number of first entry for control group 2 (CG2) */
#define PCR_CNT_CG2   4     /* Number of PCRs for CG2    */
#define FRST_PCR_CG3 68     /* PCR number of first entry for control group 3 (CG3) */
#define PCR_CNT_CG3   2     /* Number of PCRs for CG3    */
#define FRST_PCR_CG4  0     /* PCR number of first entry for control group 4 (CG4) */
#define PCR_CNT_CG4   4     /* Number of PCRs for CG4    */


/* SIU PCR ENGCLK entries */
#define OBE_ENGCLK_VAL  OBE_NO
#define DSC_ENGCLK_VAL  DSC_10PF

/* SIU PCR CLKOUT entries */
#define OBE_CLKOUT_VAL  OBE_YS
#define DSC_CLKOUT_VAL  DSC_50PF


/*################################################*/
/* Fields for the EBI MCR definitions */
/* EBI MCR field entries */
#define SIZEN_VAL SIZEN_TSIZ_01
#define SIZE_VAL  SIZE_XFR_32
#define ACGE_VAL  ACGE_DISABLED
#define EXTM_VAL  EXTM_INACTIVE
#define EARB_VAL  EARB_INTERNAL
#define EARP_VAL  EARP_EQUAL
#define MDIS_VAL  MDIS_INACTIVE
#define DBM_VAL   DBUS_32

/*################################################*/
/* Fields for the EBI Chip Select BRn (Base Register) definitions */
/* Base Address field entries */
#define CS0_BA      BA_3FF80  
#define CS1_BA      BA_3FF80
#define CS2_BA      BA_3FF80
#define CS3_BA      BA_3FF80 

/* Port Size field entries */
#define CS0_PS   PS_32BIT  
#define CS1_PS   PS_32BIT
#define CS2_PS   PS_32BIT
#define CS3_PS   PS_32BIT  

/* Burst Length field entries */
#define CS0_BL   BL_4WRD  
#define CS1_BL   BL_4WRD
#define CS2_BL   BL_4WRD
#define CS3_BL   BL_4WRD  

/* Write Enable/Byte Select field entries */
#define CS0_WEBS WEBS_BE
#define CS1_WEBS WEBS_BE
#define CS2_WEBS WEBS_BE
#define CS3_WEBS WEBS_BE  

/* Toggle Burst Data In Progress field entries */
#define CS0_TBDIP TBDIP_BURST
#define CS1_TBDIP TBDIP_BURST
#define CS2_TBDIP TBDIP_BURST
#define CS3_TBDIP TBDIP_BURST 

/* Burst Inhibit field entries */
#define CS0_BI  BI_DISABLE  
#define CS1_BI  BI_DISABLE
#define CS2_BI  BI_DISABLE
#define CS3_BI  BI_DISABLE

/* Valid field entries */
#define CS0_V  V_VALID    
#define CS1_V  V_INVALID
#define CS2_V  V_INVALID
#define CS3_V  V_INVALID   

/*################################################*/
/* Fields for the EBI Chip Select ORn (Option Register) definitions */
/* Address Mask field entries */
#define CS0_AM      AM_4M
#define CS1_AM      AM_4M
#define CS2_AM      AM_4M
#define CS3_AM      AM_4M

/* Cycle length (SCY) field entries */
#define CS0_SCY     OR_SCY_1 // EXTRAM 1 Wait
#define CS1_SCY     OR_SCY_1
#define CS2_SCY     OR_SCY_1
#define CS3_SCY     OR_SCY_1

/* Burst Cycle length (BSCY) field entries */
#define CS0_BSCY    OR_BSCY_0
#define CS1_BSCY    OR_BSCY_0
#define CS2_BSCY    OR_BSCY_0
#define CS3_BSCY    OR_BSCY_0

/*################################################*/
/* Fields for the PBRIDGE_A definitions */
#define PBA_MPCR   MPCR_DEFAULT
#define PBA_PACR0  PACR_DEFAULT
#define PBA_OPACR0 OPACR_DEFAULT
#define PBA_OPACR1 OPACR_DEFAULT
#define PBA_OPACR2 OPACR_DEFAULT

/*################################################*/
/* Fields for the PBRIDGE_B definitions */
#define PBB_MPCR   MPCR_DEFAULT
#define PBB_PACR0  PACR_DEFAULT
#define PBB_PACR2  PACR_DEFAULT
#define PBB_OPACR0 OPACR_DEFAULT
#define PBB_OPACR1 OPACR_DEFAULT
#define PBB_OPACR2 OPACR_DEFAULT
#define PBB_OPACR3 OPACR_DEFAULT

/*################################################*/
/* Fields for the XBAR definitions */

/*################################################*/
/* Master Priority Register 0 (MPR0) field entries */
#define MPR0_MST2  MST2_PRI_LO
#define MPR0_MST1  MST1_PRI_MED
#define MPR0_MST0  MST0_PRI_HI

/*################################################*/
/* Master Priority Register 1 (MPR1) field entries */
#define MPR1_MST2  MST2_PRI_LO
#define MPR1_MST1  MST1_PRI_MED
#define MPR1_MST0  MST0_PRI_HI

/*################################################*/
/* Master Priority Register 3 (MPR3) field entries */
#define MPR3_MST2  MST2_PRI_LO
#define MPR3_MST1  MST1_PRI_MED
#define MPR3_MST0  MST0_PRI_HI

/*################################################*/
/* Master Priority Register 6 (MPR6) field entries */
#define MPR6_MST2  MST2_PRI_LO
#define MPR6_MST1  MST1_PRI_MED
#define MPR6_MST0  MST0_PRI_HI

/*################################################*/
/* Master Priority Register 7 (MPR7) field entries */
#define MPR7_MST2  MST2_PRI_LO
#define MPR7_MST1  MST1_PRI_MED
#define MPR7_MST0  MST0_PRI_HI

/*################################################*/
/* Slave General Purpose Control Register 0 (XBAR_SGPCR0) field entries */
#define SGPCR0_RO   RO_RW
#define SGPCR0_ARB  ARB_FX
#define SGPCR0_PCTL PCTL_PARKMST
#define SGPCR0_PARK PARK_MSTPRT0

/*################################################*/
/* Slave General Purpose Control Register 1 (XBAR_SGPCR1) field entries */
#define SGPCR1_RO   RO_RW
#define SGPCR1_ARB  ARB_FX
#define SGPCR1_PCTL PCTL_PARKMST
#define SGPCR1_PARK PARK_MSTPRT0

/*################################################*/
/* Slave General Purpose Control Register 3 (XBAR_SGPCR3) field entries */
#define SGPCR3_RO   RO_RW
#define SGPCR3_ARB  ARB_FX
#define SGPCR3_PCTL PCTL_PARKMST
#define SGPCR3_PARK PARK_MSTPRT0

/*################################################*/
/* Slave General Purpose Control Register 6 (XBAR_SGPCR6) field entries */
#define SGPCR6_RO   RO_RW
#define SGPCR6_ARB  ARB_FX
#define SGPCR6_PCTL PCTL_PARKMST
#define SGPCR6_PARK PARK_MSTPRT0

/*################################################*/
/* Slave General Purpose Control Register 7 (XBAR_SGPCR7) field entries */
#define SGPCR7_RO   RO_RW
#define SGPCR7_ARB  ARB_FX
#define SGPCR7_PCTL PCTL_PARKMST
#define SGPCR7_PARK PARK_MSTPRT0

/*************************************************************/

