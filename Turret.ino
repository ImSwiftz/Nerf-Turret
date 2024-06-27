#include<Servo.h>

Servo Servo1;
Servo Servo2;
Servo Servo3;

int servoPin = 6;
int servoPin2 = 11;
int servoPin3 = 3;
const int fp = 8;
const int bp = 12;
const int delayT = 200;
const int Pot = A0;
const int Button = 4;
const int JoyX = A1;
const int JoyY = A2;


void setup(){
  pinMode(fp, OUTPUT);
  pinMode(bp, OUTPUT);
  pinMode(Button, INPUT);
  Servo1.attach(servoPin);
  Servo2.attach(servoPin2);
  Servo3.attach(servoPin3);
  Serial.begin(9600);
}

void loop (){

  //Servo X
  int JX = analogRead(JoyX);
  int X = map(JX, 0, 1023, 0, 180);
  Servo2.write(X);

  //Servo Y
  int JY = analogRead(JoyY);
  int Y = map(JY, 0, 1023, 0, 180);
  Servo3.write(Y+2); // Had to add to and account for the slight bit of variation there is when converting

  const int P = analogRead(Pot);
  int PB = digitalRead(Button);
  float Turn = map(P, 0, 1023, 0, 255);

  if (PB == HIGH){ //How the push Servo moves
  Servo1.write(180); //Moves 20 degrees above the middle point which is 90
  delay(500);

 
 }
 else {
  Servo1.write(90);
 }

  Serial.print("  Y  ");
  Serial.print(Y);
  Serial.print("  ServoY  ");
  Serial.print(JY);
  Serial.print("  X  ");
  Serial.print(JX);
  Serial.print("  ServoX  ");
  Serial.print(X);
  Serial.print("  Button  ");
  Serial.print(PB);
  Serial.print("  POT  ");
  Serial.print(P);
  Serial.print("  POW  ");
  Serial.println(Turn);

  analogWrite(fp, Turn);

}