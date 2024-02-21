# Arduino-Robot-Car

<p align="center">
  <img width="500" src="https://github.com/kiettran499/Programming-the-WLKATA-robotic-arm/blob/main/WLKATA-Mirobot-02.jpg">

## Description

- This is self-learning project which makes a 4WD multi-functional robot car using the Arduino platform. It includes line following, obstacle avoidance, Bluetooth control, and voice control functions:
  - Line following: The concept of the line follower robot is related to light. Here, we use the behavior of light on the black-and-white surface. The white color reflects all the light that falls on it, whereas the black color absorbs the light. I use IR transmitters and receivers (photodiodes) to send and receive the lights. When IR rays fall on a white surface, they are reflected toward the IR receiver, generating some voltage changes.

<p align="center">
  <img width="500" src="https://github.com/kiettran499/Programming-the-WLKATA-robotic-arm/blob/main/WLKATA-Mirobot-02.jpg">

  - Obstacle avoidance: It helps the car can spot obstacles and figure out new paths to move without running into them. An Ultrasonic sensor is used to take measurements in all three directions with the help of a servo motor. Based on the distance measurements, the motor takes actions to move forward or turn left and right. A servo motor mounted ultrasonic sensor to detect objects situated both in front and on either side of the car.

<p align="center">
  <img width="500" src="https://github.com/kiettran499/Programming-the-WLKATA-robotic-arm/blob/main/WLKATA-Mirobot-02.jpg">

  - Bluetooth control: The user can send commands directly to Robot via an App in Android Smartphone. Command received via Bluetooth module HC-05 is forwarded to Arduino Uno board using UART serial communication protocol. Arduino code checks the commands received. Whenever the command is a matching string, Arduino controls the movements of the robot accordingly.

<p align="center">
  <img width="500" src="https://github.com/kiettran499/Programming-the-WLKATA-robotic-arm/blob/main/WLKATA-Mirobot-02.jpg">
  
## Hardware

- Robot Car kit (chassis, motors, wheels, nuts, bolts)
- Arduino Uno R3 Board
- L293D Motor Drive Shield
- HC-05 Bluetooth Wireless
- IR sensor
- Ultrasonic sensor
- Servo motor
- Li-ion Batteries

## Software

- Arduino IDE
- Android Bluetooth RC Controller app
 
## Result

- Demonstration video for line following, obstacle avoidance and Bluetooth control functions: https://youtu.be/9Wb20bIvZSg

