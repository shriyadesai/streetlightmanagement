const int trigPin = 5;
const int echoPin = 6;


long duration;
int FirstDistance=0;
int SecondDistance=0;
double speed=0;
int distance=1;
float Time = 0.20;
float delayedtime = 1000*Time;
int pos;

void setup()
{
pinMode(trigPin, OUTPUT); 
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
pinMode(3, OUTPUT);
pinMode(echoPin, INPUT); 
Serial.begin(9600); 
}


void loop()
{
GetSpeed();
pos=GetDistance();
if(pos<10)
{ analogWrite(9, 50);
  analogWrite(10, 0);
  analogWrite(11, 0);}
  if(pos>10 && pos<25)
{ analogWrite(9, 0);
  analogWrite(10, 50);
  analogWrite(11, 0);}
  if(pos>25)
{ analogWrite(9, 0);
  analogWrite(10, 0);
  analogWrite(11, 50);}



}

float GetDistance()
{
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

//calculating distance
distance= duration*0.034/2;

// Prints the distance on the Serial Monitor
Serial.print("Distance in cm : ");
Serial.println(distance);

return distance;

}
void GetSpeed(){
 
   FirstDistance = GetDistance(); //get the first distance
   
   delay(delayedtime); //waits 2 seconds depending on the time declared above ,, feel free to change the value dependng on the resolution of your sensor 
   
   SecondDistance = GetDistance(); //gets the second distance
   
   speed = (FirstDistance - SecondDistance)/Time;  // now calculating the difference 
   
 
//printing the speed on the serial monitor
  Serial.print("the speed (cm/s) is  :  ");
  Serial.println(speed);
   if(speed>33 )
{ analogWrite(3, 50);}
 else if(speed<-33)
  { analogWrite(3, 50);}
else {
  analogWrite(3,  0);
}
 
}
