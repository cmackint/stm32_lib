#ifndef HAL_NVIC_H
#define HAL_NVIC_H

#include <stdint.h>
#include "interrupts.h"
#include "system.h"

#define HAL_NVIC_PRIORITY_BITS  (4)

uint32_t HalNvic_getPriorityGroup();

void HalNvic_setPriority(HalIrqNumber irqNumber, uint32_t priority);

void HalNvic_setPriorityPreemptSub(HalIrqNumber irqNumber, uint32_t preemptPriority, uint32_t subPriority);

void NvicHal_enableIrq(HalIrqNumber irqNumber);

#endif // HAL_NVIC_H
