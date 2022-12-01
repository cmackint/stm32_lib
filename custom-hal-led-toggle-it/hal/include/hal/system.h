#ifndef HAL_SYSTEM_H
#define HAL_SYSTEM_H

extern const uint32_t SYSTEM_CORE_CLOCK;
extern const uint8_t AHB_PRESC_TABLE[16];
extern const uint8_t APB_PRESC_TABLE[8];

///////////////////////////////////////////////////////////////////////////////
// SysTick Peripherals
///////////////////////////////////////////////////////////////////////////////

typedef struct {
    volatile uint32_t CTRL;
    volatile uint32_t LOAD;
    volatile uint32_t VAL;
    volatile const uint32_t CALIB;
} HalSysTickReg;

extern HalSysTickReg * const HAL_SYSTICK;

///////////////////////////////////////////////////////////////////////////////
// NVIC Peripherals
///////////////////////////////////////////////////////////////////////////////

typedef struct {
    volatile uint32_t ISER[8u];               // Interrupt set enable
    uint32_t RESERVED0[24u];
    volatile uint32_t ICER[8u];               // Interrupt clear enable
    uint32_t RSERVED1[24u];
    volatile uint32_t ISPR[8u];               // Interrupt set pending
    uint32_t RESERVED2[24u];
    volatile uint32_t ICPR[8u];               // Interrupt clear pending
    uint32_t RESERVED3[24u];
    volatile uint32_t IABR[8u];               // Interrupt active bit
    uint32_t RESERVED4[56u];
    volatile uint8_t IP[240u];               // Interrupt priority
    uint32_t RESERVED5[644u];
    volatile uint32_t STIR;                   // Software trigger interrupt
} HalNvicReg;

extern HalNvicReg * const HAL_NVIC;

///////////////////////////////////////////////////////////////////////////////
// SCB Peripherals
///////////////////////////////////////////////////////////////////////////////

typedef struct {
    volatile const uint32_t CPUID;           // CPUID base
    volatile uint32_t ICSR;                   // Interrupt control and state
    volatile uint32_t VTOR;                   // Vector table offset
    volatile uint32_t AIRCR;                  // Application interrupt and reset control
    volatile uint32_t SCR;                    // System control
    volatile uint32_t CCR;                    // Configuration control
    volatile uint8_t SHP[12u];               // System handlers priority
    volatile uint32_t SHCSR;                  // System handler control and state
    volatile uint32_t CFSR;                   // Configurable fault status
    volatile uint32_t HFSR;                   // HardFault status
    volatile uint32_t DFSR;                   // Debug fault status
    volatile uint32_t MMFAR;                  // MemManage fault address
    volatile uint32_t BFAR;                   // BusFault address
    volatile uint32_t AFSR;                   // Auxiliary fault status
    volatile const uint32_t PFR[2u];         // Processor feature
    volatile const uint32_t DFR;             // Debug feature
    volatile const uint32_t ADR;             // Auxiliary feature
    volatile const uint32_t MMFR[4u];        // Memory model feature
    volatile const uint32_t ISAR[5u];        // Instruction set attributes
    uint32_t RESERVED0[5u];
    volatile uint32_t CPACR;                  // Coprocessor access control
} HalScbReg;

extern HalScbReg * const HAL_SCB;

///////////////////////////////////////////////////////////////////////////////
// AHB1 Peripherals
///////////////////////////////////////////////////////////////////////////////

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
} HalGpioReg;

extern HalGpioReg * const HAL_GPIOA;
extern HalGpioReg * const HAL_GPIOB;
extern HalGpioReg * const HAL_GPIOC;
extern HalGpioReg * const HAL_GPIOD;
extern HalGpioReg * const HAL_GPIOE;
extern HalGpioReg * const HAL_GPIOF;
extern HalGpioReg * const HAL_GPIOG;
extern HalGpioReg * const HAL_GPIOH;

typedef struct {
    volatile uint32_t CR;           // Clock control
    volatile uint32_t PLLCFGR;      // PLL configuration
    volatile uint32_t CFGR;         // Clock configuration
    volatile uint32_t CIR;          // Clock interrupt
    volatile uint32_t AHB1RSTR;     // AHB1 peripheral
    volatile uint32_t AHB2RSTR;     // AHB2 peripheral
    volatile uint32_t AHB3RSTR;     // AHB3 peripheral
    uint32_t RESERVED0;        // Reserved
    volatile uint32_t APB1RSTR;     // APB1 peripheral reset
    volatile uint32_t APB2RSTR;     // APB2 peripheral reset
    uint32_t RESERVED1[2];     // Reserved
    volatile uint32_t AHB1ENR;      // AHB1 peripheral clock
    volatile uint32_t AHB2ENR;      // AHB2 peripheral clock
    volatile uint32_t AHB3ENR;      // AHB3 peripheral clock
    uint32_t RESERVED2;        // Reserved
    volatile uint32_t APB1ENR;      // APB1 peripheral clock enable
    volatile uint32_t APB2ENR;      // APB2 peripheral clock enable
    uint32_t RESERVED3[2];     // Reserved
    volatile uint32_t AHB1LPENR;    // AHB1 peripheral clock enable in low power mode
    volatile uint32_t AHB2LPENR;    // AHB2 peripheral clock enable in low power mode
    volatile uint32_t AHB3LPENR;    // AHB3 peripheral clock enable in low power mode
    uint32_t RESERVED4;        // Reserved
    volatile uint32_t APB1LPENR;    // APB1 peripheral clock enable in low power mode
    volatile uint32_t APB2LPENR;    // APB2 peripheral clock enable in low power mode
    uint32_t RESERVED5[2];     // Reserved
    volatile uint32_t BDCR;         // Backup domain control
    volatile uint32_t CSR;          // Clock control & status
    uint32_t RESERVED6[2];     // Reserved
    volatile uint32_t SSCGR;        // Spread spectrum clock generation
    volatile uint32_t PLLI2SCFGR;   // PLLI2S configuration
    uint32_t RESERVED7;        // Reserved
    volatile uint32_t DCKCFGR;      // Dedicated clocks configuration
    volatile uint32_t CKGATENR;     // Clocks gated enable
    volatile uint32_t DCKCFGR2;     // Dedicated clocks configuration 2
} HalRccReg;

extern HalRccReg * const HAL_RCC;

///////////////////////////////////////////////////////////////////////////////
// APB1 Peripherals
///////////////////////////////////////////////////////////////////////////////

typedef struct {
    volatile uint32_t SR;       // Status
    volatile uint32_t DR;       // Data
    volatile uint32_t BRR;      // Baud rate
    volatile uint32_t CR1;      // Control 1
    volatile uint32_t CR2;      // Control 2
    volatile uint32_t CR3;      // Control 3
    volatile uint32_t GTPR;     // Guard time and prescaler
} HalUsartReg;

extern HalUsartReg * const HAL_USART2;
extern HalUsartReg * const HAL_USART3;
extern HalUsartReg * const HAL_UART4;
extern HalUsartReg * const HAL_UART5;
extern HalUsartReg * const HAL_UART7;
extern HalUsartReg * const HAL_UART8;

///////////////////////////////////////////////////////////////////////////////
// APB2 Peripherals
///////////////////////////////////////////////////////////////////////////////

extern HalUsartReg * const HAL_USART1;
extern HalUsartReg * const HAL_USART6;
extern HalUsartReg * const HAL_UART9;
extern HalUsartReg * const HAL_UART10;

typedef struct {
    volatile uint32_t MEMRMP;       // Memory remap
    volatile uint32_t PMC;          // Peripheral mode configuration
    volatile uint32_t EXTICR[4];    // EXTI configuration
    uint32_t RESERVED;         // Reserved
    volatile uint32_t CFGR2;        // Configuration 2
    volatile uint32_t CMPCR;        // Compensation cell control
    uint32_t RESERVED1[2];     // Reserved
    volatile uint32_t CFGR;         // Configuration
    volatile uint32_t MCHDLYCR;     // Multi-channel delay
} HalSysCfgReg;

extern HalSysCfgReg * const HAL_SYSCFG;

typedef struct {
    volatile uint32_t IMR;
    volatile uint32_t EMR;
    volatile uint32_t RTSR;
    volatile uint32_t FTSR;
    volatile uint32_t SWIER;
    volatile uint32_t PR;
} HalExtiReg;

extern HalExtiReg * const HAL_EXTI;

#endif // HAL_SYSTEM_H
