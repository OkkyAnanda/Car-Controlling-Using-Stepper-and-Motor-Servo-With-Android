#include <Servo.h>
Servo myservo;
int pos = 0;
int motorkirimundur=4;
int motorkirimaju=5;
int motorkananmundur=6;
int motorkananmaju=7;
void setup() {
  // put your setup code here, to run once:
 pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  Serial.begin(9600);
  digitalWrite(2,LOW);
  myservo.attach(9);
}

void loop() {
 if (Serial.available()>0){
  char data= Serial.read();
  if (data=='1'){
   digitalWrite (motorkananmundur,HIGH);
   digitalWrite (motorkananmaju,LOW);
   delay(10);
   digitalWrite (motorkananmundur,LOW);
   digitalWrite (motorkananmaju,LOW);
   delay(10);
  }else if (data=='2'){
   digitalWrite (motorkananmundur,LOW);
   digitalWrite (motorkananmaju,HIGH);
   digitalWrite (2,HIGH);
   delay(10);
   digitalWrite (motorkananmundur,LOW);
   digitalWrite (motorkananmaju,LOW);
   delay(10);
    }else if(data=='0'){
   digitalWrite (motorkananmundur,LOW);
   digitalWrite (motorkananmaju,LOW);
   digitalWrite(2,LOW);
  }else if(data=='3'){
    //gerbangbuka();
    for(pos = 0; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  }else if(data=='4'){
    //gerbangtutup();
    for(pos = 180; pos>=0; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
 }
 }
}

