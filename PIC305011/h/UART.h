#ifndef _UART_H
#define _UART_H

#include "GlobalParm.h"


//---------------------   波特率设置    ---------------

#define CM_DEST_BRG                    9600
#define CM_BRG                         (((CM_FCY/CM_DEST_BRG)/16)-1)

//---------------------   数据包 包头   ---------------

#define CM_PACKET_HEAD                 0x55AA

//---------------------   数据包 确认字   ---------------

#define CM_PACKET_ACK                  0x70
#define CM_PACKET_READ                 0xF3

//---------------------  标志成员   ---------------

#define FLAG_MEMBER_03                 3

//---------------------   发送字节数设置---------------

#define CM_PACKET_DATA_NUMBER          10
#define CM_PACKET_DATA_NUMBER_LIMET    (CM_PACKET_DATA_NUMBER - 1)

#define CM_TP_COUNTER                  5

void Project01_Dispose(void);
void Project02_Dispose(void);
void Project03_Dispose(void);
void Project04_Dispose(void);
void Project05_Dispose(void);
void Project06_Dispose(void);
void Project07_Dispose(void);
void Project08_Dispose(void);
void Project09_Dispose(void);
void Project10_Dispose(void);
void Project11_Dispose(void);
void Project12_Dispose(void);
void Project13_Dispose(void);
void Project14_Dispose(void);
void Project15_Dispose(void);
void Project16_Dispose(void);
void Project17_Dispose(void);
void Project18_Dispose(void);
void Project19_Dispose(void);
void Project20_Dispose(void);
void Project21_Dispose(void);
void Project22_Dispose(void);
void Project23_Dispose(void);
void Project24_Dispose(void);
void Project25_Dispose(void);
void Project26_Dispose(void);
void Project27_Dispose(void);
void Project28_Dispose(void);
void Project29_Dispose(void);
void Project30_Dispose(void);
void Project31_Dispose(void);
void Project32_Dispose(void);
void Project33_Dispose(void);
void Project34_Dispose(void);
void Project35_Dispose(void);
void Project36_Dispose(void);
void Project37_Dispose(void);
void Project38_Dispose(void);

void Project39_Dispose(void);
void Project40_Dispose(void);
void Project41_Dispose(void);
void Project42_Dispose(void);

void Error_Disprose(void);
UInt8 check_PhaseMiss(void);




#endif


