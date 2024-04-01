/*
 * API_debounce.c
 *
 *  Created on: Mar 23, 2024
 *      Author: lalba
 */

#include "API_debounce.h"

/* Private define ------------------------------------------------------------*/
#define DELAY_DEBOUNCE 40

typedef enum{
    BUTTON_UP,
    BUTTON_FALLING,
    BUTTON_DOWN,
    BUTTON_RAISING
} estadoMEF_t;

static estadoMEF_t estadoActual;
static bool_t flancoDescendente = false;
delay_t delayDebounce;
tick_t duration = DELAY_DEBOUNCE;

uint8_t ascendente[] = "Flanco ascendente\n\r";
uint8_t descendente[] = "Flanco descendente\n\r";


/**
  * @brief  Inicializa el estado de la Máquina de Estados Finitos (MEF) para el debounce del botón.
  * @param  None
  * @retval None
  */
void debounceFSM_init(){
	estadoActual = BUTTON_UP;
}

/**
  * @brief  Actualiza el estado de la Máquina de Estados Finitos (MEF) para el debounce del botón.
  * @param  duration: Duración del debounce en milisegundos
  * @retval None
  */
void debounceFSM_update(){
	switch (estadoActual) {
	case BUTTON_UP:
		if (BSP_PB_GetState(BUTTON_USER) == GPIO_PIN_RESET){
			estadoActual = BUTTON_FALLING;
			delayInit(&delayDebounce, duration);
		}
		break;

	case BUTTON_FALLING:
		if (delayRead(&delayDebounce) == true){
			if (BSP_PB_GetState(BUTTON_USER) == GPIO_PIN_RESET){
				flancoDescendente = true;
				uartSendString(&descendente[0]);
				estadoActual = BUTTON_DOWN;
			}
			else{
				estadoActual = BUTTON_UP;
			}
		}
		break;

	case BUTTON_DOWN:
		if (BSP_PB_GetState(BUTTON_USER) == GPIO_PIN_SET){
			estadoActual = BUTTON_RAISING;
			delayInit(&delayDebounce, duration);
		}
		break;

	case BUTTON_RAISING:
		if (delayRead(&delayDebounce) == true){
			if (BSP_PB_GetState(BUTTON_USER) == GPIO_PIN_SET){
				flancoDescendente = false;
				uartSendString(&ascendente[0]);
				estadoActual = BUTTON_UP;
			}
			else{
				estadoActual = BUTTON_DOWN;
			}
		}
		break;

	default:	// Enciende el Segundo Led de la placa en caso de que la MEF
				//no tenga un estado definido.
		// BSP_LED_On(LED2);
		break;
	}
}

bool_t readKey()
{
	bool_t retVal = flancoDescendente;

	flancoDescendente = false;

	return retVal;
}
