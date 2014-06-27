//---------------------------------------------------------------------------
// hodgen-china
// workMode.h
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
#ifndef _WORK_MODE_H_
#define _WORK_MODE_H_
/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
extern u8 u8TimeFlag;
//#define Time0_5Hour 		 0x80
#define Time1Min				 0x40
#define Time1S					 0x20
#define Time0_5S				 0x10
#define Time5MS					 0x08
#define Tim0_5Flash 		 0x04
#define Tim0_5Flash_Temp 0x02
#define Tim0_2Flash			 0x01

extern u8 time0_5SCount;
extern u8 time1MinCount;
extern u8 time0_5HourCount;

extern u8	u8LedToOffTime0_5s;
extern u8	u8LockFlashTim;
extern u8		u8LedTime;
extern u8		u8LockStatus;
extern u8		u8FlashTim;
extern u8	u8BWMaxSetTemp;
extern u8	u8BWMinSetTemp;
extern u8		u8FastFreezeTimeDisptim;
extern u8	u8OutFactortTest;
extern u8	u8LockOn0_5Cnt;
extern u8	u8OldMode;
extern u8	u8OldLCSetTmp;
extern u8	u8OldLDsetTmp;
extern u8	u8OldBWsetTmp;

extern u8	u8ModeBak;
extern u8	u8ForceOffBak;
extern u8	u8LCUserSetTmpBak;
extern u8	u8BWUserSetTmpBak;
extern u8	u8LDUserSetTmpBak;

extern u8	u8ForceOff;
#define BW_FORCE_OFF	0x01
#define	LC_FORCE_OFF	0x02
#define	OUT_FACT_TEST	0x10


extern u8 u8AlarmFlag;
#define DOOR_OPEN_ALARM	0x01
#define	LD_HIGH_ALARM		0x02
#define FREEZE_KEY_DOWN	0x04
#define PWRON_FLASH_H		0x08

#ifdef _SCALE_MODE_	
extern u8	u8scaleTimFlag;
#endif	

#define		TO_OFF_LED_TIM		60		//60S
//#define		TO_LOCK_TIME			60		//30s
#define		LOCK_OFF_LED_TIM	10		//5S
#define		UNLOCK_TIM				6
#define		FLASH_TIME				6
void initTimer(void);
void Work(void);
void timerTask(void);
void errorTask(void);
void selfTest(void);
u8 MinToHour(u16 u16Min);
#endif