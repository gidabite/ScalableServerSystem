################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/PhysicalParameters/Axis.cpp \
../src/PhysicalParameters/Position.cpp \
../src/PhysicalParameters/Rotation.cpp \
../src/PhysicalParameters/Scale.cpp \
../src/PhysicalParameters/Vector3.cpp 

OBJS += \
./src/PhysicalParameters/Axis.o \
./src/PhysicalParameters/Position.o \
./src/PhysicalParameters/Rotation.o \
./src/PhysicalParameters/Scale.o \
./src/PhysicalParameters/Vector3.o 

CPP_DEPS += \
./src/PhysicalParameters/Axis.d \
./src/PhysicalParameters/Position.d \
./src/PhysicalParameters/Rotation.d \
./src/PhysicalParameters/Scale.d \
./src/PhysicalParameters/Vector3.d 


# Each subdirectory must supply rules for building sources it contributes
src/PhysicalParameters/%.o: ../src/PhysicalParameters/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


