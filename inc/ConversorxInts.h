/*
 * Nombre: ConversorxInts.h
 * Autor: Eduardo L. Blotta
 * Comentarios: Manejo de conversor A/D c/interrupciones
 */
#include "..\inc\CommonIO.h"
//======================================================
extern void Error_Handler(void);
void ADC1_NTC_Init(void);
void ADC_IRQHandler(void);
void ADCIRQHook (uint16_t ConversorAD);
//======================================================
ADC_HandleTypeDef hADC1;
//======================================================
