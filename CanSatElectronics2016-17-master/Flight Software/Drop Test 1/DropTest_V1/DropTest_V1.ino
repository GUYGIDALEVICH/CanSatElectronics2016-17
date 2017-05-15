//Libraries
#include <SoftwareSerial.h>
#include <Adafruit_BMP085.h>u
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <HMC5883L.h>
#include <SparkFunDS1307RTC.h>
#include <SD.h>
#include <Adafruit_VC0706.h>  //https://github.com/adafruit/Adafruit-VC0706-Serial-Camera-Library
#include <SPI.h>              //Built-in

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
#define pitotPin A0
#define powerPitot 9
#define xBeeSleepPin 8

#define TeamID 6082

#define RTC_ADDRESS 0x68
#define TeamID 6082


//Constants
#define GLOBE_DEG -10
#define GLOBE_MIN 45


//GlobalVariables
int packetCount = 0;
float TeleArray[TeleArrayLength];
long teleTime = millis();
char telemetryFile[16];
char IMGfilename[13];

//Software Serials
SoftwareSerial radio(SS_Rx, SS_Tx);
SoftwareSerial cameraconnection = SoftwareSerial(2, 3);

//Sensor Definitions
Adafruit_BMP085 bmp;
HMC5883L compass;
Adafruit_VC0706 cam = Adafruit_VC0706(&cameraconnection);

void setup() {
  
  Serial.begin(9600);
  radio.begin(19200);



  //Mission Setup
  //setupMissionTime();

  //Setup Sensors
    Serial.println("1");
  setupBMP();

 // setupSD();
  setupMag();

  setupRTC();

  //setupCamera();
  setupPitot();
  
}


void loop() {

  //Update All telemetery
  callPressure();
  callMagHeading();
  callAlt();
  callRTC();
  pitotTube();

  packetCount = packetCount + 1;
  TeleArray[TelePacketCount] = packetCount;



  timeDelay();
  teleTime = millis();
  
  transmitData_Serial();
  //writeTelemetryToSD();

  //receiveRadioData();

  //takeSnap();
  //storeImageToSD();

}




















