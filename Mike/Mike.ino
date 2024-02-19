#include <AFMotor.h>

AF_DCMotor leftWheel(4);
AF_DCMotor rightWheel(3);

int leftIR = 0;
int rightIR = 0;
int button = 0;

int trigPin = 19;
int echoPin = 18;
long duration = 0;
int distance = 0;

void setup() {
  Serial.begin(9600);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(17, INPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  leftWheel.run(RELEASE); //.run(direction)
  rightWheel.run(RELEASE); //RELEASE, FORWARD, BACKWARD ; RELEASE = stop
  delay(5000);
}

void loop() 
{
  proximity();

  /*
  Notes on distance:
  1 ruler length: 30cm
  2/3 ruler length: 20cm
  1/2 ruler length: 15cm
  1/4 ruler length: 10cm
  */

  int leftIR = digitalRead(10);
  int rightIR = digitalRead(9);
  
  Serial.println(distance);
  
  Serial.print(leftIR);
  Serial.print(" | ");
  Serial.println(rightIR);

  if(rightIR == 1 && leftIR == 1)
  {
    proximity();
    if(distance > 50)
    {
      int z = choice(1,2);
      search(z);
    }
    
    if (distance < 50)
    {
        charge();

      if(leftIR == 0 || rightIR == 0)
      {
      leftWheel.run(RELEASE);
      rightWheel.run(RELEASE);
      }

    }

  }

  if(leftIR == 0 && rightIR == 0)
  {
    goBackward();
    delay(500);
    int z = choice(1,2);
    if(z = 0)
    {
      turnRight();
      delay(400);
      leftWheel.run(RELEASE);
      rightWheel.run(RELEASE);
    }

    if(z = 1)
    {
      turnLeft();
      delay(400);
      leftWheel.run(RELEASE);
      rightWheel.run(RELEASE);
    }
  }

  if(leftIR == 0 && rightIR == 1)
  {
    turnRight();
    delay(400);
    leftWheel.run(RELEASE);
    rightWheel.run(RELEASE);
  }

  if(leftIR == 1 && rightIR == 0)
  {
    turnLeft();
    delay(400);
    leftWheel.run(RELEASE);
    rightWheel.run(RELEASE);
  }

/*
    Basic Movement Notes
    if(rightIR == 0 && leftIR == 0)
    {
      goBackward();
      delay(1000);
      turnRight();
      delay(500);
    }

    if(rightIR == 1 && leftIR == 1)
    {
      goForward();
    }

    if(rightIR == 0 && leftIR == 1)
    {
      turnLeft();
      delay(random(100,500));
    }

    if(rightIR == 1 && leftIR == 0)
    {
      turnRight();
      delay(random(100,500));
    }
  */
    delay(10);
}


//Functions

//Controlled Delay
int c_delay(int max)
{
  for(int x = 1; x <= max ; x++)
  {
    delay(1);
    if(rightIR == 0 || leftIR == 0)
    {
      break;
    }
  }
}

//Choice
int choice(int min, int max)
{
  int c = (random(min, (max*10)));
  int x = c%max;
  return x;
}

//Distance
void proximity()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*0.0343)/2;
}

//Search
void search(int x)
{
  if(x == 0)
  {
    leftWheel.setSpeed(200);
  rightWheel.setSpeed(200);
  leftWheel.run(FORWARD);
  rightWheel.run(BACKWARD);
  delay(25);
  leftWheel.run(RELEASE);
  rightWheel.run(RELEASE);
  }

  if(x == 1)
  {
    leftWheel.setSpeed(200);
  rightWheel.setSpeed(200);
  leftWheel.run(BACKWARD);
  rightWheel.run(FORWARD);
  delay(100);
  leftWheel.run(RELEASE);
  rightWheel.run(RELEASE);
  }
}

//Basic Movement

void goForward()
{
  leftWheel.setSpeed(200);
  leftWheel.run(FORWARD);
  rightWheel.setSpeed(200);
  rightWheel.run(FORWARD);
}


void turnRight()
{
  leftWheel.setSpeed(200);
  leftWheel.run(FORWARD);
  rightWheel.setSpeed(200);
  rightWheel.run(BACKWARD);
}

void turnLeft()
{
  leftWheel.setSpeed(200);
  leftWheel.run(BACKWARD);
  rightWheel.setSpeed(200);
  rightWheel.run(FORWARD);
}

void goBackward()
{
  leftWheel.setSpeed(200);
  leftWheel.run(BACKWARD);
  rightWheel.setSpeed(200);
  rightWheel.run(BACKWARD);
}

void charge()
{
  leftWheel.setSpeed(255);
  leftWheel.run(FORWARD);
  rightWheel.setSpeed(255);
  rightWheel.run(FORWARD);
}