/* Copyright © 1988-2020 by Abbott Analytical Products. All Rights Reserved.
 * This program plays the basic Shave and A Haircut tune
 * 170101 Switched to TimeFreeTone used extern melody and noteDurations
 *        Need to add sizeof array to for statement rather than count array members
 *  Arduino example for Tone() <== search on
 * 170101_tr closed first version and sent to svn via Arduino/libsraies
 * 161113_tr Copied in mass as  shown below and then split into cpp and h files
 * Arduino example for Tone() <== search on
 */

/*************************************************
 * Public Constants
 *************************************************/
 

#include "aapShave_Haircut.h"
#include <TimerFreeTone.h>
#include "aapBase.h"




// notes in the melody:
  int SH_melody[] = {
      NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
   };

// note durations: 4 = quarter note, 8 = eighth note, etc.:
  int SH_noteDurations[] = {
      4, 8, 8, 4, 4, 4, 4, 4
   };


void aapShave_Haircut::setTune()
{

}

 aapShave_Haircut::aapShave_Haircut()
 {
	 setTune();
 }
 
 void aapShave_Haircut::begin()
 {
	 
 }
 
 void aapShave_Haircut::end()
 {
	 
 }
 void aapShave_Haircut::loop()
 {
	 
 }
   
 
void aapShave_Haircut::play()
{
  for (int thisNote = 0; thisNote < 8; thisNote++) { // Loop through the notes in the array.
    int SH_noteDuration = 1000/SH_noteDurations[thisNote];
    TimerFreeTone(TONE_PIN, SH_melody[thisNote], SH_noteDuration); // Play thisNote for noteDuration.
    delay(SH_noteDuration * 4 / 3); // Wait while the tone plays in the background, plus another 33% delay between notes.

  }  
  
  
}
