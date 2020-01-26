const int trigPin = 8;
const int echoPin = 7;
const int leftMotor = 5;
const int rightMotor = 6;

void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(leftMotor, OUTPUT);
pinMode(rightMotor, OUTPUT);

digitalWrite(leftMotor, LOW); // Turn the motors off right away so it doesn’t start moving
digitalWrite(rightMotor, LOW);
}

void loop() {
long duration, distance;

// In order to measure a distance, we first send a trigger
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// After sending the trigger, wait for the echo
duration = pulseIn(echoPin, HIGH);

// The distance in CM is related to the time until the echo arrived
distance = (duration/2) / 29.1;

// Ignore distances less than zero
if ( (distance > 200) || (distance < 0))
{
digitalWrite(leftMotor, HIGH);
digitalWrite(rightMotor, HIGH);
}

// Turn if the nearest obstacle is closer than 1M

else if (distance < 100)
{
digitalWrite(leftMotor, LOW);
digitalWrite(rightMotor, HIGH);
}

// wait a moment
delay(200);
}
