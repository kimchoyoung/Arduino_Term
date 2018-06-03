int Raindrops_pin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
    Serial.println(analogRead(A0));  // 센서 출력값을 시리얼모니터로 전송
    delay(2000);
}
