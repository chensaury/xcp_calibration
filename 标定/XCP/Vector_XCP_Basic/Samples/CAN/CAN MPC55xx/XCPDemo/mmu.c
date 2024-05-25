#include "project.h"


unsigned char MMUWriteTLBEntry(
  unsigned char n, 
  unsigned int ea, 
  unsigned int ra, 
  unsigned int pagesize, 
  unsigned char cache_inhibit, 
  unsigned char cache_writethrough,
  unsigned char permissions) {  

  unsigned int rpn,epn;
  unsigned char pagetype,pageshift;
  
  switch (pagesize) {
    case 0x001000: pagetype = 1; pageshift = 12; break; // 4 K
    case 0x004000: pagetype = 2; pageshift = 14; break; // 16 K
    case 0x010000: pagetype = 3; pageshift = 16; break; // 64 K
    case 0x040000: pagetype = 4; pageshift = 18; break; // 256 K
    case 0x100000: pagetype = 5; pageshift = 20; break; // 1M
    default: return 0;
  }

  if ((ra%pagesize) || (ea%pagesize)) return 0;                         
  rpn = ra/pagesize;
  epn = ea/pagesize;
   
  /* Select TLB entry */
  mtMAS0(0x10000000|(n<<16));

  /* Define description context and configuration control:*/
  /* VALID=1, IPROT=0, TID=0, TS=0, TSIZE=pagetype */
  mtMAS1(0x80000000|(pagetype<<8)); 

  /* Define EPN and page attributes: */
  /* EPN = 0x06000 (addr=0x60000000), WIMAGE = xx000 */
  mtMAS2((epn<<pageshift) | (cache_inhibit?0x8:0) | (cache_writethrough?0x10:0)); 
 
  /* Define RPN and access control for data R/W */
  /* RPN = , U0:3=0, UX/SX=0, UR/SR=1, UW/SW=1 */
  mtMAS3((rpn<<pageshift)|(0x3F&permissions)); 

  asm("tlbwe"); /* Write entry defined in MAS0 to MMU TLB */
  // tlbwe();

  return 1;
}


