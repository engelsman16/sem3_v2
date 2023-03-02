#include "main.h"
#include "cmsis_os.h"
#include "usart.h"
#include "gpio.h"
#include <string.h>
#include <stdio.h>

#include "led.h"
#include "button.h"

void SystemClock_Config(void);
void MX_FREERTOS_Init(void);

volatile uint16_t pressed = 0;

extern "C" void EXTI0_IRQHandler(void) 
{
  EXTI->PR = EXTI_PR_PR0;
  pressed = 1;
}

extern "C" void EXTI1_IRQHandler(void) 
{
  EXTI->PR = EXTI_PR_PR0;
  pressed = 2;
}

Button button(GPIOA, 0);

int main(void)
{
  HAL_Init();

  SystemClock_Config();

  MX_GPIO_Init();
  MX_USART2_UART_Init();

  const int MSGBUFSIZE = 80;
  char msgBuf[MSGBUFSIZE];

  snprintf(msgBuf, MSGBUFSIZE, "%s", "WEEEEEEEEEEE!\r\n");
  HAL_UART_Transmit(&huart2, (uint8_t *)msgBuf, strlen(msgBuf), HAL_MAX_DELAY);

  button.Init();

  SYSCFG->EXTICR[0] |= (SYSCFG->EXTICR[0] & ~SYSCFG_EXTICR1_EXTI0) | (0b000 << SYSCFG_EXTICR1_EXTI0_Pos); 
  SYSCFG->EXTICR[0] |= (SYSCFG->EXTICR[0] & ~SYSCFG_EXTICR1_EXTI1) | (0b000 << SYSCFG_EXTICR1_EXTI1_Pos); 
  EXTI->FTSR |= EXTI_FTSR_FT0;     
  EXTI->RTSR |= EXTI_RTSR_RT1;                                                                                                                        
  NVIC_EnableIRQ(EXTI0_IRQn);  
  NVIC_EnableIRQ(EXTI1_IRQn);
  EXTI->IMR |= EXTI_IMR_MR0; 
  EXTI->IMR |= EXTI_IMR_MR1;  

  uint16_t count = 0;

  while (true)
  {
    if (pressed == 1)
    {
      snprintf(msgBuf, MSGBUFSIZE, "%i%s", count++, "\r\n");
      HAL_UART_Transmit(&huart2, (uint8_t *)msgBuf, strlen(msgBuf), HAL_MAX_DELAY);
      pressed = 0;
    }
    else if(pressed == 2)
    {
      snprintf(msgBuf, MSGBUFSIZE, "%s", "WEEEEEEEEEEE!\r\n");
      HAL_UART_Transmit(&huart2, (uint8_t *)msgBuf, strlen(msgBuf), HAL_MAX_DELAY);
      pressed = 0;
    }
  }
}

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
   */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART2;
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if (htim->Instance == TIM17)
  {
    HAL_IncTick();
  }
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif
