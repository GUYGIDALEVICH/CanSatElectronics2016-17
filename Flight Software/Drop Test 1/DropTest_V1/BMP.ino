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
  Serial.println(bmp.readTemperature());
}

void callPressure(){
  Serial.println(bmp.readPressure());
}

void callAlt(){
  Serial.println(bmp.readAltitude());
}

