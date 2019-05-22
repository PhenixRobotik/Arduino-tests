#include <Servo.h>

Servo central,right,left;

int l_min=140,l_max=164,r_min=54,r_max=24,c_min=0,c_max=180;

byte r;

void setup() {
  Serial.begin(115200);
  
  central.attach(11);
  left.attach(10);
  right.attach(9);

  central.write(c_min);
  left.write(l_min);
  right.write(r_min);
  Serial.println("Ready");
}

void loop() {

  if (Serial.available() > 0)
  {
    r=Serial.read();
    if(r=='c')
    {
      central.write(c_min);
    }
    else if(r=='C')
    {
      central.write(c_max);
    }
    else if(r=='r')
    {
      right.write(r_min);
    }
    else if(r=='R')
    {
      right.write(r_max);
    }
    else if(r=='l')
    {
      left.write(l_min);
    }
    else if(r=='L')
    {
      left.write(l_max);
    } 
  }
  delay(1);
}
