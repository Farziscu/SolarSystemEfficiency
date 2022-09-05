/*
 * SolarPanel.h
 *
 *  Created on: 1 set 2022
 *      Author: franc
 */

#ifndef MYLIBRARY_PHOTORESISTOR_H_
#define MYLIBRARY_PHOTORESISTOR_H_

#include "Arduino.h"

#define NAME_LENGHT				20
#define DEFAULT_PIN_RESISTOR	PIN_A2

class PhotoResistor
{
	protected:
		char name[NAME_LENGHT];
		uint8_t resistorInputPin;


	public:
    	inline 	PhotoResistor( void ) { resistorInputPin = DEFAULT_PIN_RESISTOR; };
    			PhotoResistor( uint8_t pinInput);

    	inline 	void begin( char *pName) { strcpy(name, pName); };
    			void ShowData( void );

    	inline 	int read() { return analogRead(resistorInputPin); }

};


#endif /* MYLIBRARY_PHOTORESISTOR_H_ */
