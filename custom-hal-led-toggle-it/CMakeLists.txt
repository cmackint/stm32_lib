cmake_minimum_required(VERSION 3.7)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)

# TODO: Replace environment variables with target specific macro functions
SET(CMAKE_C_COMPILER_WORKS 1)
SET(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(CMAKE_AR arm-none-eabi-ar)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_OBJDUMP arm-none-eabi-objdump)
set(SIZE arm-none-eabi-size)
set(CMAKE_VERBOSE_MAKEFILE TRUE)

set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/link.ld)
set(COMMON_FLAGS "-O0 -mcpu=cortex-m4 -mthumb -Wall -g -fmessage-length=0")
set(CMAKE_ASM_FLAGS "${COMMON_FLAGS} -x assembler-with-cpp")
set(CMAKE_C_FLAGS "${COMMON_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "-mcpu=cortex-m4 -mthumb -Wall --specs=nosys.specs -nostdlib -lgcc -T ${LINKER_SCRIPT}")

project(bm-uart-polling C ASM)

add_library(hal STATIC
        hal/src/system.c
        hal/src/rcc.c
        hal/src/systick.c
        hal/src/nvic.c
        hal/src/exti.c
        hal/src/gpio.c
        hal/src/timer.c)
target_include_directories(hal PUBLIC hal/include PRIVATE hal/src)

set(EXEC_NAME "program")
set(HEX_FILE ${PROJECT_BINARY_DIR}/${EXEC_NAME}.hex)
set(BIN_FILE ${PROJECT_BINARY_DIR}/${EXEC_NAME}.bin)
add_executable(${EXEC_NAME}.elf
        startup/core.s
        startup/vtable.s
        src/main.c
        src/interrupts.c)
target_include_directories(${EXEC_NAME}.elf PUBLIC include)
target_link_libraries(${EXEC_NAME}.elf hal)
add_custom_command(TARGET ${EXEC_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:${EXEC_NAME}.elf> ${HEX_FILE}
        COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:${EXEC_NAME}.elf> ${BIN_FILE}
        COMMENT "Building ${HEX_FILE} and ${BIN_FILE}")

add_custom_target(upload
        arm-none-eabi-gdb -iex "target remote tcp:127.0.0.1:3333"
        -iex "monitor reset init"
        -iex "monitor targets" # For debugging purposes
        -iex "monitor stm32f4x mass_erase 0"
        -iex "monitor flash write_bank 0 ${BIN_FILE} 0"
        -iex "monitor reset init"
        -iex "disconnect"
        -iex "quit")

add_custom_target(debug
        arm-none-eabi-gdb $<TARGET_FILE:${EXEC_NAME}.elf> -iex "target extended-remote :3333"
        -iex "load")

