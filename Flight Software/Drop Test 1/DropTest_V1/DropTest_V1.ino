//Libraries

//Definitions
#define TeleTeamID  0;
#define TeleMissionTime 1;

//GlobalVariables
int packetCount = 1;
float TeleArray[11];


void setup() {
  Serial.begin(19200);

  
  //Pressure Sensor Setup
  setupPressure();
  
  //Temperture Setup
  setupTemp();
  
  //SD Card Setup
  setupSD();
  
  //Magnometer Setup
  setupMag();

  //RealTimeClock Setup
  setupRTC();
}


void loop() {

  callTemp();
  callPressure();
  callMag();
  callAlt();
  callRTC();


  compileData();

  timeDelay();

  transmitAndSaveData();

  receiveRadioData();

}




















