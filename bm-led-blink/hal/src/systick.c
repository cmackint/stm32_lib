#include <stdint.h>
#include "systick.h"
#include "system.h"
#include "nvic.h"
#include "util.h"

#define SYSTICK_LOAD_MASK                   (0xFFFFFFul)
#define SYSTICK_CONTROL_ENABLE_MASK         (0x1ul)
#define SYSTICK_CONTROL_TICKINT_MASK        (0x1ul << 1ul)
#define SYSTICK_CONTROL_CLOCKSOURCE_MASK    (0x1ul << 2ul)

volatile uint32_t SysTick_currentTick;

HalStatus SysTick_configure(uint32_t ticks) {
    if ((ticks - 1) > SYSTICK_LOAD_MASK) {
        return 1;
    }

    SYSTICK->LOAD = (uint32_t) (ticks - 1);
    Nvic_setPriority(IRQ_SYSTICK, (1ul << NVIC_PRIORITY_BITS) - 1ul);
    SYSTICK->VAL = 0ul;
    SYSTICK->CTRL = SYSTICK_CONTROL_ENABLE_MASK |
            SYSTICK_CONTROL_TICKINT_MASK |
            SYSTICK_CONTROL_CLOCKSOURCE_MASK;

    return 0;
}
