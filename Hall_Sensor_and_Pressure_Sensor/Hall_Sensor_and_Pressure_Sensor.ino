#define read_mag 2
#define led_digital 4
#define led_pwm 3
#define pressure A0
float read_pressure = 0;
int if_mag = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(read_mag,INPUT);
pinMode(led_digital,OUTPUT);
pinMode(led_pwm,OUTPUT);
pinMode(pressure,INPUT);
}

void loop() {
  //读出模拟输出，进行数据中心偏移和归一化处理
read_pressure = (float(analogRead(pressure))-700.0)/(1023.0-700);
Serial.println((1.0-read_pressure)*100);//输出0-100%范围压力
int out = int(read_pressure*225.0);//转换成pwm数值
analogWrite(led_pwm,out);//led呼吸灯
delay(50);//延时，方便绘图
}


//hall sensor
  /*
if_mag = digitalRead(read_mag);
Serial.println(if_mag);
if (if_mag == 1)
{
    digitalWrite(led_digital,LOW);
}else{
    digitalWrite(led_digital,HIGH);
}
*/