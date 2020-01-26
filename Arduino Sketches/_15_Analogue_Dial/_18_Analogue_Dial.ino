#include <Servo.h>    
Servo myservo;
int pos = 0; 
int lightPin = 0;
     
void setup() {
        
myservo.attach(9); // servo to pin 9
}
     
void loop() { // start a loop
// next line reads the voltage 
int lightLevel = analogRead(lightPin); 

// this analog pin has 1024 values
lightLevel = map(lightLevel, 0, 1023, 0, 359);
pos = constrain(lightLevel, 0, 359);
       
myservo.write(pos); // sets the servo angle
delay(100);
}
