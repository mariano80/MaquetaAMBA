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
  bool moreOneServo;
  bool pushed;
  int servoManaged1;
  int servoManaged2;
  };

class buttonpush {

public:

// Constructor de buttonpush
  int buttonpin;
  bool moreOneServo;
  bool pushed;
  int servoManaged;
  int servoManaged1;
  int servoManaged2;
buttonpush(BUTTON_PARAMS *parameter){
  buttonpin = parameter->buttonpin;
  moreOneServo = parameter->moreOneServo;
  pushed = parameter->pushed;
  servoManaged1 = parameter->servoManaged1;
  servoManaged2 = parameter->servoManaged2;
}

bool states(){
  return digitalRead(buttonpin);
  }

bool mgdServo(){
  return moreOneServo;
  }

};
