//---------------------------------------------------------------------------
// hodgen-china
// AD.C
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
#include "stm8s_adc1.h"
#include "T3839_T3850.h"

/* Exported types ------------------------------------------------------------*/
u8 u8Temp;
u8 u8TempErr;
u8	u8LCSnrTemp;
u8	u8LCHSSnrTemp;
u8	u8BWSnrTemp;
u8	u8BWHSSnrTemp;
u8	u8LDSnrTemp;

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
#define SAMPLE_TIMES 4

/* Exported functions ------------------------------------------------------- */
void initAD(void)
{
		u8 i;
		GPIO_Init(GPIOD, GPIO_PIN_2, GPIO_MODE_IN_FL_NO_IT);		
		for(i=0;i<SAMPLE_TIMES;i++) ADSample();
}

/*called per 4ms*/
u16 Conversion_Value = 0;
u8 u8ADChannelCnt=0;

void ADSample(void)
{
		u8	i,tttemp;
    ADC1_DeInit();
    ADC1_ConversionConfig(ADC1_CONVERSIONMODE_SINGLE, ADC1_CHANNEL_3, ADC1_ALIGN_RIGHT);
    ADC1_SchmittTriggerConfig(ADC1_SCHMITTTRIG_CHANNEL4,ENABLE);
    ADC1_ITConfig(ADC1_IT_EOCIE,DISABLE);
		ADC1_Cmd(ENABLE);
		ADC1->CSR &= (u8)(~0x80);
		ADC1_StartConversion();		
    while((ADC1->CSR & 0x80)!=0x80) IWDG_ReloadCounter(); // µÈ´ý×ª»»½áÊø
    Conversion_Value += ADC1_GetConversionValue();
		ADC1->CSR &= (u8)(~0x80);
		u8ADChannelCnt++;
		if(u8ADChannelCnt>=SAMPLE_TIMES)
		{
				u8ADChannelCnt = 0;
				tttemp = (u8)((Conversion_Value>>2)/SAMPLE_TIMES);
				if((tttemp<20) || (tttemp>200) ) u8Temp = OFF_TMP_SET;
				else
				{
						for(i=0;T3580Tab[i]<tttemp;i++);
						u8Temp = (u8)(i+(40*2));
				}
				Conversion_Value = 0;
		}
}




@far @interrupt void ADC1_IRQHandler(void)
{
}


