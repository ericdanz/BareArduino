#include <Arduino.h>
#include "AccelStepper.h"

int maxSpeed = 9600; //about 2 rps
int motorSpeed = 9600;
int motorAccel = 160000; //steps / second / second to accelerate

int motor1DirPin = 4;
int motor1StepPin = 5;

long lastpress = millis();
int debounceTime = 1000;

AccelStepper stepper1(1,motor1StepPin, motor1DirPin);

int upButtonPin = 21;
int upButtonState = -1;

int downButtonPin = 20;
int downButtonState = -1;

int stepperGoal;

void moveUp(){
	//software debouncing
	if (millis()-lastpress > debounceTime)
	{
	lastpress = millis();
	stepperGoal = 32000;
	stepper1.moveTo(stepperGoal);
	stepper1.setSpeed(motorSpeed);
	Serial.println("moveup");
	}
}

void moveDown(){
	if (millis()-lastpress > debounceTime)
	{
	lastpress = millis();
	stepperGoal = -32000;
	stepper1.moveTo(stepperGoal);
	stepper1.setSpeed(motorSpeed);
	Serial.println("movedown");
	}
}

void moveSTOP(){
	stepper1.setSpeed(0);
}

void setup() {
	Serial.begin(115200);

	stepper1.setMaxSpeed(maxSpeed);

	stepper1.setSpeed(motorSpeed);

	stepper1.setAcceleration(motorAccel);

	stepper1.moveTo(32000);

	pinMode(upButtonPin, OUTPUT);
	pinMode(downButtonPin, OUTPUT);

	attachInterrupt(2,moveUp,RISING);

	attachInterrupt(3,moveDown,RISING);


	Serial.println("startup");
}

void loop() {
	
	//these must be called as often as possible to ensure smooth operation
	//any delay will cause jerky motion
	stepper1.run();
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



