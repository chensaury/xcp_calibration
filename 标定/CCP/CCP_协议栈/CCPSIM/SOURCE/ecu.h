/* ecu.h */
/* Declarations for ECU simulation ECU.C */

extern unsigned short CALRAM_START;
extern unsigned short CALRAM_LAST;

#define CALRAM       ((unsigned char*)&CALRAM_START)
#define CALRAM_SIZE  ((unsigned char*)&CALRAM_LAST-(unsigned char*)&CALRAM_START)

extern unsigned char gDebugLevel;

extern void ecuCyclic( void );
extern void ecuInit( void );

