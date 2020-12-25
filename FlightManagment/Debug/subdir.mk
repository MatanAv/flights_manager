################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../airline.c \
../airport.c \
../airportManager.c \
../date.c \
../flight.c \
../generalFunc.c \
../main.c \
../menu.c 

OBJS += \
./airline.o \
./airport.o \
./airportManager.o \
./date.o \
./flight.o \
./generalFunc.o \
./main.o \
./menu.o 

C_DEPS += \
./airline.d \
./airport.d \
./airportManager.d \
./date.d \
./flight.d \
./generalFunc.d \
./main.d \
./menu.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


