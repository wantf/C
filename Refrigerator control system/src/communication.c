//---------------------------------------------------------------------------
// hodgen-china
// communication.c
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
#include "stm8s.h"
#include "include.h"
#include "stm8s_tim4.h"
#include "stm8s_exti.h"


//#include "stm8s_itc.h"
// --------------------------------------------------------------------------
#define		TOTAL_TX_BYTE		10
#define		TOTAL_RX_BYTE		13
u8		u8CurSendByte = 0;
u8		u8CurSendBit = 0;
u8		u8CurSend500usCnt = 0;
u8		u8SelfTestFlag = 0;
u8		u8CurRevByte=0;
u8		u8CurRevBit = 0;
u8		u8CurRev500usCnt = 0;
u16		u16DoorOpen1s = 0;

u8		u8Comm1sCnt=0;
u8		u8receivedCnt=0;

u8		u8CommSendStep = 0;
u8		u8CommRevStep = 0;

#define		LEAD				1
#define		DATA				2


#define		LEAD_LOW		1
#define		LEAD_HIGH		2
#define		DATA_LOW		3
#define		DATA_HIGH		4

u8		u8MainBoardOutput=0;

u8		TxBuf[TOTAL_TX_BYTE];
u8		RxBuf[TOTAL_RX_BYTE];
u8		u8BCDType;
u8		u8CmpCOntinueRunTim=0;
u8		u8commStatus;
u8		u8NoRxIn0_5Cnt = 0;
u8		u8ResendCnt = 0;
u8	u8CommErr = 0;

u16	u16PwrOnFlashH0_5sCnt;

const u8 BitMap[8] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};


//-----------------------------------------------------------------------
void		fillTxBuf(void);
void	GetMainBoardInfo(void);
void TxSendData(void);
//-----------------------------------------------------------------------
void initTxRx(void)
{
		GPIO_Init(TxRxPort, TX, GPIO_MODE_OUT_PP_LOW_SLOW);
		GPIO_Init(TxRxPort, RX, GPIO_MODE_IN_PU_IT);	//开接收中断
		EXTI_SetExtIntSensitivity(ExtiRxPort, EXTI_SENSITIVITY_RISE_ONLY);
		EXTI_SetTLISensitivity(EXTI_TLISENSITIVITY_RISE_ONLY);
}

void	resetTim4For500us(void)
{
		TIM4_DeInit();
		TIM4_TimeBaseInit(TIM4_PRESCALER_32,250); 
		TIM4_ITConfig(TIM4_IT_UPDATE,ENABLE);
		TIM4_ARRPreloadConfig(ENABLE);
		TIM4_Cmd(ENABLE);	 
}

void stopTim4(void)
{
		TIM4_ITConfig(TIM4_IT_UPDATE,DISABLE);
		TIM4_Cmd(DISABLE);
}

void	commSend(void)
{
		fillTxBuf();
		TxSendData();
}

//u8 u8Int100usCnt;

@far @interrupt void EXTI_PORTD_IRQHandler(void)
{
//		u8NoRxIn0_5Cnt = 0;
		u8 i;
		for(i=0;i<80;i++)
		{
			if((GPIO_ReadInputData(TxRxPort)&RX)==0)  return;
		}
		
		switch( u8CommRevStep )
		{
				case 0:
						u8CommRevStep = LEAD;
						resetTim4For500us();
						break;

				case LEAD:
						if( (u8CurRev500usCnt>28)&& (u8CurRev500usCnt<36) )
						{
								u8CommRevStep = DATA;
								u8CurRevByte = 0;
								u8CurRevBit = 0;
								memset(RxBuf,0,TOTAL_RX_BYTE);								
						}
						else u8CommRevStep = 0;
						break;

				case DATA:
						if(  (u8CurRev500usCnt>10) )	//(u8CurRev125usCnt<2) ||
						{
								u8CommRevStep = 0;
						}
						else
						{
								if(u8CurRev500usCnt>5)	 RxBuf[u8CurRevByte]	 |= BitMap[u8CurRevBit];
								u8CurRevBit++;
								if(u8CurRevBit>7) 
								{
										u8CurRevBit = 0;
										u8CurRevByte++;
								}
								if( u8CurRevByte>= TOTAL_RX_BYTE )
								{
										GPIO_Init(TxRxPort, RX, GPIO_MODE_IN_FL_NO_IT);	// 关中断
										u8commStatus = 0;
										fgReceived = 1;
										u8CommRevStep = 0;
								}
						}
						break;

				default:
						u8CommRevStep = 0;
						break;
						
		}
		u8CurRev500usCnt = 0;

		if( u8CommRevStep == 0)
		{
				stopTim4();
				fgReceiving = 0;
		}
		else
		{
				fgReceiving = 1;
		}
}

	

@far @interrupt void TIM4_UPD_OVF_IRQHandler(void)
{
		TIM4_ClearITPendingBit(TIM4_IT_UPDATE);	

		if(u8CommSendStep != 0)
		{
				if(u8CurSend500usCnt<200) u8CurSend500usCnt++;
				switch(u8CommSendStep)
				{
						case LEAD_LOW:
									if( u8CurSend500usCnt >= 12 )
									{
											u8CommSendStep = LEAD_HIGH;
											u8CurSend500usCnt = 0;
											GPIO_WriteLow(TxRxPort,TX);
									}
									else GPIO_WriteHigh(TxRxPort,TX);
									break;
						case LEAD_HIGH:
									if( u8CurSend500usCnt >= 20 )
									{
											u8CommSendStep = DATA_LOW;
											u8CurSend500usCnt = 0;
											GPIO_WriteHigh(TxRxPort,TX);
									}
									else GPIO_WriteLow(TxRxPort,TX);
									break;
						case DATA_LOW:
									if(u8CurSend500usCnt<2) return;
									GPIO_WriteLow(TxRxPort,TX);
									u8CurSend500usCnt = 0;
									if(u8CurSendByte>=TOTAL_TX_BYTE)
									{
											stopTim4();
											GPIO_Init(TxRxPort, RX, GPIO_MODE_IN_PU_IT);	//开接收中断
											u8CommSendStep = 0;
											u8commStatus = 0;
											return;
									}									
									else u8CommSendStep = DATA_HIGH;
									break;
						case DATA_HIGH:
									if(u8CurSend500usCnt >= 2)
									{
											if( ((TxBuf[u8CurSendByte] & BitMap[u8CurSendBit]) == 0 ) || (u8CurSend500usCnt>=6) )
											{
													GPIO_WriteHigh(TxRxPort,TX);
													u8CommSendStep = DATA_LOW;
													u8CurSend500usCnt = 0;
													u8CurSendBit++;
													if(u8CurSendBit>7)
													{
															u8CurSendBit = 0;
															u8CurSendByte++;
													}
											}
											else GPIO_WriteLow(TxRxPort,TX);
									}
									else GPIO_WriteLow(TxRxPort,TX);
									break;
				}
//				resetTim4For500us();	 
		}
		else	if( u8CommRevStep != 0)
		{
				u8CurRev500usCnt++;
				if(u8CurRev500usCnt>50)
				{
					u8CommRevStep = 0;
				}
//			resetTim4For500us(); 
		}
		else stopTim4();
}



void		fillTxBuf(void)
{
		u8	 i,temp;
//		clrTxBuf();
		memset(TxBuf,0,TOTAL_TX_BYTE);
		TxBuf[0] =	0x5a;
		TxBuf[1] =	u8LCUserSetTmp;
		TxBuf[2] =	u8BWUserSetTmp;
		TxBuf[3] =	u8LDUserSetTmp;
		TxBuf[4] =	u8Temp;
		TxBuf[5] =	u8Mode;
		
		if(u8SelfTestFlag==1)
		{
			TxBuf[6] = 0x10;
		}

		TxBuf[7]	=	u8ForceOff;
#ifdef _SCALE_MODE_	
		if(u8scaleTimFlag != 0) TxBuf[7] |= 0x80;
#endif			
		
		for(i=0,temp=0;i<(TOTAL_TX_BYTE-1);i++)	temp +=	TxBuf[i];
		TxBuf[TOTAL_TX_BYTE-1] =	temp;
}


void commRevTask(void)
{
		u8	 i,temp;
		if(	fgReceived )
		{
				u8commStatus = 0;
				for(i=0,temp=0;i<(TOTAL_RX_BYTE-1);i++)	temp +=	RxBuf[i];
				if( (temp == RxBuf[TOTAL_RX_BYTE-1])	&& (RxBuf[0] == 0x5a) )
				{
					GetMainBoardInfo();
					delay(30);
					commSend();
				}
				else
				{
					GPIO_Init(TxRxPort, RX, GPIO_MODE_IN_PU_IT);	//开接收中断				
				}
		}
}

void TxSendData(void)
{
//		if( (u8OutState&BuzWork) == BuzWork) return;
		u8commStatus = 0;
		fgSending = 1;
		u8CurSendByte = 0;
		u8CurSendBit = 0;
		u8CurSend500usCnt = 0;
		u8CommSendStep = LEAD_LOW;
		GPIO_WriteHigh(TxRxPort,TX);
		GPIO_Init(TxRxPort, RX, GPIO_MODE_IN_FL_NO_IT);
//		u8CurRevByte = 0;
//		u8CurRevBit = 0;
		u8CommRevStep = 0;
		resetTim4For500us();		
}

void	RxTimeTask(void)
{
	if( (++u8NoRxIn0_5Cnt) > 40 )
	{
		u8NoRxIn0_5Cnt = 0;
		fgCommPannelErr = 1;
		u8AlarmFlag &= (u8)(~(DOOR_OPEN_ALARM|LD_HIGH_ALARM));
	}
	if( u8CommSendStep == 0 ) //(u8commStatus&((u8)(~SENDING)))
	{
		GPIO_Init(TxRxPort, TX, GPIO_MODE_OUT_PP_LOW_SLOW);
	}
}

u8	u8PowerOnGetUserSetFormMainBoard=0;

void	GetMainBoardInfo(void)
{
		u8	u8Tmp;
		u8NoRxIn0_5Cnt = 0;
		u8commStatus = 0;
		fgCommPannelErr = 0;
		u8ResendCnt = 0;
		u8LCSnrTemp			=	RxBuf[1];
		u8BWSnrTemp			=	RxBuf[2];
		u8LDSnrTemp			=	RxBuf[3];
		u8LCHSSnrTemp		=	RxBuf[4];
		if((RxBuf[11]&0x03)==0x03)	u8BWHSSnrTemp	=	OFF_TMP_SET;
		else	u8BWHSSnrTemp = 0;
//		u8BWHSSnrTemp = RxBuf[11];
		
		if(u8PowerOnGetUserSetFormMainBoard==0)
		{
			u8LCUserSetTmp	=	RxBuf[7];
			u8BWUserSetTmp	=	RxBuf[8];
			u8LDUserSetTmp	=	RxBuf[9];
			
			if( (u8LCSnrTemp != OFF_TMP_SET) && (u8LDSnrTemp != OFF_TMP_SET) )
			{
				if(u8LCSnrTemp>u8LDSnrTemp) u8Tmp = u8LCSnrTemp - u8LDSnrTemp;
				else u8Tmp = u8LDSnrTemp - u8LCSnrTemp;
				if(u8Tmp<6)
				{
					u8AlarmFlag |= PWRON_FLASH_H;
				}
				else
				{
					u8AlarmFlag &= (u8)(~PWRON_FLASH_H);
				}
				u16PwrOnFlashH0_5sCnt = 0;
			}
			
			u8Mode = RxBuf[5];	
			u8ForceOff &= (u8)(~(LC_FORCE_OFF|BW_FORCE_OFF));
			if( (RxBuf[10]&0x02)==0x02 ) u8ForceOff |= LC_FORCE_OFF;
			if( (RxBuf[10]&0x01)==0x01 ) u8ForceOff |= BW_FORCE_OFF;
		
			u8ModeBak=u8Mode;
			u8ForceOffBak=u8ForceOff;
			u8LCUserSetTmpBak=u8LCUserSetTmp;
			u8BWUserSetTmpBak=u8BWUserSetTmp;
			u8LDUserSetTmpBak=u8LDUserSetTmp;			
			
			
			u8PowerOnGetUserSetFormMainBoard = 1;
		}
		else
		{
				if( (u8MainBoardOutput&LC_DOOR_OPEN) != (RxBuf[6]&LC_DOOR_OPEN) )
				{
//						buz(BZR_DOWN_3);
//						u8MainBoardOutput	=	RxBuf[6];
//?					if( (RxBuf[6]&LC_DOOR_OPEN)==0)
						u8LedTime = TO_OFF_LED_TIM;
						updateLed(0);
				}
				if( (u8AlarmFlag&PWRON_FLASH_H)==PWRON_FLASH_H)
				{
					if( (u8LCSnrTemp == OFF_TMP_SET) || (u8LDSnrTemp == OFF_TMP_SET) ) u8AlarmFlag &= (u8)(~PWRON_FLASH_H);
					if(u8LCSnrTemp>u8LDSnrTemp) u8Tmp = u8LCSnrTemp - u8LDSnrTemp;
					else u8Tmp = u8LDSnrTemp - u8LCSnrTemp;
					if(u8Tmp>=6)
					{
						u8AlarmFlag &= (u8)(~PWRON_FLASH_H);
					}
				}
		}
		u8MainBoardOutput	=	RxBuf[6];
		if( (RxBuf[11]&0x01) == 0x01)
		{
			if( (RxBuf[11]&0xe1) == 0x21)
			{
				u8BWMaxSetTemp = C0;
				u8BWMinSetTemp = C0-14;
				u8BCDType = _BCD_220_;
			}
			else
			{
				u8BWMaxSetTemp = C0+20;
				u8BWMinSetTemp = C0-24;	
				u8BCDType = _BCD_260_;			
			}
		}

		if( (u8Mode ==FAST_COOL_MODE) || (u8Mode ==FAST_FREEZE_MODE))
		{
				u8CmpCOntinueRunTim = 0;
				u8AlarmFlag &= (u8)(~LD_HIGH_ALARM);
		}
//		else if( (u8MainBoardOutput&CMP_RUNING) == 0) 20120209
		{
//				u8CmpCOntinueRunTim = 0;
//				u8AlarmFlag &= (u8)(~LD_HIGH_ALARM); 
		}
				
		if( (u8MainBoardOutput&LC_DOOR_OPEN) == 0)
		{
			u16DoorOpen1s = 0;
			u8AlarmFlag &= (u8)(~(DOOR_OPEN_ALARM));
		}

		if( (RxBuf[10]&0xf0)==0x30 )
		{
			u8OutState |= FactoryTest;
		}
		else
		{
			u8OutState &= (~FactoryTest)&0xff;
			u8ForceOff &= (u8)(~OUT_FACT_TEST);
		}
}


