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

//The array to be transmitted
float telemetry[7]; 

//Other variables
double P0;
double T, P, A;
char status;

//Sensors
SFE_BMP180 bmp;
Adafruit_HMC5883_Unified compass = Adafruit_HMC5883_Unified(12345);

void setup() 
{
  Serial.begin(19200);
  bmpBegin();
  compassBegin();
  RTCBegin();
  radioBegin();
  cameraBegin();
  int count=0;
  telemetry[teleCount]=count;
  telemetry[teleCount]=0;
}

void loop() {
  if(telemetry[teleCount]==0)
  {
    callBasePressure();
  }
  else
  {
    callTemp();
    callPressure();
    callAlt();
    getHeading();
    getTime();
    takePicture();
    printXB();
  }
  telemetry[teleCount] = telemetry[teleCount] + 1; //counter
  delay(1000);
}
