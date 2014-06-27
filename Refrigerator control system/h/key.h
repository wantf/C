//---------------------------------------------------------------------------
// hodgen-china
// key.h
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _KEY_SCAN_H_
#define _KEY_SCAN_H_

#include "stm8s.h"

/* Includes ------------------------------------------------------------------*/
#define			SUB_LC_KEY		0x01
#define			ADD_LC_KEY		0x02
#define			SUB_BW_KEY		0x04
#define			ADD_BW_KEY		0x08
#define			SUB_LD_KEY		0x10
#define			ADD_LD_KEY		0x20
#define			MODE_KEY			0x40
#define			UNLOCK_KEY		0x80
#define			SELF_TEST_KEY	(SUB_LC_KEY|UNLOCK_KEY)
/*
#define			SUB_LC			(GPIO_PIN_1)		//PA1
#define			ADD_LC			(GPIO_PIN_2)		//PA2
#define			SUB_BW			(GPIO_PIN_3)		//PA3

#define			ADD_BW			(GPIO_PIN_5)		//PB5
#define			SUB_LD			(GPIO_PIN_4)		//PB4

#define			ADD_LD		(GPIO_PIN_3)			//PC3
#define			MODE				(GPIO_PIN_4)		//PC4
#define			UNLOCK	 		(GPIO_PIN_5)		//PC5
*/
/* Exported types ------------------------------------------------------------*/
#ifdef	NEW_260
#define LD_KEY_PORT	(GPIOD)
#define LD_KEY			(GPIO_PIN_3)
#else
#define LD_KEY_PORT	(GPIOA)
#define LD_KEY			(GPIO_PIN_3)
#endif
/* Exported constants --------------------------------------------------------*/
extern u8 u8KeyEvent;
#define fgKeyDown	                ((struct bits*)&u8KeyEvent)->BIT0
#define fgKeyPress                ((struct bits*)&u8KeyEvent)->BIT1
#define fgKeyUp		                ((struct bits*)&u8KeyEvent)->BIT2
#define fgKeyLongPress            ((struct bits*)&u8KeyEvent)->BIT3
#define fgKeyLDSetHour            ((struct bits*)&u8KeyEvent)->BIT4
#define fgKeyDispTemp             ((struct bits*)&u8KeyEvent)->BIT5


extern u8 u8KeyValue;
extern u8 u8KeyPressTime0_5s;

extern u8	 u8LCTotalRunTime0_5Hour;
extern u16	u16FastFreezeMin;
extern u8	 u8LCUserSetTmp;
extern u8	 u8BWUserSetTmp;
extern u8 	 u8LDUserSetTmp;
extern u8 	 u8Mode;
#define NORMAL_MODE        0
#define FAST_COOL_MODE     0x02  		//速冷
#define FAST_FREEZE_MODE   0x01 		//速冻
#define  INTELLIGENT_MODE  0x80 		//智能
#define HOLIDAY_MODE       0x04 		//假日

#define		TMP_SET_OFF			0xff

/* Evalboard I/Os configuration */

void keyScan(void);
u8 allKeyUp(void);
void delay(u16 time);
void initKey(void);
#endif /* __KEY_H__ */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
