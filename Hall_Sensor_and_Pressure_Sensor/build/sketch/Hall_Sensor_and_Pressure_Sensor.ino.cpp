#include <Arduino.h>
#line 1 "c:\\Users\\29180\\Desktop\\Hall_Sensor_and_Pressure_Sensor\\Hall_Sensor_and_Pressure_Sensor.ino"
#define read_mag 2
#define led_digital 4
#define led_pwm 3
#define pressure A0
float read_pressure = 0;
int if_mag = 0;

#line 8 "c:\\Users\\29180\\Desktop\\Hall_Sensor_and_Pressure_Sensor\\Hall_Sensor_and_Pressure_Sensor.ino"
void setup();
#line 17 "c:\\Users\\29180\\Desktop\\Hall_Sensor_and_Pressure_Sensor\\Hall_Sensor_and_Pressure_Sensor.ino"
void loop();
#line 8 "c:\\Users\\29180\\Desktop\\Hall_Sensor_and_Pressure_Sensor\\Hall_Sensor_and_Pressure_Sensor.ino"
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(read_mag,INPUT);
pinMode(led_digital,OUTPUT);
pinMode(led_pwm,OUTPUT);
pinMode(pressure,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //pressure_sensor

read_pressure = (float(analogRead(pressure))-700.0)/(1023.0-700);
Serial.println((1.0-read_pressure)*100);
int out = int(read_pressure*225.0);
analogWrite(led_pwm,out);
delay(50);

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
