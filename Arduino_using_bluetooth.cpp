#include <SoftwareSerial.h>

const int rxPin = 4;
const int txPin = 2;               

SoftwareSerial mySerial(rxPin, txPin);

const int Loads[] = {9, 10, 11, 12};

int state = 0;
int flag = 0;

void setup() 
{
   for (int i=0;i<4;i++)
    {
      pinMode(Loads[i], OUTPUT);
    }
   mySerial.begin(9600);
   for (int i=0;i<4;i++)
    {
      digitalWrite(Loads[i], LOW);
    }
   
}

void loop() 
{
    
    if(mySerial.available() > 0)
    {
      state = mySerial.read();
      flag=0;
    }
    
    switch(state)
    {
      case '0':digitalWrite(Loads[0], HIGH);
               flag=1;
               break;
      case '1':digitalWrite(Loads[0], LOW);
               flag=1;
               break;
      case '2':digitalWrite(Loads[1], HIGH);
               flag=1;
               break;
      case '3':digitalWrite(Loads[1], LOW);
               flag=1;
               break;
      case '4':digitalWrite(Loads[2], HIGH);
               flag=1;
               break;
      case '5':digitalWrite(Loads[2], LOW);
               flag=1;
               break;
      case '6':digitalWrite(Loads[3], HIGH);
               flag=1;
               break;
      case '7':digitalWrite(Loads[3], LOW);
               flag=1;
               break;
      case '8':digitalWrite(Loads[0], LOW);
               digitalWrite(Loads[1], LOW);
               digitalWrite(Loads[2], LOW);
               digitalWrite(Loads[3], LOW);
               flag=1;
               break;
     }
}
