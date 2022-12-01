#include "main.h"
#include <string.h>
#include <stdio.h>
#include <stm32f4xx_hal_uart.h>
#include "circbuf.h"

UART_HandleTypeDef uart2;

#define LARGEBUF_LEN (128)
#define SMALLBUF_LEN (32)
#define LARGESMALLBUF_LEN (160)

static CircBuf transmitBuf;
static uint8_t receiveByte;
static size_t receiveBufNextIdx = 0;
static uint8_t receiveBuf[LARGEBUF_LEN];


static void configureSystemClock(void);

static void configureGpio(void);

static void configureUart(void);

int main(void) {
    HAL_Init();

    configureSystemClock();
    configureGpio();
    configureUart();

    char *prompt = "Welcome to the typey system. Type a sentence and press enter!\r\n";
    HAL_UART_Transmit(&uart2, prompt, strlen(prompt), HAL_MAX_DELAY);

    HAL_UART_Receive_IT(&uart2, &receiveByte, 1);

    while(1) {
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

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *uart) {
    if (uart == &uart2) {
        if (receiveByte == '\n') {
            receiveBuf[receiveBufNextIdx] = '\0';
            char data[LARGESMALLBUF_LEN];
            snprintf(data, LARGESMALLBUF_LEN, "You entered \"%s\"!\r\n", receiveBuf);
            size_t dataLen = strlen(data);

            if (HAL_UART_Transmit_IT(&uart2, (uint8_t *) data, dataLen) != HAL_OK) {
                CircBuf_write(&transmitBuf, (uint8_t *) data, dataLen);
            }

            receiveBufNextIdx = 0;
        } else {
            receiveBuf[receiveBufNextIdx] = receiveByte;
            receiveBufNextIdx = (receiveBufNextIdx == LARGEBUF_LEN-1) ? 0 : receiveBufNextIdx + 1;
        }

        HAL_UART_Receive_IT(&uart2, (uint8_t *) &receiveByte, 1);
    }
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *uart) {
    if (uart == &uart2) {
        uint8_t data;

        // TODO: Write more than 1 byte at a time if possible

        if (CircBuf_read(&transmitBuf, &data) != -1) {
            HAL_UART_Transmit_IT(&uart2, &data, 1);
        }
    }
}
