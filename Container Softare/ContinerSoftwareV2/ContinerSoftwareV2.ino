#include <EEPROM.h>
#include <SharpIR.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <SparkFunDS1307RTC.h>
#include <SD.h>
#include <SPI.h>
#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>

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

# define Latitude 0     // For the LocationArray
# define Longitude 1

//EEPROM Addresses
#define eeMissionTime 0

#define deployPin 7 // <-- change this to whatever pin the wire burning the string will be connected to.
#define irPin A0

#define TeamID 6082

int missionTime;
float TeleArray[8]; //all data will be stored in this array for transmission. 
float LocationArray[2]; //this can be incorporated into TeleArray, left separate for now

//SFE_BMP180 pressure; //Pressure object created
double initialPressure;

//Variables for tempearture and pressure
float temperature;

long teleTime = millis();
double packetCount = 0;

const int chipselect = 6; //This is the pin that connects to the chipselect of the SD card reader


SoftwareSerial gpsSer(3, 2);
Adafruit_GPS GPS(&gpsSer);
SharpIR sharp(irPin, 50, 93, 15000);
Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);

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


