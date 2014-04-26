//-- This function is for choosing the control mode:
//
//     _ _
//    |x|x| HIGH  -- sticks for mode selection
//    |_|_| LOW   --
//     A B
//
//
//-- 2 sticks down is mode 1
//-- stick A up and stick B down is mode 2
//-- 2 sticks up is mode 3
//-- stick A down and stick B up is mode 4
//
//-- Chose the mode and then trigger the mode_reset pin

#ifndef select_modeT_h
#define select_modeT_h

#include "Arduino.h"
#include "pinsT.h"
#include "configT.h"


  void select_mode()
  {
    int mode;
    
    #ifndef MODE
      pinMode(mode_pin_A,INPUT);
      digitalWrite(mode_pin_A,HIGH);
      pinMode(mode_pin_B,INPUT);
      digitalWrite(mode_pin_B,HIGH);
    
      int a = digitalRead(mode_pin_A);
      int b = digitalRead(mode_pin_B);

      if(a == LOW  && b == LOW ) //mode 1
        mode = 1;
      if(a == HIGH && b == LOW ) //mode 2
        mode = 2;
      if(a == HIGH && b == HIGH) //mode 4
        mode = 3;
      if(a == LOW  && b == LOW ) //mode 4
        mode = 4;
    #else // MODE = X
        mode = MODE;
    #endif


    if(mode == 1)
    {
      throttle_pin_T = stick_2_y ;
      yaw_pin_T      = stick_1_x ;
      roll_pin_T     = stick_2_x ;
      pitch_pin_T    = stick_1_y ;
    }
    if(mode == 2)
    {
      throttle_pin_T = stick_1_y ;
      yaw_pin_T      = stick_1_x ;
      roll_pin_T     = stick_2_x ;
      pitch_pin_T    = stick_2_y ;
    }
    if(mode == 3)
    {
      throttle_pin_T = stick_2_y ;
      yaw_pin_T      = stick_2_x ;
      roll_pin_T     = stick_1_x ;
      pitch_pin_T    = stick_1_y ;
    }
    if(mode == 4)
    {
      throttle_pin_T = stick_1_y ;
      yaw_pin_T      = stick_2_x ;
      roll_pin_T     = stick_1_x ;
      pitch_pin_T    = stick_2_y ;
    }
  }


#endif //select_modeT_h
