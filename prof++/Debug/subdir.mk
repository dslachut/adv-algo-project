################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../Binarysearch.cc \
../Heap.cc \
../Insertionsort.cc \
../Permute.cc \
../Quicksort.cc \
../main.cc 

OBJS += \
./Binarysearch.o \
./Heap.o \
./Insertionsort.o \
./Permute.o \
./Quicksort.o \
./main.o 

CC_DEPS += \
./Binarysearch.d \
./Heap.d \
./Insertionsort.d \
./Permute.d \
./Quicksort.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


