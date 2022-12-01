#ifndef HAL_STM32F413XX_H
#define HAL_STM32F413XX_H

extern const uint32_t SYSTEM_CORE_CLOCK;
extern const uint8_t AHB_PRESC_TABLE[16];
extern const uint8_t APB_PRESC_TABLE[8];

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

typedef struct {
    volatile uint32_t CTRL;
    volatile uint32_t LOAD;
    volatile uint32_t VAL;
    volatile const uint32_t CALIB;
} SysTick;

#define SYSTICK               ((SysTick *) SYSTICK_BASE)

typedef struct {
    volatile uint32_t ISER[8U];               // Interrupt set enable
    uint32_t RESERVED0[24U];
    volatile uint32_t ICER[8U];               // Interrupt clear enable
    uint32_t RSERVED1[24U];
    volatile uint32_t ISPR[8U];               // Interrupt set pending
    uint32_t RESERVED2[24U];
    volatile uint32_t ICPR[8U];               // Interrupt clear pending
    uint32_t RESERVED3[24U];
    volatile uint32_t IABR[8U];               // Interrupt active bit
    uint32_t RESERVED4[56U];
    volatile uint8_t  IP[240U];               // Interrupt priority
    uint32_t RESERVED5[644U];
    volatile uint32_t STIR;                   // Software trigger interrupt
}  Nvic;

#define NVIC                  ((Nvic *) NVIC_BASE)

typedef struct {
    volatile const  uint32_t CPUID;           // CPUID base
    volatile uint32_t ICSR;                   // Interrupt control and state
    volatile uint32_t VTOR;                   // Vector table offset
    volatile uint32_t AIRCR;                  // Application interrupt and reset control
    volatile uint32_t SCR;                    // System control
    volatile uint32_t CCR;                    // Configuration control
    volatile uint8_t  SHP[12U];               // System handlers priority
    volatile uint32_t SHCSR;                  // System handler control and state
    volatile uint32_t CFSR;                   // Configurable fault status
    volatile uint32_t HFSR;                   // HardFault status
    volatile uint32_t DFSR;                   // Debug fault status
    volatile uint32_t MMFAR;                  // MemManage fault address
    volatile uint32_t BFAR;                   // BusFault address
    volatile uint32_t AFSR;                   // Auxiliary fault status
    volatile const  uint32_t PFR[2U];         // Processor feature
    volatile const  uint32_t DFR;             // Debug feature
    volatile const  uint32_t ADR;             // Auxiliary feature
    volatile const  uint32_t MMFR[4U];        // Memory model feature
    volatile const  uint32_t ISAR[5U];        // Instruction set attributes
    uint32_t RESERVED0[5U];
    volatile uint32_t CPACR;                  // Coprocessor access control
} Scb;

#define SCB ((Scb *) SCB_BASE)

#define APB1PERIPH_BASE       (PERIPH_BASE)
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000ul)
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000ul)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x10000000ul)

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

typedef struct {
    volatile uint32_t MODER;    // Mode
    volatile uint32_t OTYPER;   // Output type
    volatile uint32_t OSPEEDR;  // Output speed
    volatile uint32_t PUPDR;    // Pull-up/pull-down
    volatile uint32_t IDR;      // Input data
    volatile uint32_t ODR;      // Output data
    volatile uint32_t BSRR;     // Bit set/reset
    volatile uint32_t LCKR;     // Configuration lock
    volatile uint32_t AFR[2];   // Alternate functions
} GpioPort;

#define GPIOA               ((GpioPort *) GPIOA_BASE)
#define GPIOB               ((GpioPort *) GPIOB_BASE)
#define GPIOC               ((GpioPort *) GPIOC_BASE)
#define GPIOD               ((GpioPort *) GPIOD_BASE)
#define GPIOE               ((GpioPort *) GPIOE_BASE)
#define GPIOF               ((GpioPort *) GPIOF_BASE)
#define GPIOG               ((GpioPort *) GPIOG_BASE)
#define GPIOH               ((GpioPort *) GPIOH_BASE)

typedef struct
{
    volatile uint32_t CR;           // Clock control
    volatile uint32_t PLLCFGR;      // PLL configuration
    volatile uint32_t CFGR;         // Clock configuration
    volatile uint32_t CIR;          // Clock interrupt
    volatile uint32_t AHB1RSTR;     // AHB1 peripheral
    volatile uint32_t AHB2RSTR;     // AHB2 peripheral
    volatile uint32_t AHB3RSTR;     // AHB3 peripheral
    uint32_t      RESERVED0;        // Reserved
    volatile uint32_t APB1RSTR;     // APB1 peripheral reset
    volatile uint32_t APB2RSTR;     // APB2 peripheral reset
    uint32_t      RESERVED1[2];     // Reserved
    volatile uint32_t AHB1ENR;      // AHB1 peripheral clock
    volatile uint32_t AHB2ENR;      // AHB2 peripheral clock
    volatile uint32_t AHB3ENR;      // AHB3 peripheral clock
    uint32_t      RESERVED2;        // Reserved
    volatile uint32_t APB1ENR;      // APB1 peripheral clock enable
    volatile uint32_t APB2ENR;      // APB2 peripheral clock enable
    uint32_t      RESERVED3[2];     // Reserved
    volatile uint32_t AHB1LPENR;    // AHB1 peripheral clock enable in low power mode
    volatile uint32_t AHB2LPENR;    // AHB2 peripheral clock enable in low power mode
    volatile uint32_t AHB3LPENR;    // AHB3 peripheral clock enable in low power mode
    uint32_t      RESERVED4;        // Reserved
    volatile uint32_t APB1LPENR;    // APB1 peripheral clock enable in low power mode
    volatile uint32_t APB2LPENR;    // APB2 peripheral clock enable in low power mode
    uint32_t      RESERVED5[2];     // Reserved
    volatile uint32_t BDCR;         // Backup domain control
    volatile uint32_t CSR;          // Clock control & status
    uint32_t      RESERVED6[2];     // Reserved
    volatile uint32_t SSCGR;        // Spread spectrum clock generation
    volatile uint32_t PLLI2SCFGR;   // PLLI2S configuration
    uint32_t      RESERVED7;        // Reserved
    volatile uint32_t DCKCFGR;      // Dedicated clocks configuration
    volatile uint32_t CKGATENR;     // Clocks gated enable
    volatile uint32_t DCKCFGR2;     // Dedicated clocks configuration register 2
} Rcc;

#define RCC         ((Rcc *) RCC_BASE)


#endif // HAL_STM32F413XX_H
