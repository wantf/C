#ifndef _MAIN_H_
#define _MAIN_H_

/*****************************MCU������**************************/

    _FOSC( 
            CSW_FSCM_OFF &             // Fail safe �ر� 
            XT_PLL8                    // ʱ���ⲿ��׼ 8��Ƶ
         );                   
    _FWDT(
//            WDT_OFF &
            WDT_ON &                   // ���Ź���ʱ��4ms
            WDTPSA_64 &                // A��Ƶ��Ϊ1��1
            WDTPSB_8                   // B��Ƶ��Ϊ1��8
         );                            //
    _FBORPOR(
            MCLR_EN  &                 // ��λ������
            RST_PWMPIN &               //
            PWMxH_ACT_HI &             // PWM ������IO�ڿ���
            PWMxL_ACT_HI &             //
            PWRT_64 &                  // ��ʱ16����
//            PBOR_OFF &
            PBOR_ON &                  // ���翪��
            BORV_20                    //
        );                             //   
    _FGS(

            CODE_PROT_ON &            // ���뱣����ֹ
            GWRP_ON                   // ͨ�ô���α�����ֹ
  
//            CODE_PROT_OFF &            // ���뱣����ֹ
//            GWRP_OFF                   // ͨ�ô���α�����ֹ
        
         );  


//extern void test_relay(void);
#endif
