#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <AFMotor.h>

class MotorControl {
public:
  MotorControl(int frontLeftWheelPin, int frontRightWheelPin, int backLeftWheelPin, int backRightWheelPin);
 
  // Basic Movements
  void goForward();
  void turnRight();
  void turnLeft();
  void goBackward();
  void charge();
  void stop();
  void rotate();
 
  // Basic Operation
  void search();
  void attack();
  void edgePrevention();

private:
  AF_DCMotor frontLeftWheel;
  AF_DCMotor frontRightWheel;
  AF_DCMotor backLeftWheel;
  AF_DCMotor backRightWheel;
};

#endif // MOTOR_CONTROL_H
