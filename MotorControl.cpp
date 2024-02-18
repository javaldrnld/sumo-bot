#include "MotorControl.h"

MotorControl::MotorControl(int leftMotorNum, int rightMotorNum) 
    : leftMotor(leftMotorNum), rightMotor(rightMotorNum) {
    leftMotor.run(RELEASE);
    rightMotor.run(RELEASE);
}

void MotorControl::goForward() {
    leftMotor.setSpeed(200);
    leftMotor.run(FORWARD);
    rightMotor.setSpeed(200);
    rightMotor.run(FORWARD);
}
void MotorControl::goBackward() {
    leftMotor.setSpeed(200);
    leftMotor.run(BACKWARD);
    rightMotor.setSpeed(200);
    rightMotor.run(BACKWARD);
}

void MotorControl::turnRight() {
    leftMotor.setSpeed(200);
    leftMotor.run(FORWARD);
    rightMotor.setSpeed(200);
    rightMotor.run(BACKWARD);
}

void MotorControl::turnLeft() {
    leftMotor.setSpeed(200);
    leftMotor.run(BACKWARD);
    rightMotor.setSpeed(200);
    rightMotor.run(FORWARD);
}

void MotorControl::charge() {
    leftMotor.setSpeed(255);
    leftMotor.run(FORWARD);
    rightMotor.setSpeed(255);
    rightMotor.run(FORWARD);
}

void MotorControl::stop() {
    leftMotor.run(RELEASE);
    rightMotor.run(RELEASE);
}

void MotorControl::search(int) {

}