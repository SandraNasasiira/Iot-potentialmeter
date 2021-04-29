#include <Servo.h>
Servo servo1;
int trigPin = 6;
int echoPin = 7;
int potpin  =0;
long distance;
long duration;
int val;
int Red=2;
int Blue=3;
int Green=4;

 
void setup()
{
servo1.attach(12);
 pinMode(Red,OUTPUT);
 pinMode(Blue,OUTPUT);
 pinMode(Green,OUTPUT);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
}
 
void loop() {
  ultra();
  servo1.write(0);
  val=analogRead(potpin);
  val=map(val,0,1023,0,180);
  servo1.write(val);
  delay(10);
  if(distance <=100){
    digitalWrite(Red,HIGH);
    delay(3000);
    digitalWrite(Red,LOW);
      delay(2000);
    
  servo1.write(60);
  }
  else{servo1.write(0);}
    if(distance <=100){
    digitalWrite(Blue,HIGH);
      delay(3000);
    digitalWrite(Blue,LOW);
      delay(2000);
  servo1.write(120);
  }
  else{servo1.write(0);}
    if(distance <=100){
    digitalWrite(Green,HIGH);
      delay(3000);
    digitalWrite(Green,LOW);
      delay(2000);
    
  servo1.write(180);
  }
  
  
}
 
void ultra(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin,HIGH);
  distance=duration*0.34/2;
}

