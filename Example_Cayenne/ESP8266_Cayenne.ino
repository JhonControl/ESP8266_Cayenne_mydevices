// This example shows how to connect to Cayenne using an ESP8266 and send/receive sample data.
// Make sure you install the ESP8266 Board Package via the Arduino IDE Board Manager and select the correct ESP8266 board before compiling. 


/**
*    Test Cayenne Mydevices - PDAControl
*    
*    More information about projects PDAControl   
*    PDAControl English     http://pdacontrolen.com   
*    
*    Mas informacion sobre proyectos PDAControl
*    PDAControl Espanol     http://pdacontroles.com
*    
*    Channel  Youtube       https://www.youtube.com/c/JhonValenciaPDAcontrol/videos   
*
*/
//#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial
#include <CayenneMQTTESP8266.h>
#include <ESP8266WiFi.h>

// WiFi network info.
char ssid[] = "**********";
char wifiPassword[] = "***************";

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "*****************************************";
char password[] = "******************************************";
char clientID[] = "******************************************";

unsigned long lastMillis = 0;

void setup() {
   pinMode(4, OUTPUT);
	Serial.begin(115200);
	Cayenne.begin(username, password, clientID, ssid, wifiPassword);
}

void loop() {
	Cayenne.loop();

  /// ADC0 - CHANNEL 0  
  Cayenne.virtualWrite(0, analogRead(A0));
  // Cayenne.virtualWrite(1, 0  );
  
  /// ADC0 - CHANNEL 2  
  Cayenne.virtualWrite(2, analogRead(A0));
  delay(500);

	
}


//Default function for processing actuator commands from the Cayenne Dashboard.
//You can also use functions for specific channels, e.g CAYENNE_IN(1) for channel 1 commands.

///  WRITE state LED  - Escribe estado LED  

CAYENNE_IN_DEFAULT()
{
	CAYENNE_LOG("CAYENNE_IN_DEFAULT(%u) - %s, %s", request.channel, getValue.getId(), getValue.asString());
	//Process message here. If there is an error set an error message using getValue.setError(), e.g getValue.setError("Error message");

   int i = getValue.asInt();
   digitalWrite(4, i);
 
}

