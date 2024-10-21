################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../array.c \
../boolean.c \
../information.c \
../memory.c \
../struct.c 

C_DEPS += \
./array.d \
./boolean.d \
./information.d \
./memory.d \
./struct.d 

OBJS += \
./array.o \
./boolean.o \
./information.o \
./memory.o \
./struct.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -c -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./array.d ./array.o ./boolean.d ./boolean.o ./information.d ./information.o ./memory.d ./memory.o ./struct.d ./struct.o

.PHONY: clean--2e-

