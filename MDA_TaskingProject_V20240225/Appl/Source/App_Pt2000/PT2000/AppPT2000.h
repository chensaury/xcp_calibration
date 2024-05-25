
#ifndef AppPT2000_H_
#define AppPT2000_H_


#include "PT2000_LoadData.h"
#include "PT2000_irq.h"
#include "MCAL\Mcal\Tricore\Spi\ssc\inc/Spi.h"

/********************************************************************/
/*peak_hold:
 * IboostB1:10 - 15
 *
 */

/*******************************************************************/

extern uint16 HS1;
extern uint16 HS2;
extern uint16 HS3;
extern uint16 HS4;
extern uint16 HS5;
extern uint16 HS6;
extern uint16 HS7;
extern uint16 LS2;
extern uint16 LS4;
extern uint16 LS6;
extern uint16 LS7;





typedef struct
{
    uint8 valve1 ;
    uint8 valve2 ;
    uint8 valve3 ;
    uint8 valve4 ;
    uint8 valve5 ;
    uint8 valve6 ;
    uint8 valve7 ;
    uint8 valve8 ;
    uint8 valve9 ;
    uint8 valve10 ;
    uint8 valve11 ;
    uint8 valve12 ;
    uint8 valve13 ;
    uint8 valve14 ;
    uint8 valve15 ;
    uint8 valve16 ;
}Valve;




//閫氶亾缂栧彿
typedef enum
{
    Channel_number_1 = 1,
    Channel_number_2 = 2,
    Channel_number_3 = 3,
    Channel_number_4 = 4,
    Channel_number_5 = 5,
    Channel_number_6 = 6,
    Channel_number_7 = 7,
    Channel_number_8 = 8,
    Channel_number_9 = 9,
    Channel_number_10 = 10,
    Channel_number_11 = 11,
    Channel_number_12 = 12,
    Channel_number_13 =13,
    Channel_number_14 =14,
    Channel_number_15 =15,
    Channel_number_16 =16,
    Channel_number_17 =17,
    Channel_number_18 =18,

}Channel_Number;

typedef enum{
    ConstantCurrent_Mode = 0,
    Peak_Hold_Mode
}Enum_Mode;

typedef struct
{
    uint16 IboostB;       //偏置电流拉高电流大小
    uint16 Tbias_tot;     //偏置电流持续时间
    uint16 Tbias_off;     //偏置电流电流降时间
    uint16 Ibias;         //bias电流大小
    uint16 IboostP;       //PEAK电流拉高电流大小
    uint16 Tpeak_tot;     //PEAK电流持续时间
    uint16 Tpeak_off;     //PEAK电流电流降时间
    uint16 Ipeak;         //PEAK电流大小
    uint16 Tbypass;       //peak降电HOLD的时间
    uint16 Thold_tot;     //hold电流持续时间
    uint16 Thold_off;     //hold电流电流降时间
    uint16 Ihold;         //hold电流大小
    uint16 FWtimeOFF;     //降电时间
    uint8 Mode;           // PEAK_Hold 模式与恒流模式的相互转换
    uint8 State;          // 控制电磁阀的开启关闭与电流更改 （0为电磁阀关闭       1为电磁阀开启   81为电流更改）
    uint8 diag;           // 判断是否对PT2000芯片进行诊断
    uint8 PC_Change;      // MDA应用层与PC端控制方式的转换  （0为应用层  1为PC端）

}ValveParam;


//电磁阀通道1~16
typedef struct
{
    ValveParam Channel_1;
    ValveParam Channel_2;
    ValveParam Channel_3;
    ValveParam Channel_4;
    ValveParam Channel_5;
    ValveParam Channel_6;
    ValveParam Channel_7;
    ValveParam Channel_8;
    ValveParam Channel_9;
    ValveParam Channel_10;
    ValveParam Channel_11;
    ValveParam Channel_12;
    ValveParam Channel_13;
    ValveParam Channel_14;
    ValveParam Channel_15;
    ValveParam Channel_16;
    ValveParam Channel_17;
    ValveParam Channel_18;

}Channel;

typedef struct
{
	uint8 B_Valve_1_Mode   ;
	uint8 B_Valve_2_Mode   ;
	uint8 B_Valve_3_Mode   ;

}Valve_Select;



typedef struct
{
	Valve_Select Chip1;
	Valve_Select Chip2;
	Valve_Select Chip3;
	Valve_Select Chip4;
	Valve_Select Chip5;
	Valve_Select Chip6;

}Chip_Select;

/*****************  Global Function   ******************/

/* 初始化 Ch_Number 通道参数    */
void initValveParamConfig(ValveParam *m_ValveParam, Channel_Number Ch_Number, Enum_Mode mode);
void initValveParam(Enum_Mode mode);

/* 将配置的参数映射到数据数组    */
void ParamMap(uint8 CSIndex);
void ParamMap1(uint8 CSIndex , uint8 Valve_channel);
void ParamMap_Peak(uint8 CSIndex);


/* 恒流、Peak_Hold 模式参数设置  */
void Set_ConstantCurrent(uint8 ChannelID, uint16 iboostB, uint16 tbias_tot, uint16 tbias_off, uint16 ibias, uint16 iboostP,
        uint16 tpeak_tot, uint16 tpeak_off, uint16 ipeak, uint16 tbypass, uint16 thold_tot, uint16 thold_off,
        uint16 ihold, uint16 fwtimeOFF);
void Set_ConstantCurrent1(uint8 ChannelID, uint16 iboostB, uint16 tbias_tot, uint16 tbias_off, uint16 ibias, uint16 iboostP,
        uint16 tpeak_tot, uint16 tpeak_off, uint16 ipeak, uint16 tbypass, uint16 thold_tot, uint16 thold_off,
        uint16 ihold, uint16 fwtimeOFF);
void Set_Peak_Hold(uint8 ChannelID, uint16 iboostB, uint16 tbias_tot, uint16 tbias_off, uint16 ibias, uint16 iboostP,
                    uint16 tpeak_tot, uint16 tpeak_off, uint16 ipeak, uint16 tbypass, uint16 thold_tot, uint16 thold_off,
                    uint16 ihold, uint16 fwtimeOFF);

void PT2000_Init(uint8 Mode);
void Set_ConstantCurrent_all( uint16 current,uint16 frequency, uint16 flutter);
void Set_StartPin_State(Channel_Number CSIndex, boolean state);
void Set_StartPin_State1(Channel_Number CSIndex, boolean state);
void Set_CSPin_State( uint8 CSIndex, boolean state);
void SendCmd_EnChannel();
void PT2000_Contral(void);
void PT2000_Init_control(uint8 Mode);
void GET_Valve_Value(void);
void PT2000_Mode_Control(void);
void  get_value_and_judge_structural_body_value (void);
void valve_diag(void);
void Channel_Select(uint8 valve_number , ValveParam  ValveParamCH );
void pt2000_mode_control_download_judge_valve1_constant_to_peak(uint8 valve_number , Valve_Select * m_Valve_Select);
void pt2000_mode_control_download_judge_valve1_peak_to_constant(uint8 valve_number , Valve_Select * m_Valve_Select);
void pt2000_mode_control_download_judge_valve2_constant_to_peak(uint8 valve_number , Valve_Select * m_Valve_Select);
void pt2000_mode_control_download_judge_valve2_peak_to_constant(uint8 valve_number , Valve_Select * m_Valve_Select);
void pt2000_mode_control_download_judge_valve3_constant_to_peak(uint8 valve_number , Valve_Select * m_Valve_Select);
void pt2000_mode_control_download_judge_valve3_peak_to_constant(uint8 valve_number , Valve_Select * m_Valve_Select);
void pt2000_mode_control_judge_valve1(uint8 valve_number,Valve_Select * m_Valve_Select,uint8 Valve_State);
void pt2000_mode_control_judge_valve2(uint8 valve_number,Valve_Select * m_Valve_Select,uint8 Valve_State);
uint8 * Pt2000_State(uint8 * a);
void pt2000_mode_control(void);
/******************************************************/

#endif

