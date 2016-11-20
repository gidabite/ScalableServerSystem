################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/GameObject/BaseObject.cpp \
../src/GameObject/InputState.cpp 

OBJS += \
./src/GameObject/BaseObject.o \
./src/GameObject/InputState.o 

CPP_DEPS += \
./src/GameObject/BaseObject.d \
./src/GameObject/InputState.d 


# Each subdirectory must supply rules for building sources it contributes
src/GameObject/%.o: ../src/GameObject/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


