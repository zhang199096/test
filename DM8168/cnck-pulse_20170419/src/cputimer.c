#include "..\\include\\main_dsp.h"

TIMER0 Timer0;	//定时器0 结构对象

// 返回单位:ms
FLOAT64 get_delta_time(INT32U StartTime)		//计算由StartTime 起的经历时间
{
	FLOAT64 DeltaTime;
	if(StartTime > Timer0.GenericCounter)
		DeltaTime = (4294967295-StartTime)+Timer0.GenericCounter;
	else
		DeltaTime = Timer0.GenericCounter-StartTime;
	if(DeltaTime)
		DeltaTime = divdp((DeltaTime * Timer0.SamplePeriod), 1000);		//unit:ms	
	return DeltaTime;	
}

