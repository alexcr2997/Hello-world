################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
D:/DIPLOMADO_EMBEBIDOS/TAREAS/MODULO_2/S32\ Design\ Studio/S32DS/software/S32SDK_S32K1XX_RTM_4.0.2/platform/devices/S32K144/startup/gcc/startup_S32K144.S 

OBJS += \
./Project_Settings/Startup_Code/startup_S32K144.o 


# Each subdirectory must supply rules for building sources it contributes
Project_Settings/Startup_Code/startup_S32K144.o: D:/DIPLOMADO_EMBEBIDOS/TAREAS/MODULO_2/S32\ Design\ Studio/S32DS/software/S32SDK_S32K1XX_RTM_4.0.2/platform/devices/S32K144/startup/gcc/startup_S32K144.S
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS Assembler'
	arm-none-eabi-gcc "@Project_Settings/Startup_Code/startup_S32K144.args" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


