/*************************wantf*******�ļ�˵��*****************************
* *
*    ���� :    wantf 
*    ��˾ ��   CQ Hejing��
*    ��Ŀ��ţ�3EUB1A-FCT
* *
*    �ļ��� :  Main.c 
*    ���� :    2012.1.6 
*    �ļ��汾 :1.00 
* *
*    ʹ�ù��� :MPLAB 8.50 
*    ������:   C30 
* *
* 
*******************************��д����****************************************
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
		 /*****************   ���Ź����� *****************/     
		 ClrWdt(); 
TEST_IO1 = TEST_IO1+1; 
     }
}
