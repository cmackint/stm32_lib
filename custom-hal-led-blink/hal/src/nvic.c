#include <stdint.h>
#include "nvic.h"
#include "irq.h"
#include "system.h"

uint32_t Nvic_getPriorityGroup() {
    return (uint32_t) ((SCB->AIRCR & SCB_AIRCR_PRIGROUP_MASK) >> SCB_AIRCR_PRIGROUP_POS);
}

void Nvic_setPriority(IrqNumber irqNumber, uint32_t priority) {
    if ((int32_t) irqNumber >= 0) {
        NVIC->IP[(uint32_t) irqNumber] =
                (uint8_t) ((priority << (0x8u - NVIC_PRIORITY_BITS)) & (uint32_t) 0xFFul);
    } else {
        SCB->SHP[(((uint32_t) irqNumber) & 0xFul) - 4ul] =
                (uint8_t) ((priority << (0x8u - NVIC_PRIORITY_BITS)) & (uint32_t) 0xFFul);
    }
}

uint32_t Nvic_encodePriority(uint32_t priorityGroup, uint32_t preemptyPriority, uint32_t subPriority) {
    priorityGroup = (priorityGroup & (uint32_t) 0x7ul);

    uint32_t preemptPriorityBits = ((7ul - priorityGroup) > (uint32_t) (NVIC_PRIORITY_BITS)) ?
                                   (uint32_t) (NVIC_PRIORITY_BITS) : (uint32_t) (7ul - priorityGroup);

    uint32_t subPriorityBits = ((priorityGroup + (uint32_t) (NVIC_PRIORITY_BITS)) < (uint32_t) 7ul) ?
                               (uint32_t) 0ul : (uint32_t) ((priorityGroup - 7ul) + (uint32_t) (NVIC_PRIORITY_BITS));

    return ((preemptyPriority & (uint32_t) ((1ul << preemptPriorityBits) - 1ul)) << subPriorityBits) |
           (subPriority & (uint32_t) ((1ul << subPriorityBits) - 1ul));

}

void Nvic_setPriorityPreemptSub(IrqNumber irqNumber, uint32_t preemptPriority, uint32_t subPriority) {
    uint32_t priorityGroup = Nvic_getPriorityGroup();

    Nvic_setPriority(irqNumber, Nvic_encodePriority(priorityGroup, preemptPriority, subPriority));
}
