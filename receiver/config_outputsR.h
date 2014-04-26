#ifndef config_outputsR_h
#define config_outputsR_h


void config_outputs()
{
  #ifndef THROTTLE_PWM
    throttle.attach(throttle_pin_R);
  #else
    pinMode(throttle_pin_R,OUTPUT);
  #endif //throttle pwm
  
  #ifndef YAW_PWM
       yaw.attach(yaw_pin_R);  
  #else
    pinMode(yaw_pin_R,OUTPUT);
  #endif //yaw pwm
  
  #ifndef ROLL_PWM  
      roll.attach(roll_pin_R);
  #else
    pinMode(roll_pin_R,OUTPUT);
  #endif //roll pwm
  
  #ifndef PITCH_PWM
     pitch.attach(pitch_pin_R);
  #else
    pinMode(pitch_pin_R,OUTPUT);
  #endif
     
  #ifndef AUX1_PWM
      aux1.attach(aux1_pin_R);
  #else
    pinMode(aux1_pin_R,OUTPUT);
  #endif
  
  #ifndef AUX2_PWM
      aux2.attach(aux2_pin_R);
  #else
    pinMode(aux2_pin_R,OUTPUT);
  #endif
  
//  aux3.attach(aux3_pin_R);
//  aux4.attach(aux4_pin_R);
//  aux5.attach(aux5_pin_R);
//  aux6.attach(aux6_pin_R);
//  aux7.attach(aux7_pin_R);
//  aux8.attach(aux8_pin_R);
}

#endif //config_outputsR_h
