#include <AFMotor.h>

AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
AF_DCMotor motor1(1);


char bt='S';
void setup()
{
  Serial.begin(9600);
 
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  motor1.setSpeed(255);
 
  Stop();
}


void loop() {
 
bt=Serial.read();

if(bt=='F')
{
 forward(); 
}

if(bt=='B')
{
 backward(); 
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
  motor4.run(FORWARD);

}

void backward()
{
     motor3.run(BACKWARD);
  motor4.run(BACKWARD);
 
}
void left()
{
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
 
}
void right()
{
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
 
}
void Stop()
{
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  motor1.run(RELEASE);
}
