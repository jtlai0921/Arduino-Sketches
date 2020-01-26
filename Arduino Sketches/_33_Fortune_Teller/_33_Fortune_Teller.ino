#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;
 
void setup() {
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  lcd.print("FORTUNE TELLER");
 
  lcd.setCursor(0, 1);
  lcd.print("Ask a Question");
}
  void loop() {
    switchState = digitalRead(switchPin);
    if(switchState != prevSwitchState) {
      if(switchState == LOW) {
        reply = random(8);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("The answer is: ");
        lcd.setCursor(0, 1);
       
        switch(reply) {
          case 0:
          lcd.print("Yes");
          break;
         
          case 1:
          lcd.print("Probably");
          break;
         
          case 2:
          lcd.print("Definately");
          break;
         
          case 3:
          lcd.print("Don't be silly");
          break;
         
          case 4:
          lcd.print("Of course");
          break;
         
          case 5:
          lcd.print("Ask again");
          break;
         
          case 6:
          lcd.print("Doubtful");
          break;
         
          case 7:
          lcd.print("No");
          break;    
        }
      }
    }
       prevSwitchState = switchState;
  }
