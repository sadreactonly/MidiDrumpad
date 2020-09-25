#include "Buttons.h"

//------Notes-------------
#define NOTE_ONE 36
#define NOTE_TWO 37
#define NOTE_THREE 38
#define NOTE_FOUR 39
#define NOTE_FIVE 40
#define NOTE_SIX 41
#define NOTE_SEVEN 42
#define NOTE_EIGHT 43
#define NOTE_NINE 44

#define NOTE_ON_CMD 0x90
#define NOTE_OFF_CMD 0x80
#define MAX_MIDI_VELOCITY 127

//------------------------

int NUMBER_BUTTONS = 9;

Button Button1(4, NOTE_ONE);
Button Button2(3, NOTE_TWO);
Button Button3(2, NOTE_THREE);
Button Button4(7, NOTE_FOUR);
Button Button5(6, NOTE_FIVE);
Button Button6(5, NOTE_SIX);
Button Button7(10, NOTE_SEVEN);
Button Button8(9, NOTE_EIGHT);
Button Button9(8, NOTE_NINE);

Button *Buttons[] {&Button1,&Button2,&Button3,&Button4,&Button5,&Button6,&Button7,&Button8,&Button9};


int red_light_pin= 11;
int green_light_pin = 12;
int blue_light_pin = 13;


void setup() {
   Serial.begin(9600);
}

void loop() {
  if (NUMBER_BUTTONS != 0) updateButtons();
}

void updateButtons() {

  for (int i = 0; i < NUMBER_BUTTONS; i++) {
      int state = Buttons[i]->getButtonState();
      
      //  Button is pressed     
      if (state == 0) 
      {
         midiNoteOn(Buttons[i]->Note,127);
      }
  
      //  Button is not pressed
      if (state == 1) 
  	  {
  		   midiNoteOff(Buttons[i]->Note,0); 
      }
  }
}


void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}

// Send MIDI note ON
void midiNoteOn(byte note, byte midiVelocity)
{
  Serial.write(NOTE_ON_CMD);
  Serial.write(note);
  Serial.write(midiVelocity);
}

//Send MIDI note OFF
void midiNoteOff(byte note, byte midiVelocity)
{
  Serial.write(NOTE_OFF_CMD);
  Serial.write(note);
  Serial.write(midiVelocity);
}
