//---------------------------------------------------------------------------
// hodgen-china
// key.c
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

//#include "stm8s_flash.h"
#include "include.h"

u8		u8KeyPressTime0_5s	=	0;
u8		u8KeyEvent = 0;
u8 		u8KeyValue;
u8 	 u8Mode =	0; //INTELLIGENT_MODE;
u8	 u8LCUserSetTmp = 0;
u8	 u8BWUserSetTmp = 0;
u8 	 u8LDUserSetTmp = 0;
//u8	 u8LCsetTmpBak;
//u8	 u8BWsetTmpBak;
//u8	 u8LDsetTmpBak;
u16	 u16FastFreezeMin;
u8	 u8LCTotalRunTime0_5Hour = 0;
u8	u8KeyCnt = 0;

#define KEY_MAX_CNT 10

void setKeyValue(void);

void initKey(void)
{
    GPIO_Init(GPIOA, (GPIO_PIN_1 | GPIO_PIN_2), GPIO_MODE_IN_PU_NO_IT  );
    GPIO_Init(GPIOB, (GPIO_PIN_4 | GPIO_PIN_5), GPIO_MODE_IN_PU_NO_IT  );
    GPIO_Init(GPIOC, (GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5), GPIO_MODE_IN_PU_NO_IT  );
    GPIO_Init(LD_KEY_PORT, LD_KEY, GPIO_MODE_IN_PU_NO_IT  );
}

void delay(u16 time)
{
    u16 j;
    u16 i = time;
    for(; i > 0; i--)
    {
        for(j = 10; j > 0; j--) IWDG_ReloadCounter();
    }
}


u8 allKeyUp(void)
{
    if(  ( GPIO_ReadInputData(GPIOA) &(GPIO_PIN_1 | GPIO_PIN_2) ) != (GPIO_PIN_1 | GPIO_PIN_2) )
    {
        if(u8KeyCnt < KEY_MAX_CNT) u8KeyCnt++;
    }
    else if(  ( GPIO_ReadInputData(GPIOB) &(GPIO_PIN_4 | GPIO_PIN_5) ) != (GPIO_PIN_4 | GPIO_PIN_5) )
    {
        if(u8KeyCnt < KEY_MAX_CNT) u8KeyCnt++;
    }
    else if(  ( GPIO_ReadInputData(GPIOC) &(GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5) ) != (GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5) )
    {
        if(u8KeyCnt < KEY_MAX_CNT) u8KeyCnt++;
    }
    else if(  ( GPIO_ReadInputData(LD_KEY_PORT) &(LD_KEY) ) != (LD_KEY) )
    {
        if(u8KeyCnt < KEY_MAX_CNT) u8KeyCnt++;
    }
    else if(u8KeyCnt > 0) u8KeyCnt--;
    return u8KeyCnt;
}

void keyScan(void)
{
    u8  u8OldKeyValue;
    if( fgKeyPress )
    {
        if(allKeyUp() == 0 )
        {
            u8KeyEvent = 0;
            if( !fgKeyLongPress ) fgKeyUp = 1;
        }
        else
        {
            if(u8KeyCnt == KEY_MAX_CNT)
            {
                u8OldKeyValue = u8KeyValue;
                setKeyValue();
                if(u8OldKeyValue != u8KeyValue)
                {
                    fgKeyLongPress = 0;
                    u8KeyPressTime0_5s = 0;
                }
            }
        }
        return;
    }
    else
    {
        if( allKeyUp() != KEY_MAX_CNT) return;
        fgKeyPress = 1;
        fgKeyDown	 = 1;
        u8KeyPressTime0_5s = 0;
        setKeyValue();
    }
}


void setKeyValue(void)
{
    u8KeyValue = 0;
#ifdef	NEW_260
    if( (GPIO_ReadInputData(GPIOA)&GPIO_PIN_1) == 0) u8KeyValue |= ADD_BW_KEY;
    if( (GPIO_ReadInputData(GPIOA)&GPIO_PIN_2) == 0) u8KeyValue |= ADD_LC_KEY;
    if( (GPIO_ReadInputData(GPIOD)&GPIO_PIN_3) == 0) u8KeyValue |= SUB_LC_KEY;
    if( (GPIO_ReadInputData(GPIOB)&GPIO_PIN_4) == 0) u8KeyValue |= MODE_KEY;
    if( (GPIO_ReadInputData(GPIOB)&GPIO_PIN_5) == 0) u8KeyValue |= ADD_LD_KEY;
    if( (GPIO_ReadInputData(GPIOC)&GPIO_PIN_3) == 0) u8KeyValue |= UNLOCK_KEY;
    if( (GPIO_ReadInputData(GPIOC)&GPIO_PIN_4) == 0) u8KeyValue |= SUB_LD_KEY;
    if( (GPIO_ReadInputData(GPIOC)&GPIO_PIN_5) == 0) u8KeyValue |= SUB_BW_KEY;
#else
    if( (GPIO_ReadInputData(GPIOA)&GPIO_PIN_1) == 0) u8KeyValue |= SUB_LC_KEY;
    if( (GPIO_ReadInputData(GPIOA)&GPIO_PIN_2) == 0) u8KeyValue |= SUB_BW_KEY;
    if( (GPIO_ReadInputData(LD_KEY_PORT)&LD_KEY) == 0) u8KeyValue |= SUB_LD_KEY;
    if( (GPIO_ReadInputData(GPIOB)&GPIO_PIN_4) == 0) u8KeyValue |= ADD_BW_KEY;
    if( (GPIO_ReadInputData(GPIOB)&GPIO_PIN_5) == 0) u8KeyValue |= ADD_LC_KEY;
    if( (GPIO_ReadInputData(GPIOC)&GPIO_PIN_3) == 0) u8KeyValue |= ADD_LD_KEY;
    if( (GPIO_ReadInputData(GPIOC)&GPIO_PIN_4) == 0) u8KeyValue |= UNLOCK_KEY;
    if( (GPIO_ReadInputData(GPIOC)&GPIO_PIN_5) == 0) u8KeyValue |= MODE_KEY;
#endif
    if( u8KeyValue == 0 ) u8KeyEvent = 0;
}


