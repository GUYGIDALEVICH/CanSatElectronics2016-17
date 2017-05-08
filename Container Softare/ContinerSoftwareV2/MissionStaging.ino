//The whole point of this is done in order to check time although i think its uneccessary and might be remove
/*
void setupMissionTime(){
  DateTime now = rtc.now();
  int missionStartTime = now.second();
  createFile("Mission Time.txt");
  String MSTS = "Mission start time at "+missionStartTime;
  writeToSD(MSTS, "Mission Time.txt");
}
*/

//Calls all sensors just so I dont have to repeat this over and over again
void callAll(){
  callTemp();
  callAlt();
  callRTC();
  callIR();
  callGPS();
}

/*
 *These are all the states that the software will go through 
 */
void boot(){
  softwareState = readData("State.txt").toInt();
  packetCount = readData("Packet.txt").toInt();
  missionTime = readData("Time.txt").toInt();
  if(softwareState == 1){
     setupBMP();
     setupIR();
     setupRTC();
     setupGPS();
     setupSD();
     createFile("Packet.txt");
     createFile("State.txt");
     createFile("Time.txt");
  }
}

void initialize(){
  callInitialPressure();
  callInitialAltitude();
  callAll();
  transmitData();
  softwareState = 3;
}

void LWait(){
  callAll();
  transmitData();
}

void ascent(){
  callAll();
  transmitData();
}

void descent(){
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












