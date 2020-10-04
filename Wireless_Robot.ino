
#include <PS2X_lib.h>  
#include <Servo.h>


PS2X ps2x; // create PS2 Controller Class
Servo servo1, servo2, servo3, servo4;

int x = 90, y = 90, z = 90, w = 90;


void setup() {
ps2x.config_gamepad(12,10,8,11, false, false);
servo1.attach(3);
servo2.attach(5);
servo3.attach(6);
servo4.attach(9);
}

void loop() {

 ps2x.read_gamepad();

 //Controlling the base 
if (ps2x.Button(PSB_R1)) 
{
  x--;
  if (x < 30) x = 30;
  servo1.write(x);
}
  
if (ps2x.Button(PSB_L1)) 
{
  x++;
  if (x > 150) x = 150;
  servo1.write(x);
}


 //Controlling the vertical motions
if (ps2x.Button(PSB_PAD_UP)) 
 { 
    y--;
    if (y < 30) y = 30;
    servo2.write(y);
 }

if (ps2x.Button(PSB_PAD_DOWN))
 { 
    y++;
    if (y > 150) y = 160;
    servo2.write(y);
 }

  
// Controlling the Gripper
 if (ps2x.Button(PSB_R2) ) 
{
 //if (z > 70 || z < 140);
  z++;
  if (z > 140) z = 140;
  if (z < 70) z = 70;
  servo3.write(z);
}
  
if (ps2x.Button(PSB_L2)) 
{  
  z--;
  if (z < 70) z = 70;
  if (z > 140) z = 140; 
  servo3.write(z);
  }


//Controlling the Horizontal Motion
if (ps2x.Button(PSB_PAD_LEFT)) 
  {
    w++;
    if (w > 150) w = 150;
    servo4.write(w);
  }

if (ps2x.Button(PSB_PAD_RIGHT))
  {
    w--;
    if (w < 30) w = 30;
    servo4.write(w);
  }

 /////////////////////////////////////////
 delay(20); 
}
