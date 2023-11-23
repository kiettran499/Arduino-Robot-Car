

  #include <AFMotor.h>  


  #define MAX_SPEED 190 // sets speed of DC  motors
  #define MAX_SPEED_OFFSET 20
  #define Echo A0
  #define Trig A1


  char value;
  char t;
  int pwm;
  const int speed = 100; // percent of maximum speed


  AF_DCMotor Motor_Left_Front(4, MOTOR34_1KHZ); // Motor 4 
  AF_DCMotor Motor_Right_Front(3, MOTOR34_1KHZ); // Motor 3
  AF_DCMotor Motor_Left_Rear(1, MOTOR12_1KHZ); // Motor 1
  AF_DCMotor Motor_Right_Rear(2, MOTOR12_1KHZ); // Motor 2

  int speedSet = 0;
  
  void setup() {

    Serial.begin(9600);

    pwm= map(speed, 0,100, 0,255); 
    Motor_Left_Front.setSpeed(pwm);
    Motor_Right_Front.setSpeed(pwm);
    Motor_Left_Rear.setSpeed(pwm);
    Motor_Right_Rear.setSpeed(pwm);
  
  }
  
  void loop() {

    pinMode(Trig, OUTPUT);
    pinMode(Echo, INPUT);

  //Obstacle();
  Bluetoothcontrol();
  //voicecontrol();
}
void Bluetoothcontrol() {
  if (Serial.available() > 0) {
    value = Serial.read();
    Serial.println(value);
  }
  if (value == 'F') {
    forward();
  } else if (value == 'B') {
    backward();
  } else if (value == 'L') {
    left();
  } else if (value == 'R') {
    right();
  } else if (value == 'S') {
    Stop();
  }
}


  
void forward() {
  Motor_Left_Front.run(FORWARD);      
  Motor_Left_Rear.run(FORWARD);
  Motor_Right_Front.run(FORWARD); 
  Motor_Right_Rear.run(FORWARD);
}
void backward() {
  Motor_Left_Rear.run(BACKWARD);      
  Motor_Right_Rear.run(BACKWARD);
  Motor_Right_Front.run(BACKWARD);
  Motor_Left_Front.run(BACKWARD);
}
void right() {
  Motor_Left_Rear.run(FORWARD);
  Motor_Right_Rear.run(FORWARD);
  Motor_Right_Front.run(BACKWARD);
  Motor_Left_Front.run(BACKWARD);
}
void left() {
  Motor_Left_Rear.run(BACKWARD);     
  Motor_Right_Rear.run(BACKWARD);  
  Motor_Right_Front.run(FORWARD);
  Motor_Left_Front.run(FORWARD);  
}
void Stop() {
  Motor_Left_Front.run(RELEASE);
  Motor_Left_Rear.run(RELEASE);
  Motor_Right_Front.run(RELEASE);
  Motor_Right_Rear.run(RELEASE);
}