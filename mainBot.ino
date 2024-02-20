#include "MotorControl.h"
#include "IRControl.h"
#include <NewPing.h>


// DEFINE CONSTANTS
#define TRIGGER_PIN A3 // 19
#define ECHO_PIN A2 // 18
#define MAX_DISTANT 200 // Can change to 200cm
// #define DISTANCE_THRESHOLD 30

#define FRONT_LEFT_IR_SENSOR_PIN A0
#define FRONT_RIGHT_IR_SENSOR_PIN A1
#define REAR_BACK_IR_SENSOR_PIN 5



#define BACK_LEFT_WHEEL_PIN 3
#define BACK_RIGHT_WHEEL_PIN 4

#define FRONT_LEFT_WHEEL_PIN 1
#define FRONT_RIGHT_WHEEL_PIN 2



// Initialize Objects
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANT); 
// motorwheel(frontLeft, frontRight, backLeft, frontRight);
MotorControl motorWheel(FRONT_LEFT_WHEEL_PIN, FRONT_RIGHT_WHEEL_PIN,  BACK_LEFT_WHEEL_PIN, BACK_RIGHT_WHEEL_PIN); // Left Motor Pin 4, Right Motor Pin 3
IRControl irSensors(FRONT_LEFT_IR_SENSOR_PIN, FRONT_RIGHT_IR_SENSOR_PIN, REAR_BACK_IR_SENSOR_PIN, motorWheel);



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(FRONT_LEFT_IR_SENSOR_PIN, INPUT);
  pinMode(FRONT_RIGHT_IR_SENSOR_PIN, INPUT);
  delay(5000);

}

void loop() {
  // put your main code here, to run repeatedly:

  // int upperLeftIR = digitalRead(FRONT_LEFT_IR_SENSOR_PIN);
  // int upperRightIR = digitalRead(FRONT_RIGHT_IR_SENSOR_PIN);
  // int lowerBackIR = digitalRead(REAR_BACK_IR_SENSOR_PIN);
  irSensors.readSensors();
  
  int distance = sonar.ping_cm();

  // checkEdge(upperLeftIR, upperRightIR, distance);
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  //delay(1000);
  irSensors.makeDecisions(distance);

  // Serial.print(upperLeftIR);
  // Serial.print(" | ");
  // Serial.println(upperRightIR);
  // irSensors.makeDecisions(distance);

  // if (upperLeftIR == IR_HIGH && upperRightIR == IR_HIGH) {
  //   if (distance < DISTANCE_THRESHOLD) {
  //     motorWheel.charge();
  //   } else {
  //     motorWheel.goForward();
  //   }
  // } else if (upperRightIR == IR_LOW && upperLeftIR == IR_LOW) {
  //   motorWheel.goBackward();
  // } else if (upperRightIR == IR_HIGH && upperLeftIR == IR_LOW) {
  //   motorWheel.turnLeft();
  // } else if (upperRightIR == IR_LOW && upperLeftIR == IR_HIGH) {
  //   motorWheel.turnRight();
  // } else {
  //   motorWheel.stop();
  // }
}
