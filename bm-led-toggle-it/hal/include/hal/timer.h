#ifndef HAL_TIMER_H
#define HAL_TIMER_H

#include <stdint.h>
#include "util.h"
#include "rcc.h"
#include "systick.h"

HalStatus HalTimer_configure(uint32_t priority);

void HalTimer_delay(uint32_t delayTicks);

#endif // HAL_TIMER_H
