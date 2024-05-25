

#ifndef ADCFilter_H_
#define ADCFilter_H_

#include "stdint.h"
#include "Platform_Types.h"

#define Sliding_Mean_Filter_Buffer_Size 15

typedef struct
{
	uint32 Filter_Buffer[Sliding_Mean_Filter_Buffer_Size];
	uint16 fl_id;
	uint32 sum;
	uint16 average;
}Sliding_Mean_Filter;

typedef struct
{
	Sliding_Mean_Filter AccPedlPos ;
	Sliding_Mean_Filter BrkPedlPos ;
	Sliding_Mean_Filter PressureFL1 ;
	Sliding_Mean_Filter PressureFL2 ;
	Sliding_Mean_Filter PressureFR1 ;
	Sliding_Mean_Filter PressureFR2 ;
	Sliding_Mean_Filter PressureRL1 ;
	Sliding_Mean_Filter PressureRL2 ;
	Sliding_Mean_Filter PressureRR1 ;
	Sliding_Mean_Filter PressureRR2 ;
	Sliding_Mean_Filter SuspHeightFL ;
	Sliding_Mean_Filter SuspHeightFR ;
	Sliding_Mean_Filter SuspHeightRL ;
	Sliding_Mean_Filter SuspHeightRR ;
	Sliding_Mean_Filter IMUAccX ;
	Sliding_Mean_Filter IMUAccY ;
	Sliding_Mean_Filter IMUAccZ ;
	Sliding_Mean_Filter IMURollRate ;
	Sliding_Mean_Filter IMUPitchRate ;
	Sliding_Mean_Filter IMUYawRate ;
	Sliding_Mean_Filter IMURollAngle ;
	Sliding_Mean_Filter IMUPitchAngle ;
	Sliding_Mean_Filter IMUYawAngle ;
	Sliding_Mean_Filter IMUVelNorth ;
	Sliding_Mean_Filter IMUVelEarth ;
	Sliding_Mean_Filter IMUVelEast ;
	Sliding_Mean_Filter SteerWhlAngle ;
	Sliding_Mean_Filter SteerWhlHandTrq ;
	Sliding_Mean_Filter SteerWhlAngleRate ;
}Filter_Channel;



void Sliding_Mean_Filter_Calc(Sliding_Mean_Filter *filter, uint16 Data);

extern Filter_Channel Filter_Calc;

#endif
