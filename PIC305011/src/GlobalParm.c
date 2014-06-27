#include   "UART.h"
#include   "user_define.h"
UInt8	   g_RamVarStart;
UInt16     g_uiOutVoltage;      // 单片机端口电压--输出交流电压
UInt16     g_uiOutCurrent;      // 单片机端口电压--输出交流电流
UInt16     g_uiTemprt;      // 单片机端口电压--温度
UInt16     g_uiMCUBus;      // 单片机端口电压--母线电压
UInt16     g_uiMCU5V;      // 单片机供电电压
UInt16     g_uiINV15V1;      // 逆变桥自举电压
UInt16     g_uiINV15V2;      // 逆变桥自举电压
UInt16     g_uiAPhase;      // 输入三相 A 相电压流
UInt16     g_uiBPhase;      // 输入三相 B 相电压流
UInt16     g_uiCPhase;      // 输入三相 C 相电压流
UInt16     g_uiVBus;      // 母线电压
UInt16     g_uiOutVoltagefilt;      // 单片机端口电压--输出交流电压
UInt16     g_uiOutCurrentfilt;      // 单片机端口电压--输出交流电流
UInt16     g_uiTemprtfilt;      // 单片机端口电压--温度
UInt16     g_uiMCUBusfilt;      // 单片机端口电压--母线电压
UInt16     g_uiMCU5Vfilt;      // 单片机供电电压
UInt16     g_uiINV15V1filt;      // 逆变桥自举电压
UInt16     g_uiINV15V2filt;      // 逆变桥自举电压
UInt16     g_uiAPhasefilt;      // 输入三相 A 相电压流
UInt16     g_uiBPhasefilt;      // 输入三相 B 相电压流
UInt16     g_uiCPhasefilt;      // 输入三相 C 相电压流
UInt16     g_uiVBusfilt;      // 母线电压
UInt16     g_uiRxCount;
UInt16     g_uiRxCacheCount;
UInt16     g_uiUartDelayCount;
UInt16     g_Frequency;    
UInt16     g_OutFrequency;
UInt16     g_TPDelay;
UInt16     g_uiTPCounter;
UInt8	   g_KeyTimer;
UInt8	   g_ADDisposeTimer;
UInt8	   g_ADDelayTimer;
UInt8	   g_StepPosition;
UInt16	   g_COMMStateTimer;
UInt16	   g_Aarry_TPDelay[3]; 
UInt16	   g_TPCounter;
UInt16	   g_Wait_TP_IC3;
UInt16	   g_Wait_TP_T5;
UInt16     g_TP_Load[6];
UInt16     g_Aarry_of_INV15V1[4];
UInt16     g_Aarry_of_INV15V2[4];
UInt16     g_uiTemp1;
UInt16     g_uiTemp2;
UInt16     g_uiTemp3;
UInt16     g_uiNTC;
UInt16     g_uiNTCfilt;
UInt16     g_uiAUX;
UInt16     g_uiAUXfilt;



KeyInfo    key_Start		  ={0,0,0,0};               //启动一次检测的开始按键

KeyInfo    str_GLed_Start	  ={0,0,0,0};               // 绿灯状态结构体
KeyInfo    str_RLed_Start	  ={0,0,0,0};               // 红灯状态结构体
KeyInfo    str_SCR_Start	  ={0,0,0,0};               // 整流桥状态结构体
KeyInfo    str_StepL_Start	  ={0,0,0,0};               // 步进电机左转状态结构体
KeyInfo    str_StepR_Start	  ={0,0,0,0};               // 步进电机右转状态结构体
KeyInfo    str_Machine_Start  ={0,0,0,0};               // 机械状状态结构体

FlagBITS   Flag1bits;
FlagBITS   Flag2bits;
TX_RX_PACK Tx_PACK;
TX_RX_PACK Rx_PACK;
TX_RX_PACK RxWorkCachePack;
TX_RX_PACK TxWorkCachePack;
TX_RX_PACK g_RxCache[2];

UInt8 	   g_RamVarEnd;

