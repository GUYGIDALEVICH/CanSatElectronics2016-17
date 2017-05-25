void setupBMP(){
 // Initialize sensor
 if(!bmp.begin()){
  Serial.println("Could not find BMP sensor");
 }
}

void callTemp(){
  TeleArray[TeleTemp] = bmp.readTemperature();
}

void callPressure(){
  TeleArray[TelePressure] = bmp.readPressure();
}

void callAlt(){
  TeleArray[TeleAltSensor] = bmp.readAltitude();
}

