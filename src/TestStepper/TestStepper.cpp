#include <Arduino.h>

int stepPin = 5;
int dirPin = 6;


long testPos = 10000;

void setup() {
	Serial.begin(115200);
	
	pinMode(stepPin,OUTPUT);
	pinMode(dirPin,OUTPUT);
	digitalWrite(stepPin,LOW);
	digitalWrite(dirPin,LOW);
}

void loop() {
	digitalWrite(stepPin, HIGH);
	delay(1);          
	digitalWrite(stepPin, LOW); 
	delay(1);  
}




