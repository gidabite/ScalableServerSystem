################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Socket/OutMemoryStream.cpp \
../src/Socket/SocketAddress.cpp \
../src/Socket/SocketAddressFactory.cpp \
../src/Socket/SocketUtil.cpp \
../src/Socket/UDPSocket.cpp 

OBJS += \
./src/Socket/OutMemoryStream.o \
./src/Socket/SocketAddress.o \
./src/Socket/SocketAddressFactory.o \
./src/Socket/SocketUtil.o \
./src/Socket/UDPSocket.o 

CPP_DEPS += \
./src/Socket/OutMemoryStream.d \
./src/Socket/SocketAddress.d \
./src/Socket/SocketAddressFactory.d \
./src/Socket/SocketUtil.d \
./src/Socket/UDPSocket.d 


# Each subdirectory must supply rules for building sources it contributes
src/Socket/%.o: ../src/Socket/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/gidabite/workspace/Server/src/bullet -I/home/gidabite/workspace/Server/src/bullet/BulletCollision -I/home/gidabite/workspace/Server/src/bullet/BulletDynamics -I/home/gidabite/workspace/Server/src/bullet/BulletSoftBody -I/home/gidabite/workspace/Server/src/bullet/BulletMultiThreaded -I/home/gidabite/workspace/Server/src/bullet/LinearMath -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


