/*
  Author: 
  
  Learning Intention:
  The students will learn how to wire a four pin ultrasonic sensor and configure it to measure distance using a library.
  
  Success Criteria:
    1.  I can correctly wire a 4 pin ultrasonic sensor
    2.  I understand what the trigger and echo pins do
    3.  I generally understand what a library is
    4.  I can get a distance from a untra sensor
    5.  I understand that a continuous servo speed and direction is set by a frequency signal sent from the microcontroller
    6.  I can apply this knowledge to the Ultrasonic Sensor in the sensor kit

  Student Notes: 

  Documentation: 
    https://www.tutorialspoint.com/arduino/arduino_ultrasonic_sensor.htm <-- Ultrasonic sensor explained
    https://github.com/ErickSimoes/Ultrasonic/tree/master <-- We are using this library

  Schematic:
    https://www.tinkercad.com/things/kngLnqo2HEU?sharecode=OVpOeJsUP3bOHBkzbkWCfGcuSIswqXiISYQiG6UzotA
    https://github.com/TempeHS/TempeHS_Ardunio_Bootcamp/blob/main/11.ultrasonicSensor/Bootcamp-ultrasonicSensor.png
*/

// Design a mechatronic system to automate a boom gate
// As car approaches (10cm) boom gate should open
// Once car passes, boomgate closes after 30 seconds



#include "Ultrasonic.h"

#include <Servo.h>
int USPin = 5;

Servo myservo;
Ultrasonic braj_the_sensor(USPin);

unsigned static int servoPin = 7;
unsigned static int potpin = A2;

void setup() {
  myservo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  Serial.println(braj_the_sensor.distanceRead());
  
  int val = analogRead(potpin);
  val = map(val, 0, 1023, 0 , 180);
  myservo.write(val);
}