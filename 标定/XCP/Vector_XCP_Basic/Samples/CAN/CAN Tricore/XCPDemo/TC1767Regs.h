//****************************************************************************
// Description:
//       Register Definition File for TC1767
//
//----------------------------------------------------------------------------
// History:
//                 
//        Rev.             Date        Description
//        --------------------------------------------------------------------
//        1.0              29.09.08    initial version
//        
//
//
//****************************************************************************

#ifndef _REGISTER_DEFINITION_H_
#define _REGISTER_DEFINITION_H_

//****************************************************************************
// @Declaration of SFRs
//****************************************************************************

// Address Register 0 (AGPR) Global Address Register
#define A0                     (*((uword volatile *) 0xF7E1FF80))

// Address Register 1 (AGPR) Global Address Register
#define A1                     (*((uword volatile *) 0xF7E1FF84))

// Address Register 10 (AGPR) Stack Pointer
#define A10                    (*((uword volatile *) 0xF7E1FFA8))

// Address Register 11 (AGPR) Return Address
#define A11                    (*((uword volatile *) 0xF7E1FFAC))

// Address Register 12 (AGPR)
#define A12                    (*((uword volatile *) 0xF7E1FFB0))

// Address Register 13 (AGPR)
#define A13                    (*((uword volatile *) 0xF7E1FFB4))

// Address Register 14 (AGPR)
#define A14                    (*((uword volatile *) 0xF7E1FFB8))

// Address Register 15 (AGPR)
#define A15                    (*((uword volatile *) 0xF7E1FFBC))

// Address Register 2 (AGPR)
#define A2                     (*((uword volatile *) 0xF7E1FF88))

// Address Register 3 (AGPR)
#define A3                     (*((uword volatile *) 0xF7E1FF8C))

// Address Register 4 (AGPR)
#define A4                     (*((uword volatile *) 0xF7E1FF90))

// Address Register 5 (AGPR)
#define A5                     (*((uword volatile *) 0xF7E1FF94))

// Address Register 6 (AGPR)
#define A6                     (*((uword volatile *) 0xF7E1FF98))

// Address Register 7 (AGPR)
#define A7                     (*((uword volatile *) 0xF7E1FF9C))

// Address Register 8 (AGPR) Global Address Register
#define A8                     (*((uword volatile *) 0xF7E1FFA0))

// Address Register 9 (AGPR) Global Address Register
#define A9                     (*((uword volatile *) 0xF7E1FFA4))

// ADC0 Alias Register 0
#define ADC0_ALR0              (*((uword volatile *) 0xF0101210))

// ADC0 Access Protection Register
#define ADC0_APR               (*((uword volatile *) 0xF0101218))
#define ADC0_APR_ACCERR          0x00008000
#define ADC0_APR_RG0             0x00000001
#define ADC0_APR_RG1             0x00000002
#define ADC0_APR_RG2             0x00000004
#define ADC0_APR_RG3             0x00000008
#define ADC0_APR_RG4             0x00000010
#define ADC0_APR_RG5             0x00000020

// ADC0 Arbitration Slot Enable Register
#define ADC0_ASENR             (*((uword volatile *) 0xF010103C))
#define ADC0_ASENR_ASEN0         0x00000001
#define ADC0_ASENR_ASEN1         0x00000002
#define ADC0_ASENR_ASEN2         0x00000004
#define ADC0_ASENR_ASEN3         0x00000008
#define ADC0_ASENR_ASEN4         0x00000010

// ADC0 Channel 0 Control Register
#define ADC0_CHCTR0            (*((uword volatile *) 0xF0101100))
#define ADC0_CHCTR0_SYNC         0x00000080

// ADC0 Channel 1 Control Register
#define ADC0_CHCTR1            (*((uword volatile *) 0xF0101104))
#define ADC0_CHCTR1_SYNC         0x00000080

// ADC0 Channel 10 Control Register
#define ADC0_CHCTR10           (*((uword volatile *) 0xF0101128))
#define ADC0_CHCTR10_SYNC        0x00000080

// ADC0 Channel 11 Control Register
#define ADC0_CHCTR11           (*((uword volatile *) 0xF010112C))
#define ADC0_CHCTR11_SYNC        0x00000080

// ADC0 Channel 12 Control Register
#define ADC0_CHCTR12           (*((uword volatile *) 0xF0101130))
#define ADC0_CHCTR12_SYNC        0x00000080

// ADC0 Channel 13 Control Register
#define ADC0_CHCTR13           (*((uword volatile *) 0xF0101134))
#define ADC0_CHCTR13_SYNC        0x00000080

// ADC0 Channel 14 Control Register
#define ADC0_CHCTR14           (*((uword volatile *) 0xF0101138))
#define ADC0_CHCTR14_SYNC        0x00000080

// ADC0 Channel 15 Control Register
#define ADC0_CHCTR15           (*((uword volatile *) 0xF010113C))
#define ADC0_CHCTR15_SYNC        0x00000080

// ADC0 Channel 2 Control Register
#define ADC0_CHCTR2            (*((uword volatile *) 0xF0101108))
#define ADC0_CHCTR2_SYNC         0x00000080

// ADC0 Channel 3 Control Register
#define ADC0_CHCTR3            (*((uword volatile *) 0xF010110C))
#define ADC0_CHCTR3_SYNC         0x00000080

// ADC0 Channel 4 Control Register
#define ADC0_CHCTR4            (*((uword volatile *) 0xF0101110))
#define ADC0_CHCTR4_SYNC         0x00000080

// ADC0 Channel 5 Control Register
#define ADC0_CHCTR5            (*((uword volatile *) 0xF0101114))
#define ADC0_CHCTR5_SYNC         0x00000080

// ADC0 Channel 6 Control Register
#define ADC0_CHCTR6            (*((uword volatile *) 0xF0101118))
#define ADC0_CHCTR6_SYNC         0x00000080

// ADC0 Channel 7 Control Register
#define ADC0_CHCTR7            (*((uword volatile *) 0xF010111C))
#define ADC0_CHCTR7_SYNC         0x00000080

// ADC0 Channel 8 Control Register
#define ADC0_CHCTR8            (*((uword volatile *) 0xF0101120))
#define ADC0_CHCTR8_SYNC         0x00000080

// ADC0 Channel 9 Control Register
#define ADC0_CHCTR9            (*((uword volatile *) 0xF0101124))
#define ADC0_CHCTR9_SYNC         0x00000080

// ADC0 Channel Event Node Pointer Register 0
#define ADC0_CHENPR0           (*((uword volatile *) 0xF0101068))

// ADC0 Channel Event Node Pointer Register 8
#define ADC0_CHENPR8           (*((uword volatile *) 0xF010106C))

// ADC0 Channel Flag Clear Register
#define ADC0_CHFCR             (*((uword volatile *) 0xF0101064))
#define ADC0_CHFCR_CFC0          0x00000001
#define ADC0_CHFCR_CFC1          0x00000002
#define ADC0_CHFCR_CFC10         0x00000400
#define ADC0_CHFCR_CFC11         0x00000800
#define ADC0_CHFCR_CFC12         0x00001000
#define ADC0_CHFCR_CFC13         0x00002000
#define ADC0_CHFCR_CFC14         0x00004000
#define ADC0_CHFCR_CFC15         0x00008000
#define ADC0_CHFCR_CFC2          0x00000004
#define ADC0_CHFCR_CFC3          0x00000008
#define ADC0_CHFCR_CFC4          0x00000010
#define ADC0_CHFCR_CFC5          0x00000020
#define ADC0_CHFCR_CFC6          0x00000040
#define ADC0_CHFCR_CFC7          0x00000080
#define ADC0_CHFCR_CFC8          0x00000100
#define ADC0_CHFCR_CFC9          0x00000200

// ADC0 Channel Flag Register
#define ADC0_CHFR              (*((uword volatile *) 0xF0101060))
#define ADC0_CHFR_FC0            0x00000001
#define ADC0_CHFR_FC1            0x00000002
#define ADC0_CHFR_FC10           0x00000400
#define ADC0_CHFR_FC11           0x00000800
#define ADC0_CHFR_FC12           0x00001000
#define ADC0_CHFR_FC13           0x00002000
#define ADC0_CHFR_FC14           0x00004000
#define ADC0_CHFR_FC15           0x00008000
#define ADC0_CHFR_FC2            0x00000004
#define ADC0_CHFR_FC3            0x00000008
#define ADC0_CHFR_FC4            0x00000010
#define ADC0_CHFR_FC5            0x00000020
#define ADC0_CHFR_FC6            0x00000040
#define ADC0_CHFR_FC7            0x00000080
#define ADC0_CHFR_FC8            0x00000100
#define ADC0_CHFR_FC9            0x00000200

// ADC Clock Control Register
#define ADC0_CLC               (*((uword volatile *) 0xF0101000))
#define ADC0_CLC_DISR            0x00000001
#define ADC0_CLC_DISS            0x00000002
#define ADC0_CLC_EDIS            0x00000008
#define ADC0_CLC_FSOE            0x00000020
#define ADC0_CLC_SBWE            0x00000010
#define ADC0_CLC_SPEN            0x00000004

// ADC0 Conversion Request 1 Control Register
#define ADC0_CRCR1             (*((uword volatile *) 0xF0101090))
#define ADC0_CRCR1_CH0           0x00000001
#define ADC0_CRCR1_CH1           0x00000002
#define ADC0_CRCR1_CH10          0x00000400
#define ADC0_CRCR1_CH11          0x00000800
#define ADC0_CRCR1_CH12          0x00001000
#define ADC0_CRCR1_CH13          0x00002000
#define ADC0_CRCR1_CH14          0x00004000
#define ADC0_CRCR1_CH15          0x00008000
#define ADC0_CRCR1_CH2           0x00000004
#define ADC0_CRCR1_CH3           0x00000008
#define ADC0_CRCR1_CH4           0x00000010
#define ADC0_CRCR1_CH5           0x00000020
#define ADC0_CRCR1_CH6           0x00000040
#define ADC0_CRCR1_CH7           0x00000080
#define ADC0_CRCR1_CH8           0x00000100
#define ADC0_CRCR1_CH9           0x00000200

// ADC0 Conversion Request 3 Control Register
#define ADC0_CRCR3             (*((uword volatile *) 0xF01010B0))
#define ADC0_CRCR3_CH0           0x00000001
#define ADC0_CRCR3_CH1           0x00000002
#define ADC0_CRCR3_CH10          0x00000400
#define ADC0_CRCR3_CH11          0x00000800
#define ADC0_CRCR3_CH12          0x00001000
#define ADC0_CRCR3_CH13          0x00002000
#define ADC0_CRCR3_CH14          0x00004000
#define ADC0_CRCR3_CH15          0x00008000
#define ADC0_CRCR3_CH2           0x00000004
#define ADC0_CRCR3_CH3           0x00000008
#define ADC0_CRCR3_CH4           0x00000010
#define ADC0_CRCR3_CH5           0x00000020
#define ADC0_CRCR3_CH6           0x00000040
#define ADC0_CRCR3_CH7           0x00000080
#define ADC0_CRCR3_CH8           0x00000100
#define ADC0_CRCR3_CH9           0x00000200

// ADC0 Conversion Request 1 Mode Register
#define ADC0_CRMR1             (*((uword volatile *) 0xF0101098))
#define ADC0_CRMR1_CLRPND        0x00000100
#define ADC0_CRMR1_ENSI          0x00000008
#define ADC0_CRMR1_ENTR          0x00000004
#define ADC0_CRMR1_LDEV          0x00000200
#define ADC0_CRMR1_LDM           0x00000020
#define ADC0_CRMR1_REQGT         0x00000080
#define ADC0_CRMR1_SCAN          0x00000010

// ADC0 Conversion Request 3 Mode Register
#define ADC0_CRMR3             (*((uword volatile *) 0xF01010B8))
#define ADC0_CRMR3_CLRPND        0x00000100
#define ADC0_CRMR3_ENSI          0x00000008
#define ADC0_CRMR3_ENTR          0x00000004
#define ADC0_CRMR3_LDEV          0x00000200
#define ADC0_CRMR3_LDM           0x00000020
#define ADC0_CRMR3_REQGT         0x00000080
#define ADC0_CRMR3_SCAN          0x00000010

// ADC0 Conversion Request 1 Pending Register
#define ADC0_CRPR1             (*((uword volatile *) 0xF0101094))
#define ADC0_CRPR1_CHP0          0x00000001
#define ADC0_CRPR1_CHP1          0x00000002
#define ADC0_CRPR1_CHP10         0x00000400
#define ADC0_CRPR1_CHP11         0x00000800
#define ADC0_CRPR1_CHP12         0x00001000
#define ADC0_CRPR1_CHP13         0x00002000
#define ADC0_CRPR1_CHP14         0x00004000
#define ADC0_CRPR1_CHP15         0x00008000
#define ADC0_CRPR1_CHP2          0x00000004
#define ADC0_CRPR1_CHP3          0x00000008
#define ADC0_CRPR1_CHP4          0x00000010
#define ADC0_CRPR1_CHP5          0x00000020
#define ADC0_CRPR1_CHP6          0x00000040
#define ADC0_CRPR1_CHP7          0x00000080
#define ADC0_CRPR1_CHP8          0x00000100
#define ADC0_CRPR1_CHP9          0x00000200

// ADC0 Conversion Request 3 Pending Register
#define ADC0_CRPR3             (*((uword volatile *) 0xF01010B4))
#define ADC0_CRPR3_CHP0          0x00000001
#define ADC0_CRPR3_CHP1          0x00000002
#define ADC0_CRPR3_CHP10         0x00000400
#define ADC0_CRPR3_CHP11         0x00000800
#define ADC0_CRPR3_CHP12         0x00001000
#define ADC0_CRPR3_CHP13         0x00002000
#define ADC0_CRPR3_CHP14         0x00004000
#define ADC0_CRPR3_CHP15         0x00008000
#define ADC0_CRPR3_CHP2          0x00000004
#define ADC0_CRPR3_CHP3          0x00000008
#define ADC0_CRPR3_CHP4          0x00000010
#define ADC0_CRPR3_CHP5          0x00000020
#define ADC0_CRPR3_CHP6          0x00000040
#define ADC0_CRPR3_CHP7          0x00000080
#define ADC0_CRPR3_CHP8          0x00000100
#define ADC0_CRPR3_CHP9          0x00000200

// ADC0 External Multiplexer Control Register
#define ADC0_EMCTR             (*((uword volatile *) 0xF0101220))
#define ADC0_EMCTR_EMUXEN        0x00800000
#define ADC0_EMCTR_SCANEN        0x00400000
#define ADC0_EMCTR_TROEN         0x00200000

// ADC0 Event Flag Clear Register
#define ADC0_EVFCR             (*((uword volatile *) 0xF0101074))
#define ADC0_EVFCR_CFR0          0x00000001
#define ADC0_EVFCR_CFR1          0x00000002
#define ADC0_EVFCR_CFR10         0x00000400
#define ADC0_EVFCR_CFR11         0x00000800
#define ADC0_EVFCR_CFR12         0x00001000
#define ADC0_EVFCR_CFR13         0x00002000
#define ADC0_EVFCR_CFR14         0x00004000
#define ADC0_EVFCR_CFR15         0x00008000
#define ADC0_EVFCR_CFR2          0x00000004
#define ADC0_EVFCR_CFR3          0x00000008
#define ADC0_EVFCR_CFR4          0x00000010
#define ADC0_EVFCR_CFR5          0x00000020
#define ADC0_EVFCR_CFR6          0x00000040
#define ADC0_EVFCR_CFR7          0x00000080
#define ADC0_EVFCR_CFR8          0x00000100
#define ADC0_EVFCR_CFR9          0x00000200
#define ADC0_EVFCR_CFS0          0x00010000
#define ADC0_EVFCR_CFS1          0x00020000
#define ADC0_EVFCR_CFS2          0x00040000
#define ADC0_EVFCR_CFS3          0x00080000
#define ADC0_EVFCR_CFS4          0x00100000

// ADC0 Event Flag Register
#define ADC0_EVFR              (*((uword volatile *) 0xF0101070))
#define ADC0_EVFR_FR0            0x00000001
#define ADC0_EVFR_FR1            0x00000002
#define ADC0_EVFR_FR10           0x00000400
#define ADC0_EVFR_FR11           0x00000800
#define ADC0_EVFR_FR12           0x00001000
#define ADC0_EVFR_FR13           0x00002000
#define ADC0_EVFR_FR14           0x00004000
#define ADC0_EVFR_FR15           0x00008000
#define ADC0_EVFR_FR2            0x00000004
#define ADC0_EVFR_FR3            0x00000008
#define ADC0_EVFR_FR4            0x00000010
#define ADC0_EVFR_FR5            0x00000020
#define ADC0_EVFR_FR6            0x00000040
#define ADC0_EVFR_FR7            0x00000080
#define ADC0_EVFR_FR8            0x00000100
#define ADC0_EVFR_FR9            0x00000200
#define ADC0_EVFR_FS0            0x00010000
#define ADC0_EVFR_FS1            0x00020000
#define ADC0_EVFR_FS2            0x00040000
#define ADC0_EVFR_FS3            0x00080000
#define ADC0_EVFR_FS4            0x00100000
#define ADC0_EVFR_GFS0           0x01000000
#define ADC0_EVFR_GFS1           0x02000000
#define ADC0_EVFR_GFS2           0x04000000
#define ADC0_EVFR_GFS3           0x08000000
#define ADC0_EVFR_GFS4           0x10000000

// ADC0 Event Node Pointer Register
#define ADC0_EVNPR             (*((uword volatile *) 0xF0101078))

// ADC0 Global Configuration Register
#define ADC0_GLOBCFG           (*((uword volatile *) 0xF0101034))
#define ADC0_GLOBCFG_DPCAL       0x00000040
#define ADC0_GLOBCFG_MTM7        0x00000010
#define ADC0_GLOBCFG_SUCAL       0x00000020

// ADC0 Global Control Register
#define ADC0_GLOBCTR           (*((uword volatile *) 0xF0101030))
#define ADC0_GLOBCTR_ARBM        0x00008000

// ADC0 Global Status Register
#define ADC0_GLOBSTR           (*((uword volatile *) 0xF0101038))
#define ADC0_GLOBSTR_BUSY        0x00000001
#define ADC0_GLOBSTR_CAL         0x00000004
#define ADC0_GLOBSTR_SAMPLE      0x00000002
#define ADC0_GLOBSTR_SYNRUN      0x00000400

// ADC0 Input Class Register 0
#define ADC0_INPCR0            (*((uword volatile *) 0xF0101050))

// ADC0 Input Class Register 1
#define ADC0_INPCR1            (*((uword volatile *) 0xF0101054))

// ADC0 Input Class Register 2
#define ADC0_INPCR2            (*((uword volatile *) 0xF0101058))

// ADC0 Input Class Register 3
#define ADC0_INPCR3            (*((uword volatile *) 0xF010105C))

// ADC0 Interrupt Activation Register
#define ADC0_INTR              (*((uword volatile *) 0xF0101204))
#define ADC0_INTR_SISR0          0x00000001
#define ADC0_INTR_SISR1          0x00000002
#define ADC0_INTR_SISR2          0x00000004
#define ADC0_INTR_SISR3          0x00000008
#define ADC0_INTR_SISR4          0x00000010
#define ADC0_INTR_SISR5          0x00000020
#define ADC0_INTR_SISR6          0x00000040
#define ADC0_INTR_SISR7          0x00000080

// ADC0 Kernel State Configuration Register
#define ADC0_KSCFG             (*((uword volatile *) 0xF010100C))
#define ADC0_KSCFG_ACK           0x00000004
#define ADC0_KSCFG_BPNOM         0x00000080
#define ADC0_KSCFG_BPSUM         0x00000800
#define ADC0_KSCFG_SUSREQ        0x00000008

// ADC0 Limit Check Boundary Register 0
#define ADC0_LCBR0             (*((uword volatile *) 0xF01010F0))

// ADC0 Limit Check Boundary Register 1
#define ADC0_LCBR1             (*((uword volatile *) 0xF01010F4))

// ADC0 Limit Check Boundary Register 2
#define ADC0_LCBR2             (*((uword volatile *) 0xF01010F8))

// ADC0 Limit Check Boundary Register 3
#define ADC0_LCBR3             (*((uword volatile *) 0xF01010FC))

// ADC0 Queue 0 Register 0
#define ADC0_Q0R0              (*((uword volatile *) 0xF0101088))
#define ADC0_Q0R0_ENSI           0x00000040
#define ADC0_Q0R0_EXTR           0x00000080
#define ADC0_Q0R0_RF             0x00000020
#define ADC0_Q0R0_V              0x00000100

// ADC0 Queue 2 Register 0
#define ADC0_Q0R2              (*((uword volatile *) 0xF01010A8))
#define ADC0_Q0R2_ENSI           0x00000040
#define ADC0_Q0R2_EXTR           0x00000080
#define ADC0_Q0R2_RF             0x00000020
#define ADC0_Q0R2_V              0x00000100

// ADC0 Queue 4 Register 0
#define ADC0_Q0R4              (*((uword volatile *) 0xF01010C8))
#define ADC0_Q0R4_ENSI           0x00000040
#define ADC0_Q0R4_EXTR           0x00000080
#define ADC0_Q0R4_RF             0x00000020
#define ADC0_Q0R4_V              0x00000100

// ADC0 Queue 0 Backup Register
#define ADC0_QBUR0             (*((uword volatile *) 0xF010108C))
#define ADC0_QBUR0_ENSI          0x00000040
#define ADC0_QBUR0_EXTR          0x00000080
#define ADC0_QBUR0_RF            0x00000020
#define ADC0_QBUR0_V             0x00000100

// ADC0 Queue 2 Backup Register
#define ADC0_QBUR2             (*((uword volatile *) 0xF01010AC))
#define ADC0_QBUR2_ENSI          0x00000040
#define ADC0_QBUR2_EXTR          0x00000080
#define ADC0_QBUR2_RF            0x00000020
#define ADC0_QBUR2_V             0x00000100

// ADC0 Queue 4 Backup Register
#define ADC0_QBUR4             (*((uword volatile *) 0xF01010CC))
#define ADC0_QBUR4_ENSI          0x00000040
#define ADC0_QBUR4_EXTR          0x00000080
#define ADC0_QBUR4_RF            0x00000020
#define ADC0_QBUR4_V             0x00000100

// ADC0 Queue 0 Input Register
#define ADC0_QINR0             (*((uword volatile *) 0xF010108C))
#define ADC0_QINR0_ENSI          0x00000040
#define ADC0_QINR0_EXTR          0x00000080
#define ADC0_QINR0_RF            0x00000020

// ADC0 Queue 2 Input Register
#define ADC0_QINR2             (*((uword volatile *) 0xF01010AC))
#define ADC0_QINR2_ENSI          0x00000040
#define ADC0_QINR2_EXTR          0x00000080
#define ADC0_QINR2_RF            0x00000020

// ADC0 Queue 4 Input Register
#define ADC0_QINR4             (*((uword volatile *) 0xF01010CC))
#define ADC0_QINR4_ENSI          0x00000040
#define ADC0_QINR4_EXTR          0x00000080
#define ADC0_QINR4_RF            0x00000020

// ADC0 Queue 0 Mode Register
#define ADC0_QMR0              (*((uword volatile *) 0xF0101080))
#define ADC0_QMR0_CEV            0x00000800
#define ADC0_QMR0_CLRV           0x00000100
#define ADC0_QMR0_ENTR           0x00000004
#define ADC0_QMR0_FLUSH          0x00000400
#define ADC0_QMR0_TREV           0x00000200

// ADC0 Queue 2 Mode Register
#define ADC0_QMR2              (*((uword volatile *) 0xF01010A0))
#define ADC0_QMR2_CEV            0x00000800
#define ADC0_QMR2_CLRV           0x00000100
#define ADC0_QMR2_ENTR           0x00000004
#define ADC0_QMR2_FLUSH          0x00000400
#define ADC0_QMR2_TREV           0x00000200

// ADC0 Queue 4 Mode Register
#define ADC0_QMR4              (*((uword volatile *) 0xF01010C0))
#define ADC0_QMR4_CEV            0x00000800
#define ADC0_QMR4_CLRV           0x00000100
#define ADC0_QMR4_ENTR           0x00000004
#define ADC0_QMR4_FLUSH          0x00000400
#define ADC0_QMR4_TREV           0x00000200

// ADC0 Queue 0 Status Register
#define ADC0_QSR0              (*((uword volatile *) 0xF0101084))
#define ADC0_QSR0_EMPTY          0x00000020
#define ADC0_QSR0_EV             0x00000100
#define ADC0_QSR0_REQGT          0x00000080

// ADC0 Queue 2 Status Register
#define ADC0_QSR2              (*((uword volatile *) 0xF01010A4))
#define ADC0_QSR2_EMPTY          0x00000020
#define ADC0_QSR2_EV             0x00000100
#define ADC0_QSR2_REQGT          0x00000080

// ADC0 Queue 4 Status Register
#define ADC0_QSR4              (*((uword volatile *) 0xF01010C4))
#define ADC0_QSR4_EMPTY          0x00000020
#define ADC0_QSR4_EV             0x00000100
#define ADC0_QSR4_REQGT          0x00000080

// ADC0 Result Control Register 0
#define ADC0_RCR0              (*((uword volatile *) 0xF0101140))
#define ADC0_RCR0_ENRI           0x00000010
#define ADC0_RCR0_FEN            0x00000020
#define ADC0_RCR0_WFR            0x00000040

// ADC0 Result Control Register 1
#define ADC0_RCR1              (*((uword volatile *) 0xF0101144))
#define ADC0_RCR1_ENRI           0x00000010
#define ADC0_RCR1_FEN            0x00000020
#define ADC0_RCR1_WFR            0x00000040

// ADC0 Result Control Register 10
#define ADC0_RCR10             (*((uword volatile *) 0xF0101168))
#define ADC0_RCR10_ENRI          0x00000010
#define ADC0_RCR10_FEN           0x00000020
#define ADC0_RCR10_WFR           0x00000040

// ADC0 Result Control Register 11
#define ADC0_RCR11             (*((uword volatile *) 0xF010116C))
#define ADC0_RCR11_ENRI          0x00000010
#define ADC0_RCR11_FEN           0x00000020
#define ADC0_RCR11_WFR           0x00000040

// ADC0 Result Control Register 12
#define ADC0_RCR12             (*((uword volatile *) 0xF0101170))
#define ADC0_RCR12_ENRI          0x00000010
#define ADC0_RCR12_FEN           0x00000020
#define ADC0_RCR12_WFR           0x00000040

// ADC0 Result Control Register 13
#define ADC0_RCR13             (*((uword volatile *) 0xF0101174))
#define ADC0_RCR13_ENRI          0x00000010
#define ADC0_RCR13_FEN           0x00000020
#define ADC0_RCR13_WFR           0x00000040

// ADC0 Result Control Register 14
#define ADC0_RCR14             (*((uword volatile *) 0xF0101178))
#define ADC0_RCR14_ENRI          0x00000010
#define ADC0_RCR14_FEN           0x00000020
#define ADC0_RCR14_WFR           0x00000040

// ADC0 Result Control Register 15
#define ADC0_RCR15             (*((uword volatile *) 0xF010117C))
#define ADC0_RCR15_ENRI          0x00000010
#define ADC0_RCR15_FEN           0x00000020
#define ADC0_RCR15_WFR           0x00000040

// ADC0 Result Control Register 2
#define ADC0_RCR2              (*((uword volatile *) 0xF0101148))
#define ADC0_RCR2_ENRI           0x00000010
#define ADC0_RCR2_FEN            0x00000020
#define ADC0_RCR2_WFR            0x00000040

// ADC0 Result Control Register 3
#define ADC0_RCR3              (*((uword volatile *) 0xF010114C))
#define ADC0_RCR3_ENRI           0x00000010
#define ADC0_RCR3_FEN            0x00000020
#define ADC0_RCR3_WFR            0x00000040

// ADC0 Result Control Register 4
#define ADC0_RCR4              (*((uword volatile *) 0xF0101150))
#define ADC0_RCR4_ENRI           0x00000010
#define ADC0_RCR4_FEN            0x00000020
#define ADC0_RCR4_WFR            0x00000040

// ADC0 Result Control Register 5
#define ADC0_RCR5              (*((uword volatile *) 0xF0101154))
#define ADC0_RCR5_ENRI           0x00000010
#define ADC0_RCR5_FEN            0x00000020
#define ADC0_RCR5_WFR            0x00000040

// ADC0 Result Control Register 6
#define ADC0_RCR6              (*((uword volatile *) 0xF0101158))
#define ADC0_RCR6_ENRI           0x00000010
#define ADC0_RCR6_FEN            0x00000020
#define ADC0_RCR6_WFR            0x00000040

// ADC0 Result Control Register 7
#define ADC0_RCR7              (*((uword volatile *) 0xF010115C))
#define ADC0_RCR7_ENRI           0x00000010
#define ADC0_RCR7_FEN            0x00000020
#define ADC0_RCR7_WFR            0x00000040

// ADC0 Result Control Register 8
#define ADC0_RCR8              (*((uword volatile *) 0xF0101160))
#define ADC0_RCR8_ENRI           0x00000010
#define ADC0_RCR8_FEN            0x00000020
#define ADC0_RCR8_WFR            0x00000040

// ADC0 Result Control Register 9
#define ADC0_RCR9              (*((uword volatile *) 0xF0101164))
#define ADC0_RCR9_ENRI           0x00000010
#define ADC0_RCR9_FEN            0x00000020
#define ADC0_RCR9_WFR            0x00000040

// ADC0 Result Register 0
#define ADC0_RESR0             (*((uword volatile *) 0xF0101180))
#define ADC0_RESR0_VF            0x80000000

// ADC0 Result Register 1
#define ADC0_RESR1             (*((uword volatile *) 0xF0101184))
#define ADC0_RESR1_VF            0x80000000

// ADC0 Result Register 10
#define ADC0_RESR10            (*((uword volatile *) 0xF01011A8))
#define ADC0_RESR10_VF           0x80000000

// ADC0 Result Register 11
#define ADC0_RESR11            (*((uword volatile *) 0xF01011AC))
#define ADC0_RESR11_VF           0x80000000

// ADC0 Result Register 12
#define ADC0_RESR12            (*((uword volatile *) 0xF01011B0))
#define ADC0_RESR12_VF           0x80000000

// ADC0 Result Register 13
#define ADC0_RESR13            (*((uword volatile *) 0xF01011B4))
#define ADC0_RESR13_VF           0x80000000

// ADC0 Result Register 14
#define ADC0_RESR14            (*((uword volatile *) 0xF01011B8))
#define ADC0_RESR14_VF           0x80000000

// ADC0 Result Register 15
#define ADC0_RESR15            (*((uword volatile *) 0xF01011BC))
#define ADC0_RESR15_VF           0x80000000

// ADC0 Result Register 2
#define ADC0_RESR2             (*((uword volatile *) 0xF0101188))
#define ADC0_RESR2_VF            0x80000000

// ADC0 Result Register 3
#define ADC0_RESR3             (*((uword volatile *) 0xF010118C))
#define ADC0_RESR3_VF            0x80000000

// ADC0 Result Register 4
#define ADC0_RESR4             (*((uword volatile *) 0xF0101190))
#define ADC0_RESR4_VF            0x80000000

// ADC0 Result Register 5
#define ADC0_RESR5             (*((uword volatile *) 0xF0101194))
#define ADC0_RESR5_VF            0x80000000

// ADC0 Result Register 6
#define ADC0_RESR6             (*((uword volatile *) 0xF0101198))
#define ADC0_RESR6_VF            0x80000000

// ADC0 Result Register 7
#define ADC0_RESR7             (*((uword volatile *) 0xF010119C))
#define ADC0_RESR7_VF            0x80000000

// ADC0 Result Register 8
#define ADC0_RESR8             (*((uword volatile *) 0xF01011A0))
#define ADC0_RESR8_VF            0x80000000

// ADC0 Result Register 9
#define ADC0_RESR9             (*((uword volatile *) 0xF01011A4))
#define ADC0_RESR9_VF            0x80000000

// ADC0 Result Register 0 for Debugging
#define ADC0_RESRD0            (*((uword volatile *) 0xF01011C0))
#define ADC0_RESRD0_VF           0x80000000

// ADC0 Result Register 1 for Debugging
#define ADC0_RESRD1            (*((uword volatile *) 0xF01011C4))
#define ADC0_RESRD1_VF           0x80000000

// ADC0 Result Register 10 for Debugging
#define ADC0_RESRD10           (*((uword volatile *) 0xF01011E8))
#define ADC0_RESRD10_VF          0x80000000

// ADC0 Result Register 11 for Debugging
#define ADC0_RESRD11           (*((uword volatile *) 0xF01011EC))
#define ADC0_RESRD11_VF          0x80000000

// ADC0 Result Register 12 for Debugging
#define ADC0_RESRD12           (*((uword volatile *) 0xF01011F0))
#define ADC0_RESRD12_VF          0x80000000

// ADC0 Result Register 13 for Debugging
#define ADC0_RESRD13           (*((uword volatile *) 0xF01011F4))
#define ADC0_RESRD13_VF          0x80000000

// ADC0 Result Register 14 for Debugging
#define ADC0_RESRD14           (*((uword volatile *) 0xF01011F8))
#define ADC0_RESRD14_VF          0x80000000

// ADC0 Result Register 15 for Debugging
#define ADC0_RESRD15           (*((uword volatile *) 0xF01011FC))
#define ADC0_RESRD15_VF          0x80000000

// ADC0 Result Register 2 for Debugging
#define ADC0_RESRD2            (*((uword volatile *) 0xF01011C8))
#define ADC0_RESRD2_VF           0x80000000

// ADC0 Result Register 3 for Debugging
#define ADC0_RESRD3            (*((uword volatile *) 0xF01011CC))
#define ADC0_RESRD3_VF           0x80000000

// ADC0 Result Register 4 for Debugging
#define ADC0_RESRD4            (*((uword volatile *) 0xF01011D0))
#define ADC0_RESRD4_VF           0x80000000

// ADC0 Result Register 5 for Debugging
#define ADC0_RESRD5            (*((uword volatile *) 0xF01011D4))
#define ADC0_RESRD5_VF           0x80000000

// ADC0 Result Register 6 for Debugging
#define ADC0_RESRD6            (*((uword volatile *) 0xF01011D8))
#define ADC0_RESRD6_VF           0x80000000

// ADC0 Result Register 7 for Debugging
#define ADC0_RESRD7            (*((uword volatile *) 0xF01011DC))
#define ADC0_RESRD7_VF           0x80000000

// ADC0 Result Register 8 for Debugging
#define ADC0_RESRD8            (*((uword volatile *) 0xF01011E0))
#define ADC0_RESRD8_VF           0x80000000

// ADC0 Result Register 9 for Debugging
#define ADC0_RESRD9            (*((uword volatile *) 0xF01011E4))
#define ADC0_RESRD9_VF           0x80000000

// ADC0 Result Node Pointer Register 0
#define ADC0_RNPR0             (*((uword volatile *) 0xF0101208))

// ADC0 Result Node Pointer Register 8
#define ADC0_RNPR8             (*((uword volatile *) 0xF010120C))

// ADC0 Request Source 0 Input Register
#define ADC0_RSIR0             (*((uword volatile *) 0xF0101010))
#define ADC0_RSIR0_FEN           0x00001000
#define ADC0_RSIR0_GTI           0x00000080
#define ADC0_RSIR0_REN           0x00002000
#define ADC0_RSIR0_TMEN          0x00000010
#define ADC0_RSIR0_TRI           0x00008000

// ADC0 Request Source 1 Input Register
#define ADC0_RSIR1             (*((uword volatile *) 0xF0101014))
#define ADC0_RSIR1_FEN           0x00001000
#define ADC0_RSIR1_GTI           0x00000080
#define ADC0_RSIR1_REN           0x00002000
#define ADC0_RSIR1_TMEN          0x00000010
#define ADC0_RSIR1_TRI           0x00008000

// ADC0 Request Source 2 Input Register
#define ADC0_RSIR2             (*((uword volatile *) 0xF0101018))
#define ADC0_RSIR2_FEN           0x00001000
#define ADC0_RSIR2_GTI           0x00000080
#define ADC0_RSIR2_REN           0x00002000
#define ADC0_RSIR2_TMEN          0x00000010
#define ADC0_RSIR2_TRI           0x00008000

// ADC0 Request Source 3 Input Register
#define ADC0_RSIR3             (*((uword volatile *) 0xF010101C))
#define ADC0_RSIR3_FEN           0x00001000
#define ADC0_RSIR3_GTI           0x00000080
#define ADC0_RSIR3_REN           0x00002000
#define ADC0_RSIR3_TMEN          0x00000010
#define ADC0_RSIR3_TRI           0x00008000

// ADC0 Request Source 4 Input Register
#define ADC0_RSIR4             (*((uword volatile *) 0xF0101020))
#define ADC0_RSIR4_FEN           0x00001000
#define ADC0_RSIR4_GTI           0x00000080
#define ADC0_RSIR4_REN           0x00002000
#define ADC0_RSIR4_TMEN          0x00000010
#define ADC0_RSIR4_TRI           0x00008000

// ADC0 Request Source Priority Register 0
#define ADC0_RSPR0             (*((uword volatile *) 0xF0101040))
#define ADC0_RSPR0_CSM0          0x00000008
#define ADC0_RSPR0_CSM1          0x00000080
#define ADC0_RSPR0_CSM2          0x00000800
#define ADC0_RSPR0_CSM3          0x00008000

// ADC0 Request Source Priority Register 4
#define ADC0_RSPR4             (*((uword volatile *) 0xF0101044))
#define ADC0_RSPR4_CSM4          0x00000008

// ADC0 Service Request Control Register 0
#define ADC0_SRC0              (*((uword volatile *) 0xF01013FC))
#define ADC0_SRC0_CLRR           0x00004000
#define ADC0_SRC0_SETR           0x00008000
#define ADC0_SRC0_SRE            0x00001000
#define ADC0_SRC0_SRR            0x00002000
#define ADC0_SRC0_TOS            0x00000400

// ADC0 Service Request Control Register 1
#define ADC0_SRC1              (*((uword volatile *) 0xF01013F8))
#define ADC0_SRC1_CLRR           0x00004000
#define ADC0_SRC1_SETR           0x00008000
#define ADC0_SRC1_SRE            0x00001000
#define ADC0_SRC1_SRR            0x00002000
#define ADC0_SRC1_TOS            0x00000400

// ADC0 Service Request Control Register 2
#define ADC0_SRC2              (*((uword volatile *) 0xF01013F4))
#define ADC0_SRC2_CLRR           0x00004000
#define ADC0_SRC2_SETR           0x00008000
#define ADC0_SRC2_SRE            0x00001000
#define ADC0_SRC2_SRR            0x00002000
#define ADC0_SRC2_TOS            0x00000400

// ADC0 Service Request Control Register 3
#define ADC0_SRC3              (*((uword volatile *) 0xF01013F0))
#define ADC0_SRC3_CLRR           0x00004000
#define ADC0_SRC3_SETR           0x00008000
#define ADC0_SRC3_SRE            0x00001000
#define ADC0_SRC3_SRR            0x00002000
#define ADC0_SRC3_TOS            0x00000400

// ADC0 Service Request Control Register 4
#define ADC0_SRC4              (*((uword volatile *) 0xF01013EC))
#define ADC0_SRC4_CLRR           0x00004000
#define ADC0_SRC4_SETR           0x00008000
#define ADC0_SRC4_SRE            0x00001000
#define ADC0_SRC4_SRR            0x00002000
#define ADC0_SRC4_TOS            0x00000400

// ADC0 Service Request Control Register 5
#define ADC0_SRC5              (*((uword volatile *) 0xF01013E8))
#define ADC0_SRC5_CLRR           0x00004000
#define ADC0_SRC5_SETR           0x00008000
#define ADC0_SRC5_SRE            0x00001000
#define ADC0_SRC5_SRR            0x00002000
#define ADC0_SRC5_TOS            0x00000400

// ADC0 Synchronization Control Register
#define ADC0_SYNCTR            (*((uword volatile *) 0xF0101048))
#define ADC0_SYNCTR_EVALR1       0x00000010
#define ADC0_SYNCTR_EVALR2       0x00000020
#define ADC0_SYNCTR_EVALR3       0x00000040

// ADC0 Valid Flag Register
#define ADC0_VFR               (*((uword volatile *) 0xF0101200))
#define ADC0_VFR_VF0             0x00000001
#define ADC0_VFR_VF1             0x00000002
#define ADC0_VFR_VF10            0x00000400
#define ADC0_VFR_VF11            0x00000800
#define ADC0_VFR_VF12            0x00001000
#define ADC0_VFR_VF13            0x00002000
#define ADC0_VFR_VF14            0x00004000
#define ADC0_VFR_VF15            0x00008000
#define ADC0_VFR_VF2             0x00000004
#define ADC0_VFR_VF3             0x00000008
#define ADC0_VFR_VF4             0x00000010
#define ADC0_VFR_VF5             0x00000020
#define ADC0_VFR_VF6             0x00000040
#define ADC0_VFR_VF7             0x00000080
#define ADC0_VFR_VF8             0x00000100
#define ADC0_VFR_VF9             0x00000200

// ADC1 Alias Register 0
#define ADC1_ALR0              (*((uword volatile *) 0xF0101610))

// ADC1 Access Protection Register
#define ADC1_APR               (*((uword volatile *) 0xF0101618))
#define ADC1_APR_ACCERR          0x00008000
#define ADC1_APR_RG0             0x00000001
#define ADC1_APR_RG1             0x00000002
#define ADC1_APR_RG2             0x00000004
#define ADC1_APR_RG3             0x00000008
#define ADC1_APR_RG4             0x00000010
#define ADC1_APR_RG5             0x00000020

// ADC1 Arbitration Slot Enable Register
#define ADC1_ASENR             (*((uword volatile *) 0xF010143C))
#define ADC1_ASENR_ASEN0         0x00000001
#define ADC1_ASENR_ASEN1         0x00000002
#define ADC1_ASENR_ASEN2         0x00000004
#define ADC1_ASENR_ASEN3         0x00000008
#define ADC1_ASENR_ASEN4         0x00000010

// ADC1 Channel 0 Control Register
#define ADC1_CHCTR0            (*((uword volatile *) 0xF0101500))
#define ADC1_CHCTR0_SYNC         0x00000080

// ADC1 Channel 1 Control Register
#define ADC1_CHCTR1            (*((uword volatile *) 0xF0101504))
#define ADC1_CHCTR1_SYNC         0x00000080

// ADC1 Channel 10 Control Register
#define ADC1_CHCTR10           (*((uword volatile *) 0xF0101528))
#define ADC1_CHCTR10_SYNC        0x00000080

// ADC1 Channel 11 Control Register
#define ADC1_CHCTR11           (*((uword volatile *) 0xF010152C))
#define ADC1_CHCTR11_SYNC        0x00000080

// ADC1 Channel 12 Control Register
#define ADC1_CHCTR12           (*((uword volatile *) 0xF0101530))
#define ADC1_CHCTR12_SYNC        0x00000080

// ADC1 Channel 13 Control Register
#define ADC1_CHCTR13           (*((uword volatile *) 0xF0101534))
#define ADC1_CHCTR13_SYNC        0x00000080

// ADC1 Channel 14 Control Register
#define ADC1_CHCTR14           (*((uword volatile *) 0xF0101538))
#define ADC1_CHCTR14_SYNC        0x00000080

// ADC1 Channel 15 Control Register
#define ADC1_CHCTR15           (*((uword volatile *) 0xF010153C))
#define ADC1_CHCTR15_SYNC        0x00000080

// ADC1 Channel 2 Control Register
#define ADC1_CHCTR2            (*((uword volatile *) 0xF0101508))
#define ADC1_CHCTR2_SYNC         0x00000080

// ADC1 Channel 3 Control Register
#define ADC1_CHCTR3            (*((uword volatile *) 0xF010150C))
#define ADC1_CHCTR3_SYNC         0x00000080

// ADC1 Channel 4 Control Register
#define ADC1_CHCTR4            (*((uword volatile *) 0xF0101510))
#define ADC1_CHCTR4_SYNC         0x00000080

// ADC1 Channel 5 Control Register
#define ADC1_CHCTR5            (*((uword volatile *) 0xF0101514))
#define ADC1_CHCTR5_SYNC         0x00000080

// ADC1 Channel 6 Control Register
#define ADC1_CHCTR6            (*((uword volatile *) 0xF0101518))
#define ADC1_CHCTR6_SYNC         0x00000080

// ADC1 Channel 7 Control Register
#define ADC1_CHCTR7            (*((uword volatile *) 0xF010151C))
#define ADC1_CHCTR7_SYNC         0x00000080

// ADC1 Channel 8 Control Register
#define ADC1_CHCTR8            (*((uword volatile *) 0xF0101520))
#define ADC1_CHCTR8_SYNC         0x00000080

// ADC1 Channel 9 Control Register
#define ADC1_CHCTR9            (*((uword volatile *) 0xF0101524))
#define ADC1_CHCTR9_SYNC         0x00000080

// ADC1 Channel Event Node Pointer Register 0
#define ADC1_CHENPR0           (*((uword volatile *) 0xF0101468))

// ADC1 Channel Event Node Pointer Register 8
#define ADC1_CHENPR8           (*((uword volatile *) 0xF010146C))

// ADC1 Channel Flag Clear Register
#define ADC1_CHFCR             (*((uword volatile *) 0xF0101464))
#define ADC1_CHFCR_CFC0          0x00000001
#define ADC1_CHFCR_CFC1          0x00000002
#define ADC1_CHFCR_CFC10         0x00000400
#define ADC1_CHFCR_CFC11         0x00000800
#define ADC1_CHFCR_CFC12         0x00001000
#define ADC1_CHFCR_CFC13         0x00002000
#define ADC1_CHFCR_CFC14         0x00004000
#define ADC1_CHFCR_CFC15         0x00008000
#define ADC1_CHFCR_CFC2          0x00000004
#define ADC1_CHFCR_CFC3          0x00000008
#define ADC1_CHFCR_CFC4          0x00000010
#define ADC1_CHFCR_CFC5          0x00000020
#define ADC1_CHFCR_CFC6          0x00000040
#define ADC1_CHFCR_CFC7          0x00000080
#define ADC1_CHFCR_CFC8          0x00000100
#define ADC1_CHFCR_CFC9          0x00000200

// ADC1 Channel Flag Register
#define ADC1_CHFR              (*((uword volatile *) 0xF0101460))
#define ADC1_CHFR_FC0            0x00000001
#define ADC1_CHFR_FC1            0x00000002
#define ADC1_CHFR_FC10           0x00000400
#define ADC1_CHFR_FC11           0x00000800
#define ADC1_CHFR_FC12           0x00001000
#define ADC1_CHFR_FC13           0x00002000
#define ADC1_CHFR_FC14           0x00004000
#define ADC1_CHFR_FC15           0x00008000
#define ADC1_CHFR_FC2            0x00000004
#define ADC1_CHFR_FC3            0x00000008
#define ADC1_CHFR_FC4            0x00000010
#define ADC1_CHFR_FC5            0x00000020
#define ADC1_CHFR_FC6            0x00000040
#define ADC1_CHFR_FC7            0x00000080
#define ADC1_CHFR_FC8            0x00000100
#define ADC1_CHFR_FC9            0x00000200

// ADC1 Conversion Request 1 Control Register
#define ADC1_CRCR1             (*((uword volatile *) 0xF0101490))
#define ADC1_CRCR1_CH0           0x00000001
#define ADC1_CRCR1_CH1           0x00000002
#define ADC1_CRCR1_CH10          0x00000400
#define ADC1_CRCR1_CH11          0x00000800
#define ADC1_CRCR1_CH12          0x00001000
#define ADC1_CRCR1_CH13          0x00002000
#define ADC1_CRCR1_CH14          0x00004000
#define ADC1_CRCR1_CH15          0x00008000
#define ADC1_CRCR1_CH2           0x00000004
#define ADC1_CRCR1_CH3           0x00000008
#define ADC1_CRCR1_CH4           0x00000010
#define ADC1_CRCR1_CH5           0x00000020
#define ADC1_CRCR1_CH6           0x00000040
#define ADC1_CRCR1_CH7           0x00000080
#define ADC1_CRCR1_CH8           0x00000100
#define ADC1_CRCR1_CH9           0x00000200

// ADC1 Conversion Request 3 Control Register
#define ADC1_CRCR3             (*((uword volatile *) 0xF01014B0))
#define ADC1_CRCR3_CH0           0x00000001
#define ADC1_CRCR3_CH1           0x00000002
#define ADC1_CRCR3_CH10          0x00000400
#define ADC1_CRCR3_CH11          0x00000800
#define ADC1_CRCR3_CH12          0x00001000
#define ADC1_CRCR3_CH13          0x00002000
#define ADC1_CRCR3_CH14          0x00004000
#define ADC1_CRCR3_CH15          0x00008000
#define ADC1_CRCR3_CH2           0x00000004
#define ADC1_CRCR3_CH3           0x00000008
#define ADC1_CRCR3_CH4           0x00000010
#define ADC1_CRCR3_CH5           0x00000020
#define ADC1_CRCR3_CH6           0x00000040
#define ADC1_CRCR3_CH7           0x00000080
#define ADC1_CRCR3_CH8           0x00000100
#define ADC1_CRCR3_CH9           0x00000200

// ADC1 Conversion Request 1 Mode Register
#define ADC1_CRMR1             (*((uword volatile *) 0xF0101498))
#define ADC1_CRMR1_CLRPND        0x00000100
#define ADC1_CRMR1_ENSI          0x00000008
#define ADC1_CRMR1_ENTR          0x00000004
#define ADC1_CRMR1_LDEV          0x00000200
#define ADC1_CRMR1_LDM           0x00000020
#define ADC1_CRMR1_REQGT         0x00000080
#define ADC1_CRMR1_SCAN          0x00000010

// ADC1 Conversion Request 3 Mode Register
#define ADC1_CRMR3             (*((uword volatile *) 0xF01014B8))
#define ADC1_CRMR3_CLRPND        0x00000100
#define ADC1_CRMR3_ENSI          0x00000008
#define ADC1_CRMR3_ENTR          0x00000004
#define ADC1_CRMR3_LDEV          0x00000200
#define ADC1_CRMR3_LDM           0x00000020
#define ADC1_CRMR3_REQGT         0x00000080
#define ADC1_CRMR3_SCAN          0x00000010

// ADC1 Conversion Request 1 Pending Register
#define ADC1_CRPR1             (*((uword volatile *) 0xF0101494))
#define ADC1_CRPR1_CHP0          0x00000001
#define ADC1_CRPR1_CHP1          0x00000002
#define ADC1_CRPR1_CHP10         0x00000400
#define ADC1_CRPR1_CHP11         0x00000800
#define ADC1_CRPR1_CHP12         0x00001000
#define ADC1_CRPR1_CHP13         0x00002000
#define ADC1_CRPR1_CHP14         0x00004000
#define ADC1_CRPR1_CHP15         0x00008000
#define ADC1_CRPR1_CHP2          0x00000004
#define ADC1_CRPR1_CHP3          0x00000008
#define ADC1_CRPR1_CHP4          0x00000010
#define ADC1_CRPR1_CHP5          0x00000020
#define ADC1_CRPR1_CHP6          0x00000040
#define ADC1_CRPR1_CHP7          0x00000080
#define ADC1_CRPR1_CHP8          0x00000100
#define ADC1_CRPR1_CHP9          0x00000200

// ADC1 Conversion Request 3 Pending Register
#define ADC1_CRPR3             (*((uword volatile *) 0xF01014B4))
#define ADC1_CRPR3_CHP0          0x00000001
#define ADC1_CRPR3_CHP1          0x00000002
#define ADC1_CRPR3_CHP10         0x00000400
#define ADC1_CRPR3_CHP11         0x00000800
#define ADC1_CRPR3_CHP12         0x00001000
#define ADC1_CRPR3_CHP13         0x00002000
#define ADC1_CRPR3_CHP14         0x00004000
#define ADC1_CRPR3_CHP15         0x00008000
#define ADC1_CRPR3_CHP2          0x00000004
#define ADC1_CRPR3_CHP3          0x00000008
#define ADC1_CRPR3_CHP4          0x00000010
#define ADC1_CRPR3_CHP5          0x00000020
#define ADC1_CRPR3_CHP6          0x00000040
#define ADC1_CRPR3_CHP7          0x00000080
#define ADC1_CRPR3_CHP8          0x00000100
#define ADC1_CRPR3_CHP9          0x00000200

// ADC1 External Multiplexer Control Register
#define ADC1_EMCTR             (*((uword volatile *) 0xF0101620))
#define ADC1_EMCTR_EMUXEN        0x00800000
#define ADC1_EMCTR_SCANEN        0x00400000
#define ADC1_EMCTR_TROEN         0x00200000

// ADC1 Event Flag Clear Register
#define ADC1_EVFCR             (*((uword volatile *) 0xF0101474))
#define ADC1_EVFCR_CFR0          0x00000001
#define ADC1_EVFCR_CFR1          0x00000002
#define ADC1_EVFCR_CFR10         0x00000400
#define ADC1_EVFCR_CFR11         0x00000800
#define ADC1_EVFCR_CFR12         0x00001000
#define ADC1_EVFCR_CFR13         0x00002000
#define ADC1_EVFCR_CFR14         0x00004000
#define ADC1_EVFCR_CFR15         0x00008000
#define ADC1_EVFCR_CFR2          0x00000004
#define ADC1_EVFCR_CFR3          0x00000008
#define ADC1_EVFCR_CFR4          0x00000010
#define ADC1_EVFCR_CFR5          0x00000020
#define ADC1_EVFCR_CFR6          0x00000040
#define ADC1_EVFCR_CFR7          0x00000080
#define ADC1_EVFCR_CFR8          0x00000100
#define ADC1_EVFCR_CFR9          0x00000200
#define ADC1_EVFCR_CFS0          0x00010000
#define ADC1_EVFCR_CFS1          0x00020000
#define ADC1_EVFCR_CFS2          0x00040000
#define ADC1_EVFCR_CFS3          0x00080000
#define ADC1_EVFCR_CFS4          0x00100000

// ADC1 Event Flag Register
#define ADC1_EVFR              (*((uword volatile *) 0xF0101470))
#define ADC1_EVFR_FR0            0x00000001
#define ADC1_EVFR_FR1            0x00000002
#define ADC1_EVFR_FR10           0x00000400
#define ADC1_EVFR_FR11           0x00000800
#define ADC1_EVFR_FR12           0x00001000
#define ADC1_EVFR_FR13           0x00002000
#define ADC1_EVFR_FR14           0x00004000
#define ADC1_EVFR_FR15           0x00008000
#define ADC1_EVFR_FR2            0x00000004
#define ADC1_EVFR_FR3            0x00000008
#define ADC1_EVFR_FR4            0x00000010
#define ADC1_EVFR_FR5            0x00000020
#define ADC1_EVFR_FR6            0x00000040
#define ADC1_EVFR_FR7            0x00000080
#define ADC1_EVFR_FR8            0x00000100
#define ADC1_EVFR_FR9            0x00000200
#define ADC1_EVFR_FS0            0x00010000
#define ADC1_EVFR_FS1            0x00020000
#define ADC1_EVFR_FS2            0x00040000
#define ADC1_EVFR_FS3            0x00080000
#define ADC1_EVFR_FS4            0x00100000
#define ADC1_EVFR_GFS0           0x01000000
#define ADC1_EVFR_GFS1           0x02000000
#define ADC1_EVFR_GFS2           0x04000000
#define ADC1_EVFR_GFS3           0x08000000
#define ADC1_EVFR_GFS4           0x10000000

// ADC1 Event Node Pointer Register
#define ADC1_EVNPR             (*((uword volatile *) 0xF0101478))

// ADC1 Global Configuration Register
#define ADC1_GLOBCFG           (*((uword volatile *) 0xF0101434))
#define ADC1_GLOBCFG_DPCAL       0x00000040
#define ADC1_GLOBCFG_MTM7        0x00000010
#define ADC1_GLOBCFG_SUCAL       0x00000020

// ADC1 Global Control Register
#define ADC1_GLOBCTR           (*((uword volatile *) 0xF0101430))
#define ADC1_GLOBCTR_ARBM        0x00008000

// ADC1 Global Status Register
#define ADC1_GLOBSTR           (*((uword volatile *) 0xF0101438))
#define ADC1_GLOBSTR_BUSY        0x00000001
#define ADC1_GLOBSTR_CAL         0x00000004
#define ADC1_GLOBSTR_SAMPLE      0x00000002
#define ADC1_GLOBSTR_SYNRUN      0x00000400

// ADC1 Input Class Register 0
#define ADC1_INPCR0            (*((uword volatile *) 0xF0101450))

// ADC1 Input Class Register 1
#define ADC1_INPCR1            (*((uword volatile *) 0xF0101454))

// ADC1 Input Class Register 2
#define ADC1_INPCR2            (*((uword volatile *) 0xF0101458))

// ADC1 Input Class Register 3
#define ADC1_INPCR3            (*((uword volatile *) 0xF010145C))

// ADC1 Interrupt Activation Register
#define ADC1_INTR              (*((uword volatile *) 0xF0101604))
#define ADC1_INTR_SISR0          0x00000001
#define ADC1_INTR_SISR1          0x00000002
#define ADC1_INTR_SISR2          0x00000004
#define ADC1_INTR_SISR3          0x00000008
#define ADC1_INTR_SISR4          0x00000010
#define ADC1_INTR_SISR5          0x00000020
#define ADC1_INTR_SISR6          0x00000040
#define ADC1_INTR_SISR7          0x00000080

// ADC1 Limit Check Boundary Register 0
#define ADC1_LCBR0             (*((uword volatile *) 0xF01014F0))

// ADC1 Limit Check Boundary Register 1
#define ADC1_LCBR1             (*((uword volatile *) 0xF01014F4))

// ADC1 Limit Check Boundary Register 2
#define ADC1_LCBR2             (*((uword volatile *) 0xF01014F8))

// ADC1 Limit Check Boundary Register 3
#define ADC1_LCBR3             (*((uword volatile *) 0xF01014FC))

// ADC1 Queue 0 Register 0
#define ADC1_Q0R0              (*((uword volatile *) 0xF0101488))
#define ADC1_Q0R0_ENSI           0x00000040
#define ADC1_Q0R0_EXTR           0x00000080
#define ADC1_Q0R0_RF             0x00000020
#define ADC1_Q0R0_V              0x00000100

// ADC1 Queue 2 Register 0
#define ADC1_Q0R2              (*((uword volatile *) 0xF01014A8))
#define ADC1_Q0R2_ENSI           0x00000040
#define ADC1_Q0R2_EXTR           0x00000080
#define ADC1_Q0R2_RF             0x00000020
#define ADC1_Q0R2_V              0x00000100

// ADC1 Queue 4 Register 0
#define ADC1_Q0R4              (*((uword volatile *) 0xF01014C8))
#define ADC1_Q0R4_ENSI           0x00000040
#define ADC1_Q0R4_EXTR           0x00000080
#define ADC1_Q0R4_RF             0x00000020
#define ADC1_Q0R4_V              0x00000100

// ADC1 Queue 0 Backup Register
#define ADC1_QBUR0             (*((uword volatile *) 0xF010148C))
#define ADC1_QBUR0_ENSI          0x00000040
#define ADC1_QBUR0_EXTR          0x00000080
#define ADC1_QBUR0_RF            0x00000020
#define ADC1_QBUR0_V             0x00000100

// ADC1 Queue 2 Backup Register
#define ADC1_QBUR2             (*((uword volatile *) 0xF01014AC))
#define ADC1_QBUR2_ENSI          0x00000040
#define ADC1_QBUR2_EXTR          0x00000080
#define ADC1_QBUR2_RF            0x00000020
#define ADC1_QBUR2_V             0x00000100

// ADC1 Queue 4 Backup Register
#define ADC1_QBUR4             (*((uword volatile *) 0xF01014CC))
#define ADC1_QBUR4_ENSI          0x00000040
#define ADC1_QBUR4_EXTR          0x00000080
#define ADC1_QBUR4_RF            0x00000020
#define ADC1_QBUR4_V             0x00000100

// ADC1 Queue 0 Input Register
#define ADC1_QINR0             (*((uword volatile *) 0xF010148C))
#define ADC1_QINR0_ENSI          0x00000040
#define ADC1_QINR0_EXTR          0x00000080
#define ADC1_QINR0_RF            0x00000020

// ADC1 Queue 2 Input Register
#define ADC1_QINR2             (*((uword volatile *) 0xF01014AC))
#define ADC1_QINR2_ENSI          0x00000040
#define ADC1_QINR2_EXTR          0x00000080
#define ADC1_QINR2_RF            0x00000020

// ADC1 Queue 4 Input Register
#define ADC1_QINR4             (*((uword volatile *) 0xF01014CC))
#define ADC1_QINR4_ENSI          0x00000040
#define ADC1_QINR4_EXTR          0x00000080
#define ADC1_QINR4_RF            0x00000020

// ADC1 Queue 0 Mode Register
#define ADC1_QMR0              (*((uword volatile *) 0xF0101480))
#define ADC1_QMR0_CEV            0x00000800
#define ADC1_QMR0_CLRV           0x00000100
#define ADC1_QMR0_ENTR           0x00000004
#define ADC1_QMR0_FLUSH          0x00000400
#define ADC1_QMR0_TREV           0x00000200

// ADC1 Queue 2 Mode Register
#define ADC1_QMR2              (*((uword volatile *) 0xF01014A0))
#define ADC1_QMR2_CEV            0x00000800
#define ADC1_QMR2_CLRV           0x00000100
#define ADC1_QMR2_ENTR           0x00000004
#define ADC1_QMR2_FLUSH          0x00000400
#define ADC1_QMR2_TREV           0x00000200

// ADC1 Queue 4 Mode Register
#define ADC1_QMR4              (*((uword volatile *) 0xF01014C0))
#define ADC1_QMR4_CEV            0x00000800
#define ADC1_QMR4_CLRV           0x00000100
#define ADC1_QMR4_ENTR           0x00000004
#define ADC1_QMR4_FLUSH          0x00000400
#define ADC1_QMR4_TREV           0x00000200

// ADC1 Queue 0 Status Register
#define ADC1_QSR0              (*((uword volatile *) 0xF0101484))
#define ADC1_QSR0_EMPTY          0x00000020
#define ADC1_QSR0_EV             0x00000100
#define ADC1_QSR0_REQGT          0x00000080

// ADC1 Queue 2 Status Register
#define ADC1_QSR2              (*((uword volatile *) 0xF01014A4))
#define ADC1_QSR2_EMPTY          0x00000020
#define ADC1_QSR2_EV             0x00000100
#define ADC1_QSR2_REQGT          0x00000080

// ADC1 Queue 4 Status Register
#define ADC1_QSR4              (*((uword volatile *) 0xF01014C4))
#define ADC1_QSR4_EMPTY          0x00000020
#define ADC1_QSR4_EV             0x00000100
#define ADC1_QSR4_REQGT          0x00000080

// ADC1 Result Control Register 0
#define ADC1_RCR0              (*((uword volatile *) 0xF0101540))
#define ADC1_RCR0_ENRI           0x00000010
#define ADC1_RCR0_FEN            0x00000020
#define ADC1_RCR0_WFR            0x00000040

// ADC1 Result Control Register 1
#define ADC1_RCR1              (*((uword volatile *) 0xF0101544))
#define ADC1_RCR1_ENRI           0x00000010
#define ADC1_RCR1_FEN            0x00000020
#define ADC1_RCR1_WFR            0x00000040

// ADC1 Result Control Register 10
#define ADC1_RCR10             (*((uword volatile *) 0xF0101568))
#define ADC1_RCR10_ENRI          0x00000010
#define ADC1_RCR10_FEN           0x00000020
#define ADC1_RCR10_WFR           0x00000040

// ADC1 Result Control Register 11
#define ADC1_RCR11             (*((uword volatile *) 0xF010156C))
#define ADC1_RCR11_ENRI          0x00000010
#define ADC1_RCR11_FEN           0x00000020
#define ADC1_RCR11_WFR           0x00000040

// ADC1 Result Control Register 12
#define ADC1_RCR12             (*((uword volatile *) 0xF0101570))
#define ADC1_RCR12_ENRI          0x00000010
#define ADC1_RCR12_FEN           0x00000020
#define ADC1_RCR12_WFR           0x00000040

// ADC1 Result Control Register 13
#define ADC1_RCR13             (*((uword volatile *) 0xF0101574))
#define ADC1_RCR13_ENRI          0x00000010
#define ADC1_RCR13_FEN           0x00000020
#define ADC1_RCR13_WFR           0x00000040

// ADC1 Result Control Register 14
#define ADC1_RCR14             (*((uword volatile *) 0xF0101578))
#define ADC1_RCR14_ENRI          0x00000010
#define ADC1_RCR14_FEN           0x00000020
#define ADC1_RCR14_WFR           0x00000040

// ADC1 Result Control Register 15
#define ADC1_RCR15             (*((uword volatile *) 0xF010157C))
#define ADC1_RCR15_ENRI          0x00000010
#define ADC1_RCR15_FEN           0x00000020
#define ADC1_RCR15_WFR           0x00000040

// ADC1 Result Control Register 2
#define ADC1_RCR2              (*((uword volatile *) 0xF0101548))
#define ADC1_RCR2_ENRI           0x00000010
#define ADC1_RCR2_FEN            0x00000020
#define ADC1_RCR2_WFR            0x00000040

// ADC1 Result Control Register 3
#define ADC1_RCR3              (*((uword volatile *) 0xF010154C))
#define ADC1_RCR3_ENRI           0x00000010
#define ADC1_RCR3_FEN            0x00000020
#define ADC1_RCR3_WFR            0x00000040

// ADC1 Result Control Register 4
#define ADC1_RCR4              (*((uword volatile *) 0xF0101550))
#define ADC1_RCR4_ENRI           0x00000010
#define ADC1_RCR4_FEN            0x00000020
#define ADC1_RCR4_WFR            0x00000040

// ADC1 Result Control Register 5
#define ADC1_RCR5              (*((uword volatile *) 0xF0101554))
#define ADC1_RCR5_ENRI           0x00000010
#define ADC1_RCR5_FEN            0x00000020
#define ADC1_RCR5_WFR            0x00000040

// ADC1 Result Control Register 6
#define ADC1_RCR6              (*((uword volatile *) 0xF0101558))
#define ADC1_RCR6_ENRI           0x00000010
#define ADC1_RCR6_FEN            0x00000020
#define ADC1_RCR6_WFR            0x00000040

// ADC1 Result Control Register 7
#define ADC1_RCR7              (*((uword volatile *) 0xF010155C))
#define ADC1_RCR7_ENRI           0x00000010
#define ADC1_RCR7_FEN            0x00000020
#define ADC1_RCR7_WFR            0x00000040

// ADC1 Result Control Register 8
#define ADC1_RCR8              (*((uword volatile *) 0xF0101560))
#define ADC1_RCR8_ENRI           0x00000010
#define ADC1_RCR8_FEN            0x00000020
#define ADC1_RCR8_WFR            0x00000040

// ADC1 Result Control Register 9
#define ADC1_RCR9              (*((uword volatile *) 0xF0101564))
#define ADC1_RCR9_ENRI           0x00000010
#define ADC1_RCR9_FEN            0x00000020
#define ADC1_RCR9_WFR            0x00000040

// ADC1 Result Register 0
#define ADC1_RESR0             (*((uword volatile *) 0xF0101580))
#define ADC1_RESR0_VF            0x80000000

// ADC1 Result Register 1
#define ADC1_RESR1             (*((uword volatile *) 0xF0101584))
#define ADC1_RESR1_VF            0x80000000

// ADC1 Result Register 10
#define ADC1_RESR10            (*((uword volatile *) 0xF01015A8))
#define ADC1_RESR10_VF           0x80000000

// ADC1 Result Register 11
#define ADC1_RESR11            (*((uword volatile *) 0xF01015AC))
#define ADC1_RESR11_VF           0x80000000

// ADC1 Result Register 12
#define ADC1_RESR12            (*((uword volatile *) 0xF01015B0))
#define ADC1_RESR12_VF           0x80000000

// ADC1 Result Register 13
#define ADC1_RESR13            (*((uword volatile *) 0xF01015B4))
#define ADC1_RESR13_VF           0x80000000

// ADC1 Result Register 14
#define ADC1_RESR14            (*((uword volatile *) 0xF01015B8))
#define ADC1_RESR14_VF           0x80000000

// ADC1 Result Register 15
#define ADC1_RESR15            (*((uword volatile *) 0xF01015BC))
#define ADC1_RESR15_VF           0x80000000

// ADC1 Result Register 2
#define ADC1_RESR2             (*((uword volatile *) 0xF0101588))
#define ADC1_RESR2_VF            0x80000000

// ADC1 Result Register 3
#define ADC1_RESR3             (*((uword volatile *) 0xF010158C))
#define ADC1_RESR3_VF            0x80000000

// ADC1 Result Register 4
#define ADC1_RESR4             (*((uword volatile *) 0xF0101590))
#define ADC1_RESR4_VF            0x80000000

// ADC1 Result Register 5
#define ADC1_RESR5             (*((uword volatile *) 0xF0101594))
#define ADC1_RESR5_VF            0x80000000

// ADC1 Result Register 6
#define ADC1_RESR6             (*((uword volatile *) 0xF0101598))
#define ADC1_RESR6_VF            0x80000000

// ADC1 Result Register 7
#define ADC1_RESR7             (*((uword volatile *) 0xF010159C))
#define ADC1_RESR7_VF            0x80000000

// ADC1 Result Register 8
#define ADC1_RESR8             (*((uword volatile *) 0xF01015A0))
#define ADC1_RESR8_VF            0x80000000

// ADC1 Result Register 9
#define ADC1_RESR9             (*((uword volatile *) 0xF01015A4))
#define ADC1_RESR9_VF            0x80000000

// ADC1 Result Register 0 for Debugging
#define ADC1_RESRD0            (*((uword volatile *) 0xF01015C0))
#define ADC1_RESRD0_VF           0x80000000

// ADC1 Result Register 1 for Debugging
#define ADC1_RESRD1            (*((uword volatile *) 0xF01015C4))
#define ADC1_RESRD1_VF           0x80000000

// ADC1 Result Register 10 for Debugging
#define ADC1_RESRD10           (*((uword volatile *) 0xF01015E8))
#define ADC1_RESRD10_VF          0x80000000

// ADC1 Result Register 11 for Debugging
#define ADC1_RESRD11           (*((uword volatile *) 0xF01015EC))
#define ADC1_RESRD11_VF          0x80000000

// ADC1 Result Register 12 for Debugging
#define ADC1_RESRD12           (*((uword volatile *) 0xF01015F0))
#define ADC1_RESRD12_VF          0x80000000

// ADC1 Result Register 13 for Debugging
#define ADC1_RESRD13           (*((uword volatile *) 0xF01015F4))
#define ADC1_RESRD13_VF          0x80000000

// ADC1 Result Register 14 for Debugging
#define ADC1_RESRD14           (*((uword volatile *) 0xF01015F8))
#define ADC1_RESRD14_VF          0x80000000

// ADC1 Result Register 15 for Debugging
#define ADC1_RESRD15           (*((uword volatile *) 0xF01015FC))
#define ADC1_RESRD15_VF          0x80000000

// ADC1 Result Register 2 for Debugging
#define ADC1_RESRD2            (*((uword volatile *) 0xF01015C8))
#define ADC1_RESRD2_VF           0x80000000

// ADC1 Result Register 3 for Debugging
#define ADC1_RESRD3            (*((uword volatile *) 0xF01015CC))
#define ADC1_RESRD3_VF           0x80000000

// ADC1 Result Register 4 for Debugging
#define ADC1_RESRD4            (*((uword volatile *) 0xF01015D0))
#define ADC1_RESRD4_VF           0x80000000

// ADC1 Result Register 5 for Debugging
#define ADC1_RESRD5            (*((uword volatile *) 0xF01015D4))
#define ADC1_RESRD5_VF           0x80000000

// ADC1 Result Register 6 for Debugging
#define ADC1_RESRD6            (*((uword volatile *) 0xF01015D8))
#define ADC1_RESRD6_VF           0x80000000

// ADC1 Result Register 7 for Debugging
#define ADC1_RESRD7            (*((uword volatile *) 0xF01015DC))
#define ADC1_RESRD7_VF           0x80000000

// ADC1 Result Register 8 for Debugging
#define ADC1_RESRD8            (*((uword volatile *) 0xF01015E0))
#define ADC1_RESRD8_VF           0x80000000

// ADC1 Result Register 9 for Debugging
#define ADC1_RESRD9            (*((uword volatile *) 0xF01015E4))
#define ADC1_RESRD9_VF           0x80000000

// ADC1 Result Node Pointer Register 0
#define ADC1_RNPR0             (*((uword volatile *) 0xF0101608))

// ADC1 Result Node Pointer Register 8
#define ADC1_RNPR8             (*((uword volatile *) 0xF010160C))

// ADC1 Request Source 0 Input Register
#define ADC1_RSIR0             (*((uword volatile *) 0xF0101410))
#define ADC1_RSIR0_FEN           0x00001000
#define ADC1_RSIR0_GTI           0x00000080
#define ADC1_RSIR0_REN           0x00002000
#define ADC1_RSIR0_TMEN          0x00000010
#define ADC1_RSIR0_TRI           0x00008000

// ADC1 Request Source 1 Input Register
#define ADC1_RSIR1             (*((uword volatile *) 0xF0101414))
#define ADC1_RSIR1_FEN           0x00001000
#define ADC1_RSIR1_GTI           0x00000080
#define ADC1_RSIR1_REN           0x00002000
#define ADC1_RSIR1_TMEN          0x00000010
#define ADC1_RSIR1_TRI           0x00008000

// ADC1 Request Source 2 Input Register
#define ADC1_RSIR2             (*((uword volatile *) 0xF0101418))
#define ADC1_RSIR2_FEN           0x00001000
#define ADC1_RSIR2_GTI           0x00000080
#define ADC1_RSIR2_REN           0x00002000
#define ADC1_RSIR2_TMEN          0x00000010
#define ADC1_RSIR2_TRI           0x00008000

// ADC1 Request Source 3 Input Register
#define ADC1_RSIR3             (*((uword volatile *) 0xF010141C))
#define ADC1_RSIR3_FEN           0x00001000
#define ADC1_RSIR3_GTI           0x00000080
#define ADC1_RSIR3_REN           0x00002000
#define ADC1_RSIR3_TMEN          0x00000010
#define ADC1_RSIR3_TRI           0x00008000

// ADC1 Request Source 4 Input Register
#define ADC1_RSIR4             (*((uword volatile *) 0xF0101420))
#define ADC1_RSIR4_FEN           0x00001000
#define ADC1_RSIR4_GTI           0x00000080
#define ADC1_RSIR4_REN           0x00002000
#define ADC1_RSIR4_TMEN          0x00000010
#define ADC1_RSIR4_TRI           0x00008000

// ADC1 Request Source Priority Register 0
#define ADC1_RSPR0             (*((uword volatile *) 0xF0101440))
#define ADC1_RSPR0_CSM0          0x00000008
#define ADC1_RSPR0_CSM1          0x00000080
#define ADC1_RSPR0_CSM2          0x00000800
#define ADC1_RSPR0_CSM3          0x00008000

// ADC1 Request Source Priority Register 4
#define ADC1_RSPR4             (*((uword volatile *) 0xF0101444))
#define ADC1_RSPR4_CSM4          0x00000008

// ADC1 Synchronization Control Register
#define ADC1_SYNCTR            (*((uword volatile *) 0xF0101448))
#define ADC1_SYNCTR_EVALR1       0x00000010
#define ADC1_SYNCTR_EVALR2       0x00000020
#define ADC1_SYNCTR_EVALR3       0x00000040

// ADC1 Valid Flag Register
#define ADC1_VFR               (*((uword volatile *) 0xF0101600))
#define ADC1_VFR_VF0             0x00000001
#define ADC1_VFR_VF1             0x00000002
#define ADC1_VFR_VF10            0x00000400
#define ADC1_VFR_VF11            0x00000800
#define ADC1_VFR_VF12            0x00001000
#define ADC1_VFR_VF13            0x00002000
#define ADC1_VFR_VF14            0x00004000
#define ADC1_VFR_VF15            0x00008000
#define ADC1_VFR_VF2             0x00000004
#define ADC1_VFR_VF3             0x00000008
#define ADC1_VFR_VF4             0x00000010
#define ADC1_VFR_VF5             0x00000020
#define ADC1_VFR_VF6             0x00000040
#define ADC1_VFR_VF7             0x00000080
#define ADC1_VFR_VF8             0x00000100
#define ADC1_VFR_VF9             0x00000200

// ASC0 Baud Rate Timer/Reload Register
#define ASC0_BG                (*((uword volatile *) 0xF0000A14))

// ASC0 Clock Control Register
#define ASC0_CLC               (*((uword volatile *) 0xF0000A00))
#define ASC0_CLC_DISR            ((T_Reg32 *) 0xF0000A00)->bit0
#define ASC0_CLC_DISS            ((T_Reg32 *) 0xF0000A00)->bit1
#define ASC0_CLC_EDIS            ((T_Reg32 *) 0xF0000A00)->bit3
#define ASC0_CLC_FSOE            ((T_Reg32 *) 0xF0000A00)->bit5
#define ASC0_CLC_SBWE            ((T_Reg32 *) 0xF0000A00)->bit4
#define ASC0_CLC_SPEN            ((T_Reg32 *) 0xF0000A00)->bit2

// ASC0 Control Register
#define ASC0_CON               (*((uword volatile *) 0xF0000A10))
#define ASC0_CON_BRS             ((T_Reg32 *) 0xF0000A10)->bit13
#define ASC0_CON_FDE             ((T_Reg32 *) 0xF0000A10)->bit11
#define ASC0_CON_FE              ((T_Reg32 *) 0xF0000A10)->bit9
#define ASC0_CON_FEN             ((T_Reg32 *) 0xF0000A10)->bit6
#define ASC0_CON_LB              ((T_Reg32 *) 0xF0000A10)->bit14
#define ASC0_CON_ODD             ((T_Reg32 *) 0xF0000A10)->bit12
#define ASC0_CON_OE              ((T_Reg32 *) 0xF0000A10)->bit10
#define ASC0_CON_OEN             ((T_Reg32 *) 0xF0000A10)->bit7
#define ASC0_CON_PE              ((T_Reg32 *) 0xF0000A10)->bit8
#define ASC0_CON_PEN             ((T_Reg32 *) 0xF0000A10)->bit5
#define ASC0_CON_R               ((T_Reg32 *) 0xF0000A10)->bit15
#define ASC0_CON_REN             ((T_Reg32 *) 0xF0000A10)->bit4
#define ASC0_CON_STP             ((T_Reg32 *) 0xF0000A10)->bit3

// ASC0 Error Interrupt Service Request Control Register
#define ASC0_ESRC              (*((uword volatile *) 0xF0000AF8))
#define ASC0_ESRC_CLRR           ((T_Reg32 *) 0xF0000AF8)->bit14
#define ASC0_ESRC_SETR           ((T_Reg32 *) 0xF0000AF8)->bit15
#define ASC0_ESRC_SRE            ((T_Reg32 *) 0xF0000AF8)->bit12
#define ASC0_ESRC_SRR            ((T_Reg32 *) 0xF0000AF8)->bit13
#define ASC0_ESRC_TOS            ((T_Reg32 *) 0xF0000AF8)->bit10

// ASC0 Fractional Divider Register
#define ASC0_FDV               (*((uword volatile *) 0xF0000A18))

// ASC0 Module Identification Register
#define ASC0_ID                (*((uword volatile *) 0xF0000A08))

// ASC0 Peripheral Input Select Register
#define ASC0_PISEL             (*((uword volatile *) 0xF0000A04))
#define ASC0_PISEL_RIS           ((T_Reg32 *) 0xF0000A04)->bit0

// ASC0 Receive Buffer Register
#define ASC0_RBUF              (*((uword volatile *) 0xF0000A24))

// ASC0 Receive Interrupt Service Request Control Register
#define ASC0_RSRC              (*((uword volatile *) 0xF0000AF4))
#define ASC0_RSRC_CLRR           ((T_Reg32 *) 0xF0000AF4)->bit14
#define ASC0_RSRC_SETR           ((T_Reg32 *) 0xF0000AF4)->bit15
#define ASC0_RSRC_SRE            ((T_Reg32 *) 0xF0000AF4)->bit12
#define ASC0_RSRC_SRR            ((T_Reg32 *) 0xF0000AF4)->bit13
#define ASC0_RSRC_TOS            ((T_Reg32 *) 0xF0000AF4)->bit10

// ASC0 Transmit Buffer Interrupt Service Request Control Register
#define ASC0_TBSRC             (*((uword volatile *) 0xF0000AFC))
#define ASC0_TBSRC_CLRR          ((T_Reg32 *) 0xF0000AFC)->bit14
#define ASC0_TBSRC_SETR          ((T_Reg32 *) 0xF0000AFC)->bit15
#define ASC0_TBSRC_SRE           ((T_Reg32 *) 0xF0000AFC)->bit12
#define ASC0_TBSRC_SRR           ((T_Reg32 *) 0xF0000AFC)->bit13
#define ASC0_TBSRC_TOS           ((T_Reg32 *) 0xF0000AFC)->bit10

// ASC0 Transmit Buffer Register
#define ASC0_TBUF              (*((uword volatile *) 0xF0000A20))

// ASC0 Transmit Interrupt Service Request Control Register
#define ASC0_TSRC              (*((uword volatile *) 0xF0000AF0))
#define ASC0_TSRC_CLRR           ((T_Reg32 *) 0xF0000AF0)->bit14
#define ASC0_TSRC_SETR           ((T_Reg32 *) 0xF0000AF0)->bit15
#define ASC0_TSRC_SRE            ((T_Reg32 *) 0xF0000AF0)->bit12
#define ASC0_TSRC_SRR            ((T_Reg32 *) 0xF0000AF0)->bit13
#define ASC0_TSRC_TOS            ((T_Reg32 *) 0xF0000AF0)->bit10

// ASC0 Write Hardware Bits Control Register
#define ASC0_WHBCON            (*((uword volatile *) 0xF0000A50))
#define ASC0_WHBCON_CLRFE        ((T_Reg32 *) 0xF0000A50)->bit9
#define ASC0_WHBCON_CLROE        ((T_Reg32 *) 0xF0000A50)->bit10
#define ASC0_WHBCON_CLRPE        ((T_Reg32 *) 0xF0000A50)->bit8
#define ASC0_WHBCON_CLRREN       ((T_Reg32 *) 0xF0000A50)->bit4
#define ASC0_WHBCON_SETFE        ((T_Reg32 *) 0xF0000A50)->bit12
#define ASC0_WHBCON_SETOE        ((T_Reg32 *) 0xF0000A50)->bit13
#define ASC0_WHBCON_SETPE        ((T_Reg32 *) 0xF0000A50)->bit11
#define ASC0_WHBCON_SETREN       ((T_Reg32 *) 0xF0000A50)->bit5

// ASC1 Baud Rate Timer/Reload Register
#define ASC1_BG                (*((uword volatile *) 0xF0000B14))

// ASC1 Control Register
#define ASC1_CON               (*((uword volatile *) 0xF0000B10))
#define ASC1_CON_BRS             ((T_Reg32 *) 0xF0000B10)->bit13
#define ASC1_CON_FDE             ((T_Reg32 *) 0xF0000B10)->bit11
#define ASC1_CON_FE              ((T_Reg32 *) 0xF0000B10)->bit9
#define ASC1_CON_FEN             ((T_Reg32 *) 0xF0000B10)->bit6
#define ASC1_CON_LB              ((T_Reg32 *) 0xF0000B10)->bit14
#define ASC1_CON_ODD             ((T_Reg32 *) 0xF0000B10)->bit12
#define ASC1_CON_OE              ((T_Reg32 *) 0xF0000B10)->bit10
#define ASC1_CON_OEN             ((T_Reg32 *) 0xF0000B10)->bit7
#define ASC1_CON_PE              ((T_Reg32 *) 0xF0000B10)->bit8
#define ASC1_CON_PEN             ((T_Reg32 *) 0xF0000B10)->bit5
#define ASC1_CON_R               ((T_Reg32 *) 0xF0000B10)->bit15
#define ASC1_CON_REN             ((T_Reg32 *) 0xF0000B10)->bit4
#define ASC1_CON_STP             ((T_Reg32 *) 0xF0000B10)->bit3

// ASC1 Error Interrupt Service Request Control Register
#define ASC1_ESRC              (*((uword volatile *) 0xF0000BF8))
#define ASC1_ESRC_CLRR           ((T_Reg32 *) 0xF0000BF8)->bit14
#define ASC1_ESRC_SETR           ((T_Reg32 *) 0xF0000BF8)->bit15
#define ASC1_ESRC_SRE            ((T_Reg32 *) 0xF0000BF8)->bit12
#define ASC1_ESRC_SRR            ((T_Reg32 *) 0xF0000BF8)->bit13
#define ASC1_ESRC_TOS            ((T_Reg32 *) 0xF0000BF8)->bit10

// ASC1 Fractional Divider Register
#define ASC1_FDV               (*((uword volatile *) 0xF0000B18))

// ASC1 Module Identification Register
#define ASC1_ID                (*((uword volatile *) 0xF0000B08))

// ASC1 Peripheral Input Select Register
#define ASC1_PISEL             (*((uword volatile *) 0xF0000B04))
#define ASC1_PISEL_RIS           ((T_Reg32 *) 0xF0000B04)->bit0

// ASC1 Receive Buffer Register
#define ASC1_RBUF              (*((uword volatile *) 0xF0000B24))

// ASC1 Receive Interrupt Service Request Control Register
#define ASC1_RSRC              (*((uword volatile *) 0xF0000BF4))
#define ASC1_RSRC_CLRR           ((T_Reg32 *) 0xF0000BF4)->bit14
#define ASC1_RSRC_SETR           ((T_Reg32 *) 0xF0000BF4)->bit15
#define ASC1_RSRC_SRE            ((T_Reg32 *) 0xF0000BF4)->bit12
#define ASC1_RSRC_SRR            ((T_Reg32 *) 0xF0000BF4)->bit13
#define ASC1_RSRC_TOS            ((T_Reg32 *) 0xF0000BF4)->bit10

// ASC1 Transmit Buffer Interrupt Service Request Control Register
#define ASC1_TBSRC             (*((uword volatile *) 0xF0000BFC))
#define ASC1_TBSRC_CLRR          ((T_Reg32 *) 0xF0000BFC)->bit14
#define ASC1_TBSRC_SETR          ((T_Reg32 *) 0xF0000BFC)->bit15
#define ASC1_TBSRC_SRE           ((T_Reg32 *) 0xF0000BFC)->bit12
#define ASC1_TBSRC_SRR           ((T_Reg32 *) 0xF0000BFC)->bit13
#define ASC1_TBSRC_TOS           ((T_Reg32 *) 0xF0000BFC)->bit10

// ASC1 Transmit Buffer Register
#define ASC1_TBUF              (*((uword volatile *) 0xF0000B20))

// ASC1 Transmit Interrupt Service Request Control Register
#define ASC1_TSRC              (*((uword volatile *) 0xF0000BF0))
#define ASC1_TSRC_CLRR           ((T_Reg32 *) 0xF0000BF0)->bit14
#define ASC1_TSRC_SETR           ((T_Reg32 *) 0xF0000BF0)->bit15
#define ASC1_TSRC_SRE            ((T_Reg32 *) 0xF0000BF0)->bit12
#define ASC1_TSRC_SRR            ((T_Reg32 *) 0xF0000BF0)->bit13
#define ASC1_TSRC_TOS            ((T_Reg32 *) 0xF0000BF0)->bit10

// ASC1 Write Hardware Bits Control Register
#define ASC1_WHBCON            (*((uword volatile *) 0xF0000B50))
#define ASC1_WHBCON_CLRFE        ((T_Reg32 *) 0xF0000B50)->bit9
#define ASC1_WHBCON_CLROE        ((T_Reg32 *) 0xF0000B50)->bit10
#define ASC1_WHBCON_CLRPE        ((T_Reg32 *) 0xF0000B50)->bit8
#define ASC1_WHBCON_CLRREN       ((T_Reg32 *) 0xF0000B50)->bit4
#define ASC1_WHBCON_SETFE        ((T_Reg32 *) 0xF0000B50)->bit12
#define ASC1_WHBCON_SETOE        ((T_Reg32 *) 0xF0000B50)->bit13
#define ASC1_WHBCON_SETPE        ((T_Reg32 *) 0xF0000B50)->bit11
#define ASC1_WHBCON_SETREN       ((T_Reg32 *) 0xF0000B50)->bit5

// Base Interrupt Vector Table Pointer
#define BIV                    (*((uword volatile *) 0xF7E1FE20))

// BIST Mode Access Control Register
#define BMACON                 (*((uword volatile *) 0xF7E19004))
#define BMACON_DMMBE             0x00000001
#define BMACON_DTMBE             0x00010000
#define BMACON_PMMBE             0x00000100
#define BMACON_PTMBE             0x00040000

// Base Trap Vector Table Pointer
#define BTV                    (*((uword volatile *) 0xF7E1FE24))

// CAN Clock Control Register
#define CAN_CLC                (*((uword volatile *) 0xF0004000))
#define CAN_CLC_DISR             0x00000001
#define CAN_CLC_DISS             0x00000002
#define CAN_CLC_EDIS             0x00000008
#define CAN_CLC_FSOE             0x00000020
#define CAN_CLC_SBWE             0x00000010
#define CAN_CLC_SPEN             0x00000004

// CAN Fractional Divider Register
#define CAN_FDR                (*((uword volatile *) 0xF000400C))
#define CAN_FDR_DISCLK           0x80000000
#define CAN_FDR_ENHW             0x40000000
#define CAN_FDR_SM               0x00000800
#define CAN_FDR_SUSACK           0x10000000
#define CAN_FDR_SUSREQ           0x20000000

// CAN List Register 0
#define CAN_LIST0              (*((uword volatile *) 0xF0004100))
#define CAN_LIST0_EMPTY          0x01000000

// CAN List Register 1
#define CAN_LIST1              (*((uword volatile *) 0xF0004104))
#define CAN_LIST1_EMPTY          0x01000000

// CAN List Register 2
#define CAN_LIST2              (*((uword volatile *) 0xF0004108))
#define CAN_LIST2_EMPTY          0x01000000

// List Register 3
#define CAN_LIST3              (*((uword volatile *) 0xF000410C))
#define CAN_LIST3_EMPTY          0x01000000

// CAN List Register 4
#define CAN_LIST4              (*((uword volatile *) 0xF0004110))
#define CAN_LIST4_EMPTY          0x01000000

// CAN List Register 5
#define CAN_LIST5              (*((uword volatile *) 0xF0004114))
#define CAN_LIST5_EMPTY          0x01000000

// CAN List Register 6
#define CAN_LIST6              (*((uword volatile *) 0xF0004118))
#define CAN_LIST6_EMPTY          0x01000000

// CAN List Register 7
#define CAN_LIST7              (*((uword volatile *) 0xF000411C))
#define CAN_LIST7_EMPTY          0x01000000

// CAN Module Control Register
#define CAN_MCR                (*((uword volatile *) 0xF00041C8))

// CAN Module Interrupt Trigger Register
#define CAN_MITR               (*((uword volatile *) 0xF00041CC))

// CAN Message Object 0 Acceptance Mask Register
#define CAN_MOAMR0             (*((uword volatile *) 0xF000500C))
#define CAN_MOAMR0_MIDE          0x20000000

// CAN Message Object 1 Acceptance Mask Register
#define CAN_MOAMR1             (*((uword volatile *) 0xF000502C))
#define CAN_MOAMR1_MIDE          0x20000000

// CAN Message Object 10 Acceptance Mask Register
#define CAN_MOAMR10            (*((uword volatile *) 0xF000514C))
#define CAN_MOAMR10_MIDE         0x20000000

// CAN Message Object 11 Acceptance Mask Register
#define CAN_MOAMR11            (*((uword volatile *) 0xF000516C))
#define CAN_MOAMR11_MIDE         0x20000000

// CAN Message Object 12 Acceptance Mask Register
#define CAN_MOAMR12            (*((uword volatile *) 0xF000518C))
#define CAN_MOAMR12_MIDE         0x20000000

// CAN Message Object 13 Acceptance Mask Register
#define CAN_MOAMR13            (*((uword volatile *) 0xF00051AC))
#define CAN_MOAMR13_MIDE         0x20000000

// CAN Message Object 14 Acceptance Mask Register
#define CAN_MOAMR14            (*((uword volatile *) 0xF00051CC))
#define CAN_MOAMR14_MIDE         0x20000000

// CAN Message Object 15 Acceptance Mask Register
#define CAN_MOAMR15            (*((uword volatile *) 0xF00051EC))
#define CAN_MOAMR15_MIDE         0x20000000

// CAN Message Object 16 Acceptance Mask Register
#define CAN_MOAMR16            (*((uword volatile *) 0xF000520C))
#define CAN_MOAMR16_MIDE         0x20000000

// CAN Message Object 17 Acceptance Mask Register
#define CAN_MOAMR17            (*((uword volatile *) 0xF000522C))
#define CAN_MOAMR17_MIDE         0x20000000

// CAN Message Object 18 Acceptance Mask Register
#define CAN_MOAMR18            (*((uword volatile *) 0xF000524C))
#define CAN_MOAMR18_MIDE         0x20000000

// CAN Message Object 19 Acceptance Mask Register
#define CAN_MOAMR19            (*((uword volatile *) 0xF000526C))
#define CAN_MOAMR19_MIDE         0x20000000

// CAN Message Object 2 Acceptance Mask Register
#define CAN_MOAMR2             (*((uword volatile *) 0xF000504C))
#define CAN_MOAMR2_MIDE          0x20000000

// CAN Message Object 20 Acceptance Mask Register
#define CAN_MOAMR20            (*((uword volatile *) 0xF000528C))
#define CAN_MOAMR20_MIDE         0x20000000

// CAN Message Object 21 Acceptance Mask Register
#define CAN_MOAMR21            (*((uword volatile *) 0xF00052AC))
#define CAN_MOAMR21_MIDE         0x20000000

// CAN Message Object 22 Acceptance Mask Register
#define CAN_MOAMR22            (*((uword volatile *) 0xF00052CC))
#define CAN_MOAMR22_MIDE         0x20000000

// CAN Message Object 23 Acceptance Mask Register
#define CAN_MOAMR23            (*((uword volatile *) 0xF00052EC))
#define CAN_MOAMR23_MIDE         0x20000000

// CAN Message Object 24 Acceptance Mask Register
#define CAN_MOAMR24            (*((uword volatile *) 0xF000530C))
#define CAN_MOAMR24_MIDE         0x20000000

// CAN Message Object 25 Acceptance Mask Register
#define CAN_MOAMR25            (*((uword volatile *) 0xF000532C))
#define CAN_MOAMR25_MIDE         0x20000000

// CAN Message Object 26 Acceptance Mask Register
#define CAN_MOAMR26            (*((uword volatile *) 0xF000534C))
#define CAN_MOAMR26_MIDE         0x20000000

// CAN Message Object 27 Acceptance Mask Register
#define CAN_MOAMR27            (*((uword volatile *) 0xF000536C))
#define CAN_MOAMR27_MIDE         0x20000000

// CAN Message Object 28 Acceptance Mask Register
#define CAN_MOAMR28            (*((uword volatile *) 0xF000538C))
#define CAN_MOAMR28_MIDE         0x20000000

// CAN Message Object 29 Acceptance Mask Register
#define CAN_MOAMR29            (*((uword volatile *) 0xF00053AC))
#define CAN_MOAMR29_MIDE         0x20000000

// CAN Message Object 3 Acceptance Mask Register
#define CAN_MOAMR3             (*((uword volatile *) 0xF000506C))
#define CAN_MOAMR3_MIDE          0x20000000

// CAN Message Object 30 Acceptance Mask Register
#define CAN_MOAMR30            (*((uword volatile *) 0xF00053CC))
#define CAN_MOAMR30_MIDE         0x20000000

// CAN Message Object 31 Acceptance Mask Register
#define CAN_MOAMR31            (*((uword volatile *) 0xF00053EC))
#define CAN_MOAMR31_MIDE         0x20000000

// CAN Message Object 32 Acceptance Mask Register
#define CAN_MOAMR32            (*((uword volatile *) 0xF000540C))
#define CAN_MOAMR32_MIDE         0x20000000

// CAN Message Object 33 Acceptance Mask Register
#define CAN_MOAMR33            (*((uword volatile *) 0xF000542C))
#define CAN_MOAMR33_MIDE         0x20000000

// CAN Message Object 34 Acceptance Mask Register
#define CAN_MOAMR34            (*((uword volatile *) 0xF000544C))
#define CAN_MOAMR34_MIDE         0x20000000

// CAN Message Object 35 Acceptance Mask Register
#define CAN_MOAMR35            (*((uword volatile *) 0xF000546C))
#define CAN_MOAMR35_MIDE         0x20000000

// CAN Message Object 36 Acceptance Mask Register
#define CAN_MOAMR36            (*((uword volatile *) 0xF000548C))
#define CAN_MOAMR36_MIDE         0x20000000

// CAN Message Object 37 Acceptance Mask Register
#define CAN_MOAMR37            (*((uword volatile *) 0xF00054AC))
#define CAN_MOAMR37_MIDE         0x20000000

// CAN Message Object 38 Acceptance Mask Register
#define CAN_MOAMR38            (*((uword volatile *) 0xF00054CC))
#define CAN_MOAMR38_MIDE         0x20000000

// CAN Message Object 39 Acceptance Mask Register
#define CAN_MOAMR39            (*((uword volatile *) 0xF00054EC))
#define CAN_MOAMR39_MIDE         0x20000000

// CAN Message Object 4 Acceptance Mask Register
#define CAN_MOAMR4             (*((uword volatile *) 0xF000508C))
#define CAN_MOAMR4_MIDE          0x20000000

// CAN Message Object 40 Acceptance Mask Register
#define CAN_MOAMR40            (*((uword volatile *) 0xF000550C))
#define CAN_MOAMR40_MIDE         0x20000000

// CAN Message Object 41 Acceptance Mask Register
#define CAN_MOAMR41            (*((uword volatile *) 0xF000552C))
#define CAN_MOAMR41_MIDE         0x20000000

// CAN Message Object 42 Acceptance Mask Register
#define CAN_MOAMR42            (*((uword volatile *) 0xF000554C))
#define CAN_MOAMR42_MIDE         0x20000000

// CAN Message Object 43 Acceptance Mask Register
#define CAN_MOAMR43            (*((uword volatile *) 0xF000556C))
#define CAN_MOAMR43_MIDE         0x20000000

// CAN Message Object 44 Acceptance Mask Register
#define CAN_MOAMR44            (*((uword volatile *) 0xF000558C))
#define CAN_MOAMR44_MIDE         0x20000000

// CAN Message Object 45 Acceptance Mask Register
#define CAN_MOAMR45            (*((uword volatile *) 0xF00055AC))
#define CAN_MOAMR45_MIDE         0x20000000

// CAN Message Object 46 Acceptance Mask Register
#define CAN_MOAMR46            (*((uword volatile *) 0xF00055CC))
#define CAN_MOAMR46_MIDE         0x20000000

// CAN Message Object 47 Acceptance Mask Register
#define CAN_MOAMR47            (*((uword volatile *) 0xF00055EC))
#define CAN_MOAMR47_MIDE         0x20000000

// CAN Message Object 48 Acceptance Mask Register
#define CAN_MOAMR48            (*((uword volatile *) 0xF000560C))
#define CAN_MOAMR48_MIDE         0x20000000

// CAN Message Object 49 Acceptance Mask Register
#define CAN_MOAMR49            (*((uword volatile *) 0xF000562C))
#define CAN_MOAMR49_MIDE         0x20000000

// CAN Message Object 5 Acceptance Mask Register
#define CAN_MOAMR5             (*((uword volatile *) 0xF00050AC))
#define CAN_MOAMR5_MIDE          0x20000000

// CAN Message Object 50 Acceptance Mask Register
#define CAN_MOAMR50            (*((uword volatile *) 0xF000564C))
#define CAN_MOAMR50_MIDE         0x20000000

// CAN Message Object 51 Acceptance Mask Register
#define CAN_MOAMR51            (*((uword volatile *) 0xF000566C))
#define CAN_MOAMR51_MIDE         0x20000000

// CAN Message Object 52 Acceptance Mask Register
#define CAN_MOAMR52            (*((uword volatile *) 0xF000568C))
#define CAN_MOAMR52_MIDE         0x20000000

// CAN Message Object 53 Acceptance Mask Register
#define CAN_MOAMR53            (*((uword volatile *) 0xF00056AC))
#define CAN_MOAMR53_MIDE         0x20000000

// CAN Message Object 54 Acceptance Mask Register
#define CAN_MOAMR54            (*((uword volatile *) 0xF00056CC))
#define CAN_MOAMR54_MIDE         0x20000000

// CAN Message Object 55 Acceptance Mask Register
#define CAN_MOAMR55            (*((uword volatile *) 0xF00056EC))
#define CAN_MOAMR55_MIDE         0x20000000

// CAN Message Object 56 Acceptance Mask Register
#define CAN_MOAMR56            (*((uword volatile *) 0xF000570C))
#define CAN_MOAMR56_MIDE         0x20000000

// CAN Message Object 57 Acceptance Mask Register
#define CAN_MOAMR57            (*((uword volatile *) 0xF000572C))
#define CAN_MOAMR57_MIDE         0x20000000

// CAN Message Object 58 Acceptance Mask Register
#define CAN_MOAMR58            (*((uword volatile *) 0xF000574C))
#define CAN_MOAMR58_MIDE         0x20000000

// CAN Message Object 59 Acceptance Mask Register
#define CAN_MOAMR59            (*((uword volatile *) 0xF000576C))
#define CAN_MOAMR59_MIDE         0x20000000

// CAN Message Object 6 Acceptance Mask Register
#define CAN_MOAMR6             (*((uword volatile *) 0xF00050CC))
#define CAN_MOAMR6_MIDE          0x20000000

// CAN Message Object 60 Acceptance Mask Register
#define CAN_MOAMR60            (*((uword volatile *) 0xF000578C))
#define CAN_MOAMR60_MIDE         0x20000000

// CAN Message Object 61 Acceptance Mask Register
#define CAN_MOAMR61            (*((uword volatile *) 0xF00057AC))
#define CAN_MOAMR61_MIDE         0x20000000

// CAN Message Object 62 Acceptance Mask Register
#define CAN_MOAMR62            (*((uword volatile *) 0xF00057CC))
#define CAN_MOAMR62_MIDE         0x20000000

// CAN Message Object 63 Acceptance Mask Register
#define CAN_MOAMR63            (*((uword volatile *) 0xF00057EC))
#define CAN_MOAMR63_MIDE         0x20000000

// CAN Message Object 7 Acceptance Mask Register
#define CAN_MOAMR7             (*((uword volatile *) 0xF00050EC))
#define CAN_MOAMR7_MIDE          0x20000000

// CAN Message Object 8 Acceptance Mask Register
#define CAN_MOAMR8             (*((uword volatile *) 0xF000510C))
#define CAN_MOAMR8_MIDE          0x20000000

// CAN Message Object 9 Acceptance Mask Register
#define CAN_MOAMR9             (*((uword volatile *) 0xF000512C))
#define CAN_MOAMR9_MIDE          0x20000000

// CAN Message Object 0 Arbitration Register
#define CAN_MOAR0              (*((uword volatile *) 0xF0005018))
#define CAN_MOAR0_IDE            0x20000000

// Message Object 1 Arbitration Register
#define CAN_MOAR1              (*((uword volatile *) 0xF0005038))
#define CAN_MOAR1_IDE            0x20000000

// CAN Message Object 10 Arbitration Register
#define CAN_MOAR10             (*((uword volatile *) 0xF0005158))
#define CAN_MOAR10_IDE           0x20000000

// CAN Message Object 11 Arbitration Register
#define CAN_MOAR11             (*((uword volatile *) 0xF0005178))
#define CAN_MOAR11_IDE           0x20000000

// CAN Message Object 12 Arbitration Register
#define CAN_MOAR12             (*((uword volatile *) 0xF0005198))
#define CAN_MOAR12_IDE           0x20000000

// CAN Message Object 13 Arbitration Register
#define CAN_MOAR13             (*((uword volatile *) 0xF00051B8))
#define CAN_MOAR13_IDE           0x20000000

// CAN Message Object 14 Arbitration Register
#define CAN_MOAR14             (*((uword volatile *) 0xF00051D8))
#define CAN_MOAR14_IDE           0x20000000

// CAN Message Object 15 Arbitration Register
#define CAN_MOAR15             (*((uword volatile *) 0xF00051F8))
#define CAN_MOAR15_IDE           0x20000000

// CAN Message Object 16 Arbitration Register
#define CAN_MOAR16             (*((uword volatile *) 0xF0005218))
#define CAN_MOAR16_IDE           0x20000000

// CAN Message Object 17 Arbitration Register
#define CAN_MOAR17             (*((uword volatile *) 0xF0005238))
#define CAN_MOAR17_IDE           0x20000000

// CAN Message Object 18 Arbitration Register
#define CAN_MOAR18             (*((uword volatile *) 0xF0005258))
#define CAN_MOAR18_IDE           0x20000000

// CAN Message Object 19 Arbitration Register
#define CAN_MOAR19             (*((uword volatile *) 0xF0005278))
#define CAN_MOAR19_IDE           0x20000000

// Message Object 2 Arbitration Register
#define CAN_MOAR2              (*((uword volatile *) 0xF0005058))
#define CAN_MOAR2_IDE            0x20000000

// CAN Message Object 20 Arbitration Register
#define CAN_MOAR20             (*((uword volatile *) 0xF0005298))
#define CAN_MOAR20_IDE           0x20000000

// CAN Message Object 21 Arbitration Register
#define CAN_MOAR21             (*((uword volatile *) 0xF00052B8))
#define CAN_MOAR21_IDE           0x20000000

// CAN Message Object 22 Arbitration Register
#define CAN_MOAR22             (*((uword volatile *) 0xF00052D8))
#define CAN_MOAR22_IDE           0x20000000

// CAN Message Object 23 Arbitration Register
#define CAN_MOAR23             (*((uword volatile *) 0xF00052F8))
#define CAN_MOAR23_IDE           0x20000000

// CAN Message Object 24 Arbitration Register
#define CAN_MOAR24             (*((uword volatile *) 0xF0005318))
#define CAN_MOAR24_IDE           0x20000000

// CAN Message Object 25 Arbitration Register
#define CAN_MOAR25             (*((uword volatile *) 0xF0005338))
#define CAN_MOAR25_IDE           0x20000000

// CAN Message Object 26 Arbitration Register
#define CAN_MOAR26             (*((uword volatile *) 0xF0005358))
#define CAN_MOAR26_IDE           0x20000000

// CAN Message Object 27 Arbitration Register
#define CAN_MOAR27             (*((uword volatile *) 0xF0005378))
#define CAN_MOAR27_IDE           0x20000000

// CAN Message Object 28 Arbitration Register
#define CAN_MOAR28             (*((uword volatile *) 0xF0005398))
#define CAN_MOAR28_IDE           0x20000000

// CAN Message Object 29 Arbitration Register
#define CAN_MOAR29             (*((uword volatile *) 0xF00053B8))
#define CAN_MOAR29_IDE           0x20000000

// CAN Message Object 3 Arbitration Register
#define CAN_MOAR3              (*((uword volatile *) 0xF0005078))
#define CAN_MOAR3_IDE            0x20000000

// CAN Message Object 30 Arbitration Register
#define CAN_MOAR30             (*((uword volatile *) 0xF00053D8))
#define CAN_MOAR30_IDE           0x20000000

// CAN Message Object 31 Arbitration Register
#define CAN_MOAR31             (*((uword volatile *) 0xF00053F8))
#define CAN_MOAR31_IDE           0x20000000

// CAN Message Object 32 Arbitration Register
#define CAN_MOAR32             (*((uword volatile *) 0xF0005418))
#define CAN_MOAR32_IDE           0x20000000

// CAN Message Object 33 Arbitration Register
#define CAN_MOAR33             (*((uword volatile *) 0xF0005438))
#define CAN_MOAR33_IDE           0x20000000

// CAN Message Object 34 Arbitration Register
#define CAN_MOAR34             (*((uword volatile *) 0xF0005458))
#define CAN_MOAR34_IDE           0x20000000

// CAN Message Object 35 Arbitration Register
#define CAN_MOAR35             (*((uword volatile *) 0xF0005478))
#define CAN_MOAR35_IDE           0x20000000

// CAN Message Object 36 Arbitration Register
#define CAN_MOAR36             (*((uword volatile *) 0xF0005498))
#define CAN_MOAR36_IDE           0x20000000

// CAN Message Object 37 Arbitration Register
#define CAN_MOAR37             (*((uword volatile *) 0xF00054B8))
#define CAN_MOAR37_IDE           0x20000000

// CAN Message Object 38 Arbitration Register
#define CAN_MOAR38             (*((uword volatile *) 0xF00054D8))
#define CAN_MOAR38_IDE           0x20000000

// CAN Message Object 39 Arbitration Register
#define CAN_MOAR39             (*((uword volatile *) 0xF00054F8))
#define CAN_MOAR39_IDE           0x20000000

// CAN Message Object 4 Arbitration Register
#define CAN_MOAR4              (*((uword volatile *) 0xF0005098))
#define CAN_MOAR4_IDE            0x20000000

// CAN Message Object 40 Arbitration Register
#define CAN_MOAR40             (*((uword volatile *) 0xF0005518))
#define CAN_MOAR40_IDE           0x20000000

// CAN Message Object 41 Arbitration Register
#define CAN_MOAR41             (*((uword volatile *) 0xF0005538))
#define CAN_MOAR41_IDE           0x20000000

// CAN Message Object 42 Arbitration Register
#define CAN_MOAR42             (*((uword volatile *) 0xF0005558))
#define CAN_MOAR42_IDE           0x20000000

// CAN Message Object 43 Arbitration Register
#define CAN_MOAR43             (*((uword volatile *) 0xF0005578))
#define CAN_MOAR43_IDE           0x20000000

// CAN Message Object 44 Arbitration Register
#define CAN_MOAR44             (*((uword volatile *) 0xF0005598))
#define CAN_MOAR44_IDE           0x20000000

// CAN Message Object 45 Arbitration Register
#define CAN_MOAR45             (*((uword volatile *) 0xF00055B8))
#define CAN_MOAR45_IDE           0x20000000

// CAN Message Object 46 Arbitration Register
#define CAN_MOAR46             (*((uword volatile *) 0xF00055D8))
#define CAN_MOAR46_IDE           0x20000000

// CAN Message Object 47 Arbitration Register
#define CAN_MOAR47             (*((uword volatile *) 0xF00055F8))
#define CAN_MOAR47_IDE           0x20000000

// CAN Message Object 48 Arbitration Register
#define CAN_MOAR48             (*((uword volatile *) 0xF0005618))
#define CAN_MOAR48_IDE           0x20000000

// CAN Message Object 49 Arbitration Register
#define CAN_MOAR49             (*((uword volatile *) 0xF0005638))
#define CAN_MOAR49_IDE           0x20000000

// CAN Message Object 5 Arbitration Register
#define CAN_MOAR5              (*((uword volatile *) 0xF00050B8))
#define CAN_MOAR5_IDE            0x20000000

// CAN Message Object 50 Arbitration Register
#define CAN_MOAR50             (*((uword volatile *) 0xF0005658))
#define CAN_MOAR50_IDE           0x20000000

// CAN Message Object 51 Arbitration Register
#define CAN_MOAR51             (*((uword volatile *) 0xF0005678))
#define CAN_MOAR51_IDE           0x20000000

// CAN Message Object 52 Arbitration Register
#define CAN_MOAR52             (*((uword volatile *) 0xF0005698))
#define CAN_MOAR52_IDE           0x20000000

// CAN Message Object 53 Arbitration Register
#define CAN_MOAR53             (*((uword volatile *) 0xF00056B8))
#define CAN_MOAR53_IDE           0x20000000

// CAN Message Object 54 Arbitration Register
#define CAN_MOAR54             (*((uword volatile *) 0xF00056D8))
#define CAN_MOAR54_IDE           0x20000000

// CAN Message Object 55 Arbitration Register
#define CAN_MOAR55             (*((uword volatile *) 0xF00056F8))
#define CAN_MOAR55_IDE           0x20000000

// CAN Message Object 56 Arbitration Register
#define CAN_MOAR56             (*((uword volatile *) 0xF0005718))
#define CAN_MOAR56_IDE           0x20000000

// CAN Message Object 57 Arbitration Register
#define CAN_MOAR57             (*((uword volatile *) 0xF0005738))
#define CAN_MOAR57_IDE           0x20000000

// CAN Message Object 58 Arbitration Register
#define CAN_MOAR58             (*((uword volatile *) 0xF0005758))
#define CAN_MOAR58_IDE           0x20000000

// CAN Message Object 59 Arbitration Register
#define CAN_MOAR59             (*((uword volatile *) 0xF0005778))
#define CAN_MOAR59_IDE           0x20000000

// CAN Message Object 6 Arbitration Register
#define CAN_MOAR6              (*((uword volatile *) 0xF00050D8))
#define CAN_MOAR6_IDE            0x20000000

// CAN Message Object 60 Arbitration Register
#define CAN_MOAR60             (*((uword volatile *) 0xF0005798))
#define CAN_MOAR60_IDE           0x20000000

// CAN Message Object 61 Arbitration Register
#define CAN_MOAR61             (*((uword volatile *) 0xF00057B8))
#define CAN_MOAR61_IDE           0x20000000

// CAN Message Object 62 Arbitration Register
#define CAN_MOAR62             (*((uword volatile *) 0xF00057D8))
#define CAN_MOAR62_IDE           0x20000000

// CAN Message Object 63 Arbitration Register
#define CAN_MOAR63             (*((uword volatile *) 0xF00057F8))
#define CAN_MOAR63_IDE           0x20000000

// CAN Message Object 7 Arbitration Register
#define CAN_MOAR7              (*((uword volatile *) 0xF00050F8))
#define CAN_MOAR7_IDE            0x20000000

// CAN Message Object 8 Arbitration Register
#define CAN_MOAR8              (*((uword volatile *) 0xF0005118))
#define CAN_MOAR8_IDE            0x20000000

// CAN Message Object 9 Arbitration Register
#define CAN_MOAR9              (*((uword volatile *) 0xF0005138))
#define CAN_MOAR9_IDE            0x20000000

// CAN Message Object 0 Control Register
#define CAN_MOCTR0             (*((uword volatile *) 0xF000501C))
#define CAN_MOCTR0_RESDIR        0x00000800
#define CAN_MOCTR0_RESMSGLST     0x00000010
#define CAN_MOCTR0_RESMSGVAL     0x00000020
#define CAN_MOCTR0_RESNEWDAT     0x00000008
#define CAN_MOCTR0_RESRTSEL      0x00000040
#define CAN_MOCTR0_RESRXEN       0x00000080
#define CAN_MOCTR0_RESRXPND      0x00000001
#define CAN_MOCTR0_RESRXUPD      0x00000004
#define CAN_MOCTR0_RESTXEN0      0x00000200
#define CAN_MOCTR0_RESTXEN1      0x00000400
#define CAN_MOCTR0_RESTXPND      0x00000002
#define CAN_MOCTR0_RESTXRQ       0x00000100
#define CAN_MOCTR0_SETDIR        0x08000000
#define CAN_MOCTR0_SETMSGLST     0x00100000
#define CAN_MOCTR0_SETMSGVAL     0x00200000
#define CAN_MOCTR0_SETNEWDAT     0x00080000
#define CAN_MOCTR0_SETRTSEL      0x00400000
#define CAN_MOCTR0_SETRXEN       0x00800000
#define CAN_MOCTR0_SETRXPND      0x00010000
#define CAN_MOCTR0_SETRXUPD      0x00040000
#define CAN_MOCTR0_SETTXEN0      0x02000000
#define CAN_MOCTR0_SETTXEN1      0x04000000
#define CAN_MOCTR0_SETTXPND      0x00020000
#define CAN_MOCTR0_SETTXRQ       0x01000000

// CAN Message Object 1 Control Register
#define CAN_MOCTR1             (*((uword volatile *) 0xF000503C))
#define CAN_MOCTR1_RESDIR        0x00000800
#define CAN_MOCTR1_RESMSGLST     0x00000010
#define CAN_MOCTR1_RESMSGVAL     0x00000020
#define CAN_MOCTR1_RESNEWDAT     0x00000008
#define CAN_MOCTR1_RESRTSEL      0x00000040
#define CAN_MOCTR1_RESRXEN       0x00000080
#define CAN_MOCTR1_RESRXPND      0x00000001
#define CAN_MOCTR1_RESRXUPD      0x00000004
#define CAN_MOCTR1_RESTXEN0      0x00000200
#define CAN_MOCTR1_RESTXEN1      0x00000400
#define CAN_MOCTR1_RESTXPND      0x00000002
#define CAN_MOCTR1_RESTXRQ       0x00000100
#define CAN_MOCTR1_SETDIR        0x08000000
#define CAN_MOCTR1_SETMSGLST     0x00100000
#define CAN_MOCTR1_SETMSGVAL     0x00200000
#define CAN_MOCTR1_SETNEWDAT     0x00080000
#define CAN_MOCTR1_SETRTSEL      0x00400000
#define CAN_MOCTR1_SETRXEN       0x00800000
#define CAN_MOCTR1_SETRXPND      0x00010000
#define CAN_MOCTR1_SETRXUPD      0x00040000
#define CAN_MOCTR1_SETTXEN0      0x02000000
#define CAN_MOCTR1_SETTXEN1      0x04000000
#define CAN_MOCTR1_SETTXPND      0x00020000
#define CAN_MOCTR1_SETTXRQ       0x01000000

// CAN Message Object 10 Control Register
#define CAN_MOCTR10            (*((uword volatile *) 0xF000515C))
#define CAN_MOCTR10_RESDIR       0x00000800
#define CAN_MOCTR10_RESMSGLST    0x00000010
#define CAN_MOCTR10_RESMSGVAL    0x00000020
#define CAN_MOCTR10_RESNEWDAT    0x00000008
#define CAN_MOCTR10_RESRTSEL     0x00000040
#define CAN_MOCTR10_RESRXEN      0x00000080
#define CAN_MOCTR10_RESRXPND     0x00000001
#define CAN_MOCTR10_RESRXUPD     0x00000004
#define CAN_MOCTR10_RESTXEN0     0x00000200
#define CAN_MOCTR10_RESTXEN1     0x00000400
#define CAN_MOCTR10_RESTXPND     0x00000002
#define CAN_MOCTR10_RESTXRQ      0x00000100
#define CAN_MOCTR10_SETDIR       0x08000000
#define CAN_MOCTR10_SETMSGLST    0x00100000
#define CAN_MOCTR10_SETMSGVAL    0x00200000
#define CAN_MOCTR10_SETNEWDAT    0x00080000
#define CAN_MOCTR10_SETRTSEL     0x00400000
#define CAN_MOCTR10_SETRXEN      0x00800000
#define CAN_MOCTR10_SETRXPND     0x00010000
#define CAN_MOCTR10_SETRXUPD     0x00040000
#define CAN_MOCTR10_SETTXEN0     0x02000000
#define CAN_MOCTR10_SETTXEN1     0x04000000
#define CAN_MOCTR10_SETTXPND     0x00020000
#define CAN_MOCTR10_SETTXRQ      0x01000000

// CAN Message Object 11 Control Register
#define CAN_MOCTR11            (*((uword volatile *) 0xF000517C))
#define CAN_MOCTR11_RESDIR       0x00000800
#define CAN_MOCTR11_RESMSGLST    0x00000010
#define CAN_MOCTR11_RESMSGVAL    0x00000020
#define CAN_MOCTR11_RESNEWDAT    0x00000008
#define CAN_MOCTR11_RESRTSEL     0x00000040
#define CAN_MOCTR11_RESRXEN      0x00000080
#define CAN_MOCTR11_RESRXPND     0x00000001
#define CAN_MOCTR11_RESRXUPD     0x00000004
#define CAN_MOCTR11_RESTXEN0     0x00000200
#define CAN_MOCTR11_RESTXEN1     0x00000400
#define CAN_MOCTR11_RESTXPND     0x00000002
#define CAN_MOCTR11_RESTXRQ      0x00000100
#define CAN_MOCTR11_SETDIR       0x08000000
#define CAN_MOCTR11_SETMSGLST    0x00100000
#define CAN_MOCTR11_SETMSGVAL    0x00200000
#define CAN_MOCTR11_SETNEWDAT    0x00080000
#define CAN_MOCTR11_SETRTSEL     0x00400000
#define CAN_MOCTR11_SETRXEN      0x00800000
#define CAN_MOCTR11_SETRXPND     0x00010000
#define CAN_MOCTR11_SETRXUPD     0x00040000
#define CAN_MOCTR11_SETTXEN0     0x02000000
#define CAN_MOCTR11_SETTXEN1     0x04000000
#define CAN_MOCTR11_SETTXPND     0x00020000
#define CAN_MOCTR11_SETTXRQ      0x01000000

// CAN Message Object 12 Control Register
#define CAN_MOCTR12            (*((uword volatile *) 0xF000519C))
#define CAN_MOCTR12_RESDIR       0x00000800
#define CAN_MOCTR12_RESMSGLST    0x00000010
#define CAN_MOCTR12_RESMSGVAL    0x00000020
#define CAN_MOCTR12_RESNEWDAT    0x00000008
#define CAN_MOCTR12_RESRTSEL     0x00000040
#define CAN_MOCTR12_RESRXEN      0x00000080
#define CAN_MOCTR12_RESRXPND     0x00000001
#define CAN_MOCTR12_RESRXUPD     0x00000004
#define CAN_MOCTR12_RESTXEN0     0x00000200
#define CAN_MOCTR12_RESTXEN1     0x00000400
#define CAN_MOCTR12_RESTXPND     0x00000002
#define CAN_MOCTR12_RESTXRQ      0x00000100
#define CAN_MOCTR12_SETDIR       0x08000000
#define CAN_MOCTR12_SETMSGLST    0x00100000
#define CAN_MOCTR12_SETMSGVAL    0x00200000
#define CAN_MOCTR12_SETNEWDAT    0x00080000
#define CAN_MOCTR12_SETRTSEL     0x00400000
#define CAN_MOCTR12_SETRXEN      0x00800000
#define CAN_MOCTR12_SETRXPND     0x00010000
#define CAN_MOCTR12_SETRXUPD     0x00040000
#define CAN_MOCTR12_SETTXEN0     0x02000000
#define CAN_MOCTR12_SETTXEN1     0x04000000
#define CAN_MOCTR12_SETTXPND     0x00020000
#define CAN_MOCTR12_SETTXRQ      0x01000000

// CAN Message Object 13 Control Register
#define CAN_MOCTR13            (*((uword volatile *) 0xF00051BC))
#define CAN_MOCTR13_RESDIR       0x00000800
#define CAN_MOCTR13_RESMSGLST    0x00000010
#define CAN_MOCTR13_RESMSGVAL    0x00000020
#define CAN_MOCTR13_RESNEWDAT    0x00000008
#define CAN_MOCTR13_RESRTSEL     0x00000040
#define CAN_MOCTR13_RESRXEN      0x00000080
#define CAN_MOCTR13_RESRXPND     0x00000001
#define CAN_MOCTR13_RESRXUPD     0x00000004
#define CAN_MOCTR13_RESTXEN0     0x00000200
#define CAN_MOCTR13_RESTXEN1     0x00000400
#define CAN_MOCTR13_RESTXPND     0x00000002
#define CAN_MOCTR13_RESTXRQ      0x00000100
#define CAN_MOCTR13_SETDIR       0x08000000
#define CAN_MOCTR13_SETMSGLST    0x00100000
#define CAN_MOCTR13_SETMSGVAL    0x00200000
#define CAN_MOCTR13_SETNEWDAT    0x00080000
#define CAN_MOCTR13_SETRTSEL     0x00400000
#define CAN_MOCTR13_SETRXEN      0x00800000
#define CAN_MOCTR13_SETRXPND     0x00010000
#define CAN_MOCTR13_SETRXUPD     0x00040000
#define CAN_MOCTR13_SETTXEN0     0x02000000
#define CAN_MOCTR13_SETTXEN1     0x04000000
#define CAN_MOCTR13_SETTXPND     0x00020000
#define CAN_MOCTR13_SETTXRQ      0x01000000

// CAN Message Object 14 Control Register
#define CAN_MOCTR14            (*((uword volatile *) 0xF00051DC))
#define CAN_MOCTR14_RESDIR       0x00000800
#define CAN_MOCTR14_RESMSGLST    0x00000010
#define CAN_MOCTR14_RESMSGVAL    0x00000020
#define CAN_MOCTR14_RESNEWDAT    0x00000008
#define CAN_MOCTR14_RESRTSEL     0x00000040
#define CAN_MOCTR14_RESRXEN      0x00000080
#define CAN_MOCTR14_RESRXPND     0x00000001
#define CAN_MOCTR14_RESRXUPD     0x00000004
#define CAN_MOCTR14_RESTXEN0     0x00000200
#define CAN_MOCTR14_RESTXEN1     0x00000400
#define CAN_MOCTR14_RESTXPND     0x00000002
#define CAN_MOCTR14_RESTXRQ      0x00000100
#define CAN_MOCTR14_SETDIR       0x08000000
#define CAN_MOCTR14_SETMSGLST    0x00100000
#define CAN_MOCTR14_SETMSGVAL    0x00200000
#define CAN_MOCTR14_SETNEWDAT    0x00080000
#define CAN_MOCTR14_SETRTSEL     0x00400000
#define CAN_MOCTR14_SETRXEN      0x00800000
#define CAN_MOCTR14_SETRXPND     0x00010000
#define CAN_MOCTR14_SETRXUPD     0x00040000
#define CAN_MOCTR14_SETTXEN0     0x02000000
#define CAN_MOCTR14_SETTXEN1     0x04000000
#define CAN_MOCTR14_SETTXPND     0x00020000
#define CAN_MOCTR14_SETTXRQ      0x01000000

// CAN Message Object 15 Control Register
#define CAN_MOCTR15            (*((uword volatile *) 0xF00051FC))
#define CAN_MOCTR15_RESDIR       0x00000800
#define CAN_MOCTR15_RESMSGLST    0x00000010
#define CAN_MOCTR15_RESMSGVAL    0x00000020
#define CAN_MOCTR15_RESNEWDAT    0x00000008
#define CAN_MOCTR15_RESRTSEL     0x00000040
#define CAN_MOCTR15_RESRXEN      0x00000080
#define CAN_MOCTR15_RESRXPND     0x00000001
#define CAN_MOCTR15_RESRXUPD     0x00000004
#define CAN_MOCTR15_RESTXEN0     0x00000200
#define CAN_MOCTR15_RESTXEN1     0x00000400
#define CAN_MOCTR15_RESTXPND     0x00000002
#define CAN_MOCTR15_RESTXRQ      0x00000100
#define CAN_MOCTR15_SETDIR       0x08000000
#define CAN_MOCTR15_SETMSGLST    0x00100000
#define CAN_MOCTR15_SETMSGVAL    0x00200000
#define CAN_MOCTR15_SETNEWDAT    0x00080000
#define CAN_MOCTR15_SETRTSEL     0x00400000
#define CAN_MOCTR15_SETRXEN      0x00800000
#define CAN_MOCTR15_SETRXPND     0x00010000
#define CAN_MOCTR15_SETRXUPD     0x00040000
#define CAN_MOCTR15_SETTXEN0     0x02000000
#define CAN_MOCTR15_SETTXEN1     0x04000000
#define CAN_MOCTR15_SETTXPND     0x00020000
#define CAN_MOCTR15_SETTXRQ      0x01000000

// CAN Message Object 16 Control Register
#define CAN_MOCTR16            (*((uword volatile *) 0xF000521C))
#define CAN_MOCTR16_RESDIR       0x00000800
#define CAN_MOCTR16_RESMSGLST    0x00000010
#define CAN_MOCTR16_RESMSGVAL    0x00000020
#define CAN_MOCTR16_RESNEWDAT    0x00000008
#define CAN_MOCTR16_RESRTSEL     0x00000040
#define CAN_MOCTR16_RESRXEN      0x00000080
#define CAN_MOCTR16_RESRXPND     0x00000001
#define CAN_MOCTR16_RESRXUPD     0x00000004
#define CAN_MOCTR16_RESTXEN0     0x00000200
#define CAN_MOCTR16_RESTXEN1     0x00000400
#define CAN_MOCTR16_RESTXPND     0x00000002
#define CAN_MOCTR16_RESTXRQ      0x00000100
#define CAN_MOCTR16_SETDIR       0x08000000
#define CAN_MOCTR16_SETMSGLST    0x00100000
#define CAN_MOCTR16_SETMSGVAL    0x00200000
#define CAN_MOCTR16_SETNEWDAT    0x00080000
#define CAN_MOCTR16_SETRTSEL     0x00400000
#define CAN_MOCTR16_SETRXEN      0x00800000
#define CAN_MOCTR16_SETRXPND     0x00010000
#define CAN_MOCTR16_SETRXUPD     0x00040000
#define CAN_MOCTR16_SETTXEN0     0x02000000
#define CAN_MOCTR16_SETTXEN1     0x04000000
#define CAN_MOCTR16_SETTXPND     0x00020000
#define CAN_MOCTR16_SETTXRQ      0x01000000

// CAN Message Object 17 Control Register
#define CAN_MOCTR17            (*((uword volatile *) 0xF000523C))
#define CAN_MOCTR17_RESDIR       0x00000800
#define CAN_MOCTR17_RESMSGLST    0x00000010
#define CAN_MOCTR17_RESMSGVAL    0x00000020
#define CAN_MOCTR17_RESNEWDAT    0x00000008
#define CAN_MOCTR17_RESRTSEL     0x00000040
#define CAN_MOCTR17_RESRXEN      0x00000080
#define CAN_MOCTR17_RESRXPND     0x00000001
#define CAN_MOCTR17_RESRXUPD     0x00000004
#define CAN_MOCTR17_RESTXEN0     0x00000200
#define CAN_MOCTR17_RESTXEN1     0x00000400
#define CAN_MOCTR17_RESTXPND     0x00000002
#define CAN_MOCTR17_RESTXRQ      0x00000100
#define CAN_MOCTR17_SETDIR       0x08000000
#define CAN_MOCTR17_SETMSGLST    0x00100000
#define CAN_MOCTR17_SETMSGVAL    0x00200000
#define CAN_MOCTR17_SETNEWDAT    0x00080000
#define CAN_MOCTR17_SETRTSEL     0x00400000
#define CAN_MOCTR17_SETRXEN      0x00800000
#define CAN_MOCTR17_SETRXPND     0x00010000
#define CAN_MOCTR17_SETRXUPD     0x00040000
#define CAN_MOCTR17_SETTXEN0     0x02000000
#define CAN_MOCTR17_SETTXEN1     0x04000000
#define CAN_MOCTR17_SETTXPND     0x00020000
#define CAN_MOCTR17_SETTXRQ      0x01000000

// CAN Message Object 18 Control Register
#define CAN_MOCTR18            (*((uword volatile *) 0xF000525C))
#define CAN_MOCTR18_RESDIR       0x00000800
#define CAN_MOCTR18_RESMSGLST    0x00000010
#define CAN_MOCTR18_RESMSGVAL    0x00000020
#define CAN_MOCTR18_RESNEWDAT    0x00000008
#define CAN_MOCTR18_RESRTSEL     0x00000040
#define CAN_MOCTR18_RESRXEN      0x00000080
#define CAN_MOCTR18_RESRXPND     0x00000001
#define CAN_MOCTR18_RESRXUPD     0x00000004
#define CAN_MOCTR18_RESTXEN0     0x00000200
#define CAN_MOCTR18_RESTXEN1     0x00000400
#define CAN_MOCTR18_RESTXPND     0x00000002
#define CAN_MOCTR18_RESTXRQ      0x00000100
#define CAN_MOCTR18_SETDIR       0x08000000
#define CAN_MOCTR18_SETMSGLST    0x00100000
#define CAN_MOCTR18_SETMSGVAL    0x00200000
#define CAN_MOCTR18_SETNEWDAT    0x00080000
#define CAN_MOCTR18_SETRTSEL     0x00400000
#define CAN_MOCTR18_SETRXEN      0x00800000
#define CAN_MOCTR18_SETRXPND     0x00010000
#define CAN_MOCTR18_SETRXUPD     0x00040000
#define CAN_MOCTR18_SETTXEN0     0x02000000
#define CAN_MOCTR18_SETTXEN1     0x04000000
#define CAN_MOCTR18_SETTXPND     0x00020000
#define CAN_MOCTR18_SETTXRQ      0x01000000

// CAN Message Object 19 Control Register
#define CAN_MOCTR19            (*((uword volatile *) 0xF000527C))
#define CAN_MOCTR19_RESDIR       0x00000800
#define CAN_MOCTR19_RESMSGLST    0x00000010
#define CAN_MOCTR19_RESMSGVAL    0x00000020
#define CAN_MOCTR19_RESNEWDAT    0x00000008
#define CAN_MOCTR19_RESRTSEL     0x00000040
#define CAN_MOCTR19_RESRXEN      0x00000080
#define CAN_MOCTR19_RESRXPND     0x00000001
#define CAN_MOCTR19_RESRXUPD     0x00000004
#define CAN_MOCTR19_RESTXEN0     0x00000200
#define CAN_MOCTR19_RESTXEN1     0x00000400
#define CAN_MOCTR19_RESTXPND     0x00000002
#define CAN_MOCTR19_RESTXRQ      0x00000100
#define CAN_MOCTR19_SETDIR       0x08000000
#define CAN_MOCTR19_SETMSGLST    0x00100000
#define CAN_MOCTR19_SETMSGVAL    0x00200000
#define CAN_MOCTR19_SETNEWDAT    0x00080000
#define CAN_MOCTR19_SETRTSEL     0x00400000
#define CAN_MOCTR19_SETRXEN      0x00800000
#define CAN_MOCTR19_SETRXPND     0x00010000
#define CAN_MOCTR19_SETRXUPD     0x00040000
#define CAN_MOCTR19_SETTXEN0     0x02000000
#define CAN_MOCTR19_SETTXEN1     0x04000000
#define CAN_MOCTR19_SETTXPND     0x00020000
#define CAN_MOCTR19_SETTXRQ      0x01000000

// CAN Message Object 2 Control Register
#define CAN_MOCTR2             (*((uword volatile *) 0xF000505C))
#define CAN_MOCTR2_RESDIR        0x00000800
#define CAN_MOCTR2_RESMSGLST     0x00000010
#define CAN_MOCTR2_RESMSGVAL     0x00000020
#define CAN_MOCTR2_RESNEWDAT     0x00000008
#define CAN_MOCTR2_RESRTSEL      0x00000040
#define CAN_MOCTR2_RESRXEN       0x00000080
#define CAN_MOCTR2_RESRXPND      0x00000001
#define CAN_MOCTR2_RESRXUPD      0x00000004
#define CAN_MOCTR2_RESTXEN0      0x00000200
#define CAN_MOCTR2_RESTXEN1      0x00000400
#define CAN_MOCTR2_RESTXPND      0x00000002
#define CAN_MOCTR2_RESTXRQ       0x00000100
#define CAN_MOCTR2_SETDIR        0x08000000
#define CAN_MOCTR2_SETMSGLST     0x00100000
#define CAN_MOCTR2_SETMSGVAL     0x00200000
#define CAN_MOCTR2_SETNEWDAT     0x00080000
#define CAN_MOCTR2_SETRTSEL      0x00400000
#define CAN_MOCTR2_SETRXEN       0x00800000
#define CAN_MOCTR2_SETRXPND      0x00010000
#define CAN_MOCTR2_SETRXUPD      0x00040000
#define CAN_MOCTR2_SETTXEN0      0x02000000
#define CAN_MOCTR2_SETTXEN1      0x04000000
#define CAN_MOCTR2_SETTXPND      0x00020000
#define CAN_MOCTR2_SETTXRQ       0x01000000

// CAN Message Object 20 Control Register
#define CAN_MOCTR20            (*((uword volatile *) 0xF000529C))
#define CAN_MOCTR20_RESDIR       0x00000800
#define CAN_MOCTR20_RESMSGLST    0x00000010
#define CAN_MOCTR20_RESMSGVAL    0x00000020
#define CAN_MOCTR20_RESNEWDAT    0x00000008
#define CAN_MOCTR20_RESRTSEL     0x00000040
#define CAN_MOCTR20_RESRXEN      0x00000080
#define CAN_MOCTR20_RESRXPND     0x00000001
#define CAN_MOCTR20_RESRXUPD     0x00000004
#define CAN_MOCTR20_RESTXEN0     0x00000200
#define CAN_MOCTR20_RESTXEN1     0x00000400
#define CAN_MOCTR20_RESTXPND     0x00000002
#define CAN_MOCTR20_RESTXRQ      0x00000100
#define CAN_MOCTR20_SETDIR       0x08000000
#define CAN_MOCTR20_SETMSGLST    0x00100000
#define CAN_MOCTR20_SETMSGVAL    0x00200000
#define CAN_MOCTR20_SETNEWDAT    0x00080000
#define CAN_MOCTR20_SETRTSEL     0x00400000
#define CAN_MOCTR20_SETRXEN      0x00800000
#define CAN_MOCTR20_SETRXPND     0x00010000
#define CAN_MOCTR20_SETRXUPD     0x00040000
#define CAN_MOCTR20_SETTXEN0     0x02000000
#define CAN_MOCTR20_SETTXEN1     0x04000000
#define CAN_MOCTR20_SETTXPND     0x00020000
#define CAN_MOCTR20_SETTXRQ      0x01000000

// CAN Message Object 21 Control Register
#define CAN_MOCTR21            (*((uword volatile *) 0xF00052BC))
#define CAN_MOCTR21_RESDIR       0x00000800
#define CAN_MOCTR21_RESMSGLST    0x00000010
#define CAN_MOCTR21_RESMSGVAL    0x00000020
#define CAN_MOCTR21_RESNEWDAT    0x00000008
#define CAN_MOCTR21_RESRTSEL     0x00000040
#define CAN_MOCTR21_RESRXEN      0x00000080
#define CAN_MOCTR21_RESRXPND     0x00000001
#define CAN_MOCTR21_RESRXUPD     0x00000004
#define CAN_MOCTR21_RESTXEN0     0x00000200
#define CAN_MOCTR21_RESTXEN1     0x00000400
#define CAN_MOCTR21_RESTXPND     0x00000002
#define CAN_MOCTR21_RESTXRQ      0x00000100
#define CAN_MOCTR21_SETDIR       0x08000000
#define CAN_MOCTR21_SETMSGLST    0x00100000
#define CAN_MOCTR21_SETMSGVAL    0x00200000
#define CAN_MOCTR21_SETNEWDAT    0x00080000
#define CAN_MOCTR21_SETRTSEL     0x00400000
#define CAN_MOCTR21_SETRXEN      0x00800000
#define CAN_MOCTR21_SETRXPND     0x00010000
#define CAN_MOCTR21_SETRXUPD     0x00040000
#define CAN_MOCTR21_SETTXEN0     0x02000000
#define CAN_MOCTR21_SETTXEN1     0x04000000
#define CAN_MOCTR21_SETTXPND     0x00020000
#define CAN_MOCTR21_SETTXRQ      0x01000000

// CAN Message Object 22 Control Register
#define CAN_MOCTR22            (*((uword volatile *) 0xF00052DC))
#define CAN_MOCTR22_RESDIR       0x00000800
#define CAN_MOCTR22_RESMSGLST    0x00000010
#define CAN_MOCTR22_RESMSGVAL    0x00000020
#define CAN_MOCTR22_RESNEWDAT    0x00000008
#define CAN_MOCTR22_RESRTSEL     0x00000040
#define CAN_MOCTR22_RESRXEN      0x00000080
#define CAN_MOCTR22_RESRXPND     0x00000001
#define CAN_MOCTR22_RESRXUPD     0x00000004
#define CAN_MOCTR22_RESTXEN0     0x00000200
#define CAN_MOCTR22_RESTXEN1     0x00000400
#define CAN_MOCTR22_RESTXPND     0x00000002
#define CAN_MOCTR22_RESTXRQ      0x00000100
#define CAN_MOCTR22_SETDIR       0x08000000
#define CAN_MOCTR22_SETMSGLST    0x00100000
#define CAN_MOCTR22_SETMSGVAL    0x00200000
#define CAN_MOCTR22_SETNEWDAT    0x00080000
#define CAN_MOCTR22_SETRTSEL     0x00400000
#define CAN_MOCTR22_SETRXEN      0x00800000
#define CAN_MOCTR22_SETRXPND     0x00010000
#define CAN_MOCTR22_SETRXUPD     0x00040000
#define CAN_MOCTR22_SETTXEN0     0x02000000
#define CAN_MOCTR22_SETTXEN1     0x04000000
#define CAN_MOCTR22_SETTXPND     0x00020000
#define CAN_MOCTR22_SETTXRQ      0x01000000

// CAN Message Object 23 Control Register
#define CAN_MOCTR23            (*((uword volatile *) 0xF00052FC))
#define CAN_MOCTR23_RESDIR       0x00000800
#define CAN_MOCTR23_RESMSGLST    0x00000010
#define CAN_MOCTR23_RESMSGVAL    0x00000020
#define CAN_MOCTR23_RESNEWDAT    0x00000008
#define CAN_MOCTR23_RESRTSEL     0x00000040
#define CAN_MOCTR23_RESRXEN      0x00000080
#define CAN_MOCTR23_RESRXPND     0x00000001
#define CAN_MOCTR23_RESRXUPD     0x00000004
#define CAN_MOCTR23_RESTXEN0     0x00000200
#define CAN_MOCTR23_RESTXEN1     0x00000400
#define CAN_MOCTR23_RESTXPND     0x00000002
#define CAN_MOCTR23_RESTXRQ      0x00000100
#define CAN_MOCTR23_SETDIR       0x08000000
#define CAN_MOCTR23_SETMSGLST    0x00100000
#define CAN_MOCTR23_SETMSGVAL    0x00200000
#define CAN_MOCTR23_SETNEWDAT    0x00080000
#define CAN_MOCTR23_SETRTSEL     0x00400000
#define CAN_MOCTR23_SETRXEN      0x00800000
#define CAN_MOCTR23_SETRXPND     0x00010000
#define CAN_MOCTR23_SETRXUPD     0x00040000
#define CAN_MOCTR23_SETTXEN0     0x02000000
#define CAN_MOCTR23_SETTXEN1     0x04000000
#define CAN_MOCTR23_SETTXPND     0x00020000
#define CAN_MOCTR23_SETTXRQ      0x01000000

// CAN Message Object 24 Control Register
#define CAN_MOCTR24            (*((uword volatile *) 0xF000531C))
#define CAN_MOCTR24_RESDIR       0x00000800
#define CAN_MOCTR24_RESMSGLST    0x00000010
#define CAN_MOCTR24_RESMSGVAL    0x00000020
#define CAN_MOCTR24_RESNEWDAT    0x00000008
#define CAN_MOCTR24_RESRTSEL     0x00000040
#define CAN_MOCTR24_RESRXEN      0x00000080
#define CAN_MOCTR24_RESRXPND     0x00000001
#define CAN_MOCTR24_RESRXUPD     0x00000004
#define CAN_MOCTR24_RESTXEN0     0x00000200
#define CAN_MOCTR24_RESTXEN1     0x00000400
#define CAN_MOCTR24_RESTXPND     0x00000002
#define CAN_MOCTR24_RESTXRQ      0x00000100
#define CAN_MOCTR24_SETDIR       0x08000000
#define CAN_MOCTR24_SETMSGLST    0x00100000
#define CAN_MOCTR24_SETMSGVAL    0x00200000
#define CAN_MOCTR24_SETNEWDAT    0x00080000
#define CAN_MOCTR24_SETRTSEL     0x00400000
#define CAN_MOCTR24_SETRXEN      0x00800000
#define CAN_MOCTR24_SETRXPND     0x00010000
#define CAN_MOCTR24_SETRXUPD     0x00040000
#define CAN_MOCTR24_SETTXEN0     0x02000000
#define CAN_MOCTR24_SETTXEN1     0x04000000
#define CAN_MOCTR24_SETTXPND     0x00020000
#define CAN_MOCTR24_SETTXRQ      0x01000000

// CAN Message Object 25 Control Register
#define CAN_MOCTR25            (*((uword volatile *) 0xF000533C))
#define CAN_MOCTR25_RESDIR       0x00000800
#define CAN_MOCTR25_RESMSGLST    0x00000010
#define CAN_MOCTR25_RESMSGVAL    0x00000020
#define CAN_MOCTR25_RESNEWDAT    0x00000008
#define CAN_MOCTR25_RESRTSEL     0x00000040
#define CAN_MOCTR25_RESRXEN      0x00000080
#define CAN_MOCTR25_RESRXPND     0x00000001
#define CAN_MOCTR25_RESRXUPD     0x00000004
#define CAN_MOCTR25_RESTXEN0     0x00000200
#define CAN_MOCTR25_RESTXEN1     0x00000400
#define CAN_MOCTR25_RESTXPND     0x00000002
#define CAN_MOCTR25_RESTXRQ      0x00000100
#define CAN_MOCTR25_SETDIR       0x08000000
#define CAN_MOCTR25_SETMSGLST    0x00100000
#define CAN_MOCTR25_SETMSGVAL    0x00200000
#define CAN_MOCTR25_SETNEWDAT    0x00080000
#define CAN_MOCTR25_SETRTSEL     0x00400000
#define CAN_MOCTR25_SETRXEN      0x00800000
#define CAN_MOCTR25_SETRXPND     0x00010000
#define CAN_MOCTR25_SETRXUPD     0x00040000
#define CAN_MOCTR25_SETTXEN0     0x02000000
#define CAN_MOCTR25_SETTXEN1     0x04000000
#define CAN_MOCTR25_SETTXPND     0x00020000
#define CAN_MOCTR25_SETTXRQ      0x01000000

// CAN Message Object 26 Control Register
#define CAN_MOCTR26            (*((uword volatile *) 0xF000535C))
#define CAN_MOCTR26_RESDIR       0x00000800
#define CAN_MOCTR26_RESMSGLST    0x00000010
#define CAN_MOCTR26_RESMSGVAL    0x00000020
#define CAN_MOCTR26_RESNEWDAT    0x00000008
#define CAN_MOCTR26_RESRTSEL     0x00000040
#define CAN_MOCTR26_RESRXEN      0x00000080
#define CAN_MOCTR26_RESRXPND     0x00000001
#define CAN_MOCTR26_RESRXUPD     0x00000004
#define CAN_MOCTR26_RESTXEN0     0x00000200
#define CAN_MOCTR26_RESTXEN1     0x00000400
#define CAN_MOCTR26_RESTXPND     0x00000002
#define CAN_MOCTR26_RESTXRQ      0x00000100
#define CAN_MOCTR26_SETDIR       0x08000000
#define CAN_MOCTR26_SETMSGLST    0x00100000
#define CAN_MOCTR26_SETMSGVAL    0x00200000
#define CAN_MOCTR26_SETNEWDAT    0x00080000
#define CAN_MOCTR26_SETRTSEL     0x00400000
#define CAN_MOCTR26_SETRXEN      0x00800000
#define CAN_MOCTR26_SETRXPND     0x00010000
#define CAN_MOCTR26_SETRXUPD     0x00040000
#define CAN_MOCTR26_SETTXEN0     0x02000000
#define CAN_MOCTR26_SETTXEN1     0x04000000
#define CAN_MOCTR26_SETTXPND     0x00020000
#define CAN_MOCTR26_SETTXRQ      0x01000000

// CAN Message Object 27 Control Register
#define CAN_MOCTR27            (*((uword volatile *) 0xF000537C))
#define CAN_MOCTR27_RESDIR       0x00000800
#define CAN_MOCTR27_RESMSGLST    0x00000010
#define CAN_MOCTR27_RESMSGVAL    0x00000020
#define CAN_MOCTR27_RESNEWDAT    0x00000008
#define CAN_MOCTR27_RESRTSEL     0x00000040
#define CAN_MOCTR27_RESRXEN      0x00000080
#define CAN_MOCTR27_RESRXPND     0x00000001
#define CAN_MOCTR27_RESRXUPD     0x00000004
#define CAN_MOCTR27_RESTXEN0     0x00000200
#define CAN_MOCTR27_RESTXEN1     0x00000400
#define CAN_MOCTR27_RESTXPND     0x00000002
#define CAN_MOCTR27_RESTXRQ      0x00000100
#define CAN_MOCTR27_SETDIR       0x08000000
#define CAN_MOCTR27_SETMSGLST    0x00100000
#define CAN_MOCTR27_SETMSGVAL    0x00200000
#define CAN_MOCTR27_SETNEWDAT    0x00080000
#define CAN_MOCTR27_SETRTSEL     0x00400000
#define CAN_MOCTR27_SETRXEN      0x00800000
#define CAN_MOCTR27_SETRXPND     0x00010000
#define CAN_MOCTR27_SETRXUPD     0x00040000
#define CAN_MOCTR27_SETTXEN0     0x02000000
#define CAN_MOCTR27_SETTXEN1     0x04000000
#define CAN_MOCTR27_SETTXPND     0x00020000
#define CAN_MOCTR27_SETTXRQ      0x01000000

// CAN Message Object 28 Control Register
#define CAN_MOCTR28            (*((uword volatile *) 0xF000539C))
#define CAN_MOCTR28_RESDIR       0x00000800
#define CAN_MOCTR28_RESMSGLST    0x00000010
#define CAN_MOCTR28_RESMSGVAL    0x00000020
#define CAN_MOCTR28_RESNEWDAT    0x00000008
#define CAN_MOCTR28_RESRTSEL     0x00000040
#define CAN_MOCTR28_RESRXEN      0x00000080
#define CAN_MOCTR28_RESRXPND     0x00000001
#define CAN_MOCTR28_RESRXUPD     0x00000004
#define CAN_MOCTR28_RESTXEN0     0x00000200
#define CAN_MOCTR28_RESTXEN1     0x00000400
#define CAN_MOCTR28_RESTXPND     0x00000002
#define CAN_MOCTR28_RESTXRQ      0x00000100
#define CAN_MOCTR28_SETDIR       0x08000000
#define CAN_MOCTR28_SETMSGLST    0x00100000
#define CAN_MOCTR28_SETMSGVAL    0x00200000
#define CAN_MOCTR28_SETNEWDAT    0x00080000
#define CAN_MOCTR28_SETRTSEL     0x00400000
#define CAN_MOCTR28_SETRXEN      0x00800000
#define CAN_MOCTR28_SETRXPND     0x00010000
#define CAN_MOCTR28_SETRXUPD     0x00040000
#define CAN_MOCTR28_SETTXEN0     0x02000000
#define CAN_MOCTR28_SETTXEN1     0x04000000
#define CAN_MOCTR28_SETTXPND     0x00020000
#define CAN_MOCTR28_SETTXRQ      0x01000000

// CAN Message Object 29 Control Register
#define CAN_MOCTR29            (*((uword volatile *) 0xF00053BC))
#define CAN_MOCTR29_RESDIR       0x00000800
#define CAN_MOCTR29_RESMSGLST    0x00000010
#define CAN_MOCTR29_RESMSGVAL    0x00000020
#define CAN_MOCTR29_RESNEWDAT    0x00000008
#define CAN_MOCTR29_RESRTSEL     0x00000040
#define CAN_MOCTR29_RESRXEN      0x00000080
#define CAN_MOCTR29_RESRXPND     0x00000001
#define CAN_MOCTR29_RESRXUPD     0x00000004
#define CAN_MOCTR29_RESTXEN0     0x00000200
#define CAN_MOCTR29_RESTXEN1     0x00000400
#define CAN_MOCTR29_RESTXPND     0x00000002
#define CAN_MOCTR29_RESTXRQ      0x00000100
#define CAN_MOCTR29_SETDIR       0x08000000
#define CAN_MOCTR29_SETMSGLST    0x00100000
#define CAN_MOCTR29_SETMSGVAL    0x00200000
#define CAN_MOCTR29_SETNEWDAT    0x00080000
#define CAN_MOCTR29_SETRTSEL     0x00400000
#define CAN_MOCTR29_SETRXEN      0x00800000
#define CAN_MOCTR29_SETRXPND     0x00010000
#define CAN_MOCTR29_SETRXUPD     0x00040000
#define CAN_MOCTR29_SETTXEN0     0x02000000
#define CAN_MOCTR29_SETTXEN1     0x04000000
#define CAN_MOCTR29_SETTXPND     0x00020000
#define CAN_MOCTR29_SETTXRQ      0x01000000

// CAN Message Object 3 Control Register
#define CAN_MOCTR3             (*((uword volatile *) 0xF000507C))
#define CAN_MOCTR3_RESDIR        0x00000800
#define CAN_MOCTR3_RESMSGLST     0x00000010
#define CAN_MOCTR3_RESMSGVAL     0x00000020
#define CAN_MOCTR3_RESNEWDAT     0x00000008
#define CAN_MOCTR3_RESRTSEL      0x00000040
#define CAN_MOCTR3_RESRXEN       0x00000080
#define CAN_MOCTR3_RESRXPND      0x00000001
#define CAN_MOCTR3_RESRXUPD      0x00000004
#define CAN_MOCTR3_RESTXEN0      0x00000200
#define CAN_MOCTR3_RESTXEN1      0x00000400
#define CAN_MOCTR3_RESTXPND      0x00000002
#define CAN_MOCTR3_RESTXRQ       0x00000100
#define CAN_MOCTR3_SETDIR        0x08000000
#define CAN_MOCTR3_SETMSGLST     0x00100000
#define CAN_MOCTR3_SETMSGVAL     0x00200000
#define CAN_MOCTR3_SETNEWDAT     0x00080000
#define CAN_MOCTR3_SETRTSEL      0x00400000
#define CAN_MOCTR3_SETRXEN       0x00800000
#define CAN_MOCTR3_SETRXPND      0x00010000
#define CAN_MOCTR3_SETRXUPD      0x00040000
#define CAN_MOCTR3_SETTXEN0      0x02000000
#define CAN_MOCTR3_SETTXEN1      0x04000000
#define CAN_MOCTR3_SETTXPND      0x00020000
#define CAN_MOCTR3_SETTXRQ       0x01000000

// CAN Message Object 30 Control Register
#define CAN_MOCTR30            (*((uword volatile *) 0xF00053DC))
#define CAN_MOCTR30_RESDIR       0x00000800
#define CAN_MOCTR30_RESMSGLST    0x00000010
#define CAN_MOCTR30_RESMSGVAL    0x00000020
#define CAN_MOCTR30_RESNEWDAT    0x00000008
#define CAN_MOCTR30_RESRTSEL     0x00000040
#define CAN_MOCTR30_RESRXEN      0x00000080
#define CAN_MOCTR30_RESRXPND     0x00000001
#define CAN_MOCTR30_RESRXUPD     0x00000004
#define CAN_MOCTR30_RESTXEN0     0x00000200
#define CAN_MOCTR30_RESTXEN1     0x00000400
#define CAN_MOCTR30_RESTXPND     0x00000002
#define CAN_MOCTR30_RESTXRQ      0x00000100
#define CAN_MOCTR30_SETDIR       0x08000000
#define CAN_MOCTR30_SETMSGLST    0x00100000
#define CAN_MOCTR30_SETMSGVAL    0x00200000
#define CAN_MOCTR30_SETNEWDAT    0x00080000
#define CAN_MOCTR30_SETRTSEL     0x00400000
#define CAN_MOCTR30_SETRXEN      0x00800000
#define CAN_MOCTR30_SETRXPND     0x00010000
#define CAN_MOCTR30_SETRXUPD     0x00040000
#define CAN_MOCTR30_SETTXEN0     0x02000000
#define CAN_MOCTR30_SETTXEN1     0x04000000
#define CAN_MOCTR30_SETTXPND     0x00020000
#define CAN_MOCTR30_SETTXRQ      0x01000000

// CAN Message Object 31 Control Register
#define CAN_MOCTR31            (*((uword volatile *) 0xF00053FC))
#define CAN_MOCTR31_RESDIR       0x00000800
#define CAN_MOCTR31_RESMSGLST    0x00000010
#define CAN_MOCTR31_RESMSGVAL    0x00000020
#define CAN_MOCTR31_RESNEWDAT    0x00000008
#define CAN_MOCTR31_RESRTSEL     0x00000040
#define CAN_MOCTR31_RESRXEN      0x00000080
#define CAN_MOCTR31_RESRXPND     0x00000001
#define CAN_MOCTR31_RESRXUPD     0x00000004
#define CAN_MOCTR31_RESTXEN0     0x00000200
#define CAN_MOCTR31_RESTXEN1     0x00000400
#define CAN_MOCTR31_RESTXPND     0x00000002
#define CAN_MOCTR31_RESTXRQ      0x00000100
#define CAN_MOCTR31_SETDIR       0x08000000
#define CAN_MOCTR31_SETMSGLST    0x00100000
#define CAN_MOCTR31_SETMSGVAL    0x00200000
#define CAN_MOCTR31_SETNEWDAT    0x00080000
#define CAN_MOCTR31_SETRTSEL     0x00400000
#define CAN_MOCTR31_SETRXEN      0x00800000
#define CAN_MOCTR31_SETRXPND     0x00010000
#define CAN_MOCTR31_SETRXUPD     0x00040000
#define CAN_MOCTR31_SETTXEN0     0x02000000
#define CAN_MOCTR31_SETTXEN1     0x04000000
#define CAN_MOCTR31_SETTXPND     0x00020000
#define CAN_MOCTR31_SETTXRQ      0x01000000

// CAN Message Object 32 Control Register
#define CAN_MOCTR32            (*((uword volatile *) 0xF000541C))
#define CAN_MOCTR32_RESDIR       0x00000800
#define CAN_MOCTR32_RESMSGLST    0x00000010
#define CAN_MOCTR32_RESMSGVAL    0x00000020
#define CAN_MOCTR32_RESNEWDAT    0x00000008
#define CAN_MOCTR32_RESRTSEL     0x00000040
#define CAN_MOCTR32_RESRXEN      0x00000080
#define CAN_MOCTR32_RESRXPND     0x00000001
#define CAN_MOCTR32_RESRXUPD     0x00000004
#define CAN_MOCTR32_RESTXEN0     0x00000200
#define CAN_MOCTR32_RESTXEN1     0x00000400
#define CAN_MOCTR32_RESTXPND     0x00000002
#define CAN_MOCTR32_RESTXRQ      0x00000100
#define CAN_MOCTR32_SETDIR       0x08000000
#define CAN_MOCTR32_SETMSGLST    0x00100000
#define CAN_MOCTR32_SETMSGVAL    0x00200000
#define CAN_MOCTR32_SETNEWDAT    0x00080000
#define CAN_MOCTR32_SETRTSEL     0x00400000
#define CAN_MOCTR32_SETRXEN      0x00800000
#define CAN_MOCTR32_SETRXPND     0x00010000
#define CAN_MOCTR32_SETRXUPD     0x00040000
#define CAN_MOCTR32_SETTXEN0     0x02000000
#define CAN_MOCTR32_SETTXEN1     0x04000000
#define CAN_MOCTR32_SETTXPND     0x00020000
#define CAN_MOCTR32_SETTXRQ      0x01000000

// CAN Message Object 33 Control Register
#define CAN_MOCTR33            (*((uword volatile *) 0xF000543C))
#define CAN_MOCTR33_RESDIR       0x00000800
#define CAN_MOCTR33_RESMSGLST    0x00000010
#define CAN_MOCTR33_RESMSGVAL    0x00000020
#define CAN_MOCTR33_RESNEWDAT    0x00000008
#define CAN_MOCTR33_RESRTSEL     0x00000040
#define CAN_MOCTR33_RESRXEN      0x00000080
#define CAN_MOCTR33_RESRXPND     0x00000001
#define CAN_MOCTR33_RESRXUPD     0x00000004
#define CAN_MOCTR33_RESTXEN0     0x00000200
#define CAN_MOCTR33_RESTXEN1     0x00000400
#define CAN_MOCTR33_RESTXPND     0x00000002
#define CAN_MOCTR33_RESTXRQ      0x00000100
#define CAN_MOCTR33_SETDIR       0x08000000
#define CAN_MOCTR33_SETMSGLST    0x00100000
#define CAN_MOCTR33_SETMSGVAL    0x00200000
#define CAN_MOCTR33_SETNEWDAT    0x00080000
#define CAN_MOCTR33_SETRTSEL     0x00400000
#define CAN_MOCTR33_SETRXEN      0x00800000
#define CAN_MOCTR33_SETRXPND     0x00010000
#define CAN_MOCTR33_SETRXUPD     0x00040000
#define CAN_MOCTR33_SETTXEN0     0x02000000
#define CAN_MOCTR33_SETTXEN1     0x04000000
#define CAN_MOCTR33_SETTXPND     0x00020000
#define CAN_MOCTR33_SETTXRQ      0x01000000

// CAN Message Object 34 Control Register
#define CAN_MOCTR34            (*((uword volatile *) 0xF000545C))
#define CAN_MOCTR34_RESDIR       0x00000800
#define CAN_MOCTR34_RESMSGLST    0x00000010
#define CAN_MOCTR34_RESMSGVAL    0x00000020
#define CAN_MOCTR34_RESNEWDAT    0x00000008
#define CAN_MOCTR34_RESRTSEL     0x00000040
#define CAN_MOCTR34_RESRXEN      0x00000080
#define CAN_MOCTR34_RESRXPND     0x00000001
#define CAN_MOCTR34_RESRXUPD     0x00000004
#define CAN_MOCTR34_RESTXEN0     0x00000200
#define CAN_MOCTR34_RESTXEN1     0x00000400
#define CAN_MOCTR34_RESTXPND     0x00000002
#define CAN_MOCTR34_RESTXRQ      0x00000100
#define CAN_MOCTR34_SETDIR       0x08000000
#define CAN_MOCTR34_SETMSGLST    0x00100000
#define CAN_MOCTR34_SETMSGVAL    0x00200000
#define CAN_MOCTR34_SETNEWDAT    0x00080000
#define CAN_MOCTR34_SETRTSEL     0x00400000
#define CAN_MOCTR34_SETRXEN      0x00800000
#define CAN_MOCTR34_SETRXPND     0x00010000
#define CAN_MOCTR34_SETRXUPD     0x00040000
#define CAN_MOCTR34_SETTXEN0     0x02000000
#define CAN_MOCTR34_SETTXEN1     0x04000000
#define CAN_MOCTR34_SETTXPND     0x00020000
#define CAN_MOCTR34_SETTXRQ      0x01000000

// CAN Message Object 35 Control Register
#define CAN_MOCTR35            (*((uword volatile *) 0xF000547C))
#define CAN_MOCTR35_RESDIR       0x00000800
#define CAN_MOCTR35_RESMSGLST    0x00000010
#define CAN_MOCTR35_RESMSGVAL    0x00000020
#define CAN_MOCTR35_RESNEWDAT    0x00000008
#define CAN_MOCTR35_RESRTSEL     0x00000040
#define CAN_MOCTR35_RESRXEN      0x00000080
#define CAN_MOCTR35_RESRXPND     0x00000001
#define CAN_MOCTR35_RESRXUPD     0x00000004
#define CAN_MOCTR35_RESTXEN0     0x00000200
#define CAN_MOCTR35_RESTXEN1     0x00000400
#define CAN_MOCTR35_RESTXPND     0x00000002
#define CAN_MOCTR35_RESTXRQ      0x00000100
#define CAN_MOCTR35_SETDIR       0x08000000
#define CAN_MOCTR35_SETMSGLST    0x00100000
#define CAN_MOCTR35_SETMSGVAL    0x00200000
#define CAN_MOCTR35_SETNEWDAT    0x00080000
#define CAN_MOCTR35_SETRTSEL     0x00400000
#define CAN_MOCTR35_SETRXEN      0x00800000
#define CAN_MOCTR35_SETRXPND     0x00010000
#define CAN_MOCTR35_SETRXUPD     0x00040000
#define CAN_MOCTR35_SETTXEN0     0x02000000
#define CAN_MOCTR35_SETTXEN1     0x04000000
#define CAN_MOCTR35_SETTXPND     0x00020000
#define CAN_MOCTR35_SETTXRQ      0x01000000

// CAN Message Object 36 Control Register
#define CAN_MOCTR36            (*((uword volatile *) 0xF000549C))
#define CAN_MOCTR36_RESDIR       0x00000800
#define CAN_MOCTR36_RESMSGLST    0x00000010
#define CAN_MOCTR36_RESMSGVAL    0x00000020
#define CAN_MOCTR36_RESNEWDAT    0x00000008
#define CAN_MOCTR36_RESRTSEL     0x00000040
#define CAN_MOCTR36_RESRXEN      0x00000080
#define CAN_MOCTR36_RESRXPND     0x00000001
#define CAN_MOCTR36_RESRXUPD     0x00000004
#define CAN_MOCTR36_RESTXEN0     0x00000200
#define CAN_MOCTR36_RESTXEN1     0x00000400
#define CAN_MOCTR36_RESTXPND     0x00000002
#define CAN_MOCTR36_RESTXRQ      0x00000100
#define CAN_MOCTR36_SETDIR       0x08000000
#define CAN_MOCTR36_SETMSGLST    0x00100000
#define CAN_MOCTR36_SETMSGVAL    0x00200000
#define CAN_MOCTR36_SETNEWDAT    0x00080000
#define CAN_MOCTR36_SETRTSEL     0x00400000
#define CAN_MOCTR36_SETRXEN      0x00800000
#define CAN_MOCTR36_SETRXPND     0x00010000
#define CAN_MOCTR36_SETRXUPD     0x00040000
#define CAN_MOCTR36_SETTXEN0     0x02000000
#define CAN_MOCTR36_SETTXEN1     0x04000000
#define CAN_MOCTR36_SETTXPND     0x00020000
#define CAN_MOCTR36_SETTXRQ      0x01000000

// CAN Message Object 37 Control Register
#define CAN_MOCTR37            (*((uword volatile *) 0xF00054BC))
#define CAN_MOCTR37_RESDIR       0x00000800
#define CAN_MOCTR37_RESMSGLST    0x00000010
#define CAN_MOCTR37_RESMSGVAL    0x00000020
#define CAN_MOCTR37_RESNEWDAT    0x00000008
#define CAN_MOCTR37_RESRTSEL     0x00000040
#define CAN_MOCTR37_RESRXEN      0x00000080
#define CAN_MOCTR37_RESRXPND     0x00000001
#define CAN_MOCTR37_RESRXUPD     0x00000004
#define CAN_MOCTR37_RESTXEN0     0x00000200
#define CAN_MOCTR37_RESTXEN1     0x00000400
#define CAN_MOCTR37_RESTXPND     0x00000002
#define CAN_MOCTR37_RESTXRQ      0x00000100
#define CAN_MOCTR37_SETDIR       0x08000000
#define CAN_MOCTR37_SETMSGLST    0x00100000
#define CAN_MOCTR37_SETMSGVAL    0x00200000
#define CAN_MOCTR37_SETNEWDAT    0x00080000
#define CAN_MOCTR37_SETRTSEL     0x00400000
#define CAN_MOCTR37_SETRXEN      0x00800000
#define CAN_MOCTR37_SETRXPND     0x00010000
#define CAN_MOCTR37_SETRXUPD     0x00040000
#define CAN_MOCTR37_SETTXEN0     0x02000000
#define CAN_MOCTR37_SETTXEN1     0x04000000
#define CAN_MOCTR37_SETTXPND     0x00020000
#define CAN_MOCTR37_SETTXRQ      0x01000000

// CAN Message Object 38 Control Register
#define CAN_MOCTR38            (*((uword volatile *) 0xF00054DC))
#define CAN_MOCTR38_RESDIR       0x00000800
#define CAN_MOCTR38_RESMSGLST    0x00000010
#define CAN_MOCTR38_RESMSGVAL    0x00000020
#define CAN_MOCTR38_RESNEWDAT    0x00000008
#define CAN_MOCTR38_RESRTSEL     0x00000040
#define CAN_MOCTR38_RESRXEN      0x00000080
#define CAN_MOCTR38_RESRXPND     0x00000001
#define CAN_MOCTR38_RESRXUPD     0x00000004
#define CAN_MOCTR38_RESTXEN0     0x00000200
#define CAN_MOCTR38_RESTXEN1     0x00000400
#define CAN_MOCTR38_RESTXPND     0x00000002
#define CAN_MOCTR38_RESTXRQ      0x00000100
#define CAN_MOCTR38_SETDIR       0x08000000
#define CAN_MOCTR38_SETMSGLST    0x00100000
#define CAN_MOCTR38_SETMSGVAL    0x00200000
#define CAN_MOCTR38_SETNEWDAT    0x00080000
#define CAN_MOCTR38_SETRTSEL     0x00400000
#define CAN_MOCTR38_SETRXEN      0x00800000
#define CAN_MOCTR38_SETRXPND     0x00010000
#define CAN_MOCTR38_SETRXUPD     0x00040000
#define CAN_MOCTR38_SETTXEN0     0x02000000
#define CAN_MOCTR38_SETTXEN1     0x04000000
#define CAN_MOCTR38_SETTXPND     0x00020000
#define CAN_MOCTR38_SETTXRQ      0x01000000

// CAN Message Object 39 Control Register
#define CAN_MOCTR39            (*((uword volatile *) 0xF00054FC))
#define CAN_MOCTR39_RESDIR       0x00000800
#define CAN_MOCTR39_RESMSGLST    0x00000010
#define CAN_MOCTR39_RESMSGVAL    0x00000020
#define CAN_MOCTR39_RESNEWDAT    0x00000008
#define CAN_MOCTR39_RESRTSEL     0x00000040
#define CAN_MOCTR39_RESRXEN      0x00000080
#define CAN_MOCTR39_RESRXPND     0x00000001
#define CAN_MOCTR39_RESRXUPD     0x00000004
#define CAN_MOCTR39_RESTXEN0     0x00000200
#define CAN_MOCTR39_RESTXEN1     0x00000400
#define CAN_MOCTR39_RESTXPND     0x00000002
#define CAN_MOCTR39_RESTXRQ      0x00000100
#define CAN_MOCTR39_SETDIR       0x08000000
#define CAN_MOCTR39_SETMSGLST    0x00100000
#define CAN_MOCTR39_SETMSGVAL    0x00200000
#define CAN_MOCTR39_SETNEWDAT    0x00080000
#define CAN_MOCTR39_SETRTSEL     0x00400000
#define CAN_MOCTR39_SETRXEN      0x00800000
#define CAN_MOCTR39_SETRXPND     0x00010000
#define CAN_MOCTR39_SETRXUPD     0x00040000
#define CAN_MOCTR39_SETTXEN0     0x02000000
#define CAN_MOCTR39_SETTXEN1     0x04000000
#define CAN_MOCTR39_SETTXPND     0x00020000
#define CAN_MOCTR39_SETTXRQ      0x01000000

// CAN Message Object 4 Control Register
#define CAN_MOCTR4             (*((uword volatile *) 0xF000509C))
#define CAN_MOCTR4_RESDIR        0x00000800
#define CAN_MOCTR4_RESMSGLST     0x00000010
#define CAN_MOCTR4_RESMSGVAL     0x00000020
#define CAN_MOCTR4_RESNEWDAT     0x00000008
#define CAN_MOCTR4_RESRTSEL      0x00000040
#define CAN_MOCTR4_RESRXEN       0x00000080
#define CAN_MOCTR4_RESRXPND      0x00000001
#define CAN_MOCTR4_RESRXUPD      0x00000004
#define CAN_MOCTR4_RESTXEN0      0x00000200
#define CAN_MOCTR4_RESTXEN1      0x00000400
#define CAN_MOCTR4_RESTXPND      0x00000002
#define CAN_MOCTR4_RESTXRQ       0x00000100
#define CAN_MOCTR4_SETDIR        0x08000000
#define CAN_MOCTR4_SETMSGLST     0x00100000
#define CAN_MOCTR4_SETMSGVAL     0x00200000
#define CAN_MOCTR4_SETNEWDAT     0x00080000
#define CAN_MOCTR4_SETRTSEL      0x00400000
#define CAN_MOCTR4_SETRXEN       0x00800000
#define CAN_MOCTR4_SETRXPND      0x00010000
#define CAN_MOCTR4_SETRXUPD      0x00040000
#define CAN_MOCTR4_SETTXEN0      0x02000000
#define CAN_MOCTR4_SETTXEN1      0x04000000
#define CAN_MOCTR4_SETTXPND      0x00020000
#define CAN_MOCTR4_SETTXRQ       0x01000000

// CAN Message Object 40 Control Register
#define CAN_MOCTR40            (*((uword volatile *) 0xF000551C))
#define CAN_MOCTR40_RESDIR       0x00000800
#define CAN_MOCTR40_RESMSGLST    0x00000010
#define CAN_MOCTR40_RESMSGVAL    0x00000020
#define CAN_MOCTR40_RESNEWDAT    0x00000008
#define CAN_MOCTR40_RESRTSEL     0x00000040
#define CAN_MOCTR40_RESRXEN      0x00000080
#define CAN_MOCTR40_RESRXPND     0x00000001
#define CAN_MOCTR40_RESRXUPD     0x00000004
#define CAN_MOCTR40_RESTXEN0     0x00000200
#define CAN_MOCTR40_RESTXEN1     0x00000400
#define CAN_MOCTR40_RESTXPND     0x00000002
#define CAN_MOCTR40_RESTXRQ      0x00000100
#define CAN_MOCTR40_SETDIR       0x08000000
#define CAN_MOCTR40_SETMSGLST    0x00100000
#define CAN_MOCTR40_SETMSGVAL    0x00200000
#define CAN_MOCTR40_SETNEWDAT    0x00080000
#define CAN_MOCTR40_SETRTSEL     0x00400000
#define CAN_MOCTR40_SETRXEN      0x00800000
#define CAN_MOCTR40_SETRXPND     0x00010000
#define CAN_MOCTR40_SETRXUPD     0x00040000
#define CAN_MOCTR40_SETTXEN0     0x02000000
#define CAN_MOCTR40_SETTXEN1     0x04000000
#define CAN_MOCTR40_SETTXPND     0x00020000
#define CAN_MOCTR40_SETTXRQ      0x01000000

// CAN Message Object 41 Control Register
#define CAN_MOCTR41            (*((uword volatile *) 0xF000553C))
#define CAN_MOCTR41_RESDIR       0x00000800
#define CAN_MOCTR41_RESMSGLST    0x00000010
#define CAN_MOCTR41_RESMSGVAL    0x00000020
#define CAN_MOCTR41_RESNEWDAT    0x00000008
#define CAN_MOCTR41_RESRTSEL     0x00000040
#define CAN_MOCTR41_RESRXEN      0x00000080
#define CAN_MOCTR41_RESRXPND     0x00000001
#define CAN_MOCTR41_RESRXUPD     0x00000004
#define CAN_MOCTR41_RESTXEN0     0x00000200
#define CAN_MOCTR41_RESTXEN1     0x00000400
#define CAN_MOCTR41_RESTXPND     0x00000002
#define CAN_MOCTR41_RESTXRQ      0x00000100
#define CAN_MOCTR41_SETDIR       0x08000000
#define CAN_MOCTR41_SETMSGLST    0x00100000
#define CAN_MOCTR41_SETMSGVAL    0x00200000
#define CAN_MOCTR41_SETNEWDAT    0x00080000
#define CAN_MOCTR41_SETRTSEL     0x00400000
#define CAN_MOCTR41_SETRXEN      0x00800000
#define CAN_MOCTR41_SETRXPND     0x00010000
#define CAN_MOCTR41_SETRXUPD     0x00040000
#define CAN_MOCTR41_SETTXEN0     0x02000000
#define CAN_MOCTR41_SETTXEN1     0x04000000
#define CAN_MOCTR41_SETTXPND     0x00020000
#define CAN_MOCTR41_SETTXRQ      0x01000000

// CAN Message Object 42 Control Register
#define CAN_MOCTR42            (*((uword volatile *) 0xF000555C))
#define CAN_MOCTR42_RESDIR       0x00000800
#define CAN_MOCTR42_RESMSGLST    0x00000010
#define CAN_MOCTR42_RESMSGVAL    0x00000020
#define CAN_MOCTR42_RESNEWDAT    0x00000008
#define CAN_MOCTR42_RESRTSEL     0x00000040
#define CAN_MOCTR42_RESRXEN      0x00000080
#define CAN_MOCTR42_RESRXPND     0x00000001
#define CAN_MOCTR42_RESRXUPD     0x00000004
#define CAN_MOCTR42_RESTXEN0     0x00000200
#define CAN_MOCTR42_RESTXEN1     0x00000400
#define CAN_MOCTR42_RESTXPND     0x00000002
#define CAN_MOCTR42_RESTXRQ      0x00000100
#define CAN_MOCTR42_SETDIR       0x08000000
#define CAN_MOCTR42_SETMSGLST    0x00100000
#define CAN_MOCTR42_SETMSGVAL    0x00200000
#define CAN_MOCTR42_SETNEWDAT    0x00080000
#define CAN_MOCTR42_SETRTSEL     0x00400000
#define CAN_MOCTR42_SETRXEN      0x00800000
#define CAN_MOCTR42_SETRXPND     0x00010000
#define CAN_MOCTR42_SETRXUPD     0x00040000
#define CAN_MOCTR42_SETTXEN0     0x02000000
#define CAN_MOCTR42_SETTXEN1     0x04000000
#define CAN_MOCTR42_SETTXPND     0x00020000
#define CAN_MOCTR42_SETTXRQ      0x01000000

// CAN Message Object 43 Control Register
#define CAN_MOCTR43            (*((uword volatile *) 0xF000557C))
#define CAN_MOCTR43_RESDIR       0x00000800
#define CAN_MOCTR43_RESMSGLST    0x00000010
#define CAN_MOCTR43_RESMSGVAL    0x00000020
#define CAN_MOCTR43_RESNEWDAT    0x00000008
#define CAN_MOCTR43_RESRTSEL     0x00000040
#define CAN_MOCTR43_RESRXEN      0x00000080
#define CAN_MOCTR43_RESRXPND     0x00000001
#define CAN_MOCTR43_RESRXUPD     0x00000004
#define CAN_MOCTR43_RESTXEN0     0x00000200
#define CAN_MOCTR43_RESTXEN1     0x00000400
#define CAN_MOCTR43_RESTXPND     0x00000002
#define CAN_MOCTR43_RESTXRQ      0x00000100
#define CAN_MOCTR43_SETDIR       0x08000000
#define CAN_MOCTR43_SETMSGLST    0x00100000
#define CAN_MOCTR43_SETMSGVAL    0x00200000
#define CAN_MOCTR43_SETNEWDAT    0x00080000
#define CAN_MOCTR43_SETRTSEL     0x00400000
#define CAN_MOCTR43_SETRXEN      0x00800000
#define CAN_MOCTR43_SETRXPND     0x00010000
#define CAN_MOCTR43_SETRXUPD     0x00040000
#define CAN_MOCTR43_SETTXEN0     0x02000000
#define CAN_MOCTR43_SETTXEN1     0x04000000
#define CAN_MOCTR43_SETTXPND     0x00020000
#define CAN_MOCTR43_SETTXRQ      0x01000000

// CAN Message Object 44 Control Register
#define CAN_MOCTR44            (*((uword volatile *) 0xF000559C))
#define CAN_MOCTR44_RESDIR       0x00000800
#define CAN_MOCTR44_RESMSGLST    0x00000010
#define CAN_MOCTR44_RESMSGVAL    0x00000020
#define CAN_MOCTR44_RESNEWDAT    0x00000008
#define CAN_MOCTR44_RESRTSEL     0x00000040
#define CAN_MOCTR44_RESRXEN      0x00000080
#define CAN_MOCTR44_RESRXPND     0x00000001
#define CAN_MOCTR44_RESRXUPD     0x00000004
#define CAN_MOCTR44_RESTXEN0     0x00000200
#define CAN_MOCTR44_RESTXEN1     0x00000400
#define CAN_MOCTR44_RESTXPND     0x00000002
#define CAN_MOCTR44_RESTXRQ      0x00000100
#define CAN_MOCTR44_SETDIR       0x08000000
#define CAN_MOCTR44_SETMSGLST    0x00100000
#define CAN_MOCTR44_SETMSGVAL    0x00200000
#define CAN_MOCTR44_SETNEWDAT    0x00080000
#define CAN_MOCTR44_SETRTSEL     0x00400000
#define CAN_MOCTR44_SETRXEN      0x00800000
#define CAN_MOCTR44_SETRXPND     0x00010000
#define CAN_MOCTR44_SETRXUPD     0x00040000
#define CAN_MOCTR44_SETTXEN0     0x02000000
#define CAN_MOCTR44_SETTXEN1     0x04000000
#define CAN_MOCTR44_SETTXPND     0x00020000
#define CAN_MOCTR44_SETTXRQ      0x01000000

// CAN Message Object 45 Control Register
#define CAN_MOCTR45            (*((uword volatile *) 0xF00055BC))
#define CAN_MOCTR45_RESDIR       0x00000800
#define CAN_MOCTR45_RESMSGLST    0x00000010
#define CAN_MOCTR45_RESMSGVAL    0x00000020
#define CAN_MOCTR45_RESNEWDAT    0x00000008
#define CAN_MOCTR45_RESRTSEL     0x00000040
#define CAN_MOCTR45_RESRXEN      0x00000080
#define CAN_MOCTR45_RESRXPND     0x00000001
#define CAN_MOCTR45_RESRXUPD     0x00000004
#define CAN_MOCTR45_RESTXEN0     0x00000200
#define CAN_MOCTR45_RESTXEN1     0x00000400
#define CAN_MOCTR45_RESTXPND     0x00000002
#define CAN_MOCTR45_RESTXRQ      0x00000100
#define CAN_MOCTR45_SETDIR       0x08000000
#define CAN_MOCTR45_SETMSGLST    0x00100000
#define CAN_MOCTR45_SETMSGVAL    0x00200000
#define CAN_MOCTR45_SETNEWDAT    0x00080000
#define CAN_MOCTR45_SETRTSEL     0x00400000
#define CAN_MOCTR45_SETRXEN      0x00800000
#define CAN_MOCTR45_SETRXPND     0x00010000
#define CAN_MOCTR45_SETRXUPD     0x00040000
#define CAN_MOCTR45_SETTXEN0     0x02000000
#define CAN_MOCTR45_SETTXEN1     0x04000000
#define CAN_MOCTR45_SETTXPND     0x00020000
#define CAN_MOCTR45_SETTXRQ      0x01000000

// CAN Message Object 46 Control Register
#define CAN_MOCTR46            (*((uword volatile *) 0xF00055DC))
#define CAN_MOCTR46_RESDIR       0x00000800
#define CAN_MOCTR46_RESMSGLST    0x00000010
#define CAN_MOCTR46_RESMSGVAL    0x00000020
#define CAN_MOCTR46_RESNEWDAT    0x00000008
#define CAN_MOCTR46_RESRTSEL     0x00000040
#define CAN_MOCTR46_RESRXEN      0x00000080
#define CAN_MOCTR46_RESRXPND     0x00000001
#define CAN_MOCTR46_RESRXUPD     0x00000004
#define CAN_MOCTR46_RESTXEN0     0x00000200
#define CAN_MOCTR46_RESTXEN1     0x00000400
#define CAN_MOCTR46_RESTXPND     0x00000002
#define CAN_MOCTR46_RESTXRQ      0x00000100
#define CAN_MOCTR46_SETDIR       0x08000000
#define CAN_MOCTR46_SETMSGLST    0x00100000
#define CAN_MOCTR46_SETMSGVAL    0x00200000
#define CAN_MOCTR46_SETNEWDAT    0x00080000
#define CAN_MOCTR46_SETRTSEL     0x00400000
#define CAN_MOCTR46_SETRXEN      0x00800000
#define CAN_MOCTR46_SETRXPND     0x00010000
#define CAN_MOCTR46_SETRXUPD     0x00040000
#define CAN_MOCTR46_SETTXEN0     0x02000000
#define CAN_MOCTR46_SETTXEN1     0x04000000
#define CAN_MOCTR46_SETTXPND     0x00020000
#define CAN_MOCTR46_SETTXRQ      0x01000000

// CAN Message Object 47 Control Register
#define CAN_MOCTR47            (*((uword volatile *) 0xF00055FC))
#define CAN_MOCTR47_RESDIR       0x00000800
#define CAN_MOCTR47_RESMSGLST    0x00000010
#define CAN_MOCTR47_RESMSGVAL    0x00000020
#define CAN_MOCTR47_RESNEWDAT    0x00000008
#define CAN_MOCTR47_RESRTSEL     0x00000040
#define CAN_MOCTR47_RESRXEN      0x00000080
#define CAN_MOCTR47_RESRXPND     0x00000001
#define CAN_MOCTR47_RESRXUPD     0x00000004
#define CAN_MOCTR47_RESTXEN0     0x00000200
#define CAN_MOCTR47_RESTXEN1     0x00000400
#define CAN_MOCTR47_RESTXPND     0x00000002
#define CAN_MOCTR47_RESTXRQ      0x00000100
#define CAN_MOCTR47_SETDIR       0x08000000
#define CAN_MOCTR47_SETMSGLST    0x00100000
#define CAN_MOCTR47_SETMSGVAL    0x00200000
#define CAN_MOCTR47_SETNEWDAT    0x00080000
#define CAN_MOCTR47_SETRTSEL     0x00400000
#define CAN_MOCTR47_SETRXEN      0x00800000
#define CAN_MOCTR47_SETRXPND     0x00010000
#define CAN_MOCTR47_SETRXUPD     0x00040000
#define CAN_MOCTR47_SETTXEN0     0x02000000
#define CAN_MOCTR47_SETTXEN1     0x04000000
#define CAN_MOCTR47_SETTXPND     0x00020000
#define CAN_MOCTR47_SETTXRQ      0x01000000

// CAN Message Object 48 Control Register
#define CAN_MOCTR48            (*((uword volatile *) 0xF000561C))
#define CAN_MOCTR48_RESDIR       0x00000800
#define CAN_MOCTR48_RESMSGLST    0x00000010
#define CAN_MOCTR48_RESMSGVAL    0x00000020
#define CAN_MOCTR48_RESNEWDAT    0x00000008
#define CAN_MOCTR48_RESRTSEL     0x00000040
#define CAN_MOCTR48_RESRXEN      0x00000080
#define CAN_MOCTR48_RESRXPND     0x00000001
#define CAN_MOCTR48_RESRXUPD     0x00000004
#define CAN_MOCTR48_RESTXEN0     0x00000200
#define CAN_MOCTR48_RESTXEN1     0x00000400
#define CAN_MOCTR48_RESTXPND     0x00000002
#define CAN_MOCTR48_RESTXRQ      0x00000100
#define CAN_MOCTR48_SETDIR       0x08000000
#define CAN_MOCTR48_SETMSGLST    0x00100000
#define CAN_MOCTR48_SETMSGVAL    0x00200000
#define CAN_MOCTR48_SETNEWDAT    0x00080000
#define CAN_MOCTR48_SETRTSEL     0x00400000
#define CAN_MOCTR48_SETRXEN      0x00800000
#define CAN_MOCTR48_SETRXPND     0x00010000
#define CAN_MOCTR48_SETRXUPD     0x00040000
#define CAN_MOCTR48_SETTXEN0     0x02000000
#define CAN_MOCTR48_SETTXEN1     0x04000000
#define CAN_MOCTR48_SETTXPND     0x00020000
#define CAN_MOCTR48_SETTXRQ      0x01000000

// CAN Message Object 49 Control Register
#define CAN_MOCTR49            (*((uword volatile *) 0xF000563C))
#define CAN_MOCTR49_RESDIR       0x00000800
#define CAN_MOCTR49_RESMSGLST    0x00000010
#define CAN_MOCTR49_RESMSGVAL    0x00000020
#define CAN_MOCTR49_RESNEWDAT    0x00000008
#define CAN_MOCTR49_RESRTSEL     0x00000040
#define CAN_MOCTR49_RESRXEN      0x00000080
#define CAN_MOCTR49_RESRXPND     0x00000001
#define CAN_MOCTR49_RESRXUPD     0x00000004
#define CAN_MOCTR49_RESTXEN0     0x00000200
#define CAN_MOCTR49_RESTXEN1     0x00000400
#define CAN_MOCTR49_RESTXPND     0x00000002
#define CAN_MOCTR49_RESTXRQ      0x00000100
#define CAN_MOCTR49_SETDIR       0x08000000
#define CAN_MOCTR49_SETMSGLST    0x00100000
#define CAN_MOCTR49_SETMSGVAL    0x00200000
#define CAN_MOCTR49_SETNEWDAT    0x00080000
#define CAN_MOCTR49_SETRTSEL     0x00400000
#define CAN_MOCTR49_SETRXEN      0x00800000
#define CAN_MOCTR49_SETRXPND     0x00010000
#define CAN_MOCTR49_SETRXUPD     0x00040000
#define CAN_MOCTR49_SETTXEN0     0x02000000
#define CAN_MOCTR49_SETTXEN1     0x04000000
#define CAN_MOCTR49_SETTXPND     0x00020000
#define CAN_MOCTR49_SETTXRQ      0x01000000

// CAN Message Object 5 Control Register
#define CAN_MOCTR5             (*((uword volatile *) 0xF00050BC))
#define CAN_MOCTR5_RESDIR        0x00000800
#define CAN_MOCTR5_RESMSGLST     0x00000010
#define CAN_MOCTR5_RESMSGVAL     0x00000020
#define CAN_MOCTR5_RESNEWDAT     0x00000008
#define CAN_MOCTR5_RESRTSEL      0x00000040
#define CAN_MOCTR5_RESRXEN       0x00000080
#define CAN_MOCTR5_RESRXPND      0x00000001
#define CAN_MOCTR5_RESRXUPD      0x00000004
#define CAN_MOCTR5_RESTXEN0      0x00000200
#define CAN_MOCTR5_RESTXEN1      0x00000400
#define CAN_MOCTR5_RESTXPND      0x00000002
#define CAN_MOCTR5_RESTXRQ       0x00000100
#define CAN_MOCTR5_SETDIR        0x08000000
#define CAN_MOCTR5_SETMSGLST     0x00100000
#define CAN_MOCTR5_SETMSGVAL     0x00200000
#define CAN_MOCTR5_SETNEWDAT     0x00080000
#define CAN_MOCTR5_SETRTSEL      0x00400000
#define CAN_MOCTR5_SETRXEN       0x00800000
#define CAN_MOCTR5_SETRXPND      0x00010000
#define CAN_MOCTR5_SETRXUPD      0x00040000
#define CAN_MOCTR5_SETTXEN0      0x02000000
#define CAN_MOCTR5_SETTXEN1      0x04000000
#define CAN_MOCTR5_SETTXPND      0x00020000
#define CAN_MOCTR5_SETTXRQ       0x01000000

// CAN Message Object 50 Control Register
#define CAN_MOCTR50            (*((uword volatile *) 0xF000565C))
#define CAN_MOCTR50_RESDIR       0x00000800
#define CAN_MOCTR50_RESMSGLST    0x00000010
#define CAN_MOCTR50_RESMSGVAL    0x00000020
#define CAN_MOCTR50_RESNEWDAT    0x00000008
#define CAN_MOCTR50_RESRTSEL     0x00000040
#define CAN_MOCTR50_RESRXEN      0x00000080
#define CAN_MOCTR50_RESRXPND     0x00000001
#define CAN_MOCTR50_RESRXUPD     0x00000004
#define CAN_MOCTR50_RESTXEN0     0x00000200
#define CAN_MOCTR50_RESTXEN1     0x00000400
#define CAN_MOCTR50_RESTXPND     0x00000002
#define CAN_MOCTR50_RESTXRQ      0x00000100
#define CAN_MOCTR50_SETDIR       0x08000000
#define CAN_MOCTR50_SETMSGLST    0x00100000
#define CAN_MOCTR50_SETMSGVAL    0x00200000
#define CAN_MOCTR50_SETNEWDAT    0x00080000
#define CAN_MOCTR50_SETRTSEL     0x00400000
#define CAN_MOCTR50_SETRXEN      0x00800000
#define CAN_MOCTR50_SETRXPND     0x00010000
#define CAN_MOCTR50_SETRXUPD     0x00040000
#define CAN_MOCTR50_SETTXEN0     0x02000000
#define CAN_MOCTR50_SETTXEN1     0x04000000
#define CAN_MOCTR50_SETTXPND     0x00020000
#define CAN_MOCTR50_SETTXRQ      0x01000000

// CAN Message Object 51 Control Register
#define CAN_MOCTR51            (*((uword volatile *) 0xF000567C))
#define CAN_MOCTR51_RESDIR       0x00000800
#define CAN_MOCTR51_RESMSGLST    0x00000010
#define CAN_MOCTR51_RESMSGVAL    0x00000020
#define CAN_MOCTR51_RESNEWDAT    0x00000008
#define CAN_MOCTR51_RESRTSEL     0x00000040
#define CAN_MOCTR51_RESRXEN      0x00000080
#define CAN_MOCTR51_RESRXPND     0x00000001
#define CAN_MOCTR51_RESRXUPD     0x00000004
#define CAN_MOCTR51_RESTXEN0     0x00000200
#define CAN_MOCTR51_RESTXEN1     0x00000400
#define CAN_MOCTR51_RESTXPND     0x00000002
#define CAN_MOCTR51_RESTXRQ      0x00000100
#define CAN_MOCTR51_SETDIR       0x08000000
#define CAN_MOCTR51_SETMSGLST    0x00100000
#define CAN_MOCTR51_SETMSGVAL    0x00200000
#define CAN_MOCTR51_SETNEWDAT    0x00080000
#define CAN_MOCTR51_SETRTSEL     0x00400000
#define CAN_MOCTR51_SETRXEN      0x00800000
#define CAN_MOCTR51_SETRXPND     0x00010000
#define CAN_MOCTR51_SETRXUPD     0x00040000
#define CAN_MOCTR51_SETTXEN0     0x02000000
#define CAN_MOCTR51_SETTXEN1     0x04000000
#define CAN_MOCTR51_SETTXPND     0x00020000
#define CAN_MOCTR51_SETTXRQ      0x01000000

// CAN Message Object 52 Control Register
#define CAN_MOCTR52            (*((uword volatile *) 0xF000569C))
#define CAN_MOCTR52_RESDIR       0x00000800
#define CAN_MOCTR52_RESMSGLST    0x00000010
#define CAN_MOCTR52_RESMSGVAL    0x00000020
#define CAN_MOCTR52_RESNEWDAT    0x00000008
#define CAN_MOCTR52_RESRTSEL     0x00000040
#define CAN_MOCTR52_RESRXEN      0x00000080
#define CAN_MOCTR52_RESRXPND     0x00000001
#define CAN_MOCTR52_RESRXUPD     0x00000004
#define CAN_MOCTR52_RESTXEN0     0x00000200
#define CAN_MOCTR52_RESTXEN1     0x00000400
#define CAN_MOCTR52_RESTXPND     0x00000002
#define CAN_MOCTR52_RESTXRQ      0x00000100
#define CAN_MOCTR52_SETDIR       0x08000000
#define CAN_MOCTR52_SETMSGLST    0x00100000
#define CAN_MOCTR52_SETMSGVAL    0x00200000
#define CAN_MOCTR52_SETNEWDAT    0x00080000
#define CAN_MOCTR52_SETRTSEL     0x00400000
#define CAN_MOCTR52_SETRXEN      0x00800000
#define CAN_MOCTR52_SETRXPND     0x00010000
#define CAN_MOCTR52_SETRXUPD     0x00040000
#define CAN_MOCTR52_SETTXEN0     0x02000000
#define CAN_MOCTR52_SETTXEN1     0x04000000
#define CAN_MOCTR52_SETTXPND     0x00020000
#define CAN_MOCTR52_SETTXRQ      0x01000000

// CAN Message Object 53 Control Register
#define CAN_MOCTR53            (*((uword volatile *) 0xF00056BC))
#define CAN_MOCTR53_RESDIR       0x00000800
#define CAN_MOCTR53_RESMSGLST    0x00000010
#define CAN_MOCTR53_RESMSGVAL    0x00000020
#define CAN_MOCTR53_RESNEWDAT    0x00000008
#define CAN_MOCTR53_RESRTSEL     0x00000040
#define CAN_MOCTR53_RESRXEN      0x00000080
#define CAN_MOCTR53_RESRXPND     0x00000001
#define CAN_MOCTR53_RESRXUPD     0x00000004
#define CAN_MOCTR53_RESTXEN0     0x00000200
#define CAN_MOCTR53_RESTXEN1     0x00000400
#define CAN_MOCTR53_RESTXPND     0x00000002
#define CAN_MOCTR53_RESTXRQ      0x00000100
#define CAN_MOCTR53_SETDIR       0x08000000
#define CAN_MOCTR53_SETMSGLST    0x00100000
#define CAN_MOCTR53_SETMSGVAL    0x00200000
#define CAN_MOCTR53_SETNEWDAT    0x00080000
#define CAN_MOCTR53_SETRTSEL     0x00400000
#define CAN_MOCTR53_SETRXEN      0x00800000
#define CAN_MOCTR53_SETRXPND     0x00010000
#define CAN_MOCTR53_SETRXUPD     0x00040000
#define CAN_MOCTR53_SETTXEN0     0x02000000
#define CAN_MOCTR53_SETTXEN1     0x04000000
#define CAN_MOCTR53_SETTXPND     0x00020000
#define CAN_MOCTR53_SETTXRQ      0x01000000

// CAN Message Object 54 Control Register
#define CAN_MOCTR54            (*((uword volatile *) 0xF00056DC))
#define CAN_MOCTR54_RESDIR       0x00000800
#define CAN_MOCTR54_RESMSGLST    0x00000010
#define CAN_MOCTR54_RESMSGVAL    0x00000020
#define CAN_MOCTR54_RESNEWDAT    0x00000008
#define CAN_MOCTR54_RESRTSEL     0x00000040
#define CAN_MOCTR54_RESRXEN      0x00000080
#define CAN_MOCTR54_RESRXPND     0x00000001
#define CAN_MOCTR54_RESRXUPD     0x00000004
#define CAN_MOCTR54_RESTXEN0     0x00000200
#define CAN_MOCTR54_RESTXEN1     0x00000400
#define CAN_MOCTR54_RESTXPND     0x00000002
#define CAN_MOCTR54_RESTXRQ      0x00000100
#define CAN_MOCTR54_SETDIR       0x08000000
#define CAN_MOCTR54_SETMSGLST    0x00100000
#define CAN_MOCTR54_SETMSGVAL    0x00200000
#define CAN_MOCTR54_SETNEWDAT    0x00080000
#define CAN_MOCTR54_SETRTSEL     0x00400000
#define CAN_MOCTR54_SETRXEN      0x00800000
#define CAN_MOCTR54_SETRXPND     0x00010000
#define CAN_MOCTR54_SETRXUPD     0x00040000
#define CAN_MOCTR54_SETTXEN0     0x02000000
#define CAN_MOCTR54_SETTXEN1     0x04000000
#define CAN_MOCTR54_SETTXPND     0x00020000
#define CAN_MOCTR54_SETTXRQ      0x01000000

// CAN Message Object 55 Control Register
#define CAN_MOCTR55            (*((uword volatile *) 0xF00056FC))
#define CAN_MOCTR55_RESDIR       0x00000800
#define CAN_MOCTR55_RESMSGLST    0x00000010
#define CAN_MOCTR55_RESMSGVAL    0x00000020
#define CAN_MOCTR55_RESNEWDAT    0x00000008
#define CAN_MOCTR55_RESRTSEL     0x00000040
#define CAN_MOCTR55_RESRXEN      0x00000080
#define CAN_MOCTR55_RESRXPND     0x00000001
#define CAN_MOCTR55_RESRXUPD     0x00000004
#define CAN_MOCTR55_RESTXEN0     0x00000200
#define CAN_MOCTR55_RESTXEN1     0x00000400
#define CAN_MOCTR55_RESTXPND     0x00000002
#define CAN_MOCTR55_RESTXRQ      0x00000100
#define CAN_MOCTR55_SETDIR       0x08000000
#define CAN_MOCTR55_SETMSGLST    0x00100000
#define CAN_MOCTR55_SETMSGVAL    0x00200000
#define CAN_MOCTR55_SETNEWDAT    0x00080000
#define CAN_MOCTR55_SETRTSEL     0x00400000
#define CAN_MOCTR55_SETRXEN      0x00800000
#define CAN_MOCTR55_SETRXPND     0x00010000
#define CAN_MOCTR55_SETRXUPD     0x00040000
#define CAN_MOCTR55_SETTXEN0     0x02000000
#define CAN_MOCTR55_SETTXEN1     0x04000000
#define CAN_MOCTR55_SETTXPND     0x00020000
#define CAN_MOCTR55_SETTXRQ      0x01000000

// CAN Message Object 56 Control Register
#define CAN_MOCTR56            (*((uword volatile *) 0xF000571C))
#define CAN_MOCTR56_RESDIR       0x00000800
#define CAN_MOCTR56_RESMSGLST    0x00000010
#define CAN_MOCTR56_RESMSGVAL    0x00000020
#define CAN_MOCTR56_RESNEWDAT    0x00000008
#define CAN_MOCTR56_RESRTSEL     0x00000040
#define CAN_MOCTR56_RESRXEN      0x00000080
#define CAN_MOCTR56_RESRXPND     0x00000001
#define CAN_MOCTR56_RESRXUPD     0x00000004
#define CAN_MOCTR56_RESTXEN0     0x00000200
#define CAN_MOCTR56_RESTXEN1     0x00000400
#define CAN_MOCTR56_RESTXPND     0x00000002
#define CAN_MOCTR56_RESTXRQ      0x00000100
#define CAN_MOCTR56_SETDIR       0x08000000
#define CAN_MOCTR56_SETMSGLST    0x00100000
#define CAN_MOCTR56_SETMSGVAL    0x00200000
#define CAN_MOCTR56_SETNEWDAT    0x00080000
#define CAN_MOCTR56_SETRTSEL     0x00400000
#define CAN_MOCTR56_SETRXEN      0x00800000
#define CAN_MOCTR56_SETRXPND     0x00010000
#define CAN_MOCTR56_SETRXUPD     0x00040000
#define CAN_MOCTR56_SETTXEN0     0x02000000
#define CAN_MOCTR56_SETTXEN1     0x04000000
#define CAN_MOCTR56_SETTXPND     0x00020000
#define CAN_MOCTR56_SETTXRQ      0x01000000

// CAN Message Object 57 Control Register
#define CAN_MOCTR57            (*((uword volatile *) 0xF000573C))
#define CAN_MOCTR57_RESDIR       0x00000800
#define CAN_MOCTR57_RESMSGLST    0x00000010
#define CAN_MOCTR57_RESMSGVAL    0x00000020
#define CAN_MOCTR57_RESNEWDAT    0x00000008
#define CAN_MOCTR57_RESRTSEL     0x00000040
#define CAN_MOCTR57_RESRXEN      0x00000080
#define CAN_MOCTR57_RESRXPND     0x00000001
#define CAN_MOCTR57_RESRXUPD     0x00000004
#define CAN_MOCTR57_RESTXEN0     0x00000200
#define CAN_MOCTR57_RESTXEN1     0x00000400
#define CAN_MOCTR57_RESTXPND     0x00000002
#define CAN_MOCTR57_RESTXRQ      0x00000100
#define CAN_MOCTR57_SETDIR       0x08000000
#define CAN_MOCTR57_SETMSGLST    0x00100000
#define CAN_MOCTR57_SETMSGVAL    0x00200000
#define CAN_MOCTR57_SETNEWDAT    0x00080000
#define CAN_MOCTR57_SETRTSEL     0x00400000
#define CAN_MOCTR57_SETRXEN      0x00800000
#define CAN_MOCTR57_SETRXPND     0x00010000
#define CAN_MOCTR57_SETRXUPD     0x00040000
#define CAN_MOCTR57_SETTXEN0     0x02000000
#define CAN_MOCTR57_SETTXEN1     0x04000000
#define CAN_MOCTR57_SETTXPND     0x00020000
#define CAN_MOCTR57_SETTXRQ      0x01000000

// CAN Message Object 58 Control Register
#define CAN_MOCTR58            (*((uword volatile *) 0xF000575C))
#define CAN_MOCTR58_RESDIR       0x00000800
#define CAN_MOCTR58_RESMSGLST    0x00000010
#define CAN_MOCTR58_RESMSGVAL    0x00000020
#define CAN_MOCTR58_RESNEWDAT    0x00000008
#define CAN_MOCTR58_RESRTSEL     0x00000040
#define CAN_MOCTR58_RESRXEN      0x00000080
#define CAN_MOCTR58_RESRXPND     0x00000001
#define CAN_MOCTR58_RESRXUPD     0x00000004
#define CAN_MOCTR58_RESTXEN0     0x00000200
#define CAN_MOCTR58_RESTXEN1     0x00000400
#define CAN_MOCTR58_RESTXPND     0x00000002
#define CAN_MOCTR58_RESTXRQ      0x00000100
#define CAN_MOCTR58_SETDIR       0x08000000
#define CAN_MOCTR58_SETMSGLST    0x00100000
#define CAN_MOCTR58_SETMSGVAL    0x00200000
#define CAN_MOCTR58_SETNEWDAT    0x00080000
#define CAN_MOCTR58_SETRTSEL     0x00400000
#define CAN_MOCTR58_SETRXEN      0x00800000
#define CAN_MOCTR58_SETRXPND     0x00010000
#define CAN_MOCTR58_SETRXUPD     0x00040000
#define CAN_MOCTR58_SETTXEN0     0x02000000
#define CAN_MOCTR58_SETTXEN1     0x04000000
#define CAN_MOCTR58_SETTXPND     0x00020000
#define CAN_MOCTR58_SETTXRQ      0x01000000

// CAN Message Object 59 Control Register
#define CAN_MOCTR59            (*((uword volatile *) 0xF000577C))
#define CAN_MOCTR59_RESDIR       0x00000800
#define CAN_MOCTR59_RESMSGLST    0x00000010
#define CAN_MOCTR59_RESMSGVAL    0x00000020
#define CAN_MOCTR59_RESNEWDAT    0x00000008
#define CAN_MOCTR59_RESRTSEL     0x00000040
#define CAN_MOCTR59_RESRXEN      0x00000080
#define CAN_MOCTR59_RESRXPND     0x00000001
#define CAN_MOCTR59_RESRXUPD     0x00000004
#define CAN_MOCTR59_RESTXEN0     0x00000200
#define CAN_MOCTR59_RESTXEN1     0x00000400
#define CAN_MOCTR59_RESTXPND     0x00000002
#define CAN_MOCTR59_RESTXRQ      0x00000100
#define CAN_MOCTR59_SETDIR       0x08000000
#define CAN_MOCTR59_SETMSGLST    0x00100000
#define CAN_MOCTR59_SETMSGVAL    0x00200000
#define CAN_MOCTR59_SETNEWDAT    0x00080000
#define CAN_MOCTR59_SETRTSEL     0x00400000
#define CAN_MOCTR59_SETRXEN      0x00800000
#define CAN_MOCTR59_SETRXPND     0x00010000
#define CAN_MOCTR59_SETRXUPD     0x00040000
#define CAN_MOCTR59_SETTXEN0     0x02000000
#define CAN_MOCTR59_SETTXEN1     0x04000000
#define CAN_MOCTR59_SETTXPND     0x00020000
#define CAN_MOCTR59_SETTXRQ      0x01000000

// CAN Message Object 6 Control Register
#define CAN_MOCTR6             (*((uword volatile *) 0xF00050DC))
#define CAN_MOCTR6_RESDIR        0x00000800
#define CAN_MOCTR6_RESMSGLST     0x00000010
#define CAN_MOCTR6_RESMSGVAL     0x00000020
#define CAN_MOCTR6_RESNEWDAT     0x00000008
#define CAN_MOCTR6_RESRTSEL      0x00000040
#define CAN_MOCTR6_RESRXEN       0x00000080
#define CAN_MOCTR6_RESRXPND      0x00000001
#define CAN_MOCTR6_RESRXUPD      0x00000004
#define CAN_MOCTR6_RESTXEN0      0x00000200
#define CAN_MOCTR6_RESTXEN1      0x00000400
#define CAN_MOCTR6_RESTXPND      0x00000002
#define CAN_MOCTR6_RESTXRQ       0x00000100
#define CAN_MOCTR6_SETDIR        0x08000000
#define CAN_MOCTR6_SETMSGLST     0x00100000
#define CAN_MOCTR6_SETMSGVAL     0x00200000
#define CAN_MOCTR6_SETNEWDAT     0x00080000
#define CAN_MOCTR6_SETRTSEL      0x00400000
#define CAN_MOCTR6_SETRXEN       0x00800000
#define CAN_MOCTR6_SETRXPND      0x00010000
#define CAN_MOCTR6_SETRXUPD      0x00040000
#define CAN_MOCTR6_SETTXEN0      0x02000000
#define CAN_MOCTR6_SETTXEN1      0x04000000
#define CAN_MOCTR6_SETTXPND      0x00020000
#define CAN_MOCTR6_SETTXRQ       0x01000000

// CAN Message Object 60 Control Register
#define CAN_MOCTR60            (*((uword volatile *) 0xF000579C))
#define CAN_MOCTR60_RESDIR       0x00000800
#define CAN_MOCTR60_RESMSGLST    0x00000010
#define CAN_MOCTR60_RESMSGVAL    0x00000020
#define CAN_MOCTR60_RESNEWDAT    0x00000008
#define CAN_MOCTR60_RESRTSEL     0x00000040
#define CAN_MOCTR60_RESRXEN      0x00000080
#define CAN_MOCTR60_RESRXPND     0x00000001
#define CAN_MOCTR60_RESRXUPD     0x00000004
#define CAN_MOCTR60_RESTXEN0     0x00000200
#define CAN_MOCTR60_RESTXEN1     0x00000400
#define CAN_MOCTR60_RESTXPND     0x00000002
#define CAN_MOCTR60_RESTXRQ      0x00000100
#define CAN_MOCTR60_SETDIR       0x08000000
#define CAN_MOCTR60_SETMSGLST    0x00100000
#define CAN_MOCTR60_SETMSGVAL    0x00200000
#define CAN_MOCTR60_SETNEWDAT    0x00080000
#define CAN_MOCTR60_SETRTSEL     0x00400000
#define CAN_MOCTR60_SETRXEN      0x00800000
#define CAN_MOCTR60_SETRXPND     0x00010000
#define CAN_MOCTR60_SETRXUPD     0x00040000
#define CAN_MOCTR60_SETTXEN0     0x02000000
#define CAN_MOCTR60_SETTXEN1     0x04000000
#define CAN_MOCTR60_SETTXPND     0x00020000
#define CAN_MOCTR60_SETTXRQ      0x01000000

// CAN Message Object 61 Control Register
#define CAN_MOCTR61            (*((uword volatile *) 0xF00057BC))
#define CAN_MOCTR61_RESDIR       0x00000800
#define CAN_MOCTR61_RESMSGLST    0x00000010
#define CAN_MOCTR61_RESMSGVAL    0x00000020
#define CAN_MOCTR61_RESNEWDAT    0x00000008
#define CAN_MOCTR61_RESRTSEL     0x00000040
#define CAN_MOCTR61_RESRXEN      0x00000080
#define CAN_MOCTR61_RESRXPND     0x00000001
#define CAN_MOCTR61_RESRXUPD     0x00000004
#define CAN_MOCTR61_RESTXEN0     0x00000200
#define CAN_MOCTR61_RESTXEN1     0x00000400
#define CAN_MOCTR61_RESTXPND     0x00000002
#define CAN_MOCTR61_RESTXRQ      0x00000100
#define CAN_MOCTR61_SETDIR       0x08000000
#define CAN_MOCTR61_SETMSGLST    0x00100000
#define CAN_MOCTR61_SETMSGVAL    0x00200000
#define CAN_MOCTR61_SETNEWDAT    0x00080000
#define CAN_MOCTR61_SETRTSEL     0x00400000
#define CAN_MOCTR61_SETRXEN      0x00800000
#define CAN_MOCTR61_SETRXPND     0x00010000
#define CAN_MOCTR61_SETRXUPD     0x00040000
#define CAN_MOCTR61_SETTXEN0     0x02000000
#define CAN_MOCTR61_SETTXEN1     0x04000000
#define CAN_MOCTR61_SETTXPND     0x00020000
#define CAN_MOCTR61_SETTXRQ      0x01000000

// CAN Message Object 62 Control Register
#define CAN_MOCTR62            (*((uword volatile *) 0xF00057DC))
#define CAN_MOCTR62_RESDIR       0x00000800
#define CAN_MOCTR62_RESMSGLST    0x00000010
#define CAN_MOCTR62_RESMSGVAL    0x00000020
#define CAN_MOCTR62_RESNEWDAT    0x00000008
#define CAN_MOCTR62_RESRTSEL     0x00000040
#define CAN_MOCTR62_RESRXEN      0x00000080
#define CAN_MOCTR62_RESRXPND     0x00000001
#define CAN_MOCTR62_RESRXUPD     0x00000004
#define CAN_MOCTR62_RESTXEN0     0x00000200
#define CAN_MOCTR62_RESTXEN1     0x00000400
#define CAN_MOCTR62_RESTXPND     0x00000002
#define CAN_MOCTR62_RESTXRQ      0x00000100
#define CAN_MOCTR62_SETDIR       0x08000000
#define CAN_MOCTR62_SETMSGLST    0x00100000
#define CAN_MOCTR62_SETMSGVAL    0x00200000
#define CAN_MOCTR62_SETNEWDAT    0x00080000
#define CAN_MOCTR62_SETRTSEL     0x00400000
#define CAN_MOCTR62_SETRXEN      0x00800000
#define CAN_MOCTR62_SETRXPND     0x00010000
#define CAN_MOCTR62_SETRXUPD     0x00040000
#define CAN_MOCTR62_SETTXEN0     0x02000000
#define CAN_MOCTR62_SETTXEN1     0x04000000
#define CAN_MOCTR62_SETTXPND     0x00020000
#define CAN_MOCTR62_SETTXRQ      0x01000000

// CAN Message Object 63 Control Register
#define CAN_MOCTR63            (*((uword volatile *) 0xF00057FC))
#define CAN_MOCTR63_RESDIR       0x00000800
#define CAN_MOCTR63_RESMSGLST    0x00000010
#define CAN_MOCTR63_RESMSGVAL    0x00000020
#define CAN_MOCTR63_RESNEWDAT    0x00000008
#define CAN_MOCTR63_RESRTSEL     0x00000040
#define CAN_MOCTR63_RESRXEN      0x00000080
#define CAN_MOCTR63_RESRXPND     0x00000001
#define CAN_MOCTR63_RESRXUPD     0x00000004
#define CAN_MOCTR63_RESTXEN0     0x00000200
#define CAN_MOCTR63_RESTXEN1     0x00000400
#define CAN_MOCTR63_RESTXPND     0x00000002
#define CAN_MOCTR63_RESTXRQ      0x00000100
#define CAN_MOCTR63_SETDIR       0x08000000
#define CAN_MOCTR63_SETMSGLST    0x00100000
#define CAN_MOCTR63_SETMSGVAL    0x00200000
#define CAN_MOCTR63_SETNEWDAT    0x00080000
#define CAN_MOCTR63_SETRTSEL     0x00400000
#define CAN_MOCTR63_SETRXEN      0x00800000
#define CAN_MOCTR63_SETRXPND     0x00010000
#define CAN_MOCTR63_SETRXUPD     0x00040000
#define CAN_MOCTR63_SETTXEN0     0x02000000
#define CAN_MOCTR63_SETTXEN1     0x04000000
#define CAN_MOCTR63_SETTXPND     0x00020000
#define CAN_MOCTR63_SETTXRQ      0x01000000

// CAN Message Object 7 Control Register
#define CAN_MOCTR7             (*((uword volatile *) 0xF00050FC))
#define CAN_MOCTR7_RESDIR        0x00000800
#define CAN_MOCTR7_RESMSGLST     0x00000010
#define CAN_MOCTR7_RESMSGVAL     0x00000020
#define CAN_MOCTR7_RESNEWDAT     0x00000008
#define CAN_MOCTR7_RESRTSEL      0x00000040
#define CAN_MOCTR7_RESRXEN       0x00000080
#define CAN_MOCTR7_RESRXPND      0x00000001
#define CAN_MOCTR7_RESRXUPD      0x00000004
#define CAN_MOCTR7_RESTXEN0      0x00000200
#define CAN_MOCTR7_RESTXEN1      0x00000400
#define CAN_MOCTR7_RESTXPND      0x00000002
#define CAN_MOCTR7_RESTXRQ       0x00000100
#define CAN_MOCTR7_SETDIR        0x08000000
#define CAN_MOCTR7_SETMSGLST     0x00100000
#define CAN_MOCTR7_SETMSGVAL     0x00200000
#define CAN_MOCTR7_SETNEWDAT     0x00080000
#define CAN_MOCTR7_SETRTSEL      0x00400000
#define CAN_MOCTR7_SETRXEN       0x00800000
#define CAN_MOCTR7_SETRXPND      0x00010000
#define CAN_MOCTR7_SETRXUPD      0x00040000
#define CAN_MOCTR7_SETTXEN0      0x02000000
#define CAN_MOCTR7_SETTXEN1      0x04000000
#define CAN_MOCTR7_SETTXPND      0x00020000
#define CAN_MOCTR7_SETTXRQ       0x01000000

// CAN Message Object 8 Control Register
#define CAN_MOCTR8             (*((uword volatile *) 0xF000511C))
#define CAN_MOCTR8_RESDIR        0x00000800
#define CAN_MOCTR8_RESMSGLST     0x00000010
#define CAN_MOCTR8_RESMSGVAL     0x00000020
#define CAN_MOCTR8_RESNEWDAT     0x00000008
#define CAN_MOCTR8_RESRTSEL      0x00000040
#define CAN_MOCTR8_RESRXEN       0x00000080
#define CAN_MOCTR8_RESRXPND      0x00000001
#define CAN_MOCTR8_RESRXUPD      0x00000004
#define CAN_MOCTR8_RESTXEN0      0x00000200
#define CAN_MOCTR8_RESTXEN1      0x00000400
#define CAN_MOCTR8_RESTXPND      0x00000002
#define CAN_MOCTR8_RESTXRQ       0x00000100
#define CAN_MOCTR8_SETDIR        0x08000000
#define CAN_MOCTR8_SETMSGLST     0x00100000
#define CAN_MOCTR8_SETMSGVAL     0x00200000
#define CAN_MOCTR8_SETNEWDAT     0x00080000
#define CAN_MOCTR8_SETRTSEL      0x00400000
#define CAN_MOCTR8_SETRXEN       0x00800000
#define CAN_MOCTR8_SETRXPND      0x00010000
#define CAN_MOCTR8_SETRXUPD      0x00040000
#define CAN_MOCTR8_SETTXEN0      0x02000000
#define CAN_MOCTR8_SETTXEN1      0x04000000
#define CAN_MOCTR8_SETTXPND      0x00020000
#define CAN_MOCTR8_SETTXRQ       0x01000000

// CAN Message Object 9 Control Register
#define CAN_MOCTR9             (*((uword volatile *) 0xF000513C))
#define CAN_MOCTR9_RESDIR        0x00000800
#define CAN_MOCTR9_RESMSGLST     0x00000010
#define CAN_MOCTR9_RESMSGVAL     0x00000020
#define CAN_MOCTR9_RESNEWDAT     0x00000008
#define CAN_MOCTR9_RESRTSEL      0x00000040
#define CAN_MOCTR9_RESRXEN       0x00000080
#define CAN_MOCTR9_RESRXPND      0x00000001
#define CAN_MOCTR9_RESRXUPD      0x00000004
#define CAN_MOCTR9_RESTXEN0      0x00000200
#define CAN_MOCTR9_RESTXEN1      0x00000400
#define CAN_MOCTR9_RESTXPND      0x00000002
#define CAN_MOCTR9_RESTXRQ       0x00000100
#define CAN_MOCTR9_SETDIR        0x08000000
#define CAN_MOCTR9_SETMSGLST     0x00100000
#define CAN_MOCTR9_SETMSGVAL     0x00200000
#define CAN_MOCTR9_SETNEWDAT     0x00080000
#define CAN_MOCTR9_SETRTSEL      0x00400000
#define CAN_MOCTR9_SETRXEN       0x00800000
#define CAN_MOCTR9_SETRXPND      0x00010000
#define CAN_MOCTR9_SETRXUPD      0x00040000
#define CAN_MOCTR9_SETTXEN0      0x02000000
#define CAN_MOCTR9_SETTXEN1      0x04000000
#define CAN_MOCTR9_SETTXPND      0x00020000
#define CAN_MOCTR9_SETTXRQ       0x01000000

// CAN Message Object 0 Data Register High
#define CAN_MODATAH0           (*((uword volatile *) 0xF0005014))

// CAN Message Object 1 Data Register High
#define CAN_MODATAH1           (*((uword volatile *) 0xF0005034))

// CAN Message Object 10 Data Register High
#define CAN_MODATAH10          (*((uword volatile *) 0xF0005154))

// CAN Message Object 11 Data Register High
#define CAN_MODATAH11          (*((uword volatile *) 0xF0005174))

// CAN Message Object 12 Data Register High
#define CAN_MODATAH12          (*((uword volatile *) 0xF0005194))

// CAN Message Object 13 Data Register High
#define CAN_MODATAH13          (*((uword volatile *) 0xF00051B4))

// CAN Message Object 14 Data Register High
#define CAN_MODATAH14          (*((uword volatile *) 0xF00051D4))

// CAN Message Object 15 Data Register High
#define CAN_MODATAH15          (*((uword volatile *) 0xF00051F4))

// CAN Message Object 16 Data Register High
#define CAN_MODATAH16          (*((uword volatile *) 0xF0005214))

// CAN Message Object 17 Data Register High
#define CAN_MODATAH17          (*((uword volatile *) 0xF0005234))

// CAN Message Object 18 Data Register High
#define CAN_MODATAH18          (*((uword volatile *) 0xF0005254))

// CAN Message Object 19 Data Register High
#define CAN_MODATAH19          (*((uword volatile *) 0xF0005274))

// CAN Message Object 2 Data Register High
#define CAN_MODATAH2           (*((uword volatile *) 0xF0005054))

// CAN Message Object 20 Data Register High
#define CAN_MODATAH20          (*((uword volatile *) 0xF0005294))

// CAN Message Object 21 Data Register High
#define CAN_MODATAH21          (*((uword volatile *) 0xF00052B4))

// CAN Message Object 22 Data Register High
#define CAN_MODATAH22          (*((uword volatile *) 0xF00052D4))

// CAN Message Object 23 Data Register High
#define CAN_MODATAH23          (*((uword volatile *) 0xF00052F4))

// CAN Message Object 24 Data Register High
#define CAN_MODATAH24          (*((uword volatile *) 0xF0005314))

// CAN Message Object 25 Data Register High
#define CAN_MODATAH25          (*((uword volatile *) 0xF0005334))

// CAN Message Object 26 Data Register High
#define CAN_MODATAH26          (*((uword volatile *) 0xF0005354))

// CAN Message Object 27 Data Register High
#define CAN_MODATAH27          (*((uword volatile *) 0xF0005374))

// CAN Message Object 28 Data Register High
#define CAN_MODATAH28          (*((uword volatile *) 0xF0005394))

// CAN Message Object 29 Data Register High
#define CAN_MODATAH29          (*((uword volatile *) 0xF00053B4))

// CAN Message Object 3 Data Register High
#define CAN_MODATAH3           (*((uword volatile *) 0xF0005074))

// CAN Message Object 30 Data Register High
#define CAN_MODATAH30          (*((uword volatile *) 0xF00053D4))

// CAN Message Object 31 Data Register High
#define CAN_MODATAH31          (*((uword volatile *) 0xF00053F4))

// CAN Message Object 32 Data Register High
#define CAN_MODATAH32          (*((uword volatile *) 0xF0005414))

// CAN Message Object 33 Data Register High
#define CAN_MODATAH33          (*((uword volatile *) 0xF0005434))

// CAN Message Object 34 Data Register High
#define CAN_MODATAH34          (*((uword volatile *) 0xF0005454))

// CAN Message Object 35 Data Register High
#define CAN_MODATAH35          (*((uword volatile *) 0xF0005474))

// CAN Message Object 36 Data Register High
#define CAN_MODATAH36          (*((uword volatile *) 0xF0005494))

// CAN Message Object 37 Data Register High
#define CAN_MODATAH37          (*((uword volatile *) 0xF00054B4))

// CAN Message Object 38 Data Register High
#define CAN_MODATAH38          (*((uword volatile *) 0xF00054D4))

// CAN Message Object 39 Data Register High
#define CAN_MODATAH39          (*((uword volatile *) 0xF00054F4))

// CAN Message Object 4 Data Register High
#define CAN_MODATAH4           (*((uword volatile *) 0xF0005094))

// CAN Message Object 40 Data Register High
#define CAN_MODATAH40          (*((uword volatile *) 0xF0005514))

// CAN Message Object 41 Data Register High
#define CAN_MODATAH41          (*((uword volatile *) 0xF0005534))

// CAN Message Object 42 Data Register High
#define CAN_MODATAH42          (*((uword volatile *) 0xF0005554))

// CAN Message Object 43 Data Register High
#define CAN_MODATAH43          (*((uword volatile *) 0xF0005574))

// CAN Message Object 44 Data Register High
#define CAN_MODATAH44          (*((uword volatile *) 0xF0005594))

// CAN Message Object 45 Data Register High
#define CAN_MODATAH45          (*((uword volatile *) 0xF00055B4))

// CAN Message Object 46 Data Register High
#define CAN_MODATAH46          (*((uword volatile *) 0xF00055D4))

// CAN Message Object 47 Data Register High
#define CAN_MODATAH47          (*((uword volatile *) 0xF00055F4))

// CAN Message Object 48 Data Register High
#define CAN_MODATAH48          (*((uword volatile *) 0xF0005614))

// CAN Message Object 49 Data Register High
#define CAN_MODATAH49          (*((uword volatile *) 0xF0005634))

// CAN Message Object 5 Data Register High
#define CAN_MODATAH5           (*((uword volatile *) 0xF00050B4))

// CAN Message Object 50 Data Register High
#define CAN_MODATAH50          (*((uword volatile *) 0xF0005654))

// CAN Message Object 51 Data Register High
#define CAN_MODATAH51          (*((uword volatile *) 0xF0005674))

// CAN Message Object 52 Data Register High
#define CAN_MODATAH52          (*((uword volatile *) 0xF0005694))

// CAN Message Object 53 Data Register High
#define CAN_MODATAH53          (*((uword volatile *) 0xF00056B4))

// CAN Message Object 54 Data Register High
#define CAN_MODATAH54          (*((uword volatile *) 0xF00056D4))

// CAN Message Object 55 Data Register High
#define CAN_MODATAH55          (*((uword volatile *) 0xF00056F4))

// CAN Message Object 56 Data Register High
#define CAN_MODATAH56          (*((uword volatile *) 0xF0005714))

// CAN Message Object 57 Data Register High
#define CAN_MODATAH57          (*((uword volatile *) 0xF0005734))

// CAN Message Object 58 Data Register High
#define CAN_MODATAH58          (*((uword volatile *) 0xF0005754))

// CAN Message Object 59 Data Register High
#define CAN_MODATAH59          (*((uword volatile *) 0xF0005774))

// CAN Message Object 6 Data Register High
#define CAN_MODATAH6           (*((uword volatile *) 0xF00050D4))

// CAN Message Object 60 Data Register High
#define CAN_MODATAH60          (*((uword volatile *) 0xF0005794))

// CAN Message Object 61 Data Register High
#define CAN_MODATAH61          (*((uword volatile *) 0xF00057B4))

// CAN Message Object 62 Data Register High
#define CAN_MODATAH62          (*((uword volatile *) 0xF00057D4))

// CAN Message Object 63 Data Register High
#define CAN_MODATAH63          (*((uword volatile *) 0xF00057F4))

// CAN Message Object 7 Data Register High
#define CAN_MODATAH7           (*((uword volatile *) 0xF00050F4))

// CAN Message Object 8 Data Register High
#define CAN_MODATAH8           (*((uword volatile *) 0xF0005114))

// CAN Message Object 9 Data Register High
#define CAN_MODATAH9           (*((uword volatile *) 0xF0005134))

// CAN Message Object 0 Data Register Low
#define CAN_MODATAL0           (*((uword volatile *) 0xF0005010))

// CAN Message Object 1 Data Register Low
#define CAN_MODATAL1           (*((uword volatile *) 0xF0005030))

// CAN Message Object 10 Data Register Low
#define CAN_MODATAL10          (*((uword volatile *) 0xF0005150))

// CAN Message Object 11 Data Register Low
#define CAN_MODATAL11          (*((uword volatile *) 0xF0005170))

// CAN Message Object 12 Data Register Low
#define CAN_MODATAL12          (*((uword volatile *) 0xF0005190))

// CAN Message Object 13 Data Register Low
#define CAN_MODATAL13          (*((uword volatile *) 0xF00051B0))

// CAN Message Object 14 Data Register Low
#define CAN_MODATAL14          (*((uword volatile *) 0xF00051D0))

// CAN Message Object 15 Data Register Low
#define CAN_MODATAL15          (*((uword volatile *) 0xF00051F0))

// CAN Message Object 16 Data Register Low
#define CAN_MODATAL16          (*((uword volatile *) 0xF0005210))

// CAN Message Object 17 Data Register Low
#define CAN_MODATAL17          (*((uword volatile *) 0xF0005230))

// CAN Message Object 18 Data Register Low
#define CAN_MODATAL18          (*((uword volatile *) 0xF0005250))

// CAN Message Object 19 Data Register Low
#define CAN_MODATAL19          (*((uword volatile *) 0xF0005270))

// CAN Message Object 2 Data Register Low
#define CAN_MODATAL2           (*((uword volatile *) 0xF0005050))

// CAN Message Object 20 Data Register Low
#define CAN_MODATAL20          (*((uword volatile *) 0xF0005290))

// CAN Message Object 21 Data Register Low
#define CAN_MODATAL21          (*((uword volatile *) 0xF00052B0))

// CAN Message Object 22 Data Register Low
#define CAN_MODATAL22          (*((uword volatile *) 0xF00052D0))

// CAN Message Object 23 Data Register Low
#define CAN_MODATAL23          (*((uword volatile *) 0xF00052F0))

// CAN Message Object 24 Data Register Low
#define CAN_MODATAL24          (*((uword volatile *) 0xF0005310))

// CAN Message Object 25 Data Register Low
#define CAN_MODATAL25          (*((uword volatile *) 0xF0005330))

// CAN Message Object 26 Data Register Low
#define CAN_MODATAL26          (*((uword volatile *) 0xF0005350))

// CAN Message Object 27 Data Register Low
#define CAN_MODATAL27          (*((uword volatile *) 0xF0005370))

// CAN Message Object 28 Data Register Low
#define CAN_MODATAL28          (*((uword volatile *) 0xF0005390))

// CAN Message Object 29 Data Register Low
#define CAN_MODATAL29          (*((uword volatile *) 0xF00053B0))

// CAN Message Object 3 Data Register Low
#define CAN_MODATAL3           (*((uword volatile *) 0xF0005070))

// CAN Message Object 30 Data Register Low
#define CAN_MODATAL30          (*((uword volatile *) 0xF00053D0))

// CAN Message Object 31 Data Register Low
#define CAN_MODATAL31          (*((uword volatile *) 0xF00053F0))

// CAN Message Object 32 Data Register Low
#define CAN_MODATAL32          (*((uword volatile *) 0xF0005410))

// CAN Message Object 33 Data Register Low
#define CAN_MODATAL33          (*((uword volatile *) 0xF0005430))

// CAN Message Object 34 Data Register Low
#define CAN_MODATAL34          (*((uword volatile *) 0xF0005450))

// CAN Message Object 35 Data Register Low
#define CAN_MODATAL35          (*((uword volatile *) 0xF0005470))

// CAN Message Object 36 Data Register Low
#define CAN_MODATAL36          (*((uword volatile *) 0xF0005490))

// CAN Message Object 37 Data Register Low
#define CAN_MODATAL37          (*((uword volatile *) 0xF00054B0))

// CAN Message Object 38 Data Register Low
#define CAN_MODATAL38          (*((uword volatile *) 0xF00054D0))

// CAN Message Object 39 Data Register Low
#define CAN_MODATAL39          (*((uword volatile *) 0xF00054F0))

// CAN Message Object 4 Data Register Low
#define CAN_MODATAL4           (*((uword volatile *) 0xF0005090))

// CAN Message Object 40 Data Register Low
#define CAN_MODATAL40          (*((uword volatile *) 0xF0005510))

// CAN Message Object 41 Data Register Low
#define CAN_MODATAL41          (*((uword volatile *) 0xF0005530))

// CAN Message Object 42 Data Register Low
#define CAN_MODATAL42          (*((uword volatile *) 0xF0005550))

// CAN Message Object 43 Data Register Low
#define CAN_MODATAL43          (*((uword volatile *) 0xF0005570))

// CAN Message Object 44 Data Register Low
#define CAN_MODATAL44          (*((uword volatile *) 0xF0005590))

// CAN Message Object 45 Data Register Low
#define CAN_MODATAL45          (*((uword volatile *) 0xF00055B0))

// CAN Message Object 46 Data Register Low
#define CAN_MODATAL46          (*((uword volatile *) 0xF00055D0))

// CAN Message Object 47 Data Register Low
#define CAN_MODATAL47          (*((uword volatile *) 0xF00055F0))

// CAN Message Object 48 Data Register Low
#define CAN_MODATAL48          (*((uword volatile *) 0xF0005610))

// CAN Message Object 49 Data Register Low
#define CAN_MODATAL49          (*((uword volatile *) 0xF0005630))

// CAN Message Object 5 Data Register Low
#define CAN_MODATAL5           (*((uword volatile *) 0xF00050B0))

// CAN Message Object 50 Data Register Low
#define CAN_MODATAL50          (*((uword volatile *) 0xF0005650))

// CAN Message Object 51 Data Register Low
#define CAN_MODATAL51          (*((uword volatile *) 0xF0005670))

// CAN Message Object 52 Data Register Low
#define CAN_MODATAL52          (*((uword volatile *) 0xF0005690))

// CAN Message Object 53 Data Register Low
#define CAN_MODATAL53          (*((uword volatile *) 0xF00056B0))

// CAN Message Object 54 Data Register Low
#define CAN_MODATAL54          (*((uword volatile *) 0xF00056D0))

// CAN Message Object 55 Data Register Low
#define CAN_MODATAL55          (*((uword volatile *) 0xF00056F0))

// CAN Message Object 56 Data Register Low
#define CAN_MODATAL56          (*((uword volatile *) 0xF0005710))

// CAN Message Object 57 Data Register Low
#define CAN_MODATAL57          (*((uword volatile *) 0xF0005730))

// CAN Message Object 58 Data Register Low
#define CAN_MODATAL58          (*((uword volatile *) 0xF0005750))

// CAN Message Object 59 Data Register Low
#define CAN_MODATAL59          (*((uword volatile *) 0xF0005770))

// CAN Message Object 6 Data Register Low
#define CAN_MODATAL6           (*((uword volatile *) 0xF00050D0))

// CAN Message Object 60 Data Register Low
#define CAN_MODATAL60          (*((uword volatile *) 0xF0005790))

// CAN Message Object 61 Data Register Low
#define CAN_MODATAL61          (*((uword volatile *) 0xF00057B0))

// CAN Message Object 62 Data Register Low
#define CAN_MODATAL62          (*((uword volatile *) 0xF00057D0))

// CAN Message Object 63 Data Register Low
#define CAN_MODATAL63          (*((uword volatile *) 0xF00057F0))

// CAN Message Object 7 Data Register Low
#define CAN_MODATAL7           (*((uword volatile *) 0xF00050F0))

// CAN Message Object 8 Data Register Low
#define CAN_MODATAL8           (*((uword volatile *) 0xF0005110))

// CAN Message Object 9 Data Register Low
#define CAN_MODATAL9           (*((uword volatile *) 0xF0005130))

// CAN Message Object 0 Function Control Register
#define CAN_MOFCR0             (*((uword volatile *) 0xF0005000))
#define CAN_MOFCR0_DATC          0x00000800
#define CAN_MOFCR0_DLCC          0x00000400
#define CAN_MOFCR0_FRREN         0x00100000
#define CAN_MOFCR0_GDFS          0x00000100
#define CAN_MOFCR0_IDC           0x00000200
#define CAN_MOFCR0_OVIE          0x00040000
#define CAN_MOFCR0_RMM           0x00200000
#define CAN_MOFCR0_RXIE          0x00010000
#define CAN_MOFCR0_SDT           0x00400000
#define CAN_MOFCR0_STT           0x00800000
#define CAN_MOFCR0_TXIE          0x00020000

// CAN Message Object 1 Function Control Register
#define CAN_MOFCR1             (*((uword volatile *) 0xF0005020))
#define CAN_MOFCR1_DATC          0x00000800
#define CAN_MOFCR1_DLCC          0x00000400
#define CAN_MOFCR1_FRREN         0x00100000
#define CAN_MOFCR1_GDFS          0x00000100
#define CAN_MOFCR1_IDC           0x00000200
#define CAN_MOFCR1_OVIE          0x00040000
#define CAN_MOFCR1_RMM           0x00200000
#define CAN_MOFCR1_RXIE          0x00010000
#define CAN_MOFCR1_SDT           0x00400000
#define CAN_MOFCR1_STT           0x00800000
#define CAN_MOFCR1_TXIE          0x00020000

// CAN Message Object 10 Function Control Register
#define CAN_MOFCR10            (*((uword volatile *) 0xF0005140))
#define CAN_MOFCR10_DATC         0x00000800
#define CAN_MOFCR10_DLCC         0x00000400
#define CAN_MOFCR10_FRREN        0x00100000
#define CAN_MOFCR10_GDFS         0x00000100
#define CAN_MOFCR10_IDC          0x00000200
#define CAN_MOFCR10_OVIE         0x00040000
#define CAN_MOFCR10_RMM          0x00200000
#define CAN_MOFCR10_RXIE         0x00010000
#define CAN_MOFCR10_SDT          0x00400000
#define CAN_MOFCR10_STT          0x00800000
#define CAN_MOFCR10_TXIE         0x00020000

// CAN Message Object 11 Function Control Register
#define CAN_MOFCR11            (*((uword volatile *) 0xF0005160))
#define CAN_MOFCR11_DATC         0x00000800
#define CAN_MOFCR11_DLCC         0x00000400
#define CAN_MOFCR11_FRREN        0x00100000
#define CAN_MOFCR11_GDFS         0x00000100
#define CAN_MOFCR11_IDC          0x00000200
#define CAN_MOFCR11_OVIE         0x00040000
#define CAN_MOFCR11_RMM          0x00200000
#define CAN_MOFCR11_RXIE         0x00010000
#define CAN_MOFCR11_SDT          0x00400000
#define CAN_MOFCR11_STT          0x00800000
#define CAN_MOFCR11_TXIE         0x00020000

// CAN Message Object 12 Function Control Register
#define CAN_MOFCR12            (*((uword volatile *) 0xF0005180))
#define CAN_MOFCR12_DATC         0x00000800
#define CAN_MOFCR12_DLCC         0x00000400
#define CAN_MOFCR12_FRREN        0x00100000
#define CAN_MOFCR12_GDFS         0x00000100
#define CAN_MOFCR12_IDC          0x00000200
#define CAN_MOFCR12_OVIE         0x00040000
#define CAN_MOFCR12_RMM          0x00200000
#define CAN_MOFCR12_RXIE         0x00010000
#define CAN_MOFCR12_SDT          0x00400000
#define CAN_MOFCR12_STT          0x00800000
#define CAN_MOFCR12_TXIE         0x00020000

// CAN Message Object 13 Function Control Register
#define CAN_MOFCR13            (*((uword volatile *) 0xF00051A0))
#define CAN_MOFCR13_DATC         0x00000800
#define CAN_MOFCR13_DLCC         0x00000400
#define CAN_MOFCR13_FRREN        0x00100000
#define CAN_MOFCR13_GDFS         0x00000100
#define CAN_MOFCR13_IDC          0x00000200
#define CAN_MOFCR13_OVIE         0x00040000
#define CAN_MOFCR13_RMM          0x00200000
#define CAN_MOFCR13_RXIE         0x00010000
#define CAN_MOFCR13_SDT          0x00400000
#define CAN_MOFCR13_STT          0x00800000
#define CAN_MOFCR13_TXIE         0x00020000

// CAN Message Object 14 Function Control Register
#define CAN_MOFCR14            (*((uword volatile *) 0xF00051C0))
#define CAN_MOFCR14_DATC         0x00000800
#define CAN_MOFCR14_DLCC         0x00000400
#define CAN_MOFCR14_FRREN        0x00100000
#define CAN_MOFCR14_GDFS         0x00000100
#define CAN_MOFCR14_IDC          0x00000200
#define CAN_MOFCR14_OVIE         0x00040000
#define CAN_MOFCR14_RMM          0x00200000
#define CAN_MOFCR14_RXIE         0x00010000
#define CAN_MOFCR14_SDT          0x00400000
#define CAN_MOFCR14_STT          0x00800000
#define CAN_MOFCR14_TXIE         0x00020000

// CAN Message Object 15 Function Control Register
#define CAN_MOFCR15            (*((uword volatile *) 0xF00051E0))
#define CAN_MOFCR15_DATC         0x00000800
#define CAN_MOFCR15_DLCC         0x00000400
#define CAN_MOFCR15_FRREN        0x00100000
#define CAN_MOFCR15_GDFS         0x00000100
#define CAN_MOFCR15_IDC          0x00000200
#define CAN_MOFCR15_OVIE         0x00040000
#define CAN_MOFCR15_RMM          0x00200000
#define CAN_MOFCR15_RXIE         0x00010000
#define CAN_MOFCR15_SDT          0x00400000
#define CAN_MOFCR15_STT          0x00800000
#define CAN_MOFCR15_TXIE         0x00020000

// CAN Message Object 16 Function Control Register
#define CAN_MOFCR16            (*((uword volatile *) 0xF0005200))
#define CAN_MOFCR16_DATC         0x00000800
#define CAN_MOFCR16_DLCC         0x00000400
#define CAN_MOFCR16_FRREN        0x00100000
#define CAN_MOFCR16_GDFS         0x00000100
#define CAN_MOFCR16_IDC          0x00000200
#define CAN_MOFCR16_OVIE         0x00040000
#define CAN_MOFCR16_RMM          0x00200000
#define CAN_MOFCR16_RXIE         0x00010000
#define CAN_MOFCR16_SDT          0x00400000
#define CAN_MOFCR16_STT          0x00800000
#define CAN_MOFCR16_TXIE         0x00020000

// CAN Message Object 17 Function Control Register
#define CAN_MOFCR17            (*((uword volatile *) 0xF0005220))
#define CAN_MOFCR17_DATC         0x00000800
#define CAN_MOFCR17_DLCC         0x00000400
#define CAN_MOFCR17_FRREN        0x00100000
#define CAN_MOFCR17_GDFS         0x00000100
#define CAN_MOFCR17_IDC          0x00000200
#define CAN_MOFCR17_OVIE         0x00040000
#define CAN_MOFCR17_RMM          0x00200000
#define CAN_MOFCR17_RXIE         0x00010000
#define CAN_MOFCR17_SDT          0x00400000
#define CAN_MOFCR17_STT          0x00800000
#define CAN_MOFCR17_TXIE         0x00020000

// CAN Message Object 18 Function Control Register
#define CAN_MOFCR18            (*((uword volatile *) 0xF0005240))
#define CAN_MOFCR18_DATC         0x00000800
#define CAN_MOFCR18_DLCC         0x00000400
#define CAN_MOFCR18_FRREN        0x00100000
#define CAN_MOFCR18_GDFS         0x00000100
#define CAN_MOFCR18_IDC          0x00000200
#define CAN_MOFCR18_OVIE         0x00040000
#define CAN_MOFCR18_RMM          0x00200000
#define CAN_MOFCR18_RXIE         0x00010000
#define CAN_MOFCR18_SDT          0x00400000
#define CAN_MOFCR18_STT          0x00800000
#define CAN_MOFCR18_TXIE         0x00020000

// CAN Message Object 19 Function Control Register
#define CAN_MOFCR19            (*((uword volatile *) 0xF0005260))
#define CAN_MOFCR19_DATC         0x00000800
#define CAN_MOFCR19_DLCC         0x00000400
#define CAN_MOFCR19_FRREN        0x00100000
#define CAN_MOFCR19_GDFS         0x00000100
#define CAN_MOFCR19_IDC          0x00000200
#define CAN_MOFCR19_OVIE         0x00040000
#define CAN_MOFCR19_RMM          0x00200000
#define CAN_MOFCR19_RXIE         0x00010000
#define CAN_MOFCR19_SDT          0x00400000
#define CAN_MOFCR19_STT          0x00800000
#define CAN_MOFCR19_TXIE         0x00020000

// CAN Message Object 2 Function Control Register
#define CAN_MOFCR2             (*((uword volatile *) 0xF0005040))
#define CAN_MOFCR2_DATC          0x00000800
#define CAN_MOFCR2_DLCC          0x00000400
#define CAN_MOFCR2_FRREN         0x00100000
#define CAN_MOFCR2_GDFS          0x00000100
#define CAN_MOFCR2_IDC           0x00000200
#define CAN_MOFCR2_OVIE          0x00040000
#define CAN_MOFCR2_RMM           0x00200000
#define CAN_MOFCR2_RXIE          0x00010000
#define CAN_MOFCR2_SDT           0x00400000
#define CAN_MOFCR2_STT           0x00800000
#define CAN_MOFCR2_TXIE          0x00020000

// CAN Message Object 20 Function Control Register
#define CAN_MOFCR20            (*((uword volatile *) 0xF0005280))
#define CAN_MOFCR20_DATC         0x00000800
#define CAN_MOFCR20_DLCC         0x00000400
#define CAN_MOFCR20_FRREN        0x00100000
#define CAN_MOFCR20_GDFS         0x00000100
#define CAN_MOFCR20_IDC          0x00000200
#define CAN_MOFCR20_OVIE         0x00040000
#define CAN_MOFCR20_RMM          0x00200000
#define CAN_MOFCR20_RXIE         0x00010000
#define CAN_MOFCR20_SDT          0x00400000
#define CAN_MOFCR20_STT          0x00800000
#define CAN_MOFCR20_TXIE         0x00020000

// CAN Message Object 21 Function Control Register
#define CAN_MOFCR21            (*((uword volatile *) 0xF00052A0))
#define CAN_MOFCR21_DATC         0x00000800
#define CAN_MOFCR21_DLCC         0x00000400
#define CAN_MOFCR21_FRREN        0x00100000
#define CAN_MOFCR21_GDFS         0x00000100
#define CAN_MOFCR21_IDC          0x00000200
#define CAN_MOFCR21_OVIE         0x00040000
#define CAN_MOFCR21_RMM          0x00200000
#define CAN_MOFCR21_RXIE         0x00010000
#define CAN_MOFCR21_SDT          0x00400000
#define CAN_MOFCR21_STT          0x00800000
#define CAN_MOFCR21_TXIE         0x00020000

// CAN Message Object 22 Function Control Register
#define CAN_MOFCR22            (*((uword volatile *) 0xF00052C0))
#define CAN_MOFCR22_DATC         0x00000800
#define CAN_MOFCR22_DLCC         0x00000400
#define CAN_MOFCR22_FRREN        0x00100000
#define CAN_MOFCR22_GDFS         0x00000100
#define CAN_MOFCR22_IDC          0x00000200
#define CAN_MOFCR22_OVIE         0x00040000
#define CAN_MOFCR22_RMM          0x00200000
#define CAN_MOFCR22_RXIE         0x00010000
#define CAN_MOFCR22_SDT          0x00400000
#define CAN_MOFCR22_STT          0x00800000
#define CAN_MOFCR22_TXIE         0x00020000

// CAN Message Object 23 Function Control Register
#define CAN_MOFCR23            (*((uword volatile *) 0xF00052E0))
#define CAN_MOFCR23_DATC         0x00000800
#define CAN_MOFCR23_DLCC         0x00000400
#define CAN_MOFCR23_FRREN        0x00100000
#define CAN_MOFCR23_GDFS         0x00000100
#define CAN_MOFCR23_IDC          0x00000200
#define CAN_MOFCR23_OVIE         0x00040000
#define CAN_MOFCR23_RMM          0x00200000
#define CAN_MOFCR23_RXIE         0x00010000
#define CAN_MOFCR23_SDT          0x00400000
#define CAN_MOFCR23_STT          0x00800000
#define CAN_MOFCR23_TXIE         0x00020000

// CAN Message Object 24 Function Control Register
#define CAN_MOFCR24            (*((uword volatile *) 0xF0005300))
#define CAN_MOFCR24_DATC         0x00000800
#define CAN_MOFCR24_DLCC         0x00000400
#define CAN_MOFCR24_FRREN        0x00100000
#define CAN_MOFCR24_GDFS         0x00000100
#define CAN_MOFCR24_IDC          0x00000200
#define CAN_MOFCR24_OVIE         0x00040000
#define CAN_MOFCR24_RMM          0x00200000
#define CAN_MOFCR24_RXIE         0x00010000
#define CAN_MOFCR24_SDT          0x00400000
#define CAN_MOFCR24_STT          0x00800000
#define CAN_MOFCR24_TXIE         0x00020000

// CAN Message Object 25 Function Control Register
#define CAN_MOFCR25            (*((uword volatile *) 0xF0005320))
#define CAN_MOFCR25_DATC         0x00000800
#define CAN_MOFCR25_DLCC         0x00000400
#define CAN_MOFCR25_FRREN        0x00100000
#define CAN_MOFCR25_GDFS         0x00000100
#define CAN_MOFCR25_IDC          0x00000200
#define CAN_MOFCR25_OVIE         0x00040000
#define CAN_MOFCR25_RMM          0x00200000
#define CAN_MOFCR25_RXIE         0x00010000
#define CAN_MOFCR25_SDT          0x00400000
#define CAN_MOFCR25_STT          0x00800000
#define CAN_MOFCR25_TXIE         0x00020000

// CAN Message Object 26 Function Control Register
#define CAN_MOFCR26            (*((uword volatile *) 0xF0005340))
#define CAN_MOFCR26_DATC         0x00000800
#define CAN_MOFCR26_DLCC         0x00000400
#define CAN_MOFCR26_FRREN        0x00100000
#define CAN_MOFCR26_GDFS         0x00000100
#define CAN_MOFCR26_IDC          0x00000200
#define CAN_MOFCR26_OVIE         0x00040000
#define CAN_MOFCR26_RMM          0x00200000
#define CAN_MOFCR26_RXIE         0x00010000
#define CAN_MOFCR26_SDT          0x00400000
#define CAN_MOFCR26_STT          0x00800000
#define CAN_MOFCR26_TXIE         0x00020000

// CAN Message Object 27 Function Control Register
#define CAN_MOFCR27            (*((uword volatile *) 0xF0005360))
#define CAN_MOFCR27_DATC         0x00000800
#define CAN_MOFCR27_DLCC         0x00000400
#define CAN_MOFCR27_FRREN        0x00100000
#define CAN_MOFCR27_GDFS         0x00000100
#define CAN_MOFCR27_IDC          0x00000200
#define CAN_MOFCR27_OVIE         0x00040000
#define CAN_MOFCR27_RMM          0x00200000
#define CAN_MOFCR27_RXIE         0x00010000
#define CAN_MOFCR27_SDT          0x00400000
#define CAN_MOFCR27_STT          0x00800000
#define CAN_MOFCR27_TXIE         0x00020000

// CAN Message Object 28 Function Control Register
#define CAN_MOFCR28            (*((uword volatile *) 0xF0005380))
#define CAN_MOFCR28_DATC         0x00000800
#define CAN_MOFCR28_DLCC         0x00000400
#define CAN_MOFCR28_FRREN        0x00100000
#define CAN_MOFCR28_GDFS         0x00000100
#define CAN_MOFCR28_IDC          0x00000200
#define CAN_MOFCR28_OVIE         0x00040000
#define CAN_MOFCR28_RMM          0x00200000
#define CAN_MOFCR28_RXIE         0x00010000
#define CAN_MOFCR28_SDT          0x00400000
#define CAN_MOFCR28_STT          0x00800000
#define CAN_MOFCR28_TXIE         0x00020000

// CAN Message Object 29 Function Control Register
#define CAN_MOFCR29            (*((uword volatile *) 0xF00053A0))
#define CAN_MOFCR29_DATC         0x00000800
#define CAN_MOFCR29_DLCC         0x00000400
#define CAN_MOFCR29_FRREN        0x00100000
#define CAN_MOFCR29_GDFS         0x00000100
#define CAN_MOFCR29_IDC          0x00000200
#define CAN_MOFCR29_OVIE         0x00040000
#define CAN_MOFCR29_RMM          0x00200000
#define CAN_MOFCR29_RXIE         0x00010000
#define CAN_MOFCR29_SDT          0x00400000
#define CAN_MOFCR29_STT          0x00800000
#define CAN_MOFCR29_TXIE         0x00020000

// CAN Message Object 3 Function Control Register
#define CAN_MOFCR3             (*((uword volatile *) 0xF0005060))
#define CAN_MOFCR3_DATC          0x00000800
#define CAN_MOFCR3_DLCC          0x00000400
#define CAN_MOFCR3_FRREN         0x00100000
#define CAN_MOFCR3_GDFS          0x00000100
#define CAN_MOFCR3_IDC           0x00000200
#define CAN_MOFCR3_OVIE          0x00040000
#define CAN_MOFCR3_RMM           0x00200000
#define CAN_MOFCR3_RXIE          0x00010000
#define CAN_MOFCR3_SDT           0x00400000
#define CAN_MOFCR3_STT           0x00800000
#define CAN_MOFCR3_TXIE          0x00020000

// CAN Message Object 30 Function Control Register
#define CAN_MOFCR30            (*((uword volatile *) 0xF00053C0))
#define CAN_MOFCR30_DATC         0x00000800
#define CAN_MOFCR30_DLCC         0x00000400
#define CAN_MOFCR30_FRREN        0x00100000
#define CAN_MOFCR30_GDFS         0x00000100
#define CAN_MOFCR30_IDC          0x00000200
#define CAN_MOFCR30_OVIE         0x00040000
#define CAN_MOFCR30_RMM          0x00200000
#define CAN_MOFCR30_RXIE         0x00010000
#define CAN_MOFCR30_SDT          0x00400000
#define CAN_MOFCR30_STT          0x00800000
#define CAN_MOFCR30_TXIE         0x00020000

// CAN Message Object 31 Function Control Register
#define CAN_MOFCR31            (*((uword volatile *) 0xF00053E0))
#define CAN_MOFCR31_DATC         0x00000800
#define CAN_MOFCR31_DLCC         0x00000400
#define CAN_MOFCR31_FRREN        0x00100000
#define CAN_MOFCR31_GDFS         0x00000100
#define CAN_MOFCR31_IDC          0x00000200
#define CAN_MOFCR31_OVIE         0x00040000
#define CAN_MOFCR31_RMM          0x00200000
#define CAN_MOFCR31_RXIE         0x00010000
#define CAN_MOFCR31_SDT          0x00400000
#define CAN_MOFCR31_STT          0x00800000
#define CAN_MOFCR31_TXIE         0x00020000

// CAN Message Object 32 Function Control Register
#define CAN_MOFCR32            (*((uword volatile *) 0xF0005400))
#define CAN_MOFCR32_DATC         0x00000800
#define CAN_MOFCR32_DLCC         0x00000400
#define CAN_MOFCR32_FRREN        0x00100000
#define CAN_MOFCR32_GDFS         0x00000100
#define CAN_MOFCR32_IDC          0x00000200
#define CAN_MOFCR32_OVIE         0x00040000
#define CAN_MOFCR32_RMM          0x00200000
#define CAN_MOFCR32_RXIE         0x00010000
#define CAN_MOFCR32_SDT          0x00400000
#define CAN_MOFCR32_STT          0x00800000
#define CAN_MOFCR32_TXIE         0x00020000

// CAN Message Object 33 Function Control Register
#define CAN_MOFCR33            (*((uword volatile *) 0xF0005420))
#define CAN_MOFCR33_DATC         0x00000800
#define CAN_MOFCR33_DLCC         0x00000400
#define CAN_MOFCR33_FRREN        0x00100000
#define CAN_MOFCR33_GDFS         0x00000100
#define CAN_MOFCR33_IDC          0x00000200
#define CAN_MOFCR33_OVIE         0x00040000
#define CAN_MOFCR33_RMM          0x00200000
#define CAN_MOFCR33_RXIE         0x00010000
#define CAN_MOFCR33_SDT          0x00400000
#define CAN_MOFCR33_STT          0x00800000
#define CAN_MOFCR33_TXIE         0x00020000

// CAN Message Object 34 Function Control Register
#define CAN_MOFCR34            (*((uword volatile *) 0xF0005440))
#define CAN_MOFCR34_DATC         0x00000800
#define CAN_MOFCR34_DLCC         0x00000400
#define CAN_MOFCR34_FRREN        0x00100000
#define CAN_MOFCR34_GDFS         0x00000100
#define CAN_MOFCR34_IDC          0x00000200
#define CAN_MOFCR34_OVIE         0x00040000
#define CAN_MOFCR34_RMM          0x00200000
#define CAN_MOFCR34_RXIE         0x00010000
#define CAN_MOFCR34_SDT          0x00400000
#define CAN_MOFCR34_STT          0x00800000
#define CAN_MOFCR34_TXIE         0x00020000

// CAN Message Object 35 Function Control Register
#define CAN_MOFCR35            (*((uword volatile *) 0xF0005460))
#define CAN_MOFCR35_DATC         0x00000800
#define CAN_MOFCR35_DLCC         0x00000400
#define CAN_MOFCR35_FRREN        0x00100000
#define CAN_MOFCR35_GDFS         0x00000100
#define CAN_MOFCR35_IDC          0x00000200
#define CAN_MOFCR35_OVIE         0x00040000
#define CAN_MOFCR35_RMM          0x00200000
#define CAN_MOFCR35_RXIE         0x00010000
#define CAN_MOFCR35_SDT          0x00400000
#define CAN_MOFCR35_STT          0x00800000
#define CAN_MOFCR35_TXIE         0x00020000

// CAN Message Object 36 Function Control Register
#define CAN_MOFCR36            (*((uword volatile *) 0xF0005480))
#define CAN_MOFCR36_DATC         0x00000800
#define CAN_MOFCR36_DLCC         0x00000400
#define CAN_MOFCR36_FRREN        0x00100000
#define CAN_MOFCR36_GDFS         0x00000100
#define CAN_MOFCR36_IDC          0x00000200
#define CAN_MOFCR36_OVIE         0x00040000
#define CAN_MOFCR36_RMM          0x00200000
#define CAN_MOFCR36_RXIE         0x00010000
#define CAN_MOFCR36_SDT          0x00400000
#define CAN_MOFCR36_STT          0x00800000
#define CAN_MOFCR36_TXIE         0x00020000

// CAN Message Object 37 Function Control Register
#define CAN_MOFCR37            (*((uword volatile *) 0xF00054A0))
#define CAN_MOFCR37_DATC         0x00000800
#define CAN_MOFCR37_DLCC         0x00000400
#define CAN_MOFCR37_FRREN        0x00100000
#define CAN_MOFCR37_GDFS         0x00000100
#define CAN_MOFCR37_IDC          0x00000200
#define CAN_MOFCR37_OVIE         0x00040000
#define CAN_MOFCR37_RMM          0x00200000
#define CAN_MOFCR37_RXIE         0x00010000
#define CAN_MOFCR37_SDT          0x00400000
#define CAN_MOFCR37_STT          0x00800000
#define CAN_MOFCR37_TXIE         0x00020000

// CAN Message Object 38 Function Control Register
#define CAN_MOFCR38            (*((uword volatile *) 0xF00054C0))
#define CAN_MOFCR38_DATC         0x00000800
#define CAN_MOFCR38_DLCC         0x00000400
#define CAN_MOFCR38_FRREN        0x00100000
#define CAN_MOFCR38_GDFS         0x00000100
#define CAN_MOFCR38_IDC          0x00000200
#define CAN_MOFCR38_OVIE         0x00040000
#define CAN_MOFCR38_RMM          0x00200000
#define CAN_MOFCR38_RXIE         0x00010000
#define CAN_MOFCR38_SDT          0x00400000
#define CAN_MOFCR38_STT          0x00800000
#define CAN_MOFCR38_TXIE         0x00020000

// CAN Message Object 39 Function Control Register
#define CAN_MOFCR39            (*((uword volatile *) 0xF00054E0))
#define CAN_MOFCR39_DATC         0x00000800
#define CAN_MOFCR39_DLCC         0x00000400
#define CAN_MOFCR39_FRREN        0x00100000
#define CAN_MOFCR39_GDFS         0x00000100
#define CAN_MOFCR39_IDC          0x00000200
#define CAN_MOFCR39_OVIE         0x00040000
#define CAN_MOFCR39_RMM          0x00200000
#define CAN_MOFCR39_RXIE         0x00010000
#define CAN_MOFCR39_SDT          0x00400000
#define CAN_MOFCR39_STT          0x00800000
#define CAN_MOFCR39_TXIE         0x00020000

// CAN Message Object 4 Function Control Register
#define CAN_MOFCR4             (*((uword volatile *) 0xF0005080))
#define CAN_MOFCR4_DATC          0x00000800
#define CAN_MOFCR4_DLCC          0x00000400
#define CAN_MOFCR4_FRREN         0x00100000
#define CAN_MOFCR4_GDFS          0x00000100
#define CAN_MOFCR4_IDC           0x00000200
#define CAN_MOFCR4_OVIE          0x00040000
#define CAN_MOFCR4_RMM           0x00200000
#define CAN_MOFCR4_RXIE          0x00010000
#define CAN_MOFCR4_SDT           0x00400000
#define CAN_MOFCR4_STT           0x00800000
#define CAN_MOFCR4_TXIE          0x00020000

// CAN Message Object 40 Function Control Register
#define CAN_MOFCR40            (*((uword volatile *) 0xF0005500))
#define CAN_MOFCR40_DATC         0x00000800
#define CAN_MOFCR40_DLCC         0x00000400
#define CAN_MOFCR40_FRREN        0x00100000
#define CAN_MOFCR40_GDFS         0x00000100
#define CAN_MOFCR40_IDC          0x00000200
#define CAN_MOFCR40_OVIE         0x00040000
#define CAN_MOFCR40_RMM          0x00200000
#define CAN_MOFCR40_RXIE         0x00010000
#define CAN_MOFCR40_SDT          0x00400000
#define CAN_MOFCR40_STT          0x00800000
#define CAN_MOFCR40_TXIE         0x00020000

// CAN Message Object 41 Function Control Register
#define CAN_MOFCR41            (*((uword volatile *) 0xF0005520))
#define CAN_MOFCR41_DATC         0x00000800
#define CAN_MOFCR41_DLCC         0x00000400
#define CAN_MOFCR41_FRREN        0x00100000
#define CAN_MOFCR41_GDFS         0x00000100
#define CAN_MOFCR41_IDC          0x00000200
#define CAN_MOFCR41_OVIE         0x00040000
#define CAN_MOFCR41_RMM          0x00200000
#define CAN_MOFCR41_RXIE         0x00010000
#define CAN_MOFCR41_SDT          0x00400000
#define CAN_MOFCR41_STT          0x00800000
#define CAN_MOFCR41_TXIE         0x00020000

// CAN Message Object 42 Function Control Register
#define CAN_MOFCR42            (*((uword volatile *) 0xF0005540))
#define CAN_MOFCR42_DATC         0x00000800
#define CAN_MOFCR42_DLCC         0x00000400
#define CAN_MOFCR42_FRREN        0x00100000
#define CAN_MOFCR42_GDFS         0x00000100
#define CAN_MOFCR42_IDC          0x00000200
#define CAN_MOFCR42_OVIE         0x00040000
#define CAN_MOFCR42_RMM          0x00200000
#define CAN_MOFCR42_RXIE         0x00010000
#define CAN_MOFCR42_SDT          0x00400000
#define CAN_MOFCR42_STT          0x00800000
#define CAN_MOFCR42_TXIE         0x00020000

// CAN Message Object 43 Function Control Register
#define CAN_MOFCR43            (*((uword volatile *) 0xF0005560))
#define CAN_MOFCR43_DATC         0x00000800
#define CAN_MOFCR43_DLCC         0x00000400
#define CAN_MOFCR43_FRREN        0x00100000
#define CAN_MOFCR43_GDFS         0x00000100
#define CAN_MOFCR43_IDC          0x00000200
#define CAN_MOFCR43_OVIE         0x00040000
#define CAN_MOFCR43_RMM          0x00200000
#define CAN_MOFCR43_RXIE         0x00010000
#define CAN_MOFCR43_SDT          0x00400000
#define CAN_MOFCR43_STT          0x00800000
#define CAN_MOFCR43_TXIE         0x00020000

// CAN Message Object 44 Function Control Register
#define CAN_MOFCR44            (*((uword volatile *) 0xF0005580))
#define CAN_MOFCR44_DATC         0x00000800
#define CAN_MOFCR44_DLCC         0x00000400
#define CAN_MOFCR44_FRREN        0x00100000
#define CAN_MOFCR44_GDFS         0x00000100
#define CAN_MOFCR44_IDC          0x00000200
#define CAN_MOFCR44_OVIE         0x00040000
#define CAN_MOFCR44_RMM          0x00200000
#define CAN_MOFCR44_RXIE         0x00010000
#define CAN_MOFCR44_SDT          0x00400000
#define CAN_MOFCR44_STT          0x00800000
#define CAN_MOFCR44_TXIE         0x00020000

// CAN Message Object 45 Function Control Register
#define CAN_MOFCR45            (*((uword volatile *) 0xF00055A0))
#define CAN_MOFCR45_DATC         0x00000800
#define CAN_MOFCR45_DLCC         0x00000400
#define CAN_MOFCR45_FRREN        0x00100000
#define CAN_MOFCR45_GDFS         0x00000100
#define CAN_MOFCR45_IDC          0x00000200
#define CAN_MOFCR45_OVIE         0x00040000
#define CAN_MOFCR45_RMM          0x00200000
#define CAN_MOFCR45_RXIE         0x00010000
#define CAN_MOFCR45_SDT          0x00400000
#define CAN_MOFCR45_STT          0x00800000
#define CAN_MOFCR45_TXIE         0x00020000

// CAN Message Object 46 Function Control Register
#define CAN_MOFCR46            (*((uword volatile *) 0xF00055C0))
#define CAN_MOFCR46_DATC         0x00000800
#define CAN_MOFCR46_DLCC         0x00000400
#define CAN_MOFCR46_FRREN        0x00100000
#define CAN_MOFCR46_GDFS         0x00000100
#define CAN_MOFCR46_IDC          0x00000200
#define CAN_MOFCR46_OVIE         0x00040000
#define CAN_MOFCR46_RMM          0x00200000
#define CAN_MOFCR46_RXIE         0x00010000
#define CAN_MOFCR46_SDT          0x00400000
#define CAN_MOFCR46_STT          0x00800000
#define CAN_MOFCR46_TXIE         0x00020000

// CAN Message Object 47 Function Control Register
#define CAN_MOFCR47            (*((uword volatile *) 0xF00055E0))
#define CAN_MOFCR47_DATC         0x00000800
#define CAN_MOFCR47_DLCC         0x00000400
#define CAN_MOFCR47_FRREN        0x00100000
#define CAN_MOFCR47_GDFS         0x00000100
#define CAN_MOFCR47_IDC          0x00000200
#define CAN_MOFCR47_OVIE         0x00040000
#define CAN_MOFCR47_RMM          0x00200000
#define CAN_MOFCR47_RXIE         0x00010000
#define CAN_MOFCR47_SDT          0x00400000
#define CAN_MOFCR47_STT          0x00800000
#define CAN_MOFCR47_TXIE         0x00020000

// CAN Message Object 48 Function Control Register
#define CAN_MOFCR48            (*((uword volatile *) 0xF0005600))
#define CAN_MOFCR48_DATC         0x00000800
#define CAN_MOFCR48_DLCC         0x00000400
#define CAN_MOFCR48_FRREN        0x00100000
#define CAN_MOFCR48_GDFS         0x00000100
#define CAN_MOFCR48_IDC          0x00000200
#define CAN_MOFCR48_OVIE         0x00040000
#define CAN_MOFCR48_RMM          0x00200000
#define CAN_MOFCR48_RXIE         0x00010000
#define CAN_MOFCR48_SDT          0x00400000
#define CAN_MOFCR48_STT          0x00800000
#define CAN_MOFCR48_TXIE         0x00020000

// CAN Message Object 49 Function Control Register
#define CAN_MOFCR49            (*((uword volatile *) 0xF0005620))
#define CAN_MOFCR49_DATC         0x00000800
#define CAN_MOFCR49_DLCC         0x00000400
#define CAN_MOFCR49_FRREN        0x00100000
#define CAN_MOFCR49_GDFS         0x00000100
#define CAN_MOFCR49_IDC          0x00000200
#define CAN_MOFCR49_OVIE         0x00040000
#define CAN_MOFCR49_RMM          0x00200000
#define CAN_MOFCR49_RXIE         0x00010000
#define CAN_MOFCR49_SDT          0x00400000
#define CAN_MOFCR49_STT          0x00800000
#define CAN_MOFCR49_TXIE         0x00020000

// CAN Message Object 5 Function Control Register
#define CAN_MOFCR5             (*((uword volatile *) 0xF00050A0))
#define CAN_MOFCR5_DATC          0x00000800
#define CAN_MOFCR5_DLCC          0x00000400
#define CAN_MOFCR5_FRREN         0x00100000
#define CAN_MOFCR5_GDFS          0x00000100
#define CAN_MOFCR5_IDC           0x00000200
#define CAN_MOFCR5_OVIE          0x00040000
#define CAN_MOFCR5_RMM           0x00200000
#define CAN_MOFCR5_RXIE          0x00010000
#define CAN_MOFCR5_SDT           0x00400000
#define CAN_MOFCR5_STT           0x00800000
#define CAN_MOFCR5_TXIE          0x00020000

// CAN Message Object 50 Function Control Register
#define CAN_MOFCR50            (*((uword volatile *) 0xF0005640))
#define CAN_MOFCR50_DATC         0x00000800
#define CAN_MOFCR50_DLCC         0x00000400
#define CAN_MOFCR50_FRREN        0x00100000
#define CAN_MOFCR50_GDFS         0x00000100
#define CAN_MOFCR50_IDC          0x00000200
#define CAN_MOFCR50_OVIE         0x00040000
#define CAN_MOFCR50_RMM          0x00200000
#define CAN_MOFCR50_RXIE         0x00010000
#define CAN_MOFCR50_SDT          0x00400000
#define CAN_MOFCR50_STT          0x00800000
#define CAN_MOFCR50_TXIE         0x00020000

// CAN Message Object 51 Function Control Register
#define CAN_MOFCR51            (*((uword volatile *) 0xF0005660))
#define CAN_MOFCR51_DATC         0x00000800
#define CAN_MOFCR51_DLCC         0x00000400
#define CAN_MOFCR51_FRREN        0x00100000
#define CAN_MOFCR51_GDFS         0x00000100
#define CAN_MOFCR51_IDC          0x00000200
#define CAN_MOFCR51_OVIE         0x00040000
#define CAN_MOFCR51_RMM          0x00200000
#define CAN_MOFCR51_RXIE         0x00010000
#define CAN_MOFCR51_SDT          0x00400000
#define CAN_MOFCR51_STT          0x00800000
#define CAN_MOFCR51_TXIE         0x00020000

// CAN Message Object 52 Function Control Register
#define CAN_MOFCR52            (*((uword volatile *) 0xF0005680))
#define CAN_MOFCR52_DATC         0x00000800
#define CAN_MOFCR52_DLCC         0x00000400
#define CAN_MOFCR52_FRREN        0x00100000
#define CAN_MOFCR52_GDFS         0x00000100
#define CAN_MOFCR52_IDC          0x00000200
#define CAN_MOFCR52_OVIE         0x00040000
#define CAN_MOFCR52_RMM          0x00200000
#define CAN_MOFCR52_RXIE         0x00010000
#define CAN_MOFCR52_SDT          0x00400000
#define CAN_MOFCR52_STT          0x00800000
#define CAN_MOFCR52_TXIE         0x00020000

// CAN Message Object 53 Function Control Register
#define CAN_MOFCR53            (*((uword volatile *) 0xF00056A0))
#define CAN_MOFCR53_DATC         0x00000800
#define CAN_MOFCR53_DLCC         0x00000400
#define CAN_MOFCR53_FRREN        0x00100000
#define CAN_MOFCR53_GDFS         0x00000100
#define CAN_MOFCR53_IDC          0x00000200
#define CAN_MOFCR53_OVIE         0x00040000
#define CAN_MOFCR53_RMM          0x00200000
#define CAN_MOFCR53_RXIE         0x00010000
#define CAN_MOFCR53_SDT          0x00400000
#define CAN_MOFCR53_STT          0x00800000
#define CAN_MOFCR53_TXIE         0x00020000

// CAN Message Object 54 Function Control Register
#define CAN_MOFCR54            (*((uword volatile *) 0xF00056C0))
#define CAN_MOFCR54_DATC         0x00000800
#define CAN_MOFCR54_DLCC         0x00000400
#define CAN_MOFCR54_FRREN        0x00100000
#define CAN_MOFCR54_GDFS         0x00000100
#define CAN_MOFCR54_IDC          0x00000200
#define CAN_MOFCR54_OVIE         0x00040000
#define CAN_MOFCR54_RMM          0x00200000
#define CAN_MOFCR54_RXIE         0x00010000
#define CAN_MOFCR54_SDT          0x00400000
#define CAN_MOFCR54_STT          0x00800000
#define CAN_MOFCR54_TXIE         0x00020000

// CAN Message Object 55 Function Control Register
#define CAN_MOFCR55            (*((uword volatile *) 0xF00056E0))
#define CAN_MOFCR55_DATC         0x00000800
#define CAN_MOFCR55_DLCC         0x00000400
#define CAN_MOFCR55_FRREN        0x00100000
#define CAN_MOFCR55_GDFS         0x00000100
#define CAN_MOFCR55_IDC          0x00000200
#define CAN_MOFCR55_OVIE         0x00040000
#define CAN_MOFCR55_RMM          0x00200000
#define CAN_MOFCR55_RXIE         0x00010000
#define CAN_MOFCR55_SDT          0x00400000
#define CAN_MOFCR55_STT          0x00800000
#define CAN_MOFCR55_TXIE         0x00020000

// CAN Message Object 56 Function Control Register
#define CAN_MOFCR56            (*((uword volatile *) 0xF0005700))
#define CAN_MOFCR56_DATC         0x00000800
#define CAN_MOFCR56_DLCC         0x00000400
#define CAN_MOFCR56_FRREN        0x00100000
#define CAN_MOFCR56_GDFS         0x00000100
#define CAN_MOFCR56_IDC          0x00000200
#define CAN_MOFCR56_OVIE         0x00040000
#define CAN_MOFCR56_RMM          0x00200000
#define CAN_MOFCR56_RXIE         0x00010000
#define CAN_MOFCR56_SDT          0x00400000
#define CAN_MOFCR56_STT          0x00800000
#define CAN_MOFCR56_TXIE         0x00020000

// CAN Message Object 57 Function Control Register
#define CAN_MOFCR57            (*((uword volatile *) 0xF0005720))
#define CAN_MOFCR57_DATC         0x00000800
#define CAN_MOFCR57_DLCC         0x00000400
#define CAN_MOFCR57_FRREN        0x00100000
#define CAN_MOFCR57_GDFS         0x00000100
#define CAN_MOFCR57_IDC          0x00000200
#define CAN_MOFCR57_OVIE         0x00040000
#define CAN_MOFCR57_RMM          0x00200000
#define CAN_MOFCR57_RXIE         0x00010000
#define CAN_MOFCR57_SDT          0x00400000
#define CAN_MOFCR57_STT          0x00800000
#define CAN_MOFCR57_TXIE         0x00020000

// CAN Message Object 58 Function Control Register
#define CAN_MOFCR58            (*((uword volatile *) 0xF0005740))
#define CAN_MOFCR58_DATC         0x00000800
#define CAN_MOFCR58_DLCC         0x00000400
#define CAN_MOFCR58_FRREN        0x00100000
#define CAN_MOFCR58_GDFS         0x00000100
#define CAN_MOFCR58_IDC          0x00000200
#define CAN_MOFCR58_OVIE         0x00040000
#define CAN_MOFCR58_RMM          0x00200000
#define CAN_MOFCR58_RXIE         0x00010000
#define CAN_MOFCR58_SDT          0x00400000
#define CAN_MOFCR58_STT          0x00800000
#define CAN_MOFCR58_TXIE         0x00020000

// CAN Message Object 59 Function Control Register
#define CAN_MOFCR59            (*((uword volatile *) 0xF0005760))
#define CAN_MOFCR59_DATC         0x00000800
#define CAN_MOFCR59_DLCC         0x00000400
#define CAN_MOFCR59_FRREN        0x00100000
#define CAN_MOFCR59_GDFS         0x00000100
#define CAN_MOFCR59_IDC          0x00000200
#define CAN_MOFCR59_OVIE         0x00040000
#define CAN_MOFCR59_RMM          0x00200000
#define CAN_MOFCR59_RXIE         0x00010000
#define CAN_MOFCR59_SDT          0x00400000
#define CAN_MOFCR59_STT          0x00800000
#define CAN_MOFCR59_TXIE         0x00020000

// CAN Message Object 6 Function Control Register
#define CAN_MOFCR6             (*((uword volatile *) 0xF00050C0))
#define CAN_MOFCR6_DATC          0x00000800
#define CAN_MOFCR6_DLCC          0x00000400
#define CAN_MOFCR6_FRREN         0x00100000
#define CAN_MOFCR6_GDFS          0x00000100
#define CAN_MOFCR6_IDC           0x00000200
#define CAN_MOFCR6_OVIE          0x00040000
#define CAN_MOFCR6_RMM           0x00200000
#define CAN_MOFCR6_RXIE          0x00010000
#define CAN_MOFCR6_SDT           0x00400000
#define CAN_MOFCR6_STT           0x00800000
#define CAN_MOFCR6_TXIE          0x00020000

// CAN Message Object 60 Function Control Register
#define CAN_MOFCR60            (*((uword volatile *) 0xF0005780))
#define CAN_MOFCR60_DATC         0x00000800
#define CAN_MOFCR60_DLCC         0x00000400
#define CAN_MOFCR60_FRREN        0x00100000
#define CAN_MOFCR60_GDFS         0x00000100
#define CAN_MOFCR60_IDC          0x00000200
#define CAN_MOFCR60_OVIE         0x00040000
#define CAN_MOFCR60_RMM          0x00200000
#define CAN_MOFCR60_RXIE         0x00010000
#define CAN_MOFCR60_SDT          0x00400000
#define CAN_MOFCR60_STT          0x00800000
#define CAN_MOFCR60_TXIE         0x00020000

// CAN Message Object 61 Function Control Register
#define CAN_MOFCR61            (*((uword volatile *) 0xF00057A0))
#define CAN_MOFCR61_DATC         0x00000800
#define CAN_MOFCR61_DLCC         0x00000400
#define CAN_MOFCR61_FRREN        0x00100000
#define CAN_MOFCR61_GDFS         0x00000100
#define CAN_MOFCR61_IDC          0x00000200
#define CAN_MOFCR61_OVIE         0x00040000
#define CAN_MOFCR61_RMM          0x00200000
#define CAN_MOFCR61_RXIE         0x00010000
#define CAN_MOFCR61_SDT          0x00400000
#define CAN_MOFCR61_STT          0x00800000
#define CAN_MOFCR61_TXIE         0x00020000

// CAN Message Object 62 Function Control Register
#define CAN_MOFCR62            (*((uword volatile *) 0xF00057C0))
#define CAN_MOFCR62_DATC         0x00000800
#define CAN_MOFCR62_DLCC         0x00000400
#define CAN_MOFCR62_FRREN        0x00100000
#define CAN_MOFCR62_GDFS         0x00000100
#define CAN_MOFCR62_IDC          0x00000200
#define CAN_MOFCR62_OVIE         0x00040000
#define CAN_MOFCR62_RMM          0x00200000
#define CAN_MOFCR62_RXIE         0x00010000
#define CAN_MOFCR62_SDT          0x00400000
#define CAN_MOFCR62_STT          0x00800000
#define CAN_MOFCR62_TXIE         0x00020000

// CAN Message Object 63 Function Control Register
#define CAN_MOFCR63            (*((uword volatile *) 0xF00057E0))
#define CAN_MOFCR63_DATC         0x00000800
#define CAN_MOFCR63_DLCC         0x00000400
#define CAN_MOFCR63_FRREN        0x00100000
#define CAN_MOFCR63_GDFS         0x00000100
#define CAN_MOFCR63_IDC          0x00000200
#define CAN_MOFCR63_OVIE         0x00040000
#define CAN_MOFCR63_RMM          0x00200000
#define CAN_MOFCR63_RXIE         0x00010000
#define CAN_MOFCR63_SDT          0x00400000
#define CAN_MOFCR63_STT          0x00800000
#define CAN_MOFCR63_TXIE         0x00020000

// CAN Message Object 7 Function Control Register
#define CAN_MOFCR7             (*((uword volatile *) 0xF00050E0))
#define CAN_MOFCR7_DATC          0x00000800
#define CAN_MOFCR7_DLCC          0x00000400
#define CAN_MOFCR7_FRREN         0x00100000
#define CAN_MOFCR7_GDFS          0x00000100
#define CAN_MOFCR7_IDC           0x00000200
#define CAN_MOFCR7_OVIE          0x00040000
#define CAN_MOFCR7_RMM           0x00200000
#define CAN_MOFCR7_RXIE          0x00010000
#define CAN_MOFCR7_SDT           0x00400000
#define CAN_MOFCR7_STT           0x00800000
#define CAN_MOFCR7_TXIE          0x00020000

// CAN Message Object 8 Function Control Register
#define CAN_MOFCR8             (*((uword volatile *) 0xF0005100))
#define CAN_MOFCR8_DATC          0x00000800
#define CAN_MOFCR8_DLCC          0x00000400
#define CAN_MOFCR8_FRREN         0x00100000
#define CAN_MOFCR8_GDFS          0x00000100
#define CAN_MOFCR8_IDC           0x00000200
#define CAN_MOFCR8_OVIE          0x00040000
#define CAN_MOFCR8_RMM           0x00200000
#define CAN_MOFCR8_RXIE          0x00010000
#define CAN_MOFCR8_SDT           0x00400000
#define CAN_MOFCR8_STT           0x00800000
#define CAN_MOFCR8_TXIE          0x00020000

// CAN Message Object 9 Function Control Register
#define CAN_MOFCR9             (*((uword volatile *) 0xF0005120))
#define CAN_MOFCR9_DATC          0x00000800
#define CAN_MOFCR9_DLCC          0x00000400
#define CAN_MOFCR9_FRREN         0x00100000
#define CAN_MOFCR9_GDFS          0x00000100
#define CAN_MOFCR9_IDC           0x00000200
#define CAN_MOFCR9_OVIE          0x00040000
#define CAN_MOFCR9_RMM           0x00200000
#define CAN_MOFCR9_RXIE          0x00010000
#define CAN_MOFCR9_SDT           0x00400000
#define CAN_MOFCR9_STT           0x00800000
#define CAN_MOFCR9_TXIE          0x00020000

// CAN Message Object 0 FIFO/Gateway Pointer Register
#define CAN_MOFGPR0            (*((uword volatile *) 0xF0005004))

// CAN Message Object 1 FIFO/Gateway Pointer Register
#define CAN_MOFGPR1            (*((uword volatile *) 0xF0005024))

// CAN Message Object 10 FIFO/Gateway Pointer Register
#define CAN_MOFGPR10           (*((uword volatile *) 0xF0005144))

// CAN Message Object 11 FIFO/Gateway Pointer Register
#define CAN_MOFGPR11           (*((uword volatile *) 0xF0005164))

// CAN Message Object 12 FIFO/Gateway Pointer Register
#define CAN_MOFGPR12           (*((uword volatile *) 0xF0005184))

// CAN Message Object 13 FIFO/Gateway Pointer Register
#define CAN_MOFGPR13           (*((uword volatile *) 0xF00051A4))

// CAN Message Object 14 FIFO/Gateway Pointer Register
#define CAN_MOFGPR14           (*((uword volatile *) 0xF00051C4))

// CAN Message Object 15 FIFO/Gateway Pointer Register
#define CAN_MOFGPR15           (*((uword volatile *) 0xF00051E4))

// CAN Message Object 16 FIFO/Gateway Pointer Register
#define CAN_MOFGPR16           (*((uword volatile *) 0xF0005204))

// CAN Message Object 17 FIFO/Gateway Pointer Register
#define CAN_MOFGPR17           (*((uword volatile *) 0xF0005224))

// CAN Message Object 18 FIFO/Gateway Pointer Register
#define CAN_MOFGPR18           (*((uword volatile *) 0xF0005244))

// CAN Message Object 19 FIFO/Gateway Pointer Register
#define CAN_MOFGPR19           (*((uword volatile *) 0xF0005264))

// CAN Message Object 2 FIFO/Gateway Pointer Register
#define CAN_MOFGPR2            (*((uword volatile *) 0xF0005044))

// CAN Message Object 20 FIFO/Gateway Pointer Register
#define CAN_MOFGPR20           (*((uword volatile *) 0xF0005284))

// CAN Message Object 21 FIFO/Gateway Pointer Register
#define CAN_MOFGPR21           (*((uword volatile *) 0xF00052A4))

// CAN Message Object 22 FIFO/Gateway Pointer Register
#define CAN_MOFGPR22           (*((uword volatile *) 0xF00052C4))

// CAN Message Object 23 FIFO/Gateway Pointer Register
#define CAN_MOFGPR23           (*((uword volatile *) 0xF00052E4))

// CAN Message Object 24 FIFO/Gateway Pointer Register
#define CAN_MOFGPR24           (*((uword volatile *) 0xF0005304))

// CAN Message Object 25 FIFO/Gateway Pointer Register
#define CAN_MOFGPR25           (*((uword volatile *) 0xF0005324))

// CAN Message Object 26 FIFO/Gateway Pointer Register
#define CAN_MOFGPR26           (*((uword volatile *) 0xF0005344))

// CAN Message Object 27 FIFO/Gateway Pointer Register
#define CAN_MOFGPR27           (*((uword volatile *) 0xF0005364))

// CAN Message Object 28 FIFO/Gateway Pointer Register
#define CAN_MOFGPR28           (*((uword volatile *) 0xF0005384))

// CAN Message Object 29 FIFO/Gateway Pointer Register
#define CAN_MOFGPR29           (*((uword volatile *) 0xF00053A4))

// CAN Message Object 3 FIFO/Gateway Pointer Register
#define CAN_MOFGPR3            (*((uword volatile *) 0xF0005064))

// CAN Message Object 30 FIFO/Gateway Pointer Register
#define CAN_MOFGPR30           (*((uword volatile *) 0xF00053C4))

// CAN Message Object 31 FIFO/Gateway Pointer Register
#define CAN_MOFGPR31           (*((uword volatile *) 0xF00053E4))

// CAN Message Object 32 FIFO/Gateway Pointer Register
#define CAN_MOFGPR32           (*((uword volatile *) 0xF0005404))

// CAN Message Object 33 FIFO/Gateway Pointer Register
#define CAN_MOFGPR33           (*((uword volatile *) 0xF0005424))

// CAN Message Object 34 FIFO/Gateway Pointer Register
#define CAN_MOFGPR34           (*((uword volatile *) 0xF0005444))

// CAN Message Object 35 FIFO/Gateway Pointer Register
#define CAN_MOFGPR35           (*((uword volatile *) 0xF0005464))

// CAN Message Object 36 FIFO/Gateway Pointer Register
#define CAN_MOFGPR36           (*((uword volatile *) 0xF0005484))

// CAN Message Object 37 FIFO/Gateway Pointer Register
#define CAN_MOFGPR37           (*((uword volatile *) 0xF00054A4))

// CAN Message Object 38 FIFO/Gateway Pointer Register
#define CAN_MOFGPR38           (*((uword volatile *) 0xF00054C4))

// CAN Message Object 39 FIFO/Gateway Pointer Register
#define CAN_MOFGPR39           (*((uword volatile *) 0xF00054E4))

// CAN Message Object 4 FIFO/Gateway Pointer Register
#define CAN_MOFGPR4            (*((uword volatile *) 0xF0005084))

// CAN Message Object 40 FIFO/Gateway Pointer Register
#define CAN_MOFGPR40           (*((uword volatile *) 0xF0005504))

// CAN Message Object 41 FIFO/Gateway Pointer Register
#define CAN_MOFGPR41           (*((uword volatile *) 0xF0005524))

// CAN Message Object 42 FIFO/Gateway Pointer Register
#define CAN_MOFGPR42           (*((uword volatile *) 0xF0005544))

// CAN Message Object 43 FIFO/Gateway Pointer Register
#define CAN_MOFGPR43           (*((uword volatile *) 0xF0005564))

// CAN Message Object 44 FIFO/Gateway Pointer Register
#define CAN_MOFGPR44           (*((uword volatile *) 0xF0005584))

// CAN Message Object 45 FIFO/Gateway Pointer Register
#define CAN_MOFGPR45           (*((uword volatile *) 0xF00055A4))

// CAN Message Object 46 FIFO/Gateway Pointer Register
#define CAN_MOFGPR46           (*((uword volatile *) 0xF00055C4))

// CAN Message Object 47 FIFO/Gateway Pointer Register
#define CAN_MOFGPR47           (*((uword volatile *) 0xF00055E4))

// CAN Message Object 48 FIFO/Gateway Pointer Register
#define CAN_MOFGPR48           (*((uword volatile *) 0xF0005604))

// CAN Message Object 49 FIFO/Gateway Pointer Register
#define CAN_MOFGPR49           (*((uword volatile *) 0xF0005624))

// CAN Message Object 5 FIFO/Gateway Pointer Register
#define CAN_MOFGPR5            (*((uword volatile *) 0xF00050A4))

// CAN Message Object 50 FIFO/Gateway Pointer Register
#define CAN_MOFGPR50           (*((uword volatile *) 0xF0005644))

// CAN Message Object 51 FIFO/Gateway Pointer Register
#define CAN_MOFGPR51           (*((uword volatile *) 0xF0005664))

// CAN Message Object 52 FIFO/Gateway Pointer Register
#define CAN_MOFGPR52           (*((uword volatile *) 0xF0005684))

// CAN Message Object 53 FIFO/Gateway Pointer Register
#define CAN_MOFGPR53           (*((uword volatile *) 0xF00056A4))

// CAN Message Object 54 FIFO/Gateway Pointer Register
#define CAN_MOFGPR54           (*((uword volatile *) 0xF00056C4))

// CAN Message Object 55 FIFO/Gateway Pointer Register
#define CAN_MOFGPR55           (*((uword volatile *) 0xF00056E4))

// CAN Message Object 56 FIFO/Gateway Pointer Register
#define CAN_MOFGPR56           (*((uword volatile *) 0xF0005704))

// CAN Message Object 57 FIFO/Gateway Pointer Register
#define CAN_MOFGPR57           (*((uword volatile *) 0xF0005724))

// CAN Message Object 58 FIFO/Gateway Pointer Register
#define CAN_MOFGPR58           (*((uword volatile *) 0xF0005744))

// CAN Message Object 59 FIFO/Gateway Pointer Register
#define CAN_MOFGPR59           (*((uword volatile *) 0xF0005764))

// CAN Message Object 6 FIFO/Gateway Pointer Register
#define CAN_MOFGPR6            (*((uword volatile *) 0xF00050C4))

// CAN Message Object 60 FIFO/Gateway Pointer Register
#define CAN_MOFGPR60           (*((uword volatile *) 0xF0005784))

// CAN Message Object 61 FIFO/Gateway Pointer Register
#define CAN_MOFGPR61           (*((uword volatile *) 0xF00057A4))

// CAN Message Object 62 FIFO/Gateway Pointer Register
#define CAN_MOFGPR62           (*((uword volatile *) 0xF00057C4))

// CAN Message Object 63 FIFO/Gateway Pointer Register
#define CAN_MOFGPR63           (*((uword volatile *) 0xF00057E4))

// CAN Message Object 7 FIFO/Gateway Pointer Register
#define CAN_MOFGPR7            (*((uword volatile *) 0xF00050E4))

// CAN Message Object 8 FIFO/Gateway Pointer Register
#define CAN_MOFGPR8            (*((uword volatile *) 0xF0005104))

// CAN Message Object 9 FIFO/Gateway Pointer Register
#define CAN_MOFGPR9            (*((uword volatile *) 0xF0005124))

// CAN Message Object 0 Interrupt Pointer Register
#define CAN_MOIPR0             (*((uword volatile *) 0xF0005008))

// CAN Message Object 1 Interrupt Pointer Register
#define CAN_MOIPR1             (*((uword volatile *) 0xF0005028))

// CAN Message Object 10 Interrupt Pointer Register
#define CAN_MOIPR10            (*((uword volatile *) 0xF0005148))

// CAN Message Object 11 Interrupt Pointer Register
#define CAN_MOIPR11            (*((uword volatile *) 0xF0005168))

// CAN Message Object 12 Interrupt Pointer Register
#define CAN_MOIPR12            (*((uword volatile *) 0xF0005188))

// CAN Message Object 13 Interrupt Pointer Register
#define CAN_MOIPR13            (*((uword volatile *) 0xF00051A8))

// CAN Message Object 14 Interrupt Pointer Register
#define CAN_MOIPR14            (*((uword volatile *) 0xF00051C8))

// CAN Message Object 15 Interrupt Pointer Register
#define CAN_MOIPR15            (*((uword volatile *) 0xF00051E8))

// CAN Message Object 16 Interrupt Pointer Register
#define CAN_MOIPR16            (*((uword volatile *) 0xF0005208))

// CAN Message Object 17 Interrupt Pointer Register
#define CAN_MOIPR17            (*((uword volatile *) 0xF0005228))

// CAN Message Object 18 Interrupt Pointer Register
#define CAN_MOIPR18            (*((uword volatile *) 0xF0005248))

// CAN Message Object 19 Interrupt Pointer Register
#define CAN_MOIPR19            (*((uword volatile *) 0xF0005268))

// CAN Message Object 2 Interrupt Pointer Register
#define CAN_MOIPR2             (*((uword volatile *) 0xF0005048))

// CAN Message Object 20 Interrupt Pointer Register
#define CAN_MOIPR20            (*((uword volatile *) 0xF0005288))

// CAN Message Object 21 Interrupt Pointer Register
#define CAN_MOIPR21            (*((uword volatile *) 0xF00052A8))

// CAN Message Object 22 Interrupt Pointer Register
#define CAN_MOIPR22            (*((uword volatile *) 0xF00052C8))

// CAN Message Object 23 Interrupt Pointer Register
#define CAN_MOIPR23            (*((uword volatile *) 0xF00052E8))

// CAN Message Object 24 Interrupt Pointer Register
#define CAN_MOIPR24            (*((uword volatile *) 0xF0005308))

// CAN Message Object 25 Interrupt Pointer Register
#define CAN_MOIPR25            (*((uword volatile *) 0xF0005328))

// CAN Message Object 26 Interrupt Pointer Register
#define CAN_MOIPR26            (*((uword volatile *) 0xF0005348))

// CAN Message Object 27 Interrupt Pointer Register
#define CAN_MOIPR27            (*((uword volatile *) 0xF0005368))

// CAN Message Object 28 Interrupt Pointer Register
#define CAN_MOIPR28            (*((uword volatile *) 0xF0005388))

// CAN Message Object 29 Interrupt Pointer Register
#define CAN_MOIPR29            (*((uword volatile *) 0xF00053A8))

// CAN Message Object 3 Interrupt Pointer Register
#define CAN_MOIPR3             (*((uword volatile *) 0xF0005068))

// CAN Message Object 30 Interrupt Pointer Register
#define CAN_MOIPR30            (*((uword volatile *) 0xF00053C8))

// CAN Message Object 31 Interrupt Pointer Register
#define CAN_MOIPR31            (*((uword volatile *) 0xF00053E8))

// CAN Message Object 32 Interrupt Pointer Register
#define CAN_MOIPR32            (*((uword volatile *) 0xF0005408))

// CAN Message Object 33 Interrupt Pointer Register
#define CAN_MOIPR33            (*((uword volatile *) 0xF0005428))

// CAN Message Object 34 Interrupt Pointer Register
#define CAN_MOIPR34            (*((uword volatile *) 0xF0005448))

// CAN Message Object 35 Interrupt Pointer Register
#define CAN_MOIPR35            (*((uword volatile *) 0xF0005468))

// CAN Message Object 36 Interrupt Pointer Register
#define CAN_MOIPR36            (*((uword volatile *) 0xF0005488))

// CAN Message Object 37 Interrupt Pointer Register
#define CAN_MOIPR37            (*((uword volatile *) 0xF00054A8))

// CAN Message Object 38 Interrupt Pointer Register
#define CAN_MOIPR38            (*((uword volatile *) 0xF00054C8))

// CAN Message Object 39 Interrupt Pointer Register
#define CAN_MOIPR39            (*((uword volatile *) 0xF00054E8))

// CAN Message Object 4 Interrupt Pointer Register
#define CAN_MOIPR4             (*((uword volatile *) 0xF0005088))

// CAN Message Object 40 Interrupt Pointer Register
#define CAN_MOIPR40            (*((uword volatile *) 0xF0005508))

// CAN Message Object 41 Interrupt Pointer Register
#define CAN_MOIPR41            (*((uword volatile *) 0xF0005528))

// CAN Message Object 42 Interrupt Pointer Register
#define CAN_MOIPR42            (*((uword volatile *) 0xF0005548))

// CAN Message Object 43 Interrupt Pointer Register
#define CAN_MOIPR43            (*((uword volatile *) 0xF0005568))

// CAN Message Object 44 Interrupt Pointer Register
#define CAN_MOIPR44            (*((uword volatile *) 0xF0005588))

// CAN Message Object 45 Interrupt Pointer Register
#define CAN_MOIPR45            (*((uword volatile *) 0xF00055A8))

// CAN Message Object 46 Interrupt Pointer Register
#define CAN_MOIPR46            (*((uword volatile *) 0xF00055C8))

// CAN Message Object 47 Interrupt Pointer Register
#define CAN_MOIPR47            (*((uword volatile *) 0xF00055E8))

// CAN Message Object 48 Interrupt Pointer Register
#define CAN_MOIPR48            (*((uword volatile *) 0xF0005608))

// CAN Message Object 49 Interrupt Pointer Register
#define CAN_MOIPR49            (*((uword volatile *) 0xF0005628))

// CAN Message Object 5 Interrupt Pointer Register
#define CAN_MOIPR5             (*((uword volatile *) 0xF00050A8))

// CAN Message Object 50 Interrupt Pointer Register
#define CAN_MOIPR50            (*((uword volatile *) 0xF0005648))

// CAN Message Object 51 Interrupt Pointer Register
#define CAN_MOIPR51            (*((uword volatile *) 0xF0005668))

// CAN Message Object 52 Interrupt Pointer Register
#define CAN_MOIPR52            (*((uword volatile *) 0xF0005688))

// CAN Message Object 53 Interrupt Pointer Register
#define CAN_MOIPR53            (*((uword volatile *) 0xF00056A8))

// CAN Message Object 54 Interrupt Pointer Register
#define CAN_MOIPR54            (*((uword volatile *) 0xF00056C8))

// CAN Message Object 55 Interrupt Pointer Register
#define CAN_MOIPR55            (*((uword volatile *) 0xF00056E8))

// CAN Message Object 56 Interrupt Pointer Register
#define CAN_MOIPR56            (*((uword volatile *) 0xF0005708))

// CAN Message Object 57 Interrupt Pointer Register
#define CAN_MOIPR57            (*((uword volatile *) 0xF0005728))

// CAN Message Object 58 Interrupt Pointer Register
#define CAN_MOIPR58            (*((uword volatile *) 0xF0005748))

// CAN Message Object 59 Interrupt Pointer Register
#define CAN_MOIPR59            (*((uword volatile *) 0xF0005768))

// CAN Message Object 6 Interrupt Pointer Register
#define CAN_MOIPR6             (*((uword volatile *) 0xF00050C8))

// CAN Message Object 60 Interrupt Pointer Register
#define CAN_MOIPR60            (*((uword volatile *) 0xF0005788))

// CAN Message Object 61 Interrupt Pointer Register
#define CAN_MOIPR61            (*((uword volatile *) 0xF00057A8))

// CAN Message Object 62 Interrupt Pointer Register
#define CAN_MOIPR62            (*((uword volatile *) 0xF00057C8))

// CAN Message Object 63 Interrupt Pointer Register
#define CAN_MOIPR63            (*((uword volatile *) 0xF00057E8))

// CAN Message Object 7 Interrupt Pointer Register
#define CAN_MOIPR7             (*((uword volatile *) 0xF00050E8))

// CAN Message Object 8 Interrupt Pointer Register
#define CAN_MOIPR8             (*((uword volatile *) 0xF0005108))

// CAN Message Object 9 Interrupt Pointer Register
#define CAN_MOIPR9             (*((uword volatile *) 0xF0005128))

// CAN Message Object 0 Status Register
#define CAN_MOSTAT0            (*((uword volatile *) 0xF000501C))
#define CAN_MOSTAT0_DIR          0x00000800
#define CAN_MOSTAT0_MSGLST       0x00000010
#define CAN_MOSTAT0_MSGVAL       0x00000020
#define CAN_MOSTAT0_NEWDAT       0x00000008
#define CAN_MOSTAT0_RTSEL        0x00000040
#define CAN_MOSTAT0_RXEN         0x00000080
#define CAN_MOSTAT0_RXPND        0x00000001
#define CAN_MOSTAT0_RXUPD        0x00000004
#define CAN_MOSTAT0_TXEN0        0x00000200
#define CAN_MOSTAT0_TXEN1        0x00000400
#define CAN_MOSTAT0_TXPND        0x00000002
#define CAN_MOSTAT0_TXRQ         0x00000100

// CAN Message Object 1 Status Register
#define CAN_MOSTAT1            (*((uword volatile *) 0xF000503C))
#define CAN_MOSTAT1_DIR          0x00000800
#define CAN_MOSTAT1_MSGLST       0x00000010
#define CAN_MOSTAT1_MSGVAL       0x00000020
#define CAN_MOSTAT1_NEWDAT       0x00000008
#define CAN_MOSTAT1_RTSEL        0x00000040
#define CAN_MOSTAT1_RXEN         0x00000080
#define CAN_MOSTAT1_RXPND        0x00000001
#define CAN_MOSTAT1_RXUPD        0x00000004
#define CAN_MOSTAT1_TXEN0        0x00000200
#define CAN_MOSTAT1_TXEN1        0x00000400
#define CAN_MOSTAT1_TXPND        0x00000002
#define CAN_MOSTAT1_TXRQ         0x00000100

// CAN Message Object 10 Status Register
#define CAN_MOSTAT10           (*((uword volatile *) 0xF000515C))
#define CAN_MOSTAT10_DIR         0x00000800
#define CAN_MOSTAT10_MSGLST      0x00000010
#define CAN_MOSTAT10_MSGVAL      0x00000020
#define CAN_MOSTAT10_NEWDAT      0x00000008
#define CAN_MOSTAT10_RTSEL       0x00000040
#define CAN_MOSTAT10_RXEN        0x00000080
#define CAN_MOSTAT10_RXPND       0x00000001
#define CAN_MOSTAT10_RXUPD       0x00000004
#define CAN_MOSTAT10_TXEN0       0x00000200
#define CAN_MOSTAT10_TXEN1       0x00000400
#define CAN_MOSTAT10_TXPND       0x00000002
#define CAN_MOSTAT10_TXRQ        0x00000100

// CAN Message Object 11 Status Register
#define CAN_MOSTAT11           (*((uword volatile *) 0xF000517C))
#define CAN_MOSTAT11_DIR         0x00000800
#define CAN_MOSTAT11_MSGLST      0x00000010
#define CAN_MOSTAT11_MSGVAL      0x00000020
#define CAN_MOSTAT11_NEWDAT      0x00000008
#define CAN_MOSTAT11_RTSEL       0x00000040
#define CAN_MOSTAT11_RXEN        0x00000080
#define CAN_MOSTAT11_RXPND       0x00000001
#define CAN_MOSTAT11_RXUPD       0x00000004
#define CAN_MOSTAT11_TXEN0       0x00000200
#define CAN_MOSTAT11_TXEN1       0x00000400
#define CAN_MOSTAT11_TXPND       0x00000002
#define CAN_MOSTAT11_TXRQ        0x00000100

// CAN Message Object 12 Status Register
#define CAN_MOSTAT12           (*((uword volatile *) 0xF000519C))
#define CAN_MOSTAT12_DIR         0x00000800
#define CAN_MOSTAT12_MSGLST      0x00000010
#define CAN_MOSTAT12_MSGVAL      0x00000020
#define CAN_MOSTAT12_NEWDAT      0x00000008
#define CAN_MOSTAT12_RTSEL       0x00000040
#define CAN_MOSTAT12_RXEN        0x00000080
#define CAN_MOSTAT12_RXPND       0x00000001
#define CAN_MOSTAT12_RXUPD       0x00000004
#define CAN_MOSTAT12_TXEN0       0x00000200
#define CAN_MOSTAT12_TXEN1       0x00000400
#define CAN_MOSTAT12_TXPND       0x00000002
#define CAN_MOSTAT12_TXRQ        0x00000100

// CAN Message Object 13 Status Register
#define CAN_MOSTAT13           (*((uword volatile *) 0xF00051BC))
#define CAN_MOSTAT13_DIR         0x00000800
#define CAN_MOSTAT13_MSGLST      0x00000010
#define CAN_MOSTAT13_MSGVAL      0x00000020
#define CAN_MOSTAT13_NEWDAT      0x00000008
#define CAN_MOSTAT13_RTSEL       0x00000040
#define CAN_MOSTAT13_RXEN        0x00000080
#define CAN_MOSTAT13_RXPND       0x00000001
#define CAN_MOSTAT13_RXUPD       0x00000004
#define CAN_MOSTAT13_TXEN0       0x00000200
#define CAN_MOSTAT13_TXEN1       0x00000400
#define CAN_MOSTAT13_TXPND       0x00000002
#define CAN_MOSTAT13_TXRQ        0x00000100

// CAN Message Object 14 Status Register
#define CAN_MOSTAT14           (*((uword volatile *) 0xF00051DC))
#define CAN_MOSTAT14_DIR         0x00000800
#define CAN_MOSTAT14_MSGLST      0x00000010
#define CAN_MOSTAT14_MSGVAL      0x00000020
#define CAN_MOSTAT14_NEWDAT      0x00000008
#define CAN_MOSTAT14_RTSEL       0x00000040
#define CAN_MOSTAT14_RXEN        0x00000080
#define CAN_MOSTAT14_RXPND       0x00000001
#define CAN_MOSTAT14_RXUPD       0x00000004
#define CAN_MOSTAT14_TXEN0       0x00000200
#define CAN_MOSTAT14_TXEN1       0x00000400
#define CAN_MOSTAT14_TXPND       0x00000002
#define CAN_MOSTAT14_TXRQ        0x00000100

// CAN Message Object 15 Status Register
#define CAN_MOSTAT15           (*((uword volatile *) 0xF00051FC))
#define CAN_MOSTAT15_DIR         0x00000800
#define CAN_MOSTAT15_MSGLST      0x00000010
#define CAN_MOSTAT15_MSGVAL      0x00000020
#define CAN_MOSTAT15_NEWDAT      0x00000008
#define CAN_MOSTAT15_RTSEL       0x00000040
#define CAN_MOSTAT15_RXEN        0x00000080
#define CAN_MOSTAT15_RXPND       0x00000001
#define CAN_MOSTAT15_RXUPD       0x00000004
#define CAN_MOSTAT15_TXEN0       0x00000200
#define CAN_MOSTAT15_TXEN1       0x00000400
#define CAN_MOSTAT15_TXPND       0x00000002
#define CAN_MOSTAT15_TXRQ        0x00000100

// CAN Message Object 16 Status Register
#define CAN_MOSTAT16           (*((uword volatile *) 0xF000521C))
#define CAN_MOSTAT16_DIR         0x00000800
#define CAN_MOSTAT16_MSGLST      0x00000010
#define CAN_MOSTAT16_MSGVAL      0x00000020
#define CAN_MOSTAT16_NEWDAT      0x00000008
#define CAN_MOSTAT16_RTSEL       0x00000040
#define CAN_MOSTAT16_RXEN        0x00000080
#define CAN_MOSTAT16_RXPND       0x00000001
#define CAN_MOSTAT16_RXUPD       0x00000004
#define CAN_MOSTAT16_TXEN0       0x00000200
#define CAN_MOSTAT16_TXEN1       0x00000400
#define CAN_MOSTAT16_TXPND       0x00000002
#define CAN_MOSTAT16_TXRQ        0x00000100

// CAN Message Object 17 Status Register
#define CAN_MOSTAT17           (*((uword volatile *) 0xF000523C))
#define CAN_MOSTAT17_DIR         0x00000800
#define CAN_MOSTAT17_MSGLST      0x00000010
#define CAN_MOSTAT17_MSGVAL      0x00000020
#define CAN_MOSTAT17_NEWDAT      0x00000008
#define CAN_MOSTAT17_RTSEL       0x00000040
#define CAN_MOSTAT17_RXEN        0x00000080
#define CAN_MOSTAT17_RXPND       0x00000001
#define CAN_MOSTAT17_RXUPD       0x00000004
#define CAN_MOSTAT17_TXEN0       0x00000200
#define CAN_MOSTAT17_TXEN1       0x00000400
#define CAN_MOSTAT17_TXPND       0x00000002
#define CAN_MOSTAT17_TXRQ        0x00000100

// CAN Message Object 18 Status Register
#define CAN_MOSTAT18           (*((uword volatile *) 0xF000525C))
#define CAN_MOSTAT18_DIR         0x00000800
#define CAN_MOSTAT18_MSGLST      0x00000010
#define CAN_MOSTAT18_MSGVAL      0x00000020
#define CAN_MOSTAT18_NEWDAT      0x00000008
#define CAN_MOSTAT18_RTSEL       0x00000040
#define CAN_MOSTAT18_RXEN        0x00000080
#define CAN_MOSTAT18_RXPND       0x00000001
#define CAN_MOSTAT18_RXUPD       0x00000004
#define CAN_MOSTAT18_TXEN0       0x00000200
#define CAN_MOSTAT18_TXEN1       0x00000400
#define CAN_MOSTAT18_TXPND       0x00000002
#define CAN_MOSTAT18_TXRQ        0x00000100

// CAN Message Object 19 Status Register
#define CAN_MOSTAT19           (*((uword volatile *) 0xF000527C))
#define CAN_MOSTAT19_DIR         0x00000800
#define CAN_MOSTAT19_MSGLST      0x00000010
#define CAN_MOSTAT19_MSGVAL      0x00000020
#define CAN_MOSTAT19_NEWDAT      0x00000008
#define CAN_MOSTAT19_RTSEL       0x00000040
#define CAN_MOSTAT19_RXEN        0x00000080
#define CAN_MOSTAT19_RXPND       0x00000001
#define CAN_MOSTAT19_RXUPD       0x00000004
#define CAN_MOSTAT19_TXEN0       0x00000200
#define CAN_MOSTAT19_TXEN1       0x00000400
#define CAN_MOSTAT19_TXPND       0x00000002
#define CAN_MOSTAT19_TXRQ        0x00000100

// CAN Message Object 2 Status Register
#define CAN_MOSTAT2            (*((uword volatile *) 0xF000505C))
#define CAN_MOSTAT2_DIR          0x00000800
#define CAN_MOSTAT2_MSGLST       0x00000010
#define CAN_MOSTAT2_MSGVAL       0x00000020
#define CAN_MOSTAT2_NEWDAT       0x00000008
#define CAN_MOSTAT2_RTSEL        0x00000040
#define CAN_MOSTAT2_RXEN         0x00000080
#define CAN_MOSTAT2_RXPND        0x00000001
#define CAN_MOSTAT2_RXUPD        0x00000004
#define CAN_MOSTAT2_TXEN0        0x00000200
#define CAN_MOSTAT2_TXEN1        0x00000400
#define CAN_MOSTAT2_TXPND        0x00000002
#define CAN_MOSTAT2_TXRQ         0x00000100

// CAN Message Object 20 Status Register
#define CAN_MOSTAT20           (*((uword volatile *) 0xF000529C))
#define CAN_MOSTAT20_DIR         0x00000800
#define CAN_MOSTAT20_MSGLST      0x00000010
#define CAN_MOSTAT20_MSGVAL      0x00000020
#define CAN_MOSTAT20_NEWDAT      0x00000008
#define CAN_MOSTAT20_RTSEL       0x00000040
#define CAN_MOSTAT20_RXEN        0x00000080
#define CAN_MOSTAT20_RXPND       0x00000001
#define CAN_MOSTAT20_RXUPD       0x00000004
#define CAN_MOSTAT20_TXEN0       0x00000200
#define CAN_MOSTAT20_TXEN1       0x00000400
#define CAN_MOSTAT20_TXPND       0x00000002
#define CAN_MOSTAT20_TXRQ        0x00000100

// CAN Message Object 21 Status Register
#define CAN_MOSTAT21           (*((uword volatile *) 0xF00052BC))
#define CAN_MOSTAT21_DIR         0x00000800
#define CAN_MOSTAT21_MSGLST      0x00000010
#define CAN_MOSTAT21_MSGVAL      0x00000020
#define CAN_MOSTAT21_NEWDAT      0x00000008
#define CAN_MOSTAT21_RTSEL       0x00000040
#define CAN_MOSTAT21_RXEN        0x00000080
#define CAN_MOSTAT21_RXPND       0x00000001
#define CAN_MOSTAT21_RXUPD       0x00000004
#define CAN_MOSTAT21_TXEN0       0x00000200
#define CAN_MOSTAT21_TXEN1       0x00000400
#define CAN_MOSTAT21_TXPND       0x00000002
#define CAN_MOSTAT21_TXRQ        0x00000100

// CAN Message Object 22 Status Register
#define CAN_MOSTAT22           (*((uword volatile *) 0xF00052DC))
#define CAN_MOSTAT22_DIR         0x00000800
#define CAN_MOSTAT22_MSGLST      0x00000010
#define CAN_MOSTAT22_MSGVAL      0x00000020
#define CAN_MOSTAT22_NEWDAT      0x00000008
#define CAN_MOSTAT22_RTSEL       0x00000040
#define CAN_MOSTAT22_RXEN        0x00000080
#define CAN_MOSTAT22_RXPND       0x00000001
#define CAN_MOSTAT22_RXUPD       0x00000004
#define CAN_MOSTAT22_TXEN0       0x00000200
#define CAN_MOSTAT22_TXEN1       0x00000400
#define CAN_MOSTAT22_TXPND       0x00000002
#define CAN_MOSTAT22_TXRQ        0x00000100

// CAN Message Object 23 Status Register
#define CAN_MOSTAT23           (*((uword volatile *) 0xF00052FC))
#define CAN_MOSTAT23_DIR         0x00000800
#define CAN_MOSTAT23_MSGLST      0x00000010
#define CAN_MOSTAT23_MSGVAL      0x00000020
#define CAN_MOSTAT23_NEWDAT      0x00000008
#define CAN_MOSTAT23_RTSEL       0x00000040
#define CAN_MOSTAT23_RXEN        0x00000080
#define CAN_MOSTAT23_RXPND       0x00000001
#define CAN_MOSTAT23_RXUPD       0x00000004
#define CAN_MOSTAT23_TXEN0       0x00000200
#define CAN_MOSTAT23_TXEN1       0x00000400
#define CAN_MOSTAT23_TXPND       0x00000002
#define CAN_MOSTAT23_TXRQ        0x00000100

// CAN Message Object 24 Status Register
#define CAN_MOSTAT24           (*((uword volatile *) 0xF000531C))
#define CAN_MOSTAT24_DIR         0x00000800
#define CAN_MOSTAT24_MSGLST      0x00000010
#define CAN_MOSTAT24_MSGVAL      0x00000020
#define CAN_MOSTAT24_NEWDAT      0x00000008
#define CAN_MOSTAT24_RTSEL       0x00000040
#define CAN_MOSTAT24_RXEN        0x00000080
#define CAN_MOSTAT24_RXPND       0x00000001
#define CAN_MOSTAT24_RXUPD       0x00000004
#define CAN_MOSTAT24_TXEN0       0x00000200
#define CAN_MOSTAT24_TXEN1       0x00000400
#define CAN_MOSTAT24_TXPND       0x00000002
#define CAN_MOSTAT24_TXRQ        0x00000100

// CAN Message Object 25 Status Register
#define CAN_MOSTAT25           (*((uword volatile *) 0xF000533C))
#define CAN_MOSTAT25_DIR         0x00000800
#define CAN_MOSTAT25_MSGLST      0x00000010
#define CAN_MOSTAT25_MSGVAL      0x00000020
#define CAN_MOSTAT25_NEWDAT      0x00000008
#define CAN_MOSTAT25_RTSEL       0x00000040
#define CAN_MOSTAT25_RXEN        0x00000080
#define CAN_MOSTAT25_RXPND       0x00000001
#define CAN_MOSTAT25_RXUPD       0x00000004
#define CAN_MOSTAT25_TXEN0       0x00000200
#define CAN_MOSTAT25_TXEN1       0x00000400
#define CAN_MOSTAT25_TXPND       0x00000002
#define CAN_MOSTAT25_TXRQ        0x00000100

// CAN Message Object 26 Status Register
#define CAN_MOSTAT26           (*((uword volatile *) 0xF000535C))
#define CAN_MOSTAT26_DIR         0x00000800
#define CAN_MOSTAT26_MSGLST      0x00000010
#define CAN_MOSTAT26_MSGVAL      0x00000020
#define CAN_MOSTAT26_NEWDAT      0x00000008
#define CAN_MOSTAT26_RTSEL       0x00000040
#define CAN_MOSTAT26_RXEN        0x00000080
#define CAN_MOSTAT26_RXPND       0x00000001
#define CAN_MOSTAT26_RXUPD       0x00000004
#define CAN_MOSTAT26_TXEN0       0x00000200
#define CAN_MOSTAT26_TXEN1       0x00000400
#define CAN_MOSTAT26_TXPND       0x00000002
#define CAN_MOSTAT26_TXRQ        0x00000100

// CAN Message Object 27 Status Register
#define CAN_MOSTAT27           (*((uword volatile *) 0xF000537C))
#define CAN_MOSTAT27_DIR         0x00000800
#define CAN_MOSTAT27_MSGLST      0x00000010
#define CAN_MOSTAT27_MSGVAL      0x00000020
#define CAN_MOSTAT27_NEWDAT      0x00000008
#define CAN_MOSTAT27_RTSEL       0x00000040
#define CAN_MOSTAT27_RXEN        0x00000080
#define CAN_MOSTAT27_RXPND       0x00000001
#define CAN_MOSTAT27_RXUPD       0x00000004
#define CAN_MOSTAT27_TXEN0       0x00000200
#define CAN_MOSTAT27_TXEN1       0x00000400
#define CAN_MOSTAT27_TXPND       0x00000002
#define CAN_MOSTAT27_TXRQ        0x00000100

// CAN Message Object 28 Status Register
#define CAN_MOSTAT28           (*((uword volatile *) 0xF000539C))
#define CAN_MOSTAT28_DIR         0x00000800
#define CAN_MOSTAT28_MSGLST      0x00000010
#define CAN_MOSTAT28_MSGVAL      0x00000020
#define CAN_MOSTAT28_NEWDAT      0x00000008
#define CAN_MOSTAT28_RTSEL       0x00000040
#define CAN_MOSTAT28_RXEN        0x00000080
#define CAN_MOSTAT28_RXPND       0x00000001
#define CAN_MOSTAT28_RXUPD       0x00000004
#define CAN_MOSTAT28_TXEN0       0x00000200
#define CAN_MOSTAT28_TXEN1       0x00000400
#define CAN_MOSTAT28_TXPND       0x00000002
#define CAN_MOSTAT28_TXRQ        0x00000100

// CAN Message Object 29 Status Register
#define CAN_MOSTAT29           (*((uword volatile *) 0xF00053BC))
#define CAN_MOSTAT29_DIR         0x00000800
#define CAN_MOSTAT29_MSGLST      0x00000010
#define CAN_MOSTAT29_MSGVAL      0x00000020
#define CAN_MOSTAT29_NEWDAT      0x00000008
#define CAN_MOSTAT29_RTSEL       0x00000040
#define CAN_MOSTAT29_RXEN        0x00000080
#define CAN_MOSTAT29_RXPND       0x00000001
#define CAN_MOSTAT29_RXUPD       0x00000004
#define CAN_MOSTAT29_TXEN0       0x00000200
#define CAN_MOSTAT29_TXEN1       0x00000400
#define CAN_MOSTAT29_TXPND       0x00000002
#define CAN_MOSTAT29_TXRQ        0x00000100

// CAN Message Object 3 Status Register
#define CAN_MOSTAT3            (*((uword volatile *) 0xF000507C))
#define CAN_MOSTAT3_DIR          0x00000800
#define CAN_MOSTAT3_MSGLST       0x00000010
#define CAN_MOSTAT3_MSGVAL       0x00000020
#define CAN_MOSTAT3_NEWDAT       0x00000008
#define CAN_MOSTAT3_RTSEL        0x00000040
#define CAN_MOSTAT3_RXEN         0x00000080
#define CAN_MOSTAT3_RXPND        0x00000001
#define CAN_MOSTAT3_RXUPD        0x00000004
#define CAN_MOSTAT3_TXEN0        0x00000200
#define CAN_MOSTAT3_TXEN1        0x00000400
#define CAN_MOSTAT3_TXPND        0x00000002
#define CAN_MOSTAT3_TXRQ         0x00000100

// CAN Message Object 30 Status Register
#define CAN_MOSTAT30           (*((uword volatile *) 0xF00053DC))
#define CAN_MOSTAT30_DIR         0x00000800
#define CAN_MOSTAT30_MSGLST      0x00000010
#define CAN_MOSTAT30_MSGVAL      0x00000020
#define CAN_MOSTAT30_NEWDAT      0x00000008
#define CAN_MOSTAT30_RTSEL       0x00000040
#define CAN_MOSTAT30_RXEN        0x00000080
#define CAN_MOSTAT30_RXPND       0x00000001
#define CAN_MOSTAT30_RXUPD       0x00000004
#define CAN_MOSTAT30_TXEN0       0x00000200
#define CAN_MOSTAT30_TXEN1       0x00000400
#define CAN_MOSTAT30_TXPND       0x00000002
#define CAN_MOSTAT30_TXRQ        0x00000100

// CAN Message Object 31 Status Register
#define CAN_MOSTAT31           (*((uword volatile *) 0xF00053FC))
#define CAN_MOSTAT31_DIR         0x00000800
#define CAN_MOSTAT31_MSGLST      0x00000010
#define CAN_MOSTAT31_MSGVAL      0x00000020
#define CAN_MOSTAT31_NEWDAT      0x00000008
#define CAN_MOSTAT31_RTSEL       0x00000040
#define CAN_MOSTAT31_RXEN        0x00000080
#define CAN_MOSTAT31_RXPND       0x00000001
#define CAN_MOSTAT31_RXUPD       0x00000004
#define CAN_MOSTAT31_TXEN0       0x00000200
#define CAN_MOSTAT31_TXEN1       0x00000400
#define CAN_MOSTAT31_TXPND       0x00000002
#define CAN_MOSTAT31_TXRQ        0x00000100

// CAN Message Object 32 Status Register
#define CAN_MOSTAT32           (*((uword volatile *) 0xF000541C))
#define CAN_MOSTAT32_DIR         0x00000800
#define CAN_MOSTAT32_MSGLST      0x00000010
#define CAN_MOSTAT32_MSGVAL      0x00000020
#define CAN_MOSTAT32_NEWDAT      0x00000008
#define CAN_MOSTAT32_RTSEL       0x00000040
#define CAN_MOSTAT32_RXEN        0x00000080
#define CAN_MOSTAT32_RXPND       0x00000001
#define CAN_MOSTAT32_RXUPD       0x00000004
#define CAN_MOSTAT32_TXEN0       0x00000200
#define CAN_MOSTAT32_TXEN1       0x00000400
#define CAN_MOSTAT32_TXPND       0x00000002
#define CAN_MOSTAT32_TXRQ        0x00000100

// CAN Message Object 33 Status Register
#define CAN_MOSTAT33           (*((uword volatile *) 0xF000543C))
#define CAN_MOSTAT33_DIR         0x00000800
#define CAN_MOSTAT33_MSGLST      0x00000010
#define CAN_MOSTAT33_MSGVAL      0x00000020
#define CAN_MOSTAT33_NEWDAT      0x00000008
#define CAN_MOSTAT33_RTSEL       0x00000040
#define CAN_MOSTAT33_RXEN        0x00000080
#define CAN_MOSTAT33_RXPND       0x00000001
#define CAN_MOSTAT33_RXUPD       0x00000004
#define CAN_MOSTAT33_TXEN0       0x00000200
#define CAN_MOSTAT33_TXEN1       0x00000400
#define CAN_MOSTAT33_TXPND       0x00000002
#define CAN_MOSTAT33_TXRQ        0x00000100

// CAN Message Object 34 Status Register
#define CAN_MOSTAT34           (*((uword volatile *) 0xF000545C))
#define CAN_MOSTAT34_DIR         0x00000800
#define CAN_MOSTAT34_MSGLST      0x00000010
#define CAN_MOSTAT34_MSGVAL      0x00000020
#define CAN_MOSTAT34_NEWDAT      0x00000008
#define CAN_MOSTAT34_RTSEL       0x00000040
#define CAN_MOSTAT34_RXEN        0x00000080
#define CAN_MOSTAT34_RXPND       0x00000001
#define CAN_MOSTAT34_RXUPD       0x00000004
#define CAN_MOSTAT34_TXEN0       0x00000200
#define CAN_MOSTAT34_TXEN1       0x00000400
#define CAN_MOSTAT34_TXPND       0x00000002
#define CAN_MOSTAT34_TXRQ        0x00000100

// CAN Message Object 35 Status Register
#define CAN_MOSTAT35           (*((uword volatile *) 0xF000547C))
#define CAN_MOSTAT35_DIR         0x00000800
#define CAN_MOSTAT35_MSGLST      0x00000010
#define CAN_MOSTAT35_MSGVAL      0x00000020
#define CAN_MOSTAT35_NEWDAT      0x00000008
#define CAN_MOSTAT35_RTSEL       0x00000040
#define CAN_MOSTAT35_RXEN        0x00000080
#define CAN_MOSTAT35_RXPND       0x00000001
#define CAN_MOSTAT35_RXUPD       0x00000004
#define CAN_MOSTAT35_TXEN0       0x00000200
#define CAN_MOSTAT35_TXEN1       0x00000400
#define CAN_MOSTAT35_TXPND       0x00000002
#define CAN_MOSTAT35_TXRQ        0x00000100

// CAN Message Object 36 Status Register
#define CAN_MOSTAT36           (*((uword volatile *) 0xF000549C))
#define CAN_MOSTAT36_DIR         0x00000800
#define CAN_MOSTAT36_MSGLST      0x00000010
#define CAN_MOSTAT36_MSGVAL      0x00000020
#define CAN_MOSTAT36_NEWDAT      0x00000008
#define CAN_MOSTAT36_RTSEL       0x00000040
#define CAN_MOSTAT36_RXEN        0x00000080
#define CAN_MOSTAT36_RXPND       0x00000001
#define CAN_MOSTAT36_RXUPD       0x00000004
#define CAN_MOSTAT36_TXEN0       0x00000200
#define CAN_MOSTAT36_TXEN1       0x00000400
#define CAN_MOSTAT36_TXPND       0x00000002
#define CAN_MOSTAT36_TXRQ        0x00000100

// CAN Message Object 37 Status Register
#define CAN_MOSTAT37           (*((uword volatile *) 0xF00054BC))
#define CAN_MOSTAT37_DIR         0x00000800
#define CAN_MOSTAT37_MSGLST      0x00000010
#define CAN_MOSTAT37_MSGVAL      0x00000020
#define CAN_MOSTAT37_NEWDAT      0x00000008
#define CAN_MOSTAT37_RTSEL       0x00000040
#define CAN_MOSTAT37_RXEN        0x00000080
#define CAN_MOSTAT37_RXPND       0x00000001
#define CAN_MOSTAT37_RXUPD       0x00000004
#define CAN_MOSTAT37_TXEN0       0x00000200
#define CAN_MOSTAT37_TXEN1       0x00000400
#define CAN_MOSTAT37_TXPND       0x00000002
#define CAN_MOSTAT37_TXRQ        0x00000100

// CAN Message Object 38 Status Register
#define CAN_MOSTAT38           (*((uword volatile *) 0xF00054DC))
#define CAN_MOSTAT38_DIR         0x00000800
#define CAN_MOSTAT38_MSGLST      0x00000010
#define CAN_MOSTAT38_MSGVAL      0x00000020
#define CAN_MOSTAT38_NEWDAT      0x00000008
#define CAN_MOSTAT38_RTSEL       0x00000040
#define CAN_MOSTAT38_RXEN        0x00000080
#define CAN_MOSTAT38_RXPND       0x00000001
#define CAN_MOSTAT38_RXUPD       0x00000004
#define CAN_MOSTAT38_TXEN0       0x00000200
#define CAN_MOSTAT38_TXEN1       0x00000400
#define CAN_MOSTAT38_TXPND       0x00000002
#define CAN_MOSTAT38_TXRQ        0x00000100

// CAN Message Object 39 Status Register
#define CAN_MOSTAT39           (*((uword volatile *) 0xF00054FC))
#define CAN_MOSTAT39_DIR         0x00000800
#define CAN_MOSTAT39_MSGLST      0x00000010
#define CAN_MOSTAT39_MSGVAL      0x00000020
#define CAN_MOSTAT39_NEWDAT      0x00000008
#define CAN_MOSTAT39_RTSEL       0x00000040
#define CAN_MOSTAT39_RXEN        0x00000080
#define CAN_MOSTAT39_RXPND       0x00000001
#define CAN_MOSTAT39_RXUPD       0x00000004
#define CAN_MOSTAT39_TXEN0       0x00000200
#define CAN_MOSTAT39_TXEN1       0x00000400
#define CAN_MOSTAT39_TXPND       0x00000002
#define CAN_MOSTAT39_TXRQ        0x00000100

// CAN Message Object 4 Status Register
#define CAN_MOSTAT4            (*((uword volatile *) 0xF000509C))
#define CAN_MOSTAT4_DIR          0x00000800
#define CAN_MOSTAT4_MSGLST       0x00000010
#define CAN_MOSTAT4_MSGVAL       0x00000020
#define CAN_MOSTAT4_NEWDAT       0x00000008
#define CAN_MOSTAT4_RTSEL        0x00000040
#define CAN_MOSTAT4_RXEN         0x00000080
#define CAN_MOSTAT4_RXPND        0x00000001
#define CAN_MOSTAT4_RXUPD        0x00000004
#define CAN_MOSTAT4_TXEN0        0x00000200
#define CAN_MOSTAT4_TXEN1        0x00000400
#define CAN_MOSTAT4_TXPND        0x00000002
#define CAN_MOSTAT4_TXRQ         0x00000100

// CAN Message Object 40 Status Register
#define CAN_MOSTAT40           (*((uword volatile *) 0xF000551C))
#define CAN_MOSTAT40_DIR         0x00000800
#define CAN_MOSTAT40_MSGLST      0x00000010
#define CAN_MOSTAT40_MSGVAL      0x00000020
#define CAN_MOSTAT40_NEWDAT      0x00000008
#define CAN_MOSTAT40_RTSEL       0x00000040
#define CAN_MOSTAT40_RXEN        0x00000080
#define CAN_MOSTAT40_RXPND       0x00000001
#define CAN_MOSTAT40_RXUPD       0x00000004
#define CAN_MOSTAT40_TXEN0       0x00000200
#define CAN_MOSTAT40_TXEN1       0x00000400
#define CAN_MOSTAT40_TXPND       0x00000002
#define CAN_MOSTAT40_TXRQ        0x00000100

// CAN Message Object 41 Status Register
#define CAN_MOSTAT41           (*((uword volatile *) 0xF000553C))
#define CAN_MOSTAT41_DIR         0x00000800
#define CAN_MOSTAT41_MSGLST      0x00000010
#define CAN_MOSTAT41_MSGVAL      0x00000020
#define CAN_MOSTAT41_NEWDAT      0x00000008
#define CAN_MOSTAT41_RTSEL       0x00000040
#define CAN_MOSTAT41_RXEN        0x00000080
#define CAN_MOSTAT41_RXPND       0x00000001
#define CAN_MOSTAT41_RXUPD       0x00000004
#define CAN_MOSTAT41_TXEN0       0x00000200
#define CAN_MOSTAT41_TXEN1       0x00000400
#define CAN_MOSTAT41_TXPND       0x00000002
#define CAN_MOSTAT41_TXRQ        0x00000100

// CAN Message Object 42 Status Register
#define CAN_MOSTAT42           (*((uword volatile *) 0xF000555C))
#define CAN_MOSTAT42_DIR         0x00000800
#define CAN_MOSTAT42_MSGLST      0x00000010
#define CAN_MOSTAT42_MSGVAL      0x00000020
#define CAN_MOSTAT42_NEWDAT      0x00000008
#define CAN_MOSTAT42_RTSEL       0x00000040
#define CAN_MOSTAT42_RXEN        0x00000080
#define CAN_MOSTAT42_RXPND       0x00000001
#define CAN_MOSTAT42_RXUPD       0x00000004
#define CAN_MOSTAT42_TXEN0       0x00000200
#define CAN_MOSTAT42_TXEN1       0x00000400
#define CAN_MOSTAT42_TXPND       0x00000002
#define CAN_MOSTAT42_TXRQ        0x00000100

// CAN Message Object 43 Status Register
#define CAN_MOSTAT43           (*((uword volatile *) 0xF000557C))
#define CAN_MOSTAT43_DIR         0x00000800
#define CAN_MOSTAT43_MSGLST      0x00000010
#define CAN_MOSTAT43_MSGVAL      0x00000020
#define CAN_MOSTAT43_NEWDAT      0x00000008
#define CAN_MOSTAT43_RTSEL       0x00000040
#define CAN_MOSTAT43_RXEN        0x00000080
#define CAN_MOSTAT43_RXPND       0x00000001
#define CAN_MOSTAT43_RXUPD       0x00000004
#define CAN_MOSTAT43_TXEN0       0x00000200
#define CAN_MOSTAT43_TXEN1       0x00000400
#define CAN_MOSTAT43_TXPND       0x00000002
#define CAN_MOSTAT43_TXRQ        0x00000100

// CAN Message Object 44 Status Register
#define CAN_MOSTAT44           (*((uword volatile *) 0xF000559C))
#define CAN_MOSTAT44_DIR         0x00000800
#define CAN_MOSTAT44_MSGLST      0x00000010
#define CAN_MOSTAT44_MSGVAL      0x00000020
#define CAN_MOSTAT44_NEWDAT      0x00000008
#define CAN_MOSTAT44_RTSEL       0x00000040
#define CAN_MOSTAT44_RXEN        0x00000080
#define CAN_MOSTAT44_RXPND       0x00000001
#define CAN_MOSTAT44_RXUPD       0x00000004
#define CAN_MOSTAT44_TXEN0       0x00000200
#define CAN_MOSTAT44_TXEN1       0x00000400
#define CAN_MOSTAT44_TXPND       0x00000002
#define CAN_MOSTAT44_TXRQ        0x00000100

// CAN Message Object 45 Status Register
#define CAN_MOSTAT45           (*((uword volatile *) 0xF00055BC))
#define CAN_MOSTAT45_DIR         0x00000800
#define CAN_MOSTAT45_MSGLST      0x00000010
#define CAN_MOSTAT45_MSGVAL      0x00000020
#define CAN_MOSTAT45_NEWDAT      0x00000008
#define CAN_MOSTAT45_RTSEL       0x00000040
#define CAN_MOSTAT45_RXEN        0x00000080
#define CAN_MOSTAT45_RXPND       0x00000001
#define CAN_MOSTAT45_RXUPD       0x00000004
#define CAN_MOSTAT45_TXEN0       0x00000200
#define CAN_MOSTAT45_TXEN1       0x00000400
#define CAN_MOSTAT45_TXPND       0x00000002
#define CAN_MOSTAT45_TXRQ        0x00000100

// CAN Message Object 46 Status Register
#define CAN_MOSTAT46           (*((uword volatile *) 0xF00055DC))
#define CAN_MOSTAT46_DIR         0x00000800
#define CAN_MOSTAT46_MSGLST      0x00000010
#define CAN_MOSTAT46_MSGVAL      0x00000020
#define CAN_MOSTAT46_NEWDAT      0x00000008
#define CAN_MOSTAT46_RTSEL       0x00000040
#define CAN_MOSTAT46_RXEN        0x00000080
#define CAN_MOSTAT46_RXPND       0x00000001
#define CAN_MOSTAT46_RXUPD       0x00000004
#define CAN_MOSTAT46_TXEN0       0x00000200
#define CAN_MOSTAT46_TXEN1       0x00000400
#define CAN_MOSTAT46_TXPND       0x00000002
#define CAN_MOSTAT46_TXRQ        0x00000100

// CAN Message Object 47 Status Register
#define CAN_MOSTAT47           (*((uword volatile *) 0xF00055FC))
#define CAN_MOSTAT47_DIR         0x00000800
#define CAN_MOSTAT47_MSGLST      0x00000010
#define CAN_MOSTAT47_MSGVAL      0x00000020
#define CAN_MOSTAT47_NEWDAT      0x00000008
#define CAN_MOSTAT47_RTSEL       0x00000040
#define CAN_MOSTAT47_RXEN        0x00000080
#define CAN_MOSTAT47_RXPND       0x00000001
#define CAN_MOSTAT47_RXUPD       0x00000004
#define CAN_MOSTAT47_TXEN0       0x00000200
#define CAN_MOSTAT47_TXEN1       0x00000400
#define CAN_MOSTAT47_TXPND       0x00000002
#define CAN_MOSTAT47_TXRQ        0x00000100

// CAN Message Object 48 Status Register
#define CAN_MOSTAT48           (*((uword volatile *) 0xF000561C))
#define CAN_MOSTAT48_DIR         0x00000800
#define CAN_MOSTAT48_MSGLST      0x00000010
#define CAN_MOSTAT48_MSGVAL      0x00000020
#define CAN_MOSTAT48_NEWDAT      0x00000008
#define CAN_MOSTAT48_RTSEL       0x00000040
#define CAN_MOSTAT48_RXEN        0x00000080
#define CAN_MOSTAT48_RXPND       0x00000001
#define CAN_MOSTAT48_RXUPD       0x00000004
#define CAN_MOSTAT48_TXEN0       0x00000200
#define CAN_MOSTAT48_TXEN1       0x00000400
#define CAN_MOSTAT48_TXPND       0x00000002
#define CAN_MOSTAT48_TXRQ        0x00000100

// CAN Message Object 49 Status Register
#define CAN_MOSTAT49           (*((uword volatile *) 0xF000563C))
#define CAN_MOSTAT49_DIR         0x00000800
#define CAN_MOSTAT49_MSGLST      0x00000010
#define CAN_MOSTAT49_MSGVAL      0x00000020
#define CAN_MOSTAT49_NEWDAT      0x00000008
#define CAN_MOSTAT49_RTSEL       0x00000040
#define CAN_MOSTAT49_RXEN        0x00000080
#define CAN_MOSTAT49_RXPND       0x00000001
#define CAN_MOSTAT49_RXUPD       0x00000004
#define CAN_MOSTAT49_TXEN0       0x00000200
#define CAN_MOSTAT49_TXEN1       0x00000400
#define CAN_MOSTAT49_TXPND       0x00000002
#define CAN_MOSTAT49_TXRQ        0x00000100

// CAN Message Object 5 Status Register
#define CAN_MOSTAT5            (*((uword volatile *) 0xF00050BC))
#define CAN_MOSTAT5_DIR          0x00000800
#define CAN_MOSTAT5_MSGLST       0x00000010
#define CAN_MOSTAT5_MSGVAL       0x00000020
#define CAN_MOSTAT5_NEWDAT       0x00000008
#define CAN_MOSTAT5_RTSEL        0x00000040
#define CAN_MOSTAT5_RXEN         0x00000080
#define CAN_MOSTAT5_RXPND        0x00000001
#define CAN_MOSTAT5_RXUPD        0x00000004
#define CAN_MOSTAT5_TXEN0        0x00000200
#define CAN_MOSTAT5_TXEN1        0x00000400
#define CAN_MOSTAT5_TXPND        0x00000002
#define CAN_MOSTAT5_TXRQ         0x00000100

// CAN Message Object 50 Status Register
#define CAN_MOSTAT50           (*((uword volatile *) 0xF000565C))
#define CAN_MOSTAT50_DIR         0x00000800
#define CAN_MOSTAT50_MSGLST      0x00000010
#define CAN_MOSTAT50_MSGVAL      0x00000020
#define CAN_MOSTAT50_NEWDAT      0x00000008
#define CAN_MOSTAT50_RTSEL       0x00000040
#define CAN_MOSTAT50_RXEN        0x00000080
#define CAN_MOSTAT50_RXPND       0x00000001
#define CAN_MOSTAT50_RXUPD       0x00000004
#define CAN_MOSTAT50_TXEN0       0x00000200
#define CAN_MOSTAT50_TXEN1       0x00000400
#define CAN_MOSTAT50_TXPND       0x00000002
#define CAN_MOSTAT50_TXRQ        0x00000100

// CAN Message Object 51 Status Register
#define CAN_MOSTAT51           (*((uword volatile *) 0xF000567C))
#define CAN_MOSTAT51_DIR         0x00000800
#define CAN_MOSTAT51_MSGLST      0x00000010
#define CAN_MOSTAT51_MSGVAL      0x00000020
#define CAN_MOSTAT51_NEWDAT      0x00000008
#define CAN_MOSTAT51_RTSEL       0x00000040
#define CAN_MOSTAT51_RXEN        0x00000080
#define CAN_MOSTAT51_RXPND       0x00000001
#define CAN_MOSTAT51_RXUPD       0x00000004
#define CAN_MOSTAT51_TXEN0       0x00000200
#define CAN_MOSTAT51_TXEN1       0x00000400
#define CAN_MOSTAT51_TXPND       0x00000002
#define CAN_MOSTAT51_TXRQ        0x00000100

// CAN Message Object 52 Status Register
#define CAN_MOSTAT52           (*((uword volatile *) 0xF000569C))
#define CAN_MOSTAT52_DIR         0x00000800
#define CAN_MOSTAT52_MSGLST      0x00000010
#define CAN_MOSTAT52_MSGVAL      0x00000020
#define CAN_MOSTAT52_NEWDAT      0x00000008
#define CAN_MOSTAT52_RTSEL       0x00000040
#define CAN_MOSTAT52_RXEN        0x00000080
#define CAN_MOSTAT52_RXPND       0x00000001
#define CAN_MOSTAT52_RXUPD       0x00000004
#define CAN_MOSTAT52_TXEN0       0x00000200
#define CAN_MOSTAT52_TXEN1       0x00000400
#define CAN_MOSTAT52_TXPND       0x00000002
#define CAN_MOSTAT52_TXRQ        0x00000100

// CAN Message Object 53 Status Register
#define CAN_MOSTAT53           (*((uword volatile *) 0xF00056BC))
#define CAN_MOSTAT53_DIR         0x00000800
#define CAN_MOSTAT53_MSGLST      0x00000010
#define CAN_MOSTAT53_MSGVAL      0x00000020
#define CAN_MOSTAT53_NEWDAT      0x00000008
#define CAN_MOSTAT53_RTSEL       0x00000040
#define CAN_MOSTAT53_RXEN        0x00000080
#define CAN_MOSTAT53_RXPND       0x00000001
#define CAN_MOSTAT53_RXUPD       0x00000004
#define CAN_MOSTAT53_TXEN0       0x00000200
#define CAN_MOSTAT53_TXEN1       0x00000400
#define CAN_MOSTAT53_TXPND       0x00000002
#define CAN_MOSTAT53_TXRQ        0x00000100

// CAN Message Object 54 Status Register
#define CAN_MOSTAT54           (*((uword volatile *) 0xF00056DC))
#define CAN_MOSTAT54_DIR         0x00000800
#define CAN_MOSTAT54_MSGLST      0x00000010
#define CAN_MOSTAT54_MSGVAL      0x00000020
#define CAN_MOSTAT54_NEWDAT      0x00000008
#define CAN_MOSTAT54_RTSEL       0x00000040
#define CAN_MOSTAT54_RXEN        0x00000080
#define CAN_MOSTAT54_RXPND       0x00000001
#define CAN_MOSTAT54_RXUPD       0x00000004
#define CAN_MOSTAT54_TXEN0       0x00000200
#define CAN_MOSTAT54_TXEN1       0x00000400
#define CAN_MOSTAT54_TXPND       0x00000002
#define CAN_MOSTAT54_TXRQ        0x00000100

// CAN Message Object 55 Status Register
#define CAN_MOSTAT55           (*((uword volatile *) 0xF00056FC))
#define CAN_MOSTAT55_DIR         0x00000800
#define CAN_MOSTAT55_MSGLST      0x00000010
#define CAN_MOSTAT55_MSGVAL      0x00000020
#define CAN_MOSTAT55_NEWDAT      0x00000008
#define CAN_MOSTAT55_RTSEL       0x00000040
#define CAN_MOSTAT55_RXEN        0x00000080
#define CAN_MOSTAT55_RXPND       0x00000001
#define CAN_MOSTAT55_RXUPD       0x00000004
#define CAN_MOSTAT55_TXEN0       0x00000200
#define CAN_MOSTAT55_TXEN1       0x00000400
#define CAN_MOSTAT55_TXPND       0x00000002
#define CAN_MOSTAT55_TXRQ        0x00000100

// CAN Message Object 56 Status Register
#define CAN_MOSTAT56           (*((uword volatile *) 0xF000571C))
#define CAN_MOSTAT56_DIR         0x00000800
#define CAN_MOSTAT56_MSGLST      0x00000010
#define CAN_MOSTAT56_MSGVAL      0x00000020
#define CAN_MOSTAT56_NEWDAT      0x00000008
#define CAN_MOSTAT56_RTSEL       0x00000040
#define CAN_MOSTAT56_RXEN        0x00000080
#define CAN_MOSTAT56_RXPND       0x00000001
#define CAN_MOSTAT56_RXUPD       0x00000004
#define CAN_MOSTAT56_TXEN0       0x00000200
#define CAN_MOSTAT56_TXEN1       0x00000400
#define CAN_MOSTAT56_TXPND       0x00000002
#define CAN_MOSTAT56_TXRQ        0x00000100

// CAN Message Object 57 Status Register
#define CAN_MOSTAT57           (*((uword volatile *) 0xF000573C))
#define CAN_MOSTAT57_DIR         0x00000800
#define CAN_MOSTAT57_MSGLST      0x00000010
#define CAN_MOSTAT57_MSGVAL      0x00000020
#define CAN_MOSTAT57_NEWDAT      0x00000008
#define CAN_MOSTAT57_RTSEL       0x00000040
#define CAN_MOSTAT57_RXEN        0x00000080
#define CAN_MOSTAT57_RXPND       0x00000001
#define CAN_MOSTAT57_RXUPD       0x00000004
#define CAN_MOSTAT57_TXEN0       0x00000200
#define CAN_MOSTAT57_TXEN1       0x00000400
#define CAN_MOSTAT57_TXPND       0x00000002
#define CAN_MOSTAT57_TXRQ        0x00000100

// CAN Message Object 58 Status Register
#define CAN_MOSTAT58           (*((uword volatile *) 0xF000575C))
#define CAN_MOSTAT58_DIR         0x00000800
#define CAN_MOSTAT58_MSGLST      0x00000010
#define CAN_MOSTAT58_MSGVAL      0x00000020
#define CAN_MOSTAT58_NEWDAT      0x00000008
#define CAN_MOSTAT58_RTSEL       0x00000040
#define CAN_MOSTAT58_RXEN        0x00000080
#define CAN_MOSTAT58_RXPND       0x00000001
#define CAN_MOSTAT58_RXUPD       0x00000004
#define CAN_MOSTAT58_TXEN0       0x00000200
#define CAN_MOSTAT58_TXEN1       0x00000400
#define CAN_MOSTAT58_TXPND       0x00000002
#define CAN_MOSTAT58_TXRQ        0x00000100

// CAN Message Object 59 Status Register
#define CAN_MOSTAT59           (*((uword volatile *) 0xF000577C))
#define CAN_MOSTAT59_DIR         0x00000800
#define CAN_MOSTAT59_MSGLST      0x00000010
#define CAN_MOSTAT59_MSGVAL      0x00000020
#define CAN_MOSTAT59_NEWDAT      0x00000008
#define CAN_MOSTAT59_RTSEL       0x00000040
#define CAN_MOSTAT59_RXEN        0x00000080
#define CAN_MOSTAT59_RXPND       0x00000001
#define CAN_MOSTAT59_RXUPD       0x00000004
#define CAN_MOSTAT59_TXEN0       0x00000200
#define CAN_MOSTAT59_TXEN1       0x00000400
#define CAN_MOSTAT59_TXPND       0x00000002
#define CAN_MOSTAT59_TXRQ        0x00000100

// CAN Message Object 6 Status Register
#define CAN_MOSTAT6            (*((uword volatile *) 0xF00050DC))
#define CAN_MOSTAT6_DIR          0x00000800
#define CAN_MOSTAT6_MSGLST       0x00000010
#define CAN_MOSTAT6_MSGVAL       0x00000020
#define CAN_MOSTAT6_NEWDAT       0x00000008
#define CAN_MOSTAT6_RTSEL        0x00000040
#define CAN_MOSTAT6_RXEN         0x00000080
#define CAN_MOSTAT6_RXPND        0x00000001
#define CAN_MOSTAT6_RXUPD        0x00000004
#define CAN_MOSTAT6_TXEN0        0x00000200
#define CAN_MOSTAT6_TXEN1        0x00000400
#define CAN_MOSTAT6_TXPND        0x00000002
#define CAN_MOSTAT6_TXRQ         0x00000100

// CAN Message Object 60 Status Register
#define CAN_MOSTAT60           (*((uword volatile *) 0xF000579C))
#define CAN_MOSTAT60_DIR         0x00000800
#define CAN_MOSTAT60_MSGLST      0x00000010
#define CAN_MOSTAT60_MSGVAL      0x00000020
#define CAN_MOSTAT60_NEWDAT      0x00000008
#define CAN_MOSTAT60_RTSEL       0x00000040
#define CAN_MOSTAT60_RXEN        0x00000080
#define CAN_MOSTAT60_RXPND       0x00000001
#define CAN_MOSTAT60_RXUPD       0x00000004
#define CAN_MOSTAT60_TXEN0       0x00000200
#define CAN_MOSTAT60_TXEN1       0x00000400
#define CAN_MOSTAT60_TXPND       0x00000002
#define CAN_MOSTAT60_TXRQ        0x00000100

// CAN Message Object 61 Status Register
#define CAN_MOSTAT61           (*((uword volatile *) 0xF00057BC))
#define CAN_MOSTAT61_DIR         0x00000800
#define CAN_MOSTAT61_MSGLST      0x00000010
#define CAN_MOSTAT61_MSGVAL      0x00000020
#define CAN_MOSTAT61_NEWDAT      0x00000008
#define CAN_MOSTAT61_RTSEL       0x00000040
#define CAN_MOSTAT61_RXEN        0x00000080
#define CAN_MOSTAT61_RXPND       0x00000001
#define CAN_MOSTAT61_RXUPD       0x00000004
#define CAN_MOSTAT61_TXEN0       0x00000200
#define CAN_MOSTAT61_TXEN1       0x00000400
#define CAN_MOSTAT61_TXPND       0x00000002
#define CAN_MOSTAT61_TXRQ        0x00000100

// CAN Message Object 62 Status Register
#define CAN_MOSTAT62           (*((uword volatile *) 0xF00057DC))
#define CAN_MOSTAT62_DIR         0x00000800
#define CAN_MOSTAT62_MSGLST      0x00000010
#define CAN_MOSTAT62_MSGVAL      0x00000020
#define CAN_MOSTAT62_NEWDAT      0x00000008
#define CAN_MOSTAT62_RTSEL       0x00000040
#define CAN_MOSTAT62_RXEN        0x00000080
#define CAN_MOSTAT62_RXPND       0x00000001
#define CAN_MOSTAT62_RXUPD       0x00000004
#define CAN_MOSTAT62_TXEN0       0x00000200
#define CAN_MOSTAT62_TXEN1       0x00000400
#define CAN_MOSTAT62_TXPND       0x00000002
#define CAN_MOSTAT62_TXRQ        0x00000100

// CAN Message Object 63 Status Register
#define CAN_MOSTAT63           (*((uword volatile *) 0xF00057FC))
#define CAN_MOSTAT63_DIR         0x00000800
#define CAN_MOSTAT63_MSGLST      0x00000010
#define CAN_MOSTAT63_MSGVAL      0x00000020
#define CAN_MOSTAT63_NEWDAT      0x00000008
#define CAN_MOSTAT63_RTSEL       0x00000040
#define CAN_MOSTAT63_RXEN        0x00000080
#define CAN_MOSTAT63_RXPND       0x00000001
#define CAN_MOSTAT63_RXUPD       0x00000004
#define CAN_MOSTAT63_TXEN0       0x00000200
#define CAN_MOSTAT63_TXEN1       0x00000400
#define CAN_MOSTAT63_TXPND       0x00000002
#define CAN_MOSTAT63_TXRQ        0x00000100

// CAN Message Object 7 Status Register
#define CAN_MOSTAT7            (*((uword volatile *) 0xF00050FC))
#define CAN_MOSTAT7_DIR          0x00000800
#define CAN_MOSTAT7_MSGLST       0x00000010
#define CAN_MOSTAT7_MSGVAL       0x00000020
#define CAN_MOSTAT7_NEWDAT       0x00000008
#define CAN_MOSTAT7_RTSEL        0x00000040
#define CAN_MOSTAT7_RXEN         0x00000080
#define CAN_MOSTAT7_RXPND        0x00000001
#define CAN_MOSTAT7_RXUPD        0x00000004
#define CAN_MOSTAT7_TXEN0        0x00000200
#define CAN_MOSTAT7_TXEN1        0x00000400
#define CAN_MOSTAT7_TXPND        0x00000002
#define CAN_MOSTAT7_TXRQ         0x00000100

// CAN Message Object 8 Status Register
#define CAN_MOSTAT8            (*((uword volatile *) 0xF000511C))
#define CAN_MOSTAT8_DIR          0x00000800
#define CAN_MOSTAT8_MSGLST       0x00000010
#define CAN_MOSTAT8_MSGVAL       0x00000020
#define CAN_MOSTAT8_NEWDAT       0x00000008
#define CAN_MOSTAT8_RTSEL        0x00000040
#define CAN_MOSTAT8_RXEN         0x00000080
#define CAN_MOSTAT8_RXPND        0x00000001
#define CAN_MOSTAT8_RXUPD        0x00000004
#define CAN_MOSTAT8_TXEN0        0x00000200
#define CAN_MOSTAT8_TXEN1        0x00000400
#define CAN_MOSTAT8_TXPND        0x00000002
#define CAN_MOSTAT8_TXRQ         0x00000100

// CAN Message Object 9 Status Register
#define CAN_MOSTAT9            (*((uword volatile *) 0xF000513C))
#define CAN_MOSTAT9_DIR          0x00000800
#define CAN_MOSTAT9_MSGLST       0x00000010
#define CAN_MOSTAT9_MSGVAL       0x00000020
#define CAN_MOSTAT9_NEWDAT       0x00000008
#define CAN_MOSTAT9_RTSEL        0x00000040
#define CAN_MOSTAT9_RXEN         0x00000080
#define CAN_MOSTAT9_RXPND        0x00000001
#define CAN_MOSTAT9_RXUPD        0x00000004
#define CAN_MOSTAT9_TXEN0        0x00000200
#define CAN_MOSTAT9_TXEN1        0x00000400
#define CAN_MOSTAT9_TXPND        0x00000002
#define CAN_MOSTAT9_TXRQ         0x00000100

// CAN Message Index Register 0
#define CAN_MSID0              (*((uword volatile *) 0xF0004180))

// CAN Message Index Register 1
#define CAN_MSID1              (*((uword volatile *) 0xF0004184))

// CAN Message Index Register 2
#define CAN_MSID2              (*((uword volatile *) 0xF0004188))

// CAN Message Index Register 3
#define CAN_MSID3              (*((uword volatile *) 0xF000418C))

// CAN Message Index Register 4
#define CAN_MSID4              (*((uword volatile *) 0xF0004190))

// CAN Message Index Register 5
#define CAN_MSID5              (*((uword volatile *) 0xF0004194))

// CAN Message Index Register 6
#define CAN_MSID6              (*((uword volatile *) 0xF0004198))

// CAN Message Index Register 7
#define CAN_MSID7              (*((uword volatile *) 0xF000419C))

// CAN Message Index Mask Register
#define CAN_MSIMASK            (*((uword volatile *) 0xF00041C0))

// CAN Message Pending Register 0
#define CAN_MSPND0             (*((uword volatile *) 0xF0004140))

// CAN Message Pending Register 1
#define CAN_MSPND1             (*((uword volatile *) 0xF0004144))

// CAN Message Pending Register 2
#define CAN_MSPND2             (*((uword volatile *) 0xF0004148))

// CAN Message Pending Register 3
#define CAN_MSPND3             (*((uword volatile *) 0xF000414C))

// CAN Message Pending Register 4
#define CAN_MSPND4             (*((uword volatile *) 0xF0004150))

// CAN Message Pending Register 5
#define CAN_MSPND5             (*((uword volatile *) 0xF0004154))

// CAN Message Pending Register 6
#define CAN_MSPND6             (*((uword volatile *) 0xF0004158))

// CAN Message Pending Register 7
#define CAN_MSPND7             (*((uword volatile *) 0xF000415C))

// CAN Node 0 Bit Timing Register
#define CAN_NBTR0              (*((uword volatile *) 0xF0004210))
#define CAN_NBTR0_DIV8           0x00008000

// CAN Node 1 Bit Timing Register
#define CAN_NBTR1              (*((uword volatile *) 0xF0004310))
#define CAN_NBTR1_DIV8           0x00008000

// CAN Node 2 Bit Timing Register
#define CAN_NBTR2              (*((uword volatile *) 0xF0004410))
#define CAN_NBTR2_DIV8           0x00008000

// CAN Node 0 Control Register
#define CAN_NCR0               (*((uword volatile *) 0xF0004200))
#define CAN_NCR0_ALIE            0x00000008
#define CAN_NCR0_CALM            0x00000080
#define CAN_NCR0_CANDIS          0x00000010
#define CAN_NCR0_CCE             0x00000040
#define CAN_NCR0_INIT            0x00000001
#define CAN_NCR0_LECIE           0x00000004
#define CAN_NCR0_SUSEN           0x00000100
#define CAN_NCR0_TRIE            0x00000002

// CAN Node 1 Control Register
#define CAN_NCR1               (*((uword volatile *) 0xF0004300))
#define CAN_NCR1_ALIE            0x00000008
#define CAN_NCR1_CALM            0x00000080
#define CAN_NCR1_CANDIS          0x00000010
#define CAN_NCR1_CCE             0x00000040
#define CAN_NCR1_INIT            0x00000001
#define CAN_NCR1_LECIE           0x00000004
#define CAN_NCR1_SUSEN           0x00000100
#define CAN_NCR1_TRIE            0x00000002

// CAN Node 2 Control Register
#define CAN_NCR2               (*((uword volatile *) 0xF0004400))
#define CAN_NCR2_ALIE            0x00000008
#define CAN_NCR2_CALM            0x00000080
#define CAN_NCR2_CANDIS          0x00000010
#define CAN_NCR2_CCE             0x00000040
#define CAN_NCR2_INIT            0x00000001
#define CAN_NCR2_LECIE           0x00000004
#define CAN_NCR2_SUSEN           0x00000100
#define CAN_NCR2_TRIE            0x00000002

// CAN Node 0 Error Counter Register
#define CAN_NECNT0             (*((uword volatile *) 0xF0004214))
#define CAN_NECNT0_LEINC         0x02000000
#define CAN_NECNT0_LETD          0x01000000

// CAN Node 1 Error Counter Register
#define CAN_NECNT1             (*((uword volatile *) 0xF0004314))
#define CAN_NECNT1_LEINC         0x02000000
#define CAN_NECNT1_LETD          0x01000000

// CAN Node 2 Error Counter Register
#define CAN_NECNT2             (*((uword volatile *) 0xF0004414))
#define CAN_NECNT2_LEINC         0x02000000
#define CAN_NECNT2_LETD          0x01000000

// CAN Node 0 Frame Counter Register
#define CAN_NFCR0              (*((uword volatile *) 0xF0004218))
#define CAN_NFCR0_CFCIE          0x00400000
#define CAN_NFCR0_CFCOV          0x00800000

// CAN Node 1 Frame Counter Register
#define CAN_NFCR1              (*((uword volatile *) 0xF0004318))
#define CAN_NFCR1_CFCIE          0x00400000
#define CAN_NFCR1_CFCOV          0x00800000

// CAN Node 2 Frame Counter Register
#define CAN_NFCR2              (*((uword volatile *) 0xF0004418))
#define CAN_NFCR2_CFCIE          0x00400000
#define CAN_NFCR2_CFCOV          0x00800000

// CAN Node 0 Interrupt Pointer Register
#define CAN_NIPR0              (*((uword volatile *) 0xF0004208))

// CAN Node 1 Interrupt Pointer Register
#define CAN_NIPR1              (*((uword volatile *) 0xF0004308))

// CAN Node 2 Interrupt Pointer Register
#define CAN_NIPR2              (*((uword volatile *) 0xF0004408))

// CAN Node 0 Port Control Register
#define CAN_NPCR0              (*((uword volatile *) 0xF000420C))
#define CAN_NPCR0_LBM            0x00000100

// CAN Node 1 Port Control Register
#define CAN_NPCR1              (*((uword volatile *) 0xF000430C))
#define CAN_NPCR1_LBM            0x00000100

// CAN Node 2 Port Control Register
#define CAN_NPCR2              (*((uword volatile *) 0xF000440C))
#define CAN_NPCR2_LBM            0x00000100

// CAN Node 0 Status Register
#define CAN_NSR0               (*((uword volatile *) 0xF0004204))
#define CAN_NSR0_ALERT           0x00000020
#define CAN_NSR0_BOFF            0x00000080
#define CAN_NSR0_EWRN            0x00000040
#define CAN_NSR0_LLE             0x00000100
#define CAN_NSR0_LOE             0x00000200
#define CAN_NSR0_RXOK            0x00000010
#define CAN_NSR0_SUSACK          0x00000400
#define CAN_NSR0_TXOK            0x00000008

// CAN Node 1 Status Register
#define CAN_NSR1               (*((uword volatile *) 0xF0004304))
#define CAN_NSR1_ALERT           0x00000020
#define CAN_NSR1_BOFF            0x00000080
#define CAN_NSR1_EWRN            0x00000040
#define CAN_NSR1_LLE             0x00000100
#define CAN_NSR1_LOE             0x00000200
#define CAN_NSR1_RXOK            0x00000010
#define CAN_NSR1_SUSACK          0x00000400
#define CAN_NSR1_TXOK            0x00000008

// CAN Node 2 Status Register
#define CAN_NSR2               (*((uword volatile *) 0xF0004404))
#define CAN_NSR2_ALERT           0x00000020
#define CAN_NSR2_BOFF            0x00000080
#define CAN_NSR2_EWRN            0x00000040
#define CAN_NSR2_LLE             0x00000100
#define CAN_NSR2_LOE             0x00000200
#define CAN_NSR2_RXOK            0x00000010
#define CAN_NSR2_SUSACK          0x00000400
#define CAN_NSR2_TXOK            0x00000008

// CAN Panel Control Register
#define CAN_PANCTR             (*((uword volatile *) 0xF00041C4))
#define CAN_PANCTR_BUSY          0x00000100
#define CAN_PANCTR_RBUSY         0x00000200

// CAN Service Request Control Register 0
#define CAN_SRC0               (*((uword volatile *) 0xF00040FC))
#define CAN_SRC0_CLRR            0x00004000
#define CAN_SRC0_SETR            0x00008000
#define CAN_SRC0_SRE             0x00001000
#define CAN_SRC0_SRR             0x00002000
#define CAN_SRC0_TOS             0x00000400

// CAN Service Request Control Register 1
#define CAN_SRC1               (*((uword volatile *) 0xF00040F8))
#define CAN_SRC1_CLRR            0x00004000
#define CAN_SRC1_SETR            0x00008000
#define CAN_SRC1_SRE             0x00001000
#define CAN_SRC1_SRR             0x00002000
#define CAN_SRC1_TOS             0x00000400

// CAN Service Request Control Register 10
#define CAN_SRC10              (*((uword volatile *) 0xF00040D4))
#define CAN_SRC10_CLRR           0x00004000
#define CAN_SRC10_SETR           0x00008000
#define CAN_SRC10_SRE            0x00001000
#define CAN_SRC10_SRR            0x00002000
#define CAN_SRC10_TOS            0x00000400

// CAN Service Request Control Register 11
#define CAN_SRC11              (*((uword volatile *) 0xF00040D0))
#define CAN_SRC11_CLRR           0x00004000
#define CAN_SRC11_SETR           0x00008000
#define CAN_SRC11_SRE            0x00001000
#define CAN_SRC11_SRR            0x00002000
#define CAN_SRC11_TOS            0x00000400

// CAN Service Request Control Register 12
#define CAN_SRC12              (*((uword volatile *) 0xF00040CC))
#define CAN_SRC12_CLRR           0x00004000
#define CAN_SRC12_SETR           0x00008000
#define CAN_SRC12_SRE            0x00001000
#define CAN_SRC12_SRR            0x00002000
#define CAN_SRC12_TOS            0x00000400

// CAN Service Request Control Register 13
#define CAN_SRC13              (*((uword volatile *) 0xF00040C8))
#define CAN_SRC13_CLRR           0x00004000
#define CAN_SRC13_SETR           0x00008000
#define CAN_SRC13_SRE            0x00001000
#define CAN_SRC13_SRR            0x00002000
#define CAN_SRC13_TOS            0x00000400

// CAN Service Request Control Register 14
#define CAN_SRC14              (*((uword volatile *) 0xF00040C4))
#define CAN_SRC14_CLRR           0x00004000
#define CAN_SRC14_SETR           0x00008000
#define CAN_SRC14_SRE            0x00001000
#define CAN_SRC14_SRR            0x00002000
#define CAN_SRC14_TOS            0x00000400

// CAN Service Request Control Register 15
#define CAN_SRC15              (*((uword volatile *) 0xF00040C0))
#define CAN_SRC15_CLRR           0x00004000
#define CAN_SRC15_SETR           0x00008000
#define CAN_SRC15_SRE            0x00001000
#define CAN_SRC15_SRR            0x00002000
#define CAN_SRC15_TOS            0x00000400

// CAN Service Request Control Register 2
#define CAN_SRC2               (*((uword volatile *) 0xF00040F4))
#define CAN_SRC2_CLRR            0x00004000
#define CAN_SRC2_SETR            0x00008000
#define CAN_SRC2_SRE             0x00001000
#define CAN_SRC2_SRR             0x00002000
#define CAN_SRC2_TOS             0x00000400

// CAN Service Request Control Register 3
#define CAN_SRC3               (*((uword volatile *) 0xF00040F0))
#define CAN_SRC3_CLRR            0x00004000
#define CAN_SRC3_SETR            0x00008000
#define CAN_SRC3_SRE             0x00001000
#define CAN_SRC3_SRR             0x00002000
#define CAN_SRC3_TOS             0x00000400

// CAN Service Request Control Register 4
#define CAN_SRC4               (*((uword volatile *) 0xF00040EC))
#define CAN_SRC4_CLRR            0x00004000
#define CAN_SRC4_SETR            0x00008000
#define CAN_SRC4_SRE             0x00001000
#define CAN_SRC4_SRR             0x00002000
#define CAN_SRC4_TOS             0x00000400

// CAN Service Request Control Register 5
#define CAN_SRC5               (*((uword volatile *) 0xF00040E8))
#define CAN_SRC5_CLRR            0x00004000
#define CAN_SRC5_SETR            0x00008000
#define CAN_SRC5_SRE             0x00001000
#define CAN_SRC5_SRR             0x00002000
#define CAN_SRC5_TOS             0x00000400

// CAN Service Request Control Register 6
#define CAN_SRC6               (*((uword volatile *) 0xF00040E4))
#define CAN_SRC6_CLRR            0x00004000
#define CAN_SRC6_SETR            0x00008000
#define CAN_SRC6_SRE             0x00001000
#define CAN_SRC6_SRR             0x00002000
#define CAN_SRC6_TOS             0x00000400

// CAN Service Request Control Register 7
#define CAN_SRC7               (*((uword volatile *) 0xF00040E0))
#define CAN_SRC7_CLRR            0x00004000
#define CAN_SRC7_SETR            0x00008000
#define CAN_SRC7_SRE             0x00001000
#define CAN_SRC7_SRR             0x00002000
#define CAN_SRC7_TOS             0x00000400

// CAN Service Request Control Register 8
#define CAN_SRC8               (*((uword volatile *) 0xF00040DC))
#define CAN_SRC8_CLRR            0x00004000
#define CAN_SRC8_SETR            0x00008000
#define CAN_SRC8_SRE             0x00001000
#define CAN_SRC8_SRR             0x00002000
#define CAN_SRC8_TOS             0x00000400

// CAN Service Request Control Register 9
#define CAN_SRC9               (*((uword volatile *) 0xF00040D8))
#define CAN_SRC9_CLRR            0x00004000
#define CAN_SRC9_SETR            0x00008000
#define CAN_SRC9_SRE             0x00001000
#define CAN_SRC9_SRR             0x00002000
#define CAN_SRC9_TOS             0x00000400

// Communication Mode Data Register
#define CBS_COMDATA            (*((uword volatile *) 0xF0000468))

// Internally Controlled Trace Source Register
#define CBS_ICTSA              (*((uword volatile *) 0xF0000488))

// Internally Controlled Trace Destination Register
#define CBS_ICTTA              (*((uword volatile *) 0xF000048C))

// Internal Mode Status and Control Register
#define CBS_INTMOD             (*((uword volatile *) 0xF0000484))
#define CBS_INTMOD_CHANNEL_P     ((T_Reg32 *) 0xF0000484)->bit4
#define CBS_INTMOD_CLR_CS        ((T_Reg32 *) 0xF0000484)->bit3
#define CBS_INTMOD_CLR_INT_TRC   ((T_Reg32 *) 0xF0000484)->bit19
#define CBS_INTMOD_INT_MOD       ((T_Reg32 *) 0xF0000484)->bit24
#define CBS_INTMOD_INT_TRC       ((T_Reg32 *) 0xF0000484)->bit25
#define CBS_INTMOD_SET_CRS       ((T_Reg32 *) 0xF0000484)->bit0
#define CBS_INTMOD_SET_CS        ((T_Reg32 *) 0xF0000484)->bit2
#define CBS_INTMOD_SET_CWS       ((T_Reg32 *) 0xF0000484)->bit1
#define CBS_INTMOD_SET_INT_MOD   ((T_Reg32 *) 0xF0000484)->bit16
#define CBS_INTMOD_SET_INT_TRC   ((T_Reg32 *) 0xF0000484)->bit18
#define CBS_INTMOD_TRC_MOD_P     ((T_Reg32 *) 0xF0000484)->bit20

// IOClient Status and Control Register
#define CBS_IOSR               (*((uword volatile *) 0xF000046C))
#define CBS_IOSR_COM_SYNC        ((T_Reg32 *) 0xF000046C)->bit7
#define CBS_IOSR_CRSYNC          ((T_Reg32 *) 0xF000046C)->bit4
#define CBS_IOSR_CWSYNC          ((T_Reg32 *) 0xF000046C)->bit5
#define CBS_IOSR_CW_ACK          ((T_Reg32 *) 0xF000046C)->bit6
#define CBS_IOSR_HOSTED          ((T_Reg32 *) 0xF000046C)->bit8

// JTAG Device Identification Register
#define CBS_JTAGID             (*((uword volatile *) 0xF0000464))

// Break Bus Switch Configuration Register
#define CBS_MCDBBS             (*((uword volatile *) 0xF0000470))
#define CBS_MCDBBS_BSDMA         ((T_Reg32 *) 0xF0000470)->bit1
#define CBS_MCDBBS_BSHLTEN       ((T_Reg32 *) 0xF0000470)->bit7
#define CBS_MCDBBS_BSML0         ((T_Reg32 *) 0xF0000470)->bit2
#define CBS_MCDBBS_BSML1         ((T_Reg32 *) 0xF0000470)->bit3
#define CBS_MCDBBS_BSP0          ((T_Reg32 *) 0xF0000470)->bit16
#define CBS_MCDBBS_BSP1          ((T_Reg32 *) 0xF0000470)->bit17
#define CBS_MCDBBS_BSPCP         ((T_Reg32 *) 0xF0000470)->bit4
#define CBS_MCDBBS_BSPCPEN       ((T_Reg32 *) 0xF0000470)->bit6
#define CBS_MCDBBS_BSSB          ((T_Reg32 *) 0xF0000470)->bit0
#define CBS_MCDBBS_BSTC          ((T_Reg32 *) 0xF0000470)->bit5
#define CBS_MCDBBS_BTMCD         ((T_Reg32 *) 0xF0000470)->bit8
#define CBS_MCDBBS_BTP0          ((T_Reg32 *) 0xF0000470)->bit18
#define CBS_MCDBBS_BTP1          ((T_Reg32 *) 0xF0000470)->bit19
#define CBS_MCDBBS_BTPCP         ((T_Reg32 *) 0xF0000470)->bit12
#define CBS_MCDBBS_BTPCPEN       ((T_Reg32 *) 0xF0000470)->bit14
#define CBS_MCDBBS_BTSS          ((T_Reg32 *) 0xF0000470)->bit23
#define CBS_MCDBBS_BTT           ((T_Reg32 *) 0xF0000470)->bit20
#define CBS_MCDBBS_BTTC          ((T_Reg32 *) 0xF0000470)->bit13
#define CBS_MCDBBS_BTTIEN        ((T_Reg32 *) 0xF0000470)->bit24

// Break Bus Switch Status Register
#define CBS_MCDBBSS            (*((uword volatile *) 0xF0000490))
#define CBS_MCDBBSS_BBC0         ((T_Reg32 *) 0xF0000490)->bit18
#define CBS_MCDBBSS_BBC1         ((T_Reg32 *) 0xF0000490)->bit19
#define CBS_MCDBBSS_BBS0         ((T_Reg32 *) 0xF0000490)->bit16
#define CBS_MCDBBSS_BBS1         ((T_Reg32 *) 0xF0000490)->bit17
#define CBS_MCDBBSS_BSCDMA       ((T_Reg32 *) 0xF0000490)->bit9
#define CBS_MCDBBSS_BSCML0       ((T_Reg32 *) 0xF0000490)->bit10
#define CBS_MCDBBSS_BSCML1       ((T_Reg32 *) 0xF0000490)->bit11
#define CBS_MCDBBSS_BSCPCP       ((T_Reg32 *) 0xF0000490)->bit12
#define CBS_MCDBBSS_BSCSB        ((T_Reg32 *) 0xF0000490)->bit8
#define CBS_MCDBBSS_BSCTC        ((T_Reg32 *) 0xF0000490)->bit13
#define CBS_MCDBBSS_BSSDMA       ((T_Reg32 *) 0xF0000490)->bit1
#define CBS_MCDBBSS_BSSML0       ((T_Reg32 *) 0xF0000490)->bit2
#define CBS_MCDBBSS_BSSML1       ((T_Reg32 *) 0xF0000490)->bit3
#define CBS_MCDBBSS_BSSPCP       ((T_Reg32 *) 0xF0000490)->bit4
#define CBS_MCDBBSS_BSSSB        ((T_Reg32 *) 0xF0000490)->bit0
#define CBS_MCDBBSS_BSSTC        ((T_Reg32 *) 0xF0000490)->bit5
#define CBS_MCDBBSS_CAPCLR       ((T_Reg32 *) 0xF0000490)->bit24

// Suspend Source Status and Control Register
#define CBS_MCDSSG             (*((uword volatile *) 0xF0000474))
#define CBS_MCDSSG_BTSCL         ((T_Reg32 *) 0xF0000474)->bit0
#define CBS_MCDSSG_BTSEN         ((T_Reg32 *) 0xF0000474)->bit9
#define CBS_MCDSSG_BTSM          ((T_Reg32 *) 0xF0000474)->bit10
#define CBS_MCDSSG_BTS_P         ((T_Reg32 *) 0xF0000474)->bit8
#define CBS_MCDSSG_SDS           ((T_Reg32 *) 0xF0000474)->bit25
#define CBS_MCDSSG_SOS           ((T_Reg32 *) 0xF0000474)->bit24
#define CBS_MCDSSG_SSSBRK        ((T_Reg32 *) 0xF0000474)->bit22
#define CBS_MCDSSG_SSSMCD        ((T_Reg32 *) 0xF0000474)->bit19
#define CBS_MCDSSG_SSSSCU        ((T_Reg32 *) 0xF0000474)->bit18
#define CBS_MCDSSG_SSSTC         ((T_Reg32 *) 0xF0000474)->bit16
#define CBS_MCDSSG_SUS           ((T_Reg32 *) 0xF0000474)->bit7
#define CBS_MCDSSG_SUS_P         ((T_Reg32 *) 0xF0000474)->bit6

// Suspend Signal Target Control Register
#define CBS_MCDSSGC            (*((uword volatile *) 0xF0000494))
#define CBS_MCDSSGC_STCDMA       ((T_Reg32 *) 0xF0000494)->bit4
#define CBS_MCDSSGC_STCM         ((T_Reg32 *) 0xF0000494)->bit1
#define CBS_MCDSSGC_STCPCP       ((T_Reg32 *) 0xF0000494)->bit3
#define CBS_MCDSSGC_STCTC        ((T_Reg32 *) 0xF0000494)->bit2
#define CBS_MCDSSGC_STC_P        ((T_Reg32 *) 0xF0000494)->bit0

// OSCU Control Register
#define CBS_OCNTRL             (*((uword volatile *) 0xF000047C))
#define CBS_OCNTRL_OC0           ((T_Reg32 *) 0xF000047C)->bit1
#define CBS_OCNTRL_OC0_P         ((T_Reg32 *) 0xF000047C)->bit0
#define CBS_OCNTRL_OC1           ((T_Reg32 *) 0xF000047C)->bit3
#define CBS_OCNTRL_OC1_P         ((T_Reg32 *) 0xF000047C)->bit2
#define CBS_OCNTRL_OC2           ((T_Reg32 *) 0xF000047C)->bit5
#define CBS_OCNTRL_OC2_P         ((T_Reg32 *) 0xF000047C)->bit4
#define CBS_OCNTRL_OC3           ((T_Reg32 *) 0xF000047C)->bit7
#define CBS_OCNTRL_OC3_P         ((T_Reg32 *) 0xF000047C)->bit6
#define CBS_OCNTRL_OC4           ((T_Reg32 *) 0xF000047C)->bit9
#define CBS_OCNTRL_OC4_P         ((T_Reg32 *) 0xF000047C)->bit8
#define CBS_OCNTRL_OC5           ((T_Reg32 *) 0xF000047C)->bit11
#define CBS_OCNTRL_OC5_P         ((T_Reg32 *) 0xF000047C)->bit10
#define CBS_OCNTRL_OJC0          ((T_Reg32 *) 0xF000047C)->bit17
#define CBS_OCNTRL_OJC0_P        ((T_Reg32 *) 0xF000047C)->bit16
#define CBS_OCNTRL_OJC1          ((T_Reg32 *) 0xF000047C)->bit19
#define CBS_OCNTRL_OJC1_P        ((T_Reg32 *) 0xF000047C)->bit18
#define CBS_OCNTRL_OJC2          ((T_Reg32 *) 0xF000047C)->bit21
#define CBS_OCNTRL_OJC2_P        ((T_Reg32 *) 0xF000047C)->bit20
#define CBS_OCNTRL_OJC3          ((T_Reg32 *) 0xF000047C)->bit23
#define CBS_OCNTRL_OJC3_P        ((T_Reg32 *) 0xF000047C)->bit22
#define CBS_OCNTRL_OJC4          ((T_Reg32 *) 0xF000047C)->bit25
#define CBS_OCNTRL_OJC4_P        ((T_Reg32 *) 0xF000047C)->bit24
#define CBS_OCNTRL_OJC5          ((T_Reg32 *) 0xF000047C)->bit27
#define CBS_OCNTRL_OJC5_P        ((T_Reg32 *) 0xF000047C)->bit26
#define CBS_OCNTRL_OJC6          ((T_Reg32 *) 0xF000047C)->bit29
#define CBS_OCNTRL_OJC6_P        ((T_Reg32 *) 0xF000047C)->bit28
#define CBS_OCNTRL_OJC7          ((T_Reg32 *) 0xF000047C)->bit31
#define CBS_OCNTRL_OJC7_P        ((T_Reg32 *) 0xF000047C)->bit30
#define CBS_OCNTRL_STABLE        ((T_Reg32 *) 0xF000047C)->bit15
#define CBS_OCNTRL_STABLE_P      ((T_Reg32 *) 0xF000047C)->bit14
#define CBS_OCNTRL_WDTSUS        ((T_Reg32 *) 0xF000047C)->bit13
#define CBS_OCNTRL_WDTSUS_P      ((T_Reg32 *) 0xF000047C)->bit12

// OCDS Enable Control Register
#define CBS_OEC                (*((uword volatile *) 0xF0000478))
#define CBS_OEC_AUT_OK           ((T_Reg32 *) 0xF0000478)->bit19
#define CBS_OEC_AUT_OK_P         ((T_Reg32 *) 0xF0000478)->bit18
#define CBS_OEC_DS               ((T_Reg32 *) 0xF0000478)->bit8
#define CBS_OEC_IF_LCK           ((T_Reg32 *) 0xF0000478)->bit17
#define CBS_OEC_IF_LCK_P         ((T_Reg32 *) 0xF0000478)->bit16

// OSCU Status Register
#define CBS_OSTATE             (*((uword volatile *) 0xF0000480))
#define CBS_OSTATE_AUT_OK        ((T_Reg32 *) 0xF0000480)->bit17
#define CBS_OSTATE_DAPRST        ((T_Reg32 *) 0xF0000480)->bit3
#define CBS_OSTATE_EECDIS        ((T_Reg32 *) 0xF0000480)->bit6
#define CBS_OSTATE_EECTRC        ((T_Reg32 *) 0xF0000480)->bit5
#define CBS_OSTATE_ENIDIS        ((T_Reg32 *) 0xF0000480)->bit4
#define CBS_OSTATE_HARR          ((T_Reg32 *) 0xF0000480)->bit8
#define CBS_OSTATE_IF_LCK        ((T_Reg32 *) 0xF0000480)->bit16
#define CBS_OSTATE_OEN           ((T_Reg32 *) 0xF0000480)->bit0
#define CBS_OSTATE_OJC1          ((T_Reg32 *) 0xF0000480)->bit9
#define CBS_OSTATE_OJC2          ((T_Reg32 *) 0xF0000480)->bit10
#define CBS_OSTATE_OJC3          ((T_Reg32 *) 0xF0000480)->bit11
#define CBS_OSTATE_RSTCL0        ((T_Reg32 *) 0xF0000480)->bit12
#define CBS_OSTATE_RSTCL1        ((T_Reg32 *) 0xF0000480)->bit13
#define CBS_OSTATE_RSTCL3        ((T_Reg32 *) 0xF0000480)->bit15
#define CBS_OSTATE_STABLE        ((T_Reg32 *) 0xF0000480)->bit18
#define CBS_OSTATE_WDTSUS        ((T_Reg32 *) 0xF0000480)->bit7

// Service Request Node1 Control Register
#define CBS_SRC0               (*((uword volatile *) 0xF00004FC))
#define CBS_SRC0_CLRR            ((T_Reg32 *) 0xF00004FC)->bit14
#define CBS_SRC0_SETR            ((T_Reg32 *) 0xF00004FC)->bit15
#define CBS_SRC0_SRE             ((T_Reg32 *) 0xF00004FC)->bit12
#define CBS_SRC0_SRR             ((T_Reg32 *) 0xF00004FC)->bit13

// Service Request Node2 Control Register
#define CBS_SRC1               (*((uword volatile *) 0xF00004F8))
#define CBS_SRC1_CLRR            ((T_Reg32 *) 0xF00004F8)->bit14
#define CBS_SRC1_SETR            ((T_Reg32 *) 0xF00004F8)->bit15
#define CBS_SRC1_SRE             ((T_Reg32 *) 0xF00004F8)->bit12
#define CBS_SRC1_SRR             ((T_Reg32 *) 0xF00004F8)->bit13

// Trigger to Host Register
#define CBS_TRIG               (*((uword volatile *) 0xF00004A8))
#define CBS_TRIG_TRG0            ((T_Reg32 *) 0xF00004A8)->bit0
#define CBS_TRIG_TRG1            ((T_Reg32 *) 0xF00004A8)->bit1
#define CBS_TRIG_TRG10           ((T_Reg32 *) 0xF00004A8)->bit10
#define CBS_TRIG_TRG11           ((T_Reg32 *) 0xF00004A8)->bit11
#define CBS_TRIG_TRG12           ((T_Reg32 *) 0xF00004A8)->bit12
#define CBS_TRIG_TRG13           ((T_Reg32 *) 0xF00004A8)->bit13
#define CBS_TRIG_TRG14           ((T_Reg32 *) 0xF00004A8)->bit14
#define CBS_TRIG_TRG15           ((T_Reg32 *) 0xF00004A8)->bit15
#define CBS_TRIG_TRG16           ((T_Reg32 *) 0xF00004A8)->bit16
#define CBS_TRIG_TRG17           ((T_Reg32 *) 0xF00004A8)->bit17
#define CBS_TRIG_TRG18           ((T_Reg32 *) 0xF00004A8)->bit18
#define CBS_TRIG_TRG19           ((T_Reg32 *) 0xF00004A8)->bit19
#define CBS_TRIG_TRG2            ((T_Reg32 *) 0xF00004A8)->bit2
#define CBS_TRIG_TRG20           ((T_Reg32 *) 0xF00004A8)->bit20
#define CBS_TRIG_TRG21           ((T_Reg32 *) 0xF00004A8)->bit21
#define CBS_TRIG_TRG22           ((T_Reg32 *) 0xF00004A8)->bit22
#define CBS_TRIG_TRG23           ((T_Reg32 *) 0xF00004A8)->bit23
#define CBS_TRIG_TRG24           ((T_Reg32 *) 0xF00004A8)->bit24
#define CBS_TRIG_TRG25           ((T_Reg32 *) 0xF00004A8)->bit25
#define CBS_TRIG_TRG26           ((T_Reg32 *) 0xF00004A8)->bit26
#define CBS_TRIG_TRG27           ((T_Reg32 *) 0xF00004A8)->bit27
#define CBS_TRIG_TRG28           ((T_Reg32 *) 0xF00004A8)->bit28
#define CBS_TRIG_TRG29           ((T_Reg32 *) 0xF00004A8)->bit29
#define CBS_TRIG_TRG3            ((T_Reg32 *) 0xF00004A8)->bit3
#define CBS_TRIG_TRG30           ((T_Reg32 *) 0xF00004A8)->bit30
#define CBS_TRIG_TRG31           ((T_Reg32 *) 0xF00004A8)->bit31
#define CBS_TRIG_TRG4            ((T_Reg32 *) 0xF00004A8)->bit4
#define CBS_TRIG_TRG5            ((T_Reg32 *) 0xF00004A8)->bit5
#define CBS_TRIG_TRG6            ((T_Reg32 *) 0xF00004A8)->bit6
#define CBS_TRIG_TRG7            ((T_Reg32 *) 0xF00004A8)->bit7
#define CBS_TRIG_TRG8            ((T_Reg32 *) 0xF00004A8)->bit8
#define CBS_TRIG_TRG9            ((T_Reg32 *) 0xF00004A8)->bit9

// Clear Trigger to Host Register
#define CBS_TRIGC              (*((uword volatile *) 0xF00004A4))
#define CBS_TRIGC_TRG0           ((T_Reg32 *) 0xF00004A4)->bit0
#define CBS_TRIGC_TRG1           ((T_Reg32 *) 0xF00004A4)->bit1
#define CBS_TRIGC_TRG10          ((T_Reg32 *) 0xF00004A4)->bit10
#define CBS_TRIGC_TRG11          ((T_Reg32 *) 0xF00004A4)->bit11
#define CBS_TRIGC_TRG12          ((T_Reg32 *) 0xF00004A4)->bit12
#define CBS_TRIGC_TRG13          ((T_Reg32 *) 0xF00004A4)->bit13
#define CBS_TRIGC_TRG14          ((T_Reg32 *) 0xF00004A4)->bit14
#define CBS_TRIGC_TRG15          ((T_Reg32 *) 0xF00004A4)->bit15
#define CBS_TRIGC_TRG16          ((T_Reg32 *) 0xF00004A4)->bit16
#define CBS_TRIGC_TRG17          ((T_Reg32 *) 0xF00004A4)->bit17
#define CBS_TRIGC_TRG18          ((T_Reg32 *) 0xF00004A4)->bit18
#define CBS_TRIGC_TRG19          ((T_Reg32 *) 0xF00004A4)->bit19
#define CBS_TRIGC_TRG2           ((T_Reg32 *) 0xF00004A4)->bit2
#define CBS_TRIGC_TRG20          ((T_Reg32 *) 0xF00004A4)->bit20
#define CBS_TRIGC_TRG21          ((T_Reg32 *) 0xF00004A4)->bit21
#define CBS_TRIGC_TRG22          ((T_Reg32 *) 0xF00004A4)->bit22
#define CBS_TRIGC_TRG23          ((T_Reg32 *) 0xF00004A4)->bit23
#define CBS_TRIGC_TRG24          ((T_Reg32 *) 0xF00004A4)->bit24
#define CBS_TRIGC_TRG25          ((T_Reg32 *) 0xF00004A4)->bit25
#define CBS_TRIGC_TRG26          ((T_Reg32 *) 0xF00004A4)->bit26
#define CBS_TRIGC_TRG27          ((T_Reg32 *) 0xF00004A4)->bit27
#define CBS_TRIGC_TRG28          ((T_Reg32 *) 0xF00004A4)->bit28
#define CBS_TRIGC_TRG29          ((T_Reg32 *) 0xF00004A4)->bit29
#define CBS_TRIGC_TRG3           ((T_Reg32 *) 0xF00004A4)->bit3
#define CBS_TRIGC_TRG30          ((T_Reg32 *) 0xF00004A4)->bit30
#define CBS_TRIGC_TRG31          ((T_Reg32 *) 0xF00004A4)->bit31
#define CBS_TRIGC_TRG4           ((T_Reg32 *) 0xF00004A4)->bit4
#define CBS_TRIGC_TRG5           ((T_Reg32 *) 0xF00004A4)->bit5
#define CBS_TRIGC_TRG6           ((T_Reg32 *) 0xF00004A4)->bit6
#define CBS_TRIGC_TRG7           ((T_Reg32 *) 0xF00004A4)->bit7
#define CBS_TRIGC_TRG8           ((T_Reg32 *) 0xF00004A4)->bit8
#define CBS_TRIGC_TRG9           ((T_Reg32 *) 0xF00004A4)->bit9

// Set Trigger to Host Register
#define CBS_TRIGS              (*((uword volatile *) 0xF00004A0))
#define CBS_TRIGS_TRG0           ((T_Reg32 *) 0xF00004A0)->bit0
#define CBS_TRIGS_TRG1           ((T_Reg32 *) 0xF00004A0)->bit1
#define CBS_TRIGS_TRG10          ((T_Reg32 *) 0xF00004A0)->bit10
#define CBS_TRIGS_TRG11          ((T_Reg32 *) 0xF00004A0)->bit11
#define CBS_TRIGS_TRG12          ((T_Reg32 *) 0xF00004A0)->bit12
#define CBS_TRIGS_TRG13          ((T_Reg32 *) 0xF00004A0)->bit13
#define CBS_TRIGS_TRG14          ((T_Reg32 *) 0xF00004A0)->bit14
#define CBS_TRIGS_TRG15          ((T_Reg32 *) 0xF00004A0)->bit15
#define CBS_TRIGS_TRG16          ((T_Reg32 *) 0xF00004A0)->bit16
#define CBS_TRIGS_TRG17          ((T_Reg32 *) 0xF00004A0)->bit17
#define CBS_TRIGS_TRG18          ((T_Reg32 *) 0xF00004A0)->bit18
#define CBS_TRIGS_TRG19          ((T_Reg32 *) 0xF00004A0)->bit19
#define CBS_TRIGS_TRG2           ((T_Reg32 *) 0xF00004A0)->bit2
#define CBS_TRIGS_TRG20          ((T_Reg32 *) 0xF00004A0)->bit20
#define CBS_TRIGS_TRG21          ((T_Reg32 *) 0xF00004A0)->bit21
#define CBS_TRIGS_TRG22          ((T_Reg32 *) 0xF00004A0)->bit22
#define CBS_TRIGS_TRG23          ((T_Reg32 *) 0xF00004A0)->bit23
#define CBS_TRIGS_TRG24          ((T_Reg32 *) 0xF00004A0)->bit24
#define CBS_TRIGS_TRG25          ((T_Reg32 *) 0xF00004A0)->bit25
#define CBS_TRIGS_TRG26          ((T_Reg32 *) 0xF00004A0)->bit26
#define CBS_TRIGS_TRG27          ((T_Reg32 *) 0xF00004A0)->bit27
#define CBS_TRIGS_TRG28          ((T_Reg32 *) 0xF00004A0)->bit28
#define CBS_TRIGS_TRG29          ((T_Reg32 *) 0xF00004A0)->bit29
#define CBS_TRIGS_TRG3           ((T_Reg32 *) 0xF00004A0)->bit3
#define CBS_TRIGS_TRG30          ((T_Reg32 *) 0xF00004A0)->bit30
#define CBS_TRIGS_TRG31          ((T_Reg32 *) 0xF00004A0)->bit31
#define CBS_TRIGS_TRG4           ((T_Reg32 *) 0xF00004A0)->bit4
#define CBS_TRIGS_TRG5           ((T_Reg32 *) 0xF00004A0)->bit5
#define CBS_TRIGS_TRG6           ((T_Reg32 *) 0xF00004A0)->bit6
#define CBS_TRIGS_TRG7           ((T_Reg32 *) 0xF00004A0)->bit7
#define CBS_TRIGS_TRG8           ((T_Reg32 *) 0xF00004A0)->bit8
#define CBS_TRIGS_TRG9           ((T_Reg32 *) 0xF00004A0)->bit9

// Count of Corrected Data Integrity Errors Register
#define CCDIER                 (*((uword volatile *) 0xF7E19028))

// CPU Clock Count Register
#define CCNT                   (*((uword volatile *) 0xF7E1FC04))
#define CCNT_SOVF                0x80000000

// Count of Corrected Program Integrity Errors Register
#define CCPIER                 (*((uword volatile *) 0xF7E19218))

// Counter Control Register
#define CCTRL                  (*((uword volatile *) 0xF7E1FC00))
#define CCTRL_CE                 0x00000002
#define CCTRL_CM                 0x00000001

// Compatibility Control Register
#define COMPAT                 (*((uword volatile *) 0xF7E19400))
#define COMPAT_BP                0x00000004
#define COMPAT_DIE               0x00000002
#define COMPAT_PIE               0x00000001
#define COMPAT_RM                0x00000008

// Code Protection Mode Register Set 0
#define CPM0                   (*((uword volatile *) 0xF7E1E200))
#define CPM0_BL0                 0x00000008
#define CPM0_BL1                 0x00000800
#define CPM0_BL2                 0x00080000
#define CPM0_BL3                 0x08000000
#define CPM0_BU0                 0x00000001
#define CPM0_BU1                 0x00000100
#define CPM0_BU2                 0x00010000
#define CPM0_BU3                 0x01000000
#define CPM0_XE0                 0x00000080
#define CPM0_XE1                 0x00008000
#define CPM0_XE2                 0x00800000
#define CPM0_XE3                 0x80000000
#define CPM0_XS0                 0x00000020
#define CPM0_XS1                 0x00002000
#define CPM0_XS2                 0x00200000
#define CPM0_XS3                 0x20000000

// Code Protection Mode Register Set 1
#define CPM1                   (*((uword volatile *) 0xF7E1E280))
#define CPM1_BL0                 0x00000008
#define CPM1_BL1                 0x00000800
#define CPM1_BL2                 0x00080000
#define CPM1_BL3                 0x08000000
#define CPM1_BU0                 0x00000001
#define CPM1_BU1                 0x00000100
#define CPM1_BU2                 0x00010000
#define CPM1_BU3                 0x01000000
#define CPM1_XE0                 0x00000080
#define CPM1_XE1                 0x00008000
#define CPM1_XE2                 0x00800000
#define CPM1_XE3                 0x80000000
#define CPM1_XS0                 0x00000020
#define CPM1_XS1                 0x00002000
#define CPM1_XS2                 0x00200000
#define CPM1_XS3                 0x20000000

// Code Protection Mode Register Set 2
#define CPM2                   (*((uword volatile *) 0xF7E1E300))
#define CPM2_BL0                 0x00000008
#define CPM2_BL1                 0x00000800
#define CPM2_BL2                 0x00080000
#define CPM2_BL3                 0x08000000
#define CPM2_BU0                 0x00000001
#define CPM2_BU1                 0x00000100
#define CPM2_BU2                 0x00010000
#define CPM2_BU3                 0x01000000
#define CPM2_XE0                 0x00000080
#define CPM2_XE1                 0x00008000
#define CPM2_XE2                 0x00800000
#define CPM2_XE3                 0x80000000
#define CPM2_XS0                 0x00000020
#define CPM2_XS1                 0x00002000
#define CPM2_XS2                 0x00200000
#define CPM2_XS3                 0x20000000

// Code Protection Mode Register Set 3
#define CPM3                   (*((uword volatile *) 0xF7E1E380))
#define CPM3_BL0                 0x00000008
#define CPM3_BL1                 0x00000800
#define CPM3_BL2                 0x00080000
#define CPM3_BL3                 0x08000000
#define CPM3_BU0                 0x00000001
#define CPM3_BU1                 0x00000100
#define CPM3_BU2                 0x00010000
#define CPM3_BU3                 0x01000000
#define CPM3_XE0                 0x00000080
#define CPM3_XE1                 0x00008000
#define CPM3_XE2                 0x00800000
#define CPM3_XE3                 0x80000000
#define CPM3_XS0                 0x00000020
#define CPM3_XS1                 0x00002000
#define CPM3_XS2                 0x00200000
#define CPM3_XS3                 0x20000000

// Code Segment Protection Register Set 0, Range 0, Lower Boundary
#define CPR0_0L                (*((uword volatile *) 0xF7E1D000))

// Code Segment Protection Register Set 0, Range 0, Upper Boundary
#define CPR0_0U                (*((uword volatile *) 0xF7E1D004))

// Code Segment Protection Register Set 0, Range 1, Lower Boundary
#define CPR0_1L                (*((uword volatile *) 0xF7E1D008))

// Code Segment Protection Register Set 0, Range 1, Upper Boundary
#define CPR0_1U                (*((uword volatile *) 0xF7E1D00C))

// Code Segment Protection Register Set 1, Range 0, Lower Boundary
#define CPR1_0L                (*((uword volatile *) 0xF7E1D400))

// Code Segment Protection Register Set 1, Range 0, Upper Boundary
#define CPR1_0U                (*((uword volatile *) 0xF7E1D404))

// Code Segment Protection Register Set 1, Range 1, Lower Boundary
#define CPR1_1L                (*((uword volatile *) 0xF7E1D408))

// Code Segment Protection Register Set 1, Range 1, Upper Boundary
#define CPR1_1U                (*((uword volatile *) 0xF7E1D40C))

// Code Segment Protection Register Set 2, Range 0, Lower Boundary
#define CPR2_0L                (*((uword volatile *) 0xF7E1D800))

// Code Segment Protection Register Set 2, Range 0, Upper Boundary
#define CPR2_0U                (*((uword volatile *) 0xF7E1D804))

// Code Segment Protection Register Set 2, Range 1, Lower Boundary
#define CPR2_1L                (*((uword volatile *) 0xF7E1D808))

// Code Segment Protection Register Set 2, Range 1, Upper Boundary
#define CPR2_1U                (*((uword volatile *) 0xF7E1D80C))

// Code Segment Protection Register Set 3, Range 0, Lower Boundary
#define CPR3_0L                (*((uword volatile *) 0xF7E1DC00))

// Code Segment Protection Register Set 3, Range 0, Upper Boundary
#define CPR3_0U                (*((uword volatile *) 0xF7E1DC04))

// Code Segment Protection Register Set 3, Range 1, Lower Boundary
#define CPR3_1L                (*((uword volatile *) 0xF7E1DC08))

// Code Segment Protection Register Set 3, Range 1, Upper Boundary
#define CPR3_1U                (*((uword volatile *) 0xF7E1DC0C))

// CPS Module Identification Register
#define CPS_ID                 (*((uword volatile *) 0xF7E0FF08))

// CPU Identification Register
#define CPU_ID                 (*((uword volatile *) 0xF7E1FE18))

// CPU Software Breakpoint Service Request Control Register
#define CPU_SBSRC              (*((uword volatile *) 0xF7E0FFBC))
#define CPU_SBSRC_CLRR           0x00004000
#define CPU_SBSRC_SETR           0x00008000
#define CPU_SBSRC_SRE            0x00001000
#define CPU_SBSRC_SRR            0x00002000
#define CPU_SBSRC_TOS            0x00000400

// CPU Service Request Control Register 0
#define CPU_SRC0               (*((uword volatile *) 0xF7E0FFFC))
#define CPU_SRC0_CLRR            0x00004000
#define CPU_SRC0_SETR            0x00008000
#define CPU_SRC0_SRE             0x00001000
#define CPU_SRC0_SRR             0x00002000
#define CPU_SRC0_TOS             0x00000400

// CPU Service Request Control Register 1
#define CPU_SRC1               (*((uword volatile *) 0xF7E0FFF8))
#define CPU_SRC1_CLRR            0x00004000
#define CPU_SRC1_SETR            0x00008000
#define CPU_SRC1_SRE             0x00001000
#define CPU_SRC1_SRR             0x00002000
#define CPU_SRC1_TOS             0x00000400

// CPU Service Request Control Register 2
#define CPU_SRC2               (*((uword volatile *) 0xF7E0FFF4))
#define CPU_SRC2_CLRR            0x00004000
#define CPU_SRC2_SETR            0x00008000
#define CPU_SRC2_SRE             0x00001000
#define CPU_SRC2_SRR             0x00002000
#define CPU_SRC2_TOS             0x00000400

// CPU Service Request Control Register 3
#define CPU_SRC3               (*((uword volatile *) 0xF7E0FFF0))
#define CPU_SRC3_CLRR            0x00004000
#define CPU_SRC3_SETR            0x00008000
#define CPU_SRC3_SRE             0x00001000
#define CPU_SRC3_SRR             0x00002000
#define CPU_SRC3_TOS             0x00000400

// Core SFR Access Break Event Specifier Register
#define CREVT                  (*((uword volatile *) 0xF7E1FD0C))
#define CREVT_BBM                0x00000008
#define CREVT_BOD                0x00000010
#define CREVT_CSP                0x00000080
#define CREVT_CST                0x00000040
#define CREVT_SUSP               0x00000020

// Data Register 0
#define D0                     (*((uword volatile *) 0xF7E1FF00))

// Data Register 1
#define D1                     (*((uword volatile *) 0xF7E1FF04))

// Data Register 10
#define D10                    (*((uword volatile *) 0xF7E1FF28))

// Data Register 11
#define D11                    (*((uword volatile *) 0xF7E1FF2C))

// Data Register 12
#define D12                    (*((uword volatile *) 0xF7E1FF30))

// Data Register 13
#define D13                    (*((uword volatile *) 0xF7E1FF34))

// Data Register 14
#define D14                    (*((uword volatile *) 0xF7E1FF38))

// Data Register 15
#define D15                    (*((uword volatile *) 0xF7E1FF3C))

// Data Register 2
#define D2                     (*((uword volatile *) 0xF7E1FF08))

// Data Register 3
#define D3                     (*((uword volatile *) 0xF7E1FF0C))

// Data Register 4
#define D4                     (*((uword volatile *) 0xF7E1FF10))

// Data Register 5
#define D5                     (*((uword volatile *) 0xF7E1FF14))

// Data Register 6
#define D6                     (*((uword volatile *) 0xF7E1FF18))

// Data Register 7
#define D7                     (*((uword volatile *) 0xF7E1FF1C))

// Data Register 8
#define D8                     (*((uword volatile *) 0xF7E1FF20))

// Data Register 9
#define D9                     (*((uword volatile *) 0xF7E1FF24))

// Debug Status Register
#define DBGSR                  (*((uword volatile *) 0xF7E1FD00))
#define DBGSR_DE                 0x00000001
#define DBGSR_PEVT               0x00000080
#define DBGSR_PREVSUSP           0x00000040
#define DBGSR_SIH                0x00000008
#define DBGSR_SUSP               0x00000010

// Debug Trap Control Register
#define DBGTCR                 (*((uword volatile *) 0xF7E1FD48))
#define DBGTCR_DTA               0x00000001

// Debug Context Save Area Pointer Register
#define DCX                    (*((uword volatile *) 0xF7E1FD44))

// Data Integrity Error Address Register
#define DIEAR                  (*((uword volatile *) 0xF7E19020))

// Data Integrity Error Trap Register
#define DIETR                  (*((uword volatile *) 0xF7E19024))
#define DIETR_IE_B               0x00000010
#define DIETR_IE_C               0x00000004
#define DIETR_IE_S               0x00000008
#define DIETR_IE_T               0x00000002
#define DIETR_IED                0x00000001
#define DIETR_TRTYP              0x00000200

// DMA Channel 00 Address Control Register
#define DMA_ADRCR00            (*((uword volatile *) 0xF0003C8C))
#define DMA_ADRCR00_INCD         ((T_Reg32 *) 0xF0003C8C)->bit7
#define DMA_ADRCR00_INCS         ((T_Reg32 *) 0xF0003C8C)->bit3
#define DMA_ADRCR00_SHWEN        ((T_Reg32 *) 0xF0003C8C)->bit18

// DMA Channel 01 Address Control Register
#define DMA_ADRCR01            (*((uword volatile *) 0xF0003CAC))
#define DMA_ADRCR01_INCD         ((T_Reg32 *) 0xF0003CAC)->bit7
#define DMA_ADRCR01_INCS         ((T_Reg32 *) 0xF0003CAC)->bit3
#define DMA_ADRCR01_SHWEN        ((T_Reg32 *) 0xF0003CAC)->bit18

// DMA Channel 02 Address Control Register
#define DMA_ADRCR02            (*((uword volatile *) 0xF0003CCC))
#define DMA_ADRCR02_INCD         ((T_Reg32 *) 0xF0003CCC)->bit7
#define DMA_ADRCR02_INCS         ((T_Reg32 *) 0xF0003CCC)->bit3
#define DMA_ADRCR02_SHWEN        ((T_Reg32 *) 0xF0003CCC)->bit18

// DMA Channel 03 Address Control Register
#define DMA_ADRCR03            (*((uword volatile *) 0xF0003CEC))
#define DMA_ADRCR03_INCD         ((T_Reg32 *) 0xF0003CEC)->bit7
#define DMA_ADRCR03_INCS         ((T_Reg32 *) 0xF0003CEC)->bit3
#define DMA_ADRCR03_SHWEN        ((T_Reg32 *) 0xF0003CEC)->bit18

// DMA Channel 04 Address Control Register
#define DMA_ADRCR04            (*((uword volatile *) 0xF0003D0C))
#define DMA_ADRCR04_INCD         ((T_Reg32 *) 0xF0003D0C)->bit7
#define DMA_ADRCR04_INCS         ((T_Reg32 *) 0xF0003D0C)->bit3
#define DMA_ADRCR04_SHWEN        ((T_Reg32 *) 0xF0003D0C)->bit18

// DMA Channel 05 Address Control Register
#define DMA_ADRCR05            (*((uword volatile *) 0xF0003D2C))
#define DMA_ADRCR05_INCD         ((T_Reg32 *) 0xF0003D2C)->bit7
#define DMA_ADRCR05_INCS         ((T_Reg32 *) 0xF0003D2C)->bit3
#define DMA_ADRCR05_SHWEN        ((T_Reg32 *) 0xF0003D2C)->bit18

// DMA Channel 06 Address Control Register
#define DMA_ADRCR06            (*((uword volatile *) 0xF0003D4C))
#define DMA_ADRCR06_INCD         ((T_Reg32 *) 0xF0003D4C)->bit7
#define DMA_ADRCR06_INCS         ((T_Reg32 *) 0xF0003D4C)->bit3
#define DMA_ADRCR06_SHWEN        ((T_Reg32 *) 0xF0003D4C)->bit18

// DMA Channel 07 Address Control Register
#define DMA_ADRCR07            (*((uword volatile *) 0xF0003D6C))
#define DMA_ADRCR07_INCD         ((T_Reg32 *) 0xF0003D6C)->bit7
#define DMA_ADRCR07_INCS         ((T_Reg32 *) 0xF0003D6C)->bit3
#define DMA_ADRCR07_SHWEN        ((T_Reg32 *) 0xF0003D6C)->bit18

// DMA Channel 00 Control Register
#define DMA_CHCR00             (*((uword volatile *) 0xF0003C84))
#define DMA_CHCR00_CHMODE        ((T_Reg32 *) 0xF0003C84)->bit20
#define DMA_CHCR00_CHPRIO        ((T_Reg32 *) 0xF0003C84)->bit28
#define DMA_CHCR00_RROAT         ((T_Reg32 *) 0xF0003C84)->bit19

// DMA Channel 01 Control Register
#define DMA_CHCR01             (*((uword volatile *) 0xF0003CA4))
#define DMA_CHCR01_CHMODE        ((T_Reg32 *) 0xF0003CA4)->bit20
#define DMA_CHCR01_CHPRIO        ((T_Reg32 *) 0xF0003CA4)->bit28
#define DMA_CHCR01_RROAT         ((T_Reg32 *) 0xF0003CA4)->bit19

// DMA Channel 02 Control Register
#define DMA_CHCR02             (*((uword volatile *) 0xF0003CC4))
#define DMA_CHCR02_CHMODE        ((T_Reg32 *) 0xF0003CC4)->bit20
#define DMA_CHCR02_CHPRIO        ((T_Reg32 *) 0xF0003CC4)->bit28
#define DMA_CHCR02_RROAT         ((T_Reg32 *) 0xF0003CC4)->bit19

// DMA Channel 03 Control Register
#define DMA_CHCR03             (*((uword volatile *) 0xF0003CE4))
#define DMA_CHCR03_CHMODE        ((T_Reg32 *) 0xF0003CE4)->bit20
#define DMA_CHCR03_CHPRIO        ((T_Reg32 *) 0xF0003CE4)->bit28
#define DMA_CHCR03_RROAT         ((T_Reg32 *) 0xF0003CE4)->bit19

// DMA Channel 04 Control Register
#define DMA_CHCR04             (*((uword volatile *) 0xF0003D04))
#define DMA_CHCR04_CHMODE        ((T_Reg32 *) 0xF0003D04)->bit20
#define DMA_CHCR04_CHPRIO        ((T_Reg32 *) 0xF0003D04)->bit28
#define DMA_CHCR04_RROAT         ((T_Reg32 *) 0xF0003D04)->bit19

// DMA Channel 05 Control Register
#define DMA_CHCR05             (*((uword volatile *) 0xF0003D24))
#define DMA_CHCR05_CHMODE        ((T_Reg32 *) 0xF0003D24)->bit20
#define DMA_CHCR05_CHPRIO        ((T_Reg32 *) 0xF0003D24)->bit28
#define DMA_CHCR05_RROAT         ((T_Reg32 *) 0xF0003D24)->bit19

// DMA Channel 06 Control Register
#define DMA_CHCR06             (*((uword volatile *) 0xF0003D44))
#define DMA_CHCR06_CHMODE        ((T_Reg32 *) 0xF0003D44)->bit20
#define DMA_CHCR06_CHPRIO        ((T_Reg32 *) 0xF0003D44)->bit28
#define DMA_CHCR06_RROAT         ((T_Reg32 *) 0xF0003D44)->bit19

// DMA Channel 07 Control Register
#define DMA_CHCR07             (*((uword volatile *) 0xF0003D64))
#define DMA_CHCR07_CHMODE        ((T_Reg32 *) 0xF0003D64)->bit20
#define DMA_CHCR07_CHPRIO        ((T_Reg32 *) 0xF0003D64)->bit28
#define DMA_CHCR07_RROAT         ((T_Reg32 *) 0xF0003D64)->bit19

// DMA Channel 00 Interrupt Control Register
#define DMA_CHICR00            (*((uword volatile *) 0xF0003C88))
#define DMA_CHICR00_WRPDE        ((T_Reg32 *) 0xF0003C88)->bit1
#define DMA_CHICR00_WRPSE        ((T_Reg32 *) 0xF0003C88)->bit0

// DMA Channel 01 Interrupt Control Register
#define DMA_CHICR01            (*((uword volatile *) 0xF0003CA8))
#define DMA_CHICR01_WRPDE        ((T_Reg32 *) 0xF0003CA8)->bit1
#define DMA_CHICR01_WRPSE        ((T_Reg32 *) 0xF0003CA8)->bit0

// DMA Channel 02 Interrupt Control Register
#define DMA_CHICR02            (*((uword volatile *) 0xF0003CC8))
#define DMA_CHICR02_WRPDE        ((T_Reg32 *) 0xF0003CC8)->bit1
#define DMA_CHICR02_WRPSE        ((T_Reg32 *) 0xF0003CC8)->bit0

// DMA Channel 03 Interrupt Control Register
#define DMA_CHICR03            (*((uword volatile *) 0xF0003CE8))
#define DMA_CHICR03_WRPDE        ((T_Reg32 *) 0xF0003CE8)->bit1
#define DMA_CHICR03_WRPSE        ((T_Reg32 *) 0xF0003CE8)->bit0

// DMA Channel 04 Interrupt Control Register
#define DMA_CHICR04            (*((uword volatile *) 0xF0003D08))
#define DMA_CHICR04_WRPDE        ((T_Reg32 *) 0xF0003D08)->bit1
#define DMA_CHICR04_WRPSE        ((T_Reg32 *) 0xF0003D08)->bit0

// DMA Channel 05 Interrupt Control Register
#define DMA_CHICR05            (*((uword volatile *) 0xF0003D28))
#define DMA_CHICR05_WRPDE        ((T_Reg32 *) 0xF0003D28)->bit1
#define DMA_CHICR05_WRPSE        ((T_Reg32 *) 0xF0003D28)->bit0

// DMA Channel 06 Interrupt Control Register
#define DMA_CHICR06            (*((uword volatile *) 0xF0003D48))
#define DMA_CHICR06_WRPDE        ((T_Reg32 *) 0xF0003D48)->bit1
#define DMA_CHICR06_WRPSE        ((T_Reg32 *) 0xF0003D48)->bit0

// DMA Channel 07 Interrupt Control Register
#define DMA_CHICR07            (*((uword volatile *) 0xF0003D68))
#define DMA_CHICR07_WRPDE        ((T_Reg32 *) 0xF0003D68)->bit1
#define DMA_CHICR07_WRPSE        ((T_Reg32 *) 0xF0003D68)->bit0

// DMA Channel Reset Request Register
#define DMA_CHRSTR             (*((uword volatile *) 0xF0003C10))
#define DMA_CHRSTR_CH00          ((T_Reg32 *) 0xF0003C10)->bit0
#define DMA_CHRSTR_CH01          ((T_Reg32 *) 0xF0003C10)->bit1
#define DMA_CHRSTR_CH02          ((T_Reg32 *) 0xF0003C10)->bit2
#define DMA_CHRSTR_CH03          ((T_Reg32 *) 0xF0003C10)->bit3
#define DMA_CHRSTR_CH04          ((T_Reg32 *) 0xF0003C10)->bit4
#define DMA_CHRSTR_CH05          ((T_Reg32 *) 0xF0003C10)->bit5
#define DMA_CHRSTR_CH06          ((T_Reg32 *) 0xF0003C10)->bit6
#define DMA_CHRSTR_CH07          ((T_Reg32 *) 0xF0003C10)->bit7

// DMA Channel 00 Status Register
#define DMA_CHSR00             (*((uword volatile *) 0xF0003C80))
#define DMA_CHSR00_LXO           ((T_Reg32 *) 0xF0003C80)->bit15

// DMA Channel 01 Status Register
#define DMA_CHSR01             (*((uword volatile *) 0xF0003CA0))
#define DMA_CHSR01_LXO           ((T_Reg32 *) 0xF0003CA0)->bit15

// DMA Channel 02 Status Register
#define DMA_CHSR02             (*((uword volatile *) 0xF0003CC0))
#define DMA_CHSR02_LXO           ((T_Reg32 *) 0xF0003CC0)->bit15

// DMA Channel 03 Status Register
#define DMA_CHSR03             (*((uword volatile *) 0xF0003CE0))
#define DMA_CHSR03_LXO           ((T_Reg32 *) 0xF0003CE0)->bit15

// DMA Channel 04 Status Register
#define DMA_CHSR04             (*((uword volatile *) 0xF0003D00))
#define DMA_CHSR04_LXO           ((T_Reg32 *) 0xF0003D00)->bit15

// DMA Channel 05 Status Register
#define DMA_CHSR05             (*((uword volatile *) 0xF0003D20))
#define DMA_CHSR05_LXO           ((T_Reg32 *) 0xF0003D20)->bit15

// DMA Channel 06 Status Register
#define DMA_CHSR06             (*((uword volatile *) 0xF0003D40))
#define DMA_CHSR06_LXO           ((T_Reg32 *) 0xF0003D40)->bit15

// DMA Channel 07 Status Register
#define DMA_CHSR07             (*((uword volatile *) 0xF0003D60))
#define DMA_CHSR07_LXO           ((T_Reg32 *) 0xF0003D60)->bit15

// DMA Clock Control Register
#define DMA_CLC                (*((uword volatile *) 0xF0003C00))
#define DMA_CLC_DISR             ((T_Reg32 *) 0xF0003C00)->bit0
#define DMA_CLC_DISS             ((T_Reg32 *) 0xF0003C00)->bit1
#define DMA_CLC_ONE              ((T_Reg32 *) 0xF0003C00)->bit3
#define DMA_CLC_SBWE             ((T_Reg32 *) 0xF0003C00)->bit4
#define DMA_CLC_SPEN             ((T_Reg32 *) 0xF0003C00)->bit2

// DMA Clear Error Register
#define DMA_CLRE               (*((uword volatile *) 0xF0003C28))
#define DMA_CLRE_CFPIER          ((T_Reg32 *) 0xF0003C28)->bit20
#define DMA_CLRE_CLCERBERUS      ((T_Reg32 *) 0xF0003C28)->bit22
#define DMA_CLRE_CLMBER          ((T_Reg32 *) 0xF0003C28)->bit21
#define DMA_CLRE_CLRMLI0         ((T_Reg32 *) 0xF0003C28)->bit27
#define DMA_CLRE_CME0DER         ((T_Reg32 *) 0xF0003C28)->bit17
#define DMA_CLRE_CME0SER         ((T_Reg32 *) 0xF0003C28)->bit16
#define DMA_CLRE_CTL00           ((T_Reg32 *) 0xF0003C28)->bit0
#define DMA_CLRE_CTL01           ((T_Reg32 *) 0xF0003C28)->bit1
#define DMA_CLRE_CTL02           ((T_Reg32 *) 0xF0003C28)->bit2
#define DMA_CLRE_CTL03           ((T_Reg32 *) 0xF0003C28)->bit3
#define DMA_CLRE_CTL04           ((T_Reg32 *) 0xF0003C28)->bit4
#define DMA_CLRE_CTL05           ((T_Reg32 *) 0xF0003C28)->bit5
#define DMA_CLRE_CTL06           ((T_Reg32 *) 0xF0003C28)->bit6
#define DMA_CLRE_CTL07           ((T_Reg32 *) 0xF0003C28)->bit7

// DMA Channel 00 Destination Address Register
#define DMA_DADR00             (*((uword volatile *) 0xF0003C94))

// DMA Channel 01 Destination Address Register
#define DMA_DADR01             (*((uword volatile *) 0xF0003CB4))

// DMA Channel 02 Destination Address Register
#define DMA_DADR02             (*((uword volatile *) 0xF0003CD4))

// DMA Channel 03 Destination Address Register
#define DMA_DADR03             (*((uword volatile *) 0xF0003CF4))

// DMA Channel 04 Destination Address Register
#define DMA_DADR04             (*((uword volatile *) 0xF0003D14))

// DMA Channel 05 Destination Address Register
#define DMA_DADR05             (*((uword volatile *) 0xF0003D34))

// DMA Channel 06 Destination Address Register
#define DMA_DADR06             (*((uword volatile *) 0xF0003D54))

// DMA Channel 07 Destination Address Register
#define DMA_DADR07             (*((uword volatile *) 0xF0003D74))

// DMA Enable Error Register
#define DMA_EER                (*((uword volatile *) 0xF0003C20))
#define DMA_EER_EME0DER          ((T_Reg32 *) 0xF0003C20)->bit17
#define DMA_EER_EME0SER          ((T_Reg32 *) 0xF0003C20)->bit16
#define DMA_EER_ETRL00           ((T_Reg32 *) 0xF0003C20)->bit0
#define DMA_EER_ETRL01           ((T_Reg32 *) 0xF0003C20)->bit1
#define DMA_EER_ETRL02           ((T_Reg32 *) 0xF0003C20)->bit2
#define DMA_EER_ETRL03           ((T_Reg32 *) 0xF0003C20)->bit3
#define DMA_EER_ETRL04           ((T_Reg32 *) 0xF0003C20)->bit4
#define DMA_EER_ETRL05           ((T_Reg32 *) 0xF0003C20)->bit5
#define DMA_EER_ETRL06           ((T_Reg32 *) 0xF0003C20)->bit6
#define DMA_EER_ETRL07           ((T_Reg32 *) 0xF0003C20)->bit7

// DMA Error Status Register
#define DMA_ERRSR              (*((uword volatile *) 0xF0003C24))
#define DMA_ERRSR_CERBERUSER     ((T_Reg32 *) 0xF0003C24)->bit22
#define DMA_ERRSR_FPIER          ((T_Reg32 *) 0xF0003C24)->bit20
#define DMA_ERRSR_LMBER          ((T_Reg32 *) 0xF0003C24)->bit21
#define DMA_ERRSR_ME0DER         ((T_Reg32 *) 0xF0003C24)->bit17
#define DMA_ERRSR_ME0SER         ((T_Reg32 *) 0xF0003C24)->bit16
#define DMA_ERRSR_MLI0           ((T_Reg32 *) 0xF0003C24)->bit27
#define DMA_ERRSR_TRL00          ((T_Reg32 *) 0xF0003C24)->bit0
#define DMA_ERRSR_TRL01          ((T_Reg32 *) 0xF0003C24)->bit1
#define DMA_ERRSR_TRL02          ((T_Reg32 *) 0xF0003C24)->bit2
#define DMA_ERRSR_TRL03          ((T_Reg32 *) 0xF0003C24)->bit3
#define DMA_ERRSR_TRL04          ((T_Reg32 *) 0xF0003C24)->bit4
#define DMA_ERRSR_TRL05          ((T_Reg32 *) 0xF0003C24)->bit5
#define DMA_ERRSR_TRL06          ((T_Reg32 *) 0xF0003C24)->bit6
#define DMA_ERRSR_TRL07          ((T_Reg32 *) 0xF0003C24)->bit7

// DMA Global Interrupt Set Register
#define DMA_GINTR              (*((uword volatile *) 0xF0003C2C))
#define DMA_GINTR_SIDMA0         ((T_Reg32 *) 0xF0003C2C)->bit0
#define DMA_GINTR_SIDMA1         ((T_Reg32 *) 0xF0003C2C)->bit1
#define DMA_GINTR_SIDMA10        ((T_Reg32 *) 0xF0003C2C)->bit10
#define DMA_GINTR_SIDMA11        ((T_Reg32 *) 0xF0003C2C)->bit11
#define DMA_GINTR_SIDMA12        ((T_Reg32 *) 0xF0003C2C)->bit12
#define DMA_GINTR_SIDMA13        ((T_Reg32 *) 0xF0003C2C)->bit13
#define DMA_GINTR_SIDMA14        ((T_Reg32 *) 0xF0003C2C)->bit14
#define DMA_GINTR_SIDMA15        ((T_Reg32 *) 0xF0003C2C)->bit15
#define DMA_GINTR_SIDMA2         ((T_Reg32 *) 0xF0003C2C)->bit2
#define DMA_GINTR_SIDMA3         ((T_Reg32 *) 0xF0003C2C)->bit3
#define DMA_GINTR_SIDMA4         ((T_Reg32 *) 0xF0003C2C)->bit4
#define DMA_GINTR_SIDMA5         ((T_Reg32 *) 0xF0003C2C)->bit5
#define DMA_GINTR_SIDMA6         ((T_Reg32 *) 0xF0003C2C)->bit6
#define DMA_GINTR_SIDMA7         ((T_Reg32 *) 0xF0003C2C)->bit7
#define DMA_GINTR_SIDMA8         ((T_Reg32 *) 0xF0003C2C)->bit8
#define DMA_GINTR_SIDMA9         ((T_Reg32 *) 0xF0003C2C)->bit9

// DMA Hardware Transaction Request Register
#define DMA_HTREQ              (*((uword volatile *) 0xF0003C1C))
#define DMA_HTREQ_DCH00          ((T_Reg32 *) 0xF0003C1C)->bit16
#define DMA_HTREQ_DCH01          ((T_Reg32 *) 0xF0003C1C)->bit17
#define DMA_HTREQ_DCH02          ((T_Reg32 *) 0xF0003C1C)->bit18
#define DMA_HTREQ_DCH03          ((T_Reg32 *) 0xF0003C1C)->bit19
#define DMA_HTREQ_DCH04          ((T_Reg32 *) 0xF0003C1C)->bit20
#define DMA_HTREQ_DCH05          ((T_Reg32 *) 0xF0003C1C)->bit21
#define DMA_HTREQ_DCH06          ((T_Reg32 *) 0xF0003C1C)->bit22
#define DMA_HTREQ_DCH07          ((T_Reg32 *) 0xF0003C1C)->bit23
#define DMA_HTREQ_ECH00          ((T_Reg32 *) 0xF0003C1C)->bit0
#define DMA_HTREQ_ECH01          ((T_Reg32 *) 0xF0003C1C)->bit1
#define DMA_HTREQ_ECH02          ((T_Reg32 *) 0xF0003C1C)->bit2
#define DMA_HTREQ_ECH03          ((T_Reg32 *) 0xF0003C1C)->bit3
#define DMA_HTREQ_ECH04          ((T_Reg32 *) 0xF0003C1C)->bit4
#define DMA_HTREQ_ECH05          ((T_Reg32 *) 0xF0003C1C)->bit5
#define DMA_HTREQ_ECH06          ((T_Reg32 *) 0xF0003C1C)->bit6
#define DMA_HTREQ_ECH07          ((T_Reg32 *) 0xF0003C1C)->bit7

// Module Identification Register
#define DMA_ID                 (*((uword volatile *) 0xF0003C08))

// DMA Interrupt Clear Register
#define DMA_INTCR              (*((uword volatile *) 0xF0003C58))
#define DMA_INTCR_CICH00         ((T_Reg32 *) 0xF0003C58)->bit0
#define DMA_INTCR_CICH01         ((T_Reg32 *) 0xF0003C58)->bit1
#define DMA_INTCR_CICH02         ((T_Reg32 *) 0xF0003C58)->bit2
#define DMA_INTCR_CICH03         ((T_Reg32 *) 0xF0003C58)->bit3
#define DMA_INTCR_CICH04         ((T_Reg32 *) 0xF0003C58)->bit4
#define DMA_INTCR_CICH05         ((T_Reg32 *) 0xF0003C58)->bit5
#define DMA_INTCR_CICH06         ((T_Reg32 *) 0xF0003C58)->bit6
#define DMA_INTCR_CICH07         ((T_Reg32 *) 0xF0003C58)->bit7
#define DMA_INTCR_CWRP00         ((T_Reg32 *) 0xF0003C58)->bit16
#define DMA_INTCR_CWRP01         ((T_Reg32 *) 0xF0003C58)->bit17
#define DMA_INTCR_CWRP02         ((T_Reg32 *) 0xF0003C58)->bit18
#define DMA_INTCR_CWRP03         ((T_Reg32 *) 0xF0003C58)->bit19
#define DMA_INTCR_CWRP04         ((T_Reg32 *) 0xF0003C58)->bit20
#define DMA_INTCR_CWRP05         ((T_Reg32 *) 0xF0003C58)->bit21
#define DMA_INTCR_CWRP06         ((T_Reg32 *) 0xF0003C58)->bit22
#define DMA_INTCR_CWRP07         ((T_Reg32 *) 0xF0003C58)->bit23

// DMA Interrupt Status Register
#define DMA_INTSR              (*((uword volatile *) 0xF0003C54))
#define DMA_INTSR_ICH00          ((T_Reg32 *) 0xF0003C54)->bit0
#define DMA_INTSR_ICH01          ((T_Reg32 *) 0xF0003C54)->bit1
#define DMA_INTSR_ICH02          ((T_Reg32 *) 0xF0003C54)->bit2
#define DMA_INTSR_ICH03          ((T_Reg32 *) 0xF0003C54)->bit3
#define DMA_INTSR_ICH04          ((T_Reg32 *) 0xF0003C54)->bit4
#define DMA_INTSR_ICH05          ((T_Reg32 *) 0xF0003C54)->bit5
#define DMA_INTSR_ICH06          ((T_Reg32 *) 0xF0003C54)->bit6
#define DMA_INTSR_ICH07          ((T_Reg32 *) 0xF0003C54)->bit7
#define DMA_INTSR_IPM00          ((T_Reg32 *) 0xF0003C54)->bit16
#define DMA_INTSR_IPM01          ((T_Reg32 *) 0xF0003C54)->bit17
#define DMA_INTSR_IPM02          ((T_Reg32 *) 0xF0003C54)->bit18
#define DMA_INTSR_IPM03          ((T_Reg32 *) 0xF0003C54)->bit19
#define DMA_INTSR_IPM04          ((T_Reg32 *) 0xF0003C54)->bit20
#define DMA_INTSR_IPM05          ((T_Reg32 *) 0xF0003C54)->bit21
#define DMA_INTSR_IPM06          ((T_Reg32 *) 0xF0003C54)->bit22
#define DMA_INTSR_IPM07          ((T_Reg32 *) 0xF0003C54)->bit23

// DMA Move Engine 0 Access Enable Register
#define DMA_ME0AENR            (*((uword volatile *) 0xF0003C44))
#define DMA_ME0AENR_AEN0         ((T_Reg32 *) 0xF0003C44)->bit0
#define DMA_ME0AENR_AEN1         ((T_Reg32 *) 0xF0003C44)->bit1
#define DMA_ME0AENR_AEN10        ((T_Reg32 *) 0xF0003C44)->bit10
#define DMA_ME0AENR_AEN11        ((T_Reg32 *) 0xF0003C44)->bit11
#define DMA_ME0AENR_AEN12        ((T_Reg32 *) 0xF0003C44)->bit12
#define DMA_ME0AENR_AEN13        ((T_Reg32 *) 0xF0003C44)->bit13
#define DMA_ME0AENR_AEN14        ((T_Reg32 *) 0xF0003C44)->bit14
#define DMA_ME0AENR_AEN15        ((T_Reg32 *) 0xF0003C44)->bit15
#define DMA_ME0AENR_AEN16        ((T_Reg32 *) 0xF0003C44)->bit16
#define DMA_ME0AENR_AEN17        ((T_Reg32 *) 0xF0003C44)->bit17
#define DMA_ME0AENR_AEN18        ((T_Reg32 *) 0xF0003C44)->bit18
#define DMA_ME0AENR_AEN19        ((T_Reg32 *) 0xF0003C44)->bit19
#define DMA_ME0AENR_AEN2         ((T_Reg32 *) 0xF0003C44)->bit2
#define DMA_ME0AENR_AEN20        ((T_Reg32 *) 0xF0003C44)->bit20
#define DMA_ME0AENR_AEN21        ((T_Reg32 *) 0xF0003C44)->bit21
#define DMA_ME0AENR_AEN22        ((T_Reg32 *) 0xF0003C44)->bit22
#define DMA_ME0AENR_AEN23        ((T_Reg32 *) 0xF0003C44)->bit23
#define DMA_ME0AENR_AEN24        ((T_Reg32 *) 0xF0003C44)->bit24
#define DMA_ME0AENR_AEN25        ((T_Reg32 *) 0xF0003C44)->bit25
#define DMA_ME0AENR_AEN26        ((T_Reg32 *) 0xF0003C44)->bit26
#define DMA_ME0AENR_AEN27        ((T_Reg32 *) 0xF0003C44)->bit27
#define DMA_ME0AENR_AEN28        ((T_Reg32 *) 0xF0003C44)->bit28
#define DMA_ME0AENR_AEN29        ((T_Reg32 *) 0xF0003C44)->bit29
#define DMA_ME0AENR_AEN3         ((T_Reg32 *) 0xF0003C44)->bit3
#define DMA_ME0AENR_AEN30        ((T_Reg32 *) 0xF0003C44)->bit30
#define DMA_ME0AENR_AEN31        ((T_Reg32 *) 0xF0003C44)->bit31
#define DMA_ME0AENR_AEN4         ((T_Reg32 *) 0xF0003C44)->bit4
#define DMA_ME0AENR_AEN5         ((T_Reg32 *) 0xF0003C44)->bit5
#define DMA_ME0AENR_AEN6         ((T_Reg32 *) 0xF0003C44)->bit6
#define DMA_ME0AENR_AEN7         ((T_Reg32 *) 0xF0003C44)->bit7
#define DMA_ME0AENR_AEN8         ((T_Reg32 *) 0xF0003C44)->bit8
#define DMA_ME0AENR_AEN9         ((T_Reg32 *) 0xF0003C44)->bit9

// DMA Move Engine 0 Access Range Register
#define DMA_ME0ARR             (*((uword volatile *) 0xF0003C48))

// DMA Move Engine 0 Pattern Register
#define DMA_ME0PR              (*((uword volatile *) 0xF0003C3C))

// DMA Move Engine 0 Read Register
#define DMA_ME0R               (*((uword volatile *) 0xF0003C34))

// DMA Move Engine Status Register
#define DMA_MESR               (*((uword volatile *) 0xF0003C30))
#define DMA_MESR_ME0RS           ((T_Reg32 *) 0xF0003C30)->bit0
#define DMA_MESR_ME0WS           ((T_Reg32 *) 0xF0003C30)->bit4

// DMA MLI0 Service Request Control Register 0
#define DMA_MLI0SRC0           (*((uword volatile *) 0xF0003EAC))
#define DMA_MLI0SRC0_CLRR        ((T_Reg32 *) 0xF0003EAC)->bit14
#define DMA_MLI0SRC0_SETR        ((T_Reg32 *) 0xF0003EAC)->bit15
#define DMA_MLI0SRC0_SRE         ((T_Reg32 *) 0xF0003EAC)->bit12
#define DMA_MLI0SRC0_SRR         ((T_Reg32 *) 0xF0003EAC)->bit13
#define DMA_MLI0SRC0_TOS         ((T_Reg32 *) 0xF0003EAC)->bit10

// DMA MLI0 Service Request Control Register 1
#define DMA_MLI0SRC1           (*((uword volatile *) 0xF0003EA8))
#define DMA_MLI0SRC1_CLRR        ((T_Reg32 *) 0xF0003EA8)->bit14
#define DMA_MLI0SRC1_SETR        ((T_Reg32 *) 0xF0003EA8)->bit15
#define DMA_MLI0SRC1_SRE         ((T_Reg32 *) 0xF0003EA8)->bit12
#define DMA_MLI0SRC1_SRR         ((T_Reg32 *) 0xF0003EA8)->bit13
#define DMA_MLI0SRC1_TOS         ((T_Reg32 *) 0xF0003EA8)->bit10

// DMA MLI0 Service Request Control Register 2
#define DMA_MLI0SRC2           (*((uword volatile *) 0xF0003EA4))
#define DMA_MLI0SRC2_CLRR        ((T_Reg32 *) 0xF0003EA4)->bit14
#define DMA_MLI0SRC2_SETR        ((T_Reg32 *) 0xF0003EA4)->bit15
#define DMA_MLI0SRC2_SRE         ((T_Reg32 *) 0xF0003EA4)->bit12
#define DMA_MLI0SRC2_SRR         ((T_Reg32 *) 0xF0003EA4)->bit13
#define DMA_MLI0SRC2_TOS         ((T_Reg32 *) 0xF0003EA4)->bit10

// DMA MLI0 Service Request Control Register 3
#define DMA_MLI0SRC3           (*((uword volatile *) 0xF0003EA0))
#define DMA_MLI0SRC3_CLRR        ((T_Reg32 *) 0xF0003EA0)->bit14
#define DMA_MLI0SRC3_SETR        ((T_Reg32 *) 0xF0003EA0)->bit15
#define DMA_MLI0SRC3_SRE         ((T_Reg32 *) 0xF0003EA0)->bit12
#define DMA_MLI0SRC3_SRR         ((T_Reg32 *) 0xF0003EA0)->bit13
#define DMA_MLI0SRC3_TOS         ((T_Reg32 *) 0xF0003EA0)->bit10

// DMA OCDS Register
#define DMA_OCDSR              (*((uword volatile *) 0xF0003C64))
#define DMA_OCDSR_BRL0           ((T_Reg32 *) 0xF0003C64)->bit5

// DMA Channel 00 Source Address Register
#define DMA_SADR00             (*((uword volatile *) 0xF0003C90))

// DMA Channel 01 Source Address Register
#define DMA_SADR01             (*((uword volatile *) 0xF0003CB0))

// DMA Channel 02 Source Address Register
#define DMA_SADR02             (*((uword volatile *) 0xF0003CD0))

// DMA Channel 03 Source Address Register
#define DMA_SADR03             (*((uword volatile *) 0xF0003CF0))

// DMA Channel 04 Source Address Register
#define DMA_SADR04             (*((uword volatile *) 0xF0003D10))

// DMA Channel 05 Source Address Register
#define DMA_SADR05             (*((uword volatile *) 0xF0003D30))

// DMA Channel 06 Source Address Register
#define DMA_SADR06             (*((uword volatile *) 0xF0003D50))

// DMA Channel 07 Source Address Register
#define DMA_SADR07             (*((uword volatile *) 0xF0003D70))

// DMA Channel 00 Shadow Address Register
#define DMA_SHADR00            (*((uword volatile *) 0xF0003C98))

// DMA Channel 01 Shadow Address Register
#define DMA_SHADR01            (*((uword volatile *) 0xF0003CB8))

// DMA Channel 02 Shadow Address Register
#define DMA_SHADR02            (*((uword volatile *) 0xF0003CD8))

// DMA Channel 03 Shadow Address Register
#define DMA_SHADR03            (*((uword volatile *) 0xF0003CF8))

// DMA Channel 04 Shadow Address Register
#define DMA_SHADR04            (*((uword volatile *) 0xF0003D18))

// DMA Channel 05 Shadow Address Register
#define DMA_SHADR05            (*((uword volatile *) 0xF0003D38))

// DMA Channel 06 Shadow Address Register
#define DMA_SHADR06            (*((uword volatile *) 0xF0003D58))

// DMA Channel 07 Shadow Address Register
#define DMA_SHADR07            (*((uword volatile *) 0xF0003D78))

// DMA Service Request Control Register 0
#define DMA_SRC0               (*((uword volatile *) 0xF0003EFC))
#define DMA_SRC0_CLRR            ((T_Reg32 *) 0xF0003EFC)->bit14
#define DMA_SRC0_SETR            ((T_Reg32 *) 0xF0003EFC)->bit15
#define DMA_SRC0_SRE             ((T_Reg32 *) 0xF0003EFC)->bit12
#define DMA_SRC0_SRR             ((T_Reg32 *) 0xF0003EFC)->bit13
#define DMA_SRC0_TOS             ((T_Reg32 *) 0xF0003EFC)->bit10

// DMA Service Request Control Register 1
#define DMA_SRC1               (*((uword volatile *) 0xF0003EF8))
#define DMA_SRC1_CLRR            ((T_Reg32 *) 0xF0003EF8)->bit14
#define DMA_SRC1_SETR            ((T_Reg32 *) 0xF0003EF8)->bit15
#define DMA_SRC1_SRE             ((T_Reg32 *) 0xF0003EF8)->bit12
#define DMA_SRC1_SRR             ((T_Reg32 *) 0xF0003EF8)->bit13
#define DMA_SRC1_TOS             ((T_Reg32 *) 0xF0003EF8)->bit10

// DMA Service Request Control Register 2
#define DMA_SRC2               (*((uword volatile *) 0xF0003EF4))
#define DMA_SRC2_CLRR            ((T_Reg32 *) 0xF0003EF4)->bit14
#define DMA_SRC2_SETR            ((T_Reg32 *) 0xF0003EF4)->bit15
#define DMA_SRC2_SRE             ((T_Reg32 *) 0xF0003EF4)->bit12
#define DMA_SRC2_SRR             ((T_Reg32 *) 0xF0003EF4)->bit13
#define DMA_SRC2_TOS             ((T_Reg32 *) 0xF0003EF4)->bit10

// DMA Service Request Control Register 3
#define DMA_SRC3               (*((uword volatile *) 0xF0003EF0))
#define DMA_SRC3_CLRR            ((T_Reg32 *) 0xF0003EF0)->bit14
#define DMA_SRC3_SETR            ((T_Reg32 *) 0xF0003EF0)->bit15
#define DMA_SRC3_SRE             ((T_Reg32 *) 0xF0003EF0)->bit12
#define DMA_SRC3_SRR             ((T_Reg32 *) 0xF0003EF0)->bit13
#define DMA_SRC3_TOS             ((T_Reg32 *) 0xF0003EF0)->bit10

// DMA Service Request Control Register 4
#define DMA_SRC4               (*((uword volatile *) 0xF0003EEC))
#define DMA_SRC4_CLRR            ((T_Reg32 *) 0xF0003EEC)->bit14
#define DMA_SRC4_SETR            ((T_Reg32 *) 0xF0003EEC)->bit15
#define DMA_SRC4_SRE             ((T_Reg32 *) 0xF0003EEC)->bit12
#define DMA_SRC4_SRR             ((T_Reg32 *) 0xF0003EEC)->bit13
#define DMA_SRC4_TOS             ((T_Reg32 *) 0xF0003EEC)->bit10

// DMA Service Request Control Register 5
#define DMA_SRC5               (*((uword volatile *) 0xF0003EE8))
#define DMA_SRC5_CLRR            ((T_Reg32 *) 0xF0003EE8)->bit14
#define DMA_SRC5_SETR            ((T_Reg32 *) 0xF0003EE8)->bit15
#define DMA_SRC5_SRE             ((T_Reg32 *) 0xF0003EE8)->bit12
#define DMA_SRC5_SRR             ((T_Reg32 *) 0xF0003EE8)->bit13
#define DMA_SRC5_TOS             ((T_Reg32 *) 0xF0003EE8)->bit10

// DMA Service Request Control Register 6
#define DMA_SRC6               (*((uword volatile *) 0xF0003EE4))
#define DMA_SRC6_CLRR            ((T_Reg32 *) 0xF0003EE4)->bit14
#define DMA_SRC6_SETR            ((T_Reg32 *) 0xF0003EE4)->bit15
#define DMA_SRC6_SRE             ((T_Reg32 *) 0xF0003EE4)->bit12
#define DMA_SRC6_SRR             ((T_Reg32 *) 0xF0003EE4)->bit13
#define DMA_SRC6_TOS             ((T_Reg32 *) 0xF0003EE4)->bit10

// DMA Service Request Control Register 7
#define DMA_SRC7               (*((uword volatile *) 0xF0003EE0))
#define DMA_SRC7_CLRR            ((T_Reg32 *) 0xF0003EE0)->bit14
#define DMA_SRC7_SETR            ((T_Reg32 *) 0xF0003EE0)->bit15
#define DMA_SRC7_SRE             ((T_Reg32 *) 0xF0003EE0)->bit12
#define DMA_SRC7_SRR             ((T_Reg32 *) 0xF0003EE0)->bit13
#define DMA_SRC7_TOS             ((T_Reg32 *) 0xF0003EE0)->bit10

// DMA Software Transaction Request Register
#define DMA_STREQ              (*((uword volatile *) 0xF0003C18))
#define DMA_STREQ_SCH00          ((T_Reg32 *) 0xF0003C18)->bit0
#define DMA_STREQ_SCH01          ((T_Reg32 *) 0xF0003C18)->bit1
#define DMA_STREQ_SCH02          ((T_Reg32 *) 0xF0003C18)->bit2
#define DMA_STREQ_SCH03          ((T_Reg32 *) 0xF0003C18)->bit3
#define DMA_STREQ_SCH04          ((T_Reg32 *) 0xF0003C18)->bit4
#define DMA_STREQ_SCH05          ((T_Reg32 *) 0xF0003C18)->bit5
#define DMA_STREQ_SCH06          ((T_Reg32 *) 0xF0003C18)->bit6
#define DMA_STREQ_SCH07          ((T_Reg32 *) 0xF0003C18)->bit7

// DMA Suspend Mode Register
#define DMA_SUSPMR             (*((uword volatile *) 0xF0003C68))
#define DMA_SUSPMR_SUSAC00       ((T_Reg32 *) 0xF0003C68)->bit16
#define DMA_SUSPMR_SUSAC01       ((T_Reg32 *) 0xF0003C68)->bit17
#define DMA_SUSPMR_SUSAC02       ((T_Reg32 *) 0xF0003C68)->bit18
#define DMA_SUSPMR_SUSAC03       ((T_Reg32 *) 0xF0003C68)->bit19
#define DMA_SUSPMR_SUSAC04       ((T_Reg32 *) 0xF0003C68)->bit20
#define DMA_SUSPMR_SUSAC05       ((T_Reg32 *) 0xF0003C68)->bit21
#define DMA_SUSPMR_SUSAC06       ((T_Reg32 *) 0xF0003C68)->bit22
#define DMA_SUSPMR_SUSAC07       ((T_Reg32 *) 0xF0003C68)->bit23
#define DMA_SUSPMR_SUSEN00       ((T_Reg32 *) 0xF0003C68)->bit0
#define DMA_SUSPMR_SUSEN01       ((T_Reg32 *) 0xF0003C68)->bit1
#define DMA_SUSPMR_SUSEN02       ((T_Reg32 *) 0xF0003C68)->bit2
#define DMA_SUSPMR_SUSEN03       ((T_Reg32 *) 0xF0003C68)->bit3
#define DMA_SUSPMR_SUSEN04       ((T_Reg32 *) 0xF0003C68)->bit4
#define DMA_SUSPMR_SUSEN05       ((T_Reg32 *) 0xF0003C68)->bit5
#define DMA_SUSPMR_SUSEN06       ((T_Reg32 *) 0xF0003C68)->bit6
#define DMA_SUSPMR_SUSEN07       ((T_Reg32 *) 0xF0003C68)->bit7

// DMA Transaction Request State Register
#define DMA_TRSR               (*((uword volatile *) 0xF0003C14))
#define DMA_TRSR_CH00            ((T_Reg32 *) 0xF0003C14)->bit0
#define DMA_TRSR_CH01            ((T_Reg32 *) 0xF0003C14)->bit1
#define DMA_TRSR_CH02            ((T_Reg32 *) 0xF0003C14)->bit2
#define DMA_TRSR_CH03            ((T_Reg32 *) 0xF0003C14)->bit3
#define DMA_TRSR_CH04            ((T_Reg32 *) 0xF0003C14)->bit4
#define DMA_TRSR_CH05            ((T_Reg32 *) 0xF0003C14)->bit5
#define DMA_TRSR_CH06            ((T_Reg32 *) 0xF0003C14)->bit6
#define DMA_TRSR_CH07            ((T_Reg32 *) 0xF0003C14)->bit7
#define DMA_TRSR_HTRE00          ((T_Reg32 *) 0xF0003C14)->bit16
#define DMA_TRSR_HTRE01          ((T_Reg32 *) 0xF0003C14)->bit17
#define DMA_TRSR_HTRE02          ((T_Reg32 *) 0xF0003C14)->bit18
#define DMA_TRSR_HTRE03          ((T_Reg32 *) 0xF0003C14)->bit19
#define DMA_TRSR_HTRE04          ((T_Reg32 *) 0xF0003C14)->bit20
#define DMA_TRSR_HTRE05          ((T_Reg32 *) 0xF0003C14)->bit21
#define DMA_TRSR_HTRE06          ((T_Reg32 *) 0xF0003C14)->bit22
#define DMA_TRSR_HTRE07          ((T_Reg32 *) 0xF0003C14)->bit23

// DMA Wrap Status Register
#define DMA_WRPSR              (*((uword volatile *) 0xF0003C5C))
#define DMA_WRPSR_WRPD00         ((T_Reg32 *) 0xF0003C5C)->bit16
#define DMA_WRPSR_WRPD01         ((T_Reg32 *) 0xF0003C5C)->bit17
#define DMA_WRPSR_WRPD02         ((T_Reg32 *) 0xF0003C5C)->bit18
#define DMA_WRPSR_WRPD03         ((T_Reg32 *) 0xF0003C5C)->bit19
#define DMA_WRPSR_WRPD04         ((T_Reg32 *) 0xF0003C5C)->bit20
#define DMA_WRPSR_WRPD05         ((T_Reg32 *) 0xF0003C5C)->bit21
#define DMA_WRPSR_WRPD06         ((T_Reg32 *) 0xF0003C5C)->bit22
#define DMA_WRPSR_WRPD07         ((T_Reg32 *) 0xF0003C5C)->bit23
#define DMA_WRPSR_WRPS00         ((T_Reg32 *) 0xF0003C5C)->bit0
#define DMA_WRPSR_WRPS01         ((T_Reg32 *) 0xF0003C5C)->bit1
#define DMA_WRPSR_WRPS02         ((T_Reg32 *) 0xF0003C5C)->bit2
#define DMA_WRPSR_WRPS03         ((T_Reg32 *) 0xF0003C5C)->bit3
#define DMA_WRPSR_WRPS04         ((T_Reg32 *) 0xF0003C5C)->bit4
#define DMA_WRPSR_WRPS05         ((T_Reg32 *) 0xF0003C5C)->bit5
#define DMA_WRPSR_WRPS06         ((T_Reg32 *) 0xF0003C5C)->bit6
#define DMA_WRPSR_WRPS07         ((T_Reg32 *) 0xF0003C5C)->bit7

// DMI Asynchronous Trap Flag Register
#define DMI_ATR                (*((uword volatile *) 0xF87FFC20))
#define DMI_ATR_CFEATF           0x00000400
#define DMI_ATR_CMEATF           0x00000800
#define DMI_ATR_CRSEATF          0x00000080
#define DMI_ATR_CWSEATF          0x00000200
#define DMI_ATR_SBEATF           0x00000008
#define DMI_ATR_SMEATF           0x00008000
#define DMI_ATR_SREATF           0x00000002

// DMI Control Register
#define DMI_CON                (*((uword volatile *) 0xF87FFC10))

// DMI Identification Register
#define DMI_ID                 (*((uword volatile *) 0xF87FFC08))

// DMI Synchronous Trap Flag Register
#define DMI_STR                (*((uword volatile *) 0xF87FFC18))
#define DMI_STR_CRLESTF          0x00000040
#define DMI_STR_CWLESTF          0x00000100
#define DMI_STR_LBESTF           0x00000004
#define DMI_STR_LMESTF           0x00004000
#define DMI_STR_LRESTF           0x00000001

// Debug Monitor Start Address Register
#define DMS                    (*((uword volatile *) 0xF7E1FD40))

// Data Protection Mode Register Set 0
#define DPM0                   (*((uword volatile *) 0xF7E1E000))
#define DPM0_RBL0                0x00000004
#define DPM0_RBL1                0x00000400
#define DPM0_RBL2                0x00040000
#define DPM0_RBL3                0x04000000
#define DPM0_RBU0                0x00000001
#define DPM0_RBU1                0x00000100
#define DPM0_RBU2                0x00010000
#define DPM0_RBU3                0x01000000
#define DPM0_RE0                 0x00000040
#define DPM0_RE1                 0x00004000
#define DPM0_RE2                 0x00400000
#define DPM0_RE3                 0x40000000
#define DPM0_RS0                 0x00000010
#define DPM0_RS1                 0x00001000
#define DPM0_RS2                 0x00100000
#define DPM0_RS3                 0x10000000
#define DPM0_WBL0                0x00000008
#define DPM0_WBL1                0x00000800
#define DPM0_WBL2                0x00080000
#define DPM0_WBL3                0x08000000
#define DPM0_WBU0                0x00000002
#define DPM0_WBU1                0x00000200
#define DPM0_WBU2                0x00020000
#define DPM0_WBU3                0x02000000
#define DPM0_WE0                 0x00000080
#define DPM0_WE1                 0x00008000
#define DPM0_WE2                 0x00800000
#define DPM0_WE3                 0x80000000
#define DPM0_WS0                 0x00000020
#define DPM0_WS1                 0x00002000
#define DPM0_WS2                 0x00200000
#define DPM0_WS3                 0x20000000

// Data Protection Mode Register Set 1
#define DPM1                   (*((uword volatile *) 0xF7E1E080))
#define DPM1_RBL0                0x00000004
#define DPM1_RBL1                0x00000400
#define DPM1_RBL2                0x00040000
#define DPM1_RBL3                0x04000000
#define DPM1_RBU0                0x00000001
#define DPM1_RBU1                0x00000100
#define DPM1_RBU2                0x00010000
#define DPM1_RBU3                0x01000000
#define DPM1_RE0                 0x00000040
#define DPM1_RE1                 0x00004000
#define DPM1_RE2                 0x00400000
#define DPM1_RE3                 0x40000000
#define DPM1_RS0                 0x00000010
#define DPM1_RS1                 0x00001000
#define DPM1_RS2                 0x00100000
#define DPM1_RS3                 0x10000000
#define DPM1_WBL0                0x00000008
#define DPM1_WBL1                0x00000800
#define DPM1_WBL2                0x00080000
#define DPM1_WBL3                0x08000000
#define DPM1_WBU0                0x00000002
#define DPM1_WBU1                0x00000200
#define DPM1_WBU2                0x00020000
#define DPM1_WBU3                0x02000000
#define DPM1_WE0                 0x00000080
#define DPM1_WE1                 0x00008000
#define DPM1_WE2                 0x00800000
#define DPM1_WE3                 0x80000000
#define DPM1_WS0                 0x00000020
#define DPM1_WS1                 0x00002000
#define DPM1_WS2                 0x00200000
#define DPM1_WS3                 0x20000000

// Data Protection Mode Register Set 2
#define DPM2                   (*((uword volatile *) 0xF7E1E100))
#define DPM2_RBL0                0x00000004
#define DPM2_RBL1                0x00000400
#define DPM2_RBL2                0x00040000
#define DPM2_RBL3                0x04000000
#define DPM2_RBU0                0x00000001
#define DPM2_RBU1                0x00000100
#define DPM2_RBU2                0x00010000
#define DPM2_RBU3                0x01000000
#define DPM2_RE0                 0x00000040
#define DPM2_RE1                 0x00004000
#define DPM2_RE2                 0x00400000
#define DPM2_RE3                 0x40000000
#define DPM2_RS0                 0x00000010
#define DPM2_RS1                 0x00001000
#define DPM2_RS2                 0x00100000
#define DPM2_RS3                 0x10000000
#define DPM2_WBL0                0x00000008
#define DPM2_WBL1                0x00000800
#define DPM2_WBL2                0x00080000
#define DPM2_WBL3                0x08000000
#define DPM2_WBU0                0x00000002
#define DPM2_WBU1                0x00000200
#define DPM2_WBU2                0x00020000
#define DPM2_WBU3                0x02000000
#define DPM2_WE0                 0x00000080
#define DPM2_WE1                 0x00008000
#define DPM2_WE2                 0x00800000
#define DPM2_WE3                 0x80000000
#define DPM2_WS0                 0x00000020
#define DPM2_WS1                 0x00002000
#define DPM2_WS2                 0x00200000
#define DPM2_WS3                 0x20000000

// Data Protection Mode Register Set 3
#define DPM3                   (*((uword volatile *) 0xF7E1E180))
#define DPM3_RBL0                0x00000004
#define DPM3_RBL1                0x00000400
#define DPM3_RBL2                0x00040000
#define DPM3_RBL3                0x04000000
#define DPM3_RBU0                0x00000001
#define DPM3_RBU1                0x00000100
#define DPM3_RBU2                0x00010000
#define DPM3_RBU3                0x01000000
#define DPM3_RE0                 0x00000040
#define DPM3_RE1                 0x00004000
#define DPM3_RE2                 0x00400000
#define DPM3_RE3                 0x40000000
#define DPM3_RS0                 0x00000010
#define DPM3_RS1                 0x00001000
#define DPM3_RS2                 0x00100000
#define DPM3_RS3                 0x10000000
#define DPM3_WBL0                0x00000008
#define DPM3_WBL1                0x00000800
#define DPM3_WBL2                0x00080000
#define DPM3_WBL3                0x08000000
#define DPM3_WBU0                0x00000002
#define DPM3_WBU1                0x00000200
#define DPM3_WBU2                0x00020000
#define DPM3_WBU3                0x02000000
#define DPM3_WE0                 0x00000080
#define DPM3_WE1                 0x00008000
#define DPM3_WE2                 0x00800000
#define DPM3_WE3                 0x80000000
#define DPM3_WS0                 0x00000020
#define DPM3_WS1                 0x00002000
#define DPM3_WS2                 0x00200000
#define DPM3_WS3                 0x20000000

// Data Segment Protection Register Set 0, Range 0, Lower Boundary
#define DPR0_0L                (*((uword volatile *) 0xF7E1C000))

// Data Segment Protection Register Set 0, Range 0, Upper Boundary
#define DPR0_0U                (*((uword volatile *) 0xF7E1C004))

// Data Segment Protection Register Set 0, Range 1, Lower Boundary
#define DPR0_1L                (*((uword volatile *) 0xF7E1C008))

// Data Segment Protection Register Set 0, Range 1, Upper Boundary
#define DPR0_1U                (*((uword volatile *) 0xF7E1C00C))

// Data Segment Protection Register Set 0, Range 2, Lower Boundary
#define DPR0_2L                (*((uword volatile *) 0xF7E1C010))

// Data Segment Protection Register Set 0, Range 2, Upper Boundary
#define DPR0_2U                (*((uword volatile *) 0xF7E1C014))

// Data Segment Protection Register Set 0, Range 3, Lower Boundary
#define DPR0_3L                (*((uword volatile *) 0xF7E1C018))

// Data Segment Protection Register Set 0, Range 3, Upper Boundary
#define DPR0_3U                (*((uword volatile *) 0xF7E1C01C))

// Data Segment Protection Register Set 1, Range 0, Lower Boundary
#define DPR1_0L                (*((uword volatile *) 0xF7E1C400))

// Data Segment Protection Register Set 1, Range 0, Upper Boundary
#define DPR1_0U                (*((uword volatile *) 0xF7E1C404))

// Data Segment Protection Register Set 1, Range 1, Lower Boundary
#define DPR1_1L                (*((uword volatile *) 0xF7E1C408))

// Data Segment Protection Register Set 1, Range 1, Upper Boundary
#define DPR1_1U                (*((uword volatile *) 0xF7E1C40C))

// Data Segment Protection Register Set 1, Range 2, Lower Boundary
#define DPR1_2L                (*((uword volatile *) 0xF7E1C410))

// Data Segment Protection Register Set 1, Range 2, Upper Boundary
#define DPR1_2U                (*((uword volatile *) 0xF7E1C414))

// Data Segment Protection Register Set 1, Range 3, Lower Boundary
#define DPR1_3L                (*((uword volatile *) 0xF7E1C418))

// Data Segment Protection Register Set 1, Range 3, Upper Boundary
#define DPR1_3U                (*((uword volatile *) 0xF7E1C41C))

// Data Segment Protection Register Set 2, Range 0, Lower Boundary
#define DPR2_0L                (*((uword volatile *) 0xF7E1C800))

// Data Segment Protection Register Set 2, Range 0, Upper Boundary
#define DPR2_0U                (*((uword volatile *) 0xF7E1C804))

// Data Segment Protection Register Set 2, Range 1, Lower Boundary
#define DPR2_1L                (*((uword volatile *) 0xF7E1C808))

// Data Segment Protection Register Set 2, Range 1, Upper Boundary
#define DPR2_1U                (*((uword volatile *) 0xF7E1C80C))

// Data Segment Protection Register Set 2, Range 2, Lower Boundary
#define DPR2_2L                (*((uword volatile *) 0xF7E1C810))

// Data Segment Protection Register Set 2, Range 2, Upper Boundary
#define DPR2_2U                (*((uword volatile *) 0xF7E1C814))

// Data Segment Protection Register Set 2, Range 3, Lower Boundary
#define DPR2_3L                (*((uword volatile *) 0xF7E1C818))

// Data Segment Protection Register Set 2, Range 3, Upper Boundary
#define DPR2_3U                (*((uword volatile *) 0xF7E1C81C))

// Data Segment Protection Register Set 3, Range 0, Lower Boundary
#define DPR3_0L                (*((uword volatile *) 0xF7E1CC00))

// Data Segment Protection Register Set 3, Range 0, Upper Boundary
#define DPR3_0U                (*((uword volatile *) 0xF7E1CC04))

// Data Segment Protection Register Set 3, Range 1, Lower Boundary
#define DPR3_1L                (*((uword volatile *) 0xF7E1CC08))

// Data Segment Protection Register Set 3, Range 1, Upper Boundary
#define DPR3_1U                (*((uword volatile *) 0xF7E1CC0C))

// Data Segment Protection Register Set 3, Range 2, Lower Boundary
#define DPR3_2L                (*((uword volatile *) 0xF7E1CC10))

// Data Segment Protection Register Set 3, Range 2, Upper Boundary
#define DPR3_2U                (*((uword volatile *) 0xF7E1CC14))

// Data Segment Protection Register Set 3, Range 3, Lower Boundary
#define DPR3_3L                (*((uword volatile *) 0xF7E1CC18))

// Data Segment Protection Register Set 3, Range 3, Upper Boundary
#define DPR3_3U                (*((uword volatile *) 0xF7E1CC1C))

// EBU Address Select Register 0
#define EBU_ADDRSEL0           (*((uword volatile *) 0xF8000018))
#define EBU_ADDRSEL0_ALTENAB     0x00000002
#define EBU_ADDRSEL0_REGENAB     0x00000001
#define EBU_ADDRSEL0_RES         0x00000008
#define EBU_ADDRSEL0_WPROT       0x00000004

// EBU Address Select Register 1
#define EBU_ADDRSEL1           (*((uword volatile *) 0xF800001C))
#define EBU_ADDRSEL1_ALTENAB     0x00000002
#define EBU_ADDRSEL1_REGENAB     0x00000001
#define EBU_ADDRSEL1_RES         0x00000008
#define EBU_ADDRSEL1_WPROT       0x00000004

// EBU Address Select Register 2
#define EBU_ADDRSEL2           (*((uword volatile *) 0xF8000020))
#define EBU_ADDRSEL2_ALTENAB     0x00000002
#define EBU_ADDRSEL2_REGENAB     0x00000001
#define EBU_ADDRSEL2_RES         0x00000008
#define EBU_ADDRSEL2_WPROT       0x00000004

// EBU Address Select Register 3
#define EBU_ADDRSEL3           (*((uword volatile *) 0xF8000024))
#define EBU_ADDRSEL3_ALTENAB     0x00000002
#define EBU_ADDRSEL3_REGENAB     0x00000001
#define EBU_ADDRSEL3_RES         0x00000008
#define EBU_ADDRSEL3_WPROT       0x00000004

// EBU Bus Read Access Parameter Register
#define EBU_BUSRAP0            (*((uword volatile *) 0xF800002C))

// EBU Bus Read Access Parameter Register
#define EBU_BUSRAP1            (*((uword volatile *) 0xF800003C))

// EBU Bus Read Access Parameter Register
#define EBU_BUSRAP2            (*((uword volatile *) 0xF800004C))

// EBU Bus Read Access Parameter Register
#define EBU_BUSRAP3            (*((uword volatile *) 0xF800005C))

// EBU Bus Configuration Register
#define EBU_BUSRCON0           (*((uword volatile *) 0xF8000028))
#define EBU_BUSRCON0_AAP         0x04000000
#define EBU_BUSRCON0_BFCMSEL     0x00000040
#define EBU_BUSRCON0_BFSSS       0x00000010
#define EBU_BUSRCON0_DBA         0x00040000
#define EBU_BUSRCON0_EBSE        0x00020000
#define EBU_BUSRCON0_ECSE        0x00010000
#define EBU_BUSRCON0_FBBMSEL     0x00000008
#define EBU_BUSRCON0_FDBKEN      0x00000020
#define EBU_BUSRCON0_NAA         0x00000080
#define EBU_BUSRCON0_RES         0x08000000
#define EBU_BUSRCON0_WAITINV     0x00080000

// EBU Bus Configuration Register
#define EBU_BUSRCON1           (*((uword volatile *) 0xF8000038))
#define EBU_BUSRCON1_AAP         0x04000000
#define EBU_BUSRCON1_BFCMSEL     0x00000040
#define EBU_BUSRCON1_BFSSS       0x00000010
#define EBU_BUSRCON1_DBA         0x00040000
#define EBU_BUSRCON1_EBSE        0x00020000
#define EBU_BUSRCON1_ECSE        0x00010000
#define EBU_BUSRCON1_FBBMSEL     0x00000008
#define EBU_BUSRCON1_FDBKEN      0x00000020
#define EBU_BUSRCON1_NAA         0x00000080
#define EBU_BUSRCON1_RES         0x08000000
#define EBU_BUSRCON1_WAITINV     0x00080000

// EBU Bus Configuration Register
#define EBU_BUSRCON2           (*((uword volatile *) 0xF8000048))
#define EBU_BUSRCON2_AAP         0x04000000
#define EBU_BUSRCON2_BFCMSEL     0x00000040
#define EBU_BUSRCON2_BFSSS       0x00000010
#define EBU_BUSRCON2_DBA         0x00040000
#define EBU_BUSRCON2_EBSE        0x00020000
#define EBU_BUSRCON2_ECSE        0x00010000
#define EBU_BUSRCON2_FBBMSEL     0x00000008
#define EBU_BUSRCON2_FDBKEN      0x00000020
#define EBU_BUSRCON2_NAA         0x00000080
#define EBU_BUSRCON2_RES         0x08000000
#define EBU_BUSRCON2_WAITINV     0x00080000

// EBU Bus Configuration Register
#define EBU_BUSRCON3           (*((uword volatile *) 0xF8000058))
#define EBU_BUSRCON3_AAP         0x04000000
#define EBU_BUSRCON3_BFCMSEL     0x00000040
#define EBU_BUSRCON3_BFSSS       0x00000010
#define EBU_BUSRCON3_DBA         0x00040000
#define EBU_BUSRCON3_EBSE        0x00020000
#define EBU_BUSRCON3_ECSE        0x00010000
#define EBU_BUSRCON3_FBBMSEL     0x00000008
#define EBU_BUSRCON3_FDBKEN      0x00000020
#define EBU_BUSRCON3_NAA         0x00000080
#define EBU_BUSRCON3_RES         0x08000000
#define EBU_BUSRCON3_WAITINV     0x00080000

// EBU Bus Write Access Parameter Register
#define EBU_BUSWAP0            (*((uword volatile *) 0xF8000034))

// EBU Bus Write Access Parameter Register
#define EBU_BUSWAP1            (*((uword volatile *) 0xF8000044))

// EBU Bus Write Access Parameter Register
#define EBU_BUSWAP2            (*((uword volatile *) 0xF8000054))

// EBU Bus Write Access Parameter Register
#define EBU_BUSWAP3            (*((uword volatile *) 0xF8000064))

// EBU Bus Write Configuration Register
#define EBU_BUSWCON0           (*((uword volatile *) 0xF8000030))
#define EBU_BUSWCON0_AAP         0x04000000
#define EBU_BUSWCON0_EBSE        0x00020000
#define EBU_BUSWCON0_ECSE        0x00010000
#define EBU_BUSWCON0_FBBMSEL     0x00000008
#define EBU_BUSWCON0_LOCKCS      0x08000000
#define EBU_BUSWCON0_NAA         0x00000080
#define EBU_BUSWCON0_RES         0x00040000
#define EBU_BUSWCON0_WAITINV     0x00080000

// EBU Bus Write Configuration Register
#define EBU_BUSWCON1           (*((uword volatile *) 0xF8000040))
#define EBU_BUSWCON1_AAP         0x04000000
#define EBU_BUSWCON1_EBSE        0x00020000
#define EBU_BUSWCON1_ECSE        0x00010000
#define EBU_BUSWCON1_FBBMSEL     0x00000008
#define EBU_BUSWCON1_LOCKCS      0x08000000
#define EBU_BUSWCON1_NAA         0x00000080
#define EBU_BUSWCON1_RES         0x00040000
#define EBU_BUSWCON1_WAITINV     0x00080000

// EBU Bus Write Configuration Register
#define EBU_BUSWCON2           (*((uword volatile *) 0xF8000050))
#define EBU_BUSWCON2_AAP         0x04000000
#define EBU_BUSWCON2_EBSE        0x00020000
#define EBU_BUSWCON2_ECSE        0x00010000
#define EBU_BUSWCON2_FBBMSEL     0x00000008
#define EBU_BUSWCON2_LOCKCS      0x08000000
#define EBU_BUSWCON2_NAA         0x00000080
#define EBU_BUSWCON2_RES         0x00040000
#define EBU_BUSWCON2_WAITINV     0x00080000

// EBU Bus Write Configuration Register
#define EBU_BUSWCON3           (*((uword volatile *) 0xF8000060))
#define EBU_BUSWCON3_AAP         0x04000000
#define EBU_BUSWCON3_EBSE        0x00020000
#define EBU_BUSWCON3_ECSE        0x00010000
#define EBU_BUSWCON3_FBBMSEL     0x00000008
#define EBU_BUSWCON3_LOCKCS      0x08000000
#define EBU_BUSWCON3_NAA         0x00000080
#define EBU_BUSWCON3_RES         0x00040000
#define EBU_BUSWCON3_WAITINV     0x00080000

// EBU Clock Control Register
#define EBU_CLC                (*((uword volatile *) 0xF8000000))
#define EBU_CLC_DDR              0x00020000
#define EBU_CLC_DDRACK           0x00200000
#define EBU_CLC_DISR             0x00000001
#define EBU_CLC_DISS             0x00000002
#define EBU_CLC_EPE              0x00000100
#define EBU_CLC_SYNC             0x00010000
#define EBU_CLC_SYNCACK          0x00100000

// EBU External Boot Configuration Register
#define EBU_EXTBOOT            (*((uword volatile *) 0xF8000010))
#define EBU_EXTBOOT_CFGEND       0x00000001
#define EBU_EXTBOOT_CFGERR       0x00000002
#define EBU_EXTBOOT_EBUCFG       0x80000000

// EBU Configuration Register
#define EBU_MODCON             (*((uword volatile *) 0xF8000004))
#define EBU_MODCON_ALE           0x80000000
#define EBU_MODCON_ARBSYNC       0x00000020
#define EBU_MODCON_EXTLOCK       0x00000010
#define EBU_MODCON_LCKABRT       0x00000002
#define EBU_MODCON_STS           0x00000001

// EBU Test/Control Configuration Register
#define EBU_USERCON            (*((uword volatile *) 0xF800000C))
#define EBU_USERCON_DIP          0x00000001

// External Break Input Event Specifier Register
#define EXEVT                  (*((uword volatile *) 0xF7E1FD08))
#define EXEVT_BBM                0x00000008
#define EXEVT_BOD                0x00000010
#define EXEVT_CSP                0x00000080
#define EXEVT_CST                0x00000040
#define EXEVT_SUSP               0x00000020

// FADC Channel 0 Analog Control Register
#define FADC_ACR0              (*((uword volatile *) 0xF0100430))
#define FADC_ACR0_CALOFF3        0x00001000
#define FADC_ACR0_ENN            0x00000008
#define FADC_ACR0_ENP            0x00000004

// FADC Channel 1 Analog Control Register
#define FADC_ACR1              (*((uword volatile *) 0xF0100434))
#define FADC_ACR1_CALOFF3        0x00001000
#define FADC_ACR1_ENN            0x00000008
#define FADC_ACR1_ENP            0x00000004

// FADC Channel 2 Analog Control Register
#define FADC_ACR2              (*((uword volatile *) 0xF0100438))
#define FADC_ACR2_CALOFF3        0x00001000
#define FADC_ACR2_ENN            0x00000008
#define FADC_ACR2_ENP            0x00000004

// FADC Channel 3 Analog Control Register
#define FADC_ACR3              (*((uword volatile *) 0xF010043C))
#define FADC_ACR3_CALOFF3        0x00001000
#define FADC_ACR3_ENN            0x00000008
#define FADC_ACR3_ENP            0x00000004

// FADC Alias Register
#define FADC_ALR               (*((uword volatile *) 0xF0100454))

// FADC Channel 0 Configuration Register
#define FADC_CFGR0             (*((uword volatile *) 0xF0100420))
#define FADC_CFGR0_IEN           0x80000000

// FADC Channel 1 Configuration Register
#define FADC_CFGR1             (*((uword volatile *) 0xF0100424))
#define FADC_CFGR1_IEN           0x80000000

// FADC Channel 2 Configuration Register
#define FADC_CFGR2             (*((uword volatile *) 0xF0100428))
#define FADC_CFGR2_IEN           0x80000000

// FADC Channel 3 Configuration Register
#define FADC_CFGR3             (*((uword volatile *) 0xF010042C))
#define FADC_CFGR3_IEN           0x80000000

// FADC Clock Control Register
#define FADC_CLC               (*((uword volatile *) 0xF0100400))
#define FADC_CLC_DISR            0x00000001
#define FADC_CLC_DISS            0x00000002
#define FADC_CLC_EDIS            0x00000008
#define FADC_CLC_FSOE            0x00000020
#define FADC_CLC_SBWE            0x00000010
#define FADC_CLC_SPEN            0x00000004

// FADC Filter 0 Current Result Register
#define FADC_CRR0              (*((uword volatile *) 0xF0100464))

// FADC Filter 1 Current Result Register
#define FADC_CRR1              (*((uword volatile *) 0xF0100484))

// FADC Filter 2 Current Result Register
#define FADC_CRR2              (*((uword volatile *) 0xF01004A4))

// FADC Filter 3 Current Result Register
#define FADC_CRR3              (*((uword volatile *) 0xF01004C4))

// FADC Conversion Request Status Register
#define FADC_CRSR              (*((uword volatile *) 0xF0100410))
#define FADC_CRSR_BSY0           0x00000100
#define FADC_CRSR_BSY1           0x00000200
#define FADC_CRSR_BSY2           0x00000400
#define FADC_CRSR_BSY3           0x00000800
#define FADC_CRSR_CRF0           0x00000001
#define FADC_CRSR_CRF1           0x00000002
#define FADC_CRSR_CRF2           0x00000004
#define FADC_CRSR_CRF3           0x00000008
#define FADC_CRSR_IRQ0           0x00010000
#define FADC_CRSR_IRQ1           0x00020000
#define FADC_CRSR_IRQ2           0x00040000
#define FADC_CRSR_IRQ3           0x00080000
#define FADC_CRSR_IRQF0          0x00100000
#define FADC_CRSR_IRQF1          0x00200000
#define FADC_CRSR_IRQF2          0x00400000
#define FADC_CRSR_IRQF3          0x00800000

// FADC Filter 0 Control Register
#define FADC_FCR0              (*((uword volatile *) 0xF0100460))
#define FADC_FCR0_IEN            0x00008000

// FADC Filter 1 Control Register
#define FADC_FCR1              (*((uword volatile *) 0xF0100480))
#define FADC_FCR1_IEN            0x00008000

// FADC Filter 2 Control Register
#define FADC_FCR2              (*((uword volatile *) 0xF01004A0))
#define FADC_FCR2_IEN            0x00008000

// FADC Filter 3 Control Register
#define FADC_FCR3              (*((uword volatile *) 0xF01004C0))
#define FADC_FCR3_IEN            0x00008000

// FADC Fractional Divider Register
#define FADC_FDR               (*((uword volatile *) 0xF010040C))
#define FADC_FDR_DISCLK          0x80000000
#define FADC_FDR_ENHW            0x40000000
#define FADC_FDR_SM              0x00000800
#define FADC_FDR_SUSACK          0x10000000
#define FADC_FDR_SUSREQ          0x20000000

// FADC Flag Modification Register
#define FADC_FMR               (*((uword volatile *) 0xF0100414))
#define FADC_FMR_RCRF0           0x00000001
#define FADC_FMR_RCRF1           0x00000002
#define FADC_FMR_RCRF2           0x00000004
#define FADC_FMR_RCRF3           0x00000008
#define FADC_FMR_RIRQ0           0x00010000
#define FADC_FMR_RIRQ1           0x00020000
#define FADC_FMR_RIRQ2           0x00040000
#define FADC_FMR_RIRQ3           0x00080000
#define FADC_FMR_RIRQF0          0x00100000
#define FADC_FMR_RIRQF1          0x00200000
#define FADC_FMR_RIRQF2          0x00400000
#define FADC_FMR_RIRQF3          0x00800000
#define FADC_FMR_SCRF0           0x00000100
#define FADC_FMR_SCRF1           0x00000200
#define FADC_FMR_SCRF2           0x00000400
#define FADC_FMR_SCRF3           0x00000800
#define FADC_FMR_SIRQ0           0x01000000
#define FADC_FMR_SIRQ1           0x02000000
#define FADC_FMR_SIRQ2           0x04000000
#define FADC_FMR_SIRQ3           0x08000000
#define FADC_FMR_SIRQF0          0x10000000
#define FADC_FMR_SIRQF1          0x20000000
#define FADC_FMR_SIRQF2          0x40000000
#define FADC_FMR_SIRQF3          0x80000000

// FADC Filter 0 Final Result Register
#define FADC_FRR0              (*((uword volatile *) 0xF0100474))

// FADC Filter 1 Final Result Register
#define FADC_FRR1              (*((uword volatile *) 0xF0100494))

// FADC Filter 2 Final Result Register
#define FADC_FRR2              (*((uword volatile *) 0xF01004B4))

// FADC Filter 3 Final Result Register
#define FADC_FRR3              (*((uword volatile *) 0xF01004D4))

// FADC Global Control Register
#define FADC_GCR               (*((uword volatile *) 0xF010041C))
#define FADC_GCR_ANON            0x00200000
#define FADC_GCR_DPAEN           0x00040000
#define FADC_GCR_MUXTM           0x00100000
#define FADC_GCR_RCD             0x00000100
#define FADC_GCR_RCT0            0x00000001
#define FADC_GCR_RCT1            0x00000002
#define FADC_GCR_RCT2            0x00000004
#define FADC_GCR_RCT3            0x00000008
#define FADC_GCR_RESWEN          0x00080000
#define FADC_GCR_RSTF0           0x00000200
#define FADC_GCR_RSTF1           0x00000400
#define FADC_GCR_RSTF2           0x00000800
#define FADC_GCR_RSTF3           0x00001000

// FADC Filter 0 Intermediate Result Register 1
#define FADC_IRR10             (*((uword volatile *) 0xF0100468))

// FADC Filter 1 Intermediate Result Register 1
#define FADC_IRR11             (*((uword volatile *) 0xF0100488))

// FADC Filter 2 Intermediate Result Register 1
#define FADC_IRR12             (*((uword volatile *) 0xF01004A8))

// FADC Filter 3 Intermediate Result Register 1
#define FADC_IRR13             (*((uword volatile *) 0xF01004C8))

// FADC Filter 0 Intermediate Result Register 2
#define FADC_IRR20             (*((uword volatile *) 0xF010046C))

// FADC Filter 2 Intermediate Result Register 2
#define FADC_IRR22             (*((uword volatile *) 0xF01004AC))

// FADC Filter 0 Intermediate Result Register 3
#define FADC_IRR30             (*((uword volatile *) 0xF0100470))

// FADC Filter 2 Intermediate Result Register 3
#define FADC_IRR32             (*((uword volatile *) 0xF01004B0))

// FADC Neighbor Channel Trigger Register
#define FADC_NCTR              (*((uword volatile *) 0xF0100418))
#define FADC_NCTR_EN01           0x00000002
#define FADC_NCTR_EN02           0x00000004
#define FADC_NCTR_EN03           0x00000008
#define FADC_NCTR_EN10           0x00000100
#define FADC_NCTR_EN12           0x00000400
#define FADC_NCTR_EN13           0x00000800
#define FADC_NCTR_EN20           0x00010000
#define FADC_NCTR_EN21           0x00020000
#define FADC_NCTR_EN23           0x00080000
#define FADC_NCTR_EN30           0x01000000
#define FADC_NCTR_EN31           0x02000000
#define FADC_NCTR_EN32           0x04000000

// FADC Channel 0 Conversion Result Register
#define FADC_RCH0              (*((uword volatile *) 0xF0100440))

// FADC Channel 1 Conversion Result Register
#define FADC_RCH1              (*((uword volatile *) 0xF0100444))

// FADC Channel 2 Conversion Result Register
#define FADC_RCH2              (*((uword volatile *) 0xF0100448))

// FADC Channel 3 Conversion Result Register
#define FADC_RCH3              (*((uword volatile *) 0xF010044C))

// FADC Filter 1 Shifted Final Result Register
#define FADC_SFRR1             (*((uword volatile *) 0xF0100498))

// FADC Filter 3 Shifted Final Result Register
#define FADC_SFRR3             (*((uword volatile *) 0xF01004D8))

// FADC Service Request Control Register 0
#define FADC_SRC0              (*((uword volatile *) 0xF01004FC))
#define FADC_SRC0_CLRR           0x00004000
#define FADC_SRC0_SETR           0x00008000
#define FADC_SRC0_SRE            0x00001000
#define FADC_SRC0_SRR            0x00002000
#define FADC_SRC0_TOS            0x00000400

// FADC Service Request Control Register 1
#define FADC_SRC1              (*((uword volatile *) 0xF01004F8))
#define FADC_SRC1_CLRR           0x00004000
#define FADC_SRC1_SETR           0x00008000
#define FADC_SRC1_SRE            0x00001000
#define FADC_SRC1_SRR            0x00002000
#define FADC_SRC1_TOS            0x00000400

// FADC Service Request Control Register 2
#define FADC_SRC2              (*((uword volatile *) 0xF01004F4))
#define FADC_SRC2_CLRR           0x00004000
#define FADC_SRC2_SETR           0x00008000
#define FADC_SRC2_SRE            0x00001000
#define FADC_SRC2_SRR            0x00002000
#define FADC_SRC2_TOS            0x00000400

// FADC Service Request Control Register 3
#define FADC_SRC3              (*((uword volatile *) 0xF01004F0))
#define FADC_SRC3_CLRR           0x00004000
#define FADC_SRC3_SETR           0x00008000
#define FADC_SRC3_SRE            0x00001000
#define FADC_SRC3_SRR            0x00002000
#define FADC_SRC3_TOS            0x00000400

// Free CSA List Head Pointer
#define FCX                    (*((uword volatile *) 0xF7E1FE38))

// CPU Flash Test Register
#define FLASH0_CFTEST          (*((uword volatile *) 0xF8002100))
#define FLASH0_CFTEST_CONFSE     0x00000010
#define FLASH0_CFTEST_ECDECDIS   0x00000008
#define FLASH0_CFTEST_ECENCDIS   0x00000004
#define FLASH0_CFTEST_EEAS       0x00000080
#define FLASH0_CFTEST_FSIINT     0x00000200
#define FLASH0_CFTEST_FSIINTEN   0x00000100
#define FLASH0_CFTEST_FSRAME     0x00000040
#define FLASH0_CFTEST_PREFEDIS   0x00000020
#define FLASH0_CFTEST_TE         0x00000001

// ECC Read Register
#define FLASH0_ECCR            (*((uword volatile *) 0xF8002108))

// ECC Write Register
#define FLASH0_ECCW            (*((uword volatile *) 0xF8002104))

// Flash Configuration Register
#define FLASH0_FCON            (*((uword volatile *) 0xF8002014))
#define FLASH0_FCON_DCF          0x00020000
#define FLASH0_FCON_DDF          0x00040000
#define FLASH0_FCON_DDFDMA       0x00100000
#define FLASH0_FCON_DDFPCP       0x00200000
#define FLASH0_FCON_DFDBERM      0x40000000
#define FLASH0_FCON_DFSBERM      0x10000000
#define FLASH0_FCON_EOBM         0x80000000
#define FLASH0_FCON_ESLDIS       0x00004000
#define FLASH0_FCON_IDLE         0x00002000
#define FLASH0_FCON_PFDBERM      0x20000000
#define FLASH0_FCON_PFSBERM      0x08000000
#define FLASH0_FCON_PROERM       0x04000000
#define FLASH0_FCON_RPA          0x00010000
#define FLASH0_FCON_SLEEP_FSD    0x00008000
#define FLASH0_FCON_SQERM        0x02000000
#define FLASH0_FCON_VOPERM       0x01000000
#define FLASH0_FCON_WSECDF       0x00001000
#define FLASH0_FCON_WSECPF       0x00000010

// Flash Size Configuration Register
#define FLASH0_FSCON           (*((uword volatile *) 0xF800210C))

// Flash Status Register
#define FLASH0_FSR             (*((uword volatile *) 0xF8002010))
#define FLASH0_FSR_D0BUSY        0x00000004
#define FLASH0_FSR_D1BUSY        0x00000008
#define FLASH0_FSR_DFDBER        0x00008000
#define FLASH0_FSR_DFOPER        0x00000200
#define FLASH0_FSR_DFPAGE        0x00000080
#define FLASH0_FSR_DFSBER        0x00002000
#define FLASH0_FSR_ERASE         0x00000020
#define FLASH0_FSR_FABUSY        0x00000002
#define FLASH0_FSR_ORIER         0x40000000
#define FLASH0_FSR_PBUSY         0x00000001
#define FLASH0_FSR_PFDBER        0x00004000
#define FLASH0_FSR_PFOPER        0x00000100
#define FLASH0_FSR_PFPAGE        0x00000040
#define FLASH0_FSR_PFSBER        0x00001000
#define FLASH0_FSR_PROER         0x00000800
#define FLASH0_FSR_PROG          0x00000010
#define FLASH0_FSR_PROIN         0x00010000
#define FLASH0_FSR_RPRODIS       0x00080000
#define FLASH0_FSR_RPROIN        0x00040000
#define FLASH0_FSR_SLM           0x10000000
#define FLASH0_FSR_SQER          0x00000400
#define FLASH0_FSR_VER           0x80000000
#define FLASH0_FSR_VIS           0x20000000
#define FLASH0_FSR_WPRODIS0      0x02000000
#define FLASH0_FSR_WPRODIS1      0x04000000
#define FLASH0_FSR_WPROIN0       0x00200000
#define FLASH0_FSR_WPROIN1       0x00400000
#define FLASH0_FSR_WPROIN2       0x00800000

// Flash Module Identification Register
#define FLASH0_ID              (*((uword volatile *) 0xF8002008))

// Margin Control Register DFLASH
#define FLASH0_MARD            (*((uword volatile *) 0xF800201C))
#define FLASH0_MARD_BNKSEL       0x00000010
#define FLASH0_MARD_NANTRAPDIS   0x00008000
#define FLASH0_MARD_TRAPDIS      0x00008000

// Margin Control Register PFLASH
#define FLASH0_MARP            (*((uword volatile *) 0xF8002018))
#define FLASH0_MARP_NANTRAPDIS   0x00008000
#define FLASH0_MARP_TRAPDIS      0x00008000

// Flash Protection Configuration Register User 0
#define FLASH0_PROCON0         (*((uword volatile *) 0xF8002020))
#define FLASH0_PROCON0_DFEXPRO   0x00004000
#define FLASH0_PROCON0_RPRO      0x00008000
#define FLASH0_PROCON0_S0L       0x00000001
#define FLASH0_PROCON0_S10_S11L  0x00000400
#define FLASH0_PROCON0_S12_S13L  0x00000800
#define FLASH0_PROCON0_S14_S15L  0x00001000
#define FLASH0_PROCON0_S1L       0x00000002
#define FLASH0_PROCON0_S2L       0x00000004
#define FLASH0_PROCON0_S3L       0x00000008
#define FLASH0_PROCON0_S4L       0x00000010
#define FLASH0_PROCON0_S5L       0x00000020
#define FLASH0_PROCON0_S6L       0x00000040
#define FLASH0_PROCON0_S7L       0x00000080
#define FLASH0_PROCON0_S8L       0x00000100
#define FLASH0_PROCON0_S9L       0x00000200

// Flash Protection Configuration Register User 1
#define FLASH0_PROCON1         (*((uword volatile *) 0xF8002024))
#define FLASH0_PROCON1_S0L       0x00000001
#define FLASH0_PROCON1_S10_S11L  0x00000400
#define FLASH0_PROCON1_S12_S13L  0x00000800
#define FLASH0_PROCON1_S14_S15L  0x00001000
#define FLASH0_PROCON1_S1L       0x00000002
#define FLASH0_PROCON1_S2L       0x00000004
#define FLASH0_PROCON1_S3L       0x00000008
#define FLASH0_PROCON1_S4L       0x00000010
#define FLASH0_PROCON1_S5L       0x00000020
#define FLASH0_PROCON1_S6L       0x00000040
#define FLASH0_PROCON1_S7L       0x00000080
#define FLASH0_PROCON1_S8L       0x00000100
#define FLASH0_PROCON1_S9L       0x00000200

// Flash Protection Configuration Register User 2
#define FLASH0_PROCON2         (*((uword volatile *) 0xF8002028))
#define FLASH0_PROCON2_S0ROM     0x00000001
#define FLASH0_PROCON2_S10_S11ROM 0x00000400
#define FLASH0_PROCON2_S12_S13ROM 0x00000800
#define FLASH0_PROCON2_S14_S15ROM 0x00001000
#define FLASH0_PROCON2_S1ROM     0x00000002
#define FLASH0_PROCON2_S2ROM     0x00000004
#define FLASH0_PROCON2_S3ROM     0x00000008
#define FLASH0_PROCON2_S4ROM     0x00000010
#define FLASH0_PROCON2_S5ROM     0x00000020
#define FLASH0_PROCON2_S6ROM     0x00000040
#define FLASH0_PROCON2_S7ROM     0x00000080
#define FLASH0_PROCON2_S8ROM     0x00000100
#define FLASH0_PROCON2_S9ROM     0x00000200
#define FLASH0_PROCON2_TP        0x00008000

// Trapping Identification Register
#define FPU_ID                 (*((uword volatile *) 0xF7E1A020))

// Trap Control Register
#define FPU_TRAP_CON           (*((uword volatile *) 0xF7E1A000))
#define FPU_TRAP_CON_FI          0x40000000
#define FPU_TRAP_CON_FIE         0x00400000
#define FPU_TRAP_CON_FU          0x08000000
#define FPU_TRAP_CON_FUE         0x00080000
#define FPU_TRAP_CON_FV          0x20000000
#define FPU_TRAP_CON_FVE         0x00200000
#define FPU_TRAP_CON_FX          0x04000000
#define FPU_TRAP_CON_FXE         0x00040000
#define FPU_TRAP_CON_FZ          0x10000000
#define FPU_TRAP_CON_FZE         0x00100000
#define FPU_TRAP_CON_TCL         0x00000002
#define FPU_TRAP_CON_TST         0x00000001

// Trapping Instruction Opcode Register
#define FPU_TRAP_OPC           (*((uword volatile *) 0xF7E1A008))
#define FPU_TRAP_OPC_FMT         0x00000100

// Trapping Instruction Program Counter Register
#define FPU_TRAP_PC            (*((uword volatile *) 0xF7E1A004))

// Trapping Instruction Operand Register
#define FPU_TRAP_SRC1          (*((uword volatile *) 0xF7E1A010))

// Trapping Instruction Operand Register
#define FPU_TRAP_SRC2          (*((uword volatile *) 0xF7E1A014))

// Trapping Instruction Operand Register
#define FPU_TRAP_SRC3          (*((uword volatile *) 0xF7E1A018))

// GPTA0 Clock Bus Control Register
#define GPTA0_CKBCTR           (*((uword volatile *) 0xF00018D8))

// GPTA Clock Control Register
#define GPTA0_CLC              (*((uword volatile *) 0xF0001800))
#define GPTA0_CLC_DISR           ((T_Reg32 *) 0xF0001800)->bit0
#define GPTA0_CLC_DISS           ((T_Reg32 *) 0xF0001800)->bit1
#define GPTA0_CLC_EDIS           ((T_Reg32 *) 0xF0001800)->bit3
#define GPTA0_CLC_FSOE           ((T_Reg32 *) 0xF0001800)->bit5
#define GPTA0_CLC_SBWE           ((T_Reg32 *) 0xF0001800)->bit4
#define GPTA0_CLC_SPEN           ((T_Reg32 *) 0xF0001800)->bit2

// GPTA Debug Clock Control Register
#define GPTA0_DBGCTR           (*((uword volatile *) 0xF0001804))
#define GPTA0_DBGCTR_DBGCEN      ((T_Reg32 *) 0xF0001804)->bit31

// GPTA0 Duty Cycle Measurement Capture Register 0
#define GPTA0_DCMCAV0          (*((uword volatile *) 0xF0001888))

// GPTA0 Duty Cycle Measurement Capture Register 1
#define GPTA0_DCMCAV1          (*((uword volatile *) 0xF0001898))

// GPTA0 Duty Cycle Measurement Capture Register 2
#define GPTA0_DCMCAV2          (*((uword volatile *) 0xF00018A8))

// GPTA0 Duty Cycle Measurement Capture Register 3
#define GPTA0_DCMCAV3          (*((uword volatile *) 0xF00018B8))

// GPTA0 Duty Cycle Measurement Capture/Compare Register 0
#define GPTA0_DCMCOV0          (*((uword volatile *) 0xF000188C))

// GPTA0 Duty Cycle Measurement Capture/Compare Register 1
#define GPTA0_DCMCOV1          (*((uword volatile *) 0xF000189C))

// GPTA0 Duty Cycle Measurement Capture/Compare Register 2
#define GPTA0_DCMCOV2          (*((uword volatile *) 0xF00018AC))

// GPTA0 Duty Cycle Measurement Capture/Compare Register 3
#define GPTA0_DCMCOV3          (*((uword volatile *) 0xF00018BC))

// GPTA0 Duty Cycle Measurement Control Register 0
#define GPTA0_DCMCTR0          (*((uword volatile *) 0xF0001880))
#define GPTA0_DCMCTR0_CRE        ((T_Reg32 *) 0xF0001880)->bit9
#define GPTA0_DCMCTR0_FCK        ((T_Reg32 *) 0xF0001880)->bit5
#define GPTA0_DCMCTR0_FRE        ((T_Reg32 *) 0xF0001880)->bit8
#define GPTA0_DCMCTR0_FZE        ((T_Reg32 *) 0xF0001880)->bit3
#define GPTA0_DCMCTR0_OCA        ((T_Reg32 *) 0xF0001880)->bit1
#define GPTA0_DCMCTR0_QCK        ((T_Reg32 *) 0xF0001880)->bit6
#define GPTA0_DCMCTR0_RCA        ((T_Reg32 *) 0xF0001880)->bit0
#define GPTA0_DCMCTR0_RCK        ((T_Reg32 *) 0xF0001880)->bit4
#define GPTA0_DCMCTR0_RRE        ((T_Reg32 *) 0xF0001880)->bit7
#define GPTA0_DCMCTR0_RZE        ((T_Reg32 *) 0xF0001880)->bit2

// GPTA0 Duty Cycle Measurement Control Register 1
#define GPTA0_DCMCTR1          (*((uword volatile *) 0xF0001890))
#define GPTA0_DCMCTR1_CRE        ((T_Reg32 *) 0xF0001890)->bit9
#define GPTA0_DCMCTR1_FCK        ((T_Reg32 *) 0xF0001890)->bit5
#define GPTA0_DCMCTR1_FRE        ((T_Reg32 *) 0xF0001890)->bit8
#define GPTA0_DCMCTR1_FZE        ((T_Reg32 *) 0xF0001890)->bit3
#define GPTA0_DCMCTR1_OCA        ((T_Reg32 *) 0xF0001890)->bit1
#define GPTA0_DCMCTR1_QCK        ((T_Reg32 *) 0xF0001890)->bit6
#define GPTA0_DCMCTR1_RCA        ((T_Reg32 *) 0xF0001890)->bit0
#define GPTA0_DCMCTR1_RCK        ((T_Reg32 *) 0xF0001890)->bit4
#define GPTA0_DCMCTR1_RRE        ((T_Reg32 *) 0xF0001890)->bit7
#define GPTA0_DCMCTR1_RZE        ((T_Reg32 *) 0xF0001890)->bit2

// GPTA0 Duty Cycle Measurement Control Register 2
#define GPTA0_DCMCTR2          (*((uword volatile *) 0xF00018A0))
#define GPTA0_DCMCTR2_CRE        ((T_Reg32 *) 0xF00018A0)->bit9
#define GPTA0_DCMCTR2_FCK        ((T_Reg32 *) 0xF00018A0)->bit5
#define GPTA0_DCMCTR2_FRE        ((T_Reg32 *) 0xF00018A0)->bit8
#define GPTA0_DCMCTR2_FZE        ((T_Reg32 *) 0xF00018A0)->bit3
#define GPTA0_DCMCTR2_OCA        ((T_Reg32 *) 0xF00018A0)->bit1
#define GPTA0_DCMCTR2_QCK        ((T_Reg32 *) 0xF00018A0)->bit6
#define GPTA0_DCMCTR2_RCA        ((T_Reg32 *) 0xF00018A0)->bit0
#define GPTA0_DCMCTR2_RCK        ((T_Reg32 *) 0xF00018A0)->bit4
#define GPTA0_DCMCTR2_RRE        ((T_Reg32 *) 0xF00018A0)->bit7
#define GPTA0_DCMCTR2_RZE        ((T_Reg32 *) 0xF00018A0)->bit2

// GPTA0 Duty Cycle Measurement Control Register 3
#define GPTA0_DCMCTR3          (*((uword volatile *) 0xF00018B0))
#define GPTA0_DCMCTR3_CRE        ((T_Reg32 *) 0xF00018B0)->bit9
#define GPTA0_DCMCTR3_FCK        ((T_Reg32 *) 0xF00018B0)->bit5
#define GPTA0_DCMCTR3_FRE        ((T_Reg32 *) 0xF00018B0)->bit8
#define GPTA0_DCMCTR3_FZE        ((T_Reg32 *) 0xF00018B0)->bit3
#define GPTA0_DCMCTR3_OCA        ((T_Reg32 *) 0xF00018B0)->bit1
#define GPTA0_DCMCTR3_QCK        ((T_Reg32 *) 0xF00018B0)->bit6
#define GPTA0_DCMCTR3_RCA        ((T_Reg32 *) 0xF00018B0)->bit0
#define GPTA0_DCMCTR3_RCK        ((T_Reg32 *) 0xF00018B0)->bit4
#define GPTA0_DCMCTR3_RRE        ((T_Reg32 *) 0xF00018B0)->bit7
#define GPTA0_DCMCTR3_RZE        ((T_Reg32 *) 0xF00018B0)->bit2

// GPTA0 Duty Cycle Measurement Timer Register 0
#define GPTA0_DCMTIM0          (*((uword volatile *) 0xF0001884))

// GPTA0 Duty Cycle Measurement Timer Register 1
#define GPTA0_DCMTIM1          (*((uword volatile *) 0xF0001894))

// GPTA0 Duty Cycle Measurement Timer Register 2
#define GPTA0_DCMTIM2          (*((uword volatile *) 0xF00018A4))

// GPTA0 Duty Cycle Measurement Timer Register 3
#define GPTA0_DCMTIM3          (*((uword volatile *) 0xF00018B4))

// GPTA Clock Enable/Disable Control Register
#define GPTA0_EDCTR            (*((uword volatile *) 0xF0001C00))
#define GPTA0_EDCTR_G0EN         ((T_Reg32 *) 0xF0001C00)->bit8
#define GPTA0_EDCTR_GT00RUN      ((T_Reg32 *) 0xF0001C00)->bit0
#define GPTA0_EDCTR_GT01RUN      ((T_Reg32 *) 0xF0001C00)->bit1
#define GPTA0_EDCTR_L2EN         ((T_Reg32 *) 0xF0001C00)->bit10

// GPTA Fractional Divider Register
#define GPTA0_FDR              (*((uword volatile *) 0xF000180C))
#define GPTA0_FDR_DISCLK         ((T_Reg32 *) 0xF000180C)->bit31
#define GPTA0_FDR_ENHW           ((T_Reg32 *) 0xF000180C)->bit30
#define GPTA0_FDR_SM             ((T_Reg32 *) 0xF000180C)->bit11
#define GPTA0_FDR_SUSACK         ((T_Reg32 *) 0xF000180C)->bit28
#define GPTA0_FDR_SUSREQ         ((T_Reg32 *) 0xF000180C)->bit29

// GPTA0 Filter and Prescaler Cell Control Register 0
#define GPTA0_FPCCTR0          (*((uword volatile *) 0xF0001848))
#define GPTA0_FPCCTR0_RTG        ((T_Reg32 *) 0xF0001848)->bit24

// GPTA0 Filter and Prescaler Cell Control Register 1
#define GPTA0_FPCCTR1          (*((uword volatile *) 0xF0001850))
#define GPTA0_FPCCTR1_RTG        ((T_Reg32 *) 0xF0001850)->bit24

// GPTA0 Filter and Prescaler Cell Control Register 2
#define GPTA0_FPCCTR2          (*((uword volatile *) 0xF0001858))
#define GPTA0_FPCCTR2_RTG        ((T_Reg32 *) 0xF0001858)->bit24

// GPTA0 Filter and Prescaler Cell Control Register 3
#define GPTA0_FPCCTR3          (*((uword volatile *) 0xF0001860))
#define GPTA0_FPCCTR3_RTG        ((T_Reg32 *) 0xF0001860)->bit24

// GPTA0 Filter and Prescaler Cell Control Register 4
#define GPTA0_FPCCTR4          (*((uword volatile *) 0xF0001868))
#define GPTA0_FPCCTR4_RTG        ((T_Reg32 *) 0xF0001868)->bit24

// GPTA0 Filter and Prescaler Cell Control Register 5
#define GPTA0_FPCCTR5          (*((uword volatile *) 0xF0001870))
#define GPTA0_FPCCTR5_RTG        ((T_Reg32 *) 0xF0001870)->bit24

// GPTA0 Filter and Prescaler Cell Status Register
#define GPTA0_FPCSTAT          (*((uword volatile *) 0xF0001844))
#define GPTA0_FPCSTAT_FEG0       ((T_Reg32 *) 0xF0001844)->bit8
#define GPTA0_FPCSTAT_FEG1       ((T_Reg32 *) 0xF0001844)->bit9
#define GPTA0_FPCSTAT_FEG2       ((T_Reg32 *) 0xF0001844)->bit10
#define GPTA0_FPCSTAT_FEG3       ((T_Reg32 *) 0xF0001844)->bit11
#define GPTA0_FPCSTAT_FEG4       ((T_Reg32 *) 0xF0001844)->bit12
#define GPTA0_FPCSTAT_FEG5       ((T_Reg32 *) 0xF0001844)->bit13
#define GPTA0_FPCSTAT_REG0       ((T_Reg32 *) 0xF0001844)->bit0
#define GPTA0_FPCSTAT_REG1       ((T_Reg32 *) 0xF0001844)->bit1
#define GPTA0_FPCSTAT_REG2       ((T_Reg32 *) 0xF0001844)->bit2
#define GPTA0_FPCSTAT_REG3       ((T_Reg32 *) 0xF0001844)->bit3
#define GPTA0_FPCSTAT_REG4       ((T_Reg32 *) 0xF0001844)->bit4
#define GPTA0_FPCSTAT_REG5       ((T_Reg32 *) 0xF0001844)->bit5

// GPTA0 Filter and Prescaler Cell Timer Register 0
#define GPTA0_FPCTIM0          (*((uword volatile *) 0xF000184C))

// GPTA0 Filter and Prescaler Cell Timer Register 1
#define GPTA0_FPCTIM1          (*((uword volatile *) 0xF0001854))

// GPTA0 Filter and Prescaler Cell Timer Register 2
#define GPTA0_FPCTIM2          (*((uword volatile *) 0xF000185C))

// GPTA0 Filter and Prescaler Cell Timer Register 3
#define GPTA0_FPCTIM3          (*((uword volatile *) 0xF0001864))

// GPTA0 Filter and Prescaler Cell Timer Register 4
#define GPTA0_FPCTIM4          (*((uword volatile *) 0xF000186C))

// GPTA0 Filter and Prescaler Cell Timer Register 5
#define GPTA0_FPCTIM5          (*((uword volatile *) 0xF0001874))

// GPTA0 Global Timer Cell Control Register 00
#define GPTA0_GTCCTR00         (*((uword volatile *) 0xF0001900))
#define GPTA0_GTCCTR00_BYP       ((T_Reg32 *) 0xF0001900)->bit7
#define GPTA0_GTCCTR00_CEN       ((T_Reg32 *) 0xF0001900)->bit10
#define GPTA0_GTCCTR00_EOA       ((T_Reg32 *) 0xF0001900)->bit8
#define GPTA0_GTCCTR00_FED       ((T_Reg32 *) 0xF0001900)->bit5
#define GPTA0_GTCCTR00_NE        ((T_Reg32 *) 0xF0001900)->bit6
#define GPTA0_GTCCTR00_OIA       ((T_Reg32 *) 0xF0001900)->bit14
#define GPTA0_GTCCTR00_OSM       ((T_Reg32 *) 0xF0001900)->bit2
#define GPTA0_GTCCTR00_OUT       ((T_Reg32 *) 0xF0001900)->bit15
#define GPTA0_GTCCTR00_RED       ((T_Reg32 *) 0xF0001900)->bit4
#define GPTA0_GTCCTR00_REN       ((T_Reg32 *) 0xF0001900)->bit3

// GPTA0 Global Timer Cell Control Register 01
#define GPTA0_GTCCTR01         (*((uword volatile *) 0xF0001908))
#define GPTA0_GTCCTR01_BYP       ((T_Reg32 *) 0xF0001908)->bit7
#define GPTA0_GTCCTR01_CEN       ((T_Reg32 *) 0xF0001908)->bit10
#define GPTA0_GTCCTR01_EOA       ((T_Reg32 *) 0xF0001908)->bit8
#define GPTA0_GTCCTR01_FED       ((T_Reg32 *) 0xF0001908)->bit5
#define GPTA0_GTCCTR01_NE        ((T_Reg32 *) 0xF0001908)->bit6
#define GPTA0_GTCCTR01_OIA       ((T_Reg32 *) 0xF0001908)->bit14
#define GPTA0_GTCCTR01_OSM       ((T_Reg32 *) 0xF0001908)->bit2
#define GPTA0_GTCCTR01_OUT       ((T_Reg32 *) 0xF0001908)->bit15
#define GPTA0_GTCCTR01_RED       ((T_Reg32 *) 0xF0001908)->bit4
#define GPTA0_GTCCTR01_REN       ((T_Reg32 *) 0xF0001908)->bit3

// GPTA0 Global Timer Cell Control Register 02
#define GPTA0_GTCCTR02         (*((uword volatile *) 0xF0001910))
#define GPTA0_GTCCTR02_BYP       ((T_Reg32 *) 0xF0001910)->bit7
#define GPTA0_GTCCTR02_CEN       ((T_Reg32 *) 0xF0001910)->bit10
#define GPTA0_GTCCTR02_EOA       ((T_Reg32 *) 0xF0001910)->bit8
#define GPTA0_GTCCTR02_FED       ((T_Reg32 *) 0xF0001910)->bit5
#define GPTA0_GTCCTR02_NE        ((T_Reg32 *) 0xF0001910)->bit6
#define GPTA0_GTCCTR02_OIA       ((T_Reg32 *) 0xF0001910)->bit14
#define GPTA0_GTCCTR02_OSM       ((T_Reg32 *) 0xF0001910)->bit2
#define GPTA0_GTCCTR02_OUT       ((T_Reg32 *) 0xF0001910)->bit15
#define GPTA0_GTCCTR02_RED       ((T_Reg32 *) 0xF0001910)->bit4
#define GPTA0_GTCCTR02_REN       ((T_Reg32 *) 0xF0001910)->bit3

// GPTA0 Global Timer Cell Control Register 03
#define GPTA0_GTCCTR03         (*((uword volatile *) 0xF0001918))
#define GPTA0_GTCCTR03_BYP       ((T_Reg32 *) 0xF0001918)->bit7
#define GPTA0_GTCCTR03_CEN       ((T_Reg32 *) 0xF0001918)->bit10
#define GPTA0_GTCCTR03_EOA       ((T_Reg32 *) 0xF0001918)->bit8
#define GPTA0_GTCCTR03_FED       ((T_Reg32 *) 0xF0001918)->bit5
#define GPTA0_GTCCTR03_NE        ((T_Reg32 *) 0xF0001918)->bit6
#define GPTA0_GTCCTR03_OIA       ((T_Reg32 *) 0xF0001918)->bit14
#define GPTA0_GTCCTR03_OSM       ((T_Reg32 *) 0xF0001918)->bit2
#define GPTA0_GTCCTR03_OUT       ((T_Reg32 *) 0xF0001918)->bit15
#define GPTA0_GTCCTR03_RED       ((T_Reg32 *) 0xF0001918)->bit4
#define GPTA0_GTCCTR03_REN       ((T_Reg32 *) 0xF0001918)->bit3

// GPTA0 Global Timer Cell Control Register 04
#define GPTA0_GTCCTR04         (*((uword volatile *) 0xF0001920))
#define GPTA0_GTCCTR04_BYP       ((T_Reg32 *) 0xF0001920)->bit7
#define GPTA0_GTCCTR04_CEN       ((T_Reg32 *) 0xF0001920)->bit10
#define GPTA0_GTCCTR04_EOA       ((T_Reg32 *) 0xF0001920)->bit8
#define GPTA0_GTCCTR04_FED       ((T_Reg32 *) 0xF0001920)->bit5
#define GPTA0_GTCCTR04_NE        ((T_Reg32 *) 0xF0001920)->bit6
#define GPTA0_GTCCTR04_OIA       ((T_Reg32 *) 0xF0001920)->bit14
#define GPTA0_GTCCTR04_OSM       ((T_Reg32 *) 0xF0001920)->bit2
#define GPTA0_GTCCTR04_OUT       ((T_Reg32 *) 0xF0001920)->bit15
#define GPTA0_GTCCTR04_RED       ((T_Reg32 *) 0xF0001920)->bit4
#define GPTA0_GTCCTR04_REN       ((T_Reg32 *) 0xF0001920)->bit3

// GPTA0 Global Timer Cell Control Register 05
#define GPTA0_GTCCTR05         (*((uword volatile *) 0xF0001928))
#define GPTA0_GTCCTR05_BYP       ((T_Reg32 *) 0xF0001928)->bit7
#define GPTA0_GTCCTR05_CEN       ((T_Reg32 *) 0xF0001928)->bit10
#define GPTA0_GTCCTR05_EOA       ((T_Reg32 *) 0xF0001928)->bit8
#define GPTA0_GTCCTR05_FED       ((T_Reg32 *) 0xF0001928)->bit5
#define GPTA0_GTCCTR05_NE        ((T_Reg32 *) 0xF0001928)->bit6
#define GPTA0_GTCCTR05_OIA       ((T_Reg32 *) 0xF0001928)->bit14
#define GPTA0_GTCCTR05_OSM       ((T_Reg32 *) 0xF0001928)->bit2
#define GPTA0_GTCCTR05_OUT       ((T_Reg32 *) 0xF0001928)->bit15
#define GPTA0_GTCCTR05_RED       ((T_Reg32 *) 0xF0001928)->bit4
#define GPTA0_GTCCTR05_REN       ((T_Reg32 *) 0xF0001928)->bit3

// GPTA0 Global Timer Cell Control Register 06
#define GPTA0_GTCCTR06         (*((uword volatile *) 0xF0001930))
#define GPTA0_GTCCTR06_BYP       ((T_Reg32 *) 0xF0001930)->bit7
#define GPTA0_GTCCTR06_CEN       ((T_Reg32 *) 0xF0001930)->bit10
#define GPTA0_GTCCTR06_EOA       ((T_Reg32 *) 0xF0001930)->bit8
#define GPTA0_GTCCTR06_FED       ((T_Reg32 *) 0xF0001930)->bit5
#define GPTA0_GTCCTR06_NE        ((T_Reg32 *) 0xF0001930)->bit6
#define GPTA0_GTCCTR06_OIA       ((T_Reg32 *) 0xF0001930)->bit14
#define GPTA0_GTCCTR06_OSM       ((T_Reg32 *) 0xF0001930)->bit2
#define GPTA0_GTCCTR06_OUT       ((T_Reg32 *) 0xF0001930)->bit15
#define GPTA0_GTCCTR06_RED       ((T_Reg32 *) 0xF0001930)->bit4
#define GPTA0_GTCCTR06_REN       ((T_Reg32 *) 0xF0001930)->bit3

// GPTA0 Global Timer Cell Control Register 07
#define GPTA0_GTCCTR07         (*((uword volatile *) 0xF0001938))
#define GPTA0_GTCCTR07_BYP       ((T_Reg32 *) 0xF0001938)->bit7
#define GPTA0_GTCCTR07_CEN       ((T_Reg32 *) 0xF0001938)->bit10
#define GPTA0_GTCCTR07_EOA       ((T_Reg32 *) 0xF0001938)->bit8
#define GPTA0_GTCCTR07_FED       ((T_Reg32 *) 0xF0001938)->bit5
#define GPTA0_GTCCTR07_NE        ((T_Reg32 *) 0xF0001938)->bit6
#define GPTA0_GTCCTR07_OIA       ((T_Reg32 *) 0xF0001938)->bit14
#define GPTA0_GTCCTR07_OSM       ((T_Reg32 *) 0xF0001938)->bit2
#define GPTA0_GTCCTR07_OUT       ((T_Reg32 *) 0xF0001938)->bit15
#define GPTA0_GTCCTR07_RED       ((T_Reg32 *) 0xF0001938)->bit4
#define GPTA0_GTCCTR07_REN       ((T_Reg32 *) 0xF0001938)->bit3

// GPTA0 Global Timer Cell Control Register 08
#define GPTA0_GTCCTR08         (*((uword volatile *) 0xF0001940))
#define GPTA0_GTCCTR08_BYP       ((T_Reg32 *) 0xF0001940)->bit7
#define GPTA0_GTCCTR08_CEN       ((T_Reg32 *) 0xF0001940)->bit10
#define GPTA0_GTCCTR08_EOA       ((T_Reg32 *) 0xF0001940)->bit8
#define GPTA0_GTCCTR08_FED       ((T_Reg32 *) 0xF0001940)->bit5
#define GPTA0_GTCCTR08_NE        ((T_Reg32 *) 0xF0001940)->bit6
#define GPTA0_GTCCTR08_OIA       ((T_Reg32 *) 0xF0001940)->bit14
#define GPTA0_GTCCTR08_OSM       ((T_Reg32 *) 0xF0001940)->bit2
#define GPTA0_GTCCTR08_OUT       ((T_Reg32 *) 0xF0001940)->bit15
#define GPTA0_GTCCTR08_RED       ((T_Reg32 *) 0xF0001940)->bit4
#define GPTA0_GTCCTR08_REN       ((T_Reg32 *) 0xF0001940)->bit3

// GPTA0 Global Timer Cell Control Register 09
#define GPTA0_GTCCTR09         (*((uword volatile *) 0xF0001948))
#define GPTA0_GTCCTR09_BYP       ((T_Reg32 *) 0xF0001948)->bit7
#define GPTA0_GTCCTR09_CEN       ((T_Reg32 *) 0xF0001948)->bit10
#define GPTA0_GTCCTR09_EOA       ((T_Reg32 *) 0xF0001948)->bit8
#define GPTA0_GTCCTR09_FED       ((T_Reg32 *) 0xF0001948)->bit5
#define GPTA0_GTCCTR09_NE        ((T_Reg32 *) 0xF0001948)->bit6
#define GPTA0_GTCCTR09_OIA       ((T_Reg32 *) 0xF0001948)->bit14
#define GPTA0_GTCCTR09_OSM       ((T_Reg32 *) 0xF0001948)->bit2
#define GPTA0_GTCCTR09_OUT       ((T_Reg32 *) 0xF0001948)->bit15
#define GPTA0_GTCCTR09_RED       ((T_Reg32 *) 0xF0001948)->bit4
#define GPTA0_GTCCTR09_REN       ((T_Reg32 *) 0xF0001948)->bit3

// GPTA0 Global Timer Cell Control Register 10
#define GPTA0_GTCCTR10         (*((uword volatile *) 0xF0001950))
#define GPTA0_GTCCTR10_BYP       ((T_Reg32 *) 0xF0001950)->bit7
#define GPTA0_GTCCTR10_CEN       ((T_Reg32 *) 0xF0001950)->bit10
#define GPTA0_GTCCTR10_EOA       ((T_Reg32 *) 0xF0001950)->bit8
#define GPTA0_GTCCTR10_FED       ((T_Reg32 *) 0xF0001950)->bit5
#define GPTA0_GTCCTR10_NE        ((T_Reg32 *) 0xF0001950)->bit6
#define GPTA0_GTCCTR10_OIA       ((T_Reg32 *) 0xF0001950)->bit14
#define GPTA0_GTCCTR10_OSM       ((T_Reg32 *) 0xF0001950)->bit2
#define GPTA0_GTCCTR10_OUT       ((T_Reg32 *) 0xF0001950)->bit15
#define GPTA0_GTCCTR10_RED       ((T_Reg32 *) 0xF0001950)->bit4
#define GPTA0_GTCCTR10_REN       ((T_Reg32 *) 0xF0001950)->bit3

// GPTA0 Global Timer Cell Control Register 11
#define GPTA0_GTCCTR11         (*((uword volatile *) 0xF0001958))
#define GPTA0_GTCCTR11_BYP       ((T_Reg32 *) 0xF0001958)->bit7
#define GPTA0_GTCCTR11_CEN       ((T_Reg32 *) 0xF0001958)->bit10
#define GPTA0_GTCCTR11_EOA       ((T_Reg32 *) 0xF0001958)->bit8
#define GPTA0_GTCCTR11_FED       ((T_Reg32 *) 0xF0001958)->bit5
#define GPTA0_GTCCTR11_NE        ((T_Reg32 *) 0xF0001958)->bit6
#define GPTA0_GTCCTR11_OIA       ((T_Reg32 *) 0xF0001958)->bit14
#define GPTA0_GTCCTR11_OSM       ((T_Reg32 *) 0xF0001958)->bit2
#define GPTA0_GTCCTR11_OUT       ((T_Reg32 *) 0xF0001958)->bit15
#define GPTA0_GTCCTR11_RED       ((T_Reg32 *) 0xF0001958)->bit4
#define GPTA0_GTCCTR11_REN       ((T_Reg32 *) 0xF0001958)->bit3

// GPTA0 Global Timer Cell Control Register 12
#define GPTA0_GTCCTR12         (*((uword volatile *) 0xF0001960))
#define GPTA0_GTCCTR12_BYP       ((T_Reg32 *) 0xF0001960)->bit7
#define GPTA0_GTCCTR12_CEN       ((T_Reg32 *) 0xF0001960)->bit10
#define GPTA0_GTCCTR12_EOA       ((T_Reg32 *) 0xF0001960)->bit8
#define GPTA0_GTCCTR12_FED       ((T_Reg32 *) 0xF0001960)->bit5
#define GPTA0_GTCCTR12_NE        ((T_Reg32 *) 0xF0001960)->bit6
#define GPTA0_GTCCTR12_OIA       ((T_Reg32 *) 0xF0001960)->bit14
#define GPTA0_GTCCTR12_OSM       ((T_Reg32 *) 0xF0001960)->bit2
#define GPTA0_GTCCTR12_OUT       ((T_Reg32 *) 0xF0001960)->bit15
#define GPTA0_GTCCTR12_RED       ((T_Reg32 *) 0xF0001960)->bit4
#define GPTA0_GTCCTR12_REN       ((T_Reg32 *) 0xF0001960)->bit3

// GPTA0 Global Timer Cell Control Register 13
#define GPTA0_GTCCTR13         (*((uword volatile *) 0xF0001968))
#define GPTA0_GTCCTR13_BYP       ((T_Reg32 *) 0xF0001968)->bit7
#define GPTA0_GTCCTR13_CEN       ((T_Reg32 *) 0xF0001968)->bit10
#define GPTA0_GTCCTR13_EOA       ((T_Reg32 *) 0xF0001968)->bit8
#define GPTA0_GTCCTR13_FED       ((T_Reg32 *) 0xF0001968)->bit5
#define GPTA0_GTCCTR13_NE        ((T_Reg32 *) 0xF0001968)->bit6
#define GPTA0_GTCCTR13_OIA       ((T_Reg32 *) 0xF0001968)->bit14
#define GPTA0_GTCCTR13_OSM       ((T_Reg32 *) 0xF0001968)->bit2
#define GPTA0_GTCCTR13_OUT       ((T_Reg32 *) 0xF0001968)->bit15
#define GPTA0_GTCCTR13_RED       ((T_Reg32 *) 0xF0001968)->bit4
#define GPTA0_GTCCTR13_REN       ((T_Reg32 *) 0xF0001968)->bit3

// GPTA0 Global Timer Cell Control Register 14
#define GPTA0_GTCCTR14         (*((uword volatile *) 0xF0001970))
#define GPTA0_GTCCTR14_BYP       ((T_Reg32 *) 0xF0001970)->bit7
#define GPTA0_GTCCTR14_CEN       ((T_Reg32 *) 0xF0001970)->bit10
#define GPTA0_GTCCTR14_EOA       ((T_Reg32 *) 0xF0001970)->bit8
#define GPTA0_GTCCTR14_FED       ((T_Reg32 *) 0xF0001970)->bit5
#define GPTA0_GTCCTR14_NE        ((T_Reg32 *) 0xF0001970)->bit6
#define GPTA0_GTCCTR14_OIA       ((T_Reg32 *) 0xF0001970)->bit14
#define GPTA0_GTCCTR14_OSM       ((T_Reg32 *) 0xF0001970)->bit2
#define GPTA0_GTCCTR14_OUT       ((T_Reg32 *) 0xF0001970)->bit15
#define GPTA0_GTCCTR14_RED       ((T_Reg32 *) 0xF0001970)->bit4
#define GPTA0_GTCCTR14_REN       ((T_Reg32 *) 0xF0001970)->bit3

// GPTA0 Global Timer Cell Control Register 15
#define GPTA0_GTCCTR15         (*((uword volatile *) 0xF0001978))
#define GPTA0_GTCCTR15_BYP       ((T_Reg32 *) 0xF0001978)->bit7
#define GPTA0_GTCCTR15_CEN       ((T_Reg32 *) 0xF0001978)->bit10
#define GPTA0_GTCCTR15_EOA       ((T_Reg32 *) 0xF0001978)->bit8
#define GPTA0_GTCCTR15_FED       ((T_Reg32 *) 0xF0001978)->bit5
#define GPTA0_GTCCTR15_NE        ((T_Reg32 *) 0xF0001978)->bit6
#define GPTA0_GTCCTR15_OIA       ((T_Reg32 *) 0xF0001978)->bit14
#define GPTA0_GTCCTR15_OSM       ((T_Reg32 *) 0xF0001978)->bit2
#define GPTA0_GTCCTR15_OUT       ((T_Reg32 *) 0xF0001978)->bit15
#define GPTA0_GTCCTR15_RED       ((T_Reg32 *) 0xF0001978)->bit4
#define GPTA0_GTCCTR15_REN       ((T_Reg32 *) 0xF0001978)->bit3

// GPTA0 Global Timer Cell Control Register 16
#define GPTA0_GTCCTR16         (*((uword volatile *) 0xF0001980))
#define GPTA0_GTCCTR16_BYP       ((T_Reg32 *) 0xF0001980)->bit7
#define GPTA0_GTCCTR16_CEN       ((T_Reg32 *) 0xF0001980)->bit10
#define GPTA0_GTCCTR16_EOA       ((T_Reg32 *) 0xF0001980)->bit8
#define GPTA0_GTCCTR16_FED       ((T_Reg32 *) 0xF0001980)->bit5
#define GPTA0_GTCCTR16_NE        ((T_Reg32 *) 0xF0001980)->bit6
#define GPTA0_GTCCTR16_OIA       ((T_Reg32 *) 0xF0001980)->bit14
#define GPTA0_GTCCTR16_OSM       ((T_Reg32 *) 0xF0001980)->bit2
#define GPTA0_GTCCTR16_OUT       ((T_Reg32 *) 0xF0001980)->bit15
#define GPTA0_GTCCTR16_RED       ((T_Reg32 *) 0xF0001980)->bit4
#define GPTA0_GTCCTR16_REN       ((T_Reg32 *) 0xF0001980)->bit3

// GPTA0 Global Timer Cell Control Register 17
#define GPTA0_GTCCTR17         (*((uword volatile *) 0xF0001988))
#define GPTA0_GTCCTR17_BYP       ((T_Reg32 *) 0xF0001988)->bit7
#define GPTA0_GTCCTR17_CEN       ((T_Reg32 *) 0xF0001988)->bit10
#define GPTA0_GTCCTR17_EOA       ((T_Reg32 *) 0xF0001988)->bit8
#define GPTA0_GTCCTR17_FED       ((T_Reg32 *) 0xF0001988)->bit5
#define GPTA0_GTCCTR17_NE        ((T_Reg32 *) 0xF0001988)->bit6
#define GPTA0_GTCCTR17_OIA       ((T_Reg32 *) 0xF0001988)->bit14
#define GPTA0_GTCCTR17_OSM       ((T_Reg32 *) 0xF0001988)->bit2
#define GPTA0_GTCCTR17_OUT       ((T_Reg32 *) 0xF0001988)->bit15
#define GPTA0_GTCCTR17_RED       ((T_Reg32 *) 0xF0001988)->bit4
#define GPTA0_GTCCTR17_REN       ((T_Reg32 *) 0xF0001988)->bit3

// GPTA0 Global Timer Cell Control Register 18
#define GPTA0_GTCCTR18         (*((uword volatile *) 0xF0001990))
#define GPTA0_GTCCTR18_BYP       ((T_Reg32 *) 0xF0001990)->bit7
#define GPTA0_GTCCTR18_CEN       ((T_Reg32 *) 0xF0001990)->bit10
#define GPTA0_GTCCTR18_EOA       ((T_Reg32 *) 0xF0001990)->bit8
#define GPTA0_GTCCTR18_FED       ((T_Reg32 *) 0xF0001990)->bit5
#define GPTA0_GTCCTR18_NE        ((T_Reg32 *) 0xF0001990)->bit6
#define GPTA0_GTCCTR18_OIA       ((T_Reg32 *) 0xF0001990)->bit14
#define GPTA0_GTCCTR18_OSM       ((T_Reg32 *) 0xF0001990)->bit2
#define GPTA0_GTCCTR18_OUT       ((T_Reg32 *) 0xF0001990)->bit15
#define GPTA0_GTCCTR18_RED       ((T_Reg32 *) 0xF0001990)->bit4
#define GPTA0_GTCCTR18_REN       ((T_Reg32 *) 0xF0001990)->bit3

// GPTA0 Global Timer Cell Control Register 19
#define GPTA0_GTCCTR19         (*((uword volatile *) 0xF0001998))
#define GPTA0_GTCCTR19_BYP       ((T_Reg32 *) 0xF0001998)->bit7
#define GPTA0_GTCCTR19_CEN       ((T_Reg32 *) 0xF0001998)->bit10
#define GPTA0_GTCCTR19_EOA       ((T_Reg32 *) 0xF0001998)->bit8
#define GPTA0_GTCCTR19_FED       ((T_Reg32 *) 0xF0001998)->bit5
#define GPTA0_GTCCTR19_NE        ((T_Reg32 *) 0xF0001998)->bit6
#define GPTA0_GTCCTR19_OIA       ((T_Reg32 *) 0xF0001998)->bit14
#define GPTA0_GTCCTR19_OSM       ((T_Reg32 *) 0xF0001998)->bit2
#define GPTA0_GTCCTR19_OUT       ((T_Reg32 *) 0xF0001998)->bit15
#define GPTA0_GTCCTR19_RED       ((T_Reg32 *) 0xF0001998)->bit4
#define GPTA0_GTCCTR19_REN       ((T_Reg32 *) 0xF0001998)->bit3

// GPTA0 Global Timer Cell Control Register 20
#define GPTA0_GTCCTR20         (*((uword volatile *) 0xF00019A0))
#define GPTA0_GTCCTR20_BYP       ((T_Reg32 *) 0xF00019A0)->bit7
#define GPTA0_GTCCTR20_CEN       ((T_Reg32 *) 0xF00019A0)->bit10
#define GPTA0_GTCCTR20_EOA       ((T_Reg32 *) 0xF00019A0)->bit8
#define GPTA0_GTCCTR20_FED       ((T_Reg32 *) 0xF00019A0)->bit5
#define GPTA0_GTCCTR20_NE        ((T_Reg32 *) 0xF00019A0)->bit6
#define GPTA0_GTCCTR20_OIA       ((T_Reg32 *) 0xF00019A0)->bit14
#define GPTA0_GTCCTR20_OSM       ((T_Reg32 *) 0xF00019A0)->bit2
#define GPTA0_GTCCTR20_OUT       ((T_Reg32 *) 0xF00019A0)->bit15
#define GPTA0_GTCCTR20_RED       ((T_Reg32 *) 0xF00019A0)->bit4
#define GPTA0_GTCCTR20_REN       ((T_Reg32 *) 0xF00019A0)->bit3

// GPTA0 Global Timer Cell Control Register 21
#define GPTA0_GTCCTR21         (*((uword volatile *) 0xF00019A8))
#define GPTA0_GTCCTR21_BYP       ((T_Reg32 *) 0xF00019A8)->bit7
#define GPTA0_GTCCTR21_CEN       ((T_Reg32 *) 0xF00019A8)->bit10
#define GPTA0_GTCCTR21_EOA       ((T_Reg32 *) 0xF00019A8)->bit8
#define GPTA0_GTCCTR21_FED       ((T_Reg32 *) 0xF00019A8)->bit5
#define GPTA0_GTCCTR21_NE        ((T_Reg32 *) 0xF00019A8)->bit6
#define GPTA0_GTCCTR21_OIA       ((T_Reg32 *) 0xF00019A8)->bit14
#define GPTA0_GTCCTR21_OSM       ((T_Reg32 *) 0xF00019A8)->bit2
#define GPTA0_GTCCTR21_OUT       ((T_Reg32 *) 0xF00019A8)->bit15
#define GPTA0_GTCCTR21_RED       ((T_Reg32 *) 0xF00019A8)->bit4
#define GPTA0_GTCCTR21_REN       ((T_Reg32 *) 0xF00019A8)->bit3

// GPTA0 Global Timer Cell Control Register 22
#define GPTA0_GTCCTR22         (*((uword volatile *) 0xF00019B0))
#define GPTA0_GTCCTR22_BYP       ((T_Reg32 *) 0xF00019B0)->bit7
#define GPTA0_GTCCTR22_CEN       ((T_Reg32 *) 0xF00019B0)->bit10
#define GPTA0_GTCCTR22_EOA       ((T_Reg32 *) 0xF00019B0)->bit8
#define GPTA0_GTCCTR22_FED       ((T_Reg32 *) 0xF00019B0)->bit5
#define GPTA0_GTCCTR22_NE        ((T_Reg32 *) 0xF00019B0)->bit6
#define GPTA0_GTCCTR22_OIA       ((T_Reg32 *) 0xF00019B0)->bit14
#define GPTA0_GTCCTR22_OSM       ((T_Reg32 *) 0xF00019B0)->bit2
#define GPTA0_GTCCTR22_OUT       ((T_Reg32 *) 0xF00019B0)->bit15
#define GPTA0_GTCCTR22_RED       ((T_Reg32 *) 0xF00019B0)->bit4
#define GPTA0_GTCCTR22_REN       ((T_Reg32 *) 0xF00019B0)->bit3

// GPTA0 Global Timer Cell Control Register 23
#define GPTA0_GTCCTR23         (*((uword volatile *) 0xF00019B8))
#define GPTA0_GTCCTR23_BYP       ((T_Reg32 *) 0xF00019B8)->bit7
#define GPTA0_GTCCTR23_CEN       ((T_Reg32 *) 0xF00019B8)->bit10
#define GPTA0_GTCCTR23_EOA       ((T_Reg32 *) 0xF00019B8)->bit8
#define GPTA0_GTCCTR23_FED       ((T_Reg32 *) 0xF00019B8)->bit5
#define GPTA0_GTCCTR23_NE        ((T_Reg32 *) 0xF00019B8)->bit6
#define GPTA0_GTCCTR23_OIA       ((T_Reg32 *) 0xF00019B8)->bit14
#define GPTA0_GTCCTR23_OSM       ((T_Reg32 *) 0xF00019B8)->bit2
#define GPTA0_GTCCTR23_OUT       ((T_Reg32 *) 0xF00019B8)->bit15
#define GPTA0_GTCCTR23_RED       ((T_Reg32 *) 0xF00019B8)->bit4
#define GPTA0_GTCCTR23_REN       ((T_Reg32 *) 0xF00019B8)->bit3

// GPTA0 Global Timer Cell Control Register 24
#define GPTA0_GTCCTR24         (*((uword volatile *) 0xF00019C0))
#define GPTA0_GTCCTR24_BYP       ((T_Reg32 *) 0xF00019C0)->bit7
#define GPTA0_GTCCTR24_CEN       ((T_Reg32 *) 0xF00019C0)->bit10
#define GPTA0_GTCCTR24_EOA       ((T_Reg32 *) 0xF00019C0)->bit8
#define GPTA0_GTCCTR24_FED       ((T_Reg32 *) 0xF00019C0)->bit5
#define GPTA0_GTCCTR24_NE        ((T_Reg32 *) 0xF00019C0)->bit6
#define GPTA0_GTCCTR24_OIA       ((T_Reg32 *) 0xF00019C0)->bit14
#define GPTA0_GTCCTR24_OSM       ((T_Reg32 *) 0xF00019C0)->bit2
#define GPTA0_GTCCTR24_OUT       ((T_Reg32 *) 0xF00019C0)->bit15
#define GPTA0_GTCCTR24_RED       ((T_Reg32 *) 0xF00019C0)->bit4
#define GPTA0_GTCCTR24_REN       ((T_Reg32 *) 0xF00019C0)->bit3

// GPTA0 Global Timer Cell Control Register 25
#define GPTA0_GTCCTR25         (*((uword volatile *) 0xF00019C8))
#define GPTA0_GTCCTR25_BYP       ((T_Reg32 *) 0xF00019C8)->bit7
#define GPTA0_GTCCTR25_CEN       ((T_Reg32 *) 0xF00019C8)->bit10
#define GPTA0_GTCCTR25_EOA       ((T_Reg32 *) 0xF00019C8)->bit8
#define GPTA0_GTCCTR25_FED       ((T_Reg32 *) 0xF00019C8)->bit5
#define GPTA0_GTCCTR25_NE        ((T_Reg32 *) 0xF00019C8)->bit6
#define GPTA0_GTCCTR25_OIA       ((T_Reg32 *) 0xF00019C8)->bit14
#define GPTA0_GTCCTR25_OSM       ((T_Reg32 *) 0xF00019C8)->bit2
#define GPTA0_GTCCTR25_OUT       ((T_Reg32 *) 0xF00019C8)->bit15
#define GPTA0_GTCCTR25_RED       ((T_Reg32 *) 0xF00019C8)->bit4
#define GPTA0_GTCCTR25_REN       ((T_Reg32 *) 0xF00019C8)->bit3

// GPTA0 Global Timer Cell Control Register 26
#define GPTA0_GTCCTR26         (*((uword volatile *) 0xF00019D0))
#define GPTA0_GTCCTR26_BYP       ((T_Reg32 *) 0xF00019D0)->bit7
#define GPTA0_GTCCTR26_CEN       ((T_Reg32 *) 0xF00019D0)->bit10
#define GPTA0_GTCCTR26_EOA       ((T_Reg32 *) 0xF00019D0)->bit8
#define GPTA0_GTCCTR26_FED       ((T_Reg32 *) 0xF00019D0)->bit5
#define GPTA0_GTCCTR26_NE        ((T_Reg32 *) 0xF00019D0)->bit6
#define GPTA0_GTCCTR26_OIA       ((T_Reg32 *) 0xF00019D0)->bit14
#define GPTA0_GTCCTR26_OSM       ((T_Reg32 *) 0xF00019D0)->bit2
#define GPTA0_GTCCTR26_OUT       ((T_Reg32 *) 0xF00019D0)->bit15
#define GPTA0_GTCCTR26_RED       ((T_Reg32 *) 0xF00019D0)->bit4
#define GPTA0_GTCCTR26_REN       ((T_Reg32 *) 0xF00019D0)->bit3

// GPTA0 Global Timer Cell Control Register 27
#define GPTA0_GTCCTR27         (*((uword volatile *) 0xF00019D8))
#define GPTA0_GTCCTR27_BYP       ((T_Reg32 *) 0xF00019D8)->bit7
#define GPTA0_GTCCTR27_CEN       ((T_Reg32 *) 0xF00019D8)->bit10
#define GPTA0_GTCCTR27_EOA       ((T_Reg32 *) 0xF00019D8)->bit8
#define GPTA0_GTCCTR27_FED       ((T_Reg32 *) 0xF00019D8)->bit5
#define GPTA0_GTCCTR27_NE        ((T_Reg32 *) 0xF00019D8)->bit6
#define GPTA0_GTCCTR27_OIA       ((T_Reg32 *) 0xF00019D8)->bit14
#define GPTA0_GTCCTR27_OSM       ((T_Reg32 *) 0xF00019D8)->bit2
#define GPTA0_GTCCTR27_OUT       ((T_Reg32 *) 0xF00019D8)->bit15
#define GPTA0_GTCCTR27_RED       ((T_Reg32 *) 0xF00019D8)->bit4
#define GPTA0_GTCCTR27_REN       ((T_Reg32 *) 0xF00019D8)->bit3

// GPTA0 Global Timer Cell Control Register 28
#define GPTA0_GTCCTR28         (*((uword volatile *) 0xF00019E0))
#define GPTA0_GTCCTR28_BYP       ((T_Reg32 *) 0xF00019E0)->bit7
#define GPTA0_GTCCTR28_CEN       ((T_Reg32 *) 0xF00019E0)->bit10
#define GPTA0_GTCCTR28_EOA       ((T_Reg32 *) 0xF00019E0)->bit8
#define GPTA0_GTCCTR28_FED       ((T_Reg32 *) 0xF00019E0)->bit5
#define GPTA0_GTCCTR28_NE        ((T_Reg32 *) 0xF00019E0)->bit6
#define GPTA0_GTCCTR28_OIA       ((T_Reg32 *) 0xF00019E0)->bit14
#define GPTA0_GTCCTR28_OSM       ((T_Reg32 *) 0xF00019E0)->bit2
#define GPTA0_GTCCTR28_OUT       ((T_Reg32 *) 0xF00019E0)->bit15
#define GPTA0_GTCCTR28_RED       ((T_Reg32 *) 0xF00019E0)->bit4
#define GPTA0_GTCCTR28_REN       ((T_Reg32 *) 0xF00019E0)->bit3

// GPTA0 Global Timer Cell Control Register 29
#define GPTA0_GTCCTR29         (*((uword volatile *) 0xF00019E8))
#define GPTA0_GTCCTR29_BYP       ((T_Reg32 *) 0xF00019E8)->bit7
#define GPTA0_GTCCTR29_CEN       ((T_Reg32 *) 0xF00019E8)->bit10
#define GPTA0_GTCCTR29_EOA       ((T_Reg32 *) 0xF00019E8)->bit8
#define GPTA0_GTCCTR29_FED       ((T_Reg32 *) 0xF00019E8)->bit5
#define GPTA0_GTCCTR29_NE        ((T_Reg32 *) 0xF00019E8)->bit6
#define GPTA0_GTCCTR29_OIA       ((T_Reg32 *) 0xF00019E8)->bit14
#define GPTA0_GTCCTR29_OSM       ((T_Reg32 *) 0xF00019E8)->bit2
#define GPTA0_GTCCTR29_OUT       ((T_Reg32 *) 0xF00019E8)->bit15
#define GPTA0_GTCCTR29_RED       ((T_Reg32 *) 0xF00019E8)->bit4
#define GPTA0_GTCCTR29_REN       ((T_Reg32 *) 0xF00019E8)->bit3

// GPTA0 Global Timer Cell Control Register 30
#define GPTA0_GTCCTR30         (*((uword volatile *) 0xF00019F0))
#define GPTA0_GTCCTR30_BYP       ((T_Reg32 *) 0xF00019F0)->bit7
#define GPTA0_GTCCTR30_CEN       ((T_Reg32 *) 0xF00019F0)->bit10
#define GPTA0_GTCCTR30_EOA       ((T_Reg32 *) 0xF00019F0)->bit8
#define GPTA0_GTCCTR30_FED       ((T_Reg32 *) 0xF00019F0)->bit5
#define GPTA0_GTCCTR30_NE        ((T_Reg32 *) 0xF00019F0)->bit6
#define GPTA0_GTCCTR30_OIA       ((T_Reg32 *) 0xF00019F0)->bit14
#define GPTA0_GTCCTR30_OSM       ((T_Reg32 *) 0xF00019F0)->bit2
#define GPTA0_GTCCTR30_OUT       ((T_Reg32 *) 0xF00019F0)->bit15
#define GPTA0_GTCCTR30_RED       ((T_Reg32 *) 0xF00019F0)->bit4
#define GPTA0_GTCCTR30_REN       ((T_Reg32 *) 0xF00019F0)->bit3

// GPTA0 Global Timer Cell Control Register 31
#define GPTA0_GTCCTR31         (*((uword volatile *) 0xF00019F8))
#define GPTA0_GTCCTR31_BYP       ((T_Reg32 *) 0xF00019F8)->bit7
#define GPTA0_GTCCTR31_CEN       ((T_Reg32 *) 0xF00019F8)->bit10
#define GPTA0_GTCCTR31_EOA       ((T_Reg32 *) 0xF00019F8)->bit8
#define GPTA0_GTCCTR31_FED       ((T_Reg32 *) 0xF00019F8)->bit5
#define GPTA0_GTCCTR31_NE        ((T_Reg32 *) 0xF00019F8)->bit6
#define GPTA0_GTCCTR31_OIA       ((T_Reg32 *) 0xF00019F8)->bit14
#define GPTA0_GTCCTR31_OSM       ((T_Reg32 *) 0xF00019F8)->bit2
#define GPTA0_GTCCTR31_OUT       ((T_Reg32 *) 0xF00019F8)->bit15
#define GPTA0_GTCCTR31_RED       ((T_Reg32 *) 0xF00019F8)->bit4
#define GPTA0_GTCCTR31_REN       ((T_Reg32 *) 0xF00019F8)->bit3

// GPTA0 Global Timer Control Register 0
#define GPTA0_GTCTR0           (*((uword volatile *) 0xF00018E0))
#define GPTA0_GTCTR0_REN         ((T_Reg32 *) 0xF00018E0)->bit7

// GPTA0 Global Timer Control Register 1
#define GPTA0_GTCTR1           (*((uword volatile *) 0xF00018F0))
#define GPTA0_GTCTR1_REN         ((T_Reg32 *) 0xF00018F0)->bit7

// GPTA0 Global Timer Cell X Register 00
#define GPTA0_GTCXR00          (*((uword volatile *) 0xF0001904))

// GPTA0 Global Timer Cell X Register 01
#define GPTA0_GTCXR01          (*((uword volatile *) 0xF000190C))

// GPTA0 Global Timer Cell X Register 02
#define GPTA0_GTCXR02          (*((uword volatile *) 0xF0001914))

// GPTA0 Global Timer Cell X Register 03
#define GPTA0_GTCXR03          (*((uword volatile *) 0xF000191C))

// GPTA0 Global Timer Cell X Register 04
#define GPTA0_GTCXR04          (*((uword volatile *) 0xF0001924))

// GPTA0 Global Timer Cell X Register 05
#define GPTA0_GTCXR05          (*((uword volatile *) 0xF000192C))

// GPTA0 Global Timer Cell X Register 06
#define GPTA0_GTCXR06          (*((uword volatile *) 0xF0001934))

// GPTA0 Global Timer Cell X Register 07
#define GPTA0_GTCXR07          (*((uword volatile *) 0xF000193C))

// GPTA0 Global Timer Cell X Register 08
#define GPTA0_GTCXR08          (*((uword volatile *) 0xF0001944))

// GPTA0 Global Timer Cell X Register 09
#define GPTA0_GTCXR09          (*((uword volatile *) 0xF000194C))

// GPTA0 Global Timer Cell X Register 10
#define GPTA0_GTCXR10          (*((uword volatile *) 0xF0001954))

// GPTA0 Global Timer Cell X Register 11
#define GPTA0_GTCXR11          (*((uword volatile *) 0xF000195C))

// GPTA0 Global Timer Cell X Register 12
#define GPTA0_GTCXR12          (*((uword volatile *) 0xF0001964))

// GPTA0 Global Timer Cell X Register 13
#define GPTA0_GTCXR13          (*((uword volatile *) 0xF000196C))

// GPTA0 Global Timer Cell X Register 14
#define GPTA0_GTCXR14          (*((uword volatile *) 0xF0001974))

// GPTA0 Global Timer Cell X Register 15
#define GPTA0_GTCXR15          (*((uword volatile *) 0xF000197C))

// GPTA0 Global Timer Cell X Register 16
#define GPTA0_GTCXR16          (*((uword volatile *) 0xF0001984))

// GPTA0 Global Timer Cell X Register 17
#define GPTA0_GTCXR17          (*((uword volatile *) 0xF000198C))

// GPTA0 Global Timer Cell X Register 18
#define GPTA0_GTCXR18          (*((uword volatile *) 0xF0001994))

// GPTA0 Global Timer Cell X Register 19
#define GPTA0_GTCXR19          (*((uword volatile *) 0xF000199C))

// GPTA0 Global Timer Cell X Register 20
#define GPTA0_GTCXR20          (*((uword volatile *) 0xF00019A4))

// GPTA0 Global Timer Cell X Register 21
#define GPTA0_GTCXR21          (*((uword volatile *) 0xF00019AC))

// GPTA0 Global Timer Cell X Register 22
#define GPTA0_GTCXR22          (*((uword volatile *) 0xF00019B4))

// GPTA0 Global Timer Cell X Register 23
#define GPTA0_GTCXR23          (*((uword volatile *) 0xF00019BC))

// GPTA0 Global Timer Cell X Register 24
#define GPTA0_GTCXR24          (*((uword volatile *) 0xF00019C4))

// GPTA0 Global Timer Cell X Register 25
#define GPTA0_GTCXR25          (*((uword volatile *) 0xF00019CC))

// GPTA0 Global Timer Cell X Register 26
#define GPTA0_GTCXR26          (*((uword volatile *) 0xF00019D4))

// GPTA0 Global Timer Cell X Register 27
#define GPTA0_GTCXR27          (*((uword volatile *) 0xF00019DC))

// GPTA0 Global Timer Cell X Register 28
#define GPTA0_GTCXR28          (*((uword volatile *) 0xF00019E4))

// GPTA0 Global Timer Cell X Register 29
#define GPTA0_GTCXR29          (*((uword volatile *) 0xF00019EC))

// GPTA0 Global Timer Cell X Register 30
#define GPTA0_GTCXR30          (*((uword volatile *) 0xF00019F4))

// GPTA0 Global Timer Cell X Register 31
#define GPTA0_GTCXR31          (*((uword volatile *) 0xF00019FC))

// GPTA0 Global Timer Reload Value Register 0
#define GPTA0_GTREV0           (*((uword volatile *) 0xF00018E4))

// GPTA0 Global Timer Reload Value Register 1
#define GPTA0_GTREV1           (*((uword volatile *) 0xF00018F4))

// GPTA0 Global Timer Register 0
#define GPTA0_GTTIM0           (*((uword volatile *) 0xF00018E8))

// GPTA0 Global Timer Register 1
#define GPTA0_GTTIM1           (*((uword volatile *) 0xF00018F8))

// GPTA0 Identification Register
#define GPTA0_ID               (*((uword volatile *) 0xF0001808))

// GPTA0 Local Timer Cell Control Register 00
#define GPTA0_LTCCTR00         (*((uword volatile *) 0xF0001A00))
#define GPTA0_LTCCTR00_CEN       ((T_Reg32 *) 0xF0001A00)->bit10
#define GPTA0_LTCCTR00_CUD       ((T_Reg32 *) 0xF0001A00)->bit9
#define GPTA0_LTCCTR00_CUDCLR    ((T_Reg32 *) 0xF0001A00)->bit7
#define GPTA0_LTCCTR00_FED       ((T_Reg32 *) 0xF0001A00)->bit5
#define GPTA0_LTCCTR00_GBYP      ((T_Reg32 *) 0xF0001A00)->bit16
#define GPTA0_LTCCTR00_ILM       ((T_Reg32 *) 0xF0001A00)->bit8
#define GPTA0_LTCCTR00_OIA       ((T_Reg32 *) 0xF0001A00)->bit14
#define GPTA0_LTCCTR00_OSM       ((T_Reg32 *) 0xF0001A00)->bit2
#define GPTA0_LTCCTR00_OUT       ((T_Reg32 *) 0xF0001A00)->bit15
#define GPTA0_LTCCTR00_RED       ((T_Reg32 *) 0xF0001A00)->bit4
#define GPTA0_LTCCTR00_REN       ((T_Reg32 *) 0xF0001A00)->bit3
#define GPTA0_LTCCTR00_SLO       ((T_Reg32 *) 0xF0001A00)->bit6

// GPTA0 Local Timer Cell Control Register 01
#define GPTA0_LTCCTR01         (*((uword volatile *) 0xF0001A08))
#define GPTA0_LTCCTR01_CEN       ((T_Reg32 *) 0xF0001A08)->bit10
#define GPTA0_LTCCTR01_CUD       ((T_Reg32 *) 0xF0001A08)->bit9
#define GPTA0_LTCCTR01_CUDCLR    ((T_Reg32 *) 0xF0001A08)->bit7
#define GPTA0_LTCCTR01_FED       ((T_Reg32 *) 0xF0001A08)->bit5
#define GPTA0_LTCCTR01_GBYP      ((T_Reg32 *) 0xF0001A08)->bit16
#define GPTA0_LTCCTR01_ILM       ((T_Reg32 *) 0xF0001A08)->bit8
#define GPTA0_LTCCTR01_OIA       ((T_Reg32 *) 0xF0001A08)->bit14
#define GPTA0_LTCCTR01_OSM       ((T_Reg32 *) 0xF0001A08)->bit2
#define GPTA0_LTCCTR01_OUT       ((T_Reg32 *) 0xF0001A08)->bit15
#define GPTA0_LTCCTR01_RED       ((T_Reg32 *) 0xF0001A08)->bit4
#define GPTA0_LTCCTR01_REN       ((T_Reg32 *) 0xF0001A08)->bit3
#define GPTA0_LTCCTR01_SLO       ((T_Reg32 *) 0xF0001A08)->bit6

// GPTA0 Local Timer Cell Control Register 02
#define GPTA0_LTCCTR02         (*((uword volatile *) 0xF0001A10))
#define GPTA0_LTCCTR02_CEN       ((T_Reg32 *) 0xF0001A10)->bit10
#define GPTA0_LTCCTR02_CUD       ((T_Reg32 *) 0xF0001A10)->bit9
#define GPTA0_LTCCTR02_CUDCLR    ((T_Reg32 *) 0xF0001A10)->bit7
#define GPTA0_LTCCTR02_FED       ((T_Reg32 *) 0xF0001A10)->bit5
#define GPTA0_LTCCTR02_GBYP      ((T_Reg32 *) 0xF0001A10)->bit16
#define GPTA0_LTCCTR02_ILM       ((T_Reg32 *) 0xF0001A10)->bit8
#define GPTA0_LTCCTR02_OIA       ((T_Reg32 *) 0xF0001A10)->bit14
#define GPTA0_LTCCTR02_OSM       ((T_Reg32 *) 0xF0001A10)->bit2
#define GPTA0_LTCCTR02_OUT       ((T_Reg32 *) 0xF0001A10)->bit15
#define GPTA0_LTCCTR02_RED       ((T_Reg32 *) 0xF0001A10)->bit4
#define GPTA0_LTCCTR02_REN       ((T_Reg32 *) 0xF0001A10)->bit3
#define GPTA0_LTCCTR02_SLO       ((T_Reg32 *) 0xF0001A10)->bit6

// GPTA0 Local Timer Cell Control Register 03
#define GPTA0_LTCCTR03         (*((uword volatile *) 0xF0001A18))
#define GPTA0_LTCCTR03_CEN       ((T_Reg32 *) 0xF0001A18)->bit10
#define GPTA0_LTCCTR03_CUD       ((T_Reg32 *) 0xF0001A18)->bit9
#define GPTA0_LTCCTR03_CUDCLR    ((T_Reg32 *) 0xF0001A18)->bit7
#define GPTA0_LTCCTR03_FED       ((T_Reg32 *) 0xF0001A18)->bit5
#define GPTA0_LTCCTR03_GBYP      ((T_Reg32 *) 0xF0001A18)->bit16
#define GPTA0_LTCCTR03_ILM       ((T_Reg32 *) 0xF0001A18)->bit8
#define GPTA0_LTCCTR03_OIA       ((T_Reg32 *) 0xF0001A18)->bit14
#define GPTA0_LTCCTR03_OSM       ((T_Reg32 *) 0xF0001A18)->bit2
#define GPTA0_LTCCTR03_OUT       ((T_Reg32 *) 0xF0001A18)->bit15
#define GPTA0_LTCCTR03_RED       ((T_Reg32 *) 0xF0001A18)->bit4
#define GPTA0_LTCCTR03_REN       ((T_Reg32 *) 0xF0001A18)->bit3
#define GPTA0_LTCCTR03_SLO       ((T_Reg32 *) 0xF0001A18)->bit6

// GPTA0 Local Timer Cell Control Register 04
#define GPTA0_LTCCTR04         (*((uword volatile *) 0xF0001A20))
#define GPTA0_LTCCTR04_CEN       ((T_Reg32 *) 0xF0001A20)->bit10
#define GPTA0_LTCCTR04_CUD       ((T_Reg32 *) 0xF0001A20)->bit9
#define GPTA0_LTCCTR04_CUDCLR    ((T_Reg32 *) 0xF0001A20)->bit7
#define GPTA0_LTCCTR04_FED       ((T_Reg32 *) 0xF0001A20)->bit5
#define GPTA0_LTCCTR04_GBYP      ((T_Reg32 *) 0xF0001A20)->bit16
#define GPTA0_LTCCTR04_ILM       ((T_Reg32 *) 0xF0001A20)->bit8
#define GPTA0_LTCCTR04_OIA       ((T_Reg32 *) 0xF0001A20)->bit14
#define GPTA0_LTCCTR04_OSM       ((T_Reg32 *) 0xF0001A20)->bit2
#define GPTA0_LTCCTR04_OUT       ((T_Reg32 *) 0xF0001A20)->bit15
#define GPTA0_LTCCTR04_RED       ((T_Reg32 *) 0xF0001A20)->bit4
#define GPTA0_LTCCTR04_REN       ((T_Reg32 *) 0xF0001A20)->bit3
#define GPTA0_LTCCTR04_SLO       ((T_Reg32 *) 0xF0001A20)->bit6

// GPTA0 Local Timer Cell Control Register 05
#define GPTA0_LTCCTR05         (*((uword volatile *) 0xF0001A28))
#define GPTA0_LTCCTR05_CEN       ((T_Reg32 *) 0xF0001A28)->bit10
#define GPTA0_LTCCTR05_CUD       ((T_Reg32 *) 0xF0001A28)->bit9
#define GPTA0_LTCCTR05_CUDCLR    ((T_Reg32 *) 0xF0001A28)->bit7
#define GPTA0_LTCCTR05_FED       ((T_Reg32 *) 0xF0001A28)->bit5
#define GPTA0_LTCCTR05_GBYP      ((T_Reg32 *) 0xF0001A28)->bit16
#define GPTA0_LTCCTR05_ILM       ((T_Reg32 *) 0xF0001A28)->bit8
#define GPTA0_LTCCTR05_OIA       ((T_Reg32 *) 0xF0001A28)->bit14
#define GPTA0_LTCCTR05_OSM       ((T_Reg32 *) 0xF0001A28)->bit2
#define GPTA0_LTCCTR05_OUT       ((T_Reg32 *) 0xF0001A28)->bit15
#define GPTA0_LTCCTR05_RED       ((T_Reg32 *) 0xF0001A28)->bit4
#define GPTA0_LTCCTR05_REN       ((T_Reg32 *) 0xF0001A28)->bit3
#define GPTA0_LTCCTR05_SLO       ((T_Reg32 *) 0xF0001A28)->bit6

// GPTA0 Local Timer Cell Control Register 06
#define GPTA0_LTCCTR06         (*((uword volatile *) 0xF0001A30))
#define GPTA0_LTCCTR06_CEN       ((T_Reg32 *) 0xF0001A30)->bit10
#define GPTA0_LTCCTR06_CUD       ((T_Reg32 *) 0xF0001A30)->bit9
#define GPTA0_LTCCTR06_CUDCLR    ((T_Reg32 *) 0xF0001A30)->bit7
#define GPTA0_LTCCTR06_FED       ((T_Reg32 *) 0xF0001A30)->bit5
#define GPTA0_LTCCTR06_GBYP      ((T_Reg32 *) 0xF0001A30)->bit16
#define GPTA0_LTCCTR06_ILM       ((T_Reg32 *) 0xF0001A30)->bit8
#define GPTA0_LTCCTR06_OIA       ((T_Reg32 *) 0xF0001A30)->bit14
#define GPTA0_LTCCTR06_OSM       ((T_Reg32 *) 0xF0001A30)->bit2
#define GPTA0_LTCCTR06_OUT       ((T_Reg32 *) 0xF0001A30)->bit15
#define GPTA0_LTCCTR06_RED       ((T_Reg32 *) 0xF0001A30)->bit4
#define GPTA0_LTCCTR06_REN       ((T_Reg32 *) 0xF0001A30)->bit3
#define GPTA0_LTCCTR06_SLO       ((T_Reg32 *) 0xF0001A30)->bit6

// GPTA0 Local Timer Cell Control Register 07
#define GPTA0_LTCCTR07         (*((uword volatile *) 0xF0001A38))
#define GPTA0_LTCCTR07_CEN       ((T_Reg32 *) 0xF0001A38)->bit10
#define GPTA0_LTCCTR07_CUD       ((T_Reg32 *) 0xF0001A38)->bit9
#define GPTA0_LTCCTR07_CUDCLR    ((T_Reg32 *) 0xF0001A38)->bit7
#define GPTA0_LTCCTR07_FED       ((T_Reg32 *) 0xF0001A38)->bit5
#define GPTA0_LTCCTR07_GBYP      ((T_Reg32 *) 0xF0001A38)->bit16
#define GPTA0_LTCCTR07_ILM       ((T_Reg32 *) 0xF0001A38)->bit8
#define GPTA0_LTCCTR07_OIA       ((T_Reg32 *) 0xF0001A38)->bit14
#define GPTA0_LTCCTR07_OSM       ((T_Reg32 *) 0xF0001A38)->bit2
#define GPTA0_LTCCTR07_OUT       ((T_Reg32 *) 0xF0001A38)->bit15
#define GPTA0_LTCCTR07_RED       ((T_Reg32 *) 0xF0001A38)->bit4
#define GPTA0_LTCCTR07_REN       ((T_Reg32 *) 0xF0001A38)->bit3
#define GPTA0_LTCCTR07_SLO       ((T_Reg32 *) 0xF0001A38)->bit6

// GPTA0 Local Timer Cell Control Register 08
#define GPTA0_LTCCTR08         (*((uword volatile *) 0xF0001A40))
#define GPTA0_LTCCTR08_CEN       ((T_Reg32 *) 0xF0001A40)->bit10
#define GPTA0_LTCCTR08_CUD       ((T_Reg32 *) 0xF0001A40)->bit9
#define GPTA0_LTCCTR08_CUDCLR    ((T_Reg32 *) 0xF0001A40)->bit7
#define GPTA0_LTCCTR08_FED       ((T_Reg32 *) 0xF0001A40)->bit5
#define GPTA0_LTCCTR08_GBYP      ((T_Reg32 *) 0xF0001A40)->bit16
#define GPTA0_LTCCTR08_ILM       ((T_Reg32 *) 0xF0001A40)->bit8
#define GPTA0_LTCCTR08_OIA       ((T_Reg32 *) 0xF0001A40)->bit14
#define GPTA0_LTCCTR08_OSM       ((T_Reg32 *) 0xF0001A40)->bit2
#define GPTA0_LTCCTR08_OUT       ((T_Reg32 *) 0xF0001A40)->bit15
#define GPTA0_LTCCTR08_RED       ((T_Reg32 *) 0xF0001A40)->bit4
#define GPTA0_LTCCTR08_REN       ((T_Reg32 *) 0xF0001A40)->bit3
#define GPTA0_LTCCTR08_SLO       ((T_Reg32 *) 0xF0001A40)->bit6

// GPTA0 Local Timer Cell Control Register 09
#define GPTA0_LTCCTR09         (*((uword volatile *) 0xF0001A48))
#define GPTA0_LTCCTR09_CEN       ((T_Reg32 *) 0xF0001A48)->bit10
#define GPTA0_LTCCTR09_CUD       ((T_Reg32 *) 0xF0001A48)->bit9
#define GPTA0_LTCCTR09_CUDCLR    ((T_Reg32 *) 0xF0001A48)->bit7
#define GPTA0_LTCCTR09_FED       ((T_Reg32 *) 0xF0001A48)->bit5
#define GPTA0_LTCCTR09_GBYP      ((T_Reg32 *) 0xF0001A48)->bit16
#define GPTA0_LTCCTR09_ILM       ((T_Reg32 *) 0xF0001A48)->bit8
#define GPTA0_LTCCTR09_OIA       ((T_Reg32 *) 0xF0001A48)->bit14
#define GPTA0_LTCCTR09_OSM       ((T_Reg32 *) 0xF0001A48)->bit2
#define GPTA0_LTCCTR09_OUT       ((T_Reg32 *) 0xF0001A48)->bit15
#define GPTA0_LTCCTR09_RED       ((T_Reg32 *) 0xF0001A48)->bit4
#define GPTA0_LTCCTR09_REN       ((T_Reg32 *) 0xF0001A48)->bit3
#define GPTA0_LTCCTR09_SLO       ((T_Reg32 *) 0xF0001A48)->bit6

// GPTA0 Local Timer Cell Control Register 10
#define GPTA0_LTCCTR10         (*((uword volatile *) 0xF0001A50))
#define GPTA0_LTCCTR10_CEN       ((T_Reg32 *) 0xF0001A50)->bit10
#define GPTA0_LTCCTR10_CUD       ((T_Reg32 *) 0xF0001A50)->bit9
#define GPTA0_LTCCTR10_CUDCLR    ((T_Reg32 *) 0xF0001A50)->bit7
#define GPTA0_LTCCTR10_FED       ((T_Reg32 *) 0xF0001A50)->bit5
#define GPTA0_LTCCTR10_GBYP      ((T_Reg32 *) 0xF0001A50)->bit16
#define GPTA0_LTCCTR10_ILM       ((T_Reg32 *) 0xF0001A50)->bit8
#define GPTA0_LTCCTR10_OIA       ((T_Reg32 *) 0xF0001A50)->bit14
#define GPTA0_LTCCTR10_OSM       ((T_Reg32 *) 0xF0001A50)->bit2
#define GPTA0_LTCCTR10_OUT       ((T_Reg32 *) 0xF0001A50)->bit15
#define GPTA0_LTCCTR10_RED       ((T_Reg32 *) 0xF0001A50)->bit4
#define GPTA0_LTCCTR10_REN       ((T_Reg32 *) 0xF0001A50)->bit3
#define GPTA0_LTCCTR10_SLO       ((T_Reg32 *) 0xF0001A50)->bit6

// GPTA0 Local Timer Cell Control Register 11
#define GPTA0_LTCCTR11         (*((uword volatile *) 0xF0001A58))
#define GPTA0_LTCCTR11_CEN       ((T_Reg32 *) 0xF0001A58)->bit10
#define GPTA0_LTCCTR11_CUD       ((T_Reg32 *) 0xF0001A58)->bit9
#define GPTA0_LTCCTR11_CUDCLR    ((T_Reg32 *) 0xF0001A58)->bit7
#define GPTA0_LTCCTR11_FED       ((T_Reg32 *) 0xF0001A58)->bit5
#define GPTA0_LTCCTR11_GBYP      ((T_Reg32 *) 0xF0001A58)->bit16
#define GPTA0_LTCCTR11_ILM       ((T_Reg32 *) 0xF0001A58)->bit8
#define GPTA0_LTCCTR11_OIA       ((T_Reg32 *) 0xF0001A58)->bit14
#define GPTA0_LTCCTR11_OSM       ((T_Reg32 *) 0xF0001A58)->bit2
#define GPTA0_LTCCTR11_OUT       ((T_Reg32 *) 0xF0001A58)->bit15
#define GPTA0_LTCCTR11_RED       ((T_Reg32 *) 0xF0001A58)->bit4
#define GPTA0_LTCCTR11_REN       ((T_Reg32 *) 0xF0001A58)->bit3
#define GPTA0_LTCCTR11_SLO       ((T_Reg32 *) 0xF0001A58)->bit6

// GPTA0 Local Timer Cell Control Register 12
#define GPTA0_LTCCTR12         (*((uword volatile *) 0xF0001A60))
#define GPTA0_LTCCTR12_CEN       ((T_Reg32 *) 0xF0001A60)->bit10
#define GPTA0_LTCCTR12_CUD       ((T_Reg32 *) 0xF0001A60)->bit9
#define GPTA0_LTCCTR12_CUDCLR    ((T_Reg32 *) 0xF0001A60)->bit7
#define GPTA0_LTCCTR12_FED       ((T_Reg32 *) 0xF0001A60)->bit5
#define GPTA0_LTCCTR12_GBYP      ((T_Reg32 *) 0xF0001A60)->bit16
#define GPTA0_LTCCTR12_ILM       ((T_Reg32 *) 0xF0001A60)->bit8
#define GPTA0_LTCCTR12_OIA       ((T_Reg32 *) 0xF0001A60)->bit14
#define GPTA0_LTCCTR12_OSM       ((T_Reg32 *) 0xF0001A60)->bit2
#define GPTA0_LTCCTR12_OUT       ((T_Reg32 *) 0xF0001A60)->bit15
#define GPTA0_LTCCTR12_RED       ((T_Reg32 *) 0xF0001A60)->bit4
#define GPTA0_LTCCTR12_REN       ((T_Reg32 *) 0xF0001A60)->bit3
#define GPTA0_LTCCTR12_SLO       ((T_Reg32 *) 0xF0001A60)->bit6

// GPTA0 Local Timer Cell Control Register 13
#define GPTA0_LTCCTR13         (*((uword volatile *) 0xF0001A68))
#define GPTA0_LTCCTR13_CEN       ((T_Reg32 *) 0xF0001A68)->bit10
#define GPTA0_LTCCTR13_CUD       ((T_Reg32 *) 0xF0001A68)->bit9
#define GPTA0_LTCCTR13_CUDCLR    ((T_Reg32 *) 0xF0001A68)->bit7
#define GPTA0_LTCCTR13_FED       ((T_Reg32 *) 0xF0001A68)->bit5
#define GPTA0_LTCCTR13_GBYP      ((T_Reg32 *) 0xF0001A68)->bit16
#define GPTA0_LTCCTR13_ILM       ((T_Reg32 *) 0xF0001A68)->bit8
#define GPTA0_LTCCTR13_OIA       ((T_Reg32 *) 0xF0001A68)->bit14
#define GPTA0_LTCCTR13_OSM       ((T_Reg32 *) 0xF0001A68)->bit2
#define GPTA0_LTCCTR13_OUT       ((T_Reg32 *) 0xF0001A68)->bit15
#define GPTA0_LTCCTR13_RED       ((T_Reg32 *) 0xF0001A68)->bit4
#define GPTA0_LTCCTR13_REN       ((T_Reg32 *) 0xF0001A68)->bit3
#define GPTA0_LTCCTR13_SLO       ((T_Reg32 *) 0xF0001A68)->bit6

// GPTA0 Local Timer Cell Control Register 14
#define GPTA0_LTCCTR14         (*((uword volatile *) 0xF0001A70))
#define GPTA0_LTCCTR14_CEN       ((T_Reg32 *) 0xF0001A70)->bit10
#define GPTA0_LTCCTR14_CUD       ((T_Reg32 *) 0xF0001A70)->bit9
#define GPTA0_LTCCTR14_CUDCLR    ((T_Reg32 *) 0xF0001A70)->bit7
#define GPTA0_LTCCTR14_FED       ((T_Reg32 *) 0xF0001A70)->bit5
#define GPTA0_LTCCTR14_GBYP      ((T_Reg32 *) 0xF0001A70)->bit16
#define GPTA0_LTCCTR14_ILM       ((T_Reg32 *) 0xF0001A70)->bit8
#define GPTA0_LTCCTR14_OIA       ((T_Reg32 *) 0xF0001A70)->bit14
#define GPTA0_LTCCTR14_OSM       ((T_Reg32 *) 0xF0001A70)->bit2
#define GPTA0_LTCCTR14_OUT       ((T_Reg32 *) 0xF0001A70)->bit15
#define GPTA0_LTCCTR14_RED       ((T_Reg32 *) 0xF0001A70)->bit4
#define GPTA0_LTCCTR14_REN       ((T_Reg32 *) 0xF0001A70)->bit3
#define GPTA0_LTCCTR14_SLO       ((T_Reg32 *) 0xF0001A70)->bit6

// GPTA0 Local Timer Cell Control Register 15
#define GPTA0_LTCCTR15         (*((uword volatile *) 0xF0001A78))
#define GPTA0_LTCCTR15_CEN       ((T_Reg32 *) 0xF0001A78)->bit10
#define GPTA0_LTCCTR15_CUD       ((T_Reg32 *) 0xF0001A78)->bit9
#define GPTA0_LTCCTR15_CUDCLR    ((T_Reg32 *) 0xF0001A78)->bit7
#define GPTA0_LTCCTR15_FED       ((T_Reg32 *) 0xF0001A78)->bit5
#define GPTA0_LTCCTR15_GBYP      ((T_Reg32 *) 0xF0001A78)->bit16
#define GPTA0_LTCCTR15_ILM       ((T_Reg32 *) 0xF0001A78)->bit8
#define GPTA0_LTCCTR15_OIA       ((T_Reg32 *) 0xF0001A78)->bit14
#define GPTA0_LTCCTR15_OSM       ((T_Reg32 *) 0xF0001A78)->bit2
#define GPTA0_LTCCTR15_OUT       ((T_Reg32 *) 0xF0001A78)->bit15
#define GPTA0_LTCCTR15_RED       ((T_Reg32 *) 0xF0001A78)->bit4
#define GPTA0_LTCCTR15_REN       ((T_Reg32 *) 0xF0001A78)->bit3
#define GPTA0_LTCCTR15_SLO       ((T_Reg32 *) 0xF0001A78)->bit6

// GPTA0 Local Timer Cell Control Register 16
#define GPTA0_LTCCTR16         (*((uword volatile *) 0xF0001A80))
#define GPTA0_LTCCTR16_CEN       ((T_Reg32 *) 0xF0001A80)->bit10
#define GPTA0_LTCCTR16_CUD       ((T_Reg32 *) 0xF0001A80)->bit9
#define GPTA0_LTCCTR16_CUDCLR    ((T_Reg32 *) 0xF0001A80)->bit7
#define GPTA0_LTCCTR16_FED       ((T_Reg32 *) 0xF0001A80)->bit5
#define GPTA0_LTCCTR16_GBYP      ((T_Reg32 *) 0xF0001A80)->bit16
#define GPTA0_LTCCTR16_ILM       ((T_Reg32 *) 0xF0001A80)->bit8
#define GPTA0_LTCCTR16_OIA       ((T_Reg32 *) 0xF0001A80)->bit14
#define GPTA0_LTCCTR16_OSM       ((T_Reg32 *) 0xF0001A80)->bit2
#define GPTA0_LTCCTR16_OUT       ((T_Reg32 *) 0xF0001A80)->bit15
#define GPTA0_LTCCTR16_RED       ((T_Reg32 *) 0xF0001A80)->bit4
#define GPTA0_LTCCTR16_REN       ((T_Reg32 *) 0xF0001A80)->bit3
#define GPTA0_LTCCTR16_SLO       ((T_Reg32 *) 0xF0001A80)->bit6

// GPTA0 Local Timer Cell Control Register 17
#define GPTA0_LTCCTR17         (*((uword volatile *) 0xF0001A88))
#define GPTA0_LTCCTR17_CEN       ((T_Reg32 *) 0xF0001A88)->bit10
#define GPTA0_LTCCTR17_CUD       ((T_Reg32 *) 0xF0001A88)->bit9
#define GPTA0_LTCCTR17_CUDCLR    ((T_Reg32 *) 0xF0001A88)->bit7
#define GPTA0_LTCCTR17_FED       ((T_Reg32 *) 0xF0001A88)->bit5
#define GPTA0_LTCCTR17_GBYP      ((T_Reg32 *) 0xF0001A88)->bit16
#define GPTA0_LTCCTR17_ILM       ((T_Reg32 *) 0xF0001A88)->bit8
#define GPTA0_LTCCTR17_OIA       ((T_Reg32 *) 0xF0001A88)->bit14
#define GPTA0_LTCCTR17_OSM       ((T_Reg32 *) 0xF0001A88)->bit2
#define GPTA0_LTCCTR17_OUT       ((T_Reg32 *) 0xF0001A88)->bit15
#define GPTA0_LTCCTR17_RED       ((T_Reg32 *) 0xF0001A88)->bit4
#define GPTA0_LTCCTR17_REN       ((T_Reg32 *) 0xF0001A88)->bit3
#define GPTA0_LTCCTR17_SLO       ((T_Reg32 *) 0xF0001A88)->bit6

// GPTA0 Local Timer Cell Control Register 18
#define GPTA0_LTCCTR18         (*((uword volatile *) 0xF0001A90))
#define GPTA0_LTCCTR18_CEN       ((T_Reg32 *) 0xF0001A90)->bit10
#define GPTA0_LTCCTR18_CUD       ((T_Reg32 *) 0xF0001A90)->bit9
#define GPTA0_LTCCTR18_CUDCLR    ((T_Reg32 *) 0xF0001A90)->bit7
#define GPTA0_LTCCTR18_FED       ((T_Reg32 *) 0xF0001A90)->bit5
#define GPTA0_LTCCTR18_GBYP      ((T_Reg32 *) 0xF0001A90)->bit16
#define GPTA0_LTCCTR18_ILM       ((T_Reg32 *) 0xF0001A90)->bit8
#define GPTA0_LTCCTR18_OIA       ((T_Reg32 *) 0xF0001A90)->bit14
#define GPTA0_LTCCTR18_OSM       ((T_Reg32 *) 0xF0001A90)->bit2
#define GPTA0_LTCCTR18_OUT       ((T_Reg32 *) 0xF0001A90)->bit15
#define GPTA0_LTCCTR18_RED       ((T_Reg32 *) 0xF0001A90)->bit4
#define GPTA0_LTCCTR18_REN       ((T_Reg32 *) 0xF0001A90)->bit3
#define GPTA0_LTCCTR18_SLO       ((T_Reg32 *) 0xF0001A90)->bit6

// GPTA0 Local Timer Cell Control Register 19
#define GPTA0_LTCCTR19         (*((uword volatile *) 0xF0001A98))
#define GPTA0_LTCCTR19_CEN       ((T_Reg32 *) 0xF0001A98)->bit10
#define GPTA0_LTCCTR19_CUD       ((T_Reg32 *) 0xF0001A98)->bit9
#define GPTA0_LTCCTR19_CUDCLR    ((T_Reg32 *) 0xF0001A98)->bit7
#define GPTA0_LTCCTR19_FED       ((T_Reg32 *) 0xF0001A98)->bit5
#define GPTA0_LTCCTR19_GBYP      ((T_Reg32 *) 0xF0001A98)->bit16
#define GPTA0_LTCCTR19_ILM       ((T_Reg32 *) 0xF0001A98)->bit8
#define GPTA0_LTCCTR19_OIA       ((T_Reg32 *) 0xF0001A98)->bit14
#define GPTA0_LTCCTR19_OSM       ((T_Reg32 *) 0xF0001A98)->bit2
#define GPTA0_LTCCTR19_OUT       ((T_Reg32 *) 0xF0001A98)->bit15
#define GPTA0_LTCCTR19_RED       ((T_Reg32 *) 0xF0001A98)->bit4
#define GPTA0_LTCCTR19_REN       ((T_Reg32 *) 0xF0001A98)->bit3
#define GPTA0_LTCCTR19_SLO       ((T_Reg32 *) 0xF0001A98)->bit6

// GPTA0 Local Timer Cell Control Register 20
#define GPTA0_LTCCTR20         (*((uword volatile *) 0xF0001AA0))
#define GPTA0_LTCCTR20_CEN       ((T_Reg32 *) 0xF0001AA0)->bit10
#define GPTA0_LTCCTR20_CUD       ((T_Reg32 *) 0xF0001AA0)->bit9
#define GPTA0_LTCCTR20_CUDCLR    ((T_Reg32 *) 0xF0001AA0)->bit7
#define GPTA0_LTCCTR20_FED       ((T_Reg32 *) 0xF0001AA0)->bit5
#define GPTA0_LTCCTR20_GBYP      ((T_Reg32 *) 0xF0001AA0)->bit16
#define GPTA0_LTCCTR20_ILM       ((T_Reg32 *) 0xF0001AA0)->bit8
#define GPTA0_LTCCTR20_OIA       ((T_Reg32 *) 0xF0001AA0)->bit14
#define GPTA0_LTCCTR20_OSM       ((T_Reg32 *) 0xF0001AA0)->bit2
#define GPTA0_LTCCTR20_OUT       ((T_Reg32 *) 0xF0001AA0)->bit15
#define GPTA0_LTCCTR20_RED       ((T_Reg32 *) 0xF0001AA0)->bit4
#define GPTA0_LTCCTR20_REN       ((T_Reg32 *) 0xF0001AA0)->bit3
#define GPTA0_LTCCTR20_SLO       ((T_Reg32 *) 0xF0001AA0)->bit6

// GPTA0 Local Timer Cell Control Register 21
#define GPTA0_LTCCTR21         (*((uword volatile *) 0xF0001AA8))
#define GPTA0_LTCCTR21_CEN       ((T_Reg32 *) 0xF0001AA8)->bit10
#define GPTA0_LTCCTR21_CUD       ((T_Reg32 *) 0xF0001AA8)->bit9
#define GPTA0_LTCCTR21_CUDCLR    ((T_Reg32 *) 0xF0001AA8)->bit7
#define GPTA0_LTCCTR21_FED       ((T_Reg32 *) 0xF0001AA8)->bit5
#define GPTA0_LTCCTR21_GBYP      ((T_Reg32 *) 0xF0001AA8)->bit16
#define GPTA0_LTCCTR21_ILM       ((T_Reg32 *) 0xF0001AA8)->bit8
#define GPTA0_LTCCTR21_OIA       ((T_Reg32 *) 0xF0001AA8)->bit14
#define GPTA0_LTCCTR21_OSM       ((T_Reg32 *) 0xF0001AA8)->bit2
#define GPTA0_LTCCTR21_OUT       ((T_Reg32 *) 0xF0001AA8)->bit15
#define GPTA0_LTCCTR21_RED       ((T_Reg32 *) 0xF0001AA8)->bit4
#define GPTA0_LTCCTR21_REN       ((T_Reg32 *) 0xF0001AA8)->bit3
#define GPTA0_LTCCTR21_SLO       ((T_Reg32 *) 0xF0001AA8)->bit6

// GPTA0 Local Timer Cell Control Register 22
#define GPTA0_LTCCTR22         (*((uword volatile *) 0xF0001AB0))
#define GPTA0_LTCCTR22_CEN       ((T_Reg32 *) 0xF0001AB0)->bit10
#define GPTA0_LTCCTR22_CUD       ((T_Reg32 *) 0xF0001AB0)->bit9
#define GPTA0_LTCCTR22_CUDCLR    ((T_Reg32 *) 0xF0001AB0)->bit7
#define GPTA0_LTCCTR22_FED       ((T_Reg32 *) 0xF0001AB0)->bit5
#define GPTA0_LTCCTR22_GBYP      ((T_Reg32 *) 0xF0001AB0)->bit16
#define GPTA0_LTCCTR22_ILM       ((T_Reg32 *) 0xF0001AB0)->bit8
#define GPTA0_LTCCTR22_OIA       ((T_Reg32 *) 0xF0001AB0)->bit14
#define GPTA0_LTCCTR22_OSM       ((T_Reg32 *) 0xF0001AB0)->bit2
#define GPTA0_LTCCTR22_OUT       ((T_Reg32 *) 0xF0001AB0)->bit15
#define GPTA0_LTCCTR22_RED       ((T_Reg32 *) 0xF0001AB0)->bit4
#define GPTA0_LTCCTR22_REN       ((T_Reg32 *) 0xF0001AB0)->bit3
#define GPTA0_LTCCTR22_SLO       ((T_Reg32 *) 0xF0001AB0)->bit6

// GPTA0 Local Timer Cell Control Register 23
#define GPTA0_LTCCTR23         (*((uword volatile *) 0xF0001AB8))
#define GPTA0_LTCCTR23_CEN       ((T_Reg32 *) 0xF0001AB8)->bit10
#define GPTA0_LTCCTR23_CUD       ((T_Reg32 *) 0xF0001AB8)->bit9
#define GPTA0_LTCCTR23_CUDCLR    ((T_Reg32 *) 0xF0001AB8)->bit7
#define GPTA0_LTCCTR23_FED       ((T_Reg32 *) 0xF0001AB8)->bit5
#define GPTA0_LTCCTR23_GBYP      ((T_Reg32 *) 0xF0001AB8)->bit16
#define GPTA0_LTCCTR23_ILM       ((T_Reg32 *) 0xF0001AB8)->bit8
#define GPTA0_LTCCTR23_OIA       ((T_Reg32 *) 0xF0001AB8)->bit14
#define GPTA0_LTCCTR23_OSM       ((T_Reg32 *) 0xF0001AB8)->bit2
#define GPTA0_LTCCTR23_OUT       ((T_Reg32 *) 0xF0001AB8)->bit15
#define GPTA0_LTCCTR23_RED       ((T_Reg32 *) 0xF0001AB8)->bit4
#define GPTA0_LTCCTR23_REN       ((T_Reg32 *) 0xF0001AB8)->bit3
#define GPTA0_LTCCTR23_SLO       ((T_Reg32 *) 0xF0001AB8)->bit6

// GPTA0 Local Timer Cell Control Register 24
#define GPTA0_LTCCTR24         (*((uword volatile *) 0xF0001AC0))
#define GPTA0_LTCCTR24_CEN       ((T_Reg32 *) 0xF0001AC0)->bit10
#define GPTA0_LTCCTR24_CUD       ((T_Reg32 *) 0xF0001AC0)->bit9
#define GPTA0_LTCCTR24_CUDCLR    ((T_Reg32 *) 0xF0001AC0)->bit7
#define GPTA0_LTCCTR24_FED       ((T_Reg32 *) 0xF0001AC0)->bit5
#define GPTA0_LTCCTR24_GBYP      ((T_Reg32 *) 0xF0001AC0)->bit16
#define GPTA0_LTCCTR24_ILM       ((T_Reg32 *) 0xF0001AC0)->bit8
#define GPTA0_LTCCTR24_OIA       ((T_Reg32 *) 0xF0001AC0)->bit14
#define GPTA0_LTCCTR24_OSM       ((T_Reg32 *) 0xF0001AC0)->bit2
#define GPTA0_LTCCTR24_OUT       ((T_Reg32 *) 0xF0001AC0)->bit15
#define GPTA0_LTCCTR24_RED       ((T_Reg32 *) 0xF0001AC0)->bit4
#define GPTA0_LTCCTR24_REN       ((T_Reg32 *) 0xF0001AC0)->bit3
#define GPTA0_LTCCTR24_SLO       ((T_Reg32 *) 0xF0001AC0)->bit6

// GPTA0 Local Timer Cell Control Register 25
#define GPTA0_LTCCTR25         (*((uword volatile *) 0xF0001AC8))
#define GPTA0_LTCCTR25_CEN       ((T_Reg32 *) 0xF0001AC8)->bit10
#define GPTA0_LTCCTR25_CUD       ((T_Reg32 *) 0xF0001AC8)->bit9
#define GPTA0_LTCCTR25_CUDCLR    ((T_Reg32 *) 0xF0001AC8)->bit7
#define GPTA0_LTCCTR25_FED       ((T_Reg32 *) 0xF0001AC8)->bit5
#define GPTA0_LTCCTR25_GBYP      ((T_Reg32 *) 0xF0001AC8)->bit16
#define GPTA0_LTCCTR25_ILM       ((T_Reg32 *) 0xF0001AC8)->bit8
#define GPTA0_LTCCTR25_OIA       ((T_Reg32 *) 0xF0001AC8)->bit14
#define GPTA0_LTCCTR25_OSM       ((T_Reg32 *) 0xF0001AC8)->bit2
#define GPTA0_LTCCTR25_OUT       ((T_Reg32 *) 0xF0001AC8)->bit15
#define GPTA0_LTCCTR25_RED       ((T_Reg32 *) 0xF0001AC8)->bit4
#define GPTA0_LTCCTR25_REN       ((T_Reg32 *) 0xF0001AC8)->bit3
#define GPTA0_LTCCTR25_SLO       ((T_Reg32 *) 0xF0001AC8)->bit6

// GPTA0 Local Timer Cell Control Register 26
#define GPTA0_LTCCTR26         (*((uword volatile *) 0xF0001AD0))
#define GPTA0_LTCCTR26_CEN       ((T_Reg32 *) 0xF0001AD0)->bit10
#define GPTA0_LTCCTR26_CUD       ((T_Reg32 *) 0xF0001AD0)->bit9
#define GPTA0_LTCCTR26_CUDCLR    ((T_Reg32 *) 0xF0001AD0)->bit7
#define GPTA0_LTCCTR26_FED       ((T_Reg32 *) 0xF0001AD0)->bit5
#define GPTA0_LTCCTR26_GBYP      ((T_Reg32 *) 0xF0001AD0)->bit16
#define GPTA0_LTCCTR26_ILM       ((T_Reg32 *) 0xF0001AD0)->bit8
#define GPTA0_LTCCTR26_OIA       ((T_Reg32 *) 0xF0001AD0)->bit14
#define GPTA0_LTCCTR26_OSM       ((T_Reg32 *) 0xF0001AD0)->bit2
#define GPTA0_LTCCTR26_OUT       ((T_Reg32 *) 0xF0001AD0)->bit15
#define GPTA0_LTCCTR26_RED       ((T_Reg32 *) 0xF0001AD0)->bit4
#define GPTA0_LTCCTR26_REN       ((T_Reg32 *) 0xF0001AD0)->bit3
#define GPTA0_LTCCTR26_SLO       ((T_Reg32 *) 0xF0001AD0)->bit6

// GPTA0 Local Timer Cell Control Register 27
#define GPTA0_LTCCTR27         (*((uword volatile *) 0xF0001AD8))
#define GPTA0_LTCCTR27_CEN       ((T_Reg32 *) 0xF0001AD8)->bit10
#define GPTA0_LTCCTR27_CUD       ((T_Reg32 *) 0xF0001AD8)->bit9
#define GPTA0_LTCCTR27_CUDCLR    ((T_Reg32 *) 0xF0001AD8)->bit7
#define GPTA0_LTCCTR27_FED       ((T_Reg32 *) 0xF0001AD8)->bit5
#define GPTA0_LTCCTR27_GBYP      ((T_Reg32 *) 0xF0001AD8)->bit16
#define GPTA0_LTCCTR27_ILM       ((T_Reg32 *) 0xF0001AD8)->bit8
#define GPTA0_LTCCTR27_OIA       ((T_Reg32 *) 0xF0001AD8)->bit14
#define GPTA0_LTCCTR27_OSM       ((T_Reg32 *) 0xF0001AD8)->bit2
#define GPTA0_LTCCTR27_OUT       ((T_Reg32 *) 0xF0001AD8)->bit15
#define GPTA0_LTCCTR27_RED       ((T_Reg32 *) 0xF0001AD8)->bit4
#define GPTA0_LTCCTR27_REN       ((T_Reg32 *) 0xF0001AD8)->bit3
#define GPTA0_LTCCTR27_SLO       ((T_Reg32 *) 0xF0001AD8)->bit6

// GPTA0 Local Timer Cell Control Register 28
#define GPTA0_LTCCTR28         (*((uword volatile *) 0xF0001AE0))
#define GPTA0_LTCCTR28_CEN       ((T_Reg32 *) 0xF0001AE0)->bit10
#define GPTA0_LTCCTR28_CUD       ((T_Reg32 *) 0xF0001AE0)->bit9
#define GPTA0_LTCCTR28_CUDCLR    ((T_Reg32 *) 0xF0001AE0)->bit7
#define GPTA0_LTCCTR28_FED       ((T_Reg32 *) 0xF0001AE0)->bit5
#define GPTA0_LTCCTR28_GBYP      ((T_Reg32 *) 0xF0001AE0)->bit16
#define GPTA0_LTCCTR28_ILM       ((T_Reg32 *) 0xF0001AE0)->bit8
#define GPTA0_LTCCTR28_OIA       ((T_Reg32 *) 0xF0001AE0)->bit14
#define GPTA0_LTCCTR28_OSM       ((T_Reg32 *) 0xF0001AE0)->bit2
#define GPTA0_LTCCTR28_OUT       ((T_Reg32 *) 0xF0001AE0)->bit15
#define GPTA0_LTCCTR28_RED       ((T_Reg32 *) 0xF0001AE0)->bit4
#define GPTA0_LTCCTR28_REN       ((T_Reg32 *) 0xF0001AE0)->bit3
#define GPTA0_LTCCTR28_SLO       ((T_Reg32 *) 0xF0001AE0)->bit6

// GPTA0 Local Timer Cell Control Register 29
#define GPTA0_LTCCTR29         (*((uword volatile *) 0xF0001AE8))
#define GPTA0_LTCCTR29_CEN       ((T_Reg32 *) 0xF0001AE8)->bit10
#define GPTA0_LTCCTR29_CUD       ((T_Reg32 *) 0xF0001AE8)->bit9
#define GPTA0_LTCCTR29_CUDCLR    ((T_Reg32 *) 0xF0001AE8)->bit7
#define GPTA0_LTCCTR29_FED       ((T_Reg32 *) 0xF0001AE8)->bit5
#define GPTA0_LTCCTR29_GBYP      ((T_Reg32 *) 0xF0001AE8)->bit16
#define GPTA0_LTCCTR29_ILM       ((T_Reg32 *) 0xF0001AE8)->bit8
#define GPTA0_LTCCTR29_OIA       ((T_Reg32 *) 0xF0001AE8)->bit14
#define GPTA0_LTCCTR29_OSM       ((T_Reg32 *) 0xF0001AE8)->bit2
#define GPTA0_LTCCTR29_OUT       ((T_Reg32 *) 0xF0001AE8)->bit15
#define GPTA0_LTCCTR29_RED       ((T_Reg32 *) 0xF0001AE8)->bit4
#define GPTA0_LTCCTR29_REN       ((T_Reg32 *) 0xF0001AE8)->bit3
#define GPTA0_LTCCTR29_SLO       ((T_Reg32 *) 0xF0001AE8)->bit6

// GPTA0 Local Timer Cell Control Register 30
#define GPTA0_LTCCTR30         (*((uword volatile *) 0xF0001AF0))
#define GPTA0_LTCCTR30_CEN       ((T_Reg32 *) 0xF0001AF0)->bit10
#define GPTA0_LTCCTR30_CUD       ((T_Reg32 *) 0xF0001AF0)->bit9
#define GPTA0_LTCCTR30_CUDCLR    ((T_Reg32 *) 0xF0001AF0)->bit7
#define GPTA0_LTCCTR30_FED       ((T_Reg32 *) 0xF0001AF0)->bit5
#define GPTA0_LTCCTR30_GBYP      ((T_Reg32 *) 0xF0001AF0)->bit16
#define GPTA0_LTCCTR30_ILM       ((T_Reg32 *) 0xF0001AF0)->bit8
#define GPTA0_LTCCTR30_OIA       ((T_Reg32 *) 0xF0001AF0)->bit14
#define GPTA0_LTCCTR30_OSM       ((T_Reg32 *) 0xF0001AF0)->bit2
#define GPTA0_LTCCTR30_OUT       ((T_Reg32 *) 0xF0001AF0)->bit15
#define GPTA0_LTCCTR30_RED       ((T_Reg32 *) 0xF0001AF0)->bit4
#define GPTA0_LTCCTR30_REN       ((T_Reg32 *) 0xF0001AF0)->bit3
#define GPTA0_LTCCTR30_SLO       ((T_Reg32 *) 0xF0001AF0)->bit6

// GPTA0 Local Timer Cell Control Register 31
#define GPTA0_LTCCTR31         (*((uword volatile *) 0xF0001AF8))
#define GPTA0_LTCCTR31_CEN       ((T_Reg32 *) 0xF0001AF8)->bit10
#define GPTA0_LTCCTR31_CUD       ((T_Reg32 *) 0xF0001AF8)->bit9
#define GPTA0_LTCCTR31_CUDCLR    ((T_Reg32 *) 0xF0001AF8)->bit7
#define GPTA0_LTCCTR31_FED       ((T_Reg32 *) 0xF0001AF8)->bit5
#define GPTA0_LTCCTR31_GBYP      ((T_Reg32 *) 0xF0001AF8)->bit16
#define GPTA0_LTCCTR31_ILM       ((T_Reg32 *) 0xF0001AF8)->bit8
#define GPTA0_LTCCTR31_OIA       ((T_Reg32 *) 0xF0001AF8)->bit14
#define GPTA0_LTCCTR31_OSM       ((T_Reg32 *) 0xF0001AF8)->bit2
#define GPTA0_LTCCTR31_OUT       ((T_Reg32 *) 0xF0001AF8)->bit15
#define GPTA0_LTCCTR31_RED       ((T_Reg32 *) 0xF0001AF8)->bit4
#define GPTA0_LTCCTR31_REN       ((T_Reg32 *) 0xF0001AF8)->bit3
#define GPTA0_LTCCTR31_SLO       ((T_Reg32 *) 0xF0001AF8)->bit6

// GPTA0 Local Timer Cell Control Register 32
#define GPTA0_LTCCTR32         (*((uword volatile *) 0xF0001B00))
#define GPTA0_LTCCTR32_CEN       ((T_Reg32 *) 0xF0001B00)->bit10
#define GPTA0_LTCCTR32_CUD       ((T_Reg32 *) 0xF0001B00)->bit9
#define GPTA0_LTCCTR32_CUDCLR    ((T_Reg32 *) 0xF0001B00)->bit7
#define GPTA0_LTCCTR32_FED       ((T_Reg32 *) 0xF0001B00)->bit5
#define GPTA0_LTCCTR32_GBYP      ((T_Reg32 *) 0xF0001B00)->bit16
#define GPTA0_LTCCTR32_ILM       ((T_Reg32 *) 0xF0001B00)->bit8
#define GPTA0_LTCCTR32_OIA       ((T_Reg32 *) 0xF0001B00)->bit14
#define GPTA0_LTCCTR32_OSM       ((T_Reg32 *) 0xF0001B00)->bit2
#define GPTA0_LTCCTR32_OUT       ((T_Reg32 *) 0xF0001B00)->bit15
#define GPTA0_LTCCTR32_RED       ((T_Reg32 *) 0xF0001B00)->bit4
#define GPTA0_LTCCTR32_REN       ((T_Reg32 *) 0xF0001B00)->bit3
#define GPTA0_LTCCTR32_SLO       ((T_Reg32 *) 0xF0001B00)->bit6

// GPTA0 Local Timer Cell Control Register 33
#define GPTA0_LTCCTR33         (*((uword volatile *) 0xF0001B08))
#define GPTA0_LTCCTR33_CEN       ((T_Reg32 *) 0xF0001B08)->bit10
#define GPTA0_LTCCTR33_CUD       ((T_Reg32 *) 0xF0001B08)->bit9
#define GPTA0_LTCCTR33_CUDCLR    ((T_Reg32 *) 0xF0001B08)->bit7
#define GPTA0_LTCCTR33_FED       ((T_Reg32 *) 0xF0001B08)->bit5
#define GPTA0_LTCCTR33_GBYP      ((T_Reg32 *) 0xF0001B08)->bit16
#define GPTA0_LTCCTR33_ILM       ((T_Reg32 *) 0xF0001B08)->bit8
#define GPTA0_LTCCTR33_OIA       ((T_Reg32 *) 0xF0001B08)->bit14
#define GPTA0_LTCCTR33_OSM       ((T_Reg32 *) 0xF0001B08)->bit2
#define GPTA0_LTCCTR33_OUT       ((T_Reg32 *) 0xF0001B08)->bit15
#define GPTA0_LTCCTR33_RED       ((T_Reg32 *) 0xF0001B08)->bit4
#define GPTA0_LTCCTR33_REN       ((T_Reg32 *) 0xF0001B08)->bit3
#define GPTA0_LTCCTR33_SLO       ((T_Reg32 *) 0xF0001B08)->bit6

// GPTA0 Local Timer Cell Control Register 34
#define GPTA0_LTCCTR34         (*((uword volatile *) 0xF0001B10))
#define GPTA0_LTCCTR34_CEN       ((T_Reg32 *) 0xF0001B10)->bit10
#define GPTA0_LTCCTR34_CUD       ((T_Reg32 *) 0xF0001B10)->bit9
#define GPTA0_LTCCTR34_CUDCLR    ((T_Reg32 *) 0xF0001B10)->bit7
#define GPTA0_LTCCTR34_FED       ((T_Reg32 *) 0xF0001B10)->bit5
#define GPTA0_LTCCTR34_GBYP      ((T_Reg32 *) 0xF0001B10)->bit16
#define GPTA0_LTCCTR34_ILM       ((T_Reg32 *) 0xF0001B10)->bit8
#define GPTA0_LTCCTR34_OIA       ((T_Reg32 *) 0xF0001B10)->bit14
#define GPTA0_LTCCTR34_OSM       ((T_Reg32 *) 0xF0001B10)->bit2
#define GPTA0_LTCCTR34_OUT       ((T_Reg32 *) 0xF0001B10)->bit15
#define GPTA0_LTCCTR34_RED       ((T_Reg32 *) 0xF0001B10)->bit4
#define GPTA0_LTCCTR34_REN       ((T_Reg32 *) 0xF0001B10)->bit3
#define GPTA0_LTCCTR34_SLO       ((T_Reg32 *) 0xF0001B10)->bit6

// GPTA0 Local Timer Cell Control Register 35
#define GPTA0_LTCCTR35         (*((uword volatile *) 0xF0001B18))
#define GPTA0_LTCCTR35_CEN       ((T_Reg32 *) 0xF0001B18)->bit10
#define GPTA0_LTCCTR35_CUD       ((T_Reg32 *) 0xF0001B18)->bit9
#define GPTA0_LTCCTR35_CUDCLR    ((T_Reg32 *) 0xF0001B18)->bit7
#define GPTA0_LTCCTR35_FED       ((T_Reg32 *) 0xF0001B18)->bit5
#define GPTA0_LTCCTR35_GBYP      ((T_Reg32 *) 0xF0001B18)->bit16
#define GPTA0_LTCCTR35_ILM       ((T_Reg32 *) 0xF0001B18)->bit8
#define GPTA0_LTCCTR35_OIA       ((T_Reg32 *) 0xF0001B18)->bit14
#define GPTA0_LTCCTR35_OSM       ((T_Reg32 *) 0xF0001B18)->bit2
#define GPTA0_LTCCTR35_OUT       ((T_Reg32 *) 0xF0001B18)->bit15
#define GPTA0_LTCCTR35_RED       ((T_Reg32 *) 0xF0001B18)->bit4
#define GPTA0_LTCCTR35_REN       ((T_Reg32 *) 0xF0001B18)->bit3
#define GPTA0_LTCCTR35_SLO       ((T_Reg32 *) 0xF0001B18)->bit6

// GPTA0 Local Timer Cell Control Register 36
#define GPTA0_LTCCTR36         (*((uword volatile *) 0xF0001B20))
#define GPTA0_LTCCTR36_CEN       ((T_Reg32 *) 0xF0001B20)->bit10
#define GPTA0_LTCCTR36_CUD       ((T_Reg32 *) 0xF0001B20)->bit9
#define GPTA0_LTCCTR36_CUDCLR    ((T_Reg32 *) 0xF0001B20)->bit7
#define GPTA0_LTCCTR36_FED       ((T_Reg32 *) 0xF0001B20)->bit5
#define GPTA0_LTCCTR36_GBYP      ((T_Reg32 *) 0xF0001B20)->bit16
#define GPTA0_LTCCTR36_ILM       ((T_Reg32 *) 0xF0001B20)->bit8
#define GPTA0_LTCCTR36_OIA       ((T_Reg32 *) 0xF0001B20)->bit14
#define GPTA0_LTCCTR36_OSM       ((T_Reg32 *) 0xF0001B20)->bit2
#define GPTA0_LTCCTR36_OUT       ((T_Reg32 *) 0xF0001B20)->bit15
#define GPTA0_LTCCTR36_RED       ((T_Reg32 *) 0xF0001B20)->bit4
#define GPTA0_LTCCTR36_REN       ((T_Reg32 *) 0xF0001B20)->bit3
#define GPTA0_LTCCTR36_SLO       ((T_Reg32 *) 0xF0001B20)->bit6

// GPTA0 Local Timer Cell Control Register 37
#define GPTA0_LTCCTR37         (*((uword volatile *) 0xF0001B28))
#define GPTA0_LTCCTR37_CEN       ((T_Reg32 *) 0xF0001B28)->bit10
#define GPTA0_LTCCTR37_CUD       ((T_Reg32 *) 0xF0001B28)->bit9
#define GPTA0_LTCCTR37_CUDCLR    ((T_Reg32 *) 0xF0001B28)->bit7
#define GPTA0_LTCCTR37_FED       ((T_Reg32 *) 0xF0001B28)->bit5
#define GPTA0_LTCCTR37_GBYP      ((T_Reg32 *) 0xF0001B28)->bit16
#define GPTA0_LTCCTR37_ILM       ((T_Reg32 *) 0xF0001B28)->bit8
#define GPTA0_LTCCTR37_OIA       ((T_Reg32 *) 0xF0001B28)->bit14
#define GPTA0_LTCCTR37_OSM       ((T_Reg32 *) 0xF0001B28)->bit2
#define GPTA0_LTCCTR37_OUT       ((T_Reg32 *) 0xF0001B28)->bit15
#define GPTA0_LTCCTR37_RED       ((T_Reg32 *) 0xF0001B28)->bit4
#define GPTA0_LTCCTR37_REN       ((T_Reg32 *) 0xF0001B28)->bit3
#define GPTA0_LTCCTR37_SLO       ((T_Reg32 *) 0xF0001B28)->bit6

// GPTA0 Local Timer Cell Control Register 38
#define GPTA0_LTCCTR38         (*((uword volatile *) 0xF0001B30))
#define GPTA0_LTCCTR38_CEN       ((T_Reg32 *) 0xF0001B30)->bit10
#define GPTA0_LTCCTR38_CUD       ((T_Reg32 *) 0xF0001B30)->bit9
#define GPTA0_LTCCTR38_CUDCLR    ((T_Reg32 *) 0xF0001B30)->bit7
#define GPTA0_LTCCTR38_FED       ((T_Reg32 *) 0xF0001B30)->bit5
#define GPTA0_LTCCTR38_GBYP      ((T_Reg32 *) 0xF0001B30)->bit16
#define GPTA0_LTCCTR38_ILM       ((T_Reg32 *) 0xF0001B30)->bit8
#define GPTA0_LTCCTR38_OIA       ((T_Reg32 *) 0xF0001B30)->bit14
#define GPTA0_LTCCTR38_OSM       ((T_Reg32 *) 0xF0001B30)->bit2
#define GPTA0_LTCCTR38_OUT       ((T_Reg32 *) 0xF0001B30)->bit15
#define GPTA0_LTCCTR38_RED       ((T_Reg32 *) 0xF0001B30)->bit4
#define GPTA0_LTCCTR38_REN       ((T_Reg32 *) 0xF0001B30)->bit3
#define GPTA0_LTCCTR38_SLO       ((T_Reg32 *) 0xF0001B30)->bit6

// GPTA0 Local Timer Cell Control Register 39
#define GPTA0_LTCCTR39         (*((uword volatile *) 0xF0001B38))
#define GPTA0_LTCCTR39_CEN       ((T_Reg32 *) 0xF0001B38)->bit10
#define GPTA0_LTCCTR39_CUD       ((T_Reg32 *) 0xF0001B38)->bit9
#define GPTA0_LTCCTR39_CUDCLR    ((T_Reg32 *) 0xF0001B38)->bit7
#define GPTA0_LTCCTR39_FED       ((T_Reg32 *) 0xF0001B38)->bit5
#define GPTA0_LTCCTR39_GBYP      ((T_Reg32 *) 0xF0001B38)->bit16
#define GPTA0_LTCCTR39_ILM       ((T_Reg32 *) 0xF0001B38)->bit8
#define GPTA0_LTCCTR39_OIA       ((T_Reg32 *) 0xF0001B38)->bit14
#define GPTA0_LTCCTR39_OSM       ((T_Reg32 *) 0xF0001B38)->bit2
#define GPTA0_LTCCTR39_OUT       ((T_Reg32 *) 0xF0001B38)->bit15
#define GPTA0_LTCCTR39_RED       ((T_Reg32 *) 0xF0001B38)->bit4
#define GPTA0_LTCCTR39_REN       ((T_Reg32 *) 0xF0001B38)->bit3
#define GPTA0_LTCCTR39_SLO       ((T_Reg32 *) 0xF0001B38)->bit6

// GPTA0 Local Timer Cell Control Register 40
#define GPTA0_LTCCTR40         (*((uword volatile *) 0xF0001B40))
#define GPTA0_LTCCTR40_CEN       ((T_Reg32 *) 0xF0001B40)->bit10
#define GPTA0_LTCCTR40_CUD       ((T_Reg32 *) 0xF0001B40)->bit9
#define GPTA0_LTCCTR40_CUDCLR    ((T_Reg32 *) 0xF0001B40)->bit7
#define GPTA0_LTCCTR40_FED       ((T_Reg32 *) 0xF0001B40)->bit5
#define GPTA0_LTCCTR40_GBYP      ((T_Reg32 *) 0xF0001B40)->bit16
#define GPTA0_LTCCTR40_ILM       ((T_Reg32 *) 0xF0001B40)->bit8
#define GPTA0_LTCCTR40_OIA       ((T_Reg32 *) 0xF0001B40)->bit14
#define GPTA0_LTCCTR40_OSM       ((T_Reg32 *) 0xF0001B40)->bit2
#define GPTA0_LTCCTR40_OUT       ((T_Reg32 *) 0xF0001B40)->bit15
#define GPTA0_LTCCTR40_RED       ((T_Reg32 *) 0xF0001B40)->bit4
#define GPTA0_LTCCTR40_REN       ((T_Reg32 *) 0xF0001B40)->bit3
#define GPTA0_LTCCTR40_SLO       ((T_Reg32 *) 0xF0001B40)->bit6

// GPTA0 Local Timer Cell Control Register 41
#define GPTA0_LTCCTR41         (*((uword volatile *) 0xF0001B48))
#define GPTA0_LTCCTR41_CEN       ((T_Reg32 *) 0xF0001B48)->bit10
#define GPTA0_LTCCTR41_CUD       ((T_Reg32 *) 0xF0001B48)->bit9
#define GPTA0_LTCCTR41_CUDCLR    ((T_Reg32 *) 0xF0001B48)->bit7
#define GPTA0_LTCCTR41_FED       ((T_Reg32 *) 0xF0001B48)->bit5
#define GPTA0_LTCCTR41_GBYP      ((T_Reg32 *) 0xF0001B48)->bit16
#define GPTA0_LTCCTR41_ILM       ((T_Reg32 *) 0xF0001B48)->bit8
#define GPTA0_LTCCTR41_OIA       ((T_Reg32 *) 0xF0001B48)->bit14
#define GPTA0_LTCCTR41_OSM       ((T_Reg32 *) 0xF0001B48)->bit2
#define GPTA0_LTCCTR41_OUT       ((T_Reg32 *) 0xF0001B48)->bit15
#define GPTA0_LTCCTR41_RED       ((T_Reg32 *) 0xF0001B48)->bit4
#define GPTA0_LTCCTR41_REN       ((T_Reg32 *) 0xF0001B48)->bit3
#define GPTA0_LTCCTR41_SLO       ((T_Reg32 *) 0xF0001B48)->bit6

// GPTA0 Local Timer Cell Control Register 42
#define GPTA0_LTCCTR42         (*((uword volatile *) 0xF0001B50))
#define GPTA0_LTCCTR42_CEN       ((T_Reg32 *) 0xF0001B50)->bit10
#define GPTA0_LTCCTR42_CUD       ((T_Reg32 *) 0xF0001B50)->bit9
#define GPTA0_LTCCTR42_CUDCLR    ((T_Reg32 *) 0xF0001B50)->bit7
#define GPTA0_LTCCTR42_FED       ((T_Reg32 *) 0xF0001B50)->bit5
#define GPTA0_LTCCTR42_GBYP      ((T_Reg32 *) 0xF0001B50)->bit16
#define GPTA0_LTCCTR42_ILM       ((T_Reg32 *) 0xF0001B50)->bit8
#define GPTA0_LTCCTR42_OIA       ((T_Reg32 *) 0xF0001B50)->bit14
#define GPTA0_LTCCTR42_OSM       ((T_Reg32 *) 0xF0001B50)->bit2
#define GPTA0_LTCCTR42_OUT       ((T_Reg32 *) 0xF0001B50)->bit15
#define GPTA0_LTCCTR42_RED       ((T_Reg32 *) 0xF0001B50)->bit4
#define GPTA0_LTCCTR42_REN       ((T_Reg32 *) 0xF0001B50)->bit3
#define GPTA0_LTCCTR42_SLO       ((T_Reg32 *) 0xF0001B50)->bit6

// GPTA0 Local Timer Cell Control Register 43
#define GPTA0_LTCCTR43         (*((uword volatile *) 0xF0001B58))
#define GPTA0_LTCCTR43_CEN       ((T_Reg32 *) 0xF0001B58)->bit10
#define GPTA0_LTCCTR43_CUD       ((T_Reg32 *) 0xF0001B58)->bit9
#define GPTA0_LTCCTR43_CUDCLR    ((T_Reg32 *) 0xF0001B58)->bit7
#define GPTA0_LTCCTR43_FED       ((T_Reg32 *) 0xF0001B58)->bit5
#define GPTA0_LTCCTR43_GBYP      ((T_Reg32 *) 0xF0001B58)->bit16
#define GPTA0_LTCCTR43_ILM       ((T_Reg32 *) 0xF0001B58)->bit8
#define GPTA0_LTCCTR43_OIA       ((T_Reg32 *) 0xF0001B58)->bit14
#define GPTA0_LTCCTR43_OSM       ((T_Reg32 *) 0xF0001B58)->bit2
#define GPTA0_LTCCTR43_OUT       ((T_Reg32 *) 0xF0001B58)->bit15
#define GPTA0_LTCCTR43_RED       ((T_Reg32 *) 0xF0001B58)->bit4
#define GPTA0_LTCCTR43_REN       ((T_Reg32 *) 0xF0001B58)->bit3
#define GPTA0_LTCCTR43_SLO       ((T_Reg32 *) 0xF0001B58)->bit6

// GPTA0 Local Timer Cell Control Register 44
#define GPTA0_LTCCTR44         (*((uword volatile *) 0xF0001B60))
#define GPTA0_LTCCTR44_CEN       ((T_Reg32 *) 0xF0001B60)->bit10
#define GPTA0_LTCCTR44_CUD       ((T_Reg32 *) 0xF0001B60)->bit9
#define GPTA0_LTCCTR44_CUDCLR    ((T_Reg32 *) 0xF0001B60)->bit7
#define GPTA0_LTCCTR44_FED       ((T_Reg32 *) 0xF0001B60)->bit5
#define GPTA0_LTCCTR44_GBYP      ((T_Reg32 *) 0xF0001B60)->bit16
#define GPTA0_LTCCTR44_ILM       ((T_Reg32 *) 0xF0001B60)->bit8
#define GPTA0_LTCCTR44_OIA       ((T_Reg32 *) 0xF0001B60)->bit14
#define GPTA0_LTCCTR44_OSM       ((T_Reg32 *) 0xF0001B60)->bit2
#define GPTA0_LTCCTR44_OUT       ((T_Reg32 *) 0xF0001B60)->bit15
#define GPTA0_LTCCTR44_RED       ((T_Reg32 *) 0xF0001B60)->bit4
#define GPTA0_LTCCTR44_REN       ((T_Reg32 *) 0xF0001B60)->bit3
#define GPTA0_LTCCTR44_SLO       ((T_Reg32 *) 0xF0001B60)->bit6

// GPTA0 Local Timer Cell Control Register 45
#define GPTA0_LTCCTR45         (*((uword volatile *) 0xF0001B68))
#define GPTA0_LTCCTR45_CEN       ((T_Reg32 *) 0xF0001B68)->bit10
#define GPTA0_LTCCTR45_CUD       ((T_Reg32 *) 0xF0001B68)->bit9
#define GPTA0_LTCCTR45_CUDCLR    ((T_Reg32 *) 0xF0001B68)->bit7
#define GPTA0_LTCCTR45_FED       ((T_Reg32 *) 0xF0001B68)->bit5
#define GPTA0_LTCCTR45_GBYP      ((T_Reg32 *) 0xF0001B68)->bit16
#define GPTA0_LTCCTR45_ILM       ((T_Reg32 *) 0xF0001B68)->bit8
#define GPTA0_LTCCTR45_OIA       ((T_Reg32 *) 0xF0001B68)->bit14
#define GPTA0_LTCCTR45_OSM       ((T_Reg32 *) 0xF0001B68)->bit2
#define GPTA0_LTCCTR45_OUT       ((T_Reg32 *) 0xF0001B68)->bit15
#define GPTA0_LTCCTR45_RED       ((T_Reg32 *) 0xF0001B68)->bit4
#define GPTA0_LTCCTR45_REN       ((T_Reg32 *) 0xF0001B68)->bit3
#define GPTA0_LTCCTR45_SLO       ((T_Reg32 *) 0xF0001B68)->bit6

// GPTA0 Local Timer Cell Control Register 46
#define GPTA0_LTCCTR46         (*((uword volatile *) 0xF0001B70))
#define GPTA0_LTCCTR46_CEN       ((T_Reg32 *) 0xF0001B70)->bit10
#define GPTA0_LTCCTR46_CUD       ((T_Reg32 *) 0xF0001B70)->bit9
#define GPTA0_LTCCTR46_CUDCLR    ((T_Reg32 *) 0xF0001B70)->bit7
#define GPTA0_LTCCTR46_FED       ((T_Reg32 *) 0xF0001B70)->bit5
#define GPTA0_LTCCTR46_GBYP      ((T_Reg32 *) 0xF0001B70)->bit16
#define GPTA0_LTCCTR46_ILM       ((T_Reg32 *) 0xF0001B70)->bit8
#define GPTA0_LTCCTR46_OIA       ((T_Reg32 *) 0xF0001B70)->bit14
#define GPTA0_LTCCTR46_OSM       ((T_Reg32 *) 0xF0001B70)->bit2
#define GPTA0_LTCCTR46_OUT       ((T_Reg32 *) 0xF0001B70)->bit15
#define GPTA0_LTCCTR46_RED       ((T_Reg32 *) 0xF0001B70)->bit4
#define GPTA0_LTCCTR46_REN       ((T_Reg32 *) 0xF0001B70)->bit3
#define GPTA0_LTCCTR46_SLO       ((T_Reg32 *) 0xF0001B70)->bit6

// GPTA0 Local Timer Cell Control Register 47
#define GPTA0_LTCCTR47         (*((uword volatile *) 0xF0001B78))
#define GPTA0_LTCCTR47_CEN       ((T_Reg32 *) 0xF0001B78)->bit10
#define GPTA0_LTCCTR47_CUD       ((T_Reg32 *) 0xF0001B78)->bit9
#define GPTA0_LTCCTR47_CUDCLR    ((T_Reg32 *) 0xF0001B78)->bit7
#define GPTA0_LTCCTR47_FED       ((T_Reg32 *) 0xF0001B78)->bit5
#define GPTA0_LTCCTR47_GBYP      ((T_Reg32 *) 0xF0001B78)->bit16
#define GPTA0_LTCCTR47_ILM       ((T_Reg32 *) 0xF0001B78)->bit8
#define GPTA0_LTCCTR47_OIA       ((T_Reg32 *) 0xF0001B78)->bit14
#define GPTA0_LTCCTR47_OSM       ((T_Reg32 *) 0xF0001B78)->bit2
#define GPTA0_LTCCTR47_OUT       ((T_Reg32 *) 0xF0001B78)->bit15
#define GPTA0_LTCCTR47_RED       ((T_Reg32 *) 0xF0001B78)->bit4
#define GPTA0_LTCCTR47_REN       ((T_Reg32 *) 0xF0001B78)->bit3
#define GPTA0_LTCCTR47_SLO       ((T_Reg32 *) 0xF0001B78)->bit6

// GPTA0 Local Timer Cell Control Register 48
#define GPTA0_LTCCTR48         (*((uword volatile *) 0xF0001B80))
#define GPTA0_LTCCTR48_CEN       ((T_Reg32 *) 0xF0001B80)->bit10
#define GPTA0_LTCCTR48_CUD       ((T_Reg32 *) 0xF0001B80)->bit9
#define GPTA0_LTCCTR48_CUDCLR    ((T_Reg32 *) 0xF0001B80)->bit7
#define GPTA0_LTCCTR48_FED       ((T_Reg32 *) 0xF0001B80)->bit5
#define GPTA0_LTCCTR48_GBYP      ((T_Reg32 *) 0xF0001B80)->bit16
#define GPTA0_LTCCTR48_ILM       ((T_Reg32 *) 0xF0001B80)->bit8
#define GPTA0_LTCCTR48_OIA       ((T_Reg32 *) 0xF0001B80)->bit14
#define GPTA0_LTCCTR48_OSM       ((T_Reg32 *) 0xF0001B80)->bit2
#define GPTA0_LTCCTR48_OUT       ((T_Reg32 *) 0xF0001B80)->bit15
#define GPTA0_LTCCTR48_RED       ((T_Reg32 *) 0xF0001B80)->bit4
#define GPTA0_LTCCTR48_REN       ((T_Reg32 *) 0xF0001B80)->bit3
#define GPTA0_LTCCTR48_SLO       ((T_Reg32 *) 0xF0001B80)->bit6

// GPTA0 Local Timer Cell Control Register 49
#define GPTA0_LTCCTR49         (*((uword volatile *) 0xF0001B88))
#define GPTA0_LTCCTR49_CEN       ((T_Reg32 *) 0xF0001B88)->bit10
#define GPTA0_LTCCTR49_CUD       ((T_Reg32 *) 0xF0001B88)->bit9
#define GPTA0_LTCCTR49_CUDCLR    ((T_Reg32 *) 0xF0001B88)->bit7
#define GPTA0_LTCCTR49_FED       ((T_Reg32 *) 0xF0001B88)->bit5
#define GPTA0_LTCCTR49_GBYP      ((T_Reg32 *) 0xF0001B88)->bit16
#define GPTA0_LTCCTR49_ILM       ((T_Reg32 *) 0xF0001B88)->bit8
#define GPTA0_LTCCTR49_OIA       ((T_Reg32 *) 0xF0001B88)->bit14
#define GPTA0_LTCCTR49_OSM       ((T_Reg32 *) 0xF0001B88)->bit2
#define GPTA0_LTCCTR49_OUT       ((T_Reg32 *) 0xF0001B88)->bit15
#define GPTA0_LTCCTR49_RED       ((T_Reg32 *) 0xF0001B88)->bit4
#define GPTA0_LTCCTR49_REN       ((T_Reg32 *) 0xF0001B88)->bit3
#define GPTA0_LTCCTR49_SLO       ((T_Reg32 *) 0xF0001B88)->bit6

// GPTA0 Local Timer Cell Control Register 50
#define GPTA0_LTCCTR50         (*((uword volatile *) 0xF0001B90))
#define GPTA0_LTCCTR50_CEN       ((T_Reg32 *) 0xF0001B90)->bit10
#define GPTA0_LTCCTR50_CUD       ((T_Reg32 *) 0xF0001B90)->bit9
#define GPTA0_LTCCTR50_CUDCLR    ((T_Reg32 *) 0xF0001B90)->bit7
#define GPTA0_LTCCTR50_FED       ((T_Reg32 *) 0xF0001B90)->bit5
#define GPTA0_LTCCTR50_GBYP      ((T_Reg32 *) 0xF0001B90)->bit16
#define GPTA0_LTCCTR50_ILM       ((T_Reg32 *) 0xF0001B90)->bit8
#define GPTA0_LTCCTR50_OIA       ((T_Reg32 *) 0xF0001B90)->bit14
#define GPTA0_LTCCTR50_OSM       ((T_Reg32 *) 0xF0001B90)->bit2
#define GPTA0_LTCCTR50_OUT       ((T_Reg32 *) 0xF0001B90)->bit15
#define GPTA0_LTCCTR50_RED       ((T_Reg32 *) 0xF0001B90)->bit4
#define GPTA0_LTCCTR50_REN       ((T_Reg32 *) 0xF0001B90)->bit3
#define GPTA0_LTCCTR50_SLO       ((T_Reg32 *) 0xF0001B90)->bit6

// GPTA0 Local Timer Cell Control Register 51
#define GPTA0_LTCCTR51         (*((uword volatile *) 0xF0001B98))
#define GPTA0_LTCCTR51_CEN       ((T_Reg32 *) 0xF0001B98)->bit10
#define GPTA0_LTCCTR51_CUD       ((T_Reg32 *) 0xF0001B98)->bit9
#define GPTA0_LTCCTR51_CUDCLR    ((T_Reg32 *) 0xF0001B98)->bit7
#define GPTA0_LTCCTR51_FED       ((T_Reg32 *) 0xF0001B98)->bit5
#define GPTA0_LTCCTR51_GBYP      ((T_Reg32 *) 0xF0001B98)->bit16
#define GPTA0_LTCCTR51_ILM       ((T_Reg32 *) 0xF0001B98)->bit8
#define GPTA0_LTCCTR51_OIA       ((T_Reg32 *) 0xF0001B98)->bit14
#define GPTA0_LTCCTR51_OSM       ((T_Reg32 *) 0xF0001B98)->bit2
#define GPTA0_LTCCTR51_OUT       ((T_Reg32 *) 0xF0001B98)->bit15
#define GPTA0_LTCCTR51_RED       ((T_Reg32 *) 0xF0001B98)->bit4
#define GPTA0_LTCCTR51_REN       ((T_Reg32 *) 0xF0001B98)->bit3
#define GPTA0_LTCCTR51_SLO       ((T_Reg32 *) 0xF0001B98)->bit6

// GPTA0 Local Timer Cell Control Register 52
#define GPTA0_LTCCTR52         (*((uword volatile *) 0xF0001BA0))
#define GPTA0_LTCCTR52_CEN       ((T_Reg32 *) 0xF0001BA0)->bit10
#define GPTA0_LTCCTR52_CUD       ((T_Reg32 *) 0xF0001BA0)->bit9
#define GPTA0_LTCCTR52_CUDCLR    ((T_Reg32 *) 0xF0001BA0)->bit7
#define GPTA0_LTCCTR52_FED       ((T_Reg32 *) 0xF0001BA0)->bit5
#define GPTA0_LTCCTR52_GBYP      ((T_Reg32 *) 0xF0001BA0)->bit16
#define GPTA0_LTCCTR52_ILM       ((T_Reg32 *) 0xF0001BA0)->bit8
#define GPTA0_LTCCTR52_OIA       ((T_Reg32 *) 0xF0001BA0)->bit14
#define GPTA0_LTCCTR52_OSM       ((T_Reg32 *) 0xF0001BA0)->bit2
#define GPTA0_LTCCTR52_OUT       ((T_Reg32 *) 0xF0001BA0)->bit15
#define GPTA0_LTCCTR52_RED       ((T_Reg32 *) 0xF0001BA0)->bit4
#define GPTA0_LTCCTR52_REN       ((T_Reg32 *) 0xF0001BA0)->bit3
#define GPTA0_LTCCTR52_SLO       ((T_Reg32 *) 0xF0001BA0)->bit6

// GPTA0 Local Timer Cell Control Register 53
#define GPTA0_LTCCTR53         (*((uword volatile *) 0xF0001BA8))
#define GPTA0_LTCCTR53_CEN       ((T_Reg32 *) 0xF0001BA8)->bit10
#define GPTA0_LTCCTR53_CUD       ((T_Reg32 *) 0xF0001BA8)->bit9
#define GPTA0_LTCCTR53_CUDCLR    ((T_Reg32 *) 0xF0001BA8)->bit7
#define GPTA0_LTCCTR53_FED       ((T_Reg32 *) 0xF0001BA8)->bit5
#define GPTA0_LTCCTR53_GBYP      ((T_Reg32 *) 0xF0001BA8)->bit16
#define GPTA0_LTCCTR53_ILM       ((T_Reg32 *) 0xF0001BA8)->bit8
#define GPTA0_LTCCTR53_OIA       ((T_Reg32 *) 0xF0001BA8)->bit14
#define GPTA0_LTCCTR53_OSM       ((T_Reg32 *) 0xF0001BA8)->bit2
#define GPTA0_LTCCTR53_OUT       ((T_Reg32 *) 0xF0001BA8)->bit15
#define GPTA0_LTCCTR53_RED       ((T_Reg32 *) 0xF0001BA8)->bit4
#define GPTA0_LTCCTR53_REN       ((T_Reg32 *) 0xF0001BA8)->bit3
#define GPTA0_LTCCTR53_SLO       ((T_Reg32 *) 0xF0001BA8)->bit6

// GPTA0 Local Timer Cell Control Register 54
#define GPTA0_LTCCTR54         (*((uword volatile *) 0xF0001BB0))
#define GPTA0_LTCCTR54_CEN       ((T_Reg32 *) 0xF0001BB0)->bit10
#define GPTA0_LTCCTR54_CUD       ((T_Reg32 *) 0xF0001BB0)->bit9
#define GPTA0_LTCCTR54_CUDCLR    ((T_Reg32 *) 0xF0001BB0)->bit7
#define GPTA0_LTCCTR54_FED       ((T_Reg32 *) 0xF0001BB0)->bit5
#define GPTA0_LTCCTR54_GBYP      ((T_Reg32 *) 0xF0001BB0)->bit16
#define GPTA0_LTCCTR54_ILM       ((T_Reg32 *) 0xF0001BB0)->bit8
#define GPTA0_LTCCTR54_OIA       ((T_Reg32 *) 0xF0001BB0)->bit14
#define GPTA0_LTCCTR54_OSM       ((T_Reg32 *) 0xF0001BB0)->bit2
#define GPTA0_LTCCTR54_OUT       ((T_Reg32 *) 0xF0001BB0)->bit15
#define GPTA0_LTCCTR54_RED       ((T_Reg32 *) 0xF0001BB0)->bit4
#define GPTA0_LTCCTR54_REN       ((T_Reg32 *) 0xF0001BB0)->bit3
#define GPTA0_LTCCTR54_SLO       ((T_Reg32 *) 0xF0001BB0)->bit6

// GPTA0 Local Timer Cell Control Register 55
#define GPTA0_LTCCTR55         (*((uword volatile *) 0xF0001BB8))
#define GPTA0_LTCCTR55_CEN       ((T_Reg32 *) 0xF0001BB8)->bit10
#define GPTA0_LTCCTR55_CUD       ((T_Reg32 *) 0xF0001BB8)->bit9
#define GPTA0_LTCCTR55_CUDCLR    ((T_Reg32 *) 0xF0001BB8)->bit7
#define GPTA0_LTCCTR55_FED       ((T_Reg32 *) 0xF0001BB8)->bit5
#define GPTA0_LTCCTR55_GBYP      ((T_Reg32 *) 0xF0001BB8)->bit16
#define GPTA0_LTCCTR55_ILM       ((T_Reg32 *) 0xF0001BB8)->bit8
#define GPTA0_LTCCTR55_OIA       ((T_Reg32 *) 0xF0001BB8)->bit14
#define GPTA0_LTCCTR55_OSM       ((T_Reg32 *) 0xF0001BB8)->bit2
#define GPTA0_LTCCTR55_OUT       ((T_Reg32 *) 0xF0001BB8)->bit15
#define GPTA0_LTCCTR55_RED       ((T_Reg32 *) 0xF0001BB8)->bit4
#define GPTA0_LTCCTR55_REN       ((T_Reg32 *) 0xF0001BB8)->bit3
#define GPTA0_LTCCTR55_SLO       ((T_Reg32 *) 0xF0001BB8)->bit6

// GPTA0 Local Timer Cell Control Register 56
#define GPTA0_LTCCTR56         (*((uword volatile *) 0xF0001BC0))
#define GPTA0_LTCCTR56_CEN       ((T_Reg32 *) 0xF0001BC0)->bit10
#define GPTA0_LTCCTR56_CUD       ((T_Reg32 *) 0xF0001BC0)->bit9
#define GPTA0_LTCCTR56_CUDCLR    ((T_Reg32 *) 0xF0001BC0)->bit7
#define GPTA0_LTCCTR56_FED       ((T_Reg32 *) 0xF0001BC0)->bit5
#define GPTA0_LTCCTR56_GBYP      ((T_Reg32 *) 0xF0001BC0)->bit16
#define GPTA0_LTCCTR56_ILM       ((T_Reg32 *) 0xF0001BC0)->bit8
#define GPTA0_LTCCTR56_OIA       ((T_Reg32 *) 0xF0001BC0)->bit14
#define GPTA0_LTCCTR56_OSM       ((T_Reg32 *) 0xF0001BC0)->bit2
#define GPTA0_LTCCTR56_OUT       ((T_Reg32 *) 0xF0001BC0)->bit15
#define GPTA0_LTCCTR56_RED       ((T_Reg32 *) 0xF0001BC0)->bit4
#define GPTA0_LTCCTR56_REN       ((T_Reg32 *) 0xF0001BC0)->bit3
#define GPTA0_LTCCTR56_SLO       ((T_Reg32 *) 0xF0001BC0)->bit6

// GPTA0 Local Timer Cell Control Register 57
#define GPTA0_LTCCTR57         (*((uword volatile *) 0xF0001BC8))
#define GPTA0_LTCCTR57_CEN       ((T_Reg32 *) 0xF0001BC8)->bit10
#define GPTA0_LTCCTR57_CUD       ((T_Reg32 *) 0xF0001BC8)->bit9
#define GPTA0_LTCCTR57_CUDCLR    ((T_Reg32 *) 0xF0001BC8)->bit7
#define GPTA0_LTCCTR57_FED       ((T_Reg32 *) 0xF0001BC8)->bit5
#define GPTA0_LTCCTR57_GBYP      ((T_Reg32 *) 0xF0001BC8)->bit16
#define GPTA0_LTCCTR57_ILM       ((T_Reg32 *) 0xF0001BC8)->bit8
#define GPTA0_LTCCTR57_OIA       ((T_Reg32 *) 0xF0001BC8)->bit14
#define GPTA0_LTCCTR57_OSM       ((T_Reg32 *) 0xF0001BC8)->bit2
#define GPTA0_LTCCTR57_OUT       ((T_Reg32 *) 0xF0001BC8)->bit15
#define GPTA0_LTCCTR57_RED       ((T_Reg32 *) 0xF0001BC8)->bit4
#define GPTA0_LTCCTR57_REN       ((T_Reg32 *) 0xF0001BC8)->bit3
#define GPTA0_LTCCTR57_SLO       ((T_Reg32 *) 0xF0001BC8)->bit6

// GPTA0 Local Timer Cell Control Register 58
#define GPTA0_LTCCTR58         (*((uword volatile *) 0xF0001BD0))
#define GPTA0_LTCCTR58_CEN       ((T_Reg32 *) 0xF0001BD0)->bit10
#define GPTA0_LTCCTR58_CUD       ((T_Reg32 *) 0xF0001BD0)->bit9
#define GPTA0_LTCCTR58_CUDCLR    ((T_Reg32 *) 0xF0001BD0)->bit7
#define GPTA0_LTCCTR58_FED       ((T_Reg32 *) 0xF0001BD0)->bit5
#define GPTA0_LTCCTR58_GBYP      ((T_Reg32 *) 0xF0001BD0)->bit16
#define GPTA0_LTCCTR58_ILM       ((T_Reg32 *) 0xF0001BD0)->bit8
#define GPTA0_LTCCTR58_OIA       ((T_Reg32 *) 0xF0001BD0)->bit14
#define GPTA0_LTCCTR58_OSM       ((T_Reg32 *) 0xF0001BD0)->bit2
#define GPTA0_LTCCTR58_OUT       ((T_Reg32 *) 0xF0001BD0)->bit15
#define GPTA0_LTCCTR58_RED       ((T_Reg32 *) 0xF0001BD0)->bit4
#define GPTA0_LTCCTR58_REN       ((T_Reg32 *) 0xF0001BD0)->bit3
#define GPTA0_LTCCTR58_SLO       ((T_Reg32 *) 0xF0001BD0)->bit6

// GPTA0 Local Timer Cell Control Register 59
#define GPTA0_LTCCTR59         (*((uword volatile *) 0xF0001BD8))
#define GPTA0_LTCCTR59_CEN       ((T_Reg32 *) 0xF0001BD8)->bit10
#define GPTA0_LTCCTR59_CUD       ((T_Reg32 *) 0xF0001BD8)->bit9
#define GPTA0_LTCCTR59_CUDCLR    ((T_Reg32 *) 0xF0001BD8)->bit7
#define GPTA0_LTCCTR59_FED       ((T_Reg32 *) 0xF0001BD8)->bit5
#define GPTA0_LTCCTR59_GBYP      ((T_Reg32 *) 0xF0001BD8)->bit16
#define GPTA0_LTCCTR59_ILM       ((T_Reg32 *) 0xF0001BD8)->bit8
#define GPTA0_LTCCTR59_OIA       ((T_Reg32 *) 0xF0001BD8)->bit14
#define GPTA0_LTCCTR59_OSM       ((T_Reg32 *) 0xF0001BD8)->bit2
#define GPTA0_LTCCTR59_OUT       ((T_Reg32 *) 0xF0001BD8)->bit15
#define GPTA0_LTCCTR59_RED       ((T_Reg32 *) 0xF0001BD8)->bit4
#define GPTA0_LTCCTR59_REN       ((T_Reg32 *) 0xF0001BD8)->bit3
#define GPTA0_LTCCTR59_SLO       ((T_Reg32 *) 0xF0001BD8)->bit6

// GPTA0 Local Timer Cell Control Register 60
#define GPTA0_LTCCTR60         (*((uword volatile *) 0xF0001BE0))
#define GPTA0_LTCCTR60_CEN       ((T_Reg32 *) 0xF0001BE0)->bit10
#define GPTA0_LTCCTR60_CUD       ((T_Reg32 *) 0xF0001BE0)->bit9
#define GPTA0_LTCCTR60_CUDCLR    ((T_Reg32 *) 0xF0001BE0)->bit7
#define GPTA0_LTCCTR60_FED       ((T_Reg32 *) 0xF0001BE0)->bit5
#define GPTA0_LTCCTR60_GBYP      ((T_Reg32 *) 0xF0001BE0)->bit16
#define GPTA0_LTCCTR60_ILM       ((T_Reg32 *) 0xF0001BE0)->bit8
#define GPTA0_LTCCTR60_OIA       ((T_Reg32 *) 0xF0001BE0)->bit14
#define GPTA0_LTCCTR60_OSM       ((T_Reg32 *) 0xF0001BE0)->bit2
#define GPTA0_LTCCTR60_OUT       ((T_Reg32 *) 0xF0001BE0)->bit15
#define GPTA0_LTCCTR60_RED       ((T_Reg32 *) 0xF0001BE0)->bit4
#define GPTA0_LTCCTR60_REN       ((T_Reg32 *) 0xF0001BE0)->bit3
#define GPTA0_LTCCTR60_SLO       ((T_Reg32 *) 0xF0001BE0)->bit6

// GPTA0 Local Timer Cell Control Register 61
#define GPTA0_LTCCTR61         (*((uword volatile *) 0xF0001BE8))
#define GPTA0_LTCCTR61_CEN       ((T_Reg32 *) 0xF0001BE8)->bit10
#define GPTA0_LTCCTR61_CUD       ((T_Reg32 *) 0xF0001BE8)->bit9
#define GPTA0_LTCCTR61_CUDCLR    ((T_Reg32 *) 0xF0001BE8)->bit7
#define GPTA0_LTCCTR61_FED       ((T_Reg32 *) 0xF0001BE8)->bit5
#define GPTA0_LTCCTR61_GBYP      ((T_Reg32 *) 0xF0001BE8)->bit16
#define GPTA0_LTCCTR61_ILM       ((T_Reg32 *) 0xF0001BE8)->bit8
#define GPTA0_LTCCTR61_OIA       ((T_Reg32 *) 0xF0001BE8)->bit14
#define GPTA0_LTCCTR61_OSM       ((T_Reg32 *) 0xF0001BE8)->bit2
#define GPTA0_LTCCTR61_OUT       ((T_Reg32 *) 0xF0001BE8)->bit15
#define GPTA0_LTCCTR61_RED       ((T_Reg32 *) 0xF0001BE8)->bit4
#define GPTA0_LTCCTR61_REN       ((T_Reg32 *) 0xF0001BE8)->bit3
#define GPTA0_LTCCTR61_SLO       ((T_Reg32 *) 0xF0001BE8)->bit6

// GPTA0 Local Timer Cell Control Register 62
#define GPTA0_LTCCTR62         (*((uword volatile *) 0xF0001BF0))
#define GPTA0_LTCCTR62_CEN       ((T_Reg32 *) 0xF0001BF0)->bit10
#define GPTA0_LTCCTR62_CUD       ((T_Reg32 *) 0xF0001BF0)->bit9
#define GPTA0_LTCCTR62_CUDCLR    ((T_Reg32 *) 0xF0001BF0)->bit7
#define GPTA0_LTCCTR62_FED       ((T_Reg32 *) 0xF0001BF0)->bit5
#define GPTA0_LTCCTR62_GBYP      ((T_Reg32 *) 0xF0001BF0)->bit16
#define GPTA0_LTCCTR62_ILM       ((T_Reg32 *) 0xF0001BF0)->bit8
#define GPTA0_LTCCTR62_OIA       ((T_Reg32 *) 0xF0001BF0)->bit14
#define GPTA0_LTCCTR62_OSM       ((T_Reg32 *) 0xF0001BF0)->bit2
#define GPTA0_LTCCTR62_OUT       ((T_Reg32 *) 0xF0001BF0)->bit15
#define GPTA0_LTCCTR62_RED       ((T_Reg32 *) 0xF0001BF0)->bit4
#define GPTA0_LTCCTR62_REN       ((T_Reg32 *) 0xF0001BF0)->bit3
#define GPTA0_LTCCTR62_SLO       ((T_Reg32 *) 0xF0001BF0)->bit6

// GPTA0 Local Timer Cell Control Register 63
#define GPTA0_LTCCTR63         (*((uword volatile *) 0xF0001BF8))
#define GPTA0_LTCCTR63_BRM       ((T_Reg32 *) 0xF0001BF8)->bit0
#define GPTA0_LTCCTR63_CEN       ((T_Reg32 *) 0xF0001BF8)->bit10
#define GPTA0_LTCCTR63_FED       ((T_Reg32 *) 0xF0001BF8)->bit5
#define GPTA0_LTCCTR63_ILM       ((T_Reg32 *) 0xF0001BF8)->bit8
#define GPTA0_LTCCTR63_OSM       ((T_Reg32 *) 0xF0001BF8)->bit1
#define GPTA0_LTCCTR63_OUT       ((T_Reg32 *) 0xF0001BF8)->bit15
#define GPTA0_LTCCTR63_RED       ((T_Reg32 *) 0xF0001BF8)->bit4

// GPTA0 Local Timer Cell X Register 00
#define GPTA0_LTCXR00          (*((uword volatile *) 0xF0001A04))

// GPTA0 Local Timer Cell X Register 01
#define GPTA0_LTCXR01          (*((uword volatile *) 0xF0001A0C))

// GPTA0 Local Timer Cell X Register 02
#define GPTA0_LTCXR02          (*((uword volatile *) 0xF0001A14))

// GPTA0 Local Timer Cell X Register 03
#define GPTA0_LTCXR03          (*((uword volatile *) 0xF0001A1C))

// GPTA0 Local Timer Cell X Register 04
#define GPTA0_LTCXR04          (*((uword volatile *) 0xF0001A24))

// GPTA0 Local Timer Cell X Register 05
#define GPTA0_LTCXR05          (*((uword volatile *) 0xF0001A2C))

// GPTA0 Local Timer Cell X Register 06
#define GPTA0_LTCXR06          (*((uword volatile *) 0xF0001A34))

// GPTA0 Local Timer Cell X Register 07
#define GPTA0_LTCXR07          (*((uword volatile *) 0xF0001A3C))

// GPTA0 Local Timer Cell X Register 08
#define GPTA0_LTCXR08          (*((uword volatile *) 0xF0001A44))

// GPTA0 Local Timer Cell X Register 09
#define GPTA0_LTCXR09          (*((uword volatile *) 0xF0001A4C))

// GPTA0 Local Timer Cell X Register 10
#define GPTA0_LTCXR10          (*((uword volatile *) 0xF0001A54))

// GPTA0 Local Timer Cell X Register 11
#define GPTA0_LTCXR11          (*((uword volatile *) 0xF0001A5C))

// GPTA0 Local Timer Cell X Register 12
#define GPTA0_LTCXR12          (*((uword volatile *) 0xF0001A64))

// GPTA0 Local Timer Cell X Register 13
#define GPTA0_LTCXR13          (*((uword volatile *) 0xF0001A6C))

// GPTA0 Local Timer Cell X Register 14
#define GPTA0_LTCXR14          (*((uword volatile *) 0xF0001A74))

// GPTA0 Local Timer Cell X Register 15
#define GPTA0_LTCXR15          (*((uword volatile *) 0xF0001A7C))

// GPTA0 Local Timer Cell X Register 16
#define GPTA0_LTCXR16          (*((uword volatile *) 0xF0001A84))

// GPTA0 Local Timer Cell X Register 17
#define GPTA0_LTCXR17          (*((uword volatile *) 0xF0001A8C))

// GPTA0 Local Timer Cell X Register 18
#define GPTA0_LTCXR18          (*((uword volatile *) 0xF0001A94))

// GPTA0 Local Timer Cell X Register 19
#define GPTA0_LTCXR19          (*((uword volatile *) 0xF0001A9C))

// GPTA0 Local Timer Cell X Register 20
#define GPTA0_LTCXR20          (*((uword volatile *) 0xF0001AA4))

// GPTA0 Local Timer Cell X Register 21
#define GPTA0_LTCXR21          (*((uword volatile *) 0xF0001AAC))

// GPTA0 Local Timer Cell X Register 22
#define GPTA0_LTCXR22          (*((uword volatile *) 0xF0001AB4))

// GPTA0 Local Timer Cell X Register 23
#define GPTA0_LTCXR23          (*((uword volatile *) 0xF0001ABC))

// GPTA0 Local Timer Cell X Register 24
#define GPTA0_LTCXR24          (*((uword volatile *) 0xF0001AC4))

// GPTA0 Local Timer Cell X Register 25
#define GPTA0_LTCXR25          (*((uword volatile *) 0xF0001ACC))

// GPTA0 Local Timer Cell X Register 26
#define GPTA0_LTCXR26          (*((uword volatile *) 0xF0001AD4))

// GPTA0 Local Timer Cell X Register 27
#define GPTA0_LTCXR27          (*((uword volatile *) 0xF0001ADC))

// GPTA0 Local Timer Cell X Register 28
#define GPTA0_LTCXR28          (*((uword volatile *) 0xF0001AE4))

// GPTA0 Local Timer Cell X Register 29
#define GPTA0_LTCXR29          (*((uword volatile *) 0xF0001AEC))

// GPTA0 Local Timer Cell X Register 30
#define GPTA0_LTCXR30          (*((uword volatile *) 0xF0001AF4))

// GPTA0 Local Timer Cell X Register 31
#define GPTA0_LTCXR31          (*((uword volatile *) 0xF0001AFC))

// GPTA0 Local Timer Cell X Register 32
#define GPTA0_LTCXR32          (*((uword volatile *) 0xF0001B04))

// GPTA0 Local Timer Cell X Register 33
#define GPTA0_LTCXR33          (*((uword volatile *) 0xF0001B0C))

// GPTA0 Local Timer Cell X Register 34
#define GPTA0_LTCXR34          (*((uword volatile *) 0xF0001B14))

// GPTA0 Local Timer Cell X Register 35
#define GPTA0_LTCXR35          (*((uword volatile *) 0xF0001B1C))

// GPTA0 Local Timer Cell X Register 36
#define GPTA0_LTCXR36          (*((uword volatile *) 0xF0001B24))

// GPTA0 Local Timer Cell X Register 37
#define GPTA0_LTCXR37          (*((uword volatile *) 0xF0001B2C))

// GPTA0 Local Timer Cell X Register 38
#define GPTA0_LTCXR38          (*((uword volatile *) 0xF0001B34))

// GPTA0 Local Timer Cell X Register 39
#define GPTA0_LTCXR39          (*((uword volatile *) 0xF0001B3C))

// GPTA0 Local Timer Cell X Register 40
#define GPTA0_LTCXR40          (*((uword volatile *) 0xF0001B44))

// GPTA0 Local Timer Cell X Register 41
#define GPTA0_LTCXR41          (*((uword volatile *) 0xF0001B4C))

// GPTA0 Local Timer Cell X Register 42
#define GPTA0_LTCXR42          (*((uword volatile *) 0xF0001B54))

// GPTA0 Local Timer Cell X Register 43
#define GPTA0_LTCXR43          (*((uword volatile *) 0xF0001B5C))

// GPTA0 Local Timer Cell X Register 44
#define GPTA0_LTCXR44          (*((uword volatile *) 0xF0001B64))

// GPTA0 Local Timer Cell X Register 45
#define GPTA0_LTCXR45          (*((uword volatile *) 0xF0001B6C))

// GPTA0 Local Timer Cell X Register 46
#define GPTA0_LTCXR46          (*((uword volatile *) 0xF0001B74))

// GPTA0 Local Timer Cell X Register 47
#define GPTA0_LTCXR47          (*((uword volatile *) 0xF0001B7C))

// GPTA0 Local Timer Cell X Register 48
#define GPTA0_LTCXR48          (*((uword volatile *) 0xF0001B84))

// GPTA0 Local Timer Cell X Register 49
#define GPTA0_LTCXR49          (*((uword volatile *) 0xF0001B8C))

// GPTA0 Local Timer Cell X Register 50
#define GPTA0_LTCXR50          (*((uword volatile *) 0xF0001B94))

// GPTA0 Local Timer Cell X Register 51
#define GPTA0_LTCXR51          (*((uword volatile *) 0xF0001B9C))

// GPTA0 Local Timer Cell X Register 52
#define GPTA0_LTCXR52          (*((uword volatile *) 0xF0001BA4))

// GPTA0 Local Timer Cell X Register 53
#define GPTA0_LTCXR53          (*((uword volatile *) 0xF0001BAC))

// GPTA0 Local Timer Cell X Register 54
#define GPTA0_LTCXR54          (*((uword volatile *) 0xF0001BB4))

// GPTA0 Local Timer Cell X Register 55
#define GPTA0_LTCXR55          (*((uword volatile *) 0xF0001BBC))

// GPTA0 Local Timer Cell X Register 56
#define GPTA0_LTCXR56          (*((uword volatile *) 0xF0001BC4))

// GPTA0 Local Timer Cell X Register 57
#define GPTA0_LTCXR57          (*((uword volatile *) 0xF0001BCC))

// GPTA0 Local Timer Cell X Register 58
#define GPTA0_LTCXR58          (*((uword volatile *) 0xF0001BD4))

// GPTA0 Local Timer Cell X Register 59
#define GPTA0_LTCXR59          (*((uword volatile *) 0xF0001BDC))

// GPTA0 Local Timer Cell X Register 60
#define GPTA0_LTCXR60          (*((uword volatile *) 0xF0001BE4))

// GPTA0 Local Timer Cell X Register 61
#define GPTA0_LTCXR61          (*((uword volatile *) 0xF0001BEC))

// GPTA0 Local Timer Cell X Register 62
#define GPTA0_LTCXR62          (*((uword volatile *) 0xF0001BF4))

// GPTA0 Local Timer Cell X Register 63
#define GPTA0_LTCXR63          (*((uword volatile *) 0xF0001BFC))

// GPTA-to-MSC Multiplexer Control Register 00
#define GPTA0_MMXCTR00         (*((uword volatile *) 0xF0001F00))

// GPTA-to-MSC Multiplexer Control Register 01
#define GPTA0_MMXCTR01         (*((uword volatile *) 0xF0001F04))

// GPTA0 Multiplexer Register Array Control Register
#define GPTA0_MRACTL           (*((uword volatile *) 0xF0001838))
#define GPTA0_MRACTL_FIFOFULL    ((T_Reg32 *) 0xF0001838)->bit2
#define GPTA0_MRACTL_MAEN        ((T_Reg32 *) 0xF0001838)->bit0
#define GPTA0_MRACTL_WCRES       ((T_Reg32 *) 0xF0001838)->bit1

// GPTA0 Multiplexer Register Array Data In Register
#define GPTA0_MRADIN           (*((uword volatile *) 0xF000183C))

// GPTA0 Multiplexer Register Array Data Out Register
#define GPTA0_MRADOUT          (*((uword volatile *) 0xF0001840))

// GPTA0 Phase Discrimination Logic Control Register
#define GPTA0_PDLCTR           (*((uword volatile *) 0xF0001878))
#define GPTA0_PDLCTR_ERR0        ((T_Reg32 *) 0xF0001878)->bit2
#define GPTA0_PDLCTR_ERR1        ((T_Reg32 *) 0xF0001878)->bit6
#define GPTA0_PDLCTR_MUX0        ((T_Reg32 *) 0xF0001878)->bit0
#define GPTA0_PDLCTR_MUX1        ((T_Reg32 *) 0xF0001878)->bit4
#define GPTA0_PDLCTR_TSE0        ((T_Reg32 *) 0xF0001878)->bit1
#define GPTA0_PDLCTR_TSE1        ((T_Reg32 *) 0xF0001878)->bit5

// GPTA0 Phase Locked Loop Counter Register
#define GPTA0_PLLCNT           (*((uword volatile *) 0xF00018C8))

// GPTA0 Phase Locked Loop Control Register
#define GPTA0_PLLCTR           (*((uword volatile *) 0xF00018C0))
#define GPTA0_PLLCTR_AEN         ((T_Reg32 *) 0xF00018C0)->bit2
#define GPTA0_PLLCTR_PEN         ((T_Reg32 *) 0xF00018C0)->bit3
#define GPTA0_PLLCTR_REN         ((T_Reg32 *) 0xF00018C0)->bit4

// GPTA0 Phase Locked Loop Delta Register
#define GPTA0_PLLDTR           (*((uword volatile *) 0xF00018D4))

// GPTA0 Phase Locked Loop Microtick Register
#define GPTA0_PLLMTI           (*((uword volatile *) 0xF00018C4))

// GPTA0 Phase Locked Loop Reload Register
#define GPTA0_PLLREV           (*((uword volatile *) 0xF00018D0))

// GPTA0 Phase Locked Loop Step Register
#define GPTA0_PLLSTP           (*((uword volatile *) 0xF00018CC))

// GPTA0 Interrupt Service Request Control Register 00
#define GPTA0_SRC00            (*((uword volatile *) 0xF0001FFC))
#define GPTA0_SRC00_CLRR         ((T_Reg32 *) 0xF0001FFC)->bit14
#define GPTA0_SRC00_SETR         ((T_Reg32 *) 0xF0001FFC)->bit15
#define GPTA0_SRC00_SRE          ((T_Reg32 *) 0xF0001FFC)->bit12
#define GPTA0_SRC00_SRR          ((T_Reg32 *) 0xF0001FFC)->bit13
#define GPTA0_SRC00_TOS          ((T_Reg32 *) 0xF0001FFC)->bit10

// GPTA0 Interrupt Service Request Control Register 01
#define GPTA0_SRC01            (*((uword volatile *) 0xF0001FF8))
#define GPTA0_SRC01_CLRR         ((T_Reg32 *) 0xF0001FF8)->bit14
#define GPTA0_SRC01_SETR         ((T_Reg32 *) 0xF0001FF8)->bit15
#define GPTA0_SRC01_SRE          ((T_Reg32 *) 0xF0001FF8)->bit12
#define GPTA0_SRC01_SRR          ((T_Reg32 *) 0xF0001FF8)->bit13
#define GPTA0_SRC01_TOS          ((T_Reg32 *) 0xF0001FF8)->bit10

// GPTA0 Interrupt Service Request Control Register 02
#define GPTA0_SRC02            (*((uword volatile *) 0xF0001FF4))
#define GPTA0_SRC02_CLRR         ((T_Reg32 *) 0xF0001FF4)->bit14
#define GPTA0_SRC02_SETR         ((T_Reg32 *) 0xF0001FF4)->bit15
#define GPTA0_SRC02_SRE          ((T_Reg32 *) 0xF0001FF4)->bit12
#define GPTA0_SRC02_SRR          ((T_Reg32 *) 0xF0001FF4)->bit13
#define GPTA0_SRC02_TOS          ((T_Reg32 *) 0xF0001FF4)->bit10

// GPTA0 Interrupt Service Request Control Register 03
#define GPTA0_SRC03            (*((uword volatile *) 0xF0001FF0))
#define GPTA0_SRC03_CLRR         ((T_Reg32 *) 0xF0001FF0)->bit14
#define GPTA0_SRC03_SETR         ((T_Reg32 *) 0xF0001FF0)->bit15
#define GPTA0_SRC03_SRE          ((T_Reg32 *) 0xF0001FF0)->bit12
#define GPTA0_SRC03_SRR          ((T_Reg32 *) 0xF0001FF0)->bit13
#define GPTA0_SRC03_TOS          ((T_Reg32 *) 0xF0001FF0)->bit10

// GPTA0 Interrupt Service Request Control Register 04
#define GPTA0_SRC04            (*((uword volatile *) 0xF0001FEC))
#define GPTA0_SRC04_CLRR         ((T_Reg32 *) 0xF0001FEC)->bit14
#define GPTA0_SRC04_SETR         ((T_Reg32 *) 0xF0001FEC)->bit15
#define GPTA0_SRC04_SRE          ((T_Reg32 *) 0xF0001FEC)->bit12
#define GPTA0_SRC04_SRR          ((T_Reg32 *) 0xF0001FEC)->bit13
#define GPTA0_SRC04_TOS          ((T_Reg32 *) 0xF0001FEC)->bit10

// GPTA0 Interrupt Service Request Control Register 05
#define GPTA0_SRC05            (*((uword volatile *) 0xF0001FE8))
#define GPTA0_SRC05_CLRR         ((T_Reg32 *) 0xF0001FE8)->bit14
#define GPTA0_SRC05_SETR         ((T_Reg32 *) 0xF0001FE8)->bit15
#define GPTA0_SRC05_SRE          ((T_Reg32 *) 0xF0001FE8)->bit12
#define GPTA0_SRC05_SRR          ((T_Reg32 *) 0xF0001FE8)->bit13
#define GPTA0_SRC05_TOS          ((T_Reg32 *) 0xF0001FE8)->bit10

// GPTA0 Interrupt Service Request Control Register 06
#define GPTA0_SRC06            (*((uword volatile *) 0xF0001FE4))
#define GPTA0_SRC06_CLRR         ((T_Reg32 *) 0xF0001FE4)->bit14
#define GPTA0_SRC06_SETR         ((T_Reg32 *) 0xF0001FE4)->bit15
#define GPTA0_SRC06_SRE          ((T_Reg32 *) 0xF0001FE4)->bit12
#define GPTA0_SRC06_SRR          ((T_Reg32 *) 0xF0001FE4)->bit13
#define GPTA0_SRC06_TOS          ((T_Reg32 *) 0xF0001FE4)->bit10

// GPTA0 Interrupt Service Request Control Register 07
#define GPTA0_SRC07            (*((uword volatile *) 0xF0001FE0))
#define GPTA0_SRC07_CLRR         ((T_Reg32 *) 0xF0001FE0)->bit14
#define GPTA0_SRC07_SETR         ((T_Reg32 *) 0xF0001FE0)->bit15
#define GPTA0_SRC07_SRE          ((T_Reg32 *) 0xF0001FE0)->bit12
#define GPTA0_SRC07_SRR          ((T_Reg32 *) 0xF0001FE0)->bit13
#define GPTA0_SRC07_TOS          ((T_Reg32 *) 0xF0001FE0)->bit10

// GPTA0 Interrupt Service Request Control Register 08
#define GPTA0_SRC08            (*((uword volatile *) 0xF0001FDC))
#define GPTA0_SRC08_CLRR         ((T_Reg32 *) 0xF0001FDC)->bit14
#define GPTA0_SRC08_SETR         ((T_Reg32 *) 0xF0001FDC)->bit15
#define GPTA0_SRC08_SRE          ((T_Reg32 *) 0xF0001FDC)->bit12
#define GPTA0_SRC08_SRR          ((T_Reg32 *) 0xF0001FDC)->bit13
#define GPTA0_SRC08_TOS          ((T_Reg32 *) 0xF0001FDC)->bit10

// GPTA0 Interrupt Service Request Control Register 09
#define GPTA0_SRC09            (*((uword volatile *) 0xF0001FD8))
#define GPTA0_SRC09_CLRR         ((T_Reg32 *) 0xF0001FD8)->bit14
#define GPTA0_SRC09_SETR         ((T_Reg32 *) 0xF0001FD8)->bit15
#define GPTA0_SRC09_SRE          ((T_Reg32 *) 0xF0001FD8)->bit12
#define GPTA0_SRC09_SRR          ((T_Reg32 *) 0xF0001FD8)->bit13
#define GPTA0_SRC09_TOS          ((T_Reg32 *) 0xF0001FD8)->bit10

// GPTA0 Interrupt Service Request Control Register 10
#define GPTA0_SRC10            (*((uword volatile *) 0xF0001FD4))
#define GPTA0_SRC10_CLRR         ((T_Reg32 *) 0xF0001FD4)->bit14
#define GPTA0_SRC10_SETR         ((T_Reg32 *) 0xF0001FD4)->bit15
#define GPTA0_SRC10_SRE          ((T_Reg32 *) 0xF0001FD4)->bit12
#define GPTA0_SRC10_SRR          ((T_Reg32 *) 0xF0001FD4)->bit13
#define GPTA0_SRC10_TOS          ((T_Reg32 *) 0xF0001FD4)->bit10

// GPTA0 Interrupt Service Request Control Register 11
#define GPTA0_SRC11            (*((uword volatile *) 0xF0001FD0))
#define GPTA0_SRC11_CLRR         ((T_Reg32 *) 0xF0001FD0)->bit14
#define GPTA0_SRC11_SETR         ((T_Reg32 *) 0xF0001FD0)->bit15
#define GPTA0_SRC11_SRE          ((T_Reg32 *) 0xF0001FD0)->bit12
#define GPTA0_SRC11_SRR          ((T_Reg32 *) 0xF0001FD0)->bit13
#define GPTA0_SRC11_TOS          ((T_Reg32 *) 0xF0001FD0)->bit10

// GPTA0 Interrupt Service Request Control Register 12
#define GPTA0_SRC12            (*((uword volatile *) 0xF0001FCC))
#define GPTA0_SRC12_CLRR         ((T_Reg32 *) 0xF0001FCC)->bit14
#define GPTA0_SRC12_SETR         ((T_Reg32 *) 0xF0001FCC)->bit15
#define GPTA0_SRC12_SRE          ((T_Reg32 *) 0xF0001FCC)->bit12
#define GPTA0_SRC12_SRR          ((T_Reg32 *) 0xF0001FCC)->bit13
#define GPTA0_SRC12_TOS          ((T_Reg32 *) 0xF0001FCC)->bit10

// GPTA0 Interrupt Service Request Control Register 13
#define GPTA0_SRC13            (*((uword volatile *) 0xF0001FC8))
#define GPTA0_SRC13_CLRR         ((T_Reg32 *) 0xF0001FC8)->bit14
#define GPTA0_SRC13_SETR         ((T_Reg32 *) 0xF0001FC8)->bit15
#define GPTA0_SRC13_SRE          ((T_Reg32 *) 0xF0001FC8)->bit12
#define GPTA0_SRC13_SRR          ((T_Reg32 *) 0xF0001FC8)->bit13
#define GPTA0_SRC13_TOS          ((T_Reg32 *) 0xF0001FC8)->bit10

// GPTA0 Interrupt Service Request Control Register 14
#define GPTA0_SRC14            (*((uword volatile *) 0xF0001FC4))
#define GPTA0_SRC14_CLRR         ((T_Reg32 *) 0xF0001FC4)->bit14
#define GPTA0_SRC14_SETR         ((T_Reg32 *) 0xF0001FC4)->bit15
#define GPTA0_SRC14_SRE          ((T_Reg32 *) 0xF0001FC4)->bit12
#define GPTA0_SRC14_SRR          ((T_Reg32 *) 0xF0001FC4)->bit13
#define GPTA0_SRC14_TOS          ((T_Reg32 *) 0xF0001FC4)->bit10

// GPTA0 Interrupt Service Request Control Register 15
#define GPTA0_SRC15            (*((uword volatile *) 0xF0001FC0))
#define GPTA0_SRC15_CLRR         ((T_Reg32 *) 0xF0001FC0)->bit14
#define GPTA0_SRC15_SETR         ((T_Reg32 *) 0xF0001FC0)->bit15
#define GPTA0_SRC15_SRE          ((T_Reg32 *) 0xF0001FC0)->bit12
#define GPTA0_SRC15_SRR          ((T_Reg32 *) 0xF0001FC0)->bit13
#define GPTA0_SRC15_TOS          ((T_Reg32 *) 0xF0001FC0)->bit10

// GPTA0 Interrupt Service Request Control Register 16
#define GPTA0_SRC16            (*((uword volatile *) 0xF0001FBC))
#define GPTA0_SRC16_CLRR         ((T_Reg32 *) 0xF0001FBC)->bit14
#define GPTA0_SRC16_SETR         ((T_Reg32 *) 0xF0001FBC)->bit15
#define GPTA0_SRC16_SRE          ((T_Reg32 *) 0xF0001FBC)->bit12
#define GPTA0_SRC16_SRR          ((T_Reg32 *) 0xF0001FBC)->bit13
#define GPTA0_SRC16_TOS          ((T_Reg32 *) 0xF0001FBC)->bit10

// GPTA0 Interrupt Service Request Control Register 17
#define GPTA0_SRC17            (*((uword volatile *) 0xF0001FB8))
#define GPTA0_SRC17_CLRR         ((T_Reg32 *) 0xF0001FB8)->bit14
#define GPTA0_SRC17_SETR         ((T_Reg32 *) 0xF0001FB8)->bit15
#define GPTA0_SRC17_SRE          ((T_Reg32 *) 0xF0001FB8)->bit12
#define GPTA0_SRC17_SRR          ((T_Reg32 *) 0xF0001FB8)->bit13
#define GPTA0_SRC17_TOS          ((T_Reg32 *) 0xF0001FB8)->bit10

// GPTA0 Interrupt Service Request Control Register 18
#define GPTA0_SRC18            (*((uword volatile *) 0xF0001FB4))
#define GPTA0_SRC18_CLRR         ((T_Reg32 *) 0xF0001FB4)->bit14
#define GPTA0_SRC18_SETR         ((T_Reg32 *) 0xF0001FB4)->bit15
#define GPTA0_SRC18_SRE          ((T_Reg32 *) 0xF0001FB4)->bit12
#define GPTA0_SRC18_SRR          ((T_Reg32 *) 0xF0001FB4)->bit13
#define GPTA0_SRC18_TOS          ((T_Reg32 *) 0xF0001FB4)->bit10

// GPTA0 Interrupt Service Request Control Register 19
#define GPTA0_SRC19            (*((uword volatile *) 0xF0001FB0))
#define GPTA0_SRC19_CLRR         ((T_Reg32 *) 0xF0001FB0)->bit14
#define GPTA0_SRC19_SETR         ((T_Reg32 *) 0xF0001FB0)->bit15
#define GPTA0_SRC19_SRE          ((T_Reg32 *) 0xF0001FB0)->bit12
#define GPTA0_SRC19_SRR          ((T_Reg32 *) 0xF0001FB0)->bit13
#define GPTA0_SRC19_TOS          ((T_Reg32 *) 0xF0001FB0)->bit10

// GPTA0 Interrupt Service Request Control Register 20
#define GPTA0_SRC20            (*((uword volatile *) 0xF0001FAC))
#define GPTA0_SRC20_CLRR         ((T_Reg32 *) 0xF0001FAC)->bit14
#define GPTA0_SRC20_SETR         ((T_Reg32 *) 0xF0001FAC)->bit15
#define GPTA0_SRC20_SRE          ((T_Reg32 *) 0xF0001FAC)->bit12
#define GPTA0_SRC20_SRR          ((T_Reg32 *) 0xF0001FAC)->bit13
#define GPTA0_SRC20_TOS          ((T_Reg32 *) 0xF0001FAC)->bit10

// GPTA0 Interrupt Service Request Control Register 21
#define GPTA0_SRC21            (*((uword volatile *) 0xF0001FA8))
#define GPTA0_SRC21_CLRR         ((T_Reg32 *) 0xF0001FA8)->bit14
#define GPTA0_SRC21_SETR         ((T_Reg32 *) 0xF0001FA8)->bit15
#define GPTA0_SRC21_SRE          ((T_Reg32 *) 0xF0001FA8)->bit12
#define GPTA0_SRC21_SRR          ((T_Reg32 *) 0xF0001FA8)->bit13
#define GPTA0_SRC21_TOS          ((T_Reg32 *) 0xF0001FA8)->bit10

// GPTA0 Interrupt Service Request Control Register 22
#define GPTA0_SRC22            (*((uword volatile *) 0xF0001FA4))
#define GPTA0_SRC22_CLRR         ((T_Reg32 *) 0xF0001FA4)->bit14
#define GPTA0_SRC22_SETR         ((T_Reg32 *) 0xF0001FA4)->bit15
#define GPTA0_SRC22_SRE          ((T_Reg32 *) 0xF0001FA4)->bit12
#define GPTA0_SRC22_SRR          ((T_Reg32 *) 0xF0001FA4)->bit13
#define GPTA0_SRC22_TOS          ((T_Reg32 *) 0xF0001FA4)->bit10

// GPTA0 Interrupt Service Request Control Register 23
#define GPTA0_SRC23            (*((uword volatile *) 0xF0001FA0))
#define GPTA0_SRC23_CLRR         ((T_Reg32 *) 0xF0001FA0)->bit14
#define GPTA0_SRC23_SETR         ((T_Reg32 *) 0xF0001FA0)->bit15
#define GPTA0_SRC23_SRE          ((T_Reg32 *) 0xF0001FA0)->bit12
#define GPTA0_SRC23_SRR          ((T_Reg32 *) 0xF0001FA0)->bit13
#define GPTA0_SRC23_TOS          ((T_Reg32 *) 0xF0001FA0)->bit10

// GPTA0 Interrupt Service Request Control Register 24
#define GPTA0_SRC24            (*((uword volatile *) 0xF0001F9C))
#define GPTA0_SRC24_CLRR         ((T_Reg32 *) 0xF0001F9C)->bit14
#define GPTA0_SRC24_SETR         ((T_Reg32 *) 0xF0001F9C)->bit15
#define GPTA0_SRC24_SRE          ((T_Reg32 *) 0xF0001F9C)->bit12
#define GPTA0_SRC24_SRR          ((T_Reg32 *) 0xF0001F9C)->bit13
#define GPTA0_SRC24_TOS          ((T_Reg32 *) 0xF0001F9C)->bit10

// GPTA0 Interrupt Service Request Control Register 25
#define GPTA0_SRC25            (*((uword volatile *) 0xF0001F98))
#define GPTA0_SRC25_CLRR         ((T_Reg32 *) 0xF0001F98)->bit14
#define GPTA0_SRC25_SETR         ((T_Reg32 *) 0xF0001F98)->bit15
#define GPTA0_SRC25_SRE          ((T_Reg32 *) 0xF0001F98)->bit12
#define GPTA0_SRC25_SRR          ((T_Reg32 *) 0xF0001F98)->bit13
#define GPTA0_SRC25_TOS          ((T_Reg32 *) 0xF0001F98)->bit10

// GPTA0 Interrupt Service Request Control Register 26
#define GPTA0_SRC26            (*((uword volatile *) 0xF0001F94))
#define GPTA0_SRC26_CLRR         ((T_Reg32 *) 0xF0001F94)->bit14
#define GPTA0_SRC26_SETR         ((T_Reg32 *) 0xF0001F94)->bit15
#define GPTA0_SRC26_SRE          ((T_Reg32 *) 0xF0001F94)->bit12
#define GPTA0_SRC26_SRR          ((T_Reg32 *) 0xF0001F94)->bit13
#define GPTA0_SRC26_TOS          ((T_Reg32 *) 0xF0001F94)->bit10

// GPTA0 Interrupt Service Request Control Register 27
#define GPTA0_SRC27            (*((uword volatile *) 0xF0001F90))
#define GPTA0_SRC27_CLRR         ((T_Reg32 *) 0xF0001F90)->bit14
#define GPTA0_SRC27_SETR         ((T_Reg32 *) 0xF0001F90)->bit15
#define GPTA0_SRC27_SRE          ((T_Reg32 *) 0xF0001F90)->bit12
#define GPTA0_SRC27_SRR          ((T_Reg32 *) 0xF0001F90)->bit13
#define GPTA0_SRC27_TOS          ((T_Reg32 *) 0xF0001F90)->bit10

// GPTA0 Interrupt Service Request Control Register 28
#define GPTA0_SRC28            (*((uword volatile *) 0xF0001F8C))
#define GPTA0_SRC28_CLRR         ((T_Reg32 *) 0xF0001F8C)->bit14
#define GPTA0_SRC28_SETR         ((T_Reg32 *) 0xF0001F8C)->bit15
#define GPTA0_SRC28_SRE          ((T_Reg32 *) 0xF0001F8C)->bit12
#define GPTA0_SRC28_SRR          ((T_Reg32 *) 0xF0001F8C)->bit13
#define GPTA0_SRC28_TOS          ((T_Reg32 *) 0xF0001F8C)->bit10

// GPTA0 Interrupt Service Request Control Register 29
#define GPTA0_SRC29            (*((uword volatile *) 0xF0001F88))
#define GPTA0_SRC29_CLRR         ((T_Reg32 *) 0xF0001F88)->bit14
#define GPTA0_SRC29_SETR         ((T_Reg32 *) 0xF0001F88)->bit15
#define GPTA0_SRC29_SRE          ((T_Reg32 *) 0xF0001F88)->bit12
#define GPTA0_SRC29_SRR          ((T_Reg32 *) 0xF0001F88)->bit13
#define GPTA0_SRC29_TOS          ((T_Reg32 *) 0xF0001F88)->bit10

// GPTA0 Interrupt Service Request Control Register 30
#define GPTA0_SRC30            (*((uword volatile *) 0xF0001F84))
#define GPTA0_SRC30_CLRR         ((T_Reg32 *) 0xF0001F84)->bit14
#define GPTA0_SRC30_SETR         ((T_Reg32 *) 0xF0001F84)->bit15
#define GPTA0_SRC30_SRE          ((T_Reg32 *) 0xF0001F84)->bit12
#define GPTA0_SRC30_SRR          ((T_Reg32 *) 0xF0001F84)->bit13
#define GPTA0_SRC30_TOS          ((T_Reg32 *) 0xF0001F84)->bit10

// GPTA0 Interrupt Service Request Control Register 31
#define GPTA0_SRC31            (*((uword volatile *) 0xF0001F80))
#define GPTA0_SRC31_CLRR         ((T_Reg32 *) 0xF0001F80)->bit14
#define GPTA0_SRC31_SETR         ((T_Reg32 *) 0xF0001F80)->bit15
#define GPTA0_SRC31_SRE          ((T_Reg32 *) 0xF0001F80)->bit12
#define GPTA0_SRC31_SRR          ((T_Reg32 *) 0xF0001F80)->bit13
#define GPTA0_SRC31_TOS          ((T_Reg32 *) 0xF0001F80)->bit10

// GPTA0 Interrupt Service Request Control Register 32
#define GPTA0_SRC32            (*((uword volatile *) 0xF0001F7C))
#define GPTA0_SRC32_CLRR         ((T_Reg32 *) 0xF0001F7C)->bit14
#define GPTA0_SRC32_SETR         ((T_Reg32 *) 0xF0001F7C)->bit15
#define GPTA0_SRC32_SRE          ((T_Reg32 *) 0xF0001F7C)->bit12
#define GPTA0_SRC32_SRR          ((T_Reg32 *) 0xF0001F7C)->bit13
#define GPTA0_SRC32_TOS          ((T_Reg32 *) 0xF0001F7C)->bit10

// GPTA0 Interrupt Service Request Control Register 33
#define GPTA0_SRC33            (*((uword volatile *) 0xF0001F78))
#define GPTA0_SRC33_CLRR         ((T_Reg32 *) 0xF0001F78)->bit14
#define GPTA0_SRC33_SETR         ((T_Reg32 *) 0xF0001F78)->bit15
#define GPTA0_SRC33_SRE          ((T_Reg32 *) 0xF0001F78)->bit12
#define GPTA0_SRC33_SRR          ((T_Reg32 *) 0xF0001F78)->bit13
#define GPTA0_SRC33_TOS          ((T_Reg32 *) 0xF0001F78)->bit10

// GPTA0 Interrupt Service Request Control Register 34
#define GPTA0_SRC34            (*((uword volatile *) 0xF0001F74))
#define GPTA0_SRC34_CLRR         ((T_Reg32 *) 0xF0001F74)->bit14
#define GPTA0_SRC34_SETR         ((T_Reg32 *) 0xF0001F74)->bit15
#define GPTA0_SRC34_SRE          ((T_Reg32 *) 0xF0001F74)->bit12
#define GPTA0_SRC34_SRR          ((T_Reg32 *) 0xF0001F74)->bit13
#define GPTA0_SRC34_TOS          ((T_Reg32 *) 0xF0001F74)->bit10

// GPTA0 Interrupt Service Request Control Register 35
#define GPTA0_SRC35            (*((uword volatile *) 0xF0001F70))
#define GPTA0_SRC35_CLRR         ((T_Reg32 *) 0xF0001F70)->bit14
#define GPTA0_SRC35_SETR         ((T_Reg32 *) 0xF0001F70)->bit15
#define GPTA0_SRC35_SRE          ((T_Reg32 *) 0xF0001F70)->bit12
#define GPTA0_SRC35_SRR          ((T_Reg32 *) 0xF0001F70)->bit13
#define GPTA0_SRC35_TOS          ((T_Reg32 *) 0xF0001F70)->bit10

// GPTA0 Interrupt Service Request Control Register 36
#define GPTA0_SRC36            (*((uword volatile *) 0xF0001F6C))
#define GPTA0_SRC36_CLRR         ((T_Reg32 *) 0xF0001F6C)->bit14
#define GPTA0_SRC36_SETR         ((T_Reg32 *) 0xF0001F6C)->bit15
#define GPTA0_SRC36_SRE          ((T_Reg32 *) 0xF0001F6C)->bit12
#define GPTA0_SRC36_SRR          ((T_Reg32 *) 0xF0001F6C)->bit13
#define GPTA0_SRC36_TOS          ((T_Reg32 *) 0xF0001F6C)->bit10

// GPTA0 Interrupt Service Request Control Register 37
#define GPTA0_SRC37            (*((uword volatile *) 0xF0001F68))
#define GPTA0_SRC37_CLRR         ((T_Reg32 *) 0xF0001F68)->bit14
#define GPTA0_SRC37_SETR         ((T_Reg32 *) 0xF0001F68)->bit15
#define GPTA0_SRC37_SRE          ((T_Reg32 *) 0xF0001F68)->bit12
#define GPTA0_SRC37_SRR          ((T_Reg32 *) 0xF0001F68)->bit13
#define GPTA0_SRC37_TOS          ((T_Reg32 *) 0xF0001F68)->bit10

// GPTA0 Service Request Node Redirection Register
#define GPTA0_SRNR             (*((uword volatile *) 0xF0001830))
#define GPTA0_SRNR_GTC01R        ((T_Reg32 *) 0xF0001830)->bit0
#define GPTA0_SRNR_GTC03R        ((T_Reg32 *) 0xF0001830)->bit1
#define GPTA0_SRNR_GTC05R        ((T_Reg32 *) 0xF0001830)->bit2
#define GPTA0_SRNR_GTC07R        ((T_Reg32 *) 0xF0001830)->bit3
#define GPTA0_SRNR_GTC09R        ((T_Reg32 *) 0xF0001830)->bit4
#define GPTA0_SRNR_GTC11R        ((T_Reg32 *) 0xF0001830)->bit5
#define GPTA0_SRNR_GTC13R        ((T_Reg32 *) 0xF0001830)->bit6
#define GPTA0_SRNR_GTC15R        ((T_Reg32 *) 0xF0001830)->bit7
#define GPTA0_SRNR_GTC17R        ((T_Reg32 *) 0xF0001830)->bit8
#define GPTA0_SRNR_GTC19R        ((T_Reg32 *) 0xF0001830)->bit9
#define GPTA0_SRNR_GTC21R        ((T_Reg32 *) 0xF0001830)->bit10
#define GPTA0_SRNR_GTC23R        ((T_Reg32 *) 0xF0001830)->bit11
#define GPTA0_SRNR_GTC25R        ((T_Reg32 *) 0xF0001830)->bit12
#define GPTA0_SRNR_GTC27R        ((T_Reg32 *) 0xF0001830)->bit13
#define GPTA0_SRNR_GTC29R        ((T_Reg32 *) 0xF0001830)->bit14
#define GPTA0_SRNR_GTC31R        ((T_Reg32 *) 0xF0001830)->bit15

// GPTA0 Service Request State Clear Register 0
#define GPTA0_SRSC0            (*((uword volatile *) 0xF0001810))
#define GPTA0_SRSC0_DCM00C       ((T_Reg32 *) 0xF0001810)->bit2
#define GPTA0_SRSC0_DCM00F       ((T_Reg32 *) 0xF0001810)->bit1
#define GPTA0_SRSC0_DCM00R       ((T_Reg32 *) 0xF0001810)->bit0
#define GPTA0_SRSC0_DCM01C       ((T_Reg32 *) 0xF0001810)->bit5
#define GPTA0_SRSC0_DCM01F       ((T_Reg32 *) 0xF0001810)->bit4
#define GPTA0_SRSC0_DCM01R       ((T_Reg32 *) 0xF0001810)->bit3
#define GPTA0_SRSC0_DCM02C       ((T_Reg32 *) 0xF0001810)->bit8
#define GPTA0_SRSC0_DCM02F       ((T_Reg32 *) 0xF0001810)->bit7
#define GPTA0_SRSC0_DCM02R       ((T_Reg32 *) 0xF0001810)->bit6
#define GPTA0_SRSC0_DCM03C       ((T_Reg32 *) 0xF0001810)->bit11
#define GPTA0_SRSC0_DCM03F       ((T_Reg32 *) 0xF0001810)->bit10
#define GPTA0_SRSC0_DCM03R       ((T_Reg32 *) 0xF0001810)->bit9
#define GPTA0_SRSC0_GT00         ((T_Reg32 *) 0xF0001810)->bit13
#define GPTA0_SRSC0_GT01         ((T_Reg32 *) 0xF0001810)->bit14
#define GPTA0_SRSC0_PLL          ((T_Reg32 *) 0xF0001810)->bit12

// GPTA0 Service Request State Clear Register 1
#define GPTA0_SRSC1            (*((uword volatile *) 0xF0001818))
#define GPTA0_SRSC1_GTC00         ((T_Reg32 *) 0xF0001818)->bit0
#define GPTA0_SRSC1_GTC01         ((T_Reg32 *) 0xF0001818)->bit1
#define GPTA0_SRSC1_GTC10        ((T_Reg32 *) 0xF0001818)->bit10
#define GPTA0_SRSC1_GTC11        ((T_Reg32 *) 0xF0001818)->bit11
#define GPTA0_SRSC1_GTC12        ((T_Reg32 *) 0xF0001818)->bit12
#define GPTA0_SRSC1_GTC13        ((T_Reg32 *) 0xF0001818)->bit13
#define GPTA0_SRSC1_GTC14        ((T_Reg32 *) 0xF0001818)->bit14
#define GPTA0_SRSC1_GTC15        ((T_Reg32 *) 0xF0001818)->bit15
#define GPTA0_SRSC1_GTC16        ((T_Reg32 *) 0xF0001818)->bit16
#define GPTA0_SRSC1_GTC17        ((T_Reg32 *) 0xF0001818)->bit17
#define GPTA0_SRSC1_GTC18        ((T_Reg32 *) 0xF0001818)->bit18
#define GPTA0_SRSC1_GTC19        ((T_Reg32 *) 0xF0001818)->bit19
#define GPTA0_SRSC1_GTC02         ((T_Reg32 *) 0xF0001818)->bit2
#define GPTA0_SRSC1_GTC20        ((T_Reg32 *) 0xF0001818)->bit20
#define GPTA0_SRSC1_GTC21        ((T_Reg32 *) 0xF0001818)->bit21
#define GPTA0_SRSC1_GTC22        ((T_Reg32 *) 0xF0001818)->bit22
#define GPTA0_SRSC1_GTC23        ((T_Reg32 *) 0xF0001818)->bit23
#define GPTA0_SRSC1_GTC24        ((T_Reg32 *) 0xF0001818)->bit24
#define GPTA0_SRSC1_GTC25        ((T_Reg32 *) 0xF0001818)->bit25
#define GPTA0_SRSC1_GTC26        ((T_Reg32 *) 0xF0001818)->bit26
#define GPTA0_SRSC1_GTC27        ((T_Reg32 *) 0xF0001818)->bit27
#define GPTA0_SRSC1_GTC28        ((T_Reg32 *) 0xF0001818)->bit28
#define GPTA0_SRSC1_GTC29        ((T_Reg32 *) 0xF0001818)->bit29
#define GPTA0_SRSC1_GTC03         ((T_Reg32 *) 0xF0001818)->bit3
#define GPTA0_SRSC1_GTC30        ((T_Reg32 *) 0xF0001818)->bit30
#define GPTA0_SRSC1_GTC31        ((T_Reg32 *) 0xF0001818)->bit31
#define GPTA0_SRSC1_GTC04         ((T_Reg32 *) 0xF0001818)->bit4
#define GPTA0_SRSC1_GTC05         ((T_Reg32 *) 0xF0001818)->bit5
#define GPTA0_SRSC1_GTC06         ((T_Reg32 *) 0xF0001818)->bit6
#define GPTA0_SRSC1_GTC07         ((T_Reg32 *) 0xF0001818)->bit7
#define GPTA0_SRSC1_GTC08         ((T_Reg32 *) 0xF0001818)->bit8
#define GPTA0_SRSC1_GTC09         ((T_Reg32 *) 0xF0001818)->bit9

// GPTA0 Service Request State Clear Register 2
#define GPTA0_SRSC2            (*((uword volatile *) 0xF0001820))
#define GPTA0_SRSC2_LTC00         ((T_Reg32 *) 0xF0001820)->bit0
#define GPTA0_SRSC2_LTC01         ((T_Reg32 *) 0xF0001820)->bit1
#define GPTA0_SRSC2_LTC10        ((T_Reg32 *) 0xF0001820)->bit10
#define GPTA0_SRSC2_LTC11        ((T_Reg32 *) 0xF0001820)->bit11
#define GPTA0_SRSC2_LTC12        ((T_Reg32 *) 0xF0001820)->bit12
#define GPTA0_SRSC2_LTC13        ((T_Reg32 *) 0xF0001820)->bit13
#define GPTA0_SRSC2_LTC14        ((T_Reg32 *) 0xF0001820)->bit14
#define GPTA0_SRSC2_LTC15        ((T_Reg32 *) 0xF0001820)->bit15
#define GPTA0_SRSC2_LTC16        ((T_Reg32 *) 0xF0001820)->bit16
#define GPTA0_SRSC2_LTC17        ((T_Reg32 *) 0xF0001820)->bit17
#define GPTA0_SRSC2_LTC18        ((T_Reg32 *) 0xF0001820)->bit18
#define GPTA0_SRSC2_LTC19        ((T_Reg32 *) 0xF0001820)->bit19
#define GPTA0_SRSC2_LTC02         ((T_Reg32 *) 0xF0001820)->bit2
#define GPTA0_SRSC2_LTC20        ((T_Reg32 *) 0xF0001820)->bit20
#define GPTA0_SRSC2_LTC21        ((T_Reg32 *) 0xF0001820)->bit21
#define GPTA0_SRSC2_LTC22        ((T_Reg32 *) 0xF0001820)->bit22
#define GPTA0_SRSC2_LTC23        ((T_Reg32 *) 0xF0001820)->bit23
#define GPTA0_SRSC2_LTC24        ((T_Reg32 *) 0xF0001820)->bit24
#define GPTA0_SRSC2_LTC25        ((T_Reg32 *) 0xF0001820)->bit25
#define GPTA0_SRSC2_LTC26        ((T_Reg32 *) 0xF0001820)->bit26
#define GPTA0_SRSC2_LTC27        ((T_Reg32 *) 0xF0001820)->bit27
#define GPTA0_SRSC2_LTC28        ((T_Reg32 *) 0xF0001820)->bit28
#define GPTA0_SRSC2_LTC29        ((T_Reg32 *) 0xF0001820)->bit29
#define GPTA0_SRSC2_LTC03         ((T_Reg32 *) 0xF0001820)->bit3
#define GPTA0_SRSC2_LTC30        ((T_Reg32 *) 0xF0001820)->bit30
#define GPTA0_SRSC2_LTC31        ((T_Reg32 *) 0xF0001820)->bit31
#define GPTA0_SRSC2_LTC04         ((T_Reg32 *) 0xF0001820)->bit4
#define GPTA0_SRSC2_LTC05         ((T_Reg32 *) 0xF0001820)->bit5
#define GPTA0_SRSC2_LTC06         ((T_Reg32 *) 0xF0001820)->bit6
#define GPTA0_SRSC2_LTC07         ((T_Reg32 *) 0xF0001820)->bit7
#define GPTA0_SRSC2_LTC08         ((T_Reg32 *) 0xF0001820)->bit8
#define GPTA0_SRSC2_LTC09         ((T_Reg32 *) 0xF0001820)->bit9

// GPTA0 Service Request State Clear Register 3
#define GPTA0_SRSC3            (*((uword volatile *) 0xF0001828))
#define GPTA0_SRSC3_LTC32        ((T_Reg32 *) 0xF0001828)->bit0
#define GPTA0_SRSC3_LTC33        ((T_Reg32 *) 0xF0001828)->bit1
#define GPTA0_SRSC3_LTC34        ((T_Reg32 *) 0xF0001828)->bit2
#define GPTA0_SRSC3_LTC35        ((T_Reg32 *) 0xF0001828)->bit3
#define GPTA0_SRSC3_LTC36        ((T_Reg32 *) 0xF0001828)->bit4
#define GPTA0_SRSC3_LTC37        ((T_Reg32 *) 0xF0001828)->bit5
#define GPTA0_SRSC3_LTC38        ((T_Reg32 *) 0xF0001828)->bit6
#define GPTA0_SRSC3_LTC39        ((T_Reg32 *) 0xF0001828)->bit7
#define GPTA0_SRSC3_LTC40        ((T_Reg32 *) 0xF0001828)->bit8
#define GPTA0_SRSC3_LTC41        ((T_Reg32 *) 0xF0001828)->bit9
#define GPTA0_SRSC3_LTC42        ((T_Reg32 *) 0xF0001828)->bit10
#define GPTA0_SRSC3_LTC43        ((T_Reg32 *) 0xF0001828)->bit11
#define GPTA0_SRSC3_LTC44        ((T_Reg32 *) 0xF0001828)->bit12
#define GPTA0_SRSC3_LTC45        ((T_Reg32 *) 0xF0001828)->bit13
#define GPTA0_SRSC3_LTC46        ((T_Reg32 *) 0xF0001828)->bit14
#define GPTA0_SRSC3_LTC47        ((T_Reg32 *) 0xF0001828)->bit15
#define GPTA0_SRSC3_LTC48        ((T_Reg32 *) 0xF0001828)->bit16
#define GPTA0_SRSC3_LTC49        ((T_Reg32 *) 0xF0001828)->bit17
#define GPTA0_SRSC3_LTC50        ((T_Reg32 *) 0xF0001828)->bit18
#define GPTA0_SRSC3_LTC51        ((T_Reg32 *) 0xF0001828)->bit19
#define GPTA0_SRSC3_LTC52        ((T_Reg32 *) 0xF0001828)->bit20
#define GPTA0_SRSC3_LTC53        ((T_Reg32 *) 0xF0001828)->bit21
#define GPTA0_SRSC3_LTC54        ((T_Reg32 *) 0xF0001828)->bit22
#define GPTA0_SRSC3_LTC55        ((T_Reg32 *) 0xF0001828)->bit23
#define GPTA0_SRSC3_LTC56        ((T_Reg32 *) 0xF0001828)->bit24
#define GPTA0_SRSC3_LTC57        ((T_Reg32 *) 0xF0001828)->bit25
#define GPTA0_SRSC3_LTC58        ((T_Reg32 *) 0xF0001828)->bit26
#define GPTA0_SRSC3_LTC59        ((T_Reg32 *) 0xF0001828)->bit27
#define GPTA0_SRSC3_LTC60        ((T_Reg32 *) 0xF0001828)->bit28
#define GPTA0_SRSC3_LTC61        ((T_Reg32 *) 0xF0001828)->bit29
#define GPTA0_SRSC3_LTC62        ((T_Reg32 *) 0xF0001828)->bit30
#define GPTA0_SRSC3_LTC63        ((T_Reg32 *) 0xF0001828)->bit31

// GPTA0 Service Request State Set Register 0
#define GPTA0_SRSS0            (*((uword volatile *) 0xF0001814))
#define GPTA0_SRSS0_DCM00C       ((T_Reg32 *) 0xF0001814)->bit2
#define GPTA0_SRSS0_DCM00F       ((T_Reg32 *) 0xF0001814)->bit1
#define GPTA0_SRSS0_DCM00R       ((T_Reg32 *) 0xF0001814)->bit0
#define GPTA0_SRSS0_DCM01C       ((T_Reg32 *) 0xF0001814)->bit5
#define GPTA0_SRSS0_DCM01F       ((T_Reg32 *) 0xF0001814)->bit4
#define GPTA0_SRSS0_DCM01R       ((T_Reg32 *) 0xF0001814)->bit3
#define GPTA0_SRSS0_DCM02C       ((T_Reg32 *) 0xF0001814)->bit8
#define GPTA0_SRSS0_DCM02F       ((T_Reg32 *) 0xF0001814)->bit7
#define GPTA0_SRSS0_DCM02R       ((T_Reg32 *) 0xF0001814)->bit6
#define GPTA0_SRSS0_DCM03C       ((T_Reg32 *) 0xF0001814)->bit11
#define GPTA0_SRSS0_DCM03F       ((T_Reg32 *) 0xF0001814)->bit10
#define GPTA0_SRSS0_DCM03R       ((T_Reg32 *) 0xF0001814)->bit9
#define GPTA0_SRSS0_GT00         ((T_Reg32 *) 0xF0001814)->bit13
#define GPTA0_SRSS0_GT01         ((T_Reg32 *) 0xF0001814)->bit14
#define GPTA0_SRSS0_PLL          ((T_Reg32 *) 0xF0001814)->bit12

// GPTA0 Service Request State Set Register 1
#define GPTA0_SRSS1            (*((uword volatile *) 0xF000181C))
#define GPTA0_SRSS1_GTC00         ((T_Reg32 *) 0xF000181C)->bit0
#define GPTA0_SRSS1_GTC01         ((T_Reg32 *) 0xF000181C)->bit1
#define GPTA0_SRSS1_GTC10        ((T_Reg32 *) 0xF000181C)->bit10
#define GPTA0_SRSS1_GTC11        ((T_Reg32 *) 0xF000181C)->bit11
#define GPTA0_SRSS1_GTC12        ((T_Reg32 *) 0xF000181C)->bit12
#define GPTA0_SRSS1_GTC13        ((T_Reg32 *) 0xF000181C)->bit13
#define GPTA0_SRSS1_GTC14        ((T_Reg32 *) 0xF000181C)->bit14
#define GPTA0_SRSS1_GTC15        ((T_Reg32 *) 0xF000181C)->bit15
#define GPTA0_SRSS1_GTC16        ((T_Reg32 *) 0xF000181C)->bit16
#define GPTA0_SRSS1_GTC17        ((T_Reg32 *) 0xF000181C)->bit17
#define GPTA0_SRSS1_GTC18        ((T_Reg32 *) 0xF000181C)->bit18
#define GPTA0_SRSS1_GTC19        ((T_Reg32 *) 0xF000181C)->bit19
#define GPTA0_SRSS1_GTC02         ((T_Reg32 *) 0xF000181C)->bit2
#define GPTA0_SRSS1_GTC20        ((T_Reg32 *) 0xF000181C)->bit20
#define GPTA0_SRSS1_GTC21        ((T_Reg32 *) 0xF000181C)->bit21
#define GPTA0_SRSS1_GTC22        ((T_Reg32 *) 0xF000181C)->bit22
#define GPTA0_SRSS1_GTC23        ((T_Reg32 *) 0xF000181C)->bit23
#define GPTA0_SRSS1_GTC24        ((T_Reg32 *) 0xF000181C)->bit24
#define GPTA0_SRSS1_GTC25        ((T_Reg32 *) 0xF000181C)->bit25
#define GPTA0_SRSS1_GTC26        ((T_Reg32 *) 0xF000181C)->bit26
#define GPTA0_SRSS1_GTC27        ((T_Reg32 *) 0xF000181C)->bit27
#define GPTA0_SRSS1_GTC28        ((T_Reg32 *) 0xF000181C)->bit28
#define GPTA0_SRSS1_GTC29        ((T_Reg32 *) 0xF000181C)->bit29
#define GPTA0_SRSS1_GTC03         ((T_Reg32 *) 0xF000181C)->bit3
#define GPTA0_SRSS1_GTC30        ((T_Reg32 *) 0xF000181C)->bit30
#define GPTA0_SRSS1_GTC31        ((T_Reg32 *) 0xF000181C)->bit31
#define GPTA0_SRSS1_GTC04         ((T_Reg32 *) 0xF000181C)->bit4
#define GPTA0_SRSS1_GTC05         ((T_Reg32 *) 0xF000181C)->bit5
#define GPTA0_SRSS1_GTC06         ((T_Reg32 *) 0xF000181C)->bit6
#define GPTA0_SRSS1_GTC07         ((T_Reg32 *) 0xF000181C)->bit7
#define GPTA0_SRSS1_GTC08         ((T_Reg32 *) 0xF000181C)->bit8
#define GPTA0_SRSS1_GTC09         ((T_Reg32 *) 0xF000181C)->bit9

// GPTA0 Service Request State Set Register 2
#define GPTA0_SRSS2            (*((uword volatile *) 0xF0001824))
#define GPTA0_SRSS2_LTC00         ((T_Reg32 *) 0xF0001824)->bit0
#define GPTA0_SRSS2_LTC01         ((T_Reg32 *) 0xF0001824)->bit1
#define GPTA0_SRSS2_LTC10        ((T_Reg32 *) 0xF0001824)->bit10
#define GPTA0_SRSS2_LTC11        ((T_Reg32 *) 0xF0001824)->bit11
#define GPTA0_SRSS2_LTC12        ((T_Reg32 *) 0xF0001824)->bit12
#define GPTA0_SRSS2_LTC13        ((T_Reg32 *) 0xF0001824)->bit13
#define GPTA0_SRSS2_LTC14        ((T_Reg32 *) 0xF0001824)->bit14
#define GPTA0_SRSS2_LTC15        ((T_Reg32 *) 0xF0001824)->bit15
#define GPTA0_SRSS2_LTC16        ((T_Reg32 *) 0xF0001824)->bit16
#define GPTA0_SRSS2_LTC17        ((T_Reg32 *) 0xF0001824)->bit17
#define GPTA0_SRSS2_LTC18        ((T_Reg32 *) 0xF0001824)->bit18
#define GPTA0_SRSS2_LTC19        ((T_Reg32 *) 0xF0001824)->bit19
#define GPTA0_SRSS2_LTC02         ((T_Reg32 *) 0xF0001824)->bit2
#define GPTA0_SRSS2_LTC20        ((T_Reg32 *) 0xF0001824)->bit20
#define GPTA0_SRSS2_LTC21        ((T_Reg32 *) 0xF0001824)->bit21
#define GPTA0_SRSS2_LTC22        ((T_Reg32 *) 0xF0001824)->bit22
#define GPTA0_SRSS2_LTC23        ((T_Reg32 *) 0xF0001824)->bit23
#define GPTA0_SRSS2_LTC24        ((T_Reg32 *) 0xF0001824)->bit24
#define GPTA0_SRSS2_LTC25        ((T_Reg32 *) 0xF0001824)->bit25
#define GPTA0_SRSS2_LTC26        ((T_Reg32 *) 0xF0001824)->bit26
#define GPTA0_SRSS2_LTC27        ((T_Reg32 *) 0xF0001824)->bit27
#define GPTA0_SRSS2_LTC28        ((T_Reg32 *) 0xF0001824)->bit28
#define GPTA0_SRSS2_LTC29        ((T_Reg32 *) 0xF0001824)->bit29
#define GPTA0_SRSS2_LTC03         ((T_Reg32 *) 0xF0001824)->bit3
#define GPTA0_SRSS2_LTC30        ((T_Reg32 *) 0xF0001824)->bit30
#define GPTA0_SRSS2_LTC31        ((T_Reg32 *) 0xF0001824)->bit31
#define GPTA0_SRSS2_LTC04         ((T_Reg32 *) 0xF0001824)->bit4
#define GPTA0_SRSS2_LTC05         ((T_Reg32 *) 0xF0001824)->bit5
#define GPTA0_SRSS2_LTC06         ((T_Reg32 *) 0xF0001824)->bit6
#define GPTA0_SRSS2_LTC07         ((T_Reg32 *) 0xF0001824)->bit7
#define GPTA0_SRSS2_LTC08         ((T_Reg32 *) 0xF0001824)->bit8
#define GPTA0_SRSS2_LTC09         ((T_Reg32 *) 0xF0001824)->bit9

// GPTA0 Service Request State Set Register 3
#define GPTA0_SRSS3            (*((uword volatile *) 0xF000182C))
#define GPTA0_SRSS3_LTC32        ((T_Reg32 *) 0xF000182C)->bit0
#define GPTA0_SRSS3_LTC33        ((T_Reg32 *) 0xF000182C)->bit1
#define GPTA0_SRSS3_LTC34        ((T_Reg32 *) 0xF000182C)->bit2
#define GPTA0_SRSS3_LTC35        ((T_Reg32 *) 0xF000182C)->bit3
#define GPTA0_SRSS3_LTC36        ((T_Reg32 *) 0xF000182C)->bit4
#define GPTA0_SRSS3_LTC37        ((T_Reg32 *) 0xF000182C)->bit5
#define GPTA0_SRSS3_LTC38        ((T_Reg32 *) 0xF000182C)->bit6
#define GPTA0_SRSS3_LTC39        ((T_Reg32 *) 0xF000182C)->bit7
#define GPTA0_SRSS3_LTC40        ((T_Reg32 *) 0xF000182C)->bit8
#define GPTA0_SRSS3_LTC41        ((T_Reg32 *) 0xF000182C)->bit9
#define GPTA0_SRSS3_LTC42        ((T_Reg32 *) 0xF000182C)->bit10
#define GPTA0_SRSS3_LTC43        ((T_Reg32 *) 0xF000182C)->bit11
#define GPTA0_SRSS3_LTC44        ((T_Reg32 *) 0xF000182C)->bit12
#define GPTA0_SRSS3_LTC45        ((T_Reg32 *) 0xF000182C)->bit13
#define GPTA0_SRSS3_LTC46        ((T_Reg32 *) 0xF000182C)->bit14
#define GPTA0_SRSS3_LTC47        ((T_Reg32 *) 0xF000182C)->bit15
#define GPTA0_SRSS3_LTC48        ((T_Reg32 *) 0xF000182C)->bit16
#define GPTA0_SRSS3_LTC49        ((T_Reg32 *) 0xF000182C)->bit17
#define GPTA0_SRSS3_LTC50        ((T_Reg32 *) 0xF000182C)->bit18
#define GPTA0_SRSS3_LTC51        ((T_Reg32 *) 0xF000182C)->bit19
#define GPTA0_SRSS3_LTC52        ((T_Reg32 *) 0xF000182C)->bit20
#define GPTA0_SRSS3_LTC53        ((T_Reg32 *) 0xF000182C)->bit21
#define GPTA0_SRSS3_LTC54        ((T_Reg32 *) 0xF000182C)->bit22
#define GPTA0_SRSS3_LTC55        ((T_Reg32 *) 0xF000182C)->bit23
#define GPTA0_SRSS3_LTC56        ((T_Reg32 *) 0xF000182C)->bit24
#define GPTA0_SRSS3_LTC57        ((T_Reg32 *) 0xF000182C)->bit25
#define GPTA0_SRSS3_LTC58        ((T_Reg32 *) 0xF000182C)->bit26
#define GPTA0_SRSS3_LTC59        ((T_Reg32 *) 0xF000182C)->bit27
#define GPTA0_SRSS3_LTC60        ((T_Reg32 *) 0xF000182C)->bit28
#define GPTA0_SRSS3_LTC61        ((T_Reg32 *) 0xF000182C)->bit29
#define GPTA0_SRSS3_LTC62        ((T_Reg32 *) 0xF000182C)->bit30
#define GPTA0_SRSS3_LTC63        ((T_Reg32 *) 0xF000182C)->bit31

// Instruction Count Register
#define ICNT                   (*((uword volatile *) 0xF7E1FC08))
#define ICNT_SOVF                0x80000000

// Interrupt Control Register
#define ICR                    (*((uword volatile *) 0xF7E1FE2C))
#define ICR_CONECYC              0x04000000
#define ICR_IE                   0x00000100

// Interrupt Stack Pointer
#define ISP                    (*((uword volatile *) 0xF7E1FE28))

// Module Identification Register
#define LBCU_ID                (*((uword volatile *) 0xF87FFE08))

// LBCU LMB Error Address Register
#define LBCU_LEADDR            (*((uword volatile *) 0xF87FFE24))

// LBCU LMB Error Attribute Register
#define LBCU_LEATT             (*((uword volatile *) 0xF87FFE20))
#define LBCU_LEATT_LEC           0x00000001
#define LBCU_LEATT_LOC           0x00008000
#define LBCU_LEATT_NOS           0x00004000
#define LBCU_LEATT_RD            0x00800000
#define LBCU_LEATT_SVM           0x00200000
#define LBCU_LEATT_UIS           0x00080000
#define LBCU_LEATT_WR            0x00400000

// LBCU LMB Error Data High Register
#define LBCU_LEDATH            (*((uword volatile *) 0xF87FFE2C))

// LBCU LMB Error Data Low Register
#define LBCU_LEDATL            (*((uword volatile *) 0xF87FFE28))

// LBCU Service Request Control Register
#define LBCU_SRC               (*((uword volatile *) 0xF87FFEFC))
#define LBCU_SRC_CLRR            0x00004000
#define LBCU_SRC_SETR            0x00008000
#define LBCU_SRC_SRE             0x00001000
#define LBCU_SRC_SRR             0x00002000

// Free CSA List Limit Pointer
#define LCX                    (*((uword volatile *) 0xF7E1FE3C))

// LFI Configuration Register
#define LFI_CON                (*((uword volatile *) 0xF87FFF10))

// Module Identification Register
#define LFI_ID                 (*((uword volatile *) 0xF87FFF08))

// LTCA2 Identification Register
#define LTCA2_ID               (*((uword volatile *) 0xF0002808))

// Local Timer Cell Control Register 00
#define LTCA2_LTCCTR00         (*((uword volatile *) 0xF0002A00))
#define LTCA2_LTCCTR00_CEN       ((T_Reg32 *) 0xF0002A00)->bit10
#define LTCA2_LTCCTR00_CUD       ((T_Reg32 *) 0xF0002A00)->bit9
#define LTCA2_LTCCTR00_CUDCLR    ((T_Reg32 *) 0xF0002A00)->bit7
#define LTCA2_LTCCTR00_FED       ((T_Reg32 *) 0xF0002A00)->bit5
#define LTCA2_LTCCTR00_GBYP      ((T_Reg32 *) 0xF0002A00)->bit16
#define LTCA2_LTCCTR00_ILM       ((T_Reg32 *) 0xF0002A00)->bit8
#define LTCA2_LTCCTR00_OIA       ((T_Reg32 *) 0xF0002A00)->bit14
#define LTCA2_LTCCTR00_OSM       ((T_Reg32 *) 0xF0002A00)->bit2
#define LTCA2_LTCCTR00_OUT       ((T_Reg32 *) 0xF0002A00)->bit15
#define LTCA2_LTCCTR00_RED       ((T_Reg32 *) 0xF0002A00)->bit4
#define LTCA2_LTCCTR00_REN       ((T_Reg32 *) 0xF0002A00)->bit3
#define LTCA2_LTCCTR00_SLO       ((T_Reg32 *) 0xF0002A00)->bit6

// Local Timer Cell Control Register 01
#define LTCA2_LTCCTR01         (*((uword volatile *) 0xF0002A08))
#define LTCA2_LTCCTR01_CEN       ((T_Reg32 *) 0xF0002A08)->bit10
#define LTCA2_LTCCTR01_CUD       ((T_Reg32 *) 0xF0002A08)->bit9
#define LTCA2_LTCCTR01_CUDCLR    ((T_Reg32 *) 0xF0002A08)->bit7
#define LTCA2_LTCCTR01_FED       ((T_Reg32 *) 0xF0002A08)->bit5
#define LTCA2_LTCCTR01_GBYP      ((T_Reg32 *) 0xF0002A08)->bit16
#define LTCA2_LTCCTR01_ILM       ((T_Reg32 *) 0xF0002A08)->bit8
#define LTCA2_LTCCTR01_OIA       ((T_Reg32 *) 0xF0002A08)->bit14
#define LTCA2_LTCCTR01_OSM       ((T_Reg32 *) 0xF0002A08)->bit2
#define LTCA2_LTCCTR01_OUT       ((T_Reg32 *) 0xF0002A08)->bit15
#define LTCA2_LTCCTR01_RED       ((T_Reg32 *) 0xF0002A08)->bit4
#define LTCA2_LTCCTR01_REN       ((T_Reg32 *) 0xF0002A08)->bit3
#define LTCA2_LTCCTR01_SLO       ((T_Reg32 *) 0xF0002A08)->bit6

// Local Timer Cell Control Register 02
#define LTCA2_LTCCTR02         (*((uword volatile *) 0xF0002A10))
#define LTCA2_LTCCTR02_CEN       ((T_Reg32 *) 0xF0002A10)->bit10
#define LTCA2_LTCCTR02_CUD       ((T_Reg32 *) 0xF0002A10)->bit9
#define LTCA2_LTCCTR02_CUDCLR    ((T_Reg32 *) 0xF0002A10)->bit7
#define LTCA2_LTCCTR02_FED       ((T_Reg32 *) 0xF0002A10)->bit5
#define LTCA2_LTCCTR02_GBYP      ((T_Reg32 *) 0xF0002A10)->bit16
#define LTCA2_LTCCTR02_ILM       ((T_Reg32 *) 0xF0002A10)->bit8
#define LTCA2_LTCCTR02_OIA       ((T_Reg32 *) 0xF0002A10)->bit14
#define LTCA2_LTCCTR02_OSM       ((T_Reg32 *) 0xF0002A10)->bit2
#define LTCA2_LTCCTR02_OUT       ((T_Reg32 *) 0xF0002A10)->bit15
#define LTCA2_LTCCTR02_RED       ((T_Reg32 *) 0xF0002A10)->bit4
#define LTCA2_LTCCTR02_REN       ((T_Reg32 *) 0xF0002A10)->bit3
#define LTCA2_LTCCTR02_SLO       ((T_Reg32 *) 0xF0002A10)->bit6

// Local Timer Cell Control Register 03
#define LTCA2_LTCCTR03         (*((uword volatile *) 0xF0002A18))
#define LTCA2_LTCCTR03_CEN       ((T_Reg32 *) 0xF0002A18)->bit10
#define LTCA2_LTCCTR03_CUD       ((T_Reg32 *) 0xF0002A18)->bit9
#define LTCA2_LTCCTR03_CUDCLR    ((T_Reg32 *) 0xF0002A18)->bit7
#define LTCA2_LTCCTR03_FED       ((T_Reg32 *) 0xF0002A18)->bit5
#define LTCA2_LTCCTR03_GBYP      ((T_Reg32 *) 0xF0002A18)->bit16
#define LTCA2_LTCCTR03_ILM       ((T_Reg32 *) 0xF0002A18)->bit8
#define LTCA2_LTCCTR03_OIA       ((T_Reg32 *) 0xF0002A18)->bit14
#define LTCA2_LTCCTR03_OSM       ((T_Reg32 *) 0xF0002A18)->bit2
#define LTCA2_LTCCTR03_OUT       ((T_Reg32 *) 0xF0002A18)->bit15
#define LTCA2_LTCCTR03_RED       ((T_Reg32 *) 0xF0002A18)->bit4
#define LTCA2_LTCCTR03_REN       ((T_Reg32 *) 0xF0002A18)->bit3
#define LTCA2_LTCCTR03_SLO       ((T_Reg32 *) 0xF0002A18)->bit6

// Local Timer Cell Control Register 04
#define LTCA2_LTCCTR04         (*((uword volatile *) 0xF0002A20))
#define LTCA2_LTCCTR04_CEN       ((T_Reg32 *) 0xF0002A20)->bit10
#define LTCA2_LTCCTR04_CUD       ((T_Reg32 *) 0xF0002A20)->bit9
#define LTCA2_LTCCTR04_CUDCLR    ((T_Reg32 *) 0xF0002A20)->bit7
#define LTCA2_LTCCTR04_FED       ((T_Reg32 *) 0xF0002A20)->bit5
#define LTCA2_LTCCTR04_GBYP      ((T_Reg32 *) 0xF0002A20)->bit16
#define LTCA2_LTCCTR04_ILM       ((T_Reg32 *) 0xF0002A20)->bit8
#define LTCA2_LTCCTR04_OIA       ((T_Reg32 *) 0xF0002A20)->bit14
#define LTCA2_LTCCTR04_OSM       ((T_Reg32 *) 0xF0002A20)->bit2
#define LTCA2_LTCCTR04_OUT       ((T_Reg32 *) 0xF0002A20)->bit15
#define LTCA2_LTCCTR04_RED       ((T_Reg32 *) 0xF0002A20)->bit4
#define LTCA2_LTCCTR04_REN       ((T_Reg32 *) 0xF0002A20)->bit3
#define LTCA2_LTCCTR04_SLO       ((T_Reg32 *) 0xF0002A20)->bit6

// Local Timer Cell Control Register 05
#define LTCA2_LTCCTR05         (*((uword volatile *) 0xF0002A28))
#define LTCA2_LTCCTR05_CEN       ((T_Reg32 *) 0xF0002A28)->bit10
#define LTCA2_LTCCTR05_CUD       ((T_Reg32 *) 0xF0002A28)->bit9
#define LTCA2_LTCCTR05_CUDCLR    ((T_Reg32 *) 0xF0002A28)->bit7
#define LTCA2_LTCCTR05_FED       ((T_Reg32 *) 0xF0002A28)->bit5
#define LTCA2_LTCCTR05_GBYP      ((T_Reg32 *) 0xF0002A28)->bit16
#define LTCA2_LTCCTR05_ILM       ((T_Reg32 *) 0xF0002A28)->bit8
#define LTCA2_LTCCTR05_OIA       ((T_Reg32 *) 0xF0002A28)->bit14
#define LTCA2_LTCCTR05_OSM       ((T_Reg32 *) 0xF0002A28)->bit2
#define LTCA2_LTCCTR05_OUT       ((T_Reg32 *) 0xF0002A28)->bit15
#define LTCA2_LTCCTR05_RED       ((T_Reg32 *) 0xF0002A28)->bit4
#define LTCA2_LTCCTR05_REN       ((T_Reg32 *) 0xF0002A28)->bit3
#define LTCA2_LTCCTR05_SLO       ((T_Reg32 *) 0xF0002A28)->bit6

// Local Timer Cell Control Register 06
#define LTCA2_LTCCTR06         (*((uword volatile *) 0xF0002A30))
#define LTCA2_LTCCTR06_CEN       ((T_Reg32 *) 0xF0002A30)->bit10
#define LTCA2_LTCCTR06_CUD       ((T_Reg32 *) 0xF0002A30)->bit9
#define LTCA2_LTCCTR06_CUDCLR    ((T_Reg32 *) 0xF0002A30)->bit7
#define LTCA2_LTCCTR06_FED       ((T_Reg32 *) 0xF0002A30)->bit5
#define LTCA2_LTCCTR06_FED       ((T_Reg32 *) 0xF0002A30)->bit5
#define LTCA2_LTCCTR06_GBYP      ((T_Reg32 *) 0xF0002A30)->bit16
#define LTCA2_LTCCTR06_ILM       ((T_Reg32 *) 0xF0002A30)->bit8
#define LTCA2_LTCCTR06_OIA       ((T_Reg32 *) 0xF0002A30)->bit14
#define LTCA2_LTCCTR06_OSM       ((T_Reg32 *) 0xF0002A30)->bit2
#define LTCA2_LTCCTR06_OUT       ((T_Reg32 *) 0xF0002A30)->bit15
#define LTCA2_LTCCTR06_RED       ((T_Reg32 *) 0xF0002A30)->bit4
#define LTCA2_LTCCTR06_RED       ((T_Reg32 *) 0xF0002A30)->bit4
#define LTCA2_LTCCTR06_REN       ((T_Reg32 *) 0xF0002A30)->bit3
#define LTCA2_LTCCTR06_SLO       ((T_Reg32 *) 0xF0002A30)->bit6

// Local Timer Cell Control Register 07
#define LTCA2_LTCCTR07         (*((uword volatile *) 0xF0002A38))
#define LTCA2_LTCCTR07_CEN       ((T_Reg32 *) 0xF0002A38)->bit10
#define LTCA2_LTCCTR07_CUD       ((T_Reg32 *) 0xF0002A38)->bit9
#define LTCA2_LTCCTR07_CUDCLR    ((T_Reg32 *) 0xF0002A38)->bit7
#define LTCA2_LTCCTR07_GBYP      ((T_Reg32 *) 0xF0002A38)->bit16
#define LTCA2_LTCCTR07_ILM       ((T_Reg32 *) 0xF0002A38)->bit8
#define LTCA2_LTCCTR07_OIA       ((T_Reg32 *) 0xF0002A38)->bit14
#define LTCA2_LTCCTR07_OSM       ((T_Reg32 *) 0xF0002A38)->bit2
#define LTCA2_LTCCTR07_OUT       ((T_Reg32 *) 0xF0002A38)->bit15
#define LTCA2_LTCCTR07_REN       ((T_Reg32 *) 0xF0002A38)->bit3
#define LTCA2_LTCCTR07_SLO       ((T_Reg32 *) 0xF0002A38)->bit6

// Local Timer Cell Control Register 08
#define LTCA2_LTCCTR08         (*((uword volatile *) 0xF0002A40))
#define LTCA2_LTCCTR08_CEN       ((T_Reg32 *) 0xF0002A40)->bit10
#define LTCA2_LTCCTR08_CUD       ((T_Reg32 *) 0xF0002A40)->bit9
#define LTCA2_LTCCTR08_CUDCLR    ((T_Reg32 *) 0xF0002A40)->bit7
#define LTCA2_LTCCTR08_FED       ((T_Reg32 *) 0xF0002A40)->bit5
#define LTCA2_LTCCTR08_GBYP      ((T_Reg32 *) 0xF0002A40)->bit16
#define LTCA2_LTCCTR08_ILM       ((T_Reg32 *) 0xF0002A40)->bit8
#define LTCA2_LTCCTR08_OIA       ((T_Reg32 *) 0xF0002A40)->bit14
#define LTCA2_LTCCTR08_OSM       ((T_Reg32 *) 0xF0002A40)->bit2
#define LTCA2_LTCCTR08_OUT       ((T_Reg32 *) 0xF0002A40)->bit15
#define LTCA2_LTCCTR08_RED       ((T_Reg32 *) 0xF0002A40)->bit4
#define LTCA2_LTCCTR08_REN       ((T_Reg32 *) 0xF0002A40)->bit3
#define LTCA2_LTCCTR08_SLO       ((T_Reg32 *) 0xF0002A40)->bit6

// Local Timer Cell Control Register 09
#define LTCA2_LTCCTR09         (*((uword volatile *) 0xF0002A48))
#define LTCA2_LTCCTR09_CEN       ((T_Reg32 *) 0xF0002A48)->bit10
#define LTCA2_LTCCTR09_CUD       ((T_Reg32 *) 0xF0002A48)->bit9
#define LTCA2_LTCCTR09_CUDCLR    ((T_Reg32 *) 0xF0002A48)->bit7
#define LTCA2_LTCCTR09_FED       ((T_Reg32 *) 0xF0002A48)->bit5
#define LTCA2_LTCCTR09_GBYP      ((T_Reg32 *) 0xF0002A48)->bit16
#define LTCA2_LTCCTR09_ILM       ((T_Reg32 *) 0xF0002A48)->bit8
#define LTCA2_LTCCTR09_OIA       ((T_Reg32 *) 0xF0002A48)->bit14
#define LTCA2_LTCCTR09_OSM       ((T_Reg32 *) 0xF0002A48)->bit2
#define LTCA2_LTCCTR09_OUT       ((T_Reg32 *) 0xF0002A48)->bit15
#define LTCA2_LTCCTR09_RED       ((T_Reg32 *) 0xF0002A48)->bit4
#define LTCA2_LTCCTR09_REN       ((T_Reg32 *) 0xF0002A48)->bit3
#define LTCA2_LTCCTR09_SLO       ((T_Reg32 *) 0xF0002A48)->bit6

// Local Timer Cell Control Register 10
#define LTCA2_LTCCTR10         (*((uword volatile *) 0xF0002A50))
#define LTCA2_LTCCTR10_CEN       ((T_Reg32 *) 0xF0002A50)->bit10
#define LTCA2_LTCCTR10_CUD       ((T_Reg32 *) 0xF0002A50)->bit9
#define LTCA2_LTCCTR10_CUDCLR    ((T_Reg32 *) 0xF0002A50)->bit7
#define LTCA2_LTCCTR10_FED       ((T_Reg32 *) 0xF0002A50)->bit5
#define LTCA2_LTCCTR10_GBYP      ((T_Reg32 *) 0xF0002A50)->bit16
#define LTCA2_LTCCTR10_ILM       ((T_Reg32 *) 0xF0002A50)->bit8
#define LTCA2_LTCCTR10_OIA       ((T_Reg32 *) 0xF0002A50)->bit14
#define LTCA2_LTCCTR10_OSM       ((T_Reg32 *) 0xF0002A50)->bit2
#define LTCA2_LTCCTR10_OUT       ((T_Reg32 *) 0xF0002A50)->bit15
#define LTCA2_LTCCTR10_RED       ((T_Reg32 *) 0xF0002A50)->bit4
#define LTCA2_LTCCTR10_REN       ((T_Reg32 *) 0xF0002A50)->bit3
#define LTCA2_LTCCTR10_SLO       ((T_Reg32 *) 0xF0002A50)->bit6

// Local Timer Cell Control Register 11
#define LTCA2_LTCCTR11         (*((uword volatile *) 0xF0002A58))
#define LTCA2_LTCCTR11_CEN       ((T_Reg32 *) 0xF0002A58)->bit10
#define LTCA2_LTCCTR11_CUD       ((T_Reg32 *) 0xF0002A58)->bit9
#define LTCA2_LTCCTR11_CUDCLR    ((T_Reg32 *) 0xF0002A58)->bit7
#define LTCA2_LTCCTR11_FED       ((T_Reg32 *) 0xF0002A58)->bit5
#define LTCA2_LTCCTR11_GBYP      ((T_Reg32 *) 0xF0002A58)->bit16
#define LTCA2_LTCCTR11_ILM       ((T_Reg32 *) 0xF0002A58)->bit8
#define LTCA2_LTCCTR11_OIA       ((T_Reg32 *) 0xF0002A58)->bit14
#define LTCA2_LTCCTR11_OSM       ((T_Reg32 *) 0xF0002A58)->bit2
#define LTCA2_LTCCTR11_OUT       ((T_Reg32 *) 0xF0002A58)->bit15
#define LTCA2_LTCCTR11_RED       ((T_Reg32 *) 0xF0002A58)->bit4
#define LTCA2_LTCCTR11_REN       ((T_Reg32 *) 0xF0002A58)->bit3
#define LTCA2_LTCCTR11_SLO       ((T_Reg32 *) 0xF0002A58)->bit6

// Local Timer Cell Control Register 12
#define LTCA2_LTCCTR12         (*((uword volatile *) 0xF0002A60))
#define LTCA2_LTCCTR12_CEN       ((T_Reg32 *) 0xF0002A60)->bit10
#define LTCA2_LTCCTR12_CUD       ((T_Reg32 *) 0xF0002A60)->bit9
#define LTCA2_LTCCTR12_CUDCLR    ((T_Reg32 *) 0xF0002A60)->bit7
#define LTCA2_LTCCTR12_FED       ((T_Reg32 *) 0xF0002A60)->bit5
#define LTCA2_LTCCTR12_GBYP      ((T_Reg32 *) 0xF0002A60)->bit16
#define LTCA2_LTCCTR12_ILM       ((T_Reg32 *) 0xF0002A60)->bit8
#define LTCA2_LTCCTR12_OIA       ((T_Reg32 *) 0xF0002A60)->bit14
#define LTCA2_LTCCTR12_OSM       ((T_Reg32 *) 0xF0002A60)->bit2
#define LTCA2_LTCCTR12_OUT       ((T_Reg32 *) 0xF0002A60)->bit15
#define LTCA2_LTCCTR12_RED       ((T_Reg32 *) 0xF0002A60)->bit4
#define LTCA2_LTCCTR12_REN       ((T_Reg32 *) 0xF0002A60)->bit3
#define LTCA2_LTCCTR12_SLO       ((T_Reg32 *) 0xF0002A60)->bit6

// Local Timer Cell Control Register 13
#define LTCA2_LTCCTR13         (*((uword volatile *) 0xF0002A68))
#define LTCA2_LTCCTR13_CEN       ((T_Reg32 *) 0xF0002A68)->bit10
#define LTCA2_LTCCTR13_CUD       ((T_Reg32 *) 0xF0002A68)->bit9
#define LTCA2_LTCCTR13_CUDCLR    ((T_Reg32 *) 0xF0002A68)->bit7
#define LTCA2_LTCCTR13_FED       ((T_Reg32 *) 0xF0002A68)->bit5
#define LTCA2_LTCCTR13_GBYP      ((T_Reg32 *) 0xF0002A68)->bit16
#define LTCA2_LTCCTR13_ILM       ((T_Reg32 *) 0xF0002A68)->bit8
#define LTCA2_LTCCTR13_OIA       ((T_Reg32 *) 0xF0002A68)->bit14
#define LTCA2_LTCCTR13_OSM       ((T_Reg32 *) 0xF0002A68)->bit2
#define LTCA2_LTCCTR13_OUT       ((T_Reg32 *) 0xF0002A68)->bit15
#define LTCA2_LTCCTR13_RED       ((T_Reg32 *) 0xF0002A68)->bit4
#define LTCA2_LTCCTR13_REN       ((T_Reg32 *) 0xF0002A68)->bit3
#define LTCA2_LTCCTR13_SLO       ((T_Reg32 *) 0xF0002A68)->bit6

// Local Timer Cell Control Register 14
#define LTCA2_LTCCTR14         (*((uword volatile *) 0xF0002A70))
#define LTCA2_LTCCTR14_CEN       ((T_Reg32 *) 0xF0002A70)->bit10
#define LTCA2_LTCCTR14_CUD       ((T_Reg32 *) 0xF0002A70)->bit9
#define LTCA2_LTCCTR14_CUDCLR    ((T_Reg32 *) 0xF0002A70)->bit7
#define LTCA2_LTCCTR14_FED       ((T_Reg32 *) 0xF0002A70)->bit5
#define LTCA2_LTCCTR14_GBYP      ((T_Reg32 *) 0xF0002A70)->bit16
#define LTCA2_LTCCTR14_ILM       ((T_Reg32 *) 0xF0002A70)->bit8
#define LTCA2_LTCCTR14_OIA       ((T_Reg32 *) 0xF0002A70)->bit14
#define LTCA2_LTCCTR14_OSM       ((T_Reg32 *) 0xF0002A70)->bit2
#define LTCA2_LTCCTR14_OUT       ((T_Reg32 *) 0xF0002A70)->bit15
#define LTCA2_LTCCTR14_RED       ((T_Reg32 *) 0xF0002A70)->bit4
#define LTCA2_LTCCTR14_REN       ((T_Reg32 *) 0xF0002A70)->bit3
#define LTCA2_LTCCTR14_SLO       ((T_Reg32 *) 0xF0002A70)->bit6

// Local Timer Cell Control Register 15
#define LTCA2_LTCCTR15         (*((uword volatile *) 0xF0002A78))
#define LTCA2_LTCCTR15_CEN       ((T_Reg32 *) 0xF0002A78)->bit10
#define LTCA2_LTCCTR15_CUD       ((T_Reg32 *) 0xF0002A78)->bit9
#define LTCA2_LTCCTR15_CUDCLR    ((T_Reg32 *) 0xF0002A78)->bit7
#define LTCA2_LTCCTR15_FED       ((T_Reg32 *) 0xF0002A78)->bit5
#define LTCA2_LTCCTR15_GBYP      ((T_Reg32 *) 0xF0002A78)->bit16
#define LTCA2_LTCCTR15_ILM       ((T_Reg32 *) 0xF0002A78)->bit8
#define LTCA2_LTCCTR15_OIA       ((T_Reg32 *) 0xF0002A78)->bit14
#define LTCA2_LTCCTR15_OSM       ((T_Reg32 *) 0xF0002A78)->bit2
#define LTCA2_LTCCTR15_OUT       ((T_Reg32 *) 0xF0002A78)->bit15
#define LTCA2_LTCCTR15_RED       ((T_Reg32 *) 0xF0002A78)->bit4
#define LTCA2_LTCCTR15_REN       ((T_Reg32 *) 0xF0002A78)->bit3
#define LTCA2_LTCCTR15_SLO       ((T_Reg32 *) 0xF0002A78)->bit6

// Local Timer Cell Control Register 16
#define LTCA2_LTCCTR16         (*((uword volatile *) 0xF0002A80))
#define LTCA2_LTCCTR16_CEN       ((T_Reg32 *) 0xF0002A80)->bit10
#define LTCA2_LTCCTR16_CUD       ((T_Reg32 *) 0xF0002A80)->bit9
#define LTCA2_LTCCTR16_CUDCLR    ((T_Reg32 *) 0xF0002A80)->bit7
#define LTCA2_LTCCTR16_FED       ((T_Reg32 *) 0xF0002A80)->bit5
#define LTCA2_LTCCTR16_GBYP      ((T_Reg32 *) 0xF0002A80)->bit16
#define LTCA2_LTCCTR16_ILM       ((T_Reg32 *) 0xF0002A80)->bit8
#define LTCA2_LTCCTR16_OIA       ((T_Reg32 *) 0xF0002A80)->bit14
#define LTCA2_LTCCTR16_OSM       ((T_Reg32 *) 0xF0002A80)->bit2
#define LTCA2_LTCCTR16_OUT       ((T_Reg32 *) 0xF0002A80)->bit15
#define LTCA2_LTCCTR16_RED       ((T_Reg32 *) 0xF0002A80)->bit4
#define LTCA2_LTCCTR16_REN       ((T_Reg32 *) 0xF0002A80)->bit3
#define LTCA2_LTCCTR16_SLO       ((T_Reg32 *) 0xF0002A80)->bit6

// Local Timer Cell Control Register 17
#define LTCA2_LTCCTR17         (*((uword volatile *) 0xF0002A88))
#define LTCA2_LTCCTR17_CEN       ((T_Reg32 *) 0xF0002A88)->bit10
#define LTCA2_LTCCTR17_CUD       ((T_Reg32 *) 0xF0002A88)->bit9
#define LTCA2_LTCCTR17_CUDCLR    ((T_Reg32 *) 0xF0002A88)->bit7
#define LTCA2_LTCCTR17_FED       ((T_Reg32 *) 0xF0002A88)->bit5
#define LTCA2_LTCCTR17_GBYP      ((T_Reg32 *) 0xF0002A88)->bit16
#define LTCA2_LTCCTR17_ILM       ((T_Reg32 *) 0xF0002A88)->bit8
#define LTCA2_LTCCTR17_OIA       ((T_Reg32 *) 0xF0002A88)->bit14
#define LTCA2_LTCCTR17_OSM       ((T_Reg32 *) 0xF0002A88)->bit2
#define LTCA2_LTCCTR17_OUT       ((T_Reg32 *) 0xF0002A88)->bit15
#define LTCA2_LTCCTR17_RED       ((T_Reg32 *) 0xF0002A88)->bit4
#define LTCA2_LTCCTR17_REN       ((T_Reg32 *) 0xF0002A88)->bit3
#define LTCA2_LTCCTR17_SLO       ((T_Reg32 *) 0xF0002A88)->bit6

// Local Timer Cell Control Register 18
#define LTCA2_LTCCTR18         (*((uword volatile *) 0xF0002A90))
#define LTCA2_LTCCTR18_CEN       ((T_Reg32 *) 0xF0002A90)->bit10
#define LTCA2_LTCCTR18_CUD       ((T_Reg32 *) 0xF0002A90)->bit9
#define LTCA2_LTCCTR18_CUDCLR    ((T_Reg32 *) 0xF0002A90)->bit7
#define LTCA2_LTCCTR18_FED       ((T_Reg32 *) 0xF0002A90)->bit5
#define LTCA2_LTCCTR18_GBYP      ((T_Reg32 *) 0xF0002A90)->bit16
#define LTCA2_LTCCTR18_ILM       ((T_Reg32 *) 0xF0002A90)->bit8
#define LTCA2_LTCCTR18_OIA       ((T_Reg32 *) 0xF0002A90)->bit14
#define LTCA2_LTCCTR18_OSM       ((T_Reg32 *) 0xF0002A90)->bit2
#define LTCA2_LTCCTR18_OUT       ((T_Reg32 *) 0xF0002A90)->bit15
#define LTCA2_LTCCTR18_RED       ((T_Reg32 *) 0xF0002A90)->bit4
#define LTCA2_LTCCTR18_REN       ((T_Reg32 *) 0xF0002A90)->bit3
#define LTCA2_LTCCTR18_SLO       ((T_Reg32 *) 0xF0002A90)->bit6

// Local Timer Cell Control Register 19
#define LTCA2_LTCCTR19         (*((uword volatile *) 0xF0002A98))
#define LTCA2_LTCCTR19_CEN       ((T_Reg32 *) 0xF0002A98)->bit10
#define LTCA2_LTCCTR19_CUD       ((T_Reg32 *) 0xF0002A98)->bit9
#define LTCA2_LTCCTR19_CUDCLR    ((T_Reg32 *) 0xF0002A98)->bit7
#define LTCA2_LTCCTR19_FED       ((T_Reg32 *) 0xF0002A98)->bit5
#define LTCA2_LTCCTR19_GBYP      ((T_Reg32 *) 0xF0002A98)->bit16
#define LTCA2_LTCCTR19_ILM       ((T_Reg32 *) 0xF0002A98)->bit8
#define LTCA2_LTCCTR19_OIA       ((T_Reg32 *) 0xF0002A98)->bit14
#define LTCA2_LTCCTR19_OSM       ((T_Reg32 *) 0xF0002A98)->bit2
#define LTCA2_LTCCTR19_OUT       ((T_Reg32 *) 0xF0002A98)->bit15
#define LTCA2_LTCCTR19_RED       ((T_Reg32 *) 0xF0002A98)->bit4
#define LTCA2_LTCCTR19_REN       ((T_Reg32 *) 0xF0002A98)->bit3
#define LTCA2_LTCCTR19_SLO       ((T_Reg32 *) 0xF0002A98)->bit6

// Local Timer Cell Control Register 20
#define LTCA2_LTCCTR20         (*((uword volatile *) 0xF0002AA0))
#define LTCA2_LTCCTR20_CEN       ((T_Reg32 *) 0xF0002AA0)->bit10
#define LTCA2_LTCCTR20_CUD       ((T_Reg32 *) 0xF0002AA0)->bit9
#define LTCA2_LTCCTR20_CUDCLR    ((T_Reg32 *) 0xF0002AA0)->bit7
#define LTCA2_LTCCTR20_FED       ((T_Reg32 *) 0xF0002AA0)->bit5
#define LTCA2_LTCCTR20_GBYP      ((T_Reg32 *) 0xF0002AA0)->bit16
#define LTCA2_LTCCTR20_ILM       ((T_Reg32 *) 0xF0002AA0)->bit8
#define LTCA2_LTCCTR20_OIA       ((T_Reg32 *) 0xF0002AA0)->bit14
#define LTCA2_LTCCTR20_OSM       ((T_Reg32 *) 0xF0002AA0)->bit2
#define LTCA2_LTCCTR20_OUT       ((T_Reg32 *) 0xF0002AA0)->bit15
#define LTCA2_LTCCTR20_RED       ((T_Reg32 *) 0xF0002AA0)->bit4
#define LTCA2_LTCCTR20_REN       ((T_Reg32 *) 0xF0002AA0)->bit3
#define LTCA2_LTCCTR20_SLO       ((T_Reg32 *) 0xF0002AA0)->bit6

// Local Timer Cell Control Register 21
#define LTCA2_LTCCTR21         (*((uword volatile *) 0xF0002AA8))
#define LTCA2_LTCCTR21_CEN       ((T_Reg32 *) 0xF0002AA8)->bit10
#define LTCA2_LTCCTR21_CUD       ((T_Reg32 *) 0xF0002AA8)->bit9
#define LTCA2_LTCCTR21_CUDCLR    ((T_Reg32 *) 0xF0002AA8)->bit7
#define LTCA2_LTCCTR21_FED       ((T_Reg32 *) 0xF0002AA8)->bit5
#define LTCA2_LTCCTR21_GBYP      ((T_Reg32 *) 0xF0002AA8)->bit16
#define LTCA2_LTCCTR21_ILM       ((T_Reg32 *) 0xF0002AA8)->bit8
#define LTCA2_LTCCTR21_OIA       ((T_Reg32 *) 0xF0002AA8)->bit14
#define LTCA2_LTCCTR21_OSM       ((T_Reg32 *) 0xF0002AA8)->bit2
#define LTCA2_LTCCTR21_OUT       ((T_Reg32 *) 0xF0002AA8)->bit15
#define LTCA2_LTCCTR21_RED       ((T_Reg32 *) 0xF0002AA8)->bit4
#define LTCA2_LTCCTR21_REN       ((T_Reg32 *) 0xF0002AA8)->bit3
#define LTCA2_LTCCTR21_SLO       ((T_Reg32 *) 0xF0002AA8)->bit6

// Local Timer Cell Control Register 22
#define LTCA2_LTCCTR22         (*((uword volatile *) 0xF0002AB0))
#define LTCA2_LTCCTR22_CEN       ((T_Reg32 *) 0xF0002AB0)->bit10
#define LTCA2_LTCCTR22_CUD       ((T_Reg32 *) 0xF0002AB0)->bit9
#define LTCA2_LTCCTR22_CUDCLR    ((T_Reg32 *) 0xF0002AB0)->bit7
#define LTCA2_LTCCTR22_FED       ((T_Reg32 *) 0xF0002AB0)->bit5
#define LTCA2_LTCCTR22_GBYP      ((T_Reg32 *) 0xF0002AB0)->bit16
#define LTCA2_LTCCTR22_ILM       ((T_Reg32 *) 0xF0002AB0)->bit8
#define LTCA2_LTCCTR22_OIA       ((T_Reg32 *) 0xF0002AB0)->bit14
#define LTCA2_LTCCTR22_OSM       ((T_Reg32 *) 0xF0002AB0)->bit2
#define LTCA2_LTCCTR22_OUT       ((T_Reg32 *) 0xF0002AB0)->bit15
#define LTCA2_LTCCTR22_RED       ((T_Reg32 *) 0xF0002AB0)->bit4
#define LTCA2_LTCCTR22_REN       ((T_Reg32 *) 0xF0002AB0)->bit3
#define LTCA2_LTCCTR22_SLO       ((T_Reg32 *) 0xF0002AB0)->bit6

// Local Timer Cell Control Register 23
#define LTCA2_LTCCTR23         (*((uword volatile *) 0xF0002AB8))
#define LTCA2_LTCCTR23_CEN       ((T_Reg32 *) 0xF0002AB8)->bit10
#define LTCA2_LTCCTR23_CUD       ((T_Reg32 *) 0xF0002AB8)->bit9
#define LTCA2_LTCCTR23_CUDCLR    ((T_Reg32 *) 0xF0002AB8)->bit7
#define LTCA2_LTCCTR23_FED       ((T_Reg32 *) 0xF0002AB8)->bit5
#define LTCA2_LTCCTR23_GBYP      ((T_Reg32 *) 0xF0002AB8)->bit16
#define LTCA2_LTCCTR23_ILM       ((T_Reg32 *) 0xF0002AB8)->bit8
#define LTCA2_LTCCTR23_OIA       ((T_Reg32 *) 0xF0002AB8)->bit14
#define LTCA2_LTCCTR23_OSM       ((T_Reg32 *) 0xF0002AB8)->bit2
#define LTCA2_LTCCTR23_OUT       ((T_Reg32 *) 0xF0002AB8)->bit15
#define LTCA2_LTCCTR23_RED       ((T_Reg32 *) 0xF0002AB8)->bit4
#define LTCA2_LTCCTR23_REN       ((T_Reg32 *) 0xF0002AB8)->bit3
#define LTCA2_LTCCTR23_SLO       ((T_Reg32 *) 0xF0002AB8)->bit6

// Local Timer Cell Control Register 24
#define LTCA2_LTCCTR24         (*((uword volatile *) 0xF0002AC0))
#define LTCA2_LTCCTR24_CEN       ((T_Reg32 *) 0xF0002AC0)->bit10
#define LTCA2_LTCCTR24_CUD       ((T_Reg32 *) 0xF0002AC0)->bit9
#define LTCA2_LTCCTR24_CUDCLR    ((T_Reg32 *) 0xF0002AC0)->bit7
#define LTCA2_LTCCTR24_FED       ((T_Reg32 *) 0xF0002AC0)->bit5
#define LTCA2_LTCCTR24_GBYP      ((T_Reg32 *) 0xF0002AC0)->bit16
#define LTCA2_LTCCTR24_ILM       ((T_Reg32 *) 0xF0002AC0)->bit8
#define LTCA2_LTCCTR24_OIA       ((T_Reg32 *) 0xF0002AC0)->bit14
#define LTCA2_LTCCTR24_OSM       ((T_Reg32 *) 0xF0002AC0)->bit2
#define LTCA2_LTCCTR24_OUT       ((T_Reg32 *) 0xF0002AC0)->bit15
#define LTCA2_LTCCTR24_RED       ((T_Reg32 *) 0xF0002AC0)->bit4
#define LTCA2_LTCCTR24_REN       ((T_Reg32 *) 0xF0002AC0)->bit3
#define LTCA2_LTCCTR24_SLO       ((T_Reg32 *) 0xF0002AC0)->bit6

// Local Timer Cell Control Register 25
#define LTCA2_LTCCTR25         (*((uword volatile *) 0xF0002AC8))
#define LTCA2_LTCCTR25_CEN       ((T_Reg32 *) 0xF0002AC8)->bit10
#define LTCA2_LTCCTR25_CUD       ((T_Reg32 *) 0xF0002AC8)->bit9
#define LTCA2_LTCCTR25_CUDCLR    ((T_Reg32 *) 0xF0002AC8)->bit7
#define LTCA2_LTCCTR25_FED       ((T_Reg32 *) 0xF0002AC8)->bit5
#define LTCA2_LTCCTR25_GBYP      ((T_Reg32 *) 0xF0002AC8)->bit16
#define LTCA2_LTCCTR25_ILM       ((T_Reg32 *) 0xF0002AC8)->bit8
#define LTCA2_LTCCTR25_OIA       ((T_Reg32 *) 0xF0002AC8)->bit14
#define LTCA2_LTCCTR25_OSM       ((T_Reg32 *) 0xF0002AC8)->bit2
#define LTCA2_LTCCTR25_OUT       ((T_Reg32 *) 0xF0002AC8)->bit15
#define LTCA2_LTCCTR25_RED       ((T_Reg32 *) 0xF0002AC8)->bit4
#define LTCA2_LTCCTR25_REN       ((T_Reg32 *) 0xF0002AC8)->bit3
#define LTCA2_LTCCTR25_SLO       ((T_Reg32 *) 0xF0002AC8)->bit6

// Local Timer Cell Control Register 26
#define LTCA2_LTCCTR26         (*((uword volatile *) 0xF0002AD0))
#define LTCA2_LTCCTR26_CEN       ((T_Reg32 *) 0xF0002AD0)->bit10
#define LTCA2_LTCCTR26_CUD       ((T_Reg32 *) 0xF0002AD0)->bit9
#define LTCA2_LTCCTR26_CUDCLR    ((T_Reg32 *) 0xF0002AD0)->bit7
#define LTCA2_LTCCTR26_FED       ((T_Reg32 *) 0xF0002AD0)->bit5
#define LTCA2_LTCCTR26_GBYP      ((T_Reg32 *) 0xF0002AD0)->bit16
#define LTCA2_LTCCTR26_ILM       ((T_Reg32 *) 0xF0002AD0)->bit8
#define LTCA2_LTCCTR26_OIA       ((T_Reg32 *) 0xF0002AD0)->bit14
#define LTCA2_LTCCTR26_OSM       ((T_Reg32 *) 0xF0002AD0)->bit2
#define LTCA2_LTCCTR26_OUT       ((T_Reg32 *) 0xF0002AD0)->bit15
#define LTCA2_LTCCTR26_RED       ((T_Reg32 *) 0xF0002AD0)->bit4
#define LTCA2_LTCCTR26_REN       ((T_Reg32 *) 0xF0002AD0)->bit3
#define LTCA2_LTCCTR26_SLO       ((T_Reg32 *) 0xF0002AD0)->bit6

// Local Timer Cell Control Register 27
#define LTCA2_LTCCTR27         (*((uword volatile *) 0xF0002AD8))
#define LTCA2_LTCCTR27_CEN       ((T_Reg32 *) 0xF0002AD8)->bit10
#define LTCA2_LTCCTR27_CUD       ((T_Reg32 *) 0xF0002AD8)->bit9
#define LTCA2_LTCCTR27_CUDCLR    ((T_Reg32 *) 0xF0002AD8)->bit7
#define LTCA2_LTCCTR27_FED       ((T_Reg32 *) 0xF0002AD8)->bit5
#define LTCA2_LTCCTR27_GBYP      ((T_Reg32 *) 0xF0002AD8)->bit16
#define LTCA2_LTCCTR27_ILM       ((T_Reg32 *) 0xF0002AD8)->bit8
#define LTCA2_LTCCTR27_OIA       ((T_Reg32 *) 0xF0002AD8)->bit14
#define LTCA2_LTCCTR27_OSM       ((T_Reg32 *) 0xF0002AD8)->bit2
#define LTCA2_LTCCTR27_OUT       ((T_Reg32 *) 0xF0002AD8)->bit15
#define LTCA2_LTCCTR27_RED       ((T_Reg32 *) 0xF0002AD8)->bit4
#define LTCA2_LTCCTR27_REN       ((T_Reg32 *) 0xF0002AD8)->bit3
#define LTCA2_LTCCTR27_SLO       ((T_Reg32 *) 0xF0002AD8)->bit6

// Local Timer Cell Control Register 28
#define LTCA2_LTCCTR28         (*((uword volatile *) 0xF0002AE0))
#define LTCA2_LTCCTR28_CEN       ((T_Reg32 *) 0xF0002AE0)->bit10
#define LTCA2_LTCCTR28_CUD       ((T_Reg32 *) 0xF0002AE0)->bit9
#define LTCA2_LTCCTR28_CUDCLR    ((T_Reg32 *) 0xF0002AE0)->bit7
#define LTCA2_LTCCTR28_FED       ((T_Reg32 *) 0xF0002AE0)->bit5
#define LTCA2_LTCCTR28_GBYP      ((T_Reg32 *) 0xF0002AE0)->bit16
#define LTCA2_LTCCTR28_ILM       ((T_Reg32 *) 0xF0002AE0)->bit8
#define LTCA2_LTCCTR28_OIA       ((T_Reg32 *) 0xF0002AE0)->bit14
#define LTCA2_LTCCTR28_OSM       ((T_Reg32 *) 0xF0002AE0)->bit2
#define LTCA2_LTCCTR28_OUT       ((T_Reg32 *) 0xF0002AE0)->bit15
#define LTCA2_LTCCTR28_RED       ((T_Reg32 *) 0xF0002AE0)->bit4
#define LTCA2_LTCCTR28_REN       ((T_Reg32 *) 0xF0002AE0)->bit3
#define LTCA2_LTCCTR28_SLO       ((T_Reg32 *) 0xF0002AE0)->bit6

// Local Timer Cell Control Register 29
#define LTCA2_LTCCTR29         (*((uword volatile *) 0xF0002AE8))
#define LTCA2_LTCCTR29_CEN       ((T_Reg32 *) 0xF0002AE8)->bit10
#define LTCA2_LTCCTR29_CUD       ((T_Reg32 *) 0xF0002AE8)->bit9
#define LTCA2_LTCCTR29_CUDCLR    ((T_Reg32 *) 0xF0002AE8)->bit7
#define LTCA2_LTCCTR29_FED       ((T_Reg32 *) 0xF0002AE8)->bit5
#define LTCA2_LTCCTR29_GBYP      ((T_Reg32 *) 0xF0002AE8)->bit16
#define LTCA2_LTCCTR29_ILM       ((T_Reg32 *) 0xF0002AE8)->bit8
#define LTCA2_LTCCTR29_OIA       ((T_Reg32 *) 0xF0002AE8)->bit14
#define LTCA2_LTCCTR29_OSM       ((T_Reg32 *) 0xF0002AE8)->bit2
#define LTCA2_LTCCTR29_OUT       ((T_Reg32 *) 0xF0002AE8)->bit15
#define LTCA2_LTCCTR29_RED       ((T_Reg32 *) 0xF0002AE8)->bit4
#define LTCA2_LTCCTR29_REN       ((T_Reg32 *) 0xF0002AE8)->bit3
#define LTCA2_LTCCTR29_SLO       ((T_Reg32 *) 0xF0002AE8)->bit6

// Local Timer Cell Control Register 30
#define LTCA2_LTCCTR30         (*((uword volatile *) 0xF0002AF0))
#define LTCA2_LTCCTR30_CEN       ((T_Reg32 *) 0xF0002AF0)->bit10
#define LTCA2_LTCCTR30_CUD       ((T_Reg32 *) 0xF0002AF0)->bit9
#define LTCA2_LTCCTR30_CUDCLR    ((T_Reg32 *) 0xF0002AF0)->bit7
#define LTCA2_LTCCTR30_FED       ((T_Reg32 *) 0xF0002AF0)->bit5
#define LTCA2_LTCCTR30_GBYP      ((T_Reg32 *) 0xF0002AF0)->bit16
#define LTCA2_LTCCTR30_ILM       ((T_Reg32 *) 0xF0002AF0)->bit8
#define LTCA2_LTCCTR30_OIA       ((T_Reg32 *) 0xF0002AF0)->bit14
#define LTCA2_LTCCTR30_OSM       ((T_Reg32 *) 0xF0002AF0)->bit2
#define LTCA2_LTCCTR30_OUT       ((T_Reg32 *) 0xF0002AF0)->bit15
#define LTCA2_LTCCTR30_RED       ((T_Reg32 *) 0xF0002AF0)->bit4
#define LTCA2_LTCCTR30_REN       ((T_Reg32 *) 0xF0002AF0)->bit3
#define LTCA2_LTCCTR30_SLO       ((T_Reg32 *) 0xF0002AF0)->bit6

// Local Timer Cell Control Register 31
#define LTCA2_LTCCTR31         (*((uword volatile *) 0xF0002AF8))
#define LTCA2_LTCCTR31_BRM       ((T_Reg32 *) 0xF0002AF8)->bit0
#define LTCA2_LTCCTR31_CEN       ((T_Reg32 *) 0xF0002AF8)->bit10
#define LTCA2_LTCCTR31_FED       ((T_Reg32 *) 0xF0002AF8)->bit5
#define LTCA2_LTCCTR31_ILM       ((T_Reg32 *) 0xF0002AF8)->bit8
#define LTCA2_LTCCTR31_OSM       ((T_Reg32 *) 0xF0002AF8)->bit1
#define LTCA2_LTCCTR31_OUT       ((T_Reg32 *) 0xF0002AF8)->bit15
#define LTCA2_LTCCTR31_RED       ((T_Reg32 *) 0xF0002AF8)->bit4

// Local Timer Cell X Register 00
#define LTCA2_LTCXR00          (*((uword volatile *) 0xF0002A04))

// Local Timer Cell X Register 01
#define LTCA2_LTCXR01          (*((uword volatile *) 0xF0002A0C))

// Local Timer Cell X Register 02
#define LTCA2_LTCXR02          (*((uword volatile *) 0xF0002A14))

// Local Timer Cell X Register 03
#define LTCA2_LTCXR03          (*((uword volatile *) 0xF0002A1C))

// Local Timer Cell X Register 04
#define LTCA2_LTCXR04          (*((uword volatile *) 0xF0002A24))

// Local Timer Cell X Register 05
#define LTCA2_LTCXR05          (*((uword volatile *) 0xF0002A2C))

// Local Timer Cell X Register 06
#define LTCA2_LTCXR06          (*((uword volatile *) 0xF0002A34))

// Local Timer Cell X Register 07
#define LTCA2_LTCXR07          (*((uword volatile *) 0xF0002A3C))

// Local Timer Cell X Register 08
#define LTCA2_LTCXR08          (*((uword volatile *) 0xF0002A44))

// Local Timer Cell X Register 09
#define LTCA2_LTCXR09          (*((uword volatile *) 0xF0002A4C))

// Local Timer Cell X Register 10
#define LTCA2_LTCXR10          (*((uword volatile *) 0xF0002A54))

// Local Timer Cell X Register 11
#define LTCA2_LTCXR11          (*((uword volatile *) 0xF0002A5C))

// Local Timer Cell X Register 12
#define LTCA2_LTCXR12          (*((uword volatile *) 0xF0002A64))

// Local Timer Cell X Register 13
#define LTCA2_LTCXR13          (*((uword volatile *) 0xF0002A6C))

// Local Timer Cell X Register 14
#define LTCA2_LTCXR14          (*((uword volatile *) 0xF0002A74))

// Local Timer Cell X Register 15
#define LTCA2_LTCXR15          (*((uword volatile *) 0xF0002A7C))

// Local Timer Cell X Register 16
#define LTCA2_LTCXR16          (*((uword volatile *) 0xF0002A84))

// Local Timer Cell X Register 17
#define LTCA2_LTCXR17          (*((uword volatile *) 0xF0002A8C))

// Local Timer Cell X Register 18
#define LTCA2_LTCXR18          (*((uword volatile *) 0xF0002A94))

// Local Timer Cell X Register 19
#define LTCA2_LTCXR19          (*((uword volatile *) 0xF0002A9C))

// Local Timer Cell X Register 20
#define LTCA2_LTCXR20          (*((uword volatile *) 0xF0002AA4))

// Local Timer Cell X Register 21
#define LTCA2_LTCXR21          (*((uword volatile *) 0xF0002AAC))

// Local Timer Cell X Register 22
#define LTCA2_LTCXR22          (*((uword volatile *) 0xF0002AB4))

// Local Timer Cell X Register 23
#define LTCA2_LTCXR23          (*((uword volatile *) 0xF0002ABC))

// Local Timer Cell X Register 24
#define LTCA2_LTCXR24          (*((uword volatile *) 0xF0002AC4))

// Local Timer Cell X Register 25
#define LTCA2_LTCXR25          (*((uword volatile *) 0xF0002ACC))

// Local Timer Cell X Register 26
#define LTCA2_LTCXR26          (*((uword volatile *) 0xF0002AD4))

// Local Timer Cell X Register 27
#define LTCA2_LTCXR27          (*((uword volatile *) 0xF0002ADC))

// Local Timer Cell X Register 28
#define LTCA2_LTCXR28          (*((uword volatile *) 0xF0002AE4))

// Local Timer Cell X Register 29
#define LTCA2_LTCXR29          (*((uword volatile *) 0xF0002AEC))

// Local Timer Cell X Register 30
#define LTCA2_LTCXR30          (*((uword volatile *) 0xF0002AF4))

// Local Timer Cell X Register 31
#define LTCA2_LTCXR31          (*((uword volatile *) 0xF0002AFC))

// Multiplexer Register Array Control Register
#define LTCA2_MRACTL           (*((uword volatile *) 0xF0002838))
#define LTCA2_MRACTL_FIFOFULL    ((T_Reg32 *) 0xF0002838)->bit2
#define LTCA2_MRACTL_MAEN        ((T_Reg32 *) 0xF0002838)->bit0
#define LTCA2_MRACTL_WCRES       ((T_Reg32 *) 0xF0002838)->bit1

// Multiplexer Register Array Data In Register
#define LTCA2_MRADIN           (*((uword volatile *) 0xF000283C))

// Multiplexer Register Array Data Out Register
#define LTCA2_MRADOUT          (*((uword volatile *) 0xF0002840))

// LTCA2 Interrupt Service Request Control Register 00
#define LTCA2_SRC00            (*((uword volatile *) 0xF0002FFC))
#define LTCA2_SRC00_CLRR         ((T_Reg32 *) 0xF0002FFC)->bit14
#define LTCA2_SRC00_SETR         ((T_Reg32 *) 0xF0002FFC)->bit15
#define LTCA2_SRC00_SRE          ((T_Reg32 *) 0xF0002FFC)->bit12
#define LTCA2_SRC00_SRR          ((T_Reg32 *) 0xF0002FFC)->bit13
#define LTCA2_SRC00_TOS          ((T_Reg32 *) 0xF0002FFC)->bit10

// LTCA2 Interrupt Service Request Control Register 01
#define LTCA2_SRC01            (*((uword volatile *) 0xF0002FF8))
#define LTCA2_SRC01_CLRR         ((T_Reg32 *) 0xF0002FF8)->bit14
#define LTCA2_SRC01_SETR         ((T_Reg32 *) 0xF0002FF8)->bit15
#define LTCA2_SRC01_SRE          ((T_Reg32 *) 0xF0002FF8)->bit12
#define LTCA2_SRC01_SRR          ((T_Reg32 *) 0xF0002FF8)->bit13
#define LTCA2_SRC01_TOS          ((T_Reg32 *) 0xF0002FF8)->bit10

// LTCA2 Interrupt Service Request Control Register 02
#define LTCA2_SRC02            (*((uword volatile *) 0xF0002FF4))
#define LTCA2_SRC02_CLRR         ((T_Reg32 *) 0xF0002FF4)->bit14
#define LTCA2_SRC02_SETR         ((T_Reg32 *) 0xF0002FF4)->bit15
#define LTCA2_SRC02_SRE          ((T_Reg32 *) 0xF0002FF4)->bit12
#define LTCA2_SRC02_SRR          ((T_Reg32 *) 0xF0002FF4)->bit13
#define LTCA2_SRC02_TOS          ((T_Reg32 *) 0xF0002FF4)->bit10

// LTCA2 Interrupt Service Request Control Register 03
#define LTCA2_SRC03            (*((uword volatile *) 0xF0002FF0))
#define LTCA2_SRC03_CLRR         ((T_Reg32 *) 0xF0002FF0)->bit14
#define LTCA2_SRC03_SETR         ((T_Reg32 *) 0xF0002FF0)->bit15
#define LTCA2_SRC03_SRE          ((T_Reg32 *) 0xF0002FF0)->bit12
#define LTCA2_SRC03_SRR          ((T_Reg32 *) 0xF0002FF0)->bit13
#define LTCA2_SRC03_TOS          ((T_Reg32 *) 0xF0002FF0)->bit10

// LTCA2 Interrupt Service Request Control Register 04
#define LTCA2_SRC04            (*((uword volatile *) 0xF0002FEC))
#define LTCA2_SRC04_CLRR         ((T_Reg32 *) 0xF0002FEC)->bit14
#define LTCA2_SRC04_SETR         ((T_Reg32 *) 0xF0002FEC)->bit15
#define LTCA2_SRC04_SRE          ((T_Reg32 *) 0xF0002FEC)->bit12
#define LTCA2_SRC04_SRR          ((T_Reg32 *) 0xF0002FEC)->bit13
#define LTCA2_SRC04_TOS          ((T_Reg32 *) 0xF0002FEC)->bit10

// LTCA2 Interrupt Service Request Control Register 05
#define LTCA2_SRC05            (*((uword volatile *) 0xF0002FE8))
#define LTCA2_SRC05_CLRR         ((T_Reg32 *) 0xF0002FE8)->bit14
#define LTCA2_SRC05_SETR         ((T_Reg32 *) 0xF0002FE8)->bit15
#define LTCA2_SRC05_SRE          ((T_Reg32 *) 0xF0002FE8)->bit12
#define LTCA2_SRC05_SRR          ((T_Reg32 *) 0xF0002FE8)->bit13
#define LTCA2_SRC05_TOS          ((T_Reg32 *) 0xF0002FE8)->bit10

// LTCA2 Interrupt Service Request Control Register 06
#define LTCA2_SRC06            (*((uword volatile *) 0xF0002FE4))
#define LTCA2_SRC06_CLRR         ((T_Reg32 *) 0xF0002FE4)->bit14
#define LTCA2_SRC06_SETR         ((T_Reg32 *) 0xF0002FE4)->bit15
#define LTCA2_SRC06_SRE          ((T_Reg32 *) 0xF0002FE4)->bit12
#define LTCA2_SRC06_SRR          ((T_Reg32 *) 0xF0002FE4)->bit13
#define LTCA2_SRC06_TOS          ((T_Reg32 *) 0xF0002FE4)->bit10

// LTCA2 Interrupt Service Request Control Register 07
#define LTCA2_SRC07            (*((uword volatile *) 0xF0002FE0))
#define LTCA2_SRC07_CLRR         ((T_Reg32 *) 0xF0002FE0)->bit14
#define LTCA2_SRC07_SETR         ((T_Reg32 *) 0xF0002FE0)->bit15
#define LTCA2_SRC07_SRE          ((T_Reg32 *) 0xF0002FE0)->bit12
#define LTCA2_SRC07_SRR          ((T_Reg32 *) 0xF0002FE0)->bit13
#define LTCA2_SRC07_TOS          ((T_Reg32 *) 0xF0002FE0)->bit10

// LTCA2 Service Request State Clear Register 2
#define LTCA2_SRSC2            (*((uword volatile *) 0xF0002820))
#define LTCA2_SRSC2_LTC00         ((T_Reg32 *) 0xF0002820)->bit0
#define LTCA2_SRSC2_LTC01         ((T_Reg32 *) 0xF0002820)->bit1
#define LTCA2_SRSC2_LTC10        ((T_Reg32 *) 0xF0002820)->bit10
#define LTCA2_SRSC2_LTC11        ((T_Reg32 *) 0xF0002820)->bit11
#define LTCA2_SRSC2_LTC12        ((T_Reg32 *) 0xF0002820)->bit12
#define LTCA2_SRSC2_LTC13        ((T_Reg32 *) 0xF0002820)->bit13
#define LTCA2_SRSC2_LTC14        ((T_Reg32 *) 0xF0002820)->bit14
#define LTCA2_SRSC2_LTC15        ((T_Reg32 *) 0xF0002820)->bit15
#define LTCA2_SRSC2_LTC16        ((T_Reg32 *) 0xF0002820)->bit16
#define LTCA2_SRSC2_LTC17        ((T_Reg32 *) 0xF0002820)->bit17
#define LTCA2_SRSC2_LTC18        ((T_Reg32 *) 0xF0002820)->bit18
#define LTCA2_SRSC2_LTC19        ((T_Reg32 *) 0xF0002820)->bit19
#define LTCA2_SRSC2_LTC02         ((T_Reg32 *) 0xF0002820)->bit2
#define LTCA2_SRSC2_LTC20        ((T_Reg32 *) 0xF0002820)->bit20
#define LTCA2_SRSC2_LTC21        ((T_Reg32 *) 0xF0002820)->bit21
#define LTCA2_SRSC2_LTC22        ((T_Reg32 *) 0xF0002820)->bit22
#define LTCA2_SRSC2_LTC23        ((T_Reg32 *) 0xF0002820)->bit23
#define LTCA2_SRSC2_LTC24        ((T_Reg32 *) 0xF0002820)->bit24
#define LTCA2_SRSC2_LTC25        ((T_Reg32 *) 0xF0002820)->bit25
#define LTCA2_SRSC2_LTC26        ((T_Reg32 *) 0xF0002820)->bit26
#define LTCA2_SRSC2_LTC27        ((T_Reg32 *) 0xF0002820)->bit27
#define LTCA2_SRSC2_LTC28        ((T_Reg32 *) 0xF0002820)->bit28
#define LTCA2_SRSC2_LTC29        ((T_Reg32 *) 0xF0002820)->bit29
#define LTCA2_SRSC2_LTC03         ((T_Reg32 *) 0xF0002820)->bit3
#define LTCA2_SRSC2_LTC30        ((T_Reg32 *) 0xF0002820)->bit30
#define LTCA2_SRSC2_LTC31        ((T_Reg32 *) 0xF0002820)->bit31
#define LTCA2_SRSC2_LTC04         ((T_Reg32 *) 0xF0002820)->bit4
#define LTCA2_SRSC2_LTC05         ((T_Reg32 *) 0xF0002820)->bit5
#define LTCA2_SRSC2_LTC06         ((T_Reg32 *) 0xF0002820)->bit6
#define LTCA2_SRSC2_LTC07         ((T_Reg32 *) 0xF0002820)->bit7
#define LTCA2_SRSC2_LTC08         ((T_Reg32 *) 0xF0002820)->bit8
#define LTCA2_SRSC2_LTC09         ((T_Reg32 *) 0xF0002820)->bit9

// LTCA2 Service Request State Set Register 2
#define LTCA2_SRSS2            (*((uword volatile *) 0xF0002824))
#define LTCA2_SRSS2_LTC00         ((T_Reg32 *) 0xF0002824)->bit0
#define LTCA2_SRSS2_LTC01         ((T_Reg32 *) 0xF0002824)->bit1
#define LTCA2_SRSS2_LTC10        ((T_Reg32 *) 0xF0002824)->bit10
#define LTCA2_SRSS2_LTC11        ((T_Reg32 *) 0xF0002824)->bit11
#define LTCA2_SRSS2_LTC12        ((T_Reg32 *) 0xF0002824)->bit12
#define LTCA2_SRSS2_LTC13        ((T_Reg32 *) 0xF0002824)->bit13
#define LTCA2_SRSS2_LTC14        ((T_Reg32 *) 0xF0002824)->bit14
#define LTCA2_SRSS2_LTC15        ((T_Reg32 *) 0xF0002824)->bit15
#define LTCA2_SRSS2_LTC16        ((T_Reg32 *) 0xF0002824)->bit16
#define LTCA2_SRSS2_LTC17        ((T_Reg32 *) 0xF0002824)->bit17
#define LTCA2_SRSS2_LTC18        ((T_Reg32 *) 0xF0002824)->bit18
#define LTCA2_SRSS2_LTC19        ((T_Reg32 *) 0xF0002824)->bit19
#define LTCA2_SRSS2_LTC02         ((T_Reg32 *) 0xF0002824)->bit2
#define LTCA2_SRSS2_LTC20        ((T_Reg32 *) 0xF0002824)->bit20
#define LTCA2_SRSS2_LTC21        ((T_Reg32 *) 0xF0002824)->bit21
#define LTCA2_SRSS2_LTC22        ((T_Reg32 *) 0xF0002824)->bit22
#define LTCA2_SRSS2_LTC23        ((T_Reg32 *) 0xF0002824)->bit23
#define LTCA2_SRSS2_LTC24        ((T_Reg32 *) 0xF0002824)->bit24
#define LTCA2_SRSS2_LTC25        ((T_Reg32 *) 0xF0002824)->bit25
#define LTCA2_SRSS2_LTC26        ((T_Reg32 *) 0xF0002824)->bit26
#define LTCA2_SRSS2_LTC27        ((T_Reg32 *) 0xF0002824)->bit27
#define LTCA2_SRSS2_LTC28        ((T_Reg32 *) 0xF0002824)->bit28
#define LTCA2_SRSS2_LTC29        ((T_Reg32 *) 0xF0002824)->bit29
#define LTCA2_SRSS2_LTC03         ((T_Reg32 *) 0xF0002824)->bit3
#define LTCA2_SRSS2_LTC30        ((T_Reg32 *) 0xF0002824)->bit30
#define LTCA2_SRSS2_LTC31        ((T_Reg32 *) 0xF0002824)->bit31
#define LTCA2_SRSS2_LTC04         ((T_Reg32 *) 0xF0002824)->bit4
#define LTCA2_SRSS2_LTC05         ((T_Reg32 *) 0xF0002824)->bit5
#define LTCA2_SRSS2_LTC06         ((T_Reg32 *) 0xF0002824)->bit6
#define LTCA2_SRSS2_LTC07         ((T_Reg32 *) 0xF0002824)->bit7
#define LTCA2_SRSS2_LTC08         ((T_Reg32 *) 0xF0002824)->bit8
#define LTCA2_SRSS2_LTC09         ((T_Reg32 *) 0xF0002824)->bit9

// Multi-Count Register 1
#define M1CNT                  (*((uword volatile *) 0xF7E1FC0C))
#define M1CNT_SOVF               0x80000000

// Multi-Count Register 2
#define M2CNT                  (*((uword volatile *) 0xF7E1FC10))
#define M2CNT_SOVF               0x80000000

// Multi-Count Register 3
#define M3CNT                  (*((uword volatile *) 0xF7E1FC14))
#define M3CNT_SOVF               0x80000000

// Module Identification Register
#define MCHK_ID                (*((uword volatile *) 0xF010C208))

// Memory Checker Input Register
#define MCHK_IR                (*((uword volatile *) 0xF010C210))

// Memory Checker Result Register
#define MCHK_RR                (*((uword volatile *) 0xF010C214))

// Memory Checker Write Register
#define MCHK_WR                (*((uword volatile *) 0xF010C220))

// Memory Integrity Error Control Register
#define MIECON                 (*((uword volatile *) 0xF7E19044))
#define MIECON_DMIEE             0x00000001
#define MIECON_DTIEE             0x00010000
#define MIECON_PMIEE             0x00000100
#define MIECON_PTIEE             0x00040000

// MLI0 Access Enable Register
#define MLI0_AER               (*((uword volatile *) 0xF010C0B8))
#define MLI0_AER_AEN0            0x00000001
#define MLI0_AER_AEN1            0x00000002
#define MLI0_AER_AEN10           0x00000400
#define MLI0_AER_AEN11           0x00000800
#define MLI0_AER_AEN12           0x00001000
#define MLI0_AER_AEN13           0x00002000
#define MLI0_AER_AEN14           0x00004000
#define MLI0_AER_AEN15           0x00008000
#define MLI0_AER_AEN16           0x00010000
#define MLI0_AER_AEN17           0x00020000
#define MLI0_AER_AEN18           0x00040000
#define MLI0_AER_AEN19           0x00080000
#define MLI0_AER_AEN2            0x00000004
#define MLI0_AER_AEN20           0x00100000
#define MLI0_AER_AEN21           0x00200000
#define MLI0_AER_AEN22           0x00400000
#define MLI0_AER_AEN23           0x00800000
#define MLI0_AER_AEN24           0x01000000
#define MLI0_AER_AEN25           0x02000000
#define MLI0_AER_AEN26           0x04000000
#define MLI0_AER_AEN27           0x08000000
#define MLI0_AER_AEN28           0x10000000
#define MLI0_AER_AEN29           0x20000000
#define MLI0_AER_AEN3            0x00000008
#define MLI0_AER_AEN30           0x40000000
#define MLI0_AER_AEN31           0x80000000
#define MLI0_AER_AEN4            0x00000010
#define MLI0_AER_AEN5            0x00000020
#define MLI0_AER_AEN6            0x00000040
#define MLI0_AER_AEN7            0x00000080
#define MLI0_AER_AEN8            0x00000100
#define MLI0_AER_AEN9            0x00000200

// MLI0 Access Range Register
#define MLI0_ARR               (*((uword volatile *) 0xF010C0BC))

// MLI0 Fractional Divider Register
#define MLI0_FDR               (*((uword volatile *) 0xF010C00C))
#define MLI0_FDR_DISCLK          0x80000000
#define MLI0_FDR_ENHW            0x40000000
#define MLI0_FDR_SM              0x00000800
#define MLI0_FDR_SUSACK          0x10000000
#define MLI0_FDR_SUSREQ          0x20000000

// MLI0 Global Interrupt Set Register
#define MLI0_GINTR             (*((uword volatile *) 0xF010C0B0))
#define MLI0_GINTR_SIMLI0        0x00000001
#define MLI0_GINTR_SIMLI1        0x00000002
#define MLI0_GINTR_SIMLI2        0x00000004
#define MLI0_GINTR_SIMLI3        0x00000008
#define MLI0_GINTR_SIMLI4        0x00000010
#define MLI0_GINTR_SIMLI5        0x00000020
#define MLI0_GINTR_SIMLI6        0x00000040
#define MLI0_GINTR_SIMLI7        0x00000080

// MLI0 Module Identification Register
#define MLI0_ID                (*((uword volatile *) 0xF010C008))

// MLI0 Output Input Control Register
#define MLI0_OICR              (*((uword volatile *) 0xF010C0B4))
#define MLI0_OICR_RCE            0x10000000
#define MLI0_OICR_RCP            0x08000000
#define MLI0_OICR_RDP            0x80000000
#define MLI0_OICR_RRPA           0x00040000
#define MLI0_OICR_RRPB           0x00080000
#define MLI0_OICR_RRPC           0x00100000
#define MLI0_OICR_RRPD           0x00200000
#define MLI0_OICR_RVE            0x00008000
#define MLI0_OICR_RVP            0x01000000
#define MLI0_OICR_TCE            0x00001000
#define MLI0_OICR_TCP            0x00002000
#define MLI0_OICR_TDP            0x00004000
#define MLI0_OICR_TRE            0x00000800
#define MLI0_OICR_TRP            0x00000400
#define MLI0_OICR_TVEA           0x00000001
#define MLI0_OICR_TVEB           0x00000002
#define MLI0_OICR_TVEC           0x00000004
#define MLI0_OICR_TVED           0x00000008
#define MLI0_OICR_TVPA           0x00000010
#define MLI0_OICR_TVPB           0x00000020
#define MLI0_OICR_TVPC           0x00000040
#define MLI0_OICR_TVPD           0x00000080

// MLI0 Receiver Address Register
#define MLI0_RADRR             (*((uword volatile *) 0xF010C08C))

// MLI0 Receiver Control Register
#define MLI0_RCR               (*((uword volatile *) 0xF010C068))
#define MLI0_RCR_BEN             0x00100000
#define MLI0_RCR_MOD             0x00000100
#define MLI0_RCR_PE              0x00002000
#define MLI0_RCR_RCVRST          0x01000000

// MLI0 Receiver Data Register
#define MLI0_RDATAR            (*((uword volatile *) 0xF010C090))

// MLI0 Receiver Interrupt Enable Register
#define MLI0_RIER              (*((uword volatile *) 0xF010C0A4))
#define MLI0_RIER_CFRIE0         0x00000004
#define MLI0_RIER_CFRIE1         0x00000008
#define MLI0_RIER_CFRIE2         0x00000010
#define MLI0_RIER_CFRIE3         0x00000020
#define MLI0_RIER_CFRIR0         0x00040000
#define MLI0_RIER_CFRIR1         0x00080000
#define MLI0_RIER_CFRIR2         0x00100000
#define MLI0_RIER_CFRIR3         0x00200000
#define MLI0_RIER_DRAIE          0x00000200
#define MLI0_RIER_DRAIR          0x02000000
#define MLI0_RIER_ICE            0x00000040
#define MLI0_RIER_ICER           0x00400000
#define MLI0_RIER_MEIR           0x00020000
#define MLI0_RIER_MPEIE          0x00000100
#define MLI0_RIER_MPEIR          0x01000000
#define MLI0_RIER_NFRIR          0x00010000
#define MLI0_RIER_PEIE           0x00000080
#define MLI0_RIER_PEIR           0x00800000

// MLI0 Receiver Interrupt Node Pointer Register
#define MLI0_RINPR             (*((uword volatile *) 0xF010C0AC))

// MLI0 Receiver Interrupt Status Register
#define MLI0_RISR              (*((uword volatile *) 0xF010C0A8))
#define MLI0_RISR_CFRI0          0x00000004
#define MLI0_RISR_CFRI1          0x00000008
#define MLI0_RISR_CFRI2          0x00000010
#define MLI0_RISR_CFRI3          0x00000020
#define MLI0_RISR_DRAI           0x00000200
#define MLI0_RISR_IC             0x00000040
#define MLI0_RISR_MEI            0x00000002
#define MLI0_RISR_MPEI           0x00000100
#define MLI0_RISR_NFRI           0x00000001
#define MLI0_RISR_PEI            0x00000080

// MLI0 Receiver Pipe 0 Base Address Register
#define MLI0_RP0BAR            (*((uword volatile *) 0xF010C06C))

// MLI0 Receiver Pipe 0 Status Register
#define MLI0_RP0STATR          (*((uword volatile *) 0xF010C07C))

// MLI0 Receiver Pipe 1 Base Address Register
#define MLI0_RP1BAR            (*((uword volatile *) 0xF010C070))

// MLI0 Receiver Pipe 1 Status Register
#define MLI0_RP1STATR          (*((uword volatile *) 0xF010C080))

// MLI0 Receiver Pipe 2 Base Address Register
#define MLI0_RP2BAR            (*((uword volatile *) 0xF010C074))

// MLI0 Receiver Pipe 2 Status Register
#define MLI0_RP2STATR          (*((uword volatile *) 0xF010C084))

// MLI0 Receiver Pipe 3 Base Address Register
#define MLI0_RP3BAR            (*((uword volatile *) 0xF010C078))

// MLI0 Receiver Pipe 3 Status Register
#define MLI0_RP3STATR          (*((uword volatile *) 0xF010C088))

// MLI0 Set Clear Register
#define MLI0_SCR               (*((uword volatile *) 0xF010C094))
#define MLI0_SCR_CAV             0x01000000
#define MLI0_SCR_CBAV            0x00020000
#define MLI0_SCR_CCIV0           0x10000000
#define MLI0_SCR_CCIV1           0x20000000
#define MLI0_SCR_CCIV2           0x40000000
#define MLI0_SCR_CCIV3           0x80000000
#define MLI0_SCR_CCV0            0x00001000
#define MLI0_SCR_CCV1            0x00002000
#define MLI0_SCR_CCV2            0x00004000
#define MLI0_SCR_CCV3            0x00008000
#define MLI0_SCR_CDV0            0x00000100
#define MLI0_SCR_CDV1            0x00000200
#define MLI0_SCR_CDV2            0x00000400
#define MLI0_SCR_CDV3            0x00000800
#define MLI0_SCR_CMOD            0x00010000
#define MLI0_SCR_CNAE            0x08000000
#define MLI0_SCR_CRPE            0x02000000
#define MLI0_SCR_CTPE            0x04000000
#define MLI0_SCR_SCV0            0x00000001
#define MLI0_SCR_SCV1            0x00000002
#define MLI0_SCR_SCV2            0x00000004
#define MLI0_SCR_SCV3            0x00000008
#define MLI0_SCR_SMOD            0x00000010

// MLI0 Transmitter Copy Base Address Register
#define MLI0_TCBAR             (*((uword volatile *) 0xF010C064))

// MLI0 Transmitter Command Register
#define MLI0_TCMDR             (*((uword volatile *) 0xF010C028))

// MLI0 Transmitter Control Register
#define MLI0_TCR               (*((uword volatile *) 0xF010C010))
#define MLI0_TCR_DNT             0x00000002
#define MLI0_TCR_MOD             0x00000001
#define MLI0_TCR_NO              0x00004000
#define MLI0_TCR_TP              0x00008000

// MLI0 Transmitter Data Read Answer Register
#define MLI0_TDRAR             (*((uword volatile *) 0xF010C050))

// MLI0 Transmitter Interrupt Enable Register
#define MLI0_TIER              (*((uword volatile *) 0xF010C098))
#define MLI0_TIER_CFSIE0         0x00000010
#define MLI0_TIER_CFSIE1         0x00000020
#define MLI0_TIER_CFSIE2         0x00000040
#define MLI0_TIER_CFSIE3         0x00000080
#define MLI0_TIER_CFSIR0         0x00100000
#define MLI0_TIER_CFSIR1         0x00200000
#define MLI0_TIER_CFSIR2         0x00400000
#define MLI0_TIER_CFSIR3         0x00800000
#define MLI0_TIER_NFSIE0         0x00000001
#define MLI0_TIER_NFSIE1         0x00000002
#define MLI0_TIER_NFSIE2         0x00000004
#define MLI0_TIER_NFSIE3         0x00000008
#define MLI0_TIER_NFSIR0         0x00010000
#define MLI0_TIER_NFSIR1         0x00020000
#define MLI0_TIER_NFSIR2         0x00040000
#define MLI0_TIER_NFSIR3         0x00080000
#define MLI0_TIER_PEIE           0x00000100
#define MLI0_TIER_PEIR           0x01000000
#define MLI0_TIER_TEIE           0x00000200
#define MLI0_TIER_TEIR           0x02000000

// MLI0 Transmitter Interrupt Node Pointer Register
#define MLI0_TINPR             (*((uword volatile *) 0xF010C0A0))

// MLI0 Transmitter Interrupt Status Register
#define MLI0_TISR              (*((uword volatile *) 0xF010C09C))
#define MLI0_TISR_CFSI0          0x00000010
#define MLI0_TISR_CFSI1          0x00000020
#define MLI0_TISR_CFSI2          0x00000040
#define MLI0_TISR_CFSI3          0x00000080
#define MLI0_TISR_NFSI0          0x00000001
#define MLI0_TISR_NFSI1          0x00000002
#define MLI0_TISR_NFSI2          0x00000004
#define MLI0_TISR_NFSI3          0x00000008
#define MLI0_TISR_PEI            0x00000100
#define MLI0_TISR_TEI            0x00000200

// MLI0 Transmitter Pipe 0 Address Offset Register
#define MLI0_TP0AOFR           (*((uword volatile *) 0xF010C030))

// MLI0 Transmitter Pipe 0 Base Address Register
#define MLI0_TP0BAR            (*((uword volatile *) 0xF010C054))

// MLI0 Transmitter Pipe 0 Data Register
#define MLI0_TP0DATAR          (*((uword volatile *) 0xF010C040))

// MLI0 Transmitter Pipe 0 Status Register
#define MLI0_TP0STATR          (*((uword volatile *) 0xF010C018))
#define MLI0_TP0STATR_OP         0x00010000

// MLI0 Transmitter Pipe 1 Address Offset Register
#define MLI0_TP1AOFR           (*((uword volatile *) 0xF010C034))

// MLI0 Transmitter Pipe 1 Base Address Register
#define MLI0_TP1BAR            (*((uword volatile *) 0xF010C058))

// MLI0 Transmitter Pipe 1 Data Register
#define MLI0_TP1DATAR          (*((uword volatile *) 0xF010C044))

// MLI0 Transmitter Pipe 1 Status Register
#define MLI0_TP1STATR          (*((uword volatile *) 0xF010C01C))
#define MLI0_TP1STATR_OP         0x00010000

// MLI0 Transmitter Pipe 2 Address Offset Register
#define MLI0_TP2AOFR           (*((uword volatile *) 0xF010C038))

// MLI0 Transmitter Pipe 2 Base Address Register
#define MLI0_TP2BAR            (*((uword volatile *) 0xF010C05C))

// MLI0 Transmitter Pipe 2 Data Register
#define MLI0_TP2DATAR          (*((uword volatile *) 0xF010C048))

// MLI0 Transmitter Pipe 2 Status Register
#define MLI0_TP2STATR          (*((uword volatile *) 0xF010C020))
#define MLI0_TP2STATR_OP         0x00010000

// MLI0 Transmitter Pipe 3 Address Offset Register
#define MLI0_TP3AOFR           (*((uword volatile *) 0xF010C03C))

// MLI0 Transmitter Pipe 3 Base Address Register
#define MLI0_TP3BAR            (*((uword volatile *) 0xF010C060))

// MLI0 Transmitter Pipe 3 Data Register
#define MLI0_TP3DATAR          (*((uword volatile *) 0xF010C04C))

// MLI0 Transmitter Pipe 3 Status Register
#define MLI0_TP3STATR          (*((uword volatile *) 0xF010C024))
#define MLI0_TP3STATR_OP         0x00010000

// MLI0 Transmitter Receiver Status Register
#define MLI0_TRSTATR           (*((uword volatile *) 0xF010C02C))
#define MLI0_TRSTATR_AV          0x00000100
#define MLI0_TRSTATR_BAV         0x00000200
#define MLI0_TRSTATR_CIV0        0x00000001
#define MLI0_TRSTATR_CIV1        0x00000002
#define MLI0_TRSTATR_CIV2        0x00000004
#define MLI0_TRSTATR_CIV3        0x00000008
#define MLI0_TRSTATR_CV0         0x00000010
#define MLI0_TRSTATR_CV1         0x00000020
#define MLI0_TRSTATR_CV2         0x00000040
#define MLI0_TRSTATR_CV3         0x00000080
#define MLI0_TRSTATR_DV0         0x00010000
#define MLI0_TRSTATR_DV1         0x00020000
#define MLI0_TRSTATR_DV2         0x00040000
#define MLI0_TRSTATR_DV3         0x00080000
#define MLI0_TRSTATR_RP0         0x00100000
#define MLI0_TRSTATR_RP1         0x00200000
#define MLI0_TRSTATR_RP2         0x00400000
#define MLI0_TRSTATR_RP3         0x00800000

// MLI0 Transmitter Status Register
#define MLI0_TSTATR            (*((uword volatile *) 0xF010C014))
#define MLI0_TSTATR_NAE          0x00000100
#define MLI0_TSTATR_PE           0x00000080

// MMU Control Register
#define MMU_CON                (*((uword volatile *) 0xF7E18000))
#define MMU_CON_NOMMU            0x00008000

// MSC0 Clock Control Register
#define MSC0_CLC               (*((uword volatile *) 0xF0000800))
#define MSC0_CLC_DISR            ((T_Reg32 *) 0xF0000800)->bit0
#define MSC0_CLC_DISS            ((T_Reg32 *) 0xF0000800)->bit1
#define MSC0_CLC_EDIS            ((T_Reg32 *) 0xF0000800)->bit3
#define MSC0_CLC_FSOE            ((T_Reg32 *) 0xF0000800)->bit5
#define MSC0_CLC_SBWE            ((T_Reg32 *) 0xF0000800)->bit4
#define MSC0_CLC_SPEN            ((T_Reg32 *) 0xF0000800)->bit2

// MSC0 Downstream Command Register
#define MSC0_DC                (*((uword volatile *) 0xF0000820))

// MSC0 Downstream Data Register
#define MSC0_DD                (*((uword volatile *) 0xF000081C))

// MSC0 Downstream Control Register
#define MSC0_DSC               (*((uword volatile *) 0xF0000814))
#define MSC0_DSC_CP              ((T_Reg32 *) 0xF0000814)->bit1
#define MSC0_DSC_DP              ((T_Reg32 *) 0xF0000814)->bit2
#define MSC0_DSC_DSDIS           ((T_Reg32 *) 0xF0000814)->bit15
#define MSC0_DSC_ENSELH          ((T_Reg32 *) 0xF0000814)->bit14
#define MSC0_DSC_ENSELL          ((T_Reg32 *) 0xF0000814)->bit13
#define MSC0_DSC_TM              ((T_Reg32 *) 0xF0000814)->bit0

// MSC0 Downstream Select Data Source High Register
#define MSC0_DSDSH             (*((uword volatile *) 0xF0000828))

// MSC0 Downstream Select Data Source Low Register
#define MSC0_DSDSL             (*((uword volatile *) 0xF0000824))

// MSC0 Downstream Status Register
#define MSC0_DSS               (*((uword volatile *) 0xF0000818))
#define MSC0_DSS_CFA             ((T_Reg32 *) 0xF0000818)->bit25
#define MSC0_DSS_DFA             ((T_Reg32 *) 0xF0000818)->bit24

// MSC0 Emergency Stop Register
#define MSC0_ESR               (*((uword volatile *) 0xF000082C))
#define MSC0_ESR_ENH0            ((T_Reg32 *) 0xF000082C)->bit16
#define MSC0_ESR_ENH1            ((T_Reg32 *) 0xF000082C)->bit17
#define MSC0_ESR_ENH10           ((T_Reg32 *) 0xF000082C)->bit26
#define MSC0_ESR_ENH11           ((T_Reg32 *) 0xF000082C)->bit27
#define MSC0_ESR_ENH12           ((T_Reg32 *) 0xF000082C)->bit28
#define MSC0_ESR_ENH13           ((T_Reg32 *) 0xF000082C)->bit29
#define MSC0_ESR_ENH14           ((T_Reg32 *) 0xF000082C)->bit30
#define MSC0_ESR_ENH15           ((T_Reg32 *) 0xF000082C)->bit31
#define MSC0_ESR_ENH2            ((T_Reg32 *) 0xF000082C)->bit18
#define MSC0_ESR_ENH3            ((T_Reg32 *) 0xF000082C)->bit19
#define MSC0_ESR_ENH4            ((T_Reg32 *) 0xF000082C)->bit20
#define MSC0_ESR_ENH5            ((T_Reg32 *) 0xF000082C)->bit21
#define MSC0_ESR_ENH6            ((T_Reg32 *) 0xF000082C)->bit22
#define MSC0_ESR_ENH7            ((T_Reg32 *) 0xF000082C)->bit23
#define MSC0_ESR_ENH8            ((T_Reg32 *) 0xF000082C)->bit24
#define MSC0_ESR_ENH9            ((T_Reg32 *) 0xF000082C)->bit25
#define MSC0_ESR_ENL0            ((T_Reg32 *) 0xF000082C)->bit0
#define MSC0_ESR_ENL1            ((T_Reg32 *) 0xF000082C)->bit1
#define MSC0_ESR_ENL10           ((T_Reg32 *) 0xF000082C)->bit10
#define MSC0_ESR_ENL11           ((T_Reg32 *) 0xF000082C)->bit11
#define MSC0_ESR_ENL12           ((T_Reg32 *) 0xF000082C)->bit12
#define MSC0_ESR_ENL13           ((T_Reg32 *) 0xF000082C)->bit13
#define MSC0_ESR_ENL14           ((T_Reg32 *) 0xF000082C)->bit14
#define MSC0_ESR_ENL15           ((T_Reg32 *) 0xF000082C)->bit15
#define MSC0_ESR_ENL2            ((T_Reg32 *) 0xF000082C)->bit2
#define MSC0_ESR_ENL3            ((T_Reg32 *) 0xF000082C)->bit3
#define MSC0_ESR_ENL4            ((T_Reg32 *) 0xF000082C)->bit4
#define MSC0_ESR_ENL5            ((T_Reg32 *) 0xF000082C)->bit5
#define MSC0_ESR_ENL6            ((T_Reg32 *) 0xF000082C)->bit6
#define MSC0_ESR_ENL7            ((T_Reg32 *) 0xF000082C)->bit7
#define MSC0_ESR_ENL8            ((T_Reg32 *) 0xF000082C)->bit8
#define MSC0_ESR_ENL9            ((T_Reg32 *) 0xF000082C)->bit9

// MSC0 Fractional Divider Register
#define MSC0_FDR               (*((uword volatile *) 0xF000080C))
#define MSC0_FDR_DISCLK          ((T_Reg32 *) 0xF000080C)->bit31
#define MSC0_FDR_ENHW            ((T_Reg32 *) 0xF000080C)->bit30
#define MSC0_FDR_SM              ((T_Reg32 *) 0xF000080C)->bit11
#define MSC0_FDR_SUSACK          ((T_Reg32 *) 0xF000080C)->bit28
#define MSC0_FDR_SUSREQ          ((T_Reg32 *) 0xF000080C)->bit29

// MSC0 Interrupt Control Register
#define MSC0_ICR               (*((uword volatile *) 0xF0000840))
#define MSC0_ICR_ECIE            ((T_Reg32 *) 0xF0000840)->bit7
#define MSC0_ICR_TFIE            ((T_Reg32 *) 0xF0000840)->bit11

// MSC0 Module Identification Register
#define MSC0_ID                (*((uword volatile *) 0xF0000808))

// MSC0 Interrupt Set Clear Register
#define MSC0_ISC               (*((uword volatile *) 0xF0000848))
#define MSC0_ISC_CCP             ((T_Reg32 *) 0xF0000848)->bit5
#define MSC0_ISC_CDDIS           ((T_Reg32 *) 0xF0000848)->bit6
#define MSC0_ISC_CDECI           ((T_Reg32 *) 0xF0000848)->bit1
#define MSC0_ISC_CDEDI           ((T_Reg32 *) 0xF0000848)->bit0
#define MSC0_ISC_CDP             ((T_Reg32 *) 0xF0000848)->bit4
#define MSC0_ISC_CDTFI           ((T_Reg32 *) 0xF0000848)->bit2
#define MSC0_ISC_CURDI           ((T_Reg32 *) 0xF0000848)->bit3
#define MSC0_ISC_SCP             ((T_Reg32 *) 0xF0000848)->bit21
#define MSC0_ISC_SDDIS           ((T_Reg32 *) 0xF0000848)->bit22
#define MSC0_ISC_SDECI           ((T_Reg32 *) 0xF0000848)->bit17
#define MSC0_ISC_SDEDI           ((T_Reg32 *) 0xF0000848)->bit16
#define MSC0_ISC_SDP             ((T_Reg32 *) 0xF0000848)->bit20
#define MSC0_ISC_SDTFI           ((T_Reg32 *) 0xF0000848)->bit18
#define MSC0_ISC_SURDI           ((T_Reg32 *) 0xF0000848)->bit19

// MSC0 Interrupt Status Register
#define MSC0_ISR               (*((uword volatile *) 0xF0000844))
#define MSC0_ISR_DECI            ((T_Reg32 *) 0xF0000844)->bit1
#define MSC0_ISR_DEDI            ((T_Reg32 *) 0xF0000844)->bit0
#define MSC0_ISR_DTFI            ((T_Reg32 *) 0xF0000844)->bit2
#define MSC0_ISR_URDI            ((T_Reg32 *) 0xF0000844)->bit3

// MSC0 Output Control Register
#define MSC0_OCR               (*((uword volatile *) 0xF000084C))
#define MSC0_OCR_CLKCTRL         ((T_Reg32 *) 0xF000084C)->bit8
#define MSC0_OCR_CLP             ((T_Reg32 *) 0xF000084C)->bit0
#define MSC0_OCR_CSLP            ((T_Reg32 *) 0xF000084C)->bit2
#define MSC0_OCR_ILP             ((T_Reg32 *) 0xF000084C)->bit3
#define MSC0_OCR_SLP             ((T_Reg32 *) 0xF000084C)->bit1

// MSC0 Service Request Control Register 0
#define MSC0_SRC0              (*((uword volatile *) 0xF00008FC))
#define MSC0_SRC0_CLRR           ((T_Reg32 *) 0xF00008FC)->bit14
#define MSC0_SRC0_SETR           ((T_Reg32 *) 0xF00008FC)->bit15
#define MSC0_SRC0_SRE            ((T_Reg32 *) 0xF00008FC)->bit12
#define MSC0_SRC0_SRR            ((T_Reg32 *) 0xF00008FC)->bit13
#define MSC0_SRC0_TOS            ((T_Reg32 *) 0xF00008FC)->bit10

// MSC0 Service Request Control Register 1
#define MSC0_SRC1              (*((uword volatile *) 0xF00008F8))
#define MSC0_SRC1_CLRR           ((T_Reg32 *) 0xF00008F8)->bit14
#define MSC0_SRC1_SETR           ((T_Reg32 *) 0xF00008F8)->bit15
#define MSC0_SRC1_SRE            ((T_Reg32 *) 0xF00008F8)->bit12
#define MSC0_SRC1_SRR            ((T_Reg32 *) 0xF00008F8)->bit13
#define MSC0_SRC1_TOS            ((T_Reg32 *) 0xF00008F8)->bit10

// MSC0 Upstream Data Register 0
#define MSC0_UD0               (*((uword volatile *) 0xF0000830))
#define MSC0_UD0_C               ((T_Reg32 *) 0xF0000830)->bit18
#define MSC0_UD0_IPF             ((T_Reg32 *) 0xF0000830)->bit21
#define MSC0_UD0_P               ((T_Reg32 *) 0xF0000830)->bit17
#define MSC0_UD0_PERR            ((T_Reg32 *) 0xF0000830)->bit22
#define MSC0_UD0_V               ((T_Reg32 *) 0xF0000830)->bit16

// MSC0 Upstream Data Register 1
#define MSC0_UD1               (*((uword volatile *) 0xF0000834))
#define MSC0_UD1_C               ((T_Reg32 *) 0xF0000834)->bit18
#define MSC0_UD1_IPF             ((T_Reg32 *) 0xF0000834)->bit21
#define MSC0_UD1_P               ((T_Reg32 *) 0xF0000834)->bit17
#define MSC0_UD1_PERR            ((T_Reg32 *) 0xF0000834)->bit22
#define MSC0_UD1_V               ((T_Reg32 *) 0xF0000834)->bit16

// MSC0 Upstream Data Register 2
#define MSC0_UD2               (*((uword volatile *) 0xF0000838))
#define MSC0_UD2_C               ((T_Reg32 *) 0xF0000838)->bit18
#define MSC0_UD2_IPF             ((T_Reg32 *) 0xF0000838)->bit21
#define MSC0_UD2_P               ((T_Reg32 *) 0xF0000838)->bit17
#define MSC0_UD2_PERR            ((T_Reg32 *) 0xF0000838)->bit22
#define MSC0_UD2_V               ((T_Reg32 *) 0xF0000838)->bit16

// MSC0 Upstream Data Register 3
#define MSC0_UD3               (*((uword volatile *) 0xF000083C))
#define MSC0_UD3_C               ((T_Reg32 *) 0xF000083C)->bit18
#define MSC0_UD3_IPF             ((T_Reg32 *) 0xF000083C)->bit21
#define MSC0_UD3_P               ((T_Reg32 *) 0xF000083C)->bit17
#define MSC0_UD3_PERR            ((T_Reg32 *) 0xF000083C)->bit22
#define MSC0_UD3_V               ((T_Reg32 *) 0xF000083C)->bit16

// MSC0 Upstream Status Register
#define MSC0_USR               (*((uword volatile *) 0xF0000810))
#define MSC0_USR_PCTR            ((T_Reg32 *) 0xF0000810)->bit4
#define MSC0_USR_UFT             ((T_Reg32 *) 0xF0000810)->bit0

// Overlay Control Register
#define OVC_OCON               (*((uword volatile *) 0xF87FFBE0))
#define OVC_OCON_DCINVAL         0x00040000
#define OVC_OCON_OVCONF          0x01000000
#define OVC_OCON_OVSTP           0x00020000
#define OVC_OCON_OVSTRT          0x00010000
#define OVC_OCON_POVCONF         0x02000000
#define OVC_OCON_SHOVEN0         0x00000001
#define OVC_OCON_SHOVEN1         0x00000002
#define OVC_OCON_SHOVEN10        0x00000400
#define OVC_OCON_SHOVEN11        0x00000800
#define OVC_OCON_SHOVEN12        0x00001000
#define OVC_OCON_SHOVEN13        0x00002000
#define OVC_OCON_SHOVEN14        0x00004000
#define OVC_OCON_SHOVEN15        0x00008000
#define OVC_OCON_SHOVEN2         0x00000004
#define OVC_OCON_SHOVEN3         0x00000008
#define OVC_OCON_SHOVEN4         0x00000010
#define OVC_OCON_SHOVEN5         0x00000020
#define OVC_OCON_SHOVEN6         0x00000040
#define OVC_OCON_SHOVEN7         0x00000080
#define OVC_OCON_SHOVEN8         0x00000100
#define OVC_OCON_SHOVEN9         0x00000200

// Overlay Mask Register 0
#define OVC_OMASK0             (*((uword volatile *) 0xF87FFB28))

// Overlay Mask Register 0
#define OVC_OMASK0             (*((uword volatile *) 0xF87FFB28))

// Overlay Mask Register 1
#define OVC_OMASK1             (*((uword volatile *) 0xF87FFB34))

// Overlay Mask Register 1
#define OVC_OMASK1             (*((uword volatile *) 0xF87FFB34))

// Overlay Mask Register 10
#define OVC_OMASK10            (*((uword volatile *) 0xF87FFBA0))

// Overlay Mask Register 10
#define OVC_OMASK10            (*((uword volatile *) 0xF87FFBA0))

// Overlay Mask Register 11
#define OVC_OMASK11            (*((uword volatile *) 0xF87FFBAC))

// Overlay Mask Register 11
#define OVC_OMASK11            (*((uword volatile *) 0xF87FFBAC))

// Overlay Mask Register 12
#define OVC_OMASK12            (*((uword volatile *) 0xF87FFBB8))

// Overlay Mask Register 12
#define OVC_OMASK12            (*((uword volatile *) 0xF87FFBB8))

// Overlay Mask Register 13
#define OVC_OMASK13            (*((uword volatile *) 0xF87FFBC4))

// Overlay Mask Register 13
#define OVC_OMASK13            (*((uword volatile *) 0xF87FFBC4))

// Overlay Mask Register 14
#define OVC_OMASK14            (*((uword volatile *) 0xF87FFBD0))

// Overlay Mask Register 14
#define OVC_OMASK14            (*((uword volatile *) 0xF87FFBD0))

// Overlay Mask Register 15
#define OVC_OMASK15            (*((uword volatile *) 0xF87FFBDC))

// Overlay Mask Register 15
#define OVC_OMASK15            (*((uword volatile *) 0xF87FFBDC))

// Overlay Mask Register 2
#define OVC_OMASK2             (*((uword volatile *) 0xF87FFB40))

// Overlay Mask Register 2
#define OVC_OMASK2             (*((uword volatile *) 0xF87FFB40))

// Overlay Mask Register 3
#define OVC_OMASK3             (*((uword volatile *) 0xF87FFB4C))

// Overlay Mask Register 3
#define OVC_OMASK3             (*((uword volatile *) 0xF87FFB4C))

// Overlay Mask Register 4
#define OVC_OMASK4             (*((uword volatile *) 0xF87FFB58))

// Overlay Mask Register 4
#define OVC_OMASK4             (*((uword volatile *) 0xF87FFB58))

// Overlay Mask Register 5
#define OVC_OMASK5             (*((uword volatile *) 0xF87FFB64))

// Overlay Mask Register 5
#define OVC_OMASK5             (*((uword volatile *) 0xF87FFB64))

// Overlay Mask Register 6
#define OVC_OMASK6             (*((uword volatile *) 0xF87FFB70))

// Overlay Mask Register 6
#define OVC_OMASK6             (*((uword volatile *) 0xF87FFB70))

// Overlay Mask Register 7
#define OVC_OMASK7             (*((uword volatile *) 0xF87FFB7C))

// Overlay Mask Register 7
#define OVC_OMASK7             (*((uword volatile *) 0xF87FFB7C))

// Overlay Mask Register 8
#define OVC_OMASK8             (*((uword volatile *) 0xF87FFB88))

// Overlay Mask Register 8
#define OVC_OMASK8             (*((uword volatile *) 0xF87FFB88))

// Overlay Mask Register 9
#define OVC_OMASK9             (*((uword volatile *) 0xF87FFB94))

// Overlay Mask Register 9
#define OVC_OMASK9             (*((uword volatile *) 0xF87FFB94))

// Overlay Target Address Register 0
#define OVC_OTAR0              (*((uword volatile *) 0xF87FFB24))

// Overlay Target Address Register 0
#define OVC_OTAR0              (*((uword volatile *) 0xF87FFB24))

// Overlay Target Address Register 1
#define OVC_OTAR1              (*((uword volatile *) 0xF87FFB30))

// Overlay Target Address Register 1
#define OVC_OTAR1              (*((uword volatile *) 0xF87FFB30))

// Overlay Target Address Register 10
#define OVC_OTAR10             (*((uword volatile *) 0xF87FFB9C))

// Overlay Target Address Register 10
#define OVC_OTAR10             (*((uword volatile *) 0xF87FFB9C))

// Overlay Target Address Register 11
#define OVC_OTAR11             (*((uword volatile *) 0xF87FFBA8))

// Overlay Target Address Register 11
#define OVC_OTAR11             (*((uword volatile *) 0xF87FFBA8))

// Overlay Target Address Register 12
#define OVC_OTAR12             (*((uword volatile *) 0xF87FFBB4))

// Overlay Target Address Register 12
#define OVC_OTAR12             (*((uword volatile *) 0xF87FFBB4))

// Overlay Target Address Register 13
#define OVC_OTAR13             (*((uword volatile *) 0xF87FFBC0))

// Overlay Target Address Register 13
#define OVC_OTAR13             (*((uword volatile *) 0xF87FFBC0))

// Overlay Target Address Register 14
#define OVC_OTAR14             (*((uword volatile *) 0xF87FFBCC))

// Overlay Target Address Register 14
#define OVC_OTAR14             (*((uword volatile *) 0xF87FFBCC))

// Overlay Target Address Register 15
#define OVC_OTAR15             (*((uword volatile *) 0xF87FFBD8))

// Overlay Target Address Register 15
#define OVC_OTAR15             (*((uword volatile *) 0xF87FFBD8))

// Overlay Target Address Register 2
#define OVC_OTAR2              (*((uword volatile *) 0xF87FFB3C))

// Overlay Target Address Register 2
#define OVC_OTAR2              (*((uword volatile *) 0xF87FFB3C))

// Overlay Target Address Register 3
#define OVC_OTAR3              (*((uword volatile *) 0xF87FFB48))

// Overlay Target Address Register 3
#define OVC_OTAR3              (*((uword volatile *) 0xF87FFB48))

// Overlay Target Address Register 4
#define OVC_OTAR4              (*((uword volatile *) 0xF87FFB54))

// Overlay Target Address Register 4
#define OVC_OTAR4              (*((uword volatile *) 0xF87FFB54))

// Overlay Target Address Register 5
#define OVC_OTAR5              (*((uword volatile *) 0xF87FFB60))

// Overlay Target Address Register 5
#define OVC_OTAR5              (*((uword volatile *) 0xF87FFB60))

// Overlay Target Address Register 6
#define OVC_OTAR6              (*((uword volatile *) 0xF87FFB6C))

// Overlay Target Address Register 6
#define OVC_OTAR6              (*((uword volatile *) 0xF87FFB6C))

// Overlay Target Address Register 7
#define OVC_OTAR7              (*((uword volatile *) 0xF87FFB78))

// Overlay Target Address Register 7
#define OVC_OTAR7              (*((uword volatile *) 0xF87FFB78))

// Overlay Target Address Register 8
#define OVC_OTAR8              (*((uword volatile *) 0xF87FFB84))

// Overlay Target Address Register 8
#define OVC_OTAR8              (*((uword volatile *) 0xF87FFB84))

// Overlay Target Address Register 9
#define OVC_OTAR9              (*((uword volatile *) 0xF87FFB90))

// Overlay Target Address Register 9
#define OVC_OTAR9              (*((uword volatile *) 0xF87FFB90))

// Redirected Address Base Register 0
#define OVC_RABR0              (*((uword volatile *) 0xF87FFB20))

// Redirected Address Base Register 0
#define OVC_RABR0              (*((uword volatile *) 0xF87FFB20))

// Redirected Address Base Register 0
#define OVC_RABR0              (*((uword volatile *) 0xF87FFB20))
#define OVC_RABR0_EXOMS          0x20000000
#define OVC_RABR0_EXOMS          0x20000000
#define OVC_RABR0_EXOMS          0x20000000
#define OVC_RABR0_IEMS           0x40000000
#define OVC_RABR0_IEMS           0x40000000
#define OVC_RABR0_IEMS           0x40000000
#define OVC_RABR0_OVEN           0x80000000
#define OVC_RABR0_OVEN           0x80000000
#define OVC_RABR0_OVEN           0x80000000
#define OVC_RABR0_RC0            0x10000000
#define OVC_RABR0_RC0            0x10000000
#define OVC_RABR0_RC0            0x10000000

// Redirected Address Base Register 1
#define OVC_RABR1              (*((uword volatile *) 0xF87FFB2C))

// Redirected Address Base Register 1
#define OVC_RABR1              (*((uword volatile *) 0xF87FFB2C))
#define OVC_RABR1_EXOMS          0x20000000
#define OVC_RABR1_EXOMS          0x20000000
#define OVC_RABR1_EXOMS          0x20000000
#define OVC_RABR1_IEMS           0x40000000
#define OVC_RABR1_IEMS           0x40000000
#define OVC_RABR1_IEMS           0x40000000
#define OVC_RABR1_OVEN           0x80000000
#define OVC_RABR1_OVEN           0x80000000
#define OVC_RABR1_OVEN           0x80000000
#define OVC_RABR1_RC0            0x10000000
#define OVC_RABR1_RC0            0x10000000
#define OVC_RABR1_RC0            0x10000000

// Redirected Address Base Register 1
#define OVC_RABR1              (*((uword volatile *) 0xF87FFB2C))

// Redirected Address Base Register 10
#define OVC_RABR10             (*((uword volatile *) 0xF87FFB98))
#define OVC_RABR10_EXOMS         0x20000000
#define OVC_RABR10_EXOMS         0x20000000
#define OVC_RABR10_EXOMS         0x20000000
#define OVC_RABR10_IEMS          0x40000000
#define OVC_RABR10_IEMS          0x40000000
#define OVC_RABR10_IEMS          0x40000000
#define OVC_RABR10_OVEN          0x80000000
#define OVC_RABR10_OVEN          0x80000000
#define OVC_RABR10_OVEN          0x80000000
#define OVC_RABR10_RC0           0x10000000
#define OVC_RABR10_RC0           0x10000000
#define OVC_RABR10_RC0           0x10000000

// Redirected Address Base Register 10
#define OVC_RABR10             (*((uword volatile *) 0xF87FFB98))

// Redirected Address Base Register 10
#define OVC_RABR10             (*((uword volatile *) 0xF87FFB98))

// Redirected Address Base Register 11
#define OVC_RABR11             (*((uword volatile *) 0xF87FFBA4))

// Redirected Address Base Register 11
#define OVC_RABR11             (*((uword volatile *) 0xF87FFBA4))
#define OVC_RABR11_EXOMS         0x20000000
#define OVC_RABR11_EXOMS         0x20000000
#define OVC_RABR11_EXOMS         0x20000000
#define OVC_RABR11_IEMS          0x40000000
#define OVC_RABR11_IEMS          0x40000000
#define OVC_RABR11_IEMS          0x40000000
#define OVC_RABR11_OVEN          0x80000000
#define OVC_RABR11_OVEN          0x80000000
#define OVC_RABR11_OVEN          0x80000000
#define OVC_RABR11_RC0           0x10000000
#define OVC_RABR11_RC0           0x10000000
#define OVC_RABR11_RC0           0x10000000

// Redirected Address Base Register 11
#define OVC_RABR11             (*((uword volatile *) 0xF87FFBA4))

// Redirected Address Base Register 12
#define OVC_RABR12             (*((uword volatile *) 0xF87FFBB0))

// Redirected Address Base Register 12
#define OVC_RABR12             (*((uword volatile *) 0xF87FFBB0))

// Redirected Address Base Register 12
#define OVC_RABR12             (*((uword volatile *) 0xF87FFBB0))
#define OVC_RABR12_EXOMS         0x20000000
#define OVC_RABR12_EXOMS         0x20000000
#define OVC_RABR12_EXOMS         0x20000000
#define OVC_RABR12_IEMS          0x40000000
#define OVC_RABR12_IEMS          0x40000000
#define OVC_RABR12_IEMS          0x40000000
#define OVC_RABR12_OVEN          0x80000000
#define OVC_RABR12_OVEN          0x80000000
#define OVC_RABR12_OVEN          0x80000000
#define OVC_RABR12_RC0           0x10000000
#define OVC_RABR12_RC0           0x10000000
#define OVC_RABR12_RC0           0x10000000

// Redirected Address Base Register 13
#define OVC_RABR13             (*((uword volatile *) 0xF87FFBBC))

// Redirected Address Base Register 13
#define OVC_RABR13             (*((uword volatile *) 0xF87FFBBC))
#define OVC_RABR13_EXOMS         0x20000000
#define OVC_RABR13_EXOMS         0x20000000
#define OVC_RABR13_EXOMS         0x20000000
#define OVC_RABR13_IEMS          0x40000000
#define OVC_RABR13_IEMS          0x40000000
#define OVC_RABR13_IEMS          0x40000000
#define OVC_RABR13_OVEN          0x80000000
#define OVC_RABR13_OVEN          0x80000000
#define OVC_RABR13_OVEN          0x80000000
#define OVC_RABR13_RC0           0x10000000
#define OVC_RABR13_RC0           0x10000000
#define OVC_RABR13_RC0           0x10000000

// Redirected Address Base Register 13
#define OVC_RABR13             (*((uword volatile *) 0xF87FFBBC))

// Redirected Address Base Register 14
#define OVC_RABR14             (*((uword volatile *) 0xF87FFBC8))
#define OVC_RABR14_EXOMS         0x20000000
#define OVC_RABR14_EXOMS         0x20000000
#define OVC_RABR14_EXOMS         0x20000000
#define OVC_RABR14_IEMS          0x40000000
#define OVC_RABR14_IEMS          0x40000000
#define OVC_RABR14_IEMS          0x40000000
#define OVC_RABR14_OVEN          0x80000000
#define OVC_RABR14_OVEN          0x80000000
#define OVC_RABR14_OVEN          0x80000000
#define OVC_RABR14_RC0           0x10000000
#define OVC_RABR14_RC0           0x10000000
#define OVC_RABR14_RC0           0x10000000

// Redirected Address Base Register 14
#define OVC_RABR14             (*((uword volatile *) 0xF87FFBC8))

// Redirected Address Base Register 14
#define OVC_RABR14             (*((uword volatile *) 0xF87FFBC8))

// Redirected Address Base Register 15
#define OVC_RABR15             (*((uword volatile *) 0xF87FFBD4))

// Redirected Address Base Register 15
#define OVC_RABR15             (*((uword volatile *) 0xF87FFBD4))
#define OVC_RABR15_EXOMS         0x20000000
#define OVC_RABR15_EXOMS         0x20000000
#define OVC_RABR15_EXOMS         0x20000000
#define OVC_RABR15_IEMS          0x40000000
#define OVC_RABR15_IEMS          0x40000000
#define OVC_RABR15_IEMS          0x40000000
#define OVC_RABR15_OVEN          0x80000000
#define OVC_RABR15_OVEN          0x80000000
#define OVC_RABR15_OVEN          0x80000000
#define OVC_RABR15_RC0           0x10000000
#define OVC_RABR15_RC0           0x10000000
#define OVC_RABR15_RC0           0x10000000

// Redirected Address Base Register 15
#define OVC_RABR15             (*((uword volatile *) 0xF87FFBD4))

// Redirected Address Base Register 2
#define OVC_RABR2              (*((uword volatile *) 0xF87FFB38))

// Redirected Address Base Register 2
#define OVC_RABR2              (*((uword volatile *) 0xF87FFB38))

// Redirected Address Base Register 2
#define OVC_RABR2              (*((uword volatile *) 0xF87FFB38))
#define OVC_RABR2_EXOMS          0x20000000
#define OVC_RABR2_EXOMS          0x20000000
#define OVC_RABR2_EXOMS          0x20000000
#define OVC_RABR2_IEMS           0x40000000
#define OVC_RABR2_IEMS           0x40000000
#define OVC_RABR2_IEMS           0x40000000
#define OVC_RABR2_OVEN           0x80000000
#define OVC_RABR2_OVEN           0x80000000
#define OVC_RABR2_OVEN           0x80000000
#define OVC_RABR2_RC0            0x10000000
#define OVC_RABR2_RC0            0x10000000
#define OVC_RABR2_RC0            0x10000000

// Redirected Address Base Register 3
#define OVC_RABR3              (*((uword volatile *) 0xF87FFB44))

// Redirected Address Base Register 3
#define OVC_RABR3              (*((uword volatile *) 0xF87FFB44))
#define OVC_RABR3_EXOMS          0x20000000
#define OVC_RABR3_EXOMS          0x20000000
#define OVC_RABR3_EXOMS          0x20000000
#define OVC_RABR3_IEMS           0x40000000
#define OVC_RABR3_IEMS           0x40000000
#define OVC_RABR3_IEMS           0x40000000
#define OVC_RABR3_OVEN           0x80000000
#define OVC_RABR3_OVEN           0x80000000
#define OVC_RABR3_OVEN           0x80000000
#define OVC_RABR3_RC0            0x10000000
#define OVC_RABR3_RC0            0x10000000
#define OVC_RABR3_RC0            0x10000000

// Redirected Address Base Register 3
#define OVC_RABR3              (*((uword volatile *) 0xF87FFB44))

// Redirected Address Base Register 4
#define OVC_RABR4              (*((uword volatile *) 0xF87FFB50))
#define OVC_RABR4_EXOMS          0x20000000
#define OVC_RABR4_EXOMS          0x20000000
#define OVC_RABR4_EXOMS          0x20000000
#define OVC_RABR4_IEMS           0x40000000
#define OVC_RABR4_IEMS           0x40000000
#define OVC_RABR4_IEMS           0x40000000
#define OVC_RABR4_OVEN           0x80000000
#define OVC_RABR4_OVEN           0x80000000
#define OVC_RABR4_OVEN           0x80000000
#define OVC_RABR4_RC0            0x10000000
#define OVC_RABR4_RC0            0x10000000
#define OVC_RABR4_RC0            0x10000000

// Redirected Address Base Register 4
#define OVC_RABR4              (*((uword volatile *) 0xF87FFB50))

// Redirected Address Base Register 4
#define OVC_RABR4              (*((uword volatile *) 0xF87FFB50))

// Redirected Address Base Register 5
#define OVC_RABR5              (*((uword volatile *) 0xF87FFB5C))
#define OVC_RABR5_EXOMS          0x20000000
#define OVC_RABR5_EXOMS          0x20000000
#define OVC_RABR5_EXOMS          0x20000000
#define OVC_RABR5_IEMS           0x40000000
#define OVC_RABR5_IEMS           0x40000000
#define OVC_RABR5_IEMS           0x40000000
#define OVC_RABR5_OVEN           0x80000000
#define OVC_RABR5_OVEN           0x80000000
#define OVC_RABR5_OVEN           0x80000000
#define OVC_RABR5_RC0            0x10000000
#define OVC_RABR5_RC0            0x10000000
#define OVC_RABR5_RC0            0x10000000

// Redirected Address Base Register 5
#define OVC_RABR5              (*((uword volatile *) 0xF87FFB5C))

// Redirected Address Base Register 5
#define OVC_RABR5              (*((uword volatile *) 0xF87FFB5C))

// Redirected Address Base Register 6
#define OVC_RABR6              (*((uword volatile *) 0xF87FFB68))

// Redirected Address Base Register 6
#define OVC_RABR6              (*((uword volatile *) 0xF87FFB68))
#define OVC_RABR6_EXOMS          0x20000000
#define OVC_RABR6_EXOMS          0x20000000
#define OVC_RABR6_EXOMS          0x20000000
#define OVC_RABR6_IEMS           0x40000000
#define OVC_RABR6_IEMS           0x40000000
#define OVC_RABR6_IEMS           0x40000000
#define OVC_RABR6_OVEN           0x80000000
#define OVC_RABR6_OVEN           0x80000000
#define OVC_RABR6_OVEN           0x80000000
#define OVC_RABR6_RC0            0x10000000
#define OVC_RABR6_RC0            0x10000000
#define OVC_RABR6_RC0            0x10000000

// Redirected Address Base Register 6
#define OVC_RABR6              (*((uword volatile *) 0xF87FFB68))

// Redirected Address Base Register 7
#define OVC_RABR7              (*((uword volatile *) 0xF87FFB74))

// Redirected Address Base Register 7
#define OVC_RABR7              (*((uword volatile *) 0xF87FFB74))

// Redirected Address Base Register 7
#define OVC_RABR7              (*((uword volatile *) 0xF87FFB74))
#define OVC_RABR7_EXOMS          0x20000000
#define OVC_RABR7_EXOMS          0x20000000
#define OVC_RABR7_EXOMS          0x20000000
#define OVC_RABR7_IEMS           0x40000000
#define OVC_RABR7_IEMS           0x40000000
#define OVC_RABR7_IEMS           0x40000000
#define OVC_RABR7_OVEN           0x80000000
#define OVC_RABR7_OVEN           0x80000000
#define OVC_RABR7_OVEN           0x80000000
#define OVC_RABR7_RC0            0x10000000
#define OVC_RABR7_RC0            0x10000000
#define OVC_RABR7_RC0            0x10000000

// Redirected Address Base Register 8
#define OVC_RABR8              (*((uword volatile *) 0xF87FFB80))

// Redirected Address Base Register 8
#define OVC_RABR8              (*((uword volatile *) 0xF87FFB80))
#define OVC_RABR8_EXOMS          0x20000000
#define OVC_RABR8_EXOMS          0x20000000
#define OVC_RABR8_EXOMS          0x20000000
#define OVC_RABR8_IEMS           0x40000000
#define OVC_RABR8_IEMS           0x40000000
#define OVC_RABR8_IEMS           0x40000000
#define OVC_RABR8_OVEN           0x80000000
#define OVC_RABR8_OVEN           0x80000000
#define OVC_RABR8_OVEN           0x80000000
#define OVC_RABR8_RC0            0x10000000
#define OVC_RABR8_RC0            0x10000000
#define OVC_RABR8_RC0            0x10000000

// Redirected Address Base Register 8
#define OVC_RABR8              (*((uword volatile *) 0xF87FFB80))

// Redirected Address Base Register 9
#define OVC_RABR9              (*((uword volatile *) 0xF87FFB8C))
#define OVC_RABR9_EXOMS          0x20000000
#define OVC_RABR9_EXOMS          0x20000000
#define OVC_RABR9_EXOMS          0x20000000
#define OVC_RABR9_IEMS           0x40000000
#define OVC_RABR9_IEMS           0x40000000
#define OVC_RABR9_IEMS           0x40000000
#define OVC_RABR9_OVEN           0x80000000
#define OVC_RABR9_OVEN           0x80000000
#define OVC_RABR9_OVEN           0x80000000
#define OVC_RABR9_RC0            0x10000000
#define OVC_RABR9_RC0            0x10000000
#define OVC_RABR9_RC0            0x10000000

// Redirected Address Base Register 9
#define OVC_RABR9              (*((uword volatile *) 0xF87FFB8C))

// Redirected Address Base Register 9
#define OVC_RABR9              (*((uword volatile *) 0xF87FFB8C))

// Port 0 Emergency Stop Register
#define P0_ESR                 (*((uword volatile *) 0xF0000C50))
#define P0_ESR_EN0               ((T_Reg32 *) 0xF0000C50)->bit0
#define P0_ESR_EN1               ((T_Reg32 *) 0xF0000C50)->bit1
#define P0_ESR_EN10              ((T_Reg32 *) 0xF0000C50)->bit10
#define P0_ESR_EN11              ((T_Reg32 *) 0xF0000C50)->bit11
#define P0_ESR_EN12              ((T_Reg32 *) 0xF0000C50)->bit12
#define P0_ESR_EN13              ((T_Reg32 *) 0xF0000C50)->bit13
#define P0_ESR_EN14              ((T_Reg32 *) 0xF0000C50)->bit14
#define P0_ESR_EN15              ((T_Reg32 *) 0xF0000C50)->bit15
#define P0_ESR_EN2               ((T_Reg32 *) 0xF0000C50)->bit2
#define P0_ESR_EN3               ((T_Reg32 *) 0xF0000C50)->bit3
#define P0_ESR_EN4               ((T_Reg32 *) 0xF0000C50)->bit4
#define P0_ESR_EN5               ((T_Reg32 *) 0xF0000C50)->bit5
#define P0_ESR_EN6               ((T_Reg32 *) 0xF0000C50)->bit6
#define P0_ESR_EN7               ((T_Reg32 *) 0xF0000C50)->bit7
#define P0_ESR_EN8               ((T_Reg32 *) 0xF0000C50)->bit8
#define P0_ESR_EN9               ((T_Reg32 *) 0xF0000C50)->bit9

// Port 0 Input Register
#define P0_IN                  (*((uword volatile *) 0xF0000C24))
#define P0_IN_P0                 ((T_Reg32 *) 0xF0000C24)->bit0
#define P0_IN_P1                 ((T_Reg32 *) 0xF0000C24)->bit1
#define P0_IN_P10                ((T_Reg32 *) 0xF0000C24)->bit10
#define P0_IN_P11                ((T_Reg32 *) 0xF0000C24)->bit11
#define P0_IN_P12                ((T_Reg32 *) 0xF0000C24)->bit12
#define P0_IN_P13                ((T_Reg32 *) 0xF0000C24)->bit13
#define P0_IN_P14                ((T_Reg32 *) 0xF0000C24)->bit14
#define P0_IN_P15                ((T_Reg32 *) 0xF0000C24)->bit15
#define P0_IN_P2                 ((T_Reg32 *) 0xF0000C24)->bit2
#define P0_IN_P3                 ((T_Reg32 *) 0xF0000C24)->bit3
#define P0_IN_P4                 ((T_Reg32 *) 0xF0000C24)->bit4
#define P0_IN_P5                 ((T_Reg32 *) 0xF0000C24)->bit5
#define P0_IN_P6                 ((T_Reg32 *) 0xF0000C24)->bit6
#define P0_IN_P7                 ((T_Reg32 *) 0xF0000C24)->bit7
#define P0_IN_P8                 ((T_Reg32 *) 0xF0000C24)->bit8
#define P0_IN_P9                 ((T_Reg32 *) 0xF0000C24)->bit9

// Port 0 Input/Output Control Register 0
#define P0_IOCR0               (*((uword volatile *) 0xF0000C10))

// Port 0 Input/Output Control Register 12
#define P0_IOCR12              (*((uword volatile *) 0xF0000C1C))

// Port 0 Input/Output Control Register 4
#define P0_IOCR4               (*((uword volatile *) 0xF0000C14))

// Port 0 Input/Output Control Register 8
#define P0_IOCR8               (*((uword volatile *) 0xF0000C18))

// Port 0 Output Modification Register
#define P0_OMR                 (*((uword volatile *) 0xF0000C04))
#define P0_OMR_PR0               ((T_Reg32 *) 0xF0000C04)->bit16
#define P0_OMR_PR1               ((T_Reg32 *) 0xF0000C04)->bit17
#define P0_OMR_PR10              ((T_Reg32 *) 0xF0000C04)->bit26
#define P0_OMR_PR11              ((T_Reg32 *) 0xF0000C04)->bit27
#define P0_OMR_PR12              ((T_Reg32 *) 0xF0000C04)->bit28
#define P0_OMR_PR13              ((T_Reg32 *) 0xF0000C04)->bit29
#define P0_OMR_PR14              ((T_Reg32 *) 0xF0000C04)->bit30
#define P0_OMR_PR15              ((T_Reg32 *) 0xF0000C04)->bit31
#define P0_OMR_PR2               ((T_Reg32 *) 0xF0000C04)->bit18
#define P0_OMR_PR3               ((T_Reg32 *) 0xF0000C04)->bit19
#define P0_OMR_PR4               ((T_Reg32 *) 0xF0000C04)->bit20
#define P0_OMR_PR5               ((T_Reg32 *) 0xF0000C04)->bit21
#define P0_OMR_PR6               ((T_Reg32 *) 0xF0000C04)->bit22
#define P0_OMR_PR7               ((T_Reg32 *) 0xF0000C04)->bit23
#define P0_OMR_PR8               ((T_Reg32 *) 0xF0000C04)->bit24
#define P0_OMR_PR9               ((T_Reg32 *) 0xF0000C04)->bit25
#define P0_OMR_PS0               ((T_Reg32 *) 0xF0000C04)->bit0
#define P0_OMR_PS1               ((T_Reg32 *) 0xF0000C04)->bit1
#define P0_OMR_PS10              ((T_Reg32 *) 0xF0000C04)->bit10
#define P0_OMR_PS11              ((T_Reg32 *) 0xF0000C04)->bit11
#define P0_OMR_PS12              ((T_Reg32 *) 0xF0000C04)->bit12
#define P0_OMR_PS13              ((T_Reg32 *) 0xF0000C04)->bit13
#define P0_OMR_PS14              ((T_Reg32 *) 0xF0000C04)->bit14
#define P0_OMR_PS15              ((T_Reg32 *) 0xF0000C04)->bit15
#define P0_OMR_PS2               ((T_Reg32 *) 0xF0000C04)->bit2
#define P0_OMR_PS3               ((T_Reg32 *) 0xF0000C04)->bit3
#define P0_OMR_PS4               ((T_Reg32 *) 0xF0000C04)->bit4
#define P0_OMR_PS5               ((T_Reg32 *) 0xF0000C04)->bit5
#define P0_OMR_PS6               ((T_Reg32 *) 0xF0000C04)->bit6
#define P0_OMR_PS7               ((T_Reg32 *) 0xF0000C04)->bit7
#define P0_OMR_PS8               ((T_Reg32 *) 0xF0000C04)->bit8
#define P0_OMR_PS9               ((T_Reg32 *) 0xF0000C04)->bit9

// Port 0 Output Register
#define P0_OUT                 (*((uword volatile *) 0xF0000C00))
#define P0_OUT_P0                ((T_Reg32 *) 0xF0000C00)->bit0
#define P0_OUT_P1                ((T_Reg32 *) 0xF0000C00)->bit1
#define P0_OUT_P10               ((T_Reg32 *) 0xF0000C00)->bit10
#define P0_OUT_P11               ((T_Reg32 *) 0xF0000C00)->bit11
#define P0_OUT_P12               ((T_Reg32 *) 0xF0000C00)->bit12
#define P0_OUT_P13               ((T_Reg32 *) 0xF0000C00)->bit13
#define P0_OUT_P14               ((T_Reg32 *) 0xF0000C00)->bit14
#define P0_OUT_P15               ((T_Reg32 *) 0xF0000C00)->bit15
#define P0_OUT_P2                ((T_Reg32 *) 0xF0000C00)->bit2
#define P0_OUT_P3                ((T_Reg32 *) 0xF0000C00)->bit3
#define P0_OUT_P4                ((T_Reg32 *) 0xF0000C00)->bit4
#define P0_OUT_P5                ((T_Reg32 *) 0xF0000C00)->bit5
#define P0_OUT_P6                ((T_Reg32 *) 0xF0000C00)->bit6
#define P0_OUT_P7                ((T_Reg32 *) 0xF0000C00)->bit7
#define P0_OUT_P8                ((T_Reg32 *) 0xF0000C00)->bit8
#define P0_OUT_P9                ((T_Reg32 *) 0xF0000C00)->bit9

// Port 0 Pad Driver Mode Register
#define P0_PDR                 (*((uword volatile *) 0xF0000C40))

// Port 1 Emergency Stop Register
#define P1_ESR                 (*((uword volatile *) 0xF0000D50))
#define P1_ESR_EN0               ((T_Reg32 *) 0xF0000D50)->bit0
#define P1_ESR_EN1               ((T_Reg32 *) 0xF0000D50)->bit1
#define P1_ESR_EN10              ((T_Reg32 *) 0xF0000D50)->bit10
#define P1_ESR_EN11              ((T_Reg32 *) 0xF0000D50)->bit11
#define P1_ESR_EN12              ((T_Reg32 *) 0xF0000D50)->bit12
#define P1_ESR_EN13              ((T_Reg32 *) 0xF0000D50)->bit13
#define P1_ESR_EN14              ((T_Reg32 *) 0xF0000D50)->bit14
#define P1_ESR_EN15              ((T_Reg32 *) 0xF0000D50)->bit15
#define P1_ESR_EN2               ((T_Reg32 *) 0xF0000D50)->bit2
#define P1_ESR_EN3               ((T_Reg32 *) 0xF0000D50)->bit3
#define P1_ESR_EN4               ((T_Reg32 *) 0xF0000D50)->bit4
#define P1_ESR_EN5               ((T_Reg32 *) 0xF0000D50)->bit5
#define P1_ESR_EN6               ((T_Reg32 *) 0xF0000D50)->bit6
#define P1_ESR_EN7               ((T_Reg32 *) 0xF0000D50)->bit7
#define P1_ESR_EN8               ((T_Reg32 *) 0xF0000D50)->bit8
#define P1_ESR_EN9               ((T_Reg32 *) 0xF0000D50)->bit9

// Port 1 Input Register
#define P1_IN                  (*((uword volatile *) 0xF0000D24))
#define P1_IN_P0                 ((T_Reg32 *) 0xF0000D24)->bit0
#define P1_IN_P1                 ((T_Reg32 *) 0xF0000D24)->bit1
#define P1_IN_P10                ((T_Reg32 *) 0xF0000D24)->bit10
#define P1_IN_P11                ((T_Reg32 *) 0xF0000D24)->bit11
#define P1_IN_P12                ((T_Reg32 *) 0xF0000D24)->bit12
#define P1_IN_P13                ((T_Reg32 *) 0xF0000D24)->bit13
#define P1_IN_P14                ((T_Reg32 *) 0xF0000D24)->bit14
#define P1_IN_P15                ((T_Reg32 *) 0xF0000D24)->bit15
#define P1_IN_P2                 ((T_Reg32 *) 0xF0000D24)->bit2
#define P1_IN_P3                 ((T_Reg32 *) 0xF0000D24)->bit3
#define P1_IN_P4                 ((T_Reg32 *) 0xF0000D24)->bit4
#define P1_IN_P5                 ((T_Reg32 *) 0xF0000D24)->bit5
#define P1_IN_P6                 ((T_Reg32 *) 0xF0000D24)->bit6
#define P1_IN_P7                 ((T_Reg32 *) 0xF0000D24)->bit7
#define P1_IN_P8                 ((T_Reg32 *) 0xF0000D24)->bit8
#define P1_IN_P9                 ((T_Reg32 *) 0xF0000D24)->bit9

// Port 1 Input/Output Control Register 0
#define P1_IOCR0               (*((uword volatile *) 0xF0000D10))

// Port 1 Input/Output Control Register 12
#define P1_IOCR12              (*((uword volatile *) 0xF0000D1C))

// Port 1 Input/Output Control Register 4
#define P1_IOCR4               (*((uword volatile *) 0xF0000D14))

// Port 1 Input/Output Control Register 8
#define P1_IOCR8               (*((uword volatile *) 0xF0000D18))

// Port 1 Output Modification Register
#define P1_OMR                 (*((uword volatile *) 0xF0000D04))
#define P1_OMR_PR0               ((T_Reg32 *) 0xF0000D04)->bit16
#define P1_OMR_PR1               ((T_Reg32 *) 0xF0000D04)->bit17
#define P1_OMR_PR10              ((T_Reg32 *) 0xF0000D04)->bit26
#define P1_OMR_PR11              ((T_Reg32 *) 0xF0000D04)->bit27
#define P1_OMR_PR12              ((T_Reg32 *) 0xF0000D04)->bit28
#define P1_OMR_PR13              ((T_Reg32 *) 0xF0000D04)->bit29
#define P1_OMR_PR14              ((T_Reg32 *) 0xF0000D04)->bit30
#define P1_OMR_PR15              ((T_Reg32 *) 0xF0000D04)->bit31
#define P1_OMR_PR2               ((T_Reg32 *) 0xF0000D04)->bit18
#define P1_OMR_PR3               ((T_Reg32 *) 0xF0000D04)->bit19
#define P1_OMR_PR4               ((T_Reg32 *) 0xF0000D04)->bit20
#define P1_OMR_PR5               ((T_Reg32 *) 0xF0000D04)->bit21
#define P1_OMR_PR6               ((T_Reg32 *) 0xF0000D04)->bit22
#define P1_OMR_PR7               ((T_Reg32 *) 0xF0000D04)->bit23
#define P1_OMR_PR8               ((T_Reg32 *) 0xF0000D04)->bit24
#define P1_OMR_PR9               ((T_Reg32 *) 0xF0000D04)->bit25
#define P1_OMR_PS0               ((T_Reg32 *) 0xF0000D04)->bit0
#define P1_OMR_PS1               ((T_Reg32 *) 0xF0000D04)->bit1
#define P1_OMR_PS10              ((T_Reg32 *) 0xF0000D04)->bit10
#define P1_OMR_PS11              ((T_Reg32 *) 0xF0000D04)->bit11
#define P1_OMR_PS12              ((T_Reg32 *) 0xF0000D04)->bit12
#define P1_OMR_PS13              ((T_Reg32 *) 0xF0000D04)->bit13
#define P1_OMR_PS14              ((T_Reg32 *) 0xF0000D04)->bit14
#define P1_OMR_PS15              ((T_Reg32 *) 0xF0000D04)->bit15
#define P1_OMR_PS2               ((T_Reg32 *) 0xF0000D04)->bit2
#define P1_OMR_PS3               ((T_Reg32 *) 0xF0000D04)->bit3
#define P1_OMR_PS4               ((T_Reg32 *) 0xF0000D04)->bit4
#define P1_OMR_PS5               ((T_Reg32 *) 0xF0000D04)->bit5
#define P1_OMR_PS6               ((T_Reg32 *) 0xF0000D04)->bit6
#define P1_OMR_PS7               ((T_Reg32 *) 0xF0000D04)->bit7
#define P1_OMR_PS8               ((T_Reg32 *) 0xF0000D04)->bit8
#define P1_OMR_PS9               ((T_Reg32 *) 0xF0000D04)->bit9

// Port 1 Output Register
#define P1_OUT                 (*((uword volatile *) 0xF0000D00))
#define P1_OUT_P0                ((T_Reg32 *) 0xF0000D00)->bit0
#define P1_OUT_P1                ((T_Reg32 *) 0xF0000D00)->bit1
#define P1_OUT_P10               ((T_Reg32 *) 0xF0000D00)->bit10
#define P1_OUT_P11               ((T_Reg32 *) 0xF0000D00)->bit11
#define P1_OUT_P12               ((T_Reg32 *) 0xF0000D00)->bit12
#define P1_OUT_P13               ((T_Reg32 *) 0xF0000D00)->bit13
#define P1_OUT_P14               ((T_Reg32 *) 0xF0000D00)->bit14
#define P1_OUT_P15               ((T_Reg32 *) 0xF0000D00)->bit15
#define P1_OUT_P2                ((T_Reg32 *) 0xF0000D00)->bit2
#define P1_OUT_P3                ((T_Reg32 *) 0xF0000D00)->bit3
#define P1_OUT_P4                ((T_Reg32 *) 0xF0000D00)->bit4
#define P1_OUT_P5                ((T_Reg32 *) 0xF0000D00)->bit5
#define P1_OUT_P6                ((T_Reg32 *) 0xF0000D00)->bit6
#define P1_OUT_P7                ((T_Reg32 *) 0xF0000D00)->bit7
#define P1_OUT_P8                ((T_Reg32 *) 0xF0000D00)->bit8
#define P1_OUT_P9                ((T_Reg32 *) 0xF0000D00)->bit9

// Port 1 Pad Driver Mode Register
#define P1_PDR                 (*((uword volatile *) 0xF0000D40))

// Port 2 Emergency Stop Register
#define P2_ESR                 (*((uword volatile *) 0xF0000E50))
#define P2_ESR_EN0               ((T_Reg32 *) 0xF0000E50)->bit0
#define P2_ESR_EN1               ((T_Reg32 *) 0xF0000E50)->bit1
#define P2_ESR_EN10              ((T_Reg32 *) 0xF0000E50)->bit10
#define P2_ESR_EN11              ((T_Reg32 *) 0xF0000E50)->bit11
#define P2_ESR_EN12              ((T_Reg32 *) 0xF0000E50)->bit12
#define P2_ESR_EN13              ((T_Reg32 *) 0xF0000E50)->bit13
#define P2_ESR_EN14              ((T_Reg32 *) 0xF0000E50)->bit14
#define P2_ESR_EN15              ((T_Reg32 *) 0xF0000E50)->bit15
#define P2_ESR_EN2               ((T_Reg32 *) 0xF0000E50)->bit2
#define P2_ESR_EN3               ((T_Reg32 *) 0xF0000E50)->bit3
#define P2_ESR_EN4               ((T_Reg32 *) 0xF0000E50)->bit4
#define P2_ESR_EN5               ((T_Reg32 *) 0xF0000E50)->bit5
#define P2_ESR_EN6               ((T_Reg32 *) 0xF0000E50)->bit6
#define P2_ESR_EN7               ((T_Reg32 *) 0xF0000E50)->bit7
#define P2_ESR_EN8               ((T_Reg32 *) 0xF0000E50)->bit8
#define P2_ESR_EN9               ((T_Reg32 *) 0xF0000E50)->bit9

// Port 2 Input Register
#define P2_IN                  (*((uword volatile *) 0xF0000E24))
#define P2_IN_P0                 ((T_Reg32 *) 0xF0000E24)->bit0
#define P2_IN_P1                 ((T_Reg32 *) 0xF0000E24)->bit1
#define P2_IN_P10                ((T_Reg32 *) 0xF0000E24)->bit10
#define P2_IN_P11                ((T_Reg32 *) 0xF0000E24)->bit11
#define P2_IN_P12                ((T_Reg32 *) 0xF0000E24)->bit12
#define P2_IN_P13                ((T_Reg32 *) 0xF0000E24)->bit13
#define P2_IN_P14                ((T_Reg32 *) 0xF0000E24)->bit14
#define P2_IN_P15                ((T_Reg32 *) 0xF0000E24)->bit15
#define P2_IN_P2                 ((T_Reg32 *) 0xF0000E24)->bit2
#define P2_IN_P3                 ((T_Reg32 *) 0xF0000E24)->bit3
#define P2_IN_P4                 ((T_Reg32 *) 0xF0000E24)->bit4
#define P2_IN_P5                 ((T_Reg32 *) 0xF0000E24)->bit5
#define P2_IN_P6                 ((T_Reg32 *) 0xF0000E24)->bit6
#define P2_IN_P7                 ((T_Reg32 *) 0xF0000E24)->bit7
#define P2_IN_P8                 ((T_Reg32 *) 0xF0000E24)->bit8
#define P2_IN_P9                 ((T_Reg32 *) 0xF0000E24)->bit9

// Port 2 Input/Output Control Register 0
#define P2_IOCR0               (*((uword volatile *) 0xF0000E10))

// Port 2 Input/Output Control Register 12
#define P2_IOCR12              (*((uword volatile *) 0xF0000E1C))

// Port 2 Input/Output Control Register 4
#define P2_IOCR4               (*((uword volatile *) 0xF0000E14))

// Port 2 Input/Output Control Register 8
#define P2_IOCR8               (*((uword volatile *) 0xF0000E18))

// Port 2 Output Modification Register
#define P2_OMR                 (*((uword volatile *) 0xF0000E04))
#define P2_OMR_PR0               ((T_Reg32 *) 0xF0000E04)->bit16
#define P2_OMR_PR1               ((T_Reg32 *) 0xF0000E04)->bit17
#define P2_OMR_PR10              ((T_Reg32 *) 0xF0000E04)->bit26
#define P2_OMR_PR11              ((T_Reg32 *) 0xF0000E04)->bit27
#define P2_OMR_PR12              ((T_Reg32 *) 0xF0000E04)->bit28
#define P2_OMR_PR13              ((T_Reg32 *) 0xF0000E04)->bit29
#define P2_OMR_PR14              ((T_Reg32 *) 0xF0000E04)->bit30
#define P2_OMR_PR15              ((T_Reg32 *) 0xF0000E04)->bit31
#define P2_OMR_PR2               ((T_Reg32 *) 0xF0000E04)->bit18
#define P2_OMR_PR3               ((T_Reg32 *) 0xF0000E04)->bit19
#define P2_OMR_PR4               ((T_Reg32 *) 0xF0000E04)->bit20
#define P2_OMR_PR5               ((T_Reg32 *) 0xF0000E04)->bit21
#define P2_OMR_PR6               ((T_Reg32 *) 0xF0000E04)->bit22
#define P2_OMR_PR7               ((T_Reg32 *) 0xF0000E04)->bit23
#define P2_OMR_PR8               ((T_Reg32 *) 0xF0000E04)->bit24
#define P2_OMR_PR9               ((T_Reg32 *) 0xF0000E04)->bit25
#define P2_OMR_PS0               ((T_Reg32 *) 0xF0000E04)->bit0
#define P2_OMR_PS1               ((T_Reg32 *) 0xF0000E04)->bit1
#define P2_OMR_PS10              ((T_Reg32 *) 0xF0000E04)->bit10
#define P2_OMR_PS11              ((T_Reg32 *) 0xF0000E04)->bit11
#define P2_OMR_PS12              ((T_Reg32 *) 0xF0000E04)->bit12
#define P2_OMR_PS13              ((T_Reg32 *) 0xF0000E04)->bit13
#define P2_OMR_PS14              ((T_Reg32 *) 0xF0000E04)->bit14
#define P2_OMR_PS15              ((T_Reg32 *) 0xF0000E04)->bit15
#define P2_OMR_PS2               ((T_Reg32 *) 0xF0000E04)->bit2
#define P2_OMR_PS3               ((T_Reg32 *) 0xF0000E04)->bit3
#define P2_OMR_PS4               ((T_Reg32 *) 0xF0000E04)->bit4
#define P2_OMR_PS5               ((T_Reg32 *) 0xF0000E04)->bit5
#define P2_OMR_PS6               ((T_Reg32 *) 0xF0000E04)->bit6
#define P2_OMR_PS7               ((T_Reg32 *) 0xF0000E04)->bit7
#define P2_OMR_PS8               ((T_Reg32 *) 0xF0000E04)->bit8
#define P2_OMR_PS9               ((T_Reg32 *) 0xF0000E04)->bit9

// Port 2 Output Register
#define P2_OUT                 (*((uword volatile *) 0xF0000E00))
#define P2_OUT_P0                ((T_Reg32 *) 0xF0000E00)->bit0
#define P2_OUT_P1                ((T_Reg32 *) 0xF0000E00)->bit1
#define P2_OUT_P10               ((T_Reg32 *) 0xF0000E00)->bit10
#define P2_OUT_P11               ((T_Reg32 *) 0xF0000E00)->bit11
#define P2_OUT_P12               ((T_Reg32 *) 0xF0000E00)->bit12
#define P2_OUT_P13               ((T_Reg32 *) 0xF0000E00)->bit13
#define P2_OUT_P14               ((T_Reg32 *) 0xF0000E00)->bit14
#define P2_OUT_P15               ((T_Reg32 *) 0xF0000E00)->bit15
#define P2_OUT_P2                ((T_Reg32 *) 0xF0000E00)->bit2
#define P2_OUT_P3                ((T_Reg32 *) 0xF0000E00)->bit3
#define P2_OUT_P4                ((T_Reg32 *) 0xF0000E00)->bit4
#define P2_OUT_P5                ((T_Reg32 *) 0xF0000E00)->bit5
#define P2_OUT_P6                ((T_Reg32 *) 0xF0000E00)->bit6
#define P2_OUT_P7                ((T_Reg32 *) 0xF0000E00)->bit7
#define P2_OUT_P8                ((T_Reg32 *) 0xF0000E00)->bit8
#define P2_OUT_P9                ((T_Reg32 *) 0xF0000E00)->bit9

// Port 2 Pad Driver Mode Register
#define P2_PDR                 (*((uword volatile *) 0xF0000E40))

// Port 3 Emergency Stop Register
#define P3_ESR                 (*((uword volatile *) 0xF0000F50))
#define P3_ESR_EN0               ((T_Reg32 *) 0xF0000F50)->bit0
#define P3_ESR_EN1               ((T_Reg32 *) 0xF0000F50)->bit1
#define P3_ESR_EN10              ((T_Reg32 *) 0xF0000F50)->bit10
#define P3_ESR_EN11              ((T_Reg32 *) 0xF0000F50)->bit11
#define P3_ESR_EN12              ((T_Reg32 *) 0xF0000F50)->bit12
#define P3_ESR_EN13              ((T_Reg32 *) 0xF0000F50)->bit13
#define P3_ESR_EN14              ((T_Reg32 *) 0xF0000F50)->bit14
#define P3_ESR_EN15              ((T_Reg32 *) 0xF0000F50)->bit15
#define P3_ESR_EN2               ((T_Reg32 *) 0xF0000F50)->bit2
#define P3_ESR_EN3               ((T_Reg32 *) 0xF0000F50)->bit3
#define P3_ESR_EN4               ((T_Reg32 *) 0xF0000F50)->bit4
#define P3_ESR_EN5               ((T_Reg32 *) 0xF0000F50)->bit5
#define P3_ESR_EN6               ((T_Reg32 *) 0xF0000F50)->bit6
#define P3_ESR_EN7               ((T_Reg32 *) 0xF0000F50)->bit7
#define P3_ESR_EN8               ((T_Reg32 *) 0xF0000F50)->bit8
#define P3_ESR_EN9               ((T_Reg32 *) 0xF0000F50)->bit9

// Port 3 Input Register
#define P3_IN                  (*((uword volatile *) 0xF0000F24))
#define P3_IN_P0                 ((T_Reg32 *) 0xF0000F24)->bit0
#define P3_IN_P1                 ((T_Reg32 *) 0xF0000F24)->bit1
#define P3_IN_P10                ((T_Reg32 *) 0xF0000F24)->bit10
#define P3_IN_P11                ((T_Reg32 *) 0xF0000F24)->bit11
#define P3_IN_P12                ((T_Reg32 *) 0xF0000F24)->bit12
#define P3_IN_P13                ((T_Reg32 *) 0xF0000F24)->bit13
#define P3_IN_P14                ((T_Reg32 *) 0xF0000F24)->bit14
#define P3_IN_P15                ((T_Reg32 *) 0xF0000F24)->bit15
#define P3_IN_P2                 ((T_Reg32 *) 0xF0000F24)->bit2
#define P3_IN_P3                 ((T_Reg32 *) 0xF0000F24)->bit3
#define P3_IN_P4                 ((T_Reg32 *) 0xF0000F24)->bit4
#define P3_IN_P5                 ((T_Reg32 *) 0xF0000F24)->bit5
#define P3_IN_P6                 ((T_Reg32 *) 0xF0000F24)->bit6
#define P3_IN_P7                 ((T_Reg32 *) 0xF0000F24)->bit7
#define P3_IN_P8                 ((T_Reg32 *) 0xF0000F24)->bit8
#define P3_IN_P9                 ((T_Reg32 *) 0xF0000F24)->bit9

// Port 3 Input/Output Control Register 0
#define P3_IOCR0               (*((uword volatile *) 0xF0000F10))

// Port 3 Input/Output Control Register 12
#define P3_IOCR12              (*((uword volatile *) 0xF0000F1C))

// Port 3 Input/Output Control Register 4
#define P3_IOCR4               (*((uword volatile *) 0xF0000F14))

// Port 3 Input/Output Control Register 8
#define P3_IOCR8               (*((uword volatile *) 0xF0000F18))

// Port 3 Output Modification Register
#define P3_OMR                 (*((uword volatile *) 0xF0000F04))
#define P3_OMR_PR0               ((T_Reg32 *) 0xF0000F04)->bit16
#define P3_OMR_PR1               ((T_Reg32 *) 0xF0000F04)->bit17
#define P3_OMR_PR10              ((T_Reg32 *) 0xF0000F04)->bit26
#define P3_OMR_PR11              ((T_Reg32 *) 0xF0000F04)->bit27
#define P3_OMR_PR12              ((T_Reg32 *) 0xF0000F04)->bit28
#define P3_OMR_PR13              ((T_Reg32 *) 0xF0000F04)->bit29
#define P3_OMR_PR14              ((T_Reg32 *) 0xF0000F04)->bit30
#define P3_OMR_PR15              ((T_Reg32 *) 0xF0000F04)->bit31
#define P3_OMR_PR2               ((T_Reg32 *) 0xF0000F04)->bit18
#define P3_OMR_PR3               ((T_Reg32 *) 0xF0000F04)->bit19
#define P3_OMR_PR4               ((T_Reg32 *) 0xF0000F04)->bit20
#define P3_OMR_PR5               ((T_Reg32 *) 0xF0000F04)->bit21
#define P3_OMR_PR6               ((T_Reg32 *) 0xF0000F04)->bit22
#define P3_OMR_PR7               ((T_Reg32 *) 0xF0000F04)->bit23
#define P3_OMR_PR8               ((T_Reg32 *) 0xF0000F04)->bit24
#define P3_OMR_PR9               ((T_Reg32 *) 0xF0000F04)->bit25
#define P3_OMR_PS0               ((T_Reg32 *) 0xF0000F04)->bit0
#define P3_OMR_PS1               ((T_Reg32 *) 0xF0000F04)->bit1
#define P3_OMR_PS10              ((T_Reg32 *) 0xF0000F04)->bit10
#define P3_OMR_PS11              ((T_Reg32 *) 0xF0000F04)->bit11
#define P3_OMR_PS12              ((T_Reg32 *) 0xF0000F04)->bit12
#define P3_OMR_PS13              ((T_Reg32 *) 0xF0000F04)->bit13
#define P3_OMR_PS14              ((T_Reg32 *) 0xF0000F04)->bit14
#define P3_OMR_PS15              ((T_Reg32 *) 0xF0000F04)->bit15
#define P3_OMR_PS2               ((T_Reg32 *) 0xF0000F04)->bit2
#define P3_OMR_PS3               ((T_Reg32 *) 0xF0000F04)->bit3
#define P3_OMR_PS4               ((T_Reg32 *) 0xF0000F04)->bit4
#define P3_OMR_PS5               ((T_Reg32 *) 0xF0000F04)->bit5
#define P3_OMR_PS6               ((T_Reg32 *) 0xF0000F04)->bit6
#define P3_OMR_PS7               ((T_Reg32 *) 0xF0000F04)->bit7
#define P3_OMR_PS8               ((T_Reg32 *) 0xF0000F04)->bit8
#define P3_OMR_PS9               ((T_Reg32 *) 0xF0000F04)->bit9

// Port 3 Output Register
#define P3_OUT                 (*((uword volatile *) 0xF0000F00))
#define P3_OUT_P0                ((T_Reg32 *) 0xF0000F00)->bit0
#define P3_OUT_P1                ((T_Reg32 *) 0xF0000F00)->bit1
#define P3_OUT_P10               ((T_Reg32 *) 0xF0000F00)->bit10
#define P3_OUT_P11               ((T_Reg32 *) 0xF0000F00)->bit11
#define P3_OUT_P12               ((T_Reg32 *) 0xF0000F00)->bit12
#define P3_OUT_P13               ((T_Reg32 *) 0xF0000F00)->bit13
#define P3_OUT_P14               ((T_Reg32 *) 0xF0000F00)->bit14
#define P3_OUT_P15               ((T_Reg32 *) 0xF0000F00)->bit15
#define P3_OUT_P2                ((T_Reg32 *) 0xF0000F00)->bit2
#define P3_OUT_P3                ((T_Reg32 *) 0xF0000F00)->bit3
#define P3_OUT_P4                ((T_Reg32 *) 0xF0000F00)->bit4
#define P3_OUT_P5                ((T_Reg32 *) 0xF0000F00)->bit5
#define P3_OUT_P6                ((T_Reg32 *) 0xF0000F00)->bit6
#define P3_OUT_P7                ((T_Reg32 *) 0xF0000F00)->bit7
#define P3_OUT_P8                ((T_Reg32 *) 0xF0000F00)->bit8
#define P3_OUT_P9                ((T_Reg32 *) 0xF0000F00)->bit9

// Port 3 Pad Driver Mode Register
#define P3_PDR                 (*((uword volatile *) 0xF0000F40))

// Port 4 Emergency Stop Register
#define P4_ESR                 (*((uword volatile *) 0xF0001050))
#define P4_ESR_EN0               ((T_Reg32 *) 0xF0001050)->bit0
#define P4_ESR_EN1               ((T_Reg32 *) 0xF0001050)->bit1
#define P4_ESR_EN10              ((T_Reg32 *) 0xF0001050)->bit10
#define P4_ESR_EN11              ((T_Reg32 *) 0xF0001050)->bit11
#define P4_ESR_EN12              ((T_Reg32 *) 0xF0001050)->bit12
#define P4_ESR_EN13              ((T_Reg32 *) 0xF0001050)->bit13
#define P4_ESR_EN14              ((T_Reg32 *) 0xF0001050)->bit14
#define P4_ESR_EN15              ((T_Reg32 *) 0xF0001050)->bit15
#define P4_ESR_EN2               ((T_Reg32 *) 0xF0001050)->bit2
#define P4_ESR_EN3               ((T_Reg32 *) 0xF0001050)->bit3
#define P4_ESR_EN4               ((T_Reg32 *) 0xF0001050)->bit4
#define P4_ESR_EN5               ((T_Reg32 *) 0xF0001050)->bit5
#define P4_ESR_EN6               ((T_Reg32 *) 0xF0001050)->bit6
#define P4_ESR_EN7               ((T_Reg32 *) 0xF0001050)->bit7
#define P4_ESR_EN8               ((T_Reg32 *) 0xF0001050)->bit8
#define P4_ESR_EN9               ((T_Reg32 *) 0xF0001050)->bit9

// Port 4 Input Register
#define P4_IN                  (*((uword volatile *) 0xF0001024))
#define P4_IN_P0                 ((T_Reg32 *) 0xF0001024)->bit0
#define P4_IN_P1                 ((T_Reg32 *) 0xF0001024)->bit1
#define P4_IN_P10                ((T_Reg32 *) 0xF0001024)->bit10
#define P4_IN_P11                ((T_Reg32 *) 0xF0001024)->bit11
#define P4_IN_P12                ((T_Reg32 *) 0xF0001024)->bit12
#define P4_IN_P13                ((T_Reg32 *) 0xF0001024)->bit13
#define P4_IN_P14                ((T_Reg32 *) 0xF0001024)->bit14
#define P4_IN_P15                ((T_Reg32 *) 0xF0001024)->bit15
#define P4_IN_P2                 ((T_Reg32 *) 0xF0001024)->bit2
#define P4_IN_P3                 ((T_Reg32 *) 0xF0001024)->bit3
#define P4_IN_P4                 ((T_Reg32 *) 0xF0001024)->bit4
#define P4_IN_P5                 ((T_Reg32 *) 0xF0001024)->bit5
#define P4_IN_P6                 ((T_Reg32 *) 0xF0001024)->bit6
#define P4_IN_P7                 ((T_Reg32 *) 0xF0001024)->bit7
#define P4_IN_P8                 ((T_Reg32 *) 0xF0001024)->bit8
#define P4_IN_P9                 ((T_Reg32 *) 0xF0001024)->bit9

// Port 4 Input/Output Control Register 0
#define P4_IOCR0               (*((uword volatile *) 0xF0001010))

// Port 4 Output Modification Register
#define P4_OMR                 (*((uword volatile *) 0xF0001004))
#define P4_OMR_PR0               ((T_Reg32 *) 0xF0001004)->bit16
#define P4_OMR_PR1               ((T_Reg32 *) 0xF0001004)->bit17
#define P4_OMR_PR10              ((T_Reg32 *) 0xF0001004)->bit26
#define P4_OMR_PR11              ((T_Reg32 *) 0xF0001004)->bit27
#define P4_OMR_PR12              ((T_Reg32 *) 0xF0001004)->bit28
#define P4_OMR_PR13              ((T_Reg32 *) 0xF0001004)->bit29
#define P4_OMR_PR14              ((T_Reg32 *) 0xF0001004)->bit30
#define P4_OMR_PR15              ((T_Reg32 *) 0xF0001004)->bit31
#define P4_OMR_PR2               ((T_Reg32 *) 0xF0001004)->bit18
#define P4_OMR_PR3               ((T_Reg32 *) 0xF0001004)->bit19
#define P4_OMR_PR4               ((T_Reg32 *) 0xF0001004)->bit20
#define P4_OMR_PR5               ((T_Reg32 *) 0xF0001004)->bit21
#define P4_OMR_PR6               ((T_Reg32 *) 0xF0001004)->bit22
#define P4_OMR_PR7               ((T_Reg32 *) 0xF0001004)->bit23
#define P4_OMR_PR8               ((T_Reg32 *) 0xF0001004)->bit24
#define P4_OMR_PR9               ((T_Reg32 *) 0xF0001004)->bit25
#define P4_OMR_PS0               ((T_Reg32 *) 0xF0001004)->bit0
#define P4_OMR_PS1               ((T_Reg32 *) 0xF0001004)->bit1
#define P4_OMR_PS10              ((T_Reg32 *) 0xF0001004)->bit10
#define P4_OMR_PS11              ((T_Reg32 *) 0xF0001004)->bit11
#define P4_OMR_PS12              ((T_Reg32 *) 0xF0001004)->bit12
#define P4_OMR_PS13              ((T_Reg32 *) 0xF0001004)->bit13
#define P4_OMR_PS14              ((T_Reg32 *) 0xF0001004)->bit14
#define P4_OMR_PS15              ((T_Reg32 *) 0xF0001004)->bit15
#define P4_OMR_PS2               ((T_Reg32 *) 0xF0001004)->bit2
#define P4_OMR_PS3               ((T_Reg32 *) 0xF0001004)->bit3
#define P4_OMR_PS4               ((T_Reg32 *) 0xF0001004)->bit4
#define P4_OMR_PS5               ((T_Reg32 *) 0xF0001004)->bit5
#define P4_OMR_PS6               ((T_Reg32 *) 0xF0001004)->bit6
#define P4_OMR_PS7               ((T_Reg32 *) 0xF0001004)->bit7
#define P4_OMR_PS8               ((T_Reg32 *) 0xF0001004)->bit8
#define P4_OMR_PS9               ((T_Reg32 *) 0xF0001004)->bit9

// Port 4 Output Register
#define P4_OUT                 (*((uword volatile *) 0xF0001000))
#define P4_OUT_P0                ((T_Reg32 *) 0xF0001000)->bit0
#define P4_OUT_P1                ((T_Reg32 *) 0xF0001000)->bit1
#define P4_OUT_P10               ((T_Reg32 *) 0xF0001000)->bit10
#define P4_OUT_P11               ((T_Reg32 *) 0xF0001000)->bit11
#define P4_OUT_P12               ((T_Reg32 *) 0xF0001000)->bit12
#define P4_OUT_P13               ((T_Reg32 *) 0xF0001000)->bit13
#define P4_OUT_P14               ((T_Reg32 *) 0xF0001000)->bit14
#define P4_OUT_P15               ((T_Reg32 *) 0xF0001000)->bit15
#define P4_OUT_P2                ((T_Reg32 *) 0xF0001000)->bit2
#define P4_OUT_P3                ((T_Reg32 *) 0xF0001000)->bit3
#define P4_OUT_P4                ((T_Reg32 *) 0xF0001000)->bit4
#define P4_OUT_P5                ((T_Reg32 *) 0xF0001000)->bit5
#define P4_OUT_P6                ((T_Reg32 *) 0xF0001000)->bit6
#define P4_OUT_P7                ((T_Reg32 *) 0xF0001000)->bit7
#define P4_OUT_P8                ((T_Reg32 *) 0xF0001000)->bit8
#define P4_OUT_P9                ((T_Reg32 *) 0xF0001000)->bit9

// Port 4 Pad Driver Mode Register
#define P4_PDR                 (*((uword volatile *) 0xF0001040))

// Port 5 Emergency Stop Register
#define P5_ESR                 (*((uword volatile *) 0xF0001150))
#define P5_ESR_EN0               ((T_Reg32 *) 0xF0001150)->bit0
#define P5_ESR_EN1               ((T_Reg32 *) 0xF0001150)->bit1
#define P5_ESR_EN10              ((T_Reg32 *) 0xF0001150)->bit10
#define P5_ESR_EN11              ((T_Reg32 *) 0xF0001150)->bit11
#define P5_ESR_EN12              ((T_Reg32 *) 0xF0001150)->bit12
#define P5_ESR_EN13              ((T_Reg32 *) 0xF0001150)->bit13
#define P5_ESR_EN14              ((T_Reg32 *) 0xF0001150)->bit14
#define P5_ESR_EN15              ((T_Reg32 *) 0xF0001150)->bit15
#define P5_ESR_EN2               ((T_Reg32 *) 0xF0001150)->bit2
#define P5_ESR_EN3               ((T_Reg32 *) 0xF0001150)->bit3
#define P5_ESR_EN4               ((T_Reg32 *) 0xF0001150)->bit4
#define P5_ESR_EN5               ((T_Reg32 *) 0xF0001150)->bit5
#define P5_ESR_EN6               ((T_Reg32 *) 0xF0001150)->bit6
#define P5_ESR_EN7               ((T_Reg32 *) 0xF0001150)->bit7
#define P5_ESR_EN8               ((T_Reg32 *) 0xF0001150)->bit8
#define P5_ESR_EN9               ((T_Reg32 *) 0xF0001150)->bit9

// Port 5 Input Register
#define P5_IN                  (*((uword volatile *) 0xF0001124))
#define P5_IN_P0                 ((T_Reg32 *) 0xF0001124)->bit0
#define P5_IN_P1                 ((T_Reg32 *) 0xF0001124)->bit1
#define P5_IN_P10                ((T_Reg32 *) 0xF0001124)->bit10
#define P5_IN_P11                ((T_Reg32 *) 0xF0001124)->bit11
#define P5_IN_P12                ((T_Reg32 *) 0xF0001124)->bit12
#define P5_IN_P13                ((T_Reg32 *) 0xF0001124)->bit13
#define P5_IN_P14                ((T_Reg32 *) 0xF0001124)->bit14
#define P5_IN_P15                ((T_Reg32 *) 0xF0001124)->bit15
#define P5_IN_P2                 ((T_Reg32 *) 0xF0001124)->bit2
#define P5_IN_P3                 ((T_Reg32 *) 0xF0001124)->bit3
#define P5_IN_P4                 ((T_Reg32 *) 0xF0001124)->bit4
#define P5_IN_P5                 ((T_Reg32 *) 0xF0001124)->bit5
#define P5_IN_P6                 ((T_Reg32 *) 0xF0001124)->bit6
#define P5_IN_P7                 ((T_Reg32 *) 0xF0001124)->bit7
#define P5_IN_P8                 ((T_Reg32 *) 0xF0001124)->bit8
#define P5_IN_P9                 ((T_Reg32 *) 0xF0001124)->bit9

// Port 5 Input/Output Control Register 0
#define P5_IOCR0               (*((uword volatile *) 0xF0001110))

// Port 5 Input/Output Control Register 12
#define P5_IOCR12              (*((uword volatile *) 0xF000111C))

// Port n Input/Output Control Register 4
#define P5_IOCR4               (*((uword volatile *) 0xF0001114))

// Port n Input/Output Control Register 8
#define P5_IOCR8               (*((uword volatile *) 0xF0001118))

// Port 5 Output Modification Register
#define P5_OMR                 (*((uword volatile *) 0xF0001104))
#define P5_OMR_PR0               ((T_Reg32 *) 0xF0001104)->bit16
#define P5_OMR_PR1               ((T_Reg32 *) 0xF0001104)->bit17
#define P5_OMR_PR10              ((T_Reg32 *) 0xF0001104)->bit26
#define P5_OMR_PR11              ((T_Reg32 *) 0xF0001104)->bit27
#define P5_OMR_PR12              ((T_Reg32 *) 0xF0001104)->bit28
#define P5_OMR_PR13              ((T_Reg32 *) 0xF0001104)->bit29
#define P5_OMR_PR14              ((T_Reg32 *) 0xF0001104)->bit30
#define P5_OMR_PR15              ((T_Reg32 *) 0xF0001104)->bit31
#define P5_OMR_PR2               ((T_Reg32 *) 0xF0001104)->bit18
#define P5_OMR_PR3               ((T_Reg32 *) 0xF0001104)->bit19
#define P5_OMR_PR4               ((T_Reg32 *) 0xF0001104)->bit20
#define P5_OMR_PR5               ((T_Reg32 *) 0xF0001104)->bit21
#define P5_OMR_PR6               ((T_Reg32 *) 0xF0001104)->bit22
#define P5_OMR_PR7               ((T_Reg32 *) 0xF0001104)->bit23
#define P5_OMR_PR8               ((T_Reg32 *) 0xF0001104)->bit24
#define P5_OMR_PR9               ((T_Reg32 *) 0xF0001104)->bit25
#define P5_OMR_PS0               ((T_Reg32 *) 0xF0001104)->bit0
#define P5_OMR_PS1               ((T_Reg32 *) 0xF0001104)->bit1
#define P5_OMR_PS10              ((T_Reg32 *) 0xF0001104)->bit10
#define P5_OMR_PS11              ((T_Reg32 *) 0xF0001104)->bit11
#define P5_OMR_PS12              ((T_Reg32 *) 0xF0001104)->bit12
#define P5_OMR_PS13              ((T_Reg32 *) 0xF0001104)->bit13
#define P5_OMR_PS14              ((T_Reg32 *) 0xF0001104)->bit14
#define P5_OMR_PS15              ((T_Reg32 *) 0xF0001104)->bit15
#define P5_OMR_PS2               ((T_Reg32 *) 0xF0001104)->bit2
#define P5_OMR_PS3               ((T_Reg32 *) 0xF0001104)->bit3
#define P5_OMR_PS4               ((T_Reg32 *) 0xF0001104)->bit4
#define P5_OMR_PS5               ((T_Reg32 *) 0xF0001104)->bit5
#define P5_OMR_PS6               ((T_Reg32 *) 0xF0001104)->bit6
#define P5_OMR_PS7               ((T_Reg32 *) 0xF0001104)->bit7
#define P5_OMR_PS8               ((T_Reg32 *) 0xF0001104)->bit8
#define P5_OMR_PS9               ((T_Reg32 *) 0xF0001104)->bit9

// Port 5 Output Register
#define P5_OUT                 (*((uword volatile *) 0xF0001100))
#define P5_OUT_P0                ((T_Reg32 *) 0xF0001100)->bit0
#define P5_OUT_P1                ((T_Reg32 *) 0xF0001100)->bit1
#define P5_OUT_P10               ((T_Reg32 *) 0xF0001100)->bit10
#define P5_OUT_P11               ((T_Reg32 *) 0xF0001100)->bit11
#define P5_OUT_P12               ((T_Reg32 *) 0xF0001100)->bit12
#define P5_OUT_P13               ((T_Reg32 *) 0xF0001100)->bit13
#define P5_OUT_P14               ((T_Reg32 *) 0xF0001100)->bit14
#define P5_OUT_P15               ((T_Reg32 *) 0xF0001100)->bit15
#define P5_OUT_P2                ((T_Reg32 *) 0xF0001100)->bit2
#define P5_OUT_P3                ((T_Reg32 *) 0xF0001100)->bit3
#define P5_OUT_P4                ((T_Reg32 *) 0xF0001100)->bit4
#define P5_OUT_P5                ((T_Reg32 *) 0xF0001100)->bit5
#define P5_OUT_P6                ((T_Reg32 *) 0xF0001100)->bit6
#define P5_OUT_P7                ((T_Reg32 *) 0xF0001100)->bit7
#define P5_OUT_P8                ((T_Reg32 *) 0xF0001100)->bit8
#define P5_OUT_P9                ((T_Reg32 *) 0xF0001100)->bit9

// Port 5 Pad Driver Mode Register
#define P5_PDR                 (*((uword volatile *) 0xF0001140))

// Port 6 Emergency Stop Register
#define P6_ESR                 (*((uword volatile *) 0xF0001250))
#define P6_ESR_EN0               ((T_Reg32 *) 0xF0001250)->bit0
#define P6_ESR_EN1               ((T_Reg32 *) 0xF0001250)->bit1
#define P6_ESR_EN10              ((T_Reg32 *) 0xF0001250)->bit10
#define P6_ESR_EN11              ((T_Reg32 *) 0xF0001250)->bit11
#define P6_ESR_EN12              ((T_Reg32 *) 0xF0001250)->bit12
#define P6_ESR_EN13              ((T_Reg32 *) 0xF0001250)->bit13
#define P6_ESR_EN14              ((T_Reg32 *) 0xF0001250)->bit14
#define P6_ESR_EN15              ((T_Reg32 *) 0xF0001250)->bit15
#define P6_ESR_EN2               ((T_Reg32 *) 0xF0001250)->bit2
#define P6_ESR_EN3               ((T_Reg32 *) 0xF0001250)->bit3
#define P6_ESR_EN4               ((T_Reg32 *) 0xF0001250)->bit4
#define P6_ESR_EN5               ((T_Reg32 *) 0xF0001250)->bit5
#define P6_ESR_EN6               ((T_Reg32 *) 0xF0001250)->bit6
#define P6_ESR_EN7               ((T_Reg32 *) 0xF0001250)->bit7
#define P6_ESR_EN8               ((T_Reg32 *) 0xF0001250)->bit8
#define P6_ESR_EN9               ((T_Reg32 *) 0xF0001250)->bit9

// Port 6 Input Register
#define P6_IN                  (*((uword volatile *) 0xF0001224))
#define P6_IN_P0                 ((T_Reg32 *) 0xF0001224)->bit0
#define P6_IN_P1                 ((T_Reg32 *) 0xF0001224)->bit1
#define P6_IN_P10                ((T_Reg32 *) 0xF0001224)->bit10
#define P6_IN_P11                ((T_Reg32 *) 0xF0001224)->bit11
#define P6_IN_P12                ((T_Reg32 *) 0xF0001224)->bit12
#define P6_IN_P13                ((T_Reg32 *) 0xF0001224)->bit13
#define P6_IN_P14                ((T_Reg32 *) 0xF0001224)->bit14
#define P6_IN_P15                ((T_Reg32 *) 0xF0001224)->bit15
#define P6_IN_P2                 ((T_Reg32 *) 0xF0001224)->bit2
#define P6_IN_P3                 ((T_Reg32 *) 0xF0001224)->bit3
#define P6_IN_P4                 ((T_Reg32 *) 0xF0001224)->bit4
#define P6_IN_P5                 ((T_Reg32 *) 0xF0001224)->bit5
#define P6_IN_P6                 ((T_Reg32 *) 0xF0001224)->bit6
#define P6_IN_P7                 ((T_Reg32 *) 0xF0001224)->bit7
#define P6_IN_P8                 ((T_Reg32 *) 0xF0001224)->bit8
#define P6_IN_P9                 ((T_Reg32 *) 0xF0001224)->bit9

// Port 6 Input/Output Control Register 0
#define P6_IOCR0               (*((uword volatile *) 0xF0001210))

// Port 6 Output Modification Register
#define P6_OMR                 (*((uword volatile *) 0xF0001204))
#define P6_OMR_PR0               ((T_Reg32 *) 0xF0001204)->bit16
#define P6_OMR_PR1               ((T_Reg32 *) 0xF0001204)->bit17
#define P6_OMR_PR10              ((T_Reg32 *) 0xF0001204)->bit26
#define P6_OMR_PR11              ((T_Reg32 *) 0xF0001204)->bit27
#define P6_OMR_PR12              ((T_Reg32 *) 0xF0001204)->bit28
#define P6_OMR_PR13              ((T_Reg32 *) 0xF0001204)->bit29
#define P6_OMR_PR14              ((T_Reg32 *) 0xF0001204)->bit30
#define P6_OMR_PR15              ((T_Reg32 *) 0xF0001204)->bit31
#define P6_OMR_PR2               ((T_Reg32 *) 0xF0001204)->bit18
#define P6_OMR_PR3               ((T_Reg32 *) 0xF0001204)->bit19
#define P6_OMR_PR4               ((T_Reg32 *) 0xF0001204)->bit20
#define P6_OMR_PR5               ((T_Reg32 *) 0xF0001204)->bit21
#define P6_OMR_PR6               ((T_Reg32 *) 0xF0001204)->bit22
#define P6_OMR_PR7               ((T_Reg32 *) 0xF0001204)->bit23
#define P6_OMR_PR8               ((T_Reg32 *) 0xF0001204)->bit24
#define P6_OMR_PR9               ((T_Reg32 *) 0xF0001204)->bit25
#define P6_OMR_PS0               ((T_Reg32 *) 0xF0001204)->bit0
#define P6_OMR_PS1               ((T_Reg32 *) 0xF0001204)->bit1
#define P6_OMR_PS10              ((T_Reg32 *) 0xF0001204)->bit10
#define P6_OMR_PS11              ((T_Reg32 *) 0xF0001204)->bit11
#define P6_OMR_PS12              ((T_Reg32 *) 0xF0001204)->bit12
#define P6_OMR_PS13              ((T_Reg32 *) 0xF0001204)->bit13
#define P6_OMR_PS14              ((T_Reg32 *) 0xF0001204)->bit14
#define P6_OMR_PS15              ((T_Reg32 *) 0xF0001204)->bit15
#define P6_OMR_PS2               ((T_Reg32 *) 0xF0001204)->bit2
#define P6_OMR_PS3               ((T_Reg32 *) 0xF0001204)->bit3
#define P6_OMR_PS4               ((T_Reg32 *) 0xF0001204)->bit4
#define P6_OMR_PS5               ((T_Reg32 *) 0xF0001204)->bit5
#define P6_OMR_PS6               ((T_Reg32 *) 0xF0001204)->bit6
#define P6_OMR_PS7               ((T_Reg32 *) 0xF0001204)->bit7
#define P6_OMR_PS8               ((T_Reg32 *) 0xF0001204)->bit8
#define P6_OMR_PS9               ((T_Reg32 *) 0xF0001204)->bit9

// Port 6 Output Register
#define P6_OUT                 (*((uword volatile *) 0xF0001200))
#define P6_OUT_P0                ((T_Reg32 *) 0xF0001200)->bit0
#define P6_OUT_P1                ((T_Reg32 *) 0xF0001200)->bit1
#define P6_OUT_P10               ((T_Reg32 *) 0xF0001200)->bit10
#define P6_OUT_P11               ((T_Reg32 *) 0xF0001200)->bit11
#define P6_OUT_P12               ((T_Reg32 *) 0xF0001200)->bit12
#define P6_OUT_P13               ((T_Reg32 *) 0xF0001200)->bit13
#define P6_OUT_P14               ((T_Reg32 *) 0xF0001200)->bit14
#define P6_OUT_P15               ((T_Reg32 *) 0xF0001200)->bit15
#define P6_OUT_P2                ((T_Reg32 *) 0xF0001200)->bit2
#define P6_OUT_P3                ((T_Reg32 *) 0xF0001200)->bit3
#define P6_OUT_P4                ((T_Reg32 *) 0xF0001200)->bit4
#define P6_OUT_P5                ((T_Reg32 *) 0xF0001200)->bit5
#define P6_OUT_P6                ((T_Reg32 *) 0xF0001200)->bit6
#define P6_OUT_P7                ((T_Reg32 *) 0xF0001200)->bit7
#define P6_OUT_P8                ((T_Reg32 *) 0xF0001200)->bit8
#define P6_OUT_P9                ((T_Reg32 *) 0xF0001200)->bit9

// Port 6 Pad Driver Mode Register
#define P6_PDR                 (*((uword volatile *) 0xF0001240))

// Port 7 Emergency Stop Register
#define P7_ESR                 (*((uword volatile *) 0xF0001350))
#define P7_ESR_EN0               ((T_Reg32 *) 0xF0001350)->bit0
#define P7_ESR_EN1               ((T_Reg32 *) 0xF0001350)->bit1
#define P7_ESR_EN10              ((T_Reg32 *) 0xF0001350)->bit10
#define P7_ESR_EN11              ((T_Reg32 *) 0xF0001350)->bit11
#define P7_ESR_EN12              ((T_Reg32 *) 0xF0001350)->bit12
#define P7_ESR_EN13              ((T_Reg32 *) 0xF0001350)->bit13
#define P7_ESR_EN14              ((T_Reg32 *) 0xF0001350)->bit14
#define P7_ESR_EN15              ((T_Reg32 *) 0xF0001350)->bit15
#define P7_ESR_EN2               ((T_Reg32 *) 0xF0001350)->bit2
#define P7_ESR_EN3               ((T_Reg32 *) 0xF0001350)->bit3
#define P7_ESR_EN4               ((T_Reg32 *) 0xF0001350)->bit4
#define P7_ESR_EN5               ((T_Reg32 *) 0xF0001350)->bit5
#define P7_ESR_EN6               ((T_Reg32 *) 0xF0001350)->bit6
#define P7_ESR_EN7               ((T_Reg32 *) 0xF0001350)->bit7
#define P7_ESR_EN8               ((T_Reg32 *) 0xF0001350)->bit8
#define P7_ESR_EN9               ((T_Reg32 *) 0xF0001350)->bit9

// Port 7 Input Register
#define P7_IN                  (*((uword volatile *) 0xF0001324))
#define P7_IN_P0                 ((T_Reg32 *) 0xF0001324)->bit0
#define P7_IN_P1                 ((T_Reg32 *) 0xF0001324)->bit1
#define P7_IN_P10                ((T_Reg32 *) 0xF0001324)->bit10
#define P7_IN_P11                ((T_Reg32 *) 0xF0001324)->bit11
#define P7_IN_P12                ((T_Reg32 *) 0xF0001324)->bit12
#define P7_IN_P13                ((T_Reg32 *) 0xF0001324)->bit13
#define P7_IN_P14                ((T_Reg32 *) 0xF0001324)->bit14
#define P7_IN_P15                ((T_Reg32 *) 0xF0001324)->bit15
#define P7_IN_P2                 ((T_Reg32 *) 0xF0001324)->bit2
#define P7_IN_P3                 ((T_Reg32 *) 0xF0001324)->bit3
#define P7_IN_P4                 ((T_Reg32 *) 0xF0001324)->bit4
#define P7_IN_P5                 ((T_Reg32 *) 0xF0001324)->bit5
#define P7_IN_P6                 ((T_Reg32 *) 0xF0001324)->bit6
#define P7_IN_P7                 ((T_Reg32 *) 0xF0001324)->bit7
#define P7_IN_P8                 ((T_Reg32 *) 0xF0001324)->bit8
#define P7_IN_P9                 ((T_Reg32 *) 0xF0001324)->bit9

// Port 7 Input/Output Control Register 0
#define P7_IOCR0               (*((uword volatile *) 0xF0001310))

// Port 7 Input/Output Control Register 12
#define P7_IOCR12              (*((uword volatile *) 0xF000131C))

// Port 7 Input/Output Control Register 4
#define P7_IOCR4               (*((uword volatile *) 0xF0001314))

// Port 7 Input/Output Control Register 8
#define P7_IOCR8               (*((uword volatile *) 0xF0001318))

// Port 7 Output Modification Register
#define P7_OMR                 (*((uword volatile *) 0xF0001304))
#define P7_OMR_PR0               ((T_Reg32 *) 0xF0001304)->bit16
#define P7_OMR_PR1               ((T_Reg32 *) 0xF0001304)->bit17
#define P7_OMR_PR10              ((T_Reg32 *) 0xF0001304)->bit26
#define P7_OMR_PR11              ((T_Reg32 *) 0xF0001304)->bit27
#define P7_OMR_PR12              ((T_Reg32 *) 0xF0001304)->bit28
#define P7_OMR_PR13              ((T_Reg32 *) 0xF0001304)->bit29
#define P7_OMR_PR14              ((T_Reg32 *) 0xF0001304)->bit30
#define P7_OMR_PR15              ((T_Reg32 *) 0xF0001304)->bit31
#define P7_OMR_PR2               ((T_Reg32 *) 0xF0001304)->bit18
#define P7_OMR_PR3               ((T_Reg32 *) 0xF0001304)->bit19
#define P7_OMR_PR4               ((T_Reg32 *) 0xF0001304)->bit20
#define P7_OMR_PR5               ((T_Reg32 *) 0xF0001304)->bit21
#define P7_OMR_PR6               ((T_Reg32 *) 0xF0001304)->bit22
#define P7_OMR_PR7               ((T_Reg32 *) 0xF0001304)->bit23
#define P7_OMR_PR8               ((T_Reg32 *) 0xF0001304)->bit24
#define P7_OMR_PR9               ((T_Reg32 *) 0xF0001304)->bit25
#define P7_OMR_PS0               ((T_Reg32 *) 0xF0001304)->bit0
#define P7_OMR_PS1               ((T_Reg32 *) 0xF0001304)->bit1
#define P7_OMR_PS10              ((T_Reg32 *) 0xF0001304)->bit10
#define P7_OMR_PS11              ((T_Reg32 *) 0xF0001304)->bit11
#define P7_OMR_PS12              ((T_Reg32 *) 0xF0001304)->bit12
#define P7_OMR_PS13              ((T_Reg32 *) 0xF0001304)->bit13
#define P7_OMR_PS14              ((T_Reg32 *) 0xF0001304)->bit14
#define P7_OMR_PS15              ((T_Reg32 *) 0xF0001304)->bit15
#define P7_OMR_PS2               ((T_Reg32 *) 0xF0001304)->bit2
#define P7_OMR_PS3               ((T_Reg32 *) 0xF0001304)->bit3
#define P7_OMR_PS4               ((T_Reg32 *) 0xF0001304)->bit4
#define P7_OMR_PS5               ((T_Reg32 *) 0xF0001304)->bit5
#define P7_OMR_PS6               ((T_Reg32 *) 0xF0001304)->bit6
#define P7_OMR_PS7               ((T_Reg32 *) 0xF0001304)->bit7
#define P7_OMR_PS8               ((T_Reg32 *) 0xF0001304)->bit8
#define P7_OMR_PS9               ((T_Reg32 *) 0xF0001304)->bit9

// Port 7 Output Register
#define P7_OUT                 (*((uword volatile *) 0xF0001300))
#define P7_OUT_P0                ((T_Reg32 *) 0xF0001300)->bit0
#define P7_OUT_P1                ((T_Reg32 *) 0xF0001300)->bit1
#define P7_OUT_P10               ((T_Reg32 *) 0xF0001300)->bit10
#define P7_OUT_P11               ((T_Reg32 *) 0xF0001300)->bit11
#define P7_OUT_P12               ((T_Reg32 *) 0xF0001300)->bit12
#define P7_OUT_P13               ((T_Reg32 *) 0xF0001300)->bit13
#define P7_OUT_P14               ((T_Reg32 *) 0xF0001300)->bit14
#define P7_OUT_P15               ((T_Reg32 *) 0xF0001300)->bit15
#define P7_OUT_P2                ((T_Reg32 *) 0xF0001300)->bit2
#define P7_OUT_P3                ((T_Reg32 *) 0xF0001300)->bit3
#define P7_OUT_P4                ((T_Reg32 *) 0xF0001300)->bit4
#define P7_OUT_P5                ((T_Reg32 *) 0xF0001300)->bit5
#define P7_OUT_P6                ((T_Reg32 *) 0xF0001300)->bit6
#define P7_OUT_P7                ((T_Reg32 *) 0xF0001300)->bit7
#define P7_OUT_P8                ((T_Reg32 *) 0xF0001300)->bit8
#define P7_OUT_P9                ((T_Reg32 *) 0xF0001300)->bit9

// Port 7 Pad Driver Mode Register
#define P7_PDR                 (*((uword volatile *) 0xF0001340))

// Port 8 Emergency Stop Register
#define P8_ESR                 (*((uword volatile *) 0xF0001450))
#define P8_ESR_EN0               ((T_Reg32 *) 0xF0001450)->bit0
#define P8_ESR_EN1               ((T_Reg32 *) 0xF0001450)->bit1
#define P8_ESR_EN10              ((T_Reg32 *) 0xF0001450)->bit10
#define P8_ESR_EN11              ((T_Reg32 *) 0xF0001450)->bit11
#define P8_ESR_EN12              ((T_Reg32 *) 0xF0001450)->bit12
#define P8_ESR_EN13              ((T_Reg32 *) 0xF0001450)->bit13
#define P8_ESR_EN14              ((T_Reg32 *) 0xF0001450)->bit14
#define P8_ESR_EN15              ((T_Reg32 *) 0xF0001450)->bit15
#define P8_ESR_EN2               ((T_Reg32 *) 0xF0001450)->bit2
#define P8_ESR_EN3               ((T_Reg32 *) 0xF0001450)->bit3
#define P8_ESR_EN4               ((T_Reg32 *) 0xF0001450)->bit4
#define P8_ESR_EN5               ((T_Reg32 *) 0xF0001450)->bit5
#define P8_ESR_EN6               ((T_Reg32 *) 0xF0001450)->bit6
#define P8_ESR_EN7               ((T_Reg32 *) 0xF0001450)->bit7
#define P8_ESR_EN8               ((T_Reg32 *) 0xF0001450)->bit8
#define P8_ESR_EN9               ((T_Reg32 *) 0xF0001450)->bit9

// Port 8 Input Register
#define P8_IN                  (*((uword volatile *) 0xF0001424))
#define P8_IN_P0                 ((T_Reg32 *) 0xF0001424)->bit0
#define P8_IN_P1                 ((T_Reg32 *) 0xF0001424)->bit1
#define P8_IN_P10                ((T_Reg32 *) 0xF0001424)->bit10
#define P8_IN_P11                ((T_Reg32 *) 0xF0001424)->bit11
#define P8_IN_P12                ((T_Reg32 *) 0xF0001424)->bit12
#define P8_IN_P13                ((T_Reg32 *) 0xF0001424)->bit13
#define P8_IN_P14                ((T_Reg32 *) 0xF0001424)->bit14
#define P8_IN_P15                ((T_Reg32 *) 0xF0001424)->bit15
#define P8_IN_P2                 ((T_Reg32 *) 0xF0001424)->bit2
#define P8_IN_P3                 ((T_Reg32 *) 0xF0001424)->bit3
#define P8_IN_P4                 ((T_Reg32 *) 0xF0001424)->bit4
#define P8_IN_P5                 ((T_Reg32 *) 0xF0001424)->bit5
#define P8_IN_P6                 ((T_Reg32 *) 0xF0001424)->bit6
#define P8_IN_P7                 ((T_Reg32 *) 0xF0001424)->bit7
#define P8_IN_P8                 ((T_Reg32 *) 0xF0001424)->bit8
#define P8_IN_P9                 ((T_Reg32 *) 0xF0001424)->bit9

// Port 8 Input/Output Control Register 0
#define P8_IOCR0               (*((uword volatile *) 0xF0001410))

// Port 8 Input/Output Control Register 12
#define P8_IOCR12              (*((uword volatile *) 0xF000141C))

// Port 8 Input/Output Control Register 4
#define P8_IOCR4               (*((uword volatile *) 0xF0001414))

// Port 8 Input/Output Control Register 8
#define P8_IOCR8               (*((uword volatile *) 0xF0001418))

// Port 8 Output Modification Register
#define P8_OMR                 (*((uword volatile *) 0xF0001404))
#define P8_OMR_PR0               ((T_Reg32 *) 0xF0001404)->bit16
#define P8_OMR_PR1               ((T_Reg32 *) 0xF0001404)->bit17
#define P8_OMR_PR10              ((T_Reg32 *) 0xF0001404)->bit26
#define P8_OMR_PR11              ((T_Reg32 *) 0xF0001404)->bit27
#define P8_OMR_PR12              ((T_Reg32 *) 0xF0001404)->bit28
#define P8_OMR_PR13              ((T_Reg32 *) 0xF0001404)->bit29
#define P8_OMR_PR14              ((T_Reg32 *) 0xF0001404)->bit30
#define P8_OMR_PR15              ((T_Reg32 *) 0xF0001404)->bit31
#define P8_OMR_PR2               ((T_Reg32 *) 0xF0001404)->bit18
#define P8_OMR_PR3               ((T_Reg32 *) 0xF0001404)->bit19
#define P8_OMR_PR4               ((T_Reg32 *) 0xF0001404)->bit20
#define P8_OMR_PR5               ((T_Reg32 *) 0xF0001404)->bit21
#define P8_OMR_PR6               ((T_Reg32 *) 0xF0001404)->bit22
#define P8_OMR_PR7               ((T_Reg32 *) 0xF0001404)->bit23
#define P8_OMR_PR8               ((T_Reg32 *) 0xF0001404)->bit24
#define P8_OMR_PR9               ((T_Reg32 *) 0xF0001404)->bit25
#define P8_OMR_PS0               ((T_Reg32 *) 0xF0001404)->bit0
#define P8_OMR_PS1               ((T_Reg32 *) 0xF0001404)->bit1
#define P8_OMR_PS10              ((T_Reg32 *) 0xF0001404)->bit10
#define P8_OMR_PS11              ((T_Reg32 *) 0xF0001404)->bit11
#define P8_OMR_PS12              ((T_Reg32 *) 0xF0001404)->bit12
#define P8_OMR_PS13              ((T_Reg32 *) 0xF0001404)->bit13
#define P8_OMR_PS14              ((T_Reg32 *) 0xF0001404)->bit14
#define P8_OMR_PS15              ((T_Reg32 *) 0xF0001404)->bit15
#define P8_OMR_PS2               ((T_Reg32 *) 0xF0001404)->bit2
#define P8_OMR_PS3               ((T_Reg32 *) 0xF0001404)->bit3
#define P8_OMR_PS4               ((T_Reg32 *) 0xF0001404)->bit4
#define P8_OMR_PS5               ((T_Reg32 *) 0xF0001404)->bit5
#define P8_OMR_PS6               ((T_Reg32 *) 0xF0001404)->bit6
#define P8_OMR_PS7               ((T_Reg32 *) 0xF0001404)->bit7
#define P8_OMR_PS8               ((T_Reg32 *) 0xF0001404)->bit8
#define P8_OMR_PS9               ((T_Reg32 *) 0xF0001404)->bit9

// Port 8 Output Register
#define P8_OUT                 (*((uword volatile *) 0xF0001400))
#define P8_OUT_P0                ((T_Reg32 *) 0xF0001400)->bit0
#define P8_OUT_P1                ((T_Reg32 *) 0xF0001400)->bit1
#define P8_OUT_P10               ((T_Reg32 *) 0xF0001400)->bit10
#define P8_OUT_P11               ((T_Reg32 *) 0xF0001400)->bit11
#define P8_OUT_P12               ((T_Reg32 *) 0xF0001400)->bit12
#define P8_OUT_P13               ((T_Reg32 *) 0xF0001400)->bit13
#define P8_OUT_P14               ((T_Reg32 *) 0xF0001400)->bit14
#define P8_OUT_P15               ((T_Reg32 *) 0xF0001400)->bit15
#define P8_OUT_P2                ((T_Reg32 *) 0xF0001400)->bit2
#define P8_OUT_P3                ((T_Reg32 *) 0xF0001400)->bit3
#define P8_OUT_P4                ((T_Reg32 *) 0xF0001400)->bit4
#define P8_OUT_P5                ((T_Reg32 *) 0xF0001400)->bit5
#define P8_OUT_P6                ((T_Reg32 *) 0xF0001400)->bit6
#define P8_OUT_P7                ((T_Reg32 *) 0xF0001400)->bit7
#define P8_OUT_P8                ((T_Reg32 *) 0xF0001400)->bit8
#define P8_OUT_P9                ((T_Reg32 *) 0xF0001400)->bit9

// Port 8 Pad Driver Mode Register
#define P8_PDR                 (*((uword volatile *) 0xF0001440))

// Port 9 Emergency Stop Register
#define P9_ESR                 (*((uword volatile *) 0xF0001550))
#define P9_ESR_EN0               ((T_Reg32 *) 0xF0001550)->bit0
#define P9_ESR_EN1               ((T_Reg32 *) 0xF0001550)->bit1
#define P9_ESR_EN10              ((T_Reg32 *) 0xF0001550)->bit10
#define P9_ESR_EN11              ((T_Reg32 *) 0xF0001550)->bit11
#define P9_ESR_EN12              ((T_Reg32 *) 0xF0001550)->bit12
#define P9_ESR_EN13              ((T_Reg32 *) 0xF0001550)->bit13
#define P9_ESR_EN14              ((T_Reg32 *) 0xF0001550)->bit14
#define P9_ESR_EN15              ((T_Reg32 *) 0xF0001550)->bit15
#define P9_ESR_EN2               ((T_Reg32 *) 0xF0001550)->bit2
#define P9_ESR_EN3               ((T_Reg32 *) 0xF0001550)->bit3
#define P9_ESR_EN4               ((T_Reg32 *) 0xF0001550)->bit4
#define P9_ESR_EN5               ((T_Reg32 *) 0xF0001550)->bit5
#define P9_ESR_EN6               ((T_Reg32 *) 0xF0001550)->bit6
#define P9_ESR_EN7               ((T_Reg32 *) 0xF0001550)->bit7
#define P9_ESR_EN8               ((T_Reg32 *) 0xF0001550)->bit8
#define P9_ESR_EN9               ((T_Reg32 *) 0xF0001550)->bit9

// Port 9 Input Register
#define P9_IN                  (*((uword volatile *) 0xF0001524))
#define P9_IN_P0                 ((T_Reg32 *) 0xF0001524)->bit0
#define P9_IN_P1                 ((T_Reg32 *) 0xF0001524)->bit1
#define P9_IN_P10                ((T_Reg32 *) 0xF0001524)->bit10
#define P9_IN_P11                ((T_Reg32 *) 0xF0001524)->bit11
#define P9_IN_P12                ((T_Reg32 *) 0xF0001524)->bit12
#define P9_IN_P13                ((T_Reg32 *) 0xF0001524)->bit13
#define P9_IN_P14                ((T_Reg32 *) 0xF0001524)->bit14
#define P9_IN_P15                ((T_Reg32 *) 0xF0001524)->bit15
#define P9_IN_P2                 ((T_Reg32 *) 0xF0001524)->bit2
#define P9_IN_P3                 ((T_Reg32 *) 0xF0001524)->bit3
#define P9_IN_P4                 ((T_Reg32 *) 0xF0001524)->bit4
#define P9_IN_P5                 ((T_Reg32 *) 0xF0001524)->bit5
#define P9_IN_P6                 ((T_Reg32 *) 0xF0001524)->bit6
#define P9_IN_P7                 ((T_Reg32 *) 0xF0001524)->bit7
#define P9_IN_P8                 ((T_Reg32 *) 0xF0001524)->bit8
#define P9_IN_P9                 ((T_Reg32 *) 0xF0001524)->bit9

// Port 9 Input/Output Control Register 0
#define P9_IOCR0               (*((uword volatile *) 0xF0001510))

// Port 9 Input/Output Control Register 4
#define P9_IOCR4               (*((uword volatile *) 0xF0001514))

// Port 9 Input/Output Control Register 8
#define P9_IOCR8               (*((uword volatile *) 0xF0001518))

// Port 9 Output Modification Register
#define P9_OMR                 (*((uword volatile *) 0xF0001504))
#define P9_OMR_PR0               ((T_Reg32 *) 0xF0001504)->bit16
#define P9_OMR_PR1               ((T_Reg32 *) 0xF0001504)->bit17
#define P9_OMR_PR10              ((T_Reg32 *) 0xF0001504)->bit26
#define P9_OMR_PR11              ((T_Reg32 *) 0xF0001504)->bit27
#define P9_OMR_PR12              ((T_Reg32 *) 0xF0001504)->bit28
#define P9_OMR_PR13              ((T_Reg32 *) 0xF0001504)->bit29
#define P9_OMR_PR14              ((T_Reg32 *) 0xF0001504)->bit30
#define P9_OMR_PR15              ((T_Reg32 *) 0xF0001504)->bit31
#define P9_OMR_PR2               ((T_Reg32 *) 0xF0001504)->bit18
#define P9_OMR_PR3               ((T_Reg32 *) 0xF0001504)->bit19
#define P9_OMR_PR4               ((T_Reg32 *) 0xF0001504)->bit20
#define P9_OMR_PR5               ((T_Reg32 *) 0xF0001504)->bit21
#define P9_OMR_PR6               ((T_Reg32 *) 0xF0001504)->bit22
#define P9_OMR_PR7               ((T_Reg32 *) 0xF0001504)->bit23
#define P9_OMR_PR8               ((T_Reg32 *) 0xF0001504)->bit24
#define P9_OMR_PR9               ((T_Reg32 *) 0xF0001504)->bit25
#define P9_OMR_PS0               ((T_Reg32 *) 0xF0001504)->bit0
#define P9_OMR_PS1               ((T_Reg32 *) 0xF0001504)->bit1
#define P9_OMR_PS10              ((T_Reg32 *) 0xF0001504)->bit10
#define P9_OMR_PS11              ((T_Reg32 *) 0xF0001504)->bit11
#define P9_OMR_PS12              ((T_Reg32 *) 0xF0001504)->bit12
#define P9_OMR_PS13              ((T_Reg32 *) 0xF0001504)->bit13
#define P9_OMR_PS14              ((T_Reg32 *) 0xF0001504)->bit14
#define P9_OMR_PS15              ((T_Reg32 *) 0xF0001504)->bit15
#define P9_OMR_PS2               ((T_Reg32 *) 0xF0001504)->bit2
#define P9_OMR_PS3               ((T_Reg32 *) 0xF0001504)->bit3
#define P9_OMR_PS4               ((T_Reg32 *) 0xF0001504)->bit4
#define P9_OMR_PS5               ((T_Reg32 *) 0xF0001504)->bit5
#define P9_OMR_PS6               ((T_Reg32 *) 0xF0001504)->bit6
#define P9_OMR_PS7               ((T_Reg32 *) 0xF0001504)->bit7
#define P9_OMR_PS8               ((T_Reg32 *) 0xF0001504)->bit8
#define P9_OMR_PS9               ((T_Reg32 *) 0xF0001504)->bit9

// Port 9 Output Register
#define P9_OUT                 (*((uword volatile *) 0xF0001500))
#define P9_OUT_P0                ((T_Reg32 *) 0xF0001500)->bit0
#define P9_OUT_P1                ((T_Reg32 *) 0xF0001500)->bit1
#define P9_OUT_P10               ((T_Reg32 *) 0xF0001500)->bit10
#define P9_OUT_P11               ((T_Reg32 *) 0xF0001500)->bit11
#define P9_OUT_P12               ((T_Reg32 *) 0xF0001500)->bit12
#define P9_OUT_P13               ((T_Reg32 *) 0xF0001500)->bit13
#define P9_OUT_P14               ((T_Reg32 *) 0xF0001500)->bit14
#define P9_OUT_P15               ((T_Reg32 *) 0xF0001500)->bit15
#define P9_OUT_P2                ((T_Reg32 *) 0xF0001500)->bit2
#define P9_OUT_P3                ((T_Reg32 *) 0xF0001500)->bit3
#define P9_OUT_P4                ((T_Reg32 *) 0xF0001500)->bit4
#define P9_OUT_P5                ((T_Reg32 *) 0xF0001500)->bit5
#define P9_OUT_P6                ((T_Reg32 *) 0xF0001500)->bit6
#define P9_OUT_P7                ((T_Reg32 *) 0xF0001500)->bit7
#define P9_OUT_P8                ((T_Reg32 *) 0xF0001500)->bit8
#define P9_OUT_P9                ((T_Reg32 *) 0xF0001500)->bit9

// Port 9 Pad Driver Mode Register
#define P9_PDR                 (*((uword volatile *) 0xF0001540))

// Program Counter
#define PC                     (*((uword volatile *) 0xF7E1FE08))

// PCP Clock Control Register
#define PCP_CLC                (*((uword volatile *) 0xF0043F00))
#define PCP_CLC_PCGDIS           0x00008000

// PCP Control/Status Register
#define PCP_CS                 (*((uword volatile *) 0xF0043F10))
#define PCP_CS_CWE               0x00010000
#define PCP_CS_EIE               0x00000020
#define PCP_CS_EN                0x00000001
#define PCP_CS_PPE               0x00000100
#define PCP_CS_RCB               0x00000010
#define PCP_CS_RS                0x00000004
#define PCP_CS_RST               0x00000002

// PCP Error/Debug Status Register
#define PCP_ES                 (*((uword volatile *) 0xF0043F14))
#define PCP_ES_BER               0x00000001
#define PCP_ES_CWD               0x00000040
#define PCP_ES_DBE               0x00000010
#define PCP_ES_DCR               0x00000004
#define PCP_ES_IAE               0x00000008
#define PCP_ES_IOP               0x00000002
#define PCP_ES_ME                0x00000020
#define PCP_ES_PPC               0x00000080

// PCP Interrupt Configuration Register
#define PCP_ICON               (*((uword volatile *) 0xF0043F28))
#define PCP_ICON_IP0E            0x00000100
#define PCP_ICON_IP1E            0x00000200
#define PCP_ICON_IP2E            0x00000400
#define PCP_ICON_IP3E            0x00000800

// PCP Interrupt Control Register
#define PCP_ICR                (*((uword volatile *) 0xF0043F20))
#define PCP_ICR_IE               0x00000100
#define PCP_ICR_PONECYC          0x04000000

// PCP Module Identification Register
#define PCP_ID                 (*((uword volatile *) 0xF0043F08))

// PCP Interrupt Threshold Control Register
#define PCP_ITR                (*((uword volatile *) 0xF0043F24))

// PCP Service Request Control Register 0
#define PCP_SRC0               (*((uword volatile *) 0xF0043FFC))
#define PCP_SRC0_SRE             0x00001000
#define PCP_SRC0_SRR             0x00002000

// PCP Service Request Control Register 1
#define PCP_SRC1               (*((uword volatile *) 0xF0043FF8))
#define PCP_SRC1_SRE             0x00001000
#define PCP_SRC1_SRR             0x00002000

// PCP Service Request Control Register 10
#define PCP_SRC10              (*((uword volatile *) 0xF0043FD4))
#define PCP_SRC10_RRQ            0x10000000
#define PCP_SRC10_SRE            0x00001000
#define PCP_SRC10_SRR            0x00002000

// PCP Service Request Control Register 11
#define PCP_SRC11              (*((uword volatile *) 0xF0043FD0))
#define PCP_SRC11_RRQ            0x10000000
#define PCP_SRC11_SRE            0x00001000
#define PCP_SRC11_SRR            0x00002000

// PCP Service Request Control Register 2
#define PCP_SRC2               (*((uword volatile *) 0xF0043FF4))
#define PCP_SRC2_SRE             0x00001000
#define PCP_SRC2_SRR             0x00002000

// PCP Service Request Control Register 3
#define PCP_SRC3               (*((uword volatile *) 0xF0043FF0))
#define PCP_SRC3_SRE             0x00001000
#define PCP_SRC3_SRR             0x00002000

// PCP Service Request Control Register 4
#define PCP_SRC4               (*((uword volatile *) 0xF0043FEC))
#define PCP_SRC4_SRE             0x00001000
#define PCP_SRC4_SRR             0x00002000

// PCP Service Request Control Register 5
#define PCP_SRC5               (*((uword volatile *) 0xF0043FE8))
#define PCP_SRC5_SRE             0x00001000
#define PCP_SRC5_SRR             0x00002000

// PCP Service Request Control Register 6
#define PCP_SRC6               (*((uword volatile *) 0xF0043FE4))
#define PCP_SRC6_SRE             0x00001000
#define PCP_SRC6_SRR             0x00002000

// PCP Service Request Control Register 7
#define PCP_SRC7               (*((uword volatile *) 0xF0043FE0))
#define PCP_SRC7_SRE             0x00001000
#define PCP_SRC7_SRR             0x00002000

// PCP Service Request Control Register 8
#define PCP_SRC8               (*((uword volatile *) 0xF0043FDC))
#define PCP_SRC8_SRE             0x00001000
#define PCP_SRC8_SRR             0x00002000

// PCP Service Request Control Register 9
#define PCP_SRC9               (*((uword volatile *) 0xF0043FD8))
#define PCP_SRC9_RRQ             0x10000000
#define PCP_SRC9_SRE             0x00001000
#define PCP_SRC9_SRR             0x00002000

// PCP Stall Status Register
#define PCP_SSR                (*((uword volatile *) 0xF0043F2C))
#define PCP_SSR_ST               0x00008000

// Previous Context Pointer
#define PCX                    (*((uword volatile *) 0xF7E1FE00))
#define PCX_PIE                  0x00800000
#define PCX_UL                   0x00400000

// Previous Context Information Register
#define PCXI                   (*((uword volatile *) 0xF7E1FE00))
#define PCXI_PIE                 0x00800000
#define PCXI_UL                  0x00400000

// Program Integrity Error Address Register
#define PIEAR                  (*((uword volatile *) 0xF7E19210))

// Program Integrity Error Trap Register
#define PIETR                  (*((uword volatile *) 0xF7E19214))
#define PIETR_IE_B               0x00000010
#define PIETR_IE_C               0x00000004
#define PIETR_IE_S               0x00000008
#define PIETR_IE_T               0x00000002
#define PIETR_IED                0x00000001

// PMI Control Register 0
#define PMI_CON0               (*((uword volatile *) 0xF87FFD10))
#define PMI_CON0_PCBYP           0x00000002

// PMI Control Register 1
#define PMI_CON1               (*((uword volatile *) 0xF87FFD14))
#define PMI_CON1_PBINV           0x00000002
#define PMI_CON1_PCINV           0x00000001

// PMI Control Register 2
#define PMI_CON2               (*((uword volatile *) 0xF87FFD18))

// PMI Identification Register
#define PMI_ID                 (*((uword volatile *) 0xF87FFD08))

// PMI Synchronous Trap Register
#define PMI_STR                (*((uword volatile *) 0xF87FFD20))
#define PMI_STR_FBESTF           0x00000004
#define PMI_STR_FMESTF           0x00004000
#define PMI_STR_FPESTF           0x00001000
#define PMI_STR_FRESTF           0x00000001

// PMU0 Identification Register
#define PMU0_ID                (*((uword volatile *) 0xF8000508))

// Overlay RAM Control Register
#define PMU0_OVRCON            (*((uword volatile *) 0xF8000520))
#define PMU0_OVRCON_OLDAEN       0x00000001
#define PMU0_OVRCON_PB0ERR       0x00004000
#define PMU0_OVRCON_PB0R         0x00001000
#define PMU0_OVRCON_PB0W         0x00000400
#define PMU0_OVRCON_PB1ERR       0x00008000
#define PMU0_OVRCON_PB1R         0x00002000
#define PMU0_OVRCON_PB1W         0x00000800
#define PMU0_OVRCON_PEREN        0x00000200
#define PMU0_OVRCON_POLDAEN      0x00000002
#define PMU0_OVRCON_PPERCTR      0x00000100

// Program Status Word
#define PSW                    (*((uword volatile *) 0xF7E1FE04))
#define PSW_AV                   0x10000000
#define PSW_C                    0x80000000
#define PSW_CDE                  0x00000080
#define PSW_FX                   0x04000000
#define PSW_GW                   0x00000100
#define PSW_IS                   0x00000200
#define PSW_SAV                  0x08000000
#define PSW_SV                   0x20000000
#define PSW_V                    0x40000000

// SBCU Control Register
#define SBCU_CON               (*((uword volatile *) 0xF0000110))
#define SBCU_CON_DBG             ((T_Reg32 *) 0xF0000110)->bit16
#define SBCU_CON_SPE             ((T_Reg32 *) 0xF0000110)->bit19

// SBCU Debug Address 1 Register
#define SBCU_DBADR1            (*((uword volatile *) 0xF0000138))

// SBCU Debug Address 2 Register
#define SBCU_DBADR2            (*((uword volatile *) 0xF000013C))

// SBCU Debug Trapped Address Register
#define SBCU_DBADRT            (*((uword volatile *) 0xF0000148))

// SBCU Debug Bus Operation Signals Register
#define SBCU_DBBOS             (*((uword volatile *) 0xF0000140))
#define SBCU_DBBOS_RD            ((T_Reg32 *) 0xF0000140)->bit12
#define SBCU_DBBOS_SVM           ((T_Reg32 *) 0xF0000140)->bit4
#define SBCU_DBBOS_WR            ((T_Reg32 *) 0xF0000140)->bit8

// SBCU Debug Trapped Bus Operation Signals Register
#define SBCU_DBBOST            (*((uword volatile *) 0xF000014C))
#define SBCU_DBBOST_FPIABORT     ((T_Reg32 *) 0xF000014C)->bit13
#define SBCU_DBBOST_FPIOPS       ((T_Reg32 *) 0xF000014C)->bit11
#define SBCU_DBBOST_FPIRD        ((T_Reg32 *) 0xF000014C)->bit12
#define SBCU_DBBOST_FPIRDY       ((T_Reg32 *) 0xF000014C)->bit7
#define SBCU_DBBOST_FPISVM       ((T_Reg32 *) 0xF000014C)->bit4
#define SBCU_DBBOST_FPITOUT      ((T_Reg32 *) 0xF000014C)->bit14
#define SBCU_DBBOST_FPIWR        ((T_Reg32 *) 0xF000014C)->bit8

// SBCU Debug Control Register
#define SBCU_DBCNTL            (*((uword volatile *) 0xF0000130))
#define SBCU_DBCNTL_CONCOM0      ((T_Reg32 *) 0xF0000130)->bit12
#define SBCU_DBCNTL_CONCOM1      ((T_Reg32 *) 0xF0000130)->bit13
#define SBCU_DBCNTL_CONCOM2      ((T_Reg32 *) 0xF0000130)->bit14
#define SBCU_DBCNTL_EO           ((T_Reg32 *) 0xF0000130)->bit0
#define SBCU_DBCNTL_OA           ((T_Reg32 *) 0xF0000130)->bit1
#define SBCU_DBCNTL_ONBOS0       ((T_Reg32 *) 0xF0000130)->bit28
#define SBCU_DBCNTL_ONBOS1       ((T_Reg32 *) 0xF0000130)->bit29
#define SBCU_DBCNTL_ONBOS2       ((T_Reg32 *) 0xF0000130)->bit30
#define SBCU_DBCNTL_ONBOS3       ((T_Reg32 *) 0xF0000130)->bit31
#define SBCU_DBCNTL_ONG          ((T_Reg32 *) 0xF0000130)->bit16
#define SBCU_DBCNTL_RA           ((T_Reg32 *) 0xF0000130)->bit4

// SBCU Debug Data Status Register
#define SBCU_DBDAT             (*((uword volatile *) 0xF0000150))

// SBCU Debug Trapped Master Register
#define SBCU_DBGNTT            (*((uword volatile *) 0xF0000144))
#define SBCU_DBGNTT_CHNR00       ((T_Reg32 *) 0xF0000144)->bit16
#define SBCU_DBGNTT_CHNR01       ((T_Reg32 *) 0xF0000144)->bit17
#define SBCU_DBGNTT_CHNR02       ((T_Reg32 *) 0xF0000144)->bit18
#define SBCU_DBGNTT_CHNR03       ((T_Reg32 *) 0xF0000144)->bit19
#define SBCU_DBGNTT_CHNR04       ((T_Reg32 *) 0xF0000144)->bit20
#define SBCU_DBGNTT_CHNR05       ((T_Reg32 *) 0xF0000144)->bit21
#define SBCU_DBGNTT_CHNR06       ((T_Reg32 *) 0xF0000144)->bit22
#define SBCU_DBGNTT_CHNR07       ((T_Reg32 *) 0xF0000144)->bit23
#define SBCU_DBGNTT_DMAH         ((T_Reg32 *) 0xF0000144)->bit0
#define SBCU_DBGNTT_DMAL         ((T_Reg32 *) 0xF0000144)->bit6
#define SBCU_DBGNTT_DMAM         ((T_Reg32 *) 0xF0000144)->bit4
#define SBCU_DBGNTT_LFI          ((T_Reg32 *) 0xF0000144)->bit5
#define SBCU_DBGNTT_PCP          ((T_Reg32 *) 0xF0000144)->bit3

// SBCU Debug Grant Mask Register
#define SBCU_DBGRNT            (*((uword volatile *) 0xF0000134))
#define SBCU_DBGRNT_DMAH         ((T_Reg32 *) 0xF0000134)->bit0
#define SBCU_DBGRNT_DMAL         ((T_Reg32 *) 0xF0000134)->bit6
#define SBCU_DBGRNT_DMAM         ((T_Reg32 *) 0xF0000134)->bit4
#define SBCU_DBGRNT_LFI          ((T_Reg32 *) 0xF0000134)->bit5
#define SBCU_DBGRNT_PCP          ((T_Reg32 *) 0xF0000134)->bit3

// SBCU Error Address Capture Register
#define SBCU_EADD              (*((uword volatile *) 0xF0000124))

// SBCU Error Control Capture Register
#define SBCU_ECON              (*((uword volatile *) 0xF0000120))
#define SBCU_ECON_ABT            ((T_Reg32 *) 0xF0000120)->bit18
#define SBCU_ECON_RDN            ((T_Reg32 *) 0xF0000120)->bit23
#define SBCU_ECON_RDY            ((T_Reg32 *) 0xF0000120)->bit17
#define SBCU_ECON_SVM            ((T_Reg32 *) 0xF0000120)->bit21
#define SBCU_ECON_TOUT           ((T_Reg32 *) 0xF0000120)->bit16
#define SBCU_ECON_WRN            ((T_Reg32 *) 0xF0000120)->bit22

// SBCU Error Data Capture Register
#define SBCU_EDAT              (*((uword volatile *) 0xF0000128))

// Module Identification Register
#define SBCU_ID                (*((uword volatile *) 0xF0000108))

// SBCU Service Request Control Register
#define SBCU_SRC               (*((uword volatile *) 0xF00001FC))
#define SBCU_SRC_CLRR            ((T_Reg32 *) 0xF00001FC)->bit14
#define SBCU_SRC_SETR            ((T_Reg32 *) 0xF00001FC)->bit15
#define SBCU_SRC_SRE             ((T_Reg32 *) 0xF00001FC)->bit12
#define SBCU_SRC_SRR             ((T_Reg32 *) 0xF00001FC)->bit13
#define SBCU_SRC_TOS             ((T_Reg32 *) 0xF00001FC)->bit10

// Application Reset Disable Register
#define SCU_ARSTDIS            (*((uword volatile *) 0xF000055C))
#define SCU_ARSTDIS_STMDIS       ((T_Reg32 *) 0xF000055C)->bit0

// CCU Clock Control Register 0
#define SCU_CCUCON0            (*((uword volatile *) 0xF0000530))
#define SCU_CCUCON0_LCK          ((T_Reg32 *) 0xF0000530)->bit31

// CCU Clock Control Register 1
#define SCU_CCUCON1            (*((uword volatile *) 0xF0000534))
#define SCU_CCUCON1_LCK          ((T_Reg32 *) 0xF0000534)->bit31

// Chip Identification Register
#define SCU_CHIPID             (*((uword volatile *) 0xF0000640))
#define SCU_CHIPID_EEA           ((T_Reg32 *) 0xF0000640)->bit16

// Die Temperature Sensor Status Register
#define SCU_DTSSTAT            (*((uword volatile *) 0xF00005E0))
#define SCU_DTSSTAT_BUSY         ((T_Reg32 *) 0xF00005E0)->bit15
#define SCU_DTSSTAT_RDY          ((T_Reg32 *) 0xF00005E0)->bit14

// External Input Channel Register 0
#define SCU_EICR0              (*((uword volatile *) 0xF0000580))
#define SCU_EICR0_EIEN0          ((T_Reg32 *) 0xF0000580)->bit11
#define SCU_EICR0_EIEN1          ((T_Reg32 *) 0xF0000580)->bit27
#define SCU_EICR0_FEN0           ((T_Reg32 *) 0xF0000580)->bit8
#define SCU_EICR0_FEN1           ((T_Reg32 *) 0xF0000580)->bit24
#define SCU_EICR0_LDEN0          ((T_Reg32 *) 0xF0000580)->bit10
#define SCU_EICR0_LDEN1          ((T_Reg32 *) 0xF0000580)->bit26
#define SCU_EICR0_REN0           ((T_Reg32 *) 0xF0000580)->bit9
#define SCU_EICR0_REN1           ((T_Reg32 *) 0xF0000580)->bit25

// External Input Channel Register 1
#define SCU_EICR1              (*((uword volatile *) 0xF0000584))
#define SCU_EICR1_EIEN2          ((T_Reg32 *) 0xF0000584)->bit11
#define SCU_EICR1_EIEN3          ((T_Reg32 *) 0xF0000584)->bit27
#define SCU_EICR1_FEN2           ((T_Reg32 *) 0xF0000584)->bit8
#define SCU_EICR1_FEN3           ((T_Reg32 *) 0xF0000584)->bit24
#define SCU_EICR1_LDEN2          ((T_Reg32 *) 0xF0000584)->bit10
#define SCU_EICR1_LDEN3          ((T_Reg32 *) 0xF0000584)->bit26
#define SCU_EICR1_REN2           ((T_Reg32 *) 0xF0000584)->bit9
#define SCU_EICR1_REN3           ((T_Reg32 *) 0xF0000584)->bit25

// External Input Flag Register
#define SCU_EIFR               (*((uword volatile *) 0xF0000588))
#define SCU_EIFR_INTF0           ((T_Reg32 *) 0xF0000588)->bit0
#define SCU_EIFR_INTF1           ((T_Reg32 *) 0xF0000588)->bit1
#define SCU_EIFR_INTF2           ((T_Reg32 *) 0xF0000588)->bit2
#define SCU_EIFR_INTF3           ((T_Reg32 *) 0xF0000588)->bit3

// Emergency Stop Register
#define SCU_EMSR               (*((uword volatile *) 0xF0000600))
#define SCU_EMSR_EMSF            ((T_Reg32 *) 0xF0000600)->bit16
#define SCU_EMSR_ENON            ((T_Reg32 *) 0xF0000600)->bit2
#define SCU_EMSR_MODE            ((T_Reg32 *) 0xF0000600)->bit1
#define SCU_EMSR_POL             ((T_Reg32 *) 0xF0000600)->bit0

// ESR0 Configuration Register
#define SCU_ESRCFG0            (*((uword volatile *) 0xF0000570))
#define SCU_ESRCFG0_DFEN         ((T_Reg32 *) 0xF0000570)->bit4

// ESR1 Configuration Register
#define SCU_ESRCFG1            (*((uword volatile *) 0xF0000574))
#define SCU_ESRCFG1_DFEN         ((T_Reg32 *) 0xF0000574)->bit4

// ESR2 Configuration Register
#define SCU_ESRCFG2            (*((uword volatile *) 0xF0000578))
#define SCU_ESRCFG2_DFEN         ((T_Reg32 *) 0xF0000578)->bit4

// External Clock Control Register
#define SCU_EXTCON             (*((uword volatile *) 0xF000053C))
#define SCU_EXTCON_EN0           ((T_Reg32 *) 0xF000053C)->bit0
#define SCU_EXTCON_EN1           ((T_Reg32 *) 0xF000053C)->bit16
#define SCU_EXTCON_GPTAINSEL     ((T_Reg32 *) 0xF000053C)->bit6
#define SCU_EXTCON_NSEL          ((T_Reg32 *) 0xF000053C)->bit17

// Fractional Divider Register
#define SCU_FDR                (*((uword volatile *) 0xF0000538))
#define SCU_FDR_DISCLK           ((T_Reg32 *) 0xF0000538)->bit31

// Flag Modification Register
#define SCU_FMR                (*((uword volatile *) 0xF000058C))
#define SCU_FMR_FC0              ((T_Reg32 *) 0xF000058C)->bit16
#define SCU_FMR_FC1              ((T_Reg32 *) 0xF000058C)->bit17
#define SCU_FMR_FC2              ((T_Reg32 *) 0xF000058C)->bit18
#define SCU_FMR_FC3              ((T_Reg32 *) 0xF000058C)->bit19
#define SCU_FMR_FS0              ((T_Reg32 *) 0xF000058C)->bit0
#define SCU_FMR_FS1              ((T_Reg32 *) 0xF000058C)->bit1
#define SCU_FMR_FS2              ((T_Reg32 *) 0xF000058C)->bit2
#define SCU_FMR_FS3              ((T_Reg32 *) 0xF000058C)->bit3

// Identification Register
#define SCU_ID                 (*((uword volatile *) 0xF0000508))

// Interrupt Gating Register 0
#define SCU_IGCR0              (*((uword volatile *) 0xF0000594))
#define SCU_IGCR0_GEEN0          ((T_Reg32 *) 0xF0000594)->bit13
#define SCU_IGCR0_GEEN1          ((T_Reg32 *) 0xF0000594)->bit29
#define SCU_IGCR0_IPEN00         ((T_Reg32 *) 0xF0000594)->bit0
#define SCU_IGCR0_IPEN01         ((T_Reg32 *) 0xF0000594)->bit1
#define SCU_IGCR0_IPEN02         ((T_Reg32 *) 0xF0000594)->bit2
#define SCU_IGCR0_IPEN03         ((T_Reg32 *) 0xF0000594)->bit3
#define SCU_IGCR0_IPEN10         ((T_Reg32 *) 0xF0000594)->bit16
#define SCU_IGCR0_IPEN11         ((T_Reg32 *) 0xF0000594)->bit17
#define SCU_IGCR0_IPEN12         ((T_Reg32 *) 0xF0000594)->bit18
#define SCU_IGCR0_IPEN13         ((T_Reg32 *) 0xF0000594)->bit19

// Interrupt Gating Register 1
#define SCU_IGCR1              (*((uword volatile *) 0xF0000598))
#define SCU_IGCR1_GEEN2          ((T_Reg32 *) 0xF0000598)->bit13
#define SCU_IGCR1_GEEN3          ((T_Reg32 *) 0xF0000598)->bit29
#define SCU_IGCR1_IPEN20         ((T_Reg32 *) 0xF0000598)->bit0
#define SCU_IGCR1_IPEN21         ((T_Reg32 *) 0xF0000598)->bit1
#define SCU_IGCR1_IPEN22         ((T_Reg32 *) 0xF0000598)->bit2
#define SCU_IGCR1_IPEN23         ((T_Reg32 *) 0xF0000598)->bit3
#define SCU_IGCR1_IPEN30         ((T_Reg32 *) 0xF0000598)->bit16
#define SCU_IGCR1_IPEN31         ((T_Reg32 *) 0xF0000598)->bit17
#define SCU_IGCR1_IPEN32         ((T_Reg32 *) 0xF0000598)->bit18
#define SCU_IGCR1_IPEN33         ((T_Reg32 *) 0xF0000598)->bit19

// Input Register
#define SCU_IN                 (*((uword volatile *) 0xF00005AC))
#define SCU_IN_P0                ((T_Reg32 *) 0xF00005AC)->bit0
#define SCU_IN_P1                ((T_Reg32 *) 0xF00005AC)->bit1

// Interrupt Clear Register
#define SCU_INTCLR             (*((uword volatile *) 0xF0000618))
#define SCU_INTCLR_DTSI          ((T_Reg32 *) 0xF0000618)->bit7
#define SCU_INTCLR_ERUI0         ((T_Reg32 *) 0xF0000618)->bit1
#define SCU_INTCLR_ERUI1         ((T_Reg32 *) 0xF0000618)->bit2
#define SCU_INTCLR_ERUI2         ((T_Reg32 *) 0xF0000618)->bit3
#define SCU_INTCLR_ERUI3         ((T_Reg32 *) 0xF0000618)->bit4
#define SCU_INTCLR_FL0I          ((T_Reg32 *) 0xF0000618)->bit5
#define SCU_INTCLR_WDTI          ((T_Reg32 *) 0xF0000618)->bit0

// Interrupt Disable Register
#define SCU_INTDIS             (*((uword volatile *) 0xF000061C))
#define SCU_INTDIS_DTSI          ((T_Reg32 *) 0xF000061C)->bit7
#define SCU_INTDIS_ERUI0         ((T_Reg32 *) 0xF000061C)->bit1
#define SCU_INTDIS_ERUI1         ((T_Reg32 *) 0xF000061C)->bit2
#define SCU_INTDIS_ERUI2         ((T_Reg32 *) 0xF000061C)->bit3
#define SCU_INTDIS_ERUI3         ((T_Reg32 *) 0xF000061C)->bit4
#define SCU_INTDIS_FL0I          ((T_Reg32 *) 0xF000061C)->bit5
#define SCU_INTDIS_WDTI          ((T_Reg32 *) 0xF000061C)->bit0

// Interrupt Node Pointer Register
#define SCU_INTNP              (*((uword volatile *) 0xF0000620))

// Interrupt Set Register
#define SCU_INTSET             (*((uword volatile *) 0xF0000614))
#define SCU_INTSET_DTSI          ((T_Reg32 *) 0xF0000614)->bit7
#define SCU_INTSET_ERUI0         ((T_Reg32 *) 0xF0000614)->bit1
#define SCU_INTSET_ERUI1         ((T_Reg32 *) 0xF0000614)->bit2
#define SCU_INTSET_ERUI2         ((T_Reg32 *) 0xF0000614)->bit3
#define SCU_INTSET_ERUI3         ((T_Reg32 *) 0xF0000614)->bit4
#define SCU_INTSET_FL0I          ((T_Reg32 *) 0xF0000614)->bit5
#define SCU_INTSET_WDTI          ((T_Reg32 *) 0xF0000614)->bit0

// Interrupt Status Register
#define SCU_INTSTAT            (*((uword volatile *) 0xF0000610))
#define SCU_INTSTAT_DTSI         ((T_Reg32 *) 0xF0000610)->bit7
#define SCU_INTSTAT_ERUI0        ((T_Reg32 *) 0xF0000610)->bit1
#define SCU_INTSTAT_ERUI1        ((T_Reg32 *) 0xF0000610)->bit2
#define SCU_INTSTAT_ERUI2        ((T_Reg32 *) 0xF0000610)->bit3
#define SCU_INTSTAT_ERUI3        ((T_Reg32 *) 0xF0000610)->bit4
#define SCU_INTSTAT_FL0I         ((T_Reg32 *) 0xF0000610)->bit5
#define SCU_INTSTAT_WDTI         ((T_Reg32 *) 0xF0000610)->bit0

// Input/Output Control Register
#define SCU_IOCR               (*((uword volatile *) 0xF00005A0))

// Manufacturer Identification Register
#define SCU_MANID              (*((uword volatile *) 0xF0000644))

// Output Modification Register
#define SCU_OMR                (*((uword volatile *) 0xF00005A8))
#define SCU_OMR_PR0              ((T_Reg32 *) 0xF00005A8)->bit16
#define SCU_OMR_PR1              ((T_Reg32 *) 0xF00005A8)->bit17
#define SCU_OMR_PS0              ((T_Reg32 *) 0xF00005A8)->bit0
#define SCU_OMR_PS1              ((T_Reg32 *) 0xF00005A8)->bit1

// OSC Control Register
#define SCU_OSCCON             (*((uword volatile *) 0xF0000510))
#define SCU_OSCCON_OSCRES        ((T_Reg32 *) 0xF0000510)->bit2
#define SCU_OSCCON_PLLHV         ((T_Reg32 *) 0xF0000510)->bit8
#define SCU_OSCCON_PLLLV         ((T_Reg32 *) 0xF0000510)->bit1
#define SCU_OSCCON_PLLSP         ((T_Reg32 *) 0xF0000510)->bit9
#define SCU_OSCCON_SHBY          ((T_Reg32 *) 0xF0000510)->bit7
#define SCU_OSCCON_X1D           ((T_Reg32 *) 0xF0000510)->bit10
#define SCU_OSCCON_X1DEN         ((T_Reg32 *) 0xF0000510)->bit11

// Output Register
#define SCU_OUT                (*((uword volatile *) 0xF00005A4))
#define SCU_OUT_P0               ((T_Reg32 *) 0xF00005A4)->bit0
#define SCU_OUT_P1               ((T_Reg32 *) 0xF00005A4)->bit1

// Pattern Detection Result Register
#define SCU_PDRR               (*((uword volatile *) 0xF0000590))
#define SCU_PDRR_PDR0            ((T_Reg32 *) 0xF0000590)->bit0
#define SCU_PDRR_PDR1            ((T_Reg32 *) 0xF0000590)->bit1
#define SCU_PDRR_PDR2            ((T_Reg32 *) 0xF0000590)->bit2
#define SCU_PDRR_PDR3            ((T_Reg32 *) 0xF0000590)->bit3

// Parity Error Trap Status Register
#define SCU_PETSR              (*((uword volatile *) 0xF00005D4))
#define SCU_PETSR_PFLCAN         ((T_Reg32 *) 0xF00005D4)->bit7
#define SCU_PETSR_PFLCMEM        ((T_Reg32 *) 0xF00005D4)->bit6
#define SCU_PETSR_PFLDTAG        ((T_Reg32 *) 0xF00005D4)->bit1
#define SCU_PETSR_PFLLDRAM       ((T_Reg32 *) 0xF00005D4)->bit0
#define SCU_PETSR_PFLPMU         ((T_Reg32 *) 0xF00005D4)->bit4
#define SCU_PETSR_PFLPRAM        ((T_Reg32 *) 0xF00005D4)->bit5
#define SCU_PETSR_PFLPTAG        ((T_Reg32 *) 0xF00005D4)->bit3
#define SCU_PETSR_PFLSPRAM       ((T_Reg32 *) 0xF00005D4)->bit2

// PLL Configuration 0 Register
#define SCU_PLLCON0            (*((uword volatile *) 0xF0000518))
#define SCU_PLLCON0_CLRFINDIS    ((T_Reg32 *) 0xF0000518)->bit5
#define SCU_PLLCON0_OSCDISCDIS   ((T_Reg32 *) 0xF0000518)->bit6
#define SCU_PLLCON0_PLLPWD       ((T_Reg32 *) 0xF0000518)->bit16
#define SCU_PLLCON0_RESLD        ((T_Reg32 *) 0xF0000518)->bit18
#define SCU_PLLCON0_SETFINDIS    ((T_Reg32 *) 0xF0000518)->bit4
#define SCU_PLLCON0_VCOBYP       ((T_Reg32 *) 0xF0000518)->bit0
#define SCU_PLLCON0_VCOPWD       ((T_Reg32 *) 0xF0000518)->bit1

// PLL Configuration 1 Register
#define SCU_PLLCON1            (*((uword volatile *) 0xF000051C))

// PLL Status Register
#define SCU_PLLSTAT            (*((uword volatile *) 0xF0000514))
#define SCU_PLLSTAT_FINDIS       ((T_Reg32 *) 0xF0000514)->bit3
#define SCU_PLLSTAT_K1RDY        ((T_Reg32 *) 0xF0000514)->bit4
#define SCU_PLLSTAT_PWDSTAT      ((T_Reg32 *) 0xF0000514)->bit1
#define SCU_PLLSTAT_VCOBYST      ((T_Reg32 *) 0xF0000514)->bit0
#define SCU_PLLSTAT_VCOLOCK      ((T_Reg32 *) 0xF0000514)->bit2

// Power Management Control and Status Register
#define SCU_PMCSR              (*((uword volatile *) 0xF00005B0))

// Reset Counter Control Register
#define SCU_RSTCNTCON          (*((uword volatile *) 0xF0000554))

// Reset Configuration Register
#define SCU_RSTCON             (*((uword volatile *) 0xF0000558))

// Reset Status Register
#define SCU_RSTSTAT            (*((uword volatile *) 0xF0000550))
#define SCU_RSTSTAT_CB0          ((T_Reg32 *) 0xF0000550)->bit18
#define SCU_RSTSTAT_CB1          ((T_Reg32 *) 0xF0000550)->bit19
#define SCU_RSTSTAT_CB3          ((T_Reg32 *) 0xF0000550)->bit20
#define SCU_RSTSTAT_ESR0         ((T_Reg32 *) 0xF0000550)->bit0
#define SCU_RSTSTAT_ESR1         ((T_Reg32 *) 0xF0000550)->bit1
#define SCU_RSTSTAT_OCDS         ((T_Reg32 *) 0xF0000550)->bit17
#define SCU_RSTSTAT_PORST        ((T_Reg32 *) 0xF0000550)->bit16
#define SCU_RSTSTAT_SW           ((T_Reg32 *) 0xF0000550)->bit4
#define SCU_RSTSTAT_TP           ((T_Reg32 *) 0xF0000550)->bit21
#define SCU_RSTSTAT_WDT          ((T_Reg32 *) 0xF0000550)->bit3

// Service Request Control 0 Register
#define SCU_SRC0               (*((uword volatile *) 0xF00006FC))
#define SCU_SRC0_CLRR            ((T_Reg32 *) 0xF00006FC)->bit14
#define SCU_SRC0_SETR            ((T_Reg32 *) 0xF00006FC)->bit15
#define SCU_SRC0_SRE             ((T_Reg32 *) 0xF00006FC)->bit12
#define SCU_SRC0_SRR             ((T_Reg32 *) 0xF00006FC)->bit13
#define SCU_SRC0_TOS             ((T_Reg32 *) 0xF00006FC)->bit10

// Service Request Control 1 Register
#define SCU_SRC1               (*((uword volatile *) 0xF00006F8))
#define SCU_SRC1_CLRR            ((T_Reg32 *) 0xF00006F8)->bit14
#define SCU_SRC1_SETR            ((T_Reg32 *) 0xF00006F8)->bit15
#define SCU_SRC1_SRE             ((T_Reg32 *) 0xF00006F8)->bit12
#define SCU_SRC1_SRR             ((T_Reg32 *) 0xF00006F8)->bit13
#define SCU_SRC1_TOS             ((T_Reg32 *) 0xF00006F8)->bit10

// Service Request Control 2 Register
#define SCU_SRC2               (*((uword volatile *) 0xF00006F4))
#define SCU_SRC2_CLRR            ((T_Reg32 *) 0xF00006F4)->bit14
#define SCU_SRC2_SETR            ((T_Reg32 *) 0xF00006F4)->bit15
#define SCU_SRC2_SRE             ((T_Reg32 *) 0xF00006F4)->bit12
#define SCU_SRC2_SRR             ((T_Reg32 *) 0xF00006F4)->bit13
#define SCU_SRC2_TOS             ((T_Reg32 *) 0xF00006F4)->bit10

// Service Request Control 3 Register
#define SCU_SRC3               (*((uword volatile *) 0xF00006F0))
#define SCU_SRC3_CLRR            ((T_Reg32 *) 0xF00006F0)->bit14
#define SCU_SRC3_SETR            ((T_Reg32 *) 0xF00006F0)->bit15
#define SCU_SRC3_SRE             ((T_Reg32 *) 0xF00006F0)->bit12
#define SCU_SRC3_SRR             ((T_Reg32 *) 0xF00006F0)->bit13
#define SCU_SRC3_TOS             ((T_Reg32 *) 0xF00006F0)->bit10

// Start-up Configuration Register
#define SCU_STCON              (*((uword volatile *) 0xF00005C4))
#define SCU_STCON_CFCBAE         ((T_Reg32 *) 0xF00005C4)->bit14
#define SCU_STCON_SFCBAE         ((T_Reg32 *) 0xF00005C4)->bit13
#define SCU_STCON_STP            ((T_Reg32 *) 0xF00005C4)->bit15

// Start-up Status Register
#define SCU_STSTAT             (*((uword volatile *) 0xF00005C0))
#define SCU_STSTAT_EXTBEN        ((T_Reg32 *) 0xF00005C0)->bit18
#define SCU_STSTAT_FCBAE         ((T_Reg32 *) 0xF00005C0)->bit16
#define SCU_STSTAT_LUDIS         ((T_Reg32 *) 0xF00005C0)->bit17
#define SCU_STSTAT_MODE          ((T_Reg32 *) 0xF00005C0)->bit15
#define SCU_STSTAT_TRSTL         ((T_Reg32 *) 0xF00005C0)->bit19

// Software Reset Configuration Register
#define SCU_SWRSTCON           (*((uword volatile *) 0xF0000560))
#define SCU_SWRSTCON_SWBOOT      ((T_Reg32 *) 0xF0000560)->bit0
#define SCU_SWRSTCON_SWRSTREQ    ((T_Reg32 *) 0xF0000560)->bit1

// System Control Register
#define SCU_SYSCON             (*((uword volatile *) 0xF0000540))
#define SCU_SYSCON_SETEXTBEN     ((T_Reg32 *) 0xF0000540)->bit5
#define SCU_SYSCON_SETLUDIS      ((T_Reg32 *) 0xF0000540)->bit4

// Trap Clear Register
#define SCU_TRAPCLR            (*((uword volatile *) 0xF000062C))
#define SCU_TRAPCLR_ESR0T        ((T_Reg32 *) 0xF000062C)->bit0
#define SCU_TRAPCLR_ESR1T        ((T_Reg32 *) 0xF000062C)->bit1
#define SCU_TRAPCLR_OSCHWDTT     ((T_Reg32 *) 0xF000062C)->bit6
#define SCU_TRAPCLR_OSCLWDTT     ((T_Reg32 *) 0xF000062C)->bit5
#define SCU_TRAPCLR_OSCSPWDTT    ((T_Reg32 *) 0xF000062C)->bit7
#define SCU_TRAPCLR_PET          ((T_Reg32 *) 0xF000062C)->bit4
#define SCU_TRAPCLR_SYSVCOLCKT   ((T_Reg32 *) 0xF000062C)->bit8
#define SCU_TRAPCLR_WDTT         ((T_Reg32 *) 0xF000062C)->bit3

// Trap Disable Register
#define SCU_TRAPDIS            (*((uword volatile *) 0xF0000630))
#define SCU_TRAPDIS_ESR0T        ((T_Reg32 *) 0xF0000630)->bit0
#define SCU_TRAPDIS_ESR1T        ((T_Reg32 *) 0xF0000630)->bit1
#define SCU_TRAPDIS_OSCHWDTT     ((T_Reg32 *) 0xF0000630)->bit6
#define SCU_TRAPDIS_OSCLWDTT     ((T_Reg32 *) 0xF0000630)->bit5
#define SCU_TRAPDIS_OSCSPWDTT    ((T_Reg32 *) 0xF0000630)->bit7
#define SCU_TRAPDIS_PET          ((T_Reg32 *) 0xF0000630)->bit4
#define SCU_TRAPDIS_SYSVCOLCKT   ((T_Reg32 *) 0xF0000630)->bit8
#define SCU_TRAPDIS_WDTT         ((T_Reg32 *) 0xF0000630)->bit3

// Trap Set Register
#define SCU_TRAPSET            (*((uword volatile *) 0xF0000628))
#define SCU_TRAPSET_ESR0T        ((T_Reg32 *) 0xF0000628)->bit0
#define SCU_TRAPSET_ESR1T        ((T_Reg32 *) 0xF0000628)->bit1
#define SCU_TRAPSET_OSCHWDTT     ((T_Reg32 *) 0xF0000628)->bit6
#define SCU_TRAPSET_OSCLWDTT     ((T_Reg32 *) 0xF0000628)->bit5
#define SCU_TRAPSET_OSCSPWDTT    ((T_Reg32 *) 0xF0000628)->bit7
#define SCU_TRAPSET_PET          ((T_Reg32 *) 0xF0000628)->bit4
#define SCU_TRAPSET_SYSVCOLCKT   ((T_Reg32 *) 0xF0000628)->bit8
#define SCU_TRAPSET_WDTT         ((T_Reg32 *) 0xF0000628)->bit3

// Trap Status Register
#define SCU_TRAPSTAT           (*((uword volatile *) 0xF0000624))
#define SCU_TRAPSTAT_ESR0T       ((T_Reg32 *) 0xF0000624)->bit0
#define SCU_TRAPSTAT_ESR1T       ((T_Reg32 *) 0xF0000624)->bit1
#define SCU_TRAPSTAT_OSCHWDTT    ((T_Reg32 *) 0xF0000624)->bit6
#define SCU_TRAPSTAT_OSCLWDTT    ((T_Reg32 *) 0xF0000624)->bit5
#define SCU_TRAPSTAT_OSCSPWDTT   ((T_Reg32 *) 0xF0000624)->bit7
#define SCU_TRAPSTAT_PET         ((T_Reg32 *) 0xF0000624)->bit4
#define SCU_TRAPSTAT_SYSVCOLCKT  ((T_Reg32 *) 0xF0000624)->bit8
#define SCU_TRAPSTAT_WDTT        ((T_Reg32 *) 0xF0000624)->bit3

// SIST Mode Access Control Register
#define SMACON                 (*((uword volatile *) 0xF7E1900C))
#define SMACON_IODT              0x01000000

// SSC0 Baud Rate Timer Reload Register
#define SSC0_BR                (*((uword volatile *) 0xF0100114))

// SSC0 Clock Control Register
#define SSC0_CLC               (*((uword volatile *) 0xF0100100))
#define SSC0_CLC_DISR            0x00000001
#define SSC0_CLC_DISS            0x00000002
#define SSC0_CLC_EDIS            0x00000008
#define SSC0_CLC_FSOE            0x00000020
#define SSC0_CLC_SBWE            0x00000010
#define SSC0_CLC_SPEN            0x00000004

// SSC0 Control Register
#define SSC0_CON               (*((uword volatile *) 0xF0100110))
#define SSC0_CON_AREN            0x00001000
#define SSC0_CON_BEN             0x00000800
#define SSC0_CON_EN              0x00008000
#define SSC0_CON_HB              0x00000010
#define SSC0_CON_LB              0x00000080
#define SSC0_CON_MS              0x00004000
#define SSC0_CON_PEN             0x00000400
#define SSC0_CON_PH              0x00000020
#define SSC0_CON_PO              0x00000040
#define SSC0_CON_REN             0x00000200
#define SSC0_CON_TEN             0x00000100

// SSC0 Error Flag Modification Register
#define SSC0_EFM               (*((uword volatile *) 0xF010012C))
#define SSC0_EFM_CLRBE           0x00000800
#define SSC0_EFM_CLRPE           0x00000400
#define SSC0_EFM_CLRRE           0x00000200
#define SSC0_EFM_CLRTE           0x00000100
#define SSC0_EFM_SETBE           0x00008000
#define SSC0_EFM_SETPE           0x00004000
#define SSC0_EFM_SETRE           0x00002000
#define SSC0_EFM_SETTE           0x00001000

// SSC0 Error Interrupt Service Request Control Register
#define SSC0_ESRC              (*((uword volatile *) 0xF01001FC))
#define SSC0_ESRC_CLRR           0x00004000
#define SSC0_ESRC_SETR           0x00008000
#define SSC0_ESRC_SRE            0x00001000
#define SSC0_ESRC_SRR            0x00002000
#define SSC0_ESRC_TOS            0x00000400

// SSC0 Fractional Divider Register
#define SSC0_FDR               (*((uword volatile *) 0xF010010C))
#define SSC0_FDR_DISCLK          0x80000000
#define SSC0_FDR_ENHW            0x40000000
#define SSC0_FDR_SM              0x00000800
#define SSC0_FDR_SUSACK          0x10000000
#define SSC0_FDR_SUSREQ          0x20000000

// SSC0 Module Identification Register
#define SSC0_ID                (*((uword volatile *) 0xF0100108))

// SSC0 Port Input Select Register
#define SSC0_PISEL             (*((uword volatile *) 0xF0100104))
#define SSC0_PISEL_MRIS          0x00000001
#define SSC0_PISEL_SCIS          0x00000004
#define SSC0_PISEL_SRIS          0x00000002
#define SSC0_PISEL_STIP          0x00000100

// SSC0 Receive Buffer Register
#define SSC0_RB                (*((uword volatile *) 0xF0100124))

// SSC0 Receive Interrupt Service Request Control Register
#define SSC0_RSRC              (*((uword volatile *) 0xF01001F8))
#define SSC0_RSRC_CLRR           0x00004000
#define SSC0_RSRC_SETR           0x00008000
#define SSC0_RSRC_SRE            0x00001000
#define SSC0_RSRC_SRR            0x00002000
#define SSC0_RSRC_TOS            0x00000400

// SSC0 Slave Select Output Control Register
#define SSC0_SSOC              (*((uword volatile *) 0xF0100118))
#define SSC0_SSOC_AOL0           0x00000001
#define SSC0_SSOC_AOL1           0x00000002
#define SSC0_SSOC_AOL2           0x00000004
#define SSC0_SSOC_AOL3           0x00000008
#define SSC0_SSOC_AOL4           0x00000010
#define SSC0_SSOC_AOL5           0x00000020
#define SSC0_SSOC_AOL6           0x00000040
#define SSC0_SSOC_AOL7           0x00000080
#define SSC0_SSOC_OEN0           0x00000100
#define SSC0_SSOC_OEN1           0x00000200
#define SSC0_SSOC_OEN2           0x00000400
#define SSC0_SSOC_OEN3           0x00000800
#define SSC0_SSOC_OEN4           0x00001000
#define SSC0_SSOC_OEN5           0x00002000
#define SSC0_SSOC_OEN6           0x00004000
#define SSC0_SSOC_OEN7           0x00008000

// SSC0 Slave Select Output Timing Control Register
#define SSC0_SSOTC             (*((uword volatile *) 0xF010011C))
#define SSC0_SSOTC_SLSO7MOD      0x00000100

// SSC0 Status Register
#define SSC0_STAT              (*((uword volatile *) 0xF0100128))
#define SSC0_STAT_BE             0x00000800
#define SSC0_STAT_BSY            0x00001000
#define SSC0_STAT_PE             0x00000400
#define SSC0_STAT_RE             0x00000200
#define SSC0_STAT_TE             0x00000100

// SSC0 Transmit Buffer Register
#define SSC0_TB                (*((uword volatile *) 0xF0100120))

// SSC0 Transmit Interrupt Service Request Control Register
#define SSC0_TSRC              (*((uword volatile *) 0xF01001F4))
#define SSC0_TSRC_CLRR           0x00004000
#define SSC0_TSRC_SETR           0x00008000
#define SSC0_TSRC_SRE            0x00001000
#define SSC0_TSRC_SRR            0x00002000
#define SSC0_TSRC_TOS            0x00000400

// SSC1 Baud Rate Timer Reload Register
#define SSC1_BR                (*((uword volatile *) 0xF0100214))

// SSC1 Clock Control Register
#define SSC1_CLC               (*((uword volatile *) 0xF0100200))
#define SSC1_CLC_DISR            0x00000001
#define SSC1_CLC_DISS            0x00000002
#define SSC1_CLC_EDIS            0x00000008
#define SSC1_CLC_FSOE            0x00000020
#define SSC1_CLC_SBWE            0x00000010
#define SSC1_CLC_SPEN            0x00000004

// SSC1 Control Register
#define SSC1_CON               (*((uword volatile *) 0xF0100210))
#define SSC1_CON_AREN            0x00001000
#define SSC1_CON_BEN             0x00000800
#define SSC1_CON_EN              0x00008000
#define SSC1_CON_HB              0x00000010
#define SSC1_CON_LB              0x00000080
#define SSC1_CON_MS              0x00004000
#define SSC1_CON_PEN             0x00000400
#define SSC1_CON_PH              0x00000020
#define SSC1_CON_PO              0x00000040
#define SSC1_CON_REN             0x00000200
#define SSC1_CON_TEN             0x00000100

// SSC1 Error Flag Modification Register
#define SSC1_EFM               (*((uword volatile *) 0xF010022C))
#define SSC1_EFM_CLRBE           0x00000800
#define SSC1_EFM_CLRPE           0x00000400
#define SSC1_EFM_CLRRE           0x00000200
#define SSC1_EFM_CLRTE           0x00000100
#define SSC1_EFM_SETBE           0x00008000
#define SSC1_EFM_SETPE           0x00004000
#define SSC1_EFM_SETRE           0x00002000
#define SSC1_EFM_SETTE           0x00001000

// SSC1 Error Interrupt Service Request Control Register
#define SSC1_ESRC              (*((uword volatile *) 0xF01002FC))
#define SSC1_ESRC_CLRR           0x00004000
#define SSC1_ESRC_SETR           0x00008000
#define SSC1_ESRC_SRE            0x00001000
#define SSC1_ESRC_SRR            0x00002000
#define SSC1_ESRC_TOS            0x00000400

// SSC1 Fractional Divider Register
#define SSC1_FDR               (*((uword volatile *) 0xF010020C))
#define SSC1_FDR_DISCLK          0x80000000
#define SSC1_FDR_ENHW            0x40000000
#define SSC1_FDR_SM              0x00000800
#define SSC1_FDR_SUSACK          0x10000000
#define SSC1_FDR_SUSREQ          0x20000000

// SSC1 Module Identification Register
#define SSC1_ID                (*((uword volatile *) 0xF0100208))

// SSC1 Port Input Select Register
#define SSC1_PISEL             (*((uword volatile *) 0xF0100204))
#define SSC1_PISEL_MRIS          0x00000001
#define SSC1_PISEL_SCIS          0x00000004
#define SSC1_PISEL_SRIS          0x00000002
#define SSC1_PISEL_STIP          0x00000100

// SSC1 Receive Buffer Register
#define SSC1_RB                (*((uword volatile *) 0xF0100224))

// SSC1 Receive Interrupt Service Request Control Register
#define SSC1_RSRC              (*((uword volatile *) 0xF01002F8))
#define SSC1_RSRC_CLRR           0x00004000
#define SSC1_RSRC_SETR           0x00008000
#define SSC1_RSRC_SRE            0x00001000
#define SSC1_RSRC_SRR            0x00002000
#define SSC1_RSRC_TOS            0x00000400

// SSC1 Slave Select Output Control Register
#define SSC1_SSOC              (*((uword volatile *) 0xF0100218))
#define SSC1_SSOC_AOL0           0x00000001
#define SSC1_SSOC_AOL1           0x00000002
#define SSC1_SSOC_AOL2           0x00000004
#define SSC1_SSOC_AOL3           0x00000008
#define SSC1_SSOC_AOL4           0x00000010
#define SSC1_SSOC_AOL5           0x00000020
#define SSC1_SSOC_AOL6           0x00000040
#define SSC1_SSOC_AOL7           0x00000080
#define SSC1_SSOC_OEN0           0x00000100
#define SSC1_SSOC_OEN1           0x00000200
#define SSC1_SSOC_OEN2           0x00000400
#define SSC1_SSOC_OEN3           0x00000800
#define SSC1_SSOC_OEN4           0x00001000
#define SSC1_SSOC_OEN5           0x00002000
#define SSC1_SSOC_OEN6           0x00004000
#define SSC1_SSOC_OEN7           0x00008000

// SSC1 Slave Select Output Timing Control Register
#define SSC1_SSOTC             (*((uword volatile *) 0xF010021C))
#define SSC1_SSOTC_SLSO7MOD      0x00000100

// SSC1 Status Register
#define SSC1_STAT              (*((uword volatile *) 0xF0100228))
#define SSC1_STAT_BE             0x00000800
#define SSC1_STAT_BSY            0x00001000
#define SSC1_STAT_PE             0x00000400
#define SSC1_STAT_RE             0x00000200
#define SSC1_STAT_TE             0x00000100

// SSC1 Transmit Buffer Register
#define SSC1_TB                (*((uword volatile *) 0xF0100220))

// SSC1 Transmit Interrupt Service Request Control Register
#define SSC1_TSRC              (*((uword volatile *) 0xF01002F4))
#define SSC1_TSRC_CLRR           0x00004000
#define SSC1_TSRC_SETR           0x00008000
#define SSC1_TSRC_SRE            0x00001000
#define SSC1_TSRC_SRR            0x00002000
#define SSC1_TSRC_TOS            0x00000400

// STM Timer Capture Register
#define STM_CAP                (*((uword volatile *) 0xF000022C))

// STM Clock Control Register
#define STM_CLC                (*((uword volatile *) 0xF0000200))
#define STM_CLC_DISR             ((T_Reg32 *) 0xF0000200)->bit0
#define STM_CLC_DISS             ((T_Reg32 *) 0xF0000200)->bit1
#define STM_CLC_EDIS             ((T_Reg32 *) 0xF0000200)->bit3
#define STM_CLC_FSOE             ((T_Reg32 *) 0xF0000200)->bit5
#define STM_CLC_SBWE             ((T_Reg32 *) 0xF0000200)->bit4
#define STM_CLC_SPEN             ((T_Reg32 *) 0xF0000200)->bit2

// STM Compare Match Control Register
#define STM_CMCON              (*((uword volatile *) 0xF0000238))

// STM Compare Register 0
#define STM_CMP0               (*((uword volatile *) 0xF0000230))

// STM Compare Register 1
#define STM_CMP1               (*((uword volatile *) 0xF0000234))

// STM Interrupt Control Register
#define STM_ICR                (*((uword volatile *) 0xF000023C))
#define STM_ICR_CMP0EN           ((T_Reg32 *) 0xF000023C)->bit0
#define STM_ICR_CMP0IR           ((T_Reg32 *) 0xF000023C)->bit1
#define STM_ICR_CMP0OS           ((T_Reg32 *) 0xF000023C)->bit2
#define STM_ICR_CMP1EN           ((T_Reg32 *) 0xF000023C)->bit4
#define STM_ICR_CMP1IR           ((T_Reg32 *) 0xF000023C)->bit5
#define STM_ICR_CMP1OS           ((T_Reg32 *) 0xF000023C)->bit6

// STM Module Identification Register
#define STM_ID                 (*((uword volatile *) 0xF0000208))

// STM Interrupt Set/Reset Register
#define STM_ISRR               (*((uword volatile *) 0xF0000240))
#define STM_ISRR_CMP0IRR         ((T_Reg32 *) 0xF0000240)->bit0
#define STM_ISRR_CMP0IRS         ((T_Reg32 *) 0xF0000240)->bit1
#define STM_ISRR_CMP1IRR         ((T_Reg32 *) 0xF0000240)->bit2
#define STM_ISRR_CMP1IRS         ((T_Reg32 *) 0xF0000240)->bit3

// STM Service Request Control Register 0
#define STM_SRC0               (*((uword volatile *) 0xF00002FC))
#define STM_SRC0_CLRR            ((T_Reg32 *) 0xF00002FC)->bit14
#define STM_SRC0_SETR            ((T_Reg32 *) 0xF00002FC)->bit15
#define STM_SRC0_SRE             ((T_Reg32 *) 0xF00002FC)->bit12
#define STM_SRC0_SRR             ((T_Reg32 *) 0xF00002FC)->bit13
#define STM_SRC0_TOS             ((T_Reg32 *) 0xF00002FC)->bit10

// STM Service Request Control Register 1
#define STM_SRC1               (*((uword volatile *) 0xF00002F8))
#define STM_SRC1_CLRR            ((T_Reg32 *) 0xF00002F8)->bit14
#define STM_SRC1_SETR            ((T_Reg32 *) 0xF00002F8)->bit15
#define STM_SRC1_SRE             ((T_Reg32 *) 0xF00002F8)->bit12
#define STM_SRC1_SRR             ((T_Reg32 *) 0xF00002F8)->bit13
#define STM_SRC1_TOS             ((T_Reg32 *) 0xF00002F8)->bit10

// STM Timer Register 0
#define STM_TIM0               (*((uword volatile *) 0xF0000210))

// STM Timer Register 1
#define STM_TIM1               (*((uword volatile *) 0xF0000214))

// STM Timer Register 2
#define STM_TIM2               (*((uword volatile *) 0xF0000218))

// STM Timer Register 3
#define STM_TIM3               (*((uword volatile *) 0xF000021C))

// STM Timer Register 4
#define STM_TIM4               (*((uword volatile *) 0xF0000220))

// STM Timer Register 5
#define STM_TIM5               (*((uword volatile *) 0xF0000224))

// STM Timer Register 6
#define STM_TIM6               (*((uword volatile *) 0xF0000228))

// Software Break Event Specifier Register
#define SWEVT                  (*((uword volatile *) 0xF7E1FD10))
#define SWEVT_BBM                0x00000008
#define SWEVT_BOD                0x00000010
#define SWEVT_CSP                0x00000080
#define SWEVT_CST                0x00000040
#define SWEVT_SUSP               0x00000020

// System Configuration Register
#define SYSCON                 (*((uword volatile *) 0xF7E1FE14))
#define SYSCON_FCDSF             0x00000001
#define SYSCON_PROTEN            0x00000002

// Trigger Event 0 Specifier Register
#define TR0EVT                 (*((uword volatile *) 0xF7E1FD20))
#define TR0EVT_ASI_EN            0x00008000
#define TR0EVT_BBM               0x00000008
#define TR0EVT_BOD               0x00000010
#define TR0EVT_DLR_LR            0x00000100
#define TR0EVT_DLR_U             0x00000200
#define TR0EVT_DU_LR             0x00000400
#define TR0EVT_DU_U              0x00000800
#define TR0EVT_SUSP              0x00000020

// Trigger Event 1 Specifier Register
#define TR1EVT                 (*((uword volatile *) 0xF7E1FD24))
#define TR1EVT_ASI_EN            0x00008000
#define TR1EVT_BBM               0x00000008
#define TR1EVT_BOD               0x00000010
#define TR1EVT_DLR_LR            0x00000100
#define TR1EVT_DLR_U             0x00000200
#define TR1EVT_DU_LR             0x00000400
#define TR1EVT_DU_U              0x00000800
#define TR1EVT_SUSP              0x00000020

// WDT Control Register 0
#define WDT_CON0               (*((uword volatile *) 0xF00005F0))
#define WDT_CON0_ENDINIT         ((T_Reg32 *) 0xF00005F0)->bit0
#define WDT_CON0_LCK             ((T_Reg32 *) 0xF00005F0)->bit1

// WDT Control Register 1
#define WDT_CON1               (*((uword volatile *) 0xF00005F4))
#define WDT_CON1_CLRIRF          ((T_Reg32 *) 0xF00005F4)->bit0
#define WDT_CON1_DR              ((T_Reg32 *) 0xF00005F4)->bit3
#define WDT_CON1_IR              ((T_Reg32 *) 0xF00005F4)->bit2

// WDT Status Register
#define WDT_SR                 (*((uword volatile *) 0xF00005F8))
#define WDT_SR_AE                ((T_Reg32 *) 0xF00005F8)->bit0
#define WDT_SR_DS                ((T_Reg32 *) 0xF00005F8)->bit3
#define WDT_SR_IS                ((T_Reg32 *) 0xF00005F8)->bit2
#define WDT_SR_OE                ((T_Reg32 *) 0xF00005F8)->bit1
#define WDT_SR_PR                ((T_Reg32 *) 0xF00005F8)->bit5
#define WDT_SR_TO                ((T_Reg32 *) 0xF00005F8)->bit4

#endif  // ifndef _REGISTER_DEFINITION_H_
