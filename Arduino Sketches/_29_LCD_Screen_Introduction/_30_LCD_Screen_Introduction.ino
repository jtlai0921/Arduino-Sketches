/*
  LiquidCrystal Library - scrollDisplayLeft() and scrollDisplayRight()
 
 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal library works with all LCD displays that are compatible with the Hitachi HD44780 driver. There are many of them out there, and you  can usually tell them by the 16-pin interface.
 
 This sketch prints "Arduino Sketch" to the LCD and uses the scrollDisplayLeft() and scrollDisplayRight() methods to scroll the text.
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7,8,9,10,11,12);

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Arduino Sketch");
  delay(1000);
}

void loop() {
  // scroll 13 positions (string length) to the left 
  // to move it offscreen left:
  for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft(); 
    // wait a bit:
    delay(150);
  }
  // scroll 29 positions (string length + display length) to the right
  // to move it offscreen right:
  for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayRight(); 
    // wait a bit:
    delay(150);
  }
    // scroll 16 positions (display length + string length) to the left
    // to move it back to center:
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft(); 
    // wait a bit:
    delay(150);
  }
  // delay at the end of the full loop:
  delay(1000);
}
