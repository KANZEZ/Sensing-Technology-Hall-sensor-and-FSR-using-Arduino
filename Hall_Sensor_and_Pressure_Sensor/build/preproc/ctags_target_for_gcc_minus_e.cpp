# 1 "c:\\Users\\29180\\Desktop\\Hall_Sensor_and_Pressure_Sensor\\Hall_Sensor_and_Pressure_Sensor.ino"




float read_pressure = 0;
int if_mag = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(2,0x0);
pinMode(4,0x1);
pinMode(3,0x1);
pinMode(A0,0x0);
}

void loop() {
  // put your main code here, to run repeatedly:
  //pressure_sensor

read_pressure = (float(analogRead(A0))-700.0)/(1023.0-700);
Serial.println((1.0-read_pressure)*100);
int out = int(read_pressure*225.0);
analogWrite(3,out);
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
