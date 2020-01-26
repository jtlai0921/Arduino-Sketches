#include  <LiquidCrystal.h> // Includes the library to use a LCD display
#define sensor 0        // Defines the A0 pin as “sensor”

int  Vin;   //  Variable to read the value from the Arduino’s pin
float  Temperature; //Variable that receives the converted voltage value to temp
float     TF; // Variable to receive the converted value in ºC 
LiquidCrystal  lcd    (12, 11, 5, 4, 3, 2); //pins used for controlling the LCD 
void  setup()
{
  lcd.begin(16, 2);//  This tells the Arduino that the display is a 16x2 type
  lcd.print("Temperature: "); //  Send the text to the screen of the display.
}
void  loop()
{
  Vin = analogRead (sensor); //Tells Arduino to read the pin & stores value in “Vin” 
  Temperature=(500*Vin)/1023;  /* Converts the voltage value into temperature and stores it into the “Temperature”  variable  (in  ºC)*/
  TF = Temperature; 
  lcd.setCursor(0, 1); // Moves  the cursor of the display to the next line
  lcd.print(TF);    // Shows the value of the temperature on the display
  lcd.print(" C"); // Writes “C” to indicate that it is in Centigrade scale.
  delay(1000);  //  Waits for a second to read the pin again
}
