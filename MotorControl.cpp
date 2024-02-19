#include "MotorControl.h"
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()

MotorControl::MotorControl(int frontLeftWheelPin, int frontRightWheelPin, int backLeftWheelPin, int backRightWheelPin) 
    : frontLeftWheel(frontLeftWheelPin), frontRightWheel(frontRightWheelPin), backLeftWheel(backLeftWheelPin), backRightWheel(backRightWheelPin),{
    frontLeftWheel.run(RELEASE);
    frontRightWheel.run(RELEASE);
    backLeftWheel.run(RELEASE);
    backRightWheel.run(RELEASE);
}

void MotorControl::goForward() {
    frontLeftWheel.setSpeed(200);
    frontRightWheel.setSpeed(200);
    backLeftWheel.setSpeed(200);
    backRightWheel.setSpeed(200);

    frontRightWheel.run(FORWARD);
    frontLeftWheel.run(FORWARD);
    backLeftWheel.run(FORWARD);
    backRightWheel.run(FORWARD);
}

void MotorControl::goBackward() {
    frontLeftWheel.setSpeed(200);
    frontRightWheel.setSpeed(200);
    backLeftWheel.setSpeed(200);
    backRightWheel.setSpeed(200);
    
    frontRightWheel.run(BACKWARD);
    frontLeftWheel.run(BACKWARD);
    backLeftWheel.run(BACKWARD);
    backRightWheel.run(BACKWARD);
}

// need to trial and error
void MotorControl::turnRight() {
    frontLeftWheel.setSpeed(200);
    frontRightWheel.setSpeed(200);
    backLeftWheel.setSpeed(200);
    backRightWheel.setSpeed(200);
    
    frontRightWheel.run(FORWARD);
    frontLeftWheel.run(BACKWARD);
    backLeftWheel.run(FORWARD);
    backRightWheel.run(BACKWARD);
}

void MotorControl::turnLeft() {
    frontLeftWheel.setSpeed(200);
    frontRightWheel.setSpeed(200);
    backLeftWheel.setSpeed(200);
    backRightWheel.setSpeed(200);
    
    frontRightWheel.run(BACKWARD);
    frontLeftWheel.run(FORWARD);
    backLeftWheel.run(BACKWARD);
    backRightWheel.run(FORWARD);
}

void motorControl::rotate() {
    frontLeftWheel.setSpeed(200);
    frontRightWheel.setSpeed(200);
    backLeftWheel.setSpeed(200);
    backRightWheel.setSpeed(200);
    
    frontRightWheel.run(BACKWARD);
    frontLeftWheel.run(FORWARD);
    backLeftWheel.run(FORWARD);
    backRightWheel.run(BACKWARD);
}

void MotorControl::charge() {
    // What does this-> do? -> It is a pointer to the object itself
    // So I don't need MotorControl::goForward()? -> Yes, you don't need it
    this->goForward();
}

void MotorControl::stop() {
    frontLeftWheel.run(RELEASE);
    frontRightWheel.run(RELEASE);
    backLeftWheel.run(RELEASE);
    backRightWheel.run(RELEASE);
}

void MotorControl::search() {
    // Initalize random seed
    srand(time(0))

    // Generate random number 0 or 1
    int random = rand() % 2;

    // If random is 0, turn clockwise
    if (random == 0) {
        frontLeftWheel.setSpeed(200);
        frontRightWheel.setSpeed(200);
        backLeftWheel.setSpeed(200);
        backRightWheel.setSpeed(200);
        
        frontRightWheel.run(BACKWARD);
        frontLeftWheel.run(FORWARD);
        backLeftWheel.run(FORWARD);
        backRightWheel.run(BACKWARD);
    } else {
        // If random is 1, turn counter clockwise
        frontLeftWheel.setSpeed(200);
        frontRightWheel.setSpeed(200);
        backLeftWheel.setSpeed(200);
        backRightWheel.setSpeed(200);
        
        frontRightWheel.run(FORWARD);
        frontLeftWheel.run(BACKWARD);
        backLeftWheel.run(BACKWARD);
        backRightWheel.run(FORWARD);
    }
}