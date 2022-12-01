#ifndef HAL_TIMER_H
#define HAL_TIMER_H

#include <stdint.h>
#include "util.h"
#include "rcc.h"
#include "systick.h"

HalStatus Timer_configure(uint32_t priority) {
    if (SysTick_configure(SYSTEM_CORE_CLOCK / 1000u) != HAL_OK) {
        return HAL_ERROR;
    }

    if (priority < (1ul << NVIC_PRIORITY_BITS)) {
        Nvic_setPriorityPreemptSub(IRQ_SYSTICK, priority, 0u);
    } else {
        return HAL_ERROR;
    }

    return HAL_OK;
}

void Timer_delay(uint32_t delayTicks) {
    uint32_t currentTick = SysTick_currentTick;

    while (SysTick_currentTick - currentTick < delayTicks) {
    }
}

#endif // HAL_TIMER_H
