################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/API/src/API_delay.c 

OBJS += \
./Drivers/API/src/API_delay.o 

C_DEPS += \
./Drivers/API/src/API_delay.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/API/src/%.o Drivers/API/src/%.su Drivers/API/src/%.cyclo: ../Drivers/API/src/%.c Drivers/API/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DNUCLEO_F429ZI -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Inc -I"C:/Users/lalba/STM32CubeIDE/workspace_1.14.1/Practica 3/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/lalba/STM32CubeIDE/workspace_1.14.1/Practica 3/Drivers/CMSIS/Include" -I"C:/Users/lalba/STM32CubeIDE/workspace_1.14.1/Practica 3/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/lalba/STM32CubeIDE/workspace_1.14.1/Practica 3/Drivers/BSP/STM32F4xx_Nucleo_144" -I"C:/Users/lalba/STM32CubeIDE/workspace_1.14.1/Practica 3/Drivers/Core/Inc" -I"C:/Users/lalba/STM32CubeIDE/workspace_1.14.1/Practica 3/Drivers/API/inc" -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-API-2f-src

clean-Drivers-2f-API-2f-src:
	-$(RM) ./Drivers/API/src/API_delay.cyclo ./Drivers/API/src/API_delay.d ./Drivers/API/src/API_delay.o ./Drivers/API/src/API_delay.su

.PHONY: clean-Drivers-2f-API-2f-src

