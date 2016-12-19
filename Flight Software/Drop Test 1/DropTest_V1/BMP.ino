// add bmp library to master 
// #inlcude <Wire.h>
// #inculde <Adafruit_BMP085.h>
Adafruit_BMP180 bmp;

void setupTempAndPressure(){
 // Initialize sensor
 if(!bmp.begin()){
  Serial.println("Could not find BMP sensor");
  while(1); 
 }
}

void callTemp(){
  TeleArray[TeleTemp] = bmp.readTemperature();
  //Serial.println(bmp.readTemperature());
}

void callPressure(){
  TeleArray[TelePressure] = bmp.readPressure();
  //Serial.println(bmp.readPressure());
}

void callAlt(){
  TeleArray[TeleAltSensor] = bmp.readAltitude();
  //Serial.println(bmp.readAltitude());
}

