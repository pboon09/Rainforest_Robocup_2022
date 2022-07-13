#include <Arduino.h>
#include <HMC5883L_Simple.h>
HMC5883L_Simple Compass;

#include <Wire.h> //Include the Wire Library
#include <HTInfraredSeeker.h> //Include the IR Seeker Library

#include <SoftwareSerial.h>
SoftwareSerial bt(18, 19); //Tx, RX

#include <Servo.h>
Servo ms;

//1 blue servo
//#define motor1pin1 2
//#define motor1pin2 3
//#define motor1ena 4
//
//#define motor2pin1 8
//#define motor2pin2 9
//#define motor2ena 13
//
//#define motor3pin1 5
//#define motor3pin2 6
//#define motor3ena 7
//
//#define motor4pin1 11
//#define motor4pin2 12
//#define motor4ena 10.

//2 lego เสา
#define motor1pin1 2
#define motor1pin2 3
#define motor1ena 13

#define motor2pin1 8
#define motor2pin2 9
#define motor2ena 7

#define motor3pin1 6
#define motor3pin2 5
#define motor3ena 10

#define motor4pin1 12
#define motor4pin2 11
#define motor4ena 4

////3 best boy
//#define motor1pin1 8
//#define motor1pin2 9
//#define motor1ena 4
//
//#define motor2pin1 5
//#define motor2pin2 6
//#define motor2ena 13
//
//#define motor3pin1 12
//#define motor3pin2 11
//#define motor3ena 7
//
//#define motor4pin1 3
//#define motor4pin2 2
//#define motor4ena 10

int p1, p2, p3, p4;

#define red 30
#define green 31
#define blue 32

int x, y, z, a, del_a, initial_angle;

#define STR_FILTER 0
#define IR_LOWER_BOUND 1
#define IR_HIGHER_BOUND 9

int ps = 0;

#define Kp 1
#define Kd 1
#define sp 200
int error, last_error;

int light[] = {A8, A9, A10, A11, A12, A13, A14, A15};
int val1, val2, val3, val4, val5, val6, val7, val8;
int ball_found = A7;
int ball = 850;
int white = 580;
int sen;

boolean found;
int sp_dic, IR;
int kick_ball = 150;
int seek_ball = 200;

void setup() {
  Serial.begin(9600);
  bt.begin(38400);

  Wire.begin();
  InfraredSeeker::Initialize();

  Compass.SetDeclination(0, 49, 'W');
  Compass.SetSamplingMode(COMPASS_CONTINUOUS);
  Compass.SetScale(COMPASS_SCALE_130);
  Compass.SetOrientation(COMPASS_HORIZONTAL_Y_NORTH);

  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);

  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  pinMode(motor3pin1, OUTPUT);
  pinMode(motor3pin2, OUTPUT);

  pinMode(motor4pin1, OUTPUT);
  pinMode(motor4pin2, OUTPUT);

  pinMode(motor1ena, OUTPUT);
  pinMode(motor2ena, OUTPUT);
  pinMode(motor3ena, OUTPUT);
  pinMode(motor4ena, OUTPUT);

  pinMode(red, INPUT);
  pinMode(green, INPUT);
  pinMode(blue, INPUT);

  ms.attach(24);

  ms.write(180);

  while (analogRead(ball_found) > ball) {
    ao();
  }

  delay(1000);

  del_a = Compass.GetHeadingDegrees();

  ms.write(0);

  delay(100);

}

void loop() {
  attacker(del_a);
  white_line(del_a);
}
