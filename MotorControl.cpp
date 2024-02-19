#include "MotorControl.h"
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()

// Constant Speed
const int SPEED = 200;

MotorControl::MotorControl(int frontLeftWheelPin, int frontRightWheelPin, int backLeftWheelPin, int backRightWheelPin) 
    : frontLeftWheel(frontLeftWheelPin), frontRightWheel(frontRightWheelPin), backLeftWheel(backLeftWheelPin), backRightWheel(backRightWheelPin){
    frontLeftWheel.run(RELEASE);
    frontRightWheel.run(RELEASE);
    backLeftWheel.run(RELEASE);
    backRightWheel.run(RELEASE);

    // Initalize random seed
    srand(time(0));
}

void MotorControl::setAllWheelsSpeed(int speed) {
    frontLeftWheel.setSpeed(speed);
    frontRightWheel.setSpeed(speed);
    backLeftWheel.setSpeed(speed);
    backRightWheel.setSpeed(speed);
}

void MotorControl::goForward() {
    setAllWheelsSpeed(SPEED);
    frontRightWheel.run(FORWARD);
    frontLeftWheel.run(FORWARD);
    backLeftWheel.run(FORWARD);
    backRightWheel.run(FORWARD);
}

void MotorControl::goBackward() {
    setAllWheelsSpeed(SPEED);
    
    frontRightWheel.run(BACKWARD);
    frontLeftWheel.run(BACKWARD);
    backLeftWheel.run(BACKWARD);
    backRightWheel.run(BACKWARD);
}

// need to trial and error
void MotorControl::turnRight() {
    setAllWheelsSpeed(SPEED);
    
    frontRightWheel.run(FORWARD);
    frontLeftWheel.run(BACKWARD);
    backLeftWheel.run(FORWARD);
    backRightWheel.run(BACKWARD);
}

void MotorControl::turnLeft() {
    setAllWheelsSpeed(SPEED);

    frontRightWheel.run(BACKWARD);
    frontLeftWheel.run(FORWARD);
    backLeftWheel.run(BACKWARD);
    backRightWheel.run(FORWARD);
}

void MotorControl::rotate() {
    setAllWheelsSpeed(SPEED);
    
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
    // Generate random number 0 or 1
    int random = rand() % 2;

    // If random is 0, turn clockwise
    if (random == 0) {
        setAllWheelsSpeed(SPEED);

        frontRightWheel.run(BACKWARD);
        frontLeftWheel.run(FORWARD);
        backLeftWheel.run(FORWARD);
        backRightWheel.run(BACKWARD);
    } else {
        // If random is 1, turn counter clockwise
        setAllWheelsSpeed(SPEED);

        frontRightWheel.run(FORWARD);
        frontLeftWheel.run(BACKWARD);
        backLeftWheel.run(BACKWARD);
        backRightWheel.run(FORWARD);
    }
}