/* Copyright © 1988-2020 by Abbott Analytical Products. All Rights Reserved.
 * This program plays the basic Shave and a Haircut tune
 * 170101 Switched to TimeFreeTone used extern melody and noteDurations

 * 161113_tr Copied in mass as  shown below and then split into cpp and h files
 *
 * Function List:
 * 1. void buzzerOn()
 * 2. void buzzerOff()
 *
 */

 
#ifndef aapShave_Haircut_h
#define aapShave_Haircut_h

#include <Arduino.h>
#include "aapPitches.h" 


extern int SH_melody[];
extern int SH_noteDurations[];


class aapShave_Haircut
{
public:  
	aapShave_Haircut();
    void begin();
    void end();
    void loop();
    void play();

	private:
	void setTune();
	
};

#endif // aapShave_Haircut
