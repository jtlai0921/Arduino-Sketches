const int analogPin = A0; // the pin that the potentiometer is attached 
const int ledCount = 9; // the number of LEDs
int ledPins[] = {2,3,4,5,6,7,8,9,10}; // pins that LEDs are attached to
void setup() { 
for (int thisLed = 0; thisLed < ledCount; thisLed++) {
pinMode(ledPins[thisLed], OUTPUT); // sets the led pins as an output 
}
}
void loop() { //  starts a loop
int sensorReading = analogRead(analogPin);  // analog input
int ledLevel = map(sensorReading, 0, 1023, 0, ledCount);
for (int thisLed = 0; thisLed < ledCount; thisLed++) {
if (thisLed < ledLevel) {
digitalWrite(ledPins[thisLed], HIGH); // turns LEDs on in sequence
} 
else {
digitalWrite(ledPins[thisLed], LOW); // turns LEDs off in sequence
}
}
}
