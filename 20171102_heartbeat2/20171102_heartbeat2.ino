
  int ledPin = 13;
  int sensorPin = A0;

  double alpha = 0.70;                            // smoothing參數 可依硬體狀況自行調整0~1之間的值
  double beta = 0.06;                             // find peak參數 可依硬體狀況自行調整0~1之間的值
  int period = 20;                                // sample脈搏的delay period

  
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);                            // 設定baud rate, 要與Serial Monitor一樣不然會亂碼



}

void loop() {
  // put your main code here, to run repeatedly:
  double count = 0.0;                           // 記錄心跳次數
  double oldValue = 0.0;                        // 記錄上一次sense到的值
  double oldChange = 0.0;                       // 記錄上一次值的改變
  unsigned long startTime = millis();           // 記錄開始測量時間
  while(millis() - startTime < 5000){           // sense 5 seconds
    int rawValue = analogRead(sensorPin);       // 讀取心跳sensor的值
    double value = alpha * oldValue + (1 - alpha) * rawValue;
    // find peak
    double change = value - oldValue;           // 計算跟上一次值的改變
    if (change>beta && oldChange<-beta) {       // 心跳
      count = count + 1;
      }
      oldValue = value;
      oldChange = change;
      delay(period);
    }
  Serial.print(count*12);                         // 將5秒計算的心跳值*12做為每分鐘心跳估計
  Serial.print(",");

}
