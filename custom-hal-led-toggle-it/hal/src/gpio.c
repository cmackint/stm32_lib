#include <stdint.h>
#include <stdbool.h>
#include "hal/gpio.h"
#include "hal/util.h"
#include "hal/system.h"
#include "hal/rcc.h"

#define GPIOPORT_MODER_MASK                         (0x3u)
#define GPIOPORT_OSPEEDR_MASK                       (0x3u)
#define GPIOPORT_OTYPER_MASK                        (0x1u)
#define GPIOPORT_PUPDR_MASK                         (0x3u)

inline uint32_t HalGpio_getPortIndex(HalGpioReg *port) {
    if (port == HAL_GPIOA) {
        return 0u;
    } else if (port == HAL_GPIOB) {
        return 1u;
    } else if (port == HAL_GPIOC) {
        return 2u;
    } else if (port == HAL_GPIOD) {
        return 3u;
    } else if (port == HAL_GPIOE) {
        return 4u;
    } else if (port == HAL_GPIOF) {
        return 5u;
    } else if (port == HAL_GPIOG) {
        return 6u;
    } else {
        return 7u;
    }
}

void HalGpio_initPin(HalGpioReg *port, HalGpioConfig *config) {
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
        temp |= ((config->mode & GPIOCONFIG_MODEGRP_GPIO) << (currentPin * 2));
        port->MODER = temp;

        if ((config->mode == GPIOCONFIG_MODE_OUTPUT_PP) || (config->mode == GPIOCONFIG_MODE_AF_PP) ||
            (config->mode == GPIOCONFIG_MODE_OUTPUT_OD) || (config->mode == GPIOCONFIG_MODE_AF_OD)) {

            temp = port->OSPEEDR;
            temp &= ~(GPIOPORT_OSPEEDR_MASK << (currentPin & 2u));
            temp |= (config->speed << (currentPin * 2u));
            port->OSPEEDR = temp;

            temp = port->OTYPER;
            temp &= ~(GPIOPORT_OTYPER_MASK << (currentPin * 2u));
            temp |= (config->speed << (currentPin * 2u));
            port->OTYPER = temp;
        }

        temp = port->PUPDR;
        temp &= ~(GPIOPORT_PUPDR_MASK << (currentPin * 2u));
        temp |= ((config->pull) << (currentPin * 2u));
        port->PUPDR = temp;

        if ((config->mode & GPIOCONFIG_MODEGRP_EXTI) == GPIOCONFIG_MODEGRP_EXTI) {
            HalRcc_enableSysConfigClock();

            temp = HAL_SYSCFG->EXTICR[currentPin >> 2u];
            temp &= ~(0x0fu << (4u * (currentPin & 0x03u)));
            temp |= ((uint32_t) HalGpio_getPortIndex(port)) << (4u * (currentPin & 0x3u));
            HAL_SYSCFG->EXTICR[currentPin >> 2u] = temp;

            temp = HAL_EXTI->IMR;
            temp &= ~((uint32_t) currentPinMask);
            if ((config->mode & GPIOCONFIG_MODEGRP_IT) == GPIOCONFIG_MODEGRP_IT) {
                temp |= currentPinMask;
            }
            HAL_EXTI->IMR = temp;

            temp = HAL_EXTI->EMR;
            temp &= ~((uint32_t) currentPinMask);
            if ((config->mode & GPIOCONFIG_MODEGRP_EVT) == GPIOCONFIG_MODEGRP_EVT) {
                temp |= currentPinMask;
            }
            HAL_EXTI->EMR = temp;

            temp = HAL_EXTI->RTSR;
            temp &= ~((uint32_t) currentPinMask);
            if ((config->mode & GPIOCONFIG_MODEGRP_RISING_EDGE) == GPIOCONFIG_MODEGRP_RISING_EDGE) {
                temp |= currentPinMask;
            }
            HAL_EXTI->RTSR = temp;

            temp = HAL_EXTI->FTSR;
            temp &= ~((uint32_t) currentPinMask);
            if ((config->mode & GPIOCONFIG_MODEGRP_FALLING_EDGE) == GPIOCONFIG_MODEGRP_FALLING_EDGE) {
                temp |= currentPinMask;
            }
            HAL_EXTI->FTSR = temp;
        }
    }
}

inline HalGpioState HalGpio_readPin(HalGpioReg *port, uint16_t pin) {
    if ((port->IDR & pin) != (uint32_t) GPIOSTATE_RESET) {
        return GPIOSTATE_SET;
    } else {
        return GPIOSTATE_RESET;
    }
}

inline void HalGpio_writePin(HalGpioReg *port, uint16_t pin, HalGpioState state) {
    if (state != GPIOSTATE_RESET) {
        port->BSRR = pin;
    } else {
        port->BSRR = (uint32_t) pin << 16u;
    }
}

void HalGpio_togglePin(HalGpioReg *port, uint16_t pin) {
    if ((port->ODR & pin) == pin) {
        port->BSRR = (uint32_t) pin << 16u;
    } else {
        port->BSRR = pin;
    }
}

void HalGpio_initPort(HalGpioReg *port) {
    HalRcc_enableGpioClock(HalGpio_getPortIndex(port));
}
