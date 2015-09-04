################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/euler.c \
../src/pb_0001.c \
../src/pb_0002.c \
../src/pb_0003.c \
../src/pb_0004.c \
../src/pb_0005.c \
../src/pb_0006.c \
../src/pb_0007.c 

OBJS += \
./src/euler.o \
./src/pb_0001.o \
./src/pb_0002.o \
./src/pb_0003.o \
./src/pb_0004.o \
./src/pb_0005.o \
./src/pb_0006.o \
./src/pb_0007.o 

C_DEPS += \
./src/euler.d \
./src/pb_0001.d \
./src/pb_0002.d \
./src/pb_0003.d \
./src/pb_0004.d \
./src/pb_0005.d \
./src/pb_0006.d \
./src/pb_0007.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


