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

void SolarPanel::ShowData( void )
{
	Serial.println();
	Serial.print("Oggetto : "); Serial.println(name);
	Serial.print("InputPanel : "); Serial.println(panelInputPin);
};


