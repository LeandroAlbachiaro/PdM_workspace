/*
 * API_delay.c
 *
 *  Created on: Mar 14, 2024
 *      Author: lalba
 */

#include "API_delay.h"
static void Func_Error(void);

void delayInit(delay_t *delay, tick_t duration) {
	if (delay == NULL || duration <= 0){
		Func_Error();
	}
    delay->duration = duration;
    delay->running = false;
}

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

void delayWrite(delay_t *delay, tick_t duration) {
	if (delay == NULL || duration <= 0){
		Func_Error();
	}
    delay->duration = duration;
}

static void Func_Error(void){
	while (1)
	{
	}
}
