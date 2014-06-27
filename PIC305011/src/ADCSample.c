#include "GlobalParm.h"
#include "ADCSample.h"



/*******************************************************************

    �������ƣ�void Init_SYS_ADC(void)
    ��    �ܣ���MCU�����ϵ��ʼ�����Զ�˳����� CH0ͨ����
              ����10��ÿ��ģ��ڲ���1�Σ�
              ����ת��֮��Ӧ����������1 ��TAD ʱ��������Ϊ����ʱ��
    �����������
    �����������
    ����ֵ  ����
********************************************************************/

void Init_SYS_ADC(void)
{
//    ADPCFG          = 0xE0C0;                              // AN0~AN12����               
    ADPCFG          = 0x80C0;                              // 2012.6.28 ���� AN0-AN14
    ADCON1          = 0x60E4;
//    ADCON2          = 0xE428;
//	ADCON2          = 0xE430;                              // 2012.6.28 ���� AN0-AN14
	ADCON2          = 0xE434;
    ADCON3          = 0x0F3F;
//    ADCSSL          = 0x1F3F;                              // �� AN1~AN5ɨ��
    ADCSSL          = 0x7F3F; 
    ADCON1bits.ADON = 1;                                   // 0 A/D ת���ر�
    IFS0bits.ADIF   = 0;  
    IPC2bits.ADIP   = 0;                                   // AD�ж����ȼ�6
    IEC0bits.ADIE   = 0;

}
/*******************************************************************

    �������ƣ�void __attribute__((__interrupt__,no_auto_psv))  _ADCInterrupt(void)
    ��    �ܣ��Ը���AD�ڵ����ݽ��вɼ��������������Ĵ���
    �����������
    �����������
    ����ֵ  ����
********************************************************************/

/*-----------------------ADת���жϷ������--------------------*/
void __attribute__((__interrupt__,no_auto_psv))  _ADCInterrupt(void)
{   
     IFS0bits.ADIF  = 0;                                   // ���AD�жϱ�� 
     g_uiOutVoltage = ADCBUF5;                             // ��Ƭ���˿ڵ�ѹ--���������ѹ
     g_uiOutCurrent = ADCBUF4;                             // ��Ƭ���˿ڵ�ѹ--�����������
     g_uiTemprt     = ADCBUF3;                             // ��Ƭ���˿ڵ�ѹ--�¶�
     g_uiMCUBus     = ADCBUF2;                             // ��Ƭ���˿ڵ�ѹ--ĸ�ߵ�ѹ
     g_uiMCU5V      = ADCBUF1;                             // ��Ƭ�������ѹ
     g_uiINV15V1    = ADCBUF0;                             // ������Ծٵ�ѹ
     g_uiINV15V2    = ADCBUF6;                             // ������Ծٵ�ѹ
     g_uiVBus       = ADCBUF7;                             // ĸ�ߵ�ѹ
     g_uiAPhase     = ADCBUF8;                             // �������� A ���ѹ��
     g_uiBPhase     = ADCBUF9;                             // �������� B ���ѹ��
     g_uiCPhase     = ADCBUFA;                             // �������� C ���ѹ��
     g_uiNTC        = ADCBUFB;                             // NTC�¶ȼ��
     g_uiAUX        = ADCBUFC;                             // +15V���

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
		if( (TempNew!=TempFilt) && (TempErr<1) )           //��ֹ�˲�ϵ��̫С,���ܰ��˲�ֵ����ȥ
		{	
			TempErr = 1;
	    }
		TempFilt    = TempFilt + TempErr;
	}
	else
	{
		TempErr     = TempFilt - TempNew;
		TempErr     = TempErr>>1;

		if( TempErr<1 )                                    //��ֹ��Զ������ȥ�����.
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
	ADvalue_Filt(g_uiOutVoltage,&g_uiOutVoltagefilt);      // ��Ƭ���˿ڵ�ѹ--���������ѹ
	ADvalue_Filt(g_uiOutCurrent,&g_uiOutCurrentfilt);      // ��Ƭ���˿ڵ�ѹ--�����������
	ADvalue_Filt(g_uiTemprt,    &g_uiTemprtfilt);          // ��Ƭ���˿ڵ�ѹ--�¶�
	ADvalue_Filt(g_uiMCUBus,    &g_uiMCUBusfilt);          // ��Ƭ���˿ڵ�ѹ--ĸ�ߵ�ѹ
	ADvalue_Filt(g_uiMCU5V,     &g_uiMCU5Vfilt);           // ��Ƭ�������ѹ

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

	ADvalue_Filt(uiTemp0,   &g_uiINV15V1filt);         // ������Ծٵ�ѹ	

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
	ADvalue_Filt(uiTemp0,   &g_uiINV15V2filt);         // ������Ծٵ�ѹ	
	
	ADvalue_Filt(g_uiVBus,      &g_uiVBusfilt);            // ĸ�ߵ�ѹ
	ADvalue_Filt(g_uiAPhase,    &g_uiAPhasefilt);          // �������� A ���ѹ��
	ADvalue_Filt(g_uiBPhase,    &g_uiBPhasefilt);          // �������� B ���ѹ��
 	ADvalue_Filt(g_uiCPhase,    &g_uiCPhasefilt);          // �������� C ���ѹ��
 	ADvalue_Filt(g_uiNTC,       &g_uiNTCfilt);             // �����¶ȼ��
 	ADvalue_Filt(g_uiAUX,       &g_uiAUXfilt);             // ������Դ���	
}





