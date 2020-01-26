#include <Servo.h>  // use the servo library
#include <IRremote.h> // use the IR remote library

unsigned long Value1 = 0xFFA05F; // change this to your value
unsigned long Value2 = 0xFF50AF; // change this to your value
unsigned long value3 = 0xFF807F; // change this to your value
unsigned long value4 = 0xFF609F; // change this to your value
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

Servo servo1;
Servo servo2;

void setup() {       // the setup routine runs once        

Serial.begin(9600);
  irrecv.enableIRIn(); // Start the IR receiver

 servo1.attach(10); // attach servo 1 to digital pin 10
servo2.attach(9); // attach servo 2 to digital pin 9
}
void loop() { // the loop routine runs forever

if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
if(results.value == Value1) { 
// if the remote code matches value 1, then move the servo
servo1.write(160);
}
else if  (results.value == Value2){
servo1.write(70);
} 
else if  (results.value == value3){
  servo2.write(70);
}
else if  (results.value == value4){
  servo2.write(160);
}
} 
