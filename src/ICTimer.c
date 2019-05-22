/*
 * Nombre: ICTimer.c
 * Autor: Eduardo L. Blotta
 * Comentarios: Manejo de Entrada de captura de Timer
 */
#include "..\inc\ICTimer.h"


void Init_ICTimer(void)
{
	//uint32_t Ftim2;
	GPIO_InitTypeDef   GPIO_InitStruct;
	/*##-1- Enable peripherals and GPIO Clocks #################################*/
	/* TIM2 Peripheral clock enable */
	__HAL_RCC_TIM2_CLK_ENABLE();
	/* Enable GPIOA channel Clock */
	__HAL_RCC_GPIOA_CLK_ENABLE();

	/* Configure  (TIM2_Channel4) in Alternate function, push-pull and 100MHz speed */
	GPIO_InitStruct.Pin = GPIO_PIN_3;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/*##-2- Configure the NVIC for TIMx #########################################*/
	HAL_NVIC_SetPriority(TIM2_IRQn, 0, 0);
	/* Enable the TIMx global Interrupt */
	HAL_NVIC_EnableIRQ(TIM2_IRQn);

	TimHandle.Instance = TIM2;
	/* Initialize TIM2 peripheral as follows:
      + Period = 0xFFFFFFFF (Timer de 32 bits)
      + Prescaler
      + ClockDivision = 0
      + Counter direction = Up */
	TimHandle.Init.Period        = 0xFFFFFFFF;
	TimHandle.Init.Prescaler     = TIM2_PSC-1; // Timer 2 Prescaler !!!
	TimHandle.Init.ClockDivision = 0;
	TimHandle.Init.CounterMode   = TIM_COUNTERMODE_UP;
	if(HAL_TIM_IC_Init(&TimHandle) != HAL_OK)
	{
		/* Initialization Error */
		Error_Handler();
	}
/*	Clock de entrada TIM2: APB1 TimerClock
	---------------------
	Calculo frecuencia:
	PCLK1=Frec. de entrada Timer 2 (antes del PSC)
	Ftim2=Frec. de entrada al contador (luego del prescaler)
	PCLK1=HCLK/APB1_Prescaler ;obtengo esta frec. llamando a HAL_RCC_GetPCLK1Freq()
	PCLK1=HAL_RCC_GetPCLK1Freq(); // Frecuencia PCLK1
	Ftim2=PCLK1/Prescaler_Timer_2						*/

	//Ftim2=HAL_RCC_GetPCLK1Freq()/TIM2_PSC; // SOlo Para Ver!!!
	/*##-2- Configure the Input Capture channel ################################*/
	/* Configure the Input Capture of channel 4 */
	sICConfig.ICPolarity  = TIM_ICPOLARITY_RISING;
	sICConfig.ICSelection = TIM_ICSELECTION_DIRECTTI;
	sICConfig.ICPrescaler = TIM_ICPSC_DIV1;
	sICConfig.ICFilter    = 0;

	if(HAL_TIM_IC_ConfigChannel(&TimHandle, &sICConfig, TIM_CHANNEL_4) != HAL_OK)
	{
		/* Configuration Error */
		Error_Handler();
	}

	/*##-3- Start the Input Capture in interrupt mode ##########################*/
	if(HAL_TIM_IC_Start_IT(&TimHandle, TIM_CHANNEL_4) != HAL_OK)
	{
		/* Starting Error */
		Error_Handler();
	}

}
//************************************
/**
  * @brief  Input Capture callback in non blocking mode
  * @param  htim : TIM IC handle
  * @retval None
  */
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	__IO uint32_t CapturedValue;

	if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_4)
	{
		CapturedValue = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_4);
		ICTimerHook(CapturedValue);
	}
}

void TIM2_IRQHandler(void)
{
  /* USER CODE BEGIN TIM2_IRQn 0 */

  /* USER CODE END TIM2_IRQn 0 */
  HAL_TIM_IRQHandler(&TimHandle);
  /* USER CODE BEGIN TIM2_IRQn 1 */

  /* USER CODE END TIM2_IRQn 1 */
}

