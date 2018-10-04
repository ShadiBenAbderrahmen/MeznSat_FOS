################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Tasks/ground_mode_task.c \
../src/Tasks/housekeeping_task.c \
../src/Tasks/normal_mode_task.c 

OBJS += \
./src/Tasks/ground_mode_task.o \
./src/Tasks/housekeeping_task.o \
./src/Tasks/normal_mode_task.o 

C_DEPS += \
./src/Tasks/ground_mode_task.d \
./src/Tasks/housekeeping_task.d \
./src/Tasks/normal_mode_task.d 


# Each subdirectory must supply rules for building sources it contributes
src/Tasks/%.o: ../src/Tasks/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=arm926ej-s -O0 -fmessage-length=0 -ffunction-sections -Wall -Wextra  -g -Dsdram -D"IOBC_REV='C'" -Dat91sam9g20 -DTRACE_LEVEL=5 -DDEBUG=1 -D'BASE_REVISION_NUMBER=$(REV)' -D'BASE_REVISION_HASH_SHORT=$(REVHASH_SHORT)' -D'BASE_REVISION_HASH=$(REVHASH)' -I"D:\Internship 2018\OBC Projects\SecondProject\FirstProject\src" -I"D:/Internship 2018/OBC Projects/SecondProject/FirstProject/..//hal/freertos/include" -I"D:/Internship 2018/OBC Projects/SecondProject/FirstProject/..//hal/hal/include" -I"D:/Internship 2018/OBC Projects/SecondProject/FirstProject/..//hal/at91/include" -I"D:/Internship 2018/OBC Projects/SecondProject/FirstProject/..//hal/hcc/include" -I"D:/Internship 2018/OBC Projects/SecondProject/FirstProject/..//satellite-subsystems/satellite-subsystems/include" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


