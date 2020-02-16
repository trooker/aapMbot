/* Copyright © 1988-2020 by Abbott Analytical Products. All Rights Reserved.
 * This program plays the basic Happy Birthday tune
 * 161113_tr Copied in mass as  shown below and then split into cpp and h files *
 */


#ifndef aapHappyBirthDay_h
#define aapHappyBirthDay_h

#include "aapPitches.h"


extern int HB_melody[];
extern int HB_noteDurations[];


class aapHappyBirthDay
{
	private:
	void setTune();

	
	public: 
 	aapHappyBirthDay();
    void begin();
    void end();
    void loop();
    void play();
	
};

#endif // aapHappyBirthDay
