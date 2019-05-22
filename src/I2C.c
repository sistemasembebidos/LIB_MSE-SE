/*
 * I2C.c
 *
 *  Created on: 22 mar. 2019
 *      Author: BEL
 */

#include "..\inc\I2C.h"

extern void Error_Handler(void);

void I2C_Init(void)
{
	I2cHandle.Instance             = I2Cx;
	I2cHandle.Init.AddressingMode  = I2C_ADDRESSINGMODE_7BIT;
	I2cHandle.Init.ClockSpeed      = 400000;
	I2cHandle.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	I2cHandle.Init.DutyCycle       = I2C_DUTYCYCLE_16_9;
	I2cHandle.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	I2cHandle.Init.NoStretchMode   = I2C_NOSTRETCH_DISABLE;
	I2cHandle.Init.OwnAddress1     = I2C_ADDRESS;
	I2cHandle.Init.OwnAddress2     = 0;

	if(HAL_I2C_Init(&I2cHandle) != HAL_OK)
	{
	  /* Initialization Error */
	  Error_Handler();
	}
}

/** LLAMADA DESDE funcion HAL_I2C_Init
  * @brief I2C MSP Initialization
  *        This function configures the hardware resources used in this example:
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration
  *           - DMA configuration for transmission request by peripheral
  *           - NVIC configuration for DMA interrupt request enable
  * @param hi2c: I2C handle pointer
  * @retval None
  */
void HAL_I2C_MspInit(I2C_HandleTypeDef *hi2c)
{
  GPIO_InitTypeDef  GPIO_InitStruct;

  /*##-1- Enable GPIO Clocks #################################################*/
  /* Enable GPIO TX/RX clock */
  I2Cx_SCL_GPIO_CLK_ENABLE();
  I2Cx_SDA_GPIO_CLK_ENABLE();

  /*##-2- Configure peripheral GPIO ##########################################*/
  /* I2C TX GPIO pin configuration  */
  GPIO_InitStruct.Pin       = I2Cx_SCL_PIN;
  GPIO_InitStruct.Mode      = GPIO_MODE_AF_OD;
  GPIO_InitStruct.Pull      = GPIO_PULLUP;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FAST;
  GPIO_InitStruct.Alternate = I2Cx_SCL_AF;
  HAL_GPIO_Init(I2Cx_SCL_GPIO_PORT, &GPIO_InitStruct);

  /* I2C RX GPIO pin configuration  */
  GPIO_InitStruct.Pin = I2Cx_SDA_PIN;
  GPIO_InitStruct.Alternate = I2Cx_SDA_AF;
  HAL_GPIO_Init(I2Cx_SDA_GPIO_PORT, &GPIO_InitStruct);

  /*##-3- Enable I2C peripherals Clock #######################################*/
  /* Enable I2C2 clock */
  I2Cx_CLK_ENABLE();

  /*##-4- Configure the NVIC for I2C #########################################*/
  /* NVIC for I2C2 */
  HAL_NVIC_SetPriority(I2Cx_ER_IRQn, 1, 0);
  HAL_NVIC_EnableIRQ(I2Cx_ER_IRQn);
  HAL_NVIC_SetPriority(I2Cx_EV_IRQn, 2, 0);
  HAL_NVIC_EnableIRQ(I2Cx_EV_IRQn);
}


 /******************************************************************************/
 /*            Cortex-M4 Processor Exceptions Handlers                         */
 /******************************************************************************/

 /**
   * @brief  This function handles NMI exception.
   * @param  None
   * @retval None
   */
 void NMI_Handler(void)
 {
 }

 /**
   * @brief  This function handles Hard Fault exception.
   * @param  None
   * @retval None
   */
 void HardFault_Handler(void)
 {
   /* Go to infinite loop when Hard Fault exception occurs */
   while (1)
   {
   }
 }

 /**
   * @brief  This function handles Memory Manage exception.
   * @param  None
   * @retval None
   */
 void MemManage_Handler(void)
 {
   /* Go to infinite loop when Memory Manage exception occurs */
   while (1)
   {
   }
 }

 /**
   * @brief  This function handles Bus Fault exception.
   * @param  None
   * @retval None
   */
 void BusFault_Handler(void)
 {
   /* Go to infinite loop when Bus Fault exception occurs */
   while (1)
   {
   }
 }

 /**
   * @brief  This function handles Usage Fault exception.
   * @param  None
   * @retval None
   */
 void UsageFault_Handler(void)
 {
   /* Go to infinite loop when Usage Fault exception occurs */
   while (1)
   {
   }
 }

 /**
   * @brief  This function handles SVCall exception.
   * @param  None
   * @retval None
   */
 void SVC_Handler(void)
 {
 }

 /**
   * @brief  This function handles Debug Monitor exception.
   * @param  None
   * @retval None
   */
 void DebugMon_Handler(void)
 {
 }

 /**
   * @brief  This function handles PendSVC exception.
   * @param  None
   * @retval None
   */
 void PendSV_Handler(void)
 {
 }

  /******************************************************************************/
 /*                 STM32F4xx Peripherals Interrupt Handlers                   */
 /*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
 /*  available peripheral interrupt handler's name please refer to the startup */
 /*  file (startup_stm32f4xx.s).                                               */
 /******************************************************************************/
 /**
   * @brief  This function handles I2C event interrupt request.
   * @param  None
   * @retval None
   * @Note   This function is redefined in "main.h" and related to I2C data transmission
   */
 void I2Cx_EV_IRQHandler(void)
 {
   HAL_I2C_EV_IRQHandler(& I2cHandle);
 }

 /**
   * @brief  This function handles I2C error interrupt request.
   * @param  None
   * @retval None
   * @Note   This function is redefined in "main.h" and related to I2C error
   */
 void I2Cx_ER_IRQHandler(void)
 {
   HAL_I2C_ER_IRQHandler(& I2cHandle);
 }
