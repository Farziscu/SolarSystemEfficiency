################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:\eclipse_cpp2\arduinoPlugin\libraries\Simpletimer\2.1.4\src\Simpletimer.cpp 

LINK_OBJ += \
.\libraries\Simpletimer\src\Simpletimer.cpp.o 

CPP_DEPS += \
.\libraries\Simpletimer\src\Simpletimer.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries\Simpletimer\src\Simpletimer.cpp.o: C:\eclipse_cpp2\arduinoPlugin\libraries\Simpletimer\2.1.4\src\Simpletimer.cpp
	@echo 'Building file: $<'
	@echo 'Avvio compilazione C++'
	"C:\eclipse_cpp2\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR     -I"C:\eclipse_cpp2\arduinoPlugin\libraries\SD\1.2.4\src" -I"C:\eclipse_cpp2\arduinoPlugin\packages\arduino\hardware\avr\1.8.5\libraries\SPI\src" -I"C:\Users\franc\Documents\Arduino\libraries\RTClib" -I"C:\Users\franc\Documents\Arduino\libraries\Adafruit_Unified_Sensor-1.1.6" -I"C:\eclipse_cpp2\arduinoPlugin\libraries\Simpletimer\2.1.4\src" -I"C:\eclipse_cpp2\arduinoPlugin\packages\arduino\hardware\avr\1.8.5\libraries\Wire\src" -I"C:\eclipse_cpp2\arduinoPlugin\packages\arduino\hardware\avr\1.8.5\cores\arduino" -I"C:\eclipse_cpp2\arduinoPlugin\packages\arduino\hardware\avr\1.8.5\variants\standard" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '


