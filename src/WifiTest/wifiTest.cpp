#include <Arduino.h>
#include <SPI.h>
#include "WiFi.h"

char ssid[] = "odd"; 
int status = WL_IDLE_STATUS;
IPAddress server(192,168,43,188);
WiFiClient client;

void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}





void setup() {

	Serial.begin(115200);
	delay(1000);
	if (WiFi.status() == WL_NO_SHIELD) {
		Serial.println("WiFi shield not present");
		// don't continue:
		while (true);
	  }

	  String fv = WiFi.firmwareVersion();
	  if ( fv != "1.1.0" )
		Serial.println("Please upgrade the firmware");

	  // attempt to connect to Wifi network:
	  while (status != WL_CONNECTED) {
		Serial.print("Attempting to connect to SSID: ");
		Serial.println(ssid);
		// Connect to WPA/WPA2 network. Change this line if using open or WEP network:
		//status = WiFi.begin(ssid, keyIndex, key);
		 status = WiFi.begin(ssid);
		 // wait 10 seconds for connection:
		delay(10000);
	  }
	Serial.println("Connected to wifi");
  	printWifiStatus();

}

void loop() {
  // if there are incoming bytes available
  // from the server, read them and print them:
  if (!client.connected())
  {
    Serial.println("disconnected from server");
    client.flush();
    client.stop();
    delay(1000);
    if (client.connect(server, 5000)) {
      Serial.println("connected to server");
      delay(100);
    }
  }
  else
  {
    client.print("stuff");
   Serial.println("Checking for incoming data");
    client.print("stuff");
   while (client.available()) {
    Serial.println("Reading Data ");
    byte b = client.read();
    Serial.write(b);
    char c = b;
    Serial.print(" char: ");
    Serial.println(c);
    
  } 
    client.flush();
    client.stop();
  }

  delay(1000);
}



