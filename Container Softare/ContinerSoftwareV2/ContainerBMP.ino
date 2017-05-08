void setupBMP(){
  //initialize sensor
  if(!bmp.begin()){
    Serial.println("Could not find BMP sensor");
    while(1);
  }
  //Get new sensor event
  sensors_event_t event;
  bmp.getEvent(&event);
  //Checks if sensor can actually get pressure (if not then it doesnt work)
  if(event.pressure){
    Serial.println("BMP OK");
  }else{
    Serial.println("Sensor ERROR");
    failed = true;
  }
  
}

//Get temperature
void callTemp(){
    bmp.getTemperature(&temperature);
    TeleArray[TeleTemperature] = temperature;
}

//Gets current altitude
void callAlt(){
  currentAltitude = bmp.pressureToAltitude(initialPressure, event.pressure);
  TeleArray[TeleAltitude] = currentAltitude;  //Converts current pressure to altitude based on initial pressure
}

//Gets initial pressure
void callInitialPressure(){
  initialPressure = event.pressure;
  String ps = String(initialPressure);
  createFile("initial pressure.txt");
  writeToSD(ps, "initial pressure.txt");  
}

//Gets initial altitude
void callInitialAltitude(){
  initialAltitude = bmp.pressureToAltitude(initialPressure, event.pressure); 
  createFile("initial alt.txt");
  writeToSD(String(initialAltitude), "initial alt.txt");  
}


