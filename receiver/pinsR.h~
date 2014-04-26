
#ifndef pinsR_h
#define pinsR_h

#include <Servo.h>

#define MESSAGE_LENGTH_R 5
byte message_R[MESSAGE_LENGTH_R];

#define throttle_pin_R 19 //22
#define yaw_pin_R      18 //23
#define roll_pin_R     17 //24
#define pitch_pin_R    16 //25
#define aux1_pin_R     15 //26
#define aux2_pin_R     14 //27
//#define aux3_pin_R     28
//#define aux4_pin_R     29
//#define aux5_pin_R     30
//#define aux6_pin_R     31
//#define aux7_pin_R     32
//#define aux8_pin_R     33



//-- The servo library provides PPM response, so using it 
//   it's a good way to get the PPM signal easily
Servo throttle;
Servo yaw;
Servo roll;
Servo pitch;
Servo aux1;
Servo aux2;
//Servo aux3;
//Servo aux4;
//Servo aux5;
//Servo aux6;
//Servo aux7;
//Servo aux8;  //12 channels

#define MIN_SERVO_VALUE  40
#define MAX_SERVO_VALUE 150
#define MIN_PWM_VALUE     0
#define MAX_PWM_VALUE  1023

//-- This define will setup the output for the pins
//-- if you DON'T define the ouptup (comment it out)
//-- the output will be PPM, if you active the define
//-- the output will be PWM
// #define THROTTLE_PWM
// #define      YAW_PWM
// #define     ROLL_PWM
// #define    PITCH_PWM
// #define     AUX1_PWM


#endif //pinsR_h
