#include <SPI.h>
#include <RFID.h>
#include <Servo.h>
#include "pitches.h"
#include <LiquidCrystal_I2C.h> optional to add a serial LCD screen
#include <Wire.h>

// This defines the RFID
RFID rfid(10,5);

byte card[5] = {0x4D,0x55,0xAD,0xD3,0x66}; 
// This is the code in HEX form from your card
// This is where you list the cards that can access

// This defines the LCD screen
LiquidCrystal_I2C lcd(0x27,20,4);	//You can add a serial LCD screen 

byte serNum[5];
byte data[5];

// This plays the melodies, first one is correct access, second fail
int access_melody[] = {NOTE_G4,0,NOTE_A4,0, NOTE_B4,0,NOTE_A4,0,NOTE_B4,0, NOTE_C5,0};
int access_noteDurations[] = {8,8,8,8,8,4,8,8,8,8,8,4};
int fail_melody[] = {NOTE_G2,0,NOTE_F2,0,NOTE_D2,0};
int fail_noteDurations[] = {8,8,8,8,8,4};

// This defines the pins for the LEDs piezo and servo
int LED_access = 2;
int LED_intruder = 3;
int speaker_pin = 8;
int servoPin = 9;

// Defines the servo motor
Servo doorLock;

  void setup(){
  doorLock.attach(servoPin); 	// set servo as a pin
  Serial.begin(9600); 		// start serial communication
  lcd.init(); 			// initialise the LCD
  lcd.backlight();
  lcd.clear();			// clear LCD
  SPI.begin(); // Start serial communication with the RFID to your PC
  rfid.init(); // initialise the RFID
  Serial.println("Arduino card reader");
  delay(1000);
  pinMode(LED_access,OUTPUT);
  pinMode(LED_intruder,OUTPUT);
  pinMode(speaker_pin,OUTPUT);
  pinMode(servoPin,OUTPUT);
}
 
void loop(){
  lcd.clear();
  lcd.noBacklight();
  // Create a variable for each user
   boolean card_card = true; // Mark's card
  
  if (rfid.isCard()){ 
    if (rfid.readCardSerial()){ 
      delay(1000);
      data[0] = rfid.serNum[0]; 
      data[1] = rfid.serNum[1];
      data[2] = rfid.serNum[2];
      data[3] = rfid.serNum[3];
      data[4] = rfid.serNum[4];
    }
  
  //rfid.halt(); // RFID standby
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("   ID Found:");
  Serial.print("Card found - code:");
  lcd.setCursor(0,1);
  lcd.print("     ");
  if(data[0] < 16){
    lcd.print("0");
  }
  lcd.print(data[0],HEX);
  
  if(data[1] < 16){
    lcd.print("0");
}
  lcd.print(data[1],HEX);
  
  if(data[2] < 16){
    lcd.print("0");
  }
  lcd.print(data[2],HEX);
  
  if(data[3] < 16){
    lcd.print("0");
  }
  lcd.print(data[3],HEX);
  
  if(data[4] < 16){
    lcd.print("0");
  }
     lcd.print(data[4],HEX);
  for(int i=0; i<5; i++){
    if(data[i] != card[i]) card_card = false; 
			// if it is not marks card then its false
    			// you would list the other cards here
  }
  Serial.println();
  if (card_card){ 			// a card is found
    lcd.setCursor(0,2);
    lcd.print("    Hello Mark!");
    Serial.println("Hello Mark!"); // print message
    for (int i = 0; i < 12; i++){ 	// plays welcome music
      int access_noteDuration = 1000/access_noteDurations[i];
      tone(speaker_pin, access_melody[i],access_noteDuration);
      int access_pauseBetweenNotes = access_noteDuration * 1.30;
      delay(access_pauseBetweenNotes);
      noTone(speaker_pin);
    }
  }
  
  else{ 					// if card is unknown
    lcd.setCursor(0,2);
    lcd.print(" ID not recognised!");
    lcd.setCursor(0,3);
    lcd.print("   Access Denied!");
    Serial.println("Card not recognised!  Contact administrator!"); 
    						// prints message
  
digitalWrite(LED_intruder, HIGH); 	// turns on red LED
    for (int i = 0; i < 6; i++){ 	// plays intruder melody
      int fail_noteDuration = 1000/fail_noteDurations[i];
      tone(speaker_pin, fail_melody[i],fail_noteDuration);
      int fail_pauseBetweenNotes = fail_noteDuration * 1.30;
      delay(fail_pauseBetweenNotes);
      noTone(speaker_pin);
    }
    delay(1000);
    digitalWrite(LED_intruder, LOW); // Red LED goes off
  }
  if (card_card){			// add other users allowed access here
      
    lcd.setCursor(0,2);
    lcd.print("  Access granted!");
    lcd.setCursor(0,3);
    lcd.print("   Welcome!");
    Serial.println("Access granted.......Welcome!");
    digitalWrite(LED_access,HIGH); // turns green LED on
    doorLock.write(180); 		// Turns the Servo to open door
    delay(5000); 				// waits for 5 seconds
    doorLock.write(0); 			// closes the door
    digitalWrite(LED_access,LOW); 	// turns off green LED
  }
  Serial.println();
  delay(500);
  rfid.halt();
  lcd.noBacklight();
  }
}
