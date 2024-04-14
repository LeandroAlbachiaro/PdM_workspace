/*
 * API_adc.c
 *
 *  Created on: Apr 11, 2024
 *      Author: lalba
 */

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
#include "API_adc.h"

void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler_adc();
  }

  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler_adc();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief Function to read ADC1 value
  * @param hadc: pointer to ADC_HandleTypeDef structure that contains the configuration
  * information for the specified ADC.
  * @param num_samples: number of samples to be averaged.
  * @retval Average ADC value of specified number of samples.
  *
  * Esta función asegura una lectura precisa del ADC tomando múltiples muestras y calculando
  * su promedio, lo que ayuda a reducir el ruido y mejorar la estabilidad de la medición.
  */
uint32_t read_adc_value(ADC_HandleTypeDef* hadc, uint32_t num_samples) {
    uint32_t adc_sum = 0;

    for (int i = 0; i < num_samples; i++) {
        // Iniciar la conversión ADC por software
        HAL_ADC_Start(hadc);

        // Esperar a que la conversión se complete
        HAL_ADC_PollForConversion(hadc, HAL_MAX_DELAY);

        // Leer el valor convertido del ADC y acumularlo en la suma
        adc_sum += HAL_ADC_GetValue(hadc);
    }

    // Calcular el promedio de las muestras
    uint32_t adc_average = adc_sum / num_samples;

    return adc_average;
}

void Error_Handler_adc(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
