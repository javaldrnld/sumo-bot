#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <AFMotor.h>

class MotorControl {
public:
  MotorControl(int frontLeftWheelPin, int backLeftWheelPin, int frontRightWheelPin, int backRightWheelPin);
 
  // Basic Movements
  void goForward();
  void turnRight();
  void turnLeft();
  void goBackward();
  void charge();
  void stop();
  void rotate();
 
  // Basic Operation
  int search();
  void attack();
  void edgePrevention();

private:
  
  // Clean Code
  void setAllWheelsSpeed(int speed);
  
  AF_DCMotor frontLeftWheel;
  AF_DCMotor backLeftWheel;
  AF_DCMotor frontRightWheel;
  AF_DCMotor backRightWheel;
};

#endif // MOTOR_CONTROL_H
