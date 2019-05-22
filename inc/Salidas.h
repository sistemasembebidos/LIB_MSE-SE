/*
 * Nombre: Salidas.h
 * Autor: Eduardo L. Blotta
 * Comentarios: Manejo de Salidas Digitales
 */
//--------------------------------------
#include "..\inc\CommonIO.h"
void Out_Init(uint32_t nPort, uint32_t mask);
void Out_On  (uint32_t nPort, uint32_t mask);
void Out_Off (uint32_t nPort, uint32_t mask);
void Out_Toggle (uint32_t nPort, uint32_t mask);
void SelDig(uint32_t Digito);
