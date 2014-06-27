//---------------------------------------------------------------------------
// hodgen-china
// workMode.c
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

#include "include.h"
#include "stm8s_tim1.h"
#include "stm8s_itc.h"




u8 u8TimeFlag;

u8 time0_5SCount = 0;
u8 time1MinCount = 0;
u8 time0_5HourCount = 0;
u8	u8LockOn0_5Cnt=0;
u8	u8FastCoolMin=4*60;

u8	u8LedTime = TO_OFF_LED_TIM;
u8	u8LockStatus = 0;
u8	u8FlashTim = 0;

u8	u8FastFreezeTimeDisptim = 0;
//u8 u8DispTims=0;
u8 u8AlarmFlag=0;


u8	u8OldMode;
u8	u8OldLCSetTmp;
u8	u8OldLDsetTmp;
u8	u8OldBWsetTmp;
u8	u8OldLDTime;
u8	u8SetLDHourPress5msCnt=0;
u8	u8ForceOff=0;

u8	u8BWMaxSetTemp = C0+20;
u8	u8BWMinSetTemp = C0-24;

u8	u8ModeBak;
u8	u8ForceOffBak;
u8	u8LCUserSetTmpBak;
u8	u8BWUserSetTmpBak;
u8	u8LDUserSetTmpBak;
//u16 u16FastFreezeMinBak;
u8	u8LockFlashTim=0;
u8	u8PrwOnTim0_5Cnt=0;

#ifdef _SCALE_MODE_	
u8	u8scaleTimFlag=0;
#endif	

void changeMode(void);
void OneMinTask(void);

u8 MinToHour(u16 u16Min)
{
	return (u8)((u16Min+59)/60);
}

void initTimer(void)
{
		TIM1_DeInit();
		TIM1_TimeBaseInit(15, TIM1_COUNTERMODE_UP,5000-1, 0);	//5MS
		TIM1_ARRPreloadConfig(ENABLE);
		TIM1_ITConfig(TIM1_IT_UPDATE, ENABLE);
		TIM1_Cmd(ENABLE);
}

#ifdef _COSMIC_
@far @interrupt void TIM1_UPD_OVF_TRG_BRK_IRQHandler(void)
#else /* _RAISONANCE_ */
void TIM1_UPD_OVF_TRG_BRK_IRQHandler(void) interrupt 11
#endif /* _COSMIC_ */
{
		TIM1_ClearITPendingBit(TIM1_IT_UPDATE);	
		u8TimeFlag |= Time5MS;
		time0_5SCount++;
		if(time0_5SCount>=100)
		{
				time0_5SCount = 0;
				u8TimeFlag |= Time0_5S;
		}
		Buzzer5MSTask();
		nop();
		nop();
		nop();	
}



void timerTask(void)
{
		u8	u8FastFreezeHour = MinToHour(u16FastFreezeMin);
		if(u8FastFreezeHour<6) u8FastFreezeHour = 6;
		
		if( (u8TimeFlag&Time5MS) == Time5MS )
		{
				u8TimeFlag &= (u8)(~Time5MS);
				keyScan();
				if( fgKeyLDSetHour )
				{
						if(u8SetLDHourPress5msCnt<20) u8SetLDHourPress5msCnt++;
						else
						{
								u8SetLDHourPress5msCnt = 0;
								if(u8KeyValue ==SUB_LD_KEY)
								{
										if(u8FastFreezeHour>6) u8FastFreezeHour--;
										else u8FastFreezeHour = 6;	//6 hour
										u8FastFreezeTimeDisptim = 14;//7s
										u16FastFreezeMin = u8FastFreezeHour*60;
								}
								else if(u8KeyValue ==ADD_LD_KEY)
								{
										if(u8FastFreezeHour<24) u8FastFreezeHour++;
										else u8FastFreezeHour = 24;	//24 hour
										u8FastFreezeTimeDisptim = 14;//7s
										u16FastFreezeMin = u8FastFreezeHour*60;
								}
								updateLed(0);
						}
				}
		}
		if( (u8TimeFlag&Time0_5S) == Time0_5S )
		{
				u8TimeFlag &= (u8)(~Time0_5S);
				RxTimeTask();
				if(u8LockFlashTim>0) u8LockFlashTim--;
				if(u8LockOn0_5Cnt>0) u8LockOn0_5Cnt--;
				if(u8PrwOnTim0_5Cnt<250) u8PrwOnTim0_5Cnt++;
				if( !fgKeyPress ) u8TimeFlag ^= Tim0_5Flash;
				u8TimeFlag ^= Tim0_5Flash_Temp;
				if( (u8AlarmFlag&PWRON_FLASH_H)==PWRON_FLASH_H)
				{
					if(u16PwrOnFlashH0_5sCnt<2400)
					{
						u16PwrOnFlashH0_5sCnt++;//20Min
					}
					else
					{
						u8AlarmFlag &= (u8)(~PWRON_FLASH_H);
					}
				}
				if(++time1MinCount >= 120)
				{
						time1MinCount = 0;
						u8TimeFlag |= Time1Min;
						if(++time0_5HourCount >= 30)
						{
								time0_5HourCount = 0;
						}
				}
				if((time1MinCount&0x01) == 0)
				{
						u8TimeFlag |= Time1S;
				}
				if(u8LedTime>0)
				{
						u8LedTime--;
						if(u8LedTime == 0)
						{
								if(u8LockStatus == 0)	buz(BZR_A);
								if(u8LockStatus==0)
								{
									u8LockStatus = 1;
									u8LockOn0_5Cnt=TO_OFF_LED_TIM;
								}
						}
				}
				if(u8FastFreezeTimeDisptim>0)
				{
						u8FastFreezeTimeDisptim--;
						if(u8FastFreezeTimeDisptim == 0)
						{
								u8AlarmFlag &= (u8)(~FREEZE_KEY_DOWN);
						}
				}
				if(u8FlashTim>0)
				{
						u8FlashTim--;
						if(u8FlashTim == 0)
						{
							if( (u8ModeBak == FAST_FREEZE_MODE)&&(u8Mode!=FAST_FREEZE_MODE) ) u16FastFreezeMin = 6*60;	//6 hour
							if( (u8ModeBak == FAST_COOL_MODE)  &&(u8Mode!=FAST_COOL_MODE)   ) u8FastCoolMin = 4*60;	//4 hour
								
							if( (u8ModeBak==INTELLIGENT_MODE)&&((u8LCUserSetTmpBak!= C0+10)||(u8LDUserSetTmpBak!= C0-36)) ) u8ModeBak = 0;
							else if( (u8ModeBak==HOLIDAY_MODE)&&((u8LCUserSetTmpBak!= C0+14)||(u8LDUserSetTmpBak!= C0-30)) ) u8ModeBak = 0;									
								
								u8Mode = u8ModeBak;
								u8LCUserSetTmp = u8LCUserSetTmpBak;
								u8LDUserSetTmp = u8LDUserSetTmpBak;
								u8BWUserSetTmp = u8BWUserSetTmpBak;								
								if( (u8Mode != FAST_COOL_MODE) && (u8Mode != FAST_FREEZE_MODE) )
								{
									u8OldMode = u8Mode;
									u8OldLCSetTmp = u8LCUserSetTmp;
									u8OldLDsetTmp = u8LDUserSetTmp;
									u8OldBWsetTmp	=	u8BWUserSetTmp;
								}
						}
				}
				if( fgKeyPress )
				{
						if(u8KeyPressTime0_5s<200) u8KeyPressTime0_5s++;
						if( (u8KeyPressTime0_5s == UNLOCK_TIM) && (u8LedTime!=0) )
						{
								if( u8KeyValue == UNLOCK_KEY )
								{
										if( u8LockStatus != 0)
										{
												u8LockStatus = 0;
												u8LockOn0_5Cnt = 0;
												buz(BZR_UP_3);
										}
										else
										{
												u8LockStatus = 1;
												u8FlashTim = 0;
												buz(BZR_UP_3);
										}
										
										u8LedTime = TO_OFF_LED_TIM;
										fgKeyLongPress = 1;
								}
								else if( u8KeyValue == MODE_KEY )
								{
									if( u8LockStatus!=0 )
									{
										if( (u8OutState&FactoryTest) == FactoryTest )
										{
												u8ForceOff |= OUT_FACT_TEST;
												fgKeyLongPress = 1;
												buz(BZR_UP_3);
										}
										else
										{
												if(!fgCommPannelErr)
												{
													fgKeyLongPress = 1;
													fgKeyDispTemp = 1;
												}
										}
									}
								}
								else if( ((u8KeyValue ==SUB_LC_KEY)||(u8KeyValue ==ADD_LC_KEY)) && (u8Mode != FAST_COOL_MODE) )
								{
										if(u8LockStatus == 0)
										{
											if( (u8ForceOff&LC_FORCE_OFF) == 0)
											{
													u8ForceOff |= LC_FORCE_OFF;
											}
											else
											{
													u8ForceOff &= (u8)(~LC_FORCE_OFF);
											}
											fgKeyLongPress = 1;
											buz(BZR_UP_3);
										}
								}
								else if( (u8KeyValue ==SUB_BW_KEY) || (u8KeyValue ==ADD_BW_KEY) )
								{
										if(u8LockStatus == 0)
										{
											if( (u8ForceOff&BW_FORCE_OFF) == 0)
											{
													u8ForceOff |= BW_FORCE_OFF;
											}
											else
											{
													u8ForceOff &= (u8)(~BW_FORCE_OFF);
											}
										}
#ifdef	_SCALE_MODE_										
										else
										{
											if(u8scaleTimFlag==0) u8scaleTimFlag=1;
											else u8scaleTimFlag=0;
										}
#endif										
										fgKeyLongPress = 1;
										buz(BZR_UP_3);										
								}
								else if( ((u8KeyValue ==SUB_LD_KEY) || (u8KeyValue ==ADD_LD_KEY)) )
								{
										if( (u8Mode == FAST_FREEZE_MODE)&&(u8LockStatus == 0) )
										{
												fgKeyLongPress = 1;
												fgKeyLDSetHour = 1;
												u8SetLDHourPress5msCnt = 0;
												buz(BZR_UP_3);
										}
								}
								else if(u8KeyValue == SELF_TEST_KEY)
								{
									if(u8PrwOnTim0_5Cnt<60)
									{
										buz(BZR_UP_3);
										selfTest();
									}
								}
						}
						
				}
				else u8KeyPressTime0_5s = 0;
				
				if(u8LedTime>0) updateLed(0);
				else updateLed(1);		
				
//0.5s sub	
		}
		if( (u8TimeFlag&Time1S) == Time1S )
		{
				u8TimeFlag &= (u8)(~Time1S);
				ADSample();
				if( (u8MainBoardOutput&LC_DOOR_OPEN) == LC_DOOR_OPEN)
				{
						if(u16DoorOpen1s<0xfff0) u16DoorOpen1s++;
						if( u16DoorOpen1s==90 )	u8AlarmFlag |= DOOR_OPEN_ALARM;
				}
				if( (++u8Comm1sCnt) > 40)
				{
					u8Comm1sCnt = 0;
					if(u8receivedCnt>17) fgCommMainErr = 1;
					else fgCommMainErr = 0;
					u8Comm1sCnt = 0;
				}
				if( ((u8AlarmFlag&DOOR_OPEN_ALARM) == DOOR_OPEN_ALARM) && (u16DoorOpen1s<300) )
				{
						if( (u8OutState&BuzWork)!=BuzWork) buz(BZR_DOWN_3);	
				}
				else if( ((u8AlarmFlag&LD_HIGH_ALARM)==LD_HIGH_ALARM) && (u8CmpCOntinueRunTim<5) )
				{
						if( (u8OutState&BuzWork)!=BuzWork) buz(BZR_DOWN_3);
				}

#ifdef _SCALE_MODE_				
				if(u8scaleTimFlag != 0) OneMinTask();
#endif
				
//1s sub
		}
		if( (u8TimeFlag&Time1Min) == Time1Min )
		{
				u8TimeFlag &= (u8)(~Time1Min);
#ifdef _SCALE_MODE_	
				if(u8scaleTimFlag == 0)
#endif	
				{
					OneMinTask();
				}
		}
}

void OneMinTask(void)
{
	if(u8Mode == FAST_FREEZE_MODE)
	{
		if(u16FastFreezeMin != 0) u16FastFreezeMin--;
		else	//if(u16FastFreezeMin == 0)
		{
			u8Mode = u8OldMode;
			u8OldMode = u8OldMode;
			u8LDUserSetTmp = u8OldLDsetTmp;
			u8LDUserSetTmpBak = u8OldLDsetTmp;
		}
	}
	else if(u8Mode == FAST_COOL_MODE)
	{
		if(u8FastCoolMin != 0) u8FastCoolMin--;
		else	//if(u8FastCoolMin == 0)
		{
			u8Mode = u8OldMode;
			u8ModeBak = u8OldMode;
			u8LCUserSetTmp = u8OldLCSetTmp;
			u8LCUserSetTmpBak = u8OldLCSetTmp;
		}
	}
	if( (u8Mode != FAST_COOL_MODE)&&(u8Mode!=FAST_FREEZE_MODE)&&((u8MainBoardOutput&CMP_RUNING) == CMP_RUNING))
	{
	  if( (u8AlarmFlag&LD_HIGH_ALARM) == 0)
		{
			if(u8CmpCOntinueRunTim<250) u8CmpCOntinueRunTim++;
			if(u8CmpCOntinueRunTim > (4*60) )
			{
				if( u8LDSnrTemp>=(C0-16) )
				{
					u8CmpCOntinueRunTim = 0;
					u8AlarmFlag |= LD_HIGH_ALARM;
				}
			}
		}
		else
		{
			if( u8LDSnrTemp<=(C0-20) )
			{
				u8CmpCOntinueRunTim = 0;
				u8AlarmFlag &= (u8)(~LD_HIGH_ALARM);
			}
			else
			{
				if(u8CmpCOntinueRunTim<35) u8CmpCOntinueRunTim++;
				else u8CmpCOntinueRunTim = 0;
			}
		}
	}
}


void Work(void)
{
		u8	u8FastFreezeHour = MinToHour(u16FastFreezeMin);
		if(u8FastFreezeHour<6) u8FastFreezeHour = 6;
		
		if( fgKeyUp )
		{
 				fgKeyUp = 0;
				u8LedTime = TO_OFF_LED_TIM;
				if( u8LockStatus != 0 )	//lock status
				{
					updateLed(0);
					buz(BZR_A);
//					if(u8KeyValue != UNLOCK_KEY)
					{
						u8LockFlashTim = FLASH_TIME;
					}
					return;
				}
				if(u8FlashTim==0)
				{
					u8FlashTim = FLASH_TIME;
					updateLed(0);
					buz(BZR_UP_3);					
					return;
				}
				u8FlashTim = FLASH_TIME;
				
				switch(u8KeyValue)
				{
						case SUB_LC_KEY:
						{
								if(u8ModeBak == FAST_COOL_MODE)
								{
										u8LCUserSetTmpBak = C0+4;
										break;
								}
								else if( ((u8ForceOff&LC_FORCE_OFF)==LC_FORCE_OFF) ) break;
								else
								{
									u8LCUserSetTmpBak &= 0xfe;
									if(u8LCUserSetTmpBak>(C0+4))	u8LCUserSetTmpBak -= 2;
									else											u8LCUserSetTmpBak  = C0+4;	//2C
								}
								break;
						}
						case ADD_LC_KEY:
						{
								if(u8ModeBak == FAST_COOL_MODE)
								{
										u8LCUserSetTmpBak = C0+4;
										break;
								}
								else if( ((u8ForceOff&LC_FORCE_OFF)==LC_FORCE_OFF) ) break;
								else
								{
									u8LCUserSetTmpBak &= 0xfe;
									if(u8LCUserSetTmpBak<(C0+16))	u8LCUserSetTmpBak += 2;
									else											u8LCUserSetTmpBak  = C0+16;
								}
								break;		
						}
						case SUB_BW_KEY:
						{
								if( ((u8ForceOff&BW_FORCE_OFF)==BW_FORCE_OFF) ) break;
								u8BWUserSetTmpBak &= 0xfe;
								if(u8BWUserSetTmpBak>u8BWMinSetTemp)	u8BWUserSetTmpBak -= 2;
								else											u8BWUserSetTmpBak  = u8BWMinSetTemp;	//-12
								break;
						}
						case ADD_BW_KEY:
						{
								if( ((u8ForceOff&BW_FORCE_OFF)==BW_FORCE_OFF) ) break;
								u8BWUserSetTmpBak &= 0xfe;
								if(u8BWUserSetTmpBak<u8BWMaxSetTemp)	u8BWUserSetTmpBak += 2;
								else											u8BWUserSetTmpBak  = u8BWMaxSetTemp;			
								break;
						}
						case SUB_LD_KEY:
						{
								if(u8ModeBak == FAST_FREEZE_MODE)
								{
										if( (u8AlarmFlag&FREEZE_KEY_DOWN)==FREEZE_KEY_DOWN)
										{
											if(u8FastFreezeHour>6) u8FastFreezeHour--;
											else u8FastFreezeHour = 6;	//6 hour
											u8FastFreezeTimeDisptim = 14;//7s
										}
								}
								else
								{
										u8LDUserSetTmpBak &= 0xfe;
										if(u8LDUserSetTmpBak>(C0-44))	u8LDUserSetTmpBak -= 2;
										else											u8LDUserSetTmpBak  = C0-44;	//-22									
								}
								break;
						}
						case ADD_LD_KEY:
								if(u8ModeBak == FAST_FREEZE_MODE)
								{
										if( (u8AlarmFlag&FREEZE_KEY_DOWN)==FREEZE_KEY_DOWN)
										{									
											if(u8FastFreezeHour<24) u8FastFreezeHour++;
											else u8FastFreezeHour = 24;	//24 hour
											u8FastFreezeTimeDisptim = 14;//7s
										}
								}
								else
								{
										u8LDUserSetTmpBak &= 0xfe;
										if(u8LDUserSetTmpBak<(C0-32))	u8LDUserSetTmpBak += 2;
										else											u8LDUserSetTmpBak  = C0-32;	//-16C				
								}
								break;
						case MODE_KEY:
								u8ForceOff &= (u8)(~LC_FORCE_OFF);
								u8FastFreezeTimeDisptim = 0;
								changeMode();
								break;
//						case UNLOCK_KEY:
						default:
								break;
				}
				

				
				u16FastFreezeMin = u8FastFreezeHour*60;
				u8TimeFlag |= Tim0_5Flash;
				updateLed(0);
				buz(BZR_UP_3);
		}

		else if( fgKeyPress )
		{
//			u8LedTime = TO_OFF_LED_TIM;
//			if( u8LockStatus == 0 ) u8FlashTim = FLASH_TIME;
			if(u8KeyValue == UNLOCK_KEY)
			{
				u8LockFlashTim = 0;
			}			
			u8TimeFlag |= Tim0_5Flash;
		}
		if( fgKeyDown )
		{
				fgKeyDown = 0;
				u8AlarmFlag &= (u8)(~(LD_HIGH_ALARM));	//DOOR_OPEN_ALARM
//				u8LedTime = TO_OFF_LED_TIM;	//LOCK_OFF_LED_TIM;
				u8CmpCOntinueRunTim = 0;
				if( (u8Mode == FAST_FREEZE_MODE) && ((u8KeyValue==ADD_LD_KEY)|(u8KeyValue==SUB_LD_KEY)) )
				{
					if( u8LockStatus == 0 )
					{
						if(u8FastFreezeTimeDisptim != 0) u8AlarmFlag |= FREEZE_KEY_DOWN;
						u8FastFreezeTimeDisptim = 14;//7s
					}
				}
				else
				{
					u8FastFreezeTimeDisptim = 0;
					u8AlarmFlag &= (u8)(~FREEZE_KEY_DOWN);
				}				
		}
}

void changeMode(void)
{
		switch(u8ModeBak)
		{
				case FAST_COOL_MODE:
						u8ModeBak = FAST_FREEZE_MODE;
						u8FastFreezeTimeDisptim = 14;	
						u8AlarmFlag |= FREEZE_KEY_DOWN;
						break;
				case FAST_FREEZE_MODE:
						u8ModeBak = INTELLIGENT_MODE;
						u8LCUserSetTmpBak = C0+10;	//5
						u8LDUserSetTmpBak = C0-36;	//-18						
						break;
				case INTELLIGENT_MODE:
						u8ModeBak = HOLIDAY_MODE;
						u8LCUserSetTmpBak = C0+14;	//7
						u8LDUserSetTmpBak = C0-30;	//-15						
						break;
				case HOLIDAY_MODE:
						u8ModeBak =	0;
						u8LCUserSetTmpBak = u8OldLCSetTmp;
						u8LDUserSetTmpBak = u8OldLDsetTmp;
						u8BWUserSetTmpBak = u8OldBWsetTmp;
						break;
				default:
						u8ModeBak = FAST_COOL_MODE;
						u8LCUserSetTmpBak = C0+4;	//2
						break;
		}
}



