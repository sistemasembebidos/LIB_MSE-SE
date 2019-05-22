/*
 * Nombre: ConversorxInts.c
 * Autor: Eduardo L. Blotta
 * Comentarios: Manejo de conversor A/D c/interrupciones
 */
#include "..\inc\ConversorxInts.h"
//======================================================
extern void Error_Handler(void);

//======================================================
void ADC1_NTC_Init()
{
	/* Peripherals clock enable */
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__ADC1_CLK_ENABLE();
	//======================================================
	//ADC1 GPIO Configuration
	//PA2------> ADC1_IN2
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Pin = GPIO_PIN_2;
	GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	//======================================================
	/* Configure the NVIC */
		/* NVIC configuration for ADC interrupt */
		HAL_NVIC_SetPriority(ADC_IRQn, 0, 0);
		HAL_NVIC_EnableIRQ(ADC_IRQn);
	//======================================================
	//Configure the global features of the ADC (Clock, 
	//Resolution, Data Alignment and number of conversion)
	hADC1.Instance = ADC1;
	hADC1.Init.ClockPrescaler = ADC_CLOCKPRESCALER_PCLK_DIV8;
	hADC1.Init.Resolution = ADC_RESOLUTION12b;
	hADC1.Init.ScanConvMode = DISABLE;
	hADC1.Init.ContinuousConvMode = ENABLE;
	hADC1.Init.DiscontinuousConvMode = DISABLE;
	hADC1.Init.NbrOfDiscConversion = 0;
	hADC1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	hADC1.Init.ExternalTrigConv = ADC_EXTERNALTRIGCONV_T1_CC1;
	hADC1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	hADC1.Init.NbrOfConversion = 1;
	hADC1.Init.DMAContinuousRequests = DISABLE;
	hADC1.Init.EOCSelection = DISABLE;

	if(HAL_ADC_Init(&hADC1) != HAL_OK)
	{
		/* Initialization Error */
		Error_Handler();
	}
	//======================================================
	//Configure for the selected ADC regular channel its
	//corresponding rank in the sequencer and its sample time.
	ADC_ChannelConfTypeDef sConfig;
	sConfig.Channel = ADC_CHANNEL_2;
	sConfig.Rank = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_28CYCLES;

	if(HAL_ADC_ConfigChannel(&hADC1, &sConfig) != HAL_OK)
		{
			/* Initialization Error */
			Error_Handler();
		}
}

void ADC_IRQHandler(void)
{
	__IO uint16_t ConversorAD;
	// Funcion de lectura del conversor: 
	ConversorAD=HAL_ADC_GetValue(&hADC1);
	ADCIRQHook (ConversorAD);
}
