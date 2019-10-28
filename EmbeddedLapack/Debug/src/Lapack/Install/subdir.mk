################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Lapack/Install/dlamch.c \
../src/Lapack/Install/slamch.c 

OBJS += \
./src/Lapack/Install/dlamch.o \
./src/Lapack/Install/slamch.o 

C_DEPS += \
./src/Lapack/Install/dlamch.d \
./src/Lapack/Install/slamch.d 


# Each subdirectory must supply rules for building sources it contributes
src/Lapack/Install/%.o: ../src/Lapack/Install/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


