################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Components/InputComponent.cpp 

OBJS += \
./src/Components/InputComponent.o 

CPP_DEPS += \
./src/Components/InputComponent.d 


# Each subdirectory must supply rules for building sources it contributes
src/Components/%.o: ../src/Components/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


