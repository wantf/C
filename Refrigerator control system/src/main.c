//---------------------------------------------------------------------------
// hodgen-china
// main.c
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

#define _COSMIC_
//#define STM8S103
/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "stm8s_clk.h"
#include "stm8s_rst.h"
#include "stm8s_iwdg.h"
#include "include.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

void powerWait(void);
void IWDG_Configuration(void);
/* Private functions ---------------------------------------------------------*/
void main(void)
{
		CLK_DeInit();
//		CLK_HSECmd(ENABLE);
		CLK_HSIPrescalerConfig(CLK_PRESCALER_CPUDIV8);
//		CLK_HSICmd(DISABLE);
		initTxRx();
		initBuz();
		initAD();
		initTimer();
		initKey();	
		enableInterrupts();		

		RST_ClearFlag(RST_FLAG_EMCF|RST_FLAG_ILLOPF|RST_FLAG_IWDGF);
		powerWait();

		IWDG_Configuration();

		while (1)
		{
				IWDG_ReloadCounter();
				timerTask();
				Work();
				commRevTask();
		}
}


void selfTest(void)
{
		u8SelfTestFlag = 1;
		u8SelfTestStep=0;
		u8SelfTestDispStep=0;
		setDispBuf(0);	//selfTestDisplay();
		writeBufTo6964();
		while(1)
		{
				IWDG_ReloadCounter();
				if( (u8TimeFlag&Time5MS) == Time5MS )
				{
						u8TimeFlag &= (~Time5MS)&0xff;
						keyScan();
				}
				commRevTask();
				if( (u8TimeFlag&Time0_5S) == Time0_5S )
				{
						u8TimeFlag &= (~Time0_5S)&0xff;			
						selfTestDisplay();
						writeBufTo6964();
				}
				if( (fgKeyUp) && (u8SelfTestStep == 0) )
				{
						u8SelfTestStep = 1;
						fgKeyUp = 0;
				}
				if( fgKeyDown && (u8SelfTestStep!=0) )
				{
						buz(BZR_UP_3);
						fgKeyDown = 0;
						if(u8SelfTestStep==1)
						{
							u8SelfTestStep = 2; 
							u8SelfTestDispStep = 0;
						}
						if((u8SelfTestStep==2) && (u8SelfTestDispStep==19) )
						{
								setDispBuf(0);
								writeBufTo6964();
								u8SelfTestStep =3;
						}
						if(u8SelfTestStep == 3)
						{
								switch(u8KeyValue)
								{
										case SUB_LC_KEY:
										{
											if( (dispBuf[0]&0x02) == 0x02)
											{
												dispBuf[0]&=0xfd;
											}
											else 	dispBuf[0]|=0x02;
											break;
										}
										case ADD_LC_KEY:
										{
											if( (dispBuf[13]&0x01) == 0x01)
											{
												dispBuf[12]	&= (u8)(~0x10);
												dispBuf[13]	&= (u8)(~0x01);												
											}
											else
											{
												dispBuf[12]	|= 0x10;
												dispBuf[13]	|= 0x01;
											}
											break;
										}
										case	SUB_BW_KEY:
										{
											if( (dispBuf[4]&0x02) == 0x02)
											{
												dispBuf[4]&=0xfd;
											}
											else 	dispBuf[4]|=0x02;
											break;			
										}
										case	ADD_BW_KEY:
										{
											if( (dispBuf[12]&0x80) == 0x80 )
											{
												dispBuf[12] &= (u8)(~0x88);
											}
											else
											{
												dispBuf[12] |= 0x88;
											}
											break;
										}
										case	SUB_LD_KEY:
										{
											if( (dispBuf[8]&0x02) == 0x02 )
											{
												dispBuf[8] &= (u8)(~0x02);
											}
											else
											{
												dispBuf[8] |= 0x02;
											}											
											break;		
										}													
										case	ADD_LD_KEY:
										{
											if( (dispBuf[12]&0x40) == 0x40 )
											{
												dispBuf[12] &= (u8)(~0x44);
											}
											else
											{
												dispBuf[12] |= 0x44;
											}											
											break;
										}
										case	MODE_KEY:
										{
											if( (dispBuf[4]&0x01) == 0x01 )
											{
												dispBuf[4] &= (u8)(~0x01);
											}
											else
											{
												dispBuf[4] |= 0x01;
											}													
											break;
										}
										case  UNLOCK_KEY:
										{
											if( (dispBuf[8]&0x01) == 0x01 )
											{
												dispBuf[8] &= (u8)(~0x01);
											}
											else
											{
												dispBuf[8] |= 0x01;
											}														
												break;
										}
										default:					break;
								}
								writeBufTo6964();
						}
				}
		}
}


void powerWait(void)
{
		u8TimeFlag =0;
		PT6964_Init();
		setDispBuf(0xff);
		writeBufTo6964();
		buz(BZR_UP_3);		
		for(time1MinCount=0;time1MinCount<7;) //
		{
				IWDG_ReloadCounter();
/*				
				if( (u8TimeFlag&Time5MS) == Time5MS )
				{
						u8TimeFlag &= (~Time5MS)&0xff;
				}
*/				
				if((u8TimeFlag&Time0_5S) == Time0_5S)
				{
						u8TimeFlag &= (~Time0_5S)&0xff;
						time1MinCount++;
				}
				commRevTask();
		}	
		time1MinCount = 0;		
		if(u8LCUserSetTmp == 0)
		{
				u8LCUserSetTmp = C0+10;
				u8BWUserSetTmp = C0+0;
				u8LDUserSetTmp = C0-36;	//-18
				u8Mode	=	INTELLIGENT_MODE;
				u8ModeBak=u8Mode;
				u8ForceOffBak=u8ForceOff;
				u8LCUserSetTmpBak=C0+10;;
				u8BWUserSetTmpBak=C0+0;
				u8LDUserSetTmpBak=C0-36;	//-18				
				fgCommPannelErr = 1;
		}		
		if( (u8Mode == INTELLIGENT_MODE) && (u8Mode == HOLIDAY_MODE) ) u8OldMode = u8Mode;
		else	u8OldMode = INTELLIGENT_MODE;
		u8OldLCSetTmp = u8LCUserSetTmp;
		u8OldLDsetTmp = u8LDUserSetTmp;
		u8OldBWsetTmp = u8BWUserSetTmp;
		if(u8OldLCSetTmp>(C0+30)) u8OldLCSetTmp = C0+10;
		if(u8OldBWsetTmp>(C0+30)) u8OldBWsetTmp = C0;
		if(u8Mode == FAST_FREEZE_MODE) u16FastFreezeMin = 6*60;				
		updateLed(0);
}


void IWDG_Configuration(void)
{
	/* Enable the IWDG*/
	IWDG_Enable();
  /* Enable the access to the IWDG registers*/
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	/* Fixe IWDG Reset period */
  IWDG_SetPrescaler(IWDG_Prescaler_256);
	IWDG_SetReload(0xFF);
	/* Refresh IWDG */
  IWDG_ReloadCounter();
}
