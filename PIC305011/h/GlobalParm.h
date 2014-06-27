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
extern UInt16     g_uiOutVoltage;                                   // ��Ƭ���˿ڵ�ѹ--���������ѹ
extern UInt16     g_uiOutCurrent;                                   // ��Ƭ���˿ڵ�ѹ--�����������
extern UInt16     g_uiTemprt;                                       // ��Ƭ���˿ڵ�ѹ--�¶�
extern UInt16     g_uiMCUBus;                                       // ��Ƭ���˿ڵ�ѹ--ĸ�ߵ�ѹ
extern UInt16     g_uiMCU5V;                                        // ��Ƭ�������ѹ
extern UInt16     g_uiINV15V1;                                      // ������Ծٵ�ѹ
extern UInt16     g_uiINV15V2;                                      // ������Ծٵ�ѹ
extern UInt16     g_uiAPhase;                                       // �������� A ���ѹ��
extern UInt16     g_uiBPhase;                                       // �������� B ���ѹ��
extern UInt16     g_uiCPhase;                                       // �������� C ���ѹ��
extern UInt16     g_uiVBus;                                         // ĸ�ߵ�ѹ
extern UInt16     g_uiOutVoltagefilt;                                   // ��Ƭ���˿ڵ�ѹ--���������ѹ
extern UInt16     g_uiOutCurrentfilt;                                   // ��Ƭ���˿ڵ�ѹ--�����������
extern UInt16     g_uiTemprtfilt;                                       // ��Ƭ���˿ڵ�ѹ--�¶�
extern UInt16     g_uiMCUBusfilt;                                       // ��Ƭ���˿ڵ�ѹ--ĸ�ߵ�ѹ
extern UInt16     g_uiMCU5Vfilt;                                        // ��Ƭ�������ѹ
extern UInt16     g_uiINV15V1filt;                                      // ������Ծٵ�ѹ
extern UInt16     g_uiINV15V2filt;                                      // ������Ծٵ�ѹ
extern UInt16     g_uiAPhasefilt;                                       // �������� A ���ѹ��
extern UInt16     g_uiBPhasefilt;                                       // �������� B ���ѹ��
extern UInt16     g_uiCPhasefilt;                                       // �������� C ���ѹ��
extern UInt16     g_uiVBusfilt;                                         // ĸ�ߵ�ѹ
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
extern KeyInfo    str_GLed_Start;                                   // �̵�״̬�ṹ��
extern KeyInfo    str_RLed_Start;                                   // ���״̬�ṹ��
extern KeyInfo    str_SCR_Start;                                    // ������״̬�ṹ��
extern KeyInfo    str_StepL_Start;                                  // ���������ת״̬�ṹ��
extern KeyInfo    str_StepR_Start;                                  // ���������ת״̬�ṹ��
extern KeyInfo    str_Machine_Start;                                // ��е״״̬�ṹ��

extern UInt8	  g_RamVarEnd;

extern void SetupBoard(void); 
extern void Init_MCU_IOPorts(void);                                 //�ϵ��ʼ��MCU����IO�ڳ�ʼ��
extern void Init_MCU_Interrupt(void);                               //�ϵ��ʼ��MCU�������е��жϳ�ʼ��
extern void Init_MCU_ADC(void);                                     //�ϵ��ʼ��MCU����ADC�ڳ�ʼ��
extern void Init_MCU_COMP(void);                                    //�ϵ��ʼ��MCU���ԱȽϹ��ܳ�ʼ��
extern void Init_MCU_SPWM(void);                                    //�ϵ��ʼ��MCU����SPWM�ڳ�ʼ��
extern void Init_MCU_Uart(void);                                    //�ϵ��ʼ��MCU���Դ��ڳ�ʼ�� 
extern void Init_MCU_TIME1(void);                                   //�ϵ��ʼ��MCU���Զ�ʱ��1��ʼ��
extern void Init_MCU_TIME2(void);                                   //�ϵ��ʼ��MCU���Զ�ʱ��2�ڳ�ʼ��
extern void Init_MCU_TIME3(void);                                   //�ϵ��ʼ��MCU���Զ�ʱ��3�ڳ�ʼ��
extern void Init_MCU_TIME4(void);                                   //�ϵ��ʼ��MCU���Զ�ʱ��4�ڳ�ʼ��
extern void Init_MCU_INT2(void);                                    //�ϵ��ʼ��MCU�����ⲿ�жϳ�ʼ��
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


