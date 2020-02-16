
/* Copyright © 1988-2020 by Abbott Analytical Products. All Rights Reserved.
 * This program plays the basic Happy Birthday tune
 * 170101 Switched to TimeFreeTone used extern melody and noteDurations
 *        Need to add sizeof array to for statement rather than count array members
 * 170101_tr closed first version and sent to svn via Arduino/libsraies
 * 161113_tr Copied in mass as  shown below and then split into cpp and h files
 * \par Copyright (C), 2012-2016, MakeBlock
 *
 */

/*************************************************
 * Public Constants
 *************************************************/
 
//#include "aapPitches.h"
#include <Arduino.h>
#include "aapHappyBirthDay.h"
#include <TimerFreeTone.h>
#include "aapBase.h"

int  HB_melody[] = {
NOTE_G4,//5  
NOTE_G4,//5
NOTE_A4,//6
NOTE_G4,//5
NOTE_C5,//1.
NOTE_B4,//7
0//,
/*NOTE_G4,//5
NOTE_G4,//5
NOTE_A4,//6
NOTE_G4,//5
NOTE_D5,//2.
NOTE_C5,//1.
0,
NOTE_G4,//5
NOTE_G4,//5
NOTE_G5,//5.
NOTE_C5,//1.
NOTE_B4,//7
NOTE_A4,//6
0,
NOTE_F5,//4.
NOTE_F5,//4.
NOTE_E5,//3.
NOTE_E5,//3.
NOTE_C5,//1.
NOTE_D5,//2.
NOTE_C5,//1.
0,*/
};


int HB_noteDurations[] = {
  8,8,4,4,4,4,
  4 //,
 // 8,8,4,4,4,4,
 // 4,
// 8,8,4,4,4,4,2,
 // 8,
 // 8,8,4,4,4,2,
 //4,
};
/** **/ 



void aapHappyBirthDay::setTune()
{

}

 aapHappyBirthDay::aapHappyBirthDay()
 {
	 setTune();
 }
 
 void aapHappyBirthDay::begin()
 {
 
	 
 }
 
 void aapHappyBirthDay::end()
 {
  }
 void aapHappyBirthDay::loop()
 {
	 
 }
 
void aapHappyBirthDay::play()
{
  //int thisNote = 2;
  int notemax  = 7; //was 29  for full tone
  for (int thisNote = 0; thisNote <  notemax; thisNote++)
   { // Loop through the notes in the array.
    int HB_noteDuration = 1000/HB_noteDurations[thisNote];
    TimerFreeTone(TONE_PIN, HB_melody[thisNote], HB_noteDuration); // Play thisNote for noteDuration.
    delay(HB_noteDuration * 4 / 3); // Wait while the tone plays in the background, plus another 33% delay between notes.
    //noNewTone(TONE_PIN); // Turn off the tone.
  }
}

