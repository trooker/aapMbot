/* Copyright © 1988-2020 by Abbott Analytical Products. All Rights Reserved.
 * This module sets-up board specific parameters
 *
 * You must edit this header by comment/uncomment the __AVR__
 * 200208_tr Resolved the __AVR_MEGA__  warning: already defined.  The Sloeber project
 *           default is already set to Mega256.
 * 200116_tr resolved aapBase role
 *           Dropped aapBase since it does not seem to be needed
 *           #define TONE_PIN 10 // Pin you have speaker/piezo connected to
 *           (be sure to include a 100 ohm resistor)
 *           https://forum.arduino.cc/index.php?topic=235774.0
 *
 * 200113_tr Adjust for mega256 + Grove Base Shield + Grove Buzzer
 * 161230_tr Initial
 */


#ifndef aapBase_h
#define aapBase_h


#include <Arduino.h>


#ifndef aapBase_brdDef_h
#define aapBase_brdDef_h

//Establish which Arduino Board this program supports
//Using UNO
//#define __AVR_UNO__
//#define TONE_PIN 8 //made buzzer 8

//Using Mega256
//Sloeber project default
//#define __AVR_MEGA__ //Defined in Sloeber as project default
#define TONE_PIN 5
#endif



#endif
