################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/LinearAlgebra/add.c \
../src/LinearAlgebra/chol.c \
../src/LinearAlgebra/cofact.c \
../src/LinearAlgebra/copy.c \
../src/LinearAlgebra/cut.c \
../src/LinearAlgebra/det.c \
../src/LinearAlgebra/diag.c \
../src/LinearAlgebra/diagpower.c \
../src/LinearAlgebra/dot.c \
../src/LinearAlgebra/eabs.c \
../src/LinearAlgebra/eig.c \
../src/LinearAlgebra/eye.c \
../src/LinearAlgebra/hankel.c \
../src/LinearAlgebra/horzcat.c \
../src/LinearAlgebra/insert.c \
../src/LinearAlgebra/inv.c \
../src/LinearAlgebra/linsolve.c \
../src/LinearAlgebra/lu.c \
../src/LinearAlgebra/maxvector.c \
../src/LinearAlgebra/mdiag.c \
../src/LinearAlgebra/minvector.c \
../src/LinearAlgebra/move.c \
../src/LinearAlgebra/mpower.c \
../src/LinearAlgebra/mul.c \
../src/LinearAlgebra/norm.c \
../src/LinearAlgebra/ones.c \
../src/LinearAlgebra/pinv.c \
../src/LinearAlgebra/power.c \
../src/LinearAlgebra/print.c \
../src/LinearAlgebra/qr.c \
../src/LinearAlgebra/quadprog.c \
../src/LinearAlgebra/rank.c \
../src/LinearAlgebra/repmat.c \
../src/LinearAlgebra/scale.c \
../src/LinearAlgebra/sqrte.c \
../src/LinearAlgebra/sub.c \
../src/LinearAlgebra/sumrows.c \
../src/LinearAlgebra/svd.c \
../src/LinearAlgebra/toeplitz.c \
../src/LinearAlgebra/tran.c \
../src/LinearAlgebra/tril.c \
../src/LinearAlgebra/triu.c \
../src/LinearAlgebra/vec.c \
../src/LinearAlgebra/vertcat.c \
../src/LinearAlgebra/zeros.c 

OBJS += \
./src/LinearAlgebra/add.o \
./src/LinearAlgebra/chol.o \
./src/LinearAlgebra/cofact.o \
./src/LinearAlgebra/copy.o \
./src/LinearAlgebra/cut.o \
./src/LinearAlgebra/det.o \
./src/LinearAlgebra/diag.o \
./src/LinearAlgebra/diagpower.o \
./src/LinearAlgebra/dot.o \
./src/LinearAlgebra/eabs.o \
./src/LinearAlgebra/eig.o \
./src/LinearAlgebra/eye.o \
./src/LinearAlgebra/hankel.o \
./src/LinearAlgebra/horzcat.o \
./src/LinearAlgebra/insert.o \
./src/LinearAlgebra/inv.o \
./src/LinearAlgebra/linsolve.o \
./src/LinearAlgebra/lu.o \
./src/LinearAlgebra/maxvector.o \
./src/LinearAlgebra/mdiag.o \
./src/LinearAlgebra/minvector.o \
./src/LinearAlgebra/move.o \
./src/LinearAlgebra/mpower.o \
./src/LinearAlgebra/mul.o \
./src/LinearAlgebra/norm.o \
./src/LinearAlgebra/ones.o \
./src/LinearAlgebra/pinv.o \
./src/LinearAlgebra/power.o \
./src/LinearAlgebra/print.o \
./src/LinearAlgebra/qr.o \
./src/LinearAlgebra/quadprog.o \
./src/LinearAlgebra/rank.o \
./src/LinearAlgebra/repmat.o \
./src/LinearAlgebra/scale.o \
./src/LinearAlgebra/sqrte.o \
./src/LinearAlgebra/sub.o \
./src/LinearAlgebra/sumrows.o \
./src/LinearAlgebra/svd.o \
./src/LinearAlgebra/toeplitz.o \
./src/LinearAlgebra/tran.o \
./src/LinearAlgebra/tril.o \
./src/LinearAlgebra/triu.o \
./src/LinearAlgebra/vec.o \
./src/LinearAlgebra/vertcat.o \
./src/LinearAlgebra/zeros.o 

C_DEPS += \
./src/LinearAlgebra/add.d \
./src/LinearAlgebra/chol.d \
./src/LinearAlgebra/cofact.d \
./src/LinearAlgebra/copy.d \
./src/LinearAlgebra/cut.d \
./src/LinearAlgebra/det.d \
./src/LinearAlgebra/diag.d \
./src/LinearAlgebra/diagpower.d \
./src/LinearAlgebra/dot.d \
./src/LinearAlgebra/eabs.d \
./src/LinearAlgebra/eig.d \
./src/LinearAlgebra/eye.d \
./src/LinearAlgebra/hankel.d \
./src/LinearAlgebra/horzcat.d \
./src/LinearAlgebra/insert.d \
./src/LinearAlgebra/inv.d \
./src/LinearAlgebra/linsolve.d \
./src/LinearAlgebra/lu.d \
./src/LinearAlgebra/maxvector.d \
./src/LinearAlgebra/mdiag.d \
./src/LinearAlgebra/minvector.d \
./src/LinearAlgebra/move.d \
./src/LinearAlgebra/mpower.d \
./src/LinearAlgebra/mul.d \
./src/LinearAlgebra/norm.d \
./src/LinearAlgebra/ones.d \
./src/LinearAlgebra/pinv.d \
./src/LinearAlgebra/power.d \
./src/LinearAlgebra/print.d \
./src/LinearAlgebra/qr.d \
./src/LinearAlgebra/quadprog.d \
./src/LinearAlgebra/rank.d \
./src/LinearAlgebra/repmat.d \
./src/LinearAlgebra/scale.d \
./src/LinearAlgebra/sqrte.d \
./src/LinearAlgebra/sub.d \
./src/LinearAlgebra/sumrows.d \
./src/LinearAlgebra/svd.d \
./src/LinearAlgebra/toeplitz.d \
./src/LinearAlgebra/tran.d \
./src/LinearAlgebra/tril.d \
./src/LinearAlgebra/triu.d \
./src/LinearAlgebra/vec.d \
./src/LinearAlgebra/vertcat.d \
./src/LinearAlgebra/zeros.d 


# Each subdirectory must supply rules for building sources it contributes
src/LinearAlgebra/%.o: ../src/LinearAlgebra/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


