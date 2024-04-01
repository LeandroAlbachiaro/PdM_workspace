/*
 * API_delay.c
 *
 *  Created on: Mar 14, 2024
 *      Author: lalba
 */

#include "API_delay.h"
static void Func_Error(void);


// Esta función inicializa una estructura de retardo con una duración específica.
// Parámetros:
// - delay: Puntero a la estructura de retardo que se inicializará.
// - duration: Duración del retardo en unidades de tiempo (ticks).
void delayInit(delay_t *delay, tick_t duration) {
	if (delay == NULL || duration <= 0){
		Func_Error();
	}
    delay->duration = duration;
    delay->running = false;
}


// Esta función verifica y lee el estado actual del retardo.
// Parámetros:
// - delay: Puntero a la estructura de retardo que se leerá.
// Retorna:
// - true si el retardo ha terminado, false de lo contrario.
bool_t delayRead(delay_t *delay) {

	if (delay == NULL){
		Func_Error();
	}

    if (!delay->running) {
        delay->startTime = HAL_GetTick();
        delay->running = true;
        return false;
    } else {
        tick_t currentTime = HAL_GetTick();
        if ((currentTime - delay->startTime) >= delay->duration) {
            delay->running = false;
            return true;
        } else {
            return false;
        }
    }
}


// Esta función actualiza la duración de un retardo existente con una nueva duración.
// Parámetros:
// - delay: Puntero a la estructura de retardo que se actualizará.
// - duration: Nueva duración del retardo en unidades de tiempo (ticks).
void delayWrite(delay_t *delay, tick_t duration) {
	if (delay == NULL || duration <= 0){
		Func_Error();
	}
    delay->duration = duration;
}

// Esta es una función de manejo de errores interna que se llama en caso de error grave.
// Se queda en un bucle infinito si se llama.
static void Func_Error(void){
	while (1)
	{
	}
}
