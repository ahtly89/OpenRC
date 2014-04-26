
#ifndef read_statusT_h
#define read_statusT_h

#include "Arduino.h"
#include "pinsT.h"


void read_status()
{
  
  throttle_value_T = map(analogRead(throttle_pin_T),0,1023,MIN_JOYSTICK_VALUE,MAX_JOYSTICK_VALUE);
       yaw_value_T = map(analogRead(     yaw_pin_T),0,1023,MIN_JOYSTICK_VALUE,MAX_JOYSTICK_VALUE);
      roll_value_T = map(analogRead(    roll_pin_T),0,1023,MIN_JOYSTICK_VALUE,MAX_JOYSTICK_VALUE);
     pitch_value_T = map(analogRead(   pitch_pin_T),0,1023,MIN_JOYSTICK_VALUE,MAX_JOYSTICK_VALUE);
     

  buttons_value_T = 0b00000000;
  //Lo inicializo para asegurar que tengo todo a 0
  for( i = 0; i < sizeof(buttons_T); i++)
  {
    buttons_value_T <<= 1;
    buttons_value_T |= digitalRead(buttons_T[i]);
  }
}

#endif //read_statusT_h
