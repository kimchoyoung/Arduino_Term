#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>
#include <LiquidCrystal.h>

// Declaration for Button
int pre_btn=14, next_btn=15;
bool pre_pre_btn_state,pre_next_btn_state;

//for MP3
SoftwareSerial mySerial(10, 11); // TX, RX

// Declaration for Button
// 핀 번호 (RS, E, DB4, DB5, DB6, DB7)
LiquidCrystal lcd(44, 45, 46, 47, 48, 49); // LCD 연결

void setup () {
  Serial.begin (9600);
  mySerial.begin (9600);
  
  mp3_set_serial (mySerial); //set softwareSerial for DFPlayer-mini mp3 module
  delay(1);                     // delay 1ms to set volume
  mp3_set_volume (5);          // value 0~30
  
  pinMode(next_btn, INPUT); 
  pinMode(pre_btn, INPUT); 
  pre_pre_btn_state=false;
  pre_next_btn_state=false;

  lcd.begin(16, 2); // LCD 초기화
  lcd.setCursor(0,0);
  lcd.print("Temp.: "); // 문자열 출력
  lcd.setCursor(0,1);
  lcd.print("Humi.:");
}

void loop () {
  boolean play_state = digitalRead(3);// connect Pin3 to BUSY pin of player
  if(play_state == HIGH){
    mp3_next ();
  }
      checkButton();
      printLCD();      
}

void checkButton(){
   if(digitalRead(next_btn)){
      if(!pre_pre_btn_state)
        Serial.print("next Btn");
      //   mp3_next(); // 코드는 이게 맞는거같은데 내 노트북이 쓰레기라서 버튼을 안눌러도 맨처음 초기화할때 두번눌려짐
      pre_pre_btn_state=true;    
      delay(50);   
    }
    else
      pre_pre_btn_state=false;

   if(digitalRead(pre_btn)){
      if(!pre_next_btn_state)
        Serial.print("pre Btn");
      //   mp3_previous(); // 코드는 이게 맞는거같은데 내 노트북이 쓰레기라서 버튼을 안눌러도 맨처음 초기화할때 두번눌려짐
      pre_next_btn_state=true;    
      delay(50);   
    }
    else
      pre_next_btn_state=false;
}

void printLCD(){
  lcd.setCursor(6,0);
  lcd.print("26.7"); // lcd.print(String(temp));
  lcd.setCursor(6,1);
  lcd.print("99.9"); //  lcd.print(String(Humid));
}
