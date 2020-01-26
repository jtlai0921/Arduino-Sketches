// Project 19 - DC Motor and Potentiometer
int potPin = 0;
int transistorPin = 9;
int potValue = 0;
// Analog in 0 connected to the potentiometer
// PWM Pin 9 connected to the base of the transistor
// value returned from the potentiometer
void setup() {
// set the transistor pin as output:
pinMode(transistorPin, OUTPUT);
}
void loop() {
// read the potentiometer, convert it to 0 - 255:
potValue = analogRead(potPin) / 4;
// use that to control the transistor:
analogWrite(transistorPin, potValue);
}
