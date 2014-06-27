//---------------------------------------------------------------------------
// hodgen-china
// pt6964.c
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

u8	u8SelfTestStep=0;
u8	u8SelfTestDispStep=0;

u8 dispBuf[14];

#define setLCOFF()		(dispBuf[0]|=0x02)
#define clrLCOFF()		(dispBuf[0]&=0xfd)

#define setLCIcon()		(dispBuf[2]|=0x03)
#define clrLCIcon()		(dispBuf[2]&=0xfc)

#define setBWOFF()		(dispBuf[4]|=0x02)
#define clrBWOFF()		(dispBuf[4]&=0xfd)

#define	 setBWNeg()		(dispBuf[4]|=0x01)
#define	 clrBWNeg()		(dispBuf[4]&=0xfe)

#define setBWIcon()		(dispBuf[6]|=0x03)
#define clrBWIcon()		(dispBuf[6]&=0xfc)

#define setLDHour()		(dispBuf[8]|=0x02)
#define clrLDHour()		(dispBuf[8]&=0xfd)

#define	 setLDNeg()		(dispBuf[8]|=0x01)
#define	 clrLDNeg()		(dispBuf[8]&=0xfe)

#define setLDIcon()		(dispBuf[10]|=0x03)
#define clrLDIcon()		(dispBuf[10]&=0xfc)

#define setLockAddDisp()	(dispBuf[1]|=0x02)
#define clrLockAddDisp()	(dispBuf[1]&=0xfd)

void	setSMGDot(u8 dot);
void setDispBuf(u8 data);

void		setModeDisp(u8 mode)
{
		switch(mode)
		{
				case FAST_COOL_MODE:
				{
						dispBuf[12]	= (dispBuf[12]&0x01)|0x10;	//e7
						dispBuf[13]	|= 0x01;	//a7
						break;
				}
				case FAST_FREEZE_MODE:
				{
						dispBuf[12]	=  (dispBuf[12]&0x01)|0x88;	//B7 F7
						dispBuf[13]	&= 0xFE;	//a7						
						break;
				}
				case INTELLIGENT_MODE:
				{
						dispBuf[12]	=  (dispBuf[12]&0x01)|0x44;	//c7 g7
						dispBuf[13]	&= 0xFE;	//a7	
						break;
				}
				case HOLIDAY_MODE:
				{
						dispBuf[12]	=  (dispBuf[12]&0x01)|0x22;	//d7 h7
						dispBuf[13]	&= 0xFE;	//a7	
						break;
				}
				default:
				{
						dispBuf[12] = (dispBuf[12]&0x01);
						dispBuf[13]	&= 0xFE;
						break;
				}
		}
}



#define	underZero	 16
#define allOff		 18

const u8 Disp_Tab[] = 
{
	0xfc,		//0
	0x60,	//1
	0xda,	//2
	0xf2,		//3
	0x66,	//4
	0xb6,	//5
	0xbe,	//6
	0xe0,	//7
	0xfe,		//8
	0xf6,		//9
	0xee,	//A
	0x0a,	//r
	0x6e,	//H		//0x1a,	//c
	0x7a,	//d
	0x9e,	//E
	0x8e,	//F
	0x02,	//-
	0xce,	//P
	0x00		//all off
};

#define	BRIGHT_LIGHT	0x8f
#define	BRIGHT_DARK		0x80

//const u8 Brigh_Tab[9] = {0x80,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f};

void WriteData(u8 Value)
{
	u8 i;

	for(i=0;i<8;i++)
	{
		if(Value & 0x01)
			PT6964_DIN_H;
		else
			PT6964_DIN_L;

		PT6964_CLK_L;
		PT6964_CLK_H;
		Value >>= 1;
	}
}
//--------------------------------------------------------------------------
// Write_Adr_Data to LCM
//--------------------------------------------------------------------------
void Write_Adr_Data(u8 addr, u8 value) 
{
	PT6964_STB_L;
	WriteData(0x44);
	PT6964_STB_H;

	PT6964_STB_L;
	WriteData(addr|0xc0);
	WriteData(value);
	PT6964_STB_H;
}
//--------------------------------------------------------------------------
// PT6964_Init
//--------------------------------------------------------------------------
void PT6964_Init(void)
{
//	u8	 Led_Brigh;
	GPIO_Init(PT6964_CLK_PORT,PT6964_CLK, GPIO_MODE_OUT_PP_HIGH_FAST);
	GPIO_Init(PT6964_DATA_PORT,PT6964_DOUT, GPIO_MODE_OUT_PP_HIGH_FAST);
	GPIO_Init(PT6964_STB_PORT,PT6964_STB, GPIO_MODE_OUT_PP_HIGH_SLOW);

    PT6964_STB_H;					//Initial state
    PT6964_CLK_H;					//Intial state
//	Delay10ms();				//delay 200ms
	
//	writeBufTo6964();

	PT6964_STB_L;
	WriteData(0x03);			//7 digit
	PT6964_STB_H;

	PT6964_STB_L;
	WriteData(BRIGHT_LIGHT);		//(Brigh_Tab[Led_Brigh]);			//Command 3, Display ON
	PT6964_STB_H;
}
//--------------------------------------------------------------------------
// FP_Get_Key 
//--------------------------------------------------------------------------
/*
u8 FP_Get_Key(void)
{
	u8 i,value=0;

	PT6964_STB_L;
	WriteData(0x42);
    PT6964_DOUT=1;

	for(i=0;i<40;i++)
	{
		PT6964_CLK_L;
        _nop_();
		_nop_();
		PT6964_CLK_H;

		value ++;
        _nop_();
		_nop_();
		if(PT6964_DOUT==1)
		{
			PT6964_STB_H;
			return(value);
		}
	}
	PT6964_STB_H;
	value=0;
	return(value);
}
*/
void Change_Bright(u8 Led_Brigh)
{
	PT6964_STB_L;
	WriteData(0x44);
	PT6964_STB_H;

	PT6964_STB_L;
	WriteData(0x03);			//7 digit
	PT6964_STB_H;

	PT6964_STB_L;
	WriteData(BRIGHT_LIGHT);	//(Brigh_Tab[Led_Brigh]);			//Command 3, Display ON

	PT6964_STB_H;
}


//--------------------------------------------------------------------------
//whichSMG 1 to  6
// data = 0 to 9 ,10(P) 11(b) to 15(F),16(-)
//--------------------------------------------------------------------------
void changeSMGdata(u8 whichSMG,u8 data)
{
		u8 temp,temp1,addr;
		if( (whichSMG<1) || (whichSMG>6) ) return;
		if(data>18) return;
		temp = Disp_Tab[data];
		temp1 = ((temp<<1)&0xfc);	//s3~s8
		addr = ((whichSMG -1)<<1)&0xfe;
		dispBuf[addr] = (dispBuf[addr]&0x03)|temp1;
		addr++;
		dispBuf[addr] = (dispBuf[addr]&0xfe)|((temp>>7)&0x01);	//s9
}

void	writeBufTo6964(void)
{
	u8 i;

  PT6964_STB_H;					//Initial state
  PT6964_CLK_H;					//Intial state
			
	PT6964_STB_L;
	WriteData(0x40);			//Command 1, increment address
	PT6964_STB_H;

	PT6964_STB_L;
	WriteData(0xc0);			//Command 2, RAM address = 0
	for(i=0;i<=0x0D;i++) WriteData(dispBuf[i]);
	PT6964_STB_H;
}

void	updateLed(u8 ledOff)
{
		u8	u8LCtmpDisp;
		u8	u8BWtmpDisp;
		u8	u8LDtmpDisp;

		if(u8SelfTestFlag!=0) return;

		PT6964_Init();
		setDispBuf(0);
		
		if( (u8LCSnrTemp==OFF_TMP_SET)||(u8BWSnrTemp==OFF_TMP_SET)||(u8LDSnrTemp == OFF_TMP_SET)||(fgCommPannelErr) )
		{
				ledOff = 0;
		}
		else if( (u8MainBoardOutput&LC_DOOR_OPEN)==LC_DOOR_OPEN ) ledOff = 0;
		else if( (u8AlarmFlag&(LD_HIGH_ALARM|PWRON_FLASH_H))!=0 ) ledOff = 0;
		else if( fgKeyPress ) ledOff = 0;

		if(u8LockStatus != 0)
		{
			if(u8LockFlashTim>0)
			{
				if( (u8TimeFlag&Tim0_5Flash) == Tim0_5Flash)
				{
					setLockAddDisp();
				}
			}
			else if(u8LockOn0_5Cnt>0)
			{
				setLockAddDisp();
			}
		}
		if(ledOff == 1)
		{
			writeBufTo6964();
			return;
		}
		if( (u8LockFlashTim==0)&&(u8LockStatus != 0) ) setLockAddDisp();

		if( (u8AlarmFlag&DOOR_OPEN_ALARM) == DOOR_OPEN_ALARM )
		{
			if( (u8TimeFlag&Tim0_5Flash)==Tim0_5Flash )
			{
				clrLCOFF();
				changeSMGdata(1,13);		//d
				changeSMGdata(2,11);		//r		
			}
		}
		else if( (u8LCSnrTemp == OFF_TMP_SET) )	//E1 && (u8LCHSSnrTemp == OFF_TMP_SET)
		{
				setLCIcon();
				if((u8TimeFlag&Tim0_5Flash)==Tim0_5Flash)
				{
					changeSMGdata(1,0x0e);
					changeSMGdata(2,1);
				}
		}		
		else if( ( (u8AlarmFlag&PWRON_FLASH_H)==PWRON_FLASH_H ) && (u8FlashTim==0) )
		{
			if( (u16PwrOnFlashH0_5sCnt>10) || ((u8TimeFlag&Tim0_5Flash)==Tim0_5Flash) )
			{
				changeSMGdata(1,SMG_OFF);
				changeSMGdata(2,12);				
			}
			setLCIcon();
		}
		else
		{
				if( fgKeyDispTemp )
				{
					clrLCOFF();
					if((u8TimeFlag&Tim0_5Flash_Temp)==Tim0_5Flash_Temp)
					{
						clrLCIcon();
						if(u8LCHSSnrTemp>=C0)
						{
							u8LCtmpDisp = ((u8LCHSSnrTemp - C0)>>1)&0xff;
							changeSMGdata(1,u8LCtmpDisp/10);	//LC
							changeSMGdata(2,u8LCtmpDisp%10);							
						}
						else
						{
							u8LCtmpDisp = ((C0-u8LCHSSnrTemp)>>1)&0xff;
							if(u8LCtmpDisp>9) u8LCtmpDisp = 9;
							changeSMGdata(1,16);	//-
							changeSMGdata(2,u8LCtmpDisp);							
						}						
					}
					else
					{
						setLCIcon();
						if(u8LCSnrTemp>=C0)
						{
							u8LCtmpDisp = ((u8LCSnrTemp - C0)>>1)&0xff;
							changeSMGdata(1,u8LCtmpDisp/10);	//LC
							changeSMGdata(2,u8LCtmpDisp%10);							
						}
						else
						{
							u8LCtmpDisp = ((C0-u8LCSnrTemp)>>1)&0xff;
							if(u8LCtmpDisp>9) u8LCtmpDisp = 9;
							changeSMGdata(1,16);	//-
							changeSMGdata(2,u8LCtmpDisp);							
						}
					}
				}
				else
				{
					setLCIcon();
					if( (u8ForceOff&LC_FORCE_OFF)==LC_FORCE_OFF )
					{
							changeSMGdata(1,SMG_OFF);
							changeSMGdata(2,SMG_OFF);
							setLCOFF();
					}
					else
					{
							clrLCOFF();
							if(u8ModeBak == FAST_COOL_MODE) u8LCtmpDisp = 2;	//速冷模式下按照设定温度2度
							else u8LCtmpDisp = ((u8LCUserSetTmpBak - C0)>>1)&0xff;
							changeSMGdata(1,0);	//LC
							changeSMGdata(2,u8LCtmpDisp);				
					}
				}
		}

		
		if( u8BWSnrTemp == OFF_TMP_SET )	//E3
		{
				setBWIcon();
				if((u8TimeFlag&Tim0_5Flash)==Tim0_5Flash)
				{
					changeSMGdata(3,0x0e);
					changeSMGdata(4,3);
				}
		}
//		else if(u8BWHSSnrTemp == OFF_TMP_SET)	//e8
//		{
//				changeSMGdata(3,0x0e);
//				changeSMGdata(4,8);			
//		}
		else if( ( (u8AlarmFlag&PWRON_FLASH_H)==PWRON_FLASH_H ) && (u8FlashTim==0) )
		{
			if( (u16PwrOnFlashH0_5sCnt>10) || ((u8TimeFlag&Tim0_5Flash)==Tim0_5Flash) )
			{
				changeSMGdata(3,SMG_OFF);
				changeSMGdata(4,12);				
			}
			setBWIcon();
		}
		else
		{
				setBWIcon();
				if( (u8ForceOff&BW_FORCE_OFF)==BW_FORCE_OFF )
				{
						changeSMGdata(3,SMG_OFF);
						changeSMGdata(4,SMG_OFF);
						clrBWNeg();
						setBWOFF();
				}
				else
				{
						if( fgKeyDispTemp )
						{
							setBWIcon();
							clrBWOFF();
							if(u8BWSnrTemp>=C0)
							{
								clrBWNeg();
								u8BWtmpDisp = ((u8BWSnrTemp - C0)>>1)&0xff;
								changeSMGdata(3,u8BWtmpDisp/10);	//LC
								changeSMGdata(4,u8BWtmpDisp%10);							
							}
							else
							{
								setBWNeg();
								u8BWtmpDisp = ((C0-u8BWSnrTemp)>>1)&0xff;
								changeSMGdata(3,u8BWtmpDisp/10);	//
								changeSMGdata(4,u8BWtmpDisp%10);							
							}
						}					
						else
						{
								clrBWOFF();
								if(u8BWUserSetTmpBak >= C0)
								{
										clrBWNeg();
										u8BWtmpDisp = ((u8BWUserSetTmpBak-C0)>>1)&0xff;
										changeSMGdata(3,u8BWtmpDisp/10);
										changeSMGdata(4,u8BWtmpDisp%10);								
								}
								else
								{
									setBWNeg();
									u8BWtmpDisp = ((C0 - u8BWUserSetTmpBak)>>1)&0xff;
									changeSMGdata(3,u8BWtmpDisp/10);
									changeSMGdata(4,u8BWtmpDisp%10);
								}							
						}
				}
		}				


		if(fgCommPannelErr)
		{
				if((u8TimeFlag&Tim0_5Flash)==Tim0_5Flash)
				{		
					changeSMGdata(5,0x0e);	//E6 uart error
					changeSMGdata(6,6);	
				}					
				clrLDHour();
				clrLDIcon();
				clrLDNeg();
		}		
		else if(u8LDSnrTemp == OFF_TMP_SET)	//E2
		{
				setLDIcon();
				if((u8TimeFlag&Tim0_5Flash)==Tim0_5Flash)
				{
					changeSMGdata(5,0x0e);
					changeSMGdata(6,2);
				}
		}
		else if( ( (u8AlarmFlag&PWRON_FLASH_H)==PWRON_FLASH_H ) && (u8FlashTim==0) )
		{
			if( (u16PwrOnFlashH0_5sCnt>10) || ((u8TimeFlag&Tim0_5Flash)==Tim0_5Flash) )
			{
				changeSMGdata(5,SMG_OFF);
				changeSMGdata(6,12);				
			}
			setLDIcon();
		}		
		else
		{
				setLDIcon();
				if(u8FastFreezeTimeDisptim != 0) // 显示速冻时间
				{
					if((u8LockStatus!=0)||(u8FastFreezeTimeDisptim<(14-FLASH_TIME))||((u8TimeFlag&Tim0_5Flash)==Tim0_5Flash) )
					{
						setLDHour();
						clrLDNeg();
						if(u8Mode == FAST_FREEZE_MODE) u8LDtmpDisp = MinToHour(u16FastFreezeMin);	//1 ~24
						else u8LDtmpDisp = 6;
						changeSMGdata(5,u8LDtmpDisp/10);
						changeSMGdata(6,u8LDtmpDisp%10);
					}
				}
				else
				{
						if( ((u8AlarmFlag&LD_HIGH_ALARM)==LD_HIGH_ALARM)&&((u8TimeFlag&Tim0_5Flash)==Tim0_5Flash) ) setLDHour();
						else clrLDHour();
						
						if( fgKeyDispTemp )
						{
								setLDIcon();
								if(u8LDSnrTemp>=C0)
								{
									setLDNeg();
									u8LDtmpDisp = ((u8LDSnrTemp - C0)>>1)&0xff;
									changeSMGdata(5,u8LDtmpDisp/10);
									changeSMGdata(6,u8LDtmpDisp%10);							
								}
								else
								{
									setLDNeg();
									u8LDtmpDisp = ((C0-u8LDSnrTemp)>>1)&0xff;
									changeSMGdata(5,u8LDtmpDisp/10);	//
									changeSMGdata(6,u8LDtmpDisp%10);							
								}							
						}
						else
						{
							setLDNeg();	
							u8LDtmpDisp = (u8)((C0-u8LDUserSetTmpBak)>>1);
							if(u8ModeBak == FAST_FREEZE_MODE) u8LDtmpDisp = 24;	//-24
							changeSMGdata(5,u8LDtmpDisp/10);
							changeSMGdata(6,u8LDtmpDisp%10);				
						}
				}
		}
		
		
		setModeDisp(u8ModeBak);

		if( ((u8FlashTim&0x01) != 0) && (!fgKeyPress) )	//off
		{
				switch(u8KeyValue)
				{
						case SUB_LC_KEY:
						case ADD_LC_KEY:
						{
								if( u8LCSnrTemp != OFF_TMP_SET )
								{
										changeSMGdata(1,SMG_OFF);
										changeSMGdata(2,SMG_OFF);
										clrLCOFF();
								}
									break;
						}
						case SUB_BW_KEY:
						case ADD_BW_KEY:
						{
								if( u8BWSnrTemp != OFF_TMP_SET )
								{
									clrBWOFF();
									clrBWNeg();
									changeSMGdata(3,SMG_OFF);
									changeSMGdata(4,SMG_OFF);			
								}									
									break;
						}
						case SUB_LD_KEY:
						case ADD_LD_KEY:
						{
								if( (u8LDSnrTemp != OFF_TMP_SET) && (!fgCommPannelErr) )
								{
									clrLDHour();
									clrLDNeg();							
									changeSMGdata(5,SMG_OFF);
									changeSMGdata(6,SMG_OFF);	
								}
									break;
						}
						case MODE_KEY:
						{
								setModeDisp(NORMAL_MODE);
								break;
						}						
						default: break;
				}
		}		
		writeBufTo6964();
}



void selfTestDisplay(void)
{
		u8 u8HaveErr=0;
		if( (u8TempErr == OFF_TMP_SET)||(u8LCSnrTemp == OFF_TMP_SET)||(u8LCHSSnrTemp == OFF_TMP_SET)||(u8BWSnrTemp == OFF_TMP_SET)||(u8BWHSSnrTemp ==OFF_TMP_SET)||(u8LDSnrTemp ==OFF_TMP_SET)||(fgCommPannelErr) )
		u8HaveErr = 1;
	
		Change_Bright(8);

		switch(u8SelfTestStep)
		{
				case 0:
				case 1:
				case 3:
				{
						if(u8BCDType == _BCD_260_) changeSMGdata(5,3);	//机型230
						else changeSMGdata(5,2);	//机型220
						changeSMGdata(6,0);
						while(1)
						{
								if(u8HaveErr == 0)	//P0
								{
										changeSMGdata(1,17);
										changeSMGdata(2,0);
										return;
								}
								switch(u8SelfTestDispStep)
								{
										case 0:
										{
												if(u8LCSnrTemp == OFF_TMP_SET)	//E1
												{
														changeSMGdata(1,0x0e);
														changeSMGdata(2,1);
														u8SelfTestDispStep =1;
														return;
												}
										}
										case 1:
										{
												if(u8LDSnrTemp == OFF_TMP_SET)	//E2
												{
														changeSMGdata(1,0x0e);
														changeSMGdata(2,2);
														u8SelfTestDispStep = 2;
														return;
												}				
										}										
										case 2:
										{
												if(u8BWSnrTemp == OFF_TMP_SET)	//E3
												{
														changeSMGdata(1,0x0e);
														changeSMGdata(2,3);
														u8SelfTestDispStep =3;
														return;
												}
										}
										case 3:
										{
												if(fgCommPannelErr)	//E6
												{
														changeSMGdata(1,0x0e);
														changeSMGdata(2,6);
														u8SelfTestDispStep =4;
														return;
												}				
										}										
										case 4:
										{
												if(u8LCHSSnrTemp == OFF_TMP_SET)	//E7
												{
														changeSMGdata(1,0x0e);
														changeSMGdata(2,7);
														u8SelfTestDispStep =5;
														return;
												}				
										}												
										case 5:
										{
												if(u8BWHSSnrTemp == OFF_TMP_SET)	//E8
												{
														changeSMGdata(1,0x0e);
														changeSMGdata(2,8);
														u8SelfTestDispStep =6;
														return;
												}				
										}		
										case 6:
										{
												if(u8TempErr != 0)	//EA
												{
														changeSMGdata(1,0x0e);
														changeSMGdata(2,0x0a);
														u8SelfTestDispStep =0;
														return;
												}
										}
										default:
										{
												u8SelfTestDispStep = 0;
												break;
										}
								}
						}
				}
				case 2:
				{
						switch(u8SelfTestDispStep)
						{
								case 0:
								{
										setDispBuf(0);
										break;
								}
								case 1:
								{
										setBWNeg();
										break;
								}
								case 2:
								{
										setLDNeg();
										break;
								}
								case 3:
								{
										setSMGDot(1);
										break;
								}
								case 4:
								{
										setSMGDot(2);
										break;	
								}										
								case 5:
								{
										setSMGDot(3);
										break;		
								}
								case 6:
								{
										setSMGDot(4);
										break;	
								}										
								case 7:
								{
										setSMGDot(5);
										break;	
								}										
								case 8:
								{
										setSMGDot(6);
										break;
								}										
								case 9:
								{
										setSMGDot(7);
										break;		
								}
								case 10:
								{
										setLCIcon();
										setBWIcon();
										setLDIcon();
										break;
								}
								case 11:
								{
										dispBuf[12]	=  0x10;	//e7
										dispBuf[13]	= 0x01;	//a7
										break;
								}
								case 12:
								{
										dispBuf[12]	|=  0x88;	//B7 F7
										break;
								}
								case 13:
								{
										dispBuf[12]	|=  0x44;	//B7 F7
										break;	
								}										
								case 14:
								{
										dispBuf[12]	|=  0x22;	//B7 F7
										break;
								}										
								case 15:
								{
										setLCOFF();
										setBWOFF();
										break;
								}
								case 16:
								{
										setLDHour();
										break;
								}
								case 17:
								{
										setDispBuf(0);
										break;
								}
								case 18:
								{
										setDispBuf(0xff);
										break;
								}
								default:
								{
										u8SelfTestDispStep = 18;
										break;
								}
						}
						u8SelfTestDispStep++;
						break;
				}
				default: break;
		}
}



void	setSMGDot(u8 dot)
{
		u8 data,addr,whichSMG;
		switch(dot)
		{
				case 1:
				{
						for(whichSMG=1;whichSMG<7;whichSMG++)
						{
								addr = (u8)(((whichSMG -1)<<1)&0xfe);
								addr++;
								dispBuf[addr] |= 0x01;								
						}					
						return;
				}
				case 2:
				{
						data = 0x80;
						break;
				}
				case 3:
				{
						data = 0x40;
						break;
				}
				case 4:
				{
						data = 0x20;
						break;
				}
				case 5:
				{
						data = 0x10;
						break;
				}
				case 6:
				{
						data = 0x08;
						break;
				}
				case 7:
				{
						data = 0x04;
						break;
				}
				default: return;
		}
		for(whichSMG=1;whichSMG<7;whichSMG++)
		{
				addr = (u8)(((whichSMG -1)<<1)&0xfe);
				dispBuf[addr] = (u8)(dispBuf[addr]|data);
		}
}


void setDispBuf(u8 data)
{
		u8 i;
		for(i=0;i<14;i++) dispBuf[i]=data;
}


