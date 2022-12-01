.syntax unified
.cpu cortex-m4
.fpu softvfp
.thumb

.global vtable 
.global Default_handle

.type vtable, %object
.section .vectorTable,"a",%progbits
vtable:
  .word  _endStack
  .word  Reset_handle
  .word  NMI_handle
  .word  HardFault_handle
  .word  MemManage_handle
  .word  BusFault_handle
  .word  UsageFault_handle
  .word  0
  .word  0
  .word  0
  .word  0
  .word  SVC_handle
  .word  DebugMon_handle
  .word  0
  .word  PendSV_handle
  .word  SysTick_handle

  .word     IRQ_WWDG_handle                   /* Window WatchDog                             */
  .word     IRQ_PVD_handle                    /* PVD through EXTI Line detection             */
  .word     IRQ_TAMP_STAMP_handle             /* Tamper and TimeStamps through the EXTI line */
  .word     IRQ_RTC_WKUP_handle               /* RTC Wakeup through the EXTI line            */
  .word     IRQ_FLASH_handle                  /* FLASH                                       */
  .word     IRQ_RCC_handle                    /* RCC                                         */
  .word     IRQ_EXTI0_handle                  /* EXTI Line0                                  */
  .word     IRQ_EXTI1_handle                  /* EXTI Line1                                  */
  .word     IRQ_EXTI2_handle                  /* EXTI Line2                                  */
  .word     IRQ_EXTI3_handle                  /* EXTI Line3                                  */
  .word     IRQ_EXTI4_handle                  /* EXTI Line4                                  */
  .word     IRQ_DMA1_STREAM0_handle           /* DMA1 STREAM 0                               */
  .word     IRQ_DMA1_STREAM1_handle           /* DMA1 STREAM 1                               */
  .word     IRQ_DMA1_STREAM2_handle           /* DMA1 STREAM 2                               */
  .word     IRQ_DMA1_STREAM3_handle           /* DMA1 STREAM 3                               */
  .word     IRQ_DMA1_STREAM4_handle           /* DMA1 STREAM 4                               */
  .word     IRQ_DMA1_STREAM5_handle           /* DMA1 STREAM 5                               */
  .word     IRQ_DMA1_STREAM6_handle           /* DMA1 STREAM 6                               */
  .word     IRQ_ADC_handle                    /* ADC1, ADC2 and ADC3s                        */
  .word     IRQ_CAN1_TX_handle                /* CAN1 TX                                     */
  .word     IRQ_CAN1_RX0_handle               /* CAN1 RX0                                    */
  .word     IRQ_CAN1_RX1_handle               /* CAN1 RX1                                    */
  .word     IRQ_CAN1_SCE_handle               /* CAN1 SCE                                    */
  .word     IRQ_EXTI9_5_handle                /* External Line[9:5]s                         */
  .word     IRQ_TIM1_BRK_TIM9_handle          /* TIM1 Break and TIM9                         */
  .word     IRQ_TIM1_UP_TIM10_handle          /* TIM1 Update and TIM10                       */
  .word     IRQ_TIM1_TRG_COM_TIM11_handle     /* TIM1 Trigger and Commutation and TIM11      */
  .word     IRQ_TIM1_CC_handle                /* TIM1 Capture Compare                        */
  .word     IRQ_TIM2_handle                   /* TIM2                                        */
  .word     IRQ_TIM3_handle                   /* TIM3                                        */
  .word     IRQ_TIM4_handle                   /* TIM4                                        */
  .word     IRQ_I2C1_EV_handle                /* I2C1 Event                                  */
  .word     IRQ_I2C1_ER_handle                /* I2C1 Error                                  */
  .word     IRQ_I2C2_EV_handle                /* I2C2 Event                                  */
  .word     IRQ_I2C2_ER_handle                /* I2C2 Error                                  */
  .word     IRQ_SPI1_handle                   /* SPI1                                        */
  .word     IRQ_SPI2_handle                   /* SPI2                                        */
  .word     IRQ_USART1_handle                 /* USART1                                      */
  .word     IRQ_USART2_handle                 /* USART2                                      */
  .word     IRQ_USART3_handle                 /* USART3                                      */
  .word     IRQ_EXTI15_10_handle              /* External Line[15:10]s                       */
  .word     IRQ_RTC_Alarm_handle              /* RTC Alarm (A and B) through EXTI Line       */
  .word     IRQ_OTG_FS_WKUP_handle            /* USB OTG FS Wakeup through EXTI line         */
  .word     IRQ_TIM8_BRK_TIM12_handle         /* TIM8 Break and TIM12                        */
  .word     IRQ_TIM8_UP_TIM13_handle          /* TIM8 Update and TIM13                       */
  .word     IRQ_TIM8_TRG_COM_TIM14_handle     /* TIM8 Trigger and Commutation and TIM14      */
  .word     IRQ_TIM8_CC_handle                /* TIM8 Capture Compare                        */
  .word     IRQ_DMA1_STREAM7_handle           /* DMA1 STREAM7                                */
  .word     IRQ_FSMC_handle                   /* FSMC                                        */
  .word     IRQ_SDIO_handle                   /* SDIO                                        */
  .word     IRQ_TIM5_handle                   /* TIM5                                        */
  .word     IRQ_SPI3_handle                   /* SPI3                                        */
  .word     IRQ_UART4_handle                  /* UART4                                       */
  .word     IRQ_UART5_handle                  /* UART5                                       */
  .word     IRQ_TIM6_DAC_handle               /* TIM6, DAC1 and DAC2                         */
  .word     IRQ_TIM7_handle                   /* TIM7                                        */
  .word     IRQ_DMA2_STREAM0_handle           /* DMA2 STREAM 0                               */
  .word     IRQ_DMA2_STREAM1_handle           /* DMA2 STREAM 1                               */
  .word     IRQ_DMA2_STREAM2_handle           /* DMA2 STREAM 2                               */
  .word     IRQ_DMA2_STREAM3_handle           /* DMA2 STREAM 3                               */
  .word     IRQ_DMA2_STREAM4_handle           /* DMA2 STREAM 4                               */
  .word     IRQ_DFSDM1_FLT0_handle            /* DFSDM1 Filter0                              */
  .word     IRQ_DFSDM1_FLT1_handle            /* DFSDM1 Filter1                              */
  .word     IRQ_CAN2_TX_handle                /* CAN2 TX                                     */
  .word     IRQ_CAN2_RX0_handle               /* CAN2 RX0                                    */
  .word     IRQ_CAN2_RX1_handle               /* CAN2 RX1                                    */
  .word     IRQ_CAN2_SCE_handle               /* CAN2 SCE                                    */
  .word     IRQ_OTG_FS_handle                 /* USB OTG FS                                  */
  .word     IRQ_DMA2_STREAM5_handle           /* DMA2 STREAM 5                               */
  .word     IRQ_DMA2_STREAM6_handle           /* DMA2 STREAM 6                               */
  .word     IRQ_DMA2_STREAM7_handle           /* DMA2 STREAM 7                               */
  .word     IRQ_USART6_handle                 /* USART6                                      */
  .word     IRQ_I2C3_EV_handle                /* I2C3 event                                  */
  .word     IRQ_I2C3_ER_handle                /* I2C3 error                                  */
  .word     IRQ_CAN3_TX_handle                /* CAN3 TX                                     */
  .word     IRQ_CAN3_RX0_handle               /* CAN3 RX0                                    */
  .word     IRQ_CAN3_RX1_handle               /* CAN3 RX1                                    */
  .word     IRQ_CAN3_SCE_handle               /* CAN3 SCE                                    */
  .word     0                                 /* Reserved                                    */
  .word     0                                 /* Reserved                                    */
  .word     IRQ_RNG_handle                    /* RNG                                         */
  .word     IRQ_FPU_handle                    /* FPU                                         */
  .word     IRQ_UART7_handle                  /* UART7                                       */
  .word     IRQ_UART8_handle                  /* UART8                                       */
  .word     IRQ_SPI4_handle                   /* SPI4                                        */
  .word     IRQ_SPI5_handle                   /* SPI5                                        */
  .word     0                                 /* Reserved                                    */
  .word     IRQ_SAI1_handle                   /* SAI1                                        */
  .word     IRQ_UART9_handle                  /* UART9                                       */
  .word     IRQ_UART10_handle                 /* UART10                                      */
  .word     0                                 /* Reserved                                    */
  .word     0                                 /* Reserved                                    */
  .word     IRQ_QUADSPI_handle                /* QuadSPI                                     */
  .word     0                                 /* Reserved                                    */
  .word     0                                 /* Reserved                                    */
  .word     IRQ_FMPI2C1_EV_handle             /* FMPI2C1 Event                               */
  .word     IRQ_FMPI2C1_ER_handle             /* FMPI2C1 Error                               */
  .word     IRQ_LPTIM1_handle                 /* LPTIM1                                      */
  .word     IRQ_DFSDM2_FLT0_handle            /* DFSDM2 Filter0                              */
  .word     IRQ_DFSDM2_FLT1_handle            /* DFSDM2 Filter1                              */
  .word     IRQ_DFSDM2_FLT2_handle            /* DFSDM2 Filter2                              */
  .word     IRQ_DFSDM2_FLT3_handle            /* DFSDM2 Filter3                              */
  
   .weak      NMI_handle
   .thumb_set NMI_handle, Default_handle

   .weak      HardFault_handle
   .thumb_set HardFault_handle, Default_handle

   .weak      MemManage_handle
   .thumb_set MemManage_handle, Default_handle
  
   .weak      BusFault_handle
   .thumb_set BusFault_handle, Default_handle

   .weak      UsageFault_handle
   .thumb_set UsageFault_handle, Default_handle

   .weak      SVC_handle
   .thumb_set SVC_handle, Default_handle

   .weak      DebugMon_handle
   .thumb_set DebugMon_handle, Default_handle

   .weak      PendSV_handle
   .thumb_set PendSV_handle, Default_handle

   .weak      SysTick_handle
   .thumb_set SysTick_handle, Default_handle

   .weak      IRQ_WWDG_handle
   .thumb_set IRQ_WWDG_handle, Default_handle

   .weak      IRQ_PVD_handle
   .thumb_set IRQ_PVD_handle, Default_handle

   .weak      IRQ_TAMP_STAMP_handle
   .thumb_set IRQ_TAMP_STAMP_handle, Default_handle

   .weak      IRQ_RTC_WKUP_handle
   .thumb_set IRQ_RTC_WKUP_handle, Default_handle

   .weak      IRQ_FLASH_handle
   .thumb_set IRQ_FLASH_handle, Default_handle

   .weak      IRQ_RCC_handle
   .thumb_set IRQ_RCC_handle, Default_handle

   .weak      IRQ_EXTI0_handle
   .thumb_set IRQ_EXTI0_handle, Default_handle

   .weak      IRQ_EXTI1_handle
   .thumb_set IRQ_EXTI1_handle, Default_handle

   .weak      IRQ_EXTI2_handle
   .thumb_set IRQ_EXTI2_handle, Default_handle

   .weak      IRQ_EXTI3_handle
   .thumb_set IRQ_EXTI3_handle, Default_handle

   .weak      IRQ_EXTI4_handle
   .thumb_set IRQ_EXTI4_handle, Default_handle

   .weak      IRQ_DMA1_STREAM0_handle
   .thumb_set IRQ_DMA1_STREAM0_handle, Default_handle

   .weak      IRQ_DMA1_STREAM1_handle
   .thumb_set IRQ_DMA1_STREAM1_handle, Default_handle

   .weak      IRQ_DMA1_STREAM2_handle
   .thumb_set IRQ_DMA1_STREAM2_handle, Default_handle

   .weak      IRQ_DMA1_STREAM3_handle
   .thumb_set IRQ_DMA1_STREAM3_handle, Default_handle

   .weak      IRQ_DMA1_STREAM4_handle
   .thumb_set IRQ_DMA1_STREAM4_handle, Default_handle

   .weak      IRQ_DMA1_STREAM5_handle
   .thumb_set IRQ_DMA1_STREAM5_handle, Default_handle

   .weak      IRQ_DMA1_STREAM6_handle
   .thumb_set IRQ_DMA1_STREAM6_handle, Default_handle

   .weak      IRQ_ADC_handle
   .thumb_set IRQ_ADC_handle, Default_handle

   .weak      IRQ_CAN1_TX_handle
   .thumb_set IRQ_CAN1_TX_handle, Default_handle

   .weak      IRQ_CAN1_RX0_handle
   .thumb_set IRQ_CAN1_RX0_handle, Default_handle

   .weak      IRQ_CAN1_RX1_handle
   .thumb_set IRQ_CAN1_RX1_handle, Default_handle

   .weak      IRQ_CAN1_SCE_handle
   .thumb_set IRQ_CAN1_SCE_handle, Default_handle

   .weak      IRQ_EXTI9_5_handle
   .thumb_set IRQ_EXTI9_5_handle, Default_handle

   .weak      IRQ_TIM1_BRK_TIM9_handle
   .thumb_set IRQ_TIM1_BRK_TIM9_handle, Default_handle

   .weak      IRQ_TIM1_UP_TIM10_handle
   .thumb_set IRQ_TIM1_UP_TIM10_handle, Default_handle

   .weak      IRQ_TIM1_TRG_COM_TIM11_handle
   .thumb_set IRQ_TIM1_TRG_COM_TIM11_handle, Default_handle

   .weak      IRQ_TIM1_CC_handle
   .thumb_set IRQ_TIM1_CC_handle, Default_handle

   .weak      IRQ_TIM2_handle
   .thumb_set IRQ_TIM2_handle, Default_handle

   .weak      IRQ_TIM3_handle
   .thumb_set IRQ_TIM3_handle, Default_handle

   .weak      IRQ_TIM4_handle
   .thumb_set IRQ_TIM4_handle, Default_handle

   .weak      IRQ_I2C1_EV_handle
   .thumb_set IRQ_I2C1_EV_handle, Default_handle

   .weak      IRQ_I2C1_ER_handle
   .thumb_set IRQ_I2C1_ER_handle, Default_handle

   .weak      IRQ_I2C2_EV_handle
   .thumb_set IRQ_I2C2_EV_handle, Default_handle

   .weak      IRQ_I2C2_ER_handle
   .thumb_set IRQ_I2C2_ER_handle, Default_handle

   .weak      IRQ_SPI1_handle
   .thumb_set IRQ_SPI1_handle, Default_handle

   .weak      IRQ_SPI2_handle
   .thumb_set IRQ_SPI2_handle, Default_handle

   .weak      IRQ_USART1_handle
   .thumb_set IRQ_USART1_handle, Default_handle

   .weak      IRQ_USART2_handle
   .thumb_set IRQ_USART2_handle, Default_handle

   .weak      IRQ_USART3_handle
   .thumb_set IRQ_USART3_handle, Default_handle

   .weak      IRQ_EXTI15_10_handle
   .thumb_set IRQ_EXTI15_10_handle, Default_handle

   .weak      IRQ_RTC_Alarm_handle
   .thumb_set IRQ_RTC_Alarm_handle, Default_handle

   .weak      IRQ_OTG_FS_WKUP_handle
   .thumb_set IRQ_OTG_FS_WKUP_handle, Default_handle

   .weak      IRQ_TIM8_BRK_TIM12_handle
   .thumb_set IRQ_TIM8_BRK_TIM12_handle, Default_handle

   .weak      IRQ_TIM8_UP_TIM13_handle
   .thumb_set IRQ_TIM8_UP_TIM13_handle, Default_handle

   .weak      IRQ_TIM8_TRG_COM_TIM14_handle
   .thumb_set IRQ_TIM8_TRG_COM_TIM14_handle, Default_handle

   .weak      IRQ_TIM8_CC_handle
   .thumb_set IRQ_TIM8_CC_handle, Default_handle

   .weak      IRQ_DMA1_STREAM7_handle
   .thumb_set IRQ_DMA1_STREAM7_handle, Default_handle
   
   .weak      IRQ_FSMC_handle
   .thumb_set IRQ_FSMC_handle, Default_handle

   .weak      IRQ_SDIO_handle
   .thumb_set IRQ_SDIO_handle, Default_handle

   .weak      IRQ_TIM5_handle
   .thumb_set IRQ_TIM5_handle, Default_handle

   .weak      IRQ_SPI3_handle
   .thumb_set IRQ_SPI3_handle, Default_handle
   
   .weak      IRQ_UART4_handle
   .thumb_set IRQ_UART4_handle, Default_handle

   .weak      IRQ_UART5_handle
   .thumb_set IRQ_UART5_handle, Default_handle

   .weak      IRQ_TIM6_DAC_handle
   .thumb_set IRQ_TIM6_DAC_handle, Default_handle

   .weak      IRQ_TIM7_handle
   .thumb_set IRQ_TIM7_handle, Default_handle

   .weak      IRQ_DMA2_STREAM0_handle
   .thumb_set IRQ_DMA2_STREAM0_handle, Default_handle

   .weak      IRQ_DMA2_STREAM1_handle
   .thumb_set IRQ_DMA2_STREAM1_handle, Default_handle

   .weak      IRQ_DMA2_STREAM2_handle
   .thumb_set IRQ_DMA2_STREAM2_handle, Default_handle

   .weak      IRQ_DMA2_STREAM3_handle
   .thumb_set IRQ_DMA2_STREAM3_handle, Default_handle

   .weak      IRQ_DMA2_STREAM4_handle
   .thumb_set IRQ_DMA2_STREAM4_handle, Default_handle

   .weak      IRQ_DFSDM1_FLT0_handle
   .thumb_set IRQ_DFSDM1_FLT0_handle, Default_handle

   .weak      IRQ_DFSDM1_FLT1_handle
   .thumb_set IRQ_DFSDM1_FLT1_handle, Default_handle

   .weak      IRQ_CAN2_TX_handle
   .thumb_set IRQ_CAN2_TX_handle, Default_handle

   .weak      IRQ_CAN2_RX0_handle
   .thumb_set IRQ_CAN2_RX0_handle, Default_handle

   .weak      IRQ_CAN2_RX1_handle
   .thumb_set IRQ_CAN2_RX1_handle, Default_handle

   .weak      IRQ_CAN2_SCE_handle
   .thumb_set IRQ_CAN2_SCE_handle, Default_handle

   .weak      IRQ_OTG_FS_handle
   .thumb_set IRQ_OTG_FS_handle, Default_handle

   .weak      IRQ_DMA2_STREAM5_handle
   .thumb_set IRQ_DMA2_STREAM5_handle, Default_handle

   .weak      IRQ_DMA2_STREAM6_handle
   .thumb_set IRQ_DMA2_STREAM6_handle, Default_handle

   .weak      IRQ_DMA2_STREAM7_handle
   .thumb_set IRQ_DMA2_STREAM7_handle, Default_handle

   .weak      IRQ_USART6_handle
   .thumb_set IRQ_USART6_handle, Default_handle

   .weak      IRQ_I2C3_EV_handle
   .thumb_set IRQ_I2C3_EV_handle, Default_handle

   .weak      IRQ_I2C3_ER_handle
   .thumb_set IRQ_I2C3_ER_handle, Default_handle
   
   .weak      IRQ_CAN3_TX_handle
   .thumb_set IRQ_CAN3_TX_handle, Default_handle

   .weak      IRQ_CAN3_RX0_handle
   .thumb_set IRQ_CAN3_RX0_handle, Default_handle

   .weak      IRQ_CAN3_RX1_handle
   .thumb_set IRQ_CAN3_RX1_handle, Default_handle

   .weak      IRQ_CAN3_SCE_handle
   .thumb_set IRQ_CAN3_SCE_handle, Default_handle

   .weak      IRQ_RNG_handle
   .thumb_set IRQ_RNG_handle, Default_handle

   .weak      IRQ_FPU_handle
   .thumb_set IRQ_FPU_handle, Default_handle
   
   .weak      IRQ_UART7_handle
   .thumb_set IRQ_UART7_handle, Default_handle

   .weak      IRQ_UART8_handle
   .thumb_set IRQ_UART8_handle, Default_handle

   .weak      IRQ_SPI4_handle
   .thumb_set IRQ_SPI4_handle, Default_handle

   .weak      IRQ_SPI5_handle
   .thumb_set IRQ_SPI5_handle, Default_handle
   
   .weak      IRQ_SAI1_handle
   .thumb_set IRQ_SAI1_handle, Default_handle

   .weak      IRQ_UART9_handle
   .thumb_set IRQ_UART9_handle, Default_handle

   .weak      IRQ_UART10_handle
   .thumb_set IRQ_UART10_handle, Default_handle

   .weak      IRQ_QUADSPI_handle
   .thumb_set IRQ_QUADSPI_handle, Default_handle

   .weak      IRQ_FMPI2C1_EV_handle
   .thumb_set IRQ_FMPI2C1_EV_handle, Default_handle

   .weak      IRQ_FMPI2C1_ER_handle
   .thumb_set IRQ_FMPI2C1_ER_handle, Default_handle
   
   .weak      IRQ_LPTIM1_handle
   .thumb_set IRQ_LPTIM1_handle, Default_handle

   .weak      IRQ_DFSDM2_FLT0_handle
   .thumb_set IRQ_DFSDM2_FLT0_handle, Default_handle

   .weak      IRQ_DFSDM2_FLT1_handle
   .thumb_set IRQ_DFSDM2_FLT1_handle, Default_handle

   .weak      IRQ_DFSDM2_FLT2_handle
   .thumb_set IRQ_DFSDM2_FLT2_handle, Default_handle

   .weak      IRQ_DFSDM2_FLT3_handle
   .thumb_set IRQ_DFSDM2_FLT3_handle, Default_handle

.section .text.Default_handle,"ax",%progbits
Default_handle:
  Default_handle_loop:
    B Default_handle_loop
.size Default_handle, .-Default_handle

