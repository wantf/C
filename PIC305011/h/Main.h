#ifndef _MAIN_H_
#define _MAIN_H_

/*****************************MCU的配置**************************/

    _FOSC( 
            CSW_FSCM_OFF &             // Fail safe 关闭 
            XT_PLL8                    // 时钟外部标准 8倍频
         );                   
    _FWDT(
//            WDT_OFF &
            WDT_ON &                   // 看门狗定时器4ms
            WDTPSA_64 &                // A分频器为1：1
            WDTPSB_8                   // B分频器为1：8
         );                            //
    _FBORPOR(
            MCLR_EN  &                 // 复位脚启用
            RST_PWMPIN &               //
            PWMxH_ACT_HI &             // PWM 引脚由IO口控制
            PWMxL_ACT_HI &             //
            PWRT_64 &                  // 延时16毫秒
//            PBOR_OFF &
            PBOR_ON &                  // 掉电开启
            BORV_20                    //
        );                             //   
    _FGS(

            CODE_PROT_ON &            // 代码保护禁止
            GWRP_ON                   // 通用代码段保护禁止
  
//            CODE_PROT_OFF &            // 代码保护禁止
//            GWRP_OFF                   // 通用代码段保护禁止
        
         );  


//extern void test_relay(void);
#endif
