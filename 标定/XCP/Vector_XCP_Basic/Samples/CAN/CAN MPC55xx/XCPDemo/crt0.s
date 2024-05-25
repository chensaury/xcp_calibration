.text

#******************************************************************************

.extern cfg_CACHE        # Defined in mpc5500_asmcfg.s
.extern cfg_FMPLL        # Defined in mpc5500_asmcfg.s
.extern cfg_SRAM         # Defined in mpc5500_asmcfg.s
.extern cfg_FLASH        # Defined in mpc5500_asmcfg.s
.extern cfg_MMU          # Defined in mpc5500_asmcfg.s
.extern cfg_STACK        # Defined in mpc5500_asmcfg.s
.extern cfg_PNTRS        # Defined in mpc5500_asmcfg.s
.extern cfg_ROMCPY       # Defined in mpc5500_asmcfg.s

#******************************************************************************

.global	_start
.global otm

.global mfDBCR0


#******************************************************************************
_start:

  .byte  0x00   #no watchdog
  .byte  0x5A   #Boot identifier 
  .byte  0x00
  .byte  0x00
  .byte  0x00   #start of program on address 0x00000008
  .byte  0x00
  .byte  0x00
  .byte  0x08
   
  nop
  nop
  nop
  nop
  nop

  bl cfg_CACHE   # Invalidate and enable unified cache.
                 # The cache is invalidated and enabled before the
                 # FMPLL is sped up to reduce the peak power demand  
                 # of the cache start up sequence. 

  bl cfg_SRAM    # Write to all SRAM locations for ECC functionality.

  bl cfg_FMPLL   # Set up the FMPLL functions in  mpc5500_asmcfg.s
 
  bl cfg_FLASH   # Reduce Wait States for Internal and External Flash

  bl cfg_MMU

  bl cfg_STACK


  /* calculate address of _Lconst_table */
  bl _Lref1                  /* get current address */
_Lref1:
	mflr r4                    /* r4=address of _Lref1 */
	lwz	r5,(_Lref2-_Lref1)(r4) /* r5=offset to first constant */
	add	r5,r5,r4		           /* r5=address of first consrant */

  /* init stack */
  /*lwz sp,(_Lstack_end-_Lconst_table)(r5)*/
  /*lwz sp,(_Lstack_end-_Lconst_table)(r5)*/

  /* clear sbss */
	lwz	r6,_Lsbss_start-_Lconst_table(r5)   /* calculate beginning of the BSS */
	lwz r7,_Lsbss_end-_Lconst_table(r5)   /* calculate end of the BSS */
  bl _LZeroMem

  /* clear bss */
	lwz	r6,_Lbss_start-_Lconst_table(r5)   /* calculate beginning of the BSS */
	lwz r7,_Lbss_end-_Lconst_table(r5)   /* calculate end of the BSS */
  bl _LZeroMem
  
  /* copy initialized data */
	lwz	r6,_Ldata_start-_Lconst_table(r5)   /* calculate beginning of the BSS */
	lwz r7,_Ldata_end-_Lconst_table(r5)   /* calculate end of the BSS */
  lwz r10,_Linit_data_start-_Lconst_table(r5)   /* calculate end of the BSS */
  cmplw 1,r6,r7
  bc 4,4,_LCopyDone
  subf r8,r6,r7   /* number of bytes to copy */
  srwi r9,r8,2		/* number of words to copy */
  mtctr r9
  addi r6,r6,-4		/* adjust so we can use stwu */
  addi r10,r10,-4		/* adjust so we can use lwzu */
_LCopyLoop:
  lwzu r0,4(r10)
  stwu r0,4(r6)		
  bdnz _LCopyLoop
_LCopyDone:  


  #**************************************
  # Prepare a terminating stack record. 
  
  li   r0, 0xFFFF@l
  stwu r1, -8(r1)   # Decrement stack by 8 bytes, (write word)
  stw  r0, 4(r1)    # Make an illegal return address of 0xFFFFFFFF 
  stw  r0, 0(r1)    # Make an illegal back chain address of 0xFFFFFFFF


  #**************************************
  # Branch to main program

  bl main  



  #**************************************
  /* zero memory from r6 to r7 */
_LZeroMem:
  cmplw 1,r6,r7
  bc 4,4,_LZeroMemDone

  subf r8,r6,r7   /* number of bytes to zero */
  srwi r9,r8,2		/* number of words to zero */
  mtctr r9
  li r0,0			    /* zero to clear memory */
  addi r6,r6,-4		/* adjust so we can use stwu */
_LZeroMemLoop:
  stwu r0,4(r6)		/* zero bss */
  bdnz _LZeroMemLoop
_LZeroMemDone:
  blr

otm:
 mtspr 48,r3
 blr


mfDBCR0:
 mfspr r3,308
 blr
 
 


  /* constants */
_Lref2:                           
  .long _Lconst_table-_Lref1   /* _Lref2 holds offset between _Lconst_start and PC obtained when _start is called */           

_Lconst_table:
_Ldata_start:
  .long __DATA_START__ 
_Ldata_end:
  .long __DATA_END__
_Linit_data_start:
  .long __INIT_DATA_START__  
  
  
  
  
_Lstack_end:
  /*.long __STACK_END__ */
  .long 0
_Lbss_start:
  .long __bss_start__
_Lbss_end:
  .long __bss_end__
_Lsbss_start:
  .long __sbss_start__
_Lsbss_end:
  .long __sbss_end__


.end


