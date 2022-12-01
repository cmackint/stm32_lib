#include <stdint.h>
#include "hal/systick.h"
#include "hal/system.h"
#include "hal/nvic.h"
#include "hal/util.h"

#define SYSTICK_LOAD_MASK                   (0xFFFFFFul)
#define SYSTICK_CONTROL_ENABLE_MASK         (0x1ul)
#define SYSTICK_CONTROL_TICKINT_MASK        (0x1ul << 1ul)
#define SYSTICK_CONTROL_CLOCKSOURCE_MASK    (0x1ul << 2ul)

volatile uint32_t SysTick_currentTick = 0;

HalStatus SysTick_configure(uint32_t ticks) {
    if ((ticks - 1) > SYSTICK_LOAD_MASK) {
        return 1;
    }

    HAL_SYSTICK->LOAD = (uint32_t) (ticks - 1);
    HalNvic_setPriority(IRQ_SYSTICK, (1ul << HAL_NVIC_PRIORITY_BITS) - 1ul);
    HAL_SYSTICK->VAL = 0ul;
    HAL_SYSTICK->CTRL = SYSTICK_CONTROL_ENABLE_MASK |
            SYSTICK_CONTROL_TICKINT_MASK |
            SYSTICK_CONTROL_CLOCKSOURCE_MASK;

    return 0;
}
