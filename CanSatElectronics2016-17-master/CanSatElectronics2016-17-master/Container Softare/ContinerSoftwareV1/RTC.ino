//Real time clock
void setupRTC(){
  rtc.begin();
  rtc.setTime(0,0,0,0,0,0,0);
}
void callRTC(){
  rtc.update();
  int8_t seconds = rtc.second() + 60 * rtc.minute() + 60*60*rtc.hour() + 60*60*24*rtc.day();
  TeleArray[TeleMissionTime] = (float) seconds;
}

