#include <RTClib.h>
#include <Adafruit_BMP085_U.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <SD.h>
#include <SPI.h>
#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>
#include <ir.h>


//Definitions
#define TeleTeamID 0
#define TeleTime 1
#define TelePacketCount 2
#define TeleAltitude 3
#define TeleTemperature 4
#define TeleSoftwareState 5
#define TeleDeployed 6
#define TeleArrayLength 7
#define TeleLong 8
#define TeleLat 9

#define deployPin 7 // <-- change this to whatever pin the wire burning the string will be connected to.

#define TeamID 6082



#define initPressure 'A'
#define initAlt 'B'
#define sState 'C'
#define mTime 'D'
#define nTime 'E'
#define pack 'F'

float softwareState = 1;

bool trigger = false; //Use this trigger for proper release mechanism and proper checking of time in stage 7

float TeleArray[10]; //all data will be stored in this array for transmission. 

//SFE_BMP180 pressure; //Pressure object created
float initialPressure = 1013.25; //This is the sea level 'generic' value just in case we can't get an actual value
float initialAltitude = 0; //Initial altitude temporarily set to 0
float initialTime;
float totalSecondsElapsed;

int packetCount = 0;

float temp; 

int packetCounts = 1;

const int8_t chipSelect = 6; //This is the pin that connects to the chipselect of the SD card reader

float currentAltitude; //Used to check current altitude
float previousAltitude; //Used for comparison checks for certain stages
float previousTime; //Used for comparison checks for certain stages

//Declare sensors
SoftwareSerial gpsSer(3,2);
Adafruit_GPS GPS(&gpsSer);
sensors_event_t event;
Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);
RTC_DS3231 rtc;

//Start off with first stage
void setup() {
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  Serial.begin(19200);
  boot();
  timeDelay();
  Serial.println("SETUP OKAY");
}

//Goes through each stage based on the transistion guidelines in CDR
void loop() {
  if(softwareState == 2){
    initialize();
  }else if(softwareState == 3){
    middleStages();
    if(currentAltitude > initialAltitude + 10){
      softwareState = 4;
    }
  }else if(softwareState == 4){
    previousAltitude = currentAltitude;
    middleStages();
    if(((currentAltitude-previousAltitude)<-10)){
      softwareState = 5;
    }
  }else if(softwareState == 5){
    middleStages();
    if(currentAltitude<=425){
      softwareState = 6;
    }
  }else if (softwareState == 6){
    trigger = true;
    deployment();
    if (trigger = false){
      softwareState = 7;
    }
  }else if (softwareState == 7){
    callAlt();
    if(currentAltitude == previousAltitude && packetCount != 10){
      packetCount += 1;
    }else if(currentAltitude == previousAltitude && packetCount == 10){
      softwareState = 8;
    }else{
      packetCounts = 0;
    }
    previousAltitude = currentAltitude;
  }else{
    landed();
  }
  TeleArray[TeleTime] = totalSecondsElapsed;
  packetCount = packetCount + 1;
  TeleArray[TelePacketCount] = packetCount;
  writeToSD(softwareState,sState);
  delay(1000);
  //timeDelay();
}


 


