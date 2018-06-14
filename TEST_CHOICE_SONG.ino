void ChoiceSong(float angry, float light, int rain){
  int choice=0;
// {비눈X, 쾌적, 낮} 으로 초기화
  bool is_rainy=false;
  bool is_angry=false;
  bool is_day=true; 

  if(rain<=512) // 수치는 변경가능 나중에 테스트 해보고 어느정도를 물이 온상황이라할지 정정
    is_rainy=true;
  if(is_angry>=75) // 불쾌지수75부터 50% 사람들이 불쾌감을 느끼기 시작한다
    is_angry=true;
  if(is_day<=512)
    is_day=false;

  if(!is_rainy && !is_angry & is_day) choice=1;
  else if(!is_rainy && !is_angry & !is_day) choice=2;
  else if(!is_rainy && is_angry & is_day) choice =3;
  else if(!is_rainy && is_angry & !is_day)choice =4;
  else if(is_rainy && !is_angry & is_day) choice =5;
  else if(is_rainy && !is_angry & !is_day) choice =6;
  else if(is_rainy && is_angry & is_day) choice =7;
  else if(is_rainy && is_angry & !is_day) choice =8;
  
  return choice;  // object.playMp3Folder(choice);
}
