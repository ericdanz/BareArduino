#include <Arduino.h>
#include "AccelStepper.h"

int maxSpeed = 6400; //about 2 rps
int motorSpeed = 3200;
int motorAccel = 160000; //steps / second / second to accelerate

int motor1DirPin = 2;
int motor1StepPin = 3;

AccelStepper stepper1(1,motor1StepPin, motor1DirPin);

int buttonPin = 7;
int buttonState = -1;

void changeGoal(){
	stepper1.moveTo(32000*buttonState);
	buttonState = buttonState*-1;
}

void setup() {
	Serial.begin(115200);

	stepper1.setMaxSpeed(maxSpeed);

	stepper1.setSpeed(motorSpeed);

	stepper1.setAcceleration(motorAccel);

	stepper1.moveTo(32000);

	pinMode(buttonPin, INPUT);

	attachInterrupt(0,changeGoal,CHANGE);
}

void loop() {
	buttonState = digitalRead(buttonPin);

	if (buttonState == HIGH) {     
		// turn LED on:    
		stepper1.moveTo(32000);  
	  } 
	  else {
		// turn LED off:
		stepper1.moveTo(-32000);
	  }
	//Serial.println(stepper1.distanceToGo());
	//if stepper1 is at desired location
//	if (stepper1.distanceToGo() == 0){
//		Serial.println(stepper1.currentPosition());
//	//go the other way the same amount of steps
//	//so if current position is 400 steps out, go position -400
//		stepper1.moveTo(-stepper1.currentPosition()); 
//	}
	//these must be called as often as possible to ensure smooth operation
	//any delay will cause jerky motion
	stepper1.run();
}



