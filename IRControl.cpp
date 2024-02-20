#include "IRControl.h"
#include "MotorControl.h"
#include "Arduino.h"

#define DISTANCE_THRESHOLD 30
#define IR_HIGH 1 // For the meantime black daw
#define IR_LOW 0 // Then white

IRControl::IRControl(int frontLeftIRPin, int frontRightIRPin, int backIRPin, MotorControl& motorControl) 
    : frontLeftIRPin(frontLeftIRPin), frontRightIRPin(frontRightIRPin), backIRPin(backIRPin), motorControl(motorControl) {
    pinMode(frontLeftIRPin, INPUT);
    pinMode(frontRightIRPin, INPUT);
    pinMode(backIRPin, INPUT);
}

// Read Value Sensor 
void IRControl::readSensors() {
    frontLeftIRValue = digitalRead(frontLeftIRPin);
    frontRightIRValue = digitalRead(frontRightIRPin);
    backIRValue = digitalRead(backIRPin);
    printf("Front Left IR: %d | Front Right IR: %d | Back IR: %d\n", frontLeftIRValue, frontRightIRValue, backIRValue);
}

// Make Decisions
void IRControl::makeDecisions(int distance) {
  if (frontLeftIRValue == IR_HIGH && frontRightIRValue == IR_HIGH) {
    if (distance < DISTANCE_THRESHOLD) {
      motorControl.charge();
    } else {
      motorControl.goForward();
    }
  } else if (frontRightIRValue == IR_LOW && frontLeftIRValue == IR_LOW) {
    motorControl.goBackward();
  } else if (frontRightIRValue == IR_HIGH && frontLeftIRValue == IR_LOW) {
    motorControl.turnLeft();
  } else if (frontRightIRValue == IR_LOW && frontLeftIRValue == IR_HIGH) {
    motorControl.turnRight();
  } else {
    motorControl.stop();
  }
}

