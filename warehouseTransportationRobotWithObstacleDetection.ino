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

int vspeed=80;    
int tspeed=150;
int tdelay=20;

const int trigPin = 13;
const int echoPin = 12;

float duration;
float distance;
float obstacle;

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
 

  obstacle = ultrasonicSensor();
  while (obstacle != 1){

 svr=digitalRead(sr);
 svl=digitalRead(sl);

 Serial.println(svr);
 Serial.println(svl);
    
  if(svl==LOW && svr==LOW)
  {
  forward(); 
  }

  if(svl==HIGH && svr==LOW)
  {
  left(); 
  }
 
  if(svl==LOW && svr==HIGH)
  { 
  right(); 
  }
  
  if(svl==HIGH && svr==HIGH)
  {
  stop(); 
  }
    }
  
}

void forward()
 {
  digitalWrite(mr1,HIGH);
  digitalWrite(mr2,LOW);
  digitalWrite(ml1,HIGH);
  digitalWrite(ml2,LOW);
  analogWrite (enr,vspeed);
  analogWrite (enl,vspeed);
 } 

void backward()
 {
  digitalWrite(mr1,LOW);
  digitalWrite(mr2,HIGH);
  digitalWrite(ml1,LOW);
  digitalWrite(ml2,HIGH);
  analogWrite (enr,vspeed);
  analogWrite (enl,vspeed);
 }

void right()
 {
  digitalWrite(mr1,LOW);
  digitalWrite(mr2,HIGH);
  digitalWrite(ml1,HIGH);
  digitalWrite(ml2,LOW);
  analogWrite (enr,tspeed);
  analogWrite (enl,tspeed);
  delay(tdelay);
 } 

void left()
 {
  digitalWrite(mr1,HIGH);
  digitalWrite(mr2,LOW);
  digitalWrite(ml1,LOW);
  digitalWrite(ml2,HIGH);
  analogWrite (enr,tspeed);
  analogWrite (enl,tspeed);
  delay(tdelay);
}  

void stop()
 {
  analogWrite (enr,0);
  analogWrite (enl,0);
 }

 float ultrasonicSensor (){
   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(20);
   digitalWrite(trigPin, LOW);

   duration = pulseIn(echoPin, HIGH);

   distance = duration * 0.034 / 2;
  
   Serial.println(distance);

   return distance;
  }
