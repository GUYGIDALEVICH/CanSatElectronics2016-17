//Libraries


//GlobalVariables
int packetCount = 1;
float TeleArray[11];


void setup() {
  Serial.begin(19200);

  int a = 2;
  
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




















