#define PWM 5                       // PWM出力
#define A 3                         // モータドライバ Aピン                         
#define B 4                         // モータドライバ Bピン
#define SWI_1 6                     // ハンド開閉スイッチ１_上
#define SWI_2 7                     // ハンド開閉スイッチ１_下
#define sensor1 1                   // 光センサ1_上
#define EDF 9                       // EDF用PWM出力

int a_val1 = 0;                    //アナログ値
int sensorThre = 900;
int v;                            //電圧
int sw1 = 1;
int sw2 = 1;

int InitEDF_PWM = 100;              //EDF起動時のPWM
int EDF_PWM;                 //EDF吸引時のPWM

uint8_t recv_data;
uint8_t mode;   //上位3bitがモード番号_0~7
uint8_t edf ;   //下位5bitがPWM値_0~31

uint8_t send_data;
uint8_t flag = 0;
uint8_t sensor = 0;

// For test
const int LED = 13; //定数LEDを13に設定

//センサー前回値
int lv[4] = {0,0,0,0};
bool sw = false;
int counter = 0;

void Decryption() {
  mode = recv_data >> 5;  //上位3bitの取り出し_5bit右シフト_0~7
  edf = recv_data & 31 ;  //下位5bitの取り出し_31(00011111)とAND演算_0~31
  //10倍する必要がある。
}

void Sender() {
  //上位3bitがflag番号、下位5bitがセンサ値
  send_data = ( flag << 5) + sensor;
  Serial.write(send_data);
}

void setup()
{
  //初期化
  pinMode(13, OUTPUT);
  pinMode(A, OUTPUT);                     // モータドライバ Aピン
  pinMode(B, OUTPUT);                     // モータドライバ Bピン
  pinMode(PWM, OUTPUT);                   // PWM出力
  pinMode(SWI_1, INPUT_PULLUP);           // up switch
  pinMode(SWI_2, INPUT_PULLUP);           // down switch
  pinMode(sensor1, INPUT);                     // 光センサ1_上
  pinMode(EDF, OUTPUT);

  // モータ停止
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);

  // downスイッチにあたるまで回転
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  while (digitalRead(SWI_2))
  {
    analogWrite(PWM, 30);
  }
  analogWrite(PWM, 0);

  // モータ停止
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);

  // EDF起動
  analogWrite(EDF, InitEDF_PWM);
  delay(3000);

  // For test
  pinMode(LED, OUTPUT); //LEDピンを出力に設定

  Serial.begin(115200);
}
void loop()
{
  if (Serial.available() > 0)
  {
    flag = 0;
    recv_data = Serial.read();
    a_val1 = analogRead(sensor1);
    sensor = (a_val1 - 800) / 10;
    if(sensor < 0) sensor = 0;
    else if(sensor > 20) sensor = 20;
    /*lv[counter] = sensor;
    
    if(sensor >= 10 || lv[)*/
    
    counter++;
    if(counter >= 4) counter = 0;
    Decryption();
    EDF_PWM = edf * 10; //10倍する
    switch (mode) {
      // 待機_EDFストップ
      case 0:
        analogWrite(EDF, InitEDF_PWM);  //EDFストップ
        flag = 0;
        analogWrite(PWM, 0);
        Sender();
        if (digitalRead(SWI_2)) 
        {
          digitalWrite(A, HIGH);
          digitalWrite(B, LOW);
          analogWrite(PWM, 10);
        }
        else
        {
        //モータ停止
          digitalWrite(A, HIGH);
          digitalWrite(B, HIGH);
        }
        break;

      // 吸引
      case 1:
        analogWrite(EDF, EDF_PWM);   //EDF回転
        flag = 1;
        // センサ反応
        if (a_val1 > sensorThre ) flag = 5;
        Sender();
        break;

      // 切断1_刃が上のSWを押すまで
      case 2:
        analogWrite(EDF, EDF_PWM);   //EDF回転
        sw1 = digitalRead(SWI_1);
        if (sw1 == 0) flag = 6; // SW1反応あり(0)
        else flag = 2;          // SW1反応なし(1)
        Sender();
        //モータ閉
        if (digitalRead(SWI_1)) 
        {
          digitalWrite(A, LOW);
          digitalWrite(B, HIGH);
          analogWrite(PWM, 10);
        }
        else
        {
        //モータ停止
          digitalWrite(A, HIGH);
          digitalWrite(B, HIGH);
        }
        break;

      // 切断2_刃が上のSWを押すまで
      case 3:
        analogWrite(EDF, EDF_PWM);   //EDF回転
        sw2 = digitalRead(SWI_2);
        if (sw2 == 0) flag = 7; // SW2反応あり(0)
        else flag = 3;          // SW2反応なし(1)
        Sender();
        //モータ開
        if (digitalRead(SWI_2)) 
        {
          digitalWrite(A, HIGH);
          digitalWrite(B, LOW);
          analogWrite(PWM, 10);
        }
        else
        {
        //モータ停止
          digitalWrite(A, HIGH);
          digitalWrite(B, HIGH);
        }
        break;

      // 把持
      case 4:
        analogWrite(EDF, EDF_PWM);   //EDF回転
        // センサ反応あり
        if (a_val1>sensorThre ){
          flag = 4;
        } else {
          // 把持失敗
          analogWrite(EDF, InitEDF_PWM);  //EDFストップ
          flag = 0;
        }
        Sender();
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        break;
    }
  }
}


