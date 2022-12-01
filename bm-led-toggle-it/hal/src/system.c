
#include <stdint.h>
#include "hal/system.h"

const uint32_t SYSTEM_CORE_CLOCK = 16000000;
const uint8_t AHB_PRESC_TABLE[16] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};
const uint8_t APB_PRESC_TABLE[8]  = {0, 0, 0, 0, 1, 2, 3, 4};

#define FLASH_BASE            (0x08000000ul)
#define SRAM1_BASE            (0x20000000ul)
#define SRAM2_BASE            (0x20040000ul)
#define PERIPH_BASE           (0x40000000ul)
#define FSMC_R_BASE           (0xA0000000ul)
#define QSPI_R_BASE           (0xA0001000ul)
#define SRAM1_BB_BASE         (0x22000000ul)
#define SRAM2_BB_BASE         (0x22800000ul)
#define PERIPH_BB_BASE        (0x42000000ul)
#define FLASH_END             (0x0817FFFFul)
#define FLASH_OTP_BASE        (0x1FFF7800ul)
#define FLASH_OTP_END         (0x1FFF7A0Ful)

#define SCS_BASE              (0xE000E000ul)
#define ITM_BASE              (0xE0000000ul)
#define DWT_BASE              (0xE0001000ul)
#define TPI_BASE              (0xE0040000ul)
#define COREDEBUG_BASE        (0xE000EDF0ul)

#define SYSTICK_BASE          (SCS_BASE + 0x0010ul)
#define NVIC_BASE             (SCS_BASE + 0x0100ul)
#define SCB_BASE              (SCS_BASE + 0x0D00ul)

///////////////////////////////////////////////////////////////////////////////
// SysTick Peripherals
///////////////////////////////////////////////////////////////////////////////

HalSysTickReg * const HAL_SYSTICK = (HalSysTickReg *) SYSTICK_BASE;

///////////////////////////////////////////////////////////////////////////////
// NVIC Peripherals
///////////////////////////////////////////////////////////////////////////////

HalNvicReg * const HAL_NVIC = (HalNvicReg *) NVIC_BASE;

///////////////////////////////////////////////////////////////////////////////
// SCB Peripherals
///////////////////////////////////////////////////////////////////////////////

HalScbReg * const HAL_SCB = (HalScbReg *) SCB_BASE;

///////////////////////////////////////////////////////////////////////////////
// AHB1 Peripherals
///////////////////////////////////////////////////////////////////////////////

#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000ul)
#define GPIOA_BASE            (AHB1PERIPH_BASE + 0x0000ul)
#define GPIOB_BASE            (AHB1PERIPH_BASE + 0x0400ul)
#define GPIOC_BASE            (AHB1PERIPH_BASE + 0x0800ul)
#define GPIOD_BASE            (AHB1PERIPH_BASE + 0x0C00ul)
#define GPIOE_BASE            (AHB1PERIPH_BASE + 0x1000ul)
#define GPIOF_BASE            (AHB1PERIPH_BASE + 0x1400ul)
#define GPIOG_BASE            (AHB1PERIPH_BASE + 0x1800ul)
#define GPIOH_BASE            (AHB1PERIPH_BASE + 0x1C00ul)
#define CRC_BASE              (AHB1PERIPH_BASE + 0x3000ul)
#define RCC_BASE              (AHB1PERIPH_BASE + 0x3800ul)
#define FLASH_R_BASE          (AHB1PERIPH_BASE + 0x3C00ul)
#define DMA1_BASE             (AHB1PERIPH_BASE + 0x6000ul)

HalGpioReg * const HAL_GPIOA = (HalGpioReg *) GPIOA_BASE;
HalGpioReg * const HAL_GPIOB = (HalGpioReg *) GPIOB_BASE;
HalGpioReg * const HAL_GPIOC = (HalGpioReg *) GPIOC_BASE;
HalGpioReg * const HAL_GPIOD = (HalGpioReg *) GPIOD_BASE;
HalGpioReg * const HAL_GPIOE = (HalGpioReg *) GPIOE_BASE;
HalGpioReg * const HAL_GPIOF = (HalGpioReg *) GPIOF_BASE;
HalGpioReg * const HAL_GPIOG = (HalGpioReg *) GPIOG_BASE;
HalGpioReg * const HAL_GPIOH = (HalGpioReg *) GPIOH_BASE;

HalRccReg * const HAL_RCC = (HalRccReg *) RCC_BASE;

///////////////////////////////////////////////////////////////////////////////
// APB1 Peripherals
///////////////////////////////////////////////////////////////////////////////

#define APB1PERIPH_BASE       (PERIPH_BASE)

#define USART2_BASE           (APB1PERIPH_BASE + 0x4400UL)
#define USART3_BASE           (APB1PERIPH_BASE + 0x4800UL)
#define UART4_BASE            (APB1PERIPH_BASE + 0x4C00UL)
#define UART5_BASE            (APB1PERIPH_BASE + 0x5000UL)
#define UART7_BASE            (APB1PERIPH_BASE + 0x7800UL)
#define UART8_BASE            (APB1PERIPH_BASE + 0x7C00UL)

HalUsartReg * const HAL_USART2 = (HalUsartReg *) USART2_BASE;
HalUsartReg * const HAL_USART3 = (HalUsartReg *) USART3_BASE;
HalUsartReg * const HAL_UART4 = (HalUsartReg *) UART4_BASE;
HalUsartReg * const HAL_UART5 = (HalUsartReg *) UART5_BASE;
HalUsartReg * const HAL_UART7 = (HalUsartReg *) UART7_BASE;
HalUsartReg * const HAL_UART8 = (HalUsartReg *) UART8_BASE;


///////////////////////////////////////////////////////////////////////////////
// APB2 Peripherals
///////////////////////////////////////////////////////////////////////////////

#define APB2PERIPH_BASE         (PERIPH_BASE + 0x00010000ul)

#define USART1_BASE             (APB2PERIPH_BASE + 0x1000UL)
#define USART6_BASE             (APB2PERIPH_BASE + 0x1400UL)
#define UART9_BASE              (APB2PERIPH_BASE + 0x1800UL)
#define UART10_BASE             (APB2PERIPH_BASE + 0x1C00UL)
#define SYSCFG_BASE             (APB2PERIPH_BASE + 0x3800ul)
#define EXTI_BASE               (APB2PERIPH_BASE + 0x3C00ul)

HalUsartReg * const HAL_USART1 = (HalUsartReg *) USART1_BASE;
HalUsartReg * const HAL_USART6 = (HalUsartReg *) USART6_BASE;
HalUsartReg * const HAL_UART9 = (HalUsartReg *) UART9_BASE;
HalUsartReg * const HAL_UART10 = (HalUsartReg *) UART10_BASE;

HalSysCfgReg * const HAL_SYSCFG = (HalSysCfgReg *) SYSCFG_BASE;

HalExtiReg * const HAL_EXTI = (HalExtiReg *) EXTI_BASE;
