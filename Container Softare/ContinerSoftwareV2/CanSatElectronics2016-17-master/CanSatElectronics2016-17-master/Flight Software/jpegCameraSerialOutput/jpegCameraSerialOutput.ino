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

#define chipSelect 10         //Change if using different chip select (CS) pin

//Instantiate software serial connection for camera
SoftwareSerial cameraconnection = SoftwareSerial(2, 3);
//define camera
Adafruit_VC0706 cam = Adafruit_VC0706(&cameraconnection);


void setup() {

  Serial.begin(9600);
  Serial.println("Serial Started:");

  setupCam();
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

  //Create image filename
  char filename[13];
  strcpy(filename, "IMAGE00.JPG");
  for (int i = 0; i < 100; i++) {
    filename[5] = '0' + i/10;
    filename[6] = '0' + i%10;
    // create if does not exist, do not open existing, write, sync after write
    if (! SD.exists(filename)) {
      break;
    }
  }
  
  // Open the file for writing
  File imgFile = SD.open(filename, FILE_WRITE);

  // Get the size of the image (frame) taken  
  uint16_t jpglen = cam.frameLength();
  Serial.print("Storing ");
  Serial.print(jpglen, DEC);
  Serial.print(" byte image.");

  int32_t time = millis();
  pinMode(8, OUTPUT);
  // Read all the data up to # bytes!
  byte wCount = 0; // For counting # of writes
  while (jpglen > 0) {
    // read 32 bytes at a time;
    uint8_t *buffer;
    uint8_t bytesToRead = min(64, jpglen); // change 32 to 64 for a speedup but may not work with all setups!
    buffer = cam.readPicture(bytesToRead);
    imgFile.write(buffer, bytesToRead);
//    if(++wCount >= 64) { // Every 2K, give a little feedback so it doesn't appear locked up
//      Serial.print('.');
//      wCount = 0;
//    }
    //Serial.print("Read ");  Serial.print(bytesToRead, DEC); Serial.println(" bytes");
    jpglen -= bytesToRead;
  }
  imgFile.close();

  time = millis() - time;
  Serial.println("done!");
  Serial.print(time); Serial.println(" ms elapsed");
}

void setupCam(){
  if(chipSelect != 10) pinMode(10, OUTPUT);   //to prevent SPI lockups if chipselect is changed

  //Test SD Card
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }  

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

