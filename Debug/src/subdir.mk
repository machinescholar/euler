################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/commath.c \
../src/euler.c \
../src/list.c \
../src/pb_0001.c \
../src/pb_0002.c \
../src/pb_0003.c \
../src/pb_0004.c \
../src/pb_0005.c \
../src/pb_0006.c \
../src/pb_0007.c \
../src/pb_0008.c \
../src/pb_0009.c \
../src/pb_0010.c \
../src/pb_0011.c \
../src/pb_0012.c 

OBJS += \
./src/commath.o \
./src/euler.o \
./src/list.o \
./src/pb_0001.o \
./src/pb_0002.o \
./src/pb_0003.o \
./src/pb_0004.o \
./src/pb_0005.o \
./src/pb_0006.o \
./src/pb_0007.o \
./src/pb_0008.o \
./src/pb_0009.o \
./src/pb_0010.o \
./src/pb_0011.o \
./src/pb_0012.o 

C_DEPS += \
./src/commath.d \
./src/euler.d \
./src/list.d \
./src/pb_0001.d \
./src/pb_0002.d \
./src/pb_0003.d \
./src/pb_0004.d \
./src/pb_0005.d \
./src/pb_0006.d \
./src/pb_0007.d \
./src/pb_0008.d \
./src/pb_0009.d \
./src/pb_0010.d \
./src/pb_0011.d \
./src/pb_0012.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


