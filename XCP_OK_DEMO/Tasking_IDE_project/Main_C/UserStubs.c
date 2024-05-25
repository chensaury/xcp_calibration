/*user defines stubs */


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "EcuM.h"
#include "os.h"

#include "VStdLib.h"
#include "UserStubs.h"

/*******************************************************************************
**                      Imported Compiler Switch Checks                       **
*******************************************************************************/


/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define BRSHW_IOS(type, address) (*((volatile type *)(address)))
#define BRS_SFR_WDTCON0       BRSHW_IOS(uint32, 0xF003624C)  /* CPU0 WDT Control Register 0 - original name: SCU_WDTCPU0CON0 */

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
void BrsHwUnlockInit(void);
void BrsHwLockInit(void);

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

void Appl_UnlockEndinit(void)
{
	BrsHwUnlockInit();
}

void Appl_LockEndinit(void)
{
	BrsHwLockInit();
}

void Test_Mcal_ReportSafetyError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId)
{

}

/*****************************************************************************/
/**
 * @brief Routine to unlock registers that are normally protected
 * @pre   Interrupts must be disabled
 */
/*****************************************************************************/
void BrsHwUnlockInit(void)
{
  volatile uint32 wdtcon0;
  /*
   * 1st step: Password access (create password and send to WDT_CON0)
   */
  wdtcon0 = BRS_SFR_WDTCON0;
  wdtcon0 &= 0xFFFFFF01;     /* clear WDTLCK, WDTHPW0, WDTHPW1 */
  wdtcon0 |= 0xF0;           /* set WDTHPW1 to 0xf */
  wdtcon0 |= 0x01;           /* 1 must be written to ENDINIT for password access
                                (but this will not actually modify the bit)      */
  BRS_SFR_WDTCON0 = wdtcon0; /* modify access to WDTCON0 */
  /*
   * 2nd step: Modify access, set the bit ENDINIT to 1 or 0 to allow access to
   *           registers: WDT_CON1, BTV, BIV, ISP and mod_CLC
   */
  wdtcon0 &= 0xFFFFFFF0;     /* clear WDTHPW0, WDTLCK, ENDINIT  */
  wdtcon0 |= 0x02;           /* WDTHPW0=0, WDTLCK=1, ENDINIT=0 */
  __isync();
  BRS_SFR_WDTCON0 = wdtcon0;
  wdtcon0 = BRS_SFR_WDTCON0; /* read is required */
}

/*****************************************************************************/
/**
 * @brief Routine to lock registers that are normally protected
 * @pre   Interrupts must be disabled
 */
/*****************************************************************************/
void BrsHwLockInit(void)
{
 /* AURIX */
  volatile uint32 wdtcon0;
  /*
   * 1st step: Password access (create password and send to WDT_CON0)
   */
  wdtcon0 = BRS_SFR_WDTCON0;
  wdtcon0 &= 0xFFFFFF01;     /* clear WDTLCK, WDTHPW0, WDTHPW1 */
  wdtcon0 |= 0xF0;           /* set WDTHPW1 to 0xf */
  wdtcon0 |= 0x01;           /* 1 must be written to ENDINIT for password access
                                 (but this will not actually modify the bit) */
  BRS_SFR_WDTCON0 = wdtcon0; /* modify access to WDTCON0 */
  /*
   * 2nd step: Modify access, set the bit ENDINIT to 1 or 0 to allow access to
   *           registers: WDT_CON1, BTV, BIV, ISP and mod_CLC
   */
  wdtcon0 &= 0xFFFFFFF0;     /* clear WDTHPW0, WDTLCK, ENDINIT  */
  wdtcon0 |= 0x03;           /* WDTHPW0=0, WDTLCK=1, ENDINIT=0 */
  __isync();
  BRS_SFR_WDTCON0 = wdtcon0;
  wdtcon0 = BRS_SFR_WDTCON0; /* read is required */
}

