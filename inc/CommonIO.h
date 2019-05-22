/*****************************************************************************
* Archivo: CommonIO.h
* Autor archivo: Eduardo L. Blotta
* Fecha: 21/08/2015
* Comentario: Archivo de declaraciones de entradas y salidas: "CommonIO.h".
******************************************************************************/
// ----------------------------------------------------------------------------
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
// ----------------------------------------------------------------------------
#define GPIOx(_N)       ((GPIO_TypeDef *)(GPIOA_BASE + (GPIOB_BASE-GPIOA_BASE)*(_N)))
#define RCC_MASKx(_N)   (RCC_AHB1ENR_GPIOAEN << (_N))
// ----------------------------------------------------------------------------
// ---------Definicion entradas y salidas en PLACA DISCOVERY:
// STM32F4DISCOVERY (device name: STM32F407VG)
// Port numbers: 0=A, 1=B, 2=C, 3=D, 4=E, 5=F, 6=G, 7=H
#define PORTA	0
#define PORTB	1
#define PORTC	2
#define PORTD	3
#define PORTE	4
#define PORTF	5
#define PORTG	6
#define PORTH	7

//----- Switches en Port A-----
#define SW1 GPIO_PIN_2
#define SW2 GPIO_PIN_4
#define SW3 GPIO_PIN_5

//Grupo A de LEDs en Port D
#define LED_ROJO_A      GPIO_PIN_8
#define LED_AMARILLO_A 	GPIO_PIN_11
#define LED_VERDE_A		GPIO_PIN_9

//--------------------------------------
//Grupo B de LEDs en Port D
#define LED_ROJO_B      GPIO_PIN_13
#define LED_AMARILLO_B 	GPIO_PIN_15
#define LED_VERDE_B		GPIO_PIN_12

//--------------------------------------
//Definicion de segmentos
//--------------------------------------
/*		  	a (p14)
*          --------
*		  |        |
*		  |        |
*		 f|(p15)   |b (p8)
*		  |        |
*		  | g(p12) |
*          --------
*		  |        |
*		  |        |
*		 e|(p13)   |c (p11)
*		  |        |
*		  | d (p9) |	--
*          --------	   |pd| (p10)
*					    --
*/
//--------------------------------------
#define SEGMENTO_a      GPIO_PIN_14
#define SEGMENTO_b      GPIO_PIN_8
#define SEGMENTO_c 		GPIO_PIN_11
#define SEGMENTO_d		GPIO_PIN_9
#define SEGMENTO_e      GPIO_PIN_13
#define SEGMENTO_f 		GPIO_PIN_15
#define SEGMENTO_g		GPIO_PIN_12
#define SEGMENTO_PD		GPIO_PIN_10

//--------------------------------------
//Leds placa Discovery en Port D	// Serigrafia
#define LED_Green	GPIO_PIN_12		// LED4
#define LED_Orange	GPIO_PIN_13		// LED3
#define LED_Red		GPIO_PIN_14		// LED5
#define LED_Blue	GPIO_PIN_15		// LED6
//--------------------------------------
//Boton de usuario (azul)
//placa Discovery en Port A
//--------------------------------------
#define Blue_button	GPIO_PIN_0
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
