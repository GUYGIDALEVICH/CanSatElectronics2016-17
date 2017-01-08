Adafruit_BMP085 bmp;

void setupBMP(){
  //initialize sensor
  if(!bmp.begin()){
    Serial.println("Could not find BMP sensor");
    while(1);
  }
}

void callTemp(){
  TeleArray[TeleTemperature] = bmp.readTemperature();
}


void callAlt(){
  TeleArray[TeleAltitude] = bmp.readAltitude();
}


