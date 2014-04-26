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

/* ******************
** RECEIVER PREAMBLE
** ***************** */

#include <SPI.h>
#include <nRF24L01.h>
#include <Mirf.h>
#include <MirfHardwareSpiDriver.h>
#include <MirfSpiDriver.h>
 //Duplicated
 
#include "pinsR.h"
#include "output_dataR.h"
#include "config_outputsR.h"
 
#include <Servo.h>

unsigned long previous_millis = millis();


void setup()
{
  /* ***************
  ** RECEIVER SETUP
  ** ************** */
  Serial.begin(9600);
  
  Mirf.csnPin = 10;
  Mirf.cePin  =  9;
  Mirf.spi = &MirfHardwareSpi ;
  Mirf.init();
  Mirf.setRADDR((byte *)"c0001");
  Mirf.setTADDR((byte *)"s0001");
  Mirf.payload = sizeof(message_R);
  Mirf.config();
  //Duplicated
  
  config_outputs();
}

void loop()
{  
  /* **************
  ** RECEIVER LOOP
  ** ************* */

  while(!Mirf.dataReady()) //Espero a recibir un dato
    {
//      if( (millis()-previous_millis) > 500 )
//      {
//        aux_string = {0,0,0,0,0} ;
//        Serial.print("He recibido --> ");
//        int i;
//        for(i = 0 ;i < sizeof(aux_string)-1; i++)
//        {
//          Serial.print(aux_string[i]);
//          Serial.print("\t");
//        }
//          Serial.print(aux_string[i],BIN);
//          Serial.print("\t");
//        Serial.print("time --> ");
//        Serial.print(millis());
//        Serial.println();
//      }
    }


  Mirf.getData(message_R);
  
  output_data();
  
}
