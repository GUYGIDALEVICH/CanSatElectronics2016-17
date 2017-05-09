void setupMissionTime(){
  DateTime now = rtc.now();
  int missionStartTime = now.second();
  writeToSD(missionStartTime, "Mission Time.txt");
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
  if(readData("State.txt").toInt()!=NULL||readData("State.txt").toInt()!=0)
    softwareState = readData("State.txt").toInt();
  if(readData("Packet.txt").toInt()!=NULL||readData("State.txt").toInt()!=0)
    packetCount = readData("Packet.txt").toInt();
  if(readData("State.txt").toInt()!=NULL)
    missionTime = readData("Time.txt").toInt();
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












