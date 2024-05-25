/**************************************************************************
**                                                                        *
**  FILE        :  cstart_tc2.c                                           *
**                                                                        *
**  DESCRIPTION :                                                         *
**      The system startup code initializes the processor's registers     *
**      and the application C variables for core 2.                       *
**                                                                        *
**  Copyright 1996-2018 TASKING BV                                        *
**                                                                        *
**************************************************************************/

#include "cstart_tc2.h"         /* include configuration */

#include <stdlib.h>
#include <stdbool.h>

#ifdef __CPU__
#include __SFRFILE__(__CPU__)
#endif

#if ( 2>0 ) && ( defined _REGTC21X_H || defined _REGTC22X_H || defined _REGTC23X_ADAS_H || defined _REGTC23X_H )
#pragma message "This derivative only supports core 0"
#else
#if 2>1 && ( defined _REGTC26X_H || defined _REGTC26XB_H )
#pragma message "This derivative only supports core 0 and 1."
#else
#if ( 2>2 ) && !( defined _REGTC38X_H || defined _REGTC39X_H || defined _REGTC39XB_H || defined _REGUSERDEF162_H )
#pragma message "This derivative only supports core 0, 1 and 2"
#else
#if ( 2>3 ) && !( defined _REGTC39X_H || defined _REGTC39XB_H || defined _REGUSERDEF162_H )
#pragma message "This derivative only supports core 0, 1, 2 and 3"
#else

#pragma weak    exit
#pragma extern  _Exit
#pragma tradeoff 4                              /* preset tradeoff level (for size) */
#pragma runtime BCM                             /* disable runtime error checking for cstart */
#pragma nomisrac                                /* disable MISRA-C checking */
#pragma immediate_in_code                       /* no external ROM access before bus configuration */

#if __USE_ARGC_ARGV_TC2
#pragma noclear                                 /* bss clearing not before cinit */
static char argcv_tc2[__ARGCV_BUFSIZE_TC2] __align(4);
#pragma clear
extern int _argcv( const char *, size_t );
#endif

/* linker definitions */
extern __far void _lc_ue_ustack_tc2[];  /* user stack end */
extern __far void _lc_ue_istack_tc2[];  /* interrupt stack end */
extern __far void _lc_u_int_tab_tc2[];  /* interrupt table */
extern __far void _lc_u_trap_tab_tc2[]; /* trap table */
extern __far void _SMALL_DATA_TC2[];       /* centre of A0 addressable area */
extern __far void _LITERAL_DATA_TC2[];     /* centre of A1 addressable area */
extern __far void _A8_DATA_TC2[];          /* centre of A8 addressable area */
extern __far void _A9_DATA_TC2[];          /* centre of A9 addressable area */

/* external functions */
#if __C_TC2_INIT
extern void _c_init_tc2(void);          /* C initialization function */
#endif
#ifdef __CALL_TC2_INIT
extern void _call_init_tc2(void);               /* call a user function before main() */
#endif
#ifdef _CALL_ENDINIT_TC2
extern void _endinit_tc2(void);         /* call a user function with protection switched off */
#endif

/* main references with default core association share */
#pragma extern main
extern int main( int argc, char *argv[] );

/* local functions */
static void __noinline__ __noreturn__ __jump__ __init_sp( void );
static void __noinline__ __noreturn__ __jump__ _start( void );

/* endinit types */
typedef enum
{
        _ENDINIT_DISABLE,
        _ENDINIT_ENABLE
}       _endinit_t;

/*
 *      Inlining is required for endinit_set and safety_endinit_set,
 *      because the CSA list is not ready to support function calls.
 */
static void inline endinit_set(_endinit_t endinit_value);
        
/* external interface to endinit_set */
extern void _endinit_clear_tc2(void) { endinit_set(_ENDINIT_DISABLE); }
extern void _endinit_set_tc2  (void) { endinit_set(_ENDINIT_ENABLE); }

#ifdef __RM_TC2_INIT
#if __RM_TC2_INIT
#include <fenv.h>
#endif
#endif

#if __C_TC2_INIT || _CALL_ENDINIT_TC2 || (defined __CALL_TC2_INIT)
/* c init semaphores */
extern unsigned int volatile __far      _tcx_end_c_init;        /* _tcx_end_c_init := 1 << core_id */
#pragma   weak  _tcx_end_c_init
#endif

void __noreturn__ __jump__ _start_tc2( void )
{
        __init_sp();
}

static void __noinline__ __noreturn__ __jump__ __init_sp( void )
{
        /* The initialization of the stackpointer is done in a seperate function, 
           because it must be executed in a function which has no stack use.
           
           When a function uses a stack it will be updated at the start of the 
           function. In this function, however, the stackpointer has an irrelevant
           value at the start of the function. A starting value for the stackpointer
           is determined and written in this function. The update to the 
           stackpointer at the start of the function would therefore be undone.
         */
         
        /* 
         * Load user stack pointer.
         */
# define STACK_ALIGN    0xfffffff8
#if  __USP_TC2_INIT
        void * sp = (void *)((unsigned int)(_lc_ue_ustack_tc2) & STACK_ALIGN);
        
        __set_sp( sp );
#endif

        _start();
}

/* Set the PSW to its reset value in case of a warm start */
static void inline reset_psw( void )
{
        unsigned int    value = 0x980;  /* Reset value */

        value |= (__CDC_TC2 & 0x7f);    /* PSW.CDC call depth counter */

#if __USER_STACK_TC2
        value &= ~0x200;                /* clear PSW.IS */
#else
        value |= 0x200;                 /* set PSW.IS */
#endif
        __mtcr(PSW, value);
}

static void __noinline__ __noreturn__ __jump__ _start( void )
{
        /* Do a dsync before changing any of the csfr values, thus any previous
         * background state gets flushed first. Required for applications that jump
         * to the reset address.
         */
        __dsync();
        
        /* Set the PSW to its reset value in case of a warm start */
        reset_psw();

        /* Set the PCXS and PCXO to its reset value in case of a warm start */
        unsigned int pcxi = __mfcr(PCXI);
        pcxi &= 0xfff00000;
        __mtcr(PCXI, pcxi);

        /*
         * Initialize Compatibility Control Register
         *
         * bit 3 (COMPAT.RM)
         *      Rounding Mode Compatibility
         *      0B PSW.RM not restored by RET.
         *      1B PSW.RM restored by RET. TriCore 1.3 backwards compatibility.
         *
         * bit 4 (COMPAT.SP)
         *      SYSCON Safety Protection Mode Compatibility
         *      0B SYSCON[31:1] safety endinit protected.
         *      1B SYSCON[31:1] not safety endinit protected (TC1.3 behavior).
         */
#ifdef __COMPAT_TC2
#if __COMPAT_TC2 != 0xf
        __mtcr(COMPAT, (~0x18|__COMPAT_TC2));
#endif
#endif
        
        /*
         * Clear the ENDINIT bit in the SCU_WDTCPU2CON0 register in order
         * to disable the write-protection for registers protected via the EndInit feature.
         */
        endinit_set(_ENDINIT_DISABLE);
        
        /*
         * Load Base Address of Trap Vector Table.
         */
#if __BTV_TC2_INIT
        __mtcr(BTV,  (unsigned int)_lc_u_trap_tab_tc2);
#endif

        /*
         * Load Base Address of Interrupt Vector Table.
         */
#if __BIV_TC2_INIT
#if __BIV_SINGLE_TC2_INIT && (defined _REGUSERDEF16X_H || defined _REGUSERDEF162_H || defined _REGTC27X_H || defined _REGTC27XB_H || defined _REGTC27XC_H || defined _REGTC27XD_H || defined _REGTC26X_H  || defined _REGTC26XB_H || defined _REGTC29X_H)
        /*
         * Single Entry Vector Table, for core tc1.6.x or tc1.6.2, is supported
         * by _sevt_isr_tc2() calling interrupt handlers installed
         * with _sevt_isr_install() stored in _sevt_isrs_tc2 list.
         * The _sevt_isr_tc2() is located at interrupt vector table
         * entry 64. The start address of the interrupt vector table
         * is defined by linker definition INTTAB2.
         */
#pragma extern _sevt_isr_tc2
        __mtcr(BIV, (unsigned int)(_lc_u_int_tab_tc2) | (0xff<<3) | 1 );
#else
#if __BIV_8BYTE_TC2_INIT && (defined _REGUSERDEF16X_H || defined _REGUSERDEF162_H || defined _REGTC27X_H || defined _REGTC27XB_H || defined _REGTC27XC_H || defined _REGTC27XD_H || defined _REGTC26X_H || defined _REGTC26XB_H || defined _REGTC29X_H)
        __mtcr(BIV, (unsigned int)(_lc_u_int_tab_tc2) | 1 );    /* 8 Byte vector spacing */
#else
        __mtcr(BIV, (unsigned int)(_lc_u_int_tab_tc2));         /* 32 Byte vector spacing */
#endif
#endif
#endif
        
        /*
         * Load interrupt stack pointer.
         */
#if __ISP_TC2_INIT
        unsigned int isp = (unsigned int)(_lc_ue_istack_tc2) & STACK_ALIGN;
        __mtcr(ISP, isp);
#endif

        /*
         * PCON0 configuration.
         */
#if     defined PCON0 && defined __PCON0_VALUE
        if(__PCON0_INIT) __mtcr(PCON0, __PCON0_VALUE);
#endif

        /*
         * DCON0 configuration.
         */
#if     defined DCON0 && defined __DCON0_VALUE
        if(__DCON0_INIT) __mtcr(DCON0, __DCON0_VALUE);
#endif

        /*
         * Set the rounding mode (PSW.RM)
         */
#ifdef __RM_TC2_INIT
#if __RM_TC2_INIT
        __fesetround( __RM_TC2_VALUE );
#endif
#endif

        /*
         * Set the ENDINIT bit in the SCU_WDTCPU2CON0 register again
         * to enable the write-protection and to prevent a time-out. 
         */
        endinit_set(_ENDINIT_ENABLE);

        /*
         * Initialize global address registers a0/a1 to support
         * __a0/__a1 storage qualifiers of the C compiler.
         */
#if __A0A1_TC2_INIT
        void * a0 = _SMALL_DATA_TC2;
        __asm( "mov.aa\ta0,%0"::"a"(a0) );

        void * a1 = _LITERAL_DATA_TC2;
        __asm( "mov.aa\ta1,%0"::"a"(a1) );
#endif

        /*
         * Initialize global address registers a8/a9 to support
         * __a8/__a9 storage qualifiers of the C compiler. A8 and A9
         * are reserved for OS use, or for application use in cases 
         * where the application ans OS are tightly coupled.
         */
#if __A8A9_TC2_INIT
        void * a8 = _A8_DATA_TC2;
        __asm( "mov.aa\ta8,%0"::"a"(a8) );

        void * a9 = _A9_DATA_TC2;
        __asm( "mov.aa\ta9,%0"::"a"(a9) );
#endif
        
        /* Setup the context save area linked list. */
#if __CSA_TC2_INIT
        
#  define MAX_NR_OF_CSA_AREAS     1
        extern int _lc_ub_csa_tc2[][16];    /* context save area 1 begin */
        extern int _lc_ue_csa_tc2[][16];    /* context save area 1 end   */
        static __far int (* const csa_area_begin[])[16] = { _lc_ub_csa_tc2}; 
        static __far int (* const csa_area_end[])[16]   = { _lc_ue_csa_tc2};

        int  i, k;
        int  no_of_csas;
        int * csa;
        unsigned int  seg_nr, seg_idx, pcxi_val=0;
        _Bool first=1;
        
        for (i=0; i < MAX_NR_OF_CSA_AREAS; i++)
        {
                /* first calculate nr of CSAs in this area */
                no_of_csas = csa_area_end[i] - csa_area_begin[i];
                
                for (k=0; k < no_of_csas; k++)
                {
                        csa = csa_area_begin[i][k];
                        /* Store null pointer in last CSA (= very first time!) */
                        *csa = pcxi_val;                        

                        seg_nr  = (((unsigned int)csa >> 28) & 0xf) << 16;
                        seg_idx = (((unsigned int)csa >> 6) & 0xffff);
                        pcxi_val = seg_nr | seg_idx;
                        if (first)
                        {
                                first = 0;                                
                                __mtcr(LCX, pcxi_val);
                        }                        
                }
                __mtcr(FCX, pcxi_val);
        }
#endif

        /*
         * Initialize and clear C variables.
         */
#if __C_TC2_INIT
        _c_init_tc2();
#endif  

        /*
         * Call a user function within one can initialize the 
         * registers protected via the EndInit feature.
         * Beware that protected registers are unlocked 
         * for the duration of the Time-out Period only!
         */
#ifdef _CALL_ENDINIT_TC2
        endinit_set(_ENDINIT_DISABLE);  /* disable the write-protection */
        _endinit_tc2();
        endinit_set(_ENDINIT_ENABLE);   /* enable the write-protection  */
#endif

        /*
         * Call a user function before starting main().
         */
#ifdef __CALL_TC2_INIT
        _call_init_tc2();
#endif

#if __C_TC2_INIT || _CALL_ENDINIT_TC2 || (defined __CALL_TC2_INIT)
        if ( &_tcx_end_c_init )
        {
                __swapmskw( (unsigned int *)&_tcx_end_c_init, 1<<2, 1<<2 );     /* tc2 end of initialization */
                /*
                 * Before calling main, which has code core association share,
                 * wait until all cores have done the global initializations
                 * to avoid race conditions on initialized shared global data.
                 */
                while ( ( _tcx_end_c_init & 0x3f ) != 0x3f ) ;          
        }
#endif
        
        /*
         * Call C main program.
         * exit, main and _argcv have code core association share
         */
#if __USE_ARGC_ARGV_TC2
        exit( main( _argcv( argcv_tc2, __ARGCV_BUFSIZE_TC2), (char **)argcv_tc2) );
#else
        exit( main( 0, NULL ) );                /* argc is 0 */
#endif

        /*
         * Default trap vectors are resolved from the C-library.
         */
#if __BTV_TC2_INIT
#  if __RESOLVE_TRAP_0_TC2
#    pragma extern  _trapmmu
#  endif
#  if __RESOLVE_TRAP_1_TC2
#    pragma extern  _trapprotection
#  endif
#  if __RESOLVE_TRAP_2_TC2
#    pragma extern  _trapinstruction
#  endif
#  if __RESOLVE_TRAP_3_TC2
#    pragma extern  _trapcontext
#  endif
#  if __RESOLVE_TRAP_4_TC2
#    pragma extern  _trapbus
#  endif
#  if __RESOLVE_TRAP_5_TC2
#    pragma extern  _trapassertion
#  endif
#  if __RESOLVE_TRAP_6_TC2
#    pragma extern  _trapsystem
#  endif
#  if __RESOLVE_TRAP_7_TC2
#    pragma extern  _trapnmi
#  endif
#endif

}

#pragma optimize R

/**************************************************************************
 *
 * FUNCTION:     endinit_set
 *
 * DESCRIPTION:  Sets or Clears the ENDINIT bit in the SCU_WDTCPU2CON0
 *               register in order to enabled or disable the write-protection for
 *               registers protected via the EndInit feature
 *               (ie. BTV, BIV, ISP, PCON0, DCON0).
 *
 *************************************************************************/
static void inline endinit_set( _endinit_t endinit_value )
{
        unsigned int wdt_con0;

        /*
         * 1st step: Password access (create password and send to SCU_WDTCPU2CON0)
         */        
        wdt_con0 = SCU_WDTCPU2CON0.U;

        wdt_con0 &= 0xffffff01;                 /* clear WDTLCK, WDTHPW0, WDTHPW1 */
        wdt_con0 |= 0xf1;                       /* set WDTHPW1 to 0xf and ENDINIT to 1
                                                 * (but the latter will not actually change this bit) */
        SCU_WDTCPU2CON0.U = wdt_con0;

        /*
         * 2nd step: Modify access, set the bit ENDINIT to 1 or 0 to allow access to
         *           registers: SCU_WDTCPU2CON1, BTV, BIV, ISP and mod_CLC
         *
         */
        wdt_con0 &= 0xfffffff0;                 /* clear WDTHPW0, WDTLCK, ENDINIT  */
        wdt_con0 |= 0x02 | endinit_value;       /* WDTHPW0=0, WDTLCK=1, ENDINIT=endinit_value */
        __isync();
        SCU_WDTCPU2CON0.U = wdt_con0;          
        SCU_WDTCPU2CON0.U;         /* read is required */
}

#endif
#endif
#endif
#endif
