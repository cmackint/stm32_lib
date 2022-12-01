
#include <hal/exti.h>
#include <hal/gpio.h>
#include "hal/rcc.h"
#include <hal/timer.h>

static void configureGpio();
static void gpioCallback(uint32_t pin);

int main() {
    HalTimer_configure(0u);
    configureGpio();

    while (1) {
    }
}

static void configureGpio() {
    HalGpio_initPort(HAL_GPIOB);
    HalGpio_initPort(HAL_GPIOC);

    HalGpio_writePin(HAL_GPIOB, GPIO_PIN_7, GPIOSTATE_RESET);

    HalGpioConfig pinB7Config = {
            .pin = GPIO_PIN_7,
            .mode = GPIOCONFIG_MODE_OUTPUT_PP,
            .pull = GPIOCONFIG_PULL_NONE,
            .speed = GPIOCONFIG_SPEED_LOW,
    };
    HalGpio_initPin(HAL_GPIOB, &pinB7Config);

    HalGpioConfig pinC13Config = {
            .pin = GPIO_PIN_13,
            .mode = GPIOCONFIG_MODE_IT_RISING,
            .pull = GPIOCONFIG_PULL_DOWN,
    };
    HalGpio_initPin(HAL_GPIOC, &pinC13Config);

    HalExtiGpio_setCallback(gpioCallback);

    NvicHal_enableIrq(IRQ_EXTI15_10);
}

void gpioCallback(uint32_t pin) {
    if (pin == GPIO_PIN_13) {
        HalGpio_togglePin(HAL_GPIOB, GPIO_PIN_7);
    }
}
