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

  .word     WWDG_IRQ_handle                   /* Window WatchDog                             */
  .word     PVD_IRQ_handle                    /* PVD through EXTI Line detection             */
  .word     TAMP_STAMP_IRQ_handle             /* Tamper and TimeStamps through the EXTI line */
  .word     RTC_WKUP_IRQ_handle               /* RTC Wakeup through the EXTI line            */
  .word     FLASH_IRQ_handle                  /* FLASH                                       */
  .word     RCC_IRQ_handle                    /* RCC                                         */
  .word     EXTI0_IRQ_handle                  /* EXTI Line0                                  */
  .word     EXTI1_IRQ_handle                  /* EXTI Line1                                  */
  .word     EXTI2_IRQ_handle                  /* EXTI Line2                                  */
  .word     EXTI3_IRQ_handle                  /* EXTI Line3                                  */
  .word     EXTI4_IRQ_handle                  /* EXTI Line4                                  */
  .word     DMA1_STREAM0_IRQ_handle           /* DMA1 STREAM 0                               */
  .word     DMA1_STREAM1_IRQ_handle           /* DMA1 STREAM 1                               */
  .word     DMA1_STREAM2_IRQ_handle           /* DMA1 STREAM 2                               */
  .word     DMA1_STREAM3_IRQ_handle           /* DMA1 STREAM 3                               */
  .word     DMA1_STREAM4_IRQ_handle           /* DMA1 STREAM 4                               */
  .word     DMA1_STREAM5_IRQ_handle           /* DMA1 STREAM 5                               */
  .word     DMA1_STREAM6_IRQ_handle           /* DMA1 STREAM 6                               */
  .word     ADC_IRQ_handle                    /* ADC1, ADC2 and ADC3s                        */
  .word     CAN1_TX_IRQ_handle                /* CAN1 TX                                     */
  .word     CAN1_RX0_IRQ_handle               /* CAN1 RX0                                    */
  .word     CAN1_RX1_IRQ_handle               /* CAN1 RX1                                    */
  .word     CAN1_SCE_IRQ_handle               /* CAN1 SCE                                    */
  .word     EXTI9_5_IRQ_handle                /* External Line[9:5]s                         */
  .word     TIM1_BRK_TIM9_IRQ_handle          /* TIM1 Break and TIM9                         */
  .word     TIM1_UP_TIM10_IRQ_handle          /* TIM1 Update and TIM10                       */
  .word     TIM1_TRG_COM_TIM11_IRQ_handle     /* TIM1 Trigger and Commutation and TIM11      */
  .word     TIM1_CC_IRQ_handle                /* TIM1 Capture Compare                        */
  .word     TIM2_IRQ_handle                   /* TIM2                                        */
  .word     TIM3_IRQ_handle                   /* TIM3                                        */
  .word     TIM4_IRQ_handle                   /* TIM4                                        */
  .word     I2C1_EV_IRQ_handle                /* I2C1 Event                                  */
  .word     I2C1_ER_IRQ_handle                /* I2C1 Error                                  */
  .word     I2C2_EV_IRQ_handle                /* I2C2 Event                                  */
  .word     I2C2_ER_IRQ_handle                /* I2C2 Error                                  */
  .word     SPI1_IRQ_handle                   /* SPI1                                        */
  .word     SPI2_IRQ_handle                   /* SPI2                                        */
  .word     USART1_IRQ_handle                 /* USART1                                      */
  .word     USART2_IRQ_handle                 /* USART2                                      */
  .word     USART3_IRQ_handle                 /* USART3                                      */
  .word     EXTI15_10_IRQ_handle              /* External Line[15:10]s                       */
  .word     RTC_Alarm_IRQ_handle              /* RTC Alarm (A and B) through EXTI Line       */
  .word     OTG_FS_WKUP_IRQ_handle            /* USB OTG FS Wakeup through EXTI line         */
  .word     TIM8_BRK_TIM12_IRQ_handle         /* TIM8 Break and TIM12                        */
  .word     TIM8_UP_TIM13_IRQ_handle          /* TIM8 Update and TIM13                       */
  .word     TIM8_TRG_COM_TIM14_IRQ_handle     /* TIM8 Trigger and Commutation and TIM14      */
  .word     TIM8_CC_IRQ_handle                /* TIM8 Capture Compare                        */
  .word     DMA1_STREAM7_IRQ_handle           /* DMA1 STREAM7                                */
  .word     FSMC_IRQ_handle                   /* FSMC                                        */
  .word     SDIO_IRQ_handle                   /* SDIO                                        */
  .word     TIM5_IRQ_handle                   /* TIM5                                        */
  .word     SPI3_IRQ_handle                   /* SPI3                                        */
  .word     UART4_IRQ_handle                  /* UART4                                       */
  .word     UART5_IRQ_handle                  /* UART5                                       */
  .word     TIM6_DAC_IRQ_handle               /* TIM6, DAC1 and DAC2                         */
  .word     TIM7_IRQ_handle                   /* TIM7                                        */
  .word     DMA2_STREAM0_IRQ_handle           /* DMA2 STREAM 0                               */
  .word     DMA2_STREAM1_IRQ_handle           /* DMA2 STREAM 1                               */
  .word     DMA2_STREAM2_IRQ_handle           /* DMA2 STREAM 2                               */
  .word     DMA2_STREAM3_IRQ_handle           /* DMA2 STREAM 3                               */
  .word     DMA2_STREAM4_IRQ_handle           /* DMA2 STREAM 4                               */
  .word     DFSDM1_FLT0_IRQ_handle            /* DFSDM1 Filter0                              */
  .word     DFSDM1_FLT1_IRQ_handle            /* DFSDM1 Filter1                              */
  .word     CAN2_TX_IRQ_handle                /* CAN2 TX                                     */
  .word     CAN2_RX0_IRQ_handle               /* CAN2 RX0                                    */
  .word     CAN2_RX1_IRQ_handle               /* CAN2 RX1                                    */
  .word     CAN2_SCE_IRQ_handle               /* CAN2 SCE                                    */
  .word     OTG_FS_IRQ_handle                 /* USB OTG FS                                  */
  .word     DMA2_STREAM5_IRQ_handle           /* DMA2 STREAM 5                               */
  .word     DMA2_STREAM6_IRQ_handle           /* DMA2 STREAM 6                               */
  .word     DMA2_STREAM7_IRQ_handle           /* DMA2 STREAM 7                               */
  .word     USART6_IRQ_handle                 /* USART6                                      */
  .word     I2C3_EV_IRQ_handle                /* I2C3 event                                  */
  .word     I2C3_ER_IRQ_handle                /* I2C3 error                                  */
  .word     CAN3_TX_IRQ_handle                /* CAN3 TX                                     */
  .word     CAN3_RX0_IRQ_handle               /* CAN3 RX0                                    */
  .word     CAN3_RX1_IRQ_handle               /* CAN3 RX1                                    */
  .word     CAN3_SCE_IRQ_handle               /* CAN3 SCE                                    */
  .word     0                                 /* Reserved                                    */
  .word     0                                 /* Reserved                                    */
  .word     RNG_IRQ_handle                    /* RNG                                         */
  .word     FPU_IRQ_handle                    /* FPU                                         */
  .word     UART7_IRQ_handle                  /* UART7                                       */
  .word     UART8_IRQ_handle                  /* UART8                                       */
  .word     SPI4_IRQ_handle                   /* SPI4                                        */
  .word     SPI5_IRQ_handle                   /* SPI5                                        */
  .word     0                                 /* Reserved                                    */
  .word     SAI1_IRQ_handle                   /* SAI1                                        */
  .word     UART9_IRQ_handle                  /* UART9                                       */
  .word     UART10_IRQ_handle                 /* UART10                                      */
  .word     0                                 /* Reserved                                    */
  .word     0                                 /* Reserved                                    */
  .word     QUADSPI_IRQ_handle                /* QuadSPI                                     */
  .word     0                                 /* Reserved                                    */
  .word     0                                 /* Reserved                                    */
  .word     FMPI2C1_EV_IRQ_handle             /* FMPI2C1 Event                               */
  .word     FMPI2C1_ER_IRQ_handle             /* FMPI2C1 Error                               */
  .word     LPTIM1_IRQ_handle                 /* LPTIM1                                      */
  .word     DFSDM2_FLT0_IRQ_handle            /* DFSDM2 Filter0                              */
  .word     DFSDM2_FLT1_IRQ_handle            /* DFSDM2 Filter1                              */
  .word     DFSDM2_FLT2_IRQ_handle            /* DFSDM2 Filter2                              */
  .word     DFSDM2_FLT3_IRQ_handle            /* DFSDM2 Filter3                              */
  
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

   .weak      WWDG_IRQ_handle
   .thumb_set WWDG_IRQ_handle, Default_handle

   .weak      PVD_IRQ_handle
   .thumb_set PVD_IRQ_handle, Default_handle

   .weak      TAMP_STAMP_IRQ_handle
   .thumb_set TAMP_STAMP_IRQ_handle, Default_handle

   .weak      RTC_WKUP_IRQ_handle
   .thumb_set RTC_WKUP_IRQ_handle, Default_handle

   .weak      FLASH_IRQ_handle
   .thumb_set FLASH_IRQ_handle, Default_handle

   .weak      RCC_IRQ_handle
   .thumb_set RCC_IRQ_handle, Default_handle

   .weak      EXTI0_IRQ_handle
   .thumb_set EXTI0_IRQ_handle, Default_handle

   .weak      EXTI1_IRQ_handle
   .thumb_set EXTI1_IRQ_handle, Default_handle

   .weak      EXTI2_IRQ_handle
   .thumb_set EXTI2_IRQ_handle, Default_handle

   .weak      EXTI3_IRQ_handle
   .thumb_set EXTI3_IRQ_handle, Default_handle

   .weak      EXTI4_IRQ_handle
   .thumb_set EXTI4_IRQ_handle, Default_handle

   .weak      DMA1_STREAM0_IRQ_handle
   .thumb_set DMA1_STREAM0_IRQ_handle, Default_handle

   .weak      DMA1_STREAM1_IRQ_handle
   .thumb_set DMA1_STREAM1_IRQ_handle, Default_handle

   .weak      DMA1_STREAM2_IRQ_handle
   .thumb_set DMA1_STREAM2_IRQ_handle, Default_handle

   .weak      DMA1_STREAM3_IRQ_handle
   .thumb_set DMA1_STREAM3_IRQ_handle, Default_handle

   .weak      DMA1_STREAM4_IRQ_handle
   .thumb_set DMA1_STREAM4_IRQ_handle, Default_handle

   .weak      DMA1_STREAM5_IRQ_handle
   .thumb_set DMA1_STREAM5_IRQ_handle, Default_handle

   .weak      DMA1_STREAM6_IRQ_handle
   .thumb_set DMA1_STREAM6_IRQ_handle, Default_handle

   .weak      ADC_IRQ_handle
   .thumb_set ADC_IRQ_handle, Default_handle

   .weak      CAN1_TX_IRQ_handle
   .thumb_set CAN1_TX_IRQ_handle, Default_handle

   .weak      CAN1_RX0_IRQ_handle
   .thumb_set CAN1_RX0_IRQ_handle, Default_handle

   .weak      CAN1_RX1_IRQ_handle
   .thumb_set CAN1_RX1_IRQ_handle, Default_handle

   .weak      CAN1_SCE_IRQ_handle
   .thumb_set CAN1_SCE_IRQ_handle, Default_handle

   .weak      EXTI9_5_IRQ_handle
   .thumb_set EXTI9_5_IRQ_handle, Default_handle

   .weak      TIM1_BRK_TIM9_IRQ_handle
   .thumb_set TIM1_BRK_TIM9_IRQ_handle, Default_handle

   .weak      TIM1_UP_TIM10_IRQ_handle
   .thumb_set TIM1_UP_TIM10_IRQ_handle, Default_handle

   .weak      TIM1_TRG_COM_TIM11_IRQ_handle
   .thumb_set TIM1_TRG_COM_TIM11_IRQ_handle, Default_handle

   .weak      TIM1_CC_IRQ_handle
   .thumb_set TIM1_CC_IRQ_handle, Default_handle

   .weak      TIM2_IRQ_handle
   .thumb_set TIM2_IRQ_handle, Default_handle

   .weak      TIM3_IRQ_handle
   .thumb_set TIM3_IRQ_handle, Default_handle

   .weak      TIM4_IRQ_handle
   .thumb_set TIM4_IRQ_handle, Default_handle

   .weak      I2C1_EV_IRQ_handle
   .thumb_set I2C1_EV_IRQ_handle, Default_handle

   .weak      I2C1_ER_IRQ_handle
   .thumb_set I2C1_ER_IRQ_handle, Default_handle

   .weak      I2C2_EV_IRQ_handle
   .thumb_set I2C2_EV_IRQ_handle, Default_handle

   .weak      I2C2_ER_IRQ_handle
   .thumb_set I2C2_ER_IRQ_handle, Default_handle

   .weak      SPI1_IRQ_handle
   .thumb_set SPI1_IRQ_handle, Default_handle

   .weak      SPI2_IRQ_handle
   .thumb_set SPI2_IRQ_handle, Default_handle

   .weak      USART1_IRQ_handle
   .thumb_set USART1_IRQ_handle, Default_handle

   .weak      USART2_IRQ_handle
   .thumb_set USART2_IRQ_handle, Default_handle

   .weak      USART3_IRQ_handle
   .thumb_set USART3_IRQ_handle, Default_handle

   .weak      EXTI15_10_IRQ_handle
   .thumb_set EXTI15_10_IRQ_handle, Default_handle

   .weak      RTC_Alarm_IRQ_handle
   .thumb_set RTC_Alarm_IRQ_handle, Default_handle

   .weak      OTG_FS_WKUP_IRQ_handle
   .thumb_set OTG_FS_WKUP_IRQ_handle, Default_handle

   .weak      TIM8_BRK_TIM12_IRQ_handle
   .thumb_set TIM8_BRK_TIM12_IRQ_handle, Default_handle

   .weak      TIM8_UP_TIM13_IRQ_handle
   .thumb_set TIM8_UP_TIM13_IRQ_handle, Default_handle

   .weak      TIM8_TRG_COM_TIM14_IRQ_handle
   .thumb_set TIM8_TRG_COM_TIM14_IRQ_handle, Default_handle

   .weak      TIM8_CC_IRQ_handle
   .thumb_set TIM8_CC_IRQ_handle, Default_handle

   .weak      DMA1_STREAM7_IRQ_handle
   .thumb_set DMA1_STREAM7_IRQ_handle, Default_handle
   
   .weak      FSMC_IRQ_handle
   .thumb_set FSMC_IRQ_handle, Default_handle

   .weak      SDIO_IRQ_handle
   .thumb_set SDIO_IRQ_handle, Default_handle

   .weak      TIM5_IRQ_handle
   .thumb_set TIM5_IRQ_handle, Default_handle

   .weak      SPI3_IRQ_handle
   .thumb_set SPI3_IRQ_handle, Default_handle
   
   .weak      UART4_IRQ_handle
   .thumb_set UART4_IRQ_handle, Default_handle

   .weak      UART5_IRQ_handle
   .thumb_set UART5_IRQ_handle, Default_handle

   .weak      TIM6_DAC_IRQ_handle
   .thumb_set TIM6_DAC_IRQ_handle, Default_handle

   .weak      TIM7_IRQ_handle
   .thumb_set TIM7_IRQ_handle, Default_handle

   .weak      DMA2_STREAM0_IRQ_handle
   .thumb_set DMA2_STREAM0_IRQ_handle, Default_handle

   .weak      DMA2_STREAM1_IRQ_handle
   .thumb_set DMA2_STREAM1_IRQ_handle, Default_handle

   .weak      DMA2_STREAM2_IRQ_handle
   .thumb_set DMA2_STREAM2_IRQ_handle, Default_handle

   .weak      DMA2_STREAM3_IRQ_handle
   .thumb_set DMA2_STREAM3_IRQ_handle, Default_handle

   .weak      DMA2_STREAM4_IRQ_handle
   .thumb_set DMA2_STREAM4_IRQ_handle, Default_handle

   .weak      DFSDM1_FLT0_IRQ_handle
   .thumb_set DFSDM1_FLT0_IRQ_handle, Default_handle

   .weak      DFSDM1_FLT1_IRQ_handle
   .thumb_set DFSDM1_FLT1_IRQ_handle, Default_handle

   .weak      CAN2_TX_IRQ_handle
   .thumb_set CAN2_TX_IRQ_handle, Default_handle

   .weak      CAN2_RX0_IRQ_handle
   .thumb_set CAN2_RX0_IRQ_handle, Default_handle

   .weak      CAN2_RX1_IRQ_handle
   .thumb_set CAN2_RX1_IRQ_handle, Default_handle

   .weak      CAN2_SCE_IRQ_handle
   .thumb_set CAN2_SCE_IRQ_handle, Default_handle

   .weak      OTG_FS_IRQ_handle
   .thumb_set OTG_FS_IRQ_handle, Default_handle

   .weak      DMA2_STREAM5_IRQ_handle
   .thumb_set DMA2_STREAM5_IRQ_handle, Default_handle

   .weak      DMA2_STREAM6_IRQ_handle
   .thumb_set DMA2_STREAM6_IRQ_handle, Default_handle

   .weak      DMA2_STREAM7_IRQ_handle
   .thumb_set DMA2_STREAM7_IRQ_handle, Default_handle

   .weak      USART6_IRQ_handle
   .thumb_set USART6_IRQ_handle, Default_handle

   .weak      I2C3_EV_IRQ_handle
   .thumb_set I2C3_EV_IRQ_handle, Default_handle

   .weak      I2C3_ER_IRQ_handle
   .thumb_set I2C3_ER_IRQ_handle, Default_handle
   
   .weak      CAN3_TX_IRQ_handle
   .thumb_set CAN3_TX_IRQ_handle, Default_handle

   .weak      CAN3_RX0_IRQ_handle
   .thumb_set CAN3_RX0_IRQ_handle, Default_handle

   .weak      CAN3_RX1_IRQ_handle
   .thumb_set CAN3_RX1_IRQ_handle, Default_handle

   .weak      CAN3_SCE_IRQ_handle
   .thumb_set CAN3_SCE_IRQ_handle, Default_handle

   .weak      RNG_IRQ_handle
   .thumb_set RNG_IRQ_handle, Default_handle

   .weak      FPU_IRQ_handle
   .thumb_set FPU_IRQ_handle, Default_handle
   
   .weak      UART7_IRQ_handle
   .thumb_set UART7_IRQ_handle, Default_handle

   .weak      UART8_IRQ_handle
   .thumb_set UART8_IRQ_handle, Default_handle

   .weak      SPI4_IRQ_handle
   .thumb_set SPI4_IRQ_handle, Default_handle

   .weak      SPI5_IRQ_handle
   .thumb_set SPI5_IRQ_handle, Default_handle
   
   .weak      SAI1_IRQ_handle
   .thumb_set SAI1_IRQ_handle, Default_handle

   .weak      UART9_IRQ_handle
   .thumb_set UART9_IRQ_handle, Default_handle

   .weak      UART10_IRQ_handle
   .thumb_set UART10_IRQ_handle, Default_handle

   .weak      QUADSPI_IRQ_handle
   .thumb_set QUADSPI_IRQ_handle, Default_handle

    .weak     FMPI2C1_EV_IRQ_handle
   .thumb_set FMPI2C1_EV_IRQ_handle, Default_handle

   .weak      FMPI2C1_ER_IRQ_handle
   .thumb_set FMPI2C1_ER_IRQ_handle, Default_handle
   
   .weak      LPTIM1_IRQ_handle
   .thumb_set LPTIM1_IRQ_handle, Default_handle

   .weak      DFSDM2_FLT0_IRQ_handle
   .thumb_set DFSDM2_FLT0_IRQ_handle, Default_handle

   .weak      DFSDM2_FLT1_IRQ_handle
   .thumb_set DFSDM2_FLT1_IRQ_handle, Default_handle

   .weak      DFSDM2_FLT2_IRQ_handle
   .thumb_set DFSDM2_FLT2_IRQ_handle, Default_handle

   .weak      DFSDM2_FLT3_IRQ_handle
   .thumb_set DFSDM2_FLT3_IRQ_handle, Default_handle

.section .text.Default_handle,"ax",%progbits
Default_handle:
  Default_handle_loop:
    B Default_handle_loop
.size Default_handle, .-Default_handle

