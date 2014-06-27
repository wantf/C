#include   "UART.h"
#include   "user_define.h"
UInt8	   g_RamVarStart;
UInt16     g_uiOutVoltage;      // ��Ƭ���˿ڵ�ѹ--���������ѹ
UInt16     g_uiOutCurrent;      // ��Ƭ���˿ڵ�ѹ--�����������
UInt16     g_uiTemprt;      // ��Ƭ���˿ڵ�ѹ--�¶�
UInt16     g_uiMCUBus;      // ��Ƭ���˿ڵ�ѹ--ĸ�ߵ�ѹ
UInt16     g_uiMCU5V;      // ��Ƭ�������ѹ
UInt16     g_uiINV15V1;      // ������Ծٵ�ѹ
UInt16     g_uiINV15V2;      // ������Ծٵ�ѹ
UInt16     g_uiAPhase;      // �������� A ���ѹ��
UInt16     g_uiBPhase;      // �������� B ���ѹ��
UInt16     g_uiCPhase;      // �������� C ���ѹ��
UInt16     g_uiVBus;      // ĸ�ߵ�ѹ
UInt16     g_uiOutVoltagefilt;      // ��Ƭ���˿ڵ�ѹ--���������ѹ
UInt16     g_uiOutCurrentfilt;      // ��Ƭ���˿ڵ�ѹ--�����������
UInt16     g_uiTemprtfilt;      // ��Ƭ���˿ڵ�ѹ--�¶�
UInt16     g_uiMCUBusfilt;      // ��Ƭ���˿ڵ�ѹ--ĸ�ߵ�ѹ
UInt16     g_uiMCU5Vfilt;      // ��Ƭ�������ѹ
UInt16     g_uiINV15V1filt;      // ������Ծٵ�ѹ
UInt16     g_uiINV15V2filt;      // ������Ծٵ�ѹ
UInt16     g_uiAPhasefilt;      // �������� A ���ѹ��
UInt16     g_uiBPhasefilt;      // �������� B ���ѹ��
UInt16     g_uiCPhasefilt;      // �������� C ���ѹ��
UInt16     g_uiVBusfilt;      // ĸ�ߵ�ѹ
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



KeyInfo    key_Start		  ={0,0,0,0};               //����һ�μ��Ŀ�ʼ����

KeyInfo    str_GLed_Start	  ={0,0,0,0};               // �̵�״̬�ṹ��
KeyInfo    str_RLed_Start	  ={0,0,0,0};               // ���״̬�ṹ��
KeyInfo    str_SCR_Start	  ={0,0,0,0};               // ������״̬�ṹ��
KeyInfo    str_StepL_Start	  ={0,0,0,0};               // ���������ת״̬�ṹ��
KeyInfo    str_StepR_Start	  ={0,0,0,0};               // ���������ת״̬�ṹ��
KeyInfo    str_Machine_Start  ={0,0,0,0};               // ��е״״̬�ṹ��

FlagBITS   Flag1bits;
FlagBITS   Flag2bits;
TX_RX_PACK Tx_PACK;
TX_RX_PACK Rx_PACK;
TX_RX_PACK RxWorkCachePack;
TX_RX_PACK TxWorkCachePack;
TX_RX_PACK g_RxCache[2];

UInt8 	   g_RamVarEnd;

