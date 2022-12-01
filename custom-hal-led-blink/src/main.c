
#include "gpio.h"
#include "rcc.h"
#include "timer.h"

static void configureGpio(void);

int main() {
    Timer_configure(0u);
    configureGpio();

    while (1) {
        if (Gpio_read(GPIOC, GPIO_PIN_13)) {
            while (1) {
                Gpio_toggle(GPIOB, GPIO_PIN_7);
                Timer_delay(500);
            }
        }
    }
}

static void configureGpio(void) {
    Gpio_initPort(GPIOB);
    Gpio_initPort(GPIOC);

    Gpio_writePin(GPIOB, GPIO_PIN_7, GPIOSTATE_RESET);

    GpioConfig pinB7Config = {
            .pin = GPIO_PIN_7,
            .mode = GPIOCONFIG_MODE_OUTPUT_PP,
            .pull = GPIOCONFIG_PULL_NONE,
            .speed = GPIOCONFIG_SPEED_LOW,
    };
    Gpio_initPin(GPIOB, &pinB7Config);

    GpioConfig pinC13Config = {
            .pin = GPIO_PIN_13,
            .mode = GPIOCONFIG_MODE_INPUT,
            .pull = GPIOCONFIG_PULL_NONE,
    };
    Gpio_initPin(GPIOC, &pinC13Config);
}