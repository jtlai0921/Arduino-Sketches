
int latchpin = 8; // connect to pin 12 on the '595
int clockpin = 10; // connect to pin 11 on the '595
int datapin = 12; // connect to pin 14 on the '595
int zz = 500; // delay variable
int va[]={
  1,2,4,8,16,32,64,128,255};
int va2[]={
  1,3,7,15,31,63,127,255};
void setup()
{
  pinMode(latchpin, OUTPUT);
  pinMode(clockpin, OUTPUT);
  pinMode(datapin, OUTPUT);
  digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, MSBFIRST, 0);
  shiftOut(datapin, clockpin, MSBFIRST, 0);
  shiftOut(datapin, clockpin, MSBFIRST, 0);
  shiftOut(datapin, clockpin, MSBFIRST, 0);
  digitalWrite(latchpin, HIGH);
  randomSeed(analogRead(0));  
}
void allRed() // 
// turns on all RED 
{
  digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, MSBFIRST, 255); // cathodes
  shiftOut(datapin, clockpin, MSBFIRST, 0); // green
  shiftOut(datapin, clockpin, MSBFIRST, 0); // blue
  shiftOut(datapin, clockpin, MSBFIRST, 255); // red
  digitalWrite(latchpin, HIGH);
}
void allBlue() //  
// turns on all blue 
{
  digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, MSBFIRST, 255); // cathodes
  shiftOut(datapin, clockpin, MSBFIRST, 0); // green
  shiftOut(datapin, clockpin, MSBFIRST, 255); // blue
  shiftOut(datapin, clockpin, MSBFIRST, 0); // red
  digitalWrite(latchpin, HIGH);
}
void allGreen()  // 
// turns on all green
{
  digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, MSBFIRST, 255); // cathodes
  shiftOut(datapin, clockpin, MSBFIRST, 255); // green
  shiftOut(datapin, clockpin, MSBFIRST, 0); // blue
  shiftOut(datapin, clockpin, MSBFIRST, 0); // red
  digitalWrite(latchpin, HIGH);
}
void allOn() // 
// turns on all LEDs. Only use if power supply adequate!!
{
  digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, MSBFIRST, 255); // cathodes
  shiftOut(datapin, clockpin, MSBFIRST, 255); // green
  shiftOut(datapin, clockpin, MSBFIRST, 255); // blue
  shiftOut(datapin, clockpin, MSBFIRST, 255); // red
  digitalWrite(latchpin, HIGH);
}

void allYellow() // 
{
  digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, MSBFIRST, 255); // cathodes
  shiftOut(datapin, clockpin, MSBFIRST, 255); // green
  shiftOut(datapin, clockpin, MSBFIRST, 0); // blue
  shiftOut(datapin, clockpin, MSBFIRST, 255); // red
  digitalWrite(latchpin, HIGH);
}
void allAqua() // 
{
  digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, MSBFIRST, 255); // cathodes
  shiftOut(datapin, clockpin, MSBFIRST, 255); // green
  shiftOut(datapin, clockpin, MSBFIRST, 255); // blue
  shiftOut(datapin, clockpin, MSBFIRST, 0); // red
  digitalWrite(latchpin, HIGH);
}
void allPurple() // 
{
  digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, MSBFIRST, 255); // cathodes
  shiftOut(datapin, clockpin, MSBFIRST, 0); // green
  shiftOut(datapin, clockpin, MSBFIRST, 255); // blue
  shiftOut(datapin, clockpin, MSBFIRST, 255); // red
  digitalWrite(latchpin, HIGH);
}

void clearMatrix() 
{
  digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, MSBFIRST, 0); // cathodes
  shiftOut(datapin, clockpin, MSBFIRST, 0); // green
  shiftOut(datapin, clockpin, MSBFIRST, 0); // blue
  shiftOut(datapin, clockpin, MSBFIRST, 0); // red
  digitalWrite(latchpin, HIGH);
}

void lostinspace()
// warning! warning! blinkiness ahead!
{
  for (int z=0; z<100; z++)
  {
    digitalWrite(latchpin, LOW);
    shiftOut(datapin, clockpin, MSBFIRST, va[random(8)]); // cathodes
    shiftOut(datapin, clockpin, MSBFIRST, va[random(8)]); // green
    shiftOut(datapin, clockpin, MSBFIRST, va[random(8)]); // blue
    shiftOut(datapin, clockpin, MSBFIRST, va[random(8)]); // red
    digitalWrite(latchpin, HIGH);
    delay(100);
  }
}
void displayLEDs(int rr, int gg, int bb, int cc, int dd)
// inserts the base-10 values into the shiftOut functions, and holds the display 
// for dd milliseconds
{
  digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, MSBFIRST, cc); // cathodes
  shiftOut(datapin, clockpin, MSBFIRST, gg); // green
  shiftOut(datapin, clockpin, MSBFIRST, bb); // blue
  shiftOut(datapin, clockpin, MSBFIRST, rr); // red
  digitalWrite(latchpin, HIGH);
  delay(dd);
}

void loop()
{
  // first, light up the whole display in solid colours
  allOn();
  delay(zz);

  delay(zz);
  allRed();
  delay(zz);

  delay(zz);  
  allGreen();
  delay(zz);

  delay(zz);
  allBlue();
  delay(zz);

  delay(zz);
  allPurple();
  delay(zz);

  delay(zz);
  allYellow();
  delay(zz);

  delay(zz);
  allAqua(); 
  delay(1000);
  // now, just some individual LEDs, using random values
  lostinspace(); // :)
  // scroll some horizontal and vertical lines
  for (int z=0; z<5; z++)
  {
    for (int q=1; q<129; q*=2)
    {
      displayLEDs(255,0,0,q,200);
    }
  }
  clearMatrix();
  delay(1000);

  for (int z=0; z<5; z++)
  {
    for (int q=1; q<129; q*=2)
    {
      displayLEDs(0,255,0,q,200);
      displayLEDs(q,0,0,255,200);
    }
  }
  clearMatrix();
  delay(1000);
  
  
  for (int z=0; z<5; z++)
  {
    for (int q=1; q<9; q++)
    {
      displayLEDs(0,0,255,va2[q],200);
    }
  }
  clearMatrix();
  delay(1000);
}


