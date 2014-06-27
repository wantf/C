#include "GlobalParm.h"
#include "FreqencyCapt.h"

/*******************************************************************

    �������ƣ�void Init_SYS_IC1(void)
    ��    �ܣ���MCU�����ϵ��ʼ��,������׽����
    �����������
    �����������
    ����ֵ  ����
********************************************************************/
void Init_SYS_IC1(void)
{

     LATD           = LATD & 0xFCFF;                  // 
     TRISD          = TRISD | 0x0300;                 // ���� RD8 Ϊ 1 Ϊ����
     IC1CON         = 0x4082;
     IC1BUF         = 0;
     IFS0bits.IC1IF = 0;
     IPC0bits.IC1IP = 0;
     IEC0bits.IC1IE = 0;
}
/*******************************************************************

    �������ƣ�void Init_SYS_IC2(void)
    ��    �ܣ���MCU�����ϵ��ʼ��,������׽����
    �����������
    �����������
    ����ֵ  ����
********************************************************************/
void Init_SYS_IC2(void)
{

     LATD           = LATD & 0xFDFF;                  // 
     TRISD          = TRISD | 0x0200;                 // ���� RD8 Ϊ 1 Ϊ����
     IC2CON         = 0x4002;
     IC2BUF         = 0; 
     IFS0bits.IC2IF = 0;
     IPC1bits.IC2IP = 0;
     IEC0bits.IC2IE = 0;
}


/*******************************************************************

    �������ƣ�void Init_SYS_IC3(void)
    ��    �ܣ���MCU�����ϵ��ʼ��,������׽����
    �����������
    �����������
    ����ֵ  ����
********************************************************************/
void Init_SYS_IC3(void)
{

     LATD           = LATD & 0xFBFF;                  // 
     TRISD          = TRISD | 0x0400;                 // ���� RD10 Ϊ 1 Ϊ����
     IC3CON         = 0x4002;
     IC3BUF         = 0; 
     IFS1bits.IC3IF = 0;
     IPC7bits.IC3IP = 0;
     IEC1bits.IC3IE = 0;
}

/*******************************************************************

    �������ƣ�void Init_SYS_TIME3(void)
    ��    �ܣ���MCU�����ϵ��ʼ��,TIME3 �ر�������жϡ���־λ����
    �����������
    �����������
    ����ֵ  ����
********************************************************************/

void Init_SYS_TIME3(void)
{


    T3CON         = 0x0000;   
						                 /*   bit 15   TON��  ��ʱ��������λ
						                                      ��T32=1 ������32 λ��ʱ��ģʽ��ʱ��
						                                      1= ����32 λTMRx:TMRy ��ʱ����
						                                      0= ֹͣ32 λTMRx:TMRy ��ʱ����
						                                      ��T32=0 ������16 λ��ʱ��ģʽ��ʱ��
						                                      1= ����16 λ��ʱ��
						                                      0= ֹͣ16 λ��ʱ��
						                      bit 14   δ�ã� ����0
						                      bit 13   TSIDL������ģʽֹͣλ
						                                      1= �������������ģʽʱ����ʱ������������
						                                      0= �ڿ���ģʽ��ʱ����������
						                      bit 12-7 δ��:  ����0
						                      bit 6    TGATE����ʱ���ſ�ʱ���ۼ�ʹ��λ
						                                      1= �ſ�ʱ���ۼ�ʹ��
						                                      0= �ſ�ʱ���ۼӽ�ֹ
						                                     ����TGATE=1 ʱ�� TCS ��������Ϊ0�����TCS=1����λ����0��
						                      bit 5-4  TCKPS<1:0>����ʱ������ʱ��Ԥ��Ƶѡ��λ
						                                           11 = Ԥ��Ƶ����1:256
						                                           10 = Ԥ��Ƶ����1:64
						                                           01 = Ԥ��Ƶ����1:8
						                                           00 = Ԥ��Ƶ����1:1
						                      bit 3    δ�ã� ����0
						                      bit 2    δ�ã� ����0
						                      bit 1    TCS��  ��ʱ��ʱ��Դѡ��λ
						                                      1= ����TxCK ���ŵ��ⲿʱ��
						                                      0= �ڲ�ʱ�ӣ�FOSC/4��
						                      bit 0    δ�ã� ����0
						                */
    TMR3          = 0x0000;
    PR3           = 0xFFFF;
    IPC1bits.T3IP = 0;                     // ��ʱ��3�ж����ȼ�0
    IFS0bits.T3IF = 0;                     // ��ʱ��3�жϱ�־λ��0
    IEC0bits.T3IE = 0;                     // ��ʱ��3�ж�ʹ��0
    T3CONbits.TCKPS= 2;                   //1:64
                                           //11 = Ԥ��Ƶ����1:256
                                           //10 = Ԥ��Ƶ����1:64
                                           //01 = Ԥ��Ƶ����1:8
                                           //00 = Ԥ��Ƶ����1:1 
    T3CON = T3CON | 0x8000;     
}


/*******************************************************************

    �������ƣ�void __attribute__((__interrupt__,no_auto_psv)) _IC1Interrupt(void)
    ��    �ܣ���׽���ܣ���׽���뽻����ѹ��Ƶ��
    �����������
    �����������
    ����ֵ  ����
********************************************************************/
void __attribute__((__interrupt__,no_auto_psv)) _IC1Interrupt(void)
{ 
    static UInt16 s_uiBuffer  = 0;
    UInt16 uiBufferTemp   = 0;
    UInt16 uiBufferTemp1  = 0;
    IFS0bits.IC1IF    = 0;    
    TMR2              = 0;
    uiBufferTemp      = IC1BUF;   
    /**********************  �������еĲ�׽ֵ ***********************/
    while( (IC1CONbits.ICBNE & IC1CONbits.ICOV) )
    {
        uiBufferTemp1 = IC1BUF;
    }
    if( !TMR2_OVERFLOW )
    {
	    if( (uiBufferTemp < 1152)&&(uiBufferTemp > 153) )                      //�жϵ�ǰƵ���Ƿ��ڣ�230400/758=300Hz���ͣ�230400/153=1500Hz��֮�� �봦�� 
	    {   
            s_uiBuffer  = (s_uiBuffer>>1) + (uiBufferTemp>>1);
            g_Frequency = s_uiBuffer;  
	    }
        else
        {
            s_uiBuffer  = 1152; 
            g_Frequency = 1152; 
        }
    } 
    else
    {
        TMR2_OVERFLOW = 0;
    } 
}

/*******************************************************************

    �������ƣ�void __attribute__((__interrupt__,no_auto_psv)) _IC2Interrupt(void)
    ��    �ܣ���׽���ܣ���׽���뽻����ѹ��Ƶ��
    �����������
    �����������
    ����ֵ  ����
********************************************************************/
void __attribute__((__interrupt__,no_auto_psv)) _IC2Interrupt(void)
{ 
    UInt16 uiBufferTemp = 0;                                                         // �ڲ��� TP �źŵ�����ʱ�����ۼ�
    IFS0bits.IC2IF      = 0;    
    TMR3                = 0;
	g_TPCounter++;
    g_TPDelay           = IC2BUF;
//TEST_IO1 = TEST_IO1+1;
    /**********************  �������еĲ�׽ֵ ***********************/
    while( (IC2CONbits.ICBNE & IC2CONbits.ICOV) )
    {
        uiBufferTemp    = IC2BUF;
    }
}


void __attribute__((__interrupt__,no_auto_psv)) _IC3Interrupt(void)
{ 
    static UInt16 s_uiBuffer  = 0;
    UInt16 uiBufferTemp   = 0;
    UInt16 uiBufferTemp1  = 0;
    IFS1bits.IC3IF        = 0;  
    if( (g_Wait_TP_T5  == 0x11)&&(g_Wait_TP_IC3  == 0x11) )
    {
		T5CONbits.TCKPS = 1;
	    T5CON           = T5CON | 0x8000;
	    ERROR_CAPT_OVER = 0;
        g_Wait_TP_IC3   = 0;
        g_Wait_TP_T5    = 0x11; 
    }
    TMR3              = 0;
    uiBufferTemp      = IC3BUF;   
    /**********************  �������еĲ�׽ֵ ***********************/
    while( (IC3CONbits.ICBNE & IC3CONbits.ICOV) )
    {
        uiBufferTemp1 = IC3BUF;
    }
    if( !TMR3_OVERFLOW )
    {

        if( uiBufferTemp < 4000 )
        {
            s_uiBuffer     = 4000; 
        }
        if( uiBufferTemp > 5200 )
        {
            s_uiBuffer     = 5200; 
        }
        s_uiBuffer     = (s_uiBuffer>>1) + (uiBufferTemp>>1);
        g_OutFrequency = s_uiBuffer; 
//	    if( (uiBufferTemp < 5200)&&(uiBufferTemp > 4000) )   //�жϵ�ǰƵ���Ƿ��ڣ�230400/4608=50Hz
//	    {                                                   //�жϵ�ǰƵ���Ƿ��ڣ�230400/4400=52Hz���ͣ�230400/4800=48Hz��֮�� �봦��
//            s_uiBuffer     = (s_uiBuffer>>1) + (uiBufferTemp>>1);
//            g_OutFrequency = s_uiBuffer;  
//	    }
    } 
    else
    {
        TMR3_OVERFLOW = 0;
    } 
}

void __attribute__((__interrupt__,no_auto_psv)) _INT0Interrupt(void)
{
    IFS0bits.INT0IF = 0;                                // ���ⲿ�ж�0���
    IEC0bits.INT0IE = 0;                                // ��ֹ�ⲿ�ж�0 	
}

/*******************************************************************

    �������ƣ�void __attribute__((__interrupt__,no_auto_psv)) _T3Interrupt(void)
    ��    �ܣ�TIME3 �ر�������жϡ���־λ����
    �����������
    �����������
    ����ֵ  ����
********************************************************************/
void __attribute__((__interrupt__,no_auto_psv)) _T3Interrupt(void)
{
    IFS0bits.T3IF  = 0;
    TMR3           = 0;	
  //  g_OutFrequency = 23040;                                // 10HZ
    TMR3_OVERFLOW  = 1;
    TP_TMR3_OVERFLOW= 1;
  
}
void __attribute__((__interrupt__,no_auto_psv)) _T2Interrupt(void)
{
    IFS0bits.T2IF  = 0;
    TMR2           = 0;
    g_Frequency    = 1152;                                 // 200HZ 
    TMR2_OVERFLOW  = 1;
}
void __attribute__((__interrupt__,no_auto_psv)) _T5Interrupt(void)
{

    IFS1bits.T5IF  = 0;                                    // ��ʱ��5�жϱ�־λ��0
	TMR5           = 0;
	T5CON          = 0;
    if( (g_Wait_TP_T5  == 0x11)&&(g_Wait_TP_IC3  == 0x00) )
    {
		T5CON           = 0;
		T3CON           = T3CON & 0x7FFF;
	    TMR3            = 0;
	    T3CONbits.TCKPS = 3;	
	    TP_TMR3_OVERFLOW= 0;
	    IC2CON          = 0x4002;
	    g_TPCounter     = 0;	
        IEC0bits.IC2IE  = 1;
	    T3CON           = T3CON | 0x8000;
        LOAD_Switch     = LOAD_RCD_SWITCH_ENABLE; 
        g_Wait_TP_IC3   = 0x00;
        g_Wait_TP_T5    = 0x00; 
    }
}
