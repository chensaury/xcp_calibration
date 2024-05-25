/*
 * PSI5.h
 *
 *  Created on: 2023年8月2日
 *      Author: LENOVO
 */

#ifndef PSI5_H_
#define PSI5_H_

#include "Platform_Types.h"

typedef struct
{
    uint16 spiMasterTxBuffer[4];                 /* QSPI Master Transmit buffer   */
    uint16 spiMasterRxBuffer[4];                 /* QSPI Master Receive buffer    */
} psi5Buffers;

void PSI5_Init(void);
void PSI5_ReadData_24Bit(sint16 psi5data[][2]);

#endif /* PSI5_H_ */
