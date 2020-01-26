int led[10] = {2,3,4,5,6,7,8,9,10,11,}; 
// Assign the pins for the leds
int leftChannel = 0;
int left, i;
void setup()
{
for (i = 0; i < 10; i++)  
pinMode(led[i], OUTPUT);
Serial.begin(9600); 
}
void loop()
{
left = analogRead(leftChannel);
Serial.println(left);
left = left / 5;
  if (left == 0)     
{
   for(i = 0; i < 10; i++)     
{
     digitalWrite(led[i], LOW);      }
  }    else 
 {  
 for (i = 0; i < left; i++)    
 {     
digitalWrite(led[i], HIGH);       
  }       
 for(i = i; i < 10; i++)     
  {      digitalWrite(led[i], LOW);  
   } 
 }
}
