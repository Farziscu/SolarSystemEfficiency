// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef _TestLibrary_H_
#define _TestLibrary_H_
#include "Arduino.h"
//add your includes for the project TestLibrary here

#include "RTClib.h"

//end of add your includes here


//add your function definitions for the project TestLibrary here

typedef struct {
	float panel1;
	float panel2;
	int photoResistor1;
	int photoResistor2;
} VALUE_T;


void Clock();
void CreateFilename(String *fileName); //, DateTime now);
void setStringToSave(String *dataToSave, const VALUE_T *data);
void showValues(VALUE_T data);



//Do not add code below this line
#endif /* _TestLibrary_H_ */
