/*
 Open transceiver v0.0.1
 Copyright (C) 2014 Alejandro Nieto

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
** TODO list:
**
** Take away all the commented parts and put it into libraries
** Prepare to recieve some values (pe. battery status)
** LCD support
** EEPROM memory for configurations
** ....
** ....
*/

/* *********************
** TRANSMITTER PREAMBLE
** ******************** */

#include "pinsT.h"
#include "select_modeT.h"
#include "read_statusT.h"
#include "test_printsT.h"
#include "configT.h"

#include <SPI.h>
#include <nRF24L01.h>
#include <Mirf.h>
#include <MirfHardwareSpiDriver.h>
#include <MirfSpiDriver.h>

/* ******************
** RECEIVER PREAMBLE
** ***************** */

//#include <SPI.h>
//#include <nRF24L01.h>
//#include <Mirf.h>
//#include <MirfHardwareSpiDriver.h>
//#include <MirfSpiDriver.h>
 //Duplicated
 
#include "pinsR.h"
#include "output_dataR.h"
#include "config_outputsR.h"
#include "timeoutR.h"
 
#include <Servo.h>

void setup()
{
  /* ******************
  ** TRANSMITTER SETUP
  ** ***************** */

  #ifndef MODE
    //-- Attach an interrupt to mode reset pin (2)
    //-- to trigger the mode changes
    pinMode(mode_reset,INPUT);
    digitalWrite(mode_reset,HIGH);
    attachInterrupt(0,select_mode,RISING);
    //-- Right now you select the control mode by this system, but
    //-- when the LCD gets support the change will be made by LCD
  #endif //MODE
  
  //-- First read the mode the controller will get
  select_mode();
  
  //Serial is just for testing
  Serial.begin(9600);
  
  
  //Inputs for the 2 joysticks
  pinMode(throttle_pin_T,INPUT);
  pinMode(     yaw_pin_T,INPUT);
  pinMode(    roll_pin_T,INPUT);
  pinMode(   pitch_pin_T,INPUT);
  
  
    for(i = 0; i < sizeof(buttons_T); i++)
    {
      pinMode(buttons_T[i],INPUT);
      digitalWrite(buttons_T[i],HIGH); //Pull-up
    }
    
    
    /* *********************
    **  RADIO CONFIGURATION
    ** ******************** */

  Mirf.csnPin = 10;
  Mirf.cePin  =  9;
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  Mirf.setRADDR((byte *) "s0001");
  Mirf.setTADDR((byte *) "c0001");
  
  Mirf.payload = MESSAGE_LENGTH_T; 
                    //5 bytes long signal --> 12 channels:
                    //1º byte --> throttle
                    //2º byte --> yaw
                    //3º byte --> roll
                    //4º byte --> pitch
                    //5º byte --> 8 bits for 8 buttons
                    //TOTAL ----> 4 + 8 = 12 channels
  Mirf.config();  //Finalize the Mirf configuration
  
    
//-- Blink to show that setup is done
  pinMode(A5,OUTPUT);
  int i, parpadeo = LOW;
  for (i=0;i<10;i++){
    parpadeo = !parpadeo;
    digitalWrite(A5,parpadeo);delay(25);
  }
  digitalWrite(A5,LOW);
  pinMode(A5,INPUT);
  digitalWrite(A5,HIGH); //-- Let this part to simulate the stop from receveing data
  
  delay(1000); //Give a second to start right
  
  /* ***************
  ** RECEIVER SETUP
  ** ************** */
  Serial.begin(9600);
  
//  Mirf.csnPin = 10;
//  Mirf.cePin  =  9;
//  Mirf.spi = &MirfHardwareSpi ;
//  Mirf.init();
//  Mirf.setRADDR((byte *)"c0001");
//  Mirf.setTADDR((byte *)"s0001");
//  Mirf.payload = sizeof(message_R);
//  Mirf.config();
  //Duplicated
  
  config_outputs();
  
}

void loop()
{  
  /* *****************
  ** TRANSMITTER LOOP
  ** **************** */
  
  read_status();
  test_prints();
 
 
  message_T = {throttle_value_T,yaw_value_T,roll_value_T,pitch_value_T,buttons_value_T};
  
//  Mirf.send(message);      //Send the values
//  while(Mirf.isSending()); //Wait for it
//  delay(50);               //Really long delay to get a good comunication.

                          //delay(50) --> 20 loops per second
                          // OPTION : no delay, it will loose some signals,
                          // but it could recieve more data

  /* **************
  ** TRANSFER DATA
  ** ************* */
  //-- This part is made for simulate the data transmission
  //-- from the transmitter to the receiver.
  
  //-- Trigger the button A5 will simulate to stop recieveing data
  if(digitalRead(A5) == HIGH)
  {
    for(i = 0 ;i < sizeof(message_T); i++)
    {
      message_R[i] = message_T[i];
    }
    previous_data_recieved_millis = millis(); //Save when I had recieve last data
  }else
  {
    //Do nothing
  }


  /* **************
  ** RECEIVER LOOP
  ** ************* */

//  while(!Mirf.dataReady()) //Espero a recibir un dato
//    {
      timeout_check();
//    }


//  Mirf.getData(message_R);
//  previous_data_recieved_millis = millis(); //Save when I had recieve last data

  output_data();
  
}
