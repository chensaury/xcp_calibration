#include "ADCFilter.h"

Filter_Channel Filter_Calc = {{{0}}};



void Sliding_Mean_Filter_Calc(Sliding_Mean_Filter *filter, uint16 Data)
{
	filter->sum -= filter->Filter_Buffer[filter->fl_id];	//减去最旧的数
	filter->sum += Data;								//加进最新的数
	filter->Filter_Buffer[filter->fl_id] = Data;			//将最新的数覆盖最旧的数
	filter->average = filter->sum / Sliding_Mean_Filter_Buffer_Size;	//求均值
	if(++filter->fl_id == Sliding_Mean_Filter_Buffer_Size)
		filter->fl_id = 0;

}







