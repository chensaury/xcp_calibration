/*----------------------------------------------------------------------------
| File:
|   ecu.cpp
|
| Description:
|   ECU Simulation for all CANape CCP and XCP samples
|
 ----------------------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>

#include "ccppar.h"
#include "ecu.h"

/**************************************************************************/

#if !defined(WIN32) && !defined(__WIN32__) && !defined(C_MINI_CAN_DRIVER)
#include "can_inc.h"
#endif

#if defined(C_COMP_COSMIC_12)
  #define setLed(a,b)
#endif

#if defined( C_COMP_HWB_SH7055 )
  #define ENABLE_FLOAT
  #define setLed(a,b)
  #define volatile
#endif

#if defined( C_COMP_TASKING_C16X )
  #include <reg167.h>
  #define random(x) (T3/650)
  #ifdef CANBOX
    #include "ledio.h"
  #endif
#endif

#if defined(__WIN32__) || defined(WIN32)
  #define ENABLE_DOUBLE
  #define ENABLE_FLOAT
  #define setLed(a,b)
  #define volatile
#endif



/**************************************************************************/
/* ECU Measurement RAM */
/**************************************************************************/

#ifdef ENABLE_FLOAT
float timer;
float channel1;
float channel2;
float channel3;
float channel4;
float channel5;
float noise;
float noise_ampl;
#else
unsigned long timer;
short channel1;
short channel2;
short channel3;
short channel4;
short channel5;
short noise;
#endif
#ifdef ENABLE_DOUBLE
double channel_d;
#endif

unsigned char byteRandom;
unsigned char byteCounter;
unsigned short wordCounter;
unsigned long dwordCounter;
signed char sbyteCounter;
signed short swordCounter;
signed long sdwordCounter;

unsigned char byteShift;
unsigned short wordShift;

unsigned char map1InputX;
unsigned char map1InputY;
unsigned char map1Output;
unsigned char curveInput;
unsigned char curveOutput;
unsigned char curveOutput1;
unsigned char curveOutput2;
unsigned char curveOutput3;
unsigned char curveOutput4;

signed char sbyteTriangleSlope;
signed char sbyteTriangle;
unsigned char bytePWM;

unsigned char bytePWMFiltered;

unsigned char testbyte1;
unsigned char testbyte2;
unsigned char testbyte3;
unsigned char testbyte4;
unsigned char testbyte5;
unsigned char testbyte6;
unsigned char testbyte7;
unsigned char testbyte8;
unsigned char testbyte9;
unsigned char testbyte0;

unsigned short vin;
unsigned short v;

unsigned char ti;
unsigned char xi;
unsigned char yi;

#if !defined (COSMIC_HC12D60_TwinPEEK)
  unsigned char analogIndex;
  unsigned short analogChannel[16];


struct bitStruct {
  unsigned int s0 : 1;
  unsigned int s1 : 5;
  unsigned int s2 : 9;
  unsigned int s3 : 1;
};

struct bitStruct bitstruct1; /* = { 0, 5, 9, 0 }; */
struct bitStruct bitstruct2; /* = 0x4082 */
#endif
#if defined(C_COMP_TASKING_C16X)
  bit testsinglebit1;
  bit testsinglebit2;
#endif

char testString[] = "TestString"; 


/**************************************************************************/
/* ECU Calibration RAM */
/**************************************************************************/

#if defined(C_COMP_TASKING_C16X)
  #pragma romdata
  #pragma class NC=CALROM
#endif

unsigned short CALRAM_START = 0xAAAA;

unsigned char flashSignatur[32] = "Default";

#ifdef ENABLE_FLOAT

volatile float period = 5;	 /* Variant 0 */
volatile float ampl   = 6;
volatile float limit  = 100;
volatile float offset = 0;
volatile float filter = 0;

volatile float period1 = 10;	 /* Variant 1 */
volatile float ampl1   = 6;
volatile float limit1  = 100;
volatile float offset1 = 10;
volatile float filter1 = 10;
                                 /* Selector */
volatile unsigned char variantSelector = 0;

#else 

volatile unsigned short period = 5;   
volatile unsigned short ampl   = 1;
volatile short limit  = 100;
volatile short offset = 0;
volatile short filter = 8;

#endif

#ifdef ENABLE_DOUBLE

volatile double period_d = 5;	 /* Variant 0 */
volatile double ampl_d   = 6;

#endif

volatile unsigned short  a = 1;
volatile unsigned short  b = 5;
volatile unsigned short  c = 6;
volatile signed char sbytePWMLevel = 0;
volatile unsigned char	bytePWMFilter = 50;

volatile unsigned char	byte1  = 1;
volatile unsigned char	byte2  = 2;
volatile unsigned char	byte3  = 3;
volatile unsigned char	byte4  = 4;
volatile unsigned char	byte5  = 5;

#if !defined (COSMIC_HC12D60_TwinPEEK)
  volatile unsigned short  word1  = 1;
  volatile unsigned short  word2  = 1;
  volatile unsigned short  word3  = 1;
  volatile unsigned short  word4  = 1;
  volatile unsigned long dword1 = 1;
  volatile unsigned long dword2 = 1;
  volatile unsigned long dword3 = 1;
  volatile unsigned long dword4 = 1;
#endif

volatile unsigned char map1Counter = 25;

volatile unsigned char map1_8_8_uc[8][8] =
  {{0,0,0,0,0,0,1,2},
   {0,0,0,0,0,0,2,3},
   {0,0,0,0,1,1,2,3},
   {0,0,0,1,1,2,3,4},
   {0,1,1,2,3,4,5,7},
   {1,1,1,2,4,6,8,9},
   {1,1,2,4,5,8,9,10},
   {1,1,3,5,8,9,10,10}
};

volatile unsigned char map_kf1[8][8] =
  {{1,1,1,1,1,1,1,1},
   {1,1,1,1,1,1,1,1},
   {1,1,1,1,1,1,1,1},
   {1,1,1,1,1,1,1,1},
   {1,1,1,1,1,1,1,1},
   {1,1,1,1,1,1,1,1},
   {1,1,1,1,1,1,1,1},
   {1,1,1,1,1,1,1,1}
};

volatile unsigned char map_kf2[8][8] =
  {{0,0,0,0,0,0,10,20},
   {0,0,0,0,0,0,20,30},
   {0,0,0,0,10,10,20,30},
   {0,0,0,10,10,20,30,40},
   {0,10,10,20,30,40,50,70},
   {10,10,10,20,40,60,80,90},
   {10,10,20,40,50,80,90,100},
   {10,10,30,50,80,90,100,100}
};

volatile unsigned char map_kf3[8][8] =
  {{0,0,0,0,0,0,0,0},
   {1,1,1,1,1,1,1,1},
   {2,2,2,2,2,2,2,2},
   {3,3,3,3,3,3,3,3},
   {4,4,4,4,4,4,4,4},
   {5,5,5,5,5,5,5,5},
   {6,6,6,6,6,6,6,6},
   {7,7,7,7,7,7,7,7}
};

volatile unsigned char map_kf4[8][8] =
  {{0,0,0,0,0,0,0,0},
   {1,1,1,1,1,1,1,1},
   {2,2,2,2,2,2,2,2},
   {3,3,3,3,3,3,3,3},
   {4,4,4,4,4,4,4,4},
   {5,5,5,5,5,5,5,5},
   {6,6,6,6,6,6,6,6},
   {7,7,7,7,7,7,7,7}
};

volatile unsigned char map_kf6[8][8] =
  {{6,6,6,6,6,6,6,6},
   {6,6,6,6,6,6,6,6},
   {6,6,6,6,6,6,6,6},
   {6,6,6,6,6,6,6,6},
   {6,6,6,6,6,6,6,6},
   {6,6,6,6,6,6,6,6},
   {6,6,6,6,6,6,6,6},
   {6,6,6,6,6,6,6,6}
};

  volatile unsigned char map_kf7[8][8] = {
    { 1, 2, 3, 4, 5, 6, 7, 8},
    {11,12,13,14,15,16,17,18},
    {21,22,23,24,25,26,27,28},
    {31,32,33,34,35,36,37,38},
    {41,42,43,44,45,46,47,48},
    {51,52,53,54,55,56,57,58},
    {61,62,63,64,65,66,67,68},
    {71,72,73,74,75,76,77,78}
  };

  volatile unsigned char map_kf8[8][8] =
    {{0,0,0,0,0,0,1,2},
     {0,0,0,0,0,0,2,3},
     {0,0,0,0,1,1,2,3},
     {0,0,0,1,1,2,3,4},
     {0,1,1,2,3,4,5,7},
     {1,1,1,2,4,6,8,9},
     {1,1,2,4,5,8,9,10},
     {1,1,3,5,8,9,10,10}
  };

#if !defined (COSMIC_HC12D60_TwinPEEK)
  volatile unsigned char map2_8_8_uc[8][8] = {
    { 1, 2, 3, 4, 5, 6, 7, 8},
    {11,12,13,14,15,16,17,18},
    {21,22,23,24,25,26,27,28},
    {31,32,33,34,35,36,37,38},
    {41,42,43,44,45,46,47,48},
    {51,52,53,54,55,56,57,58},
    {61,62,63,64,65,66,67,68},
    {71,72,73,74,75,76,77,78}
  };

  volatile unsigned char map3_8_8_uc[8][8] =
    {{0,0,0,0,0,0,1,2},
     {0,0,0,0,0,0,2,3},
     {0,0,0,0,1,1,2,3},
     {0,0,0,1,1,2,3,4},
     {0,1,1,2,3,4,5,7},
     {1,1,1,2,4,6,8,9},
     {1,1,2,4,5,8,9,10},
     {1,1,3,5,8,9,10,10}
  };
#endif


volatile unsigned char map4_80_uc[80] =
  {
   0,  1,  2,  3,  4,  5,  6,  7,
   /* X Coordinates */
   100,101,102,103,104,105,106,107,  /* Y Coordinates */
   1,2,3,4,5,6,7,8,		     /* Values		  */
   1,2,3,4,5,6,7,8,		     /* Values		  */
   1,2,3,4,5,6,7,8,		     /* Values		  */
   1,2,3,4,5,6,7,8,		     /* Values		  */
   1,2,3,4,5,6,7,8,		     /* Values		  */
   1,2,3,4,5,6,7,8,		     /* Values		  */
   1,2,3,4,5,6,7,8,		     /* Values		  */
   1,2,3,4,5,6,7,8		     /* Values		  */
};

volatile unsigned char map_kf5[80] =
  {
   0,  1,  2,  3,  4,  5,  6,  7,
   /* X Coordinates */
   100,101,102,103,104,105,106,107,  /* Y Coordinates */
   1,2,3,4,5,6,7,8,		     /* Values		  */
   1,2,3,4,5,6,7,8,		     /* Values		  */
   1,2,3,4,5,6,7,8,		     /* Values		  */
   1,2,3,4,5,6,7,8,		     /* Values		  */
   1,2,3,4,5,6,7,8,		     /* Values		  */
   1,2,3,4,5,6,7,8,		     /* Values		  */
   1,2,3,4,5,6,7,8,		     /* Values		  */
   1,2,3,4,5,6,7,8		     /* Values		  */
};

volatile unsigned char curve5_16_uc[16] =
  {1,2,3,4,5,6,8,12,14,11,9,7,6,5,4,3};

volatile unsigned char curve5_16_uc1[16] =
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
volatile unsigned char curve5_16_uc2[16] =
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
volatile unsigned char curve5_16_uc3[16] =
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
volatile unsigned char curve5_16_uc4[16] =
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

#if !defined (COSMIC_HC12D60_TwinPEEK)

  volatile unsigned char map5_82_uc[82] =
    {
     8, 0,1,2,3,4,5,6,7,  /* X-coordinates */
     8, 0,1,2,3,4,5,6,7,  /* Y-coordinates */
     0,0,0,0,0,0,1,2,
     0,0,0,0,0,0,2,3,
     0,0,0,0,1,1,2,3,
     0,0,0,1,1,2,3,4,
     0,1,1,2,3,4,5,7,
     1,1,1,2,4,6,8,9,
     1,1,2,4,5,8,9,10,
     1,1,3,5,8,9,10,10
  };

  /* Test for insert and delete axis points, max 10*10 */
  volatile unsigned char map6_122_uc[] =
  {
     10,		    /* X-Axis Points */
     0,1,2,3,0,0,0,0,0,0,  /* X-coordinates */
     10,		    /* Y-Axis Points */
     0,1,2,3,0,0,0,0,0,0,  /* Y-coordinates */

     00,01,02,03,00,00,00,00,00,00,
     10,11,12,13,00,00,00,00,00,00,
     20,21,22,23,00,00,00,00,00,00,
     30,31,32,33,00,00,00,00,00,00,
     00,00,00,00,00,00,00,00,00,00,
     00,00,00,00,00,00,00,00,00,00,
     00,00,00,00,00,00,00,00,00,00,
     00,00,00,00,00,00,00,00,00,00,
     00,00,00,00,00,00,00,00,00,00,
     00,00,00,00,00,00,00,00,00,00
  };



volatile unsigned char curve1_8_uc[8] =
  {1,2,3,4,5,6,8,12};

volatile unsigned char curve2_8_uc[8] =
  {11,12,13,14,15,16,18,22};

#if !defined (COSMIC_HC12D60_TwinPEEK)
  volatile unsigned char curve3_8_uc[8] =
    {21,22,23,24,25,26,28,32};

  volatile unsigned char curve4_8_uc[16] =
    {41,42,43,44,45,46,48,52,
     51,52,53,54,55,56,58,62};
#endif

volatile unsigned char curve4_17_uc[17] =
  {
   8, 0,1,2,3,4,5,6,7,	/* X-coordinates */
      0,1,1,2,3,4,5,7
};


volatile unsigned char input1_uc[2] = { 112, 113 };
volatile unsigned char input2_uc = 114;


volatile unsigned char curve_kl2[8] =
  {11,22,33,44,55,66,77,88};

volatile unsigned char curve_kl3[16] =
    {41,42,43,44,45,46,48,52,
     51,52,53,54,55,56,58,62};

volatile unsigned char curve_kl4[16] =
    {41,42,43,44,45,46,48,52,
     51,52,53,54,55,56,58,62};

volatile unsigned char curve_kl5[8] =
  {10,20,30,40,50,60,80,120};


volatile unsigned char curve_kl6[8] =
  {21,22,23,24,25,26,28,32};

volatile unsigned short curve_kl7[16] =
  {1,11,2,12,3,13,4,14,5,15,6,16,7,17,8,18};

volatile unsigned short curve_kl8[8] =
  {1,2,3,4,5,6,7,8};

volatile struct {
  unsigned char n;
  float x[8];
  float v[8];
} curve_kl9 =  {8,{1,2,3,4,5,6,7,8},{0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8}};

volatile struct {
  unsigned char n;
  float v[8];
} curve_kl10 =  {8,{0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8}};







volatile unsigned char calram[32][32] = {
  0,1,2,3,4,5,6,7,8,9,
  10,11,12,13,14,15,16,17,18,19,
  20,21,22,23,24,25,26,27,28,29,
  30,31,32,33,34,35,36,37,38,39,
  40,41,42,43,44,45,46,47,48,49,
  50,51,52,53,54,55,56,57,58,59,
  60,61,62,63,64,65,66,67,68,69,
  70,71,72,73,74,75,76,77,78,79,
  80,81,82,83,84,85,86,87,88,89,
  90,91,92,93,94,95,96,97,98,99
};

/* EEPROM */
volatile unsigned char eeprom[8] = {
  0,1,2,3,4,5,6,7
};

/* Array of struct */
typedef struct	{
  char ch1;
  long l;
  char ch2;
  int  i;
} test_t ;

volatile test_t test_array[10] =
{
  {0,1,2,3},
  {10,11,12,13},
  {20,21,22,23},
  {30,31,32,33},
  {40,41,42,43},
  {50,51,52,53},
  {60,61,62,63},
  {70,71,72,73},
  {80,81,82,83},
  {90,91,92,93}
};


volatile signed char TestArray_Max_10_10[122] =
{
  5, 5, 		 /* Anzahl Stuetzstellen */
  1, 2, 3, 4, 5,	 /* X-Stuetzstellen		 */
  1, 2, 3, 4, 5,	 /* Y-Stuetzstellen		 */
  11, 21, 31, 41, 51,	 /* Zeile 1				 */
  12, 22, 32, 42, 52,	 /* Zeile 2				 */
  13, 23, 33, 43, 53,	 /* Zeile 3				 */
  14, 24, 34, 44, 54,	 /* Zeile 4				 */
  15, 25, 35, 45, 55,	 /* Zeile 5				 */
  0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0
};

volatile signed short noise_distribution[32] = {  
-24,  -21,  -17,  -14,	-10,  -8,  -6,	-5,  -4,  -3,  -2,  -1,  -1,  0,  0,  0,  0
,  0,  0,  1,  1,  1,  2,  3,  4,  5,  7,  9,  11,  13,  16,  20
 } ;







/* used template: map.templ */
/* standard template for map without axis points */
/* number of axis points variable, datatype variable */
/*  */
/* unit:  */
/* min: -100 */
/* max: 100 */


volatile signed short channel5_map[20][20] = { 

   1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
,  0,  0,  0
,  2,  2,  1,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0
,  0,  0,  0
,  3,  3,  3,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1
,  1,  0,  0
,  3,  4,  2,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1
,  1,  0,  0
,  3,  4,  2,  2,  2,  2,  2,  2,  2,  1,  1,  1,  1,  1,  1,  1,  1
,  1,  0,  0
,  4,  3,  3,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1
,  1,  0,  0
,  4,  3,  3,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  1
,  1,  0,  0
,  5,  4,  4,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  2,  2,  1
,  1,  0,  0
,  5,  4,  4,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  2,  2,  1
,  1,  0,  0
,  6,  5,  5,  4,  4,  4,  4,  4,  4,  4,  4,  3,  3,  3,  2,  2,  1
,  1,  0,  0
,  6,  6,  5,  4,  4,  4,  4,  4,  4,  4,  4,  4,  3,  3,  2,  2,  1
,  1,  0,  0
,  6,  5,  5,  3,  5,  5,  5,  4,  4,  4,  4,  4,  3,  3,  2,  2,  1
,  1,  0,  0
,  6,  5,  5,  5,  5,  5,  5,  5,  4,  4,  4,  4,  4,  3,  2,  2,  2
,  1,  0,  0
,  7,  7,  7,  6,  6,  6,  5,  5,  4,  4,  4,  4,  4,  3,  2,  2,  2
,  1,  0,  0
,  8,  8,  8,  7,  7,  6,  5,  5,  4,  4,  4,  4,  4,  3,  3,  2,  2
,  1,  0,  0
,  11,	8,  8,	7,  8,	6,  5,	5,  4,	4,  4,	4,  4,	3,  3,	2,  2
,  1,  0,  0
,  12,	10,  9,  7,  8,  7,  5,  6,  5,  5,  5,  5,  4,  4,  4,  2,  2
,  1,  0,  0
,  13,	12,  11,  10,  9,  6,  6,  6,  5,  5,  5,  4,  4,  4,  3,  3,  3
,  2,  1,  1
,  15,	13,  12,  11,  9,  7,  7,  7,  6,  6,  6,  5,  5,  5,  4,  4,  4
,  3,  2,  1
,  16,	13,  13,  12,  10,  9,	8,  8,	8,  8,	7,  6,	6,  6,	5,  5,	4
,  4,  3,  2
 
};

#endif



unsigned long CALRAM_SIGN = 0x0055AAFF;
unsigned short CALRAM_LAST = 0xAAAA;

#if defined(C_COMP_TASKING_C16X)
  #pragma default_attributes
  #pragma iramdata
#endif


/**************************************************************************/
/* ECU Calibration FLASH */
/**************************************************************************/

#if 0

#if defined(C_COMP_TASKING_C16X)
  #pragma romdata
  #pragma class NC=CALFLASH
#endif

const unsigned short CALFLASH_START = 0xAAAA;


const unsigned char map100_8_8_uc[8][8] =
  {{0,0,0,0,0,0,1,2},
   {0,0,0,0,0,0,2,3},
   {0,0,0,0,1,1,2,3},
   {0,0,0,1,1,2,3,4},
   {0,1,1,2,3,4,5,7},
   {1,1,1,2,4,6,8,9},
   {1,1,2,4,5,8,9,10},
   {1,1,3,5,8,9,10,10}
};


const unsigned short CALFLASH_LAST = 0xAAAA;

#if defined(C_COMP_TASKING_C16X)
  #pragma default_attributes
  #pragma iramdata
#endif

#endif


/**************************************************************************/
/* ECU Emulation */
/**************************************************************************/

#ifndef random
static unsigned short RndCnt = 3;
unsigned short random(unsigned short max) {
  RndCnt += max + RndCnt/3;
  return RndCnt % (max+1);
}
#endif


void ecuInit( void ) {

  timer  = 0;
  channel1 = 0;
  channel2 = 0;
  channel3 = 0;
  channel4 = 0;
  channel5 = 0;
  noise  = 0;
  byteRandom  = 0;
  byteCounter  = 0;
  wordCounter = 0;
  dwordCounter = 0;
  sbyteCounter	= 0;
  swordCounter = 0;
  sdwordCounter = 0;
  byteShift  = 1;
  wordShift = 1;
  map1InputX = 2;
  map1InputY = 4;
  map1Output = 0;
  curveInput = 0;
  curveOutput = 0;
  curveOutput1 = 0;
  curveOutput2 = 0;
  curveOutput3 = 0;
  curveOutput4 = 0;
  sbyteTriangleSlope = 1;
  sbyteTriangle = 0;
  bytePWM = 0;
  bytePWMFiltered = 0;
  testbyte1 = 101;
  testbyte2 = 102;
  testbyte3 = 103;
  testbyte4 = 104;
  testbyte5 = 105;
  testbyte6 = 106;
  testbyte7 = 107;
  testbyte8 = 108;
  testbyte9 = 109;
  testbyte0 = 100;
  vin =0;
  v = 0;
  ti = 0;
  xi = 1;
  yi = 1;
  #if !defined (COSMIC_HC12D60_TwinPEEK)
    bitstruct1.s0 = 0;
    bitstruct1.s1 = 5;
    bitstruct1.s2 = 9;
    bitstruct1.s3 = 0;
  #endif
  #if defined(C_COMP_TASKING_C16X)
    testsinglebit1 = 0;
    testsinglebit2 = 0;
  #endif

  #ifdef CANBOX
    analogIndex = 0xf;
    /* fixed channel single conversion */
    /* converts channel 0 */
    /* ADC start bit is reset */
    /* conversion time = TCL * 24 */
    /* sample time = conversion time * 1 */
    ADCON = analogIndex&0xF;
    ADST = 1;
  #endif


}

/* 10ms Raster */
void ecuCyclic( void )
{

  /* Floatingpoint sine signals */
  #ifdef ENABLE_FLOAT
    {

      float period0,offset0,ampl0,limit0;

      if (variantSelector==1) {
	period0 = period1;
	offset0 = offset1;
	ampl0 = ampl1;
	limit0 = limit1;
      } else {
	period0 = period;
	offset0 = offset;
	ampl0 = ampl;
	limit0 = limit;
      }
      if (period0>0.01||period0<-0.01) {
	     channel1  = (float)(offset0+noise+sin(6.283185307*timer/period0*1)*ampl0);
	     if (channel1>limit0) channel1 = limit0;
	     if (channel1<-limit0) channel1 = -limit0;
	     channel2  = (float)(noise+sin(6.283185307*timer/period0*2)*ampl0);
	     channel3  = (float)(noise+sin(6.283185307*timer/period0*3)*ampl0);
	     channel4  = (float)(noise+sin(6.283185307*timer/period0*4)*ampl0);
             #ifdef ENABLE_DOUBLE
               channel_d = sin(6.283185307*timer/period_d*4)*ampl_d;
             #endif
      }
      timer = (float)(timer+0.01);
      noise = noise_ampl * (float)(random(100)/100.0-0.5);

   }

  #else

    timer += 10; /* 1ms Resolution */

    noise = random(31);
    #if !defined (COSMIC_HC12D60_TwinPEEK)
      channel1 = offset + ampl*noise_distribution[noise] + channel1;
    #endif
    if (channel1>limit) channel1 = limit;
    if (channel1<-limit) channel1 = -limit;
    noise = random(31);
    #if !defined (COSMIC_HC12D60_TwinPEEK)
      channel2 = offset + ampl*noise_distribution[noise] + channel2;
    #endif
    if (channel2>limit) channel2 = limit;
    if (channel2<-limit) channel2 = -limit;
    #if !defined (COSMIC_HC12D60_TwinPEEK)
      channel3 = ((long)channel1*(filter)+(long)channel3*(100-filter))/100;
      channel4 = ((long)channel2*(filter)+(long)channel4*(100-filter))/100;
      channel5 = channel5_map[(channel1+100)/10][(channel2+100)/10];
    #endif
  #endif

  /* Working point example */
  /* Test map1_8_8_uc */
  if (++ti>map1Counter) {
   ti = 0;
   if (random(100)>50) {
     map1InputX += xi;
     if (map1InputX>=7||map1InputX<=0) {
       xi *= -1;
     }
   }
   if (random(100)>50) {
     map1InputY += yi;
     if (map1InputY>=7||map1InputY<=0) {
       yi *= -1;
     }
   }
  }
  map1Output = map1_8_8_uc[map1InputY][map1InputX];

  /* Test curve5_16_uc */
  curveOutput  = curve5_16_uc[(curveInput)>>4];
  curveOutput1 = curve5_16_uc1[(curveInput)>>4];
  curveOutput2 = curve5_16_uc2[(curveInput)>>4];
  curveOutput3 = curve5_16_uc3[(curveInput)>>4];
  curveOutput4 = curve5_16_uc4[(curveInput)>>4];
  curveInput++;

  /* Random numbers */
  byteRandom = (byteRandom+37)*41;

  /* PWM Example */
  sbyteTriangle += sbyteTriangleSlope;
  if (sbyteTriangle>=50) sbyteTriangleSlope = -1;
  if (sbyteTriangle<=-50) sbyteTriangleSlope = 1;
  if (sbyteTriangle>sbytePWMLevel) {
    #ifdef CANBOX
      if (bytePWM==0) setLed(8,1);
    #endif
    bytePWM = 100;
  } else {
    #ifdef CANBOX
      if (bytePWM==100) setLed(8,0);
    #endif
    bytePWM = 0;
  }
  bytePWMFiltered = (bytePWMFilter*bytePWMFiltered+(100-bytePWMFilter)*bytePWM)/100;

  /* Filter Examples */

  if(c==0) {
    /* Dieterle 27.06.2002 dieses Problem kann auftreten, wenn man ein bestimmtes HEX-File laedt ??*/
    v=0;
  }  
  else {
    v = (a*vin + b*v)/c;
  }

  /* Counters */
  byteCounter++;
  wordCounter++;
  dwordCounter++;
  sbyteCounter++;
  swordCounter++;
  sdwordCounter++;

  /* Shifters */
  byteShift <<=1; if (byteShift==0) byteShift=1;
  wordShift <<=1; if (wordShift==0) wordShift=1;

  /* Analog Input */
  #ifdef CANBOX
    if (ADCIR) {
     ADCIR = 0;
     analogChannel[analogIndex] = ADDAT;
     /*analogIndex++; */
     ADCON = analogIndex&0xF;
     ADST = 1;
    }
  #endif


}



