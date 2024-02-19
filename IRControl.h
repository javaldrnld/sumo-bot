#ifndef IR_CONTROL_H
#define IR_CONTROL_H

void checkEdge(int leftIRSensor, int rightIRSensor, int distance); // Dagdagan nalang kung apat na IR sensor need
void handleBothIRHIGH(int distance);
void handleBothIRLOW();
void handleLeftIRHighRightIRLow();
void handleLeftIRLowRightIRHigh();

#endif