//Real Time Clock
void setupRTC(){
  rtc.begin();
}

void callRTC(){
  rtc.update();
  int8_t seconds = rtc.second() + 60 * rtc.minute() + 60*60*rtc.hour() + 60*60*24*rtc.day();
  TeleArray[TeleMissionTime] = (float) seconds;
}


