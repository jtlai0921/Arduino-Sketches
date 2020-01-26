int setPins[] = {7,6,5,4,3};    // this sets the pins as outputs for the LEDs
int rows = 5;                   // this is the number of LED's
int columns = 5;                // this sets the number of columns
int numberOfFrames = 1;         // this sets the number of frames

int drawing[] = {1,0,0,0,1, 0,1,0,1,0, 0,0,1,0,0, 0,1,0,1,0, 1,0,0,0,1}; 
void setup()
{
for (int countPins = 0; countPins < rows; countPins++) {
pinMode(setPins[countPins], OUTPUT);
}
}
void loop()
{
for (int countFrames = 0; countFrames < numberOfFrames; countFrames++)
{
for (int countColumns = 0; countColumns < columns; countColumns++)
{
for (int countRows = 0; countRows < rows; countRows++)
{
if (drawing[countFrames*columns*rows + countColumns*rows + countRows] == 0)
{
digitalWrite(setPins[countRows], LOW);
} else {
digitalWrite(setPins[countRows], HIGH);
}
}
delay(5); // delay between showing each column in milliseconds
}
for (int countRows = 0; countRows < rows; countRows++)
{
digitalWrite(setPins[countRows], LOW);
}
delay(15); // delay between showing each frame.
}
delay(0); // delay between drawings. 
}
