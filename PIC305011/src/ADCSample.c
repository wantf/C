#include "GlobalParm.h"
#include "ADCSample.h"



/*******************************************************************

    函数名称：void Init_SYS_ADC(void)
    功    能：对MCU进行上电初始化，自动顺序采样 CH0通道，
              采样10次每个模拟口采样1次，
              两次转换之间应该至少留出1 个TAD 时间周期作为采样时间
    输入参数：无
    输出参数：无
    返回值  ：无
********************************************************************/

void Init_SYS_ADC(void)
{
//    ADPCFG          = 0xE0C0;                              // AN0~AN12开启               
    ADPCFG          = 0x80C0;                              // 2012.6.28 开启 AN0-AN14
    ADCON1          = 0x60E4;
//    ADCON2          = 0xE428;
//	ADCON2          = 0xE430;                              // 2012.6.28 开启 AN0-AN14
	ADCON2          = 0xE434;
    ADCON3          = 0x0F3F;
//    ADCSSL          = 0x1F3F;                              // 对 AN1~AN5扫描
    ADCSSL          = 0x7F3F; 
    ADCON1bits.ADON = 1;                                   // 0 A/D 转换关闭
    IFS0bits.ADIF   = 0;  
    IPC2bits.ADIP   = 0;                                   // AD中断优先级6
    IEC0bits.ADIE   = 0;

}
/*******************************************************************

    函数名称：void __attribute__((__interrupt__,no_auto_psv))  _ADCInterrupt(void)
    功    能：对各个AD口得数据进行采集，并且做初步的处理。
    输入参数：无
    输出参数：无
    返回值  ：无
********************************************************************/

/*-----------------------AD转换中断服务程序--------------------*/
void __attribute__((__interrupt__,no_auto_psv))  _ADCInterrupt(void)
{   
     IFS0bits.ADIF  = 0;                                   // 清除AD中断标记 
     g_uiOutVoltage = ADCBUF5;                             // 单片机端口电压--输出交流电压
     g_uiOutCurrent = ADCBUF4;                             // 单片机端口电压--输出交流电流
     g_uiTemprt     = ADCBUF3;                             // 单片机端口电压--温度
     g_uiMCUBus     = ADCBUF2;                             // 单片机端口电压--母线电压
     g_uiMCU5V      = ADCBUF1;                             // 单片机供电电压
     g_uiINV15V1    = ADCBUF0;                             // 逆变桥自举电压
     g_uiINV15V2    = ADCBUF6;                             // 逆变桥自举电压
     g_uiVBus       = ADCBUF7;                             // 母线电压
     g_uiAPhase     = ADCBUF8;                             // 输入三相 A 相电压流
     g_uiBPhase     = ADCBUF9;                             // 输入三相 B 相电压流
     g_uiCPhase     = ADCBUFA;                             // 输入三相 C 相电压流
     g_uiNTC        = ADCBUFB;                             // NTC温度检测
     g_uiAUX        = ADCBUFC;                             // +15V检测

}
void ADvalue_Filt(UInt16 NewValue,UInt16 * FiltValue)
{
	UInt16 TempNew  = 0;
	UInt16 TempFilt = 0;
	UInt16 TempErr  = 0;
	TempNew         = NewValue;
	TempFilt        = * FiltValue;
	if( TempNew>=TempFilt )
	{
		TempErr     = TempNew -TempFilt;
		TempErr     = TempErr>>1;
		if( (TempNew!=TempFilt) && (TempErr<1) )           //防止滤波系数太小,不能把滤波值加上去
		{	
			TempErr = 1;
	    }
		TempFilt    = TempFilt + TempErr;
	}
	else
	{
		TempErr     = TempFilt - TempNew;
		TempErr     = TempErr>>1;

		if( TempErr<1 )                                    //防止永远减不下去的情况.
		{	
			TempErr = 1;
		}
		TempFilt    = TempFilt - TempErr;
	}
	* FiltValue     = TempFilt;
}


void ATODValue_Dispose(void)
{
	int i       = 0;
	int uiTemp0 = 0;
	int uiTemp1 = 0;
	int uiTemp2 = 0;
	int uiTemp3 = 0;
	ADvalue_Filt(g_uiOutVoltage,&g_uiOutVoltagefilt);      // 单片机端口电压--输出交流电压
	ADvalue_Filt(g_uiOutCurrent,&g_uiOutCurrentfilt);      // 单片机端口电压--输出交流电流
	ADvalue_Filt(g_uiTemprt,    &g_uiTemprtfilt);          // 单片机端口电压--温度
	ADvalue_Filt(g_uiMCUBus,    &g_uiMCUBusfilt);          // 单片机端口电压--母线电压
	ADvalue_Filt(g_uiMCU5V,     &g_uiMCU5Vfilt);           // 单片机供电电压

    for( i=3;i>0;i-- )
    {
        g_Aarry_of_INV15V1[i] = g_Aarry_of_INV15V1[i-1];
	}
	g_Aarry_of_INV15V1[0]     = g_uiINV15V1;
    if( g_Aarry_of_INV15V1[0] > g_Aarry_of_INV15V1[1] )
    {
        uiTemp0               = g_Aarry_of_INV15V1[1];
		uiTemp1               = g_Aarry_of_INV15V1[0];	
	}
    else
    {
        uiTemp0               = g_Aarry_of_INV15V1[0];
		uiTemp1               = g_Aarry_of_INV15V1[1];
    }
    if( g_Aarry_of_INV15V1[2] > g_Aarry_of_INV15V1[3] )
    {
        uiTemp2               = g_Aarry_of_INV15V1[3];
		uiTemp3               = g_Aarry_of_INV15V1[2];	
	}
    else
    {
        uiTemp2               = g_Aarry_of_INV15V1[2];
		uiTemp3               = g_Aarry_of_INV15V1[3];
    }	
    if( uiTemp0 > uiTemp2 )
    {
        uiTemp2 = uiTemp0;   
	}
    if( uiTemp1 > uiTemp3 )	
    {
        uiTemp0  = (uiTemp2+uiTemp3)>>1;
    }
    else
    {
        uiTemp0  = (uiTemp2+uiTemp1)>>1;
    }

	ADvalue_Filt(uiTemp0,   &g_uiINV15V1filt);         // 逆变桥自举电压	

    for( i=3;i>0;i-- )
    {
        g_Aarry_of_INV15V2[i] = g_Aarry_of_INV15V2[i-1];
	}
	g_Aarry_of_INV15V2[0]     = g_uiINV15V2;
    if( g_Aarry_of_INV15V2[0] > g_Aarry_of_INV15V2[1] )
    {
        uiTemp0               = g_Aarry_of_INV15V2[1];
		uiTemp1               = g_Aarry_of_INV15V2[0];	
	}
    else
    {
        uiTemp0               = g_Aarry_of_INV15V2[0];
		uiTemp1               = g_Aarry_of_INV15V2[1];
    }
    if( g_Aarry_of_INV15V2[2] > g_Aarry_of_INV15V2[3] )
    {
        uiTemp2               = g_Aarry_of_INV15V2[3];
		uiTemp3               = g_Aarry_of_INV15V2[2];	
	}
    else
    {
        uiTemp2               = g_Aarry_of_INV15V2[2];
		uiTemp3               = g_Aarry_of_INV15V2[3];
    }	
    if( uiTemp0 > uiTemp2 )
    {
        uiTemp2 = uiTemp0;   
	}
    if( uiTemp1 > uiTemp3 )	
    {
        uiTemp0  = (uiTemp2+uiTemp3)>>1;
    }
    else
    {
        uiTemp0  = (uiTemp2+uiTemp1)>>1;
    }
	ADvalue_Filt(uiTemp0,   &g_uiINV15V2filt);         // 逆变桥自举电压	
	
	ADvalue_Filt(g_uiVBus,      &g_uiVBusfilt);            // 母线电压
	ADvalue_Filt(g_uiAPhase,    &g_uiAPhasefilt);          // 输入三相 A 相电压流
	ADvalue_Filt(g_uiBPhase,    &g_uiBPhasefilt);          // 输入三相 B 相电压流
 	ADvalue_Filt(g_uiCPhase,    &g_uiCPhasefilt);          // 输入三相 C 相电压流
 	ADvalue_Filt(g_uiNTC,       &g_uiNTCfilt);             // 自身温度检测
 	ADvalue_Filt(g_uiAUX,       &g_uiAUXfilt);             // 辅助电源检测	
}





