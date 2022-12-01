#include "hal/timer.h"

HalStatus HalTimer_configure(uint32_t priority) {
    if (SysTick_configure(SYSTEM_CORE_CLOCK / 1000u) != HAL_OK) {
        return HAL_ERROR;
    }

    if (priority < (1ul << HAL_NVIC_PRIORITY_BITS)) {
        HalNvic_setPriorityPreemptSub(IRQ_SYSTICK, priority, 0u);
    } else {
        return HAL_ERROR;
    }

    return HAL_OK;
}

void HalTimer_delay(uint32_t delayTicks) {
    uint32_t currentTick = SysTick_currentTick;

    while (SysTick_currentTick - currentTick < delayTicks) {
    }
}
