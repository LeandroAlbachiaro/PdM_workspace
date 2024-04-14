################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/API/src/API_adc.c \
../Drivers/API/src/API_config.c \
../Drivers/API/src/API_lcd.c \
../Drivers/API/src/API_mef_sist.c \
../Drivers/API/src/API_uart.c 

OBJS += \
./Drivers/API/src/API_adc.o \
./Drivers/API/src/API_config.o \
./Drivers/API/src/API_lcd.o \
./Drivers/API/src/API_mef_sist.o \
./Drivers/API/src/API_uart.o 

C_DEPS += \
./Drivers/API/src/API_adc.d \
./Drivers/API/src/API_config.d \
./Drivers/API/src/API_lcd.d \
./Drivers/API/src/API_mef_sist.d \
./Drivers/API/src/API_uart.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/API/src/%.o Drivers/API/src/%.su Drivers/API/src/%.cyclo: ../Drivers/API/src/%.c Drivers/API/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/lalba/STM32CubeIDE/workspace_1.14.1/Trabajo Practico Final/Drivers/API/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-API-2f-src

clean-Drivers-2f-API-2f-src:
	-$(RM) ./Drivers/API/src/API_adc.cyclo ./Drivers/API/src/API_adc.d ./Drivers/API/src/API_adc.o ./Drivers/API/src/API_adc.su ./Drivers/API/src/API_config.cyclo ./Drivers/API/src/API_config.d ./Drivers/API/src/API_config.o ./Drivers/API/src/API_config.su ./Drivers/API/src/API_lcd.cyclo ./Drivers/API/src/API_lcd.d ./Drivers/API/src/API_lcd.o ./Drivers/API/src/API_lcd.su ./Drivers/API/src/API_mef_sist.cyclo ./Drivers/API/src/API_mef_sist.d ./Drivers/API/src/API_mef_sist.o ./Drivers/API/src/API_mef_sist.su ./Drivers/API/src/API_uart.cyclo ./Drivers/API/src/API_uart.d ./Drivers/API/src/API_uart.o ./Drivers/API/src/API_uart.su

.PHONY: clean-Drivers-2f-API-2f-src

