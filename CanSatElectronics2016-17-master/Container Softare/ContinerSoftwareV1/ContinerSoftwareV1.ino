#include <EEPROM.h>
#include <SharpIR.h>
#include <Adafruit_Sensor.h>
#include <SFE_BMP180.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <SparkFunDS1307RTC.h>
#include <SD.h>
#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>
#include <SharpIR.h>

//Definitions
#define TeleTeamID 0
#define TeleMissionTime 1
#define TelePacketCount 2
#define TeleAltitude 3
#define TeleTemperature 4
#define TeleVoltage 5
#define TeleSoftwareState 6
#define TeleDeployed 7
#define TeleArrayLength 8

//EEPROM Addresses
#define eeMissionTime 0

#define deployPin 7 // <-- change this to whatever pin the wire burning the string will be connected to.
#define irPin A0

#define TeamID 6082

int missionTime;
float TeleArray[8]; //all data will be stored in this array for transmission. 
//SFE_BMP180 pressure; //Pressure object created
double initialPressure;
long teleTime = millis();
double packetCount = 0;

SoftwareSerial gpsSer(3, 2);
Adafruit_GPS GPS(&gpsSer);
SharpIR sharp(irPin, 50, 93, 15000);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);

  setupBMP();
  setupIR();
  setupRTC();

  
}

void loop() {
  callTemp();
  callAlt();
  callRTC();
  callIR();

  packetCount = packetCount + 1;
  TeleArray[TelePacketCount] = packetCount;

  timeDelay();
  teleTime = millis();

  transmitData();
 }


