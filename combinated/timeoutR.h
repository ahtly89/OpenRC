
#ifndef timeoutR_h
#define timeoutR_h

#define TIMEOUT 500  //miliseconds without reciveing data that will trigger the SAFE state

//values that will be taken if the receiver doesn't get any data
#define  THROTTLE_SAFE_VALUE   0
#define       YAW_SAFE_VALUE  90
#define      ROLL_SAFE_VALUE  90
#define     PITCH_SAFE_VALUE  90
#define   BUTTONS_SAFE_VALUE 0b01010101


int SAFE_VALUES[] {
  THROTTLE_SAFE_VALUE,
       YAW_SAFE_VALUE,
      ROLL_SAFE_VALUE,
     PITCH_SAFE_VALUE,
   BUTTONS_SAFE_VALUE,
};

#endif //timeoutR_h
