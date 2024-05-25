/**************************************************************************
**                                                                        *
**  FILE        :  cstart_tc3.h                                           *
**                                                                        *
**  DESCRIPTION :                                                         *
**      Header file to control the system startup code's general settings *
**      and register initializations. The cstart__tc3.c file must be part *
**      of your project to make use of this cstart__tc3.h.                *
**                                                                        *
**      In the Eclipse environment this file can be modified using the    *
**      C startup code editor, which provides a GUI to modify the         *
**      Configuration settings and register initialization.               *
**                                                                        *
**  Copyright 1996-2018 TASKING BV                                        *
**                                                                        *
**************************************************************************/

#ifndef CSTART_TC3_H
#define CSTART_TC3_H

/*
 * These items are shown in Eclipse on the C Start Configuration page
 */

#ifndef __NO_CSTART_DEFAULT_CONFIG

/* C Startup settings */
#define __BIV_TC3_INIT          1       /* Initialize base address of interrupt vector table */
#define __BIV_SINGLE_TC3_INIT   0       /* Initialize single entry interrupt vector table */
#define __BIV_8BYTE_TC3_INIT    0       /* Initialize 8 byte spacing interrupt vector table */
#define __BTV_TC3_INIT          1       /* Initialize base address of trap vector table */
#define __CSA_TC3_INIT          1       /* Initialize CSA lists */
#define __C_TC3_INIT            1       /* Initialize and clear C variables */
#define __USP_TC3_INIT          1       /* Initialize user stack pointer */
#define __ISP_TC3_INIT          1       /* Initialize interrupt stack pointer */
#define __A0A1_TC3_INIT         1       /* Initialize a0 and a1 for _a0/_a1 addressing */
#define __A8A9_TC3_INIT         1       /* Initialize a8 and a9 for _a8/_a9 addressing (OS support) */
#define __RM_TC3_INIT           0       /* Initialize rounding mode */
#define __RM_TC3_VALUE          FE_TONEAREST  /* FE_TONEAREST, FE_UPWARD, FE_DOWNWARD or FE_TOWARDZERO */

#define __CDC_TC3                       0x0     /* Call Depth Counter (set PSW.CDC) */
#define __USER_STACK_TC3                1       /* Use the user stack (clear PSW.IS) */
#define __COMPAT_TC3            0xf     /* Compatibility mode */
#define __USE_ARGC_ARGV_TC3     0       /* Enable passing argc/argv to main() */
#define __ARGCV_BUFSIZE_TC3     256     /* Buffer size for argv */

/* Trap Vectors */
#define __RESOLVE_TRAP_0_TC3    1       /* Class 0: MMU */
#define __RESOLVE_TRAP_1_TC3    1       /* Class 1: Internal protection */
#define __RESOLVE_TRAP_2_TC3    1       /* Class 2: Instruction error */
#define __RESOLVE_TRAP_3_TC3    1       /* Class 3: Context management */
#define __RESOLVE_TRAP_4_TC3    1       /* Class 4: System bus and peripheral errors */
#define __RESOLVE_TRAP_5_TC3    1       /* Class 5: Assertion */
#define __RESOLVE_TRAP_6_TC3    1       /* Class 6: System call */
#define __RESOLVE_TRAP_7_TC3    1       /* Class 7: Non-maskable interrupt */

#endif /* __NO_CSTART_DEFAULT_CONFIG */


/*
 * Control of initialization registers
 *
 * The *_VALUE macros define the value of the register
 * The *_INIT macros must be defined to 0 or 1, specifying whether
 * or not it will be intialized by the cstart.c code.
 *
 * Most registers are not set to be initialized, which means that
 * the CPU's defaults are used. The bus configuration registers will be
 * set by running the 'Target Board Configuration' wizard.
 * The Eclipse environment will automatically apply the CPU default
 * values to the registers. These defaults are defined in the SFR files
 * from the include/sfr directory of the product.
 *
 */
#ifndef __NO_CSTART_REGISTER_CONFIG

#define __PCON0_INIT            1
#define __PCON0_VALUE           0x00000000
#define __DCON0_INIT            1
#define __DCON0_VALUE           0x00000000

#endif /*__NO_CSTART_REGISTER_CONFIG */

#endif /* CSTART_TC3_H */
