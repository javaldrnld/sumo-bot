#include "IRControl.h"
#include "MotorControl.h"


extern MotorControl motorWheel;

void checkEdge(int leftIRSensor, int rightIRSensor, int distance) {
  if (leftIRSensor == HIGH && rightIRSensor == HIGH) {
    handleBothIRHIGH(sonar.ping_cm());
  } else if (leftIRSensor == LOW && rightIRSensor == LOW) {
    handleBothIRLOW();
  } else if (leftIRSensor == HIGH && rightIRSensor == LOW) {
    handleLeftIRHighRightIRLow();
  } else if (leftIRSensor == LOW && rightIRSensor == HIGH) {
    handleLeftIRLowRightIRHigh();
  }
}

// void handleBothIRHIGH(int distance) {
//   Serial.println(distance);
//   if (distance > 50) {

//     motorWheel.goForward();
//   } else {
//     motorWheel.stop();
//     motorWheel.search();
//   }
// }