################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Helpers/Transceiver.c \
../src/Helpers/initializations.c 

OBJS += \
./src/Helpers/Transceiver.o \
./src/Helpers/initializations.o 

C_DEPS += \
./src/Helpers/Transceiver.d \
./src/Helpers/initializations.d 


# Each subdirectory must supply rules for building sources it contributes
src/Helpers/%.o: ../src/Helpers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=arm926ej-s -O0 -fmessage-length=0 -ffunction-sections -Wall -Wextra  -g -Dsdram -D"IOBC_REV='C'" -Dat91sam9g20 -DTRACE_LEVEL=5 -DDEBUG=1 -D'BASE_REVISION_NUMBER=$(REV)' -D'BASE_REVISION_HASH_SHORT=$(REVHASH_SHORT)' -D'BASE_REVISION_HASH=$(REVHASH)' -I"D:\Internship 2018\OBC Projects\SecondProject\FirstProject\src" -I"D:/Internship 2018/OBC Projects/SecondProject/FirstProject/..//hal/freertos/include" -I"D:/Internship 2018/OBC Projects/SecondProject/FirstProject/..//hal/hal/include" -I"D:/Internship 2018/OBC Projects/SecondProject/FirstProject/..//hal/at91/include" -I"D:/Internship 2018/OBC Projects/SecondProject/FirstProject/..//hal/hcc/include" -I"D:/Internship 2018/OBC Projects/SecondProject/FirstProject/..//satellite-subsystems/satellite-subsystems/include" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


