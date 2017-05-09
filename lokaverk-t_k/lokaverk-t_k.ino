#include <Servo.h> //using the servo library

Servo myservo; // create an servo object
int xPin = A1;
int potient = A0;
int potientValue = 0;
int gradur =  0;  // hvaða gráður á ég að skrifa 
int att = 0; // í hvaða átt er ég að fara 0=hækka, 1=lækka
int teljari = 0;
const int TrigPin = 2;//Trig attach to pin2
const int EchoPin = 3;//Echo attach to pin3
float cm; // fjöldi cm sem mældir eru
int led = 4;
int snua = 0;
int snuningur = 0;
int sw = 5;
int xPosition = 0;
int takki = 0;
int buttonState = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(9); 
  pinMode(TrigPin,OUTPUT);
  pinMode(EchoPin,INPUT);
  pinMode(led,OUTPUT);
  pinMode(sw, INPUT_PULLUP);

}





void loop() {
  buttonState = digitalRead(sw);
  //xPosition = analogRead(xPin);
  if(buttonState == 1) {
    if(snuningur >= 180){
      snua = 1;
    }else if(snuningur <= 0){
      snua = 0;
    }
    if(snua == 0 && buttonState == 1){
      snuningur++;
    } else if (snua == 1 && buttonState == 1) {
      snuningur--;
    }
  }
  
  /*if(buttonState == 0 && xPosition >= 1000){
     snua = 0;
  } else if(xPosition == 0){
     snua = 1;
  } */
  
  if(buttonState == 0) {
    potientValue = analogRead(xPin);
    //snuningur = map(potientValue, 0, 1023, 0, 180);// scale it to use it with the servo (value between 0 and 180) 
    Serial.print("potient: ");
    Serial.println(potientValue);
    if(potientValue < 400 && snuningur >= 0) {
      snuningur--;  
    } else if (potientValue > 600 && snuningur <= 180) {
      snuningur++;  
    }
  }

  digitalWrite(TrigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin,LOW);
  digitalWrite(led,LOW);

  cm = pulseIn(EchoPin,HIGH)/58.0;  
  cm = (int(cm * 100.0))/100.0;
  if(cm < 0)
  {
    cm = 0;
  }
  Serial.println(cm);
    
  if(cm <= 20) {
    digitalWrite(led,HIGH);
  } else {
    digitalWrite(led,LOW);
  }
    
  Serial.print("X: ");
  Serial.print(xPosition);
  Serial.print("snuningur: ");
  Serial.print(snuningur);
  Serial.print(" | Button: ");
  Serial.println(buttonState);
  myservo.write(snuningur);
  delay(15);//give the servomotor time to go to position 
}

