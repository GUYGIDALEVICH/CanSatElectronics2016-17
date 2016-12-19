//Libraries
<<<<<<< HEAD

//Definitions
#define TeleTeamID  0;
#define TeleMissionTime 1;
#define TelePacketCount 2;
#define TeleAltSensor 3;
#define TelePessure 4;
#define TeleSpeed 5;
#define TeleTemp 6;
#define TeleVoltage 7;
#define TeleHeading 8;
#define TeleSoftwareState 9;
#define TeleBonus 10;
#define TeleDecline 11;
=======
//hi
>>>>>>> origin/master

//GlobalVariables
int packetCount = 1;
float TeleArray[12];
long teleTime = millis();



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



  timeDelay();

  transmitAndSaveData();

  receiveRadioData();

}




















