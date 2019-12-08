char blu;
byte i;
int a,state;
#define IN1 7
#define IN2 6
#define IN3 5
#define IN4 4

void setup() {
    pinMode(IN1, OUTPUT); //cấu hình ngõ ra cho các chân điều khiển động cơ
    pinMode(IN2, OUTPUT); //cấu hình ngõ ra cho các chân điều khiển động cơ
    pinMode(IN3, OUTPUT); //cấu hình ngõ ra cho các chân điều khiển động cơ
    pinMode(IN4, OUTPUT); //cấu hình ngõ ra cho các chân điều khiển động cơ
    Serial.begin(9600);
}
void motor_1_forward(int speed)
{
  digitalWrite(IN1, HIGH); // 255
  analogWrite(IN2, 255 - speed); 
  }
void motor_2_forward(int speed)
{
  analogWrite(IN3, speed);
  digitalWrite(IN4, LOW);
  }
void motor_1_backward(int speed)
{
  digitalWrite(IN1, LOW);
  analogWrite(IN2, speed);
  }
void motor_2_backward(int speed)
{
  analogWrite(IN3, 255 - speed);
  digitalWrite(IN4, HIGH);
  }
void move_forward(int speed)
{
  motor_1_forward(speed);
  motor_2_forward(speed);
  }
void move_backward(int speed)
{
  motor_1_backward(speed);
  motor_2_backward(speed);
  }
void turn_left(int speed)
{
  motor_1_backward(speed);
  motor_2_forward(speed);
  }
void turn_right(int speed)
{
  motor_1_forward(speed);
  motor_2_backward(speed);
  }
void motor_stop()
{
  move_forward(0);
  }
///////////////////////////////////////////////////////
void loop() {      
if(Serial.available() > 0){ //nếu có kết nối bluetooth thì hiển thị mã lên màn hình Serial
    int state = Serial.read(); //đọc mã bluetooth
    Serial.println(state); // xuất ra màn hình Serial để quan sát
    if(state==70)  a=1; //nếu mã là 70 gán a=1---tiến
    if(state==66)  a=2; //nếu mã là 66 gán a=2---lùi
    if(state==76)  a=3; //nếu mã là 82 gán a=3---trái
    if(state==82)  a=4; //nếu mã là 76 gán a=4---phải
    if(state==83)  a=5; //nếu mã là 76 gán a=5---dừng
 }

switch(a){
  case 2: move_forward(255);
            break;
                  
  case 1: move_backward(255);
            break;
 
  case 3: turn_left(150);
            break;
                
  case 4: turn_right(150);
            break;   
                 
  case 5: motor_stop();
            break;
}
}
          
         
