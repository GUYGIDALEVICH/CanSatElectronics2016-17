void setupMissionTime(){
  DateTime now = rtc.now();
  int missionStartTime = now.second();
  writeToSD(missionStartTime, mTime);
}


//Calls all sensors just so I dont have to repeat this over and over again
void callAll(){
  callTemp();
  callAlt();
  callRTC();
  callGPS();
}

/*
 *These are all the states that the software will go through 
 */
void boot(){
  if(readData(sState).toInt()!=0)
    softwareState = readData(sState).toInt();
    packetCount = readData(pack).toInt();
    missionTime = readData(nTime).toInt();
  if(softwareState == 1){
     setupBMP();
     setupRTC();
     setupGPS();
     setupSD();
  }
}

void initialize(){
  callInitialPressureAndAltitude();
  callAll();
  transmitData();
  softwareState = 3;
}

void middleStages(){
  callAll();
  transmitData();
}

void deployment(){
  deploy();
  callAll();
  transmitData();
}
void pDeploy(){
  Serial.print("Final data sent...Going into post deployment stage");
}
void landed(){
  writeDPin();
  callGPS();
  transmitOneTelem(TeleLat);
  transmitOneTelem(TeleLong);
}












