/* Copyright © 1988-2020 by Abbott Analytical Products. All Rights Reserved.
 * This program plays the basic Twinkle-Twinkle Little Star tune
 * Built upon Shave and a Haircut
 * and https://gist.github.com/baojie/4522173#file-arduino_music-c-L7
 * 170102_tr_Initial   
 * 
 *  *       timeHigh = period / 2 = 1 / (2 * toneFrequency)
 *
 * where the different tones are described as in the table:
 *
 * note   frequency 	period 	timeHigh
 * c 	        261 Hz 	        3830 	1915 	
 * d 	        294 Hz 	        3400 	1700 	
 * e 	        329 Hz 	        3038 	1519 	
 * f 	        349 Hz 	        2864 	1432 	
 * g 	        392 Hz 	        2550 	1275 	
 * a 	        440 Hz 	        2272 	1136 	
 * b 	        493 Hz 	        2028	1014	
 * C	        523 Hz	        1912 	956

 * 
 * int length = 15; // the number of notes

//twinkle twinkle little star
char notes[] = "ccggaag ffeeddc ggffeed ggffeed ccggaag ffeeddc "; // a space represents a rest
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
int tempo = 300;

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }



 */

 

/*************************************************
 * Public Constants
 *************************************************/
 

#include "aapTwinkle_Twinkle.h"
#include <TimerFreeTone.h>



// notes in the melody:
  int TT_melody[] = {
  NOTE_C4,// c
  NOTE_C4,// c
  NOTE_G4,// g
  NOTE_G4,// g
  NOTE_A4,// a
  NOTE_A4,// a
  NOTE_G4,// g
  0,
  NOTE_F4,//  f
  NOTE_F4,//  f
  NOTE_E4,// e
  NOTE_E4,// e
  NOTE_D4,// d
  NOTE_D4,// d
  NOTE_C4,// c
  0,
  NOTE_G4,// g
  NOTE_G4,// g
  NOTE_F4,//  f
  NOTE_F4,//  f
  NOTE_E4,// e
  NOTE_E4,// e
  NOTE_D4,// d
  0,
  NOTE_G4,// g
  NOTE_G4,// g
  NOTE_F4,//  f
  NOTE_F4,//  f
  NOTE_E4,// e
  NOTE_E4,// e
  NOTE_D4,// d
  0,
  NOTE_C4,//c
  NOTE_C4,//c
  NOTE_G4,// g
  NOTE_G4,// g
  NOTE_A4,// a
  NOTE_A4,// a
  NOTE_G4,// g
  0,
  NOTE_F4,//  f
  NOTE_F4,//  f
  NOTE_E4,// e
  NOTE_E4,// e
  NOTE_D4,// d
  NOTE_D4,// d
  NOTE_C4,// c
  0
//     NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
   };

// note durations: 4 = quarter note, 8 = eighth note, etc.:
  int TT_noteDurations[] = {
    //  4, 8, 8, 4, 4, 4, 4, 4
  //1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 
    4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2, 1,
    4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2, 1,
    4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2, 1
 /*
    4, 4, 4, 4, 4, 4, 8, 4, 4, 4, 4, 4, 4, 8, 16,
    4, 4, 4, 4, 4, 4, 8, 4, 4, 4, 4, 4, 4, 8, 16,
    4, 4, 4, 4, 4, 4, 8, 4, 4, 4, 4, 4, 4, 8, 16*/
   };


void aapTwinkle_Twinkle::setTune()
{

}

 aapTwinkle_Twinkle::aapTwinkle_Twinkle()
 {
	 setTune();
 }
 
 void aapTwinkle_Twinkle::begin()
 {
	 
 }
 
 void aapTwinkle_Twinkle::end()
 {
	 
 }
 void aapTwinkle_Twinkle::loop()
 {
	 
 }
   
 
void aapTwinkle_Twinkle::play()
{
  for (int thisNote = 0; thisNote < 47; thisNote++) { // Loop through the notes in the array.
    int TT_noteDuration = 1000/TT_noteDurations[thisNote];
    TimerFreeTone(TONE_PIN, TT_melody[thisNote], TT_noteDuration); // Play thisNote for noteDuration.
    delay(TT_noteDuration * 4 / 3); // Wait while the tone plays in the background, plus another 33% delay between notes.

  }  
  
  
}
