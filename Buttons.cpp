#include "Buttons.h"

Button::Button(int pin, short note)
{
  _pin = pin;
  pinMode(_pin, INPUT_PULLUP);
  _state = 1;
  _lastState = 1;
  Note = note;
}


int Button::getButtonState()
{
   int returnValue = -1;
   int state = digitalRead(_pin);
    
    if(state == _lastState)
      return 5;
   if(state!= _lastState)
   {
        if(state == 0)
         {
            returnValue = 0;       
         }
         else
         {
            returnValue = 1;
         }
   }

   _lastState = state;

   return returnValue;
}
int Button::lastState(){
  return _lastState;
}
/*
 *  if(_state != _lastState)
  {
      if(_state == LOW) {
        return true;
      }
      else
      {
        return false;
      }
  }
 _lastState = _state;
 */
