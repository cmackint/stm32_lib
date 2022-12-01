#include "hal/systick.h"
#include "hal/exti.h"
#include "hal/gpio.h"

void SysTick_handle() {
    SysTick_currentTick++;
}

void IRQ_EXTI15_10_handle() {
    HalExtiGpio_handle(GPIO_PIN_13);
}
