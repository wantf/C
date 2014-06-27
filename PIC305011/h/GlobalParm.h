#ifndef _GLOBALPARM_H_
#define _GLOBALPARM_H_
#include "user_define.h"


extern UInt8	  g_RamVarStart;
extern UInt16     g_uiRxCount;
extern UInt16     g_uiRxCacheCount;
extern UInt16     g_uiUartDelayCount;
extern UInt16     g_Frequency;
extern UInt16     g_OutFrequency;
extern UInt16     g_TPDelay;
extern UInt16     g_uiOutVoltage;                                   // 单片机端口电压--输出交流电压
extern UInt16     g_uiOutCurrent;                                   // 单片机端口电压--输出交流电流
extern UInt16     g_uiTemprt;                                       // 单片机端口电压--温度
extern UInt16     g_uiMCUBus;                                       // 单片机端口电压--母线电压
extern UInt16     g_uiMCU5V;                                        // 单片机供电电压
extern UInt16     g_uiINV15V1;                                      // 逆变桥自举电压
extern UInt16     g_uiINV15V2;                                      // 逆变桥自举电压
extern UInt16     g_uiAPhase;                                       // 输入三相 A 相电压流
extern UInt16     g_uiBPhase;                                       // 输入三相 B 相电压流
extern UInt16     g_uiCPhase;                                       // 输入三相 C 相电压流
extern UInt16     g_uiVBus;                                         // 母线电压
extern UInt16     g_uiOutVoltagefilt;                                   // 单片机端口电压--输出交流电压
extern UInt16     g_uiOutCurrentfilt;                                   // 单片机端口电压--输出交流电流
extern UInt16     g_uiTemprtfilt;                                       // 单片机端口电压--温度
extern UInt16     g_uiMCUBusfilt;                                       // 单片机端口电压--母线电压
extern UInt16     g_uiMCU5Vfilt;                                        // 单片机供电电压
extern UInt16     g_uiINV15V1filt;                                      // 逆变桥自举电压
extern UInt16     g_uiINV15V2filt;                                      // 逆变桥自举电压
extern UInt16     g_uiAPhasefilt;                                       // 输入三相 A 相电压流
extern UInt16     g_uiBPhasefilt;                                       // 输入三相 B 相电压流
extern UInt16     g_uiCPhasefilt;                                       // 输入三相 C 相电压流
extern UInt16     g_uiVBusfilt;                                         // 母线电压
extern UInt16	  g_COMMStateTimer;	
extern UInt8	  g_KeyTimer;
extern UInt8	  g_ADDisposeTimer;
extern UInt8	  g_ADDelayTimer;
extern UInt8	  g_StepPosition;
extern UInt16     g_uiTPCounter;
extern UInt16	  g_Aarry_TPDelay[];
extern UInt16	  g_TPCounter;
extern UInt16     g_TP_Load[];
extern UInt16     g_Aarry_of_INV15V1[];
extern UInt16     g_Aarry_of_INV15V2[];
extern UInt16	  g_Wait_TP_IC3;
extern UInt16	  g_Wait_TP_T5;
extern UInt16     g_uiTemp1;
extern UInt16     g_uiTemp2;
extern UInt16     g_uiTemp3;
extern UInt16     g_uiNTC;
extern UInt16     g_uiNTCfilt;
extern UInt16     g_uiAUX;
extern UInt16     g_uiAUXfilt;
extern FlagBITS   Flag1bits;
extern FlagBITS   Flag2bits;
extern TX_RX_PACK Tx_PACK;
extern TX_RX_PACK Rx_PACK;
extern TX_RX_PACK RxWorkCachePack;
extern TX_RX_PACK TxWorkCachePack;
extern TX_RX_PACK g_RxCache[];
extern KeyInfo 	  key_Start;
extern KeyInfo    str_GLed_Start;                                   // 绿灯状态结构体
extern KeyInfo    str_RLed_Start;                                   // 红灯状态结构体
extern KeyInfo    str_SCR_Start;                                    // 整流桥状态结构体
extern KeyInfo    str_StepL_Start;                                  // 步进电机左转状态结构体
extern KeyInfo    str_StepR_Start;                                  // 步进电机右转状态结构体
extern KeyInfo    str_Machine_Start;                                // 机械状状态结构体

extern UInt8	  g_RamVarEnd;

extern void SetupBoard(void); 
extern void Init_MCU_IOPorts(void);                                 //上电初始化MCU，对IO口初始化
extern void Init_MCU_Interrupt(void);                               //上电初始化MCU，对所有的中断初始化
extern void Init_MCU_ADC(void);                                     //上电初始化MCU，对ADC口初始化
extern void Init_MCU_COMP(void);                                    //上电初始化MCU，对比较功能初始化
extern void Init_MCU_SPWM(void);                                    //上电初始化MCU，对SPWM口初始化
extern void Init_MCU_Uart(void);                                    //上电初始化MCU，对串口初始化 
extern void Init_MCU_TIME1(void);                                   //上电初始化MCU，对定时器1初始化
extern void Init_MCU_TIME2(void);                                   //上电初始化MCU，对定时器2口初始化
extern void Init_MCU_TIME3(void);                                   //上电初始化MCU，对定时器3口初始化
extern void Init_MCU_TIME4(void);                                   //上电初始化MCU，对定时器4口初始化
extern void Init_MCU_INT2(void);                                    //上电初始化MCU，对外部中断初始化
extern void Init_MCU_INT0(void);
extern void Init_MCU_INT1(void);
extern void Init_SYS_IOPorts(void);
extern void Init_SYS_TIME1(void);
extern void Init_SYS_TIME2(void);
extern void Init_SYS_TIME4(void);
extern void Init_SYS_TIME5(void);                      
extern void Init_SYS_INT2(void);
extern void Init_SYS_INT0(void);
extern void Init_SYS_Interrupt(void);
extern void Init_SYS_Data(void);
extern void Init_SYS_UART(void);
extern void Init_SYS_ADC(void);
extern void Init_SYS_IC1(void);
extern void Init_SYS_IC2(void);
extern void Init_SYS_IC3(void);
extern void Init_SYS_TIME3(void);
extern void Init_SYS_UART_IOPorts(void);
extern void SendPacket(void);
extern void ReceivePacket(void);
extern void PackingPackage(void);
extern void ReceiveData_Dispose(void);
extern void StartTest(void);
extern void Delay_60MS(void);
extern void Delay_2MS(void);
extern void Delay_5MS(void);
#endif


