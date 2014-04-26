
#ifndef pinsT_h
#define pinsT_h

#include "Arduino.h"
#include "configT.h"


#ifndef MODE
  //pins for selecting control mode
  #define mode_reset 2  //Must can be used as interrupt
  #define mode_pin_A 3
  #define mode_pin_B 4
#endif //MODE

#define MESSAGE_LENGTH_T 5


#define stick_1_x A0
#define stick_1_y A1
#define stick_2_x A2
#define stick_2_y A3


volatile int throttle_pin_T;
volatile int yaw_pin_T;
volatile int roll_pin_T;
volatile int pitch_pin_T;
byte throttle_value_T;
byte yaw_value_T;
byte roll_value_T;
byte pitch_value_T;


//#define button_pins_T {14,15,16,17,18,19,20,21} 
#define button_pins_T {34,35,36,37,38,39,40,41}

int buttons_T[] = button_pins_T;
byte buttons_value_T;

byte message_T[MESSAGE_LENGTH_T];

int i,j,k; //Always useful


#endif //pinsT_h
