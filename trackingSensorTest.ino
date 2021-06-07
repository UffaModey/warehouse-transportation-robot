float rightPing = A0;
float midPing = A1;
float leftPing = A2;
float trackRight;
float trackMid;
float trackLeft;

 
void setup() {
  // put your setup code here, to run once:
pinMode(rightPing, INPUT);
pinMode(midPing, INPUT);
pinMode(leftPing, INPUT);
Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:

  trackRight = rightTrack();
  trackMid = midTrack();
  trackLeft = leftTrack();
  
  Serial.println(trackRight);
  Serial.println(trackMid);
  Serial.println(trackLeft);
  delay(500);

}
float rightTrack(){
  return analogRead(rightPing);
  }
  
float midTrack(){
  return analogRead(midPing);
  }
  
float leftTrack(){
  return analogRead(leftPing);
  }
