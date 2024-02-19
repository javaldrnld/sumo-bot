#include "MotorControl.h"
// #include "IRControl.h"
#include <NewPing.h>


// DEFINE CONSTANTS
#define TRIGGER_PIN 12 // 19
#define ECHO_PIN 11 // 18
#define MAX_DISTANT 200 // Can change to 200cm

#define IR_SENSOR_UPPER_LEFT_PIN
#define IR_SENSOR_UPPER_RIGHT_PIN
#define IR_SENSOR_LOWER_LEFT_PIN
#define IR_SENSOR_LOWER_RIGHT_PIN

// Global Variable ->?


// Initialize Objects
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANT); 
// motorwheel(frontLeft, frontRight, backLeft, backRight);
MotorControl motorWheel(4, 3); // Left Motor Pin 4, Right Motor Pin 3



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:

  // int upperLeftIR = digitalRead(IR_SENSOR_UPPER_LEFT_PIN);
  // int upperRightIR = digitalRead(IR_SENSOR_UPPER_RIGHT_PIN);
  // int lowerLeftIR = digitalRead(IR_SENSOR_LOWER_LEFT_PIN);
  // int lowerRightIR = digitalRead(IR_SENSOR_LOWER_RIGHT_PIN);
  Serial.
  int distance = sonar.ping_cm();

  // checkEdge(upperLeftIR, upperRightIR, distance);
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(1000);


}
