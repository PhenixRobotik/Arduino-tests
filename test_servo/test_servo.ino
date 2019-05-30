#include <Servo.h>

Servo big, small, balec;

int l_min=140,l_max=164,r_min=54,r_max=24,c_min=0,c_max=180;

int small_r=55, small_c=95,small_l=125;
int big_r=30, big_c=70, big_l=100;

byte r;

void setup() {
  Serial.begin(115200);
  
  small.attach(11);
  balec.attach(10);
  big.attach(9);

  balec.write(75);
  
  big.write(big_c);
  small.write(small_c);
  Serial.println("Ready");
}

void loop() {

  if (Serial.available() > 0)
  {
    r=Serial.read();
    if(r=='r')
    {
      big.write(big_r);
      delay(200);
      small.write(small_r);
    }
    else if(r=='c')
    {
      small.write(small_c);
      delay(200);
      big.write(big_c);
    }
    else if(r=='l')
    {
      small.write(small_l);
      delay(200);
      big.write(big_l);
    }

  }
  delay(1);
}
