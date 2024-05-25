/* xcp_par.h */

#if defined ( __XCP_PAR_H__ )
#else
#define __XCP_PAR_H__

/* XCP default settings */
#include "xcp_def.h"

/* XCP slave device identification */
#define kXcpStationIdLength 7       /* Slave device identification length */
#define kXcpStationIdString "XCPDemo"
extern const vuint8 kXcpStationId[];

V_MEMROM0 extern vuint8 MEMORY_ROM kXcpStationId[];

#endif
