//****************************************************************************
// @Module        Analog Digital Converter 0 (ADC0)
// @Filename      ADC0.c
// @Project       demo1767.dav
//----------------------------------------------------------------------------
// @Controller    Infineon TC1767
//
// @Compiler      Tasking 3.1
//
// @Codegenerator 1.0
//
// @Description   This file contains functions that use the ADC0 module.
//
//----------------------------------------------------------------------------
// @Date          16.12.2010 18:24:58
//
//****************************************************************************

// USER CODE BEGIN (ADC0_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.h"

// USER CODE BEGIN (ADC0_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (ADC0_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (ADC0_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (ADC0_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (ADC0_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (ADC0_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************




// USER CODE BEGIN (ADC0_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (ADC0_General,9)

// USER CODE END


//****************************************************************************
// @Function      void ADC0_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the initialization function of the ADC function 
//                library. It is assumed that the SFRs used by this library 
//                are in their reset state. 
//                
//                Following SFR fields will be initialized:
//                CLC  - Clock Control
//                GLOBCTR  - Global Control
//                GLOBCFG  - Global Configuration
//                RSPR0    - Priority and Arbitration Register 0
//                RSPR4    - Priority and Arbitration Register 4
//                ASENR    - Arbitration slot enable register
//                CHCTRx   - Channel Control Register x
//                RCRx     - Result Control Register x
//                KSCFG    - Module configuration Register
//                INPCR    - Input class Registers
//                CHENPRx  - Channel Interrupt register
//                EVNPRx   - Event Interrupt register
//                RNPRx    - Result Interrupt register
//                SYNCTR   - Synchronisation control register
//                LCBRx    - Limit check boundary register
//                QMR0     - Sequential 0 mode register
//                QMR2     - Sequential 2 mode register
//                QMR4     - Sequential 4 mode register
//                CRMR1    - Parallel mode register 1
//                CRMR3    - Parallel mode register 3
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          16.12.2010
//
//****************************************************************************

// USER CODE BEGIN (ADC0_Init,1)

// USER CODE END

void ADC0_vInit(void)
{
  // USER CODE BEGIN (ADC0_Init, 2); 

  // USER CODE END

  ///  -----------------------------------------------------------------------
  ///  Configuration of ADC0 clock control configuration register:
  ///  -----------------------------------------------------------------------

  ///  - the ADC module is not stopped during sleep mode

  ///  - set run mode 0 for suspend and normal

  ///  - clear DISR

  MAIN_vResetENDINIT();
  ADC0_CLC       =  0x00000034;  // load ADC0 clock control configuration 
                                 // register

  ///  - wait until module is enabled by waiting until bit DISS is cleared 
  ///    (set after reset)

  while((ADC0_CLC & 0x00000002));  //wait until module is enabled

  ///  -----------------------------------------------------------------------
  ///  Configuration of ADC0 kernel configuration register:
  ///  -----------------------------------------------------------------------
  ADC0_KSCFG     =  0x00000880;  // load ADC0 kernel configuration register

  MAIN_vSetENDINIT();

  ///  - the ADC module clock = 66,67 MHz
  ///   

  __nop();  // one cycle delay 

  __nop();  // one cycle delay 

  ///  -----------------------------------------------------------------------
  ///  Configure global control register:
  ///  -----------------------------------------------------------------------
  ///  --- Conversion Timing (for 10 bit resolution) -----------------
  ///  - conversion time (CTC)    = 01,92 us

  ///  _Analog clock is 1/9th of module clock and digital clock is 1/1 times 
  ///  of module clock

  ///  - the permanent arbitration mode is selected
  ADC0_GLOBCTR   =  0x00000408;  // load global control register

  ///  -----------------------------------------------------------------------
  ///  Configure global configuration register:
  ///  -----------------------------------------------------------------------
  ///  - start power up calibration
  ///  - don't disable Post Calibration
  ///  - no mux test mode

  ADC0_GLOBCFG   =  0x00000020;  // load global configuration register

  ///  -----------------------------------------------------------------------
  ///  Configuration of Arbitration Slot enable register and also the Source 
  ///  Priority register:
  ///  -----------------------------------------------------------------------
  ///  - Arbitration Slot 0 is enabled

  ///  - Arbitration Slot 1 is enabled

  ///  - Arbitration Slot 2 is enabled

  ///  - Arbitration Slot 3 is enabled

  ///  - Arbitration Slot 4 is enabled

  ///  - the priority of request source 0 is low
  ///  - the wait-for-start mode is selected for source 0
  ///  - the priority of request source 1 is low
  ///  - the wait-for-start mode is selected for source 1
  ///  - the priority of request source 2 is low
  ///  - the wait-for-start mode is selected for source 2
  ///  - the priority of request source 3 is low
  ///  - the wait-for-start mode is selected for source 3
  ///  - the priority of request source 4 is low
  ///  - the wait-for-start mode is selected for source 4

  ADC0_ASENR     =  0x0000001F;  // load Arbitration Slot enable register

  ADC0_RSPR0     =  0x00000000;  // load Priority and Arbitration register 0

  ADC0_RSPR4     =  0x00000000;  // load Priority and Arbitration register 4

  ///  -----------------------------------------------------------------------
  ///  Configuration of Channel Control Registers:
  ///  -----------------------------------------------------------------------
  ///  Configuration of Channel 0
  ///  - the result register0 is selected
  ///  - the limit check 0 is selected

  ///  - the reference voltage selected is Standard Voltage (Varef)

  ///  - the input class selected is Input Class 0

  ///  - LCBR0 is selected as upper boundary

  ///  - LCBR1 is selected as lower boundary

  ADC0_CHCTR0    =  0x00000004;  // load channel control register

  ///  Configuration of Channel 1
  ///  - the result register1 is selected
  ///  - the limit check 0 is selected

  ///  - the reference voltage selected is Standard Voltage (Varef)

  ///  - the input class selected is Input Class 0

  ///  - LCBR0 is selected as upper boundary

  ///  - LCBR1 is selected as lower boundary

  ADC0_CHCTR1    =  0x00001004;  // load channel control register

  ///  -----------------------------------------------------------------------
  ///  Configuration of Alias Register:
  ///  -----------------------------------------------------------------------

  ADC0_ALR0      =  0x00000100;  // load alias register 0

  ///  -----------------------------------------------------------------------
  ///  Configuration of Sample Time and Resolution:
  ///  -----------------------------------------------------------------------

  ///  10 bit resolution selected

  ADC0_INPCR0    =  0x00000000;  // load input class0 register

  ///  10 bit resolution selected

  ADC0_INPCR1    =  0x00000000;  // load input class1 register

  ///  10 bit resolution selected

  ADC0_INPCR2    =  0x00000000;  // load input class2 register

  ///  10 bit resolution selected

  ADC0_INPCR3    =  0x00000000;  // load input class3 register

  ///  -----------------------------------------------------------------------
  ///  Configuration of Result Control Registers:
  ///  -----------------------------------------------------------------------
  ///  Configuration of Result Control Register 0
  ///  - the data reduction filter is enabled
  ///  - the event interrupt is disabled
  ///  - the wait-for-read mode is disabled

  ///  - the FIFO functionality is disabled

  ADC0_RCR0      =  0x00000000;  // load result control register 0

  ///  Configuration of Result Control Register 1
  ///  - the data reduction filter is enabled
  ///  - the event interrupt is disabled
  ///  - the wait-for-read mode is disabled

  ///  - the FIFO functionality is disabled

  ADC0_RCR1      =  0x00000000;  // load result control register 1

  ///  Configuration of Result Control Register 2
  ///  - the data reduction filter is disabled
  ///  - the event interrupt is disabled
  ///  - the wait-for-read mode is disabled

  ///  - the FIFO functionality is disabled

  ADC0_RCR2      =  0x00000000;  // load result control register 2

  ///  Configuration of Result Control Register 3
  ///  - the data reduction filter is disabled
  ///  - the event interrupt is disabled
  ///  - the wait-for-read mode is disabled

  ///  - the FIFO functionality is disabled

  ADC0_RCR3      =  0x00000000;  // load result control register 3

  ///  Configuration of Result Control Register 4
  ///  - the data reduction filter is disabled
  ///  - the event interrupt is disabled
  ///  - the wait-for-read mode is disabled

  ///  - the FIFO functionality is disabled

  ADC0_RCR4      =  0x00000000;  // load result control register 4

  ///  Configuration of Result Control Register 5
  ///  - the data reduction filter is disabled
  ///  - the event interrupt is disabled
  ///  - the wait-for-read mode is disabled

  ///  - the FIFO functionality is disabled

  ADC0_RCR5      =  0x00000000;  // load result control register 5

  ///  Configuration of Result Control Register 6
  ///  - the data reduction filter is disabled
  ///  - the event interrupt is disabled
  ///  - the wait-for-read mode is disabled

  ///  - the FIFO functionality is disabled

  ADC0_RCR6      =  0x00000000;  // load result control register 6

  ///  Configuration of Result Control Register 7
  ///  - the data reduction filter is disabled
  ///  - the event interrupt is disabled
  ///  - the wait-for-read mode is disabled

  ///  - the FIFO functionality is disabled

  ADC0_RCR7      =  0x00000000;  // load result control register 7

  ///  Configuration of Result Control Register 8
  ///  - the data reduction filter is disabled
  ///  - the event interrupt is disabled
  ///  - the wait-for-read mode is disabled

  ///  - the FIFO functionality is disabled

  ADC0_RCR8      =  0x00000000;  // load result control register 8

  ///  Configuration of Result Control Register 9
  ///  - the data reduction filter is disabled
  ///  - the event interrupt is disabled
  ///  - the wait-for-read mode is disabled

  ///  - the FIFO functionality is disabled

  ADC0_RCR9      =  0x00000000;  // load result control register 9

  ///  Configuration of Result Control Register 10
  ///  - the data reduction filter is disabled
  ///  - the event interrupt is disabled
  ///  - the wait-for-read mode is disabled

  ///  - the FIFO functionality is disabled

  ADC0_RCR10     =  0x00000000;  // load result control register 10

  ///  Configuration of Result Control Register 11
  ///  - the data reduction filter is disabled
  ///  - the event interrupt is disabled
  ///  - the wait-for-read mode is disabled

  ///  - the FIFO functionality is disabled

  ADC0_RCR11     =  0x00000000;  // load result control register 11

  ///  Configuration of Result Control Register 12
  ///  - the data reduction filter is disabled
  ///  - the event interrupt is disabled
  ///  - the wait-for-read mode is disabled

  ///  - the FIFO functionality is disabled

  ADC0_RCR12     =  0x00000000;  // load result control register 12

  ///  Configuration of Result Control Register 13
  ///  - the data reduction filter is disabled
  ///  - the event interrupt is disabled
  ///  - the wait-for-read mode is disabled

  ///  - the FIFO functionality is disabled

  ADC0_RCR13     =  0x00000000;  // load result control register 13

  ///  Configuration of Result Control Register 14
  ///  - the data reduction filter is disabled
  ///  - the event interrupt is disabled
  ///  - the wait-for-read mode is disabled

  ///  - the FIFO functionality is disabled

  ADC0_RCR14     =  0x00000000;  // load result control register 14

  ///  Configuration of Result Control Register 15
  ///  - the data reduction filter is disabled
  ///  - the event interrupt is disabled
  ///  - the wait-for-read mode is disabled

  ///  - the FIFO functionality is disabled

  ADC0_RCR15     =  0x00000000;  // load result control register 15

  ///  -----------------------------------------------------------------------
  ///  Configuration of Channel Interrupt Node Pointer Register:
  ///  -----------------------------------------------------------------------
  ///  - the SR0 line become activated if channel 0 interrupt is generated

  ///  - the SR0 line become activated if channel 1 interrupt is generated

  ADC0_CHENPR0   =  0x00000000;  // load channel interrupt node pointer 
                                 // register 0

  ADC0_CHENPR8   =  0x00000000;  // load channel interrupt node pointer 
                                 // register 8

  ///  -----------------------------------------------------------------------
  ///  Configuration of Event Interrupt Node Pointer Register for Source 
  ///  Interrupts:
  ///  -----------------------------------------------------------------------
  ///  - the SR 0 line become activated if the event 0 interrupt is generated
  ///  - the SR 0 line become activated if the event 1 interrupt is generated
  ///  - the SR 0 line become activated if the event 2 interrupt is generated
  ///  - the SR 0 line become activated if the event 3 interrupt is generated
  ///  - the SR 0 line become activated if the event 4 interrupt is generated

  ADC0_EVNPR     =  0x00000000;  // load event interrupt set flag register 

  ///  -----------------------------------------------------------------------
  ///  Configuration of Event Interrupt Node Pointer Register for Result 
  ///  Interrupts:
  ///  -----------------------------------------------------------------------

  ADC0_RNPR0     =  0x00000000;  // load event interrupt set flag register 


  ADC0_RNPR8     =  0x00000000;  // load event interrupt set flag register 

  ///  -----------------------------------------------------------------------
  ///  Configuration of Service Request Nodes 0 - 7 :
  ///  -----------------------------------------------------------------------


  ///  -----------------------------------------------------------------------
  ///  Configuration of Limit Check Boundary:
  ///  -----------------------------------------------------------------------

  ADC0_LCBR0     =  0x00000198;  // load limit check boundary register 0

  ADC0_LCBR1     =  0x00000E64;  // load limit check boundary register 1

  ADC0_LCBR2     =  0x00000554;  // load limit check boundary register 2

  ADC0_LCBR3     =  0x00000AA8;  // load limit check boundary register 3

  ///  -----------------------------------------------------------------------
  ///  Configuration of Gating source and External Trigger Control:
  ///  -----------------------------------------------------------------------
  ///  - No Gating source selected for Arbitration Source 0

  ///  - the trigger input selection is not enabled for source 0

  ADC0_RSIR0     =  0x00000000;  // load external trigger control register 
                                 // for Request Source 0

  ///  - No Gating source selected for Arbitration Source 1

  ///  - the trigger input TRSEL selection is not enabled for Source 1

  ADC0_RSIR1     =  0x00000000;  // load external trigger control register 
                                 // for Request Source 1

  ///  - No Gating source selected for Arbitration Source 2

  ///  - the trigger input TRSEL selection is not enabled for Source 2

  ADC0_RSIR2     =  0x00000000;  // load external trigger control register 
                                 // for Request Source 2

  ///  - No Gating source selected for Arbitration Source 3

  ///  - the trigger input TRSEL selection is not enabled for Source 3

  ADC0_RSIR3     =  0x00000000;  // load external trigger control register 
                                 // for Request Source 3

  ///  - No Gating source selected for Arbitration Source 2

  ///  - the trigger input TRSEL selection is not enabled for Source 4

  ADC0_RSIR4     =  0x00000000;  // load external trigger control register 
                                 // for Request Source 4

  ///  -----------------------------------------------------------------------
  ///  Configuration of Conversion Queue Mode Register:Sequential Source 0
  ///  -----------------------------------------------------------------------
  ///  - the gating line is permanently Enabled
  ///  - the external trigger is disabled

  ADC0_QMR0      =  0x00000001;  // load queue mode register

  ///  -----------------------------------------------------------------------
  ///  Configuration of Conversion Queue Mode Register:Sequential Source 2
  ///  -----------------------------------------------------------------------
  ///  - the gating line is permanently Enabled
  ///  - the external trigger is disabled

  ADC0_QMR2      =  0x00000001;  // load queue mode register

  ///  -----------------------------------------------------------------------
  ///  Configuration of Conversion Queue Mode Register:Sequential Source 4
  ///  -----------------------------------------------------------------------
  ///  - the gating line is permanently Enabled
  ///  - the external trigger is disabled

  ADC0_QMR4      =  0x00000001;  // load queue mode register

  ///  -----------------------------------------------------------------------
  ///  Configuration of Conversion Request Mode Registers:Parallel Source 
  ///  -----------------------------------------------------------------------
  ///  - the gating line is permanently Enabled
  ///  - the external trigger is disabled
  ///  - the source interrupt is disabled
  ///  - the autoscan functionality is disabled

  ADC0_CRMR1     =  0x00000001;  // load conversion request mode register 1

  ///  -----------------------------------------------------------------------
  ///  Configuration of Conversion Request Mode Registers:Parallel Source 3
  ///  -----------------------------------------------------------------------
  ///  - the gating line is permanently Enabled
  ///  - the external trigger is disabled
  ///  - the source interrupt is disabled
  ///  - the autoscan functionality is disabled

  ADC0_CRMR3     =  0x00000001;  // load conversion request mode register 3

  ///  -----------------------------------------------------------------------
  ///  Configuration of Synchronisation Registers:
  ///  -----------------------------------------------------------------------
  ///  - ADC0 is master of ADC1 only 
  ADC0_SYNCTR   |=  0x00000010;  // Synchronisation register

  ///  -----------------------------------------------------------------------
  ///  Wait for calibration to finish (CAL=0)
  ///  -----------------------------------------------------------------------

  while((ADC0_GLOBSTR & 0x0004));  //wait for calibration to finish (CAL=0)

  ADC0_GLOBCTR  |=  0x00000300;  // turn on Analog part for ADC0 kernel

  // USER CODE BEGIN (ADC0_Init,3)

  // USER CODE END

} //  End of function ADC0_vInit


//****************************************************************************
// @Function      void ADC0_vStartSeq0ReqChNum(ubyte ubExtTrg, ubyte ubEnIntr, ubyte ubRFill, ubyte ubChannelNum) 
//
//----------------------------------------------------------------------------
// @Description   This function starts the conversion of the requested 
//                channel.
//                NOTE -
//                Before passing ubEnIntr argument as 1,make sure that Seq 0 
//                source interrupt is enabled.
//                External Trigger -> 0,Indicates software trigger 
//                (Conversion starts once this function is executed)
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    ubExtTrg: 
//                External Trigger : defines external trigger.
// @Parameters    ubEnIntr: 
//                Enable Source Interrupt : defines source interrupt
// @Parameters    ubRFill: 
//                Refill : defines the refill (1 for enable,0 for disable)
// @Parameters    ubChannelNum: 
//                Channel number : Name of the Request Channel Number (0 - 
//                15)- see macros defined in the header file
//
//----------------------------------------------------------------------------
// @Date          16.12.2010
//
//****************************************************************************

void ADC0_vStartSeq0ReqChNum(ubyte ubExtTrg, ubyte ubEnIntr, ubyte ubRFill, ubyte ubChannelNum)
{

    uword uwVal = 0;
    if (ubExtTrg == 1)
    {
        uwVal = 0x00000080;
    }
    if (ubEnIntr == 1)
    {
        uwVal = uwVal + 0x00000040;
    }
    if (ubRFill == 1)
    {
        uwVal = uwVal + 0x00000020;
    }
    uwVal = uwVal + (ubChannelNum & 0x0000000f);

   ADC0_QINR0 = uwVal; // requested channel 

} //  End of function ADC0_vStartSeq0ReqChNum




// USER CODE BEGIN (ADC0_General,10)

// USER CODE END

