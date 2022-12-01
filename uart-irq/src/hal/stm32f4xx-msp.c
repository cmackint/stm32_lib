#include "main.h"

// Called by HAL
void HAL_MspInit(void) { // TODO: Look at this
    __HAL_RCC_SYSCFG_CLK_ENABLE();
    __HAL_RCC_PWR_CLK_ENABLE();
}

void HAL_UART_MspInit(UART_HandleTypeDef *huart) {
    GPIO_InitTypeDef gpioConfig = {0};

    if (huart->Instance == USART2) {
        __HAL_RCC_USART2_CLK_ENABLE();
        __HAL_RCC_GPIOA_CLK_ENABLE();

        gpioConfig.Pin = GPIO_PIN_2 | GPIO_PIN_3;
        gpioConfig.Mode = GPIO_MODE_AF_PP;
        gpioConfig.Pull = GPIO_PULLUP;
        gpioConfig.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        gpioConfig.Alternate = GPIO_AF7_USART2;
        HAL_GPIO_Init(GPIOA, &gpioConfig);

        HAL_NVIC_SetPriority(USART2_IRQn, 0, 0);
        HAL_NVIC_EnableIRQ(USART2_IRQn);
    }

}

void HAL_UART_MspDeInit(UART_HandleTypeDef *huart) {
    if (huart->Instance == USART2) {
        __HAL_RCC_USART2_CLK_DISABLE();

        HAL_GPIO_DeInit(GPIOA, GPIO_PIN_2 | GPIO_PIN_3);

        HAL_NVIC_DisableIRQ(USART2_IRQn);
    }
}