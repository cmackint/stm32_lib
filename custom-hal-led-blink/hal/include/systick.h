#ifndef HAL_SYSTICK_H
#define HAL_SYSTICK_H

#include <stdint.h>
#include "system.h"
#include "nvic.h"
#include "util.h"

volatile uint32_t SysTick_currentTick;

HalStatus SysTick_configure(uint32_t ticks);

#endif // HAL_SYSTICK_H
