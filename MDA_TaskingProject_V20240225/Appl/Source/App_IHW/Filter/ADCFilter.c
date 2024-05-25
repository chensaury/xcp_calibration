#include "ADCFilter.h"

Filter_Channel Filter_Calc = {{{0}}};



void Sliding_Mean_Filter_Calc(Sliding_Mean_Filter *filter, uint16 Data)
{
	filter->sum -= filter->Filter_Buffer[filter->fl_id];	//��ȥ��ɵ���
	filter->sum += Data;								//�ӽ����µ���
	filter->Filter_Buffer[filter->fl_id] = Data;			//�����µ���������ɵ���
	filter->average = filter->sum / Sliding_Mean_Filter_Buffer_Size;	//���ֵ
	if(++filter->fl_id == Sliding_Mean_Filter_Buffer_Size)
		filter->fl_id = 0;

}







