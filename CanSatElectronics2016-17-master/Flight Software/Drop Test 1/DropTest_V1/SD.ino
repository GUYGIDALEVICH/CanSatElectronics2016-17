void setupSD(){
  SD.begin(10);

  //Set Telemetery filename
  strcpy(telemetryFile, "Telemetry_00.txt");
  for (int i = 1; i < 200; i++) {
    telemetryFile[10] = '0' + i / 10; //'0' + i is an efficent typecast from int to char
    telemetryFile[11] = '0' + i % 10;
    // create if does not exist, do not open existing, write, sync after write
    if (! SD.exists(telemetryFile)) {
      telemetryFile[10] = '0' + (i-1) / 10; //'0' + i is an efficent typecast from int to char
      telemetryFile[11] = '0' + (i-1) % 10;
      break;
    }
  }

}

//
void writeTelemetryToSD(){
  File myFile = SD.open(telemetryFile);
  myFile.print(TeamID, DEC);
  myFile.print(',');
  myFile.print("GLIDER");
  myFile.print(',');
  
  for (int telem = 1; telem < TeleArrayLength; telem++){
    myFile.print(TeleArray[telem], DEC);
    myFile.print(',');
  }

  myFile.println();
  myFile.close();
}


void storeImageToSD(){
  
  File imgFile = SD.open(IMGfilename, FILE_WRITE);

  // Get the size of the image (frame) taken  
  uint16_t jpglen = cam.frameLength();
  //Serial.print("Storing ");
  //Serial.print(jpglen, DEC);
  //Serial.print(" byte image.");

  int32_t time = millis();


  byte wCount = 0; // For counting # of writes
  while (jpglen > 0) {
    // read 32 bytes at a time;
    uint8_t *buffer;
    uint8_t bytesToRead = min(64, jpglen); // change 32 to 64 for a speedup but may not work with all setups!
    buffer = cam.readPicture(bytesToRead);
    imgFile.write(buffer, bytesToRead);
//    if(++wCount >= 64) { // Every 2K, give a little feedback so it doesn't appear locked up
//      //Serial.print('.');
//      wCount = 0;
//    }
    ////Serial.print("Read ");  //Serial.print(bytesToRead, DEC); //Serial.println(" bytes");
    jpglen -= bytesToRead;
  }
  imgFile.close();

  time = millis() - time;

  //Serial.println("done!");
  //Serial.print(time); //Serial.println(" ms elapsed");
}

