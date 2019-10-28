################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Lapack/Blas/daxpy.c \
../src/Lapack/Blas/dcopy.c \
../src/Lapack/Blas/ddot.c \
../src/Lapack/Blas/dgemm.c \
../src/Lapack/Blas/dgemv.c \
../src/Lapack/Blas/dger.c \
../src/Lapack/Blas/dnrm2.c \
../src/Lapack/Blas/drot.c \
../src/Lapack/Blas/dscal.c \
../src/Lapack/Blas/dswap.c \
../src/Lapack/Blas/dtrmm.c \
../src/Lapack/Blas/dtrmv.c \
../src/Lapack/Blas/dtrsm.c \
../src/Lapack/Blas/idamax.c \
../src/Lapack/Blas/isamax.c \
../src/Lapack/Blas/lsame.c \
../src/Lapack/Blas/saxpy.c \
../src/Lapack/Blas/scopy.c \
../src/Lapack/Blas/sdot.c \
../src/Lapack/Blas/sgemm.c \
../src/Lapack/Blas/sgemv.c \
../src/Lapack/Blas/sger.c \
../src/Lapack/Blas/snrm2.c \
../src/Lapack/Blas/srot.c \
../src/Lapack/Blas/sscal.c \
../src/Lapack/Blas/sswap.c \
../src/Lapack/Blas/strmm.c \
../src/Lapack/Blas/strmv.c \
../src/Lapack/Blas/strsm.c \
../src/Lapack/Blas/xerbla.c 

OBJS += \
./src/Lapack/Blas/daxpy.o \
./src/Lapack/Blas/dcopy.o \
./src/Lapack/Blas/ddot.o \
./src/Lapack/Blas/dgemm.o \
./src/Lapack/Blas/dgemv.o \
./src/Lapack/Blas/dger.o \
./src/Lapack/Blas/dnrm2.o \
./src/Lapack/Blas/drot.o \
./src/Lapack/Blas/dscal.o \
./src/Lapack/Blas/dswap.o \
./src/Lapack/Blas/dtrmm.o \
./src/Lapack/Blas/dtrmv.o \
./src/Lapack/Blas/dtrsm.o \
./src/Lapack/Blas/idamax.o \
./src/Lapack/Blas/isamax.o \
./src/Lapack/Blas/lsame.o \
./src/Lapack/Blas/saxpy.o \
./src/Lapack/Blas/scopy.o \
./src/Lapack/Blas/sdot.o \
./src/Lapack/Blas/sgemm.o \
./src/Lapack/Blas/sgemv.o \
./src/Lapack/Blas/sger.o \
./src/Lapack/Blas/snrm2.o \
./src/Lapack/Blas/srot.o \
./src/Lapack/Blas/sscal.o \
./src/Lapack/Blas/sswap.o \
./src/Lapack/Blas/strmm.o \
./src/Lapack/Blas/strmv.o \
./src/Lapack/Blas/strsm.o \
./src/Lapack/Blas/xerbla.o 

C_DEPS += \
./src/Lapack/Blas/daxpy.d \
./src/Lapack/Blas/dcopy.d \
./src/Lapack/Blas/ddot.d \
./src/Lapack/Blas/dgemm.d \
./src/Lapack/Blas/dgemv.d \
./src/Lapack/Blas/dger.d \
./src/Lapack/Blas/dnrm2.d \
./src/Lapack/Blas/drot.d \
./src/Lapack/Blas/dscal.d \
./src/Lapack/Blas/dswap.d \
./src/Lapack/Blas/dtrmm.d \
./src/Lapack/Blas/dtrmv.d \
./src/Lapack/Blas/dtrsm.d \
./src/Lapack/Blas/idamax.d \
./src/Lapack/Blas/isamax.d \
./src/Lapack/Blas/lsame.d \
./src/Lapack/Blas/saxpy.d \
./src/Lapack/Blas/scopy.d \
./src/Lapack/Blas/sdot.d \
./src/Lapack/Blas/sgemm.d \
./src/Lapack/Blas/sgemv.d \
./src/Lapack/Blas/sger.d \
./src/Lapack/Blas/snrm2.d \
./src/Lapack/Blas/srot.d \
./src/Lapack/Blas/sscal.d \
./src/Lapack/Blas/sswap.d \
./src/Lapack/Blas/strmm.d \
./src/Lapack/Blas/strmv.d \
./src/Lapack/Blas/strsm.d \
./src/Lapack/Blas/xerbla.d 


# Each subdirectory must supply rules for building sources it contributes
src/Lapack/Blas/%.o: ../src/Lapack/Blas/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


