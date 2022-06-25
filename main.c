#include <stdio.h>
#include "stm32f4xx_hal.h"

void GPIO_Init(void);
void Clock_config(void);

int main()
{
	HAL_Init();
	
	Clock_config();
	
	GPIO_Init();
	
	while(1)
	{
	  if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_SET)
	  {
		  HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_SET);
	  }
		HAL_Delay(100);
	}
}

void Clock_config()
{
	
	RCC_OscInitTypeDef RCCOsc;
	
	RCCOsc.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	//RCCOsc.
	
	
}

void GPIO_Init()
{
	GPIO_InitTypeDef GPIOInit;
	
	__HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
	
  GPIOInit.Pin   = GPIO_PIN_0;
	GPIOInit.Mode  = GPIO_MODE_OUTPUT_PP;
	GPIOInit.Pull  = GPIO_NOPULL;
	GPIOInit.Speed = GPIO_SPEED_FREQ_MEDIUM;
	HAL_GPIO_Init(GPIOA, &GPIOInit);
	
	
  GPIOInit.Pin   = GPIO_PIN_13;
	GPIOInit.Mode  = GPIO_MODE_OUTPUT_PP;
	GPIOInit.Pull  = GPIO_NOPULL;
	GPIOInit.Speed = GPIO_SPEED_FREQ_MEDIUM;
	HAL_GPIO_Init(GPIOG, &GPIOInit);
	
	
	
}
