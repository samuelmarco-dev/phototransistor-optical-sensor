#include <Servo.h>
Servo microServo;

#define SERVO 2
#define LED 8
#define OPTICAL_SENSOR 7 //pino digital ligado no coletor

bool object = false;
   
void setup(){  
  pinMode(OPTICAL_SENSOR, INPUT);
  pinMode(LED, OUTPUT); 
    
  microServo.attach(SERVO, 544, 2400);
  digitalWrite(LED, LOW);
  microServo.write(0);

  Serial.begin(9600);
}  
   
void loop(){
  object = digitalRead(OPTICAL_SENSOR);
  
  if (!object){ 
  	digitalWrite(LED, HIGH);
    Serial.print("Objeto detectado");
  
    for(int index = 0; index <= 180; index++) {
      microServo.write(index);
      delay(10);
    }
  } else{
    digitalWrite(LED, LOW);
    microServo.write(0);
  }
  delay(100);
}
