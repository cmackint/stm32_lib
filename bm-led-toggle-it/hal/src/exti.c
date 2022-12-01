#include <stddef.h>
#include "hal/exti.h"
#include "hal/system.h"

static void (*gpioCallback)(uint32_t) = NULL;

inline void HalExti_clearInterrupt(uint32_t pin) {
    HAL_EXTI->PR = pin;
}

inline uint32_t HalExti_getInterrupt(uint32_t pin) {
    return HAL_EXTI->PR & pin;
}

void HalExtiGpio_setCallback(void (*callback)(uint32_t)) {
    gpioCallback = callback;
}

void HalExtiGpio_handle(uint32_t pin) {
    HalExti_clearInterrupt(pin);

    if (gpioCallback != NULL) {
        gpioCallback(pin);
    }
}


