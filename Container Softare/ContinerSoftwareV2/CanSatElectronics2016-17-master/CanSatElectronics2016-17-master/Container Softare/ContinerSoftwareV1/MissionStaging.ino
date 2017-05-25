void setupMissionTime(){
  int missionStartTime = rtc.second();
  EEPROM.put(eeMissionTime, missionStartTime);
  
}

