///////////////////////////////////////
// CLASS buttonpush
// A button device C++ class for use in
// command servos in AMBA ModelRailroad layout
// Author: Mariano C. Ucha
// License: CC BY-SA 4.0
// https://creativecommons.org/licenses/by-sa/4.0/
//
// Class declaration and implementation
///////////////////////////////////////

struct BUTTON_PARAMS {
  int buttonpin;
  };

class buttonpush {

public:

int buttonState;            // the current reading from the input pin
int lastButtonState = LOW;  // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

// Constructor de buttonpush
  int buttonpin;
buttonpush(BUTTON_PARAMS *parameter){
  buttonpin = parameter->buttonpin;
}

bool states(){
  return digitalRead(buttonpin);
  }


};
