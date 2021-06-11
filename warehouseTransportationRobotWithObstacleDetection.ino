#include <NewPing.h>

#define TRIGGER_PIN 13

#define ECHO_PIN 12

#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

int mr1=9;  //motor right 1
int mr2=11;  //motor right 2
int ml1=7; //motor left 1
int ml2=8; //motor left 2
int sr=A0;   //sensor right
int sl=A2;   //sensor left
int svr=0;
int svl=0;
int led=13;
int enr=6; 
int enl=5;

int vspeed=50;    
int tspeed=100;
int tdelay=20;

int trackingTresh = 100; //the tracking sensors uses this figure to differentiate between surfaces
int distanceTresh = 10; //ultasonic sensor treshold for detecting obstacles in cm

void setup()
{
 Serial.begin(9600);

 pinMode(mr1,OUTPUT);
 pinMode(mr2,OUTPUT);
 pinMode(ml1,OUTPUT);
 pinMode(ml2,OUTPUT);
 pinMode(led,OUTPUT);
 pinMode(sr,INPUT);
 pinMode(sl,INPUT);
 
 delay(5000);
}

void loop()
{
 int distance = sonar.ping_cm();

 while (distance < distanceTresh){
  
  svr=analogRead(sr);
  svl=analogRead(sl);

  Serial.println(svr);
  Serial.println(svl);

  if(svl < trackingTresh && svr < trackingTresh)
  {
  forward(); 
  }

  if(svl > trackingTresh && svr < trackingTresh)
  {
  left(); 
  }
 
  if(svl < trackingTresh && svr > trackingTresh)
  { 
  right(); 
  }
  
  if(svl> trackingTresh && svr> trackingTresh)
  {
  stop(); 
  }
  
  }
 
 
}

void forward()
 {
  digitalWrite(mr1,LOW);
  digitalWrite(mr2,HIGH);
  digitalWrite(ml1,HIGH);
  digitalWrite(ml2,LOW);
  analogWrite (enr,vspeed);
  analogWrite (enl,vspeed);
 } 

void backward()
 {
  digitalWrite(mr1,HIGH);
  digitalWrite(mr2,LOW);
  digitalWrite(ml1,LOW);
  digitalWrite(ml2,HIGH);
  analogWrite (enr,vspeed);
  analogWrite (enl,vspeed);
 }

void right()
 {
  digitalWrite(mr1,LOW);
  digitalWrite(mr2,LOW);
  digitalWrite(ml1,HIGH);
  digitalWrite(ml2,HIGH);
  analogWrite (enr,tspeed);
  analogWrite (enl,tspeed);
  delay(tdelay);
 } 

void left()
 {
  digitalWrite(mr1,HIGH);
  digitalWrite(mr2,HIGH);
  digitalWrite(ml1,LOW);
  digitalWrite(ml2,LOW);
  analogWrite (enr,tspeed);
  analogWrite (enl,tspeed);
  delay(tdelay);
}  

void stop()
 {
  analogWrite (enr,0);
  analogWrite (enl,0);
 }
