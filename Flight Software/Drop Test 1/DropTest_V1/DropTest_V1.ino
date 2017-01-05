//Libraries
#include <SoftwareSerial.h>
#include <Adafruit_BMP085.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <HMC5883L.h>
#include <SparkFunDS1307RTC.h>
#include <SD.h>

//Definitions
#define TeleTeamID  0
#define TeleMissionTime 1
#define TelePacketCount 2
#define TeleAltSensor 3
#define TelePressure 4
#define TeleSpeed 5
#define TeleTemp 6
#define TeleVoltage 7
#define TeleHeading 8
#define TeleSoftwareState 9
#define TeleBonus 10
#define TeleDecline 11
#define TeleArrayLength 12

#define RtcMissionTimeReg 0x08

//Pin Declarations
#define SS_Rx 3
#define SS_Tx 4
#define deployPin 7

<<<<<<< HEAD
#define TeamID 6082
=======
#define RTC_ADDRESS 0x68;
#define TeamID 9999;
>>>>>>> origin/master

//Constants
#define GLOBE_DEG -10
#define GLOBE_MIN 45


//GlobalVariables
int packetCount = 0;
float TeleArray[TeleArrayLength];
long teleTime = millis();
char telemetryFile[16];

SoftwareSerial radio(SS_Rx, SS_Tx);

Adafruit_BMP085 bmp;
HMC5883L compass;

void setup() {
  
  Serial.begin(19200);
  radio.begin(19200);


  Serial.println("test1");
  
  //Mission Setup
  //setupMissionTime();

  //Setup Sensors
  setupBMP();
  
  setupSD();
  setupMag();
  Serial.println("test2");
  setupRTC();

  
}


void loop() {

  //Update All telemetery
  callTemp();
  callPressure();
  callMagHeading();
  callAlt();
  callRTC();

  packetCount = packetCount + 1;
  TeleArray[TelePacketCount] = packetCount;

  Serial.println("test3");

  timeDelay();
  teleTime = millis();
  
  transmitData_Serial();
  //writeTelemetryToSD();
  
  receiveRadioData();

}




















