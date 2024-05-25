; @(#)cstart.asm	1.42
;*****************************************************************************
;*
;* MODULE	: cstartex.asm (RAM)
;*
;* DESCRIPTION	: Startup code for the 80166/80167
;*
;*		- Processor initialization.
;*		- Initialization of static variables in internal or external
;*		  ram. C variables which have to be initialized are specified
;*		  in ROM section C166_INIT. C variables which must
;*		  be cleared are specified in ROM section C166_BSS.
;*		- Set user stack pointer.
;*		- Call the user program: main().
;*		- On exit cpu is set in idle mode.
;*
;* COPYRIGHTS	: Tasking B.V., Amersfoort 1990
;* modified     : 12.02.1993 V. Ebner,  Vector Informatik GmbH,
;*                07.02.1997 W. Janz (OSEK, P-Option)
;*
;*****************************************************************************

; Following defines can be set on the command line of the macro pre-processor,
; with the DEFINE() control. ( Syntax:  DEFINE( identifier [, replacement] )
;			       Example: DEFINE( MODEL, LARGE ) )

@IF( ! @DEFINED( @C167 ) )
@SET( C167, 0 )			; set to 1 for 80167 derivate
@ENDI


@IF( ! @DEFINED( @FUZZY_DEMO ) )
@SET( FUZZY_DEMO, 0 )		; set to 1 for fuzzy-166 evaluation kit
@ENDI

@IF( ! @DEFINED( @PXROS ) )
@SET( PXROS, 1 )		; set to 1 for PXROS support
@ENDI

@IF( ! @DEFINED( @EVA ) )
@SET( EVA, 0 )			; set to 1 when execution environment is ertec
				; EVA166/EVA167 or EPC166. Needed to:
				;  1)	force tiny model to execute with
				;	segmentation enabled.
				;  2)	do not clear monitor data in
				;	bit-addressable area.
				;  3)	run application with interrupts
				;	enabled, allowing the monitor to
				;	break it (not needed for EPC166).
				;  4)   define symbols that can be used by
				;       a debugger to initialize the EVA167 
				;       before monitor or user program is
				;       downloaded.
				; Hardware is expected to be configured for
				; non-multiplexed bus mode to get the maximum
				; performance.
@ENDI

@IF( ! @DEFINED( @EX_AB ) )
@SET( EX_AB, 0 )		; enable EX_AB if the function 'exit()' or
				; 'abort()' is used else it can be disabled.
@ENDI

@IF( ! @DEFINED( @FLOAT ) )
@SET( FLOAT, 0 )		; enable FLOAT if floating point functions are
				; used else it can be disabled.
@ENDI

@IF( ! @DEFINED( @BIT_INIT ) )
@SET( BIT_INIT, 0 )		; enable initialization of bit variables at
				; startup. Only needed if "bit b = 1;" is used.
@ENDI

@IF( @C167 )
$EXTEND				; enable all 80167 extensions
$NOMOD166			; disable the internal set of 80166 SFRs
$STDNAMES(reg167b.def)		; load set of 80167 SFRs from reg167b.def
@ENDI

@IF( @FUZZY_DEMO )
@MATCH( MODEL, "TINY" )		; override memory model selected
@SET( EVA, 0 )			; execution environment is fuzzy-166
				; evaluation kit, tiny memory model
@ENDI
				; set assembler controls.
@IF( @DEFINED( @MODEL ) )
@IF( @EQS(@MODEL,"SMALL") )
$MODEL(small)
$NONSEGMENTED
@ENDI
@IF( @EQS(@MODEL,"TINY") )
$MODEL(tiny)
$NONSEGMENTED
@ENDI
@IF( @EQS(@MODEL,"MEDIUM") )
$MODEL(medium)
$SEGMENTED
@ENDI
@IF( @EQS(@MODEL,"LARGE") )
$MODEL(large)
$SEGMENTED
@ENDI
@ELSE					; Default memory model is SMALL
@MATCH( MODEL, "SMALL" )
$MODEL(small)
$NONSEGMENTED
@ENDI
$CASE
$GENONLY
$DEBUG
$NOLOCALS

	NAME	CSTART			; module name.
	
@IF( @EQS(@MODEL,"LARGE") | @EQS(@MODEL,"SMALL") )
	EXTERN	_main:FAR		; start label user program.
@ELSE
	EXTERN	_main:NEAR		; start label user program.
@ENDI
        ;EXTERN  _bRestartFromError:BYTE

	PUBLIC	__IDLE			; cstart end
	PUBLIC	__EXIT			; address to jump to on 'exit()'.
        PUBLIC  RECOVERY                ; address to jump after error recovery

@IF( @EX_AB )
@IF( @EQS(@MODEL,"LARGE") | @EQS(@MODEL,"SMALL") )
	EXTERN	_exit:FAR		; exit()
@ELSE
	EXTERN	_exit:NEAR		; exit()
@ENDI
@ENDI

@IF( @EQS(@MODEL,"MEDIUM") | @EQS(@MODEL,"LARGE") )
ASSUME	DPP3:SYSTEM			; assume system data page pointer.
@IF( @FLOAT )
ASSUME	DPP2:?FPSTKUN
ASSUME	DPP2:?FPSP
@ENDI
@ENDI

	; Value definitions for System Configuration Register : SYSCON/BUSCON0
	; 'Default' is the value after reset.
@IF( @C167 )
	; Memory Cycle Time is extended by a number of additional State Times.
	; in a range from 0 through 15. BUSCON0[3..0]
	__MCTC		LIT	'2'	; Memory wait states is 1 (MCTC = 0EH).
					; (Default=15 additional state times)
	; The Read/Write Signal Delay is 0.5 or 0 State Times. BUSCON0.4
	__RWDC0		LIT	'1'	; 0 = Delay Time (Default)
					; 1 = No Delay Time
	; Memory Tri-state is extended by either 1 or 0 State Times. BUSCON0.5
	__MTTC0		LIT	'0'	; 0 = Delay Time (Default)
					; 1 = No Delay Time

	; External bus configurations. BUSCON0[7..6]
					; Default state is determined by the
					; state of the port pins P0L.7 and P0L.6
					; at reset. 
					; Note: coding changed in the C167
					
	; ALE Signal is lengthened by either 1 or 0 State Times. BUSCON0.9
	__ALECTL0	LIT	'0'	; 1 = Delay Time (Default if pin #EA is
					;     low)
					; 0 = No Delay Time (Default if pin #EA
					;     is high)
	; Do not disable the ALE lengthening option for a multiplexed bus
	; configuration. See problem 17 in errata sheet SAB-C167A-LM,ES-AC,1.1
	; on page 4/9.
	
	; READY# Input Enable control bit. BUSCON0.12
	__RDYEN0	LIT	'0'	; 0 = disabled (Default)
					; 1 = enabled

	; Process BUSCON0 low byte and high byte values
	BUSC0_L		EQU	((__MTTC0<<5) | (__RWDC0<<4) | ((~__MCTC)&000Fh))
	BUSC0_H		EQU	((__RDYEN0<<4) | (__ALECTL0<<1))
	BUSC0_M_L	EQU	03Fh	; Mask low byte BUSCON0
	BUSC0_M_H	EQU	012h	; Mask high byte BUSCON0
	
	; Write Configuration Mode Control Bit (CLKOUT) Enable bit. SYSCON.7
	__WRCFG 	LIT	'0'	; 0 = Normal operation of WR# end BHE# (default)
					; 1 = WR# acts as WRL#. BHE# acts as WRH#
					
	; System Clock Output (CLKOUT) Enable bit. SYSCON.8
	__CLKEN		LIT	'0'	; 0 = disabled (Default)
					; 1 = enabled

	; Byte High Enable (BHE#) pin control bit. SYSCON.9
	__BYTDIS	LIT	'0'	; 0 = enabled (Default)
					; 1 = disabled

	; Internal ROM Access Enable (Read Only). SYSCON.10
					; Default state is determined by the state
					; of the #EA pin at reset

	; Segmentation Disable control bit. SYSCON.11
@IF( @EQS( @MODEL, "TINY" )  &  NOT (@EVA) )
	__SGTDIS	LIT	'1'	; Disable segmented memory mode
					; for TINY model and NOT EVA
@ELSE
	__SGTDIS	LIT	'0'	; Default is segmentation enabled
@ENDI

	; ROM Segment Mapping control bit. SYSCON.12
	__ROMS1		LIT 	'0'	; 0 = Internal ROM mapped to segm.0 (default)
					; 1 = Internal ROM mapped to segm.1

	; Stack Size selection of between 32 and 512 words. SYSCON[15..13]
	__STKSZ		LIT	'0'	; System stack sizes
					; 0 = 256 words (Default)
					; 1 = 128 words
					; 2 =  64 words
					; 3 =  32 words
					; 4 = 512 words
					; 7 = No wrapping

	; Process SYSCON low byte and high byte values.
	SYSC_L  	EQU	(__WRCFG << 7)
	SYSC_H  	EQU  	((__STKSZ << 5) | (__ROMS1 << 4) | (__SGTDIS<<3) | (__BYTDIS<<1) | __CLKEN)
	SYSC_M_L	EQU	080H	; Mask low byte SYSCON.
	SYSC_M_H	EQU	0FBH	; Mask high byte SYSCON.
@IF( @EVA )
	; Symbols __EVA_SYSCON and __EVA_MEMSZ should be defined when the 
	; XVW166 debugger uses the EVA167 target board as its execution
	; environment.
	; They let the debugger configure the target environment correctly 
	; before the boot program downloads the monitor program MON167.
	; 
	__MEMSZ		LIT	'0'	; EVA167 Memory configuration
					; 0 =  1 MBit RAM (Default)
					; 1 =  2 MBit RAM
					; 2 =  4 MBit RAM

	__EVA_SYSCON	EQU	((SYSC_H << 8) | SYSC_L)
	__EVA_MEMSZ	EQU	__MEMSZ
	PUBLIC	__EVA_SYSCON,__EVA_MEMSZ
@ENDI
@ELSE
@IF( @FUZZY_DEMO )
	__MCTC		LIT	'0FH'	; Memory wait states is 15 (MCTC = 00H).
	__RWDC		LIT	'0'	; Delay Time
	__MTTC		LIT	'1'	; No Delay Time
@ELSE
	; Memory Cycle Time is extended by a number of additional State Times.
	; in a range from 0 through 15. SYSCON[3..0]
	__MCTC		LIT	'1'	; Memory wait states is 1 (MCTC = 0EH).
					; (Default=15 additional state times)
					; At least 1 waitstate is needed
					; for EVA166 to meet the EPROM
					; specification.
	; The Read/Write Signal Delay is 0.5 or 0 State Times. SYSCON.4
	__RWDC		LIT	'1'	; 0 = Delay Time (Default)
					; 1 = No Delay Time
					; If multiplexed bus mode is selected
					; RWDC must be set to 0 for EVA166.
	; Memory Tri-state is extended by either 1 or 0 State Times. SYSCON.5
	__MTTC		LIT	'0'	; 0 = Delay Time (Default)
					; 1 = No Delay Time
					; Default is expected that Tri-state
					; delay is needed for memory.
@ENDI

	; BTYP is read only for external bus configurations. SYSCON[7..6]

	; System Clock Output (CLKOUT) Enable bit. SYSCON.8
	__CLKEN		LIT	'0'	; 0 = disabled (Default)
					; 1 = enabled

	; Byte High Enable (BHE#) pin control bit. SYSCON.9
	__BYTDIS	LIT	'0'	; 0 = enabled (Default)
					; 1 = disabled

	; Internal ROM Access Enable (Read Only). SYSCON.10

	; Segmentation Disable control bit. SYSCON.11
@IF( @EQS( @MODEL, "TINY" )  &  NOT (@EVA) )
	__SGTDIS	LIT	'1'	; Disable segmented memory mode .
					; for TINY model and NOT EVA
@ELSE
	__SGTDIS	LIT	'0'	; Default is segmentation enabled.
@ENDI

	; READY# Input Enable control bit. SYSCON.12
	__RDYEN		LIT	'0'	; 0 = disabled (Default)
					; 1 = enabled

	; Stack Size selection of between 32 and 256 words. SYSCON[14..13]
	__STKSZ		LIT	'0'	; System stack sizes
					; 0 = 256 words (Default)
					; 1 = 128 words
					; 2 =  64 words
					; 3 =  32 words

	; Process SYSCON low byte and high byte values.
	SYSC_L  	EQU	((__MTTC << 5) | (__RWDC << 4) | ((~__MCTC) & 000FH))
	SYSC_H  	EQU  	((__STKSZ << 5) | (__RDYEN <<4) | (__SGTDIS << 3) | (__BYTDIS << 1) | __CLKEN)
	SYSC_M_L	EQU	03FH	; Mask low byte SYSCON.
	SYSC_M_H	EQU	07BH	; Mask high byte SYSCON.
@ENDI
	
	; Predefined functions for register R1, R2 and R3.
	POF_RAM		LIT	'R1'	; Page offset address ram data.
	SOF_RAM		LIT	'R1'	; Segment offset address ram data.
	SOF_RAM_H	LIT	'RH1'	; Segment address high byte.
	POF_ROM		LIT	'R2'	; Page offset address rom data.
	SOF_ROM		LIT	'R2'	; Segment offset address rom data.
	SOF_ROM_H	LIT	'RH2'	; Segment address high byte.
	BP_RAM		LIT	'R3'	; Bit position ram data

;*****************************************************************************
;* __CSTART
;*****************************************************************************
__CSTART_PR	SECTION CODE WORD PUBLIC 'CPROGRAM'
__CSTART 	PROC TASK __CSTART_TASK INTNO __CSTART_INUM = 00H

	DISWDT				; Disable watchdog timer.


						; Set SYSCON register.
	;BFLDL	SYSCON, #SYSC_M_L, #(SYSC_L AND SYSC_M_L)
	;BFLDH	SYSCON, #SYSC_M_H, #(SYSC_H AND SYSC_M_H)
        MOV     SYSCON, #0004h          ; 256 Word Stack, XRAM enabled

        ;MOV     SYSCON, #0000h          ; 256 Word Stack, XRAM disabled
@IF( @C167 )
						; Set BUSCON0 register.
	;BFLDL	BUSCON0, #BUSC0_M_L, #(BUSC0_L AND BUSC0_M_L)
	;BFLDH	BUSCON0, #BUSC0_M_H, #(BUSC0_H AND BUSC0_M_H)
@ENDI
        MOV     BUSCON0, #049Dh         ; FlashEPROM, 2 Waitstates

        MOV     ADDRSEL1, #0406h        ; RAM 256 kByte with Flash
        MOV     BUSCON1, #049Dh	        ; first addrsel, then buscon


        ;MOV     ADDRSEL2, #0000h        ;
        ;MOV     BUSCON2,  #0000h        ; unused, to avoid memory malfunction
        ;MOV     ADDRSEL3, #0000h        ;
        ;MOV     BUSCON3,  #0000h        ;

        MOV     ADDRSEL4, #0806h        ; Start 0x80000: size 255
        MOV     BUSCON4, #0440h	        ; extern Bus enable ;8 bit multiplexed;
                                        ; 15 Waitstates

	MOV	STKOV,	#?SYSSTACK_BOTTOM + 6*2	; Set stack underflow pointer.
	MOV	STKUN,	#?SYSSTACK_TOP		; Set stack overflow pointer.
	MOV	SP,	#?SYSSTACK_TOP		; Set stack pointer.

	MOV	CP, 	#osek_sys_rb		; Set context pointer.  ####2####
@IF( NOT @C167 )
	BSET	P3.13			; Set WR output high.
	BSET	DP3.13			; enable output of WR strobe.
@ENDI
	EINIT				; End of initialization
      
        MOV     DP8, #0FFh  ;     /* digital outputs   */
        MOV     P8,  #0FFh  ;     /* alle dig outs aus */

        ;MOV     DPP0, #PAG _bRestartFromError
        ;MOV     R0,   #POF _bRestartFromError
        ;MOV     R1,   #0
        ;MOVB    [R0], RL1
RECOVERY: LABEL FAR
	MOV	STKOV,	#?SYSSTACK_BOTTOM + 6*2	; Set stack underflow pointer.
	MOV	STKUN,	#?SYSSTACK_TOP		; Set stack overflow pointer.
	MOV	SP,	#?SYSSTACK_TOP		; Set stack pointer.

	MOV	CP, 	#osek_sys_rb		; Set context pointer.  ####2####

@IF( @EVA )
	BOTTOM_BITRAM	LIT  '0FD4CH'	; 0FD00H - 0FD4BH is monitor data area
@ELSE
	BOTTOM_BITRAM	LIT  '0FD00H'
@ENDI
					; Clear bit addressable memory
	MOV	R0, #0FDFEH		; R0 = top of bit addressable area
loop:	CMP	R0, #osek_sys_rb        ; if( R0 in bit addressable area )      ####2####
	JMP	CC_EQ, cbclr		; then continue next (bit) word clear.
	MOV	[R0], zeros		; clear
cbclr:	CMPD2	R0, # BOTTOM_BITRAM	; if( not bottom bit addressable area )
	JMP	CC_NE, loop		; then continue next (bit) word clear

	; The following code is needed for initialization of static variables
@IF( @EQS(@MODEL,"SMALL") )
	MOV	DPP0, #PAG ?BASE_DPP0	; Set data page pointer.
	MOV	DPP1, #PAG ?BASE_DPP1	;
	MOV	DPP2, #PAG ?BASE_DPP2	;
@ENDI
					 ; C166_INIT
@IF( @EQS(@MODEL,"MEDIUM") | @EQS(@MODEL,"LARGE") | @EQS(@MODEL,"SMALL") )
	MOV	R4,  #POF ?C166_INIT_HEAD ; move intra-page offset address rom
					 ; data section C166_INIT to R4
INIT_DPP0:				 ;
	MOV	DPP0,#PAG ?C166_INIT_HEAD ; load data page pointer register DPP0
					 ; with data page of rom data C166_INIT
	NOP				 ; delay for pipeline effect
@ENDI
@IF( @EQS( @MODEL, "TINY" ) )
	MOV	R4, #?C166_INIT_HEAD	; move intra-segment offset address of
					; rom data section C166_INIT to R4
@ENDI
INIT:					;
	MOV	R5, [R4+]		; INIT block header code -> R5
	CMP	R5, #01H		; check if header code 1 (bit)
	JMP	CC_EQ, INIT_01		;

@IF( @EQS(@MODEL,"TINY") | @EQS(@MODEL,"SMALL") )
	CMP	R5, #05H		; check if header code is 5 (near)
    @IF( @EQS(@MODEL,"SMALL") )
	JMP	CC_EQ, INIT_05		;
    @ELSE
	JMP	CC_NE, INIT_END		; if(no header code) end initialization
    @ENDI
@ENDI
@IF( @EQS(@MODEL,"MEDIUM") | @EQS(@MODEL,"LARGE") | @EQS(@MODEL,"SMALL") )
	CMP	R5, #06H		; check if header code 6 (far)
	JMP	CC_EQ, INIT_06		;
	CMP	R5, #07H		; check if header code 7 (huge)
	JMP	CC_NE, INIT_END		; if(no header code) end initialization

INIT_07:				; initialize huge ram data. (data > 64K)
	MOV	SOF_RAM, [R4+]		; move intra-segment offset address ram
					; data block to SOF_RAM=R1
	MOV	R3, [R4+]		; move segment address ram data block 
					; to register R3
					; process data page number ram data
	MOV	RH3, SOF_RAM_H		; R3.15:14=lower order bits of data page
	ROL	R3, #2			; R3.3:2:1:0 = data page number
	AND	R3, #0FH		; clr bit R3.15 to bit R3.4
	MOV	DPP1, R3		; load data page pointer register DPP1
					; with data page of ram data block
	BFLDH	SOF_RAM, #0C0H, #040H	; DPP1:POF_RAM ->SOF_RAM=R1
					;
	MOV	SOF_ROM, [R4+]		; move intra-segment offset address rom
					; data block to SOF_ROM=R2
	MOV	R3, [R4+]		; move segment address rom data block
					; to R3
					; process data page number rom data
	MOV	RH3, SOF_ROM_H		; R3.15:14=lower order bits of data page
	ROL	R3, #2			; R3.3:2:1:0 = data page number
	AND	R3, #0FH		; clr bit R3.15 to bit R3.4
	MOV	DPP2, R3		; load data page pointer register DPP2
					; with data page of rom data block
	BFLDH	SOF_ROM, #0C0H, #080H	; DPP2:POF_ROM ->SOF_ROM=R2
					;
	MOV	R5, [R4+]		; number of bytes (R6:R5) to move from
	MOV	R6, [R4+]		; rom to ram. MSW=R6, LSW=R5 (long word)
					;
MB07_3:	CMPD1	R5, #0			; test if all bytes are moved and
	JMP	CC_NE, MB07_1 		; decrement number of bytes to move.
	CMPD1	R6, #0			;
@IF( @EQS( @MODEL, "SMALL" ) )
	JMP	CC_EQ, MB07_4		;
@ELSE
	JMP	CC_EQ, INIT		; if( block end ) next initialization
@ENDI
MB07_1:	MOVB	[SOF_RAM], [SOF_ROM]	; move byte from rom to ram
	CMPI1	SOF_RAM, #07FFFH	; test end of data page and inc SOF_RAM
	JMP	CC_NE, MB07_2		; if(no page end) cont init current page
	MOV	SOF_RAM, #04000H	; preset offset address ram data
	ADD	DPP1, #1		; next page of ram data; increment DPP1
MB07_2:	CMPI1	SOF_ROM, #0BFFFH	; test end of page and inc SOF_ROM
	JMP	CC_NE, MB07_3		; if(no page end) cont init current page
	MOV	SOF_ROM, #08000H	; preset offset address rom data
	ADD	DPP2, #1		; next page of rom data; increment DPP2
	JMP	CC_UC, MB07_3		; jump for next byte move
@IF( @EQS( @MODEL, "SMALL" ) )
MB07_4:	MOV 	DPP1, #PAG ?BASE_DPP1	; restore data page register DPP1 and
	MOV 	DPP2, #PAG ?BASE_DPP2	; DPP2 to their default values.
	JMP	CC_UC, INIT		; next initialization
@ENDI

INIT_06:				; initialize far ram data. (CPU mode 
					; is segmented with DPP usage linear
					; or paged.)
	MOV	POF_RAM, [R4+]		; move intra-page offset address ram
					; data block to POF_RAM=R1
	BFLDH	SOF_RAM, #0C0H, #040H	; DPP1:POF_RAM ->SOF_RAM=R1
	MOV	DPP1, [R4]		; load data page pointer register DPP1
					; with data page of ram data block
	ADD	R4, #2			; inc offset address to ram data section
					; C166_INIT and also insure a delay for
					; pipeline effect.(DPP1 set)
					;
	MOV	POF_ROM, [R4+]		; move intra-page offset address rom
					; data block to POF_ROM=R2
	BFLDH	SOF_ROM, #0C0H, #080H	; DPP2:POF_ROM ->SOF_ROM=R2
	MOV	DPP2, [R4]		; load data page pointer register DPP2
					; with data page of rom data block
	ADD	R4, #2			; inc offset address to rom data section
					; C166_INIT and also insure a delay for
					; pipeline effect.(DPP2 set)
					;
	MOV	R5, [R4+]		; number of bytes to move from rom to
					; ram for specified data block.
					;
MB06_1:	CMPD1	R5, #0			; test on data block end
@IF( @EQS( @MODEL, "SMALL" ) )
	JMP	CC_EQ, MB06_2		;
@ELSE
	JMP	CC_EQ, INIT		; if( block end ) next initialization
@ENDI
	MOVB	[SOF_RAM], [SOF_ROM+]	; move byte from rom to ram, inc SOF_ROM
	ADD	SOF_RAM, #1		; inc SOF_RAM
	JMP	CC_UC, MB06_1		; jump for next byte move
@IF( @EQS( @MODEL, "SMALL" ) )
MB06_2:	MOV 	DPP1, #PAG ?BASE_DPP1	; restore data page register DPP1 and
	MOV 	DPP2, #PAG ?BASE_DPP2	; DPP2 to their default values.
	JMP	CC_UC, INIT		; next initialization
@ENDI
@ENDI

@IF( @EQS(@MODEL,"TINY") | @EQS(@MODEL,"SMALL") )
INIT_05:				; initialize near ram data. (DPP usage
					; is linear, CPU mode is segmented
					; for SMALL memory model and not
					; segmented for TINY memory model.)
	MOV	SOF_RAM, [R4+]		; move intra-segment offset address ram
					; data block to SOF_RAM=R1
					;
	MOV	SOF_ROM, [R4+]		; move intra-segment offset address rom
					; data block to SOF_ROM=R2
					;
	MOV	R5, [R4+]		; number of bytes to move from rom to
					; ram for specified data block.
@IF( @EQS( @MODEL, "SMALL" ) )
	MOV	DPP0, #PAG ?BASE_DPP0	; restore DPP0 to its default value
@ENDI
MB05_1:	CMPD1	R5, #0			; test on data block end, and delay
					; for pipeline effect if DPP0 is
					; restored for SMALL memory model.
@IF( @EQS( @MODEL, "TINY" ) )
	JMP	CC_EQ, INIT 		; if( block end ) next initialization
@ELSE
	JMP	CC_EQ, INIT_DPP0	; if( block end ) reload data page
					; pointer register DPP0 with data page
					; of rom data C166_INIT and start next
					; initialization.
@ENDI
	MOVB	[SOF_RAM], [SOF_ROM+]	; byte move rom to ram, inc SOF_ROM
	ADD	SOF_RAM, #1		; inc SOF_RAM
	JMP	CC_UC, MB05_1		; jump for next byte move
@ENDI

@IF( @BIT_INIT )
INIT_01:				; initialize bit data.
	MOV	BP_RAM, [R4+]		; move bit position ram data block to 
					; BOF_RAM=R3
	MOV	POF_RAM, [R4+]		; mov bit offset address ram data block
					; to POF_RAM=R1
@IF( @EQS( @MODEL, "TINY" ) )
	MOV	R5, [R4+]		; move data page of ram data block to R5
	SHL	R5, #14			; position page number
	OR	SOF_RAM, R5		; intra-segment offset address to 
					; SOF_RAM = R1
@ELSE
	BFLDH	SOF_RAM, #0C0H, #040H	; DPP1:POF_RAM ->SOF_RAM=R1
	MOV	DPP1, [R4]		; load data page pointer register DPP1
					; with data page of ram data block
	ADD	R4, #2			; inc offset address to ram data section
					; C166_INIT and also insure a delay for
					; pipeline effect.(DPP1 set)
@ENDI
					;
	MOV	POF_ROM, [R4+]		; move intra-page offset address rom
					; data block to POF_ROM=R2
@IF( @EQS( @MODEL, "TINY" ) )
	MOV	R5, [R4+]		; move data page of rom data block to R5
	SHL	R5, #14			; position page number
	OR	SOF_ROM, R5		; intra-segment offset address to 
					; SOF_ROM=R2
@ELSE
	BFLDH	SOF_ROM, #0C0H, #080H	; DPP2:POF_ROM ->SOF_ROM=R2
	MOV	DPP2, [R4]		; load data page pointer register DPP2
					; with data page of rom data block
	ADD	R4, #2			; inc offset address to rom data section
					; C166_INIT and also insure a delay for
					; pipeline effect.(DPP2 set)
@ENDI
					;
	MOV	R5, [R4+]		; number of bits to initialize.
					; start init bit block
NBBI:					; next bit block init
	CMP	BP_RAM, #0		; if ( bitpointer != 0 )
	JMP	cc_NZ, BPNZ		;   then bit pointer not at 0 location
	CMP	R5, #16			; if ( initbits < 16 )
	JMP	cc_ULT, LT16		;   then init bitblock < 16 bits
					;   else init bitblock = 16 bits
	MOV	R9, #16			; bitblocksize = 16
	SUB	R5, R9			; initbits -= bitblocksize
	JMP	cc_UC, STBINIT		; start bit initialization
LT16:					; bit block to init < 16 bits
	MOV	R9, R5			; bitblocksize = initbits
					; initbits = 0
	MOV	R5, #0			; bits left to initialize is zero
	JMP	cc_UC, STBINIT		; start bit initialization
BPNZ:					; bit pointer not zero
	MOV	R7, #16			; R7 = 16 
	SUB	R7, BP_RAM		; R7 = 16 - bitpointer
	CMP	R5, R7			; if (initbits < (16 - bitpointer))
	JMP	cc_ULT, LT16		;   then bitblocksize = initbits
	MOV	R9, R7			; bitblocksize = 16 - bitpointer
	SUB	R5, R9			; initbits -= bitblocksize
STBINIT:				; start bit initialization
	MOV	R8, #0FFFFH		; mask = 0XFFFF
	MOV	R6, #00000H		; bitbuffer = 0X0000
	MOV	R10, R9			; i = bitblocksize 	
NBI:					; next bit init
	SHR	R8, #1			; mask >> 1;
	SHR	R6, #1			; bitbuffer >> 1; 
	MOVB	RL7, [SOF_ROM+]		; move initialization data to RL7
					; and initdata++;
	JMP	CC_Z, CLRB		; if ( initialization data == 0 )
					;   then clear bitbuffer.15
	BSET	R6.15			;   else set bitbuffer.15
CLRB:					; R6.15 already zero
	CMPD1	R10, #1			; if ( i != 1 )
	JMP	cc_NE, NBI		;   then i--; next bit init;
					;   else  save bit data block	
	MOV	R7, #16			; R7 = 16
	SUB	R7, R9			; R7 = 16 - bitblocksize
	ADD	R7, BP_RAM		; R7 = 16 - bitblocksize + bitpointer
	SHR	R6, R7			; bitbuffer >> ((16 - bitblocksize ) +
					;                bitpointer)
LOOPMASK:				; mask >> ((16 - bitblocksize ) + 
					; 	    bitpointer)
	CMPD1	R7, #0			;
	JMP	cc_Z, ENDMASK		;
	SHR	R8, #1			; 
	BSET	R8.15			;
	JMP	cc_UC, LOOPMASK		;
ENDMASK:				;
	AND	R8, [SOF_RAM]		; mask &= *bitdata;
	OR	R6, R8			; bitbuffer |= mask;
	MOV	[SOF_RAM], R6		; *bitdata == bitbuffer;
	ADD	SOF_RAM, #2		; bitdata += 2;
	MOV	BP_RAM, #0		; bitpointer = 0;
	CMP	R5, #0			; if( initbits != 0) 
	JMP	cc_NZ, NBBI		;   then continue bit initialization
					;   else end of bit initialization
@IF( @EQS( @MODEL, "SMALL" ) )
	MOV 	DPP1, #PAG ?BASE_DPP1	; restore data page register DPP1 and
	MOV 	DPP2, #PAG ?BASE_DPP2	; DPP2 to their default values.
@ENDI
	JMP	CC_UC, INIT		; next initialization
					;
@ELSE					; NO BIT INITIALIZATION
					;
INIT_01:
	ADD	R4,#0CH			; skip DBPTR, DPTR and DW
	JMP	CC_UC, INIT		; continue with next initialization
@ENDI
INIT_END:				;


					; C166_BSS
@IF( @EQS(@MODEL,"MEDIUM") | @EQS(@MODEL,"LARGE") | @EQS(@MODEL,"SMALL") )
	MOV	R4, #POF ?C166_BSS_HEAD	; move intra-page offset address rom
					; data section C166_BSS to R4
BSS_DPP0:				;
	MOV	DPP0,#PAG ?C166_BSS_HEAD	; load data page pointer register DPP0
					; with data page of rom data C166_BSS
	NOP				; delay for pipeline effect
@ENDI
@IF( @EQS( @MODEL, "TINY" ) )
	MOV	R4, #?C166_BSS_HEAD	; move intra-segment offset address rom
					; data section C166_BSS to R4
@ENDI
BSS:					;
	MOV	R5, [R4+]		; BSS block header code -> R5
@IF( @EQS(@MODEL,"TINY") | @EQS(@MODEL,"SMALL") )
	CMP	R5, #05H		; check if header code 5 (near)
    @IF( @EQS(@MODEL,"SMALL") )
	JMP	CC_EQ, BSS_05		;
    @ELSE
	JMP	CC_NE, BSS_END		; if(no header code) end initialization
    @ENDI
@ENDI
@IF( @EQS(@MODEL,"MEDIUM") | @EQS(@MODEL,"LARGE") | @EQS(@MODEL,"SMALL") )
	CMP	R5, #06H		; check if header code 6 (far)
	JMP	CC_EQ, BSS_06		;
	CMP	R5, #07H		; check if header code 7 (huge)
	JMP	CC_NE, BSS_END		; if(no header code) end initialization

BSS_07:					; clear huge ram data (data > 64 K)
	MOV	SOF_RAM, [R4+]		; move intra-segment offset address ram
					; data block to SOF_RAM=R1
	MOV	R3, [R4+]		; move segment address ram data block
					; to R3
					; process data page number ram data 
	MOV	RH3, SOF_RAM_H		; R3.15:14=lower order bits of data page
	ROL	R3, #2			; R3.3:2:1:0 = data page number
	AND	R3, #0FH		; clr bit R3.15 - R3.4
	MOV	DPP1, R3		; load data page pointer register DPP1
					; with data page of ram data block
	BFLDH	SOF_RAM, #0C0H, #040H	; DPP1:POF_RAM ->SOF_RAM=R1
					;
	MOV	R5, [R4+]		; number of bytes (R6:R5) to clear in
	MOV	R6, [R4+]		; specified ram data block. 
					; MSW=R6, LSW=R5 (long word)
					;
CB07_2:	CMPD1	R5, #0			; test if all bytes are cleared and
	JMP	CC_NE, CB07_1 		; decrement number of bytes to clear.
	CMPD1	R6, #0			;
@IF( @EQS( @MODEL, "SMALL" ) )
	JMP	CC_EQ, CB07_3		;
@ELSE
	JMP	CC_EQ, BSS		; if( block end ) next initialization
@ENDI
CB07_1:	MOVB	[SOF_RAM], ZEROS	; clear byte
	CMPI1	SOF_RAM, #07FFFH	; test end of data page and inc SOF_RAM
	JMP	CC_NE, CB07_2		; if(no page end) next byte clear
	MOV	SOF_RAM, #04000H	; preset offset address ram data
	ADD	DPP1, #1		; next page ram data; increment DPP1
	JMP	CC_UC, CB07_2		; jump for next byte clear
@IF( @EQS( @MODEL, "SMALL" ) )
CB07_3:	MOV 	DPP1, #PAG ?BASE_DPP1	; restore data page register DPP1.
	JMP	CC_UC, BSS		; next initialization
@ENDI

BSS_06:					; clear far ram data. (CPU mode is
					; segmented with DPP usage linear or
					; paged.)
	MOV	POF_RAM, [R4+]		; move intra-page offset address ram
					; data block to POF_RAM=R1
	BFLDH	SOF_RAM, #0C0H, #040H	; DPP1:POF_RAM ->SOF_RAM=R1
	MOV	DPP1, [R4]		; load data page pointer register DPP1
					; with data page of ram data block
	ADD	R4, #2			; inc offset address to ram data section
					; C166_BSS and also insure a delay for 
					; pipeline effect. (DPP1 set)
					;
	MOV	R5, [R4+]		; number of bytes to clear in specified
					; ram data block
					;
CB06_1:	CMPD1	R5, #0			; test on data block end
@IF( @EQS( @MODEL, "SMALL" ) )
	JMP	CC_EQ, CB06_2 		;
@ELSE
	JMP	CC_EQ, BSS		; if( block end ) next initialization
@ENDI
	MOVB	[SOF_RAM], ZEROS	; clear byte
	ADD	SOF_RAM, #1		; inc SOF_RAM
	JMP	CC_UC, CB06_1		; jump for next byte clear
@IF( @EQS( @MODEL, "SMALL" ) )
CB06_2:	MOV 	DPP1, #PAG ?BASE_DPP1	; restore data page register DPP1
	JMP	CC_UC, BSS		; next initialization
@ENDI
@ENDI

@IF( @EQS(@MODEL,"TINY") | @EQS(@MODEL,"SMALL") )
BSS_05:					; clear near ram data. (DPP usage
					; is linear, CPU mode is segmented
					; for SMALL memory model and not
					; segmented for TINY memory model.)
	MOV	SOF_RAM, [R4+]		; move intra-segment offset address ram
					; data block to SOF_RAM=R1
					;
	MOV	R5, [R4+]		; number of bytes to clear in specified
					; ram data block
@IF( @EQS( @MODEL, "SMALL" ) )
	MOV	DPP0, #PAG ?BASE_DPP0	; restore DPP0 to its default value
@ENDI
CB05_1:	CMPD1	R5, #0			; test on data block end, and delay for
					; pipeline effect if DPP0 is restored
					; for SMALL memory model
@IF( @EQS( @MODEL, "TINY" ) )
	JMP	CC_EQ, BSS 		; if( block end ) next initialization
@ELSE
	JMP	CC_EQ, BSS_DPP0		; if( block end ) reload data page
					; pointer register DPP0 with data page
					; of rom data C166_BSS and start next
					; initialization
@ENDI
	MOVB	[SOF_RAM], ZEROS	; clear byte
	ADD	SOF_RAM, #1		; inc SOF_RAM
	JMP	CC_UC, CB05_1		; jump for next byte clear
@ENDI
BSS_END:

@IF( @EQS(@MODEL,"SMALL") )
	MOV	DPP0, #PAG ?BASE_DPP0	; restore DPP0 to its default value
@ENDI

@IF( @EQS(@MODEL,"MEDIUM") | @EQS(@MODEL,"LARGE") )
    	MOV 	DPP0, #0		 ; restore DPP0 to its default value
	MOV	DPP1, #PAG ?USRSTACK_TOP ; set DPP1 to page of user stack
	MOV	DPP2, #PAG C166_DGROUP	 ; set DPP2 to page of default data 
					 ; group
	NOP				 ; delay for pipeline effect
@ENDI

@IF( @EQS(@MODEL,"MEDIUM") | @EQS(@MODEL,"LARGE") )
	MOV	R0, #POF ?USRSTACK_TOP	; set user stack pointer
	BSET	R0.0EH			; User stack uses DPP1
@ELSE
	MOV	R0, #?USRSTACK_TOP	; set user stack pointer
@ENDI

@IF( @EVA )
	BSET	IEN			; allow monitor to break application
@ENDI

	MOV	R12, #0			; set argc to 0
	MOV	R13, #0			;
	MOV	R14, #0			; set argv[] to 0
@IF( @PXROS )
@IF( @EQS( @MODEL, "SMALL" ) | @EQS( @MODEL, "LARGE" ) )
	MOV	R1, #SOF __MAIN_RET	; store inter-segment jump to label
	MOV	[-R0], R1		; __MAIN_RET on the user stack
	MOV	R1, #SEG __MAIN_RET	;
	MOV	[-R0], R1		;
	JMPS	SEG _main, SOF _main	; call reset task main()
__MAIN_RET:				;
	ADD	R0, #4			;
@ELSE
	MOV	R1, #SOF __MAIN_RET	; store intra-segment address return
	MOV	[-R0], R1		; label __MAIN_RET on the user stack
	JMPA	CC_UC, _main		; call reset task main()
__MAIN_RET:				;
@ENDI
@ELSE
	CALL	_main			; call reset task main()
@ENDI

@IF( @EX_AB )
	MOV	R12, #0			; set exit status 0
	JMP	_exit			; jump to exit(0) function
@ENDI
; The exit() function causes normal program termination to occur. First, all 
; functions registered by the atexit() function are called in the reverse 
; order. Next, all open streams with unwritten buffered data are flushed, all 
; open streams are closed and all files created by the tmpfile() function are 
; removed. The status value passed to exit is returned in R4.
__EXIT: LABEL FAR			; the exit() or abort() function jumps
					; to this entry.
@IF( @EX_AB )
					; restore (host) environment.
	MOV	SP, #?SYSSTACK_TOP	; restore stack pointer.
@IF( @EQS(@MODEL,"MEDIUM") | @EQS(@MODEL,"LARGE") )
	MOV	R0, #POF ?USRSTACK_TOP	; restore user stack pointer
	BSET	R0.0EH			; User stack uses DPP1
@ELSE
	MOV	R0, #?USRSTACK_TOP	; restore user stack pointer
@ENDI
@IF( @FLOAT )
	MOV	R1, #?FPSTKUN		; restore floating point stack pointer.
	MOV	?FPSP, R1		; ?FPSP normally initialized via 
					; C166_INIT.
@ENDI	
@ENDI

__IDLE: IDLE				; Power down CPU until peripheral inter-
					; rupt or external interrupt occurs.
	JMPR	CC_UC, __IDLE		; set idle mode again.
	RETV				; Virtual return.
__CSTART	ENDP
__CSTART_PR	ENDS

@IF( @EQS(@MODEL,"TINY") | @EQS(@MODEL,"SMALL") )
C166_US	SECTION	LDAT WORD GLBUSRSTACK 'CUSTACK'
@ENDI
@IF( @EQS(@MODEL,"MEDIUM") | @EQS(@MODEL,"LARGE") )
C166_US	SECTION	DATA WORD GLBUSRSTACK 'CUSTACK'
@ENDI
@IF( @PXROS & ( @EQS(@MODEL,"SMALL") | @EQS(@MODEL,"LARGE") ) )
@IF( @EQS( @MODEL, "SMALL" ) | @EQS( @MODEL, "LARGE" ) )
	DS	2+4		; Allocate a user stack of at least 2 bytes +
				; return label main (__MAIN_RET).
@ELSE
	DS	2+2		; Allocate a user stack of at least 2 bytes +
				; return label main (__MAIN_RET).
@ENDI
@ELSE
	DS	2		; Allocate a user stack of at least 2 bytes
@ENDI
C166_US	ENDS

@IF( @EQS(@MODEL,"MEDIUM") | @EQS(@MODEL,"LARGE") )
C166_DGROUP	DGROUP	__DUMMY
__DUMMY	SECTION DATA WORD PUBLIC 'CNEAR'
__DUMMY	ENDS
@ENDI

;     	REGDEF R0-R15  COMMON=REGS      ; register usage      ####2####
;        EXTERN osek_sys_rb:WORD         ;                     ####2####
osek_sys_rb REGDEF R0-R15
	SSKDEF	__STKSZ			; System stack size
	
	END
