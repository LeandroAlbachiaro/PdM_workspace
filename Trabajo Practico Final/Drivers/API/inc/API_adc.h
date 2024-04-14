/*
 * API_adc.h
 *
 *  Created on: Apr 11, 2024
 *      Author: lalba
 */

#ifndef API_INC_API_ADC_H_
#define API_INC_API_ADC_H_

#include "stm32f4xx_hal.h"

extern ADC_HandleTypeDef hadc1;

void MX_ADC1_Init(void);
uint32_t read_adc_value(ADC_HandleTypeDef* hadc, uint32_t num_samples);
void Error_Handler_adc(void);

#endif /* API_INC_API_ADC_H_ */
