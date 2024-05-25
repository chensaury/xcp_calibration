//#include <iom128v.h>
//#include <iom8v.h>
#include <iom163v.h>

#include <macros.h>
#include <stdio.h>
#include <string.h>
#include <eeprom.h>   
#include <math.h>
#include <stdarg.h>
        
#define ATMEL
#define XCP
#define UARTINTR
#define UARTINTR_SMALL
#define SYSCLK 8000000
#define USE_XCP
#define XCP_INTERRUPT_CONTROL
#define XCP_ON_UART

// #include "uart.h"
#include "uartintr.h"
#include "xcpBasic.h"
#include "test1.h"
 
