const int latchPin = 8;   // Arduino pins used to interface to 74HC595
const int clockPin = 12;
const int dataPin = 11;
const int buttonPin = 2;  // Arduino pin interfaced to switch
                          // 1 to 6 and DP (decimal point) on 7-seg display
unsigned char lookup_7seg[] = {0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x80};
unsigned char shake_dice[] = {0x63, 0x5C};// shaking dice pattern on 7-seg display
unsigned char roll_dice[] = {0x1C, 0x58, 0x54, 0x4C};// rolling dice on 7-seg display
int rand_seed;                     // used for variable dice throw duration
int rand_num = 0;                  // random number generated
unsigned char shake_toggle = 0;    // for shaking dice animation
int index = 0;                     // for rolling dice animation
int shake_speed;                   // accelerates dice shake speed
void setup() {
  pinMode(latchPin, OUTPUT); // output pins for controlling the 74HC595
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(buttonPin, INPUT); // pin for reading button state
  digitalWrite(latchPin, LOW);// display DP on seven-seg display at startup
  shiftOut(dataPin, clockPin, MSBFIRST, lookup_7seg[6]);
  digitalWrite(latchPin, HIGH);
  randomSeed(analogRead(0)); // generate random seed
}
void loop() {
  if (digitalRead(buttonPin)) {
    shake_speed = 150;       // reset dice shaking speed
    delay(30);               // debounce switch
    // generate number to use for random seed and show animated shaking dice
    while (digitalRead(buttonPin)) {
      rand_seed++;           // for generating random number

if (shake_toggle) {          // animate shaking dice  
AnimateDice(0, shake_dice);
shake_toggle = 0;
}
else {
AnimateDice(1, shake_dice);
shake_toggle = 1;
}
delay(80 + shake_speed);     // accelerating animation speed
if (shake_speed > 0) {
shake_speed -= 10;
}
}
for (int rolls = 0; rolls < (rand_seed % 10 + 14); rolls++) {  // animate rolling dice
AnimateDice(index, roll_dice);
delay((1 + rolls) * 20);
index++;
if (index > 3) {
index = 0;
}
}
rand_num = random(0, 6); // generate and display number thrown on dice
DiceNumber(rand_num);
}
}
void DiceNumber(unsigned char num)  // displays the dice number on the 7-seg display
{
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, lookup_7seg[num]);
digitalWrite(latchPin, HIGH);
}
void AnimateDice(int seg, unsigned char *table)// displays one frame of the shaking or rolling dice 
{
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, table[seg]);
digitalWrite(latchPin, HIGH);
}
