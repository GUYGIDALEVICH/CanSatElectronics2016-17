//Libraries
#include <SoftwareSerial.h>
#include <Adafruit_BMP085.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>
#include <SparkFunDS1307RTC.h>

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
#define TeleArrayLength 12;

#define RtcMissionTimeReg 0x08

//Pin Declarations
#define SS_Rx 3;
#define SS_Tx 4;
#define deployPin 7;

#define RTC_ADDRESS 0x68;
#define TeamID 9999;

//Constants
#define declinationAngle 0.17 // declination angle for Toronto only, needs to be adjusted for different locations.


//GlobalVariables
int packetCount = 1;
float TeleArray[TeleArrayLength];
long teleTime = millis();

SoftwareSerial radio(SS_Rx, SS_Tx);

Adafruit_BMP180 bmp;
Adafruit_HMC5883_Unified mag;

void setup() {
  
  Serial.begin(19200);
  radio.begin(19200);

  //Mission Setup
  setupMissionTime();

  //Setup Sensors
  setupPressure();
  setupTemp();
  setupSD();
  setupMag();
  setupRTC();

  
}


void loop() {

  //Update All telemetery
  callTemp();
  callPressure();
  callMag();
  callAlt();
  callRTC();



  timeDelay();

  transmitAndSaveData();

  receiveRadioData();

}




















