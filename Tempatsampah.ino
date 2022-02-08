/* 
 This project was made and developed for task of social activity (KKN-UGM).
 A simple automatic open and close trash bin.
 The purposes of this project are to educate about Arduino and its application. 
   
 *  
 */

#include <Servo.h>
Servo servo;  
int pos = 0;                                  
const int trigPin = 10;                       // flexible number of pin
const int echoPin = 11;                       // flexible number of pin
float jarak;                                  // distance (jarak) is flexible
long durasi;                                  // duration (durasi) is flexible


void setup() 
{
  servo.attach(9);                            //the attached servo pin number is flexible, as long as it sits on digital pin
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  servo.write(pos);
}

void loop() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  durasi = pulseIn(echoPin, HIGH);
  jarak = 0.034*(durasi/2);
  if (jarak < 25)
  {
    servo.write(150);                         // the position of servo is adjustable depends on the position of the servo placement, you can adjust it to your optimal condition
    delay(1000);
  }
  else 
  {
    servo.write(pos);                         // the position of servo is adjustable depends on the position of the servo placement, you can adjust it to your optimal condition
  }
  delay(300);
}
