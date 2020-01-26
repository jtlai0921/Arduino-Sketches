#define FuseTIME      1500  //Fuse current duration in milliseconds.
#include <SoftwareSerial.h>  //Call the SoftwareSerial library.

#define Fuse     7          //Pin connected to the Fuse (your LED or igniter)
#define GoButt   6          //Pin connected to the GO button
#define ArmButt  5          //Pin connected to the ARM button
#define BuzzPin  4          //Connected to the buzzer
#define TXdata   3          //Conneted to Rx of the Display
#define RXdata   2          //not used 
#define SetPot   0          //Analog Pin connected to the Pot

SoftwareSerial mySerialPort(RXdata,TXdata);

void setup(){
  pinMode(TXdata,OUTPUT);
  pinMode(RXdata,INPUT);
  pinMode(Fuse,OUTPUT);
  pinMode(ArmButt, INPUT);        // set "ARM" button pin to input
  pinMode(GoButt, INPUT);         // set "GO" button pin to input
  digitalWrite(Fuse,LOW);         //OPEN the fuse circuit.
  digitalWrite(ArmButt, HIGH);    // turn on pullup resistor 
  digitalWrite(GoButt, HIGH);     // turn on pullup resistor 
  mySerialPort.begin(9600);
  delay(10);                      //Wait for Serial Display startup.
  mySerialPort.print("v");        //Reset the display
  mySerialPort.print("z");        //Brightness 
  mySerialPort.write(0x40);       //3/4 Intensity
  mySerialPort.print("w");        //Decimal Point Control
  mySerialPort.write(0x10);       //turn on the colon ":"
}

int  DownCntr;                    // down counter (1/10 Secs.)
int  Go=0;                        // Stopped

void loop(){
  if(!digitalRead(GoButt)||!digitalRead(ArmButt)){
    Go=0;                         // Aborts the countdown
    tone(BuzzPin, 440, 1500);
    delay(1500);
  }

  if(Go==0){
    WaitARM();  
    WaitGO();
  }
  ShowTimer();
  if (DownCntr > 50){
      if (DownCntr % 10 ==0)tone(BuzzPin, 1000, 50);  //Beeps every second
     }
  else if (DownCntr % 2 ==0)tone(BuzzPin, 1000, 50);  //Beep goes faster

  if (DownCntr ==0){
    
    tone(BuzzPin, 440, FuseTIME);  //Launch tone
    digitalWrite(Fuse,HIGH);       //CLOSE the fuse circuit
    delay(FuseTIME);
    digitalWrite(Fuse,LOW);        //OPEN the fuse circuit
    
         Go=0;
    }
  while (millis()% 100);        //wait
  delay(50);
  DownCntr--;
}

void WaitGO(){
  ShowTimer();
  while(digitalRead(GoButt));
  Go=1;
  delay(20);
  while(!digitalRead(GoButt));  //Debounce GO button
}

void ReadTimer(){
  DownCntr = map(analogRead(SetPot), 0, 1023, 5, 60);
  DownCntr*=10;  
}
void ShowTimer(){
  String seconds = String (DownCntr, DEC);
  while(seconds.length()<3)seconds= "0" + seconds;     //format to 3 numbers
  mySerialPort.print(seconds);                         //Write to Display
  mySerialPort.print(" ");                             //Last digit off
}

void WaitARM(){
  while(digitalRead(ArmButt)==1){
     ReadTimer(); 
     delay(50);
     ReadTimer(); 
     ShowTimer();                   
     delay(150);
  }

  Go=0;
  ShowTimer();
  tone(BuzzPin, 2000, 150);
  delay(200);
  tone(BuzzPin, 2000, 150);
  delay(200);
  tone(BuzzPin, 2000, 150);

  delay(20);
  while(!digitalRead(ArmButt));  //Debounce ARM button

}
