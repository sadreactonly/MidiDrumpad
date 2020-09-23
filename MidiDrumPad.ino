// Notes
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

// Button pins
const int buttonPin3 = 2;     
const int buttonPin2 = 3; 
const int buttonPin1 = 4; 

const int buttonPin6 = 5;     
const int buttonPin5 = 6; 
const int buttonPin4 = 7;

const int buttonPin9 = 8;  
const int buttonPin8 = 9; 
const int buttonPin7 = 10;

// variables for reading the pushbutton status
int buttonState1 = 1;         
int buttonState2 = 1;
int buttonState3 = 1;    
int buttonState4 = 1;         
int buttonState5 = 1;
int buttonState6 = 1;   
int buttonState7 = 1;         
int buttonState8 = 1;
int buttonState9 = 1;

// variables for reading the pushbutton last remebered status
int buttonLastState1 = 1;         
int buttonLastState2 = 1;
int buttonLastState3 = 1;    
int buttonLastState4 = 1;         
int buttonLastState5 = 1;
int buttonLastState6 = 1;   
int buttonLastState7 = 1;         
int buttonLastState8 = 1;
int buttonLastState9 = 1;


void setup() {
  Serial.begin(9600);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin5, INPUT_PULLUP);
  pinMode(buttonPin6, INPUT_PULLUP);
  pinMode(buttonPin7, INPUT_PULLUP);
  pinMode(buttonPin8, INPUT_PULLUP);
  pinMode(buttonPin9, INPUT_PULLUP);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  buttonState5 = digitalRead(buttonPin5);
  buttonState6 = digitalRead(buttonPin6);
  buttonState7 = digitalRead(buttonPin7);
  buttonState8 = digitalRead(buttonPin8);
  buttonState9 = digitalRead(buttonPin9);

  //Check state for every button
  checkState(buttonState1, &buttonLastState1, 1);
  checkState(buttonState2, &buttonLastState2, 2);
  checkState(buttonState3, &buttonLastState3, 3);
  checkState(buttonState4, &buttonLastState4, 4);
  checkState(buttonState5, &buttonLastState5, 5);
  checkState(buttonState6, &buttonLastState6, 6);
  checkState(buttonState7, &buttonLastState7, 7);
  checkState(buttonState8, &buttonLastState8, 8);
  checkState(buttonState9, &buttonLastState9, 9);
}


// Check the status and depending on the value, send a MIDI message
void checkState(int btnState, int*lastButtonState, unsigned short btnNum){

// Check if previous state and current state are different. If is different, we can send notes.
 if (btnState != *lastButtonState) {
 // If button state is LOW, then button is pressed.
  if (btnState == LOW) {
    //Check whitch button is pressed and send MIDI NOTE ON
        switch(btnNum)
        {
          case 1:
           midiNoteOn(NOTE_ONE,MAX_MIDI_VELOCITY);
            break;
          case 2:
            midiNoteOn(NOTE_TWO,MAX_MIDI_VELOCITY);
            break;
          case 3:
            midiNoteOn(NOTE_THREE,MAX_MIDI_VELOCITY);
            break;
          case 4:
            midiNoteOn(NOTE_FOUR,MAX_MIDI_VELOCITY);
            break;
          case 5:
            midiNoteOn(NOTE_FIVE,MAX_MIDI_VELOCITY);
            break;
          case 6:
            midiNoteOn(NOTE_SIX,MAX_MIDI_VELOCITY);
            break;
          case 7:
            midiNoteOn(NOTE_SEVEN,MAX_MIDI_VELOCITY);
            break;
          case 8:
           midiNoteOn(NOTE_EIGHT,MAX_MIDI_VELOCITY);
            break;
          case 9:
            midiNoteOn(NOTE_NINE,MAX_MIDI_VELOCITY);
            break;
        }
  }
  else {
    //Check whitch button is pressed and send MIDI NOTE OFF
       switch(btnNum)
        {
            case 1:
            midiNoteOff(NOTE_ONE,MAX_MIDI_VELOCITY);
            break;
          case 2:
            midiNoteOff(NOTE_TWO,MAX_MIDI_VELOCITY);
            break;
          case 3:
            midiNoteOff(NOTE_THREE,MAX_MIDI_VELOCITY);
            break;
          case 4:
            midiNoteOff(NOTE_FOUR,MAX_MIDI_VELOCITY);
            break;
          case 5:
            midiNoteOff(NOTE_FIVE,MAX_MIDI_VELOCITY);
            break;
          case 6:
            midiNoteOff(NOTE_SIX,MAX_MIDI_VELOCITY);
            break;
          case 7:
            midiNoteOff(NOTE_SEVEN,MAX_MIDI_VELOCITY);
            break;
          case 8:
           midiNoteOff(NOTE_EIGHT,MAX_MIDI_VELOCITY);
            break;
          case 9:
            midiNoteOff(NOTE_NINE,MAX_MIDI_VELOCITY);
            break;
        }
  }  
    delay(50);
  }

  // Set button last state
  *lastButtonState = btnState;
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
