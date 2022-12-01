#include <stdint.h>
#include <stdbool.h>
#include "gpio.h"
#include "rcc.h"
#include "util.h"

#define GPIO_PORT_TO_MASK \
    X(GPIOA, RCC_AHB1ENR_GPIOA_MASK) \
    X(GPIOB, RCC_AHB1ENR_GPIOB_MASK) \
    X(GPIOC, RCC_AHB1ENR_GPIOC_MASK) \
    X(GPIOD, RCC_AHB1ENR_GPIOD_MASK) \
    X(GPIOE, RCC_AHB1ENR_GPIOE_MASK) \
    X(GPIOF, RCC_AHB1ENR_GPIOF_MASK) \
    X(GPIOG, RCC_AHB1ENR_GPIOG_MASK) \
    X(GPIOH, RCC_AHB1ENR_GPIOH_MASK)

void Gpio_writePin(GpioPort *port, uint16_t pin, GpioState state) {
    if (state == GPIOSTATE_SET) {
        port->BSRR = pin;
    } else {
        port->BSRR = (uint32_t) port << 0x10u;
    }
}

void Gpio_initPin(GpioPort *port, GpioConfig *config) {
    uint32_t currentPin;
    uint32_t currentPinMask;
    uint32_t configPinMask;
    uint32_t temp;

    for (currentPin = 0u; currentPin < 16; currentPin++) {
        currentPinMask = 0x1u << currentPin;
        configPinMask = (uint32_t) (config->pin) & currentPinMask;

        if (configPinMask != currentPinMask) {
            continue;
        }

        temp = port->MODER;
        temp &= ~(GPIOPORT_MODER_MASK << (currentPin * 2));
        temp |= ((config->mode & GPIOCONFIG_MODE) << (currentPin * 2));
        port->MODER = temp;

        if ((config->mode == GPIOCONFIG_MODE_OUTPUT_PP) || (config->mode == GPIOCONFIG_MODE_AF_PP) ||
            (config->mode == GPIOCONFIG_MODE_OUTPUT_OD) || (config->mode == GPIOCONFIG_MODE_AF_OD)) {

            temp = port->OSPEEDR;
            temp &= ~(GPIOPORT_OSPEEDR_MASK << (currentPin & 2));
            temp |= (config->speed << (currentPin * 2));
            port->OSPEEDR= temp;

            temp = port->OTYPER;
            temp &= ~(GPIOPORT_OTYPER_MASK << (currentPin * 2));
            temp |= (config->speed << (currentPin * 2));
            port->OTYPER = temp;
        }

        temp = port->PUPDR;
        temp &= ~(GPIOPORT_PUPDR_MASK << (currentPin * 2));
        temp |= ((config->pull) << (currentPin * 2));
        port->PUPDR = temp;
    }
}

GpioState Gpio_read(GpioPort *port, uint16_t pin) {
    if ((port->IDR & pin) != (uint32_t) GPIOSTATE_RESET) {
        return GPIOSTATE_SET;
    } else {
        return GPIOSTATE_RESET;
    }
}

void Gpio_write(GpioPort *port, uint16_t pin, GpioState state) {
    if (state != GPIOSTATE_RESET) {
        port->BSRR = pin;
    } else {
        port->BSRR = (uint32_t) pin << 16;
    }
}

void Gpio_toggle(GpioPort *port, uint16_t pin) {
    if ((port->ODR & pin) == pin) {
        port->BSRR = (uint32_t) pin << 16;
    } else {
        port->BSRR = pin;
    }
}

void Gpio_initPort(GpioPort *port) {
    do {
#define X(PORT, MASK) if (port == PORT) { SET_BIT(RCC->AHB1ENR, MASK); break; }
        GPIO_PORT_TO_MASK
#undef X
        break;
    } while (1);
}

#undef GPIO_PORT_TO_MASK
