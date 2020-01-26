int REDPin = 11;    // RED pin of the LED to PWM pin 11
int GREENPin = 10;  // GREEN pin of the LED to PWM pin 10
int BLUEPin = 9;    // BLUE pin of the LED to PWM pin 9
int brightness = 0; // LED brightness
int increment = 5;  // brightness increment
void setup()

{
  pinMode(REDPin, OUTPUT);
  pinMode(GREENPin, OUTPUT);
  pinMode(BLUEPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{

brightness = brightness + increment;// brightness for next loop
  if (brightness <= 0 || brightness >= 255)
  // reverse the direction of fade
  {
    increment = -increment;
  }
  
brightness = constrain(brightness, 0, 255);
  analogWrite(REDPin, brightness);
  analogWrite(GREENPin, brightness);
  analogWrite(BLUEPin, brightness);
  delay(20);  
  
// wait for 20 milliseconds to see the dimming effect

}
