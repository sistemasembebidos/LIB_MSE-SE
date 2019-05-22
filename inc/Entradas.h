/*
 * Nombre: Entradas.h
 * Autor: Eduardo L. Blotta
 * Comentarios: Manejo de Entradas Digitales
 */
#include "..\inc\CommonIO.h"

void In_Init(uint32_t nPort, uint32_t mask);
uint32_t In_Read(uint32_t nPort, uint32_t mask);

