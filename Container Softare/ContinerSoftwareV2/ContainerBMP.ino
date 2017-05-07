Adafruit_BMP085 bmp;

void setupBMP(){
  //initialize sensor
  if(!bmp.begin()){
    Serial.println("Could not find BMP sensor");
    while(1);
  }
  //Get new sensor event
  sensors_event_t event;
  bmp.getEvent(&event);
  
}

void callTemp(){
    TeleArray[TeleTemperature] = bmp.getTemperature(&temperature);
}


void callAlt(){
  TeleArray[TeleAltitude] = bmp.readAltitude();
}

void callInitialPressure(){
  initialPressure = event.pressure;
   
}

