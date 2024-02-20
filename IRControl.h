#ifndef IR_CONTROL_H
#define IR_CONTROL_H

#include "MotorControl.h" // Include MotorControl to have access in MotorControl functions
#include <Arduino.h>

class IRControl {
    public:
        IRControl(int frontLeftIRPin, int frontRightIRPin, int backIRPin, MotorControl& motorControl);

        // Function read sensors
        void readSensors();

        // Function to make decision based on readings
        void makeDecisions(int distance);

    private:
        // For Pin
        int frontLeftIRPin;
        int frontRightIRPin;
        int backIRPin;

        // Store Reading Value
        int frontLeftIRValue;
        int frontRightIRValue;
        int backIRValue;
        
        MotorControl& motorControl; // Reference to MotorControl
};

#endif