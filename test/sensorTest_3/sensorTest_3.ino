#define sensor1 1                   // 光センサ1_上
#define sensor2 2                   // 光センサ2_中
#define sensor3 3                   // 光センサ3_下


int a_val1 = 0;                    //アナログ値
int a_val2 = 0;                    //アナログ値
int a_val3 = 0;                    //アナログ値

void setup() {
  pinMode(sensor1, INPUT);                     // 光センサ1_上
  pinMode(sensor2, INPUT);                     // 光センサ2_中
  pinMode(sensor3, INPUT);                     // 光センサ3_下
  Serial.begin(115200) ;
}

void loop() {
  a_val1 = analogRead(sensor1);
  //a_val2 = analogRead(sensor2);
  //a_val3 = analogRead(sensor3);
  Serial.write("\nsensor1 : ");
  Serial.print(a_val1);
  //Serial.write(",  ");
  //Serial.write("sensor2 : ");
  //Serial.print(a_val2);
  //Serial.write(",  ");
  //Serial.write("sensor3 : ");
  //Serial.println(a_val3);
  delay(100) ;

}
