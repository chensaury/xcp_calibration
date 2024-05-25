/* xcp_par.h */

#if defined ( __XCP_PAR_H__ )
#else
#define __XCP_PAR_H__

/* XCP default settings */
#include "xcp_def.h"

/* XCP slave device identification (optional) */
#define kXcpStationIdLength 6    /* Slave device identification length */

V_MEMROM0 extern vuint8 MEMORY_ROM kXcpStationId[];





#endif
