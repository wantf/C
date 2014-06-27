#ifndef	_USER_DEFINE_H
#define _USER_DEFINE_H
#include  "p30f5015.h"

#define BIT0                       1
#define BIT1                       1<<1
#define BIT2                       1<<2
#define BIT3                       1<<3
#define BIT4                       1<<4
#define BIT5                       1<<5
#define BIT6                       1<<6
#define BIT7                       1<<7
#define BIT8                       1<<8
#define BIT9                       1<<9
#define BIT10                      1<<10
#define BIT11                      1<<11
#define BIT12                      1<<12
#define BIT13                      1<<13
#define BIT14                      1<<14
#define BIT15                      1<<15

#define LED_ENABLE                  0
#define LED_DISABLE                 1
//#define	ENABLE		                1
//#define	DISABLE		                0


#define MAIN_POWER_RLY_ENABLE       1

#define MAIN_BUFFER_RLY_ENABLE      1

#define AUX_RLY_ENABLE              1

#define AUX_BUFFER_ENABLE           1

#define MCU_RESET_ENABLE            1

#define LOAD_300W_ENABLE            1

#define LOAD_1000W_ENABLE           1

#define LOAD_RCD_13A                1

#define SAVE_KEY_ENABLE             1

#define TEMPT_PROTECT_ENABLE        1

#define PROTECT_KEY_ENABLE          1

#define DISCHARGER_ENABLE           1

#define LOAD_RCD_SWITCH_ENABLE      1

#define TP_SWITCH_ENABLE            1

//--------------------    �������е���������     --------------------
//---------------------   �汾�� �����ͳ�Ա����  ----
#define CM_CLASS_VERSION           0xFF                   // �����
#define CM_MEMBER_VERSION_SELF     0xFF                   // ��Ա����

//---------------------   ��־λ �����ͳ�Ա����  ----
#define CM_CLASS_FLAG              0x10                    // �����
#define CM_MEMBER_FLAG_FAULT       0x00                    // ��Ա����
#define CM_MEMBER_FLAG_STATE       0x01                    // ��Ա����

//---------------------   ���� �����ͳ�Ա����  ------
#define CM_CLASS_CURRENT           0x20                    // �����
#define CM_MEMBER_CURRENT_AC       0x00                    // ��Ա����

//---------------------   ��ѹ �����ͳ�Ա����  ------
#define CM_CLASS_VOLTAGE           0x30                    // �����
#define CM_MEMBER_VOLTAGE_DC       0x00                    // ��Ա����
#define CM_MEMBER_VOLTAGE_AC       0x01                    // ��Ա����


//---------------------   ���� �����ͳ�Ա����  ------
#define CM_CLASS_POWER             0x40                    // �����
#define CM_MEMBER_POWER_OUT        0x30                    // ��Ա����

//---------------------   �¶� �����ͳ�Ա����  ------
#define CM_CLASS_TEMPRT            0x50                    // �����
#define CM_MEMBER_TEMPRT_CASE      0x00                    // ��Ա����

//---------------------   Ƶ�� �����ͳ�Ա����  ------
#define CM_CLASS_FREQUNCY          0x60           	       // �����
#define CM_MEMBER_FREQUNCY_MOTOR   0x00      		       // ��Ա����

//---------------------   ʱ�� �����ͳ�Ա����  ------------------------
#define	CLASS_TIME		           0X70                    //ʱ��


//--------------------  �������е�AD�˲�ϵ��  ------------------------------
#define	FILT_Ratio	               30                      //�����˲�ϵ��Ϊ30%
//--------------------    ���������ض���     -------------------------------
typedef signed   char              SInt8;                  
typedef unsigned char              UInt8;                  
typedef signed   int               SInt16;                 
typedef unsigned int               UInt16;                 
typedef signed   long              SInt32;                 
typedef unsigned long              UInt32;                 

//****************  ���� ************************************
#define CM_FOSCEXT                 7372800                 // �ⲿ�����ʱ��Ƶ�� (Hz)
#define CM_PLL                     8                       // PLL����
#define CM_FOSC                    (CM_FOSCEXT*CM_PLL)     // ʱ��Ƶ�� (Hz)
#define CM_FCY                     (CM_FOSC/4)             // ָ��Ƶ�� (Hz)
#define CM_TCY                     (1.0/CM_FCY)            // ָ������ (s)


/******************************  T1 ��ʼ������ **************************/
#define TIMEBASE                   1                       // UNIT ��λ����
#define T1_PR1                     (TIMEBASE*15260) 
                                                             
/*****************************  T1 ��ʼ�����ý��� **********************/

      
#define TIME_5MS		           3  //5--->3   5/30
#define TIME_6MS		           6
#define TIME_60MS		           60
#define TIME_3000MS		           5000
#define TRUE                       1
#define FALSE                      0

//*****************  ������־λ����  ************************************
typedef union tagFlagBITS{
    unsigned int Data;
    struct{
        unsigned bits0 :1;
        unsigned bits1 :1;  
        unsigned bits2 :1;
        unsigned bits3 :1;
        unsigned bits4 :1;
        unsigned bits5 :1;
        unsigned bits6 :1;
        unsigned bits7 :1;
        unsigned bits8 :1;
        unsigned bits9 :1;
        unsigned bits10:1;
        unsigned bits11:1;
        unsigned bits12:1;
        unsigned bits13:1;
        unsigned bits14:1;
        unsigned bits15:1;     
    }bits;
}FlagBITS;

#define	MissPhaseErr		       0x20                    // �����ĵ�����ֵ���ȵĵ�ȱ����Сֵ����
#define NO_PROJECT_ID              0xfa                    // �������ļ����Ŀ����
#define START_FLAG_DATA	           0x95
#define KEY_ON	                   1
#define KEY_OFF                    0
typedef struct _UartData_Dispose_INFO
{
	UInt8 TestProject_ID;
	void (* Data_Dispose)(void);
}UartData_Dispose_INFO;
typedef union un_TX_RX_DATA_PACK{
        unsigned char  ay_ucPack[10];
        struct{
                  unsigned int     uiPackHead;
                  unsigned char    ucPackCmd;
                  unsigned char    ucPackProject;
                  unsigned char    ucPackClass;
                  unsigned char    ucPackMember;
                  unsigned int     uiPackData;
                  unsigned int     uiPackVerify;
              }PACK;
}TX_RX_PACK;

typedef struct _KeyInfo
{	         
	UInt8	IO_H_count;                                    // 0 
	UInt8 	IO_L_count; 	                               // 1
	UInt8  	Delay_MaxCount;                                // 2
	UInt8  	Key_State;                                     // 3
} KeyInfo;
#define TX_START                   Flag1bits.bits.bits0    // ���ڷ��Ϳ�ʼ��־λ
#define RX_END                     Flag1bits.bits.bits1    // ���ڽ�����ɱ�־λ
#define RX_CACHE_UPDATA            Flag1bits.bits.bits2    // ���ջ���������־λ
#define PACK_PACKAGE_END           Flag1bits.bits.bits3    // ���������־λ
#define UART_DELAY_TIME            Flag1bits.bits.bits4    // 
#define WAIT_AdUpdateStart         Flag1bits.bits.bits5    // 
#define WAIT_AdUpdateEnd           Flag1bits.bits.bits6    // 
#define TestStart_Flag             Flag1bits.bits.bits7    // 
#define bits804                    Flag1bits.bits.bits8    //  
#define bits805                    Flag1bits.bits.bits9    // 
#define bits806                    Flag1bits.bits.bits10   //
#define bits807                    Flag1bits.bits.bits11   //
#define bits808                    Flag1bits.bits.bits12   //
#define STEP_POSITION_UPDATA       Flag1bits.bits.bits13   //
#define TMR3_OVERFLOW         	   Flag1bits.bits.bits14   //
#define BOR_PROTECT_STATE          Flag1bits.bits.bits15   //


#define TP_TEST_OVER               Flag2bits.bits.bits1    //  
#define TP_TMR3_OVERFLOW           Flag2bits.bits.bits2    // 
#define TMR2_OVERFLOW              Flag2bits.bits.bits3    //
#define WAIT_2MS_Start             Flag2bits.bits.bits4    //
#define WAIT_2MS_End               Flag2bits.bits.bits5    //
#define WAIT_5MS_Start             Flag2bits.bits.bits6    //  
#define WAIT_5MS_End               Flag2bits.bits.bits7    // 
#define bits008                    Flag2bits.bits.bits8    //
#define bits009                    Flag2bits.bits.bits9    //
#define bits010                    Flag2bits.bits.bits10   //
#define bits011                    Flag2bits.bits.bits11   //  
#define bits012                    Flag2bits.bits.bits12   // 
#define bits013                    Flag2bits.bits.bits13   //
#define bits014                    Flag2bits.bits.bits14   //
#define ERROR_CAPT_OVER            Flag2bits.bits.bits15   // �̻���ʱ





//**************************I/O�ĺ궨��*****************************************

//******************************input****************************
#define KEY_StartState   		   _RD0                    // ������I/O����
#define LED_NormalMode		       _RD5
#define LED_FaultMode		       _RD4
#define EN_ACD				       _RD3
#define STEP_L				       _RD2
#define STEP_R				       _RD1

//*********************************output***************************
#define	MAINPowerRelay		       _LATE5	               // ����̵���
#define	MAINBufferRelay		       _LATE6	               // ������̵���
#define	ASSISTPowerRelay	       _LATE3	               // ����̵���
#define	ASSISTBufferRelay	       _LATE4	               // ���绺��̵���
#define	MCU_Reset			       _LATE7	               // MCU��λ�̵���
#define	LOAD_300W			       _LATE2
#define	LOAD_1000W		           _LATF1
#define	LOAD_RCDA			       _LATE1
#define	MODE_Switch		           _LATG6	               // ģʽ�л�����
#define	Temperature_Switch	       _LATG8	               // �¶ȳ��޿���
#define	Protect_Switch		       _LATG7	               // �����г�����
#define	Discharger_Switch	       _LATG9	               // �ŵ翪��

#define	COMUNICATION_OK		       _LATC14  	           // ͨ��ָʾ��
#define	COMMState_LED		       _LATC13  	           // ����״ָ̬ʾ��
#define	LOAD_Switch			       _LATE0	               // ���ؿ���
#define	TP_Switch			       _LATF0	               // ���� TP �źſ���



#define	TEST_IO1			       _LATF5	               // ���� 


#endif
