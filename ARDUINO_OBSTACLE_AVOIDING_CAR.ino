//ARDUINO OBSTACLE AVOIDING CAR//
// Before uploading the code you have to install the necessary library//
//AFMotor Library https://learn.adafruit.com/adafruit-motor-shield/library-install //
//NewPing Library https://github.com/livetronic/Arduino-NewPing// 
//Servo Library https://github.com/arduino-libraries/Servo.git //
// To Install the libraries go to sketch >> Include Library >> Add .ZIP File >> Select the Downloaded ZIP files From the Above links //


#include <AFMotor.h>  
#include <NewPing.h>
#include <Servo.h> 

const int speed = 60; // percent of maximum speed

#define TRIG_PIN A4 
#define ECHO_PIN A5
#define MAX_DISTANCE 200 
#define MAX_SPEED 150 // sets speed of DC  motors
#define MAX_SPEED_OFFSET 20

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); 

AF_DCMotor Motor_Left_Front(4, MOTOR34_1KHZ); // Motor 4 
AF_DCMotor Motor_Right_Front(3, MOTOR34_1KHZ); // Motor 3
AF_DCMotor Motor_Left_Rear(1, MOTOR12_1KHZ); // Motor 1
AF_DCMotor Motor_Right_Rear(2, MOTOR12_1KHZ); // Motor 2

Servo myservo;   

boolean goesForward=false;
int distance = 100;
int speedSet = 0;
int pwm;


void setup() {

  myservo.attach(10);  
  myservo.write(115); 
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop() {
 int distanceR = 0;
 int distanceL = 0;
 delay(40);
 
 if(distance<=30)
 {
  moveStop();
  delay(100);
  moveBackward();
  delay(300);
  moveStop();
  delay(200);
  distanceR = lookRight();
  delay(200);
  distanceL = lookLeft();
  delay(200);

  if(distanceR>=distanceL)
  {
    turnRight();
    moveStop();
  }else if(distanceR==distanceL)
  {
    turnLeft();
    moveStop();
  }
 }else
 {
  moveForward();
 }
 distance = readPing();
}

int lookRight()
{
    myservo.write(50); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(115); 
    return distance;
}

int lookLeft()
{
    myservo.write(170); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(115); 
    return distance;
    delay(100);
}

int readPing() { 
  delay(70);
  int cm = sonar.ping_cm();
  if(cm==0)
  {
    cm = 250;
  }
  return cm;
}

void moveStop() {
    Motor_Left_Front.run(RELEASE);
    Motor_Left_Rear.run(RELEASE);
    Motor_Right_Front.run(RELEASE);
    Motor_Right_Rear.run(RELEASE);
  } 
  
void moveForward() {

 if(!goesForward)
  {
    goesForward=true;
    Motor_Left_Front.run(FORWARD);      
    Motor_Left_Rear.run(FORWARD);
    Motor_Right_Front.run(FORWARD); 
    Motor_Right_Rear.run(FORWARD);     
   for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) // slowly bring the speed up to avoid loading down the batteries too quickly
   {
    Motor_Left_Front.setSpeed(speedSet);
    Motor_Left_Rear.setSpeed(speedSet);
    Motor_Right_Front.setSpeed(speedSet);
    Motor_Right_Rear.setSpeed(speedSet);
    delay(5);
   }
  }
}

void moveBackward() {
    goesForward=false;
    Motor_Left_Rear.run(BACKWARD);      
    Motor_Right_Rear.run(BACKWARD);
    Motor_Right_Front.run(BACKWARD);
    Motor_Left_Front.run(BACKWARD);  
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) // slowly bring the speed up to avoid loading down the batteries too quickly
  {
    Motor_Left_Rear.setSpeed(speedSet);
    Motor_Right_Rear.setSpeed(speedSet);
    Motor_Right_Front.setSpeed(speedSet);
    Motor_Left_Front.setSpeed(speedSet);
    delay(5);
  }
}  

void turnRight() {
  Motor_Left_Rear.run(FORWARD);
  Motor_Right_Rear.run(FORWARD);
  Motor_Right_Front.run(BACKWARD);
  Motor_Left_Front.run(BACKWARD);     
  delay(500);
  Motor_Left_Rear.run(FORWARD);      
  Motor_Right_Rear.run(FORWARD);
  Motor_Right_Front.run(FORWARD);
  Motor_Left_Front.run(FORWARD);  
      
    for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) // slowly bring the speed up to avoid loading down the batteries too quickly
  {
    Motor_Left_Rear.setSpeed(speedSet);
    Motor_Right_Rear.setSpeed(speedSet);
    Motor_Right_Front.setSpeed(speedSet);
    Motor_Left_Front.setSpeed(speedSet);
    delay(5);    
  }


} 
 
void turnLeft() {
  Motor_Left_Rear.run(BACKWARD);     
  Motor_Right_Rear.run(BACKWARD);  
  Motor_Right_Front.run(FORWARD);
  Motor_Left_Front.run(FORWARD);   
  delay(500);
  Motor_Left_Rear.run(FORWARD);     
  Motor_Right_Rear.run(FORWARD);
  Motor_Right_Front.run(FORWARD);
  Motor_Left_Front.run(FORWARD);

    for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) // slowly bring the speed up to avoid loading down the batteries too quickly
  {
    Motor_Left_Rear.setSpeed(speedSet);
    Motor_Right_Rear.setSpeed(speedSet);
    Motor_Right_Front.setSpeed(speedSet);
    Motor_Left_Front.setSpeed(speedSet);
    delay(5); 
  }
  
}  
