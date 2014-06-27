//---------------------------------------------------------------------------
// hodgen-china
// communication.h
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

#ifndef		_COMMUNICATION_H_
#define		_COMMUNICATION_H_
/* Exported macro ------------------------------------------------------------*/


/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
extern u8	u8CommErr;
#define fgCommPannelErr	                ((struct bits*)&u8CommErr)->BIT0
#define fgCommMainErr		                ((struct bits*)&u8CommErr)->BIT1

extern u16 u16DoorOpen1s;

extern u8		u8ResendCnt;
extern u8		u8CmpCOntinueRunTim;
extern u8		u8SelfTestFlag;
extern u8		u8CommSendStep;

extern u16	u16PwrOnFlashH0_5sCnt;

extern u8		u8Comm1sCnt;
extern u8		u8receivedCnt;

extern u8		u8commStatus;
#define fgSending	                ((struct bits*)&u8commStatus)->BIT0
#define fgWaitResponse            ((struct bits*)&u8commStatus)->BIT1
#define fgReceiving		            ((struct bits*)&u8commStatus)->BIT2
#define fgReceived		            ((struct bits*)&u8commStatus)->BIT3

extern u8	u8BCDType;
#define _BCD_260_ 0
#define _BCD_220_ 1

extern u8		u8MainBoardOutput;
#define	CMP_RUNING		0x01
#define	LC_RUNING			0x02
#define	BW_RUNING			0x04
#define	LC_DOOR_OPEN	0x08
/* Exported constants --------------------------------------------------------*/
/* Evalboard I/Os configuration */
#define TxRxPort				(GPIOD)
#define TX						(GPIO_PIN_5)
#define RX						(GPIO_PIN_6)
#define	ExtiRxPort		(EXTI_PORT_GPIOD)
/* Exported functions ------------------------------------------------------- */
void		commRevTask(void);
void		commSend(void);
void		initTxRx(void);
void		RxTimeTask(void);
void 		stopTim4(void);

#endif