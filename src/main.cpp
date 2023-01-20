#include <Arduino.h>
#include <turnout.h>
#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>
#include <buttonpush.h>
#define ADAF_DRIVER
#define NUM_TURNOUTS 4
#define STANDARD_DELAY 50
#define NUM_BUTTON 4

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

turnout *turnouts[NUM_TURNOUTS];
buttonpush *buttonspush[NUM_BUTTON];

TURNOUT_PARAMS tdef[NUM_TURNOUTS] = {
 {0, 200, 215, ALIGN_MAIN, STANDARD_DELAY},
 {1, 200, 215, ALIGN_MAIN, STANDARD_DELAY},
 {2, 180, 215, ALIGN_MAIN, STANDARD_DELAY},
 {3, 200, 228, ALIGN_MAIN, STANDARD_DELAY},
 };

BUTTON_PARAMS bdef[NUM_BUTTON] = {
 {4},
 {5},
 {6},
 {7}
 };

unsigned long lastDebounceTime = 0; // The last time the output pin was toggled. Initial value 0
unsigned long debounceDelay = 200;    // the debounce time; increase if the output flickers. Initial value 200
bool lastButtonState = true;   // Estado inicial del boton. Initial value true

void setup() {
    
for (int i = 0; i < NUM_TURNOUTS; i++){ 
    turnouts[i] = new turnout(&tdef[i]); 
    }

for (int i = 0; i < NUM_TURNOUTS; i++){ 
    turnouts[i]->initialize(); 
    }

for (int x = 0; x < NUM_BUTTON; x++){ 
    buttonspush[x] = new buttonpush(&bdef[x]); 
    }

for (int x = 0; x < NUM_BUTTON; x++){ 
    pinMode(buttonspush[x]->buttonpin, INPUT_PULLUP); 
    }


pwm.begin();
pwm.setPWMFreq(50); // Analog servos run at ~60 Hz updates
Serial.begin(9600);
Serial.println("Comienzo a funcionar el sistema de Servos x Arduino y PCA9685");


}

void loop() {

unsigned long currentMilis = millis();


// turnouts[0]->update(currentMilis);
// turnouts[1]->update(currentMilis);
for (int i = 0; i < NUM_TURNOUTS; i++){ 
    turnouts[i]->update(currentMilis); 
    }

for (int w = 0; w < NUM_BUTTON; w++) {
      if (millis() - lastDebounceTime > debounceDelay) {
      bool buttonState = buttonspush[w]->states();
        if (buttonState != lastButtonState) {
          lastDebounceTime = millis();
          lastButtonState = buttonState;
          Serial.println("Detecte un boton");
          Serial.println(w, DEC);
          turnouts[w]->toggle();
          if (buttonState == true) {
          // do an action, for example print on Serial
            Serial.println("Button released");
          }
      }
}



    
//    if (buttonspush[w]->states() == false)
//    {
//        Serial.println("Detecte un boton");
//        Serial.println(w, DEC);
//        turnouts[w]->toggle();
//    }
       
}

}
