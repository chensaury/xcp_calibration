#**************************************************************************/
#* File: mpc5500_SRAM_load.s                 COPYRIGHT (c) Freescale 2004 */
#*                                                  All Rights Reserved   */
#*                                                                        */
#* Description: This section file contains assembly commands which will   */
#*               be loaded as opcodes from Flash into SRAM.               */
#*               These opcodes will then run out of SRAM to configure     */
#*               the Flash control of the MPC5500 family device.          */
#*                                                                        */
#* Section: .flash_data                                                   */
#*                                                                        */
#* NOTES:  The section .flash_data is placed into internal Flash.         */
#*           Additional space will automatically be generated as needed   */
#*           by the variable __SRAM_LOAD_SIZE in the linker file.         */
#**************************************************************************/
#* REV      AUTHOR        DATE        DESCRIPTION OF CHANGE               */
#* ---   -----------    ----------    ---------------------               */
#* 0.1   G. Jackson     26/Apr/04         Initial version                 */
#* 0.2   G. Jackson     25/May/04      Changed name from mpc5500_opcode.s */
#*                                       to mpc5500_SRAM_load.s.          */
#*                                     Changed pointer cfg_OPCODE to      */
#*                                       cfg_SRAM_LOAD                    */
#* 1.0   G. Jackson    12/Oct/04    Green Hills now does not require      */
#*                                    quotation marks around the section  */
#**************************************************************************/

    .include "mpc5500_usrdefs.inc"
    .globl cfg_SRAM_LOAD
         
    .if __PEGNU__    
    .section ".flash_data","ax"
    .endif

    .if __CWWRKS__ | __DIABCC__ | __GRNHS__
    .section .flash_data
    .endif


#****************************************************************************/
# FUNCTION     : cfg_SRAM_LOAD                                              */
# PURPOSE      : This function supplies the opcodes to be stored into the   */
#                  SRAM for reprogramming the FLASH wait states.            */
#                  Internal Flash read wait states change from 7 to 2       */
#                  Internal Flash write wait states change from 3 to 1      */
# INPUT NOTES  : None                                                       */
# RETURN NOTES : None                                                       */
# WARNING      : The number of assembly instructions below is automatically */
#                calculated for the variable __SRAM_LOAD_SIZE in the linker */
#                    file.                                                  */
#                Registers used: R6,R7                                      */
#                               (stored in mpc5500_asmcfg.s cfg_FLASH):     */
#                The value of the following registers must be preserved     */
#                   during the SRAM run:                                    */
#                    R6 = Address for FLASH_BIUCR at: 0xC3F8801C            */
#                    R7 = Data for FLASH_BIUCR at:    0x00086C35            */
#                    R8 = optional address for CS0 OR0 external Flash boot  */
#                           CS0 OR0 at:  0xC3F84014                         */
#                    R9 = optional data for CS0 OR0 external Flash boot     */
#                             Data is :  0xFF800020                         */
#                Additional opcode space is automatically generated if      */
#                     additional code is added to this file.                */
#****************************************************************************/

cfg_SRAM_LOAD:
    stw   r7, 0(r6)    # Reduce internal Flash wait states in the FLASH_BIUCR
#    stw   r9, 0(r8)   # commented out command for optimizing external Flash boot
    isync
    blr

# End of cfg_SRAM_LOAD


            
#*************************************************************************
#*                           End of SRAM_load
#*************************************************************************

