#include "AppPT2000.h"
#include "PT2000.h"
#include "MCAL\Mcal\Tricore\Spi\ssc\inc/Spi.h"
#include "system.h"
#include "MCAL\Mcal\Tricore\Dio\ssc\inc/Dio.h"
#include "lpspi.h"
#include "Com_Cfg.h"
#include "Com.h"
#include "Rte_CtPT2000_Handler.h"


#define PT2000_Enable      1
#define PT2000_Disable     0

Channel channel;
Channel channel_get_value = {{0}};
Channel channel_judge = {{0}};
Chip_Select m_Chip_Select = {{0}};
ValveParam ValveParamCH;
extern VlvActFL Write_PpVelFbAll_VlvFL;
extern VlvActFR Write_PpVelFbAll_VlvFR;
extern VlvActRL Write_PpVelFbAll_VlvRL;
extern VlvActRR Write_PpVelFbAll_VlvRR;

uint8 B_current_change = 0;
uint8 B_Value_State_change = 0;

extern uint16 Timer_coda ;


uint8 x = 1;
uint8 y = 1;


uint16 Mode_Change_Time_code = 0;



uint16 current_demarcate(uint16 current);
void initValveParamConfig(ValveParam *m_ValveParam, Channel_Number Ch_Number, Enum_Mode mode);

void initValveParam(Enum_Mode mode);
void ParamMap(uint8 csindex);
void SendCmd_EnChannel(void);
void Set_StartPin_State(Channel_Number Ch_Number, boolean state);
void Download_Pt2000(Enum_Mode mode);

void Set_Peak_Hold(uint8 ChannelID, uint16 iboostB, uint16 tbias_tot, uint16 tbias_off, uint16 ibias, uint16 iboostP,
                    uint16 tpeak_tot, uint16 tpeak_off, uint16 ipeak, uint16 tbypass, uint16 thold_tot, uint16 thold_off,
                    uint16 ihold, uint16 fwtimeOFF);
void Set_ConstantCurrent(uint8 ChannelID, uint16 iboostB, uint16 tbias_tot, uint16 tbias_off, uint16 ibias, uint16 iboostP,
        uint16 tpeak_tot, uint16 tpeak_off, uint16 ipeak, uint16 tbypass, uint16 thold_tot, uint16 thold_off,
        uint16 ihold, uint16 fwtimeOFF);

uint16 iii = 0;

//电磁阀诊断函数
void  valve_diag()
{

    if(Timer_coda >= 300)
    {
        if(Timer_coda % 10 == 1)
        {
            x = 1;
            y = 1;

            ProcessPT2000Interrupts();

            //Valve1  VlvFLDiagSts1
            if( HS1 != 0 || HS2 != 0 || LS2 != 0 )
            {
            	Write_PpVelFbAll_VlvFL.VlvFLDiagSts1 = HS1+ (HS2 << 2)+(LS2 << 5) ;
            }

            //Valve2
            if( HS3 != 0 || HS4 != 0 || LS4 != 0 )
            {
             Write_PpVelFbAll_VlvFL.VlvFLDiagSts2 =  HS3+ (HS4<< 2)+(LS4 << 5);

            }

            //Valve3
            if( HS5 != 0 || HS6 != 0 || LS6 != 0 )
            {
             Write_PpVelFbAll_VlvFR .VlvFRDiagSts1= HS5+ ( HS6 << 2)+(LS6 << 5);

            }

           //Send diagnostic information throug CAN
            if( HS1 != 0 || HS2 != 0 || HS3 != 0 || HS4 != 0 || HS5 != 0 || HS6 != 0 ||
                         HS7 != 0 || LS2 != 0 || LS4 != 0 || LS6 != 0 || LS7 != 0)
            {
                 Com_SendSignal(ComConf_ComSignal_Sig_PT1_Valve1_HS1_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_dc7f0e1c_Tx,&HS1);
                 Com_SendSignal(ComConf_ComSignal_Sig_PT1_Valve1_HS2_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_f6c3be94_Tx,&HS2);
                 Com_SendSignal(ComConf_ComSignal_Sig_PT1_Valve2_HS3_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_27ff6475_Tx,&HS3);
                 Com_SendSignal(ComConf_ComSignal_Sig_PT1_Valve2_HS4_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_ddc29722_Tx,&HS4);
                 Com_SendSignal(ComConf_ComSignal_Sig_PT1_Valve3_HS5_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_58ae3d07_Tx,&HS5);
                 Com_SendSignal(ComConf_ComSignal_Sig_PT1_Valve3_HS6_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_72128d8f_Tx,&HS6);
                 Com_SendSignal(ComConf_ComSignal_Sig_PT1_DCDC_HS7_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_aa37a69c_Tx,&HS7);
                 Com_SendSignal(ComConf_ComSignal_Sig_PT1_Valve1_LS2_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_1fb6a7ef_Tx,&LS2);
                 Com_SendSignal(ComConf_ComSignal_Sig_PT1_Valve2_LS4_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_34b78e59_Tx,&LS4);
                 Com_SendSignal(ComConf_ComSignal_Sig_PT1_Valve3_LS6_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_9b6794f4_Tx,&LS6);
                 Com_SendSignal(ComConf_ComSignal_Sig_PT1_DCDC_LS7_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_4342bfe7_Tx,&HS7);

            }


        }

        // Chip 2

        if(Timer_coda % 10 == 2)
        {
            x = 2;
            y = 2;
            ProcessPT2000Interrupts();

            //Valve4
            if( HS1 != 0 || HS2 != 0 || LS2 != 0 )
            {
             Write_PpVelFbAll_VlvFR .VlvFRDiagSts2 =	HS1+ (HS2 << 2)+(LS2 << 5);

            }

            //Valve5
            if( HS3 != 0 || HS4 != 0 || LS4 != 0 )
            {
            	Write_PpVelFbAll_VlvRL .VlvRLDiagSts1 =	HS3+ (HS4<< 2)+(LS4 << 5);

            }

            //Valve6
            if( HS5 != 0 || HS6 != 0 || LS6 != 0 )
            {
            	Write_PpVelFbAll_VlvRL .VlvRLDiagSts2 =  HS5+ ( HS6 << 2)+(LS6 << 5);

            }

            if( HS1 != 0 || HS2 != 0 || HS3 != 0 || HS4 != 0 || HS5 != 0 || HS6 != 0 ||
                           HS7 != 0 || LS2 != 0 || LS4 != 0 || LS6 != 0 || LS7 != 0)
            {
                   Com_SendSignal(ComConf_ComSignal_Sig_PT2_Valve4_HS1_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_ad20fc3f_Tx,&HS1);
                   Com_SendSignal(ComConf_ComSignal_Sig_PT2_Valve4_HS2_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_879c4cb7_Tx,&HS2);
                   Com_SendSignal(ComConf_ComSignal_Sig_PT2_Valve5_HS3_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_02f0e692_Tx,&HS3);
                   Com_SendSignal(ComConf_ComSignal_Sig_PT2_Valve5_HS4_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_f8cd15c5_Tx,&HS4);
                   Com_SendSignal(ComConf_ComSignal_Sig_PT2_Valve6_HS5_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_29f1cf24_Tx,&HS5);
                   Com_SendSignal(ComConf_ComSignal_Sig_PT2_Valve6_HS6_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_034d7fac_Tx,&HS6);
                   Com_SendSignal(ComConf_ComSignal_Sig_PT2_DCDC_HS7_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_964be8d5_Tx,&HS7);
                   Com_SendSignal(ComConf_ComSignal_Sig_PT2_Valve4_LS2_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_6ee955cc_Tx,&LS2);
                   Com_SendSignal(ComConf_ComSignal_Sig_PT2_Valve5_LS4_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_11b80cbe_Tx,&LS4);
                   Com_SendSignal(ComConf_ComSignal_Sig_PT2_Valve6_LS6_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_ea3866d7_Tx,&LS6);
                   Com_SendSignal(ComConf_ComSignal_Sig_PT2_DCDC_LS7_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_7f3ef1ae_Tx,&HS7);

            }

        }
    }
    // Chip 3
    if(Timer_coda % 10 == 3)
    {
        x = 3;
        y = 3;
        ProcessPT2000Interrupts();

        //Valve7
        if( HS1 != 0 || HS2 != 0 || LS2 != 0 )
        {
         Write_PpVelFbAll_VlvRR.VlvRRDiagSts1 =  HS1+ (HS2 << 2)+(LS2 << 5);

        }

        //Valve8
        if( HS3 != 0 || HS4 != 0 || LS4 != 0 )
        {
         Write_PpVelFbAll_VlvRR.VlvRRDiagSts1 =   HS3+ (HS4<< 2)+(LS4 << 5);

        }

        //Valve9
        if( HS5 != 0 || HS6 != 0 || LS6 != 0 )
        {
//          HS5+ ( HS6 << 2)+(LS6 << 5)

        }


        if( HS1 != 0 || HS2 != 0 || HS3 != 0 || HS4 != 0 || HS5 != 0 || HS6 != 0 ||
                       HS7 != 0 || LS2 != 0 || LS4 != 0 || LS6 != 0 || LS7 != 0)
        {
               Com_SendSignal(ComConf_ComSignal_Sig_PT3_Valve7_HS1_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_8215adde_Tx,&HS1);
               Com_SendSignal(ComConf_ComSignal_Sig_PT3_Valve7_HS2_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_a8a91d56_Tx,&HS2);
               Com_SendSignal(ComConf_ComSignal_Sig_PT3_Valve8_HS3_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_5b05e36e_Tx,&HS3);
               Com_SendSignal(ComConf_ComSignal_Sig_PT3_Valve8_HS4_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_a1381039_Tx,&HS4);
               Com_SendSignal(ComConf_ComSignal_Sig_PT3_Valve9_HS5_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_2454ba1c_Tx,&HS5);
               Com_SendSignal(ComConf_ComSignal_Sig_PT3_Valve9_HS6_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_0ee80a94_Tx,&HS6);
               Com_SendSignal(ComConf_ComSignal_Sig_PT3_DCDC_HS7_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_82602d12_Tx,&HS7);
               Com_SendSignal(ComConf_ComSignal_Sig_PT3_Valve7_LS2_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_41dc042d_Tx,&LS2);
               Com_SendSignal(ComConf_ComSignal_Sig_PT3_Valve8_LS4_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_484d0942_Tx,&LS4);
               Com_SendSignal(ComConf_ComSignal_Sig_PT3_Valve9_LS6_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_e79d13ef_Tx,&LS6);
               Com_SendSignal(ComConf_ComSignal_Sig_PT3_DCDC_LS7_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_6b153469_Tx,&HS7);

        }


    }
//    Chip 4
    if(Timer_coda % 10 == 4)
    {
        x = 4;
        y = 4;
        ProcessPT2000Interrupts();

        //Valve10
        if( HS1 != 0 || HS2 != 0 || LS2 != 0 )
        {
//          HS1+ (HS2 << 2)+(LS2 << 5)

        }

        //Valve11
        if( HS3 != 0 || HS4 != 0 || LS4 != 0 )
        {
//          HS3+ (HS4<< 2)+(LS4 << 5)

        }

        //Valve12
        if( HS5 != 0 || HS6 != 0 || LS6 != 0 )
        {
//          HS5+ ( HS6 << 2)+(LS6 << 5)

        }


        if( HS1 != 0 || HS2 != 0 || HS3 != 0 || HS4 != 0 || HS5 != 0 || HS6 != 0 ||
                       HS7 != 0 || LS2 != 0 || LS4 != 0 || LS6 != 0 || LS7 != 0)
        {

               Com_SendSignal(ComConf_ComSignal_Sig_PT4_Valve10_HS1_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_3529bf8d_Tx,&HS1);
               Com_SendSignal(ComConf_ComSignal_Sig_PT4_Valve10_HS2_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_1f950f05_Tx,&HS2);
               Com_SendSignal(ComConf_ComSignal_Sig_PT4_Valve11_HS3_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_9af9a520_Tx,&HS3);
               Com_SendSignal(ComConf_ComSignal_Sig_PT4_Valve11_HS4_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_60c45677_Tx,&HS4);
               Com_SendSignal(ComConf_ComSignal_Sig_PT4_Valve12_HS5_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_b1f88c96_Tx,&HS5);
               Com_SendSignal(ComConf_ComSignal_Sig_PT4_Valve12_HS6_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_9b443c1e_Tx,&HS6);
               Com_SendSignal(ComConf_ComSignal_Sig_PT4_DCDC_HS7_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_eeb37447_Tx,&HS7);
               Com_SendSignal(ComConf_ComSignal_Sig_PT4_Valve10_LS2_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_f6e0167e_Tx,&LS2);
               Com_SendSignal(ComConf_ComSignal_Sig_PT4_Valve11_LS4_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_89b14f0c_Tx,&LS4);
               Com_SendSignal(ComConf_ComSignal_Sig_PT4_Valve12_LS6_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_72312565_Tx,&LS6);
               Com_SendSignal(ComConf_ComSignal_Sig_PT4_DCDC_LS7_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_07c66d3c_Tx,&HS7);
        }


    }
    // Chip 5
    if(Timer_coda % 10 == 5)
    {
        x = 5;
        y = 5;
        ProcessPT2000Interrupts();





        //Valve14
        if( HS3 != 0 || HS4 != 0 || LS4 != 0 )
        {
//          HS3+ (HS4<< 2)+(LS4 << 5)

        }

        //Valve15
        if( HS5 != 0 || HS6 != 0 || LS6 != 0 )
        {
//          HS5+ ( HS6 << 2)+(LS6 << 5)

        }


        if(  HS3 != 0 || HS4 != 0 || HS5 != 0 || HS6 != 0 ||
                       HS7 != 0 || LS4 != 0 || LS6 != 0 || LS7 != 0)
        {

               Com_SendSignal(ComConf_ComSignal_Sig_PT5_Valve14_HS3_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_eace6a13_Tx,&HS3);
               Com_SendSignal(ComConf_ComSignal_Sig_PT5_Valve14_HS4_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_10f39944_Tx,&HS4);
               Com_SendSignal(ComConf_ComSignal_Sig_PT5_Valve15_HS5_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_959f3361_Tx,&HS5);
               Com_SendSignal(ComConf_ComSignal_Sig_PT5_Valve15_HS6_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_bf2383e9_Tx,&HS6);
               Com_SendSignal(ComConf_ComSignal_Sig_PT5_DCDC_HS7_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_fa98b180_Tx,&HS7);
               Com_SendSignal(ComConf_ComSignal_Sig_PT5_Valve14_LS4_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_f986803f_Tx,&LS4);
               Com_SendSignal(ComConf_ComSignal_Sig_PT5_Valve15_LS6_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_56569a92_Tx,&LS6);
               Com_SendSignal(ComConf_ComSignal_Sig_PT5_DCDC_LS7_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_13eda8fb_Tx,&HS7);
        }

    }
 // Chip 6
    if(Timer_coda % 10 == 6)
    {
        x = 6;
        y = 6;
        ProcessPT2000Interrupts();



        //Valve13
        if( HS3 != 0 || HS4 != 0 || LS4 != 0 )
        {
//          HS3+ ( HS4 << 2)+( LS4 << 5 )
        }

        //Valve16
        if( HS5 != 0 || HS6 != 0 || LS6 != 0 )
        {
//          HS5+ ( HS6 << 2)+(LS6 << 5)

        }

    }

    if(  HS3 != 0 || HS4 != 0 || HS5 != 0 || HS6 != 0 ||
                   HS7 != 0 || LS4 != 0 || LS6 != 0 || LS7 != 0)
    {
           Com_SendSignal(ComConf_ComSignal_Sig_PT5_Valve13_HS1_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_b9eee1f2_Tx,&HS3);
           Com_SendSignal(ComConf_ComSignal_Sig_PT5_Valve13_HS1_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_b9eee1f2_Tx,&HS4);
           Com_SendSignal(ComConf_ComSignal_Sig_PT6_Valve16_HS1_oMSG_PTDriver_06_oSchaeffler_MDA_CANFD_f7d60532_Tx,&HS5);
           Com_SendSignal(ComConf_ComSignal_Sig_PT6_Valve16_HS2_oMSG_PTDriver_06_oSchaeffler_MDA_CANFD_dd6ab5ba_Tx,&HS6);
           Com_SendSignal(ComConf_ComSignal_Sig_PT6_DCDC_HS7_oMSG_PTDriver_06_oSchaeffler_MDA_CANFD_c6e4ffc9_Tx,&HS7);
           Com_SendSignal(ComConf_ComSignal_Sig_PT5_Valve13_LS2_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_7a274801_Tx,&LS4);
           Com_SendSignal(ComConf_ComSignal_Sig_PT6_Valve16_LS2_oMSG_PTDriver_06_oSchaeffler_MDA_CANFD_341facc1_Tx,&LS6);
           Com_SendSignal(ComConf_ComSignal_Sig_PT6_DCDC_LS7_oMSG_PTDriver_06_oSchaeffler_MDA_CANFD_2f91e6b2_Tx,&HS7);

    }

}

// 电流更改赋值
void current_demarcate_valve_choice(uint8 valve_number,uint16 current)
{
	switch(valve_number)
	{
	    case 1:

			 channel.Channel_1.Ipeak = current_demarcate(current);
			 break;
		case 2:

			 channel.Channel_2.Ipeak = current_demarcate(current);
			 break;
		case 3:

			 channel.Channel_3.Ipeak = current_demarcate(current);
			 break;
		case 4:

			 channel.Channel_4.Ipeak = current_demarcate(current);
			 break;
		case 5:

			 channel.Channel_5.Ipeak = current_demarcate(current);
			 break;
		case 6:

			 channel.Channel_6.Ipeak = current_demarcate(current);
			 break;
		case 7:

			 channel.Channel_7.Ipeak = current_demarcate(current);
			 break;
		case 8:

			 channel.Channel_8.Ipeak = current_demarcate(current);
			 break;
		case 9:

			 channel.Channel_9.Ipeak = current_demarcate(current);
			 break;
		case 10:

			 channel.Channel_10.Ipeak = current_demarcate(current);
			 break;
		case 11:

			 channel.Channel_11.Ipeak = current_demarcate(current);
			 break;
		case 12:

			 channel.Channel_12.Ipeak = current_demarcate(current);
			 break;
		case 13:

			 channel.Channel_13.Ipeak = current_demarcate(current);
			 break;
		case 14:

			 channel.Channel_14.Ipeak = current_demarcate(current);
			 break;
		case 15:

			 channel.Channel_15.Ipeak = current_demarcate(current);

			 break;
		case 16:

			 channel.Channel_16.Ipeak = current_demarcate(current);

			 break;
        default:
             break ;


	}
}

// 电流标定（0-6A）
uint16 current_demarcate(uint16 current)
{
    switch(current){
                case 0:

            	return 29;

                case 100:

                	return 29;

                case 200:

                	return 33;

                case 300:

                	return 36;

                case 400:

                	return 39;

                case 500:

                	return 42;

                case 600:

                	return 45;

                case 700:

                	return 48;

                case 800:

                	return 51;

                case 900:

                	return 54;

                case 1000:

                	return 57;

                case 1100:

                	return 60;

                case 1200:

                	return 63;

                case 1300:

                	return 66;

                case 1400:

                	return 69;

                case 1500:

                	return 72;

                case 1600:

                	return 75;

                case 1700:

                	return 78;

                case 1800:

                	return 81;

                case 1900:

                	return 84;

                case 2000:

                	return 87;
//
//                case 2100:

//                	return
//
//                case 2200:

//                	return

//                case 2300:

//                	return
//
//                case 2400:

//                	return
//
//                case 2500:

//                	return
//
//                case 2600:

//                	return
//
//                case 2700:

//                	return

//                case 2800:

//                	return

//                case 2900:

//                	return

//                case 3000:

//                	return

//                case 3100:

//                	return

//                case 3200:

//                	return

//                case 3300:

//                	return

//                case 3400:

//                	return

//                case 3500:

//                	return

//                case 3600:

//                	return

//                case 3700:

//                	return

//                case 3800:

//                	return

//                case 3900:

//                	return

//                case 4000:

//                	return

//                case 4100:

//                	return
//
//                  case 4200:

//                	return

//                  case 4300:

//                	return

//                  case 4400:

//                	return

//                  case 4500:

//                	return

//                  case 4600:

//                	return

//                  case 4700:

//                	return

//                  case 4800:

//                	return

//                  case 4900:

//                	return

//                  case 5000:

//                	return

//                  case 5100:

//                	return

//                  case 5200:

//                	return

//                  case 5300:

//                	return

//                  case 5400:

//                	return

//                  case 5500:

//                	return

//                  case 5600:

//                	return

//                  case 5700:

//                	return

//                  case 5800:

//                	return

//                  case 5900:

//                	return

//                  case 6000:

//                	return

                default:
                   return 0;
}
}


// CAN 接受
void GET_Valve_Value(void)
{

    if(Timer_coda >= 300)
    {


		  Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve1_MDAswitchPC_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_6ab83b1c_Rx,&channel_get_value.Channel_1.PC_Change);
		  Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve2_MDAswitchPC_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_9a0ad560_Rx,&channel_get_value.Channel_2.PC_Change);
		  Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve3_MDAswitchPC_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_7cb4728b_Rx,&channel_get_value.Channel_3.PC_Change);
		  Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve4_MDAswitchPC_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_a01e0fd9_Rx,&channel_get_value.Channel_4.PC_Change);
		  Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve5_MDAswitchPC_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_46a0a832_Rx,&channel_get_value.Channel_5.PC_Change);
		  Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve6_MDAswitchPC_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_b612464e_Rx,&channel_get_value.Channel_6.PC_Change);
		  Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve7_MDAswitchPC_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_50ace1a5_Rx,&channel_get_value.Channel_7.PC_Change);
		  Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve8_MDAswitchPC_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_d437baab_Rx,&channel_get_value.Channel_8.PC_Change);
		  Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve9_MDAswitchPC_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_32891d40_Rx,&channel_get_value.Channel_9.PC_Change);
		  Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve10_MDAswitchPC_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_18c8890a_Rx,&channel_get_value.Channel_10.PC_Change);
		  Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve11_MDAswitchPC_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_fe762ee1_Rx,&channel_get_value.Channel_11.PC_Change);
		  Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve12_MDAswitchPC_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_0ec4c09d_Rx,&channel_get_value.Channel_12.PC_Change);
		  Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve13_MDAswitchPC_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_e87a6776_Rx,&channel_get_value.Channel_13.PC_Change);
		  Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve14_MDAswitchPC_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_34d01a24_Rx,&channel_get_value.Channel_14.PC_Change);
		  Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve15_MDAswitchPC_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_d26ebdcf_Rx,&channel_get_value.Channel_15.PC_Change);
		  Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve16_MDAswitchPC_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_22dc53b3_Rx,&channel_get_value.Channel_16.PC_Change);


           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve1_FWtimeOFF0_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_cdb96a4e_Rx,&channel_get_value.Channel_1.FWtimeOFF);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve1_Ibias_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_16ed333d_Rx,&channel_get_value.Channel_1.Ibias);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve1_IboostB_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_c914d65f_Rx,&channel_get_value.Channel_1.IboostB);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve1_IboostP_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_946a5245_Rx,&channel_get_value.Channel_1.IboostP);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve1_Ihold_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_6df9b71a_Rx,&channel_get_value.Channel_1.Ihold);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve1_Ipeak_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_af0de4c2_Rx,&channel_get_value.Channel_1.Ipeak);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve1_Tbias_off_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_275b00ec_Rx,&channel_get_value.Channel_1.Tbias_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve1_Tbias_tot_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_733ed7db_Rx,&channel_get_value.Channel_1.Tbias_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve1_Tbypass_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_21bc9bdf_Rx,&channel_get_value.Channel_1.Tbypass);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve1_Thold_off_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_15fb5bd6_Rx,&channel_get_value.Channel_1.Thold_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve1_Thold_tot_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_419e8ce1_Rx,&channel_get_value.Channel_1.Thold_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve1_Tpeak_off_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_9d5bdd6c_Rx,&channel_get_value.Channel_1.Tpeak_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve1_Tpeak_tot_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_c93e0a5b_Rx,&channel_get_value.Channel_1.Tpeak_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve1_Mode_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_87ad547b_Rx,&channel_get_value.Channel_1.Mode);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve1_State_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_93106638_Rx,&channel_get_value.Channel_1.State);




           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve2_FWtimeOFF0_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_3f59c6a3_Rx,&channel_get_value.Channel_2.FWtimeOFF);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve2_Ibias_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_060cdf30_Rx,&channel_get_value.Channel_2.Ibias);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve2_IboostB_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_960e99ce_Rx,&channel_get_value.Channel_2.IboostB);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve2_IboostP_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_cb701dd4_Rx,&channel_get_value.Channel_2.IboostP);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve2_Ihold_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_7d185b17_Rx,&channel_get_value.Channel_2.Ihold);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve2_Ipeak_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_bfec08cf_Rx,&channel_get_value.Channel_2.Ipeak);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve2_Tbias_off_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_ea6a37c2_Rx,&channel_get_value.Channel_2.Tbias_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve2_Tbias_tot_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_be0fe0f5_Rx,&channel_get_value.Channel_2.Tbias_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve2_Tbypass_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_7ea6d44e_Rx,&channel_get_value.Channel_2.Tbypass);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve2_Thold_off_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_d8ca6cf8_Rx,&channel_get_value.Channel_2.Thold_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve2_Thold_tot_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_8cafbbcf_Rx,&channel_get_value.Channel_2.Thold_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve2_Tpeak_off_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_506aea42_Rx,&channel_get_value.Channel_2.Tpeak_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve2_Tpeak_tot_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_040f3d75_Rx,&channel_get_value.Channel_2.Tpeak_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve2_Mode_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f3a6979c_Rx,&channel_get_value.Channel_2.Mode);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve2_State_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_83f18a35_Rx,&channel_get_value.Channel_2.State);


           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve3_FWtimeOFF0_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6ef9a2f8_Rx,&channel_get_value.Channel_3.FWtimeOFF);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve3_Ibias_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_bf7c86f4_Rx,&channel_get_value.Channel_3.Ibias);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve3_IboostB_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_15d7a17e_Rx,&channel_get_value.Channel_3.IboostB);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve3_IboostP_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_48a92564_Rx,&channel_get_value.Channel_3.IboostP);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve3_Ihold_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_c46802d3_Rx,&channel_get_value.Channel_3.Ihold);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve3_Ipeak_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_069c510b_Rx,&channel_get_value.Channel_3.Ipeak);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve3_Tbias_off_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_1855d8e7_Rx,&channel_get_value.Channel_3.Tbias_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve3_Tbias_tot_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_4c300fd0_Rx,&channel_get_value.Channel_3.Tbias_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve3_Tbypass_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_fd7fecfe_Rx,&channel_get_value.Channel_3.Tbypass);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve3_Thold_off_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_2af583dd_Rx,&channel_get_value.Channel_3.Thold_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve3_Thold_tot_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_7e9054ea_Rx,&channel_get_value.Channel_3.Thold_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve3_Tpeak_off_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_a2550567_Rx,&channel_get_value.Channel_3.Tpeak_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve3_Tpeak_tot_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_f630d250_Rx,&channel_get_value.Channel_3.Tpeak_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve3_Mode_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6970d4fe_Rx,&channel_get_value.Channel_3.Mode);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve3_State_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_3a81d3f1_Rx,&channel_get_value.Channel_3.State);


           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve4_FWtimeOFF0_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_01e99938_Rx,&channel_get_value.Channel_4.FWtimeOFF);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve4_Ibias_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_27cf072a_Rx,&channel_get_value.Channel_4.Ibias);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve4_IboostB_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_283a06ec_Rx,&channel_get_value.Channel_4.IboostB);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve4_IboostP_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_754482f6_Rx,&channel_get_value.Channel_4.IboostP);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve4_Ihold_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_5cdb830d_Rx,&channel_get_value.Channel_4.Ihold);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve4_Ipeak_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_9e2fd0d5_Rx,&channel_get_value.Channel_4.Ipeak);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve4_Tbias_off_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_ab795fdf_Rx,&channel_get_value.Channel_4.Tbias_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve4_Tbias_tot_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_ff1c88e8_Rx,&channel_get_value.Channel_4.Tbias_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve4_Tbypass_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_c0924b6c_Rx,&channel_get_value.Channel_4.Tbypass);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve4_Thold_off_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_99d904e5_Rx,&channel_get_value.Channel_4.Thold_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve4_Thold_tot_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_cdbcd3d2_Rx,&channel_get_value.Channel_4.Thold_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve4_Tpeak_off_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_1179825f_Rx,&channel_get_value.Channel_4.Tpeak_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve4_Tpeak_tot_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_451c5568_Rx,&channel_get_value.Channel_4.Tpeak_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve4_Mode_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_1bb11052_Rx,&channel_get_value.Channel_4.Mode);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve4_State_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_a232522f_Rx,&channel_get_value.Channel_4.State);



           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve5_FWtimeOFF0_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_5049fd63_Rx,&channel_get_value.Channel_5.FWtimeOFF);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve5_Ibias_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_9ebf5eee_Rx,&channel_get_value.Channel_5.Ibias);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve5_IboostB_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_abe33e5c_Rx,&channel_get_value.Channel_5.IboostB);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve5_IboostP_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_f69dba46_Rx,&channel_get_value.Channel_5.IboostP);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve5_Ihold_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_e5abdac9_Rx,&channel_get_value.Channel_5.Ihold);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve5_Ipeak_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_275f8911_Rx,&channel_get_value.Channel_5.Ipeak);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve5_Tbias_off_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_5946b0fa_Rx,&channel_get_value.Channel_5.Tbias_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve5_Tbias_tot_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_0d2367cd_Rx,&channel_get_value.Channel_5.Tbias_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve5_Tbypass_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_434b73dc_Rx,&channel_get_value.Channel_5.Tbypass);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve5_Thold_off_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_6be6ebc0_Rx,&channel_get_value.Channel_5.Thold_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve5_Thold_tot_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_3f833cf7_Rx,&channel_get_value.Channel_5.Thold_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve5_Tpeak_off_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_e3466d7a_Rx,&channel_get_value.Channel_5.Tpeak_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve5_Tpeak_tot_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_b723ba4d_Rx,&channel_get_value.Channel_5.Tpeak_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve5_Mode_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_81675330_Rx,&channel_get_value.Channel_5.Mode);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve5_State_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_1b420beb_Rx,&channel_get_value.Channel_5.State);



           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve6_FWtimeOFF0_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_a2a9518e_Rx,&channel_get_value.Channel_6.FWtimeOFF);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve6_Ibias_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_8e5eb2e3_Rx,&channel_get_value.Channel_6.Ibias);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve6_IboostB_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f4f971cd_Rx,&channel_get_value.Channel_6.IboostB);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve6_IboostP_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_a987f5d7_Rx,&channel_get_value.Channel_6.IboostP);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve6_Ihold_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f54a36c4_Rx,&channel_get_value.Channel_6.Ihold);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve6_Ipeak_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_37be651c_Rx,&channel_get_value.Channel_6.Ipeak);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve6_Tbias_off_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_947787d4_Rx,&channel_get_value.Channel_6.Tbias_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve6_Tbias_tot_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_c01250e3_Rx,&channel_get_value.Channel_6.Tbias_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve6_Tbypass_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_1c513c4d_Rx,&channel_get_value.Channel_6.Tbypass);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve6_Thold_off_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_a6d7dcee_Rx,&channel_get_value.Channel_6.Thold_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve6_Thold_tot_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f2b20bd9_Rx,&channel_get_value.Channel_6.Thold_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve6_Tpeak_off_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_2e775a54_Rx,&channel_get_value.Channel_6.Tpeak_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve6_Tpeak_tot_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_7a128d63_Rx,&channel_get_value.Channel_6.Tpeak_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve6_Mode_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f56c90d7_Rx,&channel_get_value.Channel_6.Mode);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve6_State_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_0ba3e7e6_Rx,&channel_get_value.Channel_6.State);

           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve7_FWtimeOFF0_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_f30935d5_Rx,&channel_get_value.Channel_7.FWtimeOFF);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve7_Ibias_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_372eeb27_Rx,&channel_get_value.Channel_7.Ibias);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve7_IboostB_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_7720497d_Rx,&channel_get_value.Channel_7.IboostB);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve7_IboostP_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_2a5ecd67_Rx,&channel_get_value.Channel_7.IboostP);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve7_Ihold_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_4c3a6f00_Rx,&channel_get_value.Channel_7.Ihold);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve7_Ipeak_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_8ece3cd8_Rx,&channel_get_value.Channel_7.Ipeak);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve7_Tbias_off_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_664868f1_Rx,&channel_get_value.Channel_7.Tbias_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve7_Tbias_tot_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_322dbfc6_Rx,&channel_get_value.Channel_7.Tbias_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve7_Tbypass_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_9f8804fd_Rx,&channel_get_value.Channel_7.Tbypass);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve7_Thold_off_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_54e833cb_Rx,&channel_get_value.Channel_7.Thold_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve7_Thold_tot_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_008de4fc_Rx,&channel_get_value.Channel_7.Thold_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve7_Tpeak_off_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_dc48b571_Rx,&channel_get_value.Channel_7.Tpeak_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve7_Tpeak_tot_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_882d6246_Rx,&channel_get_value.Channel_7.Tpeak_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve7_Mode_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6fbad3b5_Rx,&channel_get_value.Channel_7.Mode);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve7_State_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_b2d3be22_Rx,&channel_get_value.Channel_7.State);



           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve8_FWtimeOFF0_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_7c89260e_Rx,&channel_get_value.Channel_8.FWtimeOFF);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve8_Ibias_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_6448b71e_Rx,&channel_get_value.Channel_8.Ibias);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve8_IboostB_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_8f223ee9_Rx,&channel_get_value.Channel_8.IboostB);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve8_IboostP_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_d25cbaf3_Rx,&channel_get_value.Channel_8.IboostP);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve8_Ihold_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_1f5c3339_Rx,&channel_get_value.Channel_8.Ihold);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve8_Ipeak_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_dda860e1_Rx,&channel_get_value.Channel_8.Ipeak);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve8_Tbias_off_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_295f8fe5_Rx,&channel_get_value.Channel_8.Tbias_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve8_Tbias_tot_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_7d3a58d2_Rx,&channel_get_value.Channel_8.Tbias_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve8_Tbypass_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_678a7369_Rx,&channel_get_value.Channel_8.Tbypass);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve8_Thold_off_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_1bffd4df_Rx,&channel_get_value.Channel_8.Thold_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve8_Thold_tot_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_4f9a03e8_Rx,&channel_get_value.Channel_8.Thold_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve8_Tpeak_off_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_935f5265_Rx,&channel_get_value.Channel_8.Tpeak_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve8_Tpeak_tot_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_c73a8552_Rx,&channel_get_value.Channel_8.Tpeak_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve8_Mode_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_10ef198f_Rx,&channel_get_value.Channel_8.Mode);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve8_State_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_e1b5e21b_Rx,&channel_get_value.Channel_8.State);


           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve9_FWtimeOFF0_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_2d294255_Rx,&channel_get_value.Channel_9.FWtimeOFF);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve9_Ibias_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_dd38eeda_Rx,&channel_get_value.Channel_9.Ibias);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve9_IboostB_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_0cfb0659_Rx,&channel_get_value.Channel_9.IboostB);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve9_IboostP_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_51858243_Rx,&channel_get_value.Channel_9.IboostP);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve9_Ihold_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_a62c6afd_Rx,&channel_get_value.Channel_9.Ihold);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve9_Ipeak_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_64d83925_Rx,&channel_get_value.Channel_9.Ipeak);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve9_Tbias_off_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_db6060c0_Rx,&channel_get_value.Channel_9.Tbias_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve9_Tbias_tot_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_8f05b7f7_Rx,&channel_get_value.Channel_9.Tbias_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve9_Tbypass_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_e4534bd9_Rx,&channel_get_value.Channel_9.Tbypass);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve9_Thold_off_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_e9c03bfa_Rx,&channel_get_value.Channel_9.Thold_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve9_Thold_tot_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_bda5eccd_Rx,&channel_get_value.Channel_9.Thold_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve9_Tpeak_off_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_6160bd40_Rx,&channel_get_value.Channel_9.Tpeak_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve9_Tpeak_tot_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_35056a77_Rx,&channel_get_value.Channel_9.Tpeak_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve9_Mode_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_8a395aed_Rx,&channel_get_value.Channel_9.Mode);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve9_State_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_58c5bbdf_Rx,&channel_get_value.Channel_9.State);


           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve10_FWtimeOFF0_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_2c61f86f_Rx,&channel_get_value.Channel_10.FWtimeOFF);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve10_Ibias_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_9cd31f0c_Rx,&channel_get_value.Channel_10.Ibias);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve10_IboostB_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_65518e5a_Rx,&channel_get_value.Channel_10.IboostB);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve10_IboostP_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_382f0a40_Rx,&channel_get_value.Channel_10.IboostP);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve10_Ihold_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_e7c79b2b_Rx,&channel_get_value.Channel_10.Ihold);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve10_Ipeak_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_2533c8f3_Rx,&channel_get_value.Channel_10.Ipeak);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve10_Tbias_off_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_675c3840_Rx,&channel_get_value.Channel_10.Tbias_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve10_Tbias_tot_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_3339ef77_Rx,&channel_get_value.Channel_10.Tbias_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve10_Tbypass_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_8df9c3da_Rx,&channel_get_value.Channel_10.Tbypass);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve10_Thold_off_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_55fc637a_Rx,&channel_get_value.Channel_10.Thold_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve10_Thold_tot_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_0199b44d_Rx,&channel_get_value.Channel_10.Thold_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve10_Tpeak_off_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_dd5ce5c0_Rx,&channel_get_value.Channel_10.Tpeak_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve10_Tpeak_tot_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_893932f7_Rx,&channel_get_value.Channel_10.Tpeak_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve10_Mode_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_4a458887_Rx,&channel_get_value.Channel_10.Mode);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve10_State_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_192e4a09_Rx,&channel_get_value.Channel_10.State);


           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve11_FWtimeOFF0_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_7dc19c34_Rx,&channel_get_value.Channel_11.FWtimeOFF);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve11_Ibias_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_25a346c8_Rx,&channel_get_value.Channel_11.Ibias);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve11_IboostB_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_e688b6ea_Rx,&channel_get_value.Channel_11.IboostB);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve11_IboostP_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_bbf632f0_Rx,&channel_get_value.Channel_11.IboostP);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve11_Ihold_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_5eb7c2ef_Rx,&channel_get_value.Channel_11.Ihold);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve11_Ipeak_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_9c439137_Rx,&channel_get_value.Channel_11.Ipeak);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve11_Tbias_off_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_9563d765_Rx,&channel_get_value.Channel_11.Tbias_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve11_Tbias_tot_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_c1060052_Rx,&channel_get_value.Channel_11.Tbias_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve11_Tbypass_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0e20fb6a_Rx,&channel_get_value.Channel_11.Tbypass);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve11_Thold_off_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_a7c38c5f_Rx,&channel_get_value.Channel_11.Thold_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve11_Thold_tot_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_f3a65b68_Rx,&channel_get_value.Channel_11.Thold_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve11_Tpeak_off_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_2f630ae5_Rx,&channel_get_value.Channel_11.Tpeak_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve11_Tpeak_tot_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_7b06ddd2_Rx,&channel_get_value.Channel_11.Tpeak_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve11_Mode_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_d093cbe5_Rx,&channel_get_value.Channel_11.Mode);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve11_State_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_a05e13cd_Rx,&channel_get_value.Channel_11.State);




           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve12_FWtimeOFF0_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_8f2130d9_Rx,&channel_get_value.Channel_12.FWtimeOFF);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve12_Ibias_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_3542aac5_Rx,&channel_get_value.Channel_12.Ibias);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve12_IboostB_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_b992f97b_Rx,&channel_get_value.Channel_12.IboostB);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve12_IboostP_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_e4ec7d61_Rx,&channel_get_value.Channel_12.IboostP);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve12_Ihold_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_4e562ee2_Rx,&channel_get_value.Channel_12.Ihold);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve12_Ipeak_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_8ca27d3a_Rx,&channel_get_value.Channel_12.Ipeak);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve12_Tbias_off_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_5852e04b_Rx,&channel_get_value.Channel_12.Tbias_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve12_Tbias_tot_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_0c37377c_Rx,&channel_get_value.Channel_12.Tbias_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve12_Tbypass_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_513ab4fb_Rx,&channel_get_value.Channel_12.Tbypass);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve12_Thold_off_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_6af2bb71_Rx,&channel_get_value.Channel_12.Thold_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve12_Thold_tot_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_3e976c46_Rx,&channel_get_value.Channel_12.Thold_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve12_Tpeak_off_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_e2523dcb_Rx,&channel_get_value.Channel_12.Tpeak_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve12_Tpeak_tot_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_b637eafc_Rx,&channel_get_value.Channel_12.Tpeak_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve12_Mode_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_a4980802_Rx,&channel_get_value.Channel_12.Mode);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve12_State_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_b0bfffc0_Rx,&channel_get_value.Channel_12.State);




           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve13_FWtimeOFF0_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_de815482_Rx,&channel_get_value.Channel_13.FWtimeOFF);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve13_Ibias_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_8c32f301_Rx,&channel_get_value.Channel_13.Ibias);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve13_IboostB_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_3a4bc1cb_Rx,&channel_get_value.Channel_13.IboostB);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve13_IboostP_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_673545d1_Rx,&channel_get_value.Channel_13.IboostP);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve13_Ihold_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_f7267726_Rx,&channel_get_value.Channel_13.Ihold);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve13_Ipeak_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_35d224fe_Rx,&channel_get_value.Channel_13.Ipeak);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve13_Tbias_off_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_aa6d0f6e_Rx,&channel_get_value.Channel_13.Tbias_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve13_Tbias_tot_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_fe08d859_Rx,&channel_get_value.Channel_13.Tbias_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve13_Tbypass_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_d2e38c4b_Rx,&channel_get_value.Channel_13.Tbypass);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve13_Thold_off_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_98cd5454_Rx,&channel_get_value.Channel_13.Thold_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve13_Thold_tot_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_cca88363_Rx,&channel_get_value.Channel_13.Thold_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve13_Tpeak_off_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_106dd2ee_Rx,&channel_get_value.Channel_13.Tpeak_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve13_Tpeak_tot_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_440805d9_Rx,&channel_get_value.Channel_13.Tpeak_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve13_Mode_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_3e4e4b60_Rx,&channel_get_value.Channel_13.Mode);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve13_State_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_09cfa604_Rx,&channel_get_value.Channel_13.State);



           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve14_FWtimeOFF0_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_b1916f42_Rx,&channel_get_value.Channel_14.FWtimeOFF);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve14_Ibias_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_148172df_Rx,&channel_get_value.Channel_14.Ibias);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve14_IboostB_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_07a66659_Rx,&channel_get_value.Channel_14.IboostB);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve14_IboostP_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_5ad8e243_Rx,&channel_get_value.Channel_14.IboostP);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve14_Ihold_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_6f95f6f8_Rx,&channel_get_value.Channel_14.Ihold);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve14_Ipeak_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_ad61a520_Rx,&channel_get_value.Channel_14.Ipeak);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve14_Tbias_off_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_19418856_Rx,&channel_get_value.Channel_14.Tbias_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve14_Tbias_tot_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_4d245f61_Rx,&channel_get_value.Channel_14.Tbias_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve14_Tbypass_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_ef0e2bd9_Rx,&channel_get_value.Channel_14.Tbypass);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve14_Thold_off_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_2be1d36c_Rx,&channel_get_value.Channel_14.Thold_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve14_Thold_tot_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_7f84045b_Rx,&channel_get_value.Channel_14.Thold_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve14_Tpeak_off_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_a34155d6_Rx,&channel_get_value.Channel_14.Tpeak_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve14_Tpeak_tot_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_f72482e1_Rx,&channel_get_value.Channel_14.Tpeak_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve14_Mode_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_4c8f8fcc_Rx,&channel_get_value.Channel_14.Mode);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve14_State_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_917c27da_Rx,&channel_get_value.Channel_14.State);



           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve15_FWtimeOFF0_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_e0310b19_Rx,&channel_get_value.Channel_15.FWtimeOFF);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve15_Ibias_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_adf12b1b_Rx,&channel_get_value.Channel_15.Ibias);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve15_IboostB_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_847f5ee9_Rx,&channel_get_value.Channel_15.IboostB);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve15_IboostP_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_d901daf3_Rx,&channel_get_value.Channel_15.IboostP);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve15_Ihold_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_d6e5af3c_Rx,&channel_get_value.Channel_15.Ihold);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve15_Ipeak_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_1411fce4_Rx,&channel_get_value.Channel_15.Ipeak);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve15_Tbias_off_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_eb7e6773_Rx,&channel_get_value.Channel_15.Tbias_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve15_Tbias_tot_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_bf1bb044_Rx,&channel_get_value.Channel_15.Tbias_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve15_Tbypass_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_6cd71369_Rx,&channel_get_value.Channel_15.Tbypass);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve15_Thold_off_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_d9de3c49_Rx,&channel_get_value.Channel_15.Thold_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve15_Thold_tot_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_8dbbeb7e_Rx,&channel_get_value.Channel_15.Thold_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve15_Tpeak_off_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_517ebaf3_Rx,&channel_get_value.Channel_15.Tpeak_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve15_Tpeak_tot_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_051b6dc4_Rx,&channel_get_value.Channel_15.Tpeak_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve15_Mode_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_d659ccae_Rx,&channel_get_value.Channel_15.Mode);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve15_State_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_280c7e1e_Rx,&channel_get_value.Channel_15.State);



           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve16_FWtimeOFF0_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_12d1a7f4_Rx,&channel_get_value.Channel_16.FWtimeOFF);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve16_Ibias_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_bd10c716_Rx,&channel_get_value.Channel_16.Ibias);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve16_IboostB_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_db651178_Rx,&channel_get_value.Channel_16.IboostB);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve16_IboostP_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_861b9562_Rx,&channel_get_value.Channel_16.IboostP);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve16_Ihold_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_c6044331_Rx,&channel_get_value.Channel_16.Ihold);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve16_Ipeak_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_04f010e9_Rx,&channel_get_value.Channel_16.Ipeak);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve16_Tbias_off_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_264f505d_Rx,&channel_get_value.Channel_16.Tbias_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve16_Tbias_tot_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_722a876a_Rx,&channel_get_value.Channel_16.Tbias_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve16_Tbypass_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_33cd5cf8_Rx,&channel_get_value.Channel_16.Tbypass);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve16_Thold_off_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_14ef0b67_Rx,&channel_get_value.Channel_16.Thold_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve16_Thold_tot_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_408adc50_Rx,&channel_get_value.Channel_16.Thold_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve16_Tpeak_off_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_9c4f8ddd_Rx,&channel_get_value.Channel_16.Tpeak_off);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve16_Tpeak_tot_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_c82a5aea_Rx,&channel_get_value.Channel_16.Tpeak_tot);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve16_Mode_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_a2520f49_Rx,&channel_get_value.Channel_16.Mode);
           Com_ReceiveSignal(ComConf_ComSignal_Sig_Valve16_State_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_38ed9213_Rx,&channel_get_value.Channel_16.State);
    	  }
    }



// All solenoid valves are closed
void Set_AllStartPin_Low()
{
    Dio_WriteChannel(DioConf_DioChannel_V1_START1,PT2000_Disable);
    Dio_WriteChannel(DioConf_DioChannel_V1_START2,PT2000_Disable);
    Dio_WriteChannel(DioConf_DioChannel_V1_START3,PT2000_Disable);
    Dio_WriteChannel(DioConf_DioChannel_V2_START1,PT2000_Disable);
    Dio_WriteChannel(DioConf_DioChannel_V2_START2,PT2000_Disable);
    Dio_WriteChannel(DioConf_DioChannel_V2_START3,PT2000_Disable);
    Dio_WriteChannel(DioConf_DioChannel_V3_START1,PT2000_Disable);
    Dio_WriteChannel(DioConf_DioChannel_V3_START2,PT2000_Disable);
    Dio_WriteChannel(DioConf_DioChannel_V3_START3,PT2000_Disable);
    Dio_WriteChannel(DioConf_DioChannel_V4_START1,PT2000_Disable);
    Dio_WriteChannel(DioConf_DioChannel_V4_START2,PT2000_Disable);
    Dio_WriteChannel(DioConf_DioChannel_V4_START3,PT2000_Disable);
    Dio_WriteChannel(DioConf_DioChannel_V5_START1,PT2000_Disable);
    Dio_WriteChannel(DioConf_DioChannel_V5_START2,PT2000_Disable);
    Dio_WriteChannel(DioConf_DioChannel_V5_START3,PT2000_Disable);
    Dio_WriteChannel(DioConf_DioChannel_V6_START1,PT2000_Disable);
    Dio_WriteChannel(DioConf_DioChannel_V6_START2,PT2000_Disable);
    Dio_WriteChannel(DioConf_DioChannel_V6_START3,PT2000_Disable);

}


//Reset 引脚拉高
void Set_RESETPin_High(uint8 csindex)
{
    switch(csindex)
    {
        case 1:
            Dio_WriteChannel(DioConf_DioChannel_V1_RESET,PT2000_Enable);
            break;
        case 2:
            Dio_WriteChannel(DioConf_DioChannel_V2_RESET,PT2000_Enable);
            break;
        case 3:
            Dio_WriteChannel(DioConf_DioChannel_V3_RESET,PT2000_Enable);
            break;
        case 4:
            Dio_WriteChannel(DioConf_DioChannel_V4_RESET,PT2000_Enable);
            break;
        case 5:
            Dio_WriteChannel(DioConf_DioChannel_V5_RESET,PT2000_Enable);
            break;
        case 6:
            Dio_WriteChannel(DioConf_DioChannel_V6_RESET,PT2000_Enable);
            break;
        default:
            break;
    }
}


//Reset 引脚拉低
void Set_RESETPin_Low(uint8 csindex)
{
    switch(csindex)
    {
        case 1:
            Dio_WriteChannel(DioConf_DioChannel_V1_RESET,PT2000_Disable);
            break;
        case 2:
            Dio_WriteChannel(DioConf_DioChannel_V2_RESET,PT2000_Disable);
            break;
        case 3:
            Dio_WriteChannel(DioConf_DioChannel_V3_RESET,PT2000_Disable);
            break;
        case 4:
            Dio_WriteChannel(DioConf_DioChannel_V4_RESET,PT2000_Disable);
            break;
        case 5:
            Dio_WriteChannel(DioConf_DioChannel_V5_RESET,PT2000_Disable);
            break;
        case 6:
            Dio_WriteChannel(DioConf_DioChannel_V6_RESET,PT2000_Disable);
            break;
        default:
            break;
    }
}


//应用层电磁阀开启关闭控制所用函数
void Set_StartPin_State1(Channel_Number Ch_Number, boolean state)
{

	  if((( channel_get_value.Channel_1.PC_Change == 0)&&( channel_get_value.Channel_2.PC_Change == 0)&&
				( channel_get_value.Channel_3.PC_Change == 0)&&(channel_get_value.Channel_4.PC_Change == 0)&&( channel_get_value.Channel_5.PC_Change == 0)&&
				( channel_get_value.Channel_6.PC_Change == 0)&&( channel_get_value.Channel_7.PC_Change == 0)&&( channel_get_value.Channel_8.PC_Change == 0)&&
				( channel_get_value.Channel_9.PC_Change == 0)&&( channel_get_value.Channel_10.PC_Change == 0)&&( channel_get_value.Channel_11.PC_Change == 0)&&
				(channel_get_value.Channel_12.PC_Change == 0)&&( channel_get_value.Channel_13.PC_Change == 0)&&( channel_get_value.Channel_14.PC_Change == 0)&&
				( channel_get_value.Channel_15.PC_Change == 0)&&( channel_get_value.Channel_16.PC_Change == 0)))
	  {



    if(state == PT2000_Enable){
        switch(Ch_Number){
            case Channel_number_1:
                Dio_WriteChannel(DioConf_DioChannel_V1_START1,PT2000_Enable);
                channel.Channel_1.State = 1;
                break;

            case Channel_number_2:
                Dio_WriteChannel(DioConf_DioChannel_V1_START2,PT2000_Enable);
                channel.Channel_2.State = 1;
                break;

            case Channel_number_3:
                Dio_WriteChannel(DioConf_DioChannel_V1_START3,PT2000_Enable);
                channel.Channel_3.State = 1;
                break;

            case Channel_number_4:
                Dio_WriteChannel(DioConf_DioChannel_V2_START1,PT2000_Enable);
                channel.Channel_4.State = 1;
                break;

            case Channel_number_5:
                Dio_WriteChannel(DioConf_DioChannel_V2_START2,PT2000_Enable);
                channel.Channel_5.State = 1;
                break;

            case Channel_number_6:
                Dio_WriteChannel(DioConf_DioChannel_V2_START3,PT2000_Enable);
                channel.Channel_6.State = 1;
                break;

            case Channel_number_7:
                Dio_WriteChannel(DioConf_DioChannel_V3_START1,PT2000_Enable);
                channel.Channel_7.State = 1;
                break;

            case Channel_number_8:
                Dio_WriteChannel(DioConf_DioChannel_V3_START2,PT2000_Enable);
                channel.Channel_8.State = 1;
                break;

            case Channel_number_9:
                Dio_WriteChannel(DioConf_DioChannel_V3_START3,PT2000_Enable);
                channel.Channel_9.State = 1;
                break;

            case Channel_number_10:
                Dio_WriteChannel(DioConf_DioChannel_V4_START1,PT2000_Enable);
                channel.Channel_10.State = 1;
                break;

            case Channel_number_11:
                Dio_WriteChannel(DioConf_DioChannel_V4_START2,PT2000_Enable);
                channel.Channel_11.State = 1;
                break;

            case Channel_number_12:
                Dio_WriteChannel(DioConf_DioChannel_V4_START3,PT2000_Enable);
                channel.Channel_12.State = 1;
                break;

            case Channel_number_13:
                Dio_WriteChannel(DioConf_DioChannel_V6_START2,PT2000_Enable);
                channel.Channel_13.State = 1;
                break;

            case Channel_number_14:
                Dio_WriteChannel(DioConf_DioChannel_V5_START2,PT2000_Enable);
                channel.Channel_14.State = 1;
                break;

            case Channel_number_15:
                Dio_WriteChannel(DioConf_DioChannel_V5_START3,PT2000_Enable);
                channel.Channel_15.State = 1;
                break;

            case Channel_number_16:
                Dio_WriteChannel(DioConf_DioChannel_V6_START3,PT2000_Enable);
                channel.Channel_16.State = 1;
                break;

//            case Channel_number_17:
//                Dio_WriteChannel(DioConf_DioChannel_V6_START2,PT2000_Enable);
//                break;
//
//            case Channel_number_18:
//                Dio_WriteChannel(DioConf_DioChannel_V6_START3,PT2000_Enable);
//                break;

            default:
                break;
        }
    }
    else if(state == PT2000_Disable){
        switch(Ch_Number){
            case Channel_number_1:
                Dio_WriteChannel(DioConf_DioChannel_V1_START1,PT2000_Disable);
                channel.Channel_1.State = 0;
                break;

            case Channel_number_2:
                Dio_WriteChannel(DioConf_DioChannel_V1_START2,PT2000_Disable);
                channel.Channel_2.State = 0;
                break;

            case Channel_number_3:
                Dio_WriteChannel(DioConf_DioChannel_V1_START3,PT2000_Disable);
                channel.Channel_3.State = 0;
                break;

            case Channel_number_4:
                Dio_WriteChannel(DioConf_DioChannel_V2_START1,PT2000_Disable);
                channel.Channel_4.State = 0;
                break;

            case Channel_number_5:
                Dio_WriteChannel(DioConf_DioChannel_V2_START2,PT2000_Disable);
                channel.Channel_5.State = 0;
                break;

            case Channel_number_6:
                Dio_WriteChannel(DioConf_DioChannel_V2_START3,PT2000_Disable);
                channel.Channel_6.State = 0;
                break;

            case Channel_number_7:
                Dio_WriteChannel(DioConf_DioChannel_V3_START1,PT2000_Disable);
                channel.Channel_7.State = 0;
                break;

            case Channel_number_8:
                Dio_WriteChannel(DioConf_DioChannel_V3_START2,PT2000_Disable);
                channel.Channel_8.State = 0;
                break;

            case Channel_number_9:
                Dio_WriteChannel(DioConf_DioChannel_V3_START3,PT2000_Disable);
                channel.Channel_9.State = 0;
                break;

            case Channel_number_10:
                Dio_WriteChannel(DioConf_DioChannel_V4_START1,PT2000_Disable);
                channel.Channel_10.State = 0;
                break;

            case Channel_number_11:
                Dio_WriteChannel(DioConf_DioChannel_V4_START2,PT2000_Disable);
                channel.Channel_11.State = 0;
                break;

            case Channel_number_12:
                Dio_WriteChannel(DioConf_DioChannel_V4_START3,PT2000_Disable);
                channel.Channel_12.State = 0;
                break;

            case Channel_number_13:
                Dio_WriteChannel(DioConf_DioChannel_V6_START2,PT2000_Disable);
                channel.Channel_13.State = 0;
                break;

            case Channel_number_14:
                Dio_WriteChannel(DioConf_DioChannel_V5_START2,PT2000_Disable);
                channel.Channel_14.State = 0;
                break;

            case Channel_number_15:
                Dio_WriteChannel(DioConf_DioChannel_V5_START3,PT2000_Disable);
                channel.Channel_15.State = 0;
                break;

            case Channel_number_16:
                Dio_WriteChannel(DioConf_DioChannel_V6_START3,PT2000_Disable);
                channel.Channel_16.State = 0;
                break;

//            case Channel_number_17:
//                Dio_WriteChannel(DioConf_DioChannel_V6_START2,PT2000_Disable);
//                break;
//
//            case Channel_number_18:
//                Dio_WriteChannel(DioConf_DioChannel_V6_START3,PT2000_Disable);
//                break;

            default:
                break;
        }
    }
}
}




// CAN控制电磁阀开启关闭所用函数
void Set_StartPin_State(Channel_Number Ch_Number, boolean state)
{


    if(state == PT2000_Enable){
        switch(Ch_Number){
            case Channel_number_1:
                Dio_WriteChannel(DioConf_DioChannel_V1_START1,PT2000_Enable);
                channel.Channel_1.State = 1;
                break;

            case Channel_number_2:
                Dio_WriteChannel(DioConf_DioChannel_V1_START2,PT2000_Enable);
                channel.Channel_2.State = 1;
                break;

            case Channel_number_3:
                Dio_WriteChannel(DioConf_DioChannel_V1_START3,PT2000_Enable);
                channel.Channel_3.State = 1;
                break;

            case Channel_number_4:
                Dio_WriteChannel(DioConf_DioChannel_V2_START1,PT2000_Enable);
                channel.Channel_4.State = 1;
                break;

            case Channel_number_5:
                Dio_WriteChannel(DioConf_DioChannel_V2_START2,PT2000_Enable);
                channel.Channel_5.State = 1;
                break;

            case Channel_number_6:
                Dio_WriteChannel(DioConf_DioChannel_V2_START3,PT2000_Enable);
                channel.Channel_6.State = 1;
                break;

            case Channel_number_7:
                Dio_WriteChannel(DioConf_DioChannel_V3_START1,PT2000_Enable);
                channel.Channel_7.State = 1;
                break;

            case Channel_number_8:
                Dio_WriteChannel(DioConf_DioChannel_V3_START2,PT2000_Enable);
                channel.Channel_8.State = 1;
                break;

            case Channel_number_9:
                Dio_WriteChannel(DioConf_DioChannel_V3_START3,PT2000_Enable);
                channel.Channel_9.State = 1;
                break;

            case Channel_number_10:
                Dio_WriteChannel(DioConf_DioChannel_V4_START1,PT2000_Enable);
                channel.Channel_10.State = 1;
                break;

            case Channel_number_11:
                Dio_WriteChannel(DioConf_DioChannel_V4_START2,PT2000_Enable);
                channel.Channel_11.State = 1;
                break;

            case Channel_number_12:
                Dio_WriteChannel(DioConf_DioChannel_V4_START3,PT2000_Enable);
                channel.Channel_12.State = 1;
                break;

            case Channel_number_13:
                Dio_WriteChannel(DioConf_DioChannel_V6_START2,PT2000_Enable);
                channel.Channel_13.State = 1;
                break;

            case Channel_number_14:
                Dio_WriteChannel(DioConf_DioChannel_V5_START2,PT2000_Enable);
                channel.Channel_14.State = 1;
                break;

            case Channel_number_15:
                Dio_WriteChannel(DioConf_DioChannel_V5_START3,PT2000_Enable);
                channel.Channel_15.State = 1;
                break;

            case Channel_number_16:
                Dio_WriteChannel(DioConf_DioChannel_V6_START3,PT2000_Enable);
                channel.Channel_16.State = 1;
                break;

//            case Channel_number_17:
//                Dio_WriteChannel(DioConf_DioChannel_V6_START2,PT2000_Enable);
//                break;
//
//            case Channel_number_18:
//                Dio_WriteChannel(DioConf_DioChannel_V6_START3,PT2000_Enable);
//                break;

            default:
                break;
        }
    }
    else if(state == PT2000_Disable){
        switch(Ch_Number){
        case Channel_number_1:
            Dio_WriteChannel(DioConf_DioChannel_V1_START1,PT2000_Disable);
            channel.Channel_1.State = 0;
            break;

        case Channel_number_2:
            Dio_WriteChannel(DioConf_DioChannel_V1_START2,PT2000_Disable);
            channel.Channel_2.State = 0;
            break;

        case Channel_number_3:
            Dio_WriteChannel(DioConf_DioChannel_V1_START3,PT2000_Disable);
            channel.Channel_3.State = 0;
            break;

        case Channel_number_4:
            Dio_WriteChannel(DioConf_DioChannel_V2_START1,PT2000_Disable);
            channel.Channel_4.State = 0;
            break;

        case Channel_number_5:
            Dio_WriteChannel(DioConf_DioChannel_V2_START2,PT2000_Disable);
            channel.Channel_5.State = 0;
            break;

        case Channel_number_6:
            Dio_WriteChannel(DioConf_DioChannel_V2_START3,PT2000_Disable);
            channel.Channel_6.State = 0;
            break;

        case Channel_number_7:
            Dio_WriteChannel(DioConf_DioChannel_V3_START1,PT2000_Disable);
            channel.Channel_7.State = 0;
            break;

        case Channel_number_8:
            Dio_WriteChannel(DioConf_DioChannel_V3_START2,PT2000_Disable);
            channel.Channel_8.State = 0;
            break;

        case Channel_number_9:
            Dio_WriteChannel(DioConf_DioChannel_V3_START3,PT2000_Disable);
            channel.Channel_9.State = 0;
            break;

        case Channel_number_10:
            Dio_WriteChannel(DioConf_DioChannel_V4_START1,PT2000_Disable);
            channel.Channel_10.State = 0;
            break;

        case Channel_number_11:
            Dio_WriteChannel(DioConf_DioChannel_V4_START2,PT2000_Disable);
            channel.Channel_11.State = 0;
            break;

        case Channel_number_12:
            Dio_WriteChannel(DioConf_DioChannel_V4_START3,PT2000_Disable);
            channel.Channel_12.State = 0;
            break;

        case Channel_number_13:
            Dio_WriteChannel(DioConf_DioChannel_V6_START2,PT2000_Disable);
            channel.Channel_13.State = 0;
            break;

        case Channel_number_14:
            Dio_WriteChannel(DioConf_DioChannel_V5_START2,PT2000_Disable);
            channel.Channel_14.State = 0;
            break;

        case Channel_number_15:
            Dio_WriteChannel(DioConf_DioChannel_V5_START3,PT2000_Disable);
            channel.Channel_15.State = 0;
            break;

        case Channel_number_16:
            Dio_WriteChannel(DioConf_DioChannel_V6_START3,PT2000_Disable);
            channel.Channel_16.State = 0;
            break;
//            case Channel_number_17:
//                Dio_WriteChannel(DioConf_DioChannel_V6_START2,PT2000_Disable);
//                break;
//
//            case Channel_number_18:
//                Dio_WriteChannel(DioConf_DioChannel_V6_START3,PT2000_Disable);
//                break;

            default:
                break;
        }
    }
}


// PT2000使能发送
void SendCmd_EnChannel()
{
    sendBuf[0] = 0x20;
    sendBuf[1] = 0x01;
    IoHwAb_SPI_Write(x, y);
    sendBuf[0] = 0x00;
    sendBuf[1] = 0x18;
    IoHwAb_SPI_Write(x, y);

    sendBuf[0] = 0x24;
    sendBuf[1] = 0x01;
    IoHwAb_SPI_Write(x, y);
    sendBuf[0] = 0x00;
    sendBuf[1] = 0x18;
    IoHwAb_SPI_Write(x, y);

    sendBuf[0] = 0x28;
    sendBuf[1] = 0x01;
    IoHwAb_SPI_Write(x,y );
    sendBuf[0] = 0x00;
    sendBuf[1] = 0x18;
    IoHwAb_SPI_Write(x, y);
}

// PT2000下载
void Download_Pt2000(Enum_Mode mode)
{
    if (mode == ConstantCurrent_Mode){

        ProgramDevice();

    }
    else{

        ProgramDevice_Peak();
    }
}

// 初始化赋值
void initValveParamConfig(ValveParam *m_ValveParam, Channel_Number Ch_Number, Enum_Mode mode)
{

    //恒流模式
    if (mode == ConstantCurrent_Mode){
        switch(Ch_Number){
            case Channel_number_1:
                m_ValveParam->IboostB    = 130;
                m_ValveParam->Tbias_tot  = 0x0000;
                m_ValveParam->Tbias_off  = 0x0000;
                m_ValveParam->Ibias      = 0x0000;
                m_ValveParam->IboostP    = 0x0000;
                m_ValveParam->Tpeak_tot  = 1500;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 72;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 71;
                m_ValveParam->FWtimeOFF  = 0x00;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_2:
                m_ValveParam->IboostB    = 130;
                m_ValveParam->Tbias_tot  = 0x0000;
                m_ValveParam->Tbias_off  = 0x0000;
                m_ValveParam->Ibias      = 0x0000;
                m_ValveParam->IboostP    = 0x0000;
                m_ValveParam->Tpeak_tot  = 1500;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 72;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 71;
                m_ValveParam->FWtimeOFF  = 0x00;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_3:
                m_ValveParam->IboostB    = 130;
                m_ValveParam->Tbias_tot  = 0x0000;
                m_ValveParam->Tbias_off  = 0x0000;
                m_ValveParam->Ibias      = 0x0000;
                m_ValveParam->IboostP    = 0x0000;
                m_ValveParam->Tpeak_tot  = 1500;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 72;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 71;
                m_ValveParam->FWtimeOFF  = 0x00;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_4:
                m_ValveParam->IboostB    = 130;
                m_ValveParam->Tbias_tot  = 0x0000;
                m_ValveParam->Tbias_off  = 0x0000;
                m_ValveParam->Ibias      = 0x0000;
                m_ValveParam->IboostP    = 0x0000;
                m_ValveParam->Tpeak_tot  = 1500;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 72;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 2000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 71;
                m_ValveParam->FWtimeOFF  = 0x00;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_5:
                m_ValveParam->IboostB    = 130;
                m_ValveParam->Tbias_tot  = 0x0000;
                m_ValveParam->Tbias_off  = 0x0000;
                m_ValveParam->Ibias      = 0x0000;
                m_ValveParam->IboostP    = 0x0000;
                m_ValveParam->Tpeak_tot  = 1500;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 72;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 71;
                m_ValveParam->FWtimeOFF  = 0x00;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_6:
                m_ValveParam->IboostB    = 130;
                m_ValveParam->Tbias_tot  = 0x0000;
                m_ValveParam->Tbias_off  = 0x0000;
                m_ValveParam->Ibias      = 0x0000;
                m_ValveParam->IboostP    = 0x0000;
                m_ValveParam->Tpeak_tot  = 1500;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 72;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 71;
                m_ValveParam->FWtimeOFF  = 0x00;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_7:
                m_ValveParam->IboostB    = 130;
                m_ValveParam->Tbias_tot  = 0x0000;
                m_ValveParam->Tbias_off  = 0x0000;
                m_ValveParam->Ibias      = 0x0000;
                m_ValveParam->IboostP    = 0x0000;
                m_ValveParam->Tpeak_tot  = 1500;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 72;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 71;
                m_ValveParam->FWtimeOFF  = 0x00;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_8:
                m_ValveParam->IboostB    = 130;
                m_ValveParam->Tbias_tot  = 0x0000;
                m_ValveParam->Tbias_off  = 0x0000;
                m_ValveParam->Ibias      = 0x0000;
                m_ValveParam->IboostP    = 0x0000;
                m_ValveParam->Tpeak_tot  = 1500;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 72;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 71;
                m_ValveParam->FWtimeOFF  = 0x00;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_9:
                m_ValveParam->IboostB    = 130;
                m_ValveParam->Tbias_tot  = 0x0000;
                m_ValveParam->Tbias_off  = 0x0000;
                m_ValveParam->Ibias      = 0x0000;
                m_ValveParam->IboostP    = 0x0000;
                m_ValveParam->Tpeak_tot  = 1500;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 72;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 71;
                m_ValveParam->FWtimeOFF  = 0x00;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_10:
                m_ValveParam->IboostB    = 130;
                m_ValveParam->Tbias_tot  = 0x0000;
                m_ValveParam->Tbias_off  = 0x0000;
                m_ValveParam->Ibias      = 0x0000;
                m_ValveParam->IboostP    = 0x0000;
                m_ValveParam->Tpeak_tot  = 1500;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 72;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 71;
                m_ValveParam->FWtimeOFF  = 0;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_11:
                m_ValveParam->IboostB    = 130;
                m_ValveParam->Tbias_tot  = 0x0000;
                m_ValveParam->Tbias_off  = 0x0000;
                m_ValveParam->Ibias      = 0x0000;
                m_ValveParam->IboostP    = 0x0000;
                m_ValveParam->Tpeak_tot  = 1500;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 72;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 71;
                m_ValveParam->FWtimeOFF  = 0x00;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_12:
                m_ValveParam->IboostB    = 130;
                m_ValveParam->Tbias_tot  = 0x0000;
                m_ValveParam->Tbias_off  = 0x0000;
                m_ValveParam->Ibias      = 0x0000;
                m_ValveParam->IboostP    = 0x0000;
                m_ValveParam->Tpeak_tot  = 1500;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 72;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 71;
                m_ValveParam->FWtimeOFF  = 0x00;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_13:
                m_ValveParam->IboostB    = 130;
                m_ValveParam->Tbias_tot  = 0x0000;
                m_ValveParam->Tbias_off  = 0x0000;
                m_ValveParam->Ibias      = 0x0000;
                m_ValveParam->IboostP    = 0x0000;
                m_ValveParam->Tpeak_tot  = 1500;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 72;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 71;
                m_ValveParam->FWtimeOFF  = 0x00;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_14:
                m_ValveParam->IboostB    = 130;
                m_ValveParam->Tbias_tot  = 0x0000;
                m_ValveParam->Tbias_off  = 0x0000;
                m_ValveParam->Ibias      = 0x0000;
                m_ValveParam->IboostP    = 0x0000;
                m_ValveParam->Tpeak_tot  = 1500;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 72;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 71;
                m_ValveParam->FWtimeOFF  = 0x00;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_15:
                m_ValveParam->IboostB    = 130;
                m_ValveParam->Tbias_tot  = 0x0000;
                m_ValveParam->Tbias_off  = 0x0000;
                m_ValveParam->Ibias      = 0x0000;
                m_ValveParam->IboostP    = 0x0000;
                m_ValveParam->Tpeak_tot  = 1500;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 72;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 71;
                m_ValveParam->FWtimeOFF  = 0x00;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_16:
                m_ValveParam->IboostB    = 130;
                m_ValveParam->Tbias_tot  = 0x0000;
                m_ValveParam->Tbias_off  = 0x0000;
                m_ValveParam->Ibias      = 0x0000;
                m_ValveParam->IboostP    = 0x0000;
                m_ValveParam->Tpeak_tot  = 1500;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 72;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 71;
                m_ValveParam->FWtimeOFF  = 0x00;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_17:
                m_ValveParam->IboostB    = 130;
                m_ValveParam->Tbias_tot  = 0x0000;
                m_ValveParam->Tbias_off  = 0x0000;
                m_ValveParam->Ibias      = 0x0000;
                m_ValveParam->IboostP    = 0x0000;
                m_ValveParam->Tpeak_tot  = 1500;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 72;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 71;
                m_ValveParam->FWtimeOFF  = 0x00;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_18:
                m_ValveParam->IboostB    = 130;
                m_ValveParam->Tbias_tot  = 0x0000;
                m_ValveParam->Tbias_off  = 0x0000;
                m_ValveParam->Ibias      = 0x0000;
                m_ValveParam->IboostP    = 0x0000;
                m_ValveParam->Tpeak_tot  = 1500;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 72;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 71;
                m_ValveParam->FWtimeOFF  = 0x00;
                m_ValveParam->State  = 0x00;
                break;

            default:
                break;
        }
    }

    //Peak_hold模式
    else {
        switch(Ch_Number){
            case Channel_number_1:
                m_ValveParam->IboostB    = 120;
                m_ValveParam->Tbias_tot  = 60000;
                m_ValveParam->Tbias_off  = 40;
                m_ValveParam->Ibias      = 50;
                m_ValveParam->IboostP    = 80;
                m_ValveParam->Tpeak_tot  = 60000;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 68;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 50;
                m_ValveParam->FWtimeOFF  = 60000;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_2:
                m_ValveParam->IboostB    = 120;
                m_ValveParam->Tbias_tot  = 60000;
                m_ValveParam->Tbias_off  = 40;
                m_ValveParam->Ibias      = 50;
                m_ValveParam->IboostP    = 80;
                m_ValveParam->Tpeak_tot  = 60000;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 68;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 50;
                m_ValveParam->FWtimeOFF  = 60000;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_3:
                m_ValveParam->IboostB    = 120;
                m_ValveParam->Tbias_tot  = 60000;
                m_ValveParam->Tbias_off  = 40;
                m_ValveParam->Ibias      = 50;
                m_ValveParam->IboostP    = 80;
                m_ValveParam->Tpeak_tot  = 60000;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 68;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 50;
                m_ValveParam->FWtimeOFF  = 60000;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_4:
                m_ValveParam->IboostB    = 120;
                m_ValveParam->Tbias_tot  = 60000;
                m_ValveParam->Tbias_off  = 40;
                m_ValveParam->Ibias      = 50;
                m_ValveParam->IboostP    = 80;
                m_ValveParam->Tpeak_tot  = 60000;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 68;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 50;
                m_ValveParam->FWtimeOFF  = 60000;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_5:
                m_ValveParam->IboostB    = 120;
                m_ValveParam->Tbias_tot  = 60000;
                m_ValveParam->Tbias_off  = 40;
                m_ValveParam->Ibias      = 50;
                m_ValveParam->IboostP    = 80;
                m_ValveParam->Tpeak_tot  = 60000;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 68;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 50;
                m_ValveParam->FWtimeOFF  = 60000;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_6:
                m_ValveParam->IboostB    = 120;
                m_ValveParam->Tbias_tot  = 60000;
                m_ValveParam->Tbias_off  = 40;
                m_ValveParam->Ibias      = 50;
                m_ValveParam->IboostP    = 80;
                m_ValveParam->Tpeak_tot  = 60000;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 68;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 50;
                m_ValveParam->FWtimeOFF  = 60000;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_7:
                m_ValveParam->IboostB    = 120;
                m_ValveParam->Tbias_tot  = 60000;
                m_ValveParam->Tbias_off  = 40;
                m_ValveParam->Ibias      = 50;
                m_ValveParam->IboostP    = 80;
                m_ValveParam->Tpeak_tot  = 60000;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 68;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 50;
                m_ValveParam->FWtimeOFF  = 60000;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_8:
                m_ValveParam->IboostB    = 120;
                m_ValveParam->Tbias_tot  = 60000;
                m_ValveParam->Tbias_off  = 40;
                m_ValveParam->Ibias      = 50;
                m_ValveParam->IboostP    = 80;
                m_ValveParam->Tpeak_tot  = 60000;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 68;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 50;
                m_ValveParam->FWtimeOFF  = 60000;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_9:
                m_ValveParam->IboostB    = 120;
                m_ValveParam->Tbias_tot  = 60000;
                m_ValveParam->Tbias_off  = 40;
                m_ValveParam->Ibias      = 50;
                m_ValveParam->IboostP    = 80;
                m_ValveParam->Tpeak_tot  = 60000;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 68;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 50;
                m_ValveParam->FWtimeOFF  = 60000;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_10:
                m_ValveParam->IboostB    = 120;
                m_ValveParam->Tbias_tot  = 60000;
                m_ValveParam->Tbias_off  = 40;
                m_ValveParam->Ibias      = 50;
                m_ValveParam->IboostP    = 80;
                m_ValveParam->Tpeak_tot  = 60000;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 68;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 50;
                m_ValveParam->FWtimeOFF  = 60000;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_11:
                m_ValveParam->IboostB    = 120;
                m_ValveParam->Tbias_tot  = 60000;
                m_ValveParam->Tbias_off  = 40;
                m_ValveParam->Ibias      = 50;
                m_ValveParam->IboostP    = 80;
                m_ValveParam->Tpeak_tot  = 60000;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 68;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 50;
                m_ValveParam->FWtimeOFF  = 60000;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_12:
                m_ValveParam->IboostB    = 120;
                m_ValveParam->Tbias_tot  = 60000;
                m_ValveParam->Tbias_off  = 40;
                m_ValveParam->Ibias      = 50;
                m_ValveParam->IboostP    = 80;
                m_ValveParam->Tpeak_tot  = 60000;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 68;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 50;
                m_ValveParam->FWtimeOFF  = 60000;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_13:
                m_ValveParam->IboostB    = 120;
                m_ValveParam->Tbias_tot  = 60000;
                m_ValveParam->Tbias_off  = 40;
                m_ValveParam->Ibias      = 50;
                m_ValveParam->IboostP    = 80;
                m_ValveParam->Tpeak_tot  = 60000;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 68;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 50;
                m_ValveParam->FWtimeOFF  = 60000;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_14:
                m_ValveParam->IboostB    = 120;
                m_ValveParam->Tbias_tot  = 60000;
                m_ValveParam->Tbias_off  = 40;
                m_ValveParam->Ibias      = 50;
                m_ValveParam->IboostP    = 80;
                m_ValveParam->Tpeak_tot  = 60000;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 68;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 50;
                m_ValveParam->FWtimeOFF  = 60000;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_15:
                m_ValveParam->IboostB    = 120;
                m_ValveParam->Tbias_tot  = 60000;
                m_ValveParam->Tbias_off  = 40;
                m_ValveParam->Ibias      = 50;
                m_ValveParam->IboostP    = 80;
                m_ValveParam->Tpeak_tot  = 60000;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 68;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 50;
                m_ValveParam->FWtimeOFF  = 60000;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_16:
                m_ValveParam->IboostB    = 120;
                m_ValveParam->Tbias_tot  = 60000;
                m_ValveParam->Tbias_off  = 40;
                m_ValveParam->Ibias      = 50;
                m_ValveParam->IboostP    = 80;
                m_ValveParam->Tpeak_tot  = 60000;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 68;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 50;
                m_ValveParam->FWtimeOFF  = 60000;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_17:
                m_ValveParam->IboostB    = 120;
                m_ValveParam->Tbias_tot  = 60000;
                m_ValveParam->Tbias_off  = 40;
                m_ValveParam->Ibias      = 50;
                m_ValveParam->IboostP    = 80;
                m_ValveParam->Tpeak_tot  = 60000;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 68;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 50;
                m_ValveParam->FWtimeOFF  = 60000;
                m_ValveParam->State  = 0x00;
                break;

            case Channel_number_18:
                m_ValveParam->IboostB    = 120;
                m_ValveParam->Tbias_tot  = 60000;
                m_ValveParam->Tbias_off  = 40;
                m_ValveParam->Ibias      = 50;
                m_ValveParam->IboostP    = 80;
                m_ValveParam->Tpeak_tot  = 60000;
                m_ValveParam->Tpeak_off  = 40;
                m_ValveParam->Ipeak      = 68;
                m_ValveParam->Tbypass    = 1500;
                m_ValveParam->Thold_tot  = 60000;
                m_ValveParam->Thold_off  = 40;
                m_ValveParam->Ihold      = 50;
                m_ValveParam->FWtimeOFF  = 60000;
                m_ValveParam->State  = 0x00;
                break;

            default:
                break;
        }
    }
}

//  将初始化的值赋给各个通道
void initValveParam(Enum_Mode mode)
{
    ValveParam ValveParamCH;


    initValveParamConfig(&ValveParamCH, Channel_number_1, mode);



    channel.Channel_1 = ValveParamCH;



    initValveParamConfig(&ValveParamCH, Channel_number_2, mode);
    channel.Channel_2 = ValveParamCH;


    initValveParamConfig(&ValveParamCH, Channel_number_3, mode);
    channel.Channel_3 = ValveParamCH;


    initValveParamConfig(&ValveParamCH, Channel_number_4, mode);
    channel.Channel_4 = ValveParamCH;


    initValveParamConfig(&ValveParamCH, Channel_number_5, mode);
    channel.Channel_5 = ValveParamCH;


    initValveParamConfig(&ValveParamCH, Channel_number_6, mode);
    channel.Channel_6 = ValveParamCH;


    initValveParamConfig(&ValveParamCH, Channel_number_7, mode);
    channel.Channel_7 = ValveParamCH;


    initValveParamConfig(&ValveParamCH, Channel_number_8, mode);
    channel.Channel_8 = ValveParamCH;


    initValveParamConfig(&ValveParamCH, Channel_number_9, mode);
    channel.Channel_9 = ValveParamCH;


    initValveParamConfig(&ValveParamCH, Channel_number_10, mode);
    channel.Channel_10 = ValveParamCH;


    initValveParamConfig(&ValveParamCH, Channel_number_11, mode);
    channel.Channel_11 = ValveParamCH;


    initValveParamConfig(&ValveParamCH, Channel_number_12, mode);
    channel.Channel_12 = ValveParamCH;


    initValveParamConfig(&ValveParamCH, Channel_number_13, mode);
    channel.Channel_13 = ValveParamCH;


    initValveParamConfig(&ValveParamCH, Channel_number_14, mode);
    channel.Channel_14 = ValveParamCH;


    initValveParamConfig(&ValveParamCH, Channel_number_15, mode);
    channel.Channel_15 = ValveParamCH;


    initValveParamConfig(&ValveParamCH, Channel_number_16, mode);
    channel.Channel_16 = ValveParamCH;


    initValveParamConfig(&ValveParamCH, Channel_number_17, mode);
    channel.Channel_17 = ValveParamCH;


    initValveParamConfig(&ValveParamCH, Channel_number_18, mode);
    channel.Channel_18 = ValveParamCH;

}


// 将各个通道的值赋给数组
void ParamMap(uint8 CSIndex)
{
    switch(CSIndex){
        case 1:

            x =1;
            y =1;
           PT2000_data_RAM[0]  = channel.Channel_1.IboostB;
           PT2000_data_RAM[1]  = channel.Channel_1.Tbias_tot;
           PT2000_data_RAM[2]  = channel.Channel_1.Tbias_off;
           PT2000_data_RAM[3]  = channel.Channel_1.Ibias;
           PT2000_data_RAM[4]  = channel.Channel_1.IboostP;
           PT2000_data_RAM[5]  = channel.Channel_1.Tpeak_tot;
           PT2000_data_RAM[6]  = channel.Channel_1.Tpeak_off;
           PT2000_data_RAM[7]  = channel.Channel_1.Ipeak;
           PT2000_data_RAM[8]  = channel.Channel_1.Tbypass;
           PT2000_data_RAM[9]  = channel.Channel_1.Thold_tot;
           PT2000_data_RAM[10] = channel.Channel_1.Thold_off;
           PT2000_data_RAM[11] = channel.Channel_1.Ihold;
           PT2000_data_RAM[12] = channel.Channel_1.FWtimeOFF;

           PT2000_data_RAM[32] = channel.Channel_2.IboostB;
           PT2000_data_RAM[33] = channel.Channel_2.Tbias_tot;
           PT2000_data_RAM[34] = channel.Channel_2.Tbias_off;
           PT2000_data_RAM[35] = channel.Channel_2.Ibias;
           PT2000_data_RAM[36] = channel.Channel_2.IboostP;
           PT2000_data_RAM[37] = channel.Channel_2.Tpeak_tot;
           PT2000_data_RAM[38] = channel.Channel_2.Tpeak_off;
           PT2000_data_RAM[39] = channel.Channel_2.Ipeak;
           PT2000_data_RAM[40] = channel.Channel_2.Tbypass;
           PT2000_data_RAM[41] = channel.Channel_2.Thold_tot;
           PT2000_data_RAM[42] = channel.Channel_2.Thold_off;
           PT2000_data_RAM[43] = channel.Channel_2.Ihold;
           PT2000_data_RAM[44] = channel.Channel_2.FWtimeOFF;

           PT2000_data_RAM[64] = channel.Channel_3.IboostB;
           PT2000_data_RAM[65] = channel.Channel_3.Tbias_tot;
           PT2000_data_RAM[66] = channel.Channel_3.Tbias_off;
           PT2000_data_RAM[67] = channel.Channel_3.Ibias;
           PT2000_data_RAM[68] = channel.Channel_3.IboostP;
           PT2000_data_RAM[69] = channel.Channel_3.Tpeak_tot;
           PT2000_data_RAM[70] = channel.Channel_3.Tpeak_off;
           PT2000_data_RAM[71] = channel.Channel_3.Ipeak;
           PT2000_data_RAM[72] = channel.Channel_3.Tbypass;
           PT2000_data_RAM[73] = channel.Channel_3.Thold_tot;
           PT2000_data_RAM[74] = channel.Channel_3.Thold_off;
           PT2000_data_RAM[75] = channel.Channel_3.Ihold;
           PT2000_data_RAM[76] = channel.Channel_3.FWtimeOFF;

           break;

        case 2:
            x =2;
            y =2;
           PT2000_data_RAM[0]  = channel.Channel_4.IboostB;
           PT2000_data_RAM[1]  = channel.Channel_4.Tbias_tot;
           PT2000_data_RAM[2]  = channel.Channel_4.Tbias_off;
           PT2000_data_RAM[3]  = channel.Channel_4.Ibias;
           PT2000_data_RAM[4]  = channel.Channel_4.IboostP;
           PT2000_data_RAM[5]  = channel.Channel_4.Tpeak_tot;
           PT2000_data_RAM[6]  = channel.Channel_4.Tpeak_off;
           PT2000_data_RAM[7]  = channel.Channel_4.Ipeak;
           PT2000_data_RAM[8]  = channel.Channel_4.Tbypass;
           PT2000_data_RAM[9]  = channel.Channel_4.Thold_tot;
           PT2000_data_RAM[10] = channel.Channel_4.Thold_off;
           PT2000_data_RAM[11] = channel.Channel_4.Ihold;
           PT2000_data_RAM[12] = channel.Channel_4.FWtimeOFF;

           PT2000_data_RAM[32] = channel.Channel_5.IboostB;
           PT2000_data_RAM[33] = channel.Channel_5.Tbias_tot;
           PT2000_data_RAM[34] = channel.Channel_5.Tbias_off;
           PT2000_data_RAM[35] = channel.Channel_5.Ibias;
           PT2000_data_RAM[36] = channel.Channel_5.IboostP;
           PT2000_data_RAM[37] = channel.Channel_5.Tpeak_tot;
           PT2000_data_RAM[38] = channel.Channel_5.Tpeak_off;
           PT2000_data_RAM[39] = channel.Channel_5.Ipeak;
           PT2000_data_RAM[40] = channel.Channel_5.Tbypass;
           PT2000_data_RAM[41] = channel.Channel_5.Thold_tot;
           PT2000_data_RAM[42] = channel.Channel_5.Thold_off;
           PT2000_data_RAM[43] = channel.Channel_5.Ihold;
           PT2000_data_RAM[44] = channel.Channel_5.FWtimeOFF;

           PT2000_data_RAM[64] = channel.Channel_6.IboostB;
           PT2000_data_RAM[65] = channel.Channel_6.Tbias_tot;
           PT2000_data_RAM[66] = channel.Channel_6.Tbias_off;
           PT2000_data_RAM[67] = channel.Channel_6.Ibias;
           PT2000_data_RAM[68] = channel.Channel_6.IboostP;
           PT2000_data_RAM[69] = channel.Channel_6.Tpeak_tot;
           PT2000_data_RAM[70] = channel.Channel_6.Tpeak_off;
           PT2000_data_RAM[71] = channel.Channel_6.Ipeak;
           PT2000_data_RAM[72] = channel.Channel_6.Tbypass;
           PT2000_data_RAM[73] = channel.Channel_6.Thold_tot;
           PT2000_data_RAM[74] = channel.Channel_6.Thold_off;
           PT2000_data_RAM[75] = channel.Channel_6.Ihold;
           PT2000_data_RAM[76] = channel.Channel_6.FWtimeOFF;

           break;

        case 3:
            x =3;
            y =3;
            PT2000_data_RAM[0]  = channel.Channel_7.IboostB;
            PT2000_data_RAM[1]  = channel.Channel_7.Tbias_tot;
            PT2000_data_RAM[2]  = channel.Channel_7.Tbias_off;
            PT2000_data_RAM[3]  = channel.Channel_7.Ibias;
            PT2000_data_RAM[4]  = channel.Channel_7.IboostP;
            PT2000_data_RAM[5]  = channel.Channel_7.Tpeak_tot;
            PT2000_data_RAM[6]  = channel.Channel_7.Tpeak_off;
            PT2000_data_RAM[7]  = channel.Channel_7.Ipeak;
            PT2000_data_RAM[8]  = channel.Channel_7.Tbypass;
            PT2000_data_RAM[9]  = channel.Channel_7.Thold_tot;
            PT2000_data_RAM[10] = channel.Channel_7.Thold_off;
            PT2000_data_RAM[11] = channel.Channel_7.Ihold;
            PT2000_data_RAM[12] = channel.Channel_7.FWtimeOFF;

            PT2000_data_RAM[32] = channel.Channel_8.IboostB;
            PT2000_data_RAM[33] = channel.Channel_8.Tbias_tot;
            PT2000_data_RAM[34] = channel.Channel_8.Tbias_off;
            PT2000_data_RAM[35] = channel.Channel_8.Ibias;
            PT2000_data_RAM[36] = channel.Channel_8.IboostP;
            PT2000_data_RAM[37] = channel.Channel_8.Tpeak_tot;
            PT2000_data_RAM[38] = channel.Channel_8.Tpeak_off;
            PT2000_data_RAM[39] = channel.Channel_8.Ipeak;
            PT2000_data_RAM[40] = channel.Channel_8.Tbypass;
            PT2000_data_RAM[41] = channel.Channel_8.Thold_tot;
            PT2000_data_RAM[42] = channel.Channel_8.Thold_off;
            PT2000_data_RAM[43] = channel.Channel_8.Ihold;
            PT2000_data_RAM[44] = channel.Channel_8.FWtimeOFF;

            PT2000_data_RAM[64] = channel.Channel_9.IboostB;
            PT2000_data_RAM[65] = channel.Channel_9.Tbias_tot;
            PT2000_data_RAM[66] = channel.Channel_9.Tbias_off;
            PT2000_data_RAM[67] = channel.Channel_9.Ibias;
            PT2000_data_RAM[68] = channel.Channel_9.IboostP;
            PT2000_data_RAM[69] = channel.Channel_9.Tpeak_tot;
            PT2000_data_RAM[70] = channel.Channel_9.Tpeak_off;
            PT2000_data_RAM[71] = channel.Channel_9.Ipeak;
            PT2000_data_RAM[72] = channel.Channel_9.Tbypass;
            PT2000_data_RAM[73] = channel.Channel_9.Thold_tot;
            PT2000_data_RAM[74] = channel.Channel_9.Thold_off;
            PT2000_data_RAM[75] = channel.Channel_9.Ihold;
            PT2000_data_RAM[76] = channel.Channel_9.FWtimeOFF;

            break;

        case 4:

            x =4;
            y =4;
            PT2000_data_RAM[0]  = channel.Channel_10.IboostB;
            PT2000_data_RAM[1]  = channel.Channel_10.Tbias_tot;
            PT2000_data_RAM[2]  = channel.Channel_10.Tbias_off;
            PT2000_data_RAM[3]  = channel.Channel_10.Ibias;
            PT2000_data_RAM[4]  = channel.Channel_10.IboostP;
            PT2000_data_RAM[5]  = channel.Channel_10.Tpeak_tot;
            PT2000_data_RAM[6]  = channel.Channel_10.Tpeak_off;
            PT2000_data_RAM[7]  = channel.Channel_10.Ipeak;
            PT2000_data_RAM[8]  = channel.Channel_10.Tbypass;
            PT2000_data_RAM[9]  = channel.Channel_10.Thold_tot;
            PT2000_data_RAM[10] = channel.Channel_10.Thold_off;
            PT2000_data_RAM[11] = channel.Channel_10.Ihold;
            PT2000_data_RAM[12] = channel.Channel_10.FWtimeOFF;

            PT2000_data_RAM[32] = channel.Channel_11.IboostB;
            PT2000_data_RAM[33] = channel.Channel_11.Tbias_tot;
            PT2000_data_RAM[34] = channel.Channel_11.Tbias_off;
            PT2000_data_RAM[35] = channel.Channel_11.Ibias;
            PT2000_data_RAM[36] = channel.Channel_11.IboostP;
            PT2000_data_RAM[37] = channel.Channel_11.Tpeak_tot;
            PT2000_data_RAM[38] = channel.Channel_11.Tpeak_off;
            PT2000_data_RAM[39] = channel.Channel_11.Ipeak;
            PT2000_data_RAM[40] = channel.Channel_11.Tbypass;
            PT2000_data_RAM[41] = channel.Channel_11.Thold_tot;
            PT2000_data_RAM[42] = channel.Channel_11.Thold_off;
            PT2000_data_RAM[43] = channel.Channel_11.Ihold;
            PT2000_data_RAM[44] = channel.Channel_11.FWtimeOFF;

            PT2000_data_RAM[64] = channel.Channel_12.IboostB;
            PT2000_data_RAM[65] = channel.Channel_12.Tbias_tot;
            PT2000_data_RAM[66] = channel.Channel_12.Tbias_off;
            PT2000_data_RAM[67] = channel.Channel_12.Ibias;
            PT2000_data_RAM[68] = channel.Channel_12.IboostP;
            PT2000_data_RAM[69] = channel.Channel_12.Tpeak_tot;
            PT2000_data_RAM[70] = channel.Channel_12.Tpeak_off;
            PT2000_data_RAM[71] = channel.Channel_12.Ipeak;
            PT2000_data_RAM[72] = channel.Channel_12.Tbypass;
            PT2000_data_RAM[73] = channel.Channel_12.Thold_tot;
            PT2000_data_RAM[74] = channel.Channel_12.Thold_off;
            PT2000_data_RAM[75] = channel.Channel_12.Ihold;
            PT2000_data_RAM[76] = channel.Channel_12.FWtimeOFF;

            break;

        case 5:

            x =5;
            y =5;
            PT2000_data_RAM[0]  = channel.Channel_13.IboostB;
            PT2000_data_RAM[1]  = channel.Channel_13.Tbias_tot;
            PT2000_data_RAM[2]  = channel.Channel_13.Tbias_off;
            PT2000_data_RAM[3]  = channel.Channel_13.Ibias;
            PT2000_data_RAM[4]  = channel.Channel_13.IboostP;
            PT2000_data_RAM[5]  = channel.Channel_13.Tpeak_tot;
            PT2000_data_RAM[6]  = channel.Channel_13.Tpeak_off;
            PT2000_data_RAM[7]  = channel.Channel_13.Ipeak;
            PT2000_data_RAM[8]  = channel.Channel_13.Tbypass;
            PT2000_data_RAM[9]  = channel.Channel_13.Thold_tot;
            PT2000_data_RAM[10] = channel.Channel_13.Thold_off;
            PT2000_data_RAM[11] = channel.Channel_13.Ihold;
            PT2000_data_RAM[12] = channel.Channel_13.FWtimeOFF;

            PT2000_data_RAM[32] = channel.Channel_14.IboostB;
            PT2000_data_RAM[33] = channel.Channel_14.Tbias_tot;
            PT2000_data_RAM[34] = channel.Channel_14.Tbias_off;
            PT2000_data_RAM[35] = channel.Channel_14.Ibias;
            PT2000_data_RAM[36] = channel.Channel_14.IboostP;
            PT2000_data_RAM[37] = channel.Channel_14.Tpeak_tot;
            PT2000_data_RAM[38] = channel.Channel_14.Tpeak_off;
            PT2000_data_RAM[39] = channel.Channel_14.Ipeak;
            PT2000_data_RAM[40] = channel.Channel_14.Tbypass;
            PT2000_data_RAM[41] = channel.Channel_14.Thold_tot;
            PT2000_data_RAM[42] = channel.Channel_14.Thold_off;
            PT2000_data_RAM[43] = channel.Channel_14.Ihold;
            PT2000_data_RAM[44] = channel.Channel_14.FWtimeOFF;

            PT2000_data_RAM[64] = channel.Channel_15.IboostB;
            PT2000_data_RAM[65] = channel.Channel_15.Tbias_tot;
            PT2000_data_RAM[66] = channel.Channel_15.Tbias_off;
            PT2000_data_RAM[67] = channel.Channel_15.Ibias;
            PT2000_data_RAM[68] = channel.Channel_15.IboostP;
            PT2000_data_RAM[69] = channel.Channel_15.Tpeak_tot;
            PT2000_data_RAM[70] = channel.Channel_15.Tpeak_off;
            PT2000_data_RAM[71] = channel.Channel_15.Ipeak;
            PT2000_data_RAM[72] = channel.Channel_15.Tbypass;
            PT2000_data_RAM[73] = channel.Channel_15.Thold_tot;
            PT2000_data_RAM[74] = channel.Channel_15.Thold_off;
            PT2000_data_RAM[75] = channel.Channel_15.Ihold;
            PT2000_data_RAM[76] = channel.Channel_15.FWtimeOFF;

            break;

        case 6:

            x =6;
            y =6;
            PT2000_data_RAM[0]  = channel.Channel_16.IboostB;
            PT2000_data_RAM[1]  = channel.Channel_16.Tbias_tot;
            PT2000_data_RAM[2]  = channel.Channel_16.Tbias_off;
            PT2000_data_RAM[3]  = channel.Channel_16.Ibias;
            PT2000_data_RAM[4]  = channel.Channel_16.IboostP;
            PT2000_data_RAM[5]  = channel.Channel_16.Tpeak_tot;
            PT2000_data_RAM[6]  = channel.Channel_16.Tpeak_off;
            PT2000_data_RAM[7]  = channel.Channel_16.Ipeak;
            PT2000_data_RAM[8]  = channel.Channel_16.Tbypass;
            PT2000_data_RAM[9]  = channel.Channel_16.Thold_tot;
            PT2000_data_RAM[10] = channel.Channel_16.Thold_off;
            PT2000_data_RAM[11] = channel.Channel_16.Ihold;
            PT2000_data_RAM[12] = channel.Channel_16.FWtimeOFF;

            PT2000_data_RAM[32] = channel.Channel_17.IboostB;
            PT2000_data_RAM[33] = channel.Channel_17.Tbias_tot;
            PT2000_data_RAM[34] = channel.Channel_17.Tbias_off;
            PT2000_data_RAM[35] = channel.Channel_17.Ibias;
            PT2000_data_RAM[36] = channel.Channel_17.IboostP;
            PT2000_data_RAM[37] = channel.Channel_17.Tpeak_tot;
            PT2000_data_RAM[38] = channel.Channel_17.Tpeak_off;
            PT2000_data_RAM[39] = channel.Channel_17.Ipeak;
            PT2000_data_RAM[40] = channel.Channel_17.Tbypass;
            PT2000_data_RAM[41] = channel.Channel_17.Thold_tot;
            PT2000_data_RAM[42] = channel.Channel_17.Thold_off;
            PT2000_data_RAM[43] = channel.Channel_17.Ihold;
            PT2000_data_RAM[44] = channel.Channel_17.FWtimeOFF;

            PT2000_data_RAM[64] = channel.Channel_18.IboostB;
            PT2000_data_RAM[65] = channel.Channel_18.Tbias_tot;
            PT2000_data_RAM[66] = channel.Channel_18.Tbias_off;
            PT2000_data_RAM[67] = channel.Channel_18.Ibias;
            PT2000_data_RAM[68] = channel.Channel_18.IboostP;
            PT2000_data_RAM[69] = channel.Channel_18.Tpeak_tot;
            PT2000_data_RAM[70] = channel.Channel_18.Tpeak_off;
            PT2000_data_RAM[71] = channel.Channel_18.Ipeak;
            PT2000_data_RAM[72] = channel.Channel_18.Tbypass;
            PT2000_data_RAM[73] = channel.Channel_18.Thold_tot;
            PT2000_data_RAM[74] = channel.Channel_18.Thold_off;
            PT2000_data_RAM[75] = channel.Channel_18.Ihold;
            PT2000_data_RAM[76] = channel.Channel_18.FWtimeOFF;

            break;

        default:
            break;
    }
}




// 将各个通道的值赋给数组
void ParamMap1(uint8 CSIndex , uint8 Valve_channel)
{
 //   Set_AllCSPin_High();
 //   QSPI1_SelectNCS(CSIndex);

//
	switch(Valve_channel)
	{
		case 1 :
		{
			channel.Channel_1.IboostB   = 140;
			channel.Channel_1.Tbias_tot =  0;
			channel.Channel_1.Tbias_off = 0 ;
			channel.Channel_1.Ibias =  0;
			channel.Channel_1.IboostP = 0 ;
			channel.Channel_1.Tpeak_tot  = (1500 * 2000) / (channel.Channel_1.Tpeak_tot);
			channel.Channel_1.Tpeak_off =  ((1500 * 2000) / channel.Channel_1.Tpeak_off)/1000;
			current_demarcate_valve_choice(1, channel.Channel_1.Ipeak);
			channel.Channel_1.Tbypass = (1500 * 2000) / (channel.Channel_1.Tbypass);
			channel.Channel_1.Thold_tot = 60000 ;
			channel.Channel_1.Thold_off = ((1500 * 2000) / channel.Channel_1.Thold_off )/1000;
			channel.Channel_1.Ihold = channel.Channel_1.Ipeak - 1 ;
			channel.Channel_1.FWtimeOFF = 0;
            break;
		}

		case 2 :
		{
		    channel.Channel_2.IboostB = 140;
		    channel.Channel_2.Tbias_tot =  0;
		    channel.Channel_2.Tbias_off = 0 ;
		    channel.Channel_2.Ibias =  0;
		    channel.Channel_2.IboostP =0 ;
		    channel.Channel_2.Tpeak_tot  = (1500 * 2000) / (channel.Channel_2.Tpeak_tot);
		    channel.Channel_2.Tpeak_off =  ((1500 * 2000) / channel.Channel_2.Tpeak_off)/1000;
		    current_demarcate_valve_choice(2, channel.Channel_2.Ipeak);
		    channel.Channel_2.Tbypass = (1500 * 2000) / (channel.Channel_2.Tbypass);
		    channel.Channel_2.Thold_tot = 60000 ;
		    channel.Channel_2.Thold_off =  ((1500 * 2000) / channel.Channel_2.Thold_off )/1000;
		    channel.Channel_2.Ihold =  channel.Channel_2.Ipeak - 1 ;
		    channel.Channel_2.FWtimeOFF = 0;
            break;
		}

		case 3 :
		{
		    channel.Channel_3.IboostB = 140;
		    channel.Channel_3.Tbias_tot =  0;
		    channel.Channel_3.Tbias_off = 0 ;
		    channel.Channel_3.Ibias =  0;
		    channel.Channel_3.IboostP =0 ;
		    channel.Channel_3.Tpeak_tot  = (1500 * 2000) / (channel.Channel_3.Tpeak_tot);
		    channel.Channel_3.Tpeak_off =  ((1500 * 2000) / channel.Channel_3.Tpeak_off)/1000;
		    current_demarcate_valve_choice(3, channel.Channel_3.Ipeak);
		    channel.Channel_3.Tbypass = (1500 * 2000) / (channel.Channel_3.Tbypass);
		    channel.Channel_3.Thold_tot = 60000 ;
		    channel.Channel_3.Thold_off =  ((1500 * 2000) / channel.Channel_3.Thold_off )/1000;
		    channel.Channel_3.Ihold =  channel.Channel_3.Ipeak - 1 ;
		    channel.Channel_3.FWtimeOFF = 0;
            break;
		}

		case 4:
		{
		    channel.Channel_4.IboostB = 140;
		    channel.Channel_4.Tbias_tot =  0;
		    channel.Channel_4.Tbias_off = 0 ;
		    channel.Channel_4.Ibias =  0;
		    channel.Channel_4.IboostP =0 ;
		    channel.Channel_4.Tpeak_tot  = (1500 * 2000) / (channel.Channel_4.Tpeak_tot);
		    channel.Channel_4.Tpeak_off =  ((1500 * 2000) / channel.Channel_4.Tpeak_off)/1000;
		    current_demarcate_valve_choice(4, channel.Channel_4.Ipeak);

		    channel.Channel_4.Tbypass = (1500 * 2000) / (channel.Channel_4.Tbypass);
		    channel.Channel_4.Thold_tot = 60000 ;
		    channel.Channel_4.Thold_off =  ((1500 * 2000) / channel.Channel_4.Thold_off )/1000;
		    channel.Channel_4.Ihold =  channel.Channel_4.Ipeak - 1 ;
		    channel.Channel_4.FWtimeOFF = 0;
            break;
		}

		case 5:
		{
		    channel.Channel_5.IboostB = 150;
		    channel.Channel_5.Tbias_tot =  0;
		    channel.Channel_5.Tbias_off = 0 ;
		    channel.Channel_5.Ibias =  0;
		    channel.Channel_5.IboostP =0 ;
		    channel.Channel_5.Tpeak_tot  = (1500 * 2000) / (channel.Channel_5.Tpeak_tot);
		    channel.Channel_5.Tpeak_off =  ((1500 * 2000) / channel.Channel_5.Tpeak_off)/1000;
		    current_demarcate_valve_choice(5, channel.Channel_5.Ipeak);
		    channel.Channel_5.Tbypass = (1500 * 2000) / (channel.Channel_5.Tbypass);
		    channel.Channel_5.Thold_tot = 60000 ;
		    channel.Channel_5.Thold_off =  ((1500 * 2000) / channel.Channel_5.Thold_off )/1000;
		    channel.Channel_5.Ihold =  channel.Channel_5.Ipeak - 1 ;
		    channel.Channel_5.FWtimeOFF = 0;
            break;
		}

		case 6 :
		{
		    channel.Channel_6.IboostB = 160;
		    channel.Channel_6.Tbias_tot =  0;
		    channel.Channel_6.Tbias_off = 0 ;
		    channel.Channel_6.Ibias =  0;
		    channel.Channel_6.IboostP =0 ;
		    channel.Channel_6.Tpeak_tot  = (1500 * 2000) / (channel.Channel_6.Tpeak_tot);
		    channel.Channel_6.Tpeak_off =  ((1500 * 2000) / channel.Channel_6.Tpeak_off)/1000;
		    current_demarcate_valve_choice(6, channel.Channel_6.Ipeak);
		    channel.Channel_6.Ipeak = channel.Channel_6.Ipeak - 1;
		    channel.Channel_6.Tbypass = (1500 * 2000) / (channel.Channel_6.Tbypass);
		    channel.Channel_6.Thold_tot = 60000 ;
		    channel.Channel_6.Thold_off =  ((1500 * 2000) / channel.Channel_6.Thold_off )/1000;
		    channel.Channel_6.Ihold =  channel.Channel_6.Ipeak - 1 ;
		    channel.Channel_6.FWtimeOFF = 0;
            break;
		}

		case 7 :
		{
		    channel.Channel_7.IboostB = 140;
		    channel.Channel_7.Tbias_tot =  0;
		    channel.Channel_7.Tbias_off = 0 ;
		    channel.Channel_7.Ibias =  0;
		    channel.Channel_7.IboostP =0 ;
		    channel.Channel_7.Tpeak_tot  = (1500 * 2000) / (channel.Channel_7.Tpeak_tot);
		    channel.Channel_7.Tpeak_off =  ((1500 * 2000) / channel.Channel_7.Tpeak_off)/1000;
		    current_demarcate_valve_choice(7, channel.Channel_7.Ipeak);
		    channel.Channel_7.Tbypass = (1500 * 2000) / (channel.Channel_7.Tbypass);
		    channel.Channel_7.Thold_tot = 60000 ;
		    channel.Channel_7.Thold_off =  ((1500 * 2000) / channel.Channel_7.Thold_off )/1000;
		    channel.Channel_7.Ihold =  (channel.Channel_7.Ipeak) - 1 ;
		    channel.Channel_7.FWtimeOFF = 0;
            break;
		}

		case 8 :
		{
		    channel.Channel_8.IboostB = 140;
		    channel.Channel_8.Tbias_tot =  0;
		    channel.Channel_8.Tbias_off = 0 ;
		    channel.Channel_8.Ibias =  0;
		    channel.Channel_8.IboostP =0 ;
		    channel.Channel_8.Tpeak_tot  = (1500 * 2000) / (channel.Channel_8.Tpeak_tot);
		    channel.Channel_8.Tpeak_off =  ((1500 * 2000) / channel.Channel_8.Tpeak_off)/1000;
		    current_demarcate_valve_choice(8, channel.Channel_8.Ipeak);
		    channel.Channel_8.Tbypass = (1500 * 2000) / (channel.Channel_8.Tbypass);
		    channel.Channel_8.Thold_tot = 60000 ;
		    channel.Channel_8.Thold_off =  ((1500 * 2000) / channel.Channel_8.Thold_off )/1000;
		    channel.Channel_8.Ihold =  channel.Channel_8.Ipeak - 1 ;
		    channel.Channel_8.FWtimeOFF = 0;
            break;
		}

		case 9:
		{
		    channel.Channel_9.IboostB = 140;
		    channel.Channel_9.Tbias_tot =  0;
		    channel.Channel_9.Tbias_off = 0 ;
		    channel.Channel_9.Ibias =  0;
		    channel.Channel_9.IboostP =0 ;
		    channel.Channel_9.Tpeak_tot  = (1500 * 2000) / (channel.Channel_9.Tpeak_tot);
		    channel.Channel_9.Tpeak_off =  ((1500 * 2000) / channel.Channel_9.Tpeak_off)/1000;
		    current_demarcate_valve_choice(9, channel.Channel_9.Ipeak);
		    channel.Channel_9.Tbypass = (1500 * 2000) / (channel.Channel_9.Tbypass);
		    channel.Channel_9.Thold_tot = 60000 ;
		    channel.Channel_9.Thold_off =  ((1500 * 2000) / channel.Channel_9.Thold_off )/1000;
		    channel.Channel_9.Ihold =  channel.Channel_9.Ipeak - 1 ;
		    channel.Channel_9.FWtimeOFF = 0;
            break;
		}

		case 10 :
		{
		    channel.Channel_10.IboostB = 140;
		    channel.Channel_10.Tbias_tot =  0;
		    channel.Channel_10.Tbias_off = 0 ;
		    channel.Channel_10.Ibias =  0;
		    channel.Channel_10.IboostP =0 ;
		    channel.Channel_10.Tpeak_tot  = (1500 * 2000) / (channel.Channel_10.Tpeak_tot);
		    channel.Channel_10.Tpeak_off =  ((1500 * 2000) / channel.Channel_10.Tpeak_off)/1000;
		    current_demarcate_valve_choice(10, channel.Channel_10.Ipeak);
		    channel.Channel_10.Tbypass = (1500 * 2000) / (channel.Channel_10.Tbypass);
		    channel.Channel_10.Thold_tot = 60000 ;
		    channel.Channel_10.Thold_off =  ((1500 * 2000) / channel.Channel_10.Thold_off )/1000;
		    channel.Channel_10.Ihold =    channel.Channel_10.Ipeak - 1 ;
		    channel.Channel_10.FWtimeOFF = 0;
            break;
		}

		case 11:
		{
		    channel.Channel_11.IboostB = 140;
		    channel.Channel_11.Tbias_tot =  0;
		    channel.Channel_11.Tbias_off = 0 ;
		    channel.Channel_11.Ibias =  0;
		    channel.Channel_11.IboostP =0 ;
		    channel.Channel_11.Tpeak_tot  = (1500 * 2000) / (channel.Channel_11.Tpeak_tot);
		    channel.Channel_11.Tpeak_off =  ((1500 * 2000) / channel.Channel_11.Tpeak_off)/1000;
		    current_demarcate_valve_choice(11, channel.Channel_11.Ipeak);
		    channel.Channel_11.Tbypass = (1500 * 2000) / (channel.Channel_11.Tbypass);
		    channel.Channel_11.Thold_tot = 60000 ;
		    channel.Channel_11.Thold_off =  ((1500 * 2000) / channel.Channel_11.Thold_off )/1000;
		    channel.Channel_11.Ihold =  channel.Channel_11.Ipeak - 1 ;
		    channel.Channel_11.FWtimeOFF = 0;
            break;
		}

		case 12 :
		{
		    channel.Channel_12.IboostB = 140;
		    channel.Channel_12.Tbias_tot =  0;
		    channel.Channel_12.Tbias_off = 0 ;
		    channel.Channel_12.Ibias =  0;
		    channel.Channel_12.IboostP =0 ;
		    channel.Channel_12.Tpeak_tot  = (1500 * 2000) / (channel.Channel_12.Tpeak_tot);
		    channel.Channel_12.Tpeak_off =  ((1500 * 2000) / channel.Channel_12.Tpeak_off)/1000;
		    current_demarcate_valve_choice(12, channel.Channel_12.Ipeak);
		    channel.Channel_12.Tbypass = (1500 * 2000) / (channel.Channel_12.Tbypass);
		    channel.Channel_12.Thold_tot = 60000 ;
		    channel.Channel_12.Thold_off =  ((1500 * 2000) / channel.Channel_12.Thold_off )/1000;
		    channel.Channel_12.Ihold =  channel.Channel_12.Ipeak - 1 ;
		    channel.Channel_12.FWtimeOFF = 0;
            break;
		}

		case 13 :
		{
		    channel.Channel_13.IboostB = 140;
		    channel.Channel_13.Tbias_tot =  0;
		    channel.Channel_13.Tbias_off = 0 ;
		    channel.Channel_13.Ibias =  0;
		    channel.Channel_13.IboostP =0 ;
		    channel.Channel_13.Tpeak_tot  = (1500 * 2000) / (channel.Channel_13.Tpeak_tot);
		    channel.Channel_13.Tpeak_off =  ((1500 * 2000) / channel.Channel_13.Tpeak_off)/1000;
		    current_demarcate_valve_choice(13, channel.Channel_13.Ipeak);
		    channel.Channel_13.Tbypass = (1500 * 2000) / (channel.Channel_13.Tbypass);
		    channel.Channel_13.Thold_tot = 60000 ;
		    channel.Channel_13.Thold_off =  ((1500 * 2000) / channel.Channel_13.Thold_off )/1000;
		    channel.Channel_13.Ihold =  channel.Channel_13.Ipeak - 1 ;
		    channel.Channel_13.FWtimeOFF = 0;
            break;
		}

		case 14 :
		{
		    channel.Channel_14.IboostB = 140;
		    channel.Channel_14.Tbias_tot =  0;
		    channel.Channel_14.Tbias_off = 0 ;
		    channel.Channel_14.Ibias =  0;
		    channel.Channel_14.IboostP =0 ;
		    channel.Channel_14.Tpeak_tot  = (1500 * 2000) / (channel.Channel_14.Tpeak_tot);
		    channel.Channel_14.Tpeak_off =  ((1500 * 2000) / channel.Channel_14.Tpeak_off)/1000;
		    current_demarcate_valve_choice(14, channel.Channel_14.Ipeak);
		    channel.Channel_14.Tbypass = (1500 * 2000) / (channel.Channel_14.Tbypass);
		    channel.Channel_14.Thold_tot = 60000 ;
		    channel.Channel_14.Thold_off =  ((1500 * 2000) / channel.Channel_14.Thold_off )/1000;
		    channel.Channel_14.Ihold =  channel.Channel_14.Ipeak - 1 ;
		    channel.Channel_14.FWtimeOFF = 0;
		    break;
		}

		case 15:
		{
		    channel.Channel_15.IboostB = 140;
		    channel.Channel_15.Tbias_tot =  0;
		    channel.Channel_15.Tbias_off = 0 ;
		    channel.Channel_15.Ibias =  0;
		    channel.Channel_15.IboostP =0 ;
		    channel.Channel_15.Tpeak_tot  = (1500 * 2000) / (channel.Channel_15.Tpeak_tot);
		    channel.Channel_15.Tpeak_off =  ((1500 * 2000) / channel.Channel_15.Tpeak_off)/1000;
		    current_demarcate_valve_choice(15, channel.Channel_15.Ipeak);
		    channel.Channel_15.Tbypass = (1500 * 2000) / (channel.Channel_15.Tbypass);
		    channel.Channel_15.Thold_tot = 60000 ;
		    channel.Channel_15.Thold_off =  ((1500 * 2000) / channel.Channel_15.Thold_off )/1000;
		    channel.Channel_15.Ihold =  channel.Channel_15.Ipeak - 1 ;
		    channel.Channel_15.FWtimeOFF = 0;
            break;
		}

		case 16:
		{
		    channel.Channel_16.IboostB = 140;
		    channel.Channel_16.Tbias_tot =  0;
		    channel.Channel_16.Tbias_off = 0 ;
		    channel.Channel_16.Ibias =  0;
		    channel.Channel_16.IboostP =0 ;
		    channel.Channel_16.Tpeak_tot  = (1500 * 2000) / (channel.Channel_16.Tpeak_tot);
		    channel.Channel_16.Tpeak_off =  ((1500 * 2000) / channel.Channel_16.Tpeak_off)/1000;
		    current_demarcate_valve_choice(16, channel.Channel_16.Ipeak);
		    channel.Channel_16.Tbypass = (1500 * 2000) / (channel.Channel_16.Tbypass);
		    channel.Channel_16.Thold_tot = 60000 ;
		    channel.Channel_16.Thold_off =  ((1500 * 2000) / channel.Channel_16.Thold_off )/1000;
		    channel.Channel_16.Ihold =  channel.Channel_16.Ipeak - 1 ;
		    channel.Channel_16.FWtimeOFF = 0;
            break;

		}

        default:
            break;
	}








    switch(CSIndex){
        case 1:

            x = 1;
            y = 1;
           PT2000_data_RAM[0]  = channel.Channel_1.IboostB;
           PT2000_data_RAM[1]  = channel.Channel_1.Tbias_tot;
           PT2000_data_RAM[2]  = channel.Channel_1.Tbias_off;
           PT2000_data_RAM[3]  = channel.Channel_1.Ibias;
           PT2000_data_RAM[4]  = channel.Channel_1.IboostP;
           PT2000_data_RAM[5]  = channel.Channel_1.Tpeak_tot;
           PT2000_data_RAM[6]  = channel.Channel_1.Tpeak_off;
           PT2000_data_RAM[7]  = channel.Channel_1.Ipeak;
           PT2000_data_RAM[8]  = channel.Channel_1.Tbypass;
           PT2000_data_RAM[9]  = channel.Channel_1.Thold_tot;
           PT2000_data_RAM[10] = channel.Channel_1.Thold_off;
           PT2000_data_RAM[11] = channel.Channel_1.Ihold;
           PT2000_data_RAM[12] = channel.Channel_1.FWtimeOFF;

           PT2000_data_RAM[32] = channel.Channel_2.IboostB;
           PT2000_data_RAM[33] = channel.Channel_2.Tbias_tot;
           PT2000_data_RAM[34] = channel.Channel_2.Tbias_off;
           PT2000_data_RAM[35] = channel.Channel_2.Ibias;
           PT2000_data_RAM[36] = channel.Channel_2.IboostP;
           PT2000_data_RAM[37] = channel.Channel_2.Tpeak_tot;
           PT2000_data_RAM[38] = channel.Channel_2.Tpeak_off;
           PT2000_data_RAM[39] = channel.Channel_2.Ipeak;
           PT2000_data_RAM[40] = channel.Channel_2.Tbypass;
           PT2000_data_RAM[41] = channel.Channel_2.Thold_tot;
           PT2000_data_RAM[42] = channel.Channel_2.Thold_off;
           PT2000_data_RAM[43] = channel.Channel_2.Ihold;
           PT2000_data_RAM[44] = channel.Channel_2.FWtimeOFF;

           PT2000_data_RAM[64] = channel.Channel_3.IboostB;
           PT2000_data_RAM[65] = channel.Channel_3.Tbias_tot;
           PT2000_data_RAM[66] = channel.Channel_3.Tbias_off;
           PT2000_data_RAM[67] = channel.Channel_3.Ibias;
           PT2000_data_RAM[68] = channel.Channel_3.IboostP;
           PT2000_data_RAM[69] = channel.Channel_3.Tpeak_tot;
           PT2000_data_RAM[70] = channel.Channel_3.Tpeak_off;
           PT2000_data_RAM[71] = channel.Channel_3.Ipeak;
           PT2000_data_RAM[72] = channel.Channel_3.Tbypass;
           PT2000_data_RAM[73] = channel.Channel_3.Thold_tot;
           PT2000_data_RAM[74] = channel.Channel_3.Thold_off;
           PT2000_data_RAM[75] = channel.Channel_3.Ihold;
           PT2000_data_RAM[76] = channel.Channel_3.FWtimeOFF;

           break;

        case 2:

            x = 2;
            y = 2;
           PT2000_data_RAM[0]  = channel.Channel_4.IboostB;
           PT2000_data_RAM[1]  = channel.Channel_4.Tbias_tot;
           PT2000_data_RAM[2]  = channel.Channel_4.Tbias_off;
           PT2000_data_RAM[3]  = channel.Channel_4.Ibias;
           PT2000_data_RAM[4]  = channel.Channel_4.IboostP;
           PT2000_data_RAM[5]  = channel.Channel_4.Tpeak_tot;
           PT2000_data_RAM[6]  = channel.Channel_4.Tpeak_off;
           PT2000_data_RAM[7]  = channel.Channel_4.Ipeak;
           PT2000_data_RAM[8]  = channel.Channel_4.Tbypass;
           PT2000_data_RAM[9]  = channel.Channel_4.Thold_tot;
           PT2000_data_RAM[10] = channel.Channel_4.Thold_off;
           PT2000_data_RAM[11] = channel.Channel_4.Ihold;
           PT2000_data_RAM[12] = channel.Channel_4.FWtimeOFF;

           PT2000_data_RAM[32] = channel.Channel_5.IboostB;
           PT2000_data_RAM[33] = channel.Channel_5.Tbias_tot;
           PT2000_data_RAM[34] = channel.Channel_5.Tbias_off;
           PT2000_data_RAM[35] = channel.Channel_5.Ibias;
           PT2000_data_RAM[36] = channel.Channel_5.IboostP;
           PT2000_data_RAM[37] = channel.Channel_5.Tpeak_tot;
           PT2000_data_RAM[38] = channel.Channel_5.Tpeak_off;
           PT2000_data_RAM[39] = channel.Channel_5.Ipeak;
           PT2000_data_RAM[40] = channel.Channel_5.Tbypass;
           PT2000_data_RAM[41] = channel.Channel_5.Thold_tot;
           PT2000_data_RAM[42] = channel.Channel_5.Thold_off;
           PT2000_data_RAM[43] = channel.Channel_5.Ihold;
           PT2000_data_RAM[44] = channel.Channel_5.FWtimeOFF;

           PT2000_data_RAM[64] = channel.Channel_6.IboostB;
           PT2000_data_RAM[65] = channel.Channel_6.Tbias_tot;
           PT2000_data_RAM[66] = channel.Channel_6.Tbias_off;
           PT2000_data_RAM[67] = channel.Channel_6.Ibias;
           PT2000_data_RAM[68] = channel.Channel_6.IboostP;
           PT2000_data_RAM[69] = channel.Channel_6.Tpeak_tot;
           PT2000_data_RAM[70] = channel.Channel_6.Tpeak_off;
           PT2000_data_RAM[71] = channel.Channel_6.Ipeak;
           PT2000_data_RAM[72] = channel.Channel_6.Tbypass;
           PT2000_data_RAM[73] = channel.Channel_6.Thold_tot;
           PT2000_data_RAM[74] = channel.Channel_6.Thold_off;
           PT2000_data_RAM[75] = channel.Channel_6.Ihold;
           PT2000_data_RAM[76] = channel.Channel_6.FWtimeOFF;

           break;

        case 3:

            x = 3;
            y = 3;
            PT2000_data_RAM[0]  = channel.Channel_7.IboostB;
            PT2000_data_RAM[1]  = channel.Channel_7.Tbias_tot;
            PT2000_data_RAM[2]  = channel.Channel_7.Tbias_off;
            PT2000_data_RAM[3]  = channel.Channel_7.Ibias;
            PT2000_data_RAM[4]  = channel.Channel_7.IboostP;
            PT2000_data_RAM[5]  = channel.Channel_7.Tpeak_tot;
            PT2000_data_RAM[6]  = channel.Channel_7.Tpeak_off;
            PT2000_data_RAM[7]  = channel.Channel_7.Ipeak;
            PT2000_data_RAM[8]  = channel.Channel_7.Tbypass;
            PT2000_data_RAM[9]  = channel.Channel_7.Thold_tot;
            PT2000_data_RAM[10] = channel.Channel_7.Thold_off;
            PT2000_data_RAM[11] = channel.Channel_7.Ihold;
            PT2000_data_RAM[12] = channel.Channel_7.FWtimeOFF;

            PT2000_data_RAM[32] = channel.Channel_8.IboostB;
            PT2000_data_RAM[33] = channel.Channel_8.Tbias_tot;
            PT2000_data_RAM[34] = channel.Channel_8.Tbias_off;
            PT2000_data_RAM[35] = channel.Channel_8.Ibias;
            PT2000_data_RAM[36] = channel.Channel_8.IboostP;
            PT2000_data_RAM[37] = channel.Channel_8.Tpeak_tot;
            PT2000_data_RAM[38] = channel.Channel_8.Tpeak_off;
            PT2000_data_RAM[39] = channel.Channel_8.Ipeak;
            PT2000_data_RAM[40] = channel.Channel_8.Tbypass;
            PT2000_data_RAM[41] = channel.Channel_8.Thold_tot;
            PT2000_data_RAM[42] = channel.Channel_8.Thold_off;
            PT2000_data_RAM[43] = channel.Channel_8.Ihold;
            PT2000_data_RAM[44] = channel.Channel_8.FWtimeOFF;

            PT2000_data_RAM[64] = channel.Channel_9.IboostB;
            PT2000_data_RAM[65] = channel.Channel_9.Tbias_tot;
            PT2000_data_RAM[66] = channel.Channel_9.Tbias_off;
            PT2000_data_RAM[67] = channel.Channel_9.Ibias;
            PT2000_data_RAM[68] = channel.Channel_9.IboostP;
            PT2000_data_RAM[69] = channel.Channel_9.Tpeak_tot;
            PT2000_data_RAM[70] = channel.Channel_9.Tpeak_off;
            PT2000_data_RAM[71] = channel.Channel_9.Ipeak;
            PT2000_data_RAM[72] = channel.Channel_9.Tbypass;
            PT2000_data_RAM[73] = channel.Channel_9.Thold_tot;
            PT2000_data_RAM[74] = channel.Channel_9.Thold_off;
            PT2000_data_RAM[75] = channel.Channel_9.Ihold;
            PT2000_data_RAM[76] = channel.Channel_9.FWtimeOFF;

            break;

        case 4:
            x = 4;
            y = 4;
            PT2000_data_RAM[0]  = channel.Channel_10.IboostB;
            PT2000_data_RAM[1]  = channel.Channel_10.Tbias_tot;
            PT2000_data_RAM[2]  = channel.Channel_10.Tbias_off;
            PT2000_data_RAM[3]  = channel.Channel_10.Ibias;
            PT2000_data_RAM[4]  = channel.Channel_10.IboostP;
            PT2000_data_RAM[5]  = channel.Channel_10.Tpeak_tot;
            PT2000_data_RAM[6]  = channel.Channel_10.Tpeak_off;
            PT2000_data_RAM[7]  = channel.Channel_10.Ipeak;
            PT2000_data_RAM[8]  = channel.Channel_10.Tbypass;
            PT2000_data_RAM[9]  = channel.Channel_10.Thold_tot;
            PT2000_data_RAM[10] = channel.Channel_10.Thold_off;
            PT2000_data_RAM[11] = channel.Channel_10.Ihold;
            PT2000_data_RAM[12] = channel.Channel_10.FWtimeOFF;


            PT2000_data_RAM[32] = channel.Channel_11.IboostB;
            PT2000_data_RAM[33] = channel.Channel_11.Tbias_tot;
            PT2000_data_RAM[34] = channel.Channel_11.Tbias_off;
            PT2000_data_RAM[35] = channel.Channel_11.Ibias;
            PT2000_data_RAM[36] = channel.Channel_11.IboostP;
            PT2000_data_RAM[37] = channel.Channel_11.Tpeak_tot;
            PT2000_data_RAM[38] = channel.Channel_11.Tpeak_off;
            PT2000_data_RAM[39] = channel.Channel_11.Ipeak;
            PT2000_data_RAM[40] = channel.Channel_11.Tbypass;
            PT2000_data_RAM[41] = channel.Channel_11.Thold_tot;
            PT2000_data_RAM[42] = channel.Channel_11.Thold_off;
            PT2000_data_RAM[43] = channel.Channel_11.Ihold;
            PT2000_data_RAM[44] = channel.Channel_11.FWtimeOFF;

            PT2000_data_RAM[64] = channel.Channel_12.IboostB;
            PT2000_data_RAM[65] = channel.Channel_12.Tbias_tot;
            PT2000_data_RAM[66] = channel.Channel_12.Tbias_off;
            PT2000_data_RAM[67] = channel.Channel_12.Ibias;
            PT2000_data_RAM[68] = channel.Channel_12.IboostP;
            PT2000_data_RAM[69] = channel.Channel_12.Tpeak_tot;
            PT2000_data_RAM[70] = channel.Channel_12.Tpeak_off;
            PT2000_data_RAM[71] = channel.Channel_12.Ipeak;
            PT2000_data_RAM[72] = channel.Channel_12.Tbypass;
            PT2000_data_RAM[73] = channel.Channel_12.Thold_tot;
            PT2000_data_RAM[74] = channel.Channel_12.Thold_off;
            PT2000_data_RAM[75] = channel.Channel_12.Ihold;
            PT2000_data_RAM[76] = channel.Channel_12.FWtimeOFF;

            break;

        case 5:
            x = 5;
            y = 5;


            PT2000_data_RAM[32] = channel.Channel_14.IboostB;
            PT2000_data_RAM[33] = channel.Channel_14.Tbias_tot;
            PT2000_data_RAM[34] = channel.Channel_14.Tbias_off;
            PT2000_data_RAM[35] = channel.Channel_14.Ibias;
            PT2000_data_RAM[36] = channel.Channel_14.IboostP;
            PT2000_data_RAM[37] = channel.Channel_14.Tpeak_tot;
            PT2000_data_RAM[38] = channel.Channel_14.Tpeak_off;
            PT2000_data_RAM[39] = channel.Channel_14.Ipeak;
            PT2000_data_RAM[40] = channel.Channel_14.Tbypass;
            PT2000_data_RAM[41] = channel.Channel_14.Thold_tot;
            PT2000_data_RAM[42] = channel.Channel_14.Thold_off;
            PT2000_data_RAM[43] = channel.Channel_14.Ihold;
            PT2000_data_RAM[44] = channel.Channel_14.FWtimeOFF;

            PT2000_data_RAM[64] = channel.Channel_15.IboostB;
            PT2000_data_RAM[65] = channel.Channel_15.Tbias_tot;
            PT2000_data_RAM[66] = channel.Channel_15.Tbias_off;
            PT2000_data_RAM[67] = channel.Channel_15.Ibias;
            PT2000_data_RAM[68] = channel.Channel_15.IboostP;
            PT2000_data_RAM[69] = channel.Channel_15.Tpeak_tot;
            PT2000_data_RAM[70] = channel.Channel_15.Tpeak_off;
            PT2000_data_RAM[71] = channel.Channel_15.Ipeak;
            PT2000_data_RAM[72] = channel.Channel_15.Tbypass;
            PT2000_data_RAM[73] = channel.Channel_15.Thold_tot;
            PT2000_data_RAM[74] = channel.Channel_15.Thold_off;
            PT2000_data_RAM[75] = channel.Channel_15.Ihold;
            PT2000_data_RAM[76] = channel.Channel_15.FWtimeOFF;

            break;

        case 6:

            x = 6;
            y = 6;


            PT2000_data_RAM[32] = channel.Channel_13.IboostB;
            PT2000_data_RAM[33] = channel.Channel_13.Tbias_tot;
            PT2000_data_RAM[34] = channel.Channel_13.Tbias_off;
            PT2000_data_RAM[35] = channel.Channel_13.Ibias;
            PT2000_data_RAM[36] = channel.Channel_13.IboostP;
            PT2000_data_RAM[37] = channel.Channel_13.Tpeak_tot;
            PT2000_data_RAM[38] = channel.Channel_13.Tpeak_off;
            PT2000_data_RAM[39] = channel.Channel_13.Ipeak;
            PT2000_data_RAM[40] = channel.Channel_13.Tbypass;
            PT2000_data_RAM[41] = channel.Channel_13.Thold_tot;
            PT2000_data_RAM[42] = channel.Channel_13.Thold_off;
            PT2000_data_RAM[43] = channel.Channel_13.Ihold;
            PT2000_data_RAM[44] = channel.Channel_13.FWtimeOFF;

            PT2000_data_RAM[64] = channel.Channel_16.IboostB;
            PT2000_data_RAM[65] = channel.Channel_16.Tbias_tot;
            PT2000_data_RAM[66] = channel.Channel_16.Tbias_off;
            PT2000_data_RAM[67] = channel.Channel_16.Ibias;
            PT2000_data_RAM[68] = channel.Channel_16.IboostP;
            PT2000_data_RAM[69] = channel.Channel_16.Tpeak_tot;
            PT2000_data_RAM[70] = channel.Channel_16.Tpeak_off;
            PT2000_data_RAM[71] = channel.Channel_16.Ipeak;
            PT2000_data_RAM[72] = channel.Channel_16.Tbypass;
            PT2000_data_RAM[73] = channel.Channel_16.Thold_tot;
            PT2000_data_RAM[74] = channel.Channel_16.Thold_off;
            PT2000_data_RAM[75] = channel.Channel_16.Ihold;
            PT2000_data_RAM[76] = channel.Channel_16.FWtimeOFF;

            break;

        default:
            break;
    }
}



//Peak_Hold 濡€崇础閺佹壆绮嶇挧瀣拷锟�
void Set_Peak_Hold(uint8 ChannelID, uint16 iboostB, uint16 tbias_tot, uint16 tbias_off, uint16 ibias, uint16 iboostP,
                    uint16 tpeak_tot, uint16 tpeak_off, uint16 ipeak, uint16 tbypass, uint16 thold_tot, uint16 thold_off,
                    uint16 ihold, uint16 fwtimeOFF)
{

	if(B_current_change == 0)
	{
    switch(ChannelID){
        case Channel_number_1:
            channel.Channel_1.IboostB = iboostB;
            channel.Channel_1.Tbias_tot = tbias_tot;
            channel.Channel_1.Tbias_off = tbias_off;
            channel.Channel_1.Ibias = ibias;
            channel.Channel_1.IboostP = iboostP;
            channel.Channel_1.Tpeak_tot = tpeak_tot;
            channel.Channel_1.Tpeak_off = tpeak_off;
            channel.Channel_1.Ipeak = ipeak;
            channel.Channel_1.Tbypass = tbypass;
            channel.Channel_1.Thold_tot = thold_tot;
            channel.Channel_1.Thold_off = thold_off;
            channel.Channel_1.Ihold = ihold;
            channel.Channel_1.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_2:
            channel.Channel_2.IboostB = iboostB;
            channel.Channel_2.Tbias_tot = tbias_tot;
            channel.Channel_2.Tbias_off = tbias_off;
            channel.Channel_2.Ibias = ibias;
            channel.Channel_2.IboostP = iboostP;
            channel.Channel_2.Tpeak_tot = tpeak_tot;
            channel.Channel_2.Tpeak_off = tpeak_off;
            channel.Channel_2.Ipeak = ipeak;
            channel.Channel_2.Tbypass = tbypass;
            channel.Channel_2.Thold_tot = thold_tot;
            channel.Channel_2.Thold_off = thold_off;
            channel.Channel_2.Ihold = ihold;
            channel.Channel_2.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_3:
            channel.Channel_3.IboostB = iboostB;
            channel.Channel_3.Tbias_tot = tbias_tot;
            channel.Channel_3.Tbias_off = tbias_off;
            channel.Channel_3.Ibias = ibias;
            channel.Channel_3.IboostP = iboostP;
            channel.Channel_3.Tpeak_tot = tpeak_tot;
            channel.Channel_3.Tpeak_off = tpeak_off;
            channel.Channel_3.Ipeak = ipeak;
            channel.Channel_3.Tbypass = tbypass;
            channel.Channel_3.Thold_tot = thold_tot;
            channel.Channel_3.Thold_off = thold_off;
            channel.Channel_3.Ihold = ihold;
            channel.Channel_3.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_4:
            channel.Channel_4.IboostB = iboostB;
            channel.Channel_4.Tbias_tot = tbias_tot;
            channel.Channel_4.Tbias_off = tbias_off;
            channel.Channel_4.Ibias = ibias;
            channel.Channel_4.IboostP = iboostP;
            channel.Channel_4.Tpeak_tot = tpeak_tot;
            channel.Channel_4.Tpeak_off = tpeak_off;
            channel.Channel_4.Ipeak = ipeak;
            channel.Channel_4.Tbypass = tbypass;
            channel.Channel_4.Thold_tot = thold_tot;
            channel.Channel_4.Thold_off = thold_off;
            channel.Channel_4.Ihold = ihold;
            channel.Channel_4.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_5:
            channel.Channel_5.IboostB = iboostB;
            channel.Channel_5.Tbias_tot = tbias_tot;
            channel.Channel_5.Tbias_off = tbias_off;
            channel.Channel_5.Ibias = ibias;
            channel.Channel_5.IboostP = iboostP;
            channel.Channel_5.Tpeak_tot = tpeak_tot;
            channel.Channel_5.Tpeak_off = tpeak_off;
            channel.Channel_5.Ipeak = ipeak;
            channel.Channel_5.Tbypass = tbypass;
            channel.Channel_5.Thold_tot = thold_tot;
            channel.Channel_5.Thold_off = thold_off;
            channel.Channel_5.Ihold = ihold;
            channel.Channel_5.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_6:
            channel.Channel_6.IboostB = iboostB;
            channel.Channel_6.Tbias_tot = tbias_tot;
            channel.Channel_6.Tbias_off = tbias_off;
            channel.Channel_6.Ibias = ibias;
            channel.Channel_6.IboostP = iboostP;
            channel.Channel_6.Tpeak_tot = tpeak_tot;
            channel.Channel_6.Tpeak_off = tpeak_off;
            channel.Channel_6.Ipeak = ipeak;
            channel.Channel_6.Tbypass = tbypass;
            channel.Channel_6.Thold_tot = thold_tot;
            channel.Channel_6.Thold_off = thold_off;
            channel.Channel_6.Ihold = ihold;
            channel.Channel_6.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_7:
            channel.Channel_7.IboostB = iboostB;
            channel.Channel_7.Tbias_tot = tbias_tot;
            channel.Channel_7.Tbias_off = tbias_off;
            channel.Channel_7.Ibias = ibias;
            channel.Channel_7.IboostP = iboostP;
            channel.Channel_7.Tpeak_tot = tpeak_tot;
            channel.Channel_7.Tpeak_off = tpeak_off;
            channel.Channel_7.Ipeak = ipeak;
            channel.Channel_7.Tbypass = tbypass;
            channel.Channel_7.Thold_tot = thold_tot;
            channel.Channel_7.Thold_off = thold_off;
            channel.Channel_7.Ihold = ihold;
            channel.Channel_7.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_8:
            channel.Channel_8.IboostB = iboostB;
            channel.Channel_8.Tbias_tot = tbias_tot;
            channel.Channel_8.Tbias_off = tbias_off;
            channel.Channel_8.Ibias = ibias;
            channel.Channel_8.IboostP = iboostP;
            channel.Channel_8.Tpeak_tot = tpeak_tot;
            channel.Channel_8.Tpeak_off = tpeak_off;
            channel.Channel_8.Ipeak = ipeak;
            channel.Channel_8.Tbypass = tbypass;
            channel.Channel_8.Thold_tot = thold_tot;
            channel.Channel_8.Thold_off = thold_off;
            channel.Channel_8.Ihold = ihold;
            channel.Channel_8.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_9:
            channel.Channel_9.IboostB = iboostB;
            channel.Channel_9.Tbias_tot = tbias_tot;
            channel.Channel_9.Tbias_off = tbias_off;
            channel.Channel_9.Ibias = ibias;
            channel.Channel_9.IboostP = iboostP;
            channel.Channel_9.Tpeak_tot = tpeak_tot;
            channel.Channel_9.Tpeak_off = tpeak_off;
            channel.Channel_9.Ipeak = ipeak;
            channel.Channel_9.Tbypass = tbypass;
            channel.Channel_9.Thold_tot = thold_tot;
            channel.Channel_9.Thold_off = thold_off;
            channel.Channel_9.Ihold = ihold;
            channel.Channel_9.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_10:
            channel.Channel_10.IboostB = iboostB;
            channel.Channel_10.Tbias_tot = tbias_tot;
            channel.Channel_10.Tbias_off = tbias_off;
            channel.Channel_10.Ibias = ibias;
            channel.Channel_10.IboostP = iboostP;
            channel.Channel_10.Tpeak_tot = tpeak_tot;
            channel.Channel_10.Tpeak_off = tpeak_off;
            channel.Channel_10.Ipeak = ipeak;
            channel.Channel_10.Tbypass = tbypass;
            channel.Channel_10.Thold_tot = thold_tot;
            channel.Channel_10.Thold_off = thold_off;
            channel.Channel_10.Ihold = ihold;
            channel.Channel_10.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_11:
            channel.Channel_11.IboostB = iboostB;
            channel.Channel_11.Tbias_tot = tbias_tot;
            channel.Channel_11.Tbias_off = tbias_off;
            channel.Channel_11.Ibias = ibias;
            channel.Channel_11.IboostP = iboostP;
            channel.Channel_11.Tpeak_tot = tpeak_tot;
            channel.Channel_11.Tpeak_off = tpeak_off;
            channel.Channel_11.Ipeak = ipeak;
            channel.Channel_11.Tbypass = tbypass;
            channel.Channel_11.Thold_tot = thold_tot;
            channel.Channel_11.Thold_off = thold_off;
            channel.Channel_11.Ihold = ihold;
            channel.Channel_11.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_12:
            channel.Channel_12.IboostB = iboostB;
            channel.Channel_12.Tbias_tot = tbias_tot;
            channel.Channel_12.Tbias_off = tbias_off;
            channel.Channel_12.Ibias = ibias;
            channel.Channel_12.IboostP = iboostP;
            channel.Channel_12.Tpeak_tot = tpeak_tot;
            channel.Channel_12.Tpeak_off = tpeak_off;
            channel.Channel_12.Ipeak = ipeak;
            channel.Channel_12.Tbypass = tbypass;
            channel.Channel_12.Thold_tot = thold_tot;
            channel.Channel_12.Thold_off = thold_off;
            channel.Channel_12.Ihold = ihold;
            channel.Channel_12.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_13:
            channel.Channel_13.IboostB = iboostB;
            channel.Channel_13.Tbias_tot = tbias_tot;
            channel.Channel_13.Tbias_off = tbias_off;
            channel.Channel_13.Ibias = ibias;
            channel.Channel_13.IboostP = iboostP;
            channel.Channel_13.Tpeak_tot = tpeak_tot;
            channel.Channel_13.Tpeak_off = tpeak_off;
            channel.Channel_13.Ipeak = ipeak;
            channel.Channel_13.Tbypass = tbypass;
            channel.Channel_13.Thold_tot = thold_tot;
            channel.Channel_13.Thold_off = thold_off;
            channel.Channel_13.Ihold = ihold;
            channel.Channel_13.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_14:
            channel.Channel_14.IboostB = iboostB;
            channel.Channel_14.Tbias_tot = tbias_tot;
            channel.Channel_14.Tbias_off = tbias_off;
            channel.Channel_14.Ibias = ibias;
            channel.Channel_14.IboostP = iboostP;
            channel.Channel_14.Tpeak_tot = tpeak_tot;
            channel.Channel_14.Tpeak_off = tpeak_off;
            channel.Channel_14.Ipeak = ipeak;
            channel.Channel_14.Tbypass = tbypass;
            channel.Channel_14.Thold_tot = thold_tot;
            channel.Channel_14.Thold_off = thold_off;
            channel.Channel_14.Ihold = ihold;
            channel.Channel_14.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_15:
            channel.Channel_15.IboostB = iboostB;
            channel.Channel_15.Tbias_tot = tbias_tot;
            channel.Channel_15.Tbias_off = tbias_off;
            channel.Channel_15.Ibias = ibias;
            channel.Channel_15.IboostP = iboostP;
            channel.Channel_15.Tpeak_tot = tpeak_tot;
            channel.Channel_15.Tpeak_off = tpeak_off;
            channel.Channel_15.Ipeak = ipeak;
            channel.Channel_15.Tbypass = tbypass;
            channel.Channel_15.Thold_tot = thold_tot;
            channel.Channel_15.Thold_off = thold_off;
            channel.Channel_15.Ihold = ihold;
            channel.Channel_15.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_16:
            channel.Channel_16.IboostB = iboostB;
            channel.Channel_16.Tbias_tot = tbias_tot;
            channel.Channel_16.Tbias_off = tbias_off;
            channel.Channel_16.Ibias = ibias;
            channel.Channel_16.IboostP = iboostP;
            channel.Channel_16.Tpeak_tot = tpeak_tot;
            channel.Channel_16.Tpeak_off = tpeak_off;
            channel.Channel_16.Ipeak = ipeak;
            channel.Channel_16.Tbypass = tbypass;
            channel.Channel_16.Thold_tot = thold_tot;
            channel.Channel_16.Thold_off = thold_off;
            channel.Channel_16.Ihold = ihold;
            channel.Channel_16.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_17:
            channel.Channel_17.IboostB = iboostB;
            channel.Channel_17.Tbias_tot = tbias_tot;
            channel.Channel_17.Tbias_off = tbias_off;
            channel.Channel_17.Ibias = ibias;
            channel.Channel_17.IboostP = iboostP;
            channel.Channel_17.Tpeak_tot = tpeak_tot;
            channel.Channel_17.Tpeak_off = tpeak_off;
            channel.Channel_17.Ipeak = ipeak;
            channel.Channel_17.Tbypass = tbypass;
            channel.Channel_17.Thold_tot = thold_tot;
            channel.Channel_17.Thold_off = thold_off;
            channel.Channel_17.Ihold = ihold;
            channel.Channel_17.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_18:
            channel.Channel_18.IboostB = iboostB;
            channel.Channel_18.Tbias_tot = tbias_tot;
            channel.Channel_18.Tbias_off = tbias_off;
            channel.Channel_18.Ibias = ibias;
            channel.Channel_18.IboostP = iboostP;
            channel.Channel_18.Tpeak_tot = tpeak_tot;
            channel.Channel_18.Tpeak_off = tpeak_off;
            channel.Channel_18.Ipeak = ipeak;
            channel.Channel_18.Tbypass = tbypass;
            channel.Channel_18.Thold_tot = thold_tot;
            channel.Channel_18.Thold_off = thold_off;
            channel.Channel_18.Ihold = ihold;
            channel.Channel_18.FWtimeOFF = fwtimeOFF;
            break;

        default:
            break;
    }




    ProgramDevice_Data();


    SendCmd_EnChannel();
}
}





// 应用层电流更改函数
void Set_ConstantCurrent1(uint8 ChannelID, uint16 iboostB, uint16 tbias_tot, uint16 tbias_off, uint16 ibias, uint16 iboostP,
        uint16 tpeak_tot, uint16 tpeak_off, uint16 ipeak, uint16 tbypass, uint16 thold_tot, uint16 thold_off,
        uint16 ihold, uint16 fwtimeOFF)
{

	  if((( channel_get_value.Channel_1.PC_Change == 0)&&( channel_get_value.Channel_2.PC_Change == 0)&&
				( channel_get_value.Channel_3.PC_Change == 0)&&(channel_get_value.Channel_4.PC_Change == 0)&&( channel_get_value.Channel_5.PC_Change == 0)&&
				( channel_get_value.Channel_6.PC_Change == 0)&&( channel_get_value.Channel_7.PC_Change == 0)&&( channel_get_value.Channel_8.PC_Change == 0)&&
				( channel_get_value.Channel_9.PC_Change == 0)&&( channel_get_value.Channel_10.PC_Change == 0)&&( channel_get_value.Channel_11.PC_Change == 0)&&
				(channel_get_value.Channel_12.PC_Change == 0)&&( channel_get_value.Channel_13.PC_Change == 0)&&( channel_get_value.Channel_14.PC_Change == 0)&&
				( channel_get_value.Channel_15.PC_Change == 0)&&( channel_get_value.Channel_16.PC_Change == 0)))
	  {






	if( B_current_change == 0)
	{
    switch(ChannelID){
        case Channel_number_1:
            channel.Channel_1.IboostB = iboostB;
            channel.Channel_1.Tbias_tot = tbias_tot;
            channel.Channel_1.Tbias_off = tbias_off;
            channel.Channel_1.Ibias = ibias;
            channel.Channel_1.IboostP = iboostP;
            channel.Channel_1.Tpeak_tot = tpeak_tot;
            channel.Channel_1.Tpeak_off = tpeak_off;
            channel.Channel_1.Ipeak = ipeak;
            channel.Channel_1.Tbypass = tbypass;
            channel.Channel_1.Thold_tot = thold_tot;
            channel.Channel_1.Thold_off = thold_off;
            channel.Channel_1.Ihold = ihold;
            channel.Channel_1.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_2:
            channel.Channel_2.IboostB = iboostB;
            channel.Channel_2.Tbias_tot = tbias_tot;
            channel.Channel_2.Tbias_off = tbias_off;
            channel.Channel_2.Ibias = ibias;
            channel.Channel_2.IboostP = iboostP;
            channel.Channel_2.Tpeak_tot = tpeak_tot;
            channel.Channel_2.Tpeak_off = tpeak_off;
            channel.Channel_2.Ipeak = ipeak;
            channel.Channel_2.Tbypass = tbypass;
            channel.Channel_2.Thold_tot = thold_tot;
            channel.Channel_2.Thold_off = thold_off;
            channel.Channel_2.Ihold = ihold;
            channel.Channel_2.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_3:
            channel.Channel_3.IboostB = iboostB;
            channel.Channel_3.Tbias_tot = tbias_tot;
            channel.Channel_3.Tbias_off = tbias_off;
            channel.Channel_3.Ibias = ibias;
            channel.Channel_3.IboostP = iboostP;
            channel.Channel_3.Tpeak_tot = tpeak_tot;
            channel.Channel_3.Tpeak_off = tpeak_off;
            channel.Channel_3.Ipeak = ipeak;
            channel.Channel_3.Tbypass = tbypass;
            channel.Channel_3.Thold_tot = thold_tot;
            channel.Channel_3.Thold_off = thold_off;
            channel.Channel_3.Ihold = ihold;
            channel.Channel_3.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_4:
            channel.Channel_4.IboostB = iboostB;
            channel.Channel_4.Tbias_tot = tbias_tot;
            channel.Channel_4.Tbias_off = tbias_off;
            channel.Channel_4.Ibias = ibias;
            channel.Channel_4.IboostP = iboostP;
            channel.Channel_4.Tpeak_tot = tpeak_tot;
            channel.Channel_4.Tpeak_off = tpeak_off;
            channel.Channel_4.Ipeak = ipeak;
            channel.Channel_4.Tbypass = tbypass;
            channel.Channel_4.Thold_tot = thold_tot;
            channel.Channel_4.Thold_off = thold_off;
            channel.Channel_4.Ihold = ihold;
            channel.Channel_4.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_5:
            channel.Channel_5.IboostB = iboostB;
            channel.Channel_5.Tbias_tot = tbias_tot;
            channel.Channel_5.Tbias_off = tbias_off;
            channel.Channel_5.Ibias = ibias;
            channel.Channel_5.IboostP = iboostP;
            channel.Channel_5.Tpeak_tot = tpeak_tot;
            channel.Channel_5.Tpeak_off = tpeak_off;
            channel.Channel_5.Ipeak = ipeak;
            channel.Channel_5.Tbypass = tbypass;
            channel.Channel_5.Thold_tot = thold_tot;
            channel.Channel_5.Thold_off = thold_off;
            channel.Channel_5.Ihold = ihold;
            channel.Channel_5.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_6:
            channel.Channel_6.IboostB = iboostB;
            channel.Channel_6.Tbias_tot = tbias_tot;
            channel.Channel_6.Tbias_off = tbias_off;
            channel.Channel_6.Ibias = ibias;
            channel.Channel_6.IboostP = iboostP;
            channel.Channel_6.Tpeak_tot = tpeak_tot;
            channel.Channel_6.Tpeak_off = tpeak_off;
            channel.Channel_6.Ipeak = ipeak;
            channel.Channel_6.Tbypass = tbypass;
            channel.Channel_6.Thold_tot = thold_tot;
            channel.Channel_6.Thold_off = thold_off;
            channel.Channel_6.Ihold = ihold;
            channel.Channel_6.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_7:
            channel.Channel_7.IboostB = iboostB;
            channel.Channel_7.Tbias_tot = tbias_tot;
            channel.Channel_7.Tbias_off = tbias_off;
            channel.Channel_7.Ibias = ibias;
            channel.Channel_7.IboostP = iboostP;
            channel.Channel_7.Tpeak_tot = tpeak_tot;
            channel.Channel_7.Tpeak_off = tpeak_off;
            channel.Channel_7.Ipeak = ipeak;
            channel.Channel_7.Tbypass = tbypass;
            channel.Channel_7.Thold_tot = thold_tot;
            channel.Channel_7.Thold_off = thold_off;
            channel.Channel_7.Ihold = ihold;
            channel.Channel_7.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_8:
            channel.Channel_8.IboostB = iboostB;
            channel.Channel_8.Tbias_tot = tbias_tot;
            channel.Channel_8.Tbias_off = tbias_off;
            channel.Channel_8.Ibias = ibias;
            channel.Channel_8.IboostP = iboostP;
            channel.Channel_8.Tpeak_tot = tpeak_tot;
            channel.Channel_8.Tpeak_off = tpeak_off;
            channel.Channel_8.Ipeak = ipeak;
            channel.Channel_8.Tbypass = tbypass;
            channel.Channel_8.Thold_tot = thold_tot;
            channel.Channel_8.Thold_off = thold_off;
            channel.Channel_8.Ihold = ihold;
            channel.Channel_8.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_9:
            channel.Channel_9.IboostB = iboostB;
            channel.Channel_9.Tbias_tot = tbias_tot;
            channel.Channel_9.Tbias_off = tbias_off;
            channel.Channel_9.Ibias = ibias;
            channel.Channel_9.IboostP = iboostP;
            channel.Channel_9.Tpeak_tot = tpeak_tot;
            channel.Channel_9.Tpeak_off = tpeak_off;
            channel.Channel_9.Ipeak = ipeak;
            channel.Channel_9.Tbypass = tbypass;
            channel.Channel_9.Thold_tot = thold_tot;
            channel.Channel_9.Thold_off = thold_off;
            channel.Channel_9.Ihold = ihold;
            channel.Channel_9.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_10:
            channel.Channel_10.IboostB = iboostB;
            channel.Channel_10.Tbias_tot = tbias_tot;
            channel.Channel_10.Tbias_off = tbias_off;
            channel.Channel_10.Ibias = ibias;
            channel.Channel_10.IboostP = iboostP;
            channel.Channel_10.Tpeak_tot = tpeak_tot;
            channel.Channel_10.Tpeak_off = tpeak_off;
            channel.Channel_10.Ipeak = ipeak;
            channel.Channel_10.Tbypass = tbypass;
            channel.Channel_10.Thold_tot = thold_tot;
            channel.Channel_10.Thold_off = thold_off;
            channel.Channel_10.Ihold = ihold;
            channel.Channel_10.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_11:
            channel.Channel_11.IboostB = iboostB;
            channel.Channel_11.Tbias_tot = tbias_tot;
            channel.Channel_11.Tbias_off = tbias_off;
            channel.Channel_11.Ibias = ibias;
            channel.Channel_11.IboostP = iboostP;
            channel.Channel_11.Tpeak_tot = tpeak_tot;
            channel.Channel_11.Tpeak_off = tpeak_off;
            channel.Channel_11.Ipeak = ipeak;
            channel.Channel_11.Tbypass = tbypass;
            channel.Channel_11.Thold_tot = thold_tot;
            channel.Channel_11.Thold_off = thold_off;
            channel.Channel_11.Ihold = ihold;
            channel.Channel_11.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_12:
            channel.Channel_12.IboostB = iboostB;
            channel.Channel_12.Tbias_tot = tbias_tot;
            channel.Channel_12.Tbias_off = tbias_off;
            channel.Channel_12.Ibias = ibias;
            channel.Channel_12.IboostP = iboostP;
            channel.Channel_12.Tpeak_tot = tpeak_tot;
            channel.Channel_12.Tpeak_off = tpeak_off;
            channel.Channel_12.Ipeak = ipeak;
            channel.Channel_12.Tbypass = tbypass;
            channel.Channel_12.Thold_tot = thold_tot;
            channel.Channel_12.Thold_off = thold_off;
            channel.Channel_12.Ihold = ihold;
            channel.Channel_12.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_13:
            channel.Channel_13.IboostB = iboostB;
            channel.Channel_13.Tbias_tot = tbias_tot;
            channel.Channel_13.Tbias_off = tbias_off;
            channel.Channel_13.Ibias = ibias;
            channel.Channel_13.IboostP = iboostP;
            channel.Channel_13.Tpeak_tot = tpeak_tot;
            channel.Channel_13.Tpeak_off = tpeak_off;
            channel.Channel_13.Ipeak = ipeak;
            channel.Channel_13.Tbypass = tbypass;
            channel.Channel_13.Thold_tot = thold_tot;
            channel.Channel_13.Thold_off = thold_off;
            channel.Channel_13.Ihold = ihold;
            channel.Channel_13.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_14:
            channel.Channel_14.IboostB = iboostB;
            channel.Channel_14.Tbias_tot = tbias_tot;
            channel.Channel_14.Tbias_off = tbias_off;
            channel.Channel_14.Ibias = ibias;
            channel.Channel_14.IboostP = iboostP;
            channel.Channel_14.Tpeak_tot = tpeak_tot;
            channel.Channel_14.Tpeak_off = tpeak_off;
            channel.Channel_14.Ipeak = ipeak;
            channel.Channel_14.Tbypass = tbypass;
            channel.Channel_14.Thold_tot = thold_tot;
            channel.Channel_14.Thold_off = thold_off;
            channel.Channel_14.Ihold = ihold;
            channel.Channel_14.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_15:
            channel.Channel_15.IboostB = iboostB;
            channel.Channel_15.Tbias_tot = tbias_tot;
            channel.Channel_15.Tbias_off = tbias_off;
            channel.Channel_15.Ibias = ibias;
            channel.Channel_15.IboostP = iboostP;
            channel.Channel_15.Tpeak_tot = tpeak_tot;
            channel.Channel_15.Tpeak_off = tpeak_off;
            channel.Channel_15.Ipeak = ipeak;
            channel.Channel_15.Tbypass = tbypass;
            channel.Channel_15.Thold_tot = thold_tot;
            channel.Channel_15.Thold_off = thold_off;
            channel.Channel_15.Ihold = ihold;
            channel.Channel_15.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_16:
            channel.Channel_16.IboostB = iboostB;
            channel.Channel_16.Tbias_tot = tbias_tot;
            channel.Channel_16.Tbias_off = tbias_off;
            channel.Channel_16.Ibias = ibias;
            channel.Channel_16.IboostP = iboostP;
            channel.Channel_16.Tpeak_tot = tpeak_tot;
            channel.Channel_16.Tpeak_off = tpeak_off;
            channel.Channel_16.Ipeak = ipeak;
            channel.Channel_16.Tbypass = tbypass;
            channel.Channel_16.Thold_tot = thold_tot;
            channel.Channel_16.Thold_off = thold_off;
            channel.Channel_16.Ihold = ihold;
            channel.Channel_16.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_17:
            channel.Channel_17.IboostB = iboostB;
            channel.Channel_17.Tbias_tot = tbias_tot;
            channel.Channel_17.Tbias_off = tbias_off;
            channel.Channel_17.Ibias = ibias;
            channel.Channel_17.IboostP = iboostP;
            channel.Channel_17.Tpeak_tot = tpeak_tot;
            channel.Channel_17.Tpeak_off = tpeak_off;
            channel.Channel_17.Ipeak = ipeak;
            channel.Channel_17.Tbypass = tbypass;
            channel.Channel_17.Thold_tot = thold_tot;
            channel.Channel_17.Thold_off = thold_off;
            channel.Channel_17.Ihold = ihold;
            channel.Channel_17.FWtimeOFF = fwtimeOFF;
            break;

        case Channel_number_18:
            channel.Channel_18.IboostB = iboostB;
            channel.Channel_18.Tbias_tot = tbias_tot;
            channel.Channel_18.Tbias_off = tbias_off;
            channel.Channel_18.Ibias = ibias;
            channel.Channel_18.IboostP = iboostP;
            channel.Channel_18.Tpeak_tot = tpeak_tot;
            channel.Channel_18.Tpeak_off = tpeak_off;
            channel.Channel_18.Ipeak = ipeak;
            channel.Channel_18.Tbypass = tbypass;
            channel.Channel_18.Thold_tot = thold_tot;
            channel.Channel_18.Thold_off = thold_off;
            channel.Channel_18.Ihold = ihold;
            channel.Channel_18.FWtimeOFF = fwtimeOFF;
            break;

        default:
            break;
    }


    if(ChannelID != 13)
    {
        ParamMap1(((ChannelID + 2) / 3),ChannelID);
    }

    else
    {
        ParamMap1(6,13);
    }


    ProgramDevice_Data();



}
}
}

//PT2000初始化函数
void PT2000_Init(uint8 Mode)
{

    ++Timer_coda;
    if(Timer_coda == 40)
    {
         SendCmd_EnChannel();
         Dio_WriteChannel(DioConf_DioChannel_V1_RESET,PT2000_Disable);
         Dio_WriteChannel(DioConf_DioChannel_V2_RESET,PT2000_Disable);
         Dio_WriteChannel(DioConf_DioChannel_V3_RESET,PT2000_Disable);
         Dio_WriteChannel(DioConf_DioChannel_V4_RESET,PT2000_Disable);
         Dio_WriteChannel(DioConf_DioChannel_V5_RESET,PT2000_Disable);
         Dio_WriteChannel(DioConf_DioChannel_V6_RESET,PT2000_Disable);
         Set_AllStartPin_Low();
         Dio_WriteChannel(DioConf_DioChannel_V_DRIVEN1,PT2000_Enable);
         initValveParam(Mode);
         Set_RESETPin_High(1);
    }

    if(Timer_coda == 70)
    {

        x = 1;
        y = 1;
        ParamMap(1);
        Download_Pt2000(Mode);
        SendCmd_EnChannel();
        Set_RESETPin_High(2);
   }

    if(Timer_coda == 100)
    {

        x = 2;
        y = 2;
        ParamMap(2);
        Download_Pt2000(Mode);
        SendCmd_EnChannel();
        Set_RESETPin_High(3);
    }

    if(Timer_coda == 130)
    {
        x = 3;
        y = 3;
        Set_RESETPin_High(4);
        ParamMap(3);
        Download_Pt2000(Mode);
        SendCmd_EnChannel();
    }

    if(Timer_coda == 160)
    {
        x = 4;
        y = 4;
        Set_RESETPin_High(5);
        ParamMap(4);
        Download_Pt2000(Mode);
        SendCmd_EnChannel();

    }

    if(Timer_coda == 190)
    {
        x = 5;
        y = 5;
        ParamMap(5);
        Set_RESETPin_High(6);
        Download_Pt2000(Mode);
        SendCmd_EnChannel();
    }

    if(Timer_coda == 220)
    {
        x = 6;
        y = 6;
        ParamMap(6);
        Download_Pt2000(Mode);
        SendCmd_EnChannel();

    }

  if(Timer_coda == 1000)
  {
      Timer_coda = 950;
  }


  if(Mode_Change_Time_code == 1000)
  {
	  Mode_Change_Time_code = 900;
  }


}






// PT2000控制函数
void PT2000_Contral()
{


    if (Timer_coda >= 300)
    {

		 if((Mode_Change_Time_code >= 30) && (( channel_judge.Channel_1.Mode != channel_get_value.Channel_1.Mode)||( channel_judge.Channel_2.Mode != channel_get_value.Channel_2.Mode)||
				( channel_judge.Channel_3.Mode != channel_get_value.Channel_3.Mode)||( channel_judge.Channel_4.Mode != channel_get_value.Channel_4.Mode)||( channel_judge.Channel_5.Mode != channel_get_value.Channel_5.Mode)||
				( channel_judge.Channel_6.Mode != channel_get_value.Channel_6.Mode)||( channel_judge.Channel_7.Mode != channel_get_value.Channel_7.Mode)||( channel_judge.Channel_8.Mode != channel_get_value.Channel_8.Mode)||
				( channel_judge.Channel_9.Mode != channel_get_value.Channel_9.Mode)||( channel_judge.Channel_10.Mode != channel_get_value.Channel_10.Mode)||( channel_judge.Channel_11.Mode != channel_get_value.Channel_11.Mode)||
				( channel_judge.Channel_12.Mode != channel_get_value.Channel_12.Mode)||( channel_judge.Channel_13.Mode != channel_get_value.Channel_13.Mode)||( channel_judge.Channel_14.Mode != channel_get_value.Channel_14.Mode)||
				( channel_judge.Channel_15.Mode != channel_get_value.Channel_15.Mode)||( channel_judge.Channel_16.Mode != channel_get_value.Channel_16.Mode)))
		 {
			   Mode_Change_Time_code = 0;
	     }

	    	if ( (channel_judge.Channel_1.State != channel_get_value.Channel_1.State) ||( channel_judge.Channel_1.FWtimeOFF != channel_get_value.Channel_1.FWtimeOFF)||
	    		 (channel_judge.Channel_1.Ibias != channel_get_value.Channel_1.Ibias) ||( channel_judge.Channel_1.IboostB != channel_get_value.Channel_1.IboostB)||
			     (channel_judge.Channel_1.Ihold != channel_get_value.Channel_1.Ihold) ||( channel_judge.Channel_1.Ipeak != channel_get_value.Channel_1.Ipeak)||
		         (channel_judge.Channel_1.Tbias_off != channel_get_value.Channel_1.Tbias_off) ||( channel_judge.Channel_1.Tbias_tot != channel_get_value.Channel_1.Tbias_tot)||
			     (channel_judge.Channel_1.Tbypass != channel_get_value.Channel_1.Tbypass) ||( channel_judge.Channel_1.Thold_off != channel_get_value.Channel_1.Thold_off)||
			     (channel_judge.Channel_1.Thold_tot != channel_get_value.Channel_1.Thold_tot) ||( channel_judge.Channel_1.Tpeak_off != channel_get_value.Channel_1.Tpeak_off)||
			     (channel_judge.Channel_1.Tpeak_tot != channel_get_value.Channel_1.Tpeak_tot) ||( channel_judge.Channel_1.Mode != channel_get_value.Channel_1.Mode)||
			     (channel_judge.Channel_1.IboostP != channel_get_value.Channel_1.IboostP) )
	    	{


	    	    channel_judge.Channel_1.IboostB   =  channel_get_value.Channel_1.IboostB;
	    	    channel_judge.Channel_1.Tbias_tot =  channel_get_value.Channel_1.Tbias_tot;
	    	    channel_judge.Channel_1.Tbias_off =  channel_get_value.Channel_1.Tbias_off ;
	    	    channel_judge.Channel_1.Ibias     =  channel_get_value.Channel_1.Ibias;
	    	    channel_judge.Channel_1.IboostP   =  channel_get_value.Channel_1.IboostP ;
	    	    channel_judge.Channel_1.Tpeak_tot =  channel_get_value.Channel_1.Tpeak_tot;
	    	    channel_judge.Channel_1.Tpeak_off =  channel_get_value.Channel_1.Tpeak_off;
	    	    channel_judge.Channel_1.Ipeak     =  channel_get_value.Channel_1.Ipeak;
	    	    channel_judge.Channel_1.Tbypass   =  channel_get_value.Channel_1.Tbypass;
	    	    channel_judge.Channel_1.Thold_tot =  channel_get_value.Channel_1.Thold_tot ;
	    	    channel_judge.Channel_1.Thold_off =  channel_get_value.Channel_1.Thold_off;
	    	    channel_judge.Channel_1.Ihold     =  channel_get_value.Channel_1.Ihold ;
	    	    channel_judge.Channel_1.FWtimeOFF =  channel_get_value.Channel_1.FWtimeOFF;
	    	    channel_judge.Channel_1.State     =  channel_get_value.Channel_1.State;
	    	    channel_judge.Channel_1.Mode      =  channel_get_value.Channel_1.Mode;


	    	    channel.Channel_1.IboostB   =  channel_get_value.Channel_1.IboostB;
	    	    channel.Channel_1.Tbias_tot =  channel_get_value.Channel_1.Tbias_tot;
	    	    channel.Channel_1.Tbias_off =  channel_get_value.Channel_1.Tbias_off ;
	    	    channel.Channel_1.Ibias     =  channel_get_value.Channel_1.Ibias;
	    	    channel.Channel_1.IboostP   =  channel_get_value.Channel_1.IboostP ;
	    	    channel.Channel_1.Tpeak_tot =  channel_get_value.Channel_1.Tpeak_tot;
	    	    channel.Channel_1.Tpeak_off =  channel_get_value.Channel_1.Tpeak_off;
	    	    channel.Channel_1.Ipeak     =  channel_get_value.Channel_1.Ipeak;
	    	    channel.Channel_1.Tbypass   =  channel_get_value.Channel_1.Tbypass;
	    	    channel.Channel_1.Thold_tot =  channel_get_value.Channel_1.Thold_tot ;
	    	    channel.Channel_1.Thold_off =  channel_get_value.Channel_1.Thold_off;
	    	    channel.Channel_1.Ihold     =  channel_get_value.Channel_1.Ihold ;
	    	    channel.Channel_1.FWtimeOFF =  channel_get_value.Channel_1.FWtimeOFF;
	    	    channel.Channel_1.Mode      =  channel_get_value.Channel_1.Mode;
	    	    channel.Channel_1.State     =  channel_get_value.Channel_1.State;
	    	}


	    	if ( (channel_judge.Channel_2.State != channel_get_value.Channel_2.State) ||( channel_judge.Channel_2.FWtimeOFF != channel_get_value.Channel_2.FWtimeOFF)||
	    		 (channel_judge.Channel_2.Ibias != channel_get_value.Channel_2.Ibias) ||( channel_judge.Channel_2.IboostB != channel_get_value.Channel_2.IboostB)||
			     (channel_judge.Channel_2.Ihold != channel_get_value.Channel_2.Ihold) ||( channel_judge.Channel_2.Ipeak != channel_get_value.Channel_2.Ipeak)||
		         (channel_judge.Channel_2.Tbias_off != channel_get_value.Channel_2.Tbias_off) ||( channel_judge.Channel_2.Tbias_tot != channel_get_value.Channel_2.Tbias_tot)||
			     (channel_judge.Channel_2.Tbypass != channel_get_value.Channel_2.Tbypass) ||( channel_judge.Channel_2.Thold_off != channel_get_value.Channel_2.Thold_off)||
			     (channel_judge.Channel_2.Thold_tot != channel_get_value.Channel_2.Thold_tot) ||( channel_judge.Channel_2.Tpeak_off != channel_get_value.Channel_2.Tpeak_off)||
			     (channel_judge.Channel_2.Tpeak_tot != channel_get_value.Channel_2.Tpeak_tot) ||( channel_judge.Channel_2.Mode != channel_get_value.Channel_2.Mode)||
			     (channel_judge.Channel_2.IboostP != channel_get_value.Channel_2.IboostP) )
	    	{


	    	    channel_judge.Channel_2.IboostB   =  channel_get_value.Channel_2.IboostB;
	    	    channel_judge.Channel_2.Tbias_tot =  channel_get_value.Channel_2.Tbias_tot;
	    	    channel_judge.Channel_2.Tbias_off =  channel_get_value.Channel_2.Tbias_off ;
	    	    channel_judge.Channel_2.Ibias     =  channel_get_value.Channel_2.Ibias;
	    	    channel_judge.Channel_2.IboostP   =  channel_get_value.Channel_2.IboostP ;
	    	    channel_judge.Channel_2.Tpeak_tot =  channel_get_value.Channel_2.Tpeak_tot;
	    	    channel_judge.Channel_2.Tpeak_off =  channel_get_value.Channel_2.Tpeak_off;
	    	    channel_judge.Channel_2.Ipeak     =  channel_get_value.Channel_2.Ipeak;
	    	    channel_judge.Channel_2.Tbypass   =  channel_get_value.Channel_2.Tbypass;
	    	    channel_judge.Channel_2.Thold_tot =  channel_get_value.Channel_2.Thold_tot ;
	    	    channel_judge.Channel_2.Thold_off =  channel_get_value.Channel_2.Thold_off;
	    	    channel_judge.Channel_2.Ihold     =  channel_get_value.Channel_2.Ihold ;
	    	    channel_judge.Channel_2.FWtimeOFF =  channel_get_value.Channel_2.FWtimeOFF;
	    	    channel_judge.Channel_2.State     =  channel_get_value.Channel_2.State;
	    	    channel_judge.Channel_2.Mode      =  channel_get_value.Channel_2.Mode;


	    	    channel.Channel_2.IboostB   =  channel_get_value.Channel_2.IboostB;
	    	    channel.Channel_2.Tbias_tot =  channel_get_value.Channel_2.Tbias_tot;
	    	    channel.Channel_2.Tbias_off =  channel_get_value.Channel_2.Tbias_off ;
	    	    channel.Channel_2.Ibias     =  channel_get_value.Channel_2.Ibias;
	    	    channel.Channel_2.IboostP   =  channel_get_value.Channel_2.IboostP ;
	    	    channel.Channel_2.Tpeak_tot =  channel_get_value.Channel_2.Tpeak_tot;
	    	    channel.Channel_2.Tpeak_off =  channel_get_value.Channel_2.Tpeak_off;
	    	    channel.Channel_2.Ipeak     =  channel_get_value.Channel_2.Ipeak;
	    	    channel.Channel_2.Tbypass   =  channel_get_value.Channel_2.Tbypass;
	    	    channel.Channel_2.Thold_tot =  channel_get_value.Channel_2.Thold_tot ;
	    	    channel.Channel_2.Thold_off =  channel_get_value.Channel_2.Thold_off;
	    	    channel.Channel_2.Ihold     =  channel_get_value.Channel_2.Ihold ;
	    	    channel.Channel_2.FWtimeOFF =  channel_get_value.Channel_2.FWtimeOFF;
	    	    channel.Channel_2.Mode      =  channel_get_value.Channel_2.Mode;
	    	    channel.Channel_2.State     =  channel_get_value.Channel_2.State;
	    	}



	    	if ( (channel_judge.Channel_3.State != channel_get_value.Channel_3.State) ||( channel_judge.Channel_3.FWtimeOFF != channel_get_value.Channel_3.FWtimeOFF)||
	    		 (channel_judge.Channel_3.Ibias != channel_get_value.Channel_3.Ibias) ||( channel_judge.Channel_3.IboostB != channel_get_value.Channel_3.IboostB)||
			     (channel_judge.Channel_3.Ihold != channel_get_value.Channel_3.Ihold) ||( channel_judge.Channel_3.Ipeak != channel_get_value.Channel_3.Ipeak)||
		         (channel_judge.Channel_3.Tbias_off != channel_get_value.Channel_3.Tbias_off) ||( channel_judge.Channel_3.Tbias_tot != channel_get_value.Channel_3.Tbias_tot)||
			     (channel_judge.Channel_3.Tbypass != channel_get_value.Channel_3.Tbypass) ||( channel_judge.Channel_3.Thold_off != channel_get_value.Channel_3.Thold_off)||
			     (channel_judge.Channel_3.Thold_tot != channel_get_value.Channel_3.Thold_tot) ||( channel_judge.Channel_3.Tpeak_off != channel_get_value.Channel_3.Tpeak_off)||
			     (channel_judge.Channel_3.Tpeak_tot != channel_get_value.Channel_3.Tpeak_tot) ||( channel_judge.Channel_3.Mode != channel_get_value.Channel_3.Mode)||
			     (channel_judge.Channel_3.IboostP != channel_get_value.Channel_3.IboostP) )
	    	{


	    	    channel_judge.Channel_3.IboostB   =  channel_get_value.Channel_3.IboostB;
	    	    channel_judge.Channel_3.Tbias_tot =  channel_get_value.Channel_3.Tbias_tot;
	    	    channel_judge.Channel_3.Tbias_off =  channel_get_value.Channel_3.Tbias_off ;
	    	    channel_judge.Channel_3.Ibias     =  channel_get_value.Channel_3.Ibias;
	    	    channel_judge.Channel_3.IboostP   =  channel_get_value.Channel_3.IboostP ;
	    	    channel_judge.Channel_3.Tpeak_tot =  channel_get_value.Channel_3.Tpeak_tot;
	    	    channel_judge.Channel_3.Tpeak_off =  channel_get_value.Channel_3.Tpeak_off;
	    	    channel_judge.Channel_3.Ipeak     =  channel_get_value.Channel_3.Ipeak;
	    	    channel_judge.Channel_3.Tbypass   =  channel_get_value.Channel_3.Tbypass;
	    	    channel_judge.Channel_3.Thold_tot =  channel_get_value.Channel_3.Thold_tot ;
	    	    channel_judge.Channel_3.Thold_off =  channel_get_value.Channel_3.Thold_off;
	    	    channel_judge.Channel_3.Ihold     =  channel_get_value.Channel_3.Ihold ;
	    	    channel_judge.Channel_3.FWtimeOFF =  channel_get_value.Channel_3.FWtimeOFF;
	    	    channel_judge.Channel_3.State     =  channel_get_value.Channel_3.State;
	    	    channel_judge.Channel_3.Mode      =  channel_get_value.Channel_3.Mode;


	    	    channel.Channel_3.IboostB   =  channel_get_value.Channel_3.IboostB;
	    	    channel.Channel_3.Tbias_tot =  channel_get_value.Channel_3.Tbias_tot;
	    	    channel.Channel_3.Tbias_off =  channel_get_value.Channel_3.Tbias_off ;
	    	    channel.Channel_3.Ibias     =  channel_get_value.Channel_3.Ibias;
	    	    channel.Channel_3.IboostP   =  channel_get_value.Channel_3.IboostP ;
	    	    channel.Channel_3.Tpeak_tot =  channel_get_value.Channel_3.Tpeak_tot;
	    	    channel.Channel_3.Tpeak_off =  channel_get_value.Channel_3.Tpeak_off;
	    	    channel.Channel_3.Ipeak     =  channel_get_value.Channel_3.Ipeak;
	    	    channel.Channel_3.Tbypass   =  channel_get_value.Channel_3.Tbypass;
	    	    channel.Channel_3.Thold_tot =  channel_get_value.Channel_3.Thold_tot ;
	    	    channel.Channel_3.Thold_off =  channel_get_value.Channel_3.Thold_off;
	    	    channel.Channel_3.Ihold     =  channel_get_value.Channel_3.Ihold ;
	    	    channel.Channel_3.FWtimeOFF =  channel_get_value.Channel_3.FWtimeOFF;
	    	    channel.Channel_3.Mode      =  channel_get_value.Channel_3.Mode;
	    	    channel.Channel_3.State     =  channel_get_value.Channel_3.State;
	    	}


	    	if ( (channel_judge.Channel_4.State != channel_get_value.Channel_4.State) ||( channel_judge.Channel_4.FWtimeOFF != channel_get_value.Channel_4.FWtimeOFF)||
	    		 (channel_judge.Channel_4.Ibias != channel_get_value.Channel_4.Ibias) ||( channel_judge.Channel_4.IboostB != channel_get_value.Channel_4.IboostB)||
			     (channel_judge.Channel_4.Ihold != channel_get_value.Channel_4.Ihold) ||( channel_judge.Channel_4.Ipeak != channel_get_value.Channel_4.Ipeak)||
		         (channel_judge.Channel_4.Tbias_off != channel_get_value.Channel_4.Tbias_off) ||( channel_judge.Channel_4.Tbias_tot != channel_get_value.Channel_4.Tbias_tot)||
			     (channel_judge.Channel_4.Tbypass != channel_get_value.Channel_4.Tbypass) ||( channel_judge.Channel_4.Thold_off != channel_get_value.Channel_4.Thold_off)||
			     (channel_judge.Channel_4.Thold_tot != channel_get_value.Channel_4.Thold_tot) ||( channel_judge.Channel_4.Tpeak_off != channel_get_value.Channel_4.Tpeak_off)||
			     (channel_judge.Channel_4.Tpeak_tot != channel_get_value.Channel_4.Tpeak_tot) ||( channel_judge.Channel_4.Mode != channel_get_value.Channel_4.Mode)||
			     (channel_judge.Channel_4.IboostP != channel_get_value.Channel_4.IboostP) )
	    	{


	     	    channel_judge.Channel_4.IboostB   =  channel_get_value.Channel_4.IboostB;
				channel_judge.Channel_4.Tbias_tot =  channel_get_value.Channel_4.Tbias_tot;
				channel_judge.Channel_4.Tbias_off =  channel_get_value.Channel_4.Tbias_off ;
				channel_judge.Channel_4.Ibias     =  channel_get_value.Channel_4.Ibias;
				channel_judge.Channel_4.IboostP   =  channel_get_value.Channel_4.IboostP ;
				channel_judge.Channel_4.Tpeak_tot =  channel_get_value.Channel_4.Tpeak_tot;
				channel_judge.Channel_4.Tpeak_off =  channel_get_value.Channel_4.Tpeak_off;
				channel_judge.Channel_4.Ipeak     =  channel_get_value.Channel_4.Ipeak;
				channel_judge.Channel_4.Tbypass   =  channel_get_value.Channel_4.Tbypass;
				channel_judge.Channel_4.Thold_tot =  channel_get_value.Channel_4.Thold_tot ;
				channel_judge.Channel_4.Thold_off =  channel_get_value.Channel_4.Thold_off;
				channel_judge.Channel_4.Ihold     =  channel_get_value.Channel_4.Ihold ;
				channel_judge.Channel_4.FWtimeOFF =  channel_get_value.Channel_4.FWtimeOFF;
				channel_judge.Channel_4.State     =  channel_get_value.Channel_4.State;
				channel_judge.Channel_4.Mode      =  channel_get_value.Channel_4.Mode;


				channel.Channel_4.IboostB   =  channel_get_value.Channel_4.IboostB;
				channel.Channel_4.Tbias_tot =  channel_get_value.Channel_4.Tbias_tot;
				channel.Channel_4.Tbias_off =  channel_get_value.Channel_4.Tbias_off ;
				channel.Channel_4.Ibias     =  channel_get_value.Channel_4.Ibias;
				channel.Channel_4.IboostP   =  channel_get_value.Channel_4.IboostP ;
				channel.Channel_4.Tpeak_tot =  channel_get_value.Channel_4.Tpeak_tot;
				channel.Channel_4.Tpeak_off =  channel_get_value.Channel_4.Tpeak_off;
				channel.Channel_4.Ipeak     =  channel_get_value.Channel_4.Ipeak;
				channel.Channel_4.Tbypass   =  channel_get_value.Channel_4.Tbypass;
				channel.Channel_4.Thold_tot =  channel_get_value.Channel_4.Thold_tot ;
				channel.Channel_4.Thold_off =  channel_get_value.Channel_4.Thold_off;
				channel.Channel_4.Ihold     =  channel_get_value.Channel_4.Ihold ;
				channel.Channel_4.FWtimeOFF =  channel_get_value.Channel_4.FWtimeOFF;
				channel.Channel_4.Mode      =  channel_get_value.Channel_4.Mode;
				channel.Channel_4.State     =  channel_get_value.Channel_4.State;
	    	}


	    	if ( (channel_judge.Channel_5.State != channel_get_value.Channel_5.State) ||( channel_judge.Channel_5.FWtimeOFF != channel_get_value.Channel_5.FWtimeOFF)||
	    		 (channel_judge.Channel_5.Ibias != channel_get_value.Channel_5.Ibias) ||( channel_judge.Channel_5.IboostB != channel_get_value.Channel_5.IboostB)||
			     (channel_judge.Channel_5.Ihold != channel_get_value.Channel_5.Ihold) ||( channel_judge.Channel_5.Ipeak != channel_get_value.Channel_5.Ipeak)||
		         (channel_judge.Channel_5.Tbias_off != channel_get_value.Channel_5.Tbias_off) ||( channel_judge.Channel_5.Tbias_tot != channel_get_value.Channel_5.Tbias_tot)||
			     (channel_judge.Channel_5.Tbypass != channel_get_value.Channel_5.Tbypass) ||( channel_judge.Channel_5.Thold_off != channel_get_value.Channel_5.Thold_off)||
			     (channel_judge.Channel_5.Thold_tot != channel_get_value.Channel_5.Thold_tot) ||( channel_judge.Channel_5.Tpeak_off != channel_get_value.Channel_5.Tpeak_off)||
			     (channel_judge.Channel_5.Tpeak_tot != channel_get_value.Channel_5.Tpeak_tot) ||( channel_judge.Channel_5.Mode != channel_get_value.Channel_5.Mode)||
			     (channel_judge.Channel_5.IboostP != channel_get_value.Channel_5.IboostP) )
	    	{

	     	    channel_judge.Channel_5.IboostB   =  channel_get_value.Channel_5.IboostB;
				channel_judge.Channel_5.Tbias_tot =  channel_get_value.Channel_5.Tbias_tot;
				channel_judge.Channel_5.Tbias_off =  channel_get_value.Channel_5.Tbias_off ;
				channel_judge.Channel_5.Ibias     =  channel_get_value.Channel_5.Ibias;
				channel_judge.Channel_5.IboostP   =  channel_get_value.Channel_5.IboostP ;
				channel_judge.Channel_5.Tpeak_tot =  channel_get_value.Channel_5.Tpeak_tot;
				channel_judge.Channel_5.Tpeak_off =  channel_get_value.Channel_5.Tpeak_off;
				channel_judge.Channel_5.Ipeak     =  channel_get_value.Channel_5.Ipeak;
				channel_judge.Channel_5.Tbypass   =  channel_get_value.Channel_5.Tbypass;
				channel_judge.Channel_5.Thold_tot =  channel_get_value.Channel_5.Thold_tot ;
				channel_judge.Channel_5.Thold_off =  channel_get_value.Channel_5.Thold_off;
				channel_judge.Channel_5.Ihold     =  channel_get_value.Channel_5.Ihold ;
				channel_judge.Channel_5.FWtimeOFF =  channel_get_value.Channel_5.FWtimeOFF;
				channel_judge.Channel_5.State     =  channel_get_value.Channel_5.State;
				channel_judge.Channel_5.Mode      =  channel_get_value.Channel_5.Mode;


				channel.Channel_5.IboostB   =  channel_get_value.Channel_5.IboostB;
				channel.Channel_5.Tbias_tot =  channel_get_value.Channel_5.Tbias_tot;
				channel.Channel_5.Tbias_off =  channel_get_value.Channel_5.Tbias_off ;
				channel.Channel_5.Ibias     =  channel_get_value.Channel_5.Ibias;
				channel.Channel_5.IboostP   =  channel_get_value.Channel_5.IboostP ;
				channel.Channel_5.Tpeak_tot =  channel_get_value.Channel_5.Tpeak_tot;
				channel.Channel_5.Tpeak_off =  channel_get_value.Channel_5.Tpeak_off;
				channel.Channel_5.Ipeak     =  channel_get_value.Channel_5.Ipeak;
				channel.Channel_5.Tbypass   =  channel_get_value.Channel_5.Tbypass;
				channel.Channel_5.Thold_tot =  channel_get_value.Channel_5.Thold_tot ;
				channel.Channel_5.Thold_off =  channel_get_value.Channel_5.Thold_off;
				channel.Channel_5.Ihold     =  channel_get_value.Channel_5.Ihold ;
				channel.Channel_5.FWtimeOFF =  channel_get_value.Channel_5.FWtimeOFF;
				channel.Channel_5.Mode      =  channel_get_value.Channel_5.Mode;
				channel.Channel_5.State     =  channel_get_value.Channel_5.State;
	    	}


	    	if ( (channel_judge.Channel_6.State != channel_get_value.Channel_6.State) ||( channel_judge.Channel_6.FWtimeOFF != channel_get_value.Channel_6.FWtimeOFF)||
	    		 (channel_judge.Channel_6.Ibias != channel_get_value.Channel_6.Ibias) ||( channel_judge.Channel_6.IboostB != channel_get_value.Channel_6.IboostB)||
			     (channel_judge.Channel_6.Ihold != channel_get_value.Channel_6.Ihold) ||( channel_judge.Channel_6.Ipeak != channel_get_value.Channel_6.Ipeak)||
		         (channel_judge.Channel_6.Tbias_off != channel_get_value.Channel_6.Tbias_off) ||( channel_judge.Channel_6.Tbias_tot != channel_get_value.Channel_6.Tbias_tot)||
			     (channel_judge.Channel_6.Tbypass != channel_get_value.Channel_6.Tbypass) ||( channel_judge.Channel_6.Thold_off != channel_get_value.Channel_6.Thold_off)||
			     (channel_judge.Channel_6.Thold_tot != channel_get_value.Channel_6.Thold_tot) ||( channel_judge.Channel_6.Tpeak_off != channel_get_value.Channel_6.Tpeak_off)||
			     (channel_judge.Channel_6.Tpeak_tot != channel_get_value.Channel_6.Tpeak_tot) ||( channel_judge.Channel_6.Mode != channel_get_value.Channel_6.Mode)||
			     (channel_judge.Channel_6.IboostP != channel_get_value.Channel_6.IboostP) )
	    	{


	     	    channel_judge.Channel_6.IboostB   =  channel_get_value.Channel_6.IboostB;
				channel_judge.Channel_6.Tbias_tot =  channel_get_value.Channel_6.Tbias_tot;
				channel_judge.Channel_6.Tbias_off =  channel_get_value.Channel_6.Tbias_off ;
				channel_judge.Channel_6.Ibias     =  channel_get_value.Channel_6.Ibias;
				channel_judge.Channel_6.IboostP   =  channel_get_value.Channel_6.IboostP ;
				channel_judge.Channel_6.Tpeak_tot =  channel_get_value.Channel_6.Tpeak_tot;
				channel_judge.Channel_6.Tpeak_off =  channel_get_value.Channel_6.Tpeak_off;
				channel_judge.Channel_6.Ipeak     =  channel_get_value.Channel_6.Ipeak;
				channel_judge.Channel_6.Tbypass   =  channel_get_value.Channel_6.Tbypass;
				channel_judge.Channel_6.Thold_tot =  channel_get_value.Channel_6.Thold_tot ;
				channel_judge.Channel_6.Thold_off =  channel_get_value.Channel_6.Thold_off;
				channel_judge.Channel_6.Ihold     =  channel_get_value.Channel_6.Ihold ;
				channel_judge.Channel_6.FWtimeOFF =  channel_get_value.Channel_6.FWtimeOFF;
				channel_judge.Channel_6.State     =  channel_get_value.Channel_6.State;
				channel_judge.Channel_6.Mode      =  channel_get_value.Channel_6.Mode;


				channel.Channel_6.IboostB   =  channel_get_value.Channel_6.IboostB;
				channel.Channel_6.Tbias_tot =  channel_get_value.Channel_6.Tbias_tot;
				channel.Channel_6.Tbias_off =  channel_get_value.Channel_6.Tbias_off ;
				channel.Channel_6.Ibias     =  channel_get_value.Channel_6.Ibias;
				channel.Channel_6.IboostP   =  channel_get_value.Channel_6.IboostP ;
				channel.Channel_6.Tpeak_tot =  channel_get_value.Channel_6.Tpeak_tot;
				channel.Channel_6.Tpeak_off =  channel_get_value.Channel_6.Tpeak_off;
				channel.Channel_6.Ipeak     =  channel_get_value.Channel_6.Ipeak;
				channel.Channel_6.Tbypass   =  channel_get_value.Channel_6.Tbypass;
				channel.Channel_6.Thold_tot =  channel_get_value.Channel_6.Thold_tot ;
				channel.Channel_6.Thold_off =  channel_get_value.Channel_6.Thold_off;
				channel.Channel_6.Ihold     =  channel_get_value.Channel_6.Ihold ;
				channel.Channel_6.FWtimeOFF =  channel_get_value.Channel_6.FWtimeOFF;
				channel.Channel_6.Mode      =  channel_get_value.Channel_6.Mode;
				channel.Channel_6.State     =  channel_get_value.Channel_6.State;
	    	}


	    	if ( (channel_judge.Channel_7.State != channel_get_value.Channel_7.State) ||( channel_judge.Channel_7.FWtimeOFF != channel_get_value.Channel_7.FWtimeOFF)||
	    		 (channel_judge.Channel_7.Ibias != channel_get_value.Channel_7.Ibias) ||( channel_judge.Channel_7.IboostB != channel_get_value.Channel_7.IboostB)||
			     (channel_judge.Channel_7.Ihold != channel_get_value.Channel_7.Ihold) ||( channel_judge.Channel_7.Ipeak != channel_get_value.Channel_7.Ipeak)||
		         (channel_judge.Channel_7.Tbias_off != channel_get_value.Channel_7.Tbias_off) ||( channel_judge.Channel_7.Tbias_tot != channel_get_value.Channel_7.Tbias_tot)||
			     (channel_judge.Channel_7.Tbypass != channel_get_value.Channel_7.Tbypass) ||( channel_judge.Channel_7.Thold_off != channel_get_value.Channel_7.Thold_off)||
			     (channel_judge.Channel_7.Thold_tot != channel_get_value.Channel_7.Thold_tot) ||( channel_judge.Channel_7.Tpeak_off != channel_get_value.Channel_7.Tpeak_off)||
			     (channel_judge.Channel_7.Tpeak_tot != channel_get_value.Channel_7.Tpeak_tot) ||( channel_judge.Channel_7.Mode != channel_get_value.Channel_7.Mode)||
			     (channel_judge.Channel_7.IboostP != channel_get_value.Channel_7.IboostP) )
	    	{


	     	    channel_judge.Channel_7.IboostB   =  channel_get_value.Channel_7.IboostB;
				channel_judge.Channel_7.Tbias_tot =  channel_get_value.Channel_7.Tbias_tot;
				channel_judge.Channel_7.Tbias_off =  channel_get_value.Channel_7.Tbias_off ;
				channel_judge.Channel_7.Ibias     =  channel_get_value.Channel_7.Ibias;
				channel_judge.Channel_7.IboostP   =  channel_get_value.Channel_7.IboostP ;
				channel_judge.Channel_7.Tpeak_tot =  channel_get_value.Channel_7.Tpeak_tot;
				channel_judge.Channel_7.Tpeak_off =  channel_get_value.Channel_7.Tpeak_off;
				channel_judge.Channel_7.Ipeak     =  channel_get_value.Channel_7.Ipeak;
				channel_judge.Channel_7.Tbypass   =  channel_get_value.Channel_7.Tbypass;
				channel_judge.Channel_7.Thold_tot =  channel_get_value.Channel_7.Thold_tot ;
				channel_judge.Channel_7.Thold_off =  channel_get_value.Channel_7.Thold_off;
				channel_judge.Channel_7.Ihold     =  channel_get_value.Channel_7.Ihold ;
				channel_judge.Channel_7.FWtimeOFF =  channel_get_value.Channel_7.FWtimeOFF;
				channel_judge.Channel_7.State     =  channel_get_value.Channel_7.State;
				channel_judge.Channel_7.Mode      =  channel_get_value.Channel_7.Mode;


				channel.Channel_7.IboostB   =  channel_get_value.Channel_7.IboostB;
				channel.Channel_7.Tbias_tot =  channel_get_value.Channel_7.Tbias_tot;
				channel.Channel_7.Tbias_off =  channel_get_value.Channel_7.Tbias_off ;
				channel.Channel_7.Ibias     =  channel_get_value.Channel_7.Ibias;
				channel.Channel_7.IboostP   =  channel_get_value.Channel_7.IboostP ;
				channel.Channel_7.Tpeak_tot =  channel_get_value.Channel_7.Tpeak_tot;
				channel.Channel_7.Tpeak_off =  channel_get_value.Channel_7.Tpeak_off;
				channel.Channel_7.Ipeak     =  channel_get_value.Channel_7.Ipeak;
				channel.Channel_7.Tbypass   =  channel_get_value.Channel_7.Tbypass;
				channel.Channel_7.Thold_tot =  channel_get_value.Channel_7.Thold_tot ;
				channel.Channel_7.Thold_off =  channel_get_value.Channel_7.Thold_off;
				channel.Channel_7.Ihold     =  channel_get_value.Channel_7.Ihold ;
				channel.Channel_7.FWtimeOFF =  channel_get_value.Channel_7.FWtimeOFF;
				channel.Channel_7.Mode      =  channel_get_value.Channel_7.Mode;
				channel.Channel_7.State     =  channel_get_value.Channel_7.State;
	    	}


	    	if ( (channel_judge.Channel_8.State != channel_get_value.Channel_8.State) ||( channel_judge.Channel_8.FWtimeOFF != channel_get_value.Channel_8.FWtimeOFF)||
	    		 (channel_judge.Channel_8.Ibias != channel_get_value.Channel_8.Ibias) ||( channel_judge.Channel_8.IboostB != channel_get_value.Channel_8.IboostB)||
			     (channel_judge.Channel_8.Ihold != channel_get_value.Channel_8.Ihold) ||( channel_judge.Channel_8.Ipeak != channel_get_value.Channel_8.Ipeak)||
		         (channel_judge.Channel_8.Tbias_off != channel_get_value.Channel_8.Tbias_off) ||( channel_judge.Channel_8.Tbias_tot != channel_get_value.Channel_8.Tbias_tot)||
			     (channel_judge.Channel_8.Tbypass != channel_get_value.Channel_8.Tbypass) ||( channel_judge.Channel_8.Thold_off != channel_get_value.Channel_8.Thold_off)||
			     (channel_judge.Channel_8.Thold_tot != channel_get_value.Channel_8.Thold_tot) ||( channel_judge.Channel_8.Tpeak_off != channel_get_value.Channel_8.Tpeak_off)||
			     (channel_judge.Channel_8.Tpeak_tot != channel_get_value.Channel_8.Tpeak_tot) ||( channel_judge.Channel_8.Mode != channel_get_value.Channel_8.Mode)||
			     (channel_judge.Channel_8.IboostP != channel_get_value.Channel_8.IboostP) )
	    	{


	     	    channel_judge.Channel_8.IboostB   =  channel_get_value.Channel_8.IboostB;
				channel_judge.Channel_8.Tbias_tot =  channel_get_value.Channel_8.Tbias_tot;
				channel_judge.Channel_8.Tbias_off =  channel_get_value.Channel_8.Tbias_off ;
				channel_judge.Channel_8.Ibias     =  channel_get_value.Channel_8.Ibias;
				channel_judge.Channel_8.IboostP   =  channel_get_value.Channel_8.IboostP ;
				channel_judge.Channel_8.Tpeak_tot =  channel_get_value.Channel_8.Tpeak_tot;
				channel_judge.Channel_8.Tpeak_off =  channel_get_value.Channel_8.Tpeak_off;
				channel_judge.Channel_8.Ipeak     =  channel_get_value.Channel_8.Ipeak;
				channel_judge.Channel_8.Tbypass   =  channel_get_value.Channel_8.Tbypass;
				channel_judge.Channel_8.Thold_tot =  channel_get_value.Channel_8.Thold_tot ;
				channel_judge.Channel_8.Thold_off =  channel_get_value.Channel_8.Thold_off;
				channel_judge.Channel_8.Ihold     =  channel_get_value.Channel_8.Ihold ;
				channel_judge.Channel_8.FWtimeOFF =  channel_get_value.Channel_8.FWtimeOFF;
				channel_judge.Channel_8.State     =  channel_get_value.Channel_8.State;
				channel_judge.Channel_8.Mode      =  channel_get_value.Channel_8.Mode;


				channel.Channel_8.IboostB   =  channel_get_value.Channel_8.IboostB;
				channel.Channel_8.Tbias_tot =  channel_get_value.Channel_8.Tbias_tot;
				channel.Channel_8.Tbias_off =  channel_get_value.Channel_8.Tbias_off ;
				channel.Channel_8.Ibias     =  channel_get_value.Channel_8.Ibias;
				channel.Channel_8.IboostP   =  channel_get_value.Channel_8.IboostP ;
				channel.Channel_8.Tpeak_tot =  channel_get_value.Channel_8.Tpeak_tot;
				channel.Channel_8.Tpeak_off =  channel_get_value.Channel_8.Tpeak_off;
				channel.Channel_8.Ipeak     =  channel_get_value.Channel_8.Ipeak;
				channel.Channel_8.Tbypass   =  channel_get_value.Channel_8.Tbypass;
				channel.Channel_8.Thold_tot =  channel_get_value.Channel_8.Thold_tot ;
				channel.Channel_8.Thold_off =  channel_get_value.Channel_8.Thold_off;
				channel.Channel_8.Ihold     =  channel_get_value.Channel_8.Ihold ;
				channel.Channel_8.FWtimeOFF =  channel_get_value.Channel_8.FWtimeOFF;
				channel.Channel_8.Mode      =  channel_get_value.Channel_8.Mode;
				channel.Channel_8.State     =  channel_get_value.Channel_8.State;
	    	}


	    	if ( (channel_judge.Channel_9.State != channel_get_value.Channel_9.State) ||( channel_judge.Channel_9.FWtimeOFF != channel_get_value.Channel_9.FWtimeOFF)||
	    		 (channel_judge.Channel_9.Ibias != channel_get_value.Channel_9.Ibias) ||( channel_judge.Channel_9.IboostB != channel_get_value.Channel_9.IboostB)||
			     (channel_judge.Channel_9.Ihold != channel_get_value.Channel_9.Ihold) ||( channel_judge.Channel_9.Ipeak != channel_get_value.Channel_9.Ipeak)||
		         (channel_judge.Channel_9.Tbias_off != channel_get_value.Channel_9.Tbias_off) ||( channel_judge.Channel_9.Tbias_tot != channel_get_value.Channel_9.Tbias_tot)||
			     (channel_judge.Channel_9.Tbypass != channel_get_value.Channel_9.Tbypass) ||( channel_judge.Channel_9.Thold_off != channel_get_value.Channel_9.Thold_off)||
			     (channel_judge.Channel_9.Thold_tot != channel_get_value.Channel_9.Thold_tot) ||( channel_judge.Channel_9.Tpeak_off != channel_get_value.Channel_9.Tpeak_off)||
			     (channel_judge.Channel_9.Tpeak_tot != channel_get_value.Channel_9.Tpeak_tot) ||( channel_judge.Channel_9.Mode != channel_get_value.Channel_9.Mode)||
			     (channel_judge.Channel_9.IboostP != channel_get_value.Channel_9.IboostP) )
	    	{


	     	    channel_judge.Channel_9.IboostB   =  channel_get_value.Channel_9.IboostB;
				channel_judge.Channel_9.Tbias_tot =  channel_get_value.Channel_9.Tbias_tot;
				channel_judge.Channel_9.Tbias_off =  channel_get_value.Channel_9.Tbias_off ;
				channel_judge.Channel_9.Ibias     =  channel_get_value.Channel_9.Ibias;
				channel_judge.Channel_9.IboostP   =  channel_get_value.Channel_9.IboostP ;
				channel_judge.Channel_9.Tpeak_tot =  channel_get_value.Channel_9.Tpeak_tot;
				channel_judge.Channel_9.Tpeak_off =  channel_get_value.Channel_9.Tpeak_off;
				channel_judge.Channel_9.Ipeak     =  channel_get_value.Channel_9.Ipeak;
				channel_judge.Channel_9.Tbypass   =  channel_get_value.Channel_9.Tbypass;
				channel_judge.Channel_9.Thold_tot =  channel_get_value.Channel_9.Thold_tot ;
				channel_judge.Channel_9.Thold_off =  channel_get_value.Channel_9.Thold_off;
				channel_judge.Channel_9.Ihold     =  channel_get_value.Channel_9.Ihold ;
				channel_judge.Channel_9.FWtimeOFF =  channel_get_value.Channel_9.FWtimeOFF;
				channel_judge.Channel_9.State     =  channel_get_value.Channel_9.State;
				channel_judge.Channel_9.Mode      =  channel_get_value.Channel_9.Mode;


				channel.Channel_9.IboostB   =  channel_get_value.Channel_9.IboostB;
				channel.Channel_9.Tbias_tot =  channel_get_value.Channel_9.Tbias_tot;
				channel.Channel_9.Tbias_off =  channel_get_value.Channel_9.Tbias_off ;
				channel.Channel_9.Ibias     =  channel_get_value.Channel_9.Ibias;
				channel.Channel_9.IboostP   =  channel_get_value.Channel_9.IboostP ;
				channel.Channel_9.Tpeak_tot =  channel_get_value.Channel_9.Tpeak_tot;
				channel.Channel_9.Tpeak_off =  channel_get_value.Channel_9.Tpeak_off;
				channel.Channel_9.Ipeak     =  channel_get_value.Channel_9.Ipeak;
				channel.Channel_9.Tbypass   =  channel_get_value.Channel_9.Tbypass;
				channel.Channel_9.Thold_tot =  channel_get_value.Channel_9.Thold_tot ;
				channel.Channel_9.Thold_off =  channel_get_value.Channel_9.Thold_off;
				channel.Channel_9.Ihold     =  channel_get_value.Channel_9.Ihold ;
				channel.Channel_9.FWtimeOFF =  channel_get_value.Channel_9.FWtimeOFF;
				channel.Channel_9.Mode      =  channel_get_value.Channel_9.Mode;
				channel.Channel_9.State     =  channel_get_value.Channel_9.State;
	    	}


	    	if ( (channel_judge.Channel_10.State != channel_get_value.Channel_10.State) ||( channel_judge.Channel_10.FWtimeOFF != channel_get_value.Channel_10.FWtimeOFF)||
	    		 (channel_judge.Channel_10.Ibias != channel_get_value.Channel_10.Ibias) ||( channel_judge.Channel_10.IboostB != channel_get_value.Channel_10.IboostB)||
			     (channel_judge.Channel_10.Ihold != channel_get_value.Channel_10.Ihold) ||( channel_judge.Channel_10.Ipeak != channel_get_value.Channel_10.Ipeak)||
		         (channel_judge.Channel_10.Tbias_off != channel_get_value.Channel_10.Tbias_off) ||( channel_judge.Channel_10.Tbias_tot != channel_get_value.Channel_10.Tbias_tot)||
			     (channel_judge.Channel_10.Tbypass != channel_get_value.Channel_10.Tbypass) ||( channel_judge.Channel_10.Thold_off != channel_get_value.Channel_10.Thold_off)||
			     (channel_judge.Channel_10.Thold_tot != channel_get_value.Channel_10.Thold_tot) ||( channel_judge.Channel_10.Tpeak_off != channel_get_value.Channel_10.Tpeak_off)||
			     (channel_judge.Channel_10.Tpeak_tot != channel_get_value.Channel_10.Tpeak_tot) ||( channel_judge.Channel_10.Mode != channel_get_value.Channel_10.Mode)||
			     (channel_judge.Channel_10.IboostP != channel_get_value.Channel_10.IboostP) )
	    	{


	     	    channel_judge.Channel_10.IboostB   =  channel_get_value.Channel_10.IboostB;
				channel_judge.Channel_10.Tbias_tot =  channel_get_value.Channel_10.Tbias_tot;
				channel_judge.Channel_10.Tbias_off =  channel_get_value.Channel_10.Tbias_off ;
				channel_judge.Channel_10.Ibias     =  channel_get_value.Channel_10.Ibias;
				channel_judge.Channel_10.IboostP   =  channel_get_value.Channel_10.IboostP ;
				channel_judge.Channel_10.Tpeak_tot =  channel_get_value.Channel_10.Tpeak_tot;
				channel_judge.Channel_10.Tpeak_off =  channel_get_value.Channel_10.Tpeak_off;
				channel_judge.Channel_10.Ipeak     =  channel_get_value.Channel_10.Ipeak;
				channel_judge.Channel_10.Tbypass   =  channel_get_value.Channel_10.Tbypass;
				channel_judge.Channel_10.Thold_tot =  channel_get_value.Channel_10.Thold_tot ;
				channel_judge.Channel_10.Thold_off =  channel_get_value.Channel_10.Thold_off;
				channel_judge.Channel_10.Ihold     =  channel_get_value.Channel_10.Ihold ;
				channel_judge.Channel_10.FWtimeOFF =  channel_get_value.Channel_10.FWtimeOFF;
				channel_judge.Channel_10.State     =  channel_get_value.Channel_10.State;
				channel_judge.Channel_10.Mode      =  channel_get_value.Channel_10.Mode;


				channel.Channel_10.IboostB   =  channel_get_value.Channel_10.IboostB;
				channel.Channel_10.Tbias_tot =  channel_get_value.Channel_10.Tbias_tot;
				channel.Channel_10.Tbias_off =  channel_get_value.Channel_10.Tbias_off ;
				channel.Channel_10.Ibias     =  channel_get_value.Channel_10.Ibias;
				channel.Channel_10.IboostP   =  channel_get_value.Channel_10.IboostP ;
				channel.Channel_10.Tpeak_tot =  channel_get_value.Channel_10.Tpeak_tot;
				channel.Channel_10.Tpeak_off =  channel_get_value.Channel_10.Tpeak_off;
				channel.Channel_10.Ipeak     =  channel_get_value.Channel_10.Ipeak;
				channel.Channel_10.Tbypass   =  channel_get_value.Channel_10.Tbypass;
				channel.Channel_10.Thold_tot =  channel_get_value.Channel_10.Thold_tot ;
				channel.Channel_10.Thold_off =  channel_get_value.Channel_10.Thold_off;
				channel.Channel_10.Ihold     =  channel_get_value.Channel_10.Ihold ;
				channel.Channel_10.FWtimeOFF =  channel_get_value.Channel_10.FWtimeOFF;
				channel.Channel_10.Mode      =  channel_get_value.Channel_10.Mode;
				channel.Channel_10.State     =  channel_get_value.Channel_10.State;
	    	}


	    	if ( (channel_judge.Channel_11.State != channel_get_value.Channel_11.State) ||( channel_judge.Channel_11.FWtimeOFF != channel_get_value.Channel_11.FWtimeOFF)||
	    		 (channel_judge.Channel_11.Ibias != channel_get_value.Channel_11.Ibias) ||( channel_judge.Channel_11.IboostB != channel_get_value.Channel_11.IboostB)||
			     (channel_judge.Channel_11.Ihold != channel_get_value.Channel_11.Ihold) ||( channel_judge.Channel_11.Ipeak != channel_get_value.Channel_11.Ipeak)||
		         (channel_judge.Channel_11.Tbias_off != channel_get_value.Channel_11.Tbias_off) ||( channel_judge.Channel_11.Tbias_tot != channel_get_value.Channel_11.Tbias_tot)||
			     (channel_judge.Channel_11.Tbypass != channel_get_value.Channel_11.Tbypass) ||( channel_judge.Channel_11.Thold_off != channel_get_value.Channel_11.Thold_off)||
			     (channel_judge.Channel_11.Thold_tot != channel_get_value.Channel_11.Thold_tot) ||( channel_judge.Channel_11.Tpeak_off != channel_get_value.Channel_11.Tpeak_off)||
			     (channel_judge.Channel_11.Tpeak_tot != channel_get_value.Channel_11.Tpeak_tot) ||( channel_judge.Channel_11.Mode != channel_get_value.Channel_11.Mode)||
			     (channel_judge.Channel_11.IboostP != channel_get_value.Channel_11.IboostP) )
	    	{


	     	    channel_judge.Channel_11.IboostB   =  channel_get_value.Channel_11.IboostB;
				channel_judge.Channel_11.Tbias_tot =  channel_get_value.Channel_11.Tbias_tot;
				channel_judge.Channel_11.Tbias_off =  channel_get_value.Channel_11.Tbias_off ;
				channel_judge.Channel_11.Ibias     =  channel_get_value.Channel_11.Ibias;
				channel_judge.Channel_11.IboostP   =  channel_get_value.Channel_11.IboostP ;
				channel_judge.Channel_11.Tpeak_tot =  channel_get_value.Channel_11.Tpeak_tot;
				channel_judge.Channel_11.Tpeak_off =  channel_get_value.Channel_11.Tpeak_off;
				channel_judge.Channel_11.Ipeak     =  channel_get_value.Channel_11.Ipeak;
				channel_judge.Channel_11.Tbypass   =  channel_get_value.Channel_11.Tbypass;
				channel_judge.Channel_11.Thold_tot =  channel_get_value.Channel_11.Thold_tot ;
				channel_judge.Channel_11.Thold_off =  channel_get_value.Channel_11.Thold_off;
				channel_judge.Channel_11.Ihold     =  channel_get_value.Channel_11.Ihold ;
				channel_judge.Channel_11.FWtimeOFF =  channel_get_value.Channel_11.FWtimeOFF;
				channel_judge.Channel_11.State     =  channel_get_value.Channel_11.State;
				channel_judge.Channel_11.Mode      =  channel_get_value.Channel_11.Mode;


				channel.Channel_11.IboostB   =  channel_get_value.Channel_11.IboostB;
				channel.Channel_11.Tbias_tot =  channel_get_value.Channel_11.Tbias_tot;
				channel.Channel_11.Tbias_off =  channel_get_value.Channel_11.Tbias_off ;
				channel.Channel_11.Ibias     =  channel_get_value.Channel_11.Ibias;
				channel.Channel_11.IboostP   =  channel_get_value.Channel_11.IboostP ;
				channel.Channel_11.Tpeak_tot =  channel_get_value.Channel_11.Tpeak_tot;
				channel.Channel_11.Tpeak_off =  channel_get_value.Channel_11.Tpeak_off;
				channel.Channel_11.Ipeak     =  channel_get_value.Channel_11.Ipeak;
				channel.Channel_11.Tbypass   =  channel_get_value.Channel_11.Tbypass;
				channel.Channel_11.Thold_tot =  channel_get_value.Channel_11.Thold_tot ;
				channel.Channel_11.Thold_off =  channel_get_value.Channel_11.Thold_off;
				channel.Channel_11.Ihold     =  channel_get_value.Channel_11.Ihold ;
				channel.Channel_11.FWtimeOFF =  channel_get_value.Channel_11.FWtimeOFF;
				channel.Channel_11.Mode      =  channel_get_value.Channel_11.Mode;
				channel.Channel_11.State     =  channel_get_value.Channel_11.State;
	    	}


	    	if ( (channel_judge.Channel_12.State != channel_get_value.Channel_12.State) ||( channel_judge.Channel_12.FWtimeOFF != channel_get_value.Channel_12.FWtimeOFF)||
	    		 (channel_judge.Channel_12.Ibias != channel_get_value.Channel_12.Ibias) ||( channel_judge.Channel_12.IboostB != channel_get_value.Channel_12.IboostB)||
			     (channel_judge.Channel_12.Ihold != channel_get_value.Channel_12.Ihold) ||( channel_judge.Channel_12.Ipeak != channel_get_value.Channel_12.Ipeak)||
		         (channel_judge.Channel_12.Tbias_off != channel_get_value.Channel_12.Tbias_off) ||( channel_judge.Channel_12.Tbias_tot != channel_get_value.Channel_12.Tbias_tot)||
			     (channel_judge.Channel_12.Tbypass != channel_get_value.Channel_12.Tbypass) ||( channel_judge.Channel_12.Thold_off != channel_get_value.Channel_12.Thold_off)||
			     (channel_judge.Channel_12.Thold_tot != channel_get_value.Channel_12.Thold_tot) ||( channel_judge.Channel_12.Tpeak_off != channel_get_value.Channel_12.Tpeak_off)||
			     (channel_judge.Channel_12.Tpeak_tot != channel_get_value.Channel_12.Tpeak_tot) ||( channel_judge.Channel_12.Mode != channel_get_value.Channel_12.Mode)||
			     (channel_judge.Channel_12.IboostP != channel_get_value.Channel_12.IboostP) )
	    	{


	     	    channel_judge.Channel_12.IboostB   =  channel_get_value.Channel_12.IboostB;
				channel_judge.Channel_12.Tbias_tot =  channel_get_value.Channel_12.Tbias_tot;
				channel_judge.Channel_12.Tbias_off =  channel_get_value.Channel_12.Tbias_off ;
				channel_judge.Channel_12.Ibias     =  channel_get_value.Channel_12.Ibias;
				channel_judge.Channel_12.IboostP   =  channel_get_value.Channel_12.IboostP ;
				channel_judge.Channel_12.Tpeak_tot =  channel_get_value.Channel_12.Tpeak_tot;
				channel_judge.Channel_12.Tpeak_off =  channel_get_value.Channel_12.Tpeak_off;
				channel_judge.Channel_12.Ipeak     =  channel_get_value.Channel_12.Ipeak;
				channel_judge.Channel_12.Tbypass   =  channel_get_value.Channel_12.Tbypass;
				channel_judge.Channel_12.Thold_tot =  channel_get_value.Channel_12.Thold_tot ;
				channel_judge.Channel_12.Thold_off =  channel_get_value.Channel_12.Thold_off;
				channel_judge.Channel_12.Ihold     =  channel_get_value.Channel_12.Ihold ;
				channel_judge.Channel_12.FWtimeOFF =  channel_get_value.Channel_12.FWtimeOFF;
				channel_judge.Channel_12.State     =  channel_get_value.Channel_12.State;
				channel_judge.Channel_12.Mode      =  channel_get_value.Channel_12.Mode;


				channel.Channel_12.IboostB   =  channel_get_value.Channel_12.IboostB;
				channel.Channel_12.Tbias_tot =  channel_get_value.Channel_12.Tbias_tot;
				channel.Channel_12.Tbias_off =  channel_get_value.Channel_12.Tbias_off ;
				channel.Channel_12.Ibias     =  channel_get_value.Channel_12.Ibias;
				channel.Channel_12.IboostP   =  channel_get_value.Channel_12.IboostP ;
				channel.Channel_12.Tpeak_tot =  channel_get_value.Channel_12.Tpeak_tot;
				channel.Channel_12.Tpeak_off =  channel_get_value.Channel_12.Tpeak_off;
				channel.Channel_12.Ipeak     =  channel_get_value.Channel_12.Ipeak;
				channel.Channel_12.Tbypass   =  channel_get_value.Channel_12.Tbypass;
				channel.Channel_12.Thold_tot =  channel_get_value.Channel_12.Thold_tot ;
				channel.Channel_12.Thold_off =  channel_get_value.Channel_12.Thold_off;
				channel.Channel_12.Ihold     =  channel_get_value.Channel_12.Ihold ;
				channel.Channel_12.FWtimeOFF =  channel_get_value.Channel_12.FWtimeOFF;
				channel.Channel_12.Mode      =  channel_get_value.Channel_12.Mode;
				channel.Channel_12.State     =  channel_get_value.Channel_12.State;
	    	}


	    	if ( (channel_judge.Channel_13.State != channel_get_value.Channel_13.State) ||( channel_judge.Channel_13.FWtimeOFF != channel_get_value.Channel_13.FWtimeOFF)||
	    		 (channel_judge.Channel_13.Ibias != channel_get_value.Channel_13.Ibias) ||( channel_judge.Channel_13.IboostB != channel_get_value.Channel_13.IboostB)||
			     (channel_judge.Channel_13.Ihold != channel_get_value.Channel_13.Ihold) ||( channel_judge.Channel_13.Ipeak != channel_get_value.Channel_13.Ipeak)||
		         (channel_judge.Channel_13.Tbias_off != channel_get_value.Channel_13.Tbias_off) ||( channel_judge.Channel_13.Tbias_tot != channel_get_value.Channel_13.Tbias_tot)||
			     (channel_judge.Channel_13.Tbypass != channel_get_value.Channel_13.Tbypass) ||( channel_judge.Channel_13.Thold_off != channel_get_value.Channel_13.Thold_off)||
			     (channel_judge.Channel_13.Thold_tot != channel_get_value.Channel_13.Thold_tot) ||( channel_judge.Channel_13.Tpeak_off != channel_get_value.Channel_13.Tpeak_off)||
			     (channel_judge.Channel_13.Tpeak_tot != channel_get_value.Channel_13.Tpeak_tot) ||( channel_judge.Channel_13.Mode != channel_get_value.Channel_13.Mode)||
			     (channel_judge.Channel_13.IboostP != channel_get_value.Channel_13.IboostP) )
	    	{


	     	    channel_judge.Channel_13.IboostB   =  channel_get_value.Channel_13.IboostB;
				channel_judge.Channel_13.Tbias_tot =  channel_get_value.Channel_13.Tbias_tot;
				channel_judge.Channel_13.Tbias_off =  channel_get_value.Channel_13.Tbias_off ;
				channel_judge.Channel_13.Ibias     =  channel_get_value.Channel_13.Ibias;
				channel_judge.Channel_13.IboostP   =  channel_get_value.Channel_13.IboostP ;
				channel_judge.Channel_13.Tpeak_tot =  channel_get_value.Channel_13.Tpeak_tot;
				channel_judge.Channel_13.Tpeak_off =  channel_get_value.Channel_13.Tpeak_off;
				channel_judge.Channel_13.Ipeak     =  channel_get_value.Channel_13.Ipeak;
				channel_judge.Channel_13.Tbypass   =  channel_get_value.Channel_13.Tbypass;
				channel_judge.Channel_13.Thold_tot =  channel_get_value.Channel_13.Thold_tot ;
				channel_judge.Channel_13.Thold_off =  channel_get_value.Channel_13.Thold_off;
				channel_judge.Channel_13.Ihold     =  channel_get_value.Channel_13.Ihold ;
				channel_judge.Channel_13.FWtimeOFF =  channel_get_value.Channel_13.FWtimeOFF;
				channel_judge.Channel_13.State     =  channel_get_value.Channel_13.State;
				channel_judge.Channel_13.Mode      =  channel_get_value.Channel_13.Mode;


				channel.Channel_13.IboostB   =  channel_get_value.Channel_13.IboostB;
				channel.Channel_13.Tbias_tot =  channel_get_value.Channel_13.Tbias_tot;
				channel.Channel_13.Tbias_off =  channel_get_value.Channel_13.Tbias_off ;
				channel.Channel_13.Ibias     =  channel_get_value.Channel_13.Ibias;
				channel.Channel_13.IboostP   =  channel_get_value.Channel_13.IboostP ;
				channel.Channel_13.Tpeak_tot =  channel_get_value.Channel_13.Tpeak_tot;
				channel.Channel_13.Tpeak_off =  channel_get_value.Channel_13.Tpeak_off;
				channel.Channel_13.Ipeak     =  channel_get_value.Channel_13.Ipeak;
				channel.Channel_13.Tbypass   =  channel_get_value.Channel_13.Tbypass;
				channel.Channel_13.Thold_tot =  channel_get_value.Channel_13.Thold_tot ;
				channel.Channel_13.Thold_off =  channel_get_value.Channel_13.Thold_off;
				channel.Channel_13.Ihold     =  channel_get_value.Channel_13.Ihold ;
				channel.Channel_13.FWtimeOFF =  channel_get_value.Channel_13.FWtimeOFF;
				channel.Channel_13.Mode      =  channel_get_value.Channel_13.Mode;
				channel.Channel_13.State     =  channel_get_value.Channel_13.State;
	    	}


	    	if ( (channel_judge.Channel_14.State != channel_get_value.Channel_14.State) ||( channel_judge.Channel_14.FWtimeOFF != channel_get_value.Channel_14.FWtimeOFF)||
	    		 (channel_judge.Channel_14.Ibias != channel_get_value.Channel_14.Ibias) ||( channel_judge.Channel_14.IboostB != channel_get_value.Channel_14.IboostB)||
			     (channel_judge.Channel_14.Ihold != channel_get_value.Channel_14.Ihold) ||( channel_judge.Channel_14.Ipeak != channel_get_value.Channel_14.Ipeak)||
		         (channel_judge.Channel_14.Tbias_off != channel_get_value.Channel_14.Tbias_off) ||( channel_judge.Channel_14.Tbias_tot != channel_get_value.Channel_14.Tbias_tot)||
			     (channel_judge.Channel_14.Tbypass != channel_get_value.Channel_14.Tbypass) ||( channel_judge.Channel_14.Thold_off != channel_get_value.Channel_14.Thold_off)||
			     (channel_judge.Channel_14.Thold_tot != channel_get_value.Channel_14.Thold_tot) ||( channel_judge.Channel_14.Tpeak_off != channel_get_value.Channel_14.Tpeak_off)||
			     (channel_judge.Channel_14.Tpeak_tot != channel_get_value.Channel_14.Tpeak_tot) ||( channel_judge.Channel_14.Mode != channel_get_value.Channel_14.Mode)||
			     (channel_judge.Channel_14.IboostP != channel_get_value.Channel_14.IboostP) )
	    	{


	     	    channel_judge.Channel_14.IboostB   =  channel_get_value.Channel_14.IboostB;
				channel_judge.Channel_14.Tbias_tot =  channel_get_value.Channel_14.Tbias_tot;
				channel_judge.Channel_14.Tbias_off =  channel_get_value.Channel_14.Tbias_off ;
				channel_judge.Channel_14.Ibias     =  channel_get_value.Channel_14.Ibias;
				channel_judge.Channel_14.IboostP   =  channel_get_value.Channel_14.IboostP ;
				channel_judge.Channel_14.Tpeak_tot =  channel_get_value.Channel_14.Tpeak_tot;
				channel_judge.Channel_14.Tpeak_off =  channel_get_value.Channel_14.Tpeak_off;
				channel_judge.Channel_14.Ipeak     =  channel_get_value.Channel_14.Ipeak;
				channel_judge.Channel_14.Tbypass   =  channel_get_value.Channel_14.Tbypass;
				channel_judge.Channel_14.Thold_tot =  channel_get_value.Channel_14.Thold_tot ;
				channel_judge.Channel_14.Thold_off =  channel_get_value.Channel_14.Thold_off;
				channel_judge.Channel_14.Ihold     =  channel_get_value.Channel_14.Ihold ;
				channel_judge.Channel_14.FWtimeOFF =  channel_get_value.Channel_14.FWtimeOFF;
				channel_judge.Channel_14.State     =  channel_get_value.Channel_14.State;
				channel_judge.Channel_14.Mode      =  channel_get_value.Channel_14.Mode;


				channel.Channel_14.IboostB   =  channel_get_value.Channel_14.IboostB;
				channel.Channel_14.Tbias_tot =  channel_get_value.Channel_14.Tbias_tot;
				channel.Channel_14.Tbias_off =  channel_get_value.Channel_14.Tbias_off ;
				channel.Channel_14.Ibias     =  channel_get_value.Channel_14.Ibias;
				channel.Channel_14.IboostP   =  channel_get_value.Channel_14.IboostP ;
				channel.Channel_14.Tpeak_tot =  channel_get_value.Channel_14.Tpeak_tot;
				channel.Channel_14.Tpeak_off =  channel_get_value.Channel_14.Tpeak_off;
				channel.Channel_14.Ipeak     =  channel_get_value.Channel_14.Ipeak;
				channel.Channel_14.Tbypass   =  channel_get_value.Channel_14.Tbypass;
				channel.Channel_14.Thold_tot =  channel_get_value.Channel_14.Thold_tot ;
				channel.Channel_14.Thold_off =  channel_get_value.Channel_14.Thold_off;
				channel.Channel_14.Ihold     =  channel_get_value.Channel_14.Ihold ;
				channel.Channel_14.FWtimeOFF =  channel_get_value.Channel_14.FWtimeOFF;
				channel.Channel_14.Mode      =  channel_get_value.Channel_14.Mode;
				channel.Channel_14.State     =  channel_get_value.Channel_14.State;
	    	}


	    	if ( (channel_judge.Channel_15.State != channel_get_value.Channel_15.State) ||( channel_judge.Channel_15.FWtimeOFF != channel_get_value.Channel_15.FWtimeOFF)||
	    		 (channel_judge.Channel_15.Ibias != channel_get_value.Channel_15.Ibias) ||( channel_judge.Channel_15.IboostB != channel_get_value.Channel_15.IboostB)||
			     (channel_judge.Channel_15.Ihold != channel_get_value.Channel_15.Ihold) ||( channel_judge.Channel_15.Ipeak != channel_get_value.Channel_15.Ipeak)||
		         (channel_judge.Channel_15.Tbias_off != channel_get_value.Channel_15.Tbias_off) ||( channel_judge.Channel_15.Tbias_tot != channel_get_value.Channel_15.Tbias_tot)||
			     (channel_judge.Channel_15.Tbypass != channel_get_value.Channel_15.Tbypass) ||( channel_judge.Channel_15.Thold_off != channel_get_value.Channel_15.Thold_off)||
			     (channel_judge.Channel_15.Thold_tot != channel_get_value.Channel_15.Thold_tot) ||( channel_judge.Channel_15.Tpeak_off != channel_get_value.Channel_15.Tpeak_off)||
			     (channel_judge.Channel_15.Tpeak_tot != channel_get_value.Channel_15.Tpeak_tot) ||( channel_judge.Channel_15.Mode != channel_get_value.Channel_15.Mode)||
			     (channel_judge.Channel_15.IboostP != channel_get_value.Channel_15.IboostP) )
	    	{


	     	    channel_judge.Channel_15.IboostB   =  channel_get_value.Channel_15.IboostB;
				channel_judge.Channel_15.Tbias_tot =  channel_get_value.Channel_15.Tbias_tot;
				channel_judge.Channel_15.Tbias_off =  channel_get_value.Channel_15.Tbias_off ;
				channel_judge.Channel_15.Ibias     =  channel_get_value.Channel_15.Ibias;
				channel_judge.Channel_15.IboostP   =  channel_get_value.Channel_15.IboostP ;
				channel_judge.Channel_15.Tpeak_tot =  channel_get_value.Channel_15.Tpeak_tot;
				channel_judge.Channel_15.Tpeak_off =  channel_get_value.Channel_15.Tpeak_off;
				channel_judge.Channel_15.Ipeak     =  channel_get_value.Channel_15.Ipeak;
				channel_judge.Channel_15.Tbypass   =  channel_get_value.Channel_15.Tbypass;
				channel_judge.Channel_15.Thold_tot =  channel_get_value.Channel_15.Thold_tot ;
				channel_judge.Channel_15.Thold_off =  channel_get_value.Channel_15.Thold_off;
				channel_judge.Channel_15.Ihold     =  channel_get_value.Channel_15.Ihold ;
				channel_judge.Channel_15.FWtimeOFF =  channel_get_value.Channel_15.FWtimeOFF;
				channel_judge.Channel_15.State     =  channel_get_value.Channel_15.State;
				channel_judge.Channel_15.Mode      =  channel_get_value.Channel_15.Mode;


				channel.Channel_15.IboostB   =  channel_get_value.Channel_15.IboostB;
				channel.Channel_15.Tbias_tot =  channel_get_value.Channel_15.Tbias_tot;
				channel.Channel_15.Tbias_off =  channel_get_value.Channel_15.Tbias_off ;
				channel.Channel_15.Ibias     =  channel_get_value.Channel_15.Ibias;
				channel.Channel_15.IboostP   =  channel_get_value.Channel_15.IboostP ;
				channel.Channel_15.Tpeak_tot =  channel_get_value.Channel_15.Tpeak_tot;
				channel.Channel_15.Tpeak_off =  channel_get_value.Channel_15.Tpeak_off;
				channel.Channel_15.Ipeak     =  channel_get_value.Channel_15.Ipeak;
				channel.Channel_15.Tbypass   =  channel_get_value.Channel_15.Tbypass;
				channel.Channel_15.Thold_tot =  channel_get_value.Channel_15.Thold_tot ;
				channel.Channel_15.Thold_off =  channel_get_value.Channel_15.Thold_off;
				channel.Channel_15.Ihold     =  channel_get_value.Channel_15.Ihold ;
				channel.Channel_15.FWtimeOFF =  channel_get_value.Channel_15.FWtimeOFF;
				channel.Channel_15.Mode      =  channel_get_value.Channel_15.Mode;
				channel.Channel_15.State     =  channel_get_value.Channel_15.State;
	    	}


	    	if ( (channel_judge.Channel_16.State != channel_get_value.Channel_16.State) ||( channel_judge.Channel_16.FWtimeOFF != channel_get_value.Channel_16.FWtimeOFF)||
	    		 (channel_judge.Channel_16.Ibias != channel_get_value.Channel_16.Ibias) ||( channel_judge.Channel_16.IboostB != channel_get_value.Channel_16.IboostB)||
			     (channel_judge.Channel_16.Ihold != channel_get_value.Channel_16.Ihold) ||( channel_judge.Channel_16.Ipeak != channel_get_value.Channel_16.Ipeak)||
		         (channel_judge.Channel_16.Tbias_off != channel_get_value.Channel_16.Tbias_off) ||( channel_judge.Channel_16.Tbias_tot != channel_get_value.Channel_16.Tbias_tot)||
			     (channel_judge.Channel_16.Tbypass != channel_get_value.Channel_16.Tbypass) ||( channel_judge.Channel_16.Thold_off != channel_get_value.Channel_16.Thold_off)||
			     (channel_judge.Channel_16.Thold_tot != channel_get_value.Channel_16.Thold_tot) ||( channel_judge.Channel_16.Tpeak_off != channel_get_value.Channel_16.Tpeak_off)||
			     (channel_judge.Channel_16.Tpeak_tot != channel_get_value.Channel_16.Tpeak_tot) ||( channel_judge.Channel_16.Mode != channel_get_value.Channel_16.Mode)||
			     (channel_judge.Channel_16.IboostP != channel_get_value.Channel_16.IboostP) )
	    	{


	     	    channel_judge.Channel_16.IboostB   =  channel_get_value.Channel_16.IboostB;
				channel_judge.Channel_16.Tbias_tot =  channel_get_value.Channel_16.Tbias_tot;
				channel_judge.Channel_16.Tbias_off =  channel_get_value.Channel_16.Tbias_off ;
				channel_judge.Channel_16.Ibias     =  channel_get_value.Channel_16.Ibias;
				channel_judge.Channel_16.IboostP   =  channel_get_value.Channel_16.IboostP ;
				channel_judge.Channel_16.Tpeak_tot =  channel_get_value.Channel_16.Tpeak_tot;
				channel_judge.Channel_16.Tpeak_off =  channel_get_value.Channel_16.Tpeak_off;
				channel_judge.Channel_16.Ipeak     =  channel_get_value.Channel_16.Ipeak;
				channel_judge.Channel_16.Tbypass   =  channel_get_value.Channel_16.Tbypass;
				channel_judge.Channel_16.Thold_tot =  channel_get_value.Channel_16.Thold_tot ;
				channel_judge.Channel_16.Thold_off =  channel_get_value.Channel_16.Thold_off;
				channel_judge.Channel_16.Ihold     =  channel_get_value.Channel_16.Ihold ;
				channel_judge.Channel_16.FWtimeOFF =  channel_get_value.Channel_16.FWtimeOFF;
				channel_judge.Channel_16.State     =  channel_get_value.Channel_16.State;
				channel_judge.Channel_16.Mode      =  channel_get_value.Channel_16.Mode;


				channel.Channel_16.IboostB   =  channel_get_value.Channel_16.IboostB;
				channel.Channel_16.Tbias_tot =  channel_get_value.Channel_16.Tbias_tot;
				channel.Channel_16.Tbias_off =  channel_get_value.Channel_16.Tbias_off ;
				channel.Channel_16.Ibias     =  channel_get_value.Channel_16.Ibias;
				channel.Channel_16.IboostP   =  channel_get_value.Channel_16.IboostP ;
				channel.Channel_16.Tpeak_tot =  channel_get_value.Channel_16.Tpeak_tot;
				channel.Channel_16.Tpeak_off =  channel_get_value.Channel_16.Tpeak_off;
				channel.Channel_16.Ipeak     =  channel_get_value.Channel_16.Ipeak;
				channel.Channel_16.Tbypass   =  channel_get_value.Channel_16.Tbypass;
				channel.Channel_16.Thold_tot =  channel_get_value.Channel_16.Thold_tot ;
				channel.Channel_16.Thold_off =  channel_get_value.Channel_16.Thold_off;
				channel.Channel_16.Ihold     =  channel_get_value.Channel_16.Ihold ;
				channel.Channel_16.FWtimeOFF =  channel_get_value.Channel_16.FWtimeOFF;
				channel.Channel_16.Mode      =  channel_get_value.Channel_16.Mode;
				channel.Channel_16.State     =  channel_get_value.Channel_16.State;
	    	}

        if(((channel.Channel_1.State & 0x80) == 0x80)|| ((channel.Channel_2.State & 0x80) == 0x80) || ((channel.Channel_3.State & 0x80) == 0x80))
        {
            B_current_change = 1;

            x = 1;
            y = 1;

            if((channel.Channel_1.State & 0x80) == 0x80)
            ParamMap1(1,1);

            if((channel.Channel_2.State & 0x80) == 0x80)
            ParamMap1(1,2);

            if((channel.Channel_3.State & 0x80) == 0x80)
            ParamMap1(1,3);


            ProgramDevice_Data();


            SendCmd_EnChannel();

            channel.Channel_1.State  = channel.Channel_1.State & 0X7F;
            channel.Channel_2.State  = channel.Channel_2.State & 0X7F;
            channel.Channel_3.State  = channel.Channel_3.State & 0X7F;

            B_current_change = 0;

        	Set_StartPin_State(Channel_number_1, channel.Channel_1.State & 0X01);
		    Set_StartPin_State(Channel_number_2, channel.Channel_2.State & 0X01);
		    Set_StartPin_State(Channel_number_3, channel.Channel_3.State & 0X01);
        }


        if(((channel.Channel_4.State & 0x80) == 0x80)|| ((channel.Channel_5.State & 0x80) == 0x80) || ((channel.Channel_6.State & 0x80) == 0x80))
        {

            B_current_change = 1;
            x = 2;
            y = 2;

            if((channel.Channel_4.State & 0x80) == 0x80)
            ParamMap1(2,4);

            if((channel.Channel_5.State & 0x80) == 0x80)
            ParamMap1(2,5);

            if((channel.Channel_6.State & 0x80) == 0x80)
            ParamMap1(2,6);


            ProgramDevice_Data();


            SendCmd_EnChannel();

            channel.Channel_4.State  = channel.Channel_4.State & 0X7F;
            channel.Channel_5.State  = channel.Channel_5.State & 0X7F;
            channel.Channel_6.State  = channel.Channel_6.State & 0X7F;

            B_current_change = 0 ;

		    Set_StartPin_State(Channel_number_4, channel.Channel_4.State & 0X01);
		    Set_StartPin_State(Channel_number_5, channel.Channel_5.State & 0X01);
		    Set_StartPin_State(Channel_number_6, channel.Channel_6.State & 0X01);
        }

        if(((channel.Channel_7.State & 0x80) == 0x80)|| ((channel.Channel_8.State & 0x80) == 0x80) || ((channel.Channel_9.State & 0x80) == 0x80))
        {

            B_current_change = 1;
            x = 3;
            y = 3;

            if((channel.Channel_7.State & 0x80) == 0x80)
            ParamMap1(3,7);

            if((channel.Channel_8.State & 0x80) == 0x80)
            ParamMap1(3,8);

            if((channel.Channel_9.State & 0x80) == 0x80)
            ParamMap1(3,9);


            ProgramDevice_Data();


            SendCmd_EnChannel();

            channel.Channel_7.State  = channel.Channel_7.State & 0X7F;
            channel.Channel_8.State  = channel.Channel_8.State & 0X7F;
            channel.Channel_9.State  = channel.Channel_9.State & 0X7F;

            B_current_change = 0;

		    Set_StartPin_State(Channel_number_7, channel.Channel_7.State & 0X01);
		    Set_StartPin_State(Channel_number_8, channel.Channel_8.State & 0X01);
		    Set_StartPin_State(Channel_number_9,  channel.Channel_9.State & 0X01);
        }

        if(((channel.Channel_10.State & 0x80) == 0x80)|| ((channel.Channel_11.State & 0x80) == 0x80) || ((channel.Channel_12.State & 0x80) == 0x80))
        {

            B_current_change = 1;
            x = 4;
            y = 4;

            if((channel.Channel_10.State & 0x80) == 0x80)
            ParamMap1(4,10);

            if((channel.Channel_11.State & 0x80) == 0x80)
            ParamMap1(4,11);

            if((channel.Channel_12.State & 0x80) == 0x80)
            ParamMap1(4,12);


            ProgramDevice_Data();


            SendCmd_EnChannel();

            channel.Channel_10.State  = channel.Channel_10.State & 0X7F;
            channel.Channel_11.State  = channel.Channel_11.State & 0X7F;
            channel.Channel_12.State  = channel.Channel_12.State & 0X7F;

            B_current_change = 0;

		    Set_StartPin_State(Channel_number_10, channel.Channel_10.State & 0X01);
		    Set_StartPin_State(Channel_number_11, channel.Channel_11.State & 0X01);
		    Set_StartPin_State(Channel_number_12, channel.Channel_12.State & 0X01);
        }


        if( ((channel.Channel_14.State & 0x80) == 0x80) || ((channel.Channel_15.State & 0x80) == 0x80))
        {

            B_current_change = 1;
            x = 5;
            y = 5;

            if((channel.Channel_14.State & 0x80) == 0x80)
            ParamMap1(5,14);

            if((channel.Channel_15.State & 0x80) == 0x80)
            ParamMap1(5,15);



            ProgramDevice_Data();


            SendCmd_EnChannel();

            channel.Channel_14.State  = channel.Channel_14.State & 0X7F;
            channel.Channel_15.State  = channel.Channel_15.State & 0X7F;

            B_current_change = 0;

		    Set_StartPin_State(Channel_number_14, channel.Channel_14.State & 0X01);
		    Set_StartPin_State(Channel_number_15, channel.Channel_15.State & 0X01);
        }

        if(((channel.Channel_13.State & 0x80) == 0x80)|| ((channel.Channel_16.State & 0x80) == 0x80) )
        {

            B_current_change = 1;
            x = 6;
            y = 6;

            if((channel.Channel_13.State & 0x80) == 0x80)
            ParamMap1(6,13);

            if((channel.Channel_16.State & 0x80) == 0x80)
            ParamMap1(6,16);


            ProgramDevice_Data();


            SendCmd_EnChannel();

            channel.Channel_13.State  = channel.Channel_13.State & 0X7F;
            channel.Channel_16.State  = channel.Channel_16.State & 0X7F;

            B_current_change = 0;

		    Set_StartPin_State(Channel_number_13, channel.Channel_13.State & 0X01);
		    Set_StartPin_State(Channel_number_16, channel.Channel_16.State & 0X01);

        }



        	Set_StartPin_State(Channel_number_1, channel.Channel_1.State & 0X01);
		    Set_StartPin_State(Channel_number_2, channel.Channel_2.State & 0X01);
		    Set_StartPin_State(Channel_number_3, channel.Channel_3.State & 0X01);
		    Set_StartPin_State(Channel_number_4, channel.Channel_4.State & 0X01);
		    Set_StartPin_State(Channel_number_5, channel.Channel_5.State & 0X01);
		    Set_StartPin_State(Channel_number_6, channel.Channel_6.State & 0X01);
		    Set_StartPin_State(Channel_number_7, channel.Channel_7.State & 0X01);
		    Set_StartPin_State(Channel_number_8, channel.Channel_8.State & 0X01);
		    Set_StartPin_State(Channel_number_9,  channel.Channel_9.State & 0X01);
		    Set_StartPin_State(Channel_number_10, channel.Channel_10.State & 0X01);
		    Set_StartPin_State(Channel_number_11, channel.Channel_11.State & 0X01);
		    Set_StartPin_State(Channel_number_12, channel.Channel_12.State & 0X01);
		    Set_StartPin_State(Channel_number_13, channel.Channel_13.State & 0X01);
		    Set_StartPin_State(Channel_number_14, channel.Channel_14.State & 0X01);
		    Set_StartPin_State(Channel_number_15, channel.Channel_15.State & 0X01);
		    Set_StartPin_State(Channel_number_16, channel.Channel_16.State & 0X01);


//           Set_StartPin_State(Channel_number_17, channel.Channel_13.State & 0X01);
//           Set_StartPin_State(Channel_number_18, channel.Channel_16.State & 0X01);
    }

}




// PT2000  赋值函数
void Channel_Select(uint8 valve_number , ValveParam  ValveParamCH )
{
	   switch(valve_number)
	    {
	        case 1:

	        	 channel.Channel_1 = ValveParamCH;
	            break;
	        case 2:
	        	 channel.Channel_2  = ValveParamCH;
	            break;
	        case 3:
	        	 channel.Channel_3  = ValveParamCH;
	            break;
	        case 4:
	        	 channel.Channel_4  = ValveParamCH;
	            break;
	        case 5:
	        	 channel.Channel_5  = ValveParamCH;
	            break;
	        case 6:
	        	 channel.Channel_6  = ValveParamCH;
	            break;
	        case 7:
	        	 channel.Channel_7  = ValveParamCH;
	            break;
	        case 8:
	        	 channel.Channel_8  = ValveParamCH;
	            break;
	        case 9:
	        	 channel.Channel_9  = ValveParamCH;
	            break;
	        case 10:
	        	 channel.Channel_10  = ValveParamCH;
	            break;
	        case 11:
	        	 channel.Channel_11  = ValveParamCH;
	            break;
	        case 12:
	        	 channel.Channel_12  = ValveParamCH;
	            break;
	        case 13:
	        	 channel.Channel_13  = ValveParamCH;
	            break;
	        case 14:
	        	 channel.Channel_14  = ValveParamCH;
	            break;
	        case 15:
	        	 channel.Channel_15  = ValveParamCH;
	            break;
	        case 16:
	        	 channel.Channel_16  = ValveParamCH;
	            break;
	        default:
	            break;
}
}


// 电磁阀芯片1恒流模式转换PEAK模式  控制判断函数
void pt2000_mode_control_download_judge_valve1_constant_to_peak(uint8 valve_number , Valve_Select * m_Valve_Select)
{

	ValveParam ValveParamCH;
    if((m_Valve_Select->B_Valve_2_Mode == 0) && (m_Valve_Select->B_Valve_3_Mode  == 0))
     {

             x = (valve_number + 2) / 3;
             y = (valve_number + 2) / 3;

             initValveParamConfig(&ValveParamCH, valve_number, Peak_Hold_Mode);
             Channel_Select(valve_number , ValveParamCH);
             ParamMap((valve_number + 2) / 3);
             ProgramDevice_Peak1_Constant2_Constant3();
             SendCmd_EnChannel();
             m_Valve_Select->B_Valve_1_Mode  = 1;
     }
     if((m_Valve_Select->B_Valve_2_Mode  == 0) && (m_Valve_Select->B_Valve_3_Mode  == 1) )
     {

             x = (valve_number + 2) / 3;
             y = (valve_number + 2) / 3;

             initValveParamConfig(&ValveParamCH, valve_number, Peak_Hold_Mode);
             Channel_Select(valve_number , ValveParamCH);
             ParamMap((valve_number + 2) / 3);

             ProgramDevice_Peak1_Constant2_Peak3();

             SendCmd_EnChannel();
             m_Valve_Select->B_Valve_1_Mode  = 1;
     }
     if((m_Valve_Select->B_Valve_2_Mode  == 1) && (m_Valve_Select->B_Valve_3_Mode  == 0) )
     {
             x = (valve_number + 2) / 3;
             y = (valve_number + 2) / 3;

             initValveParamConfig(&ValveParamCH, valve_number, Peak_Hold_Mode);
             Channel_Select(valve_number , ValveParamCH);
             ParamMap((valve_number + 2) / 3);


             ProgramDevice_Peak1_Peak2_Constant3();

             SendCmd_EnChannel();
             m_Valve_Select->B_Valve_1_Mode  = 1;
     }

     if((m_Valve_Select->B_Valve_2_Mode  == 1) && (m_Valve_Select->B_Valve_3_Mode  == 1) )
     {
             x = (valve_number + 2) / 3;
             y = (valve_number + 2) / 3;

             initValveParamConfig(&ValveParamCH, valve_number, Peak_Hold_Mode);
             Channel_Select(valve_number , ValveParamCH);
             ParamMap((valve_number + 2) / 3);


             ProgramDevice_Peak();

             SendCmd_EnChannel();
             m_Valve_Select->B_Valve_1_Mode  = 1;
     }
}


// 电磁阀芯片1PEAK模式转换恒流模式  控制判断函数
void pt2000_mode_control_download_judge_valve1_peak_to_constant(uint8 valve_number , Valve_Select * m_Valve_Select)
{
	ValveParam ValveParamCH;
    if((m_Valve_Select->B_Valve_2_Mode == 0) && (m_Valve_Select->B_Valve_3_Mode == 0) )
    {
            x = (valve_number + 2) / 3;
            y = (valve_number + 2) / 3;

            initValveParamConfig(&ValveParamCH, valve_number, ConstantCurrent_Mode);
            Channel_Select(valve_number , ValveParamCH);
            ParamMap((valve_number + 2) / 3);


            ProgramDevice();

            SendCmd_EnChannel();
            m_Valve_Select->B_Valve_1_Mode  = 0;

    }

    if((m_Valve_Select->B_Valve_2_Mode  == 0) && (m_Valve_Select->B_Valve_3_Mode  == 1) )
    {
            x = (valve_number + 2) / 3;
            y = (valve_number + 2) / 3;

            initValveParamConfig(&ValveParamCH, valve_number, ConstantCurrent_Mode);
            Channel_Select(valve_number , ValveParamCH);
            ParamMap((valve_number + 2) / 3);

            ProgramDevice_Constant1_Constant2_Peak3();

            SendCmd_EnChannel();
            m_Valve_Select->B_Valve_1_Mode  = 0;

    }

    if((m_Valve_Select->B_Valve_2_Mode  == 1) && (m_Valve_Select->B_Valve_3_Mode  == 0) )
    {
            x = (valve_number + 2) / 3;
            y = (valve_number + 2) / 3;


            initValveParamConfig(&ValveParamCH, valve_number, ConstantCurrent_Mode);
            Channel_Select(valve_number , ValveParamCH);
            ParamMap((valve_number + 2) / 3);

            ProgramDevice_Constant1_Peak2_Constant3();

            SendCmd_EnChannel();
            m_Valve_Select->B_Valve_1_Mode  = 0;

    }

    if((m_Valve_Select->B_Valve_2_Mode  == 1) && (m_Valve_Select->B_Valve_3_Mode  == 1) )
    {
            x = (valve_number + 2) / 3;
            y = (valve_number + 2) / 3;

            initValveParamConfig(&ValveParamCH, valve_number, ConstantCurrent_Mode);
            Channel_Select(valve_number , ValveParamCH);
            ParamMap((valve_number + 2) / 3);

            ProgramDevice_Constant1_Peak2_Peak3();

            SendCmd_EnChannel();
            m_Valve_Select->B_Valve_1_Mode  = 0;
    }
}




// 电磁阀芯片2恒流模式转换peak模式  控制判断函数
void pt2000_mode_control_download_judge_valve2_constant_to_peak(uint8 valve_number , Valve_Select * m_Valve_Select)
{

	ValveParam ValveParamCH;
    if((m_Valve_Select->B_Valve_1_Mode == 0) && (m_Valve_Select->B_Valve_3_Mode  == 0))
     {

             x = (valve_number + 2) / 3;
             y = (valve_number + 2) / 3;

             initValveParamConfig(&ValveParamCH, valve_number, Peak_Hold_Mode);
             Channel_Select(valve_number , ValveParamCH);
             ParamMap((valve_number + 2) / 3);
             ProgramDevice_Constant1_Peak2_Constant3();;
             SendCmd_EnChannel();
             m_Valve_Select->B_Valve_2_Mode  = 1;
     }
     if((m_Valve_Select->B_Valve_1_Mode  == 0) && (m_Valve_Select->B_Valve_3_Mode  == 1) )
     {

        	 x = (valve_number + 2) / 3;
        	 y = (valve_number + 2) / 3;


             initValveParamConfig(&ValveParamCH, valve_number, Peak_Hold_Mode);
             Channel_Select(valve_number , ValveParamCH);
             ParamMap((valve_number + 2) / 3);

             ProgramDevice_Constant1_Peak2_Peak3();

             SendCmd_EnChannel();
             m_Valve_Select->B_Valve_2_Mode  = 1;
     }
     if((m_Valve_Select->B_Valve_1_Mode  == 1) && (m_Valve_Select->B_Valve_3_Mode  == 0) )
     {
			 x = (valve_number + 2) / 3;
			 y = (valve_number + 2) / 3;

             initValveParamConfig(&ValveParamCH, valve_number, Peak_Hold_Mode);
             Channel_Select(valve_number , ValveParamCH);
             ParamMap((valve_number + 2) / 3);


             ProgramDevice_Peak1_Peak2_Constant3();

             SendCmd_EnChannel();
             m_Valve_Select->B_Valve_2_Mode  = 1;
     }

     if((m_Valve_Select->B_Valve_1_Mode  == 1) && (m_Valve_Select->B_Valve_3_Mode  == 1) )
     {
			 x = (valve_number + 2) / 3;
			 y = (valve_number + 2) / 3;

             initValveParamConfig(&ValveParamCH, valve_number, Peak_Hold_Mode);
             Channel_Select(valve_number , ValveParamCH);
             ParamMap((valve_number + 2) / 3);


             ProgramDevice_Peak();

             SendCmd_EnChannel();
             m_Valve_Select->B_Valve_2_Mode  = 1;
     }
}


// 电磁阀芯片2PEAK模式转换恒流模式  控制判断函数
void pt2000_mode_control_download_judge_valve2_peak_to_constant(uint8 valve_number , Valve_Select * m_Valve_Select)
{
	ValveParam ValveParamCH;
    if((m_Valve_Select->B_Valve_1_Mode == 0) && (m_Valve_Select->B_Valve_3_Mode == 0) )
    {
			 x = (valve_number + 2) / 3;
			 y = (valve_number + 2) / 3;

            initValveParamConfig(&ValveParamCH, valve_number, ConstantCurrent_Mode);
            Channel_Select(valve_number , ValveParamCH);
            ParamMap((valve_number + 2) / 3);


            ProgramDevice();

            SendCmd_EnChannel();
            m_Valve_Select->B_Valve_2_Mode  = 0;

    }

    if((m_Valve_Select->B_Valve_1_Mode  == 0) && (m_Valve_Select->B_Valve_3_Mode  == 1) )
    {
			 x = (valve_number + 2) / 3;
			 y = (valve_number + 2) / 3;

            initValveParamConfig(&ValveParamCH, valve_number, ConstantCurrent_Mode);
            Channel_Select(valve_number , ValveParamCH);
            ParamMap((valve_number + 2) / 3);

            ProgramDevice_Constant1_Constant2_Peak3();

            SendCmd_EnChannel();
            m_Valve_Select->B_Valve_2_Mode  = 0;

    }

    if((m_Valve_Select->B_Valve_1_Mode  == 1) && (m_Valve_Select->B_Valve_3_Mode  == 0) )
    {
			 x = (valve_number + 2) / 3;
			 y = (valve_number + 2) / 3;


            initValveParamConfig(&ValveParamCH, valve_number, ConstantCurrent_Mode);
            Channel_Select(valve_number , ValveParamCH);
            ParamMap((valve_number + 2) / 3);

            ProgramDevice_Peak1_Constant2_Constant3();

            SendCmd_EnChannel();
            m_Valve_Select->B_Valve_2_Mode  = 0;

    }

    if((m_Valve_Select->B_Valve_1_Mode  == 1) && (m_Valve_Select->B_Valve_3_Mode  == 1) )
    {
			 x = (valve_number + 2) / 3;
			 y = (valve_number + 2) / 3;

            initValveParamConfig(&ValveParamCH, valve_number, ConstantCurrent_Mode);
            Channel_Select(valve_number , ValveParamCH);
            ParamMap((valve_number + 2) / 3);

            ProgramDevice_Peak1_Constant2_Peak3();

            SendCmd_EnChannel();
            m_Valve_Select->B_Valve_2_Mode  = 0;
    }
}



// 电磁阀芯片3恒流模式转换peak模式  控制判断函数
void pt2000_mode_control_download_judge_valve3_constant_to_peak(uint8 valve_number , Valve_Select * m_Valve_Select)
{

	ValveParam ValveParamCH;
    if((m_Valve_Select->B_Valve_1_Mode == 0) && (m_Valve_Select->B_Valve_2_Mode  == 0))
     {

             x = (valve_number + 2) / 3;
             y = (valve_number + 2) / 3;

             initValveParamConfig(&ValveParamCH, valve_number, Peak_Hold_Mode);
             Channel_Select(valve_number , ValveParamCH);
             ParamMap((valve_number + 2) / 3);
             ProgramDevice_Constant1_Constant2_Peak3();
             SendCmd_EnChannel();
             m_Valve_Select->B_Valve_3_Mode  = 1;
     }
     if((m_Valve_Select->B_Valve_1_Mode  == 0) && (m_Valve_Select->B_Valve_2_Mode  == 1) )
     {

        	 x = (valve_number + 2) / 3;
        	 y = (valve_number + 2) / 3;


             initValveParamConfig(&ValveParamCH, valve_number, Peak_Hold_Mode);
             Channel_Select(valve_number , ValveParamCH);
             ParamMap((valve_number + 2) / 3);

             ProgramDevice_Constant1_Peak2_Peak3();

             SendCmd_EnChannel();
             m_Valve_Select->B_Valve_3_Mode  = 1;
     }
     if((m_Valve_Select->B_Valve_1_Mode  == 1) && (m_Valve_Select->B_Valve_2_Mode  == 0) )
     {
			 x = (valve_number + 2) / 3;
			 y = (valve_number + 2) / 3;

             initValveParamConfig(&ValveParamCH, valve_number, Peak_Hold_Mode);
             Channel_Select(valve_number , ValveParamCH);
             ParamMap((valve_number + 2) / 3);


             ProgramDevice_Peak1_Constant2_Peak3();

             SendCmd_EnChannel();
             m_Valve_Select->B_Valve_3_Mode  = 1;
     }

     if((m_Valve_Select->B_Valve_1_Mode  == 1) && (m_Valve_Select->B_Valve_2_Mode  == 1) )
     {
			 x = (valve_number + 2) / 3;
			 y = (valve_number + 2) / 3;

             initValveParamConfig(&ValveParamCH, valve_number, Peak_Hold_Mode);
             Channel_Select(valve_number , ValveParamCH);
             ParamMap((valve_number + 2) / 3);


             ProgramDevice_Peak();

             SendCmd_EnChannel();
             m_Valve_Select->B_Valve_3_Mode  = 1;
     }
}


// 电磁阀芯片3PEAK模式转换恒流模式  控制判断函数
void pt2000_mode_control_download_judge_valve3_peak_to_constant(uint8 valve_number , Valve_Select * m_Valve_Select)
{
	ValveParam ValveParamCH;
    if((m_Valve_Select->B_Valve_1_Mode == 0) && (m_Valve_Select->B_Valve_2_Mode == 0) )
    {
			 x = (valve_number + 2) / 3;
			 y = (valve_number + 2) / 3;

            initValveParamConfig(&ValveParamCH, valve_number, ConstantCurrent_Mode);
            Channel_Select(valve_number , ValveParamCH);
            ParamMap((valve_number + 2) / 3);


            ProgramDevice();

            SendCmd_EnChannel();
            m_Valve_Select->B_Valve_3_Mode  = 0;

    }

    if((m_Valve_Select->B_Valve_1_Mode  == 0) && (m_Valve_Select->B_Valve_2_Mode  == 1) )
    {
			 x = (valve_number + 2) / 3;
			 y = (valve_number + 2) / 3;

            initValveParamConfig(&ValveParamCH, valve_number, ConstantCurrent_Mode);
            Channel_Select(valve_number , ValveParamCH);
            ParamMap((valve_number + 2) / 3);

            ProgramDevice_Constant1_Peak2_Constant3();

            SendCmd_EnChannel();
            m_Valve_Select->B_Valve_3_Mode  = 0;

    }

    if((m_Valve_Select->B_Valve_1_Mode  == 1) && (m_Valve_Select->B_Valve_2_Mode  == 0) )
    {
			 x = (valve_number + 2) / 3;
			 y = (valve_number + 2) / 3;


            initValveParamConfig(&ValveParamCH, valve_number, ConstantCurrent_Mode);
            Channel_Select(valve_number , ValveParamCH);
            ParamMap((valve_number + 2) / 3);

            ProgramDevice_Peak1_Constant2_Constant3();

            SendCmd_EnChannel();
            m_Valve_Select->B_Valve_3_Mode  = 0;

    }

    if((m_Valve_Select->B_Valve_2_Mode  == 1) && (m_Valve_Select->B_Valve_3_Mode  == 1) )
    {
			 x = (valve_number + 2) / 3;
			 y = (valve_number + 2) / 3;

            initValveParamConfig(&ValveParamCH, valve_number, ConstantCurrent_Mode);
            Channel_Select(valve_number , ValveParamCH);
            ParamMap((valve_number + 2) / 3);

            ProgramDevice_Peak1_Peak2_Constant3();

            SendCmd_EnChannel();
            m_Valve_Select->B_Valve_3_Mode  = 0;
    }
}
//模式判断芯片1通道
//Valve_State = 1  constant to peak     Valve_State = 0 peak to constant
void pt2000_mode_control_judge_valve1(uint8 valve_number,Valve_Select * m_Valve_Select,uint8 Valve_State)
{
	if(Valve_State == 1)
	{
		   if(Mode_Change_Time_code == 10)
			{
			   Set_RESETPin_Low((valve_number + 2) / 3);
			}


		   if(Mode_Change_Time_code == 11)
			{


				 Set_RESETPin_High((valve_number + 2) / 3);
			}

		  if(Mode_Change_Time_code == 20)
		   {
			  pt2000_mode_control_download_judge_valve1_constant_to_peak(valve_number,m_Valve_Select);


		   }

	}



	if(Valve_State == 0)
	{
		   if(Mode_Change_Time_code == 10)
			{
			   Set_RESETPin_Low((valve_number + 2) / 3);
			}


		   if(Mode_Change_Time_code == 11)
			{


				 Set_RESETPin_High((valve_number + 2) / 3);
			}


		  if(Mode_Change_Time_code == 20)
		   {
			 pt2000_mode_control_download_judge_valve1_peak_to_constant(valve_number,m_Valve_Select);

		   }
	}

}



//模式判断芯片2通道
void pt2000_mode_control_judge_valve2(uint8 valve_number,Valve_Select * m_Valve_Select,uint8 Valve_State)
{
	if(Valve_State == 1)
	{
		   if(Mode_Change_Time_code == 10)
			{
			   Set_RESETPin_Low((valve_number + 2) / 3);
			}


		   if(Mode_Change_Time_code == 11)
			{


				 Set_RESETPin_High((valve_number + 2) / 3);
			}


		  if(Mode_Change_Time_code == 20)
		   {
			  pt2000_mode_control_download_judge_valve2_constant_to_peak(valve_number,m_Valve_Select);

		   }

	}



	if(Valve_State == 0)
	{
		   if(Mode_Change_Time_code == 10)
			{
			   Set_RESETPin_Low((valve_number + 2) / 3);
			}


		   if(Mode_Change_Time_code == 11)
			{


				 Set_RESETPin_High((valve_number + 2) / 3);
			}


		  if(Mode_Change_Time_code == 20)
		   {
			 pt2000_mode_control_download_judge_valve2_peak_to_constant(valve_number,m_Valve_Select);

		   }
	}
}



//模式判断芯片3通道
void pt2000_mode_control_judge_valve3(uint8 valve_number,Valve_Select * m_Valve_Select,uint8 Valve_State)
{
	if(Valve_State == 1)
	{
		   if(Mode_Change_Time_code == 10)
			{
			   Set_RESETPin_Low((valve_number + 2) / 3);
			}


		   if(Mode_Change_Time_code == 11)
			{
				 Set_RESETPin_High((valve_number + 2) / 3);
			}


		  if(Mode_Change_Time_code == 20)
		   {
			  pt2000_mode_control_download_judge_valve3_constant_to_peak(valve_number,m_Valve_Select);
		   }

	}



	if(Valve_State == 0)
	{
		   if(Mode_Change_Time_code == 10)
			{
			   Set_RESETPin_Low((valve_number + 2) / 3);
			}


		   if(Mode_Change_Time_code == 11)
			{


				 Set_RESETPin_High((valve_number + 2) / 3);
			}


		  if(Mode_Change_Time_code == 20)
		   {
			 pt2000_mode_control_download_judge_valve3_peak_to_constant(valve_number,m_Valve_Select);


		   }
	}
}

// 模式转换判断 返回控制命令
uint8 * Pt2000_State(uint8 * a)
{
	// a[0]  is  valve number  a[1] is change state (1 is constant to peak  0 is peak to constant )


	a[0] = 0;
	a[1] = 0;
    if (m_Chip_Select.Chip1.B_Valve_1_Mode  == 0)
    {
        if(channel.Channel_1.Mode == 1)
        {
        	a[0] = 1;
        	a[1] = 1;

        	return a;
        }
    }

    if (m_Chip_Select.Chip1.B_Valve_1_Mode  == 1)
    {
        if(channel.Channel_1.Mode == 0)
        {
        	a[0] = 1;
        	a[1] = 0;
        	return a;
        }
    }



    if (m_Chip_Select.Chip1.B_Valve_2_Mode  == 0)
    {
        if(channel.Channel_2.Mode == 1)
        {
        	a[0] = 2;
        	a[1] = 1;
        	return a;
        }
    }

    if (m_Chip_Select.Chip1.B_Valve_2_Mode  == 1)
    {
        if(channel.Channel_2.Mode == 0)
        {
        	a[0] = 2;
        	a[1] = 0;
        	return a;
        }
    }


    if (m_Chip_Select.Chip1.B_Valve_3_Mode  == 0)
    {
        if(channel.Channel_3.Mode == 1)
        {
        	a[0] = 3;
        	a[1] = 1;
        	return a;
        }
    }

    if (m_Chip_Select.Chip1.B_Valve_3_Mode  == 1)
    {
        if(channel.Channel_3.Mode == 0)
        {
        	a[0] = 3;
        	a[1] = 0;
        	return a;
        }
    }


    if (m_Chip_Select.Chip2.B_Valve_1_Mode  == 0)
    {
        if(channel.Channel_4.Mode == 1)
        {
        	a[0] = 4;
        	a[1] = 1;
        	return a;
        }
    }

    if (m_Chip_Select.Chip2.B_Valve_1_Mode  == 1)
    {
        if(channel.Channel_4.Mode == 0)
        {
        	a[0] = 4;
        	a[1] = 0;
        	return a;
        }
    }


    if (m_Chip_Select.Chip2.B_Valve_2_Mode  == 0)
    {
        if(channel.Channel_5.Mode == 1)
        {
        	a[0] = 5;
        	a[1] = 1;
        	return a;
        }
    }

    if (m_Chip_Select.Chip2.B_Valve_2_Mode  == 1)
    {
        if(channel.Channel_5.Mode == 0)
        {
        	a[0] = 5;
        	a[1] = 0;
        	return a;
        }
    }


    if (m_Chip_Select.Chip2.B_Valve_3_Mode  == 0)
    {
        if(channel.Channel_6.Mode == 1)
        {
        	a[0] = 6;
        	a[1] = 1;
        	return a;
        }
    }

    if (m_Chip_Select.Chip2.B_Valve_3_Mode  == 1)
    {
        if(channel.Channel_6.Mode == 0)
        {
        	a[0] = 6;
        	a[1] = 0;
        	return a;
        }
    }



    if (m_Chip_Select.Chip3.B_Valve_1_Mode  == 0)
    {
        if(channel.Channel_7.Mode == 1)
        {
        	a[0] = 7;
        	a[1] = 1;
        	return a;
        }
    }

    if (m_Chip_Select.Chip3.B_Valve_1_Mode  == 1)
    {
        if(channel.Channel_7.Mode == 0)
        {
        	a[0] = 7;
        	a[1] = 0;
        	return a;
        }
    }


    if (m_Chip_Select.Chip3.B_Valve_2_Mode  == 0)
    {
        if(channel.Channel_8.Mode == 1)
        {
        	a[0] = 8;
        	a[1] = 1;
        	return a;
        }
    }

    if (m_Chip_Select.Chip3.B_Valve_2_Mode  == 1)
    {
        if(channel.Channel_8.Mode == 0)
        {
        	a[0] = 8;
        	a[1] = 0;
        	return a;
        }
    }


    if (m_Chip_Select.Chip3.B_Valve_3_Mode  == 0)
    {
        if(channel.Channel_9.Mode == 1)
        {
        	a[0] = 9;
        	a[1] = 1;
        	return a;
        }
    }

    if (m_Chip_Select.Chip3.B_Valve_3_Mode  == 1)
    {
        if(channel.Channel_9.Mode == 0)
        {
        	a[0] = 9;
        	a[1] = 0;
        	return a;
        }
    }



    if (m_Chip_Select.Chip4.B_Valve_1_Mode  == 0)
    {
        if(channel.Channel_10.Mode == 1)
        {
        	a[0] = 10;
        	a[1] = 1;
        	return a;
        }
    }

    if (m_Chip_Select.Chip4.B_Valve_1_Mode  == 1)
    {
        if(channel.Channel_10.Mode == 0)
        {
        	a[0] = 10;
        	a[1] = 0;
        	return a;
        }
    }


    if (m_Chip_Select.Chip4.B_Valve_2_Mode  == 0)
    {
        if(channel.Channel_11.Mode == 1)
        {
        	a[0] = 11;
        	a[1] = 1;
        	return a;
        }
    }

    if (m_Chip_Select.Chip4.B_Valve_2_Mode  == 1)
    {
        if(channel.Channel_11.Mode == 0)
        {
        	a[0] = 11;
        	a[1] = 0;
        	return a;
        }
    }


    if (m_Chip_Select.Chip4.B_Valve_3_Mode  == 0)
    {
        if(channel.Channel_12.Mode == 1)
        {
        	a[0] = 12;
        	a[1] = 1;
        	return a;
        }
    }

    if (m_Chip_Select.Chip4.B_Valve_3_Mode  == 1)
    {
        if(channel.Channel_12.Mode == 0)
        {
        	a[0] = 12;
        	a[1] = 0;
        	return a;
        }
    }



    if (m_Chip_Select.Chip5.B_Valve_1_Mode  == 0)
    {
        if(channel.Channel_13.Mode == 1)
        {
        	a[0] = 13;
        	a[1] = 1;
        	return a;
        }
    }

    if (m_Chip_Select.Chip5.B_Valve_1_Mode  == 1)
    {
        if(channel.Channel_13.Mode == 0)
        {
        	a[0] = 13;
        	a[1] = 0;
        	return a;
        }
    }


    if (m_Chip_Select.Chip5.B_Valve_2_Mode  == 0)
    {
        if(channel.Channel_14.Mode == 1)
        {
        	a[0] = 14;
        	a[1] = 1;
        	return a;
        }
    }

    if (m_Chip_Select.Chip5.B_Valve_2_Mode  == 1)
    {
        if(channel.Channel_5.Mode == 0)
        {
        	a[0] = 14;
        	a[1] = 0;
        	return a;
        }
    }


    if (m_Chip_Select.Chip5.B_Valve_3_Mode  == 0)
    {
        if(channel.Channel_15.Mode == 1)
        {
        	a[0] = 15;
        	a[1] = 1;
        	return a;
        }
    }

    if (m_Chip_Select.Chip5.B_Valve_3_Mode  == 1)
    {
        if(channel.Channel_15.Mode == 0)
        {
        	a[0] = 15;
        	a[1] = 0;
        	return a;
        }
    }



    if (m_Chip_Select.Chip6.B_Valve_1_Mode  == 0)
    {
        if(channel.Channel_16.Mode == 1)
        {
        	a[0] = 16;
        	a[1] = 1;
        	return a;
        }
    }

    if (m_Chip_Select.Chip6.B_Valve_1_Mode  == 1)
    {
        if(channel.Channel_16.Mode == 0)
        {
        	a[0] = 16;
        	a[1] = 0;
        	return a;
        }
    }

    return a;
}



//  模式转换函数
void pt2000_mode_control()
{

	++Mode_Change_Time_code;

	uint8 a[2];

	static uint8 * Mode_Change_State;

	Mode_Change_State = Pt2000_State(a);

	uint8 valve_number = Mode_Change_State[0];

	uint8 Valve_State  = Mode_Change_State[1];



	if(Timer_coda >= 300)
	{
		switch(valve_number)
			{
			   case 1 :
			   {
				   pt2000_mode_control_judge_valve1(valve_number,&m_Chip_Select.Chip1,Valve_State);

				   break;
			   }
			   case 2 :
			   {
				   pt2000_mode_control_judge_valve2(valve_number,&m_Chip_Select.Chip1,Valve_State);

				   break;
			   }

			   case 3 :
			   {
				   pt2000_mode_control_judge_valve3(valve_number,&m_Chip_Select.Chip1,Valve_State);

				   break;
			   }

			   case 4 :
			   {
				   pt2000_mode_control_judge_valve1(valve_number,&m_Chip_Select.Chip2,Valve_State);

				   break;
			   }
			   case 5 :
			   {
				   pt2000_mode_control_judge_valve2(valve_number,&m_Chip_Select.Chip2,Valve_State);

				   break;
			   }

			   case 6 :
			   {
				   pt2000_mode_control_judge_valve3(valve_number,&m_Chip_Select.Chip2,Valve_State);

				   break;
			   }

			   case 7 :
			   {
				   pt2000_mode_control_judge_valve1(valve_number,&m_Chip_Select.Chip3,Valve_State);

				   break;
			   }
			   case 8 :
			   {
				   pt2000_mode_control_judge_valve2(valve_number,&m_Chip_Select.Chip3,Valve_State);

				   break;
			   }

			   case 9 :
			   {
				   pt2000_mode_control_judge_valve3(valve_number,&m_Chip_Select.Chip3,Valve_State);

				   break;
			   }

			   case 10 :
			   {
				   pt2000_mode_control_judge_valve1(valve_number,&m_Chip_Select.Chip4,Valve_State);
				   break;
			   }
			   case 11 :
			   {
				   pt2000_mode_control_judge_valve2(valve_number,&m_Chip_Select.Chip4,Valve_State);

				   break;
			   }

			   case 12 :
			   {
				   pt2000_mode_control_judge_valve3(valve_number,&m_Chip_Select.Chip4,Valve_State);

				   break;
			   }

			   case 13 :
			   {
				   pt2000_mode_control_judge_valve2(valve_number,&m_Chip_Select.Chip6,Valve_State);

				   break;
			   }
			   case 14 :
			   {
				   pt2000_mode_control_judge_valve2(valve_number,&m_Chip_Select.Chip5,Valve_State);

				   break;
			   }

			   case 15 :
			   {
				   pt2000_mode_control_judge_valve3(valve_number,&m_Chip_Select.Chip5,Valve_State);

				   break;
			   }

			   case 16 :
			   {
				   pt2000_mode_control_judge_valve3(valve_number,&m_Chip_Select.Chip6,Valve_State);

				   break;
			   }
			}
	}
}






