const int analogInPin = A0; 
// Analog pin pot is attached to
int sensorValue = 0; // value read from pot
int timer = 0; // delay value
void setup() {
//digital pin 12, 11 as an output.
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}
void loop() {
sensorValue = analogRead(analogInPin);
//delay between 10ms to 500ms
timer = map(sensorValue, 0, 1023, 10, 500);
  digitalWrite(12, HIGH);
  delay(timer);
  digitalWrite(12, LOW);
  delay(timer);
  digitalWrite(12, HIGH);
  delay(timer);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  delay(timer);
  digitalWrite(11, LOW);
  delay(timer);
  digitalWrite(11, HIGH);
  delay(timer);
  digitalWrite(11, LOW);
}
