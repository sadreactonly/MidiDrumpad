#ifndef Buttons_h
#define Buttons_h

#include <Arduino.h>

//Button (Pin Number, Note Number)
class Button
{
  public:
    Button(int pin, short note);
    int getButtonState();
    int lastState();
    int Note;
   
  private:
    int _pin;
    short _note;
    int _state;
    int _lastState;
};

#endif
