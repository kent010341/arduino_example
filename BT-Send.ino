#include  <SoftwareSerial.h>
SoftwareSerial BTSerial(11, 12); // RX | TX

int p;
void setup()
{
   Serial.begin(9600);
   BTSerial.begin(9600);  
   p=0;
}
void loop()
{
   p = p + 1;
   //BTSerial.write("Count=>");
   BTSerial.print("Receive Count=>");
   BTSerial.println(p);
   delay(100);
   if(p>=9) {
     p=0;
   }
}
