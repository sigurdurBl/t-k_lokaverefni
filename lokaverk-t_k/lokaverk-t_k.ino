#include <Servo.h> //using the servo library

Servo myservo; // create an servo object
int potient = A0;
int potientValue = 0;
int gradur =  0;  // hvaða gráður á ég að skrifa 
int att = 0; // í hvaða átt er ég að fara 0=hækka, 1=lækka
int teljari = 0;
const int TrigPin = 2;//Trig attach to pin2
const int EchoPin = 3;//Echo attach to pin3
float cm; // fjöldi cm sem mældir eru
int led = 4;


void setup() {
  Serial.begin(9600);
  myservo.attach(9); 
  pinMode(TrigPin,OUTPUT);
  pinMode(EchoPin,INPUT);
  pinMode(led,OUTPUT);

}

void loop() {
 
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

    
    
    
    
    
  if(cm <= 20)
    {
      digitalWrite(led,HIGH);

    }
 


  
  
  
  
  potientValue = analogRead(potient);
  potientValue = map(potientValue, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180) 
//  myservo.write(0);
   // myservo.write(teljari);
  //teljari++;
   

    for (int teljari = 0; teljari <= 180 ; teljari++){
//        potientValue = analogRead(potient);
//  potientValue = map(potientValue, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180) 
//  myservo.write(0);
    myservo.write(teljari);
    
    

    
    
    
    
    
    
    
    
    delay(15);



      

}

    for (int teljari = 180; teljari >= 0 ; teljari--){
//        potientValue = analogRead(potient);
//  potientValue = map(potientValue, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180) 
//  myservo.write(0);
    myservo.write(teljari);

    delay(15);

      

}





  
  
 

 

  ;//give the servomotor time to go to position 
}
