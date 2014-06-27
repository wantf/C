
#include "GlobalParm.h"
#include "UART.h"

void PackingPackage(void);
const UartData_Dispose_INFO  uartdata_info[]={
	{0x01,Project01_Dispose},
	{0x02,Project02_Dispose},
	{0x03,Project03_Dispose},
	{0x04,Project04_Dispose},
	{0x05,Project05_Dispose},
	{0x06,Project06_Dispose},
	{0x07,Project07_Dispose},
	{0x08,Project08_Dispose},
	{0x09,Project09_Dispose},
	{0x0a,Project10_Dispose},	
	{0x0b,Project11_Dispose},
	{0x0c,Project12_Dispose},
	{0x0d,Project13_Dispose},
	{0x0e,Project14_Dispose},	
	{0x0f,Project15_Dispose},	
	{0x10,Project16_Dispose},
	{0x11,Project17_Dispose},	
	{0x12,Project18_Dispose},		
	{0x13,Project19_Dispose},	
	{0x14,Project20_Dispose},	
	{0x15,Project21_Dispose},
	{0x16,Project22_Dispose},	
	{0x17,Project23_Dispose},
	{0x18,Project24_Dispose},
	{0x19,Project25_Dispose},	
	{0x1a,Project26_Dispose},	
	{0x1b,Project27_Dispose},
	{0x1c,Project28_Dispose},	
	{0x1d,Project29_Dispose},	
	{0x1e,Project30_Dispose},
	{0x1f,Project31_Dispose},
	{0x20,Project32_Dispose},
	{0x21,Project33_Dispose},
	{0x22,Project34_Dispose},
    {0x23,Project35_Dispose},
	{0x24,Project36_Dispose},
	{0x25,Project37_Dispose},
	{0x26,Project38_Dispose},

	{0x27,Project39_Dispose},
	{0x28,Project40_Dispose},
	{0x29,Project41_Dispose},
	{0x2a,Project42_Dispose},


	
	{NO_PROJECT_ID,Error_Disprose}
};
void Project01_Dispose(void)
{
    COMUNICATION_OK     = LED_DISABLE;	
    //************�����ü̵���ֵ***********************
	MAINPowerRelay 		= !MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= !MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= !AUX_RLY_ENABLE;	
	ASSISTBufferRelay 	= !AUX_BUFFER_ENABLE;	
	MCU_Reset 			= MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;
    Delay_60MS();
    Delay_60MS();
	if(!(str_Machine_Start.Key_State & 0x01))			   // �����ݽ��и���		
	{
		TxWorkCachePack.PACK.uiPackData &= ~(BIT0);	
//		TxWorkCachePack.PACK.uiPackData = 1;		
	}
	else
	{
		TxWorkCachePack.PACK.uiPackData |= (BIT0);
//		TxWorkCachePack.PACK.uiPackData = 1;		
	}
	
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FLAG )// �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;
	}	
}

void Project02_Dispose(void)
{
//************�����ü̵���ֵ***********************

	MAINPowerRelay 		= !MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= !MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;	
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;

	TxWorkCachePack.PACK.uiPackData = 0;                   // �����ݽ��и���
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_VERSION )// �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;	
	}
	COMUNICATION_OK     = LED_DISABLE;
}

void Project03_Dispose(void)
{
//************�����ü̵���ֵ***********************

	MAINPowerRelay 		= !MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= !MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;	
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;

    Delay_60MS();
    Delay_60MS();
    Delay_60MS();
	TxWorkCachePack.PACK.uiPackData = g_uiMCUBusfilt;      // �����ݽ��и���
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_VOLTAGE )// �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;
	}
    COMUNICATION_OK     = LED_DISABLE;
}

void Project04_Dispose(void)
{
//************�����ü̵���ֵ***********************

	MAINPowerRelay 		= !MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= !MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;	
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;


    Delay_60MS();
    Delay_60MS();
    Delay_60MS();
	TxWorkCachePack.PACK.uiPackData = g_uiOutVoltagefilt;  // �����ݽ��и���
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_VOLTAGE )// �Ƿ�������������  
	{	
		PACK_PACKAGE_END= FALSE;
	}
    COMUNICATION_OK     = LED_DISABLE;
}

void Project05_Dispose(void)
{
//************�����ü̵���ֵ***********************
	MAINPowerRelay 		= !MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= !MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;	
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;

    Delay_60MS();
    Delay_60MS();
    Delay_60MS();
	TxWorkCachePack.PACK.uiPackData = g_uiOutCurrentfilt;  // �����ݽ��и���	
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_CURRENT)// �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;
	}
    COMUNICATION_OK     = LED_DISABLE;
}
void Project06_Dispose(void)
{
//************�����ü̵���ֵ***********************
	MAINPowerRelay 		= !MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= !MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;	
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;

    Delay_60MS();
    Delay_60MS();
    Delay_60MS();

    if( RxWorkCachePack.PACK.ucPackMember == 0 )
    { 
    	TxWorkCachePack.PACK.uiPackData = g_uiTemprtfilt;      // �����ݽ��и���   
    }
    else if( RxWorkCachePack.PACK.ucPackMember == 2 )
    {
	    TxWorkCachePack.PACK.uiPackData = g_uiNTCfilt;      // �����ݽ��и���       
    }
	
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_TEMPRT )// �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;
	}
    COMUNICATION_OK     = LED_DISABLE;
}
void Project07_Dispose(void)
{
//************�����ü̵���ֵ***********************

	MAINPowerRelay 		= !MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= !MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= !AUX_BUFFER_ENABLE;
    Delay_60MS();
	Delay_60MS();
	ASSISTPowerRelay	= AUX_RLY_ENABLE;	
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;

	Delay_60MS();
    Delay_60MS();
    Delay_60MS();
    Delay_60MS();
	Delay_60MS();

	TxWorkCachePack.PACK.uiPackData = g_uiMCU5Vfilt;       // �����ݽ��и���	
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_VOLTAGE )// �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;
	}	
    COMUNICATION_OK     = LED_DISABLE;
}
void Project08_Dispose(void)
{
//************�����ü̵���ֵ***********************
	MAINPowerRelay 		= !MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= !MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;
    Delay_60MS();
	Delay_60MS();
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_VOLTAGE)// �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;
	}
	if( RxWorkCachePack.PACK.ucPackMember ==0X0E )         // ��һ·15V
	{
TxWorkCachePack.PACK.uiPackData = g_uiINV15V1filt;
//		TxWorkCachePack.PACK.uiPackData = (g_Aarry_of_INV15V1[0]  
//			                              +g_Aarry_of_INV15V1[1]  
//			                              +g_Aarry_of_INV15V1[2]  
//			                              +g_Aarry_of_INV15V1[3])>>2; // �����ݽ��и���
	}
	else if( RxWorkCachePack.PACK.ucPackMember ==0X0F )
	{	
//		TxWorkCachePack.PACK.uiPackData =  (g_Aarry_of_INV15V2[0]  
//			                              +g_Aarry_of_INV15V2[1]  
//			                              +g_Aarry_of_INV15V2[2]  
//			                              +g_Aarry_of_INV15V2[3])>>2; // �����ݽ��и���
TxWorkCachePack.PACK.uiPackData = g_uiINV15V2filt;
	}
	else
	{
		PACK_PACKAGE_END = FALSE;
	}

    COMUNICATION_OK     = LED_DISABLE;	

}
void Project09_Dispose(void)                        //????????��Ҫ��ʱ��?
{
	MCU_Reset 			= MCU_RESET_ENABLE;                         // 0 reset 
//************�����ü̵���ֵ***********************
	MAINPowerRelay 		= MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= !MAIN_BUFFER_RLY_ENABLE;
	//��������̵���֮��,��ʱ60MS�ٿ������绺����
    Delay_60MS();
    Delay_60MS();
	//��������̵���֮��,��ʱ60MS�ٿ������绺����	
	MAINPowerRelay 		= MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= !DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;

    Delay_60MS();
    Delay_60MS();
    Delay_60MS();
	TxWorkCachePack.PACK.uiPackData = g_uiVBusfilt;        // �����ݽ��и���	
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_VOLTAGE )// �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;
	}
	MCU_Reset 			= !MCU_RESET_ENABLE; 
    COMUNICATION_OK     = LED_DISABLE;
}
void Project10_Dispose(void)
{
//************�����ü̵���ֵ***********************

	MAINPowerRelay 		= MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= !DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;


	TxWorkCachePack.PACK.uiPackData = 0;                   // �����ݽ��и���	
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_VOLTAGE )// �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;	
	}
    COMUNICATION_OK     = LED_DISABLE;
}
void Project11_Dispose(void)
{
//************�����ü̵���ֵ***********************
	MAINPowerRelay 		= MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= !DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;
    Delay_60MS();
    Delay_60MS();
    Delay_60MS();
	TxWorkCachePack.PACK.uiPackData = 230400/g_OutFrequency;   // �����ݽ��и���	
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FREQUNCY )// �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;	
	}
    COMUNICATION_OK     = LED_DISABLE;
}
void Project12_Dispose(void)
{
//************�����ü̵���ֵ***********************
	MAINPowerRelay 		= MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= !DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;
	TxWorkCachePack.PACK.uiPackData = 0;                   // �����ݽ��и���		
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_CURRENT )// �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;
	}
    COMUNICATION_OK     = LED_DISABLE;
}
void Project13_Dispose(void)
{
//************�����ü̵���ֵ***********************
	MAINPowerRelay 		= MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= !DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;
	TxWorkCachePack.PACK.uiPackData = 0;                   // �����ݽ��и���		
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_POWER )// �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;	
	}
    COMUNICATION_OK     = LED_DISABLE;
}

void Project14_Dispose(void)
{
//************�����ü̵���ֵ***********************
	MAINPowerRelay 		= MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= !DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;
	Delay_60MS();
    Delay_60MS();	
	if((str_RLed_Start.Key_State & 0x01)&&(!(str_GLed_Start.Key_State & 0x01)))				   // �����ݽ��и���		
	{
		TxWorkCachePack.PACK.uiPackData |= (BIT13);	
	}
	else
	{
		TxWorkCachePack.PACK.uiPackData &= ~(BIT13);	
	}  
	if(( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FLAG )||(RxWorkCachePack.PACK.ucPackMember!=FLAG_MEMBER_03))   // �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;		
	}
    COMUNICATION_OK     = LED_DISABLE;
}
void Project15_Dispose(void)                        // ����
{
//************�����ü̵���ֵ***********************
	MAINPowerRelay 		= MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= !DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;
	Delay_60MS();
	Delay_60MS();
	Delay_60MS();
	Delay_60MS();
	Delay_60MS();
//	TxWorkCachePack.PACK.uiPackData = g_StepPosition  ;
	//*
	if((g_StepPosition>>1)&1)							   // �����ݽ��и���		
	{
		TxWorkCachePack.PACK.uiPackData |= (BIT1);	
	}
	else
	{
		TxWorkCachePack.PACK.uiPackData &= ~(BIT1);	
	}  
//	*/
	if( (RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FLAG ) ||(RxWorkCachePack.PACK.ucPackMember!=FLAG_MEMBER_03))  // �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;	
	}
    COMUNICATION_OK     = LED_DISABLE;
}
void Project16_Dispose(void)
{
//************�����ü̵���ֵ***********************

	MAINPowerRelay 		= MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= !DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;

	Delay_60MS();
	Delay_60MS();
	if(check_PhaseMiss())							       // �����ݽ��и���		
	{
		TxWorkCachePack.PACK.uiPackData |= (BIT3);	
	}
	else
	{
		TxWorkCachePack.PACK.uiPackData &= ~(BIT3);	
	}  	
	if( (RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FLAG ) ||(RxWorkCachePack.PACK.ucPackMember!=FLAG_MEMBER_03))  // �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;	
	}
    COMUNICATION_OK     = LED_DISABLE;

}



void Project17_Dispose(void)
{
//************�����ü̵���ֵ***********************
	MAINPowerRelay 		= MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= !DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;
	TxWorkCachePack.PACK.uiPackData = 0;                   // �����ݽ��и���		
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_VOLTAGE )// �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;	 
	}
    COMUNICATION_OK     = LED_DISABLE;
}
void Project18_Dispose(void)
{
//************�����ü̵���ֵ***********************
	MAINPowerRelay 		= MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= !DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;
	TxWorkCachePack.PACK.uiPackData = 0;                   // �����ݽ��и���		
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_CURRENT )// �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;	
	}
    COMUNICATION_OK     = LED_DISABLE;
}
void Project19_Dispose(void)
{
//************�����ü̵���ֵ***********************
	MAINPowerRelay 		= MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= !DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;
	TxWorkCachePack.PACK.uiPackData = 230400/g_OutFrequency;  // �����ݽ��и���		
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FREQUNCY )// �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;	
	}

    IEC0bits.IC1IE      = 0;	                           // ��ֹ����1����
    IEC0bits.IC2IE      = 1;
    IEC1bits.IC3IE      = 0;
    COMUNICATION_OK     = LED_DISABLE;
	
}
void Project20_Dispose(void)
{
//************�����ü̵���ֵ***********************	
	MAINPowerRelay 		= MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= !DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;
	TxWorkCachePack.PACK.uiPackData = 0;                   // �����ݽ��и���		
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_POWER )// �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;
	}
    IEC0bits.IC1IE      = 0;	                           // ��ֹ����1����
    IEC0bits.IC2IE      = 1;
    IEC1bits.IC3IE      = 0;
    COMUNICATION_OK     = LED_DISABLE;
}
void Project21_Dispose(void)
{
//************�����ü̵���ֵ***********************
	MAINPowerRelay 		= MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= !DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;
	Delay_60MS();
	Delay_60MS();
	Delay_60MS();
	Delay_60MS();
	Delay_60MS();
	if((g_StepPosition>>2)&1)							   // �����ݽ��и���		
	{
		TxWorkCachePack.PACK.uiPackData |= (BIT2);	
	}
	else
	{
		TxWorkCachePack.PACK.uiPackData &= ~(BIT2);	
	}  	
	if( (RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FLAG ) ||(RxWorkCachePack.PACK.ucPackMember!=FLAG_MEMBER_03))  // �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;	
	}
	LOAD_1000W			= !LOAD_1000W_ENABLE;
    COMUNICATION_OK     = LED_DISABLE;
}
void Project22_Dispose(void)
{

//************�����ü̵���ֵ***********************
	MAINPowerRelay 		= MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= !DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;
    Delay_60MS();
    Delay_60MS();
	TxWorkCachePack.PACK.uiPackData = 0;                   // �����ݽ��и���		
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FLAG )// �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;	
	}
	IEC0bits.IC1IE      = 0;	                           // ��ֹ����1����
    IEC0bits.IC2IE      = 1;
    IEC1bits.IC3IE      = 0;
    COMUNICATION_OK     = LED_DISABLE;
}
void Project23_Dispose(void)
{
	int      i          = 0;
	UInt16   PR5_Temp   = 0;
    UInt16   uiTemp1    = 0;

	IC3CON              = 0x4000;
	IC2CON              = 0x4000;
    IEC0bits.IC1IE      = 0;	                           // ��ֹ����1����
    IEC0bits.IC2IE      = 0;
    IEC1bits.IC3IE      = 1;
	IFS1bits.IC3IF      = 0;
    IPC7bits.IC3IP      = 6;
    T5CON               = 0x0000; 
    TMR5                = 0x0000;
    uiTemp1             = RxWorkCachePack.PACK.uiPackData;
	if( RxWorkCachePack.PACK.ucPackMember == FLAG_MEMBER_03 )	  // �Ƿ������������� 
	{
        if( uiTemp1 == 0x1A00 )	
        {
			PR5_Temp        = uiTemp1;						   // 0x2291  12.5.24
		}
		else if( uiTemp1 == 0x0B00 )
		{
			PR5_Temp 		= uiTemp1;						   // 0x2291  12.5.24	
		}
		else
		{
		    PR5 		        = 0;
			TxWorkCachePack.PACK.uiPackData &= ~BIT4;		   // �����ݽ��и���
            TxWorkCachePack.PACK.ucPackMember = FLAG_MEMBER_03;
		    LOAD_Switch 		= !LOAD_RCD_SWITCH_ENABLE; 
		    LOAD_RCDA			= !LOAD_RCD_13A;	
		    T5CON				= 0x0000;
		    T3CON				= T3CON & 0x7FFF;
		    TMR3				= 0;
		    T3CONbits.TCKPS 	= 2;
		    TP_TMR3_OVERFLOW	= 0;
		    T3CON				= T3CON | 0x8000;		
		    IEC0bits.IC1IE		= 1;							   // ��ֹ����1����
		    IEC0bits.IC2IE		= 0;
		    IEC1bits.IC3IE		= 1;
		    IC2CON				= 0x4000;
		    g_TPCounter 		= 0;
		    g_TP_Load[0]		= 0;
		    g_TP_Load[1]		= 0;
		    g_TP_Load[2]		= 0;		
		    g_TP_Load[3]		= 0;
		    g_TP_Load[4]		= 0;
		    g_TP_Load[5]		= 0;
			COMUNICATION_OK     = LED_DISABLE;
			return;			
	     }
	}
	else
	{
		    PR5 		        = 0;
			TxWorkCachePack.PACK.uiPackData &= ~BIT4;		   // �����ݽ��и���
            TxWorkCachePack.PACK.ucPackMember = FLAG_MEMBER_03;

		    LOAD_Switch 		= !LOAD_RCD_SWITCH_ENABLE; 
		    LOAD_RCDA			= !LOAD_RCD_13A;	
		    T5CON				= 0x0000;
		    T3CON				= T3CON & 0x7FFF;
		    TMR3				= 0;
		    T3CONbits.TCKPS 	= 2;
		    TP_TMR3_OVERFLOW	= 0;
		    T3CON				= T3CON | 0x8000;		
		    IEC0bits.IC1IE		= 1;							   // ��ֹ����1����
		    IEC0bits.IC2IE		= 0;
		    IEC1bits.IC3IE		= 1;
		    IC2CON				= 0x4000;
		    g_TPCounter 		= 0;
		    g_TP_Load[0]		= 0;
		    g_TP_Load[1]		= 0;
		    g_TP_Load[2]		= 0;		
		    g_TP_Load[3]		= 0;
		    g_TP_Load[4]		= 0;
		    g_TP_Load[5]		= 0;
			COMUNICATION_OK     = LED_DISABLE;
			return;		
	 }

    PR5                 = PR5_Temp;
    T5CONbits.TCKPS     = 1; 
	IPC5bits.T5IP       = 7;                               // ��ʱ��5�ж����ȼ�0
    IFS1bits.T5IF       = 0;                               // ��ʱ��5�жϱ�־λ��0
    IEC1bits.T5IE       = 1;                               // ��ʱ��5�ж�ʹ��0
    //************�����ü̵���ֵ***********************

	MAINPowerRelay 		= MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= !DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;

    Delay_60MS();
	ERROR_CAPT_OVER     = 1;
	g_TPCounter         = 0;
    g_TP_Load[0]        = 0;
    g_TP_Load[1]        = 0;
	g_TP_Load[2]        = 0;

    g_TP_Load[3]        = 0;
    g_TP_Load[4]        = 0;
	g_TP_Load[5]        = 0;
	
	for(i = 0;i<6;i++)
	{
    	g_Wait_TP_IC3       = 0x11;
        g_Wait_TP_T5        = 0x11;
        IC3CON              = 0x4002;
 
	    WAIT_AdUpdateStart  = TRUE;
	    while(!WAIT_AdUpdateEnd)                               // ��ѭ���ȴ���ʱʱ�䵽,�ٻ�ȡADֵ
	    {	
            if( (g_Wait_TP_T5  == 0x00)&&(g_Wait_TP_IC3  == 0x00) )
            {
                break;
            }
	    }
	    WAIT_AdUpdateStart  = FALSE;                           // ��ʱ������ֹͣ
	    WAIT_AdUpdateEnd    = FALSE;  
	    Delay_5MS();
	    LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;  
	    IEC0bits.IC1IE      = 0;	                           // ��ֹ����1����
        IEC0bits.IC2IE      = 0;
        IEC1bits.IC3IE      = 0;
	    g_TP_Load[i]        = g_TPCounter;
	    g_TPCounter         = 0; 
        IEC1bits.IC3IE      = 1;	
	}

    IEC1bits.IC3IE      = 0;
	
    if( ERROR_CAPT_OVER )
    {

	    LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE; 
	    Delay_5MS();
	    LOAD_RCDA			= !LOAD_RCD_13A;	
 	    T3CON               = T3CON & 0x7FFF;
	    TMR3                = 0;
	    T3CONbits.TCKPS     = 2;
	    TP_TMR3_OVERFLOW    = 0;
	    T3CON               = T3CON | 0x8000;		
        IEC0bits.IC1IE      = 1;	                       // ��ֹ����1����
        IEC0bits.IC2IE      = 0;
        IEC1bits.IC3IE      = 1;
		T5CON               = 0x0000;
		IC2CON              = 0x4000;
        g_TPCounter         = 0;
		g_TP_Load[0]        = 0;
		g_TP_Load[1]        = 0;
		g_TP_Load[2]        = 0;
		
		g_TP_Load[3]		= 0;
		g_TP_Load[4]		= 0;
		g_TP_Load[5]		= 0;

		
		TxWorkCachePack.PACK.uiPackData &= ~BIT4;          // �����ݽ��и���
//TxWorkCachePack.PACK.uiPackData = 0xFFFF;
	    if( (RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FLAG )||
		    (RxWorkCachePack.PACK.ucPackMember!= FLAG_MEMBER_03))     // �Ƿ������������� 
	    {
		     PACK_PACKAGE_END = FALSE;	
	    }
		PR5 		        = 0;
//		TxWorkCachePack.PACK.uiPackData &= ~BIT4;		   // �����ݽ��и���
		LOAD_Switch 		= !LOAD_RCD_SWITCH_ENABLE; 
		LOAD_RCDA			= !LOAD_RCD_13A;	
		T5CON				= 0x0000;
		T3CON				= T3CON & 0x7FFF;
		TMR3				= 0;
		T3CONbits.TCKPS 	= 2;
		TP_TMR3_OVERFLOW	= 0;
		T3CON				= T3CON | 0x8000;		
		IEC0bits.IC1IE		= 1;							   // ��ֹ����1����
		IEC0bits.IC2IE		= 0;
		IEC1bits.IC3IE		= 1;
		IC2CON				= 0x4000;
		g_TPCounter 		= 0;
		g_TP_Load[0]		= 0;
		g_TP_Load[1]		= 0;
		g_TP_Load[2]		= 0;		
		g_TP_Load[3]		= 0;
		g_TP_Load[4]		= 0;
		g_TP_Load[5]		= 0;
		COMUNICATION_OK 	= LED_DISABLE;
		return;
	}
	Delay_5MS();

	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE; 
	IEC0bits.IC1IE      = 0;	                           // ��ֹ����1����
    IEC0bits.IC2IE      = 0;
    IEC1bits.IC3IE      = 0;
	g_TP_Load[0]        = g_TP_Load[0]+g_TP_Load[1]+g_TP_Load[2]+g_TP_Load[3]+g_TP_Load[4]+g_TP_Load[5];
	if( g_TP_Load[0] < 5 )
	{
		Delay_5MS();

	    LOAD_RCDA			= LOAD_RCD_13A;
        Delay_60MS();
        Delay_60MS();
	    IC3CON              = 0x4000;
	    IC2CON              = 0x4000;
        IEC0bits.IC1IE      = 0;	                       // ��ֹ����1����
        IEC0bits.IC2IE      = 0;
        IEC1bits.IC3IE      = 1;
	    IFS1bits.IC3IF      = 0;
        IPC7bits.IC3IP      = 6;
        T5CON               = 0x0000; 
        TMR5                = 0x0000;
        PR5                 = PR5_Temp;  
        T5CONbits.TCKPS     = 1; 
	    IPC5bits.T5IP       = 7;                           // ��ʱ��5�ж����ȼ�0
        IFS1bits.T5IF       = 0;                           // ��ʱ��5�жϱ�־λ��0
        IEC1bits.T5IE       = 1;                           // ��ʱ��5�ж�ʹ��0
		ERROR_CAPT_OVER     = 1;
	    g_TPCounter         = 0;
	    g_TP_Load[0]        = 0;
		g_TP_Load[1]        = 0;
		g_TP_Load[2]        = 0;

	    g_TP_Load[3]        = 0;
		g_TP_Load[4]        = 0;
		g_TP_Load[5]        = 0;

		
		for( i = 0;i<6;i++ )
		{
            g_Wait_TP_IC3       = 0x11;
            g_Wait_TP_T5        = 0x11; 
		    IC3CON              = 0x4002;

		    WAIT_AdUpdateStart  = TRUE;
	        while(!WAIT_AdUpdateEnd)                               // ��ѭ���ȴ���ʱʱ�䵽,�ٻ�ȡADֵ
	        {	
                if( (g_Wait_TP_T5  == 0x00)&&(g_Wait_TP_IC3  == 0x00) )
                {
                    break;
                }  
	        }
	        WAIT_AdUpdateStart  = FALSE;                           // ��ʱ������ֹͣ
	        WAIT_AdUpdateEnd    = FALSE;  
		    Delay_5MS();
	        LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE; 
	        IEC0bits.IC1IE      = 0;	                           // ��ֹ����1����
            IEC0bits.IC2IE      = 0;
            IEC1bits.IC3IE      = 0;
	        g_TP_Load[i]        = g_TPCounter;
	        g_TPCounter         = 0; 
            IEC1bits.IC3IE      = 1;	
	    }
		
        IEC1bits.IC3IE      = 0;
	    g_TP_Load[0]        = g_TP_Load[0]+g_TP_Load[1]+g_TP_Load[2]+g_TP_Load[3]+g_TP_Load[4]+g_TP_Load[5];	
	    if( (g_TP_Load[0] > 4)&&(!ERROR_CAPT_OVER ))
	    {
//TxWorkCachePack.PACK.uiPackData = 0x05FF;			
 	        TxWorkCachePack.PACK.uiPackData |= BIT4;       // �����ݽ��и���              
	    }
		else
		{
//TxWorkCachePack.PACK.uiPackData = 0xFFF3;	
//TxWorkCachePack.PACK.uiPackData = g_TP_Load[0];			
            TxWorkCachePack.PACK.uiPackData &= ~BIT4;      // �����ݽ��и���
		}
	}
    else
    {
//TxWorkCachePack.PACK.uiPackData = g_TP_Load[0];
//TxWorkCachePack.PACK.uiPackData = 0xFFF3;		
        TxWorkCachePack.PACK.uiPackData &= ~BIT4;          // �����ݽ��и���
	}
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE; 
	LOAD_RCDA			= !LOAD_RCD_13A;	
    T5CON               = 0x0000;
	T3CON               = T3CON & 0x7FFF;
	TMR3                = 0;
	T3CONbits.TCKPS     = 2;
	TP_TMR3_OVERFLOW    = 0;
	T3CON               = T3CON | 0x8000;		
    IEC0bits.IC1IE      = 1;	                           // ��ֹ����1����
    IEC0bits.IC2IE      = 0;
    IEC1bits.IC3IE      = 1;
	IC2CON              = 0x4000;
    g_TPCounter         = 0;
    g_TP_Load[0]        = 0;
    g_TP_Load[1]        = 0;
	g_TP_Load[2]        = 0;

    g_TP_Load[3]        = 0;
    g_TP_Load[4]        = 0;
	g_TP_Load[5]        = 0;

	
	if( (RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FLAG )||
		(RxWorkCachePack.PACK.ucPackMember!= FLAG_MEMBER_03))         // �Ƿ������������� 
	{
		PACK_PACKAGE_END= FALSE;	
	}
    COMUNICATION_OK     = LED_DISABLE;
}
void Project24_Dispose(void)
{
//************�����ü̵���ֵ***********************

	MAINPowerRelay 		= !MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= !MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= !DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = TP_SWITCH_ENABLE;
	Delay_2MS();
	TP_Switch           = !TP_SWITCH_ENABLE;
	IC2CON              = 0x4002;
    IEC0bits.IC1IE      = 0;	                           // ��ֹ����1����
    IEC0bits.IC2IE      = 0;
    IEC1bits.IC3IE      = 0;
	Delay_2MS();
	T3CON               = T3CON & 0x7FFF;
	TMR3                = 0;
	T3CONbits.TCKPS     = 0;
	TP_TMR3_OVERFLOW    = 0;
	T3CON               = T3CON | 0x8000;
	IEC0bits.IC1IE      = 0;	                           // ��ֹ����1����
    IEC0bits.IC2IE      = 1;
    IEC1bits.IC3IE      = 0;
//  	TP_Switch           = DISABLE;
	TP_Switch           = TP_SWITCH_ENABLE;
	g_TPDelay           = 0;
	Delay_2MS();
    IEC0bits.IC1IE      = 0;	                           // ��ֹ����1����
    IEC0bits.IC2IE      = 0;
    IEC1bits.IC3IE      = 0;	
//  	TP_Switch           = ENABLE;
	TP_Switch           = !TP_SWITCH_ENABLE;
	if( g_TPDelay>15000 )
	{
        g_Aarry_TPDelay[0] = 15000;
	}
	else
	{
	    g_Aarry_TPDelay[0] = g_TPDelay;
	}
	Delay_2MS();
	T3CON               = T3CON & 0x7FFF;
	TMR3                = 0;
	T3CONbits.TCKPS     = 0;
	TP_TMR3_OVERFLOW    = 0;
	T3CON               = T3CON | 0x8000;
    IEC0bits.IC1IE      = 0;	                           // ��ֹ����1����
    IEC0bits.IC2IE      = 1;
    IEC1bits.IC3IE      = 0;
//  	TP_Switch           = DISABLE; 
	TP_Switch           = TP_SWITCH_ENABLE;
	g_TPDelay           = 0;
	Delay_2MS();	
    IEC0bits.IC1IE      = 0;	                           // ��ֹ����1����
    IEC0bits.IC2IE      = 0;
    IEC1bits.IC3IE      = 0;	
//  	TP_Switch           = ENABLE;
	TP_Switch           = !TP_SWITCH_ENABLE;
	if( g_TPDelay>15000 )
	{
        g_Aarry_TPDelay[1] = 15000;
	}
	else
	{
	    g_Aarry_TPDelay[1] = g_TPDelay;
	}
	Delay_2MS();
	T3CON               = T3CON & 0x7FFF;
	TMR3                = 0;
	T3CONbits.TCKPS     = 0;
	TP_TMR3_OVERFLOW    = 0;
	T3CON               = T3CON | 0x8000;
    IEC0bits.IC1IE      = 0;	                           // ��ֹ����1����
    IEC0bits.IC2IE      = 1;
    IEC1bits.IC3IE      = 0;
//  	TP_Switch           = DISABLE; 
	TP_Switch           = TP_SWITCH_ENABLE;
	g_TPDelay           = 0;
	Delay_2MS();	
    IEC0bits.IC1IE      = 0;	                           // ��ֹ����1����
    IEC0bits.IC2IE      = 0;
    IEC1bits.IC3IE      = 0;	
//  	TP_Switch           = ENABLE;
	TP_Switch           = !TP_SWITCH_ENABLE;
	if( g_TPDelay>15000 )
	{
        g_Aarry_TPDelay[2]= 15000;
	}
	else
	{
	    g_Aarry_TPDelay[2]= g_TPDelay;
	}
    g_Aarry_TPDelay[0]  = ( g_Aarry_TPDelay[0]+
		                    g_Aarry_TPDelay[1]+
		                    g_Aarry_TPDelay[2] )/3 - 43;
    if( (int)g_Aarry_TPDelay[0]< 0 )
    {
       g_Aarry_TPDelay[0] = 500;
    }	
	TxWorkCachePack.PACK.uiPackData = g_Aarry_TPDelay[0];  // �����ݽ��и���		
	if( RxWorkCachePack.PACK.ucPackClass != CLASS_TIME )   // �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;	
	}
	T3CON               = T3CON & 0x7FFF;
	TMR3                = 0;
	T3CONbits.TCKPS     = 2;
	TP_TMR3_OVERFLOW    = 0;
	T3CON               = T3CON | 0x8000;	
	IEC0bits.IC1IE      = 1;	                           // ��ֹ����1����
    IEC0bits.IC2IE      = 0;
    IEC1bits.IC3IE      = 1;
	IC2CON              = 0x4000;
    COMUNICATION_OK     = LED_DISABLE;
}
void Project25_Dispose(void)
{
//************�����ü̵���ֵ***********************
	MAINPowerRelay 		= MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= !DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;
	TxWorkCachePack.PACK.uiPackData = 0;                   // �����ݽ��и���		
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_TEMPRT )// �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;	
	}
    COMUNICATION_OK     = LED_DISABLE;
}
void Project26_Dispose(void)
{
//************�����ü̵���ֵ***********************
	MAINPowerRelay 		= MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= !DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;
    Delay_60MS();
    Delay_60MS();
	TxWorkCachePack.PACK.uiPackData = 0;                   // �����ݽ��и���		
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FLAG )// �Ƿ������������� 
	{	
		PACK_PACKAGE_END = FALSE;	
	}
    COMUNICATION_OK     = LED_DISABLE;
}
void Project27_Dispose(void)
{
//************�����ü̵���ֵ***********************
	MAINPowerRelay 		= MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= !DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;
	Delay_60MS();
    Delay_60MS();
	if((str_SCR_Start.Key_State & 0x01)==0)				   // �����ݽ��и���		
	{
		TxWorkCachePack.PACK.uiPackData |= (BIT12);	
	}
	else
	{
		TxWorkCachePack.PACK.uiPackData &= ~(BIT12);	
	} 	
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FLAG )// �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;	
	}
    COMUNICATION_OK     = LED_DISABLE;
}
void Project28_Dispose(void)
{
//************�����ü̵���ֵ***********************
	MAINPowerRelay 		= MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= !DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;
    Delay_60MS();
    Delay_60MS();
	if((!(str_RLed_Start.Key_State & 0x01))&&((str_GLed_Start.Key_State & 0x01)))				   // �����ݽ��и���		
	{
		TxWorkCachePack.PACK.uiPackData |= (BIT14);	
	}
	else
	{
		TxWorkCachePack.PACK.uiPackData &= ~(BIT14);	
	} 	
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FLAG )// �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;
	}	
    COMUNICATION_OK     = LED_DISABLE;
}


void Project29_Dispose(void)
{
//************�����ü̵���ֵ***********************
    IPC0bits.IC1IP      = 7;
    IEC0bits.IC1IE      = 1;	                           // ��ֹ����1����
	T2CON               = T2CON | 0x8000;
	MAINPowerRelay 		= !MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= !MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= !DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;
    Delay_60MS();
    Delay_60MS();
	Delay_60MS();
	TxWorkCachePack.PACK.uiPackData = 230400/g_Frequency;  // �����ݽ��и���		
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FREQUNCY)// �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;
	}	
//************���һ�������֮��,��ʼ��־����,�Դ��´μ��
	TestStart_Flag      = FALSE;
	COMMState_LED       = LED_DISABLE;
	IPC0bits.IC1IP      = 0;	                           // ��ֹ����1����
    IEC0bits.IC1IE      = 0;	                           // ��ֹ����1����
    IEC0bits.IC2IE      = 0;
    IEC1bits.IC3IE      = 1;
    COMUNICATION_OK     = LED_DISABLE;	
}
void Project30_Dispose(void)
{
//************�����ü̵���ֵ***********************

	MAINPowerRelay 		= !MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= !MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= PROTECT_KEY_ENABLE;			
	Discharger_Switch	= !DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;

    Delay_60MS();  	
    Delay_60MS();	

	MAINPowerRelay 		= !MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= !MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;
	
    Delay_60MS();  
    Delay_60MS();
    Delay_60MS();   

	TxWorkCachePack.PACK.uiPackData = 0;                   // �����ݽ��и���		
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FLAG )// �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;
	}	
//************���һ�������֮��,��ʼ��־����,�Դ��´μ��
	TestStart_Flag      = FALSE;
	COMMState_LED       = LED_DISABLE;
    COMUNICATION_OK     = LED_DISABLE;
}
void Project31_Dispose(void)
{
//************�����ü̵���ֵ***********************

	MAINPowerRelay 		= MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= !DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;

	Delay_60MS();
    Delay_60MS();	
	if(check_PhaseMiss())							       // �����ݽ��и���		
	{
		TxWorkCachePack.PACK.uiPackData |= (BIT3);	
	}
	else
	{
		TxWorkCachePack.PACK.uiPackData &= ~(BIT3);	
	}  	
	if( (RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FLAG ) ||(RxWorkCachePack.PACK.ucPackMember!=FLAG_MEMBER_03))  // �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;	
	}
	LOAD_300W			= !LOAD_300W_ENABLE;
    COMUNICATION_OK     = LED_DISABLE;
}

void Project32_Dispose(void)
{

    //************�����ü̵���ֵ***********************

	MAINPowerRelay 		= MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= !DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;
    Delay_60MS();
    Delay_60MS();
	LOAD_Switch         = LOAD_RCD_SWITCH_ENABLE;
    Delay_60MS();
    TxWorkCachePack.PACK.uiPackData = 0;          // �����ݽ��и���
	if( (RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FLAG )||
		(RxWorkCachePack.PACK.ucPackMember!= FLAG_MEMBER_03))         // �Ƿ������������� 
	{
		PACK_PACKAGE_END= FALSE;	
	}
    COMUNICATION_OK     = LED_DISABLE;
}

void Project33_Dispose(void)
{
//************�����ü̵���ֵ***********************

	MAINPowerRelay 		= MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= !MAIN_BUFFER_RLY_ENABLE;
    Delay_60MS();
    Delay_60MS();
	MAINPowerRelay 		= !MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= !MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= !DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;
	Delay_60MS();
    Delay_60MS();

	TxWorkCachePack.PACK.uiPackData = g_uiMCU5Vfilt;       // �����ݽ��и���	
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_VOLTAGE )// �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;
	}

    COMUNICATION_OK     = LED_DISABLE;
}

void Project34_Dispose(void)
{
//************�����ü̵���ֵ***********************
    IPC0bits.IC1IP      = 7;
    IEC0bits.IC1IE      = 1;	                           // ��ֹ����1����
	T2CON               = T2CON | 0x8000;

	MAINPowerRelay 		= !MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= !MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= !DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;

    Delay_60MS();
    Delay_60MS();
	Delay_60MS();
	TxWorkCachePack.PACK.uiPackData = 230400/g_Frequency;  // �����ݽ��и���		
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FREQUNCY)// �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;
	}	
	IPC0bits.IC1IP      = 0;
    IEC0bits.IC1IE      = 0;	                           // ��ֹ����1����
//	TestStart_Flag      = FALSE;
//	COMMState_LED       = LED_DISABLE;
//    IEC0bits.IC1IE      = 0;	                           // ��ֹ����1����
//    IEC0bits.IC2IE      = 0;
//    IEC1bits.IC3IE      = 1;
    COMUNICATION_OK     = LED_DISABLE;	
}



void Project35_Dispose(void)
{
//************�����ü̵���ֵ***********************

	MAINPowerRelay 		= !MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= !MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;

	Delay_60MS();
    Delay_60MS();

	TxWorkCachePack.PACK.uiPackData = g_uiAUXfilt;       // �����ݽ��и���	
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_VOLTAGE )// �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;
	}	
    COMUNICATION_OK     = LED_DISABLE;
}




void Project36_Dispose(void)
{
//************�����ü̵���ֵ***********************

	MAINPowerRelay 		= !MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= !MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= !DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;

	Delay_60MS();
    Delay_60MS();

	TxWorkCachePack.PACK.uiPackData = g_uiAUXfilt;       // �����ݽ��и���	
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_VOLTAGE )// �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;
	}	
    COMUNICATION_OK     = LED_DISABLE;
}

void Project37_Dispose(void)                        //????????��Ҫ��ʱ��?
{

	MAINPowerRelay 		= !MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= !MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= !AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= !AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;

    Delay_60MS();
    Delay_60MS();
    Delay_60MS();
	TxWorkCachePack.PACK.uiPackData = g_uiVBusfilt;        // �����ݽ��и���	
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_VOLTAGE )// �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;
	} 
    COMUNICATION_OK     = LED_DISABLE;
}




void Project38_Dispose(void)
{
//************�����ü̵���ֵ***********************
	MAINPowerRelay 		= MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;	
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= !DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;

    Delay_60MS();
    Delay_60MS();
    Delay_60MS();
	TxWorkCachePack.PACK.uiPackData = g_uiNTCfilt;      // �����ݽ��и���	
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_TEMPRT )// �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;
	}
    COMUNICATION_OK     = LED_DISABLE;
}


void Project39_Dispose(void)
{
//************�����ü̵���ֵ***********************

	MAINPowerRelay 		= !MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= !MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= !AUX_BUFFER_ENABLE;
    Delay_60MS();
	Delay_60MS();
	ASSISTPowerRelay	= AUX_RLY_ENABLE;	
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	

	MCU_Reset			= !MCU_RESET_ENABLE; 						// 0 reset 
	//************�����ü̵���ֵ***********************
	MAINPowerRelay		= MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= !MAIN_BUFFER_RLY_ENABLE;
	//��������̵���֮��,��ʱ60MS�ٿ������绺����
	Delay_60MS();
	Delay_60MS();
	//��������̵���֮��,��ʱ60MS�ٿ������绺����	
	MAINPowerRelay		= MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay	= AUX_BUFFER_ENABLE;
	MCU_Reset			= !MCU_RESET_ENABLE; 		
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch 		= !SAVE_KEY_ENABLE; 		
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= !DISCHARGER_ENABLE;
	LOAD_Switch 		= !LOAD_RCD_SWITCH_ENABLE;								
	TP_Switch			= !TP_SWITCH_ENABLE;	
	Delay_60MS();
	Delay_60MS();
	TxWorkCachePack.PACK.uiPackData = 1;       // �����ݽ��и���	
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FLAG )// �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;
	}	
    COMUNICATION_OK     = LED_DISABLE;
}

void Project40_Dispose(void)
{
	//************�����ü̵���ֵ*********************** 
	MAINPowerRelay		= MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay	= AUX_BUFFER_ENABLE;	
	MCU_Reset			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch 		= !SAVE_KEY_ENABLE; 		
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= !DISCHARGER_ENABLE;
	LOAD_Switch 		= !LOAD_RCD_SWITCH_ENABLE;								
	TP_Switch			= !TP_SWITCH_ENABLE;
	TxWorkCachePack.PACK.uiPackData = 0;				   // �����ݽ��и���		
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_POWER )// �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;
	}
	IEC0bits.IC1IE		= 0;							   // ��ֹ����1����
	IEC0bits.IC2IE		= 1;
	IEC1bits.IC3IE		= 0;
	COMUNICATION_OK 	= LED_DISABLE;

}

void Project41_Dispose(void)
{
    COMUNICATION_OK     = LED_DISABLE;	
    //************�����ü̵���ֵ***********************
	MAINPowerRelay 		= !MAIN_POWER_RLY_ENABLE;
	Delay_60MS();
    Delay_60MS();
	MAINBufferRelay 	= !MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= !AUX_RLY_ENABLE;	
	Delay_60MS();
	ASSISTBufferRelay 	= !AUX_BUFFER_ENABLE;	
	MCU_Reset 			= MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;
    Delay_60MS();
    Delay_60MS();

	TxWorkCachePack.PACK.uiPackData = 1;	
	
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FLAG )// �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;
	}	
}

void Project42_Dispose(void)
{
//************�����ü̵���ֵ***********************

	MAINPowerRelay 		= MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;	
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= !DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;

	TxWorkCachePack.PACK.uiPackData = 0;                   // �����ݽ��и���
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_VERSION )// �Ƿ������������� 
	{	
		PACK_PACKAGE_END= FALSE;	
	}
	COMUNICATION_OK     = LED_DISABLE;
}


void Error_Disprose(void)
{
//************�����ü̵���ֵ***********************

	MAINPowerRelay 		= !MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= !MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= !AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= !AUX_BUFFER_ENABLE;	
	MCU_Reset 			= !MCU_RESET_ENABLE;			
	LOAD_300W			= !LOAD_300W_ENABLE;			
	LOAD_1000W			= !LOAD_1000W_ENABLE;		
	LOAD_RCDA			= !LOAD_RCD_13A;				
	MODE_Switch			= !SAVE_KEY_ENABLE;			
	Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	Protect_Switch		= !PROTECT_KEY_ENABLE;			
	Discharger_Switch	= DISCHARGER_ENABLE;
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	TP_Switch           = !TP_SWITCH_ENABLE;




	PACK_PACKAGE_END    = FALSE;	
//************���һ�������֮��,��ʼ��־����,�Դ��´μ��
	TestStart_Flag      = FALSE;
	COMMState_LED       = LED_DISABLE;
    COMUNICATION_OK     = LED_ENABLE;		
}

/*******************************************************************

    �������ƣ�void Init_SYS_UART_IOPorts(void)
    ��    �ܣ���ϵͳ�����ϵ��ʼ��,���ô�����Ҫ��IO��
              ��ϵͳ���� U1TX,U1RX Ϊ����ͨ�ſڡ�

              RF3    EMUD1/SOSC1/CN1/U1ATX   O   U1ATX
              RF2    EMUC1/SOSCO/CN0/U1ARX   I   U1ARX

    �����������
    �����������
    ������  ����
    �������ߣ���
    ����ֵ  ����
********************************************************************/
void Init_SYS_UART_IOPorts(void)
{
    LATF   = LATF & 0xFFF3;                                // 
    TRISF  = TRISF & 0xFFF7;                               // ���� RF3 Ϊ 0 Ϊ���
    TRISF  = TRISF | 0x0004;                               // ���� RF2 Ϊ 1 Ϊ����
}/*---------------------------���ڳ�ʼ��IO�ڽ���--------------------*/


/*******************************************************************

    �������ƣ�void Init_SYS_UART(void)
    ��    �ܣ��Դ��ڽ��г�ʼ���������첽ȫ˫��ͨ��
              ����������Ϊ 9600
              ��У��
              1Ϊֹͣλ
    �����������
    �����������
    ������  ����
    �������ߣ���
    ����ֵ  ����
********************************************************************/

void Init_SYS_UART(void)
{
     U1MODE          = 0xE000;
     U1STA           = 0x8410;
     U1RXREG         = 0;
     U1TXREG         = 0;
     U1BRG           = CM_BRG;                             // bit 15-0 BRG<15:0>�������ʳ���λ
     IFS0bits.U1RXIF = 0;
     IFS0bits.U1TXIF = 1;  
     IEC0bits.U1RXIE = 0;
     IEC0bits.U1TXIE = 0;       
     IPC2bits.U1RXIP = 0;
     IPC2bits.U1TXIP = 0;     
}

/*******************************************************************

    �������ƣ�_U1RXInterrupt(void)
    ��    �ܣ����ڽ����жϣ�ֻ���գ������жϣ�����һ���ֽ�����
              ��������յ����ݣ����¿�ʼ���ղ����첽ȫ˫��ͨ��
              ����������Ϊ 9600
              ��У��
              1Ϊֹͣλ
    �����������
    �����������
    ������  ����
    �������ߣ���
    ����ֵ  ����
********************************************************************/

void __attribute__((__interrupt__,no_auto_psv)) _U1RXInterrupt(void)
{

     static UInt16 s_uiCacheCount = 0;
     COMUNICATION_OK = COMUNICATION_OK+1;
     IFS0bits.U1RXIF = 0;                                  // ����жϱ�־λ
     U1STAbits.PERR  = 0;                                  // ���У��λ                                            
     if( !(U1STAbits.OERR|U1STAbits.FERR) )                // U1STAbits.PERR
     {
         while(U1STAbits.URXDA)
         {
             g_RxCache[s_uiCacheCount].ay_ucPack[g_uiRxCount] = U1RXREG;
             switch( g_uiRxCount++ )
             {
                case 0 :                                   //head AA
                     if( (g_RxCache[s_uiCacheCount].ay_ucPack[0]) != 0xAA )
                     {
                          g_uiRxCount        = 0;
                          U1STAbits.OERR     = 0;          // ��λ����   
                          g_uiUartDelayCount = 0;
                          UART_DELAY_TIME    = FALSE;
                     } 
                     else
                     {
                          g_uiUartDelayCount = 0;
                          UART_DELAY_TIME    = TRUE;
                     }
                     break;
                case 1 :                                   // head 5
                     if( (g_RxCache[s_uiCacheCount].ay_ucPack[1]) != 0x55 )    
                     {
                          UART_DELAY_TIME    = FALSE;
                          g_uiRxCount        = 0;
                          U1STAbits.OERR     = 0;          // ��λ����
                     }
                case 2 :                                   // CMD
                case 3 :                                   // PROJECT
                case 4 :                                   // CLASS
                case 5 :                                   // COMP
                case 6 :                                   // DATA
                case 7 :                                   // DATA
                case 8 :                                   // CRC
                     g_uiUartDelayCount = 0;
                     break;
                case 9 :
                     g_uiUartDelayCount = 0;
                     s_uiCacheCount     = ((s_uiCacheCount^1)&0x0001);
                     g_uiRxCacheCount   = ((s_uiCacheCount^1)&0x0001);  
                     RX_END             = TRUE;  
                default :  
                     g_uiUartDelayCount = 0;
                     UART_DELAY_TIME    = FALSE;           
                     g_uiRxCount        = 0;
                     U1STAbits.OERR     = 0;               // ��λ����  
                     break;
             }
         }
	}
    else
    {
         g_uiUartDelayCount = 0;
         UART_DELAY_TIME    = FALSE;
         g_uiRxCount        = 0;
         U1STAbits.OERR     = 0;                           // �����
    }
}
/*******************************************************************

    �������ƣ�_U1TXInterrupt(void)
    ��    �ܣ����ڷ����жϣ�ֻ�������ݰ��÷��ͣ�ÿCNST_PACKET_DATA_NUMBER
              ��ô������ݱ����ͣ������첽ȫ˫��ͨ��
              ����������Ϊ 9600
              ��У��
              1Ϊֹͣλ
    �����������
    �����������
    ������  ����
    �������ߣ���
    ����ֵ  ����
********************************************************************/
void __attribute__((interrupt,no_auto_psv)) _U1TXInterrupt(void)
{
     static UInt16 s_uiTxCount = CM_PACKET_DATA_NUMBER;

     IFS0bits.U1TXIF = 0;
                                                           //����жϱ�־λ
     if( TX_START )
     {
         if( s_uiTxCount > CM_PACKET_DATA_NUMBER_LIMET )
         {
             s_uiTxCount = 0;
         }
         while( !U1STAbits.UTXBF )
         {
             U1TXREG = Tx_PACK.ay_ucPack[s_uiTxCount];     //0x55;
             s_uiTxCount++;
             if( s_uiTxCount > CM_PACKET_DATA_NUMBER_LIMET )
             { 
                 TX_START = FALSE;               
                 break;
             }
         }
     }
     else
     {
         s_uiTxCount = CM_PACKET_DATA_NUMBER;
     }
}
/*******************************************************************

    �������ƣ�ReceivePacket(void)
    ��    �ܣ�ֻ����Խ��յ������ݽ�����Ч�Ծ��飬������յ�������λ��Ч
              �ģ���������½������ݻ�����
    �����������
    �����������
    ������  ����
    �������ߣ���
    ����ֵ  ����
********************************************************************/
void ReceivePacket(void)
{
     UInt16 i = 0;
     if( !RX_END )
     {
	 	 return;
	 }
      
     RX_END           = FALSE;
	 TestStart_Flag   = TRUE;                              // ����־��λ,�Ա��ּ��״̬�ڳ���
	 g_COMMStateTimer = 0;                                 // �峬ʱ������
     if( !RX_CACHE_UPDATA )
     {

         for( i = 0; i<CM_PACKET_DATA_NUMBER; i++ )
         {
          	  RxWorkCachePack.ay_ucPack[i] = g_RxCache[g_uiRxCacheCount].ay_ucPack[i];
         }
         if( (RxWorkCachePack.PACK.uiPackHead == CM_PACKET_HEAD) && 
             (RxWorkCachePack.PACK.ucPackCmd  == CM_PACKET_READ) 
		   )
         {
           	 if( RxWorkCachePack.PACK.uiPackVerify == (RxWorkCachePack.PACK.uiPackData +
                                                      (UInt16)RxWorkCachePack.PACK.ucPackMember +
                                                      (UInt16)RxWorkCachePack.PACK.ucPackClass +
                                                      (UInt16)RxWorkCachePack.PACK.ucPackProject) )
             {
                 RX_CACHE_UPDATA = TRUE; 
             }
             else
             {
                 RX_CACHE_UPDATA = FALSE; 
             }
         }
         else
         {
             RX_CACHE_UPDATA = FALSE; 
         }

     }

}
/*******************************************************************

    �������ƣ�void PackingPackage(void)
    ��    �ܣ��Խ��յ����ݽ����ж�������ڽ��յ��������ڣ��������Ӧ��
              ��Ӧ
    �����������
    �����������
    ������  ����
    �������ߣ���
    ����ֵ  ����
********************************************************************/
void PackingPackage(void)
{
	if( !PACK_PACKAGE_END )                                //�������,�򲻻ظ�
	{	
		return;
	}
  //***************************������Ϊͨ�õ�ÿһ֡�����ݸ�ֵ 
    TxWorkCachePack.PACK.ucPackProject = RxWorkCachePack.PACK.ucPackProject;              
	TxWorkCachePack.PACK.ucPackClass   = RxWorkCachePack.PACK.ucPackClass;
	TxWorkCachePack.PACK.ucPackMember  = RxWorkCachePack.PACK.ucPackMember;	
	                                                       //�����Ѿ��ڴ��������渳ֵ��
  	Tx_PACK.PACK.uiPackHead   = CM_PACKET_HEAD;
 	Tx_PACK.PACK.ucPackCmd    = CM_PACKET_ACK;
    Tx_PACK.PACK.ucPackProject= TxWorkCachePack.PACK.ucPackProject;
    Tx_PACK.PACK.ucPackClass  = TxWorkCachePack.PACK.ucPackClass;
    Tx_PACK.PACK.ucPackMember = TxWorkCachePack.PACK.ucPackMember;
    Tx_PACK.PACK.uiPackData   = TxWorkCachePack.PACK.uiPackData;
    Tx_PACK.PACK.uiPackVerify = Tx_PACK.PACK.uiPackData +
                                (UInt16)Tx_PACK.PACK.ucPackMember +
                                (UInt16)Tx_PACK.PACK.ucPackClass + 
                                (UInt16)Tx_PACK.PACK.ucPackProject;    
 
}
/*******************************************************************

    �������ƣ�void SendPacket(void)
    ��    �ܣ��Ի�Ӧ�����ݽ���������Ч�ԵĴ���ʹ���ݰ��������ݸ�ʽ��
              ��Ҫ��
    �����������
    �����������
    ������  ����
    �������ߣ���
    ����ֵ  ����
********************************************************************/
void SendPacket(void)
{
     if( !PACK_PACKAGE_END )
     {		
	 	 return;
	 }
     if( (!TX_START)&U1STAbits.TRMT )                      //
     {
                 
         TX_START         = TRUE;                          // ��������
         IFS0bits.U1TXIF  = TRUE; 
         PACK_PACKAGE_END = FALSE;
     }
}

void ReceiveData_Dispose(void)
{
	UInt8	Temp_Id = 0;
	UartData_Dispose_INFO * Temp_point;

	if( !RX_CACHE_UPDATA )
	{	
		return;	                                           // ���û�����һ֡���ݵ�ȷ��,���˳�
	}
	
	PACK_PACKAGE_END = TRUE;                               // ���ó�ֵΪ��.	
	Temp_Id          = RxWorkCachePack.PACK.ucPackProject;
	Temp_point       = uartdata_info;                      // ������ָ���ֵ
	//�˴�һ��Ҫ�ȼ���Ƿ��������յ�һ֡����,�����Ƿ���Ч.
	while( Temp_point->TestProject_ID != NO_PROJECT_ID )   // ���������ǰ�ļ����Ŀ��Ź���
	{
		if( Temp_point->TestProject_ID == Temp_Id )
		{	
			break;
		}
		else
	    {
			Temp_point++;
		}
	}
	(* Temp_point->Data_Dispose )();                       // ִ�е�ǰ�ļ����Ŀ��Ź���
	PackingPackage();
	RX_CACHE_UPDATA = FALSE;
}
void StartTest(void)
{
	if(key_Start.Key_State==KEY_ON)
	{
		key_Start.Key_State = KEY_OFF;
		COMMState_LED       = LED_ENABLE;                  // ��
        COMUNICATION_OK     = LED_DISABLE;                 // ��		
		if( TestStart_Flag )
		{	
			return;
		}
		TestStart_Flag      = TRUE; 


	    MAINPowerRelay 		= !MAIN_POWER_RLY_ENABLE;
	    MAINBufferRelay 	= !MAIN_BUFFER_RLY_ENABLE;
	    ASSISTPowerRelay	= !AUX_RLY_ENABLE;	
	    ASSISTBufferRelay 	= !AUX_BUFFER_ENABLE;	
	    MCU_Reset 			= MCU_RESET_ENABLE;			
	    LOAD_300W			= !LOAD_300W_ENABLE;			
	    LOAD_1000W			= !LOAD_1000W_ENABLE;		
	    LOAD_RCDA			= !LOAD_RCD_13A;				
	    MODE_Switch			= !SAVE_KEY_ENABLE;			
	    Temperature_Switch	= !TEMPT_PROTECT_ENABLE;		
	    Protect_Switch		= !PROTECT_KEY_ENABLE;			
	    Discharger_Switch	= DISCHARGER_ENABLE;
    	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;                           	
	    TP_Switch           = !TP_SWITCH_ENABLE;
                       

		//*****��ֵ,׼�����͵�һ֡����
  		Tx_PACK.PACK.uiPackHead   = CM_PACKET_HEAD;
 		Tx_PACK.PACK.ucPackCmd    = CM_PACKET_ACK;
       	Tx_PACK.PACK.ucPackProject= 0x01;
       	Tx_PACK.PACK.ucPackClass  = CM_CLASS_FLAG;
       	Tx_PACK.PACK.ucPackMember = FLAG_MEMBER_03;
     	Tx_PACK.PACK.uiPackData   = START_FLAG_DATA;	
     	Tx_PACK.PACK.uiPackVerify = Tx_PACK.PACK.uiPackData +
                                    (UInt16)Tx_PACK.PACK.ucPackMember +
                                    (UInt16)Tx_PACK.PACK.ucPackClass + 
                                    (UInt16)Tx_PACK.PACK.ucPackProject;    
 		PACK_PACKAGE_END          = TRUE;                  // ��λ����֡�����ɱ�־
		
	}
}
UInt8 check_PhaseMiss(void)
{
	UInt16 TempErr1,TempErr2,TempErr3;
	if( g_uiAPhasefilt >= g_uiBPhasefilt )
	{
		TempErr1 = g_uiAPhasefilt-g_uiBPhasefilt;
	}
	else
	{
		TempErr1 = g_uiBPhasefilt-g_uiAPhasefilt;
	}
	if( g_uiAPhasefilt >= g_uiCPhasefilt )
	{
		TempErr2 = g_uiAPhasefilt-g_uiCPhasefilt;
	}
	else
	{
		TempErr2 = g_uiCPhasefilt-g_uiAPhasefilt;
	}	
	if( g_uiBPhasefilt >= g_uiCPhasefilt )
	{
		TempErr3 = g_uiBPhasefilt-g_uiCPhasefilt;
	}
	else
	{
		TempErr3 = g_uiCPhasefilt-g_uiBPhasefilt;
	
	}	
	if((TempErr3 >= MissPhaseErr)||(TempErr2 >= MissPhaseErr)||(TempErr1 >= MissPhaseErr))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}



void Delay_60MS(void)
{
	WAIT_AdUpdateStart  = TRUE;
	while(!WAIT_AdUpdateEnd)                               // ��ѭ���ȴ���ʱʱ�䵽,�ٻ�ȡADֵ
		;
	WAIT_AdUpdateStart  = FALSE;                           // ��ʱ������ֹͣ
	WAIT_AdUpdateEnd    = FALSE;  
}
void Delay_2MS(void)
{
	WAIT_2MS_Start  = TRUE;
	while(!WAIT_2MS_End)                                   // ��ѭ���ȴ���ʱʱ�䵽,�ٻ�ȡADֵ
		;
	WAIT_2MS_Start  = FALSE;                               // ��ʱ������ֹͣ
	WAIT_2MS_End    = FALSE;  
}
void Delay_5MS(void)
{
	WAIT_5MS_Start  = TRUE;
	while(!WAIT_5MS_End)                                   // ��ѭ���ȴ���ʱʱ�䵽,�ٻ�ȡADֵ
		;
	WAIT_5MS_Start  = FALSE;                               // ��ʱ������ֹͣ
	WAIT_5MS_End    = FALSE;  
}


