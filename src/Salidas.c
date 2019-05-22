/*
 * Nombre: Salidas.c
 * Autor: Eduardo L. Blotta
 * Comentarios: Manejo de Salidas Digitales
 */
#include "..\inc\Salidas.h"
/*----------------------------------------------------------------------------
  inicializa Port E/S
 *----------------------------------------------------------------------------*/
void Out_Init(uint32_t nPort, uint32_t mask) {

	  RCC->AHB1ENR |= RCC_MASKx(nPort); // Enable GPIO Peripheral clock
	  // Configure pin(s)
	  GPIO_InitTypeDef GPIO_InitStructure;
	  GPIO_InitStructure.Pin = mask;
	  GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;	// Pin(s) as Output
	  GPIO_InitStructure.Speed = GPIO_SPEED_MEDIUM;		// Frec.Max.
	  GPIO_InitStructure.Pull = GPIO_NOPULL;			// Pin(s) as No Pull
	  HAL_GPIO_Init(GPIOx(nPort), &GPIO_InitStructure);		// Initialize GPIO_InitStructure on Portx
}

/*----------------------------------------------------------------------------
  Pone en 1 los pines indicados por la mascara
 *----------------------------------------------------------------------------*/
void Out_On (uint32_t nPort, uint32_t mask) {

	HAL_GPIO_WritePin(GPIOx(nPort),mask, GPIO_PIN_SET); // Salida activa alta
}

/*----------------------------------------------------------------------------
  Pone en 0 los pines indicados por la mascara
 *----------------------------------------------------------------------------*/
void Out_Off (uint32_t nPort, uint32_t mask) {

	HAL_GPIO_WritePin(GPIOx(nPort),mask, GPIO_PIN_RESET); // Salida activa baja
}

/*----------------------------------------------------------------------------
  Togglea los pines indicados por la mascara
 *----------------------------------------------------------------------------*/
void Out_Toggle (uint32_t nPort, uint32_t mask) {

	HAL_GPIO_TogglePin(GPIOx(nPort),mask); // Salida toggleada
}

/*----------------------------------------------------------------------------
  Setea el Mux 2 a 4 que maneja los displays 7-seg.
 *----------------------------------------------------------------------------*/
void SelDig(uint32_t Digito) {
	switch(Digito){
	case 0:
	Out_Off(PORTC, GPIO_PIN_0);
	Out_Off(PORTC, GPIO_PIN_2);
	break;
	case 1:
		Out_On(PORTC, GPIO_PIN_0);
		Out_Off(PORTC, GPIO_PIN_2);
		break;
	case 2:
		Out_Off(PORTC, GPIO_PIN_0);
		Out_On(PORTC, GPIO_PIN_2);
		break;
	case 3:
		Out_On(PORTC, GPIO_PIN_0);
		Out_On(PORTC, GPIO_PIN_2);
		break;
	}
}
