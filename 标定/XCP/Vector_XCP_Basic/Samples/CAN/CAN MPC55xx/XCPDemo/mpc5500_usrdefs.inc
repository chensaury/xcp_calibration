#************************************************************************
#* FILE NAME: mpc5500_usrdefs.inc            COPYRIGHT (c) Freescale 2004 
#*                                                All Rights Reserved     
#* DESCRIPTION:                                                           
#* This file contains user definitions for the MPC5500 assembly functions.
#* The user will only need to make changes to this file for the assembly
#*  portion of this code.
#* 
#*========================================================================
#* ORIGINAL AUTHOR: G. Jackson           
#* REV      AUTHOR        DATE       DESCRIPTION OF CHANGE                
#* ---   -----------   -----------   ---------------------                  
#* 0.1   G. Jackson     12/Apr/04    Initial version        
#* 0.2   G. Jackson     15/Apr/04    Added compiler designations
#* 0.3   G. Jackson     13/May/04    Added runtime variables
#* 0.4   G. Jackson     06/Jun/04    Added EXT_BOOT config option
#* 0.5   G. Jackson     30/Jun/04    Added RCHW variables
#* 1.0   G. Jackson     07/Oct/04    Internal and external RAM set to 
#*                                   CACHE_INHIBIT (TLBs 3 & 11)
#*       Vector         10/Jul/06    See code comments for modifications                                    
#************************************************************************
    .include "mpc5500_defs.inc"
    
#***************************************************************
#******** Compiler Designation for Assembler Options ***********
#  Set one compiler to "1" from the four choices below:    
    .equ __GRNHS__,  0  ## Designation for the Green Hills compiler
    .equ __PEGNU__,  1  ## Designation for the P&E Micro Gnu compiler
	.equ __DIABCC__, 0  ## Designation for the Wind River compiler
    .equ __CWWRKS__, 0  ## Designation for the Metrowerks CodeWarrior compiler

#*************** Runtime Variables *****************
#  These runtime variables are used in __start.s
# main(), assembly cfg_* calls, and cfg_mpc5500_ccd() need to  **
# have far absolute addressing if flashing to ROM with         **
# distant addresses on the MPC5500.                            **
# The .equ statements below should be set to "1" to be valid   **
#  and set to "0" to be inactive.                              **

    .equ FAR_ADDRESS,      0  # Used for a FAR_ADDRESS call
    .equ FAR_ADDRESS_MAIN, 1  # Used for a FAR_ADDRESS call to main
    .equ SIM_VER,          0  # Used with the Code Warrior simulator
    .equ FLSH_RUN,         1  # Set to (1) for code in Flash
#                             #     to (0) for code in SRAM
    .equ EXT_BOOT,         0  # Set to (1) for External boot. 
#                             #  BAM sets up external bus and CS[0]
# Reset Configuration Half Word Variables **
    .equ RCHW_WTE, WDOG_DISABLE # Watchdog control at reset
    .equ RCHW_PS0, CS0_32BIT    # CS0 data port size at reset
    .equ BOOT_ID,  MPC5500_ID   # Valid boot ID for MPC5500 devices

#*************************************************************
#******** Special Initialization Option Constants  ***********
# The "I_" prefixed variables are initialization defines      
#  Set the value to one ("1") to enable the option.
#  Or, set the value to zero ("0") to disable the option.

    .equ I_LOCEN,    1 # Set loss of clock enable function
    .equ I_BCKUPCLK, 1 # Enable backup clock on loss of clock

# Mutually exclusive pair (one set to "0", one set to "1"):
    .equ I_LOSSCRST, 0 # Enable reset on loss of clock 
    .equ I_LOCINT,   1 # Enable interrupt on loss of clock
# Mutually exclusive pair (one set to "0", one set to "1"):
    .equ I_LOSSLRST, 0 # Enable reset on loss of lock  
    .equ I_LOLINT,   1 # Enable interrupt on loss of lock 


# To match MMU entry size:
    .equ I_SRAM_SIZE,   SIZE_64K   #   64 KB RAM Size
    .equ I_XSRAM_SIZE,  SIZE_512K  #  512 KB External RAM Size
    .equ I_XSRAM_SPACE, SIZE_4M    #    4 MB External RAM Space

#*************************************************************
#      User Defined Options
#  These values should be modified based on user requirements
#*************************************************************
# Cache definitions used by cfg_CACHE and cfg_STACK:
#  Copy back mode (CWM=1) and Push buffer disabled (DPB=1) is
#   required by errata #32 and #34 to allow MMU control of cache.
#   These errata may go away in the future (see current errata)
    .equ CACHE_CLEAR,(CLFC_NO_OP | CINV_INV_OP | CE_DISABLE)
    .equ CACHE_SETTINGS, (CWM_COPYBCK | DPB_NOPUSH | CE_ENABLE) 

#*******************************************************************
# Flash definitions used by cfg_FLASH:
#     Internal Flash: FLASH_BIUCR (0xC3F8_801C)    
    .equ FLASH_SETTINGS, (EBI_PREFTCH_ON | APC_3 | WWSC_1 | RWSC_2 | IPFEN_ANY | PFLIM_2 | BFEN_EN)
#     External Flash: CS0 OR settings used by cfg_FLASH:
#     The next line is commented out as an example of optimizing
#      external Flash boot times.
#    .equ CS0_OR_OPTIONS, (AMASK_8M | OR0SCY_2 | OR0BSCY_0)
    
#*******************************************************************
# FMPLL definitions used by cfg_FMPLL

# Fsys = FRef * MFD / (PREDIV * RFD)

# Fref = 8MHz (MPC5554)

#  Set the internal clock to 32 MHz with MFD=16, and RFD=4.
#  Setting 1 is intended to only change the MFD bit with no change to the RFD bit.
    .equ FMPLL_SYNCR_SETTING1, (MFD_16 | RFD_4 | LOCEN_EN)  # MFD=16, RFD=4 for  32MHz
#  Set the internal clock to 128 MHz with MFD=16, and RFD=1.
#  This sequence sets the RFD to divide-by-1 in the FMPLL_SYNCR Register.
#  Setting 2 is intended to only change the RFD bit with no change to the MFD bit.
    .equ FMPLL_SYNCR_SETTING2, (MFD_16 | RFD_1 | LOCEN_EN)  # MFD=15, RFD=1 for 128MHz
    
    
# Fref = 40MHz (MPC5567)
                  
#  Set the internal clock to 40 MHz with MFD=4, and RFD=1.
#  Setting 1 is intended to only change the MFD bit with no change to the RFD bit.
#   .equ FMPLL_SYNCR_SETTING1, (MFD_4 | PREDIV_4 | RFD_1 | LOCEN_EN)  # 40 MHz
    
#  Set the internal clock to 128 MHz with MFD=12, and RFD=1.
#  This sequence sets the RFD to divide-by-1 in the FMPLL_SYNCR Register.
#  Setting 2 is intended to only change the RFD bit with no change to the MFD bit.

#   .equ FMPLL_SYNCR_SETTING2, (MFD_16 | PREDIV_5 | RFD_1 | LOCEN_EN)  # 128MHz 
     
#*******************************************************************
# SIU definitions used by cfg_FMPLL
# The SIU definition below will generate a reset of the device when used.
#  A system reset or an external reset will result depending on settings.
    .equ SIU_SRCR_SYSRST, (SSR_SYSRST | SER_NORST | CRE_NO)    

#*******************************************************************
# ERRLOGREG (Error Log Register) address definition
    .equ ERRLOGREG, ERRLOGAD_ETPUPRAM_HI # Assembler token address

#*********************************************************************

##*************************************************************************/
# FUNCTION     : MMU DATA Tables                                          */
# PURPOSE      : This defines the MMU data tables for the TLB entries     */
#                which are set in the file mpc5500_asmcfg.c               */
# INPUT NOTES  : Requires that the TLB settings be in MPC5500_defs.inc    */
# RETURN NOTES : mmu_tlb0 [TLB0_MAS[0:3] through mmu_tlb11 [TLB0_MAS[0:3] */
# WARNING      : Registers used: none. Section is: .rodata                */
##*************************************************************************/


# Section declaration:

    .if __PEGNU__
    .section ".text" 
    .endif

    .if __CWWRKS__ | __DIABCC__ | __GRNHS__
    .section .rodata
    .endif
    
    
#*************************************************************************/
#* DESCRIPTION:                                                          */  
#* This table contains definitions for the MPC5554 MMU TLB entries.      */
#* The bit definitions used in the TLB defines are located below.        */  
#* The second half of the file is the TLB setup code in mpc5500_asmcfg.s */
#*************************************************************************/ 

#*** TLB DEFINES ***/

#** TLB entry 15 - BAM in Flash set to 1M **
mmu_tlb15:
# TLB0_MAS0
    .long (TLB_SELECT | TLB_ENTRY15 )
# TLB0_MAS1
    .long (TLB_ENTRY_VALID | ENTRY_PROTECTED | GLOBAL_MATCH | TS_IS_COMPARE | TSIZ_1M )
# TLB0_MAS2
    .long (BAM_BASE_ADDR | CACHE_WRITE_BACK | CACHE_ACTIVE | MEM_NO_COHERENCE | PAGE_NOT_GUARDED | PAGE_BIG_ENDIAN )
# TLB0_MAS3
    .long ( BAM_BASE_ADDR | READWRITEEXECUTE )


#** TLB entry 0 - PBRIDGE_B set to 1M **
mmu_tlb0:
# TLB1_MAS0
    .long ( TLB_SELECT | TLB_ENTRY0 )
# TLB1_MAS1
    .long ( TLB_ENTRY_VALID | ENTRY_PROTECTED | GLOBAL_MATCH | TS_IS_COMPARE | TSIZ_1M )
# TLB1_MAS2
    .long ( PBRIDGEB_BASE_ADDR | CACHE_WRITE_BACK | CACHE_INHIBIT | MEM_NO_COHERENCE | PAGE_GUARDED | PAGE_BIG_ENDIAN )
# TLB1_MAS3
    .long ( PBRIDGEB_BASE_ADDR | READWRITEEXECUTE )

#** TLB entry 1 - Split Internal FLASH (1) set to 1MB **
mmu_tlb1:
# TLB5_MAS0
    .long ( TLB_SELECT | TLB_ENTRY1 )
# TLB5_MAS1
    .long ( TLB_ENTRY_VALID | ENTRY_PROTECTED | GLOBAL_MATCH | TS_IS_COMPARE | TSIZ_1M )
# TLB5_MAS2
    .long ( FLASH_BASE_ADDR | CACHE_WRITE_BACK | CACHE_ACTIVE | MEM_NO_COHERENCE | PAGE_NOT_GUARDED | PAGE_BIG_ENDIAN )
# TLB5_MAS3
    .long ( FLASH_BASE_ADDR | READWRITEEXECUTE )

#** TLB entry 2 - External Memory 1 (Flash) 4M **
mmu_tlb2:
# TLB2_MAS0
    .long ( TLB_SELECT | TLB_ENTRY2 )
# TLB2_MAS1
    .long ( TLB_ENTRY_VALID | ENTRY_PROTECTED | GLOBAL_MATCH | TS_IS_COMPARE | TSIZ_4M )
# TLB2_MAS2
    .long ( EXTMEM1_BASE_ADDR | CACHE_WRITE_BACK | CACHE_ACTIVE | MEM_NO_COHERENCE | PAGE_NOT_GUARDED | PAGE_BIG_ENDIAN )
# TLB2_MAS3
    .long ( EXTMEM1_BASE_ADDR | READWRITEEXECUTE )

#** TLB entry 3 - Internal SRAM reduce from 1M space to 64K only **
mmu_tlb3:
# TLB3_MAS0
    .long ( TLB_SELECT | TLB_ENTRY3 )
# TLB3_MAS1
    .long ( TLB_ENTRY_VALID | ENTRY_PROTECTED | GLOBAL_MATCH | TS_IS_COMPARE | TSIZ_64K )
# TLB3_MAS2
    .long ( SRAM_BASE_ADDR | CACHE_WRITE_BACK | CACHE_INHIBIT | MEM_NO_COHERENCE | PAGE_NOT_GUARDED | PAGE_BIG_ENDIAN )
#    .long ( SRAM_BASE_ADDR | CACHE_WRITE_BACK | CACHE_ACTIVE | MEM_NO_COHERENCE | PAGE_NOT_GUARDED | PAGE_BIG_ENDIAN )
# TLB3_MAS3
    .long ( SRAM_BASE_ADDR | READWRITEEXECUTE )

#** TLB entry 4 - PBRIDGE_A set to 1MB **
mmu_tlb4:
# TLB4_MAS0
    .long ( TLB_SELECT | TLB_ENTRY4 )
# TLB4_MAS1
    .long ( TLB_ENTRY_VALID | ENTRY_PROTECTED | GLOBAL_MATCH | TS_IS_COMPARE | TSIZ_1M )
# TLB4_MAS2
    .long ( PBRIDGEA_BASE_ADDR | CACHE_WRITE_BACK | CACHE_INHIBIT | MEM_NO_COHERENCE | PAGE_NOT_GUARDED | PAGE_BIG_ENDIAN )
# TLB4_MAS3
    .long ( PBRIDGEA_BASE_ADDR | READWRITEEXECUTE )

#** TLB entry 5 - Turn OFF TLB5 to eliminate duplication of Internal FLASH (1)
mmu_tlb5:
# TLB4_MAS0
    .long ( TLB_SELECT | TLB_ENTRY5 )
# TLB0_MAS1
    .long (TLB_ENTRY_INVALID | ENTRY_PROTECTED | GLOBAL_MATCH | TS_IS_COMPARE | TSIZ_1M )

#** TLB entry 6 - Internal FLASH (2) set to 256KB **
mmu_tlb6:
# TLB6_MAS0
    .long ( TLB_SELECT | TLB_ENTRY6 )
# TLB6_MAS1
    .long ( TLB_ENTRY_VALID | ENTRY_PROTECTED | GLOBAL_MATCH | TS_IS_COMPARE | TSIZ_256K )
# TLB6_MAS2
    .long ( (FLASH_BASE_ADDR + OFFSET_1M) | CACHE_WRITE_BACK | CACHE_INHIBIT | MEM_NO_COHERENCE | PAGE_NOT_GUARDED | PAGE_BIG_ENDIAN )
# TLB6_MAS3
    .long ( (FLASH_BASE_ADDR + OFFSET_1M) | READWRITEEXECUTE )

#** TLB entry 7 - Internal FLASH (3) set to 256KB **
mmu_tlb7:
# TLB7_MAS0
    .long ( TLB_SELECT | TLB_ENTRY7 )
# TLB7_MAS1
    .long ( TLB_ENTRY_VALID | ENTRY_PROTECTED | GLOBAL_MATCH | TS_IS_COMPARE | TSIZ_256K )
# TLB7_MAS2
    .long ( (FLASH_BASE_ADDR + OFFSET_1M + OFFSET_256K) | CACHE_WRITE_BACK | CACHE_INHIBIT | MEM_NO_COHERENCE | PAGE_NOT_GUARDED | PAGE_BIG_ENDIAN )
# TLB7_MAS3
    .long ( (FLASH_BASE_ADDR + OFFSET_1M + OFFSET_256K) | READWRITEEXECUTE )

#** TLB entry 8 - Internal FLASH (4) set to 256KB **
mmu_tlb8:
# TLB8_MAS0
    .long ( TLB_SELECT | TLB_ENTRY8 )
# TLB8_MAS1
    .long ( TLB_ENTRY_VALID | ENTRY_PROTECTED | GLOBAL_MATCH | TS_IS_COMPARE | TSIZ_256K )
# TLB8_MAS2
    .long ( (FLASH_BASE_ADDR + OFFSET_1M + OFFSET_512K) | CACHE_WRITE_BACK | CACHE_INHIBIT | MEM_NO_COHERENCE | PAGE_NOT_GUARDED | PAGE_BIG_ENDIAN )
# TLB8_MAS3
    .long ( (FLASH_BASE_ADDR + OFFSET_1M + OFFSET_512K) | READWRITEEXECUTE )

#** TLB entry 9 - Internal FLASH (5) set to 256KB **
mmu_tlb9:
# TLB9_MAS0
    .long ( TLB_SELECT | TLB_ENTRY9 )
# TLB9_MAS1
    .long ( TLB_ENTRY_VALID | ENTRY_PROTECTED | GLOBAL_MATCH | TS_IS_COMPARE | TSIZ_256K )
# TLB9_MAS2
    .long ( (FLASH_BASE_ADDR + OFFSET_1M + OFFSET_768K) | CACHE_WRITE_BACK | CACHE_INHIBIT | MEM_NO_COHERENCE | PAGE_NOT_GUARDED | PAGE_BIG_ENDIAN )
# TLB9_MAS3
    .long ( (FLASH_BASE_ADDR + OFFSET_1M + OFFSET_768K) | READWRITEEXECUTE )

#** TLB entry 10 - Cache used for Stack SRAM **
mmu_tlb10:
# TLB10_MAS0
    .long ( TLB_SELECT | TLB_ENTRY10 )
# TLB10_MAS1
    .long ( TLB_ENTRY_VALID | ENTRY_PROTECTED | GLOBAL_MATCH | TS_IS_COMPARE | TSIZ_4K )
# TLB10_MAS2
    .long ( (SRAM_BASE_ADDR + I_SRAM_SIZE) | CACHE_WRITE_BACK | CACHE_ACTIVE | MEM_NO_COHERENCE | PAGE_NOT_GUARDED | PAGE_BIG_ENDIAN )
# TLB10_MAS3
    .long ( (SRAM_BASE_ADDR + I_SRAM_SIZE) | READWRITEEXECUTE )

#** TLB entry 11 - External SRAM set to overall size of 4MB **
mmu_tlb11:
# TLB11_MAS0
    .long ( TLB_SELECT | TLB_ENTRY11 )
# TLB11_MAS1
    .long ( TLB_ENTRY_VALID | ENTRY_PROTECTED | GLOBAL_MATCH | TS_IS_COMPARE | TSIZ_4M )
# TLB11_MAS2
    .long ( (SRAM_BASE_ADDR - I_XSRAM_SPACE) | CACHE_WRITE_BACK | CACHE_INHIBIT | MEM_NO_COHERENCE | PAGE_NOT_GUARDED | PAGE_BIG_ENDIAN )
# TLB11_MAS3
    .long ( (SRAM_BASE_ADDR - I_XSRAM_SPACE) | READWRITEEXECUTE )

#** TLB entry 14 - Shadow Block set to overall size of 4K (Actual Shadow Block is 1K) **
mmu_tlb14:
# TLB14_MAS0
    .long ( TLB_SELECT | TLB_ENTRY14 )
# TLB14_MAS1
    .long ( TLB_ENTRY_VALID | ENTRY_PROTECTED | GLOBAL_MATCH | TS_IS_COMPARE | TSIZ_4K )
# TLB14_MAS2
    .long ( SHDW_BLK_ADDR | CACHE_WRITE_BACK | CACHE_ACTIVE | MEM_NO_COHERENCE | PAGE_NOT_GUARDED | PAGE_BIG_ENDIAN )
# TLB14_MAS3
    .long ( SHDW_BLK_ADDR | READWRITE )



#*********************************************************************/


