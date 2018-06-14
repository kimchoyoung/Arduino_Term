void setup() {
   Serial.begin(9600);
}

void loop() {
  float a= Calculate_Angry(0.70, 15.3);
  Serial.print(a);
  while(1);
}

float Calculate_Angry(float RH, float T){ // RH=humid, T=temp
  float angry= (9.0/5.0)*T-0.55*(1-RH)*((9.0/5.0)*T-26)+32;
  return angry;
}
