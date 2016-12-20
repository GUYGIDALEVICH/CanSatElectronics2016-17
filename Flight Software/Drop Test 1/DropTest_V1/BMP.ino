void setupTempAndPressure(){
 // Initialize sensor
 if(!bmp.begin()){
  Serial.println("Could not find BMP sensor");
  while(1); 
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

