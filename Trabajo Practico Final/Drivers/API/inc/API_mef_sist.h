/*
 * API_mef_sist.h
 *
 *  Created on: Apr 13, 2024
 *      Author: lalba
 */

#ifndef API_INC_API_MEF_SIST_H_
#define API_INC_API_MEF_SIST_H_

#include <stdbool.h>
#include <stdint.h>
#include "stm32f4xx_hal.h"
#include "API_config.h"

void MEF_sist_init(void);
void MEF_sist_update(uint32_t adc_value);
char Get_state(void);
void Error_Handler_MEF(void);

#endif /* API_INC_API_MEF_SIST_H_ */
