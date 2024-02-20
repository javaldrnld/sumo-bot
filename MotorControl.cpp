#include <AFMotor.h>
#include "MotorControl.h"
#include <time.h>    // for time()
#include <stdlib.h>  // for rand() and srand()
#include <stdio.h>
#include <Arduino.h>

// Constant Speed
const int SPEED = 200;
unsigned long prevMillis = 0;
const long interval = 1000; // Can change

MotorControl::MotorControl(int frontLeftWheelPin, int backLeftWheelPin, int frontRightWheelPin, int backRightWheelPin) 
    : frontLeftWheel(frontLeftWheelPin), backLeftWheel(backLeftWheelPin), frontRightWheel(frontRightWheelPin), backRightWheel(backRightWheelPin){
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
    frontRightWheel.run(FORWARD); // Back right wheel umaandar
    frontLeftWheel.run(FORWARD); // Goods
    backLeftWheel.run(FORWARD); // Goods
    backRightWheel.run(FORWARD); // front right  umaandar
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
    frontLeftWheel.setSpeed(250);
    frontRightWheel.setSpeed(250/2);
    backLeftWheel.setSpeed(250);
    backRightWheel.setSpeed(250/2);
    
    frontRightWheel.run(BACKWARD); // Back Right Wheel
    frontLeftWheel.run(FORWARD);
    backLeftWheel.run(FORWARD);
    backRightWheel.run(BACKWARD); // Front Right 
}

void MotorControl::turnLeft() {
    // setAllWheelsSpeed(SPEED);
    frontLeftWheel.setSpeed(250/2); 
    frontRightWheel.setSpeed(250); // -> Back right
    backLeftWheel.setSpeed(250/2);
    backRightWheel.setSpeed(250); // front right  umaandar 

    frontRightWheel.run(FORWARD); // Back Rright
    frontLeftWheel.run(BACKWARD);
    backLeftWheel.run(BACKWARD);
    backRightWheel.run(FORWARD); // front right  umaandar
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
    // this->goForward();
    setAllWheelsSpeed(250);

    frontRightWheel.run(FORWARD); // Back right wheel umaandar
    frontLeftWheel.run(FORWARD); // Goods
    backLeftWheel.run(FORWARD); // Goods
    backRightWheel.run(FORWARD); // front right  umaandar
}

void MotorControl::stop() {
    frontLeftWheel.run(RELEASE);
    frontRightWheel.run(RELEASE);
    backLeftWheel.run(RELEASE);
    backRightWheel.run(RELEASE);
}

int MotorControl::search() {
    unsigned long currentMillis = millis();
    static int i = 0;
    // Generate random number 0 or 1
    int random = rand() % 2;
    // If random is 0, turn clockwise
    if (random == 0) {
      // Non-blocking
      if (currentMillis - prevMillis >= interval) {
        prevMillis = currentMillis;

        if (i < 5) {
          this->turnRight();
          i++;
        }
      }

    } else {
        // If random is 1, turn counter clockwise
        // Nonblocking
        if (currentMillis - prevMillis >= interval) {
          prevMillis = currentMillis;

          if (i < 5) {
            this->turnLeft();
            i++;
          }
        
        }



    }
}