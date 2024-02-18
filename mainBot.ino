#include "MotorControl.h"
#include <NewPing.h>

// DEFINE CONSTANTS
#define TRIGGER_PIN 19
#define ECHO_PIN 18

// Initialize Objects
NewPing sonar(12, 11, 200); //
MotorControl motorWheel(4, 3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  motorWheel.goForward();

}
