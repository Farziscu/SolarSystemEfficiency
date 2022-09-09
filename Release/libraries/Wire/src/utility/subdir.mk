################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:\eclipse_cpp2\arduinoPlugin\packages\arduino\hardware\avr\1.8.5\libraries\Wire\src\utility\twi.c 

C_DEPS += \
.\libraries\Wire\src\utility\twi.c.d 

LINK_OBJ += \
.\libraries\Wire\src\utility\twi.c.o 


# Each subdirectory must supply rules for building sources it contributes
libraries\Wire\src\utility\twi.c.o: C:\eclipse_cpp2\arduinoPlugin\packages\arduino\hardware\avr\1.8.5\libraries\Wire\src\utility\twi.c
	@echo 'Building file: $<'
	@echo 'Avvio compilazione C'
	"C:\eclipse_cpp2\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR     -I"C:\eclipse_cpp2\arduinoPlugin\libraries\SD\1.2.4\src" -I"C:\eclipse_cpp2\arduinoPlugin\packages\arduino\hardware\avr\1.8.5\libraries\SPI\src" -I"C:\Users\franc\Documents\Arduino\libraries\RTClib" -I"C:\Users\franc\Documents\Arduino\libraries\Adafruit_Unified_Sensor-1.1.6" -I"C:\eclipse_cpp2\arduinoPlugin\libraries\Simpletimer\2.1.4\src" -I"C:\eclipse_cpp2\arduinoPlugin\packages\arduino\hardware\avr\1.8.5\libraries\Wire\src" -I"C:\eclipse_cpp2\arduinoPlugin\packages\arduino\hardware\avr\1.8.5\cores\arduino" -I"C:\eclipse_cpp2\arduinoPlugin\packages\arduino\hardware\avr\1.8.5\variants\standard" -I"C:\Users\franc\Documents\Arduino\libraries\MemoryUsage-2.21.1\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '


