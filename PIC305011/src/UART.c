
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
    //************首先置继电器值***********************
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
	if(!(str_Machine_Start.Key_State & 0x01))			   // 对数据进行更新		
	{
		TxWorkCachePack.PACK.uiPackData &= ~(BIT0);	
//		TxWorkCachePack.PACK.uiPackData = 1;		
	}
	else
	{
		TxWorkCachePack.PACK.uiPackData |= (BIT0);
//		TxWorkCachePack.PACK.uiPackData = 1;		
	}
	
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FLAG )// 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;
	}	
}

void Project02_Dispose(void)
{
//************首先置继电器值***********************

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

	TxWorkCachePack.PACK.uiPackData = 0;                   // 对数据进行更新
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_VERSION )// 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;	
	}
	COMUNICATION_OK     = LED_DISABLE;
}

void Project03_Dispose(void)
{
//************首先置继电器值***********************

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
	TxWorkCachePack.PACK.uiPackData = g_uiMCUBusfilt;      // 对数据进行更新
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_VOLTAGE )// 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;
	}
    COMUNICATION_OK     = LED_DISABLE;
}

void Project04_Dispose(void)
{
//************首先置继电器值***********************

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
	TxWorkCachePack.PACK.uiPackData = g_uiOutVoltagefilt;  // 对数据进行更新
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_VOLTAGE )// 是否进入自身处理进程  
	{	
		PACK_PACKAGE_END= FALSE;
	}
    COMUNICATION_OK     = LED_DISABLE;
}

void Project05_Dispose(void)
{
//************首先置继电器值***********************
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
	TxWorkCachePack.PACK.uiPackData = g_uiOutCurrentfilt;  // 对数据进行更新	
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_CURRENT)// 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;
	}
    COMUNICATION_OK     = LED_DISABLE;
}
void Project06_Dispose(void)
{
//************首先置继电器值***********************
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
    	TxWorkCachePack.PACK.uiPackData = g_uiTemprtfilt;      // 对数据进行更新   
    }
    else if( RxWorkCachePack.PACK.ucPackMember == 2 )
    {
	    TxWorkCachePack.PACK.uiPackData = g_uiNTCfilt;      // 对数据进行更新       
    }
	
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_TEMPRT )// 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;
	}
    COMUNICATION_OK     = LED_DISABLE;
}
void Project07_Dispose(void)
{
//************首先置继电器值***********************

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

	TxWorkCachePack.PACK.uiPackData = g_uiMCU5Vfilt;       // 对数据进行更新	
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_VOLTAGE )// 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;
	}	
    COMUNICATION_OK     = LED_DISABLE;
}
void Project08_Dispose(void)
{
//************首先置继电器值***********************
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
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_VOLTAGE)// 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;
	}
	if( RxWorkCachePack.PACK.ucPackMember ==0X0E )         // 第一路15V
	{
TxWorkCachePack.PACK.uiPackData = g_uiINV15V1filt;
//		TxWorkCachePack.PACK.uiPackData = (g_Aarry_of_INV15V1[0]  
//			                              +g_Aarry_of_INV15V1[1]  
//			                              +g_Aarry_of_INV15V1[2]  
//			                              +g_Aarry_of_INV15V1[3])>>2; // 对数据进行更新
	}
	else if( RxWorkCachePack.PACK.ucPackMember ==0X0F )
	{	
//		TxWorkCachePack.PACK.uiPackData =  (g_Aarry_of_INV15V2[0]  
//			                              +g_Aarry_of_INV15V2[1]  
//			                              +g_Aarry_of_INV15V2[2]  
//			                              +g_Aarry_of_INV15V2[3])>>2; // 对数据进行更新
TxWorkCachePack.PACK.uiPackData = g_uiINV15V2filt;
	}
	else
	{
		PACK_PACKAGE_END = FALSE;
	}

    COMUNICATION_OK     = LED_DISABLE;	

}
void Project09_Dispose(void)                        //????????需要延时吗?
{
	MCU_Reset 			= MCU_RESET_ENABLE;                         // 0 reset 
//************首先置继电器值***********************
	MAINPowerRelay 		= MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= !MAIN_BUFFER_RLY_ENABLE;
	//开启主电继电器之后,延时60MS再开启主电缓冲器
    Delay_60MS();
    Delay_60MS();
	//开启主电继电器之后,延时60MS再开启主电缓冲器	
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
	TxWorkCachePack.PACK.uiPackData = g_uiVBusfilt;        // 对数据进行更新	
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_VOLTAGE )// 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;
	}
	MCU_Reset 			= !MCU_RESET_ENABLE; 
    COMUNICATION_OK     = LED_DISABLE;
}
void Project10_Dispose(void)
{
//************首先置继电器值***********************

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


	TxWorkCachePack.PACK.uiPackData = 0;                   // 对数据进行更新	
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_VOLTAGE )// 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;	
	}
    COMUNICATION_OK     = LED_DISABLE;
}
void Project11_Dispose(void)
{
//************首先置继电器值***********************
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
	TxWorkCachePack.PACK.uiPackData = 230400/g_OutFrequency;   // 对数据进行更新	
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FREQUNCY )// 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;	
	}
    COMUNICATION_OK     = LED_DISABLE;
}
void Project12_Dispose(void)
{
//************首先置继电器值***********************
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
	TxWorkCachePack.PACK.uiPackData = 0;                   // 对数据进行更新		
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_CURRENT )// 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;
	}
    COMUNICATION_OK     = LED_DISABLE;
}
void Project13_Dispose(void)
{
//************首先置继电器值***********************
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
	TxWorkCachePack.PACK.uiPackData = 0;                   // 对数据进行更新		
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_POWER )// 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;	
	}
    COMUNICATION_OK     = LED_DISABLE;
}

void Project14_Dispose(void)
{
//************首先置继电器值***********************
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
	if((str_RLed_Start.Key_State & 0x01)&&(!(str_GLed_Start.Key_State & 0x01)))				   // 对数据进行更新		
	{
		TxWorkCachePack.PACK.uiPackData |= (BIT13);	
	}
	else
	{
		TxWorkCachePack.PACK.uiPackData &= ~(BIT13);	
	}  
	if(( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FLAG )||(RxWorkCachePack.PACK.ucPackMember!=FLAG_MEMBER_03))   // 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;		
	}
    COMUNICATION_OK     = LED_DISABLE;
}
void Project15_Dispose(void)                        // 待改
{
//************首先置继电器值***********************
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
	if((g_StepPosition>>1)&1)							   // 对数据进行更新		
	{
		TxWorkCachePack.PACK.uiPackData |= (BIT1);	
	}
	else
	{
		TxWorkCachePack.PACK.uiPackData &= ~(BIT1);	
	}  
//	*/
	if( (RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FLAG ) ||(RxWorkCachePack.PACK.ucPackMember!=FLAG_MEMBER_03))  // 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;	
	}
    COMUNICATION_OK     = LED_DISABLE;
}
void Project16_Dispose(void)
{
//************首先置继电器值***********************

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
	if(check_PhaseMiss())							       // 对数据进行更新		
	{
		TxWorkCachePack.PACK.uiPackData |= (BIT3);	
	}
	else
	{
		TxWorkCachePack.PACK.uiPackData &= ~(BIT3);	
	}  	
	if( (RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FLAG ) ||(RxWorkCachePack.PACK.ucPackMember!=FLAG_MEMBER_03))  // 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;	
	}
    COMUNICATION_OK     = LED_DISABLE;

}



void Project17_Dispose(void)
{
//************首先置继电器值***********************
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
	TxWorkCachePack.PACK.uiPackData = 0;                   // 对数据进行更新		
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_VOLTAGE )// 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;	 
	}
    COMUNICATION_OK     = LED_DISABLE;
}
void Project18_Dispose(void)
{
//************首先置继电器值***********************
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
	TxWorkCachePack.PACK.uiPackData = 0;                   // 对数据进行更新		
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_CURRENT )// 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;	
	}
    COMUNICATION_OK     = LED_DISABLE;
}
void Project19_Dispose(void)
{
//************首先置继电器值***********************
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
	TxWorkCachePack.PACK.uiPackData = 230400/g_OutFrequency;  // 对数据进行更新		
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FREQUNCY )// 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;	
	}

    IEC0bits.IC1IE      = 0;	                           // 禁止捕获1运行
    IEC0bits.IC2IE      = 1;
    IEC1bits.IC3IE      = 0;
    COMUNICATION_OK     = LED_DISABLE;
	
}
void Project20_Dispose(void)
{
//************首先置继电器值***********************	
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
	TxWorkCachePack.PACK.uiPackData = 0;                   // 对数据进行更新		
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_POWER )// 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;
	}
    IEC0bits.IC1IE      = 0;	                           // 禁止捕获1运行
    IEC0bits.IC2IE      = 1;
    IEC1bits.IC3IE      = 0;
    COMUNICATION_OK     = LED_DISABLE;
}
void Project21_Dispose(void)
{
//************首先置继电器值***********************
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
	if((g_StepPosition>>2)&1)							   // 对数据进行更新		
	{
		TxWorkCachePack.PACK.uiPackData |= (BIT2);	
	}
	else
	{
		TxWorkCachePack.PACK.uiPackData &= ~(BIT2);	
	}  	
	if( (RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FLAG ) ||(RxWorkCachePack.PACK.ucPackMember!=FLAG_MEMBER_03))  // 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;	
	}
	LOAD_1000W			= !LOAD_1000W_ENABLE;
    COMUNICATION_OK     = LED_DISABLE;
}
void Project22_Dispose(void)
{

//************首先置继电器值***********************
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
	TxWorkCachePack.PACK.uiPackData = 0;                   // 对数据进行更新		
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FLAG )// 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;	
	}
	IEC0bits.IC1IE      = 0;	                           // 禁止捕获1运行
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
    IEC0bits.IC1IE      = 0;	                           // 禁止捕获1运行
    IEC0bits.IC2IE      = 0;
    IEC1bits.IC3IE      = 1;
	IFS1bits.IC3IF      = 0;
    IPC7bits.IC3IP      = 6;
    T5CON               = 0x0000; 
    TMR5                = 0x0000;
    uiTemp1             = RxWorkCachePack.PACK.uiPackData;
	if( RxWorkCachePack.PACK.ucPackMember == FLAG_MEMBER_03 )	  // 是否进入自身处理进程 
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
			TxWorkCachePack.PACK.uiPackData &= ~BIT4;		   // 对数据进行更新
            TxWorkCachePack.PACK.ucPackMember = FLAG_MEMBER_03;
		    LOAD_Switch 		= !LOAD_RCD_SWITCH_ENABLE; 
		    LOAD_RCDA			= !LOAD_RCD_13A;	
		    T5CON				= 0x0000;
		    T3CON				= T3CON & 0x7FFF;
		    TMR3				= 0;
		    T3CONbits.TCKPS 	= 2;
		    TP_TMR3_OVERFLOW	= 0;
		    T3CON				= T3CON | 0x8000;		
		    IEC0bits.IC1IE		= 1;							   // 禁止捕获1运行
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
			TxWorkCachePack.PACK.uiPackData &= ~BIT4;		   // 对数据进行更新
            TxWorkCachePack.PACK.ucPackMember = FLAG_MEMBER_03;

		    LOAD_Switch 		= !LOAD_RCD_SWITCH_ENABLE; 
		    LOAD_RCDA			= !LOAD_RCD_13A;	
		    T5CON				= 0x0000;
		    T3CON				= T3CON & 0x7FFF;
		    TMR3				= 0;
		    T3CONbits.TCKPS 	= 2;
		    TP_TMR3_OVERFLOW	= 0;
		    T3CON				= T3CON | 0x8000;		
		    IEC0bits.IC1IE		= 1;							   // 禁止捕获1运行
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
	IPC5bits.T5IP       = 7;                               // 定时器5中断优先级0
    IFS1bits.T5IF       = 0;                               // 定时器5中断标志位清0
    IEC1bits.T5IE       = 1;                               // 定时器5中断使能0
    //************首先置继电器值***********************

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
	    while(!WAIT_AdUpdateEnd)                               // 死循环等待延时时间到,再获取AD值
	    {	
            if( (g_Wait_TP_T5  == 0x00)&&(g_Wait_TP_IC3  == 0x00) )
            {
                break;
            }
	    }
	    WAIT_AdUpdateStart  = FALSE;                           // 延时计数器停止
	    WAIT_AdUpdateEnd    = FALSE;  
	    Delay_5MS();
	    LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE;  
	    IEC0bits.IC1IE      = 0;	                           // 禁止捕获1运行
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
        IEC0bits.IC1IE      = 1;	                       // 禁止捕获1运行
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

		
		TxWorkCachePack.PACK.uiPackData &= ~BIT4;          // 对数据进行更新
//TxWorkCachePack.PACK.uiPackData = 0xFFFF;
	    if( (RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FLAG )||
		    (RxWorkCachePack.PACK.ucPackMember!= FLAG_MEMBER_03))     // 是否进入自身处理进程 
	    {
		     PACK_PACKAGE_END = FALSE;	
	    }
		PR5 		        = 0;
//		TxWorkCachePack.PACK.uiPackData &= ~BIT4;		   // 对数据进行更新
		LOAD_Switch 		= !LOAD_RCD_SWITCH_ENABLE; 
		LOAD_RCDA			= !LOAD_RCD_13A;	
		T5CON				= 0x0000;
		T3CON				= T3CON & 0x7FFF;
		TMR3				= 0;
		T3CONbits.TCKPS 	= 2;
		TP_TMR3_OVERFLOW	= 0;
		T3CON				= T3CON | 0x8000;		
		IEC0bits.IC1IE		= 1;							   // 禁止捕获1运行
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
	IEC0bits.IC1IE      = 0;	                           // 禁止捕获1运行
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
        IEC0bits.IC1IE      = 0;	                       // 禁止捕获1运行
        IEC0bits.IC2IE      = 0;
        IEC1bits.IC3IE      = 1;
	    IFS1bits.IC3IF      = 0;
        IPC7bits.IC3IP      = 6;
        T5CON               = 0x0000; 
        TMR5                = 0x0000;
        PR5                 = PR5_Temp;  
        T5CONbits.TCKPS     = 1; 
	    IPC5bits.T5IP       = 7;                           // 定时器5中断优先级0
        IFS1bits.T5IF       = 0;                           // 定时器5中断标志位清0
        IEC1bits.T5IE       = 1;                           // 定时器5中断使能0
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
	        while(!WAIT_AdUpdateEnd)                               // 死循环等待延时时间到,再获取AD值
	        {	
                if( (g_Wait_TP_T5  == 0x00)&&(g_Wait_TP_IC3  == 0x00) )
                {
                    break;
                }  
	        }
	        WAIT_AdUpdateStart  = FALSE;                           // 延时计数器停止
	        WAIT_AdUpdateEnd    = FALSE;  
		    Delay_5MS();
	        LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE; 
	        IEC0bits.IC1IE      = 0;	                           // 禁止捕获1运行
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
 	        TxWorkCachePack.PACK.uiPackData |= BIT4;       // 对数据进行更新              
	    }
		else
		{
//TxWorkCachePack.PACK.uiPackData = 0xFFF3;	
//TxWorkCachePack.PACK.uiPackData = g_TP_Load[0];			
            TxWorkCachePack.PACK.uiPackData &= ~BIT4;      // 对数据进行更新
		}
	}
    else
    {
//TxWorkCachePack.PACK.uiPackData = g_TP_Load[0];
//TxWorkCachePack.PACK.uiPackData = 0xFFF3;		
        TxWorkCachePack.PACK.uiPackData &= ~BIT4;          // 对数据进行更新
	}
	LOAD_Switch         = !LOAD_RCD_SWITCH_ENABLE; 
	LOAD_RCDA			= !LOAD_RCD_13A;	
    T5CON               = 0x0000;
	T3CON               = T3CON & 0x7FFF;
	TMR3                = 0;
	T3CONbits.TCKPS     = 2;
	TP_TMR3_OVERFLOW    = 0;
	T3CON               = T3CON | 0x8000;		
    IEC0bits.IC1IE      = 1;	                           // 禁止捕获1运行
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
		(RxWorkCachePack.PACK.ucPackMember!= FLAG_MEMBER_03))         // 是否进入自身处理进程 
	{
		PACK_PACKAGE_END= FALSE;	
	}
    COMUNICATION_OK     = LED_DISABLE;
}
void Project24_Dispose(void)
{
//************首先置继电器值***********************

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
    IEC0bits.IC1IE      = 0;	                           // 禁止捕获1运行
    IEC0bits.IC2IE      = 0;
    IEC1bits.IC3IE      = 0;
	Delay_2MS();
	T3CON               = T3CON & 0x7FFF;
	TMR3                = 0;
	T3CONbits.TCKPS     = 0;
	TP_TMR3_OVERFLOW    = 0;
	T3CON               = T3CON | 0x8000;
	IEC0bits.IC1IE      = 0;	                           // 禁止捕获1运行
    IEC0bits.IC2IE      = 1;
    IEC1bits.IC3IE      = 0;
//  	TP_Switch           = DISABLE;
	TP_Switch           = TP_SWITCH_ENABLE;
	g_TPDelay           = 0;
	Delay_2MS();
    IEC0bits.IC1IE      = 0;	                           // 禁止捕获1运行
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
    IEC0bits.IC1IE      = 0;	                           // 禁止捕获1运行
    IEC0bits.IC2IE      = 1;
    IEC1bits.IC3IE      = 0;
//  	TP_Switch           = DISABLE; 
	TP_Switch           = TP_SWITCH_ENABLE;
	g_TPDelay           = 0;
	Delay_2MS();	
    IEC0bits.IC1IE      = 0;	                           // 禁止捕获1运行
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
    IEC0bits.IC1IE      = 0;	                           // 禁止捕获1运行
    IEC0bits.IC2IE      = 1;
    IEC1bits.IC3IE      = 0;
//  	TP_Switch           = DISABLE; 
	TP_Switch           = TP_SWITCH_ENABLE;
	g_TPDelay           = 0;
	Delay_2MS();	
    IEC0bits.IC1IE      = 0;	                           // 禁止捕获1运行
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
	TxWorkCachePack.PACK.uiPackData = g_Aarry_TPDelay[0];  // 对数据进行更新		
	if( RxWorkCachePack.PACK.ucPackClass != CLASS_TIME )   // 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;	
	}
	T3CON               = T3CON & 0x7FFF;
	TMR3                = 0;
	T3CONbits.TCKPS     = 2;
	TP_TMR3_OVERFLOW    = 0;
	T3CON               = T3CON | 0x8000;	
	IEC0bits.IC1IE      = 1;	                           // 禁止捕获1运行
    IEC0bits.IC2IE      = 0;
    IEC1bits.IC3IE      = 1;
	IC2CON              = 0x4000;
    COMUNICATION_OK     = LED_DISABLE;
}
void Project25_Dispose(void)
{
//************首先置继电器值***********************
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
	TxWorkCachePack.PACK.uiPackData = 0;                   // 对数据进行更新		
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_TEMPRT )// 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;	
	}
    COMUNICATION_OK     = LED_DISABLE;
}
void Project26_Dispose(void)
{
//************首先置继电器值***********************
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
	TxWorkCachePack.PACK.uiPackData = 0;                   // 对数据进行更新		
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FLAG )// 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END = FALSE;	
	}
    COMUNICATION_OK     = LED_DISABLE;
}
void Project27_Dispose(void)
{
//************首先置继电器值***********************
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
	if((str_SCR_Start.Key_State & 0x01)==0)				   // 对数据进行更新		
	{
		TxWorkCachePack.PACK.uiPackData |= (BIT12);	
	}
	else
	{
		TxWorkCachePack.PACK.uiPackData &= ~(BIT12);	
	} 	
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FLAG )// 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;	
	}
    COMUNICATION_OK     = LED_DISABLE;
}
void Project28_Dispose(void)
{
//************首先置继电器值***********************
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
	if((!(str_RLed_Start.Key_State & 0x01))&&((str_GLed_Start.Key_State & 0x01)))				   // 对数据进行更新		
	{
		TxWorkCachePack.PACK.uiPackData |= (BIT14);	
	}
	else
	{
		TxWorkCachePack.PACK.uiPackData &= ~(BIT14);	
	} 	
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FLAG )// 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;
	}	
    COMUNICATION_OK     = LED_DISABLE;
}


void Project29_Dispose(void)
{
//************首先置继电器值***********************
    IPC0bits.IC1IP      = 7;
    IEC0bits.IC1IE      = 1;	                           // 禁止捕获1运行
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
	TxWorkCachePack.PACK.uiPackData = 230400/g_Frequency;  // 对数据进行更新		
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FREQUNCY)// 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;
	}	
//************最后一项检测完成之后,开始标志清零,以待下次检测
	TestStart_Flag      = FALSE;
	COMMState_LED       = LED_DISABLE;
	IPC0bits.IC1IP      = 0;	                           // 禁止捕获1运行
    IEC0bits.IC1IE      = 0;	                           // 禁止捕获1运行
    IEC0bits.IC2IE      = 0;
    IEC1bits.IC3IE      = 1;
    COMUNICATION_OK     = LED_DISABLE;	
}
void Project30_Dispose(void)
{
//************首先置继电器值***********************

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

	TxWorkCachePack.PACK.uiPackData = 0;                   // 对数据进行更新		
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FLAG )// 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;
	}	
//************最后一项检测完成之后,开始标志清零,以待下次检测
	TestStart_Flag      = FALSE;
	COMMState_LED       = LED_DISABLE;
    COMUNICATION_OK     = LED_DISABLE;
}
void Project31_Dispose(void)
{
//************首先置继电器值***********************

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
	if(check_PhaseMiss())							       // 对数据进行更新		
	{
		TxWorkCachePack.PACK.uiPackData |= (BIT3);	
	}
	else
	{
		TxWorkCachePack.PACK.uiPackData &= ~(BIT3);	
	}  	
	if( (RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FLAG ) ||(RxWorkCachePack.PACK.ucPackMember!=FLAG_MEMBER_03))  // 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;	
	}
	LOAD_300W			= !LOAD_300W_ENABLE;
    COMUNICATION_OK     = LED_DISABLE;
}

void Project32_Dispose(void)
{

    //************首先置继电器值***********************

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
    TxWorkCachePack.PACK.uiPackData = 0;          // 对数据进行更新
	if( (RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FLAG )||
		(RxWorkCachePack.PACK.ucPackMember!= FLAG_MEMBER_03))         // 是否进入自身处理进程 
	{
		PACK_PACKAGE_END= FALSE;	
	}
    COMUNICATION_OK     = LED_DISABLE;
}

void Project33_Dispose(void)
{
//************首先置继电器值***********************

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

	TxWorkCachePack.PACK.uiPackData = g_uiMCU5Vfilt;       // 对数据进行更新	
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_VOLTAGE )// 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;
	}

    COMUNICATION_OK     = LED_DISABLE;
}

void Project34_Dispose(void)
{
//************首先置继电器值***********************
    IPC0bits.IC1IP      = 7;
    IEC0bits.IC1IE      = 1;	                           // 禁止捕获1运行
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
	TxWorkCachePack.PACK.uiPackData = 230400/g_Frequency;  // 对数据进行更新		
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FREQUNCY)// 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;
	}	
	IPC0bits.IC1IP      = 0;
    IEC0bits.IC1IE      = 0;	                           // 禁止捕获1运行
//	TestStart_Flag      = FALSE;
//	COMMState_LED       = LED_DISABLE;
//    IEC0bits.IC1IE      = 0;	                           // 禁止捕获1运行
//    IEC0bits.IC2IE      = 0;
//    IEC1bits.IC3IE      = 1;
    COMUNICATION_OK     = LED_DISABLE;	
}



void Project35_Dispose(void)
{
//************首先置继电器值***********************

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

	TxWorkCachePack.PACK.uiPackData = g_uiAUXfilt;       // 对数据进行更新	
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_VOLTAGE )// 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;
	}	
    COMUNICATION_OK     = LED_DISABLE;
}




void Project36_Dispose(void)
{
//************首先置继电器值***********************

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

	TxWorkCachePack.PACK.uiPackData = g_uiAUXfilt;       // 对数据进行更新	
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_VOLTAGE )// 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;
	}	
    COMUNICATION_OK     = LED_DISABLE;
}

void Project37_Dispose(void)                        //????????需要延时吗?
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
	TxWorkCachePack.PACK.uiPackData = g_uiVBusfilt;        // 对数据进行更新	
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_VOLTAGE )// 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;
	} 
    COMUNICATION_OK     = LED_DISABLE;
}




void Project38_Dispose(void)
{
//************首先置继电器值***********************
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
	TxWorkCachePack.PACK.uiPackData = g_uiNTCfilt;      // 对数据进行更新	
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_TEMPRT )// 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;
	}
    COMUNICATION_OK     = LED_DISABLE;
}


void Project39_Dispose(void)
{
//************首先置继电器值***********************

	MAINPowerRelay 		= !MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= !MAIN_BUFFER_RLY_ENABLE;
	ASSISTPowerRelay	= AUX_RLY_ENABLE;
	ASSISTBufferRelay 	= !AUX_BUFFER_ENABLE;
    Delay_60MS();
	Delay_60MS();
	ASSISTPowerRelay	= AUX_RLY_ENABLE;	
	ASSISTBufferRelay 	= AUX_BUFFER_ENABLE;	

	MCU_Reset			= !MCU_RESET_ENABLE; 						// 0 reset 
	//************首先置继电器值***********************
	MAINPowerRelay		= MAIN_POWER_RLY_ENABLE;
	MAINBufferRelay 	= !MAIN_BUFFER_RLY_ENABLE;
	//开启主电继电器之后,延时60MS再开启主电缓冲器
	Delay_60MS();
	Delay_60MS();
	//开启主电继电器之后,延时60MS再开启主电缓冲器	
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
	TxWorkCachePack.PACK.uiPackData = 1;       // 对数据进行更新	
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FLAG )// 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;
	}	
    COMUNICATION_OK     = LED_DISABLE;
}

void Project40_Dispose(void)
{
	//************首先置继电器值*********************** 
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
	TxWorkCachePack.PACK.uiPackData = 0;				   // 对数据进行更新		
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_POWER )// 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;
	}
	IEC0bits.IC1IE		= 0;							   // 禁止捕获1运行
	IEC0bits.IC2IE		= 1;
	IEC1bits.IC3IE		= 0;
	COMUNICATION_OK 	= LED_DISABLE;

}

void Project41_Dispose(void)
{
    COMUNICATION_OK     = LED_DISABLE;	
    //************首先置继电器值***********************
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
	
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_FLAG )// 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;
	}	
}

void Project42_Dispose(void)
{
//************首先置继电器值***********************

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

	TxWorkCachePack.PACK.uiPackData = 0;                   // 对数据进行更新
	if( RxWorkCachePack.PACK.ucPackClass != CM_CLASS_VERSION )// 是否进入自身处理进程 
	{	
		PACK_PACKAGE_END= FALSE;	
	}
	COMUNICATION_OK     = LED_DISABLE;
}


void Error_Disprose(void)
{
//************首先置继电器值***********************

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
//************最后一项检测完成之后,开始标志清零,以待下次检测
	TestStart_Flag      = FALSE;
	COMMState_LED       = LED_DISABLE;
    COMUNICATION_OK     = LED_ENABLE;		
}

/*******************************************************************

    函数名称：void Init_SYS_UART_IOPorts(void)
    功    能：对系统进行上电初始化,配置串口需要的IO口
              本系统采用 U1TX,U1RX 为串口通信口。

              RF3    EMUD1/SOSC1/CN1/U1ATX   O   U1ATX
              RF2    EMUC1/SOSCO/CN0/U1ARX   I   U1ARX

    输入参数：无
    输出参数：无
    调用者  ：无
    被调用者：无
    返回值  ：无
********************************************************************/
void Init_SYS_UART_IOPorts(void)
{
    LATF   = LATF & 0xFFF3;                                // 
    TRISF  = TRISF & 0xFFF7;                               // 设置 RF3 为 0 为输出
    TRISF  = TRISF | 0x0004;                               // 设置 RF2 为 1 为输入
}/*---------------------------串口初始化IO口结束--------------------*/


/*******************************************************************

    函数名称：void Init_SYS_UART(void)
    功    能：对串口进行初始化，采用异步全双工通信
              波特率设置为 9600
              无校验
              1为停止位
    输入参数：无
    输出参数：无
    调用者  ：无
    被调用者：无
    返回值  ：无
********************************************************************/

void Init_SYS_UART(void)
{
     U1MODE          = 0xE000;
     U1STA           = 0x8410;
     U1RXREG         = 0;
     U1TXREG         = 0;
     U1BRG           = CM_BRG;                             // bit 15-0 BRG<15:0>：波特率除数位
     IFS0bits.U1RXIF = 0;
     IFS0bits.U1TXIF = 1;  
     IEC0bits.U1RXIE = 0;
     IEC0bits.U1TXIE = 0;       
     IPC2bits.U1RXIP = 0;
     IPC2bits.U1TXIP = 0;     
}

/*******************************************************************

    函数名称：_U1RXInterrupt(void)
    功    能：串口接收中断，只接收，不错判断，当第一个字节有误
              则放弃接收的数据，重新开始接收采用异步全双工通信
              波特率设置为 9600
              无校验
              1为停止位
    输入参数：无
    输出参数：无
    调用者  ：无
    被调用者：无
    返回值  ：无
********************************************************************/

void __attribute__((__interrupt__,no_auto_psv)) _U1RXInterrupt(void)
{

     static UInt16 s_uiCacheCount = 0;
     COMUNICATION_OK = COMUNICATION_OK+1;
     IFS0bits.U1RXIF = 0;                                  // 清除中断标志位
     U1STAbits.PERR  = 0;                                  // 清除校验位                                            
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
                          U1STAbits.OERR     = 0;          // 复位接收   
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
                          U1STAbits.OERR     = 0;          // 复位接收
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
                     U1STAbits.OERR     = 0;               // 复位接收  
                     break;
             }
         }
	}
    else
    {
         g_uiUartDelayCount = 0;
         UART_DELAY_TIME    = FALSE;
         g_uiRxCount        = 0;
         U1STAbits.OERR     = 0;                           // 清溢出
    }
}
/*******************************************************************

    函数名称：_U1TXInterrupt(void)
    功    能：串口发送中断，只负责数据包得发送，每CNST_PACKET_DATA_NUMBER
              这么多的数据被发送，采用异步全双工通信
              波特率设置为 9600
              无校验
              1为停止位
    输入参数：无
    输出参数：无
    调用者  ：无
    被调用者：无
    返回值  ：无
********************************************************************/
void __attribute__((interrupt,no_auto_psv)) _U1TXInterrupt(void)
{
     static UInt16 s_uiTxCount = CM_PACKET_DATA_NUMBER;

     IFS0bits.U1TXIF = 0;
                                                           //清除中断标志位
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

    函数名称：ReceivePacket(void)
    功    能：只负责对接收到的数据进行有效性经验，如果接收到的数据位无效
              的，则放弃更新接收数据缓冲区
    输入参数：无
    输出参数：无
    调用者  ：无
    被调用者：无
    返回值  ：无
********************************************************************/
void ReceivePacket(void)
{
     UInt16 i = 0;
     if( !RX_END )
     {
	 	 return;
	 }
      
     RX_END           = FALSE;
	 TestStart_Flag   = TRUE;                              // 将标志置位,以保持检测状态在持续
	 g_COMMStateTimer = 0;                                 // 清超时计数器
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

    函数名称：void PackingPackage(void)
    功    能：对接收的数据进行判定，如果在接收到的数据内，则进行相应的
              回应
    输入参数：无
    输出参数：无
    调用者  ：无
    被调用者：无
    返回值  ：无
********************************************************************/
void PackingPackage(void)
{
	if( !PACK_PACKAGE_END )                                //如果出错,则不回复
	{	
		return;
	}
  //***************************以下是为通用的每一帧的数据赋值 
    TxWorkCachePack.PACK.ucPackProject = RxWorkCachePack.PACK.ucPackProject;              
	TxWorkCachePack.PACK.ucPackClass   = RxWorkCachePack.PACK.ucPackClass;
	TxWorkCachePack.PACK.ucPackMember  = RxWorkCachePack.PACK.ucPackMember;	
	                                                       //数据已经在处理函数里面赋值了
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

    函数名称：void SendPacket(void)
    功    能：对回应的数据进行数据有效性的处理，使数据包符合数据格式的
              的要求。
    输入参数：无
    输出参数：无
    调用者  ：无
    被调用者：无
    返回值  ：无
********************************************************************/
void SendPacket(void)
{
     if( !PACK_PACKAGE_END )
     {		
	 	 return;
	 }
     if( (!TX_START)&U1STAbits.TRMT )                      //
     {
                 
         TX_START         = TRUE;                          // 启动发送
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
		return;	                                           // 如果没有完成一帧数据的确认,则退出
	}
	
	PACK_PACKAGE_END = TRUE;                               // 先置初值为真.	
	Temp_Id          = RxWorkCachePack.PACK.ucPackProject;
	Temp_point       = uartdata_info;                      // 赋搜索指针初值
	//此处一定要先检查是否完整接收到一帧数据,按键是否有效.
	while( Temp_point->TestProject_ID != NO_PROJECT_ID )   // 完成搜索当前的检测项目序号功能
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
	(* Temp_point->Data_Dispose )();                       // 执行当前的检测项目序号功能
	PackingPackage();
	RX_CACHE_UPDATA = FALSE;
}
void StartTest(void)
{
	if(key_Start.Key_State==KEY_ON)
	{
		key_Start.Key_State = KEY_OFF;
		COMMState_LED       = LED_ENABLE;                  // 亮
        COMUNICATION_OK     = LED_DISABLE;                 // 灭		
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
                       

		//*****赋值,准备发送第一帧数据
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
 		PACK_PACKAGE_END          = TRUE;                  // 置位数据帧打包完成标志
		
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
	while(!WAIT_AdUpdateEnd)                               // 死循环等待延时时间到,再获取AD值
		;
	WAIT_AdUpdateStart  = FALSE;                           // 延时计数器停止
	WAIT_AdUpdateEnd    = FALSE;  
}
void Delay_2MS(void)
{
	WAIT_2MS_Start  = TRUE;
	while(!WAIT_2MS_End)                                   // 死循环等待延时时间到,再获取AD值
		;
	WAIT_2MS_Start  = FALSE;                               // 延时计数器停止
	WAIT_2MS_End    = FALSE;  
}
void Delay_5MS(void)
{
	WAIT_5MS_Start  = TRUE;
	while(!WAIT_5MS_End)                                   // 死循环等待延时时间到,再获取AD值
		;
	WAIT_5MS_Start  = FALSE;                               // 延时计数器停止
	WAIT_5MS_End    = FALSE;  
}


