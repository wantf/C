/********************************文件说明*****************************
* *
*    作者 :  wantf    公司 ：   （CQ HeYa）
*    项目编号：3EUB1A-FCT
* *
*    文件名 :  SetupBoard.c 
*    日期 :    2012.1.6 
*    文件版本 :1.00 
* *
*    使用工具 :MPLAB 8.50 
*    编译器:   C30 
* *
* 
*******************************编写进程****************************************
*

*
********************************************************************************/ 

#include "GlobalParm.h"
#include "SetupBoard.h"

/*******************************************************************

    函数名称：void SetupBoard(void)
    功    能：对MCU进行上电初始化
    输入参数：无
    输出参数：无
    返回值  ：无

********************************************************************/
void SetupBoard(void)
{
    SET_CPU_IPL(7);                                        //关闭外设总中断

    Init_MCU_IOPorts();                                    //上电初始化MCU，对IO口初始化
    Init_MCU_Interrupt();                                  //上电初始化MCU，对所有的中断初始化
    Init_MCU_ADC();                                        //上电初始化MCU，对ADC口初始化
    Init_MCU_COMP();                                       //上电初始化MCU，对比较功能初始化
    Init_MCU_SPWM();                                       //上电初始化MCU，对SPWM口初始化
    Init_MCU_Uart();                                       //上电初始化MCU，对串口初始化 
    Init_MCU_TIME1();                                      //上电初始化MCU，对定时器1初始化
    Init_MCU_TIME2();                                      //上电初始化MCU，对定时器2口初始化
    Init_MCU_TIME3();                                      //上电初始化MCU，对定时器3口初始化
    Init_MCU_TIME4();                                      //上电初始化MCU，对定时器4口初始化
    Init_MCU_INT2();                                       //上电初始化MCU，对外部中断初始化
    Init_MCU_INT0();
    Init_MCU_INT1();
  
    Init_SYS_IOPorts();
    Init_SYS_ADC();
    Init_SYS_UART_IOPorts();
    Init_SYS_UART();
    Init_SYS_TIME1();
    Init_SYS_TIME2();
    Init_SYS_TIME3();
    Init_SYS_TIME4();
    Init_SYS_TIME5();                     
    Init_SYS_IC1();
    Init_SYS_IC2();
	Init_SYS_IC3();
    SET_CPU_IPL(0);
    Init_SYS_Data();
    Init_SYS_Interrupt();
}

/*******************************************************************

    函数名称：void Init_MCU_IOPorts(void)
    功    能：对MCU进行上电初始化,使各断端口输出 0 或 为输入口 状态
    输入参数：无
    输出参数：无
    返回值  ：无

********************************************************************/

void Init_MCU_IOPorts(void)
{

    LATB  = 0x0000;
    LATC  = 0x0000;
    LATD  = 0x0000;
    LATE  = 0x0000;
    LATF  = 0x0000;

    TRISB = 0xFFFF;                                        // 设置B口为输入口，且输出为0
    TRISC = 0xFFFF;                                        // 设置C口为输入口，且输出为0
    TRISD = 0xFFFF;                                        // 设置D口为输入口，且输出为0
    TRISE = 0xFFFF;                                        // 设置E口为输入口，且输出为0
    TRISF = 0xFFFF;                                        // 设置F口为输入口，且输出为0
    TRISG = 0xFFFF;                                        // 设置G口为输入口，且输出为0

}/*---------------------------初始化IO口结束--------------------*/


/*******************************************************************

    函数名称：void Init_MCU_Interrupt(void)
    功    能：对MCU进行上电初始化,各个中断关闭，标志位清零，优先级为零
    输入参数：无
    输出参数：无
    返回值  ：无
********************************************************************/

void Init_MCU_Interrupt(void)
{
    INTCON1 = 0x0000;                    //禁止中断嵌套
    INTCON2 = 0x0000;
    IFS0    = 0X0000;
    IFS1    = 0x0000;
    IFS2    = 0x0000;
    IEC0    = 0x0000;
    IEC1    = 0x0000;
    IEC2    = 0x0000;
    IPC0    = 0x0000;
    IPC1    = 0x0000;
    IPC2    = 0x0000;
    IPC3    = 0x0000;
    IPC4    = 0x0000;
    IPC5    = 0x0000;
    IPC6    = 0x0000;
    IPC9    = 0x0000;
    IPC10   = 0x0000;
}


/*******************************************************************

    函数名称：void Init_MCU_ADC(void)
    功    能：对MCU进行上电初始化，自动顺序逐次扫描 CH0 通道，
              采样15次每个模拟口采样3次，采用查询方式进行判断，
              采样时间3*165=495nS，转换时间 = 165nS,ADCS=9
              两次转换之间应该至少留出1 个TAD 时间周期作为采样时间
              TAD = TCY*(ADCS + 1)/2
              ADCS = 2*TAD/TCY – 1

    输入参数：无
    输出参数：无
    返回值  ：无
********************************************************************/

void Init_MCU_ADC(void)
{
    ADPCFG  = 0xFFFF;                   //  AN0~AN4开启
    ADCON1  = 0x0000;          
    ADCON2  = 0x0000;    
    ADCON3  = 0x0000; 
    ADCHS   = 0x0000;
    ADCSSL  = 0x0000;        //  不扫描
}


/*******************************************************************

    函数名称：void Init_MCU_COMP(void)
    功    能：对MCU进行上电初始化,比较输出关闭输出、中断、标志位清零
    输入参数：无
    输出参数：无
    返回值  ：无
********************************************************************/

void Init_MCU_COMP(void)
{
    OC1CON         = 0;
    OC1RS          = 0;                                                                  
    OC1R           = 0; 
    OC2CON         = 0;
    OC2RS          = 0;                                                                  
    OC2R           = 0;
    OC3CON         = 0;
    OC3RS          = 0;                                                                  
    OC3R           = 0;
    OC4CON         = 0;
    OC4RS          = 0;                                                                  
    OC4R           = 0;
    IFS1bits.OC3IF = 0;
    IFS1bits.OC4IF = 0;
    IEC1bits.OC3IE = 0;
    IEC1bits.OC4IE = 0;
    IPC4bits.OC3IP = 0;
    IPC5bits.OC4IP = 0;
}


/*******************************************************************

    函数名称：void Init_MCU_SPWM(void)
    功    能：对MCU进行上电初始化,TIME1 关闭输出、中断、标志位清零
    输入参数：无
    输出参数：无
    返回值  ：无
********************************************************************/

void Init_MCU_SPWM(void)
{

    IEC2bits.PWMIE  = 0 ;                // 禁止PWM中断
    IFS2bits.PWMIF  = 0 ;                // 清楚PWM中断标志
    IEC2bits.FLTAIE = 0 ;                // 禁止PWM保护中断
    OVDCON          = 0;                                                                                
    PTCON           = 0 ;
    PWMCON1         = 0;
    PWMCON2         = 0; 
    DTCON1          = 0;                                                                               
    FLTACON         = 0;                                                                                                                                                                                                                 
    PTMR            = 0;                                                                    
    PTPER           = 0;                                                     
    IPC9bits.PWMIP  = 0;               /* 电机控制脉宽调制中断优先级位
                                             111 = 中断优先级为7 （最高优先级中断）
                                             ...
                                             001 = 中断优先级为1
                                             000 = 中断源被禁止*/
    IFS2bits.PWMIF = 0;               // 清除 PWM 中断标志位 
    IEC2bits.PWMIE = 0;               // 使能PWM中断 
}


/*******************************************************************

    函数名称：void Init_MCU_Uart(void)
    功    能：对MCU进行上电初始化,TIME2 关闭输出、中断、标志位清零
    输入参数：无
    输出参数：无
    返回值  ：无
********************************************************************/

void Init_MCU_Uart(void)
{
    U1BRG           = 0;                   //波特率设置为00
    U1MODE          = 0x0000;              //使能UART功能
    U1STA           = 0X0000;                                                               
    U1STAbits.UTXEN = 0;                   //允许发送  
    IPC2bits.U1RXIP = 0;                   //中断优先级别 
    IEC0bits.U1TXIE = 0;                   //禁止发送中断
    IEC0bits.U1RXIE = 0;                   //使能接收中断 
    IFS0bits.U1RXIF = 0;                   //清除中断标志位
}


/*******************************************************************

    函数名称：void Init_MCU_TIME1(void)
    功    能：对MCU进行上电初始化,TIME1 关闭输出、中断、标志位清零
    输入参数：无
    输出参数：无

********************************************************************/

void Init_MCU_TIME1(void)
{
    TMR1          = 0x0000;
    PR1           = 0x0000;
    IPC0bits.T1IP = 0;                     // 定时器1中断优先级0
    IFS0bits.T1IF = 0;                     // 定时器1中断标志位清0
    IEC0bits.T1IE = 0;                     // 定时器1中断使能0
    T1CON         = 0x0000;
                         
						                 /*   bit 15   TON：  定时器开控制位
						                                      1= 启动定时器
						                                      0= 停止定时器
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
						                      bit 2    TSYNC：定时器外部时钟输入同步选择位
						                                      当TCS=1 时：
						                                      1= 同步外部时钟输入
						                                      0= 不同步外部时钟输入
						                                      当TCS=0 时：
						                                      此位被忽略。读作0。当TCS=0 时， Timer1 使用内部时钟。
						                      bit 1    TCS：  定时器时钟源选择位
						                                      1= 来自TxCK 引脚的外部时钟
						                                      0= 内部时钟（FOSC/4）
						                      bit 0    未用： 读作0
						                */

}


/*******************************************************************

    函数名称：void Init_MCU_TIME2(void)
    功    能：对MCU进行上电初始化,TIME2 关闭输出、中断、标志位清零
    输入参数：无
    输出参数：无
    返回值  ：无
********************************************************************/

void Init_MCU_TIME2(void)
{
    TMR2          = 0x0000;
    PR2           = 0x0000;
    IPC1bits.T2IP = 0;                     // 定时器2中断优先级0
    IFS0bits.T2IF = 0;                     // 定时器2中断标志位清0
    IEC0bits.T2IE = 0;                     // 定时器2中断使能0
    T2CON         = 0x0000;     
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
							                      bit 3    T32：  32 位定时器模式选择位
							                                      1=TMRx 和TMRy 形成32 位定时器
							                                      0=TMRx 和TMRy 为独立的16 位定时器
							                      bit 2    未用： 读作0
							                      bit 1    TCS：  定时器时钟源选择位
							                                      1= 来自TxCK 引脚的外部时钟
							                                      0= 内部时钟（FOSC/4）
							                      bit 0    未用： 读作0
							                */

}


/*******************************************************************

    函数名称：void Init_MCU_TIME3(void)
    功    能：对MCU进行上电初始化,TIME3 关闭输出、中断、标志位清零
    输入参数：无
    输出参数：无
    返回值  ：无
********************************************************************/

void Init_MCU_TIME3(void)
{
    TMR3          = 0x0000;
    PR3           = 0x0000;
    IPC1bits.T3IP = 0;                     // 定时器3中断优先级0
    IFS0bits.T3IF = 0;                     // 定时器3中断标志位清0
    IEC0bits.T3IE = 0;                     // 定时器3中断使能0
    T3CON         = 0x0000;   
}


/*******************************************************************

    函数名称：void Init_MCU_TIME4(void)
    功    能：对MCU进行上电初始化,TIME4 关闭输出、中断、标志位清零
    输入参数：无
    输出参数：无
    返回值  ：无
********************************************************************/

void Init_MCU_TIME4(void)
{
    TMR4          = 0x0000;
    PR4           = 0x0000;
    IPC5bits.T4IP = 0;                     // 定时器4中断优先级0
    IFS1bits.T4IF = 0;                     // 定时器4中断标志位清0
    IEC1bits.T4IE = 0;                     // 定时器4中断使能0
    T4CON         = 0x0000;     

}


/*******************************************************************

    函数名称：void Init_MCU_TIME5(void)
    功    能：对MCU进行上电初始化,TIME5 关闭输出、中断、标志位清零
    输入参数：无
    输出参数：无
    返回值  ：无
********************************************************************/

void Init_MCU_TIME5(void)
{
    TMR5          = 0x0000;
    PR5           = 0x0000;
    IPC5bits.T5IP = 0;                     // 定时器5中断优先级0
    IFS1bits.T5IF = 0;                     // 定时器5中断标志位清0
    IEC1bits.T5IE = 0;                     // 定时器5中断使能0
    T5CON         = 0x0000;     
}


/*******************************************************************

    函数名称：void Init_MCU_INT0(void)
    功    能：对MCU进行上电初始化,外部中断关闭、标志位清零
    输入参数：无
    输出参数：无
    返回值  ：无
********************************************************************/

void Init_MCU_INT0(void)
{
    INTCON2bits.INT0EP = 1;                // INT0EP：外部中断0 边沿检测极性选择位
                                           // 1 = 负边沿处中断
                                           // 0 = 正边沿处中断

    IFS0bits.INT0IF    = 0;                // 清外部中断0标记
    IPC0bits.INT0IP    = 0;                // 外部中断0优先级为0
    IEC0bits.INT0IE    = 0;                // 禁止外部中断2 
}

/*******************************************************************

    函数名称：void Init_MCU_INT1(void)
    功    能：对MCU进行上电初始化,外部中断关闭、标志位清零
    输入参数：无
    输出参数：无
    返回值  ：无
********************************************************************/

void Init_MCU_INT1(void)
{
    INTCON2bits.INT1EP = 1;                // INT1EP：外部中断1 边沿检测极性选择位
                                           // 1 = 负边沿处中断
                                           // 0 = 正边沿处中断

    IFS1bits.INT1IF    = 0;                // 清外部中断1标记
    IPC4bits.INT1IP    = 0;                // 外部中断1优先级为0
    IEC1bits.INT1IE    = 0;                // 禁止外部中断1 
}
/*******************************************************************

    函数名称：void Init_MCU_INT2(void)
    功    能：对MCU进行上电初始化,外部中断关闭、标志位清零
    输入参数：无
    输出参数：无
    返回值  ：无
********************************************************************/

void Init_MCU_INT2(void)                                                     
{                                                                               
                                                                                
    INTCON2bits.INT2EP = 1;                // INT2EP：外部中断2 边沿检测极性选择位
                                           // 1 = 负边沿处中断
                                           // 0 = 正边沿处中断
    IFS1bits.INT2IF    = 0;                // 清外部中断2标记
    IPC5bits.INT2IP    = 0;                // 外部中断2优先级为4
    IEC1bits.INT2IE    = 0;                // 禁止外部中断2  
                                                                                
}







/*******************************************************************

    函数名称：void Init_SYS_IOPorts(void)
    功    能：对系统进行上电初始化

              RB0     PGD/EMUD/AN0/CN2        I   环境温度采样输入
              RB1     PGC/EMUC/AN1/CN3        I   交流输出电流采样输入
              RB2     AN2/SS1/LVDIN/CN4       I   交流输出电压采样输入
              RB3     AN3/INDX/CN5            I   直流链电压采样输入
              RB4     AN4/QEA/CN6             O   测试口输入出
              RB5     AN5/QEB/CN7             I   无频率检测输入
              RB6     AN6/OCFA                I   无
              RB7     AN7                     I   无
              RB8     AN8                     I   无

              RC13    EMUD1/SOSC1/CN1/U1ATX   O   Tx
              RC14    EMUC1/SOSCO/CN0/U1ARX   I   Rx
              RC15    OSC2/CLKO               I   外部晶振 

              RD0     EMUC2/OC1               O   步进电机PWM驱动A
              RD1     EMUD2/INT2/OC2          O   步进电机PWM驱动B    
              RD2     OC3                     O   步进电机PWM驱动C
              RD3     OC4                     O   步进电机PWM驱动D

              RE0     PWM1L                   I   Phase1 L
              RE1     PWM1H                   I   Phase1 H
              RE2     PWM2L                   O   Phase2 L
              RE3     PWM2H                   O   Phase2 H
              RE4     PWM3L                   O   Phase3 L
              RE5     PWM3H                   O   Phase3 H
              RE8     FLTA/INT1               I   PWM Fault

              RF0                             O   无
              RF1                             O   整流桥使能
              RF2     PGC                     O   仿真
              RF3     PGD                     O   仿真、正常运行指示灯
              RF4     U2RX/CN17               I   按键2
              RF5     U2TX/CN18               I   按键1
              RF6     SCK1                    O   停机指示

    输入参数：无
    输出参数：无
    返回值  ：无
********************************************************************/

void Init_SYS_IOPorts(void)
{

    LATB  = 0x0000;
    LATC  = 0x0000; 
    LATD  = 0x0000;
    LATE  = 0x0000;
    LATF  = 0x0000;
    TRISB = 0xFFFF;              
    TRISC = 0x8FFF;                                        // 0xc000
    TRISD = 0x037F;
    TRISE = 0x0000;
    TRISF = 0x0040;                                        // RF5 做调试端口
    TRISG = 0x0006;

}
/*---------------------------初始化IO口结束--------------------*/


/*******************************************************************

    函数名称：void Init_SYS_Interrupt(void)
    功    能：对系统进行上电初始化,开启各个中断，标志位清零，
              优先级为零各自分配。
    输入参数：无
    输出参数：无
    返回值  ：无
********************************************************************/

void Init_SYS_Interrupt(void)
{
    INTCON1          = 0x0000;                    //允许中断嵌套
    
    IFS0bits.ADIF    = 0;
    IFS0bits.INT0IF  = 0;
    IFS1bits.INT2IF  = 0;
    IFS0bits.U1RXIF  = 0;
    IFS0bits.U1TXIF  = 1;
    IFS0bits.T1IF    = 0;
    IFS0bits.T2IF    = 0;
    IFS0bits.T3IF    = 0;
    IFS1bits.T4IF    = 0;
    IFS1bits.T5IF    = 0;
    IFS0bits.IC1IF   = 0;
    IFS0bits.IC2IF   = 0;
	IFS1bits.IC3IF   = 0;
    IFS0bits.OC1IF   = 0;
    IFS0bits.OC2IF   = 0;
    IFS1bits.OC4IF   = 0;
    IFS1bits.OC3IF   = 0;
    IFS2bits.FLTAIF  = 0;
    IFS2bits.PWMIF   = 0;






    IPC0bits.INT0IP  = 0;
    IPC9bits.PWMIP   = 0;
    IPC2bits.ADIP    = 4;
    IPC1bits.T2IP    = 2;        // 为步进电机提供时钟
    IPC0bits.T1IP    = 1;        // 为个模块提供时钟
    IPC1bits.T3IP    = 6;        // 频率检测计算频率
    IPC0bits.IC1IP   = 4;
    IPC1bits.IC2IP   = 7;
	IPC7bits.IC3IP   = 5;
    IPC2bits.U1RXIP  = 3;
    IPC2bits.U1TXIP  = 2;
	IPC0bits.INT0IP  = 0;                                  // 外部中断0优先级为0
    IPC5bits.INT2IP  = 0;
    IPC4bits.OC3IP   = 0;
    IPC5bits.OC4IP   = 0;
    IPC5bits.T4IP    = 0;
    IPC5bits.T5IP    = 0;
    IPC10bits.FLTAIP = 0;

    IEC0bits.U1RXIE  = 1;
    IEC0bits.U1TXIE  = 1; 
    IEC2bits.PWMIE   = 0;
    IEC0bits.ADIE    = 1;
    IEC0bits.T1IE    = 1;
    IEC0bits.T2IE    = 1;
    IEC0bits.T3IE    = 1;
    IEC0bits.INT0IE  = 0;
    IEC1bits.T4IE    = 0;
    IEC1bits.T5IE    = 0;
    IEC0bits.IC1IE   = 0;
    IEC0bits.IC2IE   = 0;
    IEC1bits.IC3IE   = 1;	
    IEC2bits.FLTAIE  = 0;
    IEC1bits.INT2IE  = 0;
}



/*******************************************************************

    函数名称：void Init_SYS_COMP(void)
    功    能：对MCU进行上电初始化,比较输出关闭输出、中断、标志位清零
    输入参数：无
    输出参数：无
    返回值  ：无
********************************************************************/

void Init_SYS_COMP(void)
{
                                                                 
                                                                                
}        

/*******************************************************************

    函数名称：void Init_SYS_TIME1(void)
    功    能：对MCU进行上电初始化,TIME1 关闭输出、中断、标志位清零
    输入参数：无
    输出参数：无
    返回值  ：无
********************************************************************/

void Init_SYS_TIME1(void)
{

    T1CON           = 0x0000;
    TMR1            = 0x0000;
    PR1             = T1_PR1;
    IPC0bits.T1IP   = 0;                     // 定时器1中断优先级0
    IFS0bits.T1IF   = 0;                     // 定时器1中断标志位清0
    IEC0bits.T1IE   = 0;                     // 定时器1中断使能0
    T1CONbits.TCKPS = 0;                
						                 /*   bit 15   TON：  定时器开控制位
						                                      1= 启动定时器
						                                      0= 停止定时器
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
						                      bit 2    TSYNC：定时器外部时钟输入同步选择位
						                                      当TCS=1 时：
						                                      1= 同步外部时钟输入
						                                      0= 不同步外部时钟输入
						                                      当TCS=0 时：
						                                      此位被忽略。读作0。当TCS=0 时， Timer1 使用内部时钟。
						                      bit 1    TCS：  定时器时钟源选择位
						                                      1= 来自TxCK 引脚的外部时钟
						                                      0= 内部时钟（FOSC/4）
						                      bit 0    未用： 读作0
						                */
    T1CON = T1CON | 0x8000;
}


/*******************************************************************

    函数名称：void Init_SYS_TIME2(void)
    功    能：对MCU进行上电初始化,TIME2 关闭输出、中断、标志位清零
    输入参数：无
    输出参数：无
    返回值  ：无
********************************************************************/

void Init_SYS_TIME2(void)
{
    T2CON = 0;

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
						                      bit 3    T32：  32 位定时器模式选择位
						                                      1=TMRx 和TMRy 形成32 位定时器
						                                      0=TMRx 和TMRy 为独立的16 位定时器
						                      bit 2    未用： 读作0
						                      bit 1    TCS：  定时器时钟源选择位
						                                      1= 来自TxCK 引脚的外部时钟
						                                      0= 内部时钟（FOSC/4）
						                      bit 0    未用： 读作0
						                */
	T2CONbits.TCKPS = 2;					                
    TMR2          = 0x0000;
    PR2           = 0xFFFF;
    IPC1bits.T2IP = 0;                     // 定时器2中断优先级0
    IFS0bits.T2IF = 0;                     // 定时器2中断标志位清0
    IEC0bits.T2IE = 0;                     // 定时器2中断使能0
    T2CON         = T2CON | 0x0000;
}



/*******************************************************************

    函数名称：void Init_SYS_TIME4(void)
    功    能：对MCU进行上电初始化,TIME4 关闭输出、中断、标志位清零
    输入参数：无
    输出参数：无
    返回值  ：无
********************************************************************/

void Init_SYS_TIME4(void)
{

    T4CON           = 0x0000; 
    TMR4            = 0x0000;
    PR4             = 0xFFFF;
    IPC5bits.T4IP   = 0;                   // 定时器4中断优先级0
    IFS1bits.T4IF   = 0;                   // 定时器4中断标志位清0
    IEC1bits.T4IE   = 0;                   // 定时器4中断使能0
    T4CONbits.TCKPS = 2;       
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
						                      bit 3    T32：  32 位定时器模式选择位
						                                      1=TMRx 和TMRy 形成32 位定时器
						                                      0=TMRx 和TMRy 为独立的16 位定时器
						                      bit 2    未用： 读作0
						                      bit 1    TCS：  定时器时钟源选择位
						                                      1= 来自TxCK 引脚的外部时钟
						                                      0= 内部时钟（FOSC/4）
						                      bit 0    未用： 读作0
						                */
    T4CON = T4CON | 0x0000;
}


/*******************************************************************

    函数名称：void Init_SYS_TIME5(void)
    功    能：对MCU进行上电初始化,TIME5 关闭输出、中断、标志位清零
    输入参数：无
    输出参数：无
    返回值  ：无
********************************************************************/

void Init_SYS_TIME5(void)
{

    T5CON         = 0x0000;     
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
									                      bit 3    T32：  32 位定时器模式选择位
									                                      1=TMRx 和TMRy 形成32 位定时器
									                                      0=TMRx 和TMRy 为独立的16 位定时器
									                      bit 2    未用： 读作0
									                      bit 1    TCS：  定时器时钟源选择位
									                                      1= 来自TxCK 引脚的外部时钟
									                                      0= 内部时钟（FOSC/4）
									                      bit 0    未用： 读作0
									                */
    TMR5          = 0x0000;
    PR5           = 0xFFFF;
    IPC5bits.T5IP = 0;                     // 定时器5中断优先级0
    IFS1bits.T5IF = 0;                     // 定时器5中断标志位清0
    IEC1bits.T5IE = 0;                     // 定时器5中断使能0
    T5CON         = T5CON | 0x0000;
}





/*******************************************************************

    函数名称：void Init_SYS_INT0(void)
    功    能：对MCU进行上电初始化,外部中断关闭、标志位清零
    输入参数：无
    输出参数：无
    返回值  ：无
********************************************************************/

void Init_SYS_INT0(void)
{
    INTCON2bits.INT0EP = 1;                // INT0EP：外部中断0 边沿检测极性选择位
                                           // 1 = 负边沿处中断
                                           // 0 = 正边沿处中断

    IFS0bits.INT0IF    = 0;                // 清外部中断0标记
    IPC0bits.INT0IP    = 0;                // 外部中断0优先级为0
    IEC0bits.INT0IE    = 0;                // 禁止外部中断2 
}


/*******************************************************************

    函数名称：void Init_SYS_INT2(void)
    功    能：对MCU进行上电初始化,外部中断关闭、标志位清零
    输入参数：无
    输出参数：无
    返回值  ：无
********************************************************************/

void Init_SYS_INT2(void)                                                     
{                                                                               
                                                                                
    INTCON2bits.INT2EP = 1;                // INT2EP：外部中断2 边沿检测极性选择位
                                           // 1 = 负边沿处中断
                                           // 0 = 正边沿处中断
    IFS1bits.INT2IF    = 0;                // 清外部中断2标记
    IPC5bits.INT2IP    = 0;                // 外部中断2优先级为4
    IEC1bits.INT2IE    = 0;                // 禁止外部中断2  
                                                                                
} 
                                           
/*******************************************************************

    函数名称：void Init_SYS_Data(void)
    功    能：对MCU进行系统上电初始化，对所需的寄存器进行初始化
    输入参数：无
    输出参数：无
    返回值  ：无
********************************************************************/

void Init_SYS_Data(void)
{
	UInt16  sh_szie = 0;
	UInt16  sh_addr = 0;

	
	sh_szie = &g_RamVarEnd - &g_RamVarStart + 1;
	
    /******       所有全局变量初值先赋零          **********/
	for( sh_addr=(UInt16)&g_RamVarStart; sh_addr<=(UInt16)&g_RamVarEnd; sh_addr++ )
	{
		*(UInt8*)sh_addr = 0;
	}	
	/******在全部赋零初值之后,特殊的变量赋固定的初值**********/

	g_Frequency                    = 200;
	key_Start.Delay_MaxCount       = 7;                    // 7*6=42ms
    str_GLed_Start.Delay_MaxCount  = 7;                    // 7*6=42ms
    str_RLed_Start.Delay_MaxCount  = 7;                    // 7*6=42ms
    str_SCR_Start.Delay_MaxCount   = 7;                    // 7*6=42ms
    str_StepL_Start.Delay_MaxCount = 7;                    // 7*6=42ms
    str_StepR_Start.Delay_MaxCount = 7;                    // 7*6=42ms

	MAINPowerRelay 	           	   = !MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	           = !MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay               = !AUX_RLY_ENABLE;	
	ASSISTBufferRelay 	           = !AUX_BUFFER_ENABLE;	
	MCU_Reset 			           = MCU_RESET_ENABLE;			
	LOAD_300W			           = !LOAD_300W_ENABLE;			
	LOAD_1000W			           = !LOAD_1000W_ENABLE;		
	LOAD_RCDA			           = !LOAD_RCD_13A;				
	MODE_Switch			           = !SAVE_KEY_ENABLE;			
	Temperature_Switch	           = !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		           = !PROTECT_KEY_ENABLE;			
	Discharger_Switch	           = DISCHARGER_ENABLE;
	LOAD_Switch                    = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch                      = !TP_SWITCH_ENABLE;
	COMMState_LED                  = LED_DISABLE;          // 熄

}




