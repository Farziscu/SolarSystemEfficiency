/*
 * SolarPanel.h
 *
 *  Created on: 1 set 2022
 *      Author: franc
 */

#ifndef MYLIBRARY_SOLARPANEL_H_
#define MYLIBRARY_SOLARPANEL_H_

#include "Arduino.h"

#define NAME_LENGHT			20
#define DEFAULT_PIN_PANEL	PIN_A0
#define MAX_VOLTAGE_VALUE	5.07


class SolarPanel
{
	protected:
		char name[NAME_LENGHT];
		uint8_t panelInputPin;


	public:
    	inline 	SolarPanel( void ) { panelInputPin = DEFAULT_PIN_PANEL; };
    			SolarPanel( uint8_t pinInput);

    	inline 	void begin( char *pName) { strcpy(name, pName); };
    			void ShowData( void );

    	inline 	float read() { return (analogRead(panelInputPin) * MAX_VOLTAGE_VALUE / 1023.0); }

};


#endif /* MYLIBRARY_SOLARPANEL_H_ */
