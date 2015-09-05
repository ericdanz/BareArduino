#include "AccelStepper.h"
#include "Durometer.h"

void setup() {
  // Serial.begin(115200);

  // stepper1.setMaxSpeed(maxSpeed);

  // stepper1.setSpeed(motorSpeed);

  // stepper1.setAcceleration(motorAccel);

  // //Set the initial movement up until the E Stop
  // stepper1.moveTo(4000);
  // stepper1.runToPosition();
  // stepper1.moveTo(goalPos*-2);
	
  // pinMode(upButtonPin, INPUT);
  // pinMode(DownButtonPin, INPUT);
  // pinMode(eStopPinTop, INPUT);
  // pinMode(eStopPinBottom, INPUT);
  pinMode(ledPin, OUTPUT);

  // attachInterrupt(0,moveStopTop,RISING);
  // attachInterrupt(1,moveStopBottom,RISING);
  
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
  //poll buttons
	
  // if (digitalRead(DownButtonPin) == HIGH && (millis() - lastPress > debounceTime))
  //   {
  //     lastPress = millis();
  //     stepper1.moveTo(goalPos);
  //     if(PRINT_SERIAL)
  // 	{
  // 	  Serial.print("Goal: ");
  // 	  Serial.print(goalPos);
  // 	  Serial.println(" DOWN");
  // 	}
  //   }
  // if (digitalRead(upButtonPin) == HIGH && (millis() - lastPress > debounceTime))
  //   {
  //     lastPress = millis();
  //     stepper1.moveTo(0);
  //     if(PRINT_SERIAL)
  // 	Serial.println("UP");
  //   }  

  //stepper1.run();
}
 



