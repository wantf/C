//---------------------------------------------------------------------------
// hodgen-china
// buz.h
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
#include "stm8s_tim2.h"



u8 u8OutState=0;
u8	u8BzrFrqBuf=0;
u8	u8BzrOn5MSCnt=0;
u8	u8BzrOff5MSCnt=0;
u8	u8BzrType=0;
u8	u8BuzStep=0;
u8 	u8BzrLastTim=0;

const u8	u16BuzSeqTab[2][4] =
{
	{BZR_FREQ_B, BZR_FREQ_C, BZR_FREQ_D, BZR_OFF_SIGN},
	{BZR_FREQ_E, BZR_FREQ_D, BZR_FREQ_B, BZR_OFF_SIGN},
};

const u8	u8SingleFrq[5] =
{
	BZR_FREQ_A, BZR_FREQ_B, BZR_FREQ_C,BZR_FREQ_D,BZR_FREQ_A,
};

void initBuz(void)
{
		InitBuzzerPwrPort();
		InitBuzzerPort();
/*
		ITC_DeInit();
		ITC->ISPR1 = 0x55;
		ITC->ISPR2 = 0x45;	//exti portd level 2
		ITC->ISPR3 = 0x55;
		ITC->ISPR4 = 0x5d;	//time2 interrupt level 3,other level 1
		ITC->ISPR5 = 0x55;
		ITC->ISPR6 = 0x15;	//timer4 level 2
		ITC->ISPR7 = 0x55;		  
*/
}

void BuzzerStart(void)
{
/*
		TIM2_DeInit();
		TIM2_TimeBaseInit(TIM2_PRESCALER_16,u8BzrFrqBuf);
		TIM2_ARRPreloadConfig(ENABLE);
		TIM2_Cmd(ENABLE);
		TIM2_ITConfig(TIM2_IT_UPDATE,ENABLE);
*/
		TIM2_DeInit(); 
		TIM2_TimeBaseInit(TIM2_PRESCALER_16,u8BzrFrqBuf ); 
#ifdef	NEW_260		
		TIM2_CCxCmd(TIM2_CHANNEL_3, ENABLE); 
		TIM2_OC3Init(TIM2_OCMODE_TOGGLE, TIM2_OUTPUTSTATE_ENABLE, 64, TIM2_OCPOLARITY_LOW); 
		TIM2_OC3PreloadConfig(ENABLE); 
#else
		TIM2_CCxCmd(TIM2_CHANNEL_2, ENABLE); 
		TIM2_OC2Init(TIM2_OCMODE_TOGGLE, TIM2_OUTPUTSTATE_ENABLE, 64, TIM2_OCPOLARITY_LOW); 
		TIM2_OC2PreloadConfig(ENABLE);
#endif
		TIM2_ARRPreloadConfig(ENABLE); 
		TIM2_ITConfig(TIM2_IT_CC1, DISABLE); 
		TIM2_ITConfig(TIM2_IT_CC2, DISABLE); 
		TIM2_ITConfig(TIM2_IT_CC3, DISABLE); 
		TIM2_ITConfig(TIM2_IT_UPDATE, DISABLE); 
		TIM2_GenerateEvent(TIM2_EVENTSOURCE_UPDATE); 
		TIM2_Cmd(ENABLE);

		SetBuzzerEnOn();
}

void BuzzerStop(void)
{
		TIM2_Cmd(DISABLE);
//		TIM2_ITConfig(TIM2_IT_UPDATE,DISABLE);
		SetBuzzerEnOff();
		u8BzrFrqBuf = 0;
		u8OutState  &= (u8)(~BuzWork);
		u8BzrOn5MSCnt = 0;
		u8BzrOff5MSCnt = 0;
		
}

void buz(u8 buzIndex)
{
//	return;
		if( ((u8OutState&BuzWork)==BuzWork) && (buzIndex>BZR_DOWN_3)&& (u8BzrType<=BZR_DOWN_3) ) return;
		u8BzrType = buzIndex;
		u8BuzStep = 0;		
		u8OutState |= BuzWork;
		if( u8BzrType <= BZR_DOWN_3 )	u8BzrFrqBuf = u16BuzSeqTab[u8BzrType-1][u8BuzStep];
		else u8BzrFrqBuf = u8SingleFrq[u8BzrType-BZR_A];

		u8BzrOn5MSCnt = BZR_Time_40ms;
		u8BzrOff5MSCnt = BZR_Time_75ms;

		u8BzrLastTim = BZR_OFF_LST_1s25;
		BuzzerStart();
}

//called in 5ms interrupt
void Buzzer5MSTask(void)
{
		if( (u8OutState&BuzWork) == 0) 
		{
				return;
		}
		if( u8BzrOn5MSCnt>0 )	u8BzrOn5MSCnt--;
		else
		{
				SetBuzzerEnOff();
				if( u8BzrOff5MSCnt>0 )u8BzrOff5MSCnt--;
				else if( u8BzrType<=BZR_DOWN_3 )
				{
						u8BzrFrqBuf = u16BuzSeqTab[u8BzrType-1][u8BuzStep+1];
						if(u8BzrFrqBuf != BZR_OFF_SIGN)
						{
								u8BuzStep++;

								u8BzrOn5MSCnt = BZR_Time_50ms;
								u8BzrOff5MSCnt = BZR_Time_75ms;
								BuzzerStart();
						}
						else if( u8BzrLastTim>0 )	u8BzrLastTim--;
						else	BuzzerStop();						
				}
				else if( u8BzrLastTim>0 )	u8BzrLastTim--;
				else	BuzzerStop();
		}
}

@far @interrupt void TIM2_UPD_OVF_BRK_IRQHandler(void)
{
//		TIM2_ClearITPendingBit(TIM2_IT_UPDATE);
//		GPIO_WriteReverse(BUZZER_PORT,BUZZER);
}