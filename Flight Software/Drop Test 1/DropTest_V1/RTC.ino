//Real Time Clock
void setupRTC(){
  rtc.begin();
  //REMOVE THIS LINE LATER******************
  rtc.setTime(0,0,0,0,0,0,0);
  //****************************************
}

void callRTC(){
  rtc.update();
  int seconds = rtc.second() + 60 * rtc.minute() + 60*60*rtc.hour() + 60*60*24*rtc.day();
  TeleArray[TeleMissionTime] = (float) seconds;
}


