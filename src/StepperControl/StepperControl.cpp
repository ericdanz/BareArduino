#include <Arduino.h>
#include "AccelStepper.h"

int maxSpeed = 3200; //about 2 rps
int motorSpeed = 1000;
int motorAccel = 10000; //steps / second / second to accelerate
long stepperGoal = 32000;

int motor1DirPin = 6;
int motor1StepPin = 5;

long lastpress = millis();
int debounceTime = 1000;

AccelStepper stepper1(1,motor1StepPin, motor1DirPin);

int upButtonPin = 10;
int downButtonPin = 11;

int eStopPin = 2;

//void moveUp(){
//	//software debouncing
//	if (millis()-lastpress > debounceTime)
//	{
//	lastpress = millis();
//	stepperGoal = 32000;
//	stepper1.moveTo(stepperGoal);
//	stepper1.setSpeed(motorSpeed);
//	Serial.println("moveup");
//	}
//}

//void moveDown(){
//	if (millis()-lastpress > debounceTime)
//	{
//	lastpress = millis();
//	stepperGoal = -32000;
//	stepper1.moveTo(stepperGoal);
//	stepper1.setSpeed(motorSpeed);
//	Serial.println("movedown");
//	}
//}

//void moveSTOP(){
//	stepper1.setSpeed(0);
//}

void setup() {
	Serial.begin(115200);

	stepper1.setMaxSpeed(maxSpeed);

	stepper1.setSpeed(motorSpeed);

	stepper1.setAcceleration(motorAccel);

	stepper1.moveTo(32000);
	//delay(2000);

	pinMode(upButtonPin, INPUT);
	pinMode(downButtonPin, INPUT);

	//attachInterrupt(0,moveUp,RISING);

	//attachInterrupt(1,moveDown,RISING);


	Serial.println("startup");
}

void loop() {
	//Serial.println(stepper1.);
	//these must be called as often as possible to ensure smooth operation
	//any delay will cause jerky motion
	stepper1.runToPosition();
}


//	buttonState = digitalRead(buttonPin);

//	if (buttonState == HIGH) {     
//		// turn LED on:    
//		stepper1.moveTo(32000);  
//	  } 
//	  else {
//		// turn LED off:
//		stepper1.moveTo(-32000);
//	  }
	//Serial.println(stepper1.distanceToGo());
	//if stepper1 is at desired location
//	if (stepper1.distanceToGo() == 0){
//		Serial.println(stepper1.currentPosition());
//	//go the other way the same amount of steps
//	//so if current position is 400 steps out, go position -400
//		stepper1.moveTo(-stepper1.currentPosition()); 
//	}



