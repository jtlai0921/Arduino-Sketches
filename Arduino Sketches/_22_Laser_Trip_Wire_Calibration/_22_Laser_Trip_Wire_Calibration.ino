void setup() {
pinMode(4, OUTPUT);
Serial.begin(9600);
}
void loop(){
digitalWrite(4, HIGH);
Serial.println(analogRead(0));
}

