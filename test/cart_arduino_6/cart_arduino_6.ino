//Pin番号定義
#define start 11
#define runbrake 10
#define cwccw 9
#define pwm 5
#define INT 8
#define AlarmReset 7 


int8_t v;           //データ受信(速度)_-128~127

uint8_t send_data;  //データ送信(距離)_0~255
uint8_t distance;   //7bit_距離(0 ~ 127)
uint8_t flag = 0;   //1bit_flag( 0:0~127 or 1:128~ )


float r=0.0250;       //車輪半径[m]
int pulse=0.000;      //パルス数
float rot=0.000;    //車輪の停止間の回転数
int val;            //PWM_速度

double d = 0;        //総移動距離

// 初期化
void setup(){
  pinMode(start, OUTPUT);  //START/STOP 
  pinMode(runbrake, OUTPUT);  //RUN/BRAKE 
  pinMode(cwccw, OUTPUT);   //CW/CCW
  pinMode(INT, OUTPUT); 
  pinMode(AlarmReset, OUTPUT); 
  pinMode(pwm, OUTPUT); 
  
  digitalWrite(INT,LOW); //New circuit
  digitalWrite(AlarmReset,LOW); //New circuit

  //停止
  digitalWrite(start,LOW); //New circuit
  digitalWrite(runbrake,LOW); //New circuit
  
  Serial.begin(115200) ;

  //割り込み処理定義
  attachInterrupt(1, senseRotation, FALLING); // 1 = D3, FALLING = 立ち下がり
}

// 回転パルス立ち下が数検を出用
void senseRotation(void) {
  pulse++;
}

// データ送信
void Send(){
  send_data = ( flag << 7) + distance;
  //Simulinkに[cm]単位で送信_最大2550cm(uint8_t Data[4];)
  //Serial.print("H");          //ヘッダ送信
  //総移動距離
  Serial.write(send_data);
}

//総移動距離の計算
void CalculateDistance(){
  //台車改良前
  //rot = pulse / 900.0;    //900 = 30(モータの出力軸1回転あたり"30"パルス) * 減速比30
  //台車改良後
  rot = pulse / 450.0;      //450 = 30(モータの出力軸1回転あたり"30"パルス) * 減速比15
  //単位[m]
  //d1:総移動距離
  d = rot * (2.000 * 3.141 * r);
  //単位[cm]
  distance = d * 100;
  if(d >= 0 && distance <= 126){
    flag = 0;
  }else if( distance > 126){
    pulse = 0;
    flag = 1;
    distance -= 126;
  } 
  Send();
}

//Simulinkから速度を受信し、その速度をPWNに変換
void CalculatePWM(){
  //速度
  //[m/s]単位で速度を受信すると0.〇となってしまう。
  //扱いやすくするために、Simulinkから[m/min]単位で受信している。
  //v[m/min] = 2πr * (3/500)*pwm(i)[rot/s] * 60[min]
  //(500/3)は測定によって算出した値_1s間の回転数
  
  //double i = (abs(v)*500)/(2*3.141*r*3*60);   //台車改良前
  double i = (abs(v)*500)/(2*3.141*r*3*60) / 2;   //台車改良後
  //整数を返す
  val = round(i);
}

// メインループ
void loop() {
  if(Serial.available() > 0) 
  {
    v = Serial.read();

    CalculatePWM();
    
    //正転
    if( v>0 && v<=14 ){
      //運転
      digitalWrite(start,HIGH); //New circuit
      digitalWrite(runbrake,HIGH); //New circuit
      //正転
      digitalWrite(cwccw,HIGH); //New circuit
      //速度
      val=1;
      analogWrite(pwm, val);
      CalculateDistance();
    }
    //逆転
    else if( v<0 && v>=-14){
      //運転
      digitalWrite(start,HIGH); //New circuit
      digitalWrite(runbrake,HIGH); //New circuit
      //逆転
      digitalWrite(cwccw,LOW); //New circuit
      //速度
      val=1;
      analogWrite(pwm, val);
      CalculateDistance();
    }
    //-14<=v<=14以外の値を受信すると、Reset
    else{
      //停止
      digitalWrite(start,LOW); //New circuit
      digitalWrite(runbrake,LOW); //New circuit
      analogWrite(pwm, 0);
      //★ひとつ前で停止した時までの距離を格納
    }
  }
}
