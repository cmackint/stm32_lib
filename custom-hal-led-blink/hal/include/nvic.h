#ifndef HAL_NVIC_H
#define HAL_NVIC_H

#include <stdint.h>
#include "irq.h"
#include "system.h"

#define NVIC_PRIORITY_BITS  (4)

#define SCB_AIRCR_VECTKEY_POS               (16u)
#define SCB_AIRCR_VECTKEY_MASK              (0xFFFFul << SCB_AIRCR_VECTKEY_POS)
#define SCB_AIRCR_VECTKEYSTAT_POS           (16u)
#define SCB_AIRCR_VECTKEYSTAT_MASK          (0xFFFFul << SCB_AIRCR_VECTKEYSTAT_POS)
#define SCB_AIRCR_ENDIANESS_POS             (15u)
#define SCB_AIRCR_ENDIANESS_MASK            (0x1ul << SCB_AIRCR_ENDIANESS_POS)
#define SCB_AIRCR_PRIGROUP_POS              (8u)
#define SCB_AIRCR_PRIGROUP_MASK             (0x7ul << SCB_AIRCR_PRIGROUP_POS)
#define SCB_AIRCR_SYSRESETEQ_POS            (2u)
#define SCB_AIRCR_SYSRESETEQ_MASK           (0x1ul << SCB_AIRCR_SYSRESETEQ_POS)
#define SCB_AIRCR_VECTCLRACTIVE_POS         (1u)
#define SCB_AIRCR_VECTCLRACTIVE_MASK        (0x1ul << SCB_AIRCR_VECTCLRACTIVE_POS)

uint32_t Nvic_getPriorityGroup();

void Nvic_setPriority(IrqNumber irqNumber, uint32_t priority);

uint32_t Nvic_encodePriority(uint32_t priorityGroup, uint32_t preemptyPriority, uint32_t subPriority);

void Nvic_setPriorityPreemptSub(IrqNumber irqNumber, uint32_t preemptPriority, uint32_t subPriority);

#endif // HAL_NVIC_H
