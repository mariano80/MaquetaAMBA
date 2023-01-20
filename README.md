# Arduino sketch for using n servos as Model Railroad turnouts 

## Table of contents
* [General info](#general-info)
* [Technologies](#technologies)
* [Setup](#setup)
* [Logic](#logic)


### General info
This project is simple sketch to use a SG90 servo as Model Railroad turnout. It has a
debounce protection and an adaptation to move two servo with one pushbutton.

The turnouth.h library is an adaptation of original made by Robin Simonds, theNscaler.com

### Technologies
This project was tested in Arduino nano, but you can easily user another arduino board.

	
### Setup
To run this project, install it on a Arduino Nano and monitor de Serial:

### Logic

-> Get Milliseconds
-> run update method on all turnouts
-> read buttons
-> if a button[i] == HIGH call turnout[i].toggle()