#include <AFMotor.h>
#include <Servo.h>
Servo servo1;
byte blue=0;
int y;
AF_DCMotor motor1(1, MOTOR12_64KHZ);
AF_DCMotor motor2(2, MOTOR12_64KHZ);
AF_DCMotor motor3(3, MOTOR12_64KHZ);
AF_DCMotor motor4(4, MOTOR12_64KHZ);
void setup() 
{
  Serial.begin(9600);
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  servo1.attach(9);
}


void loop()
{ 
  if ( Serial.available()>0)
  {
    blue=Serial.read();
  }
   if (blue == 87)
   {
     Serial.println(" Tiến");
     motor1.run(FORWARD);
     motor2.run(FORWARD);
     blue=0;
   }
   if (blue==83)
   {
    Serial.println(" Lùi ");
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
        blue=0;
   }
   if (blue ==68)
   {
    Serial.println("Phải");
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
   
    blue=0;
   }
   if (blue==65)
   {
    Serial.println("Trái");   
     motor1.run(BACKWARD);
     motor2.run(FORWARD);
     
    blue=0;
   }
      if ((blue == 52)||(blue==53))
   {
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    
   }
    if (blue==80)
  {
    Serial.println("ANGLE UP");
  motor3.run(BACKWARD);
  } 
  else  if (blue==112) motor1.run(RELEASE); 
  
  if (blue==72)
  {
    Serial.println("ANGLE DOWN");
   motor3.run(FORWARD);
  }
  if (blue ==104) motor3.run(RELEASE);
  if (blue==75)//bắn
  {
    Serial.println("FIRE");
    servo1.write(0);
    delay(50);
  }
  if (blue == 107) //ngừng bắn
  {
    servo1.write(90);
  }

  if (blue==48)
  {
   y=1;
  } 
  if (blue==49)
  {
      y=0;
  }
  if (y==1) 
  motor4.run(FORWARD); 
  else motor4.run(RELEASE);
}
