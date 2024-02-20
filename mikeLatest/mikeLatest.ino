#include <AFMotor.h>

AF_DCMotor leftWheel(4);
AF_DCMotor leftWheel2(3);
AF_DCMotor rightWheel(2);
AF_DCMotor rightWheel2(1);

int leftIR = 0;
int rightIR = 0;
int button = 0;

int trigPin = A3;
int echoPin = A2;
long duration = 0;
int distance = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(17, INPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  leftWheel.run(RELEASE); //.run(direction)
  rightWheel.run(RELEASE); //RELEASE, FORWARD, BACKWARD ; RELEASE = stop
  delay(5000);

}

void loop() {



  int leftIR = digitalRead(A0);
  int rightIR = digitalRead(A1);

  int distance = proximity();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  Serial.print(leftIR);
  Serial.print(" | ");
  Serial.println(rightIR);
  
 if ((rightIR == 1 && leftIR == 1)) {
  if (distance < 30){
    charge();
  }
  else{
    goForward();
  }

}

else if ((rightIR == 0 && leftIR == 0)) {
 goBackward();
}


else if ((rightIR == 1 && leftIR == 0)){
 turnLeft();
}


else if ((rightIR == 0 && leftIR == 1)){
 turnRight();
}
else {
   leftWheel.setSpeed(200);
  leftWheel.run(RELEASE);
  rightWheel.setSpeed(200);
  rightWheel.run(RELEASE);
  leftWheel2.setSpeed(200);
  leftWheel2.run(RELEASE);
  rightWheel2.setSpeed(200);
  rightWheel2.run(RELEASE);

}
 

}

int proximity()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2)/29.1;
  return distance;
}




//Basic Movement

void goForward()
{
  leftWheel.setSpeed(200);
  leftWheel.run(FORWARD);
  rightWheel.setSpeed(200);
  rightWheel.run(FORWARD);
  leftWheel2.setSpeed(200);
  leftWheel2.run(FORWARD);
  rightWheel2.setSpeed(200);
  rightWheel2.run(FORWARD);
}


void turnRight()
{
  leftWheel.setSpeed(200);
  leftWheel.run(FORWARD);
  rightWheel.setSpeed(200);
  rightWheel.run(BACKWARD);
  leftWheel2.setSpeed(200);
  leftWheel2.run(FORWARD);
  rightWheel2.setSpeed(200);
  rightWheel2.run(BACKWARD);
}

void turnLeft()
{
  leftWheel.setSpeed(200);
  leftWheel.run(BACKWARD);
  rightWheel.setSpeed(200);
  rightWheel.run(FORWARD);
  leftWheel2.setSpeed(200);
  leftWheel2.run(BACKWARD);
  rightWheel2.setSpeed(200);
  rightWheel2.run(FORWARD);
}

void goBackward()
{
  leftWheel.setSpeed(200);
  leftWheel.run(BACKWARD);
  rightWheel.setSpeed(200);
  rightWheel.run(BACKWARD);
  leftWheel2.setSpeed(200);
  leftWheel2.run(BACKWARD);
  rightWheel2.setSpeed(200);
  rightWheel2.run(BACKWARD);
}

void charge()
{
  leftWheel.setSpeed(220);
  leftWheel.run(FORWARD);
  rightWheel.setSpeed(220);
  rightWheel.run(FORWARD);
  leftWheel2.setSpeed(220);
  leftWheel2.run(FORWARD);
  rightWheel2.setSpeed(220);
  rightWheel2.run(FORWARD);

;
}

void rampup()
{
  leftWheel.setSpeed(255);
  leftWheel.run(FORWARD);
  rightWheel.setSpeed(255);
  rightWheel.run(FORWARD);
  leftWheel2.setSpeed(255);
  leftWheel2.run(FORWARD);
  rightWheel2.setSpeed(255);
  rightWheel2.run(FORWARD);

}


