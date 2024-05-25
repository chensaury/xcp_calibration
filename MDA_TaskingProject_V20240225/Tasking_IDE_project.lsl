//****************************************************************************
//**                                                                         *
//**  FILE        :  tc39xb .lsl                                             *
//**                                                                         *
//**  DESCRIPTION :  LSL description: Infineon TC39XB                        *
//**                 This 2nd Generation AURIX derivative has:               *
//**                            6 TriCore cores                              *
//**                            10 MCS cores                                 *
//**                            1 XC800 cores                                *
//**                                                                         *
//**  Copyright 2011-2018 TASKING BV                                         *
//**                                                                         *
//****************************************************************************


#include "tc1v1_6_2.lsl"
#define GTM_BASE_ADDR           0xf0100000
#define GTM_MCS_COPYTABLE_SPACE vtc:linear
#define GTM_CPU_ENDIANNESS little

#ifdef    __REDEFINE_ON_CHIP_ITEMS
#define GTM_REDEFINE_ON_CHIP_ITEMS
#endif  // __REDEFINE_ON_CHIP_ITEMS

#ifndef GTM_MCS_RAM0_SIZE
# define GTM_MCS_RAM0_SIZE              0x2000
#endif

#include "gtm31_10.lsl"

#ifndef __VSTACK_XDATA
#define __VSTACK_XDATA 1k
#endif

#include "arch_scr2g.lsl"

#ifndef XC800INIT_FILL
#define XC800INIT_FILL          0
#endif

#define SCR_BASE_ADDR           0xf0240000

#ifndef    __REDEFINE_ON_CHIP_ITEMS

// Specify a multi-core processor environment (mpe)

processor mpe
{
        derivative = tc39xb;
}
#endif  // __REDEFINE_ON_CHIP_ITEMS

#ifndef CSA_TC0
#define CSA_TC0         64                      /* number of context blocks tc0 */
#endif

#ifndef CSA_TC1
#define CSA_TC1         64                      /* number of context blocks tc1 */
#endif

#ifndef CSA_TC2
#define CSA_TC2         64                      /* number of context blocks tc2 */
#endif

#ifndef CSA_TC3
#define CSA_TC3         64                      /* number of context blocks tc3 */
#endif

#ifndef CSA_TC4
#define CSA_TC4         64                      /* number of context blocks tc4 */
#endif

#ifndef CSA_TC5
#define CSA_TC5         64                      /* number of context blocks tc5 */
#endif


#ifndef CSA_START_TC0
#define CSA_START_TC0   0xd0004000              /* start address of CSA tc0 */
#endif

#ifndef CSA_START_TC1
#define CSA_START_TC1   0xd0004000              /* start address of CSA tc1 */
#endif

#ifndef CSA_START_TC2
#define CSA_START_TC2   0xd0004000              /* start address of CSA tc2 */
#endif

#ifndef CSA_START_TC3
#define CSA_START_TC3   0xd0004000              /* start address of CSA tc3 */
#endif

#ifndef CSA_START_TC4
#define CSA_START_TC4   0xd0004000              /* start address of CSA tc4 */
#endif

#ifndef CSA_START_TC5
#define CSA_START_TC5   0xd0004000              /* start address of CSA tc5 */
#endif


#ifndef USTACK_TC0
#define USTACK_TC0      0x26000                 /* user stack size tc0 */
#endif

#ifndef USTACK_TC1
#define USTACK_TC1      1k                      /* user stack size tc1 */
#endif

#ifndef USTACK_TC2
#define USTACK_TC2      1k                      /* user stack size tc2 */
#endif

#ifndef USTACK_TC3
#define USTACK_TC3      1k                      /* user stack size tc3 */
#endif

#ifndef USTACK_TC4
#define USTACK_TC4      1k                      /* user stack size tc4 */
#endif

#ifndef USTACK_TC5
#define USTACK_TC5      1k                      /* user stack size tc5 */
#endif


#ifndef ISTACK_TC0
#define ISTACK_TC0      1k                      /* interrupt stack size tc0 */
#endif

#ifndef ISTACK_TC1
#define ISTACK_TC1      1k                      /* interrupt stack size tc1 */
#endif

#ifndef ISTACK_TC2
#define ISTACK_TC2      1k                      /* interrupt stack size tc2 */
#endif

#ifndef ISTACK_TC3
#define ISTACK_TC3      1k                      /* interrupt stack size tc3 */
#endif

#ifndef ISTACK_TC4
#define ISTACK_TC4      1k                      /* interrupt stack size tc4 */
#endif

#ifndef ISTACK_TC5
#define ISTACK_TC5      1k                      /* interrupt stack size tc5 */
#endif


#ifndef XVWBUF
#define XVWBUF          0                       /* buffer used by debugger */
#endif

#ifndef INTTAB
#define INTTAB          0xa00f0000              /* start address of interrupt table */
#endif
#ifndef TRAPTAB
#define TRAPTAB         (INTTAB + 0xc000)      /* start address of trap table */
#endif

#ifndef INTTAB0
#define INTTAB0         (INTTAB)
#endif
#ifndef INTTAB1
#define INTTAB1         (INTTAB0 + 0x2000)
#endif
#ifndef INTTAB2
#define INTTAB2         (INTTAB1 + 0x2000)
#endif
#ifndef INTTAB3
#define INTTAB3         (INTTAB2 + 0x2000)
#endif
#ifndef INTTAB4
#define INTTAB4         (INTTAB3 + 0x2000)
#endif
#ifndef INTTAB5
#define INTTAB5         (INTTAB4 + 0x2000)
#endif

#ifndef TRAPTAB0
#define TRAPTAB0        (TRAPTAB)
#endif
#ifndef TRAPTAB1
#define TRAPTAB1        (TRAPTAB0 + 0x100)
#endif
#ifndef TRAPTAB2
#define TRAPTAB2        (TRAPTAB1 + 0x100)
#endif
#ifndef TRAPTAB3
#define TRAPTAB3        (TRAPTAB2 + 0x100)
#endif
#ifndef TRAPTAB4
#define TRAPTAB4        (TRAPTAB3 + 0x100)
#endif
#ifndef TRAPTAB5
#define TRAPTAB5        (TRAPTAB4 + 0x100)
#endif

#ifndef RESET
#define RESET           0xa0000000              /* internal flash start address tc0 */
#endif
/***********************************/
/* Because ECLIPSE is generating Ax_START instead of Ax_START_ADDRESS */
/***********************************/
#ifndef A0_START_ADDRESS
#ifdef  A0_START
#define A0_START_ADDRESS A0_START
#endif
#endif
#ifndef A1_START_ADDRESS
#ifdef  A1_START
#define A1_START_ADDRESS A1_START
#endif
#endif
#ifndef A8_START_ADDRESS
#ifdef  A8_START
#define A8_START_ADDRESS A8_START
#endif
#endif
#ifndef A9_START_ADDRESS
#ifdef  A9_START
#define A9_START_ADDRESS A9_START
#endif
#endif
/***********************************/


derivative tc39xb
extends gtm31_10
{
        core tc0
        {
                architecture = TC1V1.6.2;
                space_id_offset = 100;  // add 100 to all space IDs in the architecture definition
                copytable_space = vtc:linear;   // use the copy table in the virtual core for 'bss' and initialized data sections
        }

        core tc1
        {
                architecture = TC1V1.6.2;
                space_id_offset = 200;  // add 200 to all space IDs in the architecture definition
                copytable_space = vtc:linear;   // use the copy table in the virtual core for 'bss' and initialized data sections
        }

        core tc2
        {
                architecture = TC1V1.6.2;
                space_id_offset = 300;  // add 300 to all space IDs in the architecture definition
                copytable_space = vtc:linear;   // use the copy table in the virtual core for 'bss' and initialized data sections
        }

        core tc3
        {
                architecture = TC1V1.6.2;
                space_id_offset = 400;  // add 400 to all space IDs in the architecture definition
                copytable_space = vtc:linear;   // use the copy table in the virtual core for 'bss' and initialized data sections
        }

        core tc4
        {
                architecture = TC1V1.6.2;
                space_id_offset = 500;  // add 500 to all space IDs in the architecture definition
                copytable_space = vtc:linear;   // use the copy table in the virtual core for 'bss' and initialized data sections
        }

        core tc5
        {
                architecture = TC1V1.6.2;
                space_id_offset = 600;  // add 600 to all space IDs in the architecture definition
                copytable_space = vtc:linear;   // use the copy table in the virtual core for 'bss' and initialized data sections
        }


        core vtc
        {
                architecture = TC1V1.6.2;
                import tc0;                      // add all address spaces of core tc0 to core vtc for linking and locating
                import tc1;                      //                             tc1
                import tc2;                      //                             tc2
                import tc3;                      //                             tc3
                import tc4;                      //                             tc4
                import tc5;                      //                             tc5
        }

        core xc800
        {
                architecture = scr2g;
        }

        bus sri
        {
                mau = 8;
                width = 32;

                // map shared addresses one-to-one to real cores and virtual core, segments starting from 0x0
                map (dest=bus:tc0:fpi_bus, src_offset=0, dest_offset=0, size=0x10000000);
                map (dest=bus:tc0:fpi_bus, src_offset=0x20000000, dest_offset=0x20000000, size=0x10000000);
                map (dest=bus:tc1:fpi_bus, src_offset=0, dest_offset=0, size=0x10000000);
                map (dest=bus:tc1:fpi_bus, src_offset=0x20000000, dest_offset=0x20000000, size=0x10000000);
                map (dest=bus:tc2:fpi_bus, src_offset=0, dest_offset=0, size=0x10000000);
                map (dest=bus:tc2:fpi_bus, src_offset=0x20000000, dest_offset=0x20000000, size=0x10000000);
                map (dest=bus:tc3:fpi_bus, src_offset=0, dest_offset=0, size=0x10000000);
                map (dest=bus:tc3:fpi_bus, src_offset=0x20000000, dest_offset=0x20000000, size=0x10000000);
                map (dest=bus:tc4:fpi_bus, src_offset=0, dest_offset=0, size=0x10000000);
                map (dest=bus:tc4:fpi_bus, src_offset=0x20000000, dest_offset=0x20000000, size=0x10000000);
                map (dest=bus:tc5:fpi_bus, src_offset=0, dest_offset=0, size=0x10000000);
                map (dest=bus:tc5:fpi_bus, src_offset=0x20000000, dest_offset=0x20000000, size=0x10000000);
                map (dest=bus:vtc:fpi_bus, src_offset=0, dest_offset=0, size=0x10000000);
                map (dest=bus:vtc:fpi_bus, src_offset=0x20000000, dest_offset=0x20000000, size=0x10000000);

                // map shared addresses one-to-one to real cores and virtual core, segments starting from 0x8
                map (dest=bus:tc0:fpi_bus, src_offset=0x80000000, dest_offset=0x80000000, size=0x40000000);
                map (dest=bus:tc1:fpi_bus, src_offset=0x80000000, dest_offset=0x80000000, size=0x40000000);
                map (dest=bus:tc2:fpi_bus, src_offset=0x80000000, dest_offset=0x80000000, size=0x40000000);
                map (dest=bus:tc3:fpi_bus, src_offset=0x80000000, dest_offset=0x80000000, size=0x40000000);
                map (dest=bus:tc4:fpi_bus, src_offset=0x80000000, dest_offset=0x80000000, size=0x40000000);
                map (dest=bus:tc5:fpi_bus, src_offset=0x80000000, dest_offset=0x80000000, size=0x40000000);
                map (dest=bus:vtc:fpi_bus, src_offset=0x80000000, dest_offset=0x80000000, size=0x40000000);

                // map shared addresses one-to-one to real cores and virtual core, segments starting from 0xe
                map (dest=bus:tc0:fpi_bus, src_offset=0xe0000000, dest_offset=0xe0000000, size=0x20000000);
                map (dest=bus:tc1:fpi_bus, src_offset=0xe0000000, dest_offset=0xe0000000, size=0x20000000);
                map (dest=bus:tc2:fpi_bus, src_offset=0xe0000000, dest_offset=0xe0000000, size=0x20000000);
                map (dest=bus:tc3:fpi_bus, src_offset=0xe0000000, dest_offset=0xe0000000, size=0x20000000);
                map (dest=bus:tc4:fpi_bus, src_offset=0xe0000000, dest_offset=0xe0000000, size=0x20000000);
                map (dest=bus:tc5:fpi_bus, src_offset=0xe0000000, dest_offset=0xe0000000, size=0x20000000);
                map (dest=bus:vtc:fpi_bus, src_offset=0xe0000000, dest_offset=0xe0000000, size=0x20000000);
                
                // map local memory
                map (dest=bus:tc0:fpi_bus, src_offset=0x70000000, dest_offset=0x70000000, size=0x00100000, priority=2, exec_priority=0);
                map (dest=bus:tc1:fpi_bus, src_offset=0x60000000, dest_offset=0x60000000, size=0x00100000, priority=2, exec_priority=0);
                map (dest=bus:tc2:fpi_bus, src_offset=0x50000000, dest_offset=0x50000000, size=0x00100000, priority=2, exec_priority=0);
                map (dest=bus:tc3:fpi_bus, src_offset=0x40000000, dest_offset=0x40000000, size=0x00100000, priority=2, exec_priority=0);
                map (dest=bus:tc4:fpi_bus, src_offset=0x30000000, dest_offset=0x30000000, size=0x00100000, priority=2, exec_priority=0);
                map (dest=bus:tc5:fpi_bus, src_offset=0x10000000, dest_offset=0x10000000, size=0x00100000, priority=2, exec_priority=0);
                map (dest=bus:tc0:fpi_bus, src_offset=0x70100000, dest_offset=0x70100000, size=0xff00000, exec_priority=2);
                map (dest=bus:tc1:fpi_bus, src_offset=0x60100000, dest_offset=0x60100000, size=0xff00000, exec_priority=2);
                map (dest=bus:tc2:fpi_bus, src_offset=0x50100000, dest_offset=0x50100000, size=0xff00000, exec_priority=2);
                map (dest=bus:tc3:fpi_bus, src_offset=0x40100000, dest_offset=0x40100000, size=0xff00000, exec_priority=2);
                map (dest=bus:tc4:fpi_bus, src_offset=0x30100000, dest_offset=0x30100000, size=0xff00000, exec_priority=2);
                map (dest=bus:tc5:fpi_bus, src_offset=0x10100000, dest_offset=0x10100000, size=0xff00000, exec_priority=2);
                map (dest=bus:tc0:fpi_bus, src_offset=0x10000000, dest_offset=0x10000000, size=0x10000000);
                map (dest=bus:tc0:fpi_bus, src_offset=0x30000000, dest_offset=0x30000000, size=0x40000000);
                map (dest=bus:tc1:fpi_bus, src_offset=0x10000000, dest_offset=0x10000000, size=0x10000000);
                map (dest=bus:tc1:fpi_bus, src_offset=0x30000000, dest_offset=0x30000000, size=0x30000000);
                map (dest=bus:tc1:fpi_bus, src_offset=0x70000000, dest_offset=0x70000000, size=0x10000000);
                map (dest=bus:tc2:fpi_bus, src_offset=0x10000000, dest_offset=0x10000000, size=0x10000000);
                map (dest=bus:tc2:fpi_bus, src_offset=0x30000000, dest_offset=0x30000000, size=0x20000000);
                map (dest=bus:tc2:fpi_bus, src_offset=0x60000000, dest_offset=0x60000000, size=0x20000000);
                map (dest=bus:tc3:fpi_bus, src_offset=0x10000000, dest_offset=0x10000000, size=0x10000000);
                map (dest=bus:tc3:fpi_bus, src_offset=0x30000000, dest_offset=0x30000000, size=0x10000000);
                map (dest=bus:tc3:fpi_bus, src_offset=0x50000000, dest_offset=0x50000000, size=0x30000000);
                map (dest=bus:tc4:fpi_bus, src_offset=0x10000000, dest_offset=0x10000000, size=0x10000000);
                map (dest=bus:tc4:fpi_bus, src_offset=0x40000000, dest_offset=0x40000000, size=0x40000000);
                map (dest=bus:tc5:fpi_bus, src_offset=0x30000000, dest_offset=0x30000000, size=0x50000000);
                map (dest=bus:vtc:fpi_bus, src_offset=0x10000000, dest_offset=0x10000000, size=0x10000000);
                map (dest=bus:vtc:fpi_bus, src_offset=0x30000000, dest_offset=0x30000000, size=0x50000000);
                map (dest=bus:aei, src_offset=GTM_BASE_ADDR, dest_offset=0, size=0x100000000-GTM_BASE_ADDR);
                map (dest=bus:xc800:code_bus, src_offset=SCR_BASE_ADDR, dest_offset=0, size=8k);
        }

#ifndef    __REDEFINE_ON_CHIP_ITEMS
#ifndef __CPP_RUN_TIME_ENTRY_FLAG 
#define __CPP_RUN_TIME_ENTRY_FLAG mem:dspr0
#endif 

        section_layout :vtc:linear
        {
                group (ordered, run_addr=__CPP_RUN_TIME_ENTRY_FLAG)
                {
                        // C++ run-time variable "main_called" that ensures the global object constructors to execute exactly once.
                        // main_called is initialized so its name gets a data prefix: .sect '.data.__section_main_called' 
                        select ".data.__section_main_called"; 
                        // C++ run-time variables to make destructors concurrent
                        select ".data.__section_dtor_finalizer"; 
                }
        }
#endif  // __REDEFINE_ON_CHIP_ITEMS

#ifndef    __REDEFINE_ON_CHIP_ITEMS


        memory dspr0 // Data Scratch Pad Ram CPU0
        {
                mau = 8;
                size = 240k;
                type = ram;
                map (dest=bus:tc0:fpi_bus, dest_offset=0xd0000000, size=240k, priority=1, exec_priority=0);
                map (dest=bus:sri, dest_offset=0x70000000, size=240k);
        }

        memory pspr0 // Program Scratch Pad Ram CPU0
        {
                mau = 8;
                size = 64k;
                type = ram;
                map (dest=bus:tc0:fpi_bus, dest_offset=0xc0000000, size=64k, exec_priority=1);
                map (dest=bus:sri, dest_offset=0x70100000, size=64k);
        }

        memory dspr1 // Data Scratch Pad Ram CPU1
        {
                mau = 8;
                size = 240k;
                type = ram;
                map (dest=bus:tc1:fpi_bus, dest_offset=0xd0000000, size=240k, priority=1, exec_priority=0);
                map (dest=bus:sri, dest_offset=0x60000000, size=240k);
        }

        memory pspr1 // Program Scratch Pad Ram CPU1
        {
                mau = 8;
                size = 64k;
                type = ram;
                map (dest=bus:tc1:fpi_bus, dest_offset=0xc0000000, size=64k, exec_priority=1);
                map (dest=bus:sri, dest_offset=0x60100000, size=64k);
        }

        memory dspr2 // Data Scratch Pad Ram CPU2
        {
                mau = 8;
                size = 96k;
                type = ram;
                map (dest=bus:tc2:fpi_bus, dest_offset=0xd0000000, size=96k, priority=1, exec_priority=0);
                map (dest=bus:sri, dest_offset=0x50000000, size=96k);
        }

        memory pspr2 // Program Scratch Pad Ram CPU2
        {
                mau = 8;
                size = 64k;
                type = ram;
                map (dest=bus:tc2:fpi_bus, dest_offset=0xc0000000, size=64k, exec_priority=1);
                map (dest=bus:sri, dest_offset=0x50100000, size=64k);
        }

        memory dspr3 // Data Scratch Pad Ram CPU3
        {
                mau = 8;
                size = 96k;
                type = ram;
                map (dest=bus:tc3:fpi_bus, dest_offset=0xd0000000, size=96k, priority=1, exec_priority=0);
                map (dest=bus:sri, dest_offset=0x40000000, size=96k);
        }

        memory pspr3 // Program Scratch Pad Ram CPU3
        {
                mau = 8;
                size = 64k;
                type = ram;
                map (dest=bus:tc3:fpi_bus, dest_offset=0xc0000000, size=64k, exec_priority=1);
                map (dest=bus:sri, dest_offset=0x40100000, size=64k);
        }

        memory dspr4 // Data Scratch Pad Ram CPU4
        {
                mau = 8;
                size = 96k;
                type = ram;
                map (dest=bus:tc4:fpi_bus, dest_offset=0xd0000000, size=96k, priority=1, exec_priority=0);
                map (dest=bus:sri, dest_offset=0x30000000, size=96k);
        }

        memory pspr4 // Program Scratch Pad Ram CPU4
        {
                mau = 8;
                size = 64k;
                type = ram;
                map (dest=bus:tc4:fpi_bus, dest_offset=0xc0000000, size=64k, exec_priority=1);
                map (dest=bus:sri, dest_offset=0x30100000, size=64k);
        }

        memory dspr5 // Data Scratch Pad Ram CPU5
        {
                mau = 8;
                size = 96k;
                type = ram;
                map (dest=bus:tc5:fpi_bus, dest_offset=0xd0000000, size=96k, priority=1, exec_priority=0);
                map (dest=bus:sri, dest_offset=0x10000000, size=96k);
        }

        memory pspr5 // Program Scratch Pad Ram CPU5
        {
                mau = 8;
                size = 64k;
                type = ram;
                map (dest=bus:tc5:fpi_bus, dest_offset=0xc0000000, size=64k, exec_priority=1);
                map (dest=bus:sri, dest_offset=0x10100000, size=64k);
        }



        memory pflash0 // Program Flash CPU0
        {
                mau = 8;
                size = 3M;
                type = rom;
                map     cached (dest=bus:sri, dest_offset=0x80000000,           size=3M);
                map not_cached (dest=bus:sri, dest_offset=0xa0000000, reserved, size=3M);
        }
        memory pflash1 // Program Flash CPU1
        {
                mau = 8;
                size = 3M;
                type = rom;
                map     cached (dest=bus:sri, dest_offset=0x80300000,           size=3M);
                map not_cached (dest=bus:sri, dest_offset=0xa0300000, reserved, size=3M);
        }
        memory pflash2 // Program Flash CPU2
        {
                mau = 8;
                size = 3M;
                type = rom;
                map     cached (dest=bus:sri, dest_offset=0x80600000,           size=3M);
                map not_cached (dest=bus:sri, dest_offset=0xa0600000, reserved, size=3M);
        }
        memory pflash3 // Program Flash CPU3
        {
                mau = 8;
                size = 3M;
                type = rom;
                map     cached (dest=bus:sri, dest_offset=0x80900000,           size=3M);
                map not_cached (dest=bus:sri, dest_offset=0xa0900000, reserved, size=3M);
        }
        memory pflash4 // Program Flash CPU4
        {
                mau = 8;
                size = 3M;
                type = rom;
                map     cached (dest=bus:sri, dest_offset=0x80c00000,           size=3M);
                map not_cached (dest=bus:sri, dest_offset=0xa0c00000, reserved, size=3M);
        }
        memory pflash5 // Program Flash CPU5
        {
                mau = 8;
                size = 1M;
                type = rom;
                map     cached (dest=bus:sri, dest_offset=0x80f00000,           size=1M);
                map not_cached (dest=bus:sri, dest_offset=0xa0f00000, reserved, size=1M);
        }


        memory brom
        {
                mau = 8;
                size = 64k;
                type = reserved rom;
                map     cached (dest=bus:sri, dest_offset=0x8fff0000,           size=64k);
                map not_cached (dest=bus:sri, dest_offset=0xafff0000, reserved, size=64k);
        }


        memory dflash0
        {
                mau = 8;
                size = 1024k;
                type = reserved nvram;
                map (dest=bus:sri, dest_offset=0xaf000000, size=1024k);
        }

        memory dflash0_ucb
        {
                mau = 8;
                size = 24k;
                type = reserved nvram;
                map (dest=bus:sri, dest_offset=0xaf400000, size=24k);
        }

        memory dflash0_cfs
        {
                mau = 8;
                size = 64k;
                type = reserved nvram;
                map (dest=bus:sri, dest_offset=0xaf800000, size=64k);
        }

        memory dflash1
        {
                mau = 8;
                size = 128k;
                type = reserved nvram;
                map (dest=bus:sri, dest_offset=0xafc00000, size=128k);
        }


        memory dlmucpu0 // DLMU CPU0
        {
                mau = 8;
                size = 64k;
                type = ram;
                map     cached (dest=bus:sri, dest_offset=0x90000000,           size=64k);
                map not_cached (dest=bus:sri, dest_offset=0xb0000000, reserved, size=64k);
        }
        memory dlmucpu1 // DLMU CPU1
        {
                mau = 8;
                size = 64k;
                type = ram;
                map     cached (dest=bus:sri, dest_offset=0x90010000,           size=64k);
                map not_cached (dest=bus:sri, dest_offset=0xb0010000, reserved, size=64k);
        }
        memory dlmucpu2 // DLMU CPU2
        {
                mau = 8;
                size = 64k;
                type = ram;
                map     cached (dest=bus:sri, dest_offset=0x90020000,           size=64k);
                map not_cached (dest=bus:sri, dest_offset=0xb0020000, reserved, size=64k);
        }
        memory dlmucpu3 // DLMU CPU3
        {
                mau = 8;
                size = 64k;
                type = ram;
                map     cached (dest=bus:sri, dest_offset=0x90030000,           size=64k);
                map not_cached (dest=bus:sri, dest_offset=0xb0030000, reserved, size=64k);
        }
        memory dlmucpu4 // DLMU CPU4
        {
                mau = 8;
                size = 64k;
                type = ram;
                map     cached (dest=bus:sri, dest_offset=0x90100000,           size=64k);
                map not_cached (dest=bus:sri, dest_offset=0xb0100000, reserved, size=64k);
        }
        memory dlmucpu5 // DLMU CPU5
        {
                mau = 8;
                size = 64k;
                type = ram;
                map     cached (dest=bus:sri, dest_offset=0x90110000,           size=64k);
                map not_cached (dest=bus:sri, dest_offset=0xb0110000, reserved, size=64k);
        }


        memory lmuram0
        {
                mau = 8;
                size = 256k;
                type = ram;
                priority = 2;
//                map     cached (dest=bus:sri, dest_offset=0x90040000, reserved, size=256k);
                map not_cached (dest=bus:sri, dest_offset=0xb0040000, size=256k);
        }
        memory lmuram1
        {
                mau = 8;
                size = 256k;
                type = ram;
                priority = 2;
//                map     cached (dest=bus:sri, dest_offset=0x90080000, reserved, size=256k);
                map not_cached (dest=bus:sri, dest_offset=0xb0080000, size=256k);
        }
        memory lmuram2
        {
                mau = 8;
                size = 256k;
                type = ram;
                priority = 2;
//                map     cached (dest=bus:sri, dest_offset=0x900c0000, reserved, size=256k);
                map not_cached (dest=bus:sri, dest_offset=0xb00c0000, size=256k);
        }


        memory dam0ram0
        {
                mau = 8;
                size = 32k;
                type = reserved ram;
                map     cached (dest=bus:sri, dest_offset=0x90400000,           size=32k);
                map not_cached (dest=bus:sri, dest_offset=0xb0400000, reserved, size=32k);
        }
        memory dam0ram1
        {
                mau = 8;
                size = 32k;
                type = reserved ram;
                map     cached (dest=bus:sri, dest_offset=0x90408000,           size=32k);
                map not_cached (dest=bus:sri, dest_offset=0xb0408000, reserved, size=32k);
        }
        memory dam1ram0
        {
                mau = 8;
                size = 32k;
                type = reserved ram;
                map     cached (dest=bus:sri, dest_offset=0x90410000,           size=32k);
                map not_cached (dest=bus:sri, dest_offset=0xb0410000, reserved, size=32k);
        }
        memory dam1ram1
        {
                mau = 8;
                size = 32k;
                type = reserved ram;
                map     cached (dest=bus:sri, dest_offset=0x90418000,           size=32k);
                map not_cached (dest=bus:sri, dest_offset=0xb0418000, reserved, size=32k);
        }


        memory tram
        {
                mau = 8;
                size = 8k;
                type = reserved ram;
                map     cached (dest=bus:sri, dest_offset=0x98000000,           size=8k);
                map not_cached (dest=bus:sri, dest_offset=0xb8000000, reserved, size=8k);
        }


        memory emem0
        {
                mau = 8;
                size = 1M;
                type = reserved ram;
                map     cached (dest=bus:sri, dest_offset=0x99000000,           size=1M);
                map not_cached (dest=bus:sri, dest_offset=0xb9000000, reserved, size=1M);
        }
        memory emem1
        {
                mau = 8;
                size = 1M;
                type = reserved ram;
                map     cached (dest=bus:sri, dest_offset=0x99100000,           size=1M);
                map not_cached (dest=bus:sri, dest_offset=0xb9100000, reserved, size=1M);
        }
        memory emem2
        {
                mau = 8;
                size = 1M;
                type = reserved ram;
                map     cached (dest=bus:sri, dest_offset=0x99200000,           size=1M);
                map not_cached (dest=bus:sri, dest_offset=0xb9200000, reserved, size=1M);
        }
        memory emem3
        {
                mau = 8;
                size = 1M;
                type = reserved ram;
                map     cached (dest=bus:sri, dest_offset=0x99300000,           size=1M);
                map not_cached (dest=bus:sri, dest_offset=0xb9300000, reserved, size=1M);
        }


        memory xtm
        {
                mau = 8;
                size = 512k;
                type = reserved ram;
                map (dest=bus:sri, dest_offset=0xb9400000, size=512k);
        }


        memory scr_iram
        {
            mau = 8;
            type = ram;
            size = 256;
            map ( dest=bus:xc800:idata_bus, src_offset=0x0, dest_offset=0x0, size=256 );
        }
        memory scr_xram
        {
            mau = 8;
            type = nvram;
            size = 8k;
            map ( dest=bus:xc800:xdata_bus, src_offset=0x0, dest_offset=0x0, size=8k );
            map ( dest=bus:xc800:code_bus, src_offset=0x0, dest_offset=0x0, size=8k );
        }
        memory scr_bootrom
        {
            mau = 8;
            type = reserved rom;
            size = 2k;
            map ( dest=bus:xc800:code_bus, src_offset=0x0, dest_offset=0xd000, size=2k );
        }

#endif  // __REDEFINE_ON_CHIP_ITEMS

        section_setup :vtc:linear
        {
#ifndef __LINKONLY__
                start_address
                (
                        run_addr = (RESET),
                        symbol = "_START"
                );
#endif
        }

        section_setup :tc0:linear
        {
                stack "ustack_tc0"
                (
                        min_size = (USTACK_TC0),
                        fixed,
                        align = 8,
                        id = 0
                );

                stack "istack_tc0"
                (
                        min_size = (ISTACK_TC0),
                        fixed,
                        align = 8,
                        id = 1
                );
        }

        section_setup :tc1:linear
        {
                stack "ustack_tc1"
                (
                        min_size = (USTACK_TC1),
                        fixed,
                        align = 8,
                        id = 2
                );

                stack "istack_tc1"
                (
                        min_size = (ISTACK_TC1),
                        fixed,
                        align = 8,
                        id = 3
                );
        }

        section_setup :tc2:linear
        {
                stack "ustack_tc2"
                (
                        min_size = (USTACK_TC2),
                        fixed,
                        align = 8,
                        id = 4
                );

                stack "istack_tc2"
                (
                        min_size = (ISTACK_TC2),
                        fixed,
                        align = 8,
                        id = 5
                );
        }

        section_setup :tc3:linear
        {
                stack "ustack_tc3"
                (
                        min_size = (USTACK_TC3),
                        fixed,
                        align = 8,
                        id = 6
                );

                stack "istack_tc3"
                (
                        min_size = (ISTACK_TC3),
                        fixed,
                        align = 8,
                        id = 7
                );
        }

        section_setup :tc4:linear
        {
                stack "ustack_tc4"
                (
                        min_size = (USTACK_TC4),
                        fixed,
                        align = 8,
                        id = 8
                );

                stack "istack_tc4"
                (
                        min_size = (ISTACK_TC4),
                        fixed,
                        align = 8,
                        id = 9
                );
        }

        section_setup :tc5:linear
        {
                stack "ustack_tc5"
                (
                        min_size = (USTACK_TC5),
                        fixed,
                        align = 8,
                        id = 10
                );

                stack "istack_tc5"
                (
                        min_size = (ISTACK_TC5),
                        fixed,
                        align = 8,
                        id = 11
                );
        }

        section_layout :tc0:linear
        {
                "_lc_ue_ustack" := "_lc_ue_ustack_tc0"; /* common cstart interface for first or single core */
                "_lc_ue_istack" := "_lc_ue_istack_tc0"; /* common cstart interface for first or single core */
        }

        section_setup :vtc:linear
        {
                copytable
                (
                        align = 4,
                        dest = linear
                        ,
                        table
                        {
                                symbol = "_lc_ub_table_tc1";
                                space = :tc1:linear, :tc1:abs24, :tc1:abs18, :tc1:csa;
                        }
                        ,
                        table
                        {
                                symbol = "_lc_ub_table_tc2";
                                space = :tc2:linear, :tc2:abs24, :tc2:abs18, :tc2:csa;
                        }
                        ,
                        table
                        {
                                symbol = "_lc_ub_table_tc3";
                                space = :tc3:linear, :tc3:abs24, :tc3:abs18, :tc3:csa;
                        }
                        ,
                        table
                        {
                                symbol = "_lc_ub_table_tc4";
                                space = :tc4:linear, :tc4:abs24, :tc4:abs18, :tc4:csa;
                        }
                        ,
                        table
                        {
                                symbol = "_lc_ub_table_tc5";
                                space = :tc5:linear, :tc5:abs24, :tc5:abs18, :tc5:csa;
                        }
                );

                mpu_data_table;
        }
        section_layout :tc0:csa
        {
                group  (ordered, align = 64, attributes=rw, run_addr=(CSA_START_TC0))
                        reserved "csa_tc0" (size = 64 * (CSA_TC0));
                "_lc_ub_csa_01" := "_lc_ub_csa_tc0"; /* common cstart interface for first or single core */
                "_lc_ue_csa_01" := "_lc_ue_csa_tc0"; /* common cstart interface for first or single core */
        }

        section_layout :tc1:csa
        {
                group  (ordered, align = 64, attributes=rw, run_addr=(CSA_START_TC1))
                        reserved "csa_tc1" (size = 64 * (CSA_TC1));
        }

        section_layout :tc2:csa
        {
                group  (ordered, align = 64, attributes=rw, run_addr=(CSA_START_TC2))
                        reserved "csa_tc2" (size = 64 * (CSA_TC2));
        }

        section_layout :tc3:csa
        {
                group  (ordered, align = 64, attributes=rw, run_addr=(CSA_START_TC3))
                        reserved "csa_tc3" (size = 64 * (CSA_TC3));
        }

        section_layout :tc4:csa
        {
                group  (ordered, align = 64, attributes=rw, run_addr=(CSA_START_TC4))
                        reserved "csa_tc4" (size = 64 * (CSA_TC4));
        }

        section_layout :tc5:csa
        {
                group  (ordered, align = 64, attributes=rw, run_addr=(CSA_START_TC5))
                        reserved "csa_tc5" (size = 64 * (CSA_TC5));
        }

        section_layout :vtc:linear
        {
#if (XVWBUF>0)
                group (align = 4) reserved "_xvwbuffer_" (size=XVWBUF, attributes=rw);
                "_lc_ub_xvwbuffer" = "_lc_ub__xvwbuffer_";
                "_lc_ue_xvwbuffer" = "_lc_ue__xvwbuffer_";
#endif

#ifndef __REDEFINE_BASE_ADDRESS_GROUPS
#include        "base_address_groups.lsl"
#endif

                "_SMALL_DATA_TC0" := "_SMALL_DATA_";
                "_SMALL_DATA_TC1" := "_SMALL_DATA_";
                "_SMALL_DATA_TC2" := "_SMALL_DATA_";
                "_SMALL_DATA_TC3" := "_SMALL_DATA_";
                "_SMALL_DATA_TC4" := "_SMALL_DATA_";
                "_SMALL_DATA_TC5" := "_SMALL_DATA_";

                "_LITERAL_DATA_TC0" := "_LITERAL_DATA_";
                "_LITERAL_DATA_TC1" := "_LITERAL_DATA_";
                "_LITERAL_DATA_TC2" := "_LITERAL_DATA_";
                "_LITERAL_DATA_TC3" := "_LITERAL_DATA_";
                "_LITERAL_DATA_TC4" := "_LITERAL_DATA_";
                "_LITERAL_DATA_TC5" := "_LITERAL_DATA_";

                "_A8_DATA_TC0" := "_A8_DATA_";
                "_A8_DATA_TC1" := "_A8_DATA_";
                "_A8_DATA_TC2" := "_A8_DATA_";
                "_A8_DATA_TC3" := "_A8_DATA_";
                "_A8_DATA_TC4" := "_A8_DATA_";
                "_A8_DATA_TC5" := "_A8_DATA_";

                "_A9_DATA_TC0" := "_A9_DATA_";
                "_A9_DATA_TC1" := "_A9_DATA_";
                "_A9_DATA_TC2" := "_A9_DATA_";
                "_A9_DATA_TC3" := "_A9_DATA_";
                "_A9_DATA_TC4" := "_A9_DATA_";
                "_A9_DATA_TC5" := "_A9_DATA_";
        }

        section_layout :vtc:linear
        {
                        "_lc_u_int_tab_tc0" = (INTTAB0);
                        "_lc_u_int_tab_tc1" = (INTTAB1);
                        "_lc_u_int_tab_tc2" = (INTTAB2);
                        "_lc_u_int_tab_tc3" = (INTTAB3);
                        "_lc_u_int_tab_tc4" = (INTTAB4);
                        "_lc_u_int_tab_tc5" = (INTTAB5);
                        "_lc_u_int_tab" = "_lc_u_int_tab_tc0"; /* common cstart interface for first or single core */

                        // interrupt vector tables
                        group int_tab_tc0 (ordered)
                        {
#                               include "inttab0.lsl"
                        }
                        group int_tab_tc1 (ordered)
                        {
#                               include "inttab1.lsl"
                        }
                        group int_tab_tc2 (ordered)
                        {
#                               include "inttab2.lsl"
                        }
                        group int_tab_tc3 (ordered)
                        {
#                               include "inttab3.lsl"
                        }
                        group int_tab_tc4 (ordered)
                        {
#                               include "inttab4.lsl"
                        }
                        group int_tab_tc5 (ordered)
                        {
#                               include "inttab5.lsl"
                        }

                        "_lc_u_trap_tab_tc0" = (TRAPTAB0);
                        "_lc_u_trap_tab_tc1" = (TRAPTAB1);
                        "_lc_u_trap_tab_tc2" = (TRAPTAB2);
                        "_lc_u_trap_tab_tc3" = (TRAPTAB3);
                        "_lc_u_trap_tab_tc4" = (TRAPTAB4);
                        "_lc_u_trap_tab_tc5" = (TRAPTAB5);
                        "_lc_u_trap_tab" = "_lc_u_trap_tab_tc0"; /* common cstart interface for first or single core */

                        // trapvector tables
                        group trap_tab_tc0 (ordered)
                        {
#                               include "traptab0.lsl"
                        }
                        group trap_tab_tc1 (ordered)
                        {
#                               include "traptab1.lsl"
                        }
                        group trap_tab_tc2 (ordered)
                        {
#                               include "traptab2.lsl"
                        }
                        group trap_tab_tc3 (ordered)
                        {
#                               include "traptab3.lsl"
                        }
                        group trap_tab_tc4 (ordered)
                        {
#                               include "traptab4.lsl"
                        }
                        group trap_tab_tc5 (ordered)
                        {
#                               include "traptab5.lsl"
                        }
        }

#ifndef NOXC800INIT
        section_layout :vtc:linear
        {
                group (ordered, align=4) memcopy ".rodata.xc800init" (memory = scr_xram, fill=XC800INIT_FILL);
        }
#endif
        section_layout :vtc:linear
        {
#include        "tc1v1_6_2.bmhd.lsl"
        }
        section_layout :vtc:linear
	    {
	        group(ordered, contiguous, run_addr = 0xb0075000, align = 8, attributes=rw)
	        {
	            section "calibration_section_ram_mes" (size = 8k, overflow = "symbol", attributes=rw)
	            {
	                select ".zbss.calibration_parameter_mes_cal"(attributes =+rw);
	                select ".bss.calibration_parameter_mes_cal"(attributes =+rw);
	            }
	        }
	    }
	    section_layout :vtc:linear
	    {
	        group(ordered, contiguous, run_addr = 0xb0060000, align = 8, attributes=rw)
	        {
	            section "calibration_section_ram_cal" (size = 64k, overflow = "symbol", attributes=rw)
	            {
	                select ".zdata.calibration_parameter_wp_cal"(attributes =+rw);
	                select ".data.calibration_parameter_wp_cal"(attributes =+rw);
	                select ".zrodata.calibration_parameter_wp_cal"(attributes =+rw);
	                select ".rodata.calibration_parameter_wp_cal"(attributes =+rw);
	            }
	        }
	        group(contiguous, ordered, load_addr = 0x80100000)
	        { 
	            select ".zdata.calibration_parameter_wp_cal";
	            select ".data.calibration_parameter_wp_cal";
	            select ".zrodata.calibration_parameter_wp_cal";
	            select ".rodata.calibration_parameter_wp_cal";
	        }       
	    }
#if !defined(__DISABLE_SCR_BOOT_MAGIC)
        /*
         *      The last 8 bytes of SCR XRAM starting at address 0x01FF8 must contain
         *      4 pairs of bytes where each pair consists of 0x55 followed by 0xAA.
         *      The user code will not be executed and the SCR will enter an endless
         *      loop if the memory content does not match this data sequence. This
         *      feature is meant to avoid an unintentional entry into User Mode 1.
         *      When the 8 bytes match, the SCR boot code will trigger an interrupt
         *      to the TriCore by setting bit NMICON.SCRINTTC to 1 with a value of 0x80
         *      in the SCRINTEXCHG register. When the 8 bytes do not match, the same
         *      interrupt is triggered with a value of 0x81 in the SCRINTEXCHG register.
         */
        section_layout :xc800:xdata
        {
                group(ordered, run_addr=0x1ff8)
                {
                        struct "scr_boot_magic"
                        {
                                0x55:1; 0xaa:1;
                                0x55:1; 0xaa:1;
                                0x55:1; 0xaa:1;
                                0x55:1; 0xaa:1;
                        }
                }
        }
#endif
}

//
//      The following macros are required for extmem.lsl
//
#define HAS_ON_CHIP_FLASH       // This derivative has on-chip flash
#define HAS_NO_EXTERNAL_RAM     // Exclude xram_8_a

