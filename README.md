# simon-says-joystick-
In this project, using Arduino, I have created a simple Simon Says game with a joystick as the input.

The Coding Part:
Using a random number generator function, I light up one of four LEDs at a time. The input is taken through the joystick, and then I compare if the input matches or not. A green light is shown if it is correct, and a red light for incorrect. To reset the game, we use the switch on the joystick.

The Hardware:
A standard Arduino Uno (ATmega328P) is used, along with a knock-off PS2 joystick. For output, four LEDs represent the direction in which the joystick has to point, and two other LEDs are used—one for correct input and another for incorrect input. I will try to upload a picture of the connections.

Problems/Drawbacks:
At the moment, I can only take one input, and I have to be very fast. I don't know how to stop the loop until I give the input.
