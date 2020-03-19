#include <SoftwareSerial.h>


SoftwareSerial mySerial(0, 1); // RX | TX
int command ;
void setup() {
   Serial.begin(9600);
   mySerial.begin(9600);
   Serial.println("You're connected via Bluetooth");
   pinMode(13,OUTPUT);   //left motors forward
   pinMode(12,OUTPUT);   //left motors reverse
   pinMode(11,OUTPUT);   //right motors forward
   pinMode(10,OUTPUT);   //right motors reverse
   pinMode(8,OUTPUT);   // Buzina (Buzzer)

}

void loop() {
   if (mySerial.available())
   {
    command=(mySerial.read());
    if (command=='B')
    {
      Serial.println("Forward");
      digitalWrite(13,HIGH);
      digitalWrite(12,LOW);
      digitalWrite(11,HIGH);
      digitalWrite(10,LOW);           
    
    }
    
        else if (command=='F')
    {
      Serial.println("Reverse");
      digitalWrite(13,LOW);
      digitalWrite(12,HIGH);
      digitalWrite(11,LOW);
      digitalWrite(10,HIGH);
    }
    
        else if (command=='R')
    {
      Serial.println("Left");
      digitalWrite(13,LOW);
      digitalWrite(12,LOW);
      digitalWrite(11,HIGH);
      digitalWrite(10,LOW);
    }

        else if (command=='L')
    {
      Serial.println("Right");
      digitalWrite(13,HIGH);
      digitalWrite(12,LOW);
      digitalWrite(11,LOW);
      digitalWrite(10,LOW);
    }

        else if (command=='S')
    {
      Serial.println("Stop");
      digitalWrite(13,LOW);
      digitalWrite(12,LOW);
      digitalWrite(11,LOW);
      digitalWrite(10,LOW);
    }

            else if (command=='W')
    {
      Serial.println("Front Lights on");
      digitalWrite(7,HIGH);
    }
            else if (command=='w')
    {
      Serial.println("Front Lights off");
      digitalWrite(7,LOW);
    }

            else if (command=='V')
    {
      Serial.println("Ligar Buzina");
      tone(8,400);
    }

                else if (command=='v')
    {
      Serial.println("Desligar Buzina");
        noTone(8);
        //delay(200);
    }

       delay(30);
  }
}
