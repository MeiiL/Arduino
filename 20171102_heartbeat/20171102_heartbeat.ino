
  int ledPin = 13;
  int sensorPin = 0;

  double alpha = 0.75;
  int period = 20;
  double change = 0.0;
  
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200); 
}

void loop() {
  // put your main code here, to run repeatedly:
  static double oldValue = 0;
  static double oldChange = 0;
  int rawValue = analogRead(sensorPin);
  double value = alpha * oldValue + (1 - alpha) * rawValue;

  Serial.print(rawValue);
  Serial.print(",");
  Serial.println(value);

  oldValue = value;
  delay(period);
}
