//Libraries
#include <SoftwareSerial.h>
#include <SPI.h>
#include <Wire.h>
#include <SparkFunDS1307RTC.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>
#include <SFE_BMP180.h>
#include <EEPROM.h>

//Location
#define teleTime 0
#define telePressure 1
#define teleTemp 2
#define teleSpeed 3
#define teleHeading 4
#define teleAlt 5
#define teleCount 6
//#define releasePin 13   Rewire for the release pin

//Other variables
double P0;
double T, P, A;
char status;
const int dataSize = 7;
int count = 0;
int flightState = 1;
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
  else if (flightState == 3)
  {
    dpwait();
  }
  else if (flightState == 4)
  {
    descent();
  }
  else if (flightState == 5)
  {
    land();
  }
  telemetry[teleCount] = telemetry[teleCount] + 1; //counter
  //saveTelemetry();
  delay(1000);
}

