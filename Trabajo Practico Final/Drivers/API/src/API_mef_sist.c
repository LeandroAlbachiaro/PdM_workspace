/*
 * API_mef_sist.c
 *
 *  Created on: Apr 13, 2024
 *      Author: lalba
 */

#include "API_mef_sist.h"

// Definición de estados
typedef enum {
    PARADA,
    BAJO,
    MEDIO,
    ALTO
} estadoMEF_sist_t;

static char estado_sist_char;
static estadoMEF_sist_t estado_sist;

void MEF_sist_init(){
	estado_sist = PARADA;
	estado_sist_char = 'P';
}

/**
  * @brief  Determines the state based on the ADC value.
  * @param  adc_value: The ADC value used to determine the state.
  * @retval The state of the system.
  */
estadoMEF_sist_t determinar_estado(uint32_t adc_value) {
	if (HAL_GPIO_ReadPin(USER_Btn_GPIO_Port, USER_Btn_Pin) == GPIO_PIN_SET){
		estado_sist = PARADA;
		estado_sist_char = 'P';
		HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);
		return PARADA;
	}
	else {
		if (adc_value >= 0 && adc_value < 20) {
			estado_sist_char = 'B';
			HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);
			return BAJO;
		} else if (adc_value >= 20 && adc_value < 80) {
			estado_sist_char = 'M';
			HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);
			return MEDIO;
		} else if (adc_value >= 80 && adc_value <= 100) {
			estado_sist_char = 'A';
			HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_SET);
			return ALTO;
		} else {
			estado_sist_char = 'P';
			HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);
			return PARADA;
		}
	}
}

/**
  * @brief  Updates the state of the Finite State Machine (FSM).
  * @param  adc_value: The ADC value used to determine the next state.
  * @retval None
  */
void MEF_sist_update(uint32_t adc_value){
	switch (estado_sist) {
	case BAJO:
		estado_sist = determinar_estado(adc_value);
		break;

	case MEDIO:
		estado_sist = determinar_estado(adc_value);
		break;

	case ALTO:
		estado_sist = determinar_estado(adc_value);
		break;

	case PARADA:
		estado_sist = determinar_estado(adc_value);
		break;

	default:
		Error_Handler_MEF();
		break;
	}
}

char Get_state(void)
{
	return estado_sist_char;
}

void Error_Handler_MEF(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
