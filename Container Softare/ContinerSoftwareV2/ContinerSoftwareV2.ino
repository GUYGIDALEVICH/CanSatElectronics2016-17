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
#define TeleVoltage 5 
#define TeleSoftwareState 6
#define TeleDeployed 7
#define TeleArrayLength 8
#define TeleLong 9
#define TeleLat 10

#define deployPin 7 // <-- change this to whatever pin the wire burning the string will be connected to.

#define TeamID 6082

int8_t softwareState = 1;

bool trigger = false; //Use this trigger for proper release mechanism and proper checking of time in stage 7

int missionTime; //Current mission time
float TeleArray[10]; //all data will be stored in this array for transmission. 

//SFE_BMP180 pressure; //Pressure object created
double initialPressure = 1013.25; //This is the sea level 'generic' value just in case we can't get an actual value
double initialAltitude = 0; //Initial altitude temporarily set to 0


float temp; 

long teleTime = millis(); //Returns the number of milliseconds since the Arduino board began running the current program
long packetCount = 1;

const int8_t chipSelect = 6; //This is the pin that connects to the chipselect of the SD card reader

int currentAltitude; //Used to check current altitude
int previousAltitude; //Used for comparison checks for certain stages
int previousTime; //Used for comparison checks for certain stages

//Declare sensors
SoftwareSerial gpsSer(3, 2);
Adafruit_GPS GPS(&gpsSer);
sensors_event_t event;
Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);
RTC_DS3231 rtc;
Ir ir(0);

//Start off with first stage
void setup() {
  Serial.begin(19200);
  boot();
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
    if (ir.status()){
      trigger = false;
      softwareState = 7;
      pDeploy();
    }
    deployment();
  }else if (softwareState == 7){
    if(trigger == false){
      previousTime = TeleArray[TeleTime];
      trigger = true;
    }
    if(TeleArray[TeleTime]-previousTime>=10){
      softwareState == 8;
      trigger = false;
    }
  }else{
    landed();
  }
  
  packetCount = packetCount + 1;
  TeleArray[TelePacketCount] = packetCount;
  writeToSD(packetCount,"Packet.txt");
  writeToSD(softwareState,"Software State.txt");
  timeDelay();
  teleTime = millis();
}


 


