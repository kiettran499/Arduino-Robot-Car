

#include <NewPing.h>
#include <Servo.h>
#include <AFMotor.h>


//Robot dò line đơn giản V 1
 

const int speed = 60; // percent of maximum speed

//ir sensor
#define left A0  //IN1
//#define IN2 A1
#define center A1 //IN3
#define right A3   //IN4

AF_DCMotor Motor_Left_Front(4, MOTOR34_1KHZ); // Motor 4 
AF_DCMotor Motor_Right_Front(3, MOTOR34_1KHZ); // Motor 3
AF_DCMotor Motor_Left_Rear(1, MOTOR12_1KHZ); // Motor 1
AF_DCMotor Motor_Right_Rear(2, MOTOR12_1KHZ); // Motor 2

int pwm;

void setup() {
  
  pinMode (right, INPUT);
  pinMode (left, INPUT);
  pinMode (center, INPUT);
  //pinMode (IN4, INPUT);
  Serial.begin(9600);

  pwm= map(speed, 0,100, 0,255); 
 Motor_Left_Front.setSpeed(pwm);
 Motor_Right_Front.setSpeed(pwm);
 Motor_Left_Rear.setSpeed(pwm);
 Motor_Right_Rear.setSpeed(pwm);
}

void loop(){

  Serial.println(digitalRead(left));
  Serial.println(digitalRead(center));
  Serial.println(digitalRead(right));

  
  if(digitalRead(left)==0 && digitalRead(right)==0  && !digitalRead(center)==0){
    // Robot di chuyển tiến 
    Motor_Left_Front.run(FORWARD);
    //motor1.setSpeed(pwm); // tốc độ di chuyển của robot phạm vi từ 0 đến 255
    Motor_Left_Rear.run(FORWARD); 
    //motor2.setSpeed(pwm);// tốc độ di chuyển của robot phạm vi từ 0 đến 255
    Motor_Right_Front.run(FORWARD);
    //motor3.setSpeed(pwm);// tốc độ di chuyển của robot phạm vi từ 0 đến 255
    Motor_Right_Rear.run(FORWARD);
    //motor4.setSpeed(pwm);// tốc độ di chuyển của robot phạm vi từ 0 đến 255
  }
  //Robot so sánh tín hiệu 2 cảm biến 
  else if(digitalRead(right)==0 && !digitalRead(left)==0 && digitalRead(center)==0){
    //dừng lại 
    Motor_Left_Front.run(RELEASE);
    //motor1.setSpeed(0);
    Motor_Left_Rear.run(RELEASE);
    //motor2.setSpeed(0);
    Motor_Right_Front.run(RELEASE);
    //motor3.setSpeed(0);
    Motor_Right_Rear.run(RELEASE);
    //motor4.setSpeed(0);
    
  }
  //Robot so sánh tín hiệu 2 cảm biến 
  else if(!digitalRead(right)==0 && digitalRead(left)==0 && digitalRead(center)==0){
    //rẽ phải 
    Motor_Left_Front.run(BACKWARD);
    //motor1.setSpeed(pwm);
    Motor_Left_Rear.run(BACKWARD);
    //motor2.setSpeed(pwm);
    Motor_Right_Front.run(FORWARD);
    //motor3.setSpeed(pwm);
    Motor_Right_Rear.run(FORWARD);
    //motor4.setSpeed(pwm);
   
  }
  //khi 2 cảm biến không có tín hiệu trả về 
  else if(!digitalRead(left)==0 && !digitalRead(right)==0 && !digitalRead(center)==0){
    //dừng lại 
    Motor_Left_Front.run(RELEASE);
    //motor1.setSpeed(0);
    Motor_Left_Rear.run(RELEASE);
    //motor2.setSpeed(0);
    Motor_Right_Front.run(RELEASE);
    //motor3.setSpeed(0);
    Motor_Right_Rear.run(RELEASE);
    //motor4.setSpeed(0);
   
  }
  
}














/* Test IR sensor
//ir sensor
#define IN1 A0
#define IN2 A1
#define IN3 A2
#define IN4 A3

void setup() {
  Serial.begin(9600);
  pinMode (IN1, INPUT);
  pinMode (IN2, INPUT);
  pinMode (IN3, INPUT);
  pinMode (IN4, INPUT);
}

void loop() {
  if (digitalRead (IN1) == 0) Serial.print("Sensor IN1 = white    ");
  else Serial.print("Sensor IN1 = black   ");

  if (digitalRead (IN2) == 0) Serial.print("Sensor IN2 = white    ");
  else Serial.print("Sensor IN2 = black   ");

  if (digitalRead (IN3) == 0) Serial.print("Sensor IN3 = white    ");
  else Serial.print("Sensor IN3 = black   ");

  if (digitalRead (IN4) == 0) Serial.print("Sensor IN4 = white    ");
  else Serial.print("Sensor IN4 = black   ");

  delay(1000);

}
*/
