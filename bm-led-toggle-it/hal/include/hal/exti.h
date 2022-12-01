#ifndef HAL_EXTI_H
#define HAL_EXTI_H

#include <stdint.h>

void HalExti_clearInterrupt(uint32_t pin);

uint32_t HalExti_getInterrupt(uint32_t pin);

void HalExtiGpio_setCallback(void (*callback)(uint32_t));

void HalExtiGpio_handle(uint32_t pin);

#endif // HAL_EXTI_H
