# simon-says-joystick-
In this project using audrino i have created a simple simon says game with a joystick as input 

The coding part:

Using a random number generator funtion i light up 1 of 4 led at a time them input is taken through joystic and then i compare if the input is 
matching or not and give a green light if it is coorect or red for incorrect.To reset the game we use the switch in the joystick.

The hardware:

A standard Arduino Uno(ATmega328P) is used and knock off PS2 joystick are connected then for output 4 leds to represent the side at which the joystick has to point 
and 2 other leds one for correct input and other for incorrect.
i will try to upload a pic of the connections.

Problems/Drawbacks:

At the moment i can only take 1 input that too i have to be very fast,i don't know how to stop the loop till i give the input.
