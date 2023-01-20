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

// Constructor de buttonpush
  int buttonpin;
buttonpush(BUTTON_PARAMS *parameter){
  buttonpin = parameter->buttonpin;
}

bool states(){
  return digitalRead(buttonpin);
  }


};
