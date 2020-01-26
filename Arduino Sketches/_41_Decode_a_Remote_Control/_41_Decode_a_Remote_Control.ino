#include <IRremote.h> // use the library
int receiver = 11; // 
IRrecv irrecv(receiver);
decode_results results;
void setup()
{
Serial.begin(9600); // for serial monitor 
irrecv.enableIRIn(); // Start the receiver
}
void loop() 
{
if (irrecv.decode(&results)) //
{
Serial.println(results.value, HEX); 
// display it on serial monitor in hexadecimal
irrecv.resume(); // receive the next value
}
}
