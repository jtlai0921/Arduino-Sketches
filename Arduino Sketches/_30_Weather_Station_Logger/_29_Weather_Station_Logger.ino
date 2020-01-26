/* quick temp data logger
*/
// Variable declaration
int temperature = 0;  // variable to keep the actual value 
// Analog pin declaration
int TsensorPin = 1;  // temperature sensor pin
void setup() 
{ 
  Serial.begin(9600);
  pinMode(TsensorPin, INPUT);
} 
void loop() 
{ 
  temperature = analogRead(TsensorPin) * .512;
  Serial.print(temperature);
  Serial.println(",");
  delay(300000);
}
