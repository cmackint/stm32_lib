#include <stdint.h>
#include "hal/nvic.h"
#include "hal/interrupts.h"
#include "hal/system.h"

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

static uint32_t HalNvic_encodePriority(uint32_t priorityGroup, uint32_t preemptyPriority, uint32_t subPriority);

uint32_t HalNvic_getPriorityGroup() {
    return (uint32_t) ((HAL_SCB->AIRCR & SCB_AIRCR_PRIGROUP_MASK) >> SCB_AIRCR_PRIGROUP_POS);
}

void HalNvic_setPriority(HalIrqNumber irqNumber, uint32_t priority) {
    if ((int32_t) irqNumber >= 0) {
        HAL_NVIC->IP[(uint32_t) irqNumber] =
                (uint8_t) ((priority << (0x8u - HAL_NVIC_PRIORITY_BITS)) & (uint32_t) 0xFFul);
    } else {
        HAL_SCB->SHP[(((uint32_t) irqNumber) & 0xFul) - 4ul] =
                (uint8_t) ((priority << (0x8u - HAL_NVIC_PRIORITY_BITS)) & (uint32_t) 0xFFul);
    }
}

void HalNvic_setPriorityPreemptSub(HalIrqNumber irqNumber, uint32_t preemptPriority, uint32_t subPriority) {
    uint32_t priorityGroup = HalNvic_getPriorityGroup();

    HalNvic_setPriority(irqNumber, HalNvic_encodePriority(priorityGroup, preemptPriority, subPriority));
}

inline void NvicHal_enableIrq(HalIrqNumber irqNumber) {
   if ((int32_t) irqNumber >= 0) {
       HAL_NVIC->ISER[(uint32_t) irqNumber >> 5ul] = (uint32_t) (1ul << ((uint32_t) irqNumber & 0x1Ful));
   }
}

static uint32_t HalNvic_encodePriority(uint32_t priorityGroup, uint32_t preemptyPriority, uint32_t subPriority) {
    priorityGroup = (priorityGroup & (uint32_t) 0x7ul);

    uint32_t preemptPriorityBits = ((7ul - priorityGroup) > (uint32_t) (HAL_NVIC_PRIORITY_BITS)) ?
                                   (uint32_t) (HAL_NVIC_PRIORITY_BITS) : (uint32_t) (7ul - priorityGroup);

    uint32_t subPriorityBits = ((priorityGroup + (uint32_t) (HAL_NVIC_PRIORITY_BITS)) < (uint32_t) 7ul) ?
                               (uint32_t) 0ul : (uint32_t) ((priorityGroup - 7ul) + (uint32_t) (HAL_NVIC_PRIORITY_BITS));

    return ((preemptyPriority & (uint32_t) ((1ul << preemptPriorityBits) - 1ul)) << subPriorityBits) |
           (subPriority & (uint32_t) ((1ul << subPriorityBits) - 1ul));
}