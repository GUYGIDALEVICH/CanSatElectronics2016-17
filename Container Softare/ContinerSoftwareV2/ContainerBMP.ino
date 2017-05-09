void setupBMP(){
  //initialize sensor
  if(!bmp.begin()){
    Serial.println("Could not find BMP sensor");
    while(1);
  }
  bmp.getEvent(&event);
  //Checks if sensor can actually get pressure (if not then it doesnt work)
  if(event.pressure){
    Serial.println("BMP OK");
  }
  
}

//Get temperature
void callTemp(){
    bmp.getTemperature(&temp);
    TeleArray[TeleTemperature] = temp;
}

//Gets current altitude
void callAlt(){
  currentAltitude = bmp.pressureToAltitude(initialPressure, event.pressure);
  TeleArray[TeleAltitude] = currentAltitude;  //Converts current pressure to altitude based on initial pressure
}

//Gets initial pressure
void callInitialPressureAndAltitude(){
  initialPressure = event.pressure;
  initialAltitude = bmp.pressureToAltitude(initialPressure, event.pressure); 
  writeToSD(initialPressure, "initial pressure.txt");  
  writeToSD(initialAltitude, "initial alt.txt");  
}



