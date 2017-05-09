//Real time clock
void setupRTC(){
  rtc.begin();
  rtc.adjust(DateTime(0,0,0,0,0,0));
}
void callRTC(){
  DateTime now = rtc.now();
  int seconds = now.second() + 60 * now.minute() + 60*60*now.hour() + 60*60*24*now.day();
  writeToSD(seconds,"Time.txt");
  TeleArray[TeleTime] = (float) seconds;
}

