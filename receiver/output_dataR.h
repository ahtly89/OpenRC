
#ifndef output_dataR_h
#define output_dataR_h

#include "pinsR.h"

void output_data()
{
  #ifndef THROTTLE_PWM
    throttle.write(message_R[0]);
  #else
    analogWrite(throttle_pin_R,message_R[0]);
  #endif //throttle pwm
  
  #ifndef      YAW_PWM
    yaw.write(message_R[1]);
  #else
    analogWrite(yaw_pin_R,message_R[1]);
  #endif //yaw pwm
  
  #ifndef     ROLL_PWM  
    roll.write(message_R[2]);
  #else
    analogWrite(roll_pin_R,message_R[2]);
  #endif //roll pwm
  
  #ifndef    PITCH_PWM
    pitch.write(message_R[3]);
  #else
    analogWrite(pitch_pin_R,message_R[3]);
  #endif
     
  #ifndef     AUX1_PWM
    aux1.write(message_R[4] & 0b10000000 ? MAX_SERVO_VALUE : MIN_SERVO_VALUE);
  #else
    analogWrite(aux1_pin_R, message_R[4] & 0b10000000 ? MAX_PWM_VALUE : MIN_PWM_VALUE);
  #endif
}

#endif //output_dataR_h
