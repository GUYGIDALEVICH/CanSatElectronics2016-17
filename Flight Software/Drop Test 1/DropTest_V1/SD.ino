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

