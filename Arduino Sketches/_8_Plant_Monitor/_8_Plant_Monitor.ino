const int moistureAO = 0;


int AO = 0;
int tmp = 0;

void setup (){
  Serial.begin(9600);
  Serial.println("Soil moisture sensor");
  pinMode(moistureAO, INPUT);
  
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

}
