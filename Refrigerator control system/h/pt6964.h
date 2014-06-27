//---------------------------------------------------------------------------
// hodgen-china
// pt6964.h
// $Project: sanyo BCD-220TGE $
// $Revision: 0.1 $
// $Author: wantf $
// $Date: 2011/08/26 16:15:51 $
// $MCU:STM8S103F3
// $Software Build Environment:STVD 4.1.1
//
// --------------------------------------------------------------------------
// >>>>>>>>>>>>>>>>>>>>>>>>> COPYRIGHT NOTICE <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// --------------------------------------------------------------------------
// Copyright 2011(c) hodgen-china.
// This is an unpublished work.
// --------------------------------------------------------------------------

#ifndef __PT6964_H__
#define __PT6964_H__

#include "stm8s.h"

extern u8	u8SelfTestStep;
extern u8	u8SelfTestDispStep;
extern u8 dispBuf[14];

#define PT6964_CLK_PORT (GPIOC)
#define PT6964_CLK  (GPIO_PIN_7)

#define 	PT6964_CLK_H		GPIO_WriteHigh(PT6964_CLK_PORT,PT6964_CLK)
#define 	PT6964_CLK_L		GPIO_WriteLow(PT6964_CLK_PORT,PT6964_CLK)

#define PT6964_DATA_PORT (GPIOD)
#define PT6964_DOUT  (GPIO_PIN_1)
#define PT6964_DIN  (GPIO_PIN_1)

#define 	PT6964_DIN_H		GPIO_WriteHigh(PT6964_DATA_PORT,PT6964_DIN)
#define 	PT6964_DIN_L		GPIO_WriteLow(PT6964_DATA_PORT,PT6964_DIN)

#define PT6964_STB_PORT (GPIOC)
#define PT6964_STB  (GPIO_PIN_6)

#define		PT6964_STB_H		GPIO_WriteHigh(PT6964_STB_PORT,PT6964_STB)
#define		PT6964_STB_L		GPIO_WriteLow(PT6964_STB_PORT,PT6964_STB)

//------------------------------------------------------------------------------------------------
//指令和数据操作
//------------------------------------------------------------------------------------------------
#define		SMG_OFF		18

//--------------------------------------------------------------------------
// Write Command to LCM
//--------------------------------------------------------------------------
extern const u8 Disp_Tab[];

//----------------------------------
// WriteData
//----------------------------------
void WriteData(u8 Value);

//----------------------------------
// Write_Adr_Data to LCM
//----------------------------------
void Write_Adr_Data(u8 addr, u8 value);
//----------------------------------
// Clear6964RAM
//----------------------------------
void Clear6964RAM(void);
void PT6964_Init(void);
void Change_Bright(u8 Led_Brigh);
//----------------------------------
// Write Command to LCM
//----------------------------------
void	updateLed(u8 ledOff);
void selfTestDisplay(void);
void	writeBufTo6964(void);
void setDispBuf(u8 data);
#endif
