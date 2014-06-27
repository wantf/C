#include "GlobalParm.h"
#include "SystemClock.h"
#include "ADCSample.h"
void GetKeyState(void);
void GetPortState(UInt8 ucBit,KeyInfo *p_PortState);
void UpdataStepPosition(void);
extern void Error_Disprose(void);
/*******************************************************************

    �������ƣ�void __attribute__((__interrupt__,no_auto_psv)) _T1Interrupt(void)
    ��    �ܣ�T1�ж�Ϊ����ϵͳ�ṩʱ�����������ж�����ɰ����ɼ��ͱ�����ʱ��
    �����������
    �����������
    ����ֵ  ����
    1ms�Ļ��� ʱ��

********************************************************************/

void __attribute__((__interrupt__,no_auto_psv)) _T1Interrupt(void)
{
//    static UInt16 s_StepTimer = 0;
	static UInt16 s_uiDelay2MS = 0;
    static UInt16 s_uiDelay5MS = 0;
    static UInt16 s_StepUpdataDelayTimer = 0;
    IFS0bits.T1IF = 0;                                                              //��ʱ��1�жϱ�־λ��0 
    TMR1          = 0; 
//	TEST_IO1      = TEST_IO1+1;
//*********������ʱ����(���ֽ���)************************
    if( UART_DELAY_TIME )
    {
        g_uiUartDelayCount++;
        if( g_uiUartDelayCount > CM_UART_RX_DELAY )
        {
            UART_DELAY_TIME    = FALSE;
            g_uiUartDelayCount = 0;
            g_uiRxCount        = 0;
            U1STAbits.OERR     = 0;                  // �����        
        }
    }
    else
    {
        g_uiUartDelayCount = 0;    
    }
    //*******��ⲽ�����λ�ü��*********************************
    if( STEP_POSITION_UPDATA )
    {
	    if( s_StepUpdataDelayTimer++ > 2250 )
	    {
		    s_StepUpdataDelayTimer = 0;
            g_StepPosition         = 0;
	    }
    }
    else
    {
        s_StepUpdataDelayTimer = 0;
	    STEP_POSITION_UPDATA   = 1;
    }
	
    //*******��ⲽ�����λ�ü��*********************************	
//	if( s_StepTimer++ > 80 )
//	{
//		s_StepTimer = 0;
//        UpdataStepPosition();
//	}	
    //*******�������*********************************	
	if( g_KeyTimer++ ==TIME_6MS )
	{
		g_KeyTimer = 0;
		GetKeyState();
        GetPortState(1,&str_StepR_Start);
        GetPortState(2,&str_StepL_Start);
        GetPortState(3,&str_SCR_Start);
     	GetPortState(4,&str_RLed_Start);
        GetPortState(5,&str_GLed_Start);
		GetPortState(6,&str_Machine_Start);
		UpdataStepPosition();
    //	if( s_StepTimer++ > 70 )
	//    {
	//	    s_StepTimer = 0;
    //        UpdataStepPosition();
	//    }       
	}
    //********ADֵ�˲�����**************************
	if(	g_ADDisposeTimer++ == TIME_5MS )
	{
		g_ADDisposeTimer = 0;
		ATODValue_Dispose();
	}
    //********ADֵ�ڼ̵����պϺ���ʱ����****
	if( WAIT_AdUpdateStart )
	{
		if( g_ADDelayTimer++ >= TIME_60MS )
		{
			WAIT_AdUpdateEnd   = TRUE;
			WAIT_AdUpdateStart = FALSE;                    //��ֹû�о������������ٴν���
			g_ADDelayTimer     = 0;
		}
			
	}

    //********2������ʱ****
	if( WAIT_2MS_Start )
	{
		if( s_uiDelay2MS++ >= 1 )
		{
			WAIT_2MS_End   = TRUE;
			WAIT_2MS_Start = FALSE;                    //��ֹû�о������������ٴν���
			s_uiDelay2MS   = 0;
		}			
	}

	    //********5������ʱ****
	if( WAIT_5MS_Start )
	{
		if( s_uiDelay5MS++ >= 5 )
		{
			WAIT_5MS_End   = TRUE;
			WAIT_5MS_Start = FALSE;                    //��ֹû�о������������ٴν���
			s_uiDelay5MS   = 0;
		}			
	}

	
    //*******��ʼ�������ٰ�����ʱʱ�� ************
    //*******ÿһ֡���ݷ�����,��ʱ2Sû���յ�����,״̬��Ϩ,���ذ�����ʼ
	if( TestStart_Flag )
	{	
		if( g_COMMStateTimer++>=TIME_3000MS )
		{
			Error_Disprose();
			g_COMMStateTimer   = 0;
		}
	}
	else
	{
		g_COMMStateTimer = 0;
	}
}
void GetKeyState(void)
{
	if(!KEY_StartState)
	{
		if( key_Start.IO_L_count > 0 )
		{	
			key_Start.IO_L_count--;
		}
		if( key_Start.IO_H_count < key_Start.Delay_MaxCount )
		{
			key_Start.IO_H_count++;
		}
		else
		{
			key_Start.IO_H_count = 0;
			key_Start.Key_State  = KEY_ON;
		}
	}
	else
	{
		if( key_Start.IO_H_count > 0 )
		{	
			key_Start.IO_H_count--;
		}
		if( key_Start.IO_L_count < key_Start.Delay_MaxCount )
		{
			key_Start.IO_L_count++;
		}
		else
		{
			key_Start.IO_L_count = 0;
			key_Start.Key_State  = KEY_OFF;
		}		
	}	
}

void GetPortState(UInt8 ucBit,KeyInfo *p_PortState)
{
    if( ucBit<1 || ucBit>6)
    {
        return;
	}
	if( (PORTD>>ucBit)&0x0001 )
	{
		if( p_PortState->IO_L_count > 0 )
		{	
			p_PortState->IO_L_count--;
		}
		if( p_PortState->IO_H_count < p_PortState->Delay_MaxCount )
		{
			p_PortState->IO_H_count++;
		}
		else
		{
			p_PortState->IO_H_count = 0;
			p_PortState->Key_State  = KEY_ON;
		}
	}
	else
	{
		if( p_PortState->IO_H_count > 0 )
		{	
			p_PortState->IO_H_count--;
		}
		if( p_PortState->IO_L_count < p_PortState->Delay_MaxCount )
		{
			p_PortState->IO_L_count++;
		}
		else
		{
			p_PortState->IO_L_count = 0;
			p_PortState->Key_State  = KEY_OFF;
		}		
	}	
}
void UpdataStepPosition(void)
{
    static UInt8 s_ucStepPrevious = 0;
    UInt8 ucTemp = 0;
    ucTemp = str_StepL_Start.Key_State|(str_StepR_Start.Key_State<<1);
    ucTemp = ucTemp & 0x0003;
    switch( s_ucStepPrevious )
    {
        case 0:
             STEP_POSITION_UPDATA = TRUE;
             if( ucTemp == 1 )
             {
                 g_StepPosition   = 2;
                 s_ucStepPrevious = 1;
                 STEP_POSITION_UPDATA = FALSE;
             }
             else if( ucTemp == 2 )
             {
                 g_StepPosition   = 4;
                 s_ucStepPrevious = 2;
                 STEP_POSITION_UPDATA = FALSE;
             }
             else
             {
                 s_ucStepPrevious = 0;
             }
             break;
        case 1:
             STEP_POSITION_UPDATA = TRUE;
             if( ucTemp == 0 )
             {
                 g_StepPosition   = 4;
                 s_ucStepPrevious = 0;
                 STEP_POSITION_UPDATA = FALSE;
             }
             else if( ucTemp == 3 )
             {
                 g_StepPosition   = 2;
                 s_ucStepPrevious = 3;
                 STEP_POSITION_UPDATA = FALSE;
             }
             else
             {
                 s_ucStepPrevious = 1;
             }
             break;
        case 2:
             STEP_POSITION_UPDATA = TRUE;
             if( ucTemp == 0 )
             {
                 g_StepPosition   = 2;
                 s_ucStepPrevious = 0;
                 STEP_POSITION_UPDATA = FALSE;
             }
             else if( ucTemp == 3 )
             {
                 g_StepPosition   = 4;
                 s_ucStepPrevious = 3;
                 STEP_POSITION_UPDATA = FALSE;
             }
             else
             {
                 s_ucStepPrevious = 2;
             }
             break;
        case 3:
             STEP_POSITION_UPDATA = TRUE;
             if( ucTemp == 1 )
             {
                 g_StepPosition   = 4;
                 s_ucStepPrevious = 1;
                 STEP_POSITION_UPDATA = FALSE;
             }
             else if( ucTemp == 2 )
             {
                 g_StepPosition   = 2;
                 s_ucStepPrevious = 2;
                 STEP_POSITION_UPDATA = FALSE;
             }
             else
             {
                 s_ucStepPrevious = 3;
             }
             break;
        default:
             s_ucStepPrevious = 0;
             break;
    } 
}



