/*
 * SolarPanel.cpp
 *
 *  Created on: 1 set 2022
 *      Author: franc
 */


#include "PhotoResistor.h"

PhotoResistor::PhotoResistor( uint8_t pinInput)
{
	if (pinInput >= A0 && pinInput <= A5)
		resistorInputPin = pinInput;
	else
		resistorInputPin = DEFAULT_PIN_RESISTOR;
};

void PhotoResistor::ShowData( void )
{
	Serial.println();
	Serial.print("Oggetto : "); Serial.println(name);
	Serial.print("InputPanel : "); Serial.println(resistorInputPin);
};


