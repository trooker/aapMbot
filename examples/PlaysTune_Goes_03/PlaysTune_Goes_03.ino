/**
 * This program plays and goes 
 * Up Arrow: Fast forwards in direction of big wheels
 * Left Aroow: Counter clockwise spin or left turn
 * Rght Arrow: Clockwise spin or riht turn
 * Down Arrow: Slower forward in direction of the IR dection/follower.
 * Btn7: Happy birthday & spins to left
 * Btn8: Buzz until release
 * Btn9: Shave and a Haircut & spins to right
 * Creates a Serial Monitor output showing the button pushed.
 * the basic Happy Birthday tune
 * 170107_tr Better release control of navigation
 * 170103_tr added Twinkle-Twinkle, Setup-Stop. B, D, E buttons for motion control
 * 170101_tr Switched to TimeFreeTone used extern melody and noteDurations
 *        Need to add sizeof array to for statement rather than count array members
 * 161113_tr Copied MakeBlock Buzzer example in mass as shown below and 
 *        then split into cpp and h files
**/

//See MeInfraredReceiver.h for values of mbot RC buttons 


#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include "SPI.h"
#include <TimerFreeTone.h>
#include <MeMCore.h>
#include <aapTunes.h>


aapHappyBirthDay   myHappyBirthdaySong;
aapShave_Haircut   myShave_Haircut;
aapTwinkle_Twinkle myTwinkle;

//#define __AVR_UNO__
int btnExec = 0;
int knt = 1;
int skip = 10; //briefdelay
int tempo = 500;
int pedal_fast = 255;
int pedal_med = 100;
int pedal_stop = 0;

MeDCMotor motor_9(9);
MeDCMotor motor_10(10);
void move(int direction, int speed)
{
      int leftSpeed = 0;
      int rightSpeed = 0;
      if(direction == 1){
          leftSpeed = speed;
          rightSpeed = speed;
      }else if(direction == 2){
          leftSpeed = -speed;
          rightSpeed = -speed;
      }else if(direction == 3){
          leftSpeed = -speed;
          rightSpeed = speed;
      }else if(direction == 4){
          leftSpeed = speed;
          rightSpeed = -speed;
      }
      motor_9.run((9)==M1?-(leftSpeed):(leftSpeed));
      motor_10.run((10)==M1?-(rightSpeed):(rightSpeed));
}
double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;



MeIR  ir;
//void makeSong();

void setup(){
  ir.begin();
  myTwinkle.begin();
  myShave_Haircut.begin();
  myHappyBirthdaySong.begin();
  Serial.begin(9600);
  Serial.println("MeIR for mbot Start!");

}

void loop(){
//BtnUp  0x40
    if(ir.keyPressed(64)){
        btnExec = IR_BUTTON_UP;
      //  move(2,pedal_fast);
      while(ir.keyPressed(64)){
        move(2,pedal_med);
        delay(skip*2);
        move(1,0);
        }
    }
//BtnDown 0x19    
    if(ir.keyPressed(25)){
        btnExec = IR_BUTTON_DOWN;
      //  move(1,pedal_med);
        while(ir.keyPressed(25)){
        move(1,pedal_med);
        delay(skip*2);
        move(1,0);
        }

    }
//BtnLeft ?? 0x07    
    if(ir.keyPressed(7)){
        btnExec = IR_BUTTON_LEFT;
        //move(3,pedal_med);
        while(ir.keyPressed(7)){
        move(3,pedal_med);
        delay(skip*2);
        move(1,0);
        }

    }
//BtnRight ?? 0x09    
    if(ir.keyPressed(9)){
       btnExec = IR_BUTTON_RIGHT;
       //move(4,pedal_med);
       while(ir.keyPressed(9)){
        move(4,pedal_med);
        delay(skip*2);
        move(1,0);
        }

    }
 //BtnSetting/Play  0x15  Menu
    if((ir.keyPressed(21))){
        btnExec = IR_BUTTON_SETTING;
        move(1,0);
    }
   
//BtnA  0x45 
    if(ir.keyPressed(69)){
        btnExec = IR_BUTTON_A;
        move(1,0);
    }
//BtnB  0x46   
    if(ir.keyPressed(70)){
        btnExec = IR_BUTTON_B;
        while(ir.keyPressed(70)){
        move(2,pedal_fast);
        delay(skip*2);
        move(1,0);
        }
    }
//BtnC 0x47
    if((ir.keyPressed(71))){
        btnExec = IR_BUTTON_C;
        move(1,0);
    }
//BtnD 0x44
    if((ir.keyPressed(68))){
        btnExec = IR_BUTTON_D;
        //move(1,0);
       while(ir.keyPressed(68)){
        move(3,pedal_fast);
        delay(skip*2);
        move(1,0);
        }

    }
//BtnE  0x43   
    if((ir.keyPressed(67))){
        btnExec = IR_BUTTON_E;
        while(ir.keyPressed(67)){
        move(4,pedal_fast);
        delay(skip*2);
        move(1,0);
       // delay(skip);
        }
    }
//BtnF  0x0d   
    if((ir.keyPressed(13))){
        btnExec = IR_BUTTON_F;
        while(ir.keyPressed(13)){
        move(1,pedal_fast);
        delay(skip*2);
        move(1,0);
       // delay(skip);
        }
    }
//Btn0   0x16
    if((ir.keyPressed(22))){
        btnExec = IR_BUTTON_0;
        move(1,0);
        TimerFreeTone(TONE_PIN, NOTE_C2, tempo); // Play thisNote for noteDuration.
    }
//Btn1   0x0c
    if((ir.keyPressed(12))){
        btnExec = IR_BUTTON_1;
        move(1,0);
        TimerFreeTone(TONE_PIN, NOTE_G3, tempo); // Play thisNote for noteDuration.
    }
//Btn2  0x18    
    if((ir.keyPressed(24))){
       btnExec = IR_BUTTON_2;
       move(1,0);
       TimerFreeTone(TONE_PIN, NOTE_F4, tempo); // Play thisNote for noteDuration.
    }
//Btn3  0x5e
    if((ir.keyPressed(94))){
       btnExec = IR_BUTTON_3;
       move(1,0);
       TimerFreeTone(TONE_PIN, NOTE_C5, tempo); // Play thisNote for noteDuration.
    }
//Btn4  0x08
    if((ir.keyPressed(8))){
       btnExec = IR_BUTTON_4;
       move(1,0);
       TimerFreeTone(TONE_PIN, NOTE_G5, tempo); // Play thisNote for noteDuration.
    }
//Btn5  0x1c    
    if((ir.keyPressed(28))){
       btnExec = IR_BUTTON_5;
       move(1,0);
      TimerFreeTone(TONE_PIN, NOTE_F6, tempo); // Play thisNote for noteDuration.
   }
//Btn6   0x5a    
    if((ir.keyPressed(90))){
       btnExec = IR_BUTTON_6;
       TimerFreeTone(TONE_PIN, NOTE_C7, tempo); // Play thisNote for noteDuration.
       move(1,0);
    }
 //Btn7     0x42     
    if((ir.keyPressed(66))){
        btnExec = IR_BUTTON_7;
        Serial.println("Press 7.");
       // int catchRow = 
       move(3,pedal_med);
       myHappyBirthdaySong.play();
     //   Serial.println("Tune Array: " + catchRow);
       move(3, pedal_stop);
     }
    
//Btn8    0x52   
    if((ir.keyPressed(82))){
       btnExec = IR_BUTTON_8;
       Serial.println("Press 8.");
       move(4,pedal_med);
       myShave_Haircut.play();
       delay(skip * 4);  
       move(3,pedal_med);
       myShave_Haircut.play();
       move(3, pedal_stop);
     }
   
//Btn9  0x4a  
    if((ir.keyPressed(74))){
       btnExec = IR_BUTTON_9;
       Serial.println("Press 9.");
       move(4,pedal_med);
       myTwinkle.play();
       move(4, pedal_stop);
     } 
     
    switch(btnExec)
    {
       case IR_BUTTON_A: Serial.println("Press A."); break;
       case IR_BUTTON_B: Serial.println("Press B."); break;
       case IR_BUTTON_C: Serial.println("Press C."); break;
       case IR_BUTTON_D: Serial.println("Press D."); break;
       case IR_BUTTON_E: Serial.println("Press E."); break;
       case IR_BUTTON_F: Serial.println("Press F."); break;
       case IR_BUTTON_SETTING: Serial.println("Press Setting."); break;
       case IR_BUTTON_UP: Serial.println("Press Up."); break;
       case IR_BUTTON_DOWN: Serial.println("Press Down."); break;
       case IR_BUTTON_LEFT: Serial.println("Press Left."); break;
       case IR_BUTTON_RIGHT: Serial.println("Press Right."); break;
       case IR_BUTTON_0: Serial.println("Press 0."); break;
       case IR_BUTTON_1: Serial.println("Press 1."); break;
       case IR_BUTTON_2: Serial.println("Press 2."); break;
       case IR_BUTTON_3: Serial.println("Press 3."); break;
       case IR_BUTTON_4: Serial.println("Press 4."); break;
       case IR_BUTTON_5: Serial.println("Press 5."); break;
       case IR_BUTTON_6: Serial.println("Press 6."); break;
       case IR_BUTTON_7: Serial.println("Press 7."); break;
       case IR_BUTTON_8: Serial.println("Press 8."); break;
       case IR_BUTTON_9: Serial.println("Press 9."); break;
       default: //Serial.println("Default."); 
       break;
    }// end switch
    btnExec = 0;
    _loop();
}


void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}



void _loop(){
   ir.loop();
}

