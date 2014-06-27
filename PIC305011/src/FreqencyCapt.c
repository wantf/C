#include "GlobalParm.h"
#include "FreqencyCapt.h"

/*******************************************************************

    函数名称：void Init_SYS_IC1(void)
    功    能：对MCU进行上电初始化,输入扑捉开启
    输入参数：无
    输出参数：无
    返回值  ：无
********************************************************************/
void Init_SYS_IC1(void)
{

     LATD           = LATD & 0xFCFF;                  // 
     TRISD          = TRISD | 0x0300;                 // 设置 RD8 为 1 为输入
     IC1CON         = 0x4082;
     IC1BUF         = 0;
     IFS0bits.IC1IF = 0;
     IPC0bits.IC1IP = 0;
     IEC0bits.IC1IE = 0;
}
/*******************************************************************

    函数名称：void Init_SYS_IC2(void)
    功    能：对MCU进行上电初始化,输入扑捉开启
    输入参数：无
    输出参数：无
    返回值  ：无
********************************************************************/
void Init_SYS_IC2(void)
{

     LATD           = LATD & 0xFDFF;                  // 
     TRISD          = TRISD | 0x0200;                 // 设置 RD8 为 1 为输入
     IC2CON         = 0x4002;
     IC2BUF         = 0; 
     IFS0bits.IC2IF = 0;
     IPC1bits.IC2IP = 0;
     IEC0bits.IC2IE = 0;
}


/*******************************************************************

    函数名称：void Init_SYS_IC3(void)
    功    能：对MCU进行上电初始化,输入扑捉开启
    输入参数：无
    输出参数：无
    返回值  ：无
********************************************************************/
void Init_SYS_IC3(void)
{

     LATD           = LATD & 0xFBFF;                  // 
     TRISD          = TRISD | 0x0400;                 // 设置 RD10 为 1 为输入
     IC3CON         = 0x4002;
     IC3BUF         = 0; 
     IFS1bits.IC3IF = 0;
     IPC7bits.IC3IP = 0;
     IEC1bits.IC3IE = 0;
}

/*******************************************************************

    函数名称：void Init_SYS_TIME3(void)
    功    能：对MCU进行上电初始化,TIME3 关闭输出、中断、标志位清零
    输入参数：无
    输出参数：无
    返回值  ：无
********************************************************************/

void Init_SYS_TIME3(void)
{


    T3CON         = 0x0000;   
						                 /*   bit 15   TON：  定时器开控制位
						                                      当T32=1 （处于32 位定时器模式）时：
						                                      1= 启动32 位TMRx:TMRy 定时器对
						                                      0= 停止32 位TMRx:TMRy 定时器对
						                                      当T32=0 （处于16 位定时器模式）时：
						                                      1= 启动16 位定时器
						                                      0= 停止16 位定时器
						                      bit 14   未用： 读作0
						                      bit 13   TSIDL：空闲模式停止位
						                                      1= 当器件进入空闲模式时，定时器不继续工作
						                                      0= 在空闲模式定时器继续工作
						                      bit 12-7 未用:  读作0
						                      bit 6    TGATE：定时器门控时间累加使能位
						                                      1= 门控时间累加使能
						                                      0= 门控时间累加禁止
						                                     （当TGATE=1 时， TCS 必须设置为0。如果TCS=1，该位读作0）
						                      bit 5-4  TCKPS<1:0>：定时器输入时钟预分频选择位
						                                           11 = 预分频比是1:256
						                                           10 = 预分频比是1:64
						                                           01 = 预分频比是1:8
						                                           00 = 预分频比是1:1
						                      bit 3    未用： 读作0
						                      bit 2    未用： 读作0
						                      bit 1    TCS：  定时器时钟源选择位
						                                      1= 来自TxCK 引脚的外部时钟
						                                      0= 内部时钟（FOSC/4）
						                      bit 0    未用： 读作0
						                */
    TMR3          = 0x0000;
    PR3           = 0xFFFF;
    IPC1bits.T3IP = 0;                     // 定时器3中断优先级0
    IFS0bits.T3IF = 0;                     // 定时器3中断标志位清0
    IEC0bits.T3IE = 0;                     // 定时器3中断使能0
    T3CONbits.TCKPS= 2;                   //1:64
                                           //11 = 预分频比是1:256
                                           //10 = 预分频比是1:64
                                           //01 = 预分频比是1:8
                                           //00 = 预分频比是1:1 
    T3CON = T3CON | 0x8000;     
}


/*******************************************************************

    函数名称：void __attribute__((__interrupt__,no_auto_psv)) _IC1Interrupt(void)
    功    能：捕捉功能，捕捉输入交流电压的频率
    输入参数：无
    输出参数：无
    返回值  ：无
********************************************************************/
void __attribute__((__interrupt__,no_auto_psv)) _IC1Interrupt(void)
{ 
    static UInt16 s_uiBuffer  = 0;
    UInt16 uiBufferTemp   = 0;
    UInt16 uiBufferTemp1  = 0;
    IFS0bits.IC1IF    = 0;    
    TMR2              = 0;
    uiBufferTemp      = IC1BUF;   
    /**********************  读出所有的捕捉值 ***********************/
    while( (IC1CONbits.ICBNE & IC1CONbits.ICOV) )
    {
        uiBufferTemp1 = IC1BUF;
    }
    if( !TMR2_OVERFLOW )
    {
	    if( (uiBufferTemp < 1152)&&(uiBufferTemp > 153) )                      //判断当前频率是否在（230400/758=300Hz）和（230400/153=1500Hz）之间 与处理 
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

    函数名称：void __attribute__((__interrupt__,no_auto_psv)) _IC2Interrupt(void)
    功    能：捕捉功能，捕捉输入交流电压的频率
    输入参数：无
    输出参数：无
    返回值  ：无
********************************************************************/
void __attribute__((__interrupt__,no_auto_psv)) _IC2Interrupt(void)
{ 
    UInt16 uiBufferTemp = 0;                                                         // 在测试 TP 信号的有无时进行累加
    IFS0bits.IC2IF      = 0;    
    TMR3                = 0;
	g_TPCounter++;
    g_TPDelay           = IC2BUF;
//TEST_IO1 = TEST_IO1+1;
    /**********************  读出所有的捕捉值 ***********************/
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
    /**********************  读出所有的捕捉值 ***********************/
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
//	    if( (uiBufferTemp < 5200)&&(uiBufferTemp > 4000) )   //判断当前频率是否在（230400/4608=50Hz
//	    {                                                   //判断当前频率是否在（230400/4400=52Hz）和（230400/4800=48Hz）之间 与处理
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
    IFS0bits.INT0IF = 0;                                // 清外部中断0标记
    IEC0bits.INT0IE = 0;                                // 禁止外部中断0 	
}

/*******************************************************************

    函数名称：void __attribute__((__interrupt__,no_auto_psv)) _T3Interrupt(void)
    功    能：TIME3 关闭输出、中断、标志位清零
    输入参数：无
    输出参数：无
    返回值  ：无
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

    IFS1bits.T5IF  = 0;                                    // 定时器5中断标志位清0
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
