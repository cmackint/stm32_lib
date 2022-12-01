#include "main.h"
#include <string.h>
#include <stdio.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
UART_HandleTypeDef uart2;

static void configureSystemClock(void);

static void configureGpio(void);

static void configureUart(void);

int main(void) {
    HAL_Init();

    configureSystemClock();
    configureGpio();
    configureUart();

    char *prompt = "Welcome to the blinky system. Type a character to toggle the blinky!\r\n";
    HAL_UART_Transmit(&uart2, prompt, strlen(prompt), HAL_MAX_DELAY);

    char inputData;
    char echoData[32];
    while(1) {

        HAL_UART_Receive(&uart2, (uint8_t *) &inputData, 1, HAL_MAX_DELAY);

        snprintf(echoData, 32, "You entered %c!\r", inputData);
        HAL_UART_Transmit(&uart2, echoData, strnlen(echoData, 32), HAL_MAX_DELAY);

        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
        HAL_Delay(100);
    }
}

static void configureSystemClock(void) {
    RCC_OscInitTypeDef oscillatorInit = {0};
    RCC_ClkInitTypeDef clockInit = {0};

    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    oscillatorInit.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    oscillatorInit.HSIState = RCC_HSI_ON;
    oscillatorInit.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    oscillatorInit.PLL.PLLState = RCC_PLL_NONE;
    if (HAL_RCC_OscConfig(&oscillatorInit) != HAL_OK) {
        handleError();
    }

    clockInit.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
                          | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    clockInit.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
    clockInit.AHBCLKDivider = RCC_SYSCLK_DIV1;
    clockInit.APB1CLKDivider = RCC_HCLK_DIV1;
    clockInit.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&clockInit, FLASH_LATENCY_0) != HAL_OK) {
        handleError();
    }
}

static void configureGpio(void) {
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();

    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);

    GPIO_InitTypeDef gpioInit = {
            .Pin = GPIO_PIN_7,
            .Mode = GPIO_MODE_OUTPUT_PP,
            .Pull = GPIO_NOPULL,
            .Speed = GPIO_SPEED_FREQ_LOW
    };
    HAL_GPIO_Init(GPIOB, &gpioInit);
}

static void configureUart(void) {
    uart2.Instance = USART2;
    uart2.Init.BaudRate = 115200;
    uart2.Init.WordLength = UART_WORDLENGTH_8B;
    uart2.Init.StopBits = UART_STOPBITS_1;
    uart2.Init.Parity = UART_PARITY_NONE;
    uart2.Init.Mode = UART_MODE_TX_RX;
    uart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    uart2.Init.OverSampling = UART_OVERSAMPLING_16;

    if (HAL_UART_Init(&uart2) != HAL_OK) {
        handleError();
    }
}

void handleError(void) {
    while(1);
}

#pragma clang diagnostic pop