#include <Arduino.h>
#include "AutoDriver.h"

// Test sketch for the L6470 AutoDriver library. This program instantiates three
//  AutoDriver boards and uses them to play Jonathon Coulton's "Want You Gone" from
//  the Portal 2 soundtrack. In a more general sense, it adds support for playing
//  music with stepper motors. Not all notes can be played, of course- at too high
//  a steps/sec rate, the motors will slip and dogs and cats will live together.

// Create our AutoDriver instances. The parameters are pin numbers in
//  Arduino-speke for CS and reset.
AutoDriver boardA(10, 6);

// Support functions.

                        // My cheesy way of reducing the note frequencies to a range
                        //  that doesn't cause the motor to slip. I *could* rewrite
                        //  the wantYouGone() function to change the notes, but that
                        //  would be a lot of work.

int stepDir = 1;        // Direction flipping bit. Rather than all going one way,
                        //  they change directions. It looks cooler.

// This is the configuration function for the two dSPIN parts. Read the inline
//  comments for more info.
void dSPINConfig(void)
{
  //boardA.configSyncPin(BUSY_PIN, 0);// BUSY pin low during operations;
                                    //  second paramter ignored.
  boardA.configStepMode(STEP_FS);   // 0 microsteps per step
  boardA.setMaxSpeed(9600);        // 10000 steps/s max
  boardA.setFullSpeed(9600);       // microstep below 10000 steps/s
  boardA.setAcc(10000);             // accelerate at 10000 steps/s/s
  boardA.setDec(10000);
  boardA.setSlewRate(SR_530V_us);   // Upping the edge speed increases torque.
  boardA.setOCThreshold(OC_750mA);  // OC threshold 750mA
  boardA.setPWMFreq(PWM_DIV_2, PWM_MUL_2); // 31.25kHz PWM freq
  boardA.setOCShutdown(OC_SD_DISABLE); // don't shutdown on OC
  boardA.setVoltageComp(VS_COMP_DISABLE); // don't compensate for motor V
  boardA.setSwitchMode(SW_USER);    // Switch is not hard stop
  boardA.setOscMode(INT_16MHZ_OSCOUT_16MHZ); // for boardA, we want 16MHz
                                    //  internal osc, 16MHz out. boardB and
                                    //  boardC will be the same in all respects
                                    //  but this, as they will bring in and
                                    //  output the clock to keep them
                                    //  all in phase.
  boardA.setAccKVAL(255);           // We'll tinker with these later, if needed.
  boardA.setDecKVAL(255);
  boardA.setRunKVAL(255);
  boardA.setHoldKVAL(32);           // This controls the holding current; keep it low.
}




void setup()
{
  Serial.begin(115200);
  Serial.println("Hello world");
  dSPINConfig();
  
}

// loop()
void loop()
{
	Serial.println(boardA.getPos());
	boardA.run(FWD,9600);
	delay(1000);
  

  /*
  if (Serial.available() !=0)
  {
    Serial.read();
    Serial.println("Switch Dirs!");
	if (stepDir)
		boardA.goToDir(FWD,32000);
	else
		boardA.goToDir(REV,32000);
	stepDir *= -1;
  } */
}


