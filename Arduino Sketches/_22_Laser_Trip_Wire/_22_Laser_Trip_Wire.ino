//Laser trip wire sketch


int buzzPin = 11; // Buzzer pin 11
int LED = 13;// LED pin 13

void setup() {
pinMode(buzzPin, OUTPUT);// sets pin as output
pinMode(LED, OUTPUT);// sets pin as output
}

void loop(){
if(analogRead(0) > 850){ // this number depends on calibration of the photocell

digitalWrite(buzzPin, HIGH);
digitalWrite(LED,HIGH);

delay(1000); // waits for 1 second
digitalWrite(buzzPin,LOW);
digitalWrite(LED,HIGH);

} else{
digitalWrite(buzzPin,LOW);
digitalWrite(LED,LOW);
}
}
