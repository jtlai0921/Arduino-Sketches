/*
-A count-down TIMER is implemented.
-The potentiometer is used to set the TIMER.
-Two Push-Buttons: "ARM" to set the counter and "GO" to start the counter.
-Display: Sparkfun's Serial 4 Digit 7-Segment Display
*/
#define FuseTIME      1500  //Fuse current duration in milliseconds.

#include <SoftwareSerial.h>  //Usinf the NewSoftSerial library.

#define Fuse     7          //Pin connected to the Fuse relay.
#define GoButt   6          //Pin connected to the GO button.
#define ArmButt  5          //Pin connected to the ARM button.
#define BuzzPin  4          //Connected to the Speaker.
#define TXdata   3          //Conneted to Rx of the Display.
#define RXdata   2          //not used in this project
#define SetPot   0          //Analog Pin connected to the Pot.

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
  mySerialPort.print("v");        //Reset the display.
  mySerialPort.print("z");        //Brightness Control.
  mySerialPort.write(0x40);  //3/4 Intensity.
  mySerialPort.print("w");        //Decimal Point Control.
  mySerialPort.write(0x10);  //turn on the colon ":".
}

int  DownCntr;                    // down counter (1/10 Secs.)
int  Go=0;                        // Stopped

//================================================================
void loop(){
  if(!digitalRead(GoButt)||!digitalRead(ArmButt)){
    Go=0;                         //ABORT!!!
    tone(BuzzPin, 440, 1500);
    delay(1500);
  }

  if(Go==0){
    WaitARM();  
    WaitGO();
  }
  ShowTimer();
  if (DownCntr > 50){
      if (DownCntr % 10 ==0)tone(BuzzPin, 1000, 50);  //Tone every second.
     }
  else if (DownCntr % 2 ==0)tone(BuzzPin, 1000, 50);  //Tone every 1/5 second.

  if (DownCntr ==0){
    //------------------ ROCKET LAUNCH! --------------------
    tone(BuzzPin, 440, FuseTIME);  //Launch audible signal
    digitalWrite(Fuse,HIGH);       //CLOSE the fuse circuit
    delay(FuseTIME);
    digitalWrite(Fuse,LOW);        //OPEN the fuse circuit.
    //------------------------------------------------------
     Go=0;
    }
  while (millis()% 100);        //Wait until the next 1/10 of second.
  delay(50);
  DownCntr--;
}

//----------------------------------------
void WaitGO(){
  ShowTimer();
  while(digitalRead(GoButt));
  Go=1;
  delay(20);
  while(!digitalRead(GoButt));  //Debounce GO button.
}

//------------------------------------------------------
void ReadTimer(){
  DownCntr = map(analogRead(SetPot), 0, 1023, 5, 60);
  DownCntr*=10;  
}
//------------------------------------------------------
void ShowTimer(){
  String seconds = String (DownCntr, DEC);
  while(seconds.length()<3)seconds= "0" + seconds;     //format to 3 numbers.
  mySerialPort.print(seconds);                         //Write to Display.
  mySerialPort.print(" ");                             //Last digit off. 
}

//------------------------------------------------------
void WaitARM(){
  while(digitalRead(ArmButt)==1){
     ReadTimer(); 
     delay(50);
     ReadTimer(); 
     ShowTimer();                   //Show Digits.
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
  while(!digitalRead(ArmButt));  //Debounce ARM button.

}
