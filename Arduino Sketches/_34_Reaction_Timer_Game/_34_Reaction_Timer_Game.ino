//Used a RGB LED with a common Anode (3 Cathodes: R, G, B)
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int LEDR = 8; // Red Led pin 8
int LEDB = 7; // Blue Led pin 7
int LEDGr = 6; // Green Led pin 6
int Button=1;
int COLOR; // variable Color
int Beep;
int PSE; // variable pause 
int TME; // Time
int RTME=0; // Reaction Time
void setup()
{
lcd.begin(16, 2); 
pinMode(LEDR, OUTPUT);
pinMode(LEDB, OUTPUT);
pinMode(LEDGr, OUTPUT);
pinMode(Button, INPUT);
digitalWrite(LEDR, LOW); // All lights are switched "on".
digitalWrite(LEDB, LOW);
digitalWrite(LEDGr, LOW);
}
void loop()
{
lcd.clear(); // Clear screen.
lcd.print("Hold Button to");
lcd.setCursor(0,1); // move to second line.
lcd.print("start.");
while (digitalRead(Button)==LOW) // The test does not start until the button is pushed (and held down).
{tone(13,1200,30);
delay(1400);
noTone(13);
}
lcd.clear();
digitalWrite(LEDR, HIGH); // switch off the "start"light.
digitalWrite(LEDB, HIGH);
digitalWrite(LEDGr, HIGH);
randomSeed(analogRead(0)); //Random noise from pin 0
COLOR = random(1,4); // Generate a random color.
PSE=random(500,1200); // Select a random pause between the lights (to increase the surprise effect).
while (COLOR!=1 && digitalRead(Button)==HIGH)// This loop is repeated while color is Green or Blue AND button is held down.
{
digitalWrite(LEDGr, HIGH);
digitalWrite(LEDB, HIGH);
delay(PSE);
randomSeed(analogRead(0));
Beep=random(1,4); // Select whether to beep or not (1 in 3 times).
PSE=random(750,1200); // Select a random pause between the lights (to increase the surprise effect).
if (Beep==1)
{tone(13,1600,350);
delay(750);
noTone(13);}
if (COLOR == 2)
{digitalWrite(LEDGr, LOW);}
if (COLOR == 3)
{digitalWrite(LEDB, LOW);}
delay(PSE);
randomSeed(analogRead(0));
COLOR = random(1,4);  // Select a random color.

}
if (COLOR == 1 && digitalRead(Button)==HIGH)// This loop is executed if the color is red.
{
digitalWrite(LEDGr, HIGH);
digitalWrite(LEDB, HIGH);
delay(PSE);
TME=millis(); // Time since this program has started (so Blue or Green loop included).
digitalWrite(LEDR, LOW);
while (digitalRead(Button)==HIGH)// This loop runs untill you have released the button, hence the reaction time.
{delay(1);}
lcd.display();
RTME=millis()-TME; // Time since Led is Red, hence reaction time.
lcd.print("Reaction Time:");
lcd.setCursor(0,1);
lcd.print(RTME);
}
if (COLOR != 1) // This step is executed if the color is NOT red but the Push button was released (wrong action). 
{
lcd.print("Released too");
lcd.setCursor(0,1); // move to second line.
lcd.print("soon !!!");
tone(13,3000,1500);
delay(500);
noTone(13);
}
while (digitalRead(Button)==LOW) // The test does not re-start until the button is pushed once.
{delay(10);}
digitalWrite(LEDR, LOW); // Resets all lights to begin again.
digitalWrite(LEDB, LOW);
digitalWrite(LEDGr, LOW);
lcd.clear();
lcd.print("Hold Button to");
lcd.setCursor(0,1);
lcd.print("start.");
int Time=0;
delay(1000);
}
