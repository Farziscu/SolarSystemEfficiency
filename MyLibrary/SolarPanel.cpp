/*
 * SolarPanel.cpp
 *
 *  Created on: 1 set 2022
 *      Author: franc
 */


#include "SolarPanel.h"

SolarPanel::SolarPanel( uint8_t pinInput)
{
	if (pinInput >= A0 && pinInput <= A5)
		panelInputPin = pinInput;
	else
		panelInputPin = DEFAULT_PIN_PANEL;
};


float SolarPanel::read( void )
{
	int   voltageValue = analogRead(panelInputPin);
	float ret 		   = 0;

	ret = (voltageValue * 0.005028);

	return ret; //map(voltageValue, 0, 1023, 0, MAX_VOLTAGE_VALUE) ; //(* MAX_VOLTAGE_VALUE / 10230.0);
};


void SolarPanel::ShowData( void )
{
	Serial.println();
	Serial.print("Oggetto : "); Serial.println(name);
	Serial.print("InputPanel : "); Serial.println(panelInputPin);
};


