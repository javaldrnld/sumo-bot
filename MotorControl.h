#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <AFMotor.h>

class MotorControl {
public:
  MotorControl(int leftMotorNum, int rightMotorNum);
  void goForward();
  void turnRight();
  void turnLeft();
  void goBackward();
  void charge();
  void stop();
  void search();

private:
  AF_DCMotor leftMotor;
  AF_DCMotor rightMotor;
};

#endif // MOTOR_CONTROL_H
