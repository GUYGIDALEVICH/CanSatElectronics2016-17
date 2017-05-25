//Libraries
#include <SoftwareSerial.h>
#include <SPI.h>
#include <Wire.h>
#include <SparkFunDS1307RTC.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>
#include <SFE_BMP180.h>
#include <EEPROM.h>
#include <SD.h> //Not coded in yet

//Location
#define USE_EXTEEPROM
#define TEAMID 6082 //Recheck before final run
#define teleTime 0
#define telePressure 1
#define teleTemp 2
#define teleSpeed 3
#define teleHeading 4
#define teleAlt 5
#define teleCount 6
#define EEPROM_ID 0x50
#define EEPROM_LocationAddress 0
//#define releasePin 13   Rewire for the release pin

//Other variables
double P0;
double T, P, A;
char status;
const int dataSize = 7;
int count = 0;
int flightState = 1;
long eeAddress_W = 0;
//int altcounter = 0;

//The array to be transmitted
float telemetry[dataSize];

//Sensors
SFE_BMP180 bmp;
Adafruit_HMC5883_Unified compass = Adafruit_HMC5883_Unified(12345);

void setup()
{
  Serial.begin(19200);
  initialize();
}

void loop() {
  if (flightState == 1)
  {
    initialize();
  }
  else if (flightState == 2)
  {
    boot();
  }
  else if (flightState == 0)
  {
    dpwait();
  }
  else if (flightState == 3)
  {
    descent();
  }
  else if (flightState == 4)
  {
    land();
  }
  telemetry[teleCount] = telemetry[teleCount] + 1; //counter

  saveTelemetry() ;//saves data to the eeprom
  delay(1000);
}

void saveTelemetry()
{
#ifdef USE_EXTEEPROM
  float saveData[dataSize + 2];
  saveData[0] = TEAMID;
  saveData[1] = flightState;
  for (int i = 0; i < dataSize; i++)
  {
    saveData[i + 2] = telemetry[i];
  }
  extEEPROMWrite(saveData, dataSize + 2);
#endif
}

