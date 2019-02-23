################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Lapack/F2c/d_lg10.c \
../src/Lapack/F2c/d_sign.c \
../src/Lapack/F2c/exit_.c \
../src/Lapack/F2c/f77_aloc.c \
../src/Lapack/F2c/i_nint.c \
../src/Lapack/F2c/pow_dd.c \
../src/Lapack/F2c/pow_di.c \
../src/Lapack/F2c/pow_ri.c \
../src/Lapack/F2c/r_lg10.c \
../src/Lapack/F2c/r_sign.c \
../src/Lapack/F2c/s_cat.c \
../src/Lapack/F2c/s_cmp.c \
../src/Lapack/F2c/s_copy.c 

OBJS += \
./src/Lapack/F2c/d_lg10.o \
./src/Lapack/F2c/d_sign.o \
./src/Lapack/F2c/exit_.o \
./src/Lapack/F2c/f77_aloc.o \
./src/Lapack/F2c/i_nint.o \
./src/Lapack/F2c/pow_dd.o \
./src/Lapack/F2c/pow_di.o \
./src/Lapack/F2c/pow_ri.o \
./src/Lapack/F2c/r_lg10.o \
./src/Lapack/F2c/r_sign.o \
./src/Lapack/F2c/s_cat.o \
./src/Lapack/F2c/s_cmp.o \
./src/Lapack/F2c/s_copy.o 

C_DEPS += \
./src/Lapack/F2c/d_lg10.d \
./src/Lapack/F2c/d_sign.d \
./src/Lapack/F2c/exit_.d \
./src/Lapack/F2c/f77_aloc.d \
./src/Lapack/F2c/i_nint.d \
./src/Lapack/F2c/pow_dd.d \
./src/Lapack/F2c/pow_di.d \
./src/Lapack/F2c/pow_ri.d \
./src/Lapack/F2c/r_lg10.d \
./src/Lapack/F2c/r_sign.d \
./src/Lapack/F2c/s_cat.d \
./src/Lapack/F2c/s_cmp.d \
./src/Lapack/F2c/s_copy.d 


# Each subdirectory must supply rules for building sources it contributes
src/Lapack/F2c/%.o: ../src/Lapack/F2c/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -std=c11 -O2 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


