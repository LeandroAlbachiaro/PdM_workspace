# Proyecto Final de Programación de Microcontroladores

## Descripción

Este proyecto consiste en un programa que mide una variable analógica a través del ADC (Convertidor Analógico-Digital) y cambia su estado dependiendo de su valor. Los estados son definidos como Bajo, Medio, Alto y Parada, y están determinados por el valor de la medición y la presencia del botón de parada.

## Estados

- **Bajo**: La medición es menor al 20% del rango del ADC y el botón de parada no está presionado.
- **Medio**: La medición está entre el 20% y el 80% del rango del ADC y el botón de parada no está presionado.
- **Alto**: La medición supera el 80% del rango del ADC y el botón de parada no está presionado.
- **Parada**: Se presiona el botón de parada, sin importar la medición del ADC.

## Funcionamiento

El programa indica el valor medido y el estado a través de la UART (Comunicación Asíncrona Universal) y de un display LCD.

## Módulos de Software Desarrollados

- **API_adc**: Inicializa y realiza la lectura del ADC.
- **API_config**: Contiene las definiciones del código y configura el clock e inicializa los periféricos.
- **API_lcd**: Funciones para el manejo del display LCD.
- **API_mef_sist**: Realiza el control de la MEF (Máquina de Estados Finitos) y devuelve el estado a través de una función Get.
- **API_uart**: Inicializa la UART.

## Periféricos Utilizados

- **UART**:
  - BaudRate: 19200 bps.
  - WordLength: 8 bits.
  - StopBits: 1 bit.
  - Paridad: No.
  - Control de flujo: No.
  - Modo: Tx/Rx.
- **GPIO**:
  - **LCD**:
    - Pines: EN_Pin, RS_Pin, D4_Pin, D5_Pin, D6_Pin, D7_Pin.
    - Modo: Salida Push-Pull.
    - Pull: Sin Pull-Up / Pull-Down.
    - Velocidad: Baja.
  - **ADC**:
    - Pines: GPIO_PIN_0.
    - Modo: Entrada analógica.
    - Pull: Sin Pull-Up / Pull-Down.

## Máquina de Estados Finitos

![Máquina de Estados Finitos](https://github.com/LeandroAlbachiaro/PdM_workspace/blob/main/Trabajo%20Practico%20Final/Diagrama%20de%20estado.png)

## Video de Funcionamiento

[Ver video](https://github.com/LeandroAlbachiaro/PdM_workspace/Trabajo%Practico%Final/Video%de%Funcionamiento.mp4)

