#**************************************************************************/
#* FILE NAME: mpc5500_asmcfg.s              COPYRIGHT (c) Freescale 2004  */
#*                                                All Rights Reserved     */
#* DESCRIPTION:                                                           */
#* This file contains functions for the MPC5500 assembly configuration.   */
#=========================================================================*/
#*                                                                        */
#* REV      AUTHOR       DATE       DESCRIPTION OF CHANGE                 */
#* ---   -----------   ----------   ---------------------                 */
#* 0.1   G. Jackson    26/Mar/04    Initial version                       */ 
#* 0.2   G. Jackson    29/Apr/04    Made compiler names unique for        */
#*                                    assembly configuration.             */
#*                                  Single designation for rcw values.    */
#* 0.3   G. Jackson    13/May/04    Changed definition of FMPLL_SYNCR     */
#*                                    register settings.                  */
#* 0.4   G. Jackson    15/May/04    Removed msync and isync from tlbwe    */
#*                                    commands.                           */
#* 0.5   G. Jackson    25/May/04    Changed __OPCOUNT to __SRAM_LOAD_SIZE */
#*                                  Changed __SRAM_OPCODE to __SRAM_LOAD  */
#*                                  Changed cfg_OPCODE to cfg_SRAM_LOAD   */
#*                                  Changed OPCNT_OFFSET to IP_ADVANCE    */
#* 0.6   G. Jackson    12/Jun/04    Changed TLB entries to work with      */
#*                                  MPC5554 Rev. 0.3 and later for the    */
#*                                  BAM, PBRIDGE_B, and Internal FLASH.   */
#* 0.7   G. Jackson    30/Jun/04    Added entries for RCHW (RCHW_VAL)     */
#* 0.8   G. Jackson    05/Aug/04    Added cfg_PNTRS for R13 and R2        */
#* 0.9   G. Jackson    18/Aug/04    Added cfg_ROMCPY for .data and .sdata */
#* 0.91  G. Jackson    20/Sep/04    cfg_ROMCPY changed to load by bytes.  */
#* 0.92  G. Jackson    11/Oct/04    L1CSR0 checks added for complete      */
#*                                    cache operation.                    */
#* 1.0   G. Jackson    12/Oct/04    Green Hills now does not require      */
#*                                    quotation marks around the section  */
#*                                  Added syntax to generate symbols for  */
#*                                    debug.                              */
#**************************************************************************/

    .include "mpc5500_usrdefs.inc"

     .globl cfg_CACHE 
     .globl cfg_FMPLL 
     .globl cfg_SRAM
     .globl cfg_FLASH
     .globl cfg_MMU
     .globl cfg_STACK
#    .globl cfg_PNTRS
#    .globl cfg_ROMCPY
    
#    .extern __start          # Primary program entry point defined in __start.s
    .extern __STACK_SIZE     # Defined in the linker file
    .extern __SP_INIT        # Defined in the linker file
    .extern __SP_END         # Defined in the linker file
    .extern __SRAM_LOAD      # Defined in the linker file
    .extern __SRAM_LOAD_SIZE # Defined in the linker file
    .extern _SDA_BASE_       # Defined by the linker EABI
    .extern _SDA2_BASE_      # Defined by the linker EABI
    .extern cfg_SRAM_LOAD    # Defined in mpc5500_SRAM_load.s
    .extern __DATA_ROM       # Defined in the linker file
#                            #   Address of initialized data in Flash
    .extern __ROM_COPY_SIZE  # Defined in the linker file
#                            #   Size of Flash area to be copied to SRAM
    .extern __SRAM_CPY_START # Defined in the linker file
#                            #   Address of ".data" section in SRAM

# set up separate section for the reset configuration half word and vector.
#       This is the start of the .rcw section.
#    .if __PEGNU__
#    .section ".rcw","ax" # The "ax" is required to generate "non-text" code
#    .endif
#
#    .if __CWWRKS__ | __DIABCC__ | __GRNHS__
#    .section .rcw
#    .endif
#
#    .equ RCHW_VAL, (RCHW_WTE | RCHW_PS0 | BOOT_ID)
#
#   .LONG RCHW_VAL
#    .LONG __start


#       This is the end of the .rcw section.
#################################################
#       This is the start of the .init section.

    .if __PEGNU__
    .section ".init","ax" # The "ax" is required to generate "non-text" code     
    .endif

    .if __GRNHS__
    .section .init,ax     # The "ax" generates symbols for debug
    .endif

    .if __DIABCC__
    .section .init,c      # The "c" generates symbols for debug
    .endif

     .if __CWWRKS__
    .section .init,text   # The "text" generates symbols for debug
    .endif


# Constants that should be defined follow:
# Defined assembler input parameters should allready understand:
#    .equ MAS0,624
#    .equ MAS1,625
#    .equ MAS2,626
#    .equ MAS3,627

# init_L2RAM requires the base address and the size of the SRAM.
#    INT_SRAM_BASE, INT_SRAM_SIZE.
# Defined in linker file.                        

# Cache definitions:
# cfg_CACHE and init_STACK CACHE Settings
#     __STACK_SIZE, __SP_INIT, __SP_END, (defined in linker file)
#    .equ CACHE_CLEAR,(CLFC_NO_OP | CINV_INV_OP | CE_DISABLE)
#    .equ CACHE_SETTINGS, (CWM_COPYBCK | DPB_NOPUSH | CE_ENABLE) 


#***********************************************************************************/
# FUNCTION     : cfg_mpc5500as                                                     */
# PURPOSE      : This function provides an example for the overall                 */ 
#                 configuration for an mpc5500 device.                             */
#                                                                                  */
#                 In cases where (numerous) alternative initializations could      */ 
#                 occur, a sample configuration is included here. Actual           */
#                 initialization required for a specific system remains the        */
#                 responsibility of the developer.                                 */
# INPUT NOTES  : None                                                              */
# RETURN NOTES : None                                                              */
# WARNING      : None                                                              */
#***********************************************************************************/
#                                                                                  */
# MPC5500 initialization functions in order of call from __start.s                 */
#cfg_mpc5500as:                                                                    */
#                                                                                  */
#   The assembly actions are called in the order seen below.                       */
#   They are called from __start in the file named __start.s                       */
#    bl cfg_CACHE    # Configure cache.                                            */
#                                                                                  */
#    bl cfg_FMPLL    # Configure the Frequency Modulated Phase Locked Loop         */
#                                                                                  */
#    bl cfg_SRAM     # Write to all SRAM locations for ECC functionality.          */
#                                                                                  */
#    bl cfg_FLASH    # Reduce Wait States for Internal and External Flash          */
#                                                                                  */
#    bl cfg_MMU      # Set up the TLB tables with the MMU registers.               */
#                                                                                  */
#    bl cfg_STACK    # Set up the Stack in the Cache                               */
#                                                                                  */
#    bl cfg_PNTRS    # Set up the small data register pointers in R2 and R13       */
#                                                                                  */
#    bl cfg_ROMCPY   # Copy initialized data from FLASH ROM to SRAM                */
#                                                                                  */
#    blr             # End of cfg_mpc5500as                                        */
#***********************************************************************************/

#************************************************************************/
#                       CALLED SEQUENCES                                */
#************************************************************************/

#**************************************************************************/
# FUNCTION     : cfg_CACHE                                                */
# PURPOSE      : This function initializes the CACHE by invalidating and  */
#                  then enabling the cache.                               */
# INPUT NOTES  : CACHE_CLEAR, CACHE_SETTINGS, L1CSR0                      */
# RETURN NOTES : None                                                     */
# WARNING      : Registers used: R5,R8,R9,R10                             */
#**************************************************************************/

cfg_CACHE:

    .EQU L1CSR0,1010

# To activate cache invalidate operation,
# place a "1" in the CINV bit location.  (L1CSR0[30])
#  This operation takes 134 cycles to complete
    lis   r5, CACHE_CLEAR@h        # Load upper L1CSR0 (0x0) into R5
    ori   r5, r5, CACHE_CLEAR@l    # Load lower L1CSR0 (CINV bit) into R5  
    mtspr L1CSR0,r5                # Move R5 to the L1CSR0 (SPR 1010)register.  
#                                  # This should start the CACHE invalidate
#                                  #  operation.
# Make sure that CINV is not active/finished
label_CINV_check:                  # Make sure that CINV is not active/finished
# The CINV mask bit will be compared to L1CSR0[30] CINV bit
    lis   r8, 0x0000               # Load upper CINV mask (0x0000) into R8
    ori   r8, r8, 0x0002           # Load lower L1CSR0[30] CINV mask bit into R8
CHECK_CINV:
    mfspr r9, L1CSR0               # Move the L1CSR0 register value to R9.
# "AND" the two registers together to check for active CINV bit
    and.  r10,r8, r9
#                                  # The "." after "and" activates the condition register
    bne CHECK_CINV                 # Branch if not zero. CINV still=1.
 
# Enable cache
    mfspr r5, L1CSR0               # Retrieve the L1CSR0 register value
    oris  r5, r5, CACHE_SETTINGS@h # OR in CWM and DPB in upper L1CSR0[11:12]
    ori   r5, r5, CACHE_SETTINGS@l # OR in cache enable bit L1CSR0[31]
    isync                          # Required before changing the CE bit to
    msync                          #  prevent disable/enable cache during access
    mtspr L1CSR0, r5               # Return value to L1CSR0 to enable the cache

    blr   
# End of cfg_CACHE


#************************************************************************/
# FUNCTION     : cfg_FMPLL                                              */
# PURPOSE      : This function configures the FMPLL.                    */
# INPUT NOTES  : FMPLL_SYNCRREG, FMPLL_SYNSRREG, SIU_SRCRREG,           */
#                FMPLL_SYNCR_16_4, FMPLL_SYNCR_16_1, SIU_SRCR_SYSRST,   */
#                ERRLOGREG, ERRLOG_MFDERR, I_LOCEN, I_LOSSLRST,         */
#                I_LOSSCRST, I_LOCINT, I_LOLINT                         */
# RETURN NOTES : None                                                   */
# WARNING      : Registers used: R5,R6,R8,R9,R10                        */
#************************************************************************/

cfg_FMPLL:

#*******************************************
# Set the internal clock to 32 MHz with MFD=16, and RFD=4.
# This sequence sets the MFD to 16 in the FMPLL_SYNCR Register.
    lis   r5, FMPLL_SYNCRREG@ha       # Load address upper FMPLL_SYNCR into R5
    addi  r5, r5, FMPLL_SYNCRREG@l    # Load address lower FMPLL_SYNCR into R5
# Load value upper FMPLL_SYNCR into R6
    lis   r6, FMPLL_SYNCR_SETTING1@h      # Load value upper FMPLL_SYNCR into R6
    ori   r6, r6, FMPLL_SYNCR_SETTING1@l  # Load value lower FMPLL_SYNCR into R6
    stw   r6, 0(r5)                   # Place value of R6 into FMPLL_SYNCR (address R5)

#*******************************************
# Check for loss-of-lock after MFD change
# Wait for PLL to lock. A timeout will occur after 6000 clocks.
# Set up counter 
    lis   r6, 0x0000                  # Load counter value into R6
    ori   r6, r6, 0x1770              # 6000 = 0x1770 for time out clocks
    mtctr r6                          # Move 0x1770 to the counter
# Load the lock bit mask into R8 
    lis   r8, 0x0000                  # Load LOCK mask value into R8
    ori   r8, r8, 0x0008              # LOCK bit is FMPLL_SYNSR[28]
# Load address of FMPLL_SYNSR 
    lis   r6, FMPLL_SYNSRREG@h        # Load address upper FMPLL_SYNSR into R6
    ori   r6, r6, FMPLL_SYNSRREG@l    # Load address lower FMPLL_SYNSR into R6
PLLnotlocked:
    bdnz  PLLcontinue                 # Check for PLL timeout
#                                     #  Decrement counter, Branch if CTR!=0
#                                     #  (0x1770 has not counted down)

# Timeout has happened. Handle here
# Store MFD ERROR bit into the error log register
    lis   r9, ERRLOGREG@ha            # Load upper address for error log into R9
    ori   r9, r9, ERRLOGREG@l         # Load lower address for error log into R9
# Load MFD ERROR bit into error log (ERRLOG)
    lis   r10, ERRLOG_MFDERR@h        # Load MFD ERROR bit into upper error log (ERRLOG)
    ori   r10, r10, ERRLOG_MFDERR@l   # Load MFD ERROR bit into lower error log (ERRLOG)
    stw   r10, 0(r9)                  # Store error bit into the error log register
# Reset the part with a system reset
    lis   r9, SIU_SRCRREG@ha          # Load upper address for SIU_SRCR into R9
    addi  r9, r9, SIU_SRCRREG@l       # Load lower address for SIU_SRCR into R9
    lis   r10, SIU_SRCR_SYSRST@ha     # Load Software system Reset (SSR bit)
    addi  r10, r10, SIU_SRCR_SYSRST@l #   value into SIU_SRCR
    stw   r10, 0(r9)                  # Load SSR bit into SIU_SRCR[0]
# Device will enter system reset at this time
    b     FMPLL_RETURN                # System reset is active, so this may never happen.
PLLcontinue:
# Check for lock achieved
    lwz   r9, 0(r6)                   # Load value of FMPLL_SYNSR into R9
    and.  r10, r9, r8                 # AND FMPLL_SYNSR with the LOCK bit mask in R8
#                                     # The "." after "and" activates the condition register
    beq   0,PLLnotlocked              # Branch not equal (not zero) (CR0[2] !=0)
#                                     # Branch back if PLL is not locked
#                                     # (LOCK has not occured)
# PLL is locked, continue
  
#***************************************
# Set the internal clock to 128 MHz with MFD=16, and RFD=1.
# This sequence sets the RFD to divide-by-1 in the FMPLL_SYNCR Register.
#  R5 holds the FMPLL_SYNCR  for this sequence.
    lis   r6, FMPLL_SYNCR_SETTING2@h      # Load RFD value upper FMPLL_SYNCR into R6
    ori   r6, r6, FMPLL_SYNCR_SETTING2@l  # Load value lower FMPLL_SYNCR into R6
    stw   r6, 0(r5)                   # Place value of R6 into FMPLL_SYNCR (address R5)


#**************************************
# The following "I_*" bits are set to one (or zeroed out) in mpc5500_usrdefs.inc

# R5 holds the FMPLL_SYNCR for these sequences
# Set loss of clock enable
#        FMPLL.SYNCR.B.LOCEN = 1; 
# Address for FMPLL_SYNCR  is in R7
    .if I_LOCEN                #  if .equ I_LOCEN = 1?
    lwz   r6,0(r5)             # Load value of FMPLL_SYNCR into R6
    oris  r6,r6,0x0004         # Load the OR of LOCEN into R6
    stw   r6,0(r5)             # Load into FMPLL_SYNCR
    .endif

#  Enable reset on loss of lock (Disable LOLIRQ)
#        FMPLL.SYNCR.B.LOLRE = 1;
#  Disable interrupt on loss of lock
#        FMPLL.SYNCR.B.LOLIRQ = 0;
# Address for FMPLL_SYNCR  is in R5
    .if I_LOSSLRST             # if .equ I_LOSSLRST = 1?
    lwz   r6,0(r5)             # Load value of FMPLL_SYNCR into R6
    oris  r6,r6,0x0002         # Load the OR of LOLRE into R5 (upper)
    lis   r8,0xFFFF            # Load upper mask for LOLIRQ FMPLL_SYNCR into R8
    ori   r8,r8,0xBFFF         # Load lower mask for LOLIRQ FMPLL_SYNCR into R8
    and   r10,r6, r8           # Mask out the LOLIRQ bit into R10
    stw   r10,0(r5)            # Load into FMPLL_SYNCR from R10
    .endif

#  Enable reset on loss of clock (Disable LOCIRQ)
#        FMPLL.SYNCR.B.LOCRE = 1;
#  Disable interrupt on loss of clock
#        FMPLL.SYNCR.B.LOCIRQ = 0;
# Address for FMPLL_SYNCR  is in R5
    .if I_LOSSCRST
    lwz   r6,0(r5)             # Load value of FMPLL_SYNCR into R6
    oris  r6,r6,0x0001         # Load the OR of LOCRE into R5 (upper)
    lis   r8,0xFFFF            # Load upper mask FMPLL_SYNCR into R8
    ori   r8,r8,0xDFFF         # Load lower mask for LOCIRQ FMPLL_SYNCR into R8
    and   r10,r6, r8           # Mask out the LOCIRQ bit into R10
    stw   r10,0(r5)            # Load into FMPLL_SYNCR from R10
    .endif

# Enable interrupt on loss of clock
#       FMPLL.SYNCR.B.LOCIRQ = 1;
#  Disable reset on loss of clock
#       FMPLL.SYNCR.B.LOCRE = 0;
# Address for FMPLL_SYNCR  is in R5
    .if I_LOCINT
    lwz   r6,0(r5)             # Load value of FMPLL_SYNCR into R6
    ori   r6,r6,0x2000         # Load the OR of LOCIRQ into R5 (lower)
    lis   r8,0xFFFE            # Load upper mask for LOCRE FMPLL_SYNCR into R8
    ori   r8,r8,0xFFFF         # Load lower mask for FMPLL_SYNCR into R8
    and   r10,r6, r8           # Mask out the LOCRE bit into R10
    stw   r10,0(r5)            # Load into FMPLL_SYNCR from R10
    .endif

# Enable interrupt on loss of lock
#      FMPLL.SYNCR.B.LOLIRQ = 1; 
#  Disable reset on loss of lock
#      FMPLL.SYNCR.B.LOLRE = 0;
# Address for FMPLL_SYNCR  is in R5
    .if I_LOLINT
    lwz   r6,0(r5)             # Load value of FMPLL_SYNCR into R6
    ori   r6,r6,0x4000         # Load the OR of LOLIRQ into R6 (lower)
    lis   r8,0xFFFD            # Load upper mask for LOLRE FMPLL_SYNCR into R8
    ori   r8,r8,0xFFFF         # Load lower mask for FMPLL_SYNCR into R8
    and   r10,r6, r8           # Mask out the LOLRE bit into R10
    stw   r10,0(r5)            # Load into FMPLL_SYNCR from R10
    .endif

FMPLL_RETURN:

    blr      
# End of cfg_FMPLL

#*************************************************************************/
# FUNCTION     : cfg_SRAM                                                */
# PURPOSE      : This function initializes the SRAM by writing 64 bit    */
#                values to every SRAM location. This will set the        */
#                 initial ECC (Error Correction Code).                   */ 
# INPUT NOTES  : INT_SRAM_BASE, INT_SRAM_128BYTSEGS (INT_SRAM_SIZE >> 7) */
# RETURN NOTES : None                                                    */
# WARNING      : Registers used: R5                                      */
#*************************************************************************/

cfg_SRAM:

# loop counter to get all of RAM
    lis   r5, INT_SRAM_128BYTSEGS@h     # Number of 128 byte segments
    ori   r5, r5, INT_SRAM_128BYTSEGS@l # Number of 128 byte segments
    mtctr r5                            # configure control register for use with bdnz
    
# base address of the internal SRAM
    lis   r5,SRAM_BASE_ADDR@h
    ori   r5,r5, SRAM_BASE_ADDR@l

sram_loop:
    stmw  r0,0(r5)                      # write all 32 registers to L2RAM
    addi  r5,r5,128                     # increment the ram ptr
    bdnz  sram_loop                     # loop for 64k of L2RAM

    blr   
# End of cfg_SRAM


#**************************************************************************/
# FUNCTION     : cfg_FLASH                                                */
# PURPOSE      : This function reduces the wait states for internal Flash */
#                  and external Flash at CS0                              */
# INPUT NOTES  : IP_ADVANCE, __SRAM_LOAD_SIZE, __SRAM_LOAD,               */
#                cfg_SRAM_LOAD, FLASH_BIUCRREG, FLASH_SETTINGS,           */
#                CS0OR0REG, commented out: CS0_OR_OPTIONS                 */
# RETURN NOTES : None                                                     */
# WARNING      : This SRAM space was set up by the BAM                    */
#                Registers used: R6,R7 (Location is critical for use in   */
#                 SRAM loads).   For local use: R3,R4,R5,R10              */
#                 Registers R8 and R9 are used in commented example for   */
#                  optimization of external Flash boot.                   */
#                __SRAM_LOAD is set to ADDR(.heap)                        */
#**************************************************************************/

cfg_FLASH:
#  Save the Link Register into R3
    mflr  r3  

#********************************
# Prepare registers for SRAM load usage


#  Enter address and settings to reduce Internal Flash wait states
# Prepare R6 and R7 to hole the FLASH_BIUCR address and wait state value
# Set R6 to hold address of FLASH_BIUCR
    lis   r6, FLASH_BIUCRREG@h     # Load upper address of FLASH_BIUCR into R6
    ori   r6, r6, FLASH_BIUCRREG@l # Load lower address of FLASH_BIUCR into R6

# Set R7 to hold value of internal Flash BIU control register (FLASH_BIUCR) settings
    lis   r7, FLASH_SETTINGS@h     # Store upper Flash BIU control
    ori   r7, r7, FLASH_SETTINGS@l # Store lower Flash BIU control

# If using external Flash boot or execution, external Flash wait states 
#     should be configured here. These are not covered here due to the 
#     many external configurations that can occur with external Flash.
#     Example steps are below.

    .if EXT_BOOT

# insert external memory wait state reduction code here

# Prepare R8 and R9  to hold the CS0 address and wait state value
# Set R8 to hold address of CS0OR0REG
#    lis r8, CS0ORREG@h            # Load upper address of CS0 OR0 register
#    ori r8, r8, CS0ORREG@l        # Load lower address of CS0 OR0 register
# Set R9 to hold value of CS0 OR0 register settings
#    lis r9, CS0_OR_OPTIONS@h
#    ori r9, r9, CS0_OR_OPTIONS@l  

    .endif

SRAMLOAD:

# Set the counter (CTR) to the count of the SRAM load size
    lis   r10, __SRAM_LOAD_SIZE@h      # Load upper SRAM load size into R10
    ori   r10,r10, __SRAM_LOAD_SIZE@l  # Load lower SRAM load size into R10
    mtctr r10                      # Move the SRAM load size into the counter

    lis   r10, cfg_SRAM_LOAD@ha       # Load address of first SRAM load 
    addi  r10,r10, cfg_SRAM_LOAD@l
    

# Load SRAM base address (__SRAM_LOAD) for loading instructions into R5
#    (__SRAM_LOAD = ADDR(.heap))
    lis   r5, __SRAM_LOAD@h      # Load upper SRAM address into R5
    ori   r5, r5, __SRAM_LOAD@l  # Load lower SRAM address into R5

SRAMLOADLOOP:
    lwz   r4, 0(r10)             # Load the opcode at R10 into R4
    stw   r4, 0(r5)              # Store R4 opcode into SRAM at R5
    addi  r5, r5,IP_ADVANCE      # Advance the SRAM address to next opcode space
    addi  r10, r10, IP_ADVANCE   # Move address to next opcode space
    bdnz  SRAMLOADLOOP           # Decrement the counter;
#                                # Branch if Counter not zero.  
  
# Call to SRAM
CallSRAMFunction:

# Link register is saved at start of this function into R3
    lis   r5, __SRAM_LOAD@ha     # Load upper SRAM address into R5
    addi  r5, r5, __SRAM_LOAD@l  # Load lower SRAM address into R5
    mtctr r5
    bctrl

# The value of the following registers must be preserved **
#  during the SRAM run:                                  **
#   R6 = Address for FLASH_BIUCR at: 0xC3F8801C          **
#   R7 = Data for FLASH_BIUCR at:    0x00086C35          **
# The assembler commands will be loaded as opcodes into  **
#  SRAM. These are located in file mpc5500_SRAM_load.s   **
#  Additional assembly commands may be added by the user.**
#  If the length of this code is longer than 0xE0, then  **
#  additional space will have to be set aside in the     **
#  linker file for the flash_data length.                **

# Return to Flash code operation
#   Restore the Link Register from R3
    mtlr  r3

    blr
# End of cfg_FLASH


#*****************************************************************************/
# FUNCTION     : cfg_STACK                                                   */
# PURPOSE      : This function initializes and locks a 4K Stack region       */
#                 to be located in Cache. After the stack and the MMU        */
#                 entries are established, C Code can be used in the         */
#                 application.                                               */
# INPUT NOTES  : __STACK_SIZE, __SP_INIT, __SP_END, (defined in linker file) */
#                CACHE_CLEAR, CACHE_SETTINGS, L1CSR0                         */
# RETURN NOTES : None                                                        */
# WARNING      : Registers used: R0(as 0),R1(to set stack ptr),R5, R6        */
#*****************************************************************************/
#
# Stack Size = __STACK_SIZE = (__SP_END - __SP_INIT = 4096) (0x1000) 32-bit constant
#    .equ __STACK_SIZE, 0x1000 (4K is the default size) -- Defined in the linker file
#    .equ __SP_INIT = 0x4001_1000  -- Defined in the linker file
#    .equ __SP_END, (__SP_INIT - __STACK_SIZE) -- Defined in the linker file
#
#    .equ CACHE_CLEAR,(CLFC_NO_OP | CINV_INV_OP | CE_DISABLE)
#    .equ CACHE_SETTINGS, (CWM_COPYBCK | DPB_NOPUSH | CE_ENABLE)


cfg_STACK:

#****************************
# Confirm that no prior cache invalidate operation is in progress
    li    r6, 0x0002              # Set bit[30] in R6 (others are 0)
WaitForInvalidateComplete1:    
    mfspr r5, L1CSR0              # Move L1CSR0 into R5
    and   r5, r5, r6              # Mask out all bits except CINV*
#P&E modification
.if __PEGNU__
    cmpli 0,r5,0x0002             # Compare if CINV, bit 30, = 1
.else
    cmpli r5, 0x0002              # Compare if CINV, bit 30, = 1
.endif
#   cmpli r5, 0x0002              # Compare if CINV, bit 30, = 1 
    beq   WaitForInvalidateComplete1 # Branch if CINV is still 1

#****************************
# Invalidate the Cache first, just to make sure it is cleared

# To activate cache invalidate operation,
# place a "1" in the CINV bit location.  (L1CSR0)
    lis   r5, CACHE_CLEAR@h        # Load upper L1CSR0 (0x0) into R5
    ori   r5, r5, CACHE_CLEAR@l    # Load lower L1CSR0 (CINV bit) into R5  
    msync                          # Before writing to L1CSR0, execute msync & isync
    isync
    mtspr L1CSR0,r5                # Move R5 to the L1CSR0 (SPR 1010)register.  
# This should start the CACHE lock Flash bit clear operation.

#****************************  
# Confirm that cache invalidate operation is complete
#   R6 still equals 0x0002 no need for:   li r6, 0x0002
WaitForInvalidateComplete2:    
    mfspr r5, L1CSR0              # Move L1CSR0 into R5
    and   r5, r5, r6              # Mask out all bits except CINV*
#P&E modification
.if __PEGNU__
    cmpli 0,r5,0x0002             # Compare if CINV, bit 30, = 1
.else
    cmpli r5, 0x0002              # Compare if CINV, bit 30, = 1 
.endif
#   cmpli r5, 0x0002              # Compare if CINV, bit 30, = 1
    beq   WaitForInvalidateComplete2 # Branch if CINV is still 1

#****************************  
# Enable cache (totally unused/invalidated)
    mfspr r5, L1CSR0               # Retrieve the L1CSR0 register value
    oris  r5, r5, CACHE_SETTINGS@h # OR in CWM and DPB in upper L1CSR0[11:12]
    ori   r5, r5, CACHE_SETTINGS@l # OR in cache enable bit L1CSR0[31]
    msync                          # Before writing to L1CSR0, execute msync & isync
    isync
    mtspr L1CSR0, r5               # Return value to L1CSR0 to enable the cache
  
#**************************** 
# Now the Stack in Cache can be set up
 

# Load size of Cache to be used for Stack (4K)
    lis   r5, __STACK_SIZE__@h       # Stack size is 4KBytes
    ori   r5, r5, __STACK_SIZE__@l
# Each stack lock instruction covers 32 bytes, so divide the input parameter
    srwi  r5, r5, 5                # Shift the contents of R5 right by 5 bits (size/32)
    mtctr r5                       # locations per cache line loaded to the CTR (SPR 9) register
    
# Point R5 to just past the system RAM (0x4001_0000). Set in the Linker file.   
    lis   r5, __SP_END__@h    
    ori   r5, r5, __SP_END__@l
  
# Run the loop to lock the cache lines for the stack
# The loop count is: 4KB / 32B = 128 = 0x80 
_cache_loop:
    dcbz   r0, r5                  # Establish address in cache for 32 bytes and zero
    dcbtls 0, r0, r5               # Lock the address into the cache
    addi   r5, r5, 32              # Increment to start of next cache line (+32 bytes)
    bdnz   _cache_loop             # Decrement the counter (CTR), branch if nonzero
                   
# Set the stack pointer
    lis   r1, (__SP_INIT__-0x10)@h
    ori   r1, r1, (__SP_INIT__-0x10)@l

    blr
# End of cfg_STACK


#*****************************************************************************/
# FUNCTION     : cfg_PNTRS                                                   */
# PURPOSE      : This function initializes register pointers for small data  */
#                 (.sbss) in R13 and small data2 (.sdata2) in R2.            */
#                                                                            */
# INPUT NOTES  : _SDA_BASE_, _SDA2_BASE_ (defined by the linker EABI)        */
# RETURN NOTES : None                                                        */
# WARNING      : Registers used: R13(to set .sdata pointer ),                */
#                                R2 (to set .sdata2 pointer)                 */
#                 The BASE addresses are offset by 0x8000 for CW, GHS, P&E   */
#                 and offset by 0x7FF0 for Diab to simplify access to small  */
#                 data.                                                      */
#*****************************************************************************/
/*
cfg_PNTRS:

# Set the small data (.sbss) pointer
    lis   r13, (_SDA_BASE_)@h
    ori   r13, r13, (_SDA_BASE_)@l

# Set the small data2 (.sdata2) pointer
    lis   r2, (_SDA2_BASE_)@h
    ori   r2, r2, (_SDA2_BASE_)@l

    blr
# End of cfg_PNTRS
*/

#*****************************************************************************/
# FUNCTION     : cfg_ROMCPY                                                  */
# PURPOSE      : This function copies initialized data from Flash to SRAM    */
#                 for the ".data" and ".sdata" sections.                     */
#                                                                            */
# INPUT NOTES  : __DATA_ROM -- defined by the linker EABI                    */
#                __ROM_COPY_SIZE -- Flash area size, in bytes, to be copied  */
#                                     into SRAM.                             */
#                __SRAM_CPY_START -- Start of ".data" section                */
#                CPY_OFFSET -- (=1) defined in mpc5500_defs.inc. 1 byte      */
#                                 offset to next data byte address.          */
# RETURN NOTES : None                                                        */
# WARNING      : Registers used: R10 -- to set .data or .sdata ROM pointer   */
#                                R9 -- to hold remaining ROM_COPY_SIZE bytes */
#                                R5 -- to set SRAM pointer                   */
#                                R4 -- hold the copy data                    */
#                                                                            */
#*****************************************************************************/
/*
cfg_ROMCPY:

# Set GPR9 to the count of the SRAM load size
    lis    r9, __ROM_COPY_SIZE@ha   # Load upper SRAM load size (# of bytes) into R9
    addic. r9,r9, __ROM_COPY_SIZE@l # Load lower SRAM load size into R9
                                    #  The "." sets the condition flag

    beq ROMCPYEND                   # Exit cfg_ROMCPY if size is zero

    mtctr  r9                       # Store # of bytes to be moved in spr CTR

    lis   r10, __DATA_ROM@ha        # Load address of first SRAM load into R10
    addi  r10,r10, __DATA_ROM@l     # Load lower address of SRAM load into R10
    subi  r10,r10, CPY_OFFSET       # Decrement address to prepare for ROMCPYLOOP    

# Load SRAM base address (__SRAM_CPY_START) for loading instructions into R5
#    (__SRAM_CPY_START = ADDR(.data))
    lis   r5, __SRAM_CPY_START@h      # Load upper SRAM address into R5
    ori   r5, r5, __SRAM_CPY_START@l  # Load lower SRAM address into R5
    subi  r5, r5, CPY_OFFSET          # Decrement address to prepare for ROMCPYLOOP

ROMCPYLOOP:
    lbzu   r4, CPY_OFFSET(r10) # Load data byte at R10 into R4,incrementing (update) ROM address
    stbu   r4, CPY_OFFSET(r5)  # Store R4 data byte into SRAM at R5 and update SRAM address 
    bdnz   ROMCPYLOOP          # Branch if more bytes to load from ROM

ROMCPYEND: 
    blr
# End of cfg_ROMCPY
*/


#*************************************************************************/
#                        MMU Functions                                   */
#*************************************************************************/

#*****************************************************************************/
# FUNCTION     : cfg_MMU                                                     */
# PURPOSE      : This function modifies the MMU TLB (translation lookaside   */
#                 buffer) table by writing to the appropriate MAS registers. */
# INPUT NOTES  : Requires SPRs defined and a data table for the TLB entries  */
#                mmu_tlb0 through mmu_tlb11, mmu_tlb15 from                  */
#                mpc5500_usrdefs.inc.                                        */
# RETURN NOTES : None                                                        */
# WARNING      : Registers used: R3,R5. Commands "msync" and "isync" are not */
#                required around the tlbwe since we are at configuration and */
#                 other background operations cannot be active.              */
#*****************************************************************************/

.EQU mas0,624
.EQU mas1,625
.EQU mas2,626
.EQU mas3,627

cfg_MMU:


# Change the TLB15 BAM in Flash size to 1M.    
    lis   r3, mmu_tlb15@h     # base address of MAS Constants
    ori   r3,r3, mmu_tlb15@l
    lwz   r5,0(r3)           # Get MAS0 value
    mtspr mas0,r5            # mtspr MAS0,r5
    lwzu  r5,4(r3)           # Get MAS1 value
    mtspr mas1,r5            # mtspr MAS1,r5
    lwzu  r5,4(r3)           # Get MAS2 value
    mtspr mas2,r5            # mtspr MAS2,r5
    lwzu  r5,4(r3)           # Get MAS3 value
    mtspr mas3,r5            # mtspr MAS3,r5
    tlbwe                    # Write the entry to the TLB 


# Change the TLB0 PBRIDGE_B size to 1M.    
    lis   r3, mmu_tlb0@h     # base address of MAS Constants
    ori   r3,r3, mmu_tlb0@l
    lwz   r5,0(r3)           # Get MAS0 value
    mtspr mas0,r5            # mtspr MAS0,r5
    lwzu  r5,4(r3)           # Get MAS1 value
    mtspr mas1,r5            # mtspr MAS1,r5
    lwzu  r5,4(r3)           # Get MAS2 value
    mtspr mas2,r5            # mtspr MAS2,r5
    lwzu  r5,4(r3)           # Get MAS3 value
    mtspr mas3,r5            # mtspr MAS3,r5
    tlbwe                    # Write the entry to the TLB 

# Change the TLB1 Flash (1) size to 1M. Split into 5 areas.    
    lis   r3, mmu_tlb1@h     # base address of MAS Constants
    ori   r3,r3, mmu_tlb1@l
    lwz   r5,0(r3)           # Get MAS0 value
    mtspr mas0,r5            # mtspr MAS0,r5
    lwzu  r5,4(r3)           # Get MAS1 value
    mtspr mas1,r5            # mtspr MAS1,r5
    lwzu  r5,4(r3)           # Get MAS2 value
    mtspr mas2,r5            # mtspr MAS2,r5
    lwzu  r5,4(r3)           # Get MAS3 value
    mtspr mas3,r5            # mtspr MAS3,r5
    msync                    # synchronize for running out of Flash
    tlbwe                    # Write the entry to the TLB 
    isync                    # synchronize for running out of Flash 

# Change the TLB2 External Flash size to 4M.    
    lis   r3, mmu_tlb2@h     # base address of MAS Constants
    ori   r3,r3, mmu_tlb2@l
    lwz   r5,0(r3)           # Get MAS0 value
    mtspr mas0,r5            # mtspr MAS0,r5
    lwzu  r5,4(r3)           # Get MAS1 value
    mtspr mas1,r5            # mtspr MAS1,r5
    lwzu  r5,4(r3)           # Get MAS2 value
    mtspr mas2,r5            # mtspr MAS2,r5
    lwzu  r5,4(r3)           # Get MAS3 value
    mtspr mas3,r5            # mtspr MAS3,r5
    tlbwe                    # Write the entry to the TLB 

# Change the TLB3 SRAM size to 64K.    
    lis   r3, mmu_tlb3@h     # base address of MAS Constants
    ori   r3,r3, mmu_tlb3@l
    lwz   r5,0(r3)           # Get MAS0 value
    mtspr mas0,r5            # mtspr MAS0,r5
    lwzu  r5,4(r3)           # Get MAS1 value
    mtspr mas1,r5            # mtspr MAS1,r5
    lwzu  r5,4(r3)           # Get MAS2 value
    mtspr mas2,r5            # mtspr MAS2,r5
    lwzu  r5,4(r3)           # Get MAS3 value
    mtspr mas3,r5            # mtspr MAS3,r5
    tlbwe                    # Write the entry to the TLB 

# Change the TLB4 PBRIDGE_A size to 1M.    
    lis   r3, mmu_tlb4@h     # base address of MAS Constants
    ori   r3,r3, mmu_tlb4@l
    lwz   r5,0(r3)           # Get MAS0 value
    mtspr mas0,r5            # mtspr MAS0,r5
    lwzu  r5,4(r3)           # Get MAS1 value
    mtspr mas1,r5            # mtspr MAS1,r5
    lwzu  r5,4(r3)           # Get MAS2 value
    mtspr mas2,r5            # mtspr MAS2,r5
    lwzu  r5,4(r3)           # Get MAS3 value
    mtspr mas3,r5            # mtspr MAS3,r5
    tlbwe                    # Write the entry to the TLB 

## Change the TLB5 to invalid to turn off duplicate entries for internal Flash
    lis   r3, mmu_tlb5@h     # base address of MAS Constants
    ori   r3,r3, mmu_tlb5@l
    lwz   r5,0(r3)           # Get MAS0 value
    mtspr mas0,r5            # mtspr MAS0,r5
    lwzu  r5,4(r3)           # Get MAS1 value
    mtspr mas1,r5            # mtspr MAS1,r5
    tlbwe                    # Write the entry to the TLB 

# Change the TLB6 Flash (2) size to 256K.    
    lis   r3, mmu_tlb6@h     # base address of MAS Constants
    ori   r3,r3, mmu_tlb6@l
    lwz   r5,0(r3)           # Get MAS0 value
    mtspr mas0,r5            # mtspr MAS0,r5
    lwzu  r5,4(r3)           # Get MAS1 value
    mtspr mas1,r5            # mtspr MAS1,r5
    lwzu  r5,4(r3)           # Get MAS2 value
    mtspr mas2,r5            # mtspr MAS2,r5
    lwzu  r5,4(r3)           # Get MAS3 value
    mtspr mas3,r5            # mtspr MAS3,r5
    tlbwe                    # Write the entry to the TLB 

# Change the TLB7 Flash (3) size to 256K.    
    lis   r3, mmu_tlb7@h     # base address of MAS Constants
    ori   r3,r3, mmu_tlb7@l
    lwz   r5,0(r3)           # Get MAS0 value
    mtspr mas0,r5            # mtspr MAS0,r5
    lwzu  r5,4(r3)           # Get MAS1 value
    mtspr mas1,r5            # mtspr MAS1,r5
    lwzu  r5,4(r3)           # Get MAS2 value
    mtspr mas2,r5            # mtspr MAS2,r5
    lwzu  r5,4(r3)           # Get MAS3 value
    mtspr mas3,r5            # mtspr MAS3,r5
    tlbwe                    # Write the entry to the TLB 

# Change the TLB8 Flash (4) size to 256K.    
    lis   r3, mmu_tlb8@h     # base address of MAS Constants
    ori   r3,r3, mmu_tlb8@l
    lwz   r5,0(r3)           # Get MAS0 value
    mtspr mas0,r5            # mtspr MAS0,r5
    lwzu  r5,4(r3)           # Get MAS1 value
    mtspr mas1,r5            # mtspr MAS1,r5
    lwzu  r5,4(r3)           # Get MAS2 value
    mtspr mas2,r5            # mtspr MAS2,r5
    lwzu  r5,4(r3)           # Get MAS3 value
    mtspr mas3,r5            # mtspr MAS3,r5
    tlbwe                    # Write the entry to the TLB 

# Change the TLB9 Flash (5) size to 256K.    
    lis   r3, mmu_tlb9@h     # base address of MAS Constants
    ori   r3,r3, mmu_tlb9@l
    lwz   r5,0(r3)           # Get MAS0 value
    mtspr mas0,r5            # mtspr MAS0,r5
    lwzu  r5,4(r3)           # Get MAS1 value
    mtspr mas1,r5            # mtspr MAS1,r5
    lwzu  r5,4(r3)           # Get MAS2 value
    mtspr mas2,r5            # mtspr MAS2,r5
    lwzu  r5,4(r3)           # Get MAS3 value
    mtspr mas3,r5            # mtspr MAS3,r5
    tlbwe                    # Write the entry to the TLB 

# Add TLB10 definition for Stack in CACHE size to 4K.    
    lis   r3, mmu_tlb10@h    # base address of MAS Constants
    ori   r3,r3, mmu_tlb10@l
    lwz   r5,0(r3)           # Get MAS0 value
    mtspr mas0,r5            # mtspr MAS0,r5
    lwzu  r5,4(r3)           # Get MAS1 value
    mtspr mas1,r5            # mtspr MAS1,r5
    lwzu  r5,4(r3)           # Get MAS2 value
    mtspr mas2,r5            # mtspr MAS2,r5
    lwzu  r5,4(r3)           # Get MAS3 value
    mtspr mas3,r5            # mtspr MAS3,r5
    tlbwe                    # Write the entry to the TLB 

# Change the TLB11 External SRAM size to 4M.    
    lis   r3, mmu_tlb11@h    # base address of MAS Constants
    ori   r3,r3, mmu_tlb11@l
    lwz   r5,0(r3)           # Get MAS0 value
    mtspr mas0,r5            # mtspr MAS0,r5
    lwzu  r5,4(r3)           # Get MAS1 value
    mtspr mas1,r5            # mtspr MAS1,r5
    lwzu  r5,4(r3)           # Get MAS2 value
    mtspr mas2,r5            # mtspr MAS2,r5
    lwzu  r5,4(r3)           # Get MAS3 value
    mtspr mas3,r5            # mtspr MAS3,r5
    tlbwe                    # Write the entry to the TLB 

# Change the TLB14 Shadow Block size to 4K.    
    lis   r3, mmu_tlb14@h     # base address of MAS Constants
    ori   r3,r3, mmu_tlb14@l
    lwz   r5,0(r3)           # Get MAS0 value
    mtspr mas0,r5            # mtspr MAS0,r5
    lwzu  r5,4(r3)           # Get MAS1 value
    mtspr mas1,r5            # mtspr MAS1,r5
    lwzu  r5,4(r3)           # Get MAS2 value
    mtspr mas2,r5            # mtspr MAS2,r5
    lwzu  r5,4(r3)           # Get MAS3 value
    mtspr mas3,r5            # mtspr MAS3,r5
    tlbwe                    # Write the entry to the TLB 

    blr
# End of cfg_MMU 


#*************************************************************************
