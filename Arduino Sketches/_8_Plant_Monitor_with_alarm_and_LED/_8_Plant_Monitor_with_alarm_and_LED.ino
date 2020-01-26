const int moistureAO = 0;


int AO = 0;
int tmp = 0;
int buzzPin = 11; // Buzzer pin 11
int LED = 13;// LED pin 13


void setup (){
  Serial.begin(9600);
  Serial.println("Soil moisture sensor");
  pinMode(moistureAO, INPUT);
  pinMode(buzzPin, OUTPUT);// sets pin as output
pinMode(LED, OUTPUT);// sets pin as output
  
}

void loop ()
{

  
  
  tmp=analogRead( moistureAO );
  if ( tmp != AO ) 
  
     
  
  {
    AO=tmp;
    Serial.print("A=");
    Serial.println(AO);
  }
  

  
  delay (1000);
  
  
  {
if(analogRead(0) > 900){ // this number depends soil moisture

digitalWrite(buzzPin, HIGH);
digitalWrite(LED,HIGH);

delay(1000); // waits for 1 second
digitalWrite(buzzPin,LOW);
digitalWrite(LED,HIGH);

} else{
digitalWrite(buzzPin,LOW);
digitalWrite(LED,LOW);
}
}
  
  

}
