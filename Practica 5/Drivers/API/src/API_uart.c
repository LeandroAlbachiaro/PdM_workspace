/*
 * API_uart.c
 *
 *  Created on: Mar 31, 2024
 *      Author: lalba
 */

#include "API_uart.h"
#include "stm32f4xx_hal.h"  		/* <- HAL include */
#include <stdio.h>
#include <string.h>

UART_HandleTypeDef UartHandle;

bool uartInit() {
	  /*##-1- Configure the UART peripheral ######################################*/
	  /* Put the USART peripheral in the Asynchronous mode (UART Mode) */
	  /* UART configured as follows:
	      - Word Length = 8 Bits (7 data bit + 1 parity bit) :
		                  BE CAREFUL : Program 7 data bits + 1 parity bit in PC HyperTerminal
	      - Stop Bit    = One Stop bit
	      - Parity      = NONE
	      - BaudRate    = 9600 baud
	      - Hardware flow control disabled (RTS and CTS signals) */
	  UartHandle.Instance        = USART3;
	  UartHandle.Init.BaudRate   = 9600;
	  UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
	  UartHandle.Init.StopBits   = UART_STOPBITS_1;
	  UartHandle.Init.Parity     = UART_PARITY_NONE;
	  UartHandle.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
	  UartHandle.Init.Mode       = UART_MODE_TX_RX;
	  UartHandle.Init.OverSampling = UART_OVERSAMPLING_16;

    if (HAL_UART_Init(&UartHandle) != HAL_OK) {
        return false;
    }



    //Imprime los parámetros de configuración por la UART
    char msg[100];
    sprintf(msg, "UART initialized. Baud rate: %lu 8N1\r\n", UartHandle.Init.BaudRate);
    HAL_UART_Transmit(&UartHandle, (uint8_t *)msg, strlen(msg), HAL_MAX_DELAY);

    return true;
}

void uartSendString(uint8_t *pstring) {
    HAL_UART_Transmit(&UartHandle, pstring, strlen((char *)pstring), HAL_MAX_DELAY);
}

void uartSendStringSize(uint8_t *pstring, uint16_t size) {
    HAL_UART_Transmit(&UartHandle, pstring, size, HAL_MAX_DELAY);
}

void uartReceiveStringSize(uint8_t *pstring, uint16_t size) {
    // TODO
}
