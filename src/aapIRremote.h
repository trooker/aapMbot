/* Copyright © 1988-2020 by Abbott Analytical Products. All Rights Reserved.
 * Used to integrate IRRemote with MBot 
 * 170109_tr: Initial
 * 
 * **/

#ifndef aapIRremote_h
#define aapIRremote_h



#define aapRec_pin 2
#define aapTKD2 aapRec_pin



class aapIRremote
{
	public: 
 	aapIRremote();
    void begin();
    void end();
    void loop();
   // void play();

};

#endif
