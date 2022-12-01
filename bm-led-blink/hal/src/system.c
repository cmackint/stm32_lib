
#include <stdint.h>
#include "system.h"

const uint32_t SYSTEM_CORE_CLOCK = 16000000;
const uint8_t AHB_PRESC_TABLE[16] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};
const uint8_t APB_PRESC_TABLE[8]  = {0, 0, 0, 0, 1, 2, 3, 4};
