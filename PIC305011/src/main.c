/*************************wantf*******文件说明*****************************
* *
*    作者 :    wantf 
*    公司 ：   CQ Hejing）
*    项目编号：3EUB1A-FCT
* *
*    文件名 :  Main.c 
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
#include "Main.h"

int main(void)
{
     SetupBoard();
     while(1)
     {  
         StartTest();
         ReceivePacket(); 
		 ReceiveData_Dispose();	
         SendPacket();
         if( (U1STAbits.OERR&U1STAbits.FERR) )                // U1STAbits.PERR
         {
             U1STAbits.OERR = 0;
             U1STAbits.FERR = 0;
         }
//Project25_Dispose();
//LOAD_RCDA			= LOAD_RCD_13A;
		 /*****************   看门狗清零 *****************/     
		 ClrWdt(); 
TEST_IO1 = TEST_IO1+1; 
     }
}

