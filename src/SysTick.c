/*
 * Nombre: SysTick.c
 * Autor: Eduardo L. Blotta
 * Comentarios: Manejo de System Tick
 */
#include "..\inc\SysTick.h"
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
volatile uint32_t timer_delayCount;
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// Inicializa System Tick;
// ----------------------------------------------------------------------------
void SysTick_Init (void)
{
  SysTick_Config (SystemCoreClock / TIMER_FREQUENCY_HZ);
}

// ----------------------------------------------------------------------------
// Provoca un retardo en ticks;
// ----------------------------------------------------------------------------
void Sleep (uint32_t ticks)
{
  timer_delayCount = ticks;
  // Ocupado hasta que el contador llegue a cero.
  while (timer_delayCount != 0u)
    ;
}

// ----------------------------------------------------------------------------
// ----- SysTick_Handler() ----------------------------------------------------
// ----------------------------------------------------------------------------
void SysTick_Handler (void)
{
	// Decrementa a cero el contador usado por la rutina Sleep.
	if (timer_delayCount != 0u)
	{
		--timer_delayCount;
	}
	HAL_IncTick();	//Incrementa Tick del sistema (usado por algunas funciones de HAL Driver)
	SysTickHook (); // Función para colgarse de la interrupción del System Tick
}

// ----------------------------------------------------------------------------
