/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define NUM_SAMPLES 10 // Número de muestras para promediar
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;
UART_HandleTypeDef huart3;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  uint32_t adc_value; // Variable para almacenar el valor del ADC
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART3_UART_Init();
  MX_ADC1_Init();
  /* USER CODE BEGIN 2 */

  // Inicializar el ADC y la MEF
  HAL_ADC_Init(&hadc1);
  MEF_sist_init();

  // Configura los pines y puertos necesarios para el LCD
  Lcd_PortType data_ports[] = {D4_GPIO_Port, D5_GPIO_Port,
		  	  	  	  	  	  D6_GPIO_Port, D7_GPIO_Port};
  Lcd_PinType data_pins[] = {D4_Pin, D5_Pin, D6_Pin, D7_Pin};
  Lcd_PortType rs_port = RS_GPIO_Port;
  Lcd_PinType rs_pin = RS_Pin;
  Lcd_PortType en_port = EN_GPIO_Port;
  Lcd_PinType en_pin = EN_Pin;

  // Crea una instancia de Lcd_HandleTypeDef
  Lcd_HandleTypeDef lcd = Lcd_create(data_ports, data_pins, rs_port, rs_pin, en_port, en_pin, LCD_4_BIT_MODE);

  // Inicializa el LCD
  Lcd_init(&lcd);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  // Leer el ADC y actualizar la MEF
	  adc_value = (read_adc_value(&hadc1, NUM_SAMPLES)*100/4095);
	  MEF_sist_update(adc_value);
	  char estado = Get_state();

	  // Limpiar pantalla LCD
	  Lcd_clear(&lcd);

	  // Mostrar el estado de la MEF en el LCD
	  Lcd_cursor(&lcd, 0, 0);
	  char lcd_buffer[16];
	  snprintf(lcd_buffer, sizeof(lcd_buffer), "Estado: %c", estado);
	  Lcd_string(&lcd, lcd_buffer);

	  // Mostrar el valor del ADC en el LCD
	  Lcd_cursor(&lcd, 1, 0);
	  snprintf(lcd_buffer, sizeof(lcd_buffer), "ADC: %lu", adc_value);
	  Lcd_string(&lcd, lcd_buffer);

      // Transmitir el valor del ADC y el estado a través del UART
      char buffer[50];
      snprintf(buffer, sizeof(buffer), "Estado: %c - Valor Medido: %lu\r", estado, adc_value);
      HAL_UART_Transmit(&huart3, (uint8_t *)buffer, strlen((char *)buffer), HAL_MAX_DELAY);

      // Esperar 500 ms antes de la próxima transmisión
      HAL_Delay(500);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
