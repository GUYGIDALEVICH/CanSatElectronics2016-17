//Periodic snapshot function
//Usage notes:
//Adapted from Adafruit snapshot example by Husain Nizami
//USE A LEVEL SHIFTER OR VOLTAGE DIVIDER if there is any chance of 5V
//Camera TX --> Pin  2
//Camera RX --> Pin  3
//SD CS     --> Pin 10
//SD OI     --> Pin 11
//SD SCK    --> Pin 13
//SD DO     --> Pin 12

#include <Adafruit_VC0706.h>  //https://github.com/adafruit/Adafruit-VC0706-Serial-Camera-Library
#include <SPI.h>              //Built-in
#include <SD.h>               //Built-in Version 1.1.0 does not work properly, use 1.0.9 or earlier (or later if it fixes the issue)
#include <SoftwareSerial.h>   //Built-in
#include <Wire.h>
#include <EEPROM.h>

#define chipSelect 10         //Change if using different chip select (CS) pin
#define EEPROM_ID 0x50
//Instantiate software serial connection for camera
SoftwareSerial cameraconnection = SoftwareSerial(2, 3);
//define camera
Adafruit_VC0706 cam = Adafruit_VC0706(&cameraconnection);

int eeAddress_W =0;
int counter[1] = {0};
void setup() {

  Serial.begin(9600);
  Serial.println("Serial Started:");

  

  setupCam();
  
  for (uint8_t i = 0; i > counter[1] ;i++){
  Serial.print(EXTreadEEPROM_byte(EEPROM_ID, (int) i), DEC);
}
  
}

void loop() {
  Serial.println("Waiting 3s...");
  delay(3000);
  Serial.println("Taking Picture...");
  takeSnapshot();

}

void takeSnapshot(){
  cam.resumeVideo();
  if (! cam.takePicture()) 
    Serial.println("Failed to snap!");
  else 
    Serial.println("Picture taken!");



  

  // Get the size of the image (frame) taken  
  uint16_t jpglen = cam.frameLength();
  Serial.print("Storing ");
  Serial.print(jpglen, DEC);
  Serial.print(" byte image.");

  int32_t time = millis();
  byte wCount = 0;
  // Read all the data up to # bytes!
   // For counting # of writes
  while (jpglen > 0) {
    // read 32 bytes at a time;
    uint8_t *buffer;
    uint8_t bytesToRead = min(32, jpglen); // change 32 to 64 for a speedup but may not work with all setups!
    buffer = cam.readPicture(bytesToRead);
    //extEEPROMWrite(buffer, bytesToRead);
    extEEPROMWrite(counter, 1);
    
    Serial.print(counter[1]);
    counter[1] ++;
    jpglen -= bytesToRead;
  }


  time = millis() - time;
  Serial.println("done!");
  Serial.print(time); Serial.println(" ms elapsed");
}

void setupCam(){
  //if(chipSelect != 10) pinMode(10, OUTPUT);   //to prevent SPI lockups if chipselect is changed

  //Test SD Card
 // if (!SD.begin(chipSelect)) {
  //  Serial.println("Card failed, or not present");
    // don't do anything more:
  //  return;
 // }  

  // Try to locate the camera
  if (cam.begin()) {
    Serial.println("Camera Found:");
  } else {
    Serial.println("No camera found?");
    return;
  }
  
  //Set Image Size
  cam.setImageSize(VC0706_640x480);         //Mission requirments call for minimum VGA
}

