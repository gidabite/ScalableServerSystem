################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Components/HandlerComponent.cpp \
../src/Components/InputComponent.cpp \
../src/Components/OutputComponent.cpp 

OBJS += \
./src/Components/HandlerComponent.o \
./src/Components/InputComponent.o \
./src/Components/OutputComponent.o 

CPP_DEPS += \
./src/Components/HandlerComponent.d \
./src/Components/InputComponent.d \
./src/Components/OutputComponent.d 


# Each subdirectory must supply rules for building sources it contributes
src/Components/%.o: ../src/Components/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


