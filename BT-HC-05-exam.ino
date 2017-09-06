#include  <SoftwareSerial.h>
SoftwareSerial BTSerial(11, 12); // RX | TX

void setup()
{
  pinMode(9, OUTPUT);  // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
  digitalWrite(9, HIGH);
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  BTSerial.begin(9600);  // HC-05 default speed in AT command more
}
void loop()
{
  char w;
  // Keep reading from HC-05 and send to Arduino Serial Monitor
  if (BTSerial.available()) {
    w = BTSerial.read();
    if(w == 'R'){
      
    }
    else if(w == 'Y'){
      
    }
    else if(w == 'G'){
      
    }
    else if(w == 'T'){
      
    }
    else if(w == 'B'){
      
    }
    else if(w == 'P'){
      
    }

    Serial.print("W=");
    Serial.println(w);

    Serial.println("BTSerial.available()");
  }
  // Keep reading from Arduino Serial Monitor and send to HC-05
  if (Serial.available()){
    BTSerial.write(Serial.read());
   // Serial.println("Serial.available()");
  }
}
