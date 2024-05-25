/*******************************************************************************
* Example Code
*
* Copyright(C) 2023 NXP Semiconductors
* NXP Semiconductors Confidential and Proprietary
*
* Software that is described herein is for illustrative purposes only
* which provides customers with programming information regarding the
* NXP products.  This software is supplied "AS IS" without any warranties
* of any kind, and NXP Semiconductors and its licensor disclaim any and
* all warranties, express or implied, including all implied warranties of
* merchantability, fitness for a particular purpose and non-infringement of
* intellectual property rights.  NXP Semiconductors assumes no responsibility
* or liability for the use of the software, conveys no license or rights
* under any patent, copyright, mask work right, or any other intellectual
* property rights in or to any products. NXP Semiconductors reserves the
* right to make changes in the software without notification. NXP
* Semiconductors also makes no representation or warranty that such
* application will be suitable for the specified use without further testing
* or modification.
*
* IN NO EVENT WILL NXP SEMICONDUCTORS BE LIABLE, WHETHER IN CONTRACT, 
* TORT, OR OTHERWISE, FOR ANY INCIDENTAL, SPECIAL, INDIRECT, CONSEQUENTIAL 
* OR PUNITIVE DAMAGES, INCLUDING, BUT NOT LIMITED TO, DAMAGES FOR ANY 
* LOSS OF USE, LOSS OF TIME, INCONVENIENCE, COMMERCIAL LOSS, OR LOST 
* PROFITS, SAVINGS, OR REVENUES, TO THE FULL EXTENT SUCH MAY BE DISCLAIMED  
* BY LAW. NXP SEMICONDUCTOR’S TOTAL LIABILITY FOR ALL COSTS, DAMAGES, 
* CLAIMS, OR LOSSES WHATSOEVER ARISING OUT OF OR IN CONNECTION WITH THE 
* SOFTWARE IS LIMITED TO THE AGGREGATE AMOUNT PAID BY YOU TO NXP SEMICONDUCTORS
* IN CONNECTION WITH THE SOFTWARE TO WHICH LOSSES OR DAMAGES ARE CLAIMED.
*
* Permission to use, copy, modify, and distribute this software and its
* documentation is hereby granted, under NXP Semiconductors' and its
* licensor's relevant copyrights in the software, without fee, provided
* that it is used in conjunction with NXP Semiconductors devices.  This
* copyright, permission, and disclaimer notice must appear in all copies
* of this code.
*******************************************************************************/

/*
 * PT2000_irq.h
 *
 *  PT2000 Interrupt Header File
 *
 */
 
#ifndef PT2000_IRQ_H_
#define PT2000_IRQ_H_
 
#include "stdint.h"

//========================================================================================
// Function Declarations
//========================================================================================
void ProcessPT2000Interrupts(void);
void ProcessDriverInterrupts(void);
void ProcessAutomaticInterrupts(void);
void ProcessSoftwareInterrupts(void);

uint16_t AutoErr(unsigned char INJ);

const typedef enum {
    INJ1 =  1,
    INJ2,
    INJ3,
    INJ4,
    INJ5,
    INJ6,
    FP,
}INJ;



#define High_side_VBAT_OPEN_OR_VBAT_SHORT_GND              0
#define HSX_SHORT_VBAT                                     1
#define VBOOST_SHORT_GND                                   2
#define High_side_VBoost_OPEN                              4
#define VBOOST_SHORT_DRAIN_SOURCE                          8
#define Low_side_OPEN_OR_Low_side_SHORT_VBAT_OR_VBOOST     16
#define LS_SHORT_GND                                       32

#endif /* PT2000_IRQ_H_ */
