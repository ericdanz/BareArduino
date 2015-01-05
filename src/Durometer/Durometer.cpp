#include "AccelStepper.h"
#include "Durometer.h"

void setup() {
	Serial.begin(115200);

	stepper1.setMaxSpeed(maxSpeed);

	stepper1.setSpeed(motorSpeed);

	stepper1.setAcceleration(motorAccel);

	//Set the initial movement up until the E Stop
	stepper1.moveTo(goalPos*-2);
	
	pinMode(upButtonPin, INPUT);
	pinMode(DownButtonPin, INPUT);
	pinMode(eStopPin, INPUT);

	attachInterrupt(0,moveSTOP,RISING);

	Serial.println("Started");
}

void loop() {
	
	if (digitalRead(DownButtonPin) == HIGH && (millis() - lastPress > debounceTime))
	{
		lastPress = millis();
		stepper1.moveTo(goalPos);
		if(PRINT_SERIAL)
			Serial.println("DOWN");
	}
	if (digitalRead(upButtonPin) == HIGH && (millis() - lastPress > debounceTime))
	{
		lastPress = millis();
		stepper1.moveTo(0);
		if(PRINT_SERIAL)
			Serial.println("UP");
	}  
	stepper1.run();
	//Serial.println(stepper1.currentPosition());
}




