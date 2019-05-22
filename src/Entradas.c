/*
 * Nombre: Entradas.h
 * Autor: Eduardo L. Blotta
 * Comentarios: Manejo de Entradas Digitales
 */
#include "..\inc\Entradas.h"
/*----------------------------------------------------------------------------
  Inicializa Pines del Puerto, especificados en la mascara, como entrada
 *----------------------------------------------------------------------------*/
void In_Init(uint32_t nPort, uint32_t mask) {
	RCC->AHB1ENR |= RCC_MASKx(nPort); // Enable GPIOA Peripheral clock
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	GPIO_InitStructure.Pin =mask;
	GPIO_InitStructure.Speed = GPIO_SPEED_MEDIUM;		// Frec.Max.
	HAL_GPIO_Init(GPIOx(nPort), &GPIO_InitStructure);
}
/*----------------------------------------------------------------------------
  Lee pines del puerto, especificados en la mascara
 *----------------------------------------------------------------------------*/
uint32_t In_Read(uint32_t nPort, uint32_t mask) {

	return (GPIOx(nPort)->IDR & mask);
}

