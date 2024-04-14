/*
 * API_uart.h
 *
 *  Created on: Apr 11, 2024
 *      Author: lalba
 */

#ifndef API_INC_API_UART_H_
#define API_INC_API_UART_H_

#include "stm32f4xx_hal.h"

extern UART_HandleTypeDef huart3;

void MX_USART3_UART_Init(void);
void Error_Handler_uart(void);

#endif /* API_INC_API_UART_H_ */
