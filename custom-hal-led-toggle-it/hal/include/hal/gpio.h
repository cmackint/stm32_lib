#ifndef HAL_GPIO_H
#define HAL_GPIO_H

#include <stdint.h>
#include <stdbool.h>
#include "hal/system.h"
#include "hal/rcc.h"
#include "hal/util.h"

typedef struct {
    uint32_t pin;
    uint32_t mode;
    uint32_t pull;
    uint32_t speed;
    uint32_t alternate;
} HalGpioConfig;

#define GPIOCONFIG_MODEGRP_GPIO                (0x00000003u)
#define GPIOCONFIG_MODEGRP_EXTI                (0x10000000u)
#define GPIOCONFIG_MODEGRP_IT                  (0x00010000u)
#define GPIOCONFIG_MODEGRP_EVT                 (0x00020000u)
#define GPIOCONFIG_MODEGRP_RISING_EDGE         (0x00100000u)
#define GPIOCONFIG_MODEGRP_FALLING_EDGE        (0x00200000u)

#define GPIOCONFIG_MODE_INPUT               (0x00000000u)
#define GPIOCONFIG_MODE_OUTPUT_PP           (0x00000001u)
#define GPIOCONFIG_MODE_OUTPUT_OD           (0x00000011u)
#define GPIOCONFIG_MODE_AF_PP               (0x00000002u)
#define GPIOCONFIG_MODE_AF_OD               (0x00000012u)
#define GPIOCONFIG_MODE_ANALOG              (0x00000003u)

#define  GPIOCONFIG_MODE_IT_RISING          (0x10110000u)
#define  GPIOCONFIG_MODE_IT_FALLING         (0x10210000u)
#define  GPIOCONFIG_MODE_IT_RISING_FALLING  (0x10310000u)
#define  GPIOCONFIG_MODE_EVT_RISING         (0x10120000u)
#define  GPIOCONFIG_MODE_EVT_FALLING        (0x10220000u)
#define  GPIOCONFIG_MODE_EVT_RISING_FALLING (0x10320000u)

#define GPIOCONFIG_PULL_NONE                (0x00000000u)
#define GPIOCONFIG_PULL_UP                  (0x00000001u)
#define GPIOCONFIG_PULL_DOWN                (0x00000002u)

#define GPIOCONFIG_SPEED_LOW                (0x00000000u)
#define GPIOCONFIG_SPEED_MEDIUM             (0x00000001u)
#define GPIOCONFIG_SPEED_HIGH               (0x00000002u)
#define GPIOCONFIG_SPEED_VHIGH              (0x00000003u)

typedef enum {
    GPIOSTATE_RESET = 0,
    GPIOSTATE_SET
} HalGpioState;

#define GPIO_PIN_0          ((uint16_t) 0x0001)
#define GPIO_PIN_1          ((uint16_t) 0x0002)
#define GPIO_PIN_2          ((uint16_t) 0x0004)
#define GPIO_PIN_3          ((uint16_t) 0x0008)
#define GPIO_PIN_4          ((uint16_t) 0x0010)
#define GPIO_PIN_5          ((uint16_t) 0x0020)
#define GPIO_PIN_6          ((uint16_t) 0x0040)
#define GPIO_PIN_7          ((uint16_t) 0x0080)
#define GPIO_PIN_8          ((uint16_t) 0x0100)
#define GPIO_PIN_9          ((uint16_t) 0x0200)
#define GPIO_PIN_10         ((uint16_t) 0x0400)
#define GPIO_PIN_11         ((uint16_t) 0x0800)
#define GPIO_PIN_12         ((uint16_t) 0x1000)
#define GPIO_PIN_13         ((uint16_t) 0x2000)
#define GPIO_PIN_14         ((uint16_t) 0x4000)
#define GPIO_PIN_15         ((uint16_t) 0x8000)
#define GPIO_PIN_ALL        ((uint16_t) 0xFFFF)

uint32_t HalGpio_getPortIndex(HalGpioReg *port);

void HalGpio_initPin(HalGpioReg *port, HalGpioConfig *config);

HalGpioState HalGpio_readPin(HalGpioReg *port, uint16_t pin);

void HalGpio_writePin(HalGpioReg *port, uint16_t pin, HalGpioState state);

void HalGpio_togglePin(HalGpioReg *port, uint16_t pin);

void HalGpio_initPort(HalGpioReg *port);

#endif // HAL_GPIO_H
