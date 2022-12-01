#include <stdint.h>
#include "hal/rcc.h"
#include "hal/system.h"
#include "hal/util.h"
#include "hal/gpio.h"

#define RCC_APB2ENR_SYSCFG_MASK          (0x1ul << 14u)

inline void HalRcc_enableGpioClock(size_t gpioIndex) {
    SET_BIT(HAL_RCC->AHB1ENR, 0x1ul << gpioIndex);
}

inline void HalRcc_enableSysConfigClock() {
    SET_BIT(HAL_RCC->APB2ENR, RCC_APB2ENR_SYSCFG_MASK);
}

// TODO __HAL_RCC_PWR_CLK_ENABLE

