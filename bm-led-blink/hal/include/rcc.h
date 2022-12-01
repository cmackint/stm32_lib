#ifndef HAL_RCC_H
#define HAL_RCC_H

#include <stdint.h>
#include "system.h"

#define RCC_AHB1ENR_GPIOA_MASK           (0x1UL << 0U)
#define RCC_AHB1ENR_GPIOB_MASK           (0x1UL << 1U)
#define RCC_AHB1ENR_GPIOC_MASK           (0x1UL << 2U)
#define RCC_AHB1ENR_GPIOD_MASK           (0x1UL << 3U)
#define RCC_AHB1ENR_GPIOE_MASK           (0x1UL << 4U)
#define RCC_AHB1ENR_GPIOF_MASK           (0x1UL << 5U)
#define RCC_AHB1ENR_GPIOG_MASK           (0x1UL << 6U)
#define RCC_AHB1ENR_GPIOH_MASK           (0x1UL << 7U)
#define RCC_AHB1ENR_CRC_MASK             (0x1UL << 12U)
#define RCC_AHB1ENR_DMA1_MASK            (0x1UL << 21U)
#define RCC_AHB1ENR_DMA2_MASK            (0x1UL << 22U)

#endif // HAL_RCC_H
