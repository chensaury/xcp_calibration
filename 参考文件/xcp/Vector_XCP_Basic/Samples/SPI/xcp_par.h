/*----------------------------------------------------------------------------
| File:
|   XCP_PAR.H
|
| Project:
|   XCP on CAN Sample
|
| Description
|   XCP custom definitions
|
 ----------------------------------------------------------------------------*/
#if defined ( __XCP_PAR_H__ )
#else
#define __XCP_PAR_H__


/* XCP default settings */
#include "xcp_def.h"

/* Slave device id */
// CANape uses this to determine the name of the A2L file
#define kXcpStationIdLength 3    /* Slave device identification length in characters */
#define kXcpStationIdString "XCP"
V_MEMROM0 extern vuint8 MEMORY_ROM kXcpStationId[];


#endif
