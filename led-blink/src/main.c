#include "main.h"

static void configureSystemClock(void);

static void configureGpio(void);

int main(void) {
    HAL_Init();

    configureSystemClock();
    configureGpio();

    while (1) {
        if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)) {
            while (1) {
                HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
                HAL_Delay(500);
            }
        }
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
    GPIO_InitTypeDef gpioInit = {0};

    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();

    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);

    gpioInit.Pin = GPIO_PIN_13;
    gpioInit.Mode = GPIO_MODE_INPUT;
    gpioInit.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOC, &gpioInit);

    gpioInit.Pin = GPIO_PIN_7;
    gpioInit.Mode = GPIO_MODE_OUTPUT_PP;
    gpioInit.Pull = GPIO_NOPULL;
    gpioInit.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOB, &gpioInit);

}

void handleError(void) {
}
