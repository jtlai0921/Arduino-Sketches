#include <Password.h> 
#include <Keypad.h> 
#include <Servo.h>

Servo myservo;
Password password = Password( "2468" );

const byte ROWS = 4; // Four rows
const byte COLS = 4; //  columns
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = { 9,8,7,6 };
// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[COLS] = { 5,4,3,2, };
// Connect keypad COL0, COL1 and COL2 to these Arduino pins.
// Create the Keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
void setup(){
  Serial.begin(9600);
    delay(200);
  pinMode(11, OUTPUT);  //green light
  pinMode(12, OUTPUT);  //red light
  myservo.attach(13); //servo on digital pin 13
  keypad.addEventListener(keypadEvent); 
  //add an event listener for this keypad
}
void loop(){
  keypad.getKey();
  myservo.write(0);
}
void keypadEvent(KeypadEvent eKey){
  switch (keypad.getState()){
    case PRESSED:
	Serial.print("Pressed: ");
	Serial.println(eKey);
	switch (eKey){
	  case '*': checkPassword(); break;
	  case '#': password.reset(); break;
	  default: password.append(eKey);
     }
  }
}
void checkPassword(){
  if (password.evaluate()){
    Serial.println("Success");
    //Add code to run if it works
    myservo.write(90); //servo movement 90 
    digitalWrite(11, HIGH);//turn on
    delay(500); //wait 5 seconds
    digitalWrite(11, LOW);// turn off
  }else{
    Serial.println("Wrong");
    //add code to run if it did not work
    myservo.write(0);
    digitalWrite(12, HIGH); //turn on
    delay(500); //wait 5 seconds
    digitalWrite(12, LOW);//turn off
  }
}
