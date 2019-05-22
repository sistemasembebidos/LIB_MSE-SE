/*
 * Nombre: SysTick.h
 * Autor: Eduardo L. Blotta
 * Comentarios: Manejo de System Tick
 */
#include "..\inc\CommonIO.h"
// ----- Timing definitions -------------------------------------------------
#define TIMER_FREQUENCY_HZ 1000
// ----------------------------------------------------------------------------
void SysTickHook (void);
void SysTick_Init (void);
void SysTick_Handler (void);
void Sleep (uint32_t ticks);
// ----------------------------------------------------------------------------
