/* Copyright © 1988-2020 by Abbott Analytical Products. All Rights Reserved.
 * Used to integrate units with MBot 
  * This module sets-up board specific parameters
 * You must edit this header by comment/un-comment the __AVR__
 * 200116_tr Dropped aapBase since it does not seem to be needed
 *           #define TONE_PIN 10 // Pin you have speaker/piezo connected to
 *           (be sure to include a 100 ohm resistor)
 *           https://forum.arduino.cc/index.php?topic=235774.0
 * 200113_tr Adjust for mega256 + Grove Base Shield + Grove Buzzer
 *           Altered to accommodate mega256 with conditional compile directives in aapBase.h
 * 170101_tr: Initial
 * 
 * **/

/* Copyright © 1988-2020 by Abbott Analytical Products. All Rights Reserved.
 * This module sets-up board specific parameters
 *
 * You must edit this header by comment/uncomment the __AVR__
 *
 * 200113_tr Adjust for mega256 + Grove Base Shield + Grove Buzzer
 * 161230_tr Initial
 */


#ifndef aapMbot_h
#define aapMbot_h

#include <Arduino.h>

/* Supported Modules for abbottanp */
//#include "aapBase.h"
//#include "aapPitches.h"
#include "aapHappyBirthDay.h"
#include "aapShave_Haircut.h"
//#include "aapTwinkle_Twinkle.h"
//#include "aapIRremote.h"




#endif // aapMbot_h



