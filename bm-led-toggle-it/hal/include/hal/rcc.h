#ifndef HAL_RCC_H
#define HAL_RCC_H

#include <stddef.h>
#include "hal/gpio.h"

void HalRcc_enableGpioClock(size_t gpioPortIndex);

void HalRcc_enableSysConfigClock();

#endif // HAL_RCC_H
