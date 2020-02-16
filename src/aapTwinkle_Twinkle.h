/* Copyright © 1988-2020 by Abbott Analytical Products. All Rights Reserved. 
 * This program plays the basic Twinkle-Twinkle Little Star tune
 * 170102_Initial
 * Built upon Shave and a Haircut
 * and https://gist.github.com/baojie/4522173#file-arduino_music-c-L7
 * 
 * 
 *  
 */

 
#ifndef aapTwinkle_Twinkle_h
#define aapTwinkle_Twinkle_h

#include "aapBase.h" 
#include "aapPitches.h" 


extern int TT_melody[];
extern int TT_noteDurations[];


class aapTwinkle_Twinkle
{
public:  
	aapTwinkle_Twinkle();
    void begin();
    void end();
    void loop();
    void play();

	private:
	void setTune();
	
};

#endif // aapTwinkle_Twinkle_h
