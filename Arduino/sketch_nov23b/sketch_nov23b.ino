#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);


char bt='S';
void setup()
{
  Serial.begin(9600);
 
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);

  Stop();
}


void loop() {
 
bt=Serial.read();

if(bt=='F')
{
 forward(); 
}



if(bt=='L')
{
 left(); 
}

if(bt=='R')
{
 right(); 
}

if(bt=='S')
{
 Stop(); 
}

}
void forward()
{
 
  motor3.run(FORWARD);
  
}


void left()
{
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  
}
void right()
{
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
 
}
void Stop()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
 
}
