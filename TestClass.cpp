
#include "TestClass.h"

// Do not remove the include below
#include <SPI.h>
#include <SD.h>
#include <MemoryUsage.h>
#include "RTClib.h"

#include "HardwareConfiguration.h"
#include "MyLibrary/SolarPanel.h"
#include "MyLibrary/PhotoResistor.h"

#define FREQ_READ 		4000
#define MAX_DATA_STORE	10
#define STRING_LENGTH	43
#define MEM_GUARD		180
#define SD_CHIP_SELECT 	10		//SD Card

SolarPanel 	  cell1(PIN_PANEL_1);
SolarPanel 	  cell2(PIN_PANEL_2);
PhotoResistor PR1(PIN_LIGHT_RESISTOR_1);
PhotoResistor PR2(PIN_LIGHT_RESISTOR_2);

File 		myFile;
RTC_DS1307  rtc;
char 		TimeBuffer[30] = "";   //Full date and time stamp

//The setup function is called once at startup of the sketch
void setup()
{
	int count = 0;
	cell1.begin("Pannello 1");
	cell2.begin("Pannello 2");

	Serial.begin(9600);

	if (! rtc.begin()) {
		Serial.println("Couldn't find RTC");
		count = 0;
		while ( count++ < 1000 );
	}
	else
		Serial.println("RTC begin is OK!");


	if (! rtc.isrunning()) {
		Serial.println("RTC is NOT running!");
	    // Set the date and time at compile time
	    //rtc.adjust(DateTime(__DATE__, __TIME__));
		rtc.adjust(DateTime(__DATE__, "11:58:00"));
	}
	else
		Serial.println("RTC is not running!");


	Serial.print("Initializing SD card...");
	if (!SD.begin(SD_CHIP_SELECT)) {
	  Serial.println("Initialization failed!");
	  count = 0;
	  while (count++ < 1000);
	}
	else
	  Serial.println("Initialization done.");
}

// The loop function is called in an endless loop
void loop()
{
	String 	 fileName 	= "";
	String 	 *dataToSD  = new String();
	VALUE_T  data;
	int		 CountDepth = 0;

	while (1) {
		Clock();
		CreateFilename(&fileName); //Serial.println(fileName);

		data.panel1 = cell1.read();
		data.panel2 = cell2.read();
		data.photoResistor1 = PR1.read();
		data.photoResistor2 = PR2.read();

		//showValues(data);

		setStringToSave(dataToSD, &data);  //Serial.println(dataToSD);

		Serial.print("freeeee : "); Serial.println(String(mu_freeRam()));

		CountDepth++;	Serial.println(CountDepth);
		if (CountDepth >= MAX_DATA_STORE ||
			( mu_freeRam() - STRING_LENGTH) <= MEM_GUARD )
		{
			// open a new file and immediately close it:
			Serial.print("Opening ");
			Serial.print(fileName); Serial.println("...");

			myFile = SD.open(fileName, FILE_WRITE);

			if (myFile)
			{
				dataToSD->operator [](dataToSD->length()-1) = '\0';
				myFile.println(*dataToSD);
				myFile.close();
				Serial.println(*dataToSD);
			}
			else
			{
				Serial.print("error " + String(myFile) + " opening ");
				Serial.println(fileName);
			}

			CountDepth = 0;

			delete dataToSD;
			dataToSD = new String();
		}
		delay(FREQ_READ);
	}
}

void Clock()
{
     DateTime now = rtc.now(); //Read the current date-time from the RTC
     sprintf(TimeBuffer, "%04d-%02d-%02d; %02d:%02d:%02d", now.year(), now.month(), now.day(), now.hour(), now.minute(), now.second());
}

void CreateFilename(String *fileName) //, DateTime now)
{
	DateTime now 	   = rtc.now();
	static uint8_t day = 100;
	char   date[20]    = "";

	Serial.println("hour = " + String(now.hour())   +  " day == " + String(day));
	if ( day != now.hour()) // now.day())
	{
		// cambiare sprintf(date, "%04d%02d%02d", now.year(), now.month(), now.day());
		sprintf(date, "22%02d%02d%02d", now.month(), now.day(), now.hour());

		*fileName = String(date);
		*fileName += ".csv";

		day = now.hour();
		//Serial.println("Cambio Nome:  ");
	}
}

void setStringToSave(String *dataToSave, const VALUE_T *data)
{
	*dataToSave += String(TimeBuffer);				*dataToSave +=  "; ";
	*dataToSave += String(data->panel1, 2); 		*dataToSave +=  "; ";
	*dataToSave += String(data->photoResistor1);	*dataToSave +=  "; ";

	*dataToSave += String(data->panel2, 2); 		*dataToSave +=  "; ";
	*dataToSave += String(data->photoResistor2);	*dataToSave +=  "\n";
}

void showValues(VALUE_T data)
{
	Serial.println();
	Serial.println("cell1 : ");
	Serial.print("  cell  : ");	Serial.println( data.panel1, 3);
	Serial.print("  light : "); Serial.println( data.photoResistor1);

	Serial.println("cell2 : ");
	Serial.print("  cell  : ");	Serial.println( data.panel2, 3);
	Serial.print("  light : "); Serial.println( data.photoResistor2);
}
